// File Line: 63
// RVA: 0x9953D0
void __fastcall Scaleform::Render::PrimitiveBundle::InsertEntry(Scaleform::Render::PrimitiveBundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // rbx
  unsigned int v4; // esi
  Scaleform::Render::PrimitiveBundle *v5; // rdi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v6; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // rbx
  Scaleform::Render::Mesh *v8; // rax

  v3 = entry;
  v4 = index;
  v5 = this;
  Scaleform::Render::Bundle::InsertEntry((Scaleform::Render::Bundle *)&this->vfptr, index, entry);
  v6 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)v3->pSourceNode;
  v7 = v6 + 22;
  v8 = (Scaleform::Render::Mesh *)((__int64 (*)(void))v6->pHandle[14].pHeader)();
  Scaleform::Render::Primitive::Insert(&v5->Prim, v4, v8, v7);
}

// File Line: 71
// RVA: 0x9A9960
void __fastcall Scaleform::Render::PrimitiveBundle::RemoveEntries(Scaleform::Render::PrimitiveBundle *this, unsigned __int64 index, unsigned __int64 count)
{
  Scaleform::Render::PrimitiveBundle *v3; // rsi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rdi

  v3 = this;
  v4 = count;
  v5 = index;
  Scaleform::Render::Primitive::Remove(&this->Prim, index, count);
  Scaleform::Render::Bundle::RemoveEntries((Scaleform::Render::Bundle *)&v3->vfptr, v5, v4);
}

// File Line: 77
// RVA: 0x9BF2A0
void __fastcall Scaleform::Render::PrimitiveBundle::UpdateMesh(Scaleform::Render::PrimitiveBundle *this, Scaleform::Render::BundleEntry *entry)
{
  unsigned __int64 v2; // rbx
  unsigned __int64 v3; // r8
  Scaleform::Render::PrimitiveBundle *v4; // rdi
  Scaleform::Render::BundleEntry **v5; // rax
  Scaleform::Render::Mesh *v6; // rax

  v2 = entry->IndexHint;
  v3 = this->Entries.Data.Size;
  v4 = this;
  if ( v2 >= v3 || this->Entries.Data.Data[v2] != entry )
  {
    v2 = 0i64;
    if ( !v3 )
      return;
    v5 = this->Entries.Data.Data;
    while ( *v5 != entry )
    {
      ++v2;
      ++v5;
      if ( v2 >= v3 )
        return;
    }
    entry->IndexHint = v2;
  }
  v6 = (Scaleform::Render::Mesh *)(*(__int64 (**)(void))entry->pSourceNode->vfptr[1].gap8)();
  Scaleform::Render::Primitive::SetMesh(&v4->Prim, v2, v6);
}

// File Line: 91
// RVA: 0x9398A0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::ComplexPrimitiveBundle(Scaleform::Render::ComplexPrimitiveBundle *this)
{
  Scaleform::Render::ComplexPrimitiveBundle *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::Bundle};
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  v2 = (signed __int64)&v1->Instances;
  *(_OWORD *)v2 = 0ui64;
  *(_QWORD *)(v2 + 16) = 0i64;
}

// File Line: 94
// RVA: 0x949330
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::~ComplexPrimitiveBundle(Scaleform::Render::ComplexPrimitiveBundle *this)
{
  Scaleform::Render::ComplexPrimitiveBundle *v1; // rdi
  void **v2; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::Bundle};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  v2 = (void **)&this->Instances.Data.Data;
  Scaleform::ConstructorMov<Scaleform::Render::Primitive::MeshEntry>::DestructArray(
    (Scaleform::Render::Primitive::MeshEntry *)this->Instances.Data.Data,
    this->Instances.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v2);
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Entries.Data.Data);
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 98
// RVA: 0x96E460
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::Draw(Scaleform::Render::ComplexPrimitiveBundle *this, Scaleform::Render::HAL *hal)
{
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rbx
  Scaleform::Render::HAL *v4; // r14
  Scaleform::Render::ComplexPrimitiveBundle *v5; // rsi
  Scaleform::Render::RenderQueueItem::Interface *v6; // rbp
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rdx
  unsigned __int64 v10; // rcx
  _QWORD *v11; // rax
  Scaleform::Render::RenderQueueItem::Interface *v12; // [rsp+20h] [rbp-18h]
  unsigned __int64 v13; // [rsp+28h] [rbp-10h]

  v2 = this->Instances.Data.Size;
  v3 = 0i64;
  v4 = hal;
  v5 = this;
  if ( v2 )
  {
    v6 = (Scaleform::Render::RenderQueueItem::Interface *)&this->vfptr;
    do
    {
      v7 = v4->vfptr;
      v12 = v6;
      v13 = v3;
      v7[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v12);
      v8 = (signed __int64)&v5->Instances.Data.Data[v3];
      v9 = *(_QWORD *)(v8 + 8);
      v10 = v5->Instances.Data.Size - 1;
      if ( v3 < v10 )
      {
        v11 = (_QWORD *)(v8 + 24);
        do
        {
          if ( *v11 != v9 )
            break;
          ++v3;
          v11 += 2;
        }
        while ( v3 < v10 );
      }
      ++v3;
    }
    while ( v3 < v2 );
  }
}

// File Line: 111
// RVA: 0x995130
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::InsertEntry(Scaleform::Render::ComplexPrimitiveBundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::ComplexPrimitiveBundle *v5; // rsi
  Scaleform::Render::TreeCacheNode *v6; // rbx
  Scaleform::Render::Mesh *v7; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v8; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v9; // rbx
  bool v10; // zf
  __int64 v11; // rcx
  Scaleform::Render::Primitive::MeshEntry val; // [rsp+28h] [rbp-20h]

  v3 = entry;
  v4 = index;
  v5 = this;
  Scaleform::Render::Bundle::InsertEntry((Scaleform::Render::Bundle *)&this->vfptr, index, entry);
  v6 = v3->pSourceNode;
  v7 = (Scaleform::Render::Mesh *)(*(__int64 (__fastcall **)(Scaleform::Render::TreeCacheNode *))v6->vfptr[1].gap8)(v6);
  v8 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)v6[1].pMask;
  val.M.pHandle = v8;
  if ( v8 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v8->pHeader->RefCount;
  if ( v7 )
    _InterlockedExchangeAdd(&v7->RefCount, 1u);
  val.pMesh.pObject = v7;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Instances,
    v4,
    &val);
  if ( val.pMesh.pObject && !_InterlockedDecrement(&val.pMesh.pObject->RefCount) )
    val.pMesh.pObject->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)val.pMesh.pObject, 1u);
  if ( val.M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v9 = val.M.pHandle->pHeader;
    v10 = val.M.pHandle->pHeader->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
    {
      v11 = v9->DataPageOffset;
      *(_WORD *)((char *)&v9[1].RefCount + v11 + 2) += 16 * (unsigned __int8)v9->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v9[1].pHandle + v11))[5].pHeader += (unsigned __int8)v9->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v9->pHandle);
      v9->pHandle = 0i64;
    }
  }
}

