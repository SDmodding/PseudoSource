// File Line: 50
// RVA: 0x9451D0
void __fastcall Scaleform::Render::StrokerAA::StrokerAA(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::LinearHeap *heap)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::StrokerAA::`vftable;
  this->LineJoin = RoundJoin;
  this->StartLineCap = RoundCap;
  this->EndLineCap = RoundCap;
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
  Scaleform::Render::StrokePath::ClosePath(&this->Path);
  this->Closed = 1;
}

// File Line: 87
// RVA: 0x9D0D40
void __fastcall Scaleform::Render::StrokerAA::calcButtCap(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v0,
        Scaleform::Render::StrokeVertex *v1,
        float len,
        Scaleform::Render::StrokerAA::WidthsType *w,
        bool endFlag)
{
  float solidWidthR; // xmm1_4
  float solidWidthL; // xmm4_4
  float totalWidthR; // xmm5_4
  float totalWidthL; // xmm6_4
  float y; // xmm2_4
  bool aaFlagR; // cl
  bool aaFlagL; // al
  unsigned int v16; // ebp
  unsigned int v17; // r14d
  unsigned int v18; // r13d
  unsigned int v19; // r15d
  float v20; // xmm14_4
  float v21; // xmm8_4
  float v22; // xmm12_4
  float v23; // xmm10_4
  float v24; // xmm11_4
  float v25; // xmm9_4
  float v26; // xmm15_4
  float v27; // xmm13_4
  float v28; // xmm11_4
  float v29; // xmm14_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int TotalL; // ecx
  unsigned int SolidL; // ecx
  bool v37; // [rsp+118h] [rbp+20h]
  bool wa; // [rsp+120h] [rbp+28h]

  if ( endFlag )
  {
    solidWidthR = w->solidWidthR;
    solidWidthL = w->solidWidthL;
    totalWidthR = w->totalWidthR;
    totalWidthL = w->totalWidthL;
  }
  else
  {
    solidWidthR = w->solidWidthL;
    solidWidthL = w->solidWidthR;
    totalWidthR = w->totalWidthL;
    totalWidthL = w->totalWidthR;
  }
  y = v0->y;
  aaFlagR = w->aaFlagR;
  aaFlagL = w->aaFlagL;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = (float)(v1->y - y) * (float)(1.0 / len);
  v21 = v20 * totalWidthL;
  v22 = v20 * solidWidthR;
  v23 = v20 * solidWidthL;
  v24 = (float)(v0->x - v1->x) * (float)(1.0 / len);
  v25 = v24 * totalWidthL;
  v26 = v24 * totalWidthR;
  v27 = v24 * solidWidthR;
  v28 = v24 * solidWidthL;
  v29 = v20 * totalWidthR;
  v30 = (float)((float)(v25 - v28) + (float)(v26 - v27)) * 0.5;
  v31 = (float)((float)(v23 - v21) + (float)(v22 - v29)) * 0.5;
  if ( endFlag )
  {
    v37 = w->aaFlagR;
    wa = w->aaFlagL;
  }
  else
  {
    v37 = w->aaFlagL;
    wa = w->aaFlagR;
  }
  if ( aaFlagL || aaFlagR )
  {
    v32 = Scaleform::Render::StrokerAA::addVertex(
            this,
            (float)(v0->x - v22) + v30,
            (float)(y - v27) + v31,
            this->StyleLeft,
            0);
    v17 = v32;
    if ( w->solidFlag )
      v32 = Scaleform::Render::StrokerAA::addVertex(
              this,
              (float)(v23 + v0->x) + v30,
              (float)(v28 + v0->y) + v31,
              this->StyleRight,
              0);
    v16 = v32;
    if ( v37 )
      v18 = Scaleform::Render::StrokerAA::addVertex(
              this,
              (float)(v0->x - v29) + v30,
              (float)(v0->y - v26) + v31,
              this->StyleLeft,
              0);
    else
      v18 = v17;
    if ( wa )
      v19 = Scaleform::Render::StrokerAA::addVertex(
              this,
              (float)(v21 + v0->x) + v30,
              (float)(v25 + v0->y) + v31,
              this->StyleRight,
              0);
    else
      v19 = v16;
  }
  if ( endFlag )
  {
    TotalL = this->TotalL;
    this->TotalL = this->TotalR;
    this->TotalR = TotalL;
    SolidL = this->SolidL;
    this->SolidL = this->SolidR;
    this->SolidR = SolidL;
  }
  else
  {
    v33 = Scaleform::Render::StrokerAA::addVertex(this, v0->x - v22, v0->y - v27, this->StyleLeft, 1);
    this->SolidL = v33;
    if ( w->aaFlagL )
      v33 = Scaleform::Render::StrokerAA::addVertex(this, v0->x - v29, v0->y - v26, this->StyleLeft, 0);
    this->TotalL = v33;
    if ( w->solidFlag )
      v34 = Scaleform::Render::StrokerAA::addVertex(this, v23 + v0->x, v28 + v0->y, this->StyleRight, 1);
    else
      v34 = this->SolidL;
    this->SolidR = v34;
    if ( w->aaFlagR )
      v34 = Scaleform::Render::StrokerAA::addVertex(this, v21 + v0->x, v25 + v0->y, this->StyleRight, 0);
    this->TotalR = v34;
  }
  if ( (w->aaFlagL || w->aaFlagR) && (w->solidFlagL || w->solidFlagR) )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, v17, v16, this->SolidL);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v16, this->SolidR);
  }
  if ( v37 )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->TotalL, v18);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v18, v17);
  }
  if ( wa )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v19, this->TotalR);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v16, v19);
  }
}

// File Line: 163
// RVA: 0x9D4800
void __fastcall Scaleform::Render::StrokerAA::calcRoundCap(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v0,
        Scaleform::Render::StrokeVertex *v1,
        float len,
        Scaleform::Render::StrokerAA::WidthsType *w,
        bool endFlag)
{
  bool v6; // r14
  float solidWidthR; // xmm1_4
  float solidWidthL; // xmm2_4
  float totalWidthR; // xmm4_4
  float totalWidthL; // xmm5_4
  float x; // xmm7_4
  float y; // xmm6_4
  float v16; // xmm13_4
  float v17; // xmm0_4
  float v18; // xmm11_4
  float v19; // xmm9_4
  float v20; // xmm14_4
  float v21; // xmm10_4
  float v22; // xmm8_4
  float v23; // xmm15_4
  float v24; // xmm13_4
  float v25; // xmm12_4
  int v26; // ebp
  float v27; // xmm12_4
  unsigned int TotalR; // eax
  float v29; // xmm14_4
  float v30; // xmm9_4
  float v31; // xmm13_4
  float v32; // xmm15_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  float totalWidth; // xmm8_4
  float v36; // xmm7_4
  float v37; // xmm8_4
  unsigned int StyleLeft; // r9d
  unsigned int SolidL; // ebp
  unsigned int v40; // r15d
  unsigned int StyleRight; // r9d
  unsigned int v42; // r12d
  unsigned int SolidR; // r13d
  unsigned __int64 v44; // r14
  __int64 v45; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v46; // rax
  unsigned int v47; // r12d
  unsigned int TotalL; // r13d
  unsigned __int64 v49; // r14
  __int64 v50; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v51; // rax
  unsigned int v52; // r12d
  unsigned __int64 v53; // r14
  __int64 v54; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v55; // rax
  unsigned int v56; // r12d
  unsigned int v57; // r13d
  unsigned __int64 v58; // r14
  __int64 v59; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v60; // rax
  unsigned int v61; // r12d
  unsigned int v62; // r13d
  unsigned __int64 v63; // r14
  __int64 v64; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v65; // rax
  unsigned int v66; // r12d
  unsigned __int64 v67; // r14
  __int64 v68; // rdx
  Scaleform::Render::StrokerAA::TriangleType *v69; // rax
  bool v70; // zf
  float v71; // [rsp+118h] [rbp+20h]
  float v72; // [rsp+118h] [rbp+20h]
  float wa; // [rsp+120h] [rbp+28h]
  Scaleform::Render::StrokerAA::WidthsType *wb; // [rsp+120h] [rbp+28h]

  v6 = endFlag;
  if ( endFlag )
  {
    solidWidthR = w->solidWidthR;
    solidWidthL = w->solidWidthL;
    totalWidthR = w->totalWidthR;
    totalWidthL = w->totalWidthL;
  }
  else
  {
    solidWidthR = w->solidWidthL;
    solidWidthL = w->solidWidthR;
    totalWidthR = w->totalWidthL;
    totalWidthL = w->totalWidthR;
  }
  x = v0->x;
  y = v0->y;
  v16 = (float)(v1->y - y) * (float)(1.0 / len);
  v17 = (float)(v0->x - v1->x) * (float)(1.0 / len);
  v18 = v17 * solidWidthR;
  v19 = v17 * totalWidthR;
  v20 = v17 * totalWidthL;
  v21 = v16 * solidWidthR;
  v22 = v16 * totalWidthR;
  wa = v17 * solidWidthL;
  v23 = v16 * solidWidthL;
  v24 = v16 * totalWidthL;
  v25 = atan2f(COERCE_FLOAT(COERCE_UNSIGNED_INT(v17 * totalWidthR) ^ _xmm[0]), COERCE_FLOAT(LODWORD(v22) ^ _xmm[0]));
  v71 = (float)(v25 + 3.1415927) - v25;
  v26 = (int)(float)(v71 / (float)(acosf(w->totalWidth / (float)((float)(this->Tolerance * 0.25) + w->totalWidth)) * 2.0))
      + 1;
  v72 = v71 / (float)v26;
  v27 = v25 + v72;
  if ( endFlag )
  {
    this->SolidL = this->SolidR;
    TotalR = this->TotalR;
  }
  else
  {
    TotalR = Scaleform::Render::StrokerAA::addVertex(this, x - v21, y - v18, this->StyleLeft, 1);
    this->SolidR = TotalR;
    this->SolidL = TotalR;
    if ( w->aaFlagL || w->aaFlagR )
      TotalR = Scaleform::Render::StrokerAA::addVertex(this, v0->x - v22, v0->y - v19, this->StyleLeft, 0);
    this->TotalR = TotalR;
  }
  this->TotalL = TotalR;
  v29 = (float)((float)(v20 - v19) * 0.5) + v0->y;
  v30 = (float)((float)(wa - v18) * 0.5) + v0->y;
  v31 = (float)((float)(v24 - v22) * 0.5) + v0->x;
  v32 = (float)((float)(v23 - v21) * 0.5) + v0->x;
  if ( v26 > 0 )
  {
    wb = (Scaleform::Render::StrokerAA::WidthsType *)(unsigned int)v26;
    do
    {
      v33 = cosf(v27);
      v34 = sinf(v27);
      totalWidth = w->totalWidth;
      v36 = (float)(totalWidth * v34) + v29;
      v37 = (float)(totalWidth * v33) + v31;
      if ( w->solidFlag )
      {
        if ( v6 )
          StyleLeft = this->StyleLeft;
        else
          StyleLeft = this->StyleRight;
        SolidL = Scaleform::Render::StrokerAA::addVertex(
                   this,
                   (float)(w->solidWidth * v33) + v32,
                   (float)(w->solidWidth * v34) + v30,
                   StyleLeft,
                   1);
      }
      else
      {
        SolidL = this->SolidL;
      }
      if ( w->aaFlagL || w->aaFlagR )
      {
        if ( v6 )
          StyleRight = this->StyleLeft;
        else
          StyleRight = this->StyleRight;
        v40 = Scaleform::Render::StrokerAA::addVertex(this, v37, v36, StyleRight, 0);
      }
      else
      {
        v40 = SolidL;
      }
      if ( v6 )
      {
        if ( w->solidFlagL || w->solidFlagR )
        {
          v42 = this->SolidL;
          SolidR = this->SolidR;
          v44 = this->Triangles.Size >> 4;
          if ( v44 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v45 = this->Triangles.Size & 0xF;
          v46 = this->Triangles.Pages[v44];
          v46[v45].v1 = v42;
          v46[v45].v2 = SolidL;
          v46[v45].v3 = SolidR;
          ++this->Triangles.Size;
        }
        if ( w->aaFlagL || w->aaFlagR )
        {
          v47 = this->SolidL;
          TotalL = this->TotalL;
          v49 = this->Triangles.Size >> 4;
          if ( v49 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v50 = this->Triangles.Size & 0xF;
          v51 = this->Triangles.Pages[v49];
          v51[v50].v1 = v47;
          v51[v50].v2 = TotalL;
          v51[v50].v3 = v40;
          ++this->Triangles.Size;
          v52 = this->SolidL;
          v53 = this->Triangles.Size >> 4;
          if ( v53 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v54 = this->Triangles.Size & 0xF;
          v55 = this->Triangles.Pages[v53];
          v55[v54].v1 = v52;
          v55[v54].v2 = v40;
          v55[v54].v3 = SolidL;
          ++this->Triangles.Size;
        }
        this->SolidL = SolidL;
        this->TotalL = v40;
      }
      else
      {
        if ( w->solidFlagL || w->solidFlagR )
        {
          v56 = this->SolidL;
          v57 = this->SolidR;
          v58 = this->Triangles.Size >> 4;
          if ( v58 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v59 = this->Triangles.Size & 0xF;
          v60 = this->Triangles.Pages[v58];
          v60[v59].v1 = v56;
          v60[v59].v2 = v57;
          v60[v59].v3 = SolidL;
          ++this->Triangles.Size;
        }
        if ( w->aaFlagL || w->aaFlagR )
        {
          v61 = this->SolidR;
          v62 = this->TotalR;
          v63 = this->Triangles.Size >> 4;
          if ( v63 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v64 = this->Triangles.Size & 0xF;
          v65 = this->Triangles.Pages[v63];
          v65[v64].v1 = v61;
          v65[v64].v2 = v62;
          v65[v64].v3 = v40;
          ++this->Triangles.Size;
          v66 = this->SolidR;
          v67 = this->Triangles.Size >> 4;
          if ( v67 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v68 = this->Triangles.Size & 0xF;
          v69 = this->Triangles.Pages[v67];
          v69[v68].v1 = v66;
          v69[v68].v2 = v40;
          v69[v68].v3 = SolidL;
          ++this->Triangles.Size;
        }
        this->SolidR = SolidL;
        this->TotalR = v40;
      }
      v70 = wb == (Scaleform::Render::StrokerAA::WidthsType *)1;
      wb = (Scaleform::Render::StrokerAA::WidthsType *)((char *)wb - 1);
      v6 = endFlag;
      v27 = v27 + v72;
    }
    while ( !v70 );
  }
}

// File Line: 282
// RVA: 0x9D4E00
void __fastcall Scaleform::Render::StrokerAA::calcRoundJoin(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v1,
        Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p)
{
  bool v4; // r12
  float v5; // xmm0_4
  float xMiterThisR; // xmm6_4
  float yMiterThisR; // xmm7_4
  float y; // xmm2_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  unsigned int v15; // eax
  unsigned int v16; // ebp
  unsigned int v17; // r15d
  unsigned int v18; // r13d
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
  float xMiterThisL; // xmm6_4
  float yMiterThisL; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm8_4
  float v33; // xmm9_4
  unsigned int v34; // eax
  unsigned int v35; // ebp
  unsigned int v36; // r15d
  unsigned int v37; // r13d
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
      xMiterThisR = p->dx1TotalR + v1->x;
      yMiterThisR = p->dy1TotalR + v1->y;
    }
    else
    {
      xMiterThisR = p->xMiterThisR;
      yMiterThisR = p->yMiterThisR;
    }
    y = v1->y;
    v13 = (float)((float)(xMiterThisR - v1->x) * w->solidCoeffR) + v1->x;
    v14 = (float)((float)(yMiterThisR - y) * w->solidCoeffR) + y;
    v15 = Scaleform::Render::StrokerAA::addVertex(this, v1->x - p->dx1SolidL, y - p->dy1SolidL, this->StyleLeft, 1);
    v16 = v15;
    if ( w->aaFlagL )
      v15 = Scaleform::Render::StrokerAA::addVertex(
              this,
              v1->x - p->dx1TotalL,
              v1->y - p->dy1TotalL,
              this->StyleLeft,
              0);
    v3 = v15;
    if ( w->solidFlag )
      v17 = Scaleform::Render::StrokerAA::addVertex(this, v13, v14, this->StyleRight, 1);
    else
      v17 = v16;
    if ( w->aaFlagR )
      v18 = Scaleform::Render::StrokerAA::addVertex(this, xMiterThisR, yMiterThisR, this->StyleRight, 0);
    else
      v18 = v17;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v17, v16);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v17);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v16);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v16, v3);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v18, v17);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v18);
    }
    this->SolidL = v16;
    this->SolidR = v17;
    this->TotalR = v18;
    this->TotalL = v3;
    if ( v4 )
    {
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(
                       this,
                       p->dx2SolidR + v1->x,
                       p->dy2SolidR + v1->y,
                       this->StyleRight,
                       1);
      if ( w->aaFlagR )
        v17 = Scaleform::Render::StrokerAA::addVertex(
                this,
                p->dx2TotalR + v1->x,
                p->dy2TotalR + v1->y,
                this->StyleRight,
                0);
      this->TotalR = v17;
    }
    v19 = atan2f(COERCE_FLOAT(LODWORD(p->dy1TotalL) ^ _xmm[0]), COERCE_FLOAT(LODWORD(p->dx1TotalL) ^ _xmm[0]));
    v20 = atan2f(COERCE_FLOAT(LODWORD(p->dy2TotalL) ^ _xmm[0]), COERCE_FLOAT(LODWORD(p->dx2TotalL) ^ _xmm[0]));
    if ( v19 < v20 )
      v20 = v20 + -6.2831855;
    v21 = v19 - v20;
    v22 = (int)(float)((float)(v19 - v20)
                     / (float)(acosf(w->totalWidthL / (float)((float)(this->Tolerance * 0.25) + w->totalWidthL)) * 2.0))
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
        if ( w->solidFlag )
          v16 = Scaleform::Render::StrokerAA::addVertex(
                  this,
                  (float)(v26 * w->solidWidthL) + v1->x,
                  (float)(v27 * w->solidWidthL) + v1->y,
                  this->StyleLeft,
                  1);
        if ( w->aaFlagL )
          v28 = Scaleform::Render::StrokerAA::addVertex(
                  this,
                  (float)(w->totalWidthL * v26) + v1->x,
                  (float)(w->totalWidthL * v27) + v1->y,
                  this->StyleLeft,
                  0);
        else
          v28 = v16;
        if ( w->solidFlagL )
          Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v16, this->SolidL);
        if ( w->aaFlagL )
        {
          Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v16, this->TotalL);
          Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v16, v28);
        }
        this->SolidL = v16;
        this->TotalL = v28;
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
      xMiterThisL = v1->x - p->dx1TotalL;
      yMiterThisL = v1->y - p->dy1TotalL;
    }
    else
    {
      xMiterThisL = p->xMiterThisL;
      yMiterThisL = p->yMiterThisL;
    }
    v31 = v1->y;
    v32 = (float)((float)(xMiterThisL - v1->x) * w->solidCoeffL) + v1->x;
    v33 = (float)((float)(yMiterThisL - v31) * w->solidCoeffL) + v31;
    v34 = Scaleform::Render::StrokerAA::addVertex(this, v1->x + p->dx1SolidR, v31 + p->dy1SolidR, this->StyleRight, 1);
    v35 = v34;
    if ( w->aaFlagR )
      v34 = Scaleform::Render::StrokerAA::addVertex(
              this,
              p->dx1TotalR + v1->x,
              p->dy1TotalR + v1->y,
              this->StyleRight,
              0);
    v3a = v34;
    if ( w->solidFlag )
      v36 = Scaleform::Render::StrokerAA::addVertex(this, v32, v33, this->StyleLeft, 1);
    else
      v36 = v35;
    if ( w->aaFlagL )
      v37 = Scaleform::Render::StrokerAA::addVertex(this, xMiterThisL, yMiterThisL, this->StyleLeft, 0);
    else
      v37 = v36;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v35, v36);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v36, this->SolidL);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v35, this->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v3a, v35);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v36, v37);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v37, this->TotalL);
    }
    this->SolidL = v36;
    this->TotalL = v37;
    this->SolidR = v35;
    this->TotalR = v3a;
    if ( v4 )
    {
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(
                       this,
                       v1->x - p->dx2SolidL,
                       v1->y - p->dy2SolidL,
                       this->StyleLeft,
                       1);
      if ( w->aaFlagL )
        v36 = Scaleform::Render::StrokerAA::addVertex(
                this,
                v1->x - p->dx2TotalL,
                v1->y - p->dy2TotalL,
                this->StyleLeft,
                0);
      this->TotalL = v36;
    }
    v38 = atan2f(p->dy1TotalR, p->dx1TotalR);
    v39 = atan2f(p->dy2TotalR, p->dx2TotalR);
    v40 = v39;
    if ( v38 > v39 )
      v40 = v39 + 6.2831855;
    v41 = v40 - v38;
    v42 = (int)(float)(v41
                     / (float)(acosf(w->totalWidthR / (float)((float)(this->Tolerance * 0.25) + w->totalWidthR)) * 2.0))
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
        if ( w->solidFlag )
          v35 = Scaleform::Render::StrokerAA::addVertex(
                  this,
                  (float)(w->solidWidthR * v46) + v1->x,
                  (float)(w->solidWidthR * v47) + v1->y,
                  this->StyleRight,
                  1);
        if ( w->aaFlagR )
          v48 = Scaleform::Render::StrokerAA::addVertex(
                  this,
                  (float)(w->totalWidthR * v46) + v1->x,
                  (float)(w->totalWidthR * v47) + v1->y,
                  this->StyleRight,
                  0);
        else
          v48 = v35;
        if ( w->solidFlagR )
          Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v35);
        if ( w->aaFlagR )
        {
          Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v35);
          Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v48, v35);
        }
        this->SolidR = v35;
        this->TotalR = v48;
        v44 = v44 + v43;
        --v45;
      }
      while ( v45 );
    }
  }
}

// File Line: 501
// RVA: 0x9D0290
void __fastcall Scaleform::Render::StrokerAA::calcBevelJoin(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v1,
        Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p,
        Scaleform::Render::StrokerTypes::LineJoinType lineJoin)
{
  float v9; // xmm7_4
  float xMiterThisR; // xmm11_4
  float yMiterThisR; // xmm12_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v14; // xmm9_4
  float v15; // xmm10_4
  float dbSolidL; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  unsigned int v23; // r14d
  unsigned int v24; // eax
  float dbTotalL; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  unsigned int v28; // r15d
  unsigned int v29; // r13d
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  unsigned int v34; // edi
  float xMiterThisL; // xmm11_4
  float yMiterThisL; // xmm12_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm9_4
  float v40; // xmm10_4
  float dbSolidR; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm7_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm6_4
  unsigned int v48; // r14d
  unsigned int v49; // eax
  float dbTotalR; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  unsigned int v53; // r15d
  unsigned int v54; // r13d
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  unsigned int v59; // edi
  unsigned int v3; // [rsp+30h] [rbp-B8h]
  unsigned int v3a; // [rsp+30h] [rbp-B8h]
  bool v62; // [rsp+108h] [rbp+20h]

  v62 = p->overlapPrev || p->overlapThis;
  v9 = 0.0;
  if ( p->rightTurnThis )
  {
    if ( *(_WORD *)&p->overlapPrev )
    {
      xMiterThisR = p->dx1TotalR + v1->x;
      yMiterThisR = p->dy1TotalR + v1->y;
    }
    else
    {
      xMiterThisR = p->xMiterThisR;
      yMiterThisR = p->yMiterThisR;
    }
    x = v1->x;
    y = v1->y;
    v14 = (float)((float)(xMiterThisR - x) * w->solidCoeffR) + x;
    v15 = (float)((float)(yMiterThisR - y) * w->solidCoeffR) + y;
    if ( lineJoin )
    {
      v24 = Scaleform::Render::StrokerAA::addVertex(this, x - p->dx1SolidL, y - p->dy1SolidL, this->StyleLeft, 1);
      dbTotalL = p->dbTotalL;
      v23 = v24;
      v26 = p->dMiterThisL - dbTotalL;
      if ( v26 == 0.0 )
        v26 = *(float *)&FLOAT_1_0;
      v22 = (float)((float)((float)(p->dbSolidL + w->totalWidthL) - w->solidWidthL) - dbTotalL) / v26;
    }
    else
    {
      dbSolidL = p->dbSolidL;
      v17 = p->dSolidMiterL - dbSolidL;
      if ( v17 == 0.0 )
        v17 = *(float *)&FLOAT_1_0;
      v18 = (float)((float)(w->totalLimitL - dbSolidL) - w->totalWidthL) + w->solidWidthL;
      if ( v18 > v17 )
        v18 = v17;
      v19 = (float)(w->solidLimitL - dbSolidL) + v18;
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
              (float)((float)(p->xSolidMiterL - (float)(x - p->dx1SolidL)) * v9) + (float)(x - p->dx1SolidL),
              (float)((float)(p->ySolidMiterL - (float)(y - p->dy1SolidL)) * v9) + (float)(y - p->dy1SolidL),
              this->StyleLeft,
              1);
    }
    if ( w->aaFlagL )
    {
      v27 = v1->y - p->dy1TotalL;
      v3 = Scaleform::Render::StrokerAA::addVertex(
             this,
             (float)((float)(p->xMiterThisL - (float)(v1->x - p->dx1TotalL)) * v22) + (float)(v1->x - p->dx1TotalL),
             (float)((float)(p->yMiterThisL - v27) * v22) + v27,
             this->StyleLeft,
             0);
    }
    else
    {
      v3 = v23;
    }
    if ( w->solidFlag )
      v28 = Scaleform::Render::StrokerAA::addVertex(this, v14, v15, this->StyleRight, 1);
    else
      v28 = v23;
    if ( w->aaFlagR )
      v29 = Scaleform::Render::StrokerAA::addVertex(this, xMiterThisR, yMiterThisR, this->StyleRight, 0);
    else
      v29 = v28;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v28, v23);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v28);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v23);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v23, v3);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v29, v28);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v29);
    }
    this->SolidL = v23;
    this->SolidR = v28;
    this->TotalR = v29;
    this->TotalL = v3;
    if ( v62 )
    {
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(
                       this,
                       p->dx2SolidR + v1->x,
                       p->dy2SolidR + v1->y,
                       this->StyleRight,
                       1);
      if ( w->aaFlagR )
        v28 = Scaleform::Render::StrokerAA::addVertex(
                this,
                p->dx2TotalR + v1->x,
                p->dy2TotalR + v1->y,
                this->StyleRight,
                0);
      this->TotalR = v28;
    }
    if ( (float)(w->totalWidthL - p->dbTotalL) > (float)((float)(this->Tolerance * 0.25) * 0.25) )
    {
      if ( w->solidFlag )
      {
        if ( lineJoin )
        {
          v31 = v1->y - p->dy2SolidL;
          v32 = v1->x - p->dx2SolidL;
        }
        else
        {
          v30 = v1->y - p->dy2SolidL;
          v31 = (float)((float)(p->ySolidMiterL - v30) * v9) + v30;
          v32 = (float)((float)(p->xSolidMiterL - (float)(v1->x - p->dx2SolidL)) * v9) + (float)(v1->x - p->dx2SolidL);
        }
        v23 = Scaleform::Render::StrokerAA::addVertex(this, v32, v31, this->StyleLeft, 1);
      }
      if ( w->aaFlagL )
      {
        v33 = v1->y - p->dy2TotalL;
        v34 = Scaleform::Render::StrokerAA::addVertex(
                this,
                (float)((float)(p->xMiterThisL - (float)(v1->x - p->dx2TotalL)) * v22) + (float)(v1->x - p->dx2TotalL),
                (float)((float)(p->yMiterThisL - v33) * v22) + v33,
                this->StyleLeft,
                0);
      }
      else
      {
        v34 = v23;
      }
      if ( w->solidFlagL )
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v23, this->SolidL);
      if ( w->aaFlagL )
      {
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v23, this->TotalL);
        Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v23, v34);
      }
      this->SolidL = v23;
      this->TotalL = v34;
    }
  }
  else
  {
    if ( *(_WORD *)&p->overlapPrev )
    {
      xMiterThisL = v1->x - p->dx1TotalL;
      yMiterThisL = v1->y - p->dy1TotalL;
    }
    else
    {
      xMiterThisL = p->xMiterThisL;
      yMiterThisL = p->yMiterThisL;
    }
    v37 = v1->x;
    v38 = v1->y;
    v39 = (float)((float)(xMiterThisL - v37) * w->solidCoeffL) + v37;
    v40 = (float)((float)(yMiterThisL - v38) * w->solidCoeffL) + v38;
    if ( lineJoin )
    {
      v49 = Scaleform::Render::StrokerAA::addVertex(this, v37 + p->dx1SolidR, v38 + p->dy1SolidR, this->StyleRight, 1);
      dbTotalR = p->dbTotalR;
      v48 = v49;
      v51 = p->dMiterThisR - dbTotalR;
      if ( v51 == 0.0 )
        v51 = *(float *)&FLOAT_1_0;
      v47 = (float)((float)((float)(p->dbSolidR + w->totalWidthR) - w->solidWidthR) - dbTotalR) / v51;
    }
    else
    {
      dbSolidR = p->dbSolidR;
      v42 = p->dSolidMiterR - dbSolidR;
      if ( v42 == 0.0 )
        v42 = *(float *)&FLOAT_1_0;
      v43 = (float)((float)(w->totalLimitR - dbSolidR) - w->totalWidthR) + w->solidWidthR;
      if ( v43 > v42 )
        v43 = v42;
      v44 = (float)(w->solidLimitR - dbSolidR) + v43;
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
              1);
    }
    if ( w->aaFlagR )
    {
      v52 = p->dy1TotalR + v1->y;
      v3a = Scaleform::Render::StrokerAA::addVertex(
              this,
              (float)((float)(p->xMiterThisR - (float)(p->dx1TotalR + v1->x)) * v47) + (float)(p->dx1TotalR + v1->x),
              (float)((float)(p->yMiterThisR - v52) * v47) + v52,
              this->StyleRight,
              0);
    }
    else
    {
      v3a = v48;
    }
    if ( w->solidFlag )
      v53 = Scaleform::Render::StrokerAA::addVertex(this, v39, v40, this->StyleLeft, 1);
    else
      v53 = v48;
    if ( w->aaFlagL )
      v54 = Scaleform::Render::StrokerAA::addVertex(this, xMiterThisL, yMiterThisL, this->StyleLeft, 0);
    else
      v54 = v53;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v48, v53);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v53, this->SolidL);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v48, this->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v3a, v48);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v53, v54);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v54, this->TotalL);
    }
    this->SolidL = v53;
    this->TotalL = v54;
    this->SolidR = v48;
    this->TotalR = v3a;
    if ( v62 )
    {
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(
                       this,
                       v1->x - p->dx2SolidL,
                       v1->y - p->dy2SolidL,
                       this->StyleLeft,
                       1);
      if ( w->aaFlagL )
        v53 = Scaleform::Render::StrokerAA::addVertex(
                this,
                v1->x - p->dx2TotalL,
                v1->y - p->dy2TotalL,
                this->StyleLeft,
                0);
      this->TotalL = v53;
    }
    if ( (float)(w->totalWidthR - p->dbTotalR) > (float)((float)(this->Tolerance * 0.25) * 0.25) )
    {
      if ( w->solidFlag )
      {
        if ( lineJoin )
        {
          v56 = p->dy2SolidR + v1->y;
          v57 = p->dx2SolidR + v1->x;
        }
        else
        {
          v55 = p->dy2SolidR + v1->y;
          v56 = (float)((float)(p->ySolidMiterR - v55) * v9) + v55;
          v57 = (float)((float)(p->xSolidMiterR - (float)(p->dx2SolidR + v1->x)) * v9) + (float)(p->dx2SolidR + v1->x);
        }
        v48 = Scaleform::Render::StrokerAA::addVertex(this, v57, v56, this->StyleRight, 1);
      }
      if ( w->aaFlagR )
      {
        v58 = p->dy2TotalR + v1->y;
        v59 = Scaleform::Render::StrokerAA::addVertex(
                this,
                (float)((float)(p->xMiterThisR - (float)(p->dx2TotalR + v1->x)) * v47) + (float)(p->dx2TotalR + v1->x),
                (float)((float)(p->yMiterThisR - v58) * v47) + v58,
                this->StyleRight,
                0);
      }
      else
      {
        v59 = v48;
      }
      if ( w->solidFlagR )
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v48);
      if ( w->aaFlagR )
      {
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v48);
        Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v59, v48);
      }
      this->SolidR = v48;
      this->TotalR = v59;
    }
  }
}Scaleform::Render::StrokerAA::addTria

// File Line: 814
// RVA: 0x9D11B0
void __fastcall Scaleform::Render::StrokerAA::calcButtJoin(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v0,
        Scaleform::Render::StrokeVertex *v1,
        float len,
        Scaleform::Render::StrokerAA::WidthsType *w)
{
  float y; // xmm5_4
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
  unsigned int v18; // r15d
  unsigned int v19; // edi
  unsigned int v20; // r14d

  y = v1->y;
  v8 = (float)(y - v0->y) * (float)(1.0 / len);
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
          y - (float)(w->solidWidthL * v12),
          this->StyleLeft,
          1);
  v17 = v16;
  if ( w->aaFlagL )
    v16 = Scaleform::Render::StrokerAA::addVertex(this, v1->x - v10, v1->y - v14, this->StyleLeft, 0);
  v18 = v16;
  if ( w->solidFlag )
    v19 = Scaleform::Render::StrokerAA::addVertex(this, v9 + v1->x, v13 + v1->y, this->StyleRight, 1);
  else
    v19 = v17;
  if ( w->aaFlagR )
    v20 = Scaleform::Render::StrokerAA::addVertex(this, v11 + v1->x, v15 + v1->y, this->StyleRight, 0);
  else
    v20 = v19;
  if ( w->solidFlagL || w->solidFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v19, v17);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v19);
  }
  if ( w->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v17);
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v17, v18);
  }
  if ( w->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v20, v19);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v20);
  }
  this->SolidL = v17;
  this->TotalL = v18;
  this->SolidR = v19;
  this->TotalR = v20;
}

// File Line: 872
// RVA: 0x9D43B0
void __fastcall Scaleform::Render::StrokerAA::calcMiterJoin(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v1,
        Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p,
        unsigned int lineJoin)
{
  bool v5; // r12
  float x; // xmm3_4
  float y; // xmm4_4
  float xMiterThisL; // xmm8_4
  float yMiterThisL; // xmm9_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  Scaleform::Render::StrokerTypes::LineJoinType v16; // eax
  float xMiterThisR; // xmm10_4
  float yMiterThisR; // xmm11_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  unsigned int v23; // eax
  unsigned int v24; // r15d
  unsigned int v25; // r14d
  unsigned int v26; // r13d
  unsigned int v3; // [rsp+D8h] [rbp+20h]

  v5 = p->overlapPrev || p->overlapThis;
  if ( p->rightTurnThis )
  {
    x = v1->x;
    y = v1->y;
    xMiterThisL = p->xMiterThisL;
    yMiterThisL = p->yMiterThisL;
    v14 = (float)((float)(xMiterThisL - x) * w->solidCoeffL) + x;
    v15 = (float)((float)(yMiterThisL - y) * w->solidCoeffL) + y;
    if ( w->totalLimitL < p->dMiterThisL )
    {
      v16 = lineJoin;
      if ( lineJoin <= 1 )
      {
LABEL_4:
        Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, v16);
        return;
      }
    }
    if ( *(_WORD *)&p->overlapPrev )
    {
      xMiterThisR = x + p->dx1TotalR;
      yMiterThisR = y + p->dy1TotalR;
    }
    else
    {
      xMiterThisR = p->xMiterThisR;
      yMiterThisR = p->yMiterThisR;
    }
    v19 = (float)((float)(xMiterThisR - x) * w->solidCoeffR) + x;
    v20 = (float)((float)(yMiterThisR - y) * w->solidCoeffR) + y;
  }
  else
  {
    v21 = v1->x;
    v22 = v1->y;
    xMiterThisR = p->xMiterThisR;
    yMiterThisR = p->yMiterThisR;
    v19 = (float)((float)(xMiterThisR - v21) * w->solidCoeffR) + v21;
    v20 = (float)((float)(yMiterThisR - v22) * w->solidCoeffR) + v22;
    if ( w->totalLimitR < p->dMiterThisR )
    {
      v16 = lineJoin;
      if ( lineJoin <= 1 )
        goto LABEL_4;
    }
    if ( *(_WORD *)&p->overlapPrev )
    {
      xMiterThisL = v21 - p->dx1TotalL;
      yMiterThisL = v22 - p->dy1TotalL;
    }
    else
    {
      xMiterThisL = p->xMiterThisL;
      yMiterThisL = p->yMiterThisL;
    }
    v14 = (float)((float)(xMiterThisL - v21) * w->solidCoeffL) + v21;
    v15 = (float)((float)(yMiterThisL - v22) * w->solidCoeffL) + v22;
  }
  v23 = Scaleform::Render::StrokerAA::addVertex(this, v14, v15, this->StyleLeft, 1);
  v24 = v23;
  if ( w->aaFlagL )
    v23 = Scaleform::Render::StrokerAA::addVertex(this, xMiterThisL, yMiterThisL, this->StyleLeft, 0);
  v3 = v23;
  if ( w->solidFlag )
    v25 = Scaleform::Render::StrokerAA::addVertex(this, v19, v20, this->StyleRight, 1);
  else
    v25 = v24;
  if ( w->aaFlagR )
    v26 = Scaleform::Render::StrokerAA::addVertex(this, xMiterThisR, yMiterThisR, this->StyleRight, 0);
  else
    v26 = v25;
  if ( w->solidFlagL || w->solidFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v25, v24);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v25);
  }
  if ( w->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v24);
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v24, v3);
  }
  if ( w->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v26, v25);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v26);
  }
  this->TotalR = v26;
  this->TotalL = v3;
  this->SolidL = v24;
  this->SolidR = v25;
  if ( v5 )
  {
    if ( p->rightTurnThis )
    {
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(
                       this,
                       p->dx2SolidR + v1->x,
                       p->dy2SolidR + v1->y,
                       this->StyleRight,
                       1);
      if ( w->aaFlagR )
        v25 = Scaleform::Render::StrokerAA::addVertex(
                this,
                p->dx2TotalR + v1->x,
                p->dy2TotalR + v1->y,
                this->StyleRight,
                0);
      this->TotalR = v25;
    }
    else
    {
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(
                       this,
                       v1->x - p->dx2SolidL,
                       v1->y - p->dy2SolidL,
                       this->StyleLeft,
                       1);
      if ( w->aaFlagL )
        v24 = Scaleform::Render::StrokerAA::addVertex(
                this,
                v1->x - p->dx2TotalL,
                v1->y - p->dy2TotalL,
                this->StyleLeft,
                0);
      this->TotalL = v24;
    }
  }
}

// File Line: 986
// RVA: 0x99B710
bool __fastcall Scaleform::Render::StrokerAA::MitersIntersect(
        float ax,
        float ay,
        float bx,
        float by,
        float cx,
        float cy,
        float dx,
        float dy,
        float epsilon)
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
void __fastcall Scaleform::Render::StrokerAA::calcJoinParam(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokeVertex *v1,
        Scaleform::Render::StrokeVertex *v2,
        Scaleform::Render::StrokeVertex *v3,
        Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p)
{
  float xMiterThisL; // eax
  float v10; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm11_4
  float v13; // xmm9_4
  float v14; // xmm11_4
  float xMiterThisR; // eax
  float *p_xMiterNextL; // r13
  float *p_yMiterNextL; // r15
  float *p_xMiterNextR; // r12
  float *p_yMiterNextR; // r14
  float epsilon; // xmm13_4
  float dx2TotalR; // xmm8_4
  __m128 dy2TotalR_low; // xmm7
  __m128 v23; // xmm0
  float dy2TotalR; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  __m128 v28; // xmm0
  float dx2TotalL; // xmm9_4
  __m128 dy2TotalL_low; // xmm8
  __m128 v31; // xmm0
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  __m128 v35; // xmm0
  bool v36; // dl
  bool rightSideCalc; // cl
  float x; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  __m128 y_low; // xmm3
  float y; // xmm5_4
  float v43; // xmm5_4
  float v44; // xmm9_4
  float v45; // xmm8_4
  float v46; // xmm1_4
  float totalLimitR; // eax
  __m128 x_low; // xmm1
  float v49; // xmm0_4
  float v50; // eax
  float v51; // xmm3_4
  float v52; // xmm3_4
  float totalLimitL; // eax
  float v54; // xmm1_4
  float v55; // xmm1_4
  bool v56; // zf
  bool badMiterThisL; // al
  float yMiterThisL; // xmm0_4
  float v59; // xmm2_4
  float yMiterThisR; // xmm1_4
  float dMiterThisL; // xmm0_4
  float dMiterThisR; // xmm1_4
  char pa; // [rsp+138h] [rbp+30h]

  p->dx1SolidL = p->dx2SolidL;
  p->dy1SolidL = p->dy2SolidL;
  p->dx1SolidR = p->dx2SolidR;
  p->dy1SolidR = p->dy2SolidR;
  p->dx1TotalL = p->dx2TotalL;
  p->dy1TotalL = p->dy2TotalL;
  p->dx1TotalR = p->dx2TotalR;
  p->dy1TotalR = p->dy2TotalR;
  p->dx2SolidL = p->dx3SolidL;
  p->dy2SolidL = p->dy3SolidL;
  p->dx2SolidR = p->dx3SolidR;
  p->dy2SolidR = p->dy3SolidR;
  p->dx2TotalL = p->dx3TotalL;
  p->dy2TotalL = p->dy3TotalL;
  p->dx2TotalR = p->dx3TotalR;
  p->dy2TotalR = p->dy3TotalR;
  xMiterThisL = p->xMiterThisL;
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
  p->xMiterPrevL = xMiterThisL;
  p->yMiterPrevL = p->yMiterThisL;
  xMiterThisR = p->xMiterThisR;
  p->dy3TotalR = v14;
  p->xMiterPrevR = xMiterThisR;
  p_xMiterNextL = &p->xMiterNextL;
  p->yMiterPrevR = p->yMiterThisR;
  p_yMiterNextL = &p->yMiterNextL;
  p->dMiterPrevL = p->dMiterThisL;
  p_xMiterNextR = &p->xMiterNextR;
  p->dMiterPrevR = p->dMiterThisR;
  p_yMiterNextR = &p->yMiterNextR;
  p->xMiterThisL = p->xMiterNextL;
  pa = 1;
  p->yMiterThisL = p->yMiterNextL;
  p->xMiterThisR = p->xMiterNextR;
  p->yMiterThisR = p->yMiterNextR;
  p->dMiterThisL = p->dMiterNextL;
  p->dMiterThisR = p->dMiterNextR;
  p->badMiterPrevL = p->badMiterThisL;
  p->badMiterPrevR = p->badMiterThisR;
  p->badMiterThisL = p->badMiterNextL;
  p->badMiterThisR = p->badMiterNextR;
  epsilon = (float)(v3->dist + v2->dist) * this->IntersectionEpsilon;
  if ( w->rightSideCalc )
  {
    dx2TotalR = p->dx2TotalR;
    dy2TotalR_low = (__m128)LODWORD(p->dy2TotalR);
    v23 = dy2TotalR_low;
    dy2TotalR = p->dy2TotalR;
    v23.m128_f32[0] = (float)((float)((float)(dy2TotalR_low.m128_f32[0] + p->dy1TotalR) * 0.5)
                            * (float)((float)(dy2TotalR_low.m128_f32[0] + p->dy1TotalR) * 0.5))
                    + (float)((float)((float)(dx2TotalR + p->dx1TotalR) * 0.5)
                            * (float)((float)(dx2TotalR + p->dx1TotalR) * 0.5));
    v25 = _mm_sqrt_ps(v23).m128_f32[0];
    p->dbTotalR = v25;
    p->dbSolidR = v25 * w->solidCoeffR;
    v26 = v25 * w->widthCoeff;
    p->dbTotalL = v26;
    p->dbSolidL = v26 * w->solidCoeffL;
    if ( !Scaleform::Render::Math2D::Intersection(
            dx2TotalR + v1->x,
            dy2TotalR_low.m128_f32[0] + v1->y,
            dx2TotalR + v2->x,
            dy2TotalR + v2->y,
            v13 + v2->x,
            v14 + v2->y,
            v13 + v3->x,
            v14 + v3->y,
            &p->xMiterNextR,
            &p->yMiterNextR,
            epsilon) )
      goto LABEL_7;
    v27 = *p_xMiterNextR;
    v28 = (__m128)*(unsigned int *)p_yMiterNextR;
    v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] - v2->y) * (float)(v28.m128_f32[0] - v2->y))
                    + (float)((float)(*p_xMiterNextR - v2->x) * (float)(*p_xMiterNextR - v2->x));
    v28.m128_f32[0] = _mm_sqrt_ps(v28).m128_f32[0];
    LODWORD(p->dMiterNextR) = v28.m128_i32[0];
    p->dMiterNextL = v28.m128_f32[0] * w->widthCoeff;
    v28.m128_f32[0] = *p_yMiterNextR;
    *p_xMiterNextL = v2->x - (float)((float)(v27 - v2->x) * w->widthCoeff);
    *p_yMiterNextL = v2->y - (float)((float)(v28.m128_f32[0] - v2->y) * w->widthCoeff);
  }
  else
  {
    dx2TotalL = p->dx2TotalL;
    dy2TotalL_low = (__m128)LODWORD(p->dy2TotalL);
    v31 = dy2TotalL_low;
    v31.m128_f32[0] = (float)((float)((float)(dy2TotalL_low.m128_f32[0] + p->dy1TotalL) * 0.5)
                            * (float)((float)(dy2TotalL_low.m128_f32[0] + p->dy1TotalL) * 0.5))
                    + (float)((float)((float)(dx2TotalL + p->dx1TotalL) * 0.5)
                            * (float)((float)(dx2TotalL + p->dx1TotalL) * 0.5));
    v32 = _mm_sqrt_ps(v31).m128_f32[0];
    p->dbTotalL = v32;
    p->dbSolidL = v32 * w->solidCoeffL;
    v33 = v32 * w->widthCoeff;
    p->dbTotalR = v33;
    p->dbSolidR = v33 * w->solidCoeffR;
    if ( !Scaleform::Render::Math2D::Intersection(
            v1->x - dx2TotalL,
            v1->y - dy2TotalL_low.m128_f32[0],
            v2->x - dx2TotalL,
            v2->y - dy2TotalL_low.m128_f32[0],
            v2->x - p->dx3TotalL,
            v2->y - p->dy3TotalL,
            v3->x - p->dx3TotalL,
            v3->y - p->dy3TotalL,
            &p->xMiterNextL,
            &p->yMiterNextL,
            epsilon) )
      goto LABEL_7;
    v34 = *p_xMiterNextL;
    v35 = (__m128)*(unsigned int *)p_yMiterNextL;
    v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] - v2->y) * (float)(v35.m128_f32[0] - v2->y))
                    + (float)((float)(*p_xMiterNextL - v2->x) * (float)(*p_xMiterNextL - v2->x));
    v35.m128_f32[0] = _mm_sqrt_ps(v35).m128_f32[0];
    LODWORD(p->dMiterNextL) = v35.m128_i32[0];
    p->dMiterNextR = v35.m128_f32[0] * w->widthCoeff;
    v35.m128_f32[0] = *p_yMiterNextL;
    *p_xMiterNextR = v2->x - (float)((float)(v34 - v2->x) * w->widthCoeff);
    *p_yMiterNextR = v2->y - (float)((float)(v35.m128_f32[0] - v2->y) * w->widthCoeff);
  }
  pa = 0;
  *(_WORD *)&p->badMiterNextL = 0;
LABEL_7:
  p->rightTurnPrev = p->rightTurnThis;
  p->rightTurnThis = p->rightTurnNext;
  v36 = (float)((float)((float)(v3->x - v2->x) * (float)(v2->y - v1->y))
              - (float)((float)(v2->x - v1->x) * (float)(v3->y - v2->y))) > 0.0;
  p->rightTurnNext = v36;
  if ( pa )
  {
    rightSideCalc = w->rightSideCalc;
    x = v2->x;
    v39 = v2->x;
    if ( rightSideCalc )
      v40 = v39 + p->dx2TotalR;
    else
      v40 = v39 - p->dx2TotalL;
    y_low = (__m128)LODWORD(v2->y);
    y = v2->y;
    if ( rightSideCalc )
      v43 = y + p->dy2TotalR;
    else
      v43 = y - p->dy2TotalL;
    v44 = v3->y;
    v45 = v1->y;
    if ( (float)((float)((float)(y_low.m128_f32[0] - v45) * (float)(v40 - x))
               - (float)((float)(x - v1->x) * (float)(v43 - y_low.m128_f32[0]))) < 0.0 == (float)((float)((float)(v40 - v3->x) * (float)(v44 - y_low.m128_f32[0]))
                                                                                                - (float)((float)(v3->x - x) * (float)(v43 - v44))) < 0.0 )
    {
      v46 = p->dy2TotalR;
      *p_xMiterNextL = x - p->dx2TotalL;
      *p_yMiterNextL = v2->y - p->dy2TotalL;
      p->dMiterNextL = w->totalLimitL;
      *p_xMiterNextR = v2->x + p->dx2TotalR;
      *p_yMiterNextR = v46 + v2->y;
      totalLimitR = w->totalLimitR;
      *(_WORD *)&p->badMiterNextL = 0;
      p->dMiterNextR = totalLimitR;
    }
    else
    {
      x_low = (__m128)LODWORD(v2->x);
      x_low.m128_f32[0] = (float)(x - (float)((float)(v1->x + v3->x) * 0.5)) * 1024.0;
      y_low.m128_f32[0] = (float)(y_low.m128_f32[0] - (float)((float)(v45 + v44) * 0.5)) * 1024.0;
      if ( v36 )
      {
        v49 = p->dy2TotalR;
        *p_xMiterNextR = x + p->dx2TotalR;
        *p_yMiterNextR = v49 + v2->y;
        v50 = w->totalLimitR;
        p->badMiterNextR = 1;
        p->dMiterNextR = v50;
        x_low.m128_f32[0] = x_low.m128_f32[0] + v2->x;
        *p_xMiterNextL = x_low.m128_f32[0];
        v51 = y_low.m128_f32[0] + v2->y;
        *p_yMiterNextL = v51;
        x_low.m128_f32[0] = x_low.m128_f32[0] - v2->x;
        v52 = v51 - v2->y;
        p->badMiterNextL = 0;
        x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v52 * v52);
        LODWORD(p->dMiterNextL) = _mm_sqrt_ps(x_low).m128_u32[0];
      }
      else
      {
        *p_xMiterNextL = x - p->dx2TotalL;
        *p_yMiterNextL = v2->y - p->dy2TotalL;
        totalLimitL = w->totalLimitL;
        p->badMiterNextL = 1;
        p->dMiterNextL = totalLimitL;
        v54 = x_low.m128_f32[0] + v2->x;
        *p_xMiterNextR = v54;
        y_low.m128_f32[0] = y_low.m128_f32[0] + v2->y;
        *p_yMiterNextR = y_low.m128_f32[0];
        y_low.m128_f32[0] = y_low.m128_f32[0] - v2->y;
        v55 = v54 - v2->x;
        p->badMiterNextR = 0;
        y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v55 * v55);
        LODWORD(p->dMiterNextR) = _mm_sqrt_ps(y_low).m128_u32[0];
      }
    }
  }
  v56 = !p->rightTurnThis;
  p->overlapPrev = p->overlapThis;
  if ( v56 )
    badMiterThisL = p->badMiterThisL;
  else
    badMiterThisL = p->badMiterThisR;
  p->overlapThis = badMiterThisL;
  if ( !badMiterThisL )
    p->overlapThis = Scaleform::Render::StrokerAA::MitersIntersect(
                       p->xMiterThisL,
                       p->yMiterThisL,
                       p->xMiterThisR,
                       p->yMiterThisR,
                       *p_xMiterNextL,
                       *p_yMiterNextL,
                       *p_xMiterNextR,
                       *p_yMiterNextR,
                       epsilon);
  yMiterThisL = p->yMiterThisL;
  v59 = p->xMiterThisR;
  p->xSolidMiterL = (float)((float)(p->xMiterThisL - v1->x) * w->solidCoeffL) + v1->x;
  yMiterThisR = p->yMiterThisR;
  p->ySolidMiterL = (float)((float)(yMiterThisL - v1->y) * w->solidCoeffL) + v1->y;
  dMiterThisL = p->dMiterThisL;
  p->xSolidMiterR = (float)((float)(v59 - v1->x) * w->solidCoeffR) + v1->x;
  p->ySolidMiterR = (float)((float)(yMiterThisR - v1->y) * w->solidCoeffR) + v1->y;
  dMiterThisR = p->dMiterThisR;
  p->dSolidMiterL = dMiterThisL * w->solidCoeffL;
  p->dSolidMiterR = dMiterThisR * w->solidCoeffR;
}

// File Line: 1250
// RVA: 0x9D56B0
void __fastcall Scaleform::Render::StrokerAA::calcWidths(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::StrokerAA::WidthsType *w)
{
  bool v2; // r9
  bool v3; // cc
  float solidWidthL; // xmm6_4
  float solidWidthR; // xmm5_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float totalWidthR; // xmm3_4
  float v10; // xmm1_4

  v2 = 0;
  w->solidWidthL = this->WidthLeft;
  v3 = w->solidWidthL >= 0.0;
  w->solidWidthR = this->WidthRight;
  if ( !v3 )
    w->solidWidthL = 0.0;
  if ( w->solidWidthR < 0.0 )
    w->solidWidthR = 0.0;
  solidWidthL = w->solidWidthL;
  solidWidthR = w->solidWidthR;
  v6 = *(float *)&FLOAT_1_0;
  v7 = w->solidWidthL + this->AaWidthLeft;
  w->totalWidthL = v7;
  w->totalWidthR = solidWidthR + this->AaWidthRight;
  if ( v7 == 0.0 )
    v8 = *(float *)&FLOAT_1_0;
  else
    v8 = solidWidthL / v7;
  totalWidthR = w->totalWidthR;
  w->solidCoeffL = v8;
  if ( totalWidthR != 0.0 )
    v6 = solidWidthR / totalWidthR;
  w->solidCoeffR = v6;
  w->solidLimitL = solidWidthL * this->MiterLimit;
  w->solidLimitR = solidWidthR * this->MiterLimit;
  w->totalLimitL = v7 * this->MiterLimit;
  v10 = totalWidthR * this->MiterLimit;
  w->solidFlagL = solidWidthL > 0.0;
  w->totalLimitR = v10;
  w->solidFlagR = solidWidthR > 0.0;
  w->totalWidth = (float)(totalWidthR + v7) * 0.5;
  w->solidWidth = (float)(solidWidthR + solidWidthL) * 0.5;
  w->aaFlagL = this->AaWidthLeft > 0.0;
  w->aaFlagR = this->AaWidthRight > 0.0;
  if ( solidWidthL > 0.0 || solidWidthR > 0.0 || this->StyleLeft != this->StyleRight )
    v2 = 1;
  w->solidFlag = v2;
  w->rightSideCalc = totalWidthR > v7;
  if ( totalWidthR <= v7 )
    w->widthCoeff = totalWidthR / v7;
  else
    w->widthCoeff = v7 / totalWidthR;
}

// File Line: 1287
// RVA: 0x978840
void __fastcall Scaleform::Render::StrokerAA::FinalizePath(
        Scaleform::Render::StrokerAA *this,
        unsigned int __formal,
        unsigned int a3,
        bool a4,
        bool __formala)
{
  bool v6; // zf
  unsigned __int64 v7; // r15
  Scaleform::Render::StrokeVertex **v8; // rbx
  Scaleform::Render::StrokeVertex *v9; // rsi
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // r9
  unsigned __int64 v15; // r8
  Scaleform::Render::StrokeVertex *v16; // rbx
  Scaleform::Render::StrokerTypes::LineJoinType v17; // eax
  __int64 v18; // r10
  unsigned __int64 v19; // rax
  Scaleform::Render::StrokerAA::TriangleType *v20; // r9
  float v21; // xmm4_4
  Scaleform::Render::StrokeVertex **Pages; // rax
  float *v23; // rcx
  float dist; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  unsigned __int64 Size; // rdx
  Scaleform::Render::StrokeVertex **v28; // r8
  __int64 v29; // r10
  Scaleform::Render::StrokeVertex *v30; // r9
  unsigned __int64 v31; // rcx
  __int64 v32; // rdx
  Scaleform::Render::StrokeVertex *v33; // rax
  float y; // xmm1_4
  Scaleform::Render::StrokeVertex *v35; // rdx
  Scaleform::Render::StrokerTypes::LineCapType StartLineCap; // eax
  Scaleform::Render::StrokeVertex *v37; // r8
  float v38; // xmm3_4
  unsigned __int64 v39; // r15
  Scaleform::Render::StrokeVertex **v40; // rax
  Scaleform::Render::StrokeVertex *v41; // rdx
  float v42; // xmm6_4
  float x; // xmm8_4
  float v44; // xmm7_4
  float v45; // xmm3_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  unsigned __int64 v48; // r15
  unsigned __int64 v49; // rbx
  unsigned __int64 v50; // rsi
  Scaleform::Render::StrokeVertex **v51; // r8
  Scaleform::Render::StrokeVertex *v52; // rdi
  Scaleform::Render::StrokerTypes::LineJoinType LineJoin; // eax
  Scaleform::Render::StrokeVertex **v54; // r10
  Scaleform::Render::StrokeVertex *v55; // r8
  Scaleform::Render::StrokeVertex *v56; // rcx
  Scaleform::Render::StrokeVertex *v57; // rax
  unsigned __int64 v58; // rdx
  Scaleform::Render::StrokeVertex *v59; // rbx
  Scaleform::Render::StrokeVertex *v60; // rax
  Scaleform::Render::StrokerTypes::LineJoinType v61; // eax
  unsigned __int64 v62; // rax
  unsigned __int64 v63; // rax
  Scaleform::Render::StrokeVertex **v64; // r10
  float v65; // xmm3_4
  Scaleform::Render::StrokeVertex *v66; // r8
  Scaleform::Render::StrokeVertex *v67; // rdx
  Scaleform::Render::StrokerTypes::LineCapType EndLineCap; // eax
  Scaleform::Render::StrokerAA::WidthsType w; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::StrokeVertex v3; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::StrokerAA::JoinParamType p; // [rsp+80h] [rbp-80h] BYREF

  if ( !this->Closed )
    this->Closed = Scaleform::Render::StrokePath::ClosePath(&this->Path);
  this->SolidL = -4;
  this->SolidR = -3;
  *(_QWORD *)&this->TotalL = -2i64;
  memset(&w, 0, 58);
  Scaleform::Render::StrokerAA::calcWidths(this, &w);
  v6 = !this->Closed;
  memset(&p, 0, 219);
  if ( v6 )
  {
    if ( this->Path.Path.Size > 1 )
    {
      v21 = (float)(this->WidthRight + this->WidthLeft) * 0.5;
      if ( this->StartLineCap == SquareCap )
      {
        Pages = this->Path.Path.Pages;
        v23 = (float *)*Pages;
        dist = (*Pages)->dist;
        *v23 = (*Pages)->x - (float)((float)((float)((*Pages)[1].x - (*Pages)->x) * v21) * (float)(1.0 / dist));
        v25 = v23[1];
        v26 = v23[4];
        v23[2] = dist + v21;
        v23[1] = v25 - (float)((float)((float)(v26 - v25) * v21) * (float)(1.0 / dist));
      }
      if ( this->EndLineCap == SquareCap )
      {
        Size = this->Path.Path.Size;
        v28 = this->Path.Path.Pages;
        v29 = ((_DWORD)Size - 2) & 0xF;
        v30 = v28[(Size - 2) >> 4];
        v31 = (Size - 1) >> 4;
        v32 = ((_DWORD)Size - 1) & 0xF;
        v33 = v28[v31];
        y = v33[v32].y;
        v33[v32].x = (float)((float)((float)(v33[v32].x - v30[v29].x) * v21) / v30[v29].dist) + v33[v32].x;
        v33[v32].y = (float)((float)((float)(y - v30[v29].y) * v21) / v30[v29].dist) + y;
        v30[v29].dist = v21 + v30[v29].dist;
      }
      v35 = *this->Path.Path.Pages;
      StartLineCap = this->StartLineCap;
      v37 = v35 + 1;
      v38 = v35->dist;
      if ( StartLineCap >= ButtCap )
      {
        if ( StartLineCap <= SquareCap )
        {
          Scaleform::Render::StrokerAA::calcButtCap(this, v35, v37, v38, &w, 0);
        }
        else if ( StartLineCap == RoundCap )
        {
          Scaleform::Render::StrokerAA::calcRoundCap(this, v35, v37, v38, &w, 0);
        }
      }
      v39 = this->Path.Path.Size;
      if ( v39 > 2 )
      {
        v40 = this->Path.Path.Pages;
        p.overlapThis = 0;
        p.rightTurnNext = 0;
        v41 = *v40;
        *(_WORD *)&p.badMiterNextL = 0;
        p.dMiterNextR = w.totalWidthR;
        v42 = 1.0 / v41->dist;
        x = v41->x;
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
        p.xMiterNextL = x - (float)(w.totalWidthL * v46);
        p.yMiterNextL = v47 - (float)(w.totalWidthL * v44);
        p.xMiterNextR = x + (float)(w.totalWidthR * v46);
        Scaleform::Render::StrokerAA::calcJoinParam(this, v41, v41 + 1, v41 + 2, &w, &p);
        v48 = v39 - 2;
        v49 = 1i64;
        if ( v48 > 1 )
        {
          v50 = 2i64;
          do
          {
            v51 = this->Path.Path.Pages;
            v52 = &v51[v49 >> 4][v49 & 0xF];
            Scaleform::Render::StrokerAA::calcJoinParam(
              this,
              v52,
              &v51[v50 >> 4][v50 & 0xF],
              &v51[(v50 + 1) >> 4][((_DWORD)v50 + 1) & 0xF],
              &w,
              &p);
            LineJoin = this->LineJoin;
            if ( LineJoin >= MiterJoin )
            {
              if ( LineJoin <= MiterBevelJoin )
              {
                Scaleform::Render::StrokerAA::calcMiterJoin(this, v52, &w, &p, this->LineJoin);
              }
              else if ( LineJoin == RoundJoin )
              {
                Scaleform::Render::StrokerAA::calcRoundJoin(this, v52, &w, &p);
              }
              else if ( LineJoin == BevelJoin )
              {
                Scaleform::Render::StrokerAA::calcBevelJoin(this, v52, &w, &p, BevelJoin);
              }
            }
            ++v49;
            ++v50;
          }
          while ( v49 < v48 );
        }
        v54 = this->Path.Path.Pages;
        v55 = v54[v48 >> 4];
        v56 = v54[(v48 + 1) >> 4];
        v57 = v54[v49 >> 4];
        v3.x = (float)(v56[((_DWORD)v48 + 1) & 0xF].x * 2.0) - v55[v48 & 0xF].x;
        v58 = v49 + 1;
        v59 = &v57[v49 & 0xF];
        v60 = v54[v58 >> 4];
        v3.y = (float)(v56[((_DWORD)v48 + 1) & 0xF].y * 2.0) - v55[v48 & 0xF].y;
        v3.dist = v55[v48 & 0xF].dist;
        Scaleform::Render::StrokerAA::calcJoinParam(this, v59, &v60[v58 & 0xF], &v3, &w, &p);
        v61 = this->LineJoin;
        if ( v61 >= MiterJoin )
        {
          if ( v61 <= MiterBevelJoin )
          {
            Scaleform::Render::StrokerAA::calcMiterJoin(this, v59, &w, &p, this->LineJoin);
          }
          else if ( v61 == RoundJoin )
          {
            Scaleform::Render::StrokerAA::calcRoundJoin(this, v59, &w, &p);
          }
          else if ( v61 == BevelJoin )
          {
            Scaleform::Render::StrokerAA::calcBevelJoin(this, v59, &w, &p, BevelJoin);
          }
        }
      }
      v62 = this->Path.Path.Size;
      Scaleform::Render::StrokerAA::calcButtJoin(
        this,
        &this->Path.Path.Pages[(v62 - 2) >> 4][((_BYTE)v62 - 2) & 0xF],
        &this->Path.Path.Pages[(v62 - 1) >> 4][((_DWORD)v62 - 1) & 0xF],
        this->Path.Path.Pages[(v62 - 2) >> 4][((_BYTE)v62 - 2) & 0xF].dist,
        &w);
      v63 = this->Path.Path.Size;
      v64 = this->Path.Path.Pages;
      v65 = v64[(v63 - 2) >> 4][((_BYTE)v63 - 2) & 0xF].dist;
      v66 = &v64[(v63 - 2) >> 4][((_DWORD)v63 - 2) & 0xF];
      v67 = &v64[(v63 - 1) >> 4][((_DWORD)v63 - 1) & 0xF];
      EndLineCap = this->EndLineCap;
      if ( EndLineCap >= ButtCap )
      {
        if ( EndLineCap <= SquareCap )
        {
          Scaleform::Render::StrokerAA::calcButtCap(this, v67, v66, v65, &w, 1);
        }
        else if ( EndLineCap == RoundCap )
        {
          Scaleform::Render::StrokerAA::calcRoundCap(this, v67, v66, v65, &w, 1);
        }
      }
    }
  }
  else
  {
    v7 = this->Path.Path.Size;
    if ( v7 > 2 )
    {
      v8 = this->Path.Path.Pages;
      v9 = *v8;
      Scaleform::Render::StrokerAA::calcJoinParam(
        this,
        &v8[(v7 - 2) >> 4][((_DWORD)v7 - 2) & 0xF],
        &v8[(v7 - 1) >> 4][((_BYTE)v7 - 1) & 0xF],
        *v8,
        &w,
        &p);
      Scaleform::Render::StrokerAA::calcJoinParam(this, &v8[(v7 - 1) >> 4][((_DWORD)v7 - 1) & 0xF], v9, v9 + 1, &w, &p);
      v10 = this->Triangles.Size;
      v11 = 1i64;
      do
      {
        v12 = this->Path.Path.Size;
        v13 = v11 + 1;
        v14 = v11 + 1;
        if ( v11 + 1 >= v12 )
          v14 -= v12;
        v15 = v11;
        if ( v11 >= v12 )
          v15 = v11 - v12;
        v16 = &this->Path.Path.Pages[(v11 - 1) >> 4][((_DWORD)v11 - 1) & 0xF];
        Scaleform::Render::StrokerAA::calcJoinParam(
          this,
          v16,
          &this->Path.Path.Pages[v15 >> 4][v15 & 0xF],
          &this->Path.Path.Pages[v14 >> 4][v14 & 0xF],
          &w,
          &p);
        v17 = this->LineJoin;
        if ( v17 >= MiterJoin )
        {
          if ( v17 <= MiterBevelJoin )
          {
            Scaleform::Render::StrokerAA::calcMiterJoin(this, v16, &w, &p, this->LineJoin);
          }
          else if ( v17 == RoundJoin )
          {
            Scaleform::Render::StrokerAA::calcRoundJoin(this, v16, &w, &p);
          }
          else if ( v17 == BevelJoin )
          {
            Scaleform::Render::StrokerAA::calcBevelJoin(this, v16, &w, &p, BevelJoin);
          }
        }
        v11 = v13;
      }
      while ( v13 - 1 < this->Path.Path.Size );
      v18 = -(__int64)v10;
      do
      {
        if ( v10 >= this->Triangles.Size )
          break;
        v19 = v10 & 0xF;
        v20 = this->Triangles.Pages[v10 >> 4];
        if ( v20[v19].v1 == -4 )
          v20[v19].v1 = this->SolidL;
        if ( v20[v19].v1 == -3 )
          v20[v19].v1 = this->SolidR;
        if ( v20[v19].v1 == -2 )
          v20[v19].v1 = this->TotalL;
        if ( v20[v19].v1 == -1 )
          v20[v19].v1 = this->TotalR;
        if ( v20[v19].v2 == -4 )
          v20[v19].v2 = this->SolidL;
        if ( v20[v19].v2 == -3 )
          v20[v19].v2 = this->SolidR;
        if ( v20[v19].v2 == -2 )
          v20[v19].v2 = this->TotalL;
        if ( v20[v19].v2 == -1 )
          v20[v19].v2 = this->TotalR;
        if ( v20[v19].v3 == -4 )
          v20[v19].v3 = this->SolidL;
        if ( v20[v19].v3 == -3 )
          v20[v19].v3 = this->SolidR;
        if ( v20[v19].v3 == -2 )
          v20[v19].v3 = this->TotalL;
        if ( v20[v19].v3 == -1 )
          v20[v19].v3 = this->TotalR;
        ++v10;
      }
      while ( v18 + v10 < 6 );
    }
  }
  this->Path.Path.Size = 0i64;
  this->Closed = 0;
}

// File Line: 1424
// RVA: 0x9BA780
void __fastcall Scaleform::Render::StrokerAA::Transform(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v2; // r10
  __int64 v3; // r9
  Scaleform::Render::StrokerAA::VertexType *v4; // rax
  float x; // xmm2_4
  float y; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v2 = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  for ( this->MaxY = -1.0e30; v2 < this->Vertices.Size; ++v2 )
  {
    v3 = v2 & 0xF;
    v4 = this->Vertices.Pages[v2 >> 4];
    x = v4[v2 & 0xF].x;
    y = v4[v2 & 0xF].y;
    v4[v3].x = (float)((float)(x * m->M[0][0]) + (float)(y * m->M[0][1])) + m->M[0][3];
    v4[v3].y = (float)((float)(y * m->M[1][1]) + (float)(x * m->M[1][0])) + m->M[1][3];
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
  }
}

// File Line: 1444
// RVA: 0x9B7F50
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::StrokerAA::StretchTo(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::Matrix2x4<float> *result,
        float x1,
        float y1,
        float x2,
        float y2)
{
  unsigned __int64 v6; // rsi
  unsigned __int64 Size; // r9
  unsigned __int64 v12; // r8
  float v13; // xmm3_4
  Scaleform::Render::StrokerAA::VertexType **Pages; // r10
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  Scaleform::Render::StrokerAA::VertexType *v18; // rax
  float x; // xmm2_4
  float y; // xmm1_4
  float MinX; // xmm3_4
  float MaxX; // xmm1_4
  float MinY; // xmm0_4
  float MaxY; // xmm2_4
  __int64 v25; // rax
  unsigned __int64 v26; // rdx
  __int64 v27; // r8
  Scaleform::Render::StrokerAA::VertexType *v28; // rax
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float dst[2]; // [rsp+20h] [rbp-29h] BYREF
  float v35; // [rsp+28h] [rbp-21h]
  float v36; // [rsp+2Ch] [rbp-1Dh]
  float v37; // [rsp+30h] [rbp-19h]
  float v38; // [rsp+34h] [rbp-15h]
  Scaleform::Render::Matrix2x4<float> src; // [rsp+40h] [rbp-9h] BYREF

  v6 = 0i64;
  *(_QWORD *)&result->M[0][0] = 1065353216i64;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  *(_QWORD *)&result->M[0][2] = 0i64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  if ( this->MaxX <= this->MinX || this->MaxY <= this->MinY )
  {
    Size = this->Vertices.Size;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    v12 = 0i64;
    if ( Size )
    {
      v13 = FLOAT_N1_0e30;
      Pages = this->Vertices.Pages;
      v15 = FLOAT_1_0e30;
      v16 = FLOAT_N1_0e30;
      v17 = FLOAT_1_0e30;
      do
      {
        v18 = Pages[v12 >> 4];
        x = v18[v12 & 0xF].x;
        y = v18[v12 & 0xF].y;
        v35 = *(float *)&v18[v12 & 0xF].style;
        if ( x < v15 )
        {
          this->MinX = x;
          v15 = x;
        }
        if ( y < v17 )
        {
          this->MinY = y;
          v17 = y;
        }
        if ( x > v13 )
        {
          this->MaxX = x;
          v13 = x;
        }
        if ( y > v16 )
        {
          this->MaxY = y;
          v16 = y;
        }
        ++v12;
      }
      while ( v12 < Size );
    }
  }
  MinX = this->MinX;
  MaxX = this->MaxX;
  if ( MinX < MaxX )
  {
    MinY = this->MinY;
    MaxY = this->MaxY;
    if ( MinY < MaxY )
    {
      src.M[0][1] = this->MinY;
      v35 = x2;
      v37 = x2;
      v38 = y2;
      src.M[0][0] = MinX;
      *(_QWORD *)&src.M[0][2] = __PAIR64__(LODWORD(MinY), LODWORD(MaxX));
      *(_QWORD *)&src.M[1][0] = __PAIR64__(LODWORD(MaxY), LODWORD(MaxX));
      dst[0] = x1;
      dst[1] = y1;
      v36 = y1;
      Scaleform::Render::Matrix2x4<float>::SetParlToParl(result, (float *)&src, dst);
      if ( this->Vertices.Size )
      {
        do
        {
          v25 = v6 & 0xF;
          v26 = v6++ >> 4;
          v27 = v25;
          v28 = this->Vertices.Pages[v26];
          v29 = v28[v27].x;
          v30 = v28[v27].y;
          v28[v27].x = (float)((float)(v29 * result->M[0][0]) + (float)(v30 * result->M[0][1])) + result->M[0][3];
          v28[v27].y = (float)((float)(v29 * result->M[1][0]) + (float)(v30 * result->M[1][1])) + result->M[1][3];
        }
        while ( v6 < this->Vertices.Size );
      }
      v31 = result->M[0][1];
      src.M[0][0] = result->M[0][0];
      *(_QWORD *)&src.M[0][1] = __PAIR64__(LODWORD(result->M[0][2]), LODWORD(v31));
      v32 = result->M[1][0];
      src.M[0][3] = result->M[0][3];
      *(_QWORD *)&src.M[1][0] = __PAIR64__(LODWORD(result->M[1][1]), LODWORD(v32));
      *(_QWORD *)&src.M[1][2] = *(_QWORD *)&result->M[1][2];
      Scaleform::Render::Matrix2x4<float>::SetInverse(result, &src);
    }
  }
  return result;
}

// File Line: 1479
// RVA: 0x989220
void __fastcall Scaleform::Render::StrokerAA::GetMesh(
        Scaleform::Render::StrokerAA *this,
        unsigned int __formal,
        Scaleform::Render::TessMesh *mesh)
{
  *(_QWORD *)&mesh->Style1 = 1i64;
  mesh->MeshIdx = 0;
  *(_QWORD *)&mesh->Flags1 = 0i64;
  mesh->StartVertex = 0;
  mesh->VertexCount = this->Vertices.Size;
}

// File Line: 1491
// RVA: 0x98EFD0
__int64 __fastcall Scaleform::Render::StrokerAA::GetVertices(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::TessMesh *mesh,
        Scaleform::Render::TessVertex *vertices,
        int num)
{
  unsigned int v6; // r10d
  unsigned __int64 v7; // rdx
  __int64 v8; // r8
  Scaleform::Render::StrokerAA::VertexType *v9; // rdx
  float v10; // eax
  unsigned __int64 v11; // rdx
  __int64 v12; // r8
  Scaleform::Render::StrokerAA::VertexType *v13; // rdx
  float v14; // eax
  unsigned __int64 v15; // rdx
  __int64 v16; // r8
  Scaleform::Render::StrokerAA::VertexType *v17; // rdx
  float v18; // eax
  unsigned __int64 v19; // rdx
  __int64 v20; // r8
  Scaleform::Render::StrokerAA::VertexType *v21; // rdx
  float v22; // eax
  unsigned int *p_Idx; // r11
  unsigned __int64 StartVertex; // rdx
  __int64 v25; // r8
  Scaleform::Render::StrokerAA::VertexType *v26; // rdx
  float y; // eax

  v6 = 0;
  if ( num < 4 )
  {
LABEL_7:
    if ( v6 < num )
    {
      p_Idx = &vertices->Idx;
      do
      {
        StartVertex = mesh->StartVertex;
        if ( StartVertex >= this->Vertices.Size )
          break;
        v25 = StartVertex & 0xF;
        v26 = this->Vertices.Pages[(unsigned __int64)(unsigned int)StartVertex >> 4];
        *(p_Idx - 2) = LODWORD(v26[v25].x);
        y = v26[v25].y;
        *p_Idx = 0;
        *((float *)p_Idx - 1) = y;
        LOWORD(y) = v26[v25].style;
        *((_WORD *)p_Idx + 3) = 0;
        *((_WORD *)p_Idx + 2) = LOWORD(y);
        ++v6;
        p_Idx += 5;
        *((_WORD *)p_Idx - 6) = v26[v25].alpha != 0 ? 2 : 0;
        ++mesh->StartVertex;
      }
      while ( v6 < num );
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = mesh->StartVertex;
      if ( v7 >= this->Vertices.Size )
        break;
      v8 = v7 & 0xF;
      v9 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v7 >> 4];
      vertices->x = v9[v8].x;
      v10 = v9[v8].y;
      vertices->Idx = 0;
      vertices->y = v10;
      LOWORD(v10) = v9[v8].style;
      vertices->Styles[1] = 0;
      vertices->Styles[0] = LOWORD(v10);
      vertices->Flags = v9[v8].alpha != 0 ? 2 : 0;
      v11 = ++mesh->StartVertex;
      if ( v11 >= this->Vertices.Size )
        return v6 + 1;
      v12 = v11 & 0xF;
      v13 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v11 >> 4];
      vertices[1].x = v13[v12].x;
      v14 = v13[v12].y;
      vertices[1].Idx = 0;
      vertices[1].y = v14;
      LOWORD(v14) = v13[v12].style;
      vertices[1].Styles[1] = 0;
      vertices[1].Styles[0] = LOWORD(v14);
      vertices[1].Flags = v13[v12].alpha != 0 ? 2 : 0;
      v15 = ++mesh->StartVertex;
      if ( v15 >= this->Vertices.Size )
        return v6 + 2;
      v16 = v15 & 0xF;
      v17 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v15 >> 4];
      vertices[2].x = v17[v16].x;
      v18 = v17[v16].y;
      vertices[2].Idx = 0;
      vertices[2].y = v18;
      LOWORD(v18) = v17[v16].style;
      vertices[2].Styles[1] = 0;
      vertices[2].Styles[0] = LOWORD(v18);
      vertices[2].Flags = v17[v16].alpha != 0 ? 2 : 0;
      v19 = ++mesh->StartVertex;
      if ( v19 >= this->Vertices.Size )
        return v6 + 3;
      v20 = v19 & 0xF;
      v21 = this->Vertices.Pages[(unsigned __int64)(unsigned int)v19 >> 4];
      vertices[3].x = v21[v20].x;
      v22 = v21[v20].y;
      vertices[3].Idx = 0;
      vertices[3].y = v22;
      LOWORD(v22) = v21[v20].style;
      vertices[3].Styles[1] = 0;
      vertices[3].Styles[0] = LOWORD(v22);
      v6 += 4;
      vertices += 4;
      vertices[-1].Flags = v21[v20].alpha != 0 ? 2 : 0;
      ++mesh->StartVertex;
      if ( v6 >= num - 3 )
        goto LABEL_7;
    }
  }
  return v6;
}

// File Line: 1510
// RVA: 0x98E010
void __fastcall Scaleform::Render::StrokerAA::GetTrianglesI16(
        Scaleform::Render::StrokerAA *this,
        unsigned int __formal,
        unsigned __int16 *idx,
        unsigned int start,
        unsigned int num)
{
  unsigned int i; // r10d
  unsigned int v6; // eax
  unsigned __int16 *v7; // rdx

  for ( i = 0; i < num; *(idx - 1) = v7[4] )
  {
    v6 = i + start;
    ++i;
    idx += 3;
    v7 = (unsigned __int16 *)&this->Triangles.Pages[(unsigned __int64)v6 >> 4][v6 & 0xF];
    *(idx - 3) = *v7;
    *(idx - 2) = v7[2];
  }
}

