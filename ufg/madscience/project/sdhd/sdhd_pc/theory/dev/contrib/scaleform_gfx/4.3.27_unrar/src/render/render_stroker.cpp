// File Line: 46
// RVA: 0x954DC0
void __fastcall Scaleform::Render::StrokePath::AddVertex(
        Scaleform::Render::StrokePath *this,
        Scaleform::Render::StrokeVertex *v)
{
  unsigned __int64 Size; // r8
  __m128 y_low; // xmm0
  unsigned __int64 v6; // r9
  __int64 v7; // r8
  Scaleform::Render::StrokeVertex *v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm1_4
  unsigned __int64 v11; // rdi
  Scaleform::Render::StrokeVertex *v12; // rdx
  __int64 v13; // r8

  Size = this->Path.Size;
  if ( !Size )
    goto LABEL_3;
  y_low = (__m128)LODWORD(v->y);
  v6 = Size - 1;
  v7 = ((_DWORD)Size - 1) & 0xF;
  v8 = this->Path.Pages[v6 >> 4];
  y_low.m128_f32[0] = y_low.m128_f32[0] - v8[v7].y;
  v9 = v->x - v8[v7].x;
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9);
  v10 = _mm_sqrt_ps(y_low).m128_f32[0];
  v8[v7].dist = v10;
  if ( v10 > 0.0 )
  {
LABEL_3:
    v11 = this->Path.Size >> 4;
    if ( v11 >= this->Path.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)this,
        this->Path.Size >> 4);
    v12 = this->Path.Pages[v11];
    v13 = this->Path.Size & 0xF;
    v12[v13].x = v->x;
    v12[v13].y = v->y;
    v12[v13].dist = v->dist;
    ++this->Path.Size;
  }
}

// File Line: 55
// RVA: 0x961590
bool __fastcall Scaleform::Render::StrokePath::ClosePath(Scaleform::Render::StrokePath *this)
{
  unsigned __int64 Size; // rax
  Scaleform::Render::StrokeVertex **Pages; // r8
  __int64 v4; // rcx
  __m128 y_low; // xmm0
  Scaleform::Render::StrokeVertex *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm1_4
  unsigned __int64 v9; // rax

  Size = this->Path.Size;
  if ( Size <= 1 )
    return 0;
  Pages = this->Path.Pages;
  v4 = ((_DWORD)Size - 1) & 0xF;
  y_low = (__m128)LODWORD((*Pages)->y);
  v6 = Pages[(Size - 1) >> 4];
  y_low.m128_f32[0] = y_low.m128_f32[0] - v6[v4].y;
  v7 = (*Pages)->x - v6[v4].x;
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7);
  v8 = _mm_sqrt_ps(y_low).m128_f32[0];
  v6[v4].dist = v8;
  if ( v8 > 0.0 )
    return 0;
  v9 = this->Path.Size;
  if ( v9 )
    this->Path.Size = v9 - 1;
  return this->Path.Size > 2;
}

// File Line: 84
// RVA: 0x95FA30
void __fastcall Scaleform::Render::Stroker::Clear(Scaleform::Render::Stroker *this)
{
  this->Path.Path.MaxPages = 0i64;
  this->Path.Path.NumPages = 0i64;
  this->Path.Path.Size = 0i64;
  this->Path.Path.Pages = 0i64;
  this->Closed = 0;
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap);
}

// File Line: 100
// RVA: 0x961610
void __fastcall Scaleform::Render::Stroker::ClosePath(Scaleform::Render::Stroker *this)
{
  Scaleform::Render::StrokePath::ClosePath(&this->Path);
  this->Closed = 1;
}

// File Line: 107
// RVA: 0x97F6F0
void __fastcall Scaleform::Render::Stroker::GenerateStroke(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess)
{
  unsigned __int64 v4; // rcx
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // r8
  Scaleform::Render::StrokeVertex *v10; // r9
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rbp
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r11
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r10
  unsigned __int64 v17; // rax
  Scaleform::Render::StrokeVertex **Pages; // rdx
  Scaleform::Render::StrokeVertex *v19; // r9
  unsigned __int64 v20; // r9
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // r10
  unsigned __int64 v25; // r8
  Scaleform::Render::StrokeVertex *v26; // r9
  unsigned __int64 v27; // rax
  unsigned __int64 v28; // rbp
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // r11
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // r10
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // rsi
  Scaleform::Render::StrokeVertex **v35; // rdx
  Scaleform::Render::StrokeVertex *v36; // r9

  if ( !this->Closed )
    this->Closed = Scaleform::Render::StrokePath::ClosePath(&this->Path);
  if ( this->Path.Path.Size > 1 )
  {
    if ( this->Closed )
    {
      v4 = 0i64;
      do
      {
        Size = v4;
        if ( !v4 )
          Size = this->Path.Path.Size;
        v6 = this->Path.Path.Size;
        v7 = v4 + 1;
        v8 = v4 + 1;
        if ( v4 + 1 >= v6 )
          v8 -= v6;
        v9 = v4;
        if ( !v4 )
          v9 = this->Path.Path.Size;
        v10 = &this->Path.Path.Pages[v4 >> 4][v4 & 0xF];
        Scaleform::Render::Stroker::calcJoin(
          this,
          tess,
          &this->Path.Path.Pages[(v9 - 1) >> 4][((_DWORD)v9 - 1) & 0xF],
          v10,
          &this->Path.Path.Pages[v8 >> 4][v8 & 0xF],
          this->Path.Path.Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF].dist,
          v10->dist);
        v4 = v7;
      }
      while ( v7 < this->Path.Path.Size );
      tess->vfptr->ClosePath(tess);
      ((void (__fastcall *)(Scaleform::Render::TessBase *, _QWORD, __int64))tess->vfptr->FinalizePath)(tess, 0i64, 1i64);
      v11 = this->Path.Path.Size;
      if ( v11 )
      {
        do
        {
          v12 = v11 - 1;
          v13 = v11 - 1;
          if ( v11 == 1 )
            v13 = this->Path.Path.Size;
          v14 = v13 - 1;
          v15 = v11 - 1;
          if ( v11 == 1 )
            v15 = this->Path.Path.Size;
          v16 = v15 - 1;
          v17 = this->Path.Path.Size;
          if ( v11 >= v17 )
            v11 -= v17;
          Pages = this->Path.Path.Pages;
          v19 = &Pages[v12 >> 4][v12 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            this,
            tess,
            &Pages[v11 >> 4][v11 & 0xF],
            v19,
            &Pages[v16 >> 4][v16 & 0xF],
            v19->dist,
            Pages[v14 >> 4][v14 & 0xF].dist);
          v11 = v12;
        }
        while ( v12 );
      }
    }
    else
    {
      Scaleform::Render::Stroker::calcCap(
        this,
        tess,
        *this->Path.Path.Pages,
        *this->Path.Path.Pages + 1,
        (*this->Path.Path.Pages)->dist,
        this->StartLineCap);
      v20 = 1i64;
      if ( this->Path.Path.Size > 2 )
      {
        v21 = 2i64;
        do
        {
          v22 = v20;
          if ( !v20 )
            v22 = this->Path.Path.Size;
          v23 = this->Path.Path.Size;
          v24 = v21;
          if ( v21 >= v23 )
            v24 = v21 - v23;
          v25 = v20;
          if ( !v20 )
            v25 = this->Path.Path.Size;
          v26 = &this->Path.Path.Pages[v20 >> 4][v20 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            this,
            tess,
            &this->Path.Path.Pages[(v25 - 1) >> 4][((_DWORD)v25 - 1) & 0xF],
            v26,
            &this->Path.Path.Pages[v24 >> 4][v24 & 0xF],
            this->Path.Path.Pages[(v22 - 1) >> 4][((_DWORD)v22 - 1) & 0xF].dist,
            v26->dist);
          v20 = v21++;
        }
        while ( v21 < this->Path.Path.Size );
      }
      v27 = this->Path.Path.Size;
      Scaleform::Render::Stroker::calcCap(
        this,
        tess,
        &this->Path.Path.Pages[(v27 - 1) >> 4][((_DWORD)v27 - 1) & 0xF],
        &this->Path.Path.Pages[(v27 - 2) >> 4][((_DWORD)v27 - 2) & 0xF],
        this->Path.Path.Pages[(v27 - 2) >> 4][((_BYTE)v27 - 2) & 0xF].dist,
        this->EndLineCap);
      v28 = this->Path.Path.Size - 2;
      if ( this->Path.Path.Size != 2 )
      {
        do
        {
          v29 = v28;
          if ( !v28 )
            v29 = this->Path.Path.Size;
          v30 = v29 - 1;
          v31 = v28;
          if ( !v28 )
            v31 = this->Path.Path.Size;
          v32 = v31 - 1;
          v33 = this->Path.Path.Size;
          v34 = v28 + 1;
          if ( v28 + 1 >= v33 )
            v34 -= v33;
          v35 = this->Path.Path.Pages;
          v36 = &v35[v28 >> 4][v28 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            this,
            tess,
            &v35[v34 >> 4][v34 & 0xF],
            v36,
            &v35[v32 >> 4][v32 & 0xF],
            v36->dist,
            v35[v30 >> 4][v30 & 0xF].dist);
          --v28;
        }
        while ( v28 );
      }
    }
    tess->vfptr->ClosePath(tess);
    ((void (__fastcall *)(Scaleform::Render::TessBase *, _QWORD, __int64))tess->vfptr->FinalizePath)(tess, 0i64, 1i64);
  }
  this->Closed = 0;
  this->Path.Path.Size = 0i64;
}

