// File Line: 173
// RVA: 0x12F9830
void __fastcall hkaiNewFaceCutterUtil::fitToPlanes(
        hkArrayBase<hkVector4f> *referenceVertices,
        hkVector4f *upIn,
        hkVector4f *outputVerticesInOut,
        int numOutputVertices)
{
  int m_size; // ebx
  __m128 m_quad; // xmm9
  __int64 v8; // rsi
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __int64 v24; // rcx
  __m128 v25; // xmm1
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  hkVector4f *m_data; // rax
  __m128 v31; // xmm8
  hkLifoAllocator *Value; // rax
  __m128 *m_cur; // r8
  int v34; // edx
  char *v35; // rcx
  int v36; // r9d
  hkLifoAllocator *v37; // rax
  char *v38; // r9
  int v39; // edx
  char *v40; // rcx
  char *v41; // rax
  int v42; // r14d
  char *v43; // r15
  int v44; // r9d
  __int64 v45; // rdx
  hkVector4f *v46; // rax
  int v47; // r10d
  __int64 v48; // r11
  __m128 v49; // xmm11
  __int64 v50; // rcx
  __int64 v51; // rdx
  __m128 v52; // xmm10
  __m128 v53; // xmm4
  __m128 v54; // xmm6
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm5
  __m128 v59; // xmm5
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm5
  __m128 v65; // xmm1
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  int v68; // edx
  __m128 v69; // xmm4
  int v70; // ecx
  int v71; // edx
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm2
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm2
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  __m128 v85; // xmm2
  __m128 v86; // xmm2
  __m128 v87; // xmm0
  signed int v88; // ebx
  hkLifoAllocator *v89; // rax
  int v90; // r8d
  int v91; // eax
  char *v92; // rdi
  signed int v93; // ebx
  hkLifoAllocator *v94; // rax
  int v95; // r8d
  char *v96; // [rsp+30h] [rbp-79h] BYREF
  int v97; // [rsp+38h] [rbp-71h]
  int v98; // [rsp+3Ch] [rbp-6Dh]
  char *v99; // [rsp+40h] [rbp-69h]
  int v100; // [rsp+48h] [rbp-61h]
  __m128 *array; // [rsp+50h] [rbp-59h] BYREF
  int v102; // [rsp+58h] [rbp-51h]
  int v103; // [rsp+5Ch] [rbp-4Dh]
  void *p; // [rsp+60h] [rbp-49h]
  int v105; // [rsp+68h] [rbp-41h]
  hkResult result; // [rsp+110h] [rbp+67h] BYREF

  m_size = referenceVertices->m_size;
  m_quad = upIn->m_quad;
  v8 = numOutputVertices;
  if ( m_size == 3 )
  {
    v9 = referenceVertices->m_data->m_quad;
    v10 = _mm_sub_ps(referenceVertices->m_data[1].m_quad, v9);
    v11 = _mm_sub_ps(referenceVertices->m_data[2].m_quad, v9);
    v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
    v13 = _mm_shuffle_ps(v12, v12, 201);
    v14 = _mm_mul_ps(v13, v9);
    v15 = _mm_shuffle_ps(
            v13,
            _mm_unpackhi_ps(
              v13,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                  _mm_shuffle_ps(v14, v14, 170)))),
            196);
    v16 = _mm_mul_ps(m_quad, v15);
    v17 = _mm_sub_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170)));
    v18 = _mm_rcp_ps(v17);
    v19 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpeq_ps((__m128)0i64, v17),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18)),
            v15);
    if ( numOutputVertices > 0 )
    {
      do
      {
        v20 = outputVerticesInOut->m_quad;
        ++outputVerticesInOut;
        v21 = _mm_mul_ps(v20, v19);
        v22 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v19), 196);
        v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
        outputVerticesInOut[-1].m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 177), v23), m_quad),
                                           outputVerticesInOut[-1].m_quad);
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v24 = referenceVertices->m_size;
    v25 = 0i64;
    v25.m128_f32[0] = (float)m_size;
    v26 = 0i64;
    v27 = _mm_shuffle_ps(v25, v25, 0);
    v28 = _mm_rcp_ps(v27);
    v29 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v28)), v28);
    if ( m_size > 0 )
    {
      m_data = referenceVertices->m_data;
      do
      {
        v26 = _mm_add_ps(v26, m_data->m_quad);
        ++m_data;
        --v24;
      }
      while ( v24 );
    }
    v31 = _mm_mul_ps(v26, v29);
    v103 = 0x80000000;
    v105 = m_size;
    array = 0i64;
    v102 = 0;
    if ( m_size )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (__m128 *)Value->m_cur;
      v34 = (16 * m_size + 127) & 0xFFFFFF80;
      v35 = (char *)m_cur + v34;
      if ( v34 > Value->m_slabSize || v35 > Value->m_end )
      {
        m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(Value, v34);
        array = m_cur;
      }
      else
      {
        Value->m_cur = v35;
        array = m_cur;
      }
    }
    else
    {
      m_cur = 0i64;
      array = 0i64;
    }
    p = m_cur;
    v103 = m_size | 0x80000000;
    if ( (m_size & 0x3FFFFFFF) < m_size )
    {
      v36 = m_size;
      if ( m_size < 2 * (m_size & 0x3FFFFFFF) )
        v36 = 2 * (m_size & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v36, 16);
      m_cur = array;
    }
    v102 = m_size;
    v96 = 0i64;
    v97 = 0;
    v98 = 0x80000000;
    v100 = m_size;
    if ( m_size )
    {
      v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (char *)v37->m_cur;
      v39 = (16 * m_size + 127) & 0xFFFFFF80;
      v40 = &v38[v39];
      if ( v39 > v37->m_slabSize || v40 > v37->m_end )
      {
        v41 = (char *)hkLifoAllocator::allocateFromNewSlab(v37, v39);
        m_cur = array;
        v38 = v41;
        v96 = v41;
      }
      else
      {
        v37->m_cur = v40;
        m_cur = array;
        v96 = v38;
      }
    }
    else
    {
      v38 = 0i64;
      v96 = 0i64;
    }
    v98 = m_size | 0x80000000;
    v42 = m_size & 0x3FFFFFFF;
    v43 = v38;
    v99 = v38;
    if ( (m_size & 0x3FFFFFFF) < m_size )
    {
      v44 = m_size;
      if ( m_size < 2 * v42 )
        v44 = 2 * v42;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v96, v44, 16);
      m_cur = array;
      v43 = v99;
      v38 = v96;
    }
    v45 = referenceVertices->m_size;
    v46 = referenceVertices->m_data;
    v97 = m_size;
    v47 = m_size;
    v48 = v45;
    v49 = _mm_sub_ps(v46[v45 - 1].m_quad, v31);
    if ( (int)v45 > 0 )
    {
      v50 = 16i64 * ((int)v45 - 1);
      v51 = 0i64;
      v52 = _mm_shuffle_ps(m_quad, m_quad, 201);
      do
      {
        v53 = _mm_shuffle_ps(v49, v49, 201);
        v54 = _mm_sub_ps(referenceVertices->m_data[v51].m_quad, v31);
        v55 = _mm_sub_ps(_mm_mul_ps(v53, m_quad), _mm_mul_ps(v52, v49));
        v56 = _mm_shuffle_ps(v55, v55, 201);
        v57 = _mm_mul_ps(v56, v31);
        v58 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v49), _mm_mul_ps(v53, v54));
        v59 = _mm_shuffle_ps(v58, v58, 201);
        v60 = _mm_shuffle_ps(
                v56,
                _mm_unpackhi_ps(
                  v56,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                      _mm_shuffle_ps(v57, v57, 170)))),
                196);
        v61 = _mm_mul_ps(v60, v31);
        v62 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                _mm_shuffle_ps(v61, v61, 170));
        v63 = _mm_mul_ps(v59, v31);
        *(__m128 *)((char *)m_cur + v50) = _mm_shuffle_ps(v60, _mm_unpackhi_ps(v60, _mm_sub_ps((__m128)0i64, v62)), 196);
        v64 = _mm_shuffle_ps(
                v59,
                _mm_unpackhi_ps(
                  v59,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                      _mm_shuffle_ps(v63, v63, 170)))),
                196);
        v65 = _mm_mul_ps(v64, m_quad);
        v66 = _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                  _mm_shuffle_ps(v65, v65, 170)));
        v67 = _mm_rcp_ps(v66);
        v49 = v54;
        *(__m128 *)&v96[v50] = _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmpeq_ps((__m128)0i64, v66),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v66)), v67)),
                                 v64);
        m_cur = array;
        v50 = v51 * 16;
        ++v51;
        --v48;
      }
      while ( v48 );
      v43 = v99;
      v47 = v97;
      v38 = v96;
    }
    v68 = 0;
    if ( v8 > 0 )
    {
      do
      {
        v69 = outputVerticesInOut->m_quad;
        v70 = v68;
        v71 = v68 + 1;
        v72 = outputVerticesInOut->m_quad;
        if ( v71 == m_size )
          v71 = 0;
        v73 = _mm_mul_ps(m_cur[v71], v69);
        v74 = _mm_shuffle_ps(v73, _mm_unpackhi_ps(v73, m_cur[v71]), 196);
        v75 = _mm_add_ps(_mm_shuffle_ps(v74, v74, 78), v74);
        if ( (float)(_mm_shuffle_ps(v75, v75, 177).m128_f32[0] + v75.m128_f32[0]) >= 0.0 )
        {
          do
          {
            v70 = v71++;
            if ( v71 == m_size )
              v71 = 0;
            v76 = _mm_mul_ps(m_cur[v71], v72);
            v77 = _mm_shuffle_ps(v76, _mm_unpackhi_ps(v76, m_cur[v71]), 196);
            v78 = _mm_add_ps(_mm_shuffle_ps(v77, v77, 78), v77);
          }
          while ( (float)(_mm_shuffle_ps(v78, v78, 177).m128_f32[0] + v78.m128_f32[0]) >= 0.0 );
        }
        v79 = _mm_mul_ps(m_cur[v70], v72);
        v80 = _mm_shuffle_ps(v79, _mm_unpackhi_ps(v79, m_cur[v70]), 196);
        v81 = _mm_add_ps(_mm_shuffle_ps(v80, v80, 78), v80);
        if ( (float)(_mm_shuffle_ps(v81, v81, 177).m128_f32[0] + v81.m128_f32[0]) < 0.0 )
        {
          do
          {
            if ( !v70 )
              v70 = m_size;
            v82 = _mm_mul_ps(m_cur[--v70], v72);
            v83 = _mm_shuffle_ps(v82, _mm_unpackhi_ps(v82, m_cur[v70]), 196);
            v84 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
          }
          while ( (float)(_mm_shuffle_ps(v84, v84, 177).m128_f32[0] + v84.m128_f32[0]) < 0.0 );
        }
        ++outputVerticesInOut;
        v68 = v70;
        v85 = _mm_mul_ps(*(__m128 *)&v38[16 * v70], v69);
        v86 = _mm_shuffle_ps(v85, _mm_unpackhi_ps(v85, *(__m128 *)&v38[16 * v70]), 196);
        v87 = _mm_add_ps(_mm_shuffle_ps(v86, v86, 78), v86);
        outputVerticesInOut[-1].m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v87, v87, 177), v87), m_quad),
                                           v69);
        --v8;
      }
      while ( v8 );
    }
    if ( v43 == v38 )
      v47 = 0;
    v97 = v47;
    v88 = (16 * v100 + 127) & 0xFFFFFF80;
    v89 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v90 = (v88 + 15) & 0xFFFFFFF0;
    if ( v88 > v89->m_slabSize || &v43[v90] != v89->m_cur || v89->m_firstNonLifoEnd == v43 )
      hkLifoAllocator::slowBlockFree(v89, v43, v90);
    else
      v89->m_cur = v43;
    v97 = 0;
    if ( v98 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v96, 16 * v98);
    v91 = v102;
    v92 = (char *)p;
    v96 = 0i64;
    if ( p == array )
      v91 = 0;
    v98 = 0x80000000;
    v102 = v91;
    v93 = (16 * v105 + 127) & 0xFFFFFF80;
    v94 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v95 = (v93 + 15) & 0xFFFFFFF0;
    if ( v93 > v94->m_slabSize || &v92[v95] != v94->m_cur || v94->m_firstNonLifoEnd == v92 )
      hkLifoAllocator::slowBlockFree(v94, v92, v95);
    else
      v94->m_cur = v92;
    v102 = 0;
    if ( v103 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v103);
  }
}

