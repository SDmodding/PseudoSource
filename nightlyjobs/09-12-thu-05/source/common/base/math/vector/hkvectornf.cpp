// File Line: 23
// RVA: 0xC731D0
void __fastcall hkVectorNf::hkVectorNf(hkVectorNf *this, int size)
{
  hkVectorNf *v2; // rdi
  int v3; // ebx
  hkMemoryAllocator **v4; // rax
  hkVector4f *v5; // rax

  v2 = this;
  this->m_size = size;
  this->m_flags = 0;
  if ( size > 0 )
  {
    v3 = (size + 3) >> 2;
    v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkVector4f *)hkMemoryRouter::alignedAlloc(v4[11], 16 * v3, 16);
    v2->m_elements = v5;
    v5[v3 - 1] = 0i64;
    v2->m_flags = 2147483648;
  }
}

// File Line: 41
// RVA: 0xC73240
void __fastcall hkVectorNf::hkVectorNf(hkVectorNf *this, const float *v, int size)
{
  int v3; // esi
  const float *v4; // rbp
  hkVectorNf *v5; // rdi
  int v6; // ebx
  hkMemoryAllocator **v7; // rax
  hkVector4f *v8; // rax

  v3 = size;
  v4 = v;
  v5 = this;
  this->m_size = size;
  this->m_flags = 0;
  if ( size > 0 )
  {
    v6 = (size + 3) >> 2;
    v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkVector4f *)hkMemoryRouter::alignedAlloc(v7[11], 16 * v6, 16);
    v5->m_elements = v8;
    hkVectorNf::_setValues(v8, v4, v3);
    v5->m_flags = 2147483648;
  }
}

// File Line: 56
// RVA: 0xC72FD0
void __fastcall hkVectorNf::set(hkVectorNf *this, const float *v, int size)
{
  const float *v3; // rsi
  int v4; // ebx
  hkVectorNf *v5; // rdi

  v3 = v;
  v4 = size;
  v5 = this;
  hkVectorNf::_setSize(this, size);
  if ( v4 > 0 )
    hkVectorNf::_setValues(v5->m_elements, v3, v4);
}

// File Line: 65
// RVA: 0xC736A0
void __fastcall hkVectorNf::_setValues(hkVector4f *dst, const float *v, int size)
{
  hkVector4f *v3; // r9
  signed __int64 v4; // rdx
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm0

  v3 = &dst[(signed __int64)(size + 3) >> 2];
  if ( (unsigned __int8)v & 0xF )
  {
    for ( ; dst != v3; dst[-1] = (hkVector4f)v6.m_quad )
    {
      v6.m_quad = *(__m128 *)v;
      ++dst;
      v += 4;
    }
  }
  else if ( dst != v3 )
  {
    v4 = (char *)v - (char *)dst;
    do
    {
      v5.m_quad = *(__m128 *)((char *)dst + v4);
      ++dst;
      dst[-1] = (hkVector4f)v5.m_quad;
    }
    while ( dst != v3 );
  }
  v3[-1].m_quad = _mm_and_ps(hkVector4fComparison_maskToComparison_297[hkVectorNf::s_zeroMask[size & 3]], v3[-1].m_quad);
}

// File Line: 94
// RVA: 0xC737F0
void __fastcall hkVectorNf::_setSizeAndZeroLast(hkVectorNf *this, int size)
{
  char v2; // bl
  hkVectorNf *v3; // rdi
  __m128 *v4; // rdx

  v2 = size;
  v3 = this;
  hkVectorNf::_setSize(this, size);
  if ( v2 & 3 )
  {
    v4 = &v3->m_elements[((v3->m_size + 3) >> 2) - 1].m_quad;
    *v4 = _mm_and_ps(hkVector4fComparison_maskToComparison_297[hkVectorNf::s_zeroMask[v2 & 3]], *v4);
  }
}

// File Line: 107
// RVA: 0xC73020
void __fastcall hkVectorNf::setSizeAndZero(hkVectorNf *this, int size)
{
  hkVectorNf *v2; // rbx

  v2 = this;
  hkVectorNf::_setSize(this, size);
  hkVectorNf::setZero(v2);
}

