// File Line: 22
// RVA: 0xD0ECB0
void __fastcall hkpMultiRayShape::hkpMultiRayShape(hkpMultiRayShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpMultiRayShape *v2; // rbx

  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMultiRayShape::`vftable;
  v2->m_type.m_storage = 33;
}

// File Line: 30
// RVA: 0xD0EAB0
void __fastcall hkpMultiRayShape::hkpMultiRayShape(hkpMultiRayShape *this, hkpMultiRayShape::Ray *Rays, int nRays, float rayPenetrationDistance)
{
  hkpMultiRayShape *v4; // rbx
  __int64 v5; // r14
  int v6; // esi
  int v7; // er9
  int v8; // eax
  hkpMultiRayShape::Ray *v9; // rbp
  int v10; // eax
  signed __int64 v11; // rax
  int v12; // esi
  char *v13; // rbp
  __m128 v14; // xmm0
  __m128 v15; // xmm7
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  int v22; // [rsp+B0h] [rbp+18h]

  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1057;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiRayShape::`vftable;
  this->m_userData = 0i64;
  this->m_rays.m_data = 0i64;
  this->m_rays.m_size = 0;
  this->m_rays.m_capacityAndFlags = 2147483648;
  this->m_rayPenetrationDistance = rayPenetrationDistance;
  v5 = this->m_rays.m_size;
  v6 = nRays;
  v7 = v5 + nRays;
  v8 = this->m_rays.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = Rays;
  if ( v8 >= (signed int)v5 + nRays )
  {
    v22 = 0;
  }
  else
  {
    v10 = 2 * v8;
    if ( v7 < v10 )
      v7 = v10;
    hkArrayUtil::_reserve(
      (hkResult *)&v22,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_rays,
      v7,
      32);
  }
  v4->m_rays.m_size += v6;
  v11 = (signed __int64)&v4->m_rays.m_data[v5];
  v12 = v6 - 1;
  if ( v12 >= 0 )
  {
    v13 = (char *)v9 - v11;
    do
    {
      v14 = *(__m128 *)&v13[v11];
      v11 += 32i64;
      --v12;
      *(__m128 *)(v11 - 32) = v14;
      v15 = *(__m128 *)&v13[v11 - 16];
      *(__m128 *)(v11 - 16) = v15;
      v16 = _mm_sub_ps(v15, v14);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      *(__m128 *)(v11 - 32) = _mm_shuffle_ps(
                                v14,
                                _mm_unpackhi_ps(
                                  v14,
                                  _mm_andnot_ps(
                                    _mm_cmpleps(v18, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v19)),
                                      v18))),
                                196);
      v20 = v18;
      v21 = _mm_rsqrt_ps(v20);
      *(__m128 *)(v11 - 16) = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v20, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v21))),
                                    v16),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(v4->m_rayPenetrationDistance),
                                    (__m128)LODWORD(v4->m_rayPenetrationDistance),
                                    0)),
                                *(__m128 *)(v11 - 16));
    }
    while ( v12 >= 0 );
  }
}

// File Line: 50
// RVA: 0xD0EE90
void __fastcall hkpMultiRayShape::castRayWithCollector(hkpMultiRayShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  ;
}

// File Line: 54
// RVA: 0xD0EE80
hkBool *__fastcall hkpMultiRayShape::castRay(hkpMultiRayShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  result->m_bool = 0;
  return result;
}

// File Line: 60
// RVA: 0xD0ECE0
void __fastcall hkpMultiRayShape::getAabb(hkpMultiRayShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  int v4; // ebx
  char *v5; // r8
  hkAabb *v6; // rbp
  hkTransformf *v7; // rsi
  hkpMultiRayShape *v8; // rdi
  int v9; // er9
  hkpMultiRayShape::Ray *v10; // rcx
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  int v15; // eax
  __int64 v16; // rdx
  signed __int64 v17; // rax
  __m128 *v18; // r9
  __m128 *v19; // r8
  __m128 v20; // xmm1
  __int64 v21; // rcx
  char *v22; // rdx
  __m128 *v23; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  int v28; // er8
  char *array; // [rsp+30h] [rbp-238h]
  unsigned int v30; // [rsp+38h] [rbp-230h]
  int v31; // [rsp+3Ch] [rbp-22Ch]
  char v32; // [rsp+50h] [rbp-218h]
  __int64 v33; // [rsp+270h] [rbp+8h]

  v4 = this->m_rays.m_size;
  v5 = &v32;
  v6 = out;
  v7 = localToWorld;
  v8 = this;
  array = &v32;
  v30 = 0;
  v31 = -2147483632;
  if ( v4 > 16 )
  {
    v9 = v4;
    if ( v4 < 32 )
      v9 = 32;
    hkArrayUtil::_reserve(
      (hkResult *)&v33,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v9,
      32);
    v5 = array;
  }
  v10 = v8->m_rays.m_data;
  v11 = v7->m_rotation.m_col0.m_quad;
  v12 = v7->m_rotation.m_col1.m_quad;
  v13 = v7->m_rotation.m_col2.m_quad;
  v14 = v7->m_translation.m_quad;
  v15 = 2 * v8->m_rays.m_size - 1;
  v30 = v4;
  v16 = v15;
  v17 = 2i64 * v15;
  v18 = (__m128 *)&v5[8 * v17];
  v19 = (__m128 *)((char *)&v10->m_start.m_quad + 8 * v17);
  do
  {
    v20 = *v19;
    --v18;
    --v19;
    --v16;
    v18[1] = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v12), _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v11)),
                 _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v13)),
               v14);
  }
  while ( v16 >= 0 );
  v21 = v30;
  v22 = array;
  v23 = (__m128 *)array;
  v24 = _mm_shuffle_ps((__m128)xmmword_141A712A0, _mm_unpackhi_ps((__m128)xmmword_141A712A0, (__m128)0i64), 196);
  v25 = _mm_shuffle_ps((__m128)xmmword_141A712F0, _mm_unpackhi_ps((__m128)xmmword_141A712F0, (__m128)0i64), 196);
  if ( (signed int)v30 > 0 )
  {
    do
    {
      v26 = _mm_min_ps(v24, v23[1]);
      v27 = _mm_max_ps(v25, v23[1]);
      v23 += 2;
      v24 = _mm_min_ps(v26, v23[-2]);
      v25 = _mm_max_ps(v27, v23[-2]);
      --v21;
    }
    while ( v21 );
  }
  v28 = v31;
  v6->m_min.m_quad = v24;
  v6->m_max.m_quad = v25;
  v30 = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22,
      32 * v28);
}

