// File Line: 47
// RVA: 0xA8E4B0
CAkFeedbackNode *__fastcall CAkFeedbackNode::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkFeedbackNode *result; // rax
  CAkFeedbackNode *v3; // rbx
  unsigned int v4; // eax
  signed int v5; // ecx
  bool v6; // al

  v1 = in_ulID;
  result = (CAkFeedbackNode *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA8ui64);
  v3 = result;
  if ( result )
  {
    CAkSoundBase::CAkSoundBase((CAkSoundBase *)&result->vfptr, v1);
    v3->vfptr = (CAkIndexableVtbl *)&CAkFeedbackNode::`vftable;
    v3->m_arSrcInfo.m_pItems = 0i64;
    *(_QWORD *)&v3->m_arSrcInfo.m_uLength = 0i64;
    v4 = v3->vfptr[3].Release((CAkIndexable *)&v3->vfptr);
    v6 = 0;
    if ( v4 <= 0xC )
    {
      v5 = 5121;
      if ( _bittest(&v5, v4) )
        v6 = 1;
    }
    *((_BYTE *)&v3->0 + 83) &= 0xFDu;
    *((_BYTE *)&v3->0 + 83) |= 2 * v6;
    CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)&v3->vfptr);
    result = v3;
  }
  return result;
}

// File Line: 65
// RVA: 0xA8E880
signed __int64 __fastcall CAkFeedbackNode::PlayInternal(CAkFeedbackNode *this, AkPBIParams *in_rPBIParams)
{
  unsigned int v2; // eax
  AkPBIParams *v3; // rsi
  CAkFeedbackNode *v4; // rdi
  CAkFeedbackDeviceMgr *v5; // rbp
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v6; // rax
  CAkSource **v7; // rbx

  v2 = in_rPBIParams->uFrameOffset;
  in_rPBIParams->bTargetFeedback = 1;
  v3 = in_rPBIParams;
  v4 = this;
  in_rPBIParams->uFrameOffset = 8 * v2 >> 10;
  v5 = CAkFeedbackDeviceMgr::s_pSingleton;
  if ( CAkFeedbackDeviceMgr::s_pSingleton )
  {
    v6 = this->m_arSrcInfo.m_pItems;
    if ( v6 != &v6[this->m_arSrcInfo.m_uLength] )
    {
      v7 = (CAkSource **)&v6->item;
      do
      {
        if ( CAkFeedbackDeviceMgr::IsDeviceActive(
               v5,
               LOWORD((*v7)[1].m_sSrcTypeInfo.mediaInfo.sourceID),
               HIWORD((*v7)[1].m_sSrcTypeInfo.mediaInfo.sourceID)) )
        {
          CAkURenderer::Play((CAkSoundBase *)&v4->vfptr, *v7, v3);
        }
        v7 += 2;
      }
      while ( v7 - 1 != (CAkSource **)&v4->m_arSrcInfo.m_pItems[v4->m_arSrcInfo.m_uLength] );
    }
  }
  return 1i64;
}

// File Line: 88
// RVA: 0xA8E550
signed __int64 __fastcall CAkFeedbackNode::ExecuteAction(CAkFeedbackNode *this, ActionParams *in_rAction)
{
  ActionParams *v2; // rbx
  CAkFeedbackNode *v3; // rdi
  AkActivityChunk *v4; // rax

  v2 = in_rAction;
  v3 = this;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkFeedbackNode *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  v4 = v3->m_pActivityChunk;
  if ( !v4 || !v4->m_PlayCount )
    return 1i64;
  if ( v2->eType == ActionParamType_Stop )
    return CAkURenderer::Stop((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType == 1 )
    return CAkURenderer::Pause((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType != 2 )
  {
    if ( v2->eType == 3 )
      ((void (__fastcall *)(CAkFeedbackNode *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))v3->vfptr[4].Category)(
        v3,
        v2->pGameObj,
        v2->targetNodePtr,
        v2->playingID);
    return 1i64;
  }
  return CAkURenderer::Resume(
           (CAkSoundBase *)&v3->vfptr,
           v2->pGameObj,
           &v2->transParams,
           v2->bIsMasterResume,
           v2->playingID);
}

// File Line: 118
// RVA: 0xA8E630
signed __int64 __fastcall CAkFeedbackNode::ExecuteActionExcept(CAkFeedbackNode *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rbx
  CAkFeedbackNode *v3; // rdi
  AkActivityChunk *v4; // rax

  v2 = in_rAction;
  v3 = this;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkFeedbackNode *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  v4 = v3->m_pActivityChunk;
  if ( v4 && v4->m_PlayCount )
  {
    switch ( v2->eType )
    {
      case 0:
        return CAkURenderer::Stop((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
      case 1:
        return CAkURenderer::Pause((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
      case 2:
        return CAkURenderer::Resume(
                 (CAkSoundBase *)&v3->vfptr,
                 v2->pGameObj,
                 &v2->transParams,
                 v2->bIsMasterResume,
                 v2->playingID);
    }
  }
  return 1i64;
}

// File Line: 160
// RVA: 0xA8E810
__int64 __fastcall CAkFeedbackNode::IncrementPlayCount(CAkFeedbackNode *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rsi
  CAkFeedbackNode *v3; // rdi
  CAkParameterNodeBase *v4; // rbx

  v2 = io_params;
  v3 = this;
  if ( !((__int64 (*)(void))this->vfptr[16].Release)() )
  {
    v4 = v3->m_pParentNode;
    if ( v4 )
    {
      while ( !(__int64)v4->vfptr[16].Release((CAkIndexable *)&v4->vfptr) )
      {
        v4 = v4->m_pParentNode;
        if ( !v4 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      CAkParameterNodeBase::GetFeedbackParentBusOrDefault((CAkParameterNodeBase *)&v3->vfptr);
    }
  }
  return CAkParameterNode::IncrementPlayCount((CAkParameterNode *)&v3->vfptr, v2);
}

// File Line: 191
// RVA: 0xA8EA50
signed __int64 __fastcall CAkFeedbackNode::SetInitialValues(CAkFeedbackNode *this, char *in_pData, unsigned int in_ulDataSize, CAkUsageSlot *in_pUsageSlot, bool in_bIsPartialLoadOnly)
{
  char *v5; // rdx
  int v6; // edi
  unsigned int v7; // er14
  char *v8; // rdx
  CAkFeedbackNode *v9; // rbp
  unsigned int v10; // ebx
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // si
  char *v13; // rdx
  float v14; // xmm6_4
  signed __int64 result; // rax
  AkBankSourceData out_rSource; // [rsp+20h] [rbp-58h]
  char *io_pData; // [rsp+88h] [rbp+10h]
  unsigned int io_ulDataSize; // [rsp+90h] [rbp+18h]

  io_ulDataSize = in_ulDataSize;
  v5 = in_pData + 4;
  v6 = 0;
  io_pData = v5;
  v7 = *(_DWORD *)v5;
  v8 = v5 + 4;
  v9 = this;
  v10 = 1;
  io_pData = v8;
  if ( !v7 )
    return CAkParameterNodeBase::SetNodeBaseParams(
             (CAkParameterNodeBase *)&v9->vfptr,
             &io_pData,
             &io_ulDataSize,
             in_bIsPartialLoadOnly);
  while ( v10 == 1 )
  {
    v11 = *(_WORD *)v8;
    io_pData = v8 + 2;
    v12 = *((_WORD *)v8 + 1);
    io_pData = v8 + 4;
    v13 = v8 + 8;
    v14 = *((float *)v13 - 1);
    io_pData = v13;
    result = CAkBankMgr::LoadSource(&io_pData, &io_ulDataSize, &out_rSource);
    if ( (_DWORD)result != 1 )
      return result;
    v10 = CAkFeedbackNode::AddPluginSource(v9, out_rSource.m_MediaInfo.sourceID, v11, v12);
    CAkFeedbackNode::SetSourceVolumeOffset(v9, out_rSource.m_MediaInfo.sourceID, v14);
    if ( ++v6 >= v7 )
    {
      if ( v10 == 1 )
        return CAkParameterNodeBase::SetNodeBaseParams(
                 (CAkParameterNodeBase *)&v9->vfptr,
                 &io_pData,
                 &io_ulDataSize,
                 in_bIsPartialLoadOnly);
      return v10;
    }
    v8 = io_pData;
  }
  return v10;
}

// File Line: 238
// RVA: 0xA8E380
signed __int64 __fastcall CAkFeedbackNode::AddPluginSource(CAkFeedbackNode *this, unsigned int in_srcID, unsigned __int16 in_idDeviceCompany, unsigned __int16 in_idDevicePlugin)
{
  AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v4; // r14
  unsigned __int16 v5; // bp
  unsigned __int16 v6; // r15
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v7; // rax
  unsigned int v8; // edi
  signed __int64 v9; // r10
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v10; // rcx
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v11; // r10
  signed __int64 result; // rax
  signed __int64 v13; // rbx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v14; // rax
  CAkSource *v15; // rax
  CAkSource *v16; // rsi

  v4 = (AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&this->m_arSrcInfo;
  v5 = in_idDevicePlugin;
  v6 = in_idDeviceCompany;
  v7 = this->m_arSrcInfo.m_pItems;
  v8 = in_srcID;
  v9 = this->m_arSrcInfo.m_uLength;
  v10 = v7;
  v11 = &v7[v9];
  if ( v7 != v11 )
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
  for ( ; v7 != v11; ++v7 )
  {
    if ( v7->key == in_srcID )
      break;
  }
  if ( v7 == v11 )
  {
    v13 = 0i64;
  }
  else
  {
    v13 = (signed __int64)&v7->item;
    if ( v7 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)-8i64 )
      goto LABEL_17;
  }
  v14 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v4);
  if ( v14 )
  {
    LODWORD(v14->key) = v8;
    v13 = (signed __int64)&v14->item;
  }
  if ( !v13 )
    return 2i64;
LABEL_17:
  v15 = (CAkSource *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v16 = v15;
  if ( v15 )
    CAkSource::CAkSource(v15);
  else
    v16 = 0i64;
  *(_QWORD *)v13 = v16;
  if ( v16 )
  {
    CAkSource::SetSource(v16, v8);
    *(_WORD *)(*(_QWORD *)v13 + 40i64) = v6;
    *(_WORD *)(*(_QWORD *)v13 + 42i64) = v5;
    *(_DWORD *)(*(_QWORD *)v13 + 44i64) = 0;
  }
  else
  {
    CAkKeyArray<unsigned long,CAkMusicSource *,4>::Unset((CAkKeyArray<unsigned long,CAkMusicSource *,4> *)v4, v8);
  }
  result = 1i64;
  if ( !*(_QWORD *)v13 )
    return 2i64;
  return result;
}

// File Line: 269
// RVA: 0xA8EB70
void __fastcall CAkFeedbackNode::SetSourceVolumeOffset(CAkFeedbackNode *this, unsigned int in_srcID, float in_fOffset)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v3; // rax
  signed __int64 v4; // r8
  signed __int64 v5; // rdi
  AkActivityChunk *v6; // rbx
  float v7; // xmm0_4
  CAkPBI *i; // rbx
  NotifParams in_rParams; // [rsp+20h] [rbp-48h]

  v3 = this->m_arSrcInfo.m_pItems;
  v4 = (signed __int64)&v3[this->m_arSrcInfo.m_uLength];
  if ( v3 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)v4 )
  {
    do
    {
      if ( v3->key == in_srcID )
        break;
      ++v3;
    }
    while ( v3 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)v4 );
    if ( v3 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)v4 )
    {
      v5 = (signed __int64)&v3->item;
      if ( v3 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)-8i64 )
      {
        v6 = this->m_pActivityChunk;
        in_rParams.eType = 0;
        in_rParams.bIsFromBus = 0;
        in_rParams.pGameObj = 0i64;
        v7 = in_fOffset - *(float *)(*(_QWORD *)v5 + 44i64);
        in_rParams.pExceptObjects = 0i64;
        in_rParams.fValue = v7;
        if ( v6 )
        {
          for ( i = v6->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
          {
            if ( i->m_pSource == *(CAkSource **)v5 )
              CAkPBI::ParamNotification(i, &in_rParams);
          }
        }
        *(float *)(*(_QWORD *)v5 + 44i64) = in_fOffset;
      }
    }
  }
}

// File Line: 302
// RVA: 0xA8E7D0
float __fastcall CAkFeedbackNode::GetSourceVolumeOffset(CAkFeedbackNode *this, CAkSource *in_pSource)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v2; // rax
  signed __int64 i; // r8

  v2 = this->m_arSrcInfo.m_pItems;
  for ( i = (signed __int64)&v2[this->m_arSrcInfo.m_uLength];
        v2 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)i;
        ++v2 )
  {
    if ( (CAkSource *)v2->item == in_pSource )
      break;
  }
  return v2->item->m_fVolumeOffset;
}

// File Line: 323
// RVA: 0xA8E9B0
void __fastcall CAkFeedbackNode::RemoveAllSources(CAkFeedbackNode *this)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v1; // rbx
  CAkFeedbackNode *v2; // rsi
  CAkFeedbackNode::SrcInfo *v3; // rdi
  int v4; // ebp

  v1 = this->m_arSrcInfo.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_arSrcInfo.m_uLength] )
  {
    this->m_arSrcInfo.m_uLength = 0;
  }
  else
  {
    do
    {
      v3 = v1->item;
      v4 = g_DefaultPoolId;
      if ( v3 )
      {
        CAkSource::~CAkSource((CAkSource *)&v1->item->m_sSrcTypeInfo);
        AK::MemoryMgr::Free(v4, v3);
      }
      ++v1;
    }
    while ( v1 != &v2->m_arSrcInfo.m_pItems[v2->m_arSrcInfo.m_uLength] );
    v2->m_arSrcInfo.m_uLength = 0;
  }
}

// File Line: 332
// RVA: 0xA8E710
__int64 __fastcall CAkFeedbackNode::GetFeedbackParameters(CAkFeedbackNode *this, AkFeedbackParams *io_Params, CAkSource *in_pSource, CAkRegisteredObj *in_GameObjPtr)
{
  CAkRegisteredObj *v4; // rbp
  CAkSource *v5; // rbx
  AkFeedbackParams *v6; // rdi
  CAkFeedbackNode *v7; // rsi
  CAkFeedbackBus *v8; // r10
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v10; // rax
  signed __int64 i; // rdx
  unsigned __int16 v12; // ax

  v4 = in_GameObjPtr;
  v5 = in_pSource;
  v6 = io_Params;
  v7 = this;
  v8 = CAkParameterNodeBase::GetFeedbackParentBusOrDefault((CAkParameterNodeBase *)&this->vfptr);
  if ( !v8 )
    return 2i64;
  v10 = v7->m_arSrcInfo.m_pItems;
  for ( i = (signed __int64)&v10[v7->m_arSrcInfo.m_uLength];
        v10 != (MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *)i;
        ++v10 )
  {
    if ( (CAkSource *)v10->item == v5 )
      break;
  }
  if ( !v6->m_usPluginID )
  {
    v6->m_usPluginID = v10->item->m_idDevicePlugin;
    v12 = v10->item->m_idDeviceCompany;
    v6->m_pOutput = v8;
    v6->m_usCompanyID = v12;
  }
  v6->m_NewVolume = 0.0;
  v6->m_MotionBusPitch = 0.0;
  return ((__int64 (__fastcall *)(CAkFeedbackBus *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, _BYTE))v8->vfptr[16].__vecDelDtor)(
           v8,
           v6,
           v5,
           v4,
           0);
}

// File Line: 358
// RVA: 0xA8E940
__int64 __fastcall CAkFeedbackNode::PrepareData(CAkFeedbackNode *this)
{
  MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> *v1; // rbx
  CAkFeedbackNode *v2; // rsi
  unsigned int v3; // edi
  unsigned int v4; // eax

  v1 = this->m_arSrcInfo.m_pItems;
  v2 = this;
  v3 = 1;
  if ( v1 != &v1[this->m_arSrcInfo.m_uLength] )
  {
    do
    {
      v4 = CAkSource::PrepareData((CAkSource *)&v1->item->m_sSrcTypeInfo);
      if ( v4 != 1 )
        v3 = v4;
      ++v1;
    }
    while ( v1 != &v2->m_arSrcInfo.m_pItems[v2->m_arSrcInfo.m_uLength] );
  }
  return v3;
}

// File Line: 372
// RVA: 0xA8EC40
void __fastcall CAkFeedbackNode::UnPrepareData(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *v1; // rbx
  CAkMusicTrack *v2; // rdi

  v1 = this->m_arSrcInfo.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_arSrcInfo.m_uLength] )
  {
    do
    {
      CAkSource::UnPrepareData((CAkSource *)&v1->item->m_sSrcTypeInfo);
      ++v1;
    }
    while ( v1 != &v2->m_arSrcInfo.m_pItems[v2->m_arSrcInfo.m_uLength] );
  }
}

// File Line: 381
// RVA: 0xA8E6F0
signed __int64 __fastcall CAkFeedbackNode::GetAudioParameters(CAkFeedbackNode *this, AkSoundParamsEx *io_Parameters, unsigned int in_ulParamSelect, CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap, CAkRegisteredObj *in_GameObjPtr, bool in_bIncludeRange, AkPBIModValues *io_Ranges)
{
  return CAkParameterNode::GetAudioParameters(
           (CAkParameterNode *)&this->vfptr,
           io_Parameters,
           in_ulParamSelect,
           io_rMutedMap,
           in_GameObjPtr,
           in_bIncludeRange,
           io_Ranges,
           0);
}

