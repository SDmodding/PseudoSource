// File Line: 26
// RVA: 0x99F7C0
Scaleform::Render::RenderQueueItem::QIPrepareResult __fastcall Scaleform::Render::Primitive::Prepare(
        Scaleform::Render::Primitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp,
        bool waitForCache)
{
  $45076D539F6ADDA0F9E9E30F948E0703 *v6; // rbx

  if ( qp->QueuePrepareFilter )
    return 0;
  v6 = &qp->72;
  if ( item != qp->PrepareItemBuffer.pItem )
    Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
      (Scaleform::Render::PrimitivePrepareBuffer *)v6,
      item,
      (Scaleform::Render::Primitive *)((char *)this - 16),
      (Scaleform::Render::PrimitiveEmitBuffer *)&qp->264,
      qp->pHAL,
      (Scaleform::Render::MeshCache *)qp->Caches.pCaches[0]);
  return Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(
           (Scaleform::Render::PrimitivePrepareBuffer *)v6,
           waitForCache);
}

// File Line: 35
// RVA: 0x96FEE0
void __fastcall Scaleform::Render::Primitive::EmitToHAL(
        Scaleform::Render::Primitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
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
void __fastcall Scaleform::Render::Primitive::emitToHAL(
        Scaleform::Render::Primitive *this,
        void *item,
        Scaleform::Render::PrimitivePrepareBuffer *prepareBuffer,
        Scaleform::Render::PrimitiveEmitBuffer *emitBuffer,
        Scaleform::Render::HAL *hal)
{
  Scaleform::Render::PrimitiveBatch *pDraw; // r11
  Scaleform::Render::PrimitiveBatch *pPrepare; // r8
  unsigned int Size; // ecx
  Scaleform::Render::PrimitiveBatch *i; // rax

  if ( item == emitBuffer->pItem )
  {
    pDraw = emitBuffer->pDraw;
  }
  else
  {
    pDraw = this->Batches.Root.pNext;
    emitBuffer->pItem = item;
    emitBuffer->pDraw = pDraw;
  }
  if ( item == prepareBuffer->pItem )
  {
    pPrepare = prepareBuffer->pPrepare;
    emitBuffer->pDraw = pPrepare;
  }
  else
  {
    pPrepare = this->Batches.Root.pPrev->pNext;
  }
  Size = this->Meshes.Data.Size;
  if ( this->ModifyIndex < Size )
  {
    for ( i = this->Batches.Root.pPrev; i != (Scaleform::Render::PrimitiveBatch *)&this->Batches; i = i->pPrev )
    {
      Size -= i->MeshCount;
      i->MeshIndex = Size;
      if ( Size < this->ModifyIndex )
        break;
    }
    this->ModifyIndex = this->Meshes.Data.Size;
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Primitive *, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::PrimitiveBatch *))hal->vfptr[34].__vecDelDtor)(
    hal,
    this,
    pDraw,
    pPrepare);
}

// File Line: 98
// RVA: 0x9B7A50
void __fastcall Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        void *item,
        Scaleform::Render::Primitive *p,
        Scaleform::Render::PrimitiveEmitBuffer *emitBuffer,
        Scaleform::Render::HAL *hal,
        Scaleform::Render::MeshCache *cache)
{
  Scaleform::Render::VertexFormat *pFormat; // r8
  Scaleform::Render::PrimitiveBatch *pNext; // rax

  this->pItem = item;
  this->pEmitBuffer = emitBuffer;
  this->pCache = cache;
  this->pPrimitive = p;
  this->MaximumBatchCount = 0;
  this->pHal = hal;
  pFormat = p->pFill.pObject->Data.pFormat;
  this->pSourceVFormat = pFormat;
  if ( pFormat )
  {
    ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, Scaleform::Render::VertexFormat **, _DWORD))hal->vfptr[66].__vecDelDtor)(
      hal,
      (unsigned int)p->pFill.pObject->Data.Type,
      pFormat,
      &this->pSingleVFormat,
      &this->pBatchVFormat,
      &this->pInstancedVFormat,
      0);
    this->MaximumBatchCount = (unsigned int)this->pHal->vfptr[67].__vecDelDtor(this->pHal, p);
  }
  else
  {
    this->pInstancedVFormat = 0i64;
    this->pBatchVFormat = 0i64;
    this->pSingleVFormat = 0i64;
  }
  this->State = PS_Loop;
  pNext = p->Batches.Root.pNext;
  this->Converting = 0;
  this->pConvert = pNext;
  this->pPrepareTail = pNext;
  this->pPrepare = pNext;
}

