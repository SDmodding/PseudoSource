// File Line: 93
// RVA: 0x822340
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v2; // rsi
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *v5; // rcx
  char *v6; // rcx

  v1 = this->Data;
  v2 = this;
  v3 = v1->Data.Size + 1;
  if ( v3 >= v1->Data.Size )
  {
    if ( v3 <= v1->Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= v1->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = v1->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v4);
LABEL_7:
  v5 = v1->Data.Data;
  v1->Data.Size = v3;
  v6 = &v5[v3 - 1];
  if ( v6 )
    *v6 = 0;
  v2->Status = 1;
}

// File Line: 101
// RVA: 0x9B78D0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int leftStyle, unsigned int rightStyle, unsigned int strokeStyle)
{
  bool v4; // zf
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  unsigned int v6; // ebp
  unsigned int v7; // er14
  unsigned int v8; // er15
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v9; // rsi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  bool *v13; // rax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v14; // [rsp+40h] [rbp+8h]

  v4 = this->Status == 0;
  v5 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v6 = strokeStyle;
  v7 = rightStyle;
  v8 = leftStyle;
  v9 = this;
  v14.Data = this->Data;
  if ( v4 )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(this);
  v10 = v5->Size;
  v11 = v10 + 1;
  if ( v10 + 1 >= v10 )
  {
    if ( v11 > v5->Policy.Capacity )
    {
      v12 = v11 + (v11 >> 2);
      goto LABEL_8;
    }
  }
  else if ( v11 < v5->Policy.Capacity >> 1 )
  {
    v12 = v10 + 1;
LABEL_8:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v5, v5, v12);
    goto LABEL_9;
  }
LABEL_9:
  v13 = v5->Data;
  v5->Size = v11;
  v13[v11 - 1] = 1;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    v8);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    v7);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &v14,
    v6);
  v9->Status = 2;
}

// File Line: 114
// RVA: 0x99B810
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, float x, float y)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v4; // rsi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  char *v8; // rax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [rsp+50h] [rbp+8h]

  v3 = this->Data;
  v4 = this;
  v9.Data = v3;
  v5 = v3->Data.Size;
  v6 = v5 + 1;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 > v3->Data.Policy.Capacity )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < v3->Data.Policy.Capacity >> 1 )
  {
    v7 = v5 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v3,
      v3,
      v7);
    goto LABEL_7;
  }
LABEL_7:
  v8 = v3->Data.Data;
  v3->Data.Size = v6;
  v8[v6 - 1] = 2;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    x);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    y);
  v4->Status = 3;
  v4->StartX = x;
  v4->StartY = y;
  v4->LastX = x;
  v4->LastY = y;
}

// File Line: 126
// RVA: 0x9987B0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, float x, float y)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v4; // rsi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  char *v8; // rax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [rsp+50h] [rbp+8h]

  v3 = this->Data;
  v4 = this;
  v9.Data = v3;
  v5 = v3->Data.Size;
  v6 = v5 + 1;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 > v3->Data.Policy.Capacity )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < v3->Data.Policy.Capacity >> 1 )
  {
    v7 = v5 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v3,
      v3,
      v7);
    goto LABEL_7;
  }
LABEL_7:
  v8 = v3->Data.Data;
  v3->Data.Size = v6;
  v8[v6 - 1] = 3;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    x);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &v9,
    y);
  v4->Status = 4;
  v4->LastX = x;
  v4->LastY = y;
}

// File Line: 137
// RVA: 0x9A39C0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, float cx, float cy, float ax, float ay)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v6; // rsi
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r8
  char *v10; // rax
  float v11; // xmm6_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v12; // [rsp+60h] [rbp+8h]

  v5 = this->Data;
  v6 = this;
  v12.Data = v5;
  v7 = v5->Data.Size;
  v8 = v7 + 1;
  if ( v7 + 1 >= v7 )
  {
    if ( v8 > v5->Data.Policy.Capacity )
    {
      v9 = v8 + (v8 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v8 < v5->Data.Policy.Capacity >> 1 )
  {
    v9 = v7 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v5,
      v5,
      v9);
    goto LABEL_7;
  }
LABEL_7:
  v10 = v5->Data.Data;
  v5->Data.Size = v8;
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
  v6->LastX = ax;
  v6->LastY = v11;
  v6->Status = 4;
}

// File Line: 150
// RVA: 0x96AA00
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, float cx1, float cy1, float cx2, float cy2, float ax, float ay)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v7; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v8; // rsi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // r8
  char *v12; // rax
  float v13; // xmm7_4
  float v14; // xmm6_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v15; // [rsp+60h] [rbp+8h]

  v7 = this->Data;
  v8 = this;
  v15.Data = v7;
  v9 = v7->Data.Size;
  v10 = v9 + 1;
  if ( v9 + 1 >= v9 )
  {
    if ( v10 > v7->Data.Policy.Capacity )
    {
      v11 = v10 + (v10 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v10 < v7->Data.Policy.Capacity >> 1 )
  {
    v11 = v9 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v7,
      v7,
      v11);
    goto LABEL_7;
  }
LABEL_7:
  v12 = v7->Data.Data;
  v7->Data.Size = v10;
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
  v8->LastX = v13;
  v8->LastY = v14;
  v8->Status = 4;
}

