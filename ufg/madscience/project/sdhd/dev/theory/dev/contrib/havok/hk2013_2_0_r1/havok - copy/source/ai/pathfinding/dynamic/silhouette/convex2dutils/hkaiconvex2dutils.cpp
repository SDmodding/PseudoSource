// File Line: 30
// RVA: 0xC0A7B0
__int64 __fastcall hkaiConvex2dUtils::createConvexHullSilhouette(hkaiConvex2dUtils::Convex2DHullInput *input, hkArrayBase<hkVector4f> *vertsOut)
{
  hkaiConvex2dUtils::Convex2DHullInput *v2; // rbx
  hkArrayBase<hkVector4f> *v3; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  unsigned int v8; // edx
  int v9; // ecx
  __int32 v10; // ecx
  int *v11; // r8
  __m128 v12; // xmm7
  __m128 v13; // xmm1
  int v14; // esi
  int v15; // eax
  int v16; // edx
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm8
  __m128 v20; // xmm1
  __m128 v21; // xmm8
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm9
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm9
  __m128 v28; // xmm9
  __m128 v29; // xmm7
  __m128 v30; // xmm7
  int v31; // er9
  int v32; // edx
  __int64 v33; // r8
  __int64 v34; // rcx
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  float *v37; // rax
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  _QWORD *v42; // rax
  unsigned __int64 v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  int v46; // edx
  int *v47; // rdx
  unsigned int v48; // ebx
  int v49; // er10
  __int64 v50; // r8
  __int64 v51; // r9
  __m128 *v52; // rax
  __m128 *v53; // rcx
  __m128 v54; // xmm6
  __m128 v55; // xmm1
  __m128 v56; // xmm3
  __m128 v57; // xmm4
  __int64 v58; // rax
  _QWORD *v59; // r8
  _QWORD *v60; // rcx
  unsigned __int64 v61; // rax
  signed __int64 v62; // rcx
  hkArrayBase<int> indicesOut; // [rsp+18h] [rbp-19h]
  float *array; // [rsp+28h] [rbp-9h]
  int v66; // [rsp+30h] [rbp-1h]
  int v67; // [rsp+34h] [rbp+3h]
  hkResult result; // [rsp+98h] [rbp+67h]

  v2 = input;
  v3 = vertsOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtConvex hull creation";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = 2147483648;
  v3->m_size = 0;
  v9 = v2->m_numVerts;
  array = 0i64;
  v66 = 0;
  v67 = 2147483648;
  indicesOut.m_data = 0i64;
  indicesOut.m_size = 0;
  indicesOut.m_capacityAndFlags = 2147483648;
  v10 = v9 + 1;
  if ( v10 )
  {
    result.m_enum = 4 * v10;
    v11 = (int *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkResult *, _QWORD *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                   &hkContainerTempAllocator::s_alloc,
                   &result,
                   v4);
    v8 = v67;
    v10 = result.m_enum / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v2->m_referenceAxis.m_quad;
  v13 = v2->m_up.m_quad;
  v14 = v2->m_numVerts;
  v15 = 2147483648;
  indicesOut.m_data = v11;
  if ( v10 )
    v15 = v10;
  indicesOut.m_size = 0;
  v16 = v8 & 0x3FFFFFFF;
  indicesOut.m_capacityAndFlags = v15;
  v17 = _mm_shuffle_ps(v12, v12, 201);
  v18 = v2->m_transform->m_rotation.m_vec.m_quad;
  v19 = _mm_sub_ps(_mm_mul_ps(v17, v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
  v20 = _mm_mul_ps(v18, v12);
  v21 = _mm_shuffle_ps(v19, v19, 201);
  v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v12), _mm_mul_ps(v18, v17));
  v23 = _mm_shuffle_ps(v18, v18, 255);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v25 = _mm_mul_ps(v18, v21);
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v21), _mm_mul_ps(v21, v18));
  v27 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v24, v18), _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v12)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23));
  v28 = _mm_add_ps(v27, v27);
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 0), _mm_shuffle_ps(v25, v25, 85)),
                _mm_shuffle_ps(v25, v25, 170)),
              v18),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v21)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v23));
  v30 = _mm_add_ps(v29, v29);
  if ( v16 < v14 )
  {
    v31 = v14;
    if ( v14 < 2 * v16 )
      v31 = 2 * v16;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v31, 8);
  }
  v32 = 0;
  v66 = v14;
  if ( v2->m_numVerts > 0 )
  {
    v33 = 0i64;
    do
    {
      v34 = v32++;
      ++v33;
      v35 = _mm_mul_ps(v28, v2->m_verts[v33 - 1].m_quad);
      v36 = _mm_mul_ps(v30, v2->m_verts[v33 - 1].m_quad);
      v37 = array;
      array[2 * v34] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170));
      v37[2 * v34 + 1] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170));
    }
    while ( v32 < v2->m_numVerts );
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "TthkMath2d::convexHullIndices";
    v40 = __rdtsc();
    v41 = (signed __int64)(v39 + 2);
    *(_DWORD *)(v41 - 8) = v40;
    v38[1] = v41;
  }
  hkVector2Util::convexHullIndices(&result, (hkArrayBase<hkVector2f> *)&array, &indicesOut);
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = v42[1];
  v44 = v42;
  if ( v43 < v42[3] )
  {
    *(_QWORD *)v43 = "Et";
    v45 = __rdtsc();
    *(_DWORD *)(v43 + 8) = v45;
    v44[1] = v43 + 16;
  }
  v46 = indicesOut.m_size;
  if ( indicesOut.m_size + 1 <= (v3->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    v3->m_size = indicesOut.m_size;
    v49 = 0;
    if ( v46 > 0 )
    {
      v50 = 0i64;
      v51 = 0i64;
      do
      {
        ++v49;
        ++v51;
        v52 = &v2->m_transform->m_rotation.m_vec.m_quad;
        ++v50;
        v53 = &v2->m_verts[indicesOut.m_data[v51 - 1]].m_quad;
        v54 = _mm_shuffle_ps(*v52, *v52, 255);
        v55 = _mm_mul_ps(*v53, *v52);
        v56 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v53, *v53, 201), *v52),
                _mm_mul_ps(_mm_shuffle_ps(*v52, *v52, 201), *v53));
        v57 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                      _mm_shuffle_ps(v55, v55, 170)),
                    *v52),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v54, v54), (__m128)xmmword_141A711B0), *v53)),
                _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v54));
        v3->m_data[v50 - 1].m_quad = _mm_add_ps(_mm_add_ps(v57, v57), v52[1]);
        v46 = indicesOut.m_size;
      }
      while ( v49 < indicesOut.m_size );
    }
    v58 = v46;
    v47 = indicesOut.m_data;
    LODWORD(v58) = indicesOut.m_data[v58 - 1];
    result.m_enum = LODWORD(FLOAT_0_001);
    if ( *indicesOut.m_data != (_DWORD)v58
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(v3->m_data->m_quad, v3->m_data[v3->m_size - 1].m_quad), 1u),
                        1u),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) & 7) != 7 )
    {
      v3->m_data[v3->m_size++] = (hkVector4f)v3->m_data->m_quad;
      v47 = indicesOut.m_data;
    }
    v48 = 1;
  }
  else
  {
    v47 = indicesOut.m_data;
    v48 = 0;
  }
  indicesOut.m_size = 0;
  if ( indicesOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v47,
      4 * indicesOut.m_capacityAndFlags);
  indicesOut.m_data = 0i64;
  indicesOut.m_capacityAndFlags = 2147483648;
  v66 = 0;
  if ( v67 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v67);
  array = 0i64;
  v67 = 2147483648;
  v59 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v60 = (_QWORD *)v59[1];
  if ( (unsigned __int64)v60 < v59[3] )
  {
    *v60 = "Et";
    v61 = __rdtsc();
    v62 = (signed __int64)(v60 + 2);
    *(_DWORD *)(v62 - 8) = v61;
    v59[1] = v62;
  }
  return v48;
}

