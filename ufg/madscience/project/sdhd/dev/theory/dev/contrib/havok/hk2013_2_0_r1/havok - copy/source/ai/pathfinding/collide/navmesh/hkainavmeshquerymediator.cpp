// File Line: 17
// RVA: 0xC0DA30
_BOOL8 __fastcall isPointOnFaceAndProject(
        hkaiNavMeshUtils *meshInstance,
        unsigned int faceIndex,
        hkVector4f *point,
        hkaiNavMeshQueryMediator::CoherentInput *cinput,
        hkVector4f *projectionOut)
{
  __m128 v9; // xmm3
  __m128 v10; // xmm3

  if ( !hkaiNavMeshUtils::isPointOnFace(meshInstance, faceIndex, &cinput->m_up, point, &cinput->m_isOnFaceTolerance) )
    return 0i64;
  hkaiNavMeshUtils::getClosestPointOnFace((hkaiNavMeshInstance *)meshInstance, point, faceIndex, projectionOut);
  v9 = _mm_sub_ps(projectionOut->m_quad, point->m_quad);
  v10 = _mm_mul_ps(v9, v9);
  return (float)((float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
               + _mm_shuffle_ps(v10, v10, 170).m128_f32[0]) <= (float)(cinput->m_coherencyTolerance.m_real.m128_f32[0]
                                                                     * cinput->m_coherencyTolerance.m_real.m128_f32[0]);
}

// File Line: 37
// RVA: 0xC0DAE0
bool __fastcall needFullCheck(unsigned int previousFaceKey, hkaiStreamingCollection *collection)
{
  bool v2; // zf
  signed int v4; // ecx
  hkaiNavMeshInstance *m_instancePtr; // rdx
  char v7; // [rsp+8h] [rbp+8h]

  v2 = previousFaceKey != -1;
  if ( previousFaceKey != -1 )
  {
    v4 = previousFaceKey & 0x3FFFFF;
    m_instancePtr = collection->m_instances.m_data[previousFaceKey >> 22].m_instancePtr;
    if ( m_instancePtr && v4 < m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size )
    {
      v7 = m_instancePtr->m_faceFlags.m_size ? m_instancePtr->m_faceFlags.m_data[v4].m_storage : 0;
      if ( (v7 & 1) == 0 )
        return 0;
    }
    v2 = 0;
  }
  return !v2;
}

// File Line: 54
// RVA: 0xC0D140
__int64 __fastcall hkaiNavMeshQueryMediator::coherentGetClosestPoint(
        hkaiNavMeshQueryMediator *this,
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator::GetClosestPointInput *input,
        hkaiNavMeshQueryMediator::CoherentInput *cinput,
        hkVector4f *closestPointOut)
{
  unsigned int m_previousFaceKey; // ebx
  hkaiNavMeshQueryMediator *v6; // rdi
  hkaiStreamingCollection *v9; // r15
  _QWORD *Value; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  unsigned int index; // esi
  hkaiNavMeshInstance *m_instancePtr; // rdi
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  hkaiNavMesh::Face *v24; // rax
  int m_startEdgeIndex; // ebp
  hkaiNavMesh::Face *v26; // r12
  __m128 v27; // xmm6
  __m128 v28; // xmm6
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  hkaiNavMesh::Edge *v32; // rax
  hkaiNavMesh::Edge *v33; // rbx
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  unsigned int m_oppositeFace; // ecx
  unsigned int v41; // eax
  unsigned int v42; // esi
  hkaiNavMeshInstance *v43; // r15
  hkaiSpatialQueryHitFilter *v44; // rcx
  _QWORD *v45; // r8
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rax
  _QWORD *v48; // rcx
  _QWORD *v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // r8
  unsigned __int64 v52; // rax
  _QWORD *v53; // rcx
  hkVector4f projectionOut; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f edgeA; // [rsp+40h] [rbp-78h] BYREF
  hkVector4f edgeB; // [rsp+50h] [rbp-68h] BYREF

  m_previousFaceKey = cinput->m_previousFaceKey;
  projectionOut.m_quad = (__m128)input->m_position;
  v6 = this;
  v9 = collection;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LtcoherentGCP";
    *(_QWORD *)(v11 + 16) = "StgetMesh";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    Value[1] = v11 + 24;
  }
  if ( needFullCheck(m_previousFaceKey, v9) )
  {
LABEL_28:
    v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v46 = (_QWORD *)v45[1];
    if ( (unsigned __int64)v46 < v45[3] )
    {
      *v46 = "Stfull";
      v47 = __rdtsc();
      v48 = v46 + 2;
      *((_DWORD *)v48 - 2) = v47;
      v45[1] = v48;
    }
    m_previousFaceKey = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::GetClosestPointInput *, hkVector4f *))v6->vfptr[1].__first_virtual_table_function__)(
                          v6,
                          input,
                          &projectionOut);
    goto $foundPoint;
  }
  index = cinput->m_previousFaceKey & 0x3FFFFF;
  m_instancePtr = v9->m_instances.m_data[m_previousFaceKey >> 22].m_instancePtr;
  m_hitFilter = input->m_hitFilter;
  if ( m_hitFilter
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
          m_hitFilter,
          m_instancePtr,
          index,
          input->m_filterInfo,
          input->m_userData) )
  {
    goto LABEL_9;
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Stprev";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
  if ( !isPointOnFaceAndProject(m_instancePtr, index, &input->m_position, cinput, &projectionOut) )
  {
LABEL_9:
    v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v21 = (_QWORD *)v20[1];
    if ( (unsigned __int64)v21 < v20[3] )
    {
      *v21 = "Stneighbors";
      v22 = __rdtsc();
      v23 = v21 + 2;
      *((_DWORD *)v23 - 2) = v22;
      v20[1] = v23;
    }
    v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__12(
            m_instancePtr->m_originalFaces,
            m_instancePtr->m_numOriginalFaces,
            &m_instancePtr->m_instancedFaces,
            &m_instancePtr->m_ownedFaces,
            &m_instancePtr->m_faceMap,
            index);
    m_startEdgeIndex = v24->m_startEdgeIndex;
    v26 = v24;
    v27 = _mm_sub_ps(input->m_position.m_quad, cinput->m_previousPoint.m_quad);
    v28 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), cinput->m_up.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(cinput->m_up.m_quad, cinput->m_up.m_quad, 201), v27));
    v29 = _mm_shuffle_ps(v28, v28, 201);
    v30 = _mm_mul_ps(cinput->m_previousPoint.m_quad, v29);
    v31 = _mm_shuffle_ps(
            v29,
            _mm_unpackhi_ps(
              v29,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                  _mm_shuffle_ps(v30, v30, 170)))),
            196);
    if ( m_startEdgeIndex < m_startEdgeIndex + v24->m_numEdges )
    {
      do
      {
        v32 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__13(
                m_instancePtr->m_originalEdges,
                m_instancePtr->m_numOriginalEdges,
                &m_instancePtr->m_instancedEdges,
                &m_instancePtr->m_ownedEdges,
                &m_instancePtr->m_edgeMap,
                m_startEdgeIndex);
        v33 = v32;
        if ( v32->m_oppositeEdge != -1 && (v32->m_flags.m_storage & 0x20) == 0 )
        {
          hkaiNavMeshInstance::getEdgePoints(m_instancePtr, m_startEdgeIndex, &edgeA, &edgeB);
          v34 = _mm_mul_ps(v31, edgeA.m_quad);
          v35 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v31), 196);
          v36 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 78), v35);
          v37 = _mm_mul_ps(edgeB.m_quad, v31);
          v38 = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v31), 196);
          v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
          if ( (float)(_mm_shuffle_ps(v36, v36, 177).m128_f32[0] + v36.m128_f32[0]) <= 0.0
            && (float)(_mm_shuffle_ps(v39, v39, 177).m128_f32[0] + v39.m128_f32[0]) >= 0.0 )
          {
            m_oppositeFace = v33->m_oppositeFace;
            if ( (v33->m_flags.m_storage & 0x40) != 0 )
              v41 = m_oppositeFace & 0xFFC00000;
            else
              v41 = m_instancePtr->m_runtimeId << 22;
            m_previousFaceKey = v41 | m_oppositeFace & 0x3FFFFF;
            if ( m_oppositeFace == -1 )
              m_previousFaceKey = -1;
            v42 = m_previousFaceKey & 0x3FFFFF;
            v43 = v9->m_instances.m_data[m_previousFaceKey >> 22].m_instancePtr;
            if ( v43 )
            {
              v44 = input->m_hitFilter;
              if ( !v44
                || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v44->vfptr[2].__vecDelDtor)(
                     v44,
                     v43,
                     v42,
                     input->m_filterInfo,
                     input->m_userData) )
              {
                if ( isPointOnFaceAndProject(v43, v42, &input->m_position, cinput, &projectionOut) )
                  goto $foundPoint;
              }
            }
            v9 = collection;
          }
        }
        ++m_startEdgeIndex;
      }
      while ( m_startEdgeIndex < v26->m_startEdgeIndex + v26->m_numEdges );
    }
    v6 = this;
    goto LABEL_28;
  }
