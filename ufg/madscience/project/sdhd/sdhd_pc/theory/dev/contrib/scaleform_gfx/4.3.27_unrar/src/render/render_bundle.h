// File Line: 164
// RVA: 0x94CD80
void __fastcall Scaleform::Render::SortKeyInterface::~SortKeyInterface(Scaleform::Render::SortKeyInterface *this)
{
  this->vfptr = (Scaleform::Render::SortKeyInterfaceVtbl *)&Scaleform::Render::SortKeyInterface::`vftable;
}

// File Line: 181
// RVA: 0x9549A0
void __fastcall Scaleform::Render::SortKeyInterface_RefCountImpl::AddRef(Scaleform::Render::SortKeyInterface_RefCountImpl *this, void *p)
{
  if ( p )
    _InterlockedExchangeAdd((volatile signed __int32 *)p + 2, 1u);
}

// File Line: 182
// RVA: 0x9A7D60
void __fastcall Scaleform::Render::SortKeyInterface_RefCountImpl::Release(Scaleform::Render::SortKeyInterface_RefCountImpl *this, void *p)
{
  if ( p )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)p + 2) )
      (**(void (__fastcall ***)(void *, signed __int64))p)(p, 1i64);
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
char __fastcall Scaleform::Render::SortKey::MatchSingleItemOverlap(Scaleform::Render::SortKey *this, Scaleform::Render::SortKey *other)
{
  unsigned int v2; // er8

  v2 = this->pImpl->Flags;
  if ( _bittest((const signed int *)&v2, 0xFu) )
    return 0;
  if ( *(_OWORD *)this == *(_OWORD *)other && _bittest((const signed int *)&v2, 0xEu) )
    return 1;
  return 0;
}

// File Line: 532
// RVA: 0x939460
void __fastcall Scaleform::Render::Bundle::Bundle(Scaleform::Render::Bundle *this, Scaleform::Render::BundleEntry *top)
{
  Scaleform::Render::Bundle *v2; // rbx
  Scaleform::ArrayLH<Scaleform::Render::BundleEntry *,2,Scaleform::ArrayDefaultPolicy> *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  v3 = &this->Entries;
  *(_OWORD *)&v3->Data.Data = 0ui64;
  v3->Data.Policy.Capacity = 0i64;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, top);
  v2->NeedUpdate = 1;
}

// File Line: 539
// RVA: 0x948EC0
void __fastcall Scaleform::Render::Bundle::~Bundle(Scaleform::Render::Bundle *this)
{
  Scaleform::Render::Bundle *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Bundle::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 567
// RVA: 0x948F10
void __fastcall Scaleform::Render::BundleEntry::~BundleEntry(Scaleform::Render::BundleEntry *this)
{
  Scaleform::Render::BundleEntry *v1; // rbx
  Scaleform::Render::Bundle *v2; // rax
  Scaleform::Render::Bundle *v3; // rdi
  Scaleform::Render::Bundle *v4; // r9
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rdx
  Scaleform::Render::BundleEntry **v7; // rax
  bool v8; // zf
  Scaleform::Render::Bundle *v9; // rcx

  v1 = this;
  if ( !this->pBundle.pObject )
    goto LABEL_16;
  v2 = this->pBundle.pObject;
  if ( v2 )
    ++v2->RefCount;
  v3 = this->pBundle.pObject;
  v4 = this->pBundle.pObject;
  v5 = v4->Entries.Data.Size;
  v6 = v1->IndexHint;
  if ( v6 < v5 && v4->Entries.Data.Data[v6] == v1 )
    goto LABEL_12;
  v6 = 0i64;
  if ( v5 )
  {
    v7 = v4->Entries.Data.Data;
    while ( *v7 != v1 )
    {
      ++v6;
      ++v7;
      if ( v6 >= v5 )
        goto LABEL_13;
    }
    v1->IndexHint = v6;
LABEL_12:
    ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, signed __int64))v4->vfptr[2].__vecDelDtor)(
      v4,
      v6,
      1i64);
  }
LABEL_13:
  if ( v3 )
  {
    v8 = v3->RefCount-- == 1;
    if ( v8 )
      v3->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, 1u);
  }
LABEL_16:
  v9 = v1->pBundle.pObject;
  if ( v9 )
  {
    v8 = v9->RefCount-- == 1;
    if ( v8 )
      v9->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v9->vfptr, 1u);
  }
  v1->Key.pImpl->vfptr->Release(v1->Key.pImpl, v1->Key.Data);
}

// File Line: 576
// RVA: 0x9AE800
void __fastcall Scaleform::Render::BundleEntry::SetBundle(Scaleform::Render::BundleEntry *this, Scaleform::Render::Bundle *b, unsigned __int64 indexHint)
{
  unsigned __int16 v3; // bp
  Scaleform::Render::Bundle *v4; // rsi
  Scaleform::Render::BundleEntry *v5; // rbx
  Scaleform::Render::Bundle *v6; // rax
  Scaleform::Render::Bundle *v7; // rdi
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rdx
  Scaleform::Render::BundleEntry **v10; // rax
  bool v11; // zf
  Scaleform::Render::Bundle *v12; // rcx

  v3 = indexHint;
  v4 = b;
  v5 = this;
  v6 = this->pBundle.pObject;
  if ( !v6 || v6 == b )
    goto LABEL_16;
  if ( v6 )
    ++v6->RefCount;
  v7 = this->pBundle.pObject;
  v8 = v7->Entries.Data.Size;
  v9 = v5->IndexHint;
  if ( v9 >= v8 || v7->Entries.Data.Data[v9] != v5 )
  {
    v9 = 0i64;
    if ( !v8 )
      goto LABEL_14;
    v10 = v7->Entries.Data.Data;
    while ( *v10 != v5 )
    {
      ++v9;
      ++v10;
      if ( v9 >= v8 )
        goto LABEL_14;
    }
    v5->IndexHint = v9;
  }
  ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, signed __int64))v7->vfptr[2].__vecDelDtor)(
    v7,
    v9,
    1i64);
LABEL_14:
  v11 = v7->RefCount-- == 1;
  if ( v11 )
    v7->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, 1u);
LABEL_16:
  if ( v4 )
    ++v4->RefCount;
  v12 = v5->pBundle.pObject;
  if ( v12 )
  {
    v11 = v12->RefCount-- == 1;
    if ( v11 )
      v12->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v12->vfptr, 1u);
  }
  v5->pBundle.pObject = v4;
  v5->IndexHint = v3;
}

// File Line: 587
// RVA: 0x960320
void __fastcall Scaleform::Render::BundleEntry::ClearBundle(Scaleform::Render::BundleEntry *this)
{
  Scaleform::Render::BundleEntry *v1; // rbx
  Scaleform::Render::Bundle *v2; // rax
  Scaleform::Render::Bundle *v3; // rdi
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rdx
  Scaleform::Render::BundleEntry **v6; // rax
  bool v7; // zf
  Scaleform::Render::Bundle *v8; // rcx

  v1 = this;
  v2 = this->pBundle.pObject;
  if ( !v2 )
    goto LABEL_13;
  ++v2->RefCount;
  v3 = this->pBundle.pObject;
  v4 = v3->Entries.Data.Size;
  v5 = v1->IndexHint;
  if ( v5 >= v4 || v3->Entries.Data.Data[v5] != v1 )
  {
    v5 = 0i64;
    if ( !v4 )
      goto LABEL_11;
    v6 = v3->Entries.Data.Data;
    while ( *v6 != v1 )
    {
      ++v5;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_11;
    }
    v1->IndexHint = v5;
  }
  ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, signed __int64))v3->vfptr[2].__vecDelDtor)(
    v3,
    v5,
    1i64);
LABEL_11:
  v7 = v3->RefCount-- == 1;
  if ( v7 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, 1u);
LABEL_13:
  v8 = v1->pBundle.pObject;
  if ( v8 )
  {
    v7 = v8->RefCount-- == 1;
    if ( v7 )
      v8->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, 1u);
  }
  v1->pBundle.pObject = 0i64;
  v1->IndexHint = 0;
}

