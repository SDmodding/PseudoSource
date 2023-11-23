// File Line: 56
// RVA: 0xA90640
void __fastcall CAkSrcLpFilter::CAkSrcLpFilter(CAkSrcLpFilter *this)
{
  AkInternalLPFState *p_m_InternalLPFState; // rcx

  p_m_InternalLPFState = &this->m_InternalLPFState;
  *(_QWORD *)&p_m_InternalLPFState[-1].fCurrentLPFPar = &CAkSrcLpFilter::`vftable;
  p_m_InternalLPFState->m_LPF.m_Memories.m_pMemories = 0i64;
  p_m_InternalLPFState->m_LPF.m_Memories.m_uSize = 0;
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
    (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)p_m_InternalLPFState,
    1.0,
    0.0,
    0.0,
    0.0,
    0.0);
  *(_QWORD *)&this->m_InternalLPFState.fCurrentLPFPar = 0i64;
}

// File Line: 62
// RVA: 0xA906A0
void __fastcall CAkSrcLpFilter::~CAkSrcLpFilter(CAkSrcLpFilter *this)
{
  DSP::Memories *m_pMemories; // rdx

  this->vfptr = (CAkSrcLpFilterVtbl *)&CAkSrcLpFilter::`vftable;
  m_pMemories = this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories;
  if ( m_pMemories )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pMemories);
    this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories = 0i64;
  }
}

// File Line: 66
// RVA: 0xA90B10
__int64 __fastcall CAkSrcLpFilter::Init(
        CAkSrcLpFilter *this,
        unsigned int in_uChannelMask,
        bool in_bComputeCoefsForFeedback)
{
  int v3; // r8d
  unsigned int v5; // r8d
  DSP::Memories *v6; // rax

  this->m_InternalLPFState.bComputeCoefsForFeedback = in_bComputeCoefsForFeedback;
  v3 = 0;
  this->m_InternalLPFState.uChannelMask = in_uChannelMask;
  *(_WORD *)&this->m_InternalLPFState.bBypassFilter = 257;
  this->m_InternalLPFState.uNumInterBlocks = 8;
  for ( this->m_InternalLPFState.bFirstSetLPF = 1; in_uChannelMask; in_uChannelMask &= in_uChannelMask - 1 )
    ++v3;
  v5 = 16 * v3;
  this->m_InternalLPFState.m_LPF.m_Memories.m_uSize = v5;
  v6 = (DSP::Memories *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v5);
  this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories = v6;
  if ( !v6 )
    return 52i64;
  memset(v6, 0, this->m_InternalLPFState.m_LPF.m_Memories.m_uSize);
  return 1i64;
}

// File Line: 91
// RVA: 0xA91390
void __fastcall CAkSrcLpFilter::Term(CAkSrcLpFilter *this)
{
  DSP::Memories *m_pMemories; // rdx

  m_pMemories = this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories;
  if ( m_pMemories )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pMemories);
    this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories = 0i64;
  }
}

// File Line: 105
// RVA: 0xA910C0
void __fastcall CAkSrcLpFilter::ResetRamp(CAkSrcLpFilter *this)
{
  this->m_InternalLPFState.bFirstSetLPF = 1;
  if ( this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories )
    memset(this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories, 0, this->m_InternalLPFState.m_LPF.m_Memories.m_uSize);
}

// File Line: 111
// RVA: 0xA913D0
void __fastcall ManageLPFChange(DSP::BiquadFilter<DSP::SingleChannelPolicy> *io_state)
{
  bool v2; // zf
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  bool v9; // al

  if ( io_state[1].m_Coefficients.vFirst.m128_i8[14] )
  {
    v2 = io_state[1].m_Coefficients.vFirst.m128_i8[15] == 0;
    io_state[1].m_Coefficients.vFirst.m128_i8[14] = 0;
    if ( v2 )
    {
      v9 = io_state[1].m_Coefficients.vFirst.m128_f32[0] <= 0.1 && io_state[1].m_Coefficients.vFirst.m128_f32[1] <= 0.1;
      io_state[1].m_Coefficients.vFirst.m128_i8[13] = v9;
      io_state[1].m_Coefficients.vFirst.m128_i16[4] = v9 ? 8 : 0;
    }
    else
    {
      v3 = io_state[1].m_Coefficients.vFirst.m128_f32[1];
      io_state[1].m_Coefficients.vFirst.m128_i8[15] = 0;
      io_state[1].m_Coefficients.vFirst.m128_i16[4] = 8;
      io_state[1].m_Coefficients.vFirst.m128_f32[0] = v3;
      io_state[1].m_Coefficients.vFirst.m128_i8[13] = v3 <= 0.1;
      if ( v3 > 0.1 )
      {
        v4 = FLOAT_0_44999999;
        v5 = EvalLPFCutoff(v3, io_state[1].m_Coefficients.vFirst.m128_i8[12])
           / (float)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v5 <= 0.44999999 )
          v4 = v5;
        v6 = 1.0 / tanf(v4 * 3.1415927);
        v7 = v6 * v6;
        v8 = v6 * 1.4142135;
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
          io_state,
          1.0 / (float)((float)(v8 + 1.0) + v7),
          (float)(1.0 / (float)((float)(v8 + 1.0) + v7)) * 2.0,
          1.0 / (float)((float)(v8 + 1.0) + v7),
          (float)((float)(1.0 - v7) * 2.0) * (float)(1.0 / (float)((float)(v8 + 1.0) + v7)),
          (float)((float)(1.0 - v8) + v7) * (float)(1.0 / (float)((float)(v8 + 1.0) + v7)));
      }
    }
  }
}

