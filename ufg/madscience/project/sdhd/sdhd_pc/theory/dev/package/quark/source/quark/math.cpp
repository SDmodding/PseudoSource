// File Line: 38
// RVA: 0x1467910
void dynamic_initializer_for__UFG::qVector3::msDirLeft__()
{
  UFG::qVector3::msDirLeft = UFG::qVector3::msAxisY;
}

// File Line: 39
// RVA: 0x1467950
void dynamic_initializer_for__UFG::qVector3::msDirRight__()
{
  UFG::qVector3::msDirRight = UFG::qVector3::msAxisYNeg;
}

// File Line: 40
// RVA: 0x14678D0
void dynamic_initializer_for__UFG::qVector3::msDirFront__()
{
  UFG::qVector3::msDirFront = UFG::qVector3::msAxisX;
}

// File Line: 41
// RVA: 0x1467850
void dynamic_initializer_for__UFG::qVector3::msDirBack__()
{
  UFG::qVector3::msDirBack = UFG::qVector3::msAxisXNeg;
}

// File Line: 42
// RVA: 0x1467990
void dynamic_initializer_for__UFG::qVector3::msDirUp__()
{
  UFG::qVector3::msDirUp = UFG::qVector3::msAxisZ;
}

// File Line: 43
// RVA: 0x1467890
void dynamic_initializer_for__UFG::qVector3::msDirDown__()
{
  UFG::qVector3::msDirDown = UFG::qVector3::msAxisZNeg;
}

// File Line: 101
// RVA: 0x18ACF0
// local variable allocation has failed, the output may be wrong!
float __fastcall UFG::qSignedMod(double a, float b)
{
  float v2; // xmm1_4
  __m128 v3; // xmm2
  float v4; // xmm3_4
  int v5; // ecx

  LODWORD(v2) = LODWORD(b) & _xmm;
  v3 = *(__m128 *)&a;
  if ( v2 > 1.1754944e-38 )
  {
    v3.m128_f32[0] = *(float *)&a / v2;
    v4 = *(float *)&a / v2;
    v5 = (int)(float)(*(float *)&a / v2);
    if ( v5 != 0x80000000 && (float)v5 != v3.m128_f32[0] )
      v4 = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
    v3.m128_f32[0] = (float)(v3.m128_f32[0] - v4) * v2;
  }
  return v3.m128_f32[0];
}

// File Line: 115
// RVA: 0x18ACC0
__int64 __fastcall UFG::qSignedMod(int a, int b)
{
  int v2; // r8d
  __int64 result; // rax
  int v4; // eax

  v2 = b;
  if ( b < 0 )
    v2 = -b;
  result = (unsigned int)a;
  if ( v2 > 0 )
  {
    v4 = v2 * (a / v2);
    if ( a < 0 )
      v4 -= v2;
    return (unsigned int)(a - v4);
  }
  return result;
}

// File Line: 138
// RVA: 0x1895E0
__int64 __fastcall UFG::qRandom(unsigned int range, unsigned int *pseed)
{
  unsigned int v4; // r8d
  int v5; // edx

  if ( !range )
    return 0i64;
  v4 = *pseed ^ 0x1D872B41;
  v5 = (int)*pseed % (int)range;
  *pseed = v4 ^ v4 ^ (v4 >> 5) ^ ((v4 ^ (v4 >> 5)) << 27);
  return (v5 + range) % range;
}

// File Line: 158
// RVA: 0x189620
float __fastcall UFG::qRandom(float range, unsigned int *pseed)
{
  unsigned int v3; // r10d
  int v4; // r8d
  unsigned int v5; // edx
  float result; // xmm0_4

  v3 = *pseed;
  v4 = *pseed ^ 0x1D872B41;
  v5 = (int)((unsigned __int64)(2147483777i64 * (int)*pseed) >> 32) >> 23;
  *pseed = v4 ^ v4 ^ ((v3 ^ 0x1D872B41) >> 5) ^ ((v4 ^ ((v3 ^ 0x1D872B41) >> 5)) << 27);
  LODWORD(result) = COERCE_UNSIGNED_INT(
                      (float)((v3 - 0xFFFFFF * ((v5 >> 31) + v5) + 0xFFFFFF) % 0xFFFFFF)
                    * (float)(range * 0.000000059604652)) & _xmm;
  return result;
}

// File Line: 163
// RVA: 0x181A10
char __fastcall UFG::qApproach(float *value, float target, float rate, float delta_sec)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v7; // xmm0_4

  v4 = *value;
  if ( *value == target )
    return 1;
  if ( target <= v4 )
  {
    if ( target < v4 )
    {
      v7 = v4 - (float)(rate * delta_sec);
      *value = v7;
      if ( v7 <= target )
        goto LABEL_4;
    }
  }
  else
  {
    v5 = (float)(rate * delta_sec) + v4;
    *value = v5;
    if ( v5 >= target )
    {
LABEL_4:
      *value = target;
      return 1;
    }
  }
  return 0;
}

// File Line: 190
// RVA: 0x181A50
char __fastcall UFG::qApproachAngle(float *angle, float desired, float rate, float timeDelta)
{
  float i; // xmm4_4
  float v5; // xmm2_4
  char result; // al
  float v7; // xmm0_4

  for ( i = desired - *angle; i > 3.1415927; i = i + -6.2831855 )
    ;
  for ( ; i < -3.1415927; i = i + 6.2831855 )
    ;
  v5 = rate * timeDelta;
  if ( COERCE_FLOAT(LODWORD(i) & _xmm) > v5 )
  {
    v7 = 0.0;
    if ( i <= 0.0 )
    {
      if ( i < 0.0 )
        v7 = FLOAT_N1_0;
    }
    else
    {
      v7 = *(float *)&FLOAT_1_0;
    }
    result = 0;
    *angle = (float)(v7 * v5) + *angle;
  }
  else
  {
    *angle = desired;
    return 1;
  }
  return result;
}

// File Line: 215
// RVA: 0x181B00
char __fastcall UFG::qApproachOrientation(UFG::qQuaternion *orientation, UFG::qQuaternion *dest, float rate, float dt)
{
  float w; // xmm10_4
  int v7; // xmm4_4
  int v8; // xmm5_4
  float v9; // xmm15_4
  float v10; // xmm13_4
  float v11; // xmm14_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm0_4
  __m128 v15; // xmm1
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm7_4
  float v21; // xmm11_4
  float v22; // xmm1_4
  char result; // al
  float v24; // xmm11_4
  float v25; // xmm0_4
  float v26; // xmm8_4
  float v27; // xmm9_4
  float v28; // xmm7_4
  float v29; // xmm0_4
  float v30; // xmm13_4
  float v31; // xmm4_4
  float v32; // xmm3_4
  float v33; // xmm11_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm12_4
  float v37; // xmm12_4
  float v38; // xmm0_4
  float v39; // xmm8_4
  float v40; // xmm15_4
  __int128 y_low; // xmm5
  __m128 v42; // xmm2
  float v43; // xmm6_4
  float z; // [rsp+24h] [rbp-B4h]
  float y; // [rsp+E0h] [rbp+8h]
  float v46; // [rsp+E8h] [rbp+10h]
  float x; // [rsp+F0h] [rbp+18h]

  z = orientation->z;
  w = dest->w;
  x = dest->x;
  v46 = dest->z;
  v7 = LODWORD(orientation->y) ^ _xmm[0];
  v8 = LODWORD(orientation->x) ^ _xmm[0];
  y = dest->y;
  v9 = orientation->w;
  v10 = (float)((float)((float)(dest->x * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])) + (float)(w * *(float *)&v7))
              - (float)(v46 * *(float *)&v8))
      + (float)(y * v9);
  v11 = (float)((float)((float)(w * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])) + (float)(y * *(float *)&v8))
              - (float)(dest->x * *(float *)&v7))
      + (float)(v46 * v9);
  v12 = (float)(w * v9)
      - (float)((float)((float)(y * *(float *)&v7) + (float)(dest->x * *(float *)&v8))
              + (float)(v46 * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])));
  v13 = (float)((float)((float)(v46 * *(float *)&v7) + (float)(w * *(float *)&v8))
              - (float)(y * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])))
      + (float)(dest->x * v9);
  v14 = FLOAT_N1_0;
  if ( v12 > -1.0 )
  {
    v14 = (float)(w * v9)
        - (float)((float)((float)(y * *(float *)&v7) + (float)(dest->x * *(float *)&v8))
                + (float)(v46 * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])));
    if ( v12 >= 1.0 )
      v14 = *(float *)&FLOAT_1_0;
  }
  v15 = (__m128)(unsigned int)FLOAT_1_0;
  v16 = acosf(v14) * 2.0;
  v15.m128_f32[0] = 1.0 - (float)(v12 * v12);
  v17 = _mm_sqrt_ps(v15).m128_f32[0];
  if ( v17 >= 0.000099999997 )
  {
    v18 = (float)(1.0 / v17) * v13;
    v20 = (float)(1.0 / v17) * v11;
    v19 = (float)(1.0 / v17) * v10;
  }
  else
  {
    v18 = *(float *)&FLOAT_1_0;
    v19 = 0.0;
    v20 = 0.0;
  }
  if ( v16 > 3.1415927 )
  {
    LODWORD(v18) ^= _xmm[0];
    LODWORD(v19) ^= _xmm[0];
    LODWORD(v20) ^= _xmm[0];
    v16 = 6.2831855 - v16;
  }
  v21 = rate * dt;
  if ( v16 > v21 )
  {
    v24 = v21 * 0.5;
    v25 = sinf(v24);
    v26 = v18 * v25;
    v27 = v19 * v25;
    v28 = v20 * v25;
    v29 = cosf(v24);
    v30 = orientation->x;
    y_low = LODWORD(orientation->y);
    v31 = v29;
    v32 = orientation->z;
    v33 = (float)((float)((float)(z * v26) + (float)(orientation->y * v29)) - (float)(orientation->x * v28))
        + (float)(v9 * v27);
    v34 = orientation->y * v26;
    v35 = orientation->y;
    v36 = (float)(z * v29) + (float)(orientation->x * v27);
    orientation->y = v33;
    v37 = (float)(v36 - v34) + (float)(v9 * v28);
    orientation->z = v37;
    v38 = v30 * v26;
    v39 = v26 * orientation->w;
    v40 = (float)(v9 * v31) - (float)((float)((float)(v35 * v27) + v38) + (float)(v32 * v28));
    orientation->w = v40;
    *(float *)&y_low = (float)((float)((float)(*(float *)&y_low * v28) + (float)(v30 * v31)) - (float)(v32 * v27)) + v39;
    LODWORD(orientation->x) = y_low;
    v42 = (__m128)y_low;
    v42.m128_f32[0] = (float)((float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v33 * v33))
                            + (float)(v37 * v37))
                    + (float)(v40 * v40);
    if ( v42.m128_f32[0] == 0.0 )
      v43 = 0.0;
    else
      v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
    result = 0;
    orientation->x = *(float *)&y_low * v43;
    orientation->z = v43 * v37;
    orientation->w = v43 * v40;
    v22 = v43 * v33;
  }
  else
  {
    v22 = y;
    result = 1;
    orientation->x = x;
    orientation->z = v46;
    orientation->w = w;
  }
  orientation->y = v22;
  return result;
}

