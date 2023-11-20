// File Line: 22
// RVA: 0x15ABCF0
__int64 UFG::_dynamic_initializer_for__gMinimapTileInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gMinimapTileInventory.vfptr,
    "UIMinimapTileInventory",
    0xB9C2B9E0,
    0x9F34FF46,
    0,
    0);
  UFG::gMinimapTileInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::UIMinimapTileInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gMinimapTileInventory__);
}

// File Line: 29
// RVA: 0xA246A0
void __fastcall UFG::UIMinimapTileInventory::Add(UFG::UIMinimapTileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::UIMinimapTileInventory *v3; // rsi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  Illusion::Texture *v6; // rdi
  int v7; // eax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2[1].mNode.mChild[1]);
  }
  v4 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v4;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v2[1].mNode.mChild[1],
    0x8B43FABF,
    (unsigned int)v2[1].mResourceHandles.mNode.mNext,
    v4);
  v6 = (Illusion::Texture *)v2[1].mResourceHandles.mNode.mPrev;
  if ( v6 )
  {
    v7 = Illusion::Texture::GetSamplerAddressFlags((Illusion::Texture *)v2[1].mResourceHandles.mNode.mPrev);
    Illusion::Texture::SetSamplerAddressFlags(v6, v7 | 3);
    Render::ForceLoadTextureResources((unsigned int)v2[1].mResourceHandles.mNode.mNext);
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 54
// RVA: 0xA28170
void __fastcall UFG::UIMinimapTileInventory::Remove(UFG::UIMinimapTileInventory *this, UFG::qResourceData *resource_data)
{
  UFG::UIMinimapTile *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax

  v2 = (UFG::UIMinimapTile *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v3;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mMapTileHandle.mPrev, v3);
  UFG::UIMinimapTile::~UIMinimapTile(v2);
}

