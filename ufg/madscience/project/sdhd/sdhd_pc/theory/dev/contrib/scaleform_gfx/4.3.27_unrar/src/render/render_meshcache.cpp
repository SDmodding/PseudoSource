// File Line: 29
// RVA: 0x9B1DF0
void __fastcall Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(Scaleform::Render::MeshCacheItemUseNode *this, Scaleform::Render::MeshCacheItem *p)
{
  if ( this->pMeshItem )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    this->pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
  }
  this->pMeshItem = p;
  if ( p )
  {
    this->pNext = p->PrimitiveBatches.Root.pNext;
    this->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)&p->PrimitiveBatches;
    p->PrimitiveBatches.Root.pNext->pPrev = this;
    p->PrimitiveBatches.Root.pNext = this;
  }
}

// File Line: 44
// RVA: 0x965790
Scaleform::Render::MeshCacheItem *__fastcall Scaleform::Render::MeshCacheItem::Create(Scaleform::Render::MeshCacheItem::MeshType type, Scaleform::Render::MeshCacheListSet *pcacheList, unsigned __int64 classSize, Scaleform::Render::MeshCacheItem::MeshBaseContent *content, unsigned __int64 allocSize, unsigned int vertexCount, unsigned int indexCount)
{
  Scaleform::Render::MeshCache *v7; // r13
  __int64 v8; // rsi
  Scaleform::Render::MeshCacheItem::MeshType v9; // ebp
  Scaleform::Render::MeshCacheListSet *v10; // r12
  unsigned __int64 v11; // rdi
  Scaleform::Render::MeshCacheItem::MeshBaseContent *v12; // r14
  __int64 v13; // r15
  Scaleform::Render::MeshCacheItem *result; // rax
  Scaleform::Render::MeshCacheItem *v15; // rbx
  __int64 v16; // r8
  __int64 v17; // r9
  Scaleform::Render::MeshBase *v18; // rax
  Scaleform::List<Scaleform::Render::MeshCacheItemUseNode,Scaleform::Render::MeshCacheItemUseNode> *v19; // rax
  __int64 v20; // rdi
  __int64 v21; // r8
  unsigned __int64 v22; // rdx
  signed __int64 v23; // rcx
  __int64 v24; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v25; // rax
  Scaleform::Render::MeshCacheItem *key; // [rsp+58h] [rbp+10h]

  v7 = pcacheList->pCache;
  v8 = LODWORD(content->Meshes.Size);
  v9 = type;
  v10 = pcacheList;
  v11 = (classSize + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  v12 = content;
  v13 = LODWORD(content->Meshes.Size);
  result = (Scaleform::Render::MeshCacheItem *)pcacheList->pCache->pHeap->vfptr->Alloc(
                                                 pcacheList->pCache->pHeap,
                                                 v11 + 8 * v8,
                                                 0i64);
  v15 = result;
  key = result;
  if ( result )
  {
    result->Type = v9;
    result->pCacheList = v10;
    result->HashKey = v12->HashKey;
    v16 = 0i64;
    result->MeshCount = v8;
    result->pMeshes = (Scaleform::Render::MeshBase **)((char *)result + v11);
    if ( (_DWORD)v8 )
    {
      v17 = v8;
      do
      {
        v18 = *(Scaleform::Render::MeshBase **)((char *)v12->Meshes.pData + v16++ * v12->Meshes.StrideSize);
        v15->pMeshes[v16 - 1] = v18;
        --v17;
      }
      while ( v17 );
    }
    v19 = &v15->PrimitiveBatches;
    v19->Root.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)v19;
    v19->Root.pNext = (Scaleform::Render::MeshCacheItemUseNode *)v19;
    v15->AllocSize = allocSize;
    v15->VertexCount = vertexCount;
    v15->IndexCount = indexCount;
    v15->GPUFence.pObject = 0i64;
    if ( v9 )
    {
      (*v15->pMeshes)[1].pPrev = (Scaleform::Render::MeshStagingNode *)v15;
    }
    else
    {
      v20 = 0i64;
      if ( (_DWORD)v8 )
      {
        do
        {
          v21 = *(__int64 *)((char *)v12->Meshes.pData + v20 * v12->Meshes.StrideSize);
          v22 = *(_QWORD *)(v21 + 160);
          if ( v22 <= 2 )
            v23 = v21 + 168;
          else
            v23 = *(_QWORD *)(v21 + 168);
          v24 = 0i64;
          if ( v22 )
          {
            while ( *(Scaleform::Render::MeshCacheItem **)(v23 + 8 * v24) != v15 )
            {
              if ( ++v24 >= v22 )
                goto LABEL_13;
            }
          }
          else
          {
LABEL_13:
            v25 = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
                    (Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *)(v21 + 160),
                    v22);
            if ( v25 )
              v25->pObject = (Scaleform::Render::TextLayerPrimitive *)v15;
          }
          ++v20;
          --v13;
        }
        while ( v13 );
      }
      Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::add<Scaleform::Render::MeshCacheItem *>(
        (Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *)&v7->BatchCacheItemHash.pTable,
        &v7->BatchCacheItemHash,
        &key,
        v15->HashKey);
    }
    v15->ListType = 0;
    v15->pNext = v10->Slots[0].Root.pNext;
    v15->pPrev = (Scaleform::Render::MeshCacheItem *)v10->Slots;
    v10->Slots[0].Root.pNext->pPrev = v15;
    v10->Slots[0].Root.pNext = v15;
    v10->Slots[0].Size += v15->AllocSize;
    result = v15;
  }
  return result;
}