// File Line: 103
// RVA: 0xC0B890
char __fastcall expandVertex(hkSimdFloat32 *radius, hkSimdFloat32 *bevelThreshold, hkVector4f *planeA, hkVector4f *planeB, hkVector4f *dir, hkVector4f *vertexA, hkVector4f *vertexB, hkVector4f *newVertexOut, bool forceNoBevel)
{
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm7
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  hkVector4f v26; // xmm4
  char result; // al
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm4

  v9 = planeA->m_quad;
  v10 = _mm_add_ps(planeA->m_quad, planeB->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) <= COERCE_FLOAT(
                                                                 _mm_shuffle_ps(
                                                                   (__m128)LODWORD(FLOAT_2_8421709eN14),
                                                                   (__m128)LODWORD(FLOAT_2_8421709eN14),
                                                                   0)) )
  {
    v28 = _mm_mul_ps(dir->m_quad, dir->m_quad);
    v29 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
            _mm_shuffle_ps(v28, v28, 170));
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v29, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                    _mm_mul_ps(*(__m128 *)_xmm, v30))),
                dir->m_quad),
              radius->m_real),
            vertexB->m_quad);
    vertexB->m_quad = _mm_add_ps(_mm_mul_ps(radius->m_real, v9), v31);
    newVertexOut->m_quad = _mm_add_ps(_mm_mul_ps(planeB->m_quad, radius->m_real), v31);
    result = 1;
  }
  else
  {
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    v14 = _mm_mul_ps(
            v10,
            _mm_andnot_ps(
              _mm_cmpleps(v12, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                _mm_mul_ps(*(__m128 *)_xmm, v13))));
    v15 = _mm_mul_ps(v9, v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rcp_ps(v16);
    v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17), radius->m_real);
    if ( forceNoBevel || v16.m128_f32[0] >= bevelThreshold->m_real.m128_f32[0] )
    {
      vertexB->m_quad = _mm_add_ps(_mm_mul_ps(v14, v18), vertexB->m_quad);
      result = 0;
    }
    else
    {
      v19 = _mm_add_ps(_mm_mul_ps(radius->m_real, v14), vertexB->m_quad);
      v20 = _mm_add_ps(_mm_mul_ps(v14, v18), vertexB->m_quad);
      v21 = _mm_mul_ps(_mm_sub_ps(v19, vertexA->m_quad), v14);
      v22 = _mm_mul_ps(_mm_sub_ps(v20, v19), v14);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                _mm_shuffle_ps(v21, v21, 170)),
              v23);
      v25 = _mm_rcp_ps(v24);
      v26.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(vertexA->m_quad, v20),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v25)), v25), v23)),
                     v20);
      *vertexB = (hkVector4f)v26.m_quad;
      newVertexOut->m_quad = _mm_add_ps(_mm_sub_ps(v19, v26.m_quad), v19);
      result = 1;
    }
  }
  return result;
}

