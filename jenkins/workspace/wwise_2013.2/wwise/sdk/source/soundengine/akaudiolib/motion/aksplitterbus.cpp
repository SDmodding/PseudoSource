// File Line: 30
// RVA: 0xA905B0
void __fastcall CAkSplitterBus::PlayerSlot::Term(CAkSplitterBus::PlayerSlot *this)
{
  CAkVPLMixBusNode *m_pFeedbackMixBus; // rcx
  CAkVPLMixBusNode *v3; // rdi
  int v4; // esi
  CAkVPLMixBusNode *m_pAudioMixBus; // rdi
  int v6; // esi

  m_pFeedbackMixBus = this->m_pFeedbackMixBus;
  if ( m_pFeedbackMixBus )
  {
    CAkVPLMixBusNode::Disconnect(m_pFeedbackMixBus);
    v3 = this->m_pFeedbackMixBus;
    v4 = g_LEngineDefaultPoolId;
    if ( v3 )
    {
      CAkVPLMixBusNode::~CAkVPLMixBusNode(v3);
      AK::MemoryMgr::Free(v4, v3);
    }
    this->m_pFeedbackMixBus = 0i64;
  }
  if ( this->m_pAudioMixBus )
  {
    CAkVPLMixBusNode::Disconnect(this->m_pAudioMixBus);
    m_pAudioMixBus = this->m_pAudioMixBus;
    v6 = g_LEngineDefaultPoolId;
    if ( this->m_pAudioMixBus )
    {
      CAkVPLMixBusNode::~CAkVPLMixBusNode(m_pAudioMixBus);
      AK::MemoryMgr::Free(v6, m_pAudioMixBus);
    }
    this->m_pAudioMixBus = 0i64;
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
// attributes: thunk
void __fastcall CAkSplitterBus::~CAkSplitterBus(CAkSplitterBus *this)
{
  CAkSplitterBus::Term(this);
}

// File Line: 62
// RVA: 0xA90540
__int64 __fastcall CAkSplitterBus::Term(CAkSplitterBus *this)
{
  __int64 i; // rdi

  for ( i = 0i64; (unsigned int)i < this->m_aBusses.m_uLength; i = (unsigned int)(i + 1) )
    CAkSplitterBus::PlayerSlot::Term(&this->m_aBusses.m_pItems[i]);
  if ( this->m_aBusses.m_pItems )
  {
    this->m_aBusses.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_aBusses.m_pItems);
    this->m_aBusses.m_pItems = 0i64;
    this->m_aBusses.m_ulReserved = 0;
  }
  return 1i64;
}

// File Line: 72
// RVA: 0xA8FA10
__int64 __fastcall CAkSplitterBus::AddBus(
        CAkSplitterBus *this,
        unsigned __int8 in_iPlayerID,
        unsigned int in_iDeviceID,
        unsigned int in_MixingFormat)
{
  __int64 m_iMaxDevices; // rbp
  unsigned __int8 m_iMaxPlayers; // r8
  unsigned int v7; // r15d
  unsigned __int8 v8; // al
  bool v9; // r13
  unsigned int v11; // esi
  int v12; // r15d
  int v13; // ecx
  int v14; // r14d
  size_t v15; // r13
  __int64 v16; // r15
  int v17; // ebp
  int v18; // edx
  unsigned int v19; // r10d
  int i; // r11d
  __int64 v21; // r8
  __int64 v22; // rax
  bool v23; // zf
  CAkSplitterBus::PlayerSlot *v24; // rsi
  CAkBusFX *v25; // rax
  CAkVPLMixBusNode *v26; // rdi
  unsigned int v27; // ebp
  int v28; // ebx
  bool v30; // [rsp+70h] [rbp+8h]

  m_iMaxDevices = (unsigned __int8)this->m_iMaxDevices;
  m_iMaxPlayers = this->m_iMaxPlayers;
  v7 = in_MixingFormat;
  v8 = in_iPlayerID;
  v9 = in_iPlayerID >= m_iMaxPlayers;
  v11 = 0;
  v30 = in_iPlayerID >= m_iMaxPlayers;
  if ( this->m_iMaxDevices )
  {
    do
    {
      if ( this->m_aBusses.m_pItems[v11].m_DeviceID == in_iDeviceID )
        break;
      ++v11;
    }
    while ( v11 < (unsigned int)m_iMaxDevices );
    v8 = in_iPlayerID;
  }
  if ( in_iPlayerID >= m_iMaxPlayers || v11 == (_DWORD)m_iMaxDevices )
  {
    v12 = m_iMaxPlayers;
    v13 = v8 + 1;
    if ( m_iMaxPlayers > v13 )
      LOBYTE(v13) = m_iMaxPlayers;
    this->m_iMaxPlayers = v13;
    if ( v11 == (_DWORD)m_iMaxDevices )
      this->m_iMaxDevices = m_iMaxDevices + 1;
    if ( !AkArray<CAkSplitterBus::PlayerSlot,CAkSplitterBus::PlayerSlot &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Resize(
            &this->m_aBusses,
            (unsigned __int8)this->m_iMaxDevices * (unsigned __int8)v13) )
      return 2i64;
    if ( v11 == (_DWORD)m_iMaxDevices )
    {
      v14 = v12 - 1;
      if ( v12 - 1 >= 0 )
      {
        v15 = 24 * m_iMaxDevices;
        v16 = (unsigned int)(m_iMaxDevices * v14);
        v17 = -(int)m_iMaxDevices;
        do
        {
          memmove(
            &this->m_aBusses.m_pItems[v14 * (unsigned int)(unsigned __int8)this->m_iMaxDevices],
            &this->m_aBusses.m_pItems[v16],
            v15);
          v16 = (unsigned int)(v17 + v16);
          --v14;
        }
        while ( v14 >= 0 );
        v9 = v30;
      }
      v18 = 0;
      if ( this->m_iMaxPlayers )
      {
        do
          this->m_aBusses.m_pItems[++v18 * (unsigned int)(unsigned __int8)this->m_iMaxDevices - 1].m_DeviceID = in_iDeviceID;
        while ( v18 < (unsigned __int8)this->m_iMaxPlayers );
      }
    }
    if ( v9 )
    {
      v19 = 0;
      for ( i = (unsigned __int8)this->m_iMaxDevices * ((unsigned __int8)this->m_iMaxPlayers - 1);
            v19 < (unsigned __int8)this->m_iMaxDevices;
            this->m_aBusses.m_pItems[v22].m_DeviceID = this->m_aBusses.m_pItems[v21].m_DeviceID )
      {
        v21 = v19;
        v22 = v19 + i;
        ++v19;
      }
    }
    v7 = in_MixingFormat;
  }
  v23 = this->m_aBusses.m_pItems[v11 + (unsigned __int8)this->m_iMaxDevices * in_iPlayerID].m_pFeedbackMixBus == 0i64;
  v24 = &this->m_aBusses.m_pItems[v11 + (unsigned __int8)this->m_iMaxDevices * in_iPlayerID];
  if ( !v23 )
    return 1i64;
  v25 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x550ui64);
  v26 = (CAkVPLMixBusNode *)v25;
  if ( v25 )
  {
    CAkBusFX::CAkBusFX(v25);
    v26->m_BusContext.m_pBus = 0i64;
    v24->m_MixingFormat = v7;
    v27 = CAkVPLMixBusNode::Init(v26, v7, v7, 8u, 0i64);
    if ( v27 != 1 )
    {
      v28 = g_LEngineDefaultPoolId;
      CAkVPLMixBusNode::~CAkVPLMixBusNode(v26);
      AK::MemoryMgr::Free(v28, v26);
      return v27;
    }
    CAkVPLMixBusNode::Connect(v26);
    v24->m_pFeedbackMixBus = v26;
    return 1i64;
  }
  return 2i64;
}