// File Line: 113
// RVA: 0xC73050
void __fastcall hkVectorNf::setZero(hkVectorNf *this)
{
  hkVector4f *v1; // rax
  hkVector4f *v2; // rdx

  v1 = this->m_elements;
  v2 = &this->m_elements[(signed __int64)(this->m_size + 3) >> 2];
  if ( this->m_elements != v2 )
  {
    do
    {
      *v1 = 0i64;
      ++v1;
    }
    while ( v1 != v2 );
  }
}

// File Line: 127
// RVA: 0xC73090
void __fastcall hkVectorNf::negate(hkVectorNf *this)
{
  hkVector4f *v1; // rax
  hkVector4f *v2; // rdx
  __m128 v3; // xmm1
  __m128 v4; // xmm0

  v1 = this->m_elements;
  v2 = &this->m_elements[(signed __int64)(this->m_size + 3) >> 2];
  if ( this->m_elements != v2 )
  {
    v3 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v4 = v1->m_quad;
      ++v1;
      v1[-1].m_quad = _mm_xor_ps(v4, v3);
    }
    while ( v1 != v2 );
  }
}

// File Line: 141
// RVA: 0xC73730
void __fastcall hkVectorNf::_setSize(hkVectorNf *this, int size)
{
  int v2; // ebp
  int v3; // esi
  hkVectorNf *v4; // rdi
  int v5; // eax
  hkVector4f *v6; // rbx
  hkMemoryAllocator **v7; // rax
  hkMemoryAllocator **v8; // rax
  hkVector4f *v9; // rax

  v2 = size;
  v3 = (size + 3) >> 2;
  v4 = this;
  v5 = (this->m_size + 3) >> 2;
  if ( v5 == v3 )
    goto LABEL_4;
  if ( this->m_flags < 0 )
  {
    if ( v5 )
    {
      v6 = this->m_elements;
      v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v7[11], v6);
      v4->m_flags = 0;
    }
    if ( !v3 )
      goto LABEL_9;
  }
  else if ( v3 <= v5 )
  {
LABEL_4:
    this->m_size = size;
    return;
  }
  v8 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkVector4f *)hkMemoryRouter::alignedAlloc(v8[11], 16 * v3, 16);
  v4->m_flags = 2147483648;
  v4->m_elements = v9;
LABEL_9:
  v4->m_size = v2;
}

// File Line: 191
// RVA: 0xC732D0
void __fastcall hkVectorNf::hkVectorNf(hkVectorNf *this, hkVectorNf *rhs)
{
  int v2; // eax
  hkVectorNf *v3; // rsi
  int v4; // ebx
  hkVectorNf *v5; // rdi
  int v6; // ebx
  hkMemoryAllocator **v7; // rax
  hkVector4f *v8; // rax
  hkVector4f *v9; // rdx
  signed __int64 i; // r8
  hkVector4f *v11; // rcx

  v2 = rhs->m_size;
  this->m_flags = 0;
  v3 = rhs;
  this->m_size = v2;
  v4 = rhs->m_size;
  v5 = this;
  if ( v4 )
  {
    v6 = (v4 + 3) >> 2;
    v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkVector4f *)hkMemoryRouter::alignedAlloc(v7[11], 16 * v6, 16);
    v5->m_elements = v8;
    v9 = v3->m_elements;
    for ( i = (signed __int64)&v8[v6]; v8 != (hkVector4f *)i; ++v9 )
    {
      v11 = v8;
      ++v8;
      *v11 = (hkVector4f)v9->m_quad;
    }
    v5->m_flags = 2147483648;
  }
}

