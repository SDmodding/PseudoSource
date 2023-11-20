// File Line: 89
// RVA: 0x8FCF00
__int64 __fastcall Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float *coord, unsigned int *styles)
{
  Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v4; // r14
  __int64 v5; // rcx
  Scaleform::Render::ShapePosInfo *v6; // rsi
  float *v7; // r15
  char *v8; // rdx
  unsigned int v9; // ebp
  unsigned int v10; // ebp
  signed int v11; // eax
  __int64 v12; // r10
  char *v13; // r11
  signed int v14; // ebx
  unsigned int v15; // er8
  unsigned int v16; // er8
  signed int v17; // eax
  int v18; // edx
  __int64 v19; // r10
  char *v20; // r11
  unsigned int v21; // er8
  signed int v22; // eax
  int v23; // edx
  __int64 v24; // r10
  char *v25; // r11
  unsigned int v26; // er8
  int v27; // edx
  unsigned int v28; // eax
  signed int v29; // edx
  int v30; // ecx

  v4 = this;
  v5 = pos->Pos;
  v6 = pos;
  v7 = coord;
  v8 = v4->Decoder.Data->Data.Data;
  v9 = (unsigned __int8)v8[v5];
  if ( v9 & 1 )
  {
    v10 = (v9 >> 1) | ((unsigned __int8)v8[(unsigned int)(v5 + 1)] << 7);
    v11 = 2;
  }
  else
  {
    v10 = v9 >> 1;
    v11 = 1;
  }
  v6->Pos += v11;
  v12 = v6->Pos;
  if ( v10 )
  {
    v13 = v4->Decoder.Data->Data.Data;
    v14 = 4;
    v15 = (unsigned __int8)v4->Decoder.Data->Data.Data[v12];
    if ( v4->Decoder.Data->Data.Data[v12] & 3 )
    {
      v16 = v15 >> 2;
      if ( (v4->Decoder.Data->Data.Data[v12] & 3) == 1 )
      {
        *styles = v16 | ((unsigned __int8)v13[(unsigned int)(v12 + 1)] << 6);
        v17 = 2;
      }
      else
      {
        if ( (v4->Decoder.Data->Data.Data[v12] & 3) == 2 )
        {
          v17 = 3;
          v18 = v16 | (((unsigned __int8)v13[(unsigned int)(v12 + 1)] | ((unsigned __int8)v13[(unsigned int)(v12 + 2)] << 8)) << 6);
        }
        else
        {
          v17 = 4;
          v18 = v16 | (((unsigned __int8)v13[(unsigned int)(v12 + 1)] | (((unsigned __int8)v13[(unsigned int)(v12 + 2)] | ((unsigned __int8)v13[(unsigned int)(v12 + 3)] << 8)) << 8)) << 6);
        }
        *styles = v18;
      }
    }
    else
    {
      v17 = 1;
      *styles = v15 >> 2;
    }
    v6->Pos += v17;
    v19 = v6->Pos;
    v20 = v4->Decoder.Data->Data.Data;
    v21 = (unsigned int)(unsigned __int8)v20[v19] >> 2;
    if ( v20[v19] & 3 )
    {
      if ( (v20[v19] & 3) == 1 )
      {
        styles[1] = v21 | ((unsigned __int8)v20[(unsigned int)(v19 + 1)] << 6);
        v22 = 2;
      }
      else
      {
        if ( (v20[v19] & 3) == 2 )
        {
          v22 = 3;
          v23 = v21 | (((unsigned __int8)v20[(unsigned int)(v19 + 1)] | ((unsigned __int8)v20[(unsigned int)(v19 + 2)] << 8)) << 6);
        }
        else
        {
          v22 = 4;
          v23 = v21 | (((unsigned __int8)v20[(unsigned int)(v19 + 1)] | (((unsigned __int8)v20[(unsigned int)(v19 + 2)] | ((unsigned __int8)v20[(unsigned int)(v19 + 3)] << 8)) << 8)) << 6);
        }
        styles[1] = v23;
      }
    }
    else
    {
      styles[1] = v21;
      v22 = 1;
    }
    v6->Pos += v22;
    v24 = v6->Pos;
    v25 = v4->Decoder.Data->Data.Data;
    v26 = (unsigned int)(unsigned __int8)v25[v24] >> 2;
    if ( v25[v24] & 3 )
    {
      if ( (v25[v24] & 3) == 1 )
      {
        v14 = 2;
        styles[2] = v26 | ((unsigned __int8)v25[(unsigned int)(v24 + 1)] << 6);
      }
      else
      {
        if ( (v25[v24] & 3) == 2 )
        {
          v14 = 3;
          v27 = v26 | (((unsigned __int8)v25[(unsigned int)(v24 + 1)] | ((unsigned __int8)v25[(unsigned int)(v24 + 2)] << 8)) << 6);
        }
        else
        {
          v27 = v26 | (((unsigned __int8)v25[(unsigned int)(v24 + 1)] | (((unsigned __int8)v25[(unsigned int)(v24 + 2)] | ((unsigned __int8)v25[(unsigned int)(v24 + 3)] << 8)) << 8)) << 6);
        }
        styles[2] = v27;
      }
    }
    else
    {
      styles[2] = v26;
      v14 = 1;
    }
    v6->Pos += v14;
    v6->Pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
                 &v4->Decoder,
                 v6->Pos,
                 &v6->StartX);
    v28 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
            &v4->Decoder,
            v6->Pos,
            &v6->StartY);
    v29 = v6->StartX;
    v30 = v6->StartY;
    v6->Pos += v28;
    v6->LastX = v29;
    v6->LastY = v30;
    *v7 = (float)v29 * v4->OneOverMultiplier;
    v7[1] = (float)v6->StartY * v4->OneOverMultiplier;
  }
  return v10;
}

