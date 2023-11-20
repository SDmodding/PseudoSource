// File Line: 210
// RVA: 0x4120
void __fastcall ModelType::SetRigHandle(ModelType *this, unsigned int rig_uid, UFG::RigResource *rig)
{
  UFG::qResourceInventory *inventory; // rax
  UFG::RigResource *v4; // rbx
  unsigned int v5; // edi
  ModelType *v6; // rsi
  UFG::qResourceWarehouse *v7; // rax

  inventory = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  v4 = rig;
  v5 = rig_uid;
  v6 = this;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v6->mRigHandle.mPrev,
    0x39BC0A7Eu,
    v5,
    (UFG::qResourceData *)&v4->mNode,
    inventory);
}

