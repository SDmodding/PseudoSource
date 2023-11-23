// File Line: 179
// RVA: 0x9CA1C0
void __fastcall Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(
        Scaleform::Render::TextPrepareBuffer *this,
        bool startFlag)
{
  Scaleform::Render::TreeCacheText *pRemainingTextFields; // rbp
  Scaleform::Render::TreeCacheText *pNextNoBatch; // rsi
  Scaleform::Render::TextPrimitiveBundle *pBundle; // rbx
  unsigned __int64 v7; // r10
  unsigned __int64 Size; // rax
  _QWORD *p_pData; // r9
  __int64 v10; // r9
  unsigned __int64 i; // rdx
  __int64 v12; // r8
  __int64 v13; // rax
  Scaleform::Render::TreeCacheText *v14; // rcx
  Scaleform::Render::TextMeshProvider *MeshProvider; // rbx
  unsigned int Flags; // eax
  Scaleform::Render::GlyphCache *pCache; // rcx
  Scaleform::Render::TreeCacheText *v18; // rcx

  pRemainingTextFields = this->pRemainingTextFields;
  if ( pRemainingTextFields )
  {
    do
    {
      pNextNoBatch = this->pRemainingTextFields->pNextNoBatch;
      if ( !this->LayersPinned )
      {
        pBundle = this->pBundle;
        v7 = 0i64;
        Size = pBundle->Layers.Size;
        if ( Size )
        {
          do
          {
            if ( Size <= 2 )
              p_pData = &pBundle->Layers.AD.pData;
            else
              p_pData = &pBundle->Layers.AD.pData->pObject;
            v10 = p_pData[v7];
            for ( i = 0i64; i < *(_QWORD *)(v10 + 112); ++i )
            {
              v12 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v10 + 104) + 8 * i) + 56i64);
              v13 = v12 + 208;
              if ( (*(_DWORD *)(v12 + 240) & 0x20) == 0 )
                v13 = 0i64;
              ++*(_QWORD *)(v13 + 136);
            }
            Size = pBundle->Layers.Size;
            ++v7;
          }
          while ( v7 < Size );
        }
        this->LayersPinned = 1;
      }
      v14 = this->pRemainingTextFields;
      if ( (v14->TMProvider.Flags & 0x20) == 0
        || (MeshProvider = &v14->TMProvider, v14 == (Scaleform::Render::TreeCacheText *)-208i64) )
      {
        MeshProvider = Scaleform::Render::TreeCacheText::CreateMeshProvider(v14);
        if ( !MeshProvider )
          break;
      }
      Flags = MeshProvider->Flags;
      if ( (Flags & 6) == 0 )
      {
        pCache = MeshProvider->pCache;
        MeshProvider->Flags = Flags | 2;
        MeshProvider->pPrev = pCache->TextInUse.Root.pPrev;
        MeshProvider->pNext = (Scaleform::Render::TextMeshProvider *)&pCache->RectsToUpdate.Capacity;
        pCache->TextInUse.Root.pPrev->pNext = MeshProvider;
        pCache->TextInUse.Root.pPrev = MeshProvider;
      }
      if ( Scaleform::Render::TextPrimitiveBundle::addAndPinBatchLayers(
             this->pBundle,
             this->pRemainingTextFields,
             MeshProvider) )
      {
        v18 = this->pRemainingTextFields;
        MeshProvider->pBundle = this->pBundle;
        MeshProvider->pBundleEntry = &v18->SorterShapeNode;
      }
      this->pRemainingTextFields->pNextNoBatch = 0i64;
      this->pRemainingTextFields = pNextNoBatch;
    }
    while ( pNextNoBatch );
  }
  if ( !startFlag && pRemainingTextFields == this->pRemainingTextFields )
    this->pRemainingTextFields = 0i64;
}

