// File Line: 328
// RVA: 0x333650
void __fastcall UFG::qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource>::~qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource>(
        UFG::qTypedResourceHandle<1139384190,UFG::AISidewalkSectionResource> *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax

  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(this, Inventory);
  UFG::qResourceHandle::~qResourceHandle(this);
}

