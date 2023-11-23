// File Line: 48
// RVA: 0xA7EE50
void __fastcall CAkBusVolumes::UpdateFinalVolumes(CAkBusVolumes *this)
{
  unsigned int m_uChannelMask; // edx
  unsigned int v2; // r10d
  unsigned int i; // r9d
  __int64 v5; // rcx
  __int64 v6; // rax
  __int64 v7; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm2

  m_uChannelMask = this->m_uChannelMask;
  v2 = 0;
  for ( i = 0; m_uChannelMask; m_uChannelMask &= m_uChannelMask - 1 )
    ++i;
  do
  {
    v5 = v2;
    v6 = v2++;
    v5 <<= 6;
    v7 = (v6 + 8) << 6;
    *(__m128 *)((char *)this->m_FinalVolumes[0].Previous.vector + v5) = *(__m128 *)((char *)this->m_PanningVolumes[0].Previous.vector
                                                                                  + v5);
    *(_OWORD *)((char *)&this->m_FinalVolumes[0].Previous.aVolumes[4] + v5) = *(_OWORD *)((char *)&this->m_PanningVolumes[0].Previous.aVolumes[4]
                                                                                        + v5);
    *(__m128 *)((char *)this->m_PanningVolumes[0].Next.vector + v7) = *(__m128 *)((char *)this->m_PanningVolumes[0].Next.vector
                                                                                + v5);
    *(_OWORD *)((char *)&this->m_PanningVolumes[0].Next.aVolumes[4] + v7) = *(_OWORD *)((char *)&this->m_PanningVolumes[0].Next.aVolumes[4]
                                                                                      + v5);
    v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_fPreviousVolume), (__m128)LODWORD(this->m_fPreviousVolume), 0);
    v9 = _mm_mul_ps(v8, *(__m128 *)((char *)this->m_FinalVolumes[0].Previous.vector + v5));
    *(__m128 *)((char *)&this->m_FinalVolumes[0].Previous.vector[1] + v5) = _mm_mul_ps(
                                                                              *(__m128 *)((char *)&this->m_FinalVolumes[0].Previous.vector[1]
                                                                                        + v5),
                                                                              v8);
    *(__m128 *)((char *)this->m_FinalVolumes[0].Previous.vector + v5) = v9;
    v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fNextVolume), (__m128)LODWORD(this->m_fNextVolume), 0);
    v11 = _mm_mul_ps(*(__m128 *)((char *)this->m_PanningVolumes[0].Next.vector + v7), v10);
    v12 = _mm_mul_ps(v10, *(__m128 *)((char *)&this->m_PanningVolumes[0].Next.vector[1] + v7));
    *(__m128 *)((char *)this->m_PanningVolumes[0].Next.vector + v7) = v11;
    *(__m128 *)((char *)&this->m_PanningVolumes[0].Next.vector[1] + v7) = v12;
  }
  while ( v2 < i );
}

