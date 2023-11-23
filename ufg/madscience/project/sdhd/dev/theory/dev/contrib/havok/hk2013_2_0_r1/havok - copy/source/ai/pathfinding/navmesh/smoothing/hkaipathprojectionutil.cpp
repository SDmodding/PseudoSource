// File Line: 35
// RVA: 0xC08700
void __fastcall hkaiPathProjectionUtil::getSimplifiedPathPoints(
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathIn,
        hkaiPath *pathOut,
        float _lengthTol,
        float _cosAngleTol,
        float _cosNormalAngleTol)
{
  int v5; // esi
  float v8; // xmm13_4
  float v9; // xmm14_4
  float v10; // xmm15_4
  __int64 i; // rdi
  __int64 m_size; // r9
  hkVector4f v13; // xmm5
  hkVector4f v14; // xmm10
  __m128 m_quad; // xmm9
  __int64 v16; // r8
  hkaiPath::PathPoint *m_data; // rdx
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm11
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  __m128 v29; // xmm9
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm11
  __m128 v34; // xmm8
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm8
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  hkaiPath::PathPoint *v43; // rcx
  __int128 v44; // [rsp+40h] [rbp-C8h]

  v5 = 0;
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(_lengthTol), (__m128)LODWORD(_lengthTol), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(_cosNormalAngleTol), (__m128)LODWORD(_cosNormalAngleTol), 0).m128_u32[0];
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(_cosAngleTol), (__m128)LODWORD(_cosAngleTol), 0).m128_u32[0];
  if ( pathIn->m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      m_size = pathOut->m_points.m_size;
      v13.m_quad = (__m128)pathIn->m_data[i].m_normal;
      v14.m_quad = (__m128)pathIn->m_data[i].m_position;
      m_quad = v13.m_quad;
      v44 = *(_OWORD *)&pathIn->m_data[i].m_userEdgeData;
      if ( (int)m_size <= 1 )
        goto LABEL_11;
      v16 = pathOut->m_points.m_size;
      m_data = pathOut->m_points.m_data;
      if ( DWORD1(v44) != m_data[v16 - 1].m_sectionId )
        goto LABEL_11;
      if ( (m_data[v16 - 1].m_flags.m_storage & 3) != 0 )
        goto LABEL_11;
      v18 = m_data[v16 - 1].m_normal.m_quad;
      v19 = _mm_mul_ps(v13.m_quad, v18);
      v20 = _mm_mul_ps(v18, v18);
      if ( (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                 + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) < (float)((float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                                                                      + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                                                              + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])
                                                                      * v9) )
        goto LABEL_11;
      v21 = m_data[v16 - 1].m_position.m_quad;
      v22 = _mm_mul_ps(v13.m_quad, v21);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_mul_ps(v13.m_quad, v14.m_quad);
      v25 = _mm_sub_ps(v21, _mm_mul_ps(v23, v13.m_quad));
      v26 = _mm_sub_ps(
              v14.m_quad,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                  _mm_shuffle_ps(v24, v24, 170)),
                v13.m_quad));
      v27 = _mm_sub_ps(v25, v26);
      v28 = _mm_mul_ps(v27, v27);
      if ( (float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
                 + _mm_shuffle_ps(v28, v28, 170).m128_f32[0]) < (float)(v8 * v8) )
        break;
      v33 = _mm_sub_ps(v26, v25);
      v34 = _mm_sub_ps(v25, m_data[m_size - 2].m_position.m_quad);
      v35 = _mm_mul_ps(v34, v34);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
              _mm_shuffle_ps(v35, v35, 170));
      v37 = _mm_rsqrt_ps(v36);
      v38 = _mm_mul_ps(v33, v33);
      v39 = _mm_mul_ps(
              v34,
              _mm_andnot_ps(
                _mm_cmple_ps(v36, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                  _mm_mul_ps(v37, *(__m128 *)_xmm))));
      v40 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v41 = _mm_rsqrt_ps(v40);
      v42 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v40, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                    _mm_mul_ps(v41, *(__m128 *)_xmm))),
                v33),
              v39);
      if ( (float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0] + _mm_shuffle_ps(v42, v42, 0).m128_f32[0])
                 + _mm_shuffle_ps(v42, v42, 170).m128_f32[0]) > v10 )
        goto LABEL_10;
