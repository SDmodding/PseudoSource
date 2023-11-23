// File Line: 34
// RVA: 0x93FD10
void __fastcall Scaleform::Render::MorphInterpolator::MorphInterpolator(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::MorphShapeData *morph,
        float ratio,
        Scaleform::Render::ShapePosInfo *pos2)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MorphInterpolator::`vftable;
  if ( shape )
    _InterlockedExchangeAdd(&shape->RefCount, 1u);
  this->pShapeData.pObject = shape;
  if ( morph )
    _InterlockedExchangeAdd(&morph->RefCount, 1u);
  this->pMorphData.pObject = morph;
  this->MorphRatio = ratio;
  this->Pos2 = *pos2;
  this->Pos2s = *pos2;
}

// File Line: 50
// RVA: 0x983E90
void __fastcall Scaleform::Render::MorphInterpolator::GetFillStyle(
        Scaleform::Render::MorphInterpolator *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *f1)
{
  float MorphRatio; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  void (__fastcall ***v9)(_QWORD, __int64); // rcx
  char v10[8]; // [rsp+28h] [rbp-20h] BYREF
  __int64 v11; // [rsp+30h] [rbp-18h]
  unsigned int v12; // [rsp+50h] [rbp+8h]

  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(this->pShapeData.pObject);
  if ( this->pMorphData.pObject && this->MorphRatio != 0.0 )
  {
    v11 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pMorphData.pObject->pMorphTo.pObject->vfptr[4].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      idx,
      v10);
    if ( !f1->pFill.pObject )
    {
      MorphRatio = this->MorphRatio;
      v7 = (float)(unsigned __int8)BYTE2(f1->Color);
      BYTE2(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[2] - v7) * MorphRatio) + v7) + 0.5);
      v8 = (float)(unsigned __int8)BYTE1(f1->Color);
      BYTE1(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[1] - v8) * MorphRatio) + v8) + 0.5);
      LOBYTE(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[0]
                                                       - (float)(unsigned __int8)f1->Color)
                                               * MorphRatio)
                                       + (float)(unsigned __int8)f1->Color)
                               + 0.5);
      HIBYTE(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[3] - (float)HIBYTE(f1->Color))
                                               * MorphRatio)
                                       + (float)HIBYTE(f1->Color))
                               + 0.5);
      f1->Color = v12;
    }
    v9 = (void (__fastcall ***)(_QWORD, __int64))v11;
    if ( v11 && !_InterlockedDecrement((volatile signed __int32 *)(v11 + 8)) )
    {
      if ( v9 )
        (**v9)(v9, 1i64);
    }
  }
}

// File Line: 67
// RVA: 0x98C230
void __fastcall Scaleform::Render::MorphInterpolator::GetStrokeStyle(
        Scaleform::Render::MorphInterpolator *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *s1)
{
  float MorphRatio; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float Color; // xmm0_4
  float Color_high; // xmm0_4
  void (__fastcall ***v11)(_QWORD, __int64); // rcx
  void (__fastcall ***v12)(_QWORD, __int64); // rcx
  float v13[4]; // [rsp+28h] [rbp-30h] BYREF
  unsigned __int8 v14; // [rsp+38h] [rbp-20h]
  unsigned __int8 v15; // [rsp+39h] [rbp-1Fh]
  unsigned __int8 v16; // [rsp+3Ah] [rbp-1Eh]
  unsigned __int8 v17; // [rsp+3Bh] [rbp-1Dh]
  __int64 v18; // [rsp+40h] [rbp-18h]
  __int64 v19; // [rsp+48h] [rbp-10h]
  unsigned int v20; // [rsp+60h] [rbp+8h]

  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[5].__vecDelDtor)(this->pShapeData.pObject);
  if ( this->pMorphData.pObject && this->MorphRatio != 0.0 )
  {
    v18 = 0i64;
    v19 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))this->pMorphData.pObject->pMorphTo.pObject->vfptr[5].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      idx,
      v13);
    s1->Width = (float)((float)(v13[0] - s1->Width) * this->MorphRatio) + s1->Width;
    if ( !s1->pFill.pObject )
    {
      MorphRatio = this->MorphRatio;
      v7 = (float)(unsigned __int8)BYTE2(s1->Color);
      BYTE2(v20) = (int)(float)((float)((float)((float)((float)v16 - v7) * MorphRatio) + v7) + 0.5);
      v8 = (float)(unsigned __int8)BYTE1(s1->Color);
      BYTE1(v20) = (int)(float)((float)((float)((float)((float)v15 - v8) * MorphRatio) + v8) + 0.5);
      Color = (float)(unsigned __int8)s1->Color;
      LOBYTE(v20) = (int)(float)((float)((float)((float)((float)v14 - Color) * MorphRatio) + Color) + 0.5);
      Color_high = (float)HIBYTE(s1->Color);
      HIBYTE(v20) = (int)(float)((float)((float)((float)((float)v17 - Color_high) * MorphRatio) + Color_high) + 0.5);
      s1->Color = v20;
    }
    v11 = (void (__fastcall ***)(_QWORD, __int64))v19;
    if ( v19 && !_InterlockedDecrement((volatile signed __int32 *)(v19 + 8)) && v11 )
      (**v11)(v11, 1i64);
    v12 = (void (__fastcall ***)(_QWORD, __int64))v18;
    if ( v18 && !_InterlockedDecrement((volatile signed __int32 *)(v18 + 8)) )
    {
      if ( v12 )
        (**v12)(v12, 1i64);
    }
  }
}

// File Line: 86
// RVA: 0x98B840
__int64 __fastcall Scaleform::Render::MorphInterpolator::GetStartingPos(Scaleform::Render::MorphInterpolator *this)
{
  Scaleform::Render::MorphShapeData *pObject; // rax
  __int64 *p_p_ShapeData1; // rdx
  char v3; // al
  Scaleform::Render::ShapeDataInterface *v4; // rcx
  Scaleform::Render::ShapeDataInterface *v5; // rdx
  __int64 v6; // rdi
  char v8; // [rsp+20h] [rbp-18h]
  Scaleform::Render::ShapeDataInterface *v9; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData1; // [rsp+48h] [rbp+10h] BYREF

  pObject = this->pMorphData.pObject;
  if ( pObject )
  {
    if ( pObject != (Scaleform::Render::MorphShapeData *)-72i64 )
      _InterlockedExchangeAdd(&pObject->ShapeData1.RefCount, 1u);
    p_ShapeData1 = &pObject->ShapeData1;
    p_p_ShapeData1 = (__int64 *)&p_ShapeData1;
    v3 = 1;
    v4 = v9;
  }
  else
  {
    v5 = this->pShapeData.pObject;
    if ( v5 )
      _InterlockedExchangeAdd(&v5->RefCount, 1u);
    v4 = this->pShapeData.pObject;
    v9 = v4;
    p_p_ShapeData1 = (__int64 *)&v9;
    v3 = 2;
  }
  v6 = *p_p_ShapeData1;
  if ( (v3 & 2) != 0 )
  {
    v3 &= ~2u;
    v8 = v3;
    if ( v4 )
    {
      if ( !_InterlockedDecrement(&v4->RefCount) )
        v9->vfptr->__vecDelDtor(v9, 1u);
      v3 = v8;
    }
  }
  if ( (v3 & 1) != 0 && p_ShapeData1 && !_InterlockedDecrement(&p_ShapeData1->RefCount) )
    p_ShapeData1->vfptr->__vecDelDtor(p_ShapeData1, 1u);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 48i64))(v6);
}

// File Line: 93
// RVA: 0x9A5DD0
__int64 __fastcall Scaleform::Render::MorphInterpolator::ReadPathInfo(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1,
        float *coord1,
        unsigned int *styles1)
{
  Scaleform::Render::MorphShapeData *pObject; // rcx
  unsigned int v8; // esi
  char v9[16]; // [rsp+20h] [rbp-38h] BYREF
  int v10[10]; // [rsp+30h] [rbp-28h] BYREF

  pObject = this->pMorphData.pObject;
  if ( !pObject )
    return ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
             this->pShapeData.pObject,
             pos1,
             coord1,
             styles1);
  v8 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))pObject->ShapeData1.vfptr[8].__vecDelDtor)(
         &pObject->ShapeData1,
         pos1,
         coord1,
         styles1);
  ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, int *, char *))this->pMorphData.pObject->ShapeData2.vfptr[8].__vecDelDtor)(
    &this->pMorphData.pObject->ShapeData2,
    &this->Pos2,
    v10,
    v9);
  if ( v8 )
  {
    *coord1 = (float)((float)(*(float *)v10 - *coord1) * this->MorphRatio) + *coord1;
    coord1[1] = (float)((float)(*(float *)&v10[1] - coord1[1]) * this->MorphRatio) + coord1[1];
  }
  return v8;
}

// File Line: 115
// RVA: 0x9A4F80
void *__fastcall Scaleform::Render::MorphInterpolator::ReadEdge(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1,
        float *coord1)
{
  Scaleform::Render::MorphShapeData *pObject; // rcx
  unsigned int v7; // esi
  int v8[10]; // [rsp+20h] [rbp-28h] BYREF

  pObject = this->pMorphData.pObject;
  if ( !pObject )
    return this->pShapeData.pObject->vfptr[9].__vecDelDtor(this->pShapeData.pObject, pos1);
  v7 = (unsigned int)pObject->ShapeData1.vfptr[9].__vecDelDtor(&pObject->ShapeData1, (unsigned int)pos1);
  ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, int *))this->pMorphData.pObject->ShapeData2.vfptr[9].__vecDelDtor)(
    &this->pMorphData.pObject->ShapeData2,
    &this->Pos2,
    v8);
  if ( v7 )
  {
    *coord1 = (float)((float)(*(float *)v8 - *coord1) * this->MorphRatio) + *coord1;
    coord1[1] = (float)((float)(*(float *)&v8[1] - coord1[1]) * this->MorphRatio) + coord1[1];
    if ( v7 - 2 <= 1 )
    {
      coord1[2] = (float)((float)(*(float *)&v8[2] - coord1[2]) * this->MorphRatio) + coord1[2];
      coord1[3] = (float)((float)(*(float *)&v8[3] - coord1[3]) * this->MorphRatio) + coord1[3];
      if ( v7 == 3 )
      {
        coord1[4] = (float)((float)(*(float *)&v8[4] - coord1[4]) * this->MorphRatio) + coord1[4];
        coord1[5] = (float)((float)(*(float *)&v8[5] - coord1[5]) * this->MorphRatio) + coord1[5];
      }
    }
  }
  return (void *)v7;
}

// File Line: 144
// RVA: 0x9B6870
void __fastcall Scaleform::Render::MorphInterpolator::SkipPathData(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1)
{
  Scaleform::Render::MorphShapeData *pObject; // rcx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData2; // rcx

  pObject = this->pMorphData.pObject;
  if ( pObject )
  {
    pObject->ShapeData1.vfptr[10].__vecDelDtor(&pObject->ShapeData1, (unsigned int)pos1);
    pos1 = &this->Pos2;
    p_ShapeData2 = &this->pMorphData.pObject->ShapeData2;
  }
  else
  {
    p_ShapeData2 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)this->pShapeData.pObject;
  }
  p_ShapeData2->vfptr[10].__vecDelDtor(p_ShapeData2, (unsigned int)pos1);
}

// File Line: 156
// RVA: 0x9AD5C0
void __fastcall Scaleform::Render::MorphInterpolator::Rewind(Scaleform::Render::MorphInterpolator *this)
{
  this->Pos2 = this->Pos2s;
}

// File Line: 174
// RVA: 0x93FE70
void __fastcall Scaleform::Render::MorphShapeData::MorphShapeData(
        Scaleform::Render::MorphShapeData *this,
        Scaleform::Render::ShapeDataInterface *morphTo)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Container1; // rdx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Container2; // r8
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData1; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MorphShapeData,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MorphShapeData::`vftable;
  if ( morphTo )
    _InterlockedExchangeAdd(&morphTo->RefCount, 1u);
  this->pMorphTo.pObject = morphTo;
  p_Container1 = &this->Container1;
  this->Container1.Data.Data = 0i64;
  this->Container1.Data.Size = 0i64;
  this->Container1.Data.Policy.Capacity = 0i64;
  p_Container2 = &this->Container2;
  this->Container2.Data.Data = 0i64;
  this->Container2.Data.Size = 0i64;
  this->Container2.Data.Policy.Capacity = 0i64;
  p_ShapeData1 = &this->ShapeData1;
  p_ShapeData1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  p_ShapeData1->RefCount = 1;
  p_ShapeData1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  p_ShapeData1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  p_ShapeData1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  p_ShapeData1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  p_ShapeData1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable;
  p_ShapeData1->Status = Status_Clean;
  p_ShapeData1->Fills.Data.Data = 0i64;
  p_ShapeData1->Fills.Data.Size = 0i64;
  p_ShapeData1->Fills.Data.Policy.Capacity = 0i64;
  p_ShapeData1->Strokes.Data.Data = 0i64;
  p_ShapeData1->Strokes.Data.Size = 0i64;
  p_ShapeData1->Strokes.Data.Policy.Capacity = 0i64;
  p_ShapeData1->Data = p_Container1;
  *(_QWORD *)&p_ShapeData1->StartingPos = 0i64;
  *(_QWORD *)&p_ShapeData1->StartY = 0i64;
  p_ShapeData1->LastY = 0.0;
  this->ShapeData2.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->ShapeData2.RefCount = 1;
  this->ShapeData2.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->ShapeData2.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->ShapeData2.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  this->ShapeData2.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  this->ShapeData2.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable;
  this->ShapeData2.Status = Status_Clean;
  this->ShapeData2.Fills.Data.Data = 0i64;
  this->ShapeData2.Fills.Data.Size = 0i64;
  this->ShapeData2.Fills.Data.Policy.Capacity = 0i64;
  this->ShapeData2.Strokes.Data.Data = 0i64;
  this->ShapeData2.Strokes.Data.Size = 0i64;
  this->ShapeData2.Strokes.Data.Policy.Capacity = 0i64;
  this->ShapeData2.Data = p_Container2;
  *(_QWORD *)&this->ShapeData2.StartingPos = 0i64;
  *(_QWORD *)&this->ShapeData2.StartY = 0i64;
  this->ShapeData2.LastY = 0.0;
}>ShapeData2.StartY = 0i64;
  th

// File Line: 180
// RVA: 0x9444B0
void __fastcall Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapeDataInterface *shapeMorph)
{
  Scaleform::Render::MorphShapeData *v5; // rdi
  Scaleform::Render::MorphShapeData *v6; // rax
  Scaleform::Render::MorphShapeData *v7; // rax
  Scaleform::Render::MorphShapeData *pObject; // rcx
  int v9; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::ArrayLH_POD<unsigned int,2,Scaleform::ArrayDefaultPolicy> *p_FillToStyleTable; // [rsp+60h] [rbp+18h]
  Scaleform::ArrayLH_POD<unsigned int,2,Scaleform::ArrayDefaultPolicy> *v11; // [rsp+68h] [rbp+20h]

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
  v5 = 0i64;
  this->hKeySet.pManager.Value = 0i64;
  this->hKeySet.pKeySet = 0i64;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable{for `Scaleform::Render::MeshProvider};
  this->DrawLayers.Data.Data = 0i64;
  this->DrawLayers.Data.Size = 0i64;
  this->DrawLayers.Data.Policy.Capacity = 0i64;
  p_FillToStyleTable = &this->FillToStyleTable;
  v11 = &this->FillToStyleTable;
  this->FillToStyleTable.Data.Data = 0i64;
  this->FillToStyleTable.Data.Size = 0i64;
  this->FillToStyleTable.Data.Policy.Capacity = 0i64;
  if ( shape )
    _InterlockedExchangeAdd(&shape->RefCount, 1u);
  this->pShapeData.pObject = shape;
  this->pMorphData.pObject = 0i64;
  *(_QWORD *)&this->IdentityBounds.x1 = 0i64;
  *(_QWORD *)&this->IdentityBounds.x2 = 0i64;
  *(_WORD *)&this->GradientMorph = 0;
  if ( shapeMorph )
  {
    v9 = 71;
    v6 = (Scaleform::Render::MorphShapeData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ShapeMeshProvider *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                280i64,
                                                &v9,
                                                -2i64);
    p_FillToStyleTable = (Scaleform::ArrayLH_POD<unsigned int,2,Scaleform::ArrayDefaultPolicy> *)v6;
    if ( v6 )
    {
      Scaleform::Render::MorphShapeData::MorphShapeData(v6, shapeMorph);
      v5 = v7;
    }
    pObject = this->pMorphData.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pMorphData.pObject = v5;
    Scaleform::Render::ShapeMeshProvider::createMorphData(this);
  }
  Scaleform::Render::ShapeMeshProvider::acquireShapeData(this);
}

// File Line: 191
// RVA: 0x94CAF0
void __fastcall Scaleform::Render::ShapeMeshProvider::~ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::MeshKeyManager *v2; // rsi
  Scaleform::Render::MorphShapeData *pObject; // rcx
  Scaleform::Render::ShapeDataInterface *v4; // rcx

  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable{for `Scaleform::Render::MeshProvider};
  if ( this->hKeySet.pKeySet )
  {
    v2 = (Scaleform::Render::MeshKeyManager *)_InterlockedExchange64((volatile __int64 *)&this->hKeySet, 0i64);
    if ( v2 )
    {
      Scaleform::Render::MeshKeyManager::providerLost(v2, &this->hKeySet);
      if ( !_InterlockedDecrement(&v2->RefCount) )
        v2->vfptr->__vecDelDtor(v2, 1u);
    }
  }
  pObject = this->pMorphData.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v4 = this->pShapeData.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) )
    v4->vfptr->__vecDelDtor(v4, 1u);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->FillToStyleTable.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->DrawLayers.Data.Data);
  Scaleform::Render::MeshProvider_KeySupport::~MeshProvider_KeySupport(this);
}

// File Line: 217
// RVA: 0x9DD7C0
void __fastcall Scaleform::Render::ShapeMeshProvider::createMorphData(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::ShapeDataInterface *pObject; // rsi
  Scaleform::Render::ShapeDataInterface *v3; // r12
  unsigned int v4; // r14d
  __int64 v5; // r10
  __int64 v6; // r11
  unsigned __int16 v7; // cx
  unsigned int v8; // edx
  __int64 v9; // r8
  __int64 v10; // r9
  void (__fastcall ***v11)(_QWORD, __int64); // rcx
  void (__fastcall ***v12)(_QWORD, __int64); // rcx
  unsigned int v13; // r14d
  __int64 v14; // r10
  __int64 v15; // r11
  unsigned __int16 v16; // cx
  unsigned int v17; // edx
  __int64 v18; // r8
  __int64 v19; // r9
  void (__fastcall ***v20)(_QWORD, __int64); // rcx
  void (__fastcall ***v21)(_QWORD, __int64); // rcx
  void (__fastcall ***v22)(_QWORD, __int64); // rcx
  void (__fastcall ***v23)(_QWORD, __int64); // rcx
  int v24; // ebx
  int v25; // eax
  Scaleform::Render::MorphShapeData *v26; // r14
  unsigned __int64 Size; // r15
  __int64 v28; // rbx
  __int64 v29; // rcx
  unsigned __int64 v30; // r15
  __int64 v31; // rbx
  __int64 v32; // rcx
  __int64 v33; // rcx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  Scaleform::Render::MorphShapeData *v35; // r14
  unsigned __int64 v36; // r15
  __int64 v37; // rbx
  __int64 v38; // rcx
  char v39; // r14
  int v40; // ebx
  int v41; // eax
  float v42; // xmm9_4
  float v43; // xmm8_4
  float v44; // xmm6_4
  float v45; // xmm7_4
  __int64 v46; // r14
  __int128 v47; // kr00_16
  int v48; // ebx
  int v49; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v50; // rcx
  int v51; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData1; // rcx
  int v53; // eax
  _BYTE leftStyle[48]; // [rsp+40h] [rbp-80h] BYREF
  float ay[2]; // [rsp+70h] [rbp-50h]
  _BYTE v56[48]; // [rsp+78h] [rbp-48h] BYREF
  __int64 v57; // [rsp+A8h] [rbp-18h]
  __int64 v58; // [rsp+B0h] [rbp-10h] BYREF
  __int64 v59; // [rsp+B8h] [rbp-8h]
  __int64 v60; // [rsp+C0h] [rbp+0h] BYREF
  __int64 v61; // [rsp+C8h] [rbp+8h]
  __int64 v62; // [rsp+D0h] [rbp+10h]
  __int64 v63; // [rsp+D8h] [rbp+18h]
  __int64 v64; // [rsp+E0h] [rbp+20h]
  __int64 v65; // [rsp+E8h] [rbp+28h]
  __int64 v66; // [rsp+F0h] [rbp+30h]
  __int64 v67; // [rsp+F8h] [rbp+38h]
  char v68[24]; // [rsp+100h] [rbp+40h] BYREF
  __int64 v69; // [rsp+118h] [rbp+58h]
  __int64 v70; // [rsp+120h] [rbp+60h]
  char v71[16]; // [rsp+128h] [rbp+68h] BYREF
  char v72[24]; // [rsp+138h] [rbp+78h] BYREF
  __int64 v73; // [rsp+150h] [rbp+90h]
  __int64 v74; // [rsp+158h] [rbp+98h]
  __int64 v75; // [rsp+160h] [rbp+A0h]
  int v76; // [rsp+210h] [rbp+150h]
  __int128 v77; // [rsp+218h] [rbp+158h]
  __int64 v78; // [rsp+228h] [rbp+168h]

  v75 = -2i64;
  pObject = this->pShapeData.pObject;
  v3 = this->pMorphData.pObject->pMorphTo.pObject;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))pObject->vfptr[2].__vecDelDtor)(pObject) )
  {
    v4 = 1;
    while ( 1 )
    {
      v59 = 0i64;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, __int64 *))pObject->vfptr[4].__vecDelDtor)(
        pObject,
        v4,
        &v58);
      if ( v59 )
      {
        if ( *(_QWORD *)(v59 + 24) )
          break;
      }
LABEL_20:
      v12 = (void (__fastcall ***)(_QWORD, __int64))v59;
      if ( v59 && !_InterlockedDecrement((volatile signed __int32 *)(v59 + 8)) && v12 )
        (**v12)(v12, 1i64);
      if ( v4++ >= ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))pObject->vfptr[2].__vecDelDtor)(pObject) )
        goto LABEL_25;
    }
    v61 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, __int64 *))v3->vfptr[4].__vecDelDtor)(
      v3,
      v4,
      &v60);
    v5 = *(_QWORD *)(v61 + 24);
    v6 = *(_QWORD *)(v59 + 24);
    v7 = *(_WORD *)(v6 + 18);
    if ( v7 == *(_WORD *)(v5 + 18)
      && *(_BYTE *)(v6 + 17) == *(_BYTE *)(v5 + 17)
      && *(float *)(v5 + 32) == *(float *)(v6 + 32)
      && *(_BYTE *)(v6 + 16) == *(_BYTE *)(v5 + 16) )
    {
      v8 = 0;
      if ( !v7 )
      {
LABEL_16:
        v11 = (void (__fastcall ***)(_QWORD, __int64))v61;
        if ( v61 && !_InterlockedDecrement((volatile signed __int32 *)(v61 + 8)) && v11 )
          (**v11)(v11, 1i64);
        goto LABEL_20;
      }
      v9 = *(_QWORD *)(v5 + 24);
      v10 = *(_QWORD *)(v6 + 24);
      while ( *(_BYTE *)(v10 + 8i64 * v8) == *(_BYTE *)(v9 + 8i64 * v8) )
      {
        v76 = *(_DWORD *)(v9 + 8i64 * v8 + 4);
        if ( *(_DWORD *)(v10 + 8i64 * v8 + 4) != v76 )
          break;
        if ( ++v8 >= v7 )
          goto LABEL_16;
      }
    }
    *(_QWORD *)(v6 + 40) = v5;
    this->GradientMorph = 1;
    goto LABEL_16;
  }