// File Line: 105
// RVA: 0x96D100
void __fastcall Scaleform::Render::MeshCacheItem::Destroy(Scaleform::Render::MeshCacheItem *this, Scaleform::Render::MeshBase *pskipMesh, bool freeMemory)
{
  Scaleform::Render::MeshCacheListSet *v3; // r10
  Scaleform::Render::MeshCacheItem *v4; // rdi
  signed __int64 v5; // rax
  bool v6; // r15
  Scaleform::Render::MeshBase *v7; // r14
  Scaleform::Render::MeshCacheItemUseNode *v8; // rax
  Scaleform::List<Scaleform::Render::MeshCacheItemUseNode,Scaleform::Render::MeshCacheItemUseNode> *v9; // rcx
  Scaleform::Render::MeshCacheItem::MeshType v10; // eax
  Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *v11; // rcx
  unsigned int i; // edx
  Scaleform::Render::MeshBase *v13; // r8
  unsigned int j; // ebp
  Scaleform::Render::MeshBase *v15; // rbx
  unsigned __int64 v16; // r8
  signed __int64 *v17; // rsi
  _QWORD *v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rcx
  signed __int64 v21; // rdx
  Scaleform::Render::MeshProvider *v22; // rcx
  unsigned int k; // ebx
  Scaleform::Render::MeshBase *v24; // rcx
  Scaleform::Render::MeshBase *v25; // rdx
  Scaleform::Render::MeshProvider *v26; // rcx
  Scaleform::Render::Fence *v27; // rsi
  bool v28; // zf
  Scaleform::Render::FenceImpl *v29; // rcx
  Scaleform::Render::RenderSync *v30; // rbx
  Scaleform::Render::FenceImpl *v31; // rcx
  Scaleform::Render::MeshCacheItem *key; // [rsp+50h] [rbp+8h]

  v3 = this->pCacheList;
  this->pPrev->pNext = this->pNext;
  this->pNext->pPrev = this->pPrev;
  v4 = this;
  v5 = (signed int)this->ListType + 1i64;
  this->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
  this->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
  *((_QWORD *)&v3->pCache + 3 * v5) -= this->AllocSize;
  v6 = freeMemory;
  v7 = pskipMesh;
  if ( this->Type <= 1u )
  {
    v8 = this->PrimitiveBatches.Root.pNext;
    v9 = &this->PrimitiveBatches;
    if ( v8 != (Scaleform::Render::MeshCacheItemUseNode *)&v4->PrimitiveBatches )
    {
      do
      {
        v8->pMeshItem = 0i64;
        v8 = v8->pNext;
      }
      while ( v8 != (Scaleform::Render::MeshCacheItemUseNode *)v9 );
    }
    v9->Root.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)v9;
    v4->PrimitiveBatches.Root.pNext = (Scaleform::Render::MeshCacheItemUseNode *)&v4->PrimitiveBatches;
  }
  v10 = v4->Type;
  if ( v10 )
  {
    if ( v10 == 1 )
    {
      v25 = *v4->pMeshes;
      if ( v25 != v7 )
      {
        v26 = v25->pProvider.pObject;
        v25[1].pPrev = 0i64;
        if ( v26 )
          ((void (*)(void))v26->vfptr->OnEvict)();
      }
    }
  }
  else
  {
    v11 = (Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *)v4->pCacheList->pCache;
    key = v4;
    Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::RemoveAlt<Scaleform::Render::MeshCacheItem *>(
      v11 + 19,
      &key);
    for ( i = 0; i < v4->MeshCount; ++i )
    {
      v13 = v4->pMeshes[i];
      if ( v13 != v7 )
        _InterlockedExchangeAdd(&v13->RefCount, 1u);
    }
    for ( j = 0; j < v4->MeshCount; ++j )
    {
      v15 = v4->pMeshes[j];
      if ( v15 != v7 )
      {
        v16 = (unsigned __int64)v15[1].vfptr;
        v17 = (signed __int64 *)&v15[1].RefCount;
        if ( v16 <= 2 )
          v18 = &v15[1].RefCount;
        else
          v18 = (_QWORD *)*v17;
        v19 = 0i64;
        if ( v16 )
        {
          while ( (Scaleform::Render::MeshCacheItem *)v18[v19] != v4 )
          {
            if ( ++v19 >= v16 )
              goto LABEL_24;
          }
          if ( v16 <= 2 )
            v20 = (signed __int64)&v15[1].RefCount;
          else
            v20 = *v17;
          memmove((void *)(v20 + 8 * v19), (const void *)(v20 + 8 * v19 + 8), 8 * (v16 - v19) - 8);
          if ( --v15[1].vfptr == (Scaleform::RefCountImplCoreVtbl *)2 )
          {
            v21 = *v17;
            *v17 = *(_QWORD *)*v17;
            v15[1].vfptr = *(Scaleform::Render::MeshStagingNodeVtbl **)(v21 + 8);
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          }
        }
LABEL_24:
        if ( !v15[1].vfptr && !v15->StagingBufferSize )
        {
          v22 = v15->pProvider.pObject;
          if ( v22 )
            v22->vfptr->OnEvict(v22, v15);
        }
      }
    }
    for ( k = 0; k < v4->MeshCount; ++k )
    {
      v24 = v4->pMeshes[k];
      if ( v24 != v7 && !_InterlockedDecrement(&v24->RefCount) && v24 )
        v24->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, 1u);
    }
  }
  v4->Type = 2;
  if ( v6 )
  {
    v27 = v4->GPUFence.pObject;
    if ( v27 )
    {
      v28 = v27->RefCount-- == 1;
      if ( v28 )
      {
        v29 = v27->Data;
        if ( v27->HasData )
        {
          v30 = v29->RSContext;
          ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v29->RSContext->FenceFrameAlloc.pHeapOrPtr)(
            v29,
            v29->APIHandle);
          v31 = v27->Data;
          v31->RSContext = (Scaleform::Render::RenderSync *)v30->FenceImplAlloc.FirstEmptySlot;
          v30->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v31;
          v27->Data = (Scaleform::Render::FenceImpl *)v30->FenceAlloc.FirstEmptySlot;
          v30->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v27;
        }
        else
        {
          v27->Data = (Scaleform::Render::FenceImpl *)v29[4].Parent;
          v29[4].Parent = (Scaleform::Render::FenceFrame *)v27;
        }
      }
    }
    v4->GPUFence.pObject = 0i64;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
}

// File Line: 228
// RVA: 0x971CB0
char __fastcall Scaleform::Render::MeshCacheListSet::EvictLRU(Scaleform::Render::MeshCacheListSet *this, Scaleform::Render::MeshCacheListSet::ListSlot *list, Scaleform::AllocAddr *a, unsigned __int64 size)
{
  Scaleform::Render::MeshCacheItem *v4; // rax
  unsigned __int64 v5; // rdi
  Scaleform::AllocAddr *v6; // rsi
  Scaleform::Render::MeshCacheListSet::ListSlot *v7; // rbx
  Scaleform::Render::MeshCacheListSet *v8; // r14

  v4 = list->Root.pPrev;
  v5 = size;
  v6 = a;
  v7 = list;
  v8 = this;
  if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev == list )
    return 0;
  while ( ((__int64 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))v8->pCache->vfptr[4].__vecDelDtor)(
            v8->pCache,
            v4,
            v6,
            0i64) < v5 )
  {
    v4 = v7->Root.pPrev;
    if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)v7->Root.pPrev == v7 )
      return 0;
  }
  return 1;
}