// File Line: 249
// RVA: 0x1892E0
UFG::qVector2 *__fastcall UFG::qRandom(UFG::qVector2 *result, UFG::qVector2 *range, unsigned int *pseed)
{
  float v3; // xmm3_4
  signed int v4; // r10d
  int v5; // edi
  float x; // xmm1_4
  UFG::qVector2 *v7; // rax

  v3 = range->y * 0.000000059604652;
  v4 = *pseed ^ 0x1D872B41 ^ *pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41) >> 5) ^ ((*pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41) >> 5)) << 27);
  v5 = (int)*pseed % 0xFFFFFF;
  *pseed = v4;
  x = range->x;
  *pseed = v4 ^ 0x1D872B41 ^ v4 ^ 0x1D872B41 ^ ((v4 ^ 0x1D872B41u) >> 5) ^ ((v4 ^ 0x1D872B41 ^ ((v4 ^ 0x1D872B41u) >> 5)) << 27);
  v7 = result;
  LODWORD(result->x) = COERCE_UNSIGNED_INT((float)((v4 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * (float)(x * 0.000000059604652)) & _xmm;
  LODWORD(result->y) = COERCE_UNSIGNED_INT((float)((v5 + 0xFFFFFF) % 0xFFFFFFu) * v3) & _xmm;
  return v7;
}

// File Line: 250
// RVA: 0x189420
UFG::qVector3 *__fastcall UFG::qRandom(UFG::qVector3 *result, UFG::qVector3 *range, unsigned int *pseed)
{
  float z; // xmm4_4
  unsigned int v6; // edi
  int v7; // edx
  signed int v8; // r8d
  float y; // xmm3_4
  signed int v10; // r9d
  float v11; // xmm1_4
  UFG::qVector3 *v12; // rax

  z = range->z;
  v6 = *pseed;
  v7 = (int)*pseed / 0xFFFFFF;
  v8 = *pseed ^ 0x1D872B41 ^ *pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41) >> 5) ^ ((*pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41) >> 5)) << 27);
  *pseed = v8;
  y = range->y;
  v10 = v8 ^ 0x1D872B41 ^ v8 ^ 0x1D872B41 ^ ((v8 ^ 0x1D872B41u) >> 5) ^ ((v8 ^ 0x1D872B41 ^ ((v8 ^ 0x1D872B41u) >> 5)) << 27);
  *pseed = v10;
  v11 = range->x * 0.000000059604652;
  *pseed = v10 ^ 0x1D872B41 ^ v10 ^ 0x1D872B41 ^ ((v10 ^ 0x1D872B41u) >> 5) ^ ((v10 ^ 0x1D872B41 ^ ((v10 ^ 0x1D872B41u) >> 5)) << 27);
  LODWORD(result->x) = COERCE_UNSIGNED_INT((float)((v10 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * v11) & _xmm;
  v12 = result;
  LODWORD(result->y) = COERCE_UNSIGNED_INT((float)((v8 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * (float)(y * 0.000000059604652)) & _xmm;
  LODWORD(result->z) = COERCE_UNSIGNED_INT((float)((v6 - 0xFFFFFF * v7 + 0xFFFFFF) % 0xFFFFFF) * (float)(z * 0.000000059604652)) & _xmm;
  return v12;
}

// File Line: 264
// RVA: 0x183BA0
UFG::qVector3 *__fastcall UFG::qFloor(UFG::qVector3 *result, UFG::qVector3 *a)
{
  __m128 x_low; // xmm1
  int v4; // r8d
  __m128 y_low; // xmm1
  int v6; // edx
  __m128 z_low; // xmm1
  int v8; // edx

  x_low = (__m128)LODWORD(a->x);
  v4 = (int)x_low.m128_f32[0];
  if ( (int)x_low.m128_f32[0] != 0x80000000 && (float)v4 != x_low.m128_f32[0] )
    x_low.m128_f32[0] = (float)(v4 - (_mm_movemask_ps(_mm_unpacklo_ps(x_low, x_low)) & 1));
  LODWORD(result->x) = x_low.m128_i32[0];
  y_low = (__m128)LODWORD(a->y);
  v6 = (int)y_low.m128_f32[0];
  if ( (int)y_low.m128_f32[0] != 0x80000000 && (float)v6 != y_low.m128_f32[0] )
    y_low.m128_f32[0] = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(y_low, y_low)) & 1));
  LODWORD(result->y) = y_low.m128_i32[0];
  z_low = (__m128)LODWORD(a->z);
  v8 = (int)z_low.m128_f32[0];
  if ( (int)z_low.m128_f32[0] != 0x80000000 && (float)v8 != z_low.m128_f32[0] )
    z_low.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(z_low, z_low)) & 1));
  LODWORD(result->z) = z_low.m128_i32[0];
  return result;
}

// File Line: 269
// RVA: 0x184ED0
__int64 __fastcall UFG::qIntersect(
        UFG::qVector2 *intersection,
        UFG::qVector2 *lA0,
        UFG::qVector2 *lA1,
        UFG::qVector2 *lB0,
        UFG::qVector2 *lB1,
        float *result)
{
  float y; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm8_4
  float v15; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm2_4

  y = lB0->y;
  v7 = lA1->x - lA0->x;
  v8 = lB1->x - lB0->x;
  v9 = lB0->x - lA0->x;
  v10 = lA1->y - lA0->y;
  v11 = lB1->y - y;
  v12 = y - lA0->y;
  v13 = (float)(v8 * v10) - (float)(v7 * v11);
  v14 = (float)(v12 * v7) - (float)(v9 * v10);
  v15 = (float)(v12 * v8) - (float)(v9 * v11);
  if ( v13 == 0.0 )
    return v14 != 0.0 || v15 != 0.0;
  v17 = (float)(1.0 / v13) * v15;
  v18 = (float)(1.0 / v13) * v14;
  if ( v18 < 0.0 || v18 > 1.0 || v17 < 0.0 || v17 > 1.0 )
  {
    return 2i64;
  }
  else
  {
    intersection->x = (float)(v8 * v18) + lB0->x;
    intersection->y = (float)((float)(lB1->y - lB0->y) * v18) + lB0->y;
    if ( result )
      *result = v18;
    return 3i64;
  }
}

// File Line: 302
// RVA: 0x183DA0
void __fastcall UFG::qGetClosestPointOnSegment(
        UFG::qVector2 *closest_point,
        UFG::qVector2 *lA0,
        UFG::qVector2 *lA1,
        UFG::qVector2 *P)
{
  float y; // xmm3_4
  float x; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  __m128 v8; // xmm9
  __m128 v9; // xmm1
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  y = lA1->y;
  x = lA0->x;
  v6 = lA0->y;
  v8 = (__m128)LODWORD(y);
  v7 = lA1->x - lA0->x;
  v8.m128_f32[0] = y - v6;
  v9 = v8;
  v9.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7);
  v10 = _mm_sqrt_ps(v9).m128_f32[0];
  if ( v10 <= 0.0
    || (v11 = (float)((float)((float)(P->y - v6) * v8.m128_f32[0]) + (float)((float)(P->x - x) * v7))
            / (float)(v10 * v10),
        v11 <= 0.0) )
  {
    v11 = 0.0;
  }
  else
  {
    v12 = *(float *)&FLOAT_1_0;
    if ( v11 >= 1.0 )
      goto LABEL_7;
  }
  v12 = v11;
LABEL_7:
  closest_point->x = (float)((float)(lA1->x - x) * v12) + x;
  closest_point->y = (float)((float)(y - v6) * v12) + v6;
}

// File Line: 330
// RVA: 0x183E80
void __fastcall UFG::qGetClosestPointOnSegment(
        UFG::qVector3 *closest_point,
        UFG::qVector3 *lA0,
        UFG::qVector3 *lA1,
        UFG::qVector3 *P)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm10_4
  __m128 v9; // xmm12
  float v10; // xmm11_4
  __m128 v11; // xmm2
  float v12; // xmm13_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm0_4

  y = lA1->y;
  z = lA1->z;
  x = lA0->x;
  v7 = lA0->y;
  v8 = lA0->z;
  v9 = (__m128)LODWORD(y);
  v9.m128_f32[0] = y - v7;
  v10 = lA1->x - lA0->x;
  v11 = v9;
  v12 = z - v8;
  v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
  v13 = _mm_sqrt_ps(v11).m128_f32[0];
  if ( v13 <= 0.0
    || (v14 = (float)((float)((float)((float)(P->y - v7) * v9.m128_f32[0]) + (float)((float)(P->x - x) * v10))
                    + (float)((float)(P->z - v8) * v12))
            / (float)(v13 * v13),
        v14 <= 0.0) )
  {
    v14 = 0.0;
  }
  else
  {
    v15 = *(float *)&FLOAT_1_0;
    if ( v14 >= 1.0 )
      goto LABEL_7;
  }
  v15 = v14;
