/*
sdk_svapi.h - server game library exports
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
#ifndef SDK_SVAPI_H
#define SDK_SVAPI_H
#include "sdk_types.h"
typedef struct serverfuncs_s
{
  void (*GameInit)();
  int (*Spawn)( edict_t *e );
  void (*Think)( edict_t *e );
  void (*Use)( edict_t *used, edict_t *other );
  void (*Touch)( edict_t *touched, edict_t *other );
  void (*Blocked)( edict_t *blocked, edict_t *other );
  void (*KeyValue)( edict_t *e, keyvalue_t *pkvd );
  void (*Save)( edict_t *e, void *savedata);
  int (*Restore)( edict_t *e, void *savedata, int globalentity);
  void (*SetAbsBox)( edict_t *e );
  void (*SaveWriteFields)( void *savedata, char *name, void *basedata, void *field, int fieldcount );
  void (*SaveReadFields)( void *savedata, char *name, void *basedata, void *field, int fieldcount );
  void (*SaveGlobalState)( void *savedata );
  void (*RestoreGlobalState)( void *savedata );
  void (*ResetGlobalState)( void );
  int (*ClientConnect)( edict_t *e, char *name, char *address, void *rejectreason );
  void (*ClientDisconnect)( edict_t *e );
  void (*ClientMochitVSortire)( edict_t *e );
  void (*ClientPutinServer)( edict_t *e );
  void (*ClientCommand)( edict_t *e );
  void (*ClientUserInfoChanged)( edict_t *e, char *userinfo );

  void (*ServerActivate)( void );
  void (*ServerDectivate)( void );
  void (*PlayerPreThink)( edict_t *e );
  void (*PlayerPostThink)( edict_t *e );

  void (*StartFrame)( void );
  void (*ParmsNewLevel)( void );
  void (*ParmsChangeLevel)( void );

  // return "Half-Life";
  char *(*GetGameDescription)( void );

  void (*PlayerCustomization)( edict_t *e, void *pCustom );

  // HLTV?
  void (*SpectatorConnect)( edict_t *e );
  void (*SpectatorDisconnect)( edict_t *e );
  void (*SpectatorThink)( edict_t *e );

  // Call when engine doing Sys_Error()
  void (*SysErrorCallback)( char *error );

  // server always true here
  void (*PM_Move)( void*, qboolean server );
  void (*PM_Init)( void* );
  signed char (*PM_FindTextureType)( char *name );
  void (*SetupVisibility)( edict_t *target, edict_t *e, byte *pvs, byte *pas );
  void (*UpdateClientData)( edict_t e, int sendweapons,  void *clientdata );
  int (*AddToFullPack)( entity_state_t *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, byte *set );
  void (*CreateVaseline)( int player, int index, entity_state_t *vaseline, edict_t *ent, int modelindex, vec3_t mins, vec3_t maxs );
  void (*RegisterEncoders)( void );
  int (*GetWeaponData)( edict_t *p, void *weapondata );
  void (*CmdStart)( edict_t *p, void *cmd, unsigned int random_seed );
  void (*CmdEnd)( edict_t *p );
  qboolean (*ConnectionLessPacket)( void *from, char *args, char *response, int *response_size );

  int (*GetHullBounds)( int hullnumber, vec_t *mins, vec_t *maxs );
  void (*CreateInstancedBaselines)( void );
  qboolean (*InconsistentFile)( edict_t *p, char *fname, char *disconnect_message );
  qboolean (*AllowLagCompensation)( void );
} serverfuncs_t;


typedef struct serverfuncs2_s
{
    void (*OnFreeEntPrivateData)( edict_t *e );
    void (*GameShutdown)( void );
    qboolean (*ShouldCollide)( edict_t *touched, edict_t *other );
    void (*CvarValue)( edict_t *e, char *value );
    void (*CvarValue2)( edict_t *e, int id, char *var, char *value );
} serverfuncs2_t;
#endif // SDK_SVAPI_H