$foundPoint:
  *closestPointOut = (hkVector4f)projectionOut.m_quad;
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  v51 = v49;
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "lt";
    v52 = __rdtsc();
    v53 = v50 + 2;
    *((_DWORD *)v53 - 2) = v52;
    v51[1] = v53;
  }
  return m_previousFaceKey;
} v50 + 2;
    *((_DWORD *)v53 - 2) = v52;
    v51[1] = v53;
  }
  return m_previousFaceKey;
}

// File Line: 149
// RVA: 0xC0DB60
__int64 __fastcall isPointOnFaceAndCast(
        hkaiNavMeshUtils *meshInstance,
        hkaiNavMeshQueryMediator::RaycastInput *input,
        hkaiNavMeshQueryMediator::CoherentInput *cinput,
        hkSimdFloat32 *hitFractionOut)
{
  unsigned int m_previousFaceKey; // edx
  hkVector4f v8; // xmm6
  __m128 m_quad; // xmm7
  __m128i v10; // xmm6
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  hkcdRay hitFractionOuta; // [rsp+20h] [rbp-68h] BYREF
  __m128 v17; // [rsp+50h] [rbp-38h]

  m_previousFaceKey = cinput->m_previousFaceKey;
  v8.m_quad = (__m128)input->m_to;
  m_quad = input->m_from.m_quad;
  hitFractionOuta.m_origin = 0i64;
  v10 = (__m128i)_mm_sub_ps(v8.m_quad, m_quad);
  hitFractionOuta.m_direction.m_quad = m_quad;
  v11 = _mm_cmpeq_ps((__m128)0i64, (__m128)v10);
  v12 = _mm_rcp_ps((__m128)v10);
  hitFractionOuta.m_invDirection.m_quad = _mm_shuffle_ps((__m128)v10, _mm_unpackhi_ps((__m128)v10, query.m_quad), 196);
  v17 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v10, 0x1Fu), 0x1Fu), (__m128)_xmm), v11),
          _mm_andnot_ps(v11, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, (__m128)v10)), v12)));
  v17.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, hitFractionOuta.m_invDirection.m_quad)) & 7 | 0x3F000000;
  if ( !(unsigned __int8)hkaiNavMeshUtils::castRayFace<hkaiNavMeshInstance>(
                           meshInstance,
                           (hkaiNavMeshInstance *)(m_previousFaceKey & 0x3FFFFF),
                           &hitFractionOuta.m_direction.m_quad,
                           &hitFractionOuta,
                           0i64) )
    return 0i64;
  v13 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad), hitFractionOuta.m_origin.m_quad),
            input->m_from.m_quad),
          input->m_from.m_quad);
  v14 = _mm_mul_ps(v13, v13);
  if ( (float)((float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
             + _mm_shuffle_ps(v14, v14, 170).m128_f32[0]) >= (float)(cinput->m_coherencyTolerance.m_real.m128_f32[0]
                                                                   * cinput->m_coherencyTolerance.m_real.m128_f32[0]) )
    return 0i64;
  *hitFractionOut = (hkSimdFloat32)hitFractionOuta.m_origin;
  return 1i64;
}

