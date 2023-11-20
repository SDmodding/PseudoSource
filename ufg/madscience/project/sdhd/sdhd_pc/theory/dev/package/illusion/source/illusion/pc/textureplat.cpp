// File Line: 66
// RVA: 0x15AA7E0
__int64 Illusion::_dynamic_initializer_for__gTextureD3DResourceInventory__()
{
  Illusion::TextureD3DResourceInventory::TextureD3DResourceInventory(&Illusion::gTextureD3DResourceInventory);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gTextureD3DResourceInventory__);
}

// File Line: 133
// RVA: 0xA19890
ID3D11Resource *__fastcall Illusion::CreateTexture(D3D11_TEXTURE2D_DESC *desc2D, int depth, D3D11_SUBRESOURCE_DATA *pSubresourceData)
{
  __int128 v4; // [rsp+20h] [rbp-38h]
  __int64 v5; // [rsp+30h] [rbp-28h]
  _QWORD v6[4]; // [rsp+38h] [rbp-20h]
  __int64 v7; // [rsp+78h] [rbp+20h]

  v7 = 0i64;
  if ( depth <= 1 )
  {
    ((void (__fastcall *)(ID3D11Device *, D3D11_TEXTURE2D_DESC *, D3D11_SUBRESOURCE_DATA *, __int64 *))UFG::gD3D11Device->vfptr->PSSetShader)(
      UFG::gD3D11Device,
      desc2D,
      pSubresourceData,
      &v7);
  }
  else
  {
    *(_QWORD *)((char *)&v4 + 4) = 0i64;
    *(__int128 *)((char *)&v4 + 12) = 0ui64;
    *(_QWORD *)((char *)v6 + 4) = 0i64;
    *(_QWORD *)&v4 = desc2D->Width;
    DWORD1(v4) = desc2D->Height;
    *((_QWORD *)&v4 + 1) = __PAIR__(desc2D->MipLevels, depth);
    v5 = *(unsigned int *)desc2D->Format;
    *(__int64 *)((char *)&v5 + 4) = *(_QWORD *)&desc2D->Usage;
    *(_QWORD *)((char *)v6 + 4) = desc2D->CPUAccessFlags;
    LODWORD(v6[1]) = desc2D->MiscFlags;
    ((void (__fastcall *)(ID3D11Device *, __int128 *, D3D11_SUBRESOURCE_DATA *, __int64 *, _QWORD, _QWORD, __int64, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->PSSetSamplers)(
      UFG::gD3D11Device,
      &v4,
      pSubresourceData,
      &v7,
      v4,
      *((_QWORD *)&v4 + 1),
      v5,
      v6[0],
      v6[1]);
  }
  return (ID3D11Resource *)v7;
}

// File Line: 596
// RVA: 0xA19EC0
void __fastcall Illusion::TextureLoader::DoCreationTask(Illusion::TextureLoader *this)
{
  Illusion::TextureLoader *v1; // rsi
  unsigned int v2; // ebx
  signed __int64 v3; // rdi
  Illusion::TextureQueueNode *v4; // rdx
  __int64 v5; // rcx

  v1 = this;
  v2 = 0;
  v3 = 48i64;
  do
  {
    v4 = v1->mTextureNode;
    v5 = *(__int64 *)((char *)&v4->mNode.mParent + v3);
    if ( v2 )
    {
      if ( !v5 )
        return;
      Illusion::TexturePlat::AcquireResources((Illusion::TexturePlat *)(v5 + 208), v4->mResource);
    }
    else
    {
      Illusion::TexturePlat::CreateResources((Illusion::TexturePlat *)(v5 + 208), v4->mResource);
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
  Illusion::TextureLoader *v1; // rsi
  unsigned int v2; // ebx
  signed __int64 v3; // rdi
  __int64 v4; // rcx

  v1 = this;
  UFG::qResourceInventory::Add(
    (UFG::qResourceInventory *)&Illusion::gTextureD3DResourceInventory.vfptr,
    (UFG::qResourceData *)&this->mTextureNode->mResource->mNode);
  v2 = 0;
  v3 = 48i64;
  do
  {
    v4 = *(__int64 *)((char *)&v1->mTextureNode->mNode.mParent + v3);
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
  signed int v1; // eax
  UFG::qResourceWarehouse *v2; // rax
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v3; // rdi
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
    v3 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::qResourceWarehouse::GetInventory(
                                                                                     v2,
                                                                                     0x8B43FABF)->mResourceDatas;
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v3);
          i;
          i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)v3, &i->mRoot) )
    {
      v5 = (Illusion::TextureD3DResource *)i[4].mRoot.mChild[0];
      if ( v5 )
        Illusion::TexturePlat::CreateSamplerState((Illusion::TexturePlat *)&i[2].mCount, v5);
    }
  }
}

// File Line: 665
// RVA: 0xA15DC0
void __fastcall Illusion::TextureD3DResourceInventory::TextureD3DResourceInventory(Illusion::TextureD3DResourceInventory *this)
{
  Illusion::TextureD3DResourceInventory *v1; // rbx

  v1 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "TextureD3DResourceInventory",
    0xEF77C5F7,
    0x501B8E62u,
    0x3218EEB7u,
    0);
  v1->vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::TextureD3DResourceInventory::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mOnLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mOnUnloadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mHighPriorityLoadQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mLoadingQueue.mTree);
}

// File Line: 669
// RVA: 0xA1EE60
char __fastcall Illusion::TextureD3DResourceInventory::OnTextureLoad(Illusion::TextureD3DResourceInventory *this, Illusion::Texture *texture)
{
  Illusion::Texture *v2; // rbp
  Illusion::TextureD3DResourceInventory *v3; // r14
  unsigned int v4; // edx
  Illusion::TextureD3DResource *v5; // rbx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // r15
  UFG::qBaseNodeRB **v8; // r8
  signed int v9; // ecx
  Illusion::Texture **v10; // rdx
  int v11; // ecx
  UFG::qBaseNodeRB *v12; // rcx
  UFG::qBaseNodeRB **v13; // rdi
  UFG::qBaseNodeRB *v14; // rdx
  UFG::qBaseNodeRB *v15; // rax
  Illusion::TextureD3DResource *v16; // rax
  unsigned int v17; // edx
  UFG::qBaseTreeRB *v18; // rax
  UFG::qBaseNodeRB **v19; // rcx
  UFG::allocator::free_link *v20; // rax
  Illusion::TextureD3DResource *v21; // rax
  Illusion::TextureD3DResource *v22; // rdi
  UFG::allocator::free_link *v23; // rax
  Illusion::TextureD3DResource *v24; // rax
  UFG::allocator::free_link *v26; // rax
  Illusion::TextureD3DResource *v27; // rax

  v2 = texture;
  v3 = this;
  v4 = texture->mNode.mUID;
  v5 = 0i64;
  if ( v4 )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, v4);
    v7 = v6;
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
          goto LABEL_9;
      }
      v11 = v9 + 1;
      if ( v11 < 32 )
        qmemcpy(&v8[v11 - 1], &v8[v11], 8i64 * (unsigned int)(32 - v11));
LABEL_9:
      if ( !*v8 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnUnloadQueue,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
        v12 = v7[4].mRoot.mChild[1];
        if ( v12 )
        {
          v13 = v12->mChild;
          v14 = v12->mChild[0];
          v15 = v12->mChild[1];
          v14->mChild[0] = v15;
          v15->mParent = v14;
          *v13 = (UFG::qBaseNodeRB *)v13;
          v13[1] = (UFG::qBaseNodeRB *)v13;
          operator delete[](v12);
          v7[4].mRoot.mChild[1] = 0i64;
        }
        operator delete[](v7);
      }
    }
  }
  if ( v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v2->mNode.mUID) )
  {
    v16 = (Illusion::TextureD3DResource *)v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v2->mNode.mUID);
    Illusion::TexturePlat::AcquireResources((Illusion::TexturePlat *)v2[1].mNode.mChild, v16);
    return 1;
  }
  if ( v2->mFlags & 0x26CC00 )
  {
    v26 = UFG::qMalloc(0xF8ui64, "TextureD3DResource", 0x800ui64);
    if ( v26 )
    {
      Illusion::TextureD3DResource::TextureD3DResource(
        (Illusion::TextureD3DResource *)v26,
        v2->mNode.mUID,
        v2->mDebugName);
      v5 = v27;
    }
    Illusion::TexturePlat::CreateResources((Illusion::TexturePlat *)v2[1].mNode.mChild, v5);
    v3->vfptr->Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v5->mNode);
    return 1;
  }
  v17 = v2->mNode.mUID;
  if ( v17 && (v18 = UFG::qBaseTreeRB::Get(&v3->mOnLoadQueue.mTree, v17)) != 0i64 )
  {
    v19 = &v18->mNULL.mChild[1];
    while ( *v19 )
    {
      LODWORD(v5) = (_DWORD)v5 + 1;
      ++v19;
      if ( (signed int)v5 >= 32 )
        goto LABEL_23;
    }
    v18->mNULL.mChild[(signed int)v5 + 1] = (UFG::qBaseNodeRB *)v2;
LABEL_23:
    v18->mNULL.mChild[0] = (UFG::qBaseNodeRB *)UFG::qGetTicks();
  }
  else
  {
    v20 = UFG::qMalloc(0xF8ui64, "TextureD3DResource", 0x800ui64);
    if ( v20 )
    {
      Illusion::TextureD3DResource::TextureD3DResource(
        (Illusion::TextureD3DResource *)v20,
        v2->mNode.mUID,
        v2->mDebugName);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    v23 = UFG::qMalloc(0x138ui64, "LoadTextureQueueNode", 0i64);
    if ( v23 )
    {
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v23, v22, v2);
      v5 = v24;
    }
    UFG::qBaseTreeRB::Add(&v3->mOnLoadQueue.mTree, &v5->mNode);
  }
  return 0;
}eueNode *)v23, v22, v2);
      v5 =

