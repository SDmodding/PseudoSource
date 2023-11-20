// File Line: 29
// RVA: 0xA98030
void __fastcall CAkMixer::CAkMixer(CAkMixer *this)
{
  this->m_usMaxFrames = 0;
  this->m_fOneOverNumFrames = 0.0;
}

// File Line: 34
// RVA: 0xA982E0
void __fastcall CAkMixer::DownMix(AkPipelineBufferBase *in_pInputBuffer, AkPipelineBufferBase *in_pOutputBuffer, AkSIMDSpeakerVolumes *in_volumes, unsigned int in_uNumSamples)
{
  unsigned int v4; // ebp
  unsigned int v5; // er14
  AkSIMDSpeakerVolumes *v6; // r11
  AkPipelineBufferBase *v7; // rdi
  AkPipelineBufferBase *v8; // r9
  unsigned int v9; // er10
  unsigned int v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  __int64 v13; // r12
  AkSIMDSpeakerVolumes *v14; // r13
  float *v15; // r15
  __int64 v16; // rbx
  __int64 v17; // [rsp+20h] [rbp-78h]
  float out_fOutputVolumes[12]; // [rsp+28h] [rbp-70h]
  AkPipelineBufferBase *v19; // [rsp+A0h] [rbp+8h]
  unsigned int v20; // [rsp+A8h] [rbp+10h]
  AkSIMDSpeakerVolumes *v21; // [rsp+B0h] [rbp+18h]
  unsigned int v22; // [rsp+B8h] [rbp+20h]

  v21 = in_volumes;
  v19 = in_pInputBuffer;
  v4 = 0;
  v5 = in_uNumSamples;
  v6 = in_volumes;
  v7 = in_pOutputBuffer;
  v8 = in_pInputBuffer;
  v22 = 0;
  v9 = in_pInputBuffer->uChannelMask & 0xFFFFFFF7;
  if ( v9 )
  {
    do
    {
      ++v4;
      v9 &= v9 - 1;
    }
    while ( v9 );
    v22 = v4;
  }
  v10 = 0;
  v11 = in_pOutputBuffer->uChannelMask & 0xFFFFFFF7;
  v20 = v11;
  v12 = v11;
  if ( v11 )
  {
    do
    {
      ++v10;
      v12 &= v12 - 1;
    }
    while ( v12 );
    if ( v10 && v4 )
    {
      v13 = 0i64;
      v14 = in_volumes;
      v17 = v4;
      do
      {
        v15 = (float *)((char *)v19->pData + 4 * v13 * v19->uMaxFrames);
        AkDownmix::ComputeVolumes((AkSpeakerVolumes *)v14, v11, out_fOutputVolumes);
        v16 = 0i64;
        do
        {
          CAkMixer::MixChannel(
            v15,
            (float *)v7->pData + (unsigned int)v16 * (unsigned __int64)v7->uMaxFrames,
            out_fOutputVolumes[v16],
            v5);
          v16 = (unsigned int)(v16 + 1);
        }
        while ( (unsigned int)v16 < v10 );
        v11 = v20;
        ++v13;
        ++v14;
        --v17;
      }
      while ( v17 );
      v4 = v22;
      v8 = v19;
      v6 = v21;
    }
  }
  if ( v8->uChannelMask & 8 && v7->uChannelMask & 8 )
    CAkMixer::MixChannel(
      (float *)v8->pData + v4 * (unsigned __int64)v8->uMaxFrames,
      (float *)v7->pData + v10 * (unsigned __int64)v7->uMaxFrames,
      v6[v4].volumes.fLfe,
      v5);
  v7->uValidFrames = v5;
}

// File Line: 86
// RVA: 0xA98640
void __fastcall CAkMixer::MixChannel(float *in_pSourceData, float *in_pDestData, float in_fVolume, unsigned int in_uNumSamples)
{
  __int64 v4; // rbx
  unsigned int v5; // edi
  float *v6; // rsi
  float *v7; // r14
  __int64 v8; // rdi
  unsigned __int64 v9; // rcx
  signed __int64 v10; // r8
  unsigned __int64 v11; // r9
  float v12; // xmm1_4
  float v13; // xmm1_4
  unsigned __int64 v14; // r8

  v4 = in_uNumSamples & 0xFFFFFFF8;
  v5 = in_uNumSamples;
  v6 = in_pDestData;
  v7 = in_pSourceData;
  CAkMixer::MixChannelSIMD(in_pSourceData, in_pDestData, in_fVolume, 0.0, in_uNumSamples & 0xFFFFFFF8);
  v8 = v5 - (unsigned int)v4;
  if ( (_DWORD)v8 )
  {
    v9 = (unsigned __int64)&v7[v4];
    v10 = (signed __int64)&v6[v4];
    v11 = v9 + 4i64 * (unsigned int)v8;
    if ( v9 < v11 )
    {
      if ( (4 * v8 + 3) / 4 >= 4 )
      {
        do
        {
          v9 += 16i64;
          v10 += 16i64;
          v12 = (float)(in_fVolume * *(float *)(v9 - 12)) + *(float *)(v10 - 12);
          *(float *)(v10 - 16) = (float)(in_fVolume * *(float *)(v9 - 16)) + *(float *)(v10 - 16);
          *(float *)(v10 - 12) = v12;
          v13 = (float)(in_fVolume * *(float *)(v9 - 4)) + *(float *)(v10 - 4);
          *(float *)(v10 - 8) = (float)(in_fVolume * *(float *)(v9 - 8)) + *(float *)(v10 - 8);
          *(float *)(v10 - 4) = v13;
        }
        while ( (signed __int64)v9 < (signed __int64)(v11 - 12) );
      }
      if ( v9 < v11 )
      {
        v14 = v10 - v9;
        do
        {
          v9 += 4i64;
          *(float *)(v14 + v9 - 4) = (float)(in_fVolume * *(float *)(v9 - 4)) + *(float *)(v14 + v9 - 4);
        }
        while ( v9 < v11 );
      }
    }
  }
}

