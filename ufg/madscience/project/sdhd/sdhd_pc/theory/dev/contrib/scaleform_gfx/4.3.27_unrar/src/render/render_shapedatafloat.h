// File Line: 93
// RVA: 0x822340
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *v5; // rcx
  char *v6; // rcx

  Data = this->Data;
  v3 = Data->Data.Size + 1;
  if ( v3 >= Data->Data.Size )
  {
    if ( v3 <= Data->Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v4);
LABEL_7:
  v5 = Data->Data.Data;
  Data->Data.Size = v3;
  v6 = &v5[v3 - 1];
  if ( v6 )
    *v6 = 0;
  this->Status = Status_StartLayer;
}

// File Line: 101
// RVA: 0x9B78D0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle)
{
  bool v4; // zf
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  char *v13; // rax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v14; // [rsp+40h] [rbp+8h] BYREF

  v4 = this->Status == Status_Clean;
  Data = this->Data;
  v14.Data = Data;
  if ( v4 )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(this);
  Size = Data->Data.Size;
  v11 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v11 > Data->Data.Policy.Capacity )
    {
      v12 = v11 + (v11 >> 2);
      goto LABEL_8;
    }
  }
  else if ( v11 < Data->Data.Policy.Capacity >> 1 )
  {
    v12 = Size + 1;
LABEL_8:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v12);
  }
  v13 = Data->Data.Data;
  Data->Data.Size = v11;
  v13[v11 - 1] = 1;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    leftStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    rightStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    strokeStyle);
  this->Status = Status_StartPath;
}

// File Line: 114
// RVA: 0x99B810
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float x,
        float y)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  char *v8; // rax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [rsp+50h] [rbp+8h] BYREF

  Data = this->Data;
  v9.Data = Data;
  Size = Data->Data.Size;
  v6 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v6 > Data->Data.Policy.Capacity )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < Data->Data.Policy.Capacity >> 1 )
  {
    v7 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v7);
  }
  v8 = Data->Data.Data;
  Data->Data.Size = v6;
  v8[v6 - 1] = 2;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    x);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    y);
  this->Status = Status_MoveTo;
  this->StartX = x;
  this->StartY = y;
  this->LastX = x;
  this->LastY = y;
}

// File Line: 126
// RVA: 0x9987B0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float x,
        float y)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  char *v8; // rax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [rsp+50h] [rbp+8h] BYREF

  Data = this->Data;
  v9.Data = Data;
  Size = Data->Data.Size;
  v6 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v6 > Data->Data.Policy.Capacity )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < Data->Data.Policy.Capacity >> 1 )
  {
    v7 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v7);
  }
  v8 = Data->Data.Data;
  Data->Data.Size = v6;
  v8[v6 - 1] = 3;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    x);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    y);
  this->Status = Status_EdgeTo;
  this->LastX = x;
  this->LastY = y;
}

// File Line: 137
// RVA: 0x9A39C0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  char *v10; // rax
  float v11; // xmm6_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v12; // [rsp+60h] [rbp+8h] BYREF

  Data = this->Data;
  v12.Data = Data;
  Size = Data->Data.Size;
  v8 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v8 > Data->Data.Policy.Capacity )
    {
      v9 = v8 + (v8 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v8 < Data->Data.Policy.Capacity >> 1 )
  {
    v9 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v9);
  }
  v10 = Data->Data.Data;
  Data->Data.Size = v8;
  v10[v8 - 1] = 4;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v12,
    cx);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v12,
    cy);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v12,
    ax);
  v11 = ay;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v12,
    ay);
  this->LastX = ax;
  this->LastY = v11;
  this->Status = Status_EdgeTo;
}

// File Line: 150
// RVA: 0x96AA00
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float cx1,
        float cy1,
        float cx2,
        float cy2,
        float ax,
        float ay)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // r8
  char *v12; // rax
  float v13; // xmm7_4
  float v14; // xmm6_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v15; // [rsp+60h] [rbp+8h] BYREF

  Data = this->Data;
  v15.Data = Data;
  Size = Data->Data.Size;
  v10 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v10 > Data->Data.Policy.Capacity )
    {
      v11 = v10 + (v10 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v10 < Data->Data.Policy.Capacity >> 1 )
  {
    v11 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v11);
  }
  v12 = Data->Data.Data;
  Data->Data.Size = v10;
  v12[v10 - 1] = 5;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v15,
    cx1);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v15,
    cy1);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v15,
    cx2);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v15,
    cy2);
  v13 = ax;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v15,
    ax);
  v14 = ay;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v15,
    ay);
  this->LastX = v13;
  this->LastY = v14;
  this->Status = Status_EdgeTo;
}

// File Line: 171
// RVA: 0x7C8FE0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *v5; // rcx
  char *v6; // rcx

  Data = this->Data;
  v3 = Data->Data.Size + 1;
  if ( v3 >= Data->Data.Size )
  {
    if ( v3 <= Data->Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= Data->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = Data->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v4);
LABEL_7:
  v5 = Data->Data.Data;
  Data->Data.Size = v3;
  v6 = &v5[v3 - 1];
  if ( v6 )
    *v6 = 6;
  this->Status = Status_EndPath;
}

