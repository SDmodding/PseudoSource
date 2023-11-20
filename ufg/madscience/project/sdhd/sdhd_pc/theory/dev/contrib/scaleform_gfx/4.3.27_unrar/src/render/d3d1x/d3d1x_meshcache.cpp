// File Line: 54
// RVA: 0xA06410
void __fastcall Scaleform::Render::D3D1x::MeshCache::MeshCache(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::MemoryHeap *pheap, Scaleform::Render::MeshCacheParams *params)
{
  Scaleform::Render::MeshCacheParams *v3; // rsi
  Scaleform::MemoryHeap *v4; // rbp
  Scaleform::Render::D3D1x::MeshCache *v5; // r14
  Scaleform::Render::MeshCacheListSet::ListSlot *v6; // rcx
  unsigned __int64 v7; // rbx
  Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *v8; // rdi
  unsigned __int64 v9; // rbx
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer> *v12; // [rsp+80h] [rbp+18h]
  signed __int64 v13; // [rsp+88h] [rbp+20h]
  signed __int64 v14; // [rsp+88h] [rbp+20h]

  v3 = params;
  v4 = pheap;
  v5 = this;
  Scaleform::Render::MeshCache::MeshCache((Scaleform::Render::MeshCache *)&this->vfptr, pheap, params);
  v5->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  v5->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  v5->pDevice.pObject = 0i64;
  v5->pDeviceContext.pObject = 0i64;
  v5->CacheList.pCache = (Scaleform::Render::MeshCache *)&v5->vfptr;
  v6 = v5->CacheList.Slots;
  v6->Root.pPrev = (Scaleform::Render::MeshCacheItem *)v6;
  v6->Root.pNext = (Scaleform::Render::MeshCacheItem *)v6;
  v6->Size = 0i64;
  v5->CacheList.Slots[1].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[1];
  v6[1].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[1];
  v6[1].Size = 0i64;
  v5->CacheList.Slots[2].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[2];
  v6[2].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[2];
  v6[2].Size = 0i64;
  v5->CacheList.Slots[3].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[3];
  v6[3].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[3];
  v6[3].Size = 0i64;
  v5->CacheList.Slots[4].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[4];
  v6[4].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[4];
  v6[4].Size = 0i64;
  v5->CacheList.Slots[5].Root.pPrev = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[5];
  v6[5].Root.pNext = (Scaleform::Render::MeshCacheItem *)&v5->CacheList.Slots[5];
  v6[5].Size = 0i64;
  v7 = 16 * ((unsigned __int64)(5 * (v3->MemGranularity >> 4) * (unsigned __int128)0xE38E38E38E38E38Fui64 >> 64) >> 3);
  v8 = &v5->VertexBuffers;
  v8->vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  v13 = (signed __int64)&v5->VertexBuffers.Buffers;
  *(_OWORD *)v13 = 0ui64;
  *(_QWORD *)(v13 + 16) = 0i64;
  Scaleform::AllocAddr::AllocAddr(&v5->VertexBuffers.Allocator, v4);
  v5->VertexBuffers.Granularity = v7;
  v5->VertexBuffers.TotalSize = 0i64;
  v8->vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>::`vftable';
  v9 = (v3->MemGranularity & 0xFFFFFFFFFFFFFFF0ui64) - (v5->VertexBuffers.Granularity & 0xFFFFFFFFFFFFFFF0ui64);
  v12 = &v5->IndexBuffers;
  v12->vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  v14 = (signed __int64)&v5->IndexBuffers.Buffers;
  *(_OWORD *)v14 = 0ui64;
  *(_QWORD *)(v14 + 16) = 0i64;
  Scaleform::AllocAddr::AllocAddr(&v5->IndexBuffers.Allocator, v4);
  v5->IndexBuffers.Granularity = v9;
  v5->IndexBuffers.TotalSize = 0i64;
  v12->vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::`vftable';
  v5->Locked = 0;
  v5->VBSizeEvictedInLock = 0i64;
  v5->LockedBuffers.pFirst = 0i64;
  v10 = (signed __int64)&v5->LockedBuffers;
  if ( v5 == (Scaleform::Render::D3D1x::MeshCache *)-504i64 )
    v10 = 0i64;
  v5->ChunkBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)v10;
  v5->ChunkBuffers.Root.pNext = (Scaleform::Render::MeshBuffer *)v10;
  v11 = (signed __int64)&v5->ChunkBuffers.Root.8;
  if ( v5 == (Scaleform::Render::D3D1x::MeshCache *)-520i64 )
    v11 = 0i64;
  v5->PendingDestructionBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)v11;
  v5->PendingDestructionBuffers.Root.pNext = (Scaleform::Render::MeshBuffer *)v11;
  v5->pMaskEraseBatchVertexBuffer.pObject = 0i64;
}

// File Line: 58
// RVA: 0xA06730
void __fastcall Scaleform::Render::D3D1x::MeshCache::~MeshCache(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshCache *v1; // rdi
  ID3D11Buffer *v2; // rcx
  ID3D11DeviceContext *v3; // rcx
  ID3D11Device *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)&Scaleform::Render::D3D1x::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  Scaleform::Render::D3D1x::MeshCache::Reset(this);
  v2 = v1->pMaskEraseBatchVertexBuffer.pObject;
  if ( v2 )
    ((void (__cdecl *)(ID3D11Buffer *))v2->vfptr->Release)(v2);
  v1->IndexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  Scaleform::AllocAddr::~AllocAddr(&v1->IndexBuffers.Allocator);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->IndexBuffers.Buffers.Data.Data);
  v1->VertexBuffers.vfptr = (Scaleform::Render::D3D1x::MeshBufferSetVtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  Scaleform::AllocAddr::~AllocAddr(&v1->VertexBuffers.Allocator);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->VertexBuffers.Buffers.Data.Data);
  v3 = v1->pDeviceContext.pObject;
  if ( v3 )
    ((void (__cdecl *)(ID3D11DeviceContext *))v3->vfptr->Release)(v3);
  v4 = v1->pDevice.pObject;
  if ( v4 )
    ((void (__cdecl *)(ID3D11Device *))v4->vfptr->Release)(v4);
  Scaleform::Render::MeshCache::~MeshCache((Scaleform::Render::MeshCache *)&v1->vfptr);
}

