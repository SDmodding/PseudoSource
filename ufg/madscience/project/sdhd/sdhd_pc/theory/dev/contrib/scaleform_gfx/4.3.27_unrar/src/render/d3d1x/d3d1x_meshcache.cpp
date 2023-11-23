// File Line: 54
// RVA: 0xA06410
void __fastcall Scaleform::Render::D3D1x::MeshCache::MeshCache(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Render::MeshCacheParams *params)
{
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rbx
  Scaleform::Render::MeshBuffer *p_LockedBuffers; // rax
  Scaleform::Render::MeshBuffer *v9; // rcx

  Scaleform::Render::MeshCache::MeshCache(this, pheap, params);
  this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable{for `Scaleform::Render::CacheBase};
  this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable{for `Scaleform::Render::MeshCacheConfig};
  this->pDevice.pObject = 0i64;
  this->pDeviceContext.pObject = 0i64;
  this->CacheList.pCache = this;
  this->CacheList.Slots[0].Root.pPrev = (Scaleform::Render::MeshCacheItem *)this->CacheList.Slots;
  this->CacheList.Slots[0].Root.pNext = (Scaleform::Render::MeshCacheItem *)this->CacheList.Slots;
  this->CacheList.Slots[0].Size = 0i64;
  this->CacheList.Slots[1].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[1];
  this->CacheList.Slots[1].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[1];
  this->CacheList.Slots[1].Size = 0i64;
  this->CacheList.Slots[2].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[2];
  this->CacheList.Slots[2].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[2];
  this->CacheList.Slots[2].Size = 0i64;
  this->CacheList.Slots[3].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[3];
  this->CacheList.Slots[3].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[3];
  this->CacheList.Slots[3].Size = 0i64;
  this->CacheList.Slots[4].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[4];
  this->CacheList.Slots[4].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[4];
  this->CacheList.Slots[4].Size = 0i64;
  this->CacheList.Slots[5].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[5];
  this->CacheList.Slots[5].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[5];
  this->CacheList.Slots[5].Size = 0i64;
  v6 = 16 * (5 * (params->MemGranularity >> 4) / 9);
  this->VertexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable;
  this->VertexBuffers.Buffers.Data.Data = 0i64;
  this->VertexBuffers.Buffers.Data.Size = 0i64;
  this->VertexBuffers.Buffers.Data.Policy.Capacity = 0i64;
  Scaleform::AllocAddr::AllocAddr(&this->VertexBuffers.Allocator, pheap);
  this->VertexBuffers.Granularity = v6;
  this->VertexBuffers.TotalSize = 0i64;
  this->VertexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>::`vftable;
  v7 = (params->MemGranularity & 0xFFFFFFFFFFFFFFF0ui64) - (this->VertexBuffers.Granularity & 0xFFFFFFFFFFFFFFF0ui64);
  this->IndexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable;
  this->IndexBuffers.Buffers.Data.Data = 0i64;
  this->IndexBuffers.Buffers.Data.Size = 0i64;
  this->IndexBuffers.Buffers.Data.Policy.Capacity = 0i64;
  Scaleform::AllocAddr::AllocAddr(&this->IndexBuffers.Allocator, pheap);
  this->IndexBuffers.Granularity = v7;
  this->IndexBuffers.TotalSize = 0i64;
  this->IndexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::`vftable;
  this->Locked = 0;
  this->VBSizeEvictedInLock = 0i64;
  this->LockedBuffers.pFirst = 0i64;
  p_LockedBuffers = (Scaleform::Render::MeshBuffer *)&this->LockedBuffers;
  if ( this == (Scaleform::Render::D3D1x::MeshCache *)-504i64 )
    p_LockedBuffers = 0i64;
  this->ChunkBuffers.Root.pPrev = p_LockedBuffers;
  this->ChunkBuffers.Root.pNext = p_LockedBuffers;
  v9 = (Scaleform::Render::MeshBuffer *)&this->ChunkBuffers.Root.8;
  if ( this == (Scaleform::Render::D3D1x::MeshCache *)-520i64 )
    v9 = 0i64;
  this->PendingDestructionBuffers.Root.pPrev = v9;
  this->PendingDestructionBuffers.Root.pNext = v9;
  this->pMaskEraseBatchVertexBuffer.pObject = 0i64;
}

// File Line: 58
// RVA: 0xA06730
void __fastcall Scaleform::Render::D3D1x::MeshCache::~MeshCache(Scaleform::Render::D3D1x::MeshCache *this)
{
  ID3D11Buffer *pObject; // rcx
  ID3D11DeviceContext *v3; // rcx
  ID3D11Device *v4; // rcx

  this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable{for `Scaleform::Render::CacheBase};
  this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable{for `Scaleform::Render::MeshCacheConfig};
  Scaleform::Render::D3D1x::MeshCache::Reset(this);
  pObject = this->pMaskEraseBatchVertexBuffer.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->IndexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable;
  Scaleform::AllocAddr::~AllocAddr(&this->IndexBuffers.Allocator);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->IndexBuffers.Buffers.Data.Data);
  this->VertexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable;
  Scaleform::AllocAddr::~AllocAddr(&this->VertexBuffers.Allocator);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->VertexBuffers.Buffers.Data.Data);
  v3 = this->pDeviceContext.pObject;
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = this->pDevice.pObject;
  if ( v4 )
    ((void (__fastcall *)(ID3D11Device *))v4->vfptr->Release)(v4);
  Scaleform::Render::MeshCache::~MeshCache(this);
}

