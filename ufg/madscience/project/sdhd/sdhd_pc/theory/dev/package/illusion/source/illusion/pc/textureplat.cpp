// File Line: 66
// RVA: 0x15AA7E0
__int64 Illusion::_dynamic_initializer_for__gTextureD3DResourceInventory__()
{
  Illusion::TextureD3DResourceInventory::TextureD3DResourceInventory(&Illusion::gTextureD3DResourceInventory);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gTextureD3DResourceInventory__);
}

// File Line: 133
// RVA: 0xA19890
ID3D11Resource *__fastcall Illusion::CreateTexture(
        D3D11_TEXTURE2D_DESC *desc2D,
        int depth,
        D3D11_SUBRESOURCE_DATA *pSubresourceData)
{
  unsigned int MipLevels; // eax
  _DWORD v5[3]; // [rsp+20h] [rbp-38h] BYREF
  __int128 v6; // [rsp+2Ch] [rbp-2Ch]
  __int64 v7; // [rsp+3Ch] [rbp-1Ch]
  __int64 v8; // [rsp+78h] [rbp+20h] BYREF

  v8 = 0i64;
  if ( depth <= 1 )
  {
    ((void (__fastcall *)(ID3D11Device *, D3D11_TEXTURE2D_DESC *, D3D11_SUBRESOURCE_DATA *, __int64 *))UFG::gD3D11Device->vfptr->PSSetShader)(
      UFG::gD3D11Device,
      desc2D,
      pSubresourceData,
      &v8);
  }
  else
  {
    *(_QWORD *)&v5[1] = 0i64;
    v6 = 0ui64;
    v7 = 0i64;
    v5[0] = desc2D->Width;
    v5[1] = desc2D->Height;
    MipLevels = desc2D->MipLevels;
    v5[2] = depth;
    LODWORD(v6) = MipLevels;
    DWORD1(v6) = *(_DWORD *)desc2D->Format;
    *((_QWORD *)&v6 + 1) = *(_QWORD *)&desc2D->Usage;
    v7 = *(_QWORD *)&desc2D->CPUAccessFlags;
    ((void (__fastcall *)(ID3D11Device *, _DWORD *, D3D11_SUBRESOURCE_DATA *, __int64 *))UFG::gD3D11Device->vfptr->PSSetSamplers)(
      UFG::gD3D11Device,
      v5,
      pSubresourceData,
      &v8);
  }
  return (ID3D11Resource *)v8;
}

// File Line: 596
// RVA: 0xA19EC0
void __fastcall Illusion::TextureLoader::DoCreationTask(Illusion::TextureLoader *this)
{
  unsigned int v2; // ebx
  __int64 v3; // rdi
  Illusion::TextureQueueNode *mTextureNode; // rdx
  __int64 v5; // rcx

  v2 = 0;
  v3 = 48i64;
  do
  {
    mTextureNode = this->mTextureNode;
    v5 = *(__int64 *)((char *)&mTextureNode->mNode.mParent + v3);
    if ( v2 )
    {
      if ( !v5 )
        return;
      Illusion::TexturePlat::AcquireResources((Illusion::TexturePlat *)(v5 + 208), mTextureNode->mResource);
    }
    else
    {
      Illusion::TexturePlat::CreateResources((Illusion::TexturePlat *)(v5 + 208), mTextureNode->mResource);
    }
    ++v2;
    v3 += 8i64;
  }
  while ( v2 < 0x20 );
}

// File Line: 619
// RVA: 0xA1F430
void __fastcall Illusion::TextureLoader::PostSyncCreationTask(Illusion::TextureLoader *this)
{
  unsigned int v2; // ebx
  __int64 v3; // rdi
  __int64 v4; // rcx

  UFG::qResourceInventory::Add(&Illusion::gTextureD3DResourceInventory, this->mTextureNode->mResource);
  v2 = 0;
  v3 = 48i64;
  do
  {
    v4 = *(__int64 *)((char *)&this->mTextureNode->mNode.mParent + v3);
    if ( !v4 )
      break;
    if ( *(_QWORD *)(v4 + 168) )
      UFG::qResourceHandle::Close((UFG::qResourceHandle *)(v4 + 152));
    ++v2;
    v3 += 8i64;
  }
  while ( v2 < 0x20 );
}

// File Line: 649
// RVA: 0xA21F00
void __fastcall Illusion::SetDefaultTextureFilterQuality(int filter_quality)
{
  int v1; // eax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *p_mResourceDatas; // rdi
  UFG::qBaseTreeRB *i; // rbx
  Illusion::TextureD3DResource *v5; // rdx

  if ( filter_quality )
    v1 = 1 << filter_quality;
  else
    v1 = 0;
  if ( gDefaultTextureFilterQuality != v1 )
  {
    gDefaultTextureFilterQuality = v1;
    v2 = UFG::qResourceWarehouse::Instance();
    p_mResourceDatas = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::qResourceWarehouse::GetInventory(
                                                                                                   v2,
                                                                                                   0x8B43FABF)->mResourceDatas;
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_mResourceDatas);
          i;
          i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)p_mResourceDatas, &i->mRoot) )
    {
      v5 = (Illusion::TextureD3DResource *)i[4].mRoot.mChild[0];
      if ( v5 )
        Illusion::TexturePlat::CreateSamplerState((Illusion::TexturePlat *)&i[2].mCount, v5);
    }
  }
}

// File Line: 665
// RVA: 0xA15DC0
void __fastcall Illusion::TextureD3DResourceInventory::TextureD3DResourceInventory(
        Illusion::TextureD3DResourceInventory *this)
{
  UFG::qResourceInventory::qResourceInventory(
    this,
    "TextureD3DResourceInventory",
    0xEF77C5F7,
    0x501B8E62u,
    0x3218EEB7u,
    0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::TextureD3DResourceInventory::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mOnLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mOnUnloadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mHighPriorityLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mLoadingQueue.mTree);
}

// File Line: 669
// RVA: 0xA1EE60
char __fastcall Illusion::TextureD3DResourceInventory::OnTextureLoad(
        Illusion::TextureD3DResourceInventory *this,
        Illusion::Texture *texture)
{
  unsigned int mUID; // edx
  Illusion::TextureD3DResource *v5; // rbx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // r15
  UFG::qBaseNodeRB **v8; // r8
  int v9; // ecx
  Illusion::Texture **v10; // rdx
  int v11; // ecx
  UFG::qBaseNodeRB *v12; // rcx
  UFG::qBaseNodeRB *v13; // rdx
  UFG::qBaseNodeRB *v14; // rax
  Illusion::TextureD3DResource *v15; // rax
  unsigned int v16; // edx
  UFG::qBaseTreeRB *v17; // rax
  UFG::qBaseNodeRB **v18; // rcx
  UFG::allocator::free_link *v19; // rax
  Illusion::TextureD3DResource *v20; // rax
  Illusion::TextureD3DResource *v21; // rdi
  UFG::allocator::free_link *v22; // rax
  Illusion::TextureD3DResource *v23; // rax
  UFG::allocator::free_link *v25; // rax
  Illusion::TextureD3DResource *v26; // rax

  mUID = texture->mNode.mUID;
  v5 = 0i64;
  if ( mUID )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, mUID);
    v7 = v6;
    if ( v6 )
    {
      v8 = &v6->mNULL.mChild[1];
      v9 = 0;
      v10 = (Illusion::Texture **)&v6->mNULL.mChild[1];
      while ( *v10 != texture )
      {
        ++v9;
        ++v10;
        if ( v9 >= 32 )
          goto LABEL_9;
      }
      v11 = v9 + 1;
      if ( v11 < 32 )
        qmemcpy(&v8[v11 - 1], &v8[v11], 8i64 * (unsigned int)(32 - v11));
LABEL_9:
      if ( !*v8 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
        v12 = v7[4].mRoot.mChild[1];
        if ( v12 )
        {
          v13 = v12->mChild[0];
          v14 = v12->mChild[1];
          v13->mChild[0] = v14;
          v14->mParent = v13;
          v12->mChild[0] = (UFG::qBaseNodeRB *)v12->mChild;
          v12->mChild[1] = (UFG::qBaseNodeRB *)v12->mChild;
          operator delete[](v12);
          v7[4].mRoot.mChild[1] = 0i64;
        }
        operator delete[](v7);
      }
    }
  }
  if ( this->vfptr->Get(this, texture->mNode.mUID) )
  {
    v15 = (Illusion::TextureD3DResource *)this->vfptr->Get(this, texture->mNode.mUID);
    Illusion::TexturePlat::AcquireResources((Illusion::TexturePlat *)texture[1].mNode.mChild, v15);
    return 1;
  }
  if ( (texture->mFlags & 0x26CC00) != 0 )
  {
    v25 = UFG::qMalloc(0xF8ui64, "TextureD3DResource", 0x800ui64);
    if ( v25 )
    {
      Illusion::TextureD3DResource::TextureD3DResource(
        (Illusion::TextureD3DResource *)v25,
        texture->mNode.mUID,
        texture->mDebugName);
      v5 = v26;
    }
    Illusion::TexturePlat::CreateResources((Illusion::TexturePlat *)texture[1].mNode.mChild, v5);
    this->vfptr->Add(this, v5);
    return 1;
  }
  v16 = texture->mNode.mUID;
  if ( v16 && (v17 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, v16)) != 0i64 )
  {
    v18 = &v17->mNULL.mChild[1];
    while ( *v18 )
    {
      LODWORD(v5) = (_DWORD)v5 + 1;
      ++v18;
      if ( (int)v5 >= 32 )
        goto LABEL_23;
    }
    v17->mNULL.mChild[(int)v5 + 1] = (UFG::qBaseNodeRB *)texture;
LABEL_23:
    v17->mNULL.mChild[0] = (UFG::qBaseNodeRB *)UFG::qGetTicks();
  }
  else
  {
    v19 = UFG::qMalloc(0xF8ui64, "TextureD3DResource", 0x800ui64);
    if ( v19 )
    {
      Illusion::TextureD3DResource::TextureD3DResource(
        (Illusion::TextureD3DResource *)v19,
        texture->mNode.mUID,
        texture->mDebugName);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    v22 = UFG::qMalloc(0x138ui64, "LoadTextureQueueNode", 0i64);
    if ( v22 )
    {
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v22, v21, texture);
      v5 = v23;
    }
    UFG::qBaseTreeRB::Add(&this->mOnLoadQueue.mTree, &v5->mNode);
  }
  return 0;
}

