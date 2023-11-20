// File Line: 32
// RVA: 0xAEB720
int AK::DSP::AkDelayPitchShift::Init(...)
{
  AK::DSP::AkDelayPitchShift *v5; // r14
  AK::IAkPluginMemAlloc *v6; // r15
  signed int v7; // ecx
  int v8; // esi
  unsigned int v9; // ecx
  signed __int64 v10; // rdi
  unsigned int v11; // ebx
  __int64 v12; // rax

  v5 = this;
  v6 = in_pAllocator;
  *(float *)&in_MaxDelayTime = (float)(*(float *)&in_MaxDelayTime * 0.001) * (float)(signed int)in_uSampleRate;
  v7 = (signed int)*(float *)&in_MaxDelayTime;
  if ( (signed int)*(float *)&in_MaxDelayTime != 0x80000000 && (float)v7 != *(float *)&in_MaxDelayTime )
    *(float *)&in_MaxDelayTime = (float)(v7
                                       - (_mm_movemask_ps(_mm_unpacklo_ps((__m128)in_MaxDelayTime, (__m128)in_MaxDelayTime)) & 1));
  v5->m_uNumChannels = in_uNumChannels;
  v5->m_fReadWriteRateDelta = 0.0;
  v8 = 0;
  v5->m_uDelayLength = ((signed int)*(float *)&in_MaxDelayTime + 3) & 0xFFFFFFFC;
  if ( !in_uNumChannels )
    return 1i64;
  while ( 1 )
  {
    v5->m_fFractDelay[v8] = 0.0;
    v9 = v5->m_uDelayLength;
    if ( v9 )
    {
      v10 = (signed __int64)&v5->m_DelayLines[v8];
      *(_DWORD *)(v10 + 16) = 1;
      *(_QWORD *)(v10 + 8) = (v9 + 3) & 0xFFFFFFFC;
      if ( (v9 + 3) & 0xFFFFFFFC )
        break;
    }
LABEL_10:
    if ( ++v8 >= v5->m_uNumChannels )
      return 1i64;
  }
  v11 = 0;
  while ( 1 )
  {
    v12 = (__int64)v6->vfptr->Malloc(v6, 4i64 * *(unsigned int *)(v10 + 8));
    *(_QWORD *)(v10 + 8i64 * v11) = v12;
    if ( !v12 )
      return 52i64;
    if ( ++v11 >= *(_DWORD *)(v10 + 16) )
      goto LABEL_10;
  }
}

// File Line: 53
// RVA: 0xAEB850
void __fastcall AK::DSP::AkDelayPitchShift::Term(AK::DSP::AkDelayPitchShift *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // r14
  AK::DSP::AkDelayPitchShift *v3; // r15
  unsigned int v4; // ebp
  unsigned int v5; // ebx
  signed __int64 v6; // rdi
  _QWORD *v7; // rsi

  v2 = in_pAllocator;
  v3 = this;
  v4 = 0;
  if ( this->m_uNumChannels )
  {
    do
    {
      v5 = 0;
      v6 = (signed __int64)&v3->m_DelayLines[v4];
      if ( v3->m_DelayLines[v4].m_uNumChannels > 0 )
      {
        do
        {
          v7 = (_QWORD *)(v6 + 8i64 * v5);
          if ( *v7 )
          {
            ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
            *v7 = 0i64;
          }
          ++v5;
        }
        while ( v5 < *(_DWORD *)(v6 + 16) );
      }
      ++v4;
      *(_DWORD *)(v6 + 8) = 0;
    }
    while ( v4 < v3->m_uNumChannels );
  }
}

// File Line: 61
// RVA: 0xAEB910
void __fastcall AK::DSP::AkDelayPitchShift::Reset(AK::DSP::AkDelayPitchShift *this)
{
  AK::DSP::AkDelayPitchShift *v1; // r14
  unsigned int v2; // esi
  AK::DSP::CAkDelayLineMemory<float,1> *v3; // rdi
  unsigned int i; // ebx
  float *v5; // rcx

  v1 = this;
  v2 = 0;
  if ( this->m_uNumChannels )
  {
    do
    {
      v3 = &v1->m_DelayLines[v2];
      if ( v1->m_DelayLines[v2].m_uDelayLineLength )
      {
        for ( i = 0; i < v3->m_uNumChannels; ++i )
        {
          v5 = v3->m_pDelay[i];
          if ( v5 )
            memset(v5, 0, 4 * v3->m_uDelayLineLength);
        }
      }
      ++v2;
      v3->m_uOffset = 0;
    }
    while ( v2 < v1->m_uNumChannels );
  }
}

