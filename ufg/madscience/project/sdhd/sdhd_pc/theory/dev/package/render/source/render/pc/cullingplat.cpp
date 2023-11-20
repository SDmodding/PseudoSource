// File Line: 49
// RVA: 0x6A2CC0
signed __int64 __fastcall IntersectSphereFrustum(UFG::qVector4 *planes, UFG::qVector3 *pos, float radius)
{
  signed __int64 v3; // rax
  float *v4; // rcx

  v3 = 0i64;
  v4 = &planes->z;
  while ( (float)((float)((float)((float)(pos->y * *(v4 - 1)) + (float)(pos->x * *(v4 - 2))) + (float)(pos->z * *v4))
                + v4[1]) <= radius )
  {
    ++v3;
    v4 += 4;
    if ( v3 >= 6 )
      return 1i64;
  }
  return 2i64;
}

// File Line: 68
// RVA: 0x6A2B50
signed __int64 __fastcall IntersectAABBFrustum(UFG::qVector4 *planes, UFG::qVector3 *min, UFG::qVector3 *max, float *centre_distance_to_nearplan)
{
  __int64 v4; // r10
  unsigned int v5; // er11
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm9_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm10_4
  float v12; // xmm5_4
  float v13; // xmm8_4
  float v14; // xmm7_4
  float v15; // xmm11_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm0_4

  v4 = 0i64;
  v5 = 1;
  while ( 1 )
  {
    v6 = planes[v4].x;
    if ( v6 <= 0.0 )
    {
      v7 = max->x;
      v8 = min->x;
    }
    else
    {
      v7 = min->x;
      v8 = max->x;
    }
    v9 = planes[v4].y;
    if ( v9 <= 0.0 )
    {
      v10 = max->y;
      v11 = min->y;
    }
    else
    {
      v10 = min->y;
      v11 = max->y;
    }
    v12 = planes[v4].z;
    if ( v12 <= 0.0 )
    {
      v13 = max->z;
      v14 = min->z;
    }
    else
    {
      v13 = min->z;
      v14 = max->z;
    }
    v15 = planes[v4].w;
    v16 = (float)((float)((float)(v9 * v10) + (float)(v6 * v7)) + (float)(v12 * v13)) + v15;
    if ( v16 > 0.0 )
      break;
    v17 = (float)((float)((float)(v9 * v11) + (float)(v6 * v8)) + (float)(v12 * v14)) + v15;
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

