// File Line: 26
// RVA: 0x99F7C0
Scaleform::Render::RenderQueueItem::QIPrepareResult __fastcall Scaleform::Render::Primitive::Prepare(Scaleform::Render::Primitive *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp, bool waitForCache)
{
  bool v4; // di
  Scaleform::Render::PrimitivePrepareBuffer *v6; // rbx

  v4 = waitForCache;
  if ( qp->QueuePrepareFilter )
    return 0;
  v6 = (Scaleform::Render::PrimitivePrepareBuffer *)&qp->72;
  if ( item != qp->PrepareItemBuffer.pItem )
    Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
      v6,
      item,
      (Scaleform::Render::Primitive *)((char *)this - 16),
      (Scaleform::Render::PrimitiveEmitBuffer *)&qp->264,
      qp->pHAL,
      (Scaleform::Render::MeshCache *)qp->Caches.pCaches[0]);
  return Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(v6, v4);
}

// File Line: 35
// RVA: 0x96FEE0
void __fastcall Scaleform::Render::Primitive::EmitToHAL(Scaleform::Render::Primitive *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( qp->QueueEmitFilter == QPF_All )
    Scaleform::Render::Primitive::emitToHAL(
      (Scaleform::Render::Primitive *)((char *)this - 16),
      item,
      (Scaleform::Render::PrimitivePrepareBuffer *)&qp->72,
      (Scaleform::Render::PrimitiveEmitBuffer *)&qp->264,
      qp->pHAL);
}

// File Line: 61
// RVA: 0x9E08C0
void __fastcall Scaleform::Render::Primitive::emitToHAL(Scaleform::Render::Primitive *this, void *item, Scaleform::Render::PrimitivePrepareBuffer *prepareBuffer, Scaleform::Render::PrimitiveEmitBuffer *emitBuffer, Scaleform::Render::HAL *hal)
{
  void *v5; // rax
  Scaleform::Render::Primitive *v6; // rdx
  Scaleform::Render::PrimitiveBatch *v7; // r11
  Scaleform::Render::PrimitiveBatch *v8; // r8
  unsigned int v9; // ecx
  Scaleform::Render::PrimitiveBatch *i; // rax

  v5 = item;
  v6 = this;
  if ( v5 == emitBuffer->pItem )
  {
    v7 = emitBuffer->pDraw;
  }
  else
  {
    v7 = this->Batches.Root.pNext;
    emitBuffer->pItem = v5;
    emitBuffer->pDraw = v7;
  }
  if ( v5 == prepareBuffer->pItem )
  {
    v8 = prepareBuffer->pPrepare;
    emitBuffer->pDraw = v8;
  }
  else
  {
    v8 = this->Batches.Root.pPrev->pNext;
  }
  v9 = this->Meshes.Data.Size;
  if ( v6->ModifyIndex < v9 )
  {
    for ( i = v6->Batches.Root.pPrev; i != (Scaleform::Render::PrimitiveBatch *)&v6->Batches; i = i->pPrev )
    {
      v9 -= i->MeshCount;
      i->MeshIndex = v9;
      if ( v9 < v6->ModifyIndex )
        break;
    }
    v6->ModifyIndex = v6->Meshes.Data.Size;
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Primitive *, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::PrimitiveBatch *))hal->vfptr[34].__vecDelDtor)(
    hal,
    v6,
    v7,
    v8);
}