// File Line: 752
// RVA: 0xA1F0B0
void __fastcall Illusion::TextureD3DResourceInventory::OnTextureUnload(Illusion::TextureD3DResourceInventory *this, Illusion::Texture *texture)
{
  Illusion::Texture *v2; // rdi
  Illusion::TextureD3DResourceInventory *v3; // rsi
  Illusion::TextureD3DResource *v4; // rbp
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // rbx
  UFG::qBaseNodeRB **v8; // r8
  signed int v9; // eax
  Illusion::Texture **v10; // rcx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rbx
  Illusion::AsyncD3DCreationTask *v14; // rcx
  unsigned int v15; // edx
  UFG::qBaseTreeRB *v16; // rax
  signed __int64 v17; // rdx
  signed int v18; // eax
  _QWORD *v19; // rcx
  UFG::allocator::free_link *v20; // rax

  v2 = texture;
  v3 = this;
  v4 = (Illusion::TextureD3DResource *)this->vfptr->Get((UFG::qResourceInventory *)this, texture->mNode.mUID);
  if ( !v4 )
  {
    v5 = v2->mNode.mUID;
    if ( v5 )
    {
      v6 = UFG::qBaseTreeRB::Get(&v3->mOnLoadQueue.mTree, v5);
      v7 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6;
      if ( v6 )
      {
        v8 = &v6->mNULL.mChild[1];
        v9 = 0;
        v10 = (Illusion::Texture **)v8;
        while ( *v10 != v2 )
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
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnLoadQueue,
            v7);
          Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v7, 1);
        }
        return;
      }
    }
    v11 = v2->mNode.mUID;
    if ( !v11 )
      return;
    v12 = UFG::qBaseTreeRB::Get(&v3->mLoadingQueue.mTree, v11);
    v13 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v12;
    if ( !v12 )
      return;
    v14 = (Illusion::AsyncD3DCreationTask *)v12[4].mRoot.mChild[1];
    if ( v14 )
      Illusion::AsyncD3DCreationTask::FinalizeAsyncCreationTask(v14);
    v4 = (Illusion::TextureD3DResource *)v13[1].mParent;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mLoadingQueue,
      v13);
    Illusion::TextureQueueNode::`scalar deleting destructor((Illusion::TextureQueueNode *)v13, 1);
  }
  v15 = v2->mNode.mUID;
  if ( v15 && (v16 = UFG::qBaseTreeRB::Get(&v3->mOnUnloadQueue.mTree, v15)) != 0i64 )
  {
    v17 = (signed __int64)&v16->mNULL.mChild[1];
    v18 = 0;
    v19 = (_QWORD *)v17;
    while ( *v19 )
    {
      ++v18;
      ++v19;
      if ( v18 >= 32 )
        return;
    }
    *(_QWORD *)(v17 + 8i64 * v18) = v2;
  }
  else
  {
    v20 = UFG::qMalloc(0x138ui64, "UnloadTextureQueueNode", 0i64);
    if ( v20 )
      Illusion::TextureQueueNode::TextureQueueNode((Illusion::TextureQueueNode *)v20, v4, v2);
    UFG::qBaseTreeRB::Add(&v3->mOnUnloadQueue.mTree, (UFG::qBaseNodeRB *)v20);
  }
}

// File Line: 822
// RVA: 0xA21FA0
void __fastcall Illusion::TextureD3DResourceInventory::SetHighPriority(Illusion::TextureD3DResourceInventory *this, unsigned int uid)
{
  Illusion::TextureD3DResourceInventory *v2; // rbx
  unsigned int v3; // edi
  signed int v4; // eax

  v2 = this;
  v3 = uid;
  v4 = (unsigned __int64)UFG::qAtomicIncrement(&Illusion::gTextureNumHighPriorityUIDs) - 1;
  if ( v4 > 4095 )
    v4 = 4095;
  v2->mHighPriorityUIDs[v4] = v3;
}

// File Line: 831
// RVA: 0xA1F900
void __fastcall Illusion::TextureD3DResourceInventory::ProcessQueuedLoads(Illusion::TextureD3DResourceInventory *this, bool bBlocking)
{
  bool v2; // r12
  Illusion::TextureD3DResourceInventory *v3; // r15
  float v4; // xmm0_4
  unsigned int *v5; // rdi
  __int64 v6; // rbp
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseNodeRB *v8; // rbx
  Render::SkinningCacheNode *v9; // rsi
  UFG::allocator::free_link *v10; // rax
  Illusion::AsyncD3DCreationTask *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  unsigned int v13; // edi
  $CA91B2824B6F331601351B2AC7FEF5D9 *v14; // r14
  UFG::qBaseNodeVariableRB<unsigned __int64> *v15; // rbx
  int v16; // edx
  char v17; // al
  bool v18; // r8
  char v19; // cl
  int v20; // eax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  __int64 v23; // rdx
  _QWORD *v24; // rax
  int i; // er14
  Render::SkinningCacheNode *v26; // rbp
  UFG::allocator::free_link *v27; // rax
  Illusion::AsyncD3DCreationTask *v28; // rcx
  UFG::allocator::free_link *v29; // rax
  unsigned int v30; // edi
  $CA91B2824B6F331601351B2AC7FEF5D9 *v31; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v32; // rbx
  int v33; // edx
  char v34; // al
  bool v35; // r8
  char v36; // cl
  int v37; // eax
  _QWORD *v38; // rcx
  _QWORD *v39; // r8
  __int64 v40; // rdx
  _QWORD *v41; // rax
  bool v42; // [rsp+78h] [rbp+10h]

  v42 = bBlocking;
  v2 = bBlocking;
  v3 = this;
  v4 = (float)Illusion::gTextureNumHighPriorityUIDs;
  if ( (float)Illusion::gTextureNumHighPriorityUIDs >= 4096.0 )
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
  _InterlockedExchange(&Illusion::gTextureNumHighPriorityUIDs, 0);
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mHighPriorityLoadQueue) )
  {
    v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mHighPriorityLoadQueue);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mHighPriorityLoadQueue,
      &v9->mNode);
    if ( !Illusion::gEnableAsyncTextureLoading || v2 )
    {
      v13 = 0;
      v14 = &v9[1].mNode.8;
      do
      {
        v15 = v14->mChild[0];
        if ( v13 )
        {
          if ( !v15 )
            break;
          UFG::qAtomicIncrement((volatile int *)&v9->mCachedBufferPtr[1].mData);
          v15[7].mChild[1] = 0i64;
          *(unsigned __int64 *)((char *)&v15[6].mUID + 4) = 0i64;
          v16 = v15[2].mUID;
          v17 = (LODWORD(v15[2].mUID) >> 17) & 1;
          v18 = _bittest(&v16, 0x12u) || v17;
          if ( _bittest(&v16, 0xAu) || v17 )
          {
            v19 = 1;
            if ( v17 )
              LODWORD(v15[2].mUID) = v16 | 0x400000;
          }
          else
          {
            v19 = 0;
          }
          if ( v18 )
          {
            v20 = 1;
            if ( v19 )
              v20 = 3;
          }
          else
          {
            v20 = v19 != 0 ? 2 : 0;
          }
          LODWORD(v15[6].mUID) = v20;
          v15[7].mChild[0] = 0i64;
        }
        else
        {
          Illusion::TexturePlat::CreateResources(
            (Illusion::TexturePlat *)&v15[6].mChild1,
            (Illusion::TextureD3DResource *)v9->mCachedBufferPtr);
        }
        if ( v15[5].mChild[0] )
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v15[4].mUID);
        ++v13;
        v14 = ($CA91B2824B6F331601351B2AC7FEF5D9 *)((char *)v14 + 8);
      }
      while ( v13 < 0x20 );
      UFG::qResourceInventory::Add(
        (UFG::qResourceInventory *)&Illusion::gTextureD3DResourceInventory.vfptr,
        (UFG::qResourceData *)&v9->mCachedBufferPtr->mNode);
      v21 = (_QWORD *)v9[7].mNode.mUID;
      v2 = v42;
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
        v11[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)v9;
      }
      else
      {
        v11 = 0i64;
      }
      v9[7].mNode.mUID = (unsigned __int64)v11;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v11);
    }
  }
  for ( i = 0;
        (i < Illusion::gMaxTextureLoadsPerFrame || v2)
     && UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mOnLoadQueue);
        ++i )
  {
    v26 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mOnLoadQueue);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnLoadQueue,
      &v26->mNode);
    if ( !Illusion::gEnableAsyncTextureLoading || v2 )
    {
      v30 = 0;
      v31 = &v26[1].mNode.8;
      do
      {
        v32 = v31->mChild[0];
        if ( v30 )
        {
          if ( !v32 )
            break;
          UFG::qAtomicIncrement((volatile int *)&v26->mCachedBufferPtr[1].mData);
          v32[7].mChild[1] = 0i64;
          *(unsigned __int64 *)((char *)&v32[6].mUID + 4) = 0i64;
          v33 = v32[2].mUID;
          v34 = (LODWORD(v32[2].mUID) >> 17) & 1;
          v35 = _bittest(&v33, 0x12u) || v34;
          if ( _bittest(&v33, 0xAu) || v34 )
          {
            v36 = 1;
            if ( v34 )
              LODWORD(v32[2].mUID) = v33 | 0x400000;
          }
          else
          {
            v36 = 0;
          }
          if ( v35 )
          {
            v37 = 1;
            if ( v36 )
              v37 = 3;
          }
          else
          {
            v37 = v36 != 0 ? 2 : 0;
          }
          LODWORD(v32[6].mUID) = v37;
          v32[7].mChild[0] = 0i64;
        }
        else
        {
          Illusion::TexturePlat::CreateResources(
            (Illusion::TexturePlat *)&v32[6].mChild1,
            (Illusion::TextureD3DResource *)v26->mCachedBufferPtr);
        }
        if ( v32[5].mChild[0] )
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v32[4].mUID);
        ++v30;
        v31 = ($CA91B2824B6F331601351B2AC7FEF5D9 *)((char *)v31 + 8);
      }
      while ( v30 < 0x20 );
      UFG::qResourceInventory::Add(
        (UFG::qResourceInventory *)&Illusion::gTextureD3DResourceInventory.vfptr,
        (UFG::qResourceData *)&v26->mCachedBufferPtr->mNode);
      v38 = (_QWORD *)v26[7].mNode.mUID;
      v2 = v42;
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
      v27 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      v28 = (Illusion::AsyncD3DCreationTask *)v27;
      if ( v27 )
      {
        v29 = v27 + 1;
        v29->mNext = v29;
        v29[1].mNext = v29;
        v28->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::AsyncD3DCreationTask::`vftable;
        v28->mTask = 0i64;
        v28->vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)&Illusion::TextureLoader::`vftable;
        v28[1].vfptr = (Illusion::AsyncD3DCreationTaskVtbl *)v26;
      }
      else
      {
        v28 = 0i64;
      }
      v26[7].mNode.mUID = (unsigned __int64)v28;
      Illusion::AsyncD3DCreationTask::BeginAsyncCreationTask(v28);
    }
  }
}

// File Line: 965
// RVA: 0xA228B0
void __fastcall Illusion::TextureD3DResourceInventory::SyncLoadTasks(Illusion::TextureD3DResourceInventory *this)
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

// File Line: 980
// RVA: 0xA1FF90
void __fastcall Illusion::TextureD3DResourceInventory::ProcessQueuedUnLoads(Illusion::TextureD3DResourceInventory *this)
{
  Illusion::TextureD3DResourceInventory *v1; // r14
  Render::SkinningCacheNode *v2; // rbx
  Illusion::TextureD3DResource *v3; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> **v5; // rcx
  signed __int64 v6; // r8
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  __int64 v9; // rdx
  _QWORD *v10; // rax

  v1 = this;
  while ( UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mOnUnloadQueue) )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mOnUnloadQueue);
    v3 = (Illusion::TextureD3DResource *)v2->mCachedBufferPtr;
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
      if ( --v3->mRefCount <= 0 )
      {
        v1->vfptr->Remove((UFG::qResourceInventory *)&v1->vfptr, (UFG::qResourceData *)&v3->mNode);
        Illusion::TextureD3DResource::~TextureD3DResource(v3);
        operator delete[](v3);
        UFG::qMemSet(qword_14245AF48, 0, 0x40000u);
        break;
      }
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mOnUnloadQueue,
      &v2->mNode);
    v7 = (_QWORD *)v2[7].mNode.mUID;
    if ( v7 )
    {
      v8 = v7 + 1;
      v9 = v7[1];
      v10 = (_QWORD *)v7[2];
      *(_QWORD *)(v9 + 8) = v10;
      *v10 = v9;
      *v8 = v8;
      v8[1] = v8;
      operator delete[](v7);
      v2[7].mNode.mUID = 0i64;
    }
    operator delete[](v2);
  }
}

// File Line: 1033
// RVA: 0xA200D0
void __fastcall Illusion::TextureD3DResourceInventory::ProcessSyncCopies(Illusion::TextureD3DResourceInventory *this)
{
  Illusion::TextureD3DResourceInventory *v1; // r15
  UFG::qResourceWarehouse *v2; // rax
  volatile int v3; // esi
  unsigned int *v4; // r14
  __int64 v5; // rbx
  UFG::qResourceData *v6; // rax
  Illusion::TexturePlat *v7; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rdi
  char *v9; // rdx
  Illusion::TextureLockInfo info; // [rsp+38h] [rbp-40h]
  Illusion::TextureLockInfo v11; // [rsp+48h] [rbp-30h]

  v1 = this;
  if ( !(_S1_32 & 1) )
  {
    _S1_32 |= 1u;
    v2 = UFG::qResourceWarehouse::Instance();
    texInventory_3 = UFG::qResourceWarehouse::GetInventory(v2, 0x8B43FABF);
  }
  v3 = 0;
  if ( Illusion::gTextureNumSyncUIDs > 0 )
  {
    v4 = v1->mSyncCopyUIDs;
    while ( 1 )
    {
      v5 = (__int64)v1->vfptr->Get((UFG::qResourceInventory *)&v1->vfptr, *v4);
      v6 = texInventory_3->vfptr->Get(texInventory_3, *v4);
      if ( !v5 || !v6 )
        goto LABEL_16;
      v7 = (Illusion::TexturePlat *)&v6[2].mResourceHandles;
      v8 = v6[3].mResourceHandles.mNode.mPrev;
      if ( !v8[10].mPrev )
        Illusion::TexturePlat::CreateClearedMainMemCopy((Illusion::TexturePlat *)&v6[2].mResourceHandles);
      if ( !LODWORD(v8[9].mNext) )
        break;
      info.mData = 0i64;
      *(_QWORD *)&info.mLinePitch = 0i64;
      if ( Illusion::TexturePlat::Lock(v7, LOCK_OVERWRITE, &info, 0, 0) )
      {
        v9 = info.mData;
LABEL_15:
        UFG::qMemCopy(v8[10].mPrev->mPrev, v9, HIDWORD(v8[10].mPrev->mNext));
        Illusion::TexturePlat::Unlock(v7);
      }
LABEL_16:
      ++v3;
      ++v4;
      if ( v3 >= Illusion::gTextureNumSyncUIDs )
        goto LABEL_17;
    }
    if ( !v8[12].mNext )
      goto LABEL_16;
    v11.mData = 0i64;
    *(_QWORD *)&v11.mLinePitch = 0i64;
    if ( !Illusion::TexturePlat::Lock(v7, 0, &v11, 0, 0) )
      goto LABEL_16;
    v9 = v11.mData;
    goto LABEL_15;
  }
LABEL_17:
  Illusion::gTextureNumSyncUIDs = 0;
}

// File Line: 1051
// RVA: 0xA1AA60
void __fastcall Illusion::TextureD3DResourceInventory::ForceLoad(Illusion::TextureD3DResourceInventory *this, unsigned int uid)
{
  unsigned int v2; // ebx
  Illusion::TextureD3DResourceInventory *v3; // rsi
  UFG::qBaseTreeVariableRB<unsigned __int64> *v4; // r14
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rdi
  UFG::qBaseNodeRB *v7; // rbx
  unsigned int *v8; // rdx
  signed __int64 v9; // r8
  UFG::qBaseNodeRB *v10; // rbx
  unsigned int *v11; // rax
  signed __int64 v12; // rdx
  unsigned int v13; // edx
  char v14; // al
  bool v15; // r8
  char v16; // cl
  int v17; // eax
  UFG::qBaseNodeRB *v18; // rcx
  UFG::qBaseNodeRB **v19; // r8
  UFG::qBaseNodeRB *v20; // rdx
  UFG::qBaseNodeRB *v21; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v22; // rcx
  UFG::qBaseTreeRB *v23; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v24; // rbx
  UFG::qBaseNodeRB *v25; // rdi
  UFG::qTask *v26; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v27; // rcx
  $CA91B2824B6F331601351B2AC7FEF5D9 *v28; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> *v29; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v30; // rax

  if ( uid )
  {
    v2 = uid;
    v3 = this;
    v4 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mOnLoadQueue;
    v5 = UFG::qBaseTreeRB::Get(&this->mOnLoadQueue.mTree, uid);
    v6 = v5;
    if ( v5 )
    {
      v7 = v5->mNULL.mChild[1];
      v8 = &v5->mNULL.mUID;
      v9 = 31i64;
      do
      {
        *((_QWORD *)v8 - 1) = *(_QWORD *)v8;
        v8 += 2;
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
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v7[4].mUID);
      }
      while ( 1 )
      {
        v10 = v6->mNULL.mChild[1];
        v11 = &v6->mNULL.mUID;
        v12 = 31i64;
        do
        {
          *((_QWORD *)v11 - 1) = *(_QWORD *)v11;
          v11 += 2;
          --v12;
        }
        while ( v12 );
        v6[4].mRoot.mChild[0] = 0i64;
        if ( !v10 )
          break;
        UFG::qAtomicIncrement((volatile int *)&v6->mNULL.mParent[7].mChild[1]);
        v10[7].mChild[1] = 0i64;
        *(_QWORD *)(&v10[6].mUID + 1) = 0i64;
        v13 = v10[2].mUID;
        v14 = (v10[2].mUID >> 17) & 1;
        v15 = _bittest((const signed int *)&v13, 0x12u) || v14;
        if ( _bittest((const signed int *)&v13, 0xAu) || v14 )
        {
          v16 = 1;
          if ( v14 )
            v10[2].mUID = v13 | 0x400000;
        }
        else
        {
          v16 = 0;
        }
        if ( v15 )
        {
          v17 = 1;
          if ( v16 )
            v17 = 3;
        }
        else
        {
          v17 = v16 != 0 ? 2 : 0;
        }
        v10[6].mUID = v17;
        v10[7].mChild[0] = 0i64;
        if ( v10[5].mChild[0] )
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v10[4].mUID);
      }
      UFG::qResourceInventory::Add(
        (UFG::qResourceInventory *)&Illusion::gTextureD3DResourceInventory.vfptr,
        (UFG::qResourceData *)v6->mNULL.mParent);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v4, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
      v18 = v6[4].mRoot.mChild[1];
      if ( v18 )
      {
        v19 = v18->mChild;
        v20 = v18->mChild[0];
        v21 = v18->mChild[1];
        v20->mChild[0] = v21;
        v21->mParent = v20;
        *v19 = (UFG::qBaseNodeRB *)v19;
        v19[1] = (UFG::qBaseNodeRB *)v19;
        operator delete[](v18);
        v6[4].mRoot.mChild[1] = 0i64;
      }
      v22 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6;
    }
    else
    {
      v23 = UFG::qBaseTreeRB::Get(&v3->mLoadingQueue.mTree, v2);
      v24 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v23;
      if ( !v23 )
        return;
      v25 = v23[4].mRoot.mChild[1];
      if ( v25 )
      {
        v26 = *(UFG::qTask **)&v25->mUID;
        if ( v26 )
        {
          UFG::qTaskManager::Sync(&UFG::gTaskManager, v26);
          *(_QWORD *)&v25->mUID = 0i64;
          ((void (__fastcall *)(UFG::qBaseNodeRB *))v25->mParent->mChild[0])(v25);
        }
      }
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mLoadingQueue,
        v24);
      v27 = v24[9].mChild[1];
      if ( v27 )
      {
        v28 = &v27->8;
        v29 = v27->mChild[0];
        v30 = v27->mChild[1];
        v29->mChild[0] = v30;
        v30->mParent = v29;
        v28->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v28;
        v28->mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v28;
        operator delete[](v27);
        v24[9].mChild[1] = 0i64;
      }
      v22 = v24;
    }
    operator delete[](v22);
  }
}

// File Line: 1117
// RVA: 0xA1ACE0
void __fastcall Illusion::TextureD3DResourceInventory::ForceUnload(Illusion::TextureD3DResourceInventory *this, unsigned int uid)
{
  unsigned int v2; // edi
  Illusion::TextureD3DResourceInventory *v3; // rsi
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rbx
  Illusion::TextureD3DResource *v6; // rdi
  UFG::qBaseNodeRB *v7; // r8
  unsigned int *v8; // rcx
  signed __int64 v9; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v10; // rcx
  $CA91B2824B6F331601351B2AC7FEF5D9 *v11; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> *v12; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rax
  __int64 v14; // rax

  v2 = uid;
  v3 = this;
  if ( uid
    && (v4 = UFG::qBaseTreeRB::Get(&this->mOnUnloadQueue.mTree, uid),
        (v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v4) != 0i64) )
  {
    v6 = (Illusion::TextureD3DResource *)v4->mNULL.mParent;
    while ( 1 )
    {
      v7 = v4->mNULL.mChild[1];
      v8 = &v4->mNULL.mUID;
      v9 = 31i64;
      do
      {
        *((_QWORD *)v8 - 1) = *(_QWORD *)v8;
        v8 += 2;
        --v9;
      }
      while ( v9 );
      v4[4].mRoot.mChild[0] = 0i64;
      if ( !v7 )
        break;
      if ( --v6->mRefCount <= 0 )
      {
        v3->vfptr->Remove((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v6->mNode);
        Illusion::TextureD3DResource::~TextureD3DResource(v6);
        operator delete[](v6);
        break;
      }
    }
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mOnUnloadQueue,
      v5);
    v10 = v5[9].mChild[1];
    if ( v10 )
    {
      v11 = &v10->8;
      v12 = v10->mChild[0];
      v13 = v10->mChild[1];
      v12->mChild[0] = v13;
      v13->mParent = v12;
      v11->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v11;
      v11->mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v11;
      operator delete[](v10);
      v5[9].mChild[1] = 0i64;
    }
  }
  else
  {
    v14 = (__int64)v3->vfptr->Get((UFG::qResourceInventory *)&v3->vfptr, v2);
    v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v14;
    if ( !v14 )
      return;
    v3->vfptr->Remove((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)v14);
    Illusion::TextureD3DResource::~TextureD3DResource((Illusion::TextureD3DResource *)v5);
  }
  operator delete[](v5);
}

// File Line: 1169
// RVA: 0xA16B40
void __fastcall Illusion::TextureD3DResource::~TextureD3DResource(Illusion::TextureD3DResource *this)
{
  Illusion::TextureD3DResource *v1; // rbx
  Illusion::TextureLockInfo *v2; // rcx
  ID3D11SamplerState *v3; // rcx
  ID3D11ShaderResourceView *v4; // rcx
  unsigned int i; // edi
  signed __int64 v6; // rsi
  ID3D11ShaderResourceView *v7; // rcx
  ID3D11ShaderResourceView **v8; // rcx
  ID3D11Resource *v9; // rcx
  ID3D11Resource *v10; // rcx
  ID3D11Resource **v11; // rdi
  signed __int64 v12; // rsi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v13; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v15; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v17; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v18; // rax

  v1 = this;
  v2 = this->mDeferredContextTextureAccessBuffer;
  if ( v2 )
  {
    operator delete[](v2->mData);
    operator delete[](v1->mDeferredContextTextureAccessBuffer);
    v1->mDeferredContextTextureAccessBuffer = 0i64;
  }
  v3 = v1->mSamplerState;
  if ( v3 )
  {
    ((void (__cdecl *)(ID3D11SamplerState *))v3->vfptr->Release)(v3);
    v1->mSamplerState = 0i64;
  }
  v4 = v1->mShaderResourceView;
  if ( v4 )
  {
    ((void (__cdecl *)(ID3D11ShaderResourceView *))v4->vfptr->Release)(v4);
    v1->mShaderResourceView = 0i64;
  }
  if ( v1->mShaderResourceViewMips )
  {
    for ( i = 0; i < v1->mNumberMipViews; ++i )
    {
      v6 = i;
      v7 = v1->mShaderResourceViewMips[v6];
      if ( v7 )
      {
        ((void (__cdecl *)(ID3D11ShaderResourceView *))v7->vfptr->Release)(v7);
        v1->mShaderResourceViewMips[v6] = 0i64;
      }
    }
  }
  v8 = v1->mShaderResourceViewMips;
  if ( v8 )
  {
    operator delete[](v8);
    v1->mShaderResourceViewMips = 0i64;
  }
  v9 = v1->mStagingResource;
  if ( v9 )
  {
    ((void (__cdecl *)(ID3D11Resource *))v9->vfptr->Release)(v9);
    v1->mStagingResource = 0i64;
  }
  if ( !v1->mAliased )
  {
    v10 = v1->mGpuResource;
    if ( v10 )
    {
      ((void (__cdecl *)(ID3D11Resource *))v10->vfptr->Release)(v10);
      v1->mGpuResource = 0i64;
    }
  }
  v11 = v1->mDelayedReadCopy;
  v12 = 5i64;
  do
  {
    if ( *v11 )
    {
      ((void (__cdecl *)(ID3D11Resource *))(*v11)->vfptr->Release)(*v11);
      *v11 = 0i64;
    }
    ++v11;
    --v12;
  }
  while ( v12 );
  v13 = &v1->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
        j != (UFG::qResourceHandle *)v13;
        j = (UFG::qResourceHandle *)v13->mNode.mNext )
  {
    v15 = j->mPrev;
    v16 = j->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    j->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&j->mPrev;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v17 = v13->mNode.mPrev;
  v18 = v13->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
}

// File Line: 1224
// RVA: 0xA1EB80
void __fastcall Illusion::TexturePlat::OnLoad(Illusion::TexturePlat *this)
{
  Illusion::TexturePlat *v1; // rdi
  char *v2; // rsi
  AMD_HD3D *v3; // rbp
  int v4; // eax
  char *v5; // rax
  unsigned int v6; // ebx
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v1 = this;
  v2 = &this[-2].mPadding[40];
  v3 = 0i64;
  this->mInitialImageData = 0i64;
  v4 = (int)this[-1].mVRamHandle.mData;
  if ( _bittest(&v4, 0xFu) )
  {
    this->mInitialImageData = this->mVRamHandle.mData;
  }
  else if ( !_bittest(&v4, 0xEu) )
  {
    Illusion::TexturePlat::TexturePlat(this);
    *((_QWORD *)v2 + 23) = Illusion::Texture::HandleUpdated;
    *((_QWORD *)v2 + 24) = v2;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v2 + 152), 0xA428072C, *((_DWORD *)v2 + 44));
    v5 = UFG::qResourceFileHandle::GetFileData((UFG::qResourceFileHandle *)(v2 + 152), *((_DWORD *)v2 + 32));
    v1->mInitialImageData = v5;
    if ( !(*((_DWORD *)v2 + 22) & 0x20000) )
      UFG::qVRAMemoryPools::BindWithinContainer(&v1->mVRamHandle, v5, *((_DWORD *)v2 + 30), v2 + 52);
  }
  if ( Illusion::TextureD3DResourceInventory::OnTextureLoad(
         &Illusion::gTextureD3DResourceInventory,
         (Illusion::Texture *)v2)
    && *((_QWORD *)v2 + 21) )
  {
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)(v2 + 152));
  }
  v6 = *(_DWORD *)&v1[-2].mPadding[64];
  v7 = `UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0xEF77C5F7);
    `UFG::qGetResourceInventory<Illusion::TextureD3DResource>::`2::result = v7;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mTextureD3DResourceHandle.mPrev, 0xEF77C5F7, v6, v7);
  if ( v1->mTextureUserPlat.mOffset )
    v3 = (AMD_HD3D *)((char *)v1 + v1->mTextureUserPlat.mOffset);
  _(v3);
}