// File Line: 65
// RVA: 0xA078E0
char __fastcall Scaleform::Render::D3D1x::MeshCache::Initialize(
        Scaleform::Render::D3D1x::MeshCache *this,
        ID3D11Device *pdevice,
        ID3D11DeviceContext *pcontext,
        Scaleform::Render::D3D1x::ShaderManager *psm)
{
  ID3D11Device *pObject; // rcx
  ID3D11DeviceContext *v9; // rcx
  __int64 MaxVerticesSizeInBatch; // rax
  unsigned int MaxBatchInstances; // ecx
  unsigned __int64 v12; // rdx
  unsigned __int64 MemReserve; // rdx

  if ( pdevice )
    ((void (__fastcall *)(ID3D11Device *))pdevice->vfptr->AddRef)(pdevice);
  pObject = this->pDevice.pObject;
  if ( pObject )
    ((void (__fastcall *)(ID3D11Device *))pObject->vfptr->Release)(pObject);
  this->pDevice.pObject = pdevice;
  if ( pcontext )
    pcontext->vfptr->AddRef(pcontext);
  v9 = this->pDeviceContext.pObject;
  if ( v9 )
    v9->vfptr->Release(v9);
  this->pDeviceContext.pObject = pcontext;
  this->pShaderManager = psm;
  MaxVerticesSizeInBatch = this->Params.MaxVerticesSizeInBatch;
  MaxBatchInstances = 24;
  this->Params.VBLockEvictSizeLimit = 0x40000i64;
  if ( this->Params.MaxBatchInstances < 0x18 )
    MaxBatchInstances = this->Params.MaxBatchInstances;
  if ( !MaxBatchInstances )
    MaxBatchInstances = 1;
  this->Params.MaxBatchInstances = MaxBatchInstances;
  v12 = 2 * (MaxVerticesSizeInBatch + 2i64 * this->Params.MaxIndicesInBatch);
  if ( v12 > this->Params.StagingBufferSize )
    this->Params.StagingBufferSize = v12;
  if ( !Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport(psm) )
    this->Params.InstancingThreshold = 0;
  if ( !Scaleform::Render::MeshStagingBuffer::Initialize(
          &this->StagingBuffer,
          this->pHeap,
          this->Params.StagingBufferSize) )
    return 0;
  if ( !Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(this, pdevice)
    || (MemReserve = this->Params.MemReserve) != 0
    && !Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(this, MemReserve, AT_Reserve, 0) )
  {
    Scaleform::Render::D3D1x::MeshCache::Reset(this);
    return 0;
  }
  return 1;
}

// File Line: 94
// RVA: 0xA07CB0
void __fastcall Scaleform::Render::D3D1x::MeshCache::Reset(Scaleform::Render::D3D1x::MeshCache *this)
{
  unsigned __int64 i; // rdi
  Scaleform::Render::D3D1x::MeshBuffer *v3; // rsi
  unsigned __int64 j; // rdi
  Scaleform::Render::D3D1x::MeshBuffer *v5; // rsi
  Scaleform::Render::MeshBuffer *p_LockedBuffers; // rcx
  ID3D11Buffer *pObject; // rcx
  ID3D11Device *v8; // rcx
  ID3D11DeviceContext *v9; // rcx

  if ( this->pDevice.pObject )
  {
    Scaleform::Render::MeshCacheListSet::EvictAll(&this->CacheList);
    for ( i = 0i64; i < this->VertexBuffers.Buffers.Data.Size; ++i )
    {
      v3 = this->VertexBuffers.Buffers.Data.Data[i];
      if ( v3 )
      {
        Scaleform::AllocAddr::RemoveSegment(&this->VertexBuffers.Allocator, v3->Index << 24, (v3->Size + 15) >> 4);
        this->VertexBuffers.TotalSize -= v3->Size;
        this->VertexBuffers.Buffers.Data.Data[v3->Index] = 0i64;
        v3->vfptr->__vecDelDtor(v3, 1u);
      }
    }
    for ( j = 0i64; j < this->IndexBuffers.Buffers.Data.Size; ++j )
    {
      v5 = this->IndexBuffers.Buffers.Data.Data[j];
      if ( v5 )
      {
        Scaleform::AllocAddr::RemoveSegment(&this->IndexBuffers.Allocator, v5->Index << 24, (v5->Size + 15) >> 4);
        this->IndexBuffers.TotalSize -= v5->Size;
        this->IndexBuffers.Buffers.Data.Data[v5->Index] = 0i64;
        v5->vfptr->__vecDelDtor(v5, 1u);
      }
    }
    p_LockedBuffers = (Scaleform::Render::MeshBuffer *)&this->LockedBuffers;
    if ( this == (Scaleform::Render::D3D1x::MeshCache *)-504i64 )
      p_LockedBuffers = 0i64;
    this->ChunkBuffers.Root.pPrev = p_LockedBuffers;
    this->ChunkBuffers.Root.pNext = p_LockedBuffers;
  }
  pObject = this->pMaskEraseBatchVertexBuffer.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->pMaskEraseBatchVertexBuffer.pObject = 0i64;
  v8 = this->pDevice.pObject;
  if ( v8 )
    ((void (__fastcall *)(ID3D11Device *))v8->vfptr->Release)(v8);
  this->pDevice.pObject = 0i64;
  v9 = this->pDeviceContext.pObject;
  if ( v9 )
    v9->vfptr->Release(v9);
  this->pDeviceContext.pObject = 0i64;
  Scaleform::Render::MeshStagingBuffer::Reset(&this->StagingBuffer);
}

