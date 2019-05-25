#include <string.h>
#include <stdio.h>

#include "sdk_common.h"

void Host_Say(edict_t *ent)
{
    int SayText = com.engfuncs->RegUserMsg( "SayText", -1 );
    char message[128];
    const char *say_cmd = "say";
    const char *cmd = com.engfuncs->Cmd_Argv( 0 );
    
    if( strcasecmp(cmd, say_cmd) == 0 )
    {
        
        char *args = (char *)com.engfuncs->Cmd_Args();
        
        if( args && *args == '"' )
        {
                args++;
                args[strlen( args ) - 1] = 0;
        }

        if(!args || !args[0])
            return;
        
        snprintf(message, sizeof(message), "%c%s: %s\n", 2, STRING(ent->v.netname), args);  
    
        com.engfuncs->ServerPrint(message);
             
        com.engfuncs->MessageBegin( MSG_ALL, SayText , NULL, NULL);
            com.engfuncs->WriteByte( com.engfuncs->IndexOfEdict( ent ) );
            com.engfuncs->WriteString( message );
        com.engfuncs->MessageEnd();

    }
}
