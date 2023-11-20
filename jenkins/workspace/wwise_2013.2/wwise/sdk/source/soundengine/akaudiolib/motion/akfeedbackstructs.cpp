// File Line: 26
// RVA: 0xA8F5F0
AkFeedbackParams *__fastcall AkFeedbackParams::Create(unsigned __int16 in_iPlayers, unsigned int in_uChannelMask, AkPannerType in_ePanType, AkPositionSourceType in_ePosSource)
{
  unsigned int v4; // esi
  unsigned __int16 v5; // bx
  unsigned int v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  AkFeedbackParams *result; // rax
  AkFeedbackParams *v10; // rdi

  v4 = in_uChannelMask;
  v5 = in_iPlayers;
  if ( in_ePanType != 1 || in_ePosSource != 1 )
    v5 = 1;
  v6 = in_uChannelMask;
  v7 = 0;
  v8 = v6 & 0xFFFFFFF7;
  if ( !v8 )
    return 0i64;
  do
  {
    ++v7;
    v8 &= v8 - 1;
  }
  while ( v8 );
  if ( !v7 )
    return 0i64;
  result = (AkFeedbackParams *)AK::MemoryMgr::Malign(g_DefaultPoolId, ((unsigned int)v5 * v7 + 1) << 6, 0x10u);
  v10 = result;
  if ( result )
  {
    AkFeedbackParams::AkFeedbackParams(result, v5, v4);
    result = v10;
  }
  return result;
}

// File Line: 50
// RVA: 0xA8F750
void __fastcall AkFeedbackParams::Destroy(AkFeedbackParams *this)
{
  AkFeedbackParams *v1; // rbx
  CAkSrcLpFilter *v2; // rcx
  CAkSrcLpFilter *v3; // rdi
  int v4; // esi

  v1 = this;
  v2 = this->m_pLPFilter;
  if ( v2 )
  {
    CAkSrcLpFilter::Term(v2);
    v3 = v1->m_pLPFilter;
    v4 = g_DefaultPoolId;
    if ( v3 )
    {
      v3->vfptr->__vecDelDtor(v3, 0);
      AK::MemoryMgr::Free(v4, v3);
    }
    v1->m_pLPFilter = 0i64;
  }
  AK::MemoryMgr::Free(g_DefaultPoolId, v1);
}

// File Line: 56
// RVA: 0xA8F260
void __fastcall AkFeedbackParams::AkFeedbackParams(AkFeedbackParams *this, unsigned __int16 in_iPlayers, unsigned int in_uChannelMask)
{
  char v3; // r9
  __int16 v4; // dx
  AkFeedbackParams *v5; // r10
  unsigned __int16 v6; // r8
  int v7; // ecx

  v3 = 0;
  this->m_pOutput = 0i64;
  *(_QWORD *)&this->m_NewVolume = 0i64;
  *(_QWORD *)&this->m_LPF = 0i64;
  this->m_pLPFilter = 0i64;
  *(_DWORD *)&this->m_usCompanyID = 0;
  *(_QWORD *)this->m_fNextAttenuation = 4575657222473777152i64;
  *(_QWORD *)&this->m_fNextAttenuation[2] = 4575657222473777152i64;
  *((_WORD *)this + 27) &= 0xFF8Fu;
  *((_WORD *)this + 27) |= 16 * (in_iPlayers & 7);
  v4 = *((_WORD *)this + 27);
  v5 = this;
  v6 = in_uChannelMask & 0xFFF7;
  v7 = v6;
  v5->m_uChannelMask = v6;
  if ( v6 )
  {
    do
    {
      ++v3;
      v7 &= v7 - 1;
    }
    while ( v7 );
  }
  *((_WORD *)v5 + 27) = v3 & 0xF | v4 & 0xFFF0 | 0x80;
}

