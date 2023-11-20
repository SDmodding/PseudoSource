// File Line: 179
// RVA: 0x9CA1C0
void __fastcall Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(Scaleform::Render::TextPrepareBuffer *this, bool startFlag)
{
  Scaleform::Render::TreeCacheText *v2; // rbp
  bool v3; // r14
  Scaleform::Render::TextPrepareBuffer *v4; // rdi
  Scaleform::Render::TreeCacheText *v5; // rsi
  Scaleform::Render::TextPrimitiveBundle *v6; // rbx
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // rax
  signed __int64 v9; // r9
  __int64 v10; // r9
  unsigned __int64 i; // rdx
  __int64 v12; // r8
  signed __int64 v13; // rax
  Scaleform::Render::TreeCacheText *v14; // rcx
  Scaleform::Render::TextMeshProvider *v15; // rbx
  unsigned int v16; // eax
  Scaleform::Render::GlyphCache *v17; // rcx
  Scaleform::Render::TreeCacheText *v18; // rcx

  v2 = this->pRemainingTextFields;
  v3 = startFlag;
  v4 = this;
  if ( v2 )
  {
    do
    {
      v5 = v4->pRemainingTextFields->pNextNoBatch;
      if ( !v4->LayersPinned )
      {
        v6 = v4->pBundle;
        v7 = 0i64;
        v8 = v6->Layers.Size;
        if ( v8 )
        {
          do
          {
            if ( v8 <= 2 )
              v9 = (signed __int64)&v6->Layers.8;
            else
              v9 = (signed __int64)v6->Layers.AD.pData;
            v10 = *(_QWORD *)(v9 + 8 * v7);
            for ( i = 0i64; i < *(_QWORD *)(v10 + 112); ++i )
            {
              v12 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v10 + 104) + 8 * i) + 56i64);
              v13 = v12 + 208;
              if ( !((*(_DWORD *)(v12 + 240) >> 5) & 1) )
                v13 = 0i64;
              ++*(_QWORD *)(v13 + 136);
            }
            v8 = v6->Layers.Size;
            ++v7;
          }
          while ( v7 < v8 );
        }
        v4->LayersPinned = 1;
      }
      v14 = v4->pRemainingTextFields;
      if ( !((v14->TMProvider.Flags >> 5) & 1)
        || (v15 = &v14->TMProvider, v14 == (Scaleform::Render::TreeCacheText *)-208i64) )
      {
        v15 = Scaleform::Render::TreeCacheText::CreateMeshProvider(v14);
        if ( !v15 )
          break;
      }
      v16 = v15->Flags;
      if ( !(v16 & 6) )
      {
        v17 = v15->pCache;
        v15->Flags = v16 | 2;
        v15->pPrev = v17->TextInUse.Root.pPrev;
        v15->pNext = (Scaleform::Render::TextMeshProvider *)&v17->RectsToUpdate.Capacity;
        v17->TextInUse.Root.pPrev->pNext = v15;
        v17->TextInUse.Root.pPrev = v15;
      }
      if ( Scaleform::Render::TextPrimitiveBundle::addAndPinBatchLayers(v4->pBundle, v4->pRemainingTextFields, v15) )
      {
        v18 = v4->pRemainingTextFields;
        v15->pBundle = v4->pBundle;
        v15->pBundleEntry = &v18->SorterShapeNode;
      }
      v4->pRemainingTextFields->pNextNoBatch = 0i64;
      v4->pRemainingTextFields = v5;
    }
    while ( v5 );
  }
  if ( !v3 && v2 == v4->pRemainingTextFields )
    v4->pRemainingTextFields = 0i64;
}

// File Line: 221
// RVA: 0x9A00D0
signed __int64 __fastcall Scaleform::Render::TextPrepareBuffer::ProcessPrimitive(Scaleform::Render::TextPrepareBuffer *this, bool waitForCache)
{
  bool v2; // si
  Scaleform::Render::TextPrepareBuffer *v3; // rbx
  Scaleform::Render::TextPrimitiveBundle *v4; // rax
  signed __int64 v5; // rcx
  Scaleform::Render::Primitive *v6; // rdx

  v2 = waitForCache;
  v3 = this;
  if ( this->LayersFinished )
  {
    this->PPBuffer.pItem = 0i64;
    Scaleform::Render::TextPrimitiveBundle::clearBatchLayers(this->pBundle);
    Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(v3, 0);
    v3->LayersFinished = 0;
    v3->ProcessingLayer = 0i64;
  }
  if ( v3->ProcessingLayer < v3->pBundle->Layers.Size )
  {
    do
    {
      v4 = v3->pBundle;
      if ( v4->Layers.Size <= 2 )
        v5 = (signed __int64)&v4->Layers.8;
      else
        v5 = (signed __int64)v4->Layers.AD.pData;
      v6 = *(Scaleform::Render::Primitive **)(v5 + 8 * v3->ProcessingLayer);
      if ( v6 != v3->PPBuffer.pItem )
        Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
          &v3->PPBuffer,
          v6,
          v6,
          &v3->pEmitBuffer->PEBuffer,
          v3->pHal,
          v3->pCache);
      if ( (unsigned int)Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(&v3->PPBuffer, v2) == 1 )
        return 1i64;
    }
    while ( ++v3->ProcessingLayer < v3->pBundle->Layers.Size );
  }
  if ( v3->LayersPinned )
  {
    Scaleform::Render::TextPrimitiveBundle::unpinLayerBatches(v3->pBundle);
    v3->LayersPinned = 0;
  }
  if ( v3->pRemainingTextFields )
  {
    v3->LayersFinished = 1;
    return 1i64;
  }
  return 0i64;
}

