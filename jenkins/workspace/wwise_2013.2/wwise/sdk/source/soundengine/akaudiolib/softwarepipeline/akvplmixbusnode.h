// File Line: 51
// RVA: 0xA7E030
void __fastcall CAkBusVolumes::CAkBusVolumes(CAkBusVolumes *this)
{
  CAkMixer *p_m_Mixer; // rcx
  AkSIMDSpeakerVolumes *p_Previous; // rax
  __int64 v4; // rcx

  p_m_Mixer = &this->m_Mixer;
  *(_DWORD *)&p_m_Mixer[-3].m_usMaxFrames = 0;
  *(_DWORD *)&p_m_Mixer[-2].m_usMaxFrames = 0;
  p_m_Mixer[-1] = 0i64;
  CAkMixer::CAkMixer(p_m_Mixer);
  this->m_BufferOut.pData = 0i64;
  *((_BYTE *)this + 1140) &= 0xFCu;
  this->m_BusPosParams.m_fPAN_X_2D = 0.5;
  this->m_BusPosParams.m_fPAN_Y_2D = 1.0;
  this->m_BusPosParams.m_fCenterPCT = 100.0;
  this->m_BusPosParams.bIsPannerEnabled = 0;
  p_Previous = &this->m_PanningVolumes[0].Previous;
  v4 = 8i64;
  this->m_PrevPosParams.m_fPAN_Y_2D = 1.0;
  this->m_PrevPosParams.m_fCenterPCT = 100.0;
  this->m_PrevPosParams.bIsPannerEnabled = 0;
  this->m_PrevPosParams.m_fPAN_X_2D = 101.0;
  do
  {
    p_Previous->vector[0] = 0i64;
    *(_OWORD *)&p_Previous->aVolumes[4] = 0i64;
    p_Previous[-1].vector[0] = 0i64;
    *(_OWORD *)&p_Previous[-1].aVolumes[4] = 0i64;
    p_Previous += 2;
    --v4;
  }
  while ( v4 );
}

// File Line: 67
// RVA: 0xA4B3F0
void __fastcall CAkBusVolumes::SetNextVolume(CAkBusVolumes *this, float in_dBVolume)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  this->m_fNextVolumedB = in_dBVolume;
  v2 = in_dBVolume * 0.050000001;
  if ( v2 >= -37.0 )
  {
    if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
    {
      v3 = *(float *)&`AkMath::FastPow10::`4::SCALE;
    }
    else
    {
      v3 = FLOAT_2_7866352e7;
      `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    this->m_fNextVolume = (float)((float)((float)((float)(COERCE_FLOAT(
                                                            ((int)(float)((float)(v2 * v3) + 1065353200.0) & 0x7FFFFF)
                                                          + 1065353216)
                                                        * 0.32518977)
                                                + 0.020805772)
                                        * COERCE_FLOAT(((int)(float)((float)(v2 * v3) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                                + 0.65304345)
                        * COERCE_FLOAT((int)(float)((float)(v2 * v3) + 1065353200.0) & 0xFF800000);
  }
  else
  {
    this->m_fNextVolume = 0.0;
  }
}

// File Line: 73
// RVA: 0xA53440
void __fastcall CAkBusVolumes::SetVolumeOffset(CAkBusVolumes *this, float in_VolumeOffsetdB)
{
  float v2; // xmm1_4
  float v3; // xmm1_4
  float v4; // xmm0_4

  v2 = in_VolumeOffsetdB + this->m_fNextVolumedB;
  this->m_fNextVolumedB = v2;
  v3 = v2 * 0.050000001;
  if ( v3 >= -37.0 )
  {
    if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
    {
      v4 = *(float *)&`AkMath::FastPow10::`4::SCALE;
    }
    else
    {
      v4 = FLOAT_2_7866352e7;
      `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    this->m_fNextVolume = (float)((float)((float)((float)(COERCE_FLOAT(
                                                            ((int)(float)((float)(v4 * v3) + 1065353200.0) & 0x7FFFFF)
                                                          + 1065353216)
                                                        * 0.32518977)
                                                + 0.020805772)
                                        * COERCE_FLOAT(((int)(float)((float)(v4 * v3) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                                + 0.65304345)
                        * COERCE_FLOAT((int)(float)((float)(v4 * v3) + 1065353200.0) & 0xFF800000);
  }
  else
  {
    this->m_fNextVolume = 0.0;
  }
}

