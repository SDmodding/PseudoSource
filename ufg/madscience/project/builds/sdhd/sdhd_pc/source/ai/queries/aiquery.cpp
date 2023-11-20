// File Line: 27
// RVA: 0x3347E0
void __fastcall UFG::AIQuery::~AIQuery(UFG::AIQuery *this)
{
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable';
}

// File Line: 34
// RVA: 0x38C220
bool __fastcall UFG::AIQuery::Update(UFG::AIQuery *this, float *fDuration, int iSteps)
{
  float *v3; // rdi
  UFG::AIQuery *v4; // rbx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rax

  v3 = fDuration;
  v4 = this;
  this->m_bCanContinue = 1;
  this->m_uStartTicks = UFG::qGetTicks();
  v4->m_fDuration = *v3;
  while ( !v4->vfptr->IsCompleted(v4) )
  {
    if ( !v4->m_bCanContinue )
      break;
    v5 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v4->m_uStartTicks, v5) >= v4->m_fDuration )
      break;
    if ( v4->m_bStateNeedsInit )
    {
      v4->vfptr->StateInit(v4, v4->m_uState);
      v4->m_bStateNeedsInit = 0;
    }
    v4->vfptr->StateUpdate(v4, v4->m_uState);
  }
  v6 = UFG::qGetTicks();
  *v3 = *v3 - UFG::qGetTickTime(v4->m_uStartTicks, v6);
  return v4->vfptr->IsCompleted(v4) == 0;
}

