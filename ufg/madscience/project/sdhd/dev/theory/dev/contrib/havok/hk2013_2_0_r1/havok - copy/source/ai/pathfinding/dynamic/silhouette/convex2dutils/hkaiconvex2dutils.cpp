// File Line: 30
// RVA: 0xC0A7B0
__int64 __fastcall hkaiConvex2dUtils::createConvexHullSilhouette(
        hkaiConvex2dUtils::Convex2DHullInput *input,
        hkArrayBase<hkVector4f> *vertsOut)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  int m_capacityAndFlags; // edx
  int m_numVerts; // ecx
  __int32 v10; // ecx
  int *v11; // r8
  hkVector4f v12; // xmm7
  hkVector4f v13; // xmm1
  int v14; // esi
  int v15; // eax
  int v16; // edx
  __m128 v17; // xmm3
  hkQuaternionf v18; // xmm2
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
  int v31; // r9d
  int v32; // edx
  __int64 v33; // r8
  __int64 v34; // rcx
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  hkVector2f *m_data; // rax
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // rax
  unsigned __int64 v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  int m_size; // edx
  int *v47; // rdx
  unsigned int v48; // ebx
  int v49; // r10d
  __int64 v50; // r8
  __int64 v51; // r9
  hkQTransformf *m_transform; // rax
  hkVector4f *v53; // rcx
  __m128 v54; // xmm6
  __m128 v55; // xmm1
  __m128 v56; // xmm3
  __m128 v57; // xmm4
  __int64 v58; // rax
  _QWORD *v59; // r8
  _QWORD *v60; // rcx
  unsigned __int64 v61; // rax
  _QWORD *v62; // rcx
  hkArrayBase<int> indicesOut; // [rsp+18h] [rbp-19h] BYREF
  hkArrayBase<hkVector2f> array[4]; // [rsp+28h] [rbp-9h] BYREF
  hkResult result; // [rsp+98h] [rbp+67h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtConvex hull creation";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  m_capacityAndFlags = 0x80000000;
  vertsOut->m_size = 0;
  m_numVerts = input->m_numVerts;
  array[0].m_data = 0i64;
  array[0].m_size = 0;
  array[0].m_capacityAndFlags = 0x80000000;
  indicesOut.m_data = 0i64;
  indicesOut.m_size = 0;
  indicesOut.m_capacityAndFlags = 0x80000000;
  v10 = m_numVerts + 1;
  if ( v10 )
  {
    result.m_enum = 4 * v10;
    v11 = (int *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkResult *, _QWORD *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                   &hkContainerTempAllocator::s_alloc,
                   &result,
                   Value);
    m_capacityAndFlags = array[0].m_capacityAndFlags;
    v10 = result.m_enum / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12.m_quad = (__m128)input->m_referenceAxis;
  v13.m_quad = (__m128)input->m_up;
  v14 = input->m_numVerts;
  v15 = 0x80000000;
  indicesOut.m_data = v11;
  if ( v10 )
    v15 = v10;
  indicesOut.m_size = 0;
  v16 = m_capacityAndFlags & 0x3FFFFFFF;
  indicesOut.m_capacityAndFlags = v15;
  v17 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 201);
  v18.m_vec.m_quad = (__m128)input->m_transform->m_rotation;
  v19 = _mm_sub_ps(_mm_mul_ps(v17, v13.m_quad), _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), v12.m_quad));
  v20 = _mm_mul_ps(v18.m_vec.m_quad, v12.m_quad);
  v21 = _mm_shuffle_ps(v19, v19, 201);
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 201), v12.m_quad),
          _mm_mul_ps(v18.m_vec.m_quad, v17));
  v23 = _mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 255);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v25 = _mm_mul_ps(v18.m_vec.m_quad, v21);
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 201), v21),
          _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v18.m_vec.m_quad));
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(v24, v18.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v12.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23));
  v28 = _mm_add_ps(v27, v27);
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 0), _mm_shuffle_ps(v25, v25, 85)),
                _mm_shuffle_ps(v25, v25, 170)),
              v18.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v21)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v23));
  v30 = _mm_add_ps(v29, v29);
  if ( v16 < v14 )
  {
    v31 = v14;
    if ( v14 < 2 * v16 )
      v31 = 2 * v16;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, array, v31, 8);
  }
  v32 = 0;
  array[0].m_size = v14;
  if ( input->m_numVerts > 0 )
  {
    v33 = 0i64;
    do
    {
      v34 = v32++;
      v35 = _mm_mul_ps(v28, input->m_verts[v33++].m_quad);
      v36 = _mm_mul_ps(v30, input->m_verts[v33 - 1].m_quad);
      m_data = array[0].m_data;
      array[0].m_data[v34].x = (float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
                             + _mm_shuffle_ps(v35, v35, 170).m128_f32[0];
      m_data[v34].y = (float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
                    + _mm_shuffle_ps(v36, v36, 170).m128_f32[0];
    }
    while ( v32 < input->m_numVerts );
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "TthkMath2d::convexHullIndices";
    v40 = __rdtsc();
    v41 = v39 + 2;
    *((_DWORD *)v41 - 2) = v40;
    v38[1] = v41;
  }
  hkVector2Util::convexHullIndices(&result, array, &indicesOut);
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
  m_size = indicesOut.m_size;
  if ( indicesOut.m_size + 1 <= (vertsOut->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    vertsOut->m_size = indicesOut.m_size;
    v49 = 0;
    if ( m_size > 0 )
    {
      v50 = 0i64;
      v51 = 0i64;
      do
      {
        ++v49;
        ++v51;
        m_transform = input->m_transform;
        ++v50;
        v53 = &input->m_verts[indicesOut.m_data[v51 - 1]];
        v54 = _mm_shuffle_ps(m_transform->m_rotation.m_vec.m_quad, m_transform->m_rotation.m_vec.m_quad, 255);
        v55 = _mm_mul_ps(v53->m_quad, m_transform->m_rotation.m_vec.m_quad);
        v56 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v53->m_quad, v53->m_quad, 201), m_transform->m_rotation.m_vec.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(m_transform->m_rotation.m_vec.m_quad, m_transform->m_rotation.m_vec.m_quad, 201),
                  v53->m_quad));
        v57 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                      _mm_shuffle_ps(v55, v55, 170)),
                    m_transform->m_rotation.m_vec.m_quad),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v54, v54), (__m128)xmmword_141A711B0), v53->m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v54));
        vertsOut->m_data[v50 - 1].m_quad = _mm_add_ps(_mm_add_ps(v57, v57), m_transform->m_translation.m_quad);
        m_size = indicesOut.m_size;
      }
      while ( v49 < indicesOut.m_size );
    }
    v58 = m_size;
    v47 = indicesOut.m_data;
    LODWORD(v58) = indicesOut.m_data[v58 - 1];
    result.m_enum = LODWORD(FLOAT_0_001);
    if ( *indicesOut.m_data != (_DWORD)v58
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32(
                          (__m128i)_mm_sub_ps(vertsOut->m_data->m_quad, vertsOut->m_data[vertsOut->m_size - 1].m_quad),
                          1u),
                        1u),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) & 7) != 7 )
    {
      vertsOut->m_data[vertsOut->m_size++] = (hkVector4f)vertsOut->m_data->m_quad;
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
      &hkContainerTempAllocator::s_alloc,
      v47,
      4 * indicesOut.m_capacityAndFlags);
  indicesOut.m_data = 0i64;
  indicesOut.m_capacityAndFlags = 0x80000000;
  array[0].m_size = 0;
  if ( array[0].m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array[0].m_data,
      8 * array[0].m_capacityAndFlags);
  array[0].m_data = 0i64;
  array[0].m_capacityAndFlags = 0x80000000;
  v59 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v60 = (_QWORD *)v59[1];
  if ( (unsigned __int64)v60 < v59[3] )
  {
    *v60 = "Et";
    v61 = __rdtsc();
    v62 = v60 + 2;
    *((_DWORD *)v62 - 2) = v61;
    v59[1] = v62;
  }
  return v48;
}

