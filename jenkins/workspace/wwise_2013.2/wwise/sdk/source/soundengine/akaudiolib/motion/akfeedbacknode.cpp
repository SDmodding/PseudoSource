// File Line: 47
// RVA: 0xA8E4B0
CAkFeedbackNode *__fastcall CAkFeedbackNode::Create(unsigned int in_ulID)
{
  CAkFeedbackNode *result; // rax
  CAkFeedbackNode *v3; // rbx
  unsigned int v4; // eax
  int v5; // ecx
  bool v6; // al

  result = (CAkFeedbackNode *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA8ui64);
  v3 = result;
  if ( result )
  {
    CAkSoundBase::CAkSoundBase(result, in_ulID);
    v3->vfptr = (CAkIndexableVtbl *)&CAkFeedbackNode::`vftable;
    v3->m_arSrcInfo.m_pItems = 0i64;
    *(_QWORD *)&v3->m_arSrcInfo.m_uLength = 0i64;
    v4 = v3->vfptr[3].Release(v3);
    v6 = 0;
    if ( v4 <= 0xC )
    {
      v5 = 5121;
      if ( _bittest(&v5, v4) )
        v6 = 1;
    }
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) &= ~2u;
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) |= 2 * v6;
    CAkParameterNodeBase::AddToIndex(v3);
    return v3;
  }
  return result;
}

// File Line: 65
// RVA: 0xA8E880
__int64 __fastcall CAkFeedbackNode::PlayInternal(CAkFeedbackNode *this, AkPBIParams *in_rPBIParams)
{
  unsigned int uFrameOffset; // eax
  CAkFeedbackDeviceMgr *v5; // rbp
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rax
  CAkSource **p_item; // rbx

  uFrameOffset = in_rPBIParams->uFrameOffset;
  in_rPBIParams->bTargetFeedback = 1;
  in_rPBIParams->uFrameOffset = (8 * uFrameOffset) >> 10;
  v5 = CAkFeedbackDeviceMgr::s_pSingleton;
  if ( CAkFeedbackDeviceMgr::s_pSingleton )
  {
    m_pItems = this->m_arSrcInfo.m_pItems;
    if ( m_pItems != &m_pItems[this->m_arSrcInfo.m_uLength] )
    {
      p_item = &m_pItems->item;
      do
      {
        if ( CAkFeedbackDeviceMgr::IsDeviceActive(
               v5,
               LOWORD((*p_item)[1].m_sSrcTypeInfo.mediaInfo.sourceID),
               HIWORD((*p_item)[1].m_sSrcTypeInfo.mediaInfo.sourceID)) )
        {
          CAkURenderer::Play(this, *p_item, in_rPBIParams);
        }
        p_item += 2;
      }
      while ( p_item - 1 != (CAkSource **)&this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
    }
  }
  return 1i64;
}

// File Line: 88
// RVA: 0xA8E550
__int64 __fastcall CAkFeedbackNode::ExecuteAction(CAkFeedbackNode *this, ActionParams *in_rAction)
{
  ActionParams *v2; // rbx
  AkActivityChunk *m_pActivityChunk; // rax

  v2 = in_rAction;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkFeedbackNode *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  m_pActivityChunk = this->m_pActivityChunk;
  if ( !m_pActivityChunk || !m_pActivityChunk->m_PlayCount )
    return 1i64;
  if ( v2->eType == ActionParamType_Stop )
    return CAkURenderer::Stop(this, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType == ActionParamType_Pause )
    return CAkURenderer::Pause(this, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType != ActionParamType_Resume )
  {
    if ( v2->eType == ActionParamType_Break )
      ((void (__fastcall *)(CAkFeedbackNode *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))this->vfptr[4].Category)(
        this,
        v2->pGameObj,
        v2->targetNodePtr,
        v2->playingID);
    return 1i64;
  }
  return CAkURenderer::Resume(this, v2->pGameObj, &v2->transParams, v2->bIsMasterResume, v2->playingID);
}

// File Line: 118
// RVA: 0xA8E630
__int64 __fastcall CAkFeedbackNode::ExecuteActionExcept(CAkFeedbackNode *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rbx
  AkActivityChunk *m_pActivityChunk; // rax

  v2 = in_rAction;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkFeedbackNode *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk && m_pActivityChunk->m_PlayCount )
  {
    switch ( v2->eType )
    {
      case ActionParamType_Stop:
        return CAkURenderer::Stop(this, v2->pGameObj, &v2->transParams, v2->playingID);
      case ActionParamType_Pause:
        return CAkURenderer::Pause(this, v2->pGameObj, &v2->transParams, v2->playingID);
      case ActionParamType_Resume:
        return CAkURenderer::Resume(this, v2->pGameObj, &v2->transParams, v2->bIsMasterResume, v2->playingID);
    }
  }
  return 1i64;
}

// File Line: 160
// RVA: 0xA8E810
__int64 __fastcall CAkFeedbackNode::IncrementPlayCount(CAkFeedbackNode *this, CounterParameters *io_params)
{
  CAkParameterNodeBase *m_pParentNode; // rbx

  if ( !((__int64 (__fastcall *)(CAkFeedbackNode *))this->vfptr[16].Release)(this) )
  {
    m_pParentNode = this->m_pParentNode;
    if ( m_pParentNode )
    {
      while ( !((__int64 (__fastcall *)(CAkParameterNodeBase *))m_pParentNode->vfptr[16].Release)(m_pParentNode) )
      {
        m_pParentNode = m_pParentNode->m_pParentNode;
        if ( !m_pParentNode )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      CAkParameterNodeBase::GetFeedbackParentBusOrDefault(this);
    }
  }
  return CAkParameterNode::IncrementPlayCount(this, io_params);
}

// File Line: 191
// RVA: 0xA8EA50
__int64 __fastcall CAkFeedbackNode::SetInitialValues(
        CAkFeedbackNode *this,
        char *in_pData,
        unsigned int in_ulDataSize,
        CAkUsageSlot *in_pUsageSlot,
        bool in_bIsPartialLoadOnly)
{
  int v5; // edi
  unsigned int v6; // r14d
  char *v7; // rdx
  unsigned int v9; // ebx
  unsigned __int16 v10; // bx
  unsigned __int16 v11; // si
  char *v12; // rdx
  float v13; // xmm6_4
  __int64 result; // rax
  AkBankSourceData out_rSource; // [rsp+20h] [rbp-58h] BYREF
  char *io_pData; // [rsp+88h] [rbp+10h] BYREF
  unsigned int io_ulDataSize; // [rsp+90h] [rbp+18h] BYREF

  io_ulDataSize = in_ulDataSize;
  v5 = 0;
  io_pData = in_pData + 4;
  v6 = *((_DWORD *)in_pData + 1);
  v7 = in_pData + 8;
  v9 = 1;
  io_pData = v7;
  if ( !v6 )
    return CAkParameterNodeBase::SetNodeBaseParams(this, &io_pData, &io_ulDataSize, in_bIsPartialLoadOnly);
  while ( v9 == 1 )
  {
    v10 = *(_WORD *)v7;
    io_pData = v7 + 2;
    v11 = *((_WORD *)v7 + 1);
    io_pData = v7 + 4;
    v12 = v7 + 8;
    v13 = *((float *)v12 - 1);
    io_pData = v12;
    result = CAkBankMgr::LoadSource(&io_pData, &io_ulDataSize, &out_rSource);
    if ( (_DWORD)result != 1 )
      return result;
    v9 = CAkFeedbackNode::AddPluginSource(this, out_rSource.m_MediaInfo.sourceID, v10, v11);
    CAkFeedbackNode::SetSourceVolumeOffset(this, out_rSource.m_MediaInfo.sourceID, v13);
    if ( ++v5 >= v6 )
    {
      if ( v9 == 1 )
        return CAkParameterNodeBase::SetNodeBaseParams(this, &io_pData, &io_ulDataSize, in_bIsPartialLoadOnly);
      return v9;
    }
    v7 = io_pData;
  }
  return v9;
}

// File Line: 238
// RVA: 0xA8E380
__int64 __fastcall CAkFeedbackNode::AddPluginSource(
        CAkFeedbackNode *this,
        unsigned int in_srcID,
        unsigned __int16 in_idDeviceCompany,
        unsigned __int16 in_idDevicePlugin)
{
  CAkKeyArray<unsigned long,CAkFeedbackNode::SrcInfo *,4> *p_m_arSrcInfo; // r14
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rax
  __int64 m_uLength; // r10
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v10; // rcx
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v11; // r10
  __int64 result; // rax
  void *p_item; // rbx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v14; // rax
  CAkSource *v15; // rax
  CAkSource *v16; // rsi

  p_m_arSrcInfo = &this->m_arSrcInfo;
  m_pItems = this->m_arSrcInfo.m_pItems;
  m_uLength = this->m_arSrcInfo.m_uLength;
  v10 = m_pItems;
  v11 = &m_pItems[m_uLength];
  if ( m_pItems != v11 )
  {
    do
    {
      if ( v10->key == in_srcID )
        break;
      ++v10;
    }
    while ( v10 != v11 );
  }
  if ( v10 != v11 && v10 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)-8i64 )
    return 1i64;
  for ( ; m_pItems != v11; ++m_pItems )
  {
    if ( m_pItems->key == in_srcID )
      break;
  }
  if ( m_pItems == v11 )
  {
    p_item = 0i64;
  }
  else
  {
    p_item = &m_pItems->item;
    if ( m_pItems != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)-8i64 )
      goto LABEL_17;
  }
  v14 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)p_m_arSrcInfo);
  if ( v14 )
  {
    LODWORD(v14->key) = in_srcID;
    p_item = &v14->item;
  }
  if ( !p_item )
    return 2i64;
LABEL_17:
  v15 = (CAkSource *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v16 = v15;
  if ( v15 )
    CAkSource::CAkSource(v15);
  else
    v16 = 0i64;
  *(_QWORD *)p_item = v16;
  if ( v16 )
  {
    CAkSource::SetSource(v16, in_srcID);
    *(_WORD *)(*(_QWORD *)p_item + 40i64) = in_idDeviceCompany;
    *(_WORD *)(*(_QWORD *)p_item + 42i64) = in_idDevicePlugin;
    *(_DWORD *)(*(_QWORD *)p_item + 44i64) = 0;
  }
  else
  {
    CAkKeyArray<unsigned long,CAkMusicSource *,4>::Unset(
      (CAkKeyArray<unsigned long,CAkMusicSource *,4> *)p_m_arSrcInfo,
      in_srcID);
  }
  result = 1i64;
  if ( !*(_QWORD *)p_item )
    return 2i64;
  return result;
}

// File Line: 269
// RVA: 0xA8EB70
void __fastcall CAkFeedbackNode::SetSourceVolumeOffset(CAkFeedbackNode *this, unsigned int in_srcID, float in_fOffset)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rax
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v4; // r8
  CAkFeedbackNode::SrcInfo **p_item; // rdi
  AkActivityChunk *m_pActivityChunk; // rbx
  float v7; // xmm0_4
  CAkPBI *i; // rbx
  NotifParams in_rParams; // [rsp+20h] [rbp-48h] BYREF

  m_pItems = this->m_arSrcInfo.m_pItems;
  v4 = &m_pItems[this->m_arSrcInfo.m_uLength];
  if ( m_pItems != v4 )
  {
    do
    {
      if ( m_pItems->key == in_srcID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v4 );
    if ( m_pItems != v4 )
    {
      p_item = &m_pItems->item;
      if ( m_pItems != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)-8i64 )
      {
        m_pActivityChunk = this->m_pActivityChunk;
        in_rParams.eType = RTPC_Volume;
        in_rParams.bIsFromBus = 0;
        in_rParams.pGameObj = 0i64;
        v7 = in_fOffset - (*p_item)->m_fVolumeOffset;
        in_rParams.pExceptObjects = 0i64;
        in_rParams.fValue = v7;
        if ( m_pActivityChunk )
        {
          for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
          {
            if ( i->m_pSource == *p_item )
              CAkPBI::ParamNotification(i, &in_rParams);
          }
        }
        (*p_item)->m_fVolumeOffset = in_fOffset;
      }
    }
  }
}

// File Line: 302
// RVA: 0xA8E7D0
float __fastcall CAkFeedbackNode::GetSourceVolumeOffset(CAkFeedbackNode *this, CAkFeedbackNode::SrcInfo *in_pSource)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rax
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *i; // r8

  m_pItems = this->m_arSrcInfo.m_pItems;
  for ( i = &m_pItems[this->m_arSrcInfo.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->item == in_pSource )
      break;
  }
  return m_pItems->item->m_fVolumeOffset;
}

// File Line: 323
// RVA: 0xA8E9B0
void __fastcall CAkFeedbackNode::RemoveAllSources(CAkFeedbackNode *this)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rbx
  CAkFeedbackNode::SrcInfo *item; // rdi
  int v4; // ebp

  m_pItems = this->m_arSrcInfo.m_pItems;
  if ( m_pItems == &m_pItems[this->m_arSrcInfo.m_uLength] )
  {
    this->m_arSrcInfo.m_uLength = 0;
  }
  else
  {
    do
    {
      item = m_pItems->item;
      v4 = g_DefaultPoolId;
      if ( item )
      {
        CAkSource::~CAkSource(m_pItems->item);
        AK::MemoryMgr::Free(v4, item);
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
    this->m_arSrcInfo.m_uLength = 0;
  }
}

// File Line: 332
// RVA: 0xA8E710
__int64 __fastcall CAkFeedbackNode::GetFeedbackParameters(
        CAkFeedbackNode *this,
        AkFeedbackParams *io_Params,
        CAkFeedbackNode::SrcInfo *in_pSource,
        CAkRegisteredObj *in_GameObjPtr)
{
  CAkFeedbackBus *FeedbackParentBusOrDefault; // r10
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rax
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *i; // rdx
  unsigned __int16 m_idDeviceCompany; // ax

  FeedbackParentBusOrDefault = CAkParameterNodeBase::GetFeedbackParentBusOrDefault(this);
  if ( !FeedbackParentBusOrDefault )
    return 2i64;
  m_pItems = this->m_arSrcInfo.m_pItems;
  for ( i = &m_pItems[this->m_arSrcInfo.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->item == in_pSource )
      break;
  }
  if ( !io_Params->m_usPluginID )
  {
    io_Params->m_usPluginID = m_pItems->item->m_idDevicePlugin;
    m_idDeviceCompany = m_pItems->item->m_idDeviceCompany;
    io_Params->m_pOutput = FeedbackParentBusOrDefault;
    io_Params->m_usCompanyID = m_idDeviceCompany;
  }
  io_Params->m_NewVolume = 0.0;
  io_Params->m_MotionBusPitch = 0.0;
  return ((__int64 (__fastcall *)(CAkFeedbackBus *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, _BYTE))FeedbackParentBusOrDefault->vfptr[16].__vecDelDtor)(
           FeedbackParentBusOrDefault,
           io_Params,
           in_pSource,
           in_GameObjPtr,
           0);
}

// File Line: 358
// RVA: 0xA8E940
__int64 __fastcall CAkFeedbackNode::PrepareData(CAkFeedbackNode *this)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *m_pItems; // rbx
  unsigned int v3; // edi
  unsigned int v4; // eax

  m_pItems = this->m_arSrcInfo.m_pItems;
  v3 = 1;
  if ( m_pItems != &m_pItems[this->m_arSrcInfo.m_uLength] )
  {
    do
    {
      v4 = CAkSource::PrepareData(m_pItems->item);
      if ( v4 != 1 )
        v3 = v4;
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
  }
  return v3;
}

// File Line: 372
// RVA: 0xA8EC40
void __fastcall CAkFeedbackNode::UnPrepareData(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rbx

  m_pItems = this->m_arSrcInfo.m_pItems;
  if ( m_pItems != &m_pItems[this->m_arSrcInfo.m_uLength] )
  {
    do
    {
      CAkSource::UnPrepareData(m_pItems->item);
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
  }
}

// File Line: 381
// RVA: 0xA8E6F0
__int64 __fastcall CAkFeedbackNode::GetAudioParameters(
        CAkFeedbackNode *this,
        AkSoundParamsEx *io_Parameters,
        unsigned int in_ulParamSelect,
        CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap,
        CAkRegisteredObj *in_GameObjPtr,
        float in_bIncludeRange,
        AkPBIModValues *io_Ranges)
{
  return CAkParameterNode::GetAudioParameters(
           this,
           io_Parameters,
           in_ulParamSelect,
           io_rMutedMap,
           in_GameObjPtr,
           in_bIncludeRange,
           io_Ranges,
           0);
}