// File Line: 106
// RVA: 0xA06E50
void __fastcall Scaleform::Render::D3D1x::MeshCache::ClearCache(Scaleform::Render::D3D1x::MeshCache *this)
{
  unsigned __int64 *p_VBSizeEvictedInLock; // rbp
  Scaleform::Render::D3D1x::MeshBuffer **i; // rdi
  __int64 v4; // rsi
  Scaleform::Render::D3D1x::MeshBuffer **j; // rdi
  __int64 v6; // rsi

  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&this->pShaderManager);
  p_VBSizeEvictedInLock = 0i64;
  for ( i = 0i64; i < this->VertexBuffers.Buffers.Data.Data; i = (Scaleform::Render::D3D1x::MeshBuffer **)((char *)i + 1) )
  {
    v4 = *((_QWORD *)&this->VertexBuffers.vfptr->__vecDelDtor + (_QWORD)i);
    if ( v4 && *(_DWORD *)(v4 + 28) == 2 )
    {
      Scaleform::AllocAddr::RemoveSegment(
        (Scaleform::AllocAddr *)&this->VertexBuffers.Buffers.Data.Policy,
        *(_QWORD *)(v4 + 48) << 24,
        (unsigned __int64)(*(_QWORD *)(v4 + 32) + 15i64) >> 4);
      this->VertexBuffers.Granularity -= *(_QWORD *)(v4 + 32);
      *((_QWORD *)&this->VertexBuffers.vfptr->__vecDelDtor + *(_QWORD *)(v4 + 48)) = 0i64;
      (**(void (__fastcall ***)(__int64, __int64))v4)(v4, 1i64);
    }
  }
  for ( j = 0i64; j < this->IndexBuffers.Buffers.Data.Data; j = (Scaleform::Render::D3D1x::MeshBuffer **)((char *)j + 1) )
  {
    v6 = *((_QWORD *)&this->IndexBuffers.vfptr->__vecDelDtor + (_QWORD)j);
    if ( v6 && *(_DWORD *)(v6 + 28) == 2 )
    {
      Scaleform::AllocAddr::RemoveSegment(
        (Scaleform::AllocAddr *)&this->IndexBuffers.Buffers.Data.Policy,
        *(_QWORD *)(v6 + 48) << 24,
        (unsigned __int64)(*(_QWORD *)(v6 + 32) + 15i64) >> 4);
      this->IndexBuffers.Granularity -= *(_QWORD *)(v6 + 32);
      *((_QWORD *)&this->IndexBuffers.vfptr->__vecDelDtor + *(_QWORD *)(v6 + 48)) = 0i64;
      (**(void (__fastcall ***)(__int64, __int64))v6)(v6, 1i64);
    }
  }
  if ( this != (Scaleform::Render::D3D1x::MeshCache *)-496i64 )
    p_VBSizeEvictedInLock = &this->VBSizeEvictedInLock;
  this->LockedBuffers.pFirst = (Scaleform::Render::D3D1x::MeshBuffer *)p_VBSizeEvictedInLock;
  this->ChunkBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)p_VBSizeEvictedInLock;
  Scaleform::Render::MeshStagingBuffer::Reset((Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch);
  Scaleform::Render::MeshStagingBuffer::Initialize(
    (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
    (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::vfptr,
    this->Params.LRUTailSize);
}

// File Line: 114
// RVA: 0xA08600
void __fastcall Scaleform::Render::D3D1x::MeshCache::destroyBuffers(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshBuffer::AllocType at)
{
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *p_ChunkBuffers; // rdi

  Scaleform::Render::MeshCacheListSet::EvictAll(&this->CacheList);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(&this->VertexBuffers, at);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(&this->IndexBuffers, at);
  p_ChunkBuffers = &this->ChunkBuffers;
  if ( p_ChunkBuffers )
  {
    p_ChunkBuffers->Root.pNext = (Scaleform::Render::MeshBuffer *)&p_ChunkBuffers[-1].Root.8;
    p_ChunkBuffers->Root.pPrev = (Scaleform::Render::MeshBuffer *)&p_ChunkBuffers[-1].Root.8;
  }
  else
  {
    MEMORY[8] = 0i64;
    MEMORY[0] = 0i64;
  }
}

// File Line: 123
// RVA: 0xA07E50
bool __fastcall Scaleform::Render::D3D1x::MeshCache::SetParams(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheParams *argParams)
{
  unsigned __int64 StagingBufferSize; // r14
  Scaleform::Render::RQCacheInterface *MemReserve; // rbp
  unsigned __int64 MemGranularity; // rsi
  unsigned int InstancingThreshold; // ebx
  unsigned int NoBatchVerticesSizeThreshold; // eax
  __int64 MaxVerticesSizeInBatch; // rdx
  unsigned int MaxBatchInstances; // eax
  bool result; // al
  Scaleform::Render::RQCacheInterface *pRQCaches; // rdx
  unsigned __int64 v13; // rcx
  __int128 v14; // [rsp+20h] [rbp-68h]
  __int128 v15; // [rsp+30h] [rbp-58h]
  __int128 v16; // [rsp+40h] [rbp-48h]
  __int128 v17; // [rsp+50h] [rbp-38h]
  __int64 v18; // [rsp+60h] [rbp-28h]

  StagingBufferSize = argParams->StagingBufferSize;
  MemReserve = (Scaleform::Render::RQCacheInterface *)argParams->MemReserve;
  MemGranularity = argParams->MemGranularity;
  InstancingThreshold = argParams->InstancingThreshold;
  v14 = *(_OWORD *)&argParams->MemReserve;
  *(_QWORD *)&v15 = MemGranularity;
  *((_QWORD *)&v15 + 1) = argParams->LRUTailSize;
  NoBatchVerticesSizeThreshold = argParams->NoBatchVerticesSizeThreshold;
  MaxVerticesSizeInBatch = argParams->MaxVerticesSizeInBatch;
  *((_QWORD *)&v17 + 1) = __PAIR64__(MaxVerticesSizeInBatch, NoBatchVerticesSizeThreshold);
  MaxBatchInstances = 24;
  LODWORD(v18) = argParams->MaxIndicesInBatch;
  if ( argParams->MaxBatchInstances < 0x18 )
    MaxBatchInstances = argParams->MaxBatchInstances;
  if ( !MaxBatchInstances )
    MaxBatchInstances = 1;
  LODWORD(v17) = MaxBatchInstances;
  *((_QWORD *)&v16 + 1) = 0x40000i64;
  if ( 2 * (MaxVerticesSizeInBatch + 2 * (unsigned __int64)argParams->MaxIndicesInBatch) > StagingBufferSize )
    StagingBufferSize = 2 * (MaxVerticesSizeInBatch + 2i64 * argParams->MaxIndicesInBatch);
  *(_QWORD *)&v16 = StagingBufferSize;
  if ( !Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport((Scaleform::Render::D3D1x::ShaderManager *)this->pDeviceContext.pObject) )
    InstancingThreshold = 0;
  DWORD1(v17) = InstancingThreshold;
  if ( !this->BatchCacheItemHash.pTable )
    goto LABEL_21;
  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&this->pShaderManager);
  if ( this->Params.LRUTailSize != StagingBufferSize
    && !Scaleform::Render::MeshStagingBuffer::Initialize(
          (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
          (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::vfptr,
          StagingBufferSize) )
  {
    Scaleform::Render::MeshStagingBuffer::Initialize(
      (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
      (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::vfptr,
      this->Params.LRUTailSize);
    return 0;
  }
  if ( this->pRQCaches == MemReserve && this->Params.MemLimit == MemGranularity )
    goto LABEL_21;
  Scaleform::Render::D3D1x::MeshCache::destroyBuffers(
    (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 8),
    AT_None);
  if ( !MemReserve
    || Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
         (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 8),
         (unsigned __int64)MemReserve,
         AT_Reserve,
         0) )
  {
    v13 = 5 * (MemGranularity >> 4);
    this->VertexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)(16 * (v13 / 9));
    this->IndexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)((MemGranularity & 0xFFFFFFFFFFFFFFF0ui64)
                                                                            - 16 * (v13 / 9));
LABEL_21:
    result = 1;
    *(_OWORD *)&this->pRQCaches = v14;
    *(_OWORD *)&this->Params.MemLimit = v15;
    *(_OWORD *)&this->Params.LRUTailSize = v16;
    *(_OWORD *)&this->Params.VBLockEvictSizeLimit = v17;
    *(_QWORD *)&this->Params.NoBatchVerticesSizeThreshold = v18;
    return result;
  }
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
    Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
      (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 8),
      (unsigned __int64)pRQCaches,
      AT_Reserve,
      0);
  return 0;
}

// File Line: 186
// RVA: 0xA08670
void __fastcall Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::MeshBuffer *pNext; // rdi
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *p_PendingDestructionBuffers; // rbp
  Scaleform::Render::MeshBuffer *v4; // rdx
  __int64 v5; // rax
  Scaleform::Render::MeshBuffer *v6; // r15
  Scaleform::Render::MeshCacheItem *v7; // rbx
  Scaleform::Render::Fence *pObject; // rax
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // [rsp+18h] [rbp-30h] BYREF
  __int64 *v12; // [rsp+20h] [rbp-28h]
  Scaleform::Render::MeshBuffer *v13; // [rsp+28h] [rbp-20h]

  pNext = this->PendingDestructionBuffers.Root.pNext;
  p_PendingDestructionBuffers = &this->PendingDestructionBuffers;
  v4 = (Scaleform::Render::MeshBuffer *)&v11;
  v12 = &v11;
  v13 = (Scaleform::Render::MeshBuffer *)&v11;
  while ( 1 )
  {
    v5 = p_PendingDestructionBuffers ? (__int64)&p_PendingDestructionBuffers[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::MeshBuffer *)v5 )
      break;
    v6 = pNext->pNext;
    v7 = this->CacheList.Slots[5].Root.pNext;
    pNext->pPrev->pNext = v6;
    pNext->pNext->pPrev = pNext->pPrev;
    pNext->pPrev = (Scaleform::Render::MeshBuffer *)-1i64;
    pNext->pNext = (Scaleform::Render::MeshBuffer *)-1i64;
    if ( v7 == (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[5] )
    {
LABEL_14:
      pNext->vfptr->__vecDelDtor(pNext, 1u);
      v4 = v13;
      pNext = v6;
    }
    else
    {
      while ( 1 )
      {
        if ( (Scaleform::Render::MeshBuffer *)v7[1].pPrev == pNext
          || (Scaleform::Render::MeshBuffer *)v7[1].pNext == pNext )
        {
          pObject = v7->GPUFence.pObject;
          if ( pObject )
          {
            if ( pObject->HasData && pObject->Data && Scaleform::Render::FenceImpl::IsPending(pObject->Data, 0i64) )
              break;
          }
        }
        v7 = v7->pNext;
        if ( v7 == (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[5] )
          goto LABEL_14;
      }
      v9 = (__int64)v13;
      pNext->pPrev = (Scaleform::Render::MeshBuffer *)&v11;
      v4 = pNext;
      pNext->pNext = (Scaleform::Render::MeshBuffer *)v9;
      v13->pPrev = pNext;
      v13 = pNext;
      pNext = v6;
    }
  }
  if ( v4 != (Scaleform::Render::MeshBuffer *)&v11 )
  {
    v10 = (__int64)v12;
    v12[2] = (__int64)p_PendingDestructionBuffers->Root.pNext;
    v4->pPrev = (Scaleform::Render::MeshBuffer *)&p_PendingDestructionBuffers[-1].Root.8;
    p_PendingDestructionBuffers->Root.pNext->pPrev = (Scaleform::Render::MeshBuffer *)v10;
    p_PendingDestructionBuffers->Root.pNext = v4;
  }
}

// File Line: 225
// RVA: 0xA07520
void __fastcall Scaleform::Render::D3D1x::MeshCache::EndFrame(Scaleform::Render::D3D1x::MeshCache *this)
{
  unsigned __int64 LRUTailSize; // rdx
  signed __int64 v3; // rbp
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *p_ChunkBuffers; // r14
  Scaleform::Render::MeshBuffer *p_LockedBuffers; // rax
  Scaleform::Render::D3D1x::MeshBuffer *pPrev; // rbx
  char *p_VertexBuffers; // r15
  bool v8; // di
  __int64 v9; // rax

  Scaleform::Render::MeshCacheListSet::EndFrame(&this->CacheList);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &this->IndexBuffers.Allocator);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &this->VertexBuffers.Allocator);
  Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(this);
  LRUTailSize = this->Params.LRUTailSize;
  if ( this->CacheList.Slots[4].Size < LRUTailSize )
    LRUTailSize = this->CacheList.Slots[4].Size;
  v3 = this->VertexBuffers.TotalSize
     + this->IndexBuffers.TotalSize
     - ((this->CacheList.Slots[3].Size + LRUTailSize) >> 2)
     - (this->CacheList.Slots[3].Size
      + LRUTailSize);
  if ( v3 > (signed __int64)this->Params.MemGranularity )
  {
    p_ChunkBuffers = &this->ChunkBuffers;
    while ( 1 )
    {
      p_LockedBuffers = (Scaleform::Render::MeshBuffer *)&this->LockedBuffers;
      if ( this == (Scaleform::Render::D3D1x::MeshCache *)-504i64 )
        p_LockedBuffers = 0i64;
      if ( this->ChunkBuffers.Root.pNext == p_LockedBuffers || v3 <= (signed __int64)this->Params.MemGranularity )
        break;
      pPrev = (Scaleform::Render::D3D1x::MeshBuffer *)p_ChunkBuffers->Root.pPrev;
      p_ChunkBuffers->Root.pPrev->pPrev->pNext = p_ChunkBuffers->Root.pPrev->pNext;
      pPrev->pNext->Scaleform::Render::MeshBuffer::pPrev = pPrev->pPrev;
      pPrev->pPrev = (Scaleform::Render::MeshBuffer *)-1i64;
      pPrev->pNext = (Scaleform::Render::MeshBuffer *)-1i64;
      v3 -= pPrev->Size;
      p_VertexBuffers = (char *)&this->VertexBuffers;
      if ( ((unsigned int (__fastcall *)(Scaleform::Render::D3D1x::MeshBuffer *))pPrev->vfptr[4].__vecDelDtor)(pPrev) )
        p_VertexBuffers = (char *)&this->IndexBuffers;
      v8 = Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer(this, this->CacheList.Slots, 6ui64, pPrev);
      Scaleform::AllocAddr::RemoveSegment(
        (Scaleform::AllocAddr *)(p_VertexBuffers + 32),
        pPrev->Index << 24,
        (pPrev->Size + 15) >> 4);
      v9 = *((_QWORD *)p_VertexBuffers + 1);
      *((_QWORD *)p_VertexBuffers + 8) -= pPrev->Size;
      *(_QWORD *)(v9 + 8 * pPrev->Index) = 0i64;
      if ( v8 )
      {
        pPrev->vfptr->__vecDelDtor(pPrev, 1u);
      }
      else
      {
        pPrev->pPrev = this->PendingDestructionBuffers.Root.pPrev;
        pPrev->pNext = (Scaleform::Render::MeshBuffer *)&this->ChunkBuffers.Root.8;
        this->PendingDestructionBuffers.Root.pPrev->pNext = pPrev;
        this->PendingDestructionBuffers.Root.pPrev = pPrev;
      }
    }
  }
}

