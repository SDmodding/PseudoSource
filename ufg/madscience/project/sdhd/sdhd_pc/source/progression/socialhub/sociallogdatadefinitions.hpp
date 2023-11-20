// File Line: 49
// RVA: 0x428A20
void __fastcall UFG::SocialLogData_BeatChallenge::SocialLogData_BeatChallenge(UFG::SocialLogData_BeatChallenge *this)
{
  UFG::SocialLogData_BeatChallenge *v1; // rbx

  v1 = this;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&this->vfptr);
  v1->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_BeatChallenge::`vftable';
  v1->m_iHasSent = 0;
  v1->m_aData = 0i64;
}

// File Line: 70
// RVA: 0x428A60
void __fastcall UFG::SocialLogData_Challenge::SocialLogData_Challenge(UFG::SocialLogData_Challenge *this)
{
  UFG::SocialLogData_Challenge *v1; // rbx

  v1 = this;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&this->vfptr);
  v1->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_Challenge::`vftable';
  v1->m_iHasBeaten = 0;
  v1->m_aData = 0i64;
}

