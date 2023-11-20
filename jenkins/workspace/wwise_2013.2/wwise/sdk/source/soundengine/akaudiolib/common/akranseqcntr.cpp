// File Line: 42
// RVA: 0xA8B4F0
void __fastcall CAkRanSeqCntr::CAkRanSeqCntr(CAkRanSeqCntr *this, unsigned int in_ulID, AkContainerMode in_ContainerMode)
{
  char v3; // bl
  CAkRanSeqCntr *v4; // rdi

  v3 = in_ContainerMode;
  v4 = this;
  CAkContainerBase::CAkContainerBase((CAkContainerBase *)&this->vfptr, in_ulID);
  v4->vfptr = (CAkIndexableVtbl *)&CAkRanSeqCntr::`vftable';
  v4->m_pPlayList = 0i64;
  v4->m_mapObjectCntrInfo.m_pItems = 0i64;
  *(_QWORD *)&v4->m_mapObjectCntrInfo.m_uLength = 0i64;
  v4->m_pGlobalContainerInfo = 0i64;
  *(_QWORD *)&v4->m_TransitionTime.m_base = 0i64;
  *(_QWORD *)&v4->m_TransitionTime.m_mod.m_max = 0i64;
  *(_DWORD *)&v4->m_LoopRanged.m_mod.m_max = 0;
  *((_BYTE *)v4 + 222) &= 0xFEu;
  *((_BYTE *)v4 + 220) &= 0xC0u;
  v4->m_LoopRanged.m_base = 1;
  *((_BYTE *)v4 + 221) = v3 & 7 | 0x90;
}

// File Line: 98
// RVA: 0xA8CD10
__int64 __fastcall CAkRanSeqCntr::SetInitialValues(CAkRanSeqCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkRanSeqCntr *v3; // rdi
  __int64 result; // rax
  __int16 v5; // ax
  char *v6; // rdx
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
  unsigned int v27; // er8
  unsigned int v28; // eax
  char v29; // [rsp+20h] [rbp-19h]
  char *io_rpData; // [rsp+A8h] [rbp+6Fh]
  unsigned int io_rulDataSize; // [rsp+B0h] [rbp+77h]
  char v32; // [rsp+B8h] [rbp+7Fh]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  v3 = this;
  result = CAkParameterNodeBase::SetNodeBaseParams((CAkParameterNodeBase *)&this->vfptr, &io_rpData, &io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
  {
    v5 = *(_WORD *)io_rpData;
    v6 = io_rpData + 2;
    io_rpData = v6;
    v7 = *(_WORD *)v6;
    v6 += 2;
    io_rpData = v6;
    v8 = *(_WORD *)v6;
    v9 = v6 + 2;
    v10 = 0;
    io_rpData = v9;
    if ( v5 )
    {
      v3->m_LoopRanged.m_base = v5;
      v3->m_LoopRanged.m_mod.m_min = v7;
      v3->m_LoopRanged.m_mod.m_max = v8;
    }
    else
    {
      *(_DWORD *)&v3->m_LoopRanged.m_base = 0;
      v3->m_LoopRanged.m_mod.m_max = 0;
    }
    v11 = *(float *)v9;
    io_rpData = v9 + 4;
    v12 = *((float *)v9 + 1);
    v13 = v9 + 8;
    io_rpData = v13;
    v13 += 4;
    v14 = *((float *)v13 - 1);
    io_rpData = v13;
    v15 = *(_WORD *)v13;
    v13 += 2;
    io_rpData = v13++;
    v16 = *(v13 - 1);
    io_rpData = v13;
    v17 = *v13++;
    io_rpData = v13;
    v13 += 2;
    v18 = (unsigned __int8)*(v13 - 2);
    io_rpData = v13;
    v19 = *v13++;
    io_rpData = v13++;
    v20 = *(v13 - 1);
    io_rpData = v13;
    v32 = *v13;
    io_rpData = v13 + 1;
    v21 = v13[1];
    io_rpData = v13 + 2;
    v29 = v21;
    result = CAkRanSeqCntr::Mode(v3, v18);
    if ( (_DWORD)result == 1 )
    {
      v3->m_TransitionTime.m_base = v11;
      v3->m_TransitionTime.m_mod.m_min = v12;
      v3->m_TransitionTime.m_mod.m_max = v14;
      CAkRanSeqCntr::AvoidRepeatingCount(v3, v15);
      CAkRanSeqCntr::TransitionMode(v3, (AkTransitionMode)v16);
      CAkRanSeqCntr::RandomMode(v3, (AkRandomMode)v17);
      CAkRanSeqCntr::ResetPlayListAtEachPlay(v3, v19 != 0);
      *((_BYTE *)v3 + 221) &= 0xDFu;
      *((_BYTE *)v3 + 221) |= 32 * (v20 != 0);
      CAkRanSeqCntr::Continuous(v3, v32 != 0);
      CAkRanSeqCntr::IsGlobal(v3, v29 != 0);
      result = CAkParentNode<CAkParameterNode>::SetChildren(
                 (CAkParentNode<CAkParameterNode> *)&v3->vfptr,
                 &io_rpData,
                 &io_rulDataSize);
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
            v28 = CAkRanSeqCntr::AddPlaylistItem(v3, v26, v27);
            v22 = v28;
            if ( v28 == 15 )
            {
              v22 = 1;
            }
            else if ( v28 != 1 )
            {
              break;
            }
            if ( ++v10 >= v25 )
              break;
            v24 = io_rpData;
          }
        }
        result = v22;
      }
    }
  }
  return result;
}

// File Line: 171
// RVA: 0xA8C360
__int64 __fastcall CAkRanSeqCntr::Init(CAkRanSeqCntr *this)
{
  CAkRanSeqCntr *v1; // rbx
  unsigned int v2; // eax
  signed int v3; // ecx
  bool v4; // al
  CAkPlayListSequence *v5; // rax
  CAkPlayList *v6; // rax
  CAkPlayListRandom *v7; // rax
  __int64 result; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[3].Release)();
  v4 = 0;
  if ( v2 <= 0xC )
  {
    v3 = 5121;
    if ( _bittest(&v3, v2) )
      v4 = 1;
  }
  *((_BYTE *)&v1->0 + 83) &= 0xFDu;
  *((_BYTE *)&v1->0 + 83) |= 2 * v4;
  CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)&v1->vfptr);
  if ( (*((_BYTE *)v1 + 221) & 7) == 1 )
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
  v1->m_pPlayList = v6;
  if ( v6 )
    result = (*(__int64 (__fastcall **)(CAkPlayList *))v6->vfptr->gap8)(v6);
  else
    result = 2i64;
  return result;
}

// File Line: 199
// RVA: 0xA8CFB0
void __fastcall CAkRanSeqCntr::Term(CAkRanSeqCntr *this)
{
  CAkRanSeqCntr *v1; // rbx
  CAkPlayList *v2; // rcx
  CAkRanSeqCntr::CntrInfoEntry *v3; // rdx

  v1 = this;
  v2 = this->m_pPlayList;
  if ( v2 )
  {
    if ( ((unsigned int (*)(void))v2->vfptr->Length)() )
    {
      ((void (*)(void))v1->m_pPlayList->vfptr->RemoveAll)();
      *((_BYTE *)v1 + 221) &= 0xF7u;
      CAkRanSeqCntr::DestroySpecificInfo(v1);
    }
    ((void (*)(void))v1->m_pPlayList->vfptr->Destroy)();
  }
  v3 = v1->m_mapObjectCntrInfo.m_pItems;
  if ( v3 )
  {
    v1->m_mapObjectCntrInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v1->m_mapObjectCntrInfo.m_pItems = 0i64;
    v1->m_mapObjectCntrInfo.m_ulReserved = 0;
  }
}

// File Line: 217
// RVA: 0xA8B950
void __fastcall CAkRanSeqCntr::Create(unsigned int in_ulID, AkContainerMode in_ContainerMode)
{
  unsigned int v2; // edi
  AkContainerMode v3; // ebx
  CAkRanSeqCntr *v4; // rax
  CAkRanSeqCntr *v5; // rax
  CAkRanSeqCntr *v6; // rbx

  v2 = in_ulID;
  v3 = in_ContainerMode;
  v4 = (CAkRanSeqCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xE0ui64);
  if ( v4 )
  {
    CAkRanSeqCntr::CAkRanSeqCntr(v4, v2, v3);
    v6 = v5;
    if ( v5 )
    {
      if ( CAkRanSeqCntr::Init(v5) != 1 )
        v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
    }
  }
}

// File Line: 239
// RVA: 0xA8D1E0
void __fastcall CAkRanSeqCntr::Unregister(CAkRanSeqCntr *this, CAkRegisteredObj *in_pGameObj)
{
  CAkRegisteredObj *v2; // rdi
  CAkRanSeqCntr *v3; // rbx
  CAkRTPCMgr::AkRTPCValue *v4; // rax

  v2 = in_pGameObj;
  v3 = this;
  CAkParameterNode::Unregister((CAkParameterNode *)&this->vfptr, in_pGameObj);
  v4 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&v3->m_mapObjectCntrInfo,
         v2);
  if ( v4 )
  {
    (*(void (**)(void))(**(_QWORD **)&v4->fValue + 8i64))();
    AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8>::Unset<CAkRegisteredObj *>(
      (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&v3->m_mapObjectCntrInfo,
      v2);
  }
}

// File Line: 258
// RVA: 0xA8CF90
signed __int64 __fastcall CAkRanSeqCntr::SetParamComplexFromRTPCManager(CAkRanSeqCntr *this, void *in_pToken, __int64 in_Param_id, __int64 in_RTPCid, float in_value, CAkRegisteredObj *in_GameObj, void *in_pGameObjExceptArray)
{
  signed __int64 result; // rax

  if ( (_DWORD)in_Param_id == 5 )
    result = 1i64;
  else
    result = CAkParameterNodeBase::SetParamComplexFromRTPCManager(
               (CAkParameterNodeBase *)&this->vfptr,
               in_pToken,
               in_Param_id,
               in_RTPCid,
               in_value,
               in_GameObj,
               in_pGameObjExceptArray);
  return result;
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
  CAkRanSeqCntr *v2; // rdi
  unsigned __int16 v3; // bx
  CAkRandomInfo *v4; // rax
  CAkRandomInfo *v5; // rax
  CAkRandomInfo *v6; // rbx
  unsigned int v8; // eax

  v2 = this;
  v3 = in_uPlaylistSize;
  v4 = (CAkRandomInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  if ( !v4 )
    return 0i64;
  CAkRandomInfo::CAkRandomInfo(v4, v3);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  if ( CAkRandomInfo::Init(v5, v2->m_wAvoidRepeatCount) != 1 )
  {
    v6->vfptr->Destroy((CAkContainerBaseInfo *)&v6->vfptr);
    return 0i64;
  }
  if ( *((_BYTE *)v2 + 221) & 8 )
  {
    v8 = (*(__int64 (**)(void))v2->m_pPlayList->vfptr[1].gap8)();
    v6->m_ulRemainingWeight = v8;
    v6->m_ulTotalWeight = v8;
  }
  return v6;
}

// File Line: 297
// RVA: 0xA8BD20
CAkContainerBaseInfo *__fastcall CAkRanSeqCntr::GetExistingSequenceInfo(CAkRanSeqCntr *this, CAkRegisteredObj *in_pGameObj)
{
  CAkContainerBaseInfo *v2; // rbx
  CAkRegisteredObj *v3; // rsi
  CAkRanSeqCntr *v4; // rdi
  CAkSequenceInfo *v5; // rax
  CAkContainerBaseInfo *v6; // rax
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  CAkSequenceInfo *v8; // rax
  CAkContainerBaseInfo *v9; // rax
  CAkRanSeqCntr::CntrInfoEntry *v11; // rax

  v2 = 0i64;
  v3 = in_pGameObj;
  v4 = this;
  if ( *((_BYTE *)this + 221) < 0 )
  {
    if ( !this->m_pGlobalContainerInfo )
    {
      v5 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
      if ( v5 )
        CAkSequenceInfo::CAkSequenceInfo(v5);
      else
        v6 = 0i64;
      v4->m_pGlobalContainerInfo = v6;
    }
    if ( v4->m_pGlobalContainerInfo )
      v2 = v4->m_pGlobalContainerInfo;
    return v2;
  }
  v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
         in_pGameObj);
  if ( v7 )
    return *(CAkContainerBaseInfo **)&v7->fValue;
  v8 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
  if ( !v8 )
    return 0i64;
  CAkSequenceInfo::CAkSequenceInfo(v8);
  v2 = v9;
  if ( !v9 )
    return 0i64;
  if ( (unsigned int)CAkRegisteredObj::SetNodeAsModified(v3, (CAkParameterNodeBase *)&v4->vfptr) != 1 )
  {
    v2->vfptr->Destroy(v2);
    return 0i64;
  }
  v11 = AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1>::Set<CAkRegisteredObj *>(
          &v4->m_mapObjectCntrInfo,
          v3);
  if ( !v11 )
  {
    v2->vfptr->Destroy(v2);
    return 0i64;
  }
  v11->pInfo = v2;
  return v2;
}

// File Line: 343
// RVA: 0xA8BC40
CAkRandomInfo *__fastcall CAkRanSeqCntr::GetExistingRandomInfo(CAkRanSeqCntr *this, unsigned __int16 in_uPlaylistSize, CAkRegisteredObj *in_pGameObj)
{
  CAkRandomInfo *v3; // rbx
  CAkRegisteredObj *v4; // rsi
  unsigned __int16 v5; // r14
  CAkRanSeqCntr *v6; // rdi
  CAkRTPCMgr::AkRTPCValue *v7; // rax
  CAkRanSeqCntr::CntrInfoEntry *v9; // rax

  v3 = 0i64;
  v4 = in_pGameObj;
  v5 = in_uPlaylistSize;
  v6 = this;
  if ( *((_BYTE *)this + 221) < 0 )
  {
    if ( !this->m_pGlobalContainerInfo )
      this->m_pGlobalContainerInfo = (CAkContainerBaseInfo *)CAkRanSeqCntr::CreateRandomInfo(this, in_uPlaylistSize);
    if ( v6->m_pGlobalContainerInfo )
      v3 = (CAkRandomInfo *)v6->m_pGlobalContainerInfo;
    return v3;
  }
  v7 = AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
         (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
         in_pGameObj);
  if ( v7 )
    return *(CAkRandomInfo **)&v7->fValue;
  v3 = CAkRanSeqCntr::CreateRandomInfo(v6, v5);
  if ( !v3 )
    return 0i64;
  if ( (unsigned int)CAkRegisteredObj::SetNodeAsModified(v4, (CAkParameterNodeBase *)&v6->vfptr) != 1
    || (v9 = AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1>::Set<CAkRegisteredObj *>(
               &v6->m_mapObjectCntrInfo,
               v4)) == 0i64 )
  {
    v3->vfptr->Destroy((CAkContainerBaseInfo *)&v3->vfptr);
    return 0i64;
  }
  v9->pInfo = (CAkContainerBaseInfo *)&v3->vfptr;
  return v3;
}

// File Line: 388
// RVA: 0xA8BE20
CAkRandomInfo *__fastcall CAkRanSeqCntr::GetNextToPlay(CAkRanSeqCntr *this, CAkRegisteredObj *in_pGameObj, unsigned __int16 *out_rwPositionSelected, unsigned int *out_uSelectedNodeID)
{
  unsigned __int16 v4; // di
  CAkRanSeqCntr *v5; // rsi
  unsigned int *v6; // rbx
  CAkRegisteredObj *v7; // rbp
  CAkIndexable *v8; // r14
  unsigned int v9; // eax
  unsigned int v10; // er13
  char v11; // r15
  int v12; // er12
  CAkParameterNodeBase *v13; // rbx
  CAkRandomInfo *result; // rax
  CAkRandomInfo *i; // rcx
  char v16; // bp
  int v17; // edi
  __int16 v18; // ax
  unsigned __int16 v19; // ax
  unsigned __int16 v20; // ax
  unsigned int v21; // eax
  CAkIndexable *v22; // rax
  unsigned int v23; // eax
  CAkRandomInfo *in_pRandomInfo; // [rsp+20h] [rbp-48h]
  bool out_bIsAnswerValid; // [rsp+70h] [rbp+8h]
  unsigned __int16 *v26; // [rsp+80h] [rbp+18h]
  unsigned int *v27; // [rsp+88h] [rbp+20h]

  v27 = out_uSelectedNodeID;
  v26 = out_rwPositionSelected;
  v4 = 0;
  v5 = this;
  v6 = out_uSelectedNodeID;
  *out_rwPositionSelected = 0;
  *out_uSelectedNodeID = 0;
  v7 = in_pGameObj;
  v8 = 0i64;
  v9 = ((__int64 (*)(void))this->m_pPlayList->vfptr->Length)();
  v10 = v9;
  if ( !v9 )
    return (CAkRandomInfo *)v8;
  if ( v9 == 1 )
  {
    v23 = v5->m_pPlayList->vfptr->ID(v5->m_pPlayList, 0);
    *v6 = v23;
    return (CAkRandomInfo *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v23, 0);
  }
  v11 = 0;
  v12 = 0;
  v13 = 0i64;
  in_pRandomInfo = 0i64;
  if ( (*((_BYTE *)v5 + 221) & 7) == 1 )
  {
    result = (CAkRandomInfo *)CAkRanSeqCntr::GetExistingSequenceInfo(v5, v7);
    v13 = (CAkParameterNodeBase *)result;
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
        v16 = CAkRanSeqCntr::CanPlayPosition(v5, i, v4);
        if ( !v16 )
        {
LABEL_29:
          if ( !v11 )
            return (CAkRandomInfo *)v8;
          goto LABEL_30;
        }
        CAkRanSeqCntr::UpdateNormalAvoidRepeat(v5, in_pRandomInfo, v4);
      }
      else
      {
        if ( (*((_BYTE *)v5 + 221) & 7) == 1 )
        {
          if ( LOBYTE(v13->pNextItem) )
          {
            v17 = SWORD1(v13->pNextItem);
            if ( v17 + 1 == ((unsigned int (__fastcall *)(CAkPlayList *, signed __int64))v5->m_pPlayList->vfptr->Length)(
                              v5->m_pPlayList,
                              1i64) )
            {
              if ( *((_BYTE *)v5 + 221) & 0x20 )
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
        v20 = CAkRanSeqCntr::SelectRandomly(v5, i, &out_bIsAnswerValid, 0i64);
        v16 = out_bIsAnswerValid;
        v4 = v20;
      }
      if ( !v16 )
        goto LABEL_29;
LABEL_26:
      v21 = v5->m_pPlayList->vfptr->ID(v5->m_pPlayList, v4);
      *v27 = v21;
      v22 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v21, 0);
      v8 = v22;
      if ( v22 )
      {
        if ( v22->vfptr[3].Category(v22) )
        {
          *v26 = v4;
          return (CAkRandomInfo *)v8;
        }
        v8->vfptr->Release(v8);
        v8 = 0i64;
      }
LABEL_30:
      if ( !v12 && !(*((_BYTE *)v5 + 221) & 7) && (*((_BYTE *)v5 + 220) & 0x30) != 16 )
        v11 = 1;
      if ( ++v12 >= v10 )
        return (CAkRandomInfo *)v8;
    }
  }
  result = CAkRanSeqCntr::GetExistingRandomInfo(v5, v9, v7);
  i = result;
  in_pRandomInfo = result;
  if ( result )
    goto LABEL_9;
  return result;
}

// File Line: 498
// RVA: 0xA8C090
CAkIndexable *__fastcall CAkRanSeqCntr::GetNextToPlayContinuous(CAkRanSeqCntr *this, CAkRegisteredObj *in_pGameObj, unsigned __int16 *out_rwPositionSelected, unsigned int *out_uSelectedNodeID, CAkContainerBaseInfo **io_pContainerInfo, AkLoop *io_rLoopInfo)
{
  __int64 v6; // r14
  CAkRanSeqCntr *v7; // rbx
  unsigned int *v8; // r15
  unsigned __int16 *v9; // r12
  CAkRegisteredObj *v10; // rsi
  int v11; // eax
  unsigned __int16 v12; // r9
  char v13; // cl
  CAkContainerBaseInfo **v14; // rdi
  CAkContainerBaseInfo *v15; // rbp
  CAkSequenceInfo *v17; // rax
  CAkSequenceInfo *v18; // rsi
  AkLoop *v19; // r9
  unsigned __int16 v20; // ax
  __int64 v21; // rax
  CAkContainerBaseInfo *v22; // rcx
  CAkSequenceInfo *v23; // rdi
  unsigned __int16 v24; // bp
  CAkRandomInfo *v25; // rax
  __int64 v26; // rdx
  unsigned int v27; // eax
  bool out_bIsAnswerValid; // [rsp+50h] [rbp+8h]

  v6 = 0i64;
  v7 = this;
  v8 = out_uSelectedNodeID;
  *out_uSelectedNodeID = 0;
  *out_rwPositionSelected = 0;
  v9 = out_rwPositionSelected;
  v10 = in_pGameObj;
  v11 = ((__int64 (*)(void))this->m_pPlayList->vfptr->Length)();
  v12 = v11;
  if ( !v11 )
    return (CAkIndexable *)v6;
  if ( v11 != 1 )
  {
    v13 = *((_BYTE *)v7 + 221);
    v14 = io_pContainerInfo;
    out_bIsAnswerValid = 1;
    if ( !(v13 & 0x10) && !*io_pContainerInfo && (v13 & 7) == 1 )
    {
      v15 = CAkRanSeqCntr::GetExistingSequenceInfo(v7, v10);
      if ( v15 )
      {
        CAkRanSeqCntr::CreateSequenceInfo(v7);
        v18 = v17;
        if ( v17 )
        {
          v19 = io_rLoopInfo;
          v17->m_bIsForward = (char)v15[1].vfptr;
          v17->m_i16LastPositionChosen = WORD1(v15[1].vfptr);
          v20 = CAkRanSeqCntr::SelectSequentially(v7, v17, &out_bIsAnswerValid, v19);
          *v14 = (CAkContainerBaseInfo *)&v18->vfptr;
LABEL_21:
          v24 = v20;
          goto LABEL_22;
        }
      }
      return 0i64;
    }
    if ( (v13 & 7) != 1 )
    {
      v25 = (CAkRandomInfo *)*io_pContainerInfo;
      if ( !*io_pContainerInfo )
      {
        v25 = CAkRanSeqCntr::CreateRandomInfo(v7, v12);
        if ( !v25 )
          return 0i64;
        *v14 = (CAkContainerBaseInfo *)&v25->vfptr;
      }
      v20 = CAkRanSeqCntr::SelectRandomly(v7, v25, &out_bIsAnswerValid, io_rLoopInfo);
      goto LABEL_21;
    }
    if ( !*io_pContainerInfo )
    {
      CAkRanSeqCntr::CreateSequenceInfo(v7);
      *v14 = (CAkContainerBaseInfo *)v21;
      if ( !v21 )
        return 0i64;
      v22 = v7->m_pGlobalContainerInfo;
      if ( v22 )
      {
        *(_WORD *)(v21 + 10) = WORD1(v22[1].vfptr);
        WORD1(v22[1].vfptr) = -1;
      }
    }
    v23 = (CAkSequenceInfo *)*v14;
    v24 = CAkRanSeqCntr::SelectSequentially(v7, v23, &out_bIsAnswerValid, io_rLoopInfo);
    if ( !(*((_BYTE *)v7 + 221) & 0x10) )
      CAkRanSeqCntr::UpdateResetPlayListSetup(v7, v23, v10);
LABEL_22:
    if ( out_bIsAnswerValid )
    {
      *v9 = v24;
      v26 = v24;
LABEL_28:
      v27 = v7->m_pPlayList->vfptr->ID(v7->m_pPlayList, v26);
      *v8 = v27;
      return CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v27, 0);
    }
    return (CAkIndexable *)v6;
  }
  if ( io_rLoopInfo->lLoopCount > 0 )
  {
    if ( !(*((_BYTE *)io_rLoopInfo + 2) & 2) )
      --io_rLoopInfo->lLoopCount;
    v26 = 0i64;
    goto LABEL_28;
  }
  return (CAkIndexable *)v6;
}

// File Line: 606
// RVA: 0xA8B6F0
__int64 __fastcall CAkRanSeqCntr::AddPlaylistItem(CAkRanSeqCntr *this, unsigned int in_ElementID, unsigned int in_weight)
{
  unsigned int v3; // edi
  unsigned int v4; // esi
  CAkRanSeqCntr *v5; // rbx
  __int64 result; // rax
  unsigned int v7; // edi

  v3 = in_weight;
  v4 = in_ElementID;
  v5 = this;
  if ( in_weight != 50000 )
    *((_BYTE *)this + 221) |= 8u;
  if ( (*((_BYTE *)this + 221) & 7) != 1 && ((unsigned __int8 (*)(void))this->m_pPlayList->vfptr->Exists)() )
    return 35i64;
  result = v5->m_pPlayList->vfptr->Add(v5->m_pPlayList, v4, v3);
  v7 = result;
  if ( (_DWORD)result == 1 )
  {
    CAkRanSeqCntr::DestroySpecificInfo(v5);
    if ( (unsigned __int8)v7 & *((_BYTE *)v5 + 222) )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v5->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v5->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v5->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
    result = v7;
  }
  return result;
}

// File Line: 697
// RVA: 0xA8B8D0
void __fastcall CAkRanSeqCntr::Continuous(CAkRanSeqCntr *this, const bool in_bIsContinuous)
{
  CAkRanSeqCntr *v2; // rbx
  unsigned __int8 v3; // cl

  v2 = this;
  v3 = *((_BYTE *)this + 221);
  if ( ((v3 >> 6) & 1) != in_bIsContinuous )
  {
    *((_BYTE *)v2 + 221) = v3 ^ (v3 ^ (in_bIsContinuous << 6)) & 0x40;
    CAkRanSeqCntr::DestroySpecificInfo(v2);
    if ( *((_BYTE *)v2 + 222) & 1 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 711
// RVA: 0xA8C510
void __fastcall CAkRanSeqCntr::IsGlobal(CAkRanSeqCntr *this, bool in_bIsGlobal)
{
  CAkRanSeqCntr *v2; // rbx
  unsigned __int8 v3; // cl

  v2 = this;
  v3 = *((_BYTE *)this + 221);
  if ( v3 >> 7 != in_bIsGlobal )
  {
    *((_BYTE *)v2 + 221) = (in_bIsGlobal << 7) | v3 & 0x7F;
    CAkRanSeqCntr::DestroySpecificInfo(v2);
    if ( *((_BYTE *)v2 + 222) & 1 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 725
// RVA: 0xA8C880
void __fastcall CAkRanSeqCntr::ResetPlayListAtEachPlay(CAkRanSeqCntr *this, bool in_bResetPlayListAtEachPlay)
{
  CAkRanSeqCntr *v2; // rbx
  unsigned __int8 v3; // cl

  v2 = this;
  v3 = *((_BYTE *)this + 221);
  if ( ((v3 >> 4) & 1) != in_bResetPlayListAtEachPlay )
  {
    *((_BYTE *)v2 + 221) = v3 ^ (v3 ^ 16 * in_bResetPlayListAtEachPlay) & 0x10;
    CAkRanSeqCntr::DestroySpecificInfo(v2);
    if ( *((_BYTE *)v2 + 222) & 1 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
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
  CAkRanSeqCntr *v2; // rbx
  char v3; // cl

  v2 = this;
  v3 = *((_BYTE *)this + 220);
  if ( (v3 & 0xF) != in_eTransitionMode )
  {
    *((_BYTE *)v2 + 220) = v3 ^ (in_eTransitionMode ^ v3) & 0xF;
    CAkRanSeqCntr::DestroySpecificInfo(v2);
    if ( *((_BYTE *)v2 + 222) & 1 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 748
// RVA: 0xA8D0D0
float __fastcall CAkRanSeqCntr::TransitionTime(CAkRanSeqCntr *this, CAkRegisteredObj *in_GameObj)
{
  CAkRanSeqCntr *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm7_4
  float v5; // xmm8_4
  float v6; // xmm0_4
  float v7; // xmm8_4
  float result; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm0_4

  v2 = this;
  if ( (LOBYTE(this->m_RTPCBitArray.m_iBitArray) >> 5) & 1 )
  {
    v3 = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 5u, in_GameObj);
    v4 = v2->m_TransitionTime.m_mod.m_max - v2->m_TransitionTime.m_mod.m_min;
    v5 = v3;
    v6 = 0.0;
    v7 = v5 * 1000.0;
    if ( v4 != 0.0 )
      v6 = (double)rand() * 0.00003051850947599719 * v4;
    result = (float)((float)(v6 + v2->m_TransitionTime.m_mod.m_min) + v2->m_TransitionTime.m_base) + v7;
  }
  else
  {
    v9 = this->m_TransitionTime.m_mod.m_max - this->m_TransitionTime.m_mod.m_min;
    v10 = 0.0;
    if ( v9 != 0.0 )
      v10 = (double)rand() * 0.00003051850947599719 * v9;
    result = (float)(v10 + v2->m_TransitionTime.m_mod.m_min) + v2->m_TransitionTime.m_base;
  }
  if ( result < 0.0 )
    result = 0.0;
  return result;
}

// File Line: 773
// RVA: 0xA8C800
void __fastcall CAkRanSeqCntr::RandomMode(CAkRanSeqCntr *this, AkRandomMode in_eRandomMode)
{
  CAkRanSeqCntr *v2; // rbx
  unsigned int v3; // ecx

  v2 = this;
  v3 = *((unsigned __int8 *)this + 220);
  if ( ((v3 >> 4) & 3) != in_eRandomMode )
  {
    *((_BYTE *)v2 + 220) = v3 ^ (v3 ^ 16 * in_eRandomMode) & 0x30;
    CAkRanSeqCntr::DestroySpecificInfo(v2);
    if ( *((_BYTE *)v2 + 222) & 1 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 787
// RVA: 0xA8B7D0
void __fastcall CAkRanSeqCntr::AvoidRepeatingCount(CAkRanSeqCntr *this, unsigned __int16 in_wCount)
{
  CAkRanSeqCntr *v2; // rbx

  v2 = this;
  if ( this->m_wAvoidRepeatCount != in_wCount )
  {
    this->m_wAvoidRepeatCount = in_wCount;
    CAkRanSeqCntr::DestroySpecificInfo(this);
    if ( *((_BYTE *)v2 + 222) & 1 )
    {
      if ( g_pAudioMgr )
      {
        CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
        CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      }
      CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
    }
  }
}

// File Line: 801
// RVA: 0xA8C590
signed __int64 __fastcall CAkRanSeqCntr::Mode(CAkRanSeqCntr *this, AkContainerMode in_eMode)
{
  CAkRanSeqCntr *v2; // rbx
  char v3; // cl
  char v4; // al
  CAkPlayList *v5; // rcx
  CAkPlayListSequence *v6; // rax
  CAkPlayList *v7; // rax
  CAkPlayListRandom *v8; // rax
  unsigned int v9; // edi

  v2 = this;
  v3 = *((_BYTE *)this + 221);
  if ( in_eMode == (v3 & 7) )
    return 1i64;
  v4 = v3 ^ (in_eMode ^ v3) & 7;
  v5 = v2->m_pPlayList;
  *((_BYTE *)v2 + 221) = v4;
  if ( v5 )
    ((void (*)(void))v5->vfptr->Destroy)();
  if ( (*((_BYTE *)v2 + 221) & 7) != 1 )
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
  v2->m_pPlayList = v7;
  if ( v7 )
  {
    v9 = (*(__int64 (__fastcall **)(CAkPlayList *))v7->vfptr->gap8)(v7);
    if ( v9 != 1 )
    {
      ((void (*)(void))v2->m_pPlayList->vfptr->Destroy)();
      v2->m_pPlayList = 0i64;
    }
  }
  else
  {
    v9 = 2;
  }
  CAkRanSeqCntr::DestroySpecificInfo(v2);
  if ( *((_BYTE *)v2 + 222) & 1 )
  {
    if ( g_pAudioMgr )
    {
      CAkAudioMgr::RemovePausedPendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
      CAkAudioMgr::RemovePendingAction(g_pAudioMgr, (CAkParameterNodeBase *)&v2->vfptr);
    }
    CAkParameterNodeBase::Stop((CAkParameterNodeBase *)&v2->vfptr, 0i64, 0, 0, AkCurveInterpolation_Linear);
  }
  return v9;
}

// File Line: 882
// RVA: 0xA8BB80
void __fastcall CAkRanSeqCntr::DestroySpecificInfo(CAkRanSeqCntr *this)
{
  CAkRanSeqCntr::CntrInfoEntry *v1; // rbx
  CAkRanSeqCntr *v2; // rdi
  CAkContainerBaseInfo *v3; // rcx

  v1 = this->m_mapObjectCntrInfo.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_mapObjectCntrInfo.m_uLength] )
  {
    do
    {
      ((void (*)(void))v1->pInfo->vfptr->Destroy)();
      ++v1;
    }
    while ( v1 != &v2->m_mapObjectCntrInfo.m_pItems[v2->m_mapObjectCntrInfo.m_uLength] );
  }
  v2->m_mapObjectCntrInfo.m_uLength = 0;
  v3 = v2->m_pGlobalContainerInfo;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Destroy)();
    v2->m_pGlobalContainerInfo = 0i64;
  }
}

// File Line: 896
// RVA: 0xA8C270
__int64 __fastcall CAkRanSeqCntr::GetPlaylistLength(CAkRanSeqCntr *this)
{
  CAkPlayList *v1; // rcx
  __int64 result; // rax

  v1 = this->m_pPlayList;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr->Length)();
  else
    result = 0i64;
  return result;
}

// File Line: 911
// RVA: 0xA8CC10
__int64 __fastcall CAkRanSeqCntr::SelectSequentially(CAkRanSeqCntr *this, CAkSequenceInfo *in_pSeqInfo, bool *out_bIsAnswerValid, AkLoop *io_pLoopCount)
{
  AkLoop *v4; // rdi
  bool *v5; // r14
  CAkSequenceInfo *v6; // rbx
  CAkRanSeqCntr *v7; // rbp
  int v8; // esi
  char v9; // al
  bool v10; // zf
  __int16 v12; // ax
  char v13; // al

  *out_bIsAnswerValid = 1;
  v4 = io_pLoopCount;
  v5 = out_bIsAnswerValid;
  v6 = in_pSeqInfo;
  v7 = this;
  if ( in_pSeqInfo->m_bIsForward )
  {
    v8 = in_pSeqInfo->m_i16LastPositionChosen;
    if ( v8 + 1 == ((unsigned int (*)(void))this->m_pPlayList->vfptr->Length)() )
    {
      if ( *((_BYTE *)v7 + 221) & 0x20 )
      {
        v6->m_bIsForward = 0;
        v6->m_i16LastPositionChosen = v8 - 1;
      }
      else
      {
        v6->m_i16LastPositionChosen = 0;
        if ( v4 )
        {
          v9 = *((_BYTE *)v4 + 2);
          if ( !(v9 & 1) || !(v9 & 2) && (v10 = v4->lLoopCount == 1, --v4->lLoopCount, v10) )
          {
            *v5 = 0;
            return 0i64;
          }
        }
      }
    }
    else
    {
      v6->m_i16LastPositionChosen = v8 + 1;
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
        if ( !(v13 & 1) || !(v13 & 2) && (v10 = io_pLoopCount->lLoopCount == 1, --io_pLoopCount->lLoopCount, v10) )
        {
          *out_bIsAnswerValid = 0;
          return 0i64;
        }
      }
    }
  }
  return (unsigned __int16)v6->m_i16LastPositionChosen;
}

// File Line: 959
// RVA: 0xA8D230
signed __int64 __fastcall CAkRanSeqCntr::UpdateNormalAvoidRepeat(CAkRanSeqCntr *this, CAkRandomInfo *in_pRandomInfo, unsigned __int16 in_uPosition)
{
  CAkPlayList *v3; // r14
  unsigned __int16 v4; // bp
  CAkRandomInfo *v5; // rsi
  CAkRanSeqCntr *v6; // rdi
  AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v7; // rbx
  unsigned __int16 *v8; // rax
  unsigned __int16 v9; // ax
  unsigned __int16 v10; // di
  unsigned int v11; // eax
  unsigned __int16 *v12; // rdi
  unsigned __int64 v13; // rcx
  unsigned __int16 *v14; // rsi
  unsigned __int64 i; // rcx

  v3 = this->m_pPlayList;
  v4 = in_uPosition;
  v5 = in_pRandomInfo;
  v6 = this;
  if ( !this->m_wAvoidRepeatCount )
    return 1i64;
  v7 = &in_pRandomInfo->m_listAvoid;
  --in_pRandomInfo->m_wRemainingItemsToPlay;
  v8 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRandomInfo->m_listAvoid);
  if ( v8 )
  {
    *v8 = v4;
    CAkRandomInfo::FlagAsBlocked(v5, v4);
    v5->m_ulRemainingWeight -= v3->vfptr->GetWeight(v3, v4);
    v9 = (unsigned __int64)((__int64 (*)(void))v6->m_pPlayList->vfptr->Length)() - 1;
    if ( v6->m_wAvoidRepeatCount < v9 )
      v9 = v6->m_wAvoidRepeatCount;
    if ( v5->m_listAvoid.m_uLength > v9 )
    {
      v10 = *v7->m_pItems;
      CAkRandomInfo::FlagAsUnBlocked(v5, *v7->m_pItems);
      v11 = v3->vfptr->GetWeight(v3, v10);
      ++v5->m_wRemainingItemsToPlay;
      v5->m_ulRemainingWeight += v11;
      v12 = v7->m_pItems;
      v13 = (unsigned __int64)&v7->m_pItems[v7->m_uLength - 1i64];
      if ( v7->m_pItems < (unsigned __int16 *)v13 )
      {
        v14 = v12 + 1;
        for ( i = ((v13 - (unsigned __int64)v12 - 1) >> 1) + 1; i; --i )
        {
          *v12 = *v14;
          ++v14;
          ++v12;
        }
      }
      --v7->m_uLength;
    }
    return 1i64;
  }
  v5->m_wCounter = 0;
  return 2i64;
}

// File Line: 990
// RVA: 0xA8C900
__int64 __fastcall CAkRanSeqCntr::SelectRandomly(CAkRanSeqCntr *this, CAkRandomInfo *in_pRandomInfo, bool *out_bIsAnswerValid, AkLoop *io_pLoopCount)
{
  CAkPlayList *v4; // r15
  unsigned __int16 v5; // bp
  signed int v6; // er14
  CAkRandomInfo *v7; // rbx
  CAkRanSeqCntr *v8; // rsi
  char v9; // al
  bool v10; // zf
  unsigned int v12; // eax
  unsigned __int16 *v13; // rdi
  unsigned int v14; // eax
  int v15; // edi
  signed int v16; // edi
  unsigned __int16 v17; // bp
  unsigned __int16 v18; // di
  unsigned __int16 *v19; // rax
  unsigned __int16 v20; // ax
  unsigned __int16 *v21; // rdi
  unsigned __int16 v22; // r12
  unsigned __int16 *v23; // rsi
  unsigned __int64 i; // rcx

  *out_bIsAnswerValid = 1;
  v4 = this->m_pPlayList;
  v5 = 0;
  v6 = -1;
  v7 = in_pRandomInfo;
  v8 = this;
  if ( !in_pRandomInfo->m_wCounter )
  {
    if ( io_pLoopCount )
    {
      v9 = *((_BYTE *)io_pLoopCount + 2);
      if ( !(v9 & 1) || !(v9 & 2) && (v10 = io_pLoopCount->lLoopCount == 1, --io_pLoopCount->lLoopCount, v10) )
      {
        *out_bIsAnswerValid = 0;
        return 0i64;
      }
    }
    in_pRandomInfo->m_wCounter = ((__int64 (*)(void))this->m_pPlayList->vfptr->Length)();
    v12 = ((__int64 (*)(void))v8->m_pPlayList->vfptr->Length)();
    CAkRandomInfo::ResetFlagsPlayed(v7, v12);
    if ( (*((_BYTE *)v8 + 220) & 0x30) == 16 )
    {
      v13 = v7->m_listAvoid.m_pItems;
      v7->m_ulRemainingWeight = v7->m_ulTotalWeight;
      if ( v13 != &v13[v7->m_listAvoid.m_uLength] )
      {
        do
        {
          v14 = v4->vfptr->GetWeight(v4, *v13);
          ++v13;
          v7->m_ulRemainingWeight -= v14;
        }
        while ( v13 != &v7->m_listAvoid.m_pItems[v7->m_listAvoid.m_uLength] );
      }
    }
    v7->m_wRemainingItemsToPlay -= LOWORD(v7->m_listAvoid.m_uLength);
  }
  if ( !(*((_BYTE *)v8 + 221) & 8) )
  {
    v16 = (unsigned __int16)(rand() % v7->m_wRemainingItemsToPlay);
    if ( v16 <= -1 )
      goto LABEL_31;
    while ( 1 )
    {
      if ( *((_BYTE *)v8 + 220) & 0x30 )
      {
        if ( CAkRandomInfo::IsFlagSetPlayed(v7, v5) || CAkRandomInfo::IsFlagBlocked(v7, v5) )
          goto LABEL_30;
      }
      else if ( v8->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(v7, v5) )
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
  v15 = CAkRandomInfo::GetRandomValue(v7);
  if ( v15 > -1 )
  {
    do
    {
      if ( *((_BYTE *)v8 + 220) & 0x30 )
      {
        if ( CAkRandomInfo::IsFlagSetPlayed(v7, v5) || CAkRandomInfo::IsFlagBlocked(v7, v5) )
          goto LABEL_20;
      }
      else if ( v8->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(v7, v5) )
      {
        goto LABEL_20;
      }
      v6 += v4->vfptr->GetWeight(v4, v5);
LABEL_20:
      ++v5;
    }
    while ( v6 < v15 );
  }
LABEL_31:
  v17 = v5 - 1;
  if ( *((_BYTE *)v8 + 220) & 0x30 )
  {
    v18 = v8->m_wAvoidRepeatCount;
    if ( !v18 )
      v18 = 1;
    v7->m_ulRemainingWeight -= v4->vfptr->GetWeight(v4, v17);
    --v7->m_wRemainingItemsToPlay;
    --v7->m_wCounter;
    CAkRandomInfo::FlagSetPlayed(v7, v17);
    v19 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&v7->m_listAvoid);
    if ( v19 )
    {
      *v19 = v17;
      CAkRandomInfo::FlagAsBlocked(v7, v17);
      v20 = (unsigned __int64)((__int64 (*)(void))v8->m_pPlayList->vfptr->Length)() - 1;
      if ( v18 < v20 )
        v20 = v18;
      if ( v7->m_listAvoid.m_uLength > v20 )
      {
        v21 = v7->m_listAvoid.m_pItems;
        v22 = *v21;
        if ( v21 < &v21[v7->m_listAvoid.m_uLength - 1i64] )
        {
          v23 = v21 + 1;
          for ( i = ((2 * ((unsigned __int64)v7->m_listAvoid.m_uLength - 1) - 1) >> 1) + 1; i; --i )
          {
            *v21 = *v23;
            ++v23;
            ++v21;
          }
        }
        --v7->m_listAvoid.m_uLength;
        CAkRandomInfo::FlagAsUnBlocked(v7, v22);
        if ( !CAkRandomInfo::IsFlagSetPlayed(v7, v22) )
        {
          v7->m_ulRemainingWeight += v4->vfptr->GetWeight(v4, v22);
          ++v7->m_wRemainingItemsToPlay;
        }
      }
    }
    else
    {
      v7->m_wCounter = 0;
    }
  }
  else
  {
    if ( !CAkRandomInfo::IsFlagSetPlayed(v7, v17) )
    {
      CAkRandomInfo::FlagSetPlayed(v7, v17);
      --v7->m_wCounter;
    }
    CAkRanSeqCntr::UpdateNormalAvoidRepeat(v8, v7, v17);
  }
  return v17;
}

// File Line: 1117
// RVA: 0xA8B840
char __fastcall CAkRanSeqCntr::CanPlayPosition(CAkRanSeqCntr *this, CAkRandomInfo *in_pRandomInfo, unsigned __int16 in_wPosition)
{
  unsigned __int16 v3; // bx
  CAkRandomInfo *v4; // rdi

  v3 = in_wPosition;
  v4 = in_pRandomInfo;
  if ( *((_BYTE *)this + 220) & 0x30 )
    return !CAkRandomInfo::IsFlagSetPlayed(in_pRandomInfo, in_wPosition) && !CAkRandomInfo::IsFlagBlocked(v4, v3);
  if ( this->m_wAvoidRepeatCount )
    return CAkRandomInfo::IsFlagBlocked(in_pRandomInfo, in_wPosition) == 0;
  return 1;
}

// File Line: 1137
// RVA: 0xA8C6C0
AKRESULT __fastcall CAkRanSeqCntr::PlayInternal(CAkRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v2; // rbx
  CAkRanSeqCntr *v3; // rdi
  CAkContinuationList *v4; // rax
  CAkContinuationList *v5; // rcx
  AKRESULT result; // eax
  AKRESULT v7; // ebx
  ContParams *v8; // rax
  CAkContinuationList *v9; // rax
  ContParams *v10; // rdx
  CAkContinuationList *v11; // rcx
  __int64 v12; // [rsp+20h] [rbp-48h]
  int v13; // [rsp+28h] [rbp-40h]
  __int64 v14; // [rsp+30h] [rbp-38h]
  __int64 v15; // [rsp+38h] [rbp-30h]
  __int64 *v16; // [rsp+40h] [rbp-28h]
  __int16 v17; // [rsp+48h] [rbp-20h]
  CAkContinuationList *v18; // [rsp+50h] [rbp-18h]
  int v19; // [rsp+58h] [rbp-10h]

  *((_BYTE *)this + 222) |= 1u;
  v2 = in_rPBIParams;
  v3 = this;
  if ( !(*((_BYTE *)this + 221) & 0x40) )
    return CAkRanSeqCntr::_Play(this, in_rPBIParams);
  if ( in_rPBIParams->eType )
  {
    v8 = in_rPBIParams->pContinuousParams;
    if ( !v8 || v8->spContList.m_pT )
      goto LABEL_20;
    v9 = CAkContinuationList::Create();
    v10 = v2->pContinuousParams;
    v11 = v10->spContList.m_pT;
    v10->spContList.m_pT = v9;
    if ( v11 )
      CAkContinuationList::Release(v11);
    if ( v2->pContinuousParams->spContList.m_pT )
LABEL_20:
      result = CAkRanSeqCntr::_PlayContinuous(v3, v2);
    else
      result = 2;
  }
  else
  {
    in_rPBIParams->pInstigator = (CAkPBIAware *)&this->vfptr;
    v16 = &v12;
    v14 = 0i64;
    v15 = 0i64;
    v17 = 0;
    v12 = 0i64;
    v18 = 0i64;
    v19 = 0;
    in_rPBIParams->eType = 1;
    v13 = 0;
    v4 = CAkContinuationList::Create();
    v5 = v18;
    v18 = v4;
    if ( v5 )
    {
      CAkContinuationList::Release(v5);
      v4 = v18;
    }
    if ( v4 )
    {
      v2->pContinuousParams = (ContParams *)&v14;
      v7 = CAkRanSeqCntr::_PlayContinuous(v3, v2);
      if ( v18 )
        CAkContinuationList::Release(v18);
      result = v7;
    }
    else
    {
      result = 2;
    }
  }
  return result;
}

// File Line: 1184
// RVA: 0xA8D400
__int64 __fastcall CAkRanSeqCntr::_Play(CAkRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v2; // rdi
  CAkRanSeqCntr *v3; // rsi
  CAkParameterNode *v4; // rbx
  unsigned int v5; // ecx
  unsigned int v6; // esi
  unsigned __int16 v7; // ax
  unsigned int v8; // eax
  __int64 result; // rax
  unsigned __int16 out_rwPositionSelected; // [rsp+38h] [rbp+10h]
  unsigned int out_uSelectedNodeID; // [rsp+40h] [rbp+18h]

  v2 = in_rPBIParams;
  v3 = this;
  v4 = (CAkParameterNode *)CAkRanSeqCntr::GetNextToPlay(
                             this,
                             in_rPBIParams->pGameObj,
                             &out_rwPositionSelected,
                             &out_uSelectedNodeID);
  if ( v4 )
  {
    v5 = v2->playHistory.HistArray.uiArraySize;
    v6 = 1;
    if ( v5 >= 0x20 )
    {
      v2->playHistory.HistArray.uiArraySize = v5 + 1;
    }
    else
    {
      v7 = out_rwPositionSelected;
      v2->playHistory.arrayIsContinuous.m_iBitArray &= ~(1 << v5);
      v2->playHistory.HistArray.aCntrHist[v2->playHistory.HistArray.uiArraySize++] = v7;
    }
    v8 = CAkParameterNode::HandleInitialDelay(v4, v2);
    if ( v8 != 3 )
    {
      if ( v8 == 1 )
        v8 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v4->vfptr[19].Category)(v4, v2);
      v6 = v8;
    }
    v4->vfptr->Release((CAkIndexable *)&v4->vfptr);
    result = v6;
  }
  else if ( v2->eType )
  {
    result = ((__int64 (__fastcall *)(CAkRanSeqCntr *, AkPBIParams *))v3->vfptr[20].AddRef)(v3, v2);
    if ( (_DWORD)result == 3 )
      result = 1i64;
  }
  else
  {
    result = 2i64;
  }
  return result;
}

// File Line: 1220
// RVA: 0xA8D4F0
__int64 __fastcall CAkRanSeqCntr::_PlayContinuous(CAkRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  RandomizerModifier *v2; // rsi
  AkPBIParams *v3; // rbp
  unsigned int v4; // edi
  RANGED_PARAMETER<short> *v5; // rdx
  CAkContinueListItem *v6; // rbx
  CAkRanSeqCntr *v7; // rcx
  char v8; // cl
  AkLoop *io_rLoopInfo; // rcx
  signed __int16 v10; // ax
  CAkParameterNode *v11; // rbx
  unsigned int v12; // ecx
  unsigned __int16 v13; // ax
  unsigned int v14; // eax
  __int64 result; // rax
  CAkContinuationList *v16; // rbx
  unsigned __int16 out_rwPositionSelected; // [rsp+58h] [rbp+10h]
  unsigned int out_uSelectedNodeID; // [rsp+60h] [rbp+18h]

  v2 = (RandomizerModifier *)this;
  v3 = in_rPBIParams;
  v4 = 1;
  v6 = AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&in_rPBIParams->pContinuousParams->spContList.m_pT->m_listItems);
  if ( v6 )
  {
    if ( v2 )
      (*(void (__fastcall **)(RandomizerModifier *))(*(_QWORD *)v2 + 8i64))(v2);
    v7 = v6->m_pContainer.m_pT;
    v6->m_pContainer.m_pT = (CAkRanSeqCntr *)v2;
    if ( v7 )
      ((void (*)(void))v7->vfptr->Release)();
    *((_BYTE *)&v6->m_LoopingInfo + 2) ^= (*((_BYTE *)&v6->m_LoopingInfo + 2) ^ (*(_WORD *)&v2[212] != 1)) & 1;
    v8 = *((_BYTE *)&v6->m_LoopingInfo + 2) ^ (*((_BYTE *)&v6->m_LoopingInfo + 2) ^ 2 * (*(_WORD *)&v2[212] == 0)) & 2;
    *((_BYTE *)&v6->m_LoopingInfo + 2) = v8;
    if ( v8 & 1 )
    {
      if ( v8 & 2 )
      {
        io_rLoopInfo = &v6->m_LoopingInfo;
        v6->m_LoopingInfo.lLoopCount = 1;
      }
      else
      {
        v10 = RandomizerModifier::GetModValue<short>(v2 + 212, v5);
        if ( v10 >= 1 )
        {
          if ( v10 > 0x7FFF )
            v10 = 0x7FFF;
        }
        else
        {
          v10 = 1;
        }
        io_rLoopInfo = &v6->m_LoopingInfo;
        v6->m_LoopingInfo.lLoopCount = v10;
      }
    }
    else
    {
      io_rLoopInfo = &v6->m_LoopingInfo;
      v6->m_LoopingInfo.lLoopCount = 1;
    }
    v11 = (CAkParameterNode *)CAkRanSeqCntr::GetNextToPlayContinuous(
                                v6->m_pContainer.m_pT,
                                v3->pGameObj,
                                &out_rwPositionSelected,
                                &out_uSelectedNodeID,
                                &v6->m_pContainerInfo,
                                io_rLoopInfo);
    if ( v11 )
    {
      v12 = v3->playHistory.HistArray.uiArraySize;
      if ( v12 >= 0x20 )
      {
        v3->playHistory.HistArray.uiArraySize = v12 + 1;
      }
      else
      {
        v13 = out_rwPositionSelected;
        v3->playHistory.arrayIsContinuous.m_iBitArray |= 1i64 << v12;
        v3->playHistory.HistArray.aCntrHist[v3->playHistory.HistArray.uiArraySize++] = v13;
      }
      v14 = CAkParameterNode::HandleInitialDelay(v11, v3);
      if ( v14 != 3 )
      {
        if ( v14 == 1 )
          v14 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v11->vfptr[19].Category)(v11, v3);
        v4 = v14;
      }
      v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
      return v4;
    }
    v16 = v3->pContinuousParams->spContList.m_pT;
    CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v16->m_listItems.m_pItems
                                                                    + 8 * (5i64 * v16->m_listItems.m_uLength - 5)));
    --v16->m_listItems.m_uLength;
  }
  result = (*(__int64 (__fastcall **)(RandomizerModifier *, AkPBIParams *))(*(_QWORD *)v2 + 648i64))(v2, v3);
  if ( (_DWORD)result == 3 )
    result = 1i64;
  return result;
}

// File Line: 1296
// RVA: 0xA8B9C0
void __fastcall CAkRanSeqCntr::CreatePBI(CAkRanSeqCntr *this, CAkSoundBase *in_pSound, CAkSource *in_pSource, AkPBIParams *in_rPBIParams, PriorityInfoCurrent *in_rPriority, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  AkPBIParams *v7; // rbx
  CAkSource *v8; // rdi
  CAkSoundBase *v9; // rsi
  CAkContinuousPBI *v10; // r10

  v7 = in_rPBIParams;
  v8 = in_pSource;
  v9 = in_pSound;
  if ( in_rPBIParams->eType == 1 )
  {
    v10 = (CAkContinuousPBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x280ui64);
    if ( v10 )
      CAkContinuousPBI::CAkContinuousPBI(
        v10,
        v9,
        v8,
        v7->pGameObj,
        v7->pContinuousParams,
        &v7->userParams,
        &v7->playHistory,
        v7->bIsFirst,
        v7->sequenceID,
        v7->pInstigator,
        in_rPriority,
        v7->bTargetFeedback,
        in_pAMLimiter,
        in_pBusLimiter);
  }
  else
  {
    CAkPBIAware::CreatePBI(
      (CAkPBIAware *)&this->vfptr,
      in_pSound,
      in_pSource,
      in_rPBIParams,
      in_rPriority,
      in_pAMLimiter,
      in_pBusLimiter);
  }
}

// File Line: 1335
// RVA: 0xA8D350
void __fastcall CAkRanSeqCntr::UpdateResetPlayListSetup(CAkRanSeqCntr *this, CAkSequenceInfo *in_pSeqInfo, CAkRegisteredObj *in_pGameObj)
{
  CAkSequenceInfo *v3; // rsi
  CAkRanSeqCntr *v4; // rdi
  CAkContainerBaseInfo *v5; // rbx
  char v6; // al
  bool v7; // zf
  __int16 v8; // ax
  __int16 v9; // ax
  __int16 v10; // si

  v3 = in_pSeqInfo;
  v4 = this;
  if ( *((_BYTE *)this + 221) >= 0 )
    v5 = *(CAkContainerBaseInfo **)&AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
                                      (AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *)&this->m_mapObjectCntrInfo,
                                      in_pGameObj)->fValue;
  else
    v5 = this->m_pGlobalContainerInfo;
  v6 = v3->m_bIsForward;
  LOBYTE(v5[1].vfptr) = v6;
  v7 = v6 == 0;
  v8 = v3->m_i16LastPositionChosen;
  if ( v7 )
    v9 = v8 + 1;
  else
    v9 = v8 - 1;
  WORD1(v5[1].vfptr) = v9;
  v10 = v9;
  if ( v9 + 1 != ((unsigned int (__fastcall *)(CAkPlayList *, CAkSequenceInfo *, CAkRegisteredObj *))v4->m_pPlayList->vfptr->Length)(
                   v4->m_pPlayList,
                   in_pSeqInfo,
                   in_pGameObj)
    || *((_BYTE *)v4 + 221) & 0x20 )
  {
    if ( !v10 && !LOBYTE(v5[1].vfptr) )
      LOBYTE(v5[1].vfptr) = 1;
  }
  else
  {
    WORD1(v5[1].vfptr) = -1;
  }
}

