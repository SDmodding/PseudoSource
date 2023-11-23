// File Line: 35
// RVA: 0x3314A0
void __fastcall UFG::PedKnowledgeRecord::PedKnowledgeRecord(UFG::PedKnowledgeRecord *this)
{
  this->pSimObject.mPrev = &this->pSimObject;
  this->pSimObject.mNext = &this->pSimObject;
  this->pSimObject.m_pPointer = 0i64;
  this->m_uLastTimeSeen = 0i64;
  this->m_uLastLOSTest = 0i64;
  this->m_uLastPathTest = 0i64;
  *((_BYTE *)this + 48) &= 0xFCu;
  *((_BYTE *)this + 48) |= 4u;
}

// File Line: 76
// RVA: 0x33A160
void __fastcall UFG::PedKnowledgeBase::~PedKnowledgeBase(UFG::PedKnowledgeBase *this)
{
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mPrev; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mNext; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v4; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v5; // rax
  UFG::PedKnowledgeRecord *p; // rcx
  void *v7; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::Ticket *p_m_ticketUpdate; // [rsp+48h] [rbp+10h]

  p_m_ticketUpdate = &this->m_ticketUpdate;
  mPrev = this->m_ticketUpdate.mPrev;
  mNext = p_m_ticketUpdate->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_ticketUpdate->mPrev = p_m_ticketUpdate;
  p_m_ticketUpdate->mNext = p_m_ticketUpdate;
  v4 = this->m_ticketRefreshHostiles.mPrev;
  v5 = this->m_ticketRefreshHostiles.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->m_ticketRefreshHostiles.mPrev = &this->m_ticketRefreshHostiles;
  this->m_ticketRefreshHostiles.mNext = &this->m_ticketRefreshHostiles;
  p = this->m_aHostilePedRecords.p;
  if ( p )
  {
    v7 = (char *)&p[-1] + 48;
    `eh vector destructor iterator(
      p,
      0x38ui64,
      *((_DWORD *)&p[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v7);
  }
  this->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&this->m_aHostilePedRecords.size = 0i64;
  if ( this->m_pParentSimObject.m_pPointer )
  {
    v8 = this->m_pParentSimObject.mPrev;
    v9 = this->m_pParentSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pParentSimObject.mPrev = &this->m_pParentSimObject;
    this->m_pParentSimObject.mNext = &this->m_pParentSimObject;
  }
  this->m_pParentSimObject.m_pPointer = 0i64;
  v10 = this->m_pParentSimObject.mPrev;
  v11 = this->m_pParentSimObject.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->m_pParentSimObject.mPrev = &this->m_pParentSimObject;
  this->m_pParentSimObject.mNext = &this->m_pParentSimObject;
}