// File Line: 1298
// RVA: 0xA1F380
void __fastcall Illusion::TexturePlat::OnUnload(Illusion::TexturePlat *this)
{
  Illusion::TexturePlat *v1; // rbx
  AMD_HD3D *v2; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  Illusion::TextureD3DResourceHandle *v5; // rdx

  v1 = this;
  if ( !((_QWORD)this[-1].mVRamHandle.mData & 0x8000) )
  {
    if ( this->mTextureUserPlat.mOffset )
      v2 = (AMD_HD3D *)((char *)this + this->mTextureUserPlat.mOffset);
    else
      v2 = 0i64;
    _(v2);
    Illusion::TextureD3DResourceInventory::OnTextureUnload(
      &Illusion::gTextureD3DResourceInventory,
      (Illusion::Texture *)&v1[-2].mPadding[40]);
    v3 = v1->mTextureD3DResourceHandle.mPrev;
    v4 = v1->mTextureD3DResourceHandle.mNext;
    v5 = &v1->mTextureD3DResourceHandle;
    v3->mNext = v4;
    v4->mPrev = v3;
    v5->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v5->mPrev;
    if ( v1->mVRamHandle.mData )
      UFG::qVRAMemoryPools::Free(&v1->mVRamHandle, 0);
    if ( *(_QWORD *)&v1[-1].mPadding[32] )
      UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1[-1].mPadding[16]);
  }
}

