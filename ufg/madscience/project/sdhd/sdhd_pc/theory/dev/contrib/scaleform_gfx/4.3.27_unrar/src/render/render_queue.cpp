// File Line: 34
// RVA: 0x94C470
void __fastcall Scaleform::Render::RenderQueue::~RenderQueue(Scaleform::Render::RenderQueue *this)
{
  Scaleform::Render::RenderQueue *v1; // rbx

  v1 = this;
  if ( this->pQueue )
  {
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v1->pQueue = 0i64;
  }
}

// File Line: 39
// RVA: 0x994320
char __fastcall Scaleform::Render::RenderQueue::Initialize(Scaleform::Render::RenderQueue *this, unsigned __int64 itemCount)
{
  unsigned int v2; // edi
  Scaleform::Render::RenderQueue *v3; // rbx
  Scaleform::Render::RenderQueueItem *v5; // rax
  unsigned int v6; // eax
  __int64 v7; // rcx
  Scaleform::Render::RenderQueueItem *v8; // rcx

  v2 = itemCount;
  v3 = this;
  if ( itemCount < 2 )
    return 0;
  v5 = (Scaleform::Render::RenderQueueItem *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               16 * itemCount,
                                               0i64);
  v3->QueueSize = v2;
  v3->pQueue = v5;
  if ( !v5 )
    return 0;
  v6 = 0;
  if ( v2 )
  {
    do
    {
      v7 = v6++;
      v8 = &v3->pQueue[v7];
      v8->pImpl = 0i64;
      v8->Data = 0i64;
    }
    while ( v6 < v3->QueueSize );
  }
  return 1;
}

// File Line: 117
// RVA: 0x95A630
void __fastcall Scaleform::Render::RenderQueueProcessor::BeginFrame(Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::RenderQueueProcessor *v1; // rdi
  __int64 v2; // rax
  Scaleform::Render::CacheBase *v3; // rbx
  Scaleform::Render::MeshCache::QueueMode v4; // eax
  Scaleform::Render::RQCacheInterface *v5; // rcx
  Scaleform::Render::CacheBaseVtbl *v6; // rax
  Scaleform::Render::RenderQueue *v7; // rax
  unsigned int v8; // ecx

  v1 = this;
  v2 = ((__int64 (*)(void))this->pHAL->vfptr[62].__vecDelDtor)();
  v3 = (Scaleform::Render::CacheBase *)v2;
  v4 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v2 + 16i64))(v2);
  v5 = &v1->Caches;
  v1->QueueMode = v4;
  v6 = v3[3].vfptr;
  if ( v6 != (Scaleform::Render::CacheBaseVtbl *)&v1->Caches )
  {
    if ( v6 )
    {
      LODWORD(v6[1].__vecDelDtor) &= 0xFFFFFFFE;
      v3[3].vfptr->__vecDelDtor = 0i64;
    }
    v3[3].vfptr = (Scaleform::Render::CacheBaseVtbl *)v5;
    if ( v1 != (Scaleform::Render::RenderQueueProcessor *)-8i64 )
    {
      v5->pCaches[0] = v3;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::CacheBase *))v3->vfptr[3].__vecDelDtor)(v3) )
        LODWORD(v3[3].vfptr[1].__vecDelDtor) |= 1u;
    }
  }
  v7 = v1->Queue;
  v8 = v7->QueueTail;
  v1->CurrentItem.pQueue = v7;
  v1->CurrentItem.QueuePos = v8;
}

// File Line: 134
// RVA: 0x9E0470
void __fastcall Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::RenderQueue *v1; // rdi
  Scaleform::Render::RenderQueueProcessor *v2; // rsi
  Scaleform::Render::RQCacheInterface *v3; // r14
  signed int v4; // ebx
  unsigned int *v5; // r15
  signed __int64 v6; // rbp
  unsigned int i; // eax
  Scaleform::Render::RenderQueueItem *v8; // rdx
  Scaleform::Render::RenderQueueItem *v9; // rax
  Scaleform::Render::RenderQueueItem *v10; // rdx

  v1 = this->Queue;
  v2 = this;
  if ( this->Caches.LockFlags )
  {
    v3 = &this->Caches;
    v4 = 1;
    v5 = &this->Caches.LockFlags;
    v6 = 2i64;
    do
    {
      if ( v4 & *v5 && v3->pCaches[0] )
        ((void (*)(void))v3->pCaches[0]->vfptr->UnlockBuffers)();
      v4 = __ROL4__(v4, 1);
      v3 = (Scaleform::Render::RQCacheInterface *)((char *)v3 + 8);
      --v6;
    }
    while ( v6 );
  }
  for ( i = v1->QueueTail; i != v2->CurrentItem.QueuePos; i = v1->QueueTail )
  {
    v8 = &v1->pQueue[i];
    v8->pImpl->vfptr->EmitToHAL(v8->pImpl, v8, v2);
    v9 = &v1->pQueue[v1->QueueTail];
    v9->pImpl = 0i64;
    v9->Data = 0i64;
    if ( ++v1->QueueTail == v1->QueueSize )
      v1->QueueTail = 0;
  }
  if ( v2->CurrentItem.QueuePos != v1->QueueHead )
  {
    v10 = &v1->pQueue[v1->QueueTail];
    v10->pImpl->vfptr->EmitToHAL(v10->pImpl, v10, v2);
  }
  v2->EmitItemBuffer.pItem = 0i64;
  v2->PrepareItemBuffer.pItem = 0i64;
}

// File Line: 170
// RVA: 0x9A01E0
void __fastcall Scaleform::Render::RenderQueueProcessor::ProcessQueue(Scaleform::Render::RenderQueueProcessor *this, Scaleform::Render::RenderQueueProcessor::QueueProcessMode mode)
{
  unsigned __int8 v2; // di
  Scaleform::Render::RenderQueueProcessor::QueueProcessMode v3; // ebp
  Scaleform::Render::RenderQueueProcessor *v4; // rbx
  Scaleform::Render::RenderQueueItem *v5; // rsi
  Scaleform::Render::RenderQueueItem::QIPrepareResult i; // eax
  Scaleform::Render::RenderQueue *v7; // rax
  unsigned int v8; // edx

  v2 = 0;
  v3 = mode;
  v4 = this;
  if ( mode )
  {
    if ( this->QueueMode )
    {
      if ( this->Caches.LockFlags )
        Scaleform::Render::RQCacheInterface::UnlockCaches(&this->Caches);
    }
    else
    {
      v2 = 1;
    }
  }
  if ( v4->CurrentItem.QueuePos != v4->Queue->QueueHead )
  {
    do
    {
      v5 = &v4->CurrentItem.pQueue->pQueue[v4->CurrentItem.QueuePos];
      for ( i = (unsigned int)v5->pImpl->vfptr->Prepare(v5->pImpl, v5, v4, v2);
            i;
            i = (unsigned int)v5->pImpl->vfptr->Prepare(v5->pImpl, v5, v4, v2) )
      {
        if ( i == 1 )
          v2 = 1;
        Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(v4);
      }
      v7 = v4->CurrentItem.pQueue;
      if ( v3 == 1 )
        v2 = 0;
      v8 = ++v4->CurrentItem.QueuePos;
      if ( v4->CurrentItem.QueuePos == v7->QueueSize )
        v8 = 0;
      v4->CurrentItem.QueuePos = v8;
    }
    while ( v8 != v4->Queue->QueueHead );
  }
  if ( v4->QueueMode != 1 || !v4->Caches.LockFlags )
    Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(v4);
}