// File Line: 221
// RVA: 0x9A00D0
__int64 __fastcall Scaleform::Render::TextPrepareBuffer::ProcessPrimitive(
        Scaleform::Render::TextPrepareBuffer *this,
        bool waitForCache)
{
  Scaleform::Render::TextPrimitiveBundle *pBundle; // rax
  _QWORD *p_pData; // rcx
  Scaleform::Render::Primitive *v6; // rdx

  if ( this->LayersFinished )
  {
    this->PPBuffer.pItem = 0i64;
    Scaleform::Render::TextPrimitiveBundle::clearBatchLayers(this->pBundle);
    Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(this, 0);
    this->LayersFinished = 0;
    this->ProcessingLayer = 0i64;
  }
  if ( this->ProcessingLayer < this->pBundle->Layers.Size )
  {
    do
    {
      pBundle = this->pBundle;
      if ( pBundle->Layers.Size <= 2 )
        p_pData = &pBundle->Layers.AD.pData;
      else
        p_pData = &pBundle->Layers.AD.pData->pObject;
      v6 = (Scaleform::Render::Primitive *)p_pData[this->ProcessingLayer];
      if ( v6 != this->PPBuffer.pItem )
        Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
          &this->PPBuffer,
          v6,
          v6,
          &this->pEmitBuffer->PEBuffer,
          this->pHal,
          this->pCache);
      if ( (unsigned int)Scaleform::Render::PrimitivePrepareBuffer::ProcessPrimitive(&this->PPBuffer, waitForCache) == 1 )
        return 1i64;
    }
    while ( ++this->ProcessingLayer < this->pBundle->Layers.Size );
  }
  if ( this->LayersPinned )
  {
    Scaleform::Render::TextPrimitiveBundle::unpinLayerBatches(this->pBundle);
    this->LayersPinned = 0;
  }
  if ( this->pRemainingTextFields )
  {
    this->LayersFinished = 1;
    return 1i64;
  }
  return 0i64;
}

// File Line: 267
// RVA: 0x96FBD0
void __fastcall Scaleform::Render::TextEmitBuffer::EmitPrimitive(
        Scaleform::Render::TextEmitBuffer *this,
        Scaleform::Render::TextPrepareBuffer *prepareBuffer,
        Scaleform::Render::HAL *hal)
{
  Scaleform::Render::TextPrimitiveBundle *pBundle; // rax
  char v7; // r15
  unsigned __int64 ProcessingLayer; // rbp
  Scaleform::Render::TextPrimitiveBundle *v9; // rcx
  _QWORD *p_pData; // rdi
  __int64 v11; // rdi
  int v12; // eax
  Scaleform::Render::PrimitiveBatch *pDraw; // r8
  Scaleform::Render::PrimitiveBatch *pPrepare; // r9
  unsigned int v15; // ecx
  __int64 *i; // rax

  pBundle = this->pBundle;
  v7 = 1;
  if ( this->pItem == prepareBuffer->pItem )
  {
    ProcessingLayer = prepareBuffer->ProcessingLayer;
    if ( ProcessingLayer < pBundle->Layers.Size )
    {
      ++ProcessingLayer;
      v7 = 0;
    }
  }
  else
  {
    ProcessingLayer = pBundle->Layers.Size;
  }
  for ( ; this->EmitLayer < ProcessingLayer; ++this->EmitLayer )
  {
    v9 = this->pBundle;
    if ( v9->Layers.Size <= 2 )
      p_pData = &v9->Layers.AD.pData;
    else
      p_pData = &v9->Layers.AD.pData->pObject;
    v11 = p_pData[this->EmitLayer];
    v12 = *(_DWORD *)(v11 + 96);
    if ( v12 >= 11 )
    {
      if ( v12 == 11 )
      {
        if ( this->MaskStatus == Mask_NotInUse && v9->pMaskPrimitive.pObject )
        {
          ((void (__fastcall *)(Scaleform::Render::HAL *))hal->vfptr[36].__vecDelDtor)(hal);
          this->MaskStatus = Mask_Submitting;
        }
      }
      else if ( this->MaskStatus == Mask_Submitting )
      {
        ((void (__fastcall *)(Scaleform::Render::HAL *))hal->vfptr[37].__vecDelDtor)(hal);
        this->MaskStatus = Mask_InUse;
      }
    }
    if ( (void *)v11 == this->PEBuffer.pItem )
    {
      pDraw = this->PEBuffer.pDraw;
    }
    else
    {
      pDraw = *(Scaleform::Render::PrimitiveBatch **)(v11 + 48);
      this->PEBuffer.pItem = (void *)v11;
      this->PEBuffer.pDraw = pDraw;
    }
    if ( (void *)v11 == prepareBuffer->PPBuffer.pItem )
    {
      pPrepare = prepareBuffer->PPBuffer.pPrepare;
      this->PEBuffer.pDraw = pPrepare;
    }
    else
    {
      pPrepare = *(Scaleform::Render::PrimitiveBatch **)(*(_QWORD *)(v11 + 40) + 8i64);
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
    ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, Scaleform::Render::PrimitiveBatch *, Scaleform::Render::PrimitiveBatch *))hal->vfptr[34].__vecDelDtor)(
      hal,
      v11,
      pDraw,
      pPrepare);
  }
  if ( v7 )
  {
    if ( this->MaskStatus )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))hal->vfptr[38].__vecDelDtor)(hal);
      this->MaskStatus = Mask_NotInUse;
    }
    this->pItem = 0i64;
  }
  else
  {
    --this->EmitLayer;
  }
}

