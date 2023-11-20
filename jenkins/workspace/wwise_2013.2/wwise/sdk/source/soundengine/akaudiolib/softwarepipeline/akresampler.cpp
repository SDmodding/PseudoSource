// File Line: 230
// RVA: 0xA91680
float __fastcall CAkResampler::GetLastRate(CAkResampler *this)
{
  return (float)((float)(signed int)this->m_InternalPitchState.uCurrentFrameSkip * 0.000015258789)
       / this->m_fSampleRateConvertRatio;
}

// File Line: 281
// RVA: 0xA91A20
void __fastcall CAkResampler::SwitchTo(CAkResampler *this, AkAudioFormat *in_fmt, float in_fPitch, AkAudioBuffer *io_pIOBuffer, unsigned int in_uSampleRate)
{
  char v5; // di
  AkAudioBuffer *v6; // rbp
  AkAudioFormat *v7; // rsi
  CAkResampler *v8; // rbx
  unsigned int v9; // eax
  int *v10; // rcx
  CAkResampler *v11; // rdx
  __int64 v12; // r8
  signed int v13; // eax
  bool v14; // di
  float v15; // xmm1_4
  int v16; // eax
  char v17; // al
  char v18; // al
  char v19; // al
  bool v20; // zf
  char v21; // al
  __int64 v22; // rdx
  __int64 v23; // rdx
  float v24; // xmm0_4
  int Dst[8]; // [rsp+20h] [rbp-38h]

  v5 = this->m_DSPFunctionIndex;
  v6 = io_pIOBuffer;
  v7 = in_fmt;
  v8 = this;
  if ( (unsigned __int8)v5 < 4u )
  {
    v9 = (unsigned __int8)this->m_uNumChannels;
    if ( this->m_uNumChannels )
    {
      v10 = Dst;
      v11 = v8;
      v12 = v9;
      do
      {
        v13 = v11->m_InternalPitchState.iLastValue[0];
        ++v10;
        v11 = (CAkResampler *)((char *)v11 + 2);
        *((float *)v10 - 1) = (float)v13 * 0.000030517578;
        --v12;
      }
      while ( v12 );
    }
  }
  else if ( (unsigned __int8)(v5 - 4) <= 3u && this->m_uNumChannels )
  {
    memmove(Dst, this, 4i64 * (unsigned __int8)this->m_uNumChannels);
  }
  v14 = v8->m_PitchOperationMode == PitchOperatingMode_Bypass
     && v8->m_uNumChannels > 2u
     && (unsigned __int8)(v5 - 4) > 3u;
  v15 = (float)(signed int)v7->uSampleRate / (float)(signed int)in_uSampleRate;
  if ( v15 != v8->m_fSampleRateConvertRatio )
  {
    v8->m_fSampleRateConvertRatio = v15;
    v8->m_bFirstSetPitch = 1;
  }
  CAkResampler::SetPitch(v8, in_fPitch);
  v8->m_uInputBlockAlign = *((_BYTE *)v7 + 7) & 0x1F;
  v16 = (*((_DWORD *)v7 + 1) >> 18) & 0x3F;
  if ( v16 == 16 )
  {
    v19 = v8->m_uNumChannels;
    if ( v19 == 1 )
    {
      v17 = 0;
    }
    else if ( v19 == 2 )
    {
      v17 = 1;
    }
    else
    {
      v17 = ((unsigned __int8)(v19 - 3) > 1u) + 2;
    }
  }
  else if ( v16 == 32 )
  {
    v18 = v8->m_uNumChannels;
    if ( v18 == 1 )
    {
      v17 = 4;
    }
    else if ( v18 == 2 )
    {
      v17 = 5;
    }
    else
    {
      v17 = ((unsigned __int8)(v18 - 3) > 1u) + 6;
    }
  }
  else
  {
    v17 = -1;
  }
  v20 = v8->m_PitchOperationMode == 0;
  v8->m_DSPFunctionIndex = v17;
  if ( v20 && v8->m_uNumChannels > 2u && (unsigned __int8)(v17 - 4) > 3u )
  {
    if ( !v14 )
      CAkResampler::InterleaveAndSwapOutput(v8, v6);
  }
  else if ( v14 )
  {
    CAkResampler::DeinterleaveAndSwapOutput(v8, v6);
  }
  v21 = v8->m_DSPFunctionIndex;
  if ( (unsigned __int8)v21 < 4u )
  {
    v23 = 0i64;
    if ( !v8->m_uNumChannels )
      return;
    while ( 1 )
    {
      v24 = *(float *)&Dst[v23] * 32767.0;
      if ( v24 >= 32767.0 )
        break;
      if ( v24 > -32768.0 )
      {
        if ( v24 >= 32767.0 )
          break;
      }
      else
      {
        v24 = FLOAT_N32768_0;
      }
LABEL_46:
      v8->m_InternalPitchState.iLastValue[v23] = (signed int)v24;
      v23 = (unsigned int)(v23 + 1);
      if ( (unsigned int)v23 >= (unsigned __int8)v8->m_uNumChannels )
        return;
    }
    v24 = FLOAT_32767_0;
    goto LABEL_46;
  }
  if ( (unsigned __int8)(v21 - 4) <= 3u )
  {
    v22 = 0i64;
    if ( v8->m_uNumChannels )
    {
      do
      {
        LODWORD(v8->m_InternalPitchState.fLastValue[v22]) = Dst[v22];
        v22 = (unsigned int)(v22 + 1);
      }
      while ( (unsigned int)v22 < (unsigned __int8)v8->m_uNumChannels );
    }
  }
}

