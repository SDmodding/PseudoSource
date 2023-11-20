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
int UFG::qSignedMod(...)
{
  float v2; // xmm1_4
  __m128 v3; // xmm2
  float v4; // xmm3_4
  signed int v5; // ecx

  LODWORD(v2) = LODWORD(b) & _xmm;
  v3 = (__m128)a;
  if ( v2 > 1.1754944e-38 )
  {
    v3.m128_f32[0] = *(float *)&a / v2;
    v4 = *(float *)&a / v2;
    v5 = (signed int)(float)(*(float *)&a / v2);
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
  int v2; // er8
  __int64 result; // rax
  int v4; // eax

  v2 = b;
  if ( b < 0 )
    v2 = -b;
  result = (unsigned int)a;
  if ( v2 > 0 )
  {
    v4 = v2 * ((signed int)result / v2);
    if ( a < 0 )
      v4 -= v2;
    result = (unsigned int)(a - v4);
  }
  return result;
}

// File Line: 138
// RVA: 0x1895E0
__int64 __fastcall UFG::qRandom(int range, int *pseed)
{
  int v3; // eax

  if ( !range )
    return 0i64;
  v3 = *pseed;
  *pseed ^= 0x1D872B41 ^ *pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41u) >> 5) ^ ((*pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41u) >> 5)) << 27);
  return (v3 % range + range) % (unsigned int)range;
}

// File Line: 158
// RVA: 0x189620
float __fastcall UFG::qRandom(float range, int *pseed)
{
  int *v2; // r9
  int v3; // er10
  unsigned int v4; // er8
  unsigned int v5; // edx
  float result; // xmm0_4

  v2 = pseed;
  v3 = *pseed;
  v4 = *pseed ^ 0x1D872B41;
  v5 = (signed int)(*pseed + ((unsigned __int64)(-2147483519i64 * *pseed) >> 32)) >> 23;
  *v2 = v4 ^ v4 ^ (v4 >> 5) ^ ((v4 ^ (v4 >> 5)) << 27);
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
    result = 1;
  }
  return result;
}

// File Line: 215
// RVA: 0x181B00
char __fastcall UFG::qApproachOrientation(UFG::qQuaternion *orientation, UFG::qQuaternion *dest, float rate, float dt)
{
  UFG::qQuaternion *v4; // rbx
  float v5; // xmm10_4
  float v6; // xmm9_4
  float v7; // xmm11_4
  int v8; // xmm4_4
  int v9; // xmm5_4
  float v10; // xmm15_4
  float v11; // xmm2_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm7_4
  float v15; // xmm9_4
  float v16; // xmm0_4
  __m128 v17; // xmm1
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm8_4
  float v21; // xmm9_4
  float v22; // xmm7_4
  float v23; // xmm11_4
  float v24; // xmm1_4
  char result; // al
  float v26; // xmm11_4
  float v27; // xmm0_4
  float v28; // xmm8_4
  float v29; // xmm9_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm13_4
  float v33; // xmm4_4
  float v34; // xmm3_4
  float v35; // xmm11_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm12_4
  float v39; // xmm12_4
  float v40; // xmm0_4
  float v41; // xmm8_4
  float v42; // xmm15_4
  __int128 v43; // xmm5
  __m128 v44; // xmm2
  float v45; // xmm6_4
  float v46; // [rsp+20h] [rbp-B8h]
  float v47; // [rsp+24h] [rbp-B4h]
  float v48; // [rsp+E0h] [rbp+8h]
  float v49; // [rsp+E8h] [rbp+10h]
  float v50; // [rsp+F0h] [rbp+18h]

  v4 = orientation;
  v47 = orientation->z;
  v5 = dest->w;
  v6 = dest->z;
  v50 = dest->x;
  v49 = v6;
  v46 = dest->w;
  v7 = rate;
  v8 = LODWORD(orientation->y) ^ _xmm[0];
  v9 = LODWORD(orientation->x) ^ _xmm[0];
  v48 = dest->y;
  v10 = orientation->w;
  v11 = dest->y;
  v12 = (float)((float)((float)(dest->x * COERCE_FLOAT(LODWORD(v47) ^ _xmm[0])) + (float)(v5 * *(float *)&v8))
              - (float)(v6 * *(float *)&v9))
      + (float)(v11 * v10);
  v13 = (float)((float)((float)(v5 * COERCE_FLOAT(LODWORD(v47) ^ _xmm[0])) + (float)(v11 * *(float *)&v9))
              - (float)(dest->x * *(float *)&v8))
      + (float)(v6 * v10);
  v14 = (float)(v5 * v10)
      - (float)((float)((float)(v11 * *(float *)&v8) + (float)(dest->x * *(float *)&v9))
              + (float)(v6 * COERCE_FLOAT(LODWORD(v47) ^ _xmm[0])));
  v15 = (float)((float)((float)(v6 * *(float *)&v8) + (float)(v5 * *(float *)&v9))
              - (float)(v11 * COERCE_FLOAT(LODWORD(v47) ^ _xmm[0])))
      + (float)(dest->x * v10);
  v16 = FLOAT_N1_0;
  if ( v14 > -1.0 )
  {
    v16 = v14;
    if ( v14 >= 1.0 )
      v16 = *(float *)&FLOAT_1_0;
  }
  v17 = (__m128)(unsigned int)FLOAT_1_0;
  v18 = acosf(v16) * 2.0;
  v17.m128_f32[0] = 1.0 - (float)(v14 * v14);
  LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v17);
  if ( v19 >= 0.000099999997 )
  {
    v20 = (float)(1.0 / v19) * v15;
    v22 = (float)(1.0 / v19) * v13;
    v21 = (float)(1.0 / v19) * v12;
  }
  else
  {
    v20 = *(float *)&FLOAT_1_0;
    v21 = 0.0;
    v22 = 0.0;
  }
  if ( v18 > 3.1415927 )
  {
    LODWORD(v20) ^= _xmm[0];
    LODWORD(v21) ^= _xmm[0];
    LODWORD(v22) ^= _xmm[0];
    v18 = 6.2831855 - v18;
  }
  v23 = v7 * dt;
  if ( v18 > v23 )
  {
    v26 = v23 * 0.5;
    v27 = sinf(v26);
    v28 = v20 * v27;
    v29 = v21 * v27;
    v30 = v22 * v27;
    v31 = cosf(v26);
    v32 = v4->x;
    v43 = LODWORD(v4->y);
    v33 = v31;
    v34 = v4->z;
    v35 = (float)((float)((float)(v47 * v28) + (float)(v4->y * v31)) - (float)(v4->x * v30)) + (float)(v10 * v29);
    v36 = v4->y * v28;
    v37 = v4->y;
    v38 = (float)(v47 * v31) + (float)(v4->x * v29);
    v4->y = v35;
    v39 = (float)(v38 - v36) + (float)(v10 * v30);
    v4->z = v39;
    v40 = v32 * v28;
    v41 = v28 * v4->w;
    v42 = (float)(v10 * v33) - (float)((float)((float)(v37 * v29) + v40) + (float)(v34 * v30));
    v4->w = v42;
    *(float *)&v43 = (float)((float)((float)(*(float *)&v43 * v30) + (float)(v32 * v33)) - (float)(v34 * v29)) + v41;
    LODWORD(v4->x) = v43;
    v44 = (__m128)v43;
    v44.m128_f32[0] = (float)((float)((float)(*(float *)&v43 * *(float *)&v43) + (float)(v35 * v35)) + (float)(v39 * v39))
                    + (float)(v42 * v42);
    if ( v44.m128_f32[0] == 0.0 )
      v45 = 0.0;
    else
      v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
    result = 0;
    v4->x = *(float *)&v43 * v45;
    v4->z = v45 * v39;
    v4->w = v45 * v42;
    v24 = v45 * v35;
  }
  else
  {
    v24 = v48;
    result = 1;
    v4->x = v50;
    v4->z = v49;
    v4->w = v46;
  }
  v4->y = v24;
  return result;
}