// File Line: 267
// RVA: 0x96FBD0
void __fastcall Scaleform::Render::TextEmitBuffer::EmitPrimitive(Scaleform::Render::TextEmitBuffer *this, Scaleform::Render::TextPrepareBuffer *prepareBuffer, Scaleform::Render::HAL *hal)
{
  Scaleform::Render::TextPrimitiveBundle *v3; // rax
  Scaleform::Render::HAL *v4; // rsi
  Scaleform::Render::TextPrepareBuffer *v5; // r14
  Scaleform::Render::TextEmitBuffer *v6; // rbx
  char v7; // r15
  unsigned __int64 v8; // rbp
  Scaleform::Render::TextPrimitiveBundle *v9; // rcx
  signed __int64 v10; // rdi
  __int64 v11; // rdi
  signed int v12; // eax
  Scaleform::Render::PrimitiveBatch *v13; // r8
  Scaleform::Render::PrimitiveBatch *v14; // r9
  unsigned int v15; // ecx
  __int64 *i; // rax

  v3 = this->pBundle;
  v4 = hal;
  v5 = prepareBuffer;
  v6 = this;
  v7 = 1;
  if ( this->pItem == prepareBuffer->pItem )
  {
    v8 = prepareBuffer->ProcessingLayer;
    if ( v8 < v3->Layers.Size )
    {
      ++v8;
      v7 = 0;
    }
  }
  else
  {
    v8 = v3->Layers.Size;
  }
  if ( this->EmitLayer < v8 )
  {
    do
    {
      v9 = v6->pBundle;
      if ( v9->Layers.Size <= 2 )
        v10 = (signed __int64)&v9->Layers.8;
      else
        v10 = (signed __int64)v9->Layers.AD.pData;
      v11 = *(_QWORD *)(v10 + 8 * v6->EmitLayer);
      v12 = *(_DWORD *)(v11 + 96);
      if ( v12 >= 11 )
      {
        if ( v12 == 11 )
        {
          if ( v6->MaskStatus == Mask_NotInUse && v9->pMaskPrimitive.pObject )
          {
            ((void (__fastcall *)(Scaleform::Render::HAL *))v4->vfptr[36].__vecDelDtor)(v4);
            v6->MaskStatus = 1;
          }
        }
        else if ( v6->MaskStatus == 1 )
        {
          ((void (__fastcall *)(Scaleform::Render::HAL *))v4->vfptr[37].__vecDelDtor)(v4);
          v6->MaskStatus = 2;
        }
      }
      if ( (void *)v11 == v6->PEBuffer.pItem )
      {
        v13 = v6->PEBuffer.pDraw;
      }
      else
      {
        v13 = *(Scaleform::Render::PrimitiveBatch **)(v11 + 48);
        v6->PEBuffer.pItem = (void *)v11;
        v6->PEBuffer.pDraw = v13;
      }
      if ( (void *)v11 == v5->PPBuffer.pItem )
      {
        v14 = v5->PPBuffer.pPrepare;
        v6->PEBuffer.pDraw = v14;
      }
      else
      {
        v14 = *(Scaleform::Render::PrimitiveBatch **)(*(_QWORD *)(v11 + 40) + 8i64);
      }
      v15 = *(_DWORD *)(v11 + 72);
      if ( *(_DWORD *)(v11 + 88) < v15 )
      {
        for ( i = *(__int64 **)(v11 + 40); i != (__int64 *)(v11 + 40); i = (__int64 *)*i )
        {
          v15 -= *((_DWORD *)i + 18);
          *((_DWORD *)i + 19) = v15;
          if ( v15 < *(_DWORD *)(v11 + 88) )
            break;
        }
        *(_DWORD *)(v11 + 88) = *(_DWORD *)(v11 + 72);
      }
      ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::PrimitiveBatch *))v4->vfptr[34].__vecDelDtor)(
        v4,
        v11,
        v13,
        v14);
      ++v6->EmitLayer;
    }
    while ( v6->EmitLayer < v8 );
  }
  if ( v7 )
  {
    if ( v6->MaskStatus )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))v4->vfptr[38].__vecDelDtor)(v4);
      v6->MaskStatus = 0;
    }
    v6->pItem = 0i64;
  }
  else
  {
    --v6->EmitLayer;
  }
}