// File Line: 184
// RVA: 0x95BA20
void __fastcall Scaleform::Render::Stroker::CalcEquidistant(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::StrokerTypes::EquidistantDir dir)
{
  unsigned __int64 Size; // rdi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // r8
  Scaleform::Render::StrokeVertex *v12; // r9
  unsigned __int64 v13; // rbp
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // r11
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // r10
  unsigned __int64 v18; // rax
  Scaleform::Render::StrokeVertex **Pages; // rdx
  Scaleform::Render::StrokeVertex *v20; // r9

  Size = this->Path.Path.Size;
  if ( Size <= 2 )
  {
    this->Path.Path.Size = 0i64;
  }
  else
  {
    if ( dir )
    {
      do
      {
        v13 = Size - 1;
        v14 = Size - 1;
        if ( Size == 1 )
          v14 = this->Path.Path.Size;
        v15 = v14 - 1;
        v16 = Size - 1;
        if ( Size == 1 )
          v16 = this->Path.Path.Size;
        v17 = v16 - 1;
        v18 = this->Path.Path.Size;
        if ( Size >= v18 )
          Size -= v18;
        Pages = this->Path.Path.Pages;
        v20 = &Pages[v13 >> 4][v13 & 0xF];
        Scaleform::Render::Stroker::calcJoin(
          this,
          tess,
          &Pages[Size >> 4][Size & 0xF],
          v20,
          &Pages[v17 >> 4][v17 & 0xF],
          v20->dist,
          Pages[v15 >> 4][v15 & 0xF].dist);
        Size = v13;
      }
      while ( v13 );
    }
    else
    {
      v6 = 0i64;
      do
      {
        v7 = v6;
        if ( !v6 )
          v7 = this->Path.Path.Size;
        v8 = this->Path.Path.Size;
        v9 = v6 + 1;
        v10 = v6 + 1;
        if ( v6 + 1 >= v8 )
          v10 -= v8;
        v11 = v6;
        if ( !v6 )
          v11 = this->Path.Path.Size;
        v12 = &this->Path.Path.Pages[v6 >> 4][v6 & 0xF];
        Scaleform::Render::Stroker::calcJoin(
          this,
          tess,
          &this->Path.Path.Pages[(v11 - 1) >> 4][((_DWORD)v11 - 1) & 0xF],
          v12,
          &this->Path.Path.Pages[v10 >> 4][v10 & 0xF],
          this->Path.Path.Pages[(v7 - 1) >> 4][((_DWORD)v7 - 1) & 0xF].dist,
          v12->dist);
        v6 = v9;
      }
      while ( v9 < this->Path.Path.Size );
    }
    tess->vfptr->ClosePath(tess);
    ((void (__fastcall *)(Scaleform::Render::TessBase *, _QWORD, __int64))tess->vfptr->FinalizePath)(tess, 0i64, 1i64);
    this->Path.Path.Size = 0i64;
  }
}

// File Line: 224
// RVA: 0x9D00D0
void __fastcall Scaleform::Render::Stroker::calcArc(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        float x,
        float y,
        float dx1,
        float dy1,
        float dx2,
        float dy2)
{
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm12_4
  float v13; // xmm9_4
  int v14; // ecx
  float v15; // xmm9_4
  float v16; // xmm8_4
  __int64 v17; // rsi
  Scaleform::Render::TessBaseVtbl *vfptr; // rbx

  v10 = atan2f(dy1, dx1);
  v11 = atan2f(dy2, dx2);
  v12 = acosf(this->Width / (float)((float)(this->CurveTolerance * 0.25) + this->Width)) * 2.0;
  ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
  if ( v10 > v11 )
    v11 = v11 + 6.2831855;
  v13 = v11 - v10;
  v14 = (int)(float)(v13 / v12);
  v15 = v13 / (float)(v14 + 1);
  v16 = v10 + v15;
  if ( v14 > 0 )
  {
    v17 = (unsigned int)v14;
    do
    {
      vfptr = tess->vfptr;
      sinf(v16);
      cosf(v16);
      ((void (__fastcall *)(Scaleform::Render::TessBase *))vfptr->AddVertex)(tess);
      v16 = v16 + v15;
      --v17;
    }
    while ( v17 );
  }
  ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
}

// File Line: 258
// RVA: 0x9D3F70
void __fastcall Scaleform::Render::Stroker::calcMiter(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::StrokeVertex *v0,
        Scaleform::Render::StrokeVertex *v1,
        Scaleform::Render::StrokeVertex *v2,
        float dx1,
        float dy1,
        float dx2,
        float dy2,
        Scaleform::Render::StrokerTypes::LineJoinType lineJoin,
        float miterLimit,
        float epsilon)
{
  float y; // xmm3_4
  float v16; // xmm4_4
  float x; // xmm2_4
  float v18; // xmm13_4
  char v19; // cl
  __int64 v20; // rdx
  float v21; // xmm14_4
  float v22; // xmm5_4
  float v23; // xmm8_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm12_4
  __m128 v27; // xmm11
  float v28; // xmm1_4
  __m128 v29; // xmm0
  Scaleform::Render::TessBaseVtbl *vfptr; // rax
  float v31; // [rsp+20h] [rbp-B8h]
  float v32; // [rsp+24h] [rbp-B4h]
  float v33; // [rsp+E0h] [rbp+8h]
  float v2a; // [rsp+100h] [rbp+28h]
  float dx1a; // [rsp+108h] [rbp+30h]
  float dy1a; // [rsp+110h] [rbp+38h]

  y = v1->y;
  v16 = v2->y;
  x = v2->x;
  v18 = miterLimit * this->Width;
  v19 = 1;
  v20 = 1i64;
  v21 = y + dy1;
  v22 = v1->x + dx1;
  v23 = y + dy1;
  v24 = y + dy2;
  v25 = v0->y;
  v26 = v22 - (float)(v0->x + dx1);
  v31 = v0->x + dx1;
  dx1a = v25 + dy1;
  v33 = (float)(v16 + dy2) - v24;
  dy1a = v23 - (float)(v25 + dy1);
  v2a = (float)(v2->x + dx2) - (float)(v1->x + dx2);
  v32 = (float)(v33 * v26) - (float)(v2a * dy1a);
  if ( COERCE_FLOAT(LODWORD(v32) & _xmm) < epsilon )
  {
    if ( (float)((float)((float)(v0->x - v22) * dy1) - (float)((float)(v25 - v21) * dx1)) < 0.0 != (float)((float)((float)(x - v22) * dy1) - (float)((float)(v16 - v21) * dx1)) < 0.0 )
    {
LABEL_10:
      ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64))tess->vfptr->AddVertex)(tess, v20);
      return;
    }
LABEL_5:
    vfptr = tess->vfptr;
    if ( lineJoin == MiterBevelJoin )
      ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64))vfptr->AddVertex)(tess, v20);
    else
      ((void (__fastcall *)(Scaleform::Render::TessBase *))vfptr->AddVertex)(tess);
    goto LABEL_10;
  }
  v27 = (__m128)LODWORD(dy1a);
  v28 = (float)((float)((float)(dx1a - v24) * v2a) - (float)((float)(v31 - (float)(v1->x + dx2)) * v33)) / v32;
  v27.m128_f32[0] = (float)(dy1a * v28) + dx1a;
  v29 = v27;
  v29.m128_f32[0] = (float)((float)(v27.m128_f32[0] - v1->y) * (float)(v27.m128_f32[0] - v1->y))
                  + (float)((float)((float)((float)(v26 * v28) + v31) - v1->x)
                          * (float)((float)((float)(v26 * v28) + v31) - v1->x));
  if ( _mm_sqrt_ps(v29).m128_f32[0] <= v18 )
  {
    ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64))tess->vfptr->AddVertex)(tess, 1i64);
    v19 = 0;
  }
  LOBYTE(v20) = 0;
  if ( v19 )
    goto LABEL_5;
}

