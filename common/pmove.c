/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "sdk_common.h"
#include "bspfile.h"
#include "mathlib.h"
#include <math.h>
#include <string.h>

vec3_t vec3_origin;

typedef struct
{
    dclipnode_t	*clipnodes;
    mplane_t	*planes;
    int			firstclipnode;
    int			lastclipnode;
    vec3_t		clip_mins;
    vec3_t		clip_maxs;
} hull_t;


typedef struct
{
    vec3_t	normal;
    float	dist;
} pmplane_t;

typedef struct
{
    qboolean	allsolid;	// if true, plane is not valid
    qboolean	startsolid;	// if true, the initial point was in a solid area
    qboolean	inopen, inwater;
    float		fraction;		// time completed, 1.0 = didn't hit anything
    vec3_t		endpos;			// final position
    pmplane_t		plane;			// surface normal at impact
    int			ent;			// entity the surface is on
    vec3_t	deltavelocity;
    int	hitgroup;
} pmtrace_t;


typedef struct model_s model_t;
#define MAX_PHYSENTS	600
#define MAX_MOVEENTS	64
#define MAX_CLIP_PLANES	5

typedef struct
{
    char		name[32];		// Name of model, or "player" or "world".
    int		player;
    vec3_t	origin;
    model_t	*model;		// only for bsp models
    struct model_s	*studiomodel;
    vec3_t	mins, maxs;	// only for non-bsp models
    int		info;		// for client or server to identify
    vec3_t		angles;

    int		solid;
    int		skin;
    int		rendermode;

    float		frame;
    int		sequence;
    byte		controller[4];
    byte		blending[2];

    int		movetype;
    int		takedamage;
    int		blooddecal;
    int		team;
    int		classnumber;

    int		iuser1;
    int		iuser2;
    int		iuser3;
    int		iuser4;
    float		fuser1;
    float		fuser2;
    float		fuser3;
    float		fuser4;
    vec3_t		vuser1;
    vec3_t		vuser2;
    vec3_t		vuser3;
    vec3_t		vuser4;
} physent_t;


#define PM_NORMAL		0x00000000
#define PM_STUDIO_IGNORE	0x00000001
#define PM_STUDIO_BOX	0x00000002
#define PM_GLASS_IGNORE	0x00000004
#define PM_WORLD_ONLY	0x00000008
#define PM_CUSTOM_IGNORE	0x00000010
typedef struct trace_s trace_t;

