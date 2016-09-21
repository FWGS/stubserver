/*
mathlib.h - base math functions
Copyright (C) 2007 Uncle Mike

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef MATHLIB_H
#define MATHLIB_H

#include <math.h>

#pragma warning(disable : 4201)	// nonstandard extension used

// euler angle order
#define PITCH		0
#define YAW		1
#define ROLL		2

#ifndef M_PI
#define M_PI		(float)3.14159265358979323846
#endif

#ifndef M_PI2
#define M_PI2		(float)6.28318530717958647692
#endif

#define M_PI_F		((float)(M_PI))
#define M_PI2_F		((float)(M_PI2))

#define RAD2DEG( x )	((float)(x) * (float)(180.f / M_PI))
#define DEG2RAD( x )	((float)(x) * (float)(M_PI / 180.f))

#define SIDE_FRONT		0
#define SIDE_BACK		1
#define SIDE_ON		2
#define SIDE_CROSS		-2

#define PLANE_X		0	// 0 - 2 are axial planes
#define PLANE_Y		1	// 3 needs alternate calc
#define PLANE_Z		2
#define PLANE_NONAXIAL	3

#define EQUAL_EPSILON	0.001f
#define STOP_EPSILON	0.1f
#define ON_EPSILON		0.1f

#define RAD_TO_STUDIO	(32768.0 / M_PI)
#define STUDIO_TO_RAD	(M_PI / 32768.0)
#define nanmask		(255<<23)

#define Q_rint(x)		((x) < 0 ? ((int)((x)-0.5f)) : ((int)((x)+0.5f)))
#define IS_NAN(x)		(((*(int *)&x)&nanmask)==nanmask)

#define VectorIsNAN(v) (IS_NAN(v[0]) || IS_NAN(v[1]) || IS_NAN(v[2]))	
#define DotProduct(x,y) ((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define DotProductAbs(x,y) (abs((x)[0]*(y)[0])+abs((x)[1]*(y)[1])+abs((x)[2]*(y)[2]))
#define DotProductFabs(x,y) (fabs((x)[0]*(y)[0])+fabs((x)[1]*(y)[1])+fabs((x)[2]*(y)[2]))
#define CrossProduct(a,b,c) ((c)[0]=(a)[1]*(b)[2]-(a)[2]*(b)[1],(c)[1]=(a)[2]*(b)[0]-(a)[0]*(b)[2],(c)[2]=(a)[0]*(b)[1]-(a)[1]*(b)[0])
#define Vector2Subtract(a,b,c) ((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1])
#define VectorSubtract(a,b,c) ((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define Vector2Add(a,b,c) ((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1])
#define VectorAdd(a,b,c) ((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define Vector2Copy(a,b) ((b)[0]=(a)[0],(b)[1]=(a)[1])
#define VectorCopy(a,b) ((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define Vector4Copy(a,b) ((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2],(b)[3]=(a)[3])
#define VectorScale(in, scale, out) ((out)[0] = (in)[0] * (scale),(out)[1] = (in)[1] * (scale),(out)[2] = (in)[2] * (scale))
#define VectorCompare(v1,v2)	((v1)[0]==(v2)[0] && (v1)[1]==(v2)[1] && (v1)[2]==(v2)[2])
#define VectorDivide( in, d, out ) VectorScale( in, (1.0f / (d)), out )
#define VectorMax(a) ( max((a)[0], max((a)[1], (a)[2])) )
#define VectorAvg(a) ( ((a)[0] + (a)[1] + (a)[2]) / 3 )
#define VectorLength(a) ( sqrt( DotProduct( a, a )))
#define VectorLength2(a) (DotProduct( a, a ))
#define VectorDistance(a, b) (sqrt( VectorDistance2( a, b )))
#define VectorDistance2(a, b) (((a)[0] - (b)[0]) * ((a)[0] - (b)[0]) + ((a)[1] - (b)[1]) * ((a)[1] - (b)[1]) + ((a)[2] - (b)[2]) * ((a)[2] - (b)[2]))
#define Vector2Average(a,b,o)	((o)[0]=((a)[0]+(b)[0])*0.5,(o)[1]=((a)[1]+(b)[1])*0.5)
#define VectorAverage(a,b,o)	((o)[0]=((a)[0]+(b)[0])*0.5,(o)[1]=((a)[1]+(b)[1])*0.5,(o)[2]=((a)[2]+(b)[2])*0.5)
#define Vector2Set(v, x, y) ((v)[0]=(x),(v)[1]=(y))
#define VectorSet(v, x, y, z) ((v)[0]=(x),(v)[1]=(y),(v)[2]=(z))
#define Vector4Set(v, a, b, c, d) ((v)[0]=(a),(v)[1]=(b),(v)[2]=(c),(v)[3] = (d))
#define VectorClear(x) ((x)[0]=(x)[1]=(x)[2]=0)
#define Vector2Lerp( v1, lerp, v2, c ) ((c)[0] = (v1)[0] + (lerp) * ((v2)[0] - (v1)[0]), (c)[1] = (v1)[1] + (lerp) * ((v2)[1] - (v1)[1]))
#define VectorLerp( v1, lerp, v2, c ) ((c)[0] = (v1)[0] + (lerp) * ((v2)[0] - (v1)[0]), (c)[1] = (v1)[1] + (lerp) * ((v2)[1] - (v1)[1]), (c)[2] = (v1)[2] + (lerp) * ((v2)[2] - (v1)[2]))
#define VectorNormalize( v ) { float ilength = (float)sqrt(DotProduct(v, v));if (ilength) ilength = 1.0f / ilength;v[0] *= ilength;v[1] *= ilength;v[2] *= ilength; }
#define VectorNormalize2( v, dest ) {float ilength = (float)sqrt(DotProduct(v,v));if (ilength) ilength = 1.0f / ilength;dest[0] = v[0] * ilength;dest[1] = v[1] * ilength;dest[2] = v[2] * ilength; }
#define VectorNormalizeFast( v ) {float	ilength = (float)rsqrt(DotProduct(v,v)); v[0] *= ilength; v[1] *= ilength; v[2] *= ilength; }
#define VectorNormalizeLength( v ) VectorNormalizeLength2((v), (v))
#define VectorNegate(x, y) ((y)[0] = -(x)[0], (y)[1] = -(x)[1], (y)[2] = -(x)[2])
#define VectorM(scale1, b1, c) ((c)[0] = (scale1) * (b1)[0],(c)[1] = (scale1) * (b1)[1],(c)[2] = (scale1) * (b1)[2])
#define VectorMA(a, scale, b, c) ((c)[0] = (a)[0] + (scale) * (b)[0],(c)[1] = (a)[1] + (scale) * (b)[1],(c)[2] = (a)[2] + (scale) * (b)[2])
#define VectorMAMAM(scale1, b1, scale2, b2, scale3, b3, c) ((c)[0] = (scale1) * (b1)[0] + (scale2) * (b2)[0] + (scale3) * (b3)[0],(c)[1] = (scale1) * (b1)[1] + (scale2) * (b2)[1] + (scale3) * (b3)[1],(c)[2] = (scale1) * (b1)[2] + (scale2) * (b2)[2] + (scale3) * (b3)[2])
#define VectorIsNull( v ) ((v)[0] == 0.0f && (v)[1] == 0.0f && (v)[2] == 0.0f)
#define MakeRGBA( out, x, y, z, w ) Vector4Set( out, x, y, z, w )
#define PlaneDist(point,plane) ((plane)->type < 3 ? (point)[(plane)->type] : DotProduct((point), (plane)->normal))
#define PlaneDiff(point,plane) (((plane)->type < 3 ? (point)[(plane)->type] : DotProduct((point), (plane)->normal)) - (plane)->dist)
#define boundmax( num, high ) ( (num) < (high) ? (num) : (high) )
#define boundmin( num, low )  ( (num) >= (low) ? (num) : (low)  )
#define bound( low, num, high ) ( boundmin( boundmax(num, high), low ))
//#define bound( min, num, max ) ((num) >= (min) ? ((num) < (max) ? (num) : (max)) : (min))

float rsqrt( float number );
float anglemod( const float a );
unsigned short FloatToHalf( float v );
float HalfToFloat( unsigned short h );
int SignbitsForPlane( const vec3_t normal );
int NearestPOW( int value, qboolean roundDown );
void SinCos( float radians, float *sine, float *cosine );
#ifdef VECTORIZE_SINCOS
void SinCosFastVector(float r1, float r2, float r3, float r4,
					  float *s0, float *s1, float *s2, float *s3,
					  float *c0, float *c1, float *c2, float *c3);
#endif
float VectorNormalizeLength2( const vec3_t v, vec3_t out );
void VectorVectors( const vec3_t forward, vec3_t right, vec3_t up );
void VectorAngles( const float *forward, float *angles );
void AngleVectors( const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up );
void VectorsAngles( const vec3_t forward, const vec3_t right, const vec3_t up, vec3_t angles );
void RotatePointAroundVector( vec3_t dst, const vec3_t dir, const vec3_t point, float degrees );

void ClearBounds( vec3_t mins, vec3_t maxs );
void AddPointToBounds( const vec3_t v, vec3_t mins, vec3_t maxs );
qboolean BoundsIntersect( const vec3_t mins1, const vec3_t maxs1, const vec3_t mins2, const vec3_t maxs2 );
qboolean BoundsAndSphereIntersect( const vec3_t mins, const vec3_t maxs, const vec3_t origin, float radius );
float RadiusFromBounds( const vec3_t mins, const vec3_t maxs );

void AngleQuaternion( const vec3_t angles, vec4_t q );
void QuaternionSlerp( const vec4_t p, vec4_t q, float t, vec4_t qt );
float RemapVal( float val, float A, float B, float C, float D );
float ApproachVal( float target, float value, float speed );


#endif//MATHLIB_H