LABEL_11:
      if ( pathOut->m_points.m_size == (pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &pathOut->m_points, 48);
      v43 = &pathOut->m_points.m_data[pathOut->m_points.m_size];
      if ( v43 )
      {
        v43->m_position = (hkVector4f)v14.m_quad;
        v43->m_normal.m_quad = m_quad;
        *(_OWORD *)&v43->m_userEdgeData = v44;
      }
      ++pathOut->m_points.m_size;
      if ( ++v5 >= pathIn->m_size )
        return;
    }
    v14.m_quad = _mm_add_ps(
                   v14.m_quad,
                   _mm_mul_ps(_mm_sub_ps(m_data[v16 - 1].m_position.m_quad, v14.m_quad), (__m128)xmmword_141A711B0));
    v29 = _mm_add_ps(
            v13.m_quad,
            _mm_mul_ps(_mm_sub_ps(m_data[v16 - 1].m_normal.m_quad, v13.m_quad), (__m128)xmmword_141A711B0));
    v30 = _mm_mul_ps(v29, v29);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v32 = _mm_rsqrt_ps(v31);
    m_quad = _mm_mul_ps(
               v29,
               _mm_andnot_ps(
                 _mm_cmple_ps(v31, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                   _mm_mul_ps(*(__m128 *)_xmm, v32))));
LABEL_10:
    pathOut->m_points.m_size = v16 - 1;
    goto LABEL_11;
  }
}

// File Line: 110
// RVA: 0xC08AF0
char __fastcall hkaiPathProjectionUtil::calcBarycentricCoordinates(
        hkVector4f *pos,
        hkVector4f *t0,
        hkVector4f *t1,
        hkVector4f *t2,
        hkVector4f *result)
{
  __m128 v5; // xmm10
  __m128 v6; // xmm11
  __m128 v7; // xmm1
  __m128 v8; // xmm8
  __m128 v9; // xmm1
  __m128 v10; // xmm9
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm7
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3

  v5 = _mm_sub_ps(t0->m_quad, t1->m_quad);
  v6 = _mm_sub_ps(t2->m_quad, t1->m_quad);
  v7 = _mm_mul_ps(v5, v5);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(v6, v6);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_mul_ps(v6, v5);
  v12 = _mm_mul_ps(v10, v8);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14 = _mm_sub_ps(v12, _mm_mul_ps(v13, v13));
  if ( v14.m128_f32[0] == 0.0
    || (float)(1.0 - (float)(v14.m128_f32[0] / v12.m128_f32[0])) >= _mm_shuffle_ps(
                                                                      (__m128)LODWORD(FLOAT_0_99800104),
                                                                      (__m128)LODWORD(FLOAT_0_99800104),
                                                                      0).m128_f32[0] )
  {
    return 0;
  }
  v15 = _mm_sub_ps(t1->m_quad, pos->m_quad);
  v16 = _mm_mul_ps(v15, v5);
  v17 = _mm_mul_ps(v15, v6);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v20 = _mm_sub_ps(_mm_mul_ps(v19, v13), _mm_mul_ps(v18, v10));
  v21 = _mm_sub_ps(_mm_mul_ps(v18, v13), _mm_mul_ps(v19, v8));
  result->m_quad = _mm_mul_ps(
                     _mm_movelh_ps(
                       _mm_unpacklo_ps(v20, _mm_sub_ps(_mm_sub_ps(v14, v20), v21)),
                       _mm_unpacklo_ps(v21, v21)),
                     _mm_div_ps(query.m_quad, v14));
  return 1;
}