// File Line: 752
// RVA: 0xA1F0B0
void __fastcall Illusion::TextureD3DResourceInventory::OnTextureUnload(
        Illusion::TextureD3DResourceInventory *this,
        Illusion::Texture *texture)
{
  Illusion::TextureD3DResource *mParent; // rbp
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // rbx
  Illusion::Texture **v8; // r8
  int v9; // eax
  Illusion::Texture **v10; // rcx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rbx
  Illusion::AsyncD3DCreationTask *v14; // rcx
  unsigned int v15; // edx
  UFG::qBaseTreeRB *v16; // rax
  UFG::qBaseNodeRB **v17; // rdx
  int v18; // eax
  UFG::qBaseNodeRB **i; // rcx
  UFG::allocator::free_link *v20; // rax

  mParent = (Illusion::TextureD3DResource *)this->vfptr->Get(this, texture->mNode.mUID);
  if ( !mParent )
  {
    mUID = texture->mNode.mUID;
    if ( mUID )
    {
      v6 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, mUID);
      v7 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6;
      if ( v6 )
      {
        v8 = (Illusion::Texture **)&v6->mNULL.mChild[1];
        v9 = 0;
        v10 = v8;
        while ( *v10 != texture )
        {
          ++v9;
          ++v10;
          if ( v9 >= 32 )
            goto LABEL_10;
        }
        if ( v9 + 1 < 32 )
          qmemcpy(&v8[v9], &v8[v9 + 1], 8i64 * (unsigned int)(32 - (v9 + 1)));
LABEL_10:
        if ( !*v8 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue,
            v7);
          Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v7, 1);
        }
        return;
      }
    }
    v11 = texture->mNode.mUID;
    if ( !v11 )
      return;
    v12 = UFG::qBaseTreeRB::Get(&this->mLoadingQueue.mTree, v11);
    v13 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v12;
    if ( !v12 )
      return;
    v14 = (Illusion::AsyncD3DCreationTask *)v12[4].mRoot.mChild[1];
    if ( v14 )
      Illusion::AsyncD3DCreationTask::FinalizeAsyncCreationTask(v14);
    mParent = (Illusion::TextureD3DResource *)v13[1].mParent;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mLoadingQueue,
      v13);
    Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v13, 1);
  }
  v15 = texture->mNode.mUID;
  if ( v15 && (v16 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, v15)) != 0i64 )
  {
    v17 = &v16->mNULL.mChild[1];
    v18 = 0;
    for ( i = v17; *i; ++i )
    {
      if ( ++v18 >= 32 )
        return;
    }
    v17[v18] = (UFG::qBaseNodeRB *)texture;
  }
  else
  {
    v20 = UFG::qMalloc(0x138ui64, "UnloadTextureQueueNode", 0i64);
    if ( v20 )
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v20, mParent, texture);
    UFG::qBaseTreeRB::Add(&this->mOnUnloadQueue.mTree, (UFG::qBaseNodeRB *)v20);
  }
}

// File Line: 822
// RVA: 0xA21FA0
void __fastcall Illusion::TextureD3DResourceInventory::SetHighPriority(
        Illusion::TextureD3DResourceInventory *this,
        unsigned int uid)
{
  int v4; // eax

  v4 = UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
  if ( v4 > 4095 )
    v4 = 4095;
  this->mHighPriorityUIDs[v4] = uid;
}

// File Line: 831
// RVA: 0xA1F900
void __fastcall Illusion::TextureD3DResourceInventory::ProcessQueuedLoads(
        Illusion::TextureD3DResourceInventory *this,
        bool bBlocking)
{
  bool v2; // r12
  float v4; // xmm0_4
  unsigned int *mHighPriorityUIDs; // rdi
  __int64 v6; // rbp
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseNodeRB *p_mRoot; // rbx
  Render::SkinningCacheNode *Head; // rsi
  UFG::allocator::free_link *v10; // rax
  Illusion::AsyncD3DCreationTask *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  unsigned int v13; // edi
  $CA91B2824B6F331601351B2AC7FEF5D9 *v14; // r14
  UFG::qBaseNodeVariableRB<unsigned __int64> *v15; // rbx
  int mUID; // edx
  bool v17; // r8
  char v18; // cl
  int v19; // eax
  _QWORD *v20; // rcx
  __int64 v21; // rdx
  _QWORD *v22; // rax
  int i; // r14d
  Render::SkinningCacheNode *v24; // rbp
  UFG::allocator::free_link *v25; // rax
  Illusion::AsyncD3DCreationTask *v26; // rcx
  UFG::allocator::free_link *v27; // rax
  unsigned int v28; // edi
  $CA91B2824B6F331601351B2AC7FEF5D9 *v29; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v30; // rbx
  int v31; // edx
  bool v32; // r8
  char v33; // cl
  int v34; // eax
  _QWORD *v35; // rcx
  __int64 v36; // rdx
  _QWORD *v37; // rax

  v2 = bBlocking;
  v4 = (float)Illusion::gTextureNumHighPriorityUIDs;
  if ( (float)Illusion::gTextureNumHighPriorityUIDs >= 4096.0 )
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
  _InterlockedExchange(&Illusion::gTextureNumHighPriorityUIDs, 0);
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mHighPriorityLoadQueue) )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mHighPriorityLoadQueue);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mHighPriorityLoadQueue,
      &Head->mNode);
    if ( !Illusion::gEnableAsyncTextureLoading || v2 )
    {
      v13 = 0;
      v14 = &Head[1].mNode.8;
      do
      {
        v15 = v14->mChild[0];
        if ( v13 )
        {
          if ( !v15 )
            break;
          UFG::qAtomicIncrement((volatile int *)&Head->mCachedBufferPtr[1].mData);
          v15[7].mChild[1] = 0i64;
          *(unsigned __int64 *)((char *)&v15[6].mUID + 4) = 0i64;
          mUID = v15[2].mUID;
          v17 = (mUID & 0x40000) != 0 || (v15[2].mUID & 0x20000) != 0;
          if ( (mUID & 0x400) != 0 || (v15[2].mUID & 0x20000) != 0 )
          {
            v18 = 1;
            if ( (v15[2].mUID & 0x20000) != 0 )
              LODWORD(v15[2].mUID) = mUID | 0x400000;
          }
          else
          {
            v18 = 0;
          }
          if ( v17 )
          {
            v19 = 1;
            if ( v18 )
              v19 = 3;
          }
          else
          {
            v19 = v18 != 0 ? 2 : 0;
          }
          LODWORD(v15[6].mUID) = v19;
          v15[7].mChild[0] = 0i64;
        }
        else
        {
          Illusion::TexturePlat::CreateResources(
            (Illusion::TexturePlat *)&v15[6].mChild1,
            (Illusion::TextureD3DResource *)Head->mCachedBufferPtr);
        }
        if ( v15[5].mChild[0] )
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v15[4].mUID);
        ++v13;
        v14 = ($CA91B2824B6F331601351B2AC7FEF5D9 *)((char *)v14 + 8);
      }
      while ( v13 < 0x20 );
      UFG::qResourceInventory::Add(&Illusion::gTextureD3DResourceInventory, &Head->mCachedBufferPtr->UFG::qResourceData);
      v20 = (_QWORD *)Head[7].mNode.mUID;
      v2 = bBlocking;
      if ( v20 )
      {
        v21 = v20[1];
        v22 = (_QWORD *)v20[2];
        *(_QWORD *)(v21 + 8) = v22;
        *v22 = v21;
        v20[1] = v20 + 1;
        v20[2] = v20 + 1;
        operator delete[](v20);
        Head[7].mNode.mUID = 0i64;
      }
      operator delete[](Head);
    }
    else
    {
      UFG::qBaseTreeRB::Add(&this->mLoadingQueue.mTree, (UFG::qBaseNodeRB *)Head);
      v10 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      v11 = (Illusion::AsyncD3DCreationTask *)v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::AsyncD3DCreationTask::`vftable;
        v11->mTask = 0i64;
        v11->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::TextureLoader::`vftable;
        v11[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)Head;
      }
      else
      {
        v11 = 0i64;
      }
      Head[7].mNode.mUID = (unsigned __int64)v11;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v11);
    }
  }
  for ( i = 0;
        (i < Illusion::gMaxTextureLoadsPerFrame || v2)
     && UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnLoadQueue);
        ++i )
  {
    v24 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnLoadQueue);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue,
      &v24->mNode);
    if ( !Illusion::gEnableAsyncTextureLoading || v2 )
    {
      v28 = 0;
      v29 = &v24[1].mNode.8;
      do
      {
        v30 = v29->mChild[0];
        if ( v28 )
        {
          if ( !v30 )
            break;
          UFG::qAtomicIncrement((volatile int *)&v24->mCachedBufferPtr[1].mData);
          v30[7].mChild[1] = 0i64;
          *(unsigned __int64 *)((char *)&v30[6].mUID + 4) = 0i64;
          v31 = v30[2].mUID;
          v32 = (v31 & 0x40000) != 0 || (v30[2].mUID & 0x20000) != 0;
          if ( (v31 & 0x400) != 0 || (v30[2].mUID & 0x20000) != 0 )
          {
            v33 = 1;
            if ( (v30[2].mUID & 0x20000) != 0 )
              LODWORD(v30[2].mUID) = v31 | 0x400000;
          }
          else
          {
            v33 = 0;
          }
          if ( v32 )
          {
            v34 = 1;
            if ( v33 )
              v34 = 3;
          }
          else
          {
            v34 = v33 != 0 ? 2 : 0;
          }
          LODWORD(v30[6].mUID) = v34;
          v30[7].mChild[0] = 0i64;
        }
        else
        {
          Illusion::TexturePlat::CreateResources(
            (Illusion::TexturePlat *)&v30[6].mChild1,
            (Illusion::TextureD3DResource *)v24->mCachedBufferPtr);
        }
        if ( v30[5].mChild[0] )
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v30[4].mUID);
        ++v28;
        v29 = ($CA91B2824B6F331601351B2AC7FEF5D9 *)((char *)v29 + 8);
      }
      while ( v28 < 0x20 );
      UFG::qResourceInventory::Add(&Illusion::gTextureD3DResourceInventory, &v24->mCachedBufferPtr->UFG::qResourceData);
      v35 = (_QWORD *)v24[7].mNode.mUID;
      v2 = bBlocking;
      if ( v35 )
      {
        v36 = v35[1];
        v37 = (_QWORD *)v35[2];
        *(_QWORD *)(v36 + 8) = v37;
        *v37 = v36;
        v35[1] = v35 + 1;
        v35[2] = v35 + 1;
        operator delete[](v35);
        v24[7].mNode.mUID = 0i64;
      }
      operator delete[](v24);
    }
    else
    {
      UFG::qBaseTreeRB::Add(&this->mLoadingQueue.mTree, (UFG::qBaseNodeRB *)v24);
      v25 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      v26 = (Illusion::AsyncD3DCreationTask *)v25;
      if ( v25 )
      {
        v27 = v25 + 1;
        v27->mNext = v27;
        v27[1].mNext = v27;
        v26->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::AsyncD3DCreationTask::`vftable;
        v26->mTask = 0i64;
        v26->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::TextureLoader::`vftable;
        v26[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)v24;
      }
      else
      {
        v26 = 0i64;
      }
      v24[7].mNode.mUID = (unsigned __int64)v26;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v26);
    }
  }
}

