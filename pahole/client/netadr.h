struct netadr_s {
	/* typedef netadrtype_t */ enum {
		NA_UNUSED = 0,
		NA_LOOPBACK = 1,
		NA_BROADCAST = 2,
		NA_IP = 3,
		NA_IPX = 4,
		NA_BROADCAST_IPX = 5,
	} type; /*     0     4 */
	unsigned char              ip[4];                                                /*     4     4 */
	unsigned char              ipx[10];                                              /*     8    10 */
	short unsigned int         port;                                                 /*    18     2 */

	/* size: 20, cachelines: 1, members: 4 */
	/* last cacheline: 20 bytes */
};