LABEL_25:
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))pObject->vfptr[3].__vecDelDtor)(pObject) )
  {
    v13 = 1;
    while ( 1 )
    {
      v69 = 0i64;
      v70 = 0i64;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))pObject->vfptr[5].__vecDelDtor)(
        pObject,
        v13,
        v68);
      if ( v69 )
      {
        if ( *(_QWORD *)(v69 + 24) )
          break;
      }
LABEL_48:
      v22 = (void (__fastcall ***)(_QWORD, __int64))v70;
      if ( v70 && !_InterlockedDecrement((volatile signed __int32 *)(v70 + 8)) && v22 )
        (**v22)(v22, 1i64);
      v23 = (void (__fastcall ***)(_QWORD, __int64))v69;
      if ( v69 && !_InterlockedDecrement((volatile signed __int32 *)(v69 + 8)) && v23 )
        (**v23)(v23, 1i64);
      if ( v13++ >= ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))pObject->vfptr[3].__vecDelDtor)(pObject) )
        goto LABEL_57;
    }
    v73 = 0i64;
    v74 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v3->vfptr[5].__vecDelDtor)(
      v3,
      v13,
      v72);
    v14 = *(_QWORD *)(v73 + 24);
    v15 = *(_QWORD *)(v69 + 24);
    v16 = *(_WORD *)(v15 + 18);
    if ( v16 == *(_WORD *)(v14 + 18)
      && *(_BYTE *)(v15 + 17) == *(_BYTE *)(v14 + 17)
      && *(float *)(v14 + 32) == *(float *)(v15 + 32)
      && *(_BYTE *)(v15 + 16) == *(_BYTE *)(v14 + 16) )
    {
      v17 = 0;
      if ( !v16 )
        goto LABEL_40;
      v18 = *(_QWORD *)(v14 + 24);
      v19 = *(_QWORD *)(v15 + 24);
      while ( *(_BYTE *)(v19 + 8i64 * v17) == *(_BYTE *)(v18 + 8i64 * v17) )
      {
        LODWORD(v77) = *(_DWORD *)(v18 + 8i64 * v17 + 4);
        if ( *(_DWORD *)(v19 + 8i64 * v17 + 4) != (_DWORD)v77 )
          break;
        if ( ++v17 >= v16 )
          goto LABEL_40;
      }
    }
    *(_QWORD *)(v15 + 40) = v14;
    this->GradientMorph = 1;
LABEL_40:
    v20 = (void (__fastcall ***)(_QWORD, __int64))v74;
    if ( v74 && !_InterlockedDecrement((volatile signed __int32 *)(v74 + 8)) && v20 )
      (**v20)(v20, 1i64);
    v21 = (void (__fastcall ***)(_QWORD, __int64))v73;
    if ( v73 && !_InterlockedDecrement((volatile signed __int32 *)(v73 + 8)) && v21 )
      (**v21)(v21, 1i64);
    goto LABEL_48;
  }
LABEL_57:
  v24 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))pObject->vfptr[6].__vecDelDtor)(pObject);
  v25 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v3->vfptr[6].__vecDelDtor)(v3);
  *(_DWORD *)leftStyle = v24;
  memset(&leftStyle[4], 0, 44);
  ay[0] = 1.0;
  LOBYTE(ay[1]) = 0;
  *(_DWORD *)v56 = v25;
  memset(&v56[4], 0, 44);
  LODWORD(v57) = 1065353216;
  BYTE4(v57) = 0;
  v26 = this->pMorphData.pObject;
  v26->ShapeData1.Status = Status_Clean;
  Size = v26->ShapeData1.Fills.Data.Size;
  if ( Size )
  {
    v28 = (__int64)&v26->ShapeData1.Fills.Data.Data[Size - 1];
    *((_QWORD *)&v77 + 1) = v28;
    do
    {
      v29 = *(_QWORD *)(v28 + 8);
      if ( v29 && !_InterlockedDecrement((volatile signed __int32 *)(v29 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v29)(v29, 1i64);
      v28 -= 16i64;
      *((_QWORD *)&v77 + 1) = v28;
      --Size;
    }
    while ( Size );
    if ( (v26->ShapeData1.Fills.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( v26->ShapeData1.Fills.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v26->ShapeData1.Fills.Data.Data = 0i64;
      }
      v26->ShapeData1.Fills.Data.Policy.Capacity = 0i64;
    }
  }
  v26->ShapeData1.Fills.Data.Size = 0i64;
  v30 = v26->ShapeData1.Strokes.Data.Size;
  if ( v30 )
  {
    v31 = (__int64)&v26->ShapeData1.Strokes.Data.Data[v30 - 1];
    *((_QWORD *)&v77 + 1) = v31;
    do
    {
      v32 = *(_QWORD *)(v31 + 32);
      if ( v32 && !_InterlockedDecrement((volatile signed __int32 *)(v32 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v32)(v32, 1i64);
      v33 = *(_QWORD *)(v31 + 24);
      if ( v33 && !_InterlockedDecrement((volatile signed __int32 *)(v33 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v33)(v33, 1i64);
      v31 -= 40i64;
      *((_QWORD *)&v77 + 1) = v31;
      --v30;
    }
    while ( v30 );
    if ( (v26->ShapeData1.Strokes.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( v26->ShapeData1.Strokes.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v26->ShapeData1.Strokes.Data.Data = 0i64;
      }
      v26->ShapeData1.Strokes.Data.Policy.Capacity = 0i64;
    }
  }
  v26->ShapeData1.Strokes.Data.Size = 0i64;
  Data = v26->ShapeData1.Data;
  if ( Data->Data.Size && (Data->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v26->ShapeData1.Data,
      v26->ShapeData1.Data,
      0i64);
  Data->Data.Size = 0i64;
  *(_QWORD *)&v26->ShapeData1.StartX = 0i64;
  *(_QWORD *)&v26->ShapeData1.LastX = 0i64;
  v35 = this->pMorphData.pObject;
  v35->ShapeData2.Status = Status_Clean;
  v36 = v35->ShapeData2.Fills.Data.Size;
  if ( v36 )
  {
    v37 = (__int64)&v35->ShapeData2.Fills.Data.Data[v36 - 1];
    *((_QWORD *)&v77 + 1) = v37;
    do
    {
      v38 = *(_QWORD *)(v37 + 8);
      if ( v38 && !_InterlockedDecrement((volatile signed __int32 *)(v38 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v38)(v38, 1i64);
      v37 -= 16i64;
      *((_QWORD *)&v77 + 1) = v37;
      --v36;
    }
    while ( v36 );
    if ( (v35->ShapeData2.Fills.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( v35->ShapeData2.Fills.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v35->ShapeData2.Fills.Data.Data = 0i64;
      }
      v35->ShapeData2.Fills.Data.Policy.Capacity = 0i64;
    }
  }
  v35->ShapeData2.Fills.Data.Size = 0i64;
  Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v35->ShapeData2.Strokes.Data,
    0i64);
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v35->ShapeData2.Data,
    0i64);
  *(_QWORD *)&v35->ShapeData2.StartX = 0i64;
  *(_QWORD *)&v35->ShapeData2.LastX = 0i64;
  v39 = 1;
  LOBYTE(v76) = 1;
  while ( 2 )
  {
    v40 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _BYTE *, _BYTE *, _BYTE *))pObject->vfptr[8].__vecDelDtor)(
            pObject,
            leftStyle,
            &leftStyle[40],
            leftStyle);
    v41 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _BYTE *, _BYTE *, char *))v3->vfptr[8].__vecDelDtor)(
            v3,
            v56,
            &leftStyle[16],
            v71);
    if ( !v40 || !v41 )
    {
      p_ShapeData1 = &this->pMorphData.pObject->ShapeData1;
      goto LABEL_124;
    }
    if ( v40 == 2 || v39 )
    {
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(&this->pMorphData.pObject->ShapeData1);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(&this->pMorphData.pObject->ShapeData2);
      LOBYTE(v76) = 0;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData1,
      *(unsigned int *)leftStyle,
      *(unsigned int *)&leftStyle[4],
      *(unsigned int *)&leftStyle[8]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData2,
      *(unsigned int *)leftStyle,
      *(unsigned int *)&leftStyle[4],
      *(unsigned int *)&leftStyle[8]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData1,
      *(float *)&leftStyle[40],
      *(float *)&leftStyle[44]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData2,
      *(float *)&leftStyle[16],
      *(float *)&leftStyle[20]);
LABEL_100:
    v42 = *(float *)&leftStyle[20];
    v43 = *(float *)&leftStyle[16];
LABEL_101:
    v44 = *(float *)&leftStyle[40];
    v45 = *(float *)&leftStyle[44];
    while ( 1 )
    {
      v63 = *(_QWORD *)leftStyle;
      v62 = *(_QWORD *)&leftStyle[8];
      v64 = *(_QWORD *)&leftStyle[16];
      v66 = *(_QWORD *)&leftStyle[24];
      v65 = *(_QWORD *)&leftStyle[32];
      v60 = *(_QWORD *)&leftStyle[40];
      v58 = *(_QWORD *)ay;
      v46 = *(_QWORD *)v56;
      v47 = *(_OWORD *)&v56[8];
      v77 = *(_OWORD *)&v56[24];
      v78 = *(_QWORD *)&v56[40];
      v67 = v57;
      v48 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _BYTE *, _BYTE *))pObject->vfptr[9].__vecDelDtor)(
              pObject,
              leftStyle,
              &leftStyle[40]);
      v49 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _BYTE *, _BYTE *))v3->vfptr[9].__vecDelDtor)(
              v3,
              v56,
              &leftStyle[16]);
      if ( !v48 )
        break;
      if ( v49 )
      {
        if ( v48 != v49 )
        {
          if ( v48 == 1 )
          {
            if ( v49 != 2 )
              goto LABEL_117;
            ay[0] = *(float *)&leftStyle[40];
            ay[1] = *(float *)&leftStyle[44];
            *(float *)&leftStyle[40] = (float)(v44 + *(float *)&leftStyle[40]) * 0.5;
            *(float *)&leftStyle[44] = (float)(v45 + *(float *)&leftStyle[44]) * 0.5;
            goto LABEL_119;
          }
          if ( v48 == 2 )
          {
            if ( v49 == 1 )
            {
              *(_QWORD *)&leftStyle[24] = *(_QWORD *)&leftStyle[16];
              *(float *)&leftStyle[16] = (float)(v43 + *(float *)&leftStyle[16]) * 0.5;
              *(float *)&leftStyle[20] = (float)(v42 + *(float *)&leftStyle[20]) * 0.5;
            }
            goto LABEL_119;
          }
        }
        switch ( v48 )
        {
          case 1:
LABEL_117:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              &this->pMorphData.pObject->ShapeData1,
              *(float *)&leftStyle[40],
              *(float *)&leftStyle[44]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              &this->pMorphData.pObject->ShapeData2,
              *(float *)&leftStyle[16],
              *(float *)&leftStyle[20]);
            goto LABEL_100;
          case 2:
LABEL_119:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &this->pMorphData.pObject->ShapeData1,
              *(float *)&leftStyle[40],
              *(float *)&leftStyle[44],
              ay[0],
              ay[1]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &this->pMorphData.pObject->ShapeData2,
              *(float *)&leftStyle[16],
              *(float *)&leftStyle[20],
              *(float *)&leftStyle[24],
              *(float *)&leftStyle[28]);
            v44 = ay[0];
            v45 = ay[1];
            v43 = *(float *)&leftStyle[24];
            v42 = *(float *)&leftStyle[28];
            break;
          case 3:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &this->pMorphData.pObject->ShapeData1,
              *(float *)&leftStyle[40],
              *(float *)&leftStyle[44],
              ay[0],
              ay[1],
              *(float *)v56,
              *(float *)&v56[4]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &this->pMorphData.pObject->ShapeData2,
              *(float *)&leftStyle[16],
              *(float *)&leftStyle[20],
              *(float *)&leftStyle[24],
              *(float *)&leftStyle[28],
              *(float *)&leftStyle[32],
              *(float *)&leftStyle[36]);
            v44 = *(float *)v56;
            v45 = *(float *)&v56[4];
            v43 = *(float *)&leftStyle[32];
            v42 = *(float *)&leftStyle[36];
            break;
        }
      }
      else
      {
        *(_QWORD *)leftStyle = v63;
        *(_QWORD *)&leftStyle[8] = v62;
        *(_QWORD *)&leftStyle[16] = v64;
        *(_QWORD *)&leftStyle[24] = v66;
        *(_QWORD *)&leftStyle[32] = v65;
        *(_QWORD *)&leftStyle[40] = v60;
        *(_QWORD *)ay = v58;
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&this->pMorphData.pObject->ShapeData1);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&this->pMorphData.pObject->ShapeData2);
        v53 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _BYTE *, _BYTE *, char *))v3->vfptr[8].__vecDelDtor)(
                v3,
                v56,
                &leftStyle[16],
                v71);
        p_ShapeData1 = &this->pMorphData.pObject->ShapeData1;
        if ( !v53 )
          goto LABEL_124;
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
          p_ShapeData1,
          *(unsigned int *)leftStyle,
          *(unsigned int *)&leftStyle[4],
          *(unsigned int *)&leftStyle[8]);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
          &this->pMorphData.pObject->ShapeData2,
          *(unsigned int *)leftStyle,
          *(unsigned int *)&leftStyle[4],
          *(unsigned int *)&leftStyle[8]);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
          &this->pMorphData.pObject->ShapeData1,
          v44,
          v45);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
          &this->pMorphData.pObject->ShapeData2,
          *(float *)&leftStyle[16],
          *(float *)&leftStyle[20]);
        v43 = *(float *)&leftStyle[16];
        v42 = *(float *)&leftStyle[20];
      }
    }
    v50 = &this->pMorphData.pObject->ShapeData1;
    if ( !v49 )
    {
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v50);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&this->pMorphData.pObject->ShapeData2);
      v39 = v76;
      continue;
    }
    break;
  }
  *(_QWORD *)v56 = v46;
  *(_OWORD *)&v56[8] = v47;
  *(_OWORD *)&v56[24] = v77;
  *(_QWORD *)&v56[40] = v78;
  v57 = v67;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v50);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&this->pMorphData.pObject->ShapeData2);
  v51 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _BYTE *, _BYTE *, _BYTE *))pObject->vfptr[8].__vecDelDtor)(
          pObject,
          leftStyle,
          &leftStyle[40],
          leftStyle);
  p_ShapeData1 = &this->pMorphData.pObject->ShapeData1;
  if ( v51 )
  {
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      p_ShapeData1,
      *(unsigned int *)leftStyle,
      *(unsigned int *)&leftStyle[4],
      *(unsigned int *)&leftStyle[8]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData2,
      *(unsigned int *)leftStyle,
      *(unsigned int *)&leftStyle[4],
      *(unsigned int *)&leftStyle[8]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData1,
      *(float *)&leftStyle[40],
      *(float *)&leftStyle[44]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData2,
      v43,
      v42);
    goto LABEL_101;
  }
LABEL_124:
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(p_ShapeData1);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(&this->pMorphData.pObject->ShapeData2);
}

// File Line: 442
// RVA: 0x9DC8E0
void __fastcall Scaleform::Render::ShapeMeshProvider::countComplexFills(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *paths,
        unsigned __int64 i1,
        unsigned __int64 i2,
        Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  unsigned __int64 v7; // r14
  unsigned int v8; // ebx
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // r8
  __int64 v13; // rsi
  unsigned int v14; // ebx
  Scaleform::MemoryHeapVtbl *v15; // rax
  __int64 *v16; // rax
  unsigned int v17; // ebx
  unsigned int v18; // edi
  unsigned __int64 Size; // rax
  unsigned __int64 v20; // rsi
  unsigned __int64 v21; // r8
  __int64 v22; // rsi
  unsigned int v23; // ebx
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  __int64 *v25; // rax
  void (__fastcall ***v26)(_QWORD, __int64); // rcx
  char v27[8]; // [rsp+28h] [rbp-28h] BYREF
  __int64 v28; // [rsp+30h] [rbp-20h]
  __int64 v29; // [rsp+38h] [rbp-18h] BYREF
  __int64 *v30; // [rsp+40h] [rbp-10h]
  Scaleform::MemoryHeap *v31; // [rsp+48h] [rbp-8h]
  __int64 v32; // [rsp+98h] [rbp+48h]

  v29 = 32i64;
  v30 = (__int64 *)((char *)&v29 + 4);
  v31 = Scaleform::Memory::pGlobalHeap;
  *(_QWORD *)&dl->StartFill = (unsigned int)this->FillToStyleTable.Data.Size;
  if ( i1 < i2 )
  {
    v7 = i1;
    v32 = i2 - i1;
    while ( paths->Data[v7].Styles[0] == paths->Data[v7].Styles[1] )
    {
LABEL_48:
      ++v7;
      if ( !--v32 )
        goto LABEL_49;
    }
    v28 = 0i64;
    v8 = paths->Data[v7].Styles[0];
    if ( !v8 )
      goto LABEL_24;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
      this->pShapeData.pObject,
      v8,
      v27);
    v9 = 0;
    if ( v28 )
      v9 = v8;
    if ( v9 < (unsigned int)v29 && (*((_DWORD *)v30 + ((unsigned __int64)v9 >> 5)) & (1 << (v9 & 0x1F))) != 0 )
    {
LABEL_24:
      v17 = paths->Data[v7].Styles[1];
      if ( !v17 )
        goto LABEL_44;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
        this->pShapeData.pObject,
        v17,
        v27);
      v18 = 0;
      if ( v28 )
        v18 = v17;
      if ( v18 < (unsigned int)v29 && (*((_DWORD *)v30 + ((unsigned __int64)v18 >> 5)) & (1 << (v18 & 0x1F))) != 0 )
        goto LABEL_44;
      Size = this->FillToStyleTable.Data.Size;
      v20 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v20 > this->FillToStyleTable.Data.Policy.Capacity )
        {
          v21 = v20 + (v20 >> 2);
          goto LABEL_34;
        }
      }
      else if ( v20 < this->FillToStyleTable.Data.Policy.Capacity >> 1 )
      {
        v21 = Size + 1;
LABEL_34:
        Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillToStyleTable,
          &this->FillToStyleTable,
          v21);
      }
      this->FillToStyleTable.Data.Size = v20;
      this->FillToStyleTable.Data.Data[v20 - 1] = v18;
      ++dl->FillCount;
      if ( v18 >= (unsigned int)v29 )
      {
        v22 = (unsigned int)(v29 + 31) >> 5;
        v23 = (v18 + 32) >> 5;
        if ( v23 < 2 * (int)v22 )
          v23 = 2 * v22;
        if ( v23 > (unsigned int)v22 )
        {
          vfptr = v31->vfptr;
          if ( v30 == (__int64 *)((char *)&v29 + 4) )
          {
            v30 = (__int64 *)vfptr->Alloc(v31, 4i64 * v23, 0i64);
            *(_DWORD *)v30 = HIDWORD(v29);
            v25 = v30;
          }
          else
          {
            v25 = (__int64 *)vfptr->Realloc(v31, v30, 4i64 * v23);
            v30 = v25;
          }
          memset((char *)v25 + 4 * v22, 0, 4i64 * (v23 - (unsigned int)v22));
          LODWORD(v29) = 32 * v23;
        }
      }
      *((_DWORD *)v30 + ((unsigned __int64)v18 >> 5)) |= 1 << (v18 & 0x1F);
LABEL_44:
      v26 = (void (__fastcall ***)(_QWORD, __int64))v28;
      if ( v28 && !_InterlockedDecrement((volatile signed __int32 *)(v28 + 8)) && v26 )
        (**v26)(v26, 1i64);
      goto LABEL_48;
    }
    v10 = this->FillToStyleTable.Data.Size;
    v11 = v10 + 1;
    if ( v10 + 1 >= v10 )
    {
      if ( v11 > this->FillToStyleTable.Data.Policy.Capacity )
      {
        v12 = v11 + (v11 >> 2);
        goto LABEL_14;
      }
    }
    else if ( v11 < this->FillToStyleTable.Data.Policy.Capacity >> 1 )
    {
      v12 = v10 + 1;
LABEL_14:
      Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillToStyleTable,
        &this->FillToStyleTable,
        v12);
    }
    this->FillToStyleTable.Data.Size = v11;
    this->FillToStyleTable.Data.Data[v11 - 1] = v9;
    ++dl->FillCount;
    if ( v9 >= (unsigned int)v29 )
    {
      v13 = (unsigned int)(v29 + 31) >> 5;
      v14 = (v9 + 32) >> 5;
      if ( v14 < 2 * (int)v13 )
        v14 = 2 * v13;
      if ( v14 > (unsigned int)v13 )
      {
        v15 = v31->vfptr;
        if ( v30 == (__int64 *)((char *)&v29 + 4) )
        {
          v30 = (__int64 *)v15->Alloc(v31, 4i64 * v14, 0i64);
          *(_DWORD *)v30 = HIDWORD(v29);
          v16 = v30;
        }
        else
        {
          v16 = (__int64 *)v15->Realloc(v31, v30, 4i64 * v14);
          v30 = v16;
        }
        memset((char *)v16 + 4 * v13, 0, 4i64 * (v14 - (unsigned int)v13));
        LODWORD(v29) = 32 * v14;
      }
    }
    *((_DWORD *)v30 + ((unsigned __int64)v9 >> 5)) |= 1 << (v9 & 0x1F);
    goto LABEL_24;
  }
LABEL_49:
  if ( v30 != (__int64 *)((char *)&v29 + 4) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))v31->vfptr->Free)(v31);
}

