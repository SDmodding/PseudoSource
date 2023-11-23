// File Line: 52
// RVA: 0x387FB0
void __fastcall UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax

  this->mPtr = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(this, Inventory);
  this->mObjUID = -1;
  this->mIndex = -1;
  this->mNameUID = -1;
  this->mPtr = 0i64;
}