// File Line: 83
// RVA: 0xA8F6A0
bool __fastcall AkFeedbackParams::CreateLowPassFilter(AkFeedbackParams *this)
{
  AkFeedbackParams *v1; // rbx
  CAkSrcLpFilter *v2; // rax
  AKRESULT v3; // eax
  CAkSrcLpFilter *v4; // rcx
  CAkSrcLpFilter *v5; // rdi
  int v6; // esi

  v1 = this;
  v2 = (CAkSrcLpFilter *)AK::MemoryMgr::Malign(g_DefaultPoolId, 0xD0ui64, 0x10u);
  if ( v2 )
    CAkSrcLpFilter::CAkSrcLpFilter(v2);
  v1->m_pLPFilter = v2;
  if ( !v2 || (v3 = CAkSrcLpFilter::Init(v2, v1->m_uChannelMask, 1), v3 != 1) )
  {
    v4 = v1->m_pLPFilter;
    if ( v4 )
    {
      CAkSrcLpFilter::Term(v4);
      v5 = v1->m_pLPFilter;
      v6 = g_DefaultPoolId;
      if ( v5 )
      {
        v5->vfptr->__vecDelDtor(v5, 0);
        AK::MemoryMgr::Free(v6, v5);
      }
      v1->m_pLPFilter = 0i64;
    }
    LOBYTE(v3) = 0;
  }
  return v3;
}

// File Line: 100
// RVA: 0xA8F7C0
void __fastcall AkFeedbackParams::StampOldVolumes(AkFeedbackParams *this)
{
  unsigned __int16 v1; // r8
  signed int v2; // er9
  __int64 v3; // rax

  v1 = 0;
  v2 = (unsigned __int16)((*((_WORD *)this + 27) & 0xF) * ((*((_WORD *)this + 27) >> 4) & 7));
  if ( v2 > 0 )
  {
    do
    {
      v3 = v1++;
      v3 <<= 6;
      *(__m128 *)((char *)this->m_Volumes[0].Previous.vector + v3) = *(__m128 *)((char *)this->m_Volumes[0].Next.vector
                                                                               + v3);
      *(_OWORD *)((char *)&this->m_Volumes[0].Previous.aVolumes[4] + v3) = *(_OWORD *)((char *)&this->m_Volumes[0].Next.aVolumes[4]
                                                                                     + v3);
    }
    while ( v1 < v2 );
  }
}

// File Line: 108
// RVA: 0xA8F820
void __fastcall AkFeedbackParams::ZeroNewVolumes(AkFeedbackParams *this)
{
  AkFeedbackParams *v1; // r8
  unsigned __int16 v2; // ax
  signed int v3; // er9
  __int64 v4; // rcx
  signed __int64 v5; // rcx

  v1 = this;
  v2 = 0;
  v3 = (unsigned __int16)((*((_WORD *)this + 27) & 0xF) * ((*((_WORD *)this + 27) >> 4) & 7));
  if ( v3 > 0 )
  {
    do
    {
      v4 = v2++;
      v5 = (v4 + 1) << 6;
      *(_OWORD *)((char *)&v1->m_pOutput + v5) = 0i64;
      *(_OWORD *)((char *)&v1->m_LPF + v5) = 0i64;
    }
    while ( v2 < v3 );
  }
}

// File Line: 115
// RVA: 0xA8F810
void __fastcall AkFeedbackParams::ZeroNewAttenuations(AkFeedbackParams *this)
{
  *(_QWORD *)this->m_fNextAttenuation = 0i64;
  *(_QWORD *)&this->m_fNextAttenuation[2] = 0i64;
}

