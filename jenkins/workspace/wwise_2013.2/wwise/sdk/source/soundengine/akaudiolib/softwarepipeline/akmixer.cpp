// File Line: 29
// RVA: 0xA98030
void __fastcall CAkMixer::CAkMixer(CAkMixer *this)
{
  this->m_usMaxFrames = 0;
  this->m_fOneOverNumFrames = 0.0;
}

// File Line: 34
// RVA: 0xA982E0
void __fastcall CAkMixer::DownMix(
        AkPipelineBufferBase *in_pInputBuffer,
        AkPipelineBufferBase *in_pOutputBuffer,
        AkSIMDSpeakerVolumes *in_volumes,
        unsigned int in_uNumSamples)
{
  unsigned int v4; // ebp
  AkSIMDSpeakerVolumes *v6; // r11
  AkPipelineBufferBase *v8; // r9
  unsigned int v9; // r10d
  unsigned int v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  __int64 v13; // r12
  AkSIMDSpeakerVolumes *v14; // r13
  float *v15; // r15
  __int64 v16; // rbx
  __int64 v17; // [rsp+20h] [rbp-78h]
  float out_fOutputVolumes[12]; // [rsp+28h] [rbp-70h] BYREF
  unsigned int v20; // [rsp+A8h] [rbp+10h]
  unsigned int v22; // [rsp+B8h] [rbp+20h]

  v4 = 0;
  v6 = in_volumes;
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
        v15 = (float *)((char *)in_pInputBuffer->pData + 4 * v13 * in_pInputBuffer->uMaxFrames);
        AkDownmix::ComputeVolumes((AkSpeakerVolumes *)v14, v11, out_fOutputVolumes);
        v16 = 0i64;
        do
        {
          CAkMixer::MixChannel(
            v15,
            (float *)in_pOutputBuffer->pData + (unsigned int)v16 * (unsigned __int64)in_pOutputBuffer->uMaxFrames,
            out_fOutputVolumes[v16],
            in_uNumSamples);
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
      v8 = in_pInputBuffer;
      v6 = in_volumes;
    }
  }
  if ( (v8->uChannelMask & 8) != 0 && (in_pOutputBuffer->uChannelMask & 8) != 0 )
    CAkMixer::MixChannel(
      (float *)v8->pData + v4 * (unsigned __int64)v8->uMaxFrames,
      (float *)in_pOutputBuffer->pData + v10 * (unsigned __int64)in_pOutputBuffer->uMaxFrames,
      v6[v4].vector[1].m128_f32[3],
      in_uNumSamples);
  in_pOutputBuffer->uValidFrames = in_uNumSamples;
}

// File Line: 86
// RVA: 0xA98640
void __fastcall CAkMixer::MixChannel(
        float *in_pSourceData,
        float *in_pDestData,
        float in_fVolume,
        unsigned int in_uNumSamples)
{
  __int64 v4; // rbx
  __int64 v8; // rdi
  float *v9; // rcx
  float *v10; // r8
  float *v11; // r9
  float v12; // xmm1_4
  float v13; // xmm1_4
  signed __int64 v14; // r8

  v4 = in_uNumSamples & 0xFFFFFFF8;
  CAkMixer::MixChannelSIMD(in_pSourceData, in_pDestData, in_fVolume, 0.0, in_uNumSamples & 0xFFFFFFF8);
  v8 = in_uNumSamples - (unsigned int)v4;
  if ( (_DWORD)v8 )
  {
    v9 = &in_pSourceData[v4];
    v10 = &in_pDestData[v4];
    v11 = &v9[(unsigned int)v8];
    if ( v9 < v11 )
    {
      if ( (4 * v8 + 3) / 4 >= 4 )
      {
        do
        {
          v9 += 4;
          v10 += 4;
          v12 = (float)(in_fVolume * *(v9 - 3)) + *(v10 - 3);
          *(v10 - 4) = (float)(in_fVolume * *(v9 - 4)) + *(v10 - 4);
          *(v10 - 3) = v12;
          v13 = (float)(in_fVolume * *(v9 - 1)) + *(v10 - 1);
          *(v10 - 2) = (float)(in_fVolume * *(v9 - 2)) + *(v10 - 2);
          *(v10 - 1) = v13;
        }
        while ( (__int64)v9 < (__int64)(v11 - 3) );
      }
      if ( v9 < v11 )
      {
        v14 = (char *)v10 - (char *)v9;
        do
        {
          ++v9;
          *(float *)((char *)v9 + v14 - 4) = (float)(in_fVolume * *(v9 - 1)) + *(float *)((char *)v9 + v14 - 4);
        }
        while ( v9 < v11 );
      }
    }
  }
}

