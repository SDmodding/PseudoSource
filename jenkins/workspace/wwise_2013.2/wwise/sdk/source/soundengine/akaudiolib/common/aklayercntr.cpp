// File Line: 31
// RVA: 0xA8D690
void __fastcall CAkLayerCntr::~CAkLayerCntr(CAkLayerCntr *this)
{
  CAkLayer **v1; // rbx
  CAkLayerCntr *v2; // rsi
  signed __int64 i; // rdi
  CAkLayer **v4; // rdx

  v1 = this->m_layers.m_pItems;
  v2 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkLayerCntr::`vftable;
  for ( i = (signed __int64)&v1[this->m_layers.m_uLength]; v1 != (CAkLayer **)i; ++v1 )
  {
    CAkLayer::SetOwner(*v1, 0i64);
    ((void (*)(void))(*v1)->vfptr->Release)();
  }
  v4 = v2->m_layers.m_pItems;
  if ( v4 )
  {
    v2->m_layers.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v2->m_layers.m_pItems = 0i64;
    v2->m_layers.m_ulReserved = 0;
  }
  CAkMultiPlayNode::Term((CAkMultiPlayNode *)&v2->vfptr);
  CAkMultiPlayNode::~CAkMultiPlayNode((CAkMultiPlayNode *)&v2->vfptr);
}

// File Line: 47
// RVA: 0xA8DB50
__int64 __fastcall CAkLayerCntr::SetInitialValues(CAkLayerCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkLayerCntr *v3; // rbp
  __int64 result; // rax
  unsigned int v5; // er14
  char *v6; // rcx
  int v7; // edi
  CAkLayer *v8; // rax
  CAkLayer *v9; // rbx
  unsigned int v10; // esi
  char *io_rpData; // [rsp+48h] [rbp+10h]
  unsigned int io_rulDataSize; // [rsp+50h] [rbp+18h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  v3 = this;
  result = CAkParameterNodeBase::SetNodeBaseParams((CAkParameterNodeBase *)&this->vfptr, &io_rpData, &io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
  {
    result = CAkParentNode<CAkParameterNode>::SetChildren(
               (CAkParentNode<CAkParameterNode> *)&v3->vfptr,
               &io_rpData,
               &io_rulDataSize);
    if ( (_DWORD)result == 1 )
    {
      v5 = *(_DWORD *)io_rpData;
      v6 = io_rpData + 4;
      v7 = 0;
      io_rpData += 4;
      if ( v5 )
      {
        while ( 1 )
        {
          v8 = CAkLayer::Create(*(_DWORD *)v6);
          v9 = v8;
          if ( !v8 )
            return 2i64;
          CAkLayer::SetOwner(v8, v3);
          v10 = CAkLayer::SetInitialValues(v9, &io_rpData, &io_rulDataSize);
          if ( v10 != 1 )
            break;
          if ( !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
                  (AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v3->m_layers,
                  (ITransitionable *)v9) )
          {
            v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
            return 2i64;
          }
          if ( ++v7 >= v5 )
            goto LABEL_13;
          v6 = io_rpData;
        }
        v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
LABEL_13:
        result = v10;
      }
    }
  }
  return result;
}

// File Line: 116
// RVA: 0xA8D760
__int64 __fastcall CAkLayerCntr::AddChild(CAkLayerCntr *this, WwiseObjectIDext in_ulID)
{
  CAkLayerCntr *v2; // rdi
  __int64 result; // rax
  CAkIndexable *v4; // rdx
  unsigned int v5; // esi
  CAkLayer **v6; // rbx
  signed __int64 v7; // rdi
  WwiseObjectIDext in_ChildID; // [rsp+38h] [rbp+10h]

  in_ChildID = in_ulID;
  v2 = this;
  if ( !in_ulID.id )
    return 14i64;
  v4 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ulID.id, 0);
  if ( !v4 )
    return 15i64;
  result = ((__int64 (__fastcall *)(CAkLayerCntr *, CAkIndexable *))v2->vfptr[2].AddRef)(v2, v4);
  v5 = result;
  if ( (_DWORD)result == 1 )
  {
    v6 = v2->m_layers.m_pItems;
    v7 = (signed __int64)&v6[v2->m_layers.m_uLength];
    if ( v6 != (CAkLayer **)v7 )
    {
      do
      {
        CAkLayer::UpdateChildPtr(*v6, in_ChildID.id);
        ++v6;
      }
      while ( v6 != (CAkLayer **)v7 );
      result = v5;
    }
  }
  return result;
}

// File Line: 135
// RVA: 0xA8DAC0
void __fastcall CAkLayerCntr::RemoveChild(CAkLayerCntr *this, CAkParameterNodeBase *in_pChild)
{
  CAkLayer **v2; // rbx
  CAkParameterNodeBase *v3; // rsi
  signed __int64 v4; // rdi
  CAkLayerCntr *i; // r14

  v2 = this->m_layers.m_pItems;
  v3 = in_pChild;
  v4 = (signed __int64)&v2[this->m_layers.m_uLength];
  for ( i = this; v2 != (CAkLayer **)v4; ++v2 )
    CAkLayer::UnsetChildAssoc(*v2, v3->key);
  if ( (CAkLayerCntr *)v3->m_pParentNode == i )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))v3->vfptr[1].Release)(v3, 0i64);
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      &i->m_mapChildId,
      v3->key);
    i->vfptr->Release((CAkIndexable *)&i->vfptr);
  }
}

// File Line: 148
// RVA: 0xA8D800
CAkMultiPlayNode *__fastcall CAkLayerCntr::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkMultiPlayNode *v2; // rax
  CAkMultiPlayNode *v3; // rbx

  v1 = in_ulID;
  v2 = (CAkMultiPlayNode *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC8ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkMultiPlayNode::CAkMultiPlayNode(v2, v1);
  v3->vfptr = (CAkIndexableVtbl *)&CAkLayerCntr::`vftable;
  v3[1].vfptr = 0i64;
  v3[1].pNextItem = 0i64;
  if ( CAkMultiPlayNode::Init(v3) == 1 )
    return v3;
  v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  return 0i64;
}

