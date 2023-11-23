// File Line: 14
// RVA: 0x267470
void __fastcall UFG::TicketBooth::TicketBooth(UFG::TicketBooth *this)
{
  this->mTickets.mNode.mPrev = &this->mTickets.mNode;
  this->mTickets.mNode.mNext = &this->mTickets.mNode;
}

// File Line: 18
// RVA: 0x267640
void __fastcall UFG::TicketBooth::~TicketBooth(UFG::TicketBooth *this)
{
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mPrev; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mNext; // rax

  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)this);
  mPrev = this->mTickets.mNode.mPrev;
  mNext = this->mTickets.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mTickets.mNode.mPrev = &this->mTickets.mNode;
  this->mTickets.mNode.mNext = &this->mTickets.mNode;
}

// File Line: 77
// RVA: 0x2677E0
void __fastcall UFG::TicketBooth::Update(UFG::TicketBooth *this, float deltaTime)
{
  unsigned __int64 Ticks; // rax
  UFG::Ticket *mpCurrentTicket; // rbp
  UFG::qNode<UFG::Ticket,UFG::Ticket> *mNext; // rbx
  unsigned __int64 v6; // r14
  unsigned int i; // esi
  unsigned __int64 v8; // rax
  float TickTime; // xmm0_4
  float mTimeQuota; // xmm1_4
  UFG::Ticket *v11; // rbx

  Ticks = UFG::qGetTicks();
  mpCurrentTicket = this->mpCurrentTicket;
  mNext = mpCurrentTicket;
  v6 = Ticks;
  for ( i = 0; i < this->mTicketQuota; ++i )
  {
    if ( !mNext )
      break;
    mNext[1].mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)UFG::Metrics::msInstance.mSimTimeMSec;
    ((void (__fastcall *)(UFG::qNode<UFG::Ticket,UFG::Ticket> *))mNext[2].mPrev)(mNext[1].mNext);
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::Ticket,UFG::Ticket> *)this )
      mNext = this->mTickets.mNode.mNext;
    this->mpCurrentTicket = (UFG::Ticket *)mNext;
    if ( mNext == mpCurrentTicket )
      mNext = 0i64;
    v8 = UFG::qGetTicks();
    TickTime = UFG::qGetTickTime(v6, v8);
    mTimeQuota = this->mTimeQuota;
    if ( mTimeQuota > 0.0 && TickTime > (float)(mTimeQuota * 0.001) )
      break;
  }
  UFG::qGetTicks();
  if ( this->mUpdateType == AllTickets )
  {
    v11 = this->mpCurrentTicket;
    while ( v11 != mpCurrentTicket )
    {
      v11->mInactiveCallback.m_Closure.m_pFunction(v11->mInactiveCallback.m_Closure.m_pthis);
      v11 = (UFG::Ticket *)v11->mNext;
      if ( v11 == (UFG::Ticket *)this )
        v11 = (UFG::Ticket *)this->mTickets.mNode.mNext;
    }
  }
}

