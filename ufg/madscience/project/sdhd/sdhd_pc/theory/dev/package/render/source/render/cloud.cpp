// File Line: 7
// RVA: 0x62B00
void __fastcall Render::CloudScene::CloudScene(Render::CloudScene *this)
{
  Render::CloudScene *v1; // rdi
  __int64 v2; // rbx
  __int64 v3; // rax
  signed __int64 v4; // rdx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = 0i64;
  if ( v1->mNumClouds )
  {
    do
    {
      v3 = v1->mInstances.mOffset;
      if ( v3 )
        v4 = (signed __int64)&v1->mInstances + v3;
      else
        v4 = 0i64;
      if ( v4 + 192 * v2 )
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v4 + 192 * v2 + 64));
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mNumClouds );
  }
}

// File Line: 24
// RVA: 0x1456A70
__int64 Render::_dynamic_initializer_for__gCloudSceneInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gCloudSceneInventory.vfptr,
    "CloudSceneInventory",
    0x4438A32Fu,
    0xD49B8DA4,
    0,
    0);
  Render::gCloudSceneInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::CloudSceneInventory::`vftable;
  return atexit(Render::_dynamic_atexit_destructor_for__gCloudSceneInventory__);
}

// File Line: 32
// RVA: 0x62E30
void __fastcall Render::CloudSceneInventory::Add(Render::CloudSceneInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Render::CloudSceneInventory *v3; // rbp
  __int64 v4; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax
  signed __int64 v6; // rdx
  UFG::qResourceHandle *v7; // rsi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    Render::CloudScene::CloudScene((Render::CloudScene *)resource_data);
  v4 = 0i64;
  if ( LODWORD(v2[1].mNode.mParent) )
  {
    do
    {
      v5 = v2[1].mResourceHandles.mNode.mPrev;
      if ( v5 )
        v6 = (signed __int64)&v2[1].mResourceHandles + (_QWORD)v5;
      else
        v6 = 0i64;
      v7 = (UFG::qResourceHandle *)(v6 + 192 * v4);
      v8 = `UFG::qGetResourceInventory<Render::Cloud>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::Cloud>::`2::result )
      {
        v9 = UFG::qResourceWarehouse::Instance();
        v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x528C47E3u);
        `UFG::qGetResourceInventory<Render::Cloud>::`2::result = v8;
      }
      UFG::qResourceHandle::Init(v7 + 2, 0x528C47E3u, v7[2].mNameUID, v8);
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < LODWORD(v2[1].mNode.mParent) );
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 47
// RVA: 0x62F40
void __fastcall Render::CloudSceneInventory::Remove(Render::CloudSceneInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rsi
  __int64 v3; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  signed __int64 v5; // rbx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v8; // rdi
  UFG::qResourceHandle *v9; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v11; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rax

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = 0i64;
  if ( LODWORD(v2[1].mNode.mParent) )
  {
    do
    {
      v4 = v2[1].mResourceHandles.mNode.mPrev;
      if ( v4 )
        v5 = (signed __int64)&v2[1].mResourceHandles + (_QWORD)v4;
      else
        v5 = 0i64;
      v6 = `UFG::qGetResourceInventory<Render::Cloud>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::Cloud>::`2::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x528C47E3u);
        `UFG::qGetResourceInventory<Render::Cloud>::`2::result = v6;
      }
      UFG::qResourceHandle::Close((UFG::qResourceHandle *)(v5 + 192 * v3 + 64), v6);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < LODWORD(v2[1].mNode.mParent) );
  }
  v8 = &v2->mResourceHandles;
  v9 = (UFG::qResourceHandle *)v2->mResourceHandles.mNode.mNext;
  if ( v9 != (UFG::qResourceHandle *)&v2->mResourceHandles )
  {
    do
    {
      v10 = v9->mPrev;
      v11 = v9->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v9->mPrev;
      v9->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v9->mPrev;
      UFG::qResourceHandle::~qResourceHandle(v9);
      operator delete[](v9);
      v9 = (UFG::qResourceHandle *)v2->mResourceHandles.mNode.mNext;
    }
    while ( v9 != (UFG::qResourceHandle *)v8 );
  }
  v12 = v8->mNode.mPrev;
  v13 = v2->mResourceHandles.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v8->mNode.mPrev = &v8->mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
}

// File Line: 70
// RVA: 0x1456A10
__int64 Render::_dynamic_initializer_for__gCloudInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gCloudInventory.vfptr,
    "CloudInventory",
    0x528C47E3u,
    0x6526B66u,
    0,
    0);
  Render::gCloudInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::CloudInventory::`vftable;
  return atexit(Render::_dynamic_atexit_destructor_for__gCloudInventory__);
}

// File Line: 78
// RVA: 0x62D90
void __fastcall Render::CloudInventory::Add(Render::CloudInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Render::CloudInventory *v3; // rsi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2[1].mTypeUID);
  }
  v4 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v4;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2[1].mTypeUID, 0x92CDEC8F, *(_DWORD *)&v2[1].mDebugName[20], v4);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 90
// RVA: 0x62EF0
void __fastcall Render::CloudInventory::Remove(Render::CloudInventory *this, UFG::qResourceData *resource_data)
{
  Render::Cloud *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax

  v2 = (Render::Cloud *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x92CDEC8F);
    `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v3;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mWispBuffer.mPrev, v3);
  Render::Cloud::~Cloud(v2);
}

