// File Line: 164
// RVA: 0x94CD80
void __fastcall Scaleform::Render::SortKeyInterface::~SortKeyInterface(Scaleform::Render::SortKeyInterface *this)
{
  this->vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SortKeyInterface::`vftable;
}

// File Line: 181
// RVA: 0x9549A0
void __fastcall Scaleform::Render::SortKeyInterface_RefCountImpl::AddRef(
        Scaleform::Render::SortKeyInterface_RefCountImpl *this,
        volatile signed __int32 *p)
{
  if ( p )
    _InterlockedExchangeAdd(p + 2, 1u);
}

// File Line: 182
// RVA: 0x9A7D60
void __fastcall Scaleform::Render::SortKeyInterface_RefCountImpl::Release(
        Scaleform::Render::SortKeyInterface_RefCountImpl *this,
        volatile signed __int32 *p)
{
  if ( p )
  {
    if ( !_InterlockedDecrement(p + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, __int64))p)(p, 1i64);
  }
}

// File Line: 212
// RVA: 0x94CD70
void __fastcall Scaleform::Render::SortKey::~SortKey(Scaleform::Render::SortKey *this)
{
  this->pImpl->vfptr->Release(this->pImpl, this->Data);
}

// File Line: 275
// RVA: 0x99A750
bool __fastcall Scaleform::Render::SortKey::MatchSingleItemOverlap(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKey *other)
{
  unsigned int Flags; // r8d

  Flags = this->pImpl->Flags;
  if ( (Flags & 0x8000) != 0 )
    return 0;
  return this->Data == other->Data && this->pImpl == other->pImpl && (Flags & 0x4000) != 0;
}

// File Line: 532
// RVA: 0x939460
void __fastcall Scaleform::Render::Bundle::Bundle(Scaleform::Render::Bundle *this, Scaleform::Render::BundleEntry *top)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  this->Entries.Data.Data = 0i64;
  this->Entries.Data.Size = 0i64;
  this->Entries.Data.Policy.Capacity = 0i64;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, top);
  this->NeedUpdate = 1;
}

// File Line: 539
// RVA: 0x948EC0
void __fastcall Scaleform::Render::Bundle::~Bundle(Scaleform::Render::Bundle *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 567
// RVA: 0x948F10
void __fastcall Scaleform::Render::BundleEntry::~BundleEntry(Scaleform::Render::BundleEntry *this)
{
  Scaleform::Render::Bundle *pObject; // rax
  Scaleform::Render::Bundle *v3; // rdi
  unsigned __int64 Size; // rcx
  unsigned __int64 IndexHint; // rdx
  Scaleform::Render::BundleEntry **Data; // rax
  bool v7; // zf
  Scaleform::Render::Bundle *v8; // rcx

  if ( !this->pBundle.pObject )
    goto LABEL_16;
  pObject = this->pBundle.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v3 = this->pBundle.pObject;
  Size = v3->Entries.Data.Size;
  IndexHint = this->IndexHint;
  if ( IndexHint < Size && v3->Entries.Data.Data[IndexHint] == this )
    goto LABEL_12;
  IndexHint = 0i64;
  if ( Size )
  {
    Data = v3->Entries.Data.Data;
    while ( *Data != this )
    {
      ++IndexHint;
      ++Data;
      if ( IndexHint >= Size )
        goto LABEL_13;
    }
    this->IndexHint = IndexHint;
LABEL_12:
    ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, __int64))v3->vfptr[2].__vecDelDtor)(
      v3,
      IndexHint,
      1i64);
  }
LABEL_13:
  if ( v3 )
  {
    v7 = v3->RefCount-- == 1;
    if ( v7 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
LABEL_16:
  v8 = this->pBundle.pObject;
  if ( v8 )
  {
    v7 = v8->RefCount-- == 1;
    if ( v7 )
      v8->vfptr->__vecDelDtor(v8, 1u);
  }
  this->Key.pImpl->vfptr->Release(this->Key.pImpl, this->Key.Data);
}

// File Line: 576
// RVA: 0x9AE800
void __fastcall Scaleform::Render::BundleEntry::SetBundle(
        Scaleform::Render::BundleEntry *this,
        Scaleform::Render::Bundle *b,
        unsigned __int64 indexHint)
{
  unsigned __int16 v3; // bp
  Scaleform::Render::Bundle *pObject; // rax
  Scaleform::Render::Bundle *v7; // rdi
  unsigned __int64 Size; // rcx
  unsigned __int64 v9; // rdx
  Scaleform::Render::BundleEntry **Data; // rax
  bool v11; // zf
  Scaleform::Render::Bundle *v12; // rcx

  v3 = indexHint;
  pObject = this->pBundle.pObject;
  if ( !pObject || pObject == b )
    goto LABEL_14;
  ++pObject->RefCount;
  v7 = this->pBundle.pObject;
  Size = v7->Entries.Data.Size;
  v9 = this->IndexHint;
  if ( v9 >= Size || v7->Entries.Data.Data[v9] != this )
  {
    v9 = 0i64;
    if ( !Size )
      goto LABEL_12;
    Data = v7->Entries.Data.Data;
    while ( *Data != this )
    {
      ++v9;
      ++Data;
      if ( v9 >= Size )
        goto LABEL_12;
    }
    this->IndexHint = v9;
  }
  ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, __int64))v7->vfptr[2].__vecDelDtor)(v7, v9, 1i64);
LABEL_12:
  v11 = v7->RefCount-- == 1;
  if ( v11 )
    v7->vfptr->__vecDelDtor(v7, 1u);
LABEL_14:
  if ( b )
    ++b->RefCount;
  v12 = this->pBundle.pObject;
  if ( v12 )
  {
    v11 = v12->RefCount-- == 1;
    if ( v11 )
      v12->vfptr->__vecDelDtor(v12, 1u);
  }
  this->pBundle.pObject = b;
  this->IndexHint = v3;
}

// File Line: 587
// RVA: 0x960320
void __fastcall Scaleform::Render::BundleEntry::ClearBundle(Scaleform::Render::BundleEntry *this)
{
  Scaleform::Render::Bundle *pObject; // rax
  Scaleform::Render::Bundle *v3; // rdi
  unsigned __int64 Size; // rcx
  unsigned __int64 IndexHint; // rdx
  Scaleform::Render::BundleEntry **Data; // rax
  bool v7; // zf
  Scaleform::Render::Bundle *v8; // rcx

  pObject = this->pBundle.pObject;
  if ( !pObject )
    goto LABEL_13;
  ++pObject->RefCount;
  v3 = this->pBundle.pObject;
  Size = v3->Entries.Data.Size;
  IndexHint = this->IndexHint;
  if ( IndexHint >= Size || v3->Entries.Data.Data[IndexHint] != this )
  {
    IndexHint = 0i64;
    if ( !Size )
      goto LABEL_11;
    Data = v3->Entries.Data.Data;
    while ( *Data != this )
    {
      ++IndexHint;
      ++Data;
      if ( IndexHint >= Size )
        goto LABEL_11;
    }
    this->IndexHint = IndexHint;
  }
  ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, __int64))v3->vfptr[2].__vecDelDtor)(
    v3,
    IndexHint,
    1i64);
LABEL_11:
  v7 = v3->RefCount-- == 1;
  if ( v7 )
    v3->vfptr->__vecDelDtor(v3, 1u);
LABEL_13:
  v8 = this->pBundle.pObject;
  if ( v8 )
  {
    v7 = v8->RefCount-- == 1;
    if ( v7 )
      v8->vfptr->__vecDelDtor(v8, 1u);
  }
  this->pBundle.pObject = 0i64;
  this->IndexHint = 0;
}

