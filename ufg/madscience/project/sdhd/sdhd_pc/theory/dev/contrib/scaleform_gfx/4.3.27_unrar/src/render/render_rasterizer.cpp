// File Line: 48
// RVA: 0x940F50
void __fastcall Scaleform::Render::Rasterizer::Rasterizer(Scaleform::Render::Rasterizer *this, Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::Rasterizer *v2; // rbx
  Scaleform::Render::LinearHeap *v3; // rax

  v2 = this;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Rasterizer::`vftable';
  v3 = &this->LHeap;
  v3->pHeap = heap;
  v3->Granularity = 0x2000i64;
  v3->pPagePool = 0i64;
  v3->pLastPage = 0i64;
  v3->MaxPages = 0i64;
  this->FillRule = 0;
  this->Cells.pHeap = &this->LHeap;
  this->Cells.Size = 0i64;
  this->Cells.NumPages = 0i64;
  this->Cells.MaxPages = 0i64;
  this->Cells.Pages = 0i64;
  this->SortedCells.pHeap = &this->LHeap;
  this->SortedCells.Size = 0i64;
  this->SortedCells.Array = 0i64;
  this->SortedYs.pHeap = &this->LHeap;
  this->SortedYs.Size = 0i64;
  this->SortedYs.Array = 0i64;
  *(_QWORD *)&this->CurrCell.x = 0i64;
  *(_QWORD *)&this->CurrCell.Cover = 0i64;
  this->MinX = 0x7FFFFFFF;
  this->MinY = 0x7FFFFFFF;
  this->MaxX = -2147483647;
  this->MaxY = -2147483647;
  *(_QWORD *)&this->StartX = 0i64;
  *(_QWORD *)&this->LastX = 0i64;
  *(_QWORD *)&this->LastXf = 0i64;
  this->CurrCell.x = 0x7FFFFFFF;
  *(_QWORD *)&this->CurrCell.y = 0x7FFFFFFFi64;
  this->CurrCell.Area = 0;
  Scaleform::Render::Rasterizer::setGamma(this, 0, 1.0);
  v2->Gamma1 = 1.0;
  Scaleform::Render::Rasterizer::setGamma(v2, 1, 1.0);
  v2->Gamma2 = 1.0;
}

// File Line: 59
// RVA: 0x95F890
void __fastcall Scaleform::Render::Rasterizer::Clear(Scaleform::Render::Rasterizer *this)
{
  Scaleform::Render::Rasterizer *v1; // rbx
  Scaleform::Render::LinearHeap *v2; // rcx

  v1 = this;
  v2 = &this->LHeap;
  v2[14].MaxPages = 0i64;
  v2[14].pLastPage = 0i64;
  v2[14].pPagePool = 0i64;
  v2[15].pHeap = 0i64;
  v2[15].pPagePool = 0i64;
  v2[15].pLastPage = 0i64;
  v2[16].pHeap = 0i64;
  v2[16].Granularity = 0i64;
  Scaleform::Render::LinearHeap::ClearAndRelease(v2);
  v1->CurrCell.x = 0x7FFFFFFF;
  *(_QWORD *)&v1->CurrCell.y = 0x7FFFFFFFi64;
  v1->CurrCell.Area = 0;
  v1->MinX = 0x7FFFFFFF;
  v1->MinY = 0x7FFFFFFF;
  v1->MaxX = -2147483647;
  v1->MaxY = -2147483647;
  *(_QWORD *)&v1->StartX = 0i64;
  *(_QWORD *)&v1->LastX = 0i64;
  *(_QWORD *)&v1->LastXf = 0i64;
}

// File Line: 82
// RVA: 0x9F09F0
void __fastcall Scaleform::Render::Rasterizer::setGamma(Scaleform::Render::Rasterizer *this, int idx, float g)
{
  signed int v3; // ebx
  char *v4; // rdi
  float v5; // xmm0_4

  v3 = 0;
  v4 = this->GammaLut[(signed __int64)idx];
  do
  {
    v5 = powf((float)v3++ * 0.0039215689, g);
    *(++v4 - 1) = (signed int)(float)((float)(v5 * 255.0) + 0.5);
  }
  while ( v3 < 256 );
}

// File Line: 99
// RVA: 0x9B0680
void __fastcall Scaleform::Render::Rasterizer::SetGamma2(Scaleform::Render::Rasterizer *this, float g)
{
  Scaleform::Render::Rasterizer *v2; // rbx

  v2 = this;
  Scaleform::Render::Rasterizer::setGamma(this, 1, g);
  v2->Gamma2 = g;
}

// File Line: 115
// RVA: 0x998950
void __fastcall Scaleform::Render::Rasterizer::LineTo(Scaleform::Render::Rasterizer *this, float x, float y)
{
  int v3; // er8
  int v4; // edx
  Scaleform::Render::Rasterizer *v5; // rsi
  int v6; // edi
  int y2; // ebx

  v3 = this->LastY;
  v4 = this->LastX;
  this->LastXf = x;
  this->LastYf = y;
  v5 = this;
  v6 = (signed int)(float)(x * 256.0);
  y2 = (signed int)(float)(y * 256.0);
  Scaleform::Render::Rasterizer::line(this, v4, v3, v6, y2);
  v5->LastY = y2;
  v5->LastX = v6;
}

// File Line: 127
// RVA: 0x961530
void __fastcall Scaleform::Render::Rasterizer::ClosePath(Scaleform::Render::Rasterizer *this)
{
  Scaleform::Render::Rasterizer *v1; // rbx

  v1 = this;
  if ( *(_QWORD *)&this->LastX != *(_QWORD *)&this->StartX )
  {
    Scaleform::Render::Rasterizer::line(this, this->LastX, this->LastY, this->StartX, this->StartY);
    v1->LastX = v1->StartX;
    v1->LastY = v1->StartY;
  }
}

// File Line: 138
// RVA: 0x9E7E20
void __fastcall Scaleform::Render::Rasterizer::horLine(Scaleform::Render::Rasterizer *this, int ey, int x1, int y1, int x2, int y2)
{
  int v6; // ebp
  int v7; // er12
  int v8; // er10
  int v9; // er13
  int v10; // er9
  int v11; // eax
  int v12; // edi
  Scaleform::Render::Rasterizer *v13; // rbx
  int v14; // er8
  int v15; // eax
  signed int v16; // er11
  signed int v17; // er15
  int v18; // eax
  int v19; // ebp
  int v20; // esi
  int v21; // edx
  int v22; // eax
  int v23; // edi
  Scaleform::Render::Rasterizer::Cell *v24; // r15
  int v25; // edx
  int v26; // kr00_4
  int v27; // eax
  int v28; // edx
  int v29; // esi
  bool v30; // sf
  int v31; // ecx
  int v32; // eax
  int v33; // ecx
  int v34; // er12
  int v35; // [rsp+20h] [rbp-48h]
  signed int v36; // [rsp+24h] [rbp-44h]
  int v37; // [rsp+28h] [rbp-40h]
  int v38; // [rsp+78h] [rbp+10h]
  signed int v39; // [rsp+80h] [rbp+18h]
  int v40; // [rsp+88h] [rbp+20h]
  int v41; // [rsp+88h] [rbp+20h]
  int x2a; // [rsp+90h] [rbp+28h]

  v38 = ey;
  v6 = x2;
  v7 = y2;
  v8 = x1;
  v9 = y1;
  v10 = x2 >> 8;
  v11 = (unsigned __int8)x2;
  v12 = x1 >> 8;
  v13 = this;
  v14 = ey;
  x2a = x2 >> 8;
  v37 = v11;
  if ( v9 == y2 )
  {
    if ( (this->CurrCell.y - ey) | (this->CurrCell.x - v10) )
    {
      if ( *(_QWORD *)&this->CurrCell.Cover )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
          (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
        v14 = v38;
        v10 = x2a;
      }
      v13->CurrCell.x = v10;
      v13->CurrCell.y = v14;
      *(_QWORD *)&v13->CurrCell.Cover = 0i64;
    }
  }
  else
  {
    if ( v12 == v10 )
    {
      v15 = (unsigned __int8)v8 + v11;
    }
    else
    {
      v16 = 1;
      v17 = 256;
      v18 = (y2 - v9) * (256 - (unsigned __int8)v8);
      v19 = v6 - v8;
      v36 = 256;
      v39 = 1;
      if ( v19 < 0 )
      {
        v16 = -1;
        v17 = 0;
        v36 = 0;
        v39 = -1;
        v18 = (unsigned __int8)v8 * (y2 - v9);
        v19 = -v19;
      }
      v20 = v18 % v19;
      v40 = v18 / v19;
      v21 = v18 / v19;
      if ( v18 % v19 < 0 )
      {
        --v21;
        v20 += v19;
        v40 = v21;
      }
      this->CurrCell.Cover += v21;
      v22 = v17 + (unsigned __int8)v8;
      v23 = v16 + v12;
      v24 = &this->CurrCell;
      this->CurrCell.Area += v21 * v22;
      if ( (this->CurrCell.y - v14) | (this->CurrCell.x - v23) )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
          v14 = v38;
          v10 = x2a;
          v21 = v40;
          v16 = v39;
        }
        v24->x = v23;
        v13->CurrCell.y = v14;
        *(_QWORD *)&v13->CurrCell.Cover = 0i64;
      }
      v9 += v21;
      if ( v23 != v10 )
      {
        v26 = (y2 + v21 - v9) << 8;
        v25 = (y2 + v21 - v9) << 8 >> 31;
        v27 = __PAIR__(v25, v26) / v19;
        v28 = __PAIR__(v25, v26) % v19;
        v35 = v28;
        v41 = v27;
        if ( v28 < 0 )
        {
          v28 += v19;
          v35 = v28;
          v41 = v27 - 1;
        }
        v29 = v20 - v19;
        do
        {
          v30 = v28 + v29 < 0;
          v29 += v28;
          v31 = v41;
          if ( !v30 )
          {
            v29 -= v19;
            v31 = v41 + 1;
          }
          v13->CurrCell.Cover += v31;
          v32 = v31;
          v9 += v31;
          v33 = v24->x;
          v23 += v16;
          v13->CurrCell.Area += v32 << 8;
          if ( (v13->CurrCell.y - v14) | (v33 - v23) )
          {
            if ( *(_QWORD *)&v13->CurrCell.Cover )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v13->Cells,
                (Scaleform::Render::StrokeSorter::VertexType *)&v13->CurrCell);
              v14 = v38;
              v10 = x2a;
              v16 = v39;
            }
            v24->x = v23;
            v13->CurrCell.y = v14;
            *(_QWORD *)&v13->CurrCell.Cover = 0i64;
          }
          v28 = v35;
        }
        while ( v23 != v10 );
        v7 = y2;
      }
      v15 = v37 - v36 + 256;
    }
    v34 = v7 - v9;
    v13->CurrCell.Cover += v34;
    v13->CurrCell.Area += v34 * v15;
  }
}

// File Line: 234
// RVA: 0x9E9190
void __fastcall Scaleform::Render::Rasterizer::line(Scaleform::Render::Rasterizer *this, int x1, int y1, int x2, int y2)
{
  int v5; // er10
  Scaleform::Render::Rasterizer *v6; // rbx
  int v7; // edi
  int v8; // er13
  int v9; // edx
  int v10; // ebp
  int v11; // er15
  int v12; // er8
  int v13; // edi
  int v14; // ecx
  int v15; // er12
  Scaleform::Render::Rasterizer::Cell *v16; // rsi
  signed int v17; // er9
  signed int v18; // edx
  int v19; // er10
  int v20; // edi
  int v21; // ecx
  int v22; // er15
  int v23; // er14
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // ebp
  int v32; // edi
  int v33; // er10
  int v34; // eax
  int v35; // ecx
  int v36; // er15
  int v37; // edx
  int v38; // ebp
  int v39; // er8
  bool v40; // sf
  int v41; // eax
  int v42; // er14
  int v43; // er14
  int v44; // [rsp+30h] [rbp-58h]
  int v45; // [rsp+30h] [rbp-58h]
  int v46; // [rsp+90h] [rbp+8h]
  int x1a; // [rsp+98h] [rbp+10h]
  int x1b; // [rsp+98h] [rbp+10h]
  int x1c; // [rsp+98h] [rbp+10h]
  int x1d; // [rsp+98h] [rbp+10h]
  int v51; // [rsp+A0h] [rbp+18h]
  int v52; // [rsp+A8h] [rbp+20h]
  int v53; // [rsp+A8h] [rbp+20h]
  int y2a; // [rsp+B0h] [rbp+28h]

  v52 = x2;
  v5 = x1;
  v6 = this;
  x1a = x1;
  v7 = y1;
  v8 = y2 - y1;
  v9 = x2 - x1;
  v10 = v5 >> 8;
  v11 = (unsigned __int8)y1;
  v12 = (unsigned __int8)y2;
  v13 = v7 >> 8;
  v14 = x2 >> 8;
  v15 = y2 >> 8;
  v46 = (unsigned __int8)y2;
  v44 = v9;
  if ( v5 >> 8 < v6->MinX )
    v6->MinX = v10;
  if ( v10 > v6->MaxX )
    v6->MaxX = v10;
  if ( v13 < v6->MinY )
    v6->MinY = v13;
  if ( v13 > v6->MaxY )
    v6->MaxY = v13;
  if ( v14 < v6->MinX )
    v6->MinX = v14;
  if ( v14 > v6->MaxX )
    v6->MaxX = v14;
  if ( v15 < v6->MinY )
    v6->MinY = v15;
  if ( v15 > v6->MaxY )
    v6->MaxY = v15;
  v16 = &v6->CurrCell;
  if ( (v6->CurrCell.x - v10) | (v6->CurrCell.y - v13) )
  {
    if ( *(_QWORD *)&v6->CurrCell.Cover )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v6->Cells,
        (Scaleform::Render::StrokeSorter::VertexType *)&v6->CurrCell);
      v5 = x1a;
      v9 = v44;
      x2 = v52;
      v12 = (unsigned __int8)y2;
    }
    v16->x = v10;
    v6->CurrCell.y = v13;
    *(_QWORD *)&v6->CurrCell.Cover = 0i64;
  }
  if ( v13 == v15 )
  {
    Scaleform::Render::Rasterizer::horLine(v6, v13, v5, v11, x2, v12);
  }
  else
  {
    v17 = 1;
    y2a = 1;
    if ( v9 )
    {
      v27 = 256;
      v51 = 256;
      v28 = v9 * (256 - v11);
      if ( v8 < 0 )
      {
        v27 = 0;
        y2a = -1;
        v51 = 0;
        v28 = v9 * v11;
        v8 = -v8;
      }
      v30 = v28 % v8;
      v29 = v28 / v8;
      v31 = v30;
      if ( v30 < 0 )
      {
        --v29;
        v31 = v8 + v30;
      }
      x1c = v29 + v5;
      Scaleform::Render::Rasterizer::horLine(v6, v13, v5, v11, v29 + v5, v27);
      v32 = y2a + v13;
      v33 = x1c;
      if ( (v6->CurrCell.y - v32) | (v16->x - (x1c >> 8)) )
      {
        if ( *(_QWORD *)&v6->CurrCell.Cover )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v6->Cells,
            (Scaleform::Render::StrokeSorter::VertexType *)&v6->CurrCell);
          v33 = x1c;
        }
        v16->x = x1c >> 8;
        v6->CurrCell.y = v32;
        *(_QWORD *)&v6->CurrCell.Cover = 0i64;
      }
      if ( v32 != v15 )
      {
        v34 = (v44 << 8) / v8;
        v45 = (v44 << 8) % v8;
        v35 = v45;
        v36 = v34;
        if ( v45 < 0 )
        {
          v36 = v34 - 1;
          v35 = v8 + v45;
          v45 += v8;
        }
        v37 = v51;
        v38 = v31 - v8;
        v39 = 256 - v51;
        do
        {
          v40 = v35 + v38 < 0;
          v38 += v35;
          v41 = v36;
          if ( !v40 )
          {
            v38 -= v8;
            v41 = v36 + 1;
          }
          v42 = v33 + v41;
          Scaleform::Render::Rasterizer::horLine(v6, v32, v33, v39, v33 + v41, v37);
          v32 += y2a;
          v33 = v42;
          x1d = v42;
          v43 = v42 >> 8;
          if ( (v6->CurrCell.y - v32) | (v16->x - v43) )
          {
            if ( *(_QWORD *)&v6->CurrCell.Cover )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v6->Cells,
                (Scaleform::Render::StrokeSorter::VertexType *)&v6->CurrCell);
              v33 = x1d;
            }
            v16->x = v43;
            v6->CurrCell.y = v32;
            *(_QWORD *)&v6->CurrCell.Cover = 0i64;
          }
          v35 = v45;
          v37 = v51;
          v39 = 256 - v51;
        }
        while ( v32 != v15 );
      }
      Scaleform::Render::Rasterizer::horLine(v6, v32, v33, 256 - v51, v52, v46);
    }
    else
    {
      v18 = 256;
      v53 = 256;
      v19 = 2 * (v5 - (v10 << 8));
      x1b = v19;
      if ( v8 < 0 )
      {
        v17 = -1;
        v18 = 0;
        y2a = -1;
        v53 = 0;
      }
      v20 = v17 + v13;
      v21 = v16->x - v10;
      v6->CurrCell.Cover += v18 - v11;
      v6->CurrCell.Area += v19 * (v18 - v11);
      if ( (v6->CurrCell.y - v20) | v21 )
      {
        if ( *(_QWORD *)&v6->CurrCell.Cover )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v6->Cells,
            (Scaleform::Render::StrokeSorter::VertexType *)&v6->CurrCell);
          v19 = x1b;
          v18 = v53;
          v17 = y2a;
        }
        v16->x = v10;
        v6->CurrCell.y = v20;
        *(_QWORD *)&v6->CurrCell.Cover = 0i64;
      }
      v22 = 2 * v18 - 256;
      v23 = v19 * v22;
      if ( v20 != v15 )
      {
        do
        {
          v20 += v17;
          v24 = v16->x - v10;
          v25 = v6->CurrCell.y - v20;
          v6->CurrCell.Cover = v22;
          v6->CurrCell.Area = v23;
          if ( v25 | v24 )
          {
            if ( v22 | v23 )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v6->Cells,
                (Scaleform::Render::StrokeSorter::VertexType *)&v6->CurrCell);
              v17 = y2a;
            }
            v16->x = v10;
            v6->CurrCell.y = v20;
            *(_QWORD *)&v6->CurrCell.Cover = 0i64;
          }
        }
        while ( v20 != v15 );
        v19 = x1b;
        v18 = v53;
      }
      v26 = v18 + v46 - 256;
      v6->CurrCell.Cover += v26;
      v6->CurrCell.Area += v19 * v26;
    }
  }
}

// File Line: 369
// RVA: 0x9B7400
char __fastcall Scaleform::Render::Rasterizer::SortCells(Scaleform::Render::Rasterizer *this)
{
  Scaleform::Render::Rasterizer *v1; // rbx
  unsigned __int64 v2; // rdx
  unsigned int v3; // esi
  unsigned int v5; // er8
  unsigned __int64 v6; // rdx
  int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // er8
  __int64 v10; // r9
  Scaleform::Render::Rasterizer::SortedY *v11; // rax
  unsigned int v12; // ecx
  unsigned int v13; // er9
  unsigned __int64 v14; // r8
  signed __int64 v15; // r8
  Scaleform::Render::Rasterizer::SortedY *v16; // rdx
  __int64 v17; // rcx
  Scaleform::Render::Rasterizer::SortedY *v18; // rax
  unsigned __int64 v19; // rdx
  __int64 v20; // rcx
  Scaleform::Render::Rasterizer::Cell **v21; // rax
  Scaleform::Alg::ArrayAdaptor<Scaleform::Render::Rasterizer::Cell *> arr; // [rsp+20h] [rbp-18h]

  v1 = this;
  if ( *(_QWORD *)&this->CurrCell.Cover )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
      (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
  v2 = v1->Cells.Size;
  v3 = 0;
  v1->CurrCell.x = 0x7FFFFFFF;
  *(_QWORD *)&v1->CurrCell.y = 0x7FFFFFFFi64;
  v1->CurrCell.Area = 0;
  if ( !v2 )
    return 0;
  if ( !v1->SortedYs.Size )
  {
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
      (Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY> *)&v1->SortedCells,
      v2);
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
      &v1->SortedYs,
      v1->MaxY - v1->MinY + 1);
    memset(v1->SortedYs.Array, 0, 8 * v1->SortedYs.Size);
    v5 = 0;
    if ( v1->Cells.Size > 0 )
    {
      v6 = 0i64;
      do
      {
        ++v5;
        v7 = v1->Cells.Pages[v6 >> 4][v6 & 0xF].y - v1->MinY;
        ++v1->SortedYs.Array[v7].Start;
        v6 = v5;
      }
      while ( v5 < v1->Cells.Size );
    }
    v8 = 0;
    v9 = 0;
    if ( v1->SortedYs.Size > 0 )
    {
      v10 = 0i64;
      do
      {
        v11 = v1->SortedYs.Array;
        ++v9;
        v12 = v11[v10].Start;
        v11[v10].Start = v8;
        v10 = v9;
        v8 += v12;
      }
      while ( v9 < v1->SortedYs.Size );
    }
    v13 = 0;
    if ( v1->Cells.Size > 0 )
    {
      v14 = 0i64;
      do
      {
        ++v13;
        v15 = (signed __int64)&v1->Cells.Pages[v14 >> 4][v14 & 0xF];
        v16 = &v1->SortedYs.Array[*(_DWORD *)(v15 + 4) - v1->MinY];
        v1->SortedCells.Array[v16->Count++ + v16->Start] = (Scaleform::Render::Rasterizer::Cell *)v15;
        v14 = v13;
      }
      while ( v13 < v1->Cells.Size );
    }
    if ( v1->SortedYs.Size > 0 )
    {
      v17 = 0i64;
      do
      {
        v18 = v1->SortedYs.Array;
        v19 = v18[v17].Count;
        if ( (_DWORD)v19 )
        {
          v20 = v18[v17].Start;
          v21 = v1->SortedCells.Array;
          arr.Size = v19;
          arr.Data = &v21[v20];
          Scaleform::Alg::QuickSortSliced<Scaleform::Alg::ArrayAdaptor<Scaleform::Render::Rasterizer::Cell *>,bool (*)(Scaleform::Render::Rasterizer::Cell const *,Scaleform::Render::Rasterizer::Cell const *)>(
            &arr,
            0i64,
            (unsigned int)v19,
            (bool (__fastcall *)(Scaleform::Render::Rasterizer::Cell *, Scaleform::Render::Rasterizer::Cell *))compareLinks);
        }
        v17 = ++v3;
      }
      while ( v3 < v1->SortedYs.Size );
    }
  }
  return 1;
}

// File Line: 435
// RVA: 0x9B87C0
void __fastcall Scaleform::Render::Rasterizer::SweepScanline(Scaleform::Render::Rasterizer *this, unsigned int scanline, char *pRaster, unsigned int numChannels, int gammaIdx)
{
  Scaleform::Render::Rasterizer *v5; // r14
  unsigned __int64 v6; // r15
  char *v7; // r13
  Scaleform::Render::Rasterizer::SortedY *v8; // rax
  unsigned int v9; // ebp
  int v10; // esi
  Scaleform::Render::Rasterizer::Cell **v11; // rbx
  Scaleform::Render::Rasterizer::Cell *v12; // rdx
  int v13; // er9
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  signed __int64 v17; // rax

  v5 = this;
  v6 = numChannels;
  v7 = pRaster;
  if ( scanline < this->SortedYs.Size )
  {
    v8 = this->SortedYs.Array;
    v9 = v8[scanline].Count;
    v10 = 0;
    v11 = &this->SortedCells.Array[v8[scanline].Start];
    if ( v9 )
    {
      while ( 1 )
      {
        v12 = *v11;
        v10 += (*v11)->Cover;
        v13 = (*v11)->x;
        v14 = (*v11)->Area;
        if ( --v9 )
        {
          do
          {
            v12 = v11[1];
            ++v11;
            if ( v12->x != v13 )
              break;
            v14 += v12->Area;
            v10 += v12->Cover;
            --v9;
          }
          while ( v9 );
        }
        if ( v14 )
        {
          v15 = ((v10 << 9) - v14) >> 9;
          if ( v15 < 0 )
            v15 = -(((v10 << 9) - v14) >> 9);
          if ( v5->FillRule == 1 )
          {
            v15 &= 0x1FFu;
            if ( v15 > 256 )
              v15 = 512 - v15;
          }
          if ( v15 > 255 )
            v15 = 255;
          if ( (_DWORD)v6 )
            memset(&v7[(unsigned int)(v6 * (v13 - v5->MinX))], v5->GammaLut[(signed __int64)gammaIdx][v15], v6);
          ++v13;
        }
        if ( !v9 )
          break;
        if ( v12->x > v13 )
        {
          v16 = v10 << 9 >> 9;
          if ( v16 < 0 )
            v16 = -(v10 << 9 >> 9);
          if ( v5->FillRule == 1 )
          {
            v16 &= 0x1FFu;
            if ( v16 > 256 )
              v16 = 512 - v16;
          }
          if ( v16 > 255 )
            v16 = 255;
          v17 = (signed __int64)v5 + 256 * (signed __int64)gammaIdx;
          if ( *(_BYTE *)(v16 + v17 + 60) )
            memset(
              &v7[(unsigned int)(v6 * (v13 - v5->MinX))],
              (unsigned __int8)v5->GammaLut[(signed __int64)gammaIdx][v16],
              (unsigned int)(v6 * (v12->x - v13)));
        }
      }
    }
  }
}

