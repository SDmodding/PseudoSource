// File Line: 67
// RVA: 0xA19DF0
void __fastcall Illusion::BufferLoader::DoCreationTask(Illusion::BufferLoader *this)
{
  Illusion::BufferQueueNode *mBufferNode; // rbx
  __int64 v3; // r8
  Illusion::Buffer *v4; // rcx
  Illusion::Buffer **v5; // rdx
  Illusion::Buffer *v6; // rax
  Illusion::Buffer *v7; // r8
  Illusion::Buffer **v8; // rax
  __int64 v9; // rdx
  Illusion::Buffer *v10; // rcx

  mBufferNode = this->mBufferNode;
  v3 = 31i64;
  v4 = mBufferNode->mRequestingBuffers[0];
  v5 = &mBufferNode->mRequestingBuffers[1];
  do
  {
    v6 = *v5++;
    *(v5 - 2) = v6;
    --v3;
  }
  while ( v3 );
  mBufferNode->mRequestingBuffers[31] = 0i64;
  if ( v4 )
    Illusion::BufferPlat::CreateResources((Illusion::BufferPlat *)&v4[1], this->mBufferNode->mResource);
  while ( 1 )
  {
    v7 = mBufferNode->mRequestingBuffers[0];
    v8 = &mBufferNode->mRequestingBuffers[1];
    v9 = 31i64;
    do
    {
      v10 = *v8++;
      *(v8 - 2) = v10;
      --v9;
    }
    while ( v9 );
    mBufferNode->mRequestingBuffers[31] = 0i64;
    if ( !v7 )
      break;
    Illusion::BufferPlat::AcquireResources((Illusion::BufferPlat *)&v7[1], this->mBufferNode->mResource);
  }
}

// File Line: 82
// RVA: 0xA1F410
void __fastcall Illusion::BufferLoader::PostSyncCreationTask(Illusion::BufferLoader *this)
{
  UFG::qResourceInventory::Add(&Illusion::gBufferD3DResourceInventory, this->mBufferNode->mResource);
}

// File Line: 90
// RVA: 0x15AA5F0
__int64 Illusion::_dynamic_initializer_for__gBufferD3DResourceInventory__()
{
  Illusion::BufferD3DResourceInventory::BufferD3DResourceInventory(&Illusion::gBufferD3DResourceInventory);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gBufferD3DResourceInventory__);
}

// File Line: 94
// RVA: 0xA15870
void __fastcall Illusion::BufferD3DResourceInventory::BufferD3DResourceInventory(
        Illusion::BufferD3DResourceInventory *this)
{
  UFG::qResourceInventory::qResourceInventory(this, "BufferD3DResourceInventory", 0x171246ADu, 0x45E061F6u, 0, 0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::BufferD3DResourceInventory::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mOnLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mOnUnloadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mHighPriorityLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mLoadingQueue.mTree);
}