typedef struct
{
    int	player_index;
    qboolean server,  multiplayer;
    float		time, frametime;
    vec3_t		forward, right, up;

    // player state
    vec3_t	origin;
    vec3_t	angles, oldangles;
    vec3_t	velocity, movedir, basevelocity;
    vec3_t		view_ofs;
    float		flDuckTime;
    qboolean		bInDuck;

    int		flTimeStepSound;
    int		iStepLeft;

    float		flFallVelocity;
    vec3_t		punchangle;

    float		flSwimTime;
    float		flNextPrimaryAttack;

    int		effects;

    int		flags;
    int		usehull;
    float		gravity;
    float		friction;
    int		oldbuttons;
    float		waterjumptime;
    qboolean	dead;
    int		deadflag;
    int		spectator;
    int		movetype;

    int		onground;
    int		waterlevel;
    int		watertype;
    int		oldwaterlevel;

    char		sztexturename[256];
    char		chtexturetype;

    float		maxspeed;
    float		clientmaxspeed;

    int		iuser1;
    int		iuser2;
    int		iuser3;
    int		iuser4;
    float		fuser1;
    float		fuser2;
    float		fuser3;
    float		fuser4;
    vec3_t		vuser1;
    vec3_t		vuser2;
    vec3_t		vuser3;
    vec3_t		vuser4;


    // world state
    int		numphysent;
    physent_t	physents[MAX_PHYSENTS];	// 0 should be the world
    int		nummoveent;
    physent_t		moveents[MAX_MOVEENTS];
    int		numvisent;
    physent_t		visents[MAX_PHYSENTS];

    // input
    usercmd_t	cmd;

    // results
    int		numtouch;
    pmtrace_t		touchindex[MAX_PHYSENTS];
    char		physinfo[MAX_PHYSINFO_STRING];

    struct movevars_s	*movevars;
    vec3_t		player_mins[4];
    vec3_t		player_maxs[4];

    // GS/Xash3D API
    const char	*(*PM_Info_ValueForKey) ( const char *s, const char *key );
    void		(*PM_Particle)( float *origin, int color, float life, int zpos, int zvel );
    int		(*PM_TestPlayerPosition)( float *pos, pmtrace_t *ptrace );
    void		(*Con_NPrintf)( int idx, char *fmt, ... );
    void		(*Con_DPrintf)( char *fmt, ... );
    void		(*Con_Printf)( char *fmt, ... );
    double		(*Sys_FloatTime)( void );
    void		(*PM_StuckTouch)( int hitent, pmtrace_t *ptraceresult );
    int		(*PM_PointContents)( float *p, int *truecontents );
    int		(*PM_TruePointContents)( float *p );
    int		(*PM_HullPointContents)( struct hull_s *hull, int num, float *p );
    pmtrace_t		(*PM_PlayerTrace)( float *start, float *end, int traceFlags, int ignore_pe );
    struct pmtrace_s	*(*PM_TraceLine)( float *start, float *end, int flags, int usehulll, int ignore_pe );
    int		(*RandomLong)( int lLow, int lHigh );
    float		(*RandomFloat)( float flLow, float flHigh );
    int		(*PM_GetModelType)( struct model_s *mod );
    void		(*PM_GetModelBounds)( struct model_s *mod, float *mins, float *maxs );
    void		*(*PM_HullForBsp)( physent_t *pe, float *offset );
    float		(*PM_TraceModel)( physent_t *pEnt, float *start, float *end, trace_t *trace );
    int		(*COM_FileSize)( char *filename );
    byte		*(*COM_LoadFile)( char *path, int usehunk, int *pLength );
    void		(*COM_FreeFile)( void *buffer );
    char		*(*memfgets)( byte *pMemFile, int fileSize, int *pFilePos, char *pBuffer, int bufferSize );

    qboolean		runfuncs;
    void		(*PM_PlaySound)( int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch );
    const char	*(*PM_TraceTexture)( int ground, float *vstart, float *vend );
    void		(*PM_PlaybackEventFull)( int flags, int clientindex, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 );

    pmtrace_t		(*PM_PlayerTraceEx) (float *start, float *end, int traceFlags, int (*pfnIgnore)( physent_t *pe ));
    int		(*PM_TestPlayerPositionEx) (float *pos, pmtrace_t *ptrace, int (*pfnIgnore)( physent_t *pe ));
    struct pmtrace_s	*(*PM_TraceLineEx)( float *start, float *end, int flags, int usehulll, int (*pfnIgnore)( physent_t *pe ));
    struct msurface_s	*(*PM_TraceSurface)( int ground, float *vstart, float *vend );
} playermove_t;

playermove_t	*pmove;


static int PM_PointContents (vec3_t point)
{
    return pmove->PM_PointContents(point, NULL);
}
qboolean PM_TestPlayerPosition (vec3_t point);
static pmtrace_t PM_PlayerMove (vec3_t start, vec3_t stop)
{
    return pmove->PM_PlayerTrace( start, stop, PM_NORMAL, -1);
}

// #define	PM_GRAVITY			800
// #define	PM_STOPSPEED		100
// #define	PM_MAXSPEED			320
// #define	PM_SPECTATORMAXSPEED	500
// #define	PM_ACCELERATE		10
// #define	PM_AIRACCELERATE	0.7
// #define	PM_WATERACCELERATE	10
// #define	PM_FRICTION			6
// #define	PM_WATERFRICTION	1

//void PM_InitBoxHull (void);

void PM_Init (struct playermove_s *ppmove)
{
    pmove = (void*) ppmove;
    //PM_InitBoxHull ();
}

#define	STEPSIZE	18


#define	BUTTON_JUMP	2


/*
==================
PM_ClipVelocity

Slide off of the impacting object
returns the blocked flags (1 = floor, 2 = step / wall)
==================
*/
#define	STOP_EPSILON	0.1