// File Line: 65
// RVA: 0xA078E0
char __fastcall Scaleform::Render::D3D1x::MeshCache::Initialize(Scaleform::Render::D3D1x::MeshCache *this, ID3D11Device *pdevice, ID3D11DeviceContext *pcontext, Scaleform::Render::D3D1x::ShaderManager *psm)
{
  Scaleform::Render::D3D1x::ShaderManager *v4; // rbp
  ID3D11DeviceContext *v5; // rsi
  ID3D11Device *v6; // rdi
  Scaleform::Render::D3D1x::MeshCache *v7; // rbx
  ID3D11Device *v8; // rcx
  ID3D11DeviceContext *v9; // rcx
  __int64 v10; // rax
  unsigned int v11; // ecx
  unsigned __int64 v12; // rdx
  unsigned __int64 v14; // rdx

  v4 = psm;
  v5 = pcontext;
  v6 = pdevice;
  v7 = this;
  if ( pdevice )
    ((void (__fastcall *)(ID3D11Device *))pdevice->vfptr->AddRef)(pdevice);
  v8 = v7->pDevice.pObject;
  if ( v8 )
    ((void (*)(void))v8->vfptr->Release)();
  v7->pDevice.pObject = v6;
  if ( v5 )
    v5->vfptr->AddRef((IUnknown *)&v5->vfptr);
  v9 = v7->pDeviceContext.pObject;
  if ( v9 )
    ((void (*)(void))v9->vfptr->Release)();
  v7->pDeviceContext.pObject = v5;
  v7->pShaderManager = v4;
  v10 = v7->Params.MaxVerticesSizeInBatch;
  v11 = 24;
  v7->Params.VBLockEvictSizeLimit = 0x40000i64;
  if ( v7->Params.MaxBatchInstances < 0x18 )
    v11 = v7->Params.MaxBatchInstances;
  if ( v11 < 1 )
    v11 = 1;
  v7->Params.MaxBatchInstances = v11;
  v12 = 2 * (v10 + 2i64 * v7->Params.MaxIndicesInBatch);
  if ( v12 > v7->Params.StagingBufferSize )
    v7->Params.StagingBufferSize = v12;
  if ( !Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport(v4) )
    v7->Params.InstancingThreshold = 0;
  if ( !Scaleform::Render::MeshStagingBuffer::Initialize(&v7->StagingBuffer, v7->pHeap, v7->Params.StagingBufferSize) )
    return 0;
  if ( !Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(v7, v6)
    || (v14 = v7->Params.MemReserve) != 0
    && !Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(v7, v14, AT_Reserve, 0) )
  {
    Scaleform::Render::D3D1x::MeshCache::Reset(v7);
    return 0;
  }
  return 1;
}

// File Line: 94
// RVA: 0xA07CB0
void __fastcall Scaleform::Render::D3D1x::MeshCache::Reset(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshCache *v1; // rbx
  unsigned __int64 i; // rdi
  Scaleform::Render::D3D1x::MeshBuffer *v3; // rsi
  unsigned __int64 j; // rdi
  Scaleform::Render::D3D1x::MeshBuffer *v5; // rsi
  signed __int64 v6; // rcx
  ID3D11Buffer *v7; // rcx
  ID3D11Device *v8; // rcx
  ID3D11DeviceContext *v9; // rcx

  v1 = this;
  if ( this->pDevice.pObject )
  {
    Scaleform::Render::MeshCacheListSet::EvictAll(&this->CacheList);
    for ( i = 0i64; i < v1->VertexBuffers.Buffers.Data.Size; ++i )
    {
      v3 = v1->VertexBuffers.Buffers.Data.Data[i];
      if ( v3 )
      {
        Scaleform::AllocAddr::RemoveSegment(&v1->VertexBuffers.Allocator, v3->Index << 24, (v3->Size + 15) >> 4);
        v1->VertexBuffers.TotalSize -= v3->Size;
        v1->VertexBuffers.Buffers.Data.Data[v3->Index] = 0i64;
        v3->vfptr->__vecDelDtor((Scaleform::Render::MeshBuffer *)&v3->vfptr, 1u);
      }
    }
    for ( j = 0i64; j < v1->IndexBuffers.Buffers.Data.Size; ++j )
    {
      v5 = v1->IndexBuffers.Buffers.Data.Data[j];
      if ( v5 )
      {
        Scaleform::AllocAddr::RemoveSegment(&v1->IndexBuffers.Allocator, v5->Index << 24, (v5->Size + 15) >> 4);
        v1->IndexBuffers.TotalSize -= v5->Size;
        v1->IndexBuffers.Buffers.Data.Data[v5->Index] = 0i64;
        v5->vfptr->__vecDelDtor((Scaleform::Render::MeshBuffer *)&v5->vfptr, 1u);
      }
    }
    v6 = (signed __int64)&v1->LockedBuffers;
    if ( v1 == (Scaleform::Render::D3D1x::MeshCache *)-504i64 )
      v6 = 0i64;
    v1->ChunkBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)v6;
    v1->ChunkBuffers.Root.pNext = (Scaleform::Render::MeshBuffer *)v6;
  }
  v7 = v1->pMaskEraseBatchVertexBuffer.pObject;
  if ( v7 )
    ((void (*)(void))v7->vfptr->Release)();
  v1->pMaskEraseBatchVertexBuffer.pObject = 0i64;
  v8 = v1->pDevice.pObject;
  if ( v8 )
    ((void (*)(void))v8->vfptr->Release)();
  v1->pDevice.pObject = 0i64;
  v9 = v1->pDeviceContext.pObject;
  if ( v9 )
    ((void (*)(void))v9->vfptr->Release)();
  v1->pDeviceContext.pObject = 0i64;
  Scaleform::Render::MeshStagingBuffer::Reset(&v1->StagingBuffer);
}

// File Line: 106
// RVA: 0xA06E50
void __fastcall Scaleform::Render::D3D1x::MeshCache::ClearCache(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshCache *v1; // rbx
  signed __int64 v2; // rbp
  Scaleform::Render::D3D1x::MeshBuffer **v3; // rdi
  __int64 v4; // rsi
  Scaleform::Render::D3D1x::MeshBuffer **v5; // rdi
  __int64 v6; // rsi

  v1 = this;
  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&this->pShaderManager);
  v2 = 0i64;
  v3 = 0i64;
  if ( v1->VertexBuffers.Buffers.Data.Data )
  {
    do
    {
      v4 = *((_QWORD *)&v1->VertexBuffers.vfptr->__vecDelDtor + (_QWORD)v3);
      if ( v4 && *(_DWORD *)(v4 + 28) == 2 )
      {
        Scaleform::AllocAddr::RemoveSegment(
          (Scaleform::AllocAddr *)&v1->VertexBuffers.Buffers.Data.Policy,
          *(_QWORD *)(v4 + 48) << 24,
          (unsigned __int64)(*(_QWORD *)(v4 + 32) + 15i64) >> 4);
        v1->VertexBuffers.Granularity -= *(_QWORD *)(v4 + 32);
        *((_QWORD *)&v1->VertexBuffers.vfptr->__vecDelDtor + *(_QWORD *)(v4 + 48)) = 0i64;
        (**(void (__fastcall ***)(__int64, signed __int64))v4)(v4, 1i64);
      }
      v3 = (Scaleform::Render::D3D1x::MeshBuffer **)((char *)v3 + 1);
    }
    while ( v3 < v1->VertexBuffers.Buffers.Data.Data );
  }
  v5 = 0i64;
  if ( v1->IndexBuffers.Buffers.Data.Data > 0 )
  {
    do
    {
      v6 = *((_QWORD *)&v1->IndexBuffers.vfptr->__vecDelDtor + (_QWORD)v5);
      if ( v6 && *(_DWORD *)(v6 + 28) == 2 )
      {
        Scaleform::AllocAddr::RemoveSegment(
          (Scaleform::AllocAddr *)&v1->IndexBuffers.Buffers.Data.Policy,
          *(_QWORD *)(v6 + 48) << 24,
          (unsigned __int64)(*(_QWORD *)(v6 + 32) + 15i64) >> 4);
        v1->IndexBuffers.Granularity -= *(_QWORD *)(v6 + 32);
        *((_QWORD *)&v1->IndexBuffers.vfptr->__vecDelDtor + *(_QWORD *)(v6 + 48)) = 0i64;
        (**(void (__fastcall ***)(__int64, signed __int64))v6)(v6, 1i64);
      }
      v5 = (Scaleform::Render::D3D1x::MeshBuffer **)((char *)v5 + 1);
    }
    while ( v5 < v1->IndexBuffers.Buffers.Data.Data );
  }
  if ( v1 != (Scaleform::Render::D3D1x::MeshCache *)-496i64 )
    v2 = (signed __int64)&v1->VBSizeEvictedInLock;
  v1->LockedBuffers.pFirst = (Scaleform::Render::D3D1x::MeshBuffer *)v2;
  v1->ChunkBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)v2;
  Scaleform::Render::MeshStagingBuffer::Reset((Scaleform::Render::MeshStagingBuffer *)&v1->Params.MaxIndicesInBatch);
  Scaleform::Render::MeshStagingBuffer::Initialize(
    (Scaleform::Render::MeshStagingBuffer *)&v1->Params.MaxIndicesInBatch,
    (Scaleform::MemoryHeap *)v1->vfptr,
    v1->Params.LRUTailSize);
}

