// File Line: 51
// RVA: 0xA7E030
void __fastcall CAkBusVolumes::CAkBusVolumes(CAkBusVolumes *this)
{
  CAkBusVolumes *v1; // rbx
  CAkMixer *v2; // rcx
  AkSIMDSpeakerVolumes *v3; // rax
  signed __int64 v4; // rcx

  v1 = this;
  v2 = &this->m_Mixer;
  *(_DWORD *)&v2[-3].m_usMaxFrames = 0;
  *(_DWORD *)&v2[-2].m_usMaxFrames = 0;
  v2[-1] = 0i64;
  CAkMixer::CAkMixer(v2);
  v1->m_BufferOut.pData = 0i64;
  *((_BYTE *)v1 + 1140) &= 0xFCu;
  v1->m_BusPosParams.m_fPAN_X_2D = 0.5;
  v1->m_BusPosParams.m_fPAN_Y_2D = 1.0;
  v1->m_BusPosParams.m_fCenterPCT = 100.0;
  v1->m_BusPosParams.bIsPannerEnabled = 0;
  v3 = &v1->m_PanningVolumes[0].Previous;
  v4 = 8i64;
  v1->m_PrevPosParams.m_fPAN_Y_2D = 1.0;
  v1->m_PrevPosParams.m_fCenterPCT = 100.0;
  v1->m_PrevPosParams.bIsPannerEnabled = 0;
  v1->m_PrevPosParams.m_fPAN_X_2D = 101.0;
  do
  {
    v3->vector[0] = 0i64;
    *(_OWORD *)&v3->aVolumes[4] = 0i64;
    v3[-1].vector[0] = 0i64;
    *(_OWORD *)&v3[-1].aVolumes[4] = 0i64;
    v3 += 2;
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
  float v4; // [rsp+10h] [rbp+10h]

  this->m_fNextVolumedB = in_dBVolume;
  v2 = in_dBVolume * 0.050000001;
  if ( v2 >= -37.0 )
  {
    if ( `AkMath::FastPow10::`4::`local static guard & 1 )
    {
      v3 = *(float *)&`AkMath::FastPow10::`4::SCALE;
    }
    else
    {
      v3 = FLOAT_2_7866352e7;
      `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    LODWORD(v4) = ((signed int)(float)((float)(v2 * v3) + 1065353200.0) & 0x7FFFFF) + 1065353216;
    this->m_fNextVolume = (float)((float)((float)((float)(v4 * 0.32518977) + 0.020805772) * v4) + 0.65304345)
                        * COERCE_FLOAT((signed int)(float)((float)(v2 * v3) + 1065353200.0) & 0xFF800000);
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
  float v5; // [rsp+10h] [rbp+10h]

  v2 = in_VolumeOffsetdB + this->m_fNextVolumedB;
  this->m_fNextVolumedB = v2;
  v3 = v2 * 0.050000001;
  if ( v3 >= -37.0 )
  {
    if ( `AkMath::FastPow10::`4::`local static guard & 1 )
    {
      v4 = *(float *)&`AkMath::FastPow10::`4::SCALE;
    }
    else
    {
      v4 = FLOAT_2_7866352e7;
      `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    LODWORD(v5) = ((signed int)(float)((float)(v4 * v3) + 1065353200.0) & 0x7FFFFF) + 1065353216;
    this->m_fNextVolume = (float)((float)((float)((float)(v5 * 0.32518977) + 0.020805772) * v5) + 0.65304345)
                        * COERCE_FLOAT((signed int)(float)((float)(v4 * v3) + 1065353200.0) & 0xFF800000);
  }
  else
  {
    this->m_fNextVolume = 0.0;
  }
}

