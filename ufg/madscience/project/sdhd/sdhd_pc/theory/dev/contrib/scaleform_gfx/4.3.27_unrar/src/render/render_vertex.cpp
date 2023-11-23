// File Line: 35
// RVA: 0x928580
void __fastcall Scaleform::Render::ConvertVertexData_XY16i_XY32f(
        Scaleform::Render::VertexElement *psourceElement,
        Scaleform::Render::VertexElement *pdestElement,
        char *psource,
        unsigned int sourceSize,
        unsigned int sourceOffset,
        char *pdest,
        unsigned int destSize,
        unsigned int destOffset,
        unsigned int count,
        const void *__formal)
{
  char *v10; // r10
  float *v11; // rdx
  char *v12; // rcx
  int v13; // eax

  v10 = &psource[count * sourceSize];
  if ( psource < v10 )
  {
    v11 = (float *)&pdest[destOffset];
    v12 = &psource[sourceOffset];
    do
    {
      *v11 = (float)*(__int16 *)v12;
      v13 = *((__int16 *)v12 + 1);
      v12 += sourceSize;
      v11[1] = (float)v13;
      v11 = (float *)((char *)v11 + destSize);
    }
    while ( &v12[-sourceOffset] < v10 );
  }
}

// File Line: 55
// RVA: 0x928600
void __fastcall Scaleform::Render::ConvertVertexData_XY16i_XYZ16i(
        Scaleform::Render::VertexElement *psourceElement,
        Scaleform::Render::VertexElement *pdestElement,
        char *psource,
        unsigned int sourceSize,
        unsigned int sourceOffset,
        char *pdest,
        unsigned int destSize,
        unsigned int destOffset,
        unsigned int count,
        const void *__formal)
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
void __fastcall Scaleform::Render::ConvertVertexData_ARGB_RGBA(
        Scaleform::Render::VertexElement *psourceElement,
        Scaleform::Render::VertexElement *pdestElement,
        char *psource,
        unsigned int sourceSize,
        unsigned int sourceOffset,
        char *pdest,
        unsigned int destSize,
        unsigned int destOffset,
        unsigned int count,
        const void *__formal)
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
void __fastcall Scaleform::Render::InitVertexData_U8(
        Scaleform::Render::VertexElement *psourceElement,
        Scaleform::Render::VertexElement *pdestElement,
        char *__formal,
        unsigned int a4,
        unsigned int __formala,
        char *pdest,
        unsigned int destSize,
        unsigned int destOffset,
        unsigned int count,
        char *parg)
{
  char *v10; // rax
  char v11; // r9
  char *v12; // rdx

  v10 = pdest;
  v11 = *parg;
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
void __fastcall Scaleform::Render::CopyVertexElements(
        char *source,
        unsigned __int64 sourceFormatSize,
        char *dest,
        unsigned __int64 destFormatSize,
        unsigned __int64 elementSize,
        unsigned __int64 count)
{
  char *v9; // rsi
  char *v10; // rbx
  int v11; // eax
  __int16 v12; // ax
  char v13; // al

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
          *dest = v13;
          dest += destFormatSize;
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
          *(_WORD *)dest = v12;
          dest += destFormatSize;
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
          *(_DWORD *)dest = v11;
          dest += destFormatSize;
        }
        while ( v10 < v9 );
      }
      break;
    default:
      if ( source < v9 )
      {
        do
        {
          memmove(dest, v10, elementSize);
          v10 += sourceFormatSize;
          dest += destFormatSize;
        }
        while ( v10 < v9 );
      }
      break;
  }
}

// File Line: 276
// RVA: 0x9638C0
void __fastcall Scaleform::Render::ConvertVertices_Buffered(
        Scaleform::Render::VertexFormat *sourceFormat,
        char *psource,
        Scaleform::Render::VertexFormat *destFormat,
        char *pdest,
        unsigned int count,
        const void **pargumentData)
{
  unsigned int v6; // r13d
  unsigned int i; // esi
  Scaleform::Render::VertexElement *pElements; // rdi
  unsigned int Attribute; // r8d
  Scaleform::Render::VertexElement *v13; // rbx
  Scaleform::Render::ConvertTarget *v14; // r10
  unsigned int j; // eax
  Scaleform::Render::VertexElementType TargetType; // ecx
  const void *v17; // rax
  char Src[8192]; // [rsp+50h] [rbp-2038h] BYREF
  unsigned int Size; // [rsp+2098h] [rbp+10h]

  v6 = count;
  Size = destFormat->Size;
  for ( i = 0x2000 / destFormat->Size; v6; pdest += Size * i )
  {
    pElements = destFormat->pElements;
    if ( i > v6 )
      i = v6;
    if ( pElements->Attribute )
    {
      do
      {
        Attribute = pElements->Attribute;
        if ( (((Attribute & 0xF0) - 112) & 0xFFFFFFEF) != 0 )
        {
          v13 = sourceFormat->pElements;
          v14 = VertexConvertTable[(Attribute >> 8) & 0xF];
          for ( j = v13->Attribute; j; ++v13 )
          {
            if ( (j & 0xFF00) == (pElements->Attribute & 0xFF00) )
              break;
            j = v13[1].Attribute;
          }
          TargetType = v14->TargetType;
          if ( TargetType )
          {
            while ( (Attribute & 0x10000) == 0 && v13->Attribute != v14->SourceType
                 || (Attribute & v14->TargetMask) != TargetType )
            {
              TargetType = v14[1].TargetType;
              ++v14;
              if ( TargetType == VET_None )
                goto LABEL_14;
            }
            if ( pargumentData )
              v17 = *pargumentData;
            else
              v17 = 0i64;
            v14->pConvertFunc(
              v13,
              pElements,
              psource,
              sourceFormat->Size,
              v13->Offset,
              Src,
              destFormat->Size,
              pElements->Offset,
              i,
              v17);
          }
          else
          {
LABEL_14:
            Scaleform::Render::CopyVertexElements(
              &psource[v13->Offset],
              sourceFormat->Size,
              &Src[pElements->Offset],
              destFormat->Size,
              (v13->Attribute & 0xF) * VertexTypeSizes_41[((unsigned __int8)v13->Attribute >> 4) - 1],
              i);
          }
        }
        ++pElements;
      }
      while ( pElements->Attribute );
      v6 = count;
    }
    memmove(pdest, Src, Size * i);
    psource += i * sourceFormat->Size;
    v6 -= i;
    count = v6;
  }
}