// File Line: 169
// RVA: 0xC0DCA0
__int64 __fastcall isPointOnFaceAndCast_0(
        hkaiNavMeshUtils *meshInstance,
        hkaiNavMeshQueryMediator::BidirectionalRaycastInput *input,
        hkaiNavMeshQueryMediator::CoherentInput *cinput,
        hkSimdFloat32 *hitFractionOut)
{
  unsigned int m_previousFaceKey; // edx
  hkVector4f v8; // xmm6
  hkVector4f v9; // xmm7
  hkVector4f v10; // xmm7
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __int64 result; // rax
  hkcdRay hitFractionOuta; // [rsp+20h] [rbp-68h] BYREF
  __m128 v18; // [rsp+50h] [rbp-38h]

  m_previousFaceKey = cinput->m_previousFaceKey;
  v8.m_quad = (__m128)input->m_forwardTo;
  v9.m_quad = (__m128)input->m_center;
  hitFractionOuta.m_origin = 0i64;
  v10.m_quad = _mm_sub_ps(v9.m_quad, _mm_sub_ps(v8.m_quad, v9.m_quad));
  v11 = (__m128i)_mm_sub_ps(v8.m_quad, v10.m_quad);
  hitFractionOuta.m_direction = (hkVector4f)v10.m_quad;
  v12 = _mm_cmpeq_ps((__m128)0i64, (__m128)v11);
  v13 = _mm_rcp_ps((__m128)v11);
  hitFractionOuta.m_invDirection.m_quad = _mm_shuffle_ps((__m128)v11, _mm_unpackhi_ps((__m128)v11, query.m_quad), 196);
  v18 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v11, 0x1Fu), 0x1Fu), (__m128)_xmm), v12),
          _mm_andnot_ps(v12, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v11, v13)), v13)));
  v18.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, hitFractionOuta.m_invDirection.m_quad)) & 7 | 0x3F000000;
  if ( !(unsigned __int8)hkaiNavMeshUtils::castRayFace<hkaiNavMeshInstance>(
                           meshInstance,
                           (hkaiNavMeshInstance *)(m_previousFaceKey & 0x3FFFFF),
                           &hitFractionOuta.m_direction.m_quad,
                           &hitFractionOuta,
                           0i64) )
    return 0i64;
  v14 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(input->m_forwardTo.m_quad, v10.m_quad), hitFractionOuta.m_origin.m_quad),
            v10.m_quad),
          input->m_center.m_quad);
  v15 = _mm_mul_ps(v14, v14);
  if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
             + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) >= (float)(cinput->m_coherencyTolerance.m_real.m128_f32[0]
                                                                   * cinput->m_coherencyTolerance.m_real.m128_f32[0]) )
    return 0i64;
  result = 1i64;
  hitFractionOut->m_real = _mm_add_ps(
                             _mm_mul_ps((__m128)xmmword_141A710D0, hitFractionOuta.m_origin.m_quad),
                             g_vectorfConstants[0]);
  return result;
}