// File Line: 98
// RVA: 0xA1E1A0
void __fastcall Illusion::BufferD3DResourceInventory::OnBufferLoad(
        Illusion::BufferD3DResourceInventory *this,
        Illusion::Texture *buffer)
{
  Illusion::BufferPlat *p_mMemoryPool; // r13
  unsigned int mUID; // esi
  char *v6; // rax
  Illusion::BufferD3DResource *v7; // rdi
  unsigned int v8; // r15d
  Illusion::BufferD3DResource *v9; // rbx
  UFG::qBaseTreeVariableRB<unsigned __int64> *p_mOnUnloadQueue; // rdi
  UFG::qBaseTreeRB *v11; // rax
  Illusion::TextureQueueNode *v12; // r12
  UFG::qBaseNodeRB **v13; // r8
  int v14; // ecx
  Illusion::Buffer **v15; // rdx
  int v16; // ecx
  Illusion::BufferD3DResource *v17; // rax
  Illusion::BufferD3DResource *v18; // rsi
  UFG::allocator::free_link *v19; // rax
  Illusion::TextureD3DResource *v20; // rax
  Illusion::TextureD3DResource *v21; // rdi
  UFG::allocator::free_link *v22; // rax
  Illusion::BufferD3DResource *v23; // rax
  __int64 v24; // rax
  UFG::qBaseTreeRB *v25; // rax
  UFG::qBaseNodeRB **v26; // rcx
  UFG::allocator::free_link *v27; // rax
  Illusion::TextureD3DResource *v28; // rax
  Illusion::TextureD3DResource *v29; // rdi
  UFG::allocator::free_link *v30; // rax
  Illusion::BufferD3DResource *v31; // rax
  UFG::allocator::free_link *v32; // rax
  Illusion::BufferD3DResource *v33; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v35; // rax

  p_mMemoryPool = (Illusion::BufferPlat *)&buffer->mMemoryPool;
  if ( (buffer->mFlags & 0x40000) != 0 )
  {
    mUID = buffer->mNode.mUID;
    v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v7 = (Illusion::BufferD3DResource *)v6;
    if ( v6 )
    {
      UFG::qResourceData::qResourceData((UFG::qResourceData *)v6, 0x171246ADu, mUID, buffer->mDebugName);
      v7->mGpuResource = 0i64;
      v7->mResourceOffset = 0;
      v7->mStagingResource = 0i64;
      v7->mRefCount = 0;
      v7->mFrameGenerated = 1;
      v7->mShaderResourceView = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    Illusion::BufferPlat::AcquireResources(p_mMemoryPool, v7);
    p_mMemoryPool->mBufferD3DResourceHandle.mData = v7;
    return;
  }
  v8 = buffer->mNode.mUID;
  v9 = 0i64;
  if ( v8 )
  {
    p_mOnUnloadQueue = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue;
    v11 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, v8);
    v12 = (Illusion::TextureQueueNode *)v11;
    if ( v11 )
    {
      v13 = &v11->mNULL.mChild[1];
      v14 = 0;
      v15 = (Illusion::Buffer **)&v11->mNULL.mChild[1];
      while ( *v15 != (Illusion::Buffer *)buffer )
      {
        ++v14;
        ++v15;
        if ( v14 >= 32 )
          goto LABEL_14;
      }
      v16 = v14 + 1;
      if ( v16 < 32 )
      {
        qmemcpy(&v13[v16 - 1], &v13[v16], 8i64 * (unsigned int)(32 - v16));
        p_mOnUnloadQueue = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue;
      }
LABEL_14:
      if ( !*v13 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          p_mOnUnloadQueue,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v11);
        Illusion::TextureQueueNode::`scalar deleting destructor(v12, 1);
      }
    }
  }
  v17 = (Illusion::BufferD3DResource *)this->vfptr->Get(this, v8);
  v18 = v17;
  if ( v17 )
  {
    if ( !UFG::qResourceInventory::smHotSwapMode )
    {
      Illusion::BufferPlat::AcquireResources(p_mMemoryPool, v17);
      goto LABEL_45;
    }
    this->vfptr->Remove(this, v17);
    Illusion::BufferD3DResource::~BufferD3DResource(v18);
    operator delete[](v18);
    v19 = UFG::qMalloc(0x80ui64, "BufferD3DResource", 0x800ui64);
    if ( v19 )
    {
      Illusion::BufferD3DResource::BufferD3DResource((Illusion::BufferD3DResource *)v19, v8, buffer->mDebugName, 0);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    v22 = UFG::qMalloc(0x138ui64, "LoadBufferQueueNode", 0i64);
    if ( v22 )
    {
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v22, v21, buffer);
      v9 = v23;
    }
  }
  else
  {
    v24 = *(_QWORD *)&buffer->mMipMapBias;
    if ( !v24 || !(unsigned int *)((char *)&buffer->mMipMapBias + v24) || BYTE1(buffer->mFlags) )
    {
      v32 = UFG::qMalloc(0x80ui64, "BufferD3DResource", 0x800ui64);
      if ( v32 )
      {
        Illusion::BufferD3DResource::BufferD3DResource((Illusion::BufferD3DResource *)v32, v8, buffer->mDebugName, 0);
        v9 = v33;
      }
      Illusion::BufferPlat::CreateResources(p_mMemoryPool, v9);
      this->vfptr->Add(this, v9);
      goto LABEL_45;
    }
    if ( v8 )
    {
      v25 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, v8);
      if ( v25 )
      {
        v26 = &v25->mNULL.mChild[1];
        while ( *v26 )
        {
          LODWORD(v9) = (_DWORD)v9 + 1;
          ++v26;
          if ( (int)v9 >= 32 )
            goto LABEL_35;
        }
        v25->mNULL.mChild[(int)v9 + 1] = (UFG::qBaseNodeRB *)buffer;
LABEL_35:
        v25->mNULL.mChild[0] = (UFG::qBaseNodeRB *)UFG::qGetTicks();
        goto LABEL_45;
      }
    }
    v27 = UFG::qMalloc(0x80ui64, "BufferD3DResource", 0x800ui64);
    if ( v27 )
    {
      Illusion::BufferD3DResource::BufferD3DResource((Illusion::BufferD3DResource *)v27, v8, buffer->mDebugName, 0);
      v29 = v28;
    }
    else
    {
      v29 = 0i64;
    }
    v30 = UFG::qMalloc(0x138ui64, "LoadBufferQueueNode", 0i64);
    if ( v30 )
    {
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v30, v29, buffer);
      v9 = v31;
    }
  }
  UFG::qBaseTreeRB::Add(&this->mOnLoadQueue.mTree, &v9->mNode);
LABEL_45:
  Inventory = `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result )
  {
    v35 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v35, 0x171246ADu);
    `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&p_mMemoryPool->mBufferD3DResourceHandle, 0x171246ADu, v8, Inventory);
}

// File Line: 183
// RVA: 0xA1E530
void __fastcall Illusion::BufferD3DResourceInventory::OnBufferUnload(
        Illusion::BufferD3DResourceInventory *this,
        Illusion::Texture *buffer)
{
  Illusion::TextureD3DResource *mParent; // r12
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v6; // rax
  Illusion::TextureQueueNode *v7; // r15
  UFG::qBaseNodeRB **v8; // r8
  int v9; // ebx
  Illusion::Buffer **v10; // rcx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rdi
  Illusion::AsyncD3DCreationTask *v14; // rcx
  unsigned int v15; // edx
  UFG::qBaseNodeRB *v16; // rbx
  UFG::qBaseTreeRB *v17; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v18; // r15
  Illusion::Buffer **v19; // rax
  int v20; // ecx
  Illusion::Buffer **v21; // rdx
  int v22; // ecx
  unsigned int v23; // edx
  UFG::qBaseTreeRB *v24; // rax
  UFG::qBaseNodeRB **v25; // rcx
  UFG::qBaseNodeRB **i; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::qBaseNodeRB *v28; // rax

  if ( (buffer->mFlags & 0x40000) != 0 )
    return;
  mParent = (Illusion::TextureD3DResource *)this->vfptr->Get(this, buffer->mNode.mUID);
  if ( !mParent )
  {
    mUID = buffer->mNode.mUID;
    if ( mUID )
    {
      v6 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, mUID);
      v7 = (Illusion::TextureQueueNode *)v6;
      if ( v6 )
      {
        v8 = &v6->mNULL.mChild[1];
        v9 = 0;
        v10 = (Illusion::Buffer **)&v6->mNULL.mChild[1];
        while ( *v10 != (Illusion::Buffer *)buffer )
        {
          ++v9;
          ++v10;
          if ( v9 >= 32 )
            goto LABEL_11;
        }
        if ( v9 + 1 < 32 )
          qmemcpy(&v8[v9], &v8[v9 + 1], 8i64 * (unsigned int)(32 - (v9 + 1)));
LABEL_11:
        if ( !*v8 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
          Illusion::TextureQueueNode::`scalar deleting destructor(v7, 1);
        }
        return;
      }
    }
    v11 = buffer->mNode.mUID;
    if ( v11 )
    {
      v12 = UFG::qBaseTreeRB::Get(&this->mLoadingQueue.mTree, v11);
      v13 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v12;
      if ( v12 )
      {
        v14 = (Illusion::AsyncD3DCreationTask *)v12[4].mRoot.mChild[1];
        if ( v14 )
          Illusion::AsyncD3DCreationTask::FinalizeAsyncCreationTask(v14);
        mParent = (Illusion::TextureD3DResource *)v13[1].mParent;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mLoadingQueue,
          v13);
        Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v13, 1);
      }
    }
  }
  v15 = buffer->mNode.mUID;
  v16 = 0i64;
  if ( v15 )
  {
    v17 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, v15);
    v18 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v17;
    if ( v17 )
    {
      mParent = (Illusion::TextureD3DResource *)v17->mNULL.mParent;
      v19 = (Illusion::Buffer **)&v17->mNULL.mChild[1];
      v20 = 0;
      v21 = v19;
      while ( *v21 != (Illusion::Buffer *)buffer )
      {
        ++v20;
        ++v21;
        if ( v20 >= 32 )
          goto LABEL_26;
      }
      v22 = v20 + 1;
      if ( v22 < 32 )
        qmemcpy(&v19[v22 - 1], &v19[v22], 8i64 * (unsigned int)(32 - v22));
LABEL_26:
      if ( !*v19 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue,
          v18);
        Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v18, 1);
      }
    }
  }
  v23 = buffer->mNode.mUID;
  if ( v23 && (v24 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, v23)) != 0i64 )
  {
    v25 = &v24->mNULL.mChild[1];
    for ( i = &v24->mNULL.mChild[1]; *i; ++i )
    {
      LODWORD(v16) = (_DWORD)v16 + 1;
      if ( (int)v16 >= 32 )
        return;
    }
    v25[(int)v16] = (UFG::qBaseNodeRB *)buffer;
  }
  else
  {
    v27 = UFG::qMalloc(0x138ui64, "UnloadBufferQueueNode", 0i64);
    if ( v27 )
    {
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v27, mParent, buffer);
      v16 = v28;
    }
    UFG::qBaseTreeRB::Add(&this->mOnUnloadQueue.mTree, v16);
  }
}