// File Line: 1321
// RVA: 0xA17000
void __fastcall Illusion::TexturePlat::AcquireResources(Illusion::TexturePlat *this, Illusion::TextureD3DResource *textureD3D)
{
  Illusion::TexturePlat *v2; // rbx
  int v3; // edx
  char v4; // al
  bool v5; // r8
  char v6; // cl
  signed int v7; // eax

  v2 = this;
  UFG::qAtomicIncrement(&textureD3D->mRefCount);
  v2->mMappedResource = 0i64;
  *(_QWORD *)&v2->mMappedSubResourceIdx = 0i64;
  v3 = (int)v2[-1].mVRamHandle.mData;
  v4 = (LODWORD(v2[-1].mVRamHandle.mData) >> 17) & 1;
  v5 = _bittest(&v3, 0x12u) || v4;
  if ( _bittest(&v3, 0xAu) || v4 )
  {
    v6 = 1;
    if ( v4 )
      LODWORD(v2[-1].mVRamHandle.mData) = v3 | 0x400000;
  }
  else
  {
    v6 = 0;
  }
  v2->mInitialImageData = 0i64;
  if ( v5 )
  {
    v7 = 1;
    if ( v6 )
      v7 = 3;
    v2->mCpuAccess = v7;
  }
  else
  {
    v2->mCpuAccess = v6 != 0 ? 2 : 0;
  }
}

