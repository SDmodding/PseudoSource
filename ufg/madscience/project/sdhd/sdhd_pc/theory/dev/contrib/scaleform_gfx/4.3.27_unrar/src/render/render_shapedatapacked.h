// File Line: 89
// RVA: 0x8FCF00
__int64 __fastcall Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
        Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  __int64 v5; // rcx
  char *Data; // rdx
  unsigned int v9; // ebp
  unsigned int v10; // ebp
  int v11; // eax
  __int64 v12; // r10
  char *v13; // r11
  int v14; // ebx
  unsigned int v15; // r8d
  unsigned int v16; // r8d
  int v17; // eax
  int v18; // edx
  __int64 v19; // r10
  char *v20; // r11
  int v21; // r8d
  int v22; // eax
  int v23; // edx
  __int64 v24; // r10
  char *v25; // r11
  int v26; // r8d
  int v27; // edx
  unsigned int SInt30; // eax
  int StartX; // edx
  int StartY; // ecx

  v5 = pos->Pos;
  Data = this->Decoder.Data->Data.Data;
  v9 = (unsigned __int8)Data[v5];
  if ( (v9 & 1) != 0 )
  {
    v10 = (v9 >> 1) | ((unsigned __int8)Data[(unsigned int)(v5 + 1)] << 7);
    v11 = 2;
  }
  else
  {
    v10 = v9 >> 1;
    v11 = 1;
  }
  pos->Pos += v11;
  v12 = pos->Pos;
  if ( v10 )
  {
    v13 = this->Decoder.Data->Data.Data;
    v14 = 4;
    v15 = (unsigned __int8)v13[v12];
    if ( (v13[v12] & 3) != 0 )
    {
      v16 = v15 >> 2;
      if ( (this->Decoder.Data->Data.Data[v12] & 3) == 1 )
      {
        *styles = v16 | ((unsigned __int8)v13[(unsigned int)(v12 + 1)] << 6);
        v17 = 2;
      }
      else
      {
        if ( (this->Decoder.Data->Data.Data[v12] & 3) == 2 )
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
    pos->Pos += v17;
    v19 = pos->Pos;
    v20 = this->Decoder.Data->Data.Data;
    v21 = (unsigned __int8)v20[v19] >> 2;
    if ( (v20[v19] & 3) != 0 )
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
    pos->Pos += v22;
    v24 = pos->Pos;
    v25 = this->Decoder.Data->Data.Data;
    v26 = (unsigned __int8)v25[v24] >> 2;
    if ( (v25[v24] & 3) != 0 )
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
    pos->Pos += v14;
    pos->Pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
                  &this->Decoder,
                  pos->Pos,
                  &pos->StartX);
    SInt30 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
               &this->Decoder,
               pos->Pos,
               &pos->StartY);
    StartX = pos->StartX;
    StartY = pos->StartY;
    pos->Pos += SInt30;
    pos->LastX = StartX;
    pos->LastY = StartY;
    *coord = (float)StartX * this->OneOverMultiplier;
    coord[1] = (float)pos->StartY * this->OneOverMultiplier;
  }
  return v10;
}

// File Line: 110
// RVA: 0x9A4E40
__int64 __fastcall Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx
  __int64 result; // rax
  int v11; // r9d
  int v12; // r8d
  float v13; // xmm1_4
  int data; // [rsp+20h] [rbp-28h] BYREF
  int v15; // [rsp+24h] [rbp-24h]
  int v16; // [rsp+28h] [rbp-20h]
  int v17; // [rsp+2Ch] [rbp-1Ch]
  int v18; // [rsp+30h] [rbp-18h]

  v6 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
         &this->Decoder,
         pos->Pos,
         &data);
  v7 = data;
  pos->Pos += v6;
  if ( !v7 )
  {
    pos->LastX += v15;
    goto LABEL_10;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    pos->LastY += v15;
    goto LABEL_10;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    pos->LastX += v15;
    pos->LastY += v16;
LABEL_10:
    result = 1i64;
    *coord = (float)pos->LastX * this->OneOverMultiplier;
    coord[1] = (float)pos->LastY * this->OneOverMultiplier;
    return result;
  }
  if ( v9 != 1 )
    return 0i64;
  v11 = pos->LastX + v17;
  result = 2i64;
  v12 = pos->LastY + v18;
  v13 = (float)(pos->LastY + v16);
  *coord = (float)(pos->LastX + v15) * this->OneOverMultiplier;
  coord[1] = v13 * this->OneOverMultiplier;
  coord[2] = (float)v11 * this->OneOverMultiplier;
  coord[3] = (float)v12 * this->OneOverMultiplier;
  pos->LastX = v11;
  pos->LastY = v12;
  return result;
}