// File Line: 103
// RVA: 0xC0B890
char __fastcall expandVertex(
        hkSimdFloat32 *radius,
        hkSimdFloat32 *bevelThreshold,
        hkVector4f *planeA,
        hkVector4f *planeB,
        hkVector4f *dir,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *newVertexOut,
        bool forceNoBevel)
{
  __m128 m_quad; // xmm5
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
  __m128 v26; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm4

  m_quad = planeA->m_quad;
  v10 = _mm_add_ps(planeA->m_quad, planeB->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
             + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) <= _mm_shuffle_ps(
                                                               (__m128)LODWORD(FLOAT_2_8421709eN14),
                                                               (__m128)LODWORD(FLOAT_2_8421709eN14),
                                                               0).m128_f32[0] )
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
                  _mm_cmple_ps(v29, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                    _mm_mul_ps(*(__m128 *)_xmm, v30))),
                dir->m_quad),
              radius->m_real),
            vertexB->m_quad);
    vertexB->m_quad = _mm_add_ps(_mm_mul_ps(radius->m_real, m_quad), v31);
    newVertexOut->m_quad = _mm_add_ps(_mm_mul_ps(planeB->m_quad, radius->m_real), v31);
    return 1;
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
              _mm_cmple_ps(v12, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                _mm_mul_ps(*(__m128 *)_xmm, v13))));
    v15 = _mm_mul_ps(m_quad, v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rcp_ps(v16);
    v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17), radius->m_real);
    if ( forceNoBevel || v16.m128_f32[0] >= bevelThreshold->m_real.m128_f32[0] )
    {
      vertexB->m_quad = _mm_add_ps(_mm_mul_ps(v14, v18), vertexB->m_quad);
      return 0;
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
      v26 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(vertexA->m_quad, v20),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v25)), v25), v23)),
              v20);
      *vertexB = (hkVector4f)v26;
      newVertexOut->m_quad = _mm_add_ps(_mm_sub_ps(v19, v26), v19);
      return 1;
    }
  }
}

