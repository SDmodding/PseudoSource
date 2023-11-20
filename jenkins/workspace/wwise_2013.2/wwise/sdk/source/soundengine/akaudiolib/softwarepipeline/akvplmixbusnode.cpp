// File Line: 48
// RVA: 0xA7EE50
void __fastcall CAkBusVolumes::UpdateFinalVolumes(CAkBusVolumes *this)
{
  unsigned int v1; // edx
  unsigned int v2; // er10
  CAkBusVolumes *v3; // r8
  unsigned int i; // er9
  __int64 v5; // rcx
  __int64 v6; // rax
  signed __int64 v7; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm2

  v1 = this->m_uChannelMask;
  v2 = 0;
  v3 = this;
  for ( i = 0; v1; v1 &= v1 - 1 )
    ++i;
  do
  {
    v5 = v2;
    v6 = v2++;
    v5 <<= 6;
    v7 = (v6 + 8) << 6;
    *(__m128 *)((char *)v3->m_FinalVolumes[0].Previous.vector + v5) = *(__m128 *)((char *)v3->m_PanningVolumes[0].Previous.vector
                                                                                + v5);
    *(_OWORD *)((char *)&v3->m_FinalVolumes[0].Previous.aVolumes[4] + v5) = *(_OWORD *)((char *)&v3->m_PanningVolumes[0].Previous.aVolumes[4]
                                                                                      + v5);
    *(__m128 *)((char *)v3->m_PanningVolumes[0].Next.vector + v7) = *(__m128 *)((char *)v3->m_PanningVolumes[0].Next.vector
                                                                              + v5);
    *(_OWORD *)((char *)&v3->m_PanningVolumes[0].Next.aVolumes[4] + v7) = *(_OWORD *)((char *)&v3->m_PanningVolumes[0].Next.aVolumes[4]
                                                                                    + v5);
    v8 = _mm_shuffle_ps((__m128)LODWORD(v3->m_fPreviousVolume), (__m128)LODWORD(v3->m_fPreviousVolume), 0);
    v9 = _mm_mul_ps(v8, *(__m128 *)((char *)v3->m_FinalVolumes[0].Previous.vector + v5));
    *(__m128 *)((char *)&v3->m_FinalVolumes[0].Previous.vector[1] + v5) = _mm_mul_ps(
                                                                            *(__m128 *)((char *)&v3->m_FinalVolumes[0].Previous.vector[1]
                                                                                      + v5),
                                                                            v8);
    *(__m128 *)((char *)v3->m_FinalVolumes[0].Previous.vector + v5) = v9;
    v10 = _mm_shuffle_ps((__m128)LODWORD(v3->m_fNextVolume), (__m128)LODWORD(v3->m_fNextVolume), 0);
    v11 = _mm_mul_ps(*(__m128 *)((char *)v3->m_PanningVolumes[0].Next.vector + v7), v10);
    v12 = _mm_mul_ps(v10, *(__m128 *)((char *)&v3->m_PanningVolumes[0].Next.vector[1] + v7));
    *(__m128 *)((char *)v3->m_PanningVolumes[0].Next.vector + v7) = v11;
    *(__m128 *)((char *)&v3->m_PanningVolumes[0].Next.vector[1] + v7) = v12;
  }
  while ( v2 < i );
}