LABEL_7:
  closest_point->x = (float)((float)(lA1->x - x) * v15) + x;
  closest_point->y = (float)((float)(y - v7) * v15) + v7;
  closest_point->z = (float)((float)(z - v8) * v15) + v8;
}

// File Line: 497
// RVA: 0x1817D0
float __fastcall UFG::qAngleBetween(UFG::qVector2 *v1, UFG::qVector2 *v2)
{
  float v3; // xmm0_4

  v3 = atan2f(v2->y, v2->x);
  return v3 - atan2f(v1->y, v1->x);
}

// File Line: 503
// RVA: 0x181810
float __fastcall UFG::qAngleBetween(UFG::qVector3 *v1, UFG::qVector3 *v2)
{
  float xmm3_4_1; // xmm3_4
  __m128 x_low; // xmm6
  float y; // xmm7_4
  float z; // xmm8_4
  __m128 v6; // xmm2
  float v7; // xmm1_4
  float v8; // xmm2_4
  __m128 v9; // xmm9
  float v10; // xmm10_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  __m128 v14; // xmm5
  float v15; // xmm1_4
  float v16; // xmm2_4

  xmm3_4_1 = *(float *)&FLOAT_1_0;
  x_low = (__m128)LODWORD(v1->x);
  v6 = x_low;
  y = v1->y;
  z = v1->z;
  v6.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v6.m128_f32[0] == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
  v8 = v2->y;
  v9 = (__m128)LODWORD(v2->x);
  v10 = v2->z;
  v11 = x_low.m128_f32[0] * v7;
  v12 = y * v7;
  v13 = z * v7;
  v14 = v9;
  v14.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v14.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
  v16 = (float)((float)((float)(v8 * v15) * v12) + (float)((float)(v9.m128_f32[0] * v15) * v11))
      + (float)((float)(v10 * v15) * v13);
  if ( v16 < -0.99989998 )
    return FLOAT_3_1415927;
  if ( v16 > 0.99989998 )
    return 0.0;
  if ( v16 <= -1.0 )
  {
    v16 = FLOAT_N1_0;
  }
  else if ( v16 >= 1.0 )
  {
    return acosf(xmm3_4_1);
  }
  xmm3_4_1 = v16;
  return acosf(xmm3_4_1);
}

// File Line: 518
// RVA: 0x181960
double __fastcall UFG::qAngleBetweenNormals(UFG::qVector3 *n1, UFG::qVector3 *n2)
{
  __int64 y_low; // xmm2_8
  double result; // xmm0_8

  y_low = LODWORD(n1->y);
  *(float *)&y_low = (float)((float)(*(float *)&y_low * n2->y) + (float)(n1->x * n2->x)) + (float)(n1->z * n2->z);
  if ( *(float *)&y_low < -0.99989998 )
  {
    *(_QWORD *)&result = LODWORD(FLOAT_3_1415927);
    return result;
  }
  if ( *(float *)&y_low > 0.99989998 )
    return 0.0;
  if ( *(float *)&y_low <= -1.0 )
  {
    y_low = LODWORD(FLOAT_N1_0);
    goto LABEL_10;
  }
  *(_QWORD *)&result = (unsigned int)FLOAT_1_0;
  if ( *(float *)&y_low < 1.0 )
  {
LABEL_10:
    HIDWORD(result) = HIDWORD(y_low);
    *(float *)&result = acosf(*(float *)&y_low);
    return result;
  }
  *(float *)&result = acosf(1.0);
  return result;
}

// File Line: 547
// RVA: 0x184CF0
float __fastcall UFG::qHeading2D(UFG::qVector3 *v1)
{
  float x; // xmm2_4
  __m128 y_low; // xmm3
  __m128 v3; // xmm1
  float v4; // xmm4_4
  float result; // xmm0_4

  x = v1->x;
  y_low = (__m128)LODWORD(v1->y);
  v3 = y_low;
  v3.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
  v4 = _mm_sqrt_ps(v3).m128_f32[0];
  if ( v4 <= 0.0 )
    return 0.0;
  result = atan2f((float)(1.0 / v4) * y_low.m128_f32[0], (float)(1.0 / v4) * x);
  if ( result < 0.0 )
    return result + 6.2831855;
  return result;
}

// File Line: 578
// RVA: 0x184D60
float __fastcall UFG::qHeadingDifference2D(UFG::qVector3 *v1, UFG::qVector3 *v2)
{
  float v3; // xmm0_4
  float v4; // xmm6_4

  v3 = UFG::qHeading2D(v2);
  v4 = v3 - UFG::qHeading2D(v1);
  if ( v4 > 3.1415927 )
    return v4 - 6.2831855;
  if ( v4 < -3.1415927 )
    return v4 + 6.2831855;
  return v4;
}

// File Line: 586
// RVA: 0x18A4B0
void __fastcall UFG::qRotateVectorZ(UFG::qVector3 *dest, UFG::qVector3 *source, float radians)
{
  float v5; // xmm7_4
  float v6; // xmm0_4

  v5 = cosf(radians);
  v6 = sinf(radians);
  dest->x = (float)(v6 * source->y) + (float)(v5 * source->x);
  dest->y = (float)(v5 * source->y) - (float)(v6 * source->x);
  dest->z = source->z;
}

// File Line: 597
// RVA: 0x18A440
void __fastcall UFG::qRotateVectorZ(UFG::qVector2 *dest, UFG::qVector2 *source, float radians)
{
  float v5; // xmm7_4
  float v6; // xmm0_4

  v5 = cosf(radians);
  v6 = sinf(radians);
  dest->x = (float)(v6 * source->y) + (float)(v5 * source->x);
  dest->y = (float)(v5 * source->y) - (float)(v6 * source->x);
}

// File Line: 607
// RVA: 0x18AFE0
void __fastcall UFG::qSphericalToCartesian(UFG::qVector3 *position, float theta, float phi)
{
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4

  v4 = (float)(phi * 3.1415927) * 0.0055555557;
  v5 = (float)(theta * 3.1415927) * 0.0055555557;
  v6 = sinf(v4);
  position->x = cosf(v5) * v6;
  position->y = sinf(v5) * v6;
  position->z = cosf(v4);
}

// File Line: 667
// RVA: 0x17C660
void __fastcall UFG::qQuaternion::Set(UFG::qQuaternion *this, float angle, UFG::qVector3 *axis)
{
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4

  v5 = sinf(angle * 0.5);
  v6 = v5 * axis->z;
  v7 = v5 * axis->y;
  this->x = v5 * axis->x;
  this->y = v7;
  this->z = v6;
  this->w = cosf(angle * 0.5);
}

// File Line: 674
// RVA: 0x17C460
void __fastcall UFG::qQuaternion::Set(UFG::qQuaternion *this, UFG::qMatrix44 *mat)
{
  __m128 x_low; // xmm4
  __m128 y_low; // xmm2
  __m128 z_low; // xmm1
  float v6; // xmm5_4
  __m128 v7; // xmm3
  float v8; // xmm1_4
  float v9; // xmm2_4
  float x; // xmm0_4
  int v11; // ecx
  int v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4

  x_low = (__m128)LODWORD(mat->v0.x);
  y_low = (__m128)LODWORD(mat->v1.y);
  z_low = (__m128)LODWORD(mat->v2.z);
  v7 = z_low;
  v6 = mat->v0.x + y_low.m128_f32[0];
  v7.m128_f32[0] = z_low.m128_f32[0] + v6;
  if ( (float)(z_low.m128_f32[0] + v6) <= 0.0 )
  {
    x = mat->v0.x;
    v11 = 0;
    if ( y_low.m128_f32[0] > x_low.m128_f32[0] )
    {
      x = mat->v1.y;
      v11 = 1;
    }
    if ( z_low.m128_f32[0] > x )
      v11 = 2;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          z_low.m128_f32[0] = (float)(z_low.m128_f32[0] - v6) + 1.0;
          v13 = _mm_sqrt_ps(z_low).m128_f32[0];
          this->z = v13 * 0.5;
          this->x = (float)(mat->v2.x + mat->v0.z) * (float)(0.5 / v13);
          this->y = (float)(mat->v2.y + mat->v1.z) * (float)(0.5 / v13);
          this->w = (float)(mat->v0.y - mat->v1.x) * (float)(0.5 / v13);
        }
      }
      else
      {
        y_low.m128_f32[0] = (float)(y_low.m128_f32[0] - (float)(z_low.m128_f32[0] + x_low.m128_f32[0])) + 1.0;
        v14 = _mm_sqrt_ps(y_low).m128_f32[0];
        this->y = v14 * 0.5;
        this->z = (float)(mat->v2.y + mat->v1.z) * (float)(0.5 / v14);
        this->x = (float)(mat->v1.x + mat->v0.y) * (float)(0.5 / v14);
        this->w = (float)(mat->v2.x - mat->v0.z) * (float)(0.5 / v14);
      }
    }
    else
    {
      x_low.m128_f32[0] = (float)(x_low.m128_f32[0] - (float)(z_low.m128_f32[0] + y_low.m128_f32[0])) + 1.0;
      v15 = _mm_sqrt_ps(x_low).m128_f32[0];
      this->x = v15 * 0.5;
      this->y = (float)(mat->v1.x + mat->v0.y) * (float)(0.5 / v15);
      this->z = (float)(mat->v2.x + mat->v0.z) * (float)(0.5 / v15);
      this->w = (float)(mat->v1.z - mat->v2.y) * (float)(0.5 / v15);
    }
  }
  else
  {
    v7.m128_f32[0] = v7.m128_f32[0] + 1.0;
    v8 = _mm_sqrt_ps(v7).m128_f32[0];
    v9 = 1.0 / (float)(v8 * 2.0);
    this->w = v8 * 0.5;
    this->x = (float)(mat->v1.z - mat->v2.y) * v9;
    this->y = (float)(mat->v2.x - mat->v0.z) * v9;
    this->z = (float)(mat->v0.y - mat->v1.x) * v9;
  }
}