// File Line: 249
// RVA: 0x1892E0
UFG::qVector2 *__fastcall UFG::qRandom(UFG::qVector2 *result, UFG::qVector2 *range, int *pseed)
{
  int v3; // edi
  float v4; // xmm3_4
  int v5; // er10
  float v6; // xmm1_4
  UFG::qVector2 *v7; // rax

  v3 = *pseed;
  v4 = range->y * 0.000000059604652;
  v5 = *pseed ^ 0x1D872B41 ^ *pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41u) >> 5) ^ ((*pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41u) >> 5)) << 27);
  *pseed = v5;
  v6 = range->x;
  *pseed = v5 ^ 0x1D872B41 ^ v5 ^ 0x1D872B41 ^ ((v5 ^ 0x1D872B41u) >> 5) ^ ((v5 ^ 0x1D872B41 ^ ((v5 ^ 0x1D872B41u) >> 5)) << 27);
  v7 = result;
  LODWORD(result->x) = COERCE_UNSIGNED_INT((float)((v5 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * (float)(v6 * 0.000000059604652)) & _xmm;
  LODWORD(result->y) = COERCE_UNSIGNED_INT((float)((v3 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * v4) & _xmm;
  return v7;
}

// File Line: 250
// RVA: 0x189420
UFG::qVector3 *__fastcall UFG::qRandom(UFG::qVector3 *result, UFG::qVector3 *range, int *pseed)
{
  float v3; // xmm4_4
  int v4; // er9
  UFG::qVector3 *v5; // r10
  int *v6; // rbx
  int v7; // edx
  signed int v8; // er8
  unsigned int v9; // edi
  float v10; // xmm3_4
  signed int v11; // er9
  float v12; // xmm1_4
  UFG::qVector3 *v13; // rax

  v3 = range->z;
  v4 = *pseed;
  v5 = range;
  v6 = pseed;
  v7 = *pseed / 0xFFFFFF;
  v8 = *pseed ^ 0x1D872B41 ^ *pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41u) >> 5) ^ ((*pseed ^ 0x1D872B41 ^ ((*pseed ^ 0x1D872B41u) >> 5)) << 27);
  v9 = v4 - 0xFFFFFF * v7 + 0xFFFFFF;
  *v6 = v8;
  v10 = v5->y;
  v11 = v8 ^ 0x1D872B41 ^ v8 ^ 0x1D872B41 ^ ((v8 ^ 0x1D872B41u) >> 5) ^ ((v8 ^ 0x1D872B41 ^ ((v8 ^ 0x1D872B41u) >> 5)) << 27);
  *v6 = v11;
  v12 = v5->x * 0.000000059604652;
  *v6 = v11 ^ 0x1D872B41 ^ v11 ^ 0x1D872B41 ^ ((v11 ^ 0x1D872B41u) >> 5) ^ ((v11 ^ 0x1D872B41 ^ ((v11 ^ 0x1D872B41u) >> 5)) << 27);
  LODWORD(result->x) = COERCE_UNSIGNED_INT((float)((v11 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * v12) & _xmm;
  v13 = result;
  LODWORD(result->y) = COERCE_UNSIGNED_INT((float)((v8 % 0xFFFFFF + 0xFFFFFF) % 0xFFFFFFu) * (float)(v10 * 0.000000059604652)) & _xmm;
  LODWORD(result->z) = COERCE_UNSIGNED_INT((float)(v9 % 0xFFFFFF) * (float)(v3 * 0.000000059604652)) & _xmm;
  return v13;
}

// File Line: 264
// RVA: 0x183BA0
UFG::qVector3 *__fastcall UFG::qFloor(UFG::qVector3 *result, UFG::qVector3 *a)
{
  __m128 v2; // xmm1
  UFG::qVector3 *v3; // r9
  signed int v4; // er8
  __m128 v5; // xmm1
  signed int v6; // edx
  __m128 v7; // xmm1
  signed int v8; // edx

  v2 = (__m128)LODWORD(a->x);
  v3 = a;
  v4 = (signed int)v2.m128_f32[0];
  if ( (signed int)v2.m128_f32[0] != 0x80000000 && (float)v4 != v2.m128_f32[0] )
    v2.m128_f32[0] = (float)(v4 - (_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1));
  LODWORD(result->x) = v2.m128_i32[0];
  v5 = (__m128)LODWORD(a->y);
  v6 = (signed int)v5.m128_f32[0];
  if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v6 != v5.m128_f32[0] )
    v5.m128_f32[0] = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
  LODWORD(result->y) = v5.m128_i32[0];
  v7 = (__m128)LODWORD(v3->z);
  v8 = (signed int)v7.m128_f32[0];
  if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
    v7.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1));
  LODWORD(result->z) = v7.m128_i32[0];
  return result;
}

// File Line: 269
// RVA: 0x184ED0
signed __int64 __fastcall UFG::qIntersect(UFG::qVector2 *intersection, UFG::qVector2 *lA0, UFG::qVector2 *lA1, UFG::qVector2 *lB0, UFG::qVector2 *lB1, float *result)
{
  float v6; // xmm7_4
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

  v6 = lB0->y;
  v7 = lA1->x - lA0->x;
  v8 = lB1->x - lB0->x;
  v9 = lB0->x - lA0->x;
  v10 = lA1->y - lA0->y;
  v11 = lB1->y - v6;
  v12 = v6 - lA0->y;
  v13 = (float)(v8 * v10) - (float)(v7 * v11);
  v14 = (float)(v12 * v7) - (float)(v9 * v10);
  v15 = (float)(v12 * v8) - (float)(v9 * v11);
  if ( v13 == 0.0 )
    return v14 != 0.0 || v15 != 0.0;
  v17 = (float)(1.0 / v13) * v15;
  v18 = (float)(1.0 / v13) * v14;
  if ( v18 < 0.0 || v18 > 1.0 || v17 < 0.0 || v17 > 1.0 )
    return 2i64;
  intersection->x = (float)(v8 * v18) + lB0->x;
  intersection->y = (float)((float)(lB1->y - lB0->y) * v18) + lB0->y;
  if ( result )
    *result = v18;
  return 3i64;
}