// File Line: 98
// RVA: 0x9B7A50
void __fastcall Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(Scaleform::Render::PrimitivePrepareBuffer *this, void *item, Scaleform::Render::Primitive *p, Scaleform::Render::PrimitiveEmitBuffer *emitBuffer, Scaleform::Render::HAL *hal, Scaleform::Render::MeshCache *cache)
{
  Scaleform::Render::PrimitivePrepareBuffer *v6; // rbx
  Scaleform::Render::Primitive *v7; // rdi
  Scaleform::Render::VertexFormat *v8; // r8
  Scaleform::Render::PrimitiveBatch *v9; // rax

  v6 = this;
  this->pItem = item;
  this->pEmitBuffer = emitBuffer;
  this->pCache = cache;
  this->pPrimitive = p;
  this->MaximumBatchCount = 0;
  this->pHal = hal;
  v7 = p;
  v8 = p->pFill.pObject->Data.pFormat;
  this->pSourceVFormat = v8;
  if ( v8 )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, _DWORD))hal->vfptr[66].__vecDelDtor)(
      hal,
      (unsigned int)v7->pFill.pObject->Data.Type,
      v8,
      &this->pSingleVFormat,
      &this->pBatchVFormat,
      &this->pInstancedVFormat,
      0);
    v6->MaximumBatchCount = (__int64)v6->pHal->vfptr[67].__vecDelDtor(
                                       (Scaleform::RefCountImplCore *)&v6->pHal->vfptr,
                                       (unsigned int)v7);
  }
  else
  {
    this->pInstancedVFormat = 0i64;
    this->pBatchVFormat = 0i64;
    this->pSingleVFormat = 0i64;
  }
  v6->State = 0;
  v9 = v7->Batches.Root.pNext;
  v6->Converting = 0;
  v6->pConvert = v9;
  v6->pPrepareTail = v9;
  v6->pPrepare = v9;
}