// File Line: 348
// RVA: 0x9A9B50
bool __fastcall Scaleform::Render::TextLayerPrimitive::RemoveEntry(Scaleform::Render::TextLayerPrimitive *this, Scaleform::Render::BundleEntry *e)
{
  Scaleform::Render::BundleEntry *v2; // rsi
  Scaleform::Render::TextLayerPrimitive *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::BundleEntry **v5; // rdx
  unsigned __int64 v6; // r8

  v2 = e;
  v3 = this;
  v4 = 0i64;
  if ( this->Entries.Data.Size )
  {
    do
    {
      v5 = v3->Entries.Data.Data;
      if ( v5[v4] == v2 )
      {
        v6 = v3->Entries.Data.Size;
        if ( v6 == 1 )
        {
          if ( v3->Entries.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
          {
            if ( v5 )
            {
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v3->Entries.Data.Data = 0i64;
            }
            v3->Entries.Data.Policy.Capacity = 0i64;
          }
          v3->Entries.Data.Size = 0i64;
        }
        else
        {
          memmove(&v5[v4], &v5[v4 + 1], 8 * (v6 - v4) - 8);
          --v3->Entries.Data.Size;
        }
        Scaleform::Render::Primitive::Remove((Scaleform::Render::Primitive *)&v3->vfptr, v4--, 1u);
      }
      ++v4;
    }
    while ( v4 < v3->Entries.Data.Size );
  }
  return 0;
}

// File Line: 399
// RVA: 0x946250
void __fastcall Scaleform::Render::TextPrimitiveBundle::TextPrimitiveBundle(Scaleform::Render::TextPrimitiveBundle *this)
{
  Scaleform::Render::TextPrimitiveBundle *v1; // rbx

  v1 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::Bundle'};
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  v1->Layers.Size = 0i64;
  v1->pMaskPrimitive.pObject = 0i64;
}

// File Line: 402
// RVA: 0x94D380
void __fastcall Scaleform::Render::TextPrimitiveBundle::~TextPrimitiveBundle(Scaleform::Render::TextPrimitiveBundle *this)
{
  Scaleform::Render::TextPrimitiveBundle *v1; // rbx
  Scaleform::Render::MaskPrimitive *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::Bundle'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  v2 = this->pMaskPrimitive.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::~ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>(&v1->Layers);
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Entries.Data.Data);
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
}

// File Line: 406
// RVA: 0x995420
void __fastcall Scaleform::Render::TextPrimitiveBundle::InsertEntry(Scaleform::Render::TextPrimitiveBundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::Bundle::InsertEntry((Scaleform::Render::Bundle *)&this->vfptr, index, entry);
}

// File Line: 417
// RVA: 0x9A99A0
void __fastcall Scaleform::Render::TextPrimitiveBundle::RemoveEntries(Scaleform::Render::TextPrimitiveBundle *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r14
  Scaleform::Render::TextPrimitiveBundle *v6; // rsi
  unsigned __int64 i; // rbx
  Scaleform::Render::TreeCacheNode *v8; // rdx
  signed __int64 v9; // rdi

  v3 = index + count;
  v4 = count;
  v5 = index;
  v6 = this;
  for ( i = index; i < v3; ++i )
  {
    v8 = v6->Entries.Data.Data[i]->pSourceNode;
    if ( (LODWORD(v8[2].pNext) >> 5) & 1 )
    {
      v9 = (signed __int64)&v8[1].SortParentBounds;
      if ( v8 != (Scaleform::Render::TreeCacheNode *)-208i64 )
      {
        if ( v8[3].pNext )
        {
          Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(v6, (Scaleform::Render::BundleEntry *)&v8[1]);
          *(_QWORD *)(v9 + 144) = 0i64;
          *(_QWORD *)(v9 + 152) = 0i64;
        }
      }
    }
  }
  Scaleform::Render::Bundle::RemoveEntries((Scaleform::Render::Bundle *)&v6->vfptr, v5, v4);
}