// File Line: 245
// RVA: 0x971D20
char __fastcall Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(Scaleform::Render::MeshCacheListSet *this, Scaleform::Render::MeshCacheListSet::ListSlot *list, Scaleform::AllocAddr *a, unsigned __int64 size, unsigned __int64 limit)
{
  Scaleform::Render::MeshCacheListSet::ListSlot *v5; // rbx
  Scaleform::Render::MeshCacheItem *v6; // rdx
  unsigned __int64 v7; // rsi
  Scaleform::AllocAddr *v8; // rbp
  Scaleform::Render::MeshCacheListSet *v9; // r14

  v5 = list;
  v6 = list->Root.pPrev;
  v7 = size;
  v8 = a;
  v9 = this;
  if ( v6 != (Scaleform::Render::MeshCacheItem *)v5 )
  {
    while ( v5->Size > limit )
    {
      if ( ((__int64 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))v9->pCache->vfptr[4].__vecDelDtor)(
             v9->pCache,
             v6,
             v8,
             0i64) >= v7 )
        return 1;
      v6 = v5->Root.pPrev;
      if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)v5->Root.pPrev == v5 )
        return 0;
    }
  }
  return 0;
}

// File Line: 260
// RVA: 0x971DA0
bool __fastcall Scaleform::Render::MeshCacheListSet::EvictPendingFree(Scaleform::Render::MeshCacheListSet *this, Scaleform::AllocAddr *a)
{
  char *v2; // rdi
  Scaleform::AllocAddr *v3; // rbp
  Scaleform::Render::MeshCacheListSet *v4; // rsi
  Scaleform::Render::MeshCacheListSet *v5; // rdx
  Scaleform::Render::MeshCacheItem *v6; // rbx

  v2 = (char *)&this->Slots[5];
  v3 = a;
  v4 = this;
  v5 = (Scaleform::Render::MeshCacheListSet *)this->Slots[5].Root.pNext;
  if ( v5 != (Scaleform::Render::MeshCacheListSet *)&this->Slots[5] )
  {
    do
    {
      v6 = v5->Slots[0].Root.pPrev;
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheListSet *, Scaleform::AllocAddr *, _QWORD))v4->pCache->vfptr[4].__vecDelDtor)(
        v4->pCache,
        v5,
        v3,
        0i64);
      v5 = (Scaleform::Render::MeshCacheListSet *)v6;
    }
    while ( v6 != (Scaleform::Render::MeshCacheItem *)v2 );
  }
  return 0;
}

// File Line: 279
// RVA: 0x971BD0
void __fastcall Scaleform::Render::MeshCacheListSet::EvictAll(Scaleform::Render::MeshCacheListSet *this)
{
  Scaleform::Render::MeshCacheListSet *v1; // rdi
  unsigned int v2; // ebp
  $A6A32721DD821860D2CFF437DFF6F231 *v3; // rbx
  signed __int64 v4; // rsi
  Scaleform::Render::MeshCacheItem *i; // rbx
  Scaleform::Render::Fence *v6; // rax
  Scaleform::Render::FenceImpl *v7; // r8

  v1 = this;
  v2 = 0;
  v3 = &this->Slots[0].Root.8;
  do
  {
    if ( v2 != 5 && ($A6A32721DD821860D2CFF437DFF6F231 *)v3->pNext != &v3[-1] )
    {
      do
        ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, _QWORD))v1->pCache->vfptr[4].__vecDelDtor)(
          v1->pCache,
          v3->pNext,
          0i64,
          0i64);
      while ( ($A6A32721DD821860D2CFF437DFF6F231 *)v3->pNext != &v3[-1] );
    }
    ++v2;
    v3 += 3;
  }
  while ( v2 < 6 );
  v4 = (signed __int64)&v1->Slots[5];
  while ( (Scaleform::Render::MeshCacheListSet::ListSlot *)v1->Slots[5].Root.pNext != &v1->Slots[5] )
  {
    for ( i = v1->Slots[5].Root.pNext; i != (Scaleform::Render::MeshCacheItem *)v4; i = v1->Slots[5].Root.pNext )
    {
      v6 = i->GPUFence.pObject;
      if ( v6 )
      {
        if ( v6->HasData )
        {
          v7 = v6->Data;
          if ( v6->Data )
          {
            if ( v7->Parent )
              ((void (__fastcall *)(Scaleform::Render::RenderSync *, _QWORD, unsigned __int64))v7->RSContext->vfptr[5].__vecDelDtor)(
                v7->RSContext,
                0i64,
                v7->APIHandle);
          }
        }
      }
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, _QWORD))v1->pCache->vfptr[4].__vecDelDtor)(
        v1->pCache,
        i,
        0i64,
        0i64);
    }
  }
}

// File Line: 311
// RVA: 0x970690
void __fastcall Scaleform::Render::MeshCacheListSet::EndFrame(Scaleform::Render::MeshCacheListSet *this)
{
  Scaleform::Render::MeshCacheListSet *v1; // rbx
  Scaleform::Render::MeshCacheItem *v2; // rax
  Scaleform::Render::MeshCacheListSet::ListSlot *v3; // rdx
  Scaleform::Render::MeshCacheItem *v4; // r8
  Scaleform::Render::MeshCacheItem *v5; // rcx
  Scaleform::Render::MeshCacheListSet::ListSlot *v6; // r8
  Scaleform::Render::MeshCacheItem *v7; // rax
  Scaleform::Render::MeshCacheItem *v8; // r9
  Scaleform::Render::MeshCacheItem *v9; // rcx

  v1 = this;
  if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)this->Slots[1].Root.pNext != &this->Slots[1] )
    Scaleform::Render::MeshCacheListSet::PushListToFront(this, MCL_PrevFrame, MCL_InFlight);
  v2 = v1->Slots[3].Root.pNext;
  v3 = &v1->Slots[3];
  if ( v2 != (Scaleform::Render::MeshCacheItem *)&v1->Slots[3] )
  {
    do
    {
      v2->ListType = 4;
      v2 = v2->pNext;
    }
    while ( v2 != (Scaleform::Render::MeshCacheItem *)v3 );
  }
  v4 = v1->Slots[3].Root.pNext;
  if ( v4 != (Scaleform::Render::MeshCacheItem *)v3 )
  {
    v5 = v3->Root.pPrev;
    v1->Slots[3].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v1->Slots[3];
    v3->Root.pPrev = (Scaleform::Render::MeshCacheItem *)v3;
    v5->pNext = v1->Slots[4].Root.pNext;
    v4->pPrev = (Scaleform::Render::MeshCacheItem *)&v1->Slots[4];
    v1->Slots[4].Root.pNext->pPrev = v5;
    v1->Slots[4].Root.pNext = v4;
  }
  v6 = &v1->Slots[2];
  v1->Slots[4].Size += v1->Slots[3].Size;
  v1->Slots[3].Size = 0i64;
  v7 = v1->Slots[2].Root.pNext;
  if ( v7 != (Scaleform::Render::MeshCacheItem *)&v1->Slots[2] )
  {
    do
    {
      v7->ListType = 3;
      v7 = v7->pNext;
    }
    while ( v7 != (Scaleform::Render::MeshCacheItem *)v6 );
  }
  v8 = v1->Slots[2].Root.pNext;
  if ( v8 != (Scaleform::Render::MeshCacheItem *)v6 )
  {
    v9 = v6->Root.pPrev;
    v1->Slots[2].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v1->Slots[2];
    v6->Root.pPrev = (Scaleform::Render::MeshCacheItem *)v6;
    v9->pNext = v1->Slots[3].Root.pNext;
    v8->pPrev = (Scaleform::Render::MeshCacheItem *)v3;
    v1->Slots[3].Root.pNext->pPrev = v9;
    v1->Slots[3].Root.pNext = v8;
  }
  v1->Slots[3].Size += v1->Slots[2].Size;
  v1->Slots[2].Size = 0i64;
}