// File Line: 152
// RVA: 0xC0BAF0
void __fastcall calcExpandedPlane(hkVector4f *prevPoint, hkVector4f *curPoint, hkVector4f *up, hkVector4f *planeOut, hkSimdFloat32 *radius)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm6

  v5 = _mm_sub_ps(curPoint->m_quad, prevPoint->m_quad);
  v6 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v5),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), up->m_quad));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          v7,
          _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v12 = _mm_mul_ps(curPoint->m_quad, v11);
  planeOut->m_quad = _mm_shuffle_ps(
                       v11,
                       _mm_unpackhi_ps(
                         v11,
                         _mm_sub_ps(
                           _mm_sub_ps(
                             (__m128)0i64,
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                               _mm_shuffle_ps(v12, v12, 170))),
                           radius->m_real)),
                       196);
}

// File Line: 164
// RVA: 0xC0AF40
void __fastcall hkaiConvex2dUtils::expandByRadius(hkArrayBase<hkVector4f> *silhouettePoints, hkVector4f *up, hkSimdFloat32 *radius, hkSimdFloat32 *bevelThreshold)
{
  hkArrayBase<hkVector4f> *v4; // rbx
  hkSimdFloat32 *v5; // r12
  hkSimdFloat32 *v6; // rbp
  hkVector4f *v7; // r15
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // r13
  int v13; // edi
  hkLifoAllocator *v14; // rax
  __m128 *v15; // r14
  int v16; // esi
  char *v17; // rcx
  _OWORD *v18; // r9
  unsigned __int64 *v19; // r10
  __int64 v20; // r11
  int v21; // edx
  int v22; // er8
  int v23; // eax
  __m128 v24; // xmm7
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm9
  __m128 v28; // xmm10
  __m128 v29; // xmm10
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm10
  __m128 v34; // xmm1
  __m128 v35; // xmm10
  __m128 v36; // xmm1
  __m128 v37; // xmm9
  __m128 v38; // xmm9
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __int64 v43; // r15
  __m128 v44; // xmm9
  __m128 v45; // xmm5
  __m128 v46; // xmm9
  int v47; // er13
  __m128i *v48; // r10
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm0
  bool v52; // zf
  __m128 *v53; // r10
  int v54; // er11
  __int64 v55; // rax
  __m128 v56; // xmm1
  __m128 v57; // xmm9
  __m128 v58; // xmm9
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm9
  __m128 v63; // xmm1
  hkLifoAllocator *v64; // rax
  int v65; // er8
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  signed __int64 v69; // rcx
  hkVector4f vertexB; // [rsp+50h] [rbp-108h]
  hkVector4f newVertexOut; // [rsp+60h] [rbp-F8h]
  hkVector4f planeA; // [rsp+70h] [rbp-E8h]
  hkVector4f planeB; // [rsp+80h] [rbp-D8h]
  hkVector4f vertexA; // [rsp+90h] [rbp-C8h]
  hkVector4f dir; // [rsp+A0h] [rbp-B8h]
  int v76; // [rsp+160h] [rbp+8h]
  hkVector4f *v77; // [rsp+168h] [rbp+10h]

  v77 = up;
  v4 = silhouettePoints;
  v5 = bevelThreshold;
  v6 = radius;
  v7 = up;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtexpandByRad2";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v4->m_size;
  v13 = (v4->m_capacityAndFlags & 0x3FFFFFFF) - v12;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (__m128 *)v14->m_cur;
  v16 = (16 * v12 + 127) & 0xFFFFFF80;
  v76 = (16 * v12 + 127) & 0xFFFFFF80;
  v17 = (char *)v15 + v16;
  if ( v16 > v14->m_slabSize || v17 > v14->m_end )
    v15 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
  else
    v14->m_cur = v17;
  v18 = (_OWORD *)v4->m_data->m_quad.m128_f32;
  if ( (signed int)v12 > 0 )
  {
    v19 = &v15->m128_u64[1];
    v20 = (unsigned int)v12;
    do
    {
      v21 = *((_DWORD *)v18 + 2);
      v22 = *((_DWORD *)v18 + 3);
      v23 = *(_DWORD *)v18;
      *((_DWORD *)v19 - 1) = *((_DWORD *)v18 + 1);
      *(_DWORD *)v19 = v21;
      *((_DWORD *)v19 + 1) = v22;
      *((_DWORD *)v19 - 2) = v23;
      v19 += 2;
      ++v18;
      --v20;
    }
    while ( v20 );
  }
  v4->m_size = 0;
  v24 = v7->m_quad;
  v25 = v15[1];
  v26 = _mm_sub_ps(*v15, v15[v12 - 2]);
  v27 = _mm_shuffle_ps(v24, v24, 201);
  v28 = _mm_sub_ps(_mm_mul_ps(v27, v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v7->m_quad));
  v29 = _mm_shuffle_ps(v28, v28, 201);
  v30 = _mm_mul_ps(v29, v29);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  v33 = _mm_mul_ps(
          v29,
          _mm_andnot_ps(
            _mm_cmpleps(v31, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
              _mm_mul_ps(*(__m128 *)_xmm, v32))));
  v34 = _mm_mul_ps(*v15, v33);
  v35 = _mm_shuffle_ps(
          v33,
          _mm_unpackhi_ps(
            v33,
            _mm_sub_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                  _mm_shuffle_ps(v34, v34, 170))),
              v6->m_real)),
          196);
  v36 = _mm_sub_ps(v15[1], *v15);
  planeA.m_quad = v35;
  v37 = _mm_sub_ps(_mm_mul_ps(v27, v36), _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v24));
  v38 = _mm_shuffle_ps(v37, v37, 201);
  v39 = _mm_mul_ps(v38, v38);
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v41 = _mm_rsqrt_ps(v40);
  v42 = v15[v12 - 2];
  v43 = (signed int)v12 - 1;
  v44 = _mm_mul_ps(
          v38,
          _mm_andnot_ps(
            _mm_cmpleps(v40, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
              _mm_mul_ps(*(__m128 *)_xmm, v41))));
  v45 = _mm_mul_ps(v25, v44);
  v46 = _mm_shuffle_ps(
          v44,
          _mm_unpackhi_ps(
            v44,
            _mm_sub_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                  _mm_shuffle_ps(v45, v45, 170))),
              v6->m_real)),
          196);
  planeB.m_quad = v46;
  if ( (signed int)v12 - 1 > 0 )
  {
    v47 = v12 - 2;
    v48 = (__m128i *)v15;
    do
    {
      v49 = *(__m128 *)v48;
      _mm_store_si128((__m128i *)&newVertexOut, *v48);
      vertexB.m_quad = v49;
      v50 = _mm_sub_ps(v49, v42);
      v51 = _mm_mul_ps(v35, v6->m_real);
      dir.m_quad = v50;
      v42 = _mm_add_ps(v42, v51);
      vertexA.m_quad = v42;
      v52 = expandVertex(v6, v5, &planeA, &planeB, &dir, &vertexA, &vertexB, &newVertexOut, v13 <= 0) == 0;
      v55 = v4->m_size;
      if ( v52 )
      {
        v4->m_data[v55] = (hkVector4f)vertexB.m_quad;
        ++v4->m_size;
      }
      else
      {
        v4->m_data[v55] = (hkVector4f)vertexB.m_quad;
        v4->m_data[++v4->m_size] = (hkVector4f)newVertexOut.m_quad;
        ++v4->m_size;
        --v13;
      }
      if ( v54 != v47 )
      {
        v42 = *v53;
        v35 = v46;
        v56 = _mm_sub_ps(v53[2], v53[1]);
        planeA.m_quad = v46;
        v57 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v77->m_quad, v77->m_quad, 201), v56),
                _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v77->m_quad));
        v58 = _mm_shuffle_ps(v57, v57, 201);
        v59 = _mm_mul_ps(v58, v58);
        v60 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                _mm_shuffle_ps(v59, v59, 170));
        v61 = _mm_rsqrt_ps(v60);
        v62 = _mm_mul_ps(
                v58,
                _mm_andnot_ps(
                  _mm_cmpleps(v60, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v61, v60), v61)),
                    _mm_mul_ps(v61, *(__m128 *)_xmm))));
        v63 = _mm_mul_ps(v62, v53[2]);
        v46 = _mm_shuffle_ps(
                v62,
                _mm_unpackhi_ps(
                  v62,
                  _mm_sub_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                        _mm_shuffle_ps(v63, v63, 170))),
                    v6->m_real)),
                196);
        planeB.m_quad = v46;
      }
      v48 = (__m128i *)&v53[1];
      --v43;
    }
    while ( v43 );
    v16 = v76;
  }
  v4->m_data[v4->m_size++] = (hkVector4f)v4->m_data->m_quad;
  v64 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v64->m_slabSize || (char *)v15 + v65 != v64->m_cur || v64->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v64, v15, v65);
  else
    v64->m_cur = v15;
  v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v67 = (_QWORD *)v66[1];
  if ( (unsigned __int64)v67 < v66[3] )
  {
    *v67 = "Et";
    v68 = __rdtsc();
    v69 = (signed __int64)(v67 + 2);
    *(_DWORD *)(v69 - 8) = v68;
    v66[1] = v69;
  }
}