// File Line: 281
// RVA: 0xA1F4A0
void __fastcall Illusion::BufferD3DResourceInventory::ProcessQueuedLoads(
        Illusion::BufferD3DResourceInventory *this,
        bool bBlocking)
{
  float v4; // xmm0_4
  unsigned int *mHighPriorityUIDs; // rdi
  __int64 v6; // rbp
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseNodeRB *p_mRoot; // rbx
  Render::SkinningCacheNode *Head; // rbx
  bool v10; // di
  UFG::allocator::free_link *v11; // rax
  Illusion::AsyncD3DCreationTask *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v14; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v15; // rcx
  __int64 v16; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v17; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v18; // rcx
  __int64 v19; // rdx
  Illusion::BufferD3DResource *mCachedBufferPtr; // rdx
  _QWORD *mUID; // rcx
  __int64 v22; // rdx
  _QWORD *v23; // rax
  int i; // ebp
  Render::SkinningCacheNode *v25; // rbx
  bool v26; // si
  UFG::allocator::free_link *v27; // rax
  Illusion::AsyncD3DCreationTask *v28; // rcx
  UFG::allocator::free_link *v29; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v30; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v31; // rcx
  __int64 v32; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v33; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v34; // rcx
  __int64 v35; // rdx
  Illusion::BufferD3DResource *v36; // rdx
  _QWORD *v37; // rcx
  __int64 v38; // rdx
  _QWORD *v39; // rax

  v4 = (float)Illusion::gNumHighPriorityUIDs;
  if ( (float)Illusion::gNumHighPriorityUIDs >= 4096.0 )
    v4 = FLOAT_4096_0;
  if ( (int)v4 )
  {
    mHighPriorityUIDs = this->mHighPriorityUIDs;
    v6 = (unsigned int)(int)v4;
    do
    {
      if ( *mHighPriorityUIDs )
      {
        v7 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, *mHighPriorityUIDs);
        p_mRoot = &v7->mRoot;
        if ( v7 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v7);
          UFG::qBaseTreeRB::Add(&this->mHighPriorityLoadQueue.mTree, p_mRoot);
        }
      }
      ++mHighPriorityUIDs;
      --v6;
    }
    while ( v6 );
  }
  _InterlockedExchange(&Illusion::gNumHighPriorityUIDs, 0);
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mHighPriorityLoadQueue) )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mHighPriorityLoadQueue);
    v10 = this->vfptr->Get(this, Head->mCachedBufferPtr->mNode.mUID) != 0;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mHighPriorityLoadQueue,
      &Head->mNode);
    if ( !Illusion::gEnableAsyncBufferLoading || bBlocking || v10 )
    {
      v14 = Head[1].mNode.mChild[0];
      v15 = &Head[1].mNode.mChild[1];
      v16 = 31i64;
      do
      {
        *(v15 - 1) = *v15;
        ++v15;
        --v16;
      }
      while ( v16 );
      Head[7].mNode.mChild[1] = 0i64;
      if ( v14 && !v10 )
        Illusion::BufferPlat::CreateResources(
          (Illusion::BufferPlat *)&v14[4].mChild1,
          (Illusion::BufferD3DResource *)Head->mCachedBufferPtr);
      while ( 1 )
      {
        v17 = Head[1].mNode.mChild[0];
        v18 = &Head[1].mNode.mChild[1];
        v19 = 31i64;
        do
        {
          *(v18 - 1) = *v18;
          ++v18;
          --v19;
        }
        while ( v19 );
        Head[7].mNode.mChild[1] = 0i64;
        mCachedBufferPtr = (Illusion::BufferD3DResource *)Head->mCachedBufferPtr;
        if ( !v17 )
          break;
        Illusion::BufferPlat::AcquireResources((Illusion::BufferPlat *)&v17[4].mChild1, mCachedBufferPtr);
      }
      UFG::qResourceInventory::Add(&Illusion::gBufferD3DResourceInventory, mCachedBufferPtr);
      mUID = (_QWORD *)Head[7].mNode.mUID;
      if ( mUID )
      {
        v22 = mUID[1];
        v23 = (_QWORD *)mUID[2];
        *(_QWORD *)(v22 + 8) = v23;
        *v23 = v22;
        mUID[1] = mUID + 1;
        mUID[2] = mUID + 1;
        operator delete[](mUID);
        Head[7].mNode.mUID = 0i64;
      }
      operator delete[](Head);
    }
    else
    {
      UFG::qBaseTreeRB::Add(&this->mLoadingQueue.mTree, (UFG::qBaseNodeRB *)Head);
      v11 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      v12 = (Illusion::AsyncD3DCreationTask *)v11;
      if ( v11 )
      {
        v13 = v11 + 1;
        v13->mNext = v13;
        v13[1].mNext = v13;
        v12->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::AsyncD3DCreationTask::`vftable;
        v12->mTask = 0i64;
        v12->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::BufferLoader::`vftable;
        v12[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)Head;
      }
      else
      {
        v12 = 0i64;
      }
      Head[7].mNode.mUID = (unsigned __int64)v12;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v12);
    }
  }
  for ( i = 0;
        (i < Illusion::gMaxBufferLoadsPerFrame || bBlocking)
     && UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnLoadQueue);
        ++i )
  {
    v25 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnLoadQueue);
    v26 = this->vfptr->Get(this, v25->mCachedBufferPtr->mNode.mUID) != 0;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue,
      &v25->mNode);
    if ( !Illusion::gEnableAsyncBufferLoading || bBlocking || v26 )
    {
      v30 = v25[1].mNode.mChild[0];
      v31 = &v25[1].mNode.mChild[1];
      v32 = 31i64;
      do
      {
        *(v31 - 1) = *v31;
        ++v31;
        --v32;
      }
      while ( v32 );
      v25[7].mNode.mChild[1] = 0i64;
      if ( v30 && !v26 )
        Illusion::BufferPlat::CreateResources(
          (Illusion::BufferPlat *)&v30[4].mChild1,
          (Illusion::BufferD3DResource *)v25->mCachedBufferPtr);
      while ( 1 )
      {
        v33 = v25[1].mNode.mChild[0];
        v34 = &v25[1].mNode.mChild[1];
        v35 = 31i64;
        do
        {
          *(v34 - 1) = *v34;
          ++v34;
          --v35;
        }
        while ( v35 );
        v25[7].mNode.mChild[1] = 0i64;
        v36 = (Illusion::BufferD3DResource *)v25->mCachedBufferPtr;
        if ( !v33 )
          break;
        Illusion::BufferPlat::AcquireResources((Illusion::BufferPlat *)&v33[4].mChild1, v36);
      }
      UFG::qResourceInventory::Add(&Illusion::gBufferD3DResourceInventory, v36);
      v37 = (_QWORD *)v25[7].mNode.mUID;
      if ( v37 )
      {
        v38 = v37[1];
        v39 = (_QWORD *)v37[2];
        *(_QWORD *)(v38 + 8) = v39;
        *v39 = v38;
        v37[1] = v37 + 1;
        v37[2] = v37 + 1;
        operator delete[](v37);
        v25[7].mNode.mUID = 0i64;
      }
      operator delete[](v25);
    }
    else
    {
      UFG::qBaseTreeRB::Add(&this->mLoadingQueue.mTree, (UFG::qBaseNodeRB *)v25);
      v27 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      v28 = (Illusion::AsyncD3DCreationTask *)v27;
      if ( v27 )
      {
        v29 = v27 + 1;
        v29->mNext = v29;
        v29[1].mNext = v29;
        v28->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::AsyncD3DCreationTask::`vftable;
        v28->mTask = 0i64;
        v28->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::BufferLoader::`vftable;
        v28[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)v25;
      }
      else
      {
        v28 = 0i64;
      }
      v25[7].mNode.mUID = (unsigned __int64)v28;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v28);
    }
  }
}usion::AsyncD3DCreationTaskVtbl *)v25;
      }
      else
      {
        v28 = 0i64;
      }
      v25[7].mNode.mUID = (unsigned __int64)v28;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v28);
   