// File Line: 62
// RVA: 0xA7EF30
void __fastcall CAkBusVolumes::UpdatePanningVolumes(CAkBusVolumes *this)
{
  __int64 v1; // rbp
  CAkBusVolumes *v2; // rdi
  unsigned int m_uChannelMask; // ecx
  unsigned int i; // edx
  unsigned int v5; // ecx
  __int64 v6; // rax
  BaseGenParams *p_m_BusPosParams; // rbx
  BaseGenParams *p_m_PrevPosParams; // rsi
  float m_fPAN_X_2D; // xmm3_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  unsigned int v13; // ecx
  unsigned int j; // edx
  unsigned int v15; // r8d
  __int64 v16; // rax
  __int64 v17; // rcx
  __int128 v18; // xmm1
  unsigned __int64 v19; // rcx
  AkSpeakerVolumes **pVolumes; // rax
  __int64 v21; // rcx
  AkSpeakerVolumeMatrixBusCallbackInfo in_rCallbackInfo; // [rsp+40h] [rbp-158h] BYREF
  AkSIMDSpeakerVolumes out_pVolumes; // [rsp+90h] [rbp-108h] BYREF

  v1 = 0i64;
  v2 = this;
  m_uChannelMask = this->m_uChannelMask;
  for ( i = 0; m_uChannelMask; m_uChannelMask &= m_uChannelMask - 1 )
    ++i;
  v5 = 0;
  do
  {
    v6 = v5++;
    v6 <<= 6;
    *(__m128 *)((char *)v2->m_PanningVolumes[0].Previous.vector + v6) = *(__m128 *)((char *)v2->m_PanningVolumes[0].Next.vector
                                                                                  + v6);
    *(_OWORD *)((char *)&v2->m_PanningVolumes[0].Previous.aVolumes[4] + v6) = *(_OWORD *)((char *)&v2->m_PanningVolumes[0].Next.aVolumes[4]
                                                                                        + v6);
  }
  while ( v5 < i );
  p_m_BusPosParams = &v2->m_BusPosParams;
  p_m_PrevPosParams = &v2->m_PrevPosParams;
  m_fPAN_X_2D = v2->m_BusPosParams.m_fPAN_X_2D;
  if ( m_fPAN_X_2D != v2->m_PrevPosParams.m_fPAN_X_2D
    || v2->m_PrevPosParams.m_fPAN_Y_2D != v2->m_BusPosParams.m_fPAN_Y_2D
    || v2->m_PrevPosParams.m_fCenterPCT != v2->m_BusPosParams.m_fCenterPCT
    || v2->m_BusPosParams.bIsPannerEnabled != v2->m_PrevPosParams.bIsPannerEnabled )
  {
    v10 = (float)(m_fPAN_X_2D + 100.0) * 0.0049999999;
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v10 = 0.0;
    }
    v11 = (float)(v2->m_BusPosParams.m_fPAN_Y_2D + 100.0) * 0.0049999999;
    if ( v11 >= 0.0 )
    {
      if ( v11 > 1.0 )
        v11 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v11 = 0.0;
    }
    v12 = v2->m_BusPosParams.m_fCenterPCT * 0.0099999998;
    if ( (*((_BYTE *)v2 + 1140) & 1) == 0 )
      v12 = *(float *)&FLOAT_1_0;
    CAkSpeakerPan::GetSpeakerVolumes2DPan(
      v10,
      v11,
      v12,
      v2->m_BusPosParams.bIsPannerEnabled,
      v2->m_uChannelMask,
      v2->m_uParentMask,
      &out_pVolumes);
    v13 = v2->m_uChannelMask;
    for ( j = 0; v13; v13 &= v13 - 1 )
      ++j;
    v15 = 0;
    do
    {
      v16 = v15;
      v17 = v15++;
      v16 *= 32i64;
      v17 <<= 6;
      v18 = *(_OWORD *)((char *)&out_pVolumes.aVolumes[4] + v16);
      *(__m128 *)((char *)v2->m_PanningVolumes[0].Next.vector + v17) = *(__m128 *)((char *)out_pVolumes.vector + v16);
      *(_OWORD *)((char *)&v2->m_PanningVolumes[0].Next.aVolumes[4] + v17) = v18;
    }
    while ( v15 < j );
    if ( (v2->m_uChannelMask & 8) != 0 )
    {
      v19 = (unsigned __int64)(j - 1) << 6;
      *(__m128 *)((char *)v2->m_PanningVolumes[0].Next.vector + v19) = 0i64;
      *(_OWORD *)((char *)&v2->m_PanningVolumes[0].Next.aVolumes[4] + v19) = 0i64;
      *(int *)((char *)&v2->m_PanningVolumes[0].Next.vector[1].m128_i32[3] + v19) = 1065353216;
    }
    if ( (*((_BYTE *)v2 + 1140) & 2) == 0 || !v2->m_busID )
      goto LABEL_33;
    in_rCallbackInfo.busID = v2->m_busID;
    in_rCallbackInfo.uChannelMask = v2->m_uChannelMask;
    if ( j )
    {
      pVolumes = in_rCallbackInfo.pVolumes;
      v1 = j;
      v21 = j;
      do
      {
        *pVolumes = (AkSpeakerVolumes *)v2;
        v2 = (CAkBusVolumes *)((char *)v2 + 64);
        ++pVolumes;
        --v21;
      }
      while ( v21 );
    }
    if ( (unsigned int)v1 < 8 )
      memset(&in_rCallbackInfo.pVolumes[v1], 0, 8i64 * (unsigned int)(8 - v1));
    if ( !(unsigned __int8)CAkBusCallbackMgr::DoCallback(g_pBusCallbackMgr, &in_rCallbackInfo) )
    {
LABEL_33:
      p_m_PrevPosParams->m_fPAN_X_2D = p_m_BusPosParams->m_fPAN_X_2D;
      p_m_PrevPosParams->m_fPAN_Y_2D = p_m_BusPosParams->m_fPAN_Y_2D;
      p_m_PrevPosParams->m_fCenterPCT = p_m_BusPosParams->m_fCenterPCT;
      *(_DWORD *)&p_m_PrevPosParams->bIsPannerEnabled = *(_DWORD *)&p_m_BusPosParams->bIsPannerEnabled;
    }
  }
}