// File Line: 152
// RVA: 0xC0BAF0
void __fastcall calcExpandedPlane(
        hkVector4f *prevPoint,
        hkVector4f *curPoint,
        hkVector4f *up,
        hkVector4f *planeOut,
        hkSimdFloat32 *radius)
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
            _mm_cmple_ps(v9, (__m128)0i64),
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
void __fastcall hkaiConvex2dUtils::expandByRadius(
        hkArrayBase<hkVector4f> *silhouettePoints,
        hkVector4f *up,
        hkSimdFloat32 *radius,
        hkSimdFloat32 *bevelThreshold)
{
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __int64 m_size; // r13
  int v13; // edi
  hkLifoAllocator *v14; // rax
  __m128 *m_cur; // r14
  int v16; // esi
  char *v17; // rcx
  hkVector4f *m_data; // r9
  int *v19; // r10
  __int64 v20; // r11
  int v21; // edx
  int v22; // r8d
  int v23; // eax
  __m128 m_quad; // xmm7
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
  int v47; // r13d
  __m128 *v48; // r10
  __m128 v49; // xmm0
  bool v50; // zf
  __m128 *v51; // r10
  int v52; // r11d
  __m128 v53; // xmm1
  __m128 v54; // xmm9
  __m128 v55; // xmm9
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm9
  __m128 v60; // xmm1
  hkLifoAllocator *v61; // rax
  int v62; // r8d
  _QWORD *v63; // r8
  _QWORD *v64; // rcx
  unsigned __int64 v65; // rax
  _QWORD *v66; // rcx
  hkVector4f vertexB; // [rsp+50h] [rbp-108h] BYREF
  hkVector4f newVertexOut; // [rsp+60h] [rbp-F8h] BYREF
  hkVector4f planeA; // [rsp+70h] [rbp-E8h] BYREF
  hkVector4f planeB; // [rsp+80h] [rbp-D8h] BYREF
  hkVector4f vertexA; // [rsp+90h] [rbp-C8h] BYREF
  hkVector4f dir; // [rsp+A0h] [rbp-B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtexpandByRad2";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_size = silhouettePoints->m_size;
  v13 = (silhouettePoints->m_capacityAndFlags & 0x3FFFFFFF) - m_size;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__m128 *)v14->m_cur;
  v16 = (16 * m_size + 127) & 0xFFFFFF80;
  v17 = (char *)m_cur + v16;
  if ( v16 > v14->m_slabSize || v17 > v14->m_end )
    m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
  else
    v14->m_cur = v17;
  m_data = silhouettePoints->m_data;
  if ( (int)m_size > 0 )
  {
    v19 = &m_cur->m128_i32[2];
    v20 = (unsigned int)m_size;
    do
    {
      v21 = m_data->m_quad.m128_i32[2];
      v22 = m_data->m_quad.m128_i32[3];
      v23 = m_data->m_quad.m128_i32[0];
      *(v19 - 1) = m_data->m_quad.m128_i32[1];
      *v19 = v21;
      v19[1] = v22;
      *(v19 - 2) = v23;
      v19 += 4;
      ++m_data;
      --v20;
    }
    while ( v20 );
  }
  silhouettePoints->m_size = 0;
  m_quad = up->m_quad;
  v25 = m_cur[1];
  v26 = _mm_sub_ps(*m_cur, m_cur[m_size - 2]);
  v27 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v28 = _mm_sub_ps(_mm_mul_ps(v27, v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), up->m_quad));
  v29 = _mm_shuffle_ps(v28, v28, 201);
  v30 = _mm_mul_ps(v29, v29);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  v33 = _mm_mul_ps(
          v29,
          _mm_andnot_ps(
            _mm_cmple_ps(v31, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
              _mm_mul_ps(*(__m128 *)_xmm, v32))));
  v34 = _mm_mul_ps(*m_cur, v33);
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
              radius->m_real)),
          196);
  v36 = _mm_sub_ps(v25, *m_cur);
  planeA.m_quad = v35;
  v37 = _mm_sub_ps(_mm_mul_ps(v27, v36), _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), m_quad));
  v38 = _mm_shuffle_ps(v37, v37, 201);
  v39 = _mm_mul_ps(v38, v38);
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v41 = _mm_rsqrt_ps(v40);
  v42 = m_cur[m_size - 2];
  v43 = (int)m_size - 1;
  v44 = _mm_mul_ps(
          v38,
          _mm_andnot_ps(
            _mm_cmple_ps(v40, (__m128)0i64),
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
              radius->m_real)),
          196);
  planeB.m_quad = v46;
  if ( (int)m_size - 1 > 0 )
  {
    v47 = m_size - 2;
    v48 = m_cur;
    do
    {
      newVertexOut.m_quad = *v48;
      vertexB.m_quad = newVertexOut.m_quad;
      v49 = _mm_mul_ps(v35, radius->m_real);
      dir.m_quad = _mm_sub_ps(newVertexOut.m_quad, v42);
      v42 = _mm_add_ps(v42, v49);
      vertexA.m_quad = v42;
      v50 = !expandVertex(radius, bevelThreshold, &planeA, &planeB, &dir, &vertexA, &vertexB, &newVertexOut, v13 <= 0);
      silhouettePoints->m_data[silhouettePoints->m_size++] = (hkVector4f)vertexB.m_quad;
      if ( !v50 )
      {
        silhouettePoints->m_data[silhouettePoints->m_size++] = (hkVector4f)newVertexOut.m_quad;
        --v13;
      }
      if ( v52 != v47 )
      {
        v42 = *v51;
        v35 = v46;
        v53 = _mm_sub_ps(v51[2], v51[1]);
        planeA.m_quad = v46;
        v54 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v53),
                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), up->m_quad));
        v55 = _mm_shuffle_ps(v54, v54, 201);
        v56 = _mm_mul_ps(v55, v55);
        v57 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                _mm_shuffle_ps(v56, v56, 170));
        v58 = _mm_rsqrt_ps(v57);
        v59 = _mm_mul_ps(
                v55,
                _mm_andnot_ps(
                  _mm_cmple_ps(v57, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)),
                    _mm_mul_ps(v58, *(__m128 *)_xmm))));
        v60 = _mm_mul_ps(v59, v51[2]);
        v46 = _mm_shuffle_ps(
                v59,
                _mm_unpackhi_ps(
                  v59,
                  _mm_sub_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                        _mm_shuffle_ps(v60, v60, 170))),
                    radius->m_real)),
                196);
        planeB.m_quad = v46;
      }
      v48 = v51 + 1;
      --v43;
    }
    while ( v43 );
  }
  silhouettePoints->m_data[silhouettePoints->m_size++] = (hkVector4f)silhouettePoints->m_data->m_quad;
  v61 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v62 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v61->m_slabSize || (char *)m_cur + v62 != v61->m_cur || v61->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v61, m_cur, v62);
  else
    v61->m_cur = m_cur;
  v63 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v64 = (_QWORD *)v63[1];
  if ( (unsigned __int64)v64 < v63[3] )
  {
    *v64 = "Et";
    v65 = __rdtsc();
    v66 = v64 + 2;
    *((_DWORD *)v66 - 2) = v65;
    v63[1] = v66;
  }
} v63 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v64 = (_QWORD *)v63[1];
  if ( (unsigned __int64)v64 < v63[3] )
  {
    *v64 = "Et";
    v65 = __

// File Line: 223
// RVA: 0xC0B480
void __fastcall hkaiConvex2dUtils::weldCoincidentVerts(hkArrayBase<hkVector4f> *points, hkSimdFloat32 *tolerance)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  int v8; // r9d
  __int64 v9; // r10
  int m_size; // ecx
  hkVector4f *m_data; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  int v14; // ecx
  __int64 v15; // rax
  int v16; // ecx
  __int64 v17; // rdx
  __int64 v18; // rcx
  int v19; // r8d
  hkVector4f *v20; // rdx
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  int v23; // eax
  __int64 v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "Ttweld";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  v8 = 0;
  if ( points->m_size - 2 > 0 )
  {
    v9 = 0i64;
    do
    {
      m_size = points->m_size;
      if ( m_size <= 4 )
        break;
      m_data = points->m_data;
      v12 = _mm_sub_ps(points->m_data[v9].m_quad, points->m_data[v9 + 1].m_quad);
      v13 = _mm_mul_ps(v12, v12);
      if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
                 + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) >= tolerance->m_real.m128_f32[0] )
      {
        ++v8;
        ++v9;
      }
      else
      {
        v14 = m_size - 1;
        points->m_size = v14;
        v15 = (__int64)&m_data[v9 + 1];
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
    while ( v8 < points->m_size - 2 );
  }
  v19 = points->m_size;
  if ( v19 > 4 )
  {
    v20 = &points->m_data[v8];
    v21 = _mm_sub_ps(v20->m_quad, points->m_data->m_quad);
    v22 = _mm_mul_ps(v21, v21);
    if ( (float)((float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
               + _mm_shuffle_ps(v22, v22, 170).m128_f32[0]) < tolerance->m_real.m128_f32[0] )
    {
      points->m_size = v19 - 1;
      v23 = 16 * (v19 - 1 - v8);
      if ( v23 > 0 )
      {
        v24 = ((unsigned int)(v23 - 1) >> 3) + 1;
        do
        {
          v25 = v20[1].m_quad.m128_u64[0];
          v20 = (hkVector4f *)((char *)v20 + 8);
          v20[-1].m_quad.m128_u64[1] = v25;
          --v24;
        }
        while ( v24 );
      }
    }
  }
  points->m_data[points->m_size - 1] = (hkVector4f)points->m_data->m_quad;
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = v27 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v26[1] = v29;
  }
}

