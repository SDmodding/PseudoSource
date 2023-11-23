// File Line: 63
// RVA: 0x9953D0
void __fastcall Scaleform::Render::PrimitiveBundle::InsertEntry(
        Scaleform::Render::PrimitiveBundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *entry)
{
  unsigned int v4; // esi
  Scaleform::Render::TreeCacheNode *pSourceNode; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_pMask; // rbx
  Scaleform::Render::Mesh *v8; // rax

  v4 = index;
  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  pSourceNode = entry->pSourceNode;
  p_pMask = (Scaleform::Render::MatrixPoolImpl::HMatrix *)&pSourceNode[1].pMask;
  v8 = (Scaleform::Render::Mesh *)(*(__int64 (**)(void))pSourceNode->vfptr[1].gap8)();
  Scaleform::Render::Primitive::Insert(&this->Prim, v4, v8, p_pMask);
}

// File Line: 71
// RVA: 0x9A9960
void __fastcall Scaleform::Render::PrimitiveBundle::RemoveEntries(
        Scaleform::Render::PrimitiveBundle *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  Scaleform::Render::Primitive::Remove(&this->Prim, index, count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}

// File Line: 77
// RVA: 0x9BF2A0
void __fastcall Scaleform::Render::PrimitiveBundle::UpdateMesh(
        Scaleform::Render::PrimitiveBundle *this,
        Scaleform::Render::BundleEntry *entry)
{
  unsigned __int64 IndexHint; // rbx
  unsigned __int64 Size; // r8
  Scaleform::Render::BundleEntry **i; // rax
  Scaleform::Render::Mesh *v6; // rax

  IndexHint = entry->IndexHint;
  Size = this->Entries.Data.Size;
  if ( IndexHint >= Size || this->Entries.Data.Data[IndexHint] != entry )
  {
    IndexHint = 0i64;
    if ( !Size )
      return;
    for ( i = this->Entries.Data.Data; *i != entry; ++i )
    {
      if ( ++IndexHint >= Size )
        return;
    }
    entry->IndexHint = IndexHint;
  }
  v6 = (Scaleform::Render::Mesh *)(*(__int64 (__fastcall **)(Scaleform::Render::TreeCacheNode *))entry->pSourceNode->vfptr[1].gap8)(entry->pSourceNode);
  Scaleform::Render::Primitive::SetMesh(&this->Prim, IndexHint, v6);
}

// File Line: 91
// RVA: 0x9398A0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::ComplexPrimitiveBundle(
        Scaleform::Render::ComplexPrimitiveBundle *this)
{
  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::Bundle};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->Instances.Data.Data = 0i64;
  this->Instances.Data.Size = 0i64;
  this->Instances.Data.Policy.Capacity = 0i64;
}

// File Line: 94
// RVA: 0x949330
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::~ComplexPrimitiveBundle(
        Scaleform::Render::ComplexPrimitiveBundle *this)
{
  Scaleform::ArrayLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2,Scaleform::ArrayDefaultPolicy> *p_Instances; // rbx

  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::Bundle};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  p_Instances = &this->Instances;
  Scaleform::ConstructorMov<Scaleform::Render::Primitive::MeshEntry>::DestructArray(
    (Scaleform::Render::Primitive::MeshEntry *)this->Instances.Data.Data,
    this->Instances.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_Instances->Data.Data);
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 98
// RVA: 0x96E460
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::Draw(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::HAL *hal)
{
  unsigned __int64 Size; // rdi
  unsigned __int64 v3; // rbx
  Scaleform::Render::RenderQueueItem::Interface *v6; // rbp
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v8; // rax
  Scaleform::Render::ComplexMesh *pObject; // rdx
  unsigned __int64 v10; // rcx
  Scaleform::Ptr<Scaleform::Render::ComplexMesh> *p_pMesh; // rax
  __int64 v12[3]; // [rsp+20h] [rbp-18h] BYREF

  Size = this->Instances.Data.Size;
  v3 = 0i64;
  if ( Size )
  {
    v6 = &this->Scaleform::Render::RenderQueueItem::Interface;
    do
    {
      vfptr = hal->vfptr;
      v12[0] = (__int64)v6;
      v12[1] = v3;
      vfptr[33].__vecDelDtor(hal, (unsigned int)v12);
      v8 = &this->Instances.Data.Data[v3];
      pObject = v8->pMesh.pObject;
      v10 = this->Instances.Data.Size - 1;
      if ( v3 < v10 )
      {
        p_pMesh = &v8[1].pMesh;
        do
        {
          if ( p_pMesh->pObject != pObject )
            break;
          ++v3;
          p_pMesh += 2;
        }
        while ( v3 < v10 );
      }
      ++v3;
    }
    while ( v3 < Size );
  }
}

// File Line: 111
// RVA: 0x995130
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::InsertEntry(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::TreeCacheNode *pSourceNode; // rbx
  Scaleform::Render::Mesh *v7; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pMask; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::Primitive::MeshEntry val; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  pSourceNode = entry->pSourceNode;
  v7 = (Scaleform::Render::Mesh *)(*(__int64 (__fastcall **)(Scaleform::Render::TreeCacheNode *))pSourceNode->vfptr[1].gap8)(pSourceNode);
  pMask = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)pSourceNode[1].pMask;
  val.M.pHandle = pMask;
  if ( pMask != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pMask->pHeader->RefCount;
  if ( v7 )
    _InterlockedExchangeAdd(&v7->RefCount, 1u);
  val.pMesh.pObject = v7;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Instances,
    index,
    &val);
  if ( val.pMesh.pObject && !_InterlockedDecrement(&val.pMesh.pObject->RefCount) )
    val.pMesh.pObject->vfptr->__vecDelDtor(val.pMesh.pObject, 1u);
  if ( val.M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = val.M.pHandle->pHeader;
    if ( val.M.pHandle->pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
}

// File Line: 123
// RVA: 0x9A98D0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::RemoveEntries(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Instances,
    index,
    count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}

