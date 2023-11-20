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
  UFG::AICoverQuery::CoverQueryRecord *v1; // rbx
  UFG::CoverPosition *v2; // rcx
  bool v3; // zf

  v1 = this;
  this->vfptr = (UFG::AICoverQuery::CoverQueryRecordVtbl *)&UFG::AICoverQuery::CoverQueryRecord::`vftable;
  v2 = this->m_pCoverPosition;
  if ( v2 )
  {
    v3 = v2->m_iRefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v2->vfptr, 1u);
    v1->m_pCoverPosition = 0i64;
  }
  v1->m_bPathFound = 0;
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
  void (__fastcall *v3)(UFG::AICoverQuery *); // rax

  v2 = uState;
  v3 = UFG::AICoverQuery::ms_aStateInfo[v2].m_InitFunc;
  if ( v3 )
    v3((UFG::AICoverQuery *)((char *)this + *(signed int *)UFG::AICoverQuery::ms_aStateInfo[v2].gap8));
}

// File Line: 193
// RVA: 0x388FF0
void __fastcall UFG::AICoverQuery::StateUpdate(UFG::AICoverQuery *this, unsigned int uState)
{
  UFG::AICoverQuery::ms_aStateInfo[uState].m_UpdateFunc((UFG::AICoverQuery *)((char *)this
                                                                            + *(signed int *)UFG::AICoverQuery::ms_aStateInfo[uState].gap18));
}

