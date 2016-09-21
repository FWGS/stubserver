/*
world.c - worldspawn entity stub
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
#include <stdio.h>
struct worldspawn
{
    entvars_t *pev;
};

void worldspawn( entvars_t *vars )
{
	struct worldspawn *t;

    t = vars->pContainingEntity->pvPrivateData = com.engfuncs->PvAllocEntPricateData( vars->pContainingEntity, sizeof( struct worldspawn ) );
	t->pev = vars;
}

globalvars_t *gpGlobals;

int main()
{
    printf("%d\n", (int)sizeof(entvars_t));
}
