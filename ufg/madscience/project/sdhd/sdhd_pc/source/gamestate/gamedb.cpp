// File Line: 92
// RVA: 0x40DC10
UFG::GameDB *__fastcall UFG::GameDB::Instance()
{
  return UFG::GameDB::sInstance;
}

// File Line: 103
// RVA: 0x40C880
__int64 __fastcall UFG::GameDB::GetRivalIndexFor(UFG::GameDB *this, UFG::TurfComponent *tc)
{
  unsigned int v2; // er9

  v2 = (this->mNextRivalIndex + 1) % 6;
  this->mNextRivalIndex = v2;
  return v2;
}

