// File Line: 31
// RVA: 0xA8D690
void __fastcall CAkLayerCntr::~CAkLayerCntr(CAkLayerCntr *this)
{
  CAkLayer **m_pItems; // rbx
  CAkLayer **i; // rdi
  CAkLayer **v4; // rdx

  m_pItems = this->m_layers.m_pItems;
  this->vfptr = (CAkIndexableVtbl *)&CAkLayerCntr::`vftable;
  for ( i = &m_pItems[this->m_layers.m_uLength]; m_pItems != i; ++m_pItems )
  {
    CAkLayer::SetOwner(*m_pItems, 0i64);
    (*m_pItems)->vfptr->Release(*m_pItems);
  }
  v4 = this->m_layers.m_pItems;
  if ( v4 )
  {
    this->m_layers.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    this->m_layers.m_pItems = 0i64;
    this->m_layers.m_ulReserved = 0;
  }
  CAkMultiPlayNode::Term(this);
  CAkMultiPlayNode::~CAkMultiPlayNode(this);
}

// File Line: 47
// RVA: 0xA8DB50
__int64 __fastcall CAkLayerCntr::SetInitialValues(CAkLayerCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  __int64 result; // rax
  unsigned int v5; // r14d
  char *v6; // rcx
  int v7; // edi
  CAkLayer *v8; // rax
  CAkLayer *v9; // rbx
  unsigned int v10; // esi
  char *io_rpData; // [rsp+48h] [rbp+10h] BYREF
  unsigned int io_rulDataSize; // [rsp+50h] [rbp+18h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  result = CAkParameterNodeBase::SetNodeBaseParams(this, &io_rpData, &io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
  {
    result = CAkParentNode<CAkParameterNode>::SetChildren(this, &io_rpData, &io_rulDataSize);
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
          CAkLayer::SetOwner(v8, this);
          v10 = CAkLayer::SetInitialValues(v9, &io_rpData, &io_rulDataSize);
          if ( v10 != 1 )
            break;
          if ( !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
                  (AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&this->m_layers,
                  (ITransitionable *)v9) )
          {
            v9->vfptr->Release(v9);
            return 2i64;
          }
          if ( ++v7 >= v5 )
            return v10;
          v6 = io_rpData;
        }
        v9->vfptr->Release(v9);
        return v10;
      }
    }
  }
  return result;
}

// File Line: 116
// RVA: 0xA8D760
__int64 __fastcall CAkLayerCntr::AddChild(CAkLayerCntr *this, WwiseObjectIDext in_ulID)
{
  __int64 result; // rax
  CAkParameterNodeBase *NodePtrAndAddRef; // rdx
  CAkLayer **m_pItems; // rbx
  CAkLayer **v6; // rdi
  unsigned int in_ChildID; // [rsp+38h] [rbp+10h]

  in_ChildID = in_ulID.id;
  if ( !in_ulID.id )
    return 14i64;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ulID.id, AkNodeType_Default);
  if ( !NodePtrAndAddRef )
    return 15i64;
  result = ((__int64 (__fastcall *)(CAkLayerCntr *, CAkParameterNodeBase *))this->vfptr[2].AddRef)(
             this,
             NodePtrAndAddRef);
  if ( (_DWORD)result == 1 )
  {
    m_pItems = this->m_layers.m_pItems;
    v6 = &m_pItems[this->m_layers.m_uLength];
    if ( m_pItems != v6 )
    {
      do
        CAkLayer::UpdateChildPtr(*m_pItems++, in_ChildID);
      while ( m_pItems != v6 );
      return 1i64;
    }
  }
  return result;
}

// File Line: 135
// RVA: 0xA8DAC0
void __fastcall CAkLayerCntr::RemoveChild(CAkLayerCntr *this, CAkParameterNodeBase *in_pChild)
{
  CAkLayer **m_pItems; // rbx
  CAkLayer **i; // rdi

  m_pItems = this->m_layers.m_pItems;
  for ( i = &m_pItems[this->m_layers.m_uLength]; m_pItems != i; ++m_pItems )
    CAkLayer::UnsetChildAssoc(*m_pItems, in_pChild->key);
  if ( in_pChild->m_pParentNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[1].Release)(in_pChild, 0i64);
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      &this->m_mapChildId,
      in_pChild->key);
    this->vfptr->Release(this);
  }
}

// File Line: 148
// RVA: 0xA8D800
CAkLayerCntr *__fastcall CAkLayerCntr::Create(unsigned int in_ulID)
{
  CAkMultiPlayNode *v2; // rax
  CAkMultiPlayNode *v3; // rbx

  v2 = (CAkMultiPlayNode *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC8ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkMultiPlayNode::CAkMultiPlayNode(v2, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkLayerCntr::`vftable;
  v3[1].vfptr = 0i64;
  v3[1].pNextItem = 0i64;
  if ( CAkMultiPlayNode::Init(v3) == AK_Success )
    return (CAkLayerCntr *)v3;
  v3->vfptr->Release(v3);
  return 0i64;
}

