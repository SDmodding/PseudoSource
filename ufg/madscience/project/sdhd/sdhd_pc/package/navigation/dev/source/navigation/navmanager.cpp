// File Line: 13
// RVA: 0x265070
void UFG::NavManager::Initialize(void)
{
  UFG::NavManager::ms_pInstance = UFG::NavigationConfigs::CreateNavManager();
}

// File Line: 18
// RVA: 0x2627D0
void __fastcall UFG::NavManager::NavManager(UFG::NavManager *this)
{
  this->vfptr = (UFG::NavManagerVtbl *)&UFG::NavManager::`vftable;
}

// File Line: 22
// RVA: 0x262E90
void __fastcall UFG::NavManager::~NavManager(UFG::NavManager *this)
{
  this->vfptr = (UFG::NavManagerVtbl *)&UFG::NavManager::`vftable;
}