// File Line: 192
// RVA: 0xC0D5C0
__int64 __fastcall hkaiNavMeshQueryMediator::coherentCastRay(
        hkaiNavMeshQueryMediator *this,
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator::RaycastInput *input,
        hkaiNavMeshQueryMediator::CoherentInput *cinput,
        hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  unsigned int m_previousFaceKey; // esi
  _QWORD *Value; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  hkaiNavMeshInstance *m_instancePtr; // rbx
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  _QWORD *v15; // r9
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rax
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  __m128 m_real; // xmm0
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  hkSimdFloat32 hitFractionOut; // [rsp+30h] [rbp-18h] BYREF

  m_previousFaceKey = cinput->m_previousFaceKey;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LtcoherentRc";
    *(_QWORD *)(v11 + 16) = "StgetMesh";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    Value[1] = v11 + 24;
  }
  if ( needFullCheck(m_previousFaceKey, collection) )
    goto LABEL_10;
  m_instancePtr = collection->m_instances.m_data[m_previousFaceKey >> 22].m_instancePtr;
  m_hitFilter = input->m_hitFilter;
  if ( m_hitFilter )
  {
    if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, __int64, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
            m_hitFilter,
            m_instancePtr,
            0xFFFFFFFFi64,
            input->m_filterInfo,
            input->m_userData) )
      goto LABEL_10;
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = v15[1];
  if ( v16 < v15[3] )
  {
    *(_QWORD *)v16 = "Stprev";
    v17 = __rdtsc();
    *(_DWORD *)(v16 + 8) = v17;
    v15[1] = v16 + 16;
  }
  hitFractionOut.m_real = query.m_quad;
  v18 = isPointOnFaceAndCast(m_instancePtr, input, cinput, &hitFractionOut);
  v19 = v18 != 0;
  if ( !v18 )
  {
LABEL_10:
    v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v22 = (_QWORD *)v21[1];
    if ( (unsigned __int64)v22 < v21[3] )
    {
      *v22 = "Stfull";
      v23 = __rdtsc();
      v24 = v22 + 2;
      *((_DWORD *)v24 - 2) = v23;
      v21[1] = v24;
    }
    v19 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::RaycastInput *, hkaiNavMeshQueryMediator::HitDetails *))this->vfptr[2].__first_virtual_table_function__)(
            this,
            input,
            hitOut);
  }
  else
  {
    m_real = hitFractionOut.m_real;
    hitOut->m_hitFaceKey = m_previousFaceKey;
    hitOut->m_hitFraction.m_real = m_real;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "lt";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
  return v19;
}