// File Line: 179
// RVA: 0x970CB0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus Status; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r8
  char *v6; // rax

  Status = this->Status;
  if ( Status != Status_EndShape && Status )
  {
    if ( Status != Status_EndPath )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this);
    Data = this->Data;
    v4 = Data->Data.Size + 1;
    if ( v4 >= Data->Data.Size )
    {
      if ( v4 > Data->Data.Policy.Capacity )
      {
        v5 = v4 + (v4 >> 2);
        goto LABEL_10;
      }
    }
    else if ( v4 < Data->Data.Policy.Capacity >> 1 )
    {
      v5 = Data->Data.Size + 1;
LABEL_10:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
        this->Data,
        v5);
    }
    v6 = Data->Data.Data;
    Data->Data.Size = v4;
    v6[v4 - 1] = 7;
    this->Status = Status_EndShape;
  }
}

// File Line: 196
// RVA: 0x983D20
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *p)
{
  Scaleform::Render::FillStyleType *v4; // rbx
  Scaleform::Render::ComplexFill *pObject; // rcx
  Scaleform::Render::ComplexFill *v6; // rcx

  v4 = &this->Fills.Data.Data[idx - 1];
  p->Color = v4->Color;
  pObject = v4->pFill.pObject;
  if ( pObject )
    _InterlockedExchangeAdd(&pObject->RefCount, 1u);
  v6 = p->pFill.pObject;
  if ( !v6 || _InterlockedDecrement(&v6->RefCount) )
  {
    p->pFill.pObject = v4->pFill.pObject;
  }
  else
  {
    v6->vfptr->__vecDelDtor(v6, 1u);
    p->pFill.pObject = v4->pFill.pObject;
  }
}

// File Line: 197
// RVA: 0x7EFFB0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(p, &this->Strokes.Data.Data[idx - 1]);
}

// File Line: 198
// RVA: 0x7EFEA0
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyleCount(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  return this->StartingPos;
}

