// File Line: 52
// RVA: 0xA55170
float __fastcall CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(CAkConversionTable<AkRTPCGraphPointBase<float>,float> *this, float in_valueToConvert, unsigned int in_index, unsigned int *out_index)
{
  unsigned int v4; // er10
  unsigned int *v5; // rsi
  __int64 v6; // rbx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v7; // rdi
  float v8; // xmm3_4
  AkRTPCGraphPointBase<float> *v9; // rdx
  AkRTPCGraphPointBase<float> *v10; // r8
  bool v11; // zf
  float v12; // xmm3_4
  float result; // xmm0_4
  AkCurveInterpolation v14; // ecx
  float v15; // xmm0_4
  signed int v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // [rsp+40h] [rbp+8h]

  v4 = this->m_ulArraySize;
  v5 = out_index;
  v6 = in_index;
  v7 = this;
  if ( v4 == 1 )
  {
    v8 = this->m_pArrayGraphPoints->To;
    goto LABEL_13;
  }
  if ( in_index >= v4 )
  {
LABEL_11:
    v8 = v20;
    goto LABEL_12;
  }
  v9 = this->m_pArrayGraphPoints;
  v10 = &this->m_pArrayGraphPoints[in_index];
  while ( 1 )
  {
    if ( in_valueToConvert <= v10->From )
    {
LABEL_23:
      v8 = v9[v6].To;
      goto LABEL_12;
    }
    v11 = (_DWORD)v6 == v4 - 1;
    if ( (unsigned int)v6 < v4 - 1 )
      break;
LABEL_9:
    if ( v11 )
      goto LABEL_23;
    v6 = (unsigned int)(v6 + 1);
    ++v10;
    if ( (unsigned int)v6 >= v4 )
      goto LABEL_11;
  }
  if ( in_valueToConvert >= v9[(unsigned int)(v6 + 1)].From )
  {
    v11 = (_DWORD)v6 == v4 - 1;
    goto LABEL_9;
  }
  v14 = v9[v6].Interp;
  if ( v14 == 4 )
  {
    v8 = (float)((float)((float)(in_valueToConvert - v9[v6].From)
                       / (float)(v9[(unsigned int)(v6 + 1)].From - v9[v6].From))
               * (float)(v9[(unsigned int)(v6 + 1)].To - v9[v6].To))
       + v9[v6].To;
  }
  else if ( v14 == 9 )
  {
    v8 = v9[v6].To;
  }
  else
  {
    v8 = AkInterpolation::InterpolateNoCheck(
           (float)(in_valueToConvert - v9[v6].From) / (float)(v9[(unsigned int)(v6 + 1)].From - v9[v6].From),
           v9[v6].To,
           v9[(unsigned int)(v6 + 1)].To,
           v14);
  }
LABEL_12:
  *v5 = v6;
LABEL_13:
  switch ( v7->m_eScaling )
  {
    case 2:
      if ( v8 >= 0.0 )
      {
        if ( v8 >= 1.0 )
        {
          result = FLOAT_4096_0;
        }
        else
        {
          v19 = (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(1.0 - v8) & 0x7FFFFF) + 1065353216) - 1.0)
              / (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(1.0 - v8) & 0x7FFFFF) + 1065353216) + 1.0);
          result = (float)((float)((float)((float)((float)((float)(v19 * v19) * 0.33333334) + 1.0) * (float)(v19 * 2.0))
                                 + (float)((float)((float)(unsigned __int8)(COERCE_UNSIGNED_INT(1.0 - v8) >> 23) - 127.0)
                                         * 0.69314718))
                         * -0.43429449)
                 * 20.0;
        }
      }
      else if ( v8 <= -1.0 )
      {
        result = FLOAT_N4096_0;
      }
      else
      {
        v18 = (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(v8 + 1.0) & 0x7FFFFF) + 1065353216) - 1.0)
            / (float)(COERCE_FLOAT((COERCE_UNSIGNED_INT(v8 + 1.0) & 0x7FFFFF) + 1065353216) + 1.0);
        result = (float)((float)((float)((float)((float)((float)(v18 * v18) * 0.33333334) + 1.0) * (float)(v18 * 2.0))
                               + (float)((float)((float)(unsigned __int8)(COERCE_UNSIGNED_INT(v8 + 1.0) >> 23) - 127.0)
                                       * 0.69314718))
                       * 0.43429449)
               * 20.0;
      }
      break;
    case 3:
      if ( v8 >= -37.0 )
      {
        if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
        {
          v17 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
        }
        else
        {
          v17 = FLOAT_2_7866352e7;
          `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
          `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
        }
        v16 = (signed int)(float)((float)(v17 * v8) + 1065353200.0);
        goto LABEL_34;
      }
