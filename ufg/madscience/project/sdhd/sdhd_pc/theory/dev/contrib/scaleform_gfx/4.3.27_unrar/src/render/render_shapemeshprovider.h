// File Line: 43
// RVA: 0x913440
void __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::Transform(Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo> *this, float *x, float *y)
{
  Scaleform::Render::Scale9GridInfo::Transform(this->Tr, x, y);
}

// File Line: 44
// RVA: 0x8DDFA0
float __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetScale(Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  Scaleform::Render::Matrix2x4<float> *v1; // rax
  __m128 v2; // xmm1
  float result; // xmm0_4

  v1 = this->Tr;
  v2 = (__m128)LODWORD(v1->M[1][1]);
  v2.m128_f32[0] = (float)((float)((float)(v2.m128_f32[0] + v1->M[1][0]) * 0.70710677)
                         * (float)((float)(v2.m128_f32[0] + v1->M[1][0]) * 0.70710677))
                 + (float)((float)((float)(v1->M[0][1] + v1->M[0][0]) * 0.70710677)
                         * (float)((float)(v1->M[0][1] + v1->M[0][0]) * 0.70710677));
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v2);
  return result;
}

// File Line: 45
// RVA: 0x8E1CC0
float __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetXScale(Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  Scaleform::Render::Matrix2x4<float> *v1; // rax
  __m128 v2; // xmm1
  float result; // xmm0_4

  v1 = this->Tr;
  v2 = (__m128)LODWORD(v1->M[0][0]);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v1->M[1][0] * v1->M[1][0]);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v2);
  return result;
}

// File Line: 46
// RVA: 0x8E1ED0
float __fastcall Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::GetYScale(Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float> > *this)
{
  Scaleform::Render::Matrix2x4<float> *v1; // rax
  __m128 v2; // xmm1
  float result; // xmm0_4

  v1 = this->Tr;
  v2 = (__m128)LODWORD(v1->M[0][1]);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v1->M[1][1] * v1->M[1][1]);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v2);
  return result;
}

// File Line: 94
// RVA: 0x944630
void __fastcall Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::MeshKeyManager *volatile v1; // rt1
  Scaleform::Render::MeshKeyManager *volatile v2; // rax
  Scaleform::ArrayLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2,Scaleform::ArrayDefaultPolicy> *v3; // [rsp+28h] [rbp+10h]
  Scaleform::ArrayLH_POD<unsigned int,2,Scaleform::ArrayDefaultPolicy> *v4; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::`vftable';
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshProvider_RCImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider_RCImpl::`vftable'{for `Scaleform::Render::MeshProvider'};
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  v1 = this->hKeySet.pManager.Value;
  this->hKeySet.pManager.Value = 0i64;
  v2 = this->hKeySet.pManager.Value;
  this->hKeySet.pKeySet = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  v3 = &this->DrawLayers;
  *(_OWORD *)&v3->Data.Data = 0ui64;
  v3->Data.Policy.Capacity = 0i64;
  v4 = &this->FillToStyleTable;
  *(_OWORD *)&v4->Data.Data = 0ui64;
  v4->Data.Policy.Capacity = 0i64;
  this->pShapeData.pObject = 0i64;
  this->pMorphData.pObject = 0i64;
  *(_QWORD *)&this->IdentityBounds.x1 = 0i64;
  *(_QWORD *)&this->IdentityBounds.x2 = 0i64;
}

// File Line: 104
// RVA: 0x9873C0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::GetIdentityBounds(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Rect<float> *result)
{
  result->x1 = *(float *)&this->pMorphData.pObject;
  result->y1 = *((float *)&this->pMorphData.pObject + 1);
  result->x2 = *((float *)&this->pMorphData + 2);
  result->y2 = *((float *)&this->pMorphData + 3);
  return result;
}

// File Line: 111
// RVA: 0x9920C0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::HitTestShape(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Matrix2x4<float> *m, float x, float y, float morphRatio, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol)
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