int PM_ClipVelocity (vec3_t in, vec3_t normal, vec3_t out, float overbounce)
{
	float	backoff;
	float	change;
	int		i, blocked;
	
	blocked = 0;
	if (normal[2] > 0)
		blocked |= 1;		// floor
	if (!normal[2])
		blocked |= 2;		// step
	
	backoff = DotProduct (in, normal) * overbounce;

	for (i=0 ; i<3 ; i++)
	{
		change = normal[i]*backoff;
		out[i] = in[i] - change;
		if (out[i] > -STOP_EPSILON && out[i] < STOP_EPSILON)
			out[i] = 0;
	}
	
	return blocked;
}

qboolean PM_AddToTouched( pmtrace_t tr, vec3_t impactvelocity )
{
    int i;

    for( i = 0; i < pmove->numtouch; i++ )
    {
        if( pmove->touchindex[i].ent == tr.ent )
            break;
    }
    if( i != pmove->numtouch )  // Already in list.
        return false;

    VectorCopy( impactvelocity, tr.deltavelocity );

    if( pmove->numtouch >= MAX_PHYSENTS )
        pmove->Con_DPrintf( "Too many entities were touched!\n" );

    pmove->touchindex[pmove->numtouch++] = tr;
    return true;
}


void PM_NoClip( void)
{
    int i;
    vec3_t wishvel;
    float fmove, smove;

    fmove = pmove->cmd.forwardmove;
    smove = pmove->cmd.sidemove;

    VectorNormalize( pmove->forward );
    VectorNormalize( pmove->right );

    for( i = 0; i < 3; i++ )
    {
        wishvel[i] = pmove->forward[i] * fmove + pmove->right[i] * smove;
    }
    wishvel[2] += pmove->cmd.upmove;
    VectorMA (pmove->origin, pmove->frametime, wishvel, pmove->origin );
}

/*
============
PM_FlyMove

The basic solid body movement clip that slides along multiple planes
============
*/
#define	MAX_CLIP_PLANES	5

int PM_FlyMove (void)
{
	int			bumpcount, numbumps;
	vec3_t		dir;
	float		d;
	int			numplanes;
	vec3_t		planes[MAX_CLIP_PLANES];
	vec3_t		primal_velocity, original_velocity;
	int			i, j;
	pmtrace_t		trace;
	vec3_t		end;
	float		time_left;
	int			blocked;
	
	numbumps = 4;
	
	blocked = 0;
    VectorCopy (pmove->velocity, original_velocity);
    VectorCopy (pmove->velocity, primal_velocity);
	numplanes = 0;
	
    time_left = pmove->frametime;

	for (bumpcount=0 ; bumpcount<numbumps ; bumpcount++)
	{
		for (i=0 ; i<3 ; i++)
            end[i] = pmove->origin[i] + time_left * pmove->velocity[i];

        trace = pmove->PM_PlayerTrace (pmove->origin, end, PM_NORMAL, -1);

		if (trace.startsolid || trace.allsolid)
		{	// entity is trapped in another solid
            VectorCopy (vec3_origin, pmove->velocity);
			return 3;
		}

		if (trace.fraction > 0)
		{	// actually covered some distance
            VectorCopy (trace.endpos, pmove->origin);
			numplanes = 0;
		}

		if (trace.fraction == 1)
			 break;		// moved the entire distance

		// save entity for contact
        PM_AddToTouched( trace, pmove->velocity );

		if (trace.plane.normal[2] > 0.7)
		{
			blocked |= 1;		// floor
		}
		if (!trace.plane.normal[2])
		{
			blocked |= 2;		// step
		}

		time_left -= time_left * trace.fraction;
		
	// cliped to another plane
		if (numplanes >= MAX_CLIP_PLANES)
		{	// this shouldn't really happen
            VectorCopy (vec3_origin, pmove->velocity);
			break;
		}

		VectorCopy (trace.plane.normal, planes[numplanes]);
		numplanes++;

//
// modify original_velocity so it parallels all of the clip planes
//
		for (i=0 ; i<numplanes ; i++)
		{
            PM_ClipVelocity (original_velocity, planes[i], pmove->velocity, 1);
			for (j=0 ; j<numplanes ; j++)
				if (j != i)
				{
                    if (DotProduct (pmove->velocity, planes[j]) < 0)
						break;	// not ok
				}
			if (j == numplanes)
				break;
		}
		
		if (i != numplanes)
		{	// go along this plane
		}
		else
		{	// go along the crease
			if (numplanes != 2)
			{
//				Con_Printf ("clip velocity, numplanes == %i\n",numplanes);
                VectorCopy (vec3_origin, pmove->velocity);
				break;
			}
			CrossProduct (planes[0], planes[1], dir);
            d = DotProduct (dir, pmove->velocity);
            VectorScale (dir, d, pmove->velocity);
		}

//
// if original velocity is against the original velocity, stop dead
// to avoid tiny occilations in sloping corners
//
        if (DotProduct (pmove->velocity, primal_velocity) <= 0)
		{
            VectorCopy (vec3_origin, pmove->velocity);
			break;
		}
	}

    if (pmove->waterjumptime)
	{
        VectorCopy (primal_velocity, pmove->velocity);
	}
	return blocked;
}

