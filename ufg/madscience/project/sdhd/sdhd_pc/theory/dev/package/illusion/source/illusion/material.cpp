// File Line: 27
// RVA: 0x934A0
void __fastcall Illusion::Material::OnLoad(Illusion::Material *this)
{
  unsigned int mNumParams; // eax
  Illusion::MaterialUser *v3; // r15
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // r14
  unsigned int *p_mTypeUID; // rbx
  __int64 v7; // rsi
  unsigned int v8; // edx
  __int16 v9; // ax
  unsigned int v10; // r8d
  __int64 mOffset; // rax

  if ( this )
    Illusion::Material::Material(this);
  mNumParams = this->mNumParams;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  if ( mNumParams )
  {
    p_mTypeUID = &this[1].mTypeUID;
    v7 = mNumParams;
    do
    {
      v8 = *(p_mTypeUID - 12);
      if ( v8 )
      {
        v9 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v8, 0i64, 0);
        *((_WORD *)p_mTypeUID - 20) = v9;
        if ( (unsigned int)v9 > 0x3F )
          v5 |= 1i64 << ((unsigned __int8)v9 - 64);
        else
          v4 |= 1i64 << v9;
        v10 = *(p_mTypeUID - 2);
        if ( v10 )
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)p_mTypeUID - 1, *p_mTypeUID, v10);
      }
      p_mTypeUID += 14;
      --v7;
    }
    while ( v7 );
  }
  this->mStateBlockMask.mFlags[0] = v4;
  this->mStateBlockMask.mFlags[1] = v5;
  mOffset = this->mMaterialUser.mOffset;
  if ( mOffset )
    v3 = (Illusion::MaterialUser *)((char *)&this->mMaterialUser + mOffset);
  Illusion::MaterialUser::OnLoad(v3, this);
}

// File Line: 84
// RVA: 0x941D0
void __fastcall Illusion::Material::OnUnload(Illusion::Material *this)
{
  unsigned int mNumParams; // eax
  __int64 v3; // rdi
  UFG::qResourceHandle *v4; // rbx
  __int64 mOffset; // rax

  mNumParams = this->mNumParams;
  if ( mNumParams )
  {
    v3 = mNumParams;
    v4 = (UFG::qResourceHandle *)&this[1].mNode.mChild[1];
    do
    {
      if ( v4->mNameUID )
        UFG::qResourceHandle::Close(v4);
      v4 = (UFG::qResourceHandle *)((char *)v4 + 56);
      --v3;
    }
    while ( v3 );
  }
  mOffset = this->mMaterialUser.mOffset;
  if ( mOffset )
    _((AMD_HD3D *)((char *)&this->mMaterialUser + mOffset));
  else
    _(0i64);
}

// File Line: 104
// RVA: 0x924A0
Illusion::Material *__fastcall Illusion::Material::GetParamByNameUID(Illusion::Material *this, unsigned int name_uid)
{
  unsigned int mNumParams; // r9d
  int v3; // r8d
  Illusion::Material *result; // rax

  mNumParams = this->mNumParams;
  v3 = 0;
  if ( !mNumParams )
    return 0i64;
  for ( result = this + 1; LODWORD(result->mNode.mParent) != name_uid; result = (Illusion::Material *)((char *)result + 56) )
  {
    if ( ++v3 >= mNumParams )
      return 0i64;
  }
  return result;
}

// File Line: 139
// RVA: 0x1457EC0
__int64 Illusion::_dynamic_initializer_for__gMaterialInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gMaterialInventory,
    "MaterialInventory",
    0xB4C26312,
    0xF5F8516F,
    0,
    0x40u);
  Illusion::gMaterialInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::MaterialInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gMaterialInventory__);
}

// File Line: 147
// RVA: 0x8DD10
void __fastcall Illusion::MaterialInventory::Add(Illusion::MaterialInventory *this, Illusion::Material *resource_data)
{
  Illusion::Material::OnLoad(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 158
// RVA: 0x94870
void __fastcall Illusion::MaterialInventory::Remove(
        Illusion::MaterialInventory *this,
        Illusion::Material *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  Illusion::Material::OnUnload(resource_data);
}

// File Line: 169
// RVA: 0x92C10
__int64 __fastcall Illusion::MaterialInventory::Load(Illusion::MaterialInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != -121931850 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Add(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 188
// RVA: 0x95AE0
__int64 __fastcall Illusion::MaterialInventory::Unload(Illusion::MaterialInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != -121931850 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Remove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 216
// RVA: 0x93580
void __fastcall Illusion::MaterialTable::OnLoad(Illusion::MaterialTable *this)
{
  AMD_HD3D *v2; // rbp
  unsigned int i; // esi
  __int64 v4; // rax
  UFG::qResourceHandle *v5; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  __int64 mOffset; // rax

  if ( this )
    Illusion::MaterialTable::MaterialTable(this);
  v2 = 0i64;
  for ( i = 0; i < this->mNumMaterials; ++i )
  {
    v4 = 32i64 * i;
    v5 = (UFG::qResourceHandle *)((char *)&this[1] + v4);
    if ( v5 )
      UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)((char *)&this[1] + v4));
    Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(v5, 0xB4C26312, v5->mNameUID, Inventory);
  }
  mOffset = this->mMaterialTableUser.mOffset;
  if ( mOffset )
    v2 = (AMD_HD3D *)((char *)&this->mMaterialTableUser + mOffset);
  _(v2);
}

// File Line: 235
// RVA: 0x94240
void __fastcall Illusion::MaterialTable::OnUnload(Illusion::MaterialTable *this)
{
  AMD_HD3D *v1; // rbp
  unsigned int i; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  __int64 mOffset; // rax

  v1 = 0i64;
  for ( i = 0; i < this->mNumMaterials; ++i )
  {
    Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&this[1].mNode + i, Inventory);
  }
  mOffset = this->mMaterialTableUser.mOffset;
  if ( mOffset )
    v1 = (AMD_HD3D *)((char *)&this->mMaterialTableUser + mOffset);
  _(v1);
}

// File Line: 265
// RVA: 0x1457F20
__int64 Illusion::_dynamic_initializer_for__gMaterialTableInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gMaterialTableInventory,
    "MaterialTableInventory",
    0x80D1F139,
    0xEB9FE716,
    0,
    0);
  Illusion::gMaterialTableInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::MaterialTableInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gMaterialTableInventory__);
}

// File Line: 274
// RVA: 0x8DD40
void __fastcall Illusion::MaterialTableInventory::Add(
        Illusion::MaterialTableInventory *this,
        Illusion::MaterialTable *resource_data)
{
  Illusion::MaterialTable::OnLoad(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 285
// RVA: 0x94890
void __fastcall Illusion::MaterialTableInventory::Remove(
        Illusion::MaterialTableInventory *this,
        Illusion::MaterialTable *resource_data)
{
  Illusion::MaterialTable::OnUnload(resource_data);
  UFG::qResourceInventory::Remove(this, resource_data);
}