// File Line: 123
// RVA: 0x9A98D0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::RemoveEntries(Scaleform::Render::ComplexPrimitiveBundle *this, unsigned __int64 index, unsigned __int64 count)
{
  Scaleform::Render::ComplexPrimitiveBundle *v3; // rsi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rdi

  v3 = this;
  v4 = count;
  v5 = index;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Instances,
    index,
    count);
  Scaleform::Render::Bundle::RemoveEntries((Scaleform::Render::Bundle *)&v3->vfptr, v5, v4);
}

// File Line: 129
// RVA: 0x9BF1F0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::UpdateMesh(Scaleform::Render::ComplexPrimitiveBundle *this, Scaleform::Render::BundleEntry *entry)
{
  unsigned __int64 v2; // rbx
  unsigned __int64 v3; // r8
  Scaleform::Render::BundleEntry **v4; // rax
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v5; // rbx
  __int64 v6; // rax
  Scaleform::Render::ComplexMesh *v7; // rdi
  Scaleform::Render::ComplexMesh *v8; // rcx

  v2 = entry->IndexHint;
  v3 = this->Entries.Data.Size;
  if ( v2 >= v3 || this->Entries.Data.Data[v2] != entry )
  {
    v2 = 0i64;
    if ( !v3 )
      return;
    v4 = this->Entries.Data.Data;
    while ( *v4 != entry )
    {
      ++v2;
      ++v4;
      if ( v2 >= v3 )
        return;
    }
    entry->IndexHint = v2;
  }
  v5 = &this->Instances.Data.Data[v2];
  v6 = (*(__int64 (**)(void))entry->pSourceNode->vfptr[1].gap8)();
  v7 = (Scaleform::Render::ComplexMesh *)v6;
  if ( v6 )
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 8), 1u);
  v8 = v5->pMesh.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) )
  {
    if ( v8 )
      v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
  }
  v5->pMesh.pObject = v7;
}

// File Line: 142
// RVA: 0x99F6F0
signed __int64 __fastcall Scaleform::Render::ComplexPrimitiveBundle::Prepare(Scaleform::Render::ComplexPrimitiveBundle *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp, bool waitForCache)
{
  Scaleform::Render::RenderQueueProcessor *v4; // rbx
  Scaleform::Render::RenderQueueItem *v5; // rdi

  v4 = qp;
  v5 = item;
  if ( qp->QueuePrepareFilter == QPF_All )
  {
    if ( !Scaleform::Render::MeshCache::PrepareComplexMesh(
            (Scaleform::Render::MeshCache *)qp->Caches.pCaches[0],
            *(Scaleform::Render::ComplexMesh **)(*(_QWORD *)&this->RefCount + 16i64 * (_QWORD)item->Data + 8),
            waitForCache)
      && v5 != v4->PrepareItemBuffer.pItem )
    {
      v4->PrepareItemBuffer.pItem = v5;
      return 1i64;
    }
    v4->PrepareItemBuffer.pItem = 0i64;
  }
  return 0i64;
}

// File Line: 173
// RVA: 0x96FDA0
void __fastcall Scaleform::Render::ComplexPrimitiveBundle::EmitToHAL(Scaleform::Render::ComplexPrimitiveBundle *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::RenderQueueItem *v3; // r10
  Scaleform::Render::RenderQueueProcessor *v4; // r11
  Scaleform::Render::ComplexPrimitiveBundle *v5; // rdx
  __int64 v6; // rax
  _BYTE *v7; // rbx
  signed __int64 v8; // rdi
  __int64 v9; // r8
  char *v10; // rcx
  unsigned __int64 v11; // rdx
  _QWORD *v12; // rax
  __int64 v13; // rdx
  __int64 v14; // [rsp+20h] [rbp-28h]
  __int64 v15; // [rsp+28h] [rbp-20h]
  __int64 v16; // [rsp+30h] [rbp-18h]

  v3 = item;
  v4 = qp;
  v5 = this;
  if ( qp->QueueEmitFilter == QPF_All )
  {
    v6 = *(_QWORD *)&this->RefCount;
    v7 = v3->Data;
    v8 = v6 + 16i64 * (_QWORD)v3->Data;
    if ( v3 != qp->PrepareItemBuffer.pItem )
    {
      if ( *(_QWORD *)(v8 + 8) )
      {
        v9 = *(_QWORD *)(v6 + 16i64 * (_QWORD)v3->Data + 8);
        v10 = (char *)v3->Data;
        v11 = (unsigned __int64)v5->Entries.Data.Data - 1;
        if ( (unsigned __int64)v7 < v11 )
        {
          v12 = (_QWORD *)(v8 + 24);
          do
          {
            if ( *v12 != v9 )
              break;
            ++v10;
            v12 += 2;
          }
          while ( (unsigned __int64)v10 < v11 );
        }
        v13 = *(_QWORD *)(v8 + 8);
        v14 = v8;
        v16 = 16i64;
        v15 = v10 - v7 + 1;
        ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64 *))v4->pHAL->vfptr[35].__vecDelDtor)(
          v4->pHAL,
          v13,
          &v14);
      }
    }
  }
}

// File Line: 199
// RVA: 0x93E4D0
void __fastcall Scaleform::Render::MaskBundle::MaskBundle(Scaleform::Render::MaskBundle *this)
{
  Scaleform::Render::MaskBundle *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]
  signed __int64 v3; // [rsp+58h] [rbp+20h]

  v1 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::MaskBundle::`vftable;
  v2 = (signed __int64)&v1->Prim;
  *(_QWORD *)v2 = &Scaleform::RefCountImplCore::`vftable;
  *(_DWORD *)(v2 + 8) = 1;
  *(_QWORD *)v2 = &Scaleform::RefCountImpl::`vftable;
  *(_QWORD *)v2 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  *(_QWORD *)v2 = &Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>::`vftable;
  v1->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  *(_QWORD *)v2 = &Scaleform::Render::MaskPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,67>};
  v1->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::MaskPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  v3 = (signed __int64)&v1->Prim.MaskAreas;
  *(_OWORD *)v3 = 0ui64;
  *(_QWORD *)(v3 + 16) = 0i64;
}

