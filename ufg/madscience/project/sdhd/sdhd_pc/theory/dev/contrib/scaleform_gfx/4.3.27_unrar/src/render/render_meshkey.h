// File Line: 130
// RVA: 0x94B820
void __fastcall Scaleform::Render::MeshKeySetHandle::~MeshKeySetHandle(Scaleform::Render::MeshKeySetHandle *this)
{
  Scaleform::Render::MeshKeyManager *v1; // rbx

  v1 = (Scaleform::Render::MeshKeyManager *)_InterlockedExchange64((volatile __int64 *)this, 0i64);
  if ( v1 )
  {
    Scaleform::Render::MeshKeyManager::providerLost(v1, this);
    if ( !_InterlockedDecrement(&v1->RefCount) )
      v1->vfptr->__vecDelDtor(v1, 1u);
  }
}

// File Line: 147
// RVA: 0x94B870
void __fastcall Scaleform::Render::MeshProvider_KeySupport::~MeshProvider_KeySupport(
        Scaleform::Render::MeshProvider_KeySupport *this)
{
  Scaleform::Render::MeshKeyManager *v2; // rbx

  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable{for `Scaleform::Render::MeshProvider};
  v2 = (Scaleform::Render::MeshKeyManager *)_InterlockedExchange64((volatile __int64 *)&this->hKeySet, 0i64);
  if ( v2 )
  {
    Scaleform::Render::MeshKeyManager::providerLost(v2, &this->hKeySet);
    if ( !_InterlockedDecrement(&v2->RefCount) )
      v2->vfptr->__vecDelDtor(v2, 1u);
  }
  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
  this->Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 189
// RVA: 0x981FA0
__int64 __fastcall Scaleform::Render::MeshKeySet::GetData(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *out,
        __int64 meshGenFlags)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::MeshBase *, Scaleform::Render::VertexOutput *, __int64))this->pDelegate->vfptr->GetData)(
           &this->pDelegate->Scaleform::Render::MeshProvider,
           mesh,
           out,
           meshGenFlags);
}

// File Line: 191
// RVA: 0x987370
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::ImageShapeCharacterDef::GetBoundsLocal(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float __formal)
{
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *))this->pShapeMeshProvider.pObject->vfptr->GetIdentityBounds)(&this->pShapeMeshProvider.pObject->Scaleform::Render::MeshProvider);
  return result;
}

// File Line: 193
// RVA: 0x980340
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::MeshKeySet::GetBounds(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m)
{
  this->pDelegate->vfptr->GetBounds(&this->pDelegate->Scaleform::Render::MeshProvider, result, m);
  return result;
}

// File Line: 197
// RVA: 0x981700
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::MeshKeySet::GetCorrectBounds(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio)
{
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *))this->pDelegate->vfptr->GetCorrectBounds)(
    &this->pDelegate->Scaleform::Render::MeshProvider,
    result,
    m);
  return result;
}

// File Line: 201
// RVA: 0x991EA0
__int64 __fastcall Scaleform::Render::MeshKeySet::HitTestShape(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::Matrix2x4<float> *))this->pDelegate->vfptr->HitTestShape)(
           &this->pDelegate->Scaleform::Render::MeshProvider,
           m);
}

// File Line: 203
// RVA: 0x988270
__int64 __fastcall Scaleform::Render::MeshKeySet::GetLayerCount(Scaleform::Render::MeshKeySet *this)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::MeshProvider *))this->pDelegate->vfptr->GetLayerCount)(&this->pDelegate->Scaleform::Render::MeshProvider);
}

// File Line: 206
// RVA: 0x983550
__int64 __fastcall Scaleform::Render::MeshKeySet::GetFillCount(
        Scaleform::Render::MeshKeySet *this,
        __int64 layer,
        __int64 meshGenFlags)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::MeshProvider *, __int64, __int64))this->pDelegate->vfptr->GetFillCount)(
           &this->pDelegate->Scaleform::Render::MeshProvider,
           layer,
           meshGenFlags);
}

// File Line: 210
// RVA: 0x983570
void __fastcall Scaleform::Render::MeshKeySet::GetFillData(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::FillData *data,
        __int64 layer,
        __int64 fillIndex,
        unsigned int meshGenFlags)
{
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::FillData *, __int64, __int64))this->pDelegate->vfptr->GetFillData)(
    &this->pDelegate->Scaleform::Render::MeshProvider,
    data,
    layer,
    fillIndex);
}

// File Line: 214
// RVA: 0x983910
void __fastcall Scaleform::Render::MeshKeySet::GetFillMatrix(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::Matrix2x4<float> *matrix,
        __int64 layer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::MeshBase *, Scaleform::Render::Matrix2x4<float> *, __int64))this->pDelegate->vfptr->GetFillMatrix)(
    &this->pDelegate->Scaleform::Render::MeshProvider,
    mesh,
    matrix,
    layer);
}

// File Line: 262
// RVA: 0x93FC60
void __fastcall Scaleform::Render::MeshKeyManager::MeshKeyManager(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::MemoryHeap *renderHeap)
{
  Scaleform::Render::MeshKeySet *v4; // r8
  unsigned __int64 *p_SpinCount; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MeshKeyManager,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshKeyManager::`vftable;
  Scaleform::Lock::Lock(&this->KeySetLock, 0);
  v4 = 0i64;
  p_SpinCount = &this->KeySetLock.cs.SpinCount;
  if ( this == (Scaleform::Render::MeshKeyManager *)-56i64 )
    p_SpinCount = 0i64;
  this->KeySets[0].Root.pPrev = (Scaleform::Render::MeshKeySet *)p_SpinCount;
  this->KeySets[0].Root.pNext = (Scaleform::Render::MeshKeySet *)p_SpinCount;
  if ( this != (Scaleform::Render::MeshKeyManager *)-72i64 )
    v4 = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.8;
  this->KeySets[1].Root.pPrev = v4;
  this->KeySets[1].Root.pNext = v4;
  this->pRenderHeap = renderHeap;
}