// File Line: 759
// RVA: 0x17BD90
void __fastcall UFG::qQuaternion::Rotate(UFG::qQuaternion *this, UFG::qVector3 *v)
{
  float y; // xmm4_4
  float v3; // xmm11_4
  float w; // xmm9_4
  float z; // xmm10_4
  float v6; // xmm12_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm10_4
  int v11; // xmm13_4
  int v12; // xmm12_4
  int v13; // xmm11_4

  y = v->y;
  v3 = this->y;
  w = this->w;
  z = v->z;
  v6 = this->z;
  v7 = (float)((float)((float)(v->x * v6) + (float)(v3 * 0.0)) - (float)(z * this->x)) + (float)(w * y);
  v8 = (float)((float)((float)(y * this->x) + (float)(v6 * 0.0)) - (float)(v->x * v3)) + (float)(w * z);
  v9 = (float)(w * 0.0) - (float)((float)((float)(y * v3) + (float)(v->x * this->x)) + (float)(z * v6));
  v10 = (float)((float)((float)(z * v3) + (float)(this->x * 0.0)) - (float)(y * v6)) + (float)(w * v->x);
  v11 = LODWORD(this->x) ^ _xmm[0];
  v12 = LODWORD(v6) ^ _xmm[0];
  v13 = LODWORD(v3) ^ _xmm[0];
  v->y = (float)((float)((float)(*(float *)&v11 * v8) + (float)(w * v7)) - (float)(*(float *)&v12 * v10))
       + (float)(*(float *)&v13 * v9);
  v->x = (float)((float)((float)(*(float *)&v12 * v7) + (float)(w * v10)) - (float)(*(float *)&v13 * v8))
       + (float)(*(float *)&v11 * v9);
  v->z = (float)((float)((float)(w * v8) + (float)(*(float *)&v13 * v10)) - (float)(*(float *)&v11 * v7))
       + (float)(*(float *)&v12 * v9);
}

// File Line: 768
// RVA: 0x171170
UFG::qMatrix44 *__fastcall UFG::qQuaternion::GetMatrix(
        UFG::qQuaternion *this,
        UFG::qMatrix44 *result,
        UFG::qVector3 *t)
{
  float y; // xmm2_4
  float w; // xmm3_4
  float z; // xmm10_4
  float v6; // xmm7_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm15_4
  float v10; // xmm13_4
  float v11; // xmm12_4
  float v12; // xmm2_4
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm9_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float x; // xmm0_4
  float v21; // [rsp+B0h] [rbp+8h]

  y = this->y;
  w = this->w;
  z = this->z;
  v6 = z * y;
  v7 = this->x * this->x;
  v21 = this->x * z;
  v8 = y * y;
  v9 = y * w;
  v10 = this->x * w;
  v11 = this->x * y;
  v12 = t->z;
  v13 = v11 - (float)(z * w);
  v14 = (float)((float)(z * w) + v11) * 2.0;
  v15 = 1.0 - (float)((float)(v7 + v8) * 2.0);
  v16 = (float)((float)(z * z) + v7) * 2.0;
  v17 = t->y;
  v18 = 1.0 - v16;
  x = t->x;
  result->v0.w = 0.0;
  result->v0.y = v14;
  result->v0.x = 1.0 - (float)((float)((float)(z * z) + v8) * 2.0);
  result->v0.z = (float)(v21 - v9) * 2.0;
  result->v1.y = v18;
  result->v1.w = 0.0;
  result->v1.x = v13 * 2.0;
  result->v1.z = (float)(v10 + v6) * 2.0;
  result->v2.w = 0.0;
  result->v2.x = (float)(v21 + v9) * 2.0;
  result->v2.y = (float)(v6 - v10) * 2.0;
  result->v2.z = v15;
  result->v3.x = x;
  result->v3.y = v17;
  result->v3.z = v12;
  result->v3.w = 1.0;
  return result;
}

// File Line: 788
// RVA: 0x18AD40
UFG::qQuaternion *__fastcall UFG::qSlerp(
        UFG::qQuaternion *result,
        UFG::qQuaternion *a,
        UFG::qQuaternion *b,
        float t,
        UFG::qAngularPath path)
{
  float v6; // xmm7_4
  UFG::qQuaternion *v7; // rax
  float y; // xmm4_4
  float z; // xmm5_4
  float w; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm13_4
  float x; // xmm12_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  float v16; // xmm2_4
  bool v17; // al
  float v18; // xmm8_4
  float v19; // xmm6_4
  float v20; // xmm9_4
  float v21; // xmm0_4
  float v22; // [rsp+20h] [rbp-B8h]
  float v23; // [rsp+F8h] [rbp+20h]

  v6 = t;
  if ( t >= 1.0 )
  {
    *result = *b;
    return result;
  }
  if ( t <= 0.0 )
  {
    *result = *a;
    return result;
  }
  y = a->y;
  z = a->z;
  w = b->w;
  v11 = a->w;
  v23 = y;
  v12 = b->y;
  x = b->x;
  v14 = b->z;
  v15 = a->x;
  v22 = z;
  v16 = (float)((float)((float)(v12 * y) + (float)(b->x * a->x)) + (float)(v14 * z)) + (float)(w * v11);
  switch ( path )
  {
    case qAngularPath_Shortest:
      v17 = v16 < 0.0;
LABEL_13:
      if ( v17 )
      {
        LODWORD(v16) ^= _xmm[0];
        LODWORD(x) ^= _xmm[0];
        LODWORD(v12) ^= _xmm[0];
        LODWORD(v14) ^= _xmm[0];
        LODWORD(w) ^= _xmm[0];
      }
      break;
    case qAngularPath_Longest:
      v17 = v16 > 0.0;
      goto LABEL_13;
    case qAngularPath_CW:
      v17 = v11 > w;
      goto LABEL_13;
    case qAngularPath_CCW:
      v17 = w > v11;
      goto LABEL_13;
  }
  v18 = 1.0 - t;
  if ( v16 < 0.98000002 )
  {
    if ( v16 <= -1.0 )
    {
      v16 = FLOAT_N1_0;
    }
    else if ( v16 >= 1.0 )
    {
      v16 = *(float *)&FLOAT_1_0;
    }
    v19 = acosf(v16);
    v20 = 1.0 / sinf(v19);
    v18 = sinf(v18 * v19) * v20;
    v21 = sinf(v19 * t);
    y = v23;
    z = v22;
    v6 = v21 * v20;
  }
  v7 = result;
  result->x = (float)(v15 * v18) + (float)(v6 * x);
  result->y = (float)(y * v18) + (float)(v6 * v12);
  result->w = (float)(v11 * v18) + (float)(v6 * w);
  result->z = (float)(z * v18) + (float)(v6 * v14);
  return v7;
}

// File Line: 829
// RVA: 0x1881A0
UFG::qQuaternion *__fastcall UFG::qNlerp(
        UFG::qQuaternion *result,
        UFG::qQuaternion *a,
        UFG::qQuaternion *b,
        float t,
        UFG::qAngularPath path)
{
  float w; // xmm3_4
  float v8; // xmm5_4
  float z; // xmm7_4
  float y; // xmm9_4
  float x; // xmm8_4
  __m128 y_low; // xmm13
  float v13; // xmm10_4
  float v14; // xmm4_4
  bool v15; // al
  float v16; // xmm12_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  __m128 v19; // xmm4
  float v20; // xmm2_4

  if ( t >= 1.0 )
  {
    *result = *b;
    return result;
  }
  if ( t > 0.0 )
  {
    w = a->w;
    v8 = b->w;
    z = a->z;
    y = b->y;
    x = b->x;
    y_low = (__m128)LODWORD(a->y);
    v13 = b->z;
    v14 = (float)((float)((float)(y * y_low.m128_f32[0]) + (float)(b->x * a->x)) + (float)(v13 * z)) + (float)(v8 * w);
    if ( path )
    {
      switch ( path )
      {
        case qAngularPath_Longest:
          v15 = v14 > 0.0;
          break;
        case qAngularPath_CW:
          v15 = w > v8;
          break;
        case qAngularPath_CCW:
          v15 = v8 > w;
          break;
        default:
LABEL_15:
          v16 = (float)(a->x * (float)(1.0 - t)) + (float)(x * t);
          y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * (float)(1.0 - t)) + (float)(y * t);
          v19 = y_low;
          v17 = (float)(z * (float)(1.0 - t)) + (float)(v13 * t);
          v18 = (float)(w * (float)(1.0 - t)) + (float)(v8 * t);
          v19.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v16 * v16))
                                  + (float)(v17 * v17))
                          + (float)(v18 * v18);
          if ( v19.m128_f32[0] == 0.0 )
            v20 = 0.0;
          else
            v20 = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
          result->z = v17 * v20;
          result->x = v20 * v16;
          result->y = v20 * y_low.m128_f32[0];
          result->w = v18 * v20;
          return result;
      }
    }
    else
    {
      v15 = v14 < 0.0;
    }
    if ( v15 )
    {
      LODWORD(x) ^= _xmm[0];
      LODWORD(y) ^= _xmm[0];
      LODWORD(v13) ^= _xmm[0];
      LODWORD(v8) ^= _xmm[0];
    }
    goto LABEL_15;
  }
  *result = *a;
  return result;
}

// File Line: 867
// RVA: 0x188B20
void __fastcall UFG::qPerspectiveMatrix(
        UFG::qMatrix44 *dest,
        float fov_x,
        float aspect_ratio,
        float near_plane,
        float far_plane)
{
  UFG::qVector4 v7; // xmm2
  float v8; // xmm4_4
  float v9; // xmm5_4

  v7 = 0i64;
  v7.x = (float)1;
  v8 = 1.0 / tanf(fov_x * 0.5);
  dest->v0 = v7;
  v9 = 1.0 / (float)(near_plane - far_plane);
  dest->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 81);
  dest->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 69);
  dest->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 21);
  dest->v0.x = v8;
  dest->v2.w = -1.0;
  dest->v3.w = 0.0;
  dest->v3.z = (float)(near_plane * far_plane) * v9;
  dest->v2.z = v9 * far_plane;
  dest->v1.y = v8 * aspect_ratio;
}

