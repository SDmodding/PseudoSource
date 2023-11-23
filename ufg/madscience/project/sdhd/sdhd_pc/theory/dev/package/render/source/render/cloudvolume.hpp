// File Line: 21
// RVA: 0x70B80
void __fastcall Render::CloudVolumeManager::~CloudVolumeManager(Render::CloudVolumeManager *this)
{
  Illusion::StateBlockHandle *p_mStateBlockStormy; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  Illusion::StateBlockHandle *p_mStateBlockSunny; // rbx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  p_mStateBlockStormy = &this->mStateBlockStormy;
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mStateBlockStormy, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mStateBlockStormy);
  p_mStateBlockSunny = &this->mStateBlockSunny;
  v6 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v6;
  }
  UFG::qResourceHandle::Close(p_mStateBlockSunny, v6);
  UFG::qResourceHandle::~qResourceHandle(p_mStateBlockSunny);
}