// File Line: 381
// RVA: 0xA916A0
void __fastcall CAkResampler::Init(CAkResampler *this, AkAudioFormat *io_pFormat, unsigned int in_uSampleRate)
{
  AkAudioFormat *v3; // r10
  CAkResampler *v4; // r9
  char v5; // cl
  int i; // edx
  int v7; // eax

  v3 = io_pFormat;
  *(_QWORD *)&this->m_InternalPitchState.uFloatIndex = 0x10000i64;
  this->m_bFirstSetPitch = 1;
  *(_QWORD *)&this->m_InternalPitchState.uInFrameOffset = 0i64;
  *(_QWORD *)&this->m_InternalPitchState.uTargetFrameSkip = 0i64;
  this->m_InternalPitchState.uInterpolationRampInc = 0xBB80 / in_uSampleRate;
  this->m_fTargetPitchVal = 0.0;
  v4 = this;
  this->m_fSampleRateConvertRatio = (float)(signed int)io_pFormat->uSampleRate / (float)(signed int)in_uSampleRate;
  v5 = 0;
  for ( i = *((_DWORD *)io_pFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v5;
  v4->m_uNumChannels = v5;
  v4->m_uInputBlockAlign = *((_BYTE *)v3 + 7) & 0x1F;
  v7 = (*((_DWORD *)v3 + 1) >> 18) & 0x3F;
  if ( v7 == 16 )
  {
    if ( v5 == 1 )
    {
      v4->m_PitchOperationMode = 0;
      v4->m_DSPFunctionIndex = 0;
    }
    else if ( v5 == 2 )
    {
      v4->m_PitchOperationMode = 0;
      v4->m_DSPFunctionIndex = 1;
    }
    else
    {
      v4->m_PitchOperationMode = 0;
      v4->m_DSPFunctionIndex = ((unsigned __int8)(v5 - 3) > 1u) + 2;
    }
  }
  else if ( v7 == 32 )
  {
    if ( v5 == 1 )
    {
      v4->m_PitchOperationMode = 0;
      v4->m_DSPFunctionIndex = 4;
    }
    else if ( v5 == 2 )
    {
      v4->m_PitchOperationMode = 0;
      v4->m_DSPFunctionIndex = 5;
    }
    else
    {
      v4->m_PitchOperationMode = 0;
      v4->m_DSPFunctionIndex = ((unsigned __int8)(v5 - 3) > 1u) + 6;
    }
  }
  else
  {
    v4->m_DSPFunctionIndex = -1;
    v4->m_PitchOperationMode = 0;
  }
}

// File Line: 492
// RVA: 0xA915D0
signed __int64 __fastcall CAkResampler::Execute(CAkResampler *this, AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer)
{
  AkAudioBuffer *v3; // rsi
  AkAudioBuffer *v4; // rdi
  CAkResampler *v5; // rbx
  AKRESULT v7; // edx
  unsigned int v8; // ecx

  v3 = io_pOutBuffer;
  v4 = io_pInBuffer;
  v5 = this;
  if ( !io_pInBuffer->uValidFrames )
    return 17i64;
  do
  {
    v7 = (unsigned int)PitchDSPFuncTable[0][(unsigned __int8)v5->m_DSPFunctionIndex
                                          + 8i64 * (signed int)v5->m_PitchOperationMode](
                         v4,
                         v3,
                         v5->m_InternalPitchState.uRequestedFrames,
                         (AkInternalPitchState *)v5);
    if ( v5->m_PitchOperationMode == 2 && v5->m_InternalPitchState.uInterpolationRampCount >= 0x400 )
    {
      v8 = v5->m_InternalPitchState.uTargetFrameSkip;
      v5->m_PitchOperationMode = 1;
      v5->m_InternalPitchState.uCurrentFrameSkip = v8;
    }
  }
  while ( v4->uValidFrames && v3->uValidFrames < v5->m_InternalPitchState.uRequestedFrames );
  return (unsigned int)v7;
}

// File Line: 535
// RVA: 0xA91840
bool __fastcall CAkResampler::IsPostDeInterleaveRequired(CAkResampler *this)
{
  return this->m_PitchOperationMode == PitchOperatingMode_Bypass
      && this->m_uNumChannels > 2u
      && (unsigned __int8)(this->m_DSPFunctionIndex - 4) > 3u;
}

// File Line: 551
// RVA: 0xA91530
signed __int64 __fastcall CAkResampler::DeinterleaveAndSwapOutput(CAkResampler *this, AkAudioBuffer *io_pIOBuffer)
{
  unsigned int v2; // er8
  AkPipelineBufferBase *v3; // rbx
  void *v4; // rax
  unsigned __int16 v5; // dx
  signed __int64 result; // rax
  AkAudioBuffer io_pOutBuffer; // [rsp+20h] [rbp-48h]
  void *v8; // [rsp+38h] [rbp-30h]
  __int64 v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+48h] [rbp-20h]
  void *v11; // [rsp+50h] [rbp-18h]

  v2 = io_pIOBuffer->uChannelMask;
  v3 = (AkPipelineBufferBase *)io_pIOBuffer;
  io_pOutBuffer.pData = io_pIOBuffer->pData;
  *(_QWORD *)&io_pOutBuffer.uChannelMask = *(_QWORD *)&io_pIOBuffer->uChannelMask;
  *(_QWORD *)&io_pOutBuffer.uMaxFrames = *(_QWORD *)&io_pIOBuffer->uMaxFrames;
  v8 = io_pIOBuffer[1].pData;
  v9 = *(_QWORD *)&io_pIOBuffer[1].uChannelMask;
  v10 = *(_QWORD *)&io_pIOBuffer[1].uMaxFrames;
  v4 = io_pIOBuffer[2].pData;
  v5 = io_pIOBuffer->uMaxFrames;
  v11 = v4;
  result = AkPipelineBufferBase::GetCachedBuffer((AkPipelineBufferBase *)&io_pOutBuffer, v5, v2);
  if ( (_DWORD)result == 1 )
  {
    io_pOutBuffer.uValidFrames = v3->uValidFrames;
    Deinterleave_Native_NChan((AkAudioBuffer *)&v3->pData, &io_pOutBuffer);
    AkPipelineBufferBase::ReleaseCachedBuffer(v3);
    *v3 = (AkPipelineBufferBase)io_pOutBuffer;
    result = 1i64;
  }
  return result;
}

// File Line: 569
// RVA: 0xA917A0
signed __int64 __fastcall CAkResampler::InterleaveAndSwapOutput(CAkResampler *this, AkAudioBuffer *io_pIOBuffer)
{
  unsigned int v2; // er8
  AkPipelineBufferBase *v3; // rbx
  void *v4; // rax
  unsigned __int16 v5; // dx
  signed __int64 result; // rax
  AkAudioBuffer io_pOutBuffer; // [rsp+20h] [rbp-48h]
  void *v8; // [rsp+38h] [rbp-30h]
  __int64 v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+48h] [rbp-20h]
  void *v11; // [rsp+50h] [rbp-18h]

  v2 = io_pIOBuffer->uChannelMask;
  v3 = (AkPipelineBufferBase *)io_pIOBuffer;
  io_pOutBuffer.pData = io_pIOBuffer->pData;
  *(_QWORD *)&io_pOutBuffer.uChannelMask = *(_QWORD *)&io_pIOBuffer->uChannelMask;
  *(_QWORD *)&io_pOutBuffer.uMaxFrames = *(_QWORD *)&io_pIOBuffer->uMaxFrames;
  v8 = io_pIOBuffer[1].pData;
  v9 = *(_QWORD *)&io_pIOBuffer[1].uChannelMask;
  v10 = *(_QWORD *)&io_pIOBuffer[1].uMaxFrames;
  v4 = io_pIOBuffer[2].pData;
  v5 = io_pIOBuffer->uMaxFrames;
  v11 = v4;
  result = AkPipelineBufferBase::GetCachedBuffer((AkPipelineBufferBase *)&io_pOutBuffer, v5, v2);
  if ( (_DWORD)result == 1 )
  {
    io_pOutBuffer.uValidFrames = v3->uValidFrames;
    Interleave_Native_NChan((AkAudioBuffer *)&v3->pData, &io_pOutBuffer);
    AkPipelineBufferBase::ReleaseCachedBuffer(v3);
    *v3 = (AkPipelineBufferBase)io_pOutBuffer;
    result = 1i64;
  }
  return result;
}