// File Line: 369
// RVA: 0x8B0EC0
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::FillStyleType *fill)
{
  Scaleform::Render::FillStyleType *v4; // rbx
  Scaleform::Render::ComplexFill *pObject; // rcx

  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->FillStyles.Data,
    &this->FillStyles,
    this->FillStyles.Data.Size + 1);
  v4 = &this->FillStyles.Data.Data[this->FillStyles.Data.Size - 1];
  if ( v4 )
  {
    v4->Color = fill->Color;
    pObject = fill->pFill.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
    v4->pFill.pObject = fill->pFill.pObject;
  }
  return LODWORD(this->FillStyles.Data.Size);
}

// File Line: 373
// RVA: 0x8B2F00
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::StrokeStyleType *stroke)
{
  Scaleform::Render::StrokeStyleType *v4; // rcx

  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->StrokeStyles.Data,
    &this->StrokeStyles,
    this->StrokeStyles.Data.Size + 1);
  v4 = &this->StrokeStyles.Data.Data[this->StrokeStyles.Data.Size - 1];
  if ( v4 )
    Scaleform::Render::StrokeStyleType::StrokeStyleType(v4, stroke);
  return LODWORD(this->StrokeStyles.Data.Size);
}

// File Line: 388
// RVA: 0x9B79A0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int type,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle,
        float startX,
        float startY)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rax
  float v10; // xmm6_4
  int v12; // edx
  int v13; // edx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v14; // [rsp+20h] [rbp-28h] BYREF
  float Multiplier; // [rsp+28h] [rbp-20h]

  pContainer = this->pContainer;
  Multiplier = this->Multiplier;
  v10 = Multiplier;
  v14.Data = pContainer;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
    &v14,
    type);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    leftStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    rightStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    strokeStyle);
  v12 = (int)(float)(v10 * startX);
  pos->LastX = v12;
  pos->StartX = v12;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
    &v14,
    v12);
  v13 = (int)(float)(v10 * startY);
  pos->LastY = v13;
  pos->StartY = v13;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
    &v14,
    v13);
}

// File Line: 394
// RVA: 0x8E8180
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float x,
        float y)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rax
  int v6; // edi
  int v7; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v8; // [rsp+20h] [rbp-18h] BYREF
  float Multiplier; // [rsp+28h] [rbp-10h]

  pContainer = this->pContainer;
  Multiplier = this->Multiplier;
  v8.Data = pContainer;
  v6 = (int)(float)(Multiplier * x) - pos->LastX;
  v7 = (int)(float)(Multiplier * y) - pos->LastY;
  if ( v7 )
  {
    if ( v6 )
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
        &v8,
        v6,
        v7);
    else
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
        &v8,
        v7);
  }
  else
  {
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
      &v8,
      v6);
  }
  pos->LastX += v6;
  pos->LastY += v7;
}

// File Line: 400
// RVA: 0x8F56F0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rax
  int v8; // edi
  int v9; // ebx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v10; // [rsp+30h] [rbp-18h] BYREF
  float Multiplier; // [rsp+38h] [rbp-10h]

  pContainer = this->pContainer;
  Multiplier = this->Multiplier;
  v10.Data = pContainer;
  v8 = (int)(float)(Multiplier * ax) - pos->LastX;
  v9 = (int)(float)(Multiplier * ay) - pos->LastY;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
    &v10,
    (int)(float)(Multiplier * cx) - pos->LastX,
    (int)(float)(Multiplier * cy) - pos->LastY,
    v8,
    v9);
  pos->LastX += v8;
  pos->LastY += v9;
}

// File Line: 406
// RVA: 0x9613F0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rax
  float Multiplier; // xmm0_4
  int StartX; // edi
  int LastX; // ecx
  int v7; // edi
  int v8; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [rsp+20h] [rbp-18h] BYREF
  float v10; // [rsp+28h] [rbp-10h]

  pContainer = this->pContainer;
  Multiplier = this->Multiplier;
  StartX = pos->StartX;
  LastX = pos->LastX;
  v10 = Multiplier;
  v9.Data = pContainer;
  if ( __PAIR64__(pos->LastY, LastX) != __PAIR64__(pos->StartY, StartX) )
  {
    v7 = StartX - LastX;
    v8 = pos->StartY - pos->LastY;
    if ( v8 )
    {
      if ( v7 )
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
          &v9,
          v7,
          v8);
      else
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
          &v9,
          v8);
    }
    else
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
        &v9,
        v7);
    }
    pos->LastX += v7;
    pos->LastY += v8;
  }
}

// File Line: 412
// RVA: 0x970BC0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *Data; // rax

  pContainer = this->pContainer;
  Size = pContainer->Data.Size;
  v3 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v3 > pContainer->Data.Policy.Capacity )
    {
      v4 = v3 + (v3 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v3 < pContainer->Data.Policy.Capacity >> 1 )
  {
    v4 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->pContainer,
      this->pContainer,
      v4);
  }
  Data = pContainer->Data.Data;
  pContainer->Data.Size = v3;
  Data[v3 - 1] = 15;
}

