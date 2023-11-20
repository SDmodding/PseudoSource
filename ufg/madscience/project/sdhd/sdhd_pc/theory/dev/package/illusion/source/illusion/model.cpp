// File Line: 35
// RVA: 0x93450
void __fastcall Illusion::Buffer::OnLoad(Illusion::Buffer *this)
{
  Illusion::Buffer *v1; // rbx
  __int64 v2; // rax
  AMD_HD3D *v3; // rcx

  v1 = this;
  if ( this )
    UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  Illusion::IBufferPlat::OnLoad((Illusion::IBufferPlat *)v1);
  v2 = v1->mBufferUser.mOffset;
  if ( v2 )
    v3 = (AMD_HD3D *)((char *)&v1->mBufferUser + v2);
  else
    v3 = 0i64;
  _(v3);
}

// File Line: 75
// RVA: 0x1457CC0
__int64 Illusion::_dynamic_initializer_for__gBufferInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gBufferInventory.vfptr,
    "BufferInventory",
    0x92CDEC8F,
    0x7A971479u,
    0,
    0x40u);
  Illusion::gBufferInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::BufferInventory::`vftable';
  UFG::qMemSet(Illusion::gBufferInventory.mNumBytes, 0, 0xCu);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gBufferInventory__);
}

// File Line: 85
// RVA: 0x8DC70
void __fastcall Illusion::BufferInventory::Add(Illusion::BufferInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Illusion::BufferInventory *v3; // rdi
  __int64 v4; // rax
  AMD_HD3D *v5; // rcx
  signed __int64 v6; // rcx

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  Illusion::IBufferPlat::OnLoad((Illusion::IBufferPlat *)v2);
  v4 = *(_QWORD *)&v2[1].mNode.mUID;
  if ( v4 )
    v5 = (AMD_HD3D *)((char *)&v2[1].mNode.mUID + v4);
  else
    v5 = 0i64;
  _(v5);
  v6 = (signed __int64)v3 + 4 * LOBYTE(v2[1].mNode.mParent);
  *(_DWORD *)(v6 + 288) += HIDWORD(v2[1].mNode.mParent);
  if ( LOBYTE(v2[1].mNode.mParent) == 1 && LODWORD(v2[1].mNode.mChild[1]) == 4 )
    UFG::qPrintf("[Buffer] 32-Bit Index Buffer - '%s'\n", v2->mDebugName);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 105
// RVA: 0x94810
void __fastcall Illusion::BufferInventory::Remove(Illusion::BufferInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rdi
  Illusion::BufferInventory *v3; // rbx
  signed __int64 v4; // rcx
  __int64 v5; // rax

  v2 = resource_data;
  v3 = this;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v4 = (signed __int64)v3 + 4 * LOBYTE(v2[1].mNode.mParent);
  *(_DWORD *)(v4 + 288) -= HIDWORD(v2[1].mNode.mParent);
  Illusion::IBufferPlat::OnUnload((Illusion::IBufferPlat *)v2);
  v5 = *(_QWORD *)&v2[1].mNode.mUID;
  if ( v5 )
    _((AMD_HD3D *)((char *)&v2[1].mNode.mUID + v5));
  else
    _(0i64);
}

// File Line: 152
// RVA: 0x1457C60
__int64 Illusion::_dynamic_initializer_for__gBonePaletteInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gBonePaletteInventory.vfptr,
    "BonePaletteInventory",
    0x50A819E3u,
    0x982456DB,
    0,
    0x10u);
  Illusion::gBonePaletteInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::BonePaletteInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gBonePaletteInventory__);
}

// File Line: 173
// RVA: 0x94800
void __fastcall Illusion::LocatorsInventory::Remove(Render::FontInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
}

// File Line: 191
// RVA: 0x93970
void __fastcall Illusion::MorphTargets::OnLoad(Illusion::MorphTargets *this)
{
  Illusion::MorphTargets *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax

  v1 = this;
  if ( this )
  {
    UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mMorphVertexBufferHandle.mPrev);
  }
  v2 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mMorphVertexBufferHandle.mPrev,
    0x92CDEC8F,
    v1->mMorphVertexBufferHandle.mNameUID,
    v2);
}

// File Line: 219
// RVA: 0x1458010
__int64 Illusion::_dynamic_initializer_for__gMorphTargetsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gMorphTargetsInventory.vfptr,
    "MorphTargetsInventory",
    0xC62C2822,
    0x2CD0C47u,
    0,
    0);
  Illusion::gMorphTargetsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::MorphTargetsInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gMorphTargetsInventory__);
}

// File Line: 228
// RVA: 0x8DDA0
void __fastcall Illusion::MorphTargetsInventory::Add(Illusion::MorphTargetsInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::MorphTargetsInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Illusion::MorphTargets::OnLoad((Illusion::MorphTargets *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v2->vfptr, v3);
}

// File Line: 239
// RVA: 0x948E0
void __fastcall Illusion::MorphTargetsInventory::Remove(Illusion::MorphTargetsInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2[1], v3);
}

// File Line: 259
// RVA: 0x93650
void __fastcall Illusion::Mesh::OnLoad(Illusion::Mesh *this)
{
  Illusion::Mesh *v1; // rdi
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceHandle *v8; // rbx
  signed __int64 v9; // rsi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax

  v1 = this;
  if ( this )
    Illusion::Mesh::Mesh(this);
  v2 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mMaterialHandle.mPrev,
    0xB4C26312,
    v1->mMaterialHandle.mNameUID,
    v2);
  v4 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev,
    0x3E5FDA3Eu,
    v1->mVertexDeclHandle.mNameUID,
    v4);
  v6 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mIndexBufferHandle.mPrev,
    0x92CDEC8F,
    v1->mIndexBufferHandle.mNameUID,
    v6);
  v8 = (UFG::qResourceHandle *)v1->mVertexBufferHandles;
  v9 = 4i64;
  do
  {
    v10 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x92CDEC8F);
      `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v10;
    }
    UFG::qResourceHandle::Init(v8, 0x92CDEC8F, v8->mNameUID, v10);
    ++v8;
    --v9;
  }
  while ( v9 );
  _((AMD_HD3D *)v1);
}

