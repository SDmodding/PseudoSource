// File Line: 35
// RVA: 0x928580
void __fastcall Scaleform::Render::ConvertVertexData_XY16i_XY32f(Scaleform::Render::VertexElement *psourceElement, Scaleform::Render::VertexElement *pdestElement, char *psource, unsigned int sourceSize, unsigned int sourceOffset, char *pdest, unsigned int destSize, unsigned int destOffset, unsigned int count, const void *__formal)
{
  char *v10; // r10
  float *v11; // rdx
  char *v12; // rcx
  signed int v13; // eax

  v10 = &psource[count * sourceSize];
  if ( psource < v10 )
  {
    v11 = (float *)&pdest[destOffset];
    v12 = &psource[sourceOffset];
    do
    {
      *v11 = (float)*(signed __int16 *)v12;
      v13 = *((signed __int16 *)v12 + 1);
      v12 += sourceSize;
      v11[1] = (float)v13;
      v11 = (float *)((char *)v11 + destSize);
    }
    while ( &v12[-sourceOffset] < v10 );
  }
}

// File Line: 55
// RVA: 0x928600
void __fastcall Scaleform::Render::ConvertVertexData_XY16i_XYZ16i(Scaleform::Render::VertexElement *psourceElement, Scaleform::Render::VertexElement *pdestElement, char *psource, unsigned int sourceSize, unsigned int sourceOffset, char *pdest, unsigned int destSize, unsigned int destOffset, unsigned int count, const void *__formal)
{
  char *v10; // r10
  char *v11; // rax
  char *v12; // rdx
  __int16 v13; // cx

  v10 = &psource[count * sourceSize];
  if ( psource < v10 )
  {
    v11 = &pdest[destOffset + 4];
    v12 = &psource[sourceOffset];
    do
    {
      *((_WORD *)v11 - 2) = *(_WORD *)v12;
      v13 = *((_WORD *)v12 + 1);
      v12 += sourceSize;
      *((_WORD *)v11 - 1) = v13;
      *(_WORD *)v11 = 0;
      v11 += destSize;
    }
    while ( &v12[-sourceOffset] < v10 );
  }
}

// File Line: 76
// RVA: 0x928670
void __fastcall Scaleform::Render::ConvertVertexData_ARGB_RGBA(Scaleform::Render::VertexElement *psourceElement, Scaleform::Render::VertexElement *pdestElement, char *psource, unsigned int sourceSize, unsigned int sourceOffset, char *pdest, unsigned int destSize, unsigned int destOffset, unsigned int count, const void *__formal)
{
  char *v10; // r10
  __int64 v11; // rdi
  char *v12; // r9
  char *v13; // r8
  int v14; // edx
  int v15; // eax

  v10 = &psource[count * sourceSize];
  if ( psource < v10 )
  {
    v11 = sourceSize;
    v12 = &pdest[destOffset];
    v13 = &psource[sourceOffset];
    do
    {
      v14 = *(_DWORD *)v13;
      v15 = (unsigned __int8)v13[2];
      v13 += v11;
      *(_DWORD *)v12 = v14 & 0xFF00FF00 | v15 | ((unsigned __int8)v14 << 16);
      v12 += destSize;
    }
    while ( &v13[-sourceOffset] < v10 );
  }
}

// File Line: 100
// RVA: 0x9286F0
void __fastcall Scaleform::Render::InitVertexData_U8(Scaleform::Render::VertexElement *psourceElement, Scaleform::Render::VertexElement *pdestElement, char *__formal, unsigned int a4, unsigned int __formala, char *pdest, unsigned int destSize, unsigned int destOffset, unsigned int count, const void *parg)
{
  char *v10; // rax
  char v11; // r9
  char *v12; // rdx

  v10 = pdest;
  v11 = *(_BYTE *)parg;
  v12 = &pdest[count * destSize];
  if ( pdest < v12 )
  {
    do
    {
      v10[destOffset] = v11;
      v10 += destSize;
    }
    while ( v10 < v12 );
  }
}

