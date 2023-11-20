// File Line: 42
// RVA: 0x21F790
void __fastcall UFG::ModelData::ModelData(UFG::ModelData *this, MemImageLoadFlag f)
{
  UFG::ModelData *v2; // r12
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  unsigned int v5; // er13
  signed __int64 v6; // rsi
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  unsigned int v9; // er15
  signed __int64 v10; // r14
  signed __int64 v11; // rbx
  UFG::qResourceHandle *v12; // rdi
  UFG::qResourceHandle *v13; // rbp
  UFG::qResourceHandle *v14; // rbx
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  signed __int64 v19; // rdi
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  char *v22; // rcx
  UFG::ModelData *v23; // [rsp+A0h] [rbp+8h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v24; // [rsp+B0h] [rbp+18h]

  v23 = this;
  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v24 = &this->mHandles;
  v24->mNode.mPrev = &v24->mNode;
  v24->mNode.mNext = &v24->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelData::`vftable;
  this->mModels.mData.mFlags = 2;
  v5 = 0;
  if ( this->mModels.mData.mNumItems )
  {
    do
    {
      v6 = (signed __int64)&v2->mModels.mData.mItems[v5];
      if ( v6 )
      {
        *(_DWORD *)(v6 + 12) = 2;
        *(_DWORD *)(v6 + 28) = 2;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v6 + 40));
        v7 = `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result )
        {
          v8 = UFG::qResourceWarehouse::Instance();
          v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x50A819E3u);
          `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result = v7;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v6 + 40), 0x50A819E3u, *(_DWORD *)(v6 + 64), v7);
        v9 = 0;
        if ( *(_DWORD *)(v6 + 24) )
        {
          do
          {
            v10 = 272i64 * v9;
            v11 = v10 + *(_QWORD *)(v6 + 16);
            if ( v11 )
            {
              *(_DWORD *)(v11 + 12) = 2;
              UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)(v11 + 16));
              v12 = (UFG::qResourceHandle *)(v11 + 56);
              UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v11 + 56));
              v13 = (UFG::qResourceHandle *)(v11 + 88);
              UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v11 + 88));
              v14 = (UFG::qResourceHandle *)(v11 + 120);
              `eh vector constructor iterator(
                v14,
                0x20ui64,
                4,
                (void (__fastcall *)(void *))Illusion::BufferHandle::BufferHandle);
              v15 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
              if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
              {
                v16 = UFG::qResourceWarehouse::Instance();
                v15 = UFG::qResourceWarehouse::GetInventory(v16, 0x3E5FDA3Eu);
                `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v15;
              }
              UFG::qResourceHandle::Init(v12, 0x3E5FDA3Eu, v12->mNameUID, v15);
              v17 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
              if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
              {
                v18 = UFG::qResourceWarehouse::Instance();
                v17 = UFG::qResourceWarehouse::GetInventory(v18, 0x92CDEC8F);
                `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v17;
              }
              UFG::qResourceHandle::Init(v13, 0x92CDEC8F, v13->mNameUID, v17);
              v19 = 4i64;
              do
              {
                v20 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
                if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
                {
                  v21 = UFG::qResourceWarehouse::Instance();
                  v20 = UFG::qResourceWarehouse::GetInventory(v21, 0x92CDEC8F);
                  `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v20;
                }
                UFG::qResourceHandle::Init(v14, 0x92CDEC8F, v14->mNameUID, v20);
                ++v14;
                --v19;
              }
              while ( v19 );
            }
            if ( *(_DWORD *)(v6 + 8) )
              v22 = *(char **)v6;
            else
              v22 = &customWorldMapCaption;
            *(_QWORD *)(*(_QWORD *)(v6 + 16) + v10 + 264) = v22;
            ++v9;
          }
          while ( v9 < *(_DWORD *)(v6 + 24) );
          v2 = v23;
        }
      }
      ++v5;
    }
    while ( v5 < v2->mModels.mData.mNumItems );
  }
}

// File Line: 50
// RVA: 0x21FBD0
void __fastcall UFG::ModelData::~ModelData(UFG::ModelData *this)
{
  UFG::ModelData *v1; // rdi
  unsigned int v2; // ebx
  Illusion::rModel *v3; // rcx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // rdi
  UFG::qReflectHandleBase *i; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v6; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v7; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelData::`vftable;
  v2 = 0;
  if ( this->mModels.mData.mNumItems )
  {
    do
      Illusion::rModel::`scalar deleting destructor(&v1->mModels.mData.mItems[v2++], 0);
    while ( v2 < v1->mModels.mData.mNumItems );
  }
  if ( !(v1->mModels.mData.mFlags & 2) )
  {
    v3 = v1->mModels.mData.mItems;
    if ( v3 )
      Illusion::rModel::`vector deleting destructor(v3, 3);
  }
  v1->mModels.mData.mItems = 0i64;
  *(_QWORD *)&v1->mModels.mData.mNumItems = 0i64;
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v4 = &v1->mHandles;
  for ( i = (UFG::qReflectHandleBase *)v4->mNode.mNext;
        i != (UFG::qReflectHandleBase *)v4;
        i = (UFG::qReflectHandleBase *)v4->mNode.mNext )
  {
    v6 = i->mPrev;
    v7 = i->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    i->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&i->mPrev;
    UFG::qReflectHandleBase::~qReflectHandleBase(i);
    operator delete[](i);
  }
  v8 = v4->mNode.mPrev;
  v9 = v4->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 90
// RVA: 0x21F5B0
void __fastcall UFG::CollisionData::CollisionData(UFG::CollisionData *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::PhysicsResourceHandle *v4; // rbx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::CollisionData::`vftable;
  v4 = &this->mCollisionMeshBundle;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mCollisionMeshBundle.mPrev);
  v4->mOwner = 0i64;
  v4->mUnloading = 0;
}

// File Line: 105
// RVA: 0x21F6F0
void __fastcall UFG::FreeRunData::FreeRunData(UFG::FreeRunData *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+50h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v4 = &this->mHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::FreeRunData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::FreeRunData::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mParkourContainerBundle.mPrev);
}

// File Line: 121
// RVA: 0x21F660
void __fastcall UFG::CoverData::CoverData(UFG::CoverData *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v2; // rdx
  unsigned __int64 v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+50h] [rbp+18h]

  v2 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v3 = this->mBaseNode.mUID;
  v2->mBaseNode.mUID = 0i64;
  v2->mBaseNode.mParent = &v2->mBaseNode;
  v2->mBaseNode.mChildren[0] = &v2->mBaseNode;
  v2->mBaseNode.mChildren[1] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[0] = &v2->mBaseNode;
  v2->mBaseNode.mNeighbours[1] = &v2->mBaseNode;
  v2->mBaseNode.mUID = v3;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v4 = &this->mHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::CoverData::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mDynamicCoverResource);
}