// File Line: 151
// RVA: 0x99FDC0
__int64 __fastcall Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        bool waitForCache)
{
  Scaleform::Render::PrimitiveBatch *p_Batches; // r14
  Scaleform::Render::PrimitiveBatch *pPrepare; // r8
  Scaleform::Render::Primitive *v6; // rdx
  unsigned int v7; // ecx
  Scaleform::Render::PrimitiveBatch *j; // rax
  unsigned int MeshCount; // r9d
  __int64 MeshIndex; // rdx
  __int64 v11; // rcx
  Scaleform::Render::Primitive::MeshEntry *Data; // r8
  Scaleform::Render::MeshBase **p_pObject; // r8
  __int64 v14; // rdx
  Scaleform::Render::MeshBase *v15; // rax
  Scaleform::Render::PrimitiveBatch *v16; // rdi
  Scaleform::HashSetLH<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > *p_BatchCacheItemHash; // rcx
  Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor> > v18; // rsi
  signed __int64 v19; // rax
  Scaleform::Render::MeshCacheItemUseNode *p_MeshNode; // rdx
  Scaleform::Render::MeshCacheItem *v21; // r8
  Scaleform::Render::MeshCacheItem *pMeshItem; // r8
  Scaleform::Render::MeshCacheListSet *pCacheList; // rdx
  __int64 ListType; // rax
  Scaleform::Render::MeshCacheListSet *v25; // rdx
  Scaleform::Render::PrimitiveBatch *v26; // rcx
  Scaleform::Render::PrimitiveBatch *pConvert; // rax
  Scaleform::Render::PrimitiveBatch *pNext; // rcx
  Scaleform::Render::PrimitiveBatch *v29; // rdx
  Scaleform::Render::Primitive *pPrimitive; // rdx
  unsigned int Size; // ecx
  Scaleform::Render::PrimitiveBatch *i; // rax
  Scaleform::Render::MeshCacheItem::MeshContent key; // [rsp+20h] [rbp-38h] BYREF

  p_Batches = (Scaleform::Render::PrimitiveBatch *)&this->pPrimitive->Batches;
  if ( this->pPrepare == p_Batches )
    return 0i64;
  while ( this->pPrepare == this->pPrepareTail )
  {
LABEL_26:
    if ( this->Converting )
      goto LABEL_39;
    if ( this->pConvert != p_Batches )
    {
      do
      {
        pConvert = this->pConvert;
        if ( pConvert->Type == DP_Virtual )
          break;
        this->pPrepareTail = pConvert;
        pNext = pConvert->pNext;
        this->pConvert = pNext;
      }
      while ( pNext != p_Batches );
    }
    v29 = this->pConvert;
    if ( v29 != p_Batches )
    {
      pPrimitive = v29->pPrimitive;
      Size = pPrimitive->Meshes.Data.Size;
      if ( pPrimitive->ModifyIndex < Size )
      {
        for ( i = pPrimitive->Batches.Root.pPrev;
              i != (Scaleform::Render::PrimitiveBatch *)&pPrimitive->Batches;
              i = i->pPrev )
        {
          Size -= i->MeshCount;
          i->MeshIndex = Size;
          if ( Size < pPrimitive->ModifyIndex )
            break;
        }
        pPrimitive->ModifyIndex = pPrimitive->Meshes.Data.Size;
      }
      if ( !this->pConvert->MeshCount )
        goto LABEL_40;
      this->Converting = 1;
LABEL_39:
      Scaleform::Render::PrimitivePrepareBuffer::batchConvertStep(this);
      goto LABEL_40;
    }
    this->pPrepareTail = v29;
LABEL_40:
    if ( this->pPrepare == p_Batches )
      return 0i64;
  }
  while ( 1 )
  {
    pPrepare = this->pPrepare;
    if ( pPrepare->MeshNode.pMeshItem )
      goto LABEL_23;
    v6 = pPrepare->pPrimitive;
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
    MeshCount = 1;
    if ( pPrepare->Type != DP_Instanced )
      MeshCount = pPrepare->MeshCount;
    MeshIndex = pPrepare->MeshIndex;
    v11 = MeshCount;
    Data = pPrepare->pPrimitive->Meshes.Data.Data;
    key.Meshes.Size = MeshCount;
    key.Meshes.StrideSize = 16i64;
    p_pObject = &Data[MeshIndex].pMesh.pObject;
    v14 = 0i64;
    key.Meshes.pData = p_pObject;
    if ( MeshCount )
    {
      do
      {
        v15 = *p_pObject;
        p_pObject += 2;
        v14 ^= (unsigned __int64)v15 >> 5;
        --v11;
      }
      while ( v11 );
    }
    v16 = this->pPrepare;
    key.HashKey = v14;
    if ( v16->Type == DP_Failed )
      goto LABEL_22;
    if ( this->State )
      break;
    p_BatchCacheItemHash = &this->pCache->BatchCacheItemHash;
    v18.pTable = p_BatchCacheItemHash->pTable;
    if ( !p_BatchCacheItemHash->pTable )
      break;
    v19 = Scaleform::HashSetBase<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::Render::MeshCacheItem::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::MeshCacheItem *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::MeshCacheItem *,Scaleform::Render::MeshCacheItem::HashFunctor>>::findIndexCore<Scaleform::Render::MeshCacheItem::MeshContent>(
            p_BatchCacheItemHash,
            &key,
            (unsigned int)v14 & v18.pTable->SizeMask);
    if ( v19 < 0 )
      break;
    p_MeshNode = &v16->MeshNode;
    v21 = (Scaleform::Render::MeshCacheItem *)*(&v18.pTable[2].EntryCount + 3 * v19);
    if ( v16->MeshNode.pMeshItem )
    {
      v16->MeshNode.pPrev->pNext = v16->MeshNode.pNext;
      v16->MeshNode.pNext->pPrev = p_MeshNode->pPrev;
      p_MeshNode->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v16->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    }
    v16->MeshNode.pMeshItem = v21;
    if ( v21 )
    {
      v16->MeshNode.pNext = v21->PrimitiveBatches.Root.pNext;
      p_MeshNode->pPrev = (Scaleform::Render::MeshCacheItemUseNode *)&v21->PrimitiveBatches;
      v21->PrimitiveBatches.Root.pNext->pPrev = p_MeshNode;
      v21->PrimitiveBatches.Root.pNext = p_MeshNode;
    }
LABEL_22:
    this->State = PS_Loop;
    waitForCache = 0;
LABEL_23:
    pMeshItem = this->pPrepare->MeshNode.pMeshItem;
    if ( pMeshItem )
    {
      pCacheList = pMeshItem->pCacheList;
      pMeshItem->pPrev->pNext = pMeshItem->pNext;
      pMeshItem->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$A6A32721DD821860D2CFF437DFF6F231::pPrev = pMeshItem->pPrev;
      ListType = pMeshItem->ListType;
      pMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
      pMeshItem->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
      pCacheList->Slots[ListType].Size -= pMeshItem->AllocSize;
      v25 = pMeshItem->pCacheList;
      pMeshItem->ListType = MCL_InFlight;
      pMeshItem->pNext = v25->Slots[1].Root.pNext;
      pMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)&v25->Slots[1];
      v25->Slots[1].Root.pNext->pPrev = pMeshItem;
      v25->Slots[1].Root.pNext = pMeshItem;
      v25->Slots[1].Size += pMeshItem->AllocSize;
    }
    v26 = this->pPrepare->pNext;
    this->pPrepare = v26;
    if ( v26 == this->pPrepareTail )
      goto LABEL_26;
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::MeshCacheItem::MeshContent *, bool))this->pCache->vfptr[4].UnlockBuffers)(
         this->pCache,
         v16,
         &key,
         waitForCache) )
  {
    goto LABEL_22;
  }
  this->State = PS_NeedCache;
  return 1i64;
}