// File Line: 902
// RVA: 0x188BE0
void __fastcall UFG::qPerspectiveObliqueMatrix(
        UFG::qMatrix44 *dest,
        float fov_x,
        float aspect,
        float near_plane,
        float far_plane,
        float pan_x,
        float pan_y)
{
  float v8; // xmm0_4

  v8 = tanf(fov_x * 0.5) * near_plane;
  UFG::qFrustumMatrix(
    dest,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * pan_x) ^ _xmm[0]) - v8,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * pan_x) ^ _xmm[0]) + v8,
    COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v8 / aspect) * pan_y) ^ _xmm[0]) - (float)(v8 / aspect),
    COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v8 / aspect) * pan_y) ^ _xmm[0]) + (float)(v8 / aspect),
    near_plane,
    far_plane);
}

// File Line: 924
// RVA: 0x183C70
void __fastcall UFG::qFrustumMatrix(UFG::qMatrix44 *dest, float l, float r, float b, float t, float n, float f)
{
  UFG::qVector4 v7; // xmm4
  float v9; // xmm3_4
  float v10; // xmm9_4
  float v11; // xmm2_4

  v7 = 0i64;
  v7.x = (float)1;
  dest->v0 = v7;
  dest->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 81);
  dest->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 69);
  dest->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 21);
  dest->v2.w = -1.0;
  dest->v3.w = 0.0;
  v9 = 1.0 / (float)(t - b);
  v10 = l + r;
  dest->v2.y = (float)(b + t) * v9;
  v11 = 1.0 / (float)(r - l);
  dest->v3.z = (float)(n * f) * (float)(1.0 / (float)(n - f));
  dest->v0.x = (float)(n * 2.0) * v11;
  dest->v2.x = v10 * v11;
  dest->v1.y = (float)(n * 2.0) * v9;
  dest->v2.z = (float)(1.0 / (float)(n - f)) * f;
}

// File Line: 960
// RVA: 0x182F80
void __fastcall UFG::qDecomposePerspective(
        float *fov_h,
        float *aspect,
        float *near_plane,
        float *far_plane,
        float *pan_x,
        float *pan_y,
        UFG::qMatrix44 *proj)
{
  float v11; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm1_4
  float v14; // xmm2_4
  float w; // xmm3_4
  float v16; // xmm4_4

  if ( proj->v0.x == 0.0 )
    v11 = 0.0;
  else
    v11 = atan2f(1.0, proj->v0.x) * 2.0;
  *fov_h = v11;
  if ( proj->v0.x == 0.0 )
    v12 = 0.0;
  else
    v12 = proj->v1.y / proj->v0.x;
  *aspect = v12;
  z = proj->v2.z;
  v14 = proj->v3.z;
  w = proj->v2.w;
  v16 = proj->v3.w;
  if ( z != 0.0 && z != w )
  {
    *near_plane = v14 / z;
    *far_plane = (float)(v14 - v16) / (float)(z - w);
  }
  *(_DWORD *)pan_x = LODWORD(proj->v2.x) ^ _xmm[0];
  *(_DWORD *)pan_y = LODWORD(proj->v2.y) ^ _xmm[0];
}

// File Line: 969
// RVA: 0x188AA0
void __fastcall UFG::qOrthographicMatrix(
        UFG::qMatrix44 *dest,
        float width,
        float height,
        float near_plane,
        float far_plane)
{
  UFG::qVector4 v5; // xmm4
  float v6; // xmm6_4

  v5 = 0i64;
  v5.x = (float)1;
  dest->v0 = v5;
  v6 = 1.0 / (float)(near_plane - far_plane);
  dest->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 81);
  dest->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 69);
  dest->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 21);
  dest->v2.z = v6;
  dest->v1.y = 2.0 / height;
  dest->v3.z = v6 * near_plane;
  dest->v0.x = 2.0 / width;
}

// File Line: 1099
// RVA: 0x183310
float __fastcall UFG::qDeterminant(UFG::qMatrix44 *m)
{
  float x; // xmm4_4
  float w; // xmm0_4
  float z; // xmm1_4
  float y; // xmm2_4
  float v5; // xmm9_4
  float v6; // xmm13_4
  float v7; // xmm5_4
  float v8; // xmm7_4
  float v9; // xmm11_4
  float v10; // xmm7_4
  float v11; // xmm14_4
  float v12; // xmm8_4
  float v13; // xmm6_4
  float v14; // xmm15_4
  float v15; // xmm12_4
  float v16; // xmm10_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v26; // [rsp+B0h] [rbp+8h]

  x = m->v3.x;
  w = m->v0.w;
  z = m->v0.z;
  y = m->v0.y;
  v5 = m->v3.y;
  v6 = m->v1.w;
  v7 = m->v1.z * w;
  v8 = m->v1.y;
  v9 = v8 * z;
  v10 = v8 * w;
  v11 = m->v1.z * y;
  v12 = m->v1.x * w;
  v13 = v6 * z;
  v14 = m->v3.z;
  v15 = m->v1.x * z;
  v16 = v6 * y;
  v26 = m->v1.z * m->v0.x;
  v17 = m->v1.x * y;
  v18 = m->v2.w;
  v19 = (float)((float)((float)((float)((float)(v7 * m->v2.y) * x) - (float)((float)(v13 * m->v2.y) * x))
                      - (float)((float)(v10 * m->v2.z) * x))
              + (float)((float)(v16 * m->v2.z) * x))
      + (float)((float)(v9 * v18) * x);
  v20 = (float)(v11 * v18) * x;
  v21 = m->v2.x;
  v22 = (float)((float)((float)(v19 - v20) - (float)((float)(v7 * v21) * v5)) + (float)((float)(v13 * v21) * v5))
      + (float)((float)(v12 * m->v2.z) * v5);
  v23 = m->v2.y;
  v24 = m->v3.w;
  return (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)(v22 - (float)((float)((float)(v6 * m->v0.x) * m->v2.z) * v5)) - (float)((float)(v15 * v18) * v5)) + (float)((float)(v26 * v18) * v5))
                                                                                               + (float)((float)(v10 * v21) * v14))
                                                                                       - (float)((float)(v16 * v21) * v14))
                                                                               - (float)((float)(v12 * v23) * v14))
                                                                       + (float)((float)((float)(v6 * m->v0.x) * v23)
                                                                               * v14))
                                                               + (float)((float)(v17 * v18) * v14))
                                                       - (float)((float)((float)(m->v1.y * m->v0.x) * v18) * v14))
                                               - (float)((float)(v9 * v21) * v24))
                                       + (float)((float)(v11 * v21) * v24))
                               + (float)((float)(v15 * v23) * v24))
                       - (float)((float)(v26 * v23) * v24))
               - (float)((float)(v17 * m->v2.z) * v24))
       + (float)((float)((float)(m->v1.y * m->v0.x) * m->v2.z) * v24);
}

