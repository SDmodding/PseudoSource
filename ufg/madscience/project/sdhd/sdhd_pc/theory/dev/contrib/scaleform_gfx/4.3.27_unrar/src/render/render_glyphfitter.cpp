// File Line: 34
// RVA: 0x93C800
void __fastcall Scaleform::Render::GlyphFitter::GlyphFitter(
        Scaleform::Render::GlyphFitter *this,
        Scaleform::MemoryHeap *heap,
        int nominalFontHeight)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::GlyphFitter::`vftable;
  this->NominalFontHeight = nominalFontHeight;
  this->LHeap.pHeap = heap;
  this->LHeap.Granularity = 0x2000i64;
  this->LHeap.pPagePool = 0i64;
  this->LHeap.pLastPage = 0i64;
  this->LHeap.MaxPages = 0i64;
  this->Contours.pHeap = &this->LHeap;
  this->Contours.Size = 0i64;
  this->Contours.NumPages = 0i64;
  this->Contours.MaxPages = 0i64;
  this->Contours.Pages = 0i64;
  this->Vertices.pHeap = &this->LHeap;
  this->Vertices.Size = 0i64;
  this->Vertices.NumPages = 0i64;
  this->Vertices.MaxPages = 0i64;
  this->Vertices.Pages = 0i64;
  this->Events.pHeap = &this->LHeap;
  this->Events.Size = 0i64;
  this->Events.Array = 0i64;
  this->LerpPairs.pHeap = &this->LHeap;
  this->LerpPairs.Size = 0i64;
  this->LerpPairs.NumPages = 0i64;
  this->LerpPairs.MaxPages = 0i64;
  this->LerpPairs.Pages = 0i64;
  this->LerpRampX.pHeap = &this->LHeap;
  this->LerpRampX.Size = 0i64;
  this->LerpRampX.Array = 0i64;
  this->LerpRampY.pHeap = &this->LHeap;
  this->LerpRampY.Size = 0i64;
  this->LerpRampY.Array = 0i64;
  *(_QWORD *)&this->StartX = 0i64;
  *(_QWORD *)&this->LastXf = 0i64;
}

// File Line: 39
// RVA: 0x95F350
void __fastcall Scaleform::Render::GlyphFitter::Clear(Scaleform::Render::GlyphFitter *this)
{
  Scaleform::Render::LinearHeap *p_LHeap; // rcx

  p_LHeap = &this->LHeap;
  p_LHeap[1].pLastPage = 0i64;
  p_LHeap[1].pPagePool = 0i64;
  p_LHeap[1].Granularity = 0i64;
  p_LHeap[1].MaxPages = 0i64;
  p_LHeap[2].pLastPage = 0i64;
  p_LHeap[2].pPagePool = 0i64;
  p_LHeap[2].Granularity = 0i64;
  p_LHeap[2].MaxPages = 0i64;
  p_LHeap[3].Granularity = 0i64;
  p_LHeap[3].pPagePool = 0i64;
  p_LHeap[4].Granularity = 0i64;
  p_LHeap[4].pHeap = 0i64;
  p_LHeap[3].MaxPages = 0i64;
  p_LHeap[4].pPagePool = 0i64;
  p_LHeap[4].MaxPages = 0i64;
  p_LHeap[5].pHeap = 0i64;
  p_LHeap[5].pPagePool = 0i64;
  p_LHeap[5].pLastPage = 0i64;
  Scaleform::Render::LinearHeap::ClearAndRelease(p_LHeap);
}

// File Line: 51
// RVA: 0x99B8D0
void __fastcall Scaleform::Render::GlyphFitter::MoveTo(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v5; // rsi
  Scaleform::Render::GlyphFitter::ContourType v6; // [rsp+50h] [rbp+8h]
  Scaleform::Render::GlyphFitter::VertexType v7; // [rsp+58h] [rbp+10h]

  v6.StartVertex = this->Vertices.Size;
  v3 = this->Contours.Size >> 2;
  v6.NumVertices = 1;
  if ( v3 >= this->Contours.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->Contours,
      v3);
  this->Contours.Pages[v3][this->Contours.Size & 3] = v6;
  ++this->Contours.Size;
  v5 = this->Vertices.Size >> 4;
  if ( v5 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(&this->Vertices, this->Vertices.Size >> 4);
  v7.y = (int)y;
  v7.x = (int)x;
  this->Vertices.Pages[v5][this->Vertices.Size & 0xF] = v7;
  ++this->Vertices.Size;
  this->StartX = x;
  this->StartY = y;
  this->LastXf = x;
  this->LastYf = y;
}

// File Line: 68
// RVA: 0x998870
void __fastcall Scaleform::Render::GlyphFitter::LineTo(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  unsigned __int64 Size; // rbx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rcx
  Scaleform::Render::GlyphFitter::ContourType *v7; // rax
  Scaleform::Render::GlyphFitter::VertexType v8; // [rsp+58h] [rbp+10h]

  Size = this->Vertices.Size;
  if ( __PAIR32__((int)y, (int)x) != *(_DWORD *)&this->Vertices.Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF] )
  {
    v5 = Size >> 4;
    if ( v5 >= this->Vertices.NumPages )
      Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(&this->Vertices, v5);
    v8.y = (int)y;
    v8.x = (int)x;
    this->Vertices.Pages[v5][this->Vertices.Size & 0xF] = v8;
    ++this->Vertices.Size;
    v6 = this->Contours.Size - 1;
    v7 = this->Contours.Pages[v6 >> 2];
    ++v7[v6 & 3].NumVertices;
  }
  this->LastYf = y;
  this->LastXf = x;
}

// File Line: 84
// RVA: 0x961470
void __fastcall Scaleform::Render::GlyphFitter::ClosePath(Scaleform::Render::GlyphFitter *this)
{
  float StartX; // xmm1_4

  StartX = this->StartX;
  if ( StartX != this->LastXf || this->StartY != this->LastYf )
    Scaleform::Render::GlyphFitter::LineTo(this, StartX, this->StartY);
}

// File Line: 92
// RVA: 0x9F0140
void __fastcall Scaleform::Render::GlyphFitter::removeDuplicateClosures(Scaleform::Render::GlyphFitter *this)
{
  unsigned int v1; // r9d
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdx
  __int64 v5; // rax
  Scaleform::Render::GlyphFitter::ContourType *v6; // rcx
  unsigned int NumVertices; // r11d
  Scaleform::Render::GlyphFitter::ContourType *v8; // r10
  Scaleform::Render::GlyphFitter::VertexType **Pages; // r8
  Scaleform::Render::GlyphFitter::VertexType *v10; // rdi
  Scaleform::Render::GlyphFitter::VertexType *v11; // rdx

  v1 = 0;
  if ( this->Contours.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = v3;
      v5 = v3 & 3;
      v6 = this->Contours.Pages[v4 >> 2];
      NumVertices = v6[v5].NumVertices;
      v8 = &v6[v5];
      if ( NumVertices > 2 )
      {
        Pages = this->Vertices.Pages;
        v10 = &Pages[(unsigned __int64)v8->StartVertex >> 4][v8->StartVertex & 0xF];
        v11 = &Pages[(unsigned __int64)(NumVertices + v8->StartVertex - 1) >> 4][((_BYTE)NumVertices
                                                                                + LOBYTE(v8->StartVertex)
                                                                                - 1) & 0xF];
        if ( v10->x == v11->x && v10->y == v11->y )
          v8->NumVertices = NumVertices - 1;
      }
      v3 = ++v1;
    }
    while ( v1 < this->Contours.Size );
  }
}

// File Line: 111
// RVA: 0x9D65D0
void __fastcall Scaleform::Render::GlyphFitter::computeBounds(Scaleform::Render::GlyphFitter *this)
{
  unsigned __int64 Size; // r11
  __int16 v2; // bx
  __int16 v3; // di
  unsigned __int64 v4; // r14
  __int16 v5; // si
  __int16 v6; // bp
  Scaleform::Render::GlyphFitter::ContourType **Pages; // r8
  unsigned __int64 v8; // rdx
  Scaleform::Render::GlyphFitter::ContourType *v9; // rax
  unsigned int NumVertices; // r8d
  unsigned int StartVertex; // r9d
  int v12; // r12d
  __int64 v13; // r13
  Scaleform::Render::GlyphFitter::VertexType v14; // eax
  unsigned __int64 v15; // r15
  Scaleform::Render::GlyphFitter::VertexType **v16; // rcx
  __int64 v17; // r8
  Scaleform::Render::GlyphFitter::VertexType *v18; // rdx
  int x; // r10d
  __int16 *p_x; // r11
  int v21; // r8d
  int y; // r9d
  int v23; // edx
  Scaleform::Render::GlyphFitter *v24; // [rsp+40h] [rbp+8h]
  unsigned __int64 v25; // [rsp+50h] [rbp+18h]

  v24 = this;
  Size = this->Contours.Size;
  v2 = 0x7FFF;
  v3 = -32767;
  v4 = 0i64;
  *(_DWORD *)&this->MinX = 2147450879;
  *(_DWORD *)&this->MaxX = -2147385343;
  v5 = 0x7FFF;
  v6 = -32767;
  v25 = Size;
  if ( Size )
  {
    Pages = this->Contours.Pages;
    do
    {
      v8 = v4 & 3;
      v9 = Pages[v4 >> 2];
      NumVertices = v9[v8].NumVertices;
      if ( NumVertices > 2 )
      {
        StartVertex = v9[v8].StartVertex;
        v12 = 0;
        v13 = NumVertices;
        v14 = this->Vertices.Pages[(unsigned __int64)(StartVertex + NumVertices - 1) >> 4][((_BYTE)StartVertex
                                                                                          + (_BYTE)NumVertices
                                                                                          - 1) & 0xF];
        v15 = StartVertex;
        v16 = this->Vertices.Pages;
        do
        {
          v17 = v15 & 0xF;
          v18 = v16[v15 >> 4];
          x = v18[v17].x;
          p_x = &v18[v17].x;
          v21 = p_x[1];
          if ( *p_x < v2 )
            v2 = x;
          if ( (__int16)v21 < v5 )
            v5 = p_x[1];
          if ( (__int16)x > v3 )
            v3 = x;
          if ( (__int16)v21 > v6 )
            v6 = p_x[1];
          ++v15;
          y = v14.y;
          v23 = v14.x;
          v14 = *(Scaleform::Render::GlyphFitter::VertexType *)p_x;
          v12 += v23 * v21 - x * y;
          --v13;
        }
        while ( v13 );
        this = v24;
        Size = v25;
        if ( v2 < v24->MinX || v5 < v24->MinY || v3 > v24->MaxX || v6 > v24->MaxY )
        {
          v24->MinX = v2;
          v24->MinY = v5;
          v24->MaxX = v3;
          v24->MaxY = v6;
          v24->Direction = (v12 > 0) + 1;
        }
      }
      Pages = this->Contours.Pages;
      ++v4;
    }
    while ( v4 < Size );
  }
}

// File Line: 156
// RVA: 0x9E0040
void __fastcall Scaleform::Render::GlyphFitter::detectEvents(
        Scaleform::Render::GlyphFitter *this,
        Scaleform::Render::GlyphFitter::FitDir dir)
{
  __int16 MinX; // ax
  int v5; // r15d
  int MaxX; // ecx
  int MinY; // eax
  unsigned int v8; // r12d
  Scaleform::Render::GlyphFitter::ContourType *v9; // r14
  int v10; // esi
  unsigned int NumVertices; // edi
  Scaleform::Render::GlyphFitter::VertexType **Pages; // r11
  Scaleform::Render::GlyphFitter::VertexType v13; // eax
  __int16 x; // bp
  __int16 v15; // di
  __int16 y; // r9
  __int16 v17; // ax
  __int16 v18; // cx
  char v19; // dl
  int v20; // r11d
  bool v21; // cc
  Scaleform::Render::GlyphFitter::VertexType v22; // [rsp+60h] [rbp+8h]

  if ( dir == FitX )
    MinX = this->MinX;
  else
    MinX = this->MinY;
  v5 = MinX;
  if ( dir == FitX )
  {
    MaxX = this->MaxX;
    MinY = this->MinX;
  }
  else
  {
    MaxX = this->MaxY;
    MinY = this->MinY;
  }
  Scaleform::Render::ArrayUnsafe<unsigned char>::Resize(&this->Events, MaxX - MinY + 1);
  memset(this->Events.Array, 0, this->Events.Size);
  v8 = 0;
  if ( LODWORD(this->Contours.Size) )
  {
    while ( 1 )
    {
      v9 = &this->Contours.Pages[(unsigned __int64)v8 >> 2][v8 & 3];
      if ( v9->NumVertices > 2 )
      {
        v10 = 0;
        *this->Events.Array = 3;
        NumVertices = v9->NumVertices;
        if ( NumVertices )
          break;
      }
LABEL_29:
      if ( ++v8 >= LODWORD(this->Contours.Size) )
        return;
    }
    while ( 1 )
    {
      Pages = this->Vertices.Pages;
      v22 = Pages[(unsigned __int64)(v9->StartVertex + (v10 + 1) % NumVertices) >> 4][((unsigned __int8)v9->StartVertex
                                                                                     + (unsigned __int8)((v10 + 1) % NumVertices)) & 0xF];
      v13 = Pages[(unsigned __int64)(v9->StartVertex + (v10 + 2) % NumVertices) >> 4][(LOBYTE(v9->StartVertex)
                                                                                     + (unsigned __int8)((v10 + 2) % NumVertices)) & 0xF];
      x = v13.x;
      if ( dir == FitX )
      {
        v15 = (__int16)Pages[(unsigned __int64)(v9->StartVertex + v10) >> 4][(LOBYTE(v9->StartVertex) + (_BYTE)v10) & 0xF];
        y = v22.x;
        v17 = -v13.y;
        v18 = x;
      }
      else
      {
        v15 = HIWORD(*(_DWORD *)&Pages[(unsigned __int64)(v9->StartVertex + v10) >> 4][(LOBYTE(v9->StartVertex)
                                                                                      + (_BYTE)v10) & 0xF]);
        v13.x = (__int16)Pages[(unsigned __int64)(v9->StartVertex + v10) >> 4][(LOBYTE(v9->StartVertex) + (_BYTE)v10) & 0xF];
        y = v22.y;
        v18 = v13.y;
      }
      v19 = 0;
      if ( v15 >= y )
      {
        if ( v18 >= y )
          goto LABEL_17;
        if ( v15 > y )
          goto LABEL_28;
      }
      if ( v18 > y )
        goto LABEL_23;
LABEL_17:
      v20 = y - v5;
      if ( v17 > v22.x )
        goto LABEL_21;
      if ( v22.x <= x )
      {
        this->Events.Array[v20] |= (this->Direction == DirCW) + 1;
        v19 = 1;
      }
      if ( v17 >= v22.x )
      {
LABEL_21:
        if ( v22.x >= x )
          goto LABEL_27;
      }
      if ( !v19 )
      {
LABEL_23:
        if ( v15 != y )
          goto LABEL_28;
        v20 = y - v5;
        v21 = v17 <= v22.x;
        if ( v17 < v22.x )
        {
          this->Events.Array[v20] |= (this->Direction == DirCW) + 1;
          v21 = v17 <= v22.x;
        }
        if ( v21 )
          goto LABEL_28;
LABEL_27:
        this->Events.Array[v20] |= (this->Direction != DirCW) + 1;
      }
LABEL_28:
      NumVertices = v9->NumVertices;
      if ( ++v10 >= NumVertices )
        goto LABEL_29;
    }
  }
}

// File Line: 230
// RVA: 0x9D6A00
void __fastcall Scaleform::Render::GlyphFitter::computeLerpRamp(
        Scaleform::Render::GlyphFitter *this,
        Scaleform::Render::GlyphFitter::FitDir dir,
        int unitsPerPixel,
        int middle,
        int lowerCaseTop,
        int upperCaseTop)
{
  __int16 SnappedHeight; // ax
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *p_LerpPairs; // rbx
  unsigned __int64 v8; // rdi
  Scaleform::Render::GlyphFitter::FitDir v10; // esi
  int v12; // r10d
  int v14; // r8d
  int v15; // ecx
  int v16; // r13d
  int v17; // r9d
  __int16 MinX; // cx
  int v19; // eax
  int v20; // r14d
  unsigned __int64 v21; // rcx
  int v22; // edi
  int v23; // r11d
  char v24; // dl
  bool v25; // cc
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rsi
  unsigned __int64 Size; // rax
  unsigned __int64 v29; // rsi
  unsigned __int64 v30; // rdi
  bool v31; // zf
  Scaleform::Render::ArrayUnsafe<short> *p_LerpRampX; // rsi
  unsigned __int64 v33; // rdi
  void *v34; // r14
  __int16 *Array; // rdx
  unsigned __int64 v36; // r8
  Scaleform::Render::GlyphFitter::VertexType **Pages; // rax
  unsigned int v38; // edi
  Scaleform::Render::GlyphFitter::VertexType v39; // r8d
  Scaleform::Render::GlyphFitter::VertexType v40; // ecx
  int v41; // ebx
  unsigned int v42; // edx
  int v43; // edx
  int v44; // [rsp+20h] [rbp-58h]
  unsigned __int64 v45; // [rsp+28h] [rbp-50h]
  int v46; // [rsp+80h] [rbp+8h]
  Scaleform::Render::GlyphFitter::VertexType v48; // [rsp+90h] [rbp+18h]
  Scaleform::Render::GlyphFitter::VertexType v49; // [rsp+90h] [rbp+18h]
  Scaleform::Render::GlyphFitter::VertexType v50; // [rsp+90h] [rbp+18h]
  int upperCaseTopa; // [rsp+A8h] [rbp+30h]

  SnappedHeight = this->SnappedHeight;
  p_LerpPairs = &this->LerpPairs;
  this->LerpPairs.Size = 0i64;
  v8 = this->LerpPairs.Size >> 4;
  v10 = dir;
  v45 = 0i64;
  v48.x = -4 * SnappedHeight;
  v48.y = -4 * SnappedHeight;
  if ( v8 >= this->LerpPairs.NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(&this->LerpPairs, v8);
  v12 = lowerCaseTop;
  v14 = -32767;
  p_LerpPairs->Pages[v8][p_LerpPairs->Size & 0xF] = v48;
  ++p_LerpPairs->Size;
  v15 = this->SnappedHeight;
  v16 = unitsPerPixel * ((lowerCaseTop + v15 + unitsPerPixel) / unitsPerPixel) - v15;
  v17 = unitsPerPixel * ((upperCaseTop + v15 + unitsPerPixel) / unitsPerPixel) - v15;
  v46 = v17;
  if ( v10 == FitX )
    MinX = this->MinX;
  else
    MinX = this->MinY;
  v19 = MinX;
  v20 = unitsPerPixel + 1;
  v44 = MinX;
  if ( this->Events.Size )
  {
    v21 = 0i64;
    v22 = v19;
    v23 = -v19;
    upperCaseTopa = -v19;
    while ( 1 )
    {
      v24 = this->Events.Array[v21];
      if ( v22 <= middle || v10 == FitX )
        break;
      if ( (v24 & 2) != 0 )
      {
        if ( !upperCaseTop )
          goto LABEL_27;
        if ( v22 >= upperCaseTop && v22 < v20 + upperCaseTop )
        {
          v25 = v22 <= v20 + v14;
          goto LABEL_15;
        }
        if ( v22 >= v12 && v22 < v20 + v12 )
        {
          if ( v22 <= v20 + v14
            || unitsPerPixel
             + p_LerpPairs->Pages[(p_LerpPairs->Size - 1) >> 4][(LODWORD(p_LerpPairs->Size) - 1) & 0xF].y >= v16 )
          {
            Size = p_LerpPairs->Size;
            if ( Size )
              p_LerpPairs->Size = Size - 1;
          }
          v27 = p_LerpPairs->Size;
          v49.y = v16;
        }
        else
        {
LABEL_27:
          v17 = unitsPerPixel * ((unitsPerPixel + this->SnappedHeight + v22) / unitsPerPixel) - this->SnappedHeight;
          v25 = v22 <= v20 + v14;
LABEL_15:
          if ( v25
            || unitsPerPixel
             + p_LerpPairs->Pages[(p_LerpPairs->Size - 1) >> 4][(LODWORD(p_LerpPairs->Size) - 1) & 0xF].y >= v17 )
          {
            v26 = p_LerpPairs->Size;
            if ( v26 )
              p_LerpPairs->Size = v26 - 1;
          }
          v27 = p_LerpPairs->Size;
          v49.y = v17;
        }
LABEL_32:
        v29 = v27 >> 4;
        v49.x = v22;
        if ( v29 >= p_LerpPairs->NumPages )
        {
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(p_LerpPairs, v29);
          v12 = lowerCaseTop;
          v23 = upperCaseTopa;
        }
        p_LerpPairs->Pages[v29][p_LerpPairs->Size & 0xF] = v49;
        ++p_LerpPairs->Size;
        goto LABEL_35;
      }
LABEL_36:
      v17 = v46;
      ++v22;
      v21 = (unsigned int)(v23 + v22);
      if ( v21 >= this->Events.Size )
        goto LABEL_37;
    }
    if ( (v24 & 1) == 0 || v22 <= v20 + v14 )
      goto LABEL_36;
    v27 = p_LerpPairs->Size;
    if ( p_LerpPairs->Pages[(v27 - 1) >> 4][((_DWORD)v27 - 1) & 0xF].y != unitsPerPixel
                                                                        * ((v22
                                                                          + this->SnappedHeight
                                                                          + unitsPerPixel / 2
                                                                          + 1)
                                                                         / unitsPerPixel)
                                                                        - this->SnappedHeight )
    {
      v49.y = unitsPerPixel * ((v22 + this->SnappedHeight + unitsPerPixel / 2 + 1) / unitsPerPixel)
            - LOWORD(this->SnappedHeight);
      goto LABEL_32;
    }
LABEL_35:
    v10 = dir;
    v14 = v22;
    goto LABEL_36;
  }
LABEL_37:
  v30 = p_LerpPairs->Size >> 4;
  v50.x = 4 * LOWORD(this->SnappedHeight);
  v50.y = v50.x;
  if ( v30 >= p_LerpPairs->NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(p_LerpPairs, v30);
  p_LerpPairs->Pages[v30][p_LerpPairs->Size & 0xF] = v50;
  ++p_LerpPairs->Size;
  v31 = v10 == FitX;
  p_LerpRampX = &this->LerpRampX;
  if ( !v31 )
    p_LerpRampX = &this->LerpRampY;
  v33 = this->Events.Size;
  if ( v33 > p_LerpRampX->Size )
  {
    v34 = Scaleform::Render::LinearHeap::Alloc(p_LerpRampX->pHeap, 2 * v33);
    memset(v34, 0, 2 * v33);
    Array = p_LerpRampX->Array;
    if ( Array )
    {
      v36 = p_LerpRampX->Size;
      if ( v36 )
        memmove(v34, Array, 2 * v36);
    }
    p_LerpRampX->Array = (__int16 *)v34;
  }
  p_LerpRampX->Size = v33;
  Pages = this->LerpPairs.Pages;
  v38 = 2;
  v39 = **Pages;
  v40 = (*Pages)[1];
  if ( this->Events.Size )
  {
    v41 = v44;
    do
    {
      if ( v41 >= v40.x )
      {
        v42 = v38;
        if ( v38 < this->LerpPairs.Size )
        {
          v39 = v40;
          ++v38;
          v40 = this->LerpPairs.Pages[(unsigned __int64)v42 >> 4][v42 & 0xF];
        }
      }
      v43 = v41++;
      p_LerpRampX->Array[v45] = v39.y + (v43 - v39.x) * (v40.y - v39.y) / (v40.x - v39.x) - v44;
      v45 = (unsigned int)(v41 - v44);
    }
    while ( v45 < this->Events.Size );
  }
}