// File Line: 110
// RVA: 0x9A4E40
signed __int64 __fastcall Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float *coord)
{
  Scaleform::Render::ShapePosInfo *v3; // rbx
  float *v4; // rsi
  Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v5; // rdi
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx
  signed __int64 result; // rax
  int v11; // er9
  int v12; // er8
  float v13; // xmm1_4
  int data; // [rsp+20h] [rbp-28h]
  int v15; // [rsp+24h] [rbp-24h]
  int v16; // [rsp+28h] [rbp-20h]
  int v17; // [rsp+2Ch] [rbp-1Ch]
  int v18; // [rsp+30h] [rbp-18h]

  v3 = pos;
  v4 = coord;
  v5 = this;
  v6 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
         &this->Decoder,
         pos->Pos,
         &data);
  v7 = data;
  v3->Pos += v6;
  if ( !v7 )
  {
    v3->LastX += v15;
    goto LABEL_10;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    v3->LastY += v15;
    goto LABEL_10;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v3->LastX += v15;
    v3->LastY += v16;
LABEL_10:
    result = 1i64;
    *v4 = (float)v3->LastX * v5->OneOverMultiplier;
    v4[1] = (float)v3->LastY * v5->OneOverMultiplier;
    return result;
  }
  if ( v9 != 1 )
    return 0i64;
  v11 = v3->LastX + v17;
  result = 2i64;
  v12 = v3->LastY + v18;
  v13 = (float)(v3->LastY + v16);
  *v4 = (float)(v3->LastX + v15) * v5->OneOverMultiplier;
  v4[1] = v13 * v5->OneOverMultiplier;
  v4[2] = (float)v11 * v5->OneOverMultiplier;
  v4[3] = (float)v12 * v5->OneOverMultiplier;
  v3->LastX = v11;
  v3->LastY = v12;
  return result;
}

// File Line: 369
// RVA: 0x8B0EC0
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::FillStyleType *fill)
{
  Scaleform::Render::FillStyleType *v2; // rdi
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v3; // rsi
  signed __int64 v4; // rbx
  Scaleform::GFx::Resource *v5; // rcx

  v2 = fill;
  v3 = this;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillStyles.Data.Data,
    &this->FillStyles,
    this->FillStyles.Data.Size + 1);
  v4 = (signed __int64)&v3->FillStyles.Data.Data[v3->FillStyles.Data.Size - 1];
  if ( v4 )
  {
    *(_DWORD *)v4 = v2->Color;
    v5 = (Scaleform::GFx::Resource *)v2->pFill.pObject;
    if ( v5 )
      Scaleform::Render::RenderBuffer::AddRef(v5);
    *(_QWORD *)(v4 + 8) = v2->pFill.pObject;
  }
  return LODWORD(v3->FillStyles.Data.Size);
}

// File Line: 373
// RVA: 0x8B2F00
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::StrokeStyleType *stroke)
{
  Scaleform::Render::StrokeStyleType *v2; // rsi
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v3; // rdi
  Scaleform::Render::StrokeStyleType *v4; // rcx

  v2 = stroke;
  v3 = this;
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy> *)&this->StrokeStyles.Data.Data,
    &this->StrokeStyles,
    this->StrokeStyles.Data.Size + 1);
  v4 = (Scaleform::Render::StrokeStyleType *)((char *)v3->StrokeStyles.Data.Data
                                            + 8 * (5 * v3->StrokeStyles.Data.Size - 5));
  if ( v4 )
    Scaleform::Render::StrokeStyleType::StrokeStyleType(v4, v2);
  return LODWORD(v3->StrokeStyles.Data.Size);
}