// File Line: 151
// RVA: 0x99FDC0
signed __int64 __fastcall Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(Scaleform::Render::PrimitivePrepareBuffer *this, bool waitForCache)
{
  bool v2; // bp
  Scaleform::Render::PrimitivePrepareBuffer *v3; // rbx
  Scaleform::Render::PrimitiveBatch *v4; // r14
  Scaleform::Render::PrimitiveBatch *v5; // r8
  Scaleform::Render::Primitive *v6; // rdx
  unsigned int v7; // ecx
  Scaleform::Render::PrimitiveBatch *j; // rax
  unsigned int v9; // er9
  __int64 v10; // rdx
  __int64 v11; // rcx
  Scaleform::Render::Primitive::MeshEntry *v12; // r8
  Scaleform::Render::MeshBase **v13; // r8
  __int64 v14; // rdx
  Scaleform::Render::MeshBase *v15; // rax
  Scaleform::Render::PrimitiveBatch *v16; // rdi
  Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *v17; // rcx
  Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > v18; // rsi
  signed __int64 v19; // rax
  Scaleform::Render::MeshCacheItemUseNode *v20; // rdx
  Scaleform::Render::MeshCacheItem *v21; // r8
  Scaleform::Render::MeshCacheItem *v22; // r8
  Scaleform::Render::MeshCacheListSet *v23; // rdx
  __int64 v24; // rax
  Scaleform::Render::MeshCacheListSet *v25; // rdx
  Scaleform::Render::PrimitiveBatch *v26; // rcx
  Scaleform::Render::PrimitiveBatch *v27; // rax
  Scaleform::Render::PrimitiveBatch *v28; // rcx
  Scaleform::Render::PrimitiveBatch *v29; // rdx
  Scaleform::Render::Primitive *v30; // rdx
  unsigned int v31; // ecx
  Scaleform::Render::PrimitiveBatch *i; // rax
  Scaleform::Render::MeshCacheItem::MeshContent key; // [rsp+20h] [rbp-38h]

  v2 = waitForCache;
  v3 = this;
  v4 = (Scaleform::Render::PrimitiveBatch *)&this->pPrimitive->Batches;
  if ( this->pPrepare == v4 )
    return 0i64;
  while ( v3->pPrepare == v3->pPrepareTail )
  {
LABEL_26:
    if ( v3->Converting )
      goto LABEL_39;
    if ( v3->pConvert != v4 )
    {
      do
      {
        v27 = v3->pConvert;
        if ( v27->Type == 3 )
          break;
        v3->pPrepareTail = v27;
        v28 = v27->pNext;
        v3->pConvert = v28;
      }
      while ( v28 != v4 );
    }
    v29 = v3->pConvert;
    if ( v29 != v4 )
    {
      v30 = v29->pPrimitive;
      v31 = v30->Meshes.Data.Size;
      if ( v30->ModifyIndex < v31 )
      {
        for ( i = v30->Batches.Root.pPrev; i != (Scaleform::Render::PrimitiveBatch *)&v30->Batches; i = i->pPrev )
        {
          v31 -= i->MeshCount;
          i->MeshIndex = v31;
          if ( v31 < v30->ModifyIndex )
            break;
        }
        v30->ModifyIndex = v30->Meshes.Data.Size;
      }
      if ( !v3->pConvert->MeshCount )
        goto LABEL_40;
      v3->Converting = 1;
LABEL_39:
      Scaleform::Render::PrimitivePrepareBuffer::batchConvertStep(v3);
      goto LABEL_40;
    }
    v3->pPrepareTail = v29;
LABEL_40:
    if ( v3->pPrepare == v4 )
      return 0i64;
  }
  while ( 1 )
  {
    v5 = v3->pPrepare;
    if ( v5->MeshNode.pMeshItem )
      goto LABEL_23;
    v6 = v5->pPrimitive;
    v7 = v6->Meshes.Data.Size;
    if ( v6->ModifyIndex < v7 )
    {
      for ( j = v6->Batches.Root.pPrev; j != (Scaleform::Render::PrimitiveBatch *)&v6->Batches; j = j->pPrev )
      {
        v7 -= j->MeshCount;
        j->MeshIndex = v7;
        if ( v7 < v6->ModifyIndex )
          break;
      }
      v6->ModifyIndex = v6->Meshes.Data.Size;
    }
    v9 = 1;
    if ( v5->Type != 2 )
      v9 = v5->MeshCount;
    v10 = v5->MeshIndex;
    v11 = v9;
    v12 = v5->pPrimitive->Meshes.Data.Data;
    key.Meshes.Size = v9;
    key.Meshes.StrideSize = 16i64;
    v13 = (Scaleform::Render::MeshBase **)&v12[v10].pMesh;
    v14 = 0i64;
    key.Meshes.pData = v13;
    if ( v9 )
    {
      do
      {
        v15 = *v13;
        v13 += 2;
        v14 ^= (unsigned __int64)v15 >> 5;
        --v11;
      }
      while ( v11 );
    }
    v16 = v3->pPrepare;
    key.HashKey = v14;
    if ( v16->Type == 4 )
      goto LABEL_22;
    if ( v3->State )
      break;
    v17 = (Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *)&v3->pCache->BatchCacheItemHash.pTable;
    v18.pTable = v17->pTable;
    if ( !v17->pTable )
      break;
    v19 = Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::findIndexCore<Scaleform::Render::MeshCacheItem::MeshContent>(
            v17,
            &key,
            (unsigned int)v14 & v18.pTable->SizeMask);
    if ( v19 < 0 )
      break;
    v20 = &v16->MeshNode;
    v21 = (Scaleform::Render::MeshCacheItem *)*(&v18.pTable[2].EntryCount + 3 * v19);
    if ( v16->MeshNode.pMeshItem )
    {
      v16->MeshNode.pPrev->pNext = v16->MeshNode.pNext;
      v16->MeshNode.pNext->pPrev = v20->pPrev;
      v20->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v16->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    }
    v16->MeshNode.pMeshItem = v21;
    if ( v21 )
    {
      v16->MeshNode.pNext = v21->PrimitiveBatches.Root.pNext;
      v20->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)&v21->PrimitiveBatches;
      v21->PrimitiveBatches.Root.pNext->pPrev = v20;
      v21->PrimitiveBatches.Root.pNext = v20;
    }
LABEL_22:
    v3->State = 0;
    v2 = 0;
LABEL_23:
    v22 = v3->pPrepare->MeshNode.pMeshItem;
    if ( v22 )
    {
      v23 = v22->pCacheList;
      v22->pPrev->pNext = v22->pNext;
      v22->pNext->pPrev = v22->pPrev;
      v24 = v22->ListType;
      v22->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
      v22->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
      *((_QWORD *)&v23->pCache + 3 * (v24 + 1)) -= v22->AllocSize;
      v25 = v22->pCacheList;
      v22->ListType = 1;
      v22->pNext = v25->Slots[1].Root.pNext;
      v22->pPrev = (Scaleform::Render::MeshCacheItem *)&v25->Slots[1];
      v25->Slots[1].Root.pNext->pPrev = v22;
      v25->Slots[1].Root.pNext = v22;
      v25->Slots[1].Size += v22->AllocSize;
    }
    v26 = v3->pPrepare->pNext;
    v3->pPrepare = v26;
    if ( v26 == v3->pPrepareTail )
      goto LABEL_26;
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::MeshCacheItem::MeshContent *, bool, Scaleform::Render::MeshBase **, unsigned __int64, unsigned __int64, _QWORD))v3->pCache->vfptr[4].UnlockBuffers)(
         v3->pCache,
         v16,
         &key,
         v2,
         key.Meshes.pData,
         key.Meshes.Size,
         key.Meshes.StrideSize,
         *(_QWORD *)&key.HashKey) )
  {
    goto LABEL_22;
  }
  v3->State = 1;
  return 1i64;
}

