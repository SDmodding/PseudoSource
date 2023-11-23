// File Line: 29
// RVA: 0x9B1DF0
void __fastcall Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(
        Scaleform::Render::MeshCacheItemUseNode *this,
        Scaleform::Render::MeshCacheItem *p)
{
  if ( this->pMeshItem )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItemUseNode>::$EC3A7FD70C0432BB4721D332D43CF72A::pPrev = this->pPrev;
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
Scaleform::Render::MeshCacheItem *__fastcall Scaleform::Render::MeshCacheItem::Create(
        Scaleform::Render::MeshCacheItem::MeshType type,
        Scaleform::Render::MeshCacheListSet *pcacheList,
        unsigned __int64 classSize,
        Scaleform::Render::MeshCacheItem::MeshBaseContent *content,
        unsigned __int64 allocSize,
        unsigned int vertexCount,
        unsigned int indexCount)
{
  Scaleform::Render::MeshCache *pCache; // r13
  __int64 Size_low; // rsi
  unsigned __int64 v11; // rdi
  __int64 v13; // r15
  Scaleform::Render::MeshCacheItem *result; // rax
  Scaleform::Render::MeshCacheItem *v15; // rbx
  __int64 v16; // r8
  __int64 v17; // r9
  Scaleform::Render::MeshBase *v18; // rax
  __int64 v19; // rdi
  __int64 v20; // r8
  unsigned __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *inserted; // rax
  Scaleform::Render::MeshCacheItem *key; // [rsp+58h] [rbp+10h] BYREF

  pCache = pcacheList->pCache;
  Size_low = LODWORD(content->Meshes.Size);
  v11 = (classSize + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  v13 = Size_low;
  result = (Scaleform::Render::MeshCacheItem *)pcacheList->pCache->pHeap->vfptr->Alloc(
                                                 pcacheList->pCache->pHeap,
                                                 v11 + 8 * Size_low,
                                                 0i64);
  v15 = result;
  key = result;
  if ( result )
  {
    result->Type = type;
    result->pCacheList = pcacheList;
    result->HashKey = content->HashKey;
    v16 = 0i64;
    result->MeshCount = Size_low;
    result->pMeshes = (Scaleform::Render::MeshBase **)((char *)result + v11);
    if ( (_DWORD)Size_low )
    {
      v17 = Size_low;
      do
      {
        v18 = *(Scaleform::Render::MeshBase **)((char *)content->Meshes.pData + v16 * content->Meshes.StrideSize);
        v15->pMeshes[v16++] = v18;
        --v17;
      }
      while ( v17 );
    }
    v15->PrimitiveBatches.Root.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)&v15->PrimitiveBatches;
    v15->PrimitiveBatches.Root.pNext = (Scaleform::Render::MeshCacheItemUseNode *)&v15->PrimitiveBatches;
    v15->AllocSize = allocSize;
    v15->VertexCount = vertexCount;
    v15->IndexCount = indexCount;
    v15->GPUFence.pObject = 0i64;
    if ( type )
    {
      (*v15->pMeshes)[1].pPrev = (Scaleform::Render::MeshStagingNode *)v15;
    }
    else
    {
      v19 = 0i64;
      if ( (_DWORD)Size_low )
      {
        do
        {
          v20 = *(__int64 *)((char *)content->Meshes.pData + v19 * content->Meshes.StrideSize);
          v21 = *(_QWORD *)(v20 + 160);
          if ( v21 <= 2 )
            v22 = v20 + 168;
          else
            v22 = *(_QWORD *)(v20 + 168);
          v23 = 0i64;
          if ( v21 )
          {
            while ( *(Scaleform::Render::MeshCacheItem **)(v22 + 8 * v23) != v15 )
            {
              if ( ++v23 >= v21 )
                goto LABEL_13;
            }
          }
          else
          {
LABEL_13:
            inserted = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
                         (Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *)(v20 + 160),
                         v21);
            if ( inserted )
              inserted->pObject = (Scaleform::Render::TextLayerPrimitive *)v15;
          }
          ++v19;
          --v13;
        }
        while ( v13 );
      }
      Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::add<Scaleform::Render::MeshCacheItem *>(
        &pCache->BatchCacheItemHash,
        &pCache->BatchCacheItemHash,
        &key,
        v15->HashKey);
    }
    v15->ListType = MCL_Uncached;
    v15->pNext = pcacheList->Slots[0].Root.pNext;
    v15->pPrev = (Scaleform::Render::MeshCacheItem *)pcacheList->Slots;
    pcacheList->Slots[0].Root.pNext->pPrev = v15;
    pcacheList->Slots[0].Root.pNext = v15;
    pcacheList->Slots[0].Size += v15->AllocSize;
    return v15;
  }
  return result;
}