// File Line: 353
// RVA: 0x95A950
bool __fastcall Scaleform::Render::MeshVertexOutput::BeginOutput(Scaleform::Render::MeshVertexOutput *this, Scaleform::Render::VertexOutput::Fill *fills, unsigned int fillCount, Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  Scaleform::Render::Mesh *v4; // rbp
  Scaleform::Render::Mesh **v5; // r14
  Scaleform::Render::Matrix2x4<float> *v6; // rdi
  Scaleform::Render::VertexOutput::Fill *v7; // rsi
  Scaleform::Render::MeshVertexOutput *v8; // rbx
  Scaleform::Render::VertexFormat *v9; // r8
  char v10; // al
  signed int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // er11
  int v14; // eax
  Scaleform::Render::MeshCacheItem *v15; // r8
  Scaleform::Render::MeshCache *v16; // rcx
  Scaleform::Render::Matrix2x4<float> *v17; // rdx
  Scaleform::Render::Mesh **v19; // [rsp+60h] [rbp-38h]
  __int64 v20; // [rsp+68h] [rbp-30h]
  __int64 v21; // [rsp+70h] [rbp-28h]
  int v22; // [rsp+78h] [rbp-20h]

  v4 = this->pMesh;
  v5 = &this->pMesh;
  v6 = vertexMatrix;
  v7 = fills;
  v8 = this;
  if ( !v4->LargeMesh )
  {
    v9 = this->pBatchFormat;
    if ( v9 )
    {
      if ( v9->Size * fills->VertexCount <= this->pCache->Params.NoBatchVerticesSizeThreshold )
      {
LABEL_6:
        v10 = Scaleform::Render::MeshStagingBuffer::AllocateMesh(
                &this->pCache->StagingBuffer,
                v4,
                fills->VertexCount,
                this->pSourceFormat->Size,
                fills->IndexCount);
        v11 = 2;
        if ( v10 )
          v11 = 0;
        v8->Result.Value = v11;
        goto LABEL_17;
      }
    }
    else if ( !this->pSingleFormat )
    {
      goto LABEL_6;
    }
  }
  v12 = fills->VertexCount;
  v19 = &this->pMesh;
  v20 = 1i64;
  v21 = 8i64;
  v22 = (unsigned __int64)v4 >> 5;
  v13 = this->pSingleFormat->Size;
  v4->VertexCount = v12;
  (*v5)->IndexCount = v7->IndexCount;
  (*v5)->LargeMesh = 1;
  v14 = ((__int64 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem **, char **, unsigned __int16 **, _DWORD, Scaleform::Render::Mesh ***, _QWORD, unsigned int, unsigned int, bool, Scaleform::Render::VertexFormat *))this->pCache->vfptr[6].__vecDelDtor)(
          this->pCache,
          &this->BatchData,
          &this->pVertexDataStart,
          &this->pIndexDataStart,
          0,
          &v19,
          v12 * v13,
          v7->VertexCount,
          v7->IndexCount,
          this->WaitForCache,
          this->pSingleFormat);
  if ( v14 == 3 )
  {
    v15 = v8->BatchData;
    v16 = v8->pCache;
    v8->Result.Value = 1;
    Scaleform::Render::MeshCache::MoveToCacheListFront(v16, MCL_ThisFrame, v15);
  }
  else if ( v14 )
  {
    if ( v14 == 1 )
    {
      v8->Result.Value = 5;
    }
    else if ( v14 == 2 )
    {
      v8->Result.Value = 7;
    }
  }
  else
  {
    v8->Result.Value = 3;
  }
LABEL_17:
  v17 = &(*v5)->VertexMatrix;
  v17->M[0][0] = v6->M[0][0];
  v17->M[0][1] = v6->M[0][1];
  v17->M[0][2] = v6->M[0][2];
  v17->M[0][3] = v6->M[0][3];
  v17->M[1][0] = v6->M[1][0];
  v17->M[1][1] = v6->M[1][1];
  v17->M[1][2] = v6->M[1][2];
  v17->M[1][3] = v6->M[1][3];
  return v8->Result.Value <= 1;
}

// File Line: 421
// RVA: 0x970B20
void __fastcall Scaleform::Render::MeshVertexOutput::EndOutput(Scaleform::Render::MeshVertexOutput *this)
{
  if ( this->Result.Value & 1 )
    ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *))this->pCache->vfptr[6].UnlockBuffers)(
      this->pCache,
      this->BatchData);
}

// File Line: 430
// RVA: 0x9B5750
void __fastcall Scaleform::Render::MeshVertexOutput::SetVertices(Scaleform::Render::MeshVertexOutput *this, unsigned int fillIndex, unsigned int vertexOffset, void *vertices, unsigned int vertexCount)
{
  if ( !fillIndex && this->Result.Value <= 1 )
  {
    if ( this->Result.Value & 1 )
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::Render::VertexFormat *, _QWORD, void *, unsigned int, Scaleform::Render::VertexFormat *, char *))this->pCache->vfptr[5].__vecDelDtor)(
        this->pCache,
        this->BatchData,
        this->pSourceFormat,
        vertexOffset,
        vertices,
        vertexCount,
        this->pSingleFormat,
        this->pVertexDataStart);
    else
      memmove(
        &this->pCache->StagingBuffer.pBuffer[vertexOffset * this->pSourceFormat->Size + this->pMesh->StagingBufferOffset],
        vertices,
        vertexCount * this->pSourceFormat->Size);
  }
}