// File Line: 388
// RVA: 0x9B79A0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, Scaleform::Render::ShapePathType type, unsigned int leftStyle, unsigned int rightStyle, unsigned int strokeStyle, float startX, float startY)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::Render::ShapePosInfo *v9; // rdi
  float v10; // xmm6_4
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // edx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v14; // [rsp+20h] [rbp-28h]
  float v15; // [rsp+28h] [rbp-20h]

  v8 = this->pContainer;
  v9 = pos;
  v15 = this->Multiplier;
  v10 = v15;
  v14.Data = v8;
  v11 = leftStyle;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
    &v14,
    type);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    v11);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    rightStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    strokeStyle);
  v12 = (signed int)(float)(v10 * startX);
  v9->LastX = v12;
  v9->StartX = v12;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
    &v14,
    v12);
  v13 = (signed int)(float)(v10 * startY);
  v9->LastY = v13;
  v9->StartY = v13;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
    &v14,
    v13);
}

// File Line: 394
// RVA: 0x8E8180
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float x, float y)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::Render::ShapePosInfo *v5; // rbx
  int v6; // edi
  int v7; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v8; // [rsp+20h] [rbp-18h]
  float v9; // [rsp+28h] [rbp-10h]

  v4 = this->pContainer;
  v5 = pos;
  v9 = this->Multiplier;
  v8.Data = v4;
  v6 = (signed int)(float)(v9 * x) - pos->LastX;
  v7 = (signed int)(float)(v9 * y) - pos->LastY;
  if ( (signed int)(float)(v9 * y) == pos->LastY )
  {
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
      &v8,
      v6);
  }
  else if ( (signed int)(float)(v9 * x) == pos->LastX )
  {
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
      &v8,
      v7);
  }
  else
  {
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
      &v8,
      v6,
      v7);
  }
  v5->LastX += v6;
  v5->LastY += v7;
}

// File Line: 400
// RVA: 0x8F56F0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float cx, float cy, float ax, float ay)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // rax
  Scaleform::Render::ShapePosInfo *v7; // rsi
  int v8; // edi
  int v9; // ebx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v10; // [rsp+30h] [rbp-18h]
  float v11; // [rsp+38h] [rbp-10h]

  v6 = this->pContainer;
  v7 = pos;
  v11 = this->Multiplier;
  v10.Data = v6;
  v8 = (signed int)(float)(v11 * ax) - pos->LastX;
  v9 = (signed int)(float)(v11 * ay) - pos->LastY;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
    &v10,
    (signed int)(float)(v11 * cx) - pos->LastX,
    (signed int)(float)(v11 * cy) - pos->LastY,
    v8,
    v9);
  v7->LastX += v8;
  v7->LastY += v9;
}

// File Line: 406
// RVA: 0x9613F0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rax
  float v3; // xmm0_4
  int v4; // edi
  int v5; // ecx
  Scaleform::Render::ShapePosInfo *v6; // rbx
  int v7; // edi
  int v8; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [rsp+20h] [rbp-18h]
  float v10; // [rsp+28h] [rbp-10h]

  v2 = this->pContainer;
  v3 = this->Multiplier;
  v4 = pos->StartX;
  v5 = pos->LastX;
  v6 = pos;
  v10 = v3;
  v9.Data = v2;
  if ( v5 != v4 || pos->LastY != pos->StartY )
  {
    v7 = v4 - v5;
    v8 = pos->StartY - pos->LastY;
    if ( pos->StartY == pos->LastY )
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
        &v9,
        v7);
    }
    else if ( v7 )
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
        &v9,
        v7,
        v8);
    }
    else
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
        &v9,
        v8);
    }
    v6->LastX += v7;
    v6->LastY += v8;
  }
}

// File Line: 412
// RVA: 0x970BC0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *v5; // rax

  v1 = this->pContainer;
  v2 = v1->Data.Size;
  v3 = v2 + 1;
  if ( v2 + 1 >= v2 )
  {
    if ( v3 > v1->Data.Policy.Capacity )
    {
      v4 = v3 + (v3 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v3 < v1->Data.Policy.Capacity >> 1 )
  {
    v4 = v2 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->pContainer,
      this->pContainer,
      v4);
    goto LABEL_7;
  }
LABEL_7:
  v5 = v1->Data.Data;
  v1->Data.Size = v3;
  v5[v3 - 1] = 15;
}

// File Line: 418
// RVA: 0x970D40
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *v5; // rax

  v1 = this->pContainer;
  v2 = v1->Data.Size;
  v3 = v2 + 1;
  if ( v2 + 1 >= v2 )
  {
    if ( v3 > v1->Data.Policy.Capacity )
    {
      v4 = v3 + (v3 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v3 < v1->Data.Policy.Capacity >> 1 )
  {
    v4 = v2 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->pContainer,
      this->pContainer,
      v4);
    goto LABEL_7;
  }
LABEL_7:
  v5 = v1->Data.Data;
  v1->Data.Size = v3;
  v5[v3 - 1] = 0;
}