// File Line: 278
// RVA: 0x942D0
void __fastcall Illusion::Mesh::OnUnload(Illusion::Mesh *this)
{
  Illusion::Mesh *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceHandle *v8; // rbx
  signed __int64 v9; // rdi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax

  v1 = this;
  _((AMD_HD3D *)this);
  v2 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mMaterialHandle.mPrev, v2);
  v4 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mIndexBufferHandle.mPrev, v6);
  v8 = (UFG::qResourceHandle *)v1->mVertexBufferHandles;
  v9 = 4i64;
  do
  {
    v10 = `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x92CDEC8F);
      `UFG::qGetResourceInventory<Illusion::Buffer>'::`2'::result = v10;
    }
    UFG::qResourceHandle::Close(v8, v10);
    ++v8;
    --v9;
  }
  while ( v9 );
}

// File Line: 326
// RVA: 0x1457E60
__int64 Illusion::_dynamic_initializer_for__gLocatorsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gLocatorsInventory.vfptr,
    "LocatorsInventory",
    0x3EDDEFF0u,
    0x15506061u,
    0,
    0);
  Illusion::gLocatorsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::LocatorsInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gLocatorsInventory__);
}

// File Line: 367
// RVA: 0x937A0
void __fastcall Illusion::Model::OnLoad(Illusion::Model *this)
{
  Illusion::Model *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  __int64 v10; // rax
  AMD_HD3D *v11; // rcx
  unsigned int v12; // eax
  UFG::qOffset64<UFG::qOffset64<Illusion::Mesh *> *> *v13; // rsi
  signed __int64 v14; // r14
  __int64 v15; // rdi
  __int64 v16; // rbp
  char *v17; // rcx
  char *v18; // rax
  __int64 v19; // rcx
  Illusion::Mesh *v20; // rbx

  v1 = this;
  if ( this )
    Illusion::Model::Model(this);
  v2 = `UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x80D1F139);
    `UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mMaterialTableHandle.mPrev,
    0x80D1F139,
    v1->mMaterialTableHandle.mNameUID,
    v2);
  v4 = `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mBonePaletteHandle.mPrev,
    0x50A819E3u,
    v1->mBonePaletteHandle.mNameUID,
    v4);
  v6 = `UFG::qGetResourceInventory<Illusion::MorphTargets>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MorphTargets>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xC62C2822);
    `UFG::qGetResourceInventory<Illusion::MorphTargets>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mMorphTargetsHandle.mPrev,
    0xC62C2822,
    v1->mMorphTargetsHandle.mNameUID,
    v6);
  v8 = `UFG::qGetResourceInventory<Illusion::Locators>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Locators>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x3EDDEFF0u);
    `UFG::qGetResourceInventory<Illusion::Locators>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v1->mLocatorsHandle.mPrev,
    0x3EDDEFF0u,
    v1->mLocatorsHandle.mNameUID,
    v8);
  v1->mLastUsedFrameNum = 0;
  Illusion::IModelPlat::OnLoad(v1);
  v10 = v1->mModelUser.mOffset;
  if ( v10 )
    v11 = (AMD_HD3D *)((char *)&v1->mModelUser + v10);
  else
    v11 = 0i64;
  _(v11);
  v12 = v1->mNumMeshes;
  if ( v12 )
  {
    v13 = &v1->mMeshOffsetTable;
    v14 = (signed __int64)v1->mDebugName;
    v15 = 0i64;
    v16 = v12;
    do
    {
      if ( v13->mOffset )
        v17 = (char *)v13 + v13->mOffset;
      else
        v17 = 0i64;
      v18 = &v17[v15];
      v19 = *(_QWORD *)&v17[v15];
      if ( v19 )
        v20 = (Illusion::Mesh *)&v18[v19];
      else
        v20 = 0i64;
      Illusion::Mesh::OnLoad(v20);
      v20->mDescription = (const char *)v14;
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
  Illusion::Model *v1; // rbx
  __int64 v2; // rax
  AMD_HD3D *v3; // rcx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  unsigned int v12; // eax
  UFG::qOffset64<UFG::qOffset64<Illusion::Mesh *> *> *v13; // rdi
  __int64 v14; // rbx
  __int64 v15; // rsi
  char *v16; // rcx
  char *v17; // rax
  Illusion::Mesh *v18; // rcx

  v1 = this;
  Illusion::IModelPlat::OnUnload((Illusion::IModelPlat *)this);
  v2 = v1->mModelUser.mOffset;
  if ( v2 )
    v3 = (AMD_HD3D *)((char *)&v1->mModelUser + v2);
  else
    v3 = 0i64;
  _(v3);
  v4 = `UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x80D1F139);
    `UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mMaterialTableHandle.mPrev, v4);
  v6 = `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x50A819E3u);
    `UFG::qGetResourceInventory<Illusion::BonePalette>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mBonePaletteHandle.mPrev, v6);
  v8 = `UFG::qGetResourceInventory<Illusion::MorphTargets>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MorphTargets>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xC62C2822);
    `UFG::qGetResourceInventory<Illusion::MorphTargets>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mMorphTargetsHandle.mPrev, v8);
  v10 = `UFG::qGetResourceInventory<Illusion::Locators>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Locators>'::`2'::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x3EDDEFF0u);
    `UFG::qGetResourceInventory<Illusion::Locators>'::`2'::result = v10;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mLocatorsHandle.mPrev, v10);
  v12 = v1->mNumMeshes;
  if ( v12 )
  {
    v13 = &v1->mMeshOffsetTable;
    v14 = 0i64;
    v15 = v12;
    do
    {
      if ( v13->mOffset )
        v16 = (char *)v13 + v13->mOffset;
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
    (UFG::qResourceInventory *)&Illusion::gModelDataInventory.vfptr,
    "ModelDataInventory",
    0xA2ADCD77,
    0x6DF963B3u,
    0,
    0x100u);
  Illusion::gModelDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::ModelDataInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gModelDataInventory__);
}

// File Line: 704
// RVA: 0x8DD70
void __fastcall Illusion::ModelDataInventory::Add(Illusion::ModelDataInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::ModelDataInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Illusion::Model::OnLoad((Illusion::Model *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v2->vfptr, v3);
}

// File Line: 718
// RVA: 0x948C0
void __fastcall Illusion::ModelDataInventory::Remove(Illusion::ModelDataInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::Model *v2; // rbx

  v2 = (Illusion::Model *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  Illusion::Model::OnUnload(v2);
}