// File Line: 255
// RVA: 0xC0B640
void __fastcall hkaiConvex2dUtils::removeColinearVerts(
        const float areaUnscaledThreshold,
        hkVector4f *referenceAxis,
        hkArrayBase<hkVector4f> *points)
{
  int m_size; // edx
  __m128 v4; // xmm1
  __m128 v6; // xmm3
  hkVector4f *m_data; // rax
  __int64 v8; // rcx
  __m128 v9; // xmm3
  int v10; // r9d
  float v11; // xmm3_4
  __int64 v12; // r10
  __int64 v13; // rbx
  hkVector4f *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  int v20; // ecx
  int v21; // ecx
  __int64 v22; // rax
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

  m_size = points->m_size;
  v4 = (__m128)xmmword_141A712A0;
  v6 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( m_size > 0 )
  {
    m_data = points->m_data;
    v8 = (unsigned int)m_size;
    do
    {
      v4 = _mm_min_ps(v4, m_data->m_quad);
      v6 = _mm_max_ps(v6, m_data->m_quad);
      ++m_data;
      --v8;
    }
    while ( v8 );
  }
  v9 = _mm_sub_ps(v6, v4);
  v10 = 0;
  v9.m128_f32[0] = fmax(
                     _mm_shuffle_ps(v9, v9, 170).m128_f32[0],
                     fmax(_mm_shuffle_ps(v9, v9, 85).m128_f32[0], _mm_shuffle_ps(v9, v9, 0).m128_f32[0]))
                 * _mm_shuffle_ps((__m128)LODWORD(areaUnscaledThreshold), (__m128)LODWORD(areaUnscaledThreshold), 0).m128_f32[0];
  v11 = v9.m128_f32[0] * v9.m128_f32[0];
  if ( m_size - 2 > 0 )
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
      if ( (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                 + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) < v11 )
      {
        v20 = points->m_size;
        if ( v20 > 4 )
        {
          v21 = v20 - 1;
          points->m_size = v21;
          v22 = (__int64)&v14[v12 + 1];
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
    v29 = _mm_sub_ps(points->m_data[v10].m_quad, points->m_data[v10 + 1].m_quad);
    v30 = _mm_sub_ps(v28->m_quad, points->m_data[v10].m_quad);
    v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v30), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v29));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_mul_ps(v32, v32);
    if ( (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0] + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
               + _mm_shuffle_ps(v33, v33, 170).m128_f32[0]) < v11 )
    {
      points->m_size = v26 - 1;
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
  points->m_data[points->m_size - 1] = (hkVector4f)points->m_data->m_quad;
}