// File Line: 171
// RVA: 0x7C8FE0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v2; // rsi
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  char *v5; // rcx
  char *v6; // rcx

  v1 = this->Data;
  v2 = this;
  v3 = v1->Data.Size + 1;
  if ( v3 >= v1->Data.Size )
  {
    if ( v3 <= v1->Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= v1->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = v1->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data,
    this->Data,
    v4);
LABEL_7:
  v5 = v1->Data.Data;
  v1->Data.Size = v3;
  v6 = &v5[v3 - 1];
  if ( v6 )
    *v6 = 6;
  v2->Status = 5;
}

// File Line: 179
// RVA: 0x970CB0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v1; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v2; // rsi
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r8
  char *v6; // rax

  v1 = this->Status;
  v2 = this;
  if ( v1 != 6 && v1 )
  {
    if ( v1 != 5 )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this);
    v3 = v2->Data;
    v4 = v3->Data.Size + 1;
    if ( v4 >= v3->Data.Size )
    {
      if ( v4 > v3->Data.Policy.Capacity )
      {
        v5 = v4 + (v4 >> 2);
        goto LABEL_10;
      }
    }
    else if ( v4 < v3->Data.Policy.Capacity >> 1 )
    {
      v5 = v3->Data.Size + 1;
LABEL_10:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v2->Data,
        v2->Data,
        v5);
      goto LABEL_11;
    }
LABEL_11:
    v6 = v3->Data.Data;
    v3->Data.Size = v4;
    v6[v4 - 1] = 7;
    v2->Status = 6;
  }
}

// File Line: 196
// RVA: 0x983D20
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle(Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int idx, Scaleform::Render::FillStyleType *p)
{
  Scaleform::Render::FillStyleType *v3; // rdi
  Scaleform::Render::FillStyleType *v4; // rbx
  Scaleform::Render::ComplexFill *v5; // rcx
  Scaleform::Render::ComplexFill *v6; // rcx

  v3 = p;
  v4 = &this->Fills.Data.Data[idx - 1];
  p->Color = v4->Color;
  v5 = v4->pFill.pObject;
  if ( v5 )
    _InterlockedExchangeAdd(&v5->RefCount, 1u);
  v6 = p->pFill.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
  {
    v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    v3->pFill.pObject = v4->pFill.pObject;
  }
  else
  {
    p->pFill.pObject = v4->pFill.pObject;
  }
}

// File Line: 197
// RVA: 0x7EFFB0
void __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, unsigned int idx, Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(p, &this->Strokes.Data.Data[idx - 1]);
}

// File Line: 198
// RVA: 0x7EFEA0
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyleCount(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  return this->StartingPos;
}

