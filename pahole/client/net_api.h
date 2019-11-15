struct net_api_s {
	void                       (*InitNetworking)(void);                              /*     0     4 */
	void                       (*Status)(struct net_status_s *);                      /*     4     4 */
	void                       (*SendRequest)(int, int, int, double, struct netadr_s *, net_api_response_func_t); /*     8     4 */
	void                       (*CancelRequest)(int);                                /*    12     4 */
	void                       (*CancelAllRequests)(void);                           /*    16     4 */
	char *                     (*AdrToString)(struct netadr_s *);                     /*    20     4 */
	int                        (*CompareAdr)(struct netadr_s *, struct netadr_s *);    /*    24     4 */
	int                        (*StringToAdr)(char *, struct netadr_s *);             /*    28     4 */
	const char  *              (*ValueForKey)(const char  *, const char  *);         /*    32     4 */
	void                       (*RemoveKey)(char *, const char  *);                  /*    36     4 */
	void                       (*SetValueForKey)(char *, const char  *, const char  *, int); /*    40     4 */

	/* size: 44, cachelines: 1, members: 11 */
	/* last cacheline: 44 bytes */
};