// File Line: 171
// RVA: 0xA90740
void __fastcall CAkSrcLpFilter::Execute(CAkSrcLpFilter *this, AkAudioBuffer *io_pBuffer)
{
  AkInternalLPFState *p_m_InternalLPFState; // rbp
  CAkSrcLpFilter *v3; // r13
  unsigned int uChannelMask; // edx
  unsigned int v6; // r15d
  unsigned int i; // esi
  unsigned int uValidFrames; // r8d
  float fCurrentLPFPar; // xmm7_4
  unsigned int v10; // r12d
  float v11; // xmm8_4
  unsigned __int16 v12; // r9
  _DWORD *pData; // rcx
  __int64 v14; // r8
  __int64 v15; // rdx
  _DWORD *p_fFFwd1; // r8
  unsigned int v17; // r14d
  unsigned __int16 uNumInterBlocks; // ax
  bool bComputeCoefsForFeedback; // dl
  unsigned __int16 v20; // ax
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm4_4
  unsigned int v26; // ebx
  __int64 v27; // rbp
  __int64 v28; // rbx
  unsigned int v30; // [rsp+110h] [rbp+18h]
  AkInternalLPFState *v31; // [rsp+118h] [rbp+20h]

  p_m_InternalLPFState = &this->m_InternalLPFState;
  v3 = this;
  v31 = &this->m_InternalLPFState;
  ManageLPFChange(&this->m_InternalLPFState);
  if ( !v3->m_InternalLPFState.bBypassFilter )
  {
    uChannelMask = io_pBuffer->uChannelMask;
    v6 = 0;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    uValidFrames = io_pBuffer->uValidFrames;
    v30 = uValidFrames;
    if ( v3->m_InternalLPFState.uNumInterBlocks >= 8u )
    {
      if ( i )
      {
        v28 = 0i64;
        do
        {
          DSP::BiquadFilter<DSP::MultiChannelPolicy>::ProcessBuffer(
            &p_m_InternalLPFState->m_LPF,
            (float *)io_pBuffer->pData + v28 * io_pBuffer->uMaxFrames,
            uValidFrames,
            v6);
          uValidFrames = v30;
          ++v6;
          ++v28;
        }
        while ( v6 < i );
      }
    }
    else
    {
      fCurrentLPFPar = v3->m_InternalLPFState.fCurrentLPFPar;
      v10 = 0;
      v11 = v3->m_InternalLPFState.fTargetLPFPar - fCurrentLPFPar;
      if ( fCurrentLPFPar <= 0.1 )
      {
        if ( uValidFrames < 2 )
          return;
        v12 = 0;
        if ( i )
        {
          do
          {
            pData = io_pBuffer->pData;
            v14 = v12++;
            v15 = v14 * io_pBuffer->uMaxFrames;
            p_fFFwd1 = (_DWORD *)&v3->m_InternalLPFState.m_LPF.m_Memories.m_pMemories[v14].fFFwd1;
            p_fFFwd1[2] = *((_DWORD *)io_pBuffer->pData + v15 + 1);
            p_fFFwd1[3] = pData[v15];
            *p_fFFwd1 = pData[v15 + 1];
            p_fFFwd1[1] = pData[v15];
          }
          while ( v12 < i );
          uValidFrames = v30;
        }
        v10 = 2;
      }
      for ( ; v10 < uValidFrames; v10 += v17 )
      {
        v17 = uValidFrames - v10;
        if ( AkAudioLibSettings::g_uLpfUpdatePeriod < uValidFrames - v10 )
          v17 = AkAudioLibSettings::g_uLpfUpdatePeriod;
        uNumInterBlocks = v3->m_InternalLPFState.uNumInterBlocks;
        if ( uNumInterBlocks < 8u )
        {
          bComputeCoefsForFeedback = v3->m_InternalLPFState.bComputeCoefsForFeedback;
          v20 = uNumInterBlocks + 1;
          v3->m_InternalLPFState.uNumInterBlocks = v20;
          v21 = (float)((float)((float)v20 * v11) * 0.125) + fCurrentLPFPar;
          v3->m_InternalLPFState.fCurrentLPFPar = v21;
          v22 = EvalLPFCutoff(v21, bComputeCoefsForFeedback) / (float)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
          if ( v22 > 0.44999999 )
            v22 = FLOAT_0_44999999;
          v23 = tanf(v22 * 3.1415927);
          v24 = (float)(1.0 / v23) * (float)(1.0 / v23);
          v25 = 1.0 / (float)((float)((float)((float)(1.0 / v23) * 1.4142135) + 1.0) + v24);
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
            (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)p_m_InternalLPFState,
            v25,
            v25 * 2.0,
            v25,
            (float)((float)(1.0 - v24) * 2.0) * v25,
            (float)((float)(1.0 - (float)((float)(1.0 / v23) * 1.4142135)) + v24) * v25);
          uValidFrames = v30;
        }
        v26 = 0;
        if ( i )
        {
          v27 = 0i64;
          do
          {
            DSP::BiquadFilter<DSP::MultiChannelPolicy>::ProcessBuffer(
              &v31->m_LPF,
              (float *)io_pBuffer->pData + v10 + v27 * io_pBuffer->uMaxFrames,
              v17,
              v26++);
            ++v27;
          }
          while ( v26 < i );
          v3 = this;
          p_m_InternalLPFState = v31;
          uValidFrames = v30;
        }
      }
      if ( v3->m_InternalLPFState.uNumInterBlocks >= 8u )
        v3->m_InternalLPFState.bBypassFilter = v3->m_InternalLPFState.fTargetLPFPar <= 0.1;
    }
  }
}

