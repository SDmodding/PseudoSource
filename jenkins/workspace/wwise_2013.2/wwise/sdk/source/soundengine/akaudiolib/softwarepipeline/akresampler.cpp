// File Line: 230
// RVA: 0xA91680
float __fastcall CAkResampler::GetLastRate(CAkResampler *this)
{
  return (float)((float)(int)this->m_InternalPitchState.uCurrentFrameSkip * 0.000015258789)
       / this->m_fSampleRateConvertRatio;
}

// File Line: 281
// RVA: 0xA91A20
void __fastcall CAkResampler::SwitchTo(
        CAkResampler *this,
        AkAudioFormat *in_fmt,
        float in_fPitch,
        AkPipelineBufferBase *io_pIOBuffer,
        signed int in_uSampleRate)
{
  char m_DSPFunctionIndex; // di
  unsigned int m_uNumChannels; // eax
  int *v10; // rcx
  CAkResampler *v11; // rdx
  __int64 v12; // r8
  int v13; // eax
  bool v14; // di
  float v15; // xmm1_4
  int v16; // eax
  char v17; // al
  char v18; // al
  char v19; // al
  bool v20; // zf
  char v21; // al
  __int64 i; // rdx
  __int64 v23; // rdx
  float v24; // xmm0_4
  float Dst[8]; // [rsp+20h] [rbp-38h] BYREF

  m_DSPFunctionIndex = this->m_DSPFunctionIndex;
  if ( (unsigned __int8)m_DSPFunctionIndex < 4u )
  {
    m_uNumChannels = (unsigned __int8)this->m_uNumChannels;
    if ( this->m_uNumChannels )
    {
      v10 = (int *)Dst;
      v11 = this;
      v12 = m_uNumChannels;
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
  else if ( (unsigned __int8)(m_DSPFunctionIndex - 4) <= 3u && this->m_uNumChannels )
  {
    memmove(Dst, this, 4i64 * (unsigned __int8)this->m_uNumChannels);
  }
  v14 = this->m_PitchOperationMode == PitchOperatingMode_Bypass
     && this->m_uNumChannels > 2u
     && (unsigned __int8)(m_DSPFunctionIndex - 4) > 3u;
  v15 = (float)(int)in_fmt->uSampleRate / (float)in_uSampleRate;
  if ( v15 != this->m_fSampleRateConvertRatio )
  {
    this->m_fSampleRateConvertRatio = v15;
    this->m_bFirstSetPitch = 1;
  }
  CAkResampler::SetPitch(this, in_fPitch);
  this->m_uInputBlockAlign = *((_BYTE *)in_fmt + 7) & 0x1F;
  v16 = (*((_DWORD *)in_fmt + 1) >> 18) & 0x3F;
  if ( v16 == 16 )
  {
    v19 = this->m_uNumChannels;
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
    v18 = this->m_uNumChannels;
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
  v20 = this->m_PitchOperationMode == PitchOperatingMode_Bypass;
  this->m_DSPFunctionIndex = v17;
  if ( v20 && this->m_uNumChannels > 2u && (unsigned __int8)(v17 - 4) > 3u )
  {
    if ( !v14 )
      CAkResampler::InterleaveAndSwapOutput(this, io_pIOBuffer);
  }
  else if ( v14 )
  {
    CAkResampler::DeinterleaveAndSwapOutput(this, io_pIOBuffer);
  }
  v21 = this->m_DSPFunctionIndex;
  if ( (unsigned __int8)v21 < 4u )
  {
    v23 = 0i64;
    if ( !this->m_uNumChannels )
      return;
    while ( 1 )
    {
      v24 = Dst[v23] * 32767.0;
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
      this->m_InternalPitchState.iLastValue[v23] = (int)v24;
      v23 = (unsigned int)(v23 + 1);
      if ( (unsigned int)v23 >= (unsigned __int8)this->m_uNumChannels )
        return;
    }
    v24 = FLOAT_32767_0;
    goto LABEL_46;
  }
  if ( (unsigned __int8)(v21 - 4) <= 3u )
  {
    for ( i = 0i64; (unsigned int)i < (unsigned __int8)this->m_uNumChannels; i = (unsigned int)(i + 1) )
      this->m_InternalPitchState.fLastValue[i] = Dst[i];
  }
}

// File Line: 381
// RVA: 0xA916A0
void __fastcall CAkResampler::Init(CAkResampler *this, AkAudioFormat *io_pFormat, int in_uSampleRate)
{
  char v5; // cl
  int i; // edx
  int v7; // eax

  *(_QWORD *)&this->m_InternalPitchState.uFloatIndex = 0x10000i64;
  this->m_bFirstSetPitch = 1;
  *(_QWORD *)&this->m_InternalPitchState.uInFrameOffset = 0i64;
  *(_QWORD *)&this->m_InternalPitchState.uTargetFrameSkip = 0i64;
  this->m_InternalPitchState.uInterpolationRampInc = 0xBB80u / in_uSampleRate;
  this->m_fTargetPitchVal = 0.0;
  this->m_fSampleRateConvertRatio = (float)(int)io_pFormat->uSampleRate / (float)in_uSampleRate;
  v5 = 0;
  for ( i = *((_DWORD *)io_pFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v5;
  this->m_uNumChannels = v5;
  this->m_uInputBlockAlign = *((_BYTE *)io_pFormat + 7) & 0x1F;
  v7 = (*((_DWORD *)io_pFormat + 1) >> 18) & 0x3F;
  if ( v7 == 16 )
  {
    if ( v5 == 1 )
    {
      this->m_PitchOperationMode = PitchOperatingMode_Bypass;
      this->m_DSPFunctionIndex = 0;
    }
    else
    {
      this->m_PitchOperationMode = PitchOperatingMode_Bypass;
      if ( v5 == 2 )
        this->m_DSPFunctionIndex = 1;
      else
        this->m_DSPFunctionIndex = ((unsigned __int8)(v5 - 3) > 1u) + 2;
    }
  }
  else if ( v7 == 32 )
  {
    if ( v5 == 1 )
    {
      this->m_PitchOperationMode = PitchOperatingMode_Bypass;
      this->m_DSPFunctionIndex = 4;
    }
    else
    {
      this->m_PitchOperationMode = PitchOperatingMode_Bypass;
      if ( v5 == 2 )
        this->m_DSPFunctionIndex = 5;
      else
        this->m_DSPFunctionIndex = ((unsigned __int8)(v5 - 3) > 1u) + 6;
    }
  }
  else
  {
    this->m_DSPFunctionIndex = -1;
    this->m_PitchOperationMode = PitchOperatingMode_Bypass;
  }
}

// File Line: 492
// RVA: 0xA915D0
__int64 __fastcall CAkResampler::Execute(CAkResampler *this, AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer)
{
  AKRESULT v7; // edx
  unsigned int uTargetFrameSkip; // ecx

  if ( !io_pInBuffer->uValidFrames )
    return 17i64;
  do
  {
    v7 = PitchDSPFuncTable[this->m_PitchOperationMode][(unsigned __int8)this->m_DSPFunctionIndex](
           io_pInBuffer,
           io_pOutBuffer,
           this->m_InternalPitchState.uRequestedFrames,
           (AkInternalPitchState *)this);
    if ( this->m_PitchOperationMode == PitchOperatingMode_Interpolating
      && this->m_InternalPitchState.uInterpolationRampCount >= 0x400 )
    {
      uTargetFrameSkip = this->m_InternalPitchState.uTargetFrameSkip;
      this->m_PitchOperationMode = PitchOperatingMode_Fixed;
      this->m_InternalPitchState.uCurrentFrameSkip = uTargetFrameSkip;
    }
  }
  while ( io_pInBuffer->uValidFrames && io_pOutBuffer->uValidFrames < this->m_InternalPitchState.uRequestedFrames );
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
__int64 __fastcall CAkResampler::DeinterleaveAndSwapOutput(CAkResampler *this, AkPipelineBufferBase *io_pIOBuffer)
{
  unsigned int uChannelMask; // r8d
  void *pData; // rax
  unsigned __int16 uMaxFrames; // dx
  __int64 result; // rax
  AkAudioBuffer io_pOutBuffer; // [rsp+20h] [rbp-48h] BYREF
  AkAudioBuffer v8; // [rsp+38h] [rbp-30h]
  void *v9; // [rsp+50h] [rbp-18h]

  uChannelMask = io_pIOBuffer->uChannelMask;
  io_pOutBuffer = io_pIOBuffer->AkAudioBuffer;
  v8 = io_pIOBuffer[1].AkAudioBuffer;
  pData = io_pIOBuffer[2].pData;
  uMaxFrames = io_pIOBuffer->uMaxFrames;
  v9 = pData;
  result = AkPipelineBufferBase::GetCachedBuffer((AkPipelineBufferBase *)&io_pOutBuffer, uMaxFrames, uChannelMask);
  if ( (_DWORD)result == 1 )
  {
    io_pOutBuffer.uValidFrames = io_pIOBuffer->uValidFrames;
    Deinterleave_Native_NChan(io_pIOBuffer, &io_pOutBuffer);
    AkPipelineBufferBase::ReleaseCachedBuffer(io_pIOBuffer);
    *io_pIOBuffer = (AkPipelineBufferBase)io_pOutBuffer;
    return 1i64;
  }
  return result;
}

// File Line: 569
// RVA: 0xA917A0
__int64 __fastcall CAkResampler::InterleaveAndSwapOutput(CAkResampler *this, AkPipelineBufferBase *io_pIOBuffer)
{
  unsigned int uChannelMask; // r8d
  void *pData; // rax
  unsigned __int16 uMaxFrames; // dx
  __int64 result; // rax
  AkAudioBuffer io_pOutBuffer; // [rsp+20h] [rbp-48h] BYREF
  AkAudioBuffer v8; // [rsp+38h] [rbp-30h]
  void *v9; // [rsp+50h] [rbp-18h]

  uChannelMask = io_pIOBuffer->uChannelMask;
  io_pOutBuffer = io_pIOBuffer->AkAudioBuffer;
  v8 = io_pIOBuffer[1].AkAudioBuffer;
  pData = io_pIOBuffer[2].pData;
  uMaxFrames = io_pIOBuffer->uMaxFrames;
  v9 = pData;
  result = AkPipelineBufferBase::GetCachedBuffer((AkPipelineBufferBase *)&io_pOutBuffer, uMaxFrames, uChannelMask);
  if ( (_DWORD)result == 1 )
  {
    io_pOutBuffer.uValidFrames = io_pIOBuffer->uValidFrames;
    Interleave_Native_NChan(io_pIOBuffer, &io_pOutBuffer);
    AkPipelineBufferBase::ReleaseCachedBuffer(io_pIOBuffer);
    *io_pIOBuffer = (AkPipelineBufferBase)io_pOutBuffer;
    return 1i64;
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
  float v5; // xmm0_4
  float v6; // xmm0_4
  PitchOperatingMode v7; // edi
  float v8; // xmm0_4
  unsigned int uCurrentFrameSkip; // eax

  v2 = FLOAT_N2400_0;
  v3 = in_fPitchVal;
  if ( in_fPitchVal <= -2400.0 || (v2 = FLOAT_2400_0, in_fPitchVal >= 2400.0) )
    v3 = v2;
  if ( this->m_bFirstSetPitch )
  {
    v5 = powf(2.0, v3 * 0.00083333335);
    this->m_fTargetPitchVal = v3;
    this->m_InternalPitchState.uInterpolationRampCount = 1024;
    this->m_bFirstSetPitch = 0;
    v6 = (float)((float)(v5 * this->m_fSampleRateConvertRatio) * 65536.0) + 0.5;
    this->m_InternalPitchState.uCurrentFrameSkip = (int)v6;
    this->m_InternalPitchState.uTargetFrameSkip = (int)v6;
  }
  v7 = PitchOperatingMode_Bypass;
  if ( v3 != this->m_fTargetPitchVal )
  {
    if ( this->m_PitchOperationMode == PitchOperatingMode_Interpolating )
      this->m_InternalPitchState.uCurrentFrameSkip += (signed int)(this->m_InternalPitchState.uInterpolationRampCount
                                                                 * (this->m_InternalPitchState.uTargetFrameSkip
                                                                  - this->m_InternalPitchState.uCurrentFrameSkip))
                                                    / 1024;
    this->m_InternalPitchState.uInterpolationRampCount = 0;
    v8 = powf(2.0, v3 * 0.00083333335);
    this->m_fTargetPitchVal = v3;
    this->m_InternalPitchState.uTargetFrameSkip = (int)(float)((float)((float)(v8 * this->m_fSampleRateConvertRatio)
                                                                     * 65536.0)
                                                             + 0.5);
  }
  uCurrentFrameSkip = this->m_InternalPitchState.uCurrentFrameSkip;
  if ( uCurrentFrameSkip == this->m_InternalPitchState.uTargetFrameSkip )
  {
    LOBYTE(v7) = uCurrentFrameSkip != 0x10000;
    this->m_PitchOperationMode = v7;
  }
  else
  {
    this->m_PitchOperationMode = PitchOperatingMode_Interpolating;
  }
}

// File Line: 678
// RVA: 0xA91990
void __fastcall CAkResampler::SetPitchForTimeSkip(CAkResampler *this, float in_fPitchVal)
{
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  unsigned int v6; // eax

  v3 = in_fPitchVal;
  if ( this->m_bFirstSetPitch || in_fPitchVal != this->m_fTargetPitchVal )
  {
    v4 = FLOAT_N2400_0;
    if ( in_fPitchVal <= -2400.0 || (v4 = FLOAT_2400_0, in_fPitchVal >= 2400.0) )
      v3 = v4;
    v5 = powf(2.0, v3 * 0.00083333335);
    this->m_fTargetPitchVal = v3;
    this->m_InternalPitchState.uInterpolationRampCount = 1024;
    this->m_bFirstSetPitch = 0;
    v6 = (int)(float)((float)((float)(v5 * this->m_fSampleRateConvertRatio) * 65536.0) + 0.5);
    this->m_InternalPitchState.uCurrentFrameSkip = v6;
    this->m_InternalPitchState.uTargetFrameSkip = v6;
  }
}