// File Line: 112
// RVA: 0xA98470
void __fastcall CAkMixer::Mix3D(CAkMixer *this, AkPipelineBufferBase *in_pInputBuffer, AkPipelineBufferBase *in_pOutputBuffer, AkAudioMix *in_audioMix)
{
  __int64 v4; // rbp
  AkAudioMix *v5; // rbx
  AkPipelineBufferBase *v6; // rsi
  AkPipelineBufferBase *v7; // r11
  CAkMixer *v8; // r14
  unsigned int v9; // er10
  unsigned int v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  AkAudioMix *v13; // r12
  __int64 v14; // r15
  float *v15; // r13
  __int64 v16; // rbx
  AkSpeakerDownmixVolumesDelta v17; // [rsp+40h] [rbp-88h]
  int v18; // [rsp+D0h] [rbp+8h]
  AkPipelineBufferBase *v19; // [rsp+D8h] [rbp+10h]
  unsigned int v20; // [rsp+E0h] [rbp+18h]
  AkAudioMix *v21; // [rsp+E8h] [rbp+20h]

  v21 = in_audioMix;
  v19 = in_pInputBuffer;
  LODWORD(v4) = 0;
  v5 = in_audioMix;
  v6 = in_pOutputBuffer;
  v7 = in_pInputBuffer;
  v8 = this;
  v18 = 0;
  v9 = in_pInputBuffer->uChannelMask & 0xFFFFFFF7;
  if ( v9 )
  {
    do
    {
      LODWORD(v4) = v4 + 1;
      v9 &= v9 - 1;
    }
    while ( v9 );
    v18 = v4;
  }
  v10 = 0;
  v11 = in_pOutputBuffer->uChannelMask & 0xFFFFFFF7;
  v20 = in_pOutputBuffer->uChannelMask & 0xFFFFFFF7;
  v12 = in_pOutputBuffer->uChannelMask & 0xFFFFFFF7;
  if ( v11 )
  {
    do
    {
      ++v10;
      v12 &= v12 - 1;
    }
    while ( v12 );
  }
  if ( (_DWORD)v4 )
  {
    v13 = in_audioMix;
    v14 = 0i64;
    v4 = (unsigned int)v4;
    do
    {
      v15 = (float *)((char *)v7->pData + 4 * v14 * v7->uMaxFrames);
      AkSpeakerDownmixVolumesDelta::AkSpeakerDownmixVolumesDelta(&v17, v13, v11, v10, v8->m_fOneOverNumFrames);
      v16 = 0i64;
      do
      {
        CAkMixer::MixChannelSIMD(
          v15,
          (float *)v6->pData + (unsigned int)v16 * (unsigned __int64)v6->uMaxFrames,
          v17.fOutputVolumes[v16],
          v17.fOutputVolumeDeltas[v16],
          v8->m_usMaxFrames);
        v16 = (unsigned int)(v16 + 1);
      }
      while ( (unsigned int)v16 < v10 );
      v7 = v19;
      v11 = v20;
      ++v14;
      ++v13;
      --v4;
    }
    while ( v4 );
    LODWORD(v4) = v18;
    v5 = v21;
  }
  if ( v7->uChannelMask & 8 && v6->uChannelMask & 8 )
    CAkMixer::MixChannelSIMD(
      (float *)v7->pData + (unsigned int)v4 * (unsigned __int64)v7->uMaxFrames,
      (float *)v6->pData + v10 * (unsigned __int64)v6->uMaxFrames,
      v5[(unsigned __int64)(unsigned int)v4].Previous.volumes.fLfe,
      (float)(v5[(unsigned __int64)(unsigned int)v4].Next.volumes.fLfe
            - v5[(unsigned __int64)(unsigned int)v4].Previous.volumes.fLfe)
    * v8->m_fOneOverNumFrames,
      v8->m_usMaxFrames);
  v6->uValidFrames = v8->m_usMaxFrames;
}

// File Line: 164
// RVA: 0xA98780
void __fastcall CAkMixer::MixFinalStereo(CAkMixer *this, AkAudioBufferBus *in_pInputBuffer, AkPipelineBufferBase *in_pOutputBuffer)
{
  CAkMixer::MixAndInterleaveStereo(this, in_pInputBuffer, in_pOutputBuffer);
}

// File Line: 193
// RVA: 0xA98760
void __fastcall CAkMixer::MixFinal51(CAkMixer *this, AkAudioBufferBus *in_pInputBuffer, AkPipelineBufferBase *in_pOutputBuffer)
{
  CAkMixer::MixAndInterleave51(this, in_pInputBuffer, in_pOutputBuffer);
}

// File Line: 218
// RVA: 0xA98770
void __fastcall CAkMixer::MixFinal71(CAkMixer *this, AkAudioBufferBus *in_pInputBuffer, AkPipelineBufferBase *in_pOutputBuffer)
{
  CAkMixer::MixAndInterleave71(this, in_pInputBuffer, in_pOutputBuffer);
}