// File Line: 263
// RVA: 0x9CED30
void __fastcall Scaleform::Render::PrimitivePrepareBuffer::batchConvertStep(Scaleform::Render::PrimitivePrepareBuffer *this)
{
  Scaleform::Render::PrimitivePrepareBuffer *v1; // rbx
  Scaleform::Render::MeshCache *v2; // rcx
  Scaleform::Render::MeshCacheConfigVtbl *v3; // rax
  unsigned int v4; // esi
  char v5; // r13
  unsigned int v6; // er14
  unsigned int v7; // ebp
  signed int v8; // er12
  __int64 v9; // rax
  Scaleform::Render::VertexFormat *batchFormat; // rdx
  unsigned int v11; // er11
  __int64 v12; // r8
  Scaleform::Render::PrimitiveBatch *v13; // rcx
  unsigned int v14; // er15
  bool v15; // r9
  signed __int64 v16; // r10
  unsigned int v17; // eax
  Scaleform::Render::Mesh **v18; // r13
  __int64 v19; // rcx
  Scaleform::Render::Mesh *v20; // rdi
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // er14
  Scaleform::Render::PrimitiveBatch *v25; // rdi
  Scaleform::Render::PrimitiveBatch *v26; // r8
  Scaleform::Render::PrimitiveBatch *v27; // rdx
  Scaleform::Render::PrimitiveBatch *v28; // r8
  __int64 v29; // r9
  unsigned int v30; // esi
  Scaleform::Render::Primitive *v31; // rdi
  __int64 v32; // rax
  _QWORD **v33; // r8
  Scaleform::Render::PrimitiveEmitBuffer *v34; // rcx
  Scaleform::Render::PrimitiveBatch *v35; // rax
  Scaleform::Render::Primitive *v36; // rdi
  unsigned int v37; // esi
  __int64 v38; // rax
  Scaleform::Render::PrimitiveBatch *v39; // r14
  _QWORD **v40; // rdx
  Scaleform::Render::PrimitiveEmitBuffer *v41; // rcx
  Scaleform::Render::PrimitiveBatch *v42; // rdx
  unsigned int knownIndexCount; // [rsp+40h] [rbp-78h]
  unsigned int knownVerticesSize; // [rsp+44h] [rbp-74h]
  unsigned int v45; // [rsp+48h] [rbp-70h]
  unsigned int v46; // [rsp+4Ch] [rbp-6Ch]
  Scaleform::Render::MeshCache::MeshResult result; // [rsp+50h] [rbp-68h]
  Scaleform::Render::Primitive::MeshEntry *v48; // [rsp+58h] [rbp-60h]
  Scaleform::Render::Mesh *v49; // [rsp+60h] [rbp-58h]
  __int64 v50; // [rsp+68h] [rbp-50h]
  char v51; // [rsp+C0h] [rbp+8h]
  bool v52; // [rsp+C8h] [rbp+10h]
  char v53; // [rsp+D0h] [rbp+18h]
  unsigned int v54; // [rsp+D8h] [rbp+20h]

  v1 = this;
  v2 = this->pCache;
  v3 = v2->vfptr;
  v4 = 0;
  v5 = 0;
  knownVerticesSize = 0;
  v6 = 0;
  knownIndexCount = 0;
  v49 = 0i64;
  v7 = 0;
  v53 = 0;
  v51 = 0;
  v8 = 1;
  v9 = (__int64)v3->GetParams((Scaleform::Render::MeshCacheConfig *)&v2->vfptr);
  batchFormat = v1->pBatchVFormat;
  v11 = *(_DWORD *)(v9 + 52);
  v12 = v9;
  v50 = v9;
  v54 = v11;
  if ( batchFormat )
    v45 = batchFormat->Size;
  else
    v45 = 0;
  v13 = v1->pConvert;
  v14 = 0;
  v15 = v1->pInstancedVFormat != 0i64;
  v52 = v1->pInstancedVFormat != 0i64;
  v16 = (signed __int64)&v13->pPrimitive->Meshes.Data.Data[v13->MeshIndex];
  v17 = v13->MeshCount;
  v48 = &v13->pPrimitive->Meshes.Data.Data[v13->MeshIndex];
  v46 = v17;
  if ( !v17 )
    goto LABEL_36;
  v18 = (Scaleform::Render::Mesh **)(v16 + 8);
  v19 = 0i64;
  while ( 1 )
  {
    v20 = *v18;
    if ( *v18 == (Scaleform::Render::Mesh *)v19 )
    {
      if ( v15 )
      {
        v21 = v1->MaximumBatchCount;
        if ( v7 == v21 )
          goto LABEL_35;
        if ( ++v7 >= v21 )
          goto LABEL_34;
      }
      else
      {
        ++v7;
      }
    }
    else
    {
      if ( v15 && v7 >= v11 )
        goto LABEL_35;
      v7 = 1;
    }
    if ( v20->IndexCount )
      goto LABEL_23;
    Scaleform::Render::MeshCache::GenerateMesh(
      v1->pCache,
      &result,
      v20,
      v1->pSourceVFormat,
      v1->pSingleVFormat,
      batchFormat,
      0);
    if ( (signed int)result.Value > 1 && result.Value != 3 )
    {
      if ( result.Value == 5 )
      {
        v51 = 1;
LABEL_21:
        v8 = 4;
        goto LABEL_22;
      }
      if ( result.Value != 7 )
        goto LABEL_21;
    }
LABEL_22:
    v11 = v54;
    v12 = v50;
    v15 = v52;
    v19 = (__int64)v49;
LABEL_23:
    if ( v20->LargeMesh || v8 == 4 || (batchFormat = v1->pBatchVFormat) == 0i64 )
    {
      v11 = 1;
      v53 = 1;
LABEL_34:
      ++v14;
LABEL_35:
      v16 = (signed __int64)v48;
      v5 = v51;
      goto LABEL_36;
    }
    v6 += v20->IndexCount;
    if ( v6 > *(_DWORD *)(v12 + 64) )
      break;
    v4 += v45 * v20->VertexCount;
    if ( v4 > *(_DWORD *)(v12 + 60) || v14 >= v1->MaximumBatchCount )
      break;
    ++v14;
    v19 = (__int64)v20;
    v18 += 2;
    knownIndexCount = v6;
    knownVerticesSize = v4;
    v49 = v20;
    if ( v14 >= v46 )
      goto LABEL_35;
  }
  v16 = (signed __int64)v48;
  v5 = v51;
  if ( v20 == (Scaleform::Render::Mesh *)v19 )
    --v7;
LABEL_36:
  v22 = v14;
  if ( v15 )
  {
    v23 = v1->pConvert->MeshCount;
    if ( v14 < v23 )
    {
      do
      {
        if ( *(_QWORD *)(v16 + 16i64 * v22 + 8) != *(_QWORD *)(v16 + 16i64 * (v14 - 1) + 8) )
          break;
        if ( v7 >= v1->MaximumBatchCount )
          break;
        ++v22;
        ++v7;
      }
      while ( v22 < v23 );
    }
  }
  else if ( v7 > 1 )
  {
    v7 = 0;
  }
  if ( v7 >= v11 || v22 == v7 && v7 != 1 )
    v14 = v22;
  else
    v7 = 0;
  v24 = v14 - v7;
  if ( v14 != v7 )
  {
    v25 = v1->pConvert;
    if ( v14 != v25->MeshCount || v7 )
    {
      v30 = v25->MeshIndex;
      v31 = v25->pPrimitive;
      v32 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Primitive *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
              Scaleform::Memory::pGlobalHeap,
              v31,
              80i64);
      *(_QWORD *)(v32 + 32) = 0i64;
      *(_DWORD *)(v32 + 40) = 1;
      *(_QWORD *)(v32 + 48) = 0i64;
      *(_BYTE *)(v32 + 56) = 0;
      *(_QWORD *)(v32 + 64) = v31;
      *(_DWORD *)(v32 + 72) = v24;
      *(_DWORD *)(v32 + 76) = v30;
      v33 = (_QWORD **)v1->pConvert;
      v29 = v32;
      *(_QWORD *)(v32 + 8) = *v33[1];
      *(_QWORD *)v32 = *v33;
      (*v33)[1] = v32;
      *v33 = (_QWORD *)v32;
      v1->pConvert->MeshIndex += v24;
      v1->pConvert->MeshCount -= v24;
      v34 = v1->pEmitBuffer;
      if ( v1->pItem == v34->pItem && v34->pDraw == v1->pConvert )
        v34->pDraw = (Scaleform::Render::PrimitiveBatch *)v32;
      if ( v1->pPrepare == v1->pConvert )
        v1->pPrepare = (Scaleform::Render::PrimitiveBatch *)v32;
    }
    else
    {
      v25->Type = 1;
      v26 = v1->pConvert;
      if ( v1->pPrepareTail != v26 )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          v1,
          v26->pPrev,
          v26,
          v26->pPrev,
          v26,
          &knownVerticesSize,
          &knownIndexCount);
      v27 = v1->pConvert;
      v28 = v27->pNext;
      if ( v28 != (Scaleform::Render::PrimitiveBatch *)&v1->pPrimitive->Batches )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          v1,
          v27,
          v28,
          v27->pNext,
          v27,
          &knownVerticesSize,
          &knownIndexCount);
      v29 = (__int64)v1->pConvert;
    }
    if ( *(_DWORD *)(v29 + 72) == 1 )
    {
      *(_DWORD *)(v29 + 40) = 0;
      *(_QWORD *)(v29 + 48) = v1->pSingleVFormat;
    }
    else
    {
      *(_QWORD *)(v29 + 48) = v1->pBatchVFormat;
    }
    v1->pPrepareTail = v1->pConvert;
  }
  if ( v7 )
  {
    if ( v7 <= 1 || v8 == 4 )
    {
      if ( !v5 )
        v8 = 0;
    }
    else
    {
      v8 = 2;
    }
    v35 = v1->pConvert;
    v36 = v35->pPrimitive;
    v37 = v35->MeshIndex;
    v38 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Primitive *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v35->pPrimitive,
            80i64);
    v39 = (Scaleform::Render::PrimitiveBatch *)v38;
    *(_QWORD *)(v38 + 32) = 0i64;
    *(_DWORD *)(v38 + 40) = v8;
    *(_QWORD *)(v38 + 48) = 0i64;
    *(_QWORD *)(v38 + 64) = v36;
    *(_DWORD *)(v38 + 72) = v7;
    *(_DWORD *)(v38 + 76) = v37;
    *(_BYTE *)(v38 + 56) = v53;
    if ( v8 == 2 )
    {
      *(_QWORD *)(v38 + 48) = v1->pInstancedVFormat;
    }
    else if ( !(v8 & 0xFFFFFFFB) )
    {
      *(_QWORD *)(v38 + 48) = v1->pSingleVFormat;
    }
    v40 = (_QWORD **)v1->pConvert;
    *(_QWORD *)(v38 + 8) = *v40[1];
    *(_QWORD *)v38 = *v40;
    (*v40)[1] = v38;
    *v40 = (_QWORD *)v38;
    v1->pConvert->MeshIndex += v7;
    v1->pConvert->MeshCount -= v7;
    v41 = v1->pEmitBuffer;
    if ( v1->pItem == v41->pItem && v41->pDraw == v1->pConvert )
      v41->pDraw = (Scaleform::Render::PrimitiveBatch *)v38;
    v42 = v1->pConvert;
    if ( v1->pPrepare == v42 )
      v1->pPrepare = (Scaleform::Render::PrimitiveBatch *)v38;
    if ( !v42->MeshCount )
    {
      v42->pPrev->pNext = v42->pNext;
      v42->pNext->pPrev = v42->pPrev;
      v42->pPrev = (Scaleform::Render::PrimitiveBatch *)-1i64;
      v42->pNext = (Scaleform::Render::PrimitiveBatch *)-1i64;
      if ( v42->MeshNode.pMeshItem )
      {
        v42->MeshNode.pPrev->pNext = v42->MeshNode.pNext;
        v42->MeshNode.pNext->pPrev = v42->MeshNode.pPrev;
        v42->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        v42->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        v42->MeshNode.pMeshItem = 0i64;
      }
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->pConvert = v39;
    }
    v1->pPrepareTail = v39;
  }
  if ( v14 >= v46 )
    v1->Converting = 0;
}

