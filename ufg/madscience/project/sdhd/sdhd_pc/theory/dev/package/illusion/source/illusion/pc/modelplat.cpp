// File Line: 67
// RVA: 0xA19DF0
void __fastcall Illusion::BufferLoader::DoCreationTask(Illusion::BufferLoader *this)
{
  Illusion::BufferQueueNode *v1; // rbx
  Illusion::BufferLoader *v2; // rdi
  signed __int64 v3; // r8
  Illusion::Buffer *v4; // rcx
  Illusion::Buffer **v5; // rdx
  Illusion::Buffer *v6; // rax
  Illusion::Buffer *v7; // r8
  Illusion::Buffer **v8; // rax
  signed __int64 v9; // rdx
  Illusion::Buffer *v10; // rcx

  v1 = this->mBufferNode;
  v2 = this;
  v3 = 31i64;
  v4 = v1->mRequestingBuffers[0];
  v5 = &v1->mRequestingBuffers[1];
  do
  {
    v6 = *v5;
    ++v5;
    *(v5 - 2) = v6;
    --v3;
  }
  while ( v3 );
  v1->mRequestingBuffers[31] = 0i64;
  if ( v4 )
    Illusion::BufferPlat::CreateResources((Illusion::BufferPlat *)&v4[1], v2->mBufferNode->mResource);
  while ( 1 )
  {
    v7 = v1->mRequestingBuffers[0];
    v8 = &v1->mRequestingBuffers[1];
    v9 = 31i64;
    do
    {
      v10 = *v8;
      ++v8;
      *(v8 - 2) = v10;
      --v9;
    }
    while ( v9 );
    v1->mRequestingBuffers[31] = 0i64;
    if ( !v7 )
      break;
    Illusion::BufferPlat::AcquireResources((Illusion::BufferPlat *)&v7[1], v2->mBufferNode->mResource);
  }
}

// File Line: 82
// RVA: 0xA1F410
void __fastcall Illusion::BufferLoader::PostSyncCreationTask(Illusion::BufferLoader *this)
{
  UFG::qResourceInventory::Add(
    (UFG::qResourceInventory *)&Illusion::gBufferD3DResourceInventory.vfptr,
    (UFG::qResourceData *)&this->mBufferNode->mResource->mNode);
}

// File Line: 90
// RVA: 0x15AA5F0
__int64 Illusion::_dynamic_initializer_for__gBufferD3DResourceInventory__()
{
  Illusion::BufferD3DResourceInventory::BufferD3DResourceInventory(&Illusion::gBufferD3DResourceInventory);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gBufferD3DResourceInventory__);
}

// File Line: 94
// RVA: 0xA15870
void __fastcall Illusion::BufferD3DResourceInventory::BufferD3DResourceInventory(Illusion::BufferD3DResourceInventory *this)
{
  Illusion::BufferD3DResourceInventory *v1; // rbx

  v1 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "BufferD3DResourceInventory",
    0x171246ADu,
    0x45E061F6u,
    0,
    0);
  v1->vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::BufferD3DResourceInventory::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mOnLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mOnUnloadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mHighPriorityLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mLoadingQueue.mTree);
}

