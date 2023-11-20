// File Line: 46
// RVA: 0x954DC0
void __fastcall Scaleform::Render::StrokePath::AddVertex(Scaleform::Render::StrokePath *this, Scaleform::Render::StrokeVertex *v)
{
  unsigned __int64 v2; // r8
  Scaleform::Render::StrokeVertex *v3; // rsi
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *v4; // rbx
  __m128 v5; // xmm0
  signed __int64 v6; // r8
  unsigned __int64 v7; // r9
  signed __int64 v8; // r8
  Scaleform::Render::StrokeVertex *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm1_4
  unsigned __int64 v12; // rdi
  Scaleform::Render::StrokerAA::VertexType *v13; // rdx
  signed __int64 v14; // r8

  v2 = this->Path.Size;
  v3 = v;
  v4 = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)this;
  if ( !v2 )
    goto LABEL_8;
  v5 = (__m128)LODWORD(v->y);
  v6 = v2 - 1;
  v7 = v6;
  v8 = v6 & 0xF;
  v9 = this->Path.Pages[v7 >> 4];
  v5.m128_f32[0] = v5.m128_f32[0] - v9[v8].y;
  v10 = v->x - v9[v8].x;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v10 * v10);
  LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v5);
  v9[v8].dist = v11;
  if ( v11 > 0.0 )
  {
LABEL_8:
    v12 = v4->Size >> 4;
    if ( v12 >= v4->NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(v4, v4->Size >> 4);
    v13 = v4->Pages[v12];
    v14 = v4->Size & 0xF;
    v13[v14].x = v3->x;
    v13[v14].y = v3->y;
    *(float *)&v13[v14].style = v3->dist;
    ++v4->Size;
  }
}

// File Line: 55
// RVA: 0x961590
bool __fastcall Scaleform::Render::StrokePath::ClosePath(Scaleform::Render::StrokePath *this)
{
  unsigned __int64 v1; // rax
  Scaleform::Render::StrokePath *v2; // r10
  Scaleform::Render::StrokeVertex **v3; // r8
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  __m128 v6; // xmm0
  Scaleform::Render::StrokeVertex *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm1_4
  unsigned __int64 v10; // rax

  v1 = this->Path.Size;
  v2 = this;
  if ( v1 <= 1 )
    return 0;
  v3 = this->Path.Pages;
  v4 = v1 - 1;
  v5 = v4 & 0xF;
  v6 = (__m128)LODWORD((*v3)->y);
  v7 = v3[v4 >> 4];
  v6.m128_f32[0] = v6.m128_f32[0] - v7[v5].y;
  v8 = (*v3)->x - v7[v5].x;
  v6.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v8 * v8);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v6);
  v7[v5].dist = v9;
  if ( v9 > 0.0 )
    return 0;
  v10 = v2->Path.Size;
  if ( v10 )
    v2->Path.Size = v10 - 1;
  return v2->Path.Size > 2;
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
  Scaleform::Render::Stroker *v1; // rbx

  v1 = this;
  Scaleform::Render::StrokePath::ClosePath(&this->Path);
  v1->Closed = 1;
}

// File Line: 107
// RVA: 0x97F6F0
void __fastcall Scaleform::Render::Stroker::GenerateStroke(Scaleform::Render::Stroker *this, Scaleform::Render::TessBase *tess)
{
  Scaleform::Render::TessBase *v2; // r14
  Scaleform::Render::Stroker *v3; // rdi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // r10
  unsigned __int64 v10; // r8
  Scaleform::Render::StrokeVertex *v11; // r9
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rbp
  signed __int64 v14; // rax
  unsigned __int64 v15; // r11
  signed __int64 v16; // rax
  unsigned __int64 v17; // r10
  unsigned __int64 v18; // rax
  Scaleform::Render::StrokeVertex **v19; // rdx
  Scaleform::Render::StrokeVertex *v20; // r9
  unsigned __int64 v21; // r9
  unsigned __int64 v22; // rsi
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rcx
  unsigned __int64 v25; // r10
  unsigned __int64 v26; // r8
  Scaleform::Render::StrokeVertex *v27; // r9
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rbp
  unsigned __int64 v30; // rax
  unsigned __int64 v31; // r11
  unsigned __int64 v32; // rax
  unsigned __int64 v33; // r10
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // rsi
  Scaleform::Render::StrokeVertex **v36; // rdx
  Scaleform::Render::StrokeVertex *v37; // r9

  v2 = tess;
  v3 = this;
  if ( !this->Closed )
    this->Closed = Scaleform::Render::StrokePath::ClosePath(&this->Path);
  v4 = v3->Path.Path.Size;
  if ( v4 > 1 )
  {
    if ( v3->Closed )
    {
      v5 = 0i64;
      if ( v4 )
      {
        do
        {
          v6 = v5;
          if ( !v5 )
            v6 = v3->Path.Path.Size;
          v7 = v3->Path.Path.Size;
          v8 = v5 + 1;
          v9 = v5 + 1;
          if ( v5 + 1 >= v7 )
            v9 -= v7;
          v10 = v5;
          if ( !v5 )
            v10 = v3->Path.Path.Size;
          v11 = &v3->Path.Path.Pages[v5 >> 4][v5 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            v3,
            v2,
            &v3->Path.Path.Pages[(v10 - 1) >> 4][((_DWORD)v10 - 1) & 0xF],
            v11,
            &v3->Path.Path.Pages[v9 >> 4][v9 & 0xF],
            v3->Path.Path.Pages[(v6 - 1) >> 4][((_DWORD)v6 - 1) & 0xF].dist,
            v11->dist);
          v5 = v8;
        }
        while ( v8 < v3->Path.Path.Size );
      }
      v2->vfptr->ClosePath(v2);
      ((void (__fastcall *)(Scaleform::Render::TessBase *, _QWORD, signed __int64))v2->vfptr->FinalizePath)(
        v2,
        0i64,
        1i64);
      v12 = v3->Path.Path.Size;
      if ( v12 )
      {
        do
        {
          v13 = v12 - 1;
          v14 = v12 - 1;
          if ( v12 == 1 )
            v14 = v3->Path.Path.Size;
          v15 = v14 - 1;
          v16 = v12 - 1;
          if ( v12 == 1 )
            v16 = v3->Path.Path.Size;
          v17 = v16 - 1;
          v18 = v3->Path.Path.Size;
          if ( v12 >= v18 )
            v12 -= v18;
          v19 = v3->Path.Path.Pages;
          v20 = &v19[v13 >> 4][v13 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            v3,
            v2,
            &v3->Path.Path.Pages[v12 >> 4][v12 & 0xF],
            v20,
            &v3->Path.Path.Pages[v17 >> 4][v17 & 0xF],
            v20->dist,
            v19[v15 >> 4][v15 & 0xF].dist);
          v12 = v13;
        }
        while ( v13 );
      }
    }
    else
    {
      Scaleform::Render::Stroker::calcCap(
        v3,
        v2,
        *v3->Path.Path.Pages,
        *v3->Path.Path.Pages + 1,
        (*v3->Path.Path.Pages)->dist,
        v3->StartLineCap);
      v21 = 1i64;
      if ( v3->Path.Path.Size > 2 )
      {
        v22 = 2i64;
        do
        {
          v23 = v21;
          if ( !v21 )
            v23 = v3->Path.Path.Size;
          v24 = v3->Path.Path.Size;
          v25 = v22;
          if ( v22 >= v24 )
            v25 = v22 - v24;
          v26 = v21;
          if ( !v21 )
            v26 = v3->Path.Path.Size;
          v27 = &v3->Path.Path.Pages[v21 >> 4][v21 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            v3,
            v2,
            &v3->Path.Path.Pages[(v26 - 1) >> 4][((_DWORD)v26 - 1) & 0xF],
            v27,
            &v3->Path.Path.Pages[v25 >> 4][v25 & 0xF],
            v3->Path.Path.Pages[(v23 - 1) >> 4][((_DWORD)v23 - 1) & 0xF].dist,
            v27->dist);
          v21 = v22++;
        }
        while ( v22 < v3->Path.Path.Size );
      }
      v28 = v3->Path.Path.Size;
      Scaleform::Render::Stroker::calcCap(
        v3,
        v2,
        &v3->Path.Path.Pages[(v28 - 1) >> 4][((_BYTE)v28 - 1) & 0xF],
        &v3->Path.Path.Pages[(v28 - 2) >> 4][((_DWORD)v28 - 2) & 0xF],
        v3->Path.Path.Pages[(v28 - 2) >> 4][((_BYTE)v28 - 2) & 0xF].dist,
        v3->EndLineCap);
      v29 = v3->Path.Path.Size - 2;
      if ( v3->Path.Path.Size != 2 )
      {
        do
        {
          v30 = v29;
          if ( !v29 )
            v30 = v3->Path.Path.Size;
          v31 = v30 - 1;
          v32 = v29;
          if ( !v29 )
            v32 = v3->Path.Path.Size;
          v33 = v32 - 1;
          v34 = v3->Path.Path.Size;
          v35 = v29 + 1;
          if ( v29 + 1 >= v34 )
            v35 -= v34;
          v36 = v3->Path.Path.Pages;
          v37 = &v36[v29 >> 4][v29 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            v3,
            v2,
            &v3->Path.Path.Pages[v35 >> 4][v35 & 0xF],
            v37,
            &v3->Path.Path.Pages[v33 >> 4][v33 & 0xF],
            v37->dist,
            v36[v31 >> 4][v31 & 0xF].dist);
          --v29;
        }
        while ( v29 );
      }
    }
    v2->vfptr->ClosePath(v2);
    ((void (__fastcall *)(Scaleform::Render::TessBase *, _QWORD, signed __int64))v2->vfptr->FinalizePath)(
      v2,
      0i64,
      1i64);
  }
  v3->Closed = 0;
  v3->Path.Path.Size = 0i64;
}