// File Line: 203
// RVA: 0x995300
void __fastcall Scaleform::Render::MaskBundle::InsertEntry(Scaleform::Render::MaskBundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::MaskBundle *v5; // rsi
  Scaleform::Render::MaskEffect *i; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rbx
  bool v9; // zf
  __int64 v10; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp+8h]

  v3 = entry;
  v4 = index;
  v5 = this;
  Scaleform::Render::Bundle::InsertEntry((Scaleform::Render::Bundle *)&this->vfptr, index, entry);
  for ( i = (Scaleform::Render::MaskEffect *)v3->pSourceNode->Effects.pEffect;
        i;
        i = (Scaleform::Render::MaskEffect *)i->pNext )
  {
    if ( i->vfptr->GetType((Scaleform::Render::CacheEffect *)&i->vfptr) == 4 )
      break;
  }
  v7 = Scaleform::Render::MaskEffect::GetBoundsMatrix(i, &result);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Prim.MaskAreas.Data,
    v4,
    v7);
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v8 = result.pHandle->pHeader;
    v9 = result.pHandle->pHeader->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
    {
      v10 = v8->DataPageOffset;
      *(_WORD *)((char *)&v8[1].RefCount + v10 + 2) += 16 * (unsigned __int8)v8->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[1].pHandle + v10))[5].pHeader += (unsigned __int8)v8->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v8->pHandle);
      v8->pHandle = 0i64;
    }
  }
}

// File Line: 212
// RVA: 0x9A9910
void __fastcall Scaleform::Render::MaskBundle::RemoveEntries(Scaleform::Render::MaskBundle *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::MaskBundle *v5; // rsi

  v3 = count;
  v4 = index;
  v5 = this;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Prim.MaskAreas.Data,
    (unsigned int)index,
    (unsigned int)count);
  Scaleform::Render::Bundle::RemoveEntries((Scaleform::Render::Bundle *)&v5->vfptr, v4, v3);
}

// File Line: 223
// RVA: 0x93BC40
void __fastcall Scaleform::Render::FilterBundle::FilterBundle(Scaleform::Render::FilterBundle *this, Scaleform::Render::FilterSet *filters, bool maskPresent)
{
  bool v3; // bl
  Scaleform::Render::FilterSet *v4; // rdi
  Scaleform::Render::FilterBundle *v5; // rsi

  v3 = maskPresent;
  v4 = filters;
  v5 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v5->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::FilterBundle::`vftable;
  Scaleform::Render::CacheablePrimitive::CacheablePrimitive(
    (Scaleform::Render::CacheablePrimitive *)&v5->Prim.vfptr,
    v3);
  v5->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  v5->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  if ( v4 )
    _InterlockedExchangeAdd(&v4->RefCount, 1u);
  v5->Prim.pFilters.pObject = v4;
}

// File Line: 227
// RVA: 0x995230
void __fastcall Scaleform::Render::FilterBundle::InsertEntry(Scaleform::Render::FilterBundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::FilterBundle *v5; // rsi
  Scaleform::Render::FilterEffect *i; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rbx
  bool v9; // zf
  __int64 v10; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp+8h]

  v3 = entry;
  v4 = index;
  v5 = this;
  Scaleform::Render::Bundle::InsertEntry((Scaleform::Render::Bundle *)&this->vfptr, index, entry);
  for ( i = (Scaleform::Render::FilterEffect *)v3->pSourceNode->Effects.pEffect;
        i;
        i = (Scaleform::Render::FilterEffect *)i->pNext )
  {
    if ( i->vfptr->GetType((Scaleform::Render::CacheEffect *)&i->vfptr) == 3 )
      break;
  }
  v7 = Scaleform::Render::FilterEffect::GetBoundsMatrix(i, &result);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Prim.PrimitiveArea.Data,
    v4,
    v7);
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v8 = result.pHandle->pHeader;
    v9 = result.pHandle->pHeader->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
    {
      v10 = v8->DataPageOffset;
      *(_WORD *)((char *)&v8[1].RefCount + v10 + 2) += 16 * (unsigned __int8)v8->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[1].pHandle + v10))[5].pHeader += (unsigned __int8)v8->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v8->pHandle);
      v8->pHandle = 0i64;
    }
  }
}

// File Line: 246
// RVA: 0x938EA0
void __fastcall Scaleform::Render::BlendModeBundle::BlendModeBundle(Scaleform::Render::BlendModeBundle *this, Scaleform::Render::BlendMode mode, bool maskPresent)
{
  bool v3; // di
  Scaleform::Render::BlendMode v4; // esi
  Scaleform::Render::BlendModeBundle *v5; // r14

  v3 = maskPresent;
  v4 = mode;
  v5 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v5->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::BlendModeBundle::`vftable;
  Scaleform::Render::CacheablePrimitive::CacheablePrimitive(
    (Scaleform::Render::CacheablePrimitive *)&v5->Prim.vfptr,
    v3);
  v5->Prim.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlendPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  v5->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::BlendPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  v5->Prim.BlendModeValue = v4;
}

// File Line: 250
// RVA: 0x994FF0
void __fastcall Scaleform::Render::BlendModeBundle::InsertEntry(Scaleform::Render::BlendModeBundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::BlendModeBundle *v5; // rsi
  Scaleform::Render::BlendModeEffect *i; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rbx
  bool v9; // zf
  __int64 v10; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+40h] [rbp+8h]

  v3 = entry;
  v4 = index;
  v5 = this;
  Scaleform::Render::Bundle::InsertEntry((Scaleform::Render::Bundle *)&this->vfptr, index, entry);
  for ( i = (Scaleform::Render::BlendModeEffect *)v3->pSourceNode->Effects.pEffect;
        i;
        i = (Scaleform::Render::BlendModeEffect *)i->pNext )
  {
    if ( i->vfptr->GetType((Scaleform::Render::CacheEffect *)&i->vfptr) == 1 )
      break;
  }
  v7 = Scaleform::Render::BlendModeEffect::GetBoundsMatrix(i, &result);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Prim.PrimitiveArea.Data,
    v4,
    v7);
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v8 = result.pHandle->pHeader;
    v9 = result.pHandle->pHeader->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
    {
      v10 = v8->DataPageOffset;
      *(_WORD *)((char *)&v8[1].RefCount + v10 + 2) += 16 * (unsigned __int8)v8->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v8[1].pHandle + v10))[5].pHeader += (unsigned __int8)v8->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v8->pHandle);
      v8->pHandle = 0i64;
    }
  }
}

