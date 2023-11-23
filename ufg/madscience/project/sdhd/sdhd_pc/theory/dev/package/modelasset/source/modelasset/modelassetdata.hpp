// File Line: 42
// RVA: 0x21F790
void __fastcall UFG::ModelData::ModelData(UFG::ModelData *this, MemImageLoadFlag f)
{
  UFG::ModelData *v2; // r12
  unsigned __int64 mUID; // rax
  unsigned int i; // r13d
  __int64 v5; // rsi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  unsigned int v8; // r15d
  __int64 v9; // r14
  __int64 v10; // rbx
  UFG::qResourceHandle *v11; // rdi
  UFG::qResourceHandle *v12; // rbp
  UFG::qResourceHandle *v13; // rbx
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  __int64 v18; // rdi
  UFG::qResourceInventory *v19; // rax
  UFG::qResourceWarehouse *v20; // rax
  char *v21; // rcx

  v2 = this;
  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelData::`vftable;
  this->mModels.mData.mFlags = 2;
  for ( i = 0; i < v2->mModels.mData.mNumItems; ++i )
  {
    v5 = (__int64)&v2->mModels.mData.mItems[i];
    if ( v5 )
    {
      *(_DWORD *)(v5 + 12) = 2;
      *(_DWORD *)(v5 + 28) = 2;
      UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v5 + 40));
      Inventory = `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x50A819E3u);
        `UFG::qGetResourceInventory<Illusion::BonePalette>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v5 + 40), 0x50A819E3u, *(_DWORD *)(v5 + 64), Inventory);
      v8 = 0;
      if ( *(_DWORD *)(v5 + 24) )
      {
        do
        {
          v9 = 272i64 * v8;
          v10 = v9 + *(_QWORD *)(v5 + 16);
          if ( v10 )
          {
            *(_DWORD *)(v10 + 12) = 2;
            UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)(v10 + 16));
            v11 = (UFG::qResourceHandle *)(v10 + 56);
            UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v10 + 56));
            v12 = (UFG::qResourceHandle *)(v10 + 88);
            UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v10 + 88));
            v13 = (UFG::qResourceHandle *)(v10 + 120);
            `eh vector constructor iterator(
              v13,
              0x20ui64,
              4,
              (void (__fastcall *)(void *))Illusion::BufferHandle::BufferHandle);
            v14 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
            {
              v15 = UFG::qResourceWarehouse::Instance();
              v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x3E5FDA3Eu);
              `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v14;
            }
            UFG::qResourceHandle::Init(v11, 0x3E5FDA3Eu, v11->mNameUID, v14);
            v16 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
            {
              v17 = UFG::qResourceWarehouse::Instance();
              v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x92CDEC8F);
              `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v16;
            }
            UFG::qResourceHandle::Init(v12, 0x92CDEC8F, v12->mNameUID, v16);
            v18 = 4i64;
            do
            {
              v19 = `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result;
              if ( !`UFG::qGetResourceInventory<Illusion::Buffer>::`2::result )
              {
                v20 = UFG::qResourceWarehouse::Instance();
                v19 = UFG::qResourceWarehouse::GetInventory(v20, 0x92CDEC8F);
                `UFG::qGetResourceInventory<Illusion::Buffer>::`2::result = v19;
              }
              UFG::qResourceHandle::Init(v13, 0x92CDEC8F, v13->mNameUID, v19);
              ++v13;
              --v18;
            }
            while ( v18 );
          }
          if ( *(_DWORD *)(v5 + 8) )
            v21 = *(char **)v5;
          else
            v21 = &customCaption;
          *(_QWORD *)(*(_QWORD *)(v5 + 16) + v9 + 264) = v21;
          ++v8;
        }
        while ( v8 < *(_DWORD *)(v5 + 24) );
        v2 = this;
      }
    }
  }
}

// File Line: 50
// RVA: 0x21FBD0
void __fastcall UFG::ModelData::~ModelData(UFG::ModelData *this)
{
  unsigned int i; // ebx
  Illusion::rModel *mItems; // rcx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *p_mHandles; // rdi
  UFG::qReflectHandleBase *j; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v9; // rax

  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelData::`vftable;
  for ( i = 0; i < this->mModels.mData.mNumItems; ++i )
    Illusion::rModel::`scalar deleting destructor(&this->mModels.mData.mItems[i], 0);
  if ( (this->mModels.mData.mFlags & 2) == 0 )
  {
    mItems = this->mModels.mData.mItems;
    if ( mItems )
      Illusion::rModel::`vector deleting destructor(mItems, 3);
  }
  this->mModels.mData.mItems = 0i64;
  *(_QWORD *)&this->mModels.mData.mNumItems = 0i64;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  p_mHandles = &this->mHandles;
  for ( j = (UFG::qReflectHandleBase *)p_mHandles->mNode.mNext;
        j != (UFG::qReflectHandleBase *)p_mHandles;
        j = (UFG::qReflectHandleBase *)p_mHandles->mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qReflectHandleBase::~qReflectHandleBase(j);
    operator delete[](j);
  }
  v8 = p_mHandles->mNode.mPrev;
  v9 = p_mHandles->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mHandles->mNode.mPrev = &p_mHandles->mNode;
  p_mHandles->mNode.mNext = &p_mHandles->mNode;
}

// File Line: 90
// RVA: 0x21F5B0
void __fastcall UFG::CollisionData::CollisionData(UFG::CollisionData *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  UFG::PhysicsResourceHandle *p_mCollisionMeshBundle; // rbx

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::CollisionData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::CollisionData::`vftable;
  p_mCollisionMeshBundle = &this->mCollisionMeshBundle;
  UFG::qResourceHandle::qResourceHandle(&this->mCollisionMeshBundle);
  p_mCollisionMeshBundle->mOwner = 0i64;
  p_mCollisionMeshBundle->mUnloading = 0;
}

// File Line: 105
// RVA: 0x21F6F0
void __fastcall UFG::FreeRunData::FreeRunData(UFG::FreeRunData *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::FreeRunData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::FreeRunData::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mParkourContainerBundle);
}

// File Line: 121
// RVA: 0x21F660
void __fastcall UFG::CoverData::CoverData(UFG::CoverData *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ModelAssetData,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ModelAssetData::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::CoverData::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mDynamicCoverResource);
}