// File Line: 154
// RVA: 0xA90420
__int64 __fastcall CAkSplitterBus::RemoveBus(
        CAkSplitterBus *this,
        unsigned __int8 in_iPlayerID,
        unsigned int in_iDeviceID)
{
  unsigned int m_iMaxDevices; // edx
  unsigned int v7; // ecx
  unsigned int *p_m_DeviceID; // rax

  if ( in_iPlayerID >= (unsigned int)this->m_iMaxPlayers )
    return 2i64;
  m_iMaxDevices = (unsigned __int8)this->m_iMaxDevices;
  v7 = 0;
  if ( this->m_iMaxDevices )
  {
    p_m_DeviceID = &this->m_aBusses.m_pItems->m_DeviceID;
    do
    {
      if ( *p_m_DeviceID == in_iDeviceID )
        break;
      ++v7;
      p_m_DeviceID += 6;
    }
    while ( v7 < m_iMaxDevices );
  }
  if ( v7 == m_iMaxDevices )
    return 2i64;
  CAkSplitterBus::PlayerSlot::Term(&this->m_aBusses.m_pItems[v7 + m_iMaxDevices * in_iPlayerID]);
  return 1i64;
}

// File Line: 177
// RVA: 0xA90180
void __fastcall CAkSplitterBus::MixFeedbackBuffer(
        CAkSplitterBus *this,
        AkRunningVPL *io_runningVPL,
        unsigned int in_uPlayers)
{
  CAkVPLSrcNode *v3; // rbx
  unsigned int v5; // edx
  CAkPBI *m_pCtx; // rbx
  char v8; // cl
  AkFeedbackParams *m_pFeedbackInfo; // rdi
  bool v10; // r13
  __int128 v11; // xmm1
  int v12; // r14d
  __int128 v13; // xmm1
  int m_uChannelMask; // ecx
  unsigned __int64 v15; // rcx
  __int64 v16; // rax
  void *v17; // rsp
  unsigned __int8 v18; // bl
  int i; // esi
  unsigned int v20; // eax
  int v21; // r10d
  int v22; // r8d
  __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rcx
  unsigned int m_iMaxDevices; // r9d
  unsigned int v28; // r8d
  CAkSplitterBus::PlayerSlot *m_pItems; // r11
  __int64 v30; // rax
  CAkVPLMixBusNode *m_pFeedbackMixBus; // rcx
  AkAudioMix out_pMix; // [rsp+20h] [rbp+0h] BYREF

  v3 = io_runningVPL->pCbx->m_pSources[0];
  v5 = 0;
  if ( v3 )
    m_pCtx = v3->m_pCtx;
  else
    m_pCtx = 0i64;
  if ( (*((_BYTE *)m_pCtx + 374) & 0x40) == 0 )
  {
    CAkPBI::ValidateFeedbackParameters(m_pCtx);
    v5 = 0;
  }
  v8 = *((_BYTE *)m_pCtx + 371);
  m_pFeedbackInfo = m_pCtx->m_pFeedbackInfo;
  v10 = (v8 & 0xC) == 4 && (v8 & 3) == 1;
  v11 = *(_OWORD *)&io_runningVPL->state.uMaxFrames;
  v12 = 0;
  out_pMix.Next.vector[0] = *(__m128 *)&io_runningVPL->state.pData;
  *(_OWORD *)&out_pMix.Next.aVolumes[4] = v11;
  v13 = *(_OWORD *)&io_runningVPL->state.posInfo.uFileEnd;
  out_pMix.Previous.vector[0] = *(__m128 *)&io_runningVPL->state.pMarkers;
  *(_OWORD *)&out_pMix.Previous.aVolumes[4] = v13;
  m_uChannelMask = m_pFeedbackInfo->m_uChannelMask;
  if ( m_pFeedbackInfo->m_uChannelMask )
  {
    do
    {
      ++v12;
      m_uChannelMask &= m_uChannelMask - 1;
    }
    while ( m_uChannelMask );
  }
  v15 = (unsigned __int64)(v12 * (unsigned int)(unsigned __int8)this->m_iMaxPlayers) << 6;
  v16 = v15 + 15;
  if ( v15 + 15 <= v15 )
    v16 = 0xFFFFFFFFFFFFFF0i64;
  v17 = alloca(v16 & 0xFFFFFFFFFFFFFFF0ui64);
  if ( !v10 )
  {
    AkFeedbackParams::CopyVolumes(m_pFeedbackInfo, 0, &out_pMix);
    v5 = 0;
  }
  v18 = 0;
  for ( i = *(_DWORD *)&m_pFeedbackInfo->m_usCompanyID; v18 < (unsigned int)this->m_iMaxPlayers; ++v18 )
  {
    v20 = in_uPlayers;
    v21 = v18;
    if ( _bittest((const int *)&v20, v18) )
    {
      if ( v10 )
      {
        v22 = v18 * (*((_WORD *)m_pFeedbackInfo + 27) & 0xF);
        if ( (*((_WORD *)m_pFeedbackInfo + 27) & 0xF) != 0 )
        {
          do
          {
            v23 = v5 + v22;
            v24 = v5++;
            v25 = (v12 * (unsigned int)v18 + v24) << 6;
            v26 = (v23 + 1) << 6;
            *(__m128 *)((char *)out_pMix.Next.vector + v25) = *(__m128 *)((char *)&m_pFeedbackInfo->m_pOutput + v26);
            *(_OWORD *)((char *)&out_pMix.Next.aVolumes[4] + v25) = *(_OWORD *)((char *)&m_pFeedbackInfo->m_LPF + v26);
            *(__m128 *)((char *)out_pMix.Previous.vector + v25) = *(__m128 *)((char *)m_pFeedbackInfo->m_fNextAttenuation
                                                                            + v26);
            *(_OWORD *)((char *)&out_pMix.Previous.aVolumes[4] + v25) = *(_OWORD *)((char *)&m_pFeedbackInfo->m_fNextAttenuation[4]
                                                                                  + v26);
          }
          while ( v5 < (*((_WORD *)m_pFeedbackInfo + 27) & 0xFu) );
        }
        v5 = 0;
      }
      m_iMaxDevices = (unsigned __int8)this->m_iMaxDevices;
      v28 = 0;
      if ( this->m_iMaxDevices )
      {
        m_pItems = this->m_aBusses.m_pItems;
        v30 = v18 * m_iMaxDevices;
        while ( m_pItems[v30].m_DeviceID != i )
        {
          ++v28;
          v30 = (unsigned int)(v30 + 1);
          if ( v28 >= m_iMaxDevices )
            goto LABEL_31;
        }
        m_pFeedbackMixBus = m_pItems[v30].m_pFeedbackMixBus;
        if ( m_pFeedbackMixBus )
        {
          if ( !v10 )
            v21 = 0;
          CAkVPLMixBusNode::ConsumeBuffer(
            m_pFeedbackMixBus,
            (AkVPLState *)&out_pMix,
            &out_pMix + (unsigned int)(v21 * v12));
        }
LABEL_31:
        v5 = 0;
      }
    }
  }
  AkFeedbackParams::StampOldVolumes(m_pFeedbackInfo);
}

