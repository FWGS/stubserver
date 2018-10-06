/*
int.c - engine server interface stub
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

#include "sdk_common.h"
#include "mathlib.h"
common_t com;
#define EXPORT

EXPORT void GiveFnptrsToDll( engineapi_t *pengfuncs, globalvars_t *globals )
{
    com.engfuncs = pengfuncs;
    com.globals = globals;
}

char *GetGameDescription( void )
{
    return "STUB!";
}

void GameInit( void )
{

}

qboolean GetHullBounds( int hullnumber, float *mins, float *maxs )
{
    VectorClear(mins);
    VectorClear(maxs);
    return true;
}

void PM_Init (struct playermove_s *ppmove);

/*
void PM_Init( void* pm )
{

}
*/
void RegisterEncoders( void )
{


}

void ParmsNewLevel( void )
{

}

void ParmsChangeLevel( void )
{

}

void ResetGlobalState( void )
{

}

void KeyValue( edict_t *ent, keyvalue_t *pkvd )
{
    pkvd->handled = true;
}


void Spawn( edict_t *ent )
{
}

void ServerActivate( edict_t *first, int num, int maxclients )
{

}

void CreateVaseline(int player, int index, entity_state_t *vaselin, edict_t *edict, int modelindex, vec_t *mins, vec_t *maxs )
{

}

void CreateInstancedBaselines( void )
{

}

void StartFrame( void )
{

}

void Think( edict_t *e )
{

    com.engfuncs->AlertMessage( AT_CONSOLE, "Think %s\n", STRING(e->v.classname));
}

void Touch( edict_t *e1, edict_t *e2 )
{
    com.engfuncs->AlertMessage( AT_CONSOLE, "Touch %s %s\n", STRING(e1->v.classname), STRING(e2->v.classname));
}

qboolean ClientConnect( edict_t *ent, char *name, char *address, char *rej )
{
    return true;
}

void SetAbsBox( edict_t *e )
{

}

void ClientUserInfoChanged( edict_t *client, char *info )
{

}
extern void player(entvars_t *pev);

void ClientPutinServer( edict_t *e )
{
    player(&e->v);
}

void PlayerPreThink( edict_t *e)
{

}
void PM_Move (struct playermove_s *ppmove, qboolean server);

/*
void PM_Move( void*pm, qboolean server )
{

}
*/
void PlayerPostThink( edict_t *player )
{
}

void CmdEnd( edict_t *player )
{

}

void CmdStart( edict_t *e, void *ucmd, int random )
{

}


void UpdateClientData( edict_t *e, int sendweapons, struct clientdata_s *cd )
{
   entvars_t *pev = &e->v;
   VectorCopy(pev->origin, cd->origin);
   VectorCopy(pev->velocity, cd->velocity);
   cd->flags = pev->flags;
   cd->maxspeed = pev->maxspeed;
   cd->fov = pev->fov;
   cd->viewmodel = com.engfuncs->ModelIndex( STRING( pev->viewmodel ) );
   cd->health = pev->health;
   VectorCopy( pev->view_ofs, cd->view_ofs );
}

qboolean AllowLagCompensation( void )
{
    return false;
}

int GetWeaponData( edict_t *p, void *w)
{
    return 0;
}

void SetupVisibility( edict_t view, edict_t *p, byte **pvs, byte **phs)
{
    if(pvs) *pvs = NULL;
    if(phs) *phs = NULL;
}

qboolean AddToFullPack( entity_state_t *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, byte *set )
{
    memset( state, 0, sizeof( *state ) );
    memcpy( state->origin, ent->v.origin, 3 * sizeof( float ) );
    memcpy( state->angles, ent->v.angles, 3 * sizeof( float ) );
    memcpy( state->mins, ent->v.mins, 3 * sizeof( float ) );
    memcpy( state->maxs, ent->v.maxs, 3 * sizeof( float ) );

    memcpy( state->startpos, ent->v.startpos, 3 * sizeof( float ) );
    memcpy( state->endpos, ent->v.endpos, 3 * sizeof( float ) );
    memcpy( state->velocity, ent->v.velocity, 3 * sizeof( float ) );

    state->number	  = e;
    state->entityType = 1;
    state->impacttime = ent->v.impacttime;
    state->starttime = ent->v.starttime;

    state->modelindex = ent->v.modelindex;

    state->frame      = ent->v.frame;

    state->skin       = ent->v.skin;
    state->effects    = ent->v.effects;
    state->scale	  = ent->v.scale;
    state->solid	  = ent->v.solid;
    state->colormap   = ent->v.colormap;

    state->movetype   = ent->v.movetype;
    state->sequence   = ent->v.sequence;
    state->framerate  = ent->v.framerate;
    state->body       = ent->v.body;
    return true;
}

void ClientCommand( edict_t *cl )
{

}

#define F(x) serverfuncs->x = x
EXPORT void GetEntityAPI2( serverfuncs_t *serverfuncs, int *version )
{
    *version = 140;
    F(GetGameDescription);
    F(GameInit);
    F(GetHullBounds);
    F(PM_Init);
    F(RegisterEncoders);
    F(ParmsNewLevel);
    F(ParmsChangeLevel);
    F(ResetGlobalState);
    F(KeyValue);
    F(Spawn);
    F(ServerActivate);
    F(CreateVaseline);
    F(CreateInstancedBaselines);
    F(StartFrame);
    F(Think);
    F(Touch);
    F(ClientConnect);
    F(SetAbsBox);
    F(ClientUserInfoChanged);
    F(ClientPutinServer);
    F(PlayerPreThink);
    F(PM_Move);
    F(PlayerPostThink);
    F(CmdEnd);
    F(CmdStart);
    F(UpdateClientData);
    F(AllowLagCompensation);
    F(GetWeaponData);
    F(SetupVisibility);
    F(AddToFullPack);
    F(ClientCommand);
}