// File Line: 485
// RVA: 0x9DCDC0
void __fastcall Scaleform::Render::ShapeMeshProvider::createDrawLayers(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *paths,
        unsigned __int64 i1,
        unsigned __int64 i2)
{
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *v6; // rsi
  Scaleform::Render::ShapeMeshProvider *v7; // rdi
  unsigned __int64 v8; // r9
  unsigned int Pos; // ebx
  __int64 *v10; // rdx
  unsigned __int64 v11; // r14
  __int64 v12; // r15
  __int64 v13; // r8
  Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  __int64 v18; // rdx
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  __int64 *v20; // rax
  unsigned __int64 v21; // rdi
  __int64 v22; // rsi
  unsigned int v23; // ebx
  Scaleform::MemoryHeapVtbl *v24; // rax
  __int64 *v25; // rax
  __int64 v26; // r12
  unsigned int v27; // ebx
  int v28; // r14d
  unsigned __int64 v29; // r15
  Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *v30; // rdi
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // rsi
  unsigned __int64 v33; // r8
  __int64 v34; // rcx
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *Data; // rax
  __int64 v36; // rdi
  unsigned int v37; // ebx
  Scaleform::MemoryHeapVtbl *v38; // rax
  __int64 *v39; // rax
  Scaleform::Render::ShapeMeshProvider::DrawLayerType v40; // [rsp+38h] [rbp-40h] BYREF
  __int64 v41; // [rsp+50h] [rbp-28h] BYREF
  __int64 *v42; // [rsp+58h] [rbp-20h]
  Scaleform::MemoryHeap *v43; // [rsp+60h] [rbp-18h]
  unsigned int v46; // [rsp+D0h] [rbp+58h]
  unsigned __int64 v47; // [rsp+D8h] [rbp+60h]

  if ( i2 > i1 )
  {
    v6 = paths;
    v7 = this;
    v41 = 32i64;
    v42 = (__int64 *)((char *)&v41 + 4);
    v43 = Scaleform::Memory::pGlobalHeap;
    v8 = 24 * i1;
    v47 = 24 * i1;
    Pos = paths->Data[i1].Pos;
    v46 = Pos;
    v10 = (__int64 *)((char *)&v41 + 4);
    if ( i1 < i2 )
    {
      v11 = i1;
      v12 = i2 - i1;
      v13 = (unsigned int)v41;
      while ( 1 )
      {
        if ( v6->Data[v11].Styles[0] == v6->Data[v11].Styles[1] || (_DWORD)v13 && (*(_DWORD *)v10 & 1) != 0 )
          goto LABEL_20;
        Scaleform::Render::ShapeMeshProvider::countComplexFills(v7, v6, i1, i2, &v40);
        v40.StartPos = Pos;
        *(_QWORD *)&v40.StrokeStyle = 0i64;
        p_Data = &v7->DrawLayers.Data;
        Size = v7->DrawLayers.Data.Size;
        v16 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v16 > p_Data->Policy.Capacity )
          {
            v17 = v16 + (v16 >> 2);
            goto LABEL_13;
          }
        }
        else if ( v16 < p_Data->Policy.Capacity >> 1 )
        {
          v17 = Size + 1;
LABEL_13:
          Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_Data,
            p_Data,
            v17);
        }
        p_Data->Size = v16;
        v18 = (__int64)&p_Data->Data[v16];
        *(_DWORD *)(v18 - 20) = v46;
        *(_DWORD *)(v18 - 16) = v40.StartFill;
        *(_DWORD *)(v18 - 12) = v40.FillCount;
        *(_QWORD *)(v18 - 8) = 0i64;
        if ( !(_DWORD)v41 )
        {
          vfptr = v43->vfptr;
          if ( v42 == (__int64 *)((char *)&v41 + 4) )
          {
            v42 = (__int64 *)vfptr->Alloc(v43, 4ui64, 0i64);
            *(_DWORD *)v42 = HIDWORD(v41);
            v20 = v42;
          }
          else
          {
            v20 = (__int64 *)vfptr->Realloc(v43, v42, 4ui64);
            v42 = v20;
          }
          memset(v20, 0, 4ui64);
          LODWORD(v41) = 32;
        }
        *(_DWORD *)v42 |= 1u;
        v10 = v42;
        v13 = (unsigned int)v41;
LABEL_20:
        v21 = v6->Data[v11].Styles[2];
        if ( (_DWORD)v21 )
        {
          if ( (unsigned int)v21 >= (unsigned int)v13 )
          {
            v22 = (unsigned int)(v13 + 31) >> 5;
            v23 = (unsigned int)(v21 + 32) >> 5;
            if ( v23 < 2 * (int)v22 )
              v23 = 2 * v22;
            if ( v23 > (unsigned int)v22 )
            {
              v24 = v43->vfptr;
              if ( v10 == (__int64 *)((char *)&v41 + 4) )
              {
                v42 = (__int64 *)v24->Alloc(v43, 4i64 * v23, 0i64);
                *(_DWORD *)v42 = HIDWORD(v41);
                v25 = v42;
              }
              else
              {
                v25 = (__int64 *)v24->Realloc(v43, v10, 4i64 * v23);
                v42 = v25;
              }
              memset((char *)v25 + 4 * v22, 0, 4i64 * (v23 - (unsigned int)v22));
              LODWORD(v41) = 32 * v23;
              v10 = v42;
            }
            v6 = paths;
          }
          *((_DWORD *)v10 + (v21 >> 5)) |= 1 << (v21 & 0x1F);
          v10 = v42;
          v13 = (unsigned int)v41;
        }
        ++v11;
        --v12;
        v7 = this;
        if ( !v12 )
        {
          v8 = v47;
          goto LABEL_34;
        }
        Pos = v46;
      }
    }
    v13 = (unsigned int)v41;
LABEL_34:
    if ( i1 < i2 )
    {
      v26 = i2 - i1;
      while ( 1 )
      {
        v27 = *(unsigned int *)((char *)&v6->Data->Styles[2] + v8);
        if ( v27 )
        {
          if ( v27 < (unsigned int)v13 )
          {
            v28 = 1 << (v27 & 0x1F);
            v29 = 4 * ((unsigned __int64)v27 >> 5);
            if ( (v28 & *(_DWORD *)((_BYTE *)v10 + v29)) != 0 )
              break;
          }
        }
LABEL_54:
        v8 += 24i64;
        v47 = v8;
        if ( !--v26 )
          goto LABEL_55;
      }
      v30 = &v7->DrawLayers.Data;
      v31 = v30->Size;
      v32 = v31 + 1;
      if ( v31 + 1 >= v31 )
      {
        if ( v32 > v30->Policy.Capacity )
        {
          v33 = v32 + (v32 >> 2);
          goto LABEL_44;
        }
      }
      else if ( v32 < v30->Policy.Capacity >> 1 )
      {
        v33 = v31 + 1;
LABEL_44:
        Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v30,
          v30,
          v33);
      }
      v30->Size = v32;
      v34 = v32;
      Data = v30->Data;
      Data[v34 - 1].StartPos = v46;
      Data[v34 - 1].StartFill = 0;
      Data[v34 - 1].FillCount = 1;
      Data[v34 - 1].StrokeStyle = v27;
      Data[v34 - 1].Image9GridType = I9gNone;
      if ( v27 >= (unsigned int)v41 )
      {
        v36 = (unsigned int)(v41 + 31) >> 5;
        v37 = (v27 + 32) >> 5;
        if ( v37 < 2 * (int)v36 )
          v37 = 2 * v36;
        if ( v37 > (unsigned int)v36 )
        {
          v38 = v43->vfptr;
          if ( v42 == (__int64 *)((char *)&v41 + 4) )
          {
            v42 = (__int64 *)v38->Alloc(v43, 4i64 * v37, 0i64);
            *(_DWORD *)v42 = HIDWORD(v41);
            v39 = v42;
          }
          else
          {
            v39 = (__int64 *)v38->Realloc(v43, v42, 4i64 * v37);
            v42 = v39;
          }
          memset((char *)v39 + 4 * v36, 0, 4i64 * (v37 - (unsigned int)v36));
          LODWORD(v41) = 32 * v37;
        }
      }
      *(_DWORD *)((char *)v42 + v29) &= ~v28;
      v7 = this;
      this->Strokes = 1;
      v10 = v42;
      v13 = (unsigned int)v41;
      v8 = v47;
      v6 = paths;
      goto LABEL_54;
    }
LABEL_55:
    if ( v42 != (__int64 *)((char *)&v41 + 4) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, __int64 *, __int64, unsigned __int64))v43->vfptr->Free)(
        v43,
        v42,
        v13,
        v8);
  }
}oto LABEL_54;
    }
LABEL_55:
    if ( v42 != (__int64 *)((char *)&v41 + 4) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, __int64 *, __int64, unsigned

// File Line: 540
// RVA: 0x9C55B0
void __fastcall Scaleform::Render::ShapeMeshProvider::acquireShapeData(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::MorphShapeData *pObject; // rcx
  __int64 p_ShapeData1; // rcx
  __int64 *v4; // rdi
  char v5; // al
  Scaleform::Render::ShapeDataInterface *v6; // rcx
  Scaleform::Render::ShapeDataInterface *v7; // rcx
  __int64 v8; // rdi
  char v9; // bl
  unsigned int v10; // r14d
  unsigned int v11; // r15d
  int i; // eax
  unsigned int j; // ebx
  unsigned __int64 v14; // r11
  unsigned __int64 v15; // r10
  unsigned __int64 Size; // r9
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *Data; // rcx
  __int64 v18; // r8
  __int64 v19; // rdx
  unsigned int ShapeLayer; // eax
  unsigned __int64 v21; // r8
  unsigned __int64 v22; // rdi
  __int64 v23; // r14
  Scaleform::Render::Rect<float> *v24; // rax
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v28; // rdx
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v29; // rax
  unsigned __int64 v30; // r15
  __int64 v31; // r14
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v32; // rdi
  char v33; // [rsp+20h] [rbp-E0h]
  int v34[4]; // [rsp+28h] [rbp-D8h] BYREF
  unsigned int v35; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v36; // [rsp+3Ch] [rbp-C4h]
  __int64 v37; // [rsp+44h] [rbp-BCh]
  __int64 v38; // [rsp+4Ch] [rbp-B4h]
  __int64 v39; // [rsp+54h] [rbp-ACh]
  __int64 v40; // [rsp+5Ch] [rbp-A4h]
  int v41; // [rsp+64h] [rbp-9Ch]
  int v42; // [rsp+68h] [rbp-98h]
  char v43; // [rsp+6Ch] [rbp-94h]
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType val; // [rsp+70h] [rbp-90h] BYREF
  __int64 v45; // [rsp+88h] [rbp-78h]
  __int128 v46[2]; // [rsp+90h] [rbp-70h] BYREF
  char v47[24]; // [rsp+B0h] [rbp-50h] BYREF
  char v48[24]; // [rsp+C8h] [rbp-38h] BYREF
  char v49[16]; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> paths; // [rsp+F0h] [rbp-10h] BYREF
  int v51; // [rsp+450h] [rbp+350h] BYREF
  Scaleform::Render::ShapeDataInterface *v52; // [rsp+458h] [rbp+358h] BYREF
  __int64 v53; // [rsp+460h] [rbp+360h] BYREF

  v45 = -2i64;
  pObject = this->pMorphData.pObject;
  if ( pObject )
  {
    p_ShapeData1 = (__int64)&pObject->ShapeData1;
    if ( p_ShapeData1 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(p_ShapeData1 + 8), 1u);
    v53 = p_ShapeData1;
    v4 = &v53;
    v5 = 1;
    v6 = v52;
  }
  else
  {
    v7 = this->pShapeData.pObject;
    if ( v7 )
      _InterlockedExchangeAdd(&v7->RefCount, 1u);
    v6 = this->pShapeData.pObject;
    v52 = v6;
    v4 = (__int64 *)&v52;
    v5 = 2;
  }
  v8 = *v4;
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    v33 = v5;
    if ( v6 )
    {
      if ( !_InterlockedDecrement(&v6->RefCount) )
        v52->vfptr->__vecDelDtor(v52, 1u);
      v5 = v33;
    }
  }
  if ( (v5 & 1) != 0 && v53 && !_InterlockedDecrement((volatile signed __int32 *)(v53 + 8)) )
    (**(void (__fastcall ***)(__int64, __int64))v53)(v53, 1i64);
  v35 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 48i64))(v8);
  v36 = 0i64;
  v37 = 0i64;
  v38 = 0i64;
  v39 = 0i64;
  v40 = 0i64;
  v41 = 0;
  v42 = (int)FLOAT_1_0;
  v43 = 0;
  v9 = 1;
  v10 = 0;
  paths.pHeap = Scaleform::Memory::pGlobalHeap;
  paths.Size = 0i64;
  paths.Reserved = 32i64;
  paths.Data = paths.Static;
  this->Strokes = 0;
  v11 = v35;
  for ( i = (*(__int64 (__fastcall **)(__int64, unsigned int *, char *, int *))(*(_QWORD *)v8 + 64i64))(
              v8,
              &v35,
              v47,
              v34);
        i;
        i = (*(__int64 (__fastcall **)(__int64, unsigned int *, char *, int *))(*(_QWORD *)v8 + 64i64))(
              v8,
              &v35,
              v47,
              v34) )
  {
    if ( i == 2 && !v9 )
      ++v10;
    val.Pos = v11;
    val.ShapeLayer = v10;
    val.Styles[0] = v34[0];
    val.Styles[1] = v34[1];
    val.Styles[2] = v34[2];
    for ( j = 0;
          (*(unsigned int (__fastcall **)(__int64, unsigned int *, char *))(*(_QWORD *)v8 + 72i64))(v8, &v35, v48);
          ++j )
    {
      ;
    }
    val.EdgeCount = j;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2>::PushBack(&paths, &val);
    v9 = 0;
    v11 = v35;
  }
  v14 = 0i64;
  v15 = 0i64;
  Size = paths.Size;
  Data = paths.Data;
  if ( paths.Size )
  {
    v18 = 0i64;
    v19 = 0i64;
    do
    {
      if ( Data[v19].EdgeCount && (Data[v19].Styles[0] || Data[v19].Styles[1] || Data[v19].Styles[2]) )
      {
        Data[v18].ShapeLayer = Data[v19].ShapeLayer;
        Data[v18].Pos = Data[v19].Pos;
        Data[v18].Styles[0] = Data[v19].Styles[0];
        Data[v18].Styles[1] = Data[v19].Styles[1];
        Data[v18].Styles[2] = Data[v19].Styles[2];
        Data[v18].EdgeCount = Data[v19].EdgeCount;
        ++v14;
        ++v18;
        Data = paths.Data;
        Size = paths.Size;
      }
      ++v15;
      ++v19;
    }
    while ( v15 < Size );
    if ( v14 < Size )
      Size = v14;
    paths.Size = Size;
  }
  if ( this->DrawLayers.Data.Size && (this->DrawLayers.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->DrawLayers.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->DrawLayers.Data.Data = 0i64;
      Data = paths.Data;
      Size = paths.Size;
    }
    this->DrawLayers.Data.Policy.Capacity = 0i64;
  }
  this->DrawLayers.Data.Size = 0i64;
  if ( this->FillToStyleTable.Data.Size && (this->FillToStyleTable.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->FillToStyleTable.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->FillToStyleTable.Data.Data = 0i64;
      Data = paths.Data;
      Size = paths.Size;
    }
    this->FillToStyleTable.Data.Policy.Capacity = 0i64;
  }
  this->FillToStyleTable.Data.Size = 0i64;
  ShapeLayer = 0;
  v21 = 0i64;
  v22 = 0i64;
  if ( Size )
  {
    v23 = 0i64;
    do
    {
      if ( ShapeLayer != Data[v23].ShapeLayer )
      {
        Scaleform::Render::ShapeMeshProvider::createDrawLayers(this, &paths, v21, v22);
        v21 = v22;
        Data = paths.Data;
        ShapeLayer = paths.Data[v23].ShapeLayer;
        Size = paths.Size;
      }
      ++v22;
      ++v23;
    }
    while ( v22 < Size );
  }
  Scaleform::Render::ShapeMeshProvider::createDrawLayers(this, &paths, v21, Size);
  v46[0] = _xmm;
  v46[1] = (__int128)_xmm;
  v24 = this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetBounds(
          &this->Scaleform::Render::MeshProvider,
          v49,
          v46);
  y2 = v24->y2;
  x2 = v24->x2;
  y1 = v24->y1;
  this->IdentityBounds.x1 = v24->x1;
  this->IdentityBounds.y1 = y1;
  this->IdentityBounds.x2 = x2;
  this->IdentityBounds.y2 = y2;
  if ( Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(this) )
  {
    if ( this->DrawLayers.Data.Size <= 1 )
    {
      if ( !this->DrawLayers.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &this->DrawLayers.Data,
          &this->DrawLayers,
          1ui64);
    }
    else if ( (this->DrawLayers.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 2 )
    {
      v28 = this->DrawLayers.Data.Data;
      if ( v28 )
      {
        v29 = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       v28,
                                                                       80i64);
      }
      else
      {
        v51 = 2;
        v29 = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       &this->DrawLayers,
                                                                       80i64,
                                                                       &v51);
      }
      this->DrawLayers.Data.Data = v29;
      this->DrawLayers.Data.Policy.Capacity = 4i64;
    }
    this->DrawLayers.Data.Size = 1i64;
    this->DrawLayers.Data.Data->Image9GridType = I9gMergedSlice;
  }
  else
  {
    v30 = 0i64;
    if ( this->DrawLayers.Data.Size )
    {
      v31 = 0i64;
      do
      {
        v32 = &this->DrawLayers.Data.Data[v31];
        if ( !v32->StrokeStyle
          && Scaleform::Render::ShapeMeshProvider::checkI9gLayer(this, &this->DrawLayers.Data.Data[v31]) )
        {
          v32->Image9GridType = I9gNormalSlice;
        }
        ++v30;
        ++v31;
      }
      while ( v30 < this->DrawLayers.Data.Size );
    }
  }
  if ( paths.Data != paths.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 635
// RVA: 0x9D5990
bool __fastcall Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(Scaleform::Render::ShapeMeshProvider *this)
{
  int v2; // esi
  __int64 v3; // rdi
  unsigned int v4; // ebp
  __int64 v5; // rax
  void (__fastcall ***v6)(_QWORD, __int64); // rcx
  char v8[8]; // [rsp+28h] [rbp-30h] BYREF
  __int64 v9; // [rsp+30h] [rbp-28h]

  if ( !this->pMorphData.pObject )
  {
    v2 = 0;
    if ( this->DrawLayers.Data.Size == 9
      && ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[2].__vecDelDtor)(this->pShapeData.pObject) == 9
      && !((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[3].__vecDelDtor)(this->pShapeData.pObject) )
    {
      v3 = 0i64;
      v4 = 0;
      while ( 1 )
      {
        v9 = 0i64;
        ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
          this->pShapeData.pObject,
          ++v4,
          v8);
        if ( !v9 )
          break;
        v5 = *(_QWORD *)(v9 + 16);
        if ( v5 && (!v3 || v3 == v5) )
          ++v2;
        v3 = *(_QWORD *)(v9 + 16);
        v6 = (void (__fastcall ***)(_QWORD, __int64))v9;
        if ( !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) )
          (**v6)(v6, 1i64);
        if ( v4 >= 9 )
          return v2 == 9;
      }
    }
  }
  return 0;
}

// File Line: 676
// RVA: 0x9D5810
char __fastcall Scaleform::Render::ShapeMeshProvider::checkI9gLayer(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  __int64 v3; // rdx
  __int64 v4; // rbx
  void (__fastcall ***v5)(_QWORD, __int64); // rcx
  void (__fastcall ***v7)(_QWORD, __int64); // rcx
  unsigned int v8; // [rsp+18h] [rbp-29h] BYREF
  unsigned int v9; // [rsp+1Ch] [rbp-25h]
  int v10; // [rsp+20h] [rbp-21h]
  char v11[8]; // [rsp+28h] [rbp-19h] BYREF
  __int64 v12; // [rsp+30h] [rbp-11h]
  unsigned int StartPos; // [rsp+38h] [rbp-9h] BYREF
  __int64 v14; // [rsp+3Ch] [rbp-5h]
  __int64 v15; // [rsp+44h] [rbp+3h]
  __int64 v16; // [rsp+4Ch] [rbp+Bh]
  __int64 v17; // [rsp+54h] [rbp+13h]
  __int64 v18; // [rsp+5Ch] [rbp+1Bh]
  int v19; // [rsp+64h] [rbp+23h]
  int v20; // [rsp+68h] [rbp+27h]
  char v21; // [rsp+6Ch] [rbp+2Bh]
  __int64 v22; // [rsp+70h] [rbp+2Fh]
  char v23[40]; // [rsp+78h] [rbp+37h] BYREF

  v22 = -2i64;
  if ( this->pMorphData.pObject )
    return 0;
  StartPos = dl->StartPos;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 0i64;
  v19 = 0;
  v20 = (int)FLOAT_1_0;
  v21 = 0;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, char *, unsigned int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
         this->pShapeData.pObject,
         &StartPos,
         v23,
         &v8)
     - 1 > 1 )
    return 0;
  v3 = v9;
  if ( (v8 == 0) == (v9 == 0) || v10 )
    return 0;
  if ( v8 )
    v3 = v8;
  v12 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
    this->pShapeData.pObject,
    v3,
    v11);
  v4 = v12;
  if ( !v12
    || !*(_QWORD *)(v12 + 16)
    || Scaleform::Render::Matrix2x4<float>::IsFreeRotation((Scaleform::Render::Matrix2x4<float> *)(v12 + 32), 0.000001)
    || (*(_BYTE *)(v4 + 64) & 1) == 0
    || (this->pShapeData.pObject->vfptr[10].__vecDelDtor(this->pShapeData.pObject, (unsigned int)&StartPos),
        (((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, char *, unsigned int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
           this->pShapeData.pObject,
           &StartPos,
           v23,
           &v8) & 0xFFFFFFFD) != 0) )
  {
    v7 = (void (__fastcall ***)(_QWORD, __int64))v12;
    if ( v12 && !_InterlockedDecrement((volatile signed __int32 *)(v12 + 8)) && v7 )
      (**v7)(v7, 1i64);
    return 0;
  }
  v5 = (void (__fastcall ***)(_QWORD, __int64))v12;
  if ( v12 && !_InterlockedDecrement((volatile signed __int32 *)(v12 + 8)) )
  {
    if ( v5 )
      (**v5)(v5, 1i64);
  }
  return 1;
}

// File Line: 734
// RVA: 0x984010
void __fastcall Scaleform::Render::ShapeMeshProvider::GetFillStyle(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *f1,
        float morphRatio)
{
  float v7; // xmm0_4
  float v8; // xmm0_4
  void (__fastcall ***v9)(_QWORD, __int64); // rcx
  char v10[8]; // [rsp+30h] [rbp-28h] BYREF
  __int64 v11; // [rsp+38h] [rbp-20h]
  unsigned int v12; // [rsp+60h] [rbp+8h]

  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(this->pShapeData.pObject);
  if ( this->pMorphData.pObject && morphRatio != 0.0 )
  {
    v11 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pMorphData.pObject->pMorphTo.pObject->vfptr[4].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      idx,
      v10);
    if ( !f1->pFill.pObject )
    {
      v7 = (float)(unsigned __int8)BYTE2(f1->Color);
      BYTE2(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[2] - v7) * morphRatio) + v7) + 0.5);
      v8 = (float)(unsigned __int8)BYTE1(f1->Color);
      BYTE1(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[1] - v8) * morphRatio) + v8) + 0.5);
      LOBYTE(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[0]
                                                       - (float)(unsigned __int8)f1->Color)
                                               * morphRatio)
                                       + (float)(unsigned __int8)f1->Color)
                               + 0.5);
      HIBYTE(v12) = (int)(float)((float)((float)((float)((float)(unsigned __int8)v10[3] - (float)HIBYTE(f1->Color))
                                               * morphRatio)
                                       + (float)HIBYTE(f1->Color))
                               + 0.5);
      f1->Color = v12;
    }
    v9 = (void (__fastcall ***)(_QWORD, __int64))v11;
    if ( v11 && !_InterlockedDecrement((volatile signed __int32 *)(v11 + 8)) )
    {
      if ( v9 )
        (**v9)(v9, 1i64);
    }
  }
}

// File Line: 752
// RVA: 0x98C3F0
void __fastcall Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *s1,
        float morphRatio)
{
  float v7; // xmm0_4
  float v8; // xmm0_4
  float Color; // xmm0_4
  float Color_high; // xmm0_4
  void (__fastcall ***v11)(_QWORD, __int64); // rcx
  void (__fastcall ***v12)(_QWORD, __int64); // rcx
  float v13[4]; // [rsp+30h] [rbp-48h] BYREF
  unsigned __int8 v14; // [rsp+40h] [rbp-38h]
  unsigned __int8 v15; // [rsp+41h] [rbp-37h]
  unsigned __int8 v16; // [rsp+42h] [rbp-36h]
  unsigned __int8 v17; // [rsp+43h] [rbp-35h]
  __int64 v18; // [rsp+48h] [rbp-30h]
  __int64 v19; // [rsp+50h] [rbp-28h]
  unsigned int v20; // [rsp+80h] [rbp+8h]

  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[5].__vecDelDtor)(this->pShapeData.pObject);
  if ( this->pMorphData.pObject && morphRatio != 0.0 )
  {
    v18 = 0i64;
    v19 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))this->pMorphData.pObject->pMorphTo.pObject->vfptr[5].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      idx,
      v13);
    s1->Width = (float)((float)(v13[0] - s1->Width) * morphRatio) + s1->Width;
    if ( !s1->pFill.pObject )
    {
      v7 = (float)(unsigned __int8)BYTE2(s1->Color);
      BYTE2(v20) = (int)(float)((float)((float)((float)((float)v16 - v7) * morphRatio) + v7) + 0.5);
      v8 = (float)(unsigned __int8)BYTE1(s1->Color);
      BYTE1(v20) = (int)(float)((float)((float)((float)((float)v15 - v8) * morphRatio) + v8) + 0.5);
      Color = (float)(unsigned __int8)s1->Color;
      LOBYTE(v20) = (int)(float)((float)((float)((float)((float)v14 - Color) * morphRatio) + Color) + 0.5);
      Color_high = (float)HIBYTE(s1->Color);
      HIBYTE(v20) = (int)(float)((float)((float)((float)((float)v17 - Color_high) * morphRatio) + Color_high) + 0.5);
      s1->Color = v20;
    }
    v11 = (void (__fastcall ***)(_QWORD, __int64))v19;
    if ( v19 && !_InterlockedDecrement((volatile signed __int32 *)(v19 + 8)) && v11 )
      (**v11)(v11, 1i64);
    v12 = (void (__fastcall ***)(_QWORD, __int64))v18;
    if ( v18 && !_InterlockedDecrement((volatile signed __int32 *)(v18 + 8)) )
    {
      if ( v12 )
        (**v12)(v12, 1i64);
    }
  }
}

