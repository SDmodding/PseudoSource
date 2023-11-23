// File Line: 7
// RVA: 0x69C0C0
float __fastcall UFG::qSignedAngleBetween(UFG::qVector3 *a, UFG::qVector3 *b)
{
  float v2; // xmm6_4
  float result; // xmm0_4

  v2 = (float)(b->y * a->x) - (float)(a->y * b->x);
  result = UFG::qAngleBetween(a, b);
  if ( v2 < 0.0 )
    LODWORD(result) ^= _xmm[0];
  return result;
}

// File Line: 17
// RVA: 0x67B2A0
float __fastcall UFG::GetSpeedLimitForCurvature(float curvature, float top_speed, float road_holding)
{
  float result; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4

  result = 0.0;
  if ( top_speed > 0.0 )
  {
    v5 = road_holding * 9.8000002;
    LODWORD(v6) = LODWORD(curvature) & _xmm;
    v7 = v5 / (float)(top_speed * top_speed);
    if ( v7 <= v6 )
      v7 = v6;
    return fsqrt(v5 / v7);
  }
  return result;
}

// File Line: 46
// RVA: 0x679C60
float __fastcall UFG::GetBrakingSpeedLimit(float distance, float top_speed, float vehicle_mass, bool is_boat)
{
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float result; // xmm0_4

  if ( is_boat )
    v6 = UFG::AiDriverComponent::m_fBoatMaxBrakingForce;
  else
    v6 = UFG::AiDriverComponent::m_fMaxBrakingForce;
  v7 = 0.0;
  if ( distance >= 0.0 )
    v7 = distance;
  v8 = FLOAT_100_0;
  if ( vehicle_mass >= 100.0 )
    v8 = vehicle_mass;
  result = fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(v6 / v8) & _xmm) * (float)(v7 * 2.0));
  if ( top_speed < result )
    return top_speed;
  return result;
}

// File Line: 57
// RVA: 0x674650
float __fastcall UFG::ClosingTime(
        UFG::qVector3 *p0,
        UFG::qVector3 *v0,
        UFG::qVector3 *p1,
        UFG::qVector3 *v1,
        float *closing_speed)
{
  float v5; // xmm5_4
  __m128 y_low; // xmm3
  float v7; // xmm7_4
  __m128 v8; // xmm2
  float v9; // xmm6_4
  float v10; // xmm8_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  __m128 v13; // xmm2
  unsigned int v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm0_4

  y_low = (__m128)LODWORD(v0->y);
  v8 = (__m128)LODWORD(p1->y);
  v5 = v0->x - v1->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - v1->y;
  v7 = p1->x - p0->x;
  v8.m128_f32[0] = v8.m128_f32[0] - p0->y;
  v9 = v0->z - v1->z;
  v10 = p1->z - p0->z;
  v11 = (float)((float)(y_low.m128_f32[0] * v8.m128_f32[0]) + (float)(v5 * v7)) + (float)(v9 * v10);
  if ( closing_speed )
  {
    v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v10 * v10);
    v12 = _mm_sqrt_ps(v8).m128_f32[0];
    if ( v12 >= 0.00000011920929 )
    {
      v14 = COERCE_UNSIGNED_INT(v11 / v12) ^ _xmm[0];
    }
    else
    {
      v13 = y_low;
      v13.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v9 * v9);
      v14 = _mm_sqrt_ps(v13).m128_u32[0];
    }
    *(_DWORD *)closing_speed = v14;
  }
  v15 = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v9 * v9);
  if ( v15 <= (float)(COERCE_FLOAT(LODWORD(v11) & _xmm) * 0.001) )
    v15 = COERCE_FLOAT(LODWORD(v11) & _xmm) * 0.001;
  if ( v15 >= 0.00000011920929 )
    return v11 / v15;
  v16 = 0.0;
  if ( v11 > 0.0 )
    return 1.0 * 1000.0;
  if ( v11 < 0.0 )
    v16 = FLOAT_N1_0;
  return v16 * 1000.0;
}

// File Line: 77
// RVA: 0x68C060
float __fastcall UFG::SoonestCloserThan(
        UFG::qVector3 *p0,
        UFG::qVector3 *v0,
        UFG::qVector3 *p1,
        UFG::qVector3 *v1,
        float distance,
        float *closing_speed)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  __m128 v10; // xmm8
  __m128 v11; // xmm7
  __m128 y_low; // xmm6
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  __m128 v17; // xmm3
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm2_4

  v6 = v1->z - v0->z;
  v7 = v1->x - v0->x;
  v8 = p1->z - p0->z;
  y_low = (__m128)LODWORD(v1->y);
  v10 = (__m128)LODWORD(p1->y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - v0->y;
  v10.m128_f32[0] = v10.m128_f32[0] - p0->y;
  v9 = p1->x - p0->x;
  v11 = y_low;
  v11.m128_f32[0] = y_low.m128_f32[0] * y_low.m128_f32[0];
  y_low.m128_f32[0] = y_low.m128_f32[0] * v10.m128_f32[0];
  v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v8 * v8);
  v11.m128_f32[0] = (float)(v11.m128_f32[0] + (float)(v7 * v7)) + (float)(v6 * v6);
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] + (float)(v7 * v9)) + (float)(v6 * v8)) * 2.0;
  v13 = v10.m128_f32[0] - (float)(distance * distance);
  if ( closing_speed )
  {
    v14 = _mm_sqrt_ps(v10).m128_f32[0] * 2.0;
    if ( v14 >= 0.00000011920929 )
      v15 = y_low.m128_f32[0] / v14;
    else
      LODWORD(v15) = _mm_sqrt_ps(v11).m128_u32[0];
    *closing_speed = v15;
  }
  v16 = 0.0;
  if ( v13 >= 0.0 )
  {
    v17 = y_low;
    v17.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) - (float)((float)(v11.m128_f32[0] * 4.0) * v13);
    if ( v17.m128_f32[0] >= 0.0 )
    {
      v18 = v11.m128_f32[0] * 2.0;
      v19 = COERCE_FLOAT(y_low.m128_i32[0] ^ _xmm[0]) - _mm_sqrt_ps(v17).m128_f32[0];
      if ( v18 <= (float)(COERCE_FLOAT(LODWORD(v19) & _xmm) * 0.001) )
        v18 = COERCE_FLOAT(LODWORD(v19) & _xmm) * 0.001;
      if ( v18 >= 0.00000011920929 )
      {
        v20 = v19 / v18;
      }
      else if ( y_low.m128_f32[0] <= 0.0 )
      {
        if ( y_low.m128_f32[0] >= 0.0 )
          v20 = 0.0 * -1000.0;
        else
          v20 = -1.0 * -1000.0;
      }
      else
      {
        v20 = 1.0 * -1000.0;
      }
      if ( v20 >= 0.0 )
        return v20;
    }
    else if ( y_low.m128_f32[0] <= 0.0 )
    {
      if ( y_low.m128_f32[0] < 0.0 )
        v16 = FLOAT_N1_0;
      return v16 * -1000.0;
    }
    else
    {
      return 1.0 * -1000.0;
    }
  }
  return v16;
}

