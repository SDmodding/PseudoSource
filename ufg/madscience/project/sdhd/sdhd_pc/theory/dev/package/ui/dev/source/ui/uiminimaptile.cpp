// File Line: 22
// RVA: 0x15ABCF0
__int64 UFG::_dynamic_initializer_for__gMinimapTileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gMinimapTileInventory,
    "UIMinimapTileInventory",
    0xB9C2B9E0,
    0x9F34FF46,
    0,
    0);
  UFG::gMinimapTileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::UIMinimapTileInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gMinimapTileInventory__);
}

// File Line: 29
// RVA: 0xA246A0
void __fastcall UFG::UIMinimapTileInventory::Add(UFG::UIMinimapTileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdi
  int SamplerAddressFlags; // eax

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&resource_data[1].mNode.mChild[1]);
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&resource_data[1].mNode.mChild[1],
    0x8B43FABF,
    (unsigned int)resource_data[1].mResourceHandles.mNode.mNext,
    Inventory);
  mPrev = resource_data[1].mResourceHandles.mNode.mPrev;
  if ( mPrev )
  {
    SamplerAddressFlags = Illusion::Texture::GetSamplerAddressFlags((Illusion::Texture *)resource_data[1].mResourceHandles.mNode.mPrev);
    Illusion::Texture::SetSamplerAddressFlags((Illusion::Texture *)mPrev, SamplerAddressFlags | 3);
    Render::ForceLoadTextureResources((unsigned int)resource_data[1].mResourceHandles.mNode.mNext);
  }
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 54
// RVA: 0xA28170
void __fastcall UFG::UIMinimapTileInventory::Remove(
        UFG::UIMinimapTileInventory *this,
        UFG::UIMinimapTile *resource_data)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&resource_data->mMapTileHandle, Inventory);
  UFG::UIMinimapTile::~UIMinimapTile(resource_data);
}