/*
=============
PM_GroundMove

Player is on ground, with no upwards velocity
=============
*/
void PM_GroundMove (void)
{
	vec3_t	start, dest;
	pmtrace_t	trace;
	vec3_t	original, originalvel, down, up, downvel;
	float	downdist, updist;

    pmove->velocity[2] = 0;
    if (!pmove->velocity[0] && !pmove->velocity[1] && !pmove->velocity[2])
		return;

	// first try just moving to the destination	
    dest[0] = pmove->origin[0] + pmove->velocity[0]*pmove->frametime;
    dest[1] = pmove->origin[1] + pmove->velocity[1]*pmove->frametime;
    dest[2] = pmove->origin[2];

	// first try moving directly to the next spot
	VectorCopy (dest, start);
    trace = PM_PlayerMove (pmove->origin, dest);
	if (trace.fraction == 1)
	{
        VectorCopy (trace.endpos, pmove->origin);
		return;
	}

	// try sliding forward both on ground and up 16 pixels
	// take the move that goes farthest
    VectorCopy (pmove->origin, original);
    VectorCopy (pmove->velocity, originalvel);

	// slide move
	PM_FlyMove ();

    VectorCopy (pmove->origin, down);
    VectorCopy (pmove->velocity, downvel);

    VectorCopy (original, pmove->origin);
    VectorCopy (originalvel, pmove->velocity);

// move up a stair height
    VectorCopy (pmove->origin, dest);
	dest[2] += STEPSIZE;
    trace = PM_PlayerMove (pmove->origin, dest);
	if (!trace.startsolid && !trace.allsolid)
	{
        VectorCopy (trace.endpos, pmove->origin);
	}

// slide move
	PM_FlyMove ();

// press down the stepheight
    VectorCopy (pmove->origin, dest);
	dest[2] -= STEPSIZE;
    trace = pmove->PM_PlayerTrace (pmove->origin, dest, PM_NORMAL, -1);
	if ( trace.plane.normal[2] < 0.7)
		goto usedown;
	if (!trace.startsolid && !trace.allsolid)
	{
        VectorCopy (trace.endpos, pmove->origin);
	}
    VectorCopy (pmove->origin, up);

	// decide which one went farther
	downdist = (down[0] - original[0])*(down[0] - original[0])
		+ (down[1] - original[1])*(down[1] - original[1]);
	updist = (up[0] - original[0])*(up[0] - original[0])
		+ (up[1] - original[1])*(up[1] - original[1]);

	if (downdist > updist)
	{
usedown:
        VectorCopy (down, pmove->origin);
        VectorCopy (downvel, pmove->velocity);
	} else // copy z value from slide move
        pmove->velocity[2] = downvel[2];

// if at a dead stop, retry the move with nudges to get around lips

}