// File Line: 302
// RVA: 0x183DA0
void __fastcall UFG::qGetClosestPointOnSegment(UFG::qVector2 *closest_point, UFG::qVector2 *lA0, UFG::qVector2 *lA1, UFG::qVector2 *P)
{
  float v4; // xmm3_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  __m128 v8; // xmm9
  __m128 v9; // xmm1
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  v4 = lA1->y;
  v5 = lA0->x;
  v6 = lA0->y;
  v8 = (__m128)LODWORD(lA1->y);
  v7 = lA1->x - lA0->x;
  v8.m128_f32[0] = v8.m128_f32[0] - v6;
  v9 = v8;
  v9.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7);
  LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v9);
  if ( v10 <= 0.0
    || (v11 = (float)((float)((float)(P->y - v6) * v8.m128_f32[0]) + (float)((float)(P->x - v5) * v7))
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
  closest_point->x = (float)((float)(lA1->x - v5) * v12) + v5;
  closest_point->y = (float)((float)(v4 - v6) * v12) + v6;
}

// File Line: 330
// RVA: 0x183E80
void __fastcall UFG::qGetClosestPointOnSegment(UFG::qVector3 *closest_point, UFG::qVector3 *lA0, UFG::qVector3 *lA1, UFG::qVector3 *P)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm10_4
  __m128 v9; // xmm12
  float v10; // xmm11_4
  __m128 v11; // xmm2
  float v12; // xmm13_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm0_4

  v4 = lA1->y;
  v5 = lA1->z;
  v6 = lA0->x;
  v7 = lA0->y;
  v8 = lA0->z;
  v9 = (__m128)LODWORD(lA1->y);
  v9.m128_f32[0] = v9.m128_f32[0] - v7;
  v10 = lA1->x - lA0->x;
  v11 = v9;
  v12 = lA1->z - v8;
  v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
  LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v11);
  if ( v13 <= 0.0
    || (v14 = (float)((float)((float)((float)(P->y - v7) * v9.m128_f32[0]) + (float)((float)(P->x - v6) * v10))
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
  closest_point->x = (float)((float)(lA1->x - v6) * v15) + v6;
  closest_point->y = (float)((float)(v4 - v7) * v15) + v7;
  closest_point->z = (float)((float)(v5 - v8) * v15) + v8;
}

// File Line: 497
// RVA: 0x1817D0
float __fastcall UFG::qAngleBetween(UFG::qVector2 *v1, UFG::qVector2 *v2)
{
  UFG::qVector2 *rbx1; // rbx
  float v3; // xmm0_4

  rbx1 = v1;
  v3 = atan2f(v2->y, v2->x);
  return v3 - atan2f(rbx1->y, rbx1->x);
}

// File Line: 503
// RVA: 0x181810
float __fastcall UFG::qAngleBetween(UFG::qVector3 *v1, UFG::qVector3 *v2)
{
  float xmm3_4_1; // xmm3_4
  __m128 v3; // xmm6
  float v4; // xmm7_4
  float v5; // xmm8_4
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
  v3 = (__m128)LODWORD(v1->x);
  v6 = v3;
  v4 = v1->y;
  v5 = v1->z;
  v6.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v4 * v4)) + (float)(v5 * v5);
  if ( v6.m128_f32[0] == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
  v8 = v2->y;
  v9 = (__m128)LODWORD(v2->x);
  v10 = v2->z;
  v11 = v3.m128_f32[0] * v7;
  v12 = v4 * v7;
  v13 = v5 * v7;
  v14 = v9;
  v14.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v14.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
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
void __fastcall UFG::qAngleBetweenNormals(UFG::qVector3 *n1, UFG::qVector3 *n2)
{
  float v2; // xmm2_4

  v2 = (float)((float)(n1->y * n2->y) + (float)(n1->x * n2->x)) + (float)(n1->z * n2->z);
  if ( v2 >= -0.99989998 && v2 <= 0.99989998 )
  {
    if ( v2 <= -1.0 )
    {
      v2 = FLOAT_N1_0;
    }
    else if ( v2 >= 1.0 )
    {
      acosf(1.0);
      return;
    }
    acosf(v2);
  }
}

// File Line: 547
// RVA: 0x184CF0
float __fastcall UFG::qHeading2D(UFG::qVector3 *v1)
{
  float xmm2_4_1; // xmm2_4
  __m128 v2; // xmm3
  __m128 v3; // xmm1
  float v4; // xmm4_4
  float result; // xmm0_4

  xmm2_4_1 = v1->x;
  v2 = (__m128)LODWORD(v1->y);
  v3 = v2;
  v3.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(xmm2_4_1 * xmm2_4_1);
  LODWORD(v4) = (unsigned __int128)_mm_sqrt_ps(v3);
  if ( v4 <= 0.0 )
    return 0.0;
  result = atan2f((float)(1.0 / v4) * v2.m128_f32[0], (float)(1.0 / v4) * xmm2_4_1);
  if ( result < 0.0 )
    result = result + 6.2831855;
  return result;
}

// File Line: 578
// RVA: 0x184D60
float __fastcall UFG::qHeadingDifference2D(UFG::qVector3 *v1, UFG::qVector3 *v2)
{
  UFG::qVector3 *rbx1; // rbx
  float v3; // xmm0_4
  float v4; // xmm6_4

  rbx1 = v1;
  v3 = UFG::qHeading2D(v2);
  v4 = v3 - UFG::qHeading2D(rbx1);
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
  UFG::qVector3 *v3; // rbx
  UFG::qVector3 *v4; // rdi
  float v5; // xmm7_4
  float v6; // xmm0_4

  v3 = source;
  v4 = dest;
  v5 = cosf(radians);
  v6 = sinf(radians);
  v4->x = (float)(v6 * v3->y) + (float)(v5 * v3->x);
  v4->y = (float)(v5 * v3->y) - (float)(v6 * v3->x);
  v4->z = v3->z;
}

// File Line: 597
// RVA: 0x18A440
void __fastcall UFG::qRotateVectorZ(UFG::qVector2 *dest, UFG::qVector2 *source, float radians)
{
  UFG::qVector2 *v3; // rbx
  UFG::qVector2 *v4; // rdi
  float v5; // xmm7_4
  float v6; // xmm0_4

  v3 = source;
  v4 = dest;
  v5 = cosf(radians);
  v6 = sinf(radians);
  v4->x = (float)(v6 * v3->y) + (float)(v5 * v3->x);
  v4->y = (float)(v5 * v3->y) - (float)(v6 * v3->x);
}

// File Line: 607
// RVA: 0x18AFE0
void __fastcall UFG::qSphericalToCartesian(UFG::qVector3 *position, float theta, float phi)
{
  UFG::qVector3 *v3; // rbx
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4

  v3 = position;
  v4 = (float)(phi * 3.1415927) * 0.0055555557;
  v5 = (float)(theta * 3.1415927) * 0.0055555557;
  v6 = sinf(v4);
  v3->x = cosf(v5) * v6;
  v3->y = sinf(v5) * v6;
  v3->z = cosf(v4);
}

// File Line: 667
// RVA: 0x17C660
void __fastcall UFG::qQuaternion::Set(UFG::qQuaternion *this, float angle, UFG::qVector3 *axis)
{
  UFG::qVector3 *v3; // rbx
  UFG::qQuaternion *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4

  v3 = axis;
  v4 = this;
  v5 = sinf(angle * 0.5);
  v6 = v5 * v3->z;
  v7 = v5 * v3->y;
  v4->x = v5 * v3->x;
  v4->y = v7;
  v4->z = v6;
  v4->w = cosf(angle * 0.5);
}

// File Line: 674
// RVA: 0x17C460
void __fastcall UFG::qQuaternion::Set(UFG::qQuaternion *this, UFG::qMatrix44 *mat)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  UFG::qQuaternion *v5; // r8
  float v6; // xmm5_4
  __m128 v7; // xmm3
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  signed int v11; // ecx
  int v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4

  v2 = (__m128)LODWORD(mat->v0.x);
  v3 = (__m128)LODWORD(mat->v1.y);
  v4 = (__m128)LODWORD(mat->v2.z);
  v5 = this;
  v7 = (__m128)LODWORD(mat->v2.z);
  v6 = mat->v0.x + v3.m128_f32[0];
  v7.m128_f32[0] = v7.m128_f32[0] + v6;
  if ( v7.m128_f32[0] <= 0.0 )
  {
    v10 = mat->v0.x;
    v11 = 0;
    if ( v3.m128_f32[0] > v2.m128_f32[0] )
    {
      v10 = mat->v1.y;
      v11 = 1;
    }
    if ( v4.m128_f32[0] > v10 )
      v11 = 2;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          v4.m128_f32[0] = (float)(v4.m128_f32[0] - v6) + 1.0;
          LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v4);
          v5->z = v13 * 0.5;
          v5->x = (float)(mat->v2.x + mat->v0.z) * (float)(0.5 / v13);
          v5->y = (float)(mat->v2.y + mat->v1.z) * (float)(0.5 / v13);
          v5->w = (float)(mat->v0.y - mat->v1.x) * (float)(0.5 / v13);
        }
      }
      else
      {
        v3.m128_f32[0] = (float)(v3.m128_f32[0] - (float)(v4.m128_f32[0] + v2.m128_f32[0])) + 1.0;
        LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v3);
        v5->y = v14 * 0.5;
        v5->z = (float)(mat->v2.y + mat->v1.z) * (float)(0.5 / v14);
        v5->x = (float)(mat->v1.x + mat->v0.y) * (float)(0.5 / v14);
        v5->w = (float)(mat->v2.x - mat->v0.z) * (float)(0.5 / v14);
      }
    }
    else
    {
      v2.m128_f32[0] = (float)(v2.m128_f32[0] - (float)(v4.m128_f32[0] + v3.m128_f32[0])) + 1.0;
      LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v2);
      v5->x = v15 * 0.5;
      v5->y = (float)(mat->v1.x + mat->v0.y) * (float)(0.5 / v15);
      v5->z = (float)(mat->v2.x + mat->v0.z) * (float)(0.5 / v15);
      v5->w = (float)(mat->v1.z - mat->v2.y) * (float)(0.5 / v15);
    }
  }
  else
  {
    v7.m128_f32[0] = v7.m128_f32[0] + 1.0;
    LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
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
  float v2; // xmm4_4
  float v3; // xmm11_4
  float v4; // xmm9_4
  float v5; // xmm10_4
  float v6; // xmm12_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm10_4
  int v11; // xmm13_4
  int v12; // xmm12_4
  int v13; // xmm11_4
  float v14; // xmm2_4

  v2 = v->y;
  v3 = this->y;
  v4 = this->w;
  v5 = v->z;
  v6 = this->z;
  v7 = (float)((float)((float)(v->x * v6) + (float)(this->y * 0.0)) - (float)(v->z * this->x)) + (float)(v4 * v2);
  v8 = (float)((float)((float)(v->y * this->x) + (float)(this->z * 0.0)) - (float)(v->x * v3)) + (float)(this->w * v5);
  v9 = (float)(this->w * 0.0) - (float)((float)((float)(v->y * v3) + (float)(v->x * this->x)) + (float)(v->z * v6));
  v10 = (float)((float)((float)(v5 * v3) + (float)(this->x * 0.0)) - (float)(v2 * v6)) + (float)(this->w * v->x);
  v11 = LODWORD(this->x) ^ _xmm[0];
  v12 = LODWORD(v6) ^ _xmm[0];
  v13 = LODWORD(v3) ^ _xmm[0];
  v14 = (float)((float)(this->w * v8) + (float)(*(float *)&v13 * v10)) - (float)(*(float *)&v11 * v7);
  v->y = (float)((float)((float)(*(float *)&v11 * v8) + (float)(this->w * v7)) - (float)(*(float *)&v12 * v10))
       + (float)(*(float *)&v13 * v9);
  v->x = (float)((float)((float)(*(float *)&v12 * v7) + (float)(v4 * v10)) - (float)(*(float *)&v13 * v8))
       + (float)(*(float *)&v11 * v9);
  v->z = v14 + (float)(*(float *)&v12 * v9);
}

