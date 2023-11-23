// File Line: 24
// RVA: 0x95F70
void __fastcall Illusion::TextureUser::OnLoad(Illusion::TextureUser *this, Illusion::Texture *texture)
{
  unsigned int mAlphaStateUID; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceInventory *v19; // rax
  UFG::qResourceWarehouse *v20; // rax
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax

  if ( this )
  {
    UFG::qResourceHandle::qResourceHandle(&this->mAlphaStateHandle);
    UFG::qResourceHandle::qResourceHandle(&this->mRasterStateHandle);
  }
  mAlphaStateUID = texture->mAlphaStateUID;
  Inventory = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mAlphaStateHandle, 0x12C800F2u, mAlphaStateUID, Inventory);
  if ( texture->mAlphaStateUID == 662883558 )
  {
    v7 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v8 = UFG::qResourceWarehouse::Instance();
      v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v7;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0x20688F05u, v7);
  }
  if ( texture->mAlphaStateUID == -1551679522 )
  {
    v9 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v10 = UFG::qResourceWarehouse::Instance();
      v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v9;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, v9);
  }
  if ( texture->mAlphaStateUID == 1775952593 )
  {
    v11 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v11;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, v11);
  }
  if ( texture->mAlphaStateUID == 721849354 )
  {
    v13 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v14 = UFG::qResourceWarehouse::Instance();
      v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v13;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0x20688F05u, v13);
  }
  if ( texture->mAlphaStateUID == -89056095 )
  {
    v15 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v16 = UFG::qResourceWarehouse::Instance();
      v15 = UFG::qResourceWarehouse::GetInventory(v16, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v15;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, v15);
  }
  if ( texture->mAlphaStateUID == -303549566 )
  {
    v17 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v18 = UFG::qResourceWarehouse::Instance();
      v17 = UFG::qResourceWarehouse::GetInventory(v18, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v17;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, v17);
  }
  if ( texture->mAlphaStateUID == 1857940896 )
  {
    v19 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v20 = UFG::qResourceWarehouse::Instance();
      v19 = UFG::qResourceWarehouse::GetInventory(v20, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v19;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, v19);
  }
  if ( texture->mAlphaStateUID == -697783528 )
  {
    v21 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
    {
      v22 = UFG::qResourceWarehouse::Instance();
      v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x3BC715E0u);
      `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v21;
    }
    UFG::qResourceHandle::Init(&this->mRasterStateHandle, 0x3BC715E0u, 0xF05AB9A5, v21);
  }
}

// File Line: 58
// RVA: 0x96220
void __fastcall Illusion::TextureUser::OnUnload(Illusion::TextureUser *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  Inventory = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x12C800F2u);
    `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mAlphaStateHandle, Inventory);
  v4 = `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::RasterState>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3BC715E0u);
    `UFG::qGetResourceInventory<Illusion::RasterState>::`2::result = v4;
  }
  UFG::qResourceHandle::Close(&this->mRasterStateHandle, v4);
}

