/*
sdk_engapi.h - engine server api
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

#ifndef SDK_ENGAPI_H
#define SDK_ENGAPI_H
#include "sdk_types.h"

typedef struct engineapi_s
{
    int (*PrecacheModel)( char *name );
    int (*PrecacheSound)( char *name );
    void (*SetModel)( edict_t *e, char *modelname );
    int (*ModelIndex)( char *name );
    int (*ModelFrames)( int modelindex );
    void (*SetSize)( edict_t *e, vec_t *mins, vec_t *maxs );
    void (*Changelevel)( char *map, char *landmark );
    void (*GetSpawnParams)( edict_t *e );
    void (*SaveSpawnParams)( edict_t *e );
    float (*VecToYaw)( vec_t *vec );
    void (*VecToAngles)( vec_t *in, vec_t *out );
    void (*MoveToOrigin)( edict_t *e, vec_t *goal, float dist, int movetype );
    void (*ChangeYaw)( edict_t *e );
    void (*ChangePitch)( edict_t *e );
    edict_t *(*FindEnitityByString)( edict_t *start, char *key, char *value );
    int (*GetEntityIllum)( edict_t *e );
    edict_t *(*FindEnitityInSphere)( edict_t *start, vec_t *origin, float radius );
    edict_t *(*FindClientInPVS)( edict_t *e );
    edict_t *(*EntitiesInPVS)( edict_t *p );
    void (*MakeVectors)( vec_t *vec );
    void (*AngleVectors)( vec_t *vec, vec_t *f, vec_t *r, vec_t *u );
    edict_t *(*CreateEntity)( void );
    void (*RemoveEntity)( edict_t *e );
    edict_t *(*CreateNamedEntity)( string_t classname );
    void (*MakeStatic)( edict_t *e );
    qboolean (*EntIsOnFloor)( edict_t *e );
    int (*DropToFloor)( edict_t *e );
    int (*WalkMove)( edict_t *e, float yaw, float dist, int mode );
    void (*SetOrigin)( edict_t *e, vec_t *origin );
    void (*EmitSound)( edict_t *e, int channel, char *sample, float vol, float attenuation, int flags, int pitch );
    void (*EmitAmbientSound)( edict_t *e, int channel, char *sample, float vol, float attenuation, int flags, int pitch );
    void (*TraceLine)( vec_t *v1, vec_t *v2, qboolean nomonsters, int hull, edict_t *skip, traceresult_t *result );
    void (*TraceToss)( edict_t *e, edict_t *skip, traceresult_t *tr );
    int (*TraceMonsterHull)( vec_t *v1, vec_t *v2, qboolean nomonsters, edict_t *skip, traceresult_t *tr );
    void (*TraceHull)( vec_t *v1, vec_t *v2, qboolean nomonsters, int hull, edict_t *skip, traceresult_t *tr );
    void (*TraceModel)( vec_t *v1, vec_t *v2, int hull, edict_t *e, traceresult_t *tr );
    void (*TraceTexture)( edict_t *e, vec_t *v1, vec_t *v2 );
    void (*TraceSphere)( vec_t *v1, vec_t *v2, qboolean nomonsters, float radius, edict_t *skip, traceresult_t *tr );
    void (*GetAimVector)( edict_t *e, float speed, float *rtn );
    void (*ServerCommand)( char *command );// Cbuf_AddText()
    void (*ServerExecute)( void ); // Cbuf_Execute()
    void (*ClientCommand)( edict_t *p, char *format, ... );
    void (*ParticleEffect)( vec_t *origin, vec_t *dir, float color, float count );
    void (*LightStyle)( int style, char *val );
    int (*DecalIndex)( char *name );
    int (*PointContents)( vec_t *origin );

    // message funcs
    void (*MessageBegin)( int dest, int type, vec_t *origin, edict_t *e );
    void (*MessageEnd)( void );
    void (*WriteByte)( int v );
    void (*WriteChar)( int v );
    void (*WriteShort)( int v );
    void (*WriteLong)( int v );
    void (*WriteAngle)( float v );
    void (*WriteCoord)( float v );
    void (*WriteString)( char *str );
    void (*WriteEntity)( int ent );

    // cvar funcs
    void (*CvarRegister)( cvar_t *cvar );
    float (*CvarGetFloat)( char *name );
    char *(*CvarGetString)( char *name );
    void (*CvarSetFloat)( char *name, float value );
    void (*CvarSetString)( char *name, char *value );

    // printing funcs
    void (*AlertMessage)( alert_type_t type, char *format, ... );

    // stdio FILE*
    void (*EngineFprintf)( void *file, char *format, ... );

    // private data funcs
    void *(*PvAllocEntPrivateData)( edict_t *e, size_t size );
    void *(*PvEntPrivateData)( edict_t *e );
    void (*FreeEntPrivateData)( edict_t *e );

    // string offset funcs
    char *(*SzFromIndex)( string_t offset );
    string_t (*AllocEngineString)( const char *s );

    // entity pointer conversion funcs
    entvars_t *(*GetVarsOfEnt)( edict_t *e );
    edict_t *(*PEntityOfEntOffset)( unsigned int offset );
    unsigned int *(*EntOffsetOfPEntity)( edict_t *e );
    int (*IndexOfEdict)( edict_t *e );
    edict_t *(*PEntityOfEntIndex)( int i );
    edict_t *(*FindEntityByVars)( entvars_t *vars );

    void *(*GetModelPtr)( edict_t *e );
    int *(*RegUserMsg)( char *name, int size );
    void (*AnimationAutomove)( edict_t *e, int bone, vec_t *origin, vec_t *angles );
    void (*GetBonePosition)( edict_t *e, int bone, vec_t *origin, vec_t *angles );

    void *(*FunctionFromName)( char *name );
    char *(*NameForFunction)( void *func );

    void *(*ClientPrintF)( edict_t *e, print_type_t ptype, char *message );
    void *(*ServerPrint)( char *message );
    char *(*Cmd_Args)( void );
    char *(*Cmd_Argv)( int i );
    int (*Cmd_Argc)( void );

    void (*GetAttachment)( edict_t *e, int attachment, vec_t *origin, vec_t *angles );

    void (*CRC32_Init)( unsigned int *crc32 );
    void (*CRC32_ProcessBuffer)( unsigned int *crc32, byte *buf, unsigned int size );
    void (*CRC32_ProcessByte)( unsigned int *crc32, byte b );
    void (*CRC32_Final)( unsigned int *crc32);

    int (*RandomLong)( int low, int high );
    float (*RandomFloat)( float low, float high );

    void (*SetView)( edict_t *p, edict_t *viewent );
    float (*Time)( void );
    void (*CrosshairAngle)( edict_t *e, float pitch, float yaw );
    byte *(*LoafFileForMe)( char *fname, int *len );
    void (*FreeFile)( void *buf );

    void (*EndSection)( char *name );
    int (*CompareFileTime)( char *name1, char*name2, int *compare );
    void (*GetGameDir)( char *gamedir );
    void (*Cvar_RegisterVariable)( cvar_t *variable );
    void (*FadeClientVolume)( edict_t *p, int percent, int fadeouts, int holdtime, int fadeins );
    void (*SetClientMaxspeed)( edict_t *p, float maxspeed );
    edict_t *(*CreateFakeClient)( char *netname );
    void (*RunPlayerMove)( edict_t *p, vec_t *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec );
    int (*NumberOfEntities)( void );
    char *(*GetInfoKeyBuffer)( edict_t *e );
    char *(*InfoKeyValue)( char *ib, char *key );
    void (*SetInfoKeyValue)( char *ib, char *key, char *value );
    void (*SetClientKeyValue)( int clientindex, char *ib, char *key, char *value );
    int (*IsMapValid)( char *filename );
    void (*StaticDecal)( vec_t *origin, int decalindex, int entityindex, int modelindex );
    int (*PrecacheGeneric)( char *s );
    int (*GetPlayerUserid )( edict_t *e );
    void (*BuildSoundMsg)( edict_t *e, int channel, char *sample, float vol, float attenuation, int flags, int pitch, int mdest, int mtype, vec_t *origin, edict_t *p );
    qboolean (*IsDedicatedServer)( void );
    cvar_t *(*CvarGetPointer)( char *name );
    unsigned int (*GetPlayerWONId)( edict_t *e);
} engineapi_t;

#endif // SDK_ENGAPI_H