// File Line: 434
// RVA: 0x9BF320
void __fastcall Scaleform::Render::TextPrimitiveBundle::UpdateMesh(Scaleform::Render::TextPrimitiveBundle *this, Scaleform::Render::BundleEntry *entry)
{
  unsigned __int64 v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::Render::TextPrimitiveBundle *v4; // r10
  unsigned __int64 v5; // rax
  Scaleform::Render::BundleEntry **v6; // rcx
  Scaleform::Render::TreeCacheNode *v7; // rdx
  signed __int64 v8; // rbx

  v2 = entry->IndexHint;
  v3 = this->Entries.Data.Size;
  v4 = this;
  if ( v2 >= v3 || this->Entries.Data.Data[v2] != entry )
  {
    v5 = 0i64;
    if ( !v3 )
      return;
    v6 = this->Entries.Data.Data;
    while ( *v6 != entry )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3 )
        return;
    }
    entry->IndexHint = v5;
  }
  v7 = entry->pSourceNode;
  if ( (LODWORD(v7[2].pNext) >> 5) & 1 )
  {
    v8 = (signed __int64)&v7[1].SortParentBounds;
    if ( v7 != (Scaleform::Render::TreeCacheNode *)-208i64 )
    {
      if ( v7[3].pNext )
      {
        Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(v4, (Scaleform::Render::BundleEntry *)&v7[1]);
        *(_QWORD *)(v8 + 144) = 0i64;
        *(_QWORD *)(v8 + 152) = 0i64;
      }
    }
  }
}

// File Line: 453
// RVA: 0x99F830
Scaleform::Render::RenderQueueItem::QIPrepareResult __fastcall Scaleform::Render::TextPrimitiveBundle::Prepare(Scaleform::Render::TextPrimitiveBundle *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp, bool waitForCache)
{
  bool v4; // di
  Scaleform::Render::TextPrepareBuffer *v6; // rbx

  v4 = waitForCache;
  if ( qp->QueuePrepareFilter )
    return 0;
  v6 = (Scaleform::Render::TextPrepareBuffer *)&qp->72;
  if ( item != qp->PrepareItemBuffer.pItem )
    Scaleform::Render::TextPrimitiveBundle::startPrimitive(
      (Scaleform::Render::TextPrimitiveBundle *)((char *)this - 56),
      item,
      (Scaleform::Render::TextPrepareBuffer *)&qp->72,
      qp);
  return Scaleform::Render::TextPrepareBuffer::ProcessPrimitive(v6, v4);
}

// File Line: 464
// RVA: 0x96FF60
void __fastcall Scaleform::Render::TextPrimitiveBundle::EmitToHAL(Scaleform::Render::TextPrimitiveBundle *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::TextPrimitiveBundle *v3; // rax
  Scaleform::Render::TextEmitBuffer *v4; // rcx

  v3 = this;
  if ( qp->QueueEmitFilter == QPF_All )
  {
    v4 = (Scaleform::Render::TextEmitBuffer *)&qp->264;
    if ( item != qp->EmitItemBuffer.pItem )
    {
      v4->pItem = item;
      *(_OWORD *)&qp->EmitItemBufferBytes[8] = (unsigned __int64)&v3[-1].pTop;
      *(_DWORD *)&qp->EmitItemBufferBytes[24] = 0;
      *(_QWORD *)&qp->EmitItemBufferBytes[32] = 0i64;
    }
    Scaleform::Render::TextEmitBuffer::EmitPrimitive(v4, (Scaleform::Render::TextPrepareBuffer *)&qp->72, qp->pHAL);
  }
}

// File Line: 481
// RVA: 0x9F38F0
void __fastcall Scaleform::Render::TextPrimitiveBundle::startPrimitive(Scaleform::Render::TextPrimitiveBundle *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::TextPrepareBuffer *prepareBuffer, Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::TreeCacheText *v4; // rsi
  unsigned __int64 v5; // r10
  Scaleform::Render::TextPrepareBuffer *v6; // rdi
  Scaleform::Render::RenderQueueItem *v7; // r8
  Scaleform::Render::TextPrimitiveBundle *v8; // rbx
  Scaleform::Render::TreeCacheNode *v9; // rdx
  signed __int64 v10; // rax
  int v11; // ecx
  Scaleform::Render::TreeCacheNode *v12; // rdx
  Scaleform::Render::HAL *v13; // rcx
  __int64 v14; // rax

  v4 = 0i64;
  v5 = 0i64;
  v6 = prepareBuffer;
  v7 = item;
  v8 = this;
  if ( this->Entries.Data.Size )
  {
    do
    {
      v9 = v8->Entries.Data.Data[v5]->pSourceNode;
      if ( (LODWORD(v9[2].pNext) >> 5) & 1
        && (v10 = (signed __int64)&v9[1].SortParentBounds, v9 != (Scaleform::Render::TreeCacheNode *)-208i64)
        && (Scaleform::Render::TextPrimitiveBundle *)v9[3].pNext == v8 )
      {
        v11 = (int)v9[2].pNext;
        if ( !(v11 & 6) )
        {
          v12 = v9[2].pPrev;
          *(_DWORD *)(v10 + 32) = v11 | 2;
          *(_QWORD *)(v10 + 8) = v12[41].pNextUpdate;
          *(_QWORD *)(v10 + 16) = (char *)v12 + 4664;
          v12[41].pNextUpdate->pNext = (Scaleform::Render::TreeCacheNode *)v10;
          v12[41].pNextUpdate = (Scaleform::Render::TreeCacheNode *)v10;
        }
      }
      else
      {
        v9[1].pNextUpdate = (Scaleform::Render::TreeCacheNode *)&v4->vfptr;
        v4 = (Scaleform::Render::TreeCacheText *)v9;
      }
      ++v5;
    }
    while ( v5 < v8->Entries.Data.Size );
  }
  v13 = qp->pHAL;
  v6->pItem = v7;
  v6->pHal = v13;
  v6->pEmitBuffer = (Scaleform::Render::TextEmitBuffer *)&qp->264;
  v14 = ((__int64 (*)(void))v13->vfptr[62].__vecDelDtor)();
  v6->pBundle = v8;
  v6->pRemainingTextFields = v4;
  v6->ProcessingLayer = 0i64;
  v6->pCache = (Scaleform::Render::MeshCache *)v14;
  *(_WORD *)&v6->LayersPinned = 0;
  v6->PPBuffer.pItem = 0i64;
  Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(v6, 1);
}