// File Line: 213
// RVA: 0xC73380
void __fastcall hkVectorNf::operator=(hkVectorNf *this, hkVectorNf *rhs)
{
  hkVectorNf *v2; // rdi
  hkVectorNf *v3; // rbx
  hkVector4f *v4; // rax
  hkVector4f *v5; // rdx
  signed __int64 v6; // r8
  hkVector4f *v7; // rcx

  v2 = rhs;
  v3 = this;
  hkVectorNf::_setSize(this, rhs->m_size);
  v4 = v3->m_elements;
  v5 = v2->m_elements;
  v6 = (signed __int64)&v3->m_elements[(signed __int64)(v2->m_size + 3) >> 2];
  if ( v3->m_elements != (hkVector4f *)v6 )
  {
    do
    {
      v7 = v4;
      ++v4;
      *v7 = (hkVector4f)v5->m_quad;
      ++v5;
    }
    while ( v4 != (hkVector4f *)v6 );
  }
}

// File Line: 228
// RVA: 0xC72DE0
hkSimdFloat32 *__fastcall hkVectorNf::lengthSquared(hkVectorNf *this, hkSimdFloat32 *result)
{
  hkVector4f *v2; // r8
  hkVector4f *v3; // rax
  __m128 i; // xmm2
  __m128 v5; // xmm0
  hkSimdFloat32 *v6; // rax
  __m128 v7; // xmm1

  v2 = &this->m_elements[(signed __int64)(this->m_size + 3) >> 2];
  v3 = this->m_elements + 1;
  for ( i = _mm_mul_ps(this->m_elements->m_quad, this->m_elements->m_quad); v3 != v2; i = _mm_add_ps(
                                                                                            i,
                                                                                            _mm_mul_ps(v5, v5)) )
  {
    v5 = v3->m_quad;
    ++v3;
  }
  v6 = result;
  v7 = _mm_add_ps(_mm_shuffle_ps(i, i, 78), i);
  result->m_real = _mm_add_ps(_mm_shuffle_ps(v7, v7, 177), v7);
  return v6;
}

// File Line: 248
// RVA: 0xC72E50
hkSimdFloat32 *__fastcall hkVectorNf::length(hkVectorNf *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rbx
  __m128 v3; // xmm3
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm1
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = hkVectorNf::lengthSquared(this, &resulta)->m_real;
  v4 = v2;
  v5 = _mm_rsqrt_ps(v3);
  v2->m_real = _mm_andnot_ps(
                 _mm_cmpleps(v3, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v5), v5)),
                     _mm_mul_ps(*(__m128 *)_xmm, v5)),
                   v3));
  return v4;
}

// File Line: 254
// RVA: 0xC72C80
hkSimdFloat32 *__fastcall hkVectorNf::dot(hkVectorNf *this, hkSimdFloat32 *result, hkVectorNf *rhs)
{
  hkVector4f *v3; // r10
  signed __int64 v4; // rcx
  __m128 v5; // xmm2
  signed __int64 v6; // rax
  signed __int64 v7; // rcx
  __m128 v8; // xmm0
  hkSimdFloat32 *v9; // rax
  __m128 v10; // xmm1

  v3 = this->m_elements;
  v4 = (this->m_size + 3) >> 2;
  v5 = _mm_mul_ps(rhs->m_elements->m_quad, v3->m_quad);
  if ( v4 > 1 )
  {
    v6 = (signed __int64)&v3[1];
    v7 = v4 - 1;
    do
    {
      v8 = *(__m128 *)((char *)rhs->m_elements - (char *)v3 + v6);
      v6 += 16i64;
      v5 = _mm_add_ps(v5, _mm_mul_ps(v8, *(__m128 *)(v6 - 16)));
      --v7;
    }
    while ( v7 );
  }
  v9 = result;
  v10 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
  result->m_real = _mm_add_ps(_mm_shuffle_ps(v10, v10, 177), v10);
  return v9;
}

// File Line: 274
// RVA: 0xC72F80
hkSimdFloat32 *__fastcall hkVectorNf::horizontalAdd(hkVectorNf *this, hkSimdFloat32 *result)
{
  hkVector4f *v2; // r8
  __m128 v3; // xmm0
  int v4; // eax
  __int64 v5; // rcx
  hkSimdFloat32 *v6; // rax
  __m128 v7; // xmm1

  v2 = this->m_elements;
  v3 = 0i64;
  v4 = (this->m_size + 3) >> 2;
  v5 = v4;
  if ( v4 > 0 )
  {
    do
    {
      v3 = _mm_add_ps(v3, v2->m_quad);
      ++v2;
      --v5;
    }
    while ( v5 );
  }
  v6 = result;
  v7 = _mm_add_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  result->m_real = _mm_add_ps(_mm_shuffle_ps(v7, v7, 177), v7);
  return v6;
}