// File Line: 105
// RVA: 0x96D100
void __fastcall Scaleform::Render::MeshCacheItem::Destroy(
        Scaleform::Render::MeshCacheItem *this,
        Scaleform::Render::MeshBase *pskipMesh,
        bool freeMemory)
{
  Scaleform::Render::MeshCacheListSet *pCacheList; // r10
  __int64 v5; // rax
  Scaleform::Render::MeshCacheItemUseNode *pNext; // rax
  Scaleform::List<Scaleform::Render::MeshCacheItemUseNode,Scaleform::Render::MeshCacheItemUseNode> *i; // rcx
  Scaleform::Render::MeshCacheItem::MeshType Type; // eax
  Scaleform::Render::MeshCache *pCache; // rcx
  unsigned int j; // edx
  Scaleform::Render::MeshBase *v13; // r8
  unsigned int k; // ebp
  Scaleform::Render::MeshBase *v15; // rbx
  unsigned __int64 vfptr; // r8
  volatile int *p_RefCount; // rsi
  volatile int *v18; // rcx
  __int64 v19; // rax
  volatile int *v20; // rcx
  volatile int *v21; // rdx
  Scaleform::Render::MeshProvider *v22; // rcx
  unsigned int m; // ebx
  Scaleform::Render::MeshBase *v24; // rcx
  Scaleform::Render::MeshBase *v25; // rdx
  Scaleform::Render::MeshProvider *pObject; // rcx
  Scaleform::Render::Fence *v27; // rsi
  Scaleform::Render::FenceImpl *Data; // rcx
  Scaleform::Render::RenderSync *RSContext; // rbx
  Scaleform::Render::FenceImpl *v31; // rcx
  Scaleform::Render::MeshCacheItem *key; // [rsp+50h] [rbp+8h] BYREF

  pCacheList = this->pCacheList;
  this->pPrev->pNext = this->pNext;
  this->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$A6A32721DD821860D2CFF437DFF6F231::pPrev = this->pPrev;
  v5 = (int)this->ListType + 1i64;
  this->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
  this->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
  *((_QWORD *)&pCacheList->pCache + 3 * v5) -= this->AllocSize;
  if ( this->Type <= (unsigned int)Mesh_Complex )
  {
    pNext = this->PrimitiveBatches.Root.pNext;
    for ( i = &this->PrimitiveBatches; pNext != (Scaleform::Render::MeshCacheItemUseNode *)i; pNext = pNext->pNext )
      pNext->pMeshItem = 0i64;
    i->Root.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)i;
    this->PrimitiveBatches.Root.pNext = (Scaleform::Render::MeshCacheItemUseNode *)&this->PrimitiveBatches;
  }
  Type = this->Type;
  if ( Type )
  {
    if ( Type == Mesh_Complex )
    {
      v25 = *this->pMeshes;
      if ( v25 != pskipMesh )
      {
        pObject = v25->pProvider.pObject;
        v25[1].pPrev = 0i64;
        if ( pObject )
          ((void (__fastcall *)(Scaleform::Render::MeshProvider *))pObject->vfptr->OnEvict)(pObject);
      }
    }
  }
  else
  {
    pCache = this->pCacheList->pCache;
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::RemoveAlt<Scaleform::Render::MeshCacheItem *>(
      &pCache->BatchCacheItemHash,
      &key);
    for ( j = 0; j < this->MeshCount; ++j )
    {
      v13 = this->pMeshes[j];
      if ( v13 != pskipMesh )
        _InterlockedExchangeAdd(&v13->RefCount, 1u);
    }
    for ( k = 0; k < this->MeshCount; ++k )
    {
      v15 = this->pMeshes[k];
      if ( v15 != pskipMesh )
      {
        vfptr = (unsigned __int64)v15[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
        p_RefCount = &v15[1].RefCount;
        if ( vfptr <= 2 )
          v18 = &v15[1].RefCount;
        else
          v18 = *(volatile int **)p_RefCount;
        v19 = 0i64;
        if ( vfptr )
        {
          while ( *(Scaleform::Render::MeshCacheItem **)&v18[2 * v19] != this )
          {
            if ( ++v19 >= vfptr )
              goto LABEL_24;
          }
          if ( vfptr <= 2 )
            v20 = &v15[1].RefCount;
          else
            v20 = *(volatile int **)p_RefCount;
          memmove((void *)&v20[2 * v19], (const void *)&v20[2 * v19 + 2], 8 * (vfptr - v19) - 8);
          if ( --v15[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr == (Scaleform::RefCountImplCoreVtbl *)2 )
          {
            v21 = *(volatile int **)p_RefCount;
            *(_QWORD *)p_RefCount = **(_QWORD **)p_RefCount;
            v15[1].Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)*((_QWORD *)v21 + 1);
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
        }
LABEL_24:
        if ( !v15[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr
          && !v15->StagingBufferSize )
        {
          v22 = v15->pProvider.pObject;
          if ( v22 )
            v22->vfptr->OnEvict(v22, v15);
        }
      }
    }
    for ( m = 0; m < this->MeshCount; ++m )
    {
      v24 = this->pMeshes[m];
      if ( v24 != pskipMesh && !_InterlockedDecrement(&v24->RefCount) && v24 )
        v24->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
          v24,
          1u);
    }
  }
  this->Type = Mesh_Destroyed;
  if ( freeMemory )
  {
    v27 = this->GPUFence.pObject;
    if ( v27 )
    {
      if ( v27->RefCount-- == 1 )
      {
        Data = v27->Data;
        if ( v27->HasData )
        {
          RSContext = Data->RSContext;
          ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))Data->RSContext->FenceFrameAlloc.pHeapOrPtr)(
            Data,
            Data->APIHandle);
          v31 = v27->Data;
          v31->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
          RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v31;
          v27->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
          RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v27;
        }
        else
        {
          v27->Data = (Scaleform::Render::FenceImpl *)Data[4].Parent;
          Data[4].Parent = (Scaleform::Render::FenceFrame *)v27;
        }
      }
    }
    this->GPUFence.pObject = 0i64;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}

// File Line: 228
// RVA: 0x971CB0
char __fastcall Scaleform::Render::MeshCacheListSet::EvictLRU(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheListSet::ListSlot *list,
        Scaleform::AllocAddr *a,
        unsigned __int64 size)
{
  Scaleform::Render::MeshCacheItem *pPrev; // rax

  pPrev = list->Root.pPrev;
  if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev == list )
    return 0;
  while ( ((__int64 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))this->pCache->vfptr[4].__vecDelDtor)(
            this->pCache,
            pPrev,
            a,
            0i64) < size )
  {
    pPrev = list->Root.pPrev;
    if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev == list )
      return 0;
  }
  return 1;
}

