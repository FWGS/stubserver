#include "sdk_common.h"
#include <stdio.h>

struct grenade
{
    entvars_t *pev;
};

void grenade( entvars_t *vars )
{
    struct grenade *t;
    com.engfuncs->AlertMessage( AT_CONSOLE, "spawnfunc %s %x %x\n", __FUNCTION__, vars, vars->pContainingEntity );

    if( !vars)
    {
        edict_t *t = com.engfuncs->CreateEntity();
        vars = &t->v;
        com.engfuncs->AlertMessage( AT_CONSOLE, "create %s %x %x\n", __FUNCTION__, vars, vars->pContainingEntity );
    }

    t = vars->pContainingEntity->pvPrivateData = com.engfuncs->PvAllocEntPricateData( vars->pContainingEntity, sizeof( struct grenade ) );
    t->pev = vars;
    t->pev->flags = 0;
    com.engfuncs->SetModel( vars->pContainingEntity, "models/grenade.mdl");
    t->pev->classname = MAKE_STRING( "grenade" );
    com.engfuncs->SetView(t->pev->pContainingEntity, t->pev->pContainingEntity);
    com.engfuncs->SetOrigin(t->pev->pContainingEntity,t->pev->origin);
    t->pev->health = 100;
    t->pev->armorvalue = 0;
    t->pev->takedamage = DAMAGE_YES;
    t->pev->solid = SOLID_SLIDEBOX;
    t->pev->movetype = MOVETYPE_NOCLIP;
}