// File Line: 184
// RVA: 0x95BA20
void __fastcall Scaleform::Render::Stroker::CalcEquidistant(Scaleform::Render::Stroker *this, Scaleform::Render::TessBase *tess, Scaleform::Render::StrokerTypes::EquidistantDir dir)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::TessBase *v4; // r14
  Scaleform::Render::Stroker *v5; // rsi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // r8
  Scaleform::Render::StrokeVertex *v12; // r9
  unsigned __int64 v13; // rbp
  signed __int64 v14; // rax
  unsigned __int64 v15; // r11
  signed __int64 v16; // rax
  unsigned __int64 v17; // r10
  unsigned __int64 v18; // rax
  Scaleform::Render::StrokeVertex **v19; // rdx
  Scaleform::Render::StrokeVertex *v20; // r9

  v3 = this->Path.Path.Size;
  v4 = tess;
  v5 = this;
  if ( v3 <= 2 )
  {
    this->Path.Path.Size = 0i64;
  }
  else
  {
    if ( dir )
    {
      if ( v3 )
      {
        do
        {
          v13 = v3 - 1;
          v14 = v3 - 1;
          if ( v3 == 1 )
            v14 = v5->Path.Path.Size;
          v15 = v14 - 1;
          v16 = v3 - 1;
          if ( v3 == 1 )
            v16 = v5->Path.Path.Size;
          v17 = v16 - 1;
          v18 = v5->Path.Path.Size;
          if ( v3 >= v18 )
            v3 -= v18;
          v19 = v5->Path.Path.Pages;
          v20 = &v19[v13 >> 4][v13 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            v5,
            v4,
            &v5->Path.Path.Pages[v3 >> 4][v3 & 0xF],
            v20,
            &v5->Path.Path.Pages[v17 >> 4][v17 & 0xF],
            v20->dist,
            v19[v15 >> 4][v15 & 0xF].dist);
          v3 = v13;
        }
        while ( v13 );
      }
    }
    else
    {
      v6 = 0i64;
      if ( v3 )
      {
        do
        {
          v7 = v6;
          if ( !v6 )
            v7 = v5->Path.Path.Size;
          v8 = v5->Path.Path.Size;
          v9 = v6 + 1;
          v10 = v6 + 1;
          if ( v6 + 1 >= v8 )
            v10 -= v8;
          v11 = v6;
          if ( !v6 )
            v11 = v5->Path.Path.Size;
          v12 = &v5->Path.Path.Pages[v6 >> 4][v6 & 0xF];
          Scaleform::Render::Stroker::calcJoin(
            v5,
            v4,
            &v5->Path.Path.Pages[(v11 - 1) >> 4][((_DWORD)v11 - 1) & 0xF],
            v12,
            &v5->Path.Path.Pages[v10 >> 4][v10 & 0xF],
            v5->Path.Path.Pages[(v7 - 1) >> 4][((_DWORD)v7 - 1) & 0xF].dist,
            v12->dist);
          v6 = v9;
        }
        while ( v9 < v5->Path.Path.Size );
      }
    }
    v4->vfptr->ClosePath(v4);
    ((void (__fastcall *)(Scaleform::Render::TessBase *, _QWORD, signed __int64))v4->vfptr->FinalizePath)(
      v4,
      0i64,
      1i64);
    v5->Path.Path.Size = 0i64;
  }
}

// File Line: 224
// RVA: 0x9D00D0
void __fastcall Scaleform::Render::Stroker::calcArc(Scaleform::Render::Stroker *this, Scaleform::Render::TessBase *tess, float x, float y, float dx1, float dy1, float dx2, float dy2)
{
  Scaleform::Render::TessBase *v8; // rdi
  Scaleform::Render::Stroker *v9; // rbp
  float v10; // xmm8_4
  float v11; // xmm9_4
  float v12; // xmm12_4
  float v13; // xmm9_4
  signed int v14; // ecx
  float v15; // xmm9_4
  float v16; // xmm8_4
  __int64 v17; // rsi
  Scaleform::Render::TessBaseVtbl *v18; // rbx
  float v19; // xmm6_4
  float v20; // xmm0_4

  v8 = tess;
  v9 = this;
  v10 = atan2f(dy1, dx1);
  v11 = atan2f(dy2, dx2);
  v12 = acosf(v9->Width / (float)((float)(v9->CurveTolerance * 0.25) + v9->Width)) * 2.0;
  ((void (__fastcall *)(Scaleform::Render::TessBase *))v8->vfptr->AddVertex)(v8);
  if ( v10 > v11 )
    v11 = v11 + 6.2831855;
  v13 = v11 - v10;
  v14 = (signed int)(float)(v13 / v12);
  v15 = v13 / (float)(v14 + 1);
  v16 = v10 + v15;
  if ( v14 > 0 )
  {
    v17 = (unsigned int)v14;
    do
    {
      v18 = v8->vfptr;
      v19 = (float)(sinf(v16) * v9->Width) + y;
      v20 = (float)(cosf(v16) * v9->Width) + x;
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v18->AddVertex)(v8);
      v16 = v16 + v15;
      --v17;
    }
    while ( v17 );
  }
  ((void (__fastcall *)(Scaleform::Render::TessBase *))v8->vfptr->AddVertex)(v8);
}

// File Line: 258
// RVA: 0x9D3F70
void __fastcall Scaleform::Render::Stroker::calcMiter(Scaleform::Render::Stroker *this, Scaleform::Render::TessBase *tess, Scaleform::Render::StrokeVertex *v0, Scaleform::Render::StrokeVertex *v1, Scaleform::Render::StrokeVertex *v2, float dx1, float dy1, float dx2, float dy2, Scaleform::Render::StrokerTypes::LineJoinType lineJoin, float miterLimit, float epsilon)
{
  float v12; // xmm3_4
  Scaleform::Render::TessBase *v13; // rbx
  Scaleform::Render::StrokeVertex *v14; // rdi
  float v15; // xmm9_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm13_4
  char v20; // cl
  signed __int64 v21; // rdx
  float v22; // xmm14_4
  float v23; // xmm5_4
  float v24; // xmm8_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm12_4
  float v28; // xmm7_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  __m128 v31; // xmm11
  float v32; // xmm1_4
  __m128 v33; // xmm0
  Scaleform::Render::TessBaseVtbl *v34; // rax
  float v35; // xmm0_4
  float v36; // xmm6_4
  float v37; // xmm2_4
  float v38; // xmm2_4
  float v39; // xmm8_4
  float v40; // xmm3_4
  float v41; // xmm6_4
  float v42; // xmm9_4
  float v43; // xmm6_4
  float v44; // xmm12_4
  float v45; // xmm8_4
  float v46; // [rsp+20h] [rbp-B8h]
  float v47; // [rsp+F0h] [rbp+18h]
  float v2a; // [rsp+100h] [rbp+28h]
  float dx1a; // [rsp+108h] [rbp+30h]
  float dy1a; // [rsp+110h] [rbp+38h]

  v12 = v1->y;
  v13 = tess;
  v14 = v1;
  v15 = dy1;
  v16 = dx1;
  v17 = v2->y;
  v18 = v2->x;
  v19 = miterLimit * this->Width;
  v20 = 1;
  v21 = 1i64;
  v22 = v12 + dy1;
  v23 = v1->x + dx1;
  v24 = v12 + dy1;
  v25 = v12 + dy2;
  v26 = v0->y;
  v47 = v25;
  v27 = v23 - (float)(v0->x + dx1);
  v46 = v0->x + dx1;
  dx1a = v26 + dy1;
  v28 = (float)(v2->y + dy2) - v25;
  v29 = (float)(v2->x + dx2) - (float)(v1->x + dx2);
  dy1a = v24 - (float)(v26 + dy1);
  v2a = v29;
  v30 = (float)(v28 * v27) - (float)(v29 * dy1a);
  if ( COERCE_FLOAT(LODWORD(v30) & _xmm) < epsilon )
  {
    if ( (float)((float)((float)(v0->x - v23) * v15) - (float)((float)(v26 - v22) * v16)) < 0.0 != (float)((float)((float)(v18 - v23) * v15) - (float)((float)(v17 - v22) * v16)) < 0.0 )
    {
LABEL_12:
      ((void (__fastcall *)(Scaleform::Render::TessBase *, signed __int64))v13->vfptr->AddVertex)(v13, v21);
      return;
    }
LABEL_5:
    v34 = v13->vfptr;
    if ( lineJoin == 1 )
    {
      v42 = v15 + v14->y;
      v43 = v16 + v14->x;
      ((void (__fastcall *)(Scaleform::Render::TessBase *, signed __int64))v34->AddVertex)(v13, v21);
      v44 = dy2 + v14->y;
      v45 = dx2 + v14->x;
    }
    else if ( (_BYTE)v21 )
    {
      v35 = v16 * miterLimit;
      v36 = (float)(v16 + v14->x) - (float)(v15 * miterLimit);
      v37 = (float)(v15 + v14->y) + v35;
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v34->AddVertex)(v13);
      v38 = (float)(dy2 + v14->y) - (float)(dx2 * miterLimit);
      v39 = (float)(dx2 + v14->x) + (float)(dy2 * miterLimit);
    }
    else
    {
      v40 = v14->x + v16;
      v41 = v14->y + dy2;
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v34->AddVertex)(v13);
    }
    goto LABEL_12;
  }
  v31 = (__m128)LODWORD(dy1a);
  v32 = (float)((float)((float)(dx1a - v47) * v2a) - (float)((float)(v46 - (float)(v1->x + dx2)) * v28)) / v30;
  v31.m128_f32[0] = (float)(dy1a * v32) + dx1a;
  v33 = v31;
  v33.m128_f32[0] = (float)((float)(v31.m128_f32[0] - v1->y) * (float)(v31.m128_f32[0] - v1->y))
                  + (float)((float)((float)((float)(v27 * v32) + v46) - v1->x)
                          * (float)((float)((float)(v27 * v32) + v46) - v1->x));
  if ( COERCE_FLOAT(_mm_sqrt_ps(v33)) <= v19 )
  {
    ((void (__fastcall *)(Scaleform::Render::TessBase *, signed __int64))v13->vfptr->AddVertex)(v13, 1i64);
    v20 = 0;
  }
  LOBYTE(v21) = 0;
  if ( v20 )
    goto LABEL_5;
}