// File Line: 351
// RVA: 0x9D1AC0
void __fastcall Scaleform::Render::Stroker::calcCap(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::StrokeVertex *v0,
        Scaleform::Render::StrokeVertex *v1,
        float len,
        Scaleform::Render::StrokerTypes::LineCapType cap)
{
  float Width; // xmm12_4
  float v9; // xmm10_4
  float v10; // xmm13_4
  int v11; // ebx
  float v12; // xmm13_4
  float v13; // xmm10_4
  __int64 v14; // rbp
  Scaleform::Render::TessBaseVtbl *vfptr; // rbx

  Width = this->Width;
  if ( Width == 0.0 )
  {
    ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
  }
  else if ( cap == RoundCap )
  {
    v9 = atan2f(
           COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v0->x - v1->x) * (float)(1.0 / len)) * Width) ^ _xmm[0]),
           COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v1->y - v0->y) * (float)(1.0 / len)) * Width) ^ _xmm[0]));
    v10 = (float)(v9 + 3.1415927) - v9;
    v11 = (int)(float)(v10 / (float)(acosf(Width / (float)((float)(this->CurveTolerance * 0.25) + Width)) * 2.0));
    v12 = v10 / (float)(v11 + 1);
    v13 = v9 + v12;
    ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
    if ( v11 > 0 )
    {
      v14 = (unsigned int)v11;
      do
      {
        vfptr = tess->vfptr;
        sinf(v13);
        cosf(v13);
        ((void (__fastcall *)(Scaleform::Render::TessBase *))vfptr->AddVertex)(tess);
        v13 = v13 + v12;
        --v14;
      }
      while ( v14 );
    }
    ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
  }
  else
  {
    ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
    ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
  }
}

// File Line: 404
// RVA: 0x9D2380
void __fastcall Scaleform::Render::Stroker::calcJoin(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::StrokeVertex *v0,
        Scaleform::Render::StrokeVertex *v1,
        Scaleform::Render::StrokeVertex *v2,
        float len1,
        float len2)
{
  float Width; // xmm8_4
  __m128 x_low; // xmm4
  float y; // xmm5_4
  Scaleform::Render::StrokeVertex *v12; // r9
  float v13; // xmm10_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float epsilon; // xmm15_4
  float dy1; // xmm9_4
  float dx2; // xmm7_4
  float dx1; // xmm11_4
  __m128 dy2; // xmm6
  __int64 lineJoin; // rdx
  __m128 v22; // xmm1
  float dbevel; // xmm3_4
  Scaleform::Render::TessBaseVtbl *vfptr; // rax
  Scaleform::Render::TessBase *v25; // rcx

  Width = this->Width;
  if ( Width == 0.0 )
  {
    ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
    return;
  }
  x_low = (__m128)LODWORD(v1->x);
  y = v1->y;
  v12 = v2;
  v13 = len1;
  v14 = v2->y - y;
  v15 = y - v0->y;
  dy2 = x_low;
  epsilon = (float)(len1 + len2) * this->IntersectionEpsilon;
  dy1 = (float)((float)(v0->x - x_low.m128_f32[0]) * Width) * (float)(1.0 / len1);
  dx2 = (float)(v14 * Width) * (float)(1.0 / len2);
  dx1 = (float)(v15 * Width) * (float)(1.0 / len1);
  dy2.m128_f32[0] = (float)((float)(x_low.m128_f32[0] - v2->x) * Width) * (float)(1.0 / len2);
  if ( (float)((float)((float)(v2->x - x_low.m128_f32[0]) * v15) - (float)((float)(x_low.m128_f32[0] - v0->x) * v14)) <= 0.0 )
  {
    lineJoin = (unsigned int)this->LineJoin;
    v22 = dy2;
    v22.m128_f32[0] = (float)((float)((float)(dy2.m128_f32[0] + dy1) * 0.5)
                            * (float)((float)(dy2.m128_f32[0] + dy1) * 0.5))
                    + (float)((float)((float)(dx2 + dx1) * 0.5) * (float)((float)(dx2 + dx1) * 0.5));
    LODWORD(dbevel) = _mm_sqrt_ps(v22).m128_u32[0];
    if ( (unsigned int)(lineJoin - 2) > 1 || (float)(Width - dbevel) >= (float)(this->CurveTolerance * 0.125) )
    {
      if ( (int)lineJoin >= 0 )
      {
        if ( (int)lineJoin <= 1 )
        {
          Scaleform::Render::Stroker::calcMiter(
            this,
            tess,
            v0,
            v1,
            v2,
            dx1,
            dy1,
            dx2,
            dy2.m128_f32[0],
            (Scaleform::Render::StrokerTypes::LineJoinType)lineJoin,
            this->MiterLimit,
            epsilon,
            dbevel);
          return;
        }
        if ( (_DWORD)lineJoin == 2 )
        {
          Scaleform::Render::Stroker::calcArc(this, tess, x_low.m128_f32[0], y, dx1, dy1, dx2, dy2.m128_f32[0]);
          return;
        }
      }
      ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64, Scaleform::Render::StrokeVertex *, Scaleform::Render::StrokeVertex *))tess->vfptr->AddVertex)(
        tess,
        lineJoin,
        v0,
        v2);
      vfptr = tess->vfptr;
      v25 = tess;
    }
    else
    {
      vfptr = tess->vfptr;
      v25 = tess;
    }
    ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64, Scaleform::Render::StrokeVertex *, Scaleform::Render::StrokeVertex *))vfptr->AddVertex)(
      v25,
      lineJoin,
      v0,
      v12);
  }
  else
  {
    if ( len1 >= len2 )
      v13 = len2;
    Scaleform::Render::Stroker::calcMiter(
      this,
      tess,
      v0,
      v1,
      v2,
      dx1,
      dy1,
      dx2,
      dy2.m128_f32[0],
      MiterBevelJoin,
      v13 / Width,
      epsilon,
      0.0);
  }
}