// File Line: 245
// RVA: 0x971D20
char __fastcall Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheItem *list,
        Scaleform::AllocAddr *a,
        unsigned __int64 size,
        Scaleform::Render::MeshCacheListSet *limit)
{
  Scaleform::Render::MeshCacheItem *pPrev; // rdx

  pPrev = list->pPrev;
  if ( pPrev != list )
  {
    while ( list->pCacheList > limit )
    {
      if ( ((__int64 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))this->pCache->vfptr[4].__vecDelDtor)(
             this->pCache,
             pPrev,
             a,
             0i64) >= size )
        return 1;
      pPrev = list->pPrev;
      if ( list->pPrev == list )
        return 0;
    }
  }
  return 0;
}

// File Line: 260
// RVA: 0x971DA0
bool __fastcall Scaleform::Render::MeshCacheListSet::EvictPendingFree(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::AllocAddr *a)
{
  Scaleform::Render::MeshCacheListSet::ListSlot *v2; // rdi
  Scaleform::Render::MeshCacheListSet *pNext; // rdx
  Scaleform::Render::MeshCacheItem *pPrev; // rbx

  v2 = &this->Slots[5];
  pNext = (Scaleform::Render::MeshCacheListSet *)this->Slots[5].Root.pNext;
  if ( pNext != (Scaleform::Render::MeshCacheListSet *)&this->Slots[5] )
  {
    do
    {
      pPrev = pNext->Slots[0].Root.pPrev;
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheListSet *, Scaleform::AllocAddr *, _QWORD))this->pCache->vfptr[4].__vecDelDtor)(
        this->pCache,
        pNext,
        a,
        0i64);
      pNext = (Scaleform::Render::MeshCacheListSet *)pPrev;
    }
    while ( pPrev != (Scaleform::Render::MeshCacheItem *)v2 );
  }
  return 0;
}

// File Line: 279
// RVA: 0x971BD0
void __fastcall Scaleform::Render::MeshCacheListSet::EvictAll(Scaleform::Render::MeshCacheListSet *this)
{
  unsigned int v2; // ebp
  $A6A32721DD821860D2CFF437DFF6F231 *v3; // rbx
  Scaleform::Render::MeshCacheListSet::ListSlot *v4; // rsi
  Scaleform::Render::MeshCacheItem *i; // rbx
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::FenceImpl *Data; // r8

  v2 = 0;
  v3 = &this->Slots[0].Root.8;
  do
  {
    if ( v2 != 5 && ($A6A32721DD821860D2CFF437DFF6F231 *)v3->pNext != &v3[-1] )
    {
      do
        ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, _QWORD))this->pCache->vfptr[4].__vecDelDtor)(
          this->pCache,
          v3->pNext,
          0i64,
          0i64);
      while ( ($A6A32721DD821860D2CFF437DFF6F231 *)v3->pNext != &v3[-1] );
    }
    ++v2;
    v3 += 3;
  }
  while ( v2 < 6 );
  v4 = &this->Slots[5];
  while ( (Scaleform::Render::MeshCacheListSet::ListSlot *)this->Slots[5].Root.pNext != &this->Slots[5] )
  {
    for ( i = this->Slots[5].Root.pNext; i != (Scaleform::Render::MeshCacheItem *)v4; i = this->Slots[5].Root.pNext )
    {
      pObject = i->GPUFence.pObject;
      if ( pObject )
      {
        if ( pObject->HasData )
        {
          Data = pObject->Data;
          if ( pObject->Data )
          {
            if ( Data->Parent )
              ((void (__fastcall *)(Scaleform::Render::RenderSync *, _QWORD, unsigned __int64))Data->RSContext->vfptr[5].__vecDelDtor)(
                Data->RSContext,
                0i64,
                Data->APIHandle);
          }
        }
      }
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, _QWORD))this->pCache->vfptr[4].__vecDelDtor)(
        this->pCache,
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
  Scaleform::Render::MeshCacheItem *pNext; // rax
  Scaleform::Render::MeshCacheListSet::ListSlot *i; // rdx
  Scaleform::Render::MeshCacheItem *v4; // r8
  Scaleform::Render::MeshCacheItem *pPrev; // rcx
  Scaleform::Render::MeshCacheListSet::ListSlot *v6; // r8
  Scaleform::Render::MeshCacheItem *v7; // rax
  Scaleform::Render::MeshCacheItem *v8; // r9
  Scaleform::Render::MeshCacheItem *v9; // rcx

  if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)this->Slots[1].Root.pNext != &this->Slots[1] )
    Scaleform::Render::MeshCacheListSet::PushListToFront(this, MCL_PrevFrame, MCL_InFlight);
  pNext = this->Slots[3].Root.pNext;
  for ( i = &this->Slots[3]; pNext != (Scaleform::Render::MeshCacheItem *)i; pNext = pNext->pNext )
    pNext->ListType = MCL_LRUTail;
  v4 = this->Slots[3].Root.pNext;
  if ( v4 != (Scaleform::Render::MeshCacheItem *)i )
  {
    pPrev = i->Root.pPrev;
    this->Slots[3].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->Slots[3];
    i->Root.pPrev = (Scaleform::Render::MeshCacheItem *)i;
    pPrev->pNext = this->Slots[4].Root.pNext;
    v4->pPrev = (Scaleform::Render::MeshCacheItem *)&this->Slots[4];
    this->Slots[4].Root.pNext->pPrev = pPrev;
    this->Slots[4].Root.pNext = v4;
  }
  v6 = &this->Slots[2];
  this->Slots[4].Size += this->Slots[3].Size;
  this->Slots[3].Size = 0i64;
  v7 = this->Slots[2].Root.pNext;
  if ( v7 != (Scaleform::Render::MeshCacheItem *)&this->Slots[2] )
  {
    do
    {
      v7->ListType = MCL_PrevFrame;
      v7 = v7->pNext;
    }
    while ( v7 != (Scaleform::Render::MeshCacheItem *)v6 );
  }
  v8 = this->Slots[2].Root.pNext;
  if ( v8 != (Scaleform::Render::MeshCacheItem *)v6 )
  {
    v9 = v6->Root.pPrev;
    this->Slots[2].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->Slots[2];
    v6->Root.pPrev = (Scaleform::Render::MeshCacheItem *)v6;
    v9->pNext = this->Slots[3].Root.pNext;
    v8->pPrev = (Scaleform::Render::MeshCacheItem *)i;
    this->Slots[3].Root.pNext->pPrev = v9;
    this->Slots[3].Root.pNext = v8;
  }
  this->Slots[3].Size += this->Slots[2].Size;
  this->Slots[2].Size = 0i64;
}