// File Line: 1118
// RVA: 0x186740
void __fastcall UFG::qInverse(UFG::qMatrix44 *d, UFG::qMatrix44 *m)
{
  float v4; // xmm0_4
  float z; // xmm4_4
  float w; // xmm10_4
  float v7; // xmm6_4
  float v8; // xmm15_4
  float v9; // xmm12_4
  float v10; // xmm7_4
  float v11; // xmm11_4
  float v12; // xmm10_4
  float v13; // xmm4_4
  float v14; // xmm7_4
  float v15; // xmm7_4
  float v16; // xmm9_4
  float v17; // xmm12_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // [rsp+20h] [rbp-128h]
  float v21; // [rsp+24h] [rbp-124h]
  float v22; // [rsp+28h] [rbp-120h]
  float v23; // [rsp+2Ch] [rbp-11Ch]
  float y; // [rsp+30h] [rbp-118h]
  float v25; // [rsp+34h] [rbp-114h]
  float v26; // [rsp+34h] [rbp-114h]
  float v27; // [rsp+38h] [rbp-110h]
  float v28; // [rsp+3Ch] [rbp-10Ch]
  float v29; // [rsp+40h] [rbp-108h]
  float v30; // [rsp+44h] [rbp-104h]
  float v31; // [rsp+48h] [rbp-100h]
  float v32; // [rsp+4Ch] [rbp-FCh]
  float v33; // [rsp+54h] [rbp-F4h]
  float v34; // [rsp+58h] [rbp-F0h]
  float v35; // [rsp+5Ch] [rbp-ECh]
  float v36; // [rsp+60h] [rbp-E8h]
  float v37; // [rsp+68h] [rbp-E0h]
  float v38; // [rsp+6Ch] [rbp-DCh]
  float v39; // [rsp+70h] [rbp-D8h]
  float v40; // [rsp+74h] [rbp-D4h]
  float v41; // [rsp+7Ch] [rbp-CCh]
  float x; // [rsp+158h] [rbp+10h]
  float v43; // [rsp+158h] [rbp+10h]
  float v44; // [rsp+160h] [rbp+18h]
  float v45; // [rsp+160h] [rbp+18h]
  float v46; // [rsp+168h] [rbp+20h]
  float v47; // [rsp+168h] [rbp+20h]

  v4 = UFG::qDeterminant(m);
  z = m->v1.z;
  w = m->v1.w;
  v7 = m->v2.w * z;
  v8 = m->v0.z;
  v9 = m->v0.w;
  y = m->v2.y;
  x = m->v1.x;
  v22 = m->v3.x;
  v23 = m->v2.z;
  v46 = m->v1.y;
  v27 = m->v2.x;
  v10 = v23 * w;
  v38 = y * w;
  v44 = z;
  v31 = m->v0.x;
  v35 = m->v0.y;
  v25 = w;
  v28 = m->v2.w;
  v20 = m->v3.y;
  v21 = m->v3.z;
  v29 = m->v3.w;
  v34 = y * z;
  v36 = v23 * v46;
  d->v0.x = (float)((float)((float)((float)((float)((float)(v7 * v20) - (float)((float)(v23 * w) * v20))
                                          + (float)((float)(y * w) * v21))
                                  - (float)((float)(v28 * v46) * v21))
                          - (float)((float)(y * z) * v29))
                  + (float)((float)(v23 * v46) * v29))
          * (float)(1.0 / v4);
  v41 = y * v9;
  v11 = w * v8;
  v40 = w * v35;
  v12 = z * v9;
  v30 = v46 * v8;
  v33 = v46 * v9;
  v32 = z * v35;
  d->v0.y = (float)((float)((float)((float)((float)((float)((float)(v23 * v9) * v20) - (float)((float)(v28 * v8) * v20))
                                          - (float)((float)(y * v9) * v21))
                                  + (float)((float)(v28 * v35) * v21))
                          + (float)((float)(y * v8) * v29))
                  - (float)((float)(v23 * v35) * v29))
          * (float)(1.0 / v4);
  d->v0.z = (float)((float)((float)((float)((float)((float)(v11 * v20) - (float)((float)(z * v9) * v20))
                                          + (float)((float)(v46 * v9) * v21))
                                  - (float)((float)(v25 * v35) * v21))
                          - (float)((float)(v46 * v8) * v29))
                  + (float)((float)(z * v35) * v29))
          * (float)(1.0 / v4);
  v13 = v27 * v25;
  v39 = v23 * x;
  v14 = (float)((float)(v10 * v22) - (float)(v7 * v22)) - (float)((float)(v27 * v25) * v21);
  d->v0.w = (float)((float)((float)((float)((float)((float)((float)(v44 * v9) * y) - (float)(v11 * y))
                                          - (float)((float)(v46 * v9) * v23))
                                  + (float)((float)(v25 * v35) * v23))
                          + (float)((float)(v46 * v8) * v28))
                  - (float)((float)(v44 * v35) * v28))
          * (float)(1.0 / v4);
  v37 = v27 * v44;
  v26 = v25 * v31;
  d->v1.x = (float)((float)((float)(v14 + (float)((float)(v28 * x) * v21)) + (float)((float)(v27 * v44) * v29))
                  - (float)((float)(v23 * x) * v29))
          * (float)(1.0 / v4);
  v15 = v27 * v9;
  d->v1.y = (float)((float)((float)((float)((float)((float)((float)(v28 * v8) * v22) - (float)((float)(v23 * v9) * v22))
                                          + (float)((float)(v27 * v9) * v21))
                                  - (float)((float)(v28 * v31) * v21))
                          - (float)((float)(v27 * v8) * v29))
                  + (float)((float)(v23 * v31) * v29))
          * (float)(1.0 / v4);
  v16 = x * v9;
  v17 = x * v8;
  v45 = v44 * v31;
  d->v1.z = (float)((float)((float)((float)((float)((float)(v12 * v22) - (float)(v11 * v22)) - (float)(v16 * v21))
                                  + (float)(v26 * v21))
                          + (float)((float)(x * v8) * v29))
                  - (float)(v45 * v29))
          * (float)(1.0 / v4);
  v18 = v27 * v46;
  d->v1.w = (float)((float)((float)((float)((float)((float)(v11 * v27) - (float)(v12 * v27)) + (float)(v16 * v23))
                                  - (float)(v26 * v23))
                          - (float)((float)(x * v8) * v28))
                  + (float)(v45 * v28))
          * (float)(1.0 / v4);
  v19 = y * x;
  d->v2.x = (float)((float)((float)((float)((float)((float)((float)(v28 * v46) * v22) - (float)(v38 * v22))
                                          + (float)(v13 * v20))
                                  - (float)((float)(v28 * x) * v20))
                          - (float)((float)(v27 * v46) * v29))
                  + (float)((float)(y * x) * v29))
          * (float)(1.0 / v4);
  v43 = x * v35;
  d->v2.y = (float)((float)((float)((float)((float)((float)(v41 * v22) - (float)((float)(v28 * v35) * v22))
                                          - (float)(v15 * v20))
                                  + (float)((float)(v28 * v31) * v20))
                          + (float)((float)(v27 * v35) * v29))
                  - (float)((float)(y * v31) * v29))
          * (float)(1.0 / v4);
  v47 = v46 * v31;
  d->v2.z = (float)((float)((float)((float)((float)((float)(v40 * v22) - (float)(v33 * v22)) + (float)(v16 * v20))
                                  - (float)(v26 * v20))
                          - (float)(v43 * v29))
                  + (float)(v47 * v29))
          * (float)(1.0 / v4);
  d->v2.w = (float)((float)((float)((float)((float)((float)(v33 * v27) - (float)(v40 * v27)) - (float)(v16 * y))
                                  + (float)(v26 * y))
                          + (float)(v43 * v28))
                  - (float)(v47 * v28))
          * (float)(1.0 / v4);
  d->v3.x = (float)((float)((float)((float)((float)((float)(v34 * v22) - (float)(v36 * v22)) - (float)(v37 * v20))
                                  + (float)(v39 * v20))
                          + (float)(v18 * v21))
                  - (float)(v19 * v21))
          * (float)(1.0 / v4);
  d->v3.y = (float)((float)((float)((float)((float)((float)((float)(v23 * v35) * v22) - (float)((float)(y * v8) * v22))
                                          + (float)((float)(v27 * v8) * v20))
                                  - (float)((float)(v23 * v31) * v20))
                          - (float)((float)(v27 * v35) * v21))
                  + (float)((float)(y * v31) * v21))
          * (float)(1.0 / v4);
  d->v3.w = (float)((float)((float)((float)((float)((float)(v32 * v27) - (float)(v30 * v27)) + (float)(v17 * y))
                                  - (float)(v45 * y))
                          - (float)(v43 * v23))
                  + (float)(v47 * v23))
          * (float)(1.0 / v4);
  d->v3.z = (float)((float)((float)((float)((float)((float)(v30 * v22) - (float)(v32 * v22)) - (float)(v17 * v20))
                                  + (float)(v45 * v20))
                          + (float)(v43 * v21))
                  - (float)(v47 * v21))
          * (float)(1.0 / v4);
}

// File Line: 1145
// RVA: 0x18C620
void __fastcall UFG::qTranspose(UFG::qMatrix44 *dest, UFG::qMatrix44 *m)
{
  float x; // eax
  float v3; // xmm3_4
  float v4; // xmm1_4
  float y; // xmm6_4
  float z; // xmm7_4
  float w; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm5_4

  x = m->v0.x;
  v3 = m->v1.x;
  v4 = m->v2.x;
  y = m->v1.y;
  z = m->v2.z;
  w = m->v3.w;
  v8 = m->v0.y;
  v9 = m->v1.z;
  v10 = m->v2.w;
  v11 = m->v0.z;
  v12 = m->v1.w;
  v13 = m->v2.y;
  v14 = m->v3.x;
  v15 = m->v3.y;
  v16 = m->v3.z;
  dest->v3.x = m->v0.w;
  dest->v1.x = v8;
  dest->v0.x = x;
  dest->v1.y = y;
  dest->v2.x = v11;
  dest->v2.y = v9;
  dest->v2.z = z;
  dest->v3.y = v12;
  dest->v3.z = v10;
  dest->v3.w = w;
  dest->v0.y = v3;
  dest->v0.z = v4;
  dest->v0.w = v14;
  dest->v1.z = v13;
  dest->v1.w = v15;
  dest->v2.w = v16;
}

// File Line: 1160
// RVA: 0x1870A0
void __fastcall UFG::qInverseAffine(UFG::qMatrix44 *d, UFG::qMatrix44 *m)
{
  float x; // xmm1_4
  float z; // xmm3_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm8_4
  float y; // xmm7_4
  float v8; // xmm9_4
  float v9; // xmm4_4
  int v10; // xmm12_4
  int v11; // xmm10_4
  int v12; // xmm11_4
  float v13; // xmm0_4

  x = m->v0.x;
  z = m->v0.z;
  v4 = m->v1.x;
  v5 = m->v1.z;
  v6 = m->v2.x;
  y = m->v2.y;
  v8 = m->v2.z;
  v9 = m->v1.y;
  v10 = LODWORD(m->v3.y) ^ _xmm[0];
  v11 = LODWORD(m->v3.z) ^ _xmm[0];
  v12 = LODWORD(m->v3.x) ^ _xmm[0];
  v13 = m->v0.y;
  d->v0.x = m->v0.x;
  d->v0.w = 0.0;
  d->v1.w = 0.0;
  d->v2.w = 0.0;
  d->v3.w = 1.0;
  d->v1.x = v13;
  d->v2.x = z;
  d->v0.z = v6;
  d->v1.z = y;
  d->v2.y = v5;
  d->v2.z = v8;
  d->v0.y = v4;
  d->v3.z = (float)((float)(*(float *)&v10 * y) + (float)(*(float *)&v12 * v6)) + (float)(*(float *)&v11 * v8);
  d->v3.y = (float)((float)(*(float *)&v10 * v9) + (float)(*(float *)&v12 * v4)) + (float)(*(float *)&v11 * v5);
  d->v1.y = v9;
  d->v3.x = (float)((float)(*(float *)&v10 * v13) + (float)(*(float *)&v12 * x)) + (float)(*(float *)&v11 * z);
}