// File Line: 519
// RVA: 0x9C62B0
char __fastcall Scaleform::Render::TextPrimitiveBundle::addAndPinBatchLayers(Scaleform::Render::TextPrimitiveBundle *this, Scaleform::Render::TreeCacheText *textCache, Scaleform::Render::TextMeshProvider *tm)
{
  Scaleform::Render::TextMeshProvider *v3; // r12
  Scaleform::Render::TreeCacheText *v4; // rsi
  Scaleform::Render::TextPrimitiveBundle *v5; // r13
  unsigned __int64 v6; // rbp
  __int64 v7; // rcx
  char *v8; // r15
  unsigned __int64 v9; // r8
  int v10; // edx
  signed __int64 v11; // rdi
  char *v12; // rdi
  int v13; // ecx
  bool v14; // zf
  bool v15; // sf
  unsigned __int8 v16; // of
  Scaleform::Render::Renderer2DImpl *v17; // rax
  int v18; // esi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v19; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v20; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v21; // rdi
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rsi
  unsigned __int64 v24; // r8
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v25; // rcx
  _DWORD *v27; // rdi
  Scaleform::Render::MaskPrimitive *v28; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v29; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v30; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v31; // rbx
  __int64 v32; // rcx
  unsigned int v33; // [rsp+20h] [rbp-98h]
  int v34; // [rsp+24h] [rbp-94h]
  __int64 v35; // [rsp+28h] [rbp-90h]
  Scaleform::Render::MatrixPoolImpl::HMatrix viewMat; // [rsp+30h] [rbp-88h]
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v37; // [rsp+38h] [rbp-80h]
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp-78h]
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v39; // [rsp+48h] [rbp-70h]
  __int64 v40; // [rsp+50h] [rbp-68h]
  char *v41; // [rsp+58h] [rbp-60h]
  char *v42; // [rsp+60h] [rbp-58h]
  Scaleform::Render::TreeCacheText *v43; // [rsp+C8h] [rbp+10h]
  unsigned int v44; // [rsp+D0h] [rbp+18h]
  signed __int64 v45; // [rsp+D0h] [rbp+18h]
  int v46; // [rsp+D8h] [rbp+20h]

  v43 = textCache;
  v40 = -2i64;
  v3 = tm;
  v4 = textCache;
  v5 = this;
  v33 = tm->vfptr->GetLayerCount((Scaleform::Render::MeshProvider *)tm);
  v44 = 0;
  v6 = 0i64;
  if ( v33 )
  {
    v7 = 0i64;
    v35 = 0i64;
    while ( 1 )
    {
      v8 = (char *)v3->Layers.Data.Data + v7;
      v9 = v5->Layers.Size;
      if ( v6 < v9 )
      {
        v10 = *(_DWORD *)v8;
        do
        {
          if ( v9 <= 2 )
            v11 = (signed __int64)&v5->Layers.8;
          else
            v11 = (signed __int64)v5->Layers.AD.pData;
          v12 = *(char **)(v11 + 8 * v6);
          v13 = *((_DWORD *)v12 + 24);
          v16 = __OFSUB__(v13, v10);
          v14 = v13 == v10;
          v15 = v13 - v10 < 0;
          if ( v13 >= v10 )
          {
            if ( v13 == v10 )
            {
              if ( *((_QWORD *)v12 + 4) == *((_QWORD *)v8 + 6) )
                goto LABEL_25;
              v16 = __OFSUB__(v13, v10);
              v14 = v13 == v10;
              v15 = v13 - v10 < 0;
            }
            if ( !((unsigned __int8)(v15 ^ v16) | v14) || *((_QWORD *)v12 + 4) > *((_QWORD *)v8 + 6) )
              break;
          }
          ++v6;
        }
        while ( v6 < v9 );
      }
      v46 = 67;
      v12 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                      Scaleform::Memory::pGlobalHeap,
                      v5,
                      128ui64,
                      (Scaleform::AllocInfo *)&v46);
      v41 = v12;
      if ( v12 )
      {
        v17 = v4->pRenderer2D;
        v18 = *(_DWORD *)v8;
        Scaleform::Render::Primitive::Primitive(
          (Scaleform::Render::Primitive *)v12,
          v17->pHal.pObject,
          *((Scaleform::Render::PrimitiveFill **)v8 + 6));
        *(_QWORD *)v12 = &Scaleform::Render::TextLayerPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,67>'};
        *((_QWORD *)v12 + 2) = &Scaleform::Render::TextLayerPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
        *((_DWORD *)v12 + 24) = v18;
        v19 = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)(v12 + 104);
        v39 = v19;
        v37 = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)(v12 + 104);
        v19->pObject = 0i64;
        v19[1].pObject = 0i64;
        v19[2].pObject = 0i64;
        v4 = v43;
      }
      else
      {
        v12 = 0i64;
      }
      if ( !v12 )
        return 0;
      _InterlockedExchangeAdd((volatile signed __int32 *)v12 + 2, 1u);
      v42 = v12;
      v20 = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
              &v5->Layers,
              v6);
      v37 = v20;
      if ( v20 )
      {
        v39 = v20;
        _InterlockedExchangeAdd((volatile signed __int32 *)v12 + 2, 1u);
        v20->pObject = (Scaleform::Render::TextLayerPrimitive *)v12;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)v12 + 2) )
        (**(void (__fastcall ***)(void *, signed __int64))v12)(v12, 1i64);
      if ( !_InterlockedDecrement((volatile signed __int32 *)v12 + 2) )
        (**(void (__fastcall ***)(void *, signed __int64))v12)(v12, 1i64);