// File Line: 201
// RVA: 0x9A5AC0
__int64 __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rax
  unsigned __int64 v6; // rdx
  __int64 result; // rax
  unsigned int v10; // ebp
  char v11; // r8
  __int64 v12; // rbx
  char *v13; // rdi
  int v14; // esi
  unsigned int v15; // r9d
  unsigned int v16; // r9d
  int v17; // ecx
  int v18; // r8d
  __int64 v19; // rbx
  char *v20; // rdi
  int v21; // r9d
  int v22; // ecx
  int v23; // r8d
  __int64 v24; // rbx
  char *v25; // rdi
  int v26; // r9d
  int v27; // r8d
  __int64 v28; // r9
  __int64 v29; // r9
  char *v30; // r8
  int v31; // [rsp+20h] [rbp+8h]

  Data = this->Data;
  v6 = pos->Pos;
  if ( v6 >= Data->Data.Size )
    return 0i64;
  v10 = 1;
  v11 = Data->Data.Data[v6];
  pos->Pos = v6 + 1;
  if ( v11 == 7 )
    return 0i64;
  if ( !v11 )
  {
    v10 = 2;
    pos->Pos = v6 + 2;
  }
  v12 = pos->Pos;
  v13 = Data->Data.Data;
  v14 = 4;
  v15 = (unsigned __int8)Data->Data.Data[v12];
  if ( (Data->Data.Data[v12] & 3) != 0 )
  {
    v16 = v15 >> 2;
    if ( (Data->Data.Data[v12] & 3) == 1 )
    {
      *styles = v16 | ((unsigned __int8)v13[(unsigned int)(v12 + 1)] << 6);
      v17 = 2;
    }
    else
    {
      if ( (Data->Data.Data[v12] & 3) == 2 )
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
  v20 = Data->Data.Data;
  v21 = (unsigned __int8)Data->Data.Data[v19] >> 2;
  if ( (Data->Data.Data[v19] & 3) != 0 )
  {
    if ( (Data->Data.Data[v19] & 3) == 1 )
    {
      styles[1] = v21 | ((unsigned __int8)v20[(unsigned int)(v19 + 1)] << 6);
      v22 = 2;
    }
    else
    {
      if ( (Data->Data.Data[v19] & 3) == 2 )
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
  v25 = Data->Data.Data;
  v26 = (unsigned __int8)Data->Data.Data[v24] >> 2;
  if ( (Data->Data.Data[v24] & 3) != 0 )
  {
    if ( (Data->Data.Data[v24] & 3) == 1 )
    {
      v14 = 2;
      styles[2] = v26 | ((unsigned __int8)v25[(unsigned int)(v24 + 1)] << 6);
    }
    else
    {
      if ( (Data->Data.Data[v24] & 3) == 2 )
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
  pos->Pos += v14 + 1;
  v28 = pos->Pos;
  LOBYTE(v31) = Data->Data.Data[v28];
  BYTE1(v31) = Data->Data.Data[(unsigned int)(v28 + 1)];
  BYTE2(v31) = Data->Data.Data[(unsigned int)(v28 + 2)];
  HIBYTE(v31) = Data->Data.Data[(unsigned int)(v28 + 3)];
  *(_DWORD *)coord = v31;
  pos->Pos += 4;
  v29 = pos->Pos;
  v30 = Data->Data.Data;
  result = v10;
  LOBYTE(v31) = v30[v29];
  BYTE1(v31) = v30[(unsigned int)(v29 + 1)];
  BYTE2(v31) = v30[(unsigned int)(v29 + 2)];
  HIBYTE(v31) = v30[(unsigned int)(v29 + 3)];
  *((_DWORD *)coord + 1) = v31;
  pos->Pos += 4;
  return result;
}

// File Line: 230
// RVA: 0x80ED20
__int64 __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  __int64 v3; // r9
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // rax
  __int64 v5; // r11
  char v7; // bl
  __int64 v8; // r9
  __int64 v9; // r9
  __int64 v10; // r9
  __int64 v11; // r9
  __int64 v12; // r8
  __int64 result; // rax
  int v14; // [rsp+10h] [rbp+10h]
  int v15; // [rsp+10h] [rbp+10h]
  int v16; // [rsp+10h] [rbp+10h]

  v3 = pos->Pos;
  Data = this->Data;
  v5 = (unsigned int)(v3 + 1);
  v7 = Data->Data.Data[v3];
  pos->Pos = v5;
  if ( v7 == 6 )
    return 0i64;
  BYTE1(v14) = Data->Data.Data[(unsigned int)(v3 + 2)];
  LOBYTE(v14) = Data->Data.Data[v5];
  BYTE2(v14) = Data->Data.Data[(unsigned int)(v3 + 3)];
  HIBYTE(v14) = Data->Data.Data[(unsigned int)(v3 + 4)];
  *(_DWORD *)coord = v14;
  pos->Pos += 4;
  v8 = pos->Pos;
  BYTE1(v14) = Data->Data.Data[(unsigned int)(v8 + 1)];
  LOBYTE(v14) = Data->Data.Data[v8];
  BYTE2(v14) = Data->Data.Data[(unsigned int)(v8 + 2)];
  HIBYTE(v14) = Data->Data.Data[(unsigned int)(v8 + 3)];
  *((_DWORD *)coord + 1) = v14;
  pos->Pos += 4;
  v9 = pos->Pos;
  if ( (unsigned __int8)(v7 - 4) > 1u )
    return 1i64;
  BYTE1(v15) = Data->Data.Data[(unsigned int)(v9 + 1)];
  LOBYTE(v15) = Data->Data.Data[v9];
  BYTE2(v15) = Data->Data.Data[(unsigned int)(v9 + 2)];
  HIBYTE(v15) = Data->Data.Data[(unsigned int)(v9 + 3)];
  *((_DWORD *)coord + 2) = v15;
  pos->Pos += 4;
  v10 = pos->Pos;
  BYTE1(v15) = Data->Data.Data[(unsigned int)(v10 + 1)];
  LOBYTE(v15) = Data->Data.Data[v10];
  BYTE2(v15) = Data->Data.Data[(unsigned int)(v10 + 2)];
  HIBYTE(v15) = Data->Data.Data[(unsigned int)(v10 + 3)];
  *((_DWORD *)coord + 3) = v15;
  pos->Pos += 4;
  v11 = pos->Pos;
  if ( v7 != 5 )
    return 2i64;
  BYTE1(v16) = Data->Data.Data[(unsigned int)(v11 + 1)];
  LOBYTE(v16) = Data->Data.Data[v11];
  BYTE2(v16) = Data->Data.Data[(unsigned int)(v11 + 2)];
  HIBYTE(v16) = Data->Data.Data[(unsigned int)(v11 + 3)];
  *((_DWORD *)coord + 4) = v16;
  pos->Pos += 4;
  v12 = pos->Pos;
  LOBYTE(v16) = Data->Data.Data[v12];
  BYTE1(v16) = Data->Data.Data[(unsigned int)(v12 + 1)];
  BYTE2(v16) = Data->Data.Data[(unsigned int)(v12 + 2)];
  HIBYTE(v16) = Data->Data.Data[(unsigned int)(v12 + 3)];
  result = 3i64;
  *((_DWORD *)coord + 5) = v16;
  pos->Pos += 4;
  return result;
}

// File Line: 275
// RVA: 0x781CF0
void __fastcall Scaleform::Render::ShapeDataFloat::ShapeDataFloat(Scaleform::Render::ShapeDataFloat *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable;
  this->Status = Status_Clean;
  this->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0i64;
  this->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0i64;
  this->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0i64;
  this->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0i64;
  this->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0i64;
  this->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0i64;
  this->Data = &this->Container;
  *(_QWORD *)&this->StartingPos = 0i64;
  *(_QWORD *)&this->StartY = 0i64;
  this->LastY = 0.0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloat::`vftable;
  this->Container.Data.Data = 0i64;
  this->Container.Data.Size = 0i64;
  this->Container.Data.Policy.Capacity = 0i64;
}