// File Line: 159
// RVA: 0xC08EA0
__int64 __fastcall hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(
        hkArrayBase<hkVector4f> *facePoints,
        hkVector4f *up,
        hkVector4f *pointInOut)
{
  _QWORD *Value; // r9
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  __m128 m_quad; // xmm4
  int v11; // esi
  __int64 v12; // rbx
  __m128 v13; // xmm9
  __int64 v14; // rbp
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm8
  __m128 v19; // xmm6
  __m128 v20; // xmm7
  __m128 v21; // xmm6
  __int64 v22; // rdi
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  unsigned __int8 v29; // bl
  _QWORD *v30; // rax
  _QWORD *v31; // rcx
  _QWORD *v32; // r8
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx
  hkVector4f t2; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4f t1; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f t0; // [rsp+50h] [rbp-98h] BYREF
  hkVector4f pos; // [rsp+60h] [rbp-88h] BYREF
  hkVector4f v40; // [rsp+70h] [rbp-78h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtcalcBary";
    v8 = __rdtsc();
    v9 = v7 + 2;
    *((_DWORD *)v9 - 2) = v8;
    Value[1] = v9;
  }
  m_quad = up->m_quad;
  v11 = 1;
  v12 = 1i64;
  v13 = facePoints->m_data->m_quad;
  v14 = facePoints->m_size - 2;
  v15 = _mm_mul_ps(up->m_quad, pointInOut->m_quad);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(up->m_quad, v13);
  v18 = _mm_sub_ps(pointInOut->m_quad, _mm_mul_ps(v16, up->m_quad));
  pos.m_quad = v18;
  v19 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
  v20 = _mm_sub_ps((__m128)0i64, v19);
  v21 = _mm_add_ps(v19, query.m_quad);
  t2.m_quad = _mm_sub_ps(
                v13,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                    _mm_shuffle_ps(v17, v17, 170)),
                  m_quad));
  if ( v14 <= 1 )
  {
LABEL_8:
    *pointInOut = (hkVector4f)v18;
    v29 = 0;
  }
  else
  {
    v22 = 1i64;
    while ( 1 )
    {
      v23 = up->m_quad;
      v24 = facePoints->m_data[v22].m_quad;
      v25 = facePoints->m_data[v22 + 1].m_quad;
      v26 = _mm_mul_ps(up->m_quad, v24);
      v27 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170));
      v28 = _mm_mul_ps(up->m_quad, v25);
      t0.m_quad = _mm_sub_ps(v24, _mm_mul_ps(v27, up->m_quad));
      t1.m_quad = _mm_sub_ps(
                    v25,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                        _mm_shuffle_ps(v28, v28, 170)),
                      v23));
      if ( hkaiPathProjectionUtil::calcBarycentricCoordinates(&pos, &t0, &t1, &t2, &v40) )
      {
        if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v20, v40.m_quad), _mm_cmple_ps(v40.m_quad, v21))) == 15 )
          break;
      }
      ++v12;
      ++v11;
      ++v22;
      if ( v12 >= v14 )
        goto LABEL_8;
    }
    v29 = 1;
    pointInOut->m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v40.m_quad, v40.m_quad, 85), facePoints->m_data[v11 + 1].m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(v40.m_quad, v40.m_quad, 0), facePoints->m_data[v11].m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(v40.m_quad, v40.m_quad, 170), v13));
  }
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  v32 = v30;
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "Et";
    v33 = __rdtsc();
    v34 = v31 + 2;
    *((_DWORD *)v34 - 2) = v33;
    v32[1] = v34;
  }
  return v29;
}31 = "Et";
    v33 = __rdtsc();