LABEL_25:
      if ( Scaleform::Render::Primitive::Insert(
             (Scaleform::Render::Primitive *)v12,
             *((_DWORD *)v12 + 18),
             *((Scaleform::Render::Mesh **)v8 + 2),
             (Scaleform::Render::MatrixPoolImpl::HMatrix *)v8 + 5) )
      {
        break;
      }
LABEL_34:
      ++v3->PinCount;
      ++v44;
      v7 = v35 + 64;
      v35 += 64i64;
      if ( v44 >= v33 )
        goto LABEL_37;
    }
    v21 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)(v12 + 104);
    v22 = v21->Size;
    v23 = v22 + 1;
    if ( v22 + 1 >= v22 )
    {
      if ( v23 <= v21->Policy.Capacity )
        goto LABEL_32;
      v24 = v23 + (v23 >> 2);
    }
    else
    {
      if ( v23 >= v21->Policy.Capacity >> 1 )
        goto LABEL_32;
      v24 = v22 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v21,
      v21,
      v24);
LABEL_32:
    v21->Size = v23;
    v25 = &v21->Data[v23 - 1];
    v4 = v43;
    if ( v25 )
      v25->pObject = (Scaleform::GFx::AS2::Object *)&v43->SorterShapeNode;
    goto LABEL_34;
  }