// File Line: 457
// RVA: 0x9B0D10
void __fastcall Scaleform::Render::MeshVertexOutput::SetIndices(Scaleform::Render::MeshVertexOutput *this, unsigned int fillIndex, unsigned int indexOffset, unsigned __int16 *indices, unsigned int indexCount)
{
  if ( !fillIndex && this->Result.Value <= 1 )
  {
    if ( this->Result.Value & 1 )
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::Render::VertexFormat *, _QWORD, unsigned __int16 *, unsigned int, Scaleform::Render::VertexFormat *, unsigned __int16 *))this->pCache->vfptr[5].UnlockBuffers)(
        this->pCache,
        this->BatchData,
        this->pSourceFormat,
        indexOffset,
        indices,
        indexCount,
        this->pSingleFormat,
        this->pIndexDataStart);
    else
      memmove(
        &this->pCache->StagingBuffer.pBuffer[2 * indexOffset + this->pMesh->StagingBufferIndexOffset],
        indices,
        2i64 * indexCount);
  }
}

// File Line: 512
// RVA: 0x94B920
void __fastcall Scaleform::Render::MeshStagingBuffer::~MeshStagingBuffer(Scaleform::Render::MeshStagingBuffer *this)
{
  Scaleform::Render::MeshStagingBuffer::Reset(this);
}

// File Line: 517
// RVA: 0x9941F0
bool __fastcall Scaleform::Render::MeshStagingBuffer::Initialize(Scaleform::Render::MeshStagingBuffer *this, Scaleform::MemoryHeap *pheap, unsigned __int64 size)
{
  unsigned __int64 v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::Render::MeshStagingBuffer *v5; // rbx
  __int64 v6; // rax

  v3 = size;
  v4 = pheap;
  v5 = this;
  if ( this->pBuffer && size != this->BufferSize )
    Scaleform::Render::MeshStagingBuffer::Reset(this);
  v6 = (__int64)v4->vfptr->Alloc(v4, v3, 0i64);
  v5->pBuffer = (char *)v6;
  if ( v6 )
  {
    v5->BufferSize = v3;
    v5->PinSizeLimit = v3 >> 1;
    v5->TotalPinnedSize = 0i64;
    LOBYTE(v6) = 1;
  }
  return v6;
}

// File Line: 530
// RVA: 0x9AB950
void __fastcall Scaleform::Render::MeshStagingBuffer::Reset(Scaleform::Render::MeshStagingBuffer *this)
{
  Scaleform::Render::MeshStagingBuffer *v1; // rdi
  Scaleform::List<Scaleform::Render::MeshStagingNode,Scaleform::Render::MeshStagingNode> *v2; // rbx
  signed __int64 v3; // rax
  Scaleform::Render::MeshStagingNode *v4; // rcx

  v1 = this;
  if ( this->pBuffer )
  {
    v2 = &this->MeshList;
    while ( 1 )
    {
      v3 = (signed __int64)&v2[-1].Root.8;
      if ( !v2 )
        v3 = 0i64;
      if ( v2->Root.pNext == (Scaleform::Render::MeshStagingNode *)v3 )
        break;
      v4 = v1->MeshList.Root.pNext;
      v4->StagingBufferOffset = 0i64;
      v4->StagingBufferIndexOffset = 0i64;
      v4->pPrev->pNext = v4->pNext;
      v4->pNext->pPrev = v4->pPrev;
      v4->pPrev = (Scaleform::Render::MeshStagingNode *)-1i64;
      v4->pNext = (Scaleform::Render::MeshStagingNode *)-1i64;
      ((void (*)(void))v4->vfptr->OnStagingNodeEvict)();
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->pBuffer);
    v1->pBuffer = 0i64;
    v1->BufferSize = 0i64;
    v1->TotalPinnedSize = 0i64;
  }
}

// File Line: 556
// RVA: 0x958040
char __fastcall Scaleform::Render::MeshStagingBuffer::AllocateBufferSpace(Scaleform::Render::MeshStagingBuffer *this, unsigned __int64 *poffset, unsigned __int64 size)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 *v4; // r15
  Scaleform::Render::MeshStagingBuffer *v5; // r14
  Scaleform::List<Scaleform::Render::MeshStagingNode,Scaleform::Render::MeshStagingNode> *v7; // rdi
  signed __int64 v8; // rax
  Scaleform::Render::MeshStagingNode *v9; // rbx
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rsi

  v3 = size;
  v4 = poffset;
  v5 = this;
  if ( size > this->PinSizeLimit )
    return 0;
  v7 = &this->MeshList;
  while ( 1 )
  {
    v8 = (signed __int64)(v7 ? &v7[-1].Root.8 : 0i64);
    if ( v7->Root.pNext == (Scaleform::Render::MeshStagingNode *)v8 )
      break;
    v9 = v7->Root.pPrev;
    v10 = v7->Root.pPrev->StagingBufferOffset;
    v11 = v5->MeshList.Root.pNext->StagingBufferSize + v5->MeshList.Root.pNext->StagingBufferOffset;
    if ( v11 > v10 )
    {
      if ( v5->BufferSize - v11 >= v3 )
      {
        *v4 = v11;
        return 1;
      }
      v12 = v7->Root.pPrev->StagingBufferOffset;
    }
    else
    {
      v12 = v10 - v11;
    }
    if ( v12 >= v3 )
    {
      *v4 = v10 - v12;
      return 1;
    }
    v9->pPrev->pNext = v9->pNext;
    v9->pNext->pPrev = v9->pPrev;
    v9->pPrev = (Scaleform::Render::MeshStagingNode *)-1i64;
    v9->pNext = (Scaleform::Render::MeshStagingNode *)-1i64;
    if ( v9->PinCount )
    {
      if ( v12 )
      {
        memmove(
          &v5->pBuffer[v9->StagingBufferOffset - v12],
          &v5->pBuffer[v9->StagingBufferOffset],
          v9->StagingBufferSize);
        v9->StagingBufferIndexOffset -= v12;
        v9->StagingBufferOffset -= v12;
      }
      v9->pNext = v7->Root.pNext;
      v9->pPrev = (Scaleform::Render::MeshStagingNode *)&v7[-1].Root.8;
      v7->Root.pNext->pPrev = v9;
      v7->Root.pNext = v9;
    }
    else
    {
      v9->vfptr->OnStagingNodeEvict(v9);
    }
  }
  *v4 = 0i64;
  return 1;
}