// File Line: 402
// RVA: 0xA227D0
void __fastcall Illusion::BufferD3DResourceInventory::SyncLoadTasks(Illusion::BufferD3DResourceInventory *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *p_mLoadingQueue; // rsi
  Render::SkinningCacheNode *Head; // rbx
  _QWORD *mUID; // rdi
  UFG::qTask *v4; // rdx
  _QWORD *v5; // rcx
  __int64 v6; // rdx
  _QWORD *v7; // rax

  p_mLoadingQueue = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mLoadingQueue;
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_mLoadingQueue) )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_mLoadingQueue);
    mUID = (_QWORD *)Head[7].mNode.mUID;
    v4 = (UFG::qTask *)mUID[3];
    if ( v4 )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v4);
      mUID[3] = 0i64;
      (*(void (__fastcall **)(_QWORD *))(*mUID + 8i64))(mUID);
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mLoadingQueue->mTree, &Head->mNode);
    v5 = (_QWORD *)Head[7].mNode.mUID;
    if ( v5 )
    {
      v6 = v5[1];
      v7 = (_QWORD *)v5[2];
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      v5[1] = v5 + 1;
      v5[2] = v5 + 1;
      operator delete[](v5);
      Head[7].mNode.mUID = 0i64;
    }
    operator delete[](Head);
  }
}