// File Line: 768
// RVA: 0x171170
UFG::qMatrix44 *__fastcall UFG::qQuaternion::GetMatrix(UFG::qQuaternion *this, UFG::qMatrix44 *result, UFG::qVector3 *t)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm10_4
  float v6; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm15_4
  float v11; // xmm10_4
  float v12; // xmm13_4
  float v13; // xmm12_4
  float v14; // xmm2_4
  float v15; // xmm9_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v21; // [rsp+B0h] [rbp+8h]

  v3 = this->y;
  v4 = this->w;
  v5 = this->z;
  v6 = this->z * v3;
  v7 = v5 * v4;
  v8 = this->x * this->x;
  v21 = this->x * v5;
  v9 = this->y * v3;
  v10 = this->y * v4;
  v11 = v5 * v5;
  v12 = this->x * v4;
  v13 = this->x * v3;
  v14 = t->z;
  v15 = 1.0 - (float)((float)(v8 + v9) * 2.0);
  v16 = (float)(v11 + v8) * 2.0;
  v17 = t->y;
  v18 = 1.0 - v16;
  v19 = t->x;
  result->v0.w = 0.0;
  result->v0.y = (float)(v7 + v13) * 2.0;
  result->v0.x = 1.0 - (float)((float)(v11 + v9) * 2.0);
  result->v0.z = (float)(v21 - v10) * 2.0;
  result->v1.y = v18;
  result->v1.w = 0.0;
  result->v1.x = (float)(v13 - v7) * 2.0;
  result->v1.z = (float)(v12 + v6) * 2.0;
  result->v2.w = 0.0;
  result->v2.x = (float)(v21 + v10) * 2.0;
  result->v2.y = (float)(v6 - v12) * 2.0;
  result->v2.z = v15;
  result->v3.x = v19;
  result->v3.y = v17;
  result->v3.z = v14;
  result->v3.w = 1.0;
  return result;
}

// File Line: 788
// RVA: 0x18AD40
UFG::qQuaternion *__fastcall UFG::qSlerp(UFG::qQuaternion *result, UFG::qQuaternion *a, UFG::qQuaternion *b, float t, UFG::qAngularPath path)
{
  UFG::qQuaternion *v5; // rbx
  float v6; // xmm7_4
  UFG::qQuaternion *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm13_4
  float v13; // xmm12_4
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

  v5 = result;
  v6 = t;
  if ( t >= 1.0 )
  {
    result->x = b->x;
    result->y = b->y;
    result->z = b->z;
    result->w = b->w;
    return result;
  }
  if ( t <= 0.0 )
  {
    result->x = a->x;
    result->y = a->y;
    result->z = a->z;
    result->w = a->w;
    return result;
  }
  v8 = a->y;
  v9 = a->z;
  v10 = b->w;
  v11 = a->w;
  v23 = v8;
  v12 = b->y;
  v13 = b->x;
  v14 = b->z;
  v15 = a->x;
  v22 = v9;
  v16 = (float)((float)((float)(v12 * v8) + (float)(b->x * a->x)) + (float)(v14 * v9)) + (float)(v10 * v11);
  switch ( path )
  {
    case 0:
      v17 = v16 < 0.0;
LABEL_13:
      if ( v17 )
      {
        LODWORD(v16) ^= _xmm[0];
        LODWORD(v13) ^= _xmm[0];
        LODWORD(v12) ^= _xmm[0];
        LODWORD(v14) ^= _xmm[0];
        LODWORD(v10) ^= _xmm[0];
      }
      break;
    case 1:
      v17 = v16 > 0.0;
      goto LABEL_13;
    case 2:
      v17 = v11 > v10;
      goto LABEL_13;
    case 3:
      v17 = v10 > v11;
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
    v8 = v23;
    v9 = v22;
    v6 = v21 * v20;
  }
  v7 = v5;
  v5->x = (float)(v15 * v18) + (float)(v6 * v13);
  v5->y = (float)(v8 * v18) + (float)(v6 * v12);
  v5->w = (float)(v11 * v18) + (float)(v6 * v10);
  v5->z = (float)(v9 * v18) + (float)(v6 * v14);
  return v7;
}

// File Line: 829
// RVA: 0x1881A0
UFG::qQuaternion *__fastcall UFG::qNlerp(UFG::qQuaternion *result, UFG::qQuaternion *a, UFG::qQuaternion *b, float t, UFG::qAngularPath path)
{
  float v5; // xmm11_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm7_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  __m128 v12; // xmm13
  float v13; // xmm10_4
  float v14; // xmm4_4
  bool v15; // al
  float v16; // xmm12_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  __m128 v19; // xmm4
  float v20; // xmm2_4

  v5 = t;
  if ( t >= 1.0 )
  {
    result->x = b->x;
    result->y = b->y;
    result->z = b->z;
    result->w = b->w;
    return result;
  }
  if ( t > 0.0 )
  {
    v7 = a->w;
    v8 = b->w;
    v9 = a->z;
    v10 = b->y;
    v11 = b->x;
    v12 = (__m128)LODWORD(a->y);
    v13 = b->z;
    v14 = (float)((float)((float)(v10 * v12.m128_f32[0]) + (float)(b->x * a->x)) + (float)(b->z * v9))
        + (float)(v8 * v7);
    if ( path )
    {
      switch ( path )
      {
        case 1:
          v15 = v14 > 0.0;
          break;
        case 2:
          v15 = v7 > v8;
          break;
        case 3:
          v15 = v8 > v7;
          break;
        default:
LABEL_15:
          v16 = (float)(a->x * (float)(1.0 - v5)) + (float)(v11 * v5);
          v12.m128_f32[0] = (float)(v12.m128_f32[0] * (float)(1.0 - v5)) + (float)(v10 * v5);
          v19 = v12;
          v17 = (float)(v9 * (float)(1.0 - v5)) + (float)(v13 * v5);
          v18 = (float)(v7 * (float)(1.0 - v5)) + (float)(v8 * v5);
          v19.m128_f32[0] = (float)((float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v16 * v16))
                                  + (float)(v17 * v17))
                          + (float)(v18 * v18);
          if ( v19.m128_f32[0] == 0.0 )
            v20 = 0.0;
          else
            v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
          result->z = v17 * v20;
          result->x = v20 * v16;
          result->y = v20 * v12.m128_f32[0];
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
      LODWORD(v11) ^= _xmm[0];
      LODWORD(v10) ^= _xmm[0];
      LODWORD(v13) ^= _xmm[0];
      LODWORD(v8) ^= _xmm[0];
    }
    goto LABEL_15;
  }
  result->x = a->x;
  result->y = a->y;
  result->z = a->z;
  result->w = a->w;
  return result;
}

// File Line: 867
// RVA: 0x188B20
void __fastcall UFG::qPerspectiveMatrix(UFG::qMatrix44 *dest, float fov_x, float aspect_ratio, float near_plane, float far_plane)
{
  UFG::qMatrix44 *v5; // rbx
  float v6; // xmm6_4
  __m128 v7; // xmm2
  float v8; // xmm4_4
  float v9; // xmm5_4

  v5 = dest;
  v6 = aspect_ratio;
  v7 = 0i64;
  v7.m128_f32[0] = (float)1;
  v8 = 1.0 / tanf(fov_x * 0.5);
  v5->v0 = (UFG::qVector4)v7;
  v9 = 1.0 / (float)(near_plane - far_plane);
  v5->v1 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 81);
  v5->v2 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 69);
  v5->v3 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 21);
  v5->v0.x = v8;
  v5->v2.w = -1.0;
  v5->v3.w = 0.0;
  v5->v3.z = (float)(near_plane * far_plane) * v9;
  v5->v2.z = v9 * far_plane;
  v5->v1.y = v8 * v6;
}