// File Line: 348
// RVA: 0x9A9B50
bool __fastcall Scaleform::Render::TextLayerPrimitive::RemoveEntry(
        Scaleform::Render::TextLayerPrimitive *this,
        Scaleform::Render::BundleEntry *e)
{
  unsigned __int64 i; // rdi
  Scaleform::Render::BundleEntry **Data; // rdx
  unsigned __int64 Size; // r8

  for ( i = 0i64; i < this->Entries.Data.Size; ++i )
  {
    Data = this->Entries.Data.Data;
    if ( Data[i] == e )
    {
      Size = this->Entries.Data.Size;
      if ( Size == 1 )
      {
        if ( (this->Entries.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        {
          if ( Data )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            this->Entries.Data.Data = 0i64;
          }
          this->Entries.Data.Policy.Capacity = 0i64;
        }
        this->Entries.Data.Size = 0i64;
      }
      else
      {
        memmove(&Data[i], &Data[i + 1], 8 * (Size - i) - 8);
        --this->Entries.Data.Size;
      }
      Scaleform::Render::Primitive::Remove(this, i--, 1u);
    }
  }
  return 0;
}

// File Line: 399
// RVA: 0x946250
void __fastcall Scaleform::Render::TextPrimitiveBundle::TextPrimitiveBundle(
        Scaleform::Render::TextPrimitiveBundle *this)
{
  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable{for `Scaleform::Render::Bundle};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->Layers.Size = 0i64;
  this->pMaskPrimitive.pObject = 0i64;
}

// File Line: 402
// RVA: 0x94D380
void __fastcall Scaleform::Render::TextPrimitiveBundle::~TextPrimitiveBundle(
        Scaleform::Render::TextPrimitiveBundle *this)
{
  Scaleform::Render::MaskPrimitive *pObject; // rcx

  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable{for `Scaleform::Render::Bundle};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  pObject = this->pMaskPrimitive.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::~ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>(&this->Layers);
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 406
// RVA: 0x995420
// attributes: thunk
void __fastcall Scaleform::Render::TextPrimitiveBundle::InsertEntry(
        Scaleform::Render::TextPrimitiveBundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
}

// File Line: 417
// RVA: 0x9A99A0
void __fastcall Scaleform::Render::TextPrimitiveBundle::RemoveEntries(
        Scaleform::Render::TextPrimitiveBundle *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 i; // rbx
  Scaleform::Render::TreeCacheNode *pSourceNode; // rdx
  Scaleform::Render::Rect<float> *p_SortParentBounds; // rdi

  v3 = index + count;
  for ( i = index; i < v3; ++i )
  {
    pSourceNode = this->Entries.Data.Data[i]->pSourceNode;
    if ( ((__int64)pSourceNode[2].pNext & 0x20) != 0 )
    {
      p_SortParentBounds = &pSourceNode[1].SortParentBounds;
      if ( pSourceNode != (Scaleform::Render::TreeCacheNode *)-208i64 )
      {
        if ( pSourceNode[3].pNext )
        {
          Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(
            this,
            (Scaleform::Render::BundleEntry *)&pSourceNode[1]);
          *(_QWORD *)&p_SortParentBounds[9].x1 = 0i64;
          *(_QWORD *)&p_SortParentBounds[9].x2 = 0i64;
        }
      }
    }
  }
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}

// File Line: 434
// RVA: 0x9BF320
void __fastcall Scaleform::Render::TextPrimitiveBundle::UpdateMesh(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::BundleEntry *entry)
{
  unsigned __int64 IndexHint; // r9
  unsigned __int64 Size; // r8
  __int64 v5; // rax
  Scaleform::Render::BundleEntry **i; // rcx
  Scaleform::Render::TreeCacheNode *pSourceNode; // rdx
  Scaleform::Render::Rect<float> *p_SortParentBounds; // rbx

  IndexHint = entry->IndexHint;
  Size = this->Entries.Data.Size;
  if ( IndexHint >= Size || this->Entries.Data.Data[IndexHint] != entry )
  {
    v5 = 0i64;
    if ( !Size )
      return;
    for ( i = this->Entries.Data.Data; *i != entry; ++i )
    {
      if ( ++v5 >= Size )
        return;
    }
    entry->IndexHint = v5;
  }
  pSourceNode = entry->pSourceNode;
  if ( ((__int64)pSourceNode[2].pNext & 0x20) != 0 )
  {
    p_SortParentBounds = &pSourceNode[1].SortParentBounds;
    if ( pSourceNode != (Scaleform::Render::TreeCacheNode *)-208i64 )
    {
      if ( pSourceNode[3].pNext )
      {
        Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(
          this,
          (Scaleform::Render::BundleEntry *)&pSourceNode[1]);
        *(_QWORD *)&p_SortParentBounds[9].x1 = 0i64;
        *(_QWORD *)&p_SortParentBounds[9].x2 = 0i64;
      }
    }
  }
}

// File Line: 453
// RVA: 0x99F830
Scaleform::Render::RenderQueueItem::QIPrepareResult __fastcall Scaleform::Render::TextPrimitiveBundle::Prepare(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp,
        bool waitForCache)
{
  $45076D539F6ADDA0F9E9E30F948E0703 *v6; // rbx

  if ( qp->QueuePrepareFilter )
    return 0;
  v6 = &qp->72;
  if ( item != qp->PrepareItemBuffer.pItem )
    Scaleform::Render::TextPrimitiveBundle::startPrimitive(
      (Scaleform::Render::TextPrimitiveBundle *)((char *)this - 56),
      item,
      (Scaleform::Render::TextPrepareBuffer *)&qp->72,
      qp);
  return Scaleform::Render::TextPrepareBuffer::ProcessPrimitive(
           (Scaleform::Render::TextPrepareBuffer *)v6,
           waitForCache);
}

// File Line: 464
// RVA: 0x96FF60
void __fastcall Scaleform::Render::TextPrimitiveBundle::EmitToHAL(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::TextEmitBuffer *v4; // rcx

  if ( qp->QueueEmitFilter == QPF_All )
  {
    v4 = (Scaleform::Render::TextEmitBuffer *)&qp->264;
    if ( item != qp->EmitItemBuffer.pItem )
    {
      v4->pItem = item;
      *(_OWORD *)&qp->EmitItemBufferBytes[8] = (unsigned __int64)&this[-1].pTop;
      *(_DWORD *)&qp->EmitItemBufferBytes[24] = 0;
      *(_QWORD *)&qp->EmitItemBufferBytes[32] = 0i64;
    }
    Scaleform::Render::TextEmitBuffer::EmitPrimitive(v4, (Scaleform::Render::TextPrepareBuffer *)&qp->72, qp->pHAL);
  }
}

// File Line: 481
// RVA: 0x9F38F0
void __fastcall Scaleform::Render::TextPrimitiveBundle::startPrimitive(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::TextPrepareBuffer *prepareBuffer,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::TreeCacheText *v4; // rsi
  unsigned __int64 i; // r10
  Scaleform::Render::TreeCacheNode *pSourceNode; // rdx
  Scaleform::Render::Rect<float> *p_SortParentBounds; // rax
  int pNext; // ecx
  Scaleform::Render::TreeCacheNode *pPrev; // rdx
  Scaleform::Render::HAL *pHAL; // rcx
  Scaleform::Render::MeshCache *v14; // rax

  v4 = 0i64;
  for ( i = 0i64; i < this->Entries.Data.Size; ++i )
  {
    pSourceNode = this->Entries.Data.Data[i]->pSourceNode;
    if ( ((__int64)pSourceNode[2].pNext & 0x20) != 0
      && (p_SortParentBounds = &pSourceNode[1].SortParentBounds,
          pSourceNode != (Scaleform::Render::TreeCacheNode *)-208i64)
      && (Scaleform::Render::TextPrimitiveBundle *)pSourceNode[3].pNext == this )
    {
      pNext = (int)pSourceNode[2].pNext;
      if ( (pNext & 6) == 0 )
      {
        pPrev = pSourceNode[2].pPrev;
        LODWORD(p_SortParentBounds[2].x1) = pNext | 2;
        *(_QWORD *)&p_SortParentBounds->x2 = pPrev[41].pNextUpdate;
        *(_QWORD *)&p_SortParentBounds[1].x1 = (char *)pPrev + 4664;
        pPrev[41].pNextUpdate->pNext = (Scaleform::Render::TreeCacheNode *)p_SortParentBounds;
        pPrev[41].pNextUpdate = (Scaleform::Render::TreeCacheNode *)p_SortParentBounds;
      }
    }
    else
    {
      pSourceNode[1].pNextUpdate = v4;
      v4 = (Scaleform::Render::TreeCacheText *)pSourceNode;
    }
  }
  pHAL = qp->pHAL;
  prepareBuffer->pItem = item;
  prepareBuffer->pHal = pHAL;
  prepareBuffer->pEmitBuffer = (Scaleform::Render::TextEmitBuffer *)&qp->264;
  v14 = (Scaleform::Render::MeshCache *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))pHAL->vfptr[62].__vecDelDtor)(pHAL);
  prepareBuffer->pBundle = this;
  prepareBuffer->pRemainingTextFields = v4;
  prepareBuffer->ProcessingLayer = 0i64;
  prepareBuffer->pCache = v14;
  *(_WORD *)&prepareBuffer->LayersPinned = 0;
  prepareBuffer->PPBuffer.pItem = 0i64;
  Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(prepareBuffer, 1);
}

