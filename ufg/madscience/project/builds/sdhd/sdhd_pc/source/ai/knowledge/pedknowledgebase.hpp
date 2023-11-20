// File Line: 35
// RVA: 0x3314A0
void __fastcall UFG::PedKnowledgeRecord::PedKnowledgeRecord(UFG::PedKnowledgeRecord *this)
{
  this->pSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->pSimObject.mPrev;
  this->pSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->pSimObject.mPrev;
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
  UFG::PedKnowledgeBase *v1; // rdi
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v2; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v3; // rax
  UFG::Ticket *v4; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v5; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v6; // rax
  UFG::PedKnowledgeRecord *v7; // rcx
  char *v8; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::Ticket *v13; // [rsp+48h] [rbp+10h]

  v1 = this;
  v13 = &this->m_ticketUpdate;
  v2 = this->m_ticketUpdate.mPrev;
  v3 = v13->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v13->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v13->mPrev;
  v4 = &v1->m_ticketRefreshHostiles;
  v5 = v1->m_ticketRefreshHostiles.mPrev;
  v6 = v1->m_ticketRefreshHostiles.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v4->mPrev;
  v7 = v1->m_aHostilePedRecords.p;
  if ( v7 )
  {
    v8 = (char *)&v7[-1] + 48;
    `eh vector destructor iterator(
      v7,
      0x38ui64,
      *((_DWORD *)&v7[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v8);
  }
  v1->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&v1->m_aHostilePedRecords.size = 0i64;
  if ( v1->m_pParentSimObject.m_pPointer )
  {
    v9 = v1->m_pParentSimObject.mPrev;
    v10 = v1->m_pParentSimObject.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v1->m_pParentSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pParentSimObject.mPrev;
    v1->m_pParentSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pParentSimObject.mPrev;
  }
  v1->m_pParentSimObject.m_pPointer = 0i64;
  v11 = v1->m_pParentSimObject.mPrev;
  v12 = v1->m_pParentSimObject.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->m_pParentSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pParentSimObject.mPrev;
  v1->m_pParentSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pParentSimObject.mPrev;
}