// File Line: 124
// RVA: 0xA7E6C0
void __fastcall CAkBusVolumes::InitPan(
        CAkBusVolumes *this,
        CAkParameterNodeBase *in_pBus,
        unsigned int in_ChanMsk,
        unsigned int in_uParentMask)
{
  unsigned int m_uChannelMask; // ecx
  unsigned int v6; // edx
  unsigned int i; // r8d
  __int64 v8; // rax

  this->m_uChannelMask = in_ChanMsk;
  this->m_uParentMask = in_uParentMask;
  if ( in_pBus && (*((_BYTE *)in_pBus + 83) & 4) != 0 )
  {
    *((_BYTE *)this + 1140) |= 1u;
    CAkParameterNodeBase::Get2DParams(in_pBus, 0i64, &this->m_BusPosParams);
  }
  else
  {
    *((_BYTE *)this + 1140) &= ~1u;
    this->m_BusPosParams.m_fPAN_X_2D = 0.5;
    this->m_BusPosParams.m_fPAN_Y_2D = 1.0;
    this->m_BusPosParams.m_fCenterPCT = 100.0;
    this->m_BusPosParams.bIsPannerEnabled = 0;
  }
  CAkBusVolumes::UpdatePanningVolumes(this);
  m_uChannelMask = this->m_uChannelMask;
  v6 = 0;
  for ( i = 0; m_uChannelMask; m_uChannelMask &= m_uChannelMask - 1 )
    ++i;
  do
  {
    v8 = v6++;
    v8 <<= 6;
    *(__m128 *)((char *)this->m_PanningVolumes[0].Previous.vector + v8) = *(__m128 *)((char *)this->m_PanningVolumes[0].Next.vector
                                                                                    + v8);
    *(_OWORD *)((char *)&this->m_PanningVolumes[0].Previous.aVolumes[4] + v8) = *(_OWORD *)((char *)&this->m_PanningVolumes[0].Next.aVolumes[4]
                                                                                          + v8);
  }
  while ( v6 < i );
}

// File Line: 134
// RVA: 0xA7EDC0
void __fastcall CAkBusVolumes::Update2DParams(CAkBusVolumes *this, CAkParameterNodeBase *in_pBus)
{
  if ( in_pBus && (*((_BYTE *)in_pBus + 83) & 4) != 0 )
  {
    *((_BYTE *)this + 1140) |= 1u;
    CAkParameterNodeBase::Get2DParams(in_pBus, 0i64, &this->m_BusPosParams);
  }
  else
  {
    *((_BYTE *)this + 1140) &= ~1u;
    this->m_BusPosParams.m_fPAN_X_2D = 0.5;
    this->m_BusPosParams.m_fPAN_Y_2D = 1.0;
    this->m_BusPosParams.m_fCenterPCT = 100.0;
    this->m_BusPosParams.bIsPannerEnabled = 0;
  }
}

// File Line: 151
// RVA: 0xA7E8E0
void __fastcall CAkBusVolumes::PositioningChangeNotification(
        CAkBusVolumes *this,
        float in_RTPCValue,
        AkRTPC_ParameterID in_ParameterID)
{
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d

  v3 = in_ParameterID - 11;
  if ( v3 )
  {
    v4 = v3 - 9;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 43 )
          this->m_BusPosParams.bIsPannerEnabled = in_RTPCValue > 0.0;
      }
      else
      {
        this->m_BusPosParams.m_fPAN_Y_2D = in_RTPCValue;
      }
    }
    else
    {
      this->m_BusPosParams.m_fPAN_X_2D = in_RTPCValue;
    }
  }
  else
  {
    this->m_BusPosParams.m_fCenterPCT = in_RTPCValue;
  }
}

// File Line: 170
// RVA: 0xA7DF70
void __fastcall CAkBusFX::CAkBusFX(CAkBusFX *this)
{
  CAkBusVolumes::CAkBusVolumes(this);
  *((_BYTE *)this->m_aFX + 32) &= 0xFCu;
  this->m_aFX[0].id = -1;
  this->m_aFX[1].id = -1;
  this->m_aFX[0].pParam = 0i64;
  this->m_aFX[0].pEffect = 0i64;
  this->m_aFX[0].pBusFXContext = 0i64;
  this->m_aFX[1].pParam = 0i64;
  this->m_aFX[1].pEffect = 0i64;
  this->m_aFX[1].pBusFXContext = 0i64;
  *((_BYTE *)&this->m_aFX[1] + 32) &= 0xFCu;
  this->m_aFX[2].id = -1;
  this->m_aFX[2].pParam = 0i64;
  this->m_aFX[2].pEffect = 0i64;
  this->m_aFX[2].pBusFXContext = 0i64;
  *((_BYTE *)&this->m_aFX[2] + 32) &= 0xFCu;
  this->m_aFX[3].id = -1;
  this->m_aFX[3].pParam = 0i64;
  this->m_aFX[3].pEffect = 0i64;
  this->m_aFX[3].pBusFXContext = 0i64;
  *((_BYTE *)&this->m_aFX[3] + 32) &= 0xFCu;
  *((_BYTE *)this + 1312) &= 0xFCu;
}