// File Line: 1353
// RVA: 0xA18FC0
void __fastcall Illusion::TexturePlat::CreateResources(Illusion::TexturePlat *this, Illusion::TextureD3DResource *textureD3D)
{
  Illusion::TexturePlat *v2; // r14
  Illusion::TextureD3DResource *v3; // r15
  int v4; // eax
  __int64 v5; // rsi
  char v6; // al
  unsigned int v7; // edx
  bool v8; // r12
  int v9; // eax
  char v10; // r8
  bool v11; // di
  char v12; // cl
  int v13; // eax
  char v14; // bl
  int v15; // er13
  bool v16; // r8
  signed int v17; // eax
  int v18; // eax
  unsigned __int8 v19; // cf
  signed int v20; // eax
  char v21; // cl
  signed int v22; // eax
  int v23; // eax
  signed int v24; // eax
  bool v25; // bl
  ID3D11Resource *v26; // rcx
  char v27; // cl
  ID3D11Texture2D *v28; // rax
  char *v29; // r9
  bool v30; // zf
  __int64 v31; // rax
  unsigned int v32; // er11
  signed int v33; // ecx
  int v34; // er10
  int v35; // edx
  int v36; // er13
  signed int v37; // er8
  int v38; // er12
  signed int v39; // eax
  unsigned int v40; // ebx
  int v41; // edi
  signed int v42; // esi
  signed __int64 v43; // rcx
  unsigned int v44; // esi
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rax
  void *v47; // rdx
  int v48; // eax
  int v49; // edx
  D3D11_SUBRESOURCE_DATA *v50; // r8
  ID3D11Resource *v51; // rax
  ID3D11Resource *v52; // rdx
  int v53; // eax
  int v54; // eax
  unsigned __int64 v55; // rax
  __int64 v56; // rbx
  int v57; // eax
  unsigned int v58; // eax
  ID3D11ShaderResourceView **v59; // rax
  ID3D11Resource *v60; // rdx
  ID3D11Resource *v61; // rdx
  int v62; // eax
  UFG::qResourceData *v63; // rbx
  __int64 v64; // rdi
  ID3D11Resource *v65; // rax
  bool v66; // [rsp+20h] [rbp-E0h]
  char v67; // [rsp+24h] [rbp-DCh]
  int v68; // [rsp+28h] [rbp-D8h]
  __int64 v69; // [rsp+2Ch] [rbp-D4h]
  char v70[12]; // [rsp+34h] [rbp-CCh]
  int v71; // [rsp+40h] [rbp-C0h]
  int v72; // [rsp+44h] [rbp-BCh]
  int v73; // [rsp+48h] [rbp-B8h]
  int v74; // [rsp+4Ch] [rbp-B4h]
  int v75; // [rsp+50h] [rbp-B0h]
  int v76; // [rsp+54h] [rbp-ACh]
  void *source; // [rsp+58h] [rbp-A8h]
  unsigned int v78; // [rsp+60h] [rbp-A0h]
  int v79; // [rsp+64h] [rbp-9Ch]
  __int64 v80; // [rsp+70h] [rbp-90h]
  int v81; // [rsp+78h] [rbp-88h]
  int v82[141]; // [rsp+7Ch] [rbp-84h]
  bool v83; // [rsp+2C0h] [rbp+1C0h]
  char v84; // [rsp+2C8h] [rbp+1C8h]
  bool v85; // [rsp+2D0h] [rbp+1D0h]
  bool v86; // [rsp+2D8h] [rbp+1D8h]

  v2 = this;
  v3 = textureD3D;
  UFG::qAtomicIncrement(&textureD3D->mRefCount);
  v4 = (int)v2[-1].mVRamHandle.mData;
  v5 = 0i64;
  if ( !_bittest(&v4, 0xFu) && _bittest(&v4, 0xEu) && _bittest(&v4, 0x15u) )
    v5 = *(_QWORD *)&v2[-1].mTextureD3DResourceHandle.mNameUID;
  v2->mMappedResource = 0i64;
  *(_QWORD *)&v2->mMappedSubResourceIdx = 0i64;
  v6 = BYTE5(v2[-1].mVRamHandle.mData);
  v7 = (unsigned int)v2[-1].mVRamHandle.mData;
  v66 = v6 == 0;
  v8 = v6 == 2;
  v83 = v6 == 3;
  v9 = v7 >> 11;
  LOBYTE(v9) = (v7 >> 11) & 1;
  v10 = (v7 >> 17) & 1;
  v73 = v9;
  if ( _bittest((const signed int *)&v7, 0x12u) || (v84 = 0, v10) )
    v84 = 1;
  v11 = _bittest((const signed int *)&v7, 0xAu) || v10;
  v12 = BYTE4(v2[-1].mVRamHandle.mData);
  v85 = ((v12 - 16) & 0xFD) == 0;
  v86 = v12 == 19;
  v13 = v7 >> 19;
  LOBYTE(v13) = (v7 >> 19) & 1;
  v14 = (v7 >> 23) & 1;
  v79 = v13;
  v67 = (v7 >> 20) & 1;
  if ( v10 )
    LODWORD(v2[-1].mVRamHandle.mData) = v7 | 0x400000;
  v15 = LODWORD(v2[-1].mVRamHandle.mData) >> 22;
  LOBYTE(v15) = v15 & 1;
  v72 = v15;
  memset(&v3->mDesc, 0, 0x2Cui64);
  v16 = v83;
  v3->mDesc.Width = *(&v2[-1].mVRamHandle.mBlockID + 1);
  v3->mDesc.Height = *(&v2[-1].mVRamHandle.mBlockID + 2);
  v3->mDesc.MipLevels = LOBYTE(v2[-1].mTextureD3DResourceHandle.mPrev);
  if ( v83 )
  {
    v17 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
  }
  else
  {
    v17 = 1;
    if ( v8 )
      v17 = 6;
  }
  v3->mDesc.ArraySize = v17;
  *(_DWORD *)v3->mDesc.Format = Illusion::HardwareState::sTextureFormat[BYTE4(v2[-1].mVRamHandle.mData)];
  v18 = (int)v2[-1].mVRamHandle.mData;
  if ( _bittest(&v18, 0x1Au) )
  {
    v3->mDesc.SampleDesc.Count = 2;
  }
  else
  {
    v19 = _bittest(&v18, 0x1Bu);
    v20 = 1;
    if ( v19 )
      v20 = 4;
    v3->mDesc.SampleDesc.Count = v20;
  }
  v21 = v73;
  v3->mDesc.SampleDesc.Quality = 0;
  if ( v21 || v11 || v84 || (_BYTE)v15 || (v22 = 1, !v2->mInitialImageData) )
    v22 = 0;
  v3->mDesc.Usage = v22;
  *(_QWORD *)&v3->mDesc.CPUAccessFlags = 0i64;
  v3->mDesc.BindFlags = (v14 != 0 ? 0x80 : 0) | 8;
  if ( v84 )
  {
    v23 = 1;
    if ( v11 )
      v23 = 3;
  }
  else
  {
    v23 = v11 != 0 ? 2 : 0;
  }
  v2->mCpuAccess = v23;
  if ( v21 )
  {
    v3->mDesc.BindFlags |= 0x20u;
  }
  else if ( v23 == 2 )
  {
    v3->mDesc.Usage = 2;
    v3->mDesc.CPUAccessFlags = 0x10000;
  }
  if ( v8 )
    v3->mDesc.MiscFlags |= 4u;
  v24 = v3->mDesc.BindFlags;
  v25 = v85;
  if ( v85 )
    v24 = 72;
  v3->mDesc.BindFlags = v24;
  if ( v5 )
  {
    v26 = *(ID3D11Resource **)(*(_QWORD *)(v5 + 296) + 136i64);
    v3->mAliased = 1;
    v3->mGpuResource = v26;
LABEL_77:
    v27 = v67;
    goto LABEL_78;
  }
  v27 = v67;
  if ( !v67 )
  {
    v29 = v2->mInitialImageData;
    source = v29;
    if ( v29 && v3->mDesc.Usage <= 1u )
    {
      v30 = ((_QWORD)v2[-1].mVRamHandle.mData & 0x24000) == 0;
      v31 = BYTE4(v2[-1].mVRamHandle.mData);
      v32 = Illusion::HardwareState::sTextureSize[v31];
      v78 = Illusion::HardwareState::sTextureSize[v31];
      if ( v30 )
      {
        v29 = v2->mVRamHandle.mData;
        source = v2->mVRamHandle.mData;
      }
      v33 = 16;
      if ( (_BYTE)v31 == 1 )
        v33 = 8;
      v34 = 0;
      v74 = v33;
      v75 = 0;
      if ( (signed int)v3->mDesc.ArraySize > 0 )
      {
        do
        {
          v35 = *(&v2[-1].mVRamHandle.mBlockID + 2);
          v36 = *(&v2[-1].mVRamHandle.mBlockID + 1);
          v30 = v16 == 0;
          v76 = *(&v2[-1].mVRamHandle.mBlockID + 2);
          v37 = 1;
          if ( v30 )
            v37 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
          v38 = 0;
          v71 = v37;
          if ( LOBYTE(v2[-1].mTextureD3DResourceHandle.mPrev) )
          {
            do
            {
              v39 = BYTE4(v2[-1].mVRamHandle.mData);
              if ( v39 <= 0 || v39 > 3 && (unsigned int)(v39 - 8) > 5 )
              {
                v40 = v32 * v36 >> 3;
                v41 = v35 * v40;
              }
              else
              {
                v40 = v33 * ((v36 + 3) >> 2);
                v41 = v40 * ((v35 + 3) >> 2);
              }
              v42 = v37;
              v43 = 2i64 * (v38 + v34 * LOBYTE(v2[-1].mTextureD3DResourceHandle.mPrev));
              if ( v37 < 1 )
                v42 = 1;
              *(&v80 + 2 * (v38 + v34 * LOBYTE(v2[-1].mTextureD3DResourceHandle.mPrev))) = (__int64)v29;
              *(&v81 + 2 * v43) = v40;
              v82[2 * v43] = v41;
              v44 = v32 * v36 * v35 * v42 >> 3;
              if ( (_BYTE)v72 && !v34 && !v38 )
              {
                v45 = UFG::qMalloc(0x10ui64, "mDeferredContextTextureAccessBuffer", 0i64);
                v3->mDeferredContextTextureAccessBuffer = (Illusion::TextureLockInfo *)v45;
                LODWORD(v45[1].mNext) = v40;
                v3->mDeferredContextTextureAccessBuffer->mDepthPitch = v41;
                v46 = UFG::qMalloc(v44, (const char *)&v2[-1].mPad, 0i64);
                v47 = source;
                v3->mDeferredContextTextureAccessBuffer->mData = (char *)v46;
                UFG::qMemCopy(v3->mDeferredContextTextureAccessBuffer->mData, v47, v44);
                v35 = v76;
                v37 = v71;
                v29 = (char *)source;
                v34 = v75;
                v32 = v78;
              }
              v33 = v74;
              v35 >>= 1;
              v29 += v44;
              v48 = LOBYTE(v2[-1].mTextureD3DResourceHandle.mPrev);
              v37 >>= 1;
              ++v38;
              v36 >>= 1;
              v76 = v35;
              source = v29;
              v71 = v37;
            }
            while ( v38 < v48 );
          }
          v16 = v83;
          v75 = ++v34;
        }
        while ( v34 < (signed int)v3->mDesc.ArraySize );
        LOBYTE(v15) = v72;
        v25 = v85;
      }
      v49 = 1;
      if ( !v16 )
        v49 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
      v50 = (D3D11_SUBRESOURCE_DATA *)&v80;
    }
    else
    {
      v49 = 1;
      if ( !v83 )
        v49 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
      v50 = 0i64;
    }
    v51 = Illusion::CreateTexture(&v3->mDesc, v49, v50);
    v16 = v83;
    v3->mGpuResource = v51;
    goto LABEL_77;
  }
  v28 = gPresentBuffer;
  v3->mAliased = 1;
  v3->mGpuResource = (ID3D11Resource *)&v28->vfptr;
LABEL_78:
  if ( v25 || v86 )
  {
    if ( v66 )
    {
      v69 = 4i64;
      *(_DWORD *)v70 = 1;
      *(_QWORD *)&v70[4] = 0i64;
    }
    else
    {
      if ( !v16 )
        goto LABEL_95;
      v69 = 5i64;
      *(_QWORD *)&v70[4] = 0i64;
      v62 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
      *(_QWORD *)v70 = 1i64;
      *(_DWORD *)&v70[8] = v62;
    }
    v61 = v3->mGpuResource;
    v68 = 46;
    ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
      UFG::gD3D11Device,
      v61,
      &v68,
      &v3->mShaderResourceView);
  }
  else if ( !v27 )
  {
    v52 = v3->mGpuResource;
    if ( v16 )
    {
      v53 = *(_DWORD *)v3->mDesc.Format;
      v69 = 5i64;
      v68 = v53;
      *(_QWORD *)&v70[4] = 0i64;
      v54 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
      *(_DWORD *)&v70[4] = 0;
      *(_DWORD *)&v70[8] = v54;
      *(_DWORD *)v70 = LOBYTE(v2[-1].mTextureD3DResourceHandle.mPrev);
      ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
        UFG::gD3D11Device,
        v52,
        &v68,
        &v3->mShaderResourceView);
    }
    else
    {
      ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, _QWORD, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
        UFG::gD3D11Device,
        v52,
        0i64,
        &v3->mShaderResourceView);
    }
    if ( (_BYTE)v79 )
    {
      v55 = 8i64 * v3->mDesc.MipLevels;
      if ( !is_mul_ok(v3->mDesc.MipLevels, 8ui64) )
        v55 = -1i64;
      v56 = 0i64;
      v3->mShaderResourceViewMips = (ID3D11ShaderResourceView **)UFG::qMalloc(
                                                                   v55,
                                                                   "ID3D11ShaderResourceView Array",
                                                                   0i64);
      v57 = *(_DWORD *)v3->mDesc.Format;
      LODWORD(v69) = 4;
      v68 = v57;
      v58 = v3->mDesc.MipLevels;
      *(_DWORD *)v70 = 1;
      v3->mNumberMipViews = v58;
      if ( v58 )
      {
        do
        {
          v59 = v3->mShaderResourceViewMips;
          v60 = v3->mGpuResource;
          HIDWORD(v69) = v56;
          ((void (__fastcall *)(ID3D11Device *, ID3D11Resource *, int *, ID3D11ShaderResourceView **))UFG::gD3D11Device->vfptr->VSSetShader)(
            UFG::gD3D11Device,
            v60,
            &v68,
            &v59[v56]);
          v56 = (unsigned int)(v56 + 1);
        }
        while ( (unsigned int)v56 < v3->mNumberMipViews );
      }
    }
  }