// File Line: 422
// RVA: 0x9976D0
bool __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::IsEmpty(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rdx

  v1 = this->pContainer;
  return !v1 || v1->Data.Size <= this->StartingPos;
}

// File Line: 428
// RVA: 0x8D7D10
__int64 __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyleCount(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  return LODWORD(this->Strokes.Data.Size);
}

// File Line: 439
// RVA: 0x983DA0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int idx, Scaleform::Render::FillStyleType *p)
{
  Scaleform::Render::FillStyleType *v3; // rbx
  Scaleform::Render::ComplexFill *v4; // rcx
  Scaleform::Render::ComplexFill *v5; // rax
  Scaleform::Render::FillStyleType *v6; // rdi
  Scaleform::Render::ComplexFill *v7; // rcx
  Scaleform::Render::ComplexFill *v8; // rcx

  v3 = p;
  if ( idx <= this->FillStyles.Data.Size )
  {
    v6 = &this->FillStyles.Data.Data[idx - 1];
    p->Color = v6->Color;
    v7 = v6->pFill.pObject;
    if ( v7 )
      _InterlockedExchangeAdd(&v7->RefCount, 1u);
    v8 = p->pFill.pObject;
    if ( v8 && !_InterlockedDecrement(&v8->RefCount) && v8 )
      v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
    v5 = v6->pFill.pObject;
  }
  else
  {
    if ( !(`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::`local static guard & 1) )
    {
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::`local static guard |= 1u;
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.Color = 0;
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject = 0i64;
      atexit(`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::`dynamic atexit destructor for defaultFillStyle);
    }
    v3->Color = `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.Color;
    if ( `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject )
      _InterlockedExchangeAdd(
        &`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject->RefCount,
        1u);
    v4 = v3->pFill.pObject;
    if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v5 = `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject;
  }
  v3->pFill.pObject = v5;
}

// File Line: 453
// RVA: 0x8DE630
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int idx, Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType *v3; // rbx
  Scaleform::Render::Renderer2D *v4; // rax
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::GFx::Resource *v6; // rax
  Scaleform::Render::RenderBuffer *v7; // rcx

  v3 = p;
  if ( idx <= this->StrokeStyles.Data.Size )
  {
    Scaleform::Render::StrokeStyleType::operator=(p, &this->StrokeStyles.Data.Data[idx - 1]);
  }
  else
  {
    if ( !(`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::`local static guard & 1) )
    {
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::`local static guard |= 1u;
      *(_QWORD *)&`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::defaultStrokeStyle.Width = 0i64;
      *(_QWORD *)&dword_142441120 = 0i64;
      unk_142441128 = 0;
      stru_142441130.pObject = 0i64;
      unk_142441138 = 0i64;
      atexit(`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::`dynamic atexit destructor for defaultStrokeStyle);
    }
    v3->Width = `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::defaultStrokeStyle.Width;
    LODWORD(v3->Units) = unk_14244111C;
    v3->Flags = dword_142441120;
    LODWORD(v3->Miter) = unk_142441124;
    v3->Color = unk_142441128;
    v4 = stru_142441130.pObject;
    if ( stru_142441130.pObject )
    {
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)stru_142441130.pObject);
      v4 = stru_142441130.pObject;
    }
    v5 = (Scaleform::Render::RenderBuffer *)v3->pFill.pObject;
    if ( v5 )
    {
      Scaleform::RefCountImpl::Release(v5);
      v4 = stru_142441130.pObject;
    }
    v3->pFill.pObject = (Scaleform::Render::ComplexFill *)v4;
    v6 = unk_142441138;
    if ( unk_142441138 )
    {
      Scaleform::Render::RenderBuffer::AddRef(unk_142441138);
      v6 = unk_142441138;
    }
    v7 = (Scaleform::Render::RenderBuffer *)v3->pDashes.pObject;
    if ( v7 )
    {
      Scaleform::RefCountImpl::Release(v7);
      v6 = unk_142441138;
    }
    v3->pDashes.pObject = (Scaleform::Render::DashArray *)v6;
  }
}

// File Line: 479
// RVA: 0x8FCEF0
Scaleform::Render::ShapePathType __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float *coord, unsigned int *styles)
{
  return Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
           &this->Decoder,
           pos,
           coord,
           styles);
}

// File Line: 487
// RVA: 0x9A4E30
Scaleform::Render::PathEdgeType __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float *coord)
{
  return Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
           &this->Decoder,
           pos,
           coord);
}

