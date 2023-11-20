// File Line: 30
// RVA: 0xA905B0
void __fastcall CAkSplitterBus::PlayerSlot::Term(CAkSplitterBus::PlayerSlot *this)
{
  CAkSplitterBus::PlayerSlot *v1; // rbx
  CAkVPLMixBusNode *v2; // rcx
  CAkVPLMixBusNode *v3; // rdi
  int v4; // esi
  CAkVPLMixBusNode *v5; // rdi
  int v6; // esi

  v1 = this;
  v2 = this->m_pFeedbackMixBus;
  if ( v2 )
  {
    CAkVPLMixBusNode::Disconnect(v2);
    v3 = v1->m_pFeedbackMixBus;
    v4 = g_LEngineDefaultPoolId;
    if ( v3 )
    {
      CAkVPLMixBusNode::~CAkVPLMixBusNode(v3);
      AK::MemoryMgr::Free(v4, v3);
    }
    v1->m_pFeedbackMixBus = 0i64;
  }
  if ( v1->m_pAudioMixBus )
  {
    CAkVPLMixBusNode::Disconnect(v1->m_pAudioMixBus);
    v5 = v1->m_pAudioMixBus;
    v6 = g_LEngineDefaultPoolId;
    if ( v1->m_pAudioMixBus )
    {
      CAkVPLMixBusNode::~CAkVPLMixBusNode(v5);
      AK::MemoryMgr::Free(v6, v5);
    }
    v1->m_pAudioMixBus = 0i64;
  }
}

// File Line: 51
// RVA: 0xA8F9E0
void __fastcall CAkSplitterBus::CAkSplitterBus(CAkSplitterBus *this)
{
  this->m_aBusses.m_pItems = 0i64;
  *(_QWORD *)&this->m_aBusses.m_uLength = 0i64;
  *(_WORD *)&this->m_iMaxPlayers = 0;
}

// File Line: 57
// RVA: 0xA8FA00
void __fastcall CAkSplitterBus::~CAkSplitterBus(CAkSplitterBus *this)
{
  CAkSplitterBus::Term(this);
}

// File Line: 62
// RVA: 0xA90540
signed __int64 __fastcall CAkSplitterBus::Term(CAkSplitterBus *this)
{
  __int64 v1; // rdi
  CAkSplitterBus *v2; // rbx

  v1 = 0i64;
  v2 = this;
  if ( this->m_aBusses.m_uLength )
  {
    do
    {
      CAkSplitterBus::PlayerSlot::Term(&v2->m_aBusses.m_pItems[v1]);
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_aBusses.m_uLength );
  }
  if ( v2->m_aBusses.m_pItems )
  {
    v2->m_aBusses.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_aBusses.m_pItems);
    v2->m_aBusses.m_pItems = 0i64;
    v2->m_aBusses.m_ulReserved = 0;
  }
  return 1i64;
}