// File Line: 295
// RVA: 0xA083D0
char __fastcall Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
        Scaleform::Render::D3D1x::MeshCache *this,
        unsigned __int64 size,
        unsigned int type,
        unsigned int arena)
{
  Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *p_VertexBuffers; // rdi
  unsigned __int64 v9; // rsi
  __int64 v10; // rbx

  p_VertexBuffers = &this->VertexBuffers;
  v9 = 16 * (5 * (size >> 4) / 9);
  v10 = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *, unsigned __int64))this->VertexBuffers.vfptr->CreateBuffer)(
          &this->VertexBuffers,
          v9);
  if ( !v10 )
    return 0;
  if ( !this->IndexBuffers.vfptr->CreateBuffer(
          &this->IndexBuffers,
          (size & 0xFFFFFFFFFFFFFFF0ui64) - (v9 & 0xFFFFFFFFFFFFFFF0ui64),
          type,
          arena,
          this->pHeap,
          this->pDevice.pObject) )
  {
    Scaleform::AllocAddr::RemoveSegment(
      &p_VertexBuffers->Allocator,
      *(_QWORD *)(v10 + 48) << 24,
      (unsigned __int64)(*(_QWORD *)(v10 + 32) + 15i64) >> 4);
    p_VertexBuffers->TotalSize -= *(_QWORD *)(v10 + 32);
    p_VertexBuffers->Buffers.Data.Data[*(_QWORD *)(v10 + 48)] = 0i64;
    (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
    return 0;
  }
  return 1;
}

