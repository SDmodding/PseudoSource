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
  UFG::TicketBooth *v1; // rbx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v2; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v3; // rax

  v1 = this;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)this);
  v2 = v1->mTickets.mNode.mPrev;
  v3 = v1->mTickets.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mTickets.mNode.mPrev = &v1->mTickets.mNode;
  v1->mTickets.mNode.mNext = &v1->mTickets.mNode;
}

// File Line: 77
// RVA: 0x2677E0
void __fastcall UFG::TicketBooth::Update(UFG::TicketBooth *this, float deltaTime)
{
  UFG::TicketBooth *v2; // rdi
  unsigned __int64 v3; // rax
  UFG::Ticket *v4; // rbp
  UFG::Ticket *v5; // rbx
  unsigned __int64 v6; // r14
  unsigned int v7; // esi
  unsigned __int64 v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::Ticket *v11; // rbx

  v2 = this;
  v3 = UFG::qGetTicks();
  v4 = v2->mpCurrentTicket;
  v5 = v2->mpCurrentTicket;
  v6 = v3;
  v7 = 0;
  if ( v2->mTicketQuota )
  {
    do
    {
      if ( !v5 )
        break;
      v5->mTimestamp;
      v5->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
      v5->mActiveCallback.m_Closure.m_pFunction(v5->mActiveCallback.m_Closure.m_pthis);
      v5 = (UFG::Ticket *)v5->mNext;
      if ( v5 == (UFG::Ticket *)v2 )
        v5 = (UFG::Ticket *)v2->mTickets.mNode.mNext;
      v2->mpCurrentTicket = v5;
      if ( v5 == v4 )
        v5 = 0i64;
      v8 = UFG::qGetTicks();
      v9 = UFG::qGetTickTime(v6, v8);
      v10 = v2->mTimeQuota;
      if ( v10 > 0.0 && v9 > (float)(v10 * 0.001) )
        break;
      ++v7;
    }
    while ( v7 < v2->mTicketQuota );
  }
  UFG::qGetTicks();
  if ( v2->mUpdateType == 1 )
  {
    v11 = v2->mpCurrentTicket;
    while ( v11 != v4 )
    {
      v11->mInactiveCallback.m_Closure.m_pFunction(v11->mInactiveCallback.m_Closure.m_pthis);
      v11 = (UFG::Ticket *)v11->mNext;
      if ( v11 == (UFG::Ticket *)v2 )
        v11 = (UFG::Ticket *)v2->mTickets.mNode.mNext;
    }
  }
}

