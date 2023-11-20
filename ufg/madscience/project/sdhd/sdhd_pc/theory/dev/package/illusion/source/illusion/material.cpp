// File Line: 27
// RVA: 0x934A0
void __fastcall Illusion::Material::OnLoad(Illusion::Material *this)
{
  Illusion::Material *v1; // rdi
  unsigned int v2; // eax
  Illusion::MaterialUser *v3; // r15
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // r14
  unsigned int *v6; // rbx
  __int64 v7; // rsi
  unsigned int v8; // edx
  __int16 v9; // ax
  unsigned int v10; // er8
  __int64 v11; // rax

  v1 = this;
  if ( this )
    Illusion::Material::Material(this);
  v2 = v1->mNumParams;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  if ( v2 )
  {
    v6 = &v1[1].mTypeUID;
    v7 = v2;
    do
    {
      v8 = *(v6 - 12);
      if ( v8 )
      {
        v9 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v8, 0i64, 0);
        *((_WORD *)v6 - 20) = v9;
        if ( (unsigned int)v9 > 0x3F )
          v5 |= 1i64 << ((unsigned __int8)v9 - 64);
        else
          v4 |= 1i64 << v9;
        v10 = *(v6 - 2);
        if ( v10 )
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)v6 - 1, *v6, v10);
      }
      v6 += 14;
      --v7;
    }
    while ( v7 );
  }
  v1->mStateBlockMask.mFlags[0] = v4;
  v1->mStateBlockMask.mFlags[1] = v5;
  v11 = v1->mMaterialUser.mOffset;
  if ( v11 )
    v3 = (Illusion::MaterialUser *)((char *)&v1->mMaterialUser + v11);
  Illusion::MaterialUser::OnLoad(v3, v1);
}

// File Line: 84
// RVA: 0x941D0
void __fastcall Illusion::Material::OnUnload(Illusion::Material *this)
{
  unsigned int v1; // eax
  Illusion::Material *v2; // rsi
  __int64 v3; // rdi
  UFG::qResourceHandle *v4; // rbx
  __int64 v5; // rax

  v1 = this->mNumParams;
  v2 = this;
  if ( v1 )
  {
    v3 = v1;
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
  v5 = v2->mMaterialUser.mOffset;
  if ( v5 )
    _((AMD_HD3D *)((char *)&v2->mMaterialUser + v5));
  else
    _(0i64);
}

// File Line: 104
// RVA: 0x924A0
Illusion::Material *__fastcall Illusion::Material::GetParamByNameUID(Illusion::Material *this, unsigned int name_uid)
{
  unsigned int v2; // er9
  unsigned int v3; // er8
  Illusion::Material *result; // rax

  v2 = this->mNumParams;
  v3 = 0;
  if ( !v2 )
    return 0i64;
  result = this + 1;
  while ( LODWORD(result->mNode.mParent) != name_uid )
  {
    ++v3;
    result = (Illusion::Material *)((char *)result + 56);
    if ( v3 >= v2 )
      return 0i64;
  }
  return result;
}

// File Line: 139
// RVA: 0x1457EC0
__int64 Illusion::_dynamic_initializer_for__gMaterialInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gMaterialInventory.vfptr,
    "MaterialInventory",
    0xB4C26312,
    0xF5F8516F,
    0,
    0x40u);
  Illusion::gMaterialInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::MaterialInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gMaterialInventory__);
}

// File Line: 147
// RVA: 0x8DD10
void __fastcall Illusion::MaterialInventory::Add(Illusion::MaterialInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::MaterialInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Illusion::Material::OnLoad((Illusion::Material *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v2->vfptr, v3);
}

// File Line: 158
// RVA: 0x94870
void __fastcall Illusion::MaterialInventory::Remove(Illusion::MaterialInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::Material *v2; // rbx

  v2 = (Illusion::Material *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  Illusion::Material::OnUnload(v2);
}

// File Line: 169
// RVA: 0x92C10
signed __int64 __fastcall Illusion::MaterialInventory::Load(Illusion::MaterialInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != -121931850 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Add((UFG::qResourceInventory *)this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 188
// RVA: 0x95AE0
signed __int64 __fastcall Illusion::MaterialInventory::Unload(Illusion::MaterialInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != -121931850 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Remove((UFG::qResourceInventory *)this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 216
// RVA: 0x93580
void __fastcall Illusion::MaterialTable::OnLoad(Illusion::MaterialTable *this)
{
  Illusion::MaterialTable *v1; // rdi
  AMD_HD3D *v2; // rbp
  unsigned int v3; // esi
  signed __int64 v4; // rax
  UFG::qResourceHandle *v5; // rbx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  __int64 v8; // rax

  v1 = this;
  if ( this )
    Illusion::MaterialTable::MaterialTable(this);
  v2 = 0i64;
  v3 = 0;
  if ( v1->mNumMaterials )
  {
    do
    {
      v4 = 32i64 * v3;
      v5 = (UFG::qResourceHandle *)((char *)&v1[1] + v4);
      if ( (Illusion::MaterialTable *)((char *)&v1[1] + v4) )
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)((char *)&v1[1] + v4));
      v6 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
        `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v6;
      }
      UFG::qResourceHandle::Init(v5, 0xB4C26312, v5->mNameUID, v6);
      ++v3;
    }
    while ( v3 < v1->mNumMaterials );
  }
  v8 = v1->mMaterialTableUser.mOffset;
  if ( v8 )
    v2 = (AMD_HD3D *)((char *)&v1->mMaterialTableUser + v8);
  _(v2);
}

// File Line: 235
// RVA: 0x94240
void __fastcall Illusion::MaterialTable::OnUnload(Illusion::MaterialTable *this)
{
  AMD_HD3D *v1; // rbp
  Illusion::MaterialTable *v2; // rdi
  unsigned int i; // ebx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  __int64 v6; // rax

  v1 = 0i64;
  v2 = this;
  for ( i = 0; i < v2->mNumMaterials; ++i )
  {
    v4 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0xB4C26312);
      `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2[1].mNode + i, v4);
  }
  v6 = v2->mMaterialTableUser.mOffset;
  if ( v6 )
    v1 = (AMD_HD3D *)((char *)&v2->mMaterialTableUser + v6);
  _(v1);
}

// File Line: 265
// RVA: 0x1457F20
__int64 Illusion::_dynamic_initializer_for__gMaterialTableInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gMaterialTableInventory.vfptr,
    "MaterialTableInventory",
    0x80D1F139,
    0xEB9FE716,
    0,
    0);
  Illusion::gMaterialTableInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::MaterialTableInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gMaterialTableInventory__);
}

// File Line: 274
// RVA: 0x8DD40
void __fastcall Illusion::MaterialTableInventory::Add(Illusion::MaterialTableInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::MaterialTableInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Illusion::MaterialTable::OnLoad((Illusion::MaterialTable *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v2->vfptr, v3);
}

// File Line: 285
// RVA: 0x94890
void __fastcall Illusion::MaterialTableInventory::Remove(Illusion::MaterialTableInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::MaterialTableInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Illusion::MaterialTable::OnUnload((Illusion::MaterialTable *)resource_data);
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v2->vfptr, v3);
}

