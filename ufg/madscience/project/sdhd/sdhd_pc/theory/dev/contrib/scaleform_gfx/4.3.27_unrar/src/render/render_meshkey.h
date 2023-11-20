// File Line: 130
// RVA: 0x94B820
void __fastcall Scaleform::Render::MeshKeySetHandle::~MeshKeySetHandle(Scaleform::Render::MeshKeySetHandle *this)
{
  _RBX = 0i64;
  __asm { xchg    rbx, [rcx]; Exchange Register/Memory with Register }
  if ( _RBX )
  {
    Scaleform::Render::MeshKeyManager::providerLost(_RBX, this);
    if ( !_InterlockedDecrement(&_RBX->RefCount) )
      _RBX->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&_RBX->vfptr, 1u);
  }
}

// File Line: 147
// RVA: 0x94B870
void __fastcall Scaleform::Render::MeshProvider_KeySupport::~MeshProvider_KeySupport(Scaleform::Render::MeshProvider_KeySupport *this)
{
  Scaleform::Render::MeshProvider_KeySupport *v1; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  _RDX = &this->hKeySet;
  _RBX = 0i64;
  __asm { xchg    rbx, [rdx]; Exchange Register/Memory with Register }
  if ( _RBX )
  {
    Scaleform::Render::MeshKeyManager::providerLost(_RBX, _RDX);
    if ( !_InterlockedDecrement(&_RBX->RefCount) )
      _RBX->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&_RBX->vfptr, 1u);
  }
  v1->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 189
// RVA: 0x981FA0
__int64 __fastcall Scaleform::Render::MeshKeySet::GetData(Scaleform::Render::MeshKeySet *this, Scaleform::Render::MeshBase *mesh, Scaleform::Render::VertexOutput *out, __int64 meshGenFlags)
{
  return this->pDelegate->vfptr->GetData(
           (Scaleform::Render::MeshProvider *)&this->pDelegate->vfptr,
           mesh,
           out,
           meshGenFlags);
}

// File Line: 191
// RVA: 0x987370
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::ImageShapeCharacterDef::GetBoundsLocal(Scaleform::GFx::ImageShapeCharacterDef *this, Scaleform::Render::Rect<float> *result, float __formal)
{
  Scaleform::Render::Rect<float> *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(Scaleform::Render::MeshProviderVtbl **))this->pShapeMeshProvider.pObject->vfptr->GetIdentityBounds)(&this->pShapeMeshProvider.pObject->vfptr);
  return v3;
}

// File Line: 193
// RVA: 0x980340
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::MeshKeySet::GetBounds(Scaleform::Render::MeshKeySet *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::Rect<float> *v3; // rbx

  v3 = result;
  this->pDelegate->vfptr->GetBounds((Scaleform::Render::MeshProvider *)&this->pDelegate->vfptr, result, m);
  return v3;
}

// File Line: 197
// RVA: 0x981700
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::MeshKeySet::GetCorrectBounds(Scaleform::Render::MeshKeySet *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *m, float morphRatio)
{
  Scaleform::Render::Rect<float> *v4; // rbx

  v4 = result;
  ((void (__fastcall *)(Scaleform::Render::MeshProviderVtbl **, Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *))this->pDelegate->vfptr->GetCorrectBounds)(
    &this->pDelegate->vfptr,
    result,
    m);
  return v4;
}

// File Line: 201
// RVA: 0x991EA0
__int64 __fastcall Scaleform::Render::MeshKeySet::HitTestShape(Scaleform::Render::MeshKeySet *this, Scaleform::Render::Matrix2x4<float> *m, float x, float y, float morphRatio, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::MeshProviderVtbl **, Scaleform::Render::Matrix2x4<float> *))this->pDelegate->vfptr->HitTestShape)(
           &this->pDelegate->vfptr,
           m);
}

// File Line: 203
// RVA: 0x988270
__int64 __fastcall Scaleform::Render::MeshKeySet::GetLayerCount(Scaleform::Render::MeshKeySet *this)
{
  return this->pDelegate->vfptr->GetLayerCount((Scaleform::Render::MeshProvider *)&this->pDelegate->vfptr);
}

// File Line: 206
// RVA: 0x983550
__int64 __fastcall Scaleform::Render::MeshKeySet::GetFillCount(Scaleform::Render::MeshKeySet *this, __int64 layer, __int64 meshGenFlags)
{
  return this->pDelegate->vfptr->GetFillCount(
           (Scaleform::Render::MeshProvider *)&this->pDelegate->vfptr,
           layer,
           meshGenFlags);
}

// File Line: 210
// RVA: 0x983570
void __fastcall Scaleform::Render::MeshKeySet::GetFillData(Scaleform::Render::MeshKeySet *this, Scaleform::Render::FillData *data, __int64 layer, __int64 fillIndex, unsigned int meshGenFlags)
{
  ((void (__fastcall *)(Scaleform::Render::MeshProviderVtbl **, Scaleform::Render::FillData *, __int64, __int64))this->pDelegate->vfptr->GetFillData)(
    &this->pDelegate->vfptr,
    data,
    layer,
    fillIndex);
}

// File Line: 214
// RVA: 0x983910
void __fastcall Scaleform::Render::MeshKeySet::GetFillMatrix(Scaleform::Render::MeshKeySet *this, Scaleform::Render::MeshBase *mesh, Scaleform::Render::Matrix2x4<float> *matrix, __int64 layer, unsigned int fillIndex, unsigned int meshGenFlags)
{
  ((void (__fastcall *)(Scaleform::Render::MeshProviderVtbl **, Scaleform::Render::MeshBase *, Scaleform::Render::Matrix2x4<float> *, __int64))this->pDelegate->vfptr->GetFillMatrix)(
    &this->pDelegate->vfptr,
    mesh,
    matrix,
    layer);
}

// File Line: 262
// RVA: 0x93FC60
void __fastcall Scaleform::Render::MeshKeyManager::MeshKeyManager(Scaleform::Render::MeshKeyManager *this, Scaleform::MemoryHeap *renderHeap)
{
  Scaleform::MemoryHeap *v2; // rdi
  Scaleform::Render::MeshKeyManager *v3; // rbx
  _QWORD *v4; // rdx
  signed __int64 v5; // r8
  signed __int64 v6; // rax

  v2 = renderHeap;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MeshKeyManager,65>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshKeyManager::`vftable';
  Scaleform::Lock::Lock(&this->KeySetLock, 0);
  v4 = v3->KeySets;
  v5 = 0i64;
  v6 = (signed __int64)&v3->KeySetLock.cs.SpinCount;
  if ( v3 == (Scaleform::Render::MeshKeyManager *)-56i64 )
    v6 = 0i64;
  *v4 = v6;
  v3->KeySets[0].Root.pNext = (Scaleform::Render::MeshKeySet *)v6;
  if ( v4 != (_QWORD *)-16i64 )
    v5 = (signed __int64)&v3->KeySets[0].Root.8;
  v3->KeySets[1].Root.pPrev = (Scaleform::Render::MeshKeySet *)v5;
  v3->KeySets[1].Root.pNext = (Scaleform::Render::MeshKeySet *)v5;
  v3->pRenderHeap = v2;
}