// File Line: 223
// RVA: 0xC0B480
void __fastcall hkaiConvex2dUtils::weldCoincidentVerts(hkArrayBase<hkVector4f> *points, hkSimdFloat32 *tolerance)
{
  hkArrayBase<hkVector4f> *v2; // rbx
  hkSimdFloat32 *v3; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  int v8; // er9
  __int64 v9; // r10
  signed int v10; // ecx
  __m128 *v11; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  int v14; // ecx
  signed __int64 v15; // rax
  int v16; // ecx
  __int64 v17; // rdx
  __int64 v18; // rcx
  signed int v19; // er8
  __m128 *v20; // rdx
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  int v23; // eax
  __int64 v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx

  v2 = points;
  v3 = tolerance;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "Ttweld";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = 0;
  if ( v2->m_size - 2 > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v2->m_size;
      if ( v10 <= 4 )
        break;
      v11 = &v2->m_data->m_quad;
      v12 = _mm_sub_ps(v2->m_data[v9].m_quad, v2->m_data[v9 + 1].m_quad);
      v13 = _mm_mul_ps(v12, v12);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) >= v3->m_real.m128_f32[0] )
      {
        ++v8;
        ++v9;
      }
      else
      {
        v14 = v10 - 1;
        v2->m_size = v14;
        v15 = (signed __int64)&v11[v9 + 1];
        v16 = 16 * (v14 - v8 - 1);
        if ( v16 > 0 )
        {
          v17 = ((unsigned int)(v16 - 1) >> 3) + 1;
          do
          {
            v18 = *(_QWORD *)(v15 + 16);
            v15 += 8i64;
            *(_QWORD *)(v15 - 8) = v18;
            --v17;
          }
          while ( v17 );
        }
      }
    }
    while ( v8 < v2->m_size - 2 );
  }
  v19 = v2->m_size;
  if ( v19 > 4 )
  {
    v20 = &v2->m_data[v8].m_quad;
    v21 = _mm_sub_ps(*v20, v2->m_data->m_quad);
    v22 = _mm_mul_ps(v21, v21);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170))) < v3->m_real.m128_f32[0] )
    {
      v2->m_size = v19 - 1;
      v23 = 16 * (v19 - 1 - v8);
      if ( v23 > 0 )
      {
        v24 = ((unsigned int)(v23 - 1) >> 3) + 1;
        do
        {
          v25 = v20[1].m128_u64[0];
          v20 = (__m128 *)((char *)v20 + 8);
          v20[-1].m128_u64[1] = v25;
          --v24;
        }
        while ( v24 );
      }
    }
  }
  v2->m_data[v2->m_size - 1] = (hkVector4f)v2->m_data->m_quad;
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v27 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v26[1] = v29;
  }
}

