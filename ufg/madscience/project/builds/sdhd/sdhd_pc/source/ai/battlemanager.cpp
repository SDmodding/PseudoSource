// File Line: 22
// RVA: 0x350E30
void UFG::BattleManager::CreateInstance(void)
{
  UFG::BattleManager *v0; // rax

  v0 = (UFG::BattleManager *)UFG::qMalloc(8ui64, "BattleManager", 0i64);
  if ( v0 )
  {
    v0->m_CurrentBattleType = eBATTLE_TYPE_NORMAL;
    v0->m_DebugDisplay = 0;
    UFG::BattleManager::s_pInstance = v0;
  }
  else
  {
    UFG::BattleManager::s_pInstance = 0i64;
  }
}

// File Line: 29
// RVA: 0x351DB0
void UFG::BattleManager::DeleteInstance(void)
{
  if ( UFG::BattleManager::s_pInstance )
    operator delete[](UFG::BattleManager::s_pInstance);
  UFG::BattleManager::s_pInstance = 0i64;
}

// File Line: 47
// RVA: 0x38D500
void __fastcall UFG::BattleManager::Update(UFG::BattleManager *this, float timestep)
{
  if ( this->m_DebugDisplay )
    UFG::DrawDebugText(30, 650, &UFG::qColour::White, "%s", UFG::BattleTypeNames[this->m_CurrentBattleType]);
}

