// File Line: 56
// RVA: 0xA90640
void __fastcall CAkSrcLpFilter::CAkSrcLpFilter(CAkSrcLpFilter *this)
{
  CAkSrcLpFilter *v1; // rbx
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v2; // rcx

  v1 = this;
  v2 = (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)&this->m_InternalLPFState;
  *(_QWORD *)&v2[-1].m_Memories.m_Memories.fFFwd1 = &CAkSrcLpFilter::`vftable';
  *(_QWORD *)&v2->m_Memories.m_Memories.fFFwd1 = 0i64;
  v2->m_Memories.m_Memories.fFFbk1 = 0.0;
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(v2, 1.0, 0.0, 0.0, 0.0, 0.0);
  *(_QWORD *)&v1->m_InternalLPFState.fCurrentLPFPar = 0i64;
}

// File Line: 62
// RVA: 0xA906A0
void __fastcall CAkSrcLpFilter::~CAkSrcLpFilter(CAkSrcLpFilter *this)
{
  CAkSrcLpFilter *v1; // rbx
  DSP::Memories *v2; // rdx

  v1 = this;
  this->vfptr = (CAkSrcLpFilterVtbl *)&CAkSrcLpFilter::`vftable';
  v2 = this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories;
  if ( v2 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v2);
    v1->m_InternalLPFState.m_LPF.m_Memories.m_pMemories = 0i64;
  }
}

// File Line: 66
// RVA: 0xA90B10
signed __int64 __fastcall CAkSrcLpFilter::Init(CAkSrcLpFilter *this, unsigned int in_uChannelMask, bool in_bComputeCoefsForFeedback)
{
  int v3; // er8
  CAkSrcLpFilter *v4; // rbx
  unsigned int v5; // er8
  DSP::Memories *v6; // rax

  this->m_InternalLPFState.bComputeCoefsForFeedback = in_bComputeCoefsForFeedback;
  v3 = 0;
  v4 = this;
  this->m_InternalLPFState.uChannelMask = in_uChannelMask;
  *(_WORD *)&this->m_InternalLPFState.bBypassFilter = 257;
  this->m_InternalLPFState.uNumInterBlocks = 8;
  for ( this->m_InternalLPFState.bFirstSetLPF = 1; in_uChannelMask; in_uChannelMask &= in_uChannelMask - 1 )
    ++v3;
  v5 = 16 * v3;
  this->m_InternalLPFState.m_LPF.m_Memories.m_uSize = v5;
  v6 = (DSP::Memories *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v5);
  v4->m_InternalLPFState.m_LPF.m_Memories.m_pMemories = v6;
  if ( !v6 )
    return 52i64;
  memset(v6, 0, v4->m_InternalLPFState.m_LPF.m_Memories.m_uSize);
  return 1i64;
}

// File Line: 91
// RVA: 0xA91390
void __fastcall CAkSrcLpFilter::Term(CAkSrcLpFilter *this)
{
  DSP::Memories *v1; // rdx
  CAkSrcLpFilter *v2; // rbx

  v1 = this->m_InternalLPFState.m_LPF.m_Memories.m_pMemories;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_InternalLPFState.m_LPF.m_Memories.m_pMemories = 0i64;
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
void __fastcall ManageLPFChange(AkInternalLPFState *io_state)
{
  AkInternalLPFState *v1; // rbx
  bool v2; // zf
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  bool v10; // al

  v1 = io_state;
  if ( io_state->bTargetDirty )
  {
    v2 = io_state->bFirstSetLPF == 0;
    io_state->bTargetDirty = 0;
    if ( v2 )
    {
      v10 = io_state->fCurrentLPFPar <= 0.1 && io_state->fTargetLPFPar <= 0.1;
      io_state->bBypassFilter = v10;
      io_state->uNumInterBlocks = v10 != 0 ? 8 : 0;
    }
    else
    {
      v3 = io_state->fTargetLPFPar;
      io_state->bFirstSetLPF = 0;
      io_state->uNumInterBlocks = 8;
      io_state->fCurrentLPFPar = v3;
      io_state->bBypassFilter = v3 <= 0.1;
      if ( v3 > 0.1 )
      {
        v4 = FLOAT_0_44999999;
        v5 = EvalLPFCutoff(v3, io_state->bComputeCoefsForFeedback)
           / (float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v5 <= 0.44999999 )
          v4 = v5;
        v6 = 1.0 / tanf(v4 * 3.1415927);
        v7 = v6;
        v8 = v6 * v6;
        v9 = v7 * 1.4142135;
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
          (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)v1,
          1.0 / (float)((float)(v9 + 1.0) + v8),
          (float)(1.0 / (float)((float)(v9 + 1.0) + v8)) * 2.0,
          1.0 / (float)((float)(v9 + 1.0) + v8),
          (float)((float)(1.0 - v8) * 2.0) * (float)(1.0 / (float)((float)(v9 + 1.0) + v8)),
          (float)((float)(1.0 - v9) + v8) * (float)(1.0 / (float)((float)(v9 + 1.0) + v8)));
      }
    }
  }
}