// File Line: 324
// RVA: 0xA08500
bool __fastcall Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(
        Scaleform::Render::D3D1x::MeshCache *this,
        ID3D11Device *pdevice)
{
  char v4; // r9
  unsigned int v5; // r10d
  char *v6; // r8
  unsigned __int8 v7; // dl
  int v8; // eax
  __int64 v9; // rcx
  ID3D10DeviceVtbl *vfptr; // rax
  int v12[2]; // [rsp+20h] [rbp-6F8h] BYREF
  __int64 v13; // [rsp+28h] [rbp-6F0h]
  __int64 v14; // [rsp+30h] [rbp-6E8h]
  __int64 v15[3]; // [rsp+38h] [rbp-6E0h] BYREF
  char v16[16]; // [rsp+50h] [rbp-6C8h] BYREF
  char v17; // [rsp+60h] [rbp-6B8h] BYREF

  v12[0] = 1728;
  v12[1] = 1;
  v13 = 1i64;
  v14 = 0i64;
  v4 = 0;
  v5 = 0;
  v6 = &v17;
  do
  {
    v7 = 0;
    do
    {
      v8 = v7++;
      v9 = 3i64 * (v5 + v8);
      v16[4 * v9 + 8] = v4;
      v16[4 * v9 + 9] = v4;
      v16[4 * v9 + 10] = v4;
      v16[4 * v9 + 11] = v4;
    }
    while ( v7 < 6u );
    v5 += 6;
    *((_DWORD *)v6 - 4) = 0;
    *((_DWORD *)v6 - 3) = 1065353216;
    *(_QWORD *)(v6 - 4) = 0i64;
    *((_QWORD *)v6 + 1) = 1065353216i64;
    *((_DWORD *)v6 + 5) = 0;
    *((_DWORD *)v6 + 6) = 1065353216;
    *((_QWORD *)v6 + 4) = 1065353216i64;
    *((_DWORD *)v6 + 11) = 1065353216;
    *((_DWORD *)v6 + 12) = 1065353216;
    ++v4;
    v6 += 72;
  }
  while ( v5 < 0x90 );
  v15[0] = (__int64)v16;
  vfptr = pdevice->vfptr;
  v15[1] = 0i64;
  return ((int (__fastcall *)(ID3D11Device *, int *, __int64 *, Scaleform::Ptr<ID3D11Buffer> *))vfptr->VSSetConstantBuffers)(
           pdevice,
           v12,
           v15,
           &this->pMaskEraseBatchVertexBuffer) >= 0;
}

// File Line: 350
// RVA: 0xA07A10
char __fastcall Scaleform::Render::D3D1x::MeshCache::LockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::RQCacheInterface *pRQCaches; // rax

  pRQCaches = this->pRQCaches;
  this->Locked = 1;
  this->VBSizeEvictedInLock = 0i64;
  if ( pRQCaches )
    pRQCaches->LockFlags |= 1u;
  return 1;
}

// File Line: 360
// RVA: 0xA08050
void __fastcall Scaleform::Render::D3D1x::MeshCache::UnlockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshBuffer *pFirst; // rbx
  ID3D11DeviceContext *i; // rsi
  Scaleform::Render::RQCacheInterface *pRQCaches; // rax

  pFirst = this->LockedBuffers.pFirst;
  for ( i = this->pDeviceContext.pObject; pFirst; pFirst = pFirst->pNextLock )
    pFirst->vfptr[3].__vecDelDtor(pFirst, (unsigned int)i);
  this->LockedBuffers.pFirst = 0i64;
  pRQCaches = this->pRQCaches;
  this->Locked = 0;
  if ( pRQCaches )
    pRQCaches->LockFlags &= ~1u;
}

