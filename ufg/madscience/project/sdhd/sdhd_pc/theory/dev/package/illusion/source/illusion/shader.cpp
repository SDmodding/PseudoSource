// File Line: 73
// RVA: 0x1458130
__int64 Illusion::_dynamic_initializer_for__gShaderInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gShaderInventory.vfptr,
    "iShaderInventory",
    0x8B5561A1,
    0,
    0,
    0);
  Illusion::gShaderInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iShaderInventory::`vftable;
  return atexit(Illusion::_dynamic_atexit_destructor_for__gShaderInventory__);
}

// File Line: 81
// RVA: 0x92AE0
void __fastcall Illusion::iShaderInventory::Init(Illusion::iShaderInventory *this)
{
  UFG::qResourceInventory::Init((UFG::qResourceInventory *)&this->vfptr);
}

// File Line: 87
// RVA: 0x8E980
void __fastcall Illusion::iShaderInventory::Close(Illusion::iShaderInventory *this)
{
  Illusion::iShaderInventory *v1; // rbx
  Render::SkinningCacheNode *v2; // rdi
  unsigned __int64 v3; // rax
  Illusion::ShaderUser *v4; // rcx

  v1 = this;
  while ( v1->mResourceDatas.mTree.mCount )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mResourceDatas);
    v1->vfptr->Remove((UFG::qResourceInventory *)&v1->vfptr, (UFG::qResourceData *)v2);
    Illusion::IShaderPlat::Close((Illusion::IShaderPlat *)v2);
    v3 = v2[2].mNode.mUID;
    if ( v3 )
      v4 = (Illusion::ShaderUser *)((char *)&v2[2].mNode.mUID + v3);
    else
      v4 = 0i64;
    Illusion::ShaderUser::Close(v4);
    Illusion::Factory::Delete((Illusion::Shader *)v2);
  }
  UFG::qResourceInventory::Close((UFG::qResourceInventory *)&v1->vfptr);
}

// File Line: 121
// RVA: 0x14580D0
__int64 Illusion::_dynamic_initializer_for__gShaderBinaryInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gShaderBinaryInventory.vfptr,
    "iShaderBinaryInventory",
    0xE80F42E1,
    0x985BE50C,
    0,
    0);
  Illusion::gShaderBinaryInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iShaderBinaryInventory::`vftable;
  return atexit(Illusion::_dynamic_atexit_destructor_for__gShaderBinaryInventory__);
}

// File Line: 129
// RVA: 0x8DEC0
void __fastcall Illusion::iShaderBinaryInventory::Add(Illusion::iShaderBinaryInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::ShaderBinary *v2; // rbx
  Illusion::iShaderBinaryInventory *v3; // rdi
  UFG::qString *v4; // rax
  int v5; // edx
  unsigned int v6; // esi
  Illusion::Shader *v7; // rdi
  Illusion::ShaderUser *v8; // rbp
  UFG::qResourceData *v9; // rax
  __int64 v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qString result; // [rsp+38h] [rbp-70h]
  UFG::qString v13; // [rsp+60h] [rbp-48h]

  v2 = (Illusion::ShaderBinary *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
  UFG::qString::qString(&v13, v2->mShaderName);
  UFG::qString::GetFilenameWithoutExtension(v4, &result);
  UFG::qString::~qString(&v13);
  v6 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    v6 = UFG::qStringHash32(result.mData, result.mStringHash32 | v5);
    result.mStringHash32 = v6;
  }
  v7 = (Illusion::Shader *)Illusion::gShaderInventory.vfptr->Get(
                             (UFG::qResourceInventory *)&Illusion::gShaderInventory,
                             v6);
  if ( !v7 )
  {
    v8 = 0i64;
    v9 = Illusion::Factory::NewShader(result.mData, v6, 0i64, 0i64, 0i64);
    v7 = (Illusion::Shader *)v9;
    v9[1].mNode.mUID = v9->mNode.mUID;
    Illusion::IShaderPlat::Init((Illusion::IShaderPlat *)v9);
    v10 = v7->mShaderUser.mOffset;
    if ( v10 )
      v8 = (Illusion::ShaderUser *)((char *)&v7->mShaderUser + v10);
    Illusion::ShaderUser::Init(v8, v7);
    v11 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v11, (UFG::qResourceData *)&v7->mNode);
  }
  Illusion::IShaderPlat::AddShaderStage((Illusion::IShaderPlat *)v7, v2);
  UFG::qString::~qString(&result);
}

