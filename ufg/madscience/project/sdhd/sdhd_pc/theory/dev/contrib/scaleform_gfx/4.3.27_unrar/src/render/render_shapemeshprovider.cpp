// File Line: 34
// RVA: 0x93FD10
void __fastcall Scaleform::Render::MorphInterpolator::MorphInterpolator(Scaleform::Render::MorphInterpolator *this, Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::MorphShapeData *morph, float ratio, Scaleform::Render::ShapePosInfo *pos2)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MorphInterpolator::`vftable';
  if ( shape )
    _InterlockedExchangeAdd(&shape->RefCount, 1u);
  this->pShapeData.pObject = shape;
  if ( morph )
    _InterlockedExchangeAdd(&morph->RefCount, 1u);
  this->pMorphData.pObject = morph;
  this->MorphRatio = ratio;
  this->Pos2.Pos = pos2->Pos;
  this->Pos2.StartX = pos2->StartX;
  this->Pos2.StartY = pos2->StartY;
  this->Pos2.LastX = pos2->LastX;
  this->Pos2.LastY = pos2->LastY;
  this->Pos2.FillBase = pos2->FillBase;
  this->Pos2.StrokeBase = pos2->StrokeBase;
  this->Pos2.NumFillBits = pos2->NumFillBits;
  this->Pos2.NumStrokeBits = pos2->NumStrokeBits;
  this->Pos2.Fill0 = pos2->Fill0;
  this->Pos2.Fill1 = pos2->Fill1;
  this->Pos2.Stroke = pos2->Stroke;
  this->Pos2.Sfactor = pos2->Sfactor;
  *(_DWORD *)&this->Pos2.Initialized = *(_DWORD *)&pos2->Initialized;
  this->Pos2s.Pos = pos2->Pos;
  this->Pos2s.StartX = pos2->StartX;
  this->Pos2s.StartY = pos2->StartY;
  this->Pos2s.LastX = pos2->LastX;
  this->Pos2s.LastY = pos2->LastY;
  this->Pos2s.FillBase = pos2->FillBase;
  this->Pos2s.StrokeBase = pos2->StrokeBase;
  this->Pos2s.NumFillBits = pos2->NumFillBits;
  this->Pos2s.NumStrokeBits = pos2->NumStrokeBits;
  this->Pos2s.Fill0 = pos2->Fill0;
  this->Pos2s.Fill1 = pos2->Fill1;
  this->Pos2s.Stroke = pos2->Stroke;
  this->Pos2s.Sfactor = pos2->Sfactor;
  *(_DWORD *)&this->Pos2s.Initialized = *(_DWORD *)&pos2->Initialized;
}

// File Line: 50
// RVA: 0x983E90
void __fastcall Scaleform::Render::MorphInterpolator::GetFillStyle(Scaleform::Render::MorphInterpolator *this, unsigned int idx, Scaleform::Render::FillStyleType *f1)
{
  Scaleform::Render::FillStyleType *v3; // rdi
  unsigned int v4; // esi
  Scaleform::Render::MorphInterpolator *v5; // rbx
  float v6; // xmm3_4
  float v7; // xmm0_4
  void (__fastcall ***v8)(_QWORD, signed __int64); // rcx
  unsigned __int8 v9; // [rsp+28h] [rbp-20h]
  unsigned __int8 v10; // [rsp+29h] [rbp-1Fh]
  unsigned __int8 v11; // [rsp+2Ah] [rbp-1Eh]
  unsigned __int8 v12; // [rsp+2Bh] [rbp-1Dh]
  __int64 v13; // [rsp+30h] [rbp-18h]
  unsigned int v14; // [rsp+50h] [rbp+8h]
  unsigned int v15; // [rsp+68h] [rbp+20h]

  v3 = f1;
  v4 = idx;
  v5 = this;
  ((void (__cdecl *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(this->pShapeData.pObject);
  if ( v5->pMorphData.pObject && v5->MorphRatio != 0.0 )
  {
    v13 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, unsigned __int8 *))v5->pMorphData.pObject->pMorphTo.pObject->vfptr[4].__vecDelDtor)(
      v5->pMorphData.pObject->pMorphTo.pObject,
      v4,
      &v9);
    if ( !v3->pFill.pObject )
    {
      v15 = v3->Color;
      v6 = v5->MorphRatio;
      v7 = (float)(unsigned __int8)(v3->Color >> 16);
      BYTE2(v14) = (signed int)(float)((float)((float)((float)((float)v11 - v7) * v6) + v7) + 0.5);
      BYTE1(v14) = (signed int)(float)((float)((float)((float)((float)v10 - (float)BYTE1(v15)) * v6) + (float)BYTE1(v15))
                                     + 0.5);
      LOBYTE(v14) = (signed int)(float)((float)((float)((float)((float)v9 - (float)(unsigned __int8)v3->Color) * v6)
                                              + (float)(unsigned __int8)v3->Color)
                                      + 0.5);
      HIBYTE(v14) = (signed int)(float)((float)((float)((float)((float)v12 - (float)(v3->Color >> 24)) * v6)
                                              + (float)(v3->Color >> 24))
                                      + 0.5);
      v3->Color = v14;
    }
    v8 = (void (__fastcall ***)(_QWORD, signed __int64))v13;
    if ( v13 && !_InterlockedDecrement((volatile signed __int32 *)(v13 + 8)) )
    {
      if ( v8 )
        (**v8)(v8, 1i64);
    }
  }
}

// File Line: 67
// RVA: 0x98C230
void __fastcall Scaleform::Render::MorphInterpolator::GetStrokeStyle(Scaleform::Render::MorphInterpolator *this, unsigned int idx, Scaleform::Render::StrokeStyleType *s1)
{
  Scaleform::Render::StrokeStyleType *v3; // rdi
  unsigned int v4; // esi
  Scaleform::Render::MorphInterpolator *v5; // rbx
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  void (__fastcall ***v10)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v11)(_QWORD, signed __int64); // rcx
  float v12; // [rsp+28h] [rbp-30h]
  unsigned __int8 v13; // [rsp+38h] [rbp-20h]
  unsigned __int8 v14; // [rsp+39h] [rbp-1Fh]
  unsigned __int8 v15; // [rsp+3Ah] [rbp-1Eh]
  unsigned __int8 v16; // [rsp+3Bh] [rbp-1Dh]
  __int64 v17; // [rsp+40h] [rbp-18h]
  __int64 v18; // [rsp+48h] [rbp-10h]
  unsigned int v19; // [rsp+60h] [rbp+8h]
  unsigned int v20; // [rsp+78h] [rbp+20h]

  v3 = s1;
  v4 = idx;
  v5 = this;
  ((void (__cdecl *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[5].__vecDelDtor)(this->pShapeData.pObject);
  if ( v5->pMorphData.pObject && v5->MorphRatio != 0.0 )
  {
    v17 = 0i64;
    v18 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))v5->pMorphData.pObject->pMorphTo.pObject->vfptr[5].__vecDelDtor)(
      v5->pMorphData.pObject->pMorphTo.pObject,
      v4,
      &v12);
    v3->Width = (float)((float)(v12 - v3->Width) * v5->MorphRatio) + v3->Width;
    if ( !v3->pFill.pObject )
    {
      v20 = v3->Color;
      v6 = v5->MorphRatio;
      v7 = (float)(unsigned __int8)(v3->Color >> 16);
      BYTE2(v19) = (signed int)(float)((float)((float)((float)((float)v15 - v7) * v6) + v7) + 0.5);
      BYTE1(v19) = (signed int)(float)((float)((float)((float)((float)v14 - (float)BYTE1(v20)) * v6) + (float)BYTE1(v20))
                                     + 0.5);
      v8 = (float)(unsigned __int8)v3->Color;
      LOBYTE(v19) = (signed int)(float)((float)((float)((float)((float)v13 - v8) * v6) + v8) + 0.5);
      v9 = (float)(v3->Color >> 24);
      HIBYTE(v19) = (signed int)(float)((float)((float)((float)((float)v16 - v9) * v6) + v9) + 0.5);
      v3->Color = v19;
    }
    v10 = (void (__fastcall ***)(_QWORD, signed __int64))v18;
    if ( v18 && !_InterlockedDecrement((volatile signed __int32 *)(v18 + 8)) && v10 )
      (**v10)(v10, 1i64);
    v11 = (void (__fastcall ***)(_QWORD, signed __int64))v17;
    if ( v17 && !_InterlockedDecrement((volatile signed __int32 *)(v17 + 8)) )
    {
      if ( v11 )
        (**v11)(v11, 1i64);
    }
  }
}

// File Line: 86
// RVA: 0x98B840
__int64 __fastcall Scaleform::Render::MorphInterpolator::GetStartingPos(Scaleform::Render::MorphInterpolator *this)
{
  Scaleform::Render::MorphShapeData *v1; // rax
  __int64 *v2; // rdx
  char v3; // al
  Scaleform::Render::ShapeDataInterface *v4; // rcx
  Scaleform::Render::ShapeDataInterface *v5; // rdx
  __int64 v6; // rdi
  char v8; // [rsp+20h] [rbp-18h]
  Scaleform::Render::ShapeDataInterface *v9; // [rsp+40h] [rbp+8h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v10; // [rsp+48h] [rbp+10h]

  v1 = this->pMorphData.pObject;
  if ( v1 )
  {
    if ( v1 != (Scaleform::Render::MorphShapeData *)-72i64 )
      _InterlockedExchangeAdd(&v1->ShapeData1.RefCount, 1u);
    v10 = &v1->ShapeData1;
    v2 = (__int64 *)&v10;
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
    v2 = (__int64 *)&v9;
    v3 = 2;
  }
  v6 = *v2;
  if ( v3 & 2 )
  {
    v3 &= 0xFDu;
    v8 = v3;
    if ( v4 )
    {
      if ( !_InterlockedDecrement(&v4->RefCount) )
        v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
      v3 = v8;
    }
  }
  if ( v3 & 1 && v10 && !_InterlockedDecrement(&v10->RefCount) )
    v10->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, 1u);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 48i64))(v6);
}

// File Line: 93
// RVA: 0x9A5DD0
__int64 __fastcall Scaleform::Render::MorphInterpolator::ReadPathInfo(Scaleform::Render::MorphInterpolator *this, Scaleform::Render::ShapePosInfo *pos1, float *coord1, unsigned int *styles1)
{
  Scaleform::Render::MorphInterpolator *v4; // rdi
  Scaleform::Render::MorphShapeData *v5; // rcx
  float *v6; // rbx
  unsigned int v8; // esi
  char v9; // [rsp+20h] [rbp-38h]
  float v10; // [rsp+30h] [rbp-28h]
  float v11; // [rsp+34h] [rbp-24h]

  v4 = this;
  v5 = this->pMorphData.pObject;
  v6 = coord1;
  if ( !v5 )
    return ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))v4->pShapeData.pObject->vfptr[8].__vecDelDtor)(
             v4->pShapeData.pObject,
             pos1,
             coord1,
             styles1);
  v8 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))v5->ShapeData1.vfptr[8].__vecDelDtor)(
         &v5->ShapeData1,
         pos1,
         coord1,
         styles1);
  ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *, char *))v4->pMorphData.pObject->ShapeData2.vfptr[8].__vecDelDtor)(
    &v4->pMorphData.pObject->ShapeData2,
    &v4->Pos2,
    &v10,
    &v9);
  if ( v8 )
  {
    *v6 = (float)((float)(v10 - *v6) * v4->MorphRatio) + *v6;
    v6[1] = (float)((float)(v11 - v6[1]) * v4->MorphRatio) + v6[1];
  }
  return v8;
}

// File Line: 115
// RVA: 0x9A4F80
__int64 __fastcall Scaleform::Render::MorphInterpolator::ReadEdge(Scaleform::Render::MorphInterpolator *this, Scaleform::Render::ShapePosInfo *pos1, float *coord1)
{
  Scaleform::Render::MorphInterpolator *v3; // rdi
  Scaleform::Render::MorphShapeData *v4; // rcx
  float *v5; // rbx
  unsigned int v7; // esi
  float v8; // [rsp+20h] [rbp-28h]
  float v9; // [rsp+24h] [rbp-24h]
  float v10; // [rsp+28h] [rbp-20h]
  float v11; // [rsp+2Ch] [rbp-1Ch]
  float v12; // [rsp+30h] [rbp-18h]
  float v13; // [rsp+34h] [rbp-14h]

  v3 = this;
  v4 = this->pMorphData.pObject;
  v5 = coord1;
  if ( !v4 )
    return v3->pShapeData.pObject->vfptr[9].__vecDelDtor(
             (Scaleform::RefCountImplCore *)&v3->pShapeData.pObject->vfptr,
             (unsigned int)pos1);
  v7 = (__int64)v4->ShapeData1.vfptr[9].__vecDelDtor(
                  (Scaleform::RefCountImplCore *)&v4->ShapeData1.vfptr,
                  (unsigned int)pos1);
  ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *))v3->pMorphData.pObject->ShapeData2.vfptr[9].__vecDelDtor)(
    &v3->pMorphData.pObject->ShapeData2,
    &v3->Pos2,
    &v8);
  if ( v7 )
  {
    *v5 = (float)((float)(v8 - *v5) * v3->MorphRatio) + *v5;
    v5[1] = (float)((float)(v9 - v5[1]) * v3->MorphRatio) + v5[1];
    if ( v7 - 2 <= 1 )
    {
      v5[2] = (float)((float)(v10 - v5[2]) * v3->MorphRatio) + v5[2];
      v5[3] = (float)((float)(v11 - v5[3]) * v3->MorphRatio) + v5[3];
      if ( v7 == 3 )
      {
        v5[4] = (float)((float)(v12 - v5[4]) * v3->MorphRatio) + v5[4];
        v5[5] = (float)((float)(v13 - v5[5]) * v3->MorphRatio) + v5[5];
      }
    }
  }
  return v7;
}

// File Line: 144
// RVA: 0x9B6870
void __fastcall Scaleform::Render::MorphInterpolator::SkipPathData(Scaleform::Render::MorphInterpolator *this, Scaleform::Render::ShapePosInfo *pos1)
{
  Scaleform::Render::MorphInterpolator *v2; // rbx
  Scaleform::Render::MorphShapeData *v3; // rcx
  signed __int64 v4; // rcx

  v2 = this;
  v3 = this->pMorphData.pObject;
  if ( v3 )
  {
    v3->ShapeData1.vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->ShapeData1.vfptr, (unsigned int)pos1);
    pos1 = &v2->Pos2;
    v4 = (signed __int64)&v2->pMorphData.pObject->ShapeData2;
  }
  else
  {
    v4 = (signed __int64)v2->pShapeData.pObject;
  }
  (*(void (__fastcall **)(signed __int64, Scaleform::Render::ShapePosInfo *))(*(_QWORD *)v4 + 80i64))(v4, pos1);
}

// File Line: 156
// RVA: 0x9AD5C0
void __fastcall Scaleform::Render::MorphInterpolator::Rewind(Scaleform::Render::MorphInterpolator *this)
{
  this->Pos2.Pos = this->Pos2s.Pos;
  this->Pos2.StartX = this->Pos2s.StartX;
  this->Pos2.StartY = this->Pos2s.StartY;
  this->Pos2.LastX = this->Pos2s.LastX;
  this->Pos2.LastY = this->Pos2s.LastY;
  this->Pos2.FillBase = this->Pos2s.FillBase;
  this->Pos2.StrokeBase = this->Pos2s.StrokeBase;
  this->Pos2.NumFillBits = this->Pos2s.NumFillBits;
  this->Pos2.NumStrokeBits = this->Pos2s.NumStrokeBits;
  this->Pos2.Fill0 = this->Pos2s.Fill0;
  this->Pos2.Fill1 = this->Pos2s.Fill1;
  this->Pos2.Stroke = this->Pos2s.Stroke;
  this->Pos2.Sfactor = this->Pos2s.Sfactor;
  *(_DWORD *)&this->Pos2.Initialized = *(_DWORD *)&this->Pos2s.Initialized;
}

// File Line: 174
// RVA: 0x93FE70
void __fastcall Scaleform::Render::MorphShapeData::MorphShapeData(Scaleform::Render::MorphShapeData *this, Scaleform::Render::ShapeDataInterface *morphTo)
{
  Scaleform::Render::MorphShapeData *v2; // r9
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v3; // rdx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // r8
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v5; // rcx
  signed __int64 v6; // [rsp+48h] [rbp+10h]
  signed __int64 v7; // [rsp+50h] [rbp+18h]
  signed __int64 v8; // [rsp+50h] [rbp+18h]
  signed __int64 v9; // [rsp+50h] [rbp+18h]
  signed __int64 v10; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MorphShapeData,71>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MorphShapeData::`vftable';
  if ( morphTo )
    _InterlockedExchangeAdd(&morphTo->RefCount, 1u);
  this->pMorphTo.pObject = morphTo;
  v3 = &this->Container1;
  v3->Data.Data = 0i64;
  v3->Data.Size = 0i64;
  v3->Data.Policy.Capacity = 0i64;
  v4 = &this->Container2;
  v4->Data.Data = 0i64;
  v4->Data.Size = 0i64;
  v4->Data.Policy.Capacity = 0i64;
  v5 = &this->ShapeData1;
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v5->RefCount = 1;
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable';
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable';
  v5->Status = 0;
  v7 = (signed __int64)&v5->Fills;
  *(_OWORD *)v7 = 0ui64;
  *(_QWORD *)(v7 + 16) = 0i64;
  v8 = (signed __int64)&v5->Strokes;
  *(_OWORD *)v8 = 0ui64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v5->Data = v3;
  *(_QWORD *)&v5->StartingPos = 0i64;
  *(_QWORD *)&v5->StartY = 0i64;
  v5->LastY = 0.0;
  v6 = (signed __int64)&v2->ShapeData2;
  *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(v6 + 8) = 1;
  *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable';
  *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
  *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
  *(_QWORD *)v6 = &Scaleform::Render::ShapeDataInterface::`vftable';
  *(_QWORD *)v6 = &Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable';
  v2->ShapeData2.Status = 0;
  v9 = (signed __int64)&v2->ShapeData2.Fills;
  *(_OWORD *)v9 = 0ui64;
  *(_QWORD *)(v9 + 16) = 0i64;
  v10 = (signed __int64)&v2->ShapeData2.Strokes;
  *(_OWORD *)v10 = 0ui64;
  *(_QWORD *)(v10 + 16) = 0i64;
  v2->ShapeData2.Data = v4;
  *(_QWORD *)&v2->ShapeData2.StartingPos = 0i64;
  *(_QWORD *)&v2->ShapeData2.StartY = 0i64;
  v2->ShapeData2.LastY = 0.0;
}

// File Line: 180
// RVA: 0x9444B0
void __fastcall Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::ShapeDataInterface *shape, Scaleform::Render::ShapeDataInterface *shapeMorph)
{
  Scaleform::Render::ShapeDataInterface *v3; // rsi
  Scaleform::Render::ShapeMeshProvider *v4; // rbx
  Scaleform::Render::MeshKeyManager *volatile v5; // rt1
  Scaleform::Render::MorphShapeData *v6; // rdi
  Scaleform::Render::MeshKeyManager *volatile v7; // rax
  Scaleform::ArrayLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::ArrayLH_POD<unsigned int,2,Scaleform::ArrayDefaultPolicy> *v9; // rax
  Scaleform::Render::MorphShapeData *v10; // rax
  Scaleform::Render::MorphShapeData *v11; // rax
  Scaleform::Render::MorphShapeData *v12; // rcx
  int v13; // [rsp+58h] [rbp+10h]
  Scaleform::Render::MorphShapeData *v14; // [rsp+60h] [rbp+18h]
  Scaleform::ArrayLH_POD<unsigned int,2,Scaleform::ArrayDefaultPolicy> *v15; // [rsp+68h] [rbp+20h]

  v3 = shapeMorph;
  v4 = this;
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
  v5 = this->hKeySet.pManager.Value;
  v6 = 0i64;
  this->hKeySet.pManager.Value = 0i64;
  v7 = this->hKeySet.pManager.Value;
  this->hKeySet.pKeySet = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  v8 = &this->DrawLayers;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  v9 = &this->FillToStyleTable;
  v14 = (Scaleform::Render::MorphShapeData *)v9;
  v15 = &this->FillToStyleTable;
  v9->Data.Data = 0i64;
  v9->Data.Size = 0i64;
  v9->Data.Policy.Capacity = 0i64;
  if ( shape )
    _InterlockedExchangeAdd(&shape->RefCount, 1u);
  this->pShapeData.pObject = shape;
  this->pMorphData.pObject = 0i64;
  *(_QWORD *)&this->IdentityBounds.x1 = 0i64;
  *(_QWORD *)&this->IdentityBounds.x2 = 0i64;
  *(_WORD *)&this->GradientMorph = 0;
  if ( shapeMorph )
  {
    v13 = 71;
    v10 = (Scaleform::Render::MorphShapeData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ShapeMeshProvider *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 280i64,
                                                 &v13,
                                                 -2i64);
    v14 = v10;
    if ( v10 )
    {
      Scaleform::Render::MorphShapeData::MorphShapeData(v10, v3);
      v6 = v11;
    }
    v12 = v4->pMorphData.pObject;
    if ( v12 && !_InterlockedDecrement(&v12->RefCount) && v12 )
      v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
    v4->pMorphData.pObject = v6;
    Scaleform::Render::ShapeMeshProvider::createMorphData(v4);
  }
  Scaleform::Render::ShapeMeshProvider::acquireShapeData(v4);
}

// File Line: 191
// RVA: 0x94CAF0
void __fastcall Scaleform::Render::ShapeMeshProvider::~ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::ShapeMeshProvider *v1; // rdi
  Scaleform::Render::MorphShapeData *v5; // rcx
  Scaleform::Render::ShapeDataInterface *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  if ( this->hKeySet.pKeySet )
  {
    _RDX = &this->hKeySet;
    _RSI = 0i64;
    __asm { xchg    rsi, [rdx]; Exchange Register/Memory with Register }
    if ( _RSI )
    {
      Scaleform::Render::MeshKeyManager::providerLost(_RSI, _RDX);
      if ( !_InterlockedDecrement(&_RSI->RefCount) )
        _RSI->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&_RSI->vfptr, 1u);
    }
  }
  v5 = v1->pMorphData.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v6 = v1->pShapeData.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
    v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->FillToStyleTable.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->DrawLayers.Data.Data);
  Scaleform::Render::MeshProvider_KeySupport::~MeshProvider_KeySupport((Scaleform::Render::MeshProvider_KeySupport *)&v1->vfptr);
}

// File Line: 217
// RVA: 0x9DD7C0
void __fastcall Scaleform::Render::ShapeMeshProvider::createMorphData(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::ShapeMeshProvider *v1; // rdi
  Scaleform::Render::ShapeDataInterface *v2; // rsi
  Scaleform::Render::ShapeDataInterface *v3; // r12
  unsigned int v4; // er14
  __int64 v5; // r10
  __int64 v6; // r11
  unsigned __int16 v7; // cx
  unsigned int v8; // edx
  __int64 v9; // r8
  __int64 v10; // r9
  void (__fastcall ***v11)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v12)(_QWORD, signed __int64); // rcx
  unsigned int v13; // er14
  __int64 v14; // r10
  __int64 v15; // r11
  unsigned __int16 v16; // cx
  unsigned int v17; // edx
  __int64 v18; // r8
  __int64 v19; // r9
  void (__fastcall ***v20)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v21)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v22)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v23)(_QWORD, signed __int64); // rcx
  unsigned int v24; // ebx
  int v25; // eax
  Scaleform::Render::MorphShapeData *v26; // r14
  unsigned __int64 v27; // r15
  signed __int64 v28; // rbx
  __int64 v29; // rcx
  unsigned __int64 v30; // r15
  Scaleform::Render::StrokeStyleType *v31; // rax
  signed __int64 v32; // rbx
  __int64 v33; // rcx
  __int64 v34; // rcx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v35; // rbx
  Scaleform::Render::MorphShapeData *v36; // r14
  unsigned __int64 v37; // r15
  signed __int64 v38; // rbx
  __int64 v39; // rcx
  char v40; // r14
  int v41; // ebx
  int v42; // eax
  float v43; // xmm9_4
  float v44; // xmm8_4
  float v45; // xmm6_4
  float v46; // xmm7_4
  __int64 v47; // r14
  __int128 v48; // kr00_16
  int v49; // ebx
  int v50; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v51; // rcx
  int v52; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v53; // rcx
  int v54; // eax
  unsigned int leftStyle[2]; // [rsp+40h] [rbp-80h]
  char strokeStyle[12]; // [rsp+48h] [rbp-78h]
  __int128 v57; // [rsp+54h] [rbp-6Ch]
  float x[2]; // [rsp+64h] [rbp-5Ch]
  float y; // [rsp+6Ch] [rbp-54h]
  float ay[2]; // [rsp+70h] [rbp-50h]
  char v61[24]; // [rsp+78h] [rbp-48h]
  char v62[20]; // [rsp+90h] [rbp-30h]
  int v63; // [rsp+A4h] [rbp-1Ch]
  __int64 v64; // [rsp+A8h] [rbp-18h]
  __int64 v65; // [rsp+B0h] [rbp-10h]
  __int64 v66; // [rsp+B8h] [rbp-8h]
  __int64 v67; // [rsp+C0h] [rbp+0h]
  __int64 v68; // [rsp+C8h] [rbp+8h]
  __int64 v69; // [rsp+D0h] [rbp+10h]
  __int64 v70; // [rsp+D8h] [rbp+18h]
  __int64 v71; // [rsp+E0h] [rbp+20h]
  __int64 v72; // [rsp+E8h] [rbp+28h]
  __int64 v73; // [rsp+F0h] [rbp+30h]
  __int64 v74; // [rsp+F8h] [rbp+38h]
  char v75; // [rsp+100h] [rbp+40h]
  __int128 v76; // [rsp+118h] [rbp+58h]
  char v77; // [rsp+128h] [rbp+68h]
  char v78; // [rsp+138h] [rbp+78h]
  __int128 v79; // [rsp+150h] [rbp+90h]
  __int64 v80; // [rsp+160h] [rbp+A0h]
  int v81; // [rsp+210h] [rbp+150h]
  __int128 v82; // [rsp+218h] [rbp+158h]
  __int64 v83; // [rsp+228h] [rbp+168h]

  v80 = -2i64;
  v1 = this;
  v2 = this->pShapeData.pObject;
  v3 = this->pMorphData.pObject->pMorphTo.pObject;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v2->vfptr[2].__vecDelDtor)(this->pShapeData.pObject) )
  {
    v4 = 1;
    while ( 1 )
    {
      v66 = 0i64;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, __int64 *))v2->vfptr[4].__vecDelDtor)(
        v2,
        v4,
        &v65);
      if ( v66 )
      {
        if ( *(_QWORD *)(v66 + 24) )
          break;
      }
LABEL_20:
      v12 = (void (__fastcall ***)(_QWORD, signed __int64))v66;
      if ( v66 && !_InterlockedDecrement((volatile signed __int32 *)(v66 + 8)) && v12 )
        (**v12)(v12, 1i64);
      if ( ++v4 - 1 >= ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v2->vfptr[2].__vecDelDtor)(v2) )
        goto LABEL_25;
    }
    v68 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, __int64 *))v3->vfptr[4].__vecDelDtor)(
      v3,
      v4,
      &v67);
    v5 = *(_QWORD *)(v68 + 24);
    v6 = *(_QWORD *)(v66 + 24);
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
        v11 = (void (__fastcall ***)(_QWORD, signed __int64))v68;
        if ( v68 && !_InterlockedDecrement((volatile signed __int32 *)(v68 + 8)) && v11 )
          (**v11)(v11, 1i64);
        goto LABEL_20;
      }
      v9 = *(_QWORD *)(v5 + 24);
      v10 = *(_QWORD *)(v6 + 24);
      while ( *(_BYTE *)(v10 + 8i64 * v8) == *(_BYTE *)(v9 + 8i64 * v8) )
      {
        v81 = *(_DWORD *)(v9 + 8i64 * v8 + 4);
        if ( *(_DWORD *)(v10 + 8i64 * v8 + 4) != v81 )
          break;
        if ( ++v8 >= v7 )
          goto LABEL_16;
      }
    }
    *(_QWORD *)(v6 + 40) = v5;
    v1->GradientMorph = 1;
    goto LABEL_16;
  }
LABEL_25:
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v2->vfptr[3].__vecDelDtor)(v2) )
  {
    v13 = 1;
    while ( 1 )
    {
      v76 = 0ui64;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v2->vfptr[5].__vecDelDtor)(
        v2,
        v13,
        &v75);
      if ( (_QWORD)v76 )
      {
        if ( *(_QWORD *)(v76 + 24) )
          break;
      }
LABEL_48:
      v22 = (void (__fastcall ***)(_QWORD, signed __int64))*((_QWORD *)&v76 + 1);
      if ( *((_QWORD *)&v76 + 1)
        && !_InterlockedDecrement((volatile signed __int32 *)(*((_QWORD *)&v76 + 1) + 8i64))
        && v22 )
      {
        (**v22)(v22, 1i64);
      }
      v23 = (void (__fastcall ***)(_QWORD, signed __int64))v76;
      if ( (_QWORD)v76 && !_InterlockedDecrement((volatile signed __int32 *)(v76 + 8)) && v23 )
        (**v23)(v23, 1i64);
      if ( ++v13 - 1 >= ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v2->vfptr[3].__vecDelDtor)(v2) )
        goto LABEL_57;
    }
    v79 = 0ui64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v3->vfptr[5].__vecDelDtor)(
      v3,
      v13,
      &v78);
    v14 = *(_QWORD *)(v79 + 24);
    v15 = *(_QWORD *)(v76 + 24);
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
        LODWORD(v82) = *(_DWORD *)(v18 + 8i64 * v17 + 4);
        if ( *(_DWORD *)(v19 + 8i64 * v17 + 4) != (_DWORD)v82 )
          break;
        if ( ++v17 >= v16 )
          goto LABEL_40;
      }
    }
    *(_QWORD *)(v15 + 40) = v14;
    v1->GradientMorph = 1;
LABEL_40:
    v20 = (void (__fastcall ***)(_QWORD, signed __int64))*((_QWORD *)&v79 + 1);
    if ( *((_QWORD *)&v79 + 1)
      && !_InterlockedDecrement((volatile signed __int32 *)(*((_QWORD *)&v79 + 1) + 8i64))
      && v20 )
    {
      (**v20)(v20, 1i64);
    }
    v21 = (void (__fastcall ***)(_QWORD, signed __int64))v79;
    if ( (_QWORD)v79 && !_InterlockedDecrement((volatile signed __int32 *)(v79 + 8)) && v21 )
      (**v21)(v21, 1i64);
    goto LABEL_48;
  }
LABEL_57:
  v24 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v2->vfptr[6].__vecDelDtor)(v2);
  v25 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v3->vfptr[6].__vecDelDtor)(v3);
  leftStyle[0] = v24;
  *(_QWORD *)&leftStyle[1] = 0i64;
  *(_QWORD *)&strokeStyle[4] = 0i64;
  v57 = 0ui64;
  *(_QWORD *)x = 0i64;
  y = 0.0;
  ay[0] = 1.0;
  LOBYTE(ay[1]) = 0;
  *(_DWORD *)v61 = v25;
  *(_OWORD *)&v61[4] = 0ui64;
  *(_OWORD *)&v61[20] = 0ui64;
  *(_QWORD *)&v62[12] = 0i64;
  v63 = 0;
  LODWORD(v64) = 1065353216;
  BYTE4(v64) = 0;
  v26 = v1->pMorphData.pObject;
  v26->ShapeData1.Status = 0;
  v27 = v26->ShapeData1.Fills.Data.Size;
  if ( v27 )
  {
    v28 = (signed __int64)&v26->ShapeData1.Fills.Data.Data[v27 - 1];
    *((_QWORD *)&v82 + 1) = &v26->ShapeData1.Fills.Data.Data[v27 - 1];
    do
    {
      v29 = *(_QWORD *)(v28 + 8);
      if ( v29 && !_InterlockedDecrement((volatile signed __int32 *)(v29 + 8)) && v29 )
        (**(void (__fastcall ***)(__int64, signed __int64))v29)(v29, 1i64);
      v28 -= 16i64;
      *((_QWORD *)&v82 + 1) = v28;
      --v27;
    }
    while ( v27 );
    if ( v26->ShapeData1.Fills.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v26->ShapeData1.Fills.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v26->ShapeData1.Fills.Data.Data = 0i64;
      }
      v26->ShapeData1.Fills.Data.Policy.Capacity = 0i64;
    }
  }
  v26->ShapeData1.Fills.Data.Size = 0i64;
  v30 = v26->ShapeData1.Strokes.Data.Size;
  if ( v30 )
  {
    v31 = v26->ShapeData1.Strokes.Data.Data;
    v32 = (signed __int64)&v31[v30 - 1];
    *((_QWORD *)&v82 + 1) = &v31[v30 - 1];
    do
    {
      v33 = *(_QWORD *)(v32 + 32);
      if ( v33 && !_InterlockedDecrement((volatile signed __int32 *)(v33 + 8)) && v33 )
        (**(void (__fastcall ***)(__int64, signed __int64))v33)(v33, 1i64);
      v34 = *(_QWORD *)(v32 + 24);
      if ( v34 && !_InterlockedDecrement((volatile signed __int32 *)(v34 + 8)) && v34 )
        (**(void (__fastcall ***)(__int64, signed __int64))v34)(v34, 1i64);
      v32 -= 40i64;
      *((_QWORD *)&v82 + 1) = v32;
      --v30;
    }
    while ( v30 );
    if ( v26->ShapeData1.Strokes.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v26->ShapeData1.Strokes.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v26->ShapeData1.Strokes.Data.Data = 0i64;
      }
      v26->ShapeData1.Strokes.Data.Policy.Capacity = 0i64;
    }
  }
  v26->ShapeData1.Strokes.Data.Size = 0i64;
  v35 = v26->ShapeData1.Data;
  if ( v35->Data.Size && v35->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v26->ShapeData1.Data,
      v26->ShapeData1.Data,
      0i64);
  v35->Data.Size = 0i64;
  *(_QWORD *)&v26->ShapeData1.StartX = 0i64;
  *(_QWORD *)&v26->ShapeData1.LastX = 0i64;
  v36 = v1->pMorphData.pObject;
  v36->ShapeData2.Status = 0;
  v37 = v36->ShapeData2.Fills.Data.Size;
  if ( v37 )
  {
    v38 = (signed __int64)&v36->ShapeData2.Fills.Data.Data[v37 - 1];
    *((_QWORD *)&v82 + 1) = &v36->ShapeData2.Fills.Data.Data[v37 - 1];
    do
    {
      v39 = *(_QWORD *)(v38 + 8);
      if ( v39 && !_InterlockedDecrement((volatile signed __int32 *)(v39 + 8)) && v39 )
        (**(void (__fastcall ***)(__int64, signed __int64))v39)(v39, 1i64);
      v38 -= 16i64;
      *((_QWORD *)&v82 + 1) = v38;
      --v37;
    }
    while ( v37 );
    if ( v36->ShapeData2.Fills.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v36->ShapeData2.Fills.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v36->ShapeData2.Fills.Data.Data = 0i64;
      }
      v36->ShapeData2.Fills.Data.Policy.Capacity = 0i64;
    }
  }
  v36->ShapeData2.Fills.Data.Size = 0i64;
  Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v36->ShapeData2.Strokes.Data,
    0i64);
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v36->ShapeData2.Data,
    0i64);
  *(_QWORD *)&v36->ShapeData2.StartX = 0i64;
  *(_QWORD *)&v36->ShapeData2.LastX = 0i64;
  v40 = 1;
  LOBYTE(v81) = 1;
  while ( 2 )
  {
    v41 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, float *, unsigned int *))v2->vfptr[8].__vecDelDtor)(
            v2,
            leftStyle,
            &x[1],
            leftStyle);
    v42 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, char *, char *, char *))v3->vfptr[8].__vecDelDtor)(
            v3,
            v61,
            &strokeStyle[8],
            &v77);
    if ( !v41 || !v42 )
    {
      v53 = &v1->pMorphData.pObject->ShapeData1;
      goto LABEL_128;
    }
    if ( v41 == 2 || v40 )
    {
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(&v1->pMorphData.pObject->ShapeData1);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(&v1->pMorphData.pObject->ShapeData2);
      LOBYTE(v81) = 0;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &v1->pMorphData.pObject->ShapeData1,
      leftStyle[0],
      leftStyle[1],
      *(unsigned int *)strokeStyle);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &v1->pMorphData.pObject->ShapeData2,
      leftStyle[0],
      leftStyle[1],
      *(unsigned int *)strokeStyle);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &v1->pMorphData.pObject->ShapeData1,
      x[1],
      y);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &v1->pMorphData.pObject->ShapeData2,
      *(float *)&strokeStyle[8],
      *(float *)&v57);
LABEL_104:
    v43 = *(float *)&v57;
    v44 = *(float *)&strokeStyle[8];
LABEL_105:
    v45 = x[1];
    v46 = y;
    while ( 1 )
    {
      v70 = *(_QWORD *)leftStyle;
      v69 = *(_QWORD *)strokeStyle;
      v71 = *(_QWORD *)&strokeStyle[8];
      v73 = *(_QWORD *)((char *)&v57 + 4);
      v72 = *(_QWORD *)((char *)&v57 + 12);
      v67 = *(_QWORD *)&x[1];
      v65 = *(_QWORD *)ay;
      v47 = *(_QWORD *)v61;
      v48 = *(_OWORD *)&v61[8];
      v82 = *(_OWORD *)v62;
      v83 = *(_QWORD *)&v62[16];
      v74 = v64;
      v49 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, float *))v2->vfptr[9].__vecDelDtor)(
              v2,
              leftStyle,
              &x[1]);
      v50 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, char *, char *))v3->vfptr[9].__vecDelDtor)(
              v3,
              v61,
              &strokeStyle[8]);
      if ( !v49 )
        break;
      if ( v50 )
      {
        if ( v49 != v50 )
        {
          if ( v49 == 1 )
          {
            if ( v50 != 2 )
              goto LABEL_121;
            ay[0] = x[1];
            ay[1] = y;
            x[1] = (float)(v45 + x[1]) * 0.5;
            y = (float)(v46 + y) * 0.5;
            goto LABEL_123;
          }
          if ( v49 == 2 )
          {
            if ( v50 == 1 )
            {
              *(_QWORD *)((char *)&v57 + 4) = *(_QWORD *)&strokeStyle[8];
              *(float *)&strokeStyle[8] = (float)(v44 + *(float *)&strokeStyle[8]) * 0.5;
              *(float *)&v57 = (float)(v43 + *(float *)&v57) * 0.5;
            }
            goto LABEL_123;
          }
        }
        switch ( v49 )
        {
          case 1:
LABEL_121:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              &v1->pMorphData.pObject->ShapeData1,
              x[1],
              y);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
              &v1->pMorphData.pObject->ShapeData2,
              *(float *)&strokeStyle[8],
              *(float *)&v57);
            goto LABEL_104;
          case 2:
LABEL_123:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &v1->pMorphData.pObject->ShapeData1,
              x[1],
              y,
              ay[0],
              ay[1]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &v1->pMorphData.pObject->ShapeData2,
              *(float *)&strokeStyle[8],
              *(float *)&v57,
              *((float *)&v57 + 1),
              *((float *)&v57 + 2));
            v45 = ay[0];
            v46 = ay[1];
            v43 = *((float *)&v57 + 2);
            v44 = *((float *)&v57 + 1);
            break;
          case 3:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &v1->pMorphData.pObject->ShapeData1,
              x[1],
              y,
              ay[0],
              ay[1],
              *(float *)v61,
              *(float *)&v61[4]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &v1->pMorphData.pObject->ShapeData2,
              *(float *)&strokeStyle[8],
              *(float *)&v57,
              *((float *)&v57 + 1),
              *((float *)&v57 + 2),
              *((float *)&v57 + 3),
              x[0]);
            v45 = *(float *)v61;
            v46 = *(float *)&v61[4];
            v44 = *((float *)&v57 + 3);
            v43 = x[0];
            break;
        }
      }
      else
      {
        *(_QWORD *)leftStyle = v70;
        *(_QWORD *)strokeStyle = v69;
        *(_QWORD *)&strokeStyle[8] = v71;
        *(_QWORD *)((char *)&v57 + 4) = v73;
        *(_QWORD *)((char *)&v57 + 12) = v72;
        *(_QWORD *)&x[1] = v67;
        *(_QWORD *)ay = v65;
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&v1->pMorphData.pObject->ShapeData1);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&v1->pMorphData.pObject->ShapeData2);
        v54 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, char *, char *, char *))v3->vfptr[8].__vecDelDtor)(
                v3,
                v61,
                &strokeStyle[8],
                &v77);
        v53 = &v1->pMorphData.pObject->ShapeData1;
        if ( !v54 )
          goto LABEL_128;
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
          v53,
          leftStyle[0],
          leftStyle[1],
          *(unsigned int *)strokeStyle);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
          &v1->pMorphData.pObject->ShapeData2,
          leftStyle[0],
          leftStyle[1],
          *(unsigned int *)strokeStyle);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
          &v1->pMorphData.pObject->ShapeData1,
          v45,
          v46);
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
          &v1->pMorphData.pObject->ShapeData2,
          *(float *)&strokeStyle[8],
          *(float *)&v57);
        v44 = *(float *)&strokeStyle[8];
        v43 = *(float *)&v57;
      }
    }
    v51 = &v1->pMorphData.pObject->ShapeData1;
    if ( !v50 )
    {
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v51);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&v1->pMorphData.pObject->ShapeData2);
      v40 = v81;
      continue;
    }
    break;
  }
  *(_QWORD *)v61 = v47;
  *(_OWORD *)&v61[8] = v48;
  *(_OWORD *)v62 = v82;
  *(_QWORD *)&v62[16] = v83;
  v64 = v74;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v51);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(&v1->pMorphData.pObject->ShapeData2);
  v52 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, float *, unsigned int *))v2->vfptr[8].__vecDelDtor)(
          v2,
          leftStyle,
          &x[1],
          leftStyle);
  v53 = &v1->pMorphData.pObject->ShapeData1;
  if ( v52 )
  {
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v53,
      leftStyle[0],
      leftStyle[1],
      *(unsigned int *)strokeStyle);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &v1->pMorphData.pObject->ShapeData2,
      leftStyle[0],
      leftStyle[1],
      *(unsigned int *)strokeStyle);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &v1->pMorphData.pObject->ShapeData1,
      x[1],
      y);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &v1->pMorphData.pObject->ShapeData2,
      v44,
      v43);
    goto LABEL_105;
  }
LABEL_128:
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v53);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(&v1->pMorphData.pObject->ShapeData2);
}

// File Line: 442
// RVA: 0x9DC8E0
void __fastcall Scaleform::Render::ShapeMeshProvider::countComplexFills(Scaleform::Render::ShapeMeshProvider *this, Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *paths, unsigned __int64 i1, unsigned __int64 i2, Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *v5; // r12
  Scaleform::Render::ShapeMeshProvider *v6; // r13
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
  __int64 *v17; // rax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  __int64 v23; // rsi
  unsigned int v24; // ebx
  Scaleform::MemoryHeapVtbl *v25; // rax
  __int64 *v26; // rax
  __int64 *v27; // rax
  void (__fastcall ***v28)(_QWORD, signed __int64); // rcx
  char v29; // [rsp+28h] [rbp-28h]
  __int64 v30; // [rsp+30h] [rbp-20h]
  __int64 v31; // [rsp+38h] [rbp-18h]
  __int64 *v32; // [rsp+40h] [rbp-10h]
  Scaleform::MemoryHeap *v33; // [rsp+48h] [rbp-8h]
  unsigned __int64 v34; // [rsp+98h] [rbp+48h]

  v5 = paths;
  v6 = this;
  v31 = 32i64;
  v32 = (__int64 *)((char *)&v31 + 4);
  v33 = Scaleform::Memory::pGlobalHeap;
  dl->StartFill = this->FillToStyleTable.Data.Size;
  dl->FillCount = 0;
  if ( i1 < i2 )
  {
    v7 = i1;
    v34 = i2 - i1;
    while ( v5->Data[v7].Styles[0] == v5->Data[v7].Styles[1] )
    {
LABEL_48:
      ++v7;
      if ( !--v34 )
        goto LABEL_49;
    }
    v30 = 0i64;
    v8 = v5->Data[v7].Styles[0];
    if ( !v8 )
      goto LABEL_24;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v6->pShapeData.pObject->vfptr[4].__vecDelDtor)(
      v6->pShapeData.pObject,
      v8,
      &v29);
    v9 = 0;
    if ( v30 )
      v9 = v8;
    if ( v9 < (unsigned int)v31 && *((_DWORD *)v32 + ((unsigned __int64)v9 >> 5)) & (1 << (v9 & 0x1F)) )
    {
LABEL_24:
      v18 = v5->Data[v7].Styles[1];
      if ( !v18 )
        goto LABEL_44;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v6->pShapeData.pObject->vfptr[4].__vecDelDtor)(
        v6->pShapeData.pObject,
        v18,
        &v29);
      v19 = 0;
      if ( v30 )
        v19 = v18;
      if ( v19 < (unsigned int)v31 && *((_DWORD *)v32 + ((unsigned __int64)v19 >> 5)) & (1 << (v19 & 0x1F)) )
        goto LABEL_44;
      v20 = v6->FillToStyleTable.Data.Size;
      v21 = v20 + 1;
      if ( v20 + 1 >= v20 )
      {
        if ( v21 > v6->FillToStyleTable.Data.Policy.Capacity )
        {
          v22 = v21 + (v21 >> 2);
          goto LABEL_34;
        }
      }
      else if ( v21 < v6->FillToStyleTable.Data.Policy.Capacity >> 1 )
      {
        v22 = v20 + 1;
LABEL_34:
        Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy> *)&v6->FillToStyleTable,
          &v6->FillToStyleTable,
          v22);
        goto LABEL_35;
      }
LABEL_35:
      v6->FillToStyleTable.Data.Size = v21;
      v6->FillToStyleTable.Data.Data[v21 - 1] = v19;
      ++dl->FillCount;
      if ( v19 >= (unsigned int)v31 )
      {
        v23 = (unsigned int)(v31 + 31) >> 5;
        v24 = (v19 + 32) >> 5;
        if ( v24 < 2 * (signed int)v23 )
          v24 = 2 * v23;
        if ( v24 > (unsigned int)v23 )
        {
          v25 = v33->vfptr;
          if ( v32 == (__int64 *)((char *)&v31 + 4) )
          {
            v26 = (__int64 *)v25->Alloc(v33, 4i64 * v24, 0i64);
            v32 = v26;
            *(_DWORD *)v26 = HIDWORD(v31);
            v27 = v32;
          }
          else
          {
            v27 = (__int64 *)v25->Realloc(v33, v32, 4i64 * v24);
            v32 = v27;
          }
          memset((char *)v27 + 4 * v23, 0, 4i64 * (v24 - (unsigned int)v23));
          LODWORD(v31) = 32 * v24;
        }
      }
      *((_DWORD *)v32 + ((unsigned __int64)v19 >> 5)) |= 1 << (v19 & 0x1F);
LABEL_44:
      v28 = (void (__fastcall ***)(_QWORD, signed __int64))v30;
      if ( v30 && !_InterlockedDecrement((volatile signed __int32 *)(v30 + 8)) && v28 )
        (**v28)(v28, 1i64);
      goto LABEL_48;
    }
    v10 = v6->FillToStyleTable.Data.Size;
    v11 = v10 + 1;
    if ( v10 + 1 >= v10 )
    {
      if ( v11 > v6->FillToStyleTable.Data.Policy.Capacity )
      {
        v12 = v11 + (v11 >> 2);
        goto LABEL_14;
      }
    }
    else if ( v11 < v6->FillToStyleTable.Data.Policy.Capacity >> 1 )
    {
      v12 = v10 + 1;
LABEL_14:
      Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy> *)&v6->FillToStyleTable,
        &v6->FillToStyleTable,
        v12);
      goto LABEL_15;
    }
LABEL_15:
    v6->FillToStyleTable.Data.Size = v11;
    v6->FillToStyleTable.Data.Data[v11 - 1] = v9;
    ++dl->FillCount;
    if ( v9 >= (unsigned int)v31 )
    {
      v13 = (unsigned int)(v31 + 31) >> 5;
      v14 = (v9 + 32) >> 5;
      if ( v14 < 2 * (signed int)v13 )
        v14 = 2 * v13;
      if ( v14 > (unsigned int)v13 )
      {
        v15 = v33->vfptr;
        if ( v32 == (__int64 *)((char *)&v31 + 4) )
        {
          v16 = (__int64 *)v15->Alloc(v33, 4i64 * v14, 0i64);
          v32 = v16;
          *(_DWORD *)v16 = HIDWORD(v31);
          v17 = v32;
        }
        else
        {
          v17 = (__int64 *)v15->Realloc(v33, v32, 4i64 * v14);
          v32 = v17;
        }
        memset((char *)v17 + 4 * v13, 0, 4i64 * (v14 - (unsigned int)v13));
        LODWORD(v31) = 32 * v14;
      }
    }
    *((_DWORD *)v32 + ((unsigned __int64)v9 >> 5)) |= 1 << (v9 & 0x1F);
    goto LABEL_24;
  }
LABEL_49:
  if ( v32 != (__int64 *)((char *)&v31 + 4) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))v33->vfptr->Free)(v33);
}

// File Line: 485
// RVA: 0x9DCDC0
void __fastcall Scaleform::Render::ShapeMeshProvider::createDrawLayers(Scaleform::Render::ShapeMeshProvider *this, Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *paths, unsigned __int64 i1, unsigned __int64 i2)
{
  unsigned __int64 v4; // r12
  unsigned __int64 v5; // r13
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *v6; // rsi
  Scaleform::Render::ShapeMeshProvider *v7; // rdi
  unsigned __int64 v8; // r9
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v9; // rax
  unsigned int v10; // ebx
  __int64 *v11; // rdx
  unsigned __int64 v12; // r14
  unsigned __int64 v13; // r15
  __int64 v14; // r8
  Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *v15; // rbx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rdi
  unsigned __int64 v18; // r8
  signed __int64 v19; // rdx
  Scaleform::MemoryHeapVtbl *v20; // rax
  __int64 *v21; // rax
  __int64 *v22; // rax
  unsigned __int64 v23; // rdi
  __int64 v24; // rsi
  unsigned int v25; // ebx
  Scaleform::MemoryHeapVtbl *v26; // rax
  __int64 *v27; // rax
  __int64 *v28; // rax
  unsigned __int64 v29; // r12
  unsigned int v30; // ebx
  signed int v31; // er14
  unsigned __int64 v32; // r15
  Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *v33; // rdi
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // rsi
  unsigned __int64 v36; // r8
  signed __int64 v37; // rcx
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v38; // rax
  __int64 v39; // rdi
  unsigned int v40; // ebx
  Scaleform::MemoryHeapVtbl *v41; // rax
  __int64 *v42; // rax
  __int64 *v43; // rax
  Scaleform::Render::ShapeMeshProvider::DrawLayerType v44; // [rsp+38h] [rbp-40h]
  __int64 v45; // [rsp+50h] [rbp-28h]
  __int64 *v46; // [rsp+58h] [rbp-20h]
  Scaleform::MemoryHeap *v47; // [rsp+60h] [rbp-18h]
  Scaleform::Render::ShapeMeshProvider *v48; // [rsp+C0h] [rbp+48h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *v49; // [rsp+C8h] [rbp+50h]
  unsigned int v50; // [rsp+D0h] [rbp+58h]
  unsigned __int64 v51; // [rsp+D8h] [rbp+60h]

  if ( i2 > i1 )
  {
    v49 = paths;
    v48 = this;
    v4 = i2;
    v5 = i1;
    v6 = paths;
    v7 = this;
    v45 = 32i64;
    v46 = (__int64 *)((char *)&v45 + 4);
    v47 = Scaleform::Memory::pGlobalHeap;
    v8 = 24 * i1;
    v51 = 24 * i1;
    v9 = paths->Data;
    v10 = v9[i1].Pos;
    v50 = v9[i1].Pos;
    v11 = (__int64 *)((char *)&v45 + 4);
    if ( i1 < v4 )
    {
      v12 = i1;
      v13 = v4 - i1;
      v14 = (unsigned int)v45;
      while ( 1 )
      {
        if ( v6->Data[v12].Styles[0] == v6->Data[v12].Styles[1] || (_DWORD)v14 && *(_DWORD *)v11 & 1 )
          goto LABEL_20;
        Scaleform::Render::ShapeMeshProvider::countComplexFills(v7, v6, v5, v4, &v44);
        v44.StartPos = v10;
        *(_QWORD *)&v44.StrokeStyle = 0i64;
        v15 = (Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *)&v7->DrawLayers.Data.Data;
        v16 = v7->DrawLayers.Data.Size;
        v17 = v16 + 1;
        if ( v16 + 1 >= v16 )
        {
          if ( v17 > v15->Policy.Capacity )
          {
            v18 = v17 + (v17 >> 2);
            goto LABEL_13;
          }
        }
        else if ( v17 < v15->Policy.Capacity >> 1 )
        {
          v18 = v16 + 1;
LABEL_13:
          Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v15,
            v15,
            v18);
          goto LABEL_14;
        }
LABEL_14:
        v15->Size = v17;
        v19 = (signed __int64)&v15->Data[v17];
        *(_DWORD *)(v19 - 20) = v50;
        *(_DWORD *)(v19 - 16) = v44.StartFill;
        *(_DWORD *)(v19 - 12) = v44.FillCount;
        *(_QWORD *)(v19 - 8) = 0i64;
        if ( !(_DWORD)v45 )
        {
          v20 = v47->vfptr;
          if ( v46 == (__int64 *)((char *)&v45 + 4) )
          {
            v21 = (__int64 *)v20->Alloc(v47, 4ui64, 0i64);
            v46 = v21;
            *(_DWORD *)v21 = HIDWORD(v45);
            v22 = v46;
          }
          else
          {
            v22 = (__int64 *)v20->Realloc(v47, v46, 4ui64);
            v46 = v22;
          }
          memset(v22, 0, 4ui64);
          LODWORD(v45) = 32;
        }
        *(_DWORD *)v46 |= 1u;
        v11 = v46;
        v14 = (unsigned int)v45;
LABEL_20:
        v23 = v6->Data[v12].Styles[2];
        if ( (_DWORD)v23 )
        {
          if ( (unsigned int)v23 >= (unsigned int)v14 )
          {
            v24 = (unsigned int)(v14 + 31) >> 5;
            v25 = (unsigned int)(v23 + 32) >> 5;
            if ( v25 < 2 * (signed int)v24 )
              v25 = 2 * v24;
            if ( v25 > (unsigned int)v24 )
            {
              v26 = v47->vfptr;
              if ( v11 == (__int64 *)((char *)&v45 + 4) )
              {
                v27 = (__int64 *)v26->Alloc(v47, 4i64 * v25, 0i64);
                v46 = v27;
                *(_DWORD *)v27 = HIDWORD(v45);
                v28 = v46;
              }
              else
              {
                v28 = (__int64 *)v26->Realloc(v47, v11, 4i64 * v25);
                v46 = v28;
              }
              memset((char *)v28 + 4 * v24, 0, 4i64 * (v25 - (unsigned int)v24));
              LODWORD(v45) = 32 * v25;
              v11 = v46;
            }
            v6 = v49;
          }
          *((_DWORD *)v11 + (v23 >> 5)) |= 1 << (v23 & 0x1F);
          v11 = v46;
          v14 = (unsigned int)v45;
        }
        ++v12;
        --v13;
        v7 = v48;
        if ( !v13 )
        {
          v8 = v51;
          goto LABEL_34;
        }
        v10 = v50;
      }
    }
    v14 = (unsigned int)v45;
LABEL_34:
    if ( v5 < v4 )
    {
      v29 = v4 - v5;
      while ( 1 )
      {
        v30 = *(unsigned int *)((char *)&v6->Data->Styles[2] + v8);
        if ( v30 )
        {
          if ( v30 < (unsigned int)v14 )
          {
            v31 = 1 << (v30 & 0x1F);
            v32 = 4 * ((unsigned __int64)v30 >> 5);
            if ( v31 & *(_DWORD *)((_BYTE *)v11 + v32) )
              break;
          }
        }
LABEL_54:
        v8 += 24i64;
        v51 = v8;
        if ( !--v29 )
          goto LABEL_55;
      }
      v33 = (Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *)&v7->DrawLayers.Data.Data;
      v34 = v33->Size;
      v35 = v34 + 1;
      if ( v34 + 1 >= v34 )
      {
        if ( v35 > v33->Policy.Capacity )
        {
          v36 = v35 + (v35 >> 2);
          goto LABEL_44;
        }
      }
      else if ( v35 < v33->Policy.Capacity >> 1 )
      {
        v36 = v34 + 1;
LABEL_44:
        Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v33,
          v33,
          v36);
        goto LABEL_45;
      }
LABEL_45:
      v33->Size = v35;
      v37 = v35;
      v38 = v33->Data;
      v38[v37 - 1].StartPos = v50;
      *((_DWORD *)&v38[v37] - 4) = 0;
      *((_DWORD *)&v38[v37] - 3) = 1;
      *((_DWORD *)&v38[v37] - 2) = v30;
      *((_DWORD *)&v38[v37] - 1) = 0;
      if ( v30 >= (unsigned int)v45 )
      {
        v39 = (unsigned int)(v45 + 31) >> 5;
        v40 = (v30 + 32) >> 5;
        if ( v40 < 2 * (signed int)v39 )
          v40 = 2 * v39;
        if ( v40 > (unsigned int)v39 )
        {
          v41 = v47->vfptr;
          if ( v46 == (__int64 *)((char *)&v45 + 4) )
          {
            v42 = (__int64 *)v41->Alloc(v47, 4i64 * v40, 0i64);
            v46 = v42;
            *(_DWORD *)v42 = HIDWORD(v45);
            v43 = v46;
          }
          else
          {
            v43 = (__int64 *)v41->Realloc(v47, v46, 4i64 * v40);
            v46 = v43;
          }
          memset((char *)v43 + 4 * v39, 0, 4i64 * (v40 - (unsigned int)v39));
          LODWORD(v45) = 32 * v40;
        }
      }
      *(_DWORD *)((char *)v46 + v32) &= ~v31;
      v7 = v48;
      v48->Strokes = 1;
      v11 = v46;
      v14 = (unsigned int)v45;
      v8 = v51;
      v6 = v49;
      goto LABEL_54;
    }
LABEL_55:
    if ( v46 != (__int64 *)((char *)&v45 + 4) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *, __int64 *, __int64, unsigned __int64))v47->vfptr->Free)(
        v47,
        v46,
        v14,
        v8);
  }
}

// File Line: 540
// RVA: 0x9C55B0
void __fastcall Scaleform::Render::ShapeMeshProvider::acquireShapeData(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::ShapeMeshProvider *v1; // rsi
  Scaleform::Render::MorphShapeData *v2; // rcx
  signed __int64 v3; // rcx
  __int64 *v4; // rdi
  char v5; // al
  volatile signed __int32 *v6; // rcx
  Scaleform::Render::ShapeDataInterface *v7; // rcx
  __int64 v8; // rdi
  char v9; // bl
  unsigned int v10; // er14
  unsigned int v11; // er15
  int i; // eax
  unsigned int j; // ebx
  unsigned __int64 v14; // r11
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // r9
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v17; // rcx
  __int64 v18; // r8
  __int64 v19; // rdx
  unsigned int v20; // eax
  unsigned __int64 v21; // r8
  unsigned __int64 v22; // rdi
  __int64 v23; // r14
  float *v24; // rax
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v28; // rdx
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v29; // rax
  unsigned __int64 v30; // r15
  __int64 v31; // r14
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v32; // rdi
  char v33; // [rsp+20h] [rbp-E0h]
  unsigned int v34; // [rsp+28h] [rbp-D8h]
  unsigned int v35; // [rsp+2Ch] [rbp-D4h]
  unsigned int v36; // [rsp+30h] [rbp-D0h]
  unsigned int v37; // [rsp+38h] [rbp-C8h]
  __int64 v38; // [rsp+3Ch] [rbp-C4h]
  __int64 v39; // [rsp+44h] [rbp-BCh]
  __int64 v40; // [rsp+4Ch] [rbp-B4h]
  __int64 v41; // [rsp+54h] [rbp-ACh]
  __int64 v42; // [rsp+5Ch] [rbp-A4h]
  int v43; // [rsp+64h] [rbp-9Ch]
  int v44; // [rsp+68h] [rbp-98h]
  char v45; // [rsp+6Ch] [rbp-94h]
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType val; // [rsp+70h] [rbp-90h]
  __int64 v47; // [rsp+88h] [rbp-78h]
  __int128 v48; // [rsp+90h] [rbp-70h]
  __m128 v49; // [rsp+A0h] [rbp-60h]
  char v50; // [rsp+B0h] [rbp-50h]
  char v51; // [rsp+C8h] [rbp-38h]
  char v52; // [rsp+E0h] [rbp-20h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> paths; // [rsp+F0h] [rbp-10h]
  int v54; // [rsp+450h] [rbp+350h]
  Scaleform::Render::ShapeDataInterface *v55; // [rsp+458h] [rbp+358h]
  __int64 v56; // [rsp+460h] [rbp+360h]

  v47 = -2i64;
  v1 = this;
  v2 = this->pMorphData.pObject;
  if ( v2 )
  {
    v3 = (signed __int64)&v2->ShapeData1;
    if ( v3 )
      _InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 8), 1u);
    v56 = v3;
    v4 = &v56;
    v5 = 1;
    v6 = (volatile signed __int32 *)v55;
  }
  else
  {
    v7 = v1->pShapeData.pObject;
    if ( v7 )
      _InterlockedExchangeAdd(&v7->RefCount, 1u);
    v6 = (volatile signed __int32 *)v1->pShapeData.pObject;
    v55 = v1->pShapeData.pObject;
    v4 = (__int64 *)&v55;
    v5 = 2;
  }
  v8 = *v4;
  if ( v5 & 2 )
  {
    v5 &= 0xFDu;
    v33 = v5;
    if ( v6 )
    {
      if ( !_InterlockedDecrement(v6 + 2) )
        v55->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v55->vfptr, 1u);
      v5 = v33;
    }
  }
  if ( v5 & 1 && v56 && !_InterlockedDecrement((volatile signed __int32 *)(v56 + 8)) )
    (**(void (__fastcall ***)(__int64, signed __int64))v56)(v56, 1i64);
  v37 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 48i64))(v8);
  v38 = 0i64;
  v39 = 0i64;
  v40 = 0i64;
  v41 = 0i64;
  v42 = 0i64;
  v43 = 0;
  v44 = (signed int)FLOAT_1_0;
  v45 = 0;
  v9 = 1;
  v10 = 0;
  paths.pHeap = Scaleform::Memory::pGlobalHeap;
  paths.Size = 0i64;
  paths.Reserved = 32i64;
  paths.Data = paths.Static;
  v1->Strokes = 0;
  v11 = v37;
  for ( i = (*(__int64 (__fastcall **)(__int64, unsigned int *, char *, unsigned int *))(*(_QWORD *)v8 + 64i64))(
              v8,
              &v37,
              &v50,
              &v34);
        i;
        i = (*(__int64 (__fastcall **)(__int64, unsigned int *, char *, unsigned int *))(*(_QWORD *)v8 + 64i64))(
              v8,
              &v37,
              &v50,
              &v34) )
  {
    if ( i == 2 && !v9 )
      ++v10;
    val.Pos = v11;
    val.ShapeLayer = v10;
    val.Styles[0] = v34;
    val.Styles[1] = v35;
    val.Styles[2] = v36;
    for ( j = 0;
          (*(unsigned int (__fastcall **)(__int64, unsigned int *, char *))(*(_QWORD *)v8 + 72i64))(v8, &v37, &v51);
          ++j )
    {
      ;
    }
    val.EdgeCount = j;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2>::PushBack(&paths, &val);
    v9 = 0;
    v11 = v37;
  }
  v14 = 0i64;
  v15 = 0i64;
  v16 = paths.Size;
  v17 = paths.Data;
  if ( paths.Size )
  {
    v18 = 0i64;
    v19 = 0i64;
    do
    {
      if ( v17[v19].EdgeCount && (v17[v19].Styles[0] || v17[v19].Styles[1] || v17[v19].Styles[2]) )
      {
        v17[v18].ShapeLayer = v17[v19].ShapeLayer;
        v17[v18].Pos = v17[v19].Pos;
        v17[v18].Styles[0] = v17[v19].Styles[0];
        v17[v18].Styles[1] = v17[v19].Styles[1];
        v17[v18].Styles[2] = v17[v19].Styles[2];
        v17[v18].EdgeCount = v17[v19].EdgeCount;
        ++v14;
        ++v18;
        v17 = paths.Data;
        v16 = paths.Size;
      }
      ++v15;
      ++v19;
    }
    while ( v15 < v16 );
    if ( v14 < v16 )
      v16 = v14;
    paths.Size = v16;
  }
  if ( v1->DrawLayers.Data.Size && v1->DrawLayers.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->DrawLayers.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->DrawLayers.Data.Data = 0i64;
      v17 = paths.Data;
      v16 = paths.Size;
    }
    v1->DrawLayers.Data.Policy.Capacity = 0i64;
  }
  v1->DrawLayers.Data.Size = 0i64;
  if ( v1->FillToStyleTable.Data.Size && v1->FillToStyleTable.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->FillToStyleTable.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->FillToStyleTable.Data.Data = 0i64;
      v17 = paths.Data;
      v16 = paths.Size;
    }
    v1->FillToStyleTable.Data.Policy.Capacity = 0i64;
  }
  v1->FillToStyleTable.Data.Size = 0i64;
  v20 = 0;
  v21 = 0i64;
  v22 = 0i64;
  if ( v16 )
  {
    v23 = 0i64;
    do
    {
      if ( v20 != v17[v23].ShapeLayer )
      {
        Scaleform::Render::ShapeMeshProvider::createDrawLayers(v1, &paths, v21, v22);
        v21 = v22;
        v17 = paths.Data;
        v20 = paths.Data[v23].ShapeLayer;
        v16 = paths.Size;
      }
      ++v22;
      ++v23;
    }
    while ( v22 < v16 );
  }
  Scaleform::Render::ShapeMeshProvider::createDrawLayers(v1, &paths, v21, v16);
  v48 = _xmm;
  v49 = _xmm;
  v24 = (float *)v1->vfptr->GetBounds(
                   (Scaleform::Render::MeshProvider *)&v1->vfptr,
                   (Scaleform::Render::Rect<float> *)&v52,
                   (Scaleform::Render::Matrix2x4<float> *)&v48);
  v25 = v24[3];
  v26 = v24[2];
  v27 = v24[1];
  v1->IdentityBounds.x1 = *v24;
  v1->IdentityBounds.y1 = v27;
  v1->IdentityBounds.x2 = v26;
  v1->IdentityBounds.y2 = v25;
  if ( Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(v1) )
  {
    if ( v1->DrawLayers.Data.Size <= 1 )
    {
      if ( v1->DrawLayers.Data.Policy.Capacity < 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *)&v1->DrawLayers.Data.Data,
          &v1->DrawLayers,
          1ui64);
    }
    else if ( (v1->DrawLayers.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 2 )
    {
      v28 = v1->DrawLayers.Data.Data;
      if ( v28 )
      {
        v29 = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       v28,
                                                                       80ui64);
      }
      else
      {
        v54 = 2;
        v29 = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       &v1->DrawLayers,
                                                                       80ui64,
                                                                       (Scaleform::AllocInfo *)&v54);
      }
      v1->DrawLayers.Data.Data = v29;
      v1->DrawLayers.Data.Policy.Capacity = 4i64;
    }
    v1->DrawLayers.Data.Size = 1i64;
    v1->DrawLayers.Data.Data->Image9GridType = 2;
  }
  else
  {
    v30 = 0i64;
    if ( v1->DrawLayers.Data.Size > 0 )
    {
      v31 = 0i64;
      do
      {
        v32 = &v1->DrawLayers.Data.Data[v31];
        if ( !v32->StrokeStyle
          && Scaleform::Render::ShapeMeshProvider::checkI9gLayer(v1, &v1->DrawLayers.Data.Data[v31]) )
        {
          v32->Image9GridType = 1;
        }
        ++v30;
        ++v31;
      }
      while ( v30 < v1->DrawLayers.Data.Size );
    }
  }
  if ( paths.Data != paths.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 635
// RVA: 0x9D5990
char __fastcall Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::ShapeMeshProvider *v1; // r14
  int v2; // esi
  __int64 v3; // rdi
  unsigned int v4; // ebp
  __int64 v5; // rax
  void (__fastcall ***v6)(_QWORD, signed __int64); // rcx
  char v8; // [rsp+28h] [rbp-30h]
  __int64 v9; // [rsp+30h] [rbp-28h]

  v1 = this;
  if ( !this->pMorphData.pObject )
  {
    v2 = 0;
    if ( this->DrawLayers.Data.Size == 9
      && ((unsigned int (__cdecl *)(Scaleform::Render::ShapeDataInterface *))this->pShapeData.pObject->vfptr[2].__vecDelDtor)(this->pShapeData.pObject) == 9
      && !((unsigned int (__cdecl *)(Scaleform::Render::ShapeDataInterface *))v1->pShapeData.pObject->vfptr[3].__vecDelDtor)(v1->pShapeData.pObject) )
    {
      v3 = 0i64;
      v4 = 0;
      while ( 1 )
      {
        v9 = 0i64;
        ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v1->pShapeData.pObject->vfptr[4].__vecDelDtor)(
          v1->pShapeData.pObject,
          ++v4,
          &v8);
        if ( !v9 )
          break;
        v5 = *(_QWORD *)(v9 + 16);
        if ( v5 && (!v3 || v3 == v5) )
          ++v2;
        v3 = *(_QWORD *)(v9 + 16);
        v6 = (void (__fastcall ***)(_QWORD, signed __int64))v9;
        if ( v9 && !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) )
        {
          if ( v6 )
            (**v6)(v6, 1i64);
        }
        if ( v4 >= 9 )
        {
          if ( v2 != 9 )
            return 0;
          return 1;
        }
      }
    }
  }
  return 0;
}

// File Line: 676
// RVA: 0x9D5810
char __fastcall Scaleform::Render::ShapeMeshProvider::checkI9gLayer(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  Scaleform::Render::ShapeMeshProvider *v2; // rdi
  __int64 v3; // rdx
  __int64 v4; // rbx
  void (__fastcall ***v5)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v7)(_QWORD, signed __int64); // rcx
  unsigned int v8; // [rsp+18h] [rbp-29h]
  unsigned int v9; // [rsp+1Ch] [rbp-25h]
  int v10; // [rsp+20h] [rbp-21h]
  char v11; // [rsp+28h] [rbp-19h]
  __int64 v12; // [rsp+30h] [rbp-11h]
  unsigned int v13; // [rsp+38h] [rbp-9h]
  __int64 v14; // [rsp+3Ch] [rbp-5h]
  __int64 v15; // [rsp+44h] [rbp+3h]
  __int64 v16; // [rsp+4Ch] [rbp+Bh]
  __int64 v17; // [rsp+54h] [rbp+13h]
  __int64 v18; // [rsp+5Ch] [rbp+1Bh]
  int v19; // [rsp+64h] [rbp+23h]
  int v20; // [rsp+68h] [rbp+27h]
  char v21; // [rsp+6Ch] [rbp+2Bh]
  __int64 v22; // [rsp+70h] [rbp+2Fh]
  char v23; // [rsp+78h] [rbp+37h]

  v22 = -2i64;
  v2 = this;
  if ( this->pMorphData.pObject )
    return 0;
  v13 = dl->StartPos;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 0i64;
  v19 = 0;
  v20 = (signed int)FLOAT_1_0;
  v21 = 0;
  if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, char *, unsigned int *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
         this->pShapeData.pObject,
         &v13,
         &v23,
         &v8)
     - 1 > 1 )
    return 0;
  v3 = v9;
  if ( (v8 == 0) == (v9 == 0) || v10 )
    return 0;
  if ( v8 )
    v3 = v8;
  v12 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *))v2->pShapeData.pObject->vfptr[4].__vecDelDtor)(
    v2->pShapeData.pObject,
    v3,
    &v11);
  v4 = v12;
  if ( !v12
    || !*(_QWORD *)(v12 + 16)
    || Scaleform::Render::Matrix2x4<float>::IsFreeRotation((Scaleform::Render::Matrix2x4<float> *)(v12 + 32), 0.000001)
    || !(*(_BYTE *)(v4 + 64) & 1)
    || (v2->pShapeData.pObject->vfptr[10].__vecDelDtor(
          (Scaleform::RefCountImplCore *)&v2->pShapeData.pObject->vfptr,
          (unsigned int)&v13),
        ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, unsigned int *, char *, unsigned int *))v2->pShapeData.pObject->vfptr[8].__vecDelDtor)(
          v2->pShapeData.pObject,
          &v13,
          &v23,
          &v8) & 0xFFFFFFFD) )
  {
    v7 = (void (__fastcall ***)(_QWORD, signed __int64))v12;
    if ( v12 && !_InterlockedDecrement((volatile signed __int32 *)(v12 + 8)) && v7 )
      (**v7)(v7, 1i64);
    return 0;
  }
  v5 = (void (__fastcall ***)(_QWORD, signed __int64))v12;
  if ( v12 && !_InterlockedDecrement((volatile signed __int32 *)(v12 + 8)) )
  {
    if ( v5 )
      (**v5)(v5, 1i64);
  }
  return 1;
}

// File Line: 734
// RVA: 0x984010
void __fastcall Scaleform::Render::ShapeMeshProvider::GetFillStyle(Scaleform::Render::ShapeMeshProvider *this, unsigned int idx, Scaleform::Render::FillStyleType *f1, float morphRatio)
{
  Scaleform::Render::FillStyleType *v4; // rdi
  unsigned int v5; // esi
  Scaleform::Render::ShapeMeshProvider *v6; // rbx
  unsigned int v7; // ST20_4
  float v8; // xmm0_4
  void (__fastcall ***v9)(_QWORD, signed __int64); // rcx
  unsigned __int8 v10; // [rsp+30h] [rbp-28h]
  unsigned __int8 v11; // [rsp+31h] [rbp-27h]
  unsigned __int8 v12; // [rsp+32h] [rbp-26h]
  unsigned __int8 v13; // [rsp+33h] [rbp-25h]
  __int64 v14; // [rsp+38h] [rbp-20h]
  unsigned int v15; // [rsp+60h] [rbp+8h]

  v4 = f1;
  v5 = idx;
  v6 = this;
  ((void (*)(void))this->pShapeData.pObject->vfptr[4].__vecDelDtor)();
  if ( v6->pMorphData.pObject && morphRatio != 0.0 )
  {
    v14 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, unsigned __int8 *))v6->pMorphData.pObject->pMorphTo.pObject->vfptr[4].__vecDelDtor)(
      v6->pMorphData.pObject->pMorphTo.pObject,
      v5,
      &v10);
    if ( !v4->pFill.pObject )
    {
      v7 = v4->Color;
      v8 = (float)(unsigned __int8)(v4->Color >> 16);
      BYTE2(v15) = (signed int)(float)((float)((float)((float)((float)v12 - v8) * morphRatio) + v8) + 0.5);
      BYTE1(v15) = (signed int)(float)((float)((float)((float)((float)v11 - (float)BYTE1(v7)) * morphRatio)
                                             + (float)BYTE1(v7))
                                     + 0.5);
      LOBYTE(v15) = (signed int)(float)((float)((float)((float)((float)v10 - (float)(unsigned __int8)v4->Color)
                                                      * morphRatio)
                                              + (float)(unsigned __int8)v4->Color)
                                      + 0.5);
      HIBYTE(v15) = (signed int)(float)((float)((float)((float)((float)v13 - (float)(v4->Color >> 24)) * morphRatio)
                                              + (float)(v4->Color >> 24))
                                      + 0.5);
      v4->Color = v15;
    }
    v9 = (void (__fastcall ***)(_QWORD, signed __int64))v14;
    if ( v14 && !_InterlockedDecrement((volatile signed __int32 *)(v14 + 8)) )
    {
      if ( v9 )
        (**v9)(v9, 1i64);
    }
  }
}

// File Line: 752
// RVA: 0x98C3F0
void __fastcall Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(Scaleform::Render::ShapeMeshProvider *this, unsigned int idx, Scaleform::Render::StrokeStyleType *s1, float morphRatio)
{
  Scaleform::Render::StrokeStyleType *v4; // rbx
  unsigned int v5; // esi
  Scaleform::Render::ShapeMeshProvider *v6; // rdi
  unsigned int v7; // ST20_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  void (__fastcall ***v11)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v12)(_QWORD, signed __int64); // rcx
  float v13; // [rsp+30h] [rbp-48h]
  unsigned __int8 v14; // [rsp+40h] [rbp-38h]
  unsigned __int8 v15; // [rsp+41h] [rbp-37h]
  unsigned __int8 v16; // [rsp+42h] [rbp-36h]
  unsigned __int8 v17; // [rsp+43h] [rbp-35h]
  __int64 v18; // [rsp+48h] [rbp-30h]
  __int64 v19; // [rsp+50h] [rbp-28h]
  unsigned int v20; // [rsp+80h] [rbp+8h]

  v4 = s1;
  v5 = idx;
  v6 = this;
  ((void (*)(void))this->pShapeData.pObject->vfptr[5].__vecDelDtor)();
  if ( v6->pMorphData.pObject && morphRatio != 0.0 )
  {
    v18 = 0i64;
    v19 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, float *))v6->pMorphData.pObject->pMorphTo.pObject->vfptr[5].__vecDelDtor)(
      v6->pMorphData.pObject->pMorphTo.pObject,
      v5,
      &v13);
    v4->Width = (float)((float)(v13 - v4->Width) * morphRatio) + v4->Width;
    if ( !v4->pFill.pObject )
    {
      v7 = v4->Color;
      v8 = (float)(unsigned __int8)(v4->Color >> 16);
      BYTE2(v20) = (signed int)(float)((float)((float)((float)((float)v16 - v8) * morphRatio) + v8) + 0.5);
      BYTE1(v20) = (signed int)(float)((float)((float)((float)((float)v15 - (float)BYTE1(v7)) * morphRatio)
                                             + (float)BYTE1(v7))
                                     + 0.5);
      v9 = (float)(unsigned __int8)v4->Color;
      LOBYTE(v20) = (signed int)(float)((float)((float)((float)((float)v14 - v9) * morphRatio) + v9) + 0.5);
      v10 = (float)(v4->Color >> 24);
      HIBYTE(v20) = (signed int)(float)((float)((float)((float)((float)v17 - v10) * morphRatio) + v10) + 0.5);
      v4->Color = v20;
    }
    v11 = (void (__fastcall ***)(_QWORD, signed __int64))v19;
    if ( v19 && !_InterlockedDecrement((volatile signed __int32 *)(v19 + 8)) && v11 )
      (**v11)(v11, 1i64);
    v12 = (void (__fastcall ***)(_QWORD, signed __int64))v18;
    if ( v18 && !_InterlockedDecrement((volatile signed __int32 *)(v18 + 8)) )
    {
      if ( v12 )
        (**v12)(v12, 1i64);
    }
  }
}

// File Line: 774
// RVA: 0x9C6E80
void __fastcall Scaleform::Render::ShapeMeshProvider::addFill(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::MeshGenerator *gen, Scaleform::Render::ToleranceParams *param, Scaleform::Render::TransformerBase *tr)
{
  Scaleform::Render::TransformerBase *v4; // rsi
  Scaleform::Render::ToleranceParams *v5; // r12
  Scaleform::Render::MeshGenerator *v6; // r14
  Scaleform::Render::ShapeMeshProvider *v7; // r15
  char v8; // r13
  int v9; // edi
  Scaleform::Render::TessBase *v10; // r14
  int v11; // edi
  Scaleform::Render::ShapeDataInterface *v12; // rcx
  unsigned int v13; // edx
  bool v14; // r15
  void (__fastcall ***v15)(_QWORD, signed __int64); // rcx
  Scaleform::Render::ShapeDataInterface *v16; // rcx
  float v17; // er10
  bool v18; // di
  void (__fastcall ***v19)(_QWORD, signed __int64); // rcx
  Scaleform::Render::MorphShapeData *v20; // rcx
  Scaleform::Render::ShapeDataInterface *v21; // rcx
  Scaleform::Render::ShapePosInfo *pos2; // [rsp+20h] [rbp-A8h]
  float x2; // [rsp+40h] [rbp-88h]
  float y2; // [rsp+44h] [rbp-84h]
  float x3; // [rsp+48h] [rbp-80h]
  float y3[2]; // [rsp+4Ch] [rbp-7Ch]
  float y4[2]; // [rsp+54h] [rbp-74h]
  unsigned int v28; // [rsp+5Ch] [rbp-6Ch]
  int v29; // [rsp+60h] [rbp-68h]
  char v30; // [rsp+64h] [rbp-64h]
  float v31; // [rsp+68h] [rbp-60h]
  __int64 v32; // [rsp+6Ch] [rbp-5Ch]
  __int64 v33; // [rsp+74h] [rbp-54h]
  Scaleform::Render::ShapePosInfo v34; // [rsp+7Ch] [rbp-4Ch]
  char v35; // [rsp+B4h] [rbp-14h]
  char v36; // [rsp+B8h] [rbp-10h]
  __int64 v37; // [rsp+C0h] [rbp-8h]
  char v38; // [rsp+C8h] [rbp+0h]
  __int64 v39; // [rsp+D0h] [rbp+8h]
  __int64 v40; // [rsp+D8h] [rbp+10h]
  float v41; // [rsp+E0h] [rbp+18h]
  float v42; // [rsp+E4h] [rbp+1Ch]
  Scaleform::Render::MorphInterpolator v43; // [rsp+F8h] [rbp+30h]
  char v44; // [rsp+198h] [rbp+D0h]
  Scaleform::Render::ShapeMeshProvider *v45; // [rsp+1E8h] [rbp+120h]
  Scaleform::Render::MeshGenerator *v46; // [rsp+1F0h] [rbp+128h]
  float v47; // [rsp+208h] [rbp+140h]
  float ratio; // [rsp+210h] [rbp+148h]

  v40 = -2i64;
  v4 = tr;
  v5 = param;
  v6 = gen;
  v7 = this;
  v31 = v47;
  v32 = 0i64;
  v33 = 0i64;
  *(_QWORD *)&v34.Pos = 0i64;
  *(_QWORD *)y3 = 0i64;
  *(_QWORD *)y4 = 0i64;
  v28 = 0;
  v29 = 1065353216;
  v30 = 0;
  *(float *)&v34.StartX = v47;
  *(_QWORD *)&v34.StartY = 0i64;
  *(_QWORD *)&v34.LastY = 0i64;
  *(_QWORD *)&v34.StrokeBase = 0i64;
  *(_QWORD *)&v34.NumStrokeBits = 0i64;
  *(_QWORD *)&v34.Fill1 = 0i64;
  v34.Sfactor = 0.0;
  *(_DWORD *)&v34.Initialized = 1065353216;
  v35 = 0;
  v8 = 1;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v43,
    this->pShapeData.pObject,
    this->pMorphData.pObject,
    ratio,
    (Scaleform::Render::ShapePosInfo *)((char *)&v34 + 4));
  while ( 1 )
  {
    if ( v43.pMorphData.pObject )
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, float *, float *, float *))v43.pMorphData.pObject->ShapeData1.vfptr[8].__vecDelDtor)(
             &v43.pMorphData.pObject->ShapeData1,
             &v31,
             &x2,
             &y4[1]);
      ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *, char *))v43.pMorphData.pObject->ShapeData2.vfptr[8].__vecDelDtor)(
        &v43.pMorphData.pObject->ShapeData2,
        &v43.Pos2,
        &v41,
        &v44);
      if ( !v9 )
        break;
      x2 = x2 + (float)((float)(v41 - x2) * v43.MorphRatio);
      y2 = y2 + (float)((float)(v42 - y2) * v43.MorphRatio);
    }
    else
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *, float *))v43.pShapeData.pObject->vfptr[8].__vecDelDtor)(
             v43.pShapeData.pObject,
             &v31,
             &x2,
             &y4[1]);
    }
    if ( !v9 || !v8 && v9 == 2 )
      break;
    v8 = 0;
    if ( LODWORD(y4[1]) == v28 )
    {
      if ( v43.pMorphData.pObject )
      {
        v43.pMorphData.pObject->ShapeData1.vfptr[10].__vecDelDtor(
          (Scaleform::RefCountImplCore *)&v43.pMorphData.pObject->ShapeData1,
          (unsigned int)&v31);
        v43.pMorphData.pObject->ShapeData2.vfptr[10].__vecDelDtor(
          (Scaleform::RefCountImplCore *)&v43.pMorphData.pObject->ShapeData2,
          (unsigned int)&v43.Pos2);
      }
      else
      {
        v43.pShapeData.pObject->vfptr[10].__vecDelDtor(
          (Scaleform::RefCountImplCore *)v43.pShapeData.pObject,
          (unsigned int)&v31);
      }
    }
    else
    {
      v4->vfptr->Transform(v4, &x2, &y2);
      v10 = (Scaleform::Render::TessBase *)&v6->mTess.vfptr;
LABEL_11:
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v10->vfptr->AddVertex)(v10);
      while ( 1 )
      {
        if ( v43.pMorphData.pObject )
        {
          v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, float *, float *))v43.pMorphData.pObject->ShapeData1.vfptr[9].__vecDelDtor)(
                  &v43.pMorphData.pObject->ShapeData1,
                  &v31,
                  &x2);
          ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *))v43.pMorphData.pObject->ShapeData2.vfptr[9].__vecDelDtor)(
            &v43.pMorphData.pObject->ShapeData2,
            &v43.Pos2,
            &v31);
          if ( !v11 )
            break;
          x2 = x2 + (float)((float)(v31 - x2) * v43.MorphRatio);
          y2 = y2 + (float)((float)(*(float *)&v32 - y2) * v43.MorphRatio);
          if ( (unsigned int)(v11 - 2) <= 1 )
          {
            x3 = x3 + (float)((float)(*((float *)&v32 + 1) - x3) * v43.MorphRatio);
            y3[0] = y3[0] + (float)((float)(*(float *)&v33 - y3[0]) * v43.MorphRatio);
            if ( v11 == 3 )
            {
              y3[1] = y3[1] + (float)((float)(*((float *)&v33 + 1) - y3[1]) * v43.MorphRatio);
              y4[0] = y4[0] + (float)((float)(*(float *)&v34.Pos - y4[0]) * v43.MorphRatio);
            }
          }
        }
        else
        {
          v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, float *, float *))v43.pShapeData.pObject->vfptr[9].__vecDelDtor)(
                  v43.pShapeData.pObject,
                  &v31,
                  &x2);
        }
        if ( !v11 )
          break;
        switch ( v11 )
        {
          case 1:
            v4->vfptr->Transform(v4, &x2, &y2);
            goto LABEL_11;
          case 2:
            v4->vfptr->Transform(v4, &x2, &y2);
            v4->vfptr->Transform(v4, &x3, y3);
            Scaleform::Render::TessellateQuadCurve(v10, v5, x2, y2, y3[0], x3, y3[0]);
            break;
          case 3:
            v4->vfptr->Transform(v4, &x2, &y2);
            v4->vfptr->Transform(v4, &x3, y3);
            v4->vfptr->Transform(v4, &y3[1], y4);
            Scaleform::Render::TessellateCubicCurve(v10, v5, x2, y2, y3[0], x3, y3[0], y3[1], y4[0]);
            break;
        }
      }
      v12 = v7->pShapeData.pObject;
      v13 = v28;
      if ( v28 )
      {
        v39 = 0i64;
        ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v12->vfptr[4].__vecDelDtor)(
          v12,
          v28,
          &v38);
        v14 = v39 != 0;
        v15 = (void (__fastcall ***)(_QWORD, signed __int64))v39;
        if ( v39 && !_InterlockedDecrement((volatile signed __int32 *)(v39 + 8)) && v15 )
          (**v15)(v15, 1i64);
        v13 = v28;
      }
      else
      {
        v14 = 0;
      }
      v16 = v45->pShapeData.pObject;
      v17 = y4[1];
      if ( LODWORD(y4[1]) )
      {
        v37 = 0i64;
        ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))v16->vfptr[4].__vecDelDtor)(
          v16,
          LODWORD(y4[1]),
          &v36);
        v18 = v37 != 0;
        v19 = (void (__fastcall ***)(_QWORD, signed __int64))v37;
        if ( v37 && !_InterlockedDecrement((volatile signed __int32 *)(v37 + 8)) && v19 )
          (**v19)(v19, 1i64);
        v13 = v28;
        v17 = y4[1];
      }
      else
      {
        v18 = 0;
      }
      LOBYTE(pos2) = v14;
      v10->vfptr->FinalizePath(v10, LODWORD(v17), v13, v18, (bool)pos2);
      v7 = v45;
      v6 = v46;
    }
  }
  v20 = v43.pMorphData.pObject;
  if ( v43.pMorphData.pObject && !_InterlockedDecrement(&v43.pMorphData.pObject->RefCount) && v20 )
    v20->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v20->vfptr, 1u);
  v21 = v43.pShapeData.pObject;
  if ( v43.pShapeData.pObject && !_InterlockedDecrement(&v43.pShapeData.pObject->RefCount) && v21 )
    v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
}

// File Line: 864
// RVA: 0x9CA960
void __usercall Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(Scaleform::Render::ShapeMeshProvider *this@<rcx>, Scaleform::Render::MeshGenerator *gen@<rdx>, Scaleform::Render::ToleranceParams *param@<r8>, Scaleform::Render::TransformerBase *tr@<r9>, float a5@<xmm0>)
{
  Scaleform::Render::TransformerBase *v5; // r15
  Scaleform::Render::MeshGenerator *v6; // r13
  Scaleform::Render::ShapeMeshProvider *v7; // rbx
  unsigned __int64 v8; // rsi
  float v9; // xmm6_4
  char v10; // r14
  int v11; // ebx
  float v12; // xmm3_4
  float v13; // xmm2_4
  unsigned int v14; // er9
  float v15; // xmm1_4
  int v16; // ebx
  float v17; // xmm9_4
  float v18; // xmm8_4
  float v19; // xmm1_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  Scaleform::Render::DashArray *v22; // rdi
  signed __int64 v23; // rdx
  Scaleform::Render::MorphShapeData *v24; // rcx
  Scaleform::Render::ShapeDataInterface *v25; // rcx
  Scaleform::Render::DashArray *v26; // rcx
  Scaleform::Render::ComplexFill *v27; // rcx
  Scaleform::Render::ShapePosInfo *pos2; // [rsp+20h] [rbp-B8h]
  float v29; // [rsp+30h] [rbp-A8h]
  float y; // [rsp+34h] [rbp-A4h]
  float v31; // [rsp+38h] [rbp-A0h]
  float v32; // [rsp+3Ch] [rbp-9Ch]
  float v33; // [rsp+40h] [rbp-98h]
  float v34; // [rsp+44h] [rbp-94h]
  int v35; // [rsp+48h] [rbp-90h]
  __int64 v36; // [rsp+4Ch] [rbp-8Ch]
  __int64 v37; // [rsp+54h] [rbp-84h]
  __int64 v38; // [rsp+5Ch] [rbp-7Ch]
  __int64 v39; // [rsp+64h] [rbp-74h]
  Scaleform::Render::ShapePosInfo v40; // [rsp+6Ch] [rbp-6Ch]
  char v41; // [rsp+A4h] [rbp-34h]
  char v42; // [rsp+A8h] [rbp-30h]
  int v43; // [rsp+B0h] [rbp-28h]
  Scaleform::Render::StrokeStyleType s1; // [rsp+B8h] [rbp-20h]
  __int64 v45; // [rsp+E0h] [rbp+8h]
  float v46; // [rsp+E8h] [rbp+10h]
  float v47; // [rsp+ECh] [rbp+14h]
  Scaleform::Render::MorphInterpolator v48; // [rsp+108h] [rbp+30h]
  char v49; // [rsp+1A8h] [rbp+D0h]
  Scaleform::Render::ToleranceParams *parama; // [rsp+238h] [rbp+160h]
  void *retaddr; // [rsp+248h] [rbp+170h]
  unsigned int idx; // [rsp+250h] [rbp+178h]
  float offsetY; // [rsp+258h] [rbp+180h]

  v45 = -2i64;
  v5 = tr;
  v6 = gen;
  v7 = this;
  v35 = (signed int)retaddr;
  v8 = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  v38 = 0i64;
  v39 = 0i64;
  *(_QWORD *)&v40.Pos = 0i64;
  v40.StartX = (signed int)retaddr;
  *(_QWORD *)&v40.StartY = 0i64;
  *(_QWORD *)&v40.LastY = 0i64;
  *(_QWORD *)&v40.StrokeBase = 0i64;
  *(_QWORD *)&v40.NumStrokeBits = 0i64;
  *(_QWORD *)&v40.Fill1 = 0i64;
  v40.Sfactor = 0.0;
  *(_DWORD *)&v40.Initialized = 1065353216;
  v41 = 0;
  s1.pFill.pObject = 0i64;
  s1.pDashes.pObject = 0i64;
  v9 = *(float *)&param;
  Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(this, idx, &s1, *(float *)&param);
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v48,
    v7->pShapeData.pObject,
    v7->pMorphData.pObject,
    v9,
    (Scaleform::Render::ShapePosInfo *)((char *)&v40 + 4));
  v10 = 1;
  while ( 1 )
  {
LABEL_2:
    if ( !v48.pMorphData.pObject )
    {
      v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, char *))v48.pShapeData.pObject->vfptr[8].__vecDelDtor)(
              v48.pShapeData.pObject,
              &v35,
              &v29,
              &v42);
LABEL_6:
      v12 = v29;
      v13 = y;
      goto LABEL_7;
    }
    v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, int *, float *, char *))v48.pMorphData.pObject->ShapeData1.vfptr[8].__vecDelDtor)(
            &v48.pMorphData.pObject->ShapeData1,
            &v35,
            &v29,
            &v42);
    ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, float *, char *))v48.pMorphData.pObject->ShapeData2.vfptr[8].__vecDelDtor)(
      &v48.pMorphData.pObject->ShapeData2,
      &v48.Pos2,
      &v46,
      &v49);
    if ( !v11 )
      goto LABEL_6;
    v12 = v29 + (float)((float)(v46 - v29) * v48.MorphRatio);
    v29 = v29 + (float)((float)(v46 - v29) * v48.MorphRatio);
    a5 = (float)(v47 - y) * v48.MorphRatio;
    v13 = y + a5;
    y = y + a5;
LABEL_7:
    if ( !v11 || !v10 && v11 == 2 )
      break;
    v10 = 0;
    if ( v43 == idx )
    {
LABEL_11:
      v14 = 1;
      v15 = v12;
LABEL_12:
      Scaleform::Render::StrokeSorter::AddVertexNV(&v6->mStrokeSorter, v15, v13, v14);
      while ( v48.pMorphData.pObject )
      {
        v16 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, int *, float *))v48.pMorphData.pObject->ShapeData1.vfptr[9].__vecDelDtor)(
                &v48.pMorphData.pObject->ShapeData1,
                &v35,
                &v29);
        ((void (__fastcall *)(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::Render::ShapePosInfo *, char *))v48.pMorphData.pObject->ShapeData2.vfptr[9].__vecDelDtor)(
          &v48.pMorphData.pObject->ShapeData2,
          &v48.Pos2,
          (char *)&v37 + 4);
        if ( !v16 )
          goto LABEL_19;
        v12 = v29 + (float)((float)(*((float *)&v37 + 1) - v29) * v48.MorphRatio);
        v29 = v29 + (float)((float)(*((float *)&v37 + 1) - v29) * v48.MorphRatio);
        a5 = (float)(*(float *)&v38 - y) * v48.MorphRatio;
        v13 = y + a5;
        y = y + a5;
        v17 = v31;
        v18 = v32;
        if ( (unsigned int)(v16 - 2) <= 1 )
        {
          a5 = (float)(*((float *)&v38 + 1) - v31) * v48.MorphRatio;
          v17 = v31 + a5;
          v31 = v31 + a5;
          v18 = v32 + (float)((float)(*(float *)&v39 - v32) * v48.MorphRatio);
          v32 = v32 + (float)((float)(*(float *)&v39 - v32) * v48.MorphRatio);
          if ( v16 == 3 )
          {
            v33 = v33 + (float)((float)(*((float *)&v39 + 1) - v33) * v48.MorphRatio);
            v19 = (float)(*(float *)&v40.Pos - v34) * v48.MorphRatio;
            a5 = v34 + v19;
            v34 = v34 + v19;
          }
        }
LABEL_20:
        switch ( v16 )
        {
          case 0:
            LOBYTE(pos2) = 0;
            v6->mStrokeSorter.vfptr->FinalizePath(
              (Scaleform::Render::TessBase *)&v6->mStrokeSorter.vfptr,
              0,
              0,
              0,
              (bool)pos2);
            goto LABEL_2;
          case 1:
            goto LABEL_11;
          case 2:
            Scaleform::Render::StrokeSorter::AddVertexNV(&v6->mStrokeSorter, v12, v13, 2u);
            v14 = 2;
            v13 = v18;
            v15 = v17;
            goto LABEL_12;
          case 3:
            v20 = v34;
            v21 = v33;
            Scaleform::Render::StrokeSorter::AddVertexNV(&v6->mStrokeSorter, v12, v13, 3u);
            Scaleform::Render::StrokeSorter::AddVertexNV(&v6->mStrokeSorter, v17, v18, 3u);
            v14 = 3;
            v13 = v20;
            v15 = v21;
            goto LABEL_12;
        }
      }
      v16 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v48.pShapeData.pObject->vfptr[9].__vecDelDtor)(
              v48.pShapeData.pObject,
              &v35,
              &v29);
LABEL_19:
      v12 = v29;
      v13 = y;
      v17 = v31;
      v18 = v32;
      goto LABEL_20;
    }
    if ( v48.pMorphData.pObject )
    {
      v48.pMorphData.pObject->ShapeData1.vfptr[10].__vecDelDtor(
        (Scaleform::RefCountImplCore *)&v48.pMorphData.pObject->ShapeData1,
        (unsigned int)&v35);
      v48.pMorphData.pObject->ShapeData2.vfptr[10].__vecDelDtor(
        (Scaleform::RefCountImplCore *)&v48.pMorphData.pObject->ShapeData2,
        (unsigned int)&v48.Pos2);
    }
    else
    {
      v48.pShapeData.pObject->vfptr[10].__vecDelDtor(
        (Scaleform::RefCountImplCore *)v48.pShapeData.pObject,
        (unsigned int)&v35);
    }
  }
  Scaleform::Render::StrokeSorter::Sort(&v6->mStrokeSorter);
  v22 = s1.pDashes.pObject;
  if ( s1.pDashes.pObject )
  {
    v5->vfptr->GetScale(v5);
    Scaleform::Render::StrokeSorter::GenerateDashes(&v6->mStrokeSorter, v22, parama, a5);
    v22 = s1.pDashes.pObject;
  }
  if ( v6->mStrokeSorter.OutVertices.Size )
  {
    do
    {
      v23 = (signed __int64)&v6->mStrokeSorter.OutVertices.Pages[v8 >> 4][v8 & 0xF];
      v5->vfptr->Transform(v5, (float *)v23, (float *)(v23 + 4));
      ++v8;
    }
    while ( v8 < v6->mStrokeSorter.OutVertices.Size );
    v22 = s1.pDashes.pObject;
  }
  if ( s1.Flags & 1 )
  {
    if ( !v22 )
      Scaleform::Render::StrokeSorter::Snap(&v6->mStrokeSorter, offsetY, offsetY);
  }
  else if ( offsetY > 0.0 )
  {
    Scaleform::Render::StrokeSorter::AddOffset(&v6->mStrokeSorter, offsetY, offsetY);
  }
  v24 = v48.pMorphData.pObject;
  if ( v48.pMorphData.pObject && !_InterlockedDecrement(&v48.pMorphData.pObject->RefCount) && v24 )
    v24->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, 1u);
  v25 = v48.pShapeData.pObject;
  if ( v48.pShapeData.pObject && !_InterlockedDecrement(&v48.pShapeData.pObject->RefCount) && v25 )
    v25->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, 1u);
  v48.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v26 = s1.pDashes.pObject;
  if ( s1.pDashes.pObject && !_InterlockedDecrement(&s1.pDashes.pObject->RefCount) && v26 )
    v26->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, 1u);
  v27 = s1.pFill.pObject;
  if ( s1.pFill.pObject && !_InterlockedDecrement(&s1.pFill.pObject->RefCount) && v27 )
    v27->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, 1u);
}

// File Line: 943
// RVA: 0x9C99E0
void __fastcall Scaleform::Render::ShapeMeshProvider::addStroke(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::MeshGenerator *gen, Scaleform::Render::TessBase *stroker, Scaleform::Render::ToleranceParams *param, Scaleform::Render::TransformerBase *tr, unsigned int startPos, unsigned int strokeStyleIdx, float snapOffset, float morphRatio)
{
  Scaleform::Render::ToleranceParams *v9; // r13
  Scaleform::Render::TessBase *v10; // rsi
  Scaleform::Render::MeshGenerator *v11; // rbp
  unsigned int v12; // er12
  unsigned __int64 v13; // r15
  __int64 v14; // rdi
  unsigned int v15; // ebx
  unsigned int v16; // er14
  int v17; // ecx
  Scaleform::Render::StrokeSorter::PathType *v18; // r8
  unsigned int v19; // eax
  Scaleform::Render::StrokeSorter::VertexType **v20; // r10
  float *v21; // rdx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ebx
  char v26; // r9
  unsigned __int64 v27; // rax
  int v28; // ecx
  float *v29; // r9
  unsigned int v30; // eax
  float *v31; // rcx
  int v32; // ecx
  unsigned int v33; // eax
  float *v34; // rcx
  __int128 v35; // xmm2
  __int128 v36; // xmm1
  _BOOL8 x3; // [rsp+20h] [rbp-48h]

  v9 = param;
  v10 = stroker;
  v11 = gen;
  Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
    this,
    gen,
    param,
    tr,
    startPos,
    strokeStyleIdx,
    snapOffset,
    morphRatio);
  (*((void (__fastcall **)(Scaleform::Render::TessBase *))&v10->vfptr->__vecDelDtor + 1))(v10);
  v12 = 0;
  if ( LODWORD(v11->mStrokeSorter.OutPaths.Size) )
  {
    do
    {
      v13 = (unsigned __int64)v12 >> 4;
      v14 = v12 & 0xF;
      v15 = 0;
      v16 = v11->mStrokeSorter.OutPaths.Pages[v13][v14].numVer & 0xFFFFFFF;
      if ( v16 )
      {
        do
        {
          v17 = v15;
          v18 = v11->mStrokeSorter.OutPaths.Pages[v13];
          v19 = v18[v14].numVer & 0xFFFFFFF;
          if ( v15 >= v19 )
            v17 = v15 - v19;
          v20 = v11->mStrokeSorter.OutVertices.Pages;
          ++v15;
          v21 = &v20[(unsigned __int64)(v17 + v18[v14].start) >> 4][((_BYTE)v17 + LOBYTE(v18[v14].start)) & 0xF].x;
          switch ( *((_BYTE *)v21 + 12) )
          {
            case 1:
              v35 = *((unsigned int *)v21 + 1);
              v36 = *(unsigned int *)v21;
              ((void (__fastcall *)(Scaleform::Render::TessBase *))v10->vfptr->AddVertex)(v10);
              break;
            case 2:
              v32 = v15;
              v33 = v18[v14].numVer & 0xFFFFFFF;
              if ( v15 >= v33 )
                v32 = v15 - v33;
              ++v15;
              v34 = &v20[(unsigned __int64)(v32 + v18[v14].start) >> 4][((_BYTE)v32 + LOBYTE(v18[v14].start)) & 0xF].x;
              Scaleform::Render::TessellateQuadCurve(v10, v9, *v21, v21[1], v34[1], *v34, v34[1]);
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
              v29 = &v20[v27 >> 4][v26 & 0xF].x;
              v30 = v18[v14].numVer & 0xFFFFFFF;
              if ( v25 >= v30 )
                v28 = v25 - v30;
              v15 = v25 + 1;
              v31 = &v20[(unsigned __int64)(v28 + v18[v14].start) >> 4][((_BYTE)v28 + LOBYTE(v18[v14].start)) & 0xF].x;
              Scaleform::Render::TessellateCubicCurve(v10, v9, *v21, v21[1], v29[1], *v29, v29[1], *v31, v31[1]);
              break;
          }
        }
        while ( v15 < v16 );
      }
      LOBYTE(x3) = 0;
      v10->vfptr->FinalizePath(v10, 0, 0, 0, x3);
      ++v12;
    }
    while ( v12 < LODWORD(v11->mStrokeSorter.OutPaths.Size) );
  }
}

// File Line: 988
// RVA: 0x9C9780
void __fastcall Scaleform::Render::ShapeMeshProvider::addStroke(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::MeshGenerator *gen, Scaleform::Render::ToleranceParams *param, Scaleform::Render::TransformerBase *tr, unsigned int startPos, unsigned int strokeStyleIdx, float snapOffset, float morphRatio)
{
  Scaleform::Render::ToleranceParams *v8; // r13
  Scaleform::Render::MeshGenerator *v9; // rbp
  unsigned int v10; // er12
  unsigned __int64 v11; // r15
  __int64 v12; // rdi
  unsigned int v13; // ebx
  unsigned int v14; // er14
  int v15; // ecx
  Scaleform::Render::StrokeSorter::PathType *v16; // r8
  unsigned int v17; // eax
  Scaleform::Render::StrokeSorter::VertexType **v18; // r10
  float *v19; // rdx
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ebx
  char v24; // r9
  unsigned __int64 v25; // rax
  int v26; // ecx
  float *v27; // r9
  unsigned int v28; // eax
  float *v29; // rcx
  int v30; // ecx
  unsigned int v31; // eax
  float *v32; // rcx
  __int128 v33; // xmm2
  __int128 v34; // xmm1

  v8 = param;
  v9 = gen;
  Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
    this,
    gen,
    param,
    tr,
    startPos,
    strokeStyleIdx,
    snapOffset,
    morphRatio);
  (*((void (__fastcall **)(Scaleform::Render::Stroker *))&v9->mStroker.vfptr->__vecDelDtor + 1))(&v9->mStroker);
  v10 = 0;
  if ( LODWORD(v9->mStrokeSorter.OutPaths.Size) )
  {
    do
    {
      v11 = (unsigned __int64)v10 >> 4;
      v12 = v10 & 0xF;
      v13 = 0;
      v14 = v9->mStrokeSorter.OutPaths.Pages[v11][v12].numVer & 0xFFFFFFF;
      if ( v14 )
      {
        do
        {
          v15 = v13;
          v16 = v9->mStrokeSorter.OutPaths.Pages[v11];
          v17 = v16[v12].numVer & 0xFFFFFFF;
          if ( v13 >= v17 )
            v15 = v13 - v17;
          v18 = v9->mStrokeSorter.OutVertices.Pages;
          ++v13;
          v19 = &v18[(unsigned __int64)(v15 + v16[v12].start) >> 4][((_BYTE)v15 + LOBYTE(v16[v12].start)) & 0xF].x;
          switch ( *((_BYTE *)v19 + 12) )
          {
            case 1:
              v33 = *((unsigned int *)v19 + 1);
              v34 = *(unsigned int *)v19;
              ((void (__fastcall *)(Scaleform::Render::Stroker *))v9->mStroker.vfptr->AddVertex)(&v9->mStroker);
              break;
            case 2:
              v30 = v13;
              v31 = v16[v12].numVer & 0xFFFFFFF;
              if ( v13 >= v31 )
                v30 = v13 - v31;
              ++v13;
              v32 = &v18[(unsigned __int64)(v30 + v16[v12].start) >> 4][((_BYTE)v30 + LOBYTE(v16[v12].start)) & 0xF].x;
              Scaleform::Render::TessellateQuadCurve(
                (Scaleform::Render::TessBase *)&v9->mStroker.vfptr,
                v8,
                *v19,
                v19[1],
                v32[1],
                *v32,
                v32[1]);
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
              v27 = &v18[v25 >> 4][v24 & 0xF].x;
              v28 = v16[v12].numVer & 0xFFFFFFF;
              if ( v23 >= v28 )
                v26 = v23 - v28;
              v13 = v23 + 1;
              v29 = &v18[(unsigned __int64)(v26 + v16[v12].start) >> 4][((_BYTE)v26 + LOBYTE(v16[v12].start)) & 0xF].x;
              Scaleform::Render::TessellateCubicCurve(
                (Scaleform::Render::TessBase *)&v9->mStroker.vfptr,
                v8,
                *v19,
                v19[1],
                v27[1],
                *v27,
                v27[1],
                *v29,
                v29[1]);
              break;
          }
        }
        while ( v13 < v14 );
      }
      Scaleform::Render::Stroker::GenerateStroke(&v9->mStroker, (Scaleform::Render::TessBase *)&v9->mTess.vfptr);
      ++v10;
    }
    while ( v10 < LODWORD(v9->mStrokeSorter.OutPaths.Size) );
  }
}

// File Line: 1030
// RVA: 0x9DE380
char __fastcall Scaleform::Render::ShapeMeshProvider::createNullMesh(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::VertexOutput *pout, unsigned int drawLayer, unsigned int meshGenFlags)
{
  Scaleform::Render::VertexOutput *v4; // rbx
  Scaleform::Render::VertexOutputVtbl *v5; // rax
  char result; // al
  signed int v7; // ST20_4
  __int64 v8; // ST20_8
  __int64 v9; // [rsp+30h] [rbp-38h]
  int v10; // [rsp+38h] [rbp-30h]
  int v11; // [rsp+3Ch] [rbp-2Ch]
  Scaleform::Render::VertexFormat *v12; // [rsp+40h] [rbp-28h]
  __int64 v13; // [rsp+48h] [rbp-20h]
  __int64 v14; // [rsp+50h] [rbp-18h]
  __int16 v15; // [rsp+78h] [rbp+10h]
  int v16; // [rsp+7Ah] [rbp+12h]

  v4 = pout;
  v12 = &Scaleform::Render::VertexXY16iCF32::Format;
  v5 = pout->vfptr;
  v9 = 0i64;
  v16 = 0;
  v15 = 0;
  v13 = 0i64;
  v14 = 0i64;
  v10 = 1;
  v11 = 3;
  result = v5->BeginOutput(
             pout,
             (Scaleform::Render::VertexOutput::Fill *)&v10,
             1u,
             &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( result )
  {
    v7 = 1;
    v4->vfptr->SetVertices(v4, 0, 0, &v9, v7);
    LODWORD(v8) = 3;
    v4->vfptr->SetIndices(v4, 0, 0, (unsigned __int16 *)&v15, v8);
    v4->vfptr->EndOutput(v4);
    result = 1;
  }
  return result;
}

// File Line: 1058
// RVA: 0x9C5AA0
_BOOL8 __fastcall Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::TessBase *tess, Scaleform::Render::Matrix2x4<float> *mtx, Scaleform::Render::VertexOutput *pout, unsigned int drawLayerIdx, unsigned int strokeStyleIdx, unsigned int meshGenFlags, float morphRatio)
{
  Scaleform::Render::VertexOutput *v8; // r14
  Scaleform::Render::Matrix2x4<float> *v9; // rsi
  Scaleform::Render::TessBase *v10; // rdi
  Scaleform::Render::ShapeMeshProvider *v11; // r13
  unsigned int v12; // er12
  unsigned int v13; // er15
  unsigned int v14; // eax
  __int64 v15; // rdi
  unsigned int v16; // er9
  unsigned int v17; // er8
  unsigned int v18; // er14
  unsigned int v19; // esi
  unsigned int v20; // edi
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // er9
  unsigned int v24; // er8
  Scaleform::Render::VertexOutput *v25; // rdx
  Scaleform::Log *v26; // rax
  Scaleform::Render::VertexOutput *v27; // rsi
  bool v28; // di
  int v29; // er15
  int v30; // er12
  unsigned int v31; // er14
  __int64 v32; // rcx
  unsigned int v33; // esi
  unsigned int v34; // ebx
  char *v35; // rsi
  char *v36; // rdi
  __int64 v37; // r14
  __m128 v38; // xmm1
  signed int v39; // ecx
  __m128 v40; // xmm2
  signed int v41; // ecx
  unsigned int v42; // eax
  unsigned __int64 v43; // rax
  unsigned int v44; // edx
  unsigned int v45; // edx
  unsigned int v46; // edx
  unsigned __int64 v47; // rcx
  unsigned int v48; // esi
  unsigned int v49; // er14
  Scaleform::Render::VertexOutput::Fill *v50; // r15
  int v51; // edi
  __int64 v52; // ST20_8
  Scaleform::Render::ComplexFill *v53; // rcx
  Scaleform::Render::ComplexFill *v54; // rcx
  Scaleform::Render::DashArray *v55; // rcx
  Scaleform::Render::ComplexFill *v56; // rcx
  __int64 v58; // [rsp+20h] [rbp-E0h]
  unsigned int v59; // [rsp+30h] [rbp-D0h]
  int v60; // [rsp+34h] [rbp-CCh]
  int v61; // [rsp+38h] [rbp-C8h]
  unsigned int v62; // [rsp+3Ch] [rbp-C4h]
  unsigned int v63; // [rsp+40h] [rbp-C0h]
  unsigned int val; // [rsp+44h] [rbp-BCh]
  Scaleform::Render::VertexOutput::Fill *v65; // [rsp+48h] [rbp-B8h]
  Scaleform::Render::FillStyleType f1; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::VertexOutput::Fill v67; // [rsp+60h] [rbp-A0h]
  char v68; // [rsp+80h] [rbp-80h]
  int v69; // [rsp+84h] [rbp-7Ch]
  int v70; // [rsp+88h] [rbp-78h]
  int v71; // [rsp+8Ch] [rbp-74h]
  int v72; // [rsp+98h] [rbp-68h]
  Scaleform::Render::FillStyleType v73; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::StrokeStyleType s1; // [rsp+B0h] [rbp-50h]
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v75; // [rsp+E0h] [rbp-20h]
  Scaleform::Render::Matrix2x4<float> v76; // [rsp+140h] [rbp+40h]
  __int64 v77; // [rsp+160h] [rbp+60h]
  Scaleform::Render::Matrix2x4<float> v78; // [rsp+170h] [rbp+70h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2> v79; // [rsp+190h] [rbp+90h]
  char v80; // [rsp+3B0h] [rbp+2B0h]
  char v81; // [rsp+9B0h] [rbp+8B0h]
  char v82; // [rsp+9B4h] [rbp+8B4h]
  char v83; // [rsp+15B0h] [rbp+14B0h]
  char v84; // [rsp+15BCh] [rbp+14BCh]
  Scaleform::Render::ShapeMeshProvider *v85; // [rsp+2A20h] [rbp+2920h]
  Scaleform::Render::TessBase *v86; // [rsp+2A28h] [rbp+2928h]
  Scaleform::Render::VertexOutput *v87; // [rsp+2A38h] [rbp+2938h]

  v87 = pout;
  v86 = tess;
  v85 = this;
  v77 = -2i64;
  v8 = pout;
  v9 = mtx;
  v10 = tess;
  v11 = this;
  s1.pFill.pObject = 0i64;
  s1.pDashes.pObject = 0i64;
  v79.pHeap = Scaleform::Memory::pGlobalHeap;
  v79.Size = 0i64;
  v79.Reserved = 16i64;
  v79.Data = v79.Static;
  v75.pHeap = Scaleform::Memory::pGlobalHeap;
  v75.Size = 0i64;
  v75.Reserved = 16i64;
  v75.Data = v75.Static;
  if ( !tess->vfptr->GetMeshCount(tess) || !v10->vfptr->GetVertexCount(v10) )
  {
    v23 = meshGenFlags;
    v24 = drawLayerIdx;
    v25 = v8;
    goto LABEL_81;
  }
  v12 = meshGenFlags;
  v13 = drawLayerIdx;
  if ( strokeStyleIdx )
  {
    Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(v11, strokeStyleIdx, &s1, morphRatio);
  }
  else
  {
    v14 = (unsigned __int64)((__int64 (*)(void))v11->pShapeData.pObject->vfptr[2].__vecDelDtor)() + 1;
    if ( v14 )
    {
      val = 0;
      v15 = v14;
      do
      {
        Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v75, &val);
        --v15;
      }
      while ( v15 );
      v10 = v86;
    }
    v16 = v11->vfptr->GetFillCount((Scaleform::Render::MeshProvider *)&v11->vfptr, drawLayerIdx, meshGenFlags);
    v17 = 0;
    if ( v16 )
    {
      do
      {
        v75.Data[v11->FillToStyleTable.Data.Data[v17 + v11->DrawLayers.Data.Data[drawLayerIdx].StartFill]] = v17;
        ++v17;
      }
      while ( v17 < v16 );
    }
  }
  *(_OWORD *)&v76.M[0][0] = _xmm;
  *(__m128 *)&v76.M[1][0] = _xmm;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v76, v9);
  v10->vfptr->Transform(v10, &v76);
  ((void (__fastcall *)(Scaleform::Render::TessBase *, Scaleform::Render::Matrix2x4<float> *))v10->vfptr->StretchTo)(
    v10,
    &v78);
  v18 = 0;
  v19 = 0;
  if ( v10->vfptr->GetMeshCount(v10) )
  {
    do
    {
      v10->vfptr->GetMesh(v10, v19, (Scaleform::Render::TessMesh *)&v68);
      v20 = v10->vfptr->GetMeshVertexCount(v10, v19);
      v67.VertexCount = v20;
      v21 = v86->vfptr->GetMeshTriangleCount(v86, v19);
      v67.IndexCount = 3 * v21;
      if ( v20 && 3 * v21 )
      {
        v67.pFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        *(_QWORD *)&v67.FillIndex0 = 0i64;
        if ( !strokeStyleIdx )
        {
          v67.FillIndex0 = v75.Data[v69];
          v67.FillIndex1 = v75.Data[v70];
        }
        v22 = 1;
        if ( v71 & 0x8000 )
          v22 = 3;
        v67.MergeFlags = v22;
        v67.MeshIndex = v19;
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2>::PushBack(&v79, &v67);
        v18 += v72;
      }
      ++v19;
      v10 = v86;
    }
    while ( v19 < v86->vfptr->GetMeshCount(v86) );
    v13 = drawLayerIdx;
    v12 = meshGenFlags;
    v11 = v85;
  }
  if ( !v79.Size )
  {
    v23 = v12;
    v24 = v13;
    v25 = v87;
LABEL_81:
    v28 = Scaleform::Render::ShapeMeshProvider::createNullMesh(v11, v25, v24, v23);
    goto LABEL_82;
  }
  if ( v18 > 0xFFFF )
  {
    v26 = Scaleform::SF_GlobalLog;
    if ( Scaleform::SF_GlobalLog || (v26 = Scaleform::Log::GetDefaultLog()) != 0i64 )
      Scaleform::Log::LogWarning(
        v26,
        "Render_ShapeMeshProvider: More than 65535 vertices, the shape cannot be displayed");
    v23 = v12;
    v24 = v13;
    v25 = v87;
    goto LABEL_81;
  }
  v27 = v87;
  if ( !v87->vfptr->BeginOutput(v87, v79.Data, v79.Size, &v78) )
  {
    v28 = 0;
    goto LABEL_82;
  }
  v29 = 0;
  v60 = 0;
  v30 = 0;
  v61 = 0;
  f1.pFill.pObject = 0i64;
  v73.pFill.pObject = 0i64;
  v31 = 0;
  v59 = 0;
  if ( v79.Size > 0 )
  {
    v32 = 0i64;
    while ( 1 )
    {
      v65 = &v79.Data[v32];
      v10->vfptr->GetMesh(v10, v65->MeshIndex, (Scaleform::Render::TessMesh *)&v68);
      v33 = 0;
      v63 = 0;
      v34 = v10->vfptr->GetVertices(
              v10,
              (Scaleform::Render::TessMesh *)&v68,
              (Scaleform::Render::TessVertex *)&v83,
              256u);
      v62 = v34;
      if ( !v34 )
        goto LABEL_64;
      do
      {
        if ( !v34 )
          goto LABEL_63;
        v35 = &v82;
        v36 = &v84;
        v37 = v34;
        do
        {
          v38 = (__m128)*((unsigned int *)v36 - 3);
          if ( v38.m128_f32[0] >= 0.0 )
            v38.m128_f32[0] = v38.m128_f32[0] + 0.5;
          else
            v38.m128_f32[0] = v38.m128_f32[0] - 0.5;
          v39 = (signed int)v38.m128_f32[0];
          if ( (signed int)v38.m128_f32[0] != 0x80000000 && (float)v39 != v38.m128_f32[0] )
            v38.m128_f32[0] = (float)(v39 - (_mm_movemask_ps(_mm_unpacklo_ps(v38, v38)) & 1));
          *((_WORD *)v35 - 2) = (signed int)v38.m128_f32[0];
          v40 = (__m128)*((unsigned int *)v36 - 2);
          if ( v40.m128_f32[0] >= 0.0 )
            v40.m128_f32[0] = v40.m128_f32[0] + 0.5;
          else
            v40.m128_f32[0] = v40.m128_f32[0] - 0.5;
          v41 = (signed int)v40.m128_f32[0];
          if ( (signed int)v40.m128_f32[0] != 0x80000000 && (float)v41 != v40.m128_f32[0] )
            v40.m128_f32[0] = (float)(v41 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
          *((_WORD *)v35 - 1) = (signed int)v40.m128_f32[0];
          if ( strokeStyleIdx )
          {
            v42 = s1.Color;
          }
          else
          {
            *(_DWORD *)v35 = 0;
            v43 = *((unsigned __int16 *)v36 + 2);
            if ( v43 & 0x8000 )
              goto LABEL_61;
            if ( v43 & 0x10 )
            {
              v44 = *(unsigned __int16 *)v36;
              if ( v29 != v44 )
              {
                Scaleform::Render::ShapeMeshProvider::GetFillStyle(v11, v44, &f1, morphRatio);
                v29 = *(unsigned __int16 *)v36;
              }
              v45 = *((unsigned __int16 *)v36 + 1);
              if ( v30 != v45 )
              {
                Scaleform::Render::ShapeMeshProvider::GetFillStyle(v11, v45, &v73, morphRatio);
                v30 = *((unsigned __int16 *)v36 + 1);
              }
              v42 = ((f1.Color | v73.Color) >> 1) & 0x7F7F7F7F;
            }
            else
            {
              v46 = *(unsigned __int16 *)&v36[2 * ((v43 >> 5) & 1)];
              if ( v29 != v46 )
              {
                Scaleform::Render::ShapeMeshProvider::GetFillStyle(v11, v46, &f1, morphRatio);
                v29 = *(unsigned __int16 *)&v36[2 * (((unsigned __int64)*((unsigned __int16 *)v36 + 2) >> 5) & 1)];
              }
              v42 = f1.Color;
            }
          }
          *(_DWORD *)v35 = v42;
LABEL_61:
          v47 = *((unsigned __int16 *)v36 + 2);
          v35[4] = Scaleform::Render::Factors[*((_WORD *)v36 + 2) & 3];
          v35[5] = Scaleform::Render::Factors[(v47 >> 2) & 3];
          v36 += 20;
          v35 += 12;
          --v37;
        }
        while ( v37 );
        v61 = v30;
        v60 = v29;
        v34 = v62;
        v10 = v86;
        v33 = v63;
        v31 = v59;
LABEL_63:
        LODWORD(v58) = v34;
        v87->vfptr->SetVertices(v87, v31, v33, &v81, v58);
        v33 += v34;
        v63 = v33;
        v34 = v10->vfptr->GetVertices(
                v10,
                (Scaleform::Render::TessMesh *)&v68,
                (Scaleform::Render::TessVertex *)&v83,
                256u);
        v62 = v34;
      }
      while ( v34 );
LABEL_64:
      v48 = 0;
      v49 = v10->vfptr->GetMeshTriangleCount(v10, v65->MeshIndex);
      if ( v49 )
      {
        v50 = v65;
        do
        {
          v51 = 256;
          if ( v48 + 256 > v49 )
          {
            v51 = v49 - v48;
            if ( v49 == v48 )
              break;
          }
          LODWORD(v58) = v51;
          v86->vfptr->GetTrianglesI16(v86, v50->MeshIndex, (unsigned __int16 *)&v80, v48, v58);
          LODWORD(v52) = 3 * v51;
          v87->vfptr->SetIndices(v87, v59, 3 * v48, (unsigned __int16 *)&v80, v52);
          v48 += v51;
        }
        while ( v48 < v49 );
        v29 = v60;
        v11 = v85;
        v30 = v61;
        v10 = v86;
      }
      v31 = v59 + 1;
      v59 = v31;
      v32 = v31;
      if ( v31 >= v79.Size )
      {
        v27 = v87;
        break;
      }
    }
  }
  v27->vfptr->EndOutput(v27);
  v28 = 1;
  v53 = v73.pFill.pObject;
  if ( v73.pFill.pObject && _InterlockedExchangeAdd(&v73.pFill.pObject->RefCount, 0xFFFFFFFF) == 1 && v53 )
    v53->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v53->vfptr, 1u);
  v54 = f1.pFill.pObject;
  if ( f1.pFill.pObject && _InterlockedExchangeAdd(&f1.pFill.pObject->RefCount, 0xFFFFFFFF) == 1 && v54 )
    v54->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v54->vfptr, 1u);
LABEL_82:
  if ( v75.Data != v75.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v75.Data = v75.Static;
  v75.Size = 0i64;
  if ( v79.Data != v79.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v79.Data = v79.Static;
  v79.Size = 0i64;
  v55 = s1.pDashes.pObject;
  if ( s1.pDashes.pObject && _InterlockedExchangeAdd(&s1.pDashes.pObject->RefCount, 0xFFFFFFFF) == 1 && v55 )
    v55->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v55->vfptr, 1u);
  v56 = s1.pFill.pObject;
  if ( s1.pFill.pObject && _InterlockedExchangeAdd(&s1.pFill.pObject->RefCount, 0xFFFFFFFF) == 1 && v56 )
    v56->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v56->vfptr, 1u);
  return v28;
}

// File Line: 1235
// RVA: 0x9F6370
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::tessellateFill(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Scale9GridInfo *s9g, unsigned int drawLayerIdx, Scaleform::Render::MeshBase *pmesh, Scaleform::Render::VertexOutput *pout, unsigned int meshGenFlags)
{
  signed __int64 v6; // rsi
  Scaleform::Render::ShapeMeshProvider *v7; // rdi
  Scaleform::Render::Renderer2DImpl *v8; // rax
  Scaleform::Render::MeshGenerator *v9; // rbx
  Scaleform::Render::Matrix2x4<float> *v10; // rcx
  float v11; // xmm6_4
  unsigned int v12; // er12
  Scaleform::Render::TransformerBase *v13; // r15
  signed __int64 v14; // r13
  signed __int64 v15; // rdi
  signed __int64 v16; // r14
  __int64 v17; // rdx
  __int64 v18; // rdx
  unsigned __int64 v19; // rax
  char **v20; // rdi
  unsigned __int64 v21; // rax
  char **v22; // rdi
  unsigned __int64 v23; // rax
  char **v24; // rdi
  unsigned __int64 v25; // rax
  char **v26; // rdi
  float v27; // xmm0_4
  unsigned int startPos; // ST20_4
  Scaleform::Render::ShapeMeshProvider *v29; // rdi
  unsigned int v30; // ST20_4
  __int64 v31; // rdx
  __int64 v32; // rdx
  __int64 v33; // rdx
  unsigned __int64 v34; // rax
  char **v35; // rdi
  unsigned __int64 v36; // rax
  char **v37; // rdi
  unsigned __int64 v38; // rax
  char **v39; // rdi
  unsigned __int64 v40; // rax
  char **v41; // rdi
  unsigned __int64 v42; // rax
  char **v43; // rdi
  unsigned __int64 v44; // rax
  char **v45; // rdi
  unsigned __int64 v46; // rax
  char **v47; // rdi
  unsigned __int64 v48; // rax
  char **v49; // rdi
  Scaleform::Render::Matrix2x4<float> m2; // [rsp+50h] [rbp-B0h]
  void **v52; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Matrix2x4<float> *v53; // [rsp+78h] [rbp-88h]
  Scaleform::Render::TransformerBase tr; // [rsp+80h] [rbp-80h]
  Scaleform::Render::Scale9GridInfo *v55; // [rsp+88h] [rbp-78h]
  Scaleform::Render::ToleranceParams param; // [rsp+90h] [rbp-70h]
  __int64 v57; // [rsp+E0h] [rbp-20h]
  float key; // [rsp+F0h] [rbp-10h]
  Scaleform::Render::ShapeMeshProvider *v59; // [rsp+1C0h] [rbp+C0h]
  signed __int64 v60; // [rsp+1C8h] [rbp+C8h]
  unsigned int drawLayer; // [rsp+1D0h] [rbp+D0h]

  drawLayer = drawLayerIdx;
  v59 = this;
  v57 = -2i64;
  v6 = drawLayerIdx;
  v7 = this;
  v8 = pmesh->pRenderer2D;
  v9 = &v8->MeshGen;
  v10 = &pmesh->ViewMatrix;
  v11 = pmesh->MorphRatio;
  *(_OWORD *)&param.Epsilon = *(_OWORD *)&v8->Tolerances.Epsilon;
  *(_OWORD *)&param.FillLowerScale = *(_OWORD *)&v8->Tolerances.FillLowerScale;
  *(_OWORD *)&param.StrokeLowerScale = *(_OWORD *)&v8->Tolerances.StrokeLowerScale;
  *(_OWORD *)&param.Scale9LowerScale = *(_OWORD *)&v8->Tolerances.Scale9LowerScale;
  *(_QWORD *)&param.MinDet3D = *(_QWORD *)&v8->Tolerances.MinDet3D;
  param.CurveRecursionLimit = v8->Tolerances.CurveRecursionLimit;
  v52 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  v12 = 0;
  v53 = 0i64;
  tr.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  v55 = 0i64;
  *(_OWORD *)&m2.M[0][0] = _xmm;
  *(__m128 *)&m2.M[1][0] = _xmm;
  if ( s9g )
  {
    *(_OWORD *)&m2.M[0][0] = *(_OWORD *)&v10->M[0][0];
    *(_OWORD *)&m2.M[1][0] = *(_OWORD *)&pmesh->ViewMatrix.M[1][0];
    v55 = s9g;
    v13 = &tr;
  }
  else
  {
    if ( !Scaleform::Render::MeshKey::CalcMatrixKey(v10, &key, &m2) )
    {
      LOBYTE(v6) = Scaleform::Render::ShapeMeshProvider::createNullMesh(v7, pout, v6, meshGenFlags);
      return (unsigned __int8)v6;
    }
    v53 = &m2;
    v13 = (Scaleform::Render::TransformerBase *)&v52;
  }
  v14 = (signed __int64)&v9->mStroker;
  v15 = (signed __int64)&v9->mStrokeSorter;
  v16 = (signed __int64)&v9->mTess;
  v60 = v6;
  LODWORD(v6) = meshGenFlags;
  while ( 1 )
  {
    (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v16 + 8i64))(&v9->mTess.vfptr);
    (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v14 + 8i64))(&v9->mStroker.vfptr);
    (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v15 + 8i64))(v15);
    (*((void (__cdecl **)(Scaleform::Render::TessBaseVtbl **, __int64))&v9->mHairliner.vfptr->__vecDelDtor + 1))(
      &v9->mHairliner.vfptr,
      v17);
    (*((void (__cdecl **)(Scaleform::Render::TessBaseVtbl **, __int64))&v9->mStrokerAA.vfptr->__vecDelDtor + 1))(
      &v9->mStrokerAA.vfptr,
      v18);
    v19 = v9->Heap1.MaxPages;
    if ( v19 )
    {
      v20 = &v9->Heap1.pPagePool->pStart + 3 * v19 - 3;
      do
      {
        --v9->Heap1.MaxPages;
        if ( *v20 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap1.pHeap->vfptr->Free)(v9->Heap1.pHeap, *v20);
        v20 -= 3;
      }
      while ( v9->Heap1.MaxPages );
      --v9->Heap1.MaxPages;
      v9->Heap1.pHeap->vfptr->Free(v9->Heap1.pHeap, v9->Heap1.pPagePool);
    }
    v9->Heap1.pLastPage = 0i64;
    v9->Heap1.pPagePool = 0i64;
    v9->Heap1.MaxPages = 0i64;
    v21 = v9->Heap2.MaxPages;
    if ( v21 )
    {
      v22 = &v9->Heap2.pPagePool->pStart + 3 * v21 - 3;
      do
      {
        --v9->Heap2.MaxPages;
        if ( *v22 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap2.pHeap->vfptr->Free)(v9->Heap2.pHeap, *v22);
        v22 -= 3;
      }
      while ( v9->Heap2.MaxPages );
      --v9->Heap2.MaxPages;
      v9->Heap2.pHeap->vfptr->Free(v9->Heap2.pHeap, v9->Heap2.pPagePool);
    }
    v9->Heap2.pLastPage = 0i64;
    v9->Heap2.pPagePool = 0i64;
    v9->Heap2.MaxPages = 0i64;
    v23 = v9->Heap3.MaxPages;
    if ( v23 )
    {
      v24 = &v9->Heap3.pPagePool->pStart + 3 * v23 - 3;
      do
      {
        --v9->Heap3.MaxPages;
        if ( *v24 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap3.pHeap->vfptr->Free)(v9->Heap3.pHeap, *v24);
        v24 -= 3;
      }
      while ( v9->Heap3.MaxPages );
      --v9->Heap3.MaxPages;
      v9->Heap3.pHeap->vfptr->Free(v9->Heap3.pHeap, v9->Heap3.pPagePool);
    }
    v9->Heap3.pLastPage = 0i64;
    v9->Heap3.pPagePool = 0i64;
    v9->Heap3.MaxPages = 0i64;
    v25 = v9->Heap4.MaxPages;
    if ( v25 )
    {
      v26 = &v9->Heap4.pPagePool->pStart + 3 * v25 - 3;
      do
      {
        --v9->Heap4.MaxPages;
        if ( *v26 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap4.pHeap->vfptr->Free)(v9->Heap4.pHeap, *v26);
        v26 -= 3;
      }
      while ( v9->Heap4.MaxPages );
      --v9->Heap4.MaxPages;
      v9->Heap4.pHeap->vfptr->Free(v9->Heap4.pHeap, v9->Heap4.pPagePool);
    }
    v9->Heap4.pLastPage = 0i64;
    v9->Heap4.pPagePool = 0i64;
    v9->Heap4.MaxPages = 0i64;
    v9->mTess.FillRule = 1;
    v9->mTess.StrokerMode = 0;
    v9->mTess.Epsilon = param.Epsilon;
    v9->mTess.HasEpsilon = param.Epsilon > 0.0;
    v9->mTess.IntersectionEpsilon = param.IntersectionEpsilon;
    if ( !(v6 & 1) || v6 & 2 )
    {
      v9->mTess.EdgeAAWidth = 0.0;
      v9->mTess.EdgeAAFlag = 0;
    }
    else
    {
      v27 = param.EdgeAAScale * 0.5;
      v9->mTess.EdgeAAWidth = param.EdgeAAScale * 0.5;
      v9->mTess.EdgeAAFlag = v27 > 0.0;
    }
    startPos = v59->DrawLayers.Data.Data[v60].StartPos;
    Scaleform::Render::ShapeMeshProvider::addFill(v59, v9, &param, v13);
    if ( v6 & 1 && LODWORD(v9->mTess.SrcVertices.Size) >= 0x8000 )
    {
      Scaleform::Render::MeshGenerator::Clear(v9);
      v9->mTess.EdgeAAWidth = 0.0;
      v9->mTess.EdgeAAFlag = 0;
      v29 = v59;
      v30 = v59->DrawLayers.Data.Data[v60].StartPos;
      Scaleform::Render::ShapeMeshProvider::addFill(v59, v9, &param, v13);
      LODWORD(v6) = v6 & 0xFFFFFFFE;
    }
    else
    {
      v29 = v59;
    }
    Scaleform::Render::Tessellator::Tessellate(&v9->mTess, 0);
    if ( (*(unsigned int (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v16 + 72i64))(&v9->mTess.vfptr) < 0xFFFF )
      break;
    LODWORD(v6) = v6 & 0xFFFFFFFE;
    param.CurveTolerance = param.CurveTolerance * 4.0;
    ++v12;
    v15 = (signed __int64)&v9->mStrokeSorter;
    if ( v12 >= 4 )
    {
      (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v16 + 8i64))(&v9->mTess.vfptr);
      (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v14 + 8i64))(&v9->mStroker.vfptr);
      (*((void (__cdecl **)(Scaleform::Render::TessBaseVtbl **, __int64))&v9->mStrokeSorter.vfptr->__vecDelDtor + 1))(
        &v9->mStrokeSorter.vfptr,
        v31);
      (*((void (__cdecl **)(Scaleform::Render::TessBaseVtbl **, __int64))&v9->mHairliner.vfptr->__vecDelDtor + 1))(
        &v9->mHairliner.vfptr,
        v32);
      (*((void (__cdecl **)(Scaleform::Render::TessBaseVtbl **, __int64))&v9->mStrokerAA.vfptr->__vecDelDtor + 1))(
        &v9->mStrokerAA.vfptr,
        v33);
      v34 = v9->Heap1.MaxPages;
      if ( v34 )
      {
        v35 = &v9->Heap1.pPagePool->pStart + 3 * v34 - 3;
        do
        {
          --v9->Heap1.MaxPages;
          if ( *v35 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap1.pHeap->vfptr->Free)(v9->Heap1.pHeap, *v35);
          v35 -= 3;
        }
        while ( v9->Heap1.MaxPages );
        --v9->Heap1.MaxPages;
        v9->Heap1.pHeap->vfptr->Free(v9->Heap1.pHeap, v9->Heap1.pPagePool);
      }
      v9->Heap1.pLastPage = 0i64;
      v9->Heap1.pPagePool = 0i64;
      v9->Heap1.MaxPages = 0i64;
      v36 = v9->Heap2.MaxPages;
      if ( v36 )
      {
        v37 = &v9->Heap2.pPagePool->pStart + 3 * v36 - 3;
        do
        {
          --v9->Heap2.MaxPages;
          if ( *v37 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap2.pHeap->vfptr->Free)(v9->Heap2.pHeap, *v37);
          v37 -= 3;
        }
        while ( v9->Heap2.MaxPages );
        --v9->Heap2.MaxPages;
        v9->Heap2.pHeap->vfptr->Free(v9->Heap2.pHeap, v9->Heap2.pPagePool);
      }
      v9->Heap2.pLastPage = 0i64;
      v9->Heap2.pPagePool = 0i64;
      v9->Heap2.MaxPages = 0i64;
      v38 = v9->Heap3.MaxPages;
      if ( v38 )
      {
        v39 = &v9->Heap3.pPagePool->pStart + 3 * v38 - 3;
        do
        {
          --v9->Heap3.MaxPages;
          if ( *v39 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap3.pHeap->vfptr->Free)(v9->Heap3.pHeap, *v39);
          v39 -= 3;
        }
        while ( v9->Heap3.MaxPages );
        --v9->Heap3.MaxPages;
        v9->Heap3.pHeap->vfptr->Free(v9->Heap3.pHeap, v9->Heap3.pPagePool);
      }
      v9->Heap3.pLastPage = 0i64;
      v9->Heap3.pPagePool = 0i64;
      v9->Heap3.MaxPages = 0i64;
      v40 = v9->Heap4.MaxPages;
      if ( v40 )
      {
        v41 = &v9->Heap4.pPagePool->pStart + 3 * v40 - 3;
        do
        {
          --v9->Heap4.MaxPages;
          if ( *v41 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, char *))v9->Heap4.pHeap->vfptr->Free)(v9->Heap4.pHeap, *v41);
          v41 -= 3;
        }
        while ( v9->Heap4.MaxPages );
        --v9->Heap4.MaxPages;
        v9->Heap4.pHeap->vfptr->Free(v9->Heap4.pHeap, v9->Heap4.pPagePool);
      }
      v9->Heap4.pLastPage = 0i64;
      v9->Heap4.pPagePool = 0i64;
      v9->Heap4.MaxPages = 0i64;
      LOBYTE(v6) = Scaleform::Render::ShapeMeshProvider::createNullMesh(v59, pout, drawLayer, v6);
      return (unsigned __int8)v6;
    }
  }
  v6 = (unsigned __int8)Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
                          v29,
                          (Scaleform::Render::TessBase *)&v9->mTess.vfptr,
                          &m2,
                          pout,
                          drawLayer,
                          0,
                          v6,
                          v11);
  (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v16 + 8i64))(&v9->mTess.vfptr);
  (*(void (__fastcall **)(Scaleform::Render::TessBaseVtbl **))(*(_QWORD *)v14 + 8i64))(&v9->mStroker.vfptr);
  (*((void (**)(void))&v9->mStrokeSorter.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v9->mHairliner.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v9->mStrokerAA.vfptr->__vecDelDtor + 1))();
  v42 = v9->Heap1.MaxPages;
  if ( v42 )
  {
    v43 = &v9->Heap1.pPagePool->pStart + 3 * v42 - 3;
    do
    {
      --v9->Heap1.MaxPages;
      if ( *v43 )
        ((void (*)(void))v9->Heap1.pHeap->vfptr->Free)();
      v43 -= 3;
    }
    while ( v9->Heap1.MaxPages );
    --v9->Heap1.MaxPages;
    v9->Heap1.pHeap->vfptr->Free(v9->Heap1.pHeap, v9->Heap1.pPagePool);
  }
  v9->Heap1.pLastPage = 0i64;
  v9->Heap1.pPagePool = 0i64;
  v9->Heap1.MaxPages = 0i64;
  v44 = v9->Heap2.MaxPages;
  if ( v44 )
  {
    v45 = &v9->Heap2.pPagePool->pStart + 3 * v44 - 3;
    do
    {
      --v9->Heap2.MaxPages;
      if ( *v45 )
        ((void (*)(void))v9->Heap2.pHeap->vfptr->Free)();
      v45 -= 3;
    }
    while ( v9->Heap2.MaxPages );
    --v9->Heap2.MaxPages;
    v9->Heap2.pHeap->vfptr->Free(v9->Heap2.pHeap, v9->Heap2.pPagePool);
  }
  v9->Heap2.pLastPage = 0i64;
  v9->Heap2.pPagePool = 0i64;
  v9->Heap2.MaxPages = 0i64;
  v46 = v9->Heap3.MaxPages;
  if ( v46 )
  {
    v47 = &v9->Heap3.pPagePool->pStart + 3 * v46 - 3;
    do
    {
      --v9->Heap3.MaxPages;
      if ( *v47 )
        ((void (*)(void))v9->Heap3.pHeap->vfptr->Free)();
      v47 -= 3;
    }
    while ( v9->Heap3.MaxPages );
    --v9->Heap3.MaxPages;
    v9->Heap3.pHeap->vfptr->Free(v9->Heap3.pHeap, v9->Heap3.pPagePool);
  }
  v9->Heap3.pLastPage = 0i64;
  v9->Heap3.pPagePool = 0i64;
  v9->Heap3.MaxPages = 0i64;
  v48 = v9->Heap4.MaxPages;
  if ( v48 )
  {
    v49 = &v9->Heap4.pPagePool->pStart + 3 * v48 - 3;
    do
    {
      --v9->Heap4.MaxPages;
      if ( *v49 )
        ((void (*)(void))v9->Heap4.pHeap->vfptr->Free)();
      v49 -= 3;
    }
    while ( v9->Heap4.MaxPages );
    --v9->Heap4.MaxPages;
    v9->Heap4.pHeap->vfptr->Free(v9->Heap4.pHeap, v9->Heap4.pPagePool);
  }
  v9->Heap4.pLastPage = 0i64;
  v9->Heap4.pPagePool = 0i64;
  v9->Heap4.MaxPages = 0i64;
  return (unsigned __int8)v6;
}

// File Line: 1329
// RVA: 0x9F6CC0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::tessellateStroke(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Scale9GridInfo *s9g, unsigned int strokeStyleIdx, unsigned int drawLayerIdx)
{
  __int64 v4; // rdi
  Scaleform::Render::Scale9GridInfo *v5; // rbx
  Scaleform::Render::ShapeMeshProvider *v6; // r13
  __int64 v7; // r10
  __int64 v8; // rax
  signed __int64 v9; // rsi
  float v10; // xmm11_4
  float v11; // xmm9_4
  unsigned int v12; // xmm13_4
  __m128 v13; // xmm7
  __m128 v14; // xmm10
  __m128 v15; // xmm8
  unsigned int v16; // xmm14_4
  __m128 v17; // xmm6
  signed __int64 v18; // r12
  char v19; // r14
  float v20; // xmm1_4
  float v21; // xmm0_4
  signed int v22; // ecx
  signed int v23; // ecx
  Scaleform::Render::TransformerBase *tr; // r15
  float v25; // xmm0_4
  int v26; // eax
  __m128 v27; // xmm1
  float v28; // xmm3_4
  signed int v29; // ecx
  __m128 v30; // xmm2
  signed int v31; // ecx
  float snapOffset; // xmm4_4
  bool v33; // al
  bool v34; // cl
  float v35; // xmm6_4
  unsigned int v36; // er14
  Scaleform::Render::TessBase *v37; // rdx
  signed int v38; // er8
  signed int v39; // er10
  signed int v40; // er9
  int v41; // eax
  int v42; // edx
  float v43; // xmm1_4
  signed __int64 v44; // rbx
  float v45; // xmm1_4
  float v46; // xmm3_4
  float v47; // xmm3_4
  __int64 v48; // rdi
  Scaleform::Render::Matrix2x4<float> *v49; // rcx
  void **v50; // rcx
  Scaleform::Render::TransformerBase v52; // [rsp+48h] [rbp-80h]
  Scaleform::Render::Matrix2x4<float> mtx; // [rsp+50h] [rbp-78h]
  void **v54; // [rsp+70h] [rbp-58h]
  Scaleform::Render::Matrix2x4<float> *v55; // [rsp+78h] [rbp-50h]
  int v56; // [rsp+88h] [rbp-40h]
  int v57; // [rsp+8Ch] [rbp-3Ch]
  int v58; // [rsp+90h] [rbp-38h]
  int v59; // [rsp+94h] [rbp-34h]
  int v60; // [rsp+98h] [rbp-30h]
  int v61; // [rsp+9Ch] [rbp-2Ch]
  int v62; // [rsp+A0h] [rbp-28h]
  int v63; // [rsp+A4h] [rbp-24h]
  void **v64; // [rsp+A8h] [rbp-20h]
  Scaleform::Render::Scale9GridInfo *v65; // [rsp+B0h] [rbp-18h]
  void **v66; // [rsp+B8h] [rbp-10h]
  Scaleform::Render::Matrix2x4<float> *v67; // [rsp+C0h] [rbp-8h]
  __int64 v68; // [rsp+C8h] [rbp+0h]
  unsigned int startPos; // [rsp+1B8h] [rbp+F0h]
  unsigned int v70; // [rsp+1C8h] [rbp+100h]
  unsigned int drawLayerIdxa; // [rsp+1D0h] [rbp+108h]
  float morphRatio[2]; // [rsp+1D8h] [rbp+110h]
  Scaleform::Render::VertexOutput *vars0; // [rsp+1E0h] [rbp+118h]
  void *retaddr; // [rsp+1E8h] [rbp+120h]

  v68 = -2i64;
  v4 = drawLayerIdx;
  v5 = s9g;
  v6 = this;
  v7 = *(_QWORD *)morphRatio;
  v8 = *(_QWORD *)(*(_QWORD *)morphRatio + 80i64);
  v9 = v8 + 88;
  v10 = *(float *)(*(_QWORD *)morphRatio + 112i64);
  v56 = *(_DWORD *)(*(_QWORD *)morphRatio + 112i64);
  v11 = *(float *)(*(_QWORD *)morphRatio + 116i64);
  v57 = *(_DWORD *)(*(_QWORD *)morphRatio + 116i64);
  v12 = *(_DWORD *)(*(_QWORD *)morphRatio + 120i64);
  v58 = *(_DWORD *)(*(_QWORD *)morphRatio + 120i64);
  v13 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 124i64);
  v59 = *(_DWORD *)(*(_QWORD *)morphRatio + 124i64);
  v14 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 128i64);
  v60 = *(_DWORD *)(*(_QWORD *)morphRatio + 128i64);
  v15 = (__m128)*(unsigned int *)(*(_QWORD *)morphRatio + 132i64);
  v61 = *(_DWORD *)(*(_QWORD *)morphRatio + 132i64);
  v16 = *(_DWORD *)(*(_QWORD *)morphRatio + 136i64);
  v62 = *(_DWORD *)(*(_QWORD *)morphRatio + 136i64);
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
  startPos = v6->DrawLayers.Data.Data[v4].StartPos;
  if ( mtx.M[1][1] < 1.0 )
    mtx.M[1][1] = 1.0;
  v19 = LOBYTE(mtx.M[1][0]) & 1;
  if ( LOBYTE(mtx.M[1][0]) & 1 )
  {
    v20 = FLOAT_N0_5;
    if ( v13.m128_f32[0] >= 0.0 )
      v21 = FLOAT_0_5;
    else
      v21 = FLOAT_N0_5;
    v13.m128_f32[0] = v13.m128_f32[0] + v21;
    v22 = (signed int)v13.m128_f32[0];
    if ( (signed int)v13.m128_f32[0] != 0x80000000 && (float)v22 != v13.m128_f32[0] )
      v13.m128_f32[0] = (float)(v22 - (_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1));
    v59 = v13.m128_i32[0];
    if ( v17.m128_f32[0] >= 0.0 )
      v20 = FLOAT_0_5;
    v17.m128_f32[0] = v17.m128_f32[0] + v20;
    v23 = (signed int)v17.m128_f32[0];
    if ( (signed int)v17.m128_f32[0] != 0x80000000 && (float)v23 != v17.m128_f32[0] )
      v17.m128_f32[0] = (float)(v23 - (_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1));
    v63 = v17.m128_i32[0];
  }
  *(_QWORD *)&mtx.M[0][2] = __PAIR__(v13.m128_u32[0], v12);
  *(_QWORD *)&mtx.M[1][0] = __PAIR__(v15.m128_u32[0], v14.m128_u32[0]);
  *(_QWORD *)&mtx.M[1][2] = __PAIR__(v17.m128_u32[0], v16);
  v54 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  v55 = 0i64;
  v52.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  *(_QWORD *)&mtx.M[0][0] = 0i64;
  if ( v5 )
  {
    v65 = v5;
    *(_QWORD *)&mtx.M[0][0] = v5;
    v64 = &Scaleform::Render::TransformerBase::`vftable';
    tr = &v52;
  }
  else
  {
    v67 = &mtx;
    v55 = &mtx;
    v66 = &Scaleform::Render::TransformerBase::`vftable';
    tr = (Scaleform::Render::TransformerBase *)&v54;
  }
  Scaleform::Render::MeshGenerator::Clear((Scaleform::Render::MeshGenerator *)v9);
  v25 = mtx.M[0][3];
  if ( !v5 )
  {
    v26 = LOBYTE(mtx.M[1][0]) & 6;
    if ( !(LOBYTE(mtx.M[1][0]) & 6) )
    {
      v11 = (float)(v11 + v10) * 0.70710677;
      v15.m128_f32[0] = (float)(v15.m128_f32[0] + v14.m128_f32[0]) * 0.70710677;
LABEL_26:
      v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v11 * v11);
      LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v15);
      goto LABEL_27;
    }
    if ( v26 == 2 )
    {
      v14.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v10 * v10);
      LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v14);
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
  if ( !((unsigned __int8)retaddr & 1) || (unsigned __int8)retaddr & 2 )
  {
    v28 = 0.0;
    v29 = (signed int)v27.m128_f32[0];
    if ( (signed int)v27.m128_f32[0] != 0x80000000 && (float)v29 != v27.m128_f32[0] )
      v27 = (__m128)COERCE_UNSIGNED_INT((float)(v29 - (_mm_movemask_ps(_mm_unpacklo_ps(v27, v27)) & 1)));
    v27.m128_f32[0] = v27.m128_f32[0] + 1.0;
  }
  if ( v19 )
  {
    if ( v27.m128_f32[0] < 1.26 )
      goto LABEL_85;
    v30 = v27;
    v30.m128_f32[0] = v27.m128_f32[0] - 0.25;
    v31 = (signed int)(float)(v27.m128_f32[0] - 0.25);
    if ( v31 != 0x80000000 && (float)v31 != v30.m128_f32[0] )
      v30.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1 ^ 1) + v31);
    if ( (signed int)v30.m128_f32[0] & 1 )
LABEL_85:
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
  if ( (unsigned __int8)retaddr & 2 )
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
      v44 = v9 + 2512;
      v45 = v43 * 0.5;
      *(float *)(v44 + 36) = v45;
      *(float *)(v44 + 32) = v45;
      v46 = (float)(v28 * *(float *)(v18 + 56)) * 2.0;
      *(float *)(v44 + 44) = v46;
      *(float *)(v44 + 40) = v46;
      *(_DWORD *)(v9 + 2520) = v38;
      *(_DWORD *)(v9 + 2524) = v39;
      *(_DWORD *)(v9 + 2528) = v40;
      *(float *)(v9 + 2532) = mtx.M[1][1];
      *(_DWORD *)(v44 + 48) = *(_DWORD *)(v18 + 4);
      *(_DWORD *)(v44 + 52) = *(_DWORD *)(v18 + 12);
      v35 = morphRatio[0];
      v36 = v70;
      Scaleform::Render::ShapeMeshProvider::addStroke(
        v6,
        (Scaleform::Render::MeshGenerator *)v9,
        (Scaleform::Render::TessBase *)(v9 + 2512),
        (Scaleform::Render::ToleranceParams *)v18,
        tr,
        startPos,
        v70,
        snapOffset,
        morphRatio[0]);
LABEL_73:
      v37 = (Scaleform::Render::TessBase *)v44;
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
    v44 = v9 + 160;
    *(_DWORD *)(v44 + 24) = 0;
    *(_BYTE *)(v44 + 33) = 1;
    v47 = v28 * *(float *)(v18 + 56);
    *(float *)(v44 + 940) = v47;
    *(_BYTE *)(v44 + 944) = v47 > 0.0;
    v35 = morphRatio[0];
    v36 = v70;
    Scaleform::Render::ShapeMeshProvider::addStroke(
      v6,
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
    v6,
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
  v48 = (unsigned __int8)Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
                           v6,
                           v37,
                           &mtx,
                           vars0,
                           drawLayerIdxa,
                           v36,
                           (unsigned int)retaddr,
                           v35);
  Scaleform::Render::MeshGenerator::Clear((Scaleform::Render::MeshGenerator *)v9);
  v52.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerBase::`vftable';
  v54 = &Scaleform::Render::TransformerBase::`vftable';
  v49 = v55;
  if ( v55 && !_InterlockedDecrement((volatile signed __int32 *)&v55->M[0][2]) && v49 )
    (**(void (__fastcall ***)(Scaleform::Render::Matrix2x4<float> *, signed __int64))&v49->M[0][0])(v49, 1i64);
  v50 = v54;
  if ( v54 && !_InterlockedDecrement((volatile signed __int32 *)v54 + 2) && v50 )
    (*(void (__fastcall **)(void **, signed __int64))*v50)(v50, 1i64);
  return (unsigned __int8)v48;
}

// File Line: 1499
// RVA: 0x9E7100
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::getLayerBounds(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Rect<float> *result, unsigned int drawLayer)
{
  Scaleform::Render::ShapeMeshProvider *v3; // rbx
  Scaleform::Render::Rect<float> *bounds; // rsi
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v5; // rax
  Scaleform::Render::ShapeDataInterface *v6; // rcx
  unsigned int v7; // er8
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  char v9; // di
  int i; // eax
  int v12; // [rsp+30h] [rbp-29h]
  int v13; // [rsp+34h] [rbp-25h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+40h] [rbp-19h]
  float coord; // [rsp+78h] [rbp+1Fh]
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+90h] [rbp+37h]

  v3 = this;
  bounds = result;
  v5 = this->DrawLayers.Data.Data;
  v6 = this->pShapeData.pObject;
  *(__m128 *)&trans.M[1][0] = _xmm;
  v7 = v5[drawLayer].StartPos;
  result->x1 = 1.0e30;
  LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
  *(_OWORD *)&trans.M[0][0] = _xmm;
  pos.Pos = v7;
  *(_QWORD *)&pos.StartX = 0i64;
  *(_QWORD *)&pos.LastX = 0i64;
  *(_QWORD *)&pos.FillBase = 0i64;
  *(_QWORD *)&pos.NumFillBits = 0i64;
  *(_QWORD *)&pos.Fill0 = 0i64;
  pos.Stroke = 0;
  pos.Initialized = 0;
  v8 = v6->vfptr;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v9 = 1;
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v8[8].__vecDelDtor)(
              v6,
              &pos,
              &coord,
              &v12);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v3->pShapeData.pObject->vfptr[8].__vecDelDtor)(
              v3->pShapeData.pObject,
              &pos,
              &coord,
              &v12) )
  {
    if ( !v9 && i == 2 )
      break;
    v9 = 0;
    if ( v12 || v13 )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        v3->pShapeData.pObject,
        &trans,
        &pos,
        &coord,
        bounds);
    else
      v3->pShapeData.pObject->vfptr[10].__vecDelDtor(
        (Scaleform::RefCountImplCore *)&v3->pShapeData.pObject->vfptr,
        (unsigned int)&pos);
  }
  return bounds;
}

// File Line: 1528
// RVA: 0x9E41D0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::generateImage9Grid(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Scale9GridInfo *s9g, Scaleform::Render::MeshBase *mesh, Scaleform::Render::VertexOutput *verOut)
{
  Scaleform::Render::VertexOutput *v4; // rbx
  Scaleform::Render::MeshBase *v5; // r14
  Scaleform::Render::Scale9GridInfo *v6; // r15
  Scaleform::Render::ShapeMeshProvider *v7; // rdi
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  Scaleform::Render::Rect<float> *v11; // rax
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  unsigned int v15; // eax
  __int64 v16; // rdx
  __int64 v17; // rax
  Scaleform::Render::Matrix2x4<float> *v18; // ST20_8
  unsigned __int8 v19; // bl
  Scaleform::Render::Matrix2x4<float> *v20; // ST20_8
  void (__fastcall ***v21)(_QWORD, signed __int64); // rcx
  Scaleform::Render::Matrix2x4<float> *uvMatrix; // [rsp+20h] [rbp-C8h]
  Scaleform::Render::Matrix2x4<float> *uvMatrixa; // [rsp+20h] [rbp-C8h]
  Scaleform::Render::Matrix2x4<float> *fillMatrix; // [rsp+28h] [rbp-C0h]
  __int64 v26; // [rsp+30h] [rbp-B8h]
  __int64 v27; // [rsp+38h] [rbp-B0h]
  char v28; // [rsp+40h] [rbp-A8h]
  __int64 v29; // [rsp+48h] [rbp-A0h]
  Scaleform::Render::Rect<float> imgRect; // [rsp+50h] [rbp-98h]
  float v31; // [rsp+60h] [rbp-88h]
  float v32; // [rsp+64h] [rbp-84h]
  float v33; // [rsp+68h] [rbp-80h]
  __int64 v34; // [rsp+6Ch] [rbp-7Ch]
  __int64 v35; // [rsp+74h] [rbp-74h]
  __int64 v36; // [rsp+7Ch] [rbp-6Ch]
  int v37; // [rsp+84h] [rbp-64h]
  int v38; // [rsp+88h] [rbp-60h]
  char v39; // [rsp+8Ch] [rbp-5Ch]
  unsigned int v40; // [rsp+90h] [rbp-58h]
  unsigned int v41; // [rsp+94h] [rbp-54h]
  unsigned int v42; // [rsp+A0h] [rbp-48h]
  int v43; // [rsp+A4h] [rbp-44h]
  Scaleform::Render::VertexFormat *v44; // [rsp+A8h] [rbp-40h]
  __int64 v45; // [rsp+B0h] [rbp-38h]
  __int64 v46; // [rsp+B8h] [rbp-30h]
  int v47; // [rsp+C0h] [rbp-28h]
  int v48; // [rsp+C4h] [rbp-24h]
  Scaleform::Render::VertexFormat *v49; // [rsp+C8h] [rbp-20h]
  __int64 v50; // [rsp+D0h] [rbp-18h]
  __int64 v51; // [rsp+D8h] [rbp-10h]
  __int64 v52; // [rsp+E0h] [rbp-8h]
  __int128 v53; // [rsp+E8h] [rbp+0h]
  __m128 v54; // [rsp+F8h] [rbp+10h]
  Scaleform::Render::Rect<float> result; // [rsp+108h] [rbp+20h]
  Scaleform::Render::Matrix2x4<float> v56; // [rsp+118h] [rbp+30h]
  char v57; // [rsp+138h] [rbp+50h]
  Scaleform::Render::Scale9GridTess v58; // [rsp+158h] [rbp+70h]
  __int16 v59; // [rsp+3B8h] [rbp+2D0h]
  int v60; // [rsp+3BAh] [rbp+2D2h]
  unsigned int v61; // [rsp+3D8h] [rbp+2F0h]

  v52 = -2i64;
  v4 = verOut;
  v5 = mesh;
  v6 = s9g;
  v7 = this;
  if ( this->DrawLayers.Data.Data[v61].Image9GridType == 2 )
  {
    v8 = this->IdentityBounds.y2;
    v9 = this->IdentityBounds.x2;
    v10 = this->IdentityBounds.y1;
    v31 = this->IdentityBounds.x1;
    v32 = v10;
    v33 = v9;
    *(float *)&v34 = v8;
    v11 = (Scaleform::Render::Rect<float> *)&v31;
  }
  else
  {
    v11 = Scaleform::Render::ShapeMeshProvider::getLayerBounds(this, &result, v61);
  }
  v12 = v11->y2;
  v13 = v11->x2;
  v14 = v11->y1;
  imgRect.x1 = v11->x1;
  imgRect.y1 = v14;
  imgRect.x2 = v13;
  imgRect.y2 = v12;
  v15 = v7->DrawLayers.Data.Data[v61].StartPos;
  v34 = 0i64;
  v35 = 0i64;
  v36 = 0i64;
  v37 = 0;
  v38 = (signed int)FLOAT_1_0;
  v39 = 0;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, char *, char *, unsigned int *))v7->pShapeData.pObject->vfptr[8].__vecDelDtor)(
    v7->pShapeData.pObject,
    (char *)&v34 + 4,
    &v57,
    &v40);
  v16 = v41;
  if ( v40 )
    v16 = v40;
  v29 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *))v7->pShapeData.pObject->vfptr[4].__vecDelDtor)(
    v7->pShapeData.pObject,
    v16,
    &v28);
  v17 = ((__int64 (*)(void))v5->pRenderer2D->pHal.pObject->vfptr[61].__vecDelDtor)();
  (*(void (__fastcall **)(_QWORD, Scaleform::Render::Matrix2x4<float> *, __int64))(**(_QWORD **)(v29 + 16) + 184i64))(
    *(_QWORD *)(v29 + 16),
    &v56,
    v17);
  fillMatrix = (Scaleform::Render::Matrix2x4<float> *)(v29 + 32);
  Scaleform::Render::Scale9GridTess::Scale9GridTess(&v58, Scaleform::Memory::pGlobalHeap, v6, &imgRect);
  if ( !LODWORD(v58.Indices.Size) )
  {
    v26 = 0i64;
    v27 = 0i64;
    v60 = 0;
    v59 = 0;
    v47 = 1;
    v48 = 3;
    v49 = &Scaleform::Render::Image9GridVertex::Format;
    v50 = 0i64;
    v51 = 0i64;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::VertexOutput *, int *, signed __int64, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))v4->vfptr->BeginOutput)(
           v4,
           &v47,
           1i64,
           &Scaleform::Render::Matrix2x4<float>::Identity,
           &v56) )
    {
      LODWORD(uvMatrixa) = 1;
      ((void (__fastcall *)(Scaleform::Render::VertexOutput *, _QWORD, _QWORD, __int64 *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))v4->vfptr->SetVertices)(
        v4,
        0i64,
        0i64,
        &v26,
        uvMatrixa,
        fillMatrix);
      LODWORD(v20) = 3;
      v4->vfptr->SetIndices(v4, 0, 0, (unsigned __int16 *)&v59, (unsigned int)v20);
      goto LABEL_12;
    }
LABEL_10:
    v19 = 0;
    goto LABEL_13;
  }
  v42 = v58.VerCount;
  v43 = v58.Indices.Size;
  v44 = &Scaleform::Render::Image9GridVertex::Format;
  v45 = 0i64;
  v46 = 0i64;
  v53 = _xmm;
  v54 = _xmm;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::VertexOutput *, unsigned int *, signed __int64, __int128 *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))v4->vfptr->BeginOutput)(
          v4,
          &v42,
          1i64,
          &v53,
          &v56,
          fillMatrix) )
    goto LABEL_10;
  LODWORD(uvMatrix) = v58.VerCount;
  v4->vfptr->SetVertices(v4, 0, 0, &v58, (unsigned int)uvMatrix);
  LODWORD(v18) = v58.Indices.Size;
  v4->vfptr->SetIndices(v4, 0, 0, v58.Indices.Data, (unsigned int)v18);
LABEL_12:
  v4->vfptr->EndOutput(v4);
  v19 = 1;
LABEL_13:
  if ( v58.Indices.Data != v58.Indices.Static )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v58.Indices.Data = v58.Indices.Static;
  v58.Indices.Size = 0i64;
  v21 = (void (__fastcall ***)(_QWORD, signed __int64))v29;
  if ( v29 && !_InterlockedDecrement((volatile signed __int32 *)(v29 + 8)) && v21 )
    (**v21)(v21, 1i64);
  return v19;
}

// File Line: 1584
// RVA: 0x981FB0
_BOOL8 __fastcall Scaleform::Render::ShapeMeshProvider::GetData(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::MeshBase *mesh, Scaleform::Render::VertexOutput *verOut, unsigned int meshGenFlags)
{
  unsigned int v4; // er15
  Scaleform::Render::VertexOutput *v5; // r14
  Scaleform::Render::MeshBase *v6; // rdi
  Scaleform::Render::ShapeMeshProvider *v7; // rsi
  Scaleform::Render::Scale9GridInfo *v8; // rbx
  __int64 drawLayer; // rbp
  int v10; // ecx
  Scaleform::Render::Scale9GridData *v11; // rax
  Scaleform::Render::Scale9GridInfo *v12; // rax
  Scaleform::Render::Scale9GridInfo *v13; // rax
  bool v14; // al
  Scaleform::Render::Scale9GridInfo *v15; // rax
  Scaleform::Render::Scale9GridInfo *v16; // rax
  unsigned int v17; // er8
  Scaleform::Render::ShapeMeshProvider *v18; // rcx
  bool v19; // di
  Scaleform::Render::Matrix2x4<float> viewMtx; // [rsp+50h] [rbp-48h]
  Scaleform::Render::Scale9GridInfo *v22; // [rsp+A0h] [rbp+8h]

  v4 = meshGenFlags;
  v5 = verOut;
  v6 = mesh;
  v7 = this;
  v8 = 0i64;
  v22 = 0i64;
  drawLayer = mesh->Layer;
  v10 = *((_DWORD *)&this->hKeySet.pManager.Value->KeySetLock.cs.DebugInfo + 5 * drawLayer);
  v11 = mesh->pScale9Grid.pObject;
  if ( !v11 )
  {
LABEL_10:
    v17 = *((_DWORD *)&v7->hKeySet.pManager.Value->RefCount + 5 * drawLayer + 1);
    v18 = (Scaleform::Render::ShapeMeshProvider *)((char *)v7 - 16);
    if ( v17 )
      v14 = Scaleform::Render::ShapeMeshProvider::tessellateStroke(v18, v8, v17, drawLayer, v6, v5, v4);
    else
      v14 = Scaleform::Render::ShapeMeshProvider::tessellateFill(v18, v8, drawLayer, v6, v5, v4);
    goto LABEL_13;
  }
  if ( !v10 )
  {
    if ( v11 )
    {
      v15 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   448ui64,
                                                   0i64);
      if ( v15 )
      {
        Scaleform::Render::Scale9GridInfo::Scale9GridInfo(
          v15,
          v6->pScale9Grid.pObject,
          &v6->pScale9Grid.pObject->ViewMtx);
        v8 = v16;
      }
      v22 = v8;
    }
    goto LABEL_10;
  }
  v12 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               448ui64,
                                               0i64);
  if ( v12 )
  {
    *(_OWORD *)&viewMtx.M[0][0] = _xmm;
    *(__m128 *)&viewMtx.M[1][0] = _xmm;
    Scaleform::Render::Scale9GridInfo::Scale9GridInfo(v12, v6->pScale9Grid.pObject, &viewMtx);
    v8 = v13;
  }
  v22 = v8;
  v14 = Scaleform::Render::ShapeMeshProvider::generateImage9Grid(
          (Scaleform::Render::ShapeMeshProvider *)((char *)v7 - 16),
          v8,
          v6,
          v5,
          drawLayer);
LABEL_13:
  v19 = v14;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) )
    v22->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, 1u);
  return v19;
}

// File Line: 1614
// RVA: 0x9E6D70
Scaleform::Render::ComplexFill *__fastcall Scaleform::Render::ShapeMeshProvider::getComplexFill(Scaleform::Render::ShapeMeshProvider *this, unsigned int drawLayer, unsigned int fillIndex, unsigned int *imgFillStyle)
{
  unsigned int *v4; // rsi
  signed __int64 v5; // rdx
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v6; // rax
  unsigned int v7; // er9
  __int64 v8; // rdi
  unsigned int v9; // ebx
  void (__fastcall ***v10)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v11)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v12)(_QWORD, signed __int64); // rcx
  char v14; // [rsp+28h] [rbp-40h]
  __int64 v15; // [rsp+30h] [rbp-38h]
  char v16; // [rsp+38h] [rbp-30h]
  __int128 v17; // [rsp+50h] [rbp-18h]

  v4 = imgFillStyle;
  v5 = drawLayer;
  v6 = this->DrawLayers.Data.Data;
  v7 = v6[v5].StrokeStyle;
  v8 = 0i64;
  if ( v7 )
  {
    v17 = 0ui64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[5].__vecDelDtor)(
      this->pShapeData.pObject,
      v7,
      &v16);
    v11 = (void (__fastcall ***)(_QWORD, signed __int64))*((_QWORD *)&v17 + 1);
    v8 = v17;
    if ( *((_QWORD *)&v17 + 1)
      && !_InterlockedDecrement((volatile signed __int32 *)(*((_QWORD *)&v17 + 1) + 8i64))
      && v11 )
    {
      (**v11)(v11, 1i64);
    }
    v12 = (void (__fastcall ***)(_QWORD, signed __int64))v17;
    if ( (_QWORD)v17 && !_InterlockedDecrement((volatile signed __int32 *)(v17 + 8)) && v12 )
      (**v12)(v12, 1i64);
  }
  else
  {
    v9 = this->FillToStyleTable.Data.Data[fillIndex + v6[v5].StartFill];
    if ( v9 )
    {
      v15 = 0i64;
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, _QWORD, char *))this->pShapeData.pObject->vfptr[4].__vecDelDtor)(
        this->pShapeData.pObject,
        v9,
        &v14);
      v8 = v15;
      if ( v4 )
        *v4 = v9;
      v10 = (void (__fastcall ***)(_QWORD, signed __int64))v15;
      if ( v15 && !_InterlockedDecrement((volatile signed __int32 *)(v15 + 8)) && v10 )
        (**v10)(v10, 1i64);
    }
  }
  return (Scaleform::Render::ComplexFill *)v8;
}

// File Line: 1646
// RVA: 0x9E72D0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::ShapeMeshProvider::getMorphMatrix(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Matrix2x4<float> *result, unsigned int drawLayer, __int64 fillIndex)
{
  Scaleform::Render::Matrix2x4<float> *v4; // rdi
  signed __int64 v5; // r8
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rdx
  _DWORD *v9; // rcx
  __int64 v10; // rcx
  _DWORD *v11; // rcx
  void (__fastcall ***v12)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v13)(_QWORD, signed __int64); // rcx
  char v15; // [rsp+28h] [rbp-40h]
  __int64 v16; // [rsp+30h] [rbp-38h]
  char v17; // [rsp+38h] [rbp-30h]
  __int128 v18; // [rsp+50h] [rbp-18h]

  v4 = result;
  v5 = drawLayer;
  v6 = this->DrawLayers.Data.Data;
  v7 = v6[v5].StrokeStyle;
  if ( (_DWORD)v7 )
  {
    v18 = 0ui64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *, __int64, signed __int64))this->pMorphData.pObject->pMorphTo.pObject->vfptr[5].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      v7,
      &v17,
      fillIndex,
      -2i64);
    v11 = (_DWORD *)v18;
    if ( (_QWORD)v18 )
    {
      v4->M[0][0] = *(float *)(v18 + 32);
      v4->M[0][1] = (float)v11[9];
      v4->M[0][2] = (float)v11[10];
      v4->M[0][3] = (float)v11[11];
      v4->M[1][0] = (float)v11[12];
      v4->M[1][1] = (float)v11[13];
      v4->M[1][2] = (float)v11[14];
      v4->M[1][3] = (float)v11[15];
      v12 = (void (__fastcall ***)(_QWORD, signed __int64))*((_QWORD *)&v18 + 1);
      if ( *((_QWORD *)&v18 + 1)
        && !_InterlockedDecrement((volatile signed __int32 *)(*((_QWORD *)&v18 + 1) + 8i64))
        && v12 )
      {
        (**v12)(v12, 1i64);
      }
    }
    else
    {
      *(_QWORD *)&v4->M[0][0] = 1065353216i64;
      *(_QWORD *)&v4->M[0][2] = 0i64;
      v4->M[1][0] = 0.0;
      *(_QWORD *)&v4->M[1][1] = 1065353216i64;
      v4->M[1][3] = 0.0;
      v13 = (void (__fastcall ***)(_QWORD, signed __int64))*((_QWORD *)&v18 + 1);
      if ( *((_QWORD *)&v18 + 1)
        && !_InterlockedDecrement((volatile signed __int32 *)(*((_QWORD *)&v18 + 1) + 8i64))
        && v13 )
      {
        (**v13)(v13, 1i64);
      }
    }
    v10 = v18;
  }
  else
  {
    v8 = this->FillToStyleTable.Data.Data[(unsigned int)(fillIndex + v6[v5].StartFill)];
    v16 = 0i64;
    ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *, __int64, char *))this->pMorphData.pObject->pMorphTo.pObject->vfptr[4].__vecDelDtor)(
      this->pMorphData.pObject->pMorphTo.pObject,
      v8,
      &v15);
    v9 = (_DWORD *)v16;
    v4->M[0][0] = *(float *)(v16 + 32);
    v4->M[0][1] = (float)v9[9];
    v4->M[0][2] = (float)v9[10];
    v4->M[0][3] = (float)v9[11];
    v4->M[1][0] = (float)v9[12];
    v4->M[1][1] = (float)v9[13];
    v4->M[1][2] = (float)v9[14];
    v4->M[1][3] = (float)v9[15];
    v10 = v16;
  }
  if ( v10 && !_InterlockedDecrement((volatile signed __int32 *)(v10 + 8)) && v10 )
    (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
  return v4;
}

// File Line: 1670
// RVA: 0x983560
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::GetFillCount(Scaleform::Render::ShapeMeshProvider *this, unsigned int drawLayer, unsigned int meshGenFlags)
{
  return *((unsigned int *)&this->hKeySet.pManager.Value->RefCount + 5 * drawLayer);
}

// File Line: 1679
// RVA: 0x983580
void __fastcall Scaleform::Render::ShapeMeshProvider::GetFillData(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::FillData *pdata, unsigned int drawLayer, unsigned int fillIndex, unsigned int meshGenFlags)
{
  __int64 v5; // rbp
  Scaleform::Render::FillData *v6; // rdi
  Scaleform::Render::ShapeMeshProvider *v7; // r14
  Scaleform::Render::ComplexFill *v8; // rax
  Scaleform::Render::GradientData *v9; // rcx
  char v10; // bl
  __int64 v11; // rax
  Scaleform::Render::VertexFormat *v12; // rax
  Scaleform::Render::GradientData *v13; // [rsp+28h] [rbp-20h]

  v5 = drawLayer;
  v6 = pdata;
  v7 = this;
  if ( meshGenFlags & 2 )
  {
    pdata->Type = 1;
    pdata->PrimFill = 1;
    LODWORD(v13) = 0;
    pdata->FillMode.Fill = 0;
    pdata->pGradient = v13;
    pdata->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
    return;
  }
  v8 = Scaleform::Render::ShapeMeshProvider::getComplexFill(
         (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
         drawLayer,
         fillIndex,
         0i64);
  if ( !v8 )
  {
    LODWORD(v13) = 0;
    v6->Type = 3;
    v6->PrimFill = 4;
    v6->FillMode.Fill = 0;
    v6->pGradient = v13;
    goto LABEL_10;
  }
  v9 = v8->pGradient.pObject;
  if ( v9 )
  {
    v6->Type = 5;
    v6->pGradient = v9;
    v6->PrimFill = 6;
    v6->FillMode.Fill = 3;
LABEL_10:
    v12 = &Scaleform::Render::VertexXY16iCF32::Format;
    goto LABEL_11;
  }
  v10 = v8->FillMode.Fill;
  v11 = ((__int64 (*)(void))v8->pImage.pObject->vfptr[9].__vecDelDtor)();
  v6->FillMode.Fill = v10;
  v6->pGradient = (Scaleform::Render::GradientData *)v11;
  v6->Type = 4;
  v6->PrimFill = 6;
  v6->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  if ( *((_DWORD *)&v7->hKeySet.pManager.Value->KeySetLock.cs.DebugInfo + 5 * v5) && meshGenFlags & 8 )
  {
    v6->PrimFill = 11;
    v12 = &Scaleform::Render::Image9GridVertex::Format;
LABEL_11:
    v6->pVFormat = v12;
  }
}

// File Line: 1716
// RVA: 0x9D6780
void __fastcall Scaleform::Render::ShapeMeshProvider::computeImgAdjustMatrix(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Scale9GridData *s9g, unsigned int drawLayer, unsigned int imgFillStyle)
{
  unsigned int v4; // edi
  Scaleform::Render::Scale9GridData *v5; // r14
  Scaleform::Render::ShapeMeshProvider *v6; // rbx
  unsigned int v7; // er8
  char v8; // si
  int i; // eax
  float v10; // xmm9_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm8_4
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-B8h]
  float x; // [rsp+40h] [rbp-A8h]
  float y; // [rsp+44h] [rbp-A4h]
  char trans[36]; // [rsp+50h] [rbp-98h]
  __int64 v18; // [rsp+74h] [rbp-74h]
  __int64 v19; // [rsp+7Ch] [rbp-6Ch]
  __int64 v20; // [rsp+84h] [rbp-64h]
  __int64 v21; // [rsp+8Ch] [rbp-5Ch]
  int v22; // [rsp+94h] [rbp-54h]
  int v23; // [rsp+98h] [rbp-50h]
  char v24; // [rsp+9Ch] [rbp-4Ch]
  float coord; // [rsp+A0h] [rbp-48h]
  __int64 v26; // [rsp+B8h] [rbp-30h]
  Scaleform::Render::Scale9GridInfo v27; // [rsp+C8h] [rbp-20h]
  Scaleform::Render::Matrix2x4<float> *v28; // [rsp+308h] [rbp+220h]

  v26 = -2i64;
  v4 = imgFillStyle;
  v5 = s9g;
  v6 = this;
  v7 = this->DrawLayers.Data.Data[drawLayer].StartPos;
  *(_QWORD *)&trans[28] = 0i64;
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0;
  v23 = (signed int)FLOAT_1_0;
  v24 = 0;
  v8 = 1;
  bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
  *(_OWORD *)trans = _xmm;
  *(__m128 *)&trans[16] = _xmm;
  for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, char *, float *, char *))this->pShapeData.pObject->vfptr[8].__vecDelDtor)(
              this->pShapeData.pObject,
              &trans[24],
              &coord,
              &trans[32]);
        i;
        i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, char *, float *, char *))v6->pShapeData.pObject->vfptr[8].__vecDelDtor)(
              v6->pShapeData.pObject,
              &trans[24],
              &coord,
              &trans[32]) )
  {
    if ( !v8 && i == 2 )
      break;
    v8 = 0;
    if ( *(_DWORD *)&trans[32] == v4 || (_DWORD)v18 == v4 )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        v6->pShapeData.pObject,
        (Scaleform::Render::Matrix2x4<float> *)trans,
        (Scaleform::Render::ShapePosInfo *)&trans[24],
        &coord,
        &bounds);
    else
      v6->pShapeData.pObject->vfptr[10].__vecDelDtor(
        (Scaleform::RefCountImplCore *)&v6->pShapeData.pObject->vfptr,
        (unsigned int)&trans[24]);
  }
  *(_OWORD *)&v28->M[0][0] = 0x3F800000ui64;
  v28->M[1][0] = 0.0;
  *(_QWORD *)&v28->M[1][1] = 1065353216i64;
  v28->M[1][3] = 0.0;
  v10 = bounds.x1;
  v11 = bounds.x2;
  if ( bounds.x1 < bounds.x2 )
  {
    v12 = bounds.y1;
    v13 = bounds.y2;
    if ( bounds.y1 < bounds.y2 )
    {
      *(_OWORD *)trans = _xmm;
      *(__m128 *)&trans[16] = _xmm;
      Scaleform::Render::Scale9GridInfo::Scale9GridInfo(&v27, v5, (Scaleform::Render::Matrix2x4<float> *)trans);
      bounds.x1 = v10;
      bounds.y1 = v12;
      bounds.x2 = v11;
      bounds.y2 = v12;
      x = v11;
      y = v13;
      Scaleform::Render::Scale9GridInfo::Transform(&v27, &bounds.x1, &bounds.y1);
      Scaleform::Render::Scale9GridInfo::Transform(&v27, &bounds.x2, &bounds.y2);
      Scaleform::Render::Scale9GridInfo::Transform(&v27, &x, &y);
      *(float *)trans = v10;
      *(float *)&trans[4] = v12;
      *(float *)&trans[8] = v11;
      *(float *)&trans[12] = v12;
      *(float *)&trans[16] = v11;
      *(float *)&trans[20] = v13;
      Scaleform::Render::Matrix2x4<float>::SetParlToParl(v28, (const float *)trans, &bounds.x1);
    }
  }
}

// File Line: 1756
// RVA: 0x983920
void __fastcall Scaleform::Render::ShapeMeshProvider::GetFillMatrix(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::MeshBase *mesh, Scaleform::Render::Matrix2x4<float> *matrix, unsigned int drawLayer, unsigned int fillIndex, unsigned int meshGenFlags)
{
  unsigned int v6; // er12
  Scaleform::Render::Matrix2x4<float> *v7; // rbx
  Scaleform::Render::MeshBase *v8; // rsi
  Scaleform::Render::ShapeMeshProvider *v9; // r15
  Scaleform::Render::ComplexFill *v10; // rax
  Scaleform::Render::ComplexFill *v11; // r14
  float v12; // xmm6_4
  Scaleform::Render::Matrix2x4<float> *v13; // rax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  Scaleform::Render::Scale9GridData *v21; // rdx
  float v22; // xmm8_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm3_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm8_4
  float v33; // xmm7_4
  float v34; // xmm1_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  __int64 v37; // rax
  __m128 v38; // xmm7
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  Scaleform::Render::Matrix2x4<float> m; // [rsp+30h] [rbp-49h]
  Scaleform::Render::Matrix2x4<float> result; // [rsp+50h] [rbp-29h]
  unsigned int imgFillStyle; // [rsp+D0h] [rbp+57h]

  v6 = drawLayer;
  v7 = matrix;
  v8 = mesh;
  v9 = this;
  imgFillStyle = 0;
  v10 = Scaleform::Render::ShapeMeshProvider::getComplexFill(
          (Scaleform::Render::ShapeMeshProvider *)((char *)this - 16),
          drawLayer,
          fillIndex,
          &imgFillStyle);
  v11 = v10;
  if ( v10 )
  {
    v7->M[0][0] = v10->ImageMatrix.M[0][0];
    v7->M[0][1] = v10->ImageMatrix.M[0][1];
    v7->M[0][2] = v10->ImageMatrix.M[0][2];
    v7->M[0][3] = v10->ImageMatrix.M[0][3];
    v7->M[1][0] = v10->ImageMatrix.M[1][0];
    v7->M[1][1] = v10->ImageMatrix.M[1][1];
    v7->M[1][2] = v10->ImageMatrix.M[1][2];
    v7->M[1][3] = v10->ImageMatrix.M[1][3];
    if ( v9->FillToStyleTable.Data.Policy.Capacity )
    {
      v12 = v8->MorphRatio;
      if ( v12 != 0.0 )
      {
        v13 = Scaleform::Render::ShapeMeshProvider::getMorphMatrix(
                (Scaleform::Render::ShapeMeshProvider *)((char *)v9 - 16),
                &result,
                v6,
                fillIndex);
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&m, v13);
        *(_OWORD *)&result.M[0][0] = _xmm;
        *(__m128 *)&result.M[1][0] = _xmm;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&result, &v11->ImageMatrix);
        v14 = (float)((float)(m.M[1][0] - result.M[1][0]) * v12) + result.M[1][0];
        v7->M[0][0] = (float)((float)(m.M[0][0] - result.M[0][0]) * v12) + result.M[0][0];
        v15 = m.M[0][1];
        v7->M[1][0] = v14;
        v16 = (float)((float)(m.M[1][1] - result.M[1][1]) * v12) + result.M[1][1];
        v7->M[0][1] = (float)((float)(v15 - result.M[0][1]) * v12) + result.M[0][1];
        v17 = m.M[0][2] - result.M[0][2];
        v7->M[1][1] = v16;
        v18 = (float)((float)(m.M[1][2] - result.M[1][2]) * v12) + result.M[1][2];
        v7->M[0][2] = (float)(v17 * v12) + result.M[0][2];
        v19 = m.M[0][3] - result.M[0][3];
        v7->M[1][2] = v18;
        v20 = (float)((float)(m.M[1][3] - result.M[1][3]) * v12) + result.M[1][3];
        v7->M[0][3] = (float)(v19 * v12) + result.M[0][3];
        v7->M[1][3] = v20;
        Scaleform::Render::Matrix2x4<float>::Invert(v7);
      }
    }
    if ( v8 )
    {
      v21 = v8->pScale9Grid.pObject;
      if ( v21 )
      {
        *(_OWORD *)&m.M[0][0] = _xmm;
        *(__m128 *)&m.M[1][0] = _xmm;
        Scaleform::Render::ShapeMeshProvider::computeImgAdjustMatrix(
          (Scaleform::Render::ShapeMeshProvider *)((char *)v9 - 16),
          v21,
          v6,
          imgFillStyle,
          &m);
        *(_OWORD *)&result.M[0][0] = _xmm;
        *(__m128 *)&result.M[1][0] = _xmm;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&result, &m);
        v7->M[1][2] = 0.0;
        v7->M[0][2] = 0.0;
        v22 = v7->M[1][1];
        v23 = v7->M[0][0];
        v24 = v7->M[0][1];
        v25 = v24;
        v26 = v7->M[1][0];
        v27 = v24 * result.M[1][3];
        v28 = v25 * result.M[1][1];
        v29 = v7->M[1][0];
        v7->M[0][0] = (float)(v7->M[0][1] * result.M[1][0]) + (float)(v7->M[0][0] * result.M[0][0]);
        v7->M[1][0] = (float)(v22 * result.M[1][0]) + (float)(v29 * result.M[0][0]);
        v30 = v22;
        v31 = v26;
        v32 = v22 * result.M[1][3];
        v33 = v26 * result.M[0][3];
        v34 = v30 * result.M[1][1];
        v35 = (float)(v27 + (float)(v23 * result.M[0][3])) + v7->M[0][3];
        v7->M[0][1] = v28 + (float)(v23 * result.M[0][1]);
        v7->M[0][3] = v35;
        v36 = v31 * result.M[0][1];
        v7->M[1][3] = (float)(v32 + v33) + v7->M[1][3];
        v7->M[1][1] = v34 + v36;
      }
    }
    if ( v11->pImage.pObject )
    {
      v37 = ((__int64 (*)(void))v8->pRenderer2D->pHal.pObject->vfptr[61].__vecDelDtor)();
      ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, __int64))v11->pImage.pObject->vfptr[22].__vecDelDtor)(
        v11->pImage.pObject,
        &result,
        v37);
      v38 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
      v39 = _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 0),
              *(__m128 *)&v7->M[0][0]);
      v40 = _mm_shuffle_ps(*(__m128 *)&result.M[1][0], *(__m128 *)&result.M[1][0], 85);
      v41 = _mm_and_ps(
              *(__m128 *)&result.M[1][0],
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v);
      *(__m128 *)&v7->M[0][0] = _mm_and_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(*(__m128 *)&result.M[0][0], *(__m128 *)&result.M[0][0], 85),
                                        *(__m128 *)&v7->M[1][0]),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(*(__m128 *)&result.M[0][0], *(__m128 *)&result.M[0][0], 0),
                                        *(__m128 *)&v7->M[0][0])),
                                    _mm_and_ps(
                                      *(__m128 *)&result.M[0][0],
                                      (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
      *(__m128 *)&v7->M[1][0] = _mm_and_ps(
                                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v40, *(__m128 *)&v7->M[1][0]), v39), v41),
                                  v38);
    }
  }
  else
  {
    *(_QWORD *)&v7->M[0][0] = 1065353216i64;
    *(_QWORD *)&v7->M[0][2] = 0i64;
    v7->M[1][0] = 0.0;
    *(_QWORD *)&v7->M[1][1] = 1065353216i64;
    v7->M[1][3] = 0.0;
  }
}

// File Line: 1820
// RVA: 0x980370
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::GetBounds(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v3; // rbx
  Scaleform::Render::Matrix2x4<float> *v4; // rdi
  Scaleform::Render::Rect<float> *v5; // rsi
  Scaleform::Render::ShapeMeshProvider *v6; // r14
  Scaleform::Render::ShapeDataInterface *v7; // rbx
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  Scaleform::Render::ShapeDataInterface *v10; // rbx
  Scaleform::RefCountImplCoreVtbl *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  int v17; // [rsp+18h] [rbp-59h]
  int v18; // [rsp+1Ch] [rbp-55h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+28h] [rbp-49h]
  Scaleform::Render::Rect<float> bounds; // [rsp+68h] [rbp-9h]
  Scaleform::Render::Rect<float> coord; // [rsp+78h] [rbp+7h]
  float v22; // [rsp+98h] [rbp+27h]

  v3 = this->FillToStyleTable.Data.Policy.Capacity;
  v4 = m;
  v5 = result;
  v6 = this;
  if ( v3 )
  {
    v7 = (Scaleform::Render::ShapeDataInterface *)(v3 + 72);
    v8 = v7->vfptr;
    bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
    pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v8[6].__vecDelDtor)(v7);
    v9 = v7->vfptr;
    *(_QWORD *)&pos.StartX = 0i64;
    *(_QWORD *)&pos.LastX = 0i64;
    *(_QWORD *)&pos.FillBase = 0i64;
    *(_QWORD *)&pos.NumFillBits = 0i64;
    *(_QWORD *)&pos.Fill0 = 0i64;
    pos.Stroke = 0;
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
          v7->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&pos);
        else
          Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v7, v4, &pos, &coord.x1, &bounds);
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
      Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(v7, v4, &bounds);
    }
    v10 = (Scaleform::Render::ShapeDataInterface *)(v6->FillToStyleTable.Data.Policy.Capacity + 176);
    coord = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
    pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v10->vfptr[6].__vecDelDtor)(v10);
    v11 = v10->vfptr;
    *(_QWORD *)&pos.StartX = 0i64;
    *(_QWORD *)&pos.LastX = 0i64;
    *(_QWORD *)&pos.FillBase = 0i64;
    *(_QWORD *)&pos.NumFillBits = 0i64;
    *(_QWORD *)&pos.Fill0 = 0i64;
    pos.Stroke = 0;
    pos.Sfactor = 1.0;
    pos.Initialized = 0;
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v11[8].__vecDelDtor)(
           v10,
           &pos,
           &v22,
           &v17) )
    {
      do
      {
        if ( (v17 == 0) == (v18 == 0) )
          v10->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)&pos);
        else
          Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v10, v4, &pos, &v22, &coord);
      }
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, int *))v10->vfptr[8].__vecDelDtor)(
                v10,
                &pos,
                &v22,
                &v17) );
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v10->vfptr[3].__vecDelDtor)(v10) )
    {
      ((void (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v10->vfptr[7].__vecDelDtor)(v10);
      Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(v10, v4, &coord);
    }
    v12 = coord.x1;
    if ( bounds.x1 <= coord.x1 )
      v12 = bounds.x1;
    v13 = bounds.x2;
    if ( bounds.x2 <= coord.x2 )
      v13 = coord.x2;
    v14 = coord.y1;
    if ( bounds.y1 <= coord.y1 )
      v14 = bounds.y1;
    v15 = bounds.y2;
    if ( bounds.y2 <= coord.y2 )
      v15 = coord.y2;
    v5->x1 = v12;
    v5->y1 = v14;
    v5->x2 = v13;
    v5->y2 = v15;
  }
  else
  {
    Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
      result,
      (Scaleform::Render::ShapeDataInterface *)this->FillToStyleTable.Data.Size,
      m,
      0);
  }
  return v5;
}

// File Line: 1838
// RVA: 0x981740
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ShapeMeshProvider::GetCorrectBounds(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *m, float morphRatio, Scaleform::Render::StrokeGenerator *gen)
{
  Scaleform::Render::Matrix2x4<float> *v5; // rsi
  Scaleform::Render::Rect<float> *v6; // rdi
  Scaleform::Render::ShapeMeshProvider *v7; // rbx
  float v8; // eax
  Scaleform::Render::MorphShapeData *v9; // rcx
  Scaleform::Render::ShapeDataInterface *v10; // rcx
  Scaleform::Render::MorphShapeData *v11; // rcx
  Scaleform::Render::ShapeDataInterface *v12; // rcx
  int v14; // [rsp+30h] [rbp-C8h]
  int v15; // [rsp+34h] [rbp-C4h]
  int v16; // [rsp+40h] [rbp-B8h]
  int v17; // [rsp+44h] [rbp-B4h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+50h] [rbp-A8h]
  __int64 v19; // [rsp+8Ch] [rbp-6Ch]
  __int64 v20; // [rsp+94h] [rbp-64h]
  __int64 v21; // [rsp+9Ch] [rbp-5Ch]
  __int64 v22; // [rsp+A4h] [rbp-54h]
  int v23; // [rsp+ACh] [rbp-4Ch]
  int v24; // [rsp+B0h] [rbp-48h]
  char v25; // [rsp+B4h] [rbp-44h]
  Scaleform::Render::ShapePosInfo pos2; // [rsp+B8h] [rbp-40h]
  Scaleform::Render::MorphInterpolator v27; // [rsp+F8h] [rbp+0h]
  float v28; // [rsp+198h] [rbp+A0h]
  float coord; // [rsp+1B0h] [rbp+B8h]
  __int64 v30; // [rsp+1C8h] [rbp+D0h]
  Scaleform::Render::StrokeGenerator *v31; // [rsp+218h] [rbp+120h]

  v30 = -2i64;
  v5 = m;
  v6 = result;
  v7 = this;
  pos2.Pos = (*(__int64 (**)(void))(*(_QWORD *)this->FillToStyleTable.Data.Size + 48i64))();
  *(_QWORD *)&pos2.StartX = 0i64;
  *(_QWORD *)&pos2.LastX = 0i64;
  *(_QWORD *)&pos2.FillBase = 0i64;
  *(_QWORD *)&pos2.NumFillBits = 0i64;
  *(_QWORD *)&pos2.Fill0 = 0i64;
  pos2.Stroke = 0;
  pos2.Sfactor = 1.0;
  pos2.Initialized = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v27,
    (Scaleform::Render::ShapeDataInterface *)v7->FillToStyleTable.Data.Size,
    (Scaleform::Render::MorphShapeData *)v7->FillToStyleTable.Data.Policy.Capacity,
    morphRatio,
    &pos2);
  v6->x1 = 1.0e30;
  v6->y1 = 1.0e30;
  v6->x2 = -1.0e30;
  v6->y2 = -1.0e30;
  LODWORD(v8) = ((__int64 (__fastcall *)(Scaleform::Render::MorphInterpolator *))v27.vfptr[6].__vecDelDtor)(&v27);
  if ( v31 )
  {
    *(float *)&pos.Pos = v8;
    *(_QWORD *)&pos.StartX = 0i64;
    *(_QWORD *)&pos.LastX = 0i64;
    *(_QWORD *)&pos.FillBase = 0i64;
    *(_QWORD *)&pos.NumFillBits = 0i64;
    *(_QWORD *)&pos.Fill0 = 0i64;
    pos.Stroke = 0;
    pos.Fill1 = 1065353216;
    LOBYTE(pos.Stroke) = 0;
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *, Scaleform::Render::ShapePosInfo *, float *, int *))v27.vfptr[8].__vecDelDtor)(
              &v27,
              &pos,
              &coord,
              &v16) )
    {
      if ( (v16 == 0) != (v17 == 0) )
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          (Scaleform::Render::ShapeDataInterface *)&v27.vfptr,
          v5,
          &pos,
          &coord,
          v6);
      else
        v27.vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v27, (unsigned int)&pos);
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *))v27.vfptr[3].__vecDelDtor)(&v27) )
    {
      ((void (__fastcall *)(Scaleform::Render::MorphInterpolator *))v27.vfptr[7].__vecDelDtor)(&v27);
      Scaleform::Render::ExpandBoundsToStrokes<Scaleform::Render::Matrix2x4<float>>(
        (Scaleform::Render::ShapeDataInterface *)&v27.vfptr,
        v5,
        v31,
        (Scaleform::Render::ToleranceParams *)gen,
        v6);
    }
    v9 = v27.pMorphData.pObject;
    if ( v27.pMorphData.pObject && !_InterlockedDecrement(&v27.pMorphData.pObject->RefCount) && v9 )
      v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
    v10 = v27.pShapeData.pObject;
    if ( v27.pShapeData.pObject && !_InterlockedDecrement(&v27.pShapeData.pObject->RefCount) && v10 )
      v10->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, 1u);
  }
  else
  {
    pos.Sfactor = v8;
    *(_QWORD *)&pos.Initialized = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    v21 = 0i64;
    v22 = 0i64;
    v23 = 0;
    v24 = 1065353216;
    v25 = 0;
    while ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *, float *, float *, int *))v27.vfptr[8].__vecDelDtor)(
              &v27,
              &pos.Sfactor,
              &v28,
              &v14) )
    {
      if ( (v14 == 0) != (v15 == 0) )
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          (Scaleform::Render::ShapeDataInterface *)&v27.vfptr,
          v5,
          (Scaleform::Render::ShapePosInfo *)((char *)&pos + 48),
          &v28,
          v6);
      else
        v27.vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v27, (unsigned int)&pos.Sfactor);
    }
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *))v27.vfptr[3].__vecDelDtor)(&v27) )
    {
      ((void (__fastcall *)(Scaleform::Render::MorphInterpolator *))v27.vfptr[7].__vecDelDtor)(&v27);
      Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
        (Scaleform::Render::ShapeDataInterface *)&v27.vfptr,
        v5,
        v6);
    }
    v11 = v27.pMorphData.pObject;
    if ( v27.pMorphData.pObject && !_InterlockedDecrement(&v27.pMorphData.pObject->RefCount) && v11 )
      v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
    v12 = v27.pShapeData.pObject;
    if ( v27.pShapeData.pObject && !_InterlockedDecrement(&v27.pShapeData.pObject->RefCount) && v12 )
      v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
  }
  return v6;
}

// File Line: 1854
// RVA: 0x991EB0
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::HitTestShape(Scaleform::Render::ShapeMeshProvider *this, Scaleform::Render::Matrix2x4<float> *m, float x, float y, __int64 morphRatio, Scaleform::Render::StrokeGenerator *gen, Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::Matrix2x4<float> *v7; // rdi
  Scaleform::Render::ShapeMeshProvider *v8; // rbx
  Scaleform::Render::TransformerBase *v9; // rbx
  unsigned __int8 v10; // di
  char v11; // al
  Scaleform::Render::MorphShapeData *v12; // rcx
  Scaleform::Render::ShapeDataInterface *v13; // rcx
  Scaleform::Render::TransformerBase trans; // [rsp+30h] [rbp-C8h]
  Scaleform::Render::ToleranceParams *v16; // [rsp+38h] [rbp-C0h]
  void **v17; // [rsp+40h] [rbp-B8h]
  Scaleform::Render::Matrix2x4<float> *v18; // [rsp+48h] [rbp-B0h]
  Scaleform::Render::ShapePosInfo pos2; // [rsp+50h] [rbp-A8h]
  Scaleform::Render::ToleranceParams *v20; // [rsp+88h] [rbp-70h]
  void **v21; // [rsp+90h] [rbp-68h]
  Scaleform::Render::Matrix2x4<float> *v22; // [rsp+98h] [rbp-60h]
  __int64 v23; // [rsp+A0h] [rbp-58h]
  Scaleform::Render::MorphInterpolator v24; // [rsp+A8h] [rbp-50h]
  float ratio; // [rsp+198h] [rbp+A0h]

  v23 = -2i64;
  v7 = m;
  v8 = this;
  pos2.Pos = ((__int64 (*)(void))this->pShapeData.pObject->vfptr[6].__vecDelDtor)();
  *(_QWORD *)&pos2.StartX = 0i64;
  *(_QWORD *)&pos2.LastX = 0i64;
  *(_QWORD *)&pos2.FillBase = 0i64;
  *(_QWORD *)&pos2.NumFillBits = 0i64;
  *(_QWORD *)&pos2.Fill0 = 0i64;
  pos2.Stroke = 0;
  pos2.Fill1 = (unsigned int)FLOAT_1_0;
  LOBYTE(pos2.Stroke) = 0;
  Scaleform::Render::MorphInterpolator::MorphInterpolator(
    &v24,
    v8->pShapeData.pObject,
    v8->pMorphData.pObject,
    ratio,
    &pos2);
  v17 = &Scaleform::Render::TransformerWrapper<Scaleform::Render::Matrix2x4<float>>::`vftable';
  v18 = 0i64;
  trans.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerWrapper<Scaleform::Render::Scale9GridInfo>::`vftable';
  v16 = 0i64;
  if ( tol )
  {
    v20 = tol;
    v16 = tol;
    *(_QWORD *)&pos2.Sfactor = &Scaleform::Render::TransformerBase::`vftable';
    v9 = &trans;
  }
  else
  {
    v22 = v7;
    v18 = v7;
    v21 = &Scaleform::Render::TransformerBase::`vftable';
    v9 = (Scaleform::Render::TransformerBase *)&v17;
  }
  if ( !morphRatio )
  {
    v11 = Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
            (Scaleform::Render::ShapeDataInterface *)&v24.vfptr,
            v7,
            x,
            y);
    goto LABEL_11;
  }
  if ( !Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(
          (Scaleform::Render::ShapeDataInterface *)&v24.vfptr,
          v9,
          x,
          y) )
  {
    if ( !((unsigned int (__fastcall *)(Scaleform::Render::MorphInterpolator *))v24.vfptr[3].__vecDelDtor)(&v24) )
    {
      v10 = 0;
      goto LABEL_12;
    }
    ((void (__fastcall *)(Scaleform::Render::MorphInterpolator *))v24.vfptr[7].__vecDelDtor)(&v24);
    v11 = Scaleform::Render::HitTestShapeStrokes<Scaleform::Render::TransformerBase>(
            (Scaleform::Render::ShapeDataInterface *)&v24.vfptr,
            v9,
            x,
            y);
LABEL_11:
    v10 = v11;
    goto LABEL_12;
  }
  v10 = 1;
LABEL_12:
  trans.vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerBase::`vftable';
  v17 = &Scaleform::Render::TransformerBase::`vftable';
  v12 = v24.pMorphData.pObject;
  if ( v24.pMorphData.pObject && !_InterlockedDecrement(&v24.pMorphData.pObject->RefCount) && v12 )
    v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
  v13 = v24.pShapeData.pObject;
  if ( v24.pShapeData.pObject && !_InterlockedDecrement(&v24.pShapeData.pObject->RefCount) && v13 )
    v13->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, 1u);
  return v10;
}