// File Line: 774
// RVA: 0x9C6E80
void __fastcall Scaleform::Render::ShapeMeshProvider::addFill(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr)
{
  Scaleform::Render::ShapeMeshProvider *v7; // r15
  char v8; // r13
  int v9; // edi
  Scaleform::Render::Tessellator *p_mTess; // r14
  int v11; // edi
  Scaleform::Render::ShapeDataInterface *pObject; // rcx
  unsigned int v13; // edx
  bool v14; // r15
  void (__fastcall ***v15)(_QWORD, __int64); // rcx
  Scaleform::Render::ShapeDataInterface *v16; // rcx
  float v17; // r10d
  bool v18; // di
  void (__fastcall ***v19)(_QWORD, __int64); // rcx
  Scaleform::Render::MorphShapeData *v20; // rcx
  Scaleform::Render::ShapeDataInterface *v21; // rcx
  BOOL pos2; // [rsp+20h] [rbp-A8h]
  float x2; // [rsp+40h] [rbp-88h] BYREF
  float y2; // [rsp+44h] [rbp-84h] BYREF
  float x3; // [rsp+48h] [rbp-80h] BYREF
  float y3[2]; // [rsp+4Ch] [rbp-7Ch] BYREF
  float y4[2]; // [rsp+54h] [rbp-74h] BYREF
  unsigned int v28; // [rsp+5Ch] [rbp-6Ch]
  int v29; // [rsp+60h] [rbp-68h]
  char v30; // [rsp+64h] [rbp-64h]
  float v31; // [rsp+68h] [rbp-60h] BYREF
  __int64 v32; // [rsp+6Ch] [rbp-5Ch]
  __int64 v33; // [rsp+74h] [rbp-54h]
  Scaleform::Render::ShapePosInfo v34; // [rsp+7Ch] [rbp-4Ch] BYREF
  char v35; // [rsp+B4h] [rbp-14h]
  Scaleform::Render::ShapePosInfo v36; // [rsp+B8h] [rbp-10h] BYREF
  Scaleform::Render::MorphInterpolator v37; // [rsp+F8h] [rbp+30h] BYREF
  char v38[80]; // [rsp+198h] [rbp+D0h] BYREF
  Scaleform::Render::ShapeMeshProvider *v39; // [rsp+1E8h] [rbp+120h]
  Scaleform::Render::MeshGenerator *v40; // [rsp+1F0h] [rbp+128h]
  float v41; // [rsp+208h] [rbp+140h]
  float ratio; // [rsp+210h] [rbp+148h]

  *(_QWORD *)&v36.NumStrokeBits = -2i64;
  v7 = this;
  v31 = v41;
  v32 = 0i64;
  v33 = 0i64;
  v34.Pos = 0;
  *(_QWORD *)y3 = 0i64;
  *(_QWORD *)y4 = 0i64;
  v28 = 0;
  v29 = 1065353216;
  v30 = 0;
  *(float *)&v34.StartX = v41;
  memset(&v34.StartY, 0, 44);
  *(_DWORD *)&v34.Initialized = 1065353216;
  v35 = 0;
  v8 = 1;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v37,
    this->pShapeData.pObject,
    this->pMorphData.pObject,
    ratio,
    &v36);
  while ( 1 )
  {
    if ( v37.pMorphData.pObject )
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, float *, float *, float *))v37.pMorphData.pObject->ShapeData1.vfptr[8].__vecDelDtor)(
             &v37.pMorphData.pObject->ShapeData1,
             &v31,
             &x2,
             &y4[1]);
      ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, unsigned int *, char *))v37.pMorphData.pObject->ShapeData2.vfptr[8].__vecDelDtor)(
        &v37.pMorphData.pObject->ShapeData2,
        &v37.Pos2,
        &v36.Fill1,
        v38);
      if ( !v9 )
        break;
      x2 = x2 + (float)((float)(*(float *)&v36.Fill1 - x2) * v37.MorphRatio);
      y2 = y2 + (float)((float)(*(float *)&v36.Stroke - y2) * v37.MorphRatio);
    }
    else
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, float *))v37.pShapeData.pObject->vfptr[8].__vecDelDtor)(
             v37.pShapeData.pObject,
             &v31,
             &x2,
             &y4[1]);
    }
    if ( !v9 || !v8 && v9 == 2 )
      break;
    v8 = 0;
    if ( LODWORD(y4[1]) == v28 )
    {
      if ( v37.pMorphData.pObject )
      {
        v37.pMorphData.pObject->ShapeData1.vfptr[10].__vecDelDtor(
          &v37.pMorphData.pObject->ShapeData1,
          (unsigned int)&v31);
        v37.pMorphData.pObject->ShapeData2.vfptr[10].__vecDelDtor(
          &v37.pMorphData.pObject->ShapeData2,
          (unsigned int)&v37.Pos2);
      }
      else
      {
        v37.pShapeData.pObject->vfptr[10].__vecDelDtor(v37.pShapeData.pObject, (unsigned int)&v31);
      }
    }
    else
    {
      tr->vfptr->Transform(tr, &x2, &y2);
      p_mTess = &gen->mTess;
LABEL_11:
      ((void (__fastcall *)(Scaleform::Render::Tessellator *))p_mTess->vfptr->AddVertex)(p_mTess);
      while ( 1 )
      {
        if ( v37.pMorphData.pObject )
        {
          v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, float *, float *))v37.pMorphData.pObject->ShapeData1.vfptr[9].__vecDelDtor)(
                  &v37.pMorphData.pObject->ShapeData1,
                  &v31,
                  &x2);
          ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *))v37.pMorphData.pObject->ShapeData2.vfptr[9].__vecDelDtor)(
            &v37.pMorphData.pObject->ShapeData2,
            &v37.Pos2,
            &v31);
          if ( !v11 )
            break;
          x2 = x2 + (float)((float)(v31 - x2) * v37.MorphRatio);
          y2 = y2 + (float)((float)(*(float *)&v32 - y2) * v37.MorphRatio);
          if ( (unsigned int)(v11 - 2) <= 1 )
          {
            x3 = x3 + (float)((float)(*((float *)&v32 + 1) - x3) * v37.MorphRatio);
            y3[0] = y3[0] + (float)((float)(*(float *)&v33 - y3[0]) * v37.MorphRatio);
            if ( v11 == 3 )
            {
              y3[1] = y3[1] + (float)((float)(*((float *)&v33 + 1) - y3[1]) * v37.MorphRatio);
              y4[0] = y4[0] + (float)((float)(*(float *)&v34.Pos - y4[0]) * v37.MorphRatio);
            }
          }
        }
        else
        {
          v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *))v37.pShapeData.pObject->vfptr[9].__vecDelDtor)(
                  v37.pShapeData.pObject,
                  &v31,
                  &x2);
        }
        if ( !v11 )
          break;
        switch ( v11 )
        {
          case 1:
            tr->vfptr->Transform(tr, &x2, &y2);
            goto LABEL_11;
          case 2:
            tr->vfptr->Transform(tr, &x2, &y2);
            tr->vfptr->Transform(tr, &x3, y3);
            Scaleform::Render::TessellateQuadCurve(p_mTess, param, x2, y2, x3, y3[0]);
            break;
          case 3:
            tr->vfptr->Transform(tr, &x2, &y2);
            tr->vfptr->Transform(tr, &x3, y3);
            tr->vfptr->Transform(tr, &y3[1], y4);
            Scaleform::Render::TessellateCubicCurve(p_mTess, param, x2, y2, x3, y3[0], y3[1], y4[0]);
            break;
        }
      }
      pObject = v7->pShapeData.pObject;
      v13 = v28;
      if ( v28 )
      {
        *(_QWORD *)&v36.StrokeBase = 0i64;
        ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, int *))pObject->vfptr[4].__vecDelDtor)(
          pObject,
          v28,
          &v36.LastY);
        v14 = *(_QWORD *)&v36.StrokeBase != 0i64;
        v15 = *(void (__fastcall ****)(_QWORD, __int64))&v36.StrokeBase;
        if ( *(_QWORD *)&v36.StrokeBase
          && !_InterlockedDecrement((volatile signed __int32 *)(*(_QWORD *)&v36.StrokeBase + 8i64))
          && v15 )
        {
          (**v15)(v15, 1i64);
        }
        v13 = v28;
      }
      else
      {
        v14 = 0;
      }
      v16 = v39->pShapeData.pObject;
      v17 = y4[1];
      if ( LODWORD(y4[1]) )
      {
        *(_QWORD *)&v36.StartY = 0i64;
        ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, Scaleform::Render::ShapePosInfo *))v16->vfptr[4].__vecDelDtor)(
          v16,
          LODWORD(y4[1]),
          &v36);
        v18 = *(_QWORD *)&v36.StartY != 0i64;
        v19 = *(void (__fastcall ****)(_QWORD, __int64))&v36.StartY;
        if ( *(_QWORD *)&v36.StartY
          && !_InterlockedDecrement((volatile signed __int32 *)(*(_QWORD *)&v36.StartY + 8i64))
          && v19 )
        {
          (**v19)(v19, 1i64);
        }
        v13 = v28;
        v17 = y4[1];
      }
      else
      {
        v18 = 0;
      }
      LOBYTE(pos2) = v14;
      p_mTess->vfptr->FinalizePath(p_mTess, LODWORD(v17), v13, v18, pos2);
      v7 = v39;
      gen = v40;
    }
  }
  v20 = v37.pMorphData.pObject;
  if ( v37.pMorphData.pObject && !_InterlockedDecrement(&v37.pMorphData.pObject->RefCount) && v20 )
    v20->vfptr->__vecDelDtor(v20, 1u);
  v21 = v37.pShapeData.pObject;
  if ( v37.pShapeData.pObject && !_InterlockedDecrement(&v37.pShapeData.pObject->RefCount) && v21 )
    v21->vfptr->__vecDelDtor(v21, 1u);
}

// File Line: 864
// RVA: 0x9CA960
void __fastcall Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr)
{
  unsigned __int64 v7; // rsi
  float v8; // xmm6_4
  char v9; // r14
  int v10; // ebx
  float v11; // xmm3_4
  float v12; // xmm2_4
  char v13; // r9
  float v14; // xmm1_4
  int v15; // ebx
  float v16; // xmm9_4
  float v17; // xmm8_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  Scaleform::Render::DashArray *pObject; // rdi
  double v21; // xmm0_8
  Scaleform::Render::StrokeSorter::VertexType *v22; // rdx
  Scaleform::Render::MorphShapeData *v23; // rcx
  Scaleform::Render::ShapeDataInterface *v24; // rcx
  Scaleform::Render::DashArray *v25; // rcx
  Scaleform::Render::ComplexFill *v26; // rcx
  BOOL pos2; // [rsp+20h] [rbp-B8h]
  float v28; // [rsp+30h] [rbp-A8h] BYREF
  float y; // [rsp+34h] [rbp-A4h]
  float v30; // [rsp+38h] [rbp-A0h]
  float v31; // [rsp+3Ch] [rbp-9Ch]
  float v32; // [rsp+40h] [rbp-98h]
  float v33; // [rsp+44h] [rbp-94h]
  int v34; // [rsp+48h] [rbp-90h] BYREF
  __int64 v35; // [rsp+4Ch] [rbp-8Ch]
  __int64 v36; // [rsp+54h] [rbp-84h] BYREF
  __int64 v37; // [rsp+5Ch] [rbp-7Ch]
  __int64 v38; // [rsp+64h] [rbp-74h]
  Scaleform::Render::ShapePosInfo v39; // [rsp+6Ch] [rbp-6Ch] BYREF
  char v40; // [rsp+A4h] [rbp-34h]
  char v41[8]; // [rsp+A8h] [rbp-30h] BYREF
  int v42; // [rsp+B0h] [rbp-28h]
  Scaleform::Render::StrokeStyleType s1; // [rsp+B8h] [rbp-20h] BYREF
  __int64 v44; // [rsp+E0h] [rbp+8h]
  int v45[8]; // [rsp+E8h] [rbp+10h] BYREF
  Scaleform::Render::MorphInterpolator v46; // [rsp+108h] [rbp+30h] BYREF
  char v47[120]; // [rsp+1A8h] [rbp+D0h] BYREF
  Scaleform::Render::ToleranceParams *parama; // [rsp+238h] [rbp+160h]
  void *retaddr; // [rsp+248h] [rbp+170h]
  unsigned int idx; // [rsp+250h] [rbp+178h]
  float offsetY; // [rsp+258h] [rbp+180h]

  v44 = -2i64;
  v34 = (int)retaddr;
  v7 = 0i64;
  v35 = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  v38 = 0i64;
  v39.Pos = 0;
  v39.StartX = (int)retaddr;
  memset(&v39.StartY, 0, 44);
  *(_DWORD *)&v39.Initialized = 1065353216;
  v40 = 0;
  s1.pFill.pObject = 0i64;
  s1.pDashes.pObject = 0i64;
  v8 = *(float *)&param;
  Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(this, idx, &s1, *(float *)&param);
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v46,
    this->pShapeData.pObject,
    this->pMorphData.pObject,
    v8,
    (Scaleform::Render::ShapePosInfo *)&v39.StartX);
  v9 = 1;
  while ( 1 )
  {
LABEL_2:
    if ( !v46.pMorphData.pObject )
    {
      v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, char *))v46.pShapeData.pObject->vfptr[8].__vecDelDtor)(
              v46.pShapeData.pObject,
              &v34,
              &v28,
              v41);
LABEL_6:
      v11 = v28;
      v12 = y;
      goto LABEL_7;
    }
    v10 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, int *, float *, char *))v46.pMorphData.pObject->ShapeData1.vfptr[8].__vecDelDtor)(
            &v46.pMorphData.pObject->ShapeData1,
            &v34,
            &v28,
            v41);
    ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, int *, char *))v46.pMorphData.pObject->ShapeData2.vfptr[8].__vecDelDtor)(
      &v46.pMorphData.pObject->ShapeData2,
      &v46.Pos2,
      v45,
      v47);
    if ( !v10 )
      goto LABEL_6;
    v11 = v28 + (float)((float)(*(float *)v45 - v28) * v46.MorphRatio);
    v28 = v11;
    v12 = y + (float)((float)(*(float *)&v45[1] - y) * v46.MorphRatio);
    y = v12;
LABEL_7:
    if ( !v10 || !v9 && v10 == 2 )
      break;
    v9 = 0;
    if ( v42 == idx )
    {
LABEL_11:
      v13 = 1;
      v14 = v11;
LABEL_12:
      Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, v14, v12, v13);
      while ( v46.pMorphData.pObject )
      {
        v15 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, int *, float *))v46.pMorphData.pObject->ShapeData1.vfptr[9].__vecDelDtor)(
                &v46.pMorphData.pObject->ShapeData1,
                &v34,
                &v28);
        ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, char *))v46.pMorphData.pObject->ShapeData2.vfptr[9].__vecDelDtor)(
          &v46.pMorphData.pObject->ShapeData2,
          &v46.Pos2,
          (char *)&v36 + 4);
        if ( !v15 )
          goto LABEL_19;
        v11 = v28 + (float)((float)(*((float *)&v36 + 1) - v28) * v46.MorphRatio);
        v28 = v11;
        v12 = y + (float)((float)(*(float *)&v37 - y) * v46.MorphRatio);
        y = v12;
        v16 = v30;
        v17 = v31;
        if ( (unsigned int)(v15 - 2) <= 1 )
        {
          v16 = v30 + (float)((float)(*((float *)&v37 + 1) - v30) * v46.MorphRatio);
          v30 = v16;
          v17 = v31 + (float)((float)(*(float *)&v38 - v31) * v46.MorphRatio);
          v31 = v17;
          if ( v15 == 3 )
          {
            v32 = v32 + (float)((float)(*((float *)&v38 + 1) - v32) * v46.MorphRatio);
            v33 = v33 + (float)((float)(*(float *)&v39.Pos - v33) * v46.MorphRatio);
          }
        }
LABEL_20:
        switch ( v15 )
        {
          case 0:
            LOBYTE(pos2) = 0;
            gen->mStrokeSorter.vfptr->FinalizePath(&gen->mStrokeSorter, 0, 0, 0, pos2);
            goto LABEL_2;
          case 1:
            goto LABEL_11;
          case 2:
            Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, v11, v12, 2);
            v13 = 2;
            v12 = v17;
            v14 = v16;
            goto LABEL_12;
          case 3:
            v18 = v33;
            v19 = v32;
            Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, v11, v12, 3);
            Scaleform::Render::StrokeSorter::AddVertexNV(&gen->mStrokeSorter, v16, v17, 3);
            v13 = 3;
            v12 = v18;
            v14 = v19;
            goto LABEL_12;
        }
      }
      v15 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v46.pShapeData.pObject->vfptr[9].__vecDelDtor)(
              v46.pShapeData.pObject,
              &v34,
              &v28);
LABEL_19:
      v11 = v28;
      v12 = y;
      v16 = v30;
      v17 = v31;
      goto LABEL_20;
    }
    if ( v46.pMorphData.pObject )
    {
      v46.pMorphData.pObject->ShapeData1.vfptr[10].__vecDelDtor(&v46.pMorphData.pObject->ShapeData1, (unsigned int)&v34);
      v46.pMorphData.pObject->ShapeData2.vfptr[10].__vecDelDtor(
        &v46.pMorphData.pObject->ShapeData2,
        (unsigned int)&v46.Pos2);
    }
    else
    {
      v46.pShapeData.pObject->vfptr[10].__vecDelDtor(v46.pShapeData.pObject, (unsigned int)&v34);
    }
  }
  Scaleform::Render::StrokeSorter::Sort(&gen->mStrokeSorter);
  pObject = s1.pDashes.pObject;
  if ( s1.pDashes.pObject )
  {
    v21 = ((double (__fastcall *)(Scaleform::Render::TransformerBase *))tr->vfptr->GetScale)(tr);
    Scaleform::Render::StrokeSorter::GenerateDashes(&gen->mStrokeSorter, pObject, parama, *(float *)&v21);
    pObject = s1.pDashes.pObject;
  }
  if ( gen->mStrokeSorter.OutVertices.Size )
  {
    do
    {
      v22 = &gen->mStrokeSorter.OutVertices.Pages[v7 >> 4][v7 & 0xF];
      tr->vfptr->Transform(tr, (float *)v22, &v22->y);
      ++v7;
    }
    while ( v7 < gen->mStrokeSorter.OutVertices.Size );
    pObject = s1.pDashes.pObject;
  }
  if ( (s1.Flags & 1) != 0 )
  {
    if ( !pObject )
      Scaleform::Render::StrokeSorter::Snap(&gen->mStrokeSorter, offsetY, offsetY);
  }
  else if ( offsetY > 0.0 )
  {
    Scaleform::Render::StrokeSorter::AddOffset(&gen->mStrokeSorter, offsetY, offsetY);
  }
  v23 = v46.pMorphData.pObject;
  if ( v46.pMorphData.pObject && !_InterlockedDecrement(&v46.pMorphData.pObject->RefCount) && v23 )
    v23->vfptr->__vecDelDtor(v23, 1u);
  v24 = v46.pShapeData.pObject;
  if ( v46.pShapeData.pObject && !_InterlockedDecrement(&v46.pShapeData.pObject->RefCount) && v24 )
    v24->vfptr->__vecDelDtor(v24, 1u);
  v46.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v25 = s1.pDashes.pObject;
  if ( s1.pDashes.pObject && !_InterlockedDecrement(&s1.pDashes.pObject->RefCount) && v25 )
    v25->vfptr->__vecDelDtor(v25, 1u);
  v26 = s1.pFill.pObject;
  if ( s1.pFill.pObject && !_InterlockedDecrement(&s1.pFill.pObject->RefCount) && v26 )
    v26->vfptr->__vecDelDtor(v26, 1u);
}

// File Line: 943
// RVA: 0x9C99E0
void __fastcall Scaleform::Render::ShapeMeshProvider::addStroke(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        Scaleform::Render::TessBase *stroker,
        Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        unsigned int strokeStyleIdx,
        float snapOffset,
        float morphRatio)
{
  unsigned int i; // r12d
  unsigned __int64 v13; // r15
  __int64 v14; // rdi
  unsigned int v15; // ebx
  unsigned int v16; // r14d
  unsigned int v17; // ecx
  Scaleform::Render::StrokeSorter::PathType *v18; // r8
  unsigned int v19; // eax
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r10
  __int64 v21; // rdx
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ebx
  char v26; // r9
  unsigned __int64 v27; // rax
  unsigned int v28; // ecx
  float *v29; // r9
  unsigned int v30; // eax
  float *v31; // rcx
  unsigned int v32; // ecx
  unsigned int v33; // eax
  float *p_x; // rcx
  BOOL x3; // [rsp+20h] [rbp-48h]

  Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
    this,
    gen,
    param,
    tr,
    startPos,
    strokeStyleIdx,
    snapOffset,
    morphRatio);
  (*((void (__fastcall **)(Scaleform::Render::TessBase *))&stroker->vfptr->__vecDelDtor + 1))(stroker);
  for ( i = 0; i < LODWORD(gen->mStrokeSorter.OutPaths.Size); ++i )
  {
    v13 = (unsigned __int64)i >> 4;
    v14 = i & 0xF;
    v15 = 0;
    v16 = gen->mStrokeSorter.OutPaths.Pages[v13][v14].numVer & 0xFFFFFFF;
    if ( v16 )
    {
      do
      {
        v17 = v15;
        v18 = gen->mStrokeSorter.OutPaths.Pages[v13];
        v19 = v18[v14].numVer & 0xFFFFFFF;
        if ( v15 >= v19 )
          v17 = v15 - v19;
        Pages = gen->mStrokeSorter.OutVertices.Pages;
        ++v15;
        v21 = (__int64)&Pages[(unsigned __int64)(v17 + v18[v14].start) >> 4][((_BYTE)v17 + LOBYTE(v18[v14].start)) & 0xF];
        switch ( *(_BYTE *)(v21 + 12) )
        {
          case 1:
            ((void (__fastcall *)(Scaleform::Render::TessBase *))stroker->vfptr->AddVertex)(stroker);
            break;
          case 2:
            v32 = v15;
            v33 = v18[v14].numVer & 0xFFFFFFF;
            if ( v15 >= v33 )
              v32 = v15 - v33;
            ++v15;
            p_x = &Pages[(unsigned __int64)(v32 + v18[v14].start) >> 4][((_BYTE)v32 + LOBYTE(v18[v14].start)) & 0xF].x;
            Scaleform::Render::TessellateQuadCurve(stroker, param, *(float *)v21, *(float *)(v21 + 4), *p_x, p_x[1]);
            break;
          case 3:
            v22 = v15;
            v23 = v18[v14].numVer & 0xFFFFFFF;
            if ( v15 >= v23 )
              v22 = v15 - v23;
            v24 = v18[v14].start + v22;
            v25 = v15 + 1;
            v26 = v24;
            v27 = v24;
            v28 = v25;
            v29 = &Pages[v27 >> 4][v26 & 0xF].x;
            v30 = v18[v14].numVer & 0xFFFFFFF;
            if ( v25 >= v30 )
              v28 = v25 - v30;
            v15 = v25 + 1;
            v31 = &Pages[(unsigned __int64)(v28 + v18[v14].start) >> 4][((_BYTE)v28 + LOBYTE(v18[v14].start)) & 0xF].x;
            Scaleform::Render::TessellateCubicCurve(
              stroker,
              param,
              *(float *)v21,
              *(float *)(v21 + 4),
              *v29,
              v29[1],
              *v31,
              v31[1]);
            break;
        }
      }
      while ( v15 < v16 );
    }
    LOBYTE(x3) = 0;
    stroker->vfptr->FinalizePath(stroker, 0, 0, 0, x3);
  }
}

