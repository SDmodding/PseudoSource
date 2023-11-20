// File Line: 40
// RVA: 0x3EF390
_BOOL8 __fastcall UFG::CopSystem::IsActive(UFG::CopSystem *this)
{
  return this->mHeatLevel != 0;
}

// File Line: 54
// RVA: 0x3EDBB0
__int64 __fastcall UFG::CopSystem::GetNumArrestAttempts(UFG::CopSystem *this)
{
  return (unsigned int)this->mNumArrestAttempts;
}