// File Line: 201
// RVA: 0x9A5AC0
__int64 __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float *coord, unsigned int *styles)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::Render::ShapePosInfo *v5; // r10
  unsigned __int64 v6; // rdx
  unsigned int *v7; // r11
  float *v8; // r14
  __int64 result; // rax
  unsigned int v10; // ebp
  char v11; // r8
  __int64 v12; // rbx
  char *v13; // rdi
  signed int v14; // esi
  unsigned int v15; // er9
  unsigned int v16; // er9
  signed int v17; // ecx
  int v18; // er8
  __int64 v19; // rbx
  char *v20; // rdi
  unsigned int v21; // er9
  signed int v22; // ecx
  int v23; // er8
  __int64 v24; // rbx
  char *v25; // rdi
  unsigned int v26; // er9
  int v27; // er8
  __int64 v28; // r9
  __int64 v29; // r9
  char *v30; // r8
  int v31; // [rsp+20h] [rbp+8h]

  v4 = this->Data;
  v5 = pos;
  v6 = pos->Pos;
  v7 = styles;
  v8 = coord;
  if ( v6 >= v4->Data.Size )
    return 0i64;
  v10 = 1;
  v11 = v4->Data.Data[v6];
  v5->Pos = v6 + 1;
  if ( v11 == 7 )
    return 0i64;
  if ( !v11 )
  {
    v10 = 2;
    v5->Pos = v6 + 2;
  }
  v12 = v5->Pos;
  v13 = v4->Data.Data;
  v14 = 4;
  v15 = (unsigned __int8)v4->Data.Data[v12];
  if ( v4->Data.Data[v12] & 3 )
  {
    v16 = v15 >> 2;
    if ( (v4->Data.Data[v12] & 3) == 1 )
    {
      *v7 = v16 | ((unsigned __int8)v13[(unsigned int)(v12 + 1)] << 6);
      v17 = 2;
    }
    else
    {
      if ( (v4->Data.Data[v12] & 3) == 2 )
      {
        v17 = 3;
        v18 = v16 | (((unsigned __int8)v13[(unsigned int)(v12 + 1)] | ((unsigned __int8)v13[(unsigned int)(v12 + 2)] << 8)) << 6);
      }
      else
      {
        v17 = 4;
        v18 = v16 | (((unsigned __int8)v13[(unsigned int)(v12 + 1)] | (((unsigned __int8)v13[(unsigned int)(v12 + 2)] | ((unsigned __int8)v13[(unsigned int)(v12 + 3)] << 8)) << 8)) << 6);
      }
      *v7 = v18;
    }
  }
  else
  {
    v17 = 1;
    *v7 = v15 >> 2;
  }
  v5->Pos += v17;
  v19 = v5->Pos;
  v20 = v4->Data.Data;
  v21 = (unsigned int)(unsigned __int8)v4->Data.Data[v19] >> 2;
  if ( v4->Data.Data[v19] & 3 )
  {
    if ( (v4->Data.Data[v19] & 3) == 1 )
    {
      v7[1] = v21 | ((unsigned __int8)v20[(unsigned int)(v19 + 1)] << 6);
      v22 = 2;
    }
    else
    {
      if ( (v4->Data.Data[v19] & 3) == 2 )
      {
        v22 = 3;
        v23 = v21 | (((unsigned __int8)v20[(unsigned int)(v19 + 1)] | ((unsigned __int8)v20[(unsigned int)(v19 + 2)] << 8)) << 6);
      }
      else
      {
        v22 = 4;
        v23 = v21 | (((unsigned __int8)v20[(unsigned int)(v19 + 1)] | (((unsigned __int8)v20[(unsigned int)(v19 + 2)] | ((unsigned __int8)v20[(unsigned int)(v19 + 3)] << 8)) << 8)) << 6);
      }
      v7[1] = v23;
    }
  }
  else
  {
    v7[1] = v21;
    v22 = 1;
  }
  v5->Pos += v22;
  v24 = v5->Pos;
  v25 = v4->Data.Data;
  v26 = (unsigned int)(unsigned __int8)v4->Data.Data[v24] >> 2;
  if ( v4->Data.Data[v24] & 3 )
  {
    if ( (v4->Data.Data[v24] & 3) == 1 )
    {
      v14 = 2;
      v7[2] = v26 | ((unsigned __int8)v25[(unsigned int)(v24 + 1)] << 6);
    }
    else
    {
      if ( (v4->Data.Data[v24] & 3) == 2 )
      {
        v14 = 3;
        v27 = v26 | (((unsigned __int8)v25[(unsigned int)(v24 + 1)] | ((unsigned __int8)v25[(unsigned int)(v24 + 2)] << 8)) << 6);
      }
      else
      {
        v27 = v26 | (((unsigned __int8)v25[(unsigned int)(v24 + 1)] | (((unsigned __int8)v25[(unsigned int)(v24 + 2)] | ((unsigned __int8)v25[(unsigned int)(v24 + 3)] << 8)) << 8)) << 6);
      }
      v7[2] = v27;
    }
  }
  else
  {
    v7[2] = v26;
    v14 = 1;
  }
  v5->Pos += v14 + 1;
  v28 = v5->Pos;
  LOBYTE(v31) = v4->Data.Data[v28];
  BYTE1(v31) = v4->Data.Data[(unsigned int)(v28 + 1)];
  HIWORD(v31) = (unsigned __int8)v4->Data.Data[(unsigned int)(v28 + 2)];
  HIBYTE(v31) = v4->Data.Data[(unsigned int)(v28 + 3)];
  *(_DWORD *)v8 = v31;
  v5->Pos += 4;
  v29 = v5->Pos;
  v30 = v4->Data.Data;
  result = v10;
  LOBYTE(v31) = v30[v29];
  BYTE1(v31) = v30[(unsigned int)(v29 + 1)];
  BYTE2(v31) = v30[(unsigned int)(v29 + 2)];
  HIBYTE(v31) = v30[(unsigned int)(v29 + 3)];
  *((_DWORD *)v8 + 1) = v31;
  v5->Pos += 4;
  return result;
}

