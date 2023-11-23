// File Line: 23
// RVA: 0xC731D0
void __fastcall hkVectorNf::hkVectorNf(hkVectorNf *this, int size)
{
  int v3; // ebx
  hkMemoryAllocator **Value; // rax
  hkVector4f *v5; // rax

  this->m_size = size;
  this->m_flags = 0;
  if ( size > 0 )
  {
    v3 = (size + 3) >> 2;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkVector4f *)hkMemoryRouter::alignedAlloc(Value[11], 16 * v3, 16);
    this->m_elements = v5;
    v5[v3 - 1] = 0i64;
    this->m_flags = 0x80000000;
  }
}

// File Line: 41
// RVA: 0xC73240
void __fastcall hkVectorNf::hkVectorNf(hkVectorNf *this, const float *v, int size)
{
  int v6; // ebx
  hkMemoryAllocator **Value; // rax
  hkVector4f *v8; // rax

  this->m_size = size;
  this->m_flags = 0;
  if ( size > 0 )
  {
    v6 = (size + 3) >> 2;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkVector4f *)hkMemoryRouter::alignedAlloc(Value[11], 16 * v6, 16);
    this->m_elements = v8;
    hkVectorNf::_setValues(v8, v, size);
    this->m_flags = 0x80000000;
  }
}

// File Line: 56
// RVA: 0xC72FD0
void __fastcall hkVectorNf::set(hkVectorNf *this, const float *v, int size)
{
  hkVectorNf::_setSize(this, size);
  if ( size > 0 )
    hkVectorNf::_setValues(this->m_elements, v, size);
}

// File Line: 65
// RVA: 0xC736A0
void __fastcall hkVectorNf::_setValues(hkVector4f *dst, const float *v, int size)
{
  hkVector4f *v3; // r9
  signed __int64 v4; // rdx
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm0

  v3 = &dst[(__int64)(size + 3) >> 2];
  if ( ((unsigned __int8)v & 0xF) != 0 )
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
      v5.m_quad = *(__m128 *)((char *)dst++ + v4);
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
  hkVector4f *v4; // rdx

  v2 = size;
  hkVectorNf::_setSize(this, size);
  if ( (v2 & 3) != 0 )
  {
    v4 = &this->m_elements[((this->m_size + 3) >> 2) - 1];
    v4->m_quad = _mm_and_ps(hkVector4fComparison_maskToComparison_297[hkVectorNf::s_zeroMask[v2 & 3]], v4->m_quad);
  }
}

// File Line: 107
// RVA: 0xC73020
void __fastcall hkVectorNf::setSizeAndZero(hkVectorNf *this, int size)
{
  hkVectorNf::_setSize(this, size);
  hkVectorNf::setZero(this);
}

// File Line: 113
// RVA: 0xC73050
void __fastcall hkVectorNf::setZero(hkVectorNf *this)
{
  hkVector4f *m_elements; // rax
  hkVector4f *v2; // rdx

  m_elements = this->m_elements;
  v2 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements != v2 )
  {
    do
      *m_elements++ = 0i64;
    while ( m_elements != v2 );
  }
}

// File Line: 127
// RVA: 0xC73090
void __fastcall hkVectorNf::negate(hkVectorNf *this)
{
  hkVector4f *m_elements; // rax
  hkVector4f *v2; // rdx
  __m128 v3; // xmm1
  __m128 m_quad; // xmm0

  m_elements = this->m_elements;
  v2 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements != v2 )
  {
    v3 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      m_quad = m_elements->m_quad;
      ++m_elements;
      m_elements[-1].m_quad = _mm_xor_ps(m_quad, v3);
    }
    while ( m_elements != v2 );
  }
}

