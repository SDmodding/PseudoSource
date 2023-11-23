// File Line: 24
// RVA: 0xCECF60
void __fastcall hkpShape::hkpShape(hkpShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShapeBase::hkpShapeBase(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpShape::`vftable;
  if ( flag.m_finishing )
    this->m_type.m_storage = 34;
}

// File Line: 32
// RVA: 0xCECFA0
float __fastcall hkpShape::getMaximumProjection(hkpShape *this, const __m128i *direction, __int64 a3)
{
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v5; // xmm5
  __m128 v7; // [rsp+20h] [rbp-68h] BYREF
  __m128 v8; // [rsp+30h] [rbp-58h]
  __int128 v9[4]; // [rsp+40h] [rbp-48h] BYREF

  vfptr = this->vfptr;
  v9[0] = (__int128)transform.m_quad;
  v9[1] = (__int128)::direction.m_quad;
  v9[2] = (__int128)stru_141A71280.m_quad;
  v9[3] = 0i64;
  ((void (__fastcall *)(hkpShape *, __int128 *, __int64, __m128 *))vfptr[2].__vecDelDtor)(this, v9, a3, &v7);
  v5 = _mm_mul_ps(
         _mm_add_ps(
           _mm_xor_ps(
             _mm_mul_ps(_mm_sub_ps(v8, v7), (__m128)xmmword_141A711B0),
             (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128(direction), 0x1Fu), 0x1Fu)),
           _mm_mul_ps(_mm_add_ps(v7, v8), (__m128)xmmword_141A711B0)),
         *(__m128 *)direction);
  return (float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
       + _mm_shuffle_ps(v5, v5, 170).m128_f32[0];
}

// File Line: 50
// RVA: 0xCED050
__int64 __fastcall hkpShape::calcSizeForSpu(
        hkpShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  return 0xFFFFFFFFi64;
}

// File Line: 58
// RVA: 0xCED060
hkVector4fComparison *__fastcall hkpShape::castRayBundle(
        hkpShape *this,
        hkVector4fComparison *result,
        hkpShapeRayBundleCastInput *input,
        hkpShapeRayBundleCastOutput *output,
        hkVector4fComparison *mask)
{
  __m128 m_quad; // xmm4
  __m128 v6; // xmm3
  hkVector4fComparison *v7; // r12
  int v8; // ebp
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  int v14; // ebx
  __int64 v15; // rdi
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __int64 v20; // r14
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm4
  __m128 v29; // xmm0
  __int128 v30; // xmm1
  hkBaseObjectVtbl *vfptr; // rax
  hkVector4fComparison *v32; // rax
  __int128 v33[2]; // [rsp+20h] [rbp-E8h] BYREF
  unsigned int m_filterInfo; // [rsp+40h] [rbp-C8h]
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // [rsp+48h] [rbp-C0h]
  __int64 v36; // [rsp+50h] [rbp-B8h]
  __int64 v37; // [rsp+58h] [rbp-B0h]
  __int128 v38[4]; // [rsp+60h] [rbp-A8h]
  __m128 v39[4]; // [rsp+A0h] [rbp-68h]
  char v40; // [rsp+118h] [rbp+10h] BYREF

  m_quad = input->m_from.m_vertices[0].m_quad;
  v6 = input->m_from.m_vertices[2].m_quad;
  v7 = mask;
  v8 = 0;
  v36 = 0i64;
  v12 = m_quad;
  v13 = v6;
  v37 = 0i64;
  v14 = 1;
  v15 = 0i64;
  v16 = _mm_shuffle_ps(m_quad, input->m_from.m_vertices[1].m_quad, 238);
  v17 = _mm_shuffle_ps(v6, (__m128)0i64, 238);
  v18 = _mm_shuffle_ps(v12, input->m_from.m_vertices[1].m_quad, 68);
  v19 = _mm_shuffle_ps(v13, (__m128)0i64, 68);
  v20 = 4i64;
  v38[0] = (__int128)_mm_shuffle_ps(v18, v19, 136);
  v38[1] = (__int128)_mm_shuffle_ps(v18, v19, 221);
  v21 = _mm_shuffle_ps(v16, v17, 136);
  v22 = _mm_shuffle_ps(v16, v17, 221);
  v23 = input->m_to.m_vertices[2].m_quad;
  v38[2] = (__int128)v21;
  v38[3] = (__int128)v22;
  v24 = v23;
  v25 = _mm_shuffle_ps(v23, (__m128)0i64, 238);
  v26 = _mm_shuffle_ps(v24, (__m128)0i64, 68);
  v27 = input->m_to.m_vertices[0].m_quad;
  v28 = _mm_shuffle_ps(v27, input->m_to.m_vertices[1].m_quad, 238);
  v29 = _mm_shuffle_ps(v27, input->m_to.m_vertices[1].m_quad, 68);
  v39[1] = _mm_shuffle_ps(v29, v26, 221);
  v39[0] = _mm_shuffle_ps(v29, v26, 136);
  v39[3] = _mm_shuffle_ps(v28, v25, 221);
  v39[2] = _mm_shuffle_ps(v28, v25, 136);
  m_filterInfo = input->m_filterInfo;
  m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
  do
  {
    if ( (_mm_movemask_ps(v7->m_mask) & v14) != 0 )
    {
      v30 = (__int128)v39[v15];
      vfptr = this->vfptr;
      v33[0] = v38[v15];
      v33[1] = v30;
      ((void (__fastcall *)(hkpShape *, char *, __int128 *, hkpShapeRayBundleCastOutput *))vfptr[2].__first_virtual_table_function__)(
        this,
        &v40,
        v33,
        output);
      if ( v40 )
        v8 |= v14;
    }
    v14 = __ROL4__(v14, 1);
    output = (hkpShapeRayBundleCastOutput *)((char *)output + 80);
    ++v15;
    --v20;
  }
  while ( v20 );
  v32 = result;
  *result = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_333[4 * v8];
  return v32;
}