LABEL_17:
      result = 0.0;
      break;
    case 4:
      v12 = v8 * 0.050000001;
      if ( v12 < -37.0 )
        goto LABEL_17;
      if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
      {
        v15 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      }
      else
      {
        v15 = FLOAT_2_7866352e7;
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
      }
      v16 = (signed int)(float)((float)(v12 * v15) + 1065353200.0);
LABEL_34:
      result = (float)((float)((float)((float)(COERCE_FLOAT((v16 & 0x7FFFFF) + 1065353216) * 0.32518977) + 0.020805772)
                             * COERCE_FLOAT((v16 & 0x7FFFFF) + 1065353216))
                     + 0.65304345)
             * COERCE_FLOAT(v16 & 0xFF800000);
      break;
    default:
      result = v8;
      break;
  }
  return result;
}

// File Line: 154
// RVA: 0xA57330
signed __int64 __fastcall CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(CAkConversionTable<AkRTPCGraphPointBase<float>,float> *this, AkRTPCGraphPointBase<float> *in_pArrayConversion, unsigned int in_ulConversionArraySize, AkCurveScaling in_eScaling)
{
  AkRTPCGraphPointBase<float> *v4; // rsi
  AkCurveScaling v5; // ebp
  __int64 v6; // rdi
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v7; // rbx
  AkRTPCGraphPointBase<float> *v8; // rcx
  signed __int64 result; // rax

  v4 = in_pArrayConversion;
  v5 = in_eScaling;
  v6 = in_ulConversionArraySize;
  v7 = this;
  if ( this->m_pArrayGraphPoints )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pArrayGraphPoints);
    v7->m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&v7->m_ulArraySize = 0i64;
  if ( !v4 || !(_DWORD)v6 )
    return 31i64;
  v8 = (AkRTPCGraphPointBase<float> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 12 * v6);
  v7->m_pArrayGraphPoints = v8;
  if ( v8 )
  {
    memmove(v8, v4, (unsigned int)(12 * v6));
    v7->m_ulArraySize = v6;
    v7->m_eScaling = v5;
    result = 1i64;
  }
  else
  {
    v7->m_ulArraySize = 0;
    result = 52i64;
  }
  return result;
}

// File Line: 181
// RVA: 0xA63980
void __fastcall CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Linearize(CAkConversionTable<AkRTPCGraphPointBase<float>,float> *this)
{
  AkCurveScaling v1; // eax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v2; // rdx
  signed __int64 v3; // r8
  signed __int64 v4; // rcx

  v1 = this->m_eScaling;
  v2 = this;
  if ( v1 )
  {
    if ( v1 == 2 )
    {
      v3 = 0i64;
      if ( this->m_ulArraySize )
      {
        do
        {
          v4 = v3;
          v3 = (unsigned int)(v3 + 1);
          v2->m_pArrayGraphPoints[v4].To = v2->m_pArrayGraphPoints[v4].To + 1.0;
        }
        while ( (unsigned int)v3 < v2->m_ulArraySize );
      }
      v2->m_eScaling = 0;
    }
  }
  else
  {
    this->m_eScaling = 4;
  }
}