// File Line: 965
// RVA: 0xA228B0
void __fastcall Illusion::TextureD3DResourceInventory::SyncLoadTasks(Illusion::TextureD3DResourceInventory *this)
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

// File Line: 980
// RVA: 0xA1FF90
void __fastcall Illusion::TextureD3DResourceInventory::ProcessQueuedUnLoads(
        Illusion::TextureD3DResourceInventory *this)
{
  Render::SkinningCacheNode *Head; // rbx
  Illusion::TextureD3DResource *mCachedBufferPtr; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> **v5; // rcx
  __int64 v6; // r8
  _QWORD *mUID; // rcx
  __int64 v8; // rdx
  _QWORD *v9; // rax

  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnUnloadQueue) )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mOnUnloadQueue);
    mCachedBufferPtr = (Illusion::TextureD3DResource *)Head->mCachedBufferPtr;
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
      if ( --mCachedBufferPtr->mRefCount <= 0 )
      {
        this->vfptr->Remove(this, mCachedBufferPtr);
        Illusion::TextureD3DResource::~TextureD3DResource(mCachedBufferPtr);
        operator delete[](mCachedBufferPtr);
        UFG::qMemSet(qword_14245AF48, 0, 0x40000u);
        break;
      }
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue,
      &Head->mNode);
    mUID = (_QWORD *)Head[7].mNode.mUID;
    if ( mUID )
    {
      v8 = mUID[1];
      v9 = (_QWORD *)mUID[2];
      *(_QWORD *)(v8 + 8) = v9;
      *v9 = v8;
      mUID[1] = mUID + 1;
      mUID[2] = mUID + 1;
      operator delete[](mUID);
      Head[7].mNode.mUID = 0i64;
    }
    operator delete[](Head);
  }
}

// File Line: 1033
// RVA: 0xA200D0
void __fastcall Illusion::TextureD3DResourceInventory::ProcessSyncCopies(Illusion::TextureD3DResourceInventory *this)
{
  UFG::qResourceWarehouse *v2; // rax
  volatile int v3; // esi
  unsigned int *mSyncCopyUIDs; // r14
  UFG::qResourceData *v5; // rbx
  UFG::qResourceData *v6; // rax
  Illusion::TexturePlat *p_mResourceHandles; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdi
  char *mData; // rdx
  Illusion::TextureLockInfo info; // [rsp+38h] [rbp-40h] BYREF
  Illusion::TextureLockInfo v11; // [rsp+48h] [rbp-30h] BYREF

  if ( (_S1_32 & 1) == 0 )
  {
    _S1_32 |= 1u;
    v2 = UFG::qResourceWarehouse::Instance();
    texInventory_3 = UFG::qResourceWarehouse::GetInventory(v2, 0x8B43FABF);
  }
  v3 = 0;
  if ( Illusion::gTextureNumSyncUIDs > 0 )
  {
    mSyncCopyUIDs = this->mSyncCopyUIDs;
    while ( 1 )
    {
      v5 = this->vfptr->Get(this, *mSyncCopyUIDs);
      v6 = texInventory_3->vfptr->Get(texInventory_3, *mSyncCopyUIDs);
      if ( !v5 || !v6 )
        goto LABEL_16;
      p_mResourceHandles = (Illusion::TexturePlat *)&v6[2].mResourceHandles;
      mPrev = v6[3].mResourceHandles.mNode.mPrev;
      if ( !mPrev[10].mPrev )
        Illusion::TexturePlat::CreateClearedMainMemCopy((Illusion::TexturePlat *)&v6[2].mResourceHandles);
      if ( !LODWORD(mPrev[9].mNext) )
        break;
      info.mData = 0i64;
      *(_QWORD *)&info.mLinePitch = 0i64;
      if ( Illusion::TexturePlat::Lock(p_mResourceHandles, 1, &info, 0, 0) )
      {
        mData = info.mData;
LABEL_15:
        UFG::qMemCopy(mPrev[10].mPrev->mPrev, mData, HIDWORD(mPrev[10].mPrev->mNext));
        Illusion::TexturePlat::Unlock(p_mResourceHandles);
      }
LABEL_16:
      ++v3;
      ++mSyncCopyUIDs;
      if ( v3 >= Illusion::gTextureNumSyncUIDs )
        goto LABEL_17;
    }
    if ( !mPrev[12].mNext )
      goto LABEL_16;
    v11.mData = 0i64;
    *(_QWORD *)&v11.mLinePitch = 0i64;
    if ( !Illusion::TexturePlat::Lock(p_mResourceHandles, 0, &v11, 0, 0) )
      goto LABEL_16;
    mData = v11.mData;
    goto LABEL_15;
  }
LABEL_17:
  Illusion::gTextureNumSyncUIDs = 0;
}

// File Line: 1051
// RVA: 0xA1AA60
void __fastcall Illusion::TextureD3DResourceInventory::ForceLoad(
        Illusion::TextureD3DResourceInventory *this,
        unsigned int uid)
{
  UFG::qBaseTreeVariableRB<unsigned __int64> *p_mOnLoadQueue; // r14
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rdi
  UFG::qBaseNodeRB *v7; // rbx
  unsigned int *p_mUID; // rdx
  __int64 v9; // r8
  unsigned int *v10; // rax
  __int64 v11; // rdx
  unsigned int mUID; // edx
  bool v13; // r8
  char v14; // cl
  int v15; // eax
  UFG::qBaseNodeRB *v16; // rcx
  UFG::qBaseNodeRB *v17; // rdx
  UFG::qBaseNodeRB *v18; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v19; // rcx
  UFG::qBaseTreeRB *v20; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v21; // rbx
  UFG::qBaseNodeRB *v22; // rdi
  UFG::qTask *v23; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v24; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v25; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v26; // rax

  if ( uid )
  {
    p_mOnLoadQueue = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue;
    v5 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, uid);
    v6 = v5;
    if ( v5 )
    {
      v7 = v5->mNULL.mChild[1];
      p_mUID = &v5->mNULL.mUID;
      v9 = 31i64;
      do
      {
        *((_QWORD *)p_mUID - 1) = *(_QWORD *)p_mUID;
        p_mUID += 2;
        --v9;
      }
      while ( v9 );
      v5[4].mRoot.mChild[0] = 0i64;
      if ( v7 )
      {
        Illusion::TexturePlat::CreateResources(
          (Illusion::TexturePlat *)&v7[6].mChild[1],
          (Illusion::TextureD3DResource *)v5->mNULL.mParent);
        if ( v7[5].mChild[0] )
LABEL_7:
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v7[4].mUID);
      }
      while ( 1 )
      {
        v7 = v6->mNULL.mChild[1];
        v10 = &v6->mNULL.mUID;
        v11 = 31i64;
        do
        {
          *((_QWORD *)v10 - 1) = *(_QWORD *)v10;
          v10 += 2;
          --v11;
        }
        while ( v11 );
        v6[4].mRoot.mChild[0] = 0i64;
        if ( !v7 )
          break;
        UFG::qAtomicIncrement((volatile int *)&v6->mNULL.mParent[7].mChild[1]);
        v7[7].mChild[1] = 0i64;
        *(_QWORD *)(&v7[6].mUID + 1) = 0i64;
        mUID = v7[2].mUID;
        v13 = (mUID & 0x40000) != 0 || (v7[2].mUID & 0x20000) != 0;
        if ( (mUID & 0x400) != 0 || (v7[2].mUID & 0x20000) != 0 )
        {
          v14 = 1;
          if ( (v7[2].mUID & 0x20000) != 0 )
            v7[2].mUID = mUID | 0x400000;
        }
        else
        {
          v14 = 0;
        }
        if ( v13 )
        {
          v15 = 1;
          if ( v14 )
            v15 = 3;
        }
        else
        {
          v15 = v14 != 0 ? 2 : 0;
        }
        v7[6].mUID = v15;
        v7[7].mChild[0] = 0i64;
        if ( v7[5].mChild[0] )
          goto LABEL_7;
      }
      UFG::qResourceInventory::Add(&Illusion::gTextureD3DResourceInventory, (UFG::qResourceData *)v6->mNULL.mParent);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        p_mOnLoadQueue,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
      v16 = v6[4].mRoot.mChild[1];
      if ( v16 )
      {
        v17 = v16->mChild[0];
        v18 = v16->mChild[1];
        v17->mChild[0] = v18;
        v18->mParent = v17;
        v16->mChild[0] = (UFG::qBaseNodeRB *)v16->mChild;
        v16->mChild[1] = (UFG::qBaseNodeRB *)v16->mChild;
        operator delete[](v16);
        v6[4].mRoot.mChild[1] = 0i64;
      }
      v19 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6;
    }
    else
    {
      v20 = UFG::qBaseTreeRB::Get(&this->mLoadingQueue.mTree, uid);
      v21 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v20;
      if ( !v20 )
        return;
      v22 = v20[4].mRoot.mChild[1];
      if ( v22 )
      {
        v23 = *(UFG::qTask **)&v22->mUID;
        if ( v23 )
        {
          UFG::qTaskManager::Sync(&UFG::gTaskManager, v23);
          *(_QWORD *)&v22->mUID = 0i64;
          ((void (__fastcall *)(UFG::qBaseNodeRB *))v22->mParent->mChild[0])(v22);
        }
      }
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mLoadingQueue,
        v21);
      v24 = v21[9].mChild[1];
      if ( v24 )
      {
        v25 = v24->mChild[0];
        v26 = v24->mChild[1];
        v25->mChild[0] = v26;
        v26->mParent = v25;
        v24->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v24->8;
        v24->mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v24->8;
        operator delete[](v24);
        v21[9].mChild[1] = 0i64;
      }
      v19 = v21;
    }
    operator delete[](v19);
  }
}