// File Line: 287
// RVA: 0xC72CF0
hkBool *__fastcall hkVectorNf::equals(hkVectorNf *this, hkBool *result, hkVectorNf *rhs, float epsilon)
{
  int v4; // er9
  hkVector4f *v5; // r10
  signed __int64 v6; // rax
  __m128 v7; // xmm1
  int v8; // er9
  char *v9; // r11

  v4 = this->m_size;
  if ( v4 > 0 && v4 == rhs->m_size )
  {
    v5 = this->m_elements;
    v6 = 0i64;
    v7 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
    v8 = (v4 + 3) >> 2;
    if ( v8 <= 0 )
    {
LABEL_7:
      result->m_bool = 1;
      return result;
    }
    v9 = (char *)((char *)rhs->m_elements - (char *)v5);
    while ( _mm_movemask_ps(
              _mm_cmpltps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32(
                            (__m128i)_mm_sub_ps(v5->m_quad, *(__m128 *)((char *)&v5->m_quad + (_QWORD)v9)),
                            1u),
                          1u),
                v7)) == 15 )
    {
      ++v6;
      ++v5;
      if ( v6 >= v8 )
        goto LABEL_7;
    }
  }
  result->m_bool = 0;
  return result;
}

// File Line: 311
// RVA: 0xC72D70
hkBool *__fastcall hkVectorNf::equalsStrided(hkVectorNf *this, hkBool *result, const float *ele, __int64 size, int stride, float epsilon)
{
  hkVector4f *v7; // r11
  __int64 v8; // rcx

  if ( (_DWORD)size != this->m_size )
  {
LABEL_2:
    result->m_bool = 0;
    return result;
  }
  v7 = this->m_elements;
  size = (signed int)size;
  v8 = 0i64;
  if ( (signed int)size > 0i64 )
  {
    while ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v7->m_quad.m128_f32[v8] - *ele)) >> 1) <= epsilon )
    {
      ++v8;
      ele += stride;
      if ( v8 >= size )
        goto LABEL_6;
    }
    goto LABEL_2;
  }
LABEL_6:
  result->m_bool = 1;
  return result;
}