// File Line: 129
// RVA: 0x9BF1F0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::UpdateMesh(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::BundleEntry *entry)
{
  unsigned __int64 IndexHint; // rbx
  unsigned __int64 Size; // r8
  Scaleform::Render::BundleEntry **i; // rax
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v5; // rbx
  __int64 v6; // rax
  Scaleform::Render::ComplexMesh *v7; // rdi
  Scaleform::Render::ComplexMesh *pObject; // rcx

  IndexHint = entry->IndexHint;
  Size = this->Entries.Data.Size;
  if ( IndexHint >= Size || this->Entries.Data.Data[IndexHint] != entry )
  {
    IndexHint = 0i64;
    if ( !Size )
      return;
    for ( i = this->Entries.Data.Data; *i != entry; ++i )
    {
      if ( ++IndexHint >= Size )
        return;
    }
    entry->IndexHint = IndexHint;
  }
  v5 = &this->Instances.Data.Data[IndexHint];
  v6 = (*(__int64 (__fastcall **)(Scaleform::Render::TreeCacheNode *))entry->pSourceNode->vfptr[1].gap8)(entry->pSourceNode);
  v7 = (Scaleform::Render::ComplexMesh *)v6;
  if ( v6 )
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 8), 1u);
  pObject = v5->pMesh.pObject;
  if ( pObject )
  {
    if ( !_InterlockedDecrement(&pObject->RefCount) )
      pObject->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        pObject,
        1u);
  }
  v5->pMesh.pObject = v7;
}

// File Line: 142
// RVA: 0x99F6F0
__int64 __fastcall Scaleform::Render::ComplexPrimitiveBundle::Prepare(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp,
        bool waitForCache)
{
  if ( qp->QueuePrepareFilter == QPF_All )
  {
    if ( !Scaleform::Render::MeshCache::PrepareComplexMesh(
            (Scaleform::Render::MeshCache *)qp->Caches.pCaches[0],
            *(Scaleform::Render::ComplexMesh **)(*(_QWORD *)&this->RefCount + 16 * (__int64)item->Data + 8),
            waitForCache)
      && item != qp->PrepareItemBuffer.pItem )
    {
      qp->PrepareItemBuffer.pItem = item;
      return 1i64;
    }
    qp->PrepareItemBuffer.pItem = 0i64;
  }
  return 0i64;
}

// File Line: 173
// RVA: 0x96FDA0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::EmitToHAL(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  __int64 v6; // rax
  char *Data; // rbx
  __int64 v8; // rdi
  __int64 v9; // r8
  char *v10; // rcx
  char *v11; // rdx
  _QWORD *v12; // rax
  __int64 v13; // rdx
  __int64 v14[4]; // [rsp+20h] [rbp-28h] BYREF

  if ( qp->QueueEmitFilter == QPF_All )
  {
    v6 = *(_QWORD *)&this->RefCount;
    Data = (char *)item->Data;
    v8 = v6 + 16i64 * (_QWORD)Data;
    if ( item != qp->PrepareItemBuffer.pItem )
    {
      if ( *(_QWORD *)(v8 + 8) )
      {
        v9 = *(_QWORD *)(v6 + 16 * (__int64)item->Data + 8);
        v10 = (char *)item->Data;
        v11 = (char *)this->Entries.Data.Data - 1;
        if ( Data < v11 )
        {
          v12 = (_QWORD *)(v8 + 24);
          do
          {
            if ( *v12 != v9 )
              break;
            ++v10;
            v12 += 2;
          }
          while ( v10 < v11 );
        }
        v13 = *(_QWORD *)(v8 + 8);
        v14[0] = v8;
        v14[2] = 16i64;
        v14[1] = v10 - Data + 1;
        ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64 *))qp->pHAL->vfptr[35].__vecDelDtor)(
          qp->pHAL,
          v13,
          v14);
      }
    }
  }
}

// File Line: 199
// RVA: 0x93E4D0
void __fastcall Scaleform::Render::MaskBundle::MaskBundle(Scaleform::Render::MaskBundle *this)
{
  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::MaskBundle::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Prim.RefCount = 1;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::`vftable;
  this->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MaskPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>};
  this->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::MaskPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->Prim.MaskAreas.Data.Data = 0i64;
  this->Prim.MaskAreas.Data.Size = 0i64;
  this->Prim.MaskAreas.Data.Policy.Capacity = 0i64;
}

// File Line: 203
// RVA: 0x995300
void __fastcall Scaleform::Render::MaskBundle::InsertEntry(
        Scaleform::Render::MaskBundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::MaskEffect *i; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *BoundsMatrix; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  for ( i = (Scaleform::Render::MaskEffect *)entry->pSourceNode->Effects.pEffect;
        i;
        i = (Scaleform::Render::MaskEffect *)i->pNext )
  {
    if ( i->vfptr->GetType(i) == State_MaskNode )
      break;
  }
  BoundsMatrix = Scaleform::Render::MaskEffect::GetBoundsMatrix(i, &result);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Prim.MaskAreas,
    index,
    BoundsMatrix);
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

// File Line: 212
// RVA: 0x9A9910
void __fastcall Scaleform::Render::MaskBundle::RemoveEntries(
        Scaleform::Render::MaskBundle *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    &this->Prim.MaskAreas,
    (unsigned int)index,
    (unsigned int)count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}

// File Line: 223
// RVA: 0x93BC40
void __fastcall Scaleform::Render::FilterBundle::FilterBundle(
        Scaleform::Render::FilterBundle *this,
        Scaleform::Render::FilterSet *filters,
        bool maskPresent)
{
  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::FilterBundle::`vftable;
  Scaleform::Render::CacheablePrimitive::CacheablePrimitive(&this->Prim, maskPresent);
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  this->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  if ( filters )
    _InterlockedExchangeAdd(&filters->RefCount, 1u);
  this->Prim.pFilters.pObject = filters;
}