// File Line: 114
// RVA: 0xA08600
void __fastcall Scaleform::Render::D3D1x::MeshCache::destroyBuffers(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::MeshBuffer::AllocType at)
{
  Scaleform::Render::D3D1x::MeshCache *v2; // rdi
  Scaleform::Render::MeshBuffer::AllocType v3; // ebx
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *v4; // rdi

  v2 = this;
  v3 = at;
  Scaleform::Render::MeshCacheListSet::EvictAll(&this->CacheList);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(
    (Scaleform::Render::D3D1x::MeshBufferSet *)&v2->VertexBuffers.vfptr,
    v3);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(
    (Scaleform::Render::D3D1x::MeshBufferSet *)&v2->IndexBuffers.vfptr,
    v3);
  v4 = &v2->ChunkBuffers;
  if ( v4 )
  {
    v4->Root.pNext = (Scaleform::Render::MeshBuffer *)&v4[-1].Root.8;
    v4->Root.pPrev = (Scaleform::Render::MeshBuffer *)&v4[-1].Root.8;
  }
  else
  {
    MEMORY[8] = 0i64;
    MEMORY[0] = 0i64;
  }
}

// File Line: 123
// RVA: 0xA07E50
char __fastcall Scaleform::Render::D3D1x::MeshCache::SetParams(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::MeshCacheParams *argParams)
{
  unsigned __int64 v2; // r14
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // eax
  Scaleform::Render::MeshCacheParams *v7; // r9
  __int64 v8; // rdx
  Scaleform::Render::D3D1x::MeshCache *v9; // rdi
  unsigned int v10; // eax
  char result; // al
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rdx
  __int128 v14; // [rsp+20h] [rbp-68h]
  __int128 v15; // [rsp+30h] [rbp-58h]
  __int128 v16; // [rsp+40h] [rbp-48h]
  __int128 v17; // [rsp+50h] [rbp-38h]
  __int64 v18; // [rsp+60h] [rbp-28h]

  v2 = argParams->StagingBufferSize;
  v3 = argParams->MemReserve;
  v4 = argParams->MemGranularity;
  v5 = argParams->InstancingThreshold;
  v14 = *(_OWORD *)&argParams->MemReserve;
  v15 = *(_OWORD *)&argParams->MemGranularity;
  v6 = argParams->NoBatchVerticesSizeThreshold;
  v7 = argParams;
  v8 = argParams->MaxVerticesSizeInBatch;
  *((_QWORD *)&v17 + 1) = __PAIR__(v8, v6);
  v9 = this;
  v10 = 24;
  LODWORD(v18) = v7->MaxIndicesInBatch;
  if ( v7->MaxBatchInstances < 0x18 )
    v10 = v7->MaxBatchInstances;
  if ( v10 < 1 )
    v10 = 1;
  LODWORD(v17) = v10;
  *((_QWORD *)&v16 + 1) = 0x40000i64;
  if ( 2 * (v8 + 2 * (unsigned __int64)v7->MaxIndicesInBatch) > v2 )
    v2 = 2 * (v8 + 2i64 * v7->MaxIndicesInBatch);
  *(_QWORD *)&v16 = v2;
  if ( !Scaleform::Render::D3D1x::ShaderManager::HasInstancingSupport((Scaleform::Render::D3D1x::ShaderManager *)this->pDeviceContext.pObject) )
    v5 = 0;
  DWORD1(v17) = v5;
  if ( !v9->BatchCacheItemHash.pTable )
    goto LABEL_21;
  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&v9->pShaderManager);
  if ( v9->Params.LRUTailSize != v2
    && !Scaleform::Render::MeshStagingBuffer::Initialize(
          (Scaleform::Render::MeshStagingBuffer *)&v9->Params.MaxIndicesInBatch,
          (Scaleform::MemoryHeap *)v9->vfptr,
          v2) )
  {
    Scaleform::Render::MeshStagingBuffer::Initialize(
      (Scaleform::Render::MeshStagingBuffer *)&v9->Params.MaxIndicesInBatch,
      (Scaleform::MemoryHeap *)v9->vfptr,
      v9->Params.LRUTailSize);
    return 0;
  }
  if ( v9->pRQCaches == (Scaleform::Render::RQCacheInterface *)v3 && v9->Params.MemLimit == v4 )
    goto LABEL_21;
  Scaleform::Render::D3D1x::MeshCache::destroyBuffers((Scaleform::Render::D3D1x::MeshCache *)((char *)v9 - 8), 0);
  if ( !v3
    || Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
         (Scaleform::Render::D3D1x::MeshCache *)((char *)v9 - 8),
         v3,
         AT_Reserve,
         0) )
  {
    v13 = 16 * ((unsigned __int64)(5 * (v4 >> 4) * (unsigned __int128)0xE38E38E38E38E38Fui64 >> 64) >> 3);
    v9->VertexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)v13;
    v9->IndexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)((v4 & 0xFFFFFFFFFFFFFFF0ui64)
                                                                          - (v13 & 0xFFFFFFFFFFFFFFF0ui64));
LABEL_21:
    result = 1;
    *(_OWORD *)&v9->pRQCaches = v14;
    *(_OWORD *)&v9->Params.MemLimit = v15;
    *(_OWORD *)&v9->Params.LRUTailSize = v16;
    *(_OWORD *)&v9->Params.VBLockEvictSizeLimit = v17;
    *(_QWORD *)&v9->Params.NoBatchVerticesSizeThreshold = v18;
    return result;
  }
  v12 = (unsigned __int64)v9->pRQCaches;
  if ( v12 )
    Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
      (Scaleform::Render::D3D1x::MeshCache *)((char *)v9 - 8),
      v12,
      AT_Reserve,
      0);
  return 0;
}

