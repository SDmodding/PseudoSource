// File Line: 96
// RVA: 0x3E4FE0
void __fastcall UFG::TimeOfDayManager::SetOverrideEnvironmentSettings(
        UFG::TimeOfDayManager *this,
        unsigned int env_stateblock_uid,
        float override_amount)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax

  this->m_OverrideStateBlockAmount = override_amount;
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mOverrideStateBlockHandle, 0x4D04C7F2u, env_stateblock_uid, Inventory);
}