// File Line: 141
// RVA: 0xC73730
void __fastcall hkVectorNf::_setSize(hkVectorNf *this, int size)
{
  int v3; // esi
  int v5; // eax
  hkVector4f *m_elements; // rbx
  hkMemoryAllocator **Value; // rax
  hkMemoryAllocator **v8; // rax
  hkVector4f *v9; // rax

  v3 = (size + 3) >> 2;
  v5 = (this->m_size + 3) >> 2;
  if ( v5 == v3 )
    goto LABEL_4;
  if ( this->m_flags < 0 )
  {
    if ( v5 )
    {
      m_elements = this->m_elements;
      Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(Value[11], (int *)m_elements);
      this->m_flags = 0;
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
  this->m_flags = 0x80000000;
  this->m_elements = v9;
LABEL_9:
  this->m_size = size;
}

// File Line: 191
// RVA: 0xC732D0
void __fastcall hkVectorNf::hkVectorNf(hkVectorNf *this, hkVectorNf *rhs)
{
  int m_size; // eax
  int v4; // ebx
  int v6; // ebx
  hkMemoryAllocator **Value; // rax
  hkVector4f *v8; // rax
  hkVector4f *m_elements; // rdx
  hkVector4f *i; // r8
  hkVector4f *v11; // rcx

  m_size = rhs->m_size;
  this->m_flags = 0;
  this->m_size = m_size;
  v4 = rhs->m_size;
  if ( v4 )
  {
    v6 = (v4 + 3) >> 2;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkVector4f *)hkMemoryRouter::alignedAlloc(Value[11], 16 * v6, 16);
    this->m_elements = v8;
    m_elements = rhs->m_elements;
    for ( i = &v8[v6]; v8 != i; ++m_elements )
    {
      v11 = v8++;
      *v11 = (hkVector4f)m_elements->m_quad;
    }
    this->m_flags = 0x80000000;
  }
}

// File Line: 213
// RVA: 0xC73380
void __fastcall hkVectorNf::operator=(hkVectorNf *this, hkVectorNf *rhs)
{
  hkVector4f *m_elements; // rax
  hkVector4f *v5; // rdx
  hkVector4f *v6; // r8
  hkVector4f *v7; // rcx

  hkVectorNf::_setSize(this, rhs->m_size);
  m_elements = this->m_elements;
  v5 = rhs->m_elements;
  v6 = &this->m_elements[(__int64)(rhs->m_size + 3) >> 2];
  if ( this->m_elements != v6 )
  {
    do
    {
      v7 = m_elements++;
      *v7 = (hkVector4f)v5->m_quad;
      ++v5;
    }
    while ( m_elements != v6 );
  }
}

// File Line: 228
// RVA: 0xC72DE0
hkSimdFloat32 *__fastcall hkVectorNf::lengthSquared(hkVectorNf *this, hkSimdFloat32 *result)
{
  hkVector4f *v2; // r8
  hkVector4f *v3; // rax
  __m128 i; // xmm2
  __m128 m_quad; // xmm0
  hkSimdFloat32 *v6; // rax
  __m128 v7; // xmm1

  v2 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  v3 = this->m_elements + 1;
  for ( i = _mm_mul_ps(this->m_elements->m_quad, this->m_elements->m_quad);
        v3 != v2;
        i = _mm_add_ps(i, _mm_mul_ps(m_quad, m_quad)) )
  {
    m_quad = v3->m_quad;
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
  __m128 m_real; // xmm3
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm1
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-18h] BYREF

  m_real = hkVectorNf::lengthSquared(this, &resulta)->m_real;
  v4 = result;
  v5 = _mm_rsqrt_ps(m_real);
  result->m_real = _mm_andnot_ps(
                     _mm_cmple_ps(m_real, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(m_real, v5), v5)),
                         _mm_mul_ps(*(__m128 *)_xmm, v5)),
                       m_real));
  return v4;
}