// File Line: 552
// RVA: 0x9CEBE0
bool __fastcall Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(Scaleform::Render::PrimitivePrepareBuffer *this, Scaleform::Render::PrimitiveBatch *pfirst, Scaleform::Render::PrimitiveBatch *psecond, Scaleform::Render::PrimitiveBatch *pother, Scaleform::Render::PrimitiveBatch *pknown, unsigned int *knownVerticesSize, unsigned int *knownIndexCount)
{
  Scaleform::Render::PrimitiveBatch *v7; // rsi
  Scaleform::Render::PrimitiveBatch *v8; // r14
  Scaleform::Render::PrimitiveBatch *v9; // rbp
  Scaleform::Render::PrimitivePrepareBuffer *v10; // rbx
  Scaleform::Render::MeshCacheParams *v11; // rax
  unsigned int v12; // er15
  Scaleform::Render::MeshCacheParams *v13; // rdi
  unsigned int *v15; // r12
  unsigned int *v16; // r14
  unsigned int v17; // er13
  Scaleform::Render::PrimitiveBatch *v18; // rdi
  Scaleform::Render::PrimitiveBatch *v19; // rcx
  unsigned int v20; // eax
  Scaleform::Render::PrimitiveEmitBuffer *v21; // rcx
  Scaleform::Render::VertexFormat *v22; // rax
  unsigned int ptotalIndices; // [rsp+20h] [rbp-38h]
  unsigned int ptotalVertices; // [rsp+78h] [rbp+20h]

  v7 = pother;
  v8 = psecond;
  v9 = pfirst;
  v10 = this;
  if ( pother->LargeMesh || !this->pBatchVFormat || pother->Type > 1u )
    return 0;
  v11 = this->pCache->vfptr->GetParams((Scaleform::Render::MeshCacheConfig *)&this->pCache->vfptr);
  v12 = v8->MeshCount + v9->MeshCount;
  v13 = v11;
  if ( v12 > v10->MaximumBatchCount )
    return 0;
  Scaleform::Render::PrimitiveBatch::CalcMeshSizes(v7, &ptotalVertices, &ptotalIndices);
  v15 = knownVerticesSize;
  if ( *knownVerticesSize + ptotalVertices * v10->pBatchVFormat->Size <= v13->MaxVerticesSizeInBatch )
  {
    v16 = knownIndexCount;
    v17 = ptotalIndices;
    if ( ptotalIndices + *knownIndexCount <= v13->MaxIndicesInBatch )
    {
      v18 = pknown;
      v19 = pknown;
      pknown->MeshCount = v12;
      v20 = v9->MeshIndex;
      v19->Type = 1;
      v19->MeshIndex = v20;
      Scaleform::Render::PrimitiveBatch::ClearCacheItem(v19);
      Scaleform::Render::PrimitiveBatch::RemoveAndFree(v7);
      v21 = v10->pEmitBuffer;
      if ( v10->pItem == v21->pItem && v21->pDraw == v9 )
        v21->pDraw = v18;
      if ( v10->pPrepare == v9 )
        v10->pPrepare = v18;
      v22 = v10->pBatchVFormat;
      v10->pConvert = v18;
      *v15 += ptotalVertices * v22->Size;
      *v16 += v17;
      v10->Converting = 0;
    }
  }
  return 0;
}

