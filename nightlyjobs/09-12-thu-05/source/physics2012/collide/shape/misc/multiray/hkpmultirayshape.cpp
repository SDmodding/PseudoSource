// File Line: 22
// RVA: 0xD0ECB0
void __fastcall hkpMultiRayShape::hkpMultiRayShape(hkpMultiRayShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiRayShape::`vftable;
  this->m_type.m_storage = 33;
}

// File Line: 30
// RVA: 0xD0EAB0
void __fastcall hkpMultiRayShape::hkpMultiRayShape(
        hkpMultiRayShape *this,
        hkpMultiRayShape::Ray *Rays,
        int nRays,
        float rayPenetrationDistance)
{
  __int64 m_size; // r14
  int v7; // r9d
  int v8; // eax
  int v10; // eax
  hkpMultiRayShape::Ray *v11; // rax
  int v12; // esi
  char *v13; // rbp
  __m128 v14; // xmm0
  __m128 v15; // xmm7
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  hkResult v20; // [rsp+B0h] [rbp+18h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1057;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiRayShape::`vftable;
  this->m_userData = 0i64;
  this->m_rays.m_data = 0i64;
  this->m_rays.m_size = 0;
  this->m_rays.m_capacityAndFlags = 0x80000000;
  this->m_rayPenetrationDistance = rayPenetrationDistance;
  m_size = this->m_rays.m_size;
  v7 = m_size + nRays;
  v8 = this->m_rays.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= (int)m_size + nRays )
  {
    v20.m_enum = HK_SUCCESS;
  }
  else
  {
    v10 = 2 * v8;
    if ( v7 < v10 )
      v7 = v10;
    hkArrayUtil::_reserve(&v20, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_rays.m_data, v7, 32);
  }
  this->m_rays.m_size += nRays;
  v11 = &this->m_rays.m_data[m_size];
  v12 = nRays - 1;
  if ( v12 >= 0 )
  {
    v13 = (char *)((char *)Rays - (char *)v11);
    do
    {
      v14 = *(__m128 *)&v13[(_QWORD)v11++];
      --v12;
      v11[-1].m_start.m_quad = v14;
      v15 = *(__m128 *)&v13[(_QWORD)v11 - 16];
      v11[-1].m_end.m_quad = v15;
      v16 = _mm_sub_ps(v15, v14);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v11[-1].m_start.m_quad = _mm_shuffle_ps(
                                 v14,
                                 _mm_unpackhi_ps(
                                   v14,
                                   _mm_andnot_ps(
                                     _mm_cmple_ps(v18, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v19)),
                                       v18))),
                                 196);
      v11[-1].m_end.m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_andnot_ps(
                                     _mm_cmple_ps(v18, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v19))),
                                   v16),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(this->m_rayPenetrationDistance),
                                   (__m128)LODWORD(this->m_rayPenetrationDistance),
                                   0)),
                               v11[-1].m_end.m_quad);
    }
    while ( v12 >= 0 );
  }
}

// File Line: 50
// RVA: 0xD0EE90
void __fastcall hkpMultiRayShape::castRayWithCollector(
        hkpMultiRayShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  ;
}

// File Line: 54
// RVA: 0xD0EE80
hkBool *__fastcall hkpMultiRayShape::castRay(
        hkpMultiRayShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  result->m_bool = 0;
  return result;
}

// File Line: 60
// RVA: 0xD0ECE0
void __fastcall hkpMultiRayShape::getAabb(
        hkpMultiRayShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  int m_size; // ebx
  char *v5; // r8
  int v9; // r9d
  hkpMultiRayShape::Ray *m_data; // rcx
  hkVector4f v11; // xmm3
  hkVector4f v12; // xmm4
  hkVector4f v13; // xmm5
  hkVector4f v14; // xmm6
  int v15; // eax
  __int64 v16; // rdx
  __int64 v17; // rax
  __m128 *v18; // r9
  __m128 *v19; // r8
  __m128 v20; // xmm1
  __int64 v21; // rcx
  char *v22; // rdx
  __m128 *v23; // rax
  hkVector4f v24; // xmm2
  hkVector4f v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  int v28; // r8d
  char *array; // [rsp+30h] [rbp-238h] BYREF
  unsigned int v30; // [rsp+38h] [rbp-230h]
  int v31; // [rsp+3Ch] [rbp-22Ch]
  char v32[528]; // [rsp+50h] [rbp-218h] BYREF
  hkResult v33; // [rsp+270h] [rbp+8h] BYREF

  m_size = this->m_rays.m_size;
  v5 = v32;
  array = v32;
  v30 = 0;
  v31 = -2147483632;
  if ( m_size > 16 )
  {
    v9 = m_size;
    if ( m_size < 32 )
      v9 = 32;
    hkArrayUtil::_reserve(&v33, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v9, 32);
    v5 = array;
  }
  m_data = this->m_rays.m_data;
  v11.m_quad = (__m128)localToWorld->m_rotation.m_col0;
  v12.m_quad = (__m128)localToWorld->m_rotation.m_col1;
  v13.m_quad = (__m128)localToWorld->m_rotation.m_col2;
  v14.m_quad = (__m128)localToWorld->m_translation;
  v15 = 2 * this->m_rays.m_size - 1;
  v30 = m_size;
  v16 = v15;
  v17 = 2i64 * v15;
  v18 = (__m128 *)&v5[8 * v17];
  v19 = (__m128 *)((char *)&m_data->m_start.m_quad + 8 * v17);
  do
  {
    v20 = *v19;
    --v18;
    --v19;
    --v16;
    v18[1] = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v12.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v11.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v13.m_quad)),
               v14.m_quad);
  }
  while ( v16 >= 0 );
  v21 = v30;
  v22 = array;
  v23 = (__m128 *)array;
  v24.m_quad = _mm_shuffle_ps((__m128)xmmword_141A712A0, _mm_unpackhi_ps((__m128)xmmword_141A712A0, (__m128)0i64), 196);
  v25.m_quad = _mm_shuffle_ps((__m128)xmmword_141A712F0, _mm_unpackhi_ps((__m128)xmmword_141A712F0, (__m128)0i64), 196);
  if ( (int)v30 > 0 )
  {
    do
    {
      v26 = _mm_min_ps(v24.m_quad, v23[1]);
      v27 = _mm_max_ps(v25.m_quad, v23[1]);
      v23 += 2;
      v24.m_quad = _mm_min_ps(v26, v23[-2]);
      v25.m_quad = _mm_max_ps(v27, v23[-2]);
      --v21;
    }
    while ( v21 );
  }
  v28 = v31;
  out->m_min = (hkVector4f)v24.m_quad;
  out->m_max = (hkVector4f)v25.m_quad;
  v30 = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v22, 32 * v28);
}