// File Line: 227
// RVA: 0x995230
void __fastcall Scaleform::Render::FilterBundle::InsertEntry(
        Scaleform::Render::FilterBundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::FilterEffect *i; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *BoundsMatrix; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  for ( i = (Scaleform::Render::FilterEffect *)entry->pSourceNode->Effects.pEffect;
        i;
        i = (Scaleform::Render::FilterEffect *)i->pNext )
  {
    if ( i->vfptr->GetType(i) == State_Filter )
      break;
  }
  BoundsMatrix = Scaleform::Render::FilterEffect::GetBoundsMatrix(i, &result);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Prim.PrimitiveArea,
    index,
    BoundsMatrix);
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

// File Line: 246
// RVA: 0x938EA0
void __fastcall Scaleform::Render::BlendModeBundle::BlendModeBundle(
        Scaleform::Render::BlendModeBundle *this,
        Scaleform::Render::BlendMode mode,
        bool maskPresent)
{
  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::BlendModeBundle::`vftable;
  Scaleform::Render::CacheablePrimitive::CacheablePrimitive(&this->Prim, maskPresent);
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlendPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  this->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::BlendPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->Prim.BlendModeValue = mode;
}

// File Line: 250
// RVA: 0x994FF0
void __fastcall Scaleform::Render::BlendModeBundle::InsertEntry(
        Scaleform::Render::BlendModeBundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BlendModeEffect *i; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *BoundsMatrix; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  for ( i = (Scaleform::Render::BlendModeEffect *)entry->pSourceNode->Effects.pEffect;
        i;
        i = (Scaleform::Render::BlendModeEffect *)i->pNext )
  {
    if ( i->vfptr->GetType(i) == State_BlendMode )
      break;
  }
  BoundsMatrix = Scaleform::Render::BlendModeEffect::GetBoundsMatrix(i, &result);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Prim.PrimitiveArea,
    index,
    BoundsMatrix);
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

// File Line: 258
// RVA: 0x9A9780
void __fastcall Scaleform::Render::FilterBundle::RemoveEntries(
        Scaleform::Render::FilterBundle *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  Scaleform::Render::CacheablePrimitive::Remove(&this->Prim, (unsigned int)index, (unsigned int)count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}

// File Line: 269
// RVA: 0x946E60
void __fastcall Scaleform::Render::ViewMatrix3DBundle::ViewMatrix3DBundle(
        Scaleform::Render::ViewMatrix3DBundle *this,
        Scaleform::Render::Matrix3x4Ref<float> *pvm)
{
  float v4; // eax
  float v5; // ecx
  float v6; // edx
  float v7; // r8d
  float v8; // r9d
  float v9; // r10d
  float v10; // r11d
  float v11; // ebx
  float v12; // edi
  float v13; // esi
  float v14; // ebp
  float v15; // r14d

  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ViewMatrix3DBundle::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Prim.RefCount = 1;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>::`vftable;
  this->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>};
  this->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  memset(&this->Prim.ViewMatrix, 0, sizeof(this->Prim.ViewMatrix));
  this->Prim.ViewMatrix.M[0][0] = 1.0;
  this->Prim.ViewMatrix.M[1][1] = 1.0;
  this->Prim.ViewMatrix.M[2][2] = 1.0;
  this->Prim.bHasViewMatrix = 0;
  if ( pvm )
  {
    v4 = pvm->M[0][0];
    v5 = pvm->M[0][1];
    v6 = pvm->M[0][2];
    v7 = pvm->M[0][3];
    v8 = pvm->M[1][0];
    v9 = pvm->M[1][1];
    v10 = pvm->M[1][2];
    v11 = pvm->M[1][3];
    v12 = pvm->M[2][0];
    v13 = pvm->M[2][1];
    v14 = pvm->M[2][2];
    v15 = pvm->M[2][3];
    this->Prim.ViewMatrix.M[0][0] = v4;
    this->Prim.ViewMatrix.M[0][1] = v5;
    this->Prim.ViewMatrix.M[0][2] = v6;
    this->Prim.ViewMatrix.M[0][3] = v7;
    this->Prim.ViewMatrix.M[1][0] = v8;
    this->Prim.ViewMatrix.M[1][1] = v9;
    this->Prim.ViewMatrix.M[1][2] = v10;
    this->Prim.ViewMatrix.M[1][3] = v11;
    this->Prim.ViewMatrix.M[2][0] = v12;
    this->Prim.ViewMatrix.M[2][1] = v13;
    this->Prim.ViewMatrix.M[2][2] = v14;
    this->Prim.ViewMatrix.M[2][3] = v15;
    this->Prim.bHasViewMatrix = 1;
  }
}