// File Line: 1117
// RVA: 0xA1ACE0
void __fastcall Illusion::TextureD3DResourceInventory::ForceUnload(
        Illusion::TextureD3DResourceInventory *this,
        unsigned int uid)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rbx
  Illusion::TextureD3DResource *mParent; // rdi
  UFG::qBaseNodeRB *v7; // r8
  unsigned int *p_mUID; // rcx
  __int64 v9; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v10; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v11; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v12; // rax
  UFG::qResourceData *v13; // rax

  if ( uid
    && (v4 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, uid),
        (v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v4) != 0i64) )
  {
    mParent = (Illusion::TextureD3DResource *)v4->mNULL.mParent;
    while ( 1 )
    {
      v7 = v4->mNULL.mChild[1];
      p_mUID = &v4->mNULL.mUID;
      v9 = 31i64;
      do
      {
        *((_QWORD *)p_mUID - 1) = *(_QWORD *)p_mUID;
        p_mUID += 2;
        --v9;
      }
      while ( v9 );
      v4[4].mRoot.mChild[0] = 0i64;
      if ( !v7 )
        break;
      if ( --mParent->mRefCount <= 0 )
      {
        this->vfptr->Remove(this, mParent);
        Illusion::TextureD3DResource::~TextureD3DResource(mParent);
        operator delete[](mParent);
        break;
      }
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnUnloadQueue,
      v5);
    v10 = v5[9].mChild[1];
    if ( v10 )
    {
      v11 = v10->mChild[0];
      v12 = v10->mChild[1];
      v11->mChild[0] = v12;
      v12->mParent = v11;
      v10->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v10->8;
      v10->mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v10->8;
      operator delete[](v10);
      v5[9].mChild[1] = 0i64;
    }
  }
  else
  {
    v13 = this->vfptr->Get(this, uid);
    v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v13;
    if ( !v13 )
      return;
    this->vfptr->Remove(this, v13);
    Illusion::TextureD3DResource::~TextureD3DResource((Illusion::TextureD3DResource *)v5);
  }
  operator delete[](v5);
}

// File Line: 1169
// RVA: 0xA16B40
void __fastcall Illusion::TextureD3DResource::~TextureD3DResource(Illusion::TextureD3DResource *this)
{
  Illusion::TextureLockInfo *mDeferredContextTextureAccessBuffer; // rcx
  ID3D11SamplerState *mSamplerState; // rcx
  ID3D11ShaderResourceView *mShaderResourceView; // rcx
  unsigned int i; // edi
  __int64 v6; // rsi
  ID3D11ShaderResourceView *v7; // rcx
  ID3D11ShaderResourceView **mShaderResourceViewMips; // rcx
  ID3D11Resource *mStagingResource; // rcx
  ID3D11Resource *mGpuResource; // rcx
  ID3D11Resource **mDelayedReadCopy; // rdi
  __int64 v12; // rsi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v17; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v18; // rax

  mDeferredContextTextureAccessBuffer = this->mDeferredContextTextureAccessBuffer;
  if ( mDeferredContextTextureAccessBuffer )
  {
    operator delete[](mDeferredContextTextureAccessBuffer->mData);
    operator delete[](this->mDeferredContextTextureAccessBuffer);
    this->mDeferredContextTextureAccessBuffer = 0i64;
  }
  mSamplerState = this->mSamplerState;
  if ( mSamplerState )
  {
    mSamplerState->vfptr->Release(mSamplerState);
    this->mSamplerState = 0i64;
  }
  mShaderResourceView = this->mShaderResourceView;
  if ( mShaderResourceView )
  {
    mShaderResourceView->vfptr->Release(mShaderResourceView);
    this->mShaderResourceView = 0i64;
  }
  if ( this->mShaderResourceViewMips )
  {
    for ( i = 0; i < this->mNumberMipViews; ++i )
    {
      v6 = i;
      v7 = this->mShaderResourceViewMips[v6];
      if ( v7 )
      {
        v7->vfptr->Release(v7);
        this->mShaderResourceViewMips[v6] = 0i64;
      }
    }
  }
  mShaderResourceViewMips = this->mShaderResourceViewMips;
  if ( mShaderResourceViewMips )
  {
    operator delete[](mShaderResourceViewMips);
    this->mShaderResourceViewMips = 0i64;
  }
  mStagingResource = this->mStagingResource;
  if ( mStagingResource )
  {
    mStagingResource->vfptr->Release(mStagingResource);
    this->mStagingResource = 0i64;
  }
  if ( !this->mAliased )
  {
    mGpuResource = this->mGpuResource;
    if ( mGpuResource )
    {
      mGpuResource->vfptr->Release(mGpuResource);
      this->mGpuResource = 0i64;
    }
  }
  mDelayedReadCopy = this->mDelayedReadCopy;
  v12 = 5i64;
  do
  {
    if ( *mDelayedReadCopy )
    {
      (*mDelayedReadCopy)->vfptr->Release(*mDelayedReadCopy);
      *mDelayedReadCopy = 0i64;
    }
    ++mDelayedReadCopy;
    --v12;
  }
  while ( v12 );
  p_mResourceHandles = &this->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
        j != (UFG::qResourceHandle *)p_mResourceHandles;
        j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v17 = p_mResourceHandles->mNode.mPrev;
  v18 = p_mResourceHandles->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
}

// File Line: 1224
// RVA: 0xA1EB80
void __fastcall Illusion::TexturePlat::OnLoad(Illusion::TexturePlat *this)
{
  char *v2; // rsi
  AMD_HD3D *v3; // rbp
  int mData; // eax
  char *FileData; // rax
  unsigned int v6; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = &this[-2].mPadding[40];
  v3 = 0i64;
  this->mInitialImageData = 0i64;
  mData = (int)this[-1].mVRamHandle.mData;
  if ( (mData & 0x8000) != 0 )
  {
    this->mInitialImageData = this->mVRamHandle.mData;
  }
  else if ( (mData & 0x4000) == 0 )
  {
    Illusion::TexturePlat::TexturePlat(this);
    *((_QWORD *)v2 + 23) = Illusion::Texture::HandleUpdated;
    *((_QWORD *)v2 + 24) = v2;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v2 + 152), 0xA428072C, *((_DWORD *)v2 + 44));
    FileData = UFG::qResourceFileHandle::GetFileData((UFG::qResourceFileHandle *)(v2 + 152), *((_DWORD *)v2 + 32));
    this->mInitialImageData = FileData;
    if ( (*((_DWORD *)v2 + 22) & 0x20000) == 0 )
      UFG::qVRAMemoryPools::BindWithinContainer(&this->mVRamHandle, FileData, *((_DWORD *)v2 + 30), v2 + 52);
  }
  if ( Illusion::TextureD3DResourceInventory::OnTextureLoad(
         &Illusion::gTextureD3DResourceInventory,
         (Illusion::Texture *)v2)
    && *((_QWORD *)v2 + 21) )
  {
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)(v2 + 152));
  }
  v6 = *(_DWORD *)&this[-2].mPadding[64];
  Inventory = `UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0xEF77C5F7);
    `UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mTextureD3DResourceHandle, 0xEF77C5F7, v6, Inventory);
  if ( this->mTextureUserPlat.mOffset )
    v3 = (AMD_HD3D *)((char *)this + this->mTextureUserPlat.mOffset);
  _(v3);
}

// File Line: 1298
// RVA: 0xA1F380
void __fastcall Illusion::TexturePlat::OnUnload(Illusion::TexturePlat *this)
{
  AMD_HD3D *v2; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  if ( ((__int64)this[-1].mVRamHandle.mData & 0x8000) == 0 )
  {
    if ( this->mTextureUserPlat.mOffset )
      v2 = (AMD_HD3D *)((char *)this + this->mTextureUserPlat.mOffset);
    else
      v2 = 0i64;
    _(v2);
    Illusion::TextureD3DResourceInventory::OnTextureUnload(
      &Illusion::gTextureD3DResourceInventory,
      (Illusion::Texture *)&this[-2].mPadding[40]);
    mPrev = this->mTextureD3DResourceHandle.mPrev;
    mNext = this->mTextureD3DResourceHandle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mTextureD3DResourceHandle.mPrev = &this->mTextureD3DResourceHandle;
    this->mTextureD3DResourceHandle.mNext = &this->mTextureD3DResourceHandle;
    if ( this->mVRamHandle.mData )
      UFG::qVRAMemoryPools::Free(&this->mVRamHandle, 0);
    if ( *(_QWORD *)&this[-1].mPadding[32] )
      UFG::qResourceHandle::Close((UFG::qResourceHandle *)&this[-1].mPadding[16]);
  }
}

// File Line: 1321
// RVA: 0xA17000
void __fastcall Illusion::TexturePlat::AcquireResources(
        Illusion::TexturePlat *this,
        Illusion::TextureD3DResource *textureD3D)
{
  int mData; // edx
  bool v4; // r8
  char v5; // cl
  unsigned int v6; // eax

  UFG::qAtomicIncrement(&textureD3D->mRefCount);
  this->mMappedResource = 0i64;
  *(_QWORD *)&this->mMappedSubResourceIdx = 0i64;
  mData = (int)this[-1].mVRamHandle.mData;
  v4 = (mData & 0x40000) != 0 || ((__int64)this[-1].mVRamHandle.mData & 0x20000) != 0;
  if ( (mData & 0x400) != 0 || ((__int64)this[-1].mVRamHandle.mData & 0x20000) != 0 )
  {
    v5 = 1;
    if ( ((__int64)this[-1].mVRamHandle.mData & 0x20000) != 0 )
      LODWORD(this[-1].mVRamHandle.mData) = mData | 0x400000;
  }
  else
  {
    v5 = 0;
  }
  this->mInitialImageData = 0i64;
  if ( v4 )
  {
    v6 = 1;
    if ( v5 )
      v6 = 3;
    this->mCpuAccess = v6;
  }
  else
  {
    this->mCpuAccess = v5 != 0 ? 2 : 0;
  }
}

