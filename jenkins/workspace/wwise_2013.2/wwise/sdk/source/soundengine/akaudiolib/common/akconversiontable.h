// File Line: 52
// RVA: 0xA55170
float __fastcall CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
        CAkConversionTable<AkRTPCGraphPointBase<float>,float> *this,
        float in_valueToConvert,
        unsigned int in_index,
        unsigned int *out_index)
{
  unsigned int m_ulArraySize; // r10d
  __int64 v6; // rbx
  float To; // xmm3_4
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx
  AkRTPCGraphPointBase<float> *v10; // r8
  bool v11; // zf
  float v12; // xmm3_4
  AkCurveInterpolation Interp; // ecx
  float v15; // xmm0_4
  int v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // [rsp+40h] [rbp+8h]

  m_ulArraySize = this->m_ulArraySize;
  v6 = in_index;
  if ( m_ulArraySize == 1 )
  {
    To = this->m_pArrayGraphPoints->To;
    goto LABEL_13;
  }
  if ( in_index >= m_ulArraySize )
  {
LABEL_11:
    To = v20;
    goto LABEL_12;
  }
  m_pArrayGraphPoints = this->m_pArrayGraphPoints;
  v10 = &this->m_pArrayGraphPoints[in_index];
  while ( 1 )
  {
    if ( in_valueToConvert <= v10->From )
    {
LABEL_23:
      To = m_pArrayGraphPoints[v6].To;
      goto LABEL_12;
    }
    v11 = (_DWORD)v6 == m_ulArraySize - 1;
    if ( (unsigned int)v6 < m_ulArraySize - 1 )
      break;
LABEL_9:
    if ( v11 )
      goto LABEL_23;
    v6 = (unsigned int)(v6 + 1);
    ++v10;
    if ( (unsigned int)v6 >= m_ulArraySize )
      goto LABEL_11;
  }
  if ( in_valueToConvert >= m_pArrayGraphPoints[(unsigned int)(v6 + 1)].From )
  {
    v11 = (_DWORD)v6 == m_ulArraySize - 1;
    goto LABEL_9;
  }
  Interp = m_pArrayGraphPoints[v6].Interp;
  if ( Interp == AkCurveInterpolation_Linear )
  {
    To = (float)((float)((float)(in_valueToConvert - m_pArrayGraphPoints[v6].From)
                       / (float)(m_pArrayGraphPoints[(unsigned int)(v6 + 1)].From - m_pArrayGraphPoints[v6].From))
               * (float)(m_pArrayGraphPoints[(unsigned int)(v6 + 1)].To - m_pArrayGraphPoints[v6].To))
       + m_pArrayGraphPoints[v6].To;
  }
  else if ( Interp == AkCurveInterpolation_Constant )
  {
    To = m_pArrayGraphPoints[v6].To;
  }
  else
  {
    To = AkInterpolation::InterpolateNoCheck(
           (float)(in_valueToConvert - m_pArrayGraphPoints[v6].From)
         / (float)(m_pArrayGraphPoints[(unsigned int)(v6 + 1)].From - m_pArrayGraphPoints[v6].From),
           m_pArrayGraphPoints[v6].To,
           m_pArrayGraphPoints[(unsigned int)(v6 + 1)].To,
           Interp);
  }
LABEL_12:
  *out_index = v6;
LABEL_13:
  switch ( this->m_eScaling )
  {
    case AkCurveScaling_dB:
      if ( To >= 0.0 )
      {
        if ( To >= 1.0 )
        {
          return FLOAT_4096_0;
        }
        else
        {
          v19 = (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(1.0 - To) & 0x7FFFFF) + 1065353216) - 1.0)
              / (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(1.0 - To) & 0x7FFFFF) + 1065353216) + 1.0);
          return (float)((float)((float)((float)((float)((float)(v19 * v19) * 0.33333334) + 1.0) * (float)(v19 * 2.0))
                               + (float)((float)((float)(unsigned __int8)(COERCE_UNSIGNED_INT(1.0 - To) >> 23) - 127.0)
                                       * 0.69314718))
                       * -0.43429449)
               * 20.0;
        }
      }
      else if ( To <= -1.0 )
      {
        return FLOAT_N4096_0;
      }
      else
      {
        v18 = (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(To + 1.0) & 0x7FFFFF) + 1065353216) - 1.0)
            / (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(To + 1.0) & 0x7FFFFF) + 1065353216) + 1.0);
        return (float)((float)((float)((float)((float)((float)(v18 * v18) * 0.33333334) + 1.0) * (float)(v18 * 2.0))
                             + (float)((float)((float)(unsigned __int8)(COERCE_UNSIGNED_INT(To + 1.0) >> 23) - 127.0)
                                     * 0.69314718))
                     * 0.43429449)
             * 20.0;
      }
    case AkCurveScaling_Log:
      if ( To >= -37.0 )
      {
        if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
        {
          v17 = *(float *)&`AkMath::FastPow10::`4::SCALE;
        }
        else
        {
          v17 = FLOAT_2_7866352e7;
          `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
          `AkMath::FastPow10::`4::`local static guard |= 1u;
        }
        v16 = (int)(float)((float)(v17 * To) + 1065353200.0);
        return (float)((float)((float)((float)(COERCE_FLOAT((v16 & 0x7FFFFF) + 1065353216) * 0.32518977) + 0.020805772)
                             * COERCE_FLOAT((v16 & 0x7FFFFF) + 1065353216))
                     + 0.65304345)
             * COERCE_FLOAT(v16 & 0xFF800000);
      }
      return 0.0;
    case AkCurveScaling_dBToLin:
      v12 = To * 0.050000001;
      if ( v12 < -37.0 )
        return 0.0;
      if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
      {
        v15 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v15 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10::`4::`local static guard |= 1u;
      }
      v16 = (int)(float)((float)(v12 * v15) + 1065353200.0);
      return (float)((float)((float)((float)(COERCE_FLOAT((v16 & 0x7FFFFF) + 1065353216) * 0.32518977) + 0.020805772)
                           * COERCE_FLOAT((v16 & 0x7FFFFF) + 1065353216))
                   + 0.65304345)
           * COERCE_FLOAT(v16 & 0xFF800000);
    default:
      return To;
  }
}