// File Line: 351
// RVA: 0x9D1AC0
void __fastcall Scaleform::Render::Stroker::calcCap(Scaleform::Render::Stroker *this, Scaleform::Render::TessBase *tess, Scaleform::Render::StrokeVertex *v0, Scaleform::Render::StrokeVertex *v1, float len, Scaleform::Render::StrokerTypes::LineCapType cap)
{
  float v6; // xmm12_4
  float v7; // xmm6_4
  Scaleform::Render::StrokeVertex *v8; // rsi
  Scaleform::Render::TessBase *v9; // rdi
  Scaleform::Render::Stroker *v10; // r14
  __int128 v11; // xmm2
  __int128 v12; // xmm1
  float v13; // xmm10_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm9_4
  float v17; // xmm8_4
  float v18; // xmm10_4
  float v19; // xmm13_4
  signed int v20; // ebx
  float v21; // xmm13_4
  float v22; // xmm10_4
  __int64 v23; // rbp
  Scaleform::Render::TessBaseVtbl *v24; // rbx
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm9_4
  float v28; // xmm8_4

  v6 = this->Width;
  v7 = 0.0;
  v8 = v0;
  v9 = tess;
  v10 = this;
  if ( v6 == 0.0 )
  {
    v11 = LODWORD(v0->y);
    v12 = LODWORD(v0->x);
    ((void (__fastcall *)(Scaleform::Render::TessBase *, Scaleform::Render::TessBase *, Scaleform::Render::StrokeVertex *, Scaleform::Render::StrokeVertex *))tess->vfptr->AddVertex)(
      tess,
      tess,
      v0,
      v1);
  }
  else
  {
    v13 = 0.0;
    v14 = (float)((float)(v1->y - v0->y) * (float)(1.0 / len)) * v6;
    v15 = (float)((float)(v0->x - v1->x) * (float)(1.0 / len)) * v6;
    if ( cap == 2 )
    {
      v18 = atan2f(COERCE_FLOAT(LODWORD(v15) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v14) ^ _xmm[0]));
      v19 = (float)(v18 + 3.1415927) - v18;
      v20 = (signed int)(float)(v19 / (float)(acosf(v6 / (float)((float)(v10->CurveTolerance * 0.25) + v6)) * 2.0));
      v21 = v19 / (float)(v20 + 1);
      v22 = v18 + v21;
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v9->vfptr->AddVertex)(v9);
      if ( v20 > 0 )
      {
        v23 = (unsigned int)v20;
        do
        {
          v24 = v9->vfptr;
          v25 = (float)(sinf(v22) * v10->Width) + v8->y;
          v26 = (float)(cosf(v22) * v10->Width) + v8->x;
          ((void (__fastcall *)(Scaleform::Render::TessBase *))v24->AddVertex)(v9);
          v22 = v22 + v21;
          --v23;
        }
        while ( v23 );
      }
      v27 = v15 + v8->y;
      v28 = v14 + v8->x;
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v9->vfptr->AddVertex)(v9);
    }
    else
    {
      if ( cap == 1 )
      {
        v7 = (float)((float)(v0->x - v1->x) * (float)(1.0 / len)) * v6;
        v13 = (float)((float)(v1->y - v0->y) * (float)(1.0 / len)) * v6;
      }
      ((void (__fastcall *)(Scaleform::Render::TessBase *))tess->vfptr->AddVertex)(tess);
      v16 = (float)(v15 + v8->y) - v13;
      v17 = (float)(v14 + v8->x) + v7;
      ((void (__fastcall *)(Scaleform::Render::TessBase *))v9->vfptr->AddVertex)(v9);
    }
  }
}

// File Line: 404
// RVA: 0x9D2380
void __fastcall Scaleform::Render::Stroker::calcJoin(Scaleform::Render::Stroker *this, Scaleform::Render::TessBase *tess, Scaleform::Render::StrokeVertex *v0, Scaleform::Render::StrokeVertex *v1, Scaleform::Render::StrokeVertex *v2, float len1, float len2)
{
  float v7; // xmm8_4
  Scaleform::Render::StrokeVertex *v8; // rdi
  Scaleform::Render::TessBase *v9; // rbx
  __int128 v10; // xmm2
  __int128 v11; // xmm1
  __m128 v12; // xmm4
  float v13; // xmm5_4
  Scaleform::Render::StrokeVertex *v14; // r9
  float v15; // xmm10_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float epsilon; // xmm15_4
  float dy1; // xmm9_4
  float dx2; // xmm7_4
  float dx1; // xmm11_4
  __m128 dy2; // xmm6
  __int64 lineJoin; // rdx
  __m128 v24; // xmm1
  float dbevel; // xmm3_4
  Scaleform::Render::TessBase v26; // rax
  Scaleform::Render::TessBase *v27; // rcx
  float v28; // xmm6_4
  float v29; // xmm7_4

  v7 = this->Width;
  v8 = v1;
  v9 = tess;
  if ( v7 == 0.0 )
  {
    v10 = LODWORD(v1->y);
    v11 = LODWORD(v1->x);
    ((void (__fastcall *)(Scaleform::Render::TessBase *, Scaleform::Render::TessBase *, Scaleform::Render::StrokeVertex *))tess->vfptr->AddVertex)(
      tess,
      tess,
      v0);
    return;
  }
  v12 = (__m128)LODWORD(v1->x);
  v13 = v1->y;
  v14 = v2;
  v15 = len1;
  v16 = v2->y - v13;
  v17 = v13 - v0->y;
  dy2 = v12;
  epsilon = (float)(len1 + len2) * this->IntersectionEpsilon;
  dy1 = (float)((float)(v0->x - v12.m128_f32[0]) * v7) * (float)(1.0 / len1);
  dx2 = (float)(v16 * v7) * (float)(1.0 / len2);
  dx1 = (float)(v17 * v7) * (float)(1.0 / len1);
  dy2.m128_f32[0] = (float)((float)(v12.m128_f32[0] - v2->x) * v7) * (float)(1.0 / len2);
  if ( (float)((float)((float)(v2->x - v12.m128_f32[0]) * v17) - (float)((float)(v12.m128_f32[0] - v0->x) * v16)) <= 0.0 )
  {
    lineJoin = (unsigned int)this->LineJoin;
    v24 = dy2;
    v24.m128_f32[0] = (float)((float)((float)(dy2.m128_f32[0] + dy1) * 0.5)
                            * (float)((float)(dy2.m128_f32[0] + dy1) * 0.5))
                    + (float)((float)((float)(dx2 + dx1) * 0.5) * (float)((float)(dx2 + dx1) * 0.5));
    LODWORD(dbevel) = (unsigned __int128)_mm_sqrt_ps(v24);
    if ( (unsigned int)(lineJoin - 2) > 1 || (float)(v7 - dbevel) >= (float)(this->CurveTolerance * 0.125) )
    {
      if ( (signed int)lineJoin >= 0 )
      {
        if ( (signed int)lineJoin <= 1 )
        {
          Scaleform::Render::Stroker::calcMiter(
            this,
            v9,
            v0,
            v8,
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
          Scaleform::Render::Stroker::calcArc(this, v9, v12.m128_f32[0], v13, dx1, dy1, dx2, dy2.m128_f32[0]);
          return;
        }
      }
      ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64, Scaleform::Render::StrokeVertex *, Scaleform::Render::StrokeVertex *))v9->vfptr->AddVertex)(
        v9,
        lineJoin,
        v0,
        v2);
      v28 = dy2.m128_f32[0] + v8->y;
      v29 = dx2 + v8->x;
      v26.vfptr = v9->vfptr;
      v27 = v9;
    }
    else
    {
      v26.vfptr = v9->vfptr;
      v27 = v9;
    }
    ((void (__fastcall *)(Scaleform::Render::TessBase *, __int64, Scaleform::Render::StrokeVertex *, Scaleform::Render::StrokeVertex *))v26.vfptr->AddVertex)(
      v27,
      lineJoin,
      v0,
      v14);
  }
  else
  {
    if ( len1 >= len2 )
      v15 = len2;
    Scaleform::Render::Stroker::calcMiter(
      this,
      tess,
      v0,
      v8,
      v2,
      dx1,
      dy1,
      dx2,
      dy2.m128_f32[0],
      MiterBevelJoin,
      v15 / v7,
      epsilon,
      0.0);
  }
}

