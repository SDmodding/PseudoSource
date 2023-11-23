// File Line: 33
// RVA: 0x94C290
void __fastcall Scaleform::RefCountImplCore::~RefCountImplCore(Scaleform::RefCountImplCore *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 52
// RVA: 0x94C2A0
void __fastcall Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(Scaleform::RefCountNTSImplCore *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 78
// RVA: 0x9A7C60
void __fastcall Scaleform::RefCountImpl::Release(Scaleform::Render::RenderBuffer *this)
{
  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    if ( this )
      this->vfptr->__vecDelDtor(this, 1i64);
  }
}

// File Line: 98
// RVA: 0x9A7C80
void __fastcall Scaleform::RefCountNTSImpl::Release(Scaleform::RefCountNTSImpl *this)
{
  if ( this->RefCount-- == 1 )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 107
// RVA: 0x94C2B0
void __fastcall Scaleform::RefCountWeakSupportImpl::~RefCountWeakSupportImpl(Scaleform::RefCountWeakSupportImpl *this)
{
  Scaleform::WeakPtrProxy *pWeakProxy; // rax
  Scaleform::WeakPtrProxy *v3; // rdx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountWeakSupportImpl::`vftable;
  pWeakProxy = this->pWeakProxy;
  if ( pWeakProxy )
  {
    pWeakProxy->pObject = 0i64;
    v3 = this->pWeakProxy;
    if ( v3->RefCount-- == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 117
// RVA: 0x96A990
Scaleform::WeakPtrProxy *__fastcall Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(
        Scaleform::RefCountWeakSupportImpl *this)
{
  Scaleform::WeakPtrProxy *result; // rax
  int v3; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::WeakPtrProxy *v4; // [rsp+50h] [rbp+18h]

  if ( this->pWeakProxy )
    goto LABEL_5;
  v3 = 2;
  result = (Scaleform::WeakPtrProxy *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::RefCountWeakSupportImpl *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        this,
                                        16i64,
                                        &v3,
                                        -2i64);
  v4 = result;
  if ( result )
  {
    result->RefCount = 1;
    result->pObject = this;
  }
  this->pWeakProxy = result;
  if ( result )
  {
LABEL_5:
    ++this->pWeakProxy->RefCount;
    return this->pWeakProxy;
  }
  return result;
}

