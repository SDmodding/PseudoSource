// File Line: 24
// RVA: 0xCECF60
void __fastcall hkpShape::hkpShape(hkpShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShapeBase::hkpShapeBase((hkpShapeBase *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpShape::`vftable';
  if ( v3 )
    v2->m_type.m_storage = 34;
}

// File Line: 32
// RVA: 0xCECFA0
float __fastcall hkpShape::getMaximumProjection(hkpShape *this, hkVector4f *direction, __int64 a3)
{
  hkBaseObjectVtbl *v3; // rax
  hkVector4f *v4; // rbx
  __m128 v5; // xmm5
  __m128 v7; // [rsp+20h] [rbp-68h]
  __m128 v8; // [rsp+30h] [rbp-58h]
  __m128 v9; // [rsp+40h] [rbp-48h]
  __m128 v10; // [rsp+50h] [rbp-38h]
  __m128 v11; // [rsp+60h] [rbp-28h]
  __int128 v12; // [rsp+70h] [rbp-18h]

  v3 = this->vfptr;
  v4 = direction;
  v9 = transform.m_quad;
  v10 = ::direction.m_quad;
  v11 = stru_141A71280.m_quad;
  v12 = 0i64;
  ((void (__fastcall *)(hkpShape *, __m128 *, __int64, __m128 *))v3[2].__vecDelDtor)(this, &v9, a3, &v7);
  v5 = _mm_mul_ps(
         _mm_add_ps(
           _mm_xor_ps(
             _mm_mul_ps(_mm_sub_ps(v8, v7), (__m128)xmmword_141A711B0),
             (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)v4), 0x1Fu), 0x1Fu)),
           _mm_mul_ps(_mm_add_ps(v7, v8), (__m128)xmmword_141A711B0)),
         v4->m_quad);
  return (float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
       + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170));
}

// File Line: 50
// RVA: 0xCED050
signed __int64 __fastcall hkpShape::calcSizeForSpu(hkpShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  return 0xFFFFFFFFi64;
}

// File Line: 58
// RVA: 0xCED060
hkVector4fComparison *__fastcall hkpShape::castRayBundle(hkpShape *this, hkVector4fComparison *result, hkpShapeRayBundleCastInput *input, hkpShapeRayBundleCastOutput *output, hkVector4fComparison *mask)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  hkVector4fComparison *v7; // r12
  int v8; // ebp
  hkpShapeRayBundleCastOutput *v9; // rsi
  hkVector4fComparison *v10; // r13
  hkpShape *v11; // r15
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  signed int v14; // ebx
  __int64 v15; // rdi
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  signed __int64 v20; // r14
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __int128 v31; // xmm1
  hkBaseObjectVtbl *v32; // rax
  hkVector4fComparison *v33; // rax
  __int128 v34; // [rsp+20h] [rbp-E8h]
  __int128 v35; // [rsp+30h] [rbp-D8h]
  unsigned int v36; // [rsp+40h] [rbp-C8h]
  hkpRayShapeCollectionFilter *v37; // [rsp+48h] [rbp-C0h]
  __int64 v38; // [rsp+50h] [rbp-B8h]
  __int64 v39; // [rsp+58h] [rbp-B0h]
  __m128 v40; // [rsp+60h] [rbp-A8h]
  __m128 v41; // [rsp+70h] [rbp-98h]
  __m128 v42; // [rsp+80h] [rbp-88h]
  __m128 v43; // [rsp+90h] [rbp-78h]
  __m128 v44; // [rsp+A0h] [rbp-68h]
  __m128 v45; // [rsp+B0h] [rbp-58h]
  __m128 v46; // [rsp+C0h] [rbp-48h]
  __m128 v47; // [rsp+D0h] [rbp-38h]
  char v48; // [rsp+118h] [rbp+10h]

  v5 = input->m_from.m_vertices[0].m_quad;
  v6 = input->m_from.m_vertices[2].m_quad;
  v7 = mask;
  v8 = 0;
  v9 = output;
  v10 = result;
  v11 = this;
  v38 = 0i64;
  v12 = v5;
  v13 = v6;
  v39 = 0i64;
  v14 = 1;
  v15 = 0i64;
  v16 = _mm_shuffle_ps(v5, input->m_from.m_vertices[1].m_quad, 238);
  v17 = _mm_shuffle_ps(v6, (__m128)0i64, 238);
  v18 = _mm_shuffle_ps(v12, input->m_from.m_vertices[1].m_quad, 68);
  v19 = _mm_shuffle_ps(v13, (__m128)0i64, 68);
  v20 = 4i64;
  v40 = _mm_shuffle_ps(v18, v19, 136);
  v41 = _mm_shuffle_ps(v18, v19, 221);
  v21 = _mm_shuffle_ps(v16, v17, 136);
  v22 = _mm_shuffle_ps(v16, v17, 221);
  v23 = input->m_to.m_vertices[2].m_quad;
  v42 = v21;
  v43 = v22;
  v24 = input->m_to.m_vertices[0].m_quad;
  v25 = v23;
  v26 = _mm_shuffle_ps(v23, (__m128)0i64, 238);
  v27 = _mm_shuffle_ps(v25, (__m128)0i64, 68);
  v28 = v24;
  v29 = _mm_shuffle_ps(v24, input->m_to.m_vertices[1].m_quad, 238);
  v30 = _mm_shuffle_ps(v28, input->m_to.m_vertices[1].m_quad, 68);
  v45 = _mm_shuffle_ps(v30, v27, 221);
  v44 = _mm_shuffle_ps(v30, v27, 136);
  v47 = _mm_shuffle_ps(v29, v26, 221);
  v46 = _mm_shuffle_ps(v29, v26, 136);
  v36 = input->m_filterInfo;
  v37 = input->m_rayShapeCollectionFilter;
  do
  {
    if ( _mm_movemask_ps(v7->m_mask) & v14 )
    {
      v31 = *(__int128 *)((char *)&v44 + v15);
      v32 = v11->vfptr;
      v34 = *(__int128 *)((char *)&v40 + v15);
      v35 = v31;
      ((void (__fastcall *)(hkpShape *, char *, __int128 *, hkpShapeRayBundleCastOutput *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, hkpRayShapeCollectionFilter *, __int64, __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))v32[2].__first_virtual_table_function__)(
        v11,
        &v48,
        &v34,
        v9,
        v34,
        *((_QWORD *)&v34 + 1),
        v31,
        *((_QWORD *)&v31 + 1),
        *(_QWORD *)&v36,
        v37,
        v38,
        v39,
        v40.m128_u64[0],
        v40.m128_u64[1],
        v41.m128_u64[0],
        v41.m128_u64[1],
        v42.m128_u64[0],
        v42.m128_u64[1],
        v43.m128_u64[0],
        v43.m128_u64[1],
        v44.m128_u64[0],
        v44.m128_u64[1],
        v45.m128_u64[0],
        v45.m128_u64[1],
        v46.m128_u64[0],
        v46.m128_u64[1],
        v47.m128_u64[0],
        v47.m128_u64[1]);
      if ( v48 )
        v8 |= v14;
    }
    v14 = __ROL4__(v14, 1);
    v9 = (hkpShapeRayBundleCastOutput *)((char *)v9 + 80);
    v15 += 16i64;
    --v20;
  }
  while ( v20 );
  v33 = v10;
  *v10 = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_333[4 * v8];
  return v33;
}