LABEL_37:
  if ( (LOWORD(v3->Flags) >> 8) & 1 )
  {
    if ( v5->pMaskPrimitive.pObject )
      goto LABEL_55;
    v34 = 67;
    v27 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                      Scaleform::Memory::pGlobalHeap,
                      v5,
                      48ui64,
                      (Scaleform::AllocInfo *)&v34);
    if ( v27 )
    {
      *(_QWORD *)v27 = &Scaleform::RefCountImplCore::`vftable';
      v27[2] = 1;
      *(_QWORD *)v27 = &Scaleform::RefCountImpl::`vftable';
      *(_QWORD *)v27 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable';
      *(_QWORD *)v27 = &Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::`vftable';
      *((_QWORD *)v27 + 2) = &Scaleform::Render::RenderQueueItem::Interface::`vftable';
      *(_QWORD *)v27 = &Scaleform::Render::MaskPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>'};
      *((_QWORD *)v27 + 2) = &Scaleform::Render::MaskPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
      v45 = (signed __int64)(v27 + 6);
      v37 = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)(v27 + 6);
      *(_OWORD *)v45 = 0ui64;
      *(_QWORD *)(v45 + 16) = 0i64;
    }
    else
    {
      v27 = 0i64;
    }
    v28 = v5->pMaskPrimitive.pObject;
    if ( v28 && !_InterlockedDecrement(&v28->RefCount) && v28 )
      v28->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, 1u);
    v5->pMaskPrimitive.pObject = (Scaleform::Render::MaskPrimitive *)v27;
    if ( v27 )
    {
LABEL_55:
      v29 = v4->M.pHandle;
      viewMat.pHandle = v29;
      if ( v29 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        ++v29->pHeader->RefCount;
      v30 = Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
              v3,
              &result,
              (Scaleform::Render::MatrixPoolImpl::HMatrix)&viewMat);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->pMaskPrimitive.pObject->MaskAreas.Data,
        v5->pMaskPrimitive.pObject->MaskAreas.Data.Size,
        v30);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        v31 = result.pHandle->pHeader;
        v14 = result.pHandle->pHeader->RefCount == 1;
        --v31->RefCount;
        if ( v14 )
        {
          v32 = v31->DataPageOffset;
          *(_WORD *)((char *)&v31[1].RefCount + v32 + 2) += 16 * (unsigned __int8)v31->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v31[1].pHandle + v32))[5].pHeader += (unsigned __int8)v31->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v31->pHandle);
          v31->pHandle = 0i64;
        }
      }
    }
  }
  return 1;
}

// File Line: 594
// RVA: 0x9F01F0
void __fastcall Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(Scaleform::Render::TextPrimitiveBundle *this, Scaleform::Render::BundleEntry *e)
{
  Scaleform::Render::BundleEntry *v2; // rbp
  Scaleform::Render::TextPrimitiveBundle *v3; // r14
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rax
  Scaleform::Render::TreeCacheNode *v8; // rcx
  signed __int64 v9; // rcx
  Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> *v10; // rdi
  unsigned __int64 v11; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v12; // rdx
  __int64 v13; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v14; // rsi
  Scaleform::Render::MatrixPoolImpl::EntryHandle v15; // rsi
  bool v16; // zf
  __int64 v17; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v18; // rbx
  __int64 v19; // rcx
  Scaleform::Render::MaskPrimitive *v20; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+50h] [rbp+8h]

  v2 = e;
  v3 = this;
  v4 = 0i64;
  v5 = this->Layers.Size;
  if ( v5 )
  {
    do
    {
      if ( v5 <= 2 )
        v6 = (signed __int64)&v3->Layers.8;
      else
        v6 = (signed __int64)v3->Layers.AD.pData;
      Scaleform::Render::TextLayerPrimitive::RemoveEntry(*(Scaleform::Render::TextLayerPrimitive **)(v6 + 8 * v4), v2);
      if ( v3->Layers.Size <= 2 )
        v7 = (signed __int64)&v3->Layers.8;
      else
        v7 = (signed __int64)v3->Layers.AD.pData;
      if ( !*(_DWORD *)(*(_QWORD *)(v7 + 8 * v4) + 72i64) )
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::RemoveAt(
          &v3->Layers,
          v4--);
      ++v4;
      v5 = v3->Layers.Size;
    }
    while ( v4 < v5 );
  }
  if ( v3->pMaskPrimitive.pObject )
  {
    v8 = v2->pSourceNode;
    if ( (LODWORD(v8[2].pNext) >> 5) & 1 )
    {
      v9 = (signed __int64)&v8[1].SortParentBounds;
      if ( v9 )
      {
        if ( (*(_WORD *)(v9 + 32) >> 8) & 1 )
        {
          Scaleform::Render::TextMeshProvider::GetMaskClearBounds((Scaleform::Render::TextMeshProvider *)v9, &result);
          v10 = (Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> *)v3->pMaskPrimitive.pObject;
          v11 = v10[1].Size;
          v12 = v10[1].Data;
          v13 = 0i64;
          if ( v11 )
          {
            while ( v12[v13].pHandle != result.pHandle )
            {
              if ( ++v13 >= v11 )
                goto LABEL_25;
            }
            if ( v11 == 1 )
            {
              Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                v10 + 1,
                0i64);
            }
            else
            {
              v14 = v12[v13].pHandle;
              if ( v14 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
              {
                v15.pHeader = v14->pHeader;
                v16 = v15.pHeader->RefCount-- == 1;
                if ( v16 )
                {
                  v17 = v15.pHeader->DataPageOffset;
                  *(_WORD *)((char *)&v15.pHeader[1].RefCount + v17 + 2) += 16 * (unsigned __int8)v15.pHeader->UnitSize;
                  (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v15.pHeader[1].pHandle + v17))[5].pHeader += (unsigned __int8)v15.pHeader->UnitSize;
                  Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v15.pHeader->pHandle);
                  v15.pHeader->pHandle = 0i64;
                }
              }
              memmove(&v10[1].Data[v13], &v10[1].Data[v13 + 1], 8 * (v10[1].Size - v13) - 8);
              --v10[1].Size;
            }
          }
LABEL_25:
          if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
          {
            v18 = result.pHandle->pHeader;
            v16 = result.pHandle->pHeader->RefCount == 1;
            --v18->RefCount;
            if ( v16 )
            {
              v19 = v18->DataPageOffset;
              *(_WORD *)((char *)&v18[1].RefCount + v19 + 2) += 16 * (unsigned __int8)v18->UnitSize;
              (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v18[1].pHandle + v19))[5].pHeader += (unsigned __int8)v18->UnitSize;
              Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v18->pHandle);
              v18->pHandle = 0i64;
            }
          }
        }
      }
    }
    v20 = v3->pMaskPrimitive.pObject;
    if ( !v20->MaskAreas.Data.Size )
    {
      if ( v20 && !_InterlockedDecrement(&v20->RefCount) )
      {
        if ( v20 )
          v20->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v20->vfptr, 1u);
      }
      v3->pMaskPrimitive.pObject = 0i64;
    }
  }
}

