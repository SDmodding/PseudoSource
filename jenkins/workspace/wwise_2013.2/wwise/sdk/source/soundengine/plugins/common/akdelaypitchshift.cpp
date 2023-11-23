// File Line: 32
// RVA: 0xAEB720
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall AK::DSP::AkDelayPitchShift::Init(
        AK::DSP::AkDelayPitchShift *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        double in_MaxDelayTime,
        unsigned int in_uNumChannels,
        signed int in_uSampleRate)
{
  int v7; // ecx
  int v8; // esi
  unsigned int m_uDelayLength; // ecx
  AK::DSP::CAkDelayLineMemory<float,1> *v10; // rdi
  int v11; // ebx
  float *v12; // rax

  *(float *)&in_MaxDelayTime = (float)(*(float *)&in_MaxDelayTime * 0.001) * (float)in_uSampleRate;
  v7 = (int)*(float *)&in_MaxDelayTime;
  if ( (int)*(float *)&in_MaxDelayTime != 0x80000000 && (float)v7 != *(float *)&in_MaxDelayTime )
    *(float *)&in_MaxDelayTime = (float)(v7
                                       - (_mm_movemask_ps(_mm_unpacklo_ps(*(__m128 *)&in_MaxDelayTime, *(__m128 *)&in_MaxDelayTime)) & 1));
  this->m_uNumChannels = in_uNumChannels;
  this->m_fReadWriteRateDelta = 0.0;
  v8 = 0;
  this->m_uDelayLength = ((int)*(float *)&in_MaxDelayTime + 3) & 0xFFFFFFFC;
  if ( !in_uNumChannels )
    return 1i64;
  while ( 1 )
  {
    this->m_fFractDelay[v8] = 0.0;
    m_uDelayLength = this->m_uDelayLength;
    if ( m_uDelayLength )
    {
      v10 = &this->m_DelayLines[v8];
      v10->m_uNumChannels = 1;
      *(_QWORD *)&v10->m_uDelayLineLength = (m_uDelayLength + 3) & 0xFFFFFFFC;
      if ( ((m_uDelayLength + 3) & 0xFFFFFFFC) != 0 )
        break;
    }
LABEL_10:
    if ( ++v8 >= this->m_uNumChannels )
      return 1i64;
  }
  v11 = 0;
  while ( 1 )
  {
    v12 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * v10->m_uDelayLineLength);
    v10->m_pDelay[v11] = v12;
    if ( !v12 )
      return 52i64;
    if ( ++v11 >= v10->m_uNumChannels )
      goto LABEL_10;
  }
}

// File Line: 53
// RVA: 0xAEB850
void __fastcall AK::DSP::AkDelayPitchShift::Term(
        AK::DSP::AkDelayPitchShift *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int i; // ebp
  unsigned int v5; // ebx
  AK::DSP::CAkDelayLineMemory<float,1> *v6; // rdi
  char *v7; // rsi

  for ( i = 0; i < this->m_uNumChannels; v6->m_uDelayLineLength = 0 )
  {
    v5 = 0;
    v6 = &this->m_DelayLines[i];
    if ( v6->m_uNumChannels )
    {
      do
      {
        v7 = (char *)&v6->m_pDelay[v5];
        if ( *(_QWORD *)v7 )
        {
          ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
          *(_QWORD *)v7 = 0i64;
        }
        ++v5;
      }
      while ( v5 < v6->m_uNumChannels );
    }
    ++i;
  }
}

// File Line: 61
// RVA: 0xAEB910
void __fastcall AK::DSP::AkDelayPitchShift::Reset(AK::DSP::AkDelayPitchShift *this)
{
  unsigned int i; // esi
  AK::DSP::CAkDelayLineMemory<float,1> *v3; // rdi
  unsigned int j; // ebx
  float *v5; // rcx

  for ( i = 0; i < this->m_uNumChannels; v3->m_uOffset = 0 )
  {
    v3 = &this->m_DelayLines[i];
    if ( v3->m_uDelayLineLength )
    {
      for ( j = 0; j < v3->m_uNumChannels; ++j )
      {
        v5 = v3->m_pDelay[j];
        if ( v5 )
          memset(v5, 0, 4 * v3->m_uDelayLineLength);
      }
    }
    ++i;
  }
}

// File Line: 70
// RVA: 0xAEB9B0
void __fastcall AK::DSP::AkDelayPitchShift::SetPitchFactor(AK::DSP::AkDelayPitchShift *this, float in_fPitchFactor)
{
  unsigned int i; // ecx
  __int64 v4; // rax

  if ( in_fPitchFactor == 1.0 )
  {
    this->m_fReadWriteRateDelta = 0.0;
    for ( i = 0; i < this->m_uNumChannels; this->m_fFractDelay[v4] = 0.0 )
      v4 = i++;
  }
  else
  {
    this->m_fReadWriteRateDelta = 1.0 - in_fPitchFactor;
  }
}