// File Line: 186
// RVA: 0xA08670
void __fastcall Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::MeshBuffer *v1; // rdi
  Scaleform::Render::D3D1x::MeshCache *v2; // r13
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *v3; // rbp
  Scaleform::Render::MeshBuffer *v4; // rdx
  signed __int64 v5; // rax
  Scaleform::Render::MeshBuffer *v6; // r15
  Scaleform::Render::MeshCacheItem *v7; // rbx
  Scaleform::Render::Fence *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // [rsp+18h] [rbp-30h]
  __int64 *v12; // [rsp+20h] [rbp-28h]
  Scaleform::Render::MeshBuffer *v13; // [rsp+28h] [rbp-20h]

  v1 = this->PendingDestructionBuffers.Root.pNext;
  v2 = this;
  v3 = &this->PendingDestructionBuffers;
  v4 = (Scaleform::Render::MeshBuffer *)&v11;
  v12 = &v11;
  v13 = (Scaleform::Render::MeshBuffer *)&v11;
  while ( 1 )
  {
    v5 = (signed __int64)(v3 ? &v3[-1].Root.8 : 0i64);
    if ( v1 == (Scaleform::Render::MeshBuffer *)v5 )
      break;
    v6 = v1->pNext;
    v7 = v2->CacheList.Slots[5].Root.pNext;
    v1->pPrev->pNext = v6;
    v1->pNext->pPrev = v1->pPrev;
    v1->pPrev = (Scaleform::Render::MeshBuffer *)-1i64;
    v1->pNext = (Scaleform::Render::MeshBuffer *)-1i64;
    if ( v7 == (Scaleform::Render::MeshCacheItem *)&v2->CacheList.Slots[5] )
    {
LABEL_14:
      v1->vfptr->__vecDelDtor(v1, 1u);
      v4 = v13;
      v1 = v6;
    }
    else
    {
      while ( 1 )
      {
        if ( (Scaleform::Render::MeshBuffer *)v7[1].pPrev == v1 || (Scaleform::Render::MeshBuffer *)v7[1].pNext == v1 )
        {
          v8 = v7->GPUFence.pObject;
          if ( v8 )
          {
            if ( v8->HasData && v8->Data && Scaleform::Render::FenceImpl::IsPending(v8->Data, 0i64) )
              break;
          }
        }
        v7 = v7->pNext;
        if ( v7 == (Scaleform::Render::MeshCacheItem *)&v2->CacheList.Slots[5] )
          goto LABEL_14;
      }
      v9 = (__int64)v13;
      v1->pPrev = (Scaleform::Render::MeshBuffer *)&v11;
      v4 = v1;
      v1->pNext = (Scaleform::Render::MeshBuffer *)v9;
      v13->pPrev = v1;
      v13 = v1;
      v1 = v6;
    }
  }
  if ( v4 != (Scaleform::Render::MeshBuffer *)&v11 )
  {
    v10 = (__int64)v12;
    v12[2] = (__int64)v3->Root.pNext;
    v4->pPrev = (Scaleform::Render::MeshBuffer *)&v3[-1].Root.8;
    v3->Root.pNext->pPrev = (Scaleform::Render::MeshBuffer *)v10;
    v3->Root.pNext = v4;
  }
}

// File Line: 225
// RVA: 0xA07520
void __fastcall Scaleform::Render::D3D1x::MeshCache::EndFrame(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshCache *v1; // rsi
  unsigned __int64 v2; // rdx
  signed __int64 v3; // rbp
  signed __int64 v4; // r14
  signed __int64 v5; // rax
  Scaleform::Render::D3D1x::MeshBuffer *v6; // rbx
  signed __int64 v7; // r15
  bool v8; // di
  __int64 v9; // rax

  v1 = this;
  Scaleform::Render::MeshCacheListSet::EndFrame(&this->CacheList);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&v1->CacheList, &v1->IndexBuffers.Allocator);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&v1->CacheList, &v1->VertexBuffers.Allocator);
  Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(v1);
  v2 = v1->Params.LRUTailSize;
  if ( v1->CacheList.Slots[4].Size < v2 )
    v2 = v1->CacheList.Slots[4].Size;
  v3 = v1->VertexBuffers.TotalSize
     + v1->IndexBuffers.TotalSize
     - ((v1->CacheList.Slots[3].Size + v2) >> 2)
     - (v1->CacheList.Slots[3].Size
      + v2);
  if ( v3 > (signed __int64)v1->Params.MemGranularity )
  {
    v4 = (signed __int64)&v1->ChunkBuffers;
    while ( 1 )
    {
      v5 = (signed __int64)&v1->LockedBuffers;
      if ( v1 == (Scaleform::Render::D3D1x::MeshCache *)-504i64 )
        v5 = 0i64;
      if ( v1->ChunkBuffers.Root.pNext == (Scaleform::Render::MeshBuffer *)v5
        || v3 <= (signed __int64)v1->Params.MemGranularity )
      {
        break;
      }
      v6 = *(Scaleform::Render::D3D1x::MeshBuffer **)v4;
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v4 + 8i64) + 16i64) = *(_QWORD *)(*(_QWORD *)v4 + 16i64);
      v6->pNext->pPrev = v6->pPrev;
      v6->pPrev = (Scaleform::Render::MeshBuffer *)-1i64;
      v6->pNext = (Scaleform::Render::MeshBuffer *)-1i64;
      v3 -= v6->Size;
      v7 = (signed __int64)&v1->VertexBuffers;
      if ( ((unsigned int (__fastcall *)(Scaleform::Render::D3D1x::MeshBuffer *))v6->vfptr[4].__vecDelDtor)(v6) )
        v7 = (signed __int64)&v1->IndexBuffers;
      v8 = Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer(v1, v1->CacheList.Slots, 6ui64, v6);
      Scaleform::AllocAddr::RemoveSegment((Scaleform::AllocAddr *)(v7 + 32), v6->Index << 24, (v6->Size + 15) >> 4);
      v9 = *(_QWORD *)(v7 + 8);
      *(_QWORD *)(v7 + 64) -= v6->Size;
      *(_QWORD *)(v9 + 8 * v6->Index) = 0i64;
      if ( v8 )
      {
        v6->vfptr->__vecDelDtor((Scaleform::Render::MeshBuffer *)&v6->vfptr, 1u);
      }
      else
      {
        v6->pPrev = v1->PendingDestructionBuffers.Root.pPrev;
        v6->pNext = (Scaleform::Render::MeshBuffer *)&v1->ChunkBuffers.Root.8;
        v1->PendingDestructionBuffers.Root.pPrev->pNext = (Scaleform::Render::MeshBuffer *)&v6->vfptr;
        v1->PendingDestructionBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)&v6->vfptr;
      }
    }
  }
}