// File Line: 167
// RVA: 0xA8D890
__int64 __fastcall CAkLayerCntr::PlayInternal(CAkLayerCntr *this, AkPBIParams *in_rPBIParams)
{
  unsigned int v4; // r14d
  unsigned int v5; // edi
  CAkParameterNodeBase **m_pItems; // rbx
  int v7; // r12d
  CAkParameterNode *v8; // rsi
  AKRESULT v9; // eax
  AKRESULT v10; // edi
  CAkContinuationList *v11; // rax
  CAkContinuationList *m_pT; // rcx
  AKRESULT v13; // eax
  AKRESULT v14; // eax
  AkContParamsAndPath in_rContParams; // [rsp+20h] [rbp-81h] BYREF
  AkExternalSourceArray *v17; // [rsp+58h] [rbp-49h]
  AkContParamsAndPath *p_in_rContParams; // [rsp+B8h] [rbp+17h]
  int v19; // [rsp+C0h] [rbp+1Fh]
  bool v20; // [rsp+108h] [rbp+67h]
  unsigned int m_uLength; // [rsp+110h] [rbp+6Fh]
  SafeContinuationList in_rSafeContList; // [rsp+118h] [rbp+77h] BYREF

  v20 = in_rPBIParams->eType != PBI;
  v4 = 1;
  SafeContinuationList::SafeContinuationList(&in_rSafeContList, in_rPBIParams, this);
  m_pItems = this->m_mapChildId.m_pItems;
  v7 = 0;
  m_uLength = this->m_mapChildId.m_uLength;
  v5 = m_uLength;
  if ( m_pItems == &m_pItems[m_uLength] )
    goto LABEL_29;
  while ( 1 )
  {
    v8 = (CAkParameterNode *)*m_pItems;
    AkPBIParams::AkPBIParams((AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition, in_rPBIParams);
    if ( v20 )
    {
      AkContParamsAndPath::AkContParamsAndPath(&in_rContParams, &p_in_rContParams->m_continuousParams);
      if ( v5 == 1 )
      {
        CAkMultiPlayNode::ContGetList(
          this,
          p_in_rContParams->m_continuousParams.spContList.m_pT,
          &in_rContParams.m_continuousParams.spContList);
        goto LABEL_15;
      }
      v19 = 0;
      v11 = CAkContinuationList::Create();
      m_pT = in_rContParams.m_continuousParams.spContList.m_pT;
      in_rContParams.m_continuousParams.spContList.m_pT = v11;
      if ( m_pT )
      {
        CAkContinuationList::Release(m_pT);
        v11 = in_rContParams.m_continuousParams.spContList.m_pT;
      }
      if ( v11 )
      {
        v10 = CAkMultiPlayNode::AddMultiplayItem(
                this,
                &in_rContParams,
                (AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition,
                &in_rSafeContList);
        if ( v10 == AK_Success )
        {
LABEL_15:
          p_in_rContParams = &in_rContParams;
          v13 = (unsigned int)CAkParameterNode::HandleInitialDelay(
                                v8,
                                (AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition);
          v10 = v13;
          if ( v13 == AK_PartialSuccess )
          {
            v10 = AK_Success;
          }
          else if ( v13 == AK_Success )
          {
            v10 = ((unsigned int (__fastcall *)(CAkParameterNode *, CAkTransition **))v8->vfptr[19].Category)(
                    v8,
                    &in_rContParams.m_continuousParams.pPauseResumeTransition);
          }
        }
      }
      else
      {
        v10 = AK_InsufficientMemory;
      }
      AkContParamsAndPath::~AkContParamsAndPath(&in_rContParams);
      goto LABEL_21;
    }
    v9 = (unsigned int)CAkParameterNode::HandleInitialDelay(
                         v8,
                         (AkPBIParams *)&in_rContParams.m_continuousParams.pPauseResumeTransition);
    v10 = v9;
    if ( v9 != AK_PartialSuccess )
    {
      if ( v9 == AK_Success )
        v10 = ((unsigned int (__fastcall *)(CAkParameterNode *, CAkTransition **))v8->vfptr[19].Category)(
                v8,
                &in_rContParams.m_continuousParams.pPauseResumeTransition);
LABEL_21:
      if ( v10 != AK_Success )
        goto LABEL_23;
      goto LABEL_22;
    }
    v10 = AK_Success;
LABEL_22:
    ++v7;
LABEL_23:
    if ( v17 )
      AkExternalSourceArray::Release(v17);
    if ( ++m_pItems == &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] )
      break;
    v5 = m_uLength;
  }
  if ( v7 )
    v10 = AK_Success;
  v4 = v10;
LABEL_29:
  if ( !v20 )
    goto LABEL_35;
  if ( !v7 )
  {
    v14 = CAkMultiPlayNode::PlayAndContinueAlternateMultiPlay(this, in_rPBIParams);
    goto LABEL_34;
  }
  if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
  {
    v14 = CAkMultiPlayNode::ContUnrefList(this, in_rSafeContList.m_spBackupContinuationList.m_pT);
LABEL_34:
    v4 = v14;
LABEL_35:
    if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
      CAkContinuationList::Release(in_rSafeContList.m_spBackupContinuationList.m_pT);
  }
  return v4;
}