// File Line: 634
// RVA: 0x9D5B30
void __fastcall Scaleform::Render::TextPrimitiveBundle::clearBatchLayers(Scaleform::Render::TextPrimitiveBundle *this)
{
  Scaleform::Render::TextPrimitiveBundle *v1; // rbx
  unsigned __int64 v2; // r8
  Scaleform::Render::TreeCacheNode *v3; // rcx
  Scaleform::Render::MaskPrimitive *v4; // rcx

  v1 = this;
  v2 = 0i64;
  if ( this->Entries.Data.Size )
  {
    do
    {
      v3 = v1->Entries.Data.Data[v2]->pSourceNode;
      if ( (LODWORD(v3[2].pNext) >> 5) & 1 && v3 != (Scaleform::Render::TreeCacheNode *)-208i64 )
      {
        v3[3].pNext = 0i64;
        v3[3].pRoot = 0i64;
      }
      ++v2;
    }
    while ( v2 < v1->Entries.Data.Size );
  }
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::Clear(&v1->Layers);
  v4 = v1->pMaskPrimitive.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  v1->pMaskPrimitive.pObject = 0i64;
}

// File Line: 668
// RVA: 0x9BD2A0
bool __fastcall Scaleform::Render::SKI_TextPrimitive::UpdateBundleEntry(Scaleform::Render::SKI_TextPrimitive *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::BundleEntry *v4; // rsi
  Scaleform::Render::TextPrimitiveBundle *v5; // rax
  Scaleform::Render::Bundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rbx
  bool v8; // zf
  Scaleform::Render::Bundle *v10; // [rsp+50h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v11; // [rsp+58h] [rbp+20h]

  v11 = tr;
  v4 = p;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v10) = 67;
    v5 = (Scaleform::Render::TextPrimitiveBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     tr,
                                                     96i64,
                                                     &v10,
                                                     -2i64);
    if ( v5 )
    {
      Scaleform::Render::TextPrimitiveBundle::TextPrimitiveBundle(v5);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    v10 = v7;
    Scaleform::Render::BundleEntry::SetBundle(v4, v7, 0i64);
    if ( v7 )
    {
      v8 = v7->RefCount-- == 1;
      if ( v8 )
        v7->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, 1u);
    }
  }
  return v4->pBundle.pObject != 0i64;
}

// File Line: 679
// RVA: 0x96F380
void __fastcall Scaleform::Render::SKI_TextPrimitive::DrawBundleEntry(Scaleform::Render::SKI_TextPrimitive *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::Bundle *v4; // rax
  Scaleform::Render::HAL *v5; // rcx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  Scaleform::Render::Bundle *v7; // [rsp+20h] [rbp-18h]
  __int64 v8; // [rsp+28h] [rbp-10h]

  v4 = p->pBundle.pObject;
  if ( v4 )
  {
    v5 = r->pHal.pObject;
    v7 = v4 + 1;
    v6 = v5->vfptr;
    v8 = 0i64;
    v6[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v7);
  }
}

// File Line: 690
// RVA: 0x159C8F0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_TextPrimitive::Instance__()
{
  Scaleform::Render::SKI_TextPrimitive::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_TextPrimitive::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_TextPrimitive::Instance__);
}

// File Line: 691
// RVA: 0x159C5E0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_TextPrimitive::Instance3D__()
{
  Scaleform::Render::SKI_TextPrimitive::Instance3D.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_TextPrimitive::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_TextPrimitive::Instance3D__);
}