// File Line: 594
// RVA: 0xA91860
void __fastcall CAkResampler::ResetOffsets(CAkResampler *this)
{
  *(_QWORD *)&this->m_InternalPitchState.uInFrameOffset = 0i64;
}

// File Line: 626
// RVA: 0xA91870
void __fastcall CAkResampler::SetPitch(CAkResampler *this, float in_fPitchVal)
{
  float v2; // xmm0_4
  float v3; // xmm6_4
  CAkResampler *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm0_4
  PitchOperatingMode v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // eax

  v2 = FLOAT_N2400_0;
  v3 = in_fPitchVal;
  v4 = this;
  if ( in_fPitchVal <= -2400.0 || (v2 = FLOAT_2400_0, in_fPitchVal >= 2400.0) )
    v3 = v2;
  if ( this->m_bFirstSetPitch )
  {
    v5 = powf(2.0, v3 * 0.00083333335);
    v4->m_fTargetPitchVal = v3;
    v4->m_InternalPitchState.uInterpolationRampCount = 1024;
    v4->m_bFirstSetPitch = 0;
    v6 = (float)((float)(v5 * v4->m_fSampleRateConvertRatio) * 65536.0) + 0.5;
    v4->m_InternalPitchState.uCurrentFrameSkip = (signed int)v6;
    v4->m_InternalPitchState.uTargetFrameSkip = (signed int)v6;
  }
  v7 = 0;
  if ( v3 != v4->m_fTargetPitchVal )
  {
    if ( v4->m_PitchOperationMode == 2 )
      v4->m_InternalPitchState.uCurrentFrameSkip += (signed int)(v4->m_InternalPitchState.uInterpolationRampCount
                                                               * (v4->m_InternalPitchState.uTargetFrameSkip
                                                                - v4->m_InternalPitchState.uCurrentFrameSkip))
                                                  / 1024;
    v4->m_InternalPitchState.uInterpolationRampCount = 0;
    v8 = powf(2.0, v3 * 0.00083333335);
    v4->m_fTargetPitchVal = v3;
    v4->m_InternalPitchState.uTargetFrameSkip = (signed int)(float)((float)((float)(v8 * v4->m_fSampleRateConvertRatio)
                                                                          * 65536.0)
                                                                  + 0.5);
  }
  v9 = v4->m_InternalPitchState.uCurrentFrameSkip;
  if ( v9 == v4->m_InternalPitchState.uTargetFrameSkip )
  {
    LOBYTE(v7) = v9 != 0x10000;
    v4->m_PitchOperationMode = v7;
  }
  else
  {
    v4->m_PitchOperationMode = 2;
  }
}

// File Line: 678
// RVA: 0xA91990
void __fastcall CAkResampler::SetPitchForTimeSkip(CAkResampler *this, float in_fPitchVal)
{
  CAkResampler *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  signed int v6; // eax

  v2 = this;
  v3 = in_fPitchVal;
  if ( this->m_bFirstSetPitch || in_fPitchVal != this->m_fTargetPitchVal )
  {
    v4 = FLOAT_N2400_0;
    if ( in_fPitchVal <= -2400.0 || (v4 = FLOAT_2400_0, in_fPitchVal >= 2400.0) )
      v3 = v4;
    v5 = powf(2.0, v3 * 0.00083333335);
    v2->m_fTargetPitchVal = v3;
    v2->m_InternalPitchState.uInterpolationRampCount = 1024;
    v2->m_bFirstSetPitch = 0;
    v6 = (signed int)(float)((float)((float)(v5 * v2->m_fSampleRateConvertRatio) * 65536.0) + 0.5);
    v2->m_InternalPitchState.uCurrentFrameSkip = v6;
    v2->m_InternalPitchState.uTargetFrameSkip = v6;
  }
}

