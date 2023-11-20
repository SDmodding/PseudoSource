// File Line: 173
// RVA: 0x12F9830
void __fastcall hkaiNewFaceCutterUtil::fitToPlanes(hkArrayBase<hkVector4f> *referenceVertices, hkVector4f *upIn, hkVector4f *outputVerticesInOut, int numOutputVertices)
{
  int v4; // ebx
  __m128 v5; // xmm9
  hkVector4f *v6; // rdi
  hkArrayBase<hkVector4f> *v7; // r12
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
  __m128 *v30; // rax
  __m128 v31; // xmm8
  hkLifoAllocator *v32; // rax
  __m128 *v33; // r8
  int v34; // edx
  char *v35; // rcx
  signed int v36; // eax
  int v37; // eax
  int v38; // er9
  hkLifoAllocator *v39; // rax
  __m128 *v40; // r9
  int v41; // edx
  char *v42; // rcx
  __m128 *v43; // rax
  signed int v44; // er14
  __m128 *v45; // r15
  int v46; // er9
  __int64 v47; // rdx
  hkVector4f *v48; // rax
  __int64 v49; // rcx
  int v50; // er10
  __int64 v51; // r11
  __m128 v52; // xmm11
  signed __int64 v53; // rcx
  __int64 v54; // rdx
  __m128 v55; // xmm10
  __m128 v56; // xmm4
  __m128 v57; // xmm6
  __m128 v58; // xmm3
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm5
  __m128 v62; // xmm5
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm5
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  int v71; // edx
  __m128 v72; // xmm4
  int v73; // ecx
  int v74; // edx
  __m128 v75; // xmm3
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
  __m128 v87; // xmm1
  __m128 v88; // xmm2
  __m128 v89; // xmm2
  __m128 v90; // xmm0
  signed int v91; // ebx
  hkLifoAllocator *v92; // rax
  int v93; // er8
  int v94; // eax
  char *v95; // rdi
  signed int v96; // ebx
  hkLifoAllocator *v97; // rax
  int v98; // er8
  __m128 *v99; // [rsp+30h] [rbp-79h]
  int v100; // [rsp+38h] [rbp-71h]
  int v101; // [rsp+3Ch] [rbp-6Dh]
  __m128 *v102; // [rsp+40h] [rbp-69h]
  int v103; // [rsp+48h] [rbp-61h]
  __m128 *array; // [rsp+50h] [rbp-59h]
  int v105; // [rsp+58h] [rbp-51h]
  int v106; // [rsp+5Ch] [rbp-4Dh]
  void *p; // [rsp+60h] [rbp-49h]
  int v108; // [rsp+68h] [rbp-41h]
  hkResult result; // [rsp+110h] [rbp+67h]

  v4 = referenceVertices->m_size;
  v5 = upIn->m_quad;
  v6 = outputVerticesInOut;
  v7 = referenceVertices;
  v8 = numOutputVertices;
  if ( v4 == 3 )
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
    v16 = _mm_mul_ps(v5, v15);
    v17 = _mm_sub_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170)));
    v18 = _mm_rcp_ps(v17);
    v19 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpeqps((__m128)0i64, v17),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18)),
            v15);
    if ( numOutputVertices > 0 )
    {
      do
      {
        v20 = v6->m_quad;
        ++v6;
        v21 = _mm_mul_ps(v20, v19);
        v22 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v19), 196);
        v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
        v6[-1].m_quad = _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 177), v23), v5), v6[-1].m_quad);
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v24 = referenceVertices->m_size;
    v25 = 0i64;
    v25.m128_f32[0] = (float)v4;
    v26 = 0i64;
    v27 = _mm_shuffle_ps(v25, v25, 0);
    v28 = _mm_rcp_ps(v27);
    v29 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v28)), v28);
    if ( v4 > 0 )
    {
      v30 = &v7->m_data->m_quad;
      do
      {
        v26 = _mm_add_ps(v26, *v30);
        ++v30;
        --v24;
      }
      while ( v24 );
    }
    v31 = _mm_mul_ps(v26, v29);
    v106 = 2147483648;
    v108 = v4;
    array = 0i64;
    v105 = 0;
    if ( v4 )
    {
      v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (__m128 *)v32->m_cur;
      v34 = (16 * v4 + 127) & 0xFFFFFF80;
      v35 = (char *)v33 + v34;
      if ( v34 > v32->m_slabSize || v35 > v32->m_end )
      {
        v33 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v32, v34);
        array = v33;
      }
      else
      {
        v32->m_cur = v35;
        array = v33;
      }
    }
    else
    {
      v33 = 0i64;
      array = 0i64;
    }
    p = v33;
    v106 = v4 | 0x80000000;
    v36 = (v4 | 0x80000000) & 0x3FFFFFFF;
    if ( v36 < v4 )
    {
      v37 = 2 * v36;
      v38 = v4;
      if ( v4 < v37 )
        v38 = v37;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v38, 16);
      v33 = array;
    }
    v105 = v4;
    v99 = 0i64;
    v100 = 0;
    v101 = 2147483648;
    v103 = v4;
    if ( v4 )
    {
      v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v40 = (__m128 *)v39->m_cur;
      v41 = (16 * v4 + 127) & 0xFFFFFF80;
      v42 = (char *)v40 + v41;
      if ( v41 > v39->m_slabSize || v42 > v39->m_end )
      {
        v43 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v39, v41);
        v33 = array;
        v40 = v43;
        v99 = v43;
      }
      else
      {
        v39->m_cur = v42;
        v33 = array;
        v99 = v40;
      }
    }
    else
    {
      v40 = 0i64;
      v99 = 0i64;
    }
    v101 = v4 | 0x80000000;
    v44 = (v4 | 0x80000000) & 0x3FFFFFFF;
    v45 = v40;
    v102 = v40;
    if ( v44 < v4 )
    {
      v46 = v4;
      if ( v4 < 2 * v44 )
        v46 = 2 * v44;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v99, v46, 16);
      v33 = array;
      v45 = v102;
      v40 = v99;
    }
    v47 = v7->m_size;
    v48 = v7->m_data;
    v49 = v7->m_size;
    v100 = v4;
    v50 = v4;
    v51 = v47;
    v52 = _mm_sub_ps(v48[v49 - 1].m_quad, v31);
    if ( (signed int)v47 > 0 )
    {
      v53 = 16i64 * ((signed int)v47 - 1);
      v54 = 0i64;
      v55 = _mm_shuffle_ps(v5, v5, 201);
      do
      {
        v56 = _mm_shuffle_ps(v52, v52, 201);
        v57 = _mm_sub_ps(v7->m_data[v54].m_quad, v31);
        v58 = _mm_sub_ps(_mm_mul_ps(v56, v5), _mm_mul_ps(v55, v52));
        v59 = _mm_shuffle_ps(v58, v58, 201);
        v60 = _mm_mul_ps(v59, v31);
        v61 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v52), _mm_mul_ps(v56, v57));
        v62 = _mm_shuffle_ps(v61, v61, 201);
        v63 = _mm_shuffle_ps(
                v59,
                _mm_unpackhi_ps(
                  v59,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                      _mm_shuffle_ps(v60, v60, 170)))),
                196);
        v64 = _mm_mul_ps(v63, v31);
        v65 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                _mm_shuffle_ps(v64, v64, 170));
        v66 = _mm_mul_ps(v62, v31);
        *(__m128 *)((char *)v33 + v53) = _mm_shuffle_ps(v63, _mm_unpackhi_ps(v63, _mm_sub_ps((__m128)0i64, v65)), 196);
        v67 = _mm_shuffle_ps(
                v62,
                _mm_unpackhi_ps(
                  v62,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                      _mm_shuffle_ps(v66, v66, 170)))),
                196);
        v68 = _mm_mul_ps(v67, v5);
        v69 = _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                  _mm_shuffle_ps(v68, v68, 170)));
        v70 = _mm_rcp_ps(v69);
        v52 = v57;
        *(__m128 *)((char *)v99 + v53) = _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmpeqps((__m128)0i64, v69),
                                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v70, v69)), v70)),
                                           v67);
        v33 = array;
        v53 = v54 * 16;
        ++v54;
        --v51;
      }
      while ( v51 );
      v45 = v102;
      v50 = v100;
      v40 = v99;
    }
    v71 = 0;
    if ( v8 > 0 )
    {
      do
      {
        v72 = v6->m_quad;
        v73 = v71;
        v74 = v71 + 1;
        v75 = v6->m_quad;
        if ( v74 == v4 )
          v74 = 0;
        v76 = _mm_mul_ps(v33[v74], v72);
        v77 = _mm_shuffle_ps(v76, _mm_unpackhi_ps(v76, v33[v74]), 196);
        v78 = _mm_add_ps(_mm_shuffle_ps(v77, v77, 78), v77);
        if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 177)) + v78.m128_f32[0]) >= 0.0 )
        {
          do
          {
            v73 = v74++;
            if ( v74 == v4 )
              v74 = 0;
            v79 = _mm_mul_ps(v33[v74], v75);
            v80 = _mm_shuffle_ps(v79, _mm_unpackhi_ps(v79, v33[v74]), 196);
            v81 = _mm_add_ps(_mm_shuffle_ps(v80, v80, 78), v80);
          }
          while ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v81, v81, 177)) + v81.m128_f32[0]) >= 0.0 );
        }
        v82 = _mm_mul_ps(v33[v73], v75);
        v83 = _mm_shuffle_ps(v82, _mm_unpackhi_ps(v82, v33[v73]), 196);
        v84 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
        if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 177)) + v84.m128_f32[0]) < 0.0 )
        {
          do
          {
            if ( !v73 )
              v73 = v4;
            v85 = _mm_mul_ps(v33[--v73], v75);
            v86 = _mm_shuffle_ps(v85, _mm_unpackhi_ps(v85, v33[v73]), 196);
            v87 = _mm_add_ps(_mm_shuffle_ps(v86, v86, 78), v86);
          }
          while ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v87, v87, 177)) + v87.m128_f32[0]) < 0.0 );
        }
        ++v6;
        v71 = v73;
        v88 = _mm_mul_ps(v40[v73], v72);
        v89 = _mm_shuffle_ps(v88, _mm_unpackhi_ps(v88, v40[v73]), 196);
        v90 = _mm_add_ps(_mm_shuffle_ps(v89, v89, 78), v89);
        v6[-1].m_quad = _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v90, v90, 177), v90), v5), v72);
        --v8;
      }
      while ( v8 );
    }
    if ( v45 == v40 )
      v50 = 0;
    v100 = v50;
    v91 = (16 * v103 + 127) & 0xFFFFFF80;
    v92 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v93 = (v91 + 15) & 0xFFFFFFF0;
    if ( v91 > v92->m_slabSize || (char *)v45 + v93 != v92->m_cur || v92->m_firstNonLifoEnd == v45 )
      hkLifoAllocator::slowBlockFree(v92, v45, v93);
    else
      v92->m_cur = v45;
    v100 = 0;
    if ( v101 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v99,
        16 * v101);
    v94 = v105;
    v95 = (char *)p;
    v99 = 0i64;
    if ( p == array )
      v94 = 0;
    v101 = 2147483648;
    v105 = v94;
    v96 = (16 * v108 + 127) & 0xFFFFFF80;
    v97 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v98 = (v96 + 15) & 0xFFFFFFF0;
    if ( v96 > v97->m_slabSize || &v95[v98] != v97->m_cur || v97->m_firstNonLifoEnd == v95 )
      hkLifoAllocator::slowBlockFree(v97, v95, v98);
    else
      v97->m_cur = v95;
    v105 = 0;
    if ( v106 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v106);
  }
}

