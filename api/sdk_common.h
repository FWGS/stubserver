/*
sdk_common.h - engine structures
Copyright (C) 2016 Mittorn

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#ifndef SDK_COMMON_H
#define SDK_COMMON_H

#include "sdk_types.h"
#include "sdk_svapi.h"
#include "sdk_engapi.h"
#include "sdk_defines.h"

typedef struct entvars_s
{
    string_t classname, globalname;
    vec3_t origin, oldorigin, velocity, basevelocity;
    vec3_t clbasevelocity, movedir;
    vec3_t angles, avelocity,  punchangle, v_angle;
    vec3_t endpos, startpos;
    float impacttime, starttime;
    int fixangle;
    float idealpitch, pitch_speed, ideal_yaw, yaw_speed;
    int modelindex;
    string_t model;
    int viewmodel, weaponmodel;
    vec3_t absmin, absmax, mins, maxs, size;
    float ltime, nextthink;
    int movetype, solid, skin, body, effects;
    float gravity, friction;
    int light_level, sequence, gaitsequence;
    float frame, animtime, framerate;
    byte controller[4], blending[2];
    float scale;
    int rendermode;
    float renderamt;
    vec3_t rendercolor;
    int renderfx;
    float health, frags;
    int weapons;
    float takedamage;
    int deadflag;
    vec3_t view_ofs;
    int button;
    int impulse;
    edict_t *chain, *dmg_inflictor, *enemy, *aiment, *owner, *groundentity;
    int spawnflags, flags, colormap, team;
    float max_health, teleport_time, armortype, armorvalue;
    int waterlevel, watertype;
    string_t target, targetname, netname, message;
    float dmg_take, dmg_save, dmg, dmgtime;
    string_t noice, noise1, noice2, noice3;
    float speed, air_finished, pain_finished, radsuit_finished;
    edict_t *pContainingEntity;
    int playerclass;
    float maxspeed, fov;
    int weaponanim, pushmsec, bInDuck, flTimeStepSound, flSwimTime,flDuckTime, iStepLeft;
    float flFallVelocity;
    int gamestate, oldbuttons, groupinfo;
    int iuser[4];
    float fuser[4];
    vec3_t vuser[4];
    edict_t *euser[4];
} entvars_t;

typedef struct link_s
{
    struct link_s *p, *n;
} link_t;

typedef struct edict_s
{
    qboolean free;
    int serialnumber;
    link_t area;
    int headnode, num_leafs;
    short leafnums[48];
    float freetime;
    void *pvPrivateData;
    entvars_t v;
} edict_t;



typedef struct globalvars_s
{
    float time, frametime, forceretouch;
    int mapname, startspot;
    float deathmatch, coop, teamplay, serverflags, foundsecrets;
    vec3_t fwd, up, right;
    float trallsolid, trstartsolid, trfraction;
    vec3_t trendpos, trplanenormal;
    float trplanedist;
    edict_t *traceent;
    float traceinopen, traceinwater;
    int tracegitgroup, traceflags;
    int msgentity, cdtrack, maxclients, maxentities;
    char *pStringBase;
    void *pSaveData;
    vec3_t *landmarkoffset;
} globalvars_t;

typedef struct keyvalue_s
{
    char *classname;
    char *keyname;
    char *value;
    qboolean handled;
} keyvalue_t;

typedef struct entity_state_s
{
    int entityType, number;
    float msgtime;
    int msgnum;
    vec3_t origin, angles;
    int modelindex, sequence;
    float frame;
    int colormap;
    short skin;
    unsigned short solid;
    int effects;
    float scale;
    byte eflags;
    int rendermode, renderamt;
    rgb_t rendercolor;
    int renderfx;
    int movetype;
    float animtime, framerate;
    int body;
    byte contoller[4];
    byte blending[4];
    vec3_t velocity, mins, maxs;
    int aiment, owner;
    float firction, graviry;
    int team, playerclass, health, spectator, weaponmodel, gaitsequence;
    vec3_t basevelocity;
    int usehull, oldbuttons, onground, stepleft;

    float flFallVelocity, fov;
    int weaponanim;
    vec3_t startpos, endpos;
    float impacttime, starttime;
    int iuser[4];
    float fuser[4];
    vec3_t vuser[4];
    edict_t *euser[4];
} entity_state_t;

#define MAX_PHYSINFO_STRING		256
typedef struct clientdata_s
{
    vec3_t		origin;
    vec3_t		velocity;

    int		viewmodel;
    vec3_t		punchangle;
    int		flags;
    int		waterlevel;
    int		watertype;
    vec3_t		view_ofs;
    float		health;

    int		bInDuck;
    int		weapons; // remove?

    int		flTimeStepSound;
    int		flDuckTime;
    int		flSwimTime;
    int		waterjumptime;

    float		maxspeed;

    float		fov;
    int		weaponanim;

    int		m_iId;
    int		ammo_shells;
    int		ammo_nails;
    int		ammo_cells;
    int		ammo_rockets;
    float		m_flNextAttack;

    int		tfstate;
    int		pushmsec;
    int		deadflag;
    char		physinfo[MAX_PHYSINFO_STRING];

    // For mods
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

} clientdata_t;

typedef struct traceresult_s
{
    qboolean allsolid, startsolid, inopen, inwater;
    float fraction;
    vec3_t endpos;
    float planedist;
    vec3_t planenormal;
    edict_t *hit;
    int hitgroup;
} traceresult_t;

typedef struct cvar_s
{
    char		*name;
    char		*string;
    int		flags;
    float		value;
    struct cvar_s	*next;
} cvar_t;

typedef struct usercmd_s
{
    short		lerp_msec;
    byte	msec;
    vec3_t	angles;
    float	forwardmove, sidemove, upmove;
    byte		lightlevel;
    unsigned short	buttons;
    byte	impulse;
    byte		weaponselect;
    int		impact_index;
    vec3_t		impact_position;
} usercmd_t;


typedef struct movevars_s {
    float	gravity;
    float	stopspeed;
    float	maxspeed;
    float	spectatormaxspeed;
    float	accelerate;
    float	airaccelerate;
    float	wateraccelerate;
    float	friction;
    float	edgefriction;
    float	waterfriction;
    float	entgravity;
    float	bounce;
    float	stepsize;
    float	maxvelocity;
    float	zmax;
    float	waveHeight;
    qboolean	footsteps;
    char	skyName[32];
    float	rollangle;
    float	rollspeed;
    float	skycolor_r;
    float	skycolor_g;
    float	skycolor_b;
    float	skyvec_x;
    float	skyvec_y;
    float	skyvec_z;
    // xash3d
    int	features;		// engine features that shared across network
    int	fog_settings;	// Global fog settings (packed color+density)
    float	wateralpha;	// World water alpha 1.0 - solid 0.0 - transparent
    float	skydir_x;		// skybox rotate direction
    float	skydir_y;		//
    float	skydir_z;		//
    float	skyangle;		// skybox rotate angle
} movevars_t;

typedef struct common_s
{
    globalvars_t *globals;
    engineapi_t *engfuncs;
} common_t;

extern common_t com;


// Use this instead of ALLOC_STRING on constant strings
#define STRING(offset)		(const char *)(com.globals->pStringBase + (int)offset)
#if !defined XASH_64BIT || defined(CLIENT_DLL)
#define MAKE_STRING(str)	((int)(long int)str - (int)(long int)STRING(0))
#else
static inline int MAKE_STRING(const char *szValue)
{
    long long ptrdiff = szValue - STRING(0);
    if( ptrdiff > INT_MAX || ptrdiff < INT_MIN )
        return com.engfuncs->AllocEngineString( szValue );
    else
        return (int)ptrdiff;
}
#endif

#endif // SDK_COMMON_H

