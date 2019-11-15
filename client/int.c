#include "sdk_common.h"
#include "../pahole/client/cl_enginefuncs.h"
#include "../pahole/client/ref_params.h"
#include "../pahole/client/cl_entity.h"
#include "mathlib.h"
struct cl_enginefuncs_s *pengfuncs;

void Initialize( struct cl_enginefuncs_s *pfuncs, int version )
{
	pengfuncs = pfuncs;
}

void HUD_Init( void )
{
}

void HUD_VidInit( void )
{
}
void HUD_Shutdown( void )
{
}
void HUD_Redraw( void )
{
}

void HUD_UpdateClientData( void )
{
}
void HUD_Reset( void )
{
}

void HUD_PlayerMove( void )
{
}

void HUD_PlayerMoveInit( void )
{
}

void HUD_PlayerMoveTexture( void )
{
}

void HUD_ConnectionlessPacket( void )
{
}

void HUD_GetHullBounds( void )
{
}

void HUD_Frame( void )
{
}

void HUD_PostRunCmd( void )
{
}
static int forward_key, side_key, jump_key;
int HUD_Key_Event( int down, int key, const char *binding )
{
	pengfuncs->Con_Printf("HUD_Key_Event(%d %d %s)\n", down, key, binding );
	if( !strcmp( binding, "cancelselect" ) )
		pengfuncs->pfnClientCmd("escape\n");

	else if( !strcmp( binding, "+forward" ) )
		forward_key = 1 * down;

	else if( !strcmp( binding, "+back" ) )
		forward_key = -1 * down;

	else if( !strcmp( binding, "+moveleft" ) )
		side_key = -1 * down;

	else if( !strcmp( binding, "+moveright" ) )
		side_key = 1 * down;

	else if( !strcmp( binding, "+jump" ) )
		jump_key = 1 * down;

	else return 1;

	return 0;
}

void HUD_AddEntity( void )
{
}

void HUD_CreateEntities( void )
{
}

void HUD_StudioEvent( void )
{
}

void HUD_TxferLocalOverrides( void )
{

}

void HUD_ProcessPlayerState( void )
{

}

void HUD_TxferPredictionData( void )
{

}

void HUD_TempEntUpdate( void )
{

}

void HUD_DrawNormalTriangles( void )
{

}

void HUD_DrawTransparentTriangles( void )
{

}

void HUD_GetUserEntity( void )
{

}

void Demo_ReadBuffer( void )
{

}

void CAM_Think( void )
{

}

void CL_IsThirdPerson( void )
{

}

void CL_CameraOffset( void )
{

}
static float forward, side;
void CL_CreateMove( float frametime, struct usercmd_s *cmd, int active )
{
	if( cmd )
	{
		cmd->forwardmove = (forward_key + forward) * 300;
		cmd->sidemove = (side_key + side) * 300;
		cmd->msec = 100;
		cmd->lerp_msec = 50;
		cmd->buttons = jump_key << 1;
		pengfuncs->GetViewAngles( cmd->angles );
	}
}

void IN_ActivateMouse( void )
{

}

void IN_DeactivateMouse( void )
{

}

void IN_MouseEvent( void )
{

}

void IN_Accumulate( void )
{

}

void IN_ClearStates( void )
{

}

void V_CalcRefdef( struct ref_params_s *rp )
{
	pengfuncs->GetViewAngles( rp->viewangles );
	rp->viewentity = 1;
	struct cl_entity_s *player = pengfuncs->GetLocalPlayer();
	VectorCopy(player->origin, rp->vieworg);
}

void KB_Find( void )
{

}


void IN_ClientMoveEvent( float forwardmove, float sidemove )
{
}
void IN_ClientLookEvent( float relyaw, float relpitch )
{
	vec3_t angles;
	pengfuncs->GetViewAngles( angles );
	angles[1] += relyaw;
	angles[0] += relpitch;
	pengfuncs->SetViewAngles( angles );
}