// File Line: 171
// RVA: 0xA90740
void __fastcall CAkSrcLpFilter::Execute(CAkSrcLpFilter *this, AkAudioBuffer *io_pBuffer)
{
  DSP::BiquadFilter<DSP::MultiChannelPolicy> *v2; // rbp
  CAkSrcLpFilter *v3; // r13
  AkAudioBuffer *v4; // rdi
  unsigned int v5; // edx
  unsigned int v6; // er15
  unsigned int i; // esi
  unsigned int v8; // er8
  float v9; // xmm7_4
  unsigned int v10; // er12
  float v11; // xmm8_4
  unsigned __int16 v12; // r9
  _DWORD *v13; // rcx
  __int64 v14; // r8
  __int64 v15; // rdx
  _DWORD *v16; // r8
  unsigned int v17; // er14
  unsigned __int16 v18; // ax
  bool v19; // dl
  unsigned __int16 v20; // ax
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  unsigned int v27; // ebx
  __int64 v28; // rbp
  __int64 v29; // rbx
  CAkSrcLpFilter *v30; // [rsp+100h] [rbp+8h]
  unsigned int v31; // [rsp+110h] [rbp+18h]
  DSP::BiquadFilter<DSP::MultiChannelPolicy> *v32; // [rsp+118h] [rbp+20h]

  v30 = this;
  v2 = &this->m_InternalLPFState.m_LPF;
  v3 = this;
  v4 = io_pBuffer;
  v32 = &this->m_InternalLPFState.m_LPF;
  ManageLPFChange(&this->m_InternalLPFState);
  if ( !v3->m_InternalLPFState.bBypassFilter )
  {
    v5 = v4->uChannelMask;
    v6 = 0;
    for ( i = 0; v5; v5 &= v5 - 1 )
      ++i;
    v8 = v4->uValidFrames;
    v31 = v4->uValidFrames;
    if ( v3->m_InternalLPFState.uNumInterBlocks >= 8u )
    {
      if ( i )
      {
        v29 = 0i64;
        do
        {
          DSP::BiquadFilter<DSP::MultiChannelPolicy>::ProcessBuffer(
            v2,
            (float *)v4->pData + v29 * v4->uMaxFrames,
            v8,
            v6);
          v8 = v31;
          ++v6;
          ++v29;
        }
        while ( v6 < i );
      }
    }
    else
    {
      v9 = v3->m_InternalLPFState.fCurrentLPFPar;
      v10 = 0;
      v11 = v3->m_InternalLPFState.fTargetLPFPar - v9;
      if ( v9 <= 0.1 )
      {
        if ( v8 < 2 )
          return;
        v12 = 0;
        if ( i )
        {
          do
          {
            v13 = v4->pData;
            v14 = v12++;
            v15 = v14 * v4->uMaxFrames;
            v16 = (_DWORD *)&v3->m_InternalLPFState.m_LPF.m_Memories.m_pMemories[v14].fFFwd1;
            v16[2] = *((_DWORD *)v4->pData + v15 + 1);
            v16[3] = v13[v15];
            *v16 = v13[v15 + 1];
            v16[1] = v13[v15];
          }
          while ( v12 < i );
          v8 = v31;
        }
        v10 = 2;
      }
      for ( ; v10 < v8; v10 += v17 )
      {
        v17 = v8 - v10;
        if ( AkAudioLibSettings::g_uLpfUpdatePeriod < v8 - v10 )
          v17 = AkAudioLibSettings::g_uLpfUpdatePeriod;
        v18 = v3->m_InternalLPFState.uNumInterBlocks;
        if ( v18 < 8u )
        {
          v19 = v3->m_InternalLPFState.bComputeCoefsForFeedback;
          v20 = v18 + 1;
          v3->m_InternalLPFState.uNumInterBlocks = v20;
          v21 = (float)((float)((float)v20 * v11) * 0.125) + v9;
          v3->m_InternalLPFState.fCurrentLPFPar = v21;
          v22 = EvalLPFCutoff(v21, v19) / (float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
          if ( v22 > 0.44999999 )
            v22 = FLOAT_0_44999999;
          v23 = 1.0 / tanf(v22 * 3.1415927);
          v24 = v23;
          v25 = v23 * v23;
          v26 = v24 * 1.4142135;
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
            (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)v2,
            1.0 / (float)((float)(v26 + 1.0) + v25),
            (float)(1.0 / (float)((float)(v26 + 1.0) + v25)) * 2.0,
            1.0 / (float)((float)(v26 + 1.0) + v25),
            (float)((float)(1.0 - v25) * 2.0) * (float)(1.0 / (float)((float)(v26 + 1.0) + v25)),
            (float)((float)(1.0 - v26) + v25) * (float)(1.0 / (float)((float)(v26 + 1.0) + v25)));
          v8 = v31;
        }
        v27 = 0;
        if ( i )
        {
          v28 = 0i64;
          do
            DSP::BiquadFilter<DSP::MultiChannelPolicy>::ProcessBuffer(
              v32,
              (float *)v4->pData + v10 + v28++ * v4->uMaxFrames,
              v17,
              v27++);
          while ( v27 < i );
          v3 = v30;
          v2 = v32;
          v8 = v31;
        }
      }
      if ( v3->m_InternalLPFState.uNumInterBlocks >= 8u )
        v3->m_InternalLPFState.bBypassFilter = 0.1 >= v3->m_InternalLPFState.fTargetLPFPar;
    }
  }
}

