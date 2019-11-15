/*
sdk_types.h - main types defination
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
#ifndef SDK_TYPES_H
#define SDK_TYPES_H

#include <stddef.h>

typedef int string_t;
typedef float vec_t;
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef struct edict_s edict_t;
typedef struct entity_state_s entity_state_t;
typedef struct entvars_s entvars_t;
typedef struct keyvalue_s keyvalue_t;
typedef unsigned char byte;
typedef byte rgb_t[3];
typedef struct globalvars_s globalvars_t;
typedef struct traceresult_s traceresult_t;
#undef false
#undef true
typedef enum { false, true } qboolean;
typedef struct cvar_s cvar_t;
typedef enum { AT_NOTICE, AT_CONSOLE, AT_AICONSOLE, AT_WARNING, AT_ERROR, AT_LOGGED } alert_type_t;
#endif // SDK_TYPES_H