// File Line: 416
// RVA: 0xA1FDB0
void __fastcall Illusion::BufferD3DResourceInventory::ProcessQueuedUnLoads(Illusion::BufferD3DResourceInventory *this)
{
  Render::SkinningCacheNode *Head; // rbp
  Illusion::Buffer *mCachedBufferPtr; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // r9
  UFG::qBaseNodeVariableRB<unsigned __int64> **v5; // rcx
  __int64 v6; // r8
  __int64 v7; // rcx
  __int64 v8; // rcx
  UFG::qResourceHandle *p_mResourceHandles; // rdi
  UFG::qResourceHandle *mNext; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v14; // rax
  _QWORD *mUID; // rcx
  __int64 v16; // rdx
  _QWORD *v17; // rax

  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnUnloadQueue) )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnUnloadQueue);
    mCachedBufferPtr = Head->mCachedBufferPtr;
    while ( 1 )
    {
      v4 = Head[1].mNode.mChild[0];
      v5 = &Head[1].mNode.mChild[1];
      v6 = 31i64;
      do
      {
        *(v5 - 1) = *v5;
        ++v5;
        --v6;
      }
      while ( v6 );
      Head[7].mNode.mChild[1] = 0i64;
      if ( !v4 )
        break;
      if ( (int)--LODWORD(mCachedBufferPtr->mBufferUser.mOffset) <= 0 )
      {
        this->vfptr->Remove(this, (UFG::qResourceData *)mCachedBufferPtr);
        if ( !BYTE4(mCachedBufferPtr->mBufferUser.mOffset) )
        {
          v7 = *(_QWORD *)&mCachedBufferPtr->mBufferType;
          if ( v7 )
          {
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
            *(_QWORD *)&mCachedBufferPtr->mBufferType = 0i64;
          }
          v8 = *(_QWORD *)&mCachedBufferPtr->mElementByteSize;
          if ( v8 )
          {
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
            *(_QWORD *)&mCachedBufferPtr->mElementByteSize = 0i64;
          }
        }
        p_mResourceHandles = (UFG::qResourceHandle *)&mCachedBufferPtr->mResourceHandles;
        mNext = (UFG::qResourceHandle *)mCachedBufferPtr->mResourceHandles.UFG::qResourceData::mNode.mNext;
        if ( mNext != (UFG::qResourceHandle *)&mCachedBufferPtr->mResourceHandles )
        {
          do
          {
            mPrev = mNext->mPrev;
            v12 = mNext->mNext;
            mPrev->mNext = v12;
            v12->mPrev = mPrev;
            mNext->mPrev = mNext;
            mNext->mNext = mNext;
            UFG::qResourceHandle::~qResourceHandle(mNext);
            operator delete[](mNext);
            mNext = (UFG::qResourceHandle *)mCachedBufferPtr->mResourceHandles.UFG::qResourceData::mNode.mNext;
          }
          while ( mNext != p_mResourceHandles );
        }
        v13 = p_mResourceHandles->mPrev;
        v14 = mCachedBufferPtr->mResourceHandles.UFG::qResourceData::mNode.mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        p_mResourceHandles->mPrev = p_mResourceHandles;
        mCachedBufferPtr->mResourceHandles.UFG::qResourceData::mNode.mNext = &mCachedBufferPtr->mResourceHandles.UFG::qResourceData::mNode;
        operator delete[](mCachedBufferPtr);
        UFG::qMemSet(qword_14245AF48, 0, 0x40000u);
      }
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue,
      &Head->mNode);
    mUID = (_QWORD *)Head[7].mNode.mUID;
    if ( mUID )
    {
      v16 = mUID[1];
      v17 = (_QWORD *)mUID[2];
      *(_QWORD *)(v16 + 8) = v17;
      *v17 = v16;
      mUID[1] = mUID + 1;
      mUID[2] = mUID + 1;
      operator delete[](mUID);
      Head[7].mNode.mUID = 0i64;
    }
    operator delete[](Head);
  }
}

