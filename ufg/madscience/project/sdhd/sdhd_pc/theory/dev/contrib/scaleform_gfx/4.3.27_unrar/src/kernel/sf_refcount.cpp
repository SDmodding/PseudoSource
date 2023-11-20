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
      this->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)this, 1u);
  }
}

// File Line: 98
// RVA: 0x9A7C80
void __fastcall Scaleform::RefCountNTSImpl::Release(Scaleform::RefCountNTSImpl *this)
{
  bool v1; // zf

  v1 = this->RefCount-- == 1;
  if ( v1 )
    this->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 1u);
}

// File Line: 107
// RVA: 0x94C2B0
void __fastcall Scaleform::RefCountWeakSupportImpl::~RefCountWeakSupportImpl(Scaleform::RefCountWeakSupportImpl *this)
{
  Scaleform::RefCountWeakSupportImpl *v1; // rbx
  Scaleform::WeakPtrProxy *v2; // rax
  Scaleform::WeakPtrProxy *v3; // rdx
  bool v4; // zf

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountWeakSupportImpl::`vftable;
  v2 = this->pWeakProxy;
  if ( v2 )
  {
    v2->pObject = 0i64;
    v3 = this->pWeakProxy;
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 117
// RVA: 0x96A990
Scaleform::WeakPtrProxy *__fastcall Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(Scaleform::RefCountWeakSupportImpl *this)
{
  Scaleform::RefCountWeakSupportImpl *v1; // rbx
  Scaleform::WeakPtrProxy *result; // rax
  int v3; // [rsp+48h] [rbp+10h]
  Scaleform::WeakPtrProxy *v4; // [rsp+50h] [rbp+18h]

  v1 = this;
  if ( this->pWeakProxy )
    goto LABEL_8;
  v3 = 2;
  result = (Scaleform::WeakPtrProxy *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::RefCountWeakSupportImpl *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        this,
                                        16i64,
                                        &v3,
                                        -2i64);
  v4 = result;
  if ( result )
  {
    result->RefCount = 1;
    result->pObject = v1;
  }
  v1->pWeakProxy = result;
  if ( result )
  {
LABEL_8:
    ++v1->pWeakProxy->RefCount;
    result = v1->pWeakProxy;
  }
  return result;
}