// File Line: 258
// RVA: 0x9A9780
void __fastcall Scaleform::Render::FilterBundle::RemoveEntries(Scaleform::Render::FilterBundle *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::FilterBundle *v5; // rsi

  v3 = count;
  v4 = index;
  v5 = this;
  Scaleform::Render::CacheablePrimitive::Remove(
    (Scaleform::Render::CacheablePrimitive *)&this->Prim.vfptr,
    (unsigned int)index,
    (unsigned int)count);
  Scaleform::Render::Bundle::RemoveEntries((Scaleform::Render::Bundle *)&v5->vfptr, v4, v3);
}

// File Line: 269
// RVA: 0x946E60
void __fastcall Scaleform::Render::ViewMatrix3DBundle::ViewMatrix3DBundle(Scaleform::Render::ViewMatrix3DBundle *this, Scaleform::Render::Matrix3x4Ref<float> *pvm)
{
  Scaleform::Render::Matrix3x4Ref<float> *v2; // r14
  Scaleform::Render::ViewMatrix3DBundle *v3; // r12
  float v4; // eax
  float v5; // ecx
  float v6; // edx
  float v7; // er8
  float v8; // er9
  float v9; // er10
  float v10; // er11
  float v11; // ebx
  float v12; // edi
  float v13; // esi
  float v14; // ebp
  float v15; // er14
  signed __int64 v16; // [rsp+68h] [rbp+10h]

  v2 = pvm;
  v3 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v3->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ViewMatrix3DBundle::`vftable;
  v16 = (signed __int64)&v3->Prim;
  *(_QWORD *)v16 = &Scaleform::RefCountImplCore::`vftable;
  *(_DWORD *)(v16 + 8) = 1;
  *(_QWORD *)v16 = &Scaleform::RefCountImpl::`vftable;
  *(_QWORD *)v16 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  *(_QWORD *)v16 = &Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>::`vftable;
  v3->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  *(_QWORD *)v16 = &Scaleform::Render::ViewMatrix3DPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>};
  v3->Prim.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  memset(&v3->Prim.ViewMatrix, 0, 0x30ui64);
  v3->Prim.ViewMatrix.M[0][0] = 1.0;
  v3->Prim.ViewMatrix.M[1][1] = 1.0;
  v3->Prim.ViewMatrix.M[2][2] = 1.0;
  v3->Prim.bHasViewMatrix = 0;
  if ( v2 )
  {
    v4 = v2->M[0][0];
    v5 = v2->M[0][1];
    v6 = v2->M[0][2];
    v7 = v2->M[0][3];
    v8 = v2->M[1][0];
    v9 = v2->M[1][1];
    v10 = v2->M[1][2];
    v11 = v2->M[1][3];
    v12 = v2->M[2][0];
    v13 = v2->M[2][1];
    v14 = v2->M[2][2];
    v15 = v2->M[2][3];
    v3->Prim.ViewMatrix.M[0][0] = v4;
    v3->Prim.ViewMatrix.M[0][1] = v5;
    v3->Prim.ViewMatrix.M[0][2] = v6;
    v3->Prim.ViewMatrix.M[0][3] = v7;
    v3->Prim.ViewMatrix.M[1][0] = v8;
    v3->Prim.ViewMatrix.M[1][1] = v9;
    v3->Prim.ViewMatrix.M[1][2] = v10;
    v3->Prim.ViewMatrix.M[1][3] = v11;
    v3->Prim.ViewMatrix.M[2][0] = v12;
    v3->Prim.ViewMatrix.M[2][1] = v13;
    v3->Prim.ViewMatrix.M[2][2] = v14;
    v3->Prim.ViewMatrix.M[2][3] = v15;
    v3->Prim.bHasViewMatrix = 1;
  }
}

