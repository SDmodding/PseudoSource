// File Line: 60
// RVA: 0x93DAD0
void __fastcall Scaleform::Render::Hairliner::Hairliner(Scaleform::Render::Hairliner *this, Scaleform::Render::LinearHeap *heap)
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
bool __fastcall Scaleform::Render::Hairliner::cmpMonoChains(Scaleform::Render::Tessellator::MonoChainType *a, Scaleform::Render::Tessellator::MonoChainType *b)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  bool result; // al

  v2 = a->ySort;
  v3 = b->ySort;
  if ( v2 != v3 || (v2 = a->xb, v3 = b->xb, v2 != v3) )
    result = v3 > v2;
  else
    result = a->xt < b->xt;
  return result;
}

// File Line: 127
// RVA: 0x9D6310
bool __fastcall UFG::SectionChooser::fnSectionStreamPriority(UFG::SectionChooser::SectionLoad *a, UFG::SectionChooser::SectionLoad *b)
{
  return a->mScore < b->mScore;
}

// File Line: 133
// RVA: 0x9D6260
bool __fastcall Scaleform::Render::Hairliner::cmpEdges(Scaleform::Render::Hairliner::FanEdgeType *a, Scaleform::Render::Hairliner::FanEdgeType *b)
{
  bool v2; // cf

  v2 = a->node1 < b->node1;
  if ( a->node1 == b->node1 )
    v2 = a->slope < b->slope;
  return v2;
}