// File Line: 453
// RVA: 0xA16260
void __fastcall Illusion::BufferD3DResource::~BufferD3DResource(Illusion::BufferD3DResource *this)
{
  ID3D11Buffer *mGpuResource; // rcx
  ID3D11Buffer *mStagingResource; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  if ( !this->mFrameGenerated )
  {
    mGpuResource = this->mGpuResource;
    if ( mGpuResource )
    {
      mGpuResource->vfptr->Release(mGpuResource);
      this->mGpuResource = 0i64;
    }
    mStagingResource = this->mStagingResource;
    if ( mStagingResource )
    {
      mStagingResource->vfptr->Release(mStagingResource);
      this->mStagingResource = 0i64;
    }
  }
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&this->mResourceHandles);
  mPrev = this->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mResourceHandles.UFG::qResourceData::mNode.mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

// File Line: 473
// RVA: 0xA1E760
void __fastcall Illusion::BufferPlat::OnLoad(Illusion::BufferPlat *this)
{
  if ( this )
  {
    *(_QWORD *)&this->mCpuAccess = 0i64;
    this->mMappedResource = 0i64;
    UFG::qResourceHandle::qResourceHandle(&this->mBufferD3DResourceHandle);
    UFG::qMemSet(this->mPadding, 0, 0x48u);
    this->mBufferD3DResourceHandle.mNameUID = 0;
  }
  Illusion::BufferD3DResourceInventory::OnBufferLoad(
    &Illusion::gBufferD3DResourceInventory,
    (Illusion::Texture *)&this[-2].mPadding[56]);
}

// File Line: 486
// RVA: 0xA16F50
void __fastcall Illusion::BufferPlat::AcquireResources(
        Illusion::BufferPlat *this,
        Illusion::BufferD3DResource *bufferD3D)
{
  __int64 v4; // rax
  unsigned int v5; // eax
  unsigned int v6; // eax

  UFG::qAtomicIncrement(&bufferD3D->mRefCount);
  if ( (this[-1].mPadding[18] & 4) != 0 )
  {
    bufferD3D->mGpuResource = Illusion::gFrameWriteMemoryPlat.mBuffer[Illusion::gFrameWriteMemoryPlat.mFrameMemoryBufferIndex];
    v4 = *(_QWORD *)&this[-1].mPadding[24];
    if ( v4 )
      v5 = (_DWORD)this + v4 - 48 - LODWORD(Illusion::gFrameWriteMemoryPlat.mLockData);
    else
      v5 = -LODWORD(Illusion::gFrameWriteMemoryPlat.mLockData);
    bufferD3D->mResourceOffset = v5;
  }
  else
  {
    if ( (this[-1].mPadding[18] & 1) != 0 )
    {
      v6 = 1;
      if ( (this[-1].mPadding[18] & 2) != 0 )
        v6 = 3;
    }
    else
    {
      v6 = (this[-1].mPadding[18] & 2) != 0 ? 2 : 0;
    }
    this->mCpuAccess = v6;
    this->mMappedResource = 0i64;
    this->mUploadAfterUnmap = 0;
  }
}

