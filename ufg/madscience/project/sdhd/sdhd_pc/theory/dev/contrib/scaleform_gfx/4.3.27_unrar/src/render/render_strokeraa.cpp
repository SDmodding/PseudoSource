// File Line: 50
// RVA: 0x9451D0
void __fastcall Scaleform::Render::StrokerAA::StrokerAA(Scaleform::Render::StrokerAA *this, Scaleform::Render::LinearHeap *heap)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::StrokerAA::`vftable;
  this->LineJoin = 2;
  this->StartLineCap = 2;
  this->EndLineCap = 2;
  this->MiterLimit = 3.0;
  this->StyleLeft = 1;
  *(_QWORD *)&this->StyleRight = 1i64;
  this->WidthRight = 0.0;
  this->AaWidthLeft = 0.5;
  this->AaWidthRight = 0.5;
  this->Tolerance = 1.0;
  this->IntersectionEpsilon = 0.0099999998;
  this->Closed = 0;
  this->Path.Path.pHeap = heap;
  this->Path.Path.Size = 0i64;
  this->Path.Path.NumPages = 0i64;
  this->Path.Path.MaxPages = 0i64;
  this->Path.Path.Pages = 0i64;
  this->Vertices.pHeap = heap;
  this->Vertices.Size = 0i64;
  this->Vertices.NumPages = 0i64;
  this->Vertices.MaxPages = 0i64;
  this->Vertices.Pages = 0i64;
  this->Triangles.pHeap = heap;
  this->Triangles.Size = 0i64;
  this->Triangles.NumPages = 0i64;
  this->Triangles.MaxPages = 0i64;
  this->Triangles.Pages = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
}

// File Line: 54
// RVA: 0x95FA50
void __fastcall Scaleform::Render::StrokerAA::Clear(Scaleform::Render::StrokerAA *this)
{
  this->Path.Path.MaxPages = 0i64;
  this->Path.Path.NumPages = 0i64;
  this->Path.Path.Size = 0i64;
  this->Path.Path.Pages = 0i64;
  this->Vertices.MaxPages = 0i64;
  this->Vertices.NumPages = 0i64;
  this->Vertices.Size = 0i64;
  this->Vertices.Pages = 0i64;
  this->Triangles.MaxPages = 0i64;
  this->Triangles.NumPages = 0i64;
  this->Triangles.Size = 0i64;
  this->Triangles.Pages = 0i64;
  this->Closed = 0;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
}

// File Line: 75
// RVA: 0x961630
void __fastcall Scaleform::Render::StrokerAA::ClosePath(Scaleform::Render::StrokerAA *this)
{
  Scaleform::Render::StrokerAA *v1; // rbx

  v1 = this;
  Scaleform::Render::StrokePath::ClosePath(&this->Path);
  v1->Closed = 1;
}

// File Line: 87
// RVA: 0x9D0D40
void __fastcall Scaleform::Render::StrokerAA::calcButtCap(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v0, Scaleform::Render::StrokeVertex *v1, float len, Scaleform::Render::StrokerAA::WidthsType *w, bool endFlag)
{
  Scaleform::Render::StrokerAA::WidthsType *v6; // rdi
  Scaleform::Render::StrokeVertex *v7; // rsi
  Scaleform::Render::StrokerAA *v8; // rbx
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  bool v14; // cl
  bool v15; // al
  unsigned int v16; // ebp
  unsigned int v17; // er14
  unsigned int v18; // er13
  unsigned int v19; // er15
  float v20; // xmm8_4
  float v21; // xmm12_4
  float v22; // xmm8_4
  float v23; // xmm9_4
  float v24; // xmm12_4
  float v25; // xmm10_4
  float v26; // xmm15_4
  float v27; // xmm9_4
  float v28; // xmm15_4
  float v29; // xmm13_4
  float v30; // xmm11_4
  float v31; // xmm14_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // ecx
  bool v39; // [rsp+118h] [rbp+20h]
  bool wa; // [rsp+120h] [rbp+28h]

  v6 = w;
  v7 = v0;
  v8 = this;
  if ( endFlag )
  {
    v9 = w->solidWidthR;
    v10 = w->solidWidthL;
    v11 = w->totalWidthR;
    v12 = w->totalWidthL;
  }
  else
  {
    v9 = w->solidWidthL;
    v10 = w->solidWidthR;
    v11 = w->totalWidthL;
    v12 = w->totalWidthR;
  }
  v13 = v0->y;
  v14 = w->aaFlagR;
  v15 = w->aaFlagL;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = (float)(v1->y - v13) * (float)(1.0 / len);
  v21 = v20;
  v22 = v20 * v12;
  v23 = (float)(v0->x - v1->x) * (float)(1.0 / len);
  v24 = v21 * v9;
  v25 = (float)((float)(v1->y - v13) * (float)(1.0 / len)) * v10;
  v26 = v23;
  v27 = v23 * v12;
  v28 = v26 * v11;
  v29 = (float)((float)(v0->x - v1->x) * (float)(1.0 / len)) * v9;
  v30 = (float)((float)(v0->x - v1->x) * (float)(1.0 / len)) * v10;
  v31 = (float)((float)(v1->y - v13) * (float)(1.0 / len)) * v11;
  v32 = (float)((float)(v27 - v30) + (float)(v28 - v29)) * 0.5;
  v33 = (float)((float)(v25 - v22) + (float)(v24 - v31)) * 0.5;
  if ( endFlag )
  {
    v39 = w->aaFlagR;
    wa = w->aaFlagL;
  }
  else
  {
    v39 = w->aaFlagL;
    wa = w->aaFlagR;
  }
  if ( v15 || v14 )
  {
    v34 = Scaleform::Render::StrokerAA::addVertex(
            v8,
            (float)(v0->x - v24) + v32,
            (float)(v13 - v29) + v33,
            v8->StyleLeft,
            0);
    v17 = v34;
    if ( v6->solidFlag )
      v34 = Scaleform::Render::StrokerAA::addVertex(
              v8,
              (float)(v25 + v7->x) + v32,
              (float)(v30 + v7->y) + v33,
              v8->StyleRight,
              0);
    v16 = v34;
    if ( v39 )
      v18 = Scaleform::Render::StrokerAA::addVertex(
              v8,
              (float)(v7->x - v31) + v32,
              (float)(v7->y - v28) + v33,
              v8->StyleLeft,
              0);
    else
      v18 = v17;
    if ( wa )
      v19 = Scaleform::Render::StrokerAA::addVertex(
              v8,
              (float)(v22 + v7->x) + v32,
              (float)(v27 + v7->y) + v33,
              v8->StyleRight,
              0);
    else
      v19 = v16;
  }
  if ( endFlag )
  {
    v37 = v8->TotalL;
    v8->TotalL = v8->TotalR;
    v8->TotalR = v37;
    v38 = v8->SolidL;
    v8->SolidL = v8->SolidR;
    v8->SolidR = v38;
  }
  else
  {
    v35 = Scaleform::Render::StrokerAA::addVertex(v8, v7->x - v24, v7->y - v29, v8->StyleLeft, 1u);
    v8->SolidL = v35;
    if ( v6->aaFlagL )
      v35 = Scaleform::Render::StrokerAA::addVertex(v8, v7->x - v31, v7->y - v28, v8->StyleLeft, 0);
    v8->TotalL = v35;
    if ( v6->solidFlag )
      v36 = Scaleform::Render::StrokerAA::addVertex(v8, v25 + v7->x, v30 + v7->y, v8->StyleRight, 1u);
    else
      v36 = v8->SolidL;
    v8->SolidR = v36;
    if ( v6->aaFlagR )
      v36 = Scaleform::Render::StrokerAA::addVertex(v8, v22 + v7->x, v27 + v7->y, v8->StyleRight, 0);
    v8->TotalR = v36;
  }
  if ( (v6->aaFlagL || v6->aaFlagR) && (v6->solidFlagL || v6->solidFlagR) )
  {
    Scaleform::Render::StrokerAA::addTriangle(v8, v17, v16, v8->SolidL);
    Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v16, v8->SolidR);
  }
  if ( v39 )
  {
    Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v8->TotalL, v18);
    Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v18, v17);
  }
  if ( wa )
  {
    Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v19, v8->TotalR);
    Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v16, v19);
  }
}

// File Line: 163
// RVA: 0x9D4800
void __fastcall Scaleform::Render::StrokerAA::calcRoundCap(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v0, Scaleform::Render::StrokeVertex *v1, float len, Scaleform::Render::StrokerAA::WidthsType *w, bool endFlag)
{
  bool v6; // r14
  Scaleform::Render::StrokerAA::WidthsType *v7; // rdi
  Scaleform::Render::StrokeVertex *v8; // rsi
  Scaleform::Render::StrokerAA *v9; // rbx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm14_4
  float v17; // xmm13_4
  float v18; // xmm0_4
  float v19; // xmm11_4
  float v20; // xmm9_4
  float v21; // xmm14_4
  float v22; // xmm10_4
  float v23; // xmm8_4
  float v24; // xmm15_4
  float v25; // xmm13_4
  float v26; // xmm12_4
  int v27; // ebp
  float v28; // xmm12_4
  unsigned int v29; // eax
  float v30; // xmm14_4
  float v31; // xmm9_4
  float v32; // xmm13_4
  float v33; // xmm15_4
  float v34; // xmm6_4
  float v35; // xmm0_4
  float v36; // xmm8_4
  float v37; // xmm7_4
  float v38; // xmm8_4
  unsigned int v39; // er9
  unsigned int v40; // ebp
  unsigned int v41; // er15
  unsigned int v42; // er9
  unsigned int v43; // er12
  unsigned int v44; // er13
  unsigned __int64 v45; // r14
  signed __int64 v46; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v47; // rax
  unsigned int v48; // er12
  unsigned int v49; // er13
  unsigned __int64 v50; // r14
  signed __int64 v51; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v52; // rax
  unsigned int v53; // er12
  unsigned __int64 v54; // r14
  signed __int64 v55; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v56; // rax
  unsigned int v57; // er12
  unsigned int v58; // er13
  unsigned __int64 v59; // r14
  signed __int64 v60; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v61; // rax
  unsigned int v62; // er12
  unsigned int v63; // er13
  unsigned __int64 v64; // r14
  signed __int64 v65; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v66; // rax
  unsigned int v67; // er12
  unsigned __int64 v68; // r14
  signed __int64 v69; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v70; // rax
  bool v71; // zf
  float v72; // [rsp+118h] [rbp+20h]
  float v73; // [rsp+118h] [rbp+20h]
  float wa; // [rsp+120h] [rbp+28h]
  Scaleform::Render::StrokerAA::WidthsType *wb; // [rsp+120h] [rbp+28h]

  v6 = endFlag;
  v7 = w;
  v8 = v0;
  v9 = this;
  if ( endFlag )
  {
    v10 = w->solidWidthR;
    v11 = w->solidWidthL;
    v12 = w->totalWidthR;
    v13 = w->totalWidthL;
  }
  else
  {
    v10 = w->solidWidthL;
    v11 = w->solidWidthR;
    v12 = w->totalWidthL;
    v13 = w->totalWidthR;
  }
  v14 = v0->x;
  v15 = v0->y;
  v16 = (float)(v0->x - v1->x) * (float)(1.0 / len);
  v17 = (float)(v1->y - v15) * (float)(1.0 / len);
  v18 = v16;
  v19 = v16 * v10;
  v20 = v16 * v12;
  v21 = v16 * v13;
  v22 = v17 * v10;
  v23 = v17 * v12;
  wa = v18 * v11;
  v24 = v17 * v11;
  v25 = v17 * v13;
  v26 = atan2f(COERCE_FLOAT(LODWORD(v20) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v23) ^ _xmm[0]));
  v72 = (float)(v26 + 3.1415927) - v26;
  v27 = (signed int)(float)(v72
                          / (float)(acosf(v7->totalWidth / (float)((float)(v9->Tolerance * 0.25) + v7->totalWidth)) * 2.0))
      + 1;
  v73 = v72 / (float)v27;
  v28 = v26 + v73;
  if ( endFlag )
  {
    v9->SolidL = v9->SolidR;
    v29 = v9->TotalR;
  }
  else
  {
    v29 = Scaleform::Render::StrokerAA::addVertex(v9, v14 - v22, v15 - v19, v9->StyleLeft, 1u);
    v9->SolidR = v29;
    v9->SolidL = v29;
    if ( v7->aaFlagL || v7->aaFlagR )
      v29 = Scaleform::Render::StrokerAA::addVertex(v9, v8->x - v23, v8->y - v20, v9->StyleLeft, 0);
    v9->TotalR = v29;
  }
  v9->TotalL = v29;
  v30 = (float)((float)(v21 - v20) * 0.5) + v8->y;
  v31 = (float)((float)(wa - v19) * 0.5) + v8->y;
  v32 = (float)((float)(v25 - v23) * 0.5) + v8->x;
  v33 = (float)((float)(v24 - v22) * 0.5) + v8->x;
  if ( v27 > 0 )
  {
    wb = (Scaleform::Render::StrokerAA::WidthsType *)(unsigned int)v27;
    do
    {
      v34 = cosf(v28);
      v35 = sinf(v28);
      v36 = v7->totalWidth;
      v37 = (float)(v36 * v35) + v30;
      v38 = (float)(v36 * v34) + v32;
      if ( v7->solidFlag )
      {
        if ( v6 )
          v39 = v9->StyleLeft;
        else
          v39 = v9->StyleRight;
        v40 = Scaleform::Render::StrokerAA::addVertex(
                v9,
                (float)(v7->solidWidth * v34) + v33,
                (float)(v7->solidWidth * v35) + v31,
                v39,
                1u);
      }
      else
      {
        v40 = v9->SolidL;
      }
      if ( v7->aaFlagL || v7->aaFlagR )
      {
        if ( v6 )
          v42 = v9->StyleLeft;
        else
          v42 = v9->StyleRight;
        v41 = Scaleform::Render::StrokerAA::addVertex(v9, v38, v37, v42, 0);
      }
      else
      {
        v41 = v40;
      }
      if ( v6 )
      {
        if ( v7->solidFlagL || v7->solidFlagR )
        {
          v43 = v9->SolidL;
          v44 = v9->SolidR;
          v45 = v9->Triangles.Size >> 4;
          if ( v45 >= v9->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v9->Triangles,
              v9->Triangles.Size >> 4);
          v46 = v9->Triangles.Size & 0xF;
          v47 = v9->Triangles.Pages[v45];
          v47[v46].v1 = v43;
          v47[v46].v2 = v40;
          v47[v46].v3 = v44;
          ++v9->Triangles.Size;
        }
        if ( v7->aaFlagL || v7->aaFlagR )
        {
          v48 = v9->SolidL;
          v49 = v9->TotalL;
          v50 = v9->Triangles.Size >> 4;
          if ( v50 >= v9->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v9->Triangles,
              v9->Triangles.Size >> 4);
          v51 = v9->Triangles.Size & 0xF;
          v52 = v9->Triangles.Pages[v50];
          v52[v51].v1 = v48;
          v52[v51].v2 = v49;
          v52[v51].v3 = v41;
          ++v9->Triangles.Size;
          v53 = v9->SolidL;
          v54 = v9->Triangles.Size >> 4;
          if ( v54 >= v9->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v9->Triangles,
              v9->Triangles.Size >> 4);
          v55 = v9->Triangles.Size & 0xF;
          v56 = v9->Triangles.Pages[v54];
          v56[v55].v1 = v53;
          v56[v55].v2 = v41;
          v56[v55].v3 = v40;
          ++v9->Triangles.Size;
        }
        v9->SolidL = v40;
        v9->TotalL = v41;
      }
      else
      {
        if ( v7->solidFlagL || v7->solidFlagR )
        {
          v57 = v9->SolidL;
          v58 = v9->SolidR;
          v59 = v9->Triangles.Size >> 4;
          if ( v59 >= v9->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v9->Triangles,
              v9->Triangles.Size >> 4);
          v60 = v9->Triangles.Size & 0xF;
          v61 = v9->Triangles.Pages[v59];
          v61[v60].v1 = v57;
          v61[v60].v2 = v58;
          v61[v60].v3 = v40;
          ++v9->Triangles.Size;
        }
        if ( v7->aaFlagL || v7->aaFlagR )
        {
          v62 = v9->SolidR;
          v63 = v9->TotalR;
          v64 = v9->Triangles.Size >> 4;
          if ( v64 >= v9->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v9->Triangles,
              v9->Triangles.Size >> 4);
          v65 = v9->Triangles.Size & 0xF;
          v66 = v9->Triangles.Pages[v64];
          v66[v65].v1 = v62;
          v66[v65].v2 = v63;
          v66[v65].v3 = v41;
          ++v9->Triangles.Size;
          v67 = v9->SolidR;
          v68 = v9->Triangles.Size >> 4;
          if ( v68 >= v9->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v9->Triangles,
              v9->Triangles.Size >> 4);
          v69 = v9->Triangles.Size & 0xF;
          v70 = v9->Triangles.Pages[v68];
          v70[v69].v1 = v67;
          v70[v69].v2 = v41;
          v70[v69].v3 = v40;
          ++v9->Triangles.Size;
        }
        v9->SolidR = v40;
        v9->TotalR = v41;
      }
      v71 = wb == (Scaleform::Render::StrokerAA::WidthsType *)1;
      wb = (Scaleform::Render::StrokerAA::WidthsType *)((char *)wb - 1);
      v6 = endFlag;
      v28 = v28 + v73;
    }
    while ( !v71 );
  }
}

// File Line: 282
// RVA: 0x9D4E00
void __fastcall Scaleform::Render::StrokerAA::calcRoundJoin(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v1, Scaleform::Render::StrokerAA::WidthsType *w, Scaleform::Render::StrokerAA::JoinParamType *p)
{
  bool v4; // r12
  float v5; // xmm0_4
  Scaleform::Render::StrokerAA::JoinParamType *v6; // rsi
  Scaleform::Render::StrokerAA::WidthsType *v7; // rdi
  Scaleform::Render::StrokeVertex *v8; // r14
  Scaleform::Render::StrokerAA *v9; // rbx
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  unsigned int v15; // eax
  unsigned int v16; // ebp
  unsigned int v17; // er15
  unsigned int v18; // er13
  float v19; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm9_4
  int v22; // eax
  float v23; // xmm9_4
  float v24; // xmm7_4
  __int64 v25; // r15
  float v26; // xmm6_4
  float v27; // xmm0_4
  unsigned int v28; // esi
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm8_4
  float v33; // xmm9_4
  unsigned int v34; // eax
  unsigned int v35; // ebp
  unsigned int v36; // er15
  unsigned int v37; // er13
  float v38; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm9_4
  float v41; // xmm9_4
  int v42; // eax
  float v43; // xmm9_4
  float v44; // xmm6_4
  __int64 v45; // r15
  float v46; // xmm7_4
  float v47; // xmm0_4
  unsigned int v48; // esi
  unsigned int v3; // [rsp+B8h] [rbp+20h]
  unsigned int v3a; // [rsp+B8h] [rbp+20h]

  v4 = p->overlapPrev || p->overlapThis;
  v5 = this->Tolerance * 0.125;
  v6 = p;
  v7 = w;
  v8 = v1;
  v9 = this;
  if ( p->rightTurnThis )
  {
    if ( (float)((float)(w->solidWidthR * 2.0) - p->dbTotalR) < v5 )
    {
LABEL_3:
      Scaleform::Render::StrokerAA::calcMiterJoin(this, v1, w, p, 0);
      return;
    }
    if ( *(_WORD *)&p->overlapPrev )
    {
      v10 = p->dx1TotalR + v1->x;
      v11 = p->dy1TotalR + v1->y;
    }
    else
    {
      v10 = p->xMiterThisR;
      v11 = p->yMiterThisR;
    }
    v12 = v1->y;
    v13 = (float)((float)(v10 - v1->x) * w->solidCoeffR) + v1->x;
    v14 = (float)((float)(v11 - v12) * w->solidCoeffR) + v12;
    v15 = Scaleform::Render::StrokerAA::addVertex(this, v1->x - p->dx1SolidL, v12 - p->dy1SolidL, this->StyleLeft, 1u);
    v16 = v15;
    if ( v7->aaFlagL )
      v15 = Scaleform::Render::StrokerAA::addVertex(v9, v8->x - v6->dx1TotalL, v8->y - v6->dy1TotalL, v9->StyleLeft, 0);
    v3 = v15;
    if ( v7->solidFlag )
      v17 = Scaleform::Render::StrokerAA::addVertex(v9, v13, v14, v9->StyleRight, 1u);
    else
      v17 = v16;
    if ( v7->aaFlagR )
      v18 = Scaleform::Render::StrokerAA::addVertex(v9, v10, v11, v9->StyleRight, 0);
    else
      v18 = v17;
    if ( v7->solidFlagL || v7->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v17, v16);
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v9->SolidR, v17);
    }
    if ( v7->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalL, v9->SolidL, v16);
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalL, v16, v3);
    }
    if ( v7->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v18, v17);
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v9->TotalR, v18);
    }
    v9->SolidL = v16;
    v9->SolidR = v17;
    v9->TotalR = v18;
    v9->TotalL = v3;
    if ( v4 )
    {
      v9->SolidR = Scaleform::Render::StrokerAA::addVertex(
                     v9,
                     v6->dx2SolidR + v8->x,
                     v6->dy2SolidR + v8->y,
                     v9->StyleRight,
                     1u);
      if ( v7->aaFlagR )
        v17 = Scaleform::Render::StrokerAA::addVertex(
                v9,
                v6->dx2TotalR + v8->x,
                v6->dy2TotalR + v8->y,
                v9->StyleRight,
                0);
      v9->TotalR = v17;
    }
    v19 = atan2f(COERCE_FLOAT(LODWORD(v6->dy1TotalL) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v6->dx1TotalL) ^ _xmm[0]));
    v20 = atan2f(COERCE_FLOAT(LODWORD(v6->dy2TotalL) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v6->dx2TotalL) ^ _xmm[0]));
    if ( v19 < v20 )
      v20 = v20 + -6.2831855;
    v21 = v19 - v20;
    v22 = (signed int)(float)((float)(v19 - v20)
                            / (float)(acosf(v7->totalWidthL / (float)((float)(v9->Tolerance * 0.25) + v7->totalWidthL))
                                    * 2.0))
        + 1;
    v23 = v21 / (float)v22;
    v24 = v19 - v23;
    if ( v22 > 0 )
    {
      v25 = (unsigned int)v22;
      do
      {
        v26 = cosf(v24);
        v27 = sinf(v24);
        if ( v7->solidFlag )
          v16 = Scaleform::Render::StrokerAA::addVertex(
                  v9,
                  (float)(v26 * v7->solidWidthL) + v8->x,
                  (float)(v27 * v7->solidWidthL) + v8->y,
                  v9->StyleLeft,
                  1u);
        if ( v7->aaFlagL )
          v28 = Scaleform::Render::StrokerAA::addVertex(
                  v9,
                  (float)(v7->totalWidthL * v26) + v8->x,
                  (float)(v7->totalWidthL * v27) + v8->y,
                  v9->StyleLeft,
                  0);
        else
          v28 = v16;
        if ( v7->solidFlagL )
          Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v16, v9->SolidL);
        if ( v7->aaFlagL )
        {
          Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v16, v9->TotalL);
          Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalL, v16, v28);
        }
        v9->SolidL = v16;
        v9->TotalL = v28;
        v24 = v24 - v23;
        --v25;
      }
      while ( v25 );
    }
  }
  else
  {
    if ( (float)((float)(w->solidWidthL * 2.0) - p->dbTotalL) < v5 )
      goto LABEL_3;
    if ( *(_WORD *)&p->overlapPrev )
    {
      v29 = v1->x - p->dx1TotalL;
      v30 = v1->y - p->dy1TotalL;
    }
    else
    {
      v29 = p->xMiterThisL;
      v30 = p->yMiterThisL;
    }
    v31 = v1->y;
    v32 = (float)((float)(v29 - v1->x) * w->solidCoeffL) + v1->x;
    v33 = (float)((float)(v30 - v31) * w->solidCoeffL) + v31;
    v34 = Scaleform::Render::StrokerAA::addVertex(this, v1->x + p->dx1SolidR, v31 + p->dy1SolidR, this->StyleRight, 1u);
    v35 = v34;
    if ( v7->aaFlagR )
      v34 = Scaleform::Render::StrokerAA::addVertex(v9, v6->dx1TotalR + v8->x, v6->dy1TotalR + v8->y, v9->StyleRight, 0);
    v3a = v34;
    if ( v7->solidFlag )
      v36 = Scaleform::Render::StrokerAA::addVertex(v9, v32, v33, v9->StyleLeft, 1u);
    else
      v36 = v35;
    if ( v7->aaFlagL )
      v37 = Scaleform::Render::StrokerAA::addVertex(v9, v29, v30, v9->StyleLeft, 0);
    else
      v37 = v36;
    if ( v7->solidFlagL || v7->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v35, v36);
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v36, v9->SolidL);
    }
    if ( v7->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalR, v35, v9->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalR, v3a, v35);
    }
    if ( v7->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v36, v37);
      Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v37, v9->TotalL);
    }
    v9->SolidL = v36;
    v9->TotalL = v37;
    v9->SolidR = v35;
    v9->TotalR = v3a;
    if ( v4 )
    {
      v9->SolidL = Scaleform::Render::StrokerAA::addVertex(
                     v9,
                     v8->x - v6->dx2SolidL,
                     v8->y - v6->dy2SolidL,
                     v9->StyleLeft,
                     1u);
      if ( v7->aaFlagL )
        v36 = Scaleform::Render::StrokerAA::addVertex(
                v9,
                v8->x - v6->dx2TotalL,
                v8->y - v6->dy2TotalL,
                v9->StyleLeft,
                0);
      v9->TotalL = v36;
    }
    v38 = atan2f(v6->dy1TotalR, v6->dx1TotalR);
    v39 = atan2f(v6->dy2TotalR, v6->dx2TotalR);
    v40 = v39;
    if ( v38 > v39 )
      v40 = v39 + 6.2831855;
    v41 = v40 - v38;
    v42 = (signed int)(float)(v41
                            / (float)(acosf(v7->totalWidthR / (float)((float)(v9->Tolerance * 0.25) + v7->totalWidthR))
                                    * 2.0))
        + 1;
    v43 = v41 / (float)v42;
    v44 = v38 + v43;
    if ( v42 > 0 )
    {
      v45 = (unsigned int)v42;
      do
      {
        v46 = cosf(v44);
        v47 = sinf(v44);
        if ( v7->solidFlag )
          v35 = Scaleform::Render::StrokerAA::addVertex(
                  v9,
                  (float)(v7->solidWidthR * v46) + v8->x,
                  (float)(v7->solidWidthR * v47) + v8->y,
                  v9->StyleRight,
                  1u);
        if ( v7->aaFlagR )
          v48 = Scaleform::Render::StrokerAA::addVertex(
                  v9,
                  (float)(v7->totalWidthR * v46) + v8->x,
                  (float)(v7->totalWidthR * v47) + v8->y,
                  v9->StyleRight,
                  0);
        else
          v48 = v35;
        if ( v7->solidFlagR )
          Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v9->SolidR, v35);
        if ( v7->aaFlagR )
        {
          Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v9->TotalR, v35);
          Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalR, v48, v35);
        }
        v9->SolidR = v35;
        v9->TotalR = v48;
        v44 = v44 + v43;
        --v45;
      }
      while ( v45 );
    }
  }
}

// File Line: 501
// RVA: 0x9D0290
void __fastcall Scaleform::Render::StrokerAA::calcBevelJoin(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v1, Scaleform::Render::StrokerAA::WidthsType *w, Scaleform::Render::StrokerAA::JoinParamType *p, Scaleform::Render::StrokerTypes::LineJoinType lineJoin)
{
  Scaleform::Render::StrokerAA::JoinParamType *v5; // rdi
  Scaleform::Render::StrokerAA::WidthsType *v6; // rsi
  Scaleform::Render::StrokeVertex *v7; // rbp
  Scaleform::Render::StrokerAA *v8; // rbx
  float v9; // xmm7_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm9_4
  float v15; // xmm10_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  unsigned int v23; // er14
  unsigned int v24; // eax
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  unsigned int v28; // er15
  unsigned int v29; // er13
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  unsigned int v34; // edi
  float v35; // xmm11_4
  float v36; // xmm12_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm9_4
  float v40; // xmm10_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm7_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm6_4
  unsigned int v48; // er14
  unsigned int v49; // eax
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  unsigned int v53; // er15
  unsigned int v54; // er13
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  unsigned int v59; // edi
  unsigned int v3; // [rsp+30h] [rbp-B8h]
  unsigned int v3a; // [rsp+30h] [rbp-B8h]
  bool v62; // [rsp+108h] [rbp+20h]

  v5 = p;
  v6 = w;
  v7 = v1;
  v8 = this;
  v62 = p->overlapPrev || p->overlapThis;
  v9 = 0.0;
  if ( p->rightTurnThis )
  {
    if ( *(_WORD *)&p->overlapPrev )
    {
      v10 = p->dx1TotalR + v1->x;
      v11 = p->dy1TotalR + v1->y;
    }
    else
    {
      v10 = p->xMiterThisR;
      v11 = p->yMiterThisR;
    }
    v12 = v1->x;
    v13 = v1->y;
    v14 = (float)((float)(v10 - v12) * w->solidCoeffR) + v12;
    v15 = (float)((float)(v11 - v13) * w->solidCoeffR) + v13;
    if ( lineJoin )
    {
      v24 = Scaleform::Render::StrokerAA::addVertex(this, v12 - p->dx1SolidL, v13 - p->dy1SolidL, this->StyleLeft, 1u);
      v25 = v5->dbTotalL;
      v23 = v24;
      v26 = v5->dMiterThisL - v25;
      if ( v26 == 0.0 )
        v26 = *(float *)&FLOAT_1_0;
      v22 = (float)((float)((float)(v5->dbSolidL + v6->totalWidthL) - v6->solidWidthL) - v25) / v26;
    }
    else
    {
      v16 = p->dbSolidL;
      v17 = p->dSolidMiterL - v16;
      if ( v17 == 0.0 )
        v17 = *(float *)&FLOAT_1_0;
      v18 = (float)((float)(w->totalLimitL - v16) - w->totalWidthL) + w->solidWidthL;
      if ( v18 > v17 )
        v18 = v17;
      v19 = (float)(w->solidLimitL - v16) + v18;
      v20 = p->dbTotalL;
      v9 = v19 / (float)(v17 * 2.0);
      v21 = p->dMiterThisL - v20;
      if ( v21 == 0.0 )
        v21 = *(float *)&FLOAT_1_0;
      v22 = (float)((float)((float)((float)(w->solidLimitL - v20) + w->totalWidthL) - w->solidWidthL)
                  + (float)(w->totalLimitL - v20))
          / (float)(v21 * 2.0);
      v23 = Scaleform::Render::StrokerAA::addVertex(
              this,
              (float)((float)(p->xSolidMiterL - (float)(v12 - p->dx1SolidL)) * v9) + (float)(v12 - p->dx1SolidL),
              (float)((float)(p->ySolidMiterL - (float)(v13 - p->dy1SolidL)) * v9) + (float)(v13 - p->dy1SolidL),
              this->StyleLeft,
              1u);
    }
    if ( v6->aaFlagL )
    {
      v27 = v7->y - v5->dy1TotalL;
      v3 = Scaleform::Render::StrokerAA::addVertex(
             v8,
             (float)((float)(v5->xMiterThisL - (float)(v7->x - v5->dx1TotalL)) * v22) + (float)(v7->x - v5->dx1TotalL),
             (float)((float)(v5->yMiterThisL - v27) * v22) + v27,
             v8->StyleLeft,
             0);
    }
    else
    {
      v3 = v23;
    }
    if ( v6->solidFlag )
      v28 = Scaleform::Render::StrokerAA::addVertex(v8, v14, v15, v8->StyleRight, 1u);
    else
      v28 = v23;
    if ( v6->aaFlagR )
      v29 = Scaleform::Render::StrokerAA::addVertex(v8, v10, v11, v8->StyleRight, 0);
    else
      v29 = v28;
    if ( v6->solidFlagL || v6->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v28, v23);
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v8->SolidR, v28);
    }
    if ( v6->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->TotalL, v8->SolidL, v23);
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->TotalL, v23, v3);
    }
    if ( v6->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v29, v28);
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v8->TotalR, v29);
    }
    v8->SolidL = v23;
    v8->SolidR = v28;
    v8->TotalR = v29;
    v8->TotalL = v3;
    if ( v62 )
    {
      v8->SolidR = Scaleform::Render::StrokerAA::addVertex(
                     v8,
                     v5->dx2SolidR + v7->x,
                     v5->dy2SolidR + v7->y,
                     v8->StyleRight,
                     1u);
      if ( v6->aaFlagR )
        v28 = Scaleform::Render::StrokerAA::addVertex(
                v8,
                v5->dx2TotalR + v7->x,
                v5->dy2TotalR + v7->y,
                v8->StyleRight,
                0);
      v8->TotalR = v28;
    }
    if ( (float)(v6->totalWidthL - v5->dbTotalL) > (float)((float)(v8->Tolerance * 0.25) * 0.25) )
    {
      if ( v6->solidFlag )
      {
        if ( lineJoin )
        {
          v31 = v7->y - v5->dy2SolidL;
          v32 = v7->x - v5->dx2SolidL;
        }
        else
        {
          v30 = v7->y - v5->dy2SolidL;
          v31 = (float)((float)(v5->ySolidMiterL - v30) * v9) + v30;
          v32 = (float)((float)(v5->xSolidMiterL - (float)(v7->x - v5->dx2SolidL)) * v9)
              + (float)(v7->x - v5->dx2SolidL);
        }
        v23 = Scaleform::Render::StrokerAA::addVertex(v8, v32, v31, v8->StyleLeft, 1u);
      }
      if ( v6->aaFlagL )
      {
        v33 = v7->y - v5->dy2TotalL;
        v34 = Scaleform::Render::StrokerAA::addVertex(
                v8,
                (float)((float)(v5->xMiterThisL - (float)(v7->x - v5->dx2TotalL)) * v22)
              + (float)(v7->x - v5->dx2TotalL),
                (float)((float)(v5->yMiterThisL - v33) * v22) + v33,
                v8->StyleLeft,
                0);
      }
      else
      {
        v34 = v23;
      }
      if ( v6->solidFlagL )
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v23, v8->SolidL);
      if ( v6->aaFlagL )
      {
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v23, v8->TotalL);
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->TotalL, v23, v34);
      }
      v8->SolidL = v23;
      v8->TotalL = v34;
    }
  }
  else
  {
    if ( *(_WORD *)&p->overlapPrev )
    {
      v35 = v1->x - p->dx1TotalL;
      v36 = v1->y - p->dy1TotalL;
    }
    else
    {
      v35 = p->xMiterThisL;
      v36 = p->yMiterThisL;
    }
    v37 = v1->x;
    v38 = v1->y;
    v39 = (float)((float)(v35 - v37) * w->solidCoeffL) + v37;
    v40 = (float)((float)(v36 - v38) * w->solidCoeffL) + v38;
    if ( lineJoin )
    {
      v49 = Scaleform::Render::StrokerAA::addVertex(this, v37 + p->dx1SolidR, v38 + p->dy1SolidR, this->StyleRight, 1u);
      v50 = v5->dbTotalR;
      v48 = v49;
      v51 = v5->dMiterThisR - v50;
      if ( v51 == 0.0 )
        v51 = *(float *)&FLOAT_1_0;
      v47 = (float)((float)((float)(v5->dbSolidR + v6->totalWidthR) - v6->solidWidthR) - v50) / v51;
    }
    else
    {
      v41 = p->dbSolidR;
      v42 = p->dSolidMiterR - v41;
      if ( v42 == 0.0 )
        v42 = *(float *)&FLOAT_1_0;
      v43 = (float)((float)(w->totalLimitR - v41) - w->totalWidthR) + w->solidWidthR;
      if ( v43 > v42 )
        v43 = v42;
      v44 = (float)(w->solidLimitR - v41) + v43;
      v45 = p->dbTotalR;
      v9 = v44 / (float)(v42 * 2.0);
      v46 = p->dMiterThisR - v45;
      if ( v46 == 0.0 )
        v46 = *(float *)&FLOAT_1_0;
      v47 = (float)((float)((float)((float)(w->solidLimitR - v45) + w->totalWidthR) - w->solidWidthR)
                  + (float)(w->totalLimitR - v45))
          / (float)(v46 * 2.0);
      v48 = Scaleform::Render::StrokerAA::addVertex(
              this,
              (float)((float)(p->xSolidMiterR - (float)(v37 + p->dx1SolidR)) * v9) + (float)(v37 + p->dx1SolidR),
              (float)((float)(p->ySolidMiterR - (float)(v38 + p->dy1SolidR)) * v9) + (float)(v38 + p->dy1SolidR),
              this->StyleRight,
              1u);
    }
    if ( v6->aaFlagR )
    {
      v52 = v5->dy1TotalR + v7->y;
      v3a = Scaleform::Render::StrokerAA::addVertex(
              v8,
              (float)((float)(v5->xMiterThisR - (float)(v5->dx1TotalR + v7->x)) * v47) + (float)(v5->dx1TotalR + v7->x),
              (float)((float)(v5->yMiterThisR - v52) * v47) + v52,
              v8->StyleRight,
              0);
    }
    else
    {
      v3a = v48;
    }
    if ( v6->solidFlag )
      v53 = Scaleform::Render::StrokerAA::addVertex(v8, v39, v40, v8->StyleLeft, 1u);
    else
      v53 = v48;
    if ( v6->aaFlagL )
      v54 = Scaleform::Render::StrokerAA::addVertex(v8, v35, v36, v8->StyleLeft, 0);
    else
      v54 = v53;
    if ( v6->solidFlagL || v6->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v48, v53);
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v53, v8->SolidL);
    }
    if ( v6->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->TotalR, v48, v8->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->TotalR, v3a, v48);
    }
    if ( v6->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v53, v54);
      Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v54, v8->TotalL);
    }
    v8->SolidL = v53;
    v8->TotalL = v54;
    v8->SolidR = v48;
    v8->TotalR = v3a;
    if ( v62 )
    {
      v8->SolidL = Scaleform::Render::StrokerAA::addVertex(
                     v8,
                     v7->x - v5->dx2SolidL,
                     v7->y - v5->dy2SolidL,
                     v8->StyleLeft,
                     1u);
      if ( v6->aaFlagL )
        v53 = Scaleform::Render::StrokerAA::addVertex(
                v8,
                v7->x - v5->dx2TotalL,
                v7->y - v5->dy2TotalL,
                v8->StyleLeft,
                0);
      v8->TotalL = v53;
    }
    if ( (float)(v6->totalWidthR - v5->dbTotalR) > (float)((float)(v8->Tolerance * 0.25) * 0.25) )
    {
      if ( v6->solidFlag )
      {
        if ( lineJoin )
        {
          v56 = v5->dy2SolidR + v7->y;
          v57 = v5->dx2SolidR + v7->x;
        }
        else
        {
          v55 = v5->dy2SolidR + v7->y;
          v56 = (float)((float)(v5->ySolidMiterR - v55) * v9) + v55;
          v57 = (float)((float)(v5->xSolidMiterR - (float)(v5->dx2SolidR + v7->x)) * v9)
              + (float)(v5->dx2SolidR + v7->x);
        }
        v48 = Scaleform::Render::StrokerAA::addVertex(v8, v57, v56, v8->StyleRight, 1u);
      }
      if ( v6->aaFlagR )
      {
        v58 = v5->dy2TotalR + v7->y;
        v59 = Scaleform::Render::StrokerAA::addVertex(
                v8,
                (float)((float)(v5->xMiterThisR - (float)(v5->dx2TotalR + v7->x)) * v47)
              + (float)(v5->dx2TotalR + v7->x),
                (float)((float)(v5->yMiterThisR - v58) * v47) + v58,
                v8->StyleRight,
                0);
      }
      else
      {
        v59 = v48;
      }
      if ( v6->solidFlagR )
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v8->SolidR, v48);
      if ( v6->aaFlagR )
      {
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidR, v8->TotalR, v48);
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->TotalR, v59, v48);
      }
      v8->SolidR = v48;
      v8->TotalR = v59;
    }
  }
}v6->solidFlagR )
        Scaleform::Render::StrokerAA::addTriangle(v8, v8->SolidL, v8->SolidR, v48);
      if 

// File Line: 814
// RVA: 0x9D11B0
void __fastcall Scaleform::Render::StrokerAA::calcButtJoin(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v0, Scaleform::Render::StrokeVertex *v1, float len, Scaleform::Render::StrokerAA::WidthsType *w)
{
  float v5; // xmm5_4
  Scaleform::Render::StrokeVertex *v6; // r14
  Scaleform::Render::StrokerAA *v7; // rbx
  float v8; // xmm4_4
  float v9; // xmm8_4
  float v10; // xmm11_4
  float v11; // xmm9_4
  float v12; // xmm2_4
  float v13; // xmm6_4
  float v14; // xmm10_4
  float v15; // xmm7_4
  unsigned int v16; // eax
  unsigned int v17; // ebp
  unsigned int v18; // er15
  unsigned int v19; // edi
  unsigned int v20; // er14

  v5 = v1->y;
  v6 = v1;
  v7 = this;
  v8 = (float)(v5 - v0->y) * (float)(1.0 / len);
  v9 = w->solidWidthR * v8;
  v10 = w->totalWidthL * v8;
  v11 = w->totalWidthR * v8;
  v12 = (float)(v0->x - v1->x) * (float)(1.0 / len);
  v13 = w->solidWidthR * v12;
  v14 = w->totalWidthL * v12;
  v15 = w->totalWidthR * v12;
  v16 = Scaleform::Render::StrokerAA::addVertex(
          this,
          v1->x - (float)(w->solidWidthL * v8),
          v5 - (float)(w->solidWidthL * v12),
          this->StyleLeft,
          1u);
  v17 = v16;
  if ( w->aaFlagL )
    v16 = Scaleform::Render::StrokerAA::addVertex(v7, v6->x - v10, v6->y - v14, v7->StyleLeft, 0);
  v18 = v16;
  if ( w->solidFlag )
    v19 = Scaleform::Render::StrokerAA::addVertex(v7, v9 + v6->x, v13 + v6->y, v7->StyleRight, 1u);
  else
    v19 = v17;
  if ( w->aaFlagR )
    v20 = Scaleform::Render::StrokerAA::addVertex(v7, v11 + v6->x, v15 + v6->y, v7->StyleRight, 0);
  else
    v20 = v19;
  if ( *(_WORD *)&w->solidFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(v7, v7->SolidL, v19, v17);
    Scaleform::Render::StrokerAA::addTriangle(v7, v7->SolidL, v7->SolidR, v19);
  }
  if ( w->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(v7, v7->TotalL, v7->SolidL, v17);
    Scaleform::Render::StrokerAA::addTriangle(v7, v7->TotalL, v17, v18);
  }
  if ( w->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(v7, v7->SolidR, v20, v19);
    Scaleform::Render::StrokerAA::addTriangle(v7, v7->SolidR, v7->TotalR, v20);
  }
  v7->SolidL = v17;
  v7->TotalL = v18;
  v7->SolidR = v19;
  v7->TotalR = v20;
}

// File Line: 872
// RVA: 0x9D43B0
void __fastcall Scaleform::Render::StrokerAA::calcMiterJoin(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v1, Scaleform::Render::StrokerAA::WidthsType *w, Scaleform::Render::StrokerAA::JoinParamType *p, Scaleform::Render::StrokerTypes::LineJoinType lineJoin)
{
  bool v5; // r12
  Scaleform::Render::StrokerAA::JoinParamType *v6; // rdi
  Scaleform::Render::StrokerAA::WidthsType *v7; // rsi
  Scaleform::Render::StrokeVertex *v8; // rbp
  Scaleform::Render::StrokerAA *v9; // rbx
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm8_4
  float v13; // xmm9_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  Scaleform::Render::StrokerTypes::LineJoinType v16; // eax
  float v17; // xmm10_4
  float v18; // xmm11_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  unsigned int v23; // eax
  unsigned int v24; // er15
  unsigned int v25; // er14
  unsigned int v26; // er13
  unsigned int v3; // [rsp+D8h] [rbp+20h]

  v5 = p->overlapPrev || p->overlapThis;
  v6 = p;
  v7 = w;
  v8 = v1;
  v9 = this;
  if ( p->rightTurnThis )
  {
    v10 = v1->x;
    v11 = v1->y;
    v12 = p->xMiterThisL;
    v13 = p->yMiterThisL;
    v14 = (float)((float)(p->xMiterThisL - v10) * w->solidCoeffL) + v10;
    v15 = (float)((float)(p->yMiterThisL - v11) * w->solidCoeffL) + v11;
    if ( w->totalLimitL < p->dMiterThisL )
    {
      v16 = lineJoin;
      if ( (unsigned int)lineJoin <= 1 )
      {
LABEL_4:
        Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, v16);
        return;
      }
    }
    if ( *(_WORD *)&p->overlapPrev )
    {
      v17 = v10 + p->dx1TotalR;
      v18 = v11 + p->dy1TotalR;
    }
    else
    {
      v17 = p->xMiterThisR;
      v18 = p->yMiterThisR;
    }
    v19 = (float)((float)(v17 - v10) * w->solidCoeffR) + v10;
    v20 = (float)((float)(v18 - v11) * w->solidCoeffR) + v11;
  }
  else
  {
    v21 = v1->x;
    v22 = v1->y;
    v17 = p->xMiterThisR;
    v18 = p->yMiterThisR;
    v19 = (float)((float)(p->xMiterThisR - v21) * w->solidCoeffR) + v21;
    v20 = (float)((float)(p->yMiterThisR - v22) * w->solidCoeffR) + v22;
    if ( w->totalLimitR < p->dMiterThisR )
    {
      v16 = lineJoin;
      if ( (unsigned int)lineJoin <= 1 )
        goto LABEL_4;
    }
    if ( *(_WORD *)&p->overlapPrev )
    {
      v12 = v21 - p->dx1TotalL;
      v13 = v22 - p->dy1TotalL;
    }
    else
    {
      v12 = p->xMiterThisL;
      v13 = p->yMiterThisL;
    }
    v14 = (float)((float)(v12 - v21) * w->solidCoeffL) + v21;
    v15 = (float)((float)(v13 - v22) * w->solidCoeffL) + v22;
  }
  v23 = Scaleform::Render::StrokerAA::addVertex(this, v14, v15, this->StyleLeft, 1u);
  v24 = v23;
  if ( v7->aaFlagL )
    v23 = Scaleform::Render::StrokerAA::addVertex(v9, v12, v13, v9->StyleLeft, 0);
  v3 = v23;
  if ( v7->solidFlag )
    v25 = Scaleform::Render::StrokerAA::addVertex(v9, v19, v20, v9->StyleRight, 1u);
  else
    v25 = v24;
  if ( v7->aaFlagR )
    v26 = Scaleform::Render::StrokerAA::addVertex(v9, v17, v18, v9->StyleRight, 0);
  else
    v26 = v25;
  if ( v7->solidFlagL || v7->solidFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v25, v24);
    Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidL, v9->SolidR, v25);
  }
  if ( v7->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalL, v9->SolidL, v24);
    Scaleform::Render::StrokerAA::addTriangle(v9, v9->TotalL, v24, v3);
  }
  if ( v7->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v26, v25);
    Scaleform::Render::StrokerAA::addTriangle(v9, v9->SolidR, v9->TotalR, v26);
  }
  v9->TotalR = v26;
  v9->TotalL = v3;
  v9->SolidL = v24;
  v9->SolidR = v25;
  if ( v5 )
  {
    if ( v6->rightTurnThis )
    {
      v9->SolidR = Scaleform::Render::StrokerAA::addVertex(
                     v9,
                     v6->dx2SolidR + v8->x,
                     v6->dy2SolidR + v8->y,
                     v9->StyleRight,
                     1u);
      if ( v7->aaFlagR )
        v25 = Scaleform::Render::StrokerAA::addVertex(
                v9,
                v6->dx2TotalR + v8->x,
                v6->dy2TotalR + v8->y,
                v9->StyleRight,
                0);
      v9->TotalR = v25;
    }
    else
    {
      v9->SolidL = Scaleform::Render::StrokerAA::addVertex(
                     v9,
                     v8->x - v6->dx2SolidL,
                     v8->y - v6->dy2SolidL,
                     v9->StyleLeft,
                     1u);
      if ( v7->aaFlagL )
        v24 = Scaleform::Render::StrokerAA::addVertex(
                v9,
                v8->x - v6->dx2TotalL,
                v8->y - v6->dy2TotalL,
                v9->StyleLeft,
                0);
      v9->TotalL = v24;
    }
  }
}

// File Line: 986
// RVA: 0x99B710
bool __fastcall Scaleform::Render::StrokerAA::MitersIntersect(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float epsilon)
{
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm4_4

  v9 = by - ay;
  v10 = (float)((float)(dy - cy) * (float)(bx - ax)) - (float)((float)(dx - cx) * (float)(by - ay));
  if ( COERCE_FLOAT(LODWORD(v10) & _xmm) < epsilon )
    return 1;
  v12 = ay - cy;
  v13 = 1.0 / v10;
  v14 = (float)((float)(v12 * (float)(dx - cx)) - (float)((float)(ax - cx) * (float)(dy - cy))) * (float)(1.0 / v10);
  v15 = (float)((float)(v12 * (float)(bx - ax)) - (float)((float)(ax - cx) * v9)) * v13;
  return v14 >= 0.0 && v14 <= 1.0 && v15 >= 0.0 && v15 <= 1.0;
}

// File Line: 1005
// RVA: 0x9D2760
void __fastcall Scaleform::Render::StrokerAA::calcJoinParam(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokeVertex *v1, Scaleform::Render::StrokeVertex *v2, Scaleform::Render::StrokeVertex *v3, Scaleform::Render::StrokerAA::WidthsType *w, Scaleform::Render::StrokerAA::JoinParamType *p)
{
  Scaleform::Render::StrokerAA::JoinParamType *v6; // rbx
  Scaleform::Render::StrokeVertex *v7; // rbp
  Scaleform::Render::StrokeVertex *v8; // rdi
  float v9; // eax
  float v10; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm11_4
  float v13; // xmm9_4
  float v14; // xmm11_4
  float v15; // eax
  float *v16; // r13
  float *v17; // r15
  float *v18; // r12
  float *v19; // r14
  float epsilon; // xmm13_4
  float v21; // xmm8_4
  __m128 v22; // xmm7
  __m128 v23; // xmm0
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  __m128 v28; // xmm0
  float v29; // xmm9_4
  __m128 v30; // xmm8
  __m128 v31; // xmm0
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  __m128 v35; // xmm0
  bool v36; // dl
  bool v37; // cl
  float v38; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  __m128 v41; // xmm3
  float v42; // xmm5_4
  float v43; // xmm5_4
  float v44; // xmm9_4
  float v45; // xmm8_4
  float v46; // xmm1_4
  float v47; // eax
  __m128 v48; // xmm1
  float v49; // xmm0_4
  float v50; // eax
  float v51; // xmm3_4
  float v52; // xmm3_4
  float v53; // eax
  float v54; // xmm1_4
  float v55; // xmm1_4
  bool v56; // zf
  bool v57; // al
  float v58; // xmm0_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  Scaleform::Render::StrokeVertex *v63; // [rsp+128h] [rbp+20h]
  char pa; // [rsp+138h] [rbp+30h]

  v63 = v3;
  v6 = p;
  v7 = v1;
  v8 = v2;
  p->dx1SolidL = p->dx2SolidL;
  v6->dy1SolidL = v6->dy2SolidL;
  v6->dx1SolidR = v6->dx2SolidR;
  v6->dy1SolidR = v6->dy2SolidR;
  v6->dx1TotalL = v6->dx2TotalL;
  v6->dy1TotalL = v6->dy2TotalL;
  v6->dx1TotalR = v6->dx2TotalR;
  v6->dy1TotalR = v6->dy2TotalR;
  v6->dx2SolidL = v6->dx3SolidL;
  v6->dy2SolidL = v6->dy3SolidL;
  v6->dx2SolidR = v6->dx3SolidR;
  v6->dy2SolidR = v6->dy3SolidR;
  v6->dx2TotalL = v6->dx3TotalL;
  v6->dy2TotalL = v6->dy3TotalL;
  v6->dx2TotalR = v6->dx3TotalR;
  v6->dy2TotalR = v6->dy3TotalR;
  v9 = p->xMiterThisL;
  v10 = 1.0 / v2->dist;
  v11 = (float)(v3->y - v2->y) * v10;
  v12 = (float)(v2->x - v3->x) * v10;
  p->dx3SolidL = v11 * w->solidWidthL;
  p->dy3SolidL = v12 * w->solidWidthL;
  p->dx3SolidR = v11 * w->solidWidthR;
  p->dy3SolidR = v12 * w->solidWidthR;
  p->dx3TotalL = v11 * w->totalWidthL;
  p->dy3TotalL = v12 * w->totalWidthL;
  v13 = v11 * w->totalWidthR;
  p->dx3TotalR = v13;
  v14 = v12 * w->totalWidthR;
  p->xMiterPrevL = v9;
  v6->yMiterPrevL = v6->yMiterThisL;
  v15 = p->xMiterThisR;
  p->dy3TotalR = v14;
  p->xMiterPrevR = v15;
  v16 = &p->xMiterNextL;
  v6->yMiterPrevR = v6->yMiterThisR;
  v17 = &p->yMiterNextL;
  v6->dMiterPrevL = v6->dMiterThisL;
  v18 = &p->xMiterNextR;
  v6->dMiterPrevR = v6->dMiterThisR;
  v19 = &p->yMiterNextR;
  v6->xMiterThisL = v6->xMiterNextL;
  pa = 1;
  v6->yMiterThisL = v6->yMiterNextL;
  v6->xMiterThisR = v6->xMiterNextR;
  v6->yMiterThisR = v6->yMiterNextR;
  v6->dMiterThisL = v6->dMiterNextL;
  v6->dMiterThisR = v6->dMiterNextR;
  v6->badMiterPrevL = v6->badMiterThisL;
  v6->badMiterPrevR = v6->badMiterThisR;
  v6->badMiterThisL = v6->badMiterNextL;
  v6->badMiterThisR = v6->badMiterNextR;
  epsilon = (float)(v3->dist + v2->dist) * this->IntersectionEpsilon;
  if ( w->rightSideCalc )
  {
    v21 = v6->dx2TotalR;
    v22 = (__m128)LODWORD(v6->dy2TotalR);
    v23 = v22;
    v24 = v6->dy2TotalR;
    v23.m128_f32[0] = (float)((float)((float)(v22.m128_f32[0] + v6->dy1TotalR) * 0.5)
                            * (float)((float)(v22.m128_f32[0] + v6->dy1TotalR) * 0.5))
                    + (float)((float)((float)(v21 + v6->dx1TotalR) * 0.5) * (float)((float)(v21 + v6->dx1TotalR) * 0.5));
    LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v23);
    v6->dbTotalR = v25;
    v6->dbSolidR = v25 * w->solidCoeffR;
    v26 = v25 * w->widthCoeff;
    v6->dbTotalL = v26;
    v6->dbSolidL = v26 * w->solidCoeffL;
    if ( !Scaleform::Render::Math2D::Intersection(
            v21 + v1->x,
            v22.m128_f32[0] + v1->y,
            v21 + v2->x,
            v24 + v2->y,
            v13 + v2->x,
            v14 + v2->y,
            v13 + v3->x,
            v14 + v3->y,
            &v6->xMiterNextR,
            &v6->yMiterNextR,
            epsilon) )
      goto LABEL_7;
    v27 = *v18;
    v28 = (__m128)*(unsigned int *)v19;
    v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] - v8->y) * (float)(v28.m128_f32[0] - v8->y))
                    + (float)((float)(*v18 - v8->x) * (float)(*v18 - v8->x));
    v28.m128_i32[0] = (unsigned __int128)_mm_sqrt_ps(v28);
    LODWORD(v6->dMiterNextR) = v28.m128_i32[0];
    v6->dMiterNextL = v28.m128_f32[0] * w->widthCoeff;
    v28.m128_f32[0] = *v19;
    *v16 = v8->x - (float)((float)(v27 - v8->x) * w->widthCoeff);
    *v17 = v8->y - (float)((float)(v28.m128_f32[0] - v8->y) * w->widthCoeff);
  }
  else
  {
    v29 = v6->dx2TotalL;
    v30 = (__m128)LODWORD(v6->dy2TotalL);
    v31 = v30;
    v31.m128_f32[0] = (float)((float)((float)(v30.m128_f32[0] + v6->dy1TotalL) * 0.5)
                            * (float)((float)(v30.m128_f32[0] + v6->dy1TotalL) * 0.5))
                    + (float)((float)((float)(v29 + v6->dx1TotalL) * 0.5) * (float)((float)(v29 + v6->dx1TotalL) * 0.5));
    LODWORD(v32) = (unsigned __int128)_mm_sqrt_ps(v31);
    v6->dbTotalL = v32;
    v6->dbSolidL = v32 * w->solidCoeffL;
    v33 = v32 * w->widthCoeff;
    v6->dbTotalR = v33;
    v6->dbSolidR = v33 * w->solidCoeffR;
    if ( !Scaleform::Render::Math2D::Intersection(
            v1->x - v29,
            v1->y - v30.m128_f32[0],
            v2->x - v29,
            v2->y - v30.m128_f32[0],
            v2->x - v6->dx3TotalL,
            v2->y - v6->dy3TotalL,
            v3->x - v6->dx3TotalL,
            v3->y - v6->dy3TotalL,
            &v6->xMiterNextL,
            &v6->yMiterNextL,
            epsilon) )
      goto LABEL_7;
    v34 = *v16;
    v35 = (__m128)*(unsigned int *)v17;
    v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] - v8->y) * (float)(v35.m128_f32[0] - v8->y))
                    + (float)((float)(*v16 - v8->x) * (float)(*v16 - v8->x));
    v35.m128_i32[0] = (unsigned __int128)_mm_sqrt_ps(v35);
    LODWORD(v6->dMiterNextL) = v35.m128_i32[0];
    v6->dMiterNextR = v35.m128_f32[0] * w->widthCoeff;
    v35.m128_f32[0] = *v17;
    *v18 = v8->x - (float)((float)(v34 - v8->x) * w->widthCoeff);
    *v19 = v8->y - (float)((float)(v35.m128_f32[0] - v8->y) * w->widthCoeff);
  }
  pa = 0;
  *(_WORD *)&v6->badMiterNextL = 0;
LABEL_7:
  v6->rightTurnPrev = v6->rightTurnThis;
  v6->rightTurnThis = v6->rightTurnNext;
  v36 = (float)((float)((float)(v63->x - v8->x) * (float)(v8->y - v7->y))
              - (float)((float)(v8->x - v7->x) * (float)(v63->y - v8->y))) > 0.0;
  v6->rightTurnNext = v36;
  if ( pa )
  {
    v37 = w->rightSideCalc;
    v38 = v8->x;
    v39 = v8->x;
    if ( v37 )
      v40 = v39 + v6->dx2TotalR;
    else
      v40 = v39 - v6->dx2TotalL;
    v41 = (__m128)LODWORD(v8->y);
    v42 = v8->y;
    if ( v37 )
      v43 = v42 + v6->dy2TotalR;
    else
      v43 = v42 - v6->dy2TotalL;
    v44 = v63->y;
    v45 = v7->y;
    if ( (float)((float)((float)(v41.m128_f32[0] - v45) * (float)(v40 - v38))
               - (float)((float)(v38 - v7->x) * (float)(v43 - v41.m128_f32[0]))) < 0.0 == (float)((float)((float)(v40 - v63->x) * (float)(v63->y - v41.m128_f32[0]))
                                                                                                - (float)((float)(v63->x - v38) * (float)(v43 - v44))) < 0.0 )
    {
      v46 = v6->dy2TotalR;
      *v16 = v38 - v6->dx2TotalL;
      *v17 = v8->y - v6->dy2TotalL;
      v6->dMiterNextL = w->totalLimitL;
      *v18 = v8->x + v6->dx2TotalR;
      *v19 = v46 + v8->y;
      v47 = w->totalLimitR;
      *(_WORD *)&v6->badMiterNextL = 0;
      v6->dMiterNextR = v47;
    }
    else
    {
      v48 = (__m128)LODWORD(v8->x);
      v48.m128_f32[0] = (float)(v38 - (float)((float)(v7->x + v63->x) * 0.5)) * 1024.0;
      v41.m128_f32[0] = (float)(v41.m128_f32[0] - (float)((float)(v45 + v44) * 0.5)) * 1024.0;
      if ( v36 )
      {
        v49 = v6->dy2TotalR;
        *v18 = v38 + v6->dx2TotalR;
        *v19 = v49 + v8->y;
        v50 = w->totalLimitR;
        v6->badMiterNextR = 1;
        v6->dMiterNextR = v50;
        v48.m128_f32[0] = v48.m128_f32[0] + v8->x;
        *v16 = v48.m128_f32[0];
        v51 = v41.m128_f32[0] + v8->y;
        *v17 = v51;
        v48.m128_f32[0] = v48.m128_f32[0] - v8->x;
        v52 = v51 - v8->y;
        v6->badMiterNextL = 0;
        v48.m128_f32[0] = (float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v52 * v52);
        LODWORD(v6->dMiterNextL) = (unsigned __int128)_mm_sqrt_ps(v48);
      }
      else
      {
        *v16 = v38 - v6->dx2TotalL;
        *v17 = v8->y - v6->dy2TotalL;
        v53 = w->totalLimitL;
        v6->badMiterNextL = 1;
        v6->dMiterNextL = v53;
        v54 = v48.m128_f32[0] + v8->x;
        *v18 = v54;
        v41.m128_f32[0] = v41.m128_f32[0] + v8->y;
        *v19 = v41.m128_f32[0];
        v41.m128_f32[0] = v41.m128_f32[0] - v8->y;
        v55 = v54 - v8->x;
        v6->badMiterNextR = 0;
        v41.m128_f32[0] = (float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v55 * v55);
        LODWORD(v6->dMiterNextR) = (unsigned __int128)_mm_sqrt_ps(v41);
      }
    }
  }
  v56 = v6->rightTurnThis == 0;
  v6->overlapPrev = v6->overlapThis;
  if ( v56 )
    v57 = v6->badMiterThisL;
  else
    v57 = v6->badMiterThisR;
  v6->overlapThis = v57;
  if ( !v57 )
    v6->overlapThis = Scaleform::Render::StrokerAA::MitersIntersect(
                        v6->xMiterThisL,
                        v6->yMiterThisL,
                        v6->xMiterThisR,
                        v6->yMiterThisR,
                        *v16,
                        *v17,
                        *v18,
                        *v19,
                        epsilon);
  v58 = v6->yMiterThisL;
  v59 = v6->xMiterThisR;
  v6->xSolidMiterL = (float)((float)(v6->xMiterThisL - v7->x) * w->solidCoeffL) + v7->x;
  v60 = v6->yMiterThisR;
  v6->ySolidMiterL = (float)((float)(v58 - v7->y) * w->solidCoeffL) + v7->y;
  v61 = v6->dMiterThisL;
  v6->xSolidMiterR = (float)((float)(v59 - v7->x) * w->solidCoeffR) + v7->x;
  v6->ySolidMiterR = (float)((float)(v60 - v7->y) * w->solidCoeffR) + v7->y;
  v62 = v6->dMiterThisR;
  v6->dSolidMiterL = v61 * w->solidCoeffL;
  v6->dSolidMiterR = v62 * w->solidCoeffR;
}

// File Line: 1250
// RVA: 0x9D56B0
void __fastcall Scaleform::Render::StrokerAA::calcWidths(Scaleform::Render::StrokerAA *this, Scaleform::Render::StrokerAA::WidthsType *w)
{
  bool v2; // r9
  bool v3; // cf
  bool v4; // zf
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4

  v2 = 0;
  w->solidWidthL = this->WidthLeft;
  v3 = w->solidWidthL > 0.0;
  v4 = w->solidWidthL == 0.0;
  w->solidWidthR = this->WidthRight;
  if ( !v3 && !v4 )
    w->solidWidthL = 0.0;
  if ( w->solidWidthR < 0.0 )
    w->solidWidthR = 0.0;
  v5 = w->solidWidthL;
  v6 = w->solidWidthR;
  v7 = *(float *)&FLOAT_1_0;
  v8 = w->solidWidthR;
  v9 = w->solidWidthL + this->AaWidthLeft;
  w->totalWidthL = v9;
  w->totalWidthR = v8 + this->AaWidthRight;
  if ( v9 == 0.0 )
    v10 = *(float *)&FLOAT_1_0;
  else
    v10 = v5 / v9;
  v11 = w->totalWidthR;
  w->solidCoeffL = v10;
  if ( v11 != 0.0 )
    v7 = v6 / v11;
  w->solidCoeffR = v7;
  w->solidLimitL = v5 * this->MiterLimit;
  w->solidLimitR = v6 * this->MiterLimit;
  w->totalLimitL = v9 * this->MiterLimit;
  v12 = v11 * this->MiterLimit;
  w->solidFlagL = v5 > 0.0;
  w->totalLimitR = v12;
  w->solidFlagR = v6 > 0.0;
  w->totalWidth = (float)(v11 + v9) * 0.5;
  w->solidWidth = (float)(v6 + v5) * 0.5;
  w->aaFlagL = this->AaWidthLeft > 0.0;
  w->aaFlagR = this->AaWidthRight > 0.0;
  if ( v5 > 0.0 || v6 > 0.0 || this->StyleLeft != this->StyleRight )
    v2 = 1;
  w->solidFlag = v2;
  w->rightSideCalc = v11 > v9;
  if ( v11 <= v9 )
    w->widthCoeff = v11 / v9;
  else
    w->widthCoeff = v9 / v11;
}

// File Line: 1287
// RVA: 0x978840
void __fastcall Scaleform::Render::StrokerAA::FinalizePath(Scaleform::Render::StrokerAA *this, unsigned int __formal, unsigned int a3, bool a4, bool __formala)
{
  Scaleform::Render::StrokerAA *v5; // r14
  bool v6; // zf
  unsigned __int64 v7; // r15
  Scaleform::Render::StrokeVertex **v8; // rbx
  Scaleform::Render::StrokeVertex *v9; // rsi
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rsi
  unsigned __int64 v14; // r9
  unsigned __int64 v15; // r8
  Scaleform::Render::StrokeVertex *v16; // rbx
  signed int v17; // eax
  signed __int64 v18; // r10
  unsigned __int64 v19; // rax
  Scaleform::Render::StrokerAA::TriangleType *v20; // r9
  float v21; // xmm4_4
  float **v22; // rax
  float *v23; // rcx
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  unsigned __int64 v27; // rdx
  Scaleform::Render::StrokeVertex **v28; // r8
  signed __int64 v29; // r10
  Scaleform::Render::StrokeVertex *v30; // r9
  unsigned __int64 v31; // rcx
  signed __int64 v32; // rdx
  Scaleform::Render::StrokeVertex *v33; // rax
  float v34; // xmm1_4
  Scaleform::Render::StrokeVertex *v35; // rdx
  signed int v36; // eax
  Scaleform::Render::StrokeVertex *v37; // r8
  float v38; // xmm3_4
  unsigned __int64 v39; // r15
  Scaleform::Render::StrokeVertex **v40; // rax
  Scaleform::Render::StrokeVertex *v41; // rdx
  float v42; // xmm6_4
  float v43; // xmm8_4
  float v44; // xmm7_4
  float v45; // xmm3_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  unsigned __int64 v48; // r15
  unsigned __int64 v49; // rbx
  unsigned __int64 v50; // rsi
  Scaleform::Render::StrokeVertex **v51; // r8
  Scaleform::Render::StrokeVertex *v52; // rdi
  signed int v53; // eax
  Scaleform::Render::StrokeVertex **v54; // r10
  Scaleform::Render::StrokeVertex *v55; // r8
  Scaleform::Render::StrokeVertex *v56; // rcx
  Scaleform::Render::StrokeVertex *v57; // rax
  unsigned __int64 v58; // rdx
  Scaleform::Render::StrokeVertex *v59; // rbx
  Scaleform::Render::StrokeVertex *v60; // rax
  signed int v61; // eax
  unsigned __int64 v62; // rax
  unsigned __int64 v63; // rax
  Scaleform::Render::StrokeVertex **v64; // r10
  float v65; // xmm3_4
  Scaleform::Render::StrokeVertex *v66; // r8
  Scaleform::Render::StrokeVertex *v67; // rdx
  signed int v68; // eax
  Scaleform::Render::StrokerAA::WidthsType w; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::StrokeVertex v3; // [rsp+70h] [rbp-90h]
  Scaleform::Render::StrokerAA::JoinParamType p; // [rsp+80h] [rbp-80h]

  v5 = this;
  if ( !this->Closed )
    this->Closed = Scaleform::Render::StrokePath::ClosePath(&this->Path);
  v5->SolidL = -4;
  v5->SolidR = -3;
  *(_QWORD *)&v5->TotalL = -2i64;
  *(_QWORD *)&w.solidWidthL = 0i64;
  *(_QWORD *)&w.solidWidth = 0i64;
  *(_QWORD *)&w.totalWidthR = 0i64;
  *(_QWORD *)&w.widthCoeff = 0i64;
  *(_QWORD *)&w.solidCoeffR = 0i64;
  *(_QWORD *)&w.solidLimitR = 0i64;
  *(_QWORD *)&w.totalLimitR = 0i64;
  *(_WORD *)&w.solidFlag = 0;
  Scaleform::Render::StrokerAA::calcWidths(v5, &w);
  v6 = v5->Closed == 0;
  *(_OWORD *)&p.dx1SolidL = 0i64;
  *(_OWORD *)&p.dx2SolidL = 0i64;
  *(_OWORD *)&p.dx3SolidL = 0i64;
  *(_OWORD *)&p.dx1SolidR = 0i64;
  *(_OWORD *)&p.dx2SolidR = 0i64;
  *(_QWORD *)&p.badMiterPrevL = 0i64;
  *(_WORD *)&p.rightTurnNext = 0;
  p.overlapThis = 0;
  *(_OWORD *)&p.dx3SolidR = 0i64;
  *(_OWORD *)&p.dbSolidL = 0i64;
  *(_OWORD *)&p.xMiterPrevL = 0i64;
  *(_OWORD *)&p.dMiterPrevL = 0i64;
  *(_OWORD *)&p.xMiterThisR = 0i64;
  *(_OWORD *)&p.xMiterNextL = 0i64;
  *(_OWORD *)&p.dMiterNextL = 0i64;
  *(_OWORD *)&p.xSolidMiterR = 0i64;
  if ( v6 )
  {
    if ( v5->Path.Path.Size > 1 )
    {
      v21 = (float)(v5->WidthRight + v5->WidthLeft) * 0.5;
      if ( v5->StartLineCap == 1 )
      {
        v22 = (float **)v5->Path.Path.Pages;
        v23 = *v22;
        v24 = (*v22)[2];
        *v23 = **v22 - (float)((float)((float)((*v22)[3] - **v22) * v21) * (float)(1.0 / v24));
        v25 = v23[1];
        v26 = v23[4];
        v23[2] = v24 + v21;
        v23[1] = v25 - (float)((float)((float)(v26 - v25) * v21) * (float)(1.0 / v24));
      }
      if ( v5->EndLineCap == 1 )
      {
        v27 = v5->Path.Path.Size;
        v28 = v5->Path.Path.Pages;
        v29 = ((_DWORD)v27 - 2) & 0xF;
        v30 = v28[(v27 - 2) >> 4];
        v31 = (v27 - 1) >> 4;
        v32 = ((_DWORD)v27 - 1) & 0xF;
        v33 = v28[v31];
        v34 = v33[v32].y;
        v33[v32].x = (float)((float)((float)(v33[v32].x - v30[v29].x) * v21) / v30[v29].dist) + v33[v32].x;
        v33[v32].y = (float)((float)((float)(v34 - v30[v29].y) * v21) / v30[v29].dist) + v34;
        v30[v29].dist = v21 + v30[v29].dist;
      }
      v35 = *v5->Path.Path.Pages;
      v36 = v5->StartLineCap;
      v37 = v35 + 1;
      v38 = v35->dist;
      if ( v36 >= 0 )
      {
        if ( v36 <= 1 )
        {
          Scaleform::Render::StrokerAA::calcButtCap(v5, v35, v37, v38, &w, 0);
        }
        else if ( v36 == 2 )
        {
          Scaleform::Render::StrokerAA::calcRoundCap(v5, v35, v37, v38, &w, 0);
        }
      }
      v39 = v5->Path.Path.Size;
      if ( v39 > 2 )
      {
        v40 = v5->Path.Path.Pages;
        p.overlapThis = 0;
        p.rightTurnNext = 0;
        v41 = *v40;
        *(_WORD *)&p.badMiterNextL = 0;
        p.dMiterNextR = w.totalWidthR;
        v42 = 1.0 / v41->dist;
        v43 = v41->x;
        v44 = (float)(v41->x - v41[1].x) * v42;
        v45 = v41[1].y - v41->y;
        p.dy3SolidL = w.solidWidthL * v44;
        v46 = v45 * v42;
        p.dMiterNextL = w.totalWidthL;
        p.dx3SolidL = w.solidWidthL * v46;
        p.dx3TotalL = w.totalWidthL * v46;
        p.dy3SolidR = w.solidWidthR * v44;
        p.dy3TotalL = w.totalWidthL * v44;
        p.dx3SolidR = w.solidWidthR * v46;
        v47 = v41->y;
        p.dx3TotalR = w.totalWidthR * v46;
        p.dy3TotalR = w.totalWidthR * v44;
        p.yMiterNextR = (float)(w.totalWidthR * v44) + v41->y;
        p.xMiterNextL = v43 - (float)(w.totalWidthL * v46);
        p.yMiterNextL = v47 - (float)(w.totalWidthL * v44);
        p.xMiterNextR = v43 + (float)(w.totalWidthR * v46);
        Scaleform::Render::StrokerAA::calcJoinParam(v5, v41, v41 + 1, v41 + 2, &w, &p);
        v48 = v39 - 2;
        v49 = 1i64;
        if ( v48 > 1 )
        {
          v50 = 2i64;
          do
          {
            v51 = v5->Path.Path.Pages;
            v52 = &v51[v49 >> 4][v49 & 0xF];
            Scaleform::Render::StrokerAA::calcJoinParam(
              v5,
              v52,
              &v51[v50 >> 4][v50 & 0xF],
              &v51[(v50 + 1) >> 4][((_DWORD)v50 + 1) & 0xF],
              &w,
              &p);
            v53 = v5->LineJoin;
            if ( v53 >= 0 )
            {
              if ( v53 <= 1 )
              {
                Scaleform::Render::StrokerAA::calcMiterJoin(v5, v52, &w, &p, v5->LineJoin);
              }
              else if ( v53 == 2 )
              {
                Scaleform::Render::StrokerAA::calcRoundJoin(v5, v52, &w, &p);
              }
              else if ( v53 == 3 )
              {
                Scaleform::Render::StrokerAA::calcBevelJoin(v5, v52, &w, &p, BevelJoin);
              }
            }
            ++v49;
            ++v50;
          }
          while ( v49 < v48 );
        }
        v54 = v5->Path.Path.Pages;
        v55 = v54[v48 >> 4];
        v56 = v54[(v48 + 1) >> 4];
        v57 = v54[v49 >> 4];
        v3.x = (float)(v56[((_DWORD)v48 + 1) & 0xF].x * 2.0) - v55[v48 & 0xF].x;
        v58 = v49 + 1;
        v59 = &v57[v49 & 0xF];
        v60 = v54[v58 >> 4];
        v3.y = (float)(v56[((_DWORD)v48 + 1) & 0xF].y * 2.0) - v55[v48 & 0xF].y;
        v3.dist = v55[v48 & 0xF].dist;
        Scaleform::Render::StrokerAA::calcJoinParam(v5, v59, &v60[v58 & 0xF], &v3, &w, &p);
        v61 = v5->LineJoin;
        if ( v61 >= 0 )
        {
          if ( v61 <= 1 )
          {
            Scaleform::Render::StrokerAA::calcMiterJoin(v5, v59, &w, &p, v5->LineJoin);
          }
          else if ( v61 == 2 )
          {
            Scaleform::Render::StrokerAA::calcRoundJoin(v5, v59, &w, &p);
          }
          else if ( v61 == 3 )
          {
            Scaleform::Render::StrokerAA::calcBevelJoin(v5, v59, &w, &p, BevelJoin);
          }
        }
      }
      v62 = v5->Path.Path.Size;
      Scaleform::Render::StrokerAA::calcButtJoin(
        v5,
        &v5->Path.Path.Pages[(v62 - 2) >> 4][((_BYTE)v62 - 2) & 0xF],
        &v5->Path.Path.Pages[(v62 - 1) >> 4][((_DWORD)v62 - 1) & 0xF],
        v5->Path.Path.Pages[(v62 - 2) >> 4][((_BYTE)v62 - 2) & 0xF].dist,
        &w);
      v63 = v5->Path.Path.Size;
      v64 = v5->Path.Path.Pages;
      v65 = v64[(v63 - 2) >> 4][((_BYTE)v63 - 2) & 0xF].dist;
      v66 = &v64[(v63 - 2) >> 4][((_DWORD)v63 - 2) & 0xF];
      v67 = &v64[(v63 - 1) >> 4][((_DWORD)v63 - 1) & 0xF];
      v68 = v5->EndLineCap;
      if ( v68 >= 0 )
      {
        if ( v68 <= 1 )
        {
          Scaleform::Render::StrokerAA::calcButtCap(v5, v67, v66, v65, &w, 1);
        }
        else if ( v68 == 2 )
        {
          Scaleform::Render::StrokerAA::calcRoundCap(v5, v67, v66, v65, &w, 1);
        }
      }
    }
  }
  else
  {
    v7 = v5->Path.Path.Size;
    if ( v7 > 2 )
    {
      v8 = v5->Path.Path.Pages;
      v9 = *v8;
      Scaleform::Render::StrokerAA::calcJoinParam(
        v5,
        &v8[(v7 - 2) >> 4][((_DWORD)v7 - 2) & 0xF],
        &v8[(v7 - 1) >> 4][((_BYTE)v7 - 1) & 0xF],
        *v8,
        &w,
        &p);
      Scaleform::Render::StrokerAA::calcJoinParam(v5, &v8[(v7 - 1) >> 4][((_DWORD)v7 - 1) & 0xF], v9, v9 + 1, &w, &p);
      v10 = v5->Triangles.Size;
      if ( v7 )
      {
        v11 = 1i64;
        do
        {
          v12 = v5->Path.Path.Size;
          v13 = v11 + 1;
          v14 = v11 + 1;
          if ( v11 + 1 >= v12 )
            v14 -= v12;
          v15 = v11;
          if ( v11 >= v12 )
            v15 = v11 - v12;
          v16 = &v5->Path.Path.Pages[(v11 - 1) >> 4][((_DWORD)v11 - 1) & 0xF];
          Scaleform::Render::StrokerAA::calcJoinParam(
            v5,
            v16,
            &v5->Path.Path.Pages[v15 >> 4][v15 & 0xF],
            &v5->Path.Path.Pages[v14 >> 4][v14 & 0xF],
            &w,
            &p);
          v17 = v5->LineJoin;
          if ( v17 >= 0 )
          {
            if ( v17 <= 1 )
            {
              Scaleform::Render::StrokerAA::calcMiterJoin(v5, v16, &w, &p, v5->LineJoin);
            }
            else if ( v17 == 2 )
            {
              Scaleform::Render::StrokerAA::calcRoundJoin(v5, v16, &w, &p);
            }
            else if ( v17 == 3 )
            {
              Scaleform::Render::StrokerAA::calcBevelJoin(v5, v16, &w, &p, BevelJoin);
            }
          }
          v11 = v13;
        }
        while ( v13 - 1 < v5->Path.Path.Size );
      }
      v18 = -(signed __int64)v10;
      do
      {
        if ( v10 >= v5->Triangles.Size )
          break;
        v19 = v10 & 0xF;
        v20 = v5->Triangles.Pages[v10 >> 4];
        if ( v20[v19].v1 == -4 )
          v20[v19].v1 = v5->SolidL;
        if ( v20[v19].v1 == -3 )
          v20[v19].v1 = v5->SolidR;
        if ( v20[v19].v1 == -2 )
          v20[v19].v1 = v5->TotalL;
        if ( v20[v19].v1 == -1 )
          v20[v19].v1 = v5->TotalR;
        if ( v20[v19].v2 == -4 )
          v20[v19].v2 = v5->SolidL;
        if ( v20[v19].v2 == -3 )
          v20[v19].v2 = v5->SolidR;
        if ( v20[v19].v2 == -2 )
          v20[v19].v2 = v5->TotalL;
        if ( v20[v19].v2 == -1 )
          v20[v19].v2 = v5->TotalR;
        if ( v20[v19].v3 == -4 )
          v20[v19].v3 = v5->SolidL;
        if ( v20[v19].v3 == -3 )
          v20[v19].v3 = v5->SolidR;
        if ( v20[v19].v3 == -2 )
          v20[v19].v3 = v5->TotalL;
        if ( v20[v19].v3 == -1 )
          v20[v19].v3 = v5->TotalR;
        ++v10;
      }
      while ( v18 + v10 < 6 );
    }
  }
  v5->Path.Path.Size = 0i64;
  v5->Closed = 0;
}   v20[v19].v3 = v5->SolidL;
        if ( v20[v19].v3 == -3 )
          v20[v19].v3 = v5->SolidR;
        if ( v20[v19].v3 == -2 )
          v20[v19].v3 = v5->TotalL;
        if ( v20[v19].v3 == -1 )
          v20[v19].v3 = v5->TotalR;
        ++v10;
      }
      while ( v18 + v10 < 6 );
    }


// File Line: 1424
// RVA: 0x9BA780
void __fastcall Scaleform::Render::StrokerAA::Transform(Scaleform::Render::StrokerAA *this, Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v2; // r10
  signed __int64 v3; // r9
  Scaleform::Render::StrokerAA::VertexType *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v2 = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  if ( this->Vertices.Size )
  {
    do
    {
      v3 = v2 & 0xF;
      v4 = this->Vertices.Pages[v2 >> 4];
      v5 = v4[v2 & 0xF].x;
      v6 = v4[v2 & 0xF].y;
      v4[v3].x = (float)((float)(v4[v2 & 0xF].x * m->M[0][0]) + (float)(v4[v2 & 0xF].y * m->M[0][1])) + m->M[0][3];
      v4[v3].y = (float)((float)(v6 * m->M[1][1]) + (float)(v5 * m->M[1][0])) + m->M[1][3];
      v7 = v4[v2 & 0xF].x;
      if ( v7 < this->MinX )
        this->MinX = v7;
      v8 = v4[v2 & 0xF].y;
      if ( v8 < this->MinY )
        this->MinY = v8;
      v9 = v4[v2 & 0xF].x;
      if ( v9 > this->MaxX )
        this->MaxX = v9;
      v10 = v4[v2 & 0xF].y;
      if ( v10 > this->MaxY )
        this->MaxY = v10;
      ++v2;
    }
    while ( v2 < this->Vertices.Size );
  }
}

// File Line: 1444
// RVA: 0x9B7F50
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::StrokerAA::StretchTo(Scaleform::Render::StrokerAA *this, Scaleform::Render::Matrix2x4<float> *result, float x1, float y1, float x2, float y2)
{
  unsigned __int64 v6; // rsi
  int v7; // xmm7_4
  float v8; // xmm8_4
  Scaleform::Render::Matrix2x4<float> *v9; // rbx
  Scaleform::Render::StrokerAA *v10; // rdi
  unsigned __int64 v11; // r9
  unsigned __int64 v12; // r8
  float v13; // xmm3_4
  Scaleform::Render::StrokerAA::VertexType **v14; // r10
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  Scaleform::Render::StrokerAA::VertexType *v18; // rax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  int v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  signed __int64 v25; // rax
  unsigned __int64 v26; // rdx
  signed __int64 v27; // r8
  Scaleform::Render::StrokerAA::VertexType *v28; // rax
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  int v32; // xmm0_4
  int v33; // xmm1_4
  int v34; // xmm0_4
  int v35; // xmm1_4
  int v36; // xmm0_4
  int v37; // xmm1_4
  float dst; // [rsp+20h] [rbp-29h]
  int v40; // [rsp+24h] [rbp-25h]
  float v41; // [rsp+28h] [rbp-21h]
  int v42; // [rsp+2Ch] [rbp-1Dh]
  float v43; // [rsp+30h] [rbp-19h]
  float v44; // [rsp+34h] [rbp-15h]
  float src; // [rsp+40h] [rbp-9h]
  float v46; // [rsp+44h] [rbp-5h]
  int v47; // [rsp+48h] [rbp-1h]
  float v48; // [rsp+4Ch] [rbp+3h]
  int v49; // [rsp+50h] [rbp+7h]
  float v50; // [rsp+54h] [rbp+Bh]
  int v51; // [rsp+58h] [rbp+Fh]
  int v52; // [rsp+5Ch] [rbp+13h]

  v6 = 0i64;
  *(_QWORD *)&result->M[0][0] = 1065353216i64;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  *(_QWORD *)&result->M[0][2] = 0i64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  v7 = LODWORD(y1);
  v8 = x1;
  v9 = result;
  v10 = this;
  if ( this->MaxX <= this->MinX || this->MaxY <= this->MinY )
  {
    v11 = this->Vertices.Size;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    v12 = 0i64;
    if ( v11 )
    {
      v13 = FLOAT_N1_0e30;
      v14 = this->Vertices.Pages;
      v15 = FLOAT_1_0e30;
      v16 = FLOAT_N1_0e30;
      v17 = FLOAT_1_0e30;
      do
      {
        v18 = v14[v12 >> 4];
        v19 = v18[v12 & 0xF].x;
        v20 = v18[v12 & 0xF].y;
        v41 = *(float *)&v18[v12 & 0xF].style;
        if ( v19 < v15 )
        {
          this->MinX = v19;
          v15 = v19;
        }
        if ( v20 < v17 )
        {
          this->MinY = v20;
          v17 = v20;
        }
        if ( v19 > v13 )
        {
          this->MaxX = v19;
          v13 = v19;
        }
        if ( v20 > v16 )
        {
          this->MaxY = v20;
          v16 = v20;
        }
        ++v12;
      }
      while ( v12 < v11 );
    }
  }
  v21 = this->MinX;
  v22 = SLODWORD(this->MaxX);
  if ( v21 < *(float *)&v22 )
  {
    v23 = this->MinY;
    v24 = this->MaxY;
    if ( v23 < v24 )
    {
      v46 = this->MinY;
      v48 = v23;
      v41 = x2;
      v43 = x2;
      v44 = y2;
      src = v21;
      v47 = v22;
      v49 = v22;
      v50 = v24;
      dst = v8;
      v40 = v7;
      v42 = v7;
      Scaleform::Render::Matrix2x4<float>::SetParlToParl(result, &src, &dst);
      if ( v10->Vertices.Size > 0 )
      {
        do
        {
          v25 = v6 & 0xF;
          v26 = v6++ >> 4;
          v27 = v25;
          v28 = v10->Vertices.Pages[v26];
          v29 = v28[v27].x;
          v30 = v28[v27].y;
          v28[v27].x = (float)((float)(v28[v27].x * v9->M[0][0]) + (float)(v28[v27].y * v9->M[0][1])) + v9->M[0][3];
          v28[v27].y = (float)((float)(v29 * v9->M[1][0]) + (float)(v30 * v9->M[1][1])) + v9->M[1][3];
        }
        while ( v6 < v10->Vertices.Size );
      }
      v31 = v9->M[0][1];
      src = v9->M[0][0];
      v32 = LODWORD(v9->M[0][2]);
      v46 = v31;
      v33 = LODWORD(v9->M[0][3]);
      v47 = v32;
      v34 = LODWORD(v9->M[1][0]);
      v48 = *(float *)&v33;
      v35 = LODWORD(v9->M[1][1]);
      v49 = v34;
      v36 = LODWORD(v9->M[1][2]);
      v50 = *(float *)&v35;
      v37 = LODWORD(v9->M[1][3]);
      v51 = v36;
      v52 = v37;
      Scaleform::Render::Matrix2x4<float>::SetInverse(v9, (Scaleform::Render::Matrix2x4<float> *)&src);
    }
  }
  return v9;
}

// File Line: 1479
// RVA: 0x989220
void __fastcall Scaleform::Render::StrokerAA::GetMesh(Scaleform::Render::StrokerAA *this, unsigned int __formal, Scaleform::Render::TessMesh *mesh)
{
  *(_QWORD *)&mesh->Style1 = 1i64;
  mesh->MeshIdx = 0;
  *(_QWORD *)&mesh->Flags1 = 0i64;
  mesh->StartVertex = 0;
  mesh->VertexCount = this->Vertices.Size;
}

// File Line: 1491
// RVA: 0x98EFD0
__int64 __fastcall Scaleform::Render::StrokerAA::GetVertices(Scaleform::Render::StrokerAA *this, Scaleform::Render::TessMesh *mesh, Scaleform::Render::TessVertex *vertices, unsigned int num)
{
  Scaleform::Render::TessVertex *v4; // r11
  Scaleform::Render::TessMesh *v5; // rbx
  unsigned int v6; // er10
  unsigned __int64 v7; // rdx
  signed __int64 v8; // r8
  Scaleform::Render::StrokerAA::VertexType *v9; // rdx
  float v10; // eax
  unsigned __int64 v11; // rdx
  signed __int64 v12; // r8
  Scaleform::Render::StrokerAA::VertexType *v13; // rdx
  float v14; // eax
  unsigned __int64 v15; // rdx
  signed __int64 v16; // r8
  Scaleform::Render::StrokerAA::VertexType *v17; // rdx
  float v18; // eax
  unsigned __int64 v19; // rdx
  signed __int64 v20; // r8
  Scaleform::Render::StrokerAA::VertexType *v21; // rdx
  float v22; // eax
  signed __int64 v23; // r11
  unsigned __int64 v24; // rdx
  signed __int64 v25; // r8
  Scaleform::Render::StrokerAA::VertexType *v26; // rdx
  float v27; // eax

  v4 = vertices;
  v5 = mesh;
  v6 = 0;
  if ( (signed int)num < 4 )
  {
LABEL_7:
    if ( v6 < num )
    {
      v23 = (signed __int64)&v4->Idx;
      do
      {
        v24 = v5->StartVertex;
        if ( v24 >= this->Vertices.Size )
          break;
        v25 = v24 & 0xF;
        v26 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v24 >> 4];
        *(float *)(v23 - 8) = v26[v25].x;
        v27 = v26[v25].y;
        *(_DWORD *)v23 = 0;
        *(float *)(v23 - 4) = v27;
        LOWORD(v27) = v26[v25].style;
        *(_WORD *)(v23 + 6) = 0;
        *(_WORD *)(v23 + 4) = LOWORD(v27);
        ++v6;
        v23 += 20i64;
        *(_WORD *)(v23 - 12) = v26[v25].alpha != 0 ? 2 : 0;
        ++v5->StartVertex;
      }
      while ( v6 < num );
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = v5->StartVertex;
      if ( v7 >= this->Vertices.Size )
        break;
      v8 = v7 & 0xF;
      v9 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v7 >> 4];
      v4->x = v9[v8].x;
      v10 = v9[v8].y;
      v4->Idx = 0;
      v4->y = v10;
      LOWORD(v10) = v9[v8].style;
      v4->Styles[1] = 0;
      v4->Styles[0] = LOWORD(v10);
      v4->Flags = v9[v8].alpha != 0 ? 2 : 0;
      v11 = ++v5->StartVertex;
      if ( v11 >= this->Vertices.Size )
        return v6 + 1;
      v12 = v11 & 0xF;
      v13 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v11 >> 4];
      v4[1].x = v13[v12].x;
      v14 = v13[v12].y;
      v4[1].Idx = 0;
      v4[1].y = v14;
      LOWORD(v14) = v13[v12].style;
      v4[1].Styles[1] = 0;
      v4[1].Styles[0] = LOWORD(v14);
      v4[1].Flags = v13[v12].alpha != 0 ? 2 : 0;
      v15 = ++v5->StartVertex;
      if ( v15 >= this->Vertices.Size )
        return v6 + 2;
      v16 = v15 & 0xF;
      v17 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v15 >> 4];
      v4[2].x = v17[v16].x;
      v18 = v17[v16].y;
      v4[2].Idx = 0;
      v4[2].y = v18;
      LOWORD(v18) = v17[v16].style;
      v4[2].Styles[1] = 0;
      v4[2].Styles[0] = LOWORD(v18);
      v4[2].Flags = v17[v16].alpha != 0 ? 2 : 0;
      v19 = ++v5->StartVertex;
      if ( v19 >= this->Vertices.Size )
        return v6 + 3;
      v20 = v19 & 0xF;
      v21 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v19 >> 4];
      v4[3].x = v21[v20].x;
      v22 = v21[v20].y;
      v4[3].Idx = 0;
      v4[3].y = v22;
      LOWORD(v22) = v21[v20].style;
      v4[3].Styles[1] = 0;
      v4[3].Styles[0] = LOWORD(v22);
      v6 += 4;
      v4 += 4;
      v4[-1].Flags = v21[v20].alpha != 0 ? 2 : 0;
      ++v5->StartVertex;
      if ( v6 >= num - 3 )
        goto LABEL_7;
    }
  }
  return v6;
}

// File Line: 1510
// RVA: 0x98E010
void __fastcall Scaleform::Render::StrokerAA::GetTrianglesI16(Scaleform::Render::StrokerAA *this, unsigned int __formal, unsigned __int16 *idx, unsigned int start, unsigned int num)
{
  unsigned int v5; // er10
  unsigned int v6; // eax
  unsigned __int16 *v7; // rdx

  v5 = 0;
  if ( num )
  {
    do
    {
      v6 = v5++ + start;
      idx += 3;
      v7 = (unsigned __int16 *)&this->Triangles.Pages[(unsigned __int64)v6 >> 4][v6 & 0xF];
      *(idx - 3) = *v7;
      *(idx - 2) = v7[2];
      *(idx - 1) = v7[4];
    }
    while ( v5 < num );
  }
}