// File Line: 280
// RVA: 0x940B40
void __fastcall Scaleform::Render::ProjectionMatrix3DBundle::ProjectionMatrix3DBundle(
        Scaleform::Render::ProjectionMatrix3DBundle *this,
        Scaleform::Render::Matrix4x4Ref<float> *ppm)
{
  float v4; // edx
  float v5; // r8d
  float v6; // r9d
  float v7; // r10d
  float v8; // r11d
  float v9; // ebx
  float v10; // edi
  float v11; // esi
  float v12; // ebp
  float v13; // r14d
  float v14; // r15d
  float v15; // r12d
  float v16; // r13d
  Scaleform::Render::ProjectionMatrix3DPrimitive *p_Prim; // [rsp+20h] [rbp-58h]
  float v19; // [rsp+88h] [rbp+10h]
  float v20; // [rsp+90h] [rbp+18h]
  float v21; // [rsp+98h] [rbp+20h]

  Scaleform::Render::Bundle::Bundle(this, 0i64);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ProjectionMatrix3DBundle::`vftable;
  p_Prim = &this->Prim;
  Scaleform::Render::ProjectionMatrix3DPrimitive::ProjectionMatrix3DPrimitive(&this->Prim);
  if ( ppm )
  {
    v20 = ppm->M[0][0];
    v21 = ppm->M[0][1];
    v4 = ppm->M[0][2];
    v5 = ppm->M[0][3];
    v6 = ppm->M[1][0];
    v7 = ppm->M[1][1];
    v8 = ppm->M[1][2];
    v9 = ppm->M[1][3];
    v10 = ppm->M[2][0];
    v11 = ppm->M[2][1];
    v12 = ppm->M[2][2];
    v13 = ppm->M[2][3];
    v14 = ppm->M[3][0];
    v15 = ppm->M[3][1];
    v16 = ppm->M[3][2];
    v19 = ppm->M[3][3];
    p_Prim->ProjectionMatrix.M[0][0] = v20;
    p_Prim->ProjectionMatrix.M[0][1] = v21;
    p_Prim->ProjectionMatrix.M[0][2] = v4;
    p_Prim->ProjectionMatrix.M[0][3] = v5;
    p_Prim->ProjectionMatrix.M[1][0] = v6;
    p_Prim->ProjectionMatrix.M[1][1] = v7;
    p_Prim->ProjectionMatrix.M[1][2] = v8;
    p_Prim->ProjectionMatrix.M[1][3] = v9;
    p_Prim->ProjectionMatrix.M[2][0] = v10;
    p_Prim->ProjectionMatrix.M[2][1] = v11;
    p_Prim->ProjectionMatrix.M[2][2] = v12;
    p_Prim->ProjectionMatrix.M[2][3] = v13;
    p_Prim->ProjectionMatrix.M[3][0] = v14;
    p_Prim->ProjectionMatrix.M[3][1] = v15;
    p_Prim->ProjectionMatrix.M[3][2] = v16;
    p_Prim->ProjectionMatrix.M[3][3] = v19;
    p_Prim->bHasProjectionMatrix = 1;
  }
}

// File Line: 309
// RVA: 0x9BD0B0
bool __fastcall Scaleform::Render::SKI_Primitive::UpdateBundleEntry(
        Scaleform::Render::SKI_Primitive *this,
        Scaleform::Render::PrimitiveFill *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::Bundle *v8; // rax
  __int64 v9; // rbx
  __int64 v12; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v13; // [rsp+88h] [rbp+20h]

  v13 = tr;
  if ( !p->pBundle.pObject )
  {
    ((void (__fastcall *)(Scaleform::Render::SKI_Primitive *))Scaleform::Render::SKI_Primitive::Instance.vfptr->AddRef)(&Scaleform::Render::SKI_Primitive::Instance);
    LODWORD(v12) = 67;
    v8 = (Scaleform::Render::Bundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, __int64 *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        tr,
                                        168i64,
                                        &v12,
                                        -2i64);
    v9 = (__int64)v8;
    if ( v8 )
    {
      Scaleform::Render::Bundle::Bundle(v8, 0i64);
      *(_QWORD *)v9 = &Scaleform::Render::DrawableBundle::`vftable;
      *(_QWORD *)(v9 + 56) = tr;
      *(_QWORD *)(v9 + 64) = r;
      *(_QWORD *)v9 = &Scaleform::Render::PrimitiveBundle::`vftable;
      Scaleform::Render::Primitive::Primitive(
        (Scaleform::Render::Primitive *)(v9 + 72),
        *(Scaleform::Render::HAL **)(*(_QWORD *)(v9 + 64) + 80i64),
        d);
    }
    else
    {
      v9 = 0i64;
    }
    v12 = v9;
    Scaleform::Render::BundleEntry::SetBundle(p, (Scaleform::Render::Bundle *)v9, 0i64);
    if ( v9 )
    {
      if ( (*(_DWORD *)(v9 + 8))-- == 1 )
        (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
    }
    Scaleform::Render::SKI_Primitive::Instance.vfptr->Release(&Scaleform::Render::SKI_Primitive::Instance, d);
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 320
// RVA: 0x96F2E0
void __fastcall Scaleform::Render::SKI_Primitive::DrawBundleEntry(
        Scaleform::Render::SKI_Primitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *a4)
{
  Scaleform::Render::Bundle *pObject; // rcx
  __int64 p_Policy; // rdx
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8[3]; // [rsp+20h] [rbp-18h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    if ( pObject == (Scaleform::Render::Bundle *)-72i64 )
      p_Policy = 0i64;
    else
      p_Policy = (__int64)&pObject[1].Entries.Data.Policy;
    v6 = *(_QWORD *)&pObject[1].RefCount;
    v8[0] = p_Policy;
    v7 = *(_QWORD *)(v6 + 80);
    v8[1] = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *, Scaleform::Render::BundleEntry *, Scaleform::Render::Renderer2DImpl *))(*(_QWORD *)v7 + 264i64))(
      v7,
      v8,
      p,
      a4);
  }
}

// File Line: 339
// RVA: 0x954980
void __fastcall Scaleform::Render::SKI_ComplexPrimitive::AddRef(Scaleform::Render::SKI_ComplexPrimitive *this, void *p)
{
  if ( p )
    (*(void (__fastcall **)(void *))(*(_QWORD *)p + 8i64))(p);
}

// File Line: 340
// RVA: 0x9A7D40
void __fastcall Scaleform::Render::SKI_ComplexPrimitive::Release(
        Scaleform::Render::SKI_ComplexPrimitive *this,
        void *p)
{
  if ( p )
    (*(void (__fastcall **)(void *))(*(_QWORD *)p + 16i64))(p);
}

// File Line: 345
// RVA: 0x9BCE30
bool __fastcall Scaleform::Render::SKI_ComplexPrimitive::UpdateBundleEntry(
        Scaleform::Render::SKI_ComplexPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::ComplexPrimitiveBundle *v5; // rax
  Scaleform::Render::Bundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rbx
  Scaleform::Render::Bundle *v10; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v11; // [rsp+58h] [rbp+20h]

  v11 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v10) = 67;
    v5 = (Scaleform::Render::ComplexPrimitiveBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        tr,
                                                        88i64,
                                                        &v10,
                                                        -2i64);
    if ( v5 )
    {
      Scaleform::Render::ComplexPrimitiveBundle::ComplexPrimitiveBundle(v5);
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

// File Line: 356
// RVA: 0x96F290
void __fastcall Scaleform::Render::SKI_ComplexPrimitive::DrawBundleEntry(
        Scaleform::Render::SKI_ComplexPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::ComplexPrimitiveBundle *pObject; // rcx

  pObject = (Scaleform::Render::ComplexPrimitiveBundle *)p->pBundle.pObject;
  if ( pObject )
    Scaleform::Render::ComplexPrimitiveBundle::Draw(pObject, r->pHal.pObject);
}

// File Line: 366
// RVA: 0x159C8B0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Primitive::Instance__()
{
  Scaleform::Render::SKI_Primitive::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Primitive::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_Primitive::Instance__);
}

// File Line: 367
// RVA: 0x159C5A0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Primitive::Instance3D__()
{
  Scaleform::Render::SKI_Primitive::Instance3D.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Primitive::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_Primitive::Instance3D__);
}

// File Line: 368
// RVA: 0x159C850
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ComplexPrimitive::Instance__()
{
  Scaleform::Render::SKI_ComplexPrimitive::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ComplexPrimitive::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_ComplexPrimitive::Instance__);
}

// File Line: 369
// RVA: 0x159C570
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ComplexPrimitive::Instance3D__()
{
  Scaleform::Render::SKI_ComplexPrimitive::Instance3D.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ComplexPrimitive::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_ComplexPrimitive::Instance3D__);
}

// File Line: 401
// RVA: 0x9BD000
bool __fastcall Scaleform::Render::SKI_MaskStart::UpdateBundleEntry(
        Scaleform::Render::SKI_MaskStart *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::MaskBundle *v5; // rax
  Scaleform::Render::Bundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rbx
  Scaleform::Render::Bundle *v10; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v11; // [rsp+58h] [rbp+20h]

  v11 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v10) = 67;
    v5 = (Scaleform::Render::MaskBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                            Scaleform::Memory::pGlobalHeap,
                                            tr,
                                            104i64,
                                            &v10,
                                            -2i64);
    if ( v5 )
    {
      Scaleform::Render::MaskBundle::MaskBundle(v5);
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

// File Line: 411
// RVA: 0x98AE90
_BOOL8 __fastcall Scaleform::Render::SKI_MaskStart::GetRangeTransition(
        Scaleform::Render::SKI_MaskStart *this,
        void *__formal,
        Scaleform::Render::SortKey *other)
{
  return other->pImpl->Type == SortKey_MaskEnd;
}

// File Line: 442
// RVA: 0x96FF30
void __fastcall Scaleform::Render::SKI_MaskEnd::RQII_EndMask::EmitToHAL(
        Scaleform::Render::SKI_MaskEnd::RQII_EndMask *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  int Data; // eax
  Scaleform::Render::HAL *pHAL; // rcx

  if ( qp->QueueEmitFilter == QPF_All )
  {
    Data = (int)item->Data;
    pHAL = qp->pHAL;
    if ( Data == 1 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))pHAL->vfptr[37].__vecDelDtor)(pHAL);
    }
    else if ( Data == 2 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))pHAL->vfptr[38].__vecDelDtor)(pHAL);
    }
  }
}

// File Line: 459
// RVA: 0x98AE70
__int64 __fastcall Scaleform::Render::SKI_MaskEnd::GetRangeTransition(
        Scaleform::Render::SKI_MaskEnd *this,
        void *data,
        Scaleform::Render::SortKey *other)
{
  __int64 result; // rax

  result = 0i64;
  if ( other->pImpl->Type == SortKey_MaskEnd )
    return 2i64;
  return result;
}

// File Line: 471
// RVA: 0x96F2B0
void __fastcall Scaleform::Render::SKI_MaskEnd::DrawBundleEntry(
        Scaleform::Render::SKI_MaskEnd *this,
        __int64 data,
        Scaleform::Render::BundleEntry *__formal,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::HAL *pObject; // rcx
  __int64 v5[3]; // [rsp+20h] [rbp-18h] BYREF

  pObject = r2d->pHal.pObject;
  v5[1] = data;
  v5[0] = (__int64)&Scaleform::Render::SKI_MaskEnd::RQII_Instance;
  ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, Scaleform::Render::BundleEntry *))pObject->vfptr[33].__vecDelDtor)(
    pObject,
    v5,
    __formal);
}

// File Line: 480
// RVA: 0x159C330
__int64 dynamic_initializer_for__Scaleform::Render::SKI_MaskStart::Combinable_Instance__()
{
  Scaleform::Render::SKI_MaskStart::Combinable_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_MaskStart::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_MaskStart::Combinable_Instance__);
}

// File Line: 481
// RVA: 0x159C880
__int64 dynamic_initializer_for__Scaleform::Render::SKI_MaskEnd::Instance__()
{
  Scaleform::Render::SKI_MaskEnd::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_MaskEnd::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_MaskEnd::Instance__);
}

// File Line: 483
// RVA: 0x159CBB0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_MaskEnd::RQII_Instance__()
{
  Scaleform::Render::SKI_MaskEnd::RQII_Instance.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::SKI_MaskEnd::RQII_EndMask::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_MaskEnd::RQII_Instance__);
}

// File Line: 504
// RVA: 0x9E8E00
bool __fastcall Scaleform::Render::isMaskPresentInsideRange(
        Scaleform::Render::BundleIterator *ibundles,
        Scaleform::Render::SortKeyType startKey,
        Scaleform::Render::SortKeyType endKey)
{
  Scaleform::Render::BundleEntry *pFirst; // r9
  int v4; // eax
  Scaleform::Render::SortKeyType Type; // edx

  pFirst = ibundles->pFirst;
  v4 = 0;
  if ( ibundles->pFirst )
  {
    while ( v4 != 1 || (unsigned int)(pFirst->Key.pImpl->Type - 3) > 2 )
    {
      Type = pFirst->Key.pImpl->Type;
      if ( Type == endKey )
      {
        if ( --v4 <= 0 )
          goto LABEL_6;
      }
      else if ( Type == startKey )
      {
        ++v4;
      }
      if ( pFirst != ibundles->pLast )
      {
        pFirst = pFirst->pNextPattern;
        if ( pFirst )
          continue;
      }
LABEL_6:
      LOBYTE(v4) = 0;
      return v4;
    }
    LOBYTE(v4) = 1;
  }
  return v4;
}

// File Line: 548
// RVA: 0x98AE30
__int64 __fastcall Scaleform::Render::SKI_BlendMode::GetRangeTransition(
        Scaleform::Render::SKI_BlendMode *this,
        void *__formal,
        Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_BlendModeEnd && this->Type == SortKey_BlendModeStart )
    return 2i64;
  else
    return 0i64;
}

// File Line: 557
// RVA: 0x9BCD50
bool __fastcall Scaleform::Render::SKI_BlendMode::UpdateBundleEntry(
        Scaleform::Render::SKI_BlendMode *this,
        void *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *__formal,
        Scaleform::Render::BundleIterator *ibundles)
{
  unsigned int v7; // ebx
  Scaleform::Render::BlendModeBundle *v8; // rbp
  int v9; // eax
  bool v10; // al
  Scaleform::Render::Bundle *v11; // rax
  Scaleform::Render::Bundle *v12; // rbx
  Scaleform::Render::Bundle *v15; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v16; // [rsp+68h] [rbp+20h]

  v16 = tr;
  v7 = (unsigned int)d;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v15) = 67;
    v8 = (Scaleform::Render::BlendModeBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 tr,
                                                 144i64,
                                                 &v15,
                                                 -2i64);
    if ( v8 )
    {
      v10 = v7 <= 0xE
         && (v9 = 24804, _bittest(&v9, v7))
         && Scaleform::Render::isMaskPresentInsideRange(ibundles, SortKey_BlendModeStart, SortKey_BlendModeEnd);
      Scaleform::Render::BlendModeBundle::BlendModeBundle(v8, (Scaleform::Render::BlendMode)v7, v10);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v15 = v12;
    Scaleform::Render::BundleEntry::SetBundle(p, v12, 0i64);
    if ( v12 )
    {
      if ( v12->RefCount-- == 1 )
        v12->vfptr->__vecDelDtor(v12, 1u);
    }
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 571
// RVA: 0x96F3C0
void __fastcall Scaleform::Render::SKI_Filter::DrawBundleEntry(
        Scaleform::Render::SKI_UserData *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::Bundle *pObject; // rcx
  Scaleform::Render::HAL *v5; // r8
  __int64 p_Entries; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  __int64 v8[3]; // [rsp+20h] [rbp-18h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v5 = r2d->pHal.pObject;
    if ( pObject == (Scaleform::Render::Bundle *)-56i64 )
      p_Entries = 0i64;
    else
      p_Entries = (__int64)&pObject[1].Entries;
    vfptr = v5->vfptr;
    v8[0] = p_Entries;
    v8[1] = 0i64;
    vfptr[33].__vecDelDtor(v5, (unsigned int)v8);
  }
}

// File Line: 583
// RVA: 0x159CC10
__int64 dynamic_initializer_for__Scaleform::Render::SKI_BlendMode::Start_Instance__()
{
  Scaleform::Render::SKI_BlendMode::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_BlendMode::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_BlendMode::Start_Instance__);
}

// File Line: 584
// RVA: 0x159CBE0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_BlendMode::StartCacheable_Instance__()
{
  Scaleform::Render::SKI_BlendMode::StartCacheable_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_BlendMode::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_BlendMode::StartCacheable_Instance__);
}

// File Line: 585
// RVA: 0x159C360
__int64 dynamic_initializer_for__Scaleform::Render::SKI_BlendMode::End_Instance__()
{
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_BlendMode::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_BlendMode::End_Instance__);
}

// File Line: 620
// RVA: 0x98AE50
__int64 __fastcall Scaleform::Render::SKI_Filter::GetRangeTransition(
        Scaleform::Render::SKI_Filter *this,
        void *__formal,
        Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_FilterEnd && this->Type == SortKey_FilterStart )
    return 2i64;
  else
    return 0i64;
}

// File Line: 629
// RVA: 0x9BCEE0
bool __fastcall Scaleform::Render::SKI_Filter::UpdateBundleEntry(
        Scaleform::Render::SKI_Filter *this,
        Scaleform::Render::FilterSet *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *__formal,
        Scaleform::Render::BundleIterator *ibundles)
{
  Scaleform::Render::FilterBundle *v8; // r11
  bool v9; // r10
  Scaleform::Render::BundleEntry *pFirst; // rdx
  int v11; // ecx
  Scaleform::Render::SortKeyType Type; // r8d
  Scaleform::Render::SortKeyType v13; // r8d
  Scaleform::Render::Bundle *v14; // rax
  Scaleform::Render::Bundle *v15; // rbx
  Scaleform::Render::Bundle *v18; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v19; // [rsp+58h] [rbp+20h]

  v19 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v18) = 67;
    v8 = (Scaleform::Render::FilterBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              tr,
                                              144i64,
                                              &v18,
                                              -2i64);
    if ( v8 )
    {
      v9 = 0;
      pFirst = ibundles->pFirst;
      v11 = 0;
      while ( pFirst )
      {
        if ( v11 == 1 )
        {
          Type = pFirst->Key.pImpl->Type;
          if ( Type == SortKey_MaskStart || Type == SortKey_MaskEnd || Type == SortKey_Text )
          {
            v9 = 1;
            break;
          }
        }
        v13 = pFirst->Key.pImpl->Type;
        if ( v13 == SortKey_FilterEnd )
        {
          if ( --v11 <= 0 )
            break;
        }
        else if ( v13 == SortKey_FilterStart )
        {
          ++v11;
        }
        if ( pFirst == ibundles->pLast )
          break;
        pFirst = pFirst->pNextPattern;
      }
      Scaleform::Render::FilterBundle::FilterBundle(v8, d, v9);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    v18 = v15;
    Scaleform::Render::BundleEntry::SetBundle(p, v15, 0i64);
    if ( v15 )
    {
      if ( v15->RefCount-- == 1 )
        v15->vfptr->__vecDelDtor(v15, 1u);
    }
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 652
// RVA: 0x159CC40
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Filter::Start_Instance__()
{
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Filter::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_Filter::Start_Instance__);
}

// File Line: 653
// RVA: 0x159C390
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Filter::End_Instance__()
{
  Scaleform::Render::SKI_Filter::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Filter::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_Filter::End_Instance__);
}

// File Line: 679
// RVA: 0x98AEE0
__int64 __fastcall Scaleform::Render::SKI_ViewMatrix3D::GetRangeTransition(
        Scaleform::Render::SKI_ViewMatrix3D *this,
        void *__formal,
        Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_ViewMatrix3DEnd && this->Type == SortKey_ViewMatrix3DStart )
    return 2i64;
  else
    return 0i64;
}

// File Line: 687
// RVA: 0x9BD420
bool __fastcall Scaleform::Render::SKI_ViewMatrix3D::UpdateBundleEntry(
        Scaleform::Render::SKI_ViewMatrix3D *this,
        Scaleform::Render::Matrix3x4Ref<float> *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::ViewMatrix3DBundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rax
  Scaleform::Render::Bundle *v8; // rbx
  Scaleform::Render::Bundle *v11; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v12; // [rsp+58h] [rbp+20h]

  v12 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v11) = 67;
    v6 = (Scaleform::Render::ViewMatrix3DBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    tr,
                                                    160i64,
                                                    &v11,
                                                    -2i64);
    if ( v6 )
    {
      Scaleform::Render::ViewMatrix3DBundle::ViewMatrix3DBundle(v6, d);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v11 = v8;
    Scaleform::Render::BundleEntry::SetBundle(p, v8, 0i64);
    if ( v8 )
    {
      if ( v8->RefCount-- == 1 )
        v8->vfptr->__vecDelDtor(v8, 1u);
    }
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 709
// RVA: 0x159CCF0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ViewMatrix3D::Start_Instance__()
{
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ViewMatrix3D::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_ViewMatrix3D::Start_Instance__);
}

// File Line: 710
// RVA: 0x159C440
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ViewMatrix3D::End_Instance__()
{
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ViewMatrix3D::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_ViewMatrix3D::End_Instance__);
}

// File Line: 736
// RVA: 0x98AEA0
__int64 __fastcall Scaleform::Render::SKI_ProjectionMatrix3D::GetRangeTransition(
        Scaleform::Render::SKI_ProjectionMatrix3D *this,
        void *__formal,
        Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_ProjectionMatrix3DEnd && this->Type == SortKey_ProjectionMatrix3DStart )
    return 2i64;
  else
    return 0i64;
}

// File Line: 744
// RVA: 0x9BD1E0
bool __fastcall Scaleform::Render::SKI_ProjectionMatrix3D::UpdateBundleEntry(
        Scaleform::Render::SKI_ProjectionMatrix3D *this,
        Scaleform::Render::Matrix4x4Ref<float> *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::ProjectionMatrix3DBundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rax
  Scaleform::Render::Bundle *v8; // rbx
  Scaleform::Render::Bundle *v11; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v12; // [rsp+58h] [rbp+20h]

  v12 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v11) = 67;
    v6 = (Scaleform::Render::ProjectionMatrix3DBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, Scaleform::Render::Bundle **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          tr,
                                                          176i64,
                                                          &v11,
                                                          -2i64);
    if ( v6 )
    {
      Scaleform::Render::ProjectionMatrix3DBundle::ProjectionMatrix3DBundle(v6, d);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v11 = v8;
    Scaleform::Render::BundleEntry::SetBundle(p, v8, 0i64);
    if ( v8 )
    {
      if ( v8->RefCount-- == 1 )
        v8->vfptr->__vecDelDtor(v8, 1u);
    }
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 754
// RVA: 0x96F330
void __fastcall Scaleform::Render::SKI_ProjectionMatrix3D::DrawBundleEntry(
        Scaleform::Render::SKI_ViewMatrix3D *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::Bundle *pObject; // rcx
  Scaleform::Render::HAL *v5; // r8
  __int64 p_Size; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  __int64 v8[3]; // [rsp+20h] [rbp-18h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v5 = r2d->pHal.pObject;
    if ( pObject == (Scaleform::Render::Bundle *)-64i64 )
      p_Size = 0i64;
    else
      p_Size = (__int64)&pObject[1].Entries.Data.Size;
    vfptr = v5->vfptr;
    v8[0] = p_Size;
    v8[1] = 0i64;
    vfptr[33].__vecDelDtor(v5, (unsigned int)v8);
  }
}

// File Line: 766
// RVA: 0x159CC80
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance__()
{
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ProjectionMatrix3D::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance__);
}

// File Line: 767
// RVA: 0x159C3D0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance__()
{
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ProjectionMatrix3D::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance__);
}

// File Line: 794
// RVA: 0x98AEC0
__int64 __fastcall Scaleform::Render::SKI_UserData::GetRangeTransition(
        Scaleform::Render::SKI_UserData *this,
        void *__formal,
        Scaleform::Render::SortKey *other)
{
  if ( other->pImpl->Type == SortKey_UserDataEnd && this->Type == SortKey_UserDataStart )
    return 2i64;
  else
    return 0i64;
}

// File Line: 802
// RVA: 0x9BD350
bool __fastcall Scaleform::Render::SKI_UserData::UpdateBundleEntry(
        Scaleform::Render::SKI_UserData *this,
        Scaleform::Render::UserDataState::Data *d,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::Bundle *v6; // rax
  __int64 v7; // rbx
  __int64 v10; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::Render::TreeCacheRoot *v11; // [rsp+68h] [rbp+20h]

  v11 = tr;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v10) = 67;
    v6 = (Scaleform::Render::Bundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, __int64, __int64 *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        tr,
                                        88i64,
                                        &v10,
                                        -2i64);
    v7 = (__int64)v6;
    if ( v6 )
    {
      Scaleform::Render::Bundle::Bundle(v6, 0i64);
      *(_QWORD *)v7 = &Scaleform::Render::UserDataBundle::`vftable;
      Scaleform::Render::UserDataPrimitive::UserDataPrimitive((Scaleform::Render::UserDataPrimitive *)(v7 + 56), d);
    }
    else
    {
      v7 = 0i64;
    }
    v10 = v7;
    Scaleform::Render::BundleEntry::SetBundle(p, (Scaleform::Render::Bundle *)v7, 0i64);
    if ( v7 )
    {
      if ( (*(_DWORD *)(v7 + 8))-- == 1 )
        (**(void (__fastcall ***)(__int64, __int64))v7)(v7, 1i64);
    }
  }
  return p->pBundle.pObject != 0i64;
}

// File Line: 823
// RVA: 0x952D00
bool __fastcall Scaleform::Render::SKI_UserData::AcceptMatch(
        Scaleform::Render::SKI_UserData *this,
        _BYTE *d0,
        _BYTE *d1)
{
  if ( d0 != d1 )
    return 0;
  if ( !d0 )
    return 1;
  return (d0[32] & 4) == 0 || !d0[28];
}

// File Line: 837
// RVA: 0x159CCB0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_UserData::Start_Instance__()
{
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_UserData::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_UserData::Start_Instance__);
}

// File Line: 838
// RVA: 0x159C400
__int64 dynamic_initializer_for__Scaleform::Render::SKI_UserData::End_Instance__()
{
  Scaleform::Render::SKI_UserData::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_UserData::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SKI_UserData::End_Instance__);
}

