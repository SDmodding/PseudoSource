// File Line: 93
// RVA: 0xA9BA00
float __fastcall EvalLPFCutoff(float in_fCurrentLPFPar, bool in_bIsForFeedbackPipeline)
{
  float v4; // xmm1_4
  float v5; // xmm0_4

  if ( in_bIsForFeedbackPipeline )
  {
    v5 = (float)(unsigned __int16)(int)(float)((float)((float)(int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                     * 0.0009765625)
                                             * 8.0);
    return (float)(v5 * 0.5) - (float)((float)((float)((float)(v5 * 0.5) - 1.0) * 0.0099999998) * in_fCurrentLPFPar);
  }
  else if ( in_fCurrentLPFPar >= 30.0 )
  {
    if ( (`FastPowOfBeta::`2::`local static guard & 1) != 0 )
    {
      v4 = *(float *)&`FastPowOfBeta::`2::SCALE;
    }
    else
    {
      v4 = FLOAT_1042939_9;
      `FastPowOfBeta::`2::SCALE = LODWORD(FLOAT_1042939_9);
      `FastPowOfBeta::`2::`local static guard |= 1u;
    }
    return (float)((float)((float)((float)((float)(COERCE_FLOAT(
                                                     ((int)(float)((float)((float)(100.0 - in_fCurrentLPFPar) * v4)
                                                                 + 1065353200.0) & 0x7FFFFF)
                                                   + 1065353216)
                                                 * 0.32518977)
                                         + 0.020805772)
                                 * COERCE_FLOAT(
                                     ((int)(float)((float)((float)(100.0 - in_fCurrentLPFPar) * v4) + 1065353200.0) & 0x7FFFFF)
                                   + 1065353216))
                         + 0.65304345)
                 * COERCE_FLOAT((int)(float)((float)((float)(100.0 - in_fCurrentLPFPar) * v4) + 1065353200.0) & 0xFF800000))
         * 16.797443;
  }
  else
  {
    return (float)((float)(30.0 - in_fCurrentLPFPar) * 433.33334) + 7000.0;
  }
}

