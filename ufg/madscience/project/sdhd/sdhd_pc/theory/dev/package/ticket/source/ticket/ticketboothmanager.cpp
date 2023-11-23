// File Line: 14
// RVA: 0x2674A0
void __fastcall UFG::TicketBoothManager::TicketBoothManager(UFG::TicketBoothManager *this)
{
  `eh vector constructor iterator(this, 0x28ui64, 10, (void (__fastcall *)(void *))UFG::TicketBooth::TicketBooth);
  this->mBooths[0].mTickets.mNode.mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)this;
  this->mBooths[0].mTickets.mNode.mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)this;
  this->mBooths[0].mpCurrentTicket = 0i64;
  this->mBooths[0].mUpdateType = ActiveTickets;
  this->mBooths[0].mTicketQuota = 10;
  this->mBooths[0].mTimeQuota = -1.0;
  this->mBooths[1].mTickets.mNode.mPrev = &this->mBooths[1].mTickets.mNode;
  this->mBooths[1].mTickets.mNode.mNext = &this->mBooths[1].mTickets.mNode;
  this->mBooths[1].mpCurrentTicket = 0i64;
  this->mBooths[1].mUpdateType = ActiveTickets;
  this->mBooths[1].mTicketQuota = 9999;
  this->mBooths[1].mTimeQuota = -1.0;
  this->mBooths[2].mTickets.mNode.mPrev = &this->mBooths[2].mTickets.mNode;
  this->mBooths[2].mTickets.mNode.mNext = &this->mBooths[2].mTickets.mNode;
  this->mBooths[2].mpCurrentTicket = 0i64;
  this->mBooths[2].mUpdateType = AllTickets;
  this->mBooths[2].mTicketQuota = 25;
  this->mBooths[2].mTimeQuota = -1.0;
  this->mBooths[3].mTickets.mNode.mPrev = &this->mBooths[3].mTickets.mNode;
  this->mBooths[3].mTickets.mNode.mNext = &this->mBooths[3].mTickets.mNode;
  this->mBooths[3].mpCurrentTicket = 0i64;
  this->mBooths[3].mUpdateType = ActiveTickets;
  this->mBooths[3].mTicketQuota = 9999;
  this->mBooths[3].mTimeQuota = -1.0;
  this->mBooths[4].mTickets.mNode.mPrev = &this->mBooths[4].mTickets.mNode;
  this->mBooths[4].mTickets.mNode.mNext = &this->mBooths[4].mTickets.mNode;
  this->mBooths[4].mpCurrentTicket = 0i64;
  this->mBooths[4].mUpdateType = AllTickets;
  this->mBooths[4].mTicketQuota = 25;
  this->mBooths[4].mTimeQuota = -1.0;
  this->mBooths[5].mTickets.mNode.mPrev = &this->mBooths[5].mTickets.mNode;
  this->mBooths[5].mTickets.mNode.mNext = &this->mBooths[5].mTickets.mNode;
  this->mBooths[5].mpCurrentTicket = 0i64;
  this->mBooths[5].mUpdateType = ActiveTickets;
  this->mBooths[5].mTicketQuota = 9999;
  this->mBooths[5].mTimeQuota = -1.0;
  this->mBooths[6].mTickets.mNode.mPrev = &this->mBooths[6].mTickets.mNode;
  this->mBooths[6].mTickets.mNode.mNext = &this->mBooths[6].mTickets.mNode;
  this->mBooths[6].mpCurrentTicket = 0i64;
  this->mBooths[6].mUpdateType = ActiveTickets;
  this->mBooths[6].mTicketQuota = 3;
  this->mBooths[6].mTimeQuota = -1.0;
  this->mBooths[7].mTickets.mNode.mPrev = &this->mBooths[7].mTickets.mNode;
  this->mBooths[7].mTickets.mNode.mNext = &this->mBooths[7].mTickets.mNode;
  this->mBooths[7].mpCurrentTicket = 0i64;
  this->mBooths[7].mUpdateType = ActiveTickets;
  this->mBooths[7].mTicketQuota = 15;
  this->mBooths[7].mTimeQuota = -1.0;
  this->mBooths[8].mTickets.mNode.mPrev = &this->mBooths[8].mTickets.mNode;
  this->mBooths[8].mTickets.mNode.mNext = &this->mBooths[8].mTickets.mNode;
  this->mBooths[8].mpCurrentTicket = 0i64;
  this->mBooths[8].mUpdateType = ActiveTickets;
  this->mBooths[8].mTicketQuota = 3;
  this->mBooths[8].mTimeQuota = -1.0;
  this->mBooths[9].mTickets.mNode.mPrev = &this->mBooths[9].mTickets.mNode;
  this->mBooths[9].mTickets.mNode.mNext = &this->mBooths[9].mTickets.mNode;
  this->mBooths[9].mpCurrentTicket = 0i64;
  this->mBooths[9].mUpdateType = ActiveTickets;
  this->mBooths[9].mTicketQuota = 10;
  this->mBooths[9].mTimeQuota = -1.0;
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
void __fastcall UFG::TicketBoothManager::Register(
        UFG::TicketBoothManager *this,
        int booth,
        UFG::Ticket *pTicket,
        fastdelegate::FastDelegate1<float,void> *callback)
{
  void (__fastcall *m_pFunction)(fastdelegate::detail::GenericClass *); // r10
  fastdelegate::detail::GenericClass *m_pthis; // r11
  unsigned __int64 v6; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mPrev; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v8; // r9

  m_pFunction = callback->m_Closure.m_pFunction;
  m_pthis = callback->m_Closure.m_pthis;
  v6 = 5i64 * booth;
  pTicket->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  pTicket->mActiveCallback.m_Closure.m_pFunction = m_pFunction;
  pTicket->mActiveCallback.m_Closure.m_pthis = m_pthis;
  mPrev = this->mBooths[v6 / 5].mTickets.mNode.mPrev;
  v8 = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)((char *)this + 8 * v6);
  mPrev->mNext = pTicket;
  pTicket->mPrev = mPrev;
  pTicket->mNext = v8;
  v8->mPrev = pTicket;
  if ( !v8[1].mPrev )
    v8[1].mPrev = pTicket;
}

// File Line: 46
// RVA: 0x267720
void __fastcall UFG::TicketBoothManager::Register(
        UFG::TicketBoothManager *this,
        int booth,
        UFG::Ticket *pTicket,
        fastdelegate::FastDelegate1<float,void> *activeCallback,
        fastdelegate::FastDelegate0<void> *inactiveCallback)
{
  void (__fastcall *m_pFunction)(fastdelegate::detail::GenericClass *); // r10
  fastdelegate::detail::GenericClass *m_pthis; // r9
  void (__fastcall *v7)(fastdelegate::detail::GenericClass *); // r11
  fastdelegate::detail::GenericClass *v8; // rbx
  unsigned __int64 v9; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mPrev; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v11; // rcx

  m_pFunction = activeCallback->m_Closure.m_pFunction;
  m_pthis = activeCallback->m_Closure.m_pthis;
  v7 = inactiveCallback->m_Closure.m_pFunction;
  v8 = inactiveCallback->m_Closure.m_pthis;
  v9 = 5i64 * booth;
  pTicket->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  pTicket->mActiveCallback.m_Closure.m_pFunction = m_pFunction;
  pTicket->mActiveCallback.m_Closure.m_pthis = m_pthis;
  pTicket->mInactiveCallback.m_Closure.m_pFunction = v7;
  pTicket->mInactiveCallback.m_Closure.m_pthis = v8;
  mPrev = this->mBooths[v9 / 5].mTickets.mNode.mPrev;
  v11 = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)((char *)this + 8 * v9);
  mPrev->mNext = pTicket;
  pTicket->mPrev = mPrev;
  pTicket->mNext = v11;
  v11->mPrev = pTicket;
  if ( !v11[1].mPrev )
    v11[1].mPrev = pTicket;
}

// File Line: 51
// RVA: 0x267790
void __fastcall UFG::TicketBoothManager::Unregister(
        UFG::TicketBoothManager *this,
        UFG::eTicketBoothEnum booth,
        UFG::Ticket *pTicket)
{
  UFG::TicketBooth *v3; // r9
  UFG::TicketBooth *mNext; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mPrev; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v6; // rax

  v3 = &this->mBooths[booth];
  if ( v3->mpCurrentTicket == pTicket )
  {
    mNext = (UFG::TicketBooth *)pTicket->mNext;
    if ( mNext == v3 )
      mNext = (UFG::TicketBooth *)v3->mTickets.mNode.mNext;
    if ( mNext == (UFG::TicketBooth *)pTicket )
      mNext = 0i64;
    v3->mpCurrentTicket = (UFG::Ticket *)mNext;
  }
  mPrev = pTicket->mPrev;
  v6 = pTicket->mNext;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  pTicket->mPrev = pTicket;
  pTicket->mNext = pTicket;
}

// File Line: 56
// RVA: 0x267920
void __fastcall UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager *this,
        UFG::eTicketBoothEnum booth,
        float deltaTime)
{
  UFG::TicketBooth::Update(&this->mBooths[booth], deltaTime);
}