// File Line: 254
// RVA: 0xC72C80
hkSimdFloat32 *__fastcall hkVectorNf::dot(hkVectorNf *this, hkSimdFloat32 *result, hkVectorNf *rhs)
{
  hkVector4f *m_elements; // r10
  __int64 v4; // rcx
  __m128 v5; // xmm2
  hkVector4f *v6; // rax
  __int64 v7; // rcx
  __m128 v8; // xmm0
  hkSimdFloat32 *v9; // rax
  __m128 v10; // xmm1

  m_elements = this->m_elements;
  v4 = (this->m_size + 3) >> 2;
  v5 = _mm_mul_ps(rhs->m_elements->m_quad, m_elements->m_quad);
  if ( v4 > 1 )
  {
    v6 = m_elements + 1;
    v7 = v4 - 1;
    do
    {
      v8 = *(__m128 *)((char *)&v6->m_quad + (char *)rhs->m_elements - (char *)m_elements);
      ++v6;
      v5 = _mm_add_ps(v5, _mm_mul_ps(v8, v6[-1].m_quad));
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
  hkVector4f *m_elements; // r8
  __m128 v3; // xmm0
  int v4; // eax
  __int64 v5; // rcx
  hkSimdFloat32 *v6; // rax
  __m128 v7; // xmm1

  m_elements = this->m_elements;
  v3 = 0i64;
  v4 = (this->m_size + 3) >> 2;
  v5 = v4;
  if ( v4 > 0 )
  {
    do
    {
      v3 = _mm_add_ps(v3, m_elements->m_quad);
      ++m_elements;
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
  int m_size; // r9d
  hkVector4f *m_elements; // r10
  __int64 v6; // rax
  __m128 v7; // xmm1
  int v8; // r9d
  char *v9; // r11

  m_size = this->m_size;
  if ( m_size > 0 && m_size == rhs->m_size )
  {
    m_elements = this->m_elements;
    v6 = 0i64;
    v7 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
    v8 = (m_size + 3) >> 2;
    if ( v8 <= 0 )
    {
LABEL_7:
      result->m_bool = 1;
      return result;
    }
    v9 = (char *)((char *)rhs->m_elements - (char *)m_elements);
    while ( _mm_movemask_ps(
              _mm_cmplt_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32(
                            (__m128i)_mm_sub_ps(
                                       m_elements->m_quad,
                                       *(__m128 *)((char *)&m_elements->m_quad + (_QWORD)v9)),
                            1u),
                          1u),
                v7)) == 15 )
    {
      ++v6;
      ++m_elements;
      if ( v6 >= v8 )
        goto LABEL_7;
    }
  }
  result->m_bool = 0;
  return result;
}

// File Line: 311
// RVA: 0xC72D70
hkBool *__fastcall hkVectorNf::equalsStrided(
        hkVectorNf *this,
        hkBool *result,
        const float *ele,
        int size,
        int stride,
        float epsilon)
{
  hkVector4f *m_elements; // r11
  __int64 v8; // rcx

  if ( size != this->m_size )
  {
LABEL_2:
    result->m_bool = 0;
    return result;
  }
  m_elements = this->m_elements;
  v8 = 0i64;
  if ( size > 0 )
  {
    while ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(m_elements->m_quad.m128_f32[v8] - *ele)) >> 1) <= epsilon )
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
  int m_size; // ebx
  __int64 v4; // r8
  int v5; // edx
  hkVector4f *m_elements; // r9
  hkVector4f *v7; // rdx
  __m128 v8; // xmm1

  m_size = this->m_size;
  v4 = 0i64;
  v5 = (m_size + 3) >> 2;
  if ( v5 <= 0 )
  {
LABEL_5:
    if ( (m_size & 3) != 0 )
    {
      v7 = &this->m_elements[v5 - 1];
      v8 = hkVector4fComparison_maskToComparison_297[hkVectorNf::s_zeroMask[m_size & 3]];
      result->m_bool = _mm_movemask_ps(
                         _mm_cmplt_ps(
                           (__m128)_mm_srli_epi32(
                                     _mm_slli_epi32(
                                       (__m128i)_mm_sub_ps(
                                                  _mm_or_ps(
                                                    _mm_and_ps(v7->m_quad, v8),
                                                    _mm_andnot_ps(v8, aabbOut.m_quad)),
                                                  v7->m_quad),
                                       1u),
                                     1u),
                           _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) == 15;
    }
    else
    {
      result->m_bool = 1;
    }
    return result;
  }
  else
  {
    m_elements = this->m_elements;
    while ( !_mm_movemask_ps(_mm_cmpunord_ps(m_elements->m_quad, m_elements->m_quad)) )
    {
      ++v4;
      ++m_elements;
      if ( v4 >= v5 )
        goto LABEL_5;
    }
    result->m_bool = 0;
    return result;
  }
}

// File Line: 361
// RVA: 0xC733F0
void __fastcall hkVectorNf::alias(hkVectorNf *this, hkVector4f *vecs, int size)
{
  hkVector4f *m_elements; // rbx
  hkMemoryAllocator **Value; // rax

  if ( this->m_flags < 0 )
  {
    m_elements = this->m_elements;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(Value[11], (int *)m_elements);
  }
  this->m_elements = vecs;
  this->m_size = size;
  this->m_flags = 0;
}

// File Line: 383
// RVA: 0xC73460
void __fastcall hkVectorNf::unalias(hkVectorNf *this)
{
  int m_size; // ebx
  hkVector4f *m_elements; // rsi
  int v4; // ebx
  hkMemoryAllocator **Value; // rax
  hkVector4f *v6; // rax
  __int64 v7; // rdx
  hkVector4f *v8; // rcx
  signed __int64 v9; // rsi
  hkVector4f v10; // xmm0

  if ( this->m_flags >= 0 )
  {
    m_size = this->m_size;
    if ( m_size > 0 )
    {
      m_elements = this->m_elements;
      v4 = (m_size + 3) >> 2;
      Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkVector4f *)hkMemoryRouter::alignedAlloc(Value[11], 16 * v4, 16);
      v7 = v4;
      if ( v4 > 0 )
      {
        v8 = v6;
        v9 = (char *)m_elements - (char *)v6;
        do
        {
          v10.m_quad = *(__m128 *)((char *)v8++ + v9);
          v8[-1] = (hkVector4f)v10.m_quad;
          --v7;
        }
        while ( v7 );
      }
      this->m_flags |= 0x80000000;
      this->m_elements = v6;
    }
  }
}