// File Line: 134
// RVA: 0xA8F880
float __fastcall dBToLinWithPositive(float in_fVal)
{
  float v1; // xmm2_4
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float result; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // [rsp+8h] [rbp+8h]

  v1 = 0.0;
  if ( in_fVal <= 0.0 )
  {
    v6 = in_fVal * 0.050000001;
    if ( v6 >= -37.0 )
    {
      if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
      {
        v7 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
      }
      else
      {
        v7 = FLOAT_2_7866352e7;
        `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
      }
      v1 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v6 * v7) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v6 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v6 * v7) + 1065353200.0) & 0xFF800000);
    }
    result = v1;
  }
  else
  {
    v2 = in_fVal * -0.050000001;
    if ( v2 < -37.0
      || (`AkMath::FastPow10'::`4'::`local static guard' & 1 ? (v3 = *(float *)&`AkMath::FastPow10'::`4'::SCALE) : (v3 = FLOAT_2_7866352e7, `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7), `AkMath::FastPow10'::`4'::`local static guard' |= 1u),
          LODWORD(v8) = ((signed int)(float)((float)(v2 * v3) + 1065353200.0) & 0x7FFFFF) + 1065353216,
          v4 = (float)((float)((float)((float)(v8 * 0.32518977) + 0.020805772) * v8) + 0.65304345)
             * COERCE_FLOAT((signed int)(float)((float)(v2 * v3) + 1065353200.0) & 0xFF800000),
          v4 <= 0.0) )
    {
      result = FLOAT_65535_0;
    }
    else
    {
      result = 1.0 / v4;
    }
  }
  return result;
}

// File Line: 151
// RVA: 0xA8F2F0
void __fastcall AkFeedbackParams::ComputePlayerVolumes(AkFeedbackParams *this, CAkPBI *in_pPBI)
{
  AkFeedbackParams *v2; // rdi
  CAkPBI *v3; // rbp
  int v4; // er15
  unsigned __int16 v5; // si
  __int64 v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm6_4
  __m128 *v12; // rbx
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __int16 v15; // ax
  unsigned __int8 v16; // dl
  __int64 v17; // rax

  v2 = this;
  v3 = in_pPBI;
  *((_WORD *)this + 27) |= 0x100u;
  v4 = CAkFeedbackDeviceMgr::GetActivePlayers(CAkFeedbackDeviceMgr::s_pSingleton, in_pPBI);
  v5 = 0;
  do
  {
    if ( _bittest(&v4, v5) )
    {
      v6 = 0i64;
      v7 = dBToLinWithPositive(v2->m_NewVolume - v2->m_AudioBusVolume) * v2->m_fNextAttenuation[v5];
      v8 = (float)(CAkPBI::GetVoiceVolumedB(v3) + v3->m_EffectiveParams.Volume) * 0.050000001;
      if ( v8 >= -37.0 )
      {
        if ( `AkMath::FastPow10'::`4'::`local static guard' & 1 )
        {
          v10 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
        }
        else
        {
          v10 = FLOAT_2_7866352e7;
          `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
          `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v9 = (float)((float)((float)((float)(COERCE_FLOAT(
                                               ((signed int)(float)((float)(v10 * v8) + 1065353200.0) & 0x7FFFFF)
                                             + 1065353216)
                                           * 0.32518977)
                                   + 0.020805772)
                           * COERCE_FLOAT(((signed int)(float)((float)(v10 * v8) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                   + 0.65304345)
           * COERCE_FLOAT((signed int)(float)((float)(v10 * v8) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v9 = 0.0;
      }
      v11 = v7 * (float)(v9 * v3->m_EffectiveParams.fFadeRatio);
      if ( (*((_BYTE *)v3 + 371) & 3) == 1 )
        v6 = v5 * (*((unsigned __int16 *)v2 + 27) & 0xFu);
      v12 = (__m128 *)((char *)v2 + 64 * (v6 + 1));
      memset(v12, 0, (*((_WORD *)v2 + 27) & 0xFu) << 6);
      *(float *)v12->m128_u64 = v11;
      v13 = _mm_shuffle_ps((__m128)LODWORD(g_fVolumeThreshold), (__m128)LODWORD(g_fVolumeThreshold), 0);
      *((_WORD *)v2 + 27) &= (unsigned __int16)((((_mm_movemask_ps(_mm_cmpleps(v12[1], v13)) == 15) & (_mm_movemask_ps(_mm_cmpleps(*v12, v13)) == 15)) != 0) << 8) | 0xFEFF;
      if ( (*((_WORD *)v2 + 27) & 0xFu) > 1 )
      {
        v12[4].m128_f32[1] = v11;
        v14 = _mm_shuffle_ps((__m128)LODWORD(g_fVolumeThreshold), (__m128)LODWORD(g_fVolumeThreshold), 0);
        *((_WORD *)v2 + 27) &= (unsigned __int16)((((_mm_movemask_ps(_mm_cmpleps(v12[5], v14)) == 15) & (_mm_movemask_ps(_mm_cmpleps(v12[4], v14)) == 15)) != 0) << 8) | 0xFEFF;
      }
      v15 = *((_WORD *)v2 + 27);
      if ( (v15 & 0x80u) != 0 )
      {
        v16 = 0;
        if ( v15 & 0xF )
        {
          do
          {
            v17 = v16++;
            v17 <<= 6;
            *(__m128 *)((char *)v12 + v17 + 32) = *(__m128 *)((char *)v12 + v17);
            *(__m128 *)((char *)v12 + v17 + 48) = *(__m128 *)((char *)v12 + v17 + 16);
          }
          while ( v16 < (unsigned __int16)(*((_WORD *)v2 + 27) & 0xF) );
        }
      }
      if ( !(*((_BYTE *)v3 + 371) & 3) )
        break;
    }
    ++v5;
  }
  while ( v5 < 4u );
}

