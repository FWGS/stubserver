#include <string.h>
#include <stdio.h>

#include "sdk_types.h"

int read_vec3(vec_t *v, const char *str)
{
   return sscanf(str, "%f %f %f", &v[0], &v[1], &v[2]) == 3;
}

int copy_vec3(vec_t *dest, vec_t *src)
{
    memcpy(&src, &dest, 3 * sizeof( float ));
}