// File Line: 295
// RVA: 0xA083D0
char __fastcall Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(Scaleform::Render::D3D1x::MeshCache *this, unsigned __int64 size, Scaleform::Render::MeshBuffer::AllocType type, unsigned int arena)
{
  unsigned __int64 v4; // rbp
  Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *v5; // rdi
  Scaleform::Render::D3D1x::MeshCache *v6; // r14
  unsigned int v7; // er15
  Scaleform::Render::MeshBuffer::AllocType v8; // er12
  ID3D11Device *v9; // ST28_8
  Scaleform::MemoryHeap *v10; // ST20_8
  unsigned __int64 v11; // rsi
  __int64 v12; // rbx

  v4 = size;
  v5 = &this->VertexBuffers;
  v6 = this;
  v7 = arena;
  v8 = type;
  v9 = this->pDevice.pObject;
  v10 = this->pHeap;
  v11 = 16 * ((unsigned __int64)(5 * (size >> 4) * (unsigned __int128)0xE38E38E38E38E38Fui64 >> 64) >> 3);
  v12 = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *, unsigned __int64))this->VertexBuffers.vfptr->CreateBuffer)(
          &this->VertexBuffers,
          16 * ((unsigned __int64)(5 * (size >> 4) * (unsigned __int128)0xE38E38E38E38E38Fui64 >> 64) >> 3));
  if ( !v12 )
    return 0;
  if ( !(__int64)v6->IndexBuffers.vfptr->CreateBuffer(
                   (Scaleform::Render::D3D1x::MeshBufferSet *)&v6->IndexBuffers.vfptr,
                   (v4 & 0xFFFFFFFFFFFFFFF0ui64) - (v11 & 0xFFFFFFFFFFFFFFF0ui64),
                   v8,
                   v7,
                   v6->pHeap,
                   v6->pDevice.pObject) )
  {
    Scaleform::AllocAddr::RemoveSegment(
      &v5->Allocator,
      *(_QWORD *)(v12 + 48) << 24,
      (unsigned __int64)(*(_QWORD *)(v12 + 32) + 15i64) >> 4);
    v5->TotalSize -= *(_QWORD *)(v12 + 32);
    v5->Buffers.Data.Data[*(_QWORD *)(v12 + 48)] = 0i64;
    (**(void (__fastcall ***)(__int64, signed __int64))v12)(v12, 1i64);
    return 0;
  }
  return 1;
}

// File Line: 324
// RVA: 0xA08500
bool __fastcall Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(Scaleform::Render::D3D1x::MeshCache *this, ID3D11Device *pdevice)
{
  ID3D11Device *v2; // r11
  Scaleform::Render::D3D1x::MeshCache *v3; // rdi
  char v4; // r9
  unsigned int v5; // er10
  char *v6; // r8
  unsigned __int8 v7; // dl
  int v8; // eax
  signed __int64 v9; // rcx
  ID3D10DeviceVtbl *v10; // rax
  int v12; // [rsp+20h] [rbp-6F8h]
  int v13; // [rsp+24h] [rbp-6F4h]
  __int64 v14; // [rsp+28h] [rbp-6F0h]
  __int64 v15; // [rsp+30h] [rbp-6E8h]
  char *v16; // [rsp+38h] [rbp-6E0h]
  __int64 v17; // [rsp+40h] [rbp-6D8h]
  char v18; // [rsp+50h] [rbp-6C8h]
  char v19; // [rsp+58h] [rbp-6C0h]
  char v20; // [rsp+59h] [rbp-6BFh]
  char v21; // [rsp+5Ah] [rbp-6BEh]
  char v22[5]; // [rsp+5Bh] [rbp-6BDh]
  char v23; // [rsp+60h] [rbp-6B8h]

  v2 = pdevice;
  v3 = this;
  v12 = 1728;
  v13 = 1;
  v14 = 1i64;
  v15 = 0i64;
  v4 = 0;
  v5 = 0;
  v6 = &v23;
  do
  {
    v7 = 0;
    do
    {
      v8 = v7++;
      v9 = 3i64 * (v5 + v8);
      *(&v19 + 4 * v9) = v4;
      *(&v20 + 4 * v9) = v4;
      *(&v21 + 4 * v9) = v4;
      v22[4 * v9] = v4;
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
  v16 = &v18;
  v10 = v2->vfptr;
  v17 = 0i64;
  return ((signed int (__fastcall *)(ID3D11Device *, int *, char **, Scaleform::Ptr<ID3D11Buffer> *, _QWORD, __int64, __int64, char *, _QWORD))v10->VSSetConstantBuffers)(
           v2,
           &v12,
           &v16,
           &v3->pMaskEraseBatchVertexBuffer,
           *(_QWORD *)&v12,
           v14,
           v15,
           &v18,
           0i64) >= 0;
}

// File Line: 350
// RVA: 0xA07A10
char __fastcall Scaleform::Render::D3D1x::MeshCache::LockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::RQCacheInterface *v1; // rax

  v1 = this->pRQCaches;
  this->Locked = 1;
  this->VBSizeEvictedInLock = 0i64;
  if ( v1 )
    v1->LockFlags |= 1u;
  return 1;
}

// File Line: 360
// RVA: 0xA08050
void __fastcall Scaleform::Render::D3D1x::MeshCache::UnlockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshBuffer *v1; // rbx
  ID3D11DeviceContext *v2; // rsi
  Scaleform::Render::D3D1x::MeshCache *i; // rdi
  Scaleform::Render::RQCacheInterface *v4; // rax

  v1 = this->LockedBuffers.pFirst;
  v2 = this->pDeviceContext.pObject;
  for ( i = this; v1; v1 = v1->pNextLock )
    v1->vfptr[3].__vecDelDtor((Scaleform::Render::MeshBuffer *)&v1->vfptr, (unsigned int)v2);
  i->LockedBuffers.pFirst = 0i64;
  v4 = i->pRQCaches;
  i->Locked = 0;
  if ( v4 )
    v4->LockFlags &= 0xFFFFFFFE;
}

// File Line: 371
// RVA: 0xA087D0
bool __fastcall Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::MeshCacheListSet::ListSlot *plist, unsigned __int64 count, Scaleform::Render::D3D1x::MeshBuffer *pbuffer)
{
  char v4; // r15
  Scaleform::Render::D3D1x::MeshBuffer *v5; // rdi
  unsigned __int64 v6; // r13
  Scaleform::Render::D3D1x::MeshCache *v7; // r14
  unsigned int v8; // er12
  __int64 v9; // rax
  __int64 v10; // rax
  Scaleform::Render::MeshCacheItem *v11; // rbx
  Scaleform::Render::MeshCacheListSet::ListSlot *v12; // rsi
  Scaleform::Render::D3D1x::MeshBuffer *v13; // rdx
  Scaleform::Render::D3D1x::MeshBuffer *v14; // rdx
  Scaleform::Render::MeshCacheListSet::ListSlot *v16; // [rsp+58h] [rbp+10h]

  v16 = plist;
  v4 = 0;
  v5 = pbuffer;
  v6 = count;
  v7 = this;
  v8 = 0;
  if ( count )
  {
    v9 = 0i64;
    do
    {
      v10 = v9;
      v11 = plist[v10].Root.pNext;
      v12 = &plist[v10];
      if ( v11 != (Scaleform::Render::MeshCacheItem *)v12 )
      {
        do
        {
          if ( (Scaleform::Render::D3D1x::MeshBuffer *)v11[1].pPrev == v5
            || (Scaleform::Render::D3D1x::MeshBuffer *)v11[1].pNext == v5 )
          {
            if ( !((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, _QWORD))v7->vfptr[4].__vecDelDtor)(
                    v7,
                    v11,
                    0i64,
                    0i64) )
            {
              v13 = (Scaleform::Render::D3D1x::MeshBuffer *)v11[1].pPrev;
              v4 = 1;
              if ( v13 == v5 )
              {
                Scaleform::AllocAddr::Free(
                  &v7->VertexBuffers.Allocator,
                  ((_QWORD)v11[1].pCacheList >> 4) | (v13->Index << 24),
                  (unsigned __int64)(*(_QWORD *)&v11[1].ListType + 15i64) >> 4);
                v11[1].pPrev = 0i64;
              }
              v14 = (Scaleform::Render::D3D1x::MeshBuffer *)v11[1].pNext;
              if ( v14 == v5 )
              {
                Scaleform::AllocAddr::Free(
                  &v7->IndexBuffers.Allocator,
                  ((_QWORD)v11[1].PrimitiveBatches.Root.pPrev >> 4) | (v14->Index << 24),
                  ((unsigned __int64)&v11[1].PrimitiveBatches.Root.pNext->pVoidNext + 7) >> 4);
                v11[1].pNext = 0i64;
              }
            }
            v11 = v12->Root.pNext;
          }
          else
          {
            v11 = v11->pNext;
          }
        }
        while ( v11 != (Scaleform::Render::MeshCacheItem *)v12 );
        plist = v16;
      }
      v9 = ++v8;
    }
    while ( v8 < v6 );
  }
  return v4 == 0;
}

