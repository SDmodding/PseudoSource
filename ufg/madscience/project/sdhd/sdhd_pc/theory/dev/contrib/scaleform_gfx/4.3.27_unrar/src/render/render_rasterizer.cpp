// File Line: 48
// RVA: 0x940F50
void __fastcall Scaleform::Render::Rasterizer::Rasterizer(
        Scaleform::Render::Rasterizer *this,
        Scaleform::MemoryHeap *heap)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Rasterizer::`vftable;
  this->LHeap.pHeap = heap;
  this->LHeap.Granularity = 0x2000i64;
  this->LHeap.pPagePool = 0i64;
  this->LHeap.pLastPage = 0i64;
  this->LHeap.MaxPages = 0i64;
  this->FillRule = FillNonZero;
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
  this->Gamma1 = 1.0;
  Scaleform::Render::Rasterizer::setGamma(this, 1, 1.0);
  this->Gamma2 = 1.0;
}

// File Line: 59
// RVA: 0x95F890
void __fastcall Scaleform::Render::Rasterizer::Clear(Scaleform::Render::Rasterizer *this)
{
  Scaleform::Render::LinearHeap *p_LHeap; // rcx

  p_LHeap = &this->LHeap;
  p_LHeap[14].MaxPages = 0i64;
  p_LHeap[14].pLastPage = 0i64;
  p_LHeap[14].pPagePool = 0i64;
  p_LHeap[15].pHeap = 0i64;
  p_LHeap[15].pPagePool = 0i64;
  p_LHeap[15].pLastPage = 0i64;
  p_LHeap[16].pHeap = 0i64;
  p_LHeap[16].Granularity = 0i64;
  Scaleform::Render::LinearHeap::ClearAndRelease(p_LHeap);
  this->CurrCell.x = 0x7FFFFFFF;
  *(_QWORD *)&this->CurrCell.y = 0x7FFFFFFFi64;
  this->CurrCell.Area = 0;
  this->MinX = 0x7FFFFFFF;
  this->MinY = 0x7FFFFFFF;
  this->MaxX = -2147483647;
  this->MaxY = -2147483647;
  *(_QWORD *)&this->StartX = 0i64;
  *(_QWORD *)&this->LastX = 0i64;
  *(_QWORD *)&this->LastXf = 0i64;
}

// File Line: 82
// RVA: 0x9F09F0
void __fastcall Scaleform::Render::Rasterizer::setGamma(Scaleform::Render::Rasterizer *this, int idx, float g)
{
  int v3; // ebx
  char *v4; // rdi
  float v5; // xmm0_4

  v3 = 0;
  v4 = this->GammaLut[(__int64)idx];
  do
  {
    v5 = powf((float)v3++ * 0.0039215689, g);
    *v4++ = (int)(float)((float)(v5 * 255.0) + 0.5);
  }
  while ( v3 < 256 );
}

// File Line: 99
// RVA: 0x9B0680
void __fastcall Scaleform::Render::Rasterizer::SetGamma2(Scaleform::Render::Rasterizer *this, float g)
{
  Scaleform::Render::Rasterizer::setGamma(this, 1, g);
  this->Gamma2 = g;
}

// File Line: 115
// RVA: 0x998950
void __fastcall Scaleform::Render::Rasterizer::LineTo(Scaleform::Render::Rasterizer *this, float x, float y)
{
  int LastY; // r8d
  int LastX; // edx
  int v6; // edi
  int y2; // ebx

  LastY = this->LastY;
  LastX = this->LastX;
  this->LastXf = x;
  this->LastYf = y;
  v6 = (int)(float)(x * 256.0);
  y2 = (int)(float)(y * 256.0);
  Scaleform::Render::Rasterizer::line(this, LastX, LastY, v6, y2);
  this->LastY = y2;
  this->LastX = v6;
}

// File Line: 127
// RVA: 0x961530
void __fastcall Scaleform::Render::Rasterizer::ClosePath(Scaleform::Render::Rasterizer *this)
{
  if ( *(_QWORD *)&this->LastX != *(_QWORD *)&this->StartX )
  {
    Scaleform::Render::Rasterizer::line(this, this->LastX, this->LastY, this->StartX, this->StartY);
    this->LastX = this->StartX;
    this->LastY = this->StartY;
  }
}

// File Line: 138
// RVA: 0x9E7E20
void __fastcall Scaleform::Render::Rasterizer::horLine(
        Scaleform::Render::Rasterizer *this,
        int ey,
        int x1,
        int y1,
        int x2,
        int y2)
{
  int v7; // r12d
  int v10; // r9d
  int v11; // eax
  int v12; // edi
  int v14; // r8d
  int v15; // eax
  int v16; // r11d
  int v17; // r15d
  int v18; // eax
  int v19; // ebp
  int v20; // esi
  int v21; // edx
  int v22; // eax
  int v23; // edi
  Scaleform::Render::Rasterizer::Cell *p_CurrCell; // r15
  int v25; // kr00_4
  int v26; // edx
  int v27; // esi
  bool v28; // sf
  int v29; // ecx
  int v30; // eax
  int x; // ecx
  int v32; // r12d
  int v33; // [rsp+20h] [rbp-48h]
  int v34; // [rsp+24h] [rbp-44h]
  int v35; // [rsp+28h] [rbp-40h]
  int v37; // [rsp+80h] [rbp+18h]
  int v38; // [rsp+88h] [rbp+20h]
  int v39; // [rsp+88h] [rbp+20h]
  int x2a; // [rsp+90h] [rbp+28h]

  v7 = y2;
  v10 = x2 >> 8;
  v11 = (unsigned __int8)x2;
  v12 = x1 >> 8;
  v14 = ey;
  x2a = x2 >> 8;
  v35 = v11;
  if ( y1 == y2 )
  {
    if ( (this->CurrCell.y - ey) | (this->CurrCell.x - v10) )
    {
      if ( *(_QWORD *)&this->CurrCell.Cover )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
          (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
        v14 = ey;
        v10 = x2a;
      }
      this->CurrCell.x = v10;
      this->CurrCell.y = v14;
      *(_QWORD *)&this->CurrCell.Cover = 0i64;
    }
  }
  else
  {
    if ( v12 == v10 )
    {
      v15 = (unsigned __int8)x1 + v11;
    }
    else
    {
      v16 = 1;
      v17 = 256;
      v18 = (y2 - y1) * (256 - (unsigned __int8)x1);
      v19 = x2 - x1;
      v34 = 256;
      v37 = 1;
      if ( v19 < 0 )
      {
        v16 = -1;
        v17 = 0;
        v34 = 0;
        v37 = -1;
        v18 = (unsigned __int8)x1 * (y2 - y1);
        v19 = -v19;
      }
      v20 = v18 % v19;
      v38 = v18 / v19;
      v21 = v18 / v19;
      if ( v18 % v19 < 0 )
      {
        --v21;
        v20 += v19;
        v38 = v21;
      }
      this->CurrCell.Cover += v21;
      v22 = v17 + (unsigned __int8)x1;
      v23 = v16 + v12;
      p_CurrCell = &this->CurrCell;
      this->CurrCell.Area += v21 * v22;
      if ( (this->CurrCell.y - v14) | (this->CurrCell.x - v23) )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
          v14 = ey;
          v10 = x2a;
          v21 = v38;
          v16 = v37;
        }
        p_CurrCell->x = v23;
        this->CurrCell.y = v14;
        *(_QWORD *)&this->CurrCell.Cover = 0i64;
      }
      y1 += v21;
      if ( v23 != v10 )
      {
        v25 = (y2 + v21 - y1) << 8;
        v26 = v25 % v19;
        v33 = v25 % v19;
        v39 = v25 / v19;
        if ( v25 % v19 < 0 )
        {
          v26 += v19;
          v33 = v26;
          v39 = v25 / v19 - 1;
        }
        v27 = v20 - v19;
        do
        {
          v28 = v26 + v27 < 0;
          v27 += v26;
          v29 = v39;
          if ( !v28 )
          {
            v27 -= v19;
            v29 = v39 + 1;
          }
          this->CurrCell.Cover += v29;
          v30 = v29;
          y1 += v29;
          x = p_CurrCell->x;
          v23 += v16;
          this->CurrCell.Area += v30 << 8;
          if ( (this->CurrCell.y - v14) | (x - v23) )
          {
            if ( *(_QWORD *)&this->CurrCell.Cover )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
              v14 = ey;
              v10 = x2a;
              v16 = v37;
            }
            p_CurrCell->x = v23;
            this->CurrCell.y = v14;
            *(_QWORD *)&this->CurrCell.Cover = 0i64;
          }
          v26 = v33;
        }
        while ( v23 != v10 );
        v7 = y2;
      }
      v15 = v35 - v34 + 256;
    }
    v32 = v7 - y1;
    this->CurrCell.Cover += v32;
    this->CurrCell.Area += v32 * v15;
  }
}

// File Line: 234
// RVA: 0x9E9190
void __fastcall Scaleform::Render::Rasterizer::line(
        Scaleform::Render::Rasterizer *this,
        int x1,
        int y1,
        int x2,
        int y2)
{
  int v5; // r10d
  int v8; // r13d
  int v9; // edx
  int v10; // ebp
  int v11; // r15d
  int v12; // r8d
  int v13; // edi
  int v14; // ecx
  int v15; // r12d
  Scaleform::Render::Rasterizer::Cell *p_CurrCell; // rsi
  int v17; // r9d
  int v18; // edx
  int v19; // r10d
  int v20; // edi
  int v21; // ecx
  int v22; // r15d
  int v23; // r14d
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // ebp
  int v32; // edi
  int v33; // r10d
  int v34; // eax
  int v35; // ecx
  int v36; // r15d
  int v37; // edx
  int v38; // ebp
  int v39; // r8d
  bool v40; // sf
  int v41; // eax
  int v42; // r14d
  int v43; // r14d
  int v44; // [rsp+30h] [rbp-58h]
  int v45; // [rsp+30h] [rbp-58h]
  int v46; // [rsp+90h] [rbp+8h]
  int x1b; // [rsp+98h] [rbp+10h]
  int x1c; // [rsp+98h] [rbp+10h]
  int x1d; // [rsp+98h] [rbp+10h]
  int v51; // [rsp+A0h] [rbp+18h]
  int v52; // [rsp+A8h] [rbp+20h]
  int v53; // [rsp+A8h] [rbp+20h]
  int y2a; // [rsp+B0h] [rbp+28h]

  v52 = x2;
  v5 = x1;
  v8 = y2 - y1;
  v9 = x2 - x1;
  v10 = v5 >> 8;
  v11 = (unsigned __int8)y1;
  v12 = (unsigned __int8)y2;
  v13 = y1 >> 8;
  v14 = x2 >> 8;
  v15 = y2 >> 8;
  v46 = (unsigned __int8)y2;
  v44 = v9;
  if ( v5 >> 8 < this->MinX )
    this->MinX = v10;
  if ( v10 > this->MaxX )
    this->MaxX = v10;
  if ( v13 < this->MinY )
    this->MinY = v13;
  if ( v13 > this->MaxY )
    this->MaxY = v13;
  if ( v14 < this->MinX )
    this->MinX = v14;
  if ( v14 > this->MaxX )
    this->MaxX = v14;
  if ( v15 < this->MinY )
    this->MinY = v15;
  if ( v15 > this->MaxY )
    this->MaxY = v15;
  p_CurrCell = &this->CurrCell;
  if ( (this->CurrCell.x - v10) | (this->CurrCell.y - v13) )
  {
    if ( *(_QWORD *)&this->CurrCell.Cover )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
        (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
      v5 = x1;
      v9 = v44;
      x2 = v52;
      v12 = (unsigned __int8)y2;
    }
    p_CurrCell->x = v10;
    this->CurrCell.y = v13;
    *(_QWORD *)&this->CurrCell.Cover = 0i64;
  }
  if ( v13 == v15 )
  {
    Scaleform::Render::Rasterizer::horLine(this, v13, v5, v11, x2, v12);
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
      Scaleform::Render::Rasterizer::horLine(this, v13, v5, v11, v29 + v5, v27);
      v32 = y2a + v13;
      v33 = x1c;
      if ( (this->CurrCell.y - v32) | (p_CurrCell->x - (x1c >> 8)) )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
          v33 = x1c;
        }
        p_CurrCell->x = x1c >> 8;
        this->CurrCell.y = v32;
        *(_QWORD *)&this->CurrCell.Cover = 0i64;
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
          Scaleform::Render::Rasterizer::horLine(this, v32, v33, v39, v33 + v41, v37);
          v32 += y2a;
          v33 = v42;
          x1d = v42;
          v43 = v42 >> 8;
          if ( (this->CurrCell.y - v32) | (p_CurrCell->x - v43) )
          {
            if ( *(_QWORD *)&this->CurrCell.Cover )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
              v33 = x1d;
            }
            p_CurrCell->x = v43;
            this->CurrCell.y = v32;
            *(_QWORD *)&this->CurrCell.Cover = 0i64;
          }
          v35 = v45;
          v37 = v51;
          v39 = 256 - v51;
        }
        while ( v32 != v15 );
      }
      Scaleform::Render::Rasterizer::horLine(this, v32, v33, 256 - v51, v52, v46);
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
      v21 = p_CurrCell->x - v10;
      this->CurrCell.Cover += v18 - v11;
      this->CurrCell.Area += v19 * (v18 - v11);
      if ( (this->CurrCell.y - v20) | v21 )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
          v19 = x1b;
          v18 = v53;
          v17 = y2a;
        }
        p_CurrCell->x = v10;
        this->CurrCell.y = v20;
        *(_QWORD *)&this->CurrCell.Cover = 0i64;
      }
      v22 = 2 * v18 - 256;
      v23 = v19 * v22;
      if ( v20 != v15 )
      {
        do
        {
          v20 += v17;
          v24 = p_CurrCell->x - v10;
          v25 = this->CurrCell.y - v20;
          this->CurrCell.Cover = v22;
          this->CurrCell.Area = v23;
          if ( v25 | v24 )
          {
            if ( v22 | v23 )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
              v17 = y2a;
            }
            p_CurrCell->x = v10;
            this->CurrCell.y = v20;
            *(_QWORD *)&this->CurrCell.Cover = 0i64;
          }
        }
        while ( v20 != v15 );
        v19 = x1b;
        v18 = v53;
      }
      v26 = v18 + v46 - 256;
      this->CurrCell.Cover += v26;
      this->CurrCell.Area += v19 * v26;
    }
  }
}

// File Line: 369
// RVA: 0x9B7400
char __fastcall Scaleform::Render::Rasterizer::SortCells(Scaleform::Render::Rasterizer *this)
{
  unsigned __int64 Size; // rdx
  unsigned int v3; // esi
  unsigned int v5; // r8d
  unsigned __int64 v6; // rdx
  int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // r8d
  __int64 v10; // r9
  Scaleform::Render::Rasterizer::SortedY *Array; // rax
  unsigned int Start; // ecx
  unsigned int v13; // r9d
  unsigned __int64 v14; // r8
  Scaleform::Render::Rasterizer::Cell *v15; // r8
  Scaleform::Render::Rasterizer::SortedY *v16; // rdx
  __int64 v17; // rcx
  Scaleform::Render::Rasterizer::SortedY *v18; // rax
  unsigned __int64 Count; // rdx
  __int64 v20; // rcx
  Scaleform::Render::Rasterizer::Cell **v21; // rax
  Scaleform::Alg::ArrayAdaptor<Scaleform::Render::Rasterizer::Cell *> arr; // [rsp+20h] [rbp-18h] BYREF

  if ( *(_QWORD *)&this->CurrCell.Cover )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
      (Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
  Size = this->Cells.Size;
  v3 = 0;
  this->CurrCell.x = 0x7FFFFFFF;
  *(_QWORD *)&this->CurrCell.y = 0x7FFFFFFFi64;
  this->CurrCell.Area = 0;
  if ( !Size )
    return 0;
  if ( !this->SortedYs.Size )
  {
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
      (Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY> *)&this->SortedCells,
      Size);
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
      &this->SortedYs,
      this->MaxY - this->MinY + 1);
    memset(this->SortedYs.Array, 0, 8 * this->SortedYs.Size);
    v5 = 0;
    if ( this->Cells.Size )
    {
      v6 = 0i64;
      do
      {
        ++v5;
        v7 = this->Cells.Pages[v6 >> 4][v6 & 0xF].y - this->MinY;
        ++this->SortedYs.Array[v7].Start;
        v6 = v5;
      }
      while ( v5 < this->Cells.Size );
    }
    v8 = 0;
    v9 = 0;
    if ( this->SortedYs.Size )
    {
      v10 = 0i64;
      do
      {
        Array = this->SortedYs.Array;
        ++v9;
        Start = Array[v10].Start;
        Array[v10].Start = v8;
        v10 = v9;
        v8 += Start;
      }
      while ( v9 < this->SortedYs.Size );
    }
    v13 = 0;
    if ( this->Cells.Size )
    {
      v14 = 0i64;
      do
      {
        ++v13;
        v15 = &this->Cells.Pages[v14 >> 4][v14 & 0xF];
        v16 = &this->SortedYs.Array[v15->y - this->MinY];
        this->SortedCells.Array[v16->Count + v16->Start] = v15;
        ++v16->Count;
        v14 = v13;
      }
      while ( v13 < this->Cells.Size );
    }
    if ( this->SortedYs.Size )
    {
      v17 = 0i64;
      do
      {
        v18 = this->SortedYs.Array;
        Count = v18[v17].Count;
        if ( (_DWORD)Count )
        {
          v20 = v18[v17].Start;
          v21 = this->SortedCells.Array;
          arr.Size = Count;
          arr.Data = &v21[v20];
          Scaleform::Alg::QuickSortSliced<Scaleform::Alg::ArrayAdaptor<Scaleform::Render::Rasterizer::Cell *>,bool (*)(Scaleform::Render::Rasterizer::Cell const *,Scaleform::Render::Rasterizer::Cell const *)>(
            &arr,
            0i64,
            (unsigned int)Count,
            (bool (__fastcall *)(Scaleform::Render::Rasterizer::Cell *, Scaleform::Render::Rasterizer::Cell *))compareLinks);
        }
        v17 = ++v3;
      }
      while ( v3 < this->SortedYs.Size );
    }
  }
  return 1;
}

// File Line: 435
// RVA: 0x9B87C0
void __fastcall Scaleform::Render::Rasterizer::SweepScanline(
        Scaleform::Render::Rasterizer *this,
        unsigned int scanline,
        char *pRaster,
        unsigned int numChannels,
        int gammaIdx)
{
  unsigned __int64 v6; // r15
  Scaleform::Render::Rasterizer::SortedY *Array; // rax
  unsigned int Count; // ebp
  int v10; // esi
  Scaleform::Render::Rasterizer::Cell **v11; // rbx
  Scaleform::Render::Rasterizer::Cell *v12; // rdx
  int x; // r9d
  int Area; // eax
  int v15; // ecx
  int v16; // ecx
  char *v17; // rax

  v6 = numChannels;
  if ( scanline < this->SortedYs.Size )
  {
    Array = this->SortedYs.Array;
    Count = Array[scanline].Count;
    v10 = 0;
    v11 = &this->SortedCells.Array[Array[scanline].Start];
    if ( Count )
    {
      while ( 1 )
      {
        v12 = *v11;
        v10 += (*v11)->Cover;
        x = (*v11)->x;
        Area = (*v11)->Area;
        if ( --Count )
        {
          do
          {
            v12 = v11[1];
            ++v11;
            if ( v12->x != x )
              break;
            Area += v12->Area;
            v10 += v12->Cover;
            --Count;
          }
          while ( Count );
        }
        if ( Area )
        {
          v15 = ((v10 << 9) - Area) >> 9;
          if ( v15 < 0 )
            v15 = -v15;
          if ( this->FillRule == FillEvenOdd )
          {
            v15 &= 0x1FFu;
            if ( v15 > 256 )
              v15 = 512 - v15;
          }
          if ( v15 > 255 )
            v15 = 255;
          if ( (_DWORD)v6 )
            memset(&pRaster[(unsigned int)(v6 * (x - this->MinX))], this->GammaLut[(__int64)gammaIdx][v15], v6);
          ++x;
        }
        if ( !Count )
          break;
        if ( v12->x > x )
        {
          v16 = v10 << 9 >> 9;
          if ( v16 < 0 )
            v16 = -v16;
          if ( this->FillRule == FillEvenOdd )
          {
            v16 &= 0x1FFu;
            if ( v16 > 256 )
              v16 = 512 - v16;
          }
          if ( v16 > 255 )
            v16 = 255;
          v17 = (char *)this + 256 * (__int64)gammaIdx;
          if ( v17[v16 + 60] )
            memset(
              &pRaster[(unsigned int)(v6 * (x - this->MinX))],
              (unsigned __int8)v17[v16 + 60],
              (unsigned int)(v6 * (v12->x - x)));
        }
      }
    }
  }
}