/*
==================
PM_Friction

Handles both ground friction and water friction
==================
*/
void PM_Friction (void)
{
	float	*vel;
	float	speed, newspeed, control;
	float	friction;
	float	drop;
	vec3_t	start, stop;
	pmtrace_t		trace;
	
    if (pmove->waterjumptime)
		return;

    vel = pmove->velocity;
	
	speed = sqrt(vel[0]*vel[0] +vel[1]*vel[1] + vel[2]*vel[2]);
	if (speed < 1)
	{
		vel[0] = 0;
		vel[1] = 0;
		return;
	}

    friction = pmove->movevars->friction;

// if the leading edge is over a dropoff, increase friction
    if (pmove->onground != -1) {
        start[0] = stop[0] = pmove->origin[0] + vel[0]/speed*16;
        start[1] = stop[1] = pmove->origin[1] + vel[1]/speed*16;
        start[2] = pmove->origin[2] + pmove->player_mins[pmove->usehull][2];// player_mins[2];
		stop[2] = start[2] - 34;

		trace = PM_PlayerMove (start, stop);

		if (trace.fraction == 1) {
			friction *= 2;
		}
	}

	drop = 0;

    if (pmove->waterlevel >= 2) // apply water friction
        drop += speed*pmove->movevars->waterfriction*pmove->waterlevel*pmove->frametime;
    else if (pmove->onground != -1) // apply ground friction
	{
        control = speed < pmove->movevars->stopspeed ? pmove->movevars->stopspeed : speed;
        drop += control*friction*pmove->frametime;
	}


// scale the velocity
	newspeed = speed - drop;
	if (newspeed < 0)
		newspeed = 0;
	newspeed /= speed;

	vel[0] = vel[0] * newspeed;
	vel[1] = vel[1] * newspeed;
	vel[2] = vel[2] * newspeed;
}


/*
==============
PM_Accelerate
==============
*/
void PM_Accelerate (vec3_t wishdir, float wishspeed, float accel)
{
	int			i;
	float		addspeed, accelspeed, currentspeed;

    if (pmove->dead)
		return;
    if (pmove->waterjumptime)
		return;

    currentspeed = DotProduct (pmove->velocity, wishdir);
	addspeed = wishspeed - currentspeed;
	if (addspeed <= 0)
		return;
    accelspeed = accel*pmove->frametime*wishspeed;
	if (accelspeed > addspeed)
		accelspeed = addspeed;
	
	for (i=0 ; i<3 ; i++)
        pmove->velocity[i] += accelspeed*wishdir[i];
}

void PM_AirAccelerate (vec3_t wishdir, float wishspeed, float accel)
{
	int			i;
	float		addspeed, accelspeed, currentspeed, wishspd = wishspeed;
		
    if (pmove->dead)
		return;
    if (pmove->waterjumptime)
		return;

	if (wishspd > 30)
		wishspd = 30;
    currentspeed = DotProduct (pmove->velocity, wishdir);
	addspeed = wishspd - currentspeed;
	if (addspeed <= 0)
		return;
    accelspeed = accel * wishspeed * pmove->frametime;
	if (accelspeed > addspeed)
		accelspeed = addspeed;
	
	for (i=0 ; i<3 ; i++)
        pmove->velocity[i] += accelspeed*wishdir[i];
}



/*
===================
PM_WaterMove

===================
*/
void PM_WaterMove (void)
{
	int		i;
	vec3_t	wishvel;
	float	wishspeed;
	vec3_t	wishdir;
	vec3_t	start, dest;
	pmtrace_t	trace;

//
// user intentions
//
	for (i=0 ; i<3 ; i++)
        wishvel[i] = pmove->forward[i]*pmove->cmd.forwardmove + pmove->right[i]*pmove->cmd.sidemove;

    if (!pmove->cmd.forwardmove && !pmove->cmd.sidemove && !pmove->cmd.upmove)
		wishvel[2] -= 60;		// drift towards bottom
	else
        wishvel[2] += pmove->cmd.upmove;

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

    if (wishspeed > pmove->movevars->maxspeed)
	{
        VectorScale (wishvel, pmove->movevars->maxspeed/wishspeed, wishvel);
        wishspeed = pmove->movevars->maxspeed;
	}
	wishspeed *= 0.7;

//
// water acceleration
//
//	if (pmove->waterjumptime)
//		Con_Printf ("wm->%f, %f, %f\n", pmove->velocity[0], pmove->velocity[1], pmove->velocity[2]);
    PM_Accelerate (wishdir, wishspeed, pmove->movevars->wateraccelerate);

// assume it is a stair or a slope, so press down from stepheight above
    VectorMA (pmove->origin, pmove->frametime, pmove->velocity, dest);
	VectorCopy (dest, start);
	start[2] += STEPSIZE + 1;
	trace = PM_PlayerMove (start, dest);
	if (!trace.startsolid && !trace.allsolid)	// FIXME: check steep slope?
	{	// walked up the step
        VectorCopy (trace.endpos, pmove->origin);
		return;
	}
	
	PM_FlyMove ();
//	if (pmove->waterjumptime)
//		Con_Printf ("<-wm%f, %f, %f\n", pmove->velocity[0], pmove->velocity[1], pmove->velocity[2]);
}