// File Line: 1353
// RVA: 0xA18FC0
void __fastcall Illusion::TexturePlat::CreateResources(
        Illusion::TexturePlat *this,
        Illusion::TextureD3DResource *textureD3D)
{
  int mData; // eax
  __int64 v5; // rsi
  char v6; // al
  unsigned int v7; // edx
  bool v8; // r12
  int v9; // eax
  bool v10; // di
  char v11; // cl
  int v12; // eax
  bool v13; // bl
  int v14; // r13d
  bool v15; // r8
  unsigned int v16; // eax
  int v17; // eax
  bool v18; // cf
  unsigned int v19; // eax
  char v20; // cl
  D3D11_USAGE v21; // eax
  unsigned int v22; // eax
  unsigned int BindFlags; // eax
  bool v24; // bl
  ID3D11Resource *v25; // rcx
  bool v26; // cl
  ID3D11Texture2D *v27; // rax
  char *mInitialImageData; // r9
  bool v29; // zf
  __int64 v30; // rax
  unsigned int v31; // r11d
  int v32; // ecx
  signed int v33; // r10d
  int v34; // edx
  int v35; // r13d
  int v36; // r8d
  int v37; // r12d
  unsigned int v38; // ebx
  int v39; // edi
  int v40; // esi
  __int64 v41; // rcx
  unsigned int v42; // esi
  Illusion::TextureLockInfo *v43; // rax
  char *v44; // rax
  void *v45; // rdx
  int mPrev_low; // eax
  int v47; // edx
  D3D11_SUBRESOURCE_DATA *v48; // r8
  ID3D11Resource *Texture; // rax
  ID3D11Resource *v50; // rdx
  int v51; // eax
  unsigned __int64 v52; // rax
  __int64 v53; // rbx
  int v54; // eax
  unsigned int MipLevels; // eax
  ID3D11ShaderResourceView **mShaderResourceViewMips; // rax
  ID3D11Resource *v57; // rdx
  ID3D11Resource *mGpuResource; // rdx
  int v59; // eax
  UFG::qResourceData *v60; // rbx
  __int64 v61; // rdi
  ID3D11Resource *CompatibleStagingResource; // rax
  bool v63; // [rsp+20h] [rbp-E0h]
  bool v64; // [rsp+24h] [rbp-DCh]
  int v65; // [rsp+28h] [rbp-D8h] BYREF
  __int64 v66; // [rsp+2Ch] [rbp-D4h]
  char v67[12]; // [rsp+34h] [rbp-CCh]
  int v68; // [rsp+40h] [rbp-C0h]
  int v69; // [rsp+44h] [rbp-BCh]
  int v70; // [rsp+48h] [rbp-B8h]
  int v71; // [rsp+4Ch] [rbp-B4h]
  int v72; // [rsp+50h] [rbp-B0h]
  int v73; // [rsp+54h] [rbp-ACh]
  void *source; // [rsp+58h] [rbp-A8h]
  unsigned int v75; // [rsp+60h] [rbp-A0h]
  int v76; // [rsp+64h] [rbp-9Ch]
  _DWORD v77[144]; // [rsp+70h] [rbp-90h] BYREF
  bool v78; // [rsp+2C0h] [rbp+1C0h]
  char v79; // [rsp+2C8h] [rbp+1C8h]
  bool v80; // [rsp+2D0h] [rbp+1D0h]
  bool v81; // [rsp+2D8h] [rbp+1D8h]

  UFG::qAtomicIncrement(&textureD3D->mRefCount);
  mData = (int)this[-1].mVRamHandle.mData;
  v5 = 0i64;
  if ( (mData & 0x8000) == 0 && (mData & 0x4000) != 0 && (mData & 0x200000) != 0 )
    v5 = *(_QWORD *)&this[-1].mTextureD3DResourceHandle.mNameUID;
  this->mMappedResource = 0i64;
  *(_QWORD *)&this->mMappedSubResourceIdx = 0i64;
  v6 = BYTE5(this[-1].mVRamHandle.mData);
  v7 = (unsigned int)this[-1].mVRamHandle.mData;
  v63 = v6 == 0;
  v8 = v6 == 2;
  v78 = v6 == 3;
  v9 = v7 >> 11;
  LOBYTE(v9) = (v7 & 0x800) != 0;
  v70 = v9;
  if ( (v7 & 0x40000) != 0 || (v79 = 0, (v7 & 0x20000) != 0) )
    v79 = 1;
  v10 = (v7 & 0x400) != 0 || (v7 & 0x20000) != 0;
  v11 = BYTE4(this[-1].mVRamHandle.mData);
  v80 = ((v11 - 16) & 0xFD) == 0;
  v81 = v11 == 19;
  v12 = v7 >> 19;
  LOBYTE(v12) = (v7 & 0x80000) != 0;
  v13 = (v7 & 0x800000) != 0;
  v76 = v12;
  v64 = (v7 & 0x100000) != 0;
  if ( (v7 & 0x20000) != 0 )
    LODWORD(this[-1].mVRamHandle.mData) = v7 | 0x400000;
  v14 = LODWORD(this[-1].mVRamHandle.mData) >> 22;
  LOBYTE(v14) = ((__int64)this[-1].mVRamHandle.mData & 0x400000) != 0;
  v69 = v14;
  memset(&textureD3D->mDesc, 0, sizeof(textureD3D->mDesc));
  v15 = v78;
  textureD3D->mDesc.Width = *(&this[-1].mVRamHandle.mBlockID + 1);
  textureD3D->mDesc.Height = *(&this[-1].mVRamHandle.mBlockID + 2);
  textureD3D->mDesc.MipLevels = LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev);
  if ( v78 )
  {
    v16 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
  }
  else
  {
    v16 = 1;
    if ( v8 )
      v16 = 6;
  }
  textureD3D->mDesc.ArraySize = v16;
  *(_DWORD *)textureD3D->mDesc.Format = Illusion::HardwareState::sTextureFormat[BYTE4(this[-1].mVRamHandle.mData)];
  v17 = (int)this[-1].mVRamHandle.mData;
  if ( (v17 & 0x4000000) != 0 )
  {
    textureD3D->mDesc.SampleDesc.Count = 2;
  }
  else
  {
    v18 = (v17 & 0x8000000) != 0;
    v19 = 1;
    if ( v18 )
      v19 = 4;
    textureD3D->mDesc.SampleDesc.Count = v19;
  }
  v20 = v70;
  textureD3D->mDesc.SampleDesc.Quality = 0;
  if ( v20 || v10 || v79 || (_BYTE)v14 || (v21 = D3D11_USAGE_IMMUTABLE, !this->mInitialImageData) )
    v21 = D3D11_USAGE_DEFAULT;
  textureD3D->mDesc.Usage = v21;
  *(_QWORD *)&textureD3D->mDesc.CPUAccessFlags = 0i64;
  textureD3D->mDesc.BindFlags = (v13 ? 0x80 : 0) | 8;
  if ( v79 )
  {
    v22 = 1;
    if ( v10 )
      v22 = 3;
  }
  else
  {
    v22 = v10 ? 2 : 0;
  }
  this->mCpuAccess = v22;
  if ( v20 )
  {
    textureD3D->mDesc.BindFlags |= 0x20u;
  }
  else if ( v22 == 2 )
  {
    textureD3D->mDesc.Usage = D3D11_USAGE_DYNAMIC;
    textureD3D->mDesc.CPUAccessFlags = 0x10000;
  }
  if ( v8 )
    textureD3D->mDesc.MiscFlags |= 4u;
  BindFlags = textureD3D->mDesc.BindFlags;
  v24 = v80;
  if ( v80 )
    BindFlags = 72;
  textureD3D->mDesc.BindFlags = BindFlags;
  if ( v5 )
  {
    v25 = *(ID3D11Resource **)(*(_QWORD *)(v5 + 296) + 136i64);
    textureD3D->mAliased = 1;
    textureD3D->mGpuResource = v25;
LABEL_77:
    v26 = v64;
    goto LABEL_78;
  }
  v26 = v64;
  if ( !v64 )
  {
    mInitialImageData = this->mInitialImageData;
    source = mInitialImageData;
    if ( mInitialImageData && textureD3D->mDesc.Usage <= (unsigned int)D3D11_USAGE_IMMUTABLE )
    {
      v29 = ((__int64)this[-1].mVRamHandle.mData & 0x24000) == 0;
      v30 = BYTE4(this[-1].mVRamHandle.mData);
      v31 = Illusion::HardwareState::sTextureSize[v30];
      v75 = v31;
      if ( v29 )
      {
        mInitialImageData = this->mVRamHandle.mData;
        source = mInitialImageData;
      }
      v32 = 16;
      if ( (_BYTE)v30 == 1 )
        v32 = 8;
      v33 = 0;
      v71 = v32;
      v72 = 0;
      if ( (int)textureD3D->mDesc.ArraySize > 0 )
      {
        do
        {
          v34 = *(&this[-1].mVRamHandle.mBlockID + 2);
          v35 = *(&this[-1].mVRamHandle.mBlockID + 1);
          v29 = !v15;
          v73 = v34;
          v36 = 1;
          if ( v29 )
            v36 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
          v37 = 0;
          v68 = v36;
          if ( LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev) )
          {
            do
            {
              if ( BYTE4(this[-1].mVRamHandle.mData)
                && (BYTE4(this[-1].mVRamHandle.mData) <= 3u || (unsigned int)BYTE4(this[-1].mVRamHandle.mData) - 8 <= 5) )
              {
                v38 = v32 * ((v35 + 3) >> 2);
                v39 = v38 * ((v34 + 3) >> 2);
              }
              else
              {
                v38 = (v31 * v35) >> 3;
                v39 = v34 * v38;
              }
              v40 = v36;
              v41 = 2i64 * (v37 + v33 * LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev));
              if ( v36 < 1 )
                v40 = 1;
              *(_QWORD *)&v77[4 * v37 + 4 * v33 * LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev)] = mInitialImageData;
              v77[2 * v41 + 2] = v38;
              v77[2 * v41 + 3] = v39;
              v42 = (v31 * v35 * v34 * v40) >> 3;
              if ( (_BYTE)v69 && !v33 && !v37 )
              {
                v43 = (Illusion::TextureLockInfo *)UFG::qMalloc(0x10ui64, "mDeferredContextTextureAccessBuffer", 0i64);
                textureD3D->mDeferredContextTextureAccessBuffer = v43;
                v43->mLinePitch = v38;
                textureD3D->mDeferredContextTextureAccessBuffer->mDepthPitch = v39;
                v44 = (char *)UFG::qMalloc(v42, (const char *)&this[-1].mPad, 0i64);
                v45 = source;
                textureD3D->mDeferredContextTextureAccessBuffer->mData = v44;
                UFG::qMemCopy(textureD3D->mDeferredContextTextureAccessBuffer->mData, v45, v42);
                v34 = v73;
                v36 = v68;
                mInitialImageData = (char *)source;
                v33 = v72;
                v31 = v75;
              }
              v32 = v71;
              v34 >>= 1;
              mInitialImageData += v42;
              mPrev_low = LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev);
              v36 >>= 1;
              ++v37;
              v35 >>= 1;
              v73 = v34;
              source = mInitialImageData;
              v68 = v36;
            }
            while ( v37 < mPrev_low );
          }
          v15 = v78;
          v72 = ++v33;
        }
        while ( v33 < (signed int)textureD3D->mDesc.ArraySize );
        LOBYTE(v14) = v69;
        v24 = v80;
      }
      v47 = 1;
      if ( !v15 )
        v47 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
      v48 = (D3D11_SUBRESOURCE_DATA *)v77;
    }
    else
    {
      v47 = 1;
      if ( !v78 )
        v47 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
      v48 = 0i64;
    }
    Texture = Illusion::CreateTexture(&textureD3D->mDesc, v47, v48);
    v15 = v78;
    textureD3D->mGpuResource = Texture;
    goto LABEL_77;
  }
  v27 = gPresentBuffer;
  textureD3D->mAliased = 1;
  textureD3D->mGpuResource = v27;
