// File Line: 49
// RVA: 0x6A2CC0
__int64 __fastcall IntersectSphereFrustum(UFG::qVector4 *planes, UFG::qVector3 *pos, float radius)
{
  __int64 v3; // rax
  float *i; // rcx

  v3 = 0i64;
  for ( i = &planes->z;
        (float)((float)((float)((float)(pos->y * *(i - 1)) + (float)(pos->x * *(i - 2))) + (float)(pos->z * *i)) + i[1]) <= radius;
        i += 4 )
  {
    if ( ++v3 >= 6 )
      return 1i64;
  }
  return 2i64;
}

// File Line: 68
// RVA: 0x6A2B50
signed __int64 __fastcall IntersectAABBFrustum(
        UFG::qVector4 *planes,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        float *centre_distance_to_nearplan)
{
  __int64 v4; // r10
  unsigned int v5; // r11d
  float x; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm9_4
  float y; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm10_4
  float z; // xmm5_4
  float v13; // xmm8_4
  float v14; // xmm7_4
  float w; // xmm11_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm0_4

  v4 = 0i64;
  v5 = 1;
  while ( 1 )
  {
    x = planes[v4].x;
    if ( x <= 0.0 )
    {
      v7 = max->x;
      v8 = min->x;
    }
    else
    {
      v7 = min->x;
      v8 = max->x;
    }
    y = planes[v4].y;
    if ( y <= 0.0 )
    {
      v10 = max->y;
      v11 = min->y;
    }
    else
    {
      v10 = min->y;
      v11 = max->y;
    }
    z = planes[v4].z;
    if ( z <= 0.0 )
    {
      v13 = max->z;
      v14 = min->z;
    }
    else
    {
      v13 = min->z;
      v14 = max->z;
    }
    w = planes[v4].w;
    v16 = (float)((float)((float)(y * v10) + (float)(x * v7)) + (float)(z * v13)) + w;
    if ( v16 > 0.0 )
      break;
    v17 = (float)((float)((float)(y * v11) + (float)(x * v8)) + (float)(z * v14)) + w;
    if ( v4 )
      v18 = *centre_distance_to_nearplan;
    else
      v18 = (float)(v17 + v16) * -0.5;
    *centre_distance_to_nearplan = v18;
    if ( v17 >= 0.0 )
      v5 = 0;
    if ( ++v4 >= 6 )
      return v5;
  }
  return 2i64;
}

