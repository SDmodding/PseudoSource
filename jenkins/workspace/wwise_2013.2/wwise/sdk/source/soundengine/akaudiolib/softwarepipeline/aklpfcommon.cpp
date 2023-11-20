// File Line: 93
// RVA: 0xA9BA00
float __fastcall EvalLPFCutoff(float in_fCurrentLPFPar, bool in_bIsForFeedbackPipeline)
{
  float v2; // xmm2_4
  float result; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4

  v2 = in_fCurrentLPFPar;
  if ( in_bIsForFeedbackPipeline )
  {
    v5 = (float)(unsigned __int16)(signed int)(float)((float)((float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                            * 0.0009765625)
                                                    * 8.0);
    result = (float)(v5 * 0.5) - (float)((float)((float)((float)(v5 * 0.5) - 1.0) * 0.0099999998) * v2);
  }
  else if ( in_fCurrentLPFPar >= 30.0 )
  {
    if ( `FastPowOfBeta::`2::`local static guard & 1 )
    {
      v4 = *(float *)&`FastPowOfBeta::`2::SCALE;
    }
    else
    {
      v4 = FLOAT_1042939_9;
      `FastPowOfBeta::`2::SCALE = LODWORD(FLOAT_1042939_9);
      `FastPowOfBeta::`2::`local static guard |= 1u;
    }
    result = (float)((float)((float)((float)((float)(COERCE_FLOAT(
                                                       ((signed int)(float)((float)((float)(100.0 - in_fCurrentLPFPar)
                                                                                  * v4)
                                                                          + 1065353200.0) & 0x7FFFFF)
                                                     + 1065353216)
                                                   * 0.32518977)
                                           + 0.020805772)
                                   * COERCE_FLOAT(
                                       ((signed int)(float)((float)((float)(100.0 - in_fCurrentLPFPar) * v4)
                                                          + 1065353200.0) & 0x7FFFFF)
                                     + 1065353216))
                           + 0.65304345)
                   * COERCE_FLOAT((signed int)(float)((float)((float)(100.0 - in_fCurrentLPFPar) * v4) + 1065353200.0) & 0xFF800000))
           * 16.797443;
  }
  else
  {
    result = (float)((float)(30.0 - in_fCurrentLPFPar) * 433.33334) + 7000.0;
  }
  return result;
}