// File Line: 902
// RVA: 0x188BE0
void __fastcall UFG::qPerspectiveObliqueMatrix(UFG::qMatrix44 *dest, float fov_x, float aspect, float near_plane, float far_plane, float pan_x, float pan_y)
{
  UFG::qMatrix44 *v7; // rbx
  float v8; // xmm0_4

  v7 = dest;
  v8 = tanf(fov_x * 0.5) * near_plane;
  UFG::qFrustumMatrix(
    v7,
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
  float v8; // xmm10_4
  float v9; // xmm3_4
  float v10; // xmm9_4
  float v11; // xmm2_4

  v7 = 0i64;
  v7.x = (float)1;
  v8 = b;
  dest->v0 = v7;
  dest->v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 81);
  dest->v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 69);
  dest->v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 21);
  dest->v2.w = -1.0;
  dest->v3.w = 0.0;
  v9 = 1.0 / (float)(t - b);
  v10 = l + r;
  dest->v2.y = (float)(v8 + t) * v9;
  v11 = 1.0 / (float)(r - l);
  dest->v3.z = (float)(n * f) * (float)(1.0 / (float)(n - f));
  dest->v0.x = (float)(n * 2.0) * v11;
  dest->v2.x = v10 * v11;
  dest->v1.y = (float)(n * 2.0) * v9;
  dest->v2.z = (float)(1.0 / (float)(n - f)) * f;
}

// File Line: 960
// RVA: 0x182F80
void __fastcall UFG::qDecomposePerspective(float *fov_h, float *aspect, float *near_plane, float *far_plane, float *pan_x, float *pan_y, UFG::qMatrix44 *proj)
{
  float *v7; // rbp
  float *v8; // r14
  float *v9; // rsi
  float *v10; // rdi
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4

  v7 = far_plane;
  v8 = near_plane;
  v9 = aspect;
  v10 = fov_h;
  if ( proj->v0.x == 0.0 )
    v11 = 0.0;
  else
    v11 = atan2f(1.0, proj->v0.x) * 2.0;
  *v10 = v11;
  if ( proj->v0.x == 0.0 )
    v12 = 0.0;
  else
    v12 = proj->v1.y / proj->v0.x;
  *v9 = v12;
  v13 = proj->v2.z;
  v14 = proj->v3.z;
  v15 = proj->v2.w;
  v16 = proj->v3.w;
  if ( v13 != 0.0 && v13 != v15 )
  {
    *v8 = v14 / v13;
    *v7 = (float)(v14 - v16) / (float)(v13 - v15);
  }
  *(_DWORD *)pan_x = LODWORD(proj->v2.x) ^ _xmm[0];
  *(_DWORD *)pan_y = LODWORD(proj->v2.y) ^ _xmm[0];
}

// File Line: 969
// RVA: 0x188AA0
void __fastcall UFG::qOrthographicMatrix(UFG::qMatrix44 *dest, float width, float height, float near_plane, float far_plane)
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
  float v1; // xmm4_4
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm11_4
  float v6; // xmm9_4
  float v7; // xmm13_4
  float v8; // xmm5_4
  float v9; // xmm7_4
  float v10; // xmm11_4
  float v11; // xmm7_4
  float v12; // xmm14_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm15_4
  float v16; // xmm12_4
  float v17; // xmm10_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  float v27; // [rsp+B0h] [rbp+8h]

  v1 = m->v3.x;
  v2 = m->v0.w;
  v3 = m->v0.z;
  v4 = m->v0.y;
  v5 = m->v1.y;
  v6 = m->v3.y;
  v7 = m->v1.w;
  v8 = m->v1.z * v2;
  v9 = v5;
  v10 = v5 * v3;
  v11 = v9 * v2;
  v12 = m->v1.z * v4;
  v13 = m->v1.x * v2;
  v14 = v7 * v3;
  v15 = m->v3.z;
  v16 = m->v1.x * v3;
  v17 = m->v1.w * v4;
  v27 = m->v1.z * m->v0.x;
  v18 = m->v1.x * v4;
  v19 = m->v2.w;
  v20 = (float)((float)((float)((float)((float)(v8 * m->v2.y) * v1) - (float)((float)(v14 * m->v2.y) * v1))
                      - (float)((float)(v11 * m->v2.z) * v1))
              + (float)((float)(v17 * m->v2.z) * v1))
      + (float)((float)(v10 * v19) * v1);
  v21 = (float)(v12 * v19) * v1;
  v22 = m->v2.x;
  v23 = (float)((float)((float)(v20 - v21) - (float)((float)(v8 * v22) * v6)) + (float)((float)(v14 * v22) * v6))
      + (float)((float)(v13 * m->v2.z) * v6);
  v24 = m->v2.y;
  v25 = m->v3.w;
  return (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)(v23 - (float)((float)((float)(v7 * m->v0.x) * m->v2.z) * v6)) - (float)((float)(v16 * v19) * v6)) + (float)((float)(v27 * v19) * v6))
                                                                                               + (float)((float)(v11 * v22) * v15))
                                                                                       - (float)((float)(v17 * v22) * v15))
                                                                               - (float)((float)(v13 * v24) * v15))
                                                                       + (float)((float)((float)(v7 * m->v0.x) * v24)
                                                                               * v15))
                                                               + (float)((float)(v18 * v19) * v15))
                                                       - (float)((float)((float)(m->v1.y * m->v0.x) * v19) * v15))
                                               - (float)((float)(v10 * v22) * v25))
                                       + (float)((float)(v12 * v22) * v25))
                               + (float)((float)(v16 * v24) * v25))
                       - (float)((float)(v27 * v24) * v25))
               - (float)((float)(v18 * m->v2.z) * v25))
       + (float)((float)((float)(m->v1.y * m->v0.x) * m->v2.z) * v25);
}

