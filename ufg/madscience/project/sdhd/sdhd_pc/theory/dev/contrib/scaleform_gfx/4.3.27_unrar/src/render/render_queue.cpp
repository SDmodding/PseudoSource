// File Line: 34
// RVA: 0x94C470
void __fastcall Scaleform::Render::RenderQueue::~RenderQueue(Scaleform::Render::RenderQueue *this)
{
  if ( this->pQueue )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->pQueue = 0i64;
  }
}

// File Line: 39
// RVA: 0x994320
char __fastcall Scaleform::Render::RenderQueue::Initialize(
        Scaleform::Render::RenderQueue *this,
        unsigned __int64 itemCount)
{
  unsigned int v2; // edi
  Scaleform::Render::RenderQueueItem *v5; // rax
  unsigned int v6; // eax
  __int64 v7; // rcx
  Scaleform::Render::RenderQueueItem *v8; // rcx

  v2 = itemCount;
  if ( itemCount < 2 )
    return 0;
  v5 = (Scaleform::Render::RenderQueueItem *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               16 * itemCount,
                                               0i64);
  this->QueueSize = v2;
  this->pQueue = v5;
  if ( !v5 )
    return 0;
  v6 = 0;
  if ( v2 )
  {
    do
    {
      v7 = v6++;
      v8 = &this->pQueue[v7];
      v8->pImpl = 0i64;
      v8->Data = 0i64;
    }
    while ( v6 < this->QueueSize );
  }
  return 1;
}

// File Line: 117
// RVA: 0x95A630
void __fastcall Scaleform::Render::RenderQueueProcessor::BeginFrame(Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::CacheBase *v2; // rbx
  Scaleform::Render::MeshCache::QueueMode v3; // eax
  Scaleform::Render::RQCacheInterface *p_Caches; // rcx
  Scaleform::Render::CacheBaseVtbl *vfptr; // rax
  Scaleform::Render::RenderQueue *Queue; // rax
  unsigned int QueueTail; // ecx

  v2 = (Scaleform::Render::CacheBase *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pHAL->vfptr[62].__vecDelDtor)(this->pHAL);
  v3 = ((unsigned int (__fastcall *)(Scaleform::Render::CacheBase *))v2->vfptr[1].__vecDelDtor)(v2);
  p_Caches = &this->Caches;
  this->QueueMode = v3;
  vfptr = v2[3].vfptr;
  if ( vfptr != (Scaleform::Render::CacheBaseVtbl *)&this->Caches )
  {
    if ( vfptr )
    {
      LODWORD(vfptr[1].__vecDelDtor) &= ~1u;
      v2[3].vfptr->__vecDelDtor = 0i64;
    }
    v2[3].vfptr = (Scaleform::Render::CacheBaseVtbl *)p_Caches;
    if ( this != (Scaleform::Render::RenderQueueProcessor *)-8i64 )
    {
      p_Caches->pCaches[0] = v2;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::CacheBase *))v2->vfptr[3].__vecDelDtor)(v2) )
        LODWORD(v2[3].vfptr[1].__vecDelDtor) |= 1u;
    }
  }
  Queue = this->Queue;
  QueueTail = Queue->QueueTail;
  this->CurrentItem.pQueue = Queue;
  this->CurrentItem.QueuePos = QueueTail;
}

// File Line: 134
// RVA: 0x9E0470
void __fastcall Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(
        Scaleform::Render::RenderQueueProcessor *this)
{
  Scaleform::Render::RenderQueue *Queue; // rdi
  Scaleform::Render::RQCacheInterface *p_Caches; // r14
  int v4; // ebx
  unsigned int *p_LockFlags; // r15
  __int64 v6; // rbp
  unsigned int i; // eax
  Scaleform::Render::RenderQueueItem *v8; // rdx
  Scaleform::Render::RenderQueueItem *v9; // rax
  Scaleform::Render::RenderQueueItem *v10; // rdx

  Queue = this->Queue;
  if ( this->Caches.LockFlags )
  {
    p_Caches = &this->Caches;
    v4 = 1;
    p_LockFlags = &this->Caches.LockFlags;
    v6 = 2i64;
    do
    {
      if ( (v4 & *p_LockFlags) != 0 && p_Caches->pCaches[0] )
        p_Caches->pCaches[0]->vfptr->UnlockBuffers(p_Caches->pCaches[0]);
      v4 = __ROL4__(v4, 1);
      p_Caches = (Scaleform::Render::RQCacheInterface *)((char *)p_Caches + 8);
      --v6;
    }
    while ( v6 );
  }
  for ( i = Queue->QueueTail; i != this->CurrentItem.QueuePos; i = Queue->QueueTail )
  {
    v8 = &Queue->pQueue[i];
    v8->pImpl->vfptr->EmitToHAL(v8->pImpl, v8, this);
    v9 = &Queue->pQueue[Queue->QueueTail];
    v9->pImpl = 0i64;
    v9->Data = 0i64;
    if ( ++Queue->QueueTail == Queue->QueueSize )
      Queue->QueueTail = 0;
  }
  if ( this->CurrentItem.QueuePos != Queue->QueueHead )
  {
    v10 = &Queue->pQueue[Queue->QueueTail];
    v10->pImpl->vfptr->EmitToHAL(v10->pImpl, v10, this);
  }
  this->EmitItemBuffer.pItem = 0i64;
  this->PrepareItemBuffer.pItem = 0i64;
}

// File Line: 170
// RVA: 0x9A01E0
void __fastcall Scaleform::Render::RenderQueueProcessor::ProcessQueue(
        Scaleform::Render::RenderQueueProcessor *this,
        Scaleform::Render::RenderQueueProcessor::QueueProcessMode mode)
{
  unsigned __int8 v2; // di
  Scaleform::Render::RenderQueueItem *v5; // rsi
  Scaleform::Render::RenderQueueItem::QIPrepareResult i; // eax
  Scaleform::Render::RenderQueue *pQueue; // rax
  unsigned int v8; // edx

  v2 = 0;
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
  if ( this->CurrentItem.QueuePos != this->Queue->QueueHead )
  {
    do
    {
      v5 = &this->CurrentItem.pQueue->pQueue[this->CurrentItem.QueuePos];
      for ( i = v5->pImpl->vfptr->Prepare(v5->pImpl, v5, this, v2);
            i;
            i = v5->pImpl->vfptr->Prepare(v5->pImpl, v5, this, v2) )
      {
        if ( i == QIP_NeedCache )
          v2 = 1;
        Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(this);
      }
      pQueue = this->CurrentItem.pQueue;
      if ( mode == QPM_One )
        v2 = 0;
      v8 = ++this->CurrentItem.QueuePos;
      if ( v8 == pQueue->QueueSize )
        v8 = 0;
      this->CurrentItem.QueuePos = v8;
    }
    while ( v8 != this->Queue->QueueHead );
  }
  if ( this->QueueMode != QM_ExtendLocks || !this->Caches.LockFlags )
    Scaleform::Render::RenderQueueProcessor::drawProcessedPrimitives(this);
}

