// File Line: 102
// RVA: 0x94D9C0
void __fastcall Scaleform::Render::VectorGlyphShape::~VectorGlyphShape(Scaleform::Render::VectorGlyphShape *this)
{
  Scaleform::Render::GlyphRaster *pObject; // rcx
  Scaleform::Render::GlyphShape *v4; // rcx

  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::VectorGlyphShape::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::VectorGlyphShape::`vftable{for `Scaleform::Render::MeshProvider};
  pObject = this->pRaster.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  v4 = this->pShape.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) )
    v4->vfptr->__vecDelDtor(v4, 1u);
  Scaleform::Render::MeshProvider_KeySupport::~MeshProvider_KeySupport(this);
}

// File Line: 104
// RVA: 0x946D90
void __fastcall Scaleform::Render::VectorGlyphShape::VectorGlyphShape(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::GlyphCache *cache)
{
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::`vftable;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshProvider_RCImpl::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider_RCImpl::`vftable{for `Scaleform::Render::MeshProvider};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable{for `Scaleform::Render::MeshProvider};
  this->hKeySet.pManager.Value = 0i64;
  this->hKeySet.pKeySet = 0i64;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::VectorGlyphShape::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::VectorGlyphShape::`vftable{for `Scaleform::Render::MeshProvider};
  this->Key.pFont = 0i64;
  this->Key.GlyphIndex = 0;
  *(_DWORD *)&this->Key.HintedVector = 0;
  this->Key.Outline = 0;
  this->pShape.pObject = 0i64;
  this->pRaster.pObject = 0i64;
  *(_QWORD *)&this->Bounds.x1 = 0i64;
  *(_QWORD *)&this->Bounds.x2 = 0i64;
  this->pCache = cache;
}

// File Line: 383
// RVA: 0x988280
__int64 __fastcall Scaleform::Render::StrokerAA::GetMeshVertexCount(Scaleform::Render::StrokerAA *this)
{
  return LODWORD(this->Vertices.Size);
}

// File Line: 394
// RVA: 0x983D00
void __fastcall Scaleform::Render::VectorGlyphShape::GetFillMatrix(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::Matrix2x4<float> *matrix,
        unsigned int layer)
{
  *(_QWORD *)&matrix->M[0][0] = 1065353216i64;
  *(_QWORD *)&matrix->M[1][1] = 1065353216i64;
  *(_QWORD *)&matrix->M[0][2] = 0i64;
  matrix->M[1][0] = 0.0;
  matrix->M[1][3] = 0.0;
}