// File Line: 1118
// RVA: 0x186740
void __fastcall UFG::qInverse(UFG::qMatrix44 *d, UFG::qMatrix44 *m)
{
  UFG::qMatrix44 *v2; // rdi
  UFG::qMatrix44 *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm10_4
  float v7; // xmm6_4
  float v8; // xmm15_4
  float v9; // xmm12_4
  float v10; // ST30_4
  float v11; // ST28_4
  float v12; // ST2C_4
  float v13; // ST38_4
  float v14; // xmm7_4
  float v15; // ST6C_4
  float v16; // ST48_4
  float v17; // ST5C_4
  float v18; // ST34_4
  float v19; // ST3C_4
  float v20; // ST20_4
  float v21; // ST24_4
  float v22; // ST40_4
  float v23; // ST58_4
  float v24; // ST60_4
  float v25; // ST7C_4
  float v26; // xmm11_4
  float v27; // ST74_4
  float v28; // xmm10_4
  float v29; // ST44_4
  float v30; // ST54_4
  float v31; // ST4C_4
  float v32; // xmm4_4
  float v33; // ST70_4
  float v34; // xmm7_4
  float v35; // ST68_4
  float v36; // ST34_4
  float v37; // xmm7_4
  float v38; // xmm9_4
  float v39; // xmm12_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  float v43; // xmm11_4
  float v44; // xmm0_4
  float v45; // [rsp+150h] [rbp+8h]
  float v46; // [rsp+158h] [rbp+10h]
  float v47; // [rsp+158h] [rbp+10h]
  float v48; // [rsp+160h] [rbp+18h]
  float v49; // [rsp+160h] [rbp+18h]
  float v50; // [rsp+168h] [rbp+20h]
  float v51; // [rsp+168h] [rbp+20h]

  v2 = d;
  v3 = m;
  v4 = UFG::qDeterminant(m);
  v5 = v3->v1.z;
  v6 = v3->v1.w;
  v7 = v3->v2.w * v5;
  v8 = v3->v0.z;
  v9 = v3->v0.w;
  v45 = 1.0 / v4;
  v10 = v3->v2.y;
  v46 = v3->v1.x;
  v11 = v3->v3.x;
  v12 = v3->v2.z;
  v50 = v3->v1.y;
  v13 = v3->v2.x;
  v14 = v12 * v6;
  v15 = v10 * v6;
  v48 = v3->v1.z;
  v16 = v3->v0.x;
  v17 = v3->v0.y;
  v18 = v3->v1.w;
  v19 = v3->v2.w;
  v20 = v3->v3.y;
  v21 = v3->v3.z;
  v22 = v3->v3.w;
  v23 = v10 * v5;
  v24 = v12 * v50;
  v2->v0.x = (float)((float)((float)((float)((float)((float)(v7 * v20) - (float)((float)(v12 * v6) * v20))
                                           + (float)((float)(v10 * v6) * v21))
                                   - (float)((float)(v19 * v50) * v21))
                           - (float)((float)(v10 * v5) * v22))
                   + (float)((float)(v12 * v50) * v22))
           * (float)(1.0 / v4);
  v25 = v10 * v9;
  v26 = v6 * v8;
  v27 = v18 * v17;
  v28 = v48 * v9;
  v29 = v50 * v8;
  v30 = v50 * v9;
  v31 = v48 * v17;
  v2->v0.y = (float)((float)((float)((float)((float)((float)((float)(v12 * v9) * v20) - (float)((float)(v19 * v8) * v20))
                                           - (float)((float)(v10 * v9) * v21))
                                   + (float)((float)(v19 * v17) * v21))
                           + (float)((float)(v10 * v8) * v22))
                   - (float)((float)(v12 * v17) * v22))
           * (float)(1.0 / v4);
  v2->v0.z = (float)((float)((float)((float)((float)((float)(v26 * v20) - (float)((float)(v48 * v9) * v20))
                                           + (float)((float)(v50 * v9) * v21))
                                   - (float)((float)(v18 * v17) * v21))
                           - (float)((float)(v50 * v8) * v22))
                   + (float)((float)(v48 * v17) * v22))
           * (float)(1.0 / v4);
  v32 = v13 * v18;
  v33 = v12 * v46;
  v34 = (float)((float)(v14 * v11) - (float)(v7 * v11)) - (float)((float)(v13 * v18) * v21);
  v2->v0.w = (float)((float)((float)((float)((float)((float)((float)(v48 * v9) * v10) - (float)(v26 * v10))
                                           - (float)((float)(v50 * v9) * v12))
                                   + (float)((float)(v18 * v17) * v12))
                           + (float)((float)(v50 * v8) * v19))
                   - (float)((float)(v48 * v17) * v19))
           * (float)(1.0 / v4);
  v35 = v13 * v48;
  v36 = v18 * v16;
  v2->v1.x = (float)((float)((float)(v34 + (float)((float)(v19 * v46) * v21)) + (float)((float)(v13 * v48) * v22))
                   - (float)((float)(v12 * v46) * v22))
           * (float)(1.0 / v4);
  v37 = v13 * v9;
  v2->v1.y = (float)((float)((float)((float)((float)((float)((float)(v19 * v8) * v11) - (float)((float)(v12 * v9) * v11))
                                           + (float)((float)(v13 * v9) * v21))
                                   - (float)((float)(v19 * v16) * v21))
                           - (float)((float)(v13 * v8) * v22))
                   + (float)((float)(v12 * v16) * v22))
           * (float)(1.0 / v4);
  v38 = v46 * v9;
  v39 = v46 * v8;
  v49 = v48 * v16;
  v2->v1.z = (float)((float)((float)((float)((float)((float)(v28 * v11) - (float)(v26 * v11)) - (float)(v38 * v21))
                                   + (float)(v36 * v21))
                           + (float)((float)(v46 * v8) * v22))
                   - (float)(v49 * v22))
           * (float)(1.0 / v4);
  v40 = v13 * v50;
  v2->v1.w = (float)((float)((float)((float)((float)((float)(v26 * v13) - (float)(v28 * v13)) + (float)(v38 * v12))
                                   - (float)(v36 * v12))
                           - (float)((float)(v46 * v8) * v19))
                   + (float)(v49 * v19))
           * (float)(1.0 / v4);
  v41 = v10 * v46;
  v2->v2.x = (float)((float)((float)((float)((float)((float)((float)(v19 * v50) * v11) - (float)(v15 * v11))
                                           + (float)(v32 * v20))
                                   - (float)((float)(v19 * v46) * v20))
                           - (float)((float)(v13 * v50) * v22))
                   + (float)((float)(v10 * v46) * v22))
           * (float)(1.0 / v4);
  v47 = v46 * v17;
  v42 = v50;
  v2->v2.y = (float)((float)((float)((float)((float)((float)(v25 * v11) - (float)((float)(v19 * v17) * v11))
                                           - (float)(v37 * v20))
                                   + (float)((float)(v19 * v16) * v20))
                           + (float)((float)(v13 * v17) * v22))
                   - (float)((float)(v10 * v16) * v22))
           * v45;
  v43 = v11;
  v51 = v50 * v16;
  v44 = v42 * v16;
  v2->v2.z = (float)((float)((float)((float)((float)((float)(v27 * v11) - (float)(v30 * v11)) + (float)(v38 * v20))
                                   - (float)(v36 * v20))
                           - (float)(v47 * v22))
                   + (float)(v44 * v22))
           * v45;
  v2->v2.w = (float)((float)((float)((float)((float)((float)(v30 * v13) - (float)(v27 * v13)) - (float)(v38 * v10))
                                   + (float)(v36 * v10))
                           + (float)(v47 * v19))
                   - (float)(v44 * v19))
           * v45;
  v2->v3.x = (float)((float)((float)((float)((float)((float)(v23 * v43) - (float)(v24 * v43)) - (float)(v35 * v20))
                                   + (float)(v33 * v20))
                           + (float)(v40 * v21))
                   - (float)(v41 * v21))
           * v45;
  v2->v3.y = (float)((float)((float)((float)((float)((float)((float)(v12 * v17) * v43) - (float)((float)(v10 * v8) * v43))
                                           + (float)((float)(v13 * v8) * v20))
                                   - (float)((float)(v12 * v16) * v20))
                           - (float)((float)(v13 * v17) * v21))
                   + (float)((float)(v10 * v16) * v21))
           * v45;
  v2->v3.w = (float)((float)((float)((float)((float)((float)(v31 * v13) - (float)(v29 * v13)) + (float)(v39 * v10))
                                   - (float)(v49 * v10))
                           - (float)(v47 * v12))
                   + (float)(v51 * v12))
           * v45;
  v2->v3.z = (float)((float)((float)((float)((float)((float)(v29 * v11) - (float)(v31 * v11)) - (float)(v39 * v20))
                                   + (float)(v49 * v20))
                           + (float)(v47 * v21))
                   - (float)(v51 * v21))
           * v45;
}

// File Line: 1145
// RVA: 0x18C620
void __fastcall UFG::qTranspose(UFG::qMatrix44 *dest, UFG::qMatrix44 *m)
{
  float v2; // eax
  float v3; // xmm3_4
  float v4; // xmm1_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm5_4

  v2 = m->v0.x;
  v3 = m->v1.x;
  v4 = m->v2.x;
  v5 = m->v1.y;
  v6 = m->v2.z;
  v7 = m->v3.w;
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
  dest->v0.x = v2;
  dest->v1.y = v5;
  dest->v2.x = v11;
  dest->v2.y = v9;
  dest->v2.z = v6;
  dest->v3.y = v12;
  dest->v3.z = v10;
  dest->v3.w = v7;
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
  float v2; // xmm1_4
  float v3; // xmm3_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm8_4
  float v7; // xmm7_4
  float v8; // xmm9_4
  float v9; // xmm4_4
  int v10; // xmm12_4
  int v11; // xmm10_4
  int v12; // xmm11_4
  float v13; // xmm0_4

  v2 = m->v0.x;
  v3 = m->v0.z;
  v4 = m->v1.x;
  v5 = m->v1.z;
  v6 = m->v2.x;
  v7 = m->v2.y;
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
  d->v2.x = v3;
  d->v0.z = v6;
  d->v1.z = v7;
  d->v2.y = v5;
  d->v2.z = v8;
  d->v0.y = v4;
  d->v3.z = (float)((float)(*(float *)&v10 * v7) + (float)(*(float *)&v12 * v6)) + (float)(*(float *)&v11 * v8);
  d->v3.y = (float)((float)(*(float *)&v10 * v9) + (float)(*(float *)&v12 * v4)) + (float)(*(float *)&v11 * v5);
  d->v1.y = v9;
  d->v3.x = (float)((float)(*(float *)&v10 * v13) + (float)(*(float *)&v12 * v2)) + (float)(*(float *)&v11 * v3);
}