// File Line: 242
// RVA: 0xC08C90
_BOOL8 __fastcall hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(
        hkaiGeneralAccessor *accessor,
        hkVector4f *up,
        unsigned int faceKey,
        hkVector4f *pointInOut)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkaiNavMesh::Face *FaceFromPacked; // rax
  hkArrayBase<hkVector4f> *v14; // r9
  int m_numEdges; // ebx
  hkaiNavMeshInstance *v16; // rdi
  int v17; // ebx
  hkLifoAllocator *v18; // rcx
  hkVector4f *m_cur; // rax
  int v20; // edx
  char *v21; // r8
  hkaiNavMeshInstance *m_accessor; // rcx
  bool v23; // al
  int m_size; // ecx
  char *v25; // rdi
  bool v26; // si
  signed int v27; // ebx
  hkLifoAllocator *v28; // rax
  int v29; // r8d
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  hkArrayBase<hkVector4f> faceVerticesOut; // [rsp+20h] [rbp-38h] BYREF
  void *p; // [rsp+30h] [rbp-28h]
  int v37; // [rsp+38h] [rbp-20h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtcalcBary";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  m_numEdges = FaceFromPacked->m_numEdges;
  v16 = (hkaiNavMeshInstance *)FaceFromPacked;
  faceVerticesOut.m_data = 0i64;
  v17 = m_numEdges + 1;
  faceVerticesOut.m_size = 0;
  faceVerticesOut.m_capacityAndFlags = 0x80000000;
  v37 = v17;
  if ( v17 )
  {
    v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)v18->m_cur;
    v20 = (16 * v17 + 127) & 0xFFFFFF80;
    v21 = (char *)m_cur + v20;
    if ( v20 > v18->m_slabSize || v21 > v18->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
    else
      v18->m_cur = v21;
  }
  else
  {
    m_cur = 0i64;
  }
  m_accessor = accessor->m_accessor;
  faceVerticesOut.m_data = m_cur;
  p = m_cur;
  faceVerticesOut.m_capacityAndFlags = v17 | 0x80000000;
  faceVerticesOut.m_size = (__int16)v16->m_memSizeAndFlags + 1;
  hkaiNavMeshUtils::getFaceVertices((hkaiNavMeshUtils *)m_accessor, v16, (hkaiNavMesh::Face *)&faceVerticesOut, v14);
  v23 = hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(&faceVerticesOut, up, pointInOut);
  m_size = faceVerticesOut.m_size;
  v25 = (char *)p;
  v26 = v23;
  if ( p == faceVerticesOut.m_data )
    m_size = 0;
  faceVerticesOut.m_size = m_size;
  v27 = (16 * v37 + 127) & 0xFFFFFF80;
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (v27 + 15) & 0xFFFFFFF0;
  if ( v27 > v28->m_slabSize || &v25[v29] != v28->m_cur || v28->m_firstNonLifoEnd == v25 )
    hkLifoAllocator::slowBlockFree(v28, v25, v29);
  else
    v28->m_cur = v25;
  faceVerticesOut.m_size = 0;
  if ( faceVerticesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      faceVerticesOut.m_data,
      16 * faceVerticesOut.m_capacityAndFlags);
  faceVerticesOut.m_data = 0i64;
  faceVerticesOut.m_capacityAndFlags = 0x80000000;
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "Et";
    v32 = __rdtsc();
    v33 = v31 + 2;
    *((_DWORD *)v33 - 2) = v32;
    v30[1] = v33;
  }
  return v26;
}

