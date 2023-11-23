// File Line: 27
// RVA: 0x3347E0
void __fastcall UFG::AIQuery::~AIQuery(UFG::AIQuery *this)
{
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable;
}

// File Line: 34
// RVA: 0x38C220
bool __fastcall UFG::AIQuery::Update(UFG::AIQuery *this, float *fDuration, int iSteps)
{
  unsigned __int64 Ticks; // rax
  unsigned __int64 v6; // rax

  this->m_bCanContinue = 1;
  this->m_uStartTicks = UFG::qGetTicks();
  this->m_fDuration = *fDuration;
  while ( !this->vfptr->IsCompleted(this) )
  {
    if ( !this->m_bCanContinue )
      break;
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    if ( this->m_bStateNeedsInit )
    {
      this->vfptr->StateInit(this, this->m_uState);
      this->m_bStateNeedsInit = 0;
    }
    this->vfptr->StateUpdate(this, this->m_uState);
  }
  v6 = UFG::qGetTicks();
  *fDuration = *fDuration - UFG::qGetTickTime(this->m_uStartTicks, v6);
  return !this->vfptr->IsCompleted(this);
}