LABEL_95:
  v2->mInitialImageData = 0i64;
  v3->mStagingResourceInitialized = 0;
  if ( v84 && !(_BYTE)v73 && !(_BYTE)v15 )
  {
    v63 = v2->mTextureD3DResourceHandle.mData;
    v64 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    if ( !*(_QWORD *)&v63[1].mDebugName[4] )
    {
      v65 = Illusion::TexturePlat::CreateCompatibleStagingResource(v2);
      *(_DWORD *)&v63[1].mDebugName[12] = 0;
      *(_QWORD *)&v63[1].mDebugName[4] = v65;
    }
    (*(void (__fastcall **)(__int64, _QWORD, ID3D11Resource *))(*(_QWORD *)v64 + 376i64))(
      v64,
      *(_QWORD *)&v63[1].mDebugName[4],
      v3->mGpuResource);
    v3->mStagingResourceInitialized = 1;
  }
  Illusion::TexturePlat::CreateSamplerState(v2, v3);
}Plat::CreateCompatibleStagingResource(v2);
      *(_DWORD *)&v63[1].mDebugName[12] = 0;
      *(_QWORD *)

// File Line: 1709
// RVA: 0xA196E0
void __fastcall Illusion::TexturePlat::CreateSamplerState(Illusion::TexturePlat *this, Illusion::TextureD3DResource *textureD3D)
{
  ID3D11SamplerState **v2; // rdi
  Illusion::TexturePlat *v3; // rbx
  ID3D11SamplerState *v4; // rcx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  signed int v12; // ecx
  __int64 v13; // rax
  float v14; // xmm0_4
  char v15; // r8
  __int64 v16; // r9
  char v17; // dl
  int v18; // ecx
  int Dst; // [rsp+20h] [rbp-48h]
  int v20; // [rsp+24h] [rbp-44h]
  int v21; // [rsp+28h] [rbp-40h]
  int v22; // [rsp+2Ch] [rbp-3Ch]
  float v23; // [rsp+30h] [rbp-38h]
  int v24; // [rsp+34h] [rbp-34h]
  int v25; // [rsp+38h] [rbp-30h]
  int v26; // [rsp+4Ch] [rbp-1Ch]
  float v27; // [rsp+50h] [rbp-18h]

  v2 = &textureD3D->mSamplerState;
  v3 = this;
  v4 = textureD3D->mSamplerState;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    *v2 = 0i64;
  }
  memset(&Dst, 0, 0x34ui64);
  v5 = BYTE1(v3[-1].mTextureD3DResourceHandle.mPrev);
  if ( BYTE4(v3[-1].mVRamHandle.mData) != 18 )
  {
    if ( BYTE1(v3[-1].mTextureD3DResourceHandle.mPrev) )
    {
      v9 = v5 - 1;
      if ( !v9 )
        goto LABEL_18;
      v10 = v9 - 1;
      if ( !v10 )
      {
        Dst = 0;
        goto LABEL_24;
      }
      v11 = v10 - 1;
      if ( v11 )
      {
        if ( v11 != 1 )
        {
LABEL_24:
          v25 = 8;
          goto LABEL_25;
        }
LABEL_18:
        Dst = 21;
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
    Dst = v12;
    goto LABEL_24;
  }
  if ( !BYTE1(v3[-1].mTextureD3DResourceHandle.mPrev) )
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
        v25 = 4;
        goto LABEL_25;
      }
LABEL_9:
      Dst = 149;
      goto LABEL_10;
    }
    Dst = 213;
    v25 = 4;
  }
  else
  {
    Dst = 128;
    v25 = 4;
  }
LABEL_25:
  v13 = HIBYTE(v3[-1].mVRamHandle.mData);
  v14 = 0.0;
  v16 = (unsigned int)(LODWORD(v3[-1].mVRamHandle.mData) >> 2);
  v15 = (LODWORD(v3[-1].mVRamHandle.mData) >> 1) & 1;
  LOBYTE(v16) = v16 & 1;
  v17 = (LODWORD(v3[-1].mVRamHandle.mData) >> 3) & 1;
  if ( v13 & 0xF )
  {
    if ( *(float *)&v3[-1].mVRamHandle.mReadOnlyAndPoolID != 0.0 )
      v14 = *(float *)&v3[-1].mVRamHandle.mReadOnlyAndPoolID;
  }
  else
  {
    v14 = aTexBias[v13];
  }
  v18 = 3;
  if ( (_QWORD)v3[-1].mVRamHandle.mData & 1 )
    v20 = 3;
  else
    v20 = ((_BYTE)v16 != 0) + 1;
  if ( !v15 )
    v18 = (v17 != 0) + 1;
  v21 = v18;
  v22 = v18;
  v23 = v14;
  v24 = gDefaultTextureFilterQuality;
  v26 = 0;
  v27 = FLOAT_3_4028235e38;
  ((void (__fastcall *)(ID3D11Device *, int *, ID3D11SamplerState **, __int64))UFG::gD3D11Device->vfptr->GSSetSamplers)(
    UFG::gD3D11Device,
    &Dst,
    v2,
    v16);
}