// File Line: 257
// RVA: 0xC09170
__int64 __fastcall hkaiPathProjectionUtil::projectSegmentOntoFaceAndClipEdgesWorldUp(
        hkArrayBase<hkVector4f> *faceVerts,
        int faceIndex,
        hkVector4f *A,
        hkVector4f *B,
        hkVector4f *up,
        hkVector4f *Aout,
        hkVector4f *Bout)
{
  hkVector4f *v9; // rdi
  _QWORD *Value; // r10
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  int v14; // r15d
  __int64 v15; // rsi
  int v16; // r12d
  __m128 m_quad; // xmm6
  int v18; // eax
  __int64 v19; // r13
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  __m128 v22; // xmm12
  __m128 v23; // xmm13
  int v24; // ebx
  __m128 v25; // xmm14
  __m128 v26; // xmm15
  __int64 v27; // rdi
  int v28; // ecx
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm9
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm7
  __m128 v37; // xmm10
  __m128 v38; // xmm11
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm10
  __m128 v43; // xmm11
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm6
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  __m128 v55; // xmm1
  __m128 v56; // xmm6
  __m128 v57; // xmm6
  __m128 v58; // xmm1
  __m128 v59; // xmm1
  __m128 v60; // xmm4
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m128 v64; // xmm6
  __m128 v65; // xmm10
  __m128 v66; // xmm3
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm5
  __m128 v71; // xmm1
  __m128 v72; // xmm10
  __m128 v73; // xmm10
  __m128 v74; // xmm1
  __m128 v75; // xmm6
  __m128 v76; // xmm10
  __m128 v77; // xmm1
  __m128 v78; // xmm5
  __m128 v79; // xmm1
  __m128 v80; // xmm4
  __m128 v81; // xmm2
  __m128 v82; // xmm2
  __m128 v83; // xmm14
  __m128 v84; // xmm2
  __m128 v85; // xmm1
  __m128 v86; // xmm10
  unsigned __int8 v87; // bl
  char v88; // bl
  __m128 v89; // xmm1
  __m128 v90; // xmm4
  __m128 v91; // xmm1
  __m128 v92; // xmm1
  __m128 v93; // xmm0
  __m128 v94; // xmm1
  __m128 v95; // xmm7
  __m128 v96; // xmm9
  __m128 v97; // xmm1
  __m128 v98; // xmm6
  __m128 v99; // xmm1
  __m128 v100; // xmm5
  __m128 v101; // xmm2
  __m128 v102; // xmm3
  __m128 v103; // xmm15
  __m128 v104; // xmm3
  __m128 v105; // xmm0
  __m128 v106; // xmm9
  __m128 v107; // xmm1
  __m128 v108; // xmm4
  __m128 v109; // xmm1
  __m128 v110; // xmm1
  __m128 v111; // xmm0
  __m128 v112; // xmm2
  __m128 v113; // xmm0
  _QWORD *v114; // rax
  _QWORD *v115; // rcx
  _QWORD *v116; // r8
  unsigned __int64 v117; // rax
  _QWORD *v118; // rcx
  hkVector4f planeOut; // [rsp+20h] [rbp-148h] BYREF
  __m128 v121; // [rsp+30h] [rbp-138h]
  __m128 v122; // [rsp+40h] [rbp-128h]
  __m128 v123; // [rsp+50h] [rbp-118h]
  hkVector4f pointInOut; // [rsp+60h] [rbp-108h] BYREF
  hkVector4f v125; // [rsp+70h] [rbp-F8h] BYREF
  hkVector4f edgePlaneOut; // [rsp+80h] [rbp-E8h] BYREF

  v9 = A;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtprojectSegmentOntoFace";
    v12 = __rdtsc();
    v13 = v11 + 2;
    *((_DWORD *)v13 - 2) = v12;
    Value[1] = v13;
  }
  v14 = -1;
  v15 = 0i64;
  v16 = -1;
  *Aout = (hkVector4f)v9->m_quad;
  *Bout = (hkVector4f)B->m_quad;
  m_quad = up->m_quad;
  v18 = faceVerts->m_size - 1;
  v19 = v18;
  v20 = _mm_mul_ps(up->m_quad, B->m_quad);
  v21 = _mm_mul_ps(up->m_quad, v9->m_quad);
  v22 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                _mm_shuffle_ps(v21, v21, 170))),
            up->m_quad),
          v9->m_quad);
  pointInOut.m_quad = v22;
  v121 = (__m128)xmmword_141A712A0;
  v23 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170))),
            m_quad),
          B->m_quad);
  v24 = 0;
  v123 = (__m128)xmmword_141A712A0;
  v25 = v22;
  v122 = v22;
  v125.m_quad = v23;
  v26 = v23;
  if ( v18 > 0 )
  {
    v27 = 0i64;
    while ( 1 )
    {
      hkaiNavMeshUtils::calcEdgePlane(faceVerts, v24, up, &edgePlaneOut);
      v28 = 0;
      v29 = _mm_mul_ps(edgePlaneOut.m_quad, v22);
      v30 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, edgePlaneOut.m_quad), 196);
      v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
      v32 = _mm_mul_ps(v23, edgePlaneOut.m_quad);
      v33 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
      v34 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, edgePlaneOut.m_quad), 196);
      if ( v33.m128_f32[0] >= 0.0 )
        v28 = 1;
      v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 78), v34);
      v36 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 177), v35);
      if ( v28 )
        break;
      if ( v36.m128_f32[0] >= 0.0 )
        goto LABEL_11;
