// File Line: 75
// RVA: 0xA97F00
void __fastcall AkSpeakerDownmixVolumesDelta::AkSpeakerDownmixVolumesDelta(
        AkSpeakerDownmixVolumesDelta *this,
        AkAudioMix *audioMix,
        unsigned int in_uOutputConfig,
        unsigned int in_uNumFullBandOutputChannels,
        float in_fOneOverNumSamples)
{
  unsigned int v6; // r10d
  AkSpeakerVolumes *v7; // r11
  int v8; // r9d
  unsigned int v9; // r10d
  __int64 v10; // rax
  signed __int64 v11; // rdx
  unsigned int v12; // eax
  float *v13; // rcx
  __int64 v14; // r8
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float *v20; // rax
  __int64 v21; // rdx
  float v22; // xmm0_4
  float out_fOutputVolumes; // [rsp+20h] [rbp-28h] BYREF
  char v24; // [rsp+24h] [rbp-24h] BYREF
  char v25; // [rsp+28h] [rbp-20h] BYREF

  AkDownmix::ComputeVolumes((AkSpeakerVolumes *)&audioMix->Previous, in_uOutputConfig, this->fOutputVolumes);
  AkDownmix::ComputeVolumes(v7, v6, &out_fOutputVolumes);
  v9 = 0;
  v10 = 0i64;
  if ( v8 >= 4 )
  {
    v11 = (char *)&out_fOutputVolumes - (char *)this;
    v12 = ((unsigned int)(v8 - 4) >> 2) + 1;
    v13 = &this->fOutputVolumes[1];
    v9 = 4 * v12;
    v14 = v12;
    v10 = 4i64 * v12;
    do
    {
      v15 = *(float *)((char *)v13 + v11 - 4);
      v16 = *(float *)((char *)v13 + v11);
      v13 += 4;
      v17 = (float)(v16 - *(v13 - 4)) * in_fOneOverNumSamples;
      v13[3] = (float)(v15 - *(v13 - 5)) * in_fOneOverNumSamples;
      v18 = *(float *)((char *)v13 + &v24 - (char *)this - 16);
      v13[4] = v17;
      v19 = *(float *)((char *)v13 + &v25 - (char *)this - 16) - *(v13 - 2);
      v13[5] = (float)(v18 - *(v13 - 3)) * in_fOneOverNumSamples;
      v13[6] = v19 * in_fOneOverNumSamples;
      --v14;
    }
    while ( v14 );
  }
  if ( v9 < v8 )
  {
    v20 = &out_fOutputVolumes + v10;
    v21 = v8 - v9;
    do
    {
      v22 = *v20++;
      *(float *)((char *)v20 + (char *)this - (char *)&out_fOutputVolumes + 28) = (float)(v22
                                                                                        - *(float *)((char *)v20 + (char *)this - (char *)&out_fOutputVolumes - 4))
                                                                                * in_fOneOverNumSamples;
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 132
// RVA: 0xA7E7F0
void __fastcall CAkMixer::Mix(
        CAkMixer *this,
        AkAudioBufferBus *in_pInputBuffer,
        AkPipelineBufferBase *io_pOutputBuffer,
        bool in_bPan,
        AkAudioMix *in_PanMix)
{
  unsigned int uChannelMask; // r10d
  unsigned int v9; // ebp
  float m_fPreviousVolume; // xmm7_4
  unsigned int v11; // ebx
  float i; // xmm6_4

  uChannelMask = io_pOutputBuffer->uChannelMask;
  if ( in_pInputBuffer->uChannelMask != uChannelMask || in_bPan )
  {
    CAkMixer::Mix3D(this, in_pInputBuffer, io_pOutputBuffer, in_PanMix);
  }
  else
  {
    v9 = 0;
    m_fPreviousVolume = in_pInputBuffer->m_fPreviousVolume;
    v11 = 0;
    for ( i = (float)(in_pInputBuffer->m_fNextVolume - m_fPreviousVolume) * this->m_fOneOverNumFrames;
          uChannelMask;
          uChannelMask &= uChannelMask - 1 )
    {
      ++v11;
    }
    do
    {
      CAkMixer::MixChannelSIMD(
        (float *)in_pInputBuffer->pData + v9 * (unsigned __int64)in_pInputBuffer->uMaxFrames,
        (float *)io_pOutputBuffer->pData + v9 * (unsigned __int64)io_pOutputBuffer->uMaxFrames,
        m_fPreviousVolume,
        i,
        this->m_usMaxFrames);
      ++v9;
    }
    while ( v9 < v11 );
  }
  io_pOutputBuffer->uValidFrames = this->m_usMaxFrames;
}