// File Line: 331
// RVA: 0xC730E0
hkBool *__fastcall hkVectorNf::isOk(hkVectorNf *this, hkBool *result)
{
  int v2; // ebx
  hkBool *v3; // r11
  signed __int64 v4; // r8
  int v5; // edx
  hkVector4f *v6; // r9
  hkVector4f *v7; // rdx
  __m128 v8; // xmm1
  hkBool *v9; // rax

  v2 = this->m_size;
  v3 = result;
  v4 = 0i64;
  v5 = (v2 + 3) >> 2;
  if ( v5 <= 0 )
  {
LABEL_5:
    if ( v2 & 3 )
    {
      v7 = &this->m_elements[v5 - 1];
      v8 = hkVector4fComparison_maskToComparison_297[hkVectorNf::s_zeroMask[v2 & 3]];
      v3->m_bool = _mm_movemask_ps(
                     _mm_cmpltps(
                       (__m128)_mm_srli_epi32(
                                 _mm_slli_epi32(
                                   (__m128i)_mm_sub_ps(
                                              _mm_or_ps(_mm_and_ps(v7->m_quad, v8), _mm_andnot_ps(v8, aabbOut.m_quad)),
                                              v7->m_quad),
                                   1u),
                                 1u),
                       _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) == 15;
    }
    else
    {
      v3->m_bool = 1;
    }
    v9 = v3;
  }
  else
  {
    v6 = this->m_elements;
    while ( !_mm_movemask_ps(_mm_cmpunordps(v6->m_quad, v6->m_quad)) )
    {
      ++v4;
      ++v6;
      if ( v4 >= v5 )
        goto LABEL_5;
    }
    v3->m_bool = 0;
    v9 = v3;
  }
  return v9;
}

// File Line: 361
// RVA: 0xC733F0
void __fastcall hkVectorNf::alias(hkVectorNf *this, hkVector4f *vecs, int size)
{
  int v3; // esi
  hkVector4f *v4; // rbp
  hkVectorNf *v5; // rdi
  hkVector4f *v6; // rbx
  hkMemoryAllocator **v7; // rax

  v3 = size;
  v4 = vecs;
  v5 = this;
  if ( this->m_flags < 0 )
  {
    v6 = this->m_elements;
    v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(v7[11], v6);
  }
  v5->m_elements = v4;
  v5->m_size = v3;
  v5->m_flags = 0;
}

// File Line: 383
// RVA: 0xC73460
void __fastcall hkVectorNf::unalias(hkVectorNf *this)
{
  hkVectorNf *v1; // rdi
  int v2; // ebx
  hkVector4f *v3; // rsi
  int v4; // ebx
  hkMemoryAllocator **v5; // rax
  hkVector4f *v6; // rax
  __int64 v7; // rdx
  hkVector4f *v8; // rcx
  signed __int64 v9; // rsi
  hkVector4f v10; // xmm0

  v1 = this;
  if ( this->m_flags >= 0 )
  {
    v2 = this->m_size;
    if ( v2 > 0 )
    {
      v3 = this->m_elements;
      v4 = (v2 + 3) >> 2;
      v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkVector4f *)hkMemoryRouter::alignedAlloc(v5[11], 16 * v4, 16);
      v7 = v4;
      if ( v4 > 0 )
      {
        v8 = v6;
        v9 = (char *)v3 - (char *)v6;
        do
        {
          v10.m_quad = *(__m128 *)((char *)v8 + v9);
          ++v8;
          v8[-1] = (hkVector4f)v10.m_quad;
          --v7;
        }
        while ( v7 );
      }
      v1->m_flags |= 0x80000000;
      v1->m_elements = v6;
    }
  }
}