// File Line: 98
// RVA: 0xA1E1A0
void __fastcall Illusion::BufferD3DResourceInventory::OnBufferLoad(Illusion::BufferD3DResourceInventory *this, Illusion::Buffer *buffer)
{
  Illusion::Buffer *v2; // rbp
  Illusion::BufferD3DResourceInventory *v3; // r14
  Illusion::BufferPlat *v4; // r13
  unsigned int v5; // esi
  char *v6; // rax
  Illusion::BufferD3DResource *v7; // rdi
  unsigned int v8; // er15
  Illusion::BufferD3DResource *v9; // rbx
  UFG::qBaseTreeVariableRB<unsigned __int64> *v10; // rdi
  UFG::qBaseTreeRB *v11; // rax
  Illusion::TextureQueueNode *v12; // r12
  UFG::qBaseNodeRB **v13; // r8
  signed int v14; // ecx
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
  UFG::qResourceInventory *v34; // rax
  UFG::qResourceWarehouse *v35; // rax

  v2 = buffer;
  v3 = this;
  v4 = (Illusion::BufferPlat *)&buffer[1];
  if ( (LOBYTE(buffer->mFlags) >> 2) & 1 )
  {
    v5 = buffer->mNode.mUID;
    v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v7 = (Illusion::BufferD3DResource *)v6;
    if ( v6 )
    {
      UFG::qResourceData::qResourceData((UFG::qResourceData *)v6, 0x171246ADu, v5, v2->mDebugName);
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
    Illusion::BufferPlat::AcquireResources(v4, v7);
    v4->mBufferD3DResourceHandle.mData = (UFG::qResourceData *)&v7->mNode;
  }
  else
  {
    v8 = buffer->mNode.mUID;
    v9 = 0i64;
    if ( v8 )
    {
      v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue;
      v11 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, v8);
      v12 = (Illusion::TextureQueueNode *)v11;
      if ( v11 )
      {
        v13 = &v11->mNULL.mChild[1];
        v14 = 0;
        v15 = (Illusion::Buffer **)&v11->mNULL.mChild[1];
        while ( *v15 != v2 )
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
          v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnUnloadQueue;
        }
LABEL_14:
        if ( !*v13 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v10, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v11);
          Illusion::TextureQueueNode::`scalar deleting destructor(v12, 1);
        }
      }
    }
    v17 = (Illusion::BufferD3DResource *)v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v8);
    v18 = v17;
    if ( v17 )
    {
      if ( UFG::qResourceInventory::smHotSwapMode == 1 )
      {
        v3->vfptr->Remove((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v17->mNode);
        Illusion::BufferD3DResource::~BufferD3DResource(v18);
        operator delete[](v18);
        v19 = UFG::qMalloc(0x80ui64, "BufferD3DResource", 0x800ui64);
        if ( v19 )
        {
          Illusion::BufferD3DResource::BufferD3DResource((Illusion::BufferD3DResource *)v19, v8, v2->mDebugName, 0);
          v21 = v20;
        }
        else
        {
          v21 = 0i64;
        }
        v22 = UFG::qMalloc(0x138ui64, "LoadBufferQueueNode", 0i64);
        if ( v22 )
        {
          Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v22, v21, (Illusion::Texture *)v2);
          v9 = v23;
        }
        UFG::qBaseTreeRB::Add(&v3->mOnLoadQueue.mTree, &v9->mNode);
      }
      else
      {
        Illusion::BufferPlat::AcquireResources(v4, v17);
      }
    }
    else
    {
      v24 = v2->mData.mOffset;
      if ( v24 && (UFG::qOffset64<void *> *)((char *)&v2->mData + v24) && !v2->mRunTimeCreated )
      {
        if ( v8 && (v25 = UFG::qBaseTreeRB::Get(&v3->mOnLoadQueue.mTree, v8)) != 0i64 )
        {
          v26 = &v25->mNULL.mChild[1];
          while ( *v26 )
          {
            LODWORD(v9) = (_DWORD)v9 + 1;
            ++v26;
            if ( (signed int)v9 >= 32 )
              goto LABEL_35;
          }
          v25->mNULL.mChild[(signed int)v9 + 1] = (UFG::qBaseNodeRB *)v2;
LABEL_35:
          v25->mNULL.mChild[0] = (UFG::qBaseNodeRB *)UFG::qGetTicks();
        }
        else
        {
          v27 = UFG::qMalloc(0x80ui64, "BufferD3DResource", 0x800ui64);
          if ( v27 )
          {
            Illusion::BufferD3DResource::BufferD3DResource((Illusion::BufferD3DResource *)v27, v8, v2->mDebugName, 0);
            v29 = v28;
          }
          else
          {
            v29 = 0i64;
          }
          v30 = UFG::qMalloc(0x138ui64, "LoadBufferQueueNode", 0i64);
          if ( v30 )
          {
            Illusion::TextureQueueNode::TextureQueueNode(
              (Illusion::TextureQueueNode *)v30,
              v29,
              (Illusion::Texture *)v2);
            v9 = v31;
          }
          UFG::qBaseTreeRB::Add(&v3->mOnLoadQueue.mTree, &v9->mNode);
        }
      }
      else
      {
        v32 = UFG::qMalloc(0x80ui64, "BufferD3DResource", 0x800ui64);
        if ( v32 )
        {
          Illusion::BufferD3DResource::BufferD3DResource((Illusion::BufferD3DResource *)v32, v8, v2->mDebugName, 0);
          v9 = v33;
        }
        Illusion::BufferPlat::CreateResources(v4, v9);
        v3->vfptr->Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v9->mNode);
      }
    }
    v34 = `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result )
    {
      v35 = UFG::qResourceWarehouse::Instance();
      v34 = UFG::qResourceWarehouse::GetInventory(v35, 0x171246ADu);
      `UFG::qGetResourceInventory<Illusion::BufferD3DResource>::`2::result = v34;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mBufferD3DResourceHandle.mPrev, 0x171246ADu, v8, v34);
  }
}