// File Line: 1180
// RVA: 0x187750
void __fastcall UFG::qLookAtMatrix(UFG::qMatrix44 *dest, UFG::qVector3 *eye, UFG::qVector3 *target, UFG::qVector3 *up)
{
  __m128 v4; // xmm5
  float v5; // xmm4_4
  float v6; // xmm6_4
  __m128 v7; // xmm2
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm10_4
  float v11; // xmm9_4
  float v12; // xmm5_4
  __m128 v13; // xmm6
  float v14; // xmm8_4
  __m128 v15; // xmm2
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm9_4
  float v24; // xmm4_4

  v4 = (__m128)LODWORD(eye->x);
  v4.m128_f32[0] = v4.m128_f32[0] - target->x;
  v5 = eye->z - target->z;
  v7 = v4;
  v6 = eye->y - target->y;
  v7.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v6 * v6)) + (float)(v5 * v5);
  if ( v7.m128_f32[0] == 0.0 )
    v8 = 0.0;
  else
    v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v7));
  v9 = v5 * v8;
  v10 = v8 * v6;
  v13 = (__m128)LODWORD(up->z);
  v11 = v8 * v4.m128_f32[0];
  v12 = (float)(up->y * v9) - (float)(up->z * v10);
  v13.m128_f32[0] = (float)(v13.m128_f32[0] * v11) - (float)(up->x * v9);
  v14 = (float)(up->x * v10) - (float)(up->y * v11);
  v15 = v13;
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
  v17 = v12 * v16;
  v18 = v13.m128_f32[0] * v16;
  dest->v0.z = v11;
  dest->v1.z = v10;
  dest->v2.z = v9;
  dest->v0.w = 0.0;
  dest->v1.w = 0.0;
  dest->v2.w = 0.0;
  v19 = v14 * v16;
  dest->v0.x = v17;
  dest->v1.x = v18;
  dest->v2.x = v19;
  v20 = (float)(v19 * v10) - (float)(v9 * v18);
  dest->v0.y = v20;
  v21 = (float)(v9 * v17) - (float)(v19 * v11);
  dest->v1.y = v21;
  v22 = (float)(v18 * v11) - (float)(v10 * v17);
  dest->v2.y = v22;
  LODWORD(dest->v3.x) = COERCE_UNSIGNED_INT((float)((float)(v17 * eye->x) + (float)(v18 * eye->y)) + (float)(v19 * eye->z)) ^ _xmm[0];
  LODWORD(dest->v3.y) = COERCE_UNSIGNED_INT((float)((float)(v20 * eye->x) + (float)(v21 * eye->y)) + (float)(v22 * eye->z)) ^ _xmm[0];
  v23 = (float)(v11 * eye->x) + (float)(v10 * eye->y);
  v24 = v9 * eye->z;
  dest->v3.w = 1.0;
  LODWORD(dest->v3.z) = COERCE_UNSIGNED_INT(v23 + v24) ^ _xmm[0];
}

// File Line: 1205
// RVA: 0x18A810
void __fastcall UFG::qRotationMatrixX(UFG::qMatrix44 *dest, float radians)
{
  UFG::qMatrix44 *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm0_4

  v2 = dest;
  v3 = cosf(radians);
  v4 = sinf(radians);
  v2->v1.y = v3;
  v2->v2.z = v3;
  *(_QWORD *)&v2->v0.x = 1065353216i64;
  v2->v1.x = 0.0;
  v2->v3.w = 1.0;
  *(_QWORD *)&v2->v0.z = 0i64;
  v2->v1.z = v4;
  LODWORD(v2->v2.y) = LODWORD(v4) ^ _xmm[0];
  *(_QWORD *)&v2->v1.w = 0i64;
  *(_QWORD *)&v2->v2.w = 0i64;
  *(_QWORD *)&v2->v3.y = 0i64;
}

// File Line: 1216
// RVA: 0x18AA00
void __fastcall UFG::qRotationMatrixY(UFG::qMatrix44 *dest, float radians)
{
  UFG::qMatrix44 *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm0_4

  v2 = dest;
  v3 = cosf(radians);
  v4 = sinf(radians);
  v2->v0.x = v3;
  v2->v2.z = v3;
  *(_QWORD *)&v2->v1.y = 1065353216i64;
  v2->v0.y = 0.0;
  v2->v1.w = 0.0;
  v2->v2.y = 0.0;
  v2->v2.x = v4;
  *(_QWORD *)&v2->v0.w = 0i64;
  *(_QWORD *)&v2->v2.w = 0i64;
  *(_QWORD *)&v2->v3.y = 0i64;
  LODWORD(v2->v0.z) = LODWORD(v4) ^ _xmm[0];
  v2->v3.w = 1.0;
}

// File Line: 1227
// RVA: 0x18AA80
void __fastcall UFG::qRotationMatrixZ(UFG::qMatrix44 *dest, float radians)
{
  UFG::qMatrix44 *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm0_4

  v2 = dest;
  v3 = cosf(radians);
  v4 = sinf(radians);
  v2->v0.x = v3;
  v2->v1.y = v3;
  *(_QWORD *)&v2->v2.z = 1065353216i64;
  v2->v3.z = 0.0;
  v2->v3.w = 1.0;
  *(_QWORD *)&v2->v0.z = 0i64;
  v2->v0.y = v4;
  LODWORD(v2->v1.x) = LODWORD(v4) ^ _xmm[0];
  *(_QWORD *)&v2->v1.z = 0i64;
  *(_QWORD *)&v2->v2.x = 0i64;
  *(_QWORD *)&v2->v3.x = 0i64;
}

// File Line: 1238
// RVA: 0x18A890
void __fastcall UFG::qRotationMatrixXYZDepreciated(UFG::qMatrix44 *rot, UFG::qVector3 *radians)
{
  float v2; // xmm8_4
  UFG::qVector3 *v3; // rbx
  UFG::qMatrix44 *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm11_4
  float v8; // xmm10_4
  float v9; // xmm9_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm5_4

  v2 = radians->x;
  v3 = radians;
  v4 = rot;
  v5 = sinf(radians->x);
  v6 = v3->y;
  v7 = v5;
  v8 = sinf(v3->y);
  v9 = sinf(v3->z);
  v10 = cosf(v2);
  v11 = cosf(v6);
  v12 = cosf(v3->z);
  v4->v2.x = v8;
  v4->v0.w = 0.0;
  v4->v1.w = 0.0;
  v4->v2.w = 0.0;
  v4->v0.x = v12 * v11;
  v4->v0.y = (float)((float)(v8 * v7) * v12) + (float)(v9 * v10);
  v4->v0.z = (float)(v7 * v9) - (float)((float)(v8 * v10) * v12);
  v4->v2.z = v10 * v11;
  LODWORD(v4->v1.x) = COERCE_UNSIGNED_INT(v9 * v11) ^ _xmm[0];
  v4->v1.y = (float)(v10 * v12) - (float)((float)(v8 * v7) * v9);
  LODWORD(v4->v2.y) = COERCE_UNSIGNED_INT(v7 * v11) ^ _xmm[0];
  v4->v1.z = (float)((float)(v8 * v10) * v9) + (float)(v7 * v12);
}

// File Line: 1247
// RVA: 0x18A6A0
void __fastcall UFG::qRotationMatrixEuler(UFG::qMatrix44 *rot, UFG::qVector3 *angles)
{
  float v2; // xmm8_4
  UFG::qVector3 *v3; // rbx
  UFG::qMatrix44 *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm11_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm0_4

  v2 = angles->x;
  v3 = angles;
  v4 = rot;
  v5 = sinf(angles->x);
  v6 = v3->y;
  v7 = v5;
  v8 = sinf(v3->y);
  v9 = sinf(v3->z);
  v10 = cosf(v2);
  v11 = cosf(v6);
  v12 = cosf(v3->z);
  v4->v3.w = 1.0;
  v4->v0.y = v9 * v11;
  v4->v0.w = 0.0;
  v4->v1.w = 0.0;
  *(_QWORD *)&v4->v2.w = 0i64;
  v4->v0.x = v12 * v11;
  *(_QWORD *)&v4->v3.y = 0i64;
  LODWORD(v4->v0.z) = LODWORD(v8) ^ _xmm[0];
  v4->v1.x = (float)((float)(v7 * v8) * v12) - (float)(v10 * v9);
  v4->v1.y = (float)((float)(v7 * v8) * v9) + (float)(v10 * v12);
  v4->v1.z = v7 * v11;
  v4->v2.z = v10 * v11;
  v4->v2.x = (float)((float)(v10 * v8) * v12) + (float)(v7 * v9);
  v4->v2.y = (float)((float)(v10 * v8) * v9) - (float)(v7 * v12);
}

// File Line: 1258
// RVA: 0x18A530
void __fastcall UFG::qRotationMatrixAxis(UFG::qMatrix44 *dest, UFG::qVector3 *axis, float radians)
{
  UFG::qVector3 *v3; // rbx
  UFG::qMatrix44 *v4; // rdi
  float v5; // xmm11_4
  float v6; // xmm0_4
  float v7; // xmm9_4
  float v8; // xmm8_4
  float v9; // xmm4_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm8_4
  float v16; // xmm0_4
  float v17; // xmm6_4

  v3 = axis;
  v4 = dest;
  v5 = cosf(radians);
  v6 = sinf(radians);
  v7 = v3->z;
  v8 = v3->x;
  v9 = v3->y;
  v4->v0.w = 0.0;
  v4->v1.w = 0.0;
  *(_QWORD *)&v4->v2.w = 0i64;
  *(_QWORD *)&v4->v3.y = 0i64;
  v4->v3.w = 1.0;
  v10 = v8 * (float)(1.0 - v5);
  v11 = v9 * (float)(1.0 - v5);
  v12 = v10;
  v13 = v10 * v7;
  v14 = v12 * v9;
  v4->v0.x = (float)((float)(v8 * (float)(1.0 - v5)) * v8) + v5;
  v15 = v8 * v6;
  v4->v0.y = v14 - (float)(v7 * v6);
  v4->v1.x = (float)(v7 * v6) + v14;
  v4->v0.z = (float)(v9 * v6) + v13;
  v4->v2.x = v13 - (float)(v9 * v6);
  v16 = v11;
  v17 = v11 * v7;
  v4->v1.y = (float)(v16 * v9) + v5;
  v4->v1.z = v17 - v15;
  v4->v2.y = v15 + v17;
  v4->v2.z = (float)((float)(v7 * (float)(1.0 - v5)) * v7) + v5;
}

