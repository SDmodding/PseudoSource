// File Line: 157
// RVA: 0xA68050
float __fastcall CAkListener::ComputeConeAttenuation(float in_fInsideAngle, float in_fOutsideAngle, float in_fConeOutsideVolume, float in_fAngle, float *out_fCone)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v8; // xmm0_4

  v5 = AkMath::Interpolate(in_fInsideAngle, 0.0, in_fOutsideAngle, 1.0, in_fAngle);
  *out_fCone = v5;
  v6 = (float)(v5 * in_fConeOutsideVolume) * 0.050000001;
  if ( v6 < -37.0 )
    return 0.0;
  if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
  {
    v8 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
  }
  else
  {
    v8 = FLOAT_2_7866352e7;
    `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
    `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
  }
  return (float)((float)((float)((float)(COERCE_FLOAT(
                                           ((signed int)(float)((float)(v6 * v8) + 1065353200.0) & 0x7FFFFF)
                                         + 1065353216)
                                       * 0.32518977)
                               + 0.020805772)
                       * COERCE_FLOAT(((signed int)(float)((float)(v6 * v8) + 1065353200.0) & 0x7FFFFF) + 1065353216))
               + 0.65304345)
       * COERCE_FLOAT((signed int)(float)((float)(v6 * v8) + 1065353200.0) & 0xFF800000);
}