// File Line: 988
// RVA: 0x9C9780
void __fastcall Scaleform::Render::ShapeMeshProvider::addStroke(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        unsigned int strokeStyleIdx,
        float snapOffset,
        float morphRatio)
{
  unsigned int i; // r12d
  unsigned __int64 v11; // r15
  __int64 v12; // rdi
  unsigned int v13; // ebx
  unsigned int v14; // r14d
  unsigned int v15; // ecx
  Scaleform::Render::StrokeSorter::PathType *v16; // r8
  unsigned int v17; // eax
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r10
  __int64 v19; // rdx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ebx
  char v24; // r9
  unsigned __int64 v25; // rax
  unsigned int v26; // ecx
  float *v27; // r9
  unsigned int v28; // eax
  float *v29; // rcx
  unsigned int v30; // ecx
  unsigned int v31; // eax
  float *p_x; // rcx

  Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
    this,
    gen,
    param,
    tr,
    startPos,
    strokeStyleIdx,
    snapOffset,
    morphRatio);
  (*((void (__fastcall **)(Scaleform::Render::Stroker *))&gen->mStroker.vfptr->__vecDelDtor + 1))(&gen->mStroker);
  for ( i = 0; i < LODWORD(gen->mStrokeSorter.OutPaths.Size); ++i )
  {
    v11 = (unsigned __int64)i >> 4;
    v12 = i & 0xF;
    v13 = 0;
    v14 = gen->mStrokeSorter.OutPaths.Pages[v11][v12].numVer & 0xFFFFFFF;
    if ( v14 )
    {
      do
      {
        v15 = v13;
        v16 = gen->mStrokeSorter.OutPaths.Pages[v11];
        v17 = v16[v12].numVer & 0xFFFFFFF;
        if ( v13 >= v17 )
          v15 = v13 - v17;
        Pages = gen->mStrokeSorter.OutVertices.Pages;
        ++v13;
        v19 = (__int64)&Pages[(unsigned __int64)(v15 + v16[v12].start) >> 4][((_BYTE)v15 + LOBYTE(v16[v12].start)) & 0xF];
        switch ( *(_BYTE *)(v19 + 12) )
        {
          case 1:
            ((void (__fastcall *)(Scaleform::Render::Stroker *))gen->mStroker.vfptr->AddVertex)(&gen->mStroker);
            break;
          case 2:
            v30 = v13;
            v31 = v16[v12].numVer & 0xFFFFFFF;
            if ( v13 >= v31 )
              v30 = v13 - v31;
            ++v13;
            p_x = &Pages[(unsigned __int64)(v30 + v16[v12].start) >> 4][((_BYTE)v30 + LOBYTE(v16[v12].start)) & 0xF].x;
            Scaleform::Render::TessellateQuadCurve(
              &gen->mStroker,
              param,
              *(float *)v19,
              *(float *)(v19 + 4),
              *p_x,
              p_x[1]);
            break;
          case 3:
            v20 = v13;
            v21 = v16[v12].numVer & 0xFFFFFFF;
            if ( v13 >= v21 )
              v20 = v13 - v21;
            v22 = v16[v12].start + v20;
            v23 = v13 + 1;
            v24 = v22;
            v25 = v22;
            v26 = v23;
            v27 = &Pages[v25 >> 4][v24 & 0xF].x;
            v28 = v16[v12].numVer & 0xFFFFFFF;
            if ( v23 >= v28 )
              v26 = v23 - v28;
            v13 = v23 + 1;
            v29 = &Pages[(unsigned __int64)(v26 + v16[v12].start) >> 4][((_BYTE)v26 + LOBYTE(v16[v12].start)) & 0xF].x;
            Scaleform::Render::TessellateCubicCurve(
              &gen->mStroker,
              param,
              *(float *)v19,
              *(float *)(v19 + 4),
              *v27,
              v27[1],
              *v29,
              v29[1]);
            break;
        }
      }
      while ( v13 < v14 );
    }
    Scaleform::Render::Stroker::GenerateStroke(&gen->mStroker, &gen->mTess);
  }
}

// File Line: 1030
// RVA: 0x9DE380
char __fastcall Scaleform::Render::ShapeMeshProvider::createNullMesh(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::VertexOutput *pout,
        unsigned int drawLayer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::VertexOutputVtbl *vfptr; // rax
  char result; // al
  __int64 v7; // [rsp+30h] [rbp-38h] BYREF
  int v8[2]; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::Render::VertexFormat *v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+48h] [rbp-20h]
  __int64 v11; // [rsp+50h] [rbp-18h]
  __int16 v12; // [rsp+78h] [rbp+10h] BYREF
  int v13; // [rsp+7Ah] [rbp+12h]

  v9 = &Scaleform::Render::VertexXY16iCF32::Format;
  vfptr = pout->vfptr;
  v7 = 0i64;
  v13 = 0;
  v12 = 0;
  v10 = 0i64;
  v11 = 0i64;
  v8[0] = 1;
  v8[1] = 3;
  result = vfptr->BeginOutput(
             pout,
             (Scaleform::Render::VertexOutput::Fill *)v8,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    pout->vfptr->SetVertices(pout, 0, 0, &v7, 1u);
    pout->vfptr->SetIndices(pout, 0, 0, (unsigned __int16 *)&v12, 3u);
    pout->vfptr->EndOutput(pout);
    return 1;
  }
  return result;
}

// File Line: 1058
// RVA: 0x9C5AA0
_BOOL8 __fastcall Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::Matrix2x4<float> *mtx,
        Scaleform::Render::VertexOutput *pout,
        unsigned int drawLayerIdx,
        unsigned int strokeStyleIdx,
        unsigned int meshGenFlags,
        float morphRatio)
{
  Scaleform::Render::TessBase *v10; // rdi
  Scaleform::Render::ShapeMeshProvider *v11; // r13
  unsigned int v12; // r12d
  unsigned int v13; // r15d
  unsigned int v14; // eax
  __int64 v15; // rdi
  unsigned int v16; // r9d
  unsigned int i; // r8d
  unsigned int v18; // r14d
  unsigned int v19; // esi
  unsigned int v20; // edi
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // r9d
  unsigned int v24; // r8d
  Scaleform::Render::VertexOutput *v25; // rdx
  Scaleform::Log *DefaultLog; // rax
  Scaleform::Render::VertexOutput *v27; // rsi
  bool NullMesh; // di
  int v29; // r15d
  int v30; // r12d
  __int64 v31; // rcx
  unsigned int v32; // ebx
  char *v33; // rsi
  char *v34; // rdi
  __int64 v35; // r14
  __m128 v36; // xmm1
  int v37; // ecx
  __m128 v38; // xmm2
  int v39; // ecx
  unsigned int Color; // eax
  unsigned __int64 v41; // rax
  unsigned int v42; // edx
  unsigned int v43; // edx
  unsigned int v44; // edx
  unsigned __int64 v45; // rcx
  unsigned int v46; // esi
  unsigned int v47; // r14d
  __int64 v48; // r15
  unsigned int v49; // edi
  unsigned int v50; // r14d
  Scaleform::Render::ComplexFill *pObject; // rcx
  Scaleform::Render::ComplexFill *v52; // rcx
  Scaleform::Render::DashArray *v53; // rcx
  Scaleform::Render::ComplexFill *v54; // rcx
  unsigned int v56; // [rsp+30h] [rbp-D0h]
  int v57; // [rsp+34h] [rbp-CCh]
  int v58; // [rsp+38h] [rbp-C8h]
  unsigned int v59; // [rsp+3Ch] [rbp-C4h]
  unsigned int v60; // [rsp+40h] [rbp-C0h]
  unsigned int val; // [rsp+44h] [rbp-BCh] BYREF
  Scaleform::Render::VertexOutput::Fill *v62; // [rsp+48h] [rbp-B8h]
  Scaleform::Render::FillStyleType f1; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::VertexOutput::Fill v64; // [rsp+60h] [rbp-A0h] BYREF
  char v65[4]; // [rsp+80h] [rbp-80h] BYREF
  int v66; // [rsp+84h] [rbp-7Ch]
  int v67; // [rsp+88h] [rbp-78h]
  int v68; // [rsp+8Ch] [rbp-74h]
  int v69; // [rsp+98h] [rbp-68h]
  Scaleform::Render::FillStyleType v70; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::Render::StrokeStyleType s1; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v72; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::Render::Matrix2x4<float> v73; // [rsp+140h] [rbp+40h] BYREF
  __int64 v74; // [rsp+160h] [rbp+60h]
  char v75[32]; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2> v76; // [rsp+190h] [rbp+90h] BYREF
  char v77[1536]; // [rsp+3B0h] [rbp+2B0h] BYREF
  char v78[4]; // [rsp+9B0h] [rbp+8B0h] BYREF
  char v79; // [rsp+9B4h] [rbp+8B4h] BYREF
  char v80[12]; // [rsp+15B0h] [rbp+14B0h] BYREF
  char v81; // [rsp+15BCh] [rbp+14BCh] BYREF

  v74 = -2i64;
  v10 = tess;
  v11 = this;
  s1.pFill.pObject = 0i64;
  s1.pDashes.pObject = 0i64;
  v76.pHeap = Scaleform::Memory::pGlobalHeap;
  v76.Size = 0i64;
  v76.Reserved = 16i64;
  v76.Data = v76.Static;
  v72.pHeap = Scaleform::Memory::pGlobalHeap;
  v72.Size = 0i64;
  v72.Reserved = 16i64;
  v72.Data = v72.Static;
  if ( !tess->vfptr->GetMeshCount(tess) || !v10->vfptr->GetVertexCount(v10) )
  {
    v23 = meshGenFlags;
    v24 = drawLayerIdx;
    v25 = pout;
    goto LABEL_79;
  }
  v12 = meshGenFlags;
  v13 = drawLayerIdx;
  if ( strokeStyleIdx )
  {
    Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(v11, strokeStyleIdx, &s1, morphRatio);
  }
  else
  {
    v14 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v11->pShapeData.pObject->vfptr[2].__vecDelDtor)(v11->pShapeData.pObject)
        + 1;
    if ( v14 )
    {
      val = 0;
      v15 = v14;
      do
      {
        Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v72, &val);
        --v15;
      }
      while ( v15 );
      v10 = tess;
    }
    v16 = v11->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->GetFillCount(
            &v11->Scaleform::Render::MeshProvider,
            drawLayerIdx,
            meshGenFlags);
    for ( i = 0; i < v16; ++i )
      v72.Data[v11->FillToStyleTable.Data.Data[i + v11->DrawLayers.Data.Data[drawLayerIdx].StartFill]] = i;
  }
  *(_OWORD *)&v73.M[0][0] = _xmm;
  *(__m128 *)&v73.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v73, mtx);
  v10->vfptr->Transform(v10, &v73);
  ((void (__fastcall *)(Scaleform::Render::TessBase *, char *))v10->vfptr->StretchTo)(v10, v75);
  v18 = 0;
  v19 = 0;
  if ( v10->vfptr->GetMeshCount(v10) )
  {
    do
    {
      v10->vfptr->GetMesh(v10, v19, (Scaleform::Render::TessMesh *)v65);
      v20 = v10->vfptr->GetMeshVertexCount(v10, v19);
      v64.VertexCount = v20;
      v21 = 3
          * ((__int64 (__fastcall *)(Scaleform::Render::TessBase *, _QWORD))tess->vfptr->GetMeshTriangleCount)(
              tess,
              v19);
      v64.IndexCount = v21;
      if ( v20 && v21 )
      {
        v64.pFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        *(_QWORD *)&v64.FillIndex0 = 0i64;
        if ( !strokeStyleIdx )
        {
          v64.FillIndex0 = v72.Data[v66];
          v64.FillIndex1 = v72.Data[v67];
        }
        v22 = 1;
        if ( (v68 & 0x8000) != 0 )
          v22 = 3;
        v64.MergeFlags = v22;
        v64.MeshIndex = v19;
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2>::PushBack(&v76, &v64);
        v18 += v69;
      }
      ++v19;
      v10 = tess;
    }
    while ( v19 < tess->vfptr->GetMeshCount(tess) );
    v13 = drawLayerIdx;
    v12 = meshGenFlags;
    v11 = this;
  }
  if ( !v76.Size )
  {
    v23 = v12;
    v24 = v13;
    v25 = pout;
LABEL_79:
    NullMesh = Scaleform::Render::ShapeMeshProvider::createNullMesh(v11, v25, v24, v23);
    goto LABEL_80;
  }
  if ( v18 > 0xFFFF )
  {
    DefaultLog = Scaleform::SF_GlobalLog;
    if ( Scaleform::SF_GlobalLog || (DefaultLog = Scaleform::Log::GetDefaultLog()) != 0i64 )
      Scaleform::Log::LogWarning(
        DefaultLog,
        "Render_ShapeMeshProvider: More than 65535 vertices, the shape cannot be displayed");
    v23 = v12;
    v24 = v13;
    v25 = pout;
    goto LABEL_79;
  }
  v27 = pout;
  if ( !pout->vfptr->BeginOutput(pout, v76.Data, v76.Size, (Scaleform::Render::Matrix2x4<float> *)v75) )
  {
    NullMesh = 0;
    goto LABEL_80;
  }
  v29 = 0;
  v57 = 0;
  v30 = 0;
  v58 = 0;
  f1.pFill.pObject = 0i64;
  v70.pFill.pObject = 0i64;
  v56 = 0;
  if ( v76.Size )
  {
    v31 = 0i64;
    while ( 1 )
    {
      v62 = &v76.Data[v31];
      v10->vfptr->GetMesh(v10, v62->MeshIndex, (Scaleform::Render::TessMesh *)v65);
      v60 = 0;
      v32 = v10->vfptr->GetVertices(v10, (Scaleform::Render::TessMesh *)v65, (Scaleform::Render::TessVertex *)v80, 256u);
      v59 = v32;
      if ( !v32 )
        goto LABEL_62;
      do
      {
        v33 = &v79;
        v34 = &v81;
        v35 = v32;
        do
        {
          v36 = (__m128)*((unsigned int *)v34 - 3);
          if ( v36.m128_f32[0] >= 0.0 )
            v36.m128_f32[0] = v36.m128_f32[0] + 0.5;
          else
            v36.m128_f32[0] = v36.m128_f32[0] - 0.5;
          v37 = (int)v36.m128_f32[0];
          if ( (int)v36.m128_f32[0] != 0x80000000 && (float)v37 != v36.m128_f32[0] )
            v36.m128_f32[0] = (float)(v37 - (_mm_movemask_ps(_mm_unpacklo_ps(v36, v36)) & 1));
          *((_WORD *)v33 - 2) = (int)v36.m128_f32[0];
          v38 = (__m128)*((unsigned int *)v34 - 2);
          if ( v38.m128_f32[0] >= 0.0 )
            v38.m128_f32[0] = v38.m128_f32[0] + 0.5;
          else
            v38.m128_f32[0] = v38.m128_f32[0] - 0.5;
          v39 = (int)v38.m128_f32[0];
          if ( (int)v38.m128_f32[0] != 0x80000000 && (float)v39 != v38.m128_f32[0] )
            v38.m128_f32[0] = (float)(v39 - (_mm_movemask_ps(_mm_unpacklo_ps(v38, v38)) & 1));
          *((_WORD *)v33 - 1) = (int)v38.m128_f32[0];
          if ( strokeStyleIdx )
          {
            Color = s1.Color;
          }
          else
          {
            *(_DWORD *)v33 = 0;
            v41 = *((unsigned __int16 *)v34 + 2);
            if ( (v41 & 0x8000) != 0 )
              goto LABEL_60;
            if ( (v41 & 0x10) != 0 )
            {
              v42 = *(unsigned __int16 *)v34;
              if ( v29 != v42 )
              {
                Scaleform::Render::ShapeMeshProvider::GetFillStyle(v11, v42, &f1, morphRatio);
                v29 = *(unsigned __int16 *)v34;
              }
              v43 = *((unsigned __int16 *)v34 + 1);
              if ( v30 != v43 )
              {
                Scaleform::Render::ShapeMeshProvider::GetFillStyle(v11, v43, &v70, morphRatio);
                v30 = *((unsigned __int16 *)v34 + 1);
              }
              Color = ((f1.Color | v70.Color) >> 1) & 0x7F7F7F7F;
            }
            else
            {
              v44 = *(unsigned __int16 *)&v34[2 * ((v41 >> 5) & 1)];
              if ( v29 != v44 )
              {
                Scaleform::Render::ShapeMeshProvider::GetFillStyle(v11, v44, &f1, morphRatio);
                v29 = *(unsigned __int16 *)&v34[2 * (((unsigned __int64)*((unsigned __int16 *)v34 + 2) >> 5) & 1)];
              }
              Color = f1.Color;
            }
          }
          *(_DWORD *)v33 = Color;
LABEL_60:
          v45 = *((unsigned __int16 *)v34 + 2);
          v33[4] = Scaleform::Render::Factors[*((_WORD *)v34 + 2) & 3];
          v33[5] = Scaleform::Render::Factors[(v45 >> 2) & 3];
          v34 += 20;
          v33 += 12;
          --v35;
        }
        while ( v35 );
        v58 = v30;
        v57 = v29;
        v10 = tess;
        pout->vfptr->SetVertices(pout, v56, v60, v78, v59);
        v60 += v59;
        v32 = tess->vfptr->GetVertices(
                tess,
                (Scaleform::Render::TessMesh *)v65,
                (Scaleform::Render::TessVertex *)v80,
                256u);
        v59 = v32;
      }
      while ( v32 );
LABEL_62:
      v46 = 0;
      v47 = v10->vfptr->GetMeshTriangleCount(v10, v62->MeshIndex);
      if ( v47 )
      {
        v48 = (__int64)v62;
        do
        {
          v49 = 256;
          if ( v46 + 256 > v47 )
          {
            v49 = v47 - v46;
            if ( v47 == v46 )
              break;
          }
          tess->vfptr->GetTrianglesI16(tess, *(unsigned int *)(v48 + 28), (unsigned __int16 *)v77, v46, v49);
          pout->vfptr->SetIndices(pout, v56, 3 * v46, (unsigned __int16 *)v77, 3 * v49);
          v46 += v49;
        }
        while ( v46 < v47 );
        v29 = v57;
        v11 = this;
        v30 = v58;
        v10 = tess;
      }
      v50 = v56 + 1;
      v56 = v50;
      v31 = v50;
      if ( v50 >= v76.Size )
      {
        v27 = pout;
        break;
      }
    }
  }
  v27->vfptr->EndOutput(v27);
  NullMesh = 1;
  pObject = v70.pFill.pObject;
  if ( v70.pFill.pObject && !_InterlockedDecrement(&v70.pFill.pObject->RefCount) && pObject )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v52 = f1.pFill.pObject;
  if ( f1.pFill.pObject && !_InterlockedDecrement(&f1.pFill.pObject->RefCount) && v52 )
    v52->vfptr->__vecDelDtor(v52, 1u);