// File Line: 407
// RVA: 0xC72B20
void __fastcall hkVectorNf::add(hkVectorNf *this, hkVectorNf *a)
{
  hkVector4f *v2; // rax
  hkVector4f *v3; // r8
  hkVector4f *v4; // rdx
  __m128 v5; // xmm0

  v2 = this->m_elements;
  v3 = a->m_elements;
  v4 = &this->m_elements[(signed __int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v4 )
  {
    do
    {
      v5 = v2->m_quad;
      ++v2;
      ++v3;
      v2[-1].m_quad = _mm_add_ps(v5, v3[-1].m_quad);
    }
    while ( v2 < v4 );
  }
}

// File Line: 421
// RVA: 0xC72B70
void __fastcall hkVectorNf::sub(hkVectorNf *this, hkVectorNf *a)
{
  hkVector4f *v2; // rax
  hkVector4f *v3; // r8
  hkVector4f *v4; // rdx
  __m128 v5; // xmm0

  v2 = this->m_elements;
  v3 = a->m_elements;
  v4 = &this->m_elements[(signed __int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v4 )
  {
    do
    {
      v5 = v2->m_quad;
      ++v2;
      ++v3;
      v2[-1].m_quad = _mm_sub_ps(v5, v3[-1].m_quad);
    }
    while ( v2 < v4 );
  }
}

// File Line: 435
// RVA: 0xC72A00
void __fastcall hkVectorNf::setSub(hkVectorNf *this, hkVectorNf *a, hkVectorNf *b)
{
  hkVectorNf *v3; // rdi
  int v4; // edx
  hkVectorNf *v5; // rsi
  hkVectorNf *v6; // rbx
  hkVector4f *v7; // rax
  __m128 *v8; // rdx
  hkVector4f *v9; // r8
  unsigned __int64 v10; // r9
  __m128 v11; // xmm0

  v3 = a;
  v4 = a->m_size;
  v5 = b;
  v6 = this;
  if ( v4 != this->m_size )
    hkVectorNf::_setSizeAndZeroLast(this, v4);
  v7 = v6->m_elements;
  v8 = &v3->m_elements->m_quad;
  v9 = v5->m_elements;
  v10 = (unsigned __int64)&v6->m_elements[(signed __int64)(v6->m_size + 3) >> 2];
  if ( v6->m_elements < (hkVector4f *)v10 )
  {
    do
    {
      v11 = *v8;
      ++v7;
      ++v8;
      ++v9;
      v7[-1].m_quad = _mm_sub_ps(v11, v9[-1].m_quad);
    }
    while ( (unsigned __int64)v7 < v10 );
  }
}

// File Line: 452
// RVA: 0xC72A90
void __fastcall hkVectorNf::setAdd(hkVectorNf *this, hkVectorNf *a, hkVectorNf *b)
{
  hkVectorNf *v3; // rdi
  int v4; // edx
  hkVectorNf *v5; // rsi
  hkVectorNf *v6; // rbx
  hkVector4f *v7; // rax
  hkVector4f *v8; // rdx
  __m128 *v9; // r8
  unsigned __int64 v10; // r9
  __m128 v11; // xmm0

  v3 = a;
  v4 = a->m_size;
  v5 = b;
  v6 = this;
  if ( v4 != this->m_size )
    hkVectorNf::_setSizeAndZeroLast(this, v4);
  v7 = v6->m_elements;
  v8 = v3->m_elements;
  v9 = &v5->m_elements->m_quad;
  v10 = (unsigned __int64)&v6->m_elements[(signed __int64)(v6->m_size + 3) >> 2];
  if ( v6->m_elements < (hkVector4f *)v10 )
  {
    do
    {
      v11 = *v9;
      ++v7;
      ++v8;
      ++v9;
      v7[-1].m_quad = _mm_add_ps(v11, v8[-1].m_quad);
    }
    while ( (unsigned __int64)v7 < v10 );
  }
}

// File Line: 469
// RVA: 0xC72C40
void __fastcall hkVectorNf::mul(hkVectorNf *this, hkSimdFloat32 *vIn)
{
  hkVector4f *v2; // rax
  hkVector4f *v3; // r8
  __m128 v4; // xmm0

  v2 = this->m_elements;
  v3 = &this->m_elements[(signed __int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v3 )
  {
    do
    {
      v4 = v2->m_quad;
      ++v2;
      v2[-1].m_quad = _mm_mul_ps(v4, vIn->m_real);
    }
    while ( v2 < v3 );
  }
}

// File Line: 480
// RVA: 0xC72BC0
void __fastcall hkVectorNf::setMul(hkVectorNf *this, hkSimdFloat32 *s, hkVectorNf *v)
{
  hkSimdFloat32 *v3; // rbx
  int v4; // edx
  hkVectorNf *v5; // rsi
  hkVectorNf *v6; // rdi
  hkVector4f *v7; // rax
  __m128 *v8; // rcx
  unsigned __int64 v9; // rdx
  __m128 v10; // xmm0

  v3 = s;
  v4 = v->m_size;
  v5 = v;
  v6 = this;
  if ( v4 != this->m_size )
    hkVectorNf::_setSizeAndZeroLast(this, v4);
  v7 = v6->m_elements;
  v8 = &v5->m_elements->m_quad;
  v9 = (unsigned __int64)&v6->m_elements[(signed __int64)(v6->m_size + 3) >> 2];
  if ( v6->m_elements < (hkVector4f *)v9 )
  {
    do
    {
      v10 = *v8;
      ++v7;
      ++v8;
      v7[-1].m_quad = _mm_mul_ps(v10, v3->m_real);
    }
    while ( (unsigned __int64)v7 < v9 );
  }
}

// File Line: 494
// RVA: 0xC72EB0
hkSimdFloat32 *__fastcall hkVectorNf::normalize(hkVectorNf *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rbx
  hkVectorNf *v3; // rdi
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  hkSimdFloat32 *v6; // rax
  int v7; // ecx
  _OWORD *v8; // rsi
  unsigned __int64 v9; // rcx
  hkVector4f *v10; // rdi
  hkSimdFloat32 vIn; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = this;
  hkVectorNf::length(this, result);
  v4 = v2->m_real;
  if ( COERCE_FLOAT(*v2) <= 1.0e-10 )
  {
    v7 = v3->m_size + 3;
    *v3->m_elements = (hkVector4f)_xmm;
    v8 = (_OWORD *)v3->m_elements[1].m_quad.m128_f32;
    v9 = (unsigned __int64)&v3->m_elements[v7 >> 2];
    if ( (unsigned __int64)v8 < v9 )
    {
      v10 = v3->m_elements + 2;
      *v8 = 0i64;
      qmemcpy(v10, v8, 8 * (((v9 - (unsigned __int64)v8 - 1) >> 3) & 0x1FFFFFFFFFFFFFFEi64));
    }
    v6 = v2;
  }
  else
  {
    v5 = _mm_rcp_ps(v4);
    vIn.m_real = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v5)), v5);
    hkVectorNf::mul(v3, &vIn);
    v6 = v2;
  }
  return v6;
}

