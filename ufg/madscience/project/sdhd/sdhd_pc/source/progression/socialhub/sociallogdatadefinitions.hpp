// File Line: 49
// RVA: 0x428A20
void __fastcall UFG::SocialLogData_BeatChallenge::SocialLogData_BeatChallenge(UFG::SocialLogData_BeatChallenge *this)
{
  UFG::SocialLogData::SocialLogData(this);
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_BeatChallenge::`vftable;
  this->m_iHasSent = 0;
  this->m_aData = 0i64;
}

// File Line: 70
// RVA: 0x428A60
void __fastcall UFG::SocialLogData_Challenge::SocialLogData_Challenge(UFG::SocialLogData_Challenge *this)
{
  UFG::SocialLogData::SocialLogData(this);
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_Challenge::`vftable;
  this->m_iHasBeaten = 0;
  this->m_aData = 0i64;
}

