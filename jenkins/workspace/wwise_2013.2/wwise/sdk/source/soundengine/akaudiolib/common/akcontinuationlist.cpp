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
  CAkContainerBaseInfo *m_pContainerInfo; // rcx
  CAkMultiPlayNode *m_pT; // rcx

  m_pContainerInfo = this->m_pContainerInfo;
  if ( m_pContainerInfo )
  {
    m_pContainerInfo->vfptr->Destroy(m_pContainerInfo);
    this->m_pContainerInfo = 0i64;
  }
  m_pT = this->m_pMultiPlayNode.m_pT;
  if ( m_pT )
  {
    m_pT->vfptr->Release(m_pT);
    this->m_pMultiPlayNode.m_pT = 0i64;
  }
  if ( this->m_pContainer.m_pT )
  {
    this->m_pContainer.m_pT->vfptr->Release(this->m_pContainer.m_pT);
    this->m_pContainer.m_pT = 0i64;
  }
}

// File Line: 42
// RVA: 0xA6F8A0
CAkContinueListItem *__fastcall CAkContinueListItem::operator=(
        CAkContinueListItem *this,
        CAkContinueListItem *in_listItem)
{
  CAkRanSeqCntr *m_pT; // rbx
  CAkRanSeqCntr *v5; // rcx
  CAkContainerBaseInfo *m_pContainerInfo; // rbx
  CAkContainerBaseInfoVtbl *vfptr; // rbx
  unsigned int PlaylistLength; // eax
  CAkMultiPlayNode *v9; // rbx
  CAkMultiPlayNode *v10; // rcx

  if ( in_listItem != this )
  {
    m_pT = in_listItem->m_pContainer.m_pT;
    if ( in_listItem->m_pContainer.m_pT )
      m_pT->vfptr->AddRef(in_listItem->m_pContainer.m_pT);
    v5 = this->m_pContainer.m_pT;
    this->m_pContainer.m_pT = m_pT;
    if ( v5 )
      v5->vfptr->Release(v5);
    m_pContainerInfo = in_listItem->m_pContainerInfo;
    if ( m_pContainerInfo )
    {
      vfptr = m_pContainerInfo->vfptr;
      PlaylistLength = CAkRanSeqCntr::GetPlaylistLength(this->m_pContainer.m_pT);
      this->m_pContainerInfo = vfptr->Clone(in_listItem->m_pContainerInfo, PlaylistLength);
    }
    else
    {
      this->m_pContainerInfo = 0i64;
    }
    this->m_LoopingInfo = in_listItem->m_LoopingInfo;
    v9 = in_listItem->m_pMultiPlayNode.m_pT;
    if ( v9 )
      v9->vfptr->AddRef(in_listItem->m_pMultiPlayNode.m_pT);
    v10 = this->m_pMultiPlayNode.m_pT;
    this->m_pMultiPlayNode.m_pT = v9;
    if ( v10 )
      v10->vfptr->Release(v10);
    this->m_pAlternateContList = in_listItem->m_pAlternateContList;
  }
  return this;
}

// File Line: 60
// RVA: 0xA6FA90
void __fastcall CAkContinuationList::Term(CAkContinuationList *this)
{
  CAkSmartPtr<CAkMultiPlayNode> *p_m_pMultiPlayNode; // rbx
  CAkContinuationList *m_pT; // rdx

  if ( this->m_listItems.m_pItems != &this->m_listItems.m_pItems[this->m_listItems.m_uLength] )
  {
    p_m_pMultiPlayNode = &this->m_listItems.m_pItems->m_pMultiPlayNode;
    do
    {
      if ( p_m_pMultiPlayNode->m_pT )
      {
        m_pT = (CAkContinuationList *)p_m_pMultiPlayNode[1].m_pT;
        if ( m_pT )
          CAkMultiPlayNode::ContUnrefList(p_m_pMultiPlayNode->m_pT, m_pT);
      }
      p_m_pMultiPlayNode += 5;
    }
    while ( &p_m_pMultiPlayNode[-3] != (CAkSmartPtr<CAkMultiPlayNode> *)&this->m_listItems.m_pItems[this->m_listItems.m_uLength] );
  }
  if ( this->m_listItems.m_pItems )
  {
    AkArray<CAkContinueListItem,CAkContinueListItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::RemoveAll(&this->m_listItems);
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_listItems.m_pItems);
    this->m_listItems.m_pItems = 0i64;
    this->m_listItems.m_ulReserved = 0;
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
  if ( this->m_iRefCount-- == 1 )
  {
    CAkContinuationList::Term(this);
    AK::MemoryMgr::Free(g_DefaultPoolId, this);
  }
}