// File Line: 236
// RVA: 0xC0D7A0
__int64 __fastcall hkaiNavMeshQueryMediator::coherentCastBidirectionalRay(
        hkaiNavMeshQueryMediator *this,
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator::BidirectionalRaycastInput *input,
        hkaiNavMeshQueryMediator::CoherentInput *cinput,
        hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  unsigned int m_previousFaceKey; // esi
  _QWORD *Value; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  hkaiNavMeshInstance *m_instancePtr; // rbx
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  _QWORD *v15; // r9
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rax
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  __m128 m_real; // xmm0
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  hkSimdFloat32 hitFractionOut; // [rsp+30h] [rbp-18h] BYREF

  m_previousFaceKey = cinput->m_previousFaceKey;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LtcoherentBrc";
    *(_QWORD *)(v11 + 16) = "StgetMesh";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    Value[1] = v11 + 24;
  }
  if ( needFullCheck(m_previousFaceKey, collection) )
    goto LABEL_10;
  m_instancePtr = collection->m_instances.m_data[m_previousFaceKey >> 22].m_instancePtr;
  m_hitFilter = input->m_hitFilter;
  if ( m_hitFilter )
  {
    if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, __int64, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
            m_hitFilter,
            m_instancePtr,
            0xFFFFFFFFi64,
            input->m_filterInfo,
            input->m_userData) )
      goto LABEL_10;
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = v15[1];
  if ( v16 < v15[3] )
  {
    *(_QWORD *)v16 = "Stprev";
    v17 = __rdtsc();
    *(_DWORD *)(v16 + 8) = v17;
    v15[1] = v16 + 16;
  }
  hitFractionOut.m_real = query.m_quad;
  v18 = isPointOnFaceAndCast_0(m_instancePtr, input, cinput, &hitFractionOut);
  v19 = v18 != 0;
  if ( !v18 )
  {
LABEL_10:
    v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v22 = (_QWORD *)v21[1];
    if ( (unsigned __int64)v22 < v21[3] )
    {
      *v22 = "Stfull";
      v23 = __rdtsc();
      v24 = v22 + 2;
      *((_DWORD *)v24 - 2) = v23;
      v21[1] = v24;
    }
    v19 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *, hkaiNavMeshQueryMediator::HitDetails *))this->vfptr[3].__vecDelDtor)(
            this,
            input,
            hitOut);
  }
  else
  {
    m_real = hitFractionOut.m_real;
    hitOut->m_hitFaceKey = m_previousFaceKey;
    hitOut->m_hitFraction.m_real = m_real;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "lt";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
  return v19;
}