/*
===================
PM_AirMove

===================
*/
void PM_AirMove (void)
{
	int			i;
	vec3_t		wishvel;
	float		fmove, smove;
	vec3_t		wishdir;
	float		wishspeed;

    fmove = pmove->cmd.forwardmove;
    smove = pmove->cmd.sidemove;
   /* pmove->movevars->maxspeed = 1000;
    pmove->movevars->maxvelocity = 1000;
    pmove->movevars->gravity = 800;
    pmove->movevars->accelerate = 1000;
    pmove->movevars->accelerate = 1000;
    pmove->movevars->entgravity = 1;
    pmove->movevars->bounce = 1;*/
    pmove->movevars->entgravity = 1;

	
    pmove->forward[2] = 0;
    pmove->right[2] = 0;
    VectorNormalize (pmove->forward);
    VectorNormalize (pmove->right);

	for (i=0 ; i<2 ; i++)
        wishvel[i] = pmove->forward[i]*fmove + pmove->right[i]*smove;
	wishvel[2] = 0;

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

//
// clamp to server defined max speed
//
    if (wishspeed > pmove->movevars->maxspeed)
	{
        VectorScale (wishvel, pmove->movevars->maxspeed/wishspeed, wishvel);
        wishspeed = pmove->movevars->maxspeed;
	}
	
//	if (pmove->waterjumptime)
//		Con_Printf ("am->%f, %f, %f\n", pmove->velocity[0], pmove->velocity[1], pmove->velocity[2]);

    if ( pmove->onground != -1)
	{
        pmove->velocity[2] = 0;
        PM_Accelerate (wishdir, wishspeed, pmove->movevars->accelerate);
        pmove->velocity[2] -= pmove->movevars->entgravity * pmove->movevars->gravity * pmove->frametime;
		PM_GroundMove ();
	}
	else
	{	// not on ground, so little effect on velocity
        PM_AirAccelerate (wishdir, wishspeed, pmove->movevars->accelerate);

		// add gravity
        pmove->velocity[2] -= pmove->movevars->entgravity * pmove->movevars->gravity * pmove->frametime;

		PM_FlyMove ();

	}

//Con_Printf("airmove:vec: %4.2f %4.2f %4.2f\n",
//			pmove->velocity[0],
//			pmove->velocity[1],
//			pmove->velocity[2]);
//

//	if (pmove->waterjumptime)
//		Con_Printf ("<-am%f, %f, %f\n", pmove->velocity[0], pmove->velocity[1], pmove->velocity[2]);
}