// File Line: 552
// RVA: 0xAEBA00
void __fastcall AK::DSP::AkDelayPitchShift::ProcessChannel(
        AK::DSP::AkDelayPitchShift *this,
        float *in_pfInBuf,
        float *out_pfOutBuf,
        unsigned int in_uNumFrames,
        unsigned int in_uChanIndex)
{
  signed int m_uDelayLength; // r10d
  float m_fReadWriteRateDelta; // xmm10_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  unsigned int v9; // edi
  float v13; // xmm9_4
  int m_uOffset; // r11d
  float *v15; // rsi
  unsigned int v16; // ebx
  __int64 v17; // rbp
  float v18; // xmm2_4
  __m128 v19; // xmm1
  __m128 v20; // xmm7
  float v21; // xmm3_4
  int v22; // ecx
  int v23; // r9d
  int v24; // ecx
  int v25; // r8d
  float v26; // xmm7_4
  int v27; // ecx
  float v28; // xmm2_4
  int v29; // edx
  float v30; // xmm3_4
  __int64 v31; // rax
  __int64 v32; // rcx
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm7_4

  m_uDelayLength = this->m_uDelayLength;
  m_fReadWriteRateDelta = this->m_fReadWriteRateDelta;
  v7 = this->m_fFractDelay[in_uChanIndex];
  v8 = (float)m_uDelayLength;
  v9 = in_uNumFrames;
  v13 = (float)((unsigned int)m_uDelayLength >> 1);
  m_uOffset = this->m_DelayLines[in_uChanIndex].m_uOffset;
  v15 = this->m_DelayLines[in_uChanIndex].m_pDelay[0];
  v16 = m_uDelayLength - m_uOffset;
  if ( in_uNumFrames )
  {
    do
    {
      if ( v9 < v16 )
        v16 = v9;
      if ( v16 )
      {
        v17 = v16;
        do
        {
          v7 = v7 + m_fReadWriteRateDelta;
          v18 = v7 + v13;
          if ( v7 >= v8 )
            v7 = v7 - v8;
          if ( v18 >= v8 )
            v18 = v18 - v8;
          if ( v7 < 0.0 )
            v7 = v7 + v8;
          if ( v18 < 0.0 )
            v18 = v18 + v8;
          v19 = 0i64;
          v19.m128_f32[0] = (float)m_uOffset;
          v20 = v19;
          v20.m128_f32[0] = (float)m_uOffset - v7;
          v21 = v20.m128_f32[0];
          v22 = (int)v20.m128_f32[0];
          if ( (int)v20.m128_f32[0] != 0x80000000 && (float)v22 != v20.m128_f32[0] )
            v21 = (float)(v22 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1));
          v19.m128_f32[0] = v19.m128_f32[0] - v18;
          v23 = (int)v21;
          v24 = (int)v19.m128_f32[0];
          if ( (int)v19.m128_f32[0] != 0x80000000 && (float)v24 != v19.m128_f32[0] )
            v19.m128_f32[0] = (float)(v24 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
          v25 = (int)v19.m128_f32[0];
          if ( v23 >= m_uDelayLength )
            v23 -= m_uDelayLength;
          if ( v25 >= m_uDelayLength )
            v25 -= m_uDelayLength;
          if ( v23 < 0 )
            v23 += m_uDelayLength;
          if ( v25 < 0 )
            v25 += m_uDelayLength;
          v26 = v20.m128_f32[0] - v21;
          v27 = v23 + 1;
          v28 = 1.0 - v26;
          if ( v23 + 1 >= m_uDelayLength )
            v27 = 0;
          v29 = v25 + 1;
          if ( v25 + 1 >= m_uDelayLength )
            v29 = 0;
          ++out_pfOutBuf;
          ++in_pfInBuf;
          v30 = v28 * v15[v23];
          v31 = v27;
          v32 = (unsigned int)m_uOffset++;
          v33 = v26 * v15[v31];
          v34 = v28 * v15[v25];
          v35 = v26 * v15[v29];
          v15[v32] = *(in_pfInBuf - 1);
          *(out_pfOutBuf - 1) = (float)((float)(v30 + v33)
                                      * (float)(1.0
                                              - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 - v13) & _xmm)
                                                      * (float)(1.0 / v13))))
                              + (float)((float)(v34 + v35)
                                      * (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 - v13) & _xmm) * (float)(1.0 / v13)));
          --v17;
        }
        while ( v17 );
      }
      if ( m_uOffset == m_uDelayLength )
        m_uOffset = 0;
      v9 -= v16;
      v16 = m_uDelayLength - m_uOffset;
    }
    while ( v9 );
    this->m_DelayLines[in_uChanIndex].m_uOffset = m_uOffset;
    this->m_fFractDelay[in_uChanIndex] = v7;
  }
  else
  {
    this->m_DelayLines[in_uChanIndex].m_uOffset = m_uOffset;
    this->m_fFractDelay[in_uChanIndex] = v7;
  }
}