// File Line: 195
// RVA: 0xA7EB10
__int64 __fastcall CAkBusFX::SetInsertFx(CAkBusFX *this, AK::CAkBusCtx *in_busCtx, unsigned int in_uFXIndex)
{
  __int64 v5; // r15
  int v6; // edi
  CAkFxBase *m_pT; // r9
  unsigned int v8; // ebx
  char *v9; // r14
  AK::IAkPluginParam *m_pParam; // rcx
  AK::IAkRTPCSubscriber *v11; // rax
  int v12; // esi
  CAkBusFXContext *v14; // rax
  __int64 v15; // rax
  bool bIsBypassed; // al
  unsigned int v17; // edx
  unsigned int v18; // eax
  int v19; // eax
  unsigned int uChannelMask; // r8d
  unsigned int i; // ecx
  __int64 v22; // rcx
  __int64 v23; // r9
  int v24; // edi
  __int64 v25; // r8
  AkFXDesc out_rFXInfo; // [rsp+30h] [rbp-38h] BYREF
  unsigned int v27; // [rsp+88h] [rbp+20h] BYREF
  unsigned int v28; // [rsp+8Ch] [rbp+24h]

  v5 = in_uFXIndex;
  CAkBusFX::DropFx(this, in_uFXIndex);
  v6 = 0;
  out_rFXInfo.pFx.m_pT = 0i64;
  AK::CAkBusCtx::GetFX(in_busCtx, v5, &out_rFXInfo);
  m_pT = out_rFXInfo.pFx.m_pT;
  if ( !out_rFXInfo.pFx.m_pT )
  {
    v8 = 1;
    goto LABEL_10;
  }
  v9 = (char *)this->m_aFX + 32 * v5 + 8 * v5;
  *(_DWORD *)v9 = out_rFXInfo.pFx.m_pT->m_FXID;
  m_pParam = m_pT->m_pParam;
  if ( !m_pParam )
  {
    v8 = 2;
    goto LABEL_10;
  }
  v11 = (AK::IAkRTPCSubscriber *)m_pParam->vfptr[1].__vecDelDtor(m_pParam, (unsigned int)&AkFXMemAlloc::m_instanceLower);
  *((_QWORD *)v9 + 1) = v11;
  if ( v11 )
  {
    CAkFxBase::SubscribeRTPC(out_rFXInfo.pFx.m_pT, v11, 0i64);
    v14 = (CAkBusFXContext *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x30ui64);
    if ( v14 )
      CAkBusFXContext::CAkBusFXContext(v14, this, v5, in_busCtx);
    else
      v15 = 0i64;
    *((_QWORD *)v9 + 3) = v15;
    v12 = 2;
    if ( v15 )
    {
      bIsBypassed = out_rFXInfo.bIsBypassed;
      v9[32] &= ~1u;
      v17 = *(_DWORD *)v9;
      v9[32] |= bIsBypassed;
      v18 = CAkEffectsMgr::Alloc(&AkFXMemAlloc::m_instanceLower, v17, (AK::IAkPlugin **)v9 + 2);
      if ( v18 != 1 )
      {
        v8 = v18;
        goto LABEL_9;
      }
      v19 = (*(__int64 (__fastcall **)(_QWORD, unsigned int *))(**((_QWORD **)v9 + 2) + 24i64))(
              *((_QWORD *)v9 + 2),
              &v27);
      v12 = v19;
      if ( BYTE1(v28) )
      {
        v12 = 2;
      }
      else if ( v19 == 1 )
      {
        uChannelMask = this->m_BufferOut.uChannelMask;
        for ( i = uChannelMask; i; i &= i - 1 )
          ++v6;
        v22 = *((_QWORD *)v9 + 2);
        v23 = *((_QWORD *)v9 + 1);
        v27 = AkAudioLibSettings::g_pipelineCoreFrequency;
        v24 = uChannelMask & 0x3FFFF | (v6 << 26) & 0x1F000000;
        v25 = *((_QWORD *)v9 + 3);
        v28 = v24 | 0xA0800000;
        v12 = (*(__int64 (__fastcall **)(__int64, AkFXMemAlloc *, __int64, __int64, unsigned int *))(*(_QWORD *)v22 + 48i64))(
                v22,
                &AkFXMemAlloc::m_instanceLower,
                v25,
                v23,
                &v27);
        if ( v12 == 1 )
        {
          v12 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)v9 + 2) + 16i64))(*((_QWORD *)v9 + 2));
          if ( v12 == 1 )
            goto LABEL_8;
        }
      }
    }
  }
  else
  {
    v12 = 2;
  }
  CAkBusFX::DropFx(this, v5);