// File Line: 353
// RVA: 0x95A950
bool __fastcall Scaleform::Render::MeshVertexOutput::BeginOutput(
        Scaleform::Render::MeshVertexOutput *this,
        Scaleform::Render::VertexOutput::Fill *fills,
        unsigned int fillCount,
        Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  Scaleform::Render::Mesh *pMesh; // rbp
  Scaleform::Render::Mesh **p_pMesh; // r14
  Scaleform::Render::VertexFormat *pBatchFormat; // r8
  char Mesh; // al
  Scaleform::Render::MeshCache::MeshResult::ResultType v11; // edx
  unsigned int VertexCount; // edx
  unsigned int Size; // r11d
  int v14; // eax
  Scaleform::Render::MeshCacheItem *BatchData; // r8
  Scaleform::Render::MeshCache *pCache; // rcx
  float *p_VertexMatrix; // rdx
  __int64 v19[3]; // [rsp+60h] [rbp-38h] BYREF
  int v20; // [rsp+78h] [rbp-20h]

  pMesh = this->pMesh;
  p_pMesh = &this->pMesh;
  if ( !pMesh->LargeMesh )
  {
    pBatchFormat = this->pBatchFormat;
    if ( pBatchFormat )
    {
      if ( pBatchFormat->Size * fills->VertexCount <= this->pCache->Params.NoBatchVerticesSizeThreshold )
      {
LABEL_6:
        Mesh = Scaleform::Render::MeshStagingBuffer::AllocateMesh(
                 &this->pCache->StagingBuffer,
                 pMesh,
                 fills->VertexCount,
                 this->pSourceFormat->Size,
                 fills->IndexCount);
        v11 = Fail_Staging_NoBuffer;
        if ( Mesh )
          v11 = Success_Staging;
        this->Result.Value = v11;
        goto LABEL_17;
      }
    }
    else if ( !this->pSingleFormat )
    {
      goto LABEL_6;
    }
  }
  VertexCount = fills->VertexCount;
  v19[0] = (__int64)&this->pMesh;
  v19[1] = 1i64;
  v19[2] = 8i64;
  v20 = (unsigned __int64)pMesh >> 5;
  Size = this->pSingleFormat->Size;
  pMesh->VertexCount = VertexCount;
  (*p_pMesh)->IndexCount = fills->IndexCount;
  (*p_pMesh)->LargeMesh = 1;
  v14 = ((__int64 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem **, char **, unsigned __int16 **, _DWORD, __int64 *, _QWORD, unsigned int, unsigned int, bool, Scaleform::Render::VertexFormat *))this->pCache->vfptr[6].__vecDelDtor)(
          this->pCache,
          &this->BatchData,
          &this->pVertexDataStart,
          &this->pIndexDataStart,
          0,
          v19,
          VertexCount * Size,
          fills->VertexCount,
          fills->IndexCount,
          this->WaitForCache,
          this->pSingleFormat);
  if ( v14 == 3 )
  {
    BatchData = this->BatchData;
    pCache = this->pCache;
    this->Result.Value = Success_LargeMesh;
    Scaleform::Render::MeshCache::MoveToCacheListFront(pCache, MCL_ThisFrame, BatchData);
  }
  else if ( v14 )
  {
    if ( v14 == 1 )
    {
      this->Result.Value = Fail_LargeMesh_TooBig;
    }
    else if ( v14 == 2 )
    {
      this->Result.Value = Fail_LargeMesh_ThisFrame;
    }
  }
  else
  {
    this->Result.Value = Fail_LargeMesh_NeedCache;
  }
LABEL_17:
  p_VertexMatrix = (float *)&(*p_pMesh)->VertexMatrix;
  *p_VertexMatrix = vertexMatrix->M[0][0];
  p_VertexMatrix[1] = vertexMatrix->M[0][1];
  p_VertexMatrix[2] = vertexMatrix->M[0][2];
  p_VertexMatrix[3] = vertexMatrix->M[0][3];
  p_VertexMatrix[4] = vertexMatrix->M[1][0];
  p_VertexMatrix[5] = vertexMatrix->M[1][1];
  p_VertexMatrix[6] = vertexMatrix->M[1][2];
  p_VertexMatrix[7] = vertexMatrix->M[1][3];
  return this->Result.Value <= Success_LargeMesh;
}

// File Line: 421
// RVA: 0x970B20
void __fastcall Scaleform::Render::MeshVertexOutput::EndOutput(Scaleform::Render::MeshVertexOutput *this)
{
  if ( (this->Result.Value & 1) != 0 )
    ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *))this->pCache->vfptr[6].UnlockBuffers)(
      this->pCache,
      this->BatchData);
}

