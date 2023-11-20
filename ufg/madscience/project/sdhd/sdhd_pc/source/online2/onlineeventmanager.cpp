// File Line: 37
// RVA: 0x42E230
void __fastcall UFG::OnlineEventManager::Initialize(UFG::OnlineEventManager *this)
{
  char v1; // cl

  v1 = UFG::OnlineEventManager::nInitialized;
  if ( !UFG::OnlineEventManager::nInitialized )
    v1 = 1;
  UFG::OnlineEventManager::nInitialized = v1;
}

// File Line: 55
// RVA: 0x430EE0
void __fastcall UFG::OnlineEventManager::Shutdown(UFG::OnlineEventManager *this)
{
  UFG::OnlineEventManager::nInitialized = 0;
}

// File Line: 67
// RVA: 0x42EB50
bool __fastcall UFG::OnlineEventManager::PostEvent(UFG::OnlineEventManager::Event evt, int param)
{
  return 0;
}

