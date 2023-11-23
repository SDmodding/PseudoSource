// File Line: 72
// RVA: 0x32DAF0
void __fastcall UFG::AICoverQuery::CoverQueryRecord::CoverQueryRecord(UFG::AICoverQuery::CoverQueryRecord *this)
{
  this->m_pCoverPosition = 0i64;
  this->m_bPathFound = 0;
  this->vfptr = (UFG::AICoverQuery::CoverQueryRecordVtbl *)&UFG::AICoverQuery::CoverQueryRecord::`vftable;
}

// File Line: 73
// RVA: 0x335F60
void __fastcall UFG::AICoverQuery::CoverQueryRecord::~CoverQueryRecord(UFG::AICoverQuery::CoverQueryRecord *this)
{
  UFG::CoverPosition *m_pCoverPosition; // rcx

  this->vfptr = (UFG::AICoverQuery::CoverQueryRecordVtbl *)&UFG::AICoverQuery::CoverQueryRecord::`vftable;
  m_pCoverPosition = this->m_pCoverPosition;
  if ( m_pCoverPosition )
  {
    if ( m_pCoverPosition->m_iRefCount-- == 1 )
      m_pCoverPosition->vfptr->__vecDelDtor(m_pCoverPosition, 1u);
    this->m_pCoverPosition = 0i64;
  }
  this->m_bPathFound = 0;
}

// File Line: 179
// RVA: 0x369F70
bool __fastcall UFG::AICoverQuery::IsCompleted(UFG::AICoverQuery *this)
{
  return this->m_uState - 13 <= 1;
}

// File Line: 184
// RVA: 0x388FA0
void __fastcall UFG::AICoverQuery::StateInit(UFG::AICoverQuery *this, unsigned int uState)
{
  __int64 v2; // rdx
  void (__fastcall *m_InitFunc)(UFG::AICoverQuery *); // rax

  v2 = uState;
  m_InitFunc = UFG::AICoverQuery::ms_aStateInfo[v2].m_InitFunc;
  if ( m_InitFunc )
    m_InitFunc((UFG::AICoverQuery *)((char *)this + *(int *)UFG::AICoverQuery::ms_aStateInfo[v2].gap8));
}

// File Line: 193
// RVA: 0x388FF0
void __fastcall UFG::AICoverQuery::StateUpdate(UFG::AICoverQuery *this, unsigned int uState)
{
  UFG::AICoverQuery::ms_aStateInfo[uState].m_UpdateFunc((UFG::AICoverQuery *)((char *)this
                                                                            + *(int *)UFG::AICoverQuery::ms_aStateInfo[uState].gap18));
}