// File Line: 255
// RVA: 0xC0B640
void __fastcall hkaiConvex2dUtils::removeColinearVerts(const float areaUnscaledThreshold, hkVector4f *referenceAxis, hkArrayBase<hkVector4f> *points)
{
  int v3; // edx
  __m128 v4; // xmm1
  hkArrayBase<hkVector4f> *v5; // r11
  __m128 v6; // xmm3
  hkVector4f *v7; // rax
  __int64 v8; // rcx
  __m128 v9; // xmm3
  int v10; // er9
  float v11; // xmm3_4
  __int64 v12; // r10
  signed __int64 v13; // rbx
  hkVector4f *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  int v20; // ecx
  int v21; // ecx
  signed __int64 v22; // rax
  int v23; // ecx
  __int64 v24; // rdx
  __int64 v25; // rcx
  int v26; // edx
  hkVector4f *v27; // rcx
  hkVector4f *v28; // r8
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  int v34; // eax
  signed __int64 v35; // r8
  __int64 v36; // rdx
  unsigned __int64 v37; // rax

  v3 = points->m_size;
  v4 = (__m128)xmmword_141A712A0;
  v5 = points;
  v6 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( v3 > 0 )
  {
    v7 = points->m_data;
    v8 = (unsigned int)v3;
    do
    {
      v4 = _mm_min_ps(v4, v7->m_quad);
      v6 = _mm_max_ps(v6, v7->m_quad);
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  v9 = _mm_sub_ps(v6, v4);
  v10 = 0;
  v9.m128_f32[0] = fmax(
                     COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170)),
                     fmax(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)), COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0))))
                 * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(areaUnscaledThreshold), (__m128)LODWORD(areaUnscaledThreshold), 0));
  v11 = v9.m128_f32[0] * v9.m128_f32[0];
  if ( v3 - 2 > 0 )
  {
    v12 = 0i64;
    v13 = 2i64;
    do
    {
      v14 = points->m_data;
      v15 = _mm_sub_ps(points->m_data[v13].m_quad, points->m_data[v12].m_quad);
      v16 = _mm_sub_ps(points->m_data[v12 + 1].m_quad, points->m_data[v12].m_quad);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      v18 = _mm_shuffle_ps(v17, v17, 201);
      v19 = _mm_mul_ps(v18, v18);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) < v11 )
      {
        v20 = points->m_size;
        if ( v20 > 4 )
        {
          v21 = v20 - 1;
          points->m_size = v21;
          v22 = (signed __int64)&v14[v12 + 1];
          v23 = 16 * (v21 - v10 - 1);
          if ( v23 > 0 )
          {
            v24 = ((unsigned int)(v23 - 1) >> 3) + 1;
            do
            {
              v25 = *(_QWORD *)(v22 + 16);
              v22 += 8i64;
              *(_QWORD *)(v22 - 8) = v25;
              --v24;
            }
            while ( v24 );
          }
          --v10;
          --v12;
          --v13;
        }
      }
      ++v10;
      ++v12;
      ++v13;
    }
    while ( v10 < points->m_size - 2 );
  }
  v26 = points->m_size;
  if ( v26 > 4 )
  {
    v27 = points->m_data;
    v28 = points->m_data + 1;
    v29 = _mm_sub_ps(v5->m_data[v10].m_quad, v5->m_data[v10 + 1].m_quad);
    v30 = _mm_sub_ps(v28->m_quad, v5->m_data[v10].m_quad);
    v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v30), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v29));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_mul_ps(v32, v32);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170))) < v11 )
    {
      v5->m_size = v26 - 1;
      v34 = 16 * (v26 - 1);
      if ( v34 > 0 )
      {
        v35 = (char *)v28 - (char *)v27;
        v36 = ((unsigned int)(v34 - 1) >> 3) + 1;
        do
        {
          v37 = *(unsigned __int64 *)((char *)v27->m_quad.m128_u64 + v35);
          v27 = (hkVector4f *)((char *)v27 + 8);
          v27[-1].m_quad.m128_u64[1] = v37;
          --v36;
        }
        while ( v36 );
      }
    }
  }
  v5->m_data[v5->m_size - 1] = (hkVector4f)v5->m_data->m_quad;
}

