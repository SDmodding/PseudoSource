// File Line: 46
// RVA: 0xA83EE0
float __fastcall CAkVPLSrcNode::GetPitch(CAkVPLSrcNode *this)
{
  return this->m_pCtx->m_EffectiveParams.Pitch;
}

// File Line: 122
// RVA: 0xA667F0
float __fastcall CAkVPLSrcNode::GetMakeupGain(CAkVPLSrcNode *this)
{
  CAkPBI *v1; // rdx
  float v2; // xmm1_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  AkFileParser::AnalysisData *v5; // rax

  v1 = this->m_pCtx;
  v2 = v1->m_EffectiveParams.normalization.fMakeUpGain * 0.050000001;
  if ( v2 >= -37.0 )
  {
    if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
    {
      v4 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
    }
    else
    {
      v4 = FLOAT_2_7866352e7;
      `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
    }
    v3 = (float)((float)((float)((float)(COERCE_FLOAT(
                                           ((signed int)(float)((float)(v4 * v2) + 1065353200.0) & 0x7FFFFF)
                                         + 1065353216)
                                       * 0.32518977)
                               + 0.020805772)
                       * COERCE_FLOAT(((signed int)(float)((float)(v4 * v2) + 1065353200.0) & 0x7FFFFF) + 1065353216))
               + 0.65304345)
       * COERCE_FLOAT((signed int)(float)((float)(v4 * v2) + 1065353200.0) & 0xFF800000);
  }
  else
  {
    v3 = 0.0;
  }
  v5 = this->m_pAnalysisData;
  if ( v5 )
  {
    v3 = v3 * v5->fDownmixNormalizationGain;
    if ( *((_BYTE *)&v1->m_EffectiveParams.normalization + 4) & 1 )
      v3 = v3 * v5->fLoudnessNormalizationGain;
  }
  return v3;
}