// File Line: 516
// RVA: 0xA18DA0
void __fastcall Illusion::BufferPlat::CreateResources(
        Illusion::BufferPlat *this,
        Illusion::BufferD3DResource *bufferD3D)
{
  __int64 v4; // rax
  char *v5; // r10
  char v6; // r15
  unsigned int v7; // r11d
  bool v8; // di
  char v9; // r15
  unsigned int v10; // r9d
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // eax
  int v15; // r8d
  D3D11_SUBRESOURCE_DATA *v16; // r12
  __int16 v17; // ax
  bool v18; // zf
  int v19; // eax
  unsigned int v20; // eax
  ID3D11Buffer *mGpuResource; // rcx
  ID3D11Buffer *mStagingResource; // rcx
  char *v23; // [rsp+20h] [rbp-40h] BYREF
  __int64 v24; // [rsp+28h] [rbp-38h]
  D3D11_BUFFER_DESC v25; // [rsp+30h] [rbp-30h] BYREF
  int v26; // [rsp+48h] [rbp-18h] BYREF
  __int64 v27; // [rsp+4Ch] [rbp-14h]
  int v28; // [rsp+54h] [rbp-Ch]
  int v29; // [rsp+58h] [rbp-8h]

  UFG::qAtomicIncrement(&bufferD3D->mRefCount);
  v4 = *(_QWORD *)&this[-1].mPadding[24];
  if ( v4 )
    v5 = &this[-1].mPadding[v4 + 24];
  else
    v5 = 0i64;
  v6 = this[-1].mPadding[18];
  v7 = *(_DWORD *)&this[-1].mPadding[20];
  v8 = (v6 & 2) != 0;
  v9 = v6 & 1;
  if ( v9 )
  {
    v10 = 1;
    if ( v8 )
      v10 = 3;
  }
  else
  {
    v10 = v8 ? 2 : 0;
  }
  this->mCpuAccess = v10;
  v11 = (unsigned __int8)this[-1].mPadding[16];
  *(_QWORD *)&v25.CPUAccessFlags = 0i64;
  v25.StructureByteStride = 0;
  v25.ByteWidth = v7;
  v25.Usage = D3D11_USAGE_DEFAULT;
  if ( v11 )
  {
    v12 = v11 - 1;
    if ( !v12 )
    {
      v15 = 2;
      goto LABEL_15;
    }
    if ( v12 != 1 )
    {
      v13 = *(unsigned __int16 *)&this[-1].mPadding[18];
      v14 = *(_WORD *)&this[-1].mPadding[18] & 0x10;
      v25.MiscFlags = (2 * (*(_WORD *)&this[-1].mPadding[18] & 0x20)) | (v13 >> 1) & 0x20;
      v15 = v13 & 8 | (8 * v14);
      v25.StructureByteStride = *(_DWORD *)&this[-1].mPadding[32];
      goto LABEL_15;
    }
  }
  v15 = 1;
LABEL_15:
  v25.BindFlags = v15;
  if ( v10 == 2 )
  {
    v25.Usage = D3D11_USAGE_DYNAMIC;
    v25.CPUAccessFlags = 65536;
  }
  else if ( v5 )
  {
    v25.Usage = v10 == 0;
  }
  v23 = v5;
  v24 = 0i64;
  v16 = (D3D11_SUBRESOURCE_DATA *)&v23;
  if ( !v7 )
    v16 = 0i64;                                 // CreateBuffer Call
  if ( ((int (__fastcall *)(ID3D11Device *, D3D11_BUFFER_DESC *, D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **, char *, __int64, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
         UFG::gD3D11Device,
         &v25,
         v16,
         &bufferD3D->mGpuResource,
         v23,
         v24,
         *(_QWORD *)&v25.ByteWidth,
         *(_QWORD *)&v25.BindFlags,
         *(_QWORD *)&v25.MiscFlags) < 0 )
    goto $D3D_ERROR_HANDLER_1;
  v17 = *(_WORD *)&this[-1].mPadding[18];
  if ( (v17 & 8) != 0 )
  {
    v18 = (v17 & 0x40) == 0;
    v19 = *(_DWORD *)&this[-1].mPadding[36];
    v26 = 0;
    v28 = v19;
    if ( v18 )
    {
      v27 = 1i64;
    }
    else
    {
      v27 = 11i64;
      v29 = 0;
    }
    if ( ((int (__fastcall *)(ID3D11Device *, ID3D11Buffer *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
           UFG::gD3D11Device,
           bufferD3D->mGpuResource,
           &v26,
           &bufferD3D->mShaderResourceView) < 0 )
      goto $D3D_ERROR_HANDLER_1;
  }
  this->mMappedResource = 0i64;
  this->mUploadAfterUnmap = 0;
  if ( v9 )
  {
    v20 = 0x20000;
    *(_QWORD *)&v25.Usage = 3i64;
    if ( v8 )
      v20 = 196608;
    v25.CPUAccessFlags = v20;
    if ( ((int (__fastcall *)(ID3D11Device *, D3D11_BUFFER_DESC *, D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
           UFG::gD3D11Device,
           &v25,
           v16,
           &bufferD3D->mStagingResource) < 0 )
    {
$D3D_ERROR_HANDLER_1:
      mGpuResource = bufferD3D->mGpuResource;
      if ( mGpuResource )
      {
        mGpuResource->vfptr->Release(mGpuResource);
        bufferD3D->mGpuResource = 0i64;
      }
      mStagingResource = bufferD3D->mStagingResource;
      if ( mStagingResource )
      {
        mStagingResource->vfptr->Release(mStagingResource);
        bufferD3D->mStagingResource = 0i64;
      }
    }
  }
}

// File Line: 628
// RVA: 0xA1C3E0
__int64 __fastcall Illusion::BufferPlat::Lock(Illusion::BufferPlat *this, Illusion::IBufferPlat::LockType lockType)
{
  unsigned __int8 v2; // si
  int v4; // edx
  __int64 v5; // r9
  UFG::qBaseNodeRB *mParent; // rdi
  __int64 v7; // rax
  __int64 v9[3]; // [rsp+30h] [rbp-18h] BYREF

  v2 = 0;
  if ( lockType == LOCK_READ )
  {
    if ( ((this->mCpuAccess - 1) & 0xFFFFFFFD) != 0 )
      return 0i64;
    v5 = 1i64;
    goto LABEL_10;
  }
  v4 = lockType - 1;
  if ( v4 )
  {
    if ( v4 != 1 || this->mCpuAccess != 3 )
      return 0i64;
    v5 = 3i64;
    v2 = 1;
LABEL_10:
    mParent = this->mBufferD3DResourceHandle.mData[1].mNode.mChild[1];
    goto LABEL_11;
  }
  if ( this->mCpuAccess != 2 )
    return 0i64;
  v5 = 4i64;
  mParent = this->mBufferD3DResourceHandle.mData[1].mNode.mParent;
LABEL_11:
  if ( mParent )
  {
    v9[1] = 0i64;
    v7 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
    v9[0] = 0i64;
    if ( (*(int (__fastcall **)(_QWORD, UFG::qBaseNodeRB *, _QWORD, __int64, _DWORD, __int64 *))(**(_QWORD **)(v7 + 104)
                                                                                               + 112i64))(
           *(_QWORD *)(v7 + 104),
           mParent,
           0i64,
           v5,
           0,
           v9) >= 0 )
    {
      this->mMappedResource = (ID3D11Buffer *)mParent;
      this->mUploadAfterUnmap = v2;
      return v9[0];
    }
  }
  return 0i64;
}

// File Line: 688
// RVA: 0xA22990
void __fastcall Illusion::BufferPlat::Unlock(Illusion::BufferPlat *this)
{
  ID3D11Buffer *mMappedResource; // rdx
  _QWORD *v3; // rdi

  mMappedResource = this->mMappedResource;
  if ( mMappedResource )
  {
    v3 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    (*(void (__fastcall **)(_QWORD, ID3D11Buffer *, _QWORD))(*(_QWORD *)*v3 + 120i64))(*v3, mMappedResource, 0i64);
    if ( this->mUploadAfterUnmap )
      (*(void (__fastcall **)(_QWORD, UFG::qBaseNodeRB *, ID3D11Buffer *))(*(_QWORD *)*v3 + 376i64))(
        *v3,
        this->mBufferD3DResourceHandle.mData[1].mNode.mParent,
        this->mMappedResource);
    this->mMappedResource = 0i64;
    this->mUploadAfterUnmap = 0;
  }
  else
  {
    this->mMappedResource = 0i64;
    this->mUploadAfterUnmap = 0;
  }
}

// File Line: 714
// RVA: 0xA1E7D0
void __fastcall Illusion::IBufferPlat::OnLoad(Illusion::IBufferPlat *this)
{
  Illusion::IBufferPlat *v1; // rbx

  v1 = this + 144;
  Illusion::BufferPlat::OnLoad((Illusion::BufferPlat *)&this[144]);
  if ( *(_QWORD *)v1 )
    _((AMD_HD3D *)&v1[*(_QWORD *)v1]);
  else
    _(0i64);
}

// File Line: 723
// RVA: 0xA1F250
void __fastcall Illusion::IBufferPlat::OnUnload(Illusion::IBufferPlat *this)
{
  Illusion::IBufferPlat *v1; // rbx
  _QWORD *v2; // rax
  __int64 v3; // rcx

  v1 = this + 144;
  Illusion::BufferD3DResourceInventory::OnBufferUnload(
    &Illusion::gBufferD3DResourceInventory,
    (Illusion::Texture *)this);
  v2 = *(_QWORD **)&v1[32];
  v3 = *(_QWORD *)&v1[24];
  *(_QWORD *)(v3 + 8) = v2;
  *v2 = v3;
  *(_QWORD *)&v1[24] = v1 + 24;
  *(_QWORD *)&v1[32] = v1 + 24;
  if ( *(_QWORD *)v1 )
    _((AMD_HD3D *)&v1[*(_QWORD *)v1]);
  else
    _(0i64);
}

// File Line: 732
// RVA: 0xA1C550
__int64 __fastcall Illusion::IBufferPlat::Lock(Illusion::IBufferPlat *this, Illusion::IBufferPlat::LockType lockType)
{
  return Illusion::BufferPlat::Lock((Illusion::BufferPlat *)&this[144], lockType);
}

// File Line: 740
// RVA: 0xA22A60
void __fastcall Illusion::IBufferPlat::Unlock(Illusion::IBufferPlat *this)
{
  Illusion::BufferPlat::Unlock((Illusion::BufferPlat *)&this[144]);
}

// File Line: 794
// RVA: 0xA1E820
void __fastcall Illusion::IModelPlat::OnLoad(Illusion::Model *this)
{
  UFG::qBaseNodeRB *v1; // rax

  v1 = this[1].mNode.mChild[0];
  if ( v1 )
    _((AMD_HD3D *)((char *)this[1].mNode.mChild + (_QWORD)v1));
  else
    _(0i64);
}

// File Line: 803
// RVA: 0xA1F2B0
void __fastcall Illusion::IModelPlat::OnUnload(Illusion::IModelPlat *this)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)&this[304];
  if ( v1 )
    _((AMD_HD3D *)&this[v1 + 304]);
  else
    _(0i64);
}