// File Line: 430
// RVA: 0x9B5750
void __fastcall Scaleform::Render::MeshVertexOutput::SetVertices(
        Scaleform::Render::MeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int vertexOffset,
        void *vertices,
        unsigned int vertexCount)
{
  if ( !fillIndex && this->Result.Value <= Success_LargeMesh )
  {
    if ( (this->Result.Value & 1) != 0 )
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
void __fastcall Scaleform::Render::MeshVertexOutput::SetIndices(
        Scaleform::Render::MeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int indexOffset,
        unsigned __int16 *indices,
        unsigned int indexCount)
{
  if ( !fillIndex && this->Result.Value <= Success_LargeMesh )
  {
    if ( (this->Result.Value & 1) != 0 )
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
// attributes: thunk
void __fastcall Scaleform::Render::MeshStagingBuffer::~MeshStagingBuffer(Scaleform::Render::MeshStagingBuffer *this)
{
  Scaleform::Render::MeshStagingBuffer::Reset(this);
}

// File Line: 517
// RVA: 0x9941F0
bool __fastcall Scaleform::Render::MeshStagingBuffer::Initialize(
        Scaleform::Render::MeshStagingBuffer *this,
        Scaleform::MemoryHeap *pheap,
        unsigned __int64 size)
{
  char *v6; // rax

  if ( this->pBuffer && size != this->BufferSize )
    Scaleform::Render::MeshStagingBuffer::Reset(this);
  v6 = (char *)pheap->vfptr->Alloc(pheap, size, 0i64);
  this->pBuffer = v6;
  if ( v6 )
  {
    this->BufferSize = size;
    this->PinSizeLimit = size >> 1;
    this->TotalPinnedSize = 0i64;
    LOBYTE(v6) = 1;
  }
  return (char)v6;
}

// File Line: 530
// RVA: 0x9AB950
void __fastcall Scaleform::Render::MeshStagingBuffer::Reset(Scaleform::Render::MeshStagingBuffer *this)
{
  Scaleform::List<Scaleform::Render::MeshStagingNode,Scaleform::Render::MeshStagingNode> *p_MeshList; // rbx
  Scaleform::Render::MeshStagingNode *v3; // rax
  Scaleform::Render::MeshStagingNode *pNext; // rcx

  if ( this->pBuffer )
  {
    p_MeshList = &this->MeshList;
    while ( 1 )
    {
      v3 = (Scaleform::Render::MeshStagingNode *)&p_MeshList[-1].Root.8;
      if ( !p_MeshList )
        v3 = 0i64;
      if ( p_MeshList->Root.pNext == v3 )
        break;
      pNext = this->MeshList.Root.pNext;
      pNext->StagingBufferOffset = 0i64;
      pNext->StagingBufferIndexOffset = 0i64;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::MeshStagingNode *)-1i64;
      pNext->pNext = (Scaleform::Render::MeshStagingNode *)-1i64;
      pNext->vfptr->OnStagingNodeEvict(pNext);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pBuffer);
    this->pBuffer = 0i64;
    this->BufferSize = 0i64;
    this->TotalPinnedSize = 0i64;
  }
}

// File Line: 556
// RVA: 0x958040
char __fastcall Scaleform::Render::MeshStagingBuffer::AllocateBufferSpace(
        Scaleform::Render::MeshStagingBuffer *this,
        unsigned __int64 *poffset,
        unsigned __int64 size)
{
  Scaleform::List<Scaleform::Render::MeshStagingNode,Scaleform::Render::MeshStagingNode> *p_MeshList; // rdi
  __int64 v8; // rax
  Scaleform::Render::MeshStagingNode *pPrev; // rbx
  unsigned __int64 StagingBufferOffset; // rdx
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rsi

  if ( size > this->PinSizeLimit )
    return 0;
  p_MeshList = &this->MeshList;
  while ( 1 )
  {
    v8 = p_MeshList ? (__int64)&p_MeshList[-1].Root.8 : 0i64;
    if ( p_MeshList->Root.pNext == (Scaleform::Render::MeshStagingNode *)v8 )
      break;
    pPrev = p_MeshList->Root.pPrev;
    StagingBufferOffset = p_MeshList->Root.pPrev->StagingBufferOffset;
    v11 = this->MeshList.Root.pNext->StagingBufferSize + this->MeshList.Root.pNext->StagingBufferOffset;
    if ( v11 > StagingBufferOffset )
    {
      if ( this->BufferSize - v11 >= size )
      {
        *poffset = v11;
        return 1;
      }
      v12 = p_MeshList->Root.pPrev->StagingBufferOffset;
    }
    else
    {
      v12 = StagingBufferOffset - v11;
    }
    if ( v12 >= size )
    {
      *poffset = StagingBufferOffset - v12;
      return 1;
    }
    pPrev->pPrev->pNext = pPrev->pNext;
    pPrev->pNext->pPrev = pPrev->pPrev;
    pPrev->pPrev = (Scaleform::Render::MeshStagingNode *)-1i64;
    pPrev->pNext = (Scaleform::Render::MeshStagingNode *)-1i64;
    if ( pPrev->PinCount )
    {
      if ( v12 )
      {
        memmove(
          &this->pBuffer[pPrev->StagingBufferOffset - v12],
          &this->pBuffer[pPrev->StagingBufferOffset],
          pPrev->StagingBufferSize);
        pPrev->StagingBufferIndexOffset -= v12;
        pPrev->StagingBufferOffset -= v12;
      }
      pPrev->pNext = p_MeshList->Root.pNext;
      pPrev->pPrev = (Scaleform::Render::MeshStagingNode *)&p_MeshList[-1].Root.8;
      p_MeshList->Root.pNext->pPrev = pPrev;
      p_MeshList->Root.pNext = pPrev;
    }
    else
    {
      pPrev->vfptr->OnStagingNodeEvict(pPrev);
    }
  }
  *poffset = 0i64;
  return 1;
}

// File Line: 623
// RVA: 0x958360
char __fastcall Scaleform::Render::MeshStagingBuffer::AllocateMesh(
        Scaleform::Render::MeshStagingBuffer *this,
        Scaleform::Render::Mesh *pmesh,
        unsigned __int64 vertexCount,
        unsigned __int64 vertexSize,
        unsigned __int64 indexCount)
{
  unsigned int v5; // r15d
  unsigned int v7; // r14d
  unsigned __int64 v8; // rsi
  unsigned __int64 v10; // rbp
  char result; // al
  unsigned __int64 v12; // rax

  v5 = indexCount;
  v7 = vertexCount;
  v8 = vertexSize * vertexCount;
  v10 = (vertexSize * vertexCount + 2 * indexCount + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  result = Scaleform::Render::MeshStagingBuffer::AllocateBufferSpace(this, &indexCount, v10);
  if ( result )
  {
    v12 = indexCount;
    pmesh->StagingBufferSize = v10;
    pmesh->VertexCount = v7;
    pmesh->StagingBufferOffset = v12;
    pmesh->IndexCount = v5;
    pmesh->StagingBufferIndexOffset = v8 + v12;
    pmesh->pNext = this->MeshList.Root.pNext;
    pmesh->pPrev = (Scaleform::Render::MeshStagingNode *)&this->PinSizeLimit;
    this->MeshList.Root.pNext->pPrev = &pmesh->Scaleform::Render::MeshStagingNode;
    this->MeshList.Root.pNext = &pmesh->Scaleform::Render::MeshStagingNode;
    return 1;
  }
  return result;
}

// File Line: 661
// RVA: 0x9447F0
void __fastcall Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
        Scaleform::Render::MeshCache::StagingBufferPrep *this,
        Scaleform::Render::MeshCache *cache,
        Scaleform::Render::MeshCacheItem::MeshContent *mc,
        Scaleform::Render::VertexFormat *format,
        bool canCopyData)
{
  unsigned int Size; // ecx
  bool *PinnedFlagArray; // rax
  __int64 v8; // r9
  __int64 v9; // r8
  __int64 v10; // rcx

  this->pCache = cache;
  this->MC = mc;
  this->PinMeshes = 1;
  this->pVertexFormat = format;
  this->CanCopyData = canCopyData;
  Size = mc->Meshes.Size;
  if ( Size )
  {
    PinnedFlagArray = this->PinnedFlagArray;
    v8 = Size;
    do
    {
      v9 = *(__int64 *)((char *)this->MC->Meshes.pData
                      + this->MC->Meshes.StrideSize * (_QWORD)&PinnedFlagArray[-32i64 - (_QWORD)this]);
      v10 = *(_QWORD *)(v9 + 40);
      if ( v10 )
      {
        if ( !*(_DWORD *)(v9 + 64) )
          cache->StagingBuffer.TotalPinnedSize += v10;
        ++*(_DWORD *)(v9 + 64);
        *PinnedFlagArray = 1;
      }
      else
      {
        *PinnedFlagArray = 0;
      }
      ++PinnedFlagArray;
      --v8;
    }
    while ( v8 );
  }
  Scaleform::Render::MeshCache::StagingBufferPrep::GenerateMeshes(this, 0i64);
}

// File Line: 688
// RVA: 0x97EFC0
void __fastcall Scaleform::Render::MeshCache::StagingBufferPrep::GenerateMeshes(
        Scaleform::Render::MeshCache::StagingBufferPrep *this,
        Scaleform::Render::MeshCacheItem *skipBatch)
{
  Scaleform::Render::MeshCacheItem::MeshContent *MC; // rax
  unsigned int Size; // ecx
  Scaleform::Render::MeshCache *pCache; // r14
  __int64 v7; // rsi
  __int64 v8; // rbp
  __int64 v9; // rbx
  __int64 v10; // rax
  __int64 Size_low; // rbp
  Scaleform::Render::Mesh *v12; // rbx
  Scaleform::Render::MeshCache::MeshResult result; // [rsp+70h] [rbp+8h] BYREF

  MC = this->MC;
  Size = MC->Meshes.Size;
  pCache = this->pCache;
  v7 = 0i64;
  if ( this->CanCopyData )
  {
    if ( Size )
    {
      v8 = Size;
      do
      {
        v9 = *(__int64 *)((char *)this->MC->Meshes.pData + v7 * this->MC->Meshes.StrideSize);
        if ( !this->PinnedFlagArray[v7] )
        {
          v10 = *(_QWORD *)(v9 + 160);
          if ( !v10 || v10 == 1 && *(Scaleform::Render::MeshCacheItem **)(v9 + 168) == skipBatch )
          {
            if ( !*(_QWORD *)(v9 + 40) )
              Scaleform::Render::MeshCache::GenerateMesh(
                this->pCache,
                &result,
                (Scaleform::Render::Mesh *)v9,
                this->pVertexFormat,
                0i64,
                0i64,
                0);
            if ( this->PinMeshes || !*(_DWORD *)(v9 + 64) )
            {
              if ( !*(_DWORD *)(v9 + 64) )
                pCache->StagingBuffer.TotalPinnedSize += *(_QWORD *)(v9 + 40);
              ++*(_DWORD *)(v9 + 64);
            }
          }
        }
        ++v7;
        --v8;
      }
      while ( v8 );
      this->PinMeshes = 0;
      return;
    }
LABEL_29:
    this->PinMeshes = 0;
    return;
  }
  if ( !Size )
    goto LABEL_29;
  Size_low = LODWORD(MC->Meshes.Size);
  do
  {
    if ( !this->PinnedFlagArray[v7] )
    {
      v12 = *(Scaleform::Render::Mesh **)((char *)this->MC->Meshes.pData + v7 * this->MC->Meshes.StrideSize);
      if ( !v12->StagingBufferSize )
        Scaleform::Render::MeshCache::GenerateMesh(this->pCache, &result, v12, this->pVertexFormat, 0i64, 0i64, 0);
      if ( this->PinMeshes || !v12->PinCount )
      {
        if ( !v12->PinCount )
          pCache->StagingBuffer.TotalPinnedSize += v12->StagingBufferSize;
        ++v12->PinCount;
      }
    }
    ++v7;
    --Size_low;
  }
  while ( Size_low );
  this->PinMeshes = 0;
}

// File Line: 743
// RVA: 0x94CDB0
void __fastcall Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(
        Scaleform::Render::MeshCache::StagingBufferPrep *this)
{
  Scaleform::Render::MeshCacheItem::MeshContent *MC; // rax
  Scaleform::Render::MeshCache *pCache; // r9
  unsigned int i; // r8d
  __int64 v4; // rax

  MC = this->MC;
  pCache = this->pCache;
  for ( i = 0; i < LODWORD(MC->Meshes.Size); ++i )
  {
    if ( (*(Scaleform::Render::MeshBase **)((char *)MC->Meshes.pData + i * MC->Meshes.StrideSize))->StagingBufferSize )
    {
      v4 = *(__int64 *)((char *)MC->Meshes.pData + i * MC->Meshes.StrideSize);
      if ( (*(_DWORD *)(v4 + 64))-- == 1 )
        pCache->StagingBuffer.TotalPinnedSize -= *(_QWORD *)(v4 + 40);
    }
    MC = this->MC;
  }
}

// File Line: 776
// RVA: 0x95A830
bool __fastcall Scaleform::Render::ComplexMeshVertexOutput::BeginOutput(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        Scaleform::Render::VertexOutput::Fill *fills,
        unsigned int fillCount,
        Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  Scaleform::Render::ComplexMesh **p_pMesh; // rbx
  bool v7; // zf
  Scaleform::Render::ComplexMesh *v8; // rax
  Scaleform::Render::MeshCache *pCache; // rcx
  bool WaitForCache; // al
  Scaleform::Render::MeshCache::AllocResult v12; // eax
  unsigned int v13; // [rsp+60h] [rbp-48h] BYREF
  unsigned __int64 v14; // [rsp+68h] [rbp-40h] BYREF
  char v15[8]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v16[3]; // [rsp+78h] [rbp-30h] BYREF
  int v17; // [rsp+90h] [rbp-18h]
  unsigned int v18; // [rsp+B0h] [rbp+8h] BYREF

  p_pMesh = &this->pMesh;
  v7 = !Scaleform::Render::ComplexMesh::InitFillRecords(
          this->pMesh,
          fills,
          fillCount,
          vertexMatrix,
          this->pHAL,
          &v14,
          &v13,
          &v18);
  v8 = *p_pMesh;
  if ( v7 )
  {
    v8->AllocTooBig = 1;
    return 0;
  }
  else
  {
    pCache = this->pCache;
    v16[0] = (__int64)p_pMesh;
    v17 = (unsigned __int64)v8 >> 5;
    WaitForCache = this->WaitForCache;
    v16[1] = 1i64;
    v16[2] = 8i64;
    v12 = ((unsigned int (__fastcall *)(Scaleform::Render::MeshCache *, char *, char **, unsigned __int16 **, int, __int64 *, unsigned __int64, unsigned int, unsigned int, bool, _QWORD))pCache->Scaleform::Render::CacheBase::vfptr[6].__vecDelDtor)(
            pCache,
            v15,
            &this->pVertexDataStart,
            &this->pIndexDataStart,
            1,
            v16,
            v14,
            v13,
            v18,
            WaitForCache,
            0i64);
    this->AllocState = v12;
    this->pFills = fills;
    if ( v12 == Alloc_Fail_TooBig )
      (*p_pMesh)->AllocTooBig = 1;
    return this->AllocState == Alloc_Success;
  }
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
void __fastcall Scaleform::Render::ComplexMeshVertexOutput::SetVertices(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int vertexOffset,
        char *vertices,
        unsigned int vertexCount)
{
  __int64 v5; // r10
  Scaleform::Render::ComplexMesh::FillRecord *v6; // rdx

  if ( this->AllocState == Alloc_Success )
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
void __fastcall Scaleform::Render::ComplexMeshVertexOutput::SetIndices(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int indexOffset,
        unsigned __int16 *indices,
        unsigned int indexCount)
{
  if ( this->AllocState == Alloc_Success )
    memmove(
      &this->pIndexDataStart[indexOffset + (unsigned __int64)this->pMesh->FillRecords.Data.Data[fillIndex].IndexOffset],
      indices,
      2i64 * indexCount);
}

// File Line: 855
// RVA: 0x93FA30
void __fastcall Scaleform::Render::MeshCache::MeshCache(
        Scaleform::Render::MeshCache *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Render::MeshCacheParams *params)
{
  unsigned __int64 *p_PinSizeLimit; // rax

  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
  this->Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCacheConfig::`vftable;
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::CacheBase};
  this->Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::MeshCacheConfig};
  this->pHeap = pheap;
  this->pRQCaches = 0i64;
  this->Params = *params;
  this->StagingBuffer.pBuffer = 0i64;
  this->StagingBuffer.BufferSize = 0i64;
  this->StagingBuffer.TotalPinnedSize = 0i64;
  this->StagingBuffer.PinSizeLimit = 0i64;
  p_PinSizeLimit = &this->StagingBuffer.PinSizeLimit;
  if ( this == (Scaleform::Render::MeshCache *)-136i64 )
    p_PinSizeLimit = 0i64;
  this->StagingBuffer.MeshList.Root.pPrev = (Scaleform::Render::MeshStagingNode *)p_PinSizeLimit;
  this->StagingBuffer.MeshList.Root.pNext = (Scaleform::Render::MeshStagingNode *)p_PinSizeLimit;
  this->BatchCacheItemHash.pTable = 0i64;
}

// File Line: 861
// RVA: 0x94B680
void __fastcall Scaleform::Render::MeshCache::~MeshCache(Scaleform::Render::MeshCache *this)
{
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::CacheBase};
  this->Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCache::`vftable{for `Scaleform::Render::MeshCacheConfig};
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->BatchCacheItemHash);
  Scaleform::Render::MeshStagingBuffer::Reset(&this->StagingBuffer);
  this->Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::MeshCacheConfig::`vftable;
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
}

// File Line: 884
// RVA: 0x987CE0
__int64 __fastcall Scaleform::Render::MeshCache::GetItemUseStatus(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheItem *item)
{
  switch ( item->ListType )
  {
    case MCL_InFlight:
      return 4i64;
    case MCL_ThisFrame:
      return 3i64;
    case MCL_PrevFrame:
      return 2i64;
  }
  return item->ListType == MCL_LRUTail;
}

// File Line: 907
// RVA: 0x97EF00
Scaleform::Render::MeshCache::MeshResult *__fastcall Scaleform::Render::MeshCache::GenerateMesh(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCache::MeshResult *result,
        Scaleform::Render::Mesh *mesh,
        Scaleform::Render::VertexFormat *sourceFormat,
        Scaleform::Render::VertexFormat *singleFormat,
        Scaleform::Render::VertexFormat *batchFormat,
        bool waitForCache)
{
  __int64 v9[2]; // [rsp+30h] [rbp-68h] BYREF
  bool v10; // [rsp+40h] [rbp-58h]
  Scaleform::Render::Mesh *v11; // [rsp+48h] [rbp-50h]
  Scaleform::Render::VertexFormat *v12; // [rsp+50h] [rbp-48h]
  Scaleform::Render::VertexFormat *v13; // [rsp+58h] [rbp-40h]
  Scaleform::Render::VertexFormat *v14; // [rsp+60h] [rbp-38h]
  Scaleform::Render::MeshCache::MeshResult::ResultType v15; // [rsp+68h] [rbp-30h]
  __int128 v16; // [rsp+70h] [rbp-28h]
  __int64 v17; // [rsp+80h] [rbp-18h]

  v9[0] = (__int64)&Scaleform::Render::MeshVertexOutput::`vftable;
  v9[1] = (__int64)this;
  v10 = waitForCache;
  v11 = mesh;
  v12 = sourceFormat;
  v13 = singleFormat;
  v14 = batchFormat;
  v15 = Fail_General;
  v16 = 0i64;
  v17 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::Mesh *, __int64 *, _QWORD, __int64))mesh->pProvider.pObject->Scaleform::Render::MeshBase::vfptr->GetData)(
    mesh->pProvider.pObject,
    mesh,
    v9,
    mesh->MGFlags,
    -2i64);
  result->Value = v15;
  return result;
}

// File Line: 918
// RVA: 0x99FAA0
char __fastcall Scaleform::Render::MeshCache::PrepareComplexMesh(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::ComplexMesh *mesh,
        bool waitForCache)
{
  Scaleform::Render::HAL *pHAL; // rcx
  char result; // al
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // r8
  __int64 v8[4]; // [rsp+30h] [rbp-58h] BYREF
  bool v9; // [rsp+50h] [rbp-38h]
  int v10; // [rsp+60h] [rbp-28h]

  if ( mesh && !mesh->AllocTooBig )
  {
    if ( !mesh->pCacheMeshItem )
    {
      pHAL = mesh->pFillManager->pHAL;
      v8[0] = (__int64)&Scaleform::Render::ComplexMeshVertexOutput::`vftable;
      v8[1] = (__int64)mesh;
      v8[2] = (__int64)this;
      v8[3] = (__int64)pHAL;
      v9 = waitForCache;
      v10 = 4;
      ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::ComplexMesh *, __int64 *, _QWORD, __int64))mesh->pProvider.pObject->Scaleform::Render::MeshBase::vfptr->GetData)(
        mesh->pProvider.pObject,
        mesh,
        v8,
        mesh->MGFlags,
        -2i64);
      result = v10;
      if ( !v10 )
      {
LABEL_7:
        v8[0] = (__int64)&Scaleform::Render::VertexOutput::`vftable;
        return result;
      }
      if ( v10 != 3 )
      {
        result = 1;
        goto LABEL_7;
      }
      v8[0] = (__int64)&Scaleform::Render::VertexOutput::`vftable;
    }
    pCacheMeshItem = mesh->pCacheMeshItem;
    if ( pCacheMeshItem )
      Scaleform::Render::MeshCache::MoveToCacheListFront(this, MCL_InFlight, pCacheMeshItem);
  }
  return 1;
}

// File Line: 952
// RVA: 0x9B0F00
char __fastcall Scaleform::Render::MeshCache::SetLargeMeshVertices(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pcacheItem,
        Scaleform::Render::VertexFormat *pSourceFormat,
        unsigned __int64 vertexOffset,
        char *pvertices,
        unsigned int vertexCount,
        Scaleform::Render::VertexFormat *pDestFormat,
        char *pdestStart)
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
char __fastcall Scaleform::Render::MeshCache::SetLargeMeshIndices(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pcacheItem,
        Scaleform::Render::VertexFormat *pSourceFormat,
        unsigned __int64 indexOffset,
        const unsigned __int16 *pindices,
        unsigned int indexCount,
        Scaleform::Render::VertexFormat *pDestFormat,
        char *pdestIndex)
{
  memmove(&pdestIndex[2 * indexOffset], pindices, 2i64 * indexCount);
  return 1;
}