// File Line: 623
// RVA: 0x958360
char __fastcall Scaleform::Render::MeshStagingBuffer::AllocateMesh(Scaleform::Render::MeshStagingBuffer *this, Scaleform::Render::Mesh *pmesh, unsigned __int64 vertexCount, unsigned __int64 vertexSize, unsigned __int64 indexCount)
{
  unsigned int v5; // er15
  Scaleform::Render::Mesh *v6; // rbx
  unsigned int v7; // er14
  unsigned __int64 v8; // rsi
  Scaleform::Render::MeshStagingBuffer *v9; // rdi
  unsigned __int64 v10; // rbp
  char result; // al
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v5 = indexCount;
  v6 = pmesh;
  v7 = vertexCount;
  v8 = vertexSize * vertexCount;
  v9 = this;
  v10 = (vertexSize * vertexCount + 2 * indexCount + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  result = Scaleform::Render::MeshStagingBuffer::AllocateBufferSpace(this, &indexCount, v10);
  if ( result )
  {
    v12 = indexCount;
    v6->StagingBufferSize = v10;
    v6->VertexCount = v7;
    v6->StagingBufferOffset = v12;
    v6->IndexCount = v5;
    v6->StagingBufferIndexOffset = v8 + v12;
    v13 = (signed __int64)&v6->vfptr;
    *(_QWORD *)(v13 + 16) = v9->MeshList.Root.pNext;
    *(_QWORD *)(v13 + 8) = (char *)v9 + 24;
    v9->MeshList.Root.pNext->pPrev = (Scaleform::Render::MeshStagingNode *)&v6->vfptr;
    v9->MeshList.Root.pNext = (Scaleform::Render::MeshStagingNode *)&v6->vfptr;
    result = 1;
  }
  return result;
}

// File Line: 661
// RVA: 0x9447F0
void __fastcall Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(Scaleform::Render::MeshCache::StagingBufferPrep *this, Scaleform::Render::MeshCache *cache, Scaleform::Render::MeshCacheItem::MeshContent *mc, Scaleform::Render::VertexFormat *format, bool canCopyData)
{
  Scaleform::Render::MeshCache::StagingBufferPrep *v5; // rbx
  unsigned int v6; // ecx
  bool *v7; // rax
  __int64 v8; // r9
  __int64 v9; // r8
  __int64 v10; // rcx

  v5 = this;
  this->pCache = cache;
  this->MC = mc;
  this->PinMeshes = 1;
  this->pVertexFormat = format;
  this->CanCopyData = canCopyData;
  v6 = mc->Meshes.Size;
  if ( v6 )
  {
    v7 = v5->PinnedFlagArray;
    v8 = v6;
    do
    {
      v9 = *(__int64 *)((char *)v5->MC->Meshes.pData + v5->MC->Meshes.StrideSize * (_QWORD)&v7[-32i64 - (_QWORD)v5]);
      v10 = *(_QWORD *)(v9 + 40);
      if ( v10 )
      {
        if ( !*(_DWORD *)(v9 + 64) )
          cache->StagingBuffer.TotalPinnedSize += v10;
        ++*(_DWORD *)(v9 + 64);
        *v7 = 1;
      }
      else
      {
        *v7 = 0;
      }
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  Scaleform::Render::MeshCache::StagingBufferPrep::GenerateMeshes(v5, 0i64);
}

// File Line: 688
// RVA: 0x97EFC0
void __fastcall Scaleform::Render::MeshCache::StagingBufferPrep::GenerateMeshes(Scaleform::Render::MeshCache::StagingBufferPrep *this, Scaleform::Render::MeshCacheItem *skipBatch)
{
  Scaleform::Render::MeshCacheItem::MeshContent *v2; // rax
  Scaleform::Render::MeshCache::StagingBufferPrep *v3; // rdi
  unsigned int v4; // ecx
  Scaleform::Render::MeshCache *v5; // r14
  Scaleform::Render::MeshCacheItem *v6; // r12
  __int64 v7; // rsi
  __int64 v8; // rbp
  Scaleform::Render::Mesh *v9; // rbx
  unsigned __int64 v10; // rax
  __int64 v11; // rbp
  Scaleform::Render::Mesh *v12; // rbx
  Scaleform::Render::MeshCache::MeshResult result; // [rsp+70h] [rbp+8h]

  v2 = this->MC;
  v3 = this;
  v4 = v2->Meshes.Size;
  v5 = v3->pCache;
  v6 = skipBatch;
  v7 = 0i64;
  if ( v3->CanCopyData )
  {
    if ( v4 )
    {
      v8 = v4;
      do
      {
        v9 = *(Scaleform::Render::Mesh **)((char *)v3->MC->Meshes.pData + v7 * v3->MC->Meshes.StrideSize);
        if ( !v3->PinnedFlagArray[v7] )
        {
          v10 = v9->CacheItems.Size;
          if ( !v10 || v10 == 1 && (Scaleform::Render::MeshCacheItem *)v9->CacheItems.AD.pData == v6 )
          {
            if ( !v9->StagingBufferSize )
              Scaleform::Render::MeshCache::GenerateMesh(v3->pCache, &result, v9, v3->pVertexFormat, 0i64, 0i64, 0);
            if ( v3->PinMeshes || !v9->PinCount )
            {
              if ( !v9->PinCount )
                v5->StagingBuffer.TotalPinnedSize += v9->StagingBufferSize;
              ++v9->PinCount;
            }
          }
        }
        ++v7;
        --v8;
      }
      while ( v8 );
      v3->PinMeshes = 0;
      return;
    }
LABEL_29:
    v3->PinMeshes = 0;
    return;
  }
  if ( !v4 )
    goto LABEL_29;
  v11 = LODWORD(v2->Meshes.Size);
  do
  {
    if ( !v3->PinnedFlagArray[v7] )
    {
      v12 = *(Scaleform::Render::Mesh **)((char *)v3->MC->Meshes.pData + v7 * v3->MC->Meshes.StrideSize);
      if ( !v12->StagingBufferSize )
        Scaleform::Render::MeshCache::GenerateMesh(v3->pCache, &result, v12, v3->pVertexFormat, 0i64, 0i64, 0);
      if ( v3->PinMeshes || !v12->PinCount )
      {
        if ( !v12->PinCount )
          v5->StagingBuffer.TotalPinnedSize += v12->StagingBufferSize;
        ++v12->PinCount;
      }
    }
    ++v7;
    --v11;
  }
  while ( v11 );
  v3->PinMeshes = 0;
}

// File Line: 743
// RVA: 0x94CDB0
void __fastcall Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(Scaleform::Render::MeshCache::StagingBufferPrep *this)
{
  Scaleform::Render::MeshCacheItem::MeshContent *v1; // rax
  Scaleform::Render::MeshCache *v2; // r9
  unsigned int v3; // er8
  __int64 v4; // rax
  bool v5; // zf

  v1 = this->MC;
  v2 = this->pCache;
  v3 = 0;
  if ( LODWORD(v1->Meshes.Size) )
  {
    do
    {
      if ( (*(Scaleform::Render::MeshBase **)((char *)v1->Meshes.pData + v3 * v1->Meshes.StrideSize))->StagingBufferSize )
      {
        v4 = *(__int64 *)((char *)v1->Meshes.pData + v3 * v1->Meshes.StrideSize);
        v5 = (*(_DWORD *)(v4 + 64))-- == 1;
        if ( v5 )
          v2->StagingBuffer.TotalPinnedSize -= *(_QWORD *)(v4 + 40);
      }
      v1 = this->MC;
      ++v3;
    }
    while ( v3 < LODWORD(v1->Meshes.Size) );
  }
}

// File Line: 776
// RVA: 0x95A830
bool __fastcall Scaleform::Render::ComplexMeshVertexOutput::BeginOutput(Scaleform::Render::ComplexMeshVertexOutput *this, Scaleform::Render::VertexOutput::Fill *fills, unsigned int fillCount, Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  Scaleform::Render::ComplexMesh **v4; // rbx
  Scaleform::Render::ComplexMeshVertexOutput *v5; // rdi
  Scaleform::Render::VertexOutput::Fill *v6; // rbp
  bool v7; // zf
  Scaleform::Render::ComplexMesh *v8; // rax
  bool result; // al
  Scaleform::Render::MeshCache *v10; // rcx
  bool v11; // al
  Scaleform::Render::MeshCache::AllocResult v12; // eax
  Scaleform::Render::HAL *hal; // [rsp+20h] [rbp-88h]
  __int64 v14; // [rsp+38h] [rbp-70h]
  int v15; // [rsp+60h] [rbp-48h]
  __int64 v16; // [rsp+68h] [rbp-40h]
  char v17; // [rsp+70h] [rbp-38h]
  Scaleform::Render::ComplexMesh **v18; // [rsp+78h] [rbp-30h]
  __int64 v19; // [rsp+80h] [rbp-28h]
  __int64 v20; // [rsp+88h] [rbp-20h]
  int v21; // [rsp+90h] [rbp-18h]
  int v22; // [rsp+B0h] [rbp+8h]

  v4 = &this->pMesh;
  v5 = this;
  v6 = fills;
  v7 = Scaleform::Render::ComplexMesh::InitFillRecords(
         this->pMesh,
         fills,
         fillCount,
         vertexMatrix,
         this->pHAL,
         (unsigned __int64 *)&v16,
         (unsigned int *)&v15,
         (unsigned int *)&v22) == 0;
  v8 = *v4;
  if ( v7 )
  {
    v8->AllocTooBig = 1;
    result = 0;
  }
  else
  {
    v10 = v5->pCache;
    v18 = v4;
    v21 = (unsigned __int64)v8 >> 5;
    v11 = v5->WaitForCache;
    v19 = 1i64;
    v20 = 8i64;
    LODWORD(v14) = v15;
    LODWORD(hal) = 1;
    v12 = ((unsigned int (__fastcall *)(Scaleform::Render::MeshCache *, char *, char **, unsigned __int16 **, Scaleform::Render::HAL *, Scaleform::Render::ComplexMesh ***, __int64, __int64, int, bool, _QWORD))v10->vfptr[6].__vecDelDtor)(
            v10,
            &v17,
            &v5->pVertexDataStart,
            &v5->pIndexDataStart,
            hal,
            &v18,
            v16,
            v14,
            v22,
            v11,
            0i64);
    v5->AllocState = v12;
    v5->pFills = v6;
    if ( v12 == 1 )
      (*v4)->AllocTooBig = 1;
    result = v5->AllocState == 3;
  }
  return result;
}

// File Line: 803
// RVA: 0x970B00
void __fastcall Scaleform::Render::ComplexMeshVertexOutput::EndOutput(Scaleform::Render::ComplexMeshVertexOutput *this)
{
  ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *))this->pCache->vfptr[6].UnlockBuffers)(
    this->pCache,
    this->pMesh->pCacheMeshItem);
}