// File Line: 414
// RVA: 0xA076E0
unsigned __int64 __fastcall Scaleform::Render::D3D1x::MeshCache::Evict(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::MeshCacheItem *pbatch, Scaleform::AllocAddr *pallocator, Scaleform::Render::MeshBase *pskipMesh)
{
  Scaleform::Render::Fence *v4; // rax
  Scaleform::Render::MeshBase *v5; // r15
  Scaleform::AllocAddr *v6; // r14
  Scaleform::Render::MeshCacheItem *v7; // rbx
  Scaleform::Render::D3D1x::MeshCache *v8; // rsi
  Scaleform::Render::MeshCacheItem *v9; // rax
  unsigned __int64 result; // rax
  Scaleform::Render::MeshCacheItem *v11; // rdx
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // rbp
  Scaleform::Render::MeshCacheItem *v14; // rdx

  v4 = pbatch->GPUFence.pObject;
  v5 = pskipMesh;
  v6 = pallocator;
  v7 = pbatch;
  v8 = this;
  if ( v4 && v4->HasData && v4->Data && Scaleform::Render::FenceImpl::IsPending(v4->Data, 0i64) )
  {
    Scaleform::Render::MeshCacheItem::Destroy(v7, v5, 0);
    v7->ListType = 5;
    v9 = v8->CacheList.Slots[5].Root.pNext;
    v7->pPrev = (Scaleform::Render::MeshCacheItem *)&v8->CacheList.Slots[5];
    v7->pNext = v9;
    v8->CacheList.Slots[5].Root.pNext->pPrev = v7;
    v8->CacheList.Slots[5].Root.pNext = v7;
    v8->CacheList.Slots[5].Size += v7->AllocSize;
    result = 0i64;
  }
  else
  {
    v11 = v7[1].pPrev;
    v12 = 0i64;
    if ( v11 )
      v13 = 16
          * Scaleform::AllocAddr::Free(
              &v8->VertexBuffers.Allocator,
              ((_QWORD)v7[1].pCacheList >> 4) | (*(_QWORD *)&v11->HashKey << 24),
              (unsigned __int64)(*(_QWORD *)&v7[1].ListType + 15i64) >> 4);
    else
      v13 = 0i64;
    v14 = v7[1].pNext;
    if ( v14 )
      v12 = 16
          * Scaleform::AllocAddr::Free(
              &v8->IndexBuffers.Allocator,
              ((_QWORD)v7[1].PrimitiveBatches.Root.pPrev >> 4) | (*(_QWORD *)&v14->HashKey << 24),
              ((unsigned __int64)&v7[1].PrimitiveBatches.Root.pNext->pVoidNext + 7) >> 4);
    if ( v6 )
    {
      if ( &v8->VertexBuffers.Allocator == v6 )
        v12 = v13;
    }
    else
    {
      v12 += v13;
    }
    v8->VBSizeEvictedInLock += (unsigned int)v7[1].ListType;
    Scaleform::Render::MeshCacheItem::Destroy(v7, v5, 1);
    result = v12;
  }
  return result;
}

// File Line: 444
// RVA: 0xA08120
char __fastcall Scaleform::Render::D3D1x::MeshCache::allocBuffer(Scaleform::Render::D3D1x::MeshCache *this, unsigned __int64 *poffset, Scaleform::Render::D3D1x::MeshBuffer **pbuffer, Scaleform::Render::D3D1x::MeshBufferSet *mbs, unsigned __int64 size, bool waitForCache)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v6; // r15
  unsigned __int64 *v7; // r13
  Scaleform::Render::D3D1x::MeshCache *v8; // rdi
  Scaleform::Render::D3D1x::MeshBuffer **v9; // r12
  unsigned __int64 v11; // rdx
  ID3D11Device *v12; // ST28_8
  unsigned __int64 limit; // ST20_8
  __int64 v14; // rax
  Scaleform::Render::MeshCacheItem *v15; // rbx
  Scaleform::Render::Fence *v16; // rax
  Scaleform::Render::MeshCacheItem *v17; // rbx
  Scaleform::Render::Fence *v18; // rax

  v6 = mbs;
  v7 = poffset;
  v8 = this;
  v9 = pbuffer;
  if ( Scaleform::Render::D3D1x::MeshBufferSet::Alloc(mbs, size, pbuffer, poffset) )
    return 1;
  if ( Scaleform::Render::MeshCacheListSet::EvictPendingFree(&v8->CacheList, &v6->Allocator) )
    return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v6, size, v9, v7) != 0;
  if ( v8->IndexBuffers.TotalSize + v8->VertexBuffers.TotalSize + 0x4000 > v8->Params.MemLimit )
  {
LABEL_14:
    if ( Scaleform::Render::MeshCacheListSet::EvictLRU(&v8->CacheList, &v8->CacheList.Slots[4], &v6->Allocator, size) )
      return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v6, size, v9, v7) != 0;
    if ( v8->VBSizeEvictedInLock <= v8->Params.VBLockEvictSizeLimit )
    {
      v15 = v8->CacheList.Slots[3].Root.pNext;
      while ( v15 != (Scaleform::Render::MeshCacheItem *)&v8->CacheList.Slots[3] )
      {
        v16 = v15->GPUFence.pObject;
        if ( v16 && v16->HasData && v16->Data && Scaleform::Render::FenceImpl::IsPending(v16->Data, 0i64) )
        {
          v15 = v15->pNext;
        }
        else
        {
          if ( ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))v8->vfptr[4].__vecDelDtor)(
                 v8,
                 v15,
                 &v6->Allocator,
                 0i64) >= size )
            return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v6, size, v9, v7) != 0;
          v15 = v8->CacheList.Slots[3].Root.pNext;
        }
      }
      v17 = v8->CacheList.Slots[2].Root.pNext;
      if ( waitForCache )
      {
        while ( v17 != (Scaleform::Render::MeshCacheItem *)&v8->CacheList.Slots[2] )
        {
          v18 = v17->GPUFence.pObject;
          if ( v18 && v18->HasData )
          {
            if ( v18->Data )
              Scaleform::Render::FenceImpl::WaitFence(v18->Data, 0i64);
          }
          if ( ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem *, Scaleform::AllocAddr *, _QWORD))v8->vfptr[4].__vecDelDtor)(
                 v8,
                 v17,
                 &v6->Allocator,
                 0i64) >= size )
            return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v6, size, v9, v7) != 0;
          v17 = v8->CacheList.Slots[2].Root.pNext;
        }
      }
    }
    return 0;
  }
  if ( Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(
         &v8->CacheList,
         &v8->CacheList.Slots[4],
         &v6->Allocator,
         size,
         v8->Params.LRUTailSize) )
  {
    return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v6, size, v9, v7) != 0;
  }
  v11 = v6->Granularity;
  if ( size <= v11 )
  {
    if ( v8->Params.MemLimit - v8->VertexBuffers.TotalSize - v8->IndexBuffers.TotalSize < v11 )
      v11 = v8->Params.MemLimit - v8->VertexBuffers.TotalSize - v8->IndexBuffers.TotalSize;
    if ( size <= v11 )
    {
      v12 = v8->pDevice.pObject;
      limit = (unsigned __int64)v8->pHeap;
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshBufferSet *, unsigned __int64, signed __int64))v6->vfptr->CreateBuffer)(
              v6,
              v11,
              2i64);
      if ( v14 )
      {
        *(_QWORD *)(v14 + 8) = v8->ChunkBuffers.Root.pPrev;
        *(_QWORD *)(v14 + 16) = (char *)v8 + 496;
        v8->ChunkBuffers.Root.pPrev->pNext = (Scaleform::Render::MeshBuffer *)v14;
        v8->ChunkBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)v14;
        return Scaleform::Render::D3D1x::MeshBufferSet::Alloc(v6, size, v9, v7) != 0;
      }
    }
    goto LABEL_14;
  }
  return 0;
}