// File Line: 371
// RVA: 0xA087D0
bool __fastcall Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheListSet::ListSlot *plist,
        unsigned __int64 count,
        Scaleform::Render::D3D1x::MeshBuffer *pbuffer)
{
  char v4; // r15
  unsigned int v8; // r12d
  __int64 v9; // rax
  __int64 v10; // rax
  Scaleform::Render::MeshCacheItem *pNext; // rbx
  Scaleform::Render::MeshCacheListSet::ListSlot *v12; // rsi
  Scaleform::Render::D3D1x::MeshBuffer *pPrev; // rdx
  Scaleform::Render::D3D1x::MeshBuffer *v14; // rdx
  Scaleform::Render::MeshCacheListSet::ListSlot *v16; // [rsp+58h] [rbp+10h]

  v16 = plist;
  v4 = 0;
  v8 = 0;
  if ( count )
  {
    v9 = 0i64;
    do
    {
      v10 = v9;
      pNext = plist[v10].Root.pNext;
      v12 = &plist[v10];
      if ( pNext != (Scaleform::Render::MeshCacheItem *)v12 )
      {
        do
        {
          if ( (Scaleform::Render::D3D1x::MeshBuffer *)pNext[1].pPrev == pbuffer
            || (Scaleform::Render::D3D1x::MeshBuffer *)pNext[1].pNext == pbuffer )
          {
            if ( !((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, _QWORD))this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr[4].__vecDelDtor)(
                    this,
                    pNext,
                    0i64,
                    0i64) )
            {
              pPrev = (Scaleform::Render::D3D1x::MeshBuffer *)pNext[1].pPrev;
              v4 = 1;
              if ( pPrev == pbuffer )
              {
                Scaleform::AllocAddr::Free(
                  &this->VertexBuffers.Allocator,
                  ((unsigned __int64)pNext[1].pCacheList >> 4) | (pPrev->Index << 24),
                  (unsigned __int64)(*(_QWORD *)&pNext[1].ListType + 15i64) >> 4);
                pNext[1].pPrev = 0i64;
              }
              v14 = (Scaleform::Render::D3D1x::MeshBuffer *)pNext[1].pNext;
              if ( v14 == pbuffer )
              {
                Scaleform::AllocAddr::Free(
                  &this->IndexBuffers.Allocator,
                  ((unsigned __int64)pNext[1].PrimitiveBatches.Root.pPrev >> 4) | (v14->Index << 24),
                  ((unsigned __int64)&pNext[1].PrimitiveBatches.Root.pNext->pVoidNext + 7) >> 4);
                pNext[1].pNext = 0i64;
              }
            }
            pNext = v12->Root.pNext;
          }
          else
          {
            pNext = pNext->pNext;
          }
        }
        while ( pNext != (Scaleform::Render::MeshCacheItem *)v12 );
        plist = v16;
      }
      v9 = ++v8;
    }
    while ( v8 < count );
  }
  return v4 == 0;
}

// File Line: 414
// RVA: 0xA076E0
unsigned __int64 __fastcall Scaleform::Render::D3D1x::MeshCache::Evict(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pbatch,
        Scaleform::AllocAddr *pallocator,
        Scaleform::Render::MeshBase *pskipMesh)
{
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::MeshCacheItem *pNext; // rax
  Scaleform::Render::MeshCacheItem *pPrev; // rdx
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // rbp
  Scaleform::Render::MeshCacheItem *v14; // rdx

  pObject = pbatch->GPUFence.pObject;
  if ( pObject && pObject->HasData && pObject->Data && Scaleform::Render::FenceImpl::IsPending(pObject->Data, 0i64) )
  {
    Scaleform::Render::MeshCacheItem::Destroy(pbatch, pskipMesh, 0);
    pbatch->ListType = MCL_PendingFree;
    pNext = this->CacheList.Slots[5].Root.pNext;
    pbatch->pPrev = (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[5];
    pbatch->pNext = pNext;
    this->CacheList.Slots[5].Root.pNext->pPrev = pbatch;
    this->CacheList.Slots[5].Root.pNext = pbatch;
    this->CacheList.Slots[5].Size += pbatch->AllocSize;
    return 0i64;
  }
  else
  {
    pPrev = pbatch[1].pPrev;
    v12 = 0i64;
    if ( pPrev )
      v13 = 16
          * Scaleform::AllocAddr::Free(
              &this->VertexBuffers.Allocator,
              ((unsigned __int64)pbatch[1].pCacheList >> 4) | (*(_QWORD *)&pPrev->HashKey << 24),
              (unsigned __int64)(*(_QWORD *)&pbatch[1].ListType + 15i64) >> 4);
    else
      v13 = 0i64;
    v14 = pbatch[1].pNext;
    if ( v14 )
      v12 = 16
          * Scaleform::AllocAddr::Free(
              &this->IndexBuffers.Allocator,
              ((unsigned __int64)pbatch[1].PrimitiveBatches.Root.pPrev >> 4) | (*(_QWORD *)&v14->HashKey << 24),
              ((unsigned __int64)&pbatch[1].PrimitiveBatches.Root.pNext->pVoidNext + 7) >> 4);
    if ( pallocator )
    {
      if ( &this->VertexBuffers.Allocator == pallocator )
        v12 = v13;
    }
    else
    {
      v12 += v13;
    }
    this->VBSizeEvictedInLock += (unsigned int)pbatch[1].ListType;
    Scaleform::Render::MeshCacheItem::Destroy(pbatch, pskipMesh, 1);
    return v12;
  }
}

// File Line: 444
// RVA: 0xA08120
char __fastcall Scaleform::Render::D3D1x::MeshCache::allocBuffer(
        Scaleform::Render::D3D1x::MeshCache *this,
        unsigned __int64 *poffset,
        Scaleform::Render::D3D1x::MeshBuffer **pbuffer,
        Scaleform::Render::D3D1x::MeshBufferSet *mbs,
        unsigned __int64 size,
        bool waitForCache)
{
  unsigned __int64 Granularity; // rdx
  Scaleform::Render::MeshBuffer *v12; // rax
  Scaleform::Render::MeshCacheItem *pNext; // rbx
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::MeshCacheItem *v15; // rbx
  Scaleform::Render::Fence *v16; // rax

  if ( Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset) )
    return 1;
  if ( Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &mbs->Allocator) )
    return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset);
  if ( this->IndexBuffers.TotalSize + this->VertexBuffers.TotalSize + 0x4000 > this->Params.MemLimit )
    goto LABEL_14;
  if ( !Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(
          &this->CacheList,
          (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[4],
          &mbs->Allocator,
          size,
          (Scaleform::Render::MeshCacheListSet *)this->Params.LRUTailSize) )
  {
    Granularity = mbs->Granularity;
    if ( size > Granularity )
      return 0;
    if ( this->Params.MemLimit - this->VertexBuffers.TotalSize - this->IndexBuffers.TotalSize < Granularity )
      Granularity = this->Params.MemLimit - this->VertexBuffers.TotalSize - this->IndexBuffers.TotalSize;
    if ( size <= Granularity )
    {
      v12 = (Scaleform::Render::MeshBuffer *)((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshBufferSet *, unsigned __int64, __int64))mbs->vfptr->CreateBuffer)(
                                               mbs,
                                               Granularity,
                                               2i64);
      if ( v12 )
      {
        v12->pPrev = this->ChunkBuffers.Root.pPrev;
        v12->pNext = (Scaleform::Render::MeshBuffer *)&this->LockedBuffers;
        this->ChunkBuffers.Root.pPrev->pNext = v12;
        this->ChunkBuffers.Root.pPrev = v12;
        return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset);
      }
    }