// File Line: 263
// RVA: 0x9CED30
void __fastcall Scaleform::Render::PrimitivePrepareBuffer::batchConvertStep(
        Scaleform::Render::PrimitivePrepareBuffer *this)
{
  Scaleform::Render::MeshCache *pCache; // rcx
  Scaleform::Render::MeshCacheConfigVtbl *vfptr; // rax
  unsigned int v4; // esi
  char v5; // r13
  unsigned int v6; // r14d
  unsigned int v7; // ebp
  int v8; // r12d
  __int64 v9; // rax
  Scaleform::Render::VertexFormat *batchFormat; // rdx
  unsigned int v11; // r11d
  __int64 v12; // r8
  Scaleform::Render::PrimitiveBatch *pConvert; // rcx
  unsigned int v14; // r15d
  bool v15; // r9
  __int64 v16; // r10
  unsigned int MeshCount; // eax
  Scaleform::Render::Mesh **v18; // r13
  __int64 v19; // rcx
  Scaleform::Render::Mesh *v20; // rdi
  unsigned int MaximumBatchCount; // eax
  unsigned int v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // r14d
  Scaleform::Render::PrimitiveBatch *v25; // rdi
  Scaleform::Render::PrimitiveBatch *v26; // r8
  Scaleform::Render::PrimitiveBatch *v27; // rdx
  Scaleform::Render::PrimitiveBatch *pNext; // r8
  Scaleform::Render::PrimitiveBatch *v29; // r9
  unsigned int MeshIndex; // esi
  Scaleform::Render::Primitive *pPrimitive; // rdi
  __int64 v32; // rax
  Scaleform::Render::PrimitiveBatch *v33; // r8
  Scaleform::Render::PrimitiveEmitBuffer *pEmitBuffer; // rcx
  Scaleform::Render::PrimitiveBatch *v35; // rax
  Scaleform::Render::Primitive *v36; // rdi
  unsigned int v37; // esi
  __int64 v38; // rax
  Scaleform::Render::PrimitiveBatch *v39; // r14
  Scaleform::Render::PrimitiveBatch *v40; // rdx
  Scaleform::Render::PrimitiveEmitBuffer *v41; // rcx
  Scaleform::Render::PrimitiveBatch *v42; // rdx
  unsigned int knownIndexCount; // [rsp+40h] [rbp-78h] BYREF
  unsigned int knownVerticesSize; // [rsp+44h] [rbp-74h] BYREF
  unsigned int Size; // [rsp+48h] [rbp-70h]
  unsigned int v46; // [rsp+4Ch] [rbp-6Ch]
  Scaleform::Render::MeshCache::MeshResult result; // [rsp+50h] [rbp-68h] BYREF
  __int64 v48; // [rsp+58h] [rbp-60h]
  Scaleform::Render::Mesh *v49; // [rsp+60h] [rbp-58h]
  __int64 v50; // [rsp+68h] [rbp-50h]
  char v51; // [rsp+C0h] [rbp+8h]
  bool v52; // [rsp+C8h] [rbp+10h]
  char v53; // [rsp+D0h] [rbp+18h]
  unsigned int v54; // [rsp+D8h] [rbp+20h]

  pCache = this->pCache;
  vfptr = pCache->Scaleform::Render::MeshCacheConfig::vfptr;
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
  v9 = (__int64)vfptr->GetParams(&pCache->Scaleform::Render::MeshCacheConfig);
  batchFormat = this->pBatchVFormat;
  v11 = *(_DWORD *)(v9 + 52);
  v12 = v9;
  v50 = v9;
  v54 = v11;
  if ( batchFormat )
    Size = batchFormat->Size;
  else
    Size = 0;
  pConvert = this->pConvert;
  v14 = 0;
  v15 = this->pInstancedVFormat != 0i64;
  v52 = v15;
  v16 = (__int64)&pConvert->pPrimitive->Meshes.Data.Data[pConvert->MeshIndex];
  MeshCount = pConvert->MeshCount;
  v48 = v16;
  v46 = MeshCount;
  if ( !MeshCount )
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
        MaximumBatchCount = this->MaximumBatchCount;
        if ( v7 == MaximumBatchCount )
          goto LABEL_35;
        if ( ++v7 >= MaximumBatchCount )
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
      this->pCache,
      &result,
      v20,
      this->pSourceVFormat,
      this->pSingleVFormat,
      batchFormat,
      0);
    if ( result.Value > Success_LargeMesh && result.Value != Fail_LargeMesh_NeedCache )
    {
      if ( result.Value == Fail_LargeMesh_TooBig )
      {
        v51 = 1;
LABEL_21:
        v8 = 4;
        goto LABEL_22;
      }
      if ( result.Value != Fail_LargeMesh_ThisFrame )
        goto LABEL_21;
    }