// File Line: 1180
// RVA: 0x187750
void __fastcall UFG::qLookAtMatrix(UFG::qMatrix44 *dest, UFG::qVector3 *eye, UFG::qVector3 *target, UFG::qVector3 *up)
{
  __m128 x_low; // xmm5
  float v5; // xmm4_4
  float v6; // xmm6_4
  __m128 v7; // xmm2
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm10_4
  float v11; // xmm9_4
  float y; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  __m128 z_low; // xmm6
  float v16; // xmm8_4
  __m128 v17; // xmm2
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm8_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm9_4
  float v26; // xmm4_4

  x_low = (__m128)LODWORD(eye->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - target->x;
  v5 = eye->z - target->z;
  v7 = x_low;
  v6 = eye->y - target->y;
  v7.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v6 * v6)) + (float)(v5 * v5);
  if ( v7.m128_f32[0] == 0.0 )
    v8 = 0.0;
  else
    v8 = 1.0 / _mm_sqrt_ps(v7).m128_f32[0];
  v9 = v5 * v8;
  v10 = v8 * v6;
  z_low = (__m128)LODWORD(up->z);
  v11 = v8 * x_low.m128_f32[0];
  y = up->y;
  v13 = y * v11;
  v14 = (float)(y * v9) - (float)(up->z * v10);
  z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v11) - (float)(up->x * v9);
  v16 = (float)(up->x * v10) - v13;
  v17 = z_low;
  v17.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
  if ( v17.m128_f32[0] == 0.0 )
    v18 = 0.0;
  else
    v18 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
  v19 = v14 * v18;
  v20 = z_low.m128_f32[0] * v18;
  dest->v0.z = v11;
  dest->v1.z = v10;
  dest->v2.z = v9;
  dest->v0.w = 0.0;
  dest->v1.w = 0.0;
  dest->v2.w = 0.0;
  v21 = v16 * v18;
  dest->v0.x = v19;
  dest->v1.x = v20;
  dest->v2.x = v21;
  v22 = (float)(v21 * v10) - (float)(v9 * v20);
  dest->v0.y = v22;
  v23 = (float)(v9 * v19) - (float)(v21 * v11);
  dest->v1.y = v23;
  v24 = (float)(v20 * v11) - (float)(v10 * v19);
  dest->v2.y = v24;
  LODWORD(dest->v3.x) = COERCE_UNSIGNED_INT((float)((float)(v19 * eye->x) + (float)(v20 * eye->y)) + (float)(v21 * eye->z)) ^ _xmm[0];
  LODWORD(dest->v3.y) = COERCE_UNSIGNED_INT((float)((float)(v22 * eye->x) + (float)(v23 * eye->y)) + (float)(v24 * eye->z)) ^ _xmm[0];
  v25 = (float)(v11 * eye->x) + (float)(v10 * eye->y);
  v26 = v9 * eye->z;
  dest->v3.w = 1.0;
  LODWORD(dest->v3.z) = COERCE_UNSIGNED_INT(v25 + v26) ^ _xmm[0];
}

// File Line: 1205
// RVA: 0x18A810
void __fastcall UFG::qRotationMatrixX(UFG::qMatrix44 *dest, float radians)
{
  float v3; // xmm7_4
  float v4; // xmm0_4

  v3 = cosf(radians);
  v4 = sinf(radians);
  dest->v1.y = v3;
  dest->v2.z = v3;
  *(_QWORD *)&dest->v0.x = 1065353216i64;
  dest->v1.x = 0.0;
  dest->v3.w = 1.0;
  *(_QWORD *)&dest->v0.z = 0i64;
  dest->v1.z = v4;
  LODWORD(dest->v2.y) = LODWORD(v4) ^ _xmm[0];
  *(_QWORD *)&dest->v1.w = 0i64;
  *(_QWORD *)&dest->v2.w = 0i64;
  *(_QWORD *)&dest->v3.y = 0i64;
}

// File Line: 1216
// RVA: 0x18AA00
void __fastcall UFG::qRotationMatrixY(UFG::qMatrix44 *dest, float radians)
{
  float v3; // xmm7_4
  float v4; // xmm0_4

  v3 = cosf(radians);
  v4 = sinf(radians);
  dest->v0.x = v3;
  dest->v2.z = v3;
  *(_QWORD *)&dest->v1.y = 1065353216i64;
  dest->v0.y = 0.0;
  dest->v1.w = 0.0;
  dest->v2.y = 0.0;
  dest->v2.x = v4;
  *(_QWORD *)&dest->v0.w = 0i64;
  *(_QWORD *)&dest->v2.w = 0i64;
  *(_QWORD *)&dest->v3.y = 0i64;
  LODWORD(dest->v0.z) = LODWORD(v4) ^ _xmm[0];
  dest->v3.w = 1.0;
}

// File Line: 1227
// RVA: 0x18AA80
void __fastcall UFG::qRotationMatrixZ(UFG::qMatrix44 *dest, float radians)
{
  float v3; // xmm7_4
  float v4; // xmm0_4

  v3 = cosf(radians);
  v4 = sinf(radians);
  dest->v0.x = v3;
  dest->v1.y = v3;
  *(_QWORD *)&dest->v2.z = 1065353216i64;
  dest->v3.z = 0.0;
  dest->v3.w = 1.0;
  *(_QWORD *)&dest->v0.z = 0i64;
  dest->v0.y = v4;
  LODWORD(dest->v1.x) = LODWORD(v4) ^ _xmm[0];
  *(_QWORD *)&dest->v1.z = 0i64;
  *(_QWORD *)&dest->v2.x = 0i64;
  *(_QWORD *)&dest->v3.x = 0i64;
}

// File Line: 1238
// RVA: 0x18A890
void __fastcall UFG::qRotationMatrixXYZDepreciated(UFG::qMatrix44 *rot, UFG::qVector3 *radians)
{
  float x; // xmm8_4
  float v5; // xmm0_4
  float y; // xmm7_4
  float v7; // xmm11_4
  float v8; // xmm10_4
  float v9; // xmm9_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm5_4

  x = radians->x;
  v5 = sinf(radians->x);
  y = radians->y;
  v7 = v5;
  v8 = sinf(y);
  v9 = sinf(radians->z);
  v10 = cosf(x);
  v11 = cosf(y);
  v12 = cosf(radians->z);
  rot->v2.x = v8;
  rot->v0.w = 0.0;
  rot->v1.w = 0.0;
  rot->v2.w = 0.0;
  rot->v0.x = v12 * v11;
  rot->v0.y = (float)((float)(v8 * v7) * v12) + (float)(v9 * v10);
  rot->v0.z = (float)(v7 * v9) - (float)((float)(v8 * v10) * v12);
  rot->v2.z = v10 * v11;
  LODWORD(rot->v1.x) = COERCE_UNSIGNED_INT(v9 * v11) ^ _xmm[0];
  rot->v1.y = (float)(v10 * v12) - (float)((float)(v8 * v7) * v9);
  LODWORD(rot->v2.y) = COERCE_UNSIGNED_INT(v7 * v11) ^ _xmm[0];
  rot->v1.z = (float)((float)(v8 * v10) * v9) + (float)(v7 * v12);
}

// File Line: 1247
// RVA: 0x18A6A0
void __fastcall UFG::qRotationMatrixEuler(UFG::qMatrix44 *rot, UFG::qVector3 *angles)
{
  float x; // xmm8_4
  float v5; // xmm0_4
  float y; // xmm7_4
  float v7; // xmm11_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm0_4

  x = angles->x;
  v5 = sinf(angles->x);
  y = angles->y;
  v7 = v5;
  v8 = sinf(y);
  v9 = sinf(angles->z);
  v10 = cosf(x);
  v11 = cosf(y);
  v12 = cosf(angles->z);
  rot->v3.w = 1.0;
  rot->v0.y = v9 * v11;
  rot->v0.w = 0.0;
  rot->v1.w = 0.0;
  *(_QWORD *)&rot->v2.w = 0i64;
  rot->v0.x = v12 * v11;
  *(_QWORD *)&rot->v3.y = 0i64;
  LODWORD(rot->v0.z) = LODWORD(v8) ^ _xmm[0];
  rot->v1.x = (float)((float)(v7 * v8) * v12) - (float)(v10 * v9);
  rot->v1.y = (float)((float)(v7 * v8) * v9) + (float)(v10 * v12);
  rot->v1.z = v7 * v11;
  rot->v2.z = v10 * v11;
  rot->v2.x = (float)((float)(v10 * v8) * v12) + (float)(v7 * v9);
  rot->v2.y = (float)((float)(v10 * v8) * v9) - (float)(v7 * v12);
}

// File Line: 1258
// RVA: 0x18A530
void __fastcall UFG::qRotationMatrixAxis(UFG::qMatrix44 *dest, UFG::qVector3 *axis, float radians)
{
  float v5; // xmm11_4
  float v6; // xmm0_4
  float z; // xmm9_4
  float x; // xmm8_4
  float y; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm8_4
  float v14; // xmm0_4

  v5 = cosf(radians);
  v6 = sinf(radians);
  z = axis->z;
  x = axis->x;
  y = axis->y;
  dest->v0.w = 0.0;
  dest->v1.w = 0.0;
  *(_QWORD *)&dest->v2.w = 0i64;
  *(_QWORD *)&dest->v3.y = 0i64;
  dest->v3.w = 1.0;
  v10 = x * (float)(1.0 - v5);
  v11 = v10 * z;
  v12 = v10 * y;
  dest->v0.x = (float)((float)(x * (float)(1.0 - v5)) * x) + v5;
  v13 = x * v6;
  dest->v0.y = v12 - (float)(z * v6);
  dest->v1.x = (float)(z * v6) + v12;
  dest->v0.z = (float)(y * v6) + v11;
  dest->v2.x = v11 - (float)(y * v6);
  v14 = y * (float)(1.0 - v5);
  dest->v1.y = (float)(v14 * y) + v5;
  dest->v1.z = (float)(v14 * z) - v13;
  dest->v2.y = v13 + (float)(v14 * z);
  dest->v2.z = (float)((float)(z * (float)(1.0 - v5)) * z) + v5;
}