/*
=============
PM_CatagorizePosition
=============
*/
void PM_CatagorizePosition (void)
{
	vec3_t		point;
	int			cont;
	pmtrace_t		tr;

// if the player hull point one unit down is solid, the player
// is on ground

// see if standing on something solid	
    point[0] = pmove->origin[0];
    point[1] = pmove->origin[1];
    point[2] = pmove->origin[2] - 1;
    if (pmove->velocity[2] > 180)
	{
        pmove->onground = -1;
	}
	else
	{
        tr = PM_PlayerMove (pmove->origin, point);
		if ( tr.plane.normal[2] < 0.7)
            pmove->onground = -1;	// too steep
		else
            pmove->onground = tr.ent;
        if (pmove->onground != -1)
		{
            pmove->waterjumptime = 0;
			if (!tr.startsolid && !tr.allsolid)
                VectorCopy (tr.endpos, pmove->origin);
		}

		// standing on an entity other than the world
		if (tr.ent > 0)
		{
           PM_AddToTouched( tr, pmove->velocity );
		}
	}

//
// get waterlevel
//
    pmove->waterlevel = 0;
    pmove->watertype = CONTENTS_EMPTY;

    point[2] = pmove->origin[2] + pmove->player_mins[pmove->usehull][2] + 1;
	cont = PM_PointContents (point);

	if (cont <= CONTENTS_WATER)
	{
        pmove->watertype = cont;
        pmove->waterlevel = 1;
        point[2] = pmove->origin[2] + (pmove->player_mins[pmove->usehull][2] + pmove->player_mins[pmove->usehull][2])*0.5;
		cont = PM_PointContents (point);
		if (cont <= CONTENTS_WATER)
		{
            pmove->waterlevel = 2;
            point[2] = pmove->origin[2] + 22;
			cont = PM_PointContents (point);
			if (cont <= CONTENTS_WATER)
                pmove->waterlevel = 3;
		}
	}
}


/*
=============
JumpButton
=============
*/
void JumpButton (void)
{
    if (pmove->dead)
	{
        pmove->oldbuttons |= BUTTON_JUMP;	// don't jump again until released
		return;
	}

    if (pmove->waterjumptime)
	{
        pmove->waterjumptime -= pmove->frametime;
        if (pmove->waterjumptime < 0)
            pmove->waterjumptime = 0;
		return;
	}

    if (pmove->waterlevel >= 2)
	{	// swimming, not jumping
        pmove->onground = -1;

        if (pmove->watertype == CONTENTS_WATER)
            pmove->velocity[2] = 100;
        else if (pmove->watertype == CONTENTS_SLIME)
            pmove->velocity[2] = 80;
		else
            pmove->velocity[2] = 50;
		return;
	}

    if (pmove->onground == -1)
		return;		// in air, so no effect

    if ( pmove->oldbuttons & BUTTON_JUMP )
		return;		// don't pogo stick

    pmove->onground = -1;
    pmove->velocity[2] += 270;

    pmove->oldbuttons |= BUTTON_JUMP;	// don't jump again until released
}

/*
=============
CheckWaterJump
=============
*/
void CheckWaterJump (void)
{
	vec3_t	spot;
	int		cont;
	vec3_t	flatforward;

    if (pmove->waterjumptime)
		return;

	// ZOID, don't hop out if we just jumped in
    if (pmove->velocity[2] < -180)
		return; // only hop out if we are moving up

	// see if near an edge
    flatforward[0] = pmove->forward[0];
    flatforward[1] = pmove->forward[1];
	flatforward[2] = 0;
	VectorNormalize (flatforward);

    VectorMA (pmove->origin, 24, flatforward, spot);
	spot[2] += 8;
	cont = PM_PointContents (spot);
	if (cont != CONTENTS_SOLID)
		return;
	spot[2] += 24;
	cont = PM_PointContents (spot);
	if (cont != CONTENTS_EMPTY)
		return;
	// jump out of water
    VectorScale (flatforward, 50, pmove->velocity);
    pmove->velocity[2] = 310;
    pmove->waterjumptime = 2;	// safety net
    pmove->oldbuttons |= BUTTON_JUMP;	// don't jump again until released
}

/*
=================
NudgePosition

If pmove->origin is in a solid position,
try nudging slightly on all axis to
allow for the cut precision of the net coordinates
=================
*/
void NudgePosition (void)
{
	vec3_t	base;
	int		x, y, z;
	int		i;
	static int		sign[3] = {0, -1, 1};

    VectorCopy (pmove->origin, base);

	for (i=0 ; i<3 ; i++)
        pmove->origin[i] = ((int)(pmove->origin[i]*8)) * 0.125;
//	pmove->origin[2] += 0.124;

//	if (pmove->dead)
//		return;		// might be a squished point, so don'y bother
//	if (PM_TestPlayerPosition (pmove->origin) )
//		return;

	for (z=0 ; z<=2 ; z++)
	{
		for (x=0 ; x<=2 ; x++)
		{
			for (y=0 ; y<=2 ; y++)
			{
                pmove->origin[0] = base[0] + (sign[x] * 1.0/8);
                pmove->origin[1] = base[1] + (sign[y] * 1.0/8);
                pmove->origin[2] = base[2] + (sign[z] * 1.0/8);
                if (pmove->PM_TestPlayerPosition (pmove->origin, NULL))
					return;
			}
		}
	}
    VectorCopy (base, pmove->origin);
//	Con_DPrintf ("NudgePosition: stuck\n");
}