// File Line: 313
// RVA: 0xC0B850
char __fastcall hkaiConvex2dUtils::validateHullIsBounding(
        hkArray<hkVector4f,hkContainerHeapAllocator> *inputPoints,
        hkVector4f *upAxis,
        hkArray<hkVector4f,hkContainerHeapAllocator> *hullPoints,
        hkBool allowDuplicates)
{
  return 1;
}

// File Line: 386
// RVA: 0xC0B860
__int64 __fastcall hkaiConvex2dUtils::getStackSizeInBytesRequiredForHullGeneration(unsigned int inputPointsSize)
{
  __int64 v2; // rax

  LODWORD(v2) = hkVector2Util::getStackSizeInBytesRequiredForConvexHullIndices(inputPointsSize);
  return 4 * (inputPointsSize + 1 + 2i64 * inputPointsSize) + v2;
}

// File Line: 393
// RVA: 0xC0A570
__int64 __fastcall hkaiConvex2dUtils::getSilhouetteFromPointCloud(
        hkVector4f *points,
        int numPoints,
        hkaiSilhouetteGenerationParameters *params,
        hkQTransformf *transform,
        hkSimdFloat32 *extraRadius,
        hkSimdFloat32 *weldTolerance,
        hkArrayBase<hkVector4f> *verticesOut)
{
  __int64 v8; // rdi
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // r10
  hkVector4f *v14; // r8
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  unsigned int v17; // eax
  hkVector4f *m_data; // r14
  int m_size; // eax
  __int64 v20; // rcx
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  signed int v23; // ebx
  hkLifoAllocator *v24; // rax
  int v25; // r8d
  hkSimdFloat32 bevelThreshold; // [rsp+20h] [rbp-98h] BYREF
  hkSimdFloat32 radius; // [rsp+30h] [rbp-88h] BYREF
  hkArrayBase<hkVector4f> vertsOut; // [rsp+40h] [rbp-78h] BYREF
  void *p; // [rsp+50h] [rbp-68h]
  int v31; // [rsp+58h] [rbp-60h]
  hkaiConvex2dUtils::Convex2DHullInput input; // [rsp+60h] [rbp-58h] BYREF

  v8 = 0i64;
  vertsOut.m_size = 0;
  v31 = 128;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkVector4f *)Value->m_cur;
  v14 = m_cur + 128;
  if ( Value->m_slabSize < 2048 || v14 > Value->m_end )
    m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, 2048);
  else
    Value->m_cur = v14;
  v15.m_quad = (__m128)params->m_referenceFrame.m_referenceAxis;
  v16.m_quad = (__m128)params->m_referenceFrame.m_up;
  vertsOut.m_data = m_cur;
  vertsOut.m_capacityAndFlags = -2147483520;
  input.m_referenceAxis = (hkVector4f)v15.m_quad;
  input.m_up = (hkVector4f)v16.m_quad;
  p = m_cur;
  input.m_transform = transform;
  input.m_verts = points;
  input.m_numVerts = numPoints;
  v17 = hkaiConvex2dUtils::createConvexHullSilhouette(&input, &vertsOut);
  m_data = vertsOut.m_data;
  if ( v17 )
  {
    m_size = vertsOut.m_size;
    if ( vertsOut.m_size >= 4 )
    {
      verticesOut->m_size = vertsOut.m_size;
      if ( m_size > 0 )
      {
        v20 = (unsigned int)m_size;
        do
        {
          v21 = *(__m128 *)((char *)&m_data->m_quad + v8);
          v8 += 16i64;
          v22 = _mm_mul_ps(v21, params->m_referenceFrame.m_up.m_quad);
          *(__m128 *)((char *)&verticesOut->m_data[-1].m_quad + v8) = _mm_add_ps(
                                                                        _mm_mul_ps(
                                                                          _mm_sub_ps(
                                                                            (__m128)0i64,
                                                                            _mm_add_ps(
                                                                              _mm_add_ps(
                                                                                _mm_shuffle_ps(v22, v22, 85),
                                                                                _mm_shuffle_ps(v22, v22, 0)),
                                                                              _mm_shuffle_ps(v22, v22, 170))),
                                                                          params->m_referenceFrame.m_up.m_quad),
                                                                        *(__m128 *)((char *)&m_data[-1].m_quad + v8));
          --v20;
        }
        while ( v20 );
      }
      hkaiConvex2dUtils::weldCoincidentVerts(verticesOut, weldTolerance);
      hkaiConvex2dUtils::removeColinearVerts(
        params->m_simplify2dConvexHullThreshold,
        &params->m_referenceFrame.m_referenceAxis,
        verticesOut);
      radius.m_real = _mm_add_ps(
                        _mm_shuffle_ps(
                          (__m128)LODWORD(params->m_extraExpansion),
                          (__m128)LODWORD(params->m_extraExpansion),
                          0),
                        extraRadius->m_real);
      if ( radius.m_real.m128_f32[0] > 0.0 )
      {
        bevelThreshold.m_real = _mm_shuffle_ps(
                                  (__m128)LODWORD(params->m_bevelThreshold),
                                  (__m128)LODWORD(params->m_bevelThreshold),
                                  0);
        hkaiConvex2dUtils::expandByRadius(verticesOut, &params->m_referenceFrame.m_up, &radius, &bevelThreshold);
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
      &hkContainerHeapAllocator::s_alloc,
      m_data,
      16 * vertsOut.m_capacityAndFlags);
  return (unsigned int)v8;
}

// File Line: 433
// RVA: 0xC0AF10
void __fastcall hkaiConvex2dUtils::createAabbSilhouette(
        hkaiSilhouetteGenerationParameters *generationParams,
        hkAabb *genAabb,
        hkSimdFloat32 *extraRadius,
        hkArrayBase<hkVector4f> *silhouetteOut)
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
void __fastcall hkaiConvex2dUtils::createObbSilhouette(
        hkaiSilhouetteGenerationParameters *params,
        hkAabb *localAabb,
        hkQTransformf *transform,
        hkSimdFloat32 *extraRadius,
        hkArrayBase<hkVector4f> *silhouetteOut)
{
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // rbx
  hkVector4f *v11; // r10
  __m128 m_extraExpansion_low; // xmm0
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm4
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
  hkaiConvex2dUtils::Convex2DHullInput input; // [rsp+20h] [rbp-48h] BYREF

  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkVector4f *)Value->m_cur;
  v11 = m_cur + 8;
  if ( Value->m_slabSize < 128 || v11 > Value->m_end )
    m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
  else
    Value->m_cur = v11;
  m_extraExpansion_low = (__m128)LODWORD(params->m_extraExpansion);
  v13.m_quad = (__m128)localAabb->m_max;
  v14.m_quad = (__m128)localAabb->m_min;
  input.m_transform = transform;
  input.m_verts = m_cur;
  input.m_numVerts = 8;
  v15 = _mm_add_ps(_mm_shuffle_ps(m_extraExpansion_low, m_extraExpansion_low, 0), extraRadius->m_real);
  v16 = (__m128i)_mm_add_ps(v13.m_quad, v15);
  v17 = _mm_sub_ps(v14.m_quad, v15);
  *m_cur = (hkVector4f)v16;
  *(__m128i *)m_cur = _mm_srli_si128(_mm_slli_si128(v16, 4), 4);
  v18 = v16;
  *(float *)v18.m128i_i32 = v17.m128_f32[0];
  m_cur[1] = (hkVector4f)v18;
  m_cur[1] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v18, 4), 4);
  v19 = (__m128i)_mm_or_ps(
                   _mm_and_ps(v17, (__m128)xmmword_141A60400),
                   _mm_andnot_ps((__m128)xmmword_141A60400, (__m128)v16));
  m_cur[2] = (hkVector4f)v19;
  m_cur[2] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v19, 4), 4);
  v20 = (__m128i)_mm_shuffle_ps(v17, (__m128)v16, 228);
  m_cur[3] = (hkVector4f)v20;
  m_cur[3] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v20, 4), 4);
  v21 = (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141A60420, (__m128)v16),
                   _mm_and_ps(v17, (__m128)xmmword_141A60420));
  m_cur[4] = (hkVector4f)v21;
  m_cur[4] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v21, 4), 4);
  v22 = (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141A60430, (__m128)v16),
                   _mm_and_ps(v17, (__m128)xmmword_141A60430));
  m_cur[5] = (hkVector4f)v22;
  m_cur[5] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v22, 4), 4);
  v23 = (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141A60440, (__m128)v16),
                   _mm_and_ps(v17, (__m128)xmmword_141A60440));
  m_cur[6] = (hkVector4f)v23;
  m_cur[6] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v23, 4), 4);
  v24 = (__m128i)_mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, (__m128)v16), 196);
  m_cur[7] = (hkVector4f)v24;
  m_cur[7] = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v24, 4), 4);
  v25.m_quad = (__m128)params->m_referenceFrame.m_up;
  input.m_referenceAxis = params->m_referenceFrame.m_referenceAxis;
  input.m_up = (hkVector4f)v25.m_quad;
  hkaiConvex2dUtils::createConvexHullSilhouette(&input, silhouetteOut);
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v26->m_slabSize < 128 || &m_cur[8] != v26->m_cur || v26->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v26, m_cur, 128);
  else
    v26->m_cur = m_cur;
}

