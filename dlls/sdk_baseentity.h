#include "sdk_common.h"
#include "sdk_types.h"

typedef struct baseentity_s baseentity_t;

struct baseentity_s
{
    void (*Use)( entvars_t , entvars_t );
    void (*Touch)( entvars_t , entvars_t );
    void (*Think)( entvars_t ) ;
    void (*KeyValue)( entvars_t , keyvalue_t * );
    entvars_t *pev;
};