LABEL_18:
      ++v15;
      ++v24;
      ++v27;
      if ( v15 >= v19 )
      {
        if ( v14 != -1 )
        {
          v75 = faceVerts->m_data[v14].m_quad;
          v76 = _mm_sub_ps(faceVerts->m_data[v14 + 1].m_quad, v75);
          v77 = _mm_mul_ps(up->m_quad, v76);
          v78 = _mm_sub_ps(
                  v76,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                      _mm_shuffle_ps(v77, v77, 170)),
                    up->m_quad));
          v79 = _mm_mul_ps(v78, v78);
          v80 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                  _mm_shuffle_ps(v79, v79, 170));
          v81 = _mm_rsqrt_ps(v80);
          v82 = _mm_andnot_ps(
                  _mm_cmple_ps(v80, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v81, v80), v81)),
                    _mm_mul_ps(*(__m128 *)_xmm, v81)));
          v83 = _mm_mul_ps(_mm_sub_ps(v25, v75), _mm_mul_ps(v82, v78));
          v84 = _mm_mul_ps(v82, v80);
          v85 = _mm_rcp_ps(v84);
          v86 = _mm_add_ps(
                  _mm_mul_ps(
                    v76,
                    _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v85, v84)), v85),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
                        _mm_shuffle_ps(v83, v83, 170)))),
                  v75);
          goto LABEL_26;
        }
        v9 = A;
        goto LABEL_23;
      }
    }
    if ( v36.m128_f32[0] >= 0.0 )
    {
      v87 = 0;
      goto LABEL_35;
    }
LABEL_11:
    v37 = faceVerts->m_data[v27].m_quad;
    v38 = faceVerts->m_data[v27 + 1].m_quad;
    v39 = _mm_mul_ps(up->m_quad, v37);
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v41 = _mm_mul_ps(up->m_quad, v38);
    v42 = _mm_sub_ps(v37, _mm_mul_ps(v40, up->m_quad));
    v43 = _mm_sub_ps(
            v38,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170)),
              up->m_quad));
    if ( v28 )
    {
      v44 = _mm_sub_ps(v33, v36);
      v45 = _mm_sub_ps(v42, v43);
      v46 = _mm_rcp_ps(v44);
      v47 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v46));
      v48 = _mm_mul_ps(v45, v45);
      v49 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
              _mm_shuffle_ps(v48, v48, 170));
      v25 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v23, v22), _mm_mul_ps(_mm_mul_ps(v47, v46), v33)), v22);
      v50 = _mm_sub_ps(v42, v25);
      v51 = _mm_mul_ps(v50, v45);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
              _mm_shuffle_ps(v51, v51, 170));
      v53 = _mm_rcp_ps(v49);
      v54 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v53, v49)), v53), v52);
      v55 = _mm_cmplt_ps(v54, query.m_quad);
      v56 = _mm_sub_ps(
              v50,
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v55, v54), _mm_andnot_ps(v55, query.m_quad))),
                v45));
      v57 = _mm_mul_ps(v56, v56);
      v58 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
              _mm_shuffle_ps(v57, v57, 170));
      if ( v58.m128_f32[0] >= v121.m128_f32[0] )
      {
        v25 = v122;
      }
      else
      {
        v121 = v58;
        v14 = v24;
        v122 = v25;
      }
    }
    if ( v36.m128_f32[0] >= 0.0 )
    {
      v59 = _mm_sub_ps(v36, v33);
      v60 = _mm_sub_ps(v42, v43);
      v61 = _mm_rcp_ps(v59);
      v62 = _mm_mul_ps(v61, v59);
      v63 = _mm_mul_ps(v60, v60);
      v64 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v22, v23), _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v62), v61), v36)),
              v23);
      v65 = _mm_sub_ps(v42, v64);
      v66 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
              _mm_shuffle_ps(v63, v63, 170));
      v67 = _mm_mul_ps(v65, v60);
      v68 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
              _mm_shuffle_ps(v67, v67, 170));
      v69 = _mm_rcp_ps(v66);
      v70 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v66)), v69), v68);
      v71 = _mm_cmplt_ps(v70, query.m_quad);
      v72 = _mm_sub_ps(
              v65,
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v71, v70), _mm_andnot_ps(v71, query.m_quad))),
                v60));
      v73 = _mm_mul_ps(v72, v72);
      v74 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
              _mm_shuffle_ps(v73, v73, 170));
      if ( v74.m128_f32[0] < v123.m128_f32[0] )
      {
        v123 = v74;
        v16 = v24;
        v26 = v64;
      }
    }
    goto LABEL_18;
  }