// File Line: 407
// RVA: 0xC72B20
void __fastcall hkVectorNf::add(hkVectorNf *this, hkVectorNf *a)
{
  hkVector4f *m_elements; // rax
  hkVector4f *v3; // r8
  hkVector4f *v4; // rdx
  __m128 m_quad; // xmm0

  m_elements = this->m_elements;
  v3 = a->m_elements;
  v4 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v4 )
  {
    do
    {
      m_quad = m_elements->m_quad;
      ++m_elements;
      ++v3;
      m_elements[-1].m_quad = _mm_add_ps(m_quad, v3[-1].m_quad);
    }
    while ( m_elements < v4 );
  }
}

// File Line: 421
// RVA: 0xC72B70
void __fastcall hkVectorNf::sub(hkVectorNf *this, hkVectorNf *a)
{
  hkVector4f *m_elements; // rax
  hkVector4f *v3; // r8
  hkVector4f *v4; // rdx
  __m128 m_quad; // xmm0

  m_elements = this->m_elements;
  v3 = a->m_elements;
  v4 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v4 )
  {
    do
    {
      m_quad = m_elements->m_quad;
      ++m_elements;
      ++v3;
      m_elements[-1].m_quad = _mm_sub_ps(m_quad, v3[-1].m_quad);
    }
    while ( m_elements < v4 );
  }
}

// File Line: 435
// RVA: 0xC72A00
void __fastcall hkVectorNf::setSub(hkVectorNf *this, hkVectorNf *a, hkVectorNf *b)
{
  int m_size; // edx
  hkVector4f *m_elements; // rax
  hkVector4f *v8; // rdx
  hkVector4f *v9; // r8
  hkVector4f *v10; // r9
  __m128 m_quad; // xmm0

  m_size = a->m_size;
  if ( m_size != this->m_size )
    hkVectorNf::_setSizeAndZeroLast(this, m_size);
  m_elements = this->m_elements;
  v8 = a->m_elements;
  v9 = b->m_elements;
  v10 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v10 )
  {
    do
    {
      m_quad = v8->m_quad;
      ++m_elements;
      ++v8;
      ++v9;
      m_elements[-1].m_quad = _mm_sub_ps(m_quad, v9[-1].m_quad);
    }
    while ( m_elements < v10 );
  }
}

// File Line: 452
// RVA: 0xC72A90
void __fastcall hkVectorNf::setAdd(hkVectorNf *this, hkVectorNf *a, hkVectorNf *b)
{
  int m_size; // edx
  hkVector4f *m_elements; // rax
  hkVector4f *v8; // rdx
  hkVector4f *v9; // r8
  hkVector4f *v10; // r9
  __m128 m_quad; // xmm0

  m_size = a->m_size;
  if ( m_size != this->m_size )
    hkVectorNf::_setSizeAndZeroLast(this, m_size);
  m_elements = this->m_elements;
  v8 = a->m_elements;
  v9 = b->m_elements;
  v10 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v10 )
  {
    do
    {
      m_quad = v9->m_quad;
      ++m_elements;
      ++v8;
      ++v9;
      m_elements[-1].m_quad = _mm_add_ps(m_quad, v8[-1].m_quad);
    }
    while ( m_elements < v10 );
  }
}

// File Line: 469
// RVA: 0xC72C40
void __fastcall hkVectorNf::mul(hkVectorNf *this, hkSimdFloat32 *vIn)
{
  hkVector4f *m_elements; // rax
  hkVector4f *v3; // r8
  __m128 m_quad; // xmm0

  m_elements = this->m_elements;
  v3 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v3 )
  {
    do
    {
      m_quad = m_elements->m_quad;
      ++m_elements;
      m_elements[-1].m_quad = _mm_mul_ps(m_quad, vIn->m_real);
    }
    while ( m_elements < v3 );
  }
}