// File Line: 167
// RVA: 0xA8D890
__int64 __fastcall CAkLayerCntr::PlayInternal(CAkLayerCntr *this, AkPBIParams *in_rPBIParams)
{
  CAkLayerCntr *v2; // r15
  AkPBIParams *v3; // r13
  unsigned int v4; // er14
  unsigned int v5; // edi
  CAkParameterNode **v6; // rbx
  unsigned int v7; // er12
  CAkParameterNode *v8; // rsi
  AKRESULT v9; // eax
  AKRESULT v10; // edi
  CAkContinuationList *v11; // rax
  CAkContinuationList *v12; // rcx
  AKRESULT v13; // eax
  AKRESULT v14; // eax
  AkContParamsAndPath in_rContParams; // [rsp+20h] [rbp-81h]
  AkExternalSourceArray *v17; // [rsp+58h] [rbp-49h]
  AkContParamsAndPath *v18; // [rsp+B8h] [rbp+17h]
  int v19; // [rsp+C0h] [rbp+1Fh]
  bool v20; // [rsp+108h] [rbp+67h]
  unsigned int v21; // [rsp+110h] [rbp+6Fh]
  SafeContinuationList in_rSafeContList; // [rsp+118h] [rbp+77h]

  v2 = this;
  v3 = in_rPBIParams;
  v20 = in_rPBIParams->eType != 0;
  v4 = 1;
  SafeContinuationList::SafeContinuationList(&in_rSafeContList, in_rPBIParams, (CAkMultiPlayNode *)&this->vfptr);
  v6 = (CAkParameterNode **)v2->m_mapChildId.m_pItems;
  v7 = 0;
  v21 = v2->m_mapChildId.m_uLength;
  v5 = v21;
  if ( v6 == &v6[v21] )
    goto LABEL_29;
  while ( 1 )
  {
    v8 = *v6;
    AkPBIParams::AkPBIParams((AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition, v3);
    if ( v20 )
    {
      AkContParamsAndPath::AkContParamsAndPath(&in_rContParams, &v18->m_continuousParams);
      if ( v5 == 1 )
      {
        CAkMultiPlayNode::ContGetList(
          (CAkMultiPlayNode *)&v2->vfptr,
          v18->m_continuousParams.spContList.m_pT,
          &in_rContParams.m_continuousParams.spContList);
        goto LABEL_15;
      }
      v19 = 0;
      v11 = CAkContinuationList::Create();
      v12 = in_rContParams.m_continuousParams.spContList.m_pT;
      in_rContParams.m_continuousParams.spContList.m_pT = v11;
      if ( v12 )
      {
        CAkContinuationList::Release(v12);
        v11 = in_rContParams.m_continuousParams.spContList.m_pT;
      }
      if ( v11 )
      {
        v10 = CAkMultiPlayNode::AddMultiplayItem(
                (CAkMultiPlayNode *)&v2->vfptr,
                &in_rContParams,
                (AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition,
                &in_rSafeContList);
        if ( v10 == 1 )
        {
LABEL_15:
          v18 = &in_rContParams;
          v13 = (unsigned int)CAkParameterNode::HandleInitialDelay(
                                v8,
                                (AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition);
          v10 = v13;
          if ( v13 == 3 )
          {
            v10 = 1;
          }
          else if ( v13 == 1 )
          {
            v10 = ((unsigned int (__fastcall *)(CAkParameterNode *, CAkTransition **))v8->vfptr[19].Category)(
                    v8,
                    &in_rContParams.m_continuousParams.pPauseResumeTransition);
          }
          goto LABEL_20;
        }
      }
      else
      {
        v10 = 52;
      }
LABEL_20:
      AkContParamsAndPath::~AkContParamsAndPath(&in_rContParams);
      goto LABEL_21;
    }
    v9 = (unsigned int)CAkParameterNode::HandleInitialDelay(
                         v8,
                         (AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition);
    v10 = v9;
    if ( v9 != 3 )
    {
      if ( v9 == 1 )
        v10 = ((unsigned int (__fastcall *)(CAkParameterNode *, CAkTransition **))v8->vfptr[19].Category)(
                v8,
                &in_rContParams.m_continuousParams.pPauseResumeTransition);
LABEL_21:
      if ( v10 != 1 )
        goto LABEL_23;
      goto LABEL_22;
    }
    v10 = 1;
LABEL_22:
    ++v7;
LABEL_23:
    if ( v17 )
      AkExternalSourceArray::Release(v17);
    ++v6;
    if ( v6 == (CAkParameterNode **)&v2->m_mapChildId.m_pItems[v2->m_mapChildId.m_uLength] )
      break;
    v5 = v21;
  }
  if ( v7 >= 1 )
    v10 = 1;
  v4 = v10;
LABEL_29:
  if ( !v20 )
    goto LABEL_35;
  if ( !v7 )
  {
    v14 = CAkMultiPlayNode::PlayAndContinueAlternateMultiPlay((CAkMultiPlayNode *)&v2->vfptr, v3);
    goto LABEL_34;
  }
  if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
  {
    v14 = CAkMultiPlayNode::ContUnrefList(
            (CAkMultiPlayNode *)&v2->vfptr,
            in_rSafeContList.m_spBackupContinuationList.m_pT);
LABEL_34:
    v4 = v14;
LABEL_35:
    if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
      CAkContinuationList::Release(in_rSafeContList.m_spBackupContinuationList.m_pT);
  }
  return v4;
}