// File Line: 546
// RVA: 0xA07A40
bool __fastcall Scaleform::Render::D3D1x::MeshCache::PreparePrimitive(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::PrimitiveBatch *pbatch, Scaleform::Render::MeshCacheItem::MeshContent *mc, bool waitForCache)
{
  bool v4; // r12
  Scaleform::Render::MeshCacheItem::MeshContent *v5; // rdi
  Scaleform::Render::PrimitiveBatch *v6; // rbx
  Scaleform::Render::D3D1x::MeshCache *v7; // r14
  Scaleform::Render::Primitive *v8; // r15
  Scaleform::Render::Mesh *v9; // r8
  Scaleform::Render::MeshCache::MeshResult::ResultType v10; // eax
  Scaleform::Render::MeshBase *v11; // rcx
  Scaleform::Render::MeshCacheItem **v12; // rdx
  bool v13; // al
  int v14; // esi
  unsigned int v15; // er13
  bool v16; // ST48_1
  unsigned int v17; // ST40_4
  unsigned int v18; // ST38_4
  Scaleform::Render::VertexFormat *ST20_8_9; // ST20_8
  int v20; // eax
  bool v21; // bl
  char *v22; // r14
  Scaleform::Render::VertexFormat *v23; // r15
  Scaleform::Render::VertexFormat *v24; // r12
  unsigned int v25; // eax
  char *v26; // r8
  __int64 v27; // rbx
  void *pdest; // [rsp+60h] [rbp-A0h]
  unsigned int ptotalVertices; // [rsp+68h] [rbp-98h]
  unsigned __int16 *v30; // [rsp+70h] [rbp-90h]
  Scaleform::Render::MeshCacheItem *p; // [rsp+78h] [rbp-88h]
  unsigned int ptotalIndices; // [rsp+80h] [rbp-80h]
  __int64 v33; // [rsp+88h] [rbp-78h]
  Scaleform::Render::MeshCache::StagingBufferPrep v34; // [rsp+90h] [rbp-70h]
  unsigned int v35; // [rsp+1F8h] [rbp+F8h]
  Scaleform::Render::MeshCache::MeshResult result; // [rsp+200h] [rbp+100h]

  v33 = -2i64;
  v4 = waitForCache;
  v5 = mc;
  v6 = pbatch;
  v7 = this;
  v8 = pbatch->pPrimitive;
  if ( LODWORD(mc->Meshes.Size) && (v9 = (Scaleform::Render::Mesh *)*mc->Meshes.pData, v9->LargeMesh) )
  {
    Scaleform::Render::MeshCache::GenerateMesh(
      (Scaleform::Render::MeshCache *)&this->vfptr,
      &result,
      v9,
      v8->pFill.pObject->Data.pFormat,
      pbatch->pFormat,
      0i64,
      waitForCache);
    v10 = result.Value;
    if ( (signed int)result.Value <= 1 )
    {
      v11 = *v5->Meshes.pData;
      if ( v11[1].vfptr <= (Scaleform::RefCountImplCoreVtbl *)2 )
        v12 = (Scaleform::Render::MeshCacheItem **)&v11[1].RefCount;
      else
        v12 = *(Scaleform::Render::MeshCacheItem ***)&v11[1].RefCount;
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&v6->MeshNode, *v12);
      v10 = result.Value;
    }
    v13 = v10 != 3;
  }
  else
  {
    Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
      &v34,
      (Scaleform::Render::MeshCache *)&this->vfptr,
      v5,
      v8->pFill.pObject->Data.pFormat,
      0);
    Scaleform::Render::PrimitiveBatch::CalcMeshSizes(v6, &ptotalVertices, &ptotalIndices);
    v14 = 0;
    p = 0i64;
    v15 = v6->pFormat->Size;
    v16 = v4;
    v17 = ptotalIndices;
    v18 = ptotalVertices;
    LODWORD(ST20_8_9) = 0;
    v20 = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem **, void **, unsigned __int16 **, Scaleform::Render::VertexFormat *, Scaleform::Render::MeshCacheItem::MeshContent *, _QWORD, unsigned int, unsigned int, bool, _QWORD))v7->vfptr[6].__vecDelDtor)(
            v7,
            &p,
            &pdest,
            &v30,
            ST20_8_9,
            v5,
            ptotalVertices * v6->pFormat->Size,
            v18,
            v17,
            v16,
            0i64);
    if ( v20 == 3 )
    {
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&v6->MeshNode, p);
      Scaleform::Render::MeshCache::StagingBufferPrep::GenerateMeshes(&v34, p);
      v22 = v7->StagingBuffer.pBuffer;
      v23 = v8->pFill.pObject->Data.pFormat;
      v24 = v6->pFormat;
      v25 = 0;
      v35 = 0;
      if ( LODWORD(v5->Meshes.Size) > 0 )
      {
        v26 = (char *)pdest;
        do
        {
          v27 = *(__int64 *)((char *)v5->Meshes.pData + v5->Meshes.StrideSize * v25);
          *(_QWORD *)&result.Value = &v35;
          Scaleform::Render::ConvertVertices_Buffered(
            v23,
            &v22[*(_QWORD *)(v27 + 48)],
            v24,
            v26,
            *(_DWORD *)(v27 + 68),
            (void **)&result);
          Scaleform::Render::ConvertIndices(
            v30,
            (unsigned __int16 *)&v22[*(_QWORD *)(v27 + 56)],
            *(_DWORD *)(v27 + 72),
            v14);
          v26 = (char *)pdest + *(_DWORD *)(v27 + 68) * v15;
          pdest = (char *)pdest + *(_DWORD *)(v27 + 68) * v15;
          v30 += *(unsigned int *)(v27 + 72);
          v14 += *(_DWORD *)(v27 + 68);
          v25 = v35 + 1;
          v35 = v25;
        }
        while ( v25 < LODWORD(v5->Meshes.Size) );
      }
      v21 = 1;
    }
    else
    {
      v21 = v20 != 0;
    }
    Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(&v34);
    v13 = v21;
  }
  return v13;
}