LABEL_23:
  if ( (unsigned __int8)hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(faceVerts, up, &pointInOut) )
  {
    v86 = pointInOut.m_quad;
LABEL_26:
    v88 = 0;
  }
  else
  {
    v88 = 1;
    hkaiNavMeshUtils::calcFacePlane(faceVerts, &planeOut);
    v89 = _mm_mul_ps(up->m_quad, planeOut.m_quad);
    v90 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
            _mm_shuffle_ps(v89, v89, 170));
    v91 = _mm_mul_ps(v9->m_quad, planeOut.m_quad);
    v92 = _mm_shuffle_ps(v91, _mm_unpackhi_ps(v91, planeOut.m_quad), 196);
    v93 = _mm_add_ps(_mm_shuffle_ps(v92, v92, 78), v92);
    v94 = _mm_rcp_ps(v90);
    v86 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v94, v90)), v94),
                  _mm_add_ps(_mm_shuffle_ps(v93, v93, 177), v93))),
              up->m_quad),
            v9->m_quad);
  }
  if ( v16 == -1 )
  {
    if ( (unsigned __int8)hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(faceVerts, up, &v125) )
    {
      v106 = v125.m_quad;
    }
    else
    {
      if ( !v88 )
        hkaiNavMeshUtils::calcFacePlane(faceVerts, &planeOut);
      v107 = _mm_mul_ps(up->m_quad, planeOut.m_quad);
      v108 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
               _mm_shuffle_ps(v107, v107, 170));
      v109 = _mm_mul_ps(B->m_quad, planeOut.m_quad);
      v110 = _mm_shuffle_ps(v109, _mm_unpackhi_ps(v109, planeOut.m_quad), 196);
      v111 = _mm_add_ps(_mm_shuffle_ps(v110, v110, 78), v110);
      v112 = _mm_add_ps(_mm_shuffle_ps(v111, v111, 177), v111);
      v113 = _mm_rcp_ps(v108);
      v106 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_sub_ps(
                   (__m128)0i64,
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v108, v113)), v113), v112)),
                 up->m_quad),
               B->m_quad);
    }
  }
  else
  {
    v95 = faceVerts->m_data[v16].m_quad;
    v96 = _mm_sub_ps(faceVerts->m_data[v16 + 1].m_quad, v95);
    v97 = _mm_mul_ps(up->m_quad, v96);
    v98 = _mm_sub_ps(
            v96,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                _mm_shuffle_ps(v97, v97, 170)),
              up->m_quad));
    v99 = _mm_mul_ps(v98, v98);
    v100 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
             _mm_shuffle_ps(v99, v99, 170));
    v101 = _mm_rsqrt_ps(v100);
    v102 = _mm_andnot_ps(
             _mm_cmple_ps(v100, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v101, v100), v101)),
               _mm_mul_ps(*(__m128 *)_xmm, v101)));
    v103 = _mm_mul_ps(_mm_sub_ps(v26, v95), _mm_mul_ps(v102, v98));
    v104 = _mm_mul_ps(v102, v100);
    v105 = _mm_rcp_ps(v104);
    v106 = _mm_add_ps(
             _mm_mul_ps(
               v96,
               _mm_mul_ps(
                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v104, v105)), v105),
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
                   _mm_shuffle_ps(v103, v103, 170)))),
             v95);
  }
  v87 = 1;
  *Aout = (hkVector4f)v86;
  *Bout = (hkVector4f)v106;
LABEL_35:
  v114 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v115 = (_QWORD *)v114[1];
  v116 = v114;
  if ( (unsigned __int64)v115 < v114[3] )
  {
    *v115 = "Et";
    v117 = __rdtsc();
    v118 = v115 + 2;
    *((_DWORD *)v118 - 2) = v117;
    v116[1] = v118;
  }
  return v87;
}