// File Line: 230
// RVA: 0x80ED20
signed __int64 __fastcall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Render::ShapePosInfo *pos, float *coord)
{
  __int64 v3; // r9
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  __int64 v5; // r11
  float *v6; // rdi
  char v7; // bl
  __int64 v8; // r9
  __int64 v9; // r9
  __int64 v10; // r9
  __int64 v11; // r9
  __int64 v12; // r8
  signed __int64 result; // rax
  int v14; // [rsp+10h] [rbp+10h]
  int v15; // [rsp+10h] [rbp+10h]
  int v16; // [rsp+10h] [rbp+10h]

  v3 = pos->Pos;
  v4 = this->Data;
  v5 = (unsigned int)(v3 + 1);
  v6 = coord;
  v7 = v4->Data.Data[v3];
  pos->Pos = v5;
  if ( v7 == 6 )
    return 0i64;
  *(_WORD *)((char *)&v14 + 1) = (unsigned __int8)v4->Data.Data[(unsigned int)(v3 + 2)];
  LOBYTE(v14) = v4->Data.Data[v5];
  BYTE2(v14) = v4->Data.Data[(unsigned int)(v3 + 3)];
  HIBYTE(v14) = v4->Data.Data[(unsigned int)(v3 + 4)];
  *(_DWORD *)coord = v14;
  pos->Pos += 4;
  v8 = pos->Pos;
  BYTE1(v14) = v4->Data.Data[(unsigned int)(v8 + 1)];
  LOBYTE(v14) = v4->Data.Data[v8];
  BYTE2(v14) = v4->Data.Data[(unsigned int)(v8 + 2)];
  HIBYTE(v14) = v4->Data.Data[(unsigned int)(v8 + 3)];
  *((_DWORD *)coord + 1) = v14;
  pos->Pos += 4;
  v9 = pos->Pos;
  if ( (unsigned __int8)(v7 - 4) > 1u )
    return 1i64;
  *(_WORD *)((char *)&v15 + 1) = (unsigned __int8)v4->Data.Data[(unsigned int)(v9 + 1)];
  LOBYTE(v15) = v4->Data.Data[v9];
  BYTE2(v15) = v4->Data.Data[(unsigned int)(v9 + 2)];
  HIBYTE(v15) = v4->Data.Data[(unsigned int)(v9 + 3)];
  *((_DWORD *)coord + 2) = v15;
  pos->Pos += 4;
  v10 = pos->Pos;
  BYTE1(v15) = v4->Data.Data[(unsigned int)(v10 + 1)];
  LOBYTE(v15) = v4->Data.Data[v10];
  BYTE2(v15) = v4->Data.Data[(unsigned int)(v10 + 2)];
  HIBYTE(v15) = v4->Data.Data[(unsigned int)(v10 + 3)];
  *((_DWORD *)coord + 3) = v15;
  pos->Pos += 4;
  v11 = pos->Pos;
  if ( v7 != 5 )
    return 2i64;
  *(_WORD *)((char *)&v16 + 1) = (unsigned __int8)v4->Data.Data[(unsigned int)(v11 + 1)];
  LOBYTE(v16) = v4->Data.Data[v11];
  BYTE2(v16) = v4->Data.Data[(unsigned int)(v11 + 2)];
  HIBYTE(v16) = v4->Data.Data[(unsigned int)(v11 + 3)];
  *((_DWORD *)coord + 4) = v16;
  pos->Pos += 4;
  v12 = pos->Pos;
  LOBYTE(v16) = v4->Data.Data[v12];
  BYTE1(v16) = v4->Data.Data[(unsigned int)(v12 + 1)];
  BYTE2(v16) = v4->Data.Data[(unsigned int)(v12 + 2)];
  HIBYTE(v16) = v4->Data.Data[(unsigned int)(v12 + 3)];
  result = 3i64;
  *((_DWORD *)v6 + 5) = v16;
  pos->Pos += 4;
  return result;
}

// File Line: 275
// RVA: 0x781CF0
void __fastcall Scaleform::Render::ShapeDataFloat::ShapeDataFloat(Scaleform::Render::ShapeDataFloat *this)
{
  Scaleform::ArrayLH<Scaleform::Render::FillStyleType,2,Scaleform::ArrayDefaultPolicy> *v1; // rax
  Scaleform::ArrayLH<Scaleform::Render::StrokeStyleType,2,Scaleform::ArrayDefaultPolicy> *v2; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable';
  this->Status = 0;
  v1 = &this->Fills;
  v1->Data.Data = 0i64;
  v1->Data.Size = 0i64;
  v1->Data.Policy.Capacity = 0i64;
  v2 = &this->Strokes;
  v2->Data.Data = 0i64;
  v2->Data.Size = 0i64;
  v2->Data.Policy.Capacity = 0i64;
  this->Data = &this->Container;
  *(_QWORD *)&this->StartingPos = 0i64;
  *(_QWORD *)&this->StartY = 0i64;
  this->LastY = 0.0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloat::`vftable';
  this->Container.Data.Data = 0i64;
  this->Container.Data.Size = 0i64;
  this->Container.Data.Policy.Capacity = 0i64;
}

