// File Line: 96
// RVA: 0x3E4FE0
void __fastcall UFG::TimeOfDayManager::SetOverrideEnvironmentSettings(UFG::TimeOfDayManager *this, unsigned int env_stateblock_uid, float override_amount)
{
  UFG::qResourceInventory *v3; // rax
  unsigned int v4; // edi
  UFG::TimeOfDayManager *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax

  this->m_OverrideStateBlockAmount = override_amount;
  v3 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  v4 = env_stateblock_uid;
  v5 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v6, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mOverrideStateBlockHandle.mPrev, 0x4D04C7F2u, v4, v3);
}