LABEL_80:
  if ( v72.Data != v72.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v72.Data = v72.Static;
  v72.Size = 0i64;
  if ( v76.Data != v76.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v76.Data = v76.Static;
  v76.Size = 0i64;
  v53 = s1.pDashes.pObject;
  if ( s1.pDashes.pObject && !_InterlockedDecrement(&s1.pDashes.pObject->RefCount) && v53 )
    v53->vfptr->__vecDelDtor(v53, 1u);
  v54 = s1.pFill.pObject;
  if ( s1.pFill.pObject && !_InterlockedDecrement(&s1.pFill.pObject->RefCount) && v54 )
    v54->vfptr->__vecDelDtor(v54, 1u);
  return NullMesh;
}tic;
  v76.Size = 0i64;
  v53 = s1.pDashes.pObject;
  if ( s1.pDashes.pObject && !_InterlockedDecr

// File Line: 1235
// RVA: 0x9F6370
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::tessellateFill(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Scale9GridInfo *s9g,
        unsigned int drawLayerIdx,
        Scaleform::Render::MeshBase *pmesh,
        Scaleform::Render::VertexOutput *pout,
        unsigned int meshGenFlags)
{
  Scaleform::Render::Renderer2DImpl *pRenderer2D; // rax
  Scaleform::Render::MeshGenerator *p_MeshGen; // rbx
  Scaleform::Render::Matrix2x4<float> *p_ViewMatrix; // rcx
  float MorphRatio; // xmm6_4
  unsigned int v12; // r12d
  Scaleform::Render::TransformerBase *p_tr; // r15
  bool v14; // si
  Scaleform::Render::Stroker *p_mStroker; // r13
  Scaleform::Render::StrokeSorter *p_mStrokeSorter; // rdi
  Scaleform::Render::Tessellator *p_mTess; // r14
  unsigned int v18; // esi
  unsigned __int64 MaxPages; // rax
  Scaleform::Render::LinearHeap::PageType *v20; // rdi
  unsigned __int64 v21; // rax
  Scaleform::Render::LinearHeap::PageType *v22; // rdi
  unsigned __int64 v23; // rax
  Scaleform::Render::LinearHeap::PageType *v24; // rdi
  unsigned __int64 v25; // rax
  Scaleform::Render::LinearHeap::PageType *v26; // rdi
  float v27; // xmm0_4
  Scaleform::Render::ShapeMeshProvider *v28; // rdi
  unsigned __int64 v29; // rax
  Scaleform::Render::LinearHeap::PageType *v30; // rdi
  unsigned __int64 v31; // rax
  Scaleform::Render::LinearHeap::PageType *v32; // rdi
  unsigned __int64 v33; // rax
  Scaleform::Render::LinearHeap::PageType *v34; // rdi
  unsigned __int64 v35; // rax
  Scaleform::Render::LinearHeap::PageType *v36; // rdi
  unsigned __int64 v37; // rax
  Scaleform::Render::LinearHeap::PageType *v38; // rdi
  unsigned __int64 v39; // rax
  Scaleform::Render::LinearHeap::PageType *v40; // rdi
  unsigned __int64 v41; // rax
  Scaleform::Render::LinearHeap::PageType *v42; // rdi
  unsigned __int64 v43; // rax
  Scaleform::Render::LinearHeap::PageType *v44; // rdi
  Scaleform::Render::Matrix2x4<float> m2; // [rsp+50h] [rbp-B0h] BYREF
  void **v47; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::Matrix2x4<float> *p_m2; // [rsp+78h] [rbp-88h]
  Scaleform::Render::TransformerBase tr; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Render::Scale9GridInfo *v50; // [rsp+88h] [rbp-78h]
  Scaleform::Render::ToleranceParams param; // [rsp+90h] [rbp-70h] BYREF
  __int64 v52; // [rsp+E0h] [rbp-20h]
  float key[36]; // [rsp+F0h] [rbp-10h] BYREF

  v52 = -2i64;
  pRenderer2D = pmesh->pRenderer2D;
  p_MeshGen = &pRenderer2D->MeshGen;
  p_ViewMatrix = &pmesh->ViewMatrix;
  MorphRatio = pmesh->MorphRatio;
  param = pRenderer2D->Tolerances;
  v47 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable;
  v12 = 0;
  p_m2 = 0i64;
  tr.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable;
  v50 = 0i64;
  *(_OWORD *)&m2.M[0][0] = _xmm;
  *(__m128 *)&m2.M[1][0] = _xmm;
  if ( s9g )
  {
    *(_OWORD *)&m2.M[0][0] = *(_OWORD *)&p_ViewMatrix->M[0][0];
    *(_OWORD *)&m2.M[1][0] = *(_OWORD *)&pmesh->ViewMatrix.M[1][0];
    v50 = s9g;
    p_tr = &tr;
  }
  else
  {
    if ( !Scaleform::Render::MeshKey::CalcMatrixKey(p_ViewMatrix, key, &m2) )
      return Scaleform::Render::ShapeMeshProvider::createNullMesh(this, pout, drawLayerIdx, meshGenFlags);
    p_m2 = &m2;
    p_tr = (Scaleform::Render::TransformerBase *)&v47;
  }
  p_mStroker = &p_MeshGen->mStroker;
  p_mStrokeSorter = &p_MeshGen->mStrokeSorter;
  p_mTess = &p_MeshGen->mTess;
  v18 = meshGenFlags;
  while ( 1 )
  {
    (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_mTess->vfptr->__vecDelDtor + 1))(&p_MeshGen->mTess.vfptr);
    (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_mStroker->vfptr->__vecDelDtor + 1))(&p_MeshGen->mStroker.vfptr);
    (*((void (__fastcall **)(Scaleform::Render::StrokeSorter *))&p_mStrokeSorter->vfptr->__vecDelDtor + 1))(p_mStrokeSorter);
    (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mHairliner.vfptr->__vecDelDtor + 1))(&p_MeshGen->mHairliner.vfptr);
    (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mStrokerAA.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokerAA.vfptr);
    MaxPages = p_MeshGen->Heap1.MaxPages;
    if ( MaxPages )
    {
      v20 = &p_MeshGen->Heap1.pPagePool[MaxPages - 1];
      do
      {
        --p_MeshGen->Heap1.MaxPages;
        if ( v20->pStart )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap1.pHeap->vfptr->Free)(p_MeshGen->Heap1.pHeap);
        --v20;
      }
      while ( p_MeshGen->Heap1.MaxPages );
      --p_MeshGen->Heap1.MaxPages;
      p_MeshGen->Heap1.pHeap->vfptr->Free(p_MeshGen->Heap1.pHeap, p_MeshGen->Heap1.pPagePool);
    }
    p_MeshGen->Heap1.pLastPage = 0i64;
    p_MeshGen->Heap1.pPagePool = 0i64;
    p_MeshGen->Heap1.MaxPages = 0i64;
    v21 = p_MeshGen->Heap2.MaxPages;
    if ( v21 )
    {
      v22 = &p_MeshGen->Heap2.pPagePool[v21 - 1];
      do
      {
        --p_MeshGen->Heap2.MaxPages;
        if ( v22->pStart )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap2.pHeap->vfptr->Free)(p_MeshGen->Heap2.pHeap);
        --v22;
      }
      while ( p_MeshGen->Heap2.MaxPages );
      --p_MeshGen->Heap2.MaxPages;
      p_MeshGen->Heap2.pHeap->vfptr->Free(p_MeshGen->Heap2.pHeap, p_MeshGen->Heap2.pPagePool);
    }
    p_MeshGen->Heap2.pLastPage = 0i64;
    p_MeshGen->Heap2.pPagePool = 0i64;
    p_MeshGen->Heap2.MaxPages = 0i64;
    v23 = p_MeshGen->Heap3.MaxPages;
    if ( v23 )
    {
      v24 = &p_MeshGen->Heap3.pPagePool[v23 - 1];
      do
      {
        --p_MeshGen->Heap3.MaxPages;
        if ( v24->pStart )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap3.pHeap->vfptr->Free)(p_MeshGen->Heap3.pHeap);
        --v24;
      }
      while ( p_MeshGen->Heap3.MaxPages );
      --p_MeshGen->Heap3.MaxPages;
      p_MeshGen->Heap3.pHeap->vfptr->Free(p_MeshGen->Heap3.pHeap, p_MeshGen->Heap3.pPagePool);
    }
    p_MeshGen->Heap3.pLastPage = 0i64;
    p_MeshGen->Heap3.pPagePool = 0i64;
    p_MeshGen->Heap3.MaxPages = 0i64;
    v25 = p_MeshGen->Heap4.MaxPages;
    if ( v25 )
    {
      v26 = &p_MeshGen->Heap4.pPagePool[v25 - 1];
      do
      {
        --p_MeshGen->Heap4.MaxPages;
        if ( v26->pStart )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap4.pHeap->vfptr->Free)(p_MeshGen->Heap4.pHeap);
        --v26;
      }
      while ( p_MeshGen->Heap4.MaxPages );
      --p_MeshGen->Heap4.MaxPages;
      p_MeshGen->Heap4.pHeap->vfptr->Free(p_MeshGen->Heap4.pHeap, p_MeshGen->Heap4.pPagePool);
    }
    p_MeshGen->Heap4.pLastPage = 0i64;
    p_MeshGen->Heap4.pPagePool = 0i64;
    p_MeshGen->Heap4.MaxPages = 0i64;
    p_MeshGen->mTess.FillRule = FillEvenOdd;
    p_MeshGen->mTess.StrokerMode = 0;
    p_MeshGen->mTess.Epsilon = param.Epsilon;
    p_MeshGen->mTess.HasEpsilon = param.Epsilon > 0.0;
    p_MeshGen->mTess.IntersectionEpsilon = param.IntersectionEpsilon;
    if ( (v18 & 1) == 0 || (v18 & 2) != 0 )
    {
      p_MeshGen->mTess.EdgeAAWidth = 0.0;
      p_MeshGen->mTess.EdgeAAFlag = 0;
    }
    else
    {
      v27 = param.EdgeAAScale * 0.5;
      p_MeshGen->mTess.EdgeAAWidth = param.EdgeAAScale * 0.5;
      p_MeshGen->mTess.EdgeAAFlag = v27 > 0.0;
    }
    Scaleform::Render::ShapeMeshProvider::addFill(this, p_MeshGen, &param, p_tr);
    if ( (v18 & 1) != 0 && LODWORD(p_MeshGen->mTess.SrcVertices.Size) >= 0x8000 )
    {
      Scaleform::Render::MeshGenerator::Clear(p_MeshGen);
      p_MeshGen->mTess.EdgeAAWidth = 0.0;
      p_MeshGen->mTess.EdgeAAFlag = 0;
      v28 = this;
      Scaleform::Render::ShapeMeshProvider::addFill(this, p_MeshGen, &param, p_tr);
      v18 &= ~1u;
    }
    else
    {
      v28 = this;
    }
    Scaleform::Render::Tessellator::Tessellate(&p_MeshGen->mTess, 0);
    if ( p_mTess->vfptr->GetVertexCount(&p_MeshGen->mTess) < 0xFFFF )
      break;
    v18 &= ~1u;
    param.CurveTolerance = param.CurveTolerance * 4.0;
    ++v12;
    p_mStrokeSorter = &p_MeshGen->mStrokeSorter;
    if ( v12 >= 4 )
    {
      (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_mTess->vfptr->__vecDelDtor + 1))(&p_MeshGen->mTess.vfptr);
      (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_mStroker->vfptr->__vecDelDtor + 1))(&p_MeshGen->mStroker.vfptr);
      (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mStrokeSorter.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokeSorter.vfptr);
      (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mHairliner.vfptr->__vecDelDtor + 1))(&p_MeshGen->mHairliner.vfptr);
      (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mStrokerAA.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokerAA.vfptr);
      v29 = p_MeshGen->Heap1.MaxPages;
      if ( v29 )
      {
        v30 = &p_MeshGen->Heap1.pPagePool[v29 - 1];
        do
        {
          --p_MeshGen->Heap1.MaxPages;
          if ( v30->pStart )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap1.pHeap->vfptr->Free)(p_MeshGen->Heap1.pHeap);
          --v30;
        }
        while ( p_MeshGen->Heap1.MaxPages );
        --p_MeshGen->Heap1.MaxPages;
        p_MeshGen->Heap1.pHeap->vfptr->Free(p_MeshGen->Heap1.pHeap, p_MeshGen->Heap1.pPagePool);
      }
      p_MeshGen->Heap1.pLastPage = 0i64;
      p_MeshGen->Heap1.pPagePool = 0i64;
      p_MeshGen->Heap1.MaxPages = 0i64;
      v31 = p_MeshGen->Heap2.MaxPages;
      if ( v31 )
      {
        v32 = &p_MeshGen->Heap2.pPagePool[v31 - 1];
        do
        {
          --p_MeshGen->Heap2.MaxPages;
          if ( v32->pStart )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap2.pHeap->vfptr->Free)(p_MeshGen->Heap2.pHeap);
          --v32;
        }
        while ( p_MeshGen->Heap2.MaxPages );
        --p_MeshGen->Heap2.MaxPages;
        p_MeshGen->Heap2.pHeap->vfptr->Free(p_MeshGen->Heap2.pHeap, p_MeshGen->Heap2.pPagePool);
      }
      p_MeshGen->Heap2.pLastPage = 0i64;
      p_MeshGen->Heap2.pPagePool = 0i64;
      p_MeshGen->Heap2.MaxPages = 0i64;
      v33 = p_MeshGen->Heap3.MaxPages;
      if ( v33 )
      {
        v34 = &p_MeshGen->Heap3.pPagePool[v33 - 1];
        do
        {
          --p_MeshGen->Heap3.MaxPages;
          if ( v34->pStart )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap3.pHeap->vfptr->Free)(p_MeshGen->Heap3.pHeap);
          --v34;
        }
        while ( p_MeshGen->Heap3.MaxPages );
        --p_MeshGen->Heap3.MaxPages;
        p_MeshGen->Heap3.pHeap->vfptr->Free(p_MeshGen->Heap3.pHeap, p_MeshGen->Heap3.pPagePool);
      }
      p_MeshGen->Heap3.pLastPage = 0i64;
      p_MeshGen->Heap3.pPagePool = 0i64;
      p_MeshGen->Heap3.MaxPages = 0i64;
      v35 = p_MeshGen->Heap4.MaxPages;
      if ( v35 )
      {
        v36 = &p_MeshGen->Heap4.pPagePool[v35 - 1];
        do
        {
          --p_MeshGen->Heap4.MaxPages;
          if ( v36->pStart )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap4.pHeap->vfptr->Free)(p_MeshGen->Heap4.pHeap);
          --v36;
        }
        while ( p_MeshGen->Heap4.MaxPages );
        --p_MeshGen->Heap4.MaxPages;
        p_MeshGen->Heap4.pHeap->vfptr->Free(p_MeshGen->Heap4.pHeap, p_MeshGen->Heap4.pPagePool);
      }
      p_MeshGen->Heap4.pLastPage = 0i64;
      p_MeshGen->Heap4.pPagePool = 0i64;
      p_MeshGen->Heap4.MaxPages = 0i64;
      return Scaleform::Render::ShapeMeshProvider::createNullMesh(this, pout, drawLayerIdx, v18);
    }
  }
  v14 = Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
          v28,
          &p_MeshGen->mTess,
          &m2,
          pout,
          drawLayerIdx,
          0,
          v18,
          MorphRatio);
  (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_mTess->vfptr->__vecDelDtor + 1))(&p_MeshGen->mTess.vfptr);
  (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_mStroker->vfptr->__vecDelDtor + 1))(&p_MeshGen->mStroker.vfptr);
  (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mStrokeSorter.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokeSorter.vfptr);
  (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mHairliner.vfptr->__vecDelDtor + 1))(&p_MeshGen->mHairliner.vfptr);
  (*((void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))&p_MeshGen->mStrokerAA.vfptr->__vecDelDtor + 1))(&p_MeshGen->mStrokerAA.vfptr);
  v37 = p_MeshGen->Heap1.MaxPages;
  if ( v37 )
  {
    v38 = &p_MeshGen->Heap1.pPagePool[v37 - 1];
    do
    {
      --p_MeshGen->Heap1.MaxPages;
      if ( v38->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap1.pHeap->vfptr->Free)(p_MeshGen->Heap1.pHeap);
      --v38;
    }
    while ( p_MeshGen->Heap1.MaxPages );
    --p_MeshGen->Heap1.MaxPages;
    p_MeshGen->Heap1.pHeap->vfptr->Free(p_MeshGen->Heap1.pHeap, p_MeshGen->Heap1.pPagePool);
  }
  p_MeshGen->Heap1.pLastPage = 0i64;
  p_MeshGen->Heap1.pPagePool = 0i64;
  p_MeshGen->Heap1.MaxPages = 0i64;
  v39 = p_MeshGen->Heap2.MaxPages;
  if ( v39 )
  {
    v40 = &p_MeshGen->Heap2.pPagePool[v39 - 1];
    do
    {
      --p_MeshGen->Heap2.MaxPages;
      if ( v40->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap2.pHeap->vfptr->Free)(p_MeshGen->Heap2.pHeap);
      --v40;
    }
    while ( p_MeshGen->Heap2.MaxPages );
    --p_MeshGen->Heap2.MaxPages;
    p_MeshGen->Heap2.pHeap->vfptr->Free(p_MeshGen->Heap2.pHeap, p_MeshGen->Heap2.pPagePool);
  }
  p_MeshGen->Heap2.pLastPage = 0i64;
  p_MeshGen->Heap2.pPagePool = 0i64;
  p_MeshGen->Heap2.MaxPages = 0i64;
  v41 = p_MeshGen->Heap3.MaxPages;
  if ( v41 )
  {
    v42 = &p_MeshGen->Heap3.pPagePool[v41 - 1];
    do
    {
      --p_MeshGen->Heap3.MaxPages;
      if ( v42->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap3.pHeap->vfptr->Free)(p_MeshGen->Heap3.pHeap);
      --v42;
    }
    while ( p_MeshGen->Heap3.MaxPages );
    --p_MeshGen->Heap3.MaxPages;
    p_MeshGen->Heap3.pHeap->vfptr->Free(p_MeshGen->Heap3.pHeap, p_MeshGen->Heap3.pPagePool);
  }
  p_MeshGen->Heap3.pLastPage = 0i64;
  p_MeshGen->Heap3.pPagePool = 0i64;
  p_MeshGen->Heap3.MaxPages = 0i64;
  v43 = p_MeshGen->Heap4.MaxPages;
  if ( v43 )
  {
    v44 = &p_MeshGen->Heap4.pPagePool[v43 - 1];
    do
    {
      --p_MeshGen->Heap4.MaxPages;
      if ( v44->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))p_MeshGen->Heap4.pHeap->vfptr->Free)(p_MeshGen->Heap4.pHeap);
      --v44;
    }
    while ( p_MeshGen->Heap4.MaxPages );
    --p_MeshGen->Heap4.MaxPages;
    p_MeshGen->Heap4.pHeap->vfptr->Free(p_MeshGen->Heap4.pHeap, p_MeshGen->Heap4.pPagePool);
  }
  p_MeshGen->Heap4.pLastPage = 0i64;
  p_MeshGen->Heap4.pPagePool = 0i64;
  p_MeshGen->Heap4.MaxPages = 0i64;
  return v14;
}

// File Line: 1329
// RVA: 0x9F6CC0
_BOOL8 __fastcall Scaleform::Render::ShapeMeshProvider::tessellateStroke(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Scale9GridInfo *s9g,
        unsigned int strokeStyleIdx,
        unsigned int drawLayerIdx)
{
  __int64 v4; // rdi
  __int64 v7; // r10
  __int64 v8; // rax
  __int64 v9; // rsi
  float v10; // xmm11_4
  float v11; // xmm9_4
  int v12; // xmm13_4
  __m128 v13; // xmm7
  __m128 v14; // xmm10
  __m128 v15; // xmm8
  int v16; // xmm14_4
  __m128 v17; // xmm6
  __int64 v18; // r12
  char v19; // r14
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // ecx
  int v23; // ecx
  Scaleform::Render::TransformerBase *tr; // r15
  float v25; // xmm0_4
  int v26; // eax
  __m128 v27; // xmm1
  float v28; // xmm3_4
  int v29; // ecx
  __m128 v30; // xmm2
  int v31; // ecx
  float snapOffset; // xmm4_4
  bool v33; // al
  bool v34; // cl
  float v35; // xmm6_4
  unsigned int v36; // r14d
  Scaleform::Render::TessBase *v37; // rdx
  int v38; // r8d
  int v39; // r10d
  int v40; // r9d
  int v41; // eax
  int v42; // edx
  float v43; // xmm1_4
  Scaleform::Render::TessBase *v44; // rbx
  float v45; // xmm1_4
  float v46; // xmm3_4
  float v47; // xmm3_4
  bool v48; // di
  Scaleform::Render::Matrix2x4<float> *v49; // rcx
  void **v50; // rcx
  Scaleform::Render::TransformerBase v52; // [rsp+48h] [rbp-80h] BYREF
  Scaleform::Render::Matrix2x4<float> mtx; // [rsp+50h] [rbp-78h] BYREF
  void **v54; // [rsp+70h] [rbp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> *v55; // [rsp+78h] [rbp-50h]
  float v56; // [rsp+88h] [rbp-40h]
  float v57; // [rsp+8Ch] [rbp-3Ch]
  int v58; // [rsp+90h] [rbp-38h]
  int v59; // [rsp+94h] [rbp-34h]
  int v60; // [rsp+98h] [rbp-30h]
  int v61; // [rsp+9Ch] [rbp-2Ch]
  int v62; // [rsp+A0h] [rbp-28h]
  int v63; // [rsp+A4h] [rbp-24h]
  void **v64; // [rsp+A8h] [rbp-20h]
  Scaleform::Render::Scale9GridInfo *v65; // [rsp+B0h] [rbp-18h]
  void **v66; // [rsp+B8h] [rbp-10h]
  Scaleform::Render::Matrix2x4<float> *p_mtx; // [rsp+C0h] [rbp-8h]
  __int64 v68; // [rsp+C8h] [rbp+0h]
  unsigned int startPos; // [rsp+1B8h] [rbp+F0h]
  unsigned int v70; // [rsp+1C8h] [rbp+100h]
  unsigned int drawLayerIdxa; // [rsp+1D0h] [rbp+108h]
  float morphRatio[2]; // [rsp+1D8h] [rbp+110h]
  Scaleform::Render::VertexOutput *vars0; // [rsp+1E0h] [rbp+118h]
  void *retaddr; // [rsp+1E8h] [rbp+120h]

  v68 = -2i64;
  v4 = drawLayerIdx;
  v7 = *(_QWORD *)morphRatio;
  v8 = *(_QWORD *)(*(_QWORD *)morphRatio + 80i64);
  v9 = v8 + 88;
  v10 = *(float *)(*(_QWORD *)morphRatio + 112i64);
  v56 = v10;
  v11 = *(float *)(*(_QWORD *)morphRatio + 116i64);
  v57 = v11;
  v12 = *(_DWORD *)(*(_QWORD *)morphRatio + 120i64);
  v58 = v12;
  v13 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 124i64);
  v59 = *(_DWORD *)(*(_QWORD *)morphRatio + 124i64);
  v14 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 128i64);
  v60 = *(_DWORD *)(*(_QWORD *)morphRatio + 128i64);
  v15 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 132i64);
  v61 = *(_DWORD *)(*(_QWORD *)morphRatio + 132i64);
  v16 = *(_DWORD *)(*(_QWORD *)morphRatio + 136i64);
  v62 = v16;
  v17 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 140i64);
  v63 = *(_DWORD *)(*(_QWORD *)morphRatio + 140i64);
  morphRatio[0] = *(float *)(*(_QWORD *)morphRatio + 144i64);
  v18 = v8 + 3288;
  v54 = 0i64;
  v55 = 0i64;
  Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(
    this,
    strokeStyleIdx,
    (Scaleform::Render::StrokeStyleType *)&mtx.M[0][2],
    *(float *)(v7 + 144));
  startPos = this->DrawLayers.Data.Data[v4].StartPos;
  if ( mtx.M[1][1] < 1.0 )
    mtx.M[1][1] = 1.0;
  v19 = LOBYTE(mtx.M[1][0]) & 1;
  if ( (LOBYTE(mtx.M[1][0]) & 1) != 0 )
  {
    v20 = FLOAT_N0_5;
    if ( v13.m128_f32[0] >= 0.0 )
      v21 = FLOAT_0_5;
    else
      v21 = FLOAT_N0_5;
    v13.m128_f32[0] = v13.m128_f32[0] + v21;
    v22 = (int)v13.m128_f32[0];
    if ( (int)v13.m128_f32[0] != 0x80000000 && (float)v22 != v13.m128_f32[0] )
      v13.m128_f32[0] = (float)(v22 - (_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1));
    v59 = v13.m128_i32[0];
    if ( v17.m128_f32[0] >= 0.0 )
      v20 = FLOAT_0_5;
    v17.m128_f32[0] = v17.m128_f32[0] + v20;
    v23 = (int)v17.m128_f32[0];
    if ( (int)v17.m128_f32[0] != 0x80000000 && (float)v23 != v17.m128_f32[0] )
      v17.m128_f32[0] = (float)(v23 - (_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1));
    v63 = v17.m128_i32[0];
  }
  *(_QWORD *)&mtx.M[0][2] = __PAIR64__(v13.m128_u32[0], v12);
  *(_QWORD *)&mtx.M[1][0] = __PAIR64__(v15.m128_u32[0], v14.m128_u32[0]);
  *(_QWORD *)&mtx.M[1][2] = __PAIR64__(v17.m128_u32[0], v16);
  v54 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable;
  v55 = 0i64;
  v52.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable;
  *(_QWORD *)&mtx.M[0][0] = 0i64;
  if ( s9g )
  {
    v65 = s9g;
    *(_QWORD *)&mtx.M[0][0] = s9g;
    v64 = &Scaleform::Render::TransformerBase::`vftable;
    tr = &v52;
  }
  else
  {
    p_mtx = &mtx;
    v55 = &mtx;
    v66 = &Scaleform::Render::TransformerBase::`vftable;
    tr = (Scaleform::Render::TransformerBase *)&v54;
  }
  Scaleform::Render::MeshGenerator::Clear((Scaleform::Render::MeshGenerator *)v9);
  v25 = mtx.M[0][3];
  if ( !s9g )
  {
    v26 = LOBYTE(mtx.M[1][0]) & 6;
    if ( (LOBYTE(mtx.M[1][0]) & 6) == 0 )
    {
      v11 = (float)(v11 + v10) * 0.70710677;
      v15.m128_f32[0] = (float)(v15.m128_f32[0] + v14.m128_f32[0]) * 0.70710677;
LABEL_26:
      v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v11 * v11);
      LODWORD(v25) = _mm_sqrt_ps(v15).m128_u32[0];
      goto LABEL_27;
    }
    if ( v26 == 2 )
    {
      v14.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v10 * v10);
      LODWORD(v25) = _mm_sqrt_ps(v14).m128_u32[0];
    }
    else if ( v26 == 4 )
    {
      goto LABEL_26;
    }
  }
LABEL_27:
  v27 = (__m128)LODWORD(mtx.M[0][2]);
  v27.m128_f32[0] = mtx.M[0][2] * v25;
  v28 = FLOAT_0_5;
  if ( ((unsigned __int8)retaddr & 1) == 0 || ((unsigned __int8)retaddr & 2) != 0 )
  {
    v28 = 0.0;
    v29 = (int)v27.m128_f32[0];
    if ( (int)v27.m128_f32[0] != 0x80000000 && (float)v29 != v27.m128_f32[0] )
      v27 = (__m128)COERCE_UNSIGNED_INT((float)(v29 - (_mm_movemask_ps(_mm_unpacklo_ps(v27, v27)) & 1)));
    v27.m128_f32[0] = v27.m128_f32[0] + 1.0;
  }
  if ( v19 )
  {
    if ( v27.m128_f32[0] < 1.26 )
      goto LABEL_40;
    v30 = v27;
    v30.m128_f32[0] = v27.m128_f32[0] - 0.25;
    v31 = (int)(float)(v27.m128_f32[0] - 0.25);
    if ( v31 != 0x80000000 && (float)v31 != v30.m128_f32[0] )
      v30.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1) + v31);
    if ( ((int)v30.m128_f32[0] & 1) != 0 )
