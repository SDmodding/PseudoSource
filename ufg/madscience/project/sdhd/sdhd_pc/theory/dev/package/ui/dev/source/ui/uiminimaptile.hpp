// File Line: 34
// RVA: 0xA23D10
void __fastcall UFG::UIMinimapTile::~UIMinimapTile(UFG::UIMinimapTile *this)
{
  Illusion::TextureHandle *p_mMapTileHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  p_mMapTileHandle = &this->mMapTileHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mMapTileHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mMapTileHandle);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&this->mResourceHandles);
  mPrev = this->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mResourceHandles.UFG::qResourceData::mNode.mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