// File Line: 62
// RVA: 0xA7EF30
void __fastcall CAkBusVolumes::UpdatePanningVolumes(CAkBusVolumes *this)
{
  __int64 v1; // rbp
  CAkBusVolumes *v2; // rdi
  unsigned int v3; // ecx
  unsigned int i; // edx
  unsigned int v5; // ecx
  __int64 v6; // rax
  _DWORD *v7; // rbx
  _DWORD *v8; // rsi
  float v9; // xmm3_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  unsigned int v13; // ecx
  unsigned int j; // edx
  unsigned int v15; // er8
  __int64 v16; // rax
  __int64 v17; // rcx
  __int128 v18; // xmm1
  unsigned __int64 v19; // rcx
  _QWORD *v20; // rax
  __int64 v21; // rcx
  AkSpeakerVolumeMatrixBusCallbackInfo in_rCallbackInfo; // [rsp+40h] [rbp-158h]
  AkSIMDSpeakerVolumes out_pVolumes; // [rsp+90h] [rbp-108h]

  v1 = 0i64;
  v2 = this;
  v3 = this->m_uChannelMask;
  for ( i = 0; v3; v3 &= v3 - 1 )
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
  v7 = (_DWORD *)&v2->m_BusPosParams.m_fPAN_X_2D;
  v8 = (_DWORD *)&v2->m_PrevPosParams.m_fPAN_X_2D;
  v9 = v2->m_BusPosParams.m_fPAN_X_2D;
  if ( v9 != v2->m_PrevPosParams.m_fPAN_X_2D
    || v2->m_PrevPosParams.m_fPAN_Y_2D != v2->m_BusPosParams.m_fPAN_Y_2D
    || v2->m_PrevPosParams.m_fCenterPCT != v2->m_BusPosParams.m_fCenterPCT
    || v2->m_BusPosParams.bIsPannerEnabled != v2->m_PrevPosParams.bIsPannerEnabled )
  {
    v10 = (float)(v9 + 100.0) * 0.0049999999;
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
    if ( !(*((_BYTE *)v2 + 1140) & 1) )
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
    if ( v2->m_uChannelMask & 8 )
    {
      v19 = (unsigned __int64)(j - 1) << 6;
      *(__m128 *)((char *)v2->m_PanningVolumes[0].Next.vector + v19) = 0i64;
      *(_OWORD *)((char *)&v2->m_PanningVolumes[0].Next.aVolumes[4] + v19) = 0i64;
      *(float *)((char *)&v2->m_PanningVolumes[0].Next.volumes.fLfe + v19) = 1.0;
    }
    if ( !(*((_BYTE *)v2 + 1140) & 2) || !v2->m_busID )
      goto LABEL_36;
    in_rCallbackInfo.busID = v2->m_busID;
    in_rCallbackInfo.uChannelMask = v2->m_uChannelMask;
    if ( j )
    {
      v20 = in_rCallbackInfo.pVolumes;
      v1 = j;
      v21 = j;
      do
      {
        *v20 = v2;
        v2 = (CAkBusVolumes *)((char *)v2 + 64);
        ++v20;
        --v21;
      }
      while ( v21 );
    }
    if ( (unsigned int)v1 < 8 )
      memset(&in_rCallbackInfo.pVolumes[v1], 0, 8i64 * (unsigned int)(8 - v1));
    if ( !(unsigned __int8)CAkBusCallbackMgr::DoCallback(g_pBusCallbackMgr, &in_rCallbackInfo) )
    {
LABEL_36:
      *v8 = *v7;
      v8[1] = v7[1];
      v8[2] = v7[2];
      v8[3] = v7[3];
    }
  }
}CallbackInfo) )
    {
LABEL_36:
      *v8 = *v7;
      v8[1] = v7[1];
      v8[2] = v7

// File Line: 124
// RVA: 0xA7E6C0
void __fastcall CAkBusVolumes::InitPan(CAkBusVolumes *this, CAkParameterNodeBase *in_pBus, unsigned int in_ChanMsk, unsigned int in_uParentMask)
{
  CAkBusVolumes *v4; // rbx
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int i; // er8
  __int64 v8; // rax

  v4 = this;
  this->m_uChannelMask = in_ChanMsk;
  this->m_uParentMask = in_uParentMask;
  if ( in_pBus && *((_BYTE *)in_pBus + 83) & 4 )
  {
    *((_BYTE *)this + 1140) |= 1u;
    CAkParameterNodeBase::Get2DParams(in_pBus, 0i64, &this->m_BusPosParams);
  }
  else
  {
    *((_BYTE *)this + 1140) &= 0xFEu;
    this->m_BusPosParams.m_fPAN_X_2D = 0.5;
    this->m_BusPosParams.m_fPAN_Y_2D = 1.0;
    this->m_BusPosParams.m_fCenterPCT = 100.0;
    this->m_BusPosParams.bIsPannerEnabled = 0;
  }
  CAkBusVolumes::UpdatePanningVolumes(v4);
  v5 = v4->m_uChannelMask;
  v6 = 0;
  for ( i = 0; v5; v5 &= v5 - 1 )
    ++i;
  do
  {
    v8 = v6++;
    v8 <<= 6;
    *(__m128 *)((char *)v4->m_PanningVolumes[0].Previous.vector + v8) = *(__m128 *)((char *)v4->m_PanningVolumes[0].Next.vector
                                                                                  + v8);
    *(_OWORD *)((char *)&v4->m_PanningVolumes[0].Previous.aVolumes[4] + v8) = *(_OWORD *)((char *)&v4->m_PanningVolumes[0].Next.aVolumes[4]
                                                                                        + v8);
  }
  while ( v6 < i );
}

// File Line: 134
// RVA: 0xA7EDC0
void __fastcall CAkBusVolumes::Update2DParams(CAkBusVolumes *this, CAkParameterNodeBase *in_pBus)
{
  if ( in_pBus && *((_BYTE *)in_pBus + 83) & 4 )
  {
    *((_BYTE *)this + 1140) |= 1u;
    CAkParameterNodeBase::Get2DParams(in_pBus, 0i64, &this->m_BusPosParams);
  }
  else
  {
    *((_BYTE *)this + 1140) &= 0xFEu;
    this->m_BusPosParams.m_fPAN_X_2D = 0.5;
    this->m_BusPosParams.m_fPAN_Y_2D = 1.0;
    this->m_BusPosParams.m_fCenterPCT = 100.0;
    this->m_BusPosParams.bIsPannerEnabled = 0;
  }
}

// File Line: 151
// RVA: 0xA7E8E0
void __fastcall CAkBusVolumes::PositioningChangeNotification(CAkBusVolumes *this, float in_RTPCValue, AkRTPC_ParameterID in_ParameterID)
{
  __int32 v3; // er8
  int v4; // er8
  int v5; // er8

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
  CAkBusFX *v1; // rbx

  v1 = this;
  CAkBusVolumes::CAkBusVolumes((CAkBusVolumes *)this->m_PanningVolumes);
  *((_BYTE *)v1->m_aFX + 32) &= 0xFCu;
  v1->m_aFX[0].id = -1;
  v1->m_aFX[1].id = -1;
  v1->m_aFX[0].pParam = 0i64;
  v1->m_aFX[0].pEffect = 0i64;
  v1->m_aFX[0].pBusFXContext = 0i64;
  v1->m_aFX[1].pParam = 0i64;
  v1->m_aFX[1].pEffect = 0i64;
  v1->m_aFX[1].pBusFXContext = 0i64;
  *((_BYTE *)&v1->m_aFX[1] + 32) &= 0xFCu;
  v1->m_aFX[2].id = -1;
  v1->m_aFX[2].pParam = 0i64;
  v1->m_aFX[2].pEffect = 0i64;
  v1->m_aFX[2].pBusFXContext = 0i64;
  *((_BYTE *)&v1->m_aFX[2] + 32) &= 0xFCu;
  v1->m_aFX[3].id = -1;
  v1->m_aFX[3].pParam = 0i64;
  v1->m_aFX[3].pEffect = 0i64;
  v1->m_aFX[3].pBusFXContext = 0i64;
  *((_BYTE *)&v1->m_aFX[3] + 32) &= 0xFCu;
  *((_BYTE *)v1 + 1312) &= 0xFCu;
}

// File Line: 195
// RVA: 0xA7EB10
__int64 __fastcall CAkBusFX::SetInsertFx(CAkBusFX *this, AK::CAkBusCtx *in_busCtx, unsigned int in_uFXIndex)
{
  AK::CAkBusCtx *v3; // rbx
  CAkBusFX *v4; // rbp
  __int64 v5; // r15
  int v6; // edi
  CAkFxBase *v7; // r9
  unsigned int v8; // ebx
  signed __int64 v9; // r14
  AK::IAkPluginParam *v10; // rcx
  AK::IAkRTPCSubscriber *v11; // rax
  signed int v12; // esi
  CAkBusFXContext *v14; // rax
  __int64 v15; // rax
  bool v16; // al
  unsigned int v17; // edx
  unsigned int v18; // eax
  signed int v19; // eax
  unsigned int v20; // er8
  unsigned int i; // ecx
  __int64 v22; // rcx
  __int64 v23; // r9
  int v24; // edi
  __int64 v25; // r8
  AkFXDesc out_rFXInfo; // [rsp+30h] [rbp-38h]
  unsigned int v27; // [rsp+88h] [rbp+20h]
  unsigned int v28; // [rsp+8Ch] [rbp+24h]

  v3 = in_busCtx;
  v4 = this;
  v5 = in_uFXIndex;
  CAkBusFX::DropFx(this, in_uFXIndex);
  v6 = 0;
  out_rFXInfo.pFx.m_pT = 0i64;
  AK::CAkBusCtx::GetFX(v3, v5, &out_rFXInfo);
  v7 = out_rFXInfo.pFx.m_pT;
  if ( !out_rFXInfo.pFx.m_pT )
  {
    v8 = 1;
    goto LABEL_10;
  }
  v9 = (signed __int64)v4 + 8 * (v5 + 4 * (v5 + 36));
  *(_DWORD *)v9 = out_rFXInfo.pFx.m_pT->m_FXID;
  v10 = v7->m_pParam;
  if ( !v10 )
  {
    v8 = 2;
    goto LABEL_10;
  }
  v11 = (AK::IAkRTPCSubscriber *)v10->vfptr[1].__vecDelDtor(
                                   (AK::IAkRTPCSubscriber *)&v10->vfptr,
                                   (unsigned int)&AkFXMemAlloc::m_instanceLower);
  *(_QWORD *)(v9 + 8) = v11;
  if ( v11 )
  {
    CAkFxBase::SubscribeRTPC(out_rFXInfo.pFx.m_pT, v11, 0i64);
    v14 = (CAkBusFXContext *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x30ui64);
    if ( v14 )
      CAkBusFXContext::CAkBusFXContext(v14, v4, v5, v3);
    else
      v15 = 0i64;
    *(_QWORD *)(v9 + 24) = v15;
    v12 = 2;
    if ( v15 )
    {
      v16 = out_rFXInfo.bIsBypassed;
      *(_BYTE *)(v9 + 32) &= 0xFEu;
      v17 = *(_DWORD *)v9;
      *(_BYTE *)(v9 + 32) |= v16;
      v18 = CAkEffectsMgr::Alloc(
              (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr,
              v17,
              (AK::IAkPlugin **)(v9 + 16));
      if ( v18 != 1 )
      {
        v8 = v18;
        goto LABEL_9;
      }
      v19 = (*(__int64 (__fastcall **)(_QWORD, unsigned int *))(**(_QWORD **)(v9 + 16) + 24i64))(
              *(_QWORD *)(v9 + 16),
              &v27);
      v12 = v19;
      if ( BYTE1(v28) )
      {
        v12 = 2;
      }
      else if ( v19 == 1 )
      {
        v20 = v4->m_BufferOut.uChannelMask;
        for ( i = v20; i; i &= i - 1 )
          ++v6;
        v22 = *(_QWORD *)(v9 + 16);
        v23 = *(_QWORD *)(v9 + 8);
        v27 = AkAudioLibSettings::g_pipelineCoreFrequency;
        v24 = v20 & 0x3FFFF | (v6 << 26) & 0x1F000000;
        v25 = *(_QWORD *)(v9 + 24);
        v28 = v24 | 0xA0800000;
        v12 = (*(__int64 (__fastcall **)(__int64, AkFXMemAlloc *, __int64, __int64, unsigned int *))(*(_QWORD *)v22 + 48i64))(
                v22,
                &AkFXMemAlloc::m_instanceLower,
                v25,
                v23,
                &v27);
        if ( v12 == 1 )
        {
          v12 = (*(__int64 (**)(void))(**(_QWORD **)(v9 + 16) + 16i64))();
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
  CAkBusFX::DropFx(v4, v5);
LABEL_8:
  v8 = v12;
LABEL_9:
  v7 = out_rFXInfo.pFx.m_pT;
LABEL_10:
  if ( v7 )
    v7->vfptr->Release((CAkIndexable *)&v7->vfptr);
  return v8;
}

// File Line: 314
// RVA: 0xA7ED40
void __fastcall CAkBusFX::SetInsertFxBypass(CAkBusFX *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  if ( in_uTargetMask & 1 )
  {
    *((_BYTE *)this->m_aFX + 32) &= 0xFEu;
    *((_BYTE *)this->m_aFX + 32) |= in_bitsFXBypass & 1;
  }
  if ( in_uTargetMask & 2 )
  {
    *((_BYTE *)&this->m_aFX[1] + 32) &= 0xFEu;
    *((_BYTE *)&this->m_aFX[1] + 32) |= (in_bitsFXBypass >> 1) & 1;
  }
  if ( in_uTargetMask & 4 )
  {
    *((_BYTE *)&this->m_aFX[2] + 32) &= 0xFEu;
    *((_BYTE *)&this->m_aFX[2] + 32) |= (in_bitsFXBypass >> 2) & 1;
  }
  if ( in_uTargetMask & 8 )
  {
    *((_BYTE *)&this->m_aFX[3] + 32) &= 0xFEu;
    *((_BYTE *)&this->m_aFX[3] + 32) |= (in_bitsFXBypass >> 3) & 1;
  }
  if ( in_uTargetMask & 0x10 )
  {
    *((_BYTE *)this + 1312) &= 0xFEu;
    *((_BYTE *)this + 1312) |= (in_bitsFXBypass >> 4) & 1;
  }
}

// File Line: 341
// RVA: 0xA7E3A0
void __fastcall CAkBusFX::DropFx(CAkBusFX *this)
{
  AK::IAkInPlaceEffectPlugin **v1; // rbx
  signed __int64 v2; // rbp
  AK::IAkInPlaceEffectPlugin *v3; // rsi
  int v4; // edi
  void *v5; // rdx

  v1 = &this->m_aFX[0].pEffect;
  v2 = 4i64;
  do
  {
    if ( *v1 )
    {
      (*v1)->vfptr->Term((AK::IAkPlugin *)&(*v1)->vfptr, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr);
      *v1 = 0i64;
    }
    v3 = v1[1];
    if ( v3 )
    {
      v4 = g_LEngineDefaultPoolId;
      v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v1[1]->vfptr, 0);
      AK::MemoryMgr::Free(v4, v3);
      v1[1] = 0i64;
    }
    v5 = *(v1 - 1);
    *((_DWORD *)v1 - 4) = -1;
    if ( v5 )
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v5);
      ((void (__fastcall *)(_QWORD, AkFXMemAlloc *))(*(v1 - 1))->vfptr->SupportMediaRelocation)(
        *(v1 - 1),
        &AkFXMemAlloc::m_instanceLower);
      *(v1 - 1) = 0i64;
    }
    v1 += 5;
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

  v2 = (char *)this + 8 * (in_uFXIndex + 4 * (in_uFXIndex + 36i64));
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
signed __int64 __fastcall CAkVPLMixBusNode::Init(CAkVPLMixBusNode *this, unsigned int in_uChannelMask, unsigned int in_uParentMask, unsigned __int16 in_uMaxFrames, AK::CAkBusCtx in_busContext)
{
  CAkVPLMixBusNode *v5; // rdi
  AK::CAkBusCtx *v6; // rcx
  signed int v7; // ebp
  unsigned int v8; // ebx
  unsigned int v9; // esi
  unsigned int v10; // eax
  bool v11; // al
  CAkBus *v12; // rcx
  signed __int64 result; // rax
  unsigned int v14; // ecx
  int i; // edx
  unsigned __int64 v16; // rdx
  void *v17; // rax
  void *v18; // rbx

  v5 = this;
  v6 = &this->m_BusContext;
  v6->m_pBus = in_busContext.m_pBus;
  v7 = in_uMaxFrames;
  v8 = in_uParentMask;
  v9 = in_uChannelMask;
  v10 = AK::CAkBusCtx::ID(v6);
  v5->m_busID = v10;
  v11 = CAkBusCallbackMgr::IsCallbackEnabled(g_pBusCallbackMgr, v10);
  *((_BYTE *)&v5->0 + 1140) &= 0xFDu;
  v5->m_bEffectCreated = 0;
  *((_BYTE *)&v5->0 + 1140) |= 2 * v11;
  CAkBusVolumes::InitPan(
    (CAkBusVolumes *)v5->m_PanningVolumes,
    (CAkParameterNodeBase *)&in_busContext.m_pBus->vfptr,
    v9,
    v8);
  v5->m_Mixer.m_usMaxFrames = v7;
  v5->m_Mixer.m_fOneOverNumFrames = 1.0 / (float)v7;
  v12 = v5->m_BusContext.m_pBus;
  if ( v12 )
  {
    ((void (*)(void))v12->vfptr->AddRef)();
    if ( !((unsigned __int8 (__fastcall *)(CAkBus *, signed __int64))v5->m_BusContext.m_pBus->vfptr[9].Release)(
            v5->m_BusContext.m_pBus,
            3i64) )
      return 2i64;
  }
  v5->m_eState = 4;
  v5->m_fPreviousVolume = 1.0;
  v5->m_fNextVolume = 1.0;
  v14 = v9;
  *(_QWORD *)&v5->m_fNextVolumedB = 0i64;
  for ( i = 0; v14; v14 &= v14 - 1 )
    ++i;
  v5->m_uConnectCount = 0;
  v5->m_ulBufferOutSize = 4 * i * v7;
  v5->m_BufferOut.pData = 0i64;
  *(_QWORD *)&v5->m_BufferOut.eState = 43i64;
  v16 = v5->m_ulBufferOutSize;
  v5->m_BufferOut.eState = 17;
  v17 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, v16, 0x10u);
  v18 = v17;
  if ( !v17 )
    return 52i64;
  memset(v17, 0, v5->m_ulBufferOutSize);
  v5->m_BufferOut.pData = v18;
  v5->m_BufferOut.uMaxFrames = v7;
  v5->m_BufferOut.uValidFrames = 0;
  v5->m_BufferOut.uChannelMask = v9;
  result = 1i64;
  *(_QWORD *)&v5->m_BufferOut.m_fNextVolume = 0i64;
  return result;
}

// File Line: 501
// RVA: 0xA7E0F0
void __fastcall CAkVPLMixBusNode::~CAkVPLMixBusNode(CAkVPLMixBusNode *this)
{
  CAkVPLMixBusNode *v1; // rbx
  CAkBus *v2; // rcx
  void *v3; // rdx

  v1 = this;
  v2 = this->m_BusContext.m_pBus;
  if ( v2 )
  {
    ((void (__fastcall *)(CAkBus *, signed __int64))v2->vfptr[9].Category)(v2, 3i64);
    ((void (*)(void))v1->m_BusContext.m_pBus->vfptr->Release)();
  }
  CAkBusFX::DropFx((CAkBusFX *)v1->m_PanningVolumes);
  v3 = v1->m_BufferOut.pData;
  if ( v3 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
    v1->m_BufferOut.pData = 0i64;
  }
}

// File Line: 533
// RVA: 0xA7E9D0
void __fastcall CAkVPLMixBusNode::ReleaseBuffer(CAkVPLMixBusNode *this)
{
  void *v1; // r9
  VPLNodeState v2; // eax

  v1 = this->m_BufferOut.pData;
  if ( v1 )
  {
    v2 = 1;
    if ( this->m_BufferOut.eState == 17 )
      v2 = 4;
    this->m_BufferOut.eState = 17;
    this->m_eState = v2;
    this->m_BufferOut.uValidFrames = 0;
  }
  memset(v1, 0, this->m_ulBufferOutSize);
}

// File Line: 543
// RVA: 0xA7E7D0
bool __fastcall CAkVPLMixBusNode::IsPanning(CAkVPLMixBusNode *this)
{
  CAkBus *v1; // rax

  v1 = this->m_BusContext.m_pBus;
  if ( v1 )
    LOBYTE(v1) = (*((_BYTE *)&v1->0 + 83) >> 2) & 1;
  return (char)v1;
}

// File Line: 556
// RVA: 0xA7EA20
void __fastcall CAkVPLMixBusNode::ResetNextVolume(CAkVPLMixBusNode *this, float in_dBVolume)
{
  CAkVPLMixBusNode *v2; // rbx
  CAkBus *v3; // rcx

  v2 = this;
  CAkBusVolumes::SetNextVolume((CAkBusVolumes *)this->m_PanningVolumes, in_dBVolume);
  v3 = v2->m_BusContext.m_pBus;
  if ( v3 && *((_BYTE *)&v3->0 + 83) & 4 )
  {
    *((_BYTE *)&v2->0 + 1140) |= 1u;
    CAkParameterNodeBase::Get2DParams((CAkParameterNodeBase *)&v3->vfptr, 0i64, &v2->m_BusPosParams);
  }
  else
  {
    *((_BYTE *)&v2->0 + 1140) &= 0xFEu;
    v2->m_BusPosParams.m_fPAN_X_2D = 0.5;
    v2->m_BusPosParams.m_fPAN_Y_2D = 1.0;
    v2->m_BusPosParams.m_fCenterPCT = 100.0;
    v2->m_BusPosParams.bIsPannerEnabled = 0;
  }
}

// File Line: 589
// RVA: 0xA7E150
void __fastcall CAkVPLMixBusNode::Connect(CAkVPLMixBusNode *this)
{
  CAkVPLMixBusNode *v1; // rbx
  float v2; // xmm0_4
  float v3; // eax

  v1 = this;
  if ( this->m_eState == 1 )
  {
    ++this->m_uConnectCount;
  }
  else
  {
    v2 = AK::CAkBusCtx::GetVolume(&this->m_BusContext, 0);
    CAkBusVolumes::SetNextVolume((CAkBusVolumes *)v1->m_PanningVolumes, v2);
    v3 = v1->m_fNextVolume;
    ++v1->m_uConnectCount;
    v1->m_fPreviousVolume = v3;
    v1->m_fPreviousVolumedB = v1->m_fNextVolumedB;
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
  CAkVPLMixBusNode *v1; // rbx
  float v2; // xmm0_4

  v1 = this;
  if ( this->m_eState != 1 )
  {
    v2 = AK::CAkBusCtx::GetVolume(&this->m_BusContext, 0);
    CAkBusVolumes::SetNextVolume((CAkBusVolumes *)v1->m_PanningVolumes, v2);
    v1->m_fPreviousVolume = v1->m_fNextVolume;
    v1->m_fPreviousVolumedB = v1->m_fNextVolumedB;
  }
}

// File Line: 622
// RVA: 0xA7EA90
__int64 __fastcall CAkVPLMixBusNode::SetAllInsertFx(CAkVPLMixBusNode *this)
{
  CAkVPLMixBusNode *v1; // rdi
  unsigned int v2; // ebx
  AKRESULT v3; // eax
  AKRESULT v4; // ebp
  bool v5; // al

  v1 = this;
  v2 = 0;
  do
  {
    v3 = CAkBusFX::SetInsertFx((CAkBusFX *)v1->m_PanningVolumes, &v1->m_BusContext, v2++);
    v4 = v3;
  }
  while ( v2 < 4 );
  v1->m_bEffectCreated = 1;
  v5 = AK::CAkBusCtx::GetBypassAllFX(&v1->m_BusContext);
  *((_BYTE *)&v1->0 + 1312) &= 0xFEu;
  *((_BYTE *)&v1->0 + 1312) |= v5;
  return (unsigned int)v4;
}

// File Line: 637
// RVA: 0xA7EE20
void __fastcall CAkVPLMixBusNode::UpdateBypassFx(CAkVPLMixBusNode *this)
{
  CAkVPLMixBusNode *v1; // rbx
  bool v2; // al

  v1 = this;
  v2 = AK::CAkBusCtx::GetBypassAllFX(&this->m_BusContext);
  *((_BYTE *)&v1->0 + 1312) &= 0xFEu;
  *((_BYTE *)&v1->0 + 1312) |= v2;
}

// File Line: 646
// RVA: 0xA7E240
void __fastcall CAkVPLMixBusNode::ConsumeBuffer(CAkVPLMixBusNode *this, AkAudioBufferBus *io_rBuffer, bool in_bPan, AkAudioMix *in_PanMix)
{
  AkAudioMix *v4; // rsi
  bool v5; // bp
  AkAudioBufferBus *v6; // rdi
  CAkVPLMixBusNode *v7; // rbx
  bool v8; // zf

  v4 = in_PanMix;
  v5 = in_bPan;
  v6 = io_rBuffer;
  v7 = this;
  if ( io_rBuffer->uValidFrames )
  {
    if ( !this->m_bEffectCreated )
      CAkVPLMixBusNode::SetAllInsertFx(this);
    v8 = v7->m_eState == 4;
    v7->m_BufferOut.eState = 45;
    if ( v8 )
      v7->m_eState = 1;
    ZeroPadBuffer((AkAudioBuffer *)&v6->pData);
    v6->uValidFrames = v6->uMaxFrames;
    CAkMixer::Mix(&v7->m_Mixer, v6, (AkPipelineBufferBase *)&v7->m_BufferOut.pData, v5, v4);
  }
}

// File Line: 702
// RVA: 0xA7E1B0
void __fastcall CAkVPLMixBusNode::ConsumeBuffer(CAkVPLMixBusNode *this, AkVPLState *io_rVPLState, AkAudioMix *in_arMix)
{
  AkAudioMix *v3; // rsi
  AkVPLState *v4; // rdi
  CAkVPLMixBusNode *v5; // rbx
  bool v6; // zf

  v3 = in_arMix;
  v4 = io_rVPLState;
  v5 = this;
  if ( io_rVPLState->uValidFrames )
  {
    if ( !this->m_bEffectCreated )
      CAkVPLMixBusNode::SetAllInsertFx(this);
    v6 = v5->m_eState == 4;
    v5->m_BufferOut.eState = 45;
    if ( v6 )
      v5->m_eState = 1;
    ZeroPadBuffer((AkAudioBuffer *)&v4->pData);
    v4->uValidFrames = v4->uMaxFrames;
    CAkMixer::Mix3D(
      &v5->m_Mixer,
      (AkPipelineBufferBase *)&v4->pData,
      (AkPipelineBufferBase *)&v5->m_BufferOut.pData,
      v3);
  }
}

// File Line: 794
// RVA: 0xA7E470
void __fastcall CAkVPLMixBusNode::GetResultingBuffer(CAkVPLMixBusNode *this, AkAudioBufferBus **io_rpBuffer)
{
  AkAudioBufferBus **v2; // rdi
  CAkVPLMixBusNode *v3; // rbx
  float v4; // xmm0_4
  float v5; // eax

  v2 = io_rpBuffer;
  v3 = this;
  CAkVPLMixBusNode::ProcessAllFX(this);
  if ( v3->m_eState == 1 )
    *((_BYTE *)&v3->0 + 1312) ^= (*((_BYTE *)&v3->0 + 1312) ^ 2 * *((_BYTE *)&v3->0 + 1312)) & 2;
  v4 = v3->m_fNextVolume;
  v3->m_BufferOut.m_fPreviousVolume = v3->m_fPreviousVolume;
  v5 = v3->m_fNextVolumedB;
  v3->m_BufferOut.m_fNextVolume = v4;
  v3->m_fPreviousVolume = v4;
  v3->m_fPreviousVolumedB = v5;
  *v2 = &v3->m_BufferOut;
  CAkBusVolumes::UpdatePanningVolumes((CAkBusVolumes *)v3->m_PanningVolumes);
}

// File Line: 830
// RVA: 0xA7E930
void __fastcall CAkVPLMixBusNode::ProcessAllFX(CAkVPLMixBusNode *this)
{
  CAkVPLMixBusNode *v1; // rdi
  signed __int64 v2; // rsi
  _BYTE *v3; // rbx
  __int64 v4; // rcx
  char v5; // al

  v1 = this;
  if ( this->m_eState == 1 )
  {
    v2 = 4i64;
    v3 = (char *)this->m_aFX + 32;
    do
    {
      if ( v1->m_eState == 1 )
      {
        v4 = *((_QWORD *)v3 - 2);
        if ( v4 )
        {
          v5 = *v3 | *((_BYTE *)&v1->0 + 1312);
          if ( v5 & 1 )
          {
            if ( !(v5 & 2) )
              (*(void (**)(void))(*(_QWORD *)v4 + 16i64))();
          }
          else
          {
            (*(void (__fastcall **)(__int64, AkAudioBufferBus *))(*(_QWORD *)v4 + 56i64))(v4, &v1->m_BufferOut);
          }
          *v3 ^= (*v3 ^ 2 * *v3) & 2;
        }
      }
      v3 += 40;
      --v2;
    }
    while ( v2 );
  }
}