// File Line: 357
// RVA: 0x963690
void __fastcall Scaleform::Render::ConvertIndices_SIMD(
        __m128i *pdest,
        __m128i *psource,
        unsigned int count,
        signed __int16 delta)
{
  __int64 v4; // rax
  unsigned __int64 v5; // r8
  unsigned __int16 *v6; // r10
  unsigned __int64 v7; // r11
  __int16 v8; // ax
  __m128i v9; // xmm1
  __m128i v10; // xmm1
  __m128i v11; // xmm0
  signed __int64 v12; // rcx
  __int16 v13; // ax

  if ( (((unsigned __int8)psource ^ (unsigned __int8)pdest) & 0xF) != 0 )
  {
    Scaleform::Render::ConvertIndices_NonOpt(pdest->m128i_i8, psource->m128i_i8, count, delta);
  }
  else
  {
    v4 = count;
    v5 = ((unsigned __int64)&pdest->m128i_u64[1] + 7) & 0xFFFFFFFFFFFFFFF0ui64;
    v6 = (unsigned __int16 *)psource + v4;
    v7 = ((unsigned __int64)pdest + 2 * v4) & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v5 < v7 )
    {
      for ( ; (unsigned __int64)pdest < v5; pdest[-1].m128i_i16[7] = delta + v8 )
      {
        v8 = psource->m128i_i16[0];
        pdest = (__m128i *)((char *)pdest + 2);
        psource = (__m128i *)((char *)psource + 2);
      }
      v9 = _mm_cvtsi32_si128(delta);
      v10 = _mm_shuffle_epi32(_mm_unpacklo_epi16(v9, v9), 0);
      do
      {
        v11 = _mm_loadu_si128(psource);
        ++pdest;
        ++psource;
        _mm_stream_si128(pdest - 1, _mm_add_epi16(v11, v10));
      }
      while ( (unsigned __int64)pdest < v7 );
    }
    if ( psource < (__m128i *)v6 )
    {
      v12 = (char *)pdest - (char *)psource;
      do
      {
        v13 = psource->m128i_i16[0];
        psource = (__m128i *)((char *)psource + 2);
        *(__int16 *)((char *)&psource->m128i_i16[-1] + v12) = delta + v13;
      }
      while ( psource < (__m128i *)v6 );
    }
  }
}

// File Line: 398
// RVA: 0x9635D0
void __fastcall Scaleform::Render::ConvertIndices_NonOpt(
        char *pdest,
        char *psource,
        unsigned int count,
        unsigned __int16 delta)
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
      pdest += 2;
      v4 = delta + *(_WORD *)psource;
      psource += 2;
      *((_WORD *)pdest - 1) = v4;
    }
    pdest += 2;
    v5 = delta + *(_WORD *)psource;
    psource += 2;
    *((_WORD *)pdest - 1) = v5;
  }
  pdest += 2;
  v6 = delta + *(_WORD *)psource;
  psource += 2;
  *((_WORD *)pdest - 1) = v6;
LABEL_7:
  v7 = (unsigned __int16 *)&psource[2 * (count & 0xFFFFFFFC)];
  if ( psource < (char *)v7 )
  {
    v8 = (unsigned __int16 *)(psource + 4);
    v9 = (unsigned __int16 *)(pdest + 4);
    v10 = psource - pdest - 4;
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
void __fastcall Scaleform::Render::ConvertIndices(
        unsigned __int16 *pdest,
        unsigned __int16 *psource,
        unsigned int count,
        unsigned __int16 delta)
{
  if ( (`Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics::`2::`local static guard & 1) == 0 )
  {
    `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics::`2::`local static guard |= 1u;
    `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics::`2::HasSSE2 = 1;
  }
  if ( `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics::`2::HasSSE2 )
    Scaleform::Render::ConvertIndices_SIMD(pdest, psource, count, delta);
  else
    Scaleform::Render::ConvertIndices_NonOpt(pdest, psource, count, delta);
}

// File Line: 431
// RVA: 0x94D020
void __fastcall Scaleform::Render::SystemVertexFormat::~SystemVertexFormat(Scaleform::Render::SystemVertexFormat *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SystemVertexFormat::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 442
// RVA: 0x159C4C0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16i::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16i::Format__);
}

// File Line: 453
// RVA: 0x159C4A0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16f::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16f::Format__);
}

// File Line: 463
// RVA: 0x159C4B0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16fAlpha::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16fAlpha::Format__);
}

// File Line: 472
// RVA: 0x159C4E0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iC32::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iC32::Format__);
}

// File Line: 482
// RVA: 0x159C4D0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iAlpha::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iAlpha::Format__);
}

// File Line: 494
// RVA: 0x159C4F0
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iCF32::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iCF32::Format__);
}

// File Line: 504
// RVA: 0x159C500
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iInstance::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iInstance::Format__);
}

// File Line: 513
// RVA: 0x159C510
__int64 dynamic_initializer_for__Scaleform::Render::VertexXY16iUV::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::VertexXY16iUV::Format__);
}

