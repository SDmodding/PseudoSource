// File Line: 35
// RVA: 0x93450
void __fastcall Illusion::Buffer::OnLoad(Illusion::Buffer *this)
{
  __int64 mOffset; // rax

  if ( this )
    UFG::qResourceData::qResourceData(&this->UFG::qResourceData);
  Illusion::IBufferPlat::OnLoad(this);
  mOffset = this->mBufferUser.mOffset;
  if ( mOffset )
    _((AMD_HD3D *)((char *)&this->mBufferUser + mOffset));
  else
    _(0i64);
}

// File Line: 75
// RVA: 0x1457CC0
__int64 Illusion::_dynamic_initializer_for__gBufferInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gBufferInventory,
    "BufferInventory",
    0x92CDEC8F,
    0x7A971479u,
    0,
    0x40u);
  Illusion::gBufferInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::BufferInventory::`vftable;
  UFG::qMemSet(Illusion::gBufferInventory.mNumBytes, 0, 0xCu);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gBufferInventory__);
}

// File Line: 85
// RVA: 0x8DC70
void __fastcall Illusion::BufferInventory::Add(Illusion::BufferInventory *this, UFG::qResourceData *resource_data)
{
  __int64 v4; // rax
  AMD_HD3D *v5; // rcx
  char *v6; // rcx

  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  Illusion::IBufferPlat::OnLoad((Illusion::IBufferPlat *)resource_data);
  v4 = *(_QWORD *)&resource_data[1].mNode.mUID;
  if ( v4 )
    v5 = (AMD_HD3D *)((char *)&resource_data[1].mNode.mChild[2] + v4);
  else
    v5 = 0i64;
  _(v5);
  v6 = (char *)this + 4 * LOBYTE(resource_data[1].mNode.mParent);
  *((_DWORD *)v6 + 72) += HIDWORD(resource_data[1].mNode.mParent);
  if ( LOBYTE(resource_data[1].mNode.mParent) == 1 && LODWORD(resource_data[1].mNode.mChild[1]) == 4 )
    UFG::qPrintf("[Buffer] 32-Bit Index Buffer - %s\n", resource_data->mDebugName);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 105
// RVA: 0x94810
void __fastcall Illusion::BufferInventory::Remove(Illusion::BufferInventory *this, UFG::qResourceData *resource_data)
{
  char *v4; // rcx
  __int64 v5; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  v4 = (char *)this + 4 * LOBYTE(resource_data[1].mNode.mParent);
  *((_DWORD *)v4 + 72) -= HIDWORD(resource_data[1].mNode.mParent);
  Illusion::IBufferPlat::OnUnload((Illusion::IBufferPlat *)resource_data);
  v5 = *(_QWORD *)&resource_data[1].mNode.mUID;
  if ( v5 )
    _((AMD_HD3D *)((char *)&resource_data[1].mNode.mChild[2] + v5));
  else
    _(0i64);
}

// File Line: 152
// RVA: 0x1457C60
__int64 Illusion::_dynamic_initializer_for__gBonePaletteInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gBonePaletteInventory,
    "BonePaletteInventory",
    0x50A819E3u,
    0x982456DB,
    0,
    0x10u);
  Illusion::gBonePaletteInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::BonePaletteInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gBonePaletteInventory__);
}

// File Line: 173
// RVA: 0x94800
// attributes: thunk
void __fastcall Illusion::LocatorsInventory::Remove(Render::FontInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
}

// File Line: 191
// RVA: 0x93970
void __fastcall Illusion::MorphTargets::OnLoad(Illusion::MorphTargets *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax

  if ( this )
  {
    UFG::qResourceData::qResourceData(this);
    UFG::qResourceHandle::qResourceHandle(&this->mMorphVertexBufferHandle);
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(
    &this->mMorphVertexBufferHandle,
    0x92CDEC8F,
    this->mMorphVertexBufferHandle.mNameUID,
    Inventory);
}

// File Line: 219
// RVA: 0x1458010
__int64 Illusion::_dynamic_initializer_for__gMorphTargetsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gMorphTargetsInventory,
    "MorphTargetsInventory",
    0xC62C2822,
    0x2CD0C47u,
    0,
    0);
  Illusion::gMorphTargetsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::MorphTargetsInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gMorphTargetsInventory__);
}

// File Line: 228
// RVA: 0x8DDA0
void __fastcall Illusion::MorphTargetsInventory::Add(
        Illusion::MorphTargetsInventory *this,
        Illusion::MorphTargets *resource_data)
{
  Illusion::MorphTargets::OnLoad(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 239
// RVA: 0x948E0
void __fastcall Illusion::MorphTargetsInventory::Remove(
        Illusion::MorphTargetsInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  Inventory = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&resource_data[1], Inventory);
}

// File Line: 259
// RVA: 0x93650
void __fastcall Illusion::Mesh::OnLoad(Illusion::Mesh *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  Illusion::BufferHandle *mVertexBufferHandles; // rbx
  __int64 v9; // rsi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax

  if ( this )
    Illusion::Mesh::Mesh(this);
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mMaterialHandle, 0xB4C26312, this->mMaterialHandle.mNameUID, Inventory);
  v4 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v4;
  }
  UFG::qResourceHandle::Init(&this->mVertexDeclHandle, 0x3E5FDA3Eu, this->mVertexDeclHandle.mNameUID, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mIndexBufferHandle, 0x92CDEC8F, this->mIndexBufferHandle.mNameUID, v6);
  mVertexBufferHandles = this->mVertexBufferHandles;
  v9 = 4i64;
  do
  {
    v10 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x92CDEC8F);
      `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v10;
    }
    UFG::qResourceHandle::Init(mVertexBufferHandles, 0x92CDEC8F, mVertexBufferHandles->mNameUID, v10);
    ++mVertexBufferHandles;
    --v9;
  }
  while ( v9 );
  _((AMD_HD3D *)this);
}