LABEL_22:
    v11 = v54;
    v12 = v50;
    v15 = v52;
    v19 = (__int64)v49;
LABEL_23:
    if ( v20->LargeMesh || v8 == 4 || (batchFormat = this->pBatchVFormat) == 0i64 )
    {
      v11 = 1;
      v53 = 1;
LABEL_34:
      ++v14;
LABEL_35:
      v16 = v48;
      v5 = v51;
      goto LABEL_36;
    }
    v6 += v20->IndexCount;
    if ( v6 > *(_DWORD *)(v12 + 64) )
      break;
    v4 += Size * v20->VertexCount;
    if ( v4 > *(_DWORD *)(v12 + 60) || v14 >= this->MaximumBatchCount )
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
  v16 = v48;
  v5 = v51;
  if ( v20 == (Scaleform::Render::Mesh *)v19 )
    --v7;
LABEL_36:
  v22 = v14;
  if ( v15 )
  {
    v23 = this->pConvert->MeshCount;
    if ( v14 < v23 )
    {
      do
      {
        if ( *(_QWORD *)(v16 + 16i64 * v22 + 8) != *(_QWORD *)(v16 + 16i64 * (v14 - 1) + 8) )
          break;
        if ( v7 >= this->MaximumBatchCount )
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
    v25 = this->pConvert;
    if ( v14 != v25->MeshCount || v7 )
    {
      MeshIndex = v25->MeshIndex;
      pPrimitive = v25->pPrimitive;
      v32 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Primitive *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
              Scaleform::Memory::pGlobalHeap,
              pPrimitive,
              80i64);
      *(_QWORD *)(v32 + 32) = 0i64;
      *(_DWORD *)(v32 + 40) = 1;
      *(_QWORD *)(v32 + 48) = 0i64;
      *(_BYTE *)(v32 + 56) = 0;
      *(_QWORD *)(v32 + 64) = pPrimitive;
      *(_DWORD *)(v32 + 72) = v24;
      *(_DWORD *)(v32 + 76) = MeshIndex;
      v33 = this->pConvert;
      v29 = (Scaleform::Render::PrimitiveBatch *)v32;
      *(_QWORD *)(v32 + 8) = v33->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$562A4EA56C1311C603F27EF2D0BF37C2::pPrev;
      *(_QWORD *)v32 = v33->pPrev;
      v33->pPrev->pNext = (Scaleform::Render::PrimitiveBatch *)v32;
      v33->pPrev = (Scaleform::Render::PrimitiveBatch *)v32;
      this->pConvert->MeshIndex += v24;
      this->pConvert->MeshCount -= v24;
      pEmitBuffer = this->pEmitBuffer;
      if ( this->pItem == pEmitBuffer->pItem && pEmitBuffer->pDraw == this->pConvert )
        pEmitBuffer->pDraw = (Scaleform::Render::PrimitiveBatch *)v32;
      if ( this->pPrepare == this->pConvert )
        this->pPrepare = (Scaleform::Render::PrimitiveBatch *)v32;
    }
    else
    {
      v25->Type = DP_Batch;
      v26 = this->pConvert;
      if ( this->pPrepareTail != v26 )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          this,
          v26->pPrev,
          v26,
          v26->pPrev,
          v26,
          &knownVerticesSize,
          &knownIndexCount);
      v27 = this->pConvert;
      pNext = v27->pNext;
      if ( pNext != (Scaleform::Render::PrimitiveBatch *)&this->pPrimitive->Batches )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          this,
          v27,
          pNext,
          v27->pNext,
          v27,
          &knownVerticesSize,
          &knownIndexCount);
      v29 = this->pConvert;
    }
    if ( v29->MeshCount == 1 )
    {
      v29->Type = DP_Single;
      v29->pFormat = this->pSingleVFormat;
    }
    else
    {
      v29->pFormat = this->pBatchVFormat;
    }
    this->pPrepareTail = this->pConvert;
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
    v35 = this->pConvert;
    v36 = v35->pPrimitive;
    v37 = v35->MeshIndex;
    v38 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Primitive *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v36,
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
      *(_QWORD *)(v38 + 48) = this->pInstancedVFormat;
    }
    else if ( (v8 & 0xFFFFFFFB) == 0 )
    {
      *(_QWORD *)(v38 + 48) = this->pSingleVFormat;
    }
    v40 = this->pConvert;
    *(_QWORD *)(v38 + 8) = v40->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$562A4EA56C1311C603F27EF2D0BF37C2::pPrev;
    *(_QWORD *)v38 = v40->pPrev;
    v40->pPrev->pNext = (Scaleform::Render::PrimitiveBatch *)v38;
    v40->pPrev = (Scaleform::Render::PrimitiveBatch *)v38;
    this->pConvert->MeshIndex += v7;
    this->pConvert->MeshCount -= v7;
    v41 = this->pEmitBuffer;
    if ( this->pItem == v41->pItem && v41->pDraw == this->pConvert )
      v41->pDraw = (Scaleform::Render::PrimitiveBatch *)v38;
    v42 = this->pConvert;
    if ( this->pPrepare == v42 )
      this->pPrepare = (Scaleform::Render::PrimitiveBatch *)v38;
    if ( !v42->MeshCount )
    {
      v42->pPrev->pNext = v42->pNext;
      v42->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$562A4EA56C1311C603F27EF2D0BF37C2::pPrev = v42->pPrev;
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
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->pConvert = v39;
    }
    this->pPrepareTail = v39;
  }
  if ( v14 >= v46 )
    this->Converting = 0;
}