// File Line: 154
// RVA: 0xA57330
__int64 __fastcall CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
        CAkConversionTable<AkRTPCGraphPointBase<float>,float> *this,
        AkRTPCGraphPointBase<float> *in_pArrayConversion,
        unsigned int in_ulConversionArraySize,
        AkCurveScaling in_eScaling)
{
  __int64 v6; // rdi
  AkRTPCGraphPointBase<float> *v8; // rcx

  v6 = in_ulConversionArraySize;
  if ( this->m_pArrayGraphPoints )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pArrayGraphPoints);
    this->m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&this->m_ulArraySize = 0i64;
  if ( !in_pArrayConversion || !(_DWORD)v6 )
    return 31i64;
  v8 = (AkRTPCGraphPointBase<float> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 12 * v6);
  this->m_pArrayGraphPoints = v8;
  if ( v8 )
  {
    memmove(v8, in_pArrayConversion, (unsigned int)(12 * v6));
    this->m_ulArraySize = v6;
    this->m_eScaling = in_eScaling;
    return 1i64;
  }
  else
  {
    this->m_ulArraySize = 0;
    return 52i64;
  }
}

// File Line: 181
// RVA: 0xA63980
void __fastcall CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Linearize(
        CAkConversionTable<AkRTPCGraphPointBase<float>,float> *this)
{
  AkCurveScaling m_eScaling; // eax
  __int64 i; // r8
  __int64 v4; // rcx

  m_eScaling = this->m_eScaling;
  if ( m_eScaling )
  {
    if ( m_eScaling == AkCurveScaling_dB )
    {
      for ( i = 0i64;
            (unsigned int)i < this->m_ulArraySize;
            this->m_pArrayGraphPoints[v4].To = this->m_pArrayGraphPoints[v4].To + 1.0 )
      {
        v4 = i;
        i = (unsigned int)(i + 1);
      }
      this->m_eScaling = AkCurveScaling_None;
    }
  }
  else
  {
    this->m_eScaling = AkCurveScaling_dBToLin;
  }
}