// File Line: 112
// RVA: 0xA98470
void __fastcall CAkMixer::Mix3D(
        CAkMixer *this,
        AkPipelineBufferBase *in_pInputBuffer,
        AkPipelineBufferBase *in_pOutputBuffer,
        AkAudioMix *in_audioMix)
{
  __int64 v4; // rbp
  AkAudioMix *v5; // rbx
  AkPipelineBufferBase *v7; // r11
  unsigned int v9; // r10d
  unsigned int v10; // edi
  unsigned int v11; // edx
  unsigned int i; // ecx
  AkAudioMix *v13; // r12
  __int64 v14; // r15
  float *v15; // r13
  __int64 v16; // rbx
  AkSpeakerDownmixVolumesDelta v17; // [rsp+40h] [rbp-88h] BYREF
  int v18; // [rsp+D0h] [rbp+8h]
  unsigned int v20; // [rsp+E0h] [rbp+18h]

  LODWORD(v4) = 0;
  v5 = in_audioMix;
  v7 = in_pInputBuffer;
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
  v20 = v11;
  for ( i = v11; i; i &= i - 1 )
    ++v10;
  if ( (_DWORD)v4 )
  {
    v13 = in_audioMix;
    v14 = 0i64;
    v4 = (unsigned int)v4;
    do
    {
      v15 = (float *)((char *)v7->pData + 4 * v14 * v7->uMaxFrames);
      AkSpeakerDownmixVolumesDelta::AkSpeakerDownmixVolumesDelta(&v17, v13, v11, v10, this->m_fOneOverNumFrames);
      v16 = 0i64;
      do
      {
        CAkMixer::MixChannelSIMD(
          v15,
          (float *)in_pOutputBuffer->pData + (unsigned int)v16 * (unsigned __int64)in_pOutputBuffer->uMaxFrames,
          v17.fOutputVolumes[v16],
          v17.fOutputVolumeDeltas[v16],
          this->m_usMaxFrames);
        v16 = (unsigned int)(v16 + 1);
      }
      while ( (unsigned int)v16 < v10 );
      v7 = in_pInputBuffer;
      v11 = v20;
      ++v14;
      ++v13;
      --v4;
    }
    while ( v4 );
    LODWORD(v4) = v18;
    v5 = in_audioMix;
  }
  if ( (v7->uChannelMask & 8) != 0 && (in_pOutputBuffer->uChannelMask & 8) != 0 )
    CAkMixer::MixChannelSIMD(
      (float *)v7->pData + (unsigned int)v4 * (unsigned __int64)v7->uMaxFrames,
      (float *)in_pOutputBuffer->pData + v10 * (unsigned __int64)in_pOutputBuffer->uMaxFrames,
      v5[(unsigned __int64)(unsigned int)v4].Previous.vector[1].m128_f32[3],
      (float)(v5[(unsigned __int64)(unsigned int)v4].Next.vector[1].m128_f32[3]
            - v5[(unsigned __int64)(unsigned int)v4].Previous.vector[1].m128_f32[3])
    * this->m_fOneOverNumFrames,
      this->m_usMaxFrames);
  in_pOutputBuffer->uValidFrames = this->m_usMaxFrames;
}

// File Line: 164
// RVA: 0xA98780
// attributes: thunk
void __fastcall CAkMixer::MixFinalStereo(
        CAkMixer *this,
        AkAudioBufferBus *in_pInputBuffer,
        AkPipelineBufferBase *in_pOutputBuffer)
{
  CAkMixer::MixAndInterleaveStereo(this, in_pInputBuffer, in_pOutputBuffer);
}

// File Line: 193
// RVA: 0xA98760
// attributes: thunk
void __fastcall CAkMixer::MixFinal51(
        CAkMixer *this,
        AkAudioBufferBus *in_pInputBuffer,
        AkPipelineBufferBase *in_pOutputBuffer)
{
  CAkMixer::MixAndInterleave51(this, in_pInputBuffer, in_pOutputBuffer);
}

// File Line: 218
// RVA: 0xA98770
// attributes: thunk
void __fastcall CAkMixer::MixFinal71(
        CAkMixer *this,
        AkAudioBufferBus *in_pInputBuffer,
        AkPipelineBufferBase *in_pOutputBuffer)
{
  CAkMixer::MixAndInterleave71(this, in_pInputBuffer, in_pOutputBuffer);
}

