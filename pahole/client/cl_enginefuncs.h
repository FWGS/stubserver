typedef int int32;
typedef struct wrect_s wrect_t;
#include "cmdalias.h"
struct cl_enginefuncs_s {
    /* typedef pfnEngSrc_pfnSPR_Load_t */ int                    (*pfnSPR_Load)(const char  *); /*     0     4 */
    /* typedef pfnEngSrc_pfnSPR_Frames_t */ int                        (*pfnSPR_Frames)(int); /*     4     4 */
    /* typedef pfnEngSrc_pfnSPR_Height_t */ int                        (*pfnSPR_Height)(int, int); /*     8     4 */
    /* typedef pfnEngSrc_pfnSPR_Width_t */ int                        (*pfnSPR_Width)(int, int); /*    12     4 */
    /* typedef pfnEngSrc_pfnSPR_Set_t */ void                       (*pfnSPR_Set)(int, int, int, int); /*    16     4 */
	/* typedef pfnEngSrc_pfnSPR_Draw_t */ void                       (*pfnSPR_Draw)(int, int, int, const struct rect_s  *); /*    20     4 */
	/* typedef pfnEngSrc_pfnSPR_DrawHoles_t */ void                       (*pfnSPR_DrawHoles)(int, int, int, const struct rect_s  *); /*    24     4 */
	/* typedef pfnEngSrc_pfnSPR_DrawAdditive_t */ void                       (*pfnSPR_DrawAdditive)(int, int, int, const struct rect_s  *); /*    28     4 */
	/* typedef pfnEngSrc_pfnSPR_EnableScissor_t */ void                       (*pfnSPR_EnableScissor)(int, int, int, int); /*    32     4 */
	/* typedef pfnEngSrc_pfnSPR_DisableScissor_t */ void                       (*pfnSPR_DisableScissor)(void); /*    36     4 */
	/* typedef pfnEngSrc_pfnSPR_GetList_t */ struct client_sprite_s *    (*pfnSPR_GetList)(char *, int *); /*    40     4 */
	/* typedef pfnEngSrc_pfnFillRGBA_t */ void                       (*pfnFillRGBA)(int, int, int, int, int, int, int, int); /*    44     4 */
	/* typedef pfnEngSrc_pfnGetScreenInfo_t */ int                        (*pfnGetScreenInfo)(struct SCREENINFO_s *); /*    48     4 */
    /* typedef pfnEngSrc_pfnSetCrosshair_t */ void                       (*pfnSetCrosshair)(int, wrect_t, int, int, int); /*    52     4 */
	/* typedef pfnEngSrc_pfnRegisterVariable_t */ struct cvar_s *             (*pfnRegisterVariable)(char *, char *, int); /*    56     4 */
	/* typedef pfnEngSrc_pfnGetCvarFloat_t */ float                      (*pfnGetCvarFloat)(char *); /*    60     4 */
	/* --- cacheline 1 boundary (64 bytes) --- */
	/* typedef pfnEngSrc_pfnGetCvarString_t */ char *                     (*pfnGetCvarString)(char *); /*    64     4 */
	/* typedef pfnEngSrc_pfnAddCommand_t */ int                        (*pfnAddCommand)(char *, void (*)(void)); /*    68     4 */
    /* typedef pfnEngSrc_pfnHookUserMsg_t */ int                        (*pfnHookUserMsg)(char *, void*); /*    72     4 */
	/* typedef pfnEngSrc_pfnServerCmd_t */ int                        (*pfnServerCmd)(char *); /*    76     4 */
	/* typedef pfnEngSrc_pfnClientCmd_t */ int                        (*pfnClientCmd)(char *); /*    80     4 */
	/* typedef pfnEngSrc_pfnGetPlayerInfo_t */ void                       (*pfnGetPlayerInfo)(int, struct hud_player_info_s *); /*    84     4 */
	/* typedef pfnEngSrc_pfnPlaySoundByName_t */ void                       (*pfnPlaySoundByName)(char *, float); /*    88     4 */
	/* typedef pfnEngSrc_pfnPlaySoundByIndex_t */ void                       (*pfnPlaySoundByIndex)(int, float); /*    92     4 */
	/* typedef pfnEngSrc_pfnAngleVectors_t */ void                       (*pfnAngleVectors)(const float  *, float *, float *, float *); /*    96     4 */
	/* typedef pfnEngSrc_pfnTextMessageGet_t */ struct client_textmessage_s * (*pfnTextMessageGet)(const char  *); /*   100     4 */
	/* typedef pfnEngSrc_pfnDrawCharacter_t */ int                        (*pfnDrawCharacter)(int, int, int, int, int, int); /*   104     4 */
	/* typedef pfnEngSrc_pfnDrawConsoleString_t */ int                        (*pfnDrawConsoleString)(int, int, char *); /*   108     4 */
	/* typedef pfnEngSrc_pfnDrawSetTextColor_t */ void                       (*pfnDrawSetTextColor)(float, float, float); /*   112     4 */
	/* typedef pfnEngSrc_pfnDrawConsoleStringLen_t */ void                       (*pfnDrawConsoleStringLen)(const char  *, int *, int *); /*   116     4 */
	/* typedef pfnEngSrc_pfnConsolePrint_t */ void                       (*pfnConsolePrint)(const char  *); /*   120     4 */
	/* typedef pfnEngSrc_pfnCenterPrint_t */ void                       (*pfnCenterPrint)(const char  *); /*   124     4 */
	/* --- cacheline 2 boundary (128 bytes) --- */
	/* typedef pfnEngSrc_GetWindowCenterX_t */ int                        (*GetWindowCenterX)(void); /*   128     4 */
	/* typedef pfnEngSrc_GetWindowCenterY_t */ int                        (*GetWindowCenterY)(void); /*   132     4 */
	/* typedef pfnEngSrc_GetViewAngles_t */ void                       (*GetViewAngles)(float *); /*   136     4 */
	/* typedef pfnEngSrc_SetViewAngles_t */ void                       (*SetViewAngles)(float *); /*   140     4 */
	/* typedef pfnEngSrc_GetMaxClients_t */ int                        (*GetMaxClients)(void); /*   144     4 */
	/* typedef pfnEngSrc_Cvar_SetValue_t */ void                       (*Cvar_SetValue)(char *, float); /*   148     4 */
	/* typedef pfnEngSrc_Cmd_Argc_t */ int                        (*Cmd_Argc)(void); /*   152     4 */
	/* typedef pfnEngSrc_Cmd_Argv_t */ char *                     (*Cmd_Argv)(int);  /*   156     4 */
	/* typedef pfnEngSrc_Con_Printf_t */ void                       (*Con_Printf)(char *, ...); /*   160     4 */
	/* typedef pfnEngSrc_Con_DPrintf_t */ void                       (*Con_DPrintf)(char *, ...); /*   164     4 */
	/* typedef pfnEngSrc_Con_NPrintf_t */ void                       (*Con_NPrintf)(int, char *, ...); /*   168     4 */
	/* typedef pfnEngSrc_Con_NXPrintf_t */ void                       (*Con_NXPrintf)(struct con_nprint_s *, char *, ...); /*   172     4 */
	/* typedef pfnEngSrc_PhysInfo_ValueForKey_t */ const char  *              (*PhysInfo_ValueForKey)(const char  *); /*   176     4 */
	/* typedef pfnEngSrc_ServerInfo_ValueForKey_t */ const char  *              (*ServerInfo_ValueForKey)(const char  *); /*   180     4 */
	/* typedef pfnEngSrc_GetClientMaxspeed_t */ float                      (*GetClientMaxspeed)(void); /*   184     4 */
	/* typedef pfnEngSrc_CheckParm_t */ int                        (*CheckParm)(char *, char * *); /*   188     4 */
	/* --- cacheline 3 boundary (192 bytes) --- */
	/* typedef pfnEngSrc_Key_Event_t */ void                       (*Key_Event)(int, int); /*   192     4 */
	/* typedef pfnEngSrc_GetMousePosition_t */ void                       (*GetMousePosition)(int *, int *); /*   196     4 */
	/* typedef pfnEngSrc_IsNoClipping_t */ int                        (*IsNoClipping)(void); /*   200     4 */
	/* typedef pfnEngSrc_GetLocalPlayer_t */ struct cl_entity_s *        (*GetLocalPlayer)(void); /*   204     4 */
	/* typedef pfnEngSrc_GetViewModel_t */ struct cl_entity_s *        (*GetViewModel)(void); /*   208     4 */
	/* typedef pfnEngSrc_GetEntityByIndex_t */ struct cl_entity_s *        (*GetEntityByIndex)(int); /*   212     4 */
	/* typedef pfnEngSrc_GetClientTime_t */ float                      (*GetClientTime)(void); /*   216     4 */
	/* typedef pfnEngSrc_V_CalcShake_t */ void                       (*V_CalcShake)(void); /*   220     4 */
	/* typedef pfnEngSrc_V_ApplyShake_t */ void                       (*V_ApplyShake)(float *, float *, float); /*   224     4 */
	/* typedef pfnEngSrc_PM_PointContents_t */ int                        (*PM_PointContents)(float *, int *); /*   228     4 */
	/* typedef pfnEngSrc_PM_WaterEntity_t */ int                        (*PM_WaterEntity)(float *); /*   232     4 */
	/* typedef pfnEngSrc_PM_TraceLine_t */ struct pmtrace_s *          (*PM_TraceLine)(float *, float *, int, int, int); /*   236     4 */
	/* typedef pfnEngSrc_CL_LoadModel_t */ struct model_s *            (*CL_LoadModel)(const char  *, int *); /*   240     4 */
	/* typedef pfnEngSrc_CL_CreateVisibleEntity_t */ int                        (*CL_CreateVisibleEntity)(int, struct cl_entity_s *); /*   244     4 */
    /* typedef pfnEngSrc_GetSpritePointer_t */ const struct model_s  *     (*GetSpritePointer)(int); /*   248     4 */
	/* typedef pfnEngSrc_pfnPlaySoundByNameAtLocation_t */ void                       (*pfnPlaySoundByNameAtLocation)(char *, float, float *); /*   252     4 */
	/* --- cacheline 4 boundary (256 bytes) --- */
	/* typedef pfnEngSrc_pfnPrecacheEvent_t */ short unsigned int         (*pfnPrecacheEvent)(int, const char  *); /*   256     4 */
	/* typedef pfnEngSrc_pfnPlaybackEvent_t */ void                       (*pfnPlaybackEvent)(int, const struct edict_s  *, short unsigned int, float, float *, float *, float, float, int, int, int, int); /*   260     4 */
	/* typedef pfnEngSrc_pfnWeaponAnim_t */ void                       (*pfnWeaponAnim)(int, int); /*   264     4 */
	/* typedef pfnEngSrc_pfnRandomFloat_t */ float                      (*pfnRandomFloat)(float, float); /*   268     4 */
	/* typedef pfnEngSrc_pfnRandomLong_t */ int32                      (*pfnRandomLong)(int32, int32); /*   272     4 */
	/* typedef pfnEngSrc_pfnHookEvent_t */ void                       (*pfnHookEvent)(char *, void (*)(struct event_args_s *)); /*   276     4 */
	/* typedef pfnEngSrc_Con_IsVisible_t */ int                        (*Con_IsVisible)(void); /*   280     4 */
	/* typedef pfnEngSrc_pfnGetGameDirectory_t */ const char  *              (*pfnGetGameDirectory)(void); /*   284     4 */
	/* typedef pfnEngSrc_pfnGetCvarPointer_t */ struct cvar_s *             (*pfnGetCvarPointer)(const char  *); /*   288     4 */
	/* typedef pfnEngSrc_Key_LookupBinding_t */ const char  *              (*Key_LookupBinding)(const char  *); /*   292     4 */
	/* typedef pfnEngSrc_pfnGetLevelName_t */ const char  *              (*pfnGetLevelName)(void); /*   296     4 */
	/* typedef pfnEngSrc_pfnGetScreenFade_t */ void                       (*pfnGetScreenFade)(struct screenfade_s *); /*   300     4 */
	/* typedef pfnEngSrc_pfnSetScreenFade_t */ void                       (*pfnSetScreenFade)(struct screenfade_s *); /*   304     4 */
	/* typedef pfnEngSrc_VGui_GetPanel_t */ void *                     (*VGui_GetPanel)(void); /*   308     4 */
	/* typedef pfnEngSrc_VGui_ViewportPaintBackground_t */ void                       (*VGui_ViewportPaintBackground)(int *); /*   312     4 */
	/* typedef pfnEngSrc_COM_LoadFile_t */ byte *                     (*COM_LoadFile)(char *, int, int *); /*   316     4 */
	/* --- cacheline 5 boundary (320 bytes) --- */
	/* typedef pfnEngSrc_COM_ParseFile_t */ char *                     (*COM_ParseFile)(char *, char *); /*   320     4 */
	/* typedef pfnEngSrc_COM_FreeFile_t */ void                       (*COM_FreeFile)(void *); /*   324     4 */
	struct triangleapi_s *      pTriAPI;                                              /*   328     4 */
	struct efx_api_s *          pEfxAPI;                                              /*   332     4 */
	struct event_api_s *        pEventAPI;                                            /*   336     4 */
	struct demo_api_s *         pDemoAPI;                                             /*   340     4 */
	struct net_api_s *          pNetAPI;                                              /*   344     4 */
	struct IVoiceTweak_s *      pVoiceTweak;                                          /*   348     4 */
	/* typedef pfnEngSrc_IsSpectateOnly_t */ int                        (*IsSpectateOnly)(void); /*   352     4 */
	/* typedef pfnEngSrc_LoadMapSprite_t */ struct model_s *            (*LoadMapSprite)(const char  *); /*   356     4 */
	/* typedef pfnEngSrc_COM_AddAppDirectoryToSearchPath_t */ void                       (*COM_AddAppDirectoryToSearchPath)(const char  *, const char  *); /*   360     4 */
	/* typedef pfnEngSrc_COM_ExpandFilename_t */ int                        (*COM_ExpandFilename)(const char  *, char *, int); /*   364     4 */
	/* typedef pfnEngSrc_PlayerInfo_ValueForKey_t */ const char  *              (*PlayerInfo_ValueForKey)(int, const char  *); /*   368     4 */
	/* typedef pfnEngSrc_PlayerInfo_SetValueForKey_t */ void                       (*PlayerInfo_SetValueForKey)(const char  *, const char  *); /*   372     4 */
	/* typedef pfnEngSrc_GetPlayerUniqueID_t */ qboolean                   (*GetPlayerUniqueID)(int, char *); /*   376     4 */
	/* typedef pfnEngSrc_GetTrackerIDForPlayer_t */ int                        (*GetTrackerIDForPlayer)(int); /*   380     4 */
	/* --- cacheline 6 boundary (384 bytes) --- */
	/* typedef pfnEngSrc_GetPlayerForTrackerID_t */ int                        (*GetPlayerForTrackerID)(int); /*   384     4 */
	/* typedef pfnEngSrc_pfnServerCmdUnreliable_t */ int                        (*pfnServerCmdUnreliable)(char *); /*   388     4 */
	/* typedef pfnEngSrc_GetMousePos_t */ void                       (*pfnGetMousePos)(struct tagPOINT *); /*   392     4 */
	/* typedef pfnEngSrc_SetMousePos_t */ void                       (*pfnSetMousePos)(int, int); /*   396     4 */
	/* typedef pfnEngSrc_SetMouseEnable_t */ void                       (*pfnSetMouseEnable)(qboolean); /*   400     4 */
	/* typedef pfnEngSrc_GetFirstCVarPtr_t */ struct cvar_s *             (*GetFirstCvarPtr)(void); /*   404     4 */
	/* typedef pfnEngSrc_GetFirstCmdFunctionHandle_t */ unsigned int               (*GetFirstCmdFunctionHandle)(void); /*   408     4 */
	/* typedef pfnEngSrc_GetNextCmdFunctionHandle_t */ unsigned int               (*GetNextCmdFunctionHandle)(unsigned int); /*   412     4 */
	/* typedef pfnEngSrc_GetCmdFunctionName_t */ const char  *              (*GetCmdFunctionName)(unsigned int); /*   416     4 */
	/* typedef pfnEngSrc_GetClientOldTime_t */ float                      (*hudGetClientOldTime)(void); /*   420     4 */
	/* typedef pfnEngSrc_GetServerGravityValue_t */ float                      (*hudGetServerGravityValue)(void); /*   424     4 */
	/* typedef pfnEngSrc_GetModelByIndex_t */ struct model_s *            (*hudGetModelByIndex)(int); /*   428     4 */
	/* typedef pfnEngSrc_pfnSetFilterMode_t */ void                       (*pfnSetFilterMode)(int); /*   432     4 */
	/* typedef pfnEngSrc_pfnSetFilterColor_t */ void                       (*pfnSetFilterColor)(float, float, float); /*   436     4 */
	/* typedef pfnEngSrc_pfnSetFilterBrightness_t */ void                       (*pfnSetFilterBrightness)(float); /*   440     4 */
    /* typedef pfnEngSrc_pfnSequenceGet_t */ struct sequenceEntry_s *          (*pfnSequenceGet)(const char  *, const char  *); /*   444     4 */
	/* --- cacheline 7 boundary (448 bytes) --- */
	/* typedef pfnEngSrc_pfnSPR_DrawGeneric_t */ void                       (*pfnSPR_DrawGeneric)(int, int, int, const struct rect_s  *, int, int, int, int); /*   448     4 */
    /* typedef pfnEngSrc_pfnSequencePickSentence_t */ struct sentenceEntry_s *          (*pfnSequencePickSentence)(const char  *, int, int *); /*   452     4 */
	/* typedef pfnEngSrc_pfnDrawString_t */ int                        (*pfnDrawString)(int, int, const char  *, int, int, int); /*   456     4 */
	/* typedef pfnEngSrc_pfnDrawStringReverse_t */ int                        (*pfnDrawStringReverse)(int, int, const char  *, int, int, int); /*   460     4 */
	/* typedef pfnEngSrc_LocalPlayerInfo_ValueForKey_t */ const char  *              (*LocalPlayerInfo_ValueForKey)(const char  *); /*   464     4 */
	/* typedef pfnEngSrc_pfnVGUI2DrawCharacter_t */ int                        (*pfnVGUI2DrawCharacter)(int, int, int, unsigned int); /*   468     4 */
	/* typedef pfnEngSrc_pfnVGUI2DrawCharacterAdd_t */ int                        (*pfnVGUI2DrawCharacterAdd)(int, int, int, int, int, int, unsigned int); /*   472     4 */
	/* typedef pfnEngSrc_COM_GetApproxWavePlayLength */ unsigned int               (*COM_GetApproxWavePlayLength)(const char  *); /*   476     4 */
	/* typedef pfnEngSrc_pfnGetCareerUI_t */ void *                     (*pfnGetCareerUI)(void); /*   480     4 */
	/* typedef pfnEngSrc_Cvar_Set_t */ void                       (*Cvar_Set)(char *, char *); /*   484     4 */
	/* typedef pfnEngSrc_pfnIsPlayingCareerMatch_t */ int                        (*pfnIsCareerMatch)(void); /*   488     4 */
	/* typedef pfnEngSrc_pfnPlaySoundVoiceByName_t */ void                       (*pfnPlaySoundVoiceByName)(char *, float, int); /*   492     4 */
	/* typedef pfnEngSrc_pfnPrimeMusicStream_t */ void                       (*pfnPrimeMusicStream)(char *, int); /*   496     4 */
	/* typedef pfnEngSrc_GetAbsoluteTime_t */ double                     (*GetAbsoluteTime)(void); /*   500     4 */
	/* typedef pfnEngSrc_pfnProcessTutorMessageDecayBuffer_t */ void                       (*pfnProcessTutorMessageDecayBuffer)(int *, int); /*   504     4 */
	/* typedef pfnEngSrc_pfnConstructTutorMessageDecayBuffer_t */ void                       (*pfnConstructTutorMessageDecayBuffer)(int *, int); /*   508     4 */
	/* --- cacheline 8 boundary (512 bytes) --- */
	/* typedef pfnEngSrc_pfnResetTutorMessageDecayData_t */ void                       (*pfnResetTutorMessageDecayData)(void); /*   512     4 */
	/* typedef pfnEngSrc_pfnPlaySoundByNameAtPitch_t */ void                       (*pfnPlaySoundByNameAtPitch)(char *, float, int); /*   516     4 */
	/* typedef pfnEngSrc_pfnFillRGBABlend_t */ void                       (*pfnFillRGBABlend)(int, int, int, int, int, int, int, int); /*   520     4 */
	/* typedef pfnEngSrc_pfnGetAppID_t */ int                        (*pfnGetAppID)(void); /*   524     4 */
	/* typedef pfnEngSrc_pfnGetAliases_t */ cmdalias_t *               (*pfnGetAliasList)(void); /*   528     4 */
	/* typedef pfnEngSrc_pfnVguiWrap2_GetMouseDelta_t */ void                       (*pfnVguiWrap2_GetMouseDelta)(int *, int *); /*   532     4 */

	/* size: 536, cachelines: 9, members: 134 */
	/* last cacheline: 24 bytes */
};
