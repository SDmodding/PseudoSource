// File Line: 21
// RVA: 0x350E80
void UFG::GlobalCooldownManager::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax
  __int64 v1; // rcx

  if ( !UFG::GlobalCooldownManager::s_pInstance )
  {
    v0 = UFG::qMalloc(0x98ui64, "GlobalCooldownManager", 0i64);
    v1 = 0i64;
    if ( v0 )
    {
      do
      {
        *((_DWORD *)&v0->mNext + v1) = -943501440;
        *((_DWORD *)&v0[9].mNext + ++v1) = -943501440;
      }
      while ( v1 < 19 );
    }
    else
    {
      v0 = 0i64;
    }
    UFG::GlobalCooldownManager::s_pInstance = (UFG::GlobalCooldownManager *)v0;
  }
}

// File Line: 29
// RVA: 0x351DE0
void UFG::GlobalCooldownManager::DeleteInstance(void)
{
  if ( UFG::GlobalCooldownManager::s_pInstance )
    operator delete[](UFG::GlobalCooldownManager::s_pInstance);
  UFG::GlobalCooldownManager::s_pInstance = 0i64;
}

// File Line: 55
// RVA: 0x386F80
void __fastcall UFG::GlobalCooldownManager::SetLastTimeFired(
        UFG::GlobalCooldownManager *this,
        UFG::eGlobalCooldownType type,
        float min_time_until_next_can_fire,
        float max_time_until_next_can_fire)
{
  __int64 v4; // rdi
  float v6; // xmm0_4

  v4 = type;
  this->m_LastTimeFired[type] = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( max_time_until_next_can_fire <= min_time_until_next_can_fire )
  {
    this->m_TimeUntilNextCanFire[type] = max_time_until_next_can_fire;
  }
  else
  {
    v6 = UFG::qRandom(max_time_until_next_can_fire - min_time_until_next_can_fire, (unsigned int *)&UFG::qDefaultSeed)
       + min_time_until_next_can_fire;
    if ( v6 <= min_time_until_next_can_fire )
      v6 = min_time_until_next_can_fire;
    if ( v6 >= max_time_until_next_can_fire )
      this->m_TimeUntilNextCanFire[v4] = max_time_until_next_can_fire;
    else
      this->m_TimeUntilNextCanFire[v4] = v6;
  }
}