// File Line: 169
// RVA: 0x965270
void __fastcall Scaleform::Render::CopyVertexElements(char *source, unsigned __int64 sourceFormatSize, char *dest, unsigned __int64 destFormatSize, unsigned __int64 elementSize, unsigned __int64 count)
{
  unsigned __int64 v6; // r14
  char *v7; // rdi
  unsigned __int64 v8; // rbp
  char *v9; // rsi
  char *v10; // rbx
  int v11; // eax
  __int16 v12; // ax
  char v13; // al

  v6 = destFormatSize;
  v7 = dest;
  v8 = sourceFormatSize;
  v9 = &source[count * sourceFormatSize];
  v10 = source;
  switch ( elementSize )
  {
    case 1ui64:
      if ( source < v9 )
      {
        do
        {
          v13 = *v10;
          v10 += sourceFormatSize;
          *v7 = v13;
          v7 += destFormatSize;
        }
        while ( v10 < v9 );
      }
      break;
    case 2ui64:
      if ( source < v9 )
      {
        do
        {
          v12 = *(_WORD *)v10;
          v10 += sourceFormatSize;
          *(_WORD *)v7 = v12;
          v7 += destFormatSize;
        }
        while ( v10 < v9 );
      }
      break;
    case 4ui64:
      if ( source < v9 )
      {
        do
        {
          v11 = *(_DWORD *)v10;
          v10 += sourceFormatSize;
          *(_DWORD *)v7 = v11;
          v7 += destFormatSize;
        }
        while ( v10 < v9 );
      }
      break;
    default:
      if ( source < v9 )
      {
        do
        {
          memmove(v7, v10, elementSize);
          v10 += v8;
          v7 += v6;
        }
        while ( v10 < v9 );
      }
      break;
  }
}

// File Line: 276
// RVA: 0x9638C0
void __fastcall Scaleform::Render::ConvertVertices_Buffered(Scaleform::Render::VertexFormat *sourceFormat, void *psource, Scaleform::Render::VertexFormat *destFormat, void *pdest, unsigned int count, void **pargumentData)
{
  unsigned int v6; // er13
  char *v7; // rbp
  Scaleform::Render::VertexFormat *v8; // r12
  Scaleform::Render::VertexFormat *v9; // r15
  unsigned int i; // esi
  Scaleform::Render::VertexElement *v11; // rdi
  unsigned int v12; // er8
  Scaleform::Render::VertexElement *v13; // rbx
  Scaleform::Render::ConvertTarget *v14; // r10
  unsigned int j; // eax
  Scaleform::Render::VertexElementType v16; // ecx
  void *v17; // rax
  unsigned __int64 elementSize; // [rsp+20h] [rbp-2068h]
  __int64 v19; // [rsp+30h] [rbp-2058h]
  __int64 v20; // [rsp+38h] [rbp-2050h]
  __int64 v21; // [rsp+40h] [rbp-2048h]
  char Src[8192]; // [rsp+50h] [rbp-2038h]
  unsigned int v23; // [rsp+2098h] [rbp+10h]
  char *Dst; // [rsp+20A0h] [rbp+18h]

  v6 = count;
  v7 = (char *)psource;
  v23 = destFormat->Size;
  Dst = (char *)pdest;
  v8 = destFormat;
  v9 = sourceFormat;
  for ( i = 0x2000 / destFormat->Size; v6; Dst += v23 * i )
  {
    v11 = v8->pElements;
    if ( i > v6 )
      i = v6;
    if ( v11->Attribute )
    {
      do
      {
        v12 = v11->Attribute;
        if ( ((v11->Attribute & 0xF0) - 112) & 0xFFFFFFEF )
        {
          v13 = v9->pElements;
          v14 = VertexConvertTable[(v12 >> 8) & 0xF];
          for ( j = v13->Attribute; j; ++v13 )
          {
            if ( (j & 0xFF00) == (v11->Attribute & 0xFF00) )
              break;
            j = v13[1].Attribute;
          }
          v16 = v14->TargetType;
          if ( v16 )
          {
            while ( !(v12 & 0x10000) && v13->Attribute != v14->SourceType || (v12 & v14->TargetMask) != v16 )
            {
              v16 = v14[1].TargetType;
              ++v14;
              if ( v16 == VET_None )
                goto LABEL_14;
            }
            if ( pargumentData )
              v17 = *pargumentData;
            else
              v17 = 0i64;
            LODWORD(v21) = i;
            LODWORD(v20) = v11->Offset;
            LODWORD(v19) = v8->Size;
            LODWORD(elementSize) = v13->Offset;
            v14->pConvertFunc(v13, v11, v7, v9->Size, elementSize, Src, v19, v20, v21, v17);
          }
          else
          {
LABEL_14:
            Scaleform::Render::CopyVertexElements(
              &v7[v13->Offset],
              v9->Size,
              &Src[v11->Offset],
              v8->Size,
              (v13->Attribute & 0xF) * VertexTypeSizes_41[((unsigned __int8)v13->Attribute >> 4) - 1],
              i);
          }
        }
        ++v11;
      }
      while ( v11->Attribute );
      v6 = count;
    }
    memmove(Dst, Src, v23 * i);
    v7 += i * v9->Size;
    v6 -= i;
    count = v6;
  }
}