/*
===============
SpectatorMove
===============
*/
void SpectatorMove (void)
{
	float	speed, drop, friction, control, newspeed, accel;
	float	currentspeed, addspeed, accelspeed;
	int			i;
	vec3_t		wishvel;
	float		fmove, smove;
	vec3_t		wishdir;
	float		wishspeed;
#ifndef SERVERONLY
	extern float	server_version;	// version of server we connected to
#endif

	// friction

    speed = Length (pmove->velocity);
	if (speed < 1)
	{
        VectorCopy (vec3_origin, pmove->velocity);
	}
	else
	{
		drop = 0;

        friction = pmove->movevars->friction*1.5;	// extra friction
        control = speed < pmove->movevars->stopspeed ? pmove->movevars->stopspeed : speed;
        drop += control*friction*pmove->frametime;

		// scale the velocity
		newspeed = speed - drop;
		if (newspeed < 0)
			newspeed = 0;
		newspeed /= speed;

        VectorScale (pmove->velocity, newspeed, pmove->velocity);
	}

	// accelerate
    fmove = pmove->cmd.forwardmove;
    smove = pmove->cmd.sidemove;
	
    VectorNormalize (pmove->forward);
    VectorNormalize (pmove->right);

	for (i=0 ; i<3 ; i++)
        wishvel[i] = pmove->forward[i]*fmove + pmove->right[i]*smove;
    wishvel[2] += pmove->cmd.upmove;

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

	//
	// clamp to server defined max speed
	//
    if (wishspeed > pmove->movevars->spectatormaxspeed)
	{
        VectorScale (wishvel, pmove->movevars->spectatormaxspeed/wishspeed, wishvel);
        wishspeed = pmove->movevars->spectatormaxspeed;
	}

    currentspeed = DotProduct(pmove->velocity, wishdir);
	addspeed = wishspeed - currentspeed;
	if (addspeed <= 0)
		return;
    accelspeed = pmove->movevars->accelerate*pmove->frametime*wishspeed;
	if (accelspeed > addspeed)
		accelspeed = addspeed;
	
	for (i=0 ; i<3 ; i++)
        pmove->velocity[i] += accelspeed*wishdir[i];


	// move
    VectorMA (pmove->origin, pmove->frametime, pmove->velocity, pmove->origin);
}

/*
=============
PlayerMove

Returns with origin, angles, and velocity modified in place.

Numtouch and touchindex[] will be set if any of the physents
were contacted during the move.
=============
*/
void PM_Move (struct playermove_s *ppmove, qboolean server)
{
    pmove->frametime = pmove->cmd.msec * 0.001;
    pmove->numtouch = 0;
    //pmove = ppmove;

    AngleVectors (pmove->angles, pmove->forward, pmove->right, pmove->up);

    if (pmove->spectator)
	{
		SpectatorMove ();
		return;
	}

	NudgePosition ();

	// take angles directly from command
    VectorCopy (pmove->cmd.angles, pmove->angles);

	// set onground, watertype, and waterlevel
	PM_CatagorizePosition ();

    if (pmove->waterlevel == 2)
		CheckWaterJump ();

    if (pmove->velocity[2] < 0)
        pmove->waterjumptime = 0;

    if (pmove->cmd.buttons & BUTTON_JUMP)
		JumpButton ();
	else
        pmove->oldbuttons &= ~BUTTON_JUMP;

	PM_Friction ();

    if( pmove->movetype == MOVETYPE_NOCLIP )
    {
        PM_NoClip();
        return;
    }

    if (pmove->waterlevel >= 2)
		PM_WaterMove ();
	else
		PM_AirMove ();

	// set onground, watertype, and waterlevel for final spot
	PM_CatagorizePosition ();
}