// File Line: 1785
// RVA: 0xA18B50
ID3D11Resource *__fastcall Illusion::TexturePlat::CreateCompatibleStagingResource(Illusion::TexturePlat *this)
{
  UFG::qResourceData *v1; // rdx
  Illusion::TexturePlat *v2; // r8
  signed int v3; // ecx
  unsigned int v4; // er9
  unsigned int v5; // er10
  int v6; // er11
  unsigned int v7; // ebx
  int v8; // eax
  signed int v9; // edx
  unsigned __int64 v11; // [rsp+20h] [rbp-60h]
  unsigned __int64 v12; // [rsp+28h] [rbp-58h]
  int v13; // [rsp+30h] [rbp-50h]
  __int64 v14; // [rsp+34h] [rbp-4Ch]
  unsigned __int64 v15; // [rsp+3Ch] [rbp-44h]
  UFG::qBaseNodeRB *v16; // [rsp+48h] [rbp-38h]
  int v17; // [rsp+50h] [rbp-30h]
  int v18; // [rsp+54h] [rbp-2Ch]
  int v19; // [rsp+58h] [rbp-28h]
  int v20; // [rsp+5Ch] [rbp-24h]
  unsigned int v21; // [rsp+60h] [rbp-20h]
  __int64 v22; // [rsp+64h] [rbp-1Ch]
  int v23; // [rsp+6Ch] [rbp-14h]
  int v24; // [rsp+70h] [rbp-10h]
  __int64 v25; // [rsp+90h] [rbp+10h]

  v1 = this->mTextureD3DResourceHandle.mData;
  v2 = this;
  v3 = 0;
  v4 = (unsigned int)v1[1].mNode.mParent;
  v16 = v1[1].mNode.mParent;
  v5 = (unsigned int)v1[1].mNode.mChild[0];
  v17 = (int)v1[1].mNode.mChild[0];
  v18 = HIDWORD(v1[1].mNode.mChild[0]);
  v6 = (int)v1[1].mNode.mChild[1];
  v19 = (int)v1[1].mNode.mChild[1];
  v20 = HIDWORD(v1[1].mNode.mChild[1]);
  v21 = v1[1].mNode.mUID;
  v22 = *(_QWORD *)(&v1[1].mNode.mUID + 1);
  v23 = HIDWORD(v1[1].mResourceHandles.mNode.mPrev);
  v7 = (unsigned int)v1[1].mResourceHandles.mNode.mNext;
  v8 = (int)v2[-1].mVRamHandle.mData;
  v24 = (int)v1[1].mResourceHandles.mNode.mNext;
  v22 = 3i64;
  v23 = 0;
  if ( _bittest(&v8, 0x12u) || _bittest(&v8, 0x11u) )
  {
    v3 = 0x20000;
    v23 = 0x20000;
  }
  if ( _bittest(&v8, 0xAu) || _bittest(&v8, 0x11u) )
  {
    v3 |= 0x10000u;
    v23 = v3;
  }
  v9 = 1;
  if ( BYTE5(v2[-1].mVRamHandle.mData) != 3 )
    v9 = WORD1(v2[-1].mTextureD3DResourceHandle.mPrev);
  v25 = 0i64;
  if ( v9 <= 1 )
  {
    ((void (__fastcall *)(ID3D11Device *, UFG::qBaseNodeRB **, _QWORD, __int64 *))UFG::gD3D11Device->vfptr->PSSetShader)(
      UFG::gD3D11Device,
      &v16,
      0i64,
      &v25);
  }
  else
  {
    v11 = __PAIR__(HIDWORD(v16), v4);
    v15 = __PAIR__(v7, v3);
    v12 = __PAIR__(v5, v9);
    v13 = v6;
    v14 = 3i64;
    ((void (__fastcall *)(ID3D11Device *, unsigned __int64 *, _QWORD, __int64 *, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, UFG::qBaseNodeRB *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->PSSetSamplers)(
      UFG::gD3D11Device,
      &v11,
      0i64,
      &v25,
      __PAIR__(HIDWORD(v16), v4),
      __PAIR__(v5, v9),
      *(_QWORD *)&v13,
      *(__int64 *)((char *)&v14 + 4),
      *(unsigned __int64 *)((char *)&v15 + 4),
      v16,
      *(_QWORD *)&v17,
      *(_QWORD *)&v19,
      *(_QWORD *)&v21,
      *(__int64 *)((char *)&v22 + 4),
      *(_QWORD *)&v24);
  }
  return (ID3D11Resource *)v25;
}

// File Line: 1815
// RVA: 0xA1AFC0
ID3D11Resource *__fastcall Illusion::TexturePlat::GetOrCreateStagingResource(Illusion::TexturePlat *this)
{
  UFG::qResourceData *v1; // rbx
  ID3D11Resource *result; // rax

  v1 = this->mTextureD3DResourceHandle.mData;
  if ( *(_QWORD *)&v1[1].mDebugName[4] )
    return *(ID3D11Resource **)&v1[1].mDebugName[4];
  result = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
  *(_DWORD *)&v1[1].mDebugName[12] = 0;
  *(_QWORD *)&v1[1].mDebugName[4] = result;
  return result;
}

// File Line: 1828
// RVA: 0xA1ED30
void __fastcall Illusion::TexturePlat::OnPreMove(Illusion::TexturePlat *this)
{
  Illusion::TexturePlat *v1; // rdi
  Illusion::Texture *v2; // rbx
  AMD_HD3D *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax
  Illusion::TextureD3DResourceHandle *v6; // rdx

  v1 = this;
  v2 = (Illusion::Texture *)&this[-2].mPadding[40];
  if ( this->mTextureUserPlat.mOffset )
    v3 = (AMD_HD3D *)((char *)this + this->mTextureUserPlat.mOffset);
  else
    v3 = 0i64;
  _(v3);
  Illusion::TextureD3DResourceInventory::OnTextureUnload(&Illusion::gTextureD3DResourceInventory, v2);
  v4 = v1->mTextureD3DResourceHandle.mPrev;
  v5 = v1->mTextureD3DResourceHandle.mNext;
  v6 = &v1->mTextureD3DResourceHandle;
  v4->mNext = v5;
  v5->mPrev = v4;
  v6->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v6->mPrev;
  if ( v2->mTextureDataHandle.mData )
  {
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mTextureDataHandle.mPrev);
    v2->mFlags |= 0x1000000u;
  }
  v2->mFlags |= 0x8000u;
  UFG::qVRAMemoryPools::PreMove(&v1->mVRamHandle);
}

// File Line: 1899
// RVA: 0xA17E80
void __fastcall Illusion::TexturePlat::CopyForDelayedRead(Illusion::TexturePlat *this)
{
  UFG::qResourceData *v1; // rbp
  float v2; // xmm0_4
  unsigned int *v3; // rdi
  signed int v4; // ebx
  ID3D11Resource *v5; // rsi
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // rcx
  signed __int64 v7; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  __int64 v9; // rcx
  unsigned int *v10; // rax

  v1 = this->mTextureD3DResourceHandle.mData;
  v2 = FLOAT_5_0;
  v3 = &v1[2].mNode.mUID;
  if ( (float)Illusion::gEnginePlat.mMaxGpuFramesInFlight <= 5.0 )
    v2 = (float)Illusion::gEnginePlat.mMaxGpuFramesInFlight;
  v4 = 0;
  if ( *(_QWORD *)&v3[2 * (signed int)v2 - 2] )
  {
    v5 = *(ID3D11Resource **)v3;
    v6 = &v1[2].mResourceHandles;
    v7 = 4i64;
    do
    {
      v8 = v6->mNode.mPrev;
      v6 = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)((char *)v6 + 8);
      v6[-1].mNode.mPrev = v8;
      --v7;
    }
    while ( v7 );
    *(_QWORD *)&v1[2].mDebugName[4] = 0i64;
  }
  else
  {
    v5 = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
  }
  if ( v5 )
  {
    v9 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    (*(void (__fastcall **)(__int64, ID3D11Resource *, _QWORD))(*(_QWORD *)v9 + 376i64))(
      v9,
      v5,
      *(_QWORD *)&v1[1].mTypeUID);
    v10 = &v1[2].mNode.mUID;
    while ( *(_QWORD *)v10 )
    {
      ++v4;
      v10 += 2;
      if ( v4 >= 5 )
        return;
    }
    *(_QWORD *)&v3[2 * v4] = v5;
  }
}

// File Line: 1957
// RVA: 0xA1C570
char __fastcall Illusion::TexturePlat::Lock(Illusion::TexturePlat *this, Illusion::ITexturePlat::LockType type, Illusion::TextureLockInfo *info, int mipLevel, int faceIndex)
{
  UFG::qResourceData *v5; // rdi
  Illusion::TexturePlat *v6; // rbx
  Illusion::ITexturePlat::LockType v7; // ebp
  char v8; // r13
  Illusion::TextureLockInfo *v9; // rsi
  char v10; // r12
  bool v11; // al
  bool v12; // r15
  int v14; // ebp
  int v15; // ebp
  unsigned int v16; // er14
  ID3D11Resource *v17; // rbp
  unsigned int v18; // eax
  signed int v19; // er12
  UFG::qResourceData *v20; // r15
  __int64 v21; // r13
  ID3D11Resource *v22; // rax
  int v23; // edi
  unsigned int v24; // edi
  int v25; // eax
  char v26; // [rsp+30h] [rbp-58h]
  _QWORD *v27; // [rsp+38h] [rbp-50h]
  char *v28; // [rsp+40h] [rbp-48h]
  __int64 v29; // [rsp+48h] [rbp-40h]
  unsigned __int8 v30; // [rsp+90h] [rbp+8h]
  int v31; // [rsp+A8h] [rbp+20h]

  v31 = mipLevel;
  v5 = this->mTextureD3DResourceHandle.mData;
  v6 = this;
  v7 = type;
  v8 = 0;
  v9 = info;
  v27 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
  v10 = (LODWORD(this[-1].mVRamHandle.mData) >> 11) & 1;
  v26 = 0;
  v30 = 0;
  v11 = (*(unsigned int (**)(void))(*(_QWORD *)*v27 + 896i64))() == 1;
  v12 = (_QWORD)v6[-1].mVRamHandle.mData & 0x400000 || *(_QWORD *)&v5[1].mDebugName[20];
  if ( !v11 || !v12 )
  {
    if ( v7 == LOCK_READ )
    {
      if ( v6->mCpuAccess != 1 )
        return 0;
      v17 = *(ID3D11Resource **)&v5[2].mNode.mUID;
      if ( !v17 )
        return 0;
      v16 = 1;
      v26 = 1;
      goto LABEL_45;
    }
    v14 = v7 - 1;
    if ( !v14 )
    {
      if ( (v6->mCpuAccess - 1) & 0xFFFFFFFD )
        return 0;
      v16 = 1;
      v17 = Illusion::TexturePlat::GetOrCreateStagingResource(v6);
      if ( v10 && !v12 || !*(_DWORD *)&v5[1].mDebugName[12] )
        v8 = 1;
      goto LABEL_45;
    }
    v15 = v14 - 1;
    if ( v15 )
    {
      if ( v15 != 1 || v6->mCpuAccess != 3 )
        return 0;
      v16 = 3;
      v30 = 1;
      v17 = Illusion::TexturePlat::GetOrCreateStagingResource(v6);
      if ( v10 && !v12 || !*(_DWORD *)&v5[1].mDebugName[12] )
        v8 = 1;
      goto LABEL_45;
    }
    v18 = v6->mCpuAccess;
    if ( v18 == 2 )
    {
      if ( !v10 )
      {
        v17 = *(ID3D11Resource **)&v5[1].mTypeUID;
        v16 = 4;
LABEL_45:
        if ( v17 )
        {
          v19 = 0;
          if ( v8 )
          {
            v20 = v6->mTextureD3DResourceHandle.mData;
            v21 = *v27;
            if ( !*(_QWORD *)&v20[1].mDebugName[4] )
            {
              v22 = Illusion::TexturePlat::CreateCompatibleStagingResource(v6);
              *(_DWORD *)&v20[1].mDebugName[12] = 0;
              *(_QWORD *)&v20[1].mDebugName[4] = v22;
            }
            (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v21 + 376i64))(
              v21,
              *(_QWORD *)&v20[1].mDebugName[4],
              *(_QWORD *)&v5[1].mTypeUID);
            *(_DWORD *)&v5[1].mDebugName[12] = 1;
          }
          v23 = LOBYTE(v6[-1].mTextureD3DResourceHandle.mPrev);
          v29 = 0i64;
          v28 = 0i64;
          if ( v26 )
            v19 = 0x100000;
          v24 = v31 + faceIndex * v23;
          v25 = (*(__int64 (__fastcall **)(_QWORD, ID3D11Resource *, _QWORD, _QWORD, signed int, char **))(*(_QWORD *)*v27 + 112i64))(
                  *v27,
                  v17,
                  v24,
                  v16,
                  v19,
                  &v28);
          if ( v25 != -2005270518 && v25 >= 0 )
          {
            v6->mMappedResource = v17;
            v6->mMappedSubResourceIdx = v24;
            v6->mUploadAfterUnmap = v30;
            if ( v9 )
            {
              v9->mData = v28;
              *(_QWORD *)&v9->mLinePitch = v29;
            }
            return 1;
          }
        }
        return 0;
      }
    }
    else if ( v18 != 3 )
    {
      return 0;
    }
    v16 = 2;
    v30 = 1;
    v17 = Illusion::TexturePlat::GetOrCreateStagingResource(v6);
    goto LABEL_45;
  }
  if ( (v7 & 0x80000000) != 0 )
    return 0;
  if ( (signed int)v7 > 1 )
  {
    if ( (signed int)v7 <= 3 && v6->mCpuAccess == 3 )
    {
      if ( !*(_QWORD *)&v5[1].mDebugName[20] )
        Illusion::TexturePlat::CreateClearedMainMemCopy(v6);
      if ( v9 )
      {
        v9->mData = **(char ***)&v5[1].mDebugName[20];
        v9->mLinePitch = *(_DWORD *)(*(_QWORD *)&v5[1].mDebugName[20] + 8i64);
        v9->mDepthPitch = *(_DWORD *)(*(_QWORD *)&v5[1].mDebugName[20] + 12i64);
      }
      v6->mUploadAfterUnmap = 1;
      return 1;
    }
    return 0;
  }
  if ( (v6->mCpuAccess - 1) & 0xFFFFFFFD )
    return 0;
  if ( !*(_QWORD *)&v5[1].mDebugName[20] )
    Illusion::TexturePlat::CreateClearedMainMemCopy(v6);
  if ( v9 )
  {
    v9->mData = **(char ***)&v5[1].mDebugName[20];
    v9->mLinePitch = *(_DWORD *)(*(_QWORD *)&v5[1].mDebugName[20] + 8i64);
    v9->mDepthPitch = *(_DWORD *)(*(_QWORD *)&v5[1].mDebugName[20] + 12i64);
  }
  return 1;
}

