#define BitSet(BitVector, bit) ((int)(BitVector) & (bit))

int read_vec3(vec_t *v, const char *str);
int copy_vec3(vec_t *dest, vec_t *src);
