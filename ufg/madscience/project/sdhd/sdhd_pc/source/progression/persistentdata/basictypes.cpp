// File Line: 15
// RVA: 0x48DF20
void __fastcall UFG::PersistentData::Time::Time(UFG::PersistentData::Time *this)
{
  UFG::SimpleTimer::SimpleTimer(&this->mTimer);
}

// File Line: 20
// RVA: 0x491650
void __fastcall UFG::PersistentData::Time::~Time(UFG::PersistentData::Time *this)
{
  _((AMD_HD3D *)this);
}

// File Line: 25
// RVA: 0x4A7030
// attributes: thunk
double __fastcall UFG::PersistentData::Time::GetTotalTime(UFG::PersistentData::Time *this)
{
  double result; // xmm0_8

  *(float *)&result = UFG::SimpleTimer::GetElapsedSeconds(&this->mTimer);
  return result;
}

// File Line: 30
// RVA: 0x49E150
// attributes: thunk
void __fastcall UFG::PersistentData::Time::EndTimer(UFG::PersistentData::Time *this)
{
  UFG::SimpleTimer::Stop(&this->mTimer);
}

