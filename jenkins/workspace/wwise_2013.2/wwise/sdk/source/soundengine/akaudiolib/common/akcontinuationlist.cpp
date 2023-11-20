// File Line: 29
// RVA: 0xA6F820
void __fastcall CAkContinueListItem::CAkContinueListItem(CAkContinueListItem *this)
{
  this->m_pContainer.m_pT = 0i64;
  this->m_pContainerInfo = 0i64;
  *((_BYTE *)&this->m_LoopingInfo + 2) &= 0xFCu;
  this->m_LoopingInfo.lLoopCount = 0;
  this->m_pMultiPlayNode.m_pT = 0i64;
  this->m_pAlternateContList = 0i64;
}

// File Line: 33
// RVA: 0xA6F840
void __fastcall CAkContinueListItem::~CAkContinueListItem(CAkContinueListItem *this)
{
  CAkContinueListItem *v1; // rbx
  CAkContainerBaseInfo *v2; // rcx
  CAkMultiPlayNode *v3; // rcx

  v1 = this;
  v2 = this->m_pContainerInfo;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Destroy)();
    v1->m_pContainerInfo = 0i64;
  }
  v3 = v1->m_pMultiPlayNode.m_pT;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_pMultiPlayNode.m_pT = 0i64;
  }
  if ( v1->m_pContainer.m_pT )
  {
    ((void (*)(void))v1->m_pContainer.m_pT->vfptr->Release)();
    v1->m_pContainer.m_pT = 0i64;
  }
}

// File Line: 42
// RVA: 0xA6F8A0
CAkContinueListItem *__fastcall CAkContinueListItem::operator=(CAkContinueListItem *this, CAkContinueListItem *in_listItem)
{
  CAkContinueListItem *v2; // rsi
  CAkContinueListItem *v3; // rdi
  CAkRanSeqCntr *v4; // rbx
  CAkRanSeqCntr *v5; // rcx
  CAkContainerBaseInfo *v6; // rbx
  CAkContainerBaseInfoVtbl *v7; // rbx
  unsigned int v8; // eax
  CAkMultiPlayNode *v9; // rbx
  CAkMultiPlayNode *v10; // rcx

  v2 = in_listItem;
  v3 = this;
  if ( in_listItem != this )
  {
    v4 = in_listItem->m_pContainer.m_pT;
    if ( in_listItem->m_pContainer.m_pT )
      v4->vfptr->AddRef((CAkIndexable *)&in_listItem->m_pContainer.m_pT->vfptr);
    v5 = v3->m_pContainer.m_pT;
    v3->m_pContainer.m_pT = v4;
    if ( v5 )
      ((void (*)(void))v5->vfptr->Release)();
    v6 = v2->m_pContainerInfo;
    if ( v6 )
    {
      v7 = v6->vfptr;
      v8 = CAkRanSeqCntr::GetPlaylistLength(v3->m_pContainer.m_pT);
      v3->m_pContainerInfo = v7->Clone(v2->m_pContainerInfo, v8);
    }
    else
    {
      v3->m_pContainerInfo = 0i64;
    }
    v3->m_LoopingInfo = v2->m_LoopingInfo;
    v9 = v2->m_pMultiPlayNode.m_pT;
    if ( v9 )
      v9->vfptr->AddRef((CAkIndexable *)&v2->m_pMultiPlayNode.m_pT->vfptr);
    v10 = v3->m_pMultiPlayNode.m_pT;
    v3->m_pMultiPlayNode.m_pT = v9;
    if ( v10 )
      ((void (*)(void))v10->vfptr->Release)();
    v3->m_pAlternateContList = v2->m_pAlternateContList;
  }
  return v3;
}

// File Line: 60
// RVA: 0xA6FA90
void __fastcall CAkContinuationList::Term(CAkContinuationList *this)
{
  CAkContinuationList *v1; // rdi
  CAkSmartPtr<CAkMultiPlayNode> *v2; // rbx
  CAkContinuationList *v3; // rdx

  v1 = this;
  if ( this->m_listItems.m_pItems != &this->m_listItems.m_pItems[this->m_listItems.m_uLength] )
  {
    v2 = &this->m_listItems.m_pItems->m_pMultiPlayNode;
    do
    {
      if ( v2->m_pT )
      {
        v3 = (CAkContinuationList *)v2[1].m_pT;
        if ( v3 )
          CAkMultiPlayNode::ContUnrefList(v2->m_pT, v3);
      }
      v2 += 5;
    }
    while ( &v2[-3] != (CAkSmartPtr<CAkMultiPlayNode> *)&v1->m_listItems.m_pItems[v1->m_listItems.m_uLength] );
  }
  if ( v1->m_listItems.m_pItems )
  {
    AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::RemoveAll(&v1->m_listItems);
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_listItems.m_pItems);
    v1->m_listItems.m_pItems = 0i64;
    v1->m_listItems.m_ulReserved = 0;
  }
}

// File Line: 81
// RVA: 0xA6F970
CAkContinuationList *__fastcall CAkContinuationList::Create()
{
  CAkContinuationList *result; // rax

  result = (CAkContinuationList *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x18ui64);
  if ( !result )
    return 0i64;
  result->m_listItems.m_pItems = 0i64;
  *(_QWORD *)&result->m_listItems.m_uLength = 0i64;
  result->m_iRefCount = 1;
  return result;
}

// File Line: 86
// RVA: 0xA6F960
void __fastcall CAkContinuationList::AddRef(CAkContinuationList *this)
{
  ++this->m_iRefCount;
}

// File Line: 90
// RVA: 0xA6F9B0
void __fastcall CAkContinuationList::Release(CAkContinuationList *this)
{
  bool v1; // zf
  CAkContinuationList *v2; // rbx

  v1 = this->m_iRefCount-- == 1;
  v2 = this;
  if ( v1 )
  {
    CAkContinuationList::Term(this);
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
  }
}