// File Line: 809
// RVA: 0x9B56F0
void __fastcall Scaleform::Render::ComplexMeshVertexOutput::SetVertices(Scaleform::Render::ComplexMeshVertexOutput *this, unsigned int fillIndex, unsigned int vertexOffset, void *vertices, unsigned int vertexCount)
{
  __int64 v5; // r10
  Scaleform::Render::ComplexMesh::FillRecord *v6; // rdx

  if ( this->AllocState == 3 )
  {
    v5 = fillIndex;
    v6 = &this->pMesh->FillRecords.Data.Data[fillIndex];
    Scaleform::Render::ConvertVertices_Buffered(
      this->pFills[v5].pFormat,
      vertices,
      v6->pFormats[0],
      &this->pVertexDataStart[v6->VertexByteOffset + v6->pFormats[0]->Size * vertexOffset],
      vertexCount,
      0i64);
  }
}

// File Line: 826
// RVA: 0x9B0CD0
void __fastcall Scaleform::Render::ComplexMeshVertexOutput::SetIndices(Scaleform::Render::ComplexMeshVertexOutput *this, unsigned int fillIndex, unsigned int indexOffset, unsigned __int16 *indices, unsigned int indexCount)
{
  if ( this->AllocState == 3 )
    memmove(
      &this->pIndexDataStart[indexOffset + (unsigned __int64)this->pMesh->FillRecords.Data.Data[fillIndex].IndexOffset],
      indices,
      2i64 * indexCount);
}

// File Line: 855
// RVA: 0x93FA30
void __fastcall Scaleform::Render::MeshCache::MeshCache(Scaleform::Render::MeshCache *this, Scaleform::MemoryHeap *pheap, Scaleform::Render::MeshCacheParams *params)
{
  Scaleform::Render::MeshStagingNode *v3; // rax

  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
  this->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCacheConfig::`vftable;
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::CacheBase};
  this->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::MeshCacheConfig};
  this->pHeap = pheap;
  this->pRQCaches = 0i64;
  this->Params.MemReserve = params->MemReserve;
  this->Params.MemLimit = params->MemLimit;
  this->Params.MemGranularity = params->MemGranularity;
  this->Params.LRUTailSize = params->LRUTailSize;
  this->Params.StagingBufferSize = params->StagingBufferSize;
  this->Params.VBLockEvictSizeLimit = params->VBLockEvictSizeLimit;
  this->Params.MaxBatchInstances = params->MaxBatchInstances;
  this->Params.InstancingThreshold = params->InstancingThreshold;
  this->Params.NoBatchVerticesSizeThreshold = params->NoBatchVerticesSizeThreshold;
  this->Params.MaxVerticesSizeInBatch = params->MaxVerticesSizeInBatch;
  this->Params.MaxIndicesInBatch = params->MaxIndicesInBatch;
  this->StagingBuffer.pBuffer = 0i64;
  this->StagingBuffer.BufferSize = 0i64;
  this->StagingBuffer.TotalPinnedSize = 0i64;
  this->StagingBuffer.PinSizeLimit = 0i64;
  v3 = (Scaleform::Render::MeshStagingNode *)&this->StagingBuffer.PinSizeLimit;
  if ( this == (Scaleform::Render::MeshCache *)-136i64 )
    v3 = 0i64;
  this->StagingBuffer.MeshList.Root.pPrev = v3;
  this->StagingBuffer.MeshList.Root.pNext = v3;
  this->BatchCacheItemHash.pTable = 0i64;
}

// File Line: 861
// RVA: 0x94B680
void __fastcall Scaleform::Render::MeshCache::~MeshCache(Scaleform::Render::MeshCache *this)
{
  Scaleform::Render::MeshCache *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::CacheBase};
  this->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::MeshCacheConfig};
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->BatchCacheItemHash);
  Scaleform::Render::MeshStagingBuffer::Reset(&v1->StagingBuffer);
  v1->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCacheConfig::`vftable;
  v1->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
}