// File Line: 480
// RVA: 0xC72BC0
void __fastcall hkVectorNf::setMul(hkVectorNf *this, hkSimdFloat32 *s, hkVectorNf *v)
{
  int m_size; // edx
  hkVector4f *m_elements; // rax
  hkVector4f *v8; // rcx
  hkVector4f *v9; // rdx
  __m128 m_quad; // xmm0

  m_size = v->m_size;
  if ( m_size != this->m_size )
    hkVectorNf::_setSizeAndZeroLast(this, m_size);
  m_elements = this->m_elements;
  v8 = v->m_elements;
  v9 = &this->m_elements[(__int64)(this->m_size + 3) >> 2];
  if ( this->m_elements < v9 )
  {
    do
    {
      m_quad = v8->m_quad;
      ++m_elements;
      ++v8;
      m_elements[-1].m_quad = _mm_mul_ps(m_quad, s->m_real);
    }
    while ( m_elements < v9 );
  }
}

// File Line: 494
// RVA: 0xC72EB0
hkSimdFloat32 *__fastcall hkVectorNf::normalize(hkVectorNf *this, hkSimdFloat32 *result)
{
  __m128 m_real; // xmm2
  __m128 v5; // xmm1
  int v7; // ecx
  hkVector4f *v8; // rsi
  hkVector4f *v9; // rcx
  hkVector4f *v10; // rdi
  hkSimdFloat32 vIn; // [rsp+20h] [rbp-18h] BYREF

  hkVectorNf::length(this, result);
  m_real = result->m_real;
  if ( COERCE_FLOAT(*result) <= 1.0e-10 )
  {
    v7 = this->m_size + 3;
    *this->m_elements = (hkVector4f)_xmm;
    v8 = this->m_elements + 1;
    v9 = &this->m_elements[v7 >> 2];
    if ( v8 < v9 )
    {
      v10 = this->m_elements + 2;
      *v8 = 0i64;
      qmemcpy(v10, v8, 8 * (((unsigned __int64)((char *)v9 - (char *)v8 - 1) >> 3) & 0x1FFFFFFFFFFFFFFEi64));
    }
    return result;
  }
  else
  {
    v5 = _mm_rcp_ps(m_real);
    vIn.m_real = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_real, v5)), v5);
    hkVectorNf::mul(this, &vIn);
    return result;
  }
}

// File Line: 518
// RVA: 0xC73500
void __fastcall hkVectorNf::calcUnitAxes(hkVectorNf *a, hkVectorNf *b, hkVectorNf *c, hkVectorNf *e1, hkVectorNf *e2)
{
  hkSimdFloat32 *v8; // rax
  hkMemoryAllocator **Value; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-28h] BYREF
  hkSimdFloat32 v11; // [rsp+30h] [rbp-18h] BYREF

  hkVectorNf::setSub(e1, b, a);
  hkVectorNf::normalize(e1, &result);
  hkVectorNf::setSub(e2, c, a);
  result.m_real = (__m128)0i64;
  v8 = hkVectorNf::dot(e1, &v11, e2);
  hkVectorNf::setMul((hkVectorNf *)&result, v8, e1);
  hkVectorNf::sub(e2, (hkVectorNf *)&result);
  hkVectorNf::normalize(e2, &v11);
  if ( result.m_real.m128_i32[3] < 0 )
  {
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(Value[11], (int *)result.m_real.m128_u64[0]);
  }
}

// File Line: 535
// RVA: 0xC735D0
hkSimdFloat32 *__fastcall hkVectorNf::calcPlaneDistanceSquared(
        hkSimdFloat32 *result,
        hkVectorNf *p,
        hkVectorNf *e1,
        hkVectorNf *e2,
        hkVectorNf *planePoint)
{
  hkSimdFloat32 *v8; // rax
  bool v9; // zf
  hkMemoryAllocator **Value; // rax
  hkVectorNf v12; // [rsp+20h] [rbp-48h] BYREF
  hkSimdFloat32 resulta; // [rsp+30h] [rbp-38h] BYREF
  hkSimdFloat32 v14; // [rsp+40h] [rbp-28h] BYREF
  hkSimdFloat32 v15; // [rsp+50h] [rbp-18h] BYREF

  v12.m_elements = 0i64;
  *(_QWORD *)&v12.m_size = 0i64;
  hkVectorNf::setSub(&v12, p, planePoint);
  hkVectorNf::dot(&v12, &resulta, e1);
  hkVectorNf::dot(&v12, &v14, e2);
  v8 = hkVectorNf::lengthSquared(&v12, &v15);
  v9 = v12.m_flags >= 0;
  result->m_real = _mm_sub_ps(
                     _mm_sub_ps(v8->m_real, _mm_mul_ps(resulta.m_real, resulta.m_real)),
                     _mm_mul_ps(v14.m_real, v14.m_real));
  if ( !v9 )
  {
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(Value[11], (int *)v12.m_elements);
  }
  return result;
}