// File Line: 183
// RVA: 0xA1E530
void __fastcall Illusion::BufferD3DResourceInventory::OnBufferUnload(Illusion::BufferD3DResourceInventory *this, Illusion::Buffer *buffer)
{
  Illusion::Texture *v2; // rbp
  Illusion::BufferD3DResourceInventory *v3; // r14
  Illusion::TextureD3DResource *v4; // r12
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax
  Illusion::TextureQueueNode *v7; // r15
  UFG::qBaseNodeRB **v8; // r8
  signed int v9; // ebx
  Illusion::Texture **v10; // rcx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rdi
  Illusion::AsyncD3DCreationTask *v14; // rcx
  unsigned int v15; // edx
  UFG::qBaseNodeRB *v16; // rbx
  UFG::qBaseTreeRB *v17; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v18; // r15
  UFG::qBaseNodeRB **v19; // rax
  signed int v20; // ecx
  Illusion::Texture **v21; // rdx
  int v22; // ecx
  unsigned int v23; // edx
  UFG::qBaseTreeRB *v24; // rax
  signed __int64 v25; // rcx
  UFG::qBaseNodeRB **v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::qBaseNodeRB *v28; // rax

  v2 = (Illusion::Texture *)buffer;
  v3 = this;
  if ( (LOBYTE(buffer->mFlags) >> 2) & 1 )
    return;
  v4 = (Illusion::TextureD3DResource *)this->vfptr->Get((UFG::qResourceInventory *)this, buffer->mNode.mUID);
  if ( !v4 )
  {
    v5 = v2->mNode.mUID;
    if ( v5 )
    {
      v6 = UFG::qBaseTreeRB::Get(&v3->mOnLoadQueue.mTree, v5);
      v7 = (Illusion::TextureQueueNode *)v6;
      if ( v6 )
      {
        v8 = &v6->mNULL.mChild[1];
        v9 = 0;
        v10 = (Illusion::Texture **)&v6->mNULL.mChild[1];
        while ( *v10 != v2 )
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
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnLoadQueue,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
          Illusion::TextureQueueNode::`scalar deleting destructor(v7, 1);
        }
        return;
      }
    }
    v11 = v2->mNode.mUID;
    if ( v11 )
    {
      v12 = UFG::qBaseTreeRB::Get(&v3->mLoadingQueue.mTree, v11);
      v13 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v12;
      if ( v12 )
      {
        v14 = (Illusion::AsyncD3DCreationTask *)v12[4].mRoot.mChild[1];
        if ( v14 )
          Illusion::AsyncD3DCreationTask::FinalizeAsyncCreationTask(v14);
        v4 = (Illusion::TextureD3DResource *)v13[1].mParent;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mLoadingQueue,
          v13);
        Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v13, 1);
      }
    }
  }
  v15 = v2->mNode.mUID;
  v16 = 0i64;
  if ( v15 )
  {
    v17 = UFG::qBaseTreeRB::Get(&v3->mOnLoadQueue.mTree, v15);
    v18 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v17;
    if ( v17 )
    {
      v4 = (Illusion::TextureD3DResource *)v17->mNULL.mParent;
      v19 = &v17->mNULL.mChild[1];
      v20 = 0;
      v21 = (Illusion::Texture **)v19;
      while ( *v21 != v2 )
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
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnLoadQueue,
          v18);
        Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v18, 1);
      }
    }
  }
  v23 = v2->mNode.mUID;
  if ( v23 && (v24 = UFG::qBaseTreeRB::Get(&v3->mOnUnloadQueue.mTree, v23)) != 0i64 )
  {
    v25 = (signed __int64)&v24->mNULL.mChild[1];
    v26 = &v24->mNULL.mChild[1];
    while ( *v26 )
    {
      LODWORD(v16) = (_DWORD)v16 + 1;
      ++v26;
      if ( (signed int)v16 >= 32 )
        return;
    }
    *(_QWORD *)(v25 + 8i64 * (signed int)v16) = v2;
  }
  else
  {
    v27 = UFG::qMalloc(0x138ui64, "UnloadBufferQueueNode", 0i64);
    if ( v27 )
    {
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v27, v4, v2);
      v16 = v28;
    }
    UFG::qBaseTreeRB::Add(&v3->mOnUnloadQueue.mTree, v16);
  }
}

// File Line: 281
// RVA: 0xA1F4A0
void __fastcall Illusion::BufferD3DResourceInventory::ProcessQueuedLoads(Illusion::BufferD3DResourceInventory *this, bool bBlocking)
{
  bool v2; // r15
  Illusion::BufferD3DResourceInventory *v3; // r14
  float v4; // xmm0_4
  unsigned int *v5; // rdi
  __int64 v6; // rbp
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseNodeRB *v8; // rbx
  Render::SkinningCacheNode *v9; // rbx
  char v10; // di
  UFG::allocator::free_link *v11; // rax
  Illusion::AsyncD3DCreationTask *v12; // rcx
  UFG::allocator::free_link *v13; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v14; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v15; // rcx
  signed __int64 v16; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v17; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v18; // rcx
  signed __int64 v19; // rdx
  Illusion::BufferD3DResource *v20; // rdx
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  __int64 v23; // rdx
  _QWORD *v24; // rax
  int i; // ebp
  Render::SkinningCacheNode *v26; // rbx
  char v27; // si
  UFG::allocator::free_link *v28; // rax
  Illusion::AsyncD3DCreationTask *v29; // rcx
  UFG::allocator::free_link *v30; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v31; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v32; // rcx
  signed __int64 v33; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v34; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> **v35; // rcx
  signed __int64 v36; // rdx
  Illusion::BufferD3DResource *v37; // rdx
  _QWORD *v38; // rcx
  _QWORD *v39; // r8
  __int64 v40; // rdx
  _QWORD *v41; // rax

  v2 = bBlocking;
  v3 = this;
  v4 = (float)Illusion::gNumHighPriorityUIDs;
  if ( (float)Illusion::gNumHighPriorityUIDs >= 4096.0 )
    v4 = FLOAT_4096_0;
  if ( (signed int)v4 )
  {
    v5 = this->mHighPriorityUIDs;
    v6 = (unsigned int)(signed int)v4;
    do
    {
      if ( *v5 )
      {
        v7 = UFG::qBaseTreeRB::Get(&v3->mOnLoadQueue.mTree, *v5);
        v8 = &v7->mRoot;
        if ( v7 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnLoadQueue,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v7);
          UFG::qBaseTreeRB::Add(&v3->mHighPriorityLoadQueue.mTree, v8);
        }
      }
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  _InterlockedExchange(&Illusion::gNumHighPriorityUIDs, 0);
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mHighPriorityLoadQueue) )
  {
    v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mHighPriorityLoadQueue);
    v10 = 0;
    if ( v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v9->mCachedBufferPtr->mNode.mUID) )
      v10 = 1;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mHighPriorityLoadQueue,
      &v9->mNode);
    if ( !Illusion::gEnableAsyncBufferLoading || v2 || v10 )
    {
      v14 = v9[1].mNode.mChild[0];
      v15 = &v9[1].mNode.mChild[1];
      v16 = 31i64;
      do
      {
        *(v15 - 1) = *v15;
        ++v15;
        --v16;
      }
      while ( v16 );
      v9[7].mNode.mChild[1] = 0i64;
      if ( v14 && !v10 )
        Illusion::BufferPlat::CreateResources(
          (Illusion::BufferPlat *)&v14[4].mChild1,
          (Illusion::BufferD3DResource *)v9->mCachedBufferPtr);
      while ( 1 )
      {
        v17 = v9[1].mNode.mChild[0];
        v18 = &v9[1].mNode.mChild[1];
        v19 = 31i64;
        do
        {
          *(v18 - 1) = *v18;
          ++v18;
          --v19;
        }
        while ( v19 );
        v9[7].mNode.mChild[1] = 0i64;
        v20 = (Illusion::BufferD3DResource *)v9->mCachedBufferPtr;
        if ( !v17 )
          break;
        Illusion::BufferPlat::AcquireResources((Illusion::BufferPlat *)&v17[4].mChild1, v20);
      }
      UFG::qResourceInventory::Add(
        (UFG::qResourceInventory *)&Illusion::gBufferD3DResourceInventory.vfptr,
        (UFG::qResourceData *)&v20->mNode);
      v21 = (_QWORD *)v9[7].mNode.mUID;
      if ( v21 )
      {
        v22 = v21 + 1;
        v23 = v21[1];
        v24 = (_QWORD *)v21[2];
        *(_QWORD *)(v23 + 8) = v24;
        *v24 = v23;
        *v22 = v22;
        v22[1] = v22;
        operator delete[](v21);
        v9[7].mNode.mUID = 0i64;
      }
      operator delete[](v9);
    }
    else
    {
      UFG::qBaseTreeRB::Add(&v3->mLoadingQueue.mTree, (UFG::qBaseNodeRB *)v9);
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
        v12[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)v9;
      }
      else
      {
        v12 = 0i64;
      }
      v9[7].mNode.mUID = (unsigned __int64)v12;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v12);
    }
  }
  for ( i = 0;
        (i < Illusion::gMaxBufferLoadsPerFrame || v2)
     && UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mOnLoadQueue);
        ++i )
  {
    v26 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mOnLoadQueue);
    v27 = 0;
    if ( v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v26->mCachedBufferPtr->mNode.mUID) )
      v27 = 1;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnLoadQueue,
      &v26->mNode);
    if ( !Illusion::gEnableAsyncBufferLoading || v2 || v27 )
    {
      v31 = v26[1].mNode.mChild[0];
      v32 = &v26[1].mNode.mChild[1];
      v33 = 31i64;
      do
      {
        *(v32 - 1) = *v32;
        ++v32;
        --v33;
      }
      while ( v33 );
      v26[7].mNode.mChild[1] = 0i64;
      if ( v31 && !v27 )
        Illusion::BufferPlat::CreateResources(
          (Illusion::BufferPlat *)&v31[4].mChild1,
          (Illusion::BufferD3DResource *)v26->mCachedBufferPtr);
      while ( 1 )
      {
        v34 = v26[1].mNode.mChild[0];
        v35 = &v26[1].mNode.mChild[1];
        v36 = 31i64;
        do
        {
          *(v35 - 1) = *v35;
          ++v35;
          --v36;
        }
        while ( v36 );
        v26[7].mNode.mChild[1] = 0i64;
        v37 = (Illusion::BufferD3DResource *)v26->mCachedBufferPtr;
        if ( !v34 )
          break;
        Illusion::BufferPlat::AcquireResources((Illusion::BufferPlat *)&v34[4].mChild1, v37);
      }
      UFG::qResourceInventory::Add(
        (UFG::qResourceInventory *)&Illusion::gBufferD3DResourceInventory.vfptr,
        (UFG::qResourceData *)&v37->mNode);
      v38 = (_QWORD *)v26[7].mNode.mUID;
      if ( v38 )
      {
        v39 = v38 + 1;
        v40 = v38[1];
        v41 = (_QWORD *)v38[2];
        *(_QWORD *)(v40 + 8) = v41;
        *v41 = v40;
        *v39 = v39;
        v39[1] = v39;
        operator delete[](v38);
        v26[7].mNode.mUID = 0i64;
      }
      operator delete[](v26);
    }
    else
    {
      UFG::qBaseTreeRB::Add(&v3->mLoadingQueue.mTree, (UFG::qBaseNodeRB *)v26);
      v28 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      v29 = (Illusion::AsyncD3DCreationTask *)v28;
      if ( v28 )
      {
        v30 = v28 + 1;
        v30->mNext = v30;
        v30[1].mNext = v30;
        v29->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::AsyncD3DCreationTask::`vftable;
        v29->mTask = 0i64;
        v29->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::BufferLoader::`vftable;
        v29[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)v26;
      }
      else
      {
        v29 = 0i64;
      }
      v26[7].mNode.mUID = (unsigned __int64)v29;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v29);
    }
  }
}

// File Line: 402
// RVA: 0xA227D0
void __fastcall Illusion::BufferD3DResourceInventory::SyncLoadTasks(Illusion::BufferD3DResourceInventory *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v1; // rsi
  Render::SkinningCacheNode *v2; // rbx
  _QWORD *v3; // rdi
  UFG::qTask *v4; // rdx
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  __int64 v7; // rdx
  _QWORD *v8; // rax

  v1 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mLoadingQueue;
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v1) )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v1);
    v3 = (_QWORD *)v2[7].mNode.mUID;
    v4 = (UFG::qTask *)v3[3];
    if ( v4 )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v4);
      v3[3] = 0i64;
      (*(void (__fastcall **)(_QWORD *))(*v3 + 8i64))(v3);
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mTree, &v2->mNode);
    v5 = (_QWORD *)v2[7].mNode.mUID;
    if ( v5 )
    {
      v6 = v5 + 1;
      v7 = v5[1];
      v8 = (_QWORD *)v5[2];
      *(_QWORD *)(v7 + 8) = v8;
      *v8 = v7;
      *v6 = v6;
      v6[1] = v6;
      operator delete[](v5);
      v2[7].mNode.mUID = 0i64;
    }
    operator delete[](v2);
  }
}

// File Line: 416
// RVA: 0xA1FDB0
void __fastcall Illusion::BufferD3DResourceInventory::ProcessQueuedUnLoads(Illusion::BufferD3DResourceInventory *this)
{
  Illusion::BufferD3DResourceInventory *v1; // r14
  Render::SkinningCacheNode *v2; // rbp
  Illusion::Buffer *v3; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // r9
  UFG::qBaseNodeVariableRB<unsigned __int64> **v5; // rcx
  signed __int64 v6; // r8
  __int64 v7; // rcx
  __int64 v8; // rcx
  UFG::qResourceHandle *v9; // rdi
  UFG::qResourceHandle *v10; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v11; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  __int64 v17; // rdx
  _QWORD *v18; // rax

  v1 = this;
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mOnUnloadQueue) )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mOnUnloadQueue);
    v3 = v2->mCachedBufferPtr;
    while ( 1 )
    {
      v4 = v2[1].mNode.mChild[0];
      v5 = &v2[1].mNode.mChild[1];
      v6 = 31i64;
      do
      {
        *(v5 - 1) = *v5;
        ++v5;
        --v6;
      }
      while ( v6 );
      v2[7].mNode.mChild[1] = 0i64;
      if ( !v4 )
        break;
      if ( --LODWORD(v3->mBufferUser.mOffset) <= 0 )
      {
        v1->vfptr->Remove((UFG::qResourceInventory *)&v1->vfptr, (UFG::qResourceData *)&v3->mNode);
        if ( !BYTE4(v3->mBufferUser.mOffset) )
        {
          v7 = *(_QWORD *)&v3->mBufferType;
          if ( v7 )
          {
            (*(void (__cdecl **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
            *(_QWORD *)&v3->mBufferType = 0i64;
          }
          v8 = *(_QWORD *)&v3->mElementByteSize;
          if ( v8 )
          {
            (*(void (__cdecl **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
            *(_QWORD *)&v3->mElementByteSize = 0i64;
          }
        }
        v9 = (UFG::qResourceHandle *)&v3->mResourceHandles;
        v10 = (UFG::qResourceHandle *)v3->mResourceHandles.mNode.mNext;
        if ( v10 != (UFG::qResourceHandle *)&v3->mResourceHandles )
        {
          do
          {
            v11 = v10->mPrev;
            v12 = v10->mNext;
            v11->mNext = v12;
            v12->mPrev = v11;
            v10->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v10->mPrev;
            v10->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v10->mPrev;
            UFG::qResourceHandle::~qResourceHandle(v10);
            operator delete[](v10);
            v10 = (UFG::qResourceHandle *)v3->mResourceHandles.mNode.mNext;
          }
          while ( v10 != v9 );
        }
        v13 = v9->mPrev;
        v14 = v3->mResourceHandles.mNode.mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        v9->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v9->mPrev;
        v3->mResourceHandles.mNode.mNext = &v3->mResourceHandles.mNode;
        operator delete[](v3);
        UFG::qMemSet(qword_14245AF48, 0, 0x40000u);
      }
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mOnUnloadQueue,
      &v2->mNode);
    v15 = (_QWORD *)v2[7].mNode.mUID;
    if ( v15 )
    {
      v16 = v15 + 1;
      v17 = v15[1];
      v18 = (_QWORD *)v15[2];
      *(_QWORD *)(v17 + 8) = v18;
      *v18 = v17;
      *v16 = v16;
      v16[1] = v16;
      operator delete[](v15);
      v2[7].mNode.mUID = 0i64;
    }
    operator delete[](v2);
  }
}

// File Line: 453
// RVA: 0xA16260
void __fastcall Illusion::BufferD3DResource::~BufferD3DResource(Illusion::BufferD3DResource *this)
{
  Illusion::BufferD3DResource *v1; // rbx
  ID3D11Buffer *v2; // rcx
  ID3D11Buffer *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( !this->mFrameGenerated )
  {
    v2 = this->mGpuResource;
    if ( v2 )
    {
      ((void (__cdecl *)(ID3D11Buffer *))v2->vfptr->Release)(v2);
      v1->mGpuResource = 0i64;
    }
    v3 = v1->mStagingResource;
    if ( v3 )
    {
      ((void (__cdecl *)(ID3D11Buffer *))v3->vfptr->Release)(v3);
      v1->mStagingResource = 0i64;
    }
  }
  v6 = &v1->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
  v4 = v1->mResourceHandles.mNode.mPrev;
  v5 = v1->mResourceHandles.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
}

// File Line: 473
// RVA: 0xA1E760
void __fastcall Illusion::BufferPlat::OnLoad(Illusion::BufferPlat *this)
{
  Illusion::BufferPlat *v1; // rbx

  v1 = this;
  if ( this )
  {
    *(_QWORD *)&this->mCpuAccess = 0i64;
    this->mMappedResource = 0i64;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mBufferD3DResourceHandle.mPrev);
    UFG::qMemSet(v1->mPadding, 0, 0x48u);
    v1->mBufferD3DResourceHandle.mNameUID = 0;
  }
  Illusion::BufferD3DResourceInventory::OnBufferLoad(
    &Illusion::gBufferD3DResourceInventory,
    (Illusion::Buffer *)&v1[-2].mPadding[56]);
}

// File Line: 486
// RVA: 0xA16F50
void __fastcall Illusion::BufferPlat::AcquireResources(Illusion::BufferPlat *this, Illusion::BufferD3DResource *bufferD3D)
{
  Illusion::BufferPlat *v2; // rbx
  Illusion::BufferD3DResource *v3; // rdi
  __int64 v4; // rax
  int v5; // eax
  char v6; // cl
  int v7; // eax

  v2 = this;
  v3 = bufferD3D;
  UFG::qAtomicIncrement(&bufferD3D->mRefCount);
  if ( ((unsigned __int8)v2[-1].mPadding[18] >> 2) & 1 )
  {
    v3->mGpuResource = Illusion::gFrameWriteMemoryPlat.mBuffer[Illusion::gFrameWriteMemoryPlat.mFrameMemoryBufferIndex];
    v4 = *(_QWORD *)&v2[-1].mPadding[24];
    if ( v4 )
      v5 = (_DWORD)v2 + v4 - 48 - LODWORD(Illusion::gFrameWriteMemoryPlat.mLockData);
    else
      v5 = -LODWORD(Illusion::gFrameWriteMemoryPlat.mLockData);
    v3->mResourceOffset = v5;
  }
  else
  {
    v6 = ((unsigned __int8)v2[-1].mPadding[18] >> 1) & 1;
    if ( v2[-1].mPadding[18] & 1 )
    {
      v7 = 1;
      if ( v6 )
        v7 = 3;
    }
    else
    {
      v7 = v6 != 0 ? 2 : 0;
    }
    v2->mCpuAccess = v7;
    v2->mMappedResource = 0i64;
    v2->mUploadAfterUnmap = 0;
  }
}

// File Line: 516
// RVA: 0xA18DA0
void __fastcall Illusion::BufferPlat::CreateResources(Illusion::BufferPlat *this, Illusion::BufferD3DResource *bufferD3D)
{
  Illusion::BufferPlat *v2; // rbx
  Illusion::BufferD3DResource *v3; // rsi
  __int64 v4; // rax
  signed __int64 v5; // r10
  unsigned __int8 v6; // r15
  unsigned int v7; // er11
  char v8; // di
  char v9; // r15
  int v10; // er9
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // eax
  int v15; // er8
  D3D11_USAGE v16; // eax
  D3D11_SUBRESOURCE_DATA *v17; // r12
  __int16 v18; // ax
  bool v19; // zf
  int v20; // eax
  unsigned int v21; // eax
  ID3D11Buffer *v22; // rcx
  ID3D11Buffer *v23; // rcx
  __int64 v24; // [rsp+20h] [rbp-40h]
  __int64 v25; // [rsp+28h] [rbp-38h]
  D3D11_BUFFER_DESC v26; // [rsp+30h] [rbp-30h]
  int v27; // [rsp+48h] [rbp-18h]
  __int64 v28; // [rsp+4Ch] [rbp-14h]
  int v29; // [rsp+54h] [rbp-Ch]
  int v30; // [rsp+58h] [rbp-8h]

  v2 = this;
  v3 = bufferD3D;
  UFG::qAtomicIncrement(&bufferD3D->mRefCount);
  v4 = *(_QWORD *)&v2[-1].mPadding[24];
  if ( v4 )
    v5 = (signed __int64)&v2[-1].mPadding[v4 + 24];
  else
    v5 = 0i64;
  v6 = v2[-1].mPadding[18];
  v7 = *(_DWORD *)&v2[-1].mPadding[20];
  v8 = (v6 >> 1) & 1;
  v9 = v6 & 1;
  if ( v9 )
  {
    v10 = 1;
    if ( v8 )
      v10 = 3;
  }
  else
  {
    v10 = v8 != 0 ? 2 : 0;
  }
  v2->mCpuAccess = v10;
  v11 = (unsigned __int8)v2[-1].mPadding[16];
  *(_QWORD *)&v26.CPUAccessFlags = 0i64;
  v26.StructureByteStride = 0;
  v26.ByteWidth = v7;
  v26.Usage = 0;
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
      v13 = *(unsigned __int16 *)&v2[-1].mPadding[18];
      v14 = *(_WORD *)&v2[-1].mPadding[18] & 0x10;
      v26.MiscFlags = 2 * (*(_WORD *)&v2[-1].mPadding[18] & 0x20) | (v13 >> 1) & 0x20;
      v15 = v13 & 8 | 8 * v14;
      v26.StructureByteStride = *(_DWORD *)&v2[-1].mPadding[32];
      goto LABEL_15;
    }
  }
  v15 = 1;
LABEL_15:
  v26.BindFlags = v15;
  if ( v10 == 2 )
  {
    v26.Usage = 2;
    v26.CPUAccessFlags = 65536;
  }
  else if ( v5 )
  {
    v16 = 0;
    if ( !v10 )
      v16 = 1;
    v26.Usage = v16;
  }
  v24 = v5;
  v25 = 0i64;
  v17 = (D3D11_SUBRESOURCE_DATA *)&v24;
  if ( !v7 )
    v17 = 0i64;                                 // CreateBuffer Call
  if ( ((signed int (__fastcall *)(ID3D11Device *, D3D11_BUFFER_DESC *, D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **, __int64, __int64, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
         UFG::gD3D11Device,
         &v26,
         v17,
         &v3->mGpuResource,
         v24,
         v25,
         *(_QWORD *)&v26.ByteWidth,
         *(_QWORD *)&v26.BindFlags,
         *(_QWORD *)&v26.MiscFlags) < 0 )
    goto LABEL_39;
  v18 = *(_WORD *)&v2[-1].mPadding[18];
  if ( v18 & 8 )
  {
    v19 = (v18 & 0x40) == 0;
    v20 = *(_DWORD *)&v2[-1].mPadding[36];
    v27 = 0;
    v29 = v20;
    if ( v19 )
    {
      v28 = 1i64;
    }
    else
    {
      v28 = 11i64;
      v30 = 0;
    }
    if ( ((signed int (__fastcall *)(ID3D11Device *, ID3D11Buffer *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
           UFG::gD3D11Device,
           v3->mGpuResource,
           &v27,
           &v3->mShaderResourceView) < 0 )
      goto LABEL_39;
  }
  v2->mMappedResource = 0i64;
  v2->mUploadAfterUnmap = 0;
  if ( v9 )
  {
    v21 = 0x20000;
    *(_QWORD *)&v26.Usage = 3i64;
    if ( v8 )
      v21 = 196608;
    v26.CPUAccessFlags = v21;
    if ( ((signed int (__fastcall *)(ID3D11Device *, D3D11_BUFFER_DESC *, D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
           UFG::gD3D11Device,
           &v26,
           v17,
           &v3->mStagingResource) < 0 )
    {
LABEL_39:
      v22 = v3->mGpuResource;
      if ( v22 )
      {
        ((void (*)(void))v22->vfptr->Release)();
        v3->mGpuResource = 0i64;
      }
      v23 = v3->mStagingResource;
      if ( v23 )
      {
        ((void (*)(void))v23->vfptr->Release)();
        v3->mStagingResource = 0i64;
      }
    }
  }
}

// File Line: 628
// RVA: 0xA1C3E0
__int64 __fastcall Illusion::BufferPlat::Lock(Illusion::BufferPlat *this, Illusion::IBufferPlat::LockType lockType)
{
  unsigned __int8 v2; // si
  Illusion::BufferPlat *v3; // rbx
  unsigned __int32 v4; // edx
  signed __int64 v5; // r9
  UFG::qBaseNodeRB *v6; // rdi
  __int64 v7; // rax
  __int64 v9; // [rsp+30h] [rbp-18h]
  __int64 v10; // [rsp+38h] [rbp-10h]

  v2 = 0;
  v3 = this;
  if ( lockType == LOCK_READ )
  {
    if ( (this->mCpuAccess - 1) & 0xFFFFFFFD )
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
    v6 = this->mBufferD3DResourceHandle.mData[1].mNode.mChild[1];
    goto LABEL_11;
  }
  if ( this->mCpuAccess != 2 )
    return 0i64;
  v5 = 4i64;
  v6 = this->mBufferD3DResourceHandle.mData[1].mNode.mParent;
LABEL_11:
  if ( v6 )
  {
    v10 = 0i64;
    v7 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
    v9 = 0i64;
    if ( (*(signed int (__fastcall **)(_QWORD, UFG::qBaseNodeRB *, _QWORD, signed __int64, _DWORD, __int64 *))(**(_QWORD **)(v7 + 104) + 112i64))(
           *(_QWORD *)(v7 + 104),
           v6,
           0i64,
           v5,
           0,
           &v9) >= 0 )
    {
      v3->mMappedResource = (ID3D11Buffer *)v6;
      v3->mUploadAfterUnmap = v2;
      return v9;
    }
  }
  return 0i64;
}

// File Line: 688
// RVA: 0xA22990
void __fastcall Illusion::BufferPlat::Unlock(Illusion::BufferPlat *this)
{
  ID3D11Buffer *v1; // rdx
  Illusion::BufferPlat *v2; // rbx
  _QWORD *v3; // rdi

  v1 = this->mMappedResource;
  v2 = this;
  if ( v1 )
  {
    v3 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    (*(void (__fastcall **)(_QWORD, ID3D11Buffer *, _QWORD))(*(_QWORD *)*v3 + 120i64))(*v3, v1, 0i64);
    if ( v2->mUploadAfterUnmap )
      (*(void (__fastcall **)(_QWORD, UFG::qBaseNodeRB *, ID3D11Buffer *))(*(_QWORD *)*v3 + 376i64))(
        *v3,
        v2->mBufferD3DResourceHandle.mData[1].mNode.mParent,
        v2->mMappedResource);
    v2->mMappedResource = 0i64;
    v2->mUploadAfterUnmap = 0;
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
  Illusion::IBufferPlat *v4; // rdx

  v1 = this + 144;
  Illusion::BufferD3DResourceInventory::OnBufferUnload(&Illusion::gBufferD3DResourceInventory, (Illusion::Buffer *)this);
  v2 = *(_QWORD **)&v1[32];
  v3 = *(_QWORD *)&v1[24];
  v4 = v1 + 24;
  *(_QWORD *)(v3 + 8) = v2;
  *v2 = v3;
  *(_QWORD *)v4 = v4;
  *(_QWORD *)&v4[8] = v4;
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