// File Line: 177
// RVA: 0x9CF700
void __fastcall Scaleform::Render::Hairliner::buildEdgeList(Scaleform::Render::Hairliner *this, unsigned int start, unsigned int numEdges, int step)
{
  unsigned __int64 v4; // r13
  unsigned int v5; // edi
  int v6; // er12
  unsigned int v7; // er14
  unsigned int v8; // er15
  Scaleform::Render::Hairliner *v9; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcEdgeType,4,16> *v10; // rbx
  Scaleform::Render::Hairliner::SrcVertexType **v11; // rcx
  unsigned __int64 v12; // rax
  char v13; // r9
  Scaleform::Render::Hairliner::SrcVertexType *v14; // r8
  unsigned __int64 v15; // rsi
  Scaleform::Render::Hairliner::SrcVertexType *v16; // rcx
  Scaleform::Render::Hairliner::SrcEdgeType *v17; // rdx
  signed __int64 v18; // r8
  Scaleform::Render::Hairliner::SrcEdgeType *v19; // rax
  Scaleform::Render::Hairliner::SrcVertexType **v20; // rdx
  unsigned __int64 v21; // rdi
  unsigned int v22; // er8
  signed __int64 v23; // rsi
  Scaleform::Render::Hairliner::MonoChainType *v24; // rcx
  signed __int64 v25; // rdx
  unsigned __int64 v26; // [rsp+20h] [rbp-48h]
  __int64 v27; // [rsp+28h] [rbp-40h]
  __int64 v28; // [rsp+28h] [rbp-40h]
  __int64 v29; // [rsp+30h] [rbp-38h]
  __int64 v30; // [rsp+38h] [rbp-30h]

  v4 = LODWORD(this->SrcEdges.Size);
  v5 = 0;
  v6 = step;
  v7 = numEdges;
  v8 = start;
  v9 = this;
  if ( numEdges )
  {
    v10 = &this->SrcEdges;
    do
    {
      v11 = v9->SrcVertices.Pages;
      v12 = v8;
      v13 = v8;
      v8 += v6;
      v26 = __PAIR__(v8, (unsigned int)v12);
      v14 = v11[v12 >> 4];
      v15 = v10->Size >> 4;
      v16 = v11[(unsigned __int64)v8 >> 4];
      *(float *)&v27 = (float)(v16[v8 & 0xF].x - v14[v13 & 0xF].x) / (float)(v16[v8 & 0xF].y - v14[v13 & 0xF].y);
      if ( v15 >= v10->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcEdgeType,4,16>::allocPage(v10, v15);
      v17 = v10->Pages[v15];
      v18 = v10->Size & 0xF;
      *(_QWORD *)&v17[v18].lower = v26;
      *(_QWORD *)&v17[v18].slope = v27;
      v17[v18].next = 0i64;
      ++v10->Size;
      if ( v5 )
        v9->SrcEdges.Pages[(v9->SrcEdges.Size - 2) >> 4][(LODWORD(v9->SrcEdges.Size) - 2) & 0xF].next = &v10->Pages[(v10->Size - 1) >> 4][((unsigned int)v10->Size - 1) & 0xF];
      ++v5;
    }
    while ( v5 < v7 );
  }
  v19 = v9->SrcEdges.Pages[v4 >> 4];
  v20 = v9->SrcVertices.Pages;
  v21 = v9->MonoChains.Size >> 4;
  v22 = v19[v4 & 0xF].lower;
  v23 = (signed __int64)&v19[v4 & 0xF];
  LODWORD(v30) = -1;
  v29 = *(unsigned int *)(v23 + 8);
  *(float *)&v28 = v20[(unsigned __int64)v22 >> 4][v22 & 0xF].y;
  HIDWORD(v28) = LODWORD(v20[(unsigned __int64)v22 >> 4][v22 & 0xF].x);
  if ( v21 >= v9->MonoChains.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType,4,8>::allocPage(&v9->MonoChains, v21);
  v24 = v9->MonoChains.Pages[v21];
  v25 = v9->MonoChains.Size & 0xF;
  v24[v25].edge = (Scaleform::Render::Hairliner::SrcEdgeType *)v23;
  *(_QWORD *)&v24[v25].ySort = v28;
  *(_QWORD *)&v24[v25].xt = v29;
  *(_QWORD *)&v24[v25].prevVertex = v30;
  ++v9->MonoChains.Size;
}

// File Line: 209
// RVA: 0x9614B0
void __fastcall Scaleform::Render::Hairliner::ClosePath(Scaleform::Render::Hairliner *this)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcVertexType,4,16> *v1; // rbx
  unsigned __int64 v2; // rdi
  Scaleform::Render::Hairliner::SrcVertexType *v3; // rsi

  v1 = &this->SrcVertices;
  v2 = this->SrcVertices.Size >> 4;
  v3 = &this->SrcVertices.Pages[(unsigned __int64)this->LastVertex >> 4][this->LastVertex & 0xF];
  if ( v2 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices,
      v2);
  v1->Pages[v2][v1->Size & 0xF] = *v3;
  ++v1->Size;
}

// File Line: 216
// RVA: 0x978710
void __fastcall Scaleform::Render::Hairliner::FinalizePath(Scaleform::Render::Hairliner *this, unsigned int __formal, unsigned int a3, bool a4)
{
  Scaleform::Render::Hairliner *v4; // rbx
  unsigned __int64 v5; // rcx
  unsigned int v6; // edx
  unsigned __int64 v7; // rsi
  Scaleform::Render::Hairliner::PathType v8; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = this->LastVertex;
  v6 = v4->SrcVertices.Size;
  if ( v6 >= (signed int)v5 + 2 )
  {
    v7 = v4->Paths.Size >> 4;
    v8.start = v5;
    v8.end = v6 - 1;
    if ( v7 >= v4->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::PathType,4,4>::allocPage(&v4->Paths, v7);
    v4->Paths.Pages[v7][v4->Paths.Size & 0xF] = v8;
    ++v4->Paths.Size;
    v4->LastVertex = v4->SrcVertices.Size;
  }
  else if ( v5 < v4->SrcVertices.Size )
  {
    v4->SrcVertices.Size = v5;
  }
}

// File Line: 232
// RVA: 0x9DF130
void __fastcall Scaleform::Render::Hairliner::decomposePath(Scaleform::Render::Hairliner *this, Scaleform::Render::Hairliner::PathType *path)
{
  signed int v2; // ebp
  signed int v3; // esi
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::Render::Hairliner *v6; // r15
  float v7; // xmm8_4
  unsigned int v8; // er14
  unsigned __int64 v9; // r13
  Scaleform::Render::Hairliner::SrcVertexType **v10; // rcx
  __int64 v11; // r15
  Scaleform::Render::Hairliner::SrcVertexType *v12; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v13; // r12
  float v14; // xmm9_4
  unsigned __int64 v15; // rdi
  float v16; // xmm6_4
  float v17; // xmm7_4
  unsigned __int64 v18; // rdi
  signed __int64 v19; // rdx
  Scaleform::Render::Hairliner::HorizontalEdgeType *v20; // rax
  signed int i; // edi
  Scaleform::Render::Hairliner::SrcVertexType **v22; // r11
  float v23; // xmm0_4
  int v24; // er9
  unsigned int v25; // ebx
  int j; // er10
  signed int k; // edi
  Scaleform::Render::Hairliner::SrcVertexType **v28; // r11
  int v29; // er9
  float v30; // xmm0_4
  __int64 v31; // rcx
  Scaleform::Render::Hairliner::SrcVertexType *v32; // rax
  unsigned int v33; // ebx
  int l; // er10
  Scaleform::Render::Hairliner *v35; // [rsp+C0h] [rbp+8h]
  unsigned int v36; // [rsp+C8h] [rbp+10h]

  v35 = this;
  v2 = path->start;
  v3 = path->end;
  v4 = (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->Scanbeams;
  v5 = this->Scanbeams.Size >> 4;
  v6 = this;
  v36 = path->start;
  v7 = this->SrcVertices.Pages[(unsigned __int64)(signed int)path->start >> 4][path->start & 0xF].y;
  if ( v5 >= this->Scanbeams.NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->Scanbeams,
      v5);
  v8 = v2 + 1;
  v4->Pages[v5][v4->Size & 0xF] = (Scaleform::Render::GlyphFitter::VertexType)v2;
  ++v4->Size;
  if ( v2 + 1 <= (unsigned int)v3 )
  {
    v9 = v8;
    do
    {
      v10 = v35->SrcVertices.Pages;
      v11 = v9 & 0xF;
      v13 = v10[v9 >> 4];
      v14 = v13[v11].y;
      if ( v14 == v7 )
      {
        v12 = v10[(unsigned __int64)(v8 - 1) >> 4];
        v16 = v12[((_BYTE)v8 - 1) & 0xF].x;
        v17 = v13[v11].x;
        if ( v16 != v17 )
        {
          if ( v16 > v17 )
          {
            v16 = v13[v11].x;
            v17 = v12[((_BYTE)v8 - 1) & 0xF].x;
          }
          v18 = v35->HorizontalEdges.Size >> 2;
          if ( v18 >= v35->HorizontalEdges.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>::allocPage(
              &v35->HorizontalEdges,
              v35->HorizontalEdges.Size >> 2);
          v19 = v35->HorizontalEdges.Size & 3;
          v20 = v35->HorizontalEdges.Pages[v18];
          v20[v19].x1 = v16;
          v20[v19].x2 = v17;
          v20[v19].y = v14;
          *(_QWORD *)&v20[v19].lv = -1i64;
          ++v35->HorizontalEdges.Size;
        }
      }
      else
      {
        v15 = v4->Size >> 4;
        if ( v15 >= v4->NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(v4, v4->Size >> 4);
        v4->Pages[v15][v4->Size & 0xF] = (Scaleform::Render::GlyphFitter::VertexType)v8;
        ++v4->Size;
        v7 = v13[v11].y;
      }
      ++v8;
      ++v9;
    }
    while ( v8 <= v3 );
    v2 = v36;
    v6 = v35;
  }
  for ( i = v2; i < v3; ++i )
  {
    v22 = v6->SrcVertices.Pages;
    v23 = v22[(unsigned __int64)i >> 4][i & 0xF].y;
    if ( i > v2 )
    {
      if ( v23 <= v22[(unsigned __int64)(i - 1) >> 4][(i - 1) & 0xF].y )
      {
        v24 = i + 1;
        if ( v23 < v22[(unsigned __int64)(i + 1) >> 4][(i + 1) & 0xF].y )
        {
LABEL_23:
          v25 = 1;
          for ( j = v24 + 1;
                v24 < v3 && v22[(unsigned __int64)j >> 4][j & 0xF].y > v22[(unsigned __int64)v24 >> 4][v24 & 0xF].y;
                ++j )
          {
            ++v25;
            ++v24;
          }
          Scaleform::Render::Hairliner::buildEdgeList(v6, i, v25, 1);
          i = v25 + i - 1;
          continue;
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
  for ( k = v3; k > v2; --k )
  {
    v28 = v6->SrcVertices.Pages;
    v29 = k - 1;
    v30 = v28[(unsigned __int64)k >> 4][k & 0xF].y;
    v31 = (k - 1) & 0xF;
    v32 = v28[(unsigned __int64)(k - 1) >> 4];
    if ( k < v3 )
    {
      if ( v30 < v32[v31].y && v30 <= v28[(unsigned __int64)(k + 1) >> 4][(k + 1) & 0xF].y )
      {
LABEL_35:
        v33 = 1;
        for ( l = k - 2;
              v29 > v2 && v28[(unsigned __int64)l >> 4][l & 0xF].y > v28[(unsigned __int64)v29 >> 4][v29 & 0xF].y;
              --l )
        {
          ++v33;
          --v29;
        }
        Scaleform::Render::Hairliner::buildEdgeList(v6, k, v33, -1);
        k += 1 - v33;
        continue;
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
__int64 __fastcall Scaleform::Render::Hairliner::nextScanbeam(Scaleform::Render::Hairliner *this, float yb, float yt, unsigned int startMc, unsigned int numMc)
{
  __int64 v5; // r13
  unsigned int v6; // er15
  unsigned __int64 v7; // r12
  Scaleform::Render::Hairliner *v8; // rdi
  float v9; // xmm7_4
  float v10; // xmm6_4
  unsigned __int64 v11; // rbp
  float *v12; // rbx
  _DWORD *v13; // r9
  Scaleform::Render::Hairliner::SrcVertexType **v14; // r10
  unsigned int *v15; // rax
  unsigned int v16; // er8
  unsigned int v17; // edx
  Scaleform::Render::Hairliner::SrcVertexType **v18; // rcx
  unsigned __int64 v19; // rax
  __int64 v20; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v21; // r9
  float v22; // xmm0_4
  Scaleform::Render::Hairliner::SrcVertexType *v23; // rdx
  unsigned __int64 v24; // r14
  int v25; // eax
  __int64 v26; // rdx
  Scaleform::Render::Hairliner::SrcVertexType *v27; // rcx
  float v28; // xmm0_4
  float *v29; // r8
  unsigned int v30; // er9
  unsigned __int64 v31; // rsi
  unsigned __int64 v32; // rbp
  __int64 v33; // r14
  Scaleform::Render::Hairliner::MonoChainType *v34; // r9
  Scaleform::Render::Hairliner::SrcVertexType **v35; // rcx
  float *v36; // r10
  __int64 v37; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v38; // r11
  float v39; // xmm0_4
  Scaleform::Render::Hairliner::SrcVertexType *v40; // rdx
  unsigned __int64 v41; // rsi
  unsigned __int64 v42; // r10
  unsigned int v43; // ebx
  unsigned __int64 v44; // r11
  int v45; // er12
  unsigned __int64 v46; // rsi
  Scaleform::Render::Hairliner::MonoChainType ***v47; // r9
  Scaleform::Render::Hairliner::MonoChainType *v48; // r8
  float v49; // xmm1_4
  Scaleform::Render::Hairliner::MonoChainType *v50; // rdx
  float v51; // xmm0_4
  bool v52; // al
  Scaleform::Render::Hairliner::MonoChainType **v53; // rcx
  Scaleform::Render::Hairliner::MonoChainType *v54; // rax
  unsigned __int64 v55; // rsi
  unsigned __int64 v56; // rbp
  unsigned __int64 v57; // r10
  float v58; // xmm8_4
  int v59; // er15
  int v60; // er9
  unsigned int **v61; // rdx
  Scaleform::Render::Hairliner::MonoChainType ***v62; // r8
  __int64 v63; // rbp
  unsigned int v64; // ecx
  Scaleform::Render::Hairliner::MonoChainType *v65; // r12
  __int64 v66; // r14
  unsigned int v67; // ecx
  Scaleform::Render::Hairliner::MonoChainType *v68; // r13
  unsigned __int64 v69; // rbp
  unsigned __int64 v70; // rsi
  Scaleform::Render::Hairliner::MonoChainType **v71; // r15
  unsigned __int64 v72; // r14
  unsigned __int64 v73; // rdx
  Scaleform::Render::LinearHeap *v74; // rcx
  void *v75; // rbx
  unsigned __int64 v76; // rax
  float v77; // xmm2_4
  float v78; // xmm0_4
  float v79; // xmm1_4
  float v80; // xmm0_4
  unsigned __int64 v81; // rsi
  unsigned __int64 v82; // rdx
  Scaleform::Render::LinearHeap *v83; // rcx
  void *v84; // rbx
  unsigned __int64 v85; // rax
  Scaleform::Render::Hairliner::IntersectionType *v86; // rdx
  signed __int64 v87; // r8
  unsigned int **v88; // rcx
  Scaleform::Render::Hairliner::MonoChainType ***v89; // rdx
  unsigned int v90; // er10
  unsigned int v91; // er9
  unsigned __int64 v92; // rax
  __int64 v93; // r10
  Scaleform::Render::Hairliner::MonoChainType **v94; // r8
  unsigned __int64 v95; // rax
  __int64 v96; // r9
  Scaleform::Render::Hairliner::MonoChainType **v97; // rdx
  Scaleform::Render::Hairliner::MonoChainType *v98; // rcx
  signed __int64 v100; // [rsp+20h] [rbp-B8h]
  __int64 v101; // [rsp+28h] [rbp-B0h]
  unsigned __int64 v102; // [rsp+30h] [rbp-A8h]
  unsigned __int64 v103; // [rsp+38h] [rbp-A0h]
  __int64 v104; // [rsp+50h] [rbp-88h]
  __int64 v105; // [rsp+E0h] [rbp+8h]
  int v106; // [rsp+E8h] [rbp+10h]
  int v107; // [rsp+F0h] [rbp+18h]
  unsigned int numMca; // [rsp+100h] [rbp+28h]

  v5 = numMc;
  v6 = 0;
  v7 = startMc;
  v8 = this;
  this->ValidChains.Size = 0i64;
  v9 = yt;
  v10 = yb;
  if ( numMc )
    v6 = 1;
  v11 = 0i64;
  v100 = 1i64;
  numMca = v6;
  if ( this->ActiveChains.Size )
  {
    do
    {
      v12 = (float *)v8->ActiveChains.Pages[v11 >> 4][v11 & 0xF];
      *((_DWORD *)v12 + 5) &= 0xFFFFFFFD;
      v13 = *(_DWORD **)v12;
      v14 = v8->SrcVertices.Pages;
      if ( yb == v14[(unsigned __int64)*(unsigned int *)(*(_QWORD *)v12 + 4i64) >> 4][*(_DWORD *)(*(_QWORD *)v12 + 4i64) & 0xF].y )
      {
        v15 = (unsigned int *)*((_QWORD *)v13 + 2);
        if ( v15 )
        {
          *(_QWORD *)v12 = v15;
          v16 = v15[1];
          v17 = *v15;
          v18 = v8->SrcVertices.Pages;
          v19 = v16;
          v20 = v16 & 0xF;
          v21 = v18[v19 >> 4];
          v12[3] = v18[(unsigned __int64)v17 >> 4][v17 & 0xF].x;
          if ( yt == v21[v20].y )
          {
            v22 = v21[v20].x;
          }
          else
          {
            v23 = v8->SrcVertices.Pages[(unsigned __int64)**(unsigned int **)v12 >> 4];
            v22 = (float)((float)(yt - v23[**(_DWORD **)v12 & 0xF].y) * *(float *)(*(_QWORD *)v12 + 8i64))
                + v23[**(_DWORD **)v12 & 0xF].x;
          }
          v12[4] = v22;
          v24 = v8->ValidChains.Size >> 4;
          if ( v24 >= v8->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v8->ValidChains,
              v8->ValidChains.Size >> 4);
          v8->ValidChains.Pages[v24][v8->ValidChains.Size & 0xF] = v11;
          ++v8->ValidChains.Size;
          *((_DWORD *)v12 + 5) |= 2u;
        }
        else
        {
          v25 = *((_DWORD *)v12 + 4);
          *((_DWORD *)v12 + 5) |= 1u;
          v6 |= 2u;
          *((_DWORD *)v12 + 5) |= 2u;
          *((_DWORD *)v12 + 3) = v25;
        }
      }
      else
      {
        v26 = *(_DWORD *)(*(_QWORD *)v12 + 4i64) & 0xF;
        v27 = v14[(unsigned __int64)*(unsigned int *)(*(_QWORD *)v12 + 4i64) >> 4];
        v12[3] = v12[4];
        if ( yt == v27[v26].y )
        {
          v28 = v27[v26].x;
        }
        else
        {
          v29 = (float *)v13;
          v30 = *v13;
          v28 = (float)((float)(yt - v8->SrcVertices.Pages[(unsigned __int64)v30 >> 4][v30 & 0xF].y) * v29[2])
              + v8->SrcVertices.Pages[(unsigned __int64)v30 >> 4][v30 & 0xF].x;
        }
        v12[4] = v28;
        v31 = v8->ValidChains.Size >> 4;
        if ( v31 >= v8->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v8->ValidChains,
            v8->ValidChains.Size >> 4);
        v8->ValidChains.Pages[v31][v8->ValidChains.Size & 0xF] = v11;
        ++v8->ValidChains.Size;
      }
      ++v11;
    }
    while ( v11 < v8->ActiveChains.Size );
    numMca = v6;
  }
  if ( (_DWORD)v5 )
  {
    v32 = v7;
    v33 = v5;
    do
    {
      v34 = v8->MonoChainsSorted.Pages[v32 >> 4][v32 & 0xF];
      v35 = v8->SrcVertices.Pages;
      v36 = (float *)&v34->edge->lower;
      v37 = v34->edge->lower & 0xF;
      v38 = v35[(unsigned __int64)v34->edge->lower >> 4];
      *(float *)&v35 = v35[(unsigned __int64)v34->edge->lower >> 4][v37].x;
      v34->flags = 2;
      LODWORD(v34->xb) = (_DWORD)v35;
      if ( yt == v38[v37].y )
      {
        v39 = v38[v37].x;
      }
      else
      {
        v40 = v8->SrcVertices.Pages[(unsigned __int64)*(unsigned int *)v36 >> 4];
        v39 = (float)((float)(yt - v40[*(_DWORD *)v36 & 0xF].y) * v36[2]) + v40[*(_DWORD *)v36 & 0xF].x;
      }
      v34->xt = v39;
      v41 = v8->ActiveChains.Size >> 4;
      if ( v41 >= v8->ActiveChains.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&v8->ActiveChains,
          v8->ActiveChains.Size >> 4);
      ++v32;
      v8->ActiveChains.Pages[v41][v8->ActiveChains.Size & 0xF] = 0i64;
      ++v8->ActiveChains.Size;
      --v33;
    }
    while ( v33 );
    v42 = v8->ActiveChains.Size;
    v43 = v7 + v5;
    v44 = v8->ActiveChains.Size - v5;
    v45 = -(signed int)v7;
    v46 = v44 - 1;
    do
    {
      if ( !v44
        || ((v47 = v8->ActiveChains.Pages,
             v48 = v8->MonoChainsSorted.Pages[(unsigned __int64)(v43 - 1) >> 4][((_BYTE)v43 - 1) & 0xF],
             v49 = v48->xb,
             v50 = v47[v46 >> 4][v46 & 0xF],
             v51 = v50->xb,
             v51 == v49) ? (v52 = v50->xt < v48->xt) : (v52 = v49 > v51),
            v52) )
      {
        --v43;
        v53 = v8->ActiveChains.Pages[--v42 >> 4];
        v54 = v8->MonoChainsSorted.Pages[(unsigned __int64)v43 >> 4][v43 & 0xF];
      }
      else
      {
        --v44;
        --v42;
        --v46;
        v53 = v47[v42 >> 4];
        v54 = v47[v44 >> 4][v44 & 0xF];
      }
      v53[v42 & 0xF] = v54;
    }
    while ( v45 + v43 );
    v6 = numMca;
  }
  v8->Intersections.Size = 0i64;
  if ( v6 & 1 )
  {
    v55 = 0i64;
    v8->ValidChains.Size = 0i64;
    if ( v8->ActiveChains.Size )
    {
      do
      {
        if ( !(v8->ActiveChains.Pages[v55 >> 4][v55 & 0xF]->flags & 1) )
        {
          v56 = v8->ValidChains.Size >> 4;
          if ( v56 >= v8->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v8->ValidChains,
              v8->ValidChains.Size >> 4);
          v8->ValidChains.Pages[v56][v8->ValidChains.Size & 0xF] = v55;
          ++v8->ValidChains.Size;
        }
        ++v55;
      }
      while ( v55 < v8->ActiveChains.Size );
    }
  }
  v57 = 1i64;
  v58 = yt - v10;
  if ( v8->ValidChains.Size <= 1 )
    return v6;
  do
  {
    v59 = v57 - 1;
    v106 = v57 - 1;
    if ( (signed int)v57 - 1 >= 0 )
    {
      v60 = v57;
      v107 = v57;
      do
      {
        v61 = v8->ValidChains.Pages;
        v62 = v8->ActiveChains.Pages;
        v63 = v59 & 0xF;
        v105 = v63;
        v103 = (unsigned __int64)v59 >> 4;
        v64 = v61[v103][v63];
        v65 = v62[(unsigned __int64)v64 >> 4][v64 & 0xF];
        v66 = v60 & 0xF;
        v101 = v66;
        v102 = (unsigned __int64)v60 >> 4;
        v67 = v61[v102][v66];
        v68 = v62[(unsigned __int64)v67 >> 4][v67 & 0xF];
        if ( v68->xt >= v65->xt )
          break;
        if ( !v8->Intersections.Size )
        {
          v69 = 0i64;
          v8->ChainsAtBottom.Size = 0i64;
          if ( v8->ActiveChains.Size )
          {
            do
            {
              v70 = v8->ChainsAtBottom.Size >> 4;
              v71 = v8->ActiveChains.Pages[v69 >> 4];
              v72 = v69 & 0xF;
              if ( v70 >= v8->ChainsAtBottom.NumPages )
              {
                v73 = v8->ChainsAtBottom.MaxPages;
                if ( v70 >= v73 )
                {
                  v74 = v8->ChainsAtBottom.pHeap;
                  if ( v8->ChainsAtBottom.Pages )
                  {
                    v75 = Scaleform::Render::LinearHeap::Alloc(v74, 16 * v73);
                    memmove(v75, v8->ChainsAtBottom.Pages, 8 * v8->ChainsAtBottom.NumPages);
                    v76 = v8->ChainsAtBottom.MaxPages;
                    v8->ChainsAtBottom.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)v75;
                    v8->ChainsAtBottom.MaxPages = 2 * v76;
                  }
                  else
                  {
                    v8->ChainsAtBottom.MaxPages = 8i64;
                    v8->ChainsAtBottom.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)Scaleform::Render::LinearHeap::Alloc(
                                                                                                  v74,
                                                                                                  0x40ui64);
                  }
                }
                v8->ChainsAtBottom.Pages[v70] = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                                  v8->ChainsAtBottom.pHeap,
                                                                                                  0x80ui64);
                ++v8->ChainsAtBottom.NumPages;
              }
              ++v69;
              v8->ChainsAtBottom.Pages[v70][v8->ChainsAtBottom.Size & 0xF] = v71[v72];
              ++v8->ChainsAtBottom.Size;
            }
            while ( v69 < v8->ActiveChains.Size );
            v66 = v101;
            v59 = v106;
          }
          v63 = v105;
        }
        v77 = v68->xb;
        v78 = v65->xb;
        v79 = (float)((float)(v68->xt - v77) - v65->xt) + v78;
        if ( v79 != 0.0 )
        {
          v80 = (float)((float)((float)(v78 - v77) * v58) / v79) + v10;
          *(float *)&v104 = v80;
          if ( v80 >= v10 )
            continue;
        }
        v80 = v10;
        *(float *)&v104 = v10;
        if ( v80 > v9 )
          *(float *)&v104 = v9;
        v81 = v8->Intersections.Size >> 4;
        if ( v81 >= v8->Intersections.NumPages )
        {
          v82 = v8->Intersections.MaxPages;
          if ( v81 >= v82 )
          {
            v83 = v8->Intersections.pHeap;
            if ( v8->Intersections.Pages )
            {
              v84 = Scaleform::Render::LinearHeap::Alloc(v83, 16 * v82);
              memmove(v84, v8->Intersections.Pages, 8 * v8->Intersections.NumPages);
              v85 = v8->Intersections.MaxPages;
              v8->Intersections.Pages = (Scaleform::Render::Hairliner::IntersectionType **)v84;
              v8->Intersections.MaxPages = 2 * v85;
            }
            else
            {
              v8->Intersections.MaxPages = 4i64;
              v8->Intersections.Pages = (Scaleform::Render::Hairliner::IntersectionType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                             v83,
                                                                                             0x20ui64);
            }
          }
          v8->Intersections.Pages[v81] = (Scaleform::Render::Hairliner::IntersectionType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                             v8->Intersections.pHeap,
                                                                                             0x180ui64);
          ++v8->Intersections.NumPages;
        }
        --v59;
        v86 = v8->Intersections.Pages[v81];
        v106 = v59;
        v87 = v8->Intersections.Size & 0xF;
        v86[v87].mc1 = v65;
        v86[v87].mc2 = v68;
        *(_QWORD *)&v86[v87].y = v104;
        ++v8->Intersections.Size;
        v88 = v8->ValidChains.Pages;
        v89 = v8->ActiveChains.Pages;
        v90 = v88[v102][v66];
        v91 = v88[v103][v63];
        v92 = v90;
        v93 = v90 & 0xF;
        v94 = v89[v92 >> 4];
        v95 = v91;
        v96 = v91 & 0xF;
        v97 = v89[v95 >> 4];
        v98 = v97[v96];
        v97[v96] = v94[v93];
        v60 = v107 - 1;
        v94[v93] = v98;
        --v107;
      }
      while ( v59 >= 0 );
      v57 = v100;
    }
    v100 = ++v57;
  }
  while ( v57 < v8->ValidChains.Size );
  return numMca;
}

// File Line: 480
// RVA: 0x9C6950
__int64 __fastcall Scaleform::Render::Hairliner::addEventVertex(Scaleform::Render::Hairliner *this, Scaleform::Render::Hairliner::SrcVertexType *v1)
{
  Scaleform::Render::Hairliner *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm7_4
  unsigned __int64 v5; // rsi
  signed __int64 v6; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v7; // rax

  v2 = this;
  if ( this->LastY != v1->y || this->LastX != v1->x )
  {
    this->LastX = v1->x;
    this->LastY = v1->y;
    v3 = v1->x;
    v4 = v1->y;
    v5 = this->OutVertices.Size >> 4;
    if ( v5 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->OutVertices,
        this->OutVertices.Size >> 4);
    v6 = v2->OutVertices.Size & 0xF;
    v7 = v2->OutVertices.Pages[v5];
    v7[v6].x = v3;
    v7[v6].y = v4;
    v7[v6].alpha = 1;
    ++v2->OutVertices.Size;
  }
  return (unsigned int)(LODWORD(v2->OutVertices.Size) - 1);
}

// File Line: 495
// RVA: 0x9C6A20
signed __int64 __fastcall Scaleform::Render::Hairliner::addEventVertex(Scaleform::Render::Hairliner *this, Scaleform::Render::Hairliner::MonoChainType *mc, float yb, bool enforce)
{
  Scaleform::Render::Hairliner *v4; // rbx
  Scaleform::Render::Hairliner::SrcVertexType **v5; // r8
  unsigned __int64 v6; // rdx
  signed __int64 result; // rax
  Scaleform::Render::Hairliner::SrcVertexType **v8; // r9
  Scaleform::Render::Hairliner::SrcEdgeType *v9; // r9
  Scaleform::Render::Hairliner::SrcVertexType *v10; // rcx
  float v11; // xmm7_4
  unsigned __int64 v12; // rsi
  signed __int64 v13; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v14; // rax

  v4 = this;
  if ( enforce )
  {
    if ( mc->flags & 1
      && (v8 = this->SrcVertices.Pages, yb == v8[(unsigned __int64)mc->edge->upper >> 4][mc->edge->upper & 0xF].y) )
    {
      result = Scaleform::Render::Hairliner::addEventVertex(
                 this,
                 &v8[(unsigned __int64)mc->edge->upper >> 4][mc->edge->upper & 0xF]);
    }
    else
    {
      v9 = mc->edge;
      v5 = this->SrcVertices.Pages;
      v6 = mc->edge->lower;
      if ( yb == v5[(unsigned __int64)(unsigned int)v6 >> 4][v6 & 0xF].y )
        return Scaleform::Render::Hairliner::addEventVertex(this, &v5[v6 >> 4][v6 & 0xF]);
      v10 = v5[(unsigned __int64)v9->lower >> 4];
      v11 = (float)((float)(yb - v10[v9->lower & 0xF].y) * v9->slope) + v10[v9->lower & 0xF].x;
      if ( yb != v4->LastY || COERCE_FLOAT(COERCE_UNSIGNED_INT(v11 - v4->LastX) & _xmm) > v4->Epsilon )
      {
        v4->LastX = v11;
        v4->LastY = yb;
        v12 = v4->OutVertices.Size >> 4;
        if ( v12 >= v4->OutVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v4->OutVertices,
            v12);
        v13 = v4->OutVertices.Size & 0xF;
        v14 = v4->OutVertices.Pages[v12];
        v14[v13].x = v11;
        v14[v13].y = yb;
        v14[v13].alpha = 1;
        ++v4->OutVertices.Size;
      }
      result = (unsigned int)(LODWORD(v4->OutVertices.Size) - 1);
    }
  }
  else
  {
    if ( mc->flags & 2 )
    {
      v5 = this->SrcVertices.Pages;
      v6 = mc->edge->lower;
      if ( yb == v5[(unsigned __int64)(unsigned int)v6 >> 4][v6 & 0xF].y )
        return Scaleform::Render::Hairliner::addEventVertex(this, &v5[v6 >> 4][v6 & 0xF]);
    }
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 571
// RVA: 0x9E0550
void __fastcall Scaleform::Render::Hairliner::emitEdge(Scaleform::Render::Hairliner *this, unsigned int v1, unsigned int v2)
{
  Scaleform::Render::Hairliner *v3; // rbx
  Scaleform::Render::Hairliner::OutVertexType **v4; // rcx
  unsigned int v5; // esi
  __int64 v6; // r9
  float v7; // xmm6_4
  Scaleform::Render::Hairliner::OutVertexType *v8; // r8
  __int64 v9; // r11
  unsigned int v10; // ebp
  Scaleform::Render::Hairliner::OutVertexType *v11; // rcx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *v16; // rbx
  unsigned __int64 v17; // rdi
  signed __int64 v18; // rdx
  Scaleform::Render::StrokerAA::VertexType *v19; // rax
  float v20; // xmm6_4
  unsigned __int64 v21; // rdi
  signed __int64 v22; // rdx
  Scaleform::Render::StrokerAA::VertexType *v23; // rax
  unsigned int v24; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = this->OutVertices.Pages;
  v5 = v2;
  v6 = v2 & 0xF;
  v7 = 0.0;
  v8 = v4[(unsigned __int64)v2 >> 4];
  v9 = v1 & 0xF;
  v10 = v1;
  v11 = v4[(unsigned __int64)v1 >> 4];
  v24 = v1;
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
  v16 = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v3->FanEdges;
  v17 = v16->Size >> 4;
  if ( v17 >= v16->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(v16, v16->Size >> 4);
  v18 = v16->Size & 0xF;
  v19 = v16->Pages[v17];
  LODWORD(v19[v18].x) = v24;
  LODWORD(v19[v18].y) = v5;
  *(float *)&v19[v18].style = v7;
  ++v16->Size;
  v20 = v7 - 1.0;
  if ( v20 < -1.0 )
    v20 = v20 + 2.0;
  v21 = v16->Size >> 4;
  if ( v21 >= v16->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(v16, v16->Size >> 4);
  v22 = v16->Size & 0xF;
  v23 = v16->Pages[v21];
  LODWORD(v23[v22].x) = v5;
  LODWORD(v23[v22].y) = v10;
  *(float *)&v23[v22].style = v20;
  ++v16->Size;
}

// File Line: 609
// RVA: 0x9ED2F0
__int64 __fastcall Scaleform::Render::Hairliner::processHorizontalEdges(Scaleform::Render::Hairliner *this, Scaleform::Render::Hairliner::MonoChainType *mc, unsigned int vertex, float yb)
{
  unsigned int v4; // er14
  char v5; // r15
  unsigned int v6; // ebx
  Scaleform::Render::Hairliner::MonoChainType *v7; // r12
  Scaleform::Render::Hairliner *v8; // rbp
  float v9; // xmm6_4
  Scaleform::Render::Hairliner::HorizontalEdgeType *v10; // rsi
  signed __int64 v11; // rdx
  signed __int64 v12; // rdi
  unsigned int v13; // er9
  unsigned int v14; // edx
  Scaleform::Render::Hairliner::SrcEdgeType *v15; // r10
  Scaleform::Render::Hairliner::SrcVertexType **v16; // r11
  unsigned int v17; // edx
  unsigned int v18; // ecx
  unsigned __int64 v19; // rax
  __int64 v20; // rdx
  Scaleform::Render::Hairliner::SrcVertexType *v21; // r9
  unsigned __int64 v22; // rax
  __int64 v23; // rcx
  Scaleform::Render::Hairliner::SrcVertexType *v24; // r8
  Scaleform::Render::Hairliner::SrcVertexType *v25; // rcx
  float v26; // xmm0_4
  bool v27; // zf
  Scaleform::Render::Hairliner::SrcVertexType v29; // [rsp+20h] [rbp-58h]
  Scaleform::Render::Hairliner::SrcVertexType v1; // [rsp+80h] [rbp+8h]

  v4 = 0;
  v5 = 0;
  v6 = vertex;
  v7 = mc;
  v8 = this;
  v9 = 0.0;
  if ( this->NumHorizontals )
  {
    do
    {
      v10 = v8->HorizontalEdges.Pages[(unsigned __int64)(v4 + v8->StartHorizontals) >> 2];
      v11 = ((_BYTE)v4 + LOBYTE(v8->StartHorizontals)) & 3;
      v12 = v11;
      if ( v6 == -1 )
        goto LABEL_34;
      v13 = v10[v11].rv;
      if ( v13 == -1 && v8->OutVertices.Pages[(unsigned __int64)v6 >> 4][v6 & 0xF].x == v10[v11].x1 )
      {
        v10[v11].rv = v6;
LABEL_29:
        v10[v12].lv = v6;
        goto LABEL_30;
      }
      if ( v8->OutVertices.Pages[(unsigned __int64)v6 >> 4][v6 & 0xF].x != v10[v11].x2 )
      {
LABEL_34:
        if ( !v5 )
        {
          v15 = v7->edge;
          v16 = v8->SrcVertices.Pages;
          v17 = v7->edge->lower;
          v18 = v7->edge->upper;
          v19 = v17;
          v20 = v17 & 0xF;
          v21 = v16[v19 >> 4];
          v22 = v18;
          v23 = v18 & 0xF;
          v24 = v16[v22 >> 4];
          if ( yb == v21[v20].y )
          {
            v9 = v21[v20].x;
          }
          else if ( yb == v24[v23].y )
          {
            v9 = v24[v23].x;
          }
          else
          {
            v25 = v16[(unsigned __int64)v15->lower >> 4];
            v9 = (float)((float)(yb - v25[v15->lower & 0xF].y) * v15->slope) + v25[v15->lower & 0xF].x;
          }
          v5 = 1;
        }
        v26 = v10[v12].x1;
        if ( v9 == v26 )
        {
          v1.x = v9;
          v1.y = yb;
          if ( v6 == -1 )
            v6 = Scaleform::Render::Hairliner::addEventVertex(v8, &v1);
          v10[v12].rv = v6;
          goto LABEL_30;
        }
        if ( v9 < v26 || v9 > v10[v12].x2 )
          goto LABEL_30;
        v29.x = v9;
        v29.y = yb;
        if ( v6 == -1 )
          v6 = Scaleform::Render::Hairliner::addEventVertex(v8, &v29);
        v14 = v10[v12].rv;
        if ( v14 != -1 && v14 != v6 )
          goto LABEL_27;
      }
      else if ( v13 != -1 && v13 != v6 )
      {
        v14 = v10[v11].rv;
LABEL_27:
        Scaleform::Render::Hairliner::emitEdge(v8, v14, v6);
        goto LABEL_28;
      }
LABEL_28:
      v27 = v10[v12].lv == -1;
      v10[v12].rv = v6;
      if ( v27 )
        goto LABEL_29;
LABEL_30:
      ++v4;
    }
    while ( v4 < v8->NumHorizontals );
  }
  return v6;
}

// File Line: 659
// RVA: 0x9F3CF0
void __fastcall Scaleform::Render::Hairliner::sweepScanbeam(Scaleform::Render::Hairliner *this, Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8> *aet, float yb)
{
  unsigned __int64 v3; // r15
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8> *v4; // r14
  Scaleform::Render::Hairliner *v5; // rbx
  unsigned __int64 v6; // rsi
  Scaleform::Render::Hairliner::MonoChainType *v7; // rbp
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // rdi
  Scaleform::Render::Hairliner::HorizontalEdgeType *v15; // rsi
  unsigned int v16; // eax
  float v17; // xmm7_4
  unsigned __int64 v18; // r14
  signed __int64 v19; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v20; // rax
  unsigned int v21; // eax
  float v22; // xmm7_4
  unsigned __int64 v23; // r14
  signed __int64 v24; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v25; // rax
  float v26; // xmm8_4
  float v27; // xmm7_4
  unsigned __int64 v28; // rsi
  signed __int64 v29; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v30; // rax
  unsigned __int64 v31; // rbp
  signed __int64 v32; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v33; // rax

  v3 = 0i64;
  v4 = aet;
  v5 = this;
  v6 = 0i64;
  if ( aet->Size )
  {
    do
    {
      v7 = v4->Pages[v6 >> 4][v6 & 0xF];
      v8 = Scaleform::Render::Hairliner::addEventVertex(v5, v7, yb, v7->flags & 1);
      v9 = v8;
      if ( v5->NumHorizontals )
        v9 = Scaleform::Render::Hairliner::processHorizontalEdges(v5, v7, v8, yb);
      if ( v9 != -1 )
      {
        v10 = v7->prevVertex;
        if ( v10 != -1 && v10 != v9 )
          Scaleform::Render::Hairliner::emitEdge(v5, v10, v9);
        v7->prevVertex = v9;
      }
      ++v6;
    }
    while ( v6 < v4->Size );
  }
  if ( v5->NumHorizontals > 0 )
  {
    do
    {
      v11 = v3 + v5->StartHorizontals;
      v12 = v11;
      v13 = v11 & 3;
      v14 = v13;
      v15 = v5->HorizontalEdges.Pages[v12 >> 2];
      v16 = v15[v13].lv;
      if ( v16 != -1 )
      {
        v17 = v15[v13].x1;
        if ( v17 != v5->OutVertices.Pages[(unsigned __int64)v16 >> 4][v16 & 0xF].x )
        {
          if ( yb != v5->LastY || v17 != v5->LastX )
          {
            v5->LastX = v17;
            v5->LastY = yb;
            v18 = v5->OutVertices.Size >> 4;
            if ( v18 >= v5->OutVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v5->OutVertices,
                v18);
            v19 = v5->OutVertices.Size & 0xF;
            v20 = v5->OutVertices.Pages[v18];
            v20[v19].x = v17;
            v20[v19].y = yb;
            v20[v19].alpha = 1;
            ++v5->OutVertices.Size;
          }
          Scaleform::Render::Hairliner::emitEdge(v5, v15[v14].lv, LODWORD(v5->OutVertices.Size) - 1);
        }
      }
      v21 = v15[v14].rv;
      if ( v21 != -1 )
      {
        v22 = v15[v14].x2;
        if ( v22 != v5->OutVertices.Pages[(unsigned __int64)v21 >> 4][v21 & 0xF].x )
        {
          if ( yb != v5->LastY || v22 != v5->LastX )
          {
            v5->LastX = v22;
            v5->LastY = yb;
            v23 = v5->OutVertices.Size >> 4;
            if ( v23 >= v5->OutVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v5->OutVertices,
                v23);
            v24 = v5->OutVertices.Size & 0xF;
            v25 = v5->OutVertices.Pages[v23];
            v25[v24].x = v22;
            v25[v24].y = yb;
            v25[v24].alpha = 1;
            ++v5->OutVertices.Size;
          }
          Scaleform::Render::Hairliner::emitEdge(v5, v15[v14].rv, LODWORD(v5->OutVertices.Size) - 1);
        }
      }
      if ( v15[v14].lv == -1 && v15[v14].rv == -1 )
      {
        v26 = v15[v14].x1;
        v27 = v15[v14].x2;
        if ( yb != v5->LastY || v27 != v5->LastX )
        {
          v5->LastX = v27;
          v5->LastY = yb;
          v28 = v5->OutVertices.Size >> 4;
          if ( v28 >= v5->OutVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v5->OutVertices,
              v28);
          v29 = v5->OutVertices.Size & 0xF;
          v30 = v5->OutVertices.Pages[v28];
          v30[v29].x = v27;
          v30[v29].y = yb;
          v30[v29].alpha = 1;
          ++v5->OutVertices.Size;
        }
        v31 = v5->OutVertices.Size;
        if ( yb != v5->LastY || v26 != v5->LastX )
        {
          v5->LastX = v26;
          v5->LastY = yb;
          if ( v31 >> 4 >= v5->OutVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v5->OutVertices,
              v31 >> 4);
          v32 = v5->OutVertices.Size & 0xF;
          v33 = v5->OutVertices.Pages[v31 >> 4];
          v33[v32].x = v26;
          v33[v32].y = yb;
          v33[v32].alpha = 1;
          ++v5->OutVertices.Size;
        }
        Scaleform::Render::Hairliner::emitEdge(v5, LODWORD(v5->OutVertices.Size) - 1, v31 - 1);
      }
      ++v3;
    }
    while ( v3 < v5->NumHorizontals );
  }
}

// File Line: 703
// RVA: 0x9ED520
void __fastcall Scaleform::Render::Hairliner::processInterior(Scaleform::Render::Hairliner *this, float yb)
{
  Scaleform::Render::Hairliner *v2; // rbx
  unsigned __int64 v3; // rdi
  signed __int64 v4; // rax
  Scaleform::Render::Hairliner::IntersectionType *v5; // r14
  signed __int64 v6; // rbp
  float v7; // xmm2_4
  unsigned int v8; // eax
  Scaleform::Render::Hairliner::MonoChainType *v9; // r15
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // eax
  Scaleform::Render::Hairliner::MonoChainType *v13; // rbp
  unsigned int v14; // edx
  unsigned int v15; // esi

  v2 = this;
  Scaleform::Render::Hairliner::sweepScanbeam(this, &this->ChainsAtBottom, yb);
  v3 = 0i64;
  if ( v2->Intersections.Size )
  {
    do
    {
      v4 = v3 & 0xF;
      v5 = v2->Intersections.Pages[v3 >> 4];
      v6 = v4;
      v7 = v5[v4].y;
      if ( v7 > yb )
      {
        v8 = Scaleform::Render::Hairliner::addEventVertex(v2, v5[v4].mc1, v7, 1);
        v9 = v5[v6].mc1;
        v10 = v9->prevVertex;
        v11 = v8;
        if ( v10 != -1 && v10 != v8 )
          Scaleform::Render::Hairliner::emitEdge(v2, v10, v8);
        v9->prevVertex = v11;
        v12 = Scaleform::Render::Hairliner::addEventVertex(v2, v5[v6].mc2, v5[v6].y, 1);
        v13 = v5[v6].mc2;
        v14 = v13->prevVertex;
        v15 = v12;
        if ( v14 != -1 && v14 != v12 )
          Scaleform::Render::Hairliner::emitEdge(v2, v14, v12);
        v13->prevVertex = v15;
      }
      ++v3;
    }
    while ( v3 < v2->Intersections.Size );
  }
}

// File Line: 720
// RVA: 0x9CFB80
void __fastcall Scaleform::Render::Hairliner::buildGraph(Scaleform::Render::Hairliner *this)
{
  unsigned __int64 v1; // rax
  Scaleform::Render::Hairliner *v2; // rdi
  unsigned __int64 v3; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r8
  float v8; // xmm2_4
  unsigned int **v9; // rbx
  __int64 v10; // r9
  Scaleform::Render::Hairliner::SrcVertexType *v11; // r10
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rbx
  unsigned __int64 v15; // r14
  unsigned __int64 v16; // rbp
  signed __int64 v17; // rsi
  unsigned __int64 v18; // rdx
  Scaleform::Render::LinearHeap *v19; // rcx
  void *v20; // rbx
  unsigned __int64 v21; // rax
  unsigned int v22; // ebp
  unsigned int v23; // er13
  unsigned int v24; // er14
  float v25; // xmm7_4
  float v26; // xmm6_4
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // rdx
  unsigned int v30; // er9
  unsigned __int64 v31; // r8
  char v32; // r15
  unsigned int v33; // edx
  unsigned int v34; // er10
  unsigned __int64 v35; // rcx
  Scaleform::Render::Hairliner::MonoChainType ***v36; // r8
  Scaleform::Render::Hairliner::MonoChainType *v37; // r9
  unsigned __int64 v38; // rax
  __int64 v39; // rcx

  v1 = this->SrcVertices.Size;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    if ( v1 )
    {
      v4 = (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->Scanbeams;
      do
      {
        v5 = v4->Size >> 4;
        if ( v5 >= v4->NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(v4, v4->Size >> 4);
        v4->Pages[v5][v4->Size & 0xF] = (Scaleform::Render::GlyphFitter::VertexType)v3;
        ++v4->Size;
        ++v3;
      }
      while ( v3 < v2->SrcVertices.Size );
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
      &v2->Scanbeams,
      0i64,
      v2->Scanbeams.Size,
      (Scaleform::Render::Tessellator::CmpScanbeams)&v2->SrcVertices);
    v6 = 0i64;
    v7 = 0i64;
    v8 = FLOAT_N1_0e30;
    if ( v2->Scanbeams.Size )
    {
      do
      {
        v9 = v2->Scanbeams.Pages;
        v10 = v9[v6 >> 4][v6 & 0xF] & 0xF;
        v11 = v2->SrcVertices.Pages[(unsigned __int64)v9[v6 >> 4][v6 & 0xF] >> 4];
        if ( (float)(v11[v10].y - v8) <= (float)(COERCE_FLOAT(LODWORD(v11[v10].y) & _xmm) * v2->Epsilon) )
        {
          v11[v10].y = v8;
        }
        else
        {
          v12 = v7 >> 4;
          v13 = v7++ & 0xF;
          v9[v12][v13] = v9[v6 >> 4][v6 & 0xF];
          v8 = v11[v10].y;
        }
        ++v6;
      }
      while ( v6 < v2->Scanbeams.Size );
    }
    if ( v7 < v2->Scanbeams.Size )
      v2->Scanbeams.Size = v7;
    v14 = 0i64;
    if ( v2->Paths.Size )
    {
      do
      {
        Scaleform::Render::Hairliner::decomposePath(v2, &v2->Paths.Pages[v14 >> 4][v14 & 0xF]);
        ++v14;
      }
      while ( v14 < v2->Paths.Size );
    }
    v15 = 0i64;
    if ( v2->MonoChains.Size )
    {
      do
      {
        v16 = v2->MonoChainsSorted.Size >> 4;
        v17 = (signed __int64)&v2->MonoChains.Pages[v15 >> 4][v15 & 0xF];
        if ( v16 >= v2->MonoChainsSorted.NumPages )
        {
          v18 = v2->MonoChainsSorted.MaxPages;
          if ( v16 >= v18 )
          {
            v19 = v2->MonoChainsSorted.pHeap;
            if ( v2->MonoChainsSorted.Pages )
            {
              v20 = Scaleform::Render::LinearHeap::Alloc(v19, 16 * v18);
              memmove(v20, v2->MonoChainsSorted.Pages, 8 * v2->MonoChainsSorted.NumPages);
              v21 = v2->MonoChainsSorted.MaxPages;
              v2->MonoChainsSorted.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)v20;
              v2->MonoChainsSorted.MaxPages = 2 * v21;
            }
            else
            {
              v2->MonoChainsSorted.MaxPages = 8i64;
              v2->MonoChainsSorted.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)Scaleform::Render::LinearHeap::Alloc(
                                                                                              v19,
                                                                                              0x40ui64);
            }
          }
          v2->MonoChainsSorted.Pages[v16] = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                              v2->MonoChainsSorted.pHeap,
                                                                                              0x80ui64);
          ++v2->MonoChainsSorted.NumPages;
        }
        ++v15;
        v2->MonoChainsSorted.Pages[v16][v2->MonoChainsSorted.Size & 0xF] = (Scaleform::Render::Hairliner::MonoChainType *)v17;
        ++v2->MonoChainsSorted.Size;
      }
      while ( v15 < v2->MonoChains.Size );
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>,bool (*)(Scaleform::Render::Hairliner::HorizontalEdgeType const &,Scaleform::Render::Hairliner::HorizontalEdgeType const &)>(
      &v2->HorizontalEdges,
      0i64,
      v2->HorizontalEdges.Size,
      (bool (__fastcall *)(Scaleform::Render::Hairliner::HorizontalEdgeType *, Scaleform::Render::Hairliner::HorizontalEdgeType *))UFG::SectionChooser::fnSectionStreamPriority);
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>,bool (*)(Scaleform::Render::Hairliner::MonoChainType const *,Scaleform::Render::Hairliner::MonoChainType const *)>(
      &v2->MonoChainsSorted,
      0i64,
      v2->MonoChainsSorted.Size,
      (bool (__fastcall *)(Scaleform::Render::Hairliner::MonoChainType *, Scaleform::Render::Hairliner::MonoChainType *))Scaleform::Render::Hairliner::cmpMonoChains);
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v25 = v2->SrcVertices.Pages[(unsigned __int64)**v2->Scanbeams.Pages >> 4][**v2->Scanbeams.Pages & 0xF].y;
    v2->LastX = -1.0e30;
    v2->LastY = -1.0e30;
    v26 = v25;
    if ( v2->Scanbeams.Size )
    {
      v27 = 0i64;
      v28 = 0i64;
      do
      {
        if ( ++v23 < v2->Scanbeams.Size )
          v25 = v2->SrcVertices.Pages[(unsigned __int64)v2->Scanbeams.Pages[(unsigned __int64)v23 >> 4][v23 & 0xF] >> 4][v2->Scanbeams.Pages[(unsigned __int64)v23 >> 4][v23 & 0xF] & 0xF].y;
        v29 = v2->MonoChainsSorted.Size;
        v30 = v22;
        if ( v27 < v29 )
        {
          do
          {
            if ( v26 < v2->MonoChainsSorted.Pages[v27 >> 4][v27 & 0xF]->ySort )
              break;
            v27 = ++v22;
          }
          while ( v22 < v29 );
        }
        v31 = v2->HorizontalEdges.Size;
        v2->StartHorizontals = v24;
        if ( v28 < v31 )
        {
          do
          {
            if ( v26 < v2->HorizontalEdges.Pages[v28 >> 2][v28 & 3].y )
              break;
            v28 = ++v24;
          }
          while ( v24 < v31 );
        }
        v2->NumHorizontals = v24 - v2->StartHorizontals;
        v32 = Scaleform::Render::Hairliner::nextScanbeam(v2, v26, v25, v30, v22 - v30);
        if ( v2->Intersections.Size )
          Scaleform::Render::Hairliner::processInterior(v2, v26);
        else
          Scaleform::Render::Hairliner::sweepScanbeam(v2, &v2->ActiveChains, v26);
        if ( v32 & 2 )
        {
          v33 = 0;
          v34 = 0;
          if ( v2->ActiveChains.Size )
          {
            v35 = 0i64;
            do
            {
              v36 = v2->ActiveChains.Pages;
              v37 = v36[v35 >> 4][v35 & 0xF];
              if ( !(v37->flags & 1) )
              {
                v38 = (unsigned __int64)v34 >> 4;
                v39 = v34++ & 0xF;
                v36[v38][v39] = v37;
              }
              v35 = ++v33;
            }
            while ( v33 < v2->ActiveChains.Size );
          }
          if ( v34 < v2->ActiveChains.Size )
            v2->ActiveChains.Size = v34;
        }
        v26 = v25;
      }
      while ( v23 < v2->Scanbeams.Size );
    }
  }
}

// File Line: 829
// RVA: 0x9E3E80
void __fastcall Scaleform::Render::Hairliner::generateContourAA(Scaleform::Render::Hairliner *this, unsigned int startEdgeIdx)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  __int64 v4; // r9
  Scaleform::Render::Hairliner *v5; // r13
  Scaleform::Render::Hairliner::FanEdgeType *v6; // rax
  signed __int64 v7; // r12
  Scaleform::Render::Hairliner::FanEdgeType *v8; // rbx
  unsigned int v9; // er15
  signed __int64 v10; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v11; // r14
  signed __int64 v12; // rbp
  unsigned __int64 v13; // rsi
  signed __int64 v14; // r8
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // r11
  Scaleform::Render::Hairliner::FanEdgeType **v17; // rdi
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // r9
  unsigned int v20; // eax
  unsigned int v21; // edx
  __int64 v22; // rax
  int v23; // er9
  Scaleform::Render::Hairliner::OutVertexType **v24; // r8
  unsigned __int64 v25; // r10
  unsigned int v26; // edx
  signed __int64 v27; // r11
  Scaleform::Render::Hairliner::OutVertexType *v28; // rbx
  unsigned int v29; // edx
  signed __int64 v30; // rcx
  Scaleform::Render::Hairliner::OutVertexType *v31; // rdx

  v2 = FLOAT_N1_0e30;
  v3 = FLOAT_N1_0e30;
  v4 = startEdgeIdx & 0xF;
  v5 = this;
  v6 = this->FanEdges.Pages[(unsigned __int64)startEdgeIdx >> 4];
  this->ContourNodes.Size = 0i64;
  v7 = (signed __int64)&v6[v4];
  v8 = &v6[v4];
  do
  {
    if ( (v8->node1 & 0x80000000) != 0 )
      break;
    v9 = v8->node1 & 0x7FFFFFFF;
    v10 = v8->node1 & 0xF;
    v11 = v5->OutVertices.Pages[(unsigned __int64)v9 >> 4];
    v12 = v10;
    if ( v2 != v11[v10].x || v3 != v11[v10].y )
    {
      v13 = v5->ContourNodes.Size >> 4;
      if ( v13 >= v5->ContourNodes.NumPages )
        Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v5->ContourNodes,
          v5->ContourNodes.Size >> 4);
      v5->ContourNodes.Pages[v13][v5->ContourNodes.Size & 0xF] = v9;
      ++v5->ContourNodes.Size;
      v2 = v11[v12].x;
      v3 = v11[v12].y;
    }
    v8->node1 |= 0x80000000;
    v14 = v5->FanEdges.Size;
    v15 = 0i64;
    while ( v14 > 0 )
    {
      if ( (v5->FanEdges.Pages[((v14 >> 1) + v15) >> 4][((unsigned __int8)(v14 >> 1) + (_BYTE)v15) & 0xF].node1 & 0x7FFFFFFF) >= v8->node2 )
      {
        v14 >>= 1;
      }
      else
      {
        v15 += (v14 >> 1) + 1;
        v14 += -1 - (v14 >> 1);
      }
    }
    v16 = v5->FanEdges.Size;
    if ( v15 >= v16 )
      break;
    v17 = v5->FanEdges.Pages;
    v18 = 0i64;
    v19 = v15;
    do
    {
      if ( (v17[v19 >> 4][v19 & 0xF].node1 & 0x7FFFFFFF) != v8->node2 )
        break;
      ++v19;
      ++v18;
    }
    while ( v19 < v16 );
    if ( v18 == 1 )
    {
      v8 = &v17[v15 >> 4][v15 & 0xF];
    }
    else if ( v18 == 2 )
    {
      v8 = &v17[v15 >> 4][v15 & 0xF];
      v20 = v8->node2;
      if ( v20 == v17[(v15 + 1) >> 4][((_DWORD)v15 + 1) & 0xF].node2 )
      {
        if ( (v8->node1 & 0x80000000) != 0 )
          v8 = &v17[(v15 + 1) >> 4][((_DWORD)v15 + 1) & 0xF];
      }
      else if ( v20 == v9 )
      {
        v8 = &v17[(v15 + 1) >> 4][((_DWORD)v15 + 1) & 0xF];
      }
    }
    else
    {
      v21 = 0;
      if ( v18 )
      {
        v22 = 0i64;
        while ( v17[(v22 + v15) >> 4][((_DWORD)v22 + (_DWORD)v15) & 0xF].node2 != v9 )
        {
          v22 = ++v21;
          if ( v21 >= v18 )
            goto LABEL_38;
        }
        v23 = 0;
        while ( 1 )
        {
          if ( ++v21 >= v18 )
            v21 = 0;
          v8 = &v17[(v15 + v21) >> 4][((_DWORD)v15 + v21) & 0xF];
          if ( v8 == (Scaleform::Render::Hairliner::FanEdgeType *)v7 )
            goto LABEL_39;
          if ( (v8->node1 & 0x80000000) != 0 && (unsigned int)++v23 < v18 )
            continue;
          break;
        }
      }
    }
LABEL_38:
    ;
  }
  while ( v8 != (Scaleform::Render::Hairliner::FanEdgeType *)v7 );
LABEL_39:
  if ( v5->ContourNodes.Size )
  {
    v24 = v5->OutVertices.Pages;
    v25 = v5->ContourNodes.Size;
    v26 = **v5->ContourNodes.Pages;
    v27 = v26 & 0xF;
    v28 = v24[(unsigned __int64)v26 >> 4];
    v29 = v5->ContourNodes.Pages[(v25 - 1) >> 4][((_BYTE)v25 - 1) & 0xF];
    v30 = v29 & 0xF;
    v31 = v24[(unsigned __int64)v29 >> 4];
    if ( v31[v30].x == v28[v27].x && v31[v30].y == v28[v27].y )
    {
      if ( v25 )
        v5->ContourNodes.Size = v25 - 1;
    }
  }
}

// File Line: 924
// RVA: 0x9C7E10
signed __int64 __fastcall Scaleform::Render::Hairliner::addJoin(Scaleform::Render::Hairliner *this, unsigned int refVertex, Scaleform::Render::Hairliner::OutVertexType *v1, Scaleform::Render::Hairliner::OutVertexType *v2, Scaleform::Render::Hairliner::OutVertexType *v3, float len1, float len2, float width)
{
  Scaleform::Render::Hairliner::OutVertexType *v8; // rsi
  Scaleform::Render::Hairliner::OutVertexType *v9; // rdi
  unsigned int v10; // er14
  Scaleform::Render::Hairliner *v11; // rbp
  float v12; // xmm8_4
  Scaleform::Render::Hairliner::OutVertexType *v13; // rbx
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm9_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm10_4
  float v21; // xmm4_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  unsigned __int64 v24; // rdi
  signed __int64 result; // rax
  signed __int64 v26; // r8
  Scaleform::Render::Hairliner::OutVertexType *v27; // rcx
  float v28; // xmm2_4
  float v29; // xmm11_4
  float v30; // xmm12_4
  float v31; // xmm14_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm13_4
  float v35; // xmm1_4
  __m128 v36; // xmm0
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  unsigned __int64 v40; // rdi
  signed __int64 v41; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v42; // rax
  unsigned __int64 v43; // rdi
  signed __int64 v44; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v45; // rax
  signed __int64 v46; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v47; // rax
  float v48; // xmm12_4
  float v49; // xmm9_4
  float v50; // xmm10_4
  float v51; // xmm11_4
  signed __int64 v52; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v53; // rax
  unsigned __int64 v54; // rdi
  signed __int64 v55; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v56; // rax
  float v57; // xmm12_4
  float v58; // xmm14_4
  unsigned __int64 v59; // rdi
  float v60; // xmm13_4
  signed __int64 v61; // rdx
  Scaleform::Render::Hairliner::OutVertexType *v62; // rax
  unsigned __int64 v63; // rdi
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *v64; // rbp
  int v65; // eax
  unsigned __int64 v66; // rbx
  int v67; // esi
  int v68; // edi
  signed __int64 v69; // rdx
  Scaleform::Render::StrokerAA::VertexType *v70; // rax
  float v71; // [rsp+30h] [rbp-F8h]
  float v72; // [rsp+34h] [rbp-F4h]
  float v73; // [rsp+130h] [rbp+8h]
  float v74; // [rsp+140h] [rbp+18h]
  float v75; // [rsp+148h] [rbp+20h]
  float v3a; // [rsp+150h] [rbp+28h]
  float len1a; // [rsp+158h] [rbp+30h]
  int len1b; // [rsp+158h] [rbp+30h]

  v8 = v3;
  v9 = v1;
  v10 = refVertex;
  v11 = this;
  v12 = len1;
  v13 = v2;
  v14 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(
          (Scaleform::Render::TessVertex *)v1,
          (Scaleform::Render::TessVertex *)v2,
          (Scaleform::Render::TessVertex *)v3,
          len1,
          len2);
  v15 = v13->x;
  v16 = v13->y;
  v75 = (float)(len1 + len2) * v11->IntersectionEpsilon;
  v72 = v14;
  v17 = (float)((float)(v9->y - v16) * width) * (float)(1.0 / len1);
  v18 = (float)((float)(v13->x - v9->x) * width) * (float)(1.0 / len1);
  v19 = v3->y;
  v20 = (float)((float)(v3->x - v13->x) * width) * (float)(1.0 / len2);
  v21 = (float)((float)(v16 - v19) * width) * (float)(1.0 / len2);
  if ( COERCE_FLOAT(LODWORD(v14) & _xmm) < 0.125 )
  {
    if ( len1 <= len2 )
    {
      v22 = v15 + v21;
      v23 = v16 + v20;
    }
    else
    {
      v22 = v15 + v17;
      v23 = v16 + v18;
    }
    v24 = v11->OutVertices.Size >> 4;
    if ( v24 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    result = 1i64;
    v26 = v11->OutVertices.Size & 0xF;
    v27 = v11->OutVertices.Pages[v24];
    v27[v26].x = v22;
    v27[v26].y = v23;
    v27[v26].alpha = 0;
    ++v11->OutVertices.Size;
    return result;
  }
  v28 = v9->y;
  v73 = v28 + v18;
  v29 = v16 + v20;
  v30 = v15 + v17;
  v74 = (float)(v19 + v20) - (float)(v16 + v20);
  v3a = v9->x + v17;
  v31 = v16 + v18;
  v32 = (float)(v16 + v18) - (float)(v28 + v18);
  v33 = (float)(v15 + v17) - v3a;
  len1a = v32;
  v34 = v15 + v21;
  v71 = (float)(v8->x + v21) - (float)(v15 + v21);
  v35 = (float)(v74 * v33) - (float)(v71 * v32);
  if ( COERCE_FLOAT(LODWORD(v35) & _xmm) < v75 )
  {
    v57 = v30 - v18;
    v58 = v31 + v17;
    v59 = v11->OutVertices.Size >> 4;
    v60 = v34 + v20;
    v51 = v29 - v21;
    if ( v59 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    v61 = v11->OutVertices.Size & 0xF;
    v62 = v11->OutVertices.Pages[v59];
    v62[v61].x = v57;
    v62[v61].y = v58;
    v62[v61].alpha = 0;
    v63 = ++v11->OutVertices.Size >> 4;
    if ( v63 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    v55 = v11->OutVertices.Size & 0xF;
    v56 = v11->OutVertices.Pages[v63];
    v56[v11->OutVertices.Size & 0xF].x = v60;
    goto LABEL_32;
  }
  v36 = (__m128)LODWORD(len1a);
  v37 = (float)((float)((float)(v73 - v29) * v71) - (float)((float)(v3a - v34) * v74)) / v35;
  v36.m128_f32[0] = (float)(len1a * v37) + v73;
  v38 = (float)(v33 * v37) + v3a;
  len1b = v36.m128_i32[0];
  v36.m128_f32[0] = (float)((float)(v36.m128_f32[0] - v16) * (float)(v36.m128_f32[0] - v16))
                  + (float)((float)(v38 - v15) * (float)(v38 - v15));
  LODWORD(v39) = (unsigned __int128)_mm_sqrt_ps(v36);
  if ( v72 <= 0.0 )
  {
    v40 = v11->OutVertices.Size >> 4;
    if ( v39 <= (float)(width * -4.0) )
      goto LABEL_19;
    v48 = v30 - (float)(v18 * 2.0);
    v49 = (float)(v17 * 2.0) + v31;
    v50 = (float)(v20 * 2.0) + v34;
    v51 = v29 - (float)(v21 * 2.0);
    if ( v40 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    v52 = v11->OutVertices.Size & 0xF;
    v53 = v11->OutVertices.Pages[v40];
    v53[v52].x = v48;
    v53[v52].y = v49;
    v53[v52].alpha = 0;
    v54 = ++v11->OutVertices.Size >> 4;
    if ( v54 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    v55 = v11->OutVertices.Size & 0xF;
    v56 = v11->OutVertices.Pages[v54];
    v56[v11->OutVertices.Size & 0xF].x = v50;
LABEL_32:
    v56[v55].y = v51;
    v64 = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->Triangles;
    v56[v55].alpha = 0;
    ++v64[-1].Size;
    v65 = v64[-1].Size;
    v66 = v64->Size >> 4;
    v67 = v65 - 1;
    v68 = v65 - 2;
    if ( v66 >= v64->NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(v64, v64->Size >> 4);
    v69 = v64->Size & 0xF;
    v70 = v64->Pages[v66];
    LODWORD(v70[v69].x) = v10;
    LODWORD(v70[v69].y) = v68;
    *(_DWORD *)&v70[v69].style = v67;
    ++v64->Size;
    return 2i64;
  }
  if ( v12 >= len2 )
    v12 = len2;
  v40 = v11->OutVertices.Size >> 4;
  if ( v39 > (float)(v12 / v72) )
  {
    if ( v40 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    v41 = v11->OutVertices.Size & 0xF;
    v42 = v11->OutVertices.Pages[v40];
    v42[v41].x = v30;
    v42[v41].y = v31;
    v42[v41].alpha = 0;
    v43 = ++v11->OutVertices.Size >> 4;
    if ( v43 >= v11->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
        v11->OutVertices.Size >> 4);
    v44 = v11->OutVertices.Size & 0xF;
    v45 = v11->OutVertices.Pages[v43];
    v45[v44].x = v34;
    v45[v44].y = v29;
    v45[v44].alpha = 0;
    ++v11->OutVertices.Size;
    return 2i64;
  }
LABEL_19:
  if ( v40 >= v11->OutVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&v11->OutVertices,
      v40);
  v46 = v11->OutVertices.Size & 0xF;
  v47 = v11->OutVertices.Pages[v40];
  v47[v46].x = v38;
  LODWORD(v47[v46].y) = len1b;
  v47[v46].alpha = 0;
  ++v11->OutVertices.Size;
  return 1i64;
}

// File Line: 1045
// RVA: 0x9E5FE0
void __fastcall Scaleform::Render::Hairliner::generateTriangles(Scaleform::Render::Hairliner *this, float width)
{
  unsigned __int64 v2; // r11
  Scaleform::Render::Hairliner *rdi1; // rdi
  unsigned int **v4; // r9
  signed int v5; // er13
  unsigned int v6; // ebx
  int v7; // er12
  int v8; // er15
  unsigned int v9; // ebp
  Scaleform::Render::Hairliner::OutVertexType **v10; // r8
  unsigned int v11; // edx
  Scaleform::Render::Hairliner::OutVertexType *v12; // r10
  signed __int64 v13; // r8
  __m128 v14; // xmm0
  float len1; // xmm2_4
  unsigned __int64 v16; // r14
  unsigned __int64 v17; // rax
  __int64 v18; // r14
  signed __int64 v3; // rax
  __m128 v20; // xmm0
  float len2; // xmm6_4
  int v22; // eax
  unsigned int v23; // esi
  unsigned __int64 v24; // rsi
  signed __int64 v25; // rdx
  Scaleform::Render::Hairliner::TriangleType *v26; // rax
  int v27; // er12
  unsigned __int64 v28; // rsi
  signed __int64 v29; // rdx
  Scaleform::Render::Hairliner::TriangleType *v30; // rax
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *v31; // rdi
  unsigned __int64 v32; // rbx
  signed __int64 v33; // rdx
  Scaleform::Render::StrokerAA::VertexType *v34; // rax
  unsigned __int64 v35; // rbx
  signed __int64 v36; // rdx
  Scaleform::Render::StrokerAA::VertexType *v37; // rax
  Scaleform::Render::Hairliner::OutVertexType *v38; // [rsp+40h] [rbp-78h]
  unsigned int v39; // [rsp+48h] [rbp-70h]
  signed __int64 v40; // [rsp+50h] [rbp-68h]
  unsigned __int64 v41; // [rsp+58h] [rbp-60h]
  signed int v42; // [rsp+C0h] [rbp+8h]
  int v43; // [rsp+D0h] [rbp+18h]
  int v44; // [rsp+D8h] [rbp+20h]

  v2 = this->ContourNodes.Size;
  rdi1 = this;
  if ( v2 >= 2 )
  {
    v4 = this->ContourNodes.Pages;
    v5 = -1;
    v6 = 0;
    v7 = -1;
    v8 = -1;
    v42 = -1;
    v9 = this->ContourNodes.Pages[(v2 - 1) >> 4][((_DWORD)v2 - 1) & 0xF];
    v10 = this->OutVertices.Pages;
    v39 = 0;
    v11 = v4[(v2 - 2) >> 4][((_DWORD)v2 - 2) & 0xF];
    v12 = &v10[(unsigned __int64)v11 >> 4][v11 & 0xF];
    v13 = (signed __int64)&v10[(unsigned __int64)v9 >> 4][v9 & 0xF];
    v38 = (Scaleform::Render::Hairliner::OutVertexType *)v13;
    v14 = (__m128)*(unsigned int *)(v13 + 4);
    v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] - v12->y) * (float)(v14.m128_f32[0] - v12->y))
                    + (float)((float)(*(float *)v13 - v12->x) * (float)(*(float *)v13 - v12->x));
    LODWORD(len1) = (unsigned __int128)_mm_sqrt_ps(v14);
    if ( v2 )
    {
      v16 = 0i64;
      do
      {
        v17 = v16;
        v18 = v16 & 0xF;
        v17 >>= 4;
        v41 = v17;
        v3 = (signed __int64)&rdi1->OutVertices.Pages[(unsigned __int64)v4[v17][v18] >> 4][v4[v17][v18] & 0xF];
        v40 = v3;
        v20 = (__m128)*(unsigned int *)(v3 + 4);
        v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] - *(float *)(v13 + 4))
                                * (float)(v20.m128_f32[0] - *(float *)(v13 + 4)))
                        + (float)((float)(*(float *)v3 - *(float *)v13) * (float)(*(float *)v3 - *(float *)v13));
        LODWORD(len2) = (unsigned __int128)_mm_sqrt_ps(v20);
        v22 = Scaleform::Render::Hairliner::addJoin(
                rdi1,
                v9,
                v12,
                (Scaleform::Render::Hairliner::OutVertexType *)v13,
                (Scaleform::Render::Hairliner::OutVertexType *)v3,
                len1,
                len2,
                width);
        v44 = v22;
        if ( v5 == -1 )
        {
          v23 = v9;
          v42 = v9;
          v8 = LODWORD(rdi1->OutVertices.Size) - v22;
        }
        else
        {
          v24 = rdi1->Triangles.Size >> 4;
          v43 = LODWORD(rdi1->OutVertices.Size) - v22;
          if ( v24 >= rdi1->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&rdi1->Triangles,
              v24);
          v25 = rdi1->Triangles.Size & 0xF;
          v26 = rdi1->Triangles.Pages[v24];
          v26[v25].v1 = v5;
          v26[v25].v2 = v7;
          v26[v25].v3 = v43;
          ++rdi1->Triangles.Size;
          v27 = LODWORD(rdi1->OutVertices.Size) - v44;
          v28 = rdi1->Triangles.Size >> 4;
          if ( v28 >= rdi1->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&rdi1->Triangles,
              rdi1->Triangles.Size >> 4);
          v29 = rdi1->Triangles.Size & 0xF;
          v30 = rdi1->Triangles.Pages[v28];
          v23 = v42;
          v30[v29].v1 = v5;
          v30[v29].v2 = v27;
          v30[v29].v3 = v9;
          ++rdi1->Triangles.Size;
          v6 = v39;
        }
        v4 = rdi1->ContourNodes.Pages;
        len1 = len2;
        v13 = v40;
        v12 = v38;
        ++v6;
        v5 = v9;
        v9 = v4[v41][v18];
        v16 = v6;
        v7 = LODWORD(rdi1->OutVertices.Size) - 1;
        v38 = (Scaleform::Render::Hairliner::OutVertexType *)v40;
        v39 = v6;
      }
      while ( v6 < rdi1->ContourNodes.Size );
      if ( v5 != -1 )
      {
        v31 = (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&rdi1->Triangles;
        v32 = v31->Size >> 4;
        if ( v32 >= v31->NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(v31, v31->Size >> 4);
        v33 = v31->Size & 0xF;
        v34 = v31->Pages[v32];
        LODWORD(v34[v33].x) = v5;
        LODWORD(v34[v33].y) = v7;
        *(_DWORD *)&v34[v33].style = v8;
        v35 = ++v31->Size >> 4;
        if ( v35 >= v31->NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(v31, v31->Size >> 4);
        v36 = v31->Size & 0xF;
        v37 = v31->Pages[v35];
        LODWORD(v37[v36].x) = v5;
        LODWORD(v37[v36].y) = v8;
        *(_DWORD *)&v37[v36].style = v23;
        ++v31->Size;
      }
    }
  }
}

// File Line: 1103
// RVA: 0x9B8A90
void __fastcall Scaleform::Render::Hairliner::Tessellate(Scaleform::Render::Hairliner *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::Render::Hairliner *v2; // rbx
  unsigned __int64 v3; // r9
  unsigned __int64 i; // rsi
  Scaleform::Render::Hairliner::FanEdgeType **v5; // r14
  Scaleform::Render::Hairliner::FanEdgeType *v6; // r8
  Scaleform::Render::Hairliner::FanEdgeType *v7; // r11
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  Scaleform::Render::Hairliner::FanEdgeType *v10; // rdx
  signed __int64 v11; // r8

  v1 = 0i64;
  v2 = this;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  this->Triangles.Size = 0i64;
  Scaleform::Render::Hairliner::buildGraph(this);
  if ( v2->FanEdges.Size >= 2 )
  {
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>,bool (*)(Scaleform::Render::Hairliner::FanEdgeType const &,Scaleform::Render::Hairliner::FanEdgeType const &)>(
      &v2->FanEdges,
      0i64,
      v2->FanEdges.Size,
      Scaleform::Render::Hairliner::cmpEdges);
    v3 = 1i64;
    for ( i = 1i64; v3 < v2->FanEdges.Size; ++v3 )
    {
      v5 = v2->FanEdges.Pages;
      v6 = v5[(v3 - 1) >> 4];
      v7 = v5[v3 >> 4];
      if ( v6[((_DWORD)v3 - 1) & 0xF].node1 != v7[v3 & 0xF].node1
        || v6[((_DWORD)v3 - 1) & 0xF].node2 != v7[v3 & 0xF].node2 )
      {
        v8 = i & 0xF;
        v9 = i++ >> 4;
        v10 = v5[v9];
        v11 = v8;
        v10[v11].node1 = v7[v3 & 0xF].node1;
        v10[v11].node2 = v7[v3 & 0xF].node2;
        v10[v11].slope = v7[v3 & 0xF].slope;
      }
    }
    if ( i < v2->FanEdges.Size )
      v2->FanEdges.Size = i;
    if ( v2->FanEdges.Size > 0 )
    {
      do
      {
        if ( (v2->FanEdges.Pages[v1 >> 4][v1 & 0xF].node1 & 0x80000000) == 0 )
        {
          Scaleform::Render::Hairliner::generateContourAA(v2, v1);
          Scaleform::Render::Hairliner::generateTriangles(v2, COERCE_FLOAT(LODWORD(v2->Width) ^ _xmm[0]));
        }
        ++v1;
      }
      while ( v1 < v2->FanEdges.Size );
    }
  }
}

// File Line: 1147
// RVA: 0x9BA540
void __fastcall Scaleform::Render::Hairliner::Transform(Scaleform::Render::Hairliner *this, Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v2; // r10
  signed __int64 v3; // r9
  Scaleform::Render::Hairliner::OutVertexType *v4; // rax
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
  if ( this->OutVertices.Size )
  {
    do
    {
      v3 = v2 & 0xF;
      v4 = this->OutVertices.Pages[v2 >> 4];
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
    while ( v2 < this->OutVertices.Size );
  }
}

// File Line: 1167
// RVA: 0x9B7C80
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Hairliner::StretchTo(Scaleform::Render::Hairliner *this, Scaleform::Render::Matrix2x4<float> *result, float x1, float y1, float x2, float y2)
{
  unsigned __int64 v6; // rsi
  int v7; // xmm7_4
  float v8; // xmm8_4
  Scaleform::Render::Matrix2x4<float> *v9; // rbx
  Scaleform::Render::Hairliner *v10; // rdi
  unsigned __int64 v11; // r9
  unsigned __int64 v12; // r8
  float v13; // xmm3_4
  Scaleform::Render::Hairliner::OutVertexType **v14; // r10
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  Scaleform::Render::Hairliner::OutVertexType *v18; // rax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  int v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  signed __int64 v25; // rax
  unsigned __int64 v26; // rdx
  signed __int64 v27; // r8
  Scaleform::Render::Hairliner::OutVertexType *v28; // rax
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
    v11 = this->OutVertices.Size;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    v12 = 0i64;
    if ( v11 )
    {
      v13 = FLOAT_N1_0e30;
      v14 = this->OutVertices.Pages;
      v15 = FLOAT_1_0e30;
      v16 = FLOAT_N1_0e30;
      v17 = FLOAT_1_0e30;
      do
      {
        v18 = v14[v12 >> 4];
        v19 = v18[v12 & 0xF].x;
        v20 = v18[v12 & 0xF].y;
        v41 = *(float *)&v18[v12 & 0xF].alpha;
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
      if ( v10->OutVertices.Size > 0 )
      {
        do
        {
          v25 = v6 & 0xF;
          v26 = v6++ >> 4;
          v27 = v25;
          v28 = v10->OutVertices.Pages[v26];
          v29 = v28[v27].x;
          v30 = v28[v27].y;
          v28[v27].x = (float)((float)(v28[v27].x * v9->M[0][0]) + (float)(v28[v27].y * v9->M[0][1])) + v9->M[0][3];
          v28[v27].y = (float)((float)(v29 * v9->M[1][0]) + (float)(v30 * v9->M[1][1])) + v9->M[1][3];
        }
        while ( v6 < v10->OutVertices.Size );
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

// File Line: 1202
// RVA: 0x989200
void __fastcall Scaleform::Render::Hairliner::GetMesh(Scaleform::Render::Hairliner *this, unsigned int __formal, Scaleform::Render::TessMesh *mesh)
{
  *(_QWORD *)&mesh->Style1 = 1i64;
  mesh->MeshIdx = 0;
  *(_QWORD *)&mesh->Flags1 = 0i64;
  mesh->StartVertex = 0;
  mesh->VertexCount = this->OutVertices.Size;
}

// File Line: 1214
// RVA: 0x98ED90
__int64 __fastcall Scaleform::Render::Hairliner::GetVertices(Scaleform::Render::Hairliner *this, Scaleform::Render::TessMesh *mesh, Scaleform::Render::TessVertex *vertices, unsigned int num)
{
  Scaleform::Render::TessVertex *v4; // r11
  Scaleform::Render::TessMesh *v5; // rbx
  unsigned int v6; // er10
  unsigned __int64 v7; // rdx
  signed __int64 v8; // r8
  Scaleform::Render::Hairliner::OutVertexType *v9; // rdx
  float v10; // eax
  unsigned __int64 v11; // rdx
  signed __int64 v12; // r8
  Scaleform::Render::Hairliner::OutVertexType *v13; // rdx
  float v14; // eax
  unsigned __int64 v15; // rdx
  signed __int64 v16; // r8
  Scaleform::Render::Hairliner::OutVertexType *v17; // rdx
  float v18; // eax
  unsigned __int64 v19; // rdx
  signed __int64 v20; // r8
  Scaleform::Render::Hairliner::OutVertexType *v21; // rdx
  float v22; // eax
  unsigned int *v23; // r11
  unsigned __int64 v24; // rdx
  signed __int64 v25; // r8
  Scaleform::Render::Hairliner::OutVertexType *v26; // rdx
  float v27; // eax

  v4 = vertices;
  v5 = mesh;
  v6 = 0;
  if ( (signed int)num < 4 )
  {
LABEL_7:
    if ( v6 < num )
    {
      v23 = &v4->Idx;
      do
      {
        v24 = v5->StartVertex;
        if ( v24 >= this->OutVertices.Size )
          break;
        v25 = v24 & 0xF;
        v26 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v24 >> 4];
        *(v23 - 2) = LODWORD(v26[v25].x);
        v27 = v26[v25].y;
        *v23 = 0;
        *((float *)v23 - 1) = v27;
        v23[1] = 1;
        ++v6;
        v23 += 5;
        *((_WORD *)v23 - 6) = v26[v25].alpha != 0 ? 2 : 0;
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
      if ( v7 >= this->OutVertices.Size )
        break;
      v8 = v7 & 0xF;
      v9 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v7 >> 4];
      v4->x = v9[v8].x;
      v10 = v9[v8].y;
      v4->Idx = 0;
      v4->y = v10;
      *(_DWORD *)v4->Styles = 1;
      v4->Flags = v9[v8].alpha != 0 ? 2 : 0;
      v11 = ++v5->StartVertex;
      if ( v11 >= this->OutVertices.Size )
        return v6 + 1;
      v12 = v11 & 0xF;
      v13 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v11 >> 4];
      v4[1].x = v13[v12].x;
      v14 = v13[v12].y;
      v4[1].Idx = 0;
      v4[1].y = v14;
      *(_DWORD *)v4[1].Styles = 1;
      v4[1].Flags = v13[v12].alpha != 0 ? 2 : 0;
      v15 = ++v5->StartVertex;
      if ( v15 >= this->OutVertices.Size )
        return v6 + 2;
      v16 = v15 & 0xF;
      v17 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v15 >> 4];
      v4[2].x = v17[v16].x;
      v18 = v17[v16].y;
      v4[2].Idx = 0;
      v4[2].y = v18;
      *(_DWORD *)v4[2].Styles = 1;
      v4[2].Flags = v17[v16].alpha != 0 ? 2 : 0;
      v19 = ++v5->StartVertex;
      if ( v19 >= this->OutVertices.Size )
        return v6 + 3;
      v20 = v19 & 0xF;
      v21 = this->OutVertices.Pages[(unsigned __int64)(unsigned int)v19 >> 4];
      v4[3].x = v21[v20].x;
      v22 = v21[v20].y;
      v4[3].Idx = 0;
      v4[3].y = v22;
      *(_DWORD *)v4[3].Styles = 1;
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

// File Line: 1233
// RVA: 0x98DF90
void __fastcall Scaleform::Render::Hairliner::GetTrianglesI16(Scaleform::Render::Hairliner *this, unsigned int __formal, unsigned __int16 *idx, unsigned int start, unsigned int num)
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