LABEL_40:
      snapOffset = FLOAT_0_5;
    else
      snapOffset = 0.0;
  }
  else
  {
    snapOffset = FLOAT_0_25;
  }
  v33 = (LODWORD(mtx.M[1][2]) & 0xFF000000) >= 0xF0000000 && !v54;
  v34 = v33;
  if ( ((unsigned __int8)retaddr & 2) != 0 )
    v34 = 0;
  if ( v27.m128_f32[0] >= 1.25 || v34 || v28 <= 0.0 )
  {
    v38 = 2;
    v39 = 2;
    v40 = 2;
    v41 = LOBYTE(mtx.M[1][0]) & 0x30;
    if ( v41 == 16 )
    {
      v38 = 3;
    }
    else if ( v41 == 32 )
    {
      v38 = 0;
    }
    if ( (LOBYTE(mtx.M[1][0]) & 0xC0) == 64 )
    {
      v39 = 0;
    }
    else if ( (LOBYTE(mtx.M[1][0]) & 0xC0) == 128 )
    {
      v39 = 1;
    }
    v42 = LOWORD(mtx.M[1][0]) & 0x300;
    if ( v42 == 256 )
    {
      v40 = 0;
    }
    else if ( v42 == 512 )
    {
      v40 = 1;
    }
    v43 = v27.m128_f32[0] + (float)(v28 * -2.0);
    if ( v43 < 0.1 )
    {
      if ( !v34 )
      {
        v28 = v28 + -0.050000001;
        v43 = FLOAT_0_1;
        goto LABEL_72;
      }
      v43 = 0.0;
    }
    if ( v34 )
    {
      v44 = (Scaleform::Render::TessBase *)(v9 + 2512);
      v45 = v43 * 0.5;
      *(float *)(v9 + 2548) = v45;
      *(float *)(v9 + 2544) = v45;
      v46 = (float)(v28 * *(float *)(v18 + 56)) * 2.0;
      *(float *)(v9 + 2556) = v46;
      *(float *)(v9 + 2552) = v46;
      *(_DWORD *)(v9 + 2520) = v38;
      *(_DWORD *)(v9 + 2524) = v39;
      *(_DWORD *)(v9 + 2528) = v40;
      *(float *)(v9 + 2532) = mtx.M[1][1];
      *(_DWORD *)(v9 + 2560) = *(_DWORD *)(v18 + 4);
      *(_DWORD *)(v9 + 2564) = *(_DWORD *)(v18 + 12);
      v35 = morphRatio[0];
      v36 = v70;
      Scaleform::Render::ShapeMeshProvider::addStroke(
        this,
        (Scaleform::Render::MeshGenerator *)v9,
        (Scaleform::Render::TessBase *)(v9 + 2512),
        (Scaleform::Render::ToleranceParams *)v18,
        tr,
        startPos,
        v70,
        snapOffset,
        morphRatio[0]);
LABEL_73:
      v37 = v44;
      goto LABEL_74;
    }
LABEL_72:
    *(float *)(v9 + 1600) = v43 * 0.5;
    *(_DWORD *)(v9 + 1604) = v38;
    *(_DWORD *)(v9 + 1608) = v39;
    *(_DWORD *)(v9 + 1612) = v40;
    *(float *)(v9 + 1616) = mtx.M[1][1];
    *(_DWORD *)(v9 + 1620) = *(_DWORD *)(v18 + 4);
    *(_DWORD *)(v9 + 1624) = *(_DWORD *)(v18 + 12);
    v44 = (Scaleform::Render::TessBase *)(v9 + 160);
    *(_DWORD *)(v9 + 184) = 0;
    *(_BYTE *)(v9 + 193) = 1;
    v47 = v28 * *(float *)(v18 + 56);
    *(float *)(v9 + 1100) = v47;
    *(_BYTE *)(v9 + 1104) = v47 > 0.0;
    v35 = morphRatio[0];
    v36 = v70;
    Scaleform::Render::ShapeMeshProvider::addStroke(
      this,
      (Scaleform::Render::MeshGenerator *)v9,
      (Scaleform::Render::ToleranceParams *)v18,
      tr,
      startPos,
      v70,
      snapOffset,
      morphRatio[0]);
    Scaleform::Render::Tessellator::Tessellate((Scaleform::Render::Tessellator *)(v9 + 160), 0);
    goto LABEL_73;
  }
  if ( v27.m128_f32[0] >= 1.0 )
    v28 = (float)(v27.m128_f32[0] - 1.0) + v28;
  *(float *)(v9 + 1864) = v28 * 2.0;
  *(_DWORD *)(v9 + 1856) = *(_DWORD *)v18;
  *(_DWORD *)(v9 + 1860) = *(_DWORD *)(v18 + 12);
  v35 = morphRatio[0];
  v36 = v70;
  Scaleform::Render::ShapeMeshProvider::addStroke(
    this,
    (Scaleform::Render::MeshGenerator *)v9,
    (Scaleform::Render::TessBase *)(v9 + 1840),
    (Scaleform::Render::ToleranceParams *)v18,
    tr,
    startPos,
    v70,
    snapOffset,
    morphRatio[0]);
  Scaleform::Render::Hairliner::Tessellate((Scaleform::Render::Hairliner *)(v9 + 1840));
  v37 = (Scaleform::Render::TessBase *)(v9 + 1840);
LABEL_74:
  v48 = Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
          this,
          v37,
          &mtx,
          vars0,
          drawLayerIdxa,
          v36,
          (unsigned int)retaddr,
          v35);
  Scaleform::Render::MeshGenerator::Clear((Scaleform::Render::MeshGenerator *)v9);
  v52.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerBase::`vftable;
  v54 = &Scaleform::Render::TransformerBase::`vftable;
  v49 = v55;
  if ( v55 && !_InterlockedDecrement((volatile signed __int32 *)&v55->M[0][2]) && v49 )
    (**(void (__fastcall ***)(Scaleform::Render::Matrix2x4<float> *, __int64))&v49->M[0][0])(v49, 1i64);
  v50 = v54;
  if ( v54 && !_InterlockedDecrement((volatile signed __int32 *)v54 + 2) && v50 )
    (*(void (__fastcall **)(void **, __int64))*v50)(v50, 1i64);
  return v48;
}

// File Line: 1499
// RVA: 0x9E7100
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::getLayerBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        unsigned int drawLayer)
{
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *Data; // rax
  Scaleform::Render::ShapeDataInterface *pObject; // rcx
  unsigned int StartPos; // r8d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  char v9; // di
  int i; // eax
  int v12[4]; // [rsp+30h] [rbp-29h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [rsp+40h] [rbp-19h] BYREF
  float coord[6]; // [rsp+78h] [rbp+1Fh] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+90h] [rbp+37h] BYREF

  Data = this->DrawLayers.Data.Data;
  pObject = this->pShapeData.pObject;
  *(__m128 *)&trans.M[1][0] = _xmm;
  StartPos = Data[drawLayer].StartPos;
  result->x1 = 1.0e30;
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  *(_OWORD *)&trans.M[0][0] = _xmm;
  pos.Pos = StartPos;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  vfptr = pObject->vfptr;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v9 = 1;
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))vfptr[8].__vecDelDtor)(
              pObject,
              &pos,
              coord,
              v12);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
              this->pShapeData.pObject,
              &pos,
              coord,
              v12) )
  {
    if ( !v9 && i == 2 )
      break;
    v9 = 0;
    if ( v12[0] || v12[1] )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        this->pShapeData.pObject,
        &trans,
        &pos,
        coord,
        result);
    else
      this->pShapeData.pObject->vfptr[10].__vecDelDtor(this->pShapeData.pObject, (unsigned int)&pos);
  }
  return result;
}

// File Line: 1528
// RVA: 0x9E41D0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::generateImage9Grid(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Scale9GridInfo *s9g,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut)
{
  float y2; // xmm3_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  int *LayerBounds; // rax
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  __int64 v15; // rdx
  __int64 v16; // rax
  unsigned __int8 v17; // bl
  void (__fastcall ***v18)(_QWORD, __int64); // rcx
  Scaleform::Render::Matrix2x4<float> *fillMatrix; // [rsp+28h] [rbp-C0h]
  __int64 v21; // [rsp+30h] [rbp-B8h] BYREF
  char v22[8]; // [rsp+40h] [rbp-A8h] BYREF
  __int64 v23; // [rsp+48h] [rbp-A0h]
  Scaleform::Render::Rect<float> imgRect; // [rsp+50h] [rbp-98h] BYREF
  int v25[11]; // [rsp+60h] [rbp-88h] BYREF
  char v26; // [rsp+8Ch] [rbp-5Ch]
  int v27[4]; // [rsp+90h] [rbp-58h] BYREF
  int v28[2]; // [rsp+A0h] [rbp-48h] BYREF
  Scaleform::Render::VertexFormat *v29; // [rsp+A8h] [rbp-40h]
  __int64 v30; // [rsp+B0h] [rbp-38h]
  __int64 v31; // [rsp+B8h] [rbp-30h]
  int v32[2]; // [rsp+C0h] [rbp-28h] BYREF
  Scaleform::Render::VertexFormat *v33; // [rsp+C8h] [rbp-20h]
  __int64 v34; // [rsp+D0h] [rbp-18h]
  __int64 v35; // [rsp+D8h] [rbp-10h]
  __int64 v36; // [rsp+E0h] [rbp-8h]
  __int128 v37[2]; // [rsp+E8h] [rbp+0h] BYREF
  Scaleform::Render::Rect<float> result; // [rsp+108h] [rbp+20h] BYREF
  Scaleform::Render::Matrix2x4<float> v39; // [rsp+118h] [rbp+30h] BYREF
  char v40[32]; // [rsp+138h] [rbp+50h] BYREF
  Scaleform::Render::Scale9GridTess v41; // [rsp+158h] [rbp+70h] BYREF
  __int16 v42; // [rsp+3B8h] [rbp+2D0h] BYREF
  int v43; // [rsp+3BAh] [rbp+2D2h]
  unsigned int v44; // [rsp+3D8h] [rbp+2F0h]

  v36 = -2i64;
  if ( this->DrawLayers.Data.Data[v44].Image9GridType == I9gMergedSlice )
  {
    y2 = this->IdentityBounds.y2;
    x2 = this->IdentityBounds.x2;
    y1 = this->IdentityBounds.y1;
    v25[0] = LODWORD(this->IdentityBounds.x1);
    *(float *)&v25[1] = y1;
    *(float *)&v25[2] = x2;
    *(float *)&v25[3] = y2;
    LayerBounds = v25;
  }
  else
  {
    LayerBounds = (int *)Scaleform::Render::ShapeMeshProvider::getLayerBounds(this, &result, v44);
  }
  v12 = *((float *)LayerBounds + 3);
  v13 = *((float *)LayerBounds + 2);
  v14 = *((float *)LayerBounds + 1);
  LODWORD(imgRect.x1) = *LayerBounds;
  imgRect.y1 = v14;
  imgRect.x2 = v13;
  imgRect.y2 = v12;
  memset(&v25[3], 0, 28);
  v25[10] = (int)FLOAT_1_0;
  v26 = 0;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, char *, int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
    this->pShapeData.pObject,
    &v25[4],
    v40,
    v27);
  v15 = (unsigned int)v27[1];
  if ( v27[0] )
    v15 = (unsigned int)v27[0];
  v23 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
    this->pShapeData.pObject,
    v15,
    v22);
  v16 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))mesh->pRenderer2D->pHal.pObject->vfptr[61].__vecDelDtor)(mesh->pRenderer2D->pHal.pObject);
  (*(void (__fastcall **)(_QWORD, Scaleform::Render::Matrix2x4<float> *, __int64))(**(_QWORD **)(v23 + 16) + 184i64))(
    *(_QWORD *)(v23 + 16),
    &v39,
    v16);
  fillMatrix = (Scaleform::Render::Matrix2x4<float> *)(v23 + 32);
  Scaleform::Render::Scale9GridTess::Scale9GridTess(&v41, Scaleform::Memory::pGlobalHeap, s9g, &imgRect);
  if ( !LODWORD(v41.Indices.Size) )
  {
    v43 = 0;
    v42 = 0;
    v32[0] = 1;
    v32[1] = 3;
    v33 = &Scaleform::Render::Image9GridVertex::Format;
    v34 = 0i64;
    v35 = 0i64;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::VertexOutput *, int *, __int64, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *, _QWORD, _QWORD))verOut->vfptr->BeginOutput)(
           verOut,
           v32,
           1i64,
           &Scaleform::Render::Matrix2x4<float>::Identity,
           &v39,
           fillMatrix,
           0i64,
           0i64) )
    {
      verOut->vfptr->SetVertices(verOut, 0, 0, &v21, 1u);
      verOut->vfptr->SetIndices(verOut, 0, 0, (unsigned __int16 *)&v42, 3u);
      goto LABEL_12;
    }
LABEL_10:
    v17 = 0;
    goto LABEL_13;
  }
  v28[0] = v41.VerCount;
  v28[1] = v41.Indices.Size;
  v29 = &Scaleform::Render::Image9GridVertex::Format;
  v30 = 0i64;
  v31 = 0i64;
  v37[0] = _xmm;
  v37[1] = (__int128)_xmm;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::VertexOutput *, int *, __int64, __int128 *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))verOut->vfptr->BeginOutput)(
          verOut,
          v28,
          1i64,
          v37,
          &v39,
          fillMatrix) )
    goto LABEL_10;
  verOut->vfptr->SetVertices(verOut, 0, 0, &v41, v41.VerCount);
  verOut->vfptr->SetIndices(verOut, 0, 0, v41.Indices.Data, v41.Indices.Size);
LABEL_12:
  verOut->vfptr->EndOutput(verOut);
  v17 = 1;
LABEL_13:
  if ( v41.Indices.Data != v41.Indices.Static )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v41.Indices.Data = v41.Indices.Static;
  v41.Indices.Size = 0i64;
  v18 = (void (__fastcall ***)(_QWORD, __int64))v23;
  if ( v23 && !_InterlockedDecrement((volatile signed __int32 *)(v23 + 8)) && v18 )
    (**v18)(v18, 1i64);
  return v17;
}

// File Line: 1584
// RVA: 0x981FB0
_BOOL8 __fastcall Scaleform::Render::ShapeMeshProvider::GetData(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        unsigned int meshGenFlags)
{
  Scaleform::Render::Scale9GridInfo *v8; // rbx
  __int64 drawLayer; // rbp
  int v10; // ecx
  Scaleform::Render::Scale9GridInfo *v11; // rax
  Scaleform::Render::Scale9GridInfo *v12; // rax
  bool Image9Grid; // al
  Scaleform::Render::Scale9GridInfo *v14; // rax
  Scaleform::Render::Scale9GridInfo *v15; // rax
  unsigned int v16; // r8d
  Scaleform::Render::ShapeMeshProvider *v17; // rcx
  bool v18; // di
  Scaleform::Render::Matrix2x4<float> viewMtx; // [rsp+50h] [rbp-48h] BYREF
  Scaleform::Render::Scale9GridInfo *v21; // [rsp+A0h] [rbp+8h]

  v8 = 0i64;
  v21 = 0i64;
  drawLayer = mesh->Layer;
  v10 = *((_DWORD *)&this->hKeySet.pManager.Value->KeySetLock.cs.DebugInfo + 5 * drawLayer);
  if ( !mesh->pScale9Grid.pObject )
  {
LABEL_9:
    v16 = *((_DWORD *)&this->hKeySet.pManager.Value->RefCount + 5 * drawLayer + 1);
    v17 = (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16);
    if ( v16 )
      Image9Grid = Scaleform::Render::ShapeMeshProvider::tessellateStroke(
                     v17,
                     v8,
                     v16,
                     drawLayer,
                     mesh,
                     verOut,
                     meshGenFlags);
    else
      Image9Grid = Scaleform::Render::ShapeMeshProvider::tessellateFill(v17, v8, drawLayer, mesh, verOut, meshGenFlags);
    goto LABEL_12;
  }
  if ( !v10 )
  {
    v14 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 448i64,
                                                 0i64);
    if ( v14 )
    {
      Scaleform::Render::Scale9GridInfo::Scale9GridInfo(
        v14,
        mesh->pScale9Grid.pObject,
        &mesh->pScale9Grid.pObject->ViewMtx);
      v8 = v15;
    }
    v21 = v8;
    goto LABEL_9;
  }
  v11 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               448i64,
                                               0i64);
  if ( v11 )
  {
    *(_OWORD *)&viewMtx.M[0][0] = _xmm;
    *(__m128 *)&viewMtx.M[1][0] = _xmm;
    Scaleform::Render::Scale9GridInfo::Scale9GridInfo(v11, mesh->pScale9Grid.pObject, &viewMtx);
    v8 = v12;
  }
  v21 = v8;
  Image9Grid = Scaleform::Render::ShapeMeshProvider::generateImage9Grid(
                 (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
                 v8,
                 mesh,
                 verOut,
                 drawLayer);
LABEL_12:
  v18 = Image9Grid;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) )
    v21->vfptr->__vecDelDtor(v21, 1u);
  return v18;
}

// File Line: 1614
// RVA: 0x9E6D70
Scaleform::Render::ComplexFill *__fastcall Scaleform::Render::ShapeMeshProvider::getComplexFill(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int drawLayer,
        unsigned int fillIndex,
        unsigned int *imgFillStyle)
{
  __int64 v5; // rdx
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *Data; // rax
  unsigned int StrokeStyle; // r9d
  __int64 v8; // rdi
  unsigned int v9; // ebx
  void (__fastcall ***v10)(_QWORD, __int64); // rcx
  void (__fastcall ***v11)(_QWORD, __int64); // rcx
  void (__fastcall ***v12)(_QWORD, __int64); // rcx
  char v14[8]; // [rsp+28h] [rbp-40h] BYREF
  __int64 v15; // [rsp+30h] [rbp-38h]
  char v16[24]; // [rsp+38h] [rbp-30h] BYREF
  __int64 v17; // [rsp+50h] [rbp-18h]
  __int64 v18; // [rsp+58h] [rbp-10h]

  v5 = drawLayer;
  Data = this->DrawLayers.Data.Data;
  StrokeStyle = Data[v5].StrokeStyle;
  v8 = 0i64;
  if ( StrokeStyle )
  {
    v17 = 0i64;
    v18 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[5].__vecDelDtor)(
      this->pShapeData.pObject,
      StrokeStyle,
      v16);
    v8 = v17;
    v11 = (void (__fastcall ***)(_QWORD, __int64))v18;
    if ( v18 && !_InterlockedDecrement((volatile signed __int32 *)(v18 + 8)) && v11 )
      (**v11)(v11, 1i64);
    v12 = (void (__fastcall ***)(_QWORD, __int64))v17;
    if ( v17 && !_InterlockedDecrement((volatile signed __int32 *)(v17 + 8)) && v12 )
      (**v12)(v12, 1i64);
  }
  else
  {
    v9 = this->FillToStyleTable.Data.Data[fillIndex + Data[v5].StartFill];
    if ( v9 )
    {
      v15 = 0i64;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
        this->pShapeData.pObject,
        v9,
        v14);
      v8 = v15;
      if ( imgFillStyle )
        *imgFillStyle = v9;
      v10 = (void (__fastcall ***)(_QWORD, __int64))v15;
      if ( v15 && !_InterlockedDecrement((volatile signed __int32 *)(v15 + 8)) && v10 )
        (**v10)(v10, 1i64);
    }
  }
  return (Scaleform::Render::ComplexFill *)v8;
}

// File Line: 1646
// RVA: 0x9E72D0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::ShapeMeshProvider::getMorphMatrix(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Matrix2x4<float> *result,
        unsigned int drawLayer,
        __int64 fillIndex)
{
  __int64 v5; // r8
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *Data; // rax
  __int64 StrokeStyle; // rdx
  __int64 v8; // rdx
  float *v9; // rcx
  __int64 v10; // rcx
  float *v11; // rcx
  void (__fastcall ***v12)(_QWORD, __int64); // rcx
  void (__fastcall ***v13)(_QWORD, __int64); // rcx
  char v15[8]; // [rsp+28h] [rbp-40h] BYREF
  float *v16; // [rsp+30h] [rbp-38h]
  char v17[24]; // [rsp+38h] [rbp-30h] BYREF
  float *v18; // [rsp+50h] [rbp-18h]
  __int64 v19; // [rsp+58h] [rbp-10h]

  v5 = drawLayer;
  Data = this->DrawLayers.Data.Data;
  StrokeStyle = Data[v5].StrokeStyle;
  if ( (_DWORD)StrokeStyle )
  {
    v18 = 0i64;
    v19 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *, __int64, __int64))this->pMorphData.pObject->pMorphTo.pObject->vfptr[5].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      StrokeStyle,
      v17,
      fillIndex,
      -2i64);
    v11 = v18;
    if ( v18 )
    {
      result->M[0][0] = v18[8];
      result->M[0][1] = v11[9];
      result->M[0][2] = v11[10];
      result->M[0][3] = v11[11];
      result->M[1][0] = v11[12];
      result->M[1][1] = v11[13];
      result->M[1][2] = v11[14];
      result->M[1][3] = v11[15];
      v12 = (void (__fastcall ***)(_QWORD, __int64))v19;
      if ( v19 && !_InterlockedDecrement((volatile signed __int32 *)(v19 + 8)) && v12 )
        (**v12)(v12, 1i64);
    }
    else
    {
      *(_QWORD *)&result->M[0][0] = 1065353216i64;
      *(_QWORD *)&result->M[0][2] = 0i64;
      result->M[1][0] = 0.0;
      *(_QWORD *)&result->M[1][1] = 1065353216i64;
      result->M[1][3] = 0.0;
      v13 = (void (__fastcall ***)(_QWORD, __int64))v19;
      if ( v19 && !_InterlockedDecrement((volatile signed __int32 *)(v19 + 8)) && v13 )
        (**v13)(v13, 1i64);
    }
    v10 = (__int64)v18;
  }
  else
  {
    v8 = this->FillToStyleTable.Data.Data[(unsigned int)(fillIndex + Data[v5].StartFill)];
    v16 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *))this->pMorphData.pObject->pMorphTo.pObject->vfptr[4].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      v8,
      v15);
    v9 = v16;
    result->M[0][0] = v16[8];
    result->M[0][1] = v9[9];
    result->M[0][2] = v9[10];
    result->M[0][3] = v9[11];
    result->M[1][0] = v9[12];
    result->M[1][1] = v9[13];
    result->M[1][2] = v9[14];
    result->M[1][3] = v9[15];
    v10 = (__int64)v16;
  }
  if ( v10 && !_InterlockedDecrement((volatile signed __int32 *)(v10 + 8)) )
    (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
  return result;
}

// File Line: 1670
// RVA: 0x983560
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::GetFillCount(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int drawLayer,
        unsigned int meshGenFlags)
{
  return *((unsigned int *)&this->hKeySet.pManager.Value->RefCount + 5 * drawLayer);
}