LABEL_78:
  if ( v24 || v81 )
  {
    if ( v63 )
    {
      v66 = 4i64;
      *(_DWORD *)v67 = 1;
      *(_QWORD *)&v67[4] = 0i64;
    }
    else
    {
      if ( !v15 )
        goto LABEL_95;
      v66 = 5i64;
      *(_QWORD *)&v67[4] = 0i64;
      v59 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
      *(_QWORD *)v67 = 1i64;
      *(_DWORD *)&v67[8] = v59;
    }
    mGpuResource = textureD3D->mGpuResource;
    v65 = 46;
    ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
      UFG::gD3D11Device,
      mGpuResource,
      &v65,
      &textureD3D->mShaderResourceView);
  }
  else if ( !v26 )
  {
    v50 = textureD3D->mGpuResource;
    if ( v15 )
    {
      v51 = *(_DWORD *)textureD3D->mDesc.Format;
      v66 = 5i64;
      v65 = v51;
      *(_QWORD *)&v67[4] = 0i64;
      *(_DWORD *)&v67[8] = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
      *(_DWORD *)v67 = LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev);
      ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
        UFG::gD3D11Device,
        v50,
        &v65,
        &textureD3D->mShaderResourceView);
    }
    else
    {
      ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, _QWORD, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
        UFG::gD3D11Device,
        v50,
        0i64,
        &textureD3D->mShaderResourceView);
    }
    if ( (_BYTE)v76 )
    {
      v52 = 8i64 * textureD3D->mDesc.MipLevels;
      if ( !is_mul_ok(textureD3D->mDesc.MipLevels, 8ui64) )
        v52 = -1i64;
      v53 = 0i64;
      textureD3D->mShaderResourceViewMips = (ID3D11ShaderResourceView **)UFG::qMalloc(
                                                                           v52,
                                                                           "ID3D11ShaderResourceView Array",
                                                                           0i64);
      v54 = *(_DWORD *)textureD3D->mDesc.Format;
      LODWORD(v66) = 4;
      v65 = v54;
      MipLevels = textureD3D->mDesc.MipLevels;
      *(_DWORD *)v67 = 1;
      textureD3D->mNumberMipViews = MipLevels;
      if ( MipLevels )
      {
        do
        {
          mShaderResourceViewMips = textureD3D->mShaderResourceViewMips;
          v57 = textureD3D->mGpuResource;
          HIDWORD(v66) = v53;
          ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
            UFG::gD3D11Device,
            v57,
            &v65,
            &mShaderResourceViewMips[v53]);
          v53 = (unsigned int)(v53 + 1);
        }
        while ( (unsigned int)v53 < textureD3D->mNumberMipViews );
      }
    }
  }
LABEL_95:
  this->mInitialImageData = 0i64;
  textureD3D->mStagingResourceInitialized = 0;
  if ( v79 && !(_BYTE)v70 && !(_BYTE)v14 )
  {
    v60 = this->mTextureD3DResourceHandle.mData;
    v61 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    if ( !*(_QWORD *)&v60[1].mDebugName[4] )
    {
      CompatibleStagingResource = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
      *(_DWORD *)&v60[1].mDebugName[12] = 0;
      *(_QWORD *)&v60[1].mDebugName[4] = CompatibleStagingResource;
    }
    (*(void (__fastcall **)(__int64, _QWORD, ID3D11Resource *))(*(_QWORD *)v61 + 376i64))(
      v61,
      *(_QWORD *)&v60[1].mDebugName[4],
      textureD3D->mGpuResource);
    textureD3D->mStagingResourceInitialized = 1;
  }
  Illusion::TexturePlat::CreateSamplerState(this, textureD3D);
}

// File Line: 1709
// RVA: 0xA196E0
void __fastcall Illusion::TexturePlat::CreateSamplerState(
        Illusion::TexturePlat *this,
        Illusion::TextureD3DResource *textureD3D)
{
  ID3D11SamplerState **p_mSamplerState; // rdi
  ID3D11SamplerState *mSamplerState; // rcx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  __int64 mData_high; // rax
  int v14; // xmm0_4
  unsigned int mData; // r9d
  unsigned int v16; // edx
  unsigned int v17; // r8d
  char v18; // r8
  __int64 v19; // r9
  char v20; // dl
  int v21; // ecx
  int Dst[18]; // [rsp+20h] [rbp-48h] BYREF

  p_mSamplerState = &textureD3D->mSamplerState;
  mSamplerState = textureD3D->mSamplerState;
  if ( mSamplerState )
  {
    mSamplerState->vfptr->Release(mSamplerState);
    *p_mSamplerState = 0i64;
  }
  memset(Dst, 0, 0x34ui64);
  v5 = BYTE1(this[-1].mTextureD3DResourceHandle.mPrev);
  if ( BYTE4(this[-1].mVRamHandle.mData) != 18 )
  {
    if ( BYTE1(this[-1].mTextureD3DResourceHandle.mPrev) )
    {
      v9 = v5 - 1;
      if ( !v9 )
        goto LABEL_18;
      v10 = v9 - 1;
      if ( !v10 )
      {
        Dst[0] = 0;
        goto LABEL_24;
      }
      v11 = v10 - 1;
      if ( v11 )
      {
        if ( v11 != 1 )
        {
LABEL_24:
          Dst[6] = 8;
          goto LABEL_25;
        }
LABEL_18:
        Dst[0] = 21;
        goto LABEL_24;
      }
      v12 = 85;
    }
    else
    {
      v12 = 85;
      if ( gDefaultTextureFilterQuality == 1 )
        v12 = 21;
    }
    Dst[0] = v12;
    goto LABEL_24;
  }
  if ( !BYTE1(this[-1].mTextureD3DResourceHandle.mPrev) )
    goto LABEL_9;
  v6 = v5 - 1;
  if ( !v6 )
    goto LABEL_9;
  v7 = v6 - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 != 1 )
      {
LABEL_10:
        Dst[6] = 4;
        goto LABEL_25;
      }
LABEL_9:
      Dst[0] = 149;
      goto LABEL_10;
    }
    Dst[0] = 213;
    Dst[6] = 4;
  }
  else
  {
    Dst[0] = 128;
    Dst[6] = 4;
  }
LABEL_25:
  mData_high = HIBYTE(this[-1].mVRamHandle.mData);
  v14 = 0;
  mData = (unsigned int)this[-1].mVRamHandle.mData;
  v16 = mData >> 3;
  v17 = mData >> 1;
  v19 = mData >> 2;
  v18 = v17 & 1;
  LOBYTE(v19) = v19 & 1;
  v20 = v16 & 1;
  if ( (mData_high & 0xF) != 0 )
  {
    if ( *(float *)&this[-1].mVRamHandle.mReadOnlyAndPoolID != 0.0 )
      v14 = *(_DWORD *)&this[-1].mVRamHandle.mReadOnlyAndPoolID;
  }
  else
  {
    v14 = LODWORD(aTexBias[mData_high]);
  }
  v21 = 3;
  if ( ((__int64)this[-1].mVRamHandle.mData & 1) != 0 )
    Dst[1] = 3;
  else
    Dst[1] = ((_BYTE)v19 != 0) + 1;
  if ( !v18 )
    v21 = (v20 != 0) + 1;
  Dst[2] = v21;
  Dst[3] = v21;
  Dst[4] = v14;
  Dst[5] = gDefaultTextureFilterQuality;
  Dst[11] = 0;
  *(float *)&Dst[12] = FLOAT_3_4028235e38;
  ((void (__fastcall *)(ID3D11Device *, int *, ID3D11SamplerState **, __int64))UFG::gD3D11Device->vfptr->GSSetSamplers)(
    UFG::gD3D11Device,
    Dst,
    p_mSamplerState,
    v19);
}

// File Line: 1785
// RVA: 0xA18B50
ID3D11Resource *__fastcall Illusion::TexturePlat::CreateCompatibleStagingResource(Illusion::TexturePlat *this)
{
  UFG::qResourceData *mData; // rdx
  int v3; // ecx
  int mParent; // r9d
  int v5; // r10d
  int v6; // r11d
  int mNext; // ebx
  int v8; // eax
  int v9; // edx
  int v11[5]; // [rsp+20h] [rbp-60h] BYREF
  __int64 v12; // [rsp+34h] [rbp-4Ch]
  int v13; // [rsp+3Ch] [rbp-44h]
  int v14; // [rsp+40h] [rbp-40h]
  UFG::qBaseNodeRB *v15; // [rsp+48h] [rbp-38h] BYREF
  int v16; // [rsp+50h] [rbp-30h]
  int v17; // [rsp+54h] [rbp-2Ch]
  int v18; // [rsp+58h] [rbp-28h]
  int v19; // [rsp+5Ch] [rbp-24h]
  unsigned int mUID; // [rsp+60h] [rbp-20h]
  __int64 v21; // [rsp+64h] [rbp-1Ch]
  int mPrev_high; // [rsp+6Ch] [rbp-14h]
  int v23; // [rsp+70h] [rbp-10h]
  __int64 v24; // [rsp+90h] [rbp+10h] BYREF

  mData = this->mTextureD3DResourceHandle.mData;
  v3 = 0;
  mParent = (int)mData[1].mNode.mParent;
  v15 = mData[1].mNode.mParent;
  v5 = (int)mData[1].mNode.mChild[0];
  v16 = v5;
  v17 = HIDWORD(mData[1].mNode.mChild[0]);
  v6 = (int)mData[1].mNode.mChild[1];
  v18 = v6;
  v19 = HIDWORD(mData[1].mNode.mChild[1]);
  mUID = mData[1].mNode.mUID;
  v21 = *(_QWORD *)(&mData[1].mNode.mUID + 1);
  mPrev_high = HIDWORD(mData[1].mResourceHandles.mNode.mPrev);
  mNext = (int)mData[1].mResourceHandles.mNode.mNext;
  v8 = (int)this[-1].mVRamHandle.mData;
  v23 = mNext;
  v21 = 3i64;
  mPrev_high = 0;
  if ( (v8 & 0x40000) != 0 || (v8 & 0x20000) != 0 )
  {
    v3 = 0x20000;
    mPrev_high = 0x20000;
  }
  if ( (v8 & 0x400) != 0 || (v8 & 0x20000) != 0 )
  {
    v3 |= 0x10000u;
    mPrev_high = v3;
  }
  v9 = 1;
  if ( BYTE5(this[-1].mVRamHandle.mData) != 3 )
    v9 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
  v24 = 0i64;
  if ( v9 <= 1 )
  {
    ((void (__fastcall *)(ID3D11Device *, UFG::qBaseNodeRB **, _QWORD, __int64 *))UFG::gD3D11Device->vfptr->PSSetShader)(
      UFG::gD3D11Device,
      &v15,
      0i64,
      &v24);
  }
  else
  {
    v11[0] = mParent;
    v13 = v3;
    v11[2] = v9;
    v11[1] = HIDWORD(v15);
    v11[3] = v5;
    v11[4] = v6;
    v12 = 3i64;
    v14 = mNext;
    ((void (__fastcall *)(ID3D11Device *, int *, _QWORD, __int64 *))UFG::gD3D11Device->vfptr->PSSetSamplers)(
      UFG::gD3D11Device,
      v11,
      0i64,
      &v24);
  }
  return (ID3D11Resource *)v24;
}