// File Line: 313
// RVA: 0xC0B850
char __fastcall hkaiConvex2dUtils::validateHullIsBounding(hkArray<hkVector4f,hkContainerHeapAllocator> *inputPoints, hkVector4f *upAxis, hkArray<hkVector4f,hkContainerHeapAllocator> *hullPoints, hkBool allowDuplicates)
{
  return 1;
}

// File Line: 386
// RVA: 0xC0B860
signed __int64 __fastcall hkaiConvex2dUtils::getStackSizeInBytesRequiredForHullGeneration(int inputPointsSize)
{
  unsigned int v1; // ebx
  __int64 v2; // rax

  v1 = inputPointsSize;
  LODWORD(v2) = hkVector2Util::getStackSizeInBytesRequiredForConvexHullIndices(inputPointsSize);
  return 4 * (v1 + 1 + 2i64 * v1) + v2;
}

// File Line: 393
// RVA: 0xC0A570
__int64 __fastcall hkaiConvex2dUtils::getSilhouetteFromPointCloud(hkVector4f *points, int numPoints, hkaiSilhouetteGenerationParameters *params, hkQTransformf *transform, hkSimdFloat32 *extraRadius, hkSimdFloat32 *weldTolerance, hkArrayBase<hkVector4f> *verticesOut)
{
  hkVector4f *v7; // r14
  __int64 v8; // rdi
  hkQTransformf *v9; // rbx
  hkVector4f *v10; // rsi
  int v11; // ebp
  hkLifoAllocator *v12; // rax
  hkVector4f *v13; // r10
  unsigned __int64 v14; // r8
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  unsigned int v17; // eax
  hkVector4f *v18; // r14
  int v19; // eax
  __int64 v20; // rcx
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  signed int v23; // ebx
  hkLifoAllocator *v24; // rax
  int v25; // er8
  hkSimdFloat32 bevelThreshold; // [rsp+20h] [rbp-98h]
  hkSimdFloat32 radius; // [rsp+30h] [rbp-88h]
  hkArrayBase<hkVector4f> vertsOut; // [rsp+40h] [rbp-78h]
  void *p; // [rsp+50h] [rbp-68h]
  int v31; // [rsp+58h] [rbp-60h]
  hkaiConvex2dUtils::Convex2DHullInput input; // [rsp+60h] [rbp-58h]

  v7 = points;
  v8 = 0i64;
  v9 = transform;
  v10 = (hkVector4f *)params;
  v11 = numPoints;
  vertsOut.m_size = 0;
  v31 = 128;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkVector4f *)v12->m_cur;
  v14 = (unsigned __int64)&v13[128];
  if ( v12->m_slabSize < 2048 || (void *)v14 > v12->m_end )
    v13 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v12, 2048);
  else
    v12->m_cur = (void *)v14;
  v15.m_quad = (__m128)v10[2];
  v16.m_quad = (__m128)v10[1];
  vertsOut.m_data = v13;
  vertsOut.m_capacityAndFlags = -2147483520;
  input.m_referenceAxis = (hkVector4f)v15.m_quad;
  input.m_up = (hkVector4f)v16.m_quad;
  p = v13;
  input.m_transform = v9;
  input.m_verts = v7;
  input.m_numVerts = v11;
  v17 = hkaiConvex2dUtils::createConvexHullSilhouette(&input, &vertsOut);
  v18 = vertsOut.m_data;
  if ( v17 )
  {
    v19 = vertsOut.m_size;
    if ( vertsOut.m_size >= 4 )
    {
      verticesOut->m_size = vertsOut.m_size;
      if ( v19 > 0 )
      {
        v20 = (unsigned int)v19;
        do
        {
          v21 = *(__m128 *)((char *)&v18->m_quad + v8);
          v8 += 16i64;
          v22 = _mm_mul_ps(v21, v10[1].m_quad);
          *(__m128 *)((char *)&verticesOut->m_data[-1].m_quad + v8) = _mm_add_ps(
                                                                        _mm_mul_ps(
                                                                          _mm_sub_ps(
                                                                            (__m128)0i64,
                                                                            _mm_add_ps(
                                                                              _mm_add_ps(
                                                                                _mm_shuffle_ps(v22, v22, 85),
                                                                                _mm_shuffle_ps(v22, v22, 0)),
                                                                              _mm_shuffle_ps(v22, v22, 170))),
                                                                          v10[1].m_quad),
                                                                        *(__m128 *)((char *)&v18[-1].m_quad + v8));
          --v20;
        }
        while ( v20 );
      }
      hkaiConvex2dUtils::weldCoincidentVerts(verticesOut, weldTolerance);
      hkaiConvex2dUtils::removeColinearVerts(v10->m_quad.m128_f32[3], v10 + 2, verticesOut);
      radius.m_real = _mm_add_ps(
                        _mm_shuffle_ps((__m128)v10->m_quad.m128_u32[0], (__m128)v10->m_quad.m128_u32[0], 0),
                        extraRadius->m_real);
      if ( radius.m_real.m128_f32[0] > 0.0 )
      {
        bevelThreshold.m_real = _mm_shuffle_ps((__m128)v10->m_quad.m128_u32[1], (__m128)v10->m_quad.m128_u32[1], 0);
        hkaiConvex2dUtils::expandByRadius(verticesOut, v10 + 1, &radius, &bevelThreshold);
      }
      LODWORD(v8) = 1;
    }
  }
  v23 = (16 * v31 + 127) & 0xFFFFFF80;
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (v23 + 15) & 0xFFFFFFF0;
  if ( v23 > v24->m_slabSize || (char *)p + v25 != v24->m_cur || v24->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v24, p, v25);
  else
    v24->m_cur = p;
  if ( vertsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v18,
      16 * vertsOut.m_capacityAndFlags);
  return (unsigned int)v8;
}