LABEL_8:
  v8 = v12;
LABEL_9:
  m_pT = out_rFXInfo.pFx.m_pT;
LABEL_10:
  if ( m_pT )
    m_pT->vfptr->Release(m_pT);
  return v8;
}

// File Line: 314
// RVA: 0xA7ED40
void __fastcall CAkBusFX::SetInsertFxBypass(CAkBusFX *this, char in_bitsFXBypass, char in_uTargetMask)
{
  if ( (in_uTargetMask & 1) != 0 )
  {
    *((_BYTE *)this->m_aFX + 32) &= ~1u;
    *((_BYTE *)this->m_aFX + 32) |= in_bitsFXBypass & 1;
  }
  if ( (in_uTargetMask & 2) != 0 )
  {
    *((_BYTE *)&this->m_aFX[1] + 32) &= ~1u;
    *((_BYTE *)&this->m_aFX[1] + 32) |= (in_bitsFXBypass & 2) != 0;
  }
  if ( (in_uTargetMask & 4) != 0 )
  {
    *((_BYTE *)&this->m_aFX[2] + 32) &= ~1u;
    *((_BYTE *)&this->m_aFX[2] + 32) |= (in_bitsFXBypass & 4) != 0;
  }
  if ( (in_uTargetMask & 8) != 0 )
  {
    *((_BYTE *)&this->m_aFX[3] + 32) &= ~1u;
    *((_BYTE *)&this->m_aFX[3] + 32) |= (in_bitsFXBypass & 8) != 0;
  }
  if ( (in_uTargetMask & 0x10) != 0 )
  {
    *((_BYTE *)this + 1312) &= ~1u;
    *((_BYTE *)this + 1312) |= (in_bitsFXBypass & 0x10) != 0;
  }
}

// File Line: 341
// RVA: 0xA7E3A0
void __fastcall CAkBusFX::DropFx(CAkBusFX *this)
{
  AK::IAkInPlaceEffectPlugin **p_pEffect; // rbx
  __int64 v2; // rbp
  AK::IAkInPlaceEffectPlugin *v3; // rsi
  int v4; // edi
  void *v5; // rdx

  p_pEffect = &this->m_aFX[0].pEffect;
  v2 = 4i64;
  do
  {
    if ( *p_pEffect )
    {
      (*p_pEffect)->vfptr->Term(*p_pEffect, &AkFXMemAlloc::m_instanceLower);
      *p_pEffect = 0i64;
    }
    v3 = p_pEffect[1];
    if ( v3 )
    {
      v4 = g_LEngineDefaultPoolId;
      v3->vfptr->__vecDelDtor(p_pEffect[1], 0);
      AK::MemoryMgr::Free(v4, v3);
      p_pEffect[1] = 0i64;
    }
    v5 = *(p_pEffect - 1);
    *((_DWORD *)p_pEffect - 4) = -1;
    if ( v5 )
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v5);
      ((void (__fastcall *)(_QWORD, AkFXMemAlloc *))(*(p_pEffect - 1))->vfptr->SupportMediaRelocation)(
        *(p_pEffect - 1),
        &AkFXMemAlloc::m_instanceLower);
      *(p_pEffect - 1) = 0i64;
    }
    p_pEffect += 5;
    --v2;
  }
  while ( v2 );
}

// File Line: 349
// RVA: 0xA7E2F0
void __fastcall CAkBusFX::DropFx(CAkBusFX *this, unsigned int in_uFXIndex)
{
  char *v2; // rdi
  __int64 v3; // rcx
  void *v4; // rsi
  int v5; // ebx
  void *v6; // rdx

  v2 = (char *)this->m_aFX + 32 * in_uFXIndex + 8 * in_uFXIndex;
  v3 = *((_QWORD *)v2 + 2);
  if ( v3 )
  {
    (*(void (__fastcall **)(__int64, AkFXMemAlloc *))(*(_QWORD *)v3 + 8i64))(v3, &AkFXMemAlloc::m_instanceLower);
    *((_QWORD *)v2 + 2) = 0i64;
  }
  v4 = (void *)*((_QWORD *)v2 + 3);
  if ( v4 )
  {
    v5 = g_LEngineDefaultPoolId;
    (**(void (__fastcall ***)(_QWORD, _QWORD))v4)(*((_QWORD *)v2 + 3), 0i64);
    AK::MemoryMgr::Free(v5, v4);
    *((_QWORD *)v2 + 3) = 0i64;
  }
  v6 = (void *)*((_QWORD *)v2 + 1);
  *(_DWORD *)v2 = -1;
  if ( v6 )
  {
    CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v6);
    (*(void (__fastcall **)(_QWORD, AkFXMemAlloc *))(**((_QWORD **)v2 + 1) + 32i64))(
      *((_QWORD *)v2 + 1),
      &AkFXMemAlloc::m_instanceLower);
    *((_QWORD *)v2 + 1) = 0i64;
  }
}