// File Line: 280
// RVA: 0x940B40
void __fastcall Scaleform::Render::ProjectionMatrix3DBundle::ProjectionMatrix3DBundle(Scaleform::Render::ProjectionMatrix3DBundle *this, Scaleform::Render::Matrix4x4Ref<float> *ppm)
{
  Scaleform::Render::Matrix4x4Ref<float> *v2; // r13
  Scaleform::Render::ProjectionMatrix3DBundle *v3; // rbx
  float v4; // edx
  float v5; // er8
  float v6; // er9
  float v7; // er10
  float v8; // er11
  float v9; // ebx
  float v10; // edi
  float v11; // esi
  float v12; // ebp
  float v13; // er14
  float v14; // er15
  float v15; // er12
  float v16; // er13
  signed __int64 v17; // [rsp+20h] [rbp-58h]
  Scaleform::Render::Matrix4x4Ref<float> *v18; // [rsp+88h] [rbp+10h]
  float v19; // [rsp+88h] [rbp+10h]
  float v20; // [rsp+90h] [rbp+18h]
  float v21; // [rsp+98h] [rbp+20h]

  v18 = ppm;
  v2 = ppm;
  v3 = this;
  Scaleform::Render::Bundle::Bundle((Scaleform::Render::Bundle *)&this->vfptr, 0i64);
  v3->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::ProjectionMatrix3DBundle::`vftable;
  v17 = (signed __int64)&v3->Prim;
  Scaleform::Render::ProjectionMatrix3DPrimitive::ProjectionMatrix3DPrimitive(&v3->Prim);
  if ( v2 )
  {
    v20 = v2->M[0][0];
    v21 = v2->M[0][1];
    v4 = v2->M[0][2];
    v5 = v2->M[0][3];
    v6 = v2->M[1][0];
    v7 = v2->M[1][1];
    v8 = v2->M[1][2];
    v9 = v2->M[1][3];
    v10 = v2->M[2][0];
    v11 = v2->M[2][1];
    v12 = v2->M[2][2];
    v13 = v2->M[2][3];
    v14 = v2->M[3][0];
    v15 = v2->M[3][1];
    v16 = v2->M[3][2];
    v19 = v18->M[3][3];
    *(float *)(v17 + 32) = v20;
    *(float *)(v17 + 36) = v21;
    *(float *)(v17 + 40) = v4;
    *(float *)(v17 + 44) = v5;
    *(float *)(v17 + 48) = v6;
    *(float *)(v17 + 52) = v7;
    *(float *)(v17 + 56) = v8;
    *(float *)(v17 + 60) = v9;
    *(float *)(v17 + 64) = v10;
    *(float *)(v17 + 68) = v11;
    *(float *)(v17 + 72) = v12;
    *(float *)(v17 + 76) = v13;
    *(float *)(v17 + 80) = v14;
    *(float *)(v17 + 84) = v15;
    *(float *)(v17 + 88) = v16;
    *(float *)(v17 + 92) = v19;
    *(_BYTE *)(v17 + 96) = 1;
  }
}

// File Line: 309
// RVA: 0x9BD0B0
bool __fastcall Scaleform::Render::SKI_Primitive::UpdateBundleEntry(Scaleform::Render::SKI_Primitive *this, void *d, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr, Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::TreeCacheRoot *v5; // r14
  Scaleform::Render::BundleEntry *v6; // rsi
  Scaleform::Render::PrimitiveFill *v7; // rbp
  Scaleform::Render::Bundle *v8; // rax
  __int64 v9; // rbx
  bool v10; // zf
  __int64 v12; // [rsp+80h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v13; // [rsp+88h] [rbp+20h]

  v13 = tr;
  v5 = tr;
  v6 = p;
  v7 = (Scaleform::Render::PrimitiveFill *)d;
  if ( !p->pBundle.pObject )
  {
    ((void (__fastcall *)(Scaleform::Render::SKI_Primitive *))Scaleform::Render::SKI_Primitive::Instance.vfptr->AddRef)(&Scaleform::Render::SKI_Primitive::Instance);
    LODWORD(v12) = 67;
    v8 = (Scaleform::Render::Bundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, __int64 *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        v5,
                                        168i64,
                                        &v12,
                                        -2i64);
    v9 = (__int64)v8;
    if ( v8 )
    {
      Scaleform::Render::Bundle::Bundle(v8, 0i64);
      *(_QWORD *)v9 = &Scaleform::Render::DrawableBundle::`vftable;
      *(_QWORD *)(v9 + 56) = v5;
      *(_QWORD *)(v9 + 64) = r;
      *(_QWORD *)v9 = &Scaleform::Render::PrimitiveBundle::`vftable;
      Scaleform::Render::Primitive::Primitive(
        (Scaleform::Render::Primitive *)(v9 + 72),
        *(Scaleform::Render::HAL **)(*(_QWORD *)(v9 + 64) + 80i64),
        v7);
    }
    else
    {
      v9 = 0i64;
    }
    v12 = v9;
    Scaleform::Render::BundleEntry::SetBundle(v6, (Scaleform::Render::Bundle *)v9, 0i64);
    if ( v9 )
    {
      v10 = (*(_DWORD *)(v9 + 8))-- == 1;
      if ( v10 )
        (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
    }
    Scaleform::Render::SKI_Primitive::Instance.vfptr->Release(
      (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Primitive::Instance,
      v7);
  }
  return v6->pBundle.pObject != 0i64;
}

// File Line: 320
// RVA: 0x96F2E0
void __fastcall Scaleform::Render::SKI_Primitive::DrawBundleEntry(Scaleform::Render::SKI_Primitive *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::Renderer2DImpl *a4)
{
  Scaleform::Render::Bundle *v4; // rcx
  signed __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // [rsp+20h] [rbp-18h]
  __int64 v9; // [rsp+28h] [rbp-10h]

  v4 = p->pBundle.pObject;
  if ( v4 )
  {
    if ( v4 == (Scaleform::Render::Bundle *)-72i64 )
      v5 = 0i64;
    else
      v5 = (signed __int64)&v4[1].Entries.Data.Policy;
    v6 = *(_QWORD *)&v4[1].RefCount;
    v8 = v5;
    v7 = *(_QWORD *)(v6 + 80);
    v9 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *, Scaleform::Render::BundleEntry *, Scaleform::Render::Renderer2DImpl *, signed __int64, _QWORD))(*(_QWORD *)v7 + 264i64))(
      v7,
      &v8,
      p,
      a4,
      v5,
      0i64);
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
void __fastcall Scaleform::Render::SKI_ComplexPrimitive::Release(Scaleform::Render::SKI_ComplexPrimitive *this, void *p)
{
  if ( p )
    (*(void (__fastcall **)(void *))(*(_QWORD *)p + 16i64))(p);
}

// File Line: 345
// RVA: 0x9BCE30
bool __fastcall Scaleform::Render::SKI_ComplexPrimitive::UpdateBundleEntry(Scaleform::Render::SKI_ComplexPrimitive *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::BundleEntry *v4; // rsi
  Scaleform::Render::ComplexPrimitiveBundle *v5; // rax
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
    v5 = (Scaleform::Render::ComplexPrimitiveBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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

// File Line: 356
// RVA: 0x96F290
void __fastcall Scaleform::Render::SKI_ComplexPrimitive::DrawBundleEntry(Scaleform::Render::SKI_ComplexPrimitive *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::Render::ComplexPrimitiveBundle *v4; // rcx

  v4 = (Scaleform::Render::ComplexPrimitiveBundle *)p->pBundle.pObject;
  if ( v4 )
    Scaleform::Render::ComplexPrimitiveBundle::Draw(v4, r->pHal.pObject);
}

// File Line: 366
// RVA: 0x159C8B0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Primitive::Instance__()
{
  Scaleform::Render::SKI_Primitive::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Primitive::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_Primitive::Instance__);
}

// File Line: 367
// RVA: 0x159C5A0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Primitive::Instance3D__()
{
  Scaleform::Render::SKI_Primitive::Instance3D.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Primitive::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_Primitive::Instance3D__);
}

// File Line: 368
// RVA: 0x159C850
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ComplexPrimitive::Instance__()
{
  Scaleform::Render::SKI_ComplexPrimitive::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ComplexPrimitive::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_ComplexPrimitive::Instance__);
}

// File Line: 369
// RVA: 0x159C570
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ComplexPrimitive::Instance3D__()
{
  Scaleform::Render::SKI_ComplexPrimitive::Instance3D.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ComplexPrimitive::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_ComplexPrimitive::Instance3D__);
}

// File Line: 401
// RVA: 0x9BD000
bool __fastcall Scaleform::Render::SKI_MaskStart::UpdateBundleEntry(Scaleform::Render::SKI_MaskStart *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::BundleEntry *v4; // rsi
  Scaleform::Render::MaskBundle *v5; // rax
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
    v5 = (Scaleform::Render::MaskBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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

// File Line: 411
// RVA: 0x98AE90
_BOOL8 __fastcall Scaleform::Render::SKI_MaskStart::GetRangeTransition(Scaleform::Render::SKI_MaskStart *this, void *__formal, Scaleform::Render::SortKey *other)
{
  return other->pImpl->Type == 5;
}

// File Line: 442
// RVA: 0x96FF30
void __fastcall Scaleform::Render::SKI_MaskEnd::RQII_EndMask::EmitToHAL(Scaleform::Render::SKI_MaskEnd::RQII_EndMask *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  int v3; // eax
  Scaleform::Render::HAL *v4; // rcx

  if ( qp->QueueEmitFilter == QPF_All )
  {
    v3 = (int)item->Data;
    v4 = qp->pHAL;
    if ( v3 == 1 )
    {
      ((void (*)(void))v4->vfptr[37].__vecDelDtor)();
    }
    else if ( v3 == 2 )
    {
      ((void (*)(void))v4->vfptr[38].__vecDelDtor)();
    }
  }
}

// File Line: 459
// RVA: 0x98AE70
signed __int64 __fastcall Scaleform::Render::SKI_MaskEnd::GetRangeTransition(Scaleform::Render::SKI_MaskEnd *this, void *data, Scaleform::Render::SortKey *other)
{
  signed __int64 result; // rax

  result = 0i64;
  if ( other->pImpl->Type == 5 )
    result = 2i64;
  return result;
}

// File Line: 471
// RVA: 0x96F2B0
void __fastcall Scaleform::Render::SKI_MaskEnd::DrawBundleEntry(Scaleform::Render::SKI_MaskEnd *this, void *data, Scaleform::Render::BundleEntry *__formal, Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::HAL *v4; // rcx
  Scaleform::Render::SKI_MaskEnd::RQII_EndMask *v5; // [rsp+20h] [rbp-18h]
  void *v6; // [rsp+28h] [rbp-10h]

  v4 = r2d->pHal.pObject;
  v6 = data;
  v5 = &Scaleform::Render::SKI_MaskEnd::RQII_Instance;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::SKI_MaskEnd::RQII_EndMask **, Scaleform::Render::BundleEntry *))v4->vfptr[33].__vecDelDtor)(
    v4,
    &v5,
    __formal);
}

// File Line: 480
// RVA: 0x159C330
__int64 dynamic_initializer_for__Scaleform::Render::SKI_MaskStart::Combinable_Instance__()
{
  Scaleform::Render::SKI_MaskStart::Combinable_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_MaskStart::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_MaskStart::Combinable_Instance__);
}

// File Line: 481
// RVA: 0x159C880
__int64 dynamic_initializer_for__Scaleform::Render::SKI_MaskEnd::Instance__()
{
  Scaleform::Render::SKI_MaskEnd::Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_MaskEnd::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_MaskEnd::Instance__);
}

// File Line: 483
// RVA: 0x159CBB0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_MaskEnd::RQII_Instance__()
{
  Scaleform::Render::SKI_MaskEnd::RQII_Instance.vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::SKI_MaskEnd::RQII_EndMask::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_MaskEnd::RQII_Instance__);
}

// File Line: 504
// RVA: 0x9E8E00
bool __fastcall Scaleform::Render::isMaskPresentInsideRange(Scaleform::Render::BundleIterator *ibundles, Scaleform::Render::SortKeyType startKey, Scaleform::Render::SortKeyType endKey)
{
  Scaleform::Render::BundleEntry *v3; // r9
  int v4; // eax
  Scaleform::Render::SortKeyType v5; // er11
  Scaleform::Render::SortKeyType v6; // edx

  v3 = ibundles->pFirst;
  v4 = 0;
  v5 = startKey;
  if ( ibundles->pFirst )
  {
    while ( v4 != 1 || (unsigned int)(v3->Key.pImpl->Type - 3) > 2 )
    {
      v6 = v3->Key.pImpl->Type;
      if ( v6 == endKey )
      {
        if ( --v4 <= 0 )
          goto LABEL_6;
      }
      else if ( v6 == v5 )
      {
        ++v4;
      }
      if ( v3 != ibundles->pLast )
      {
        v3 = v3->pNextPattern;
        if ( v3 )
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
signed __int64 __fastcall Scaleform::Render::SKI_BlendMode::GetRangeTransition(Scaleform::Render::SKI_BlendMode *this, void *__formal, Scaleform::Render::SortKey *other)
{
  signed __int64 result; // rax

  if ( other->pImpl->Type != 7 || this->Type != 6 )
    result = 0i64;
  else
    result = 2i64;
  return result;
}

// File Line: 557
// RVA: 0x9BCD50
bool __fastcall Scaleform::Render::SKI_BlendMode::UpdateBundleEntry(Scaleform::Render::SKI_BlendMode *this, void *d, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr, Scaleform::Render::Renderer2DImpl *__formal, Scaleform::Render::BundleIterator *ibundles)
{
  Scaleform::Render::BundleEntry *v6; // rsi
  unsigned int v7; // ebx
  Scaleform::Render::BlendModeBundle *v8; // rbp
  signed int v9; // eax
  bool v10; // al
  Scaleform::Render::Bundle *v11; // rax
  Scaleform::Render::Bundle *v12; // rbx
  bool v13; // zf
  Scaleform::Render::Bundle *v15; // [rsp+60h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v16; // [rsp+68h] [rbp+20h]

  v16 = tr;
  v6 = p;
  v7 = (unsigned int)d;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v15) = 67;
    v8 = (Scaleform::Render::BlendModeBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 tr,
                                                 144i64,
                                                 &v15,
                                                 -2i64);
    if ( v8 )
    {
      if ( v7 <= 0xE && (v9 = 24804, _bittest(&v9, v7)) )
        v10 = Scaleform::Render::isMaskPresentInsideRange(ibundles, SortKey_BlendModeStart, SortKey_BlendModeEnd);
      else
        v10 = 0;
      Scaleform::Render::BlendModeBundle::BlendModeBundle(v8, (Scaleform::Render::BlendMode)v7, v10);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v15 = v12;
    Scaleform::Render::BundleEntry::SetBundle(v6, v12, 0i64);
    if ( v12 )
    {
      v13 = v12->RefCount-- == 1;
      if ( v13 )
        v12->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v12->vfptr, 1u);
    }
  }
  return v6->pBundle.pObject != 0i64;
}

// File Line: 571
// RVA: 0x96F3C0
void __fastcall Scaleform::Render::SKI_Filter::DrawBundleEntry(Scaleform::Render::SKI_UserData *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::Bundle *v4; // rcx
  Scaleform::Render::HAL *v5; // r8
  signed __int64 v6; // rcx
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  __int64 v8; // [rsp+20h] [rbp-18h]
  __int64 v9; // [rsp+28h] [rbp-10h]

  v4 = p->pBundle.pObject;
  if ( v4 )
  {
    v5 = r2d->pHal.pObject;
    if ( v4 == (Scaleform::Render::Bundle *)-56i64 )
      v6 = 0i64;
    else
      v6 = (signed __int64)&v4[1].Entries;
    v7 = v5->vfptr;
    v8 = v6;
    v9 = 0i64;
    v7[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v8);
  }
}

// File Line: 583
// RVA: 0x159CC10
__int64 dynamic_initializer_for__Scaleform::Render::SKI_BlendMode::Start_Instance__()
{
  Scaleform::Render::SKI_BlendMode::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_BlendMode::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_BlendMode::Start_Instance__);
}

// File Line: 584
// RVA: 0x159CBE0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_BlendMode::StartCacheable_Instance__()
{
  Scaleform::Render::SKI_BlendMode::StartCacheable_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_BlendMode::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_BlendMode::StartCacheable_Instance__);
}

// File Line: 585
// RVA: 0x159C360
__int64 dynamic_initializer_for__Scaleform::Render::SKI_BlendMode::End_Instance__()
{
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_BlendMode::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_BlendMode::End_Instance__);
}

// File Line: 620
// RVA: 0x98AE50
signed __int64 __fastcall Scaleform::Render::SKI_Filter::GetRangeTransition(Scaleform::Render::SKI_Filter *this, void *__formal, Scaleform::Render::SortKey *other)
{
  signed __int64 result; // rax

  if ( other->pImpl->Type != 9 || this->Type != 8 )
    result = 0i64;
  else
    result = 2i64;
  return result;
}

// File Line: 629
// RVA: 0x9BCEE0
bool __fastcall Scaleform::Render::SKI_Filter::UpdateBundleEntry(Scaleform::Render::SKI_Filter *this, void *d, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr, Scaleform::Render::Renderer2DImpl *__formal, Scaleform::Render::BundleIterator *ibundles)
{
  Scaleform::Render::BundleEntry *v6; // rsi
  Scaleform::Render::FilterSet *v7; // rbx
  Scaleform::Render::FilterBundle *v8; // r11
  bool v9; // r10
  Scaleform::Render::BundleEntry *v10; // rdx
  int v11; // ecx
  Scaleform::Render::SortKeyType v12; // er8
  Scaleform::Render::SortKeyType v13; // er8
  Scaleform::Render::Bundle *v14; // rax
  Scaleform::Render::Bundle *v15; // rbx
  bool v16; // zf
  Scaleform::Render::Bundle *v18; // [rsp+50h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v19; // [rsp+58h] [rbp+20h]

  v19 = tr;
  v6 = p;
  v7 = (Scaleform::Render::FilterSet *)d;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v18) = 67;
    v8 = (Scaleform::Render::FilterBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              tr,
                                              144i64,
                                              &v18,
                                              -2i64);
    if ( v8 )
    {
      v9 = 0;
      v10 = ibundles->pFirst;
      v11 = 0;
      while ( v10 )
      {
        if ( v11 == 1 )
        {
          v12 = v10->Key.pImpl->Type;
          if ( v12 == 4 || v12 == 5 || v12 == 3 )
          {
            v9 = 1;
            break;
          }
        }
        v13 = v10->Key.pImpl->Type;
        if ( v13 == 9 )
        {
          if ( --v11 <= 0 )
            break;
        }
        else if ( v13 == 8 )
        {
          ++v11;
        }
        if ( v10 == ibundles->pLast )
          break;
        v10 = v10->pNextPattern;
      }
      Scaleform::Render::FilterBundle::FilterBundle(v8, v7, v9);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    v18 = v15;
    Scaleform::Render::BundleEntry::SetBundle(v6, v15, 0i64);
    if ( v15 )
    {
      v16 = v15->RefCount-- == 1;
      if ( v16 )
        v15->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v15->vfptr, 1u);
    }
  }
  return v6->pBundle.pObject != 0i64;
}

// File Line: 652
// RVA: 0x159CC40
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Filter::Start_Instance__()
{
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Filter::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_Filter::Start_Instance__);
}

// File Line: 653
// RVA: 0x159C390
__int64 dynamic_initializer_for__Scaleform::Render::SKI_Filter::End_Instance__()
{
  Scaleform::Render::SKI_Filter::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_Filter::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_Filter::End_Instance__);
}

// File Line: 679
// RVA: 0x98AEE0
signed __int64 __fastcall Scaleform::Render::SKI_ViewMatrix3D::GetRangeTransition(Scaleform::Render::SKI_ViewMatrix3D *this, void *__formal, Scaleform::Render::SortKey *other)
{
  signed __int64 result; // rax

  if ( other->pImpl->Type != 11 || this->Type != 10 )
    result = 0i64;
  else
    result = 2i64;
  return result;
}

// File Line: 687
// RVA: 0x9BD420
bool __fastcall Scaleform::Render::SKI_ViewMatrix3D::UpdateBundleEntry(Scaleform::Render::SKI_ViewMatrix3D *this, void *d, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::BundleEntry *v4; // rsi
  Scaleform::Render::Matrix3x4Ref<float> *v5; // rbx
  Scaleform::Render::ViewMatrix3DBundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rax
  Scaleform::Render::Bundle *v8; // rbx
  bool v9; // zf
  Scaleform::Render::Bundle *v11; // [rsp+50h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v12; // [rsp+58h] [rbp+20h]

  v12 = tr;
  v4 = p;
  v5 = (Scaleform::Render::Matrix3x4Ref<float> *)d;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v11) = 67;
    v6 = (Scaleform::Render::ViewMatrix3DBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    tr,
                                                    160i64,
                                                    &v11,
                                                    -2i64);
    if ( v6 )
    {
      Scaleform::Render::ViewMatrix3DBundle::ViewMatrix3DBundle(v6, v5);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v11 = v8;
    Scaleform::Render::BundleEntry::SetBundle(v4, v8, 0i64);
    if ( v8 )
    {
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        v8->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, 1u);
    }
  }
  return v4->pBundle.pObject != 0i64;
}

// File Line: 709
// RVA: 0x159CCF0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ViewMatrix3D::Start_Instance__()
{
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ViewMatrix3D::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_ViewMatrix3D::Start_Instance__);
}

// File Line: 710
// RVA: 0x159C440
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ViewMatrix3D::End_Instance__()
{
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ViewMatrix3D::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_ViewMatrix3D::End_Instance__);
}

// File Line: 736
// RVA: 0x98AEA0
signed __int64 __fastcall Scaleform::Render::SKI_ProjectionMatrix3D::GetRangeTransition(Scaleform::Render::SKI_ProjectionMatrix3D *this, void *__formal, Scaleform::Render::SortKey *other)
{
  signed __int64 result; // rax

  if ( other->pImpl->Type != 13 || this->Type != 12 )
    result = 0i64;
  else
    result = 2i64;
  return result;
}

// File Line: 744
// RVA: 0x9BD1E0
bool __fastcall Scaleform::Render::SKI_ProjectionMatrix3D::UpdateBundleEntry(Scaleform::Render::SKI_ProjectionMatrix3D *this, void *d, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::BundleEntry *v4; // rsi
  Scaleform::Render::Matrix4x4Ref<float> *v5; // rbx
  Scaleform::Render::ProjectionMatrix3DBundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rax
  Scaleform::Render::Bundle *v8; // rbx
  bool v9; // zf
  Scaleform::Render::Bundle *v11; // [rsp+50h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v12; // [rsp+58h] [rbp+20h]

  v12 = tr;
  v4 = p;
  v5 = (Scaleform::Render::Matrix4x4Ref<float> *)d;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v11) = 67;
    v6 = (Scaleform::Render::ProjectionMatrix3DBundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, Scaleform::Render::Bundle **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          tr,
                                                          176i64,
                                                          &v11,
                                                          -2i64);
    if ( v6 )
    {
      Scaleform::Render::ProjectionMatrix3DBundle::ProjectionMatrix3DBundle(v6, v5);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v11 = v8;
    Scaleform::Render::BundleEntry::SetBundle(v4, v8, 0i64);
    if ( v8 )
    {
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        v8->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, 1u);
    }
  }
  return v4->pBundle.pObject != 0i64;
}

// File Line: 754
// RVA: 0x96F330
void __fastcall Scaleform::Render::SKI_ProjectionMatrix3D::DrawBundleEntry(Scaleform::Render::SKI_ViewMatrix3D *this, void *__formal, Scaleform::Render::BundleEntry *p, Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::Bundle *v4; // rcx
  Scaleform::Render::HAL *v5; // r8
  signed __int64 v6; // rcx
  Scaleform::RefCountImplCoreVtbl *v7; // rax
  __int64 v8; // [rsp+20h] [rbp-18h]
  __int64 v9; // [rsp+28h] [rbp-10h]

  v4 = p->pBundle.pObject;
  if ( v4 )
  {
    v5 = r2d->pHal.pObject;
    if ( v4 == (Scaleform::Render::Bundle *)-64i64 )
      v6 = 0i64;
    else
      v6 = (signed __int64)&v4[1].Entries.Data.Size;
    v7 = v5->vfptr;
    v8 = v6;
    v9 = 0i64;
    v7[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v8);
  }
}

// File Line: 766
// RVA: 0x159CC80
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance__()
{
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ProjectionMatrix3D::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance__);
}

// File Line: 767
// RVA: 0x159C3D0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance__()
{
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_ProjectionMatrix3D::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance__);
}

// File Line: 794
// RVA: 0x98AEC0
signed __int64 __fastcall Scaleform::Render::SKI_UserData::GetRangeTransition(Scaleform::Render::SKI_UserData *this, void *__formal, Scaleform::Render::SortKey *other)
{
  signed __int64 result; // rax

  if ( other->pImpl->Type != 15 || this->Type != 14 )
    result = 0i64;
  else
    result = 2i64;
  return result;
}

// File Line: 802
// RVA: 0x9BD350
bool __fastcall Scaleform::Render::SKI_UserData::UpdateBundleEntry(Scaleform::Render::SKI_UserData *this, void *d, Scaleform::Render::BundleEntry *p, Scaleform::Render::TreeCacheRoot *tr)
{
  Scaleform::Render::BundleEntry *v4; // rsi
  Scaleform::Render::UserDataState::Data *v5; // rbp
  Scaleform::Render::Bundle *v6; // rax
  __int64 v7; // rbx
  bool v8; // zf
  __int64 v10; // [rsp+60h] [rbp+18h]
  Scaleform::Render::TreeCacheRoot *v11; // [rsp+68h] [rbp+20h]

  v11 = tr;
  v4 = p;
  v5 = (Scaleform::Render::UserDataState::Data *)d;
  if ( !p->pBundle.pObject )
  {
    LODWORD(v10) = 67;
    v6 = (Scaleform::Render::Bundle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheRoot *, signed __int64, __int64 *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
      Scaleform::Render::UserDataPrimitive::UserDataPrimitive((Scaleform::Render::UserDataPrimitive *)(v7 + 56), v5);
    }
    else
    {
      v7 = 0i64;
    }
    v10 = v7;
    Scaleform::Render::BundleEntry::SetBundle(v4, (Scaleform::Render::Bundle *)v7, 0i64);
    if ( v7 )
    {
      v8 = (*(_DWORD *)(v7 + 8))-- == 1;
      if ( v8 )
        (**(void (__fastcall ***)(__int64, signed __int64))v7)(v7, 1i64);
    }
  }
  return v4->pBundle.pObject != 0i64;
}

// File Line: 823
// RVA: 0x952D00
char __fastcall Scaleform::Render::SKI_UserData::AcceptMatch(Scaleform::Render::SKI_UserData *this, void *d0, void *d1)
{
  if ( d0 != d1 )
    return 0;
  if ( !d0 )
    return 1;
  if ( *((_BYTE *)d0 + 32) & 4 && *((_BYTE *)d0 + 28) )
    return 0;
  return 1;
}

// File Line: 837
// RVA: 0x159CCB0
__int64 dynamic_initializer_for__Scaleform::Render::SKI_UserData::Start_Instance__()
{
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_UserData::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_UserData::Start_Instance__);
}

// File Line: 838
// RVA: 0x159C400
__int64 dynamic_initializer_for__Scaleform::Render::SKI_UserData::End_Instance__()
{
  Scaleform::Render::SKI_UserData::End_Instance.vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SKI_UserData::`vftable;
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SKI_UserData::End_Instance__);
}