// File Line: 518
// RVA: 0xC73500
void __fastcall hkVectorNf::calcUnitAxes(hkVectorNf *a, hkVectorNf *b, hkVectorNf *c, hkVectorNf *e1, hkVectorNf *e2)
{
  hkVectorNf *v5; // rdi
  hkVectorNf *v6; // rbx
  hkVectorNf *v7; // rsi
  hkSimdFloat32 *v8; // rax
  hkMemoryAllocator **v9; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-28h]
  hkSimdFloat32 v11; // [rsp+30h] [rbp-18h]

  v5 = c;
  v6 = a;
  v7 = e1;
  hkVectorNf::setSub(e1, b, a);
  hkVectorNf::normalize(v7, &result);
  hkVectorNf::setSub(e2, v5, v6);
  result.m_real = (__m128)0i64;
  v8 = hkVectorNf::dot(v7, &v11, e2);
  hkVectorNf::setMul((hkVectorNf *)&result, v8, v7);
  hkVectorNf::sub(e2, (hkVectorNf *)&result);
  hkVectorNf::normalize(e2, &v11);
  if ( result.m_real.m128_i32[3] < 0 )
  {
    v9 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(v9[11], (void *)result.m_real.m128_u64[0]);
  }
}

// File Line: 535
// RVA: 0xC735D0
hkSimdFloat32 *__fastcall hkVectorNf::calcPlaneDistanceSquared(hkSimdFloat32 *result, hkVectorNf *p, hkVectorNf *e1, hkVectorNf *e2, hkVectorNf *planePoint)
{
  hkVectorNf *v5; // rbx
  hkSimdFloat32 *v6; // rsi
  hkVectorNf *v7; // rdi
  hkSimdFloat32 *v8; // rax
  bool v9; // zf
  hkMemoryAllocator **v10; // rax
  hkVectorNf v12; // [rsp+20h] [rbp-48h]
  hkSimdFloat32 resulta; // [rsp+30h] [rbp-38h]
  hkSimdFloat32 v14; // [rsp+40h] [rbp-28h]
  hkSimdFloat32 v15; // [rsp+50h] [rbp-18h]

  v5 = e1;
  v6 = result;
  v7 = e2;
  v12.m_elements = 0i64;
  *(_QWORD *)&v12.m_size = 0i64;
  hkVectorNf::setSub(&v12, p, planePoint);
  hkVectorNf::dot(&v12, &resulta, v5);
  hkVectorNf::dot(&v12, &v14, v7);
  v8 = hkVectorNf::lengthSquared(&v12, &v15);
  v9 = v12.m_flags >= 0;
  v6->m_real = _mm_sub_ps(
                 _mm_sub_ps(v8->m_real, _mm_mul_ps(resulta.m_real, resulta.m_real)),
                 _mm_mul_ps(v14.m_real, v14.m_real));
  if ( !v9 )
  {
    v10 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(v10[11], v12.m_elements);
  }
  return v6;
}

