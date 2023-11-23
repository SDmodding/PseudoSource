// File Line: 73
// RVA: 0x1458130
__int64 Illusion::_dynamic_initializer_for__gShaderInventory__()
{
  UFG::qResourceInventory::qResourceInventory(&Illusion::gShaderInventory, "iShaderInventory", 0x8B5561A1, 0, 0, 0);
  Illusion::gShaderInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iShaderInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gShaderInventory__);
}

// File Line: 81
// RVA: 0x92AE0
// attributes: thunk
void __fastcall Illusion::iShaderInventory::Init(Illusion::iShaderInventory *this)
{
  UFG::qResourceInventory::Init(this);
}

// File Line: 87
// RVA: 0x8E980
void __fastcall Illusion::iShaderInventory::Close(Illusion::iShaderInventory *this)
{
  Illusion::Shader *Head; // rdi
  __int64 mOffset; // rax
  Illusion::ShaderUser *v4; // rcx

  while ( this->mResourceDatas.mTree.mCount )
  {
    Head = (Illusion::Shader *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mResourceDatas);
    this->vfptr->Remove(this, (UFG::qResourceData *)Head);
    Illusion::IShaderPlat::Close(Head);
    mOffset = Head->mShaderUser.mOffset;
    if ( mOffset )
      v4 = (Illusion::ShaderUser *)((char *)&Head->mShaderUser + mOffset);
    else
      v4 = 0i64;
    Illusion::ShaderUser::Close(v4);
    Illusion::Factory::Delete(Head);
  }
  UFG::qResourceInventory::Close(this);
}

// File Line: 121
// RVA: 0x14580D0
__int64 Illusion::_dynamic_initializer_for__gShaderBinaryInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gShaderBinaryInventory,
    "iShaderBinaryInventory",
    0xE80F42E1,
    0x985BE50C,
    0,
    0);
  Illusion::gShaderBinaryInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iShaderBinaryInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gShaderBinaryInventory__);
}

// File Line: 129
// RVA: 0x8DEC0
void __fastcall Illusion::iShaderBinaryInventory::Add(
        Illusion::iShaderBinaryInventory *this,
        Illusion::ShaderBinary *resource_data)
{
  UFG::qString *v4; // rax
  unsigned int mStringHash32; // esi
  Illusion::Shader *v6; // rdi
  Illusion::ShaderUser *v7; // rbp
  __int64 mOffset; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qString result; // [rsp+38h] [rbp-70h] BYREF
  UFG::qString v11; // [rsp+60h] [rbp-48h] BYREF

  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
  UFG::qString::qString(&v11, resource_data->mShaderName);
  UFG::qString::GetFilenameWithoutExtension(v4, &result);
  UFG::qString::~qString(&v11);
  mStringHash32 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
    result.mStringHash32 = mStringHash32;
  }
  v6 = (Illusion::Shader *)Illusion::gShaderInventory.vfptr->Get(&Illusion::gShaderInventory, mStringHash32);
  if ( !v6 )
  {
    v7 = 0i64;
    v6 = (Illusion::Shader *)Illusion::Factory::NewShader(result.mData, mStringHash32, 0i64, 0i64, 0i64);
    v6->mSortID = v6->mNode.mUID;
    Illusion::IShaderPlat::Init(v6);
    mOffset = v6->mShaderUser.mOffset;
    if ( mOffset )
      v7 = (Illusion::ShaderUser *)((char *)&v6->mShaderUser + mOffset);
    Illusion::ShaderUser::Init(v7, v6);
    v9 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v9, &v6->UFG::qResourceData);
  }
  Illusion::IShaderPlat::AddShaderStage(v6, resource_data);
  UFG::qString::~qString(&result);
}

