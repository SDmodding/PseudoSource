// File Line: 14
// RVA: 0x2674A0
void __fastcall UFG::TicketBoothManager::TicketBoothManager(UFG::TicketBoothManager *this)
{
  UFG::TicketBoothManager *v1; // rbx
  signed __int64 v2; // rax
  signed __int64 v3; // rax
  signed __int64 v4; // rax
  signed __int64 v5; // rax
  signed __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  signed __int64 v10; // rax

  v1 = this;
  `eh vector constructor iterator'(this, 0x28ui64, 10, (void (__fastcall *)(void *))UFG::TicketBooth::TicketBooth);
  v1->mBooths[0].mTickets.mNode.mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)v1;
  v1->mBooths[0].mTickets.mNode.mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)v1;
  v1->mBooths[0].mpCurrentTicket = 0i64;
  v1->mBooths[0].mUpdateType = 0;
  v1->mBooths[0].mTicketQuota = 10;
  v1->mBooths[0].mTimeQuota = -1.0;
  v2 = (signed __int64)&v1->mBooths[1];
  *(_QWORD *)v2 = v2;
  *(_QWORD *)(v2 + 8) = v2;
  *(_QWORD *)(v2 + 16) = 0i64;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 9999;
  *(_DWORD *)(v2 + 32) = -1082130432;
  v3 = (signed __int64)&v1->mBooths[2];
  *(_QWORD *)v3 = v3;
  *(_QWORD *)(v3 + 8) = v3;
  *(_QWORD *)(v3 + 16) = 0i64;
  *(_DWORD *)(v3 + 24) = 1;
  *(_DWORD *)(v3 + 28) = 25;
  *(_DWORD *)(v3 + 32) = -1082130432;
  v4 = (signed __int64)&v1->mBooths[3];
  *(_QWORD *)v4 = v4;
  *(_QWORD *)(v4 + 8) = v4;
  *(_QWORD *)(v4 + 16) = 0i64;
  *(_DWORD *)(v4 + 24) = 0;
  *(_DWORD *)(v4 + 28) = 9999;
  *(_DWORD *)(v4 + 32) = -1082130432;
  v5 = (signed __int64)&v1->mBooths[4];
  *(_QWORD *)v5 = v5;
  *(_QWORD *)(v5 + 8) = v5;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_DWORD *)(v5 + 24) = 1;
  *(_DWORD *)(v5 + 28) = 25;
  *(_DWORD *)(v5 + 32) = -1082130432;
  v6 = (signed __int64)&v1->mBooths[5];
  *(_QWORD *)v6 = v6;
  *(_QWORD *)(v6 + 8) = v6;
  *(_QWORD *)(v6 + 16) = 0i64;
  *(_DWORD *)(v6 + 24) = 0;
  *(_DWORD *)(v6 + 28) = 9999;
  *(_DWORD *)(v6 + 32) = -1082130432;
  v7 = (signed __int64)&v1->mBooths[6];
  *(_QWORD *)v7 = v7;
  *(_QWORD *)(v7 + 8) = v7;
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_DWORD *)(v7 + 24) = 0;
  *(_DWORD *)(v7 + 28) = 3;
  *(_DWORD *)(v7 + 32) = -1082130432;
  v8 = (signed __int64)&v1->mBooths[7];
  *(_QWORD *)v8 = v8;
  *(_QWORD *)(v8 + 8) = v8;
  *(_QWORD *)(v8 + 16) = 0i64;
  *(_DWORD *)(v8 + 24) = 0;
  *(_DWORD *)(v8 + 28) = 15;
  *(_DWORD *)(v8 + 32) = -1082130432;
  v9 = (signed __int64)&v1->mBooths[8];
  *(_QWORD *)v9 = v9;
  *(_QWORD *)(v9 + 8) = v9;
  *(_QWORD *)(v9 + 16) = 0i64;
  *(_DWORD *)(v9 + 24) = 0;
  *(_DWORD *)(v9 + 28) = 3;
  *(_DWORD *)(v9 + 32) = -1082130432;
  v10 = (signed __int64)&v1->mBooths[9];
  *(_QWORD *)v10 = v10;
  *(_QWORD *)(v10 + 8) = v10;
  *(_QWORD *)(v10 + 16) = 0i64;
  *(_DWORD *)(v10 + 24) = 0;
  *(_DWORD *)(v10 + 28) = 10;
  *(_DWORD *)(v10 + 32) = -1082130432;
}

// File Line: 28
// RVA: 0x267680
void UFG::TicketBoothManager::Initialize(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::TicketBoothManager *v1; // rax

  v0 = UFG::qMalloc(0x190ui64, "TicketBoothManager", 0i64);
  if ( v0 )
  {
    UFG::TicketBoothManager::TicketBoothManager((UFG::TicketBoothManager *)v0);
    UFG::TicketBoothManager::mpSingleton = v1;
  }
  else
  {
    UFG::TicketBoothManager::mpSingleton = 0i64;
  }
}

// File Line: 41
// RVA: 0x2676D0
void __fastcall UFG::TicketBoothManager::Register(UFG::TicketBoothManager *this, UFG::eTicketBoothEnum booth, UFG::Ticket *pTicket, fastdelegate::FastDelegate1<float,void> *callback)
{
  void (__fastcall *v4)(fastdelegate::detail::GenericClass *); // r10
  fastdelegate::detail::GenericClass *v5; // r11
  unsigned __int64 v6; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v7; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v8; // r9

  v4 = callback->m_Closure.m_pFunction;
  v5 = callback->m_Closure.m_pthis;
  v6 = 5i64 * (signed int)booth;
  pTicket->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  pTicket->mActiveCallback.m_Closure.m_pFunction = v4;
  pTicket->mActiveCallback.m_Closure.m_pthis = v5;
  v7 = this->mBooths[v6 / 5].mTickets.mNode.mPrev;
  v8 = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)((char *)this + 8 * v6);
  v7->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
  pTicket->mPrev = v7;
  pTicket->mNext = v8;
  v8->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
  if ( !v8[1].mPrev )
    v8[1].mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
}

// File Line: 46
// RVA: 0x267720
void __fastcall UFG::TicketBoothManager::Register(UFG::TicketBoothManager *this, UFG::eTicketBoothEnum booth, UFG::Ticket *pTicket, fastdelegate::FastDelegate1<float,void> *activeCallback, fastdelegate::FastDelegate0<void> *inactiveCallback)
{
  void (__fastcall *v5)(fastdelegate::detail::GenericClass *); // r10
  fastdelegate::detail::GenericClass *v6; // r9
  void (__fastcall *v7)(fastdelegate::detail::GenericClass *); // r11
  fastdelegate::detail::GenericClass *v8; // rbx
  unsigned __int64 v9; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v10; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v11; // rcx

  v5 = activeCallback->m_Closure.m_pFunction;
  v6 = activeCallback->m_Closure.m_pthis;
  v7 = inactiveCallback->m_Closure.m_pFunction;
  v8 = inactiveCallback->m_Closure.m_pthis;
  v9 = 5i64 * (signed int)booth;
  pTicket->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  pTicket->mActiveCallback.m_Closure.m_pFunction = v5;
  pTicket->mActiveCallback.m_Closure.m_pthis = v6;
  pTicket->mInactiveCallback.m_Closure.m_pFunction = v7;
  pTicket->mInactiveCallback.m_Closure.m_pthis = v8;
  v10 = this->mBooths[v9 / 5].mTickets.mNode.mPrev;
  v11 = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)((char *)this + 8 * v9);
  v10->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
  pTicket->mPrev = v10;
  pTicket->mNext = v11;
  v11->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
  if ( !v11[1].mPrev )
    v11[1].mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
}

// File Line: 51
// RVA: 0x267790
void __fastcall UFG::TicketBoothManager::Unregister(UFG::TicketBoothManager *this, UFG::eTicketBoothEnum booth, UFG::Ticket *pTicket)
{
  UFG::TicketBooth *v3; // r9
  UFG::TicketBooth *v4; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v5; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v6; // rax

  v3 = &this->mBooths[booth];
  if ( v3->mpCurrentTicket == pTicket )
  {
    v4 = (UFG::TicketBooth *)pTicket->mNext;
    if ( v4 == v3 )
      v4 = (UFG::TicketBooth *)v3->mTickets.mNode.mNext;
    if ( v4 == (UFG::TicketBooth *)pTicket )
      v4 = 0i64;
    v3->mpCurrentTicket = (UFG::Ticket *)v4;
  }
  v5 = pTicket->mPrev;
  v6 = pTicket->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  pTicket->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
  pTicket->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&pTicket->mPrev;
}

// File Line: 56
// RVA: 0x267920
void __fastcall UFG::TicketBoothManager::UpdateBooth(UFG::TicketBoothManager *this, UFG::eTicketBoothEnum booth, float deltaTime)
{
  UFG::TicketBooth::Update(&this->mBooths[booth], deltaTime);
}