// File Line: 1277
// RVA: 0x182C10
char __fastcall UFG::qDecomposeAffineEuler(UFG::qVector3 *sol_a, UFG::qVector3 *sol_b, UFG::qMatrix44 *m, bool pos_bias)
{
  __m128 v4; // xmm4
  bool v5; // si
  UFG::qVector3 *v6; // rbx
  UFG::qVector3 *v7; // rdi
  __m128 v8; // xmm3
  float v9; // xmm11_4
  float v10; // xmm10_4
  __m128 v11; // xmm5
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

  v11 = (__m128)LODWORD(m->v0.y);
  v4 = (__m128)LODWORD(m->v1.y);
  v5 = pos_bias;
  v6 = sol_b;
  v7 = sol_a;
  v8 = (__m128)LODWORD(m->v2.y);
  v9 = m->v0.x;
  v10 = m->v1.x;
  v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v9 * v9))
                          + (float)(m->v0.z * m->v0.z))
                  + (float)(m->v0.w * m->v0.w);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v40 = v12 * v9;
  v13 = v12 * m->v0.y;
  v14 = v12 * m->v0.z;
  v39 = v13;
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v10 * v10))
                         + (float)(m->v1.z * m->v1.z))
                 + (float)(m->v1.w * m->v1.w);
  if ( v4.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v4));
  v16 = v15;
  v17 = v15 * m->v1.z;
  v18 = v16 * v10;
  v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(m->v2.x * m->v2.x))
                         + (float)(m->v2.z * m->v2.z))
                 + (float)(m->v2.w * m->v2.w);
  if ( v8.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
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
      v7->y = v30;
      v31 = UFG::qNormalizedAngleBiased(3.1415927 - v30, v5);
      v6->y = v31;
      v32 = cosf(v7->y);
      v33 = cosf(v31);
      v34 = atan2f((float)(1.0 / v32) * v17, (float)(1.0 / v32) * v21);
      v7->x = UFG::qNormalizedAngleBiased(v34, v5);
      v35 = atan2f((float)(1.0 / v33) * v17, (float)(1.0 / v33) * v21);
      v6->x = UFG::qNormalizedAngleBiased(v35, v5);
      v36 = atan2f((float)(1.0 / v32) * v39, (float)(1.0 / v32) * v40);
      v7->z = UFG::qNormalizedAngleBiased(v36, v5);
      v37 = atan2f((float)(1.0 / v33) * v39, (float)(1.0 / v33) * v40);
      v38 = UFG::qNormalizedAngleBiased(v37, v5);
      result = 0;
      v6->z = v38;
    }
    else
    {
      sol_a->y = -0.63661975;
      v28 = atan2f(COERCE_FLOAT(LODWORD(v18) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v22) ^ _xmm[0]));
      v29 = UFG::qNormalizedAngleBiased(v28, v5);
      result = 1;
      v7->x = v29;
      v6->x = v29;
      v6->y = -0.63661975;
      v6->z = 0.0;
    }
  }
  else
  {
    sol_a->y = 1.5707964;
    v24 = atan2f(v18, v22);
    v25 = UFG::qNormalizedAngleBiased(v24, v5);
    result = 1;
    v7->x = v25;
    v6->x = v25;
    *(_QWORD *)&v6->y = 1070141403i64;
  }
  return result;
}gleBiased(v24, v5);
    result = 1;
    v7->x = v25;
    v6->x = v25;
    *(_QWORD *)&v6->y = 1070141403i64;
  }
  r

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
char __fastcall UFG::qMakeMatrix(UFG::qMatrix44 *dest, UFG::qVector3 *forward, UFG::qVector3 *up, UFG::qVector3 *translation, const float threshold)
{
  float v5; // xmm11_4
  float v6; // xmm10_4
  float v7; // xmm9_4
  __m128 v8; // xmm13
  float v9; // xmm14_4
  float v10; // xmm8_4
  __m128 v11; // xmm12
  float v12; // xmm5_4
  __m128 v13; // xmm6
  float v14; // xmm7_4
  __m128 v15; // xmm4
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
  char result; // al

  v5 = forward->z;
  v6 = forward->y;
  v7 = forward->x;
  v8 = (__m128)LODWORD(up->y);
  v8.m128_f32[0] = (float)(v8.m128_f32[0] * v5) - (float)(up->z * v6);
  v11 = v8;
  v9 = (float)(forward->x * up->z) - (float)(up->x * v5);
  v10 = (float)(up->x * v6) - (float)(forward->x * up->y);
  v11.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] <= threshold )
    return 0;
  v13 = (__m128)LODWORD(forward->z);
  v15 = (__m128)LODWORD(forward->x);
  v12 = (float)(v6 * v10) - (float)(v5 * v9);
  v13.m128_f32[0] = (float)(v5 * v8.m128_f32[0]) - (float)(v7 * v10);
  v14 = (float)(v7 * v9) - (float)(v6 * v8.m128_f32[0]);
  v15.m128_f32[0] = (float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v5 * v5);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
  v17 = v7 * v16;
  v18 = v6 * v16;
  v19 = v5 * v16;
  if ( v11.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v21 = v8.m128_f32[0] * v20;
  v22 = v9 * v20;
  v23 = v10 * v20;
  v24 = v13;
  v24.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
  dest->v0.x = v17;
  dest->v0.y = v18;
  dest->v0.z = v19;
  dest->v0.w = 0.0;
  dest->v1.w = 0.0;
  dest->v1.x = v21;
  dest->v1.y = v22;
  dest->v1.z = v23;
  dest->v2.w = 0.0;
  dest->v2.y = v13.m128_f32[0] * v25;
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
UFG::qVector3 *__fastcall UFG::qGetScreenCoord(UFG::qVector3 *result, UFG::qVector3 *world_pos, UFG::qMatrix44 *world_view_projection, UFG::qVector2 *viewport_scale, bool *is_on_screen)
{
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm8_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  bool v28; // al
  UFG::qVector3 *v29; // rax
  float v30; // xmm0_4

  v5 = world_pos->x;
  v6 = world_pos->y;
  v7 = world_pos->z;
  v8 = v6;
  v9 = v6 * world_view_projection->v1.w;
  v10 = world_pos->y * world_view_projection->v1.z;
  v11 = (float)((float)((float)(v8 * world_view_projection->v1.x) + (float)(world_pos->x * world_view_projection->v0.x))
              + (float)(world_pos->z * world_view_projection->v2.x))
      + world_view_projection->v3.x;
  v12 = world_pos->z * world_view_projection->v2.y;
  v13 = (float)(world_pos->y * world_view_projection->v1.y) + (float)(world_pos->x * world_view_projection->v0.y);
  result->x = v11;
  v14 = v5 * world_view_projection->v0.z;
  v15 = v5 * world_view_projection->v0.w;
  v16 = v13 + v12;
  v17 = v7;
  v18 = v16 + world_view_projection->v3.y;
  v19 = v10 + v14;
  v20 = FLOAT_1_1920929eN7;
  v21 = v7 * world_view_projection->v2.w;
  v22 = v17 * world_view_projection->v2.z;
  result->y = v18;
  v23 = (float)(v19 + v22) + world_view_projection->v3.z;
  v24 = (float)((float)(v9 + v15) + v21) + world_view_projection->v3.w;
  result->z = v23;
  if ( v24 < 0.00000011920929 && v24 >= 0.0 || (v20 = FLOAT_N1_1920929eN7, v24 > -0.00000011920929) && v24 < 0.0 )
    v24 = v20;
  v25 = (float)(1.0 / v24) * v23;
  v26 = (float)(1.0 / v24) * v11;
  v27 = (float)(1.0 / v24) * v18;
  result->z = v25;
  result->x = v26;
  result->y = v27;
  if ( is_on_screen )
  {
    v28 = v26 > -1.0 && v26 < 1.0 && v27 > -1.0 && v27 < 1.0 && v25 > 0.0 && v25 < 1.0;
    *is_on_screen = v28;
  }
  v29 = result;
  v30 = (float)((float)(v27 - 1.0) * viewport_scale->y) * -0.5;
  result->x = (float)((float)(v26 + 1.0) * viewport_scale->x) * 0.5;
  result->y = v30;
  return v29;
}