// File Line: 72
// RVA: 0xA8FA10
signed __int64 __fastcall CAkSplitterBus::AddBus(CAkSplitterBus *this, char in_iPlayerID, unsigned int in_iDeviceID, unsigned int in_MixingFormat)
{
  __int64 v4; // rbp
  unsigned int v5; // er12
  unsigned __int8 v6; // r8
  unsigned int v7; // er15
  unsigned __int8 v8; // al
  bool v9; // r13
  CAkSplitterBus *v10; // rdi
  unsigned int v11; // esi
  bool v12; // r14
  int v13; // er15
  int v14; // ecx
  int v15; // er14
  size_t v16; // r13
  __int64 v17; // r15
  int v18; // ebp
  signed int v19; // edx
  unsigned int v20; // er10
  int v21; // er11
  signed __int64 v22; // r8
  __int64 v23; // rax
  bool v24; // zf
  signed __int64 v25; // rsi
  CAkBusFX *v26; // rax
  CAkVPLMixBusNode *v27; // rdi
  unsigned int v28; // ebp
  int v29; // ebx
  bool v31; // [rsp+70h] [rbp+8h]
  unsigned __int8 v32; // [rsp+78h] [rbp+10h]
  unsigned int v33; // [rsp+88h] [rbp+20h]

  v33 = in_MixingFormat;
  v32 = in_iPlayerID;
  v4 = (unsigned __int8)this->m_iMaxDevices;
  v5 = in_iDeviceID;
  v6 = this->m_iMaxPlayers;
  v7 = in_MixingFormat;
  v8 = in_iPlayerID;
  v9 = (unsigned __int8)in_iPlayerID >= v6;
  v10 = this;
  v11 = 0;
  v31 = (unsigned __int8)in_iPlayerID >= v6;
  if ( this->m_iMaxDevices )
  {
    do
    {
      if ( this->m_aBusses.m_pItems[v11].m_DeviceID == v5 )
        break;
      ++v11;
    }
    while ( v11 < (unsigned int)v4 );
    v8 = in_iPlayerID;
  }
  v12 = v11 == (_DWORD)v4;
  if ( (unsigned __int8)in_iPlayerID >= v6 || v12 )
  {
    v13 = v6;
    v14 = v8 + 1;
    if ( v6 > v14 )
      LOBYTE(v14) = v6;
    v10->m_iMaxPlayers = v14;
    if ( v12 )
      v10->m_iMaxDevices = v4 + 1;
    if ( !AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Resize(
            &v10->m_aBusses,
            (unsigned __int8)v10->m_iMaxDevices * (unsigned __int8)v14) )
      return 2i64;
    if ( v12 )
    {
      v15 = v13 - 1;
      if ( v13 - 1 >= 0 )
      {
        v16 = 24 * v4;
        v17 = (unsigned int)(v4 * v15);
        v18 = -(signed int)v4;
        do
        {
          memmove(
            &v10->m_aBusses.m_pItems[v15 * (unsigned int)(unsigned __int8)v10->m_iMaxDevices],
            &v10->m_aBusses.m_pItems[v17],
            v16);
          v17 = (unsigned int)(v18 + v17);
          --v15;
        }
        while ( v15 >= 0 );
        v9 = v31;
      }
      v19 = 0;
      if ( v10->m_iMaxPlayers > 0u )
      {
        do
          v10->m_aBusses.m_pItems[++v19 * (unsigned int)(unsigned __int8)v10->m_iMaxDevices - 1].m_DeviceID = v5;
        while ( v19 < (unsigned __int8)v10->m_iMaxPlayers );
      }
    }
    if ( v9 )
    {
      v20 = 0;
      v21 = (unsigned __int8)v10->m_iMaxDevices * ((unsigned __int8)v10->m_iMaxPlayers - 1);
      if ( v10->m_iMaxDevices )
      {
        do
        {
          v22 = v20;
          v23 = v20++ + v21;
          v10->m_aBusses.m_pItems[v23].m_DeviceID = v10->m_aBusses.m_pItems[v22].m_DeviceID;
        }
        while ( v20 < (unsigned __int8)v10->m_iMaxDevices );
      }
    }
    v7 = v33;
  }
  v24 = v10->m_aBusses.m_pItems[v11 + (unsigned __int8)v10->m_iMaxDevices * v32].m_pFeedbackMixBus == 0i64;
  v25 = (signed __int64)&v10->m_aBusses.m_pItems[v11 + (unsigned __int8)v10->m_iMaxDevices * v32];
  if ( !v24 )
    return 1i64;
  v26 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x550ui64);
  v27 = (CAkVPLMixBusNode *)v26;
  if ( v26 )
  {
    CAkBusFX::CAkBusFX(v26);
    v27->m_BusContext.m_pBus = 0i64;
    *(_DWORD *)(v25 + 20) = v7;
    v28 = CAkVPLMixBusNode::Init(v27, v7, v7, 8u, 0i64);
    if ( v28 != 1 )
    {
      v29 = g_LEngineDefaultPoolId;
      CAkVPLMixBusNode::~CAkVPLMixBusNode(v27);
      AK::MemoryMgr::Free(v29, v27);
      return v28;
    }
    CAkVPLMixBusNode::Connect(v27);
    *(_QWORD *)(v25 + 8) = v27;
    return 1i64;
  }
  return 2i64;
}

