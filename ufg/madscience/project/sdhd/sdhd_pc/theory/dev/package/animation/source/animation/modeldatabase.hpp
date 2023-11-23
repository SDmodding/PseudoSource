// File Line: 210
// RVA: 0x4120
void __fastcall ModelType::SetRigHandle(ModelType *this, unsigned int rig_uid, UFG::RigResource *rig)
{
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = inventory;
  }
  UFG::qResourceHandle::Init(&this->mRigHandle, 0x39BC0A7Eu, rig_uid, rig, inventory);
}