// File Line: 415
// RVA: 0xA7E500
__int64 __fastcall CAkVPLMixBusNode::Init(
        CAkVPLMixBusNode *this,
        unsigned int in_uChannelMask,
        unsigned int in_uParentMask,
        unsigned __int16 in_uMaxFrames,
        AK::CAkBusCtx in_busContext)
{
  AK::CAkBusCtx *p_m_BusContext; // rcx
  int v7; // ebp
  unsigned int v10; // eax
  bool IsCallbackEnabled; // al
  CAkBus *m_pBus; // rcx
  __int64 result; // rax
  unsigned int v14; // ecx
  int i; // edx
  unsigned __int64 m_ulBufferOutSize; // rdx
  void *v17; // rax
  void *v18; // rbx

  p_m_BusContext = &this->m_BusContext;
  p_m_BusContext->m_pBus = in_busContext.m_pBus;
  v7 = in_uMaxFrames;
  v10 = AK::CAkBusCtx::ID(p_m_BusContext);
  this->m_busID = v10;
  IsCallbackEnabled = CAkBusCallbackMgr::IsCallbackEnabled(g_pBusCallbackMgr, v10);
  *((_BYTE *)&this->CAkBusVolumes + 1140) &= ~2u;
  this->m_bEffectCreated = 0;
  *((_BYTE *)&this->CAkBusVolumes + 1140) |= 2 * IsCallbackEnabled;
  CAkBusVolumes::InitPan(this, in_busContext.m_pBus, in_uChannelMask, in_uParentMask);
  this->m_Mixer.m_usMaxFrames = v7;
  this->m_Mixer.m_fOneOverNumFrames = 1.0 / (float)v7;
  m_pBus = this->m_BusContext.m_pBus;
  if ( m_pBus )
  {
    m_pBus->vfptr->AddRef(m_pBus);
    if ( !((unsigned __int8 (__fastcall *)(CAkBus *, __int64))this->m_BusContext.m_pBus->vfptr[9].Release)(
            this->m_BusContext.m_pBus,
            3i64) )
      return 2i64;
  }
  this->m_eState = NodeStateIdle;
  this->m_fPreviousVolume = 1.0;
  this->m_fNextVolume = 1.0;
  v14 = in_uChannelMask;
  *(_QWORD *)&this->m_fNextVolumedB = 0i64;
  for ( i = 0; v14; v14 &= v14 - 1 )
    ++i;
  this->m_uConnectCount = 0;
  this->m_ulBufferOutSize = 4 * i * v7;
  this->m_BufferOut.pData = 0i64;
  *(_QWORD *)&this->m_BufferOut.eState = 43i64;
  m_ulBufferOutSize = this->m_ulBufferOutSize;
  this->m_BufferOut.eState = AK_NoMoreData;
  v17 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, m_ulBufferOutSize, 0x10u);
  v18 = v17;
  if ( !v17 )
    return 52i64;
  memset(v17, 0, this->m_ulBufferOutSize);
  this->m_BufferOut.pData = v18;
  this->m_BufferOut.uMaxFrames = v7;
  this->m_BufferOut.uValidFrames = 0;
  this->m_BufferOut.uChannelMask = in_uChannelMask;
  result = 1i64;
  *(_QWORD *)&this->m_BufferOut.m_fNextVolume = 0i64;
  return result;
}

// File Line: 501
// RVA: 0xA7E0F0
void __fastcall CAkVPLMixBusNode::~CAkVPLMixBusNode(CAkVPLMixBusNode *this)
{
  CAkBus *m_pBus; // rcx
  void *pData; // rdx

  m_pBus = this->m_BusContext.m_pBus;
  if ( m_pBus )
  {
    ((void (__fastcall *)(CAkBus *, __int64))m_pBus->vfptr[9].Category)(m_pBus, 3i64);
    this->m_BusContext.m_pBus->vfptr->Release(this->m_BusContext.m_pBus);
  }
  CAkBusFX::DropFx(this);
  pData = this->m_BufferOut.pData;
  if ( pData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pData);
    this->m_BufferOut.pData = 0i64;
  }
}