LABEL_14:
    if ( Scaleform::Render::MeshCacheListSet::EvictLRU(
           &this->CacheList,
           &this->CacheList.Slots[4],
           &mbs->Allocator,
           size) )
    {
      return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset);
    }
    if ( this->VBSizeEvictedInLock <= this->Params.VBLockEvictSizeLimit )
    {
      pNext = this->CacheList.Slots[3].Root.pNext;
      while ( pNext != (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[3] )
      {
        pObject = pNext->GPUFence.pObject;
        if ( pObject
          && pObject->HasData
          && pObject->Data
          && Scaleform::Render::FenceImpl::IsPending(pObject->Data, 0i64) )
        {
          pNext = pNext->pNext;
        }
        else
        {
          if ( ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr[4].__vecDelDtor)(
                 this,
                 pNext,
                 &mbs->Allocator,
                 0i64) >= size )
            return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset);
          pNext = this->CacheList.Slots[3].Root.pNext;
        }
      }
      v15 = this->CacheList.Slots[2].Root.pNext;
      if ( waitForCache )
      {
        while ( v15 != (Scaleform::Render::MeshCacheItem *)&this->CacheList.Slots[2] )
        {
          v16 = v15->GPUFence.pObject;
          if ( v16 && v16->HasData )
          {
            if ( v16->Data )
              Scaleform::Render::FenceImpl::WaitFence(v16->Data, 0i64);
          }
          if ( ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr[4].__vecDelDtor)(
                 this,
                 v15,
                 &mbs->Allocator,
                 0i64) >= size )
            return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset);
          v15 = this->CacheList.Slots[2].Root.pNext;
        }
      }
    }
    return 0;
  }
  return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset);
}

// File Line: 546
// RVA: 0xA07A40
bool __fastcall Scaleform::Render::D3D1x::MeshCache::PreparePrimitive(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::PrimitiveBatch *pbatch,
        Scaleform::Render::MeshCacheItem::MeshContent *mc,
        bool waitForCache)
{
  Scaleform::Render::Primitive *pPrimitive; // r15
  Scaleform::Render::Mesh *v9; // r8
  int v10; // eax
  Scaleform::Render::MeshBase *v11; // rcx
  Scaleform::Render::MeshCacheItem **p_RefCount; // rdx
  int v14; // esi
  unsigned int Size; // r13d
  int v16; // eax
  bool v17; // bl
  char *pBuffer; // r14
  Scaleform::Render::VertexFormat *pFormat; // r15
  Scaleform::Render::VertexFormat *v20; // r12
  unsigned int v21; // eax
  char *v22; // r8
  __int64 v23; // rbx
  void *pdest; // [rsp+60h] [rbp-A0h] BYREF
  unsigned int ptotalVertices; // [rsp+68h] [rbp-98h] BYREF
  unsigned __int16 *v26; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::MeshCacheItem *p; // [rsp+78h] [rbp-88h] BYREF
  unsigned int ptotalIndices; // [rsp+80h] [rbp-80h] BYREF
  __int64 v29; // [rsp+88h] [rbp-78h]
  Scaleform::Render::MeshCache::StagingBufferPrep v30; // [rsp+90h] [rbp-70h] BYREF
  unsigned int v31; // [rsp+1F8h] [rbp+F8h] BYREF
  int *result; // [rsp+200h] [rbp+100h] BYREF

  v29 = -2i64;
  pPrimitive = pbatch->pPrimitive;
  if ( LODWORD(mc->Meshes.Size) && (v9 = (Scaleform::Render::Mesh *)*mc->Meshes.pData, v9->LargeMesh) )
  {
    Scaleform::Render::MeshCache::GenerateMesh(
      this,
      (Scaleform::Render::MeshCache::MeshResult *)&result,
      v9,
      pPrimitive->pFill.pObject->Data.pFormat,
      pbatch->pFormat,
      0i64,
      waitForCache);
    v10 = (int)result;
    if ( (int)result <= 1 )
    {
      v11 = *mc->Meshes.pData;
      if ( v11[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr <= (Scaleform::RefCountImplCoreVtbl *)2 )
        p_RefCount = (Scaleform::Render::MeshCacheItem **)&v11[1].RefCount;
      else
        p_RefCount = *(Scaleform::Render::MeshCacheItem ***)&v11[1].RefCount;
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&pbatch->MeshNode, *p_RefCount);
      v10 = (int)result;
    }
    return v10 != 3;
  }
  else
  {
    Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
      &v30,
      this,
      mc,
      pPrimitive->pFill.pObject->Data.pFormat,
      0);
    Scaleform::Render::PrimitiveBatch::CalcMeshSizes(pbatch, &ptotalVertices, &ptotalIndices);
    v14 = 0;
    p = 0i64;
    Size = pbatch->pFormat->Size;
    v16 = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem **, void **, unsigned __int16 **, _DWORD, Scaleform::Render::MeshCacheItem::MeshContent *, _QWORD, unsigned int, unsigned int, bool, _QWORD))this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr[6].__vecDelDtor)(
            this,
            &p,
            &pdest,
            &v26,
            0,
            mc,
            ptotalVertices * Size,
            ptotalVertices,
            ptotalIndices,
            waitForCache,
            0i64);
    if ( v16 == 3 )
    {
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&pbatch->MeshNode, p);
      Scaleform::Render::MeshCache::StagingBufferPrep::GenerateMeshes(&v30, p);
      pBuffer = this->StagingBuffer.pBuffer;
      pFormat = pPrimitive->pFill.pObject->Data.pFormat;
      v20 = pbatch->pFormat;
      v21 = 0;
      v31 = 0;
      if ( LODWORD(mc->Meshes.Size) )
      {
        v22 = (char *)pdest;
        do
        {
          v23 = *(__int64 *)((char *)mc->Meshes.pData + mc->Meshes.StrideSize * v21);
          result = (int *)&v31;
          Scaleform::Render::ConvertVertices_Buffered(
            pFormat,
            &pBuffer[*(_QWORD *)(v23 + 48)],
            v20,
            v22,
            *(_DWORD *)(v23 + 68),
            (const void **)&result);
          Scaleform::Render::ConvertIndices(
            v26,
            (unsigned __int16 *)&pBuffer[*(_QWORD *)(v23 + 56)],
            *(_DWORD *)(v23 + 72),
            v14);
          v22 = (char *)pdest + *(_DWORD *)(v23 + 68) * Size;
          pdest = v22;
          v26 += *(unsigned int *)(v23 + 72);
          v14 += *(_DWORD *)(v23 + 68);
          v21 = v31 + 1;
          v31 = v21;
        }
        while ( v21 < LODWORD(mc->Meshes.Size) );
      }
      v17 = 1;
    }
    else
    {
      v17 = v16 != 0;
    }
    Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(&v30);
    return v17;
  }
}