// File Line: 433
// RVA: 0xC0AF10
void __fastcall hkaiConvex2dUtils::createAabbSilhouette(hkaiSilhouetteGenerationParameters *generationParams, hkAabb *genAabb, hkSimdFloat32 *extraRadius, hkArrayBase<hkVector4f> *silhouetteOut)
{
  hkaiConvex2dUtils::createObbSilhouette(
    generationParams,
    genAabb,
    &hkQTransformfIdentity_storage,
    extraRadius,
    silhouetteOut);
}

// File Line: 438
// RVA: 0xC0ACD0
void __fastcall hkaiConvex2dUtils::createObbSilhouette(hkaiSilhouetteGenerationParameters *params, hkAabb *localAabb, hkQTransformf *transform, hkSimdFloat32 *extraRadius, hkArrayBase<hkVector4f> *silhouetteOut)
{
  hkaiSilhouetteGenerationParameters *v5; // rdi
  hkSimdFloat32 *v6; // rbp
  hkQTransformf *v7; // r14
  hkAabb *v8; // rsi
  hkLifoAllocator *v9; // rax
  char *v10; // rbx
  unsigned __int64 v11; // r10
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128i v16; // xmm3
  __m128 v17; // xmm4
  __m128i v18; // xmm0
  __m128i v19; // xmm1
  __m128i v20; // xmm0
  __m128i v21; // xmm2
  __m128i v22; // xmm2
  __m128i v23; // xmm2
  __m128i v24; // xmm4
  hkVector4f v25; // xmm1
  hkLifoAllocator *v26; // rax
  hkaiConvex2dUtils::Convex2DHullInput input; // [rsp+20h] [rbp-48h]

  v5 = params;
  v6 = extraRadius;
  v7 = transform;
  v8 = localAabb;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (char *)v9->m_cur;
  v11 = (unsigned __int64)(v10 + 128);
  if ( v9->m_slabSize < 128 || (void *)v11 > v9->m_end )
    v10 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, 128);
  else
    v9->m_cur = (void *)v11;
  v12 = (__m128)LODWORD(v5->m_extraExpansion);
  v13 = v8->m_max.m_quad;
  v14 = v8->m_min.m_quad;
  input.m_transform = v7;
  input.m_verts = (hkVector4f *)v10;
  input.m_numVerts = 8;
  v15 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 0), v6->m_real);
  v16 = (__m128i)_mm_add_ps(v13, v15);
  v17 = _mm_sub_ps(v14, v15);
  *(__m128i *)v10 = v16;
  _mm_store_si128((__m128i *)v10, _mm_srli_si128(_mm_slli_si128(v16, 4), 4));
  v18 = v16;
  *(float *)v18.m128i_i32 = v17.m128_f32[0];
  *((__m128i *)v10 + 1) = v18;
  _mm_store_si128((__m128i *)v10 + 1, _mm_srli_si128(_mm_slli_si128(v18, 4), 4));
  v19 = (__m128i)_mm_or_ps(
                   _mm_and_ps(v17, (__m128)xmmword_141A60400),
                   _mm_andnot_ps((__m128)xmmword_141A60400, (__m128)v16));
  *((__m128i *)v10 + 2) = v19;
  _mm_store_si128((__m128i *)v10 + 2, _mm_srli_si128(_mm_slli_si128(v19, 4), 4));
  v20 = (__m128i)_mm_shuffle_ps(v17, (__m128)v16, 228);
  *((__m128i *)v10 + 3) = v20;
  _mm_store_si128((__m128i *)v10 + 3, _mm_srli_si128(_mm_slli_si128(v20, 4), 4));
  v21 = (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141A60420, (__m128)v16),
                   _mm_and_ps(v17, (__m128)xmmword_141A60420));
  *((__m128i *)v10 + 4) = v21;
  _mm_store_si128((__m128i *)v10 + 4, _mm_srli_si128(_mm_slli_si128(v21, 4), 4));
  v22 = (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141A60430, (__m128)v16),
                   _mm_and_ps(v17, (__m128)xmmword_141A60430));
  *((__m128i *)v10 + 5) = v22;
  _mm_store_si128((__m128i *)v10 + 5, _mm_srli_si128(_mm_slli_si128(v22, 4), 4));
  v23 = (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141A60440, (__m128)v16),
                   _mm_and_ps(v17, (__m128)xmmword_141A60440));
  *((__m128i *)v10 + 6) = v23;
  _mm_store_si128((__m128i *)v10 + 6, _mm_srli_si128(_mm_slli_si128(v23, 4), 4));
  v24 = (__m128i)_mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, (__m128)v16), 196);
  *((__m128i *)v10 + 7) = v24;
  _mm_store_si128((__m128i *)v10 + 7, _mm_srli_si128(_mm_slli_si128(v24, 4), 4));
  v25.m_quad = (__m128)v5->m_referenceFrame.m_up;
  input.m_referenceAxis = v5->m_referenceFrame.m_referenceAxis;
  input.m_up = (hkVector4f)v25.m_quad;
  hkaiConvex2dUtils::createConvexHullSilhouette(&input, silhouetteOut);
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v26->m_slabSize < 128 || v10 + 128 != v26->m_cur || v26->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v26, v10, 128);
  else
    v26->m_cur = v10;
}