// File Line: 357
// RVA: 0x963690
void __fastcall Scaleform::Render::ConvertIndices_SIMD(unsigned __int16 *pdest, unsigned __int16 *psource, unsigned int count, unsigned __int16 delta)
{
  __int64 v4; // rax
  unsigned __int64 v5; // r8
  unsigned __int16 *v6; // r10
  unsigned __int64 v7; // r11
  unsigned __int16 v8; // ax
  __m128i v9; // xmm1
  __m128i v10; // xmm1
  __m128i v11; // xmm0
  signed __int64 v12; // rcx
  unsigned __int16 v13; // ax

  JUMPOUT(((unsigned __int8)psource ^ (unsigned __int8)pdest) & 0xF, 0, Scaleform::Render::ConvertIndices_NonOpt);
  v4 = count;
  v5 = ((unsigned __int64)pdest + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v6 = &psource[v4];
  v7 = (unsigned __int64)&pdest[v4] & 0xFFFFFFFFFFFFFFF0ui64;
  if ( v5 < v7 )
  {
    for ( ; (unsigned __int64)pdest < v5; *(pdest - 1) = delta + v8 )
    {
      v8 = *psource;
      ++pdest;
      ++psource;
    }
    v9 = _mm_cvtsi32_si128((signed __int16)delta);
    v10 = _mm_shuffle_epi32(_mm_unpacklo_epi16(v9, v9), 0);
    do
    {
      v11 = _mm_loadu_si128((const __m128i *)psource);
      pdest += 8;
      psource += 8;
      _mm_stream_si128((__m128i *)pdest - 1, _mm_add_epi16(v11, v10));
    }
    while ( (unsigned __int64)pdest < v7 );
  }
  if ( psource < v6 )
  {
    v12 = (char *)pdest - (char *)psource;
    do
    {
      v13 = *psource;
      ++psource;
      *(unsigned __int16 *)((char *)psource + v12 - 2) = delta + v13;
    }
    while ( psource < v6 );
  }
}

// File Line: 398
// RVA: 0x9635D0
void __fastcall Scaleform::Render::ConvertIndices_NonOpt(unsigned __int16 *pdest, unsigned __int16 *psource, unsigned int count, unsigned __int16 delta)
{
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned __int16 *v7; // r10
  unsigned __int16 *v8; // r8
  unsigned __int16 *v9; // rax
  signed __int64 v10; // rdx
  __int16 v11; // cx

  if ( (count & 3) != 1 )
  {
    if ( (count & 3) != 2 )
    {
      if ( (count & 3) != 3 )
        goto LABEL_7;
      ++pdest;
      v4 = delta + *psource;
      ++psource;
      *(pdest - 1) = v4;
    }
    ++pdest;
    v5 = delta + *psource;
    ++psource;
    *(pdest - 1) = v5;
  }
  ++pdest;
  v6 = delta + *psource;
  ++psource;
  *(pdest - 1) = v6;
LABEL_7:
  v7 = &psource[count & 0xFFFFFFFC];
  if ( psource < v7 )
  {
    v8 = psource + 2;
    v9 = pdest + 2;
    v10 = (char *)psource - (char *)pdest - 4;
    do
    {
      v11 = *(unsigned __int16 *)((char *)v9 + v10);
      v9 += 4;
      v8 += 4;
      *(v9 - 6) = delta + v11;
      *(v9 - 5) = delta + *(v8 - 5);
      *(v9 - 4) = delta + *(v8 - 4);
      *(v9 - 3) = delta + *(v8 - 3);
    }
    while ( (unsigned __int16 *)((char *)v9 + v10) < v7 );
  }
}

// File Line: 417
// RVA: 0x963580
void __fastcall Scaleform::Render::ConvertIndices(unsigned __int16 *pdest, unsigned __int16 *psource, unsigned int count, unsigned __int16 delta)
{
  if ( !(`Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::`local static guard' & 1) )
  {
    `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::`local static guard' |= 1u;
    `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::HasSSE2 = 1;
  }
  if ( `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::HasSSE2 )
    Scaleform::Render::ConvertIndices_SIMD(pdest, psource, count, delta);
  else
    Scaleform::Render::ConvertIndices_NonOpt(pdest, psource, count, delta);
}

// File Line: 431
// RVA: 0x94D020
void __fastcall Scaleform::Render::SystemVertexFormat::~SystemVertexFormat(Scaleform::Render::SystemVertexFormat *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SystemVertexFormat::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 442
// RVA: 0x159C4C0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16i::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16i::Format__);
}

// File Line: 453
// RVA: 0x159C4A0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16f::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16f::Format__);
}

// File Line: 463
// RVA: 0x159C4B0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16fAlpha::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16fAlpha::Format__);
}

// File Line: 472
// RVA: 0x159C4E0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iC32::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iC32::Format__);
}

// File Line: 482
// RVA: 0x159C4D0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iAlpha::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iAlpha::Format__);
}

// File Line: 494
// RVA: 0x159C4F0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iCF32::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iCF32::Format__);
}

// File Line: 504
// RVA: 0x159C500
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iInstance::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iInstance::Format__);
}

// File Line: 513
// RVA: 0x159C510
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iUV::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iUV::Format__);
}