// File Line: 643
// RVA: 0xA06B40
__int64 __fastcall Scaleform::Render::D3D1x::MeshCache::AllocCacheItem(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheItem **pdata,
        char **pvertexDataStart,
        unsigned __int16 **pindexDataStart,
        Scaleform::Render::MeshCacheItem::MeshType meshType,
        Scaleform::Render::MeshCacheItem::MeshBaseContent *mc,
        unsigned __int64 vertexBufferSize,
        unsigned int vertexCount,
        unsigned int indexCount,
        bool waitForCache)
{
  unsigned __int64 v12; // rdi
  bool v13; // r15
  Scaleform::Render::D3D1x::IndexBuffer *v14; // rsi
  unsigned int v15; // ebp
  bool v16; // al
  unsigned __int64 v17; // r13
  Scaleform::Render::D3D1x::VertexBuffer *v18; // r14
  unsigned int v19; // r12d
  char *v20; // r12
  char *v21; // r15
  Scaleform::Render::D3D1x::MeshCacheItem *v22; // rax
  Scaleform::Render::D3D1x::MeshBuffer *v23; // [rsp+60h] [rbp-68h] BYREF
  unsigned __int64 poffset; // [rsp+68h] [rbp-60h] BYREF
  Scaleform::Render::D3D1x::MeshBuffer *pbuffer; // [rsp+70h] [rbp-58h] BYREF
  unsigned __int64 v26; // [rsp+D0h] [rbp+8h] BYREF
  Scaleform::Render::MeshCacheItem **v27; // [rsp+D8h] [rbp+10h]
  char **v28; // [rsp+E0h] [rbp+18h]
  unsigned __int16 **v29; // [rsp+E8h] [rbp+20h]

  v29 = pindexDataStart;
  v28 = pvertexDataStart;
  v27 = pdata;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *))this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr[3].__vecDelDtor)(this)
    && !((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *))this->Scaleform::Render::MeshCache::Scaleform::Render::CacheBase::vfptr[2].UnlockBuffers)(this) )
  {
    return 4i64;
  }
  v12 = 0i64;
  v13 = waitForCache;
  poffset = 0i64;
  v26 = 0i64;
  pbuffer = 0i64;
  v14 = 0i64;
  v23 = 0i64;
  v15 = 0;
  v16 = Scaleform::Render::D3D1x::MeshCache::allocBuffer(
          this,
          &poffset,
          &pbuffer,
          &this->VertexBuffers,
          vertexBufferSize,
          waitForCache);
  v17 = poffset;
  v18 = (Scaleform::Render::D3D1x::VertexBuffer *)pbuffer;
  if ( v16 )
  {
    v19 = indexCount;
    pbuffer = (Scaleform::Render::D3D1x::MeshBuffer *)(2i64 * indexCount);
    if ( !Scaleform::Render::D3D1x::MeshCache::allocBuffer(
            this,
            &v26,
            &v23,
            &this->IndexBuffers,
            (unsigned __int64)pbuffer,
            v13) )
    {
      v12 = v26;
      v14 = (Scaleform::Render::D3D1x::IndexBuffer *)v23;
      goto $handle_alloc_fail;
    }
    if ( !v18->pData )
    {
      if ( !v18->vfptr[2].__vecDelDtor(v18, (unsigned int)this->pDeviceContext.pObject) )
      {
        v20 = 0i64;
        goto LABEL_11;
      }
      v18->pNextLock = this->LockedBuffers.pFirst;
      this->LockedBuffers.pFirst = v18;
    }
    v20 = (char *)v18->pData;
LABEL_11:
    v14 = (Scaleform::Render::D3D1x::IndexBuffer *)v23;
    if ( !v23->pData )
    {
      if ( !v23->vfptr[2].__vecDelDtor(v23, this->pDeviceContext.pObject) )
      {
        v21 = 0i64;
LABEL_16:
        if ( v20 && v21 )
        {
          v12 = v26;
          v22 = Scaleform::Render::D3D1x::MeshCacheItem::Create(
                  meshType,
                  &this->CacheList,
                  mc,
                  v18,
                  v14,
                  (unsigned int)v17,
                  vertexBufferSize,
                  vertexCount,
                  (unsigned int)v26,
                  (unsigned __int64)pbuffer,
                  indexCount);
          *v27 = v22;
          if ( v22 )
          {
            *v28 = &v20[v17];
            *v29 = (unsigned __int16 *)&v21[v12];
            return 3i64;
          }
          v15 = 4;
        }
        else
        {
          v12 = v26;
        }
        goto LABEL_20;
      }
      v14->pNextLock = this->LockedBuffers.pFirst;
      this->LockedBuffers.pFirst = v14;
    }
    v21 = (char *)v14->pData;
    goto LABEL_16;
  }
LABEL_20:
  v19 = indexCount;
$handle_alloc_fail:
  if ( v18 )
    Scaleform::AllocAddr::Free(
      &this->VertexBuffers.Allocator,
      (v17 >> 4) | (v18->Index << 24),
      (vertexBufferSize + 15) >> 4);
  if ( v14 )
    Scaleform::AllocAddr::Free(
      &this->IndexBuffers.Allocator,
      (v12 >> 4) | (v14->Index << 24),
      (2 * (unsigned __int64)v19 + 15) >> 4);
  return v15;
}

// File Line: 692
// RVA: 0xA07840
void __fastcall Scaleform::Render::D3D1x::MeshCache::GetStats(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCache::Stats *stats)
{
  stats->TotalSize[0] = 0i64;
  stats->TotalSize[1] = 0i64;
  stats->TotalSize[2] = 0i64;
  stats->TotalSize[3] = 0i64;
  stats->TotalSize[4] = 0i64;
  stats->TotalSize[5] = 0i64;
  stats->TotalSize[6] = 0i64;
  stats->UsedSize[0] = 0i64;
  stats->UsedSize[1] = 0i64;
  stats->UsedSize[2] = 0i64;
  stats->UsedSize[3] = 0i64;
  stats->UsedSize[4] = 0i64;
  stats->UsedSize[5] = 0i64;
  stats->UsedSize[6] = 0i64;
  stats->TotalSize[5] = this->VertexBuffers.TotalSize;
  stats->UsedSize[5] = 16 * Scaleform::AllocAddr::GetFreeSize(&this->VertexBuffers.Allocator);
  stats->TotalSize[6] = this->IndexBuffers.TotalSize;
  stats->UsedSize[6] = 16 * Scaleform::AllocAddr::GetFreeSize(&this->IndexBuffers.Allocator);
}