// File Line: 643
// RVA: 0xA06B40
signed __int64 __fastcall Scaleform::Render::D3D1x::MeshCache::AllocCacheItem(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::MeshCacheItem **pdata, char **pvertexDataStart, unsigned __int16 **pindexDataStart, Scaleform::Render::MeshCacheItem::MeshType meshType, Scaleform::Render::MeshCacheItem::MeshBaseContent *mc, unsigned __int64 vertexBufferSize, unsigned int vertexCount, unsigned int indexCount, bool waitForCache)
{
  Scaleform::Render::D3D1x::MeshCache *v10; // rbx
  unsigned __int64 v12; // rdi
  bool v13; // r15
  Scaleform::Render::D3D1x::IndexBuffer *v14; // rsi
  unsigned int v15; // ebp
  bool v16; // al
  unsigned __int64 v17; // r13
  Scaleform::Render::D3D1x::VertexBuffer *v18; // r14
  unsigned int v19; // er12
  char *v20; // r12
  char *v21; // r15
  Scaleform::Render::D3D1x::MeshCacheItem *v22; // rax
  Scaleform::Render::D3D1x::MeshBuffer *v23; // [rsp+60h] [rbp-68h]
  __int128 poffset; // [rsp+68h] [rbp-60h]
  unsigned __int64 v25; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::MeshCacheItem **v26; // [rsp+D8h] [rbp+10h]
  char **v27; // [rsp+E0h] [rbp+18h]
  unsigned __int16 **v28; // [rsp+E8h] [rbp+20h]

  v28 = pindexDataStart;
  v27 = pvertexDataStart;
  v26 = pdata;
  v10 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[3].__vecDelDtor)()
    && !((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::MeshCache *))v10->vfptr[2].UnlockBuffers)(v10) )
  {
    return 4i64;
  }
  v12 = 0i64;
  v13 = waitForCache;
  poffset = 0ui64;
  v25 = 0i64;
  v14 = 0i64;
  v23 = 0i64;
  v15 = 0;
  v16 = Scaleform::Render::D3D1x::MeshCache::allocBuffer(
          v10,
          (unsigned __int64 *)&poffset,
          (Scaleform::Render::D3D1x::MeshBuffer **)&poffset + 1,
          (Scaleform::Render::D3D1x::MeshBufferSet *)&v10->VertexBuffers.vfptr,
          vertexBufferSize,
          waitForCache);
  v18 = (Scaleform::Render::D3D1x::VertexBuffer *)*((_QWORD *)&poffset + 1);
  v17 = poffset;
  if ( v16 )
  {
    v19 = indexCount;
    *((_QWORD *)&poffset + 1) = 2i64 * indexCount;
    if ( !Scaleform::Render::D3D1x::MeshCache::allocBuffer(
            v10,
            &v25,
            &v23,
            (Scaleform::Render::D3D1x::MeshBufferSet *)&v10->IndexBuffers.vfptr,
            2i64 * indexCount,
            v13) )
    {
      v12 = v25;
      v14 = (Scaleform::Render::D3D1x::IndexBuffer *)v23;
      goto $handle_alloc_fail;
    }
    if ( !v18->pData )
    {
      if ( !(unsigned __int8)v18->vfptr[2].__vecDelDtor(
                               (Scaleform::Render::MeshBuffer *)&v18->vfptr,
                               (unsigned int)v10->pDeviceContext.pObject) )
      {
        v20 = 0i64;
        goto LABEL_11;
      }
      v18->pNextLock = v10->LockedBuffers.pFirst;
      v10->LockedBuffers.pFirst = (Scaleform::Render::D3D1x::MeshBuffer *)&v18->vfptr;
    }
    v20 = (char *)v18->pData;
LABEL_11:
    v14 = (Scaleform::Render::D3D1x::IndexBuffer *)v23;
    if ( !v23->pData )
    {
      if ( !(unsigned __int8)v23->vfptr[2].__vecDelDtor(
                               (Scaleform::Render::MeshBuffer *)v23,
                               (unsigned int)v10->pDeviceContext.pObject) )
      {
        v21 = 0i64;
LABEL_16:
        if ( v20 && v21 )
        {
          v12 = v25;
          v22 = Scaleform::Render::D3D1x::MeshCacheItem::Create(
                  meshType,
                  &v10->CacheList,
                  mc,
                  v18,
                  v14,
                  (unsigned int)v17,
                  vertexBufferSize,
                  vertexCount,
                  (unsigned int)v25,
                  *((unsigned __int64 *)&poffset + 1),
                  indexCount);
          *v26 = (Scaleform::Render::MeshCacheItem *)&v22->0;
          if ( v22 )
          {
            *v27 = &v20[v17];
            *v28 = (unsigned __int16 *)&v21[v12];
            return 3i64;
          }
          v15 = 4;
        }
        else
        {
          v12 = v25;
        }
        goto LABEL_20;
      }
      v14->pNextLock = v10->LockedBuffers.pFirst;
      v10->LockedBuffers.pFirst = (Scaleform::Render::D3D1x::MeshBuffer *)&v14->vfptr;
    }
    v21 = (char *)v14->pData;
    goto LABEL_16;
  }
LABEL_20:
  v19 = indexCount;
$handle_alloc_fail:
  if ( v18 )
    Scaleform::AllocAddr::Free(
      &v10->VertexBuffers.Allocator,
      (v17 >> 4) | (v18->Index << 24),
      (vertexBufferSize + 15) >> 4);
  if ( v14 )
    Scaleform::AllocAddr::Free(
      &v10->IndexBuffers.Allocator,
      (v12 >> 4) | (v14->Index << 24),
      (2 * (unsigned __int64)v19 + 15) >> 4);
  return v15;
}

// File Line: 692
// RVA: 0xA07840
void __fastcall Scaleform::Render::D3D1x::MeshCache::GetStats(Scaleform::Render::D3D1x::MeshCache *this, Scaleform::Render::MeshCache::Stats *stats)
{
  Scaleform::Render::D3D1x::MeshCache *v2; // rbx
  Scaleform::Render::MeshCache::Stats *v3; // rdi

  v2 = this;
  v3 = stats;
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
  v3->TotalSize[6] = v2->IndexBuffers.TotalSize;
  v3->UsedSize[6] = 16 * Scaleform::AllocAddr::GetFreeSize(&v2->IndexBuffers.Allocator);
}