// File Line: 533
// RVA: 0xA7E9D0
void __fastcall CAkVPLMixBusNode::ReleaseBuffer(CAkVPLMixBusNode *this)
{
  void *pData; // r9
  VPLNodeState v2; // eax

  pData = this->m_BufferOut.pData;
  if ( pData )
  {
    v2 = NodeStatePlay;
    if ( this->m_BufferOut.eState == AK_NoMoreData )
      v2 = NodeStateIdle;
    this->m_BufferOut.eState = AK_NoMoreData;
    this->m_eState = v2;
    this->m_BufferOut.uValidFrames = 0;
  }
  memset(pData, 0, this->m_ulBufferOutSize);
}

// File Line: 543
// RVA: 0xA7E7D0
bool __fastcall CAkVPLMixBusNode::IsPanning(CAkVPLMixBusNode *this)
{
  CAkBus *m_pBus; // rax

  m_pBus = this->m_BusContext.m_pBus;
  if ( m_pBus )
    LOBYTE(m_pBus) = (*((_BYTE *)&m_pBus->CAkParameterNodeBase + 83) & 4) != 0;
  return (char)m_pBus;
}

// File Line: 556
// RVA: 0xA7EA20
void __fastcall CAkVPLMixBusNode::ResetNextVolume(CAkVPLMixBusNode *this, float in_dBVolume)
{
  CAkBus *m_pBus; // rcx

  CAkBusVolumes::SetNextVolume(this, in_dBVolume);
  m_pBus = this->m_BusContext.m_pBus;
  if ( m_pBus && (*((_BYTE *)&m_pBus->CAkParameterNodeBase + 83) & 4) != 0 )
  {
    *((_BYTE *)&this->CAkBusVolumes + 1140) |= 1u;
    CAkParameterNodeBase::Get2DParams(m_pBus, 0i64, &this->m_BusPosParams);
  }
  else
  {
    *((_BYTE *)&this->CAkBusVolumes + 1140) &= ~1u;
    this->m_BusPosParams.m_fPAN_X_2D = 0.5;
    this->m_BusPosParams.m_fPAN_Y_2D = 1.0;
    this->m_BusPosParams.m_fCenterPCT = 100.0;
    this->m_BusPosParams.bIsPannerEnabled = 0;
  }
}

// File Line: 589
// RVA: 0xA7E150
void __fastcall CAkVPLMixBusNode::Connect(CAkVPLMixBusNode *this)
{
  float Volume; // xmm0_4
  float m_fNextVolume; // eax

  if ( this->m_eState == NodeStatePlay )
  {
    ++this->m_uConnectCount;
  }
  else
  {
    Volume = AK::CAkBusCtx::GetVolume(&this->m_BusContext, BusVolumeType_ToNextBusWithEffect);
    CAkBusVolumes::SetNextVolume(this, Volume);
    m_fNextVolume = this->m_fNextVolume;
    ++this->m_uConnectCount;
    this->m_fPreviousVolume = m_fNextVolume;
    this->m_fPreviousVolumedB = this->m_fNextVolumedB;
  }
}

// File Line: 603
// RVA: 0xA7E2E0
void __fastcall CAkVPLMixBusNode::Disconnect(CAkVPLMixBusNode *this)
{
  --this->m_uConnectCount;
}

// File Line: 609
// RVA: 0xA7E780
void __fastcall CAkVPLMixBusNode::InitVolumes(CAkVPLMixBusNode *this)
{
  float Volume; // xmm0_4

  if ( this->m_eState != NodeStatePlay )
  {
    Volume = AK::CAkBusCtx::GetVolume(&this->m_BusContext, BusVolumeType_ToNextBusWithEffect);
    CAkBusVolumes::SetNextVolume(this, Volume);
    this->m_fPreviousVolume = this->m_fNextVolume;
    this->m_fPreviousVolumedB = this->m_fNextVolumedB;
  }
}

// File Line: 622
// RVA: 0xA7EA90
__int64 __fastcall CAkVPLMixBusNode::SetAllInsertFx(CAkVPLMixBusNode *this)
{
  unsigned int i; // ebx
  AKRESULT inserted; // eax
  AKRESULT v4; // ebp
  bool BypassAllFX; // al

  for ( i = 0; i < 4; ++i )
  {
    inserted = CAkBusFX::SetInsertFx(this, &this->m_BusContext, i);
    v4 = inserted;
  }
  this->m_bEffectCreated = 1;
  BypassAllFX = AK::CAkBusCtx::GetBypassAllFX(&this->m_BusContext);
  *((_BYTE *)&this->CAkBusFX + 1312) &= ~1u;
  *((_BYTE *)&this->CAkBusFX + 1312) |= BypassAllFX;
  return (unsigned int)v4;
}