// File Line: 154
// RVA: 0xA90420
signed __int64 __fastcall CAkSplitterBus::RemoveBus(CAkSplitterBus *this, char in_iPlayerID, unsigned int in_iDeviceID)
{
  unsigned __int8 v3; // r10
  CAkSplitterBus *v4; // r9
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned int *v8; // rax

  v3 = in_iPlayerID;
  v4 = this;
  if ( (unsigned __int8)in_iPlayerID >= this->m_iMaxPlayers )
    return 2i64;
  v6 = (unsigned __int8)this->m_iMaxDevices;
  v7 = 0;
  if ( v4->m_iMaxDevices )
  {
    v8 = &v4->m_aBusses.m_pItems->m_DeviceID;
    do
    {
      if ( *v8 == in_iDeviceID )
        break;
      ++v7;
      v8 += 6;
    }
    while ( v7 < v6 );
  }
  if ( v7 == v6 )
    return 2i64;
  CAkSplitterBus::PlayerSlot::Term(&v4->m_aBusses.m_pItems[v7 + v6 * v3]);
  return 1i64;
}

// File Line: 177
// RVA: 0xA90180
void __fastcall CAkSplitterBus::MixFeedbackBuffer(CAkSplitterBus *this, AkRunningVPL *io_runningVPL, unsigned int in_uPlayers)
{
  CAkVPLSrcNode *v3; // rbx
  AkRunningVPL *v4; // rsi
  unsigned int v5; // edx
  CAkSplitterBus *v6; // r15
  CAkPBI *v7; // rbx
  char v8; // cl
  AkFeedbackParams *v9; // rdi
  bool v10; // r13
  __int128 v11; // xmm1
  int v12; // er14
  __int128 v13; // xmm1
  int v14; // ecx
  unsigned __int64 v15; // rcx
  signed __int64 v16; // rax
  void *v17; // rsp
  unsigned __int8 v18; // bl
  int v19; // esi
  unsigned int v20; // eax
  int v21; // er10
  int v22; // er8
  __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rax
  signed __int64 v26; // rcx
  unsigned int v27; // er9
  unsigned int v28; // er8
  CAkSplitterBus::PlayerSlot *v29; // r11
  __int64 v30; // rax
  CAkVPLMixBusNode *v31; // rcx
  AkAudioMix out_pMix; // [rsp+20h] [rbp+0h]
  unsigned int v33; // [rsp+A0h] [rbp+80h]

  v33 = in_uPlayers;
  v3 = io_runningVPL->pCbx->m_pSources[0];
  v4 = io_runningVPL;
  v5 = 0;
  v6 = this;
  if ( v3 )
    v7 = v3->m_pCtx;
  else
    v7 = 0i64;
  if ( !(*((_BYTE *)v7 + 374) & 0x40) )
  {
    CAkPBI::ValidateFeedbackParameters(v7);
    v5 = 0;
  }
  v8 = *((_BYTE *)v7 + 371);
  v9 = v7->m_pFeedbackInfo;
  v10 = (v8 & 0xC) == 4 && (v8 & 3) == 1;
  v11 = *(_OWORD *)&v4->state.uMaxFrames;
  v12 = 0;
  out_pMix.Next.vector[0] = *(__m128 *)&v4->state.pData;
  *(_OWORD *)&out_pMix.Next.aVolumes[4] = v11;
  v13 = *(_OWORD *)&v4->state.posInfo.uFileEnd;
  out_pMix.Previous.vector[0] = *(__m128 *)&v4->state.pMarkers;
  *(_OWORD *)&out_pMix.Previous.aVolumes[4] = v13;
  v14 = v9->m_uChannelMask;
  if ( v9->m_uChannelMask )
  {
    do
    {
      ++v12;
      v14 &= v14 - 1;
    }
    while ( v14 );
  }
  v15 = (unsigned __int64)(v12 * (unsigned int)(unsigned __int8)v6->m_iMaxPlayers) << 6;
  v16 = v15 + 15;
  if ( v15 + 15 <= v15 )
    v16 = 1152921504606846960i64;
  v17 = alloca(v16);
  if ( !v10 )
  {
    AkFeedbackParams::CopyVolumes(v9, 0, &out_pMix);
    v5 = 0;
  }
  v18 = 0;
  v19 = *(_DWORD *)&v9->m_usCompanyID;
  if ( v6->m_iMaxPlayers )
  {
    do
    {
      v20 = v33;
      v21 = v18;
      if ( _bittest((const signed int *)&v20, v18) )
      {
        if ( v10 )
        {
          v22 = v18 * (*((_WORD *)v9 + 27) & 0xF);
          if ( *((_WORD *)v9 + 27) & 0xF )
          {
            do
            {
              v23 = v5 + v22;
              v24 = v5++;
              v25 = (v12 * (unsigned int)v18 + v24) << 6;
              v26 = (v23 + 1) << 6;
              *(__m128 *)((char *)out_pMix.Next.vector + v25) = *(__m128 *)((char *)&v9->m_pOutput + v26);
              *(_OWORD *)((char *)&out_pMix.Next.aVolumes[4] + v25) = *(_OWORD *)((char *)&v9->m_LPF + v26);
              *(__m128 *)((char *)out_pMix.Previous.vector + v25) = *(__m128 *)((char *)v9->m_fNextAttenuation + v26);
              *(_OWORD *)((char *)&out_pMix.Previous.aVolumes[4] + v25) = *(_OWORD *)((char *)&v9->m_usCompanyID + v26);
            }
            while ( v5 < (*((_WORD *)v9 + 27) & 0xFu) );
          }
          v5 = 0;
        }
        v27 = (unsigned __int8)v6->m_iMaxDevices;
        v28 = 0;
        if ( v6->m_iMaxDevices )
        {
          v29 = v6->m_aBusses.m_pItems;
          v30 = v18 * v27;
          while ( v29[v30].m_DeviceID != v19 )
          {
            ++v28;
            v30 = (unsigned int)(v30 + 1);
            if ( v28 >= v27 )
              goto LABEL_31;
          }
          v31 = v29[v30].m_pFeedbackMixBus;
          if ( v31 )
          {
            if ( !v10 )
              v21 = 0;
            CAkVPLMixBusNode::ConsumeBuffer(v31, (AkVPLState *)&out_pMix, &out_pMix + (unsigned int)(v21 * v12));
          }
LABEL_31:
          v5 = 0;
        }
      }
      ++v18;
    }
    while ( v18 < v6->m_iMaxPlayers );
  }
  AkFeedbackParams::StampOldVolumes(v9);
}