// File Line: 418
// RVA: 0x970D40
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *Data; // rax

  pContainer = this->pContainer;
  Size = pContainer->Data.Size;
  v3 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v3 > pContainer->Data.Policy.Capacity )
    {
      v4 = v3 + (v3 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v3 < pContainer->Data.Policy.Capacity >> 1 )
  {
    v4 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->pContainer,
      this->pContainer,
      v4);
  }
  Data = pContainer->Data.Data;
  pContainer->Data.Size = v3;
  Data[v3 - 1] = 0;
}

// File Line: 422
// RVA: 0x9976D0
bool __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::IsEmpty(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rdx

  pContainer = this->pContainer;
  return !pContainer || pContainer->Data.Size <= this->StartingPos;
}

// File Line: 428
// RVA: 0x8D7D10
__int64 __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyleCount(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  return LODWORD(this->Strokes.Data.Size);
}

// File Line: 439
// RVA: 0x983DA0
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *p)
{
  Scaleform::Render::ComplexFill *v4; // rcx
  Scaleform::Render::ComplexFill *v5; // rax
  Scaleform::Render::FillStyleType *v6; // rdi
  Scaleform::Render::ComplexFill *pObject; // rcx
  Scaleform::Render::ComplexFill *v8; // rcx

  if ( idx <= this->FillStyles.Data.Size )
  {
    v6 = &this->FillStyles.Data.Data[idx - 1];
    p->Color = v6->Color;
    pObject = v6->pFill.pObject;
    if ( pObject )
      _InterlockedExchangeAdd(&pObject->RefCount, 1u);
    v8 = p->pFill.pObject;
    if ( v8 && !_InterlockedDecrement(&v8->RefCount) )
      v8->vfptr->__vecDelDtor(v8, 1u);
    v5 = v6->pFill.pObject;
  }
  else
  {
    if ( (`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::`local static guard & 1) == 0 )
    {
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::`local static guard |= 1u;
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.Color = 0;
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject = 0i64;
      atexit(`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::`dynamic atexit destructor for defaultFillStyle);
    }
    p->Color = `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.Color;
    if ( `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject )
      _InterlockedExchangeAdd(
        &`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject->RefCount,
        1u);
    v4 = p->pFill.pObject;
    if ( v4 && !_InterlockedDecrement(&v4->RefCount) )
      v4->vfptr->__vecDelDtor(v4, 1u);
    v5 = `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle::`5::defaultFillStyle.pFill.pObject;
  }
  p->pFill.pObject = v5;
}

// File Line: 453
// RVA: 0x8DE630
void __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::Renderer2D *pObject; // rax
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::DashArray *v6; // rax
  Scaleform::Render::RenderBuffer *v7; // rcx

  if ( idx <= this->StrokeStyles.Data.Size )
  {
    Scaleform::Render::StrokeStyleType::operator=(p, &this->StrokeStyles.Data.Data[idx - 1]);
  }
  else
  {
    if ( (`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::`local static guard & 1) == 0 )
    {
      `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::`local static guard |= 1u;
      *(_QWORD *)&`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::defaultStrokeStyle.Width = 0i64;
      unk_142441120 = 0i64;
      unk_142441128 = 0;
      stru_142441130.pObject = 0i64;
      unk_142441138 = 0i64;
      atexit(`Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::`dynamic atexit destructor for defaultStrokeStyle);
    }
    p->Width = `Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle::`5::defaultStrokeStyle.Width;
    LODWORD(p->Units) = unk_14244111C;
    p->Flags = unk_142441120;
    LODWORD(p->Miter) = unk_142441124;
    p->Color = unk_142441128;
    pObject = stru_142441130.pObject;
    if ( stru_142441130.pObject )
    {
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)stru_142441130.pObject);
      pObject = stru_142441130.pObject;
    }
    v5 = (Scaleform::Render::RenderBuffer *)p->pFill.pObject;
    if ( v5 )
    {
      Scaleform::RefCountImpl::Release(v5);
      pObject = stru_142441130.pObject;
    }
    p->pFill.pObject = (Scaleform::Render::ComplexFill *)pObject;
    v6 = (Scaleform::Render::DashArray *)unk_142441138;
    if ( unk_142441138 )
    {
      Scaleform::Render::RenderBuffer::AddRef(unk_142441138);
      v6 = (Scaleform::Render::DashArray *)unk_142441138;
    }
    v7 = (Scaleform::Render::RenderBuffer *)p->pDashes.pObject;
    if ( v7 )
    {
      Scaleform::RefCountImpl::Release(v7);
      v6 = (Scaleform::Render::DashArray *)unk_142441138;
    }
    p->pDashes.pObject = v6;
  }
}

// File Line: 479
// RVA: 0x8FCEF0
Scaleform::Render::ShapePathType __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  return Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
           &this->Decoder,
           pos,
           coord,
           styles);
}

// File Line: 487
// RVA: 0x9A4E30
Scaleform::Render::PathEdgeType __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  return Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
           &this->Decoder,
           pos,
           coord);
}