// File Line: 2147
// RVA: 0xA22A80
void __fastcall Illusion::TexturePlat::Unlock(Illusion::TexturePlat *this)
{
  UFG::qResourceData *v1; // rdi
  Illusion::TexturePlat *v2; // rbx
  _QWORD *v3; // rsi
  _QWORD *v4; // rsi

  v1 = this->mTextureD3DResourceHandle.mData;
  v2 = this;
  if ( this->mMappedResource )
  {
    v3 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    (*(void (__fastcall **)(_QWORD, ID3D11Resource *, _QWORD))(*(_QWORD *)*v3 + 120i64))(
      *v3,
      this->mMappedResource,
      this->mMappedSubResourceIdx);
    if ( v2->mUploadAfterUnmap )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, ID3D11Resource *))(*(_QWORD *)*v3 + 376i64))(
        *v3,
        *(_QWORD *)&v1[1].mTypeUID,
        v2->mMappedResource);
      *(_DWORD *)&v1[1].mDebugName[12] = 1;
    }
    v2->mMappedResource = 0i64;
    v2->mUploadAfterUnmap = 0;
  }
  else if ( this->mUploadAfterUnmap )
  {
    v4 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    if ( (*(unsigned int (**)(void))(*(_QWORD *)*v4 + 896i64))() == 1 && (LODWORD(v2[-1].mVRamHandle.mData) >> 22) & 1 )
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD))(*(_QWORD *)*v4 + 384i64))(
        *v4,
        *(_QWORD *)&v1[1].mTypeUID,
        0i64,
        0i64,
        **(_QWORD **)&v1[1].mDebugName[20],
        *(_DWORD *)(*(_QWORD *)&v1[1].mDebugName[20] + 8i64),
        *(_DWORD *)(*(_QWORD *)&v1[1].mDebugName[20] + 12i64));
    v2->mUploadAfterUnmap = 0;
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
  UFG::qResourceData *v1; // rbx
  __int64 v2; // rdi
  ID3D11Resource *v3; // rax
  unsigned int v4; // ebx

  v1 = this->mTextureD3DResourceHandle.mData;
  if ( Illusion::gTextureReadBackRequired == 1 || (_QWORD)this[-1].mVRamHandle.mData & 0x20000 )
  {
    v2 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    if ( !*(_QWORD *)&v1[1].mDebugName[4] )
    {
      v3 = Illusion::TexturePlat::CreateCompatibleStagingResource(this);
      *(_DWORD *)&v1[1].mDebugName[12] = 0;
      *(_QWORD *)&v1[1].mDebugName[4] = v3;
    }
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v2 + 376i64))(
      v2,
      *(_QWORD *)&v1[1].mDebugName[4],
      *(_QWORD *)&v1[1].mTypeUID);
    *(_DWORD *)&v1[1].mDebugName[12] = 1;
  }
  else
  {
    Illusion::TexturePlat::CopyForDelayedRead(this);
  }
  v4 = v1->mNode.mUID;
  Illusion::gTextureD3DResourceInventory.mHighPriorityUIDs[(signed int)UFG::qAtomicIncrement(&Illusion::gTextureNumSyncUIDs)
                                                         + 4095] = v4;
}

// File Line: 2273
// RVA: 0xA18A70
void __fastcall Illusion::TexturePlat::CreateClearedMainMemCopy(Illusion::TexturePlat *this)
{
  UFG::qResourceData *v1; // r14
  Illusion::TexturePlat *v2; // rbp
  int v3; // edx
  signed int v4; // esi
  unsigned int v5; // er8
  int v6; // eax
  unsigned int v7; // edi
  int v8; // ebx
  unsigned int v9; // esi
  UFG::allocator::free_link *v10; // rax

  v1 = this->mTextureD3DResourceHandle.mData;
  v2 = this;
  v3 = *(&this[-1].mVRamHandle.mBlockID + 1);
  v4 = WORD1(this[-1].mTextureD3DResourceHandle.mPrev);
  v5 = Illusion::HardwareState::sTextureSize[BYTE4(this[-1].mVRamHandle.mData)];
  v6 = *(&this[-1].mVRamHandle.mBlockID + 2);
  v7 = v5 * v3 >> 3;
  v8 = v6 * v7;
  if ( v4 < 1 )
    v4 = 1;
  v9 = v5 * v3 * v6 * v4 >> 3;
  v10 = UFG::qMalloc(0x10ui64, "mDeferredContextTextureAccessBuffer", 0i64);
  *(_QWORD *)&v1[1].mDebugName[20] = v10;
  LODWORD(v10[1].mNext) = v7;
  *(_DWORD *)(*(_QWORD *)&v1[1].mDebugName[20] + 12i64) = v8;
  **(_QWORD **)&v1[1].mDebugName[20] = UFG::qMalloc(v9, (const char *)&v2[-1].mPad, 0i64);
  UFG::qMemSet(**(void ***)&v1[1].mDebugName[20], 0, v9);
}

// File Line: 2302
// RVA: 0xA226A0
void __fastcall Illusion::TexturePlat::SwitchAliasTexture(Illusion::TexturePlat *this, Illusion::Texture *new_alias_texture)
{
  UFG::qResourceData *v2; // rsi
  Illusion::Texture *v3; // rdi
  __int64 v4; // rcx
  __int64 v5; // rdx
  char v6; // al
  char v7; // r8
  int *v8; // r8
  int v9; // eax
  int v10; // eax
  int v11; // [rsp+20h] [rbp-28h]
  __int64 v12; // [rsp+24h] [rbp-24h]
  __int64 v13; // [rsp+2Ch] [rbp-1Ch]
  int v14; // [rsp+34h] [rbp-14h]

  v2 = this->mTextureD3DResourceHandle.mData;
  v3 = new_alias_texture;
  v4 = *(_QWORD *)&v2[1].mDebugName[28];
  if ( v4 )
  {
    (*(void (**)(void))(*(_QWORD *)v4 + 16i64))();
    *(_QWORD *)&v2[1].mDebugName[28] = 0i64;
  }
  v5 = *(_QWORD *)(*(_QWORD *)&v3[1].mMipMapBias + 136i64);
  *(_QWORD *)&v2[1].mTypeUID = v5;
  v6 = v3->mType;
  v7 = v3->mFormat;
  if ( (v7 - 16) & 0xFC || v7 == 17 )
  {
    if ( v6 == 3 )
    {
      v10 = (int)v2[1].mNode.mChild[1];
      v12 = 5i64;
      v8 = &v11;
      v11 = v10;
      *(__int64 *)((char *)&v13 + 4) = 0i64;
      v14 = v3->mDepth;
      v13 = (unsigned __int8)v3->mNumMipMaps;
    }
    else
    {
      v8 = 0i64;
    }
  }
  else if ( v6 )
  {
    if ( v6 != 3 )
      return;
    v11 = 46;
    v12 = 5i64;
    *(__int64 *)((char *)&v13 + 4) = 0i64;
    v9 = v3->mDepth;
    v13 = 1i64;
    v14 = v9;
    v8 = &v11;
  }
  else
  {
    v11 = 46;
    v12 = 4i64;
    LODWORD(v13) = 1;
    v8 = &v11;
    *(__int64 *)((char *)&v13 + 4) = 0i64;
  }
  ((void (__fastcall *)(ID3D11Device *, __int64, int *, char *, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetShader)(
    UFG::gD3D11Device,
    v5,
    v8,
    &v2[1].mDebugName[28],
    *(_QWORD *)&v11,
    *(__int64 *)((char *)&v12 + 4),
    *(__int64 *)((char *)&v13 + 4));
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
  Illusion::ITexturePlat *v1; // rbx
  signed __int64 v2; // rcx
  unsigned int v3; // er8

  *(_DWORD *)&this[88] &= 0xFFFF7FFF;
  v1 = this;
  UFG::qVRAMemoryPools::PostMove((UFG::qVRAMemoryHandle *)&this[248]);
  if ( *(_DWORD *)&v1[88] & 0x1000000 )
  {
    v2 = (signed __int64)&v1[152];
    v3 = *(_DWORD *)&v1[176];
    *(_QWORD *)(v2 + 32) = Illusion::Texture::HandleUpdated;
    *(_QWORD *)(v2 + 40) = v1;
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1[152], 0xA428072C, v3);
    *(_DWORD *)&v1[88] &= 0xFEFFFFFF;
  }
}

// File Line: 2437
// RVA: 0xA1EE40
void __fastcall Illusion::ITexturePlat::OnSetSampler(Illusion::ITexturePlat *this)
{
  JUMPOUT(*(_QWORD *)&this[296], 0i64, Illusion::TexturePlat::CreateSamplerState);
}

// File Line: 2468
// RVA: 0xA1C560
bool __fastcall Illusion::ITexturePlat::Lock(Illusion::ITexturePlat *this, Illusion::ITexturePlat::LockType type, Illusion::TextureLockInfo *info, int mipLevel, int faceIndex)
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
  if ( *(_DWORD *)&this[88] & 0x4000 )
    Illusion::TextureD3DResourceInventory::ForceUnload(&Illusion::gTextureD3DResourceInventory, *(_DWORD *)&this[24]);
}

// File Line: 2508
// RVA: 0xA22690
void __fastcall Illusion::ITexturePlat::SwitchAliasTexture(Illusion::ITexturePlat *this, Illusion::Texture *new_alias_texture)
{
  Illusion::TexturePlat::SwitchAliasTexture((Illusion::TexturePlat *)&this[208], new_alias_texture);
}