// File Line: 519
// RVA: 0x9C62B0
char __fastcall Scaleform::Render::TextPrimitiveBundle::addAndPinBatchLayers(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::TreeCacheText *textCache,
        Scaleform::Render::TextMeshProvider *tm)
{
  Scaleform::Render::TreeCacheText *v4; // rsi
  unsigned __int64 v6; // rbp
  __int64 v7; // rcx
  char *v8; // r15
  unsigned __int64 Size; // r8
  int v10; // edx
  _QWORD *p_pData; // rdi
  char *v12; // rdi
  int v13; // ecx
  bool v14; // cc
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rax
  int v16; // esi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *inserted; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rsi
  unsigned __int64 v21; // r8
  _QWORD *p_pObject; // rcx
  Scaleform::Render::MaskPrimitive *v24; // rdi
  Scaleform::Render::MaskPrimitive *pObject; // rcx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::MatrixPoolImpl::HMatrix *updated; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  unsigned int v31; // [rsp+20h] [rbp-98h]
  int v32; // [rsp+24h] [rbp-94h] BYREF
  __int64 v33; // [rsp+28h] [rbp-90h]
  Scaleform::Render::MatrixPoolImpl::HMatrix viewMat; // [rsp+30h] [rbp-88h] BYREF
  void *p_MaskAreas; // [rsp+38h] [rbp-80h]
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp-78h] BYREF
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v37; // [rsp+48h] [rbp-70h]
  __int64 v38; // [rsp+50h] [rbp-68h]
  char *v39; // [rsp+58h] [rbp-60h]
  char *v40; // [rsp+60h] [rbp-58h]
  unsigned int v42; // [rsp+D0h] [rbp+18h]
  int v43; // [rsp+D8h] [rbp+20h] BYREF

  v38 = -2i64;
  v4 = textCache;
  v31 = tm->vfptr->GetLayerCount(tm);
  v42 = 0;
  v6 = 0i64;
  if ( v31 )
  {
    v7 = 0i64;
    v33 = 0i64;
    while ( 1 )
    {
      v8 = (char *)tm->Layers.Data.Data + v7;
      Size = this->Layers.Size;
      if ( v6 < Size )
      {
        v10 = *(_DWORD *)v8;
        do
        {
          if ( Size <= 2 )
            p_pData = &this->Layers.AD.pData;
          else
            p_pData = &this->Layers.AD.pData->pObject;
          v12 = (char *)p_pData[v6];
          v13 = *((_DWORD *)v12 + 24);
          v14 = v13 <= v10;
          if ( v13 >= v10 )
          {
            if ( v13 == v10 )
            {
              if ( *((_QWORD *)v12 + 4) == *((_QWORD *)v8 + 6) )
                goto LABEL_25;
              v14 = v13 <= v10;
            }
            if ( !v14 || *((_QWORD *)v12 + 4) > *((_QWORD *)v8 + 6) )
              break;
          }
          ++v6;
        }
        while ( v6 < Size );
      }
      v43 = 67;
      v12 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                      Scaleform::Memory::pGlobalHeap,
                      this,
                      128i64,
                      &v43);
      v39 = v12;
      if ( v12 )
      {
        pRenderer2D = v4->pRenderer2D;
        v16 = *(_DWORD *)v8;
        Scaleform::Render::Primitive::Primitive(
          (Scaleform::Render::Primitive *)v12,
          pRenderer2D->pHal.pObject,
          *((Scaleform::Render::PrimitiveFill **)v8 + 6));
        *(_QWORD *)v12 = &Scaleform::Render::TextLayerPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,67>};
        *((_QWORD *)v12 + 2) = &Scaleform::Render::TextLayerPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
        *((_DWORD *)v12 + 24) = v16;
        v37 = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)(v12 + 104);
        p_MaskAreas = v12 + 104;
        *((_QWORD *)v12 + 13) = 0i64;
        *((_QWORD *)v12 + 14) = 0i64;
        *((_QWORD *)v12 + 15) = 0i64;
        v4 = textCache;
      }
      else
      {
        v12 = 0i64;
      }
      if ( !v12 )
        return 0;
      _InterlockedExchangeAdd((volatile signed __int32 *)v12 + 2, 1u);
      v40 = v12;
      inserted = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
                   &this->Layers,
                   v6);
      p_MaskAreas = inserted;
      if ( inserted )
      {
        v37 = inserted;
        _InterlockedExchangeAdd((volatile signed __int32 *)v12 + 2, 1u);
        inserted->pObject = (Scaleform::Render::TextLayerPrimitive *)v12;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)v12 + 2) )
        (**(void (__fastcall ***)(void *, __int64))v12)(v12, 1i64);
      if ( !_InterlockedDecrement((volatile signed __int32 *)v12 + 2) )
        (**(void (__fastcall ***)(void *, __int64))v12)(v12, 1i64);
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
      ++tm->PinCount;
      ++v42;
      v7 = v33 + 64;
      v33 += 64i64;
      if ( v42 >= v31 )
        goto LABEL_37;
    }
    v18 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)(v12 + 104);
    v19 = v18->Size;
    v20 = v19 + 1;
    if ( v19 + 1 >= v19 )
    {
      if ( v20 <= v18->Policy.Capacity )
        goto LABEL_32;
      v21 = v20 + (v20 >> 2);
    }
    else
    {
      if ( v20 >= v18->Policy.Capacity >> 1 )
        goto LABEL_32;
      v21 = v19 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v18,
      v18,
      v21);
