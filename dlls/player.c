#include "sdk_common.h"
#include <stdio.h>
struct player
{
    entvars_t *pev;
};

void player( entvars_t *vars )
{
    struct player *t;
    com.engfuncs->AlertMessage( AT_CONSOLE, "spawnfunc %s %x %x\n", __FUNCTION__, vars, vars->pContainingEntity );

    if( !vars)
    {
        edict_t *t = com.engfuncs->CreateEntity();
        vars = &t->v;
        com.engfuncs->AlertMessage( AT_CONSOLE, "create %s %x %x\n", __FUNCTION__, vars, vars->pContainingEntity );
    }

    t = vars->pContainingEntity->pvPrivateData = com.engfuncs->PvAllocEntPricateData( vars->pContainingEntity, sizeof( struct player ) );
    t->pev = vars;
    t->pev->flags |= FL_CLIENT;
    com.engfuncs->SetModel( vars->pContainingEntity, "models/player.mdl");
    t->pev->classname = MAKE_STRING( "player" );
   // com.engfuncs->SetView(t->pev->pContainingEntity, t->pev->pContainingEntity);
    vec3_t origin = {0,0,0};
    com.engfuncs->SetOrigin(t->pev->pContainingEntity,origin);
    t->pev->health = 100;
    t->pev->armorvalue = 0;
    t->pev->takedamage = DAMAGE_AIM;
    t->pev->solid = SOLID_SLIDEBOX;
    t->pev->movetype = MOVETYPE_WALK;
    t->pev->view_ofs[2] = 32;
}