// File Line: 1815
// RVA: 0xA1AFC0
ID3D11Resource *__fastcall Illusion::TexturePlat::GetOrCreateStagingResource(Illusion::TexturePlat *this)
{
  UFG::qResourceData *mData; // rbx
  ID3D11Resource *result; // rax

  mData = this->mTextureD3DResourceHandle.mData;
  if ( *(_QWORD *)&mData[1].mDebugName[4] )
    return *(ID3D11Resource **)&mData[1].mDebugName[4];
  result = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
  *(_DWORD *)&mData[1].mDebugName[12] = 0;
  *(_QWORD *)&mData[1].mDebugName[4] = result;
  return result;
}

// File Line: 1828
// RVA: 0xA1ED30
void __fastcall Illusion::TexturePlat::OnPreMove(Illusion::TexturePlat *this)
{
  Illusion::Texture *v2; // rbx
  AMD_HD3D *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  v2 = (Illusion::Texture *)&this[-2].mPadding[40];
  if ( this->mTextureUserPlat.mOffset )
    v3 = (AMD_HD3D *)((char *)this + this->mTextureUserPlat.mOffset);
  else
    v3 = 0i64;
  _(v3);
  Illusion::TextureD3DResourceInventory::OnTextureUnload(&Illusion::gTextureD3DResourceInventory, v2);
  mPrev = this->mTextureD3DResourceHandle.mPrev;
  mNext = this->mTextureD3DResourceHandle.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mTextureD3DResourceHandle.mPrev = &this->mTextureD3DResourceHandle;
  this->mTextureD3DResourceHandle.mNext = &this->mTextureD3DResourceHandle;
  if ( v2->mTextureDataHandle.mData )
  {
    UFG::qResourceHandle::Close(&v2->mTextureDataHandle);
    v2->mFlags |= 0x1000000u;
  }
  v2->mFlags |= 0x8000u;
  UFG::qVRAMemoryPools::PreMove(&this->mVRamHandle);
}

// File Line: 1899
// RVA: 0xA17E80
void __fastcall Illusion::TexturePlat::CopyForDelayedRead(Illusion::TexturePlat *this)
{
  UFG::qResourceData *mData; // rbp
  float mMaxGpuFramesInFlight; // xmm0_4
  unsigned int *p_mUID; // rdi
  int v4; // ebx
  ID3D11Resource *CompatibleStagingResource; // rsi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rcx
  __int64 v7; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  __int64 v9; // rcx
  unsigned int *i; // rax

  mData = this->mTextureD3DResourceHandle.mData;
  mMaxGpuFramesInFlight = FLOAT_5_0;
  p_mUID = &mData[2].mNode.mUID;
  if ( (float)Illusion::gEnginePlat.mMaxGpuFramesInFlight <= 5.0 )
    mMaxGpuFramesInFlight = (float)Illusion::gEnginePlat.mMaxGpuFramesInFlight;
  v4 = 0;
  if ( *(_QWORD *)&p_mUID[2 * (int)mMaxGpuFramesInFlight - 2] )
  {
    CompatibleStagingResource = *(ID3D11Resource **)p_mUID;
    p_mResourceHandles = &mData[2].mResourceHandles;
    v7 = 4i64;
    do
    {
      mPrev = p_mResourceHandles->mNode.mPrev;
      p_mResourceHandles = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)((char *)p_mResourceHandles + 8);
      p_mResourceHandles[-1].mNode.mPrev = mPrev;
      --v7;
    }
    while ( v7 );
    *(_QWORD *)&mData[2].mDebugName[4] = 0i64;
  }
  else
  {
    CompatibleStagingResource = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
  }
  if ( CompatibleStagingResource )
  {
    v9 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    (*(void (__fastcall **)(__int64, ID3D11Resource *, _QWORD))(*(_QWORD *)v9 + 376i64))(
      v9,
      CompatibleStagingResource,
      *(_QWORD *)&mData[1].mTypeUID);
    for ( i = &mData[2].mNode.mUID; *(_QWORD *)i; i += 2 )
    {
      if ( ++v4 >= 5 )
        return;
    }
    *(_QWORD *)&p_mUID[2 * v4] = CompatibleStagingResource;
  }
}

// File Line: 1957
// RVA: 0xA1C570
char __fastcall Illusion::TexturePlat::Lock(
        Illusion::TexturePlat *this,
        int type,
        Illusion::TextureLockInfo *info,
        int mipLevel,
        int faceIndex)
{
  UFG::qResourceData *mData; // rdi
  char v8; // r13
  bool v10; // r12
  bool v11; // al
  bool v12; // r15
  int v14; // ebp
  int v15; // ebp
  unsigned int v16; // r14d
  ID3D11Resource *StagingResource; // rbp
  unsigned int mCpuAccess; // eax
  int v19; // r12d
  UFG::qResourceData *v20; // r15
  __int64 v21; // r13
  ID3D11Resource *CompatibleStagingResource; // rax
  int mPrev_low; // edi
  unsigned int v24; // edi
  char v25; // [rsp+30h] [rbp-58h]
  _QWORD *v26; // [rsp+38h] [rbp-50h]
  char *v27; // [rsp+40h] [rbp-48h] BYREF
  __int64 v28; // [rsp+48h] [rbp-40h]
  unsigned __int8 v29; // [rsp+90h] [rbp+8h]

  mData = this->mTextureD3DResourceHandle.mData;
  v8 = 0;
  v26 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
  v10 = ((__int64)this[-1].mVRamHandle.mData & 0x800) != 0;
  v25 = 0;
  v29 = 0;
  v11 = (*(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)*v26 + 896i64))(*v26) == 1;
  v12 = ((__int64)this[-1].mVRamHandle.mData & 0x400000) != 0 || *(_QWORD *)&mData[1].mDebugName[20];
  if ( !v11 || !v12 )
  {
    if ( !type )
    {
      if ( this->mCpuAccess != 1 )
        return 0;
      StagingResource = *(ID3D11Resource **)&mData[2].mNode.mUID;
      if ( !StagingResource )
        return 0;
      v16 = 1;
      v25 = 1;
      goto LABEL_45;
    }
    v14 = type - 1;
    if ( !v14 )
    {
      if ( ((this->mCpuAccess - 1) & 0xFFFFFFFD) != 0 )
        return 0;
      v16 = 1;
      StagingResource = Illusion::TexturePlat::GetOrCreateStagingResource(this);
      if ( v10 && !v12 || !*(_DWORD *)&mData[1].mDebugName[12] )
        v8 = 1;
      goto LABEL_45;
    }
    v15 = v14 - 1;
    if ( v15 )
    {
      if ( v15 != 1 || this->mCpuAccess != 3 )
        return 0;
      v16 = 3;
      v29 = 1;
      StagingResource = Illusion::TexturePlat::GetOrCreateStagingResource(this);
      if ( v10 && !v12 || !*(_DWORD *)&mData[1].mDebugName[12] )
        v8 = 1;
      goto LABEL_45;
    }
    mCpuAccess = this->mCpuAccess;
    if ( mCpuAccess == 2 )
    {
      if ( !v10 )
      {
        StagingResource = *(ID3D11Resource **)&mData[1].mTypeUID;
        v16 = 4;
LABEL_45:
        if ( StagingResource )
        {
          v19 = 0;
          if ( v8 )
          {
            v20 = this->mTextureD3DResourceHandle.mData;
            v21 = *v26;
            if ( !*(_QWORD *)&v20[1].mDebugName[4] )
            {
              CompatibleStagingResource = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
              *(_DWORD *)&v20[1].mDebugName[12] = 0;
              *(_QWORD *)&v20[1].mDebugName[4] = CompatibleStagingResource;
            }
            (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v21 + 376i64))(
              v21,
              *(_QWORD *)&v20[1].mDebugName[4],
              *(_QWORD *)&mData[1].mTypeUID);
            *(_DWORD *)&mData[1].mDebugName[12] = 1;
          }
          mPrev_low = LOBYTE(this[-1].mTextureD3DResourceHandle.mPrev);
          v28 = 0i64;
          v27 = 0i64;
          if ( v25 )
            v19 = 0x100000;
          v24 = mipLevel + faceIndex * mPrev_low;
          if ( (*(int (__fastcall **)(_QWORD, ID3D11Resource *, _QWORD, _QWORD, int, char **))(*(_QWORD *)*v26 + 112i64))(
                 *v26,
                 StagingResource,
                 v24,
                 v16,
                 v19,
                 &v27) >= 0 )
          {
            this->mMappedResource = StagingResource;
            this->mMappedSubResourceIdx = v24;
            this->mUploadAfterUnmap = v29;
            if ( info )
            {
              info->mData = v27;
              *(_QWORD *)&info->mLinePitch = v28;
            }
            return 1;
          }
        }
        return 0;
      }
    }
    else if ( mCpuAccess != 3 )
    {
      return 0;
    }
    v16 = 2;
    v29 = 1;
    StagingResource = Illusion::TexturePlat::GetOrCreateStagingResource(this);
    goto LABEL_45;
  }
  if ( type < 0 )
    return 0;
  if ( type > 1 )
  {
    if ( type <= 3 && this->mCpuAccess == 3 )
    {
      if ( !*(_QWORD *)&mData[1].mDebugName[20] )
        Illusion::TexturePlat::CreateClearedMainMemCopy(this);
      if ( info )
      {
        info->mData = **(char ***)&mData[1].mDebugName[20];
        info->mLinePitch = *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 8i64);
        info->mDepthPitch = *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 12i64);
      }
      this->mUploadAfterUnmap = 1;
      return 1;
    }
    return 0;
  }
  if ( ((this->mCpuAccess - 1) & 0xFFFFFFFD) != 0 )
    return 0;
  if ( !*(_QWORD *)&mData[1].mDebugName[20] )
    Illusion::TexturePlat::CreateClearedMainMemCopy(this);
  if ( info )
  {
    info->mData = **(char ***)&mData[1].mDebugName[20];
    info->mLinePitch = *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 8i64);
    info->mDepthPitch = *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 12i64);
  }
  return 1;
}