// File Line: 237
// RVA: 0xA8FE20
void __fastcall CAkSplitterBus::MixAudioBuffer(
        CAkSplitterBus *this,
        AkRunningVPL *io_runningVPL,
        unsigned int in_uPlayers)
{
  unsigned int v3; // r15d
  CAkVPLSrcNode *v4; // rdi
  CAkSplitterBus *v6; // r13
  CAkPBI *m_pCtx; // rdi
  unsigned __int64 m_pFeedbackInfo; // r14
  int v9; // r9d
  int v10; // ecx
  unsigned __int64 v11; // rcx
  __int64 v12; // rax
  signed __int64 v13; // rax
  void *v14; // rsp
  char v15; // cl
  void *v16; // rsp
  AkAudioMix *p_out_pMix; // r11
  bool v18; // r10
  AkFeedbackVPLData *pFeedbackData; // rax
  unsigned __int64 pData; // r8
  __int16 uMaxFrames; // cx
  int v22; // edx
  unsigned __int16 uValidFrames; // ax
  int v24; // ecx
  unsigned __int16 v25; // ax
  unsigned __int8 v26; // al
  int v27; // r12d
  unsigned int v28; // edx
  int v29; // r8d
  __int64 v30; // r9
  __int64 v31; // rcx
  __int64 v32; // rax
  __int64 v33; // rax
  __int64 v34; // rcx
  int v35; // r15d
  CAkSplitterBus::PlayerSlot *m_pItems; // rdi
  CAkBusFX *v37; // rax
  CAkBusFX *v38; // r14
  CAkVPLMixBusNode *m_pAudioMixBus; // rcx
  unsigned int m_MixingFormat; // edx
  CAkVPLMixBusNode *v41; // r14
  int v42; // r13d
  int v43; // ecx
  AkAudioMix out_pMix; // [rsp+30h] [rbp+0h] BYREF
  __int64 v45; // [rsp+70h] [rbp+40h]
  unsigned __int8 v47; // [rsp+E8h] [rbp+B8h]
  bool v49; // [rsp+F8h] [rbp+C8h]

  v3 = in_uPlayers;
  v4 = io_runningVPL->pCbx->m_pSources[0];
  v6 = this;
  if ( v4 )
    m_pCtx = v4->m_pCtx;
  else
    m_pCtx = 0i64;
  if ( (*((_BYTE *)m_pCtx + 374) & 0x40) == 0 )
    CAkPBI::ValidateFeedbackParameters(m_pCtx);
  m_pFeedbackInfo = (unsigned __int64)m_pCtx->m_pFeedbackInfo;
  v9 = 0;
  out_pMix.Next.vector[0].m128_i32[0] = 0;
  v10 = *(unsigned __int16 *)(m_pFeedbackInfo + 52);
  out_pMix.Next.vector[1].m128_u64[0] = m_pFeedbackInfo;
  if ( v10 )
  {
    do
    {
      ++v9;
      v10 &= v10 - 1;
    }
    while ( v10 );
    out_pMix.Next.vector[0].m128_i32[0] = v9;
  }
  v11 = (unsigned __int64)(v9 * (unsigned int)(unsigned __int8)v6->m_iMaxPlayers) << 6;
  v12 = v11 + 15;
  if ( v11 + 15 <= v11 )
    v12 = 0xFFFFFFFFFFFFFF0i64;
  v13 = v12 & 0xFFFFFFFFFFFFFFF0ui64;
  v14 = alloca(v13);
  v15 = *((_BYTE *)m_pCtx + 371);
  v16 = alloca(v13);
  p_out_pMix = &out_pMix;
  out_pMix.Next.vector[0].m128_u64[1] = (unsigned __int64)&out_pMix;
  v18 = (v15 & 0xC) == 4 && (v15 & 3) == 1;
  pFeedbackData = io_runningVPL->pFeedbackData;
  out_pMix.Previous.vector[0].m128_u64[0] = 0i64;
  out_pMix.Previous.vector[1].m128_i16[4] = 0;
  v45 = 0i64;
  pData = (unsigned __int64)pFeedbackData->LPFBuffer.pData;
  v49 = v18;
  if ( pFeedbackData->LPFBuffer.pData )
  {
    uMaxFrames = pFeedbackData->LPFBuffer.uMaxFrames;
    v22 = *(unsigned __int16 *)(m_pFeedbackInfo + 52);
    uValidFrames = pFeedbackData->LPFBuffer.uValidFrames;
    out_pMix.Previous.vector[1].m128_i16[0] = uMaxFrames;
    out_pMix.Previous.vector[0].m128_i32[2] = v22;
    out_pMix.Previous.vector[0].m128_u64[0] = pData;
  }
  else
  {
    v24 = *(unsigned __int16 *)(m_pFeedbackInfo + 52);
    out_pMix.Previous.vector[0].m128_u64[0] = (unsigned __int64)io_runningVPL->state.pData;
    v25 = io_runningVPL->state.uMaxFrames;
    out_pMix.Previous.vector[0].m128_i32[2] = v24;
    out_pMix.Previous.vector[1].m128_i16[0] = v25;
    uValidFrames = io_runningVPL->state.uValidFrames;
  }
  out_pMix.Previous.vector[1].m128_i16[1] = uValidFrames;
  if ( !v18 )
  {
    AkFeedbackParams::CopyVolumes((AkFeedbackParams *)m_pFeedbackInfo, 0, &out_pMix);
    v9 = out_pMix.Next.vector[0].m128_i32[0];
    v18 = v49;
    p_out_pMix = (AkAudioMix *)out_pMix.Next.vector[0].m128_u64[1];
  }
  v26 = 0;
  v27 = 0;
  v47 = 0;
  if ( v6->m_iMaxPlayers )
  {
    while ( !_bittest((const int *)&v3, v26) )
    {
      v27 += (unsigned __int8)v6->m_iMaxDevices;
      v26 = v47;
LABEL_46:
      v9 = out_pMix.Next.vector[0].m128_i32[0];
      v18 = v49;
      p_out_pMix = (AkAudioMix *)out_pMix.Next.vector[0].m128_u64[1];
      v47 = ++v26;
      if ( v26 >= (unsigned int)v6->m_iMaxPlayers )
        goto LABEL_47;
    }
    if ( v18 )
    {
      v28 = 0;
      v29 = v26 * (*(_WORD *)(m_pFeedbackInfo + 54) & 0xF);
      if ( (*(_WORD *)(m_pFeedbackInfo + 54) & 0xF) != 0 )
      {
        v30 = (unsigned int)v26 * v9;
        do
        {
          v31 = v28 + v29;
          v32 = v28++;
          v33 = (v30 + v32) << 6;
          v34 = (v31 + 1) << 6;
          *(__m128 *)((char *)p_out_pMix->Next.vector + v33) = *(__m128 *)(v34 + m_pFeedbackInfo);
          *(_OWORD *)((char *)&p_out_pMix->Next.aVolumes[4] + v33) = *(_OWORD *)(v34 + m_pFeedbackInfo + 16);
          *(__m128 *)((char *)p_out_pMix->Previous.vector + v33) = *(__m128 *)(v34 + m_pFeedbackInfo + 32);
          *(_OWORD *)((char *)&p_out_pMix->Previous.aVolumes[4] + v33) = *(_OWORD *)(v34 + m_pFeedbackInfo + 48);
        }
        while ( v28 < (*(_WORD *)(m_pFeedbackInfo + 54) & 0xFu) );
      }
      v26 = v47;
    }
    v35 = 0;
    if ( !v6->m_iMaxDevices )
    {
LABEL_45:
      v3 = in_uPlayers;
      goto LABEL_46;
    }
    while ( 1 )
    {
      m_pItems = v6->m_aBusses.m_pItems;
      if ( v6->m_aBusses.m_pItems[v27].m_pFeedbackMixBus )
      {
        if ( !m_pItems[v27].m_pAudioMixBus )
        {
          v37 = (CAkBusFX *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x550ui64);
          v38 = v37;
          m_pItems[v27].m_pAudioMixBus = (CAkVPLMixBusNode *)v37;
          if ( v37 )
          {
            CAkBusFX::CAkBusFX(v37);
            v38[1].m_PanningVolumes[0].Next.vector[0].m128_u64[0] = 0i64;
          }
          m_pAudioMixBus = m_pItems[v27].m_pAudioMixBus;
          if ( !m_pAudioMixBus )
            goto LABEL_43;
          m_MixingFormat = m_pItems[v27].m_MixingFormat;
          if ( (unsigned int)CAkVPLMixBusNode::Init(m_pAudioMixBus, m_MixingFormat, m_MixingFormat, 0x400u, 0i64) != 1 )
          {
            v41 = m_pItems[v27].m_pAudioMixBus;
            v42 = g_LEngineDefaultPoolId;
            if ( v41 )
            {
              CAkVPLMixBusNode::~CAkVPLMixBusNode(m_pItems[v27].m_pAudioMixBus);
              AK::MemoryMgr::Free(v42, v41);
            }
            v6 = this;
            m_pItems[v27].m_pAudioMixBus = 0i64;
            goto LABEL_43;
          }
          CAkVPLMixBusNode::Connect(m_pItems[v27].m_pAudioMixBus);
          v18 = v49;
        }
        v43 = v47;
        if ( !v18 )
          v43 = 0;
        CAkVPLMixBusNode::ConsumeBuffer(
          m_pItems[v27].m_pAudioMixBus,
          (AkVPLState *)&out_pMix.Previous,
          (AkAudioMix *)(out_pMix.Next.vector[0].m128_u64[1]
                       + ((unsigned __int64)(unsigned int)(v43 * out_pMix.Next.vector[0].m128_i32[0]) << 6)));
      }
      ++v27;
LABEL_43:
      v18 = v49;
      if ( ++v35 >= (unsigned int)(unsigned __int8)v6->m_iMaxDevices )
      {
        m_pFeedbackInfo = out_pMix.Next.vector[1].m128_u64[0];
        v26 = v47;
        goto LABEL_45;
      }
    }
  }
LABEL_47:
  AkFeedbackParams::StampOldVolumes((AkFeedbackParams *)m_pFeedbackInfo);
}