// File Line: 1277
// RVA: 0x182C10
char __fastcall UFG::qDecomposeAffineEuler(
        UFG::qVector3 *sol_a,
        UFG::qVector3 *sol_b,
        UFG::qMatrix44 *m,
        bool pos_bias)
{
  __m128 v4; // xmm4
  __m128 v8; // xmm3
  float x; // xmm11_4
  float v10; // xmm10_4
  __m128 y_low; // xmm5
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm11_4
  float v16; // xmm4_4
  float v17; // xmm11_4
  float v18; // xmm4_4
  float v19; // xmm10_4
  float v20; // xmm1_4
  float v21; // xmm10_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  char result; // al
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // [rsp+90h] [rbp+8h]
  float v40; // [rsp+A0h] [rbp+18h]

  y_low = (__m128)LODWORD(m->v0.y);
  v4 = (__m128)LODWORD(m->v1.y);
  v8 = (__m128)LODWORD(m->v2.y);
  x = m->v0.x;
  v10 = m->v1.x;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x))
                            + (float)(m->v0.z * m->v0.z))
                    + (float)(m->v0.w * m->v0.w);
  if ( y_low.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
  v40 = v12 * x;
  v13 = v12 * m->v0.y;
  v14 = v12 * m->v0.z;
  v39 = v13;
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v10 * v10))
                         + (float)(m->v1.z * m->v1.z))
                 + (float)(m->v1.w * m->v1.w);
  if ( v4.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / _mm_sqrt_ps(v4).m128_f32[0];
  v16 = v15;
  v17 = v15 * m->v1.z;
  v18 = v16 * v10;
  v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(m->v2.x * m->v2.x))
                         + (float)(m->v2.z * m->v2.z))
                 + (float)(m->v2.w * m->v2.w);
  if ( v8.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
  v20 = v19;
  v21 = v19 * m->v2.z;
  v22 = v20 * m->v2.x;
  v23 = v14 - -1.0;
  sol_a->z = 0.0;
  if ( (float)(v14 - -1.0) < 0.0 )
    LODWORD(v23) ^= _xmm[0];
  if ( v23 >= 0.0000099999997 )
  {
    v27 = v14 - 1.0;
    if ( (float)(v14 - 1.0) < 0.0 )
      LODWORD(v27) ^= _xmm[0];
    if ( v27 >= 0.0000099999997 )
    {
      if ( v14 <= -1.0 )
      {
        v14 = FLOAT_N1_0;
      }
      else if ( v14 >= 1.0 )
      {
        v14 = *(float *)&FLOAT_1_0;
      }
      LODWORD(v30) = COERCE_UNSIGNED_INT(asinf(v14)) ^ _xmm[0];
      sol_a->y = v30;
      v31 = UFG::qNormalizedAngleBiased(3.1415927 - v30, pos_bias);
      sol_b->y = v31;
      v32 = cosf(sol_a->y);
      v33 = cosf(v31);
      v34 = atan2f((float)(1.0 / v32) * v17, (float)(1.0 / v32) * v21);
      sol_a->x = UFG::qNormalizedAngleBiased(v34, pos_bias);
      v35 = atan2f((float)(1.0 / v33) * v17, (float)(1.0 / v33) * v21);
      sol_b->x = UFG::qNormalizedAngleBiased(v35, pos_bias);
      v36 = atan2f((float)(1.0 / v32) * v39, (float)(1.0 / v32) * v40);
      sol_a->z = UFG::qNormalizedAngleBiased(v36, pos_bias);
      v37 = atan2f((float)(1.0 / v33) * v39, (float)(1.0 / v33) * v40);
      v38 = UFG::qNormalizedAngleBiased(v37, pos_bias);
      result = 0;
      sol_b->z = v38;
    }
    else
    {
      sol_a->y = -0.63661975;
      v28 = atan2f(COERCE_FLOAT(LODWORD(v18) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v22) ^ _xmm[0]));
      v29 = UFG::qNormalizedAngleBiased(v28, pos_bias);
      result = 1;
      sol_a->x = v29;
      sol_b->x = v29;
      sol_b->y = -0.63661975;
      sol_b->z = 0.0;
    }
  }
  else
  {
    sol_a->y = 1.5707964;
    v24 = atan2f(v18, v22);
    v25 = UFG::qNormalizedAngleBiased(v24, pos_bias);
    result = 1;
    sol_a->x = v25;
    sol_b->x = v25;
    *(_QWORD *)&sol_b->y = 1070141403i64;
  }
  return result;
}s_bias);
    result = 1;
    sol_a->x = v25;
    sol_b->x = v25;
    *(_QWORD *)&sol_b->y = 1070141403i64;
  }

// File Line: 1321
// RVA: 0x18C5E0
void __fastcall UFG::qTranslationMatrix(UFG::qMatrix44 *dest, UFG::qVector3 *offset)
{
  UFG::qVector4 v2; // xmm2

  v2 = 0i64;
  v2.x = (float)1;
  dest->v0 = v2;
  dest->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  dest->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  dest->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  dest->v3.x = offset->x;
  dest->v3.y = offset->y;
  dest->v3.z = offset->z;
}

// File Line: 1330
// RVA: 0x18ABA0
void __fastcall UFG::qScaleMatrix(UFG::qMatrix44 *dest, UFG::qVector3 *scale)
{
  UFG::qVector4 v2; // xmm2

  v2 = 0i64;
  v2.x = (float)1;
  dest->v0 = v2;
  dest->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  dest->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  dest->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  dest->v0.x = scale->x;
  dest->v1.y = scale->y;
  dest->v2.z = scale->z;
}

// File Line: 1339
// RVA: 0x187970
bool __fastcall UFG::qMakeMatrix(
        UFG::qMatrix44 *dest,
        UFG::qVector3 *forward,
        UFG::qVector3 *up,
        UFG::qVector3 *translation,
        float threshold)
{
  float z; // xmm11_4
  float y; // xmm10_4
  float x; // xmm9_4
  __m128 y_low; // xmm13
  float v9; // xmm14_4
  float v10; // xmm8_4
  __m128 v11; // xmm12
  float v12; // xmm5_4
  __m128 z_low; // xmm6
  float v14; // xmm7_4
  __m128 x_low; // xmm4
  float v16; // xmm1_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  float v19; // xmm11_4
  float v20; // xmm1_4
  float v21; // xmm13_4
  float v22; // xmm14_4
  float v23; // xmm8_4
  __m128 v24; // xmm4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  bool result; // al

  z = forward->z;
  y = forward->y;
  x = forward->x;
  y_low = (__m128)LODWORD(up->y);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * z) - (float)(up->z * y);
  v11 = y_low;
  v9 = (float)(forward->x * up->z) - (float)(up->x * z);
  v10 = (float)(up->x * y) - (float)(forward->x * up->y);
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] <= threshold )
    return 0;
  z_low = (__m128)LODWORD(forward->z);
  x_low = (__m128)LODWORD(forward->x);
  v12 = (float)(y * v10) - (float)(z * v9);
  z_low.m128_f32[0] = (float)(z * y_low.m128_f32[0]) - (float)(x * v10);
  v14 = (float)(x * v9) - (float)(y * y_low.m128_f32[0]);
  x_low.m128_f32[0] = (float)((float)(x * x) + (float)(y * y)) + (float)(z * z);
  if ( x_low.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
  v17 = x * v16;
  v18 = y * v16;
  v19 = z * v16;
  if ( v11.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  v21 = y_low.m128_f32[0] * v20;
  v22 = v9 * v20;
  v23 = v10 * v20;
  v24 = z_low;
  v24.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  dest->v0.x = v17;
  dest->v0.y = v18;
  dest->v0.z = v19;
  dest->v0.w = 0.0;
  dest->v1.w = 0.0;
  dest->v1.x = v21;
  dest->v1.y = v22;
  dest->v1.z = v23;
  dest->v2.w = 0.0;
  dest->v2.y = z_low.m128_f32[0] * v25;
  dest->v2.z = v14 * v25;
  dest->v2.x = v12 * v25;
  v26 = translation->y;
  v27 = translation->z;
  dest->v3.x = translation->x;
  dest->v3.w = 1.0;
  result = 1;
  dest->v3.y = v26;
  dest->v3.z = v27;
  return result;
}

// File Line: 1390
// RVA: 0x184B40
UFG::qVector3 *__fastcall UFG::qGetScreenCoord(
        UFG::qVector3 *result,
        UFG::qVector3 *world_pos,
        UFG::qMatrix44 *world_view_projection,
        UFG::qVector2 *viewport_scale,
        bool *is_on_screen)
{
  float x; // xmm2_4
  float z; // xmm3_4
  float y; // xmm6_4
  float v8; // xmm4_4
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm8_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  bool v27; // al
  UFG::qVector3 *v28; // rax
  float v29; // xmm0_4

  x = world_pos->x;
  z = world_pos->z;
  y = world_pos->y;
  v8 = y * world_view_projection->v1.w;
  v9 = y * world_view_projection->v1.z;
  v10 = (float)((float)((float)(y * world_view_projection->v1.x) + (float)(world_pos->x * world_view_projection->v0.x))
              + (float)(z * world_view_projection->v2.x))
      + world_view_projection->v3.x;
  v11 = z * world_view_projection->v2.y;
  v12 = (float)(world_pos->y * world_view_projection->v1.y) + (float)(world_pos->x * world_view_projection->v0.y);
  result->x = v10;
  v13 = x * world_view_projection->v0.z;
  v14 = x * world_view_projection->v0.w;
  v15 = v12 + v11;
  v16 = z;
  v17 = v15 + world_view_projection->v3.y;
  v18 = v9 + v13;
  v19 = FLOAT_1_1920929eN7;
  v20 = z * world_view_projection->v2.w;
  v21 = v16 * world_view_projection->v2.z;
  result->y = v17;
  v22 = (float)(v18 + v21) + world_view_projection->v3.z;
  v23 = (float)((float)(v8 + v14) + v20) + world_view_projection->v3.w;
  result->z = v22;
  if ( v23 < 0.00000011920929 && v23 >= 0.0 || (v19 = FLOAT_N1_1920929eN7, v23 > -0.00000011920929) && v23 < 0.0 )
    v23 = v19;
  v24 = (float)(1.0 / v23) * v22;
  v25 = (float)(1.0 / v23) * v10;
  v26 = (float)(1.0 / v23) * v17;
  result->z = v24;
  result->x = v25;
  result->y = v26;
  if ( is_on_screen )
  {
    v27 = v25 > -1.0 && v25 < 1.0 && v26 > -1.0 && v26 < 1.0 && v24 > 0.0 && v24 < 1.0;
    *is_on_screen = v27;
  }
  v28 = result;
  v29 = (float)((float)(v26 - 1.0) * viewport_scale->y) * -0.5;
  result->x = (float)((float)(v25 + 1.0) * viewport_scale->x) * 0.5;
  result->y = v29;
  return v28;
}

