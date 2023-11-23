// File Line: 60
// RVA: 0x93DAD0
void __fastcall Scaleform::Render::Hairliner::Hairliner(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::LinearHeap *heap)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Hairliner::`vftable;
  this->pHeap = heap;
  this->Epsilon = 0.0;
  this->IntersectionEpsilon = 0.0099999998;
  this->Width = 0.5;
  this->Paths.pHeap = heap;
  this->Paths.Size = 0i64;
  this->Paths.NumPages = 0i64;
  this->Paths.MaxPages = 0i64;
  this->Paths.Pages = 0i64;
  this->SrcVertices.pHeap = heap;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->OutVertices.pHeap = heap;
  this->OutVertices.Size = 0i64;
  this->OutVertices.NumPages = 0i64;
  this->OutVertices.MaxPages = 0i64;
  this->OutVertices.Pages = 0i64;
  this->Triangles.pHeap = heap;
  this->Triangles.Size = 0i64;
  this->Triangles.NumPages = 0i64;
  this->Triangles.MaxPages = 0i64;
  this->Triangles.Pages = 0i64;
  this->LastVertex = 0;
  this->SrcEdges.pHeap = heap;
  this->SrcEdges.Size = 0i64;
  this->SrcEdges.NumPages = 0i64;
  this->SrcEdges.MaxPages = 0i64;
  this->SrcEdges.Pages = 0i64;
  this->MonoChains.pHeap = heap;
  this->MonoChains.Size = 0i64;
  this->MonoChains.NumPages = 0i64;
  this->MonoChains.MaxPages = 0i64;
  this->MonoChains.Pages = 0i64;
  this->MonoChainsSorted.pHeap = heap;
  this->MonoChainsSorted.Size = 0i64;
  this->MonoChainsSorted.NumPages = 0i64;
  this->MonoChainsSorted.MaxPages = 0i64;
  this->MonoChainsSorted.Pages = 0i64;
  this->Scanbeams.pHeap = heap;
  this->Scanbeams.Size = 0i64;
  this->Scanbeams.NumPages = 0i64;
  this->Scanbeams.MaxPages = 0i64;
  this->Scanbeams.Pages = 0i64;
  this->HorizontalEdges.pHeap = heap;
  this->HorizontalEdges.Size = 0i64;
  this->HorizontalEdges.NumPages = 0i64;
  this->HorizontalEdges.MaxPages = 0i64;
  this->HorizontalEdges.Pages = 0i64;
  *(_QWORD *)&this->StartHorizontals = 0i64;
  this->LastX = -1.0e30;
  this->LastY = -1.0e30;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  this->ActiveChains.pHeap = heap;
  this->ActiveChains.Size = 0i64;
  this->ActiveChains.NumPages = 0i64;
  this->ActiveChains.MaxPages = 0i64;
  this->ActiveChains.Pages = 0i64;
  this->ChainsAtBottom.pHeap = heap;
  this->ChainsAtBottom.Size = 0i64;
  this->ChainsAtBottom.NumPages = 0i64;
  this->ChainsAtBottom.MaxPages = 0i64;
  this->ChainsAtBottom.Pages = 0i64;
  this->ValidChains.pHeap = heap;
  this->ValidChains.Size = 0i64;
  this->ValidChains.NumPages = 0i64;
  this->ValidChains.MaxPages = 0i64;
  this->ValidChains.Pages = 0i64;
  this->Intersections.pHeap = heap;
  this->Intersections.Size = 0i64;
  this->Intersections.NumPages = 0i64;
  this->Intersections.MaxPages = 0i64;
  this->Intersections.Pages = 0i64;
  this->ContourNodes.pHeap = heap;
  this->ContourNodes.Size = 0i64;
  this->ContourNodes.NumPages = 0i64;
  this->ContourNodes.MaxPages = 0i64;
  this->ContourNodes.Pages = 0i64;
  this->FanEdges.pHeap = heap;
  this->FanEdges.Size = 0i64;
  this->FanEdges.NumPages = 0i64;
  this->FanEdges.MaxPages = 0i64;
  this->FanEdges.Pages = 0i64;
}

// File Line: 64
// RVA: 0x95F5B0
void __fastcall Scaleform::Render::Hairliner::Clear(Scaleform::Render::Hairliner *this)
{
  this->Paths.MaxPages = 0i64;
  this->Paths.NumPages = 0i64;
  this->Paths.Size = 0i64;
  this->Paths.Pages = 0i64;
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->OutVertices.MaxPages = 0i64;
  this->OutVertices.NumPages = 0i64;
  this->OutVertices.Size = 0i64;
  this->OutVertices.Pages = 0i64;
  this->Triangles.MaxPages = 0i64;
  this->Triangles.NumPages = 0i64;
  this->Triangles.Size = 0i64;
  this->Triangles.Pages = 0i64;
  this->LastVertex = 0;
  this->SrcEdges.MaxPages = 0i64;
  this->SrcEdges.NumPages = 0i64;
  this->SrcEdges.Size = 0i64;
  this->SrcEdges.Pages = 0i64;
  this->MonoChains.MaxPages = 0i64;
  this->MonoChains.NumPages = 0i64;
  this->MonoChains.Size = 0i64;
  this->MonoChains.Pages = 0i64;
  this->MonoChainsSorted.MaxPages = 0i64;
  this->MonoChainsSorted.NumPages = 0i64;
  this->MonoChainsSorted.Size = 0i64;
  this->MonoChainsSorted.Pages = 0i64;
  this->Scanbeams.MaxPages = 0i64;
  this->Scanbeams.NumPages = 0i64;
  this->Scanbeams.Size = 0i64;
  this->Scanbeams.Pages = 0i64;
  this->HorizontalEdges.MaxPages = 0i64;
  this->HorizontalEdges.NumPages = 0i64;
  this->HorizontalEdges.Size = 0i64;
  this->HorizontalEdges.Pages = 0i64;
  *(_QWORD *)&this->StartHorizontals = 0i64;
  this->ActiveChains.MaxPages = 0i64;
  this->ActiveChains.NumPages = 0i64;
  this->ActiveChains.Size = 0i64;
  this->ActiveChains.Pages = 0i64;
  this->ChainsAtBottom.MaxPages = 0i64;
  this->ChainsAtBottom.NumPages = 0i64;
  this->ChainsAtBottom.Size = 0i64;
  this->ChainsAtBottom.Pages = 0i64;
  this->ValidChains.MaxPages = 0i64;
  this->ValidChains.NumPages = 0i64;
  this->ValidChains.Size = 0i64;
  this->ValidChains.Pages = 0i64;
  this->Intersections.MaxPages = 0i64;
  this->Intersections.NumPages = 0i64;
  this->Intersections.Size = 0i64;
  this->Intersections.Pages = 0i64;
  this->ContourNodes.MaxPages = 0i64;
  this->ContourNodes.NumPages = 0i64;
  this->ContourNodes.Size = 0i64;
  this->ContourNodes.Pages = 0i64;
  this->FanEdges.MaxPages = 0i64;
  this->FanEdges.NumPages = 0i64;
  this->FanEdges.Size = 0i64;
  this->FanEdges.Pages = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap);
}

// File Line: 103
// RVA: 0x9D6280
bool __fastcall Scaleform::Render::Hairliner::cmpMonoChains(
        Scaleform::Render::Tessellator::MonoChainType *a,
        Scaleform::Render::Tessellator::MonoChainType *b)
{
  float ySort; // xmm0_4
  float xb; // xmm1_4

  ySort = a->ySort;
  xb = b->ySort;
  if ( ySort == xb && (ySort = a->xb, xb = b->xb, ySort == xb) )
    return a->xt < b->xt;
  else
    return xb > ySort;
}

// File Line: 127
// RVA: 0x9D6310
bool __fastcall UFG::SectionChooser::fnSectionStreamPriority(
        UFG::SectionChooser::SectionLoad *a,
        UFG::SectionChooser::SectionLoad *b)
{
  return a->mScore < b->mScore;
}

// File Line: 133
// RVA: 0x9D6260
bool __fastcall Scaleform::Render::Hairliner::cmpEdges(
        Scaleform::Render::Hairliner::FanEdgeType *a,
        Scaleform::Render::Hairliner::FanEdgeType *b)
{
  bool v2; // cf

  v2 = a->node1 < b->node1;
  if ( a->node1 == b->node1 )
    return a->slope < b->slope;
  return v2;
}

// File Line: 177
// RVA: 0x9CF700
void __fastcall Scaleform::Render::Hairliner::buildEdgeList(
        Scaleform::Render::Hairliner *this,
        unsigned int start,
        unsigned int numEdges,
        int step)
{
  unsigned __int64 Size_low; // r13
  unsigned int v5; // edi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcEdgeType,4,16> *p_SrcEdges; // rbx
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // rcx
  unsigned __int64 v12; // rax
  char v13; // r9
  Scaleform::Render::Hairliner::SrcVertexType *v14; // r8
  unsigned __int64 v15; // rsi
  Scaleform::Render::Hairliner::SrcVertexType *v16; // rcx
  Scaleform::Render::Hairliner::SrcEdgeType *v17; // rdx
  __int64 v18; // r8
  Scaleform::Render::Hairliner::SrcEdgeType *v19; // rax
  Scaleform::Render::Hairliner::SrcVertexType **v20; // rdx
  unsigned __int64 v21; // rdi
  unsigned int lower; // r8d
  Scaleform::Render::Hairliner::SrcEdgeType *v23; // rsi
  Scaleform::Render::Hairliner::MonoChainType *v24; // rcx
  __int64 v25; // rdx
  unsigned __int64 v26; // [rsp+20h] [rbp-48h]
  __int64 v27; // [rsp+28h] [rbp-40h]
  __int64 v28; // [rsp+28h] [rbp-40h]
  __int64 slope_low; // [rsp+30h] [rbp-38h]
  __int64 v30; // [rsp+38h] [rbp-30h]

  Size_low = LODWORD(this->SrcEdges.Size);
  v5 = 0;
  if ( numEdges )
  {
    p_SrcEdges = &this->SrcEdges;
    do
    {
      Pages = this->SrcVertices.Pages;
      v12 = start;
      v13 = start;
      start += step;
      v26 = __PAIR64__(start, v12);
      v14 = Pages[v12 >> 4];
      v15 = p_SrcEdges->Size >> 4;
      v16 = Pages[(unsigned __int64)start >> 4];
      *(float *)&v27 = (float)(v16[start & 0xF].x - v14[v13 & 0xF].x) / (float)(v16[start & 0xF].y - v14[v13 & 0xF].y);
      if ( v15 >= p_SrcEdges->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcEdgeType,4,16>::allocPage(p_SrcEdges, v15);
      v17 = p_SrcEdges->Pages[v15];
      v18 = p_SrcEdges->Size & 0xF;
      *(_QWORD *)&v17[v18].lower = v26;
      *(_QWORD *)&v17[v18].slope = v27;
      v17[v18].next = 0i64;
      ++p_SrcEdges->Size;
      if ( v5 )
        this->SrcEdges.Pages[(this->SrcEdges.Size - 2) >> 4][(LODWORD(this->SrcEdges.Size) - 2) & 0xF].next = &p_SrcEdges->Pages[(p_SrcEdges->Size - 1) >> 4][((unsigned int)p_SrcEdges->Size - 1) & 0xF];
      ++v5;
    }
    while ( v5 < numEdges );
  }
  v19 = this->SrcEdges.Pages[Size_low >> 4];
  v20 = this->SrcVertices.Pages;
  v21 = this->MonoChains.Size >> 4;
  lower = v19[Size_low & 0xF].lower;
  v23 = &v19[Size_low & 0xF];
  LODWORD(v30) = -1;
  slope_low = LODWORD(v23->slope);
  *(float *)&v28 = v20[(unsigned __int64)lower >> 4][lower & 0xF].y;
  HIDWORD(v28) = LODWORD(v20[(unsigned __int64)lower >> 4][lower & 0xF].x);
  if ( v21 >= this->MonoChains.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType,4,8>::allocPage(&this->MonoChains, v21);
  v24 = this->MonoChains.Pages[v21];
  v25 = this->MonoChains.Size & 0xF;
  v24[v25].edge = v23;
  *(_QWORD *)&v24[v25].ySort = v28;
  *(_QWORD *)&v24[v25].xt = slope_low;
  *(_QWORD *)&v24[v25].prevVertex = v30;
  ++this->MonoChains.Size;
}

// File Line: 209
// RVA: 0x9614B0
void __fastcall Scaleform::Render::Hairliner::ClosePath(Scaleform::Render::Hairliner *this)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcVertexType,4,16> *p_SrcVertices; // rbx
  unsigned __int64 v2; // rdi
  Scaleform::Render::Hairliner::SrcVertexType *v3; // rsi

  p_SrcVertices = &this->SrcVertices;
  v2 = this->SrcVertices.Size >> 4;
  v3 = &this->SrcVertices.Pages[(unsigned __int64)this->LastVertex >> 4][this->LastVertex & 0xF];
  if ( v2 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices,
      v2);
  p_SrcVertices->Pages[v2][p_SrcVertices->Size & 0xF] = *v3;
  ++p_SrcVertices->Size;
}

// File Line: 216
// RVA: 0x978710
void __fastcall Scaleform::Render::Hairliner::FinalizePath(
        Scaleform::Render::Hairliner *this,
        unsigned int __formal,
        unsigned int a3,
        bool a4)
{
  unsigned __int64 LastVertex; // rcx
  unsigned int Size; // edx
  unsigned __int64 v7; // rsi
  Scaleform::Render::Hairliner::PathType v8; // [rsp+30h] [rbp+8h]

  LastVertex = this->LastVertex;
  Size = this->SrcVertices.Size;
  if ( Size >= (int)LastVertex + 2 )
  {
    v7 = this->Paths.Size >> 4;
    v8.start = LastVertex;
    v8.end = Size - 1;
    if ( v7 >= this->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::PathType,4,4>::allocPage(&this->Paths, v7);
    this->Paths.Pages[v7][this->Paths.Size & 0xF] = v8;
    ++this->Paths.Size;
    this->LastVertex = this->SrcVertices.Size;
  }
  else if ( LastVertex < this->SrcVertices.Size )
  {
    this->SrcVertices.Size = LastVertex;
  }
}

// File Line: 232
// RVA: 0x9DF130
void __fastcall Scaleform::Render::Hairliner::decomposePath(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Hairliner::PathType *path)
{
  signed int start; // ebp
  signed int end; // esi
  Scaleform::Render::ArrayPaged<unsigned int,4,16> *p_Scanbeams; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::Render::Hairliner *v6; // r15
  float y; // xmm8_4
  unsigned int v8; // r14d
  unsigned __int64 v9; // r13
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // rcx
  __int64 v11; // r15
  Scaleform::Render::Hairliner::SrcVertexType *v12; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v13; // r12
  float v14; // xmm9_4
  unsigned __int64 v15; // rdi
  float x; // xmm6_4
  float v17; // xmm7_4
  unsigned __int64 v18; // rdi
  __int64 v19; // rdx
  Scaleform::Render::Hairliner::HorizontalEdgeType *v20; // rax
  signed int i; // edi
  Scaleform::Render::Hairliner::SrcVertexType **v22; // r11
  float v23; // xmm0_4
  signed int v24; // r9d
  unsigned int v25; // ebx
  int j; // r10d
  signed int k; // edi
  Scaleform::Render::Hairliner::SrcVertexType **v28; // r11
  signed int v29; // r9d
  float v30; // xmm0_4
  __int64 v31; // rcx
  Scaleform::Render::Hairliner::SrcVertexType *v32; // rax
  unsigned int v33; // ebx
  int m; // r10d
  unsigned int v36; // [rsp+C8h] [rbp+10h]

  start = path->start;
  end = path->end;
  p_Scanbeams = &this->Scanbeams;
  v5 = this->Scanbeams.Size >> 4;
  v6 = this;
  v36 = path->start;
  y = this->SrcVertices.Pages[(unsigned __int64)(int)path->start >> 4][path->start & 0xF].y;
  if ( v5 >= this->Scanbeams.NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->Scanbeams,
      v5);
  v8 = start + 1;
  p_Scanbeams->Pages[v5][p_Scanbeams->Size & 0xF] = start;
  ++p_Scanbeams->Size;
  if ( start + 1 <= (unsigned int)end )
  {
    v9 = v8;
    do
    {
      Pages = this->SrcVertices.Pages;
      v11 = v9 & 0xF;
      v13 = Pages[v9 >> 4];
      v14 = v13[v11].y;
      if ( v14 == y )
      {
        v12 = Pages[(unsigned __int64)(v8 - 1) >> 4];
        x = v12[((_BYTE)v8 - 1) & 0xF].x;
        v17 = v13[v11].x;
        if ( x != v17 )
        {
          if ( x > v17 )
          {
            x = v13[v11].x;
            v17 = v12[((_BYTE)v8 - 1) & 0xF].x;
          }
          v18 = this->HorizontalEdges.Size >> 2;
          if ( v18 >= this->HorizontalEdges.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>::allocPage(
              &this->HorizontalEdges,
              this->HorizontalEdges.Size >> 2);
          v19 = this->HorizontalEdges.Size & 3;
          v20 = this->HorizontalEdges.Pages[v18];
          v20[v19].x1 = x;
          v20[v19].x2 = v17;
          v20[v19].y = v14;
          *(_QWORD *)&v20[v19].lv = -1i64;
          ++this->HorizontalEdges.Size;
        }
      }
      else
      {
        v15 = p_Scanbeams->Size >> 4;
        if ( v15 >= p_Scanbeams->NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)p_Scanbeams,
            p_Scanbeams->Size >> 4);
        p_Scanbeams->Pages[v15][p_Scanbeams->Size & 0xF] = v8;
        ++p_Scanbeams->Size;
        y = v13[v11].y;
      }
      ++v8;
      ++v9;
    }
    while ( v8 <= end );
    start = v36;
    v6 = this;
  }
  for ( i = start; i < end; ++i )
  {
    v22 = v6->SrcVertices.Pages;
    v23 = v22[(unsigned __int64)i >> 4][i & 0xF].y;
    if ( i > start )
    {
      if ( v23 <= v22[(unsigned __int64)(i - 1) >> 4][(i - 1) & 0xF].y )
      {
        v24 = i + 1;
        if ( v23 < v22[(unsigned __int64)(i + 1) >> 4][(i + 1) & 0xF].y )
        {
LABEL_23:
          v25 = 1;
          for ( j = v24 + 1;
                v24 < end && v22[(unsigned __int64)j >> 4][j & 0xF].y > v22[(unsigned __int64)v24 >> 4][v24 & 0xF].y;
                ++j )
          {
            ++v25;
            ++v24;
          }
          Scaleform::Render::Hairliner::buildEdgeList(v6, i, v25, 1);
          i = v25 + i - 1;
        }
      }
    }
    else
    {
      v24 = i + 1;
      if ( v23 < v22[(unsigned __int64)(i + 1) >> 4][(i + 1) & 0xF].y )
        goto LABEL_23;
    }
  }
  for ( k = end; k > start; --k )
  {
    v28 = v6->SrcVertices.Pages;
    v29 = k - 1;
    v30 = v28[(unsigned __int64)k >> 4][k & 0xF].y;
    v31 = (k - 1) & 0xF;
    v32 = v28[(unsigned __int64)(k - 1) >> 4];
    if ( k < end )
    {
      if ( v30 < v32[v31].y && v30 <= v28[(unsigned __int64)(k + 1) >> 4][(k + 1) & 0xF].y )
      {
LABEL_35:
        v33 = 1;
        for ( m = k - 2;
              v29 > start && v28[(unsigned __int64)m >> 4][m & 0xF].y > v28[(unsigned __int64)v29 >> 4][v29 & 0xF].y;
              --m )
        {
          ++v33;
          --v29;
        }
        Scaleform::Render::Hairliner::buildEdgeList(v6, k, v33, -1);
        k += 1 - v33;
      }
    }
    else if ( v30 < v32[v31].y )
    {
      goto LABEL_35;
    }
  }
}

// File Line: 317
// RVA: 0x9EA5A0
__int64 __fastcall Scaleform::Render::Hairliner::nextScanbeam(
        Scaleform::Render::Hairliner *this,
        float yb,
        float yt,
        unsigned int startMc,
        unsigned int numMc)
{
  __int64 v5; // r13
  unsigned int v6; // r15d
  unsigned __int64 v7; // r12
  unsigned __int64 v11; // rbp
  Scaleform::Render::Hairliner::MonoChainType *v12; // rbx
  Scaleform::Render::Hairliner::SrcEdgeType *edge; // r9
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // r10
  Scaleform::Render::Hairliner::SrcEdgeType *next; // rax
  unsigned int lower; // edx
  Scaleform::Render::Hairliner::SrcVertexType **v17; // rcx
  unsigned __int64 upper; // rax
  __int64 v19; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v20; // r9
  float x; // xmm0_4
  Scaleform::Render::Hairliner::SrcVertexType *v22; // rdx
  unsigned __int64 v23; // r14
  float xt; // eax
  __int64 v25; // rdx
  Scaleform::Render::Hairliner::SrcVertexType *v26; // rcx
  float v27; // xmm0_4
  Scaleform::Render::Hairliner::SrcEdgeType *v28; // r8
  unsigned int v29; // r9d
  unsigned __int64 v30; // rsi
  unsigned __int64 v31; // rbp
  __int64 v32; // r14
  Scaleform::Render::Hairliner::MonoChainType *v33; // r9
  Scaleform::Render::Hairliner::SrcEdgeType *v34; // r10
  __int64 v35; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v36; // r11
  float v37; // ecx
  float v38; // xmm0_4
  Scaleform::Render::Hairliner::SrcVertexType *v39; // rdx
  unsigned __int64 v40; // rsi
  unsigned __int64 Size; // r10
  unsigned int v42; // ebx
  unsigned __int64 v43; // r11
  int v44; // r12d
  unsigned __int64 v45; // rsi
  Scaleform::Render::Hairliner::MonoChainType ***v46; // r9
  Scaleform::Render::Hairliner::MonoChainType *v47; // r8
  float xb; // xmm1_4
  Scaleform::Render::Hairliner::MonoChainType *v49; // rdx
  float v50; // xmm0_4
  bool v51; // al
  Scaleform::Render::Hairliner::MonoChainType **v52; // rcx
  Scaleform::Render::Hairliner::MonoChainType *v53; // rax
  unsigned __int64 v54; // rsi
  unsigned __int64 v55; // rbp
  unsigned __int64 v56; // r10
  float v57; // xmm8_4
  int v58; // r15d
  int v59; // r9d
  unsigned int **v60; // rdx
  Scaleform::Render::Hairliner::MonoChainType ***v61; // r8
  __int64 v62; // rbp
  unsigned __int64 v63; // rax
  Scaleform::Render::Hairliner::MonoChainType *v64; // r12
  __int64 v65; // r14
  unsigned __int64 v66; // rax
  Scaleform::Render::Hairliner::MonoChainType *v67; // r13
  unsigned __int64 v68; // rbp
  unsigned __int64 v69; // rsi
  Scaleform::Render::Hairliner::MonoChainType **v70; // r15
  unsigned __int64 v71; // r14
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v74; // rbx
  unsigned __int64 v75; // rax
  float v76; // xmm2_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm0_4
  unsigned __int64 v80; // rsi
  unsigned __int64 v81; // rdx
  Scaleform::Render::LinearHeap *v82; // rcx
  void *v83; // rbx
  unsigned __int64 v84; // rax
  Scaleform::Render::Hairliner::IntersectionType *v85; // rdx
  __int64 v86; // r8
  unsigned int **v87; // rcx
  Scaleform::Render::Hairliner::MonoChainType ***v88; // rdx
  unsigned __int64 v89; // rax
  __int64 v90; // r10
  Scaleform::Render::Hairliner::MonoChainType **v91; // r8
  unsigned __int64 v92; // rax
  __int64 v93; // r9
  Scaleform::Render::Hairliner::MonoChainType **v94; // rdx
  Scaleform::Render::Hairliner::MonoChainType *v95; // rcx
  __int64 v97; // [rsp+20h] [rbp-B8h]
  __int64 v98; // [rsp+28h] [rbp-B0h]
  unsigned __int64 v99; // [rsp+30h] [rbp-A8h]
  unsigned __int64 v100; // [rsp+38h] [rbp-A0h]
  __int64 v101; // [rsp+50h] [rbp-88h]
  __int64 v102; // [rsp+E0h] [rbp+8h]
  int v103; // [rsp+E8h] [rbp+10h]
  int v104; // [rsp+F0h] [rbp+18h]
  unsigned int numMca; // [rsp+100h] [rbp+28h]

  v5 = numMc;
  v6 = 0;
  v7 = startMc;
  this->ValidChains.Size = 0i64;
  if ( numMc )
    v6 = 1;
  v11 = 0i64;
  v97 = 1i64;
  numMca = v6;
  if ( this->ActiveChains.Size )
  {
    do
    {
      v12 = this->ActiveChains.Pages[v11 >> 4][v11 & 0xF];
      v12->flags &= ~2u;
      edge = v12->edge;
      Pages = this->SrcVertices.Pages;
      if ( yb == Pages[(unsigned __int64)v12->edge->upper >> 4][v12->edge->upper & 0xF].y )
      {
        next = edge->next;
        if ( next )
        {
          v12->edge = next;
          lower = next->lower;
          v17 = this->SrcVertices.Pages;
          upper = next->upper;
          v19 = upper & 0xF;
          v20 = v17[upper >> 4];
          v12->xb = v17[(unsigned __int64)lower >> 4][lower & 0xF].x;
          if ( yt == v20[v19].y )
          {
            x = v20[v19].x;
          }
          else
          {
            v22 = this->SrcVertices.Pages[(unsigned __int64)v12->edge->lower >> 4];
            x = (float)((float)(yt - v22[v12->edge->lower & 0xF].y) * v12->edge->slope) + v22[v12->edge->lower & 0xF].x;
          }
          v12->xt = x;
          v23 = this->ValidChains.Size >> 4;
          if ( v23 >= this->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ValidChains,
              this->ValidChains.Size >> 4);
          this->ValidChains.Pages[v23][this->ValidChains.Size & 0xF] = v11;
          ++this->ValidChains.Size;
          v12->flags |= 2u;
        }
        else
        {
          xt = v12->xt;
          v12->flags |= 1u;
          v6 |= 2u;
          v12->flags |= 2u;
          v12->xb = xt;
        }
      }
      else
      {
        v25 = v12->edge->upper & 0xF;
        v26 = Pages[(unsigned __int64)v12->edge->upper >> 4];
        v12->xb = v12->xt;
        if ( yt == v26[v25].y )
        {
          v27 = v26[v25].x;
        }
        else
        {
          v28 = edge;
          v29 = edge->lower;
          v27 = (float)((float)(yt - this->SrcVertices.Pages[(unsigned __int64)v29 >> 4][v29 & 0xF].y) * v28->slope)
              + this->SrcVertices.Pages[(unsigned __int64)v29 >> 4][v29 & 0xF].x;
        }
        v12->xt = v27;
        v30 = this->ValidChains.Size >> 4;
        if ( v30 >= this->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ValidChains,
            this->ValidChains.Size >> 4);
        this->ValidChains.Pages[v30][this->ValidChains.Size & 0xF] = v11;
        ++this->ValidChains.Size;
      }
      ++v11;
    }
    while ( v11 < this->ActiveChains.Size );
    numMca = v6;
  }
  if ( (_DWORD)v5 )
  {
    v31 = v7;
    v32 = v5;
    do
    {
      v33 = this->MonoChainsSorted.Pages[v31 >> 4][v31 & 0xF];
      v34 = v33->edge;
      v35 = v33->edge->lower & 0xF;
      v36 = this->SrcVertices.Pages[(unsigned __int64)v33->edge->lower >> 4];
      v37 = v36[v35].x;
      v33->flags = 2;
      v33->xb = v37;
      if ( yt == v36[v35].y )
      {
        v38 = v36[v35].x;
      }
      else
      {
        v39 = this->SrcVertices.Pages[(unsigned __int64)v34->lower >> 4];
        v38 = (float)((float)(yt - v39[v34->lower & 0xF].y) * v34->slope) + v39[v34->lower & 0xF].x;
      }
      v33->xt = v38;
      v40 = this->ActiveChains.Size >> 4;
      if ( v40 >= this->ActiveChains.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->ActiveChains,
          this->ActiveChains.Size >> 4);
      ++v31;
      this->ActiveChains.Pages[v40][this->ActiveChains.Size & 0xF] = 0i64;
      ++this->ActiveChains.Size;
      --v32;
    }
    while ( v32 );
    Size = this->ActiveChains.Size;
    v42 = v7 + v5;
    v43 = Size - v5;
    v44 = -(int)v7;
    v45 = Size - v5 - 1;
    do
    {
      if ( !v43
        || ((v46 = this->ActiveChains.Pages,
             v47 = this->MonoChainsSorted.Pages[(unsigned __int64)(v42 - 1) >> 4][((_BYTE)v42 - 1) & 0xF],
             xb = v47->xb,
             v49 = v46[v45 >> 4][v45 & 0xF],
             v50 = v49->xb,
             v50 == xb)
          ? (v51 = v49->xt < v47->xt)
          : (v51 = xb > v50),
            v51) )
      {
        --v42;
        v52 = this->ActiveChains.Pages[--Size >> 4];
        v53 = this->MonoChainsSorted.Pages[(unsigned __int64)v42 >> 4][v42 & 0xF];
      }
      else
      {
        --v43;
        --Size;
        --v45;
        v52 = v46[Size >> 4];
        v53 = v46[v43 >> 4][v43 & 0xF];
      }
      v52[Size & 0xF] = v53;
    }
    while ( v44 + v42 );
    v6 = numMca;
  }
  this->Intersections.Size = 0i64;
  if ( (v6 & 1) != 0 )
  {
    v54 = 0i64;
    for ( this->ValidChains.Size = 0i64; v54 < this->ActiveChains.Size; ++v54 )
    {
      if ( (this->ActiveChains.Pages[v54 >> 4][v54 & 0xF]->flags & 1) == 0 )
      {
        v55 = this->ValidChains.Size >> 4;
        if ( v55 >= this->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ValidChains,
            this->ValidChains.Size >> 4);
        this->ValidChains.Pages[v55][this->ValidChains.Size & 0xF] = v54;
        ++this->ValidChains.Size;
      }
    }
  }
  v56 = 1i64;
  v57 = yt - yb;
  if ( this->ValidChains.Size <= 1 )
    return v6;
  do
  {
    v58 = v56 - 1;
    v103 = v56 - 1;
    if ( (int)v56 - 1 >= 0 )
    {
      v59 = v56;
      v104 = v56;
      do
      {
        v60 = this->ValidChains.Pages;
        v61 = this->ActiveChains.Pages;
        v62 = v58 & 0xF;
        v102 = v62;
        v100 = (unsigned __int64)v58 >> 4;
        v63 = v60[v100][v62];
        v64 = v61[v63 >> 4][v63 & 0xF];
        v65 = v59 & 0xF;
        v98 = v65;
        v99 = (unsigned __int64)v59 >> 4;
        v66 = v60[v99][v65];
        v67 = v61[v66 >> 4][v66 & 0xF];
        if ( v67->xt >= v64->xt )
          break;
        if ( !this->Intersections.Size )
        {
          v68 = 0i64;
          this->ChainsAtBottom.Size = 0i64;
          if ( this->ActiveChains.Size )
          {
            do
            {
              v69 = this->ChainsAtBottom.Size >> 4;
              v70 = this->ActiveChains.Pages[v68 >> 4];
              v71 = v68 & 0xF;
              if ( v69 >= this->ChainsAtBottom.NumPages )
              {
                MaxPages = this->ChainsAtBottom.MaxPages;
                if ( v69 >= MaxPages )
                {
                  pHeap = this->ChainsAtBottom.pHeap;
                  if ( this->ChainsAtBottom.Pages )
                  {
                    v74 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
                    memmove(v74, this->ChainsAtBottom.Pages, 8 * this->ChainsAtBottom.NumPages);
                    v75 = this->ChainsAtBottom.MaxPages;
                    this->ChainsAtBottom.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)v74;
                    this->ChainsAtBottom.MaxPages = 2 * v75;
                  }
                  else
                  {
                    this->ChainsAtBottom.MaxPages = 8i64;
                    this->ChainsAtBottom.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)Scaleform::Render::LinearHeap::Alloc(
                                                                                                    pHeap,
                                                                                                    0x40ui64);
                  }
                }
                this->ChainsAtBottom.Pages[v69] = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                                    this->ChainsAtBottom.pHeap,
                                                                                                    0x80ui64);
                ++this->ChainsAtBottom.NumPages;
              }
              ++v68;
              this->ChainsAtBottom.Pages[v69][this->ChainsAtBottom.Size & 0xF] = v70[v71];
              ++this->ChainsAtBottom.Size;
            }
            while ( v68 < this->ActiveChains.Size );
            v65 = v98;
            v58 = v103;
          }
          v62 = v102;
        }
        v76 = v67->xb;
        v77 = v64->xb;
        v78 = (float)((float)(v67->xt - v76) - v64->xt) + v77;
        if ( v78 != 0.0 )
        {
          v79 = (float)((float)((float)(v77 - v76) * v57) / v78) + yb;
          *(float *)&v101 = v79;
          if ( v79 >= yb )
            continue;
        }
        v79 = yb;
        *(float *)&v101 = yb;
        if ( v79 > yt )
          *(float *)&v101 = yt;
        v80 = this->Intersections.Size >> 4;
        if ( v80 >= this->Intersections.NumPages )
        {
          v81 = this->Intersections.MaxPages;
          if ( v80 >= v81 )
          {
            v82 = this->Intersections.pHeap;
            if ( this->Intersections.Pages )
            {
              v83 = Scaleform::Render::LinearHeap::Alloc(v82, 16 * v81);
              memmove(v83, this->Intersections.Pages, 8 * this->Intersections.NumPages);
              v84 = this->Intersections.MaxPages;
              this->Intersections.Pages = (Scaleform::Render::Hairliner::IntersectionType **)v83;
              this->Intersections.MaxPages = 2 * v84;
            }
            else
            {
              this->Intersections.MaxPages = 4i64;
              this->Intersections.Pages = (Scaleform::Render::Hairliner::IntersectionType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                               v82,
                                                                                               0x20ui64);
            }
          }
          this->Intersections.Pages[v80] = (Scaleform::Render::Hairliner::IntersectionType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                               this->Intersections.pHeap,
                                                                                               0x180ui64);
          ++this->Intersections.NumPages;
        }
        --v58;
        v85 = this->Intersections.Pages[v80];
        v103 = v58;
        v86 = this->Intersections.Size & 0xF;
        v85[v86].mc1 = v64;
        v85[v86].mc2 = v67;
        *(_QWORD *)&v85[v86].y = v101;
        ++this->Intersections.Size;
        v87 = this->ValidChains.Pages;
        v88 = this->ActiveChains.Pages;
        v89 = v87[v99][v65];
        v90 = v89 & 0xF;
        v91 = v88[v89 >> 4];
        v92 = v87[v100][v62];
        v93 = v92 & 0xF;
        v94 = v88[v92 >> 4];
        v95 = v94[v93];
        v94[v93] = v91[v90];
        v59 = v104 - 1;
        v91[v90] = v95;
        --v104;
      }
      while ( v58 >= 0 );
      v56 = v97;
    }
    v97 = ++v56;
  }
  while ( v56 < this->ValidChains.Size );
  return numMca;
}

// File Line: 480
// RVA: 0x9C6950
__int64 __fastcall Scaleform::Render::Hairliner::addEventVertex(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Hairliner::SrcVertexType *v1)
{
  float x; // xmm6_4
  float y; // xmm7_4
  unsigned __int64 v5; // rsi
  __int64 v6; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v7; // rax

  if ( this->LastY != v1->y || this->LastX != v1->x )
  {
    *(Scaleform::Render::Hairliner::SrcVertexType *)&this->LastX = *v1;
    x = v1->x;
    y = v1->y;
    v5 = this->OutVertices.Size >> 4;
    if ( v5 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v6 = this->OutVertices.Size & 0xF;
    v7 = this->OutVertices.Pages[v5];
    v7[v6].x = x;
    v7[v6].y = y;
    v7[v6].alpha = 1;
    ++this->OutVertices.Size;
  }
  return (unsigned int)(LODWORD(this->OutVertices.Size) - 1);
}

// File Line: 495
// RVA: 0x9C6A20
__int64 __fastcall Scaleform::Render::Hairliner::addEventVertex(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Hairliner::MonoChainType *mc,
        float yb,
        bool enforce)
{
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // r8
  unsigned __int64 lower; // rdx
  Scaleform::Render::Hairliner::SrcVertexType **v8; // r9
  Scaleform::Render::Hairliner::SrcEdgeType *edge; // r9
  float v10; // xmm7_4
  unsigned __int64 v11; // rsi
  __int64 v12; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v13; // rax

  if ( enforce )
  {
    if ( (mc->flags & 1) != 0
      && (v8 = this->SrcVertices.Pages, yb == v8[(unsigned __int64)mc->edge->upper >> 4][mc->edge->upper & 0xF].y) )
    {
      return Scaleform::Render::Hairliner::addEventVertex(
               this,
               &v8[(unsigned __int64)mc->edge->upper >> 4][mc->edge->upper & 0xF]);
    }
    else
    {
      edge = mc->edge;
      Pages = this->SrcVertices.Pages;
      lower = mc->edge->lower;
      if ( yb == Pages[(unsigned __int64)(unsigned int)lower >> 4][lower & 0xF].y )
        return Scaleform::Render::Hairliner::addEventVertex(this, &Pages[lower >> 4][lower & 0xF]);
      v10 = (float)((float)(yb - Pages[(unsigned __int64)edge->lower >> 4][edge->lower & 0xF].y) * edge->slope)
          + Pages[(unsigned __int64)edge->lower >> 4][edge->lower & 0xF].x;
      if ( yb != this->LastY || COERCE_FLOAT(COERCE_UNSIGNED_INT(v10 - this->LastX) & _xmm) > this->Epsilon )
      {
        this->LastX = v10;
        this->LastY = yb;
        v11 = this->OutVertices.Size >> 4;
        if ( v11 >= this->OutVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
            v11);
        v12 = this->OutVertices.Size & 0xF;
        v13 = this->OutVertices.Pages[v11];
        v13[v12].x = v10;
        v13[v12].y = yb;
        v13[v12].alpha = 1;
        ++this->OutVertices.Size;
      }
      return (unsigned int)(LODWORD(this->OutVertices.Size) - 1);
    }
  }
  else
  {
    if ( (mc->flags & 2) != 0 )
    {
      Pages = this->SrcVertices.Pages;
      lower = mc->edge->lower;
      if ( yb == Pages[(unsigned __int64)(unsigned int)lower >> 4][lower & 0xF].y )
        return Scaleform::Render::Hairliner::addEventVertex(this, &Pages[lower >> 4][lower & 0xF]);
    }
    return 0xFFFFFFFFi64;
  }
}

// File Line: 571
// RVA: 0x9E0550
void __fastcall Scaleform::Render::Hairliner::emitEdge(
        Scaleform::Render::Hairliner *this,
        unsigned int v1,
        unsigned int v2)
{
  Scaleform::Render::Hairliner::OutVertexType **Pages; // rcx
  __int64 v6; // r9
  float v7; // xmm6_4
  Scaleform::Render::Hairliner::OutVertexType *v8; // r8
  __int64 v9; // r11
  Scaleform::Render::Hairliner::OutVertexType *v11; // rcx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *p_FanEdges; // rbx
  unsigned __int64 v17; // rdi
  __int64 v18; // rdx
  Scaleform::Render::StrokerAA::VertexType *v19; // rax
  float v20; // xmm6_4
  unsigned __int64 v21; // rdi
  __int64 v22; // rdx
  Scaleform::Render::StrokerAA::VertexType *v23; // rax

  Pages = this->OutVertices.Pages;
  v6 = v2 & 0xF;
  v7 = 0.0;
  v8 = Pages[(unsigned __int64)v2 >> 4];
  v9 = v1 & 0xF;
  v11 = Pages[(unsigned __int64)v1 >> 4];
  v12 = v8[v6].x - v11[v9].x;
  v13 = v8[v6].y - v11[v9].y;
  v14 = (float)((float)(v13 * v13) + (float)(v12 * v12)) * 2.0;
  if ( v14 != 0.0 )
  {
    v15 = (float)(v12 * v12) / v14;
    if ( v12 < 0.0 )
      LODWORD(v15) ^= _xmm[0];
    if ( v13 > 0.0 )
      v15 = 1.0 - v15;
    v7 = v15 - 0.5;
  }
  p_FanEdges = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->FanEdges;
  v17 = p_FanEdges->Size >> 4;
  if ( v17 >= p_FanEdges->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(p_FanEdges, p_FanEdges->Size >> 4);
  v18 = p_FanEdges->Size & 0xF;
  v19 = p_FanEdges->Pages[v17];
  LODWORD(v19[v18].x) = v1;
  LODWORD(v19[v18].y) = v2;
  *(float *)&v19[v18].style = v7;
  ++p_FanEdges->Size;
  v20 = v7 - 1.0;
  if ( v20 < -1.0 )
    v20 = v20 + 2.0;
  v21 = p_FanEdges->Size >> 4;
  if ( v21 >= p_FanEdges->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(p_FanEdges, p_FanEdges->Size >> 4);
  v22 = p_FanEdges->Size & 0xF;
  v23 = p_FanEdges->Pages[v21];
  LODWORD(v23[v22].x) = v2;
  LODWORD(v23[v22].y) = v1;
  *(float *)&v23[v22].style = v20;
  ++p_FanEdges->Size;
}

// File Line: 609
// RVA: 0x9ED2F0
__int64 __fastcall Scaleform::Render::Hairliner::processHorizontalEdges(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Hairliner::MonoChainType *mc,
        unsigned int vertex,
        float yb)
{
  unsigned int v4; // r14d
  char v5; // r15
  float x; // xmm6_4
  Scaleform::Render::Hairliner::HorizontalEdgeType *v10; // rsi
  __int64 v11; // rdx
  __int64 v12; // rdi
  unsigned int rv; // r9d
  unsigned int v14; // edx
  Scaleform::Render::Hairliner::SrcEdgeType *edge; // r10
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // r11
  unsigned __int64 lower; // rax
  __int64 v18; // rdx
  Scaleform::Render::Hairliner::SrcVertexType *v19; // r9
  unsigned __int64 upper; // rax
  __int64 v21; // rcx
  Scaleform::Render::Hairliner::SrcVertexType *v22; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v23; // rcx
  float x1; // xmm0_4
  bool v25; // zf
  Scaleform::Render::Hairliner::SrcVertexType v27; // [rsp+20h] [rbp-58h] BYREF
  Scaleform::Render::Hairliner::SrcVertexType v1; // [rsp+80h] [rbp+8h] BYREF

  v4 = 0;
  v5 = 0;
  x = 0.0;
  while ( v4 < this->NumHorizontals )
  {
    v10 = this->HorizontalEdges.Pages[(unsigned __int64)(v4 + this->StartHorizontals) >> 2];
    v11 = ((_BYTE)v4 + LOBYTE(this->StartHorizontals)) & 3;
    v12 = v11;
    if ( vertex == -1 )
      goto LABEL_10;
    rv = v10[v11].rv;
    if ( rv == -1 && this->OutVertices.Pages[(unsigned __int64)vertex >> 4][vertex & 0xF].x == v10[v11].x1 )
    {
      v10[v11].rv = vertex;
LABEL_29:
      v10[v12].lv = vertex;
      goto LABEL_30;
    }
    if ( this->OutVertices.Pages[(unsigned __int64)vertex >> 4][vertex & 0xF].x != v10[v11].x2 )
    {
LABEL_10:
      if ( !v5 )
      {
        edge = mc->edge;
        Pages = this->SrcVertices.Pages;
        lower = mc->edge->lower;
        v18 = lower & 0xF;
        v19 = Pages[lower >> 4];
        upper = mc->edge->upper;
        v21 = upper & 0xF;
        v22 = Pages[upper >> 4];
        if ( yb == v19[v18].y )
        {
          x = v19[v18].x;
        }
        else if ( yb == v22[v21].y )
        {
          x = v22[v21].x;
        }
        else
        {
          v23 = Pages[(unsigned __int64)edge->lower >> 4];
          x = (float)((float)(yb - v23[edge->lower & 0xF].y) * edge->slope) + v23[edge->lower & 0xF].x;
        }
        v5 = 1;
      }
      x1 = v10[v12].x1;
      if ( x == x1 )
      {
        v1.x = x;
        v1.y = yb;
        if ( vertex == -1 )
          vertex = Scaleform::Render::Hairliner::addEventVertex(this, &v1);
        v10[v12].rv = vertex;
        goto LABEL_30;
      }
      if ( x < x1 || x > v10[v12].x2 )
        goto LABEL_30;
      v27.x = x;
      v27.y = yb;
      if ( vertex == -1 )
        vertex = Scaleform::Render::Hairliner::addEventVertex(this, &v27);
      v14 = v10[v12].rv;
      if ( v14 != -1 && v14 != vertex )
        goto LABEL_27;
    }
    else if ( rv != -1 && rv != vertex )
    {
      v14 = v10[v11].rv;
LABEL_27:
      Scaleform::Render::Hairliner::emitEdge(this, v14, vertex);
    }
    v25 = v10[v12].lv == -1;
    v10[v12].rv = vertex;
    if ( v25 )
      goto LABEL_29;
LABEL_30:
    ++v4;
  }
  return vertex;
}

// File Line: 659
// RVA: 0x9F3CF0
void __fastcall Scaleform::Render::Hairliner::sweepScanbeam(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8> *aet,
        float yb)
{
  unsigned __int64 v3; // r15
  unsigned __int64 i; // rsi
  Scaleform::Render::Hairliner::MonoChainType *v7; // rbp
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned int prevVertex; // edx
  unsigned __int64 v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // rdi
  Scaleform::Render::Hairliner::HorizontalEdgeType *v14; // rsi
  unsigned int lv; // eax
  float x1; // xmm7_4
  unsigned __int64 v17; // r14
  __int64 v18; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v19; // rax
  unsigned int rv; // eax
  float x2; // xmm7_4
  unsigned __int64 v22; // r14
  __int64 v23; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v24; // rax
  float v25; // xmm8_4
  float v26; // xmm7_4
  unsigned __int64 v27; // rsi
  __int64 v28; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v29; // rax
  unsigned __int64 Size; // rbp
  __int64 v31; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v32; // rax

  v3 = 0i64;
  for ( i = 0i64; i < aet->Size; ++i )
  {
    v7 = aet->Pages[i >> 4][i & 0xF];
    v8 = Scaleform::Render::Hairliner::addEventVertex(this, v7, yb, v7->flags & 1);
    v9 = v8;
    if ( this->NumHorizontals )
      v9 = Scaleform::Render::Hairliner::processHorizontalEdges(this, v7, v8, yb);
    if ( v9 != -1 )
    {
      prevVertex = v7->prevVertex;
      if ( prevVertex != -1 && prevVertex != v9 )
        Scaleform::Render::Hairliner::emitEdge(this, prevVertex, v9);
      v7->prevVertex = v9;
    }
  }
  if ( this->NumHorizontals )
  {
    do
    {
      v11 = v3 + this->StartHorizontals;
      v12 = v11 & 3;
      v13 = v12;
      v14 = this->HorizontalEdges.Pages[v11 >> 2];
      lv = v14[v12].lv;
      if ( lv != -1 )
      {
        x1 = v14[v12].x1;
        if ( x1 != this->OutVertices.Pages[(unsigned __int64)lv >> 4][lv & 0xF].x )
        {
          if ( yb != this->LastY || x1 != this->LastX )
          {
            this->LastX = x1;
            this->LastY = yb;
            v17 = this->OutVertices.Size >> 4;
            if ( v17 >= this->OutVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
                v17);
            v18 = this->OutVertices.Size & 0xF;
            v19 = this->OutVertices.Pages[v17];
            v19[v18].x = x1;
            v19[v18].y = yb;
            v19[v18].alpha = 1;
            ++this->OutVertices.Size;
          }
          Scaleform::Render::Hairliner::emitEdge(this, v14[v13].lv, LODWORD(this->OutVertices.Size) - 1);
        }
      }
      rv = v14[v13].rv;
      if ( rv != -1 )
      {
        x2 = v14[v13].x2;
        if ( x2 != this->OutVertices.Pages[(unsigned __int64)rv >> 4][rv & 0xF].x )
        {
          if ( yb != this->LastY || x2 != this->LastX )
          {
            this->LastX = x2;
            this->LastY = yb;
            v22 = this->OutVertices.Size >> 4;
            if ( v22 >= this->OutVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
                v22);
            v23 = this->OutVertices.Size & 0xF;
            v24 = this->OutVertices.Pages[v22];
            v24[v23].x = x2;
            v24[v23].y = yb;
            v24[v23].alpha = 1;
            ++this->OutVertices.Size;
          }
          Scaleform::Render::Hairliner::emitEdge(this, v14[v13].rv, LODWORD(this->OutVertices.Size) - 1);
        }
      }
      if ( v14[v13].lv == -1 && v14[v13].rv == -1 )
      {
        v25 = v14[v13].x1;
        v26 = v14[v13].x2;
        if ( yb != this->LastY || v26 != this->LastX )
        {
          this->LastX = v26;
          this->LastY = yb;
          v27 = this->OutVertices.Size >> 4;
          if ( v27 >= this->OutVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
              v27);
          v28 = this->OutVertices.Size & 0xF;
          v29 = this->OutVertices.Pages[v27];
          v29[v28].x = v26;
          v29[v28].y = yb;
          v29[v28].alpha = 1;
          ++this->OutVertices.Size;
        }
        Size = this->OutVertices.Size;
        if ( yb != this->LastY || v25 != this->LastX )
        {
          this->LastX = v25;
          this->LastY = yb;
          if ( Size >> 4 >= this->OutVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
              Size >> 4);
          v31 = this->OutVertices.Size & 0xF;
          v32 = this->OutVertices.Pages[Size >> 4];
          v32[v31].x = v25;
          v32[v31].y = yb;
          v32[v31].alpha = 1;
          ++this->OutVertices.Size;
        }
        Scaleform::Render::Hairliner::emitEdge(this, LODWORD(this->OutVertices.Size) - 1, Size - 1);
      }
      ++v3;
    }
    while ( v3 < this->NumHorizontals );
  }
}

// File Line: 703
// RVA: 0x9ED520
void __fastcall Scaleform::Render::Hairliner::processInterior(Scaleform::Render::Hairliner *this, float yb)
{
  unsigned __int64 i; // rdi
  __int64 v4; // rax
  Scaleform::Render::Hairliner::IntersectionType *v5; // r14
  __int64 v6; // rbp
  float y; // xmm2_4
  unsigned int v8; // eax
  Scaleform::Render::Hairliner::MonoChainType *mc1; // r15
  unsigned int prevVertex; // edx
  unsigned int v11; // esi
  unsigned int v12; // eax
  Scaleform::Render::Hairliner::MonoChainType *mc2; // rbp
  unsigned int v14; // edx
  unsigned int v15; // esi

  Scaleform::Render::Hairliner::sweepScanbeam(this, &this->ChainsAtBottom, yb);
  for ( i = 0i64; i < this->Intersections.Size; ++i )
  {
    v4 = i & 0xF;
    v5 = this->Intersections.Pages[i >> 4];
    v6 = v4;
    y = v5[v4].y;
    if ( y > yb )
    {
      v8 = Scaleform::Render::Hairliner::addEventVertex(this, v5[v4].mc1, y, 1);
      mc1 = v5[v6].mc1;
      prevVertex = mc1->prevVertex;
      v11 = v8;
      if ( prevVertex != -1 && prevVertex != v8 )
        Scaleform::Render::Hairliner::emitEdge(this, prevVertex, v8);
      mc1->prevVertex = v11;
      v12 = Scaleform::Render::Hairliner::addEventVertex(this, v5[v6].mc2, v5[v6].y, 1);
      mc2 = v5[v6].mc2;
      v14 = mc2->prevVertex;
      v15 = v12;
      if ( v14 != -1 && v14 != v12 )
        Scaleform::Render::Hairliner::emitEdge(this, v14, v12);
      mc2->prevVertex = v15;
    }
  }
}

// File Line: 720
// RVA: 0x9CFB80
void __fastcall Scaleform::Render::Hairliner::buildGraph(Scaleform::Render::Hairliner *this)
{
  unsigned __int64 v2; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *p_Scanbeams; // rbx
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // r8
  float i; // xmm2_4
  unsigned int **Pages; // rbx
  __int64 v9; // r9
  Scaleform::Render::Hairliner::SrcVertexType *v10; // r10
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rcx
  unsigned __int64 j; // rbx
  unsigned __int64 k; // r14
  unsigned __int64 v15; // rbp
  Scaleform::Render::Hairliner::MonoChainType *v16; // rsi
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v19; // rbx
  unsigned __int64 v20; // rax
  unsigned int v21; // ebp
  unsigned int v22; // r13d
  unsigned int v23; // r14d
  unsigned __int64 v24; // rcx
  float y; // xmm7_4
  float v26; // xmm6_4
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // rsi
  unsigned __int64 Size; // rdx
  unsigned int v30; // r9d
  unsigned __int64 v31; // r8
  char Scanbeam; // r15
  unsigned int v33; // edx
  unsigned int v34; // r10d
  unsigned __int64 v35; // rcx
  Scaleform::Render::Hairliner::MonoChainType ***v36; // r8
  Scaleform::Render::Hairliner::MonoChainType *v37; // r9
  unsigned __int64 v38; // rax
  __int64 v39; // rcx

  if ( this->SrcVertices.Size )
  {
    v2 = 0i64;
    p_Scanbeams = (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->Scanbeams;
    do
    {
      v4 = p_Scanbeams->Size >> 4;
      if ( v4 >= p_Scanbeams->NumPages )
        Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(p_Scanbeams, p_Scanbeams->Size >> 4);
      p_Scanbeams->Pages[v4][p_Scanbeams->Size & 0xF] = (Scaleform::Render::GlyphFitter::VertexType)v2;
      ++p_Scanbeams->Size;
      ++v2;
    }
    while ( v2 < this->SrcVertices.Size );
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
      &this->Scanbeams,
      0i64,
      this->Scanbeams.Size,
      (Scaleform::Render::Tessellator::CmpScanbeams)&this->SrcVertices);
    v5 = 0i64;
    v6 = 0i64;
    for ( i = FLOAT_N1_0e30; v5 < this->Scanbeams.Size; ++v5 )
    {
      Pages = this->Scanbeams.Pages;
      v9 = Pages[v5 >> 4][v5 & 0xF] & 0xF;
      v10 = this->SrcVertices.Pages[(unsigned __int64)Pages[v5 >> 4][v5 & 0xF] >> 4];
      if ( (float)(v10[v9].y - i) <= (float)(COERCE_FLOAT(LODWORD(v10[v9].y) & _xmm) * this->Epsilon) )
      {
        v10[v9].y = i;
      }
      else
      {
        v11 = v6 >> 4;
        v12 = v6++ & 0xF;
        Pages[v11][v12] = Pages[v5 >> 4][v5 & 0xF];
        i = v10[v9].y;
      }
    }
    if ( v6 < this->Scanbeams.Size )
      this->Scanbeams.Size = v6;
    for ( j = 0i64; j < this->Paths.Size; ++j )
      Scaleform::Render::Hairliner::decomposePath(this, &this->Paths.Pages[j >> 4][j & 0xF]);
    for ( k = 0i64; k < this->MonoChains.Size; ++this->MonoChainsSorted.Size )
    {
      v15 = this->MonoChainsSorted.Size >> 4;
      v16 = &this->MonoChains.Pages[k >> 4][k & 0xF];
      if ( v15 >= this->MonoChainsSorted.NumPages )
      {
        MaxPages = this->MonoChainsSorted.MaxPages;
        if ( v15 >= MaxPages )
        {
          pHeap = this->MonoChainsSorted.pHeap;
          if ( this->MonoChainsSorted.Pages )
          {
            v19 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
            memmove(v19, this->MonoChainsSorted.Pages, 8 * this->MonoChainsSorted.NumPages);
            v20 = this->MonoChainsSorted.MaxPages;
            this->MonoChainsSorted.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)v19;
            this->MonoChainsSorted.MaxPages = 2 * v20;
          }
          else
          {
            this->MonoChainsSorted.MaxPages = 8i64;
            this->MonoChainsSorted.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)Scaleform::Render::LinearHeap::Alloc(
                                                                                              pHeap,
                                                                                              0x40ui64);
          }
        }
        this->MonoChainsSorted.Pages[v15] = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                              this->MonoChainsSorted.pHeap,
                                                                                              0x80ui64);
        ++this->MonoChainsSorted.NumPages;
      }
      ++k;
      this->MonoChainsSorted.Pages[v15][this->MonoChainsSorted.Size & 0xF] = v16;
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>,bool (*)(Scaleform::Render::Hairliner::HorizontalEdgeType const &,Scaleform::Render::Hairliner::HorizontalEdgeType const &)>(
      &this->HorizontalEdges,
      0i64,
      this->HorizontalEdges.Size,
      (bool (__fastcall *)(Scaleform::Render::Hairliner::HorizontalEdgeType *, Scaleform::Render::Hairliner::HorizontalEdgeType *))UFG::SectionChooser::fnSectionStreamPriority);
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>,bool (*)(Scaleform::Render::Hairliner::MonoChainType const *,Scaleform::Render::Hairliner::MonoChainType const *)>(
      &this->MonoChainsSorted,
      0i64,
      this->MonoChainsSorted.Size,
      (bool (__fastcall *)(Scaleform::Render::Hairliner::MonoChainType *, Scaleform::Render::Hairliner::MonoChainType *))Scaleform::Render::Hairliner::cmpMonoChains);
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v24 = **this->Scanbeams.Pages;
    y = this->SrcVertices.Pages[v24 >> 4][v24 & 0xF].y;
    this->LastX = -1.0e30;
    this->LastY = -1.0e30;
    v26 = y;
    if ( this->Scanbeams.Size )
    {
      v27 = 0i64;
      v28 = 0i64;
      do
      {
        if ( ++v22 < this->Scanbeams.Size )
          y = this->SrcVertices.Pages[(unsigned __int64)this->Scanbeams.Pages[(unsigned __int64)v22 >> 4][v22 & 0xF] >> 4][this->Scanbeams.Pages[(unsigned __int64)v22 >> 4][v22 & 0xF] & 0xF].y;
        Size = this->MonoChainsSorted.Size;
        v30 = v21;
        if ( v27 < Size )
        {
          do
          {
            if ( v26 < this->MonoChainsSorted.Pages[v27 >> 4][v27 & 0xF]->ySort )
              break;
            v27 = ++v21;
          }
          while ( v21 < Size );
        }
        v31 = this->HorizontalEdges.Size;
        this->StartHorizontals = v23;
        if ( v28 < v31 )
        {
          do
          {
            if ( v26 < this->HorizontalEdges.Pages[v28 >> 2][v28 & 3].y )
              break;
            v28 = ++v23;
          }
          while ( v23 < v31 );
        }
        this->NumHorizontals = v23 - this->StartHorizontals;
        Scanbeam = Scaleform::Render::Hairliner::nextScanbeam(this, v26, y, v30, v21 - v30);
        if ( this->Intersections.Size )
          Scaleform::Render::Hairliner::processInterior(this, v26);
        else
          Scaleform::Render::Hairliner::sweepScanbeam(this, &this->ActiveChains, v26);
        if ( (Scanbeam & 2) != 0 )
        {
          v33 = 0;
          v34 = 0;
          if ( this->ActiveChains.Size )
          {
            v35 = 0i64;
            do
            {
              v36 = this->ActiveChains.Pages;
              v37 = v36[v35 >> 4][v35 & 0xF];
              if ( (v37->flags & 1) == 0 )
              {
                v38 = (unsigned __int64)v34 >> 4;
                v39 = v34++ & 0xF;
                v36[v38][v39] = v37;
              }
              v35 = ++v33;
            }
            while ( v33 < this->ActiveChains.Size );
          }
          if ( v34 < this->ActiveChains.Size )
            this->ActiveChains.Size = v34;
        }
        v26 = y;
      }
      while ( v22 < this->Scanbeams.Size );
    }
  }
}
          }
          if ( v34 < this->ActiveChains.Size )
            this->ActiveChains.Size = v34;
        }
        v26 = y;
      }
      while ( v22 < this->Scanbeams.Siz

// File Line: 829
// RVA: 0x9E3E80
void __fastcall Scaleform::Render::Hairliner::generateContourAA(
        Scaleform::Render::Hairliner *this,
        unsigned int startEdgeIdx)
{
  float x; // xmm1_4
  float y; // xmm0_4
  Scaleform::Render::Hairliner::FanEdgeType *v5; // rax
  Scaleform::Render::Hairliner::FanEdgeType *v6; // r12
  int *v7; // rbx
  unsigned int v8; // r15d
  __int64 v9; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v10; // r14
  __int64 v11; // rbp
  unsigned __int64 v12; // rsi
  __int64 Size; // r8
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // r11
  Scaleform::Render::Hairliner::FanEdgeType **Pages; // rdi
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // r9
  int v19; // eax
  unsigned int v20; // edx
  __int64 v21; // rax
  int v22; // r9d
  Scaleform::Render::Hairliner::OutVertexType **v23; // r8
  unsigned __int64 v24; // r10
  unsigned __int64 v25; // rax
  __int64 v26; // r11
  Scaleform::Render::Hairliner::OutVertexType *v27; // rbx
  unsigned __int64 v28; // rax
  Scaleform::Render::Hairliner::OutVertexType *v29; // rdx

  x = FLOAT_N1_0e30;
  y = FLOAT_N1_0e30;
  v5 = this->FanEdges.Pages[(unsigned __int64)startEdgeIdx >> 4];
  this->ContourNodes.Size = 0i64;
  v6 = &v5[startEdgeIdx & 0xF];
  v7 = (int *)v6;
  do
  {
    if ( *v7 < 0 )
      break;
    v8 = *v7 & 0x7FFFFFFF;
    v9 = *(_BYTE *)v7 & 0xF;
    v10 = this->OutVertices.Pages[(unsigned __int64)v8 >> 4];
    v11 = v9;
    if ( x != v10[v9].x || y != v10[v9].y )
    {
      v12 = this->ContourNodes.Size >> 4;
      if ( v12 >= this->ContourNodes.NumPages )
        Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ContourNodes,
          this->ContourNodes.Size >> 4);
      this->ContourNodes.Pages[v12][this->ContourNodes.Size & 0xF] = v8;
      ++this->ContourNodes.Size;
      x = v10[v11].x;
      y = v10[v11].y;
    }
    *v7 |= 0x80000000;
    Size = this->FanEdges.Size;
    v14 = 0i64;
    while ( Size > 0 )
    {
      if ( (this->FanEdges.Pages[((Size >> 1) + v14) >> 4][((unsigned __int8)(Size >> 1) + (_BYTE)v14) & 0xF].node1 & 0x7FFFFFFF) >= v7[1] )
      {
        Size >>= 1;
      }
      else
      {
        v14 += (Size >> 1) + 1;
        Size += -1 - (Size >> 1);
      }
    }
    v15 = this->FanEdges.Size;
    if ( v14 >= v15 )
      break;
    Pages = this->FanEdges.Pages;
    v17 = 0i64;
    v18 = v14;
    do
    {
      if ( (Pages[v18 >> 4][v18 & 0xF].node1 & 0x7FFFFFFF) != v7[1] )
        break;
      ++v18;
      ++v17;
    }
    while ( v18 < v15 );
    if ( v17 == 1 )
    {
      v7 = (int *)&Pages[v14 >> 4][v14 & 0xF];
    }
    else if ( v17 == 2 )
    {
      v7 = (int *)&Pages[v14 >> 4][v14 & 0xF];
      v19 = v7[1];
      if ( v19 == Pages[(v14 + 1) >> 4][((_DWORD)v14 + 1) & 0xF].node2 )
      {
        if ( *v7 < 0 )
          v7 = (int *)&Pages[(v14 + 1) >> 4][((_DWORD)v14 + 1) & 0xF];
      }
      else if ( v19 == v8 )
      {
        v7 = (int *)&Pages[(v14 + 1) >> 4][((_DWORD)v14 + 1) & 0xF];
      }
    }
    else
    {
      v20 = 0;
      if ( v17 )
      {
        v21 = 0i64;
        while ( Pages[(v21 + v14) >> 4][((_DWORD)v21 + (_DWORD)v14) & 0xF].node2 != v8 )
        {
          v21 = ++v20;
          if ( v20 >= v17 )
            goto LABEL_38;
        }
        v22 = 0;
        while ( 1 )
        {
          if ( ++v20 >= v17 )
            v20 = 0;
          v7 = (int *)&Pages[(v14 + v20) >> 4][((_DWORD)v14 + v20) & 0xF];
          if ( v7 == (int *)v6 )
            goto LABEL_39;
          if ( *v7 < 0 && (unsigned int)++v22 < v17 )
            continue;
          break;
        }
      }
    }
LABEL_38:
    ;
  }
  while ( v7 != (int *)v6 );
LABEL_39:
  if ( this->ContourNodes.Size )
  {
    v23 = this->OutVertices.Pages;
    v24 = this->ContourNodes.Size;
    v25 = **this->ContourNodes.Pages;
    v26 = v25 & 0xF;
    v27 = v23[v25 >> 4];
    v28 = this->ContourNodes.Pages[(v24 - 1) >> 4][((_BYTE)v24 - 1) & 0xF];
    v29 = v23[v28 >> 4];
    if ( v29[v28 & 0xF].x == v27[v26].x && v29[v28 & 0xF].y == v27[v26].y )
    {
      if ( v24 )
        this->ContourNodes.Size = v24 - 1;
    }
  }
}

// File Line: 924
// RVA: 0x9C7E10
__int64 __fastcall Scaleform::Render::Hairliner::addJoin(
        Scaleform::Render::Hairliner *this,
        unsigned int refVertex,
        Scaleform::Render::TessVertex *v1,
        Scaleform::Render::TessVertex *v2,
        Scaleform::Render::TessVertex *v3,
        float len1,
        float len2,
        float width)
{
  float v12; // xmm8_4
  float v14; // xmm0_4
  float x; // xmm6_4
  float y; // xmm7_4
  float v17; // xmm9_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm10_4
  float v21; // xmm4_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  unsigned __int64 v24; // rdi
  __int64 result; // rax
  __int64 v26; // r8
  Scaleform::Render::Hairliner::OutVertexType *v27; // rcx
  float v28; // xmm11_4
  float v29; // xmm12_4
  float v30; // xmm14_4
  float v31; // xmm2_4
  float v32; // xmm13_4
  __m128 v33; // xmm0
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  unsigned __int64 v37; // rdi
  __int64 v38; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v39; // rax
  unsigned __int64 v40; // rdi
  __int64 v41; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v42; // rax
  __int64 v43; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v44; // rax
  float v45; // xmm12_4
  float v46; // xmm9_4
  float v47; // xmm10_4
  float v48; // xmm11_4
  __int64 v49; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v50; // rax
  unsigned __int64 v51; // rdi
  __int64 v52; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v53; // rax
  float v54; // xmm12_4
  float v55; // xmm14_4
  unsigned __int64 v56; // rdi
  float v57; // xmm13_4
  __int64 v58; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v59; // rax
  unsigned __int64 v60; // rdi
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *p_Triangles; // rbp
  int Size; // eax
  unsigned __int64 v63; // rbx
  int v64; // esi
  float v65; // edi
  __int64 v66; // rdx
  Scaleform::Render::StrokerAA::VertexType *v67; // rax
  float v68; // [rsp+30h] [rbp-F8h]
  float v69; // [rsp+34h] [rbp-F4h]
  float v70; // [rsp+130h] [rbp+8h]
  float v71; // [rsp+140h] [rbp+18h]
  float v72; // [rsp+148h] [rbp+20h]
  float v3a; // [rsp+150h] [rbp+28h]
  float len1a; // [rsp+158h] [rbp+30h]
  float len1b; // [rsp+158h] [rbp+30h]

  v12 = len1;
  v14 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(
          v1,
          v2,
          v3,
          len1,
          len2);
  x = v2->x;
  y = v2->y;
  v72 = (float)(len1 + len2) * this->IntersectionEpsilon;
  v69 = v14;
  v17 = (float)((float)(v1->y - y) * width) * (float)(1.0 / len1);
  v18 = (float)((float)(v2->x - v1->x) * width) * (float)(1.0 / len1);
  v19 = v3->y;
  v20 = (float)((float)(v3->x - v2->x) * width) * (float)(1.0 / len2);
  v21 = (float)((float)(y - v19) * width) * (float)(1.0 / len2);
  if ( COERCE_FLOAT(LODWORD(v14) & _xmm) < 0.125 )
  {
    if ( len1 <= len2 )
    {
      v22 = x + v21;
      v23 = y + v20;
    }
    else
    {
      v22 = x + v17;
      v23 = y + v18;
    }
    v24 = this->OutVertices.Size >> 4;
    if ( v24 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    result = 1i64;
    v26 = this->OutVertices.Size & 0xF;
    v27 = this->OutVertices.Pages[v24];
    v27[v26].x = v22;
    v27[v26].y = v23;
    v27[v26].alpha = 0;
    ++this->OutVertices.Size;
    return result;
  }
  v70 = v1->y + v18;
  v28 = y + v20;
  v29 = x + v17;
  v71 = (float)(v19 + v20) - (float)(y + v20);
  v3a = v1->x + v17;
  v30 = y + v18;
  v31 = (float)(x + v17) - v3a;
  len1a = (float)(y + v18) - v70;
  v32 = x + v21;
  v68 = (float)(v3->x + v21) - (float)(x + v21);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v71 * v31) - (float)(v68 * len1a)) & _xmm) < v72 )
  {
    v54 = v29 - v18;
    v55 = v30 + v17;
    v56 = this->OutVertices.Size >> 4;
    v57 = v32 + v20;
    v48 = v28 - v21;
    if ( v56 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v58 = this->OutVertices.Size & 0xF;
    v59 = this->OutVertices.Pages[v56];
    v59[v58].x = v54;
    v59[v58].y = v55;
    v59[v58].alpha = 0;
    v60 = ++this->OutVertices.Size >> 4;
    if ( v60 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v52 = this->OutVertices.Size & 0xF;
    v53 = this->OutVertices.Pages[v60];
    v53[this->OutVertices.Size & 0xF].x = v57;
    goto LABEL_32;
  }
  v33 = (__m128)LODWORD(len1a);
  v34 = (float)((float)((float)(v70 - v28) * v68) - (float)((float)(v3a - v32) * v71))
      / (float)((float)(v71 * v31) - (float)(v68 * len1a));
  v35 = (float)(v31 * v34) + v3a;
  len1b = (float)(len1a * v34) + v70;
  v33.m128_f32[0] = (float)((float)(len1b - y) * (float)(len1b - y)) + (float)((float)(v35 - x) * (float)(v35 - x));
  LODWORD(v36) = _mm_sqrt_ps(v33).m128_u32[0];
  if ( v69 <= 0.0 )
  {
    v37 = this->OutVertices.Size >> 4;
    if ( v36 <= (float)(width * -4.0) )
      goto LABEL_19;
    v45 = v29 - (float)(v18 * 2.0);
    v46 = (float)(v17 * 2.0) + v30;
    v47 = (float)(v20 * 2.0) + v32;
    v48 = v28 - (float)(v21 * 2.0);
    if ( v37 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v49 = this->OutVertices.Size & 0xF;
    v50 = this->OutVertices.Pages[v37];
    v50[v49].x = v45;
    v50[v49].y = v46;
    v50[v49].alpha = 0;
    v51 = ++this->OutVertices.Size >> 4;
    if ( v51 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v52 = this->OutVertices.Size & 0xF;
    v53 = this->OutVertices.Pages[v51];
    v53[this->OutVertices.Size & 0xF].x = v47;
LABEL_32:
    v53[v52].y = v48;
    p_Triangles = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles;
    v53[v52].alpha = 0;
    ++p_Triangles[-1].Size;
    Size = p_Triangles[-1].Size;
    v63 = p_Triangles->Size >> 4;
    v64 = Size - 1;
    LODWORD(v65) = Size - 2;
    if ( v63 >= p_Triangles->NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        p_Triangles,
        p_Triangles->Size >> 4);
    v66 = p_Triangles->Size & 0xF;
    v67 = p_Triangles->Pages[v63];
    LODWORD(v67[v66].x) = refVertex;
    v67[v66].y = v65;
    *(_DWORD *)&v67[v66].style = v64;
    ++p_Triangles->Size;
    return 2i64;
  }
  if ( v12 >= len2 )
    v12 = len2;
  v37 = this->OutVertices.Size >> 4;
  if ( v36 > (float)(v12 / v69) )
  {
    if ( v37 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v38 = this->OutVertices.Size & 0xF;
    v39 = this->OutVertices.Pages[v37];
    v39[v38].x = v29;
    v39[v38].y = v30;
    v39[v38].alpha = 0;
    v40 = ++this->OutVertices.Size >> 4;
    if ( v40 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v41 = this->OutVertices.Size & 0xF;
    v42 = this->OutVertices.Pages[v40];
    v42[v41].x = v32;
    v42[v41].y = v28;
    v42[v41].alpha = 0;
    ++this->OutVertices.Size;
    return 2i64;
  }
LABEL_19:
  if ( v37 >= this->OutVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
      v37);
  v43 = this->OutVertices.Size & 0xF;
  v44 = this->OutVertices.Pages[v37];
  v44[v43].x = v35;
  v44[v43].y = len1b;
  v44[v43].alpha = 0;
  ++this->OutVertices.Size;
  return 1i64;
}

// File Line: 1045
// RVA: 0x9E5FE0
void __fastcall Scaleform::Render::Hairliner::generateTriangles(Scaleform::Render::Hairliner *this, float width)
{
  unsigned __int64 Size; // r11
  unsigned int **Pages; // r9
  int v5; // r13d
  unsigned int v6; // ebx
  int v7; // r12d
  int v8; // r15d
  unsigned int v9; // ebp
  Scaleform::Render::Hairliner::OutVertexType **v10; // r8
  unsigned __int64 v11; // rax
  Scaleform::Render::TessVertex *v12; // r10
  __int64 v13; // r8
  __m128 v14; // xmm0
  float len1; // xmm2_4
  unsigned __int64 v16; // r14
  unsigned __int64 v17; // rax
  __int64 v18; // r14
  __m128 y_low; // xmm0
  float len2; // xmm6_4
  int v21; // eax
  unsigned int v22; // esi
  unsigned __int64 v23; // rsi
  __int64 v24; // rdx
  Scaleform::Render::Hairliner::TriangleType *v25; // rax
  unsigned int v26; // r12d
  unsigned __int64 v27; // rsi
  __int64 v28; // rdx
  Scaleform::Render::Hairliner::TriangleType *v29; // rax
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *p_Triangles; // rdi
  unsigned __int64 v31; // rbx
  __int64 v32; // rdx
  Scaleform::Render::StrokerAA::VertexType *v33; // rax
  unsigned __int64 v34; // rbx
  __int64 v35; // rdx
  Scaleform::Render::StrokerAA::VertexType *v36; // rax
  Scaleform::Render::TessVertex *v37; // [rsp+40h] [rbp-78h]
  unsigned int v38; // [rsp+48h] [rbp-70h]
  Scaleform::Render::Hairliner::OutVertexType *v3; // [rsp+50h] [rbp-68h]
  unsigned __int64 v40; // [rsp+58h] [rbp-60h]
  int v41; // [rsp+C0h] [rbp+8h]
  unsigned int v42; // [rsp+D0h] [rbp+18h]
  int v43; // [rsp+D8h] [rbp+20h]

  Size = this->ContourNodes.Size;
  if ( Size >= 2 )
  {
    Pages = this->ContourNodes.Pages;
    v5 = -1;
    v6 = 0;
    v7 = -1;
    v8 = -1;
    v41 = -1;
    v9 = Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF];
    v10 = this->OutVertices.Pages;
    v38 = 0;
    v11 = Pages[(Size - 2) >> 4][((_DWORD)Size - 2) & 0xF];
    v12 = (Scaleform::Render::TessVertex *)&v10[v11 >> 4][v11 & 0xF];
    v13 = (__int64)&v10[(unsigned __int64)v9 >> 4][v9 & 0xF];
    v37 = (Scaleform::Render::TessVertex *)v13;
    v14 = (__m128)*(unsigned int *)(v13 + 4);
    v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] - v12->y) * (float)(v14.m128_f32[0] - v12->y))
                    + (float)((float)(*(float *)v13 - v12->x) * (float)(*(float *)v13 - v12->x));
    LODWORD(len1) = _mm_sqrt_ps(v14).m128_u32[0];
    v16 = 0i64;
    do
    {
      v17 = v16;
      v18 = v16 & 0xF;
      v40 = v17 >> 4;
      v3 = &this->OutVertices.Pages[(unsigned __int64)Pages[v17 >> 4][v18] >> 4][Pages[v17 >> 4][v18] & 0xF];
      y_low = (__m128)LODWORD(v3->y);
      y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - *(float *)(v13 + 4))
                                * (float)(y_low.m128_f32[0] - *(float *)(v13 + 4)))
                        + (float)((float)(v3->x - *(float *)v13) * (float)(v3->x - *(float *)v13));
      LODWORD(len2) = _mm_sqrt_ps(y_low).m128_u32[0];
      v21 = Scaleform::Render::Hairliner::addJoin(
              this,
              v9,
              v12,
              (Scaleform::Render::TessVertex *)v13,
              (Scaleform::Render::TessVertex *)v3,
              len1,
              len2,
              width);
      v43 = v21;
      if ( v5 == -1 )
      {
        v22 = v9;
        v41 = v9;
        v8 = LODWORD(this->OutVertices.Size) - v21;
      }
      else
      {
        v23 = this->Triangles.Size >> 4;
        v42 = LODWORD(this->OutVertices.Size) - v21;
        if ( v23 >= this->Triangles.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
            v23);
        v24 = this->Triangles.Size & 0xF;
        v25 = this->Triangles.Pages[v23];
        v25[v24].v1 = v5;
        v25[v24].v2 = v7;
        v25[v24].v3 = v42;
        ++this->Triangles.Size;
        v26 = LODWORD(this->OutVertices.Size) - v43;
        v27 = this->Triangles.Size >> 4;
        if ( v27 >= this->Triangles.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
            this->Triangles.Size >> 4);
        v28 = this->Triangles.Size & 0xF;
        v29 = this->Triangles.Pages[v27];
        v22 = v41;
        v29[v28].v1 = v5;
        v29[v28].v2 = v26;
        v29[v28].v3 = v9;
        ++this->Triangles.Size;
        v6 = v38;
      }
      Pages = this->ContourNodes.Pages;
      len1 = len2;
      v13 = (__int64)v3;
      v12 = v37;
      ++v6;
      v5 = v9;
      v9 = Pages[v40][v18];
      v16 = v6;
      v7 = LODWORD(this->OutVertices.Size) - 1;
      v37 = (Scaleform::Render::TessVertex *)v3;
      v38 = v6;
    }
    while ( v6 < this->ContourNodes.Size );
    if ( v5 != -1 )
    {
      p_Triangles = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles;
      v31 = p_Triangles->Size >> 4;
      if ( v31 >= p_Triangles->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
          p_Triangles,
          p_Triangles->Size >> 4);
      v32 = p_Triangles->Size & 0xF;
      v33 = p_Triangles->Pages[v31];
      LODWORD(v33[v32].x) = v5;
      LODWORD(v33[v32].y) = v7;
      *(_DWORD *)&v33[v32].style = v8;
      v34 = ++p_Triangles->Size >> 4;
      if ( v34 >= p_Triangles->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
          p_Triangles,
          p_Triangles->Size >> 4);
      v35 = p_Triangles->Size & 0xF;
      v36 = p_Triangles->Pages[v34];
      LODWORD(v36[v35].x) = v5;
      LODWORD(v36[v35].y) = v8;
      *(_DWORD *)&v36[v35].style = v22;
      ++p_Triangles->Size;
    }
  }
}

// File Line: 1103
// RVA: 0x9B8A90
void __fastcall Scaleform::Render::Hairliner::Tessellate(Scaleform::Render::Hairliner *this)
{
  unsigned __int64 v1; // rdi
  unsigned __int64 v3; // r9
  unsigned __int64 i; // rsi
  Scaleform::Render::Hairliner::FanEdgeType **Pages; // r14
  Scaleform::Render::Hairliner::FanEdgeType *v6; // r8
  Scaleform::Render::Hairliner::FanEdgeType *v7; // r11
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  Scaleform::Render::Hairliner::FanEdgeType *v10; // rdx
  __int64 v11; // r8

  v1 = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  this->Triangles.Size = 0i64;
  Scaleform::Render::Hairliner::buildGraph(this);
  if ( this->FanEdges.Size >= 2 )
  {
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>,bool (*)(Scaleform::Render::Hairliner::FanEdgeType const &,Scaleform::Render::Hairliner::FanEdgeType const &)>(
      &this->FanEdges,
      0i64,
      this->FanEdges.Size,
      Scaleform::Render::Hairliner::cmpEdges);
    v3 = 1i64;
    for ( i = 1i64; v3 < this->FanEdges.Size; ++v3 )
    {
      Pages = this->FanEdges.Pages;
      v6 = Pages[(v3 - 1) >> 4];
      v7 = Pages[v3 >> 4];
      if ( v6[((_DWORD)v3 - 1) & 0xF].node1 != v7[v3 & 0xF].node1
        || v6[((_DWORD)v3 - 1) & 0xF].node2 != v7[v3 & 0xF].node2 )
      {
        v8 = i & 0xF;
        v9 = i++ >> 4;
        v10 = Pages[v9];
        v11 = v8;
        v10[v11].node1 = v7[v3 & 0xF].node1;
        v10[v11].node2 = v7[v3 & 0xF].node2;
        v10[v11].slope = v7[v3 & 0xF].slope;
      }
    }
    if ( i < this->FanEdges.Size )
      this->FanEdges.Size = i;
    if ( this->FanEdges.Size )
    {
      do
      {
        if ( (this->FanEdges.Pages[v1 >> 4][v1 & 0xF].node1 & 0x80000000) == 0 )
        {
          Scaleform::Render::Hairliner::generateContourAA(this, v1);
          Scaleform::Render::Hairliner::generateTriangles(this, COERCE_FLOAT(LODWORD(this->Width) ^ _xmm[0]));
        }
        ++v1;
      }
      while ( v1 < this->FanEdges.Size );
    }
  }
}

// File Line: 1147
// RVA: 0x9BA540
void __fastcall Scaleform::Render::Hairliner::Transform(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v2; // r10
  __int64 v3; // r9
  Scaleform::Render::Hairliner::OutVertexType *v4; // rax
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
  for ( this->MaxY = -1.0e30; v2 < this->OutVertices.Size; ++v2 )
  {
    v3 = v2 & 0xF;
    v4 = this->OutVertices.Pages[v2 >> 4];
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

// File Line: 1167
// RVA: 0x9B7C80
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Hairliner::StretchTo(
        Scaleform::Render::Hairliner *this,
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
  Scaleform::Render::Hairliner::OutVertexType **Pages; // r10
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  Scaleform::Render::Hairliner::OutVertexType *v18; // rax
  float x; // xmm2_4
  float y; // xmm1_4
  float MinX; // xmm3_4
  float MaxX; // xmm1_4
  float MinY; // xmm0_4
  float MaxY; // xmm2_4
  __int64 v25; // rax
  unsigned __int64 v26; // rdx
  __int64 v27; // r8
  Scaleform::Render::Hairliner::OutVertexType *v28; // rax
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
    Size = this->OutVertices.Size;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    v12 = 0i64;
    if ( Size )
    {
      v13 = FLOAT_N1_0e30;
      Pages = this->OutVertices.Pages;
      v15 = FLOAT_1_0e30;
      v16 = FLOAT_N1_0e30;
      v17 = FLOAT_1_0e30;
      do
      {
        v18 = Pages[v12 >> 4];
        x = v18[v12 & 0xF].x;
        y = v18[v12 & 0xF].y;
        v35 = *(float *)&v18[v12 & 0xF].alpha;
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
      if ( this->OutVertices.Size )
      {
        do
        {
          v25 = v6 & 0xF;
          v26 = v6++ >> 4;
          v27 = v25;
          v28 = this->OutVertices.Pages[v26];
          v29 = v28[v27].x;
          v30 = v28[v27].y;
          v28[v27].x = (float)((float)(v29 * result->M[0][0]) + (float)(v30 * result->M[0][1])) + result->M[0][3];
          v28[v27].y = (float)((float)(v29 * result->M[1][0]) + (float)(v30 * result->M[1][1])) + result->M[1][3];
        }
        while ( v6 < this->OutVertices.Size );
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

// File Line: 1202
// RVA: 0x989200
void __fastcall Scaleform::Render::Hairliner::GetMesh(
        Scaleform::Render::Hairliner *this,
        unsigned int __formal,
        Scaleform::Render::TessMesh *mesh)
{
  *(_QWORD *)&mesh->Style1 = 1i64;
  mesh->MeshIdx = 0;
  *(_QWORD *)&mesh->Flags1 = 0i64;
  mesh->StartVertex = 0;
  mesh->VertexCount = this->OutVertices.Size;
}

// File Line: 1214
// RVA: 0x98ED90
__int64 __fastcall Scaleform::Render::Hairliner::GetVertices(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::TessMesh *mesh,
        Scaleform::Render::TessVertex *vertices,
        int num)
{
  unsigned int v6; // r10d
  unsigned __int64 v7; // rdx
  __int64 v8; // r8
  Scaleform::Render::Hairliner::OutVertexType *v9; // rdx
  float v10; // eax
  unsigned __int64 v11; // rdx
  __int64 v12; // r8
  Scaleform::Render::Hairliner::OutVertexType *v13; // rdx
  float v14; // eax
  unsigned __int64 v15; // rdx
  __int64 v16; // r8
  Scaleform::Render::Hairliner::OutVertexType *v17; // rdx
  float v18; // eax
  unsigned __int64 v19; // rdx
  __int64 v20; // r8
  Scaleform::Render::Hairliner::OutVertexType *v21; // rdx
  float v22; // eax
  unsigned int *p_Idx; // r11
  unsigned __int64 StartVertex; // rdx
  __int64 v25; // r8
  Scaleform::Render::Hairliner::OutVertexType *v26; // rdx
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
        if ( StartVertex >= this->OutVertices.Size )
          break;
        v25 = StartVertex & 0xF;
        v26 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)StartVertex >> 4];
        *(p_Idx - 2) = LODWORD(v26[v25].x);
        y = v26[v25].y;
        *p_Idx = 0;
        *((float *)p_Idx - 1) = y;
        p_Idx[1] = 1;
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
      if ( v7 >= this->OutVertices.Size )
        break;
      v8 = v7 & 0xF;
      v9 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v7 >> 4];
      vertices->x = v9[v8].x;
      v10 = v9[v8].y;
      vertices->Idx = 0;
      vertices->y = v10;
      *(_DWORD *)vertices->Styles = 1;
      vertices->Flags = v9[v8].alpha != 0 ? 2 : 0;
      v11 = ++mesh->StartVertex;
      if ( v11 >= this->OutVertices.Size )
        return v6 + 1;
      v12 = v11 & 0xF;
      v13 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v11 >> 4];
      vertices[1].x = v13[v12].x;
      v14 = v13[v12].y;
      vertices[1].Idx = 0;
      vertices[1].y = v14;
      *(_DWORD *)vertices[1].Styles = 1;
      vertices[1].Flags = v13[v12].alpha != 0 ? 2 : 0;
      v15 = ++mesh->StartVertex;
      if ( v15 >= this->OutVertices.Size )
        return v6 + 2;
      v16 = v15 & 0xF;
      v17 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v15 >> 4];
      vertices[2].x = v17[v16].x;
      v18 = v17[v16].y;
      vertices[2].Idx = 0;
      vertices[2].y = v18;
      *(_DWORD *)vertices[2].Styles = 1;
      vertices[2].Flags = v17[v16].alpha != 0 ? 2 : 0;
      v19 = ++mesh->StartVertex;
      if ( v19 >= this->OutVertices.Size )
        return v6 + 3;
      v20 = v19 & 0xF;
      v21 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v19 >> 4];
      vertices[3].x = v21[v20].x;
      v22 = v21[v20].y;
      vertices[3].Idx = 0;
      vertices[3].y = v22;
      *(_DWORD *)vertices[3].Styles = 1;
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

// File Line: 1233
// RVA: 0x98DF90
void __fastcall Scaleform::Render::Hairliner::GetTrianglesI16(
        Scaleform::Render::Hairliner *this,
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

