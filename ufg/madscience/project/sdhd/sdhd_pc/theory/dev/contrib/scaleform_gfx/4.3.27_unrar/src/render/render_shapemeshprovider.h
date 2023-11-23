// File Line: 43
// RVA: 0x913440
void __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::Transform(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo> *this,
        float *x,
        float *y)
{
  Scaleform::Render::Scale9GridInfo::Transform(this->Tr, x, y);
}

// File Line: 44
// RVA: 0x8DDFA0
float __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetScale(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  Scaleform::Render::Matrix2x4<float> *Tr; // rax
  __m128 v2; // xmm1
  float result; // xmm0_4

  Tr = this->Tr;
  v2 = (__m128)LODWORD(Tr->M[1][1]);
  v2.m128_f32[0] = (float)((float)((float)(v2.m128_f32[0] + Tr->M[1][0]) * 0.70710677)
                         * (float)((float)(v2.m128_f32[0] + Tr->M[1][0]) * 0.70710677))
                 + (float)((float)((float)(Tr->M[0][1] + Tr->M[0][0]) * 0.70710677)
                         * (float)((float)(Tr->M[0][1] + Tr->M[0][0]) * 0.70710677));
  LODWORD(result) = _mm_sqrt_ps(v2).m128_u32[0];
  return result;
}

// File Line: 45
// RVA: 0x8E1CC0
float __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetXScale(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  Scaleform::Render::Matrix2x4<float> *Tr; // rax
  __m128 v2; // xmm1
  float result; // xmm0_4

  Tr = this->Tr;
  v2 = (__m128)LODWORD(Tr->M[0][0]);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(Tr->M[1][0] * Tr->M[1][0]);
  LODWORD(result) = _mm_sqrt_ps(v2).m128_u32[0];
  return result;
}

// File Line: 46
// RVA: 0x8E1ED0
float __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetYScale(
        Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  Scaleform::Render::Matrix2x4<float> *Tr; // rax
  __m128 v2; // xmm1
  float result; // xmm0_4

  Tr = this->Tr;
  v2 = (__m128)LODWORD(Tr->M[0][1]);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(Tr->M[1][1] * Tr->M[1][1]);
  LODWORD(result) = _mm_sqrt_ps(v2).m128_u32[0];
  return result;
}

// File Line: 94
// RVA: 0x944630
void __fastcall Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
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
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable{for `Scaleform::Render::MeshProvider};
  this->DrawLayers.Data.Data = 0i64;
  this->DrawLayers.Data.Size = 0i64;
  this->DrawLayers.Data.Policy.Capacity = 0i64;
  this->FillToStyleTable.Data.Data = 0i64;
  this->FillToStyleTable.Data.Size = 0i64;
  this->FillToStyleTable.Data.Policy.Capacity = 0i64;
  this->pShapeData.pObject = 0i64;
  this->pMorphData.pObject = 0i64;
  *(_QWORD *)&this->IdentityBounds.x1 = 0i64;
  *(_QWORD *)&this->IdentityBounds.x2 = 0i64;
}

// File Line: 104
// RVA: 0x9873C0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::GetIdentityBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result)
{
  result->x1 = *(float *)&this->pMorphData.pObject;
  result->y1 = *((float *)&this->pMorphData.pObject + 1);
  result->x2 = *((float *)&this->pMorphData + 2);
  result->y2 = *((float *)&this->pMorphData + 3);
  return result;
}

// File Line: 111
// RVA: 0x9920C0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::HitTestShape(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol)
{
  __int64 v8; // [rsp+20h] [rbp-28h]

  *(float *)&v8 = morphRatio;
  return Scaleform::Render::ShapeMeshProvider::HitTestShape(
           (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
           m,
           x,
           y,
           v8,
           gen,
           tol);
}