// File Line: 279
// RVA: 0xC0D020
bool __fastcall hkaiNavMeshQueryMediator::castBidirectionalRay(
        hkaiNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::BidirectionalRaycastInput *input,
        hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  __int128 v3; // xmm1
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm0
  char v9; // si
  __m128 v10; // xmm1
  hkSimdFloat32 v11; // xmm0
  unsigned int v12; // eax
  bool result; // al
  hkSimdFloat32 v14; // xmm0
  __m128 v15; // [rsp+20h] [rbp-98h] BYREF
  unsigned int v16; // [rsp+30h] [rbp-88h]
  _OWORD v17[2]; // [rsp+40h] [rbp-78h] BYREF
  hkTransformf *m_localToWorldTransform; // [rsp+60h] [rbp-58h]
  __m128 m_quad; // [rsp+70h] [rbp-48h]
  __m128 v20; // [rsp+80h] [rbp-38h]
  __m128 v21; // [rsp+90h] [rbp-28h] BYREF
  unsigned int v22; // [rsp+A0h] [rbp-18h]

  v3 = *(_OWORD *)&input->m_hitFilter;
  v17[0] = *(_OWORD *)&input->m_filterInfo;
  v17[1] = v3;
  v7.m_quad = (__m128)input->m_center;
  m_localToWorldTransform = input->m_localToWorldTransform;
  v8.m_quad = (__m128)input->m_forwardTo;
  m_quad = v7.m_quad;
  v20 = v8.m_quad;
  v9 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, _OWORD *, __m128 *))this->vfptr[2].__first_virtual_table_function__)(
         this,
         v17,
         &v15);
  v10 = _mm_add_ps(
          _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
            input->m_forwardTo.m_quad),
          _mm_mul_ps(input->m_center.m_quad, (__m128)xmmword_141A710D0));
  v20 = v10;
  if ( v9 )
    v20 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v10, m_quad), v15), m_quad);
  if ( ((unsigned __int8 (__fastcall *)(hkaiNavMeshQueryMediator *, _OWORD *, __m128 *))this->vfptr[2].__first_virtual_table_function__)(
         this,
         v17,
         &v21) )
  {
    v11.m_real = _mm_sub_ps((__m128)0i64, v21);
    if ( v9 )
      v11.m_real = _mm_mul_ps(v11.m_real, v15);
    v12 = v22;
    hitOut->m_hitFraction = (hkSimdFloat32)v11.m_real;
    hitOut->m_hitFaceKey = v12;
    return 1;
  }
  else if ( v9 )
  {
    v14.m_real = v15;
    hitOut->m_hitFaceKey = v16;
    result = 1;
    hitOut->m_hitFraction = (hkSimdFloat32)v14.m_real;
  }
  else
  {
    return 0;
  }
  return result;
}