// File Line: 884
// RVA: 0x987CE0
signed __int64 __fastcall Scaleform::Render::MeshCache::GetItemUseStatus(Scaleform::Render::MeshCache *this, Scaleform::Render::MeshCacheItem *item)
{
  switch ( item->ListType )
  {
    case 1:
      return 4i64;
    case 2:
      return 3i64;
    case 3:
      return 2i64;
  }
  return item->ListType == 4;
}

// File Line: 907
// RVA: 0x97EF00
Scaleform::Render::MeshCache::MeshResult *__fastcall Scaleform::Render::MeshCache::GenerateMesh(Scaleform::Render::MeshCache *this, Scaleform::Render::MeshCache::MeshResult *result, Scaleform::Render::Mesh *mesh, Scaleform::Render::VertexFormat *sourceFormat, Scaleform::Render::VertexFormat *singleFormat, Scaleform::Render::VertexFormat *batchFormat, bool waitForCache)
{
  Scaleform::Render::MeshCache::MeshResult *v7; // rbx
  void **v9; // [rsp+30h] [rbp-68h]
  Scaleform::Render::MeshCache *v10; // [rsp+38h] [rbp-60h]
  bool v11; // [rsp+40h] [rbp-58h]
  Scaleform::Render::Mesh *v12; // [rsp+48h] [rbp-50h]
  Scaleform::Render::VertexFormat *v13; // [rsp+50h] [rbp-48h]
  Scaleform::Render::VertexFormat *v14; // [rsp+58h] [rbp-40h]
  Scaleform::Render::VertexFormat *v15; // [rsp+60h] [rbp-38h]
  Scaleform::Render::MeshCache::MeshResult::ResultType v16; // [rsp+68h] [rbp-30h]
  __int128 v17; // [rsp+70h] [rbp-28h]
  __int64 v18; // [rsp+80h] [rbp-18h]

  v7 = result;
  v9 = &Scaleform::Render::MeshVertexOutput::`vftable;
  v10 = this;
  v11 = waitForCache;
  v12 = mesh;
  v13 = sourceFormat;
  v14 = singleFormat;
  v15 = batchFormat;
  v16 = 6;
  _mm_store_si128((__m128i *)&v17, (__m128i)0i64);
  v18 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::Mesh *, void ***, _QWORD, signed __int64))mesh->pProvider.pObject->vfptr->GetData)(
    mesh->pProvider.pObject,
    mesh,
    &v9,
    mesh->MGFlags,
    -2i64);
  v7->Value = v16;
  return v7;
}

// File Line: 918
// RVA: 0x99FAA0
char __fastcall Scaleform::Render::MeshCache::PrepareComplexMesh(Scaleform::Render::MeshCache *this, Scaleform::Render::ComplexMesh *mesh, bool waitForCache)
{
  Scaleform::Render::ComplexMesh *v3; // rbx
  Scaleform::Render::MeshCache *v4; // rdi
  Scaleform::Render::HAL *v5; // rcx
  char result; // al
  Scaleform::Render::MeshCacheItem *v7; // r8
  void **v8; // [rsp+30h] [rbp-58h]
  Scaleform::Render::ComplexMesh *v9; // [rsp+38h] [rbp-50h]
  Scaleform::Render::MeshCache *v10; // [rsp+40h] [rbp-48h]
  Scaleform::Render::HAL *v11; // [rsp+48h] [rbp-40h]
  bool v12; // [rsp+50h] [rbp-38h]
  int v13; // [rsp+60h] [rbp-28h]

  v3 = mesh;
  v4 = this;
  if ( mesh && !mesh->AllocTooBig )
  {
    if ( !mesh->pCacheMeshItem )
    {
      v5 = mesh->pFillManager->pHAL;
      v8 = &Scaleform::Render::ComplexMeshVertexOutput::`vftable;
      v9 = mesh;
      v10 = v4;
      v11 = v5;
      v12 = waitForCache;
      v13 = 4;
      ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::ComplexMesh *, void ***, _QWORD, signed __int64))mesh->pProvider.pObject->vfptr->GetData)(
        mesh->pProvider.pObject,
        mesh,
        &v8,
        mesh->MGFlags,
        -2i64);
      result = v13;
      if ( !v13 )
      {
LABEL_7:
        v8 = &Scaleform::Render::VertexOutput::`vftable;
        return result;
      }
      if ( v13 != 3 )
      {
        result = 1;
        goto LABEL_7;
      }
      v8 = &Scaleform::Render::VertexOutput::`vftable;
    }
    v7 = v3->pCacheMeshItem;
    if ( v7 )
      Scaleform::Render::MeshCache::MoveToCacheListFront(v4, MCL_InFlight, v7);
  }
  return 1;
}

// File Line: 952
// RVA: 0x9B0F00
char __fastcall Scaleform::Render::MeshCache::SetLargeMeshVertices(Scaleform::Render::MeshCache *this, Scaleform::Render::MeshCacheItem *pcacheItem, Scaleform::Render::VertexFormat *pSourceFormat, unsigned __int64 vertexOffset, char *pvertices, unsigned int vertexCount, Scaleform::Render::VertexFormat *pDestFormat, char *pdestStart)
{
  Scaleform::Render::ConvertVertices_Buffered(
    pSourceFormat,
    pvertices,
    pDestFormat,
    &pdestStart[pDestFormat->Size * vertexOffset],
    vertexCount,
    0i64);
  return 1;
}

// File Line: 963
// RVA: 0x9B0ED0
char __fastcall Scaleform::Render::MeshCache::SetLargeMeshIndices(Scaleform::Render::MeshCache *this, Scaleform::Render::MeshCacheItem *pcacheItem, Scaleform::Render::VertexFormat *pSourceFormat, unsigned __int64 indexOffset, const unsigned __int16 *pindices, unsigned int indexCount, Scaleform::Render::VertexFormat *pDestFormat, char *pdestIndex)
{
  memmove(&pdestIndex[2 * indexOffset], pindices, 2i64 * indexCount);
  return 1;
}

