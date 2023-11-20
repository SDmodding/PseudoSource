// File Line: 75
// RVA: 0xFD3E0
float __fastcall UFG::FlashlightScore(UFG::qVector3 *vPosition, UFG::qVector3 *vDirection, UFG::FlashlightParams *params, UFG::qVector3 *vTargetPosition)
{
  __m128 v4; // xmm2
  UFG::FlashlightParams *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-48h]

  v4 = (__m128)LODWORD(vTargetPosition->y);
  v5 = params;
  v4.m128_f32[0] = v4.m128_f32[0] - vPosition->y;
  v6 = vTargetPosition->x - vPosition->x;
  v7 = vTargetPosition->z - vPosition->z;
  LODWORD(v2.y) = v4.m128_i32[0];
  v2.x = v6;
  v8 = *(float *)&FLOAT_1_0;
  v2.z = v7;
  v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v6 * v6)) + (float)(v7 * v7);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v4);
  if ( params->fAngleWeight < 1.0 )
  {
    if ( v9 <= params->fDeadDistance )
      return 0.0;
    v11 = params->fMinDistance;
    if ( v9 > v11 )
    {
      v8 = (float)(v9 - params->fMaxDistance) / (float)(v11 - params->fMaxDistance);
      if ( v8 <= 0.0 )
      {
        v8 = 0.0;
      }
      else if ( v8 >= 1.0 )
      {
        v8 = *(float *)&FLOAT_1_0;
      }
      if ( v8 <= 0.0 )
        return v8;
    }
    else
    {
      v8 = *(float *)&FLOAT_1_0;
    }
  }
  if ( params->fAngleWeight <= 0.0 )
    return v8;
  v12 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qAngleBetween(vDirection, &v2)) & _xmm) - params->fMaxRads)
      / (float)(params->fMinRads - params->fMaxRads);
  if ( v12 <= 0.0 )
  {
    v12 = 0.0;
  }
  else if ( v12 >= 1.0 )
  {
    v12 = *(float *)&FLOAT_1_0;
    return (float)((float)(1.0 - v5->fAngleWeight) * v8) + (float)(v5->fAngleWeight * v12);
  }
  if ( v12 > 0.0 )
    return (float)((float)(1.0 - v5->fAngleWeight) * v8) + (float)(v5->fAngleWeight * v12);
  return 0.0;
}