// File Line: 237
// RVA: 0xA8FE20
void __fastcall CAkSplitterBus::MixAudioBuffer(CAkSplitterBus *this, AkRunningVPL *io_runningVPL, unsigned int in_uPlayers)
{
  unsigned int v3; // er15
  CAkVPLSrcNode *v4; // rdi
  AkRunningVPL *v5; // rsi
  CAkSplitterBus *v6; // r13
  CAkPBI *v7; // rdi
  AkFeedbackParams *v8; // r14
  float v9; // er9
  int v10; // ecx
  unsigned __int64 v11; // rcx
  signed __int64 v12; // rax
  signed __int64 v13; // rax
  void *v14; // rsp
  char v15; // cl
  void *v16; // rsp
  AkAudioMix *v17; // r11
  bool v18; // r10
  AkFeedbackVPLData *v19; // rax
  unsigned __int64 v20; // r8
  unsigned __int16 v21; // cx
  float v22; // edx
  unsigned __int16 v23; // ax
  float v24; // ecx
  unsigned __int16 v25; // ax
  unsigned __int8 v26; // al
  int v27; // er12
  unsigned int v28; // edx
  int v29; // er8
  __int64 v30; // r9
  __int64 v31; // rcx
  __int64 v32; // rax
  __int64 v33; // rax
  signed __int64 v34; // rcx
  int v35; // er15
  CAkSplitterBus::PlayerSlot *v36; // rdi
  CAkBusFX *v37; // rax
  CAkBusFX *v38; // r14
  CAkVPLMixBusNode *v39; // rcx
  unsigned int v40; // er8
  CAkVPLMixBusNode *v41; // r14
  int v42; // er13
  int v43; // ecx
  AkAudioMix out_pMix; // [rsp+30h] [rbp+0h]
  __int64 v45; // [rsp+70h] [rbp+40h]
  CAkSplitterBus *v46; // [rsp+E0h] [rbp+B0h]
  unsigned __int8 v47; // [rsp+E8h] [rbp+B8h]
  unsigned int v48; // [rsp+F0h] [rbp+C0h]
  bool v49; // [rsp+F8h] [rbp+C8h]

  v48 = in_uPlayers;
  v46 = this;
  v3 = in_uPlayers;
  v4 = io_runningVPL->pCbx->m_pSources[0];
  v5 = io_runningVPL;
  v6 = this;
  if ( v4 )
    v7 = v4->m_pCtx;
  else
    v7 = 0i64;
  if ( !(*((_BYTE *)v7 + 374) & 0x40) )
    CAkPBI::ValidateFeedbackParameters(v7);
  v8 = v7->m_pFeedbackInfo;
  v9 = 0.0;
  out_pMix.Next.volumes.fFrontLeft = 0.0;
  v10 = v8->m_uChannelMask;
  *(_QWORD *)&out_pMix.Next.aVolumes[4] = v8;
  if ( v10 )
  {
    do
    {
      ++LODWORD(v9);
      v10 &= v10 - 1;
    }
    while ( v10 );
    out_pMix.Next.volumes.fFrontLeft = v9;
  }
  v11 = (unsigned __int64)(LODWORD(v9) * (unsigned int)(unsigned __int8)v6->m_iMaxPlayers) << 6;
  v12 = v11 + 15;
  if ( v11 + 15 <= v11 )
    v12 = 1152921504606846960i64;
  v13 = v12 & 0xFFFFFFFFFFFFFFF0ui64;
  v14 = alloca(v13);
  v15 = *((_BYTE *)v7 + 371);
  v16 = alloca(v13);
  v17 = &out_pMix;
  *(_QWORD *)&out_pMix.Next.aVolumes[2] = &out_pMix;
  v18 = (v15 & 0xC) == 4 && (v15 & 3) == 1;
  v19 = v5->pFeedbackData;
  out_pMix.Previous.vector[0].m128_u64[0] = 0i64;
  LOWORD(out_pMix.Previous.aVolumes[6]) = 0;
  v45 = 0i64;
  v20 = (unsigned __int64)v19->LPFBuffer.pData;
  v49 = v18;
  if ( v19->LPFBuffer.pData )
  {
    v21 = v19->LPFBuffer.uMaxFrames;
    LODWORD(v22) = v8->m_uChannelMask;
    v23 = v19->LPFBuffer.uValidFrames;
    LOWORD(out_pMix.Previous.aVolumes[4]) = v21;
    out_pMix.Previous.volumes.fCenter = v22;
    out_pMix.Previous.vector[0].m128_u64[0] = v20;
  }
  else
  {
    LODWORD(v24) = v8->m_uChannelMask;
    out_pMix.Previous.vector[0].m128_u64[0] = (unsigned __int64)v5->state.pData;
    v25 = v5->state.uMaxFrames;
    out_pMix.Previous.volumes.fCenter = v24;
    LOWORD(out_pMix.Previous.aVolumes[4]) = v25;
    v23 = v5->state.uValidFrames;
  }
  HIWORD(out_pMix.Previous.aVolumes[4]) = v23;
  if ( !v18 )
  {
    AkFeedbackParams::CopyVolumes(v8, 0, &out_pMix);
    v9 = out_pMix.Next.volumes.fFrontLeft;
    v18 = v49;
    v17 = *(AkAudioMix **)&out_pMix.Next.aVolumes[2];
  }
  v26 = 0;
  v27 = 0;
  v47 = 0;
  if ( v6->m_iMaxPlayers )
  {
    while ( !_bittest((const signed int *)&v3, v26) )
    {
      v27 += (unsigned __int8)v6->m_iMaxDevices;
      v26 = v47;
LABEL_46:
      v9 = out_pMix.Next.volumes.fFrontLeft;
      v18 = v49;
      v17 = *(AkAudioMix **)&out_pMix.Next.aVolumes[2];
      v47 = ++v26;
      if ( v26 >= v6->m_iMaxPlayers )
        goto LABEL_47;
    }
    if ( v18 )
    {
      v28 = 0;
      v29 = v26 * (*((_WORD *)v8 + 27) & 0xF);
      if ( *((_WORD *)v8 + 27) & 0xF )
      {
        v30 = (unsigned int)v26 * LODWORD(v9);
        do
        {
          v31 = v28 + v29;
          v32 = v28++;
          v33 = (v30 + v32) << 6;
          v34 = (v31 + 1) << 6;
          *(__m128 *)((char *)v17->Next.vector + v33) = *(__m128 *)((char *)&v8->m_pOutput + v34);
          *(_OWORD *)((char *)&v17->Next.aVolumes[4] + v33) = *(_OWORD *)((char *)&v8->m_LPF + v34);
          *(__m128 *)((char *)v17->Previous.vector + v33) = *(__m128 *)((char *)v8->m_fNextAttenuation + v34);
          *(_OWORD *)((char *)&v17->Previous.aVolumes[4] + v33) = *(_OWORD *)((char *)&v8->m_usCompanyID + v34);
        }
        while ( v28 < (*((_WORD *)v8 + 27) & 0xFu) );
      }
      v26 = v47;
    }
    v35 = 0;
    if ( v6->m_iMaxDevices <= 0u )
    {
LABEL_45:
      v3 = v48;
      goto LABEL_46;
    }
    while ( 1 )
    {
      v36 = v6->m_aBusses.m_pItems;
      if ( v6->m_aBusses.m_pItems[v27].m_pFeedbackMixBus )
      {
        if ( !v36[v27].m_pAudioMixBus )
        {
          v37 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x550ui64);
          v38 = v37;
          v36[v27].m_pAudioMixBus = (CAkVPLMixBusNode *)v37;
          if ( v37 )
          {
            CAkBusFX::CAkBusFX(v37);
            v38[1].m_PanningVolumes[0].Next.vector[0].m128_u64[0] = 0i64;
          }
          v39 = v36[v27].m_pAudioMixBus;
          if ( !v39 )
            goto LABEL_43;
          v40 = v36[v27].m_MixingFormat;
          if ( (unsigned int)CAkVPLMixBusNode::Init(v39, v40, v40, 0x400u, 0i64) != 1 )
          {
            v41 = v36[v27].m_pAudioMixBus;
            v42 = g_LEngineDefaultPoolId;
            if ( v41 )
            {
              CAkVPLMixBusNode::~CAkVPLMixBusNode(v36[v27].m_pAudioMixBus);
              AK::MemoryMgr::Free(v42, v41);
            }
            v6 = v46;
            v36[v27].m_pAudioMixBus = 0i64;
            goto LABEL_43;
          }
          CAkVPLMixBusNode::Connect(v36[v27].m_pAudioMixBus);
          v18 = v49;
        }
        v43 = v47;
        if ( !v18 )
          v43 = 0;
        CAkVPLMixBusNode::ConsumeBuffer(
          v36[v27].m_pAudioMixBus,
          (AkVPLState *)&out_pMix.Previous,
          (AkAudioMix *)(*(_QWORD *)&out_pMix.Next.aVolumes[2]
                       + ((unsigned __int64)(unsigned int)(v43 * LODWORD(out_pMix.Next.volumes.fFrontLeft)) << 6)));
      }
      ++v27;
LABEL_43:
      v18 = v49;
      if ( ++v35 >= (unsigned int)(unsigned __int8)v6->m_iMaxDevices )
      {
        v8 = *(AkFeedbackParams **)&out_pMix.Next.aVolumes[4];
        v26 = v47;
        goto LABEL_45;
      }
    }
  }