// File Line: 2147
// RVA: 0xA22A80
void __fastcall Illusion::TexturePlat::Unlock(Illusion::TexturePlat *this)
{
  UFG::qResourceData *mData; // rdi
  _QWORD *v3; // rsi
  _QWORD *v4; // rsi

  mData = this->mTextureD3DResourceHandle.mData;
  if ( this->mMappedResource )
  {
    v3 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    (*(void (__fastcall **)(_QWORD, ID3D11Resource *, _QWORD))(*(_QWORD *)*v3 + 120i64))(
      *v3,
      this->mMappedResource,
      this->mMappedSubResourceIdx);
    if ( this->mUploadAfterUnmap )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, ID3D11Resource *))(*(_QWORD *)*v3 + 376i64))(
        *v3,
        *(_QWORD *)&mData[1].mTypeUID,
        this->mMappedResource);
      *(_DWORD *)&mData[1].mDebugName[12] = 1;
    }
    this->mMappedResource = 0i64;
    this->mUploadAfterUnmap = 0;
  }
  else if ( this->mUploadAfterUnmap )
  {
    v4 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    if ( (*(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)*v4 + 896i64))(*v4) == 1
      && ((__int64)this[-1].mVRamHandle.mData & 0x400000) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD))(*(_QWORD *)*v4 + 384i64))(
        *v4,
        *(_QWORD *)&mData[1].mTypeUID,
        0i64,
        0i64,
        **(_QWORD **)&mData[1].mDebugName[20],
        *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 8i64),
        *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 12i64));
    }
    this->mUploadAfterUnmap = 0;
  }
  else
  {
    this->mUploadAfterUnmap = 0;
  }
}

// File Line: 2183
// RVA: 0xA22BC0
void __fastcall Illusion::TexturePlat::UpdateStagingResources(Illusion::TexturePlat *this)
{
  UFG::qResourceData *mData; // rbx
  __int64 v2; // rdi
  ID3D11Resource *CompatibleStagingResource; // rax
  unsigned int mUID; // ebx

  mData = this->mTextureD3DResourceHandle.mData;
  if ( Illusion::gTextureReadBackRequired || ((__int64)this[-1].mVRamHandle.mData & 0x20000) != 0 )
  {
    v2 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    if ( !*(_QWORD *)&mData[1].mDebugName[4] )
    {
      CompatibleStagingResource = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
      *(_DWORD *)&mData[1].mDebugName[12] = 0;
      *(_QWORD *)&mData[1].mDebugName[4] = CompatibleStagingResource;
    }
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v2 + 376i64))(
      v2,
      *(_QWORD *)&mData[1].mDebugName[4],
      *(_QWORD *)&mData[1].mTypeUID);
    *(_DWORD *)&mData[1].mDebugName[12] = 1;
  }
  else
  {
    Illusion::TexturePlat::CopyForDelayedRead(this);
  }
  mUID = mData->mNode.mUID;
  Illusion::gTextureD3DResourceInventory.mSyncCopyUIDs[(int)UFG::qAtomicIncrement(&Illusion::gTextureNumSyncUIDs) - 1] = mUID;
}

// File Line: 2273
// RVA: 0xA18A70
void __fastcall Illusion::TexturePlat::CreateClearedMainMemCopy(Illusion::TexturePlat *this)
{
  UFG::qResourceData *mData; // r14
  int v3; // edx
  int v4; // esi
  unsigned int v5; // r8d
  int v6; // eax
  unsigned int v7; // edi
  int v8; // ebx
  unsigned int v9; // esi
  UFG::allocator::free_link *v10; // rax

  mData = this->mTextureD3DResourceHandle.mData;
  v3 = *(&this[-1].mVRamHandle.mBlockID + 1);
  v4 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
  v5 = Illusion::HardwareState::sTextureSize[BYTE4(this[-1].mVRamHandle.mData)];
  v6 = *(&this[-1].mVRamHandle.mBlockID + 2);
  v7 = (v5 * v3) >> 3;
  v8 = v6 * v7;
  if ( !WORD1(this[-1].mTextureD3DResourceHandle.mPrev) )
    v4 = 1;
  v9 = (v5 * v3 * v6 * v4) >> 3;
  v10 = UFG::qMalloc(0x10ui64, "mDeferredContextTextureAccessBuffer", 0i64);
  *(_QWORD *)&mData[1].mDebugName[20] = v10;
  LODWORD(v10[1].mNext) = v7;
  *(_DWORD *)(*(_QWORD *)&mData[1].mDebugName[20] + 12i64) = v8;
  **(_QWORD **)&mData[1].mDebugName[20] = UFG::qMalloc(v9, (const char *)&this[-1].mPad, 0i64);
  UFG::qMemSet(**(void ***)&mData[1].mDebugName[20], 0, v9);
}

// File Line: 2302
// RVA: 0xA226A0
void __fastcall Illusion::TexturePlat::SwitchAliasTexture(
        Illusion::TexturePlat *this,
        Illusion::Texture *new_alias_texture)
{
  UFG::qResourceData *mData; // rsi
  __int64 v4; // rcx
  __int64 v5; // rdx
  char mType; // al
  char mFormat; // r8
  _BYTE *v8; // r8
  int mDepth; // eax
  int v10; // eax
  _BYTE v11[24]; // [rsp+20h] [rbp-28h] BYREF

  mData = this->mTextureD3DResourceHandle.mData;
  v4 = *(_QWORD *)&mData[1].mDebugName[28];
  if ( v4 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
    *(_QWORD *)&mData[1].mDebugName[28] = 0i64;
  }
  v5 = *(_QWORD *)(*(_QWORD *)&new_alias_texture[1].mMipMapBias + 136i64);
  *(_QWORD *)&mData[1].mTypeUID = v5;
  mType = new_alias_texture->mType;
  mFormat = new_alias_texture->mFormat;
  if ( ((mFormat - 16) & 0xFC) != 0 || mFormat == 17 )
  {
    if ( mType == 3 )
    {
      v10 = (int)mData[1].mNode.mChild[1];
      *(_QWORD *)&v11[4] = 5i64;
      v8 = v11;
      *(_DWORD *)v11 = v10;
      *(_QWORD *)&v11[16] = 0i64;
      *(_DWORD *)&v11[20] = new_alias_texture->mDepth;
      *(_DWORD *)&v11[12] = (unsigned __int8)new_alias_texture->mNumMipMaps;
    }
    else
    {
      v8 = 0i64;
    }
  }
  else if ( mType )
  {
    if ( mType != 3 )
      return;
    *(_DWORD *)v11 = 46;
    *(_QWORD *)&v11[4] = 5i64;
    *(_QWORD *)&v11[16] = 0i64;
    mDepth = new_alias_texture->mDepth;
    *(_QWORD *)&v11[12] = 1i64;
    *(_DWORD *)&v11[20] = mDepth;
    v8 = v11;
  }
  else
  {
    *(_DWORD *)v11 = 46;
    *(_QWORD *)&v11[4] = 4i64;
    *(_DWORD *)&v11[12] = 1;
    v8 = v11;
    *(_QWORD *)&v11[16] = 0i64;
  }
  ((void (__fastcall *)(ID3D11Device *, __int64, _BYTE *, char *, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetShader)(
    UFG::gD3D11Device,
    v5,
    v8,
    &mData[1].mDebugName[28],
    *(_QWORD *)v11,
    *(_QWORD *)&v11[8],
    *(_QWORD *)&v11[16]);
}

// File Line: 2395
// RVA: 0xA1E850
void __fastcall Illusion::ITexturePlat::OnLoad(Illusion::ITexturePlat *this)
{
  Illusion::TexturePlat::OnLoad((Illusion::TexturePlat *)&this[208]);
}

// File Line: 2404
// RVA: 0xA1F2E0
void __fastcall Illusion::ITexturePlat::OnUnload(Illusion::ITexturePlat *this)
{
  Illusion::TexturePlat::OnUnload((Illusion::TexturePlat *)&this[208]);
}

// File Line: 2412
// RVA: 0xA1ED20
void __fastcall Illusion::ITexturePlat::OnPreMove(Illusion::ITexturePlat *this)
{
  Illusion::TexturePlat::OnPreMove((Illusion::TexturePlat *)&this[208]);
}

// File Line: 2421
// RVA: 0xA1ECC0
void __fastcall Illusion::ITexturePlat::OnPostMove(Illusion::ITexturePlat *this)
{
  unsigned int v2; // r8d

  *(_DWORD *)&this[88] &= ~0x8000u;
  UFG::qVRAMemoryPools::PostMove((UFG::qVRAMemoryHandle *)&this[248]);
  if ( (*(_DWORD *)&this[88] & 0x1000000) != 0 )
  {
    v2 = *(_DWORD *)&this[176];
    *(_QWORD *)&this[184] = Illusion::Texture::HandleUpdated;
    *(_QWORD *)&this[192] = this;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&this[152], 0xA428072C, v2);
    *(_DWORD *)&this[88] &= ~0x1000000u;
  }
}

// File Line: 2437
// RVA: 0xA1EE40
void __fastcall Illusion::ITexturePlat::OnSetSampler(Illusion::ITexturePlat *this)
{
  Illusion::TexturePlat *v1; // rcx
  Illusion::TextureD3DResource *mData; // rdx

  v1 = (Illusion::TexturePlat *)&this[208];
  mData = (Illusion::TextureD3DResource *)v1->mTextureD3DResourceHandle.mData;
  if ( mData )
    Illusion::TexturePlat::CreateSamplerState(v1, mData);
}

// File Line: 2468
// RVA: 0xA1C560
bool __fastcall Illusion::ITexturePlat::Lock(
        Illusion::ITexturePlat *this,
        Illusion::ITexturePlat::LockType type,
        Illusion::TextureLockInfo *info,
        int mipLevel,
        int faceIndex)
{
  return Illusion::TexturePlat::Lock((Illusion::TexturePlat *)&this[208], type, info, mipLevel, faceIndex);
}

// File Line: 2476
// RVA: 0xA22A70
void __fastcall Illusion::ITexturePlat::Unlock(Illusion::ITexturePlat *this)
{
  Illusion::TexturePlat::Unlock((Illusion::TexturePlat *)&this[208]);
}

// File Line: 2486
// RVA: 0xA19940
void __fastcall Illusion::ITexturePlat::CreateTextureData(Illusion::ITexturePlat *this)
{
  if ( (*(_DWORD *)&this[88] & 0x4000) != 0 )
    Illusion::TextureD3DResourceInventory::ForceUnload(&Illusion::gTextureD3DResourceInventory, *(_DWORD *)&this[24]);
}

// File Line: 2508
// RVA: 0xA22690
void __fastcall Illusion::ITexturePlat::SwitchAliasTexture(
        Illusion::ITexturePlat *this,
        Illusion::Texture *new_alias_texture)
{
  Illusion::TexturePlat::SwitchAliasTexture((Illusion::TexturePlat *)&this[208], new_alias_texture);
}

