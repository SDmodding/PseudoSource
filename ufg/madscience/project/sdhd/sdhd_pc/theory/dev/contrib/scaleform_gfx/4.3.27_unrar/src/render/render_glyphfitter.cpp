// File Line: 34
// RVA: 0x93C800
void __fastcall Scaleform::Render::GlyphFitter::GlyphFitter(Scaleform::Render::GlyphFitter *this, Scaleform::MemoryHeap *heap, int nominalFontHeight)
{
  Scaleform::Render::LinearHeap *v3; // rax

  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::GlyphFitter::`vftable;
  this->NominalFontHeight = nominalFontHeight;
  v3 = &this->LHeap;
  v3->pHeap = heap;
  v3->Granularity = 0x2000i64;
  v3->pPagePool = 0i64;
  v3->pLastPage = 0i64;
  v3->MaxPages = 0i64;
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
  Scaleform::Render::LinearHeap *v1; // rcx

  v1 = &this->LHeap;
  v1[1].pLastPage = 0i64;
  v1[1].pPagePool = 0i64;
  v1[1].Granularity = 0i64;
  v1[1].MaxPages = 0i64;
  v1[2].pLastPage = 0i64;
  v1[2].pPagePool = 0i64;
  v1[2].Granularity = 0i64;
  v1[2].MaxPages = 0i64;
  v1[3].Granularity = 0i64;
  v1[3].pPagePool = 0i64;
  v1[4].Granularity = 0i64;
  v1[4].pHeap = 0i64;
  v1[3].MaxPages = 0i64;
  v1[4].pPagePool = 0i64;
  v1[4].MaxPages = 0i64;
  v1[5].pHeap = 0i64;
  v1[5].pPagePool = 0i64;
  v1[5].pLastPage = 0i64;
  Scaleform::Render::LinearHeap::ClearAndRelease(v1);
}

// File Line: 51
// RVA: 0x99B8D0
void __fastcall Scaleform::Render::GlyphFitter::MoveTo(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  unsigned __int64 v3; // rsi
  Scaleform::Render::GlyphFitter *v4; // rdi
  unsigned __int64 v5; // rsi
  Scaleform::Render::GlyphFitter::ContourType v6; // [rsp+50h] [rbp+8h]
  Scaleform::Render::GlyphFitter::VertexType v7; // [rsp+58h] [rbp+10h]

  v6.StartVertex = this->Vertices.Size;
  v3 = this->Contours.Size >> 2;
  v4 = this;
  v6.NumVertices = 1;
  if ( v3 >= this->Contours.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->Contours,
      v3);
  v4->Contours.Pages[v3][v4->Contours.Size & 3] = v6;
  ++v4->Contours.Size;
  v5 = v4->Vertices.Size >> 4;
  if ( v5 >= v4->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(&v4->Vertices, v4->Vertices.Size >> 4);
  v7.x = (signed int)x;
  v7.y = (signed int)y;
  v4->Vertices.Pages[v5][v4->Vertices.Size & 0xF] = v7;
  ++v4->Vertices.Size;
  v4->StartX = x;
  v4->StartY = y;
  v4->LastXf = x;
  v4->LastYf = y;
}

// File Line: 68
// RVA: 0x998870
void __fastcall Scaleform::Render::GlyphFitter::LineTo(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  unsigned __int64 v3; // rbx
  Scaleform::Render::GlyphFitter *v4; // rdi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rcx
  Scaleform::Render::GlyphFitter::ContourType *v7; // rax
  Scaleform::Render::GlyphFitter::VertexType v8; // [rsp+58h] [rbp+10h]

  v3 = this->Vertices.Size;
  v4 = this;
  if ( __PAIR__((signed int)y, (unsigned __int16)(signed int)x) != *(_DWORD *)&this->Vertices.Pages[(v3 - 1) >> 4][((_DWORD)v3 - 1) & 0xF] )
  {
    v5 = v3 >> 4;
    if ( v5 >= this->Vertices.NumPages )
      Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(&this->Vertices, v5);
    v8.x = (signed int)x;
    v8.y = (signed int)y;
    v4->Vertices.Pages[v5][v4->Vertices.Size & 0xF] = v8;
    ++v4->Vertices.Size;
    v6 = v4->Contours.Size - 1;
    v7 = v4->Contours.Pages[v6 >> 2];
    ++v7[v6 & 3].NumVertices;
  }
  v4->LastYf = y;
  v4->LastXf = x;
}

// File Line: 84
// RVA: 0x961470
void __fastcall Scaleform::Render::GlyphFitter::ClosePath(Scaleform::Render::GlyphFitter *this)
{
  float v1; // xmm1_4

  v1 = this->StartX;
  if ( v1 != this->LastXf || this->StartY != this->LastYf )
    Scaleform::Render::GlyphFitter::LineTo(this, v1, this->StartY);
}

// File Line: 92
// RVA: 0x9F0140
void __fastcall Scaleform::Render::GlyphFitter::removeDuplicateClosures(Scaleform::Render::GlyphFitter *this)
{
  unsigned int v1; // er9
  Scaleform::Render::GlyphFitter *v2; // rbx
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdx
  __int64 v5; // rax
  Scaleform::Render::GlyphFitter::ContourType *v6; // rcx
  unsigned int v7; // er11
  Scaleform::Render::GlyphFitter::ContourType *v8; // r10
  Scaleform::Render::GlyphFitter::VertexType **v9; // r8
  Scaleform::Render::GlyphFitter::VertexType *v10; // rdi
  Scaleform::Render::GlyphFitter::VertexType *v11; // rdx

  v1 = 0;
  v2 = this;
  if ( this->Contours.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = v3;
      v5 = v3 & 3;
      v6 = v2->Contours.Pages[v4 >> 2];
      v7 = v6[v5].NumVertices;
      v8 = &v6[v5];
      if ( v7 > 2 )
      {
        v9 = v2->Vertices.Pages;
        v10 = &v9[(unsigned __int64)v8->StartVertex >> 4][v8->StartVertex & 0xF];
        v11 = &v9[(unsigned __int64)(v7 + v8->StartVertex - 1) >> 4][((_BYTE)v7 + LOBYTE(v8->StartVertex) - 1) & 0xF];
        if ( v10->x == v11->x && v10->y == v11->y )
          v8->NumVertices = v7 - 1;
      }
      v3 = ++v1;
    }
    while ( v1 < v2->Contours.Size );
  }
}

// File Line: 111
// RVA: 0x9D65D0
void __fastcall Scaleform::Render::GlyphFitter::computeBounds(Scaleform::Render::GlyphFitter *this)
{
  unsigned __int64 v1; // r11
  signed __int16 v2; // bx
  signed __int16 v3; // di
  unsigned __int64 v4; // r14
  signed __int16 v5; // si
  signed __int16 v6; // bp
  Scaleform::Render::GlyphFitter::ContourType **v7; // r8
  unsigned __int64 v8; // rdx
  Scaleform::Render::GlyphFitter::ContourType *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  int v12; // er12
  __int64 v13; // r13
  Scaleform::Render::GlyphFitter::VertexType v14; // eax
  unsigned __int64 v15; // r15
  Scaleform::Render::GlyphFitter::VertexType **v16; // rcx
  __int64 v17; // r8
  Scaleform::Render::GlyphFitter::VertexType *v18; // rdx
  int v19; // er10
  signed __int64 v20; // r11
  bool v21; // sf
  unsigned __int8 v22; // of
  int v23; // er8
  int v24; // er9
  int v25; // edx
  Scaleform::Render::GlyphFitter *v26; // [rsp+40h] [rbp+8h]
  unsigned __int64 v27; // [rsp+50h] [rbp+18h]

  v26 = this;
  v1 = this->Contours.Size;
  v2 = 0x7FFF;
  v3 = -32767;
  v4 = 0i64;
  *(_DWORD *)&this->MinX = 2147450879;
  *(_DWORD *)&this->MaxX = -2147385343;
  v5 = 0x7FFF;
  v6 = -32767;
  v27 = v1;
  if ( v1 )
  {
    v7 = this->Contours.Pages;
    do
    {
      v8 = v4 & 3;
      v9 = v7[v4 >> 2];
      v10 = v9[v8].NumVertices;
      if ( v10 > 2 )
      {
        v11 = v9[v8].StartVertex;
        v12 = 0;
        v13 = v10;
        v14 = this->Vertices.Pages[(unsigned __int64)(v11 + v10 - 1) >> 4][((_BYTE)v11 + (_BYTE)v10 - 1) & 0xF];
        if ( v10 )
        {
          v15 = v11;
          v16 = this->Vertices.Pages;
          do
          {
            v17 = v15 & 0xF;
            v18 = v16[v15 >> 4];
            v19 = v18[v17].x;
            v20 = (signed __int64)&v18[v17];
            v22 = __OFSUB__(v18[v17].x, v2);
            v21 = (signed __int16)(v18[v17].x - v2) < 0;
            v23 = *(signed __int16 *)(v20 + 2);
            if ( v21 ^ v22 )
              v2 = v19;
            if ( (signed __int16)v23 < v5 )
              v5 = *(_WORD *)(v20 + 2);
            if ( (signed __int16)v19 > v3 )
              v3 = v19;
            if ( (signed __int16)v23 > v6 )
              v6 = *(_WORD *)(v20 + 2);
            ++v15;
            v24 = v14.y;
            v25 = v14.x;
            v14 = *(Scaleform::Render::GlyphFitter::VertexType *)v20;
            v12 += v25 * v23 - v19 * v24;
            --v13;
          }
          while ( v13 );
          this = v26;
          v1 = v27;
        }
        if ( v2 < this->MinX || v5 < this->MinY || v3 > this->MaxX || v6 > this->MaxY )
        {
          this->MinX = v2;
          this->MinY = v5;
          this->MaxX = v3;
          this->MaxY = v6;
          this->Direction = (v12 > 0) + 1;
        }
      }
      v7 = this->Contours.Pages;
      ++v4;
    }
    while ( v4 < v1 );
  }
}

// File Line: 156
// RVA: 0x9E0040
void __fastcall Scaleform::Render::GlyphFitter::detectEvents(Scaleform::Render::GlyphFitter *this, Scaleform::Render::GlyphFitter::FitDir dir)
{
  Scaleform::Render::GlyphFitter::FitDir v2; // er13
  Scaleform::Render::GlyphFitter *v3; // rbx
  __int16 v4; // ax
  int v5; // er15
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // er12
  Scaleform::Render::GlyphFitter::ContourType *v9; // r14
  int v10; // esi
  unsigned int v11; // edi
  Scaleform::Render::GlyphFitter::VertexType **v12; // r11
  unsigned int v13; // edx
  __int16 v14; // r10
  __int64 v15; // rcx
  __int16 v16; // bp
  __int16 v17; // di
  __int16 v18; // r9
  __int16 v19; // ax
  __int16 v20; // cx
  char v21; // dl
  int v22; // er11
  bool v23; // zf
  bool v24; // sf
  unsigned __int8 v25; // of
  Scaleform::Render::GlyphFitter::VertexType v26; // [rsp+60h] [rbp+8h]
  Scaleform::Render::GlyphFitter::VertexType v27; // [rsp+70h] [rbp+18h]

  v2 = dir;
  v3 = this;
  if ( dir == 1 )
    v4 = this->MinX;
  else
    v4 = this->MinY;
  v5 = v4;
  if ( dir == 1 )
  {
    v6 = this->MaxX;
    v7 = v3->MinX;
  }
  else
  {
    v6 = this->MaxY;
    v7 = v3->MinY;
  }
  Scaleform::Render::ArrayUnsafe<unsigned char>::Resize(&v3->Events, v6 - v7 + 1);
  memset(v3->Events.Array, 0, v3->Events.Size);
  v8 = 0;
  if ( LODWORD(v3->Contours.Size) )
  {
    while ( 1 )
    {
      v9 = &v3->Contours.Pages[(unsigned __int64)v8 >> 2][v8 & 3];
      if ( v9->NumVertices > 2 )
      {
        v10 = 0;
        *v3->Events.Array = 3;
        v11 = v9->NumVertices;
        if ( v11 )
          break;
      }
LABEL_29:
      if ( ++v8 >= LODWORD(v3->Contours.Size) )
        return;
    }
    while ( 1 )
    {
      v12 = v3->Vertices.Pages;
      v26 = v12[(unsigned __int64)(v9->StartVertex + (v10 + 1) % v11) >> 4][((unsigned __int8)v9->StartVertex
                                                                           + (unsigned __int8)((v10 + 1) % v11)) & 0xF];
      v13 = v9->StartVertex + (v10 + 2) % v11;
      v14 = (__int16)v12[(unsigned __int64)(v9->StartVertex + (v10 + 1) % v11) >> 4][((unsigned __int8)v9->StartVertex
                                                                                    + (unsigned __int8)((v10 + 1) % v11)) & 0xF];
      v15 = (LOBYTE(v9->StartVertex) + (unsigned __int8)((v10 + 2) % v11)) & 0xF;
      v27 = v12[(unsigned __int64)v13 >> 4][v15];
      v16 = (__int16)v12[(unsigned __int64)v13 >> 4][v15];
      if ( v2 == 1 )
      {
        v17 = (__int16)v12[(unsigned __int64)(v9->StartVertex + v10) >> 4][(LOBYTE(v9->StartVertex) + (_BYTE)v10) & 0xF];
        v18 = v14;
        v19 = -(signed __int16)(*(_DWORD *)&v12[(unsigned __int64)v13 >> 4][v15] >> 16);
        v20 = (__int16)v12[(unsigned __int64)v13 >> 4][v15];
      }
      else
      {
        v17 = *(_DWORD *)&v12[(unsigned __int64)(v9->StartVertex + v10) >> 4][(LOBYTE(v9->StartVertex) + (_BYTE)v10) & 0xF] >> 16;
        v19 = (__int16)v12[(unsigned __int64)(v9->StartVertex + v10) >> 4][(LOBYTE(v9->StartVertex) + (_BYTE)v10) & 0xF];
        v18 = v26.y;
        v20 = v27.y;
      }
      v21 = 0;
      if ( v17 >= v18 )
      {
        if ( v20 >= v18 )
          goto LABEL_17;
        if ( v17 > v18 )
          goto LABEL_28;
      }
      if ( v20 > v18 )
        goto LABEL_23;
LABEL_17:
      v22 = v18 - v5;
      if ( v19 > v14 )
        goto LABEL_32;
      if ( v14 <= v16 )
      {
        v3->Events.Array[v22] |= (v3->Direction == 1) + 1;
        v21 = 1;
      }
      if ( v19 >= v14 )
      {
LABEL_32:
        if ( v14 >= v16 )
          goto LABEL_27;
      }
      if ( !v21 )
      {
LABEL_23:
        if ( v17 != v18 )
          goto LABEL_28;
        v22 = v18 - v5;
        v25 = __OFSUB__(v19, v14);
        v23 = v19 == v14;
        v24 = (signed __int16)(v19 - v14) < 0;
        if ( v19 < v14 )
        {
          v3->Events.Array[v22] |= (v3->Direction == 1) + 1;
          v25 = __OFSUB__(v19, v14);
          v23 = v19 == v14;
          v24 = (signed __int16)(v19 - v14) < 0;
        }
        if ( (unsigned __int8)(v24 ^ v25) | v23 )
          goto LABEL_28;
LABEL_27:
        v3->Events.Array[v22] |= (v3->Direction != 1) + 1;
      }
LABEL_28:
      v11 = v9->NumVertices;
      if ( ++v10 >= v11 )
        goto LABEL_29;
    }
  }
}

// File Line: 230
// RVA: 0x9D6A00
void __fastcall Scaleform::Render::GlyphFitter::computeLerpRamp(Scaleform::Render::GlyphFitter *this, Scaleform::Render::GlyphFitter::FitDir dir, int unitsPerPixel, int middle, int lowerCaseTop, int upperCaseTop)
{
  __int16 v6; // ax
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *v7; // rbx
  unsigned __int64 v8; // rdi
  int v9; // er15
  Scaleform::Render::GlyphFitter::FitDir v10; // esi
  Scaleform::Render::GlyphFitter *v11; // rbp
  int v12; // er10
  int v13; // er12
  signed int v14; // er8
  int v15; // ecx
  int v16; // er13
  int v17; // er9
  __int16 v18; // cx
  int v19; // eax
  int v20; // er14
  unsigned __int64 v21; // rcx
  int v22; // edi
  int v23; // er11
  char v24; // dl
  bool v25; // zf
  bool v26; // sf
  unsigned __int8 v27; // of
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rsi
  unsigned __int64 v30; // rax
  int v31; // eax
  unsigned __int64 v32; // rsi
  unsigned __int64 v33; // rdi
  signed __int64 v34; // rsi
  unsigned __int64 v35; // rdi
  void *v36; // r14
  const void *v37; // rdx
  __int64 v38; // r8
  Scaleform::Render::GlyphFitter::VertexType **v39; // rax
  unsigned int v40; // edi
  Scaleform::Render::GlyphFitter::VertexType v41; // er8
  Scaleform::Render::GlyphFitter::VertexType v42; // ecx
  signed int v43; // ebx
  unsigned int v44; // edx
  signed int v45; // edx
  signed int v46; // [rsp+20h] [rbp-58h]
  unsigned __int64 v47; // [rsp+28h] [rbp-50h]
  int v48; // [rsp+80h] [rbp+8h]
  Scaleform::Render::GlyphFitter::FitDir v49; // [rsp+88h] [rbp+10h]
  Scaleform::Render::GlyphFitter::VertexType v50; // [rsp+90h] [rbp+18h]
  Scaleform::Render::GlyphFitter::VertexType v51; // [rsp+90h] [rbp+18h]
  Scaleform::Render::GlyphFitter::VertexType v52; // [rsp+90h] [rbp+18h]
  int v53; // [rsp+98h] [rbp+20h]
  int upperCaseTopa; // [rsp+A8h] [rbp+30h]

  v53 = middle;
  v49 = dir;
  v6 = this->SnappedHeight;
  v7 = &this->LerpPairs;
  this->LerpPairs.Size = 0i64;
  v8 = this->LerpPairs.Size >> 4;
  v9 = unitsPerPixel;
  v10 = dir;
  v11 = this;
  v47 = 0i64;
  v50.x = -4 * v6;
  v50.y = -4 * v6;
  if ( v8 >= this->LerpPairs.NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(&this->LerpPairs, v8);
  v12 = lowerCaseTop;
  v13 = upperCaseTop;
  v14 = -32767;
  v7->Pages[v8][v7->Size & 0xF] = v50;
  ++v7->Size;
  v15 = v11->SnappedHeight;
  v16 = v9 * ((lowerCaseTop + v15 + v9) / v9) - v15;
  v17 = v9 * ((upperCaseTop + v15 + v9) / v9) - v15;
  v48 = v9 * ((upperCaseTop + v15 + v9) / v9) - v15;
  if ( v10 == 1 )
    v18 = v11->MinX;
  else
    v18 = v11->MinY;
  v19 = v18;
  v20 = v9 + 1;
  v46 = v18;
  if ( v11->Events.Size )
  {
    v21 = 0i64;
    v22 = v19;
    v23 = -v19;
    upperCaseTopa = -v19;
    while ( 1 )
    {
      v24 = v11->Events.Array[v21];
      if ( v22 <= v53 || v10 == 1 )
        break;
      if ( v24 & 2 )
      {
        if ( !v13 )
          goto LABEL_54;
        if ( v22 >= v13 && v22 < v20 + v13 )
        {
          v27 = __OFSUB__(v22, v20 + v14);
          v25 = v22 == v20 + v14;
          v26 = v22 - (v20 + v14) < 0;
          goto LABEL_15;
        }
        if ( v22 >= v12 && v22 < v20 + v12 )
        {
          if ( v22 <= v20 + v14 || v9 + v7->Pages[(v7->Size - 1) >> 4][(LODWORD(v7->Size) - 1) & 0xF].y >= v16 )
          {
            v30 = v7->Size;
            if ( v30 )
              v7->Size = v30 - 1;
          }
          v29 = v7->Size;
          v51.y = v16;
        }
        else
        {
LABEL_54:
          v17 = v9 * ((v9 + v11->SnappedHeight + v22) / v9) - v11->SnappedHeight;
          v27 = __OFSUB__(v22, v20 + v14);
          v25 = v22 == v20 + v14;
          v26 = v22 - (v20 + v14) < 0;
LABEL_15:
          if ( (unsigned __int8)(v26 ^ v27) | v25
            || v9 + v7->Pages[(v7->Size - 1) >> 4][(LODWORD(v7->Size) - 1) & 0xF].y >= v17 )
          {
            v28 = v7->Size;
            if ( v28 )
              v7->Size = v28 - 1;
          }
          v29 = v7->Size;
          v51.y = v17;
        }
LABEL_32:
        v32 = v29 >> 4;
        v51.x = v22;
        if ( v32 >= v7->NumPages )
        {
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(v7, v32);
          v12 = lowerCaseTop;
          v23 = upperCaseTopa;
        }
        v7->Pages[v32][v7->Size & 0xF] = v51;
        ++v7->Size;
        goto LABEL_35;
      }
LABEL_36:
      v17 = v48;
      v21 = (unsigned int)(v23 + ++v22);
      if ( v21 >= v11->Events.Size )
        goto LABEL_37;
    }
    if ( !(v24 & 1) || v22 <= v20 + v14 )
      goto LABEL_36;
    v29 = v7->Size;
    v31 = v9 * ((v22 + v11->SnappedHeight + v9 / 2 + 1) / v9) - v11->SnappedHeight;
    if ( v7->Pages[(v29 - 1) >> 4][((_DWORD)v29 - 1) & 0xF].y != v31 )
    {
      v51.y = v9 * ((v22 + v11->SnappedHeight + v9 / 2 + 1) / v9) - LOWORD(v11->SnappedHeight);
      goto LABEL_32;
    }
LABEL_35:
    v10 = v49;
    v14 = v22;
    goto LABEL_36;
  }
LABEL_37:
  v33 = v7->Size >> 4;
  v52.x = 4 * LOWORD(v11->SnappedHeight);
  v52.y = 4 * LOWORD(v11->SnappedHeight);
  if ( v33 >= v7->NumPages )
    Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(v7, v33);
  v7->Pages[v33][v7->Size & 0xF] = v52;
  ++v7->Size;
  v25 = v10 == 1;
  v34 = (signed __int64)&v11->LerpRampX;
  if ( !v25 )
    v34 = (signed __int64)&v11->LerpRampY;
  v35 = v11->Events.Size;
  if ( v35 > *(_QWORD *)(v34 + 8) )
  {
    v36 = Scaleform::Render::LinearHeap::Alloc(*(Scaleform::Render::LinearHeap **)v34, 2 * v35);
    memset(v36, 0, 2 * v35);
    v37 = *(const void **)(v34 + 16);
    if ( v37 )
    {
      v38 = *(_QWORD *)(v34 + 8);
      if ( v38 )
        memmove(v36, v37, 2 * v38);
    }
    *(_QWORD *)(v34 + 16) = v36;
  }
  *(_QWORD *)(v34 + 8) = v35;
  v39 = v11->LerpPairs.Pages;
  v40 = 2;
  v41 = **v39;
  v42 = (*v39)[1];
  if ( v11->Events.Size )
  {
    v43 = v46;
    do
    {
      if ( v43 >= v42.x )
      {
        v44 = v40;
        if ( v40 < v11->LerpPairs.Size )
        {
          v41 = v42;
          ++v40;
          v42 = v11->LerpPairs.Pages[(unsigned __int64)v44 >> 4][v44 & 0xF];
        }
      }
      v45 = v43++;
      *(_WORD *)(*(_QWORD *)(v34 + 16) + 2 * v47) = v41.y + (v45 - v41.x) * (v42.y - v41.y) / (v42.x - v41.x) - v46;
      v47 = (unsigned int)(v43 - v46);
    }
    while ( v47 < v11->Events.Size );
  }
}