// File Line: 70
// RVA: 0xAEB9B0
void __fastcall AK::DSP::AkDelayPitchShift::SetPitchFactor(AK::DSP::AkDelayPitchShift *this, float in_fPitchFactor)
{
  AK::DSP::AkDelayPitchShift *v2; // rdx
  unsigned int v3; // ecx
  __int64 v4; // rax

  v2 = this;
  if ( in_fPitchFactor == 1.0 )
  {
    this->m_fReadWriteRateDelta = 0.0;
    v3 = 0;
    if ( v2->m_uNumChannels )
    {
      do
      {
        v4 = v3++;
        v2->m_fFractDelay[v4] = 0.0;
      }
      while ( v3 < v2->m_uNumChannels );
    }
  }
  else
  {
    this->m_fReadWriteRateDelta = 1.0 - in_fPitchFactor;
  }
}

// File Line: 552
// RVA: 0xAEBA00
void __fastcall AK::DSP::AkDelayPitchShift::ProcessChannel(AK::DSP::AkDelayPitchShift *this, float *in_pfInBuf, float *out_pfOutBuf, unsigned int in_uNumFrames, unsigned int in_uChanIndex)
{
  signed int v5; // er10
  float v6; // xmm10_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  unsigned int v9; // edi
  float *v10; // r12
  float *v11; // r15
  AK::DSP::AkDelayPitchShift *v12; // r14
  float v13; // xmm9_4
  signed int v14; // er11
  float *v15; // rsi
  unsigned int v16; // ebx
  __int64 v17; // rbp
  float v18; // xmm2_4
  __m128 v19; // xmm1
  __m128 v20; // xmm7
  float v21; // xmm3_4
  signed int v22; // ecx
  signed int v23; // er9
  signed int v24; // ecx
  signed int v25; // er8
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

  v5 = this->m_uDelayLength;
  v6 = this->m_fReadWriteRateDelta;
  v7 = this->m_fFractDelay[in_uChanIndex];
  v8 = (float)v5;
  v9 = in_uNumFrames;
  v10 = out_pfOutBuf;
  v11 = in_pfInBuf;
  v12 = this;
  v13 = (float)(this->m_uDelayLength >> 1);
  v14 = this->m_DelayLines[in_uChanIndex].m_uOffset;
  v15 = this->m_DelayLines[in_uChanIndex].m_pDelay[0];
  v16 = v5 - v14;
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
          v7 = v7 + v6;
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
          v19.m128_f32[0] = (float)v14;
          v20 = v19;
          v20.m128_f32[0] = (float)v14 - v7;
          v21 = v20.m128_f32[0];
          v22 = (signed int)v20.m128_f32[0];
          if ( (signed int)v20.m128_f32[0] != 0x80000000 && (float)v22 != v20.m128_f32[0] )
            v21 = (float)(v22 - (_mm_movemask_ps(_mm_unpacklo_ps(v20, v20)) & 1));
          v19.m128_f32[0] = v19.m128_f32[0] - v18;
          v23 = (signed int)v21;
          v24 = (signed int)v19.m128_f32[0];
          if ( (signed int)v19.m128_f32[0] != 0x80000000 && (float)v24 != v19.m128_f32[0] )
            v19.m128_f32[0] = (float)(v24 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
          v25 = (signed int)v19.m128_f32[0];
          if ( v23 >= v5 )
            v23 -= v5;
          if ( v25 >= v5 )
            v25 -= v5;
          if ( v23 < 0 )
            v23 += v5;
          if ( v25 < 0 )
            v25 += v5;
          v26 = v20.m128_f32[0] - v21;
          v27 = v23 + 1;
          v28 = 1.0 - v26;
          if ( v23 + 1 >= v5 )
            v27 = 0;
          v29 = v25 + 1;
          if ( v25 + 1 >= v5 )
            v29 = 0;
          ++v10;
          ++v11;
          v30 = v28 * v15[v23];
          v31 = v27;
          v32 = (unsigned int)v14++;
          v33 = v26 * v15[v31];
          v34 = v28 * v15[v25];
          v35 = v26 * v15[v29];
          v15[v32] = *(v11 - 1);
          *(v10 - 1) = (float)((float)(v30 + v33)
                             * (float)(1.0
                                     - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 - v13) & _xmm) * (float)(1.0 / v13))))
                     + (float)((float)(v34 + v35)
                             * (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 - v13) & _xmm) * (float)(1.0 / v13)));
          --v17;
        }
        while ( v17 );
      }
      if ( v14 == v5 )
        v14 = 0;
      v9 -= v16;
      v16 = v5 - v14;
    }
    while ( v9 );
    v12->m_DelayLines[in_uChanIndex].m_uOffset = v14;
    v12->m_fFractDelay[in_uChanIndex] = v7;
  }
  else
  {
    this->m_DelayLines[in_uChanIndex].m_uOffset = v14;
    this->m_fFractDelay[in_uChanIndex] = v7;
  }
}