// File Line: 334
// RVA: 0xA8FCD0
void __fastcall CAkSplitterBus::GetBuffer(
        CAkSplitterBus *this,
        unsigned __int8 in_iPlayerID,
        unsigned int in_iDeviceID,
        AkAudioBufferBus **out_pAudioBuffer,
        AkAudioBufferBus **out_pFeedbackBuffer)
{
  unsigned int v5; // r10d
  unsigned int m_iMaxDevices; // r11d
  unsigned int *p_m_DeviceID; // rax
  CAkSplitterBus::PlayerSlot *v8; // rbx
  CAkVPLMixBusNode *m_pFeedbackMixBus; // rcx

  v5 = 0;
  *out_pAudioBuffer = 0i64;
  *out_pFeedbackBuffer = 0i64;
  if ( in_iPlayerID < (unsigned int)this->m_iMaxPlayers )
  {
    m_iMaxDevices = (unsigned __int8)this->m_iMaxDevices;
    if ( this->m_iMaxDevices )
    {
      p_m_DeviceID = &this->m_aBusses.m_pItems->m_DeviceID;
      do
      {
        if ( *p_m_DeviceID == in_iDeviceID )
          break;
        ++v5;
        p_m_DeviceID += 6;
      }
      while ( v5 < m_iMaxDevices );
    }
    if ( v5 != m_iMaxDevices )
    {
      v8 = &this->m_aBusses.m_pItems[v5 + m_iMaxDevices * in_iPlayerID];
      if ( v8->m_pAudioMixBus )
        CAkVPLMixBusNode::GetResultingBuffer(v8->m_pAudioMixBus, out_pAudioBuffer);
      m_pFeedbackMixBus = v8->m_pFeedbackMixBus;
      if ( m_pFeedbackMixBus )
        CAkVPLMixBusNode::GetResultingBuffer(m_pFeedbackMixBus, out_pFeedbackBuffer);
    }
  }
}

// File Line: 358
// RVA: 0xA903C0
void __fastcall CAkSplitterBus::ReleaseBuffers(CAkSplitterBus *this)
{
  __int64 i; // rbx
  CAkVPLMixBusNode *m_pAudioMixBus; // rcx
  CAkSplitterBus::PlayerSlot *v4; // rsi
  CAkVPLMixBusNode *m_pFeedbackMixBus; // rcx

  for ( i = 0i64; (unsigned int)i < this->m_aBusses.m_uLength; i = (unsigned int)(i + 1) )
  {
    m_pAudioMixBus = this->m_aBusses.m_pItems[i].m_pAudioMixBus;
    v4 = &this->m_aBusses.m_pItems[i];
    if ( m_pAudioMixBus )
      CAkVPLMixBusNode::ReleaseBuffer(m_pAudioMixBus);
    m_pFeedbackMixBus = v4->m_pFeedbackMixBus;
    if ( m_pFeedbackMixBus )
      CAkVPLMixBusNode::ReleaseBuffer(m_pFeedbackMixBus);
  }
}

