// File Line: 42
// RVA: 0xA8B4F0
void __fastcall CAkRanSeqCntr::CAkRanSeqCntr(
        CAkRanSeqCntr *this,
        unsigned int in_ulID,
        AkContainerMode in_ContainerMode)
{
  char v3; // bl

  v3 = in_ContainerMode;
  CAkContainerBase::CAkContainerBase(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkRanSeqCntr::`vftable;
  this->m_pPlayList = 0i64;
  this->m_mapObjectCntrInfo.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapObjectCntrInfo.m_uLength = 0i64;
  this->m_pGlobalContainerInfo = 0i64;
  *(_QWORD *)&this->m_TransitionTime.m_base = 0i64;
  *(_QWORD *)&this->m_TransitionTime.m_mod.m_max = 0i64;
  *(_DWORD *)&this->m_LoopRanged.m_mod.m_max = 0;
  *((_BYTE *)this + 222) &= ~1u;
  *((_BYTE *)this + 220) &= 0xC0u;
  this->m_LoopRanged.m_base = 1;
  *((_BYTE *)this + 221) = v3 & 7 | 0x90;
}

// File Line: 98
// RVA: 0xA8CD10
__int64 __fastcall CAkRanSeqCntr::SetInitialValues(CAkRanSeqCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  __int64 result; // rax
  char *v5; // rdx
  __int16 v6; // ax
  __int16 v7; // cx
  __int16 v8; // r8
  char *v9; // rdx
  int v10; // ebx
  float v11; // xmm6_4
  float v12; // xmm7_4
  char *v13; // rdx
  float v14; // xmm8_4
  unsigned __int16 v15; // si
  unsigned __int8 v16; // r14
  unsigned __int8 v17; // r15
  AkContainerMode v18; // eax
  char v19; // r12
  char v20; // r13
  char v21; // cl
  unsigned int v22; // edx
  unsigned int v23; // eax
  char *v24; // rcx
  unsigned int v25; // esi
  unsigned int v26; // edx
  unsigned int v27; // r8d
  unsigned int v28; // eax
  char v29; // [rsp+20h] [rbp-19h]
  char *io_rpData; // [rsp+A8h] [rbp+6Fh] BYREF
  unsigned int io_rulDataSize; // [rsp+B0h] [rbp+77h] BYREF
  char v32; // [rsp+B8h] [rbp+7Fh]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  result = CAkParameterNodeBase::SetNodeBaseParams(this, &io_rpData, &io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
  {
    v5 = io_rpData;
    v6 = *(_WORD *)io_rpData;
    io_rpData += 2;
    v7 = *((_WORD *)v5 + 1);
    io_rpData = v5 + 4;
    v8 = *((_WORD *)v5 + 2);
    v9 = v5 + 6;
    v10 = 0;
    io_rpData = v9;
    if ( v6 )
    {
      this->m_LoopRanged.m_base = v6;
      this->m_LoopRanged.m_mod.m_min = v7;
      this->m_LoopRanged.m_mod.m_max = v8;
    }
    else
    {
      *(_DWORD *)&this->m_LoopRanged.m_base = 0;
      this->m_LoopRanged.m_mod.m_max = 0;
    }
    v11 = *(float *)v9;
    io_rpData = v9 + 4;
    v12 = *((float *)v9 + 1);
    io_rpData = v9 + 8;
    v13 = v9 + 12;
    v14 = *((float *)v13 - 1);
    io_rpData = v13;
    v15 = *(_WORD *)v13;
    io_rpData = v13 + 2;
    v13 += 3;
    v16 = *(v13 - 1);
    io_rpData = v13;
    v17 = *v13;
    io_rpData = v13 + 1;
    v13 += 3;
    v18 = (unsigned __int8)*(v13 - 2);
    io_rpData = v13;
    v19 = *v13;
    io_rpData = v13 + 1;
    v13 += 2;
    v20 = *(v13 - 1);
    io_rpData = v13;
    v32 = *v13;
    io_rpData = v13 + 1;
    v21 = v13[1];
    io_rpData = v13 + 2;
    v29 = v21;
    result = CAkRanSeqCntr::Mode(this, v18);
    if ( (_DWORD)result == 1 )
    {
      this->m_TransitionTime.m_base = v11;
      this->m_TransitionTime.m_mod.m_min = v12;
      this->m_TransitionTime.m_mod.m_max = v14;
      CAkRanSeqCntr::AvoidRepeatingCount(this, v15);
      CAkRanSeqCntr::TransitionMode(this, (AkTransitionMode)v16);
      CAkRanSeqCntr::RandomMode(this, (AkRandomMode)v17);
      CAkRanSeqCntr::ResetPlayListAtEachPlay(this, v19 != 0);
      *((_BYTE *)this + 221) &= ~0x20u;
      *((_BYTE *)this + 221) |= 32 * (v20 != 0);
      CAkRanSeqCntr::Continuous(this, v32 != 0);
      CAkRanSeqCntr::IsGlobal(this, v29 != 0);
      result = CAkParentNode<CAkParameterNode>::SetChildren(this, &io_rpData, &io_rulDataSize);
      if ( (_DWORD)result == 1 )
      {
        v22 = 1;
        v23 = *(unsigned __int16 *)io_rpData;
        v24 = io_rpData + 2;
        io_rpData += 2;
        v25 = v23;
        if ( v23 )
        {
          while ( 1 )
          {
            v26 = *(_DWORD *)v24;
            io_rpData = v24 + 4;
            v27 = *((_DWORD *)v24 + 1);
            io_rpData = v24 + 8;
            v28 = CAkRanSeqCntr::AddPlaylistItem(this, v26, v27);
            v22 = v28;
            if ( v28 == 15 )
            {
              v22 = 1;
            }
            else if ( v28 != 1 )
            {
              return v22;
            }
            if ( ++v10 >= v25 )
              break;
            v24 = io_rpData;
          }
        }
        return v22;
      }
    }
  }
  return result;
}

// File Line: 171
// RVA: 0xA8C360
__int64 __fastcall CAkRanSeqCntr::Init(CAkRanSeqCntr *this)
{
  unsigned int v2; // eax
  int v3; // ecx
  bool v4; // al
  CAkPlayListSequence *v5; // rax
  CAkPlayList *v6; // rax
  CAkPlayListRandom *v7; // rax

  v2 = this->vfptr[3].Release(this);
  v4 = 0;
  if ( v2 <= 0xC )
  {
    v3 = 5121;
    if ( _bittest(&v3, v2) )
      v4 = 1;
  }
  *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~2u;
  *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 2 * v4;
  CAkParameterNodeBase::AddToIndex(this);
  if ( (*((_BYTE *)this + 221) & 7) == 1 )
  {
    v5 = (CAkPlayListSequence *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( v5 )
    {
      CAkPlayListSequence::CAkPlayListSequence(v5);
      goto LABEL_11;
    }
  }
  else
  {
    v7 = (CAkPlayListRandom *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( v7 )
    {
      CAkPlayListRandom::CAkPlayListRandom(v7);
      goto LABEL_11;
    }
  }
  v6 = 0i64;
LABEL_11:
  this->m_pPlayList = v6;
  if ( v6 )
    return (*(__int64 (__fastcall **)(CAkPlayList *))v6->vfptr->gap8)(v6);
  else
    return 2i64;
}

// File Line: 199
// RVA: 0xA8CFB0
void __fastcall CAkRanSeqCntr::Term(CAkRanSeqCntr *this)
{
  CAkPlayList *m_pPlayList; // rcx
  CAkRanSeqCntr::CntrInfoEntry *m_pItems; // rdx

  m_pPlayList = this->m_pPlayList;
  if ( m_pPlayList )
  {
    if ( m_pPlayList->vfptr->Length(m_pPlayList) )
    {
      this->m_pPlayList->vfptr->RemoveAll(this->m_pPlayList);
      *((_BYTE *)this + 221) &= ~8u;
      CAkRanSeqCntr::DestroySpecificInfo(this);
    }
    this->m_pPlayList->vfptr->Destroy(this->m_pPlayList);
  }
  m_pItems = this->m_mapObjectCntrInfo.m_pItems;
  if ( m_pItems )
  {
    this->m_mapObjectCntrInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapObjectCntrInfo.m_pItems = 0i64;
    this->m_mapObjectCntrInfo.m_ulReserved = 0;
  }
}

// File Line: 217
// RVA: 0xA8B950
void __fastcall CAkRanSeqCntr::Create(unsigned int in_ulID, AkContainerMode in_ContainerMode)
{
  CAkRanSeqCntr *v4; // rax
  CAkRanSeqCntr *v5; // rax
  CAkRanSeqCntr *v6; // rbx

  v4 = (CAkRanSeqCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xE0ui64);
  if ( v4 )
  {
    CAkRanSeqCntr::CAkRanSeqCntr(v4, in_ulID, in_ContainerMode);
    v6 = v5;
    if ( v5 )
    {
      if ( CAkRanSeqCntr::Init(v5) != AK_Success )
        v6->vfptr->Release(v6);
    }
  }
}

// File Line: 239
// RVA: 0xA8D1E0
void __fastcall CAkRanSeqCntr::Unregister(CAkRanSeqCntr *this, CAkRegisteredObj *in_pGameObj)
{
  CAkRTPCMgr::AkRTPCValue *v4; // rax

  CAkParameterNode::Unregister(this, in_pGameObj);
  v4 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
         in_pGameObj);
  if ( v4 )
  {
    (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&v4->fValue + 8i64))(*(_QWORD *)&v4->fValue);
    AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Unset<CAkRegisteredObj *>(
      (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
      in_pGameObj);
  }
}

// File Line: 258
// RVA: 0xA8CF90
__int64 __fastcall CAkRanSeqCntr::SetParamComplexFromRTPCManager(
        CAkRanSeqCntr *this,
        _QWORD *in_pToken,
        __int64 in_Param_id,
        __int64 in_RTPCid,
        float in_value,
        CAkRegisteredObj *in_GameObj,
        void *in_pGameObjExceptArray)
{
  if ( (_DWORD)in_Param_id == 5 )
    return 1i64;
  else
    return CAkParameterNodeBase::SetParamComplexFromRTPCManager(
             this,
             in_pToken,
             in_Param_id,
             in_RTPCid,
             in_value,
             in_GameObj,
             in_pGameObjExceptArray);
}

// File Line: 273
// RVA: 0xA8BB50
void __fastcall CAkRanSeqCntr::CreateSequenceInfo(CAkRanSeqCntr *this)
{
  CAkSequenceInfo *v1; // rax

  v1 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
  if ( v1 )
    CAkSequenceInfo::CAkSequenceInfo(v1);
}

// File Line: 278
// RVA: 0xA8BAC0
CAkRandomInfo *__fastcall CAkRanSeqCntr::CreateRandomInfo(CAkRanSeqCntr *this, unsigned __int16 in_uPlaylistSize)
{
  CAkRandomInfo *v4; // rax
  CAkRandomInfo *v5; // rax
  CAkRandomInfo *v6; // rbx
  unsigned int v8; // eax

  v4 = (CAkRandomInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  if ( !v4 )
    return 0i64;
  CAkRandomInfo::CAkRandomInfo(v4, in_uPlaylistSize);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  if ( CAkRandomInfo::Init(v5, this->m_wAvoidRepeatCount) != AK_Success )
  {
    v6->vfptr->Destroy(v6);
    return 0i64;
  }
  if ( (*((_BYTE *)this + 221) & 8) != 0 )
  {
    v8 = (*(__int64 (__fastcall **)(CAkPlayList *))this->m_pPlayList->vfptr[1].gap8)(this->m_pPlayList);
    v6->m_ulRemainingWeight = v8;
    v6->m_ulTotalWeight = v8;
  }
  return v6;
}

// File Line: 297
// RVA: 0xA8BD20
CAkSequenceInfo *__fastcall CAkRanSeqCntr::GetExistingSequenceInfo(CAkRanSeqCntr *this, CAkRegisteredObj *in_pGameObj)
{
  CAkContainerBaseInfo *v2; // rbx
  CAkSequenceInfo *v5; // rax
  CAkContainerBaseInfo *v6; // rax
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  CAkSequenceInfo *v8; // rax
  CAkContainerBaseInfo *v9; // rax
  CAkRanSeqCntr::CntrInfoEntry *v11; // rax

  v2 = 0i64;
  if ( *((char *)this + 221) < 0 )
  {
    if ( !this->m_pGlobalContainerInfo )
    {
      v5 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
      if ( v5 )
        CAkSequenceInfo::CAkSequenceInfo(v5);
      else
        v6 = 0i64;
      this->m_pGlobalContainerInfo = v6;
    }
    if ( this->m_pGlobalContainerInfo )
      return (CAkSequenceInfo *)this->m_pGlobalContainerInfo;
    return (CAkSequenceInfo *)v2;
  }
  v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
         in_pGameObj);
  if ( v7 )
    return *(CAkSequenceInfo **)&v7->fValue;
  v8 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
  if ( !v8 )
    return 0i64;
  CAkSequenceInfo::CAkSequenceInfo(v8);
  v2 = v9;
  if ( !v9 )
    return 0i64;
  if ( (unsigned int)CAkRegisteredObj::SetNodeAsModified(in_pGameObj, this) != 1 )
  {
    v2->vfptr->Destroy(v2);
    return 0i64;
  }
  v11 = AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1>::Set<CAkRegisteredObj *>(
          &this->m_mapObjectCntrInfo,
          in_pGameObj);
  if ( !v11 )
  {
    v2->vfptr->Destroy(v2);
    return 0i64;
  }
  v11->pInfo = v2;
  return (CAkSequenceInfo *)v2;
}

// File Line: 343
// RVA: 0xA8BC40
CAkRandomInfo *__fastcall CAkRanSeqCntr::GetExistingRandomInfo(
        CAkRanSeqCntr *this,
        unsigned __int16 in_uPlaylistSize,
        CAkRegisteredObj *in_pGameObj)
{
  CAkRandomInfo *RandomInfo; // rbx
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  CAkRanSeqCntr::CntrInfoEntry *v9; // rax

  RandomInfo = 0i64;
  if ( *((char *)this + 221) < 0 )
  {
    if ( !this->m_pGlobalContainerInfo )
      this->m_pGlobalContainerInfo = CAkRanSeqCntr::CreateRandomInfo(this, in_uPlaylistSize);
    if ( this->m_pGlobalContainerInfo )
      return (CAkRandomInfo *)this->m_pGlobalContainerInfo;
    return RandomInfo;
  }
  v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
         in_pGameObj);
  if ( v7 )
    return *(CAkRandomInfo **)&v7->fValue;
  RandomInfo = CAkRanSeqCntr::CreateRandomInfo(this, in_uPlaylistSize);
  if ( !RandomInfo )
    return 0i64;
  if ( (unsigned int)CAkRegisteredObj::SetNodeAsModified(in_pGameObj, this) != 1
    || (v9 = AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1>::Set<CAkRegisteredObj *>(
               &this->m_mapObjectCntrInfo,
               in_pGameObj)) == 0i64 )
  {
    RandomInfo->vfptr->Destroy(RandomInfo);
    return 0i64;
  }
  v9->pInfo = RandomInfo;
  return RandomInfo;
}

// File Line: 388
// RVA: 0xA8BE20
CAkParameterNodeBase *__fastcall CAkRanSeqCntr::GetNextToPlay(
        CAkRanSeqCntr *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned __int16 *out_rwPositionSelected,
        unsigned int *out_uSelectedNodeID)
{
  unsigned __int16 v4; // di
  CAkParameterNodeBase *v8; // r14
  unsigned int v9; // eax
  unsigned int v10; // r13d
  char v11; // r15
  int v12; // r12d
  CAkParameterNodeBase *v13; // rbx
  CAkParameterNodeBase *result; // rax
  CAkRandomInfo *i; // rcx
  bool CanPlayPosition; // bp
  int v17; // edi
  __int16 v18; // ax
  unsigned __int16 v19; // ax
  unsigned __int16 v20; // ax
  unsigned int v21; // eax
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  unsigned int v23; // eax
  CAkRandomInfo *in_pRandomInfo; // [rsp+20h] [rbp-48h]
  bool out_bIsAnswerValid; // [rsp+70h] [rbp+8h] BYREF
  unsigned __int16 *v26; // [rsp+80h] [rbp+18h]
  unsigned int *v27; // [rsp+88h] [rbp+20h]

  v27 = out_uSelectedNodeID;
  v26 = out_rwPositionSelected;
  v4 = 0;
  *out_rwPositionSelected = 0;
  *out_uSelectedNodeID = 0;
  v8 = 0i64;
  v9 = this->m_pPlayList->vfptr->Length(this->m_pPlayList);
  v10 = v9;
  if ( !v9 )
    return v8;
  if ( v9 == 1 )
  {
    v23 = this->m_pPlayList->vfptr->ID(this->m_pPlayList, 0);
    *out_uSelectedNodeID = v23;
    return CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v23, AkNodeType_Default);
  }
  v11 = 0;
  v12 = 0;
  v13 = 0i64;
  in_pRandomInfo = 0i64;
  if ( (*((_BYTE *)this + 221) & 7) == 1 )
  {
    result = (CAkParameterNodeBase *)CAkRanSeqCntr::GetExistingSequenceInfo(this, in_pGameObj);
    v13 = result;
    if ( !result )
      return result;
    for ( i = 0i64; ; i = in_pRandomInfo )
    {
LABEL_9:
      out_bIsAnswerValid = 1;
      if ( v11 )
      {
        if ( ++v4 >= v10 )
          v4 = 0;
        CanPlayPosition = CAkRanSeqCntr::CanPlayPosition(this, i, v4);
        if ( !CanPlayPosition )
        {
LABEL_29:
          if ( !v11 )
            return v8;
          goto LABEL_30;
        }
        CAkRanSeqCntr::UpdateNormalAvoidRepeat(this, in_pRandomInfo, v4);
      }
      else
      {
        if ( (*((_BYTE *)this + 221) & 7) == 1 )
        {
          if ( LOBYTE(v13->pNextItem) )
          {
            v17 = SWORD1(v13->pNextItem);
            if ( v17 + 1 == ((unsigned int (__fastcall *)(CAkPlayList *, __int64))this->m_pPlayList->vfptr->Length)(
                              this->m_pPlayList,
                              1i64) )
            {
              if ( (*((_BYTE *)this + 221) & 0x20) != 0 )
              {
                v4 = v17 - 1;
                LOBYTE(v13->pNextItem) = 0;
                WORD1(v13->pNextItem) = v4;
              }
              else
              {
                WORD1(v13->pNextItem) = 0;
                v4 = 0;
              }
            }
            else
            {
              v4 = v17 + 1;
              WORD1(v13->pNextItem) = v4;
            }
          }
          else
          {
            v18 = WORD1(v13->pNextItem);
            if ( v18 )
            {
              v19 = v18 - 1;
              WORD1(v13->pNextItem) = v19;
              v4 = v19;
            }
            else
            {
              WORD1(v13->pNextItem) = 1;
              LOBYTE(v13->pNextItem) = 1;
              v4 = 1;
            }
          }
          goto LABEL_26;
        }
        v20 = CAkRanSeqCntr::SelectRandomly(this, i, &out_bIsAnswerValid, 0i64);
        CanPlayPosition = out_bIsAnswerValid;
        v4 = v20;
      }
      if ( !CanPlayPosition )
        goto LABEL_29;
LABEL_26:
      v21 = this->m_pPlayList->vfptr->ID(this->m_pPlayList, v4);
      *v27 = v21;
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v21, AkNodeType_Default);
      v8 = NodePtrAndAddRef;
      if ( NodePtrAndAddRef )
      {
        if ( (unsigned __int8)NodePtrAndAddRef->vfptr[3].Category(NodePtrAndAddRef) )
        {
          *v26 = v4;
          return v8;
        }
        v8->vfptr->Release(v8);
        v8 = 0i64;
      }
LABEL_30:
      if ( !v12 && (*((_BYTE *)this + 221) & 7) == 0 && (*((_BYTE *)this + 220) & 0x30) != 16 )
        v11 = 1;
      if ( ++v12 >= v10 )
        return v8;
    }
  }
  result = (CAkParameterNodeBase *)CAkRanSeqCntr::GetExistingRandomInfo(this, v9, in_pGameObj);
  i = (CAkRandomInfo *)result;
  in_pRandomInfo = (CAkRandomInfo *)result;
  if ( result )
    goto LABEL_9;
  return result;
}

// File Line: 498
// RVA: 0xA8C090
CAkParameterNodeBase *__fastcall CAkRanSeqCntr::GetNextToPlayContinuous(
        CAkRanSeqCntr *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned __int16 *out_rwPositionSelected,
        unsigned int *out_uSelectedNodeID,
        CAkContainerBaseInfo **io_pContainerInfo,
        AkLoop *io_rLoopInfo)
{
  __int64 v6; // r14
  unsigned int v11; // eax
  unsigned __int16 v12; // r9
  char v13; // cl
  CAkContainerBaseInfo **v14; // rdi
  CAkSequenceInfo *ExistingSequenceInfo; // rbp
  CAkSequenceInfo *v17; // rax
  CAkSequenceInfo *v18; // rsi
  AkLoop *v19; // r9
  unsigned __int16 v20; // ax
  __int64 v21; // rax
  CAkContainerBaseInfo *m_pGlobalContainerInfo; // rcx
  CAkSequenceInfo *v23; // rdi
  unsigned __int16 v24; // bp
  CAkRandomInfo *RandomInfo; // rax
  __int64 v26; // rdx
  unsigned int v27; // eax
  bool out_bIsAnswerValid; // [rsp+50h] [rbp+8h] BYREF

  v6 = 0i64;
  *out_uSelectedNodeID = 0;
  *out_rwPositionSelected = 0;
  v11 = this->m_pPlayList->vfptr->Length(this->m_pPlayList);
  v12 = v11;
  if ( !v11 )
    return (CAkParameterNodeBase *)v6;
  if ( v11 != 1 )
  {
    v13 = *((_BYTE *)this + 221);
    v14 = io_pContainerInfo;
    out_bIsAnswerValid = 1;
    if ( (v13 & 0x10) == 0 && !*io_pContainerInfo && (v13 & 7) == 1 )
    {
      ExistingSequenceInfo = CAkRanSeqCntr::GetExistingSequenceInfo(this, in_pGameObj);
      if ( ExistingSequenceInfo )
      {
        CAkRanSeqCntr::CreateSequenceInfo(this);
        v18 = v17;
        if ( v17 )
        {
          v19 = io_rLoopInfo;
          v17->m_bIsForward = ExistingSequenceInfo->m_bIsForward;
          v17->m_i16LastPositionChosen = ExistingSequenceInfo->m_i16LastPositionChosen;
          v20 = CAkRanSeqCntr::SelectSequentially(this, v17, &out_bIsAnswerValid, v19);
          *v14 = v18;
LABEL_21:
          v24 = v20;
          goto LABEL_22;
        }
      }
      return 0i64;
    }
    if ( (v13 & 7) != 1 )
    {
      RandomInfo = (CAkRandomInfo *)*io_pContainerInfo;
      if ( !*io_pContainerInfo )
      {
        RandomInfo = CAkRanSeqCntr::CreateRandomInfo(this, v12);
        if ( !RandomInfo )
          return 0i64;
        *v14 = RandomInfo;
      }
      v20 = CAkRanSeqCntr::SelectRandomly(this, RandomInfo, &out_bIsAnswerValid, io_rLoopInfo);
      goto LABEL_21;
    }
    if ( !*io_pContainerInfo )
    {
      CAkRanSeqCntr::CreateSequenceInfo(this);
      *v14 = (CAkContainerBaseInfo *)v21;
      if ( !v21 )
        return 0i64;
      m_pGlobalContainerInfo = this->m_pGlobalContainerInfo;
      if ( m_pGlobalContainerInfo )
      {
        *(_WORD *)(v21 + 10) = WORD1(m_pGlobalContainerInfo[1].vfptr);
        WORD1(m_pGlobalContainerInfo[1].vfptr) = -1;
      }
    }
    v23 = (CAkSequenceInfo *)*v14;
    v24 = CAkRanSeqCntr::SelectSequentially(this, v23, &out_bIsAnswerValid, io_rLoopInfo);
    if ( (*((_BYTE *)this + 221) & 0x10) == 0 )
      CAkRanSeqCntr::UpdateResetPlayListSetup(this, v23, in_pGameObj);
LABEL_22:
    if ( out_bIsAnswerValid )
    {
      *out_rwPositionSelected = v24;
      v26 = v24;
LABEL_28:
      v27 = this->m_pPlayList->vfptr->ID(this->m_pPlayList, v26);
      *out_uSelectedNodeID = v27;
      return CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v27, AkNodeType_Default);
    }
    return (CAkParameterNodeBase *)v6;
  }
  if ( io_rLoopInfo->lLoopCount > 0 )
  {
    if ( (*((_BYTE *)io_rLoopInfo + 2) & 2) == 0 )
      --io_rLoopInfo->lLoopCount;
    v26 = 0i64;
    goto LABEL_28;
  }
  return (CAkParameterNodeBase *)v6;
}

// File Line: 606
// RVA: 0xA8B6F0
__int64 __fastcall CAkRanSeqCntr::AddPlaylistItem(
        CAkRanSeqCntr *this,
        unsigned int in_ElementID,
        unsigned int in_weight)
{
  __int64 result; // rax

  if ( in_weight != 50000 )
    *((_BYTE *)this + 221) |= 8u;
  if ( (*((_BYTE *)this + 221) & 7) != 1
    && ((unsigned __int8 (__fastcall *)(CAkPlayList *))this->m_pPlayList->vfptr->Exists)(this->m_pPlayList) )
  {
    return 35i64;
  }
  result = ((__int64 (__fastcall *)(CAkPlayList *, _QWORD, _QWORD))this->m_pPlayList->vfptr->Add)(
             this->m_pPlayList,
             in_ElementID,
             in_weight);
  if ( (_DWORD)result == 1 )
  {
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
    return 1i64;
  }
  return result;
}

// File Line: 697
// RVA: 0xA8B8D0
void __fastcall CAkRanSeqCntr::Continuous(CAkRanSeqCntr *this, const bool in_bIsContinuous)
{
  char v3; // cl

  v3 = *((_BYTE *)this + 221);
  if ( ((v3 & 0x40) != 0) != in_bIsContinuous )
  {
    *((_BYTE *)this + 221) = v3 ^ (v3 ^ (in_bIsContinuous << 6)) & 0x40;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 711
// RVA: 0xA8C510
void __fastcall CAkRanSeqCntr::IsGlobal(CAkRanSeqCntr *this, bool in_bIsGlobal)
{
  unsigned __int8 v3; // cl

  v3 = *((_BYTE *)this + 221);
  if ( v3 >> 7 != in_bIsGlobal )
  {
    *((_BYTE *)this + 221) = (in_bIsGlobal << 7) | v3 & 0x7F;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 725
// RVA: 0xA8C880
void __fastcall CAkRanSeqCntr::ResetPlayListAtEachPlay(CAkRanSeqCntr *this, bool in_bResetPlayListAtEachPlay)
{
  char v3; // cl

  v3 = *((_BYTE *)this + 221);
  if ( ((v3 & 0x10) != 0) != in_bResetPlayListAtEachPlay )
  {
    *((_BYTE *)this + 221) = v3 ^ (v3 ^ (16 * in_bResetPlayListAtEachPlay)) & 0x10;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 734
// RVA: 0xA8D040
__int64 __fastcall CAkRanSeqCntr::TransitionMode(CAkRanSeqCntr *this)
{
  return *((_BYTE *)this + 220) & 0xF;
}

// File Line: 739
// RVA: 0xA8D050
void __fastcall CAkRanSeqCntr::TransitionMode(CAkRanSeqCntr *this, AkTransitionMode in_eTransitionMode)
{
  char v3; // cl

  v3 = *((_BYTE *)this + 220);
  if ( (v3 & 0xF) != in_eTransitionMode )
  {
    *((_BYTE *)this + 220) = v3 ^ (in_eTransitionMode ^ v3) & 0xF;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 748
// RVA: 0xA8D0D0
float __fastcall CAkRanSeqCntr::TransitionTime(CAkRanSeqCntr *this, CAkRegisteredObj *in_GameObj)
{
  float RTPCConvertedValue; // xmm0_4
  float v4; // xmm7_4
  float v5; // xmm8_4
  float v6; // xmm0_4
  float v7; // xmm8_4
  float result; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm0_4

  if ( (this->m_RTPCBitArray.m_iBitArray & 0x20) != 0 )
  {
    RTPCConvertedValue = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 5u, in_GameObj);
    v4 = this->m_TransitionTime.m_mod.m_max - this->m_TransitionTime.m_mod.m_min;
    v5 = RTPCConvertedValue;
    v6 = 0.0;
    v7 = v5 * 1000.0;
    if ( v4 != 0.0 )
      v6 = (double)rand() * 0.00003051850947599719 * v4;
    result = (float)((float)(v6 + this->m_TransitionTime.m_mod.m_min) + this->m_TransitionTime.m_base) + v7;
  }
  else
  {
    v9 = this->m_TransitionTime.m_mod.m_max - this->m_TransitionTime.m_mod.m_min;
    v10 = 0.0;
    if ( v9 != 0.0 )
      v10 = (double)rand() * 0.00003051850947599719 * v9;
    result = (float)(v10 + this->m_TransitionTime.m_mod.m_min) + this->m_TransitionTime.m_base;
  }
  if ( result < 0.0 )
    return 0.0;
  return result;
}

// File Line: 773
// RVA: 0xA8C800
void __fastcall CAkRanSeqCntr::RandomMode(CAkRanSeqCntr *this, AkRandomMode in_eRandomMode)
{
  unsigned int v3; // ecx

  v3 = *((unsigned __int8 *)this + 220);
  if ( ((v3 >> 4) & 3) != in_eRandomMode )
  {
    *((_BYTE *)this + 220) = v3 ^ (v3 ^ (16 * in_eRandomMode)) & 0x30;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 787
// RVA: 0xA8B7D0
void __fastcall CAkRanSeqCntr::AvoidRepeatingCount(CAkRanSeqCntr *this, unsigned __int16 in_wCount)
{
  if ( this->m_wAvoidRepeatCount != in_wCount )
  {
    this->m_wAvoidRepeatCount = in_wCount;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( (*((_BYTE *)this + 222) & 1) != 0 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
      }
      CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 801
// RVA: 0xA8C590
__int64 __fastcall CAkRanSeqCntr::Mode(CAkRanSeqCntr *this, AkContainerMode in_eMode)
{
  char v3; // cl
  char v4; // al
  CAkPlayList *m_pPlayList; // rcx
  CAkPlayListSequence *v6; // rax
  CAkPlayList *v7; // rax
  CAkPlayListRandom *v8; // rax
  unsigned int v9; // edi

  v3 = *((_BYTE *)this + 221);
  if ( in_eMode == (v3 & 7) )
    return 1i64;
  v4 = v3 ^ (in_eMode ^ v3) & 7;
  m_pPlayList = this->m_pPlayList;
  *((_BYTE *)this + 221) = v4;
  if ( m_pPlayList )
    m_pPlayList->vfptr->Destroy(m_pPlayList);
  if ( (*((_BYTE *)this + 221) & 7) != 1 )
  {
    v8 = (CAkPlayListRandom *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
    if ( v8 )
    {
      CAkPlayListRandom::CAkPlayListRandom(v8);
      goto LABEL_10;
    }
LABEL_9:
    v7 = 0i64;
    goto LABEL_10;
  }
  v6 = (CAkPlayListSequence *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
  if ( !v6 )
    goto LABEL_9;
  CAkPlayListSequence::CAkPlayListSequence(v6);
LABEL_10:
  this->m_pPlayList = v7;
  if ( v7 )
  {
    v9 = (*(__int64 (__fastcall **)(CAkPlayList *))v7->vfptr->gap8)(v7);
    if ( v9 != 1 )
    {
      this->m_pPlayList->vfptr->Destroy(this->m_pPlayList);
      this->m_pPlayList = 0i64;
    }
  }
  else
  {
    v9 = 2;
  }
  CAkRanSeqCntr::DestroySpecificInfo(this);
  if ( (*((_BYTE *)this + 222) & 1) != 0 )
  {
    if ( g_pAudioMgr )
    {
      CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, this);
      CAkAudioMgr::RemovePendingAction(g_pAudioMgr, this);
    }
    CAkParameterNodeBase::Stop(this, 0i64, 0, 0, AkCurveInterpolation_Linear);
  }
  return v9;
}

// File Line: 882
// RVA: 0xA8BB80
void __fastcall CAkRanSeqCntr::DestroySpecificInfo(CAkRanSeqCntr *this)
{
  CAkRanSeqCntr::CntrInfoEntry *m_pItems; // rbx
  CAkContainerBaseInfo *m_pGlobalContainerInfo; // rcx

  m_pItems = this->m_mapObjectCntrInfo.m_pItems;
  if ( m_pItems != &m_pItems[this->m_mapObjectCntrInfo.m_uLength] )
  {
    do
    {
      m_pItems->pInfo->vfptr->Destroy(m_pItems->pInfo);
      ++m_pItems;
    }
    while ( m_pItems != &this->m_mapObjectCntrInfo.m_pItems[this->m_mapObjectCntrInfo.m_uLength] );
  }
  this->m_mapObjectCntrInfo.m_uLength = 0;
  m_pGlobalContainerInfo = this->m_pGlobalContainerInfo;
  if ( m_pGlobalContainerInfo )
  {
    m_pGlobalContainerInfo->vfptr->Destroy(m_pGlobalContainerInfo);
    this->m_pGlobalContainerInfo = 0i64;
  }
}

// File Line: 896
// RVA: 0xA8C270
__int64 __fastcall CAkRanSeqCntr::GetPlaylistLength(CAkRanSeqCntr *this)
{
  CAkPlayList *m_pPlayList; // rcx

  m_pPlayList = this->m_pPlayList;
  if ( m_pPlayList )
    return ((__int64 (__fastcall *)(CAkPlayList *))m_pPlayList->vfptr->Length)(m_pPlayList);
  else
    return 0i64;
}

// File Line: 911
// RVA: 0xA8CC10
__int64 __fastcall CAkRanSeqCntr::SelectSequentially(
        CAkRanSeqCntr *this,
        CAkSequenceInfo *in_pSeqInfo,
        bool *out_bIsAnswerValid,
        AkLoop *io_pLoopCount)
{
  int m_i16LastPositionChosen; // esi
  char v9; // al
  bool v10; // zf
  __int16 v12; // ax
  char v13; // al

  *out_bIsAnswerValid = 1;
  if ( in_pSeqInfo->m_bIsForward )
  {
    m_i16LastPositionChosen = in_pSeqInfo->m_i16LastPositionChosen;
    if ( m_i16LastPositionChosen + 1 == this->m_pPlayList->vfptr->Length(this->m_pPlayList) )
    {
      if ( (*((_BYTE *)this + 221) & 0x20) != 0 )
      {
        in_pSeqInfo->m_bIsForward = 0;
        in_pSeqInfo->m_i16LastPositionChosen = m_i16LastPositionChosen - 1;
      }
      else
      {
        in_pSeqInfo->m_i16LastPositionChosen = 0;
        if ( io_pLoopCount )
        {
          v9 = *((_BYTE *)io_pLoopCount + 2);
          if ( (v9 & 1) == 0
            || (v9 & 2) == 0 && (v10 = io_pLoopCount->lLoopCount == 1, --io_pLoopCount->lLoopCount, v10) )
          {
            *out_bIsAnswerValid = 0;
            return 0i64;
          }
        }
      }
    }
    else
    {
      in_pSeqInfo->m_i16LastPositionChosen = m_i16LastPositionChosen + 1;
    }
  }
  else
  {
    v12 = in_pSeqInfo->m_i16LastPositionChosen;
    if ( v12 )
    {
      in_pSeqInfo->m_i16LastPositionChosen = v12 - 1;
    }
    else
    {
      in_pSeqInfo->m_i16LastPositionChosen = 1;
      in_pSeqInfo->m_bIsForward = 1;
      if ( io_pLoopCount )
      {
        v13 = *((_BYTE *)io_pLoopCount + 2);
        if ( (v13 & 1) == 0
          || (v13 & 2) == 0 && (v10 = io_pLoopCount->lLoopCount == 1, --io_pLoopCount->lLoopCount, v10) )
        {
          *out_bIsAnswerValid = 0;
          return 0i64;
        }
      }
    }
  }
  return (unsigned __int16)in_pSeqInfo->m_i16LastPositionChosen;
}

// File Line: 959
// RVA: 0xA8D230
__int64 __fastcall CAkRanSeqCntr::UpdateNormalAvoidRepeat(
        CAkRanSeqCntr *this,
        CAkRandomInfo *in_pRandomInfo,
        unsigned __int16 in_uPosition)
{
  CAkPlayList *m_pPlayList; // r14
  AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *p_m_listAvoid; // rbx
  unsigned __int16 *v8; // rax
  unsigned __int16 m_wAvoidRepeatCount; // ax
  unsigned __int16 v10; // di
  unsigned int v11; // eax
  unsigned __int16 *m_pItems; // rdi
  unsigned __int64 v13; // rcx
  unsigned __int16 *v14; // rsi
  unsigned __int64 i; // rcx

  m_pPlayList = this->m_pPlayList;
  if ( !this->m_wAvoidRepeatCount )
    return 1i64;
  p_m_listAvoid = &in_pRandomInfo->m_listAvoid;
  --in_pRandomInfo->m_wRemainingItemsToPlay;
  v8 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRandomInfo->m_listAvoid);
  if ( v8 )
  {
    *v8 = in_uPosition;
    CAkRandomInfo::FlagAsBlocked(in_pRandomInfo, in_uPosition);
    in_pRandomInfo->m_ulRemainingWeight -= m_pPlayList->vfptr->GetWeight(m_pPlayList, in_uPosition);
    m_wAvoidRepeatCount = ((__int64 (__fastcall *)(CAkPlayList *))this->m_pPlayList->vfptr->Length)(this->m_pPlayList)
                        - 1;
    if ( this->m_wAvoidRepeatCount < m_wAvoidRepeatCount )
      m_wAvoidRepeatCount = this->m_wAvoidRepeatCount;
    if ( in_pRandomInfo->m_listAvoid.m_uLength > m_wAvoidRepeatCount )
    {
      v10 = *p_m_listAvoid->m_pItems;
      CAkRandomInfo::FlagAsUnBlocked(in_pRandomInfo, v10);
      v11 = m_pPlayList->vfptr->GetWeight(m_pPlayList, v10);
      ++in_pRandomInfo->m_wRemainingItemsToPlay;
      in_pRandomInfo->m_ulRemainingWeight += v11;
      m_pItems = p_m_listAvoid->m_pItems;
      v13 = (unsigned __int64)&p_m_listAvoid->m_pItems[p_m_listAvoid->m_uLength - 1];
      if ( p_m_listAvoid->m_pItems < (unsigned __int16 *)v13 )
      {
        v14 = m_pItems + 1;
        for ( i = ((v13 - (unsigned __int64)m_pItems - 1) >> 1) + 1; i; --i )
          *m_pItems++ = *v14++;
      }
      --p_m_listAvoid->m_uLength;
    }
    return 1i64;
  }
  in_pRandomInfo->m_wCounter = 0;
  return 2i64;
}

// File Line: 990
// RVA: 0xA8C900
__int64 __fastcall CAkRanSeqCntr::SelectRandomly(
        CAkRanSeqCntr *this,
        CAkRandomInfo *in_pRandomInfo,
        bool *out_bIsAnswerValid,
        AkLoop *io_pLoopCount)
{
  CAkPlayList *m_pPlayList; // r15
  unsigned __int16 v5; // bp
  int v6; // r14d
  char v9; // al
  bool v10; // zf
  unsigned int v12; // eax
  unsigned __int16 *m_pItems; // rdi
  unsigned int v14; // eax
  int RandomValue; // edi
  int v16; // edi
  unsigned __int16 v17; // bp
  unsigned __int16 m_wAvoidRepeatCount; // di
  unsigned __int16 *v19; // rax
  unsigned __int16 v20; // ax
  unsigned __int16 *v21; // rdi
  unsigned __int16 v22; // r12
  unsigned __int16 *v23; // rsi
  unsigned __int64 i; // rcx

  *out_bIsAnswerValid = 1;
  m_pPlayList = this->m_pPlayList;
  v5 = 0;
  v6 = -1;
  if ( !in_pRandomInfo->m_wCounter )
  {
    if ( io_pLoopCount )
    {
      v9 = *((_BYTE *)io_pLoopCount + 2);
      if ( (v9 & 1) == 0 || (v9 & 2) == 0 && (v10 = io_pLoopCount->lLoopCount == 1, --io_pLoopCount->lLoopCount, v10) )
      {
        *out_bIsAnswerValid = 0;
        return 0i64;
      }
    }
    in_pRandomInfo->m_wCounter = this->m_pPlayList->vfptr->Length(this->m_pPlayList);
    v12 = this->m_pPlayList->vfptr->Length(this->m_pPlayList);
    CAkRandomInfo::ResetFlagsPlayed(in_pRandomInfo, v12);
    if ( (*((_BYTE *)this + 220) & 0x30) == 16 )
    {
      m_pItems = in_pRandomInfo->m_listAvoid.m_pItems;
      in_pRandomInfo->m_ulRemainingWeight = in_pRandomInfo->m_ulTotalWeight;
      if ( m_pItems != &m_pItems[in_pRandomInfo->m_listAvoid.m_uLength] )
      {
        do
        {
          v14 = m_pPlayList->vfptr->GetWeight(m_pPlayList, *m_pItems++);
          in_pRandomInfo->m_ulRemainingWeight -= v14;
        }
        while ( m_pItems != &in_pRandomInfo->m_listAvoid.m_pItems[in_pRandomInfo->m_listAvoid.m_uLength] );
      }
    }
    in_pRandomInfo->m_wRemainingItemsToPlay -= LOWORD(in_pRandomInfo->m_listAvoid.m_uLength);
  }
  if ( (*((_BYTE *)this + 221) & 8) == 0 )
  {
    v16 = (unsigned __int16)(rand() % in_pRandomInfo->m_wRemainingItemsToPlay);
    while ( 1 )
    {
      if ( (*((_BYTE *)this + 220) & 0x30) != 0 )
      {
        if ( CAkRandomInfo::IsFlagSetPlayed(in_pRandomInfo, v5) || CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, v5) )
          goto LABEL_30;
      }
      else if ( this->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, v5) )
      {
        goto LABEL_30;
      }
      ++v6;
LABEL_30:
      ++v5;
      if ( v6 >= v16 )
        goto LABEL_31;
    }
  }
  RandomValue = CAkRandomInfo::GetRandomValue(in_pRandomInfo);
  if ( RandomValue > -1 )
  {
    do
    {
      if ( (*((_BYTE *)this + 220) & 0x30) != 0 )
      {
        if ( CAkRandomInfo::IsFlagSetPlayed(in_pRandomInfo, v5) || CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, v5) )
          goto LABEL_20;
      }
      else if ( this->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, v5) )
      {
        goto LABEL_20;
      }
      v6 += m_pPlayList->vfptr->GetWeight(m_pPlayList, v5);
LABEL_20:
      ++v5;
    }
    while ( v6 < RandomValue );
  }
LABEL_31:
  v17 = v5 - 1;
  if ( (*((_BYTE *)this + 220) & 0x30) != 0 )
  {
    m_wAvoidRepeatCount = this->m_wAvoidRepeatCount;
    if ( !m_wAvoidRepeatCount )
      m_wAvoidRepeatCount = 1;
    in_pRandomInfo->m_ulRemainingWeight -= m_pPlayList->vfptr->GetWeight(m_pPlayList, v17);
    --in_pRandomInfo->m_wRemainingItemsToPlay;
    --in_pRandomInfo->m_wCounter;
    CAkRandomInfo::FlagSetPlayed(in_pRandomInfo, v17);
    v19 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRandomInfo->m_listAvoid);
    if ( v19 )
    {
      *v19 = v17;
      CAkRandomInfo::FlagAsBlocked(in_pRandomInfo, v17);
      v20 = ((__int64 (__fastcall *)(CAkPlayList *))this->m_pPlayList->vfptr->Length)(this->m_pPlayList) - 1;
      if ( m_wAvoidRepeatCount < v20 )
        v20 = m_wAvoidRepeatCount;
      if ( in_pRandomInfo->m_listAvoid.m_uLength > v20 )
      {
        v21 = in_pRandomInfo->m_listAvoid.m_pItems;
        v22 = *v21;
        if ( v21 < &v21[in_pRandomInfo->m_listAvoid.m_uLength - 1] )
        {
          v23 = v21 + 1;
          for ( i = ((2 * ((unsigned __int64)in_pRandomInfo->m_listAvoid.m_uLength - 1) - 1) >> 1) + 1; i; --i )
            *v21++ = *v23++;
        }
        --in_pRandomInfo->m_listAvoid.m_uLength;
        CAkRandomInfo::FlagAsUnBlocked(in_pRandomInfo, v22);
        if ( !CAkRandomInfo::IsFlagSetPlayed(in_pRandomInfo, v22) )
        {
          in_pRandomInfo->m_ulRemainingWeight += m_pPlayList->vfptr->GetWeight(m_pPlayList, v22);
          ++in_pRandomInfo->m_wRemainingItemsToPlay;
        }
      }
    }
    else
    {
      in_pRandomInfo->m_wCounter = 0;
    }
  }
  else
  {
    if ( !CAkRandomInfo::IsFlagSetPlayed(in_pRandomInfo, v17) )
    {
      CAkRandomInfo::FlagSetPlayed(in_pRandomInfo, v17);
      --in_pRandomInfo->m_wCounter;
    }
    CAkRanSeqCntr::UpdateNormalAvoidRepeat(this, in_pRandomInfo, v17);
  }
  return v17;
}

// File Line: 1117
// RVA: 0xA8B840
bool __fastcall CAkRanSeqCntr::CanPlayPosition(
        CAkRanSeqCntr *this,
        CAkRandomInfo *in_pRandomInfo,
        unsigned __int16 in_wPosition)
{
  if ( (*((_BYTE *)this + 220) & 0x30) != 0 )
    return !CAkRandomInfo::IsFlagSetPlayed(in_pRandomInfo, in_wPosition)
        && !CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, in_wPosition);
  return !this->m_wAvoidRepeatCount || !CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, in_wPosition);
}

// File Line: 1137
// RVA: 0xA8C6C0
AKRESULT __fastcall CAkRanSeqCntr::PlayInternal(CAkRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  CAkContinuationList *v4; // rax
  CAkContinuationList *v5; // rcx
  AKRESULT v7; // ebx
  ContParams *pContinuousParams; // rax
  CAkContinuationList *v9; // rax
  ContParams *v10; // rdx
  CAkContinuationList *m_pT; // rcx
  __int64 v12; // [rsp+20h] [rbp-48h] BYREF
  int v13; // [rsp+28h] [rbp-40h]
  _QWORD v14[3]; // [rsp+30h] [rbp-38h] BYREF
  __int16 v15; // [rsp+48h] [rbp-20h]
  CAkContinuationList *v16; // [rsp+50h] [rbp-18h]
  int v17; // [rsp+58h] [rbp-10h]

  *((_BYTE *)this + 222) |= 1u;
  if ( (*((_BYTE *)this + 221) & 0x40) == 0 )
    return CAkRanSeqCntr::_Play(this, in_rPBIParams);
  if ( in_rPBIParams->eType )
  {
    pContinuousParams = in_rPBIParams->pContinuousParams;
    if ( !pContinuousParams || pContinuousParams->spContList.m_pT )
      return CAkRanSeqCntr::_PlayContinuous(this, in_rPBIParams);
    v9 = CAkContinuationList::Create();
    v10 = in_rPBIParams->pContinuousParams;
    m_pT = v10->spContList.m_pT;
    v10->spContList.m_pT = v9;
    if ( m_pT )
      CAkContinuationList::Release(m_pT);
    if ( in_rPBIParams->pContinuousParams->spContList.m_pT )
      return CAkRanSeqCntr::_PlayContinuous(this, in_rPBIParams);
    else
      return 2;
  }
  else
  {
    in_rPBIParams->pInstigator = this;
    v14[2] = &v12;
    v14[0] = 0i64;
    v14[1] = 0i64;
    v15 = 0;
    v12 = 0i64;
    v16 = 0i64;
    v17 = 0;
    in_rPBIParams->eType = ContinuousPBI;
    v13 = 0;
    v4 = CAkContinuationList::Create();
    v5 = v16;
    v16 = v4;
    if ( v5 )
    {
      CAkContinuationList::Release(v5);
      v4 = v16;
    }
    if ( v4 )
    {
      in_rPBIParams->pContinuousParams = (ContParams *)v14;
      v7 = CAkRanSeqCntr::_PlayContinuous(this, in_rPBIParams);
      if ( v16 )
        CAkContinuationList::Release(v16);
      return v7;
    }
    else
    {
      return 2;
    }
  }
}

// File Line: 1184
// RVA: 0xA8D400
__int64 __fastcall CAkRanSeqCntr::_Play(CAkRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  CAkParameterNode *NextToPlay; // rbx
  unsigned int uiArraySize; // ecx
  unsigned int v6; // esi
  unsigned __int16 v7; // ax
  unsigned int v8; // eax
  __int64 result; // rax
  unsigned __int16 out_rwPositionSelected; // [rsp+38h] [rbp+10h] BYREF
  unsigned int out_uSelectedNodeID; // [rsp+40h] [rbp+18h] BYREF

  NextToPlay = (CAkParameterNode *)CAkRanSeqCntr::GetNextToPlay(
                                     this,
                                     in_rPBIParams->pGameObj,
                                     &out_rwPositionSelected,
                                     &out_uSelectedNodeID);
  if ( NextToPlay )
  {
    uiArraySize = in_rPBIParams->playHistory.HistArray.uiArraySize;
    v6 = 1;
    if ( uiArraySize >= 0x20 )
    {
      in_rPBIParams->playHistory.HistArray.uiArraySize = uiArraySize + 1;
    }
    else
    {
      v7 = out_rwPositionSelected;
      in_rPBIParams->playHistory.arrayIsContinuous.m_iBitArray &= ~(1 << uiArraySize);
      in_rPBIParams->playHistory.HistArray.aCntrHist[in_rPBIParams->playHistory.HistArray.uiArraySize++] = v7;
    }
    v8 = CAkParameterNode::HandleInitialDelay(NextToPlay, in_rPBIParams);
    if ( v8 != 3 )
    {
      if ( v8 == 1 )
        v8 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))NextToPlay->vfptr[19].Category)(
               NextToPlay,
               in_rPBIParams);
      v6 = v8;
    }
    NextToPlay->vfptr->Release(NextToPlay);
    return v6;
  }
  else if ( in_rPBIParams->eType )
  {
    result = ((__int64 (__fastcall *)(CAkRanSeqCntr *, AkPBIParams *))this->vfptr[20].AddRef)(this, in_rPBIParams);
    if ( (_DWORD)result == 3 )
      return 1i64;
  }
  else
  {
    return 2i64;
  }
  return result;
}

// File Line: 1220
// RVA: 0xA8D4F0
__int64 __fastcall CAkRanSeqCntr::_PlayContinuous(CAkRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  unsigned int v4; // edi
  RANGED_PARAMETER<short> *v5; // rdx
  CAkContinueListItem *v6; // rbx
  CAkRanSeqCntr *m_pT; // rcx
  char v8; // cl
  AkLoop *io_rLoopInfo; // rcx
  __int16 Mod; // ax
  CAkParameterNode *NextToPlayContinuous; // rbx
  unsigned int uiArraySize; // ecx
  unsigned __int16 v13; // ax
  unsigned int v14; // eax
  __int64 result; // rax
  CAkContinuationList *v16; // rbx
  unsigned __int16 out_rwPositionSelected; // [rsp+58h] [rbp+10h] BYREF
  unsigned int out_uSelectedNodeID; // [rsp+60h] [rbp+18h] BYREF

  v4 = 1;
  v6 = AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&in_rPBIParams->pContinuousParams->spContList.m_pT->m_listItems);
  if ( v6 )
  {
    if ( this )
      this->vfptr->AddRef(this);
    m_pT = v6->m_pContainer.m_pT;
    v6->m_pContainer.m_pT = this;
    if ( m_pT )
      m_pT->vfptr->Release(m_pT);
    *((_BYTE *)&v6->m_LoopingInfo + 2) ^= (*((_BYTE *)&v6->m_LoopingInfo + 2) ^ (this->m_LoopRanged.m_base != 1)) & 1;
    v8 = *((_BYTE *)&v6->m_LoopingInfo + 2) ^ (*((_BYTE *)&v6->m_LoopingInfo + 2) ^ (2 * (this->m_LoopRanged.m_base == 0))) & 2;
    *((_BYTE *)&v6->m_LoopingInfo + 2) = v8;
    if ( (v8 & 1) != 0 )
    {
      if ( (v8 & 2) != 0 )
      {
        io_rLoopInfo = &v6->m_LoopingInfo;
        v6->m_LoopingInfo.lLoopCount = 1;
      }
      else
      {
        Mod = RandomizerModifier::GetModValue<short>((RandomizerModifier *)&this->m_LoopRanged, v5);
        if ( Mod < 1 )
          Mod = 1;
        io_rLoopInfo = &v6->m_LoopingInfo;
        v6->m_LoopingInfo.lLoopCount = Mod;
      }
    }
    else
    {
      io_rLoopInfo = &v6->m_LoopingInfo;
      v6->m_LoopingInfo.lLoopCount = 1;
    }
    NextToPlayContinuous = (CAkParameterNode *)CAkRanSeqCntr::GetNextToPlayContinuous(
                                                 v6->m_pContainer.m_pT,
                                                 in_rPBIParams->pGameObj,
                                                 &out_rwPositionSelected,
                                                 &out_uSelectedNodeID,
                                                 &v6->m_pContainerInfo,
                                                 io_rLoopInfo);
    if ( NextToPlayContinuous )
    {
      uiArraySize = in_rPBIParams->playHistory.HistArray.uiArraySize;
      if ( uiArraySize >= 0x20 )
      {
        in_rPBIParams->playHistory.HistArray.uiArraySize = uiArraySize + 1;
      }
      else
      {
        v13 = out_rwPositionSelected;
        in_rPBIParams->playHistory.arrayIsContinuous.m_iBitArray |= 1i64 << uiArraySize;
        in_rPBIParams->playHistory.HistArray.aCntrHist[in_rPBIParams->playHistory.HistArray.uiArraySize++] = v13;
      }
      v14 = CAkParameterNode::HandleInitialDelay(NextToPlayContinuous, in_rPBIParams);
      if ( v14 != 3 )
      {
        if ( v14 == 1 )
          v14 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))NextToPlayContinuous->vfptr[19].Category)(
                  NextToPlayContinuous,
                  in_rPBIParams);
        v4 = v14;
      }
      NextToPlayContinuous->vfptr->Release(NextToPlayContinuous);
      return v4;
    }
    v16 = in_rPBIParams->pContinuousParams->spContList.m_pT;
    CAkContinueListItem::~CAkContinueListItem(&v16->m_listItems.m_pItems[v16->m_listItems.m_uLength - 1]);
    --v16->m_listItems.m_uLength;
  }
  result = ((__int64 (__fastcall *)(CAkRanSeqCntr *, AkPBIParams *))this->vfptr[20].AddRef)(this, in_rPBIParams);
  if ( (_DWORD)result == 3 )
    return 1i64;
  return result;
}

// File Line: 1296
// RVA: 0xA8B9C0
void __fastcall CAkRanSeqCntr::CreatePBI(
        CAkRanSeqCntr *this,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        AkPBIParams *in_rPBIParams,
        PriorityInfoCurrent *in_rPriority,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  CAkContinuousPBI *v10; // r10

  if ( in_rPBIParams->eType == ContinuousPBI )
  {
    v10 = (CAkContinuousPBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x280ui64);
    if ( v10 )
      CAkContinuousPBI::CAkContinuousPBI(
        v10,
        in_pSound,
        in_pSource,
        in_rPBIParams->pGameObj,
        in_rPBIParams->pContinuousParams,
        &in_rPBIParams->userParams,
        &in_rPBIParams->playHistory,
        in_rPBIParams->bIsFirst,
        in_rPBIParams->sequenceID,
        in_rPBIParams->pInstigator,
        in_rPriority,
        in_rPBIParams->bTargetFeedback,
        in_pAMLimiter,
        in_pBusLimiter);
  }
  else
  {
    CAkPBIAware::CreatePBI(this, in_pSound, in_pSource, in_rPBIParams, in_rPriority, in_pAMLimiter, in_pBusLimiter);
  }
}

// File Line: 1335
// RVA: 0xA8D350
void __fastcall CAkRanSeqCntr::UpdateResetPlayListSetup(
        CAkRanSeqCntr *this,
        CAkSequenceInfo *in_pSeqInfo,
        CAkRegisteredObj *in_pGameObj)
{
  CAkContainerBaseInfo *m_pGlobalContainerInfo; // rbx
  char m_bIsForward; // al
  bool v7; // zf
  __int16 m_i16LastPositionChosen; // ax
  __int16 v9; // ax
  __int16 v10; // si

  if ( *((char *)this + 221) >= 0 )
    m_pGlobalContainerInfo = *(CAkContainerBaseInfo **)&AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                                                          (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
                                                          in_pGameObj)->fValue;
  else
    m_pGlobalContainerInfo = this->m_pGlobalContainerInfo;
  m_bIsForward = in_pSeqInfo->m_bIsForward;
  LOBYTE(m_pGlobalContainerInfo[1].vfptr) = m_bIsForward;
  v7 = m_bIsForward == 0;
  m_i16LastPositionChosen = in_pSeqInfo->m_i16LastPositionChosen;
  if ( v7 )
    v9 = m_i16LastPositionChosen + 1;
  else
    v9 = m_i16LastPositionChosen - 1;
  WORD1(m_pGlobalContainerInfo[1].vfptr) = v9;
  v10 = v9;
  if ( v9 + 1 != ((unsigned int (__fastcall *)(CAkPlayList *, CAkSequenceInfo *, CAkRegisteredObj *))this->m_pPlayList->vfptr->Length)(
                   this->m_pPlayList,
                   in_pSeqInfo,
                   in_pGameObj)
    || (*((_BYTE *)this + 221) & 0x20) != 0 )
  {
    if ( !v10 && !LOBYTE(m_pGlobalContainerInfo[1].vfptr) )
      LOBYTE(m_pGlobalContainerInfo[1].vfptr) = 1;
  }
  else
  {
    WORD1(m_pGlobalContainerInfo[1].vfptr) = -1;
  }
}

