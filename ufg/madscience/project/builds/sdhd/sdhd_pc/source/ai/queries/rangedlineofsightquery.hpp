// File Line: 83
// RVA: 0x369F80
bool __fastcall UFG::AIRangedLineOfSightQuery::IsCompleted(UFG::AIRangedLineOfSightQuery *this)
{
  return this->m_uState - 8 <= 1;
}

// File Line: 88
// RVA: 0x388FD0
void __fastcall UFG::AIRangedLineOfSightQuery::StateInit(UFG::AIRangedLineOfSightQuery *this, unsigned int uState)
{
  void (__fastcall *v2)(UFG::AIRangedLineOfSightQuery *); // rax

  v2 = UFG::AIRangedLineOfSightQuery::ms_aStateInfo[uState].m_InitFunc;
  if ( v2 )
    v2(this);
}

// File Line: 97
// RVA: 0x389010
void __fastcall UFG::AIRangedLineOfSightQuery::StateUpdate(UFG::AIRangedLineOfSightQuery *this, unsigned int uState)
{
  JUMPOUT(__CS__, UFG::AIRangedLineOfSightQuery::ms_aStateInfo[uState].m_UpdateFunc);
}

