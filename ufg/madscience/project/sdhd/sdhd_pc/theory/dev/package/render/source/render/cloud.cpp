// File Line: 7
// RVA: 0x62B00
void __fastcall Render::CloudScene::CloudScene(Render::CloudScene *this)
{
  __int64 i; // rbx
  __int64 mOffset; // rax
  char *v4; // rdx

  UFG::qResourceData::qResourceData(this);
  for ( i = 0i64; (unsigned int)i < this->mNumClouds; i = (unsigned int)(i + 1) )
  {
    mOffset = this->mInstances.mOffset;
    if ( mOffset )
      v4 = (char *)&this->mInstances + mOffset;
    else
      v4 = 0i64;
    if ( &v4[192 * i] )
      UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v4[192 * i + 64]);
  }
}

// File Line: 24
// RVA: 0x1456A70
__int64 Render::_dynamic_initializer_for__gCloudSceneInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gCloudSceneInventory,
    "CloudSceneInventory",
    0x4438A32Fu,
    0xD49B8DA4,
    0,
    0);
  Render::gCloudSceneInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::CloudSceneInventory::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gCloudSceneInventory__);
}

// File Line: 32
// RVA: 0x62E30
void __fastcall Render::CloudSceneInventory::Add(Render::CloudSceneInventory *this, Render::CloudScene *resource_data)
{
  __int64 i; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mOffset; // rax
  char *v6; // rdx
  UFG::qResourceHandle *v7; // rsi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax

  if ( resource_data )
    Render::CloudScene::CloudScene(resource_data);
  for ( i = 0i64; (unsigned int)i < resource_data->mNumClouds; i = (unsigned int)(i + 1) )
  {
    mOffset = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)resource_data->mInstances.mOffset;
    if ( mOffset )
      v6 = (char *)&resource_data->mInstances + (_QWORD)mOffset;
    else
      v6 = 0i64;
    v7 = (UFG::qResourceHandle *)&v6[192 * i];
    Inventory = `UFG::qGetResourceInventory<Render::Cloud>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::Cloud>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x528C47E3u);
      `UFG::qGetResourceInventory<Render::Cloud>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(v7 + 2, 0x528C47E3u, v7[2].mNameUID, Inventory);
  }
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 47
// RVA: 0x62F40
void __fastcall Render::CloudSceneInventory::Remove(
        Render::CloudSceneInventory *this,
        UFG::qResourceData *resource_data)
{
  __int64 i; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  char *v5; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *mNext; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v11; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  for ( i = 0i64; (unsigned int)i < LODWORD(resource_data[1].mNode.mParent); i = (unsigned int)(i + 1) )
  {
    mPrev = resource_data[1].mResourceHandles.mNode.mPrev;
    if ( mPrev )
      v5 = (char *)&resource_data[1].mResourceHandles + (_QWORD)mPrev;
    else
      v5 = 0i64;
    Inventory = `UFG::qGetResourceInventory<Render::Cloud>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::Cloud>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x528C47E3u);
      `UFG::qGetResourceInventory<Render::Cloud>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v5[192 * i + 64], Inventory);
  }
  p_mResourceHandles = &resource_data->mResourceHandles;
  mNext = (UFG::qResourceHandle *)resource_data->mResourceHandles.mNode.mNext;
  if ( mNext != (UFG::qResourceHandle *)&resource_data->mResourceHandles )
  {
    do
    {
      v10 = mNext->mPrev;
      v11 = mNext->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qResourceHandle::~qResourceHandle(mNext);
      operator delete[](mNext);
      mNext = (UFG::qResourceHandle *)resource_data->mResourceHandles.mNode.mNext;
    }
    while ( mNext != (UFG::qResourceHandle *)p_mResourceHandles );
  }
  v12 = p_mResourceHandles->mNode.mPrev;
  v13 = resource_data->mResourceHandles.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  resource_data->mResourceHandles.mNode.mNext = &resource_data->mResourceHandles.mNode;
}

// File Line: 70
// RVA: 0x1456A10
__int64 Render::_dynamic_initializer_for__gCloudInventory__()
{
  UFG::qResourceInventory::qResourceInventory(&Render::gCloudInventory, "CloudInventory", 0x528C47E3u, 0x6526B66u, 0, 0);
  Render::gCloudInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::CloudInventory::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gCloudInventory__);
}

// File Line: 78
// RVA: 0x62D90
void __fastcall Render::CloudInventory::Add(Render::CloudInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&resource_data[1].mTypeUID);
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&resource_data[1].mTypeUID,
    0x92CDEC8F,
    *(_DWORD *)&resource_data[1].mDebugName[20],
    Inventory);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 90
// RVA: 0x62EF0
void __fastcall Render::CloudInventory::Remove(Render::CloudInventory *this, Render::Cloud *resource_data)
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
  UFG::qResourceHandle::Close(&resource_data->mWispBuffer, Inventory);
  Render::Cloud::~Cloud(resource_data);
}