LABEL_32:
    v18->Size = v20;
    p_pObject = &v18->Data[v20 - 1].pObject;
    v4 = textCache;
    if ( p_pObject )
      *p_pObject = &textCache->SorterShapeNode;
    goto LABEL_34;
  }
LABEL_37:
  if ( (tm->Flags & 0x100) != 0 )
  {
    if ( this->pMaskPrimitive.pObject )
      goto LABEL_46;
    v32 = 67;
    v24 = (Scaleform::Render::MaskPrimitive *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                48i64,
                                                &v32);
    if ( v24 )
    {
      v24->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
      v24->RefCount = 1;
      v24->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
      v24->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
      v24->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::`vftable;
      v24->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
      v24->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MaskPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>};
      v24->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::MaskPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
      p_MaskAreas = &v24->MaskAreas;
      v24->MaskAreas.Data.Data = 0i64;
      v24->MaskAreas.Data.Size = 0i64;
      v24->MaskAreas.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v24 = 0i64;
    }
    pObject = this->pMaskPrimitive.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        pObject,
        1u);
    this->pMaskPrimitive.pObject = v24;
    if ( v24 )
    {
LABEL_46:
      pHandle = v4->M.pHandle;
      viewMat.pHandle = pHandle;
      if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        ++pHandle->pHeader->RefCount;
      updated = Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
                  tm,
                  &result,
                  (Scaleform::Render::MatrixPoolImpl::HMatrix)&viewMat);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->pMaskPrimitive.pObject->MaskAreas,
        this->pMaskPrimitive.pObject->MaskAreas.Data.Size,
        updated);
      if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      {
        pHeader = result.pHandle->pHeader;
        if ( result.pHandle->pHeader->RefCount-- == 1 )
        {
          DataPageOffset = pHeader->DataPageOffset;
          *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
          (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
          Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
          pHeader->pHandle = 0i64;
        }
      }
    }
  }
  return 1;
}

// File Line: 594
// RVA: 0x9F01F0
void __fastcall Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::BundleEntry *e)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 Size; // rax
  Scaleform::Render::TextLayerPrimitive **p_pObject; // rcx
  _QWORD *p_pData; // rax
  Scaleform::Render::TreeCacheNode *pSourceNode; // rcx
  Scaleform::Render::TextMeshProvider *p_SortParentBounds; // rcx
  Scaleform::Render::MaskPrimitive *pObject; // rdi
  unsigned __int64 v11; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix *Data; // rdx
  __int64 v13; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rsi
  Scaleform::Render::MatrixPoolImpl::EntryHandle v15; // rsi
  bool v16; // zf
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 v19; // rcx
  Scaleform::Render::MaskPrimitive *v20; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+50h] [rbp+8h] BYREF

  v4 = 0i64;
  Size = this->Layers.Size;
  if ( Size )
  {
    do
    {
      if ( Size <= 2 )
        p_pObject = (Scaleform::Render::TextLayerPrimitive **)&this->Layers.8;
      else
        p_pObject = &this->Layers.AD.pData->pObject;
      Scaleform::Render::TextLayerPrimitive::RemoveEntry(p_pObject[v4], e);
      if ( this->Layers.Size <= 2 )
        p_pData = &this->Layers.AD.pData;
      else
        p_pData = &this->Layers.AD.pData->pObject;
      if ( !*(_DWORD *)(p_pData[v4] + 72i64) )
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::RemoveAt(
          &this->Layers,
          v4--);
      ++v4;
      Size = this->Layers.Size;
    }
    while ( v4 < Size );
  }
  if ( this->pMaskPrimitive.pObject )
  {
    pSourceNode = e->pSourceNode;
    if ( ((__int64)pSourceNode[2].pNext & 0x20) != 0 )
    {
      p_SortParentBounds = (Scaleform::Render::TextMeshProvider *)&pSourceNode[1].SortParentBounds;
      if ( p_SortParentBounds )
      {
        if ( (p_SortParentBounds->Flags & 0x100) != 0 )
        {
          Scaleform::Render::TextMeshProvider::GetMaskClearBounds(p_SortParentBounds, &result);
          pObject = this->pMaskPrimitive.pObject;
          v11 = pObject->MaskAreas.Data.Size;
          Data = pObject->MaskAreas.Data.Data;
          v13 = 0i64;
          if ( v11 )
          {
            while ( Data[v13].pHandle != result.pHandle )
            {
              if ( ++v13 >= v11 )
                goto LABEL_25;
            }
            if ( v11 == 1 )
            {
              Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>::Resize(
                &pObject->MaskAreas.Data,
                0i64);
            }
            else
            {
              pHandle = Data[v13].pHandle;
              if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
              {
                v15.pHeader = pHandle->pHeader;
                v16 = v15.pHeader->RefCount-- == 1;
                if ( v16 )
                {
                  DataPageOffset = v15.pHeader->DataPageOffset;
                  *(_WORD *)((char *)&v15.pHeader[1].RefCount + DataPageOffset + 2) += 16
                                                                                     * (unsigned __int8)v15.pHeader->UnitSize;
                  (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v15.pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)v15.pHeader->UnitSize;
                  Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v15.pNext->pNext);
                  v15.pHeader->pHandle = 0i64;
                }
              }
              memmove(
                &pObject->MaskAreas.Data.Data[v13],
                &pObject->MaskAreas.Data.Data[v13 + 1],
                8 * (pObject->MaskAreas.Data.Size - v13) - 8);
              --pObject->MaskAreas.Data.Size;
            }
          }
LABEL_25:
          if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
          {
            pHeader = result.pHandle->pHeader;
            v16 = result.pHandle->pHeader->RefCount-- == 1;
            if ( v16 )
            {
              v19 = pHeader->DataPageOffset;
              *(_WORD *)((char *)&pHeader[1].RefCount + v19 + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
              (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + v19))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
              Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
              pHeader->pHandle = 0i64;
            }
          }
        }
      }
    }
    v20 = this->pMaskPrimitive.pObject;
    if ( !v20->MaskAreas.Data.Size )
    {
      if ( v20 )
      {
        if ( !_InterlockedDecrement(&v20->RefCount) )
          v20->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
            v20,
            1u);
      }
      this->pMaskPrimitive.pObject = 0i64;
    }
  }
}

// File Line: 634
// RVA: 0x9D5B30
void __fastcall Scaleform::Render::TextPrimitiveBundle::clearBatchLayers(Scaleform::Render::TextPrimitiveBundle *this)
{
  unsigned __int64 i; // r8
  Scaleform::Render::TreeCacheNode *pSourceNode; // rcx
  Scaleform::Render::MaskPrimitive *pObject; // rcx

  for ( i = 0i64; i < this->Entries.Data.Size; ++i )
  {
    pSourceNode = this->Entries.Data.Data[i]->pSourceNode;
    if ( ((__int64)pSourceNode[2].pNext & 0x20) != 0 && pSourceNode != (Scaleform::Render::TreeCacheNode *)-208i64 )
    {
      pSourceNode[3].pNext = 0i64;
      pSourceNode[3].pRoot = 0i64;
    }
  }
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::Clear(&this->Layers);
  pObject = this->pMaskPrimitive.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  this->pMaskPrimitive.pObject = 0i64;
}

// File Line: 668
// RVA: 0x9BD2A0
bool __fastcall Scaleform::Render::SKI_TextPrimitive::UpdateBundleEntry(
        Scaleform::Render::SKI_TextPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::TextPrimitiveBundle *v5; // rax
  Scaleform::Render::Bundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rbx
  Scaleform::Render::Bundle *v10; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v11; // [rsp+58h] [rbp+20h]

  v11 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v10) = 67;
    v5 = (Scaleform::Render::TextPrimitiveBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
    Scaleform::Render::BundleEntry::SetBundle(p, v7, 0i64);
    if ( v7 )
    {
      if ( v7->RefCount-- == 1 )
        v7->vfptr->__vecDelDtor(v7, 1u);
    }
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 679
// RVA: 0x96F380
void __fastcall Scaleform::Render::SKI_TextPrimitive::DrawBundleEntry(
        Scaleform::Render::SKI_TextPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::Bundle *pObject; // rax
  Scaleform::Render::HAL *v5; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  __int64 v7[3]; // [rsp+20h] [rbp-18h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v5 = r->pHal.pObject;
    v7[0] = (__int64)&pObject[1];
    vfptr = v5->vfptr;
    v7[1] = 0i64;
    vfptr[33].__vecDelDtor(v5, (unsigned int)v7);
  }
}

// File Line: 690
// RVA: 0x159C8F0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_TextPrimitive::Instance__()
{
  Scaleform::Render::SKI_TextPrimitive::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_TextPrimitive::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_TextPrimitive::Instance__);
}

// File Line: 691
// RVA: 0x159C5E0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_TextPrimitive::Instance3D__()
{
  Scaleform::Render::SKI_TextPrimitive::Instance3D.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_TextPrimitive::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_TextPrimitive::Instance3D__);
}