// File Line: 278
// RVA: 0x942D0
void __fastcall Illusion::Mesh::OnUnload(Illusion::Mesh *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  Illusion::BufferHandle *mVertexBufferHandles; // rbx
  __int64 v9; // rdi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax

  _((AMD_HD3D *)this);
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mMaterialHandle, Inventory);
  v4 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v4;
  }
  UFG::qResourceHandle::Close(&this->mVertexDeclHandle, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v6;
  }
  UFG::qResourceHandle::Close(&this->mIndexBufferHandle, v6);
  mVertexBufferHandles = this->mVertexBufferHandles;
  v9 = 4i64;
  do
  {
    v10 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x92CDEC8F);
      `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v10;
    }
    UFG::qResourceHandle::Close(mVertexBufferHandles++, v10);
    --v9;
  }
  while ( v9 );
}

// File Line: 326
// RVA: 0x1457E60
__int64 Illusion::_dynamic_initializer_for__gLocatorsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gLocatorsInventory,
    "LocatorsInventory",
    0x3EDDEFF0u,
    0x15506061u,
    0,
    0);
  Illusion::gLocatorsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::LocatorsInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gLocatorsInventory__);
}

// File Line: 367
// RVA: 0x937A0
void __fastcall Illusion::Model::OnLoad(Illusion::Model *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  __int64 mOffset; // rax
  AMD_HD3D *v11; // rcx
  unsigned int mNumMeshes; // eax
  UFG::qOffset64<UFG::qOffset64<Illusion::Mesh *> *> *p_mMeshOffsetTable; // rsi
  char *mDebugName; // r14
  __int64 v15; // rdi
  __int64 v16; // rbp
  char *v17; // rcx
  char *v18; // rax
  __int64 v19; // rcx
  Illusion::Mesh *v20; // rbx

  if ( this )
    Illusion::Model::Model(this);
  Inventory = `UFG::qGetResourceInventory<Illusion::MaterialTable>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MaterialTable>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x80D1F139);
    `UFG::qGetResourceInventory<Illusion::MaterialTable>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mMaterialTableHandle, 0x80D1F139, this->mMaterialTableHandle.mNameUID, Inventory);
  v4 = `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result = v4;
  }
  UFG::qResourceHandle::Init(&this->mBonePaletteHandle, 0x50A819E3u, this->mBonePaletteHandle.mNameUID, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::MorphTargets>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MorphTargets>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xC62C2822);
    `UFG::qGetResourceInventory<Illusion::MorphTargets>::`2::result = v6;
  }
  UFG::qResourceHandle::Init(&this->mMorphTargetsHandle, 0xC62C2822, this->mMorphTargetsHandle.mNameUID, v6);
  v8 = `UFG::qGetResourceInventory<Illusion::Locators>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Locators>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x3EDDEFF0u);
    `UFG::qGetResourceInventory<Illusion::Locators>::`2::result = v8;
  }
  UFG::qResourceHandle::Init(&this->mLocatorsHandle, 0x3EDDEFF0u, this->mLocatorsHandle.mNameUID, v8);
  this->mLastUsedFrameNum = 0;
  Illusion::IModelPlat::OnLoad(this);
  mOffset = this->mModelUser.mOffset;
  if ( mOffset )
    v11 = (AMD_HD3D *)((char *)&this->mModelUser + mOffset);
  else
    v11 = 0i64;
  _(v11);
  mNumMeshes = this->mNumMeshes;
  if ( mNumMeshes )
  {
    p_mMeshOffsetTable = &this->mMeshOffsetTable;
    mDebugName = this->mDebugName;
    v15 = 0i64;
    v16 = mNumMeshes;
    do
    {
      if ( p_mMeshOffsetTable->mOffset )
        v17 = (char *)p_mMeshOffsetTable + p_mMeshOffsetTable->mOffset;
      else
        v17 = 0i64;
      v18 = &v17[v15];
      v19 = *(_QWORD *)&v17[v15];
      if ( v19 )
        v20 = (Illusion::Mesh *)&v18[v19];
      else
        v20 = 0i64;
      Illusion::Mesh::OnLoad(v20);
      v20->mDescription = mDebugName;
      v15 += 8i64;
      --v16;
    }
    while ( v16 );
  }
}

// File Line: 400
// RVA: 0x943D0
void __fastcall Illusion::Model::OnUnload(Illusion::Model *this)
{
  __int64 mOffset; // rax
  AMD_HD3D *v3; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  unsigned int mNumMeshes; // eax
  UFG::qOffset64<UFG::qOffset64<Illusion::Mesh *> *> *p_mMeshOffsetTable; // rdi
  __int64 v14; // rbx
  __int64 v15; // rsi
  char *v16; // rcx
  char *v17; // rax
  Illusion::Mesh *v18; // rcx

  Illusion::IModelPlat::OnUnload(this);
  mOffset = this->mModelUser.mOffset;
  if ( mOffset )
    v3 = (AMD_HD3D *)((char *)&this->mModelUser + mOffset);
  else
    v3 = 0i64;
  _(v3);
  Inventory = `UFG::qGetResourceInventory<Illusion::MaterialTable>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MaterialTable>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x80D1F139);
    `UFG::qGetResourceInventory<Illusion::MaterialTable>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mMaterialTableHandle, Inventory);
  v6 = `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result = v6;
  }
  UFG::qResourceHandle::Close(&this->mBonePaletteHandle, v6);
  v8 = `UFG::qGetResourceInventory<Illusion::MorphTargets>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MorphTargets>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xC62C2822);
    `UFG::qGetResourceInventory<Illusion::MorphTargets>::`2::result = v8;
  }
  UFG::qResourceHandle::Close(&this->mMorphTargetsHandle, v8);
  v10 = `UFG::qGetResourceInventory<Illusion::Locators>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Locators>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x3EDDEFF0u);
    `UFG::qGetResourceInventory<Illusion::Locators>::`2::result = v10;
  }
  UFG::qResourceHandle::Close(&this->mLocatorsHandle, v10);
  mNumMeshes = this->mNumMeshes;
  if ( mNumMeshes )
  {
    p_mMeshOffsetTable = &this->mMeshOffsetTable;
    v14 = 0i64;
    v15 = mNumMeshes;
    do
    {
      if ( p_mMeshOffsetTable->mOffset )
        v16 = (char *)p_mMeshOffsetTable + p_mMeshOffsetTable->mOffset;
      else
        v16 = 0i64;
      v17 = &v16[v14];
      v18 = *(Illusion::Mesh **)&v16[v14];
      if ( v18 )
        v18 = (Illusion::Mesh *)((char *)v18 + (_QWORD)v17);
      Illusion::Mesh::OnUnload(v18);
      v14 += 8i64;
      --v15;
    }
    while ( v15 );
  }
}

// File Line: 695
// RVA: 0x1457FB0
__int64 Illusion::_dynamic_initializer_for__gModelDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gModelDataInventory,
    "ModelDataInventory",
    0xA2ADCD77,
    0x6DF963B3u,
    0,
    0x100u);
  Illusion::gModelDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::ModelDataInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gModelDataInventory__);
}

// File Line: 704
// RVA: 0x8DD70
void __fastcall Illusion::ModelDataInventory::Add(Illusion::ModelDataInventory *this, Illusion::Model *resource_data)
{
  Illusion::Model::OnLoad(resource_data);
  UFG::qResourceInventory::Add(this, &resource_data->UFG::qResourceData);
}

// File Line: 718
// RVA: 0x948C0
void __fastcall Illusion::ModelDataInventory::Remove(
        Illusion::ModelDataInventory *this,
        Illusion::Model *resource_data)
{
  UFG::qResourceInventory::Remove(this, &resource_data->UFG::qResourceData);
  Illusion::Model::OnUnload(resource_data);
}