// File Line: 637
// RVA: 0xA7EE20
void __fastcall CAkVPLMixBusNode::UpdateBypassFx(CAkVPLMixBusNode *this)
{
  bool BypassAllFX; // al

  BypassAllFX = AK::CAkBusCtx::GetBypassAllFX(&this->m_BusContext);
  *((_BYTE *)&this->CAkBusFX + 1312) &= ~1u;
  *((_BYTE *)&this->CAkBusFX + 1312) |= BypassAllFX;
}

// File Line: 646
// RVA: 0xA7E240
void __fastcall CAkVPLMixBusNode::ConsumeBuffer(
        CAkVPLMixBusNode *this,
        AkAudioBufferBus *io_rBuffer,
        bool in_bPan,
        AkAudioMix *in_PanMix)
{
  bool v8; // zf

  if ( io_rBuffer->uValidFrames )
  {
    if ( !this->m_bEffectCreated )
      CAkVPLMixBusNode::SetAllInsertFx(this);
    v8 = this->m_eState == NodeStateIdle;
    this->m_BufferOut.eState = AK_DataReady;
    if ( v8 )
      this->m_eState = NodeStatePlay;
    ZeroPadBuffer(io_rBuffer);
    io_rBuffer->uValidFrames = io_rBuffer->uMaxFrames;
    CAkMixer::Mix(&this->m_Mixer, io_rBuffer, &this->m_BufferOut, in_bPan, in_PanMix);
  }
}

// File Line: 702
// RVA: 0xA7E1B0
void __fastcall CAkVPLMixBusNode::ConsumeBuffer(CAkVPLMixBusNode *this, AkVPLState *io_rVPLState, AkAudioMix *in_arMix)
{
  bool v6; // zf

  if ( io_rVPLState->uValidFrames )
  {
    if ( !this->m_bEffectCreated )
      CAkVPLMixBusNode::SetAllInsertFx(this);
    v6 = this->m_eState == NodeStateIdle;
    this->m_BufferOut.eState = AK_DataReady;
    if ( v6 )
      this->m_eState = NodeStatePlay;
    ZeroPadBuffer(io_rVPLState);
    io_rVPLState->uValidFrames = io_rVPLState->uMaxFrames;
    CAkMixer::Mix3D(&this->m_Mixer, io_rVPLState, &this->m_BufferOut, in_arMix);
  }
}

// File Line: 794
// RVA: 0xA7E470
void __fastcall CAkVPLMixBusNode::GetResultingBuffer(CAkVPLMixBusNode *this, AkAudioBufferBus **io_rpBuffer)
{
  float m_fNextVolume; // xmm0_4
  float m_fNextVolumedB; // eax

  CAkVPLMixBusNode::ProcessAllFX(this);
  if ( this->m_eState == NodeStatePlay )
    *((_BYTE *)&this->CAkBusFX + 1312) ^= (*((_BYTE *)&this->CAkBusFX + 1312) ^ (2 * *((_BYTE *)&this->CAkBusFX + 1312))) & 2;
  m_fNextVolume = this->m_fNextVolume;
  this->m_BufferOut.m_fPreviousVolume = this->m_fPreviousVolume;
  m_fNextVolumedB = this->m_fNextVolumedB;
  this->m_BufferOut.m_fNextVolume = m_fNextVolume;
  this->m_fPreviousVolume = m_fNextVolume;
  this->m_fPreviousVolumedB = m_fNextVolumedB;
  *io_rpBuffer = &this->m_BufferOut;
  CAkBusVolumes::UpdatePanningVolumes(this);
}

// File Line: 830
// RVA: 0xA7E930
void __fastcall CAkVPLMixBusNode::ProcessAllFX(CAkVPLMixBusNode *this)
{
  __int64 v2; // rsi
  _BYTE *v3; // rbx
  __int64 v4; // rcx
  char v5; // al

  if ( this->m_eState == NodeStatePlay )
  {
    v2 = 4i64;
    v3 = (char *)this->m_aFX + 32;
    do
    {
      if ( this->m_eState == NodeStatePlay )
      {
        v4 = *((_QWORD *)v3 - 2);
        if ( v4 )
        {
          v5 = *v3 | *((_BYTE *)&this->CAkBusFX + 1312);
          if ( (v5 & 1) != 0 )
          {
            if ( (v5 & 2) == 0 )
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
          }
          else
          {
            (*(void (__fastcall **)(__int64, AkAudioBufferBus *))(*(_QWORD *)v4 + 56i64))(v4, &this->m_BufferOut);
          }
          *v3 ^= (*v3 ^ (2 * *v3)) & 2;
        }
      }
      v3 += 40;
      --v2;
    }
    while ( v2 );
  }
}