// File Line: 552
// RVA: 0x9CEBE0
bool __fastcall Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        Scaleform::Render::PrimitiveBatch *pfirst,
        Scaleform::Render::PrimitiveBatch *psecond,
        Scaleform::Render::PrimitiveBatch *pother,
        Scaleform::Render::PrimitiveBatch *pknown,
        unsigned int *knownVerticesSize,
        unsigned int *knownIndexCount)
{
  Scaleform::Render::MeshCacheParams *v11; // rax
  unsigned int v12; // r15d
  Scaleform::Render::MeshCacheParams *v13; // rdi
  unsigned int *v15; // r12
  unsigned int *v16; // r14
  unsigned int v17; // r13d
  Scaleform::Render::PrimitiveBatch *v18; // rdi
  Scaleform::Render::PrimitiveBatch *v19; // rcx
  unsigned int MeshIndex; // eax
  Scaleform::Render::PrimitiveEmitBuffer *pEmitBuffer; // rcx
  Scaleform::Render::VertexFormat *pBatchVFormat; // rax
  unsigned int ptotalIndices[4]; // [rsp+20h] [rbp-38h] BYREF
  unsigned int ptotalVertices; // [rsp+78h] [rbp+20h] BYREF

  if ( pother->LargeMesh || !this->pBatchVFormat || pother->Type > (unsigned int)DP_Batch )
    return 0;
  v11 = this->pCache->vfptr->GetParams(&this->pCache->Scaleform::Render::MeshCacheConfig);
  v12 = psecond->MeshCount + pfirst->MeshCount;
  v13 = v11;
  if ( v12 > this->MaximumBatchCount )
    return 0;
  Scaleform::Render::PrimitiveBatch::CalcMeshSizes(pother, &ptotalVertices, ptotalIndices);
  v15 = knownVerticesSize;
  if ( *knownVerticesSize + ptotalVertices * this->pBatchVFormat->Size <= v13->MaxVerticesSizeInBatch )
  {
    v16 = knownIndexCount;
    v17 = ptotalIndices[0];
    if ( ptotalIndices[0] + *knownIndexCount <= v13->MaxIndicesInBatch )
    {
      v18 = pknown;
      v19 = pknown;
      pknown->MeshCount = v12;
      MeshIndex = pfirst->MeshIndex;
      v19->Type = DP_Batch;
      v19->MeshIndex = MeshIndex;
      Scaleform::Render::PrimitiveBatch::ClearCacheItem(v19);
      Scaleform::Render::PrimitiveBatch::RemoveAndFree(pother);
      pEmitBuffer = this->pEmitBuffer;
      if ( this->pItem == pEmitBuffer->pItem && pEmitBuffer->pDraw == pfirst )
        pEmitBuffer->pDraw = v18;
      if ( this->pPrepare == pfirst )
        this->pPrepare = v18;
      pBatchVFormat = this->pBatchVFormat;
      this->pConvert = v18;
      *v15 += ptotalVertices * pBatchVFormat->Size;
      *v16 += v17;
      this->Converting = 0;
    }
  }
  return 0;
}

