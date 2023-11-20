// File Line: 26
// RVA: 0x263D10
void UFG::NavAvoidanceManager::CreateInstance(void)
{
  UFG::NavAvoidanceManager *v0; // rax

  if ( !UFG::NavAvoidanceManager::mspAvoidanceManager )
  {
    v0 = (UFG::NavAvoidanceManager *)UFG::qMalloc(0x10ui64, "NavAvoidanceManager", 0i64);
    if ( v0 )
    {
      v0->vfptr = (UFG::NavAvoidanceManagerVtbl *)&UFG::NavAvoidanceManager::`vftable';
      v0->mpAvoidanceStrategy = 0i64;
    }
    UFG::NavAvoidanceManager::mspAvoidanceManager = v0;
  }
}

// File Line: 34
// RVA: 0x263F50
void UFG::NavAvoidanceManager::DeleteInstance(void)
{
  if ( UFG::NavAvoidanceManager::mspAvoidanceManager )
  {
    UFG::NavAvoidanceManager::mspAvoidanceManager->vfptr->__vecDelDtor(
      UFG::NavAvoidanceManager::mspAvoidanceManager,
      1u);
    UFG::NavAvoidanceManager::mspAvoidanceManager = 0i64;
  }
}

// File Line: 43
// RVA: 0x264110
void __fastcall UFG::NavAvoidanceManager::EnterGame(UFG::NavAvoidanceManager *this)
{
  this->mpAvoidanceStrategy = UFG::NavigationConfigs::CreateAvoidanceStrategy();
}

// File Line: 55
// RVA: 0x2666D0
void __fastcall UFG::NavAvoidanceManager::Update(UFG::NavAvoidanceManager *this, __int64 phase, float deltaTime)
{
  ((void (__fastcall *)(UFG::NavAvoidanceStrategy *, __int64))this->mpAvoidanceStrategy->vfptr->Update)(
    this->mpAvoidanceStrategy,
    phase);
}