// File Line: 1679
// RVA: 0x983580
void __fastcall Scaleform::Render::ShapeMeshProvider::GetFillData(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::FillData *pdata,
        unsigned int drawLayer,
        unsigned int fillIndex,
        char meshGenFlags)
{
  __int64 v5; // rbp
  Scaleform::Render::ComplexFill *ComplexFill; // rax
  Scaleform::Render::GradientData *pObject; // rcx
  char Fill; // bl
  Scaleform::Render::GradientData *v11; // rax
  Scaleform::Render::VertexFormat *v12; // rax
  Scaleform::Render::GradientData *v13; // [rsp+28h] [rbp-20h]

  v5 = drawLayer;
  if ( (meshGenFlags & 2) != 0 )
  {
    pdata->Type = Fill_Mask;
    pdata->PrimFill = PrimFill_Mask;
    LODWORD(v13) = 0;
    pdata->FillMode.Fill = 0;
    pdata->pGradient = v13;
    pdata->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
    return;
  }
  ComplexFill = Scaleform::Render::ShapeMeshProvider::getComplexFill(
                  (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
                  drawLayer,
                  fillIndex,
                  0i64);
  if ( !ComplexFill )
  {
    LODWORD(v13) = 0;
    pdata->Type = Fill_VColor;
    pdata->PrimFill = PrimFill_VColor_EAlpha;
    pdata->FillMode.Fill = 0;
    pdata->pGradient = v13;
    goto LABEL_10;
  }
  pObject = ComplexFill->pGradient.pObject;
  if ( pObject )
  {
    pdata->Type = Fill_Gradient;
    pdata->pGradient = pObject;
    pdata->PrimFill = PrimFill_Texture_EAlpha;
    pdata->FillMode.Fill = 3;
LABEL_10:
    v12 = &Scaleform::Render::VertexXY16iCF32::Format;
    goto LABEL_11;
  }
  Fill = ComplexFill->FillMode.Fill;
  v11 = (Scaleform::Render::GradientData *)((__int64 (__fastcall *)(Scaleform::Render::Image *))ComplexFill->pImage.pObject->vfptr[9].__vecDelDtor)(ComplexFill->pImage.pObject);
  pdata->FillMode.Fill = Fill;
  pdata->pGradient = v11;
  pdata->Type = Fill_Image;
  pdata->PrimFill = PrimFill_Texture_EAlpha;
  pdata->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  if ( *((_DWORD *)&this->hKeySet.pManager.Value->KeySetLock.cs.DebugInfo + 5 * v5) && (meshGenFlags & 8) != 0 )
  {
    pdata->PrimFill = PrimFill_UVTexture;
    v12 = &Scaleform::Render::Image9GridVertex::Format;
LABEL_11:
    pdata->pVFormat = v12;
  }
}

// File Line: 1716
// RVA: 0x9D6780
void __fastcall Scaleform::Render::ShapeMeshProvider::computeImgAdjustMatrix(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Scale9GridData *s9g,
        unsigned int drawLayer,
        unsigned int imgFillStyle)
{
  char v7; // si
  int i; // eax
  float x1; // xmm9_4
  float x2; // xmm7_4
  float y1; // xmm6_4
  float y2; // xmm8_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-B8h] BYREF
  float x; // [rsp+40h] [rbp-A8h] BYREF
  float y[3]; // [rsp+44h] [rbp-A4h] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+50h] [rbp-98h] BYREF
  int v17; // [rsp+70h] [rbp-78h] BYREF
  __int64 v18; // [rsp+74h] [rbp-74h]
  __int64 v19; // [rsp+7Ch] [rbp-6Ch]
  __int64 v20; // [rsp+84h] [rbp-64h]
  __int64 v21; // [rsp+8Ch] [rbp-5Ch]
  int v22; // [rsp+94h] [rbp-54h]
  int v23; // [rsp+98h] [rbp-50h]
  char v24; // [rsp+9Ch] [rbp-4Ch]
  float coord[6]; // [rsp+A0h] [rbp-48h] BYREF
  __int64 v26; // [rsp+B8h] [rbp-30h]
  Scaleform::Render::Scale9GridInfo v27; // [rsp+C8h] [rbp-20h] BYREF
  Scaleform::Render::Matrix2x4<float> *v28; // [rsp+308h] [rbp+220h]

  v26 = -2i64;
  v17 = 0;
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0;
  v23 = (int)FLOAT_1_0;
  v24 = 0;
  v7 = 1;
  bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
  *(_OWORD *)&trans.M[0][0] = _xmm;
  *(__m128 *)&trans.M[1][0] = _xmm;
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
              this->pShapeData.pObject,
              &trans.M[1][2],
              coord,
              &v17);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
              this->pShapeData.pObject,
              &trans.M[1][2],
              coord,
              &v17) )
  {
    if ( !v7 && i == 2 )
      break;
    v7 = 0;
    if ( v17 == imgFillStyle || (_DWORD)v18 == imgFillStyle )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        this->pShapeData.pObject,
        &trans,
        (Scaleform::Render::ShapePosInfo *)&trans.M[1][2],
        coord,
        &bounds);
    else
      this->pShapeData.pObject->vfptr[10].__vecDelDtor(this->pShapeData.pObject, (unsigned int)&trans.M[1][2]);
  }
  *(_QWORD *)&v28->M[0][0] = 1065353216i64;
  *(_QWORD *)&v28->M[0][2] = 0i64;
  v28->M[1][0] = 0.0;
  *(_QWORD *)&v28->M[1][1] = 1065353216i64;
  v28->M[1][3] = 0.0;
  x1 = bounds.x1;
  x2 = bounds.x2;
  if ( bounds.x1 < bounds.x2 )
  {
    y1 = bounds.y1;
    y2 = bounds.y2;
    if ( bounds.y1 < bounds.y2 )
    {
      *(_OWORD *)&trans.M[0][0] = _xmm;
      *(__m128 *)&trans.M[1][0] = _xmm;
      Scaleform::Render::Scale9GridInfo::Scale9GridInfo(&v27, s9g, &trans);
      bounds.x1 = x1;
      bounds.y1 = y1;
      bounds.x2 = x2;
      bounds.y2 = y1;
      x = x2;
      y[0] = y2;
      Scaleform::Render::Scale9GridInfo::Transform(&v27, &bounds.x1, &bounds.y1);
      Scaleform::Render::Scale9GridInfo::Transform(&v27, &bounds.x2, &bounds.y2);
      Scaleform::Render::Scale9GridInfo::Transform(&v27, &x, y);
      *(_QWORD *)&trans.M[0][0] = __PAIR64__(LODWORD(y1), LODWORD(x1));
      *(_QWORD *)&trans.M[0][2] = __PAIR64__(LODWORD(y1), LODWORD(x2));
      *(_QWORD *)&trans.M[1][0] = __PAIR64__(LODWORD(y2), LODWORD(x2));
      Scaleform::Render::Matrix2x4<float>::SetParlToParl(v28, (float *)&trans, &bounds.x1);
    }
  }
}

// File Line: 1756
// RVA: 0x983920
void __fastcall Scaleform::Render::ShapeMeshProvider::GetFillMatrix(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::Matrix2x4<float> *matrix,
        unsigned int drawLayer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  float *ComplexFill; // rax
  float *v11; // r14
  float MorphRatio; // xmm6_4
  Scaleform::Render::Matrix2x4<float> *MorphMatrix; // rax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  Scaleform::Render::Scale9GridData *pObject; // rdx
  float v22; // xmm8_4
  float v23; // xmm5_4
  float v24; // xmm3_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm8_4
  float v31; // xmm7_4
  float v32; // xmm1_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  __int64 v35; // rax
  __m128 v36; // xmm7
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm5
  Scaleform::Render::Matrix2x4<float> m; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [rsp+50h] [rbp-29h] BYREF
  unsigned int imgFillStyle; // [rsp+D0h] [rbp+57h] BYREF

  imgFillStyle = 0;
  ComplexFill = (float *)Scaleform::Render::ShapeMeshProvider::getComplexFill(
                           (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
                           drawLayer,
                           fillIndex,
                           &imgFillStyle);
  v11 = ComplexFill;
  if ( ComplexFill )
  {
    matrix->M[0][0] = ComplexFill[8];
    matrix->M[0][1] = ComplexFill[9];
    matrix->M[0][2] = ComplexFill[10];
    matrix->M[0][3] = ComplexFill[11];
    matrix->M[1][0] = ComplexFill[12];
    matrix->M[1][1] = ComplexFill[13];
    matrix->M[1][2] = ComplexFill[14];
    matrix->M[1][3] = ComplexFill[15];
    if ( this->FillToStyleTable.Data.Policy.Capacity )
    {
      MorphRatio = mesh->MorphRatio;
      if ( MorphRatio != 0.0 )
      {
        MorphMatrix = Scaleform::Render::ShapeMeshProvider::getMorphMatrix(
                        (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
                        &result,
                        drawLayer,
                        fillIndex);
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&m, MorphMatrix);
        *(_OWORD *)&result.M[0][0] = _xmm;
        *(__m128 *)&result.M[1][0] = _xmm;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&result, (Scaleform::Render::Matrix2x4<float> *)v11 + 1);
        v14 = (float)((float)(m.M[1][0] - result.M[1][0]) * MorphRatio) + result.M[1][0];
        matrix->M[0][0] = (float)((float)(m.M[0][0] - result.M[0][0]) * MorphRatio) + result.M[0][0];
        v15 = m.M[0][1];
        matrix->M[1][0] = v14;
        v16 = (float)((float)(m.M[1][1] - result.M[1][1]) * MorphRatio) + result.M[1][1];
        matrix->M[0][1] = (float)((float)(v15 - result.M[0][1]) * MorphRatio) + result.M[0][1];
        v17 = m.M[0][2] - result.M[0][2];
        matrix->M[1][1] = v16;
        v18 = (float)((float)(m.M[1][2] - result.M[1][2]) * MorphRatio) + result.M[1][2];
        matrix->M[0][2] = (float)(v17 * MorphRatio) + result.M[0][2];
        v19 = m.M[0][3] - result.M[0][3];
        matrix->M[1][2] = v18;
        v20 = (float)((float)(m.M[1][3] - result.M[1][3]) * MorphRatio) + result.M[1][3];
        matrix->M[0][3] = (float)(v19 * MorphRatio) + result.M[0][3];
        matrix->M[1][3] = v20;
        Scaleform::Render::Matrix2x4<float>::Invert(matrix);
      }
    }
    if ( mesh )
    {
      pObject = mesh->pScale9Grid.pObject;
      if ( pObject )
      {
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        Scaleform::Render::ShapeMeshProvider::computeImgAdjustMatrix(
          (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
          pObject,
          drawLayer,
          imgFillStyle,
          &m);
        *(_OWORD *)&result.M[0][0] = _xmm;
        *(__m128 *)&result.M[1][0] = _xmm;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&result, &m);
        matrix->M[1][2] = 0.0;
        matrix->M[0][2] = 0.0;
        v22 = matrix->M[1][1];
        v23 = matrix->M[0][0];
        v24 = matrix->M[0][1];
        v25 = matrix->M[1][0];
        v26 = v24 * result.M[1][3];
        v27 = v24 * result.M[1][1];
        matrix->M[0][0] = (float)(matrix->M[0][1] * result.M[1][0]) + (float)(matrix->M[0][0] * result.M[0][0]);
        matrix->M[1][0] = (float)(v22 * result.M[1][0]) + (float)(v25 * result.M[0][0]);
        v28 = v22;
        v29 = v25;
        v30 = v22 * result.M[1][3];
        v31 = v25 * result.M[0][3];
        v32 = v28 * result.M[1][1];
        v33 = (float)(v26 + (float)(v23 * result.M[0][3])) + matrix->M[0][3];
        matrix->M[0][1] = v27 + (float)(v23 * result.M[0][1]);
        matrix->M[0][3] = v33;
        v34 = v29 * result.M[0][1];
        matrix->M[1][3] = (float)(v30 + v31) + matrix->M[1][3];
        matrix->M[1][1] = v32 + v34;
      }
    }
    if ( *((_QWORD *)v11 + 2) )
    {
      v35 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))mesh->pRenderer2D->pHal.pObject->vfptr[61].__vecDelDtor)(mesh->pRenderer2D->pHal.pObject);
      (*(void (__fastcall **)(_QWORD, Scaleform::Render::Matrix2x4<float> *, __int64))(**((_QWORD **)v11 + 2) + 176i64))(
        *((_QWORD *)v11 + 2),
        &result,
        v35);
      v36 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v;
      v37 = _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 0),
              *(__m128 *)&matrix->M[0][0]);
      v38 = _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 85);
      v39 = _mm_and_ps(
              *(__m128 *)&result.M[1][0],
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
      *(__m128 *)&matrix->M[0][0] = _mm_and_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(*(__m128 *)&result.M[0][0], *(__m128 *)&result.M[0][0], 85),
                                            *(__m128 *)&matrix->M[1][0]),
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(*(__m128 *)&result.M[0][0], *(__m128 *)&result.M[0][0], 0),
                                            *(__m128 *)&matrix->M[0][0])),
                                        _mm_and_ps(
                                          *(__m128 *)&result.M[0][0],
                                          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
      *(__m128 *)&matrix->M[1][0] = _mm_and_ps(
                                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, *(__m128 *)&matrix->M[1][0]), v37), v39),
                                      v36);
    }
  }
  else
  {
    *(_QWORD *)&matrix->M[0][0] = 1065353216i64;
    *(_QWORD *)&matrix->M[0][2] = 0i64;
    matrix->M[1][0] = 0.0;
    *(_QWORD *)&matrix->M[1][1] = 1065353216i64;
    matrix->M[1][3] = 0.0;
  }
}

// File Line: 1820
// RVA: 0x980370
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::GetBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 Capacity; // rbx
  Scaleform::Render::ShapeDataInterface *v7; // rbx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  Scaleform::Render::ShapeDataInterface *v10; // rbx
  Scaleform::RefCountImplCoreVtbl *v11; // rax
  float x1; // xmm0_4
  float x2; // xmm1_4
  float y1; // xmm2_4
  float y2; // xmm3_4
  int v17; // [rsp+18h] [rbp-59h] BYREF
  int v18; // [rsp+1Ch] [rbp-55h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::Render::Rect<float> bounds; // [rsp+68h] [rbp-9h] BYREF
  Scaleform::Render::Rect<float> coord; // [rsp+78h] [rbp+7h] BYREF
  float v22[14]; // [rsp+98h] [rbp+27h] BYREF

  Capacity = this->FillToStyleTable.Data.Policy.Capacity;
  if ( Capacity )
  {
    v7 = (Scaleform::Render::ShapeDataInterface *)(Capacity + 72);
    vfptr = v7->vfptr;
    bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
    pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))vfptr[6].__vecDelDtor)(v7);
    v9 = v7->vfptr;
    memset(&pos.StartX, 0, 44);
    pos.Sfactor = 1.0;
    pos.Initialized = 0;
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v9[8].__vecDelDtor)(
           v7,
           &pos,
           &coord.x1,
           &v17) )
    {
      do
      {
        if ( (v17 == 0) == (v18 == 0) )
          v7->vfptr[10].__vecDelDtor(v7, (unsigned int)&pos);
        else
          Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v7, m, &pos, &coord.x1, &bounds);
      }
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v7->vfptr[8].__vecDelDtor)(
                v7,
                &pos,
                &coord.x1,
                &v17) );
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v7->vfptr[3].__vecDelDtor)(v7) )
    {
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v7->vfptr[7].__vecDelDtor)(v7);
      Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(v7, m, &bounds);
    }
    v10 = (Scaleform::Render::ShapeDataInterface *)(this->FillToStyleTable.Data.Policy.Capacity + 176);
    coord = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
    pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v10->vfptr[6].__vecDelDtor)(v10);
    v11 = v10->vfptr;
    memset(&pos.StartX, 0, 44);
    pos.Sfactor = 1.0;
    pos.Initialized = 0;
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v11[8].__vecDelDtor)(
           v10,
           &pos,
           v22,
           &v17) )
    {
      do
      {
        if ( (v17 == 0) == (v18 == 0) )
          v10->vfptr[10].__vecDelDtor(v10, (unsigned int)&pos);
        else
          Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v10, m, &pos, v22, &coord);
      }
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v10->vfptr[8].__vecDelDtor)(
                v10,
                &pos,
                v22,
                &v17) );
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v10->vfptr[3].__vecDelDtor)(v10) )
    {
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v10->vfptr[7].__vecDelDtor)(v10);
      Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(v10, m, &coord);
    }
    x1 = coord.x1;
    if ( bounds.x1 <= coord.x1 )
      x1 = bounds.x1;
    x2 = bounds.x2;
    if ( bounds.x2 <= coord.x2 )
      x2 = coord.x2;
    y1 = coord.y1;
    if ( bounds.y1 <= coord.y1 )
      y1 = bounds.y1;
    y2 = bounds.y2;
    if ( bounds.y2 <= coord.y2 )
      y2 = coord.y2;
    result->x1 = x1;
    result->y1 = y1;
    result->x2 = x2;
    result->y2 = y2;
  }
  else
  {
    Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
      result,
      (Scaleform::Render::ShapeDataInterface *)this->FillToStyleTable.Data.Size,
      m,
      Bound_OuterEdges);
  }
  return result;
}

// File Line: 1838
// RVA: 0x981740
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::GetCorrectBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen)
{
  int v8; // eax
  Scaleform::Render::MorphShapeData *pObject; // rcx
  Scaleform::Render::ShapeDataInterface *v10; // rcx
  Scaleform::Render::MorphShapeData *v11; // rcx
  Scaleform::Render::ShapeDataInterface *v12; // rcx
  int v14[4]; // [rsp+30h] [rbp-C8h] BYREF
  int v15[4]; // [rsp+40h] [rbp-B8h] BYREF
  _BYTE pos[96]; // [rsp+50h] [rbp-A8h] BYREF
  int v17; // [rsp+B0h] [rbp-48h]
  char v18; // [rsp+B4h] [rbp-44h]
  Scaleform::Render::ShapePosInfo pos2; // [rsp+B8h] [rbp-40h] BYREF
  Scaleform::Render::MorphInterpolator v20; // [rsp+F8h] [rbp+0h] BYREF
  float v21[6]; // [rsp+198h] [rbp+A0h] BYREF
  float coord[6]; // [rsp+1B0h] [rbp+B8h] BYREF
  __int64 v23; // [rsp+1C8h] [rbp+D0h]
  Scaleform::Render::StrokeGenerator *v24; // [rsp+218h] [rbp+120h]

  v23 = -2i64;
  pos2.Pos = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)this->FillToStyleTable.Data.Size + 48i64))(this->FillToStyleTable.Data.Size);
  memset(&pos2.StartX, 0, 44);
  pos2.Sfactor = 1.0;
  pos2.Initialized = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v20,
    (Scaleform::Render::ShapeDataInterface *)this->FillToStyleTable.Data.Size,
    (Scaleform::Render::MorphShapeData *)this->FillToStyleTable.Data.Policy.Capacity,
    morphRatio,
    &pos2);
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v8 = ((__int64 (__fastcall *)(Scaleform::Render::MorphInterpolator *))v20.vfptr[6].__vecDelDtor)(&v20);
  if ( v24 )
  {
    *(_DWORD *)pos = v8;
    memset(&pos[4], 0, 36);
    *(_DWORD *)&pos[44] = 0;
    *(_DWORD *)&pos[40] = 1065353216;
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *, _BYTE *, float *, int *))v20.vfptr[8].__vecDelDtor)(
              &v20,
              pos,
              coord,
              v15) )
    {
      if ( (v15[0] == 0) == (v15[1] == 0) )
        v20.vfptr[10].__vecDelDtor(&v20, (unsigned int)pos);
      else
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          &v20,
          m,
          (Scaleform::Render::ShapePosInfo *)pos,
          coord,
          result);
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *))v20.vfptr[3].__vecDelDtor)(&v20) )
    {
      ((void (__fastcall *)(Scaleform::Render::MorphInterpolator *))v20.vfptr[7].__vecDelDtor)(&v20);
      Scaleform::Render::ExpandBoundsToStrokes<Scaleform::Render::Matrix2x4<float>>(
        &v20,
        m,
        v24,
        (Scaleform::Render::ToleranceParams *)gen,
        result);
    }
    pObject = v20.pMorphData.pObject;
    if ( v20.pMorphData.pObject && !_InterlockedDecrement(&v20.pMorphData.pObject->RefCount) && pObject )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    v10 = v20.pShapeData.pObject;
    if ( v20.pShapeData.pObject && !_InterlockedDecrement(&v20.pShapeData.pObject->RefCount) && v10 )
      v10->vfptr->__vecDelDtor(v10, 1u);
  }
  else
  {
    *(_DWORD *)&pos[48] = v8;
    memset(&pos[52], 0, 44);
    v17 = 1065353216;
    v18 = 0;
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *, _BYTE *, float *, int *))v20.vfptr[8].__vecDelDtor)(
              &v20,
              &pos[48],
              v21,
              v14) )
    {
      if ( (v14[0] == 0) == (v14[1] == 0) )
        v20.vfptr[10].__vecDelDtor(&v20, (unsigned int)&pos[48]);
      else
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          &v20,
          m,
          (Scaleform::Render::ShapePosInfo *)&pos[48],
          v21,
          result);
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *))v20.vfptr[3].__vecDelDtor)(&v20) )
    {
      ((void (__fastcall *)(Scaleform::Render::MorphInterpolator *))v20.vfptr[7].__vecDelDtor)(&v20);
      Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(&v20, m, result);
    }
    v11 = v20.pMorphData.pObject;
    if ( v20.pMorphData.pObject && !_InterlockedDecrement(&v20.pMorphData.pObject->RefCount) && v11 )
      v11->vfptr->__vecDelDtor(v11, 1u);
    v12 = v20.pShapeData.pObject;
    if ( v20.pShapeData.pObject && !_InterlockedDecrement(&v20.pShapeData.pObject->RefCount) && v12 )
      v12->vfptr->__vecDelDtor(v12, 1u);
  }
  return result;
}

// File Line: 1854
// RVA: 0x991EB0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::HitTestShape(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        __int64 morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::TransformerBase *p_trans; // rbx
  unsigned __int8 v10; // di
  char v11; // al
  Scaleform::Render::MorphShapeData *pObject; // rcx
  Scaleform::Render::ShapeDataInterface *v13; // rcx
  Scaleform::Render::TransformerBase trans; // [rsp+30h] [rbp-C8h] BYREF
  Scaleform::Render::ToleranceParams *v16; // [rsp+38h] [rbp-C0h]
  void **v17; // [rsp+40h] [rbp-B8h] BYREF
  Scaleform::Render::Matrix2x4<float> *v18; // [rsp+48h] [rbp-B0h]
  Scaleform::Render::ShapePosInfo pos2; // [rsp+50h] [rbp-A8h] BYREF
  Scaleform::Render::ToleranceParams *v20; // [rsp+88h] [rbp-70h]
  void **v21; // [rsp+90h] [rbp-68h]
  Scaleform::Render::Matrix2x4<float> *v22; // [rsp+98h] [rbp-60h]
  __int64 v23; // [rsp+A0h] [rbp-58h]
  Scaleform::Render::MorphInterpolator v24; // [rsp+A8h] [rbp-50h] BYREF
  float ratio; // [rsp+198h] [rbp+A0h]

  v23 = -2i64;
  pos2.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[6].__vecDelDtor)(this->pShapeData.pObject);
  memset(&pos2.StartX, 0, 36);
  pos2.Stroke = 0;
  pos2.Fill1 = (unsigned int)FLOAT_1_0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v24,
    this->pShapeData.pObject,
    this->pMorphData.pObject,
    ratio,
    &pos2);
  v17 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable;
  v18 = 0i64;
  trans.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable;
  v16 = 0i64;
  if ( tol )
  {
    v20 = tol;
    v16 = tol;
    *(_QWORD *)&pos2.Sfactor = &Scaleform::Render::TransformerBase::`vftable;
    p_trans = &trans;
  }
  else
  {
    v22 = m;
    v18 = m;
    v21 = &Scaleform::Render::TransformerBase::`vftable;
    p_trans = (Scaleform::Render::TransformerBase *)&v17;
  }
  if ( !morphRatio )
  {
    v11 = Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(&v24, m, x, y);
    goto LABEL_11;
  }
  if ( !Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(&v24, p_trans, x, y) )
  {
    if ( !((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *))v24.vfptr[3].__vecDelDtor)(&v24) )
    {
      v10 = 0;
      goto LABEL_12;
    }
    ((void (__fastcall *)(Scaleform::Render::MorphInterpolator *))v24.vfptr[7].__vecDelDtor)(&v24);
    v11 = Scaleform::Render::HitTestShapeStrokes<Scaleform::Render::TransformerBase>(&v24, p_trans, x, y);
LABEL_11:
    v10 = v11;
    goto LABEL_12;
  }
  v10 = 1;
LABEL_12:
  trans.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerBase::`vftable;
  v17 = &Scaleform::Render::TransformerBase::`vftable;
  pObject = v24.pMorphData.pObject;
  if ( v24.pMorphData.pObject && !_InterlockedDecrement(&v24.pMorphData.pObject->RefCount) && pObject )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v13 = v24.pShapeData.pObject;
  if ( v24.pShapeData.pObject && !_InterlockedDecrement(&v24.pShapeData.pObject->RefCount) && v13 )
    v13->vfptr->__vecDelDtor(v13, 1u);
  return v10;
}