LABEL_47:
  AkFeedbackParams::StampOldVolumes(v8);
}

// File Line: 334
// RVA: 0xA8FCD0
void __fastcall CAkSplitterBus::GetBuffer(CAkSplitterBus *this, char in_iPlayerID, unsigned int in_iDeviceID, AkAudioBufferBus **out_pAudioBuffer, AkAudioBufferBus **out_pFeedbackBuffer)
{
  unsigned int v5; // er10
  unsigned int v6; // er11
  unsigned int *v7; // rax
  CAkSplitterBus::PlayerSlot *v8; // rbx
  CAkVPLMixBusNode *v9; // rcx
  CAkVPLMixBusNode *v10; // rcx

  v5 = 0;
  *out_pAudioBuffer = 0i64;
  *out_pFeedbackBuffer = 0i64;
  if ( (unsigned __int8)in_iPlayerID < this->m_iMaxPlayers )
  {
    v6 = (unsigned __int8)this->m_iMaxDevices;
    if ( this->m_iMaxDevices )
    {
      v7 = &this->m_aBusses.m_pItems->m_DeviceID;
      do
      {
        if ( *v7 == in_iDeviceID )
          break;
        ++v5;
        v7 += 6;
      }
      while ( v5 < v6 );
    }
    if ( v5 != v6 )
    {
      v8 = &this->m_aBusses.m_pItems[v5 + v6 * (unsigned __int8)in_iPlayerID];
      v9 = v8->m_pAudioMixBus;
      if ( v9 )
        CAkVPLMixBusNode::GetResultingBuffer(v9, out_pAudioBuffer);
      v10 = v8->m_pFeedbackMixBus;
      if ( v10 )
        CAkVPLMixBusNode::GetResultingBuffer(v10, out_pFeedbackBuffer);
    }
  }
}

// File Line: 358
// RVA: 0xA903C0
void __fastcall CAkSplitterBus::ReleaseBuffers(CAkSplitterBus *this)
{
  __int64 v1; // rbx
  CAkSplitterBus *v2; // rdi
  CAkVPLMixBusNode *v3; // rcx
  signed __int64 v4; // rsi
  CAkVPLMixBusNode *v5; // rcx

  v1 = 0i64;
  v2 = this;
  if ( this->m_aBusses.m_uLength )
  {
    do
    {
      v3 = v2->m_aBusses.m_pItems[v1].m_pAudioMixBus;
      v4 = (signed __int64)&v2->m_aBusses.m_pItems[v1];
      if ( v3 )
        CAkVPLMixBusNode::ReleaseBuffer(v3);
      v5 = *(CAkVPLMixBusNode **)(v4 + 8);
      if ( v5 )
        CAkVPLMixBusNode::ReleaseBuffer(v5);
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_aBusses.m_uLength );
  }
}