// File Line: 531
// RVA: 0x945120
void __fastcall Scaleform::Render::StrokeSorter::StrokeSorter(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::LinearHeap *heap)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::StrokeSorter::`vftable;
  this->pHeap = heap;
  this->SrcVertices.pHeap = heap;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->SrcPaths.pHeap = heap;
  this->SrcPaths.Size = 0i64;
  this->SrcPaths.NumPages = 0i64;
  this->SrcPaths.MaxPages = 0i64;
  this->SrcPaths.Pages = 0i64;
  this->SortedPaths.pHeap = heap;
  this->SortedPaths.Size = 0i64;
  this->SortedPaths.Array = 0i64;
  this->OutVertices.pHeap = heap;
  this->OutVertices.Size = 0i64;
  this->OutVertices.NumPages = 0i64;
  this->OutVertices.MaxPages = 0i64;
  this->OutVertices.Pages = 0i64;
  this->OutPaths.pHeap = heap;
  this->OutPaths.Size = 0i64;
  this->OutPaths.NumPages = 0i64;
  this->OutPaths.MaxPages = 0i64;
  this->OutPaths.Pages = 0i64;
  this->LastVertex = 0;
}

// File Line: 535
// RVA: 0x95F9B0
void __fastcall Scaleform::Render::StrokeSorter::Clear(Scaleform::Render::StrokeSorter *this)
{
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->SrcPaths.MaxPages = 0i64;
  this->SrcPaths.NumPages = 0i64;
  this->SrcPaths.Size = 0i64;
  this->SrcPaths.Pages = 0i64;
  this->SortedPaths.Size = 0i64;
  this->SortedPaths.Array = 0i64;
  this->OutVertices.MaxPages = 0i64;
  this->OutVertices.NumPages = 0i64;
  this->OutVertices.Size = 0i64;
  this->OutVertices.Pages = 0i64;
  this->OutPaths.MaxPages = 0i64;
  this->OutPaths.NumPages = 0i64;
  this->OutPaths.Size = 0i64;
  this->OutPaths.Pages = 0i64;
  this->LastVertex = 0;
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap);
}

// File Line: 547
// RVA: 0x955070
void __fastcall Scaleform::Render::StrokeSorter::AddVertexNV(
        Scaleform::Render::StrokeSorter *this,
        float x,
        float y,
        char segType)
{
  unsigned __int64 Size; // rcx
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r9
  unsigned __int64 v8; // rax
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *p_SrcVertices; // rbx
  unsigned __int64 v10; // rdi
  Scaleform::Render::StrokeSorter::VertexType *v11; // rcx
  __int64 v12; // rdx
  int v13; // [rsp+2Ch] [rbp-3Ch]

  Size = this->SrcVertices.Size;
  if ( Size == this->LastVertex
    && Size
    && (Pages = this->SrcVertices.Pages, x == Pages[(Size - 1) >> 4][((_BYTE)Size - 1) & 0xF].x)
    && y == Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF].y )
  {
    this->LastVertex = this->SrcPaths.Pages[(this->SrcPaths.Size - 1) >> 4][(LODWORD(this->SrcPaths.Size) - 1) & 0xF].start;
    v8 = this->SrcPaths.Size;
    if ( v8 )
      this->SrcPaths.Size = v8 - 1;
  }
  else
  {
    p_SrcVertices = &this->SrcVertices;
    v10 = this->SrcVertices.Size >> 4;
    LOBYTE(v13) = segType;
    *(_WORD *)((char *)&v13 + 1) = 0;
    if ( v10 >= this->SrcVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        &this->SrcVertices,
        v10);
    v11 = p_SrcVertices->Pages[v10];
    v12 = p_SrcVertices->Size & 0xF;
    v11[v12].x = x;
    v11[v12].y = y;
    v11[v12].Dist = 0.0;
    *(_DWORD *)&v11[v12].segType = v13;
    ++p_SrcVertices->Size;
  }
}

// File Line: 566
// RVA: 0x954EB0
void __fastcall Scaleform::Render::StrokeSorter::AddVertex(Scaleform::Render::StrokeSorter *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *p_SrcVertices; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::StrokeSorter::VertexType *v5; // rcx
  __int64 v6; // rdx
  int v7; // [rsp+2Ch] [rbp-3Ch]

  p_SrcVertices = &this->SrcVertices;
  v4 = this->SrcVertices.Size >> 4;
  LOWORD(v7) = 1;
  BYTE2(v7) = 0;
  if ( v4 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(&this->SrcVertices, v4);
  v5 = p_SrcVertices->Pages[v4];
  v6 = p_SrcVertices->Size & 0xF;
  v5[v6].x = x;
  v5[v6].y = y;
  v5[v6].Dist = 0.0;
  *(_DWORD *)&v5[v6].segType = v7;
  ++p_SrcVertices->Size;
}

// File Line: 588
// RVA: 0x9787A0
void __fastcall Scaleform::Render::StrokeSorter::FinalizePath(
        Scaleform::Render::StrokeSorter *this,
        unsigned int closeFlag,
        unsigned int __formal,
        bool a4,
        bool __formala)
{
  unsigned __int64 LastVertex; // rcx
  unsigned __int64 v7; // rsi
  Scaleform::Render::StrokeSorter::PathType v8; // [rsp+30h] [rbp+8h]

  LastVertex = this->LastVertex;
  if ( this->SrcVertices.Size <= (unsigned int)(LastVertex + 1) )
  {
    if ( LastVertex < this->SrcVertices.Size )
      this->SrcVertices.Size = LastVertex;
  }
  else
  {
    v8.start = LastVertex;
    v8.numVer = LODWORD(this->SrcVertices.Size) - LastVertex;
    if ( closeFlag )
      v8.numVer = (LODWORD(this->SrcVertices.Size) - LastVertex) | 0x20000000;
    v7 = this->SrcPaths.Size >> 4;
    if ( v7 >= this->SrcPaths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcPaths,
        this->SrcPaths.Size >> 4);
    this->SrcPaths.Pages[v7][this->SrcPaths.Size & 0xF] = v8;
    ++this->SrcPaths.Size;
    this->LastVertex = this->SrcVertices.Size;
  }
}

// File Line: 606
// RVA: 0x9CE750
void __fastcall Scaleform::Render::StrokeSorter::appendPath(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::StrokeSorter::PathType *dst,
        Scaleform::Render::StrokeSorter::PathType *src)
{
  unsigned int v6; // ebp
  unsigned int v7; // r15d
  unsigned __int64 v8; // rsi
  Scaleform::Render::StrokeSorter::VertexType *v9; // rbx
  Scaleform::Render::StrokeSorter::VertexType *v10; // rdx

  if ( !dst->numVer )
  {
    dst->start = this->OutVertices.Size;
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
      &this->OutVertices,
      &this->SrcVertices.Pages[(unsigned __int64)src->start >> 4][src->start & 0xF]);
    ++dst->numVer;
  }
  v6 = 1;
  v7 = src->numVer & 0xFFFFFFF;
  if ( v7 > 1 )
  {
    do
    {
      v8 = this->OutVertices.Size >> 4;
      v9 = &this->SrcVertices.Pages[(unsigned __int64)(v6 + src->start) >> 4][((_BYTE)v6 + LOBYTE(src->start)) & 0xF];
      if ( v8 >= this->OutVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          &this->OutVertices,
          this->OutVertices.Size >> 4);
      ++v6;
      v10 = &this->OutVertices.Pages[v8][this->OutVertices.Size & 0xF];
      v10->x = v9->x;
      v10->y = v9->y;
      v10->Dist = v9->Dist;
      *(_DWORD *)&v10->segType = *(_DWORD *)&v9->segType;
      ++this->OutVertices.Size;
      ++dst->numVer;
    }
    while ( v6 < v7 );
  }
}

// File Line: 627
// RVA: 0x9E2F60
__int64 __fastcall Scaleform::Render::StrokeSorter::findNext(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::StrokeSorter::PathType *outPath)
{
  Scaleform::Render::StrokeSorter::VertexType **Pages; // rax
  __int64 Size; // rcx
  unsigned __int64 v5; // rdx
  float *p_x; // r8
  unsigned __int64 v7; // rdx
  float v8; // xmm1_4
  float v9; // xmm2_4
  Scaleform::Render::StrokeSorter::SortedPathType *v10; // rax
  float x; // xmm0_4
  bool v12; // cf
  bool v13; // zf
  unsigned __int64 v14; // r8
  Scaleform::Render::StrokeSorter::SortedPathType *i; // rcx

  Pages = this->OutVertices.Pages;
  Size = this->SortedPaths.Size;
  v5 = (outPath->numVer & 0xFFFFFFF) + outPath->start - 1;
  p_x = &Pages[v5 >> 4][v5 & 0xF].x;
  v7 = 0i64;
  v8 = *p_x;
  v9 = p_x[1];
  while ( Size > 0 )
  {
    v10 = &this->SortedPaths.Array[(Size >> 1) + v7];
    x = v10->x;
    if ( v10->x == v8 )
    {
      v12 = v9 < v10->y;
      v13 = v9 == v10->y;
    }
    else
    {
      v12 = v8 < x;
      v13 = v8 == x;
    }
    if ( v12 || v13 )
    {
      Size >>= 1;
    }
    else
    {
      v7 += (Size >> 1) + 1;
      Size += -1 - (Size >> 1);
    }
  }
  v14 = this->SortedPaths.Size;
  if ( v7 < v14 )
  {
    for ( i = &this->SortedPaths.Array[v7]; v8 == i->x && v9 == i->y; ++i )
    {
      if ( (i->thisPath->numVer & 0x40000000) == 0 )
        return (unsigned int)v7;
      if ( ++v7 >= v14 )
        return 0xFFFFFFFFi64;
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 650
// RVA: 0x9B7080
void __fastcall Scaleform::Render::StrokeSorter::Sort(Scaleform::Render::StrokeSorter *this)
{
  unsigned __int64 Size; // r15
  unsigned __int64 i; // r14
  unsigned __int64 v4; // rbp
  Scaleform::Render::StrokeSorter::PathType v5; // rbx
  Scaleform::Render::StrokeSorter::SortedPathType *v6; // rbp
  Scaleform::Render::StrokeSorter::SortedPathType *Array; // rdx
  unsigned __int64 v8; // r8
  unsigned __int64 v9; // r11
  __int64 v10; // rbx
  Scaleform::Render::StrokeSorter::SortedPathType *v11; // r8
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // r10
  unsigned __int64 start; // rcx
  Scaleform::Render::StrokeSorter::VertexType *v15; // rdx
  unsigned __int64 v16; // rbp
  __int64 v17; // r14
  unsigned int Next; // eax
  Scaleform::Render::StrokeSorter::PathType *thisPath; // rcx
  unsigned __int64 v20; // rsi
  Scaleform::Render::StrokeSorter::VertexType **Pages; // rcx
  unsigned int numVer; // ebx
  float *p_x; // rdx
  float *v24; // r8
  Scaleform::Render::StrokeSorter::VertexType **v25; // rcx
  float *v26; // rdx
  float *v27; // r8
  unsigned __int64 v28; // rsi
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v31; // rbx
  unsigned __int64 v32; // rax
  Scaleform::Render::StrokeSorter::PathType dst; // [rsp+50h] [rbp+8h] BYREF

  Size = this->SrcPaths.Size;
  for ( i = 0i64; i < Size; ++this->SrcPaths.Size )
  {
    v4 = this->SrcPaths.Size >> 4;
    v5 = this->SrcPaths.Pages[i >> 4][i & 0xF];
    if ( v4 >= this->SrcPaths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcPaths,
        this->SrcPaths.Size >> 4);
    ++i;
    this->SrcPaths.Pages[v4][this->SrcPaths.Size & 0xF] = v5;
  }
  if ( Size > this->SortedPaths.Size )
  {
    v6 = (Scaleform::Render::StrokeSorter::SortedPathType *)Scaleform::Render::LinearHeap::Alloc(
                                                              this->SortedPaths.pHeap,
                                                              16 * Size);
    memset(v6, 0, 16 * Size);
    Array = this->SortedPaths.Array;
    if ( Array )
    {
      v8 = this->SortedPaths.Size;
      if ( v8 )
        memmove(v6, Array, 16 * v8);
    }
    this->SortedPaths.Array = v6;
  }
  this->SortedPaths.Size = Size;
  v9 = 0i64;
  if ( Size )
  {
    v10 = 0i64;
    do
    {
      v11 = this->SortedPaths.Array;
      v12 = v9 & 0xF;
      v13 = v9++;
      v13 >>= 4;
      ++v10;
      start = this->SrcPaths.Pages[v13][v12].start;
      v15 = &this->SrcVertices.Pages[start >> 4][start & 0xF];
      v11[v10 - 1].x = v15->x;
      v11[v10 - 1].y = v15->y;
      v11[v10 - 1].thisPath = &this->SrcPaths.Pages[v13][v12];
    }
    while ( v9 < Size );
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::StrokeSorter::SortedPathType>,bool (*)(Scaleform::Render::StrokeSorter::SortedPathType const &,Scaleform::Render::StrokeSorter::SortedPathType const &)>(
    &this->SortedPaths,
    0i64,
    this->SortedPaths.Size,
    (unsigned __int8 (__fastcall *)(Scaleform::Render::StrokeSorter::SortedPathType *))Scaleform::Render::StrokeSorter::cmpPaths);
  v16 = 0i64;
  if ( this->SortedPaths.Size )
  {
    v17 = 0i64;
    do
    {
      if ( (this->SortedPaths.Array[v17].thisPath->numVer & 0x40000000) == 0 )
      {
        Next = v16;
        dst = 0i64;
        do
        {
          thisPath = this->SortedPaths.Array[Next & 0xFFFFFFF].thisPath;
          thisPath->numVer |= 0x40000000u;
          Scaleform::Render::StrokeSorter::appendPath(this, &dst, this->SortedPaths.Array[Next & 0xFFFFFFF].thisPath);
          v20 = dst.start;
          Pages = this->OutVertices.Pages;
          numVer = dst.numVer;
          p_x = &Pages[(unsigned __int64)dst.start >> 4][dst.start & 0xF].x;
          v24 = &Pages[(unsigned __int64)(dst.start + (dst.numVer & 0xFFFFFFF) - 1) >> 4][(LOBYTE(dst.start)
                                                                                         + LOBYTE(dst.numVer)
                                                                                         - 1) & 0xF].x;
          if ( *v24 == *p_x && v24[1] == p_x[1] )
            break;
          Next = Scaleform::Render::StrokeSorter::findNext(this, &dst);
        }
        while ( Next != -1 );
        v25 = this->OutVertices.Pages;
        v26 = &v25[v20 >> 4][v20 & 0xF].x;
        v27 = &v25[(unsigned __int64)((unsigned int)v20 + (numVer & 0xFFFFFFF) - 1) >> 4][((_BYTE)v20 + (_BYTE)numVer - 1) & 0xF].x;
        if ( *v27 == *v26 && v27[1] == v26[1] )
          dst.numVer = numVer | 0x20000000;
        v28 = this->OutPaths.Size >> 4;
        if ( v28 >= this->OutPaths.NumPages )
        {
          MaxPages = this->OutPaths.MaxPages;
          if ( v28 >= MaxPages )
          {
            pHeap = this->OutPaths.pHeap;
            if ( this->OutPaths.Pages )
            {
              v31 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
              memmove(v31, this->OutPaths.Pages, 8 * this->OutPaths.NumPages);
              v32 = this->OutPaths.MaxPages;
              this->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)v31;
              this->OutPaths.MaxPages = 2 * v32;
            }
            else
            {
              this->OutPaths.MaxPages = 16i64;
              this->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                     pHeap,
                                                                                     0x80ui64);
            }
          }
          this->OutPaths.Pages[v28] = (Scaleform::Render::StrokeSorter::PathType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                     this->OutPaths.pHeap,
                                                                                     0x80ui64);
          ++this->OutPaths.NumPages;
        }
        this->OutPaths.Pages[v28][this->OutPaths.Size & 0xF] = dst;
        ++this->OutPaths.Size;
      }
      ++v16;
      ++v17;
    }
    while ( v16 < this->SortedPaths.Size );
  }
}

// File Line: 710
// RVA: 0x954670
void __fastcall Scaleform::Render::StrokeSorter::AddOffset(
        Scaleform::Render::StrokeSorter *this,
        float offsetX,
        float offsetY)
{
  unsigned int v3; // edi
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rcx
  __int64 v7; // rdx
  unsigned int v8; // ebx
  Scaleform::Render::StrokeSorter::PathType *v9; // rcx
  unsigned int start; // ebp
  unsigned int v11; // r11d
  unsigned int v12; // r10d
  unsigned int v13; // eax
  __int64 v14; // rsi
  unsigned __int64 v15; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v16; // rcx
  __int64 v17; // r8
  Scaleform::Render::StrokeSorter::VertexType *v18; // rcx
  unsigned __int64 v19; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v20; // rcx
  __int64 v21; // r8
  Scaleform::Render::StrokeSorter::VertexType *v22; // rcx
  unsigned __int64 v23; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v24; // rcx
  __int64 v25; // r8
  Scaleform::Render::StrokeSorter::VertexType *v26; // rcx
  unsigned int v27; // eax
  unsigned __int64 v28; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v29; // rcx
  __int64 v30; // r8
  Scaleform::Render::StrokeSorter::VertexType *v31; // rcx
  unsigned int v32; // r10d
  __int64 v33; // r11
  unsigned __int64 v34; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v35; // rcx
  __int64 v36; // r8
  Scaleform::Render::StrokeSorter::VertexType *v37; // rcx

  v3 = 0;
  if ( this->OutPaths.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = v5;
      v7 = v5 & 0xF;
      v8 = 0;
      v9 = this->OutPaths.Pages[v6 >> 4];
      start = v9[v7].start;
      v11 = v9[v7].numVer & 0xFFFFFFF;
      if ( v11 >= 4 )
      {
        v12 = start + 1;
        v13 = ((v11 - 4) >> 2) + 1;
        v14 = v13;
        v8 = 4 * v13;
        do
        {
          v15 = (unsigned __int64)(v12 - 1) >> 4;
          v16 = this->OutVertices.Pages[v15];
          v17 = ((_BYTE)v12 - 1) & 0xF;
          v16[v17].x = offsetX + v16[((_BYTE)v12 - 1) & 0xF].x;
          v18 = this->OutVertices.Pages[v15];
          v19 = (unsigned __int64)v12 >> 4;
          v18[v17].y = offsetY + v18[((_BYTE)v12 - 1) & 0xF].y;
          v20 = this->OutVertices.Pages[v19];
          v21 = v12 & 0xF;
          v20[v21].x = offsetX + v20[v12 & 0xF].x;
          v22 = this->OutVertices.Pages[v19];
          v23 = (unsigned __int64)(v12 + 1) >> 4;
          v22[v21].y = offsetY + v22[v12 & 0xF].y;
          v24 = this->OutVertices.Pages[v23];
          v25 = ((_BYTE)v12 + 1) & 0xF;
          v24[v25].x = offsetX + v24[((_BYTE)v12 + 1) & 0xF].x;
          v26 = this->OutVertices.Pages[v23];
          v27 = v12 + 2;
          v12 += 4;
          v28 = (unsigned __int64)v27 >> 4;
          v26[v25].y = offsetY + v26[v25].y;
          v29 = this->OutVertices.Pages[v28];
          v30 = v27 & 0xF;
          v29[v30].x = offsetX + v29[v30].x;
          v31 = this->OutVertices.Pages[v28];
          v31[v30].y = offsetY + v31[v27 & 0xF].y;
          --v14;
        }
        while ( v14 );
      }
      if ( v8 < v11 )
      {
        v32 = v8 + start;
        v33 = v11 - v8;
        do
        {
          v34 = (unsigned __int64)v32 >> 4;
          v35 = this->OutVertices.Pages[v34];
          v36 = v32++ & 0xF;
          v35[v36].x = offsetX + v35[v36].x;
          v37 = this->OutVertices.Pages[v34];
          v37[v36].y = offsetY + v37[v36].y;
          --v33;
        }
        while ( v33 );
      }
      v5 = ++v3;
    }
    while ( v3 < this->OutPaths.Size );
  }
}

// File Line: 728
// RVA: 0x9B6C00
void __fastcall Scaleform::Render::StrokeSorter::Snap(
        Scaleform::Render::StrokeSorter *this,
        float offsetX,
        float offsetY)
{
  unsigned int v3; // r15d
  unsigned __int64 v7; // rdx
  Scaleform::Render::StrokeSorter::VertexType **Pages; // rdi
  unsigned __int64 v9; // rcx
  __int64 v10; // rdx
  char v11; // r10
  Scaleform::Render::StrokeSorter::PathType *v12; // rcx
  char v13; // r11
  unsigned int v14; // r9d
  unsigned int start; // esi
  unsigned int numVer; // edx
  unsigned int v17; // ebp
  float *p_x; // rcx
  unsigned int v19; // r8d
  unsigned int v20; // eax
  __int64 v21; // rbx
  float *v22; // rdx
  float v23; // xmm2_4
  float v24; // xmm1_4
  float *v25; // rcx
  float v26; // xmm2_4
  float v27; // xmm1_4
  float *v28; // rdx
  float v29; // xmm2_4
  float *v30; // rdx
  unsigned int v31; // r8d
  __int64 v32; // r10
  Scaleform::Render::StrokeSorter::VertexType *v33; // r9
  __int64 v34; // rdx
  __m128 x_low; // xmm1
  int v36; // ecx
  __int64 v37; // r9
  Scaleform::Render::StrokeSorter::VertexType *v38; // r8
  __int64 v39; // rdx
  __m128 y_low; // xmm1
  int v41; // ecx

  v3 = 0;
  if ( this->OutPaths.Size )
  {
    v7 = 0i64;
    do
    {
      Pages = this->OutVertices.Pages;
      v9 = v7 >> 4;
      v10 = v7 & 0xF;
      v11 = 0;
      v12 = this->OutPaths.Pages[v9];
      v13 = 0;
      v14 = 1;
      start = v12[v10].start;
      numVer = v12[v10].numVer;
      v17 = numVer & 0xFFFFFFF;
      p_x = &Pages[(unsigned __int64)start >> 4][start & 0xF].x;
      if ( (numVer & 0x20000000) != 0 )
      {
        v14 = 0;
        p_x = &Pages[(unsigned __int64)((numVer & 0xFFFFFFF) + start - 1) >> 4][((_BYTE)numVer + (_BYTE)start - 1) & 0xF].x;
      }
      if ( v14 < v17 )
      {
        if ( (int)(v17 - v14) >= 4 )
        {
          v19 = v14 + start + 1;
          v20 = ((v17 - v14 - 4) >> 2) + 1;
          v21 = v20;
          v14 += 4 * v20;
          do
          {
            v22 = &Pages[(unsigned __int64)(v19 - 1) >> 4][((_BYTE)v19 - 1) & 0xF].x;
            v23 = *v22;
            if ( *p_x == *v22 && v22[1] != p_x[1] )
              v11 = 1;
            if ( v22[1] == p_x[1] && *p_x != v23 )
              v13 = 1;
            v24 = v23;
            v25 = &Pages[(unsigned __int64)v19 >> 4][v19 & 0xF].x;
            v26 = *v25;
            if ( v24 == *v25 && v25[1] != v22[1] )
              v11 = 1;
            if ( v25[1] == v22[1] && v24 != v26 )
              v13 = 1;
            v27 = v26;
            v28 = &Pages[(unsigned __int64)(v19 + 1) >> 4][((_BYTE)v19 + 1) & 0xF].x;
            v29 = *v28;
            if ( v27 == *v28 && v28[1] != v25[1] )
              v11 = 1;
            if ( v28[1] == v25[1] && v27 != v29 )
              v13 = 1;
            p_x = &Pages[(unsigned __int64)(v19 + 2) >> 4][((_BYTE)v19 + 2) & 0xF].x;
            if ( v29 == *p_x && p_x[1] != v28[1] )
              v11 = 1;
            if ( p_x[1] == v28[1] && v29 != *p_x )
              v13 = 1;
            v19 += 4;
            --v21;
          }
          while ( v21 );
        }
        for ( ; v14 < v17; p_x = v30 )
        {
          v30 = &Pages[(unsigned __int64)(v14 + start) >> 4][((_BYTE)v14 + (_BYTE)start) & 0xF].x;
          if ( *p_x == *v30 && v30[1] != p_x[1] )
            v11 = 1;
          if ( v30[1] == p_x[1] && *p_x != *v30 )
            v13 = 1;
          ++v14;
        }
        if ( v11 && v17 )
        {
          v31 = start;
          v32 = v17;
          do
          {
            v33 = this->OutVertices.Pages[(unsigned __int64)v31 >> 4];
            v34 = v31 & 0xF;
            x_low = (__m128)LODWORD(v33[v31 & 0xF].x);
            if ( x_low.m128_f32[0] >= 0.0 )
              x_low.m128_f32[0] = x_low.m128_f32[0] + 0.5;
            else
              x_low.m128_f32[0] = x_low.m128_f32[0] - 0.5;
            v36 = (int)x_low.m128_f32[0];
            if ( (int)x_low.m128_f32[0] != 0x80000000 && (float)v36 != x_low.m128_f32[0] )
              x_low.m128_f32[0] = (float)(v36 - (_mm_movemask_ps(_mm_unpacklo_ps(x_low, x_low)) & 1));
            ++v31;
            v33[v34].x = x_low.m128_f32[0] + offsetX;
            --v32;
          }
          while ( v32 );
        }
        if ( v13 && v17 )
        {
          v37 = v17;
          do
          {
            v38 = this->OutVertices.Pages[(unsigned __int64)start >> 4];
            v39 = start & 0xF;
            y_low = (__m128)LODWORD(v38[start & 0xF].y);
            if ( y_low.m128_f32[0] >= 0.0 )
              y_low.m128_f32[0] = y_low.m128_f32[0] + 0.5;
            else
              y_low.m128_f32[0] = y_low.m128_f32[0] - 0.5;
            v41 = (int)y_low.m128_f32[0];
            if ( (int)y_low.m128_f32[0] != 0x80000000 && (float)v41 != y_low.m128_f32[0] )
              y_low.m128_f32[0] = (float)(v41 - (_mm_movemask_ps(_mm_unpacklo_ps(y_low, y_low)) & 1));
            ++start;
            v38[v39].y = y_low.m128_f32[0] + offsetY;
            --v37;
          }
          while ( v37 );
        }
      }
      v7 = ++v3;
    }
    while ( v3 < this->OutPaths.Size );
  }
}

// File Line: 791
// RVA: 0x97E720
void __fastcall Scaleform::Render::StrokeSorter::GenerateDashes(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::DashArray *da,
        Scaleform::Render::ToleranceParams *param,
        float scale)
{
  unsigned int CurveRecursionLimit; // eax
  unsigned int v7; // r12d
  __int64 v8; // xmm1_8
  unsigned __int64 v9; // r14
  __int64 v10; // rsi
  unsigned int v11; // ebx
  unsigned int v12; // r15d
  unsigned int v13; // ecx
  Scaleform::Render::StrokeSorter::PathType *v14; // r8
  unsigned int v15; // eax
  Scaleform::Render::StrokeSorter::VertexType **Pages; // r10
  __int64 v17; // rdx
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  char v22; // r9
  unsigned __int64 v23; // rax
  unsigned int v24; // ecx
  float *v25; // r9
  unsigned int v26; // eax
  float y3; // xmm9_4
  float x3; // xmm10_4
  float y2; // xmm11_4
  float x2; // xmm12_4
  float *v31; // rcx
  float v32; // xmm7_4
  float x4; // xmm8_4
  double v34; // xmm0_8
  float v35; // xmm6_4
  unsigned int v36; // ecx
  unsigned int v37; // eax
  float *p_x; // rcx
  signed int DashCount; // r9d
  unsigned int v40; // r14d
  unsigned int v41; // r11d
  __int64 v42; // rbx
  int v43; // r8d
  float *v44; // rdx
  unsigned int v45; // eax
  __int64 v46; // r10
  __int64 v47; // rcx
  float v48; // eax
  __int64 v49; // rcx
  float *v50; // rdx
  __int64 v51; // r8
  float v52; // eax
  __int64 v53; // rcx
  unsigned int v54; // r11d
  __int64 v55; // rbx
  __int64 v56; // r8
  float *v57; // rdx
  unsigned int v58; // eax
  __int64 v59; // r10
  __int64 v60; // rcx
  __int64 v61; // rcx
  float v62; // eax
  float *v63; // rdx
  __int64 v64; // r8
  float v65; // eax
  __int64 v66; // rcx
  unsigned int v67; // r15d
  unsigned int v68; // r12d
  unsigned __int64 v69; // rdx
  unsigned __int64 v70; // rcx
  __int64 v71; // rdx
  Scaleform::Render::StrokeSorter::PathType *v72; // rcx
  unsigned int i; // eax
  unsigned __int64 Size; // rsi
  unsigned __int64 v75; // rsi
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v78; // rbx
  unsigned __int64 v79; // rax
  float v80; // xmm6_4
  float v81; // xmm7_4
  unsigned __int64 v82; // rsi
  unsigned __int64 v83; // rdx
  Scaleform::Render::LinearHeap *v84; // rcx
  void *v85; // rbx
  unsigned __int64 v86; // rax
  Scaleform::Render::StrokeSorter::VertexType *v87; // rcx
  __int64 v88; // rdx
  unsigned __int64 v89; // rcx
  Scaleform::Render::StrokeSorter::PathType *v90; // rax
  BOOL y1; // [rsp+20h] [rbp-A8h]
  _BYTE v92[24]; // [rsp+68h] [rbp-60h] BYREF
  unsigned int param_16; // [rsp+80h] [rbp-48h]
  float param_24[32]; // [rsp+88h] [rbp-40h] BYREF
  Scaleform::Render::DashGenerator v95; // [rsp+108h] [rbp+40h] BYREF
  float x; // [rsp+218h] [rbp+150h] BYREF
  Scaleform::Render::StrokeSorter::PathType v97; // [rsp+220h] [rbp+158h]
  float y[4]; // [rsp+230h] [rbp+168h] BYREF

  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->SrcPaths.MaxPages = 0i64;
  this->SrcPaths.NumPages = 0i64;
  this->SrcPaths.Size = 0i64;
  this->SrcPaths.Pages = 0i64;
  this->LastVertex = 0;
  CurveRecursionLimit = param->CurveRecursionLimit;
  *(_OWORD *)&v92[8] = *(_OWORD *)&param->Epsilon;
  v7 = 0;
  param_16 = CurveRecursionLimit;
  v8 = *(_QWORD *)&param->MinDet3D;
  *(_OWORD *)v92 = *(_OWORD *)&param->Scale9LowerScale;
  *(_QWORD *)&v92[16] = v8;
  for ( *(float *)&v92[12] = *(float *)&v92[12] * (float)(1.0 / scale); v7 < LODWORD(this->OutPaths.Size); ++v7 )
  {
    v9 = (unsigned __int64)v7 >> 4;
    v10 = v7 & 0xF;
    v11 = 0;
    v12 = this->OutPaths.Pages[v9][v10].numVer & 0xFFFFFFF;
    if ( v12 )
    {
      do
      {
        v13 = v11;
        v14 = this->OutPaths.Pages[v9];
        v15 = v14[v10].numVer & 0xFFFFFFF;
        if ( v11 >= v15 )
          v13 = v11 - v15;
        Pages = this->OutVertices.Pages;
        ++v11;
        v17 = (__int64)&Pages[(unsigned __int64)(v13 + v14[v10].start) >> 4][((_BYTE)v13 + LOBYTE(v14[v10].start)) & 0xF];
        switch ( *(_BYTE *)(v17 + 12) )
        {
          case 1:
            ((void (__fastcall *)(Scaleform::Render::StrokeSorter *))this->vfptr->AddVertex)(this);
            break;
          case 2:
            v36 = v11;
            v37 = v14[v10].numVer & 0xFFFFFFF;
            if ( v11 >= v37 )
              v36 = v11 - v37;
            ++v11;
            p_x = &Pages[(unsigned __int64)(v36 + v14[v10].start) >> 4][((_BYTE)v36 + LOBYTE(v14[v10].start)) & 0xF].x;
            Scaleform::Render::TessellateQuadCurve(
              this,
              (Scaleform::Render::ToleranceParams *)&v92[8],
              *(float *)v17,
              *(float *)(v17 + 4),
              *p_x,
              p_x[1]);
            break;
          case 3:
            v18 = v11;
            v19 = v14[v10].numVer & 0xFFFFFFF;
            if ( v11 >= v19 )
              v18 = v11 - v19;
            v20 = v14[v10].start + v18;
            v21 = v11 + 1;
            v22 = v20;
            v23 = v20;
            v24 = v21;
            v25 = &Pages[v23 >> 4][v22 & 0xF].x;
            v26 = v14[v10].numVer & 0xFFFFFFF;
            if ( v21 >= v26 )
              v24 = v21 - v26;
            y3 = v25[1];
            x3 = *v25;
            v11 = v21 + 1;
            y2 = *(float *)(v17 + 4);
            x2 = *(float *)v17;
            v31 = &Pages[(unsigned __int64)(v24 + v14[v10].start) >> 4][((_BYTE)v24 + LOBYTE(v14[v10].start)) & 0xF].x;
            v32 = v31[1];
            x4 = *v31;
            v34 = ((double (__fastcall *)(Scaleform::Render::StrokeSorter *))this->vfptr->GetLastX)(this);
            v35 = *(float *)&v34;
            *(float *)&v34 = this->vfptr->GetLastY(this);
            Scaleform::Render::TessellateCubicRecursively(
              this,
              (Scaleform::Render::ToleranceParams *)&v92[8],
              (float)(*(float *)&v92[12] * 0.25) * (float)(*(float *)&v92[12] * 0.25),
              v35,
              *(float *)&v34,
              x2,
              y2,
              x3,
              y3,
              x4,
              v32,
              0);
            break;
        }
      }
      while ( v11 < v12 );
    }
    LOBYTE(y1) = 0;
    this->vfptr->FinalizePath(this, (this->OutPaths.Pages[v9][v10].numVer >> 29) & 1, 0, 0, y1);
  }
  this->OutVertices.MaxPages = 0i64;
  this->OutVertices.NumPages = 0i64;
  this->OutVertices.Size = 0i64;
  this->OutVertices.Pages = 0i64;
  this->OutPaths.MaxPages = 0i64;
  this->OutPaths.NumPages = 0i64;
  this->OutPaths.Size = 0i64;
  this->OutPaths.Pages = 0i64;
  DashCount = da->DashCount;
  v40 = 0;
  v41 = 0;
  v42 = 0i64;
  if ( DashCount >= 4 )
  {
    v43 = 2;
    v44 = &da->Dashes[1];
    v45 = ((unsigned int)(DashCount - 4) >> 2) + 1;
    v46 = v45;
    v41 = 4 * v45;
    v42 = 4i64 * v45;
    do
    {
      v47 = v40;
      v40 += 4;
      param_24[v47] = *(v44 - 1);
      param_24[v43 - 1] = *v44;
      param_24[v43] = v44[1];
      v48 = v44[2];
      v49 = (unsigned int)(v43 + 1);
      v43 += 4;
      v44 += 4;
      param_24[v49] = v48;
      --v46;
    }
    while ( v46 );
  }
  if ( v41 < DashCount )
  {
    v50 = &da->Dashes[v42];
    v51 = DashCount - v41;
    do
    {
      v52 = *v50;
      v53 = v40++;
      ++v50;
      param_24[v53] = v52;
      --v51;
    }
    while ( v51 );
  }
  if ( (v40 & 1) != 0 )
  {
    v54 = 0;
    v55 = 0i64;
    if ( DashCount >= 4 )
    {
      v56 = v40 + 2;
      v57 = &da->Dashes[1];
      v58 = ((unsigned int)(DashCount - 4) >> 2) + 1;
      v59 = v58;
      v54 = 4 * v58;
      v55 = 4i64 * v58;
      do
      {
        v60 = v40;
        v40 += 4;
        param_24[v60] = *(v57 - 1);
        param_24[(unsigned int)(v56 - 1)] = *v57;
        v61 = (unsigned int)(v56 + 1);
        param_24[v56] = v57[1];
        v62 = v57[2];
        v57 += 4;
        v56 = (unsigned int)(v56 + 4);
        param_24[v61] = v62;
        --v59;
      }
      while ( v59 );
    }
    if ( v54 < DashCount )
    {
      v63 = &da->Dashes[v55];
      v64 = DashCount - v54;
      do
      {
        v65 = *v63;
        v66 = v40++;
        ++v63;
        param_24[v66] = v65;
        --v64;
      }
      while ( v64 );
    }
  }
  v67 = 0;
  v68 = 0;
  if ( this->SrcPaths.Size )
  {
    v69 = 0i64;
    do
    {
      v70 = v69;
      v71 = v69 & 0xF;
      v72 = this->SrcPaths.Pages[v70 >> 4];
      Scaleform::Render::DashGenerator::DashGenerator(
        &v95,
        param_24,
        v40,
        da->DashStart,
        &this->SrcVertices.Pages[(unsigned __int64)v72[v71].start >> 4][v72[v71].start & 0xF],
        v72[v71].numVer & 0xFFFFFFF,
        (v72[v71].numVer & 0x20000000) != 0);
      for ( i = Scaleform::Render::DashGenerator::GetVertex(&v95, &x, y);
            i != 4;
            i = Scaleform::Render::DashGenerator::GetVertex(&v95, &x, y) )
      {
        if ( !i )
        {
          Size = this->OutPaths.Size;
          v97 = (Scaleform::Render::StrokeSorter::PathType)v67;
          v75 = Size >> 4;
          if ( v75 >= this->OutPaths.NumPages )
          {
            MaxPages = this->OutPaths.MaxPages;
            if ( v75 >= MaxPages )
            {
              pHeap = this->OutPaths.pHeap;
              if ( this->OutPaths.Pages )
              {
                v78 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
                memmove(v78, this->OutPaths.Pages, 8 * this->OutPaths.NumPages);
                v79 = this->OutPaths.MaxPages;
                this->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)v78;
                this->OutPaths.MaxPages = 2 * v79;
              }
              else
              {
                this->OutPaths.MaxPages = 16i64;
                this->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                       pHeap,
                                                                                       0x80ui64);
              }
            }
            this->OutPaths.Pages[v75] = (Scaleform::Render::StrokeSorter::PathType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                       this->OutPaths.pHeap,
                                                                                       0x80ui64);
            ++this->OutPaths.NumPages;
          }
          this->OutPaths.Pages[v75][this->OutPaths.Size & 0xF] = v97;
          ++this->OutPaths.Size;
        }
        v80 = x;
        v81 = y[0];
        v82 = this->OutVertices.Size >> 4;
        *(_WORD *)&v92[4] = 1;
        v92[6] = 0;
        if ( v82 >= this->OutVertices.NumPages )
        {
          v83 = this->OutVertices.MaxPages;
          if ( v82 >= v83 )
          {
            v84 = this->OutVertices.pHeap;
            if ( this->OutVertices.Pages )
            {
              v85 = Scaleform::Render::LinearHeap::Alloc(v84, 16 * v83);
              memmove(v85, this->OutVertices.Pages, 8 * this->OutVertices.NumPages);
              v86 = this->OutVertices.MaxPages;
              this->OutVertices.Pages = (Scaleform::Render::StrokeSorter::VertexType **)v85;
              this->OutVertices.MaxPages = 2 * v86;
            }
            else
            {
              this->OutVertices.MaxPages = 16i64;
              this->OutVertices.Pages = (Scaleform::Render::StrokeSorter::VertexType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                          v84,
                                                                                          0x80ui64);
            }
          }
          this->OutVertices.Pages[v82] = (Scaleform::Render::StrokeSorter::VertexType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                          this->OutVertices.pHeap,
                                                                                          0x100ui64);
          ++this->OutVertices.NumPages;
        }
        v87 = this->OutVertices.Pages[v82];
        v88 = this->OutVertices.Size & 0xF;
        ++v67;
        v87[v88].x = v80;
        v87[v88].y = v81;
        v87[v88].Dist = 0.0;
        *(_DWORD *)&v87[v88].segType = *(_DWORD *)&v92[4];
        ++this->OutVertices.Size;
        v89 = this->OutPaths.Size - 1;
        v90 = this->OutPaths.Pages[v89 >> 4];
        ++v90[v89 & 0xF].numVer;
      }
      v69 = ++v68;
    }
    while ( v68 < this->SrcPaths.Size );
  }
}

// File Line: 901
// RVA: 0x93AE60
void __fastcall Scaleform::Render::DashGenerator::DashGenerator(
        Scaleform::Render::DashGenerator *this,
        const float *dashArray,
        unsigned int dashCount,
        float dashStart,
        Scaleform::Render::StrokeSorter::VertexType *ver,
        unsigned int verCount,
        bool closed)
{
  unsigned int v7; // r10d
  __int64 CurrDash; // rax
  float v10; // xmm0_4
  unsigned int v11; // eax
  unsigned int v12; // ecx
  Scaleform::Render::StrokeSorter::VertexType *Vertices; // rdx
  unsigned int v14; // r11d
  __int64 v15; // r8
  __m128 y_low; // xmm0
  float v17; // xmm1_4
  float v18; // xmm2_4
  __int64 v19; // rcx
  __int64 v20; // rcx
  bool v21; // zf
  Scaleform::Render::StrokeSorter::VertexType *v22; // rdx
  __m128 v23; // xmm0
  float v24; // xmm2_4
  __m128 v25; // xmm0

  v7 = 0;
  this->Vertices = ver;
  this->DashStart = dashStart;
  this->pDashArray = dashArray;
  this->DashCount = dashCount;
  *(_QWORD *)&this->CurrDash = 0i64;
  this->CurrDashStart = 0.0;
  this->Closed = closed;
  this->Ver1 = 0i64;
  this->Ver2 = 0i64;
  *(_QWORD *)&this->Status = 0i64;
  this->VerCount = verCount;
  if ( dashStart > 0.0 )
  {
    this->CurrDash = 0;
    this->CurrDashStart = 0.0;
    while ( 1 )
    {
      CurrDash = this->CurrDash;
      v10 = dashArray[CurrDash];
      if ( dashStart <= v10 )
        break;
      v11 = CurrDash + 1;
      dashStart = dashStart - v10;
      this->CurrDashStart = 0.0;
      if ( v11 >= dashCount )
        v11 = 0;
      this->CurrDash = v11;
      if ( dashStart <= 0.0 )
        goto LABEL_9;
    }
    this->CurrDashStart = dashStart;
  }
LABEL_9:
  if ( verCount > 1 )
  {
    v12 = 0;
    do
    {
      Vertices = this->Vertices;
      v14 = v12 + 1;
      v15 = v12;
      y_low = (__m128)LODWORD(Vertices[v12 + 1].y);
      y_low.m128_f32[0] = y_low.m128_f32[0] - Vertices[v12].y;
      v17 = Vertices[v12 + 1].x - Vertices[v12].x;
      y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v17 * v17);
      v18 = _mm_sqrt_ps(y_low).m128_f32[0];
      if ( v18 > 1.0e-10 )
      {
        if ( v7 < v12 )
        {
          v19 = v7;
          Vertices[v19].x = Vertices[v15].x;
          Vertices[v19].y = Vertices[v15].y;
          Vertices[v19].Dist = Vertices[v15].Dist;
          *(_DWORD *)&Vertices[v19].segType = *(_DWORD *)&Vertices[v15].segType;
        }
        v20 = v7++;
        this->Vertices[v20].Dist = v18;
      }
      v12 = v14;
    }
    while ( v14 + 1 < this->VerCount );
  }
  this->Vertices[v7].Dist = 1.0e10;
  v21 = !this->Closed;
  this->VerCount = v7 + 1;
  if ( !v21 && v7 + 1 > 2 )
  {
    v22 = this->Vertices;
    v23 = (__m128)LODWORD(v22[v7].y);
    v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] - v22->y) * (float)(v23.m128_f32[0] - v22->y))
                    + (float)((float)(v22[v7].x - v22->x) * (float)(v22[v7].x - v22->x));
    v24 = _mm_sqrt_ps(v23).m128_f32[0];
    if ( v24 <= 1.0e-10 )
    {
      this->VerCount = v7;
      v25 = (__m128)LODWORD(v22[v7 - 1].y);
      v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] - v22->y) * (float)(v25.m128_f32[0] - v22->y))
                      + (float)((float)(v22[v7 - 1].x - v22->x) * (float)(v22[v7 - 1].x - v22->x));
      LODWORD(v22[v7 - 1].Dist) = _mm_sqrt_ps(v25).m128_u32[0];
    }
    else
    {
      v22[v7].Dist = v24;
    }
  }
}

// File Line: 965
// RVA: 0x98EBC0
__int64 __fastcall Scaleform::Render::DashGenerator::GetVertex(
        Scaleform::Render::DashGenerator *this,
        float *x,
        float *y)
{
  Scaleform::Render::DashGenerator::DashStatus Status; // r10d
  __int64 result; // rax
  __int64 CurrDash; // rcx
  float CurrDashStart; // xmm1_4
  float CurrRest; // xmm2_4
  BOOL v10; // edx
  float v11; // xmm0_4
  float v12; // xmm2_4
  unsigned int v13; // eax
  Scaleform::Render::StrokeSorter::VertexType *Ver1; // rcx
  bool v15; // cf
  Scaleform::Render::StrokeSorter::VertexType *Ver2; // rax
  bool v17; // zf
  Scaleform::Render::StrokeSorter::VertexType *v18; // rax
  __int64 SrcVertex; // rcx
  unsigned int VerCount; // eax
  Scaleform::Render::StrokeSorter::VertexType *Vertices; // rcx

  Status = this->Status;
  while ( Status )
  {
    if ( Status == Status_Polyline )
    {
      CurrDash = this->CurrDash;
      CurrDashStart = this->CurrDashStart;
      CurrRest = this->CurrRest;
      v10 = (this->CurrDash & 1) == 0;
      v11 = (float)this->pDashArray[CurrDash] - CurrDashStart;
      if ( CurrRest > v11 )
      {
        v12 = CurrRest - v11;
        v13 = CurrDash + 1;
        Ver1 = this->Ver1;
        this->CurrRest = v12;
        v15 = v13 < this->DashCount;
        this->CurrDashStart = 0.0;
        if ( !v15 )
          v13 = 0;
        this->CurrDash = v13;
        *x = this->Ver2->x - (float)((float)((float)(this->Ver2->x - Ver1->x) * v12) / Ver1->Dist);
        result = v10;
        *y = this->Ver2->y
           - (float)((float)((float)(this->Ver2->y - this->Ver1->y) * this->CurrRest) / this->Ver1->Dist);
        return result;
      }
      Ver2 = this->Ver2;
      this->CurrDashStart = CurrRest + CurrDashStart;
      *x = Ver2->x;
      *y = this->Ver2->y;
      ++this->SrcVertex;
      v17 = !this->Closed;
      v18 = this->Ver2;
      SrcVertex = this->SrcVertex;
      this->Ver1 = v18;
      this->CurrRest = v18->Dist;
      if ( v17 )
      {
        if ( (unsigned int)SrcVertex < this->VerCount )
        {
          result = v10;
          this->Ver2 = &this->Vertices[SrcVertex];
          return result;
        }
      }
      else
      {
        VerCount = this->VerCount;
        if ( (unsigned int)SrcVertex <= VerCount )
        {
          if ( (unsigned int)SrcVertex >= VerCount )
            LODWORD(SrcVertex) = 0;
          this->Ver2 = &this->Vertices[(unsigned int)SrcVertex];
          return v10;
        }
      }
      this->Status = Status_Stop;
      return v10;
    }
    if ( Status == Status_Stop )
      return 4i64;
  }
  if ( this->DashCount < 2 || this->VerCount < 2 )
    return 4i64;
  Vertices = this->Vertices;
  this->Status = Status_Polyline;
  this->Ver1 = Vertices;
  this->SrcVertex = 1;
  this->Ver2 = Vertices + 1;
  this->CurrRest = Vertices->Dist;
  *x = Vertices->x;
  result = 0i64;
  *y = this->Ver1->y;
  return result;
}