// File Line: 531
// RVA: 0x945120
void __fastcall Scaleform::Render::StrokeSorter::StrokeSorter(Scaleform::Render::StrokeSorter *this, Scaleform::Render::LinearHeap *heap)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::StrokeSorter::`vftable';
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
void __fastcall Scaleform::Render::StrokeSorter::AddVertexNV(Scaleform::Render::StrokeSorter *this, float x, float y, unsigned int segType)
{
  Scaleform::Render::StrokeSorter *v4; // r8
  unsigned __int64 v5; // rcx
  char v6; // r10
  Scaleform::Render::StrokeSorter::VertexType **v7; // r9
  unsigned __int64 v8; // rax
  signed __int64 v9; // rbx
  unsigned __int64 v10; // rdi
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  int v13; // [rsp+2Ch] [rbp-3Ch]

  v4 = this;
  v5 = this->SrcVertices.Size;
  v6 = segType;
  if ( v5 == v4->LastVertex
    && v5
    && (v7 = v4->SrcVertices.Pages, x == v7[(v5 - 1) >> 4][((_BYTE)v5 - 1) & 0xF].x)
    && y == v7[(v5 - 1) >> 4][((_DWORD)v5 - 1) & 0xF].y )
  {
    v4->LastVertex = v4->SrcPaths.Pages[(v4->SrcPaths.Size - 1) >> 4][(LODWORD(v4->SrcPaths.Size) - 1) & 0xF].start;
    v8 = v4->SrcPaths.Size;
    if ( v8 )
      v4->SrcPaths.Size = v8 - 1;
  }
  else
  {
    v9 = (signed __int64)&v4->SrcVertices;
    v10 = v4->SrcVertices.Size >> 4;
    LOBYTE(v13) = v6;
    *(_WORD *)((char *)&v13 + 1) = 0;
    if ( v10 >= v4->SrcVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        &v4->SrcVertices,
        v10);
    v11 = *(_QWORD *)(*(_QWORD *)(v9 + 32) + 8 * v10);
    v12 = 2i64 * (*(_DWORD *)(v9 + 8) & 0xF);
    *(float *)(v11 + 8 * v12) = x;
    *(float *)(v11 + 8 * v12 + 4) = y;
    *(_DWORD *)(v11 + 8 * v12 + 8) = 0;
    *(_DWORD *)(v11 + 8 * v12 + 12) = v13;
    ++*(_QWORD *)(v9 + 8);
  }
}

// File Line: 566
// RVA: 0x954EB0
void __fastcall Scaleform::Render::StrokeSorter::AddVertex(Scaleform::Render::StrokeSorter *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::StrokeSorter::VertexType *v5; // rcx
  signed __int64 v6; // rdx
  int v7; // [rsp+2Ch] [rbp-3Ch]

  v3 = &this->SrcVertices;
  v4 = this->SrcVertices.Size >> 4;
  LOWORD(v7) = 1;
  BYTE2(v7) = 0;
  if ( v4 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(&this->SrcVertices, v4);
  v5 = v3->Pages[v4];
  v6 = v3->Size & 0xF;
  v5[v6].x = x;
  v5[v6].y = y;
  v5[v6].Dist = 0.0;
  *(_DWORD *)&v5[v6].segType = v7;
  ++v3->Size;
}

// File Line: 588
// RVA: 0x9787A0
void __fastcall Scaleform::Render::StrokeSorter::FinalizePath(Scaleform::Render::StrokeSorter *this, unsigned int closeFlag, unsigned int __formal, bool a4, bool __formala)
{
  Scaleform::Render::StrokeSorter *v5; // rbx
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rsi
  Scaleform::Render::StrokeSorter::PathType v8; // [rsp+30h] [rbp+8h]

  v5 = this;
  v6 = this->LastVertex;
  if ( v5->SrcVertices.Size <= (unsigned int)(v6 + 1) )
  {
    if ( v6 < v5->SrcVertices.Size )
      v5->SrcVertices.Size = v6;
  }
  else
  {
    v8.start = v6;
    v8.numVer = LODWORD(v5->SrcVertices.Size) - v6;
    if ( closeFlag )
      v8.numVer = (LODWORD(v5->SrcVertices.Size) - v6) | 0x20000000;
    v7 = v5->SrcPaths.Size >> 4;
    if ( v7 >= v5->SrcPaths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v5->SrcPaths,
        v5->SrcPaths.Size >> 4);
    v5->SrcPaths.Pages[v7][v5->SrcPaths.Size & 0xF] = v8;
    ++v5->SrcPaths.Size;
    v5->LastVertex = v5->SrcVertices.Size;
  }
}

// File Line: 606
// RVA: 0x9CE750
void __fastcall Scaleform::Render::StrokeSorter::appendPath(Scaleform::Render::StrokeSorter *this, Scaleform::Render::StrokeSorter::PathType *dst, Scaleform::Render::StrokeSorter::PathType *src)
{
  Scaleform::Render::StrokeSorter::PathType *v3; // r12
  Scaleform::Render::StrokeSorter::PathType *v4; // r14
  Scaleform::Render::StrokeSorter *v5; // r13
  unsigned int v6; // ebp
  unsigned int v7; // er15
  unsigned __int64 v8; // rsi
  _DWORD *v9; // rbx
  _DWORD *v10; // rdx

  v3 = src;
  v4 = dst;
  v5 = this;
  if ( !dst->numVer )
  {
    dst->start = this->OutVertices.Size;
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
      &this->OutVertices,
      &this->SrcVertices.Pages[(unsigned __int64)src->start >> 4][src->start & 0xF]);
    ++v4->numVer;
  }
  v6 = 1;
  v7 = v3->numVer & 0xFFFFFFF;
  if ( v7 > 1 )
  {
    do
    {
      v8 = v5->OutVertices.Size >> 4;
      v9 = (_DWORD *)&v5->SrcVertices.Pages[(unsigned __int64)(v6 + v3->start) >> 4][((_BYTE)v6 + LOBYTE(v3->start)) & 0xF].x;
      if ( v8 >= v5->OutVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          &v5->OutVertices,
          v5->OutVertices.Size >> 4);
      ++v6;
      v10 = (_DWORD *)&v5->OutVertices.Pages[v8][v5->OutVertices.Size & 0xF].x;
      *v10 = *v9;
      v10[1] = v9[1];
      v10[2] = v9[2];
      v10[3] = v9[3];
      ++v5->OutVertices.Size;
      ++v4->numVer;
    }
    while ( v6 < v7 );
  }
}

// File Line: 627
// RVA: 0x9E2F60
signed __int64 __fastcall Scaleform::Render::StrokeSorter::findNext(Scaleform::Render::StrokeSorter *this, Scaleform::Render::StrokeSorter::PathType *outPath)
{
  Scaleform::Render::StrokeSorter::VertexType **v2; // rax
  Scaleform::Render::StrokeSorter *v3; // r11
  signed __int64 v4; // rcx
  unsigned __int64 v5; // rdx
  float *v6; // r8
  unsigned __int64 v7; // rdx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float *v10; // rax
  float v11; // xmm0_4
  bool v12; // cf
  bool v13; // zf
  unsigned __int64 v14; // r8
  signed __int64 v15; // rcx

  v2 = this->OutVertices.Pages;
  v3 = this;
  v4 = this->SortedPaths.Size;
  v5 = (outPath->numVer & 0xFFFFFFF) + outPath->start - 1;
  v6 = &v2[v5 >> 4][v5 & 0xF].x;
  v7 = 0i64;
  v8 = *v6;
  v9 = v6[1];
  while ( v4 > 0 )
  {
    v10 = &v3->SortedPaths.Array[(v4 >> 1) + v7].x;
    v11 = *v10;
    if ( *v10 == v8 )
    {
      v12 = v9 < v10[1];
      v13 = v9 == v10[1];
    }
    else
    {
      v12 = v8 < v11;
      v13 = v8 == v11;
    }
    if ( v12 || v13 )
    {
      v4 >>= 1;
    }
    else
    {
      v7 += (v4 >> 1) + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  v14 = v3->SortedPaths.Size;
  if ( v7 < v14 )
  {
    v15 = (signed __int64)&v3->SortedPaths.Array[v7];
    while ( v8 == *(float *)v15 && v9 == *(float *)(v15 + 4) )
    {
      if ( !(*(_DWORD *)(*(_QWORD *)(v15 + 8) + 4i64) & 0x40000000) )
        return (unsigned int)v7;
      ++v7;
      v15 += 16i64;
      if ( v7 >= v14 )
        return 0xFFFFFFFFi64;
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 650
// RVA: 0x9B7080
void __fastcall Scaleform::Render::StrokeSorter::Sort(Scaleform::Render::StrokeSorter *this)
{
  unsigned __int64 v1; // r15
  Scaleform::Render::StrokeSorter *v2; // rdi
  unsigned __int64 v3; // r14
  unsigned __int64 v4; // rbp
  Scaleform::Render::StrokeSorter::PathType v5; // rbx
  Scaleform::Render::StrokeSorter::SortedPathType *v6; // rbp
  Scaleform::Render::StrokeSorter::SortedPathType *v7; // rdx
  unsigned __int64 v8; // r8
  unsigned __int64 v9; // r11
  __int64 v10; // rbx
  Scaleform::Render::StrokeSorter::SortedPathType *v11; // r8
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // r10
  unsigned int v14; // edx
  float *v15; // rdx
  unsigned __int64 v16; // rbp
  __int64 v17; // r14
  unsigned int v18; // eax
  Scaleform::Render::StrokeSorter::PathType *v19; // rcx
  unsigned __int64 v20; // rsi
  Scaleform::Render::StrokeSorter::VertexType **v21; // rcx
  unsigned int v22; // ebx
  float *v23; // rdx
  float *v24; // r8
  Scaleform::Render::StrokeSorter::VertexType **v25; // rcx
  float *v26; // rdx
  float *v27; // r8
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // rdx
  Scaleform::Render::LinearHeap *v30; // rcx
  void *v31; // rbx
  unsigned __int64 v32; // rax
  Scaleform::Render::StrokeSorter::PathType dst; // [rsp+50h] [rbp+8h]

  v1 = this->SrcPaths.Size;
  v2 = this;
  v3 = 0i64;
  if ( v1 )
  {
    do
    {
      v4 = v2->SrcPaths.Size >> 4;
      v5 = v2->SrcPaths.Pages[v3 >> 4][v3 & 0xF];
      if ( v4 >= v2->SrcPaths.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v2->SrcPaths,
          v2->SrcPaths.Size >> 4);
      ++v3;
      v2->SrcPaths.Pages[v4][v2->SrcPaths.Size & 0xF] = v5;
      ++v2->SrcPaths.Size;
    }
    while ( v3 < v1 );
  }
  if ( v1 > v2->SortedPaths.Size )
  {
    v6 = (Scaleform::Render::StrokeSorter::SortedPathType *)Scaleform::Render::LinearHeap::Alloc(
                                                              v2->SortedPaths.pHeap,
                                                              16 * v1);
    memset(v6, 0, 16 * v1);
    v7 = v2->SortedPaths.Array;
    if ( v7 )
    {
      v8 = v2->SortedPaths.Size;
      if ( v8 )
        memmove(v6, v7, 16 * v8);
    }
    v2->SortedPaths.Array = v6;
  }
  v2->SortedPaths.Size = v1;
  v9 = 0i64;
  if ( v1 )
  {
    v10 = 0i64;
    do
    {
      v11 = v2->SortedPaths.Array;
      v12 = v9 & 0xF;
      v13 = v9++;
      v13 >>= 4;
      ++v10;
      v14 = v2->SrcPaths.Pages[v13][v12].start;
      v15 = &v2->SrcVertices.Pages[(unsigned __int64)v14 >> 4][v14 & 0xF].x;
      v11[v10 - 1].x = *v15;
      *((float *)&v11[v10] - 3) = v15[1];
      *((_QWORD *)&v11[v10] - 1) = &v2->SrcPaths.Pages[v13][v12];
    }
    while ( v9 < v1 );
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::StrokeSorter::SortedPathType>,bool (*)(Scaleform::Render::StrokeSorter::SortedPathType const &,Scaleform::Render::StrokeSorter::SortedPathType const &)>(
    &v2->SortedPaths,
    0i64,
    v2->SortedPaths.Size,
    Scaleform::Render::StrokeSorter::cmpPaths);
  v16 = 0i64;
  if ( v2->SortedPaths.Size > 0 )
  {
    v17 = 0i64;
    do
    {
      if ( !(v2->SortedPaths.Array[v17].thisPath->numVer & 0x40000000) )
      {
        v18 = v16;
        dst = 0i64;
        do
        {
          v19 = v2->SortedPaths.Array[v18 & 0xFFFFFFF].thisPath;
          v19->numVer |= 0x40000000u;
          Scaleform::Render::StrokeSorter::appendPath(v2, &dst, v2->SortedPaths.Array[v18 & 0xFFFFFFF].thisPath);
          v20 = dst.start;
          v21 = v2->OutVertices.Pages;
          v22 = dst.numVer;
          v23 = &v21[(unsigned __int64)dst.start >> 4][dst.start & 0xF].x;
          v24 = &v21[(unsigned __int64)(dst.start + (dst.numVer & 0xFFFFFFF) - 1) >> 4][(LOBYTE(dst.start)
                                                                                       + LOBYTE(dst.numVer)
                                                                                       - 1) & 0xF].x;
          if ( *v24 == *v23 && v24[1] == v23[1] )
            break;
          v18 = Scaleform::Render::StrokeSorter::findNext(v2, &dst);
        }
        while ( v18 != -1 );
        v25 = v2->OutVertices.Pages;
        v26 = &v25[v20 >> 4][v20 & 0xF].x;
        v27 = &v25[(unsigned __int64)((unsigned int)v20 + (v22 & 0xFFFFFFF) - 1) >> 4][((_BYTE)v20 + (_BYTE)v22 - 1) & 0xF].x;
        if ( *v27 == *v26 && v27[1] == v26[1] )
          dst.numVer = v22 | 0x20000000;
        v28 = v2->OutPaths.Size >> 4;
        if ( v28 >= v2->OutPaths.NumPages )
        {
          v29 = v2->OutPaths.MaxPages;
          if ( v28 >= v29 )
          {
            v30 = v2->OutPaths.pHeap;
            if ( v2->OutPaths.Pages )
            {
              v31 = Scaleform::Render::LinearHeap::Alloc(v30, 16 * v29);
              memmove(v31, v2->OutPaths.Pages, 8 * v2->OutPaths.NumPages);
              v32 = v2->OutPaths.MaxPages;
              v2->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)v31;
              v2->OutPaths.MaxPages = 2 * v32;
            }
            else
            {
              v2->OutPaths.MaxPages = 16i64;
              v2->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                   v30,
                                                                                   0x80ui64);
            }
          }
          v2->OutPaths.Pages[v28] = (Scaleform::Render::StrokeSorter::PathType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                   v2->OutPaths.pHeap,
                                                                                   0x80ui64);
          ++v2->OutPaths.NumPages;
        }
        v2->OutPaths.Pages[v28][v2->OutPaths.Size & 0xF] = dst;
        ++v2->OutPaths.Size;
      }
      ++v16;
      ++v17;
    }
    while ( v16 < v2->SortedPaths.Size );
  }
}

// File Line: 710
// RVA: 0x954670
void __fastcall Scaleform::Render::StrokeSorter::AddOffset(Scaleform::Render::StrokeSorter *this, float offsetX, float offsetY)
{
  unsigned int v3; // edi
  Scaleform::Render::StrokeSorter *v4; // r9
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rcx
  __int64 v7; // rdx
  unsigned int v8; // ebx
  Scaleform::Render::StrokeSorter::PathType *v9; // rcx
  unsigned int v10; // ebp
  int v11; // er11
  unsigned int v12; // er10
  unsigned int v13; // eax
  __int64 v14; // rsi
  unsigned __int64 v15; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v16; // rcx
  signed __int64 v17; // r8
  Scaleform::Render::StrokeSorter::VertexType *v18; // rcx
  unsigned __int64 v19; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v20; // rcx
  signed __int64 v21; // r8
  Scaleform::Render::StrokeSorter::VertexType *v22; // rcx
  unsigned __int64 v23; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v24; // rcx
  signed __int64 v25; // r8
  Scaleform::Render::StrokeSorter::VertexType *v26; // rcx
  unsigned int v27; // eax
  unsigned __int64 v28; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v29; // rcx
  signed __int64 v30; // r8
  Scaleform::Render::StrokeSorter::VertexType *v31; // rcx
  unsigned int v32; // er10
  __int64 v33; // r11
  unsigned __int64 v34; // rdx
  Scaleform::Render::StrokeSorter::VertexType *v35; // rcx
  signed __int64 v36; // r8
  Scaleform::Render::StrokeSorter::VertexType *v37; // rcx

  v3 = 0;
  v4 = this;
  if ( this->OutPaths.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = v5;
      v7 = v5 & 0xF;
      v8 = 0;
      v9 = v4->OutPaths.Pages[v6 >> 4];
      v10 = v9[v7].start;
      v11 = v9[v7].numVer & 0xFFFFFFF;
      if ( v11 >= 4 )
      {
        v12 = v10 + 1;
        v13 = ((unsigned int)(v11 - 4) >> 2) + 1;
        v14 = v13;
        v8 = 4 * v13;
        do
        {
          v15 = (unsigned __int64)(v12 - 1) >> 4;
          v16 = v4->OutVertices.Pages[v15];
          v17 = ((_BYTE)v12 - 1) & 0xF;
          v16[v17].x = offsetX + v16[((_BYTE)v12 - 1) & 0xF].x;
          v18 = v4->OutVertices.Pages[v15];
          v19 = (unsigned __int64)v12 >> 4;
          v18[v17].y = offsetY + v18[((_BYTE)v12 - 1) & 0xF].y;
          v20 = v4->OutVertices.Pages[v19];
          v21 = v12 & 0xF;
          v20[v21].x = offsetX + v20[v12 & 0xF].x;
          v22 = v4->OutVertices.Pages[v19];
          v23 = (unsigned __int64)(v12 + 1) >> 4;
          v22[v21].y = offsetY + v22[v12 & 0xF].y;
          v24 = v4->OutVertices.Pages[v23];
          v25 = ((_BYTE)v12 + 1) & 0xF;
          v24[v25].x = offsetX + v24[((_BYTE)v12 + 1) & 0xF].x;
          v26 = v4->OutVertices.Pages[v23];
          v27 = v12 + 2;
          v12 += 4;
          v28 = (unsigned __int64)v27 >> 4;
          v26[v25].y = offsetY + v26[v25].y;
          v29 = v4->OutVertices.Pages[v28];
          v30 = v27 & 0xF;
          v29[v30].x = offsetX + v29[v30].x;
          v31 = v4->OutVertices.Pages[v28];
          v31[v30].y = offsetY + v31[v27 & 0xF].y;
          --v14;
        }
        while ( v14 );
      }
      if ( v8 < v11 )
      {
        v32 = v8 + v10;
        v33 = v11 - v8;
        do
        {
          v34 = (unsigned __int64)v32 >> 4;
          v35 = v4->OutVertices.Pages[v34];
          v36 = v32++ & 0xF;
          v35[v36].x = offsetX + v35[v36].x;
          v37 = v4->OutVertices.Pages[v34];
          v37[v36].y = offsetY + v37[v36].y;
          --v33;
        }
        while ( v33 );
      }
      v5 = ++v3;
    }
    while ( v3 < v4->OutPaths.Size );
  }
}

// File Line: 728
// RVA: 0x9B6C00
void __fastcall Scaleform::Render::StrokeSorter::Snap(Scaleform::Render::StrokeSorter *this, float offsetX, float offsetY)
{
  unsigned int v3; // er15
  float v4; // xmm5_4
  Scaleform::Render::StrokeSorter *v5; // r14
  float v6; // xmm6_4
  unsigned __int64 v7; // rdx
  Scaleform::Render::StrokeSorter::VertexType **v8; // rdi
  unsigned __int64 v9; // rcx
  __int64 v10; // rdx
  char v11; // r10
  Scaleform::Render::StrokeSorter::PathType *v12; // rcx
  char v13; // r11
  unsigned int v14; // er9
  unsigned int v15; // esi
  unsigned int v16; // edx
  unsigned int v17; // ebp
  float *v18; // rcx
  unsigned int v19; // er8
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
  unsigned int v31; // er8
  __int64 v32; // r10
  Scaleform::Render::StrokeSorter::VertexType *v33; // r9
  signed __int64 v34; // rdx
  __m128 v35; // xmm1
  signed int v36; // ecx
  __int64 v37; // r9
  Scaleform::Render::StrokeSorter::VertexType *v38; // r8
  signed __int64 v39; // rdx
  __m128 v40; // xmm1
  signed int v41; // ecx

  v3 = 0;
  v4 = offsetY;
  v5 = this;
  v6 = offsetX;
  if ( this->OutPaths.Size )
  {
    v7 = 0i64;
    do
    {
      v8 = v5->OutVertices.Pages;
      v9 = v7 >> 4;
      v10 = v7 & 0xF;
      v11 = 0;
      v12 = v5->OutPaths.Pages[v9];
      v13 = 0;
      v14 = 1;
      v15 = v12[v10].start;
      v16 = v12[v10].numVer;
      v17 = v16 & 0xFFFFFFF;
      v18 = &v8[(unsigned __int64)v15 >> 4][v15 & 0xF].x;
      if ( _bittest((const signed int *)&v16, 0x1Du) )
      {
        v14 = 0;
        v18 = &v8[(unsigned __int64)((v16 & 0xFFFFFFF) + v15 - 1) >> 4][((_BYTE)v16 + (_BYTE)v15 - 1) & 0xF].x;
      }
      if ( v14 < v17 )
      {
        if ( (signed int)(v17 - v14) >= 4 )
        {
          v19 = v14 + v15 + 1;
          v20 = ((v17 - v14 - 4) >> 2) + 1;
          v21 = v20;
          v14 += 4 * v20;
          do
          {
            v22 = &v8[(unsigned __int64)(v19 - 1) >> 4][((_BYTE)v19 - 1) & 0xF].x;
            v23 = *v22;
            if ( *v18 == *v22 && v22[1] != v18[1] )
              v11 = 1;
            if ( v22[1] == v18[1] && *v18 != v23 )
              v13 = 1;
            v24 = v23;
            v25 = &v8[(unsigned __int64)v19 >> 4][v19 & 0xF].x;
            v26 = *v25;
            if ( v24 == *v25 && v25[1] != v22[1] )
              v11 = 1;
            if ( v25[1] == v22[1] && v24 != v26 )
              v13 = 1;
            v27 = v26;
            v28 = &v8[(unsigned __int64)(v19 + 1) >> 4][((_BYTE)v19 + 1) & 0xF].x;
            v29 = *v28;
            if ( v27 == *v28 && v28[1] != v25[1] )
              v11 = 1;
            if ( v28[1] == v25[1] && v27 != v29 )
              v13 = 1;
            v18 = &v8[(unsigned __int64)(v19 + 2) >> 4][((_BYTE)v19 + 2) & 0xF].x;
            if ( v29 == *v18 && v18[1] != v28[1] )
              v11 = 1;
            if ( v18[1] == v28[1] && v29 != *v18 )
              v13 = 1;
            v19 += 4;
            --v21;
          }
          while ( v21 );
        }
        for ( ; v14 < v17; v18 = v30 )
        {
          v30 = &v8[(unsigned __int64)(v14 + v15) >> 4][((_BYTE)v14 + (_BYTE)v15) & 0xF].x;
          if ( *v18 == *v30 && v30[1] != v18[1] )
            v11 = 1;
          if ( v30[1] == v18[1] && *v18 != *v30 )
            v13 = 1;
          ++v14;
        }
        if ( v11 && v17 )
        {
          v31 = v15;
          v32 = v17;
          do
          {
            v33 = v5->OutVertices.Pages[(unsigned __int64)v31 >> 4];
            v34 = v31 & 0xF;
            v35 = (__m128)LODWORD(v33[v31 & 0xF].x);
            if ( v35.m128_f32[0] >= 0.0 )
              v35.m128_f32[0] = v35.m128_f32[0] + 0.5;
            else
              v35.m128_f32[0] = v35.m128_f32[0] - 0.5;
            v36 = (signed int)v35.m128_f32[0];
            if ( (signed int)v35.m128_f32[0] != 0x80000000 && (float)v36 != v35.m128_f32[0] )
              v35.m128_f32[0] = (float)(v36 - (_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1));
            ++v31;
            v33[v34].x = v35.m128_f32[0] + v6;
            --v32;
          }
          while ( v32 );
        }
        if ( v13 && v17 )
        {
          v37 = v17;
          do
          {
            v38 = v5->OutVertices.Pages[(unsigned __int64)v15 >> 4];
            v39 = v15 & 0xF;
            v40 = (__m128)LODWORD(v38[v15 & 0xF].y);
            if ( v40.m128_f32[0] >= 0.0 )
              v40.m128_f32[0] = v40.m128_f32[0] + 0.5;
            else
              v40.m128_f32[0] = v40.m128_f32[0] - 0.5;
            v41 = (signed int)v40.m128_f32[0];
            if ( (signed int)v40.m128_f32[0] != 0x80000000 && (float)v41 != v40.m128_f32[0] )
              v40.m128_f32[0] = (float)(v41 - (_mm_movemask_ps(_mm_unpacklo_ps(v40, v40)) & 1));
            ++v15;
            v38[v39].y = v40.m128_f32[0] + v4;
            --v37;
          }
          while ( v37 );
        }
      }
      v7 = ++v3;
    }
    while ( v3 < v5->OutPaths.Size );
  }
}

// File Line: 791
// RVA: 0x97E720
void __fastcall Scaleform::Render::StrokeSorter::GenerateDashes(Scaleform::Render::StrokeSorter *this, Scaleform::Render::DashArray *da, Scaleform::Render::ToleranceParams *param, float scale)
{
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  unsigned int v6; // eax
  Scaleform::Render::DashArray *v7; // r13
  Scaleform::Render::StrokeSorter *v8; // rdi
  unsigned int v9; // er12
  float v10; // xmm2_4
  float v11; // xmm0_4
  unsigned __int64 v12; // r14
  __int64 v13; // rsi
  unsigned int v14; // ebx
  unsigned int v15; // er15
  int v16; // ecx
  Scaleform::Render::StrokeSorter::PathType *v17; // r8
  unsigned int v18; // eax
  Scaleform::Render::StrokeSorter::VertexType **v19; // r10
  float *v20; // rdx
  int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ebx
  char v25; // r9
  unsigned __int64 v26; // rax
  int v27; // ecx
  float *v28; // r9
  unsigned int v29; // eax
  float y3; // xmm9_4
  float x3; // xmm10_4
  float y2; // xmm11_4
  float x2; // xmm12_4
  float *v34; // rcx
  float v35; // xmm7_4
  float x4; // xmm8_4
  int v37; // ecx
  unsigned int v38; // eax
  float *v39; // rcx
  __int128 v40; // xmm2
  __int128 v41; // xmm1
  signed int v42; // er9
  unsigned int v43; // er14
  unsigned int v44; // er11
  signed __int64 v45; // rbx
  unsigned int v46; // er8
  _DWORD *v47; // rdx
  unsigned int v48; // eax
  __int64 v49; // r10
  __int64 v50; // rcx
  int v51; // eax
  __int64 v52; // rcx
  int *v53; // rdx
  __int64 v54; // r8
  int v55; // eax
  __int64 v56; // rcx
  unsigned int v57; // er11
  signed __int64 v58; // rbx
  __int64 v59; // r8
  _DWORD *v60; // rdx
  unsigned int v61; // eax
  __int64 v62; // r10
  __int64 v63; // rcx
  __int64 v64; // rcx
  int v65; // eax
  int *v66; // rdx
  __int64 v67; // r8
  int v68; // eax
  __int64 v69; // rcx
  unsigned int v70; // er15
  unsigned int v71; // er12
  unsigned __int64 v72; // rdx
  unsigned __int64 v73; // rcx
  __int64 v74; // rdx
  Scaleform::Render::StrokeSorter::PathType *v75; // rcx
  unsigned int i; // eax
  unsigned __int64 v77; // rsi
  unsigned __int64 v78; // rsi
  unsigned __int64 v79; // rdx
  Scaleform::Render::LinearHeap *v80; // rcx
  void *v81; // rbx
  unsigned __int64 v82; // rax
  float v83; // xmm6_4
  float v84; // xmm7_4
  unsigned __int64 v85; // rsi
  unsigned __int64 v86; // rdx
  Scaleform::Render::LinearHeap *v87; // rcx
  void *v88; // rbx
  unsigned __int64 v89; // rax
  Scaleform::Render::StrokeSorter::VertexType *v90; // rcx
  signed __int64 v91; // rdx
  unsigned __int64 v92; // rcx
  Scaleform::Render::StrokeSorter::PathType *v93; // rax
  _BOOL8 y1; // [rsp+20h] [rbp-A8h]
  __int128 v95; // [rsp+68h] [rbp-60h]
  int v96; // [rsp+6Ch] [rbp-5Ch]
  __int64 param_8; // [rsp+78h] [rbp-50h]
  unsigned int param_16; // [rsp+80h] [rbp-48h]
  Scaleform::Render::ToleranceParams param_24; // [rsp+88h] [rbp-40h]
  Scaleform::Render::DashGenerator v100; // [rsp+108h] [rbp+40h]
  float x; // [rsp+218h] [rbp+150h]
  Scaleform::Render::StrokeSorter::PathType v102; // [rsp+220h] [rbp+158h]
  float y; // [rsp+230h] [rbp+168h]

  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->SrcPaths.MaxPages = 0i64;
  this->SrcPaths.NumPages = 0i64;
  this->SrcPaths.Size = 0i64;
  this->SrcPaths.Pages = 0i64;
  this->LastVertex = 0;
  v4 = *(_OWORD *)&param->FillLowerScale;
  v5 = *(_OWORD *)&param->StrokeLowerScale;
  v6 = param->CurveRecursionLimit;
  v7 = da;
  v8 = this;
  *(__int128 *)((char *)&v95 + 8) = *(_OWORD *)&param->Epsilon;
  v9 = 0;
  param_16 = v6;
  *(_QWORD *)&v5 = *(_QWORD *)&param->MinDet3D;
  v10 = param->CollinearityTolerance * (float)(1.0 / scale);
  v95 = *(_OWORD *)&param->Scale9LowerScale;
  param_8 = v5;
  v11 = *((float *)&v95 + 3) * (float)(1.0 / scale);
  *((float *)&v95 + 3) = *((float *)&v95 + 3) * (float)(1.0 / scale);
  if ( LODWORD(this->OutPaths.Size) )
  {
    do
    {
      v12 = (unsigned __int64)v9 >> 4;
      v13 = v9 & 0xF;
      v14 = 0;
      v15 = v8->OutPaths.Pages[v12][v13].numVer & 0xFFFFFFF;
      if ( v15 )
      {
        do
        {
          v16 = v14;
          v17 = v8->OutPaths.Pages[v12];
          v18 = v17[v13].numVer & 0xFFFFFFF;
          if ( v14 >= v18 )
            v16 = v14 - v18;
          v19 = v8->OutVertices.Pages;
          ++v14;
          v20 = &v19[(unsigned __int64)(v16 + v17[v13].start) >> 4][((_BYTE)v16 + LOBYTE(v17[v13].start)) & 0xF].x;
          switch ( *((_BYTE *)v20 + 12) )
          {
            case 1:
              v40 = *((unsigned int *)v20 + 1);
              v41 = *(unsigned int *)v20;
              ((void (__fastcall *)(Scaleform::Render::StrokeSorter *))v8->vfptr->AddVertex)(v8);
              break;
            case 2:
              v37 = v14;
              v38 = v17[v13].numVer & 0xFFFFFFF;
              if ( v14 >= v38 )
                v37 = v14 - v38;
              ++v14;
              v39 = &v19[(unsigned __int64)(v37 + v17[v13].start) >> 4][((_BYTE)v37 + LOBYTE(v17[v13].start)) & 0xF].x;
              v11 = v39[1];
              Scaleform::Render::TessellateQuadCurve(
                (Scaleform::Render::TessBase *)&v8->vfptr,
                (Scaleform::Render::ToleranceParams *)((char *)&v95 + 8),
                *v20,
                v20[1],
                *v39,
                v11);
              break;
            case 3:
              v21 = v14;
              v22 = v17[v13].numVer & 0xFFFFFFF;
              if ( v14 >= v22 )
                v21 = v14 - v22;
              v23 = v17[v13].start + v21;
              v24 = v14 + 1;
              v25 = v23;
              v26 = v23;
              v27 = v24;
              v28 = &v19[v26 >> 4][v25 & 0xF].x;
              v29 = v17[v13].numVer & 0xFFFFFFF;
              if ( v24 >= v29 )
                v27 = v24 - v29;
              y3 = v28[1];
              x3 = *v28;
              v14 = v24 + 1;
              y2 = v20[1];
              x2 = *v20;
              v34 = &v19[(unsigned __int64)(v27 + v17[v13].start) >> 4][((_BYTE)v27 + LOBYTE(v17[v13].start)) & 0xF].x;
              v35 = v34[1];
              x4 = *v34;
              v8->vfptr->GetLastX((Scaleform::Render::TessBase *)&v8->vfptr);
              v8->vfptr->GetLastY((Scaleform::Render::TessBase *)&v8->vfptr);
              Scaleform::Render::TessellateCubicRecursively(
                (Scaleform::Render::TessBase *)&v8->vfptr,
                (Scaleform::Render::ToleranceParams *)((char *)&v95 + 8),
                (float)(*((float *)&v95 + 3) * 0.25) * (float)(*((float *)&v95 + 3) * 0.25),
                v11,
                v11,
                x2,
                y2,
                x3,
                y3,
                x4,
                v35,
                0);
              break;
          }
        }
        while ( v14 < v15 );
      }
      LOBYTE(y1) = 0;
      v8->vfptr->FinalizePath(
        (Scaleform::Render::TessBase *)&v8->vfptr,
        (v8->OutPaths.Pages[v12][v13].numVer >> 29) & 1,
        0,
        0,
        y1);
      ++v9;
    }
    while ( v9 < LODWORD(v8->OutPaths.Size) );
  }
  v8->OutVertices.MaxPages = 0i64;
  v8->OutVertices.NumPages = 0i64;
  v8->OutVertices.Size = 0i64;
  v8->OutVertices.Pages = 0i64;
  v8->OutPaths.MaxPages = 0i64;
  v8->OutPaths.NumPages = 0i64;
  v8->OutPaths.Size = 0i64;
  v8->OutPaths.Pages = 0i64;
  v42 = v7->DashCount;
  v43 = 0;
  v44 = 0;
  v45 = 0i64;
  if ( v42 >= 4 )
  {
    v46 = 2;
    v47 = (_DWORD *)&v7->Dashes[1];
    v48 = ((unsigned int)(v42 - 4) >> 2) + 1;
    v49 = v48;
    v44 = 4 * v48;
    v45 = 4i64 * v48;
    do
    {
      v50 = v43;
      v43 += 4;
      *((_DWORD *)&param_24.Epsilon + v50) = *(v47 - 1);
      *((_DWORD *)&param_24.Epsilon + v46 - 1) = *v47;
      *((_DWORD *)&param_24.Epsilon + v46) = v47[1];
      v51 = v47[2];
      v52 = v46 + 1;
      v46 += 4;
      v47 += 4;
      *((_DWORD *)&param_24.Epsilon + v52) = v51;
      --v49;
    }
    while ( v49 );
  }
  if ( v44 < v42 )
  {
    v53 = (int *)&v7->Dashes[v45];
    v54 = v42 - v44;
    do
    {
      v55 = *v53;
      v56 = v43++;
      ++v53;
      *((_DWORD *)&param_24.Epsilon + v56) = v55;
      --v54;
    }
    while ( v54 );
  }
  if ( v43 & 1 )
  {
    v57 = 0;
    v58 = 0i64;
    if ( v42 >= 4 )
    {
      v59 = v43 + 2;
      v60 = (_DWORD *)&v7->Dashes[1];
      v61 = ((unsigned int)(v42 - 4) >> 2) + 1;
      v62 = v61;
      v57 = 4 * v61;
      v58 = 4i64 * v61;
      do
      {
        v63 = v43;
        v43 += 4;
        *((_DWORD *)&param_24.Epsilon + v63) = *(v60 - 1);
        *((_DWORD *)&param_24.Epsilon + (unsigned int)(v59 - 1)) = *v60;
        v64 = (unsigned int)(v59 + 1);
        *((_DWORD *)&param_24.Epsilon + v59) = v60[1];
        v65 = v60[2];
        v60 += 4;
        v59 = (unsigned int)(v59 + 4);
        *((_DWORD *)&param_24.Epsilon + v64) = v65;
        --v62;
      }
      while ( v62 );
    }
    if ( v57 < v42 )
    {
      v66 = (int *)&v7->Dashes[v58];
      v67 = v42 - v57;
      do
      {
        v68 = *v66;
        v69 = v43++;
        ++v66;
        *((_DWORD *)&param_24.Epsilon + v69) = v68;
        --v67;
      }
      while ( v67 );
    }
  }
  v70 = 0;
  v71 = 0;
  if ( v8->SrcPaths.Size )
  {
    v72 = 0i64;
    do
    {
      v73 = v72;
      v74 = v72 & 0xF;
      v75 = v8->SrcPaths.Pages[v73 >> 4];
      Scaleform::Render::DashGenerator::DashGenerator(
        &v100,
        &param_24.Epsilon,
        v43,
        v7->DashStart,
        &v8->SrcVertices.Pages[(unsigned __int64)v75[v74].start >> 4][v75[v74].start & 0xF],
        v75[v74].numVer & 0xFFFFFFF,
        (v75[v74].numVer >> 29) & 1);
      for ( i = Scaleform::Render::DashGenerator::GetVertex(&v100, &x, &y);
            i != 4;
            i = Scaleform::Render::DashGenerator::GetVertex(&v100, &x, &y) )
      {
        if ( !i )
        {
          v77 = v8->OutPaths.Size;
          v102 = (Scaleform::Render::StrokeSorter::PathType)v70;
          v78 = v77 >> 4;
          if ( v78 >= v8->OutPaths.NumPages )
          {
            v79 = v8->OutPaths.MaxPages;
            if ( v78 >= v79 )
            {
              v80 = v8->OutPaths.pHeap;
              if ( v8->OutPaths.Pages )
              {
                v81 = Scaleform::Render::LinearHeap::Alloc(v80, 16 * v79);
                memmove(v81, v8->OutPaths.Pages, 8 * v8->OutPaths.NumPages);
                v82 = v8->OutPaths.MaxPages;
                v8->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)v81;
                v8->OutPaths.MaxPages = 2 * v82;
              }
              else
              {
                v8->OutPaths.MaxPages = 16i64;
                v8->OutPaths.Pages = (Scaleform::Render::StrokeSorter::PathType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                     v80,
                                                                                     0x80ui64);
              }
            }
            v8->OutPaths.Pages[v78] = (Scaleform::Render::StrokeSorter::PathType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                     v8->OutPaths.pHeap,
                                                                                     0x80ui64);
            ++v8->OutPaths.NumPages;
          }
          v8->OutPaths.Pages[v78][v8->OutPaths.Size & 0xF] = v102;
          ++v8->OutPaths.Size;
        }
        v83 = x;
        v84 = y;
        v85 = v8->OutVertices.Size >> 4;
        LOWORD(v96) = 1;
        BYTE2(v96) = 0;
        if ( v85 >= v8->OutVertices.NumPages )
        {
          v86 = v8->OutVertices.MaxPages;
          if ( v85 >= v86 )
          {
            v87 = v8->OutVertices.pHeap;
            if ( v8->OutVertices.Pages )
            {
              v88 = Scaleform::Render::LinearHeap::Alloc(v87, 16 * v86);
              memmove(v88, v8->OutVertices.Pages, 8 * v8->OutVertices.NumPages);
              v89 = v8->OutVertices.MaxPages;
              v8->OutVertices.Pages = (Scaleform::Render::StrokeSorter::VertexType **)v88;
              v8->OutVertices.MaxPages = 2 * v89;
            }
            else
            {
              v8->OutVertices.MaxPages = 16i64;
              v8->OutVertices.Pages = (Scaleform::Render::StrokeSorter::VertexType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                        v87,
                                                                                        0x80ui64);
            }
          }
          v8->OutVertices.Pages[v85] = (Scaleform::Render::StrokeSorter::VertexType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                        v8->OutVertices.pHeap,
                                                                                        0x100ui64);
          ++v8->OutVertices.NumPages;
        }
        v90 = v8->OutVertices.Pages[v85];
        v91 = v8->OutVertices.Size & 0xF;
        ++v70;
        v90[v91].x = v83;
        v90[v91].y = v84;
        v90[v91].Dist = 0.0;
        *(_DWORD *)&v90[v91].segType = v96;
        ++v8->OutVertices.Size;
        v92 = v8->OutPaths.Size - 1;
        v93 = v8->OutPaths.Pages[v92 >> 4];
        ++v93[v92 & 0xF].numVer;
      }
      v72 = ++v71;
    }
    while ( v71 < v8->SrcPaths.Size );
  }
}

// File Line: 901
// RVA: 0x93AE60
void __fastcall Scaleform::Render::DashGenerator::DashGenerator(Scaleform::Render::DashGenerator *this, const float *dashArray, unsigned int dashCount, float dashStart, Scaleform::Render::StrokeSorter::VertexType *ver, unsigned int verCount, bool closed)
{
  unsigned int v7; // er10
  Scaleform::Render::DashGenerator *v8; // r9
  __int64 v9; // rax
  float v10; // xmm0_4
  unsigned int v11; // eax
  unsigned int v12; // ecx
  Scaleform::Render::StrokeSorter::VertexType *v13; // rdx
  int v14; // er11
  signed __int64 v15; // r8
  __m128 v16; // xmm0
  float v17; // xmm1_4
  float v18; // xmm2_4
  signed __int64 v19; // rcx
  signed __int64 v20; // rcx
  bool v21; // zf
  float *v22; // rdx
  __m128 v23; // xmm0
  float v24; // xmm2_4
  __m128 v25; // xmm0

  v7 = 0;
  v8 = this;
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
      v9 = this->CurrDash;
      v10 = dashArray[v9];
      if ( dashStart <= v10 )
        break;
      v11 = v9 + 1;
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
      v13 = v8->Vertices;
      v14 = v12 + 1;
      v15 = v12;
      v16 = (__m128)LODWORD(v13[v12 + 1].y);
      v16.m128_f32[0] = v16.m128_f32[0] - v13[v12].y;
      v17 = v13[v12 + 1].x - v13[v12].x;
      v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v17 * v17);
      LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v16);
      if ( v18 > 1.0e-10 )
      {
        if ( v7 < v12 )
        {
          v19 = v7;
          v13[v19].x = v13[v15].x;
          v13[v19].y = v13[v15].y;
          v13[v19].Dist = v13[v15].Dist;
          *(_DWORD *)&v13[v19].segType = *(_DWORD *)&v13[v15].segType;
        }
        v20 = v7++;
        v8->Vertices[v20].Dist = v18;
      }
      v12 = v14;
    }
    while ( v14 + 1 < v8->VerCount );
  }
  v8->Vertices[v7].Dist = 1.0e10;
  v21 = v8->Closed == 0;
  v8->VerCount = v7 + 1;
  if ( !v21 && v7 + 1 > 2 )
  {
    v22 = &v8->Vertices->x;
    v23 = (__m128)LODWORD(v22[4 * v7 + 1]);
    v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] - v22[1]) * (float)(v23.m128_f32[0] - v22[1]))
                    + (float)((float)(v22[4 * v7] - *v22) * (float)(v22[4 * v7] - *v22));
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
    if ( v24 <= 1.0e-10 )
    {
      v8->VerCount = v7;
      v25 = (__m128)LODWORD(v22[4 * (v7 - 1) + 1]);
      v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] - v22[1]) * (float)(v25.m128_f32[0] - v22[1]))
                      + (float)((float)(v22[4 * (v7 - 1)] - *v22) * (float)(v22[4 * (v7 - 1)] - *v22));
      LODWORD(v22[4 * (v7 - 1) + 2]) = (unsigned __int128)_mm_sqrt_ps(v25);
    }
    else
    {
      v22[4 * v7 + 2] = v24;
    }
  }
}

// File Line: 965
// RVA: 0x98EBC0
signed __int64 __fastcall Scaleform::Render::DashGenerator::GetVertex(Scaleform::Render::DashGenerator *this, float *x, float *y)
{
  Scaleform::Render::DashGenerator::DashStatus v3; // er10
  float *v4; // rbx
  Scaleform::Render::DashGenerator *v5; // r9
  signed __int64 result; // rax
  __int64 v7; // rcx
  float v8; // xmm1_4
  float v9; // xmm2_4
  unsigned int v10; // edx
  float v11; // xmm0_4
  float v12; // xmm2_4
  unsigned int v13; // eax
  float *v14; // rcx
  bool v15; // cf
  float *v16; // rax
  bool v17; // zf
  Scaleform::Render::StrokeSorter::VertexType *v18; // rax
  __int64 v19; // rcx
  unsigned int v20; // eax
  Scaleform::Render::StrokeSorter::VertexType *v21; // rcx

  v3 = this->Status;
  v4 = x;
  v5 = this;
  while ( v3 )
  {
    if ( v3 == 1 )
    {
      v7 = this->CurrDash;
      v8 = v5->CurrDashStart;
      v9 = v5->CurrRest;
      v10 = ~(unsigned __int8)v5->CurrDash & 1;
      v11 = (float)v5->pDashArray[v7] - v8;
      if ( v9 > v11 )
      {
        v12 = v9 - v11;
        v13 = v7 + 1;
        v14 = &v5->Ver1->x;
        v5->CurrRest = v12;
        v15 = v13 < v5->DashCount;
        v5->CurrDashStart = 0.0;
        if ( !v15 )
          v13 = 0;
        v5->CurrDash = v13;
        *v4 = v5->Ver2->x - (float)((float)((float)(v5->Ver2->x - *v14) * v12) / v14[2]);
        result = v10;
        *y = v5->Ver2->y - (float)((float)((float)(v5->Ver2->y - v5->Ver1->y) * v5->CurrRest) / v5->Ver1->Dist);
        return result;
      }
      v16 = &v5->Ver2->x;
      v5->CurrDashStart = v9 + v8;
      *v4 = *v16;
      *y = v5->Ver2->y;
      ++v5->SrcVertex;
      v17 = v5->Closed == 0;
      v18 = v5->Ver2;
      v19 = v5->SrcVertex;
      v5->Ver1 = v18;
      v5->CurrRest = v18->Dist;
      if ( v17 )
      {
        if ( (unsigned int)v19 < v5->VerCount )
        {
          result = v10;
          v5->Ver2 = &v5->Vertices[v19];
          return result;
        }
      }
      else
      {
        v20 = v5->VerCount;
        if ( (unsigned int)v19 <= v20 )
        {
          if ( (unsigned int)v19 >= v20 )
            LODWORD(v19) = 0;
          v5->Ver2 = &v5->Vertices[(unsigned int)v19];
          return v10;
        }
      }
      v5->Status = 2;
      return v10;
    }
    if ( v3 == 2 )
      return 4i64;
  }
  if ( this->DashCount < 2 || this->VerCount < 2 )
    return 4i64;
  v21 = this->Vertices;
  v5->Status = 1;
  v5->Ver1 = v21;
  v5->SrcVertex = 1;
  v5->Ver2 = v21 + 1;
  v5->CurrRest = v21->Dist;
  *x = v21->x;
  result = 0i64;
  *y = v5->Ver1->y;
  return result;
}

