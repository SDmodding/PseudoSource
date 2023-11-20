// File Line: 17
// RVA: 0xC0DA30
_BOOL8 __fastcall isPointOnFaceAndProject(hkaiNavMeshInstance *meshInstance, int faceIndex, hkVector4f *point, hkaiNavMeshQueryMediator::CoherentInput *cinput, hkVector4f *projectionOut)
{
  hkVector4f *v5; // rsi
  hkaiNavMeshQueryMediator::CoherentInput *v6; // rdi
  int v7; // ebp
  hkaiNavMeshInstance *v8; // r14
  __m128 v9; // xmm3
  __m128 v10; // xmm3

  v5 = point;
  v6 = cinput;
  v7 = faceIndex;
  v8 = meshInstance;
  if ( !hkaiNavMeshUtils::isPointOnFace(meshInstance, faceIndex, &cinput->m_up, point, &cinput->m_isOnFaceTolerance) )
    return 0i64;
  hkaiNavMeshUtils::getClosestPointOnFace(v8, v5, v7, projectionOut);
  v9 = _mm_sub_ps(projectionOut->m_quad, v5->m_quad);
  v10 = _mm_mul_ps(v9, v9);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170))) <= (float)(v6->m_coherencyTolerance.m_real.m128_f32[0]
                                                                       * v6->m_coherencyTolerance.m_real.m128_f32[0]);
}

// File Line: 37
// RVA: 0xC0DAE0
bool __fastcall needFullCheck(unsigned int previousFaceKey, hkaiStreamingCollection *collection)
{
  bool v2; // zf
  unsigned int v3; // eax
  signed int v4; // ecx
  hkaiNavMeshInstance *v5; // rdx
  char v7; // [rsp+8h] [rbp+8h]

  v2 = previousFaceKey != -1;
  if ( previousFaceKey != -1 )
  {
    v3 = previousFaceKey;
    v4 = previousFaceKey & 0x3FFFFF;
    v5 = collection->m_instances.m_data[v3 >> 22].m_instancePtr;
    if ( v5 && v4 < v5->m_numOriginalFaces + v5->m_ownedFaces.m_size )
    {
      v7 = v5->m_faceFlags.m_size ? v5->m_faceFlags.m_data[v4].m_storage : 0;
      if ( !(v7 & 1) )
        return 0;
    }
    v2 = 0;
  }
  return !v2;
}

// File Line: 54
// RVA: 0xC0D140
__int64 __fastcall hkaiNavMeshQueryMediator::coherentGetClosestPoint(hkaiNavMeshQueryMediator *this, hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator::GetClosestPointInput *input, hkaiNavMeshQueryMediator::CoherentInput *cinput, hkVector4f *closestPointOut)
{
  unsigned int v5; // ebx
  hkaiNavMeshQueryMediator *v6; // rdi
  hkaiNavMeshQueryMediator::CoherentInput *v7; // r13
  hkaiNavMeshQueryMediator::GetClosestPointInput *v8; // r14
  hkaiStreamingCollection *v9; // r15
  _QWORD *v10; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  unsigned int index; // esi
  hkaiNavMeshInstance *v14; // rdi
  hkaiSpatialQueryHitFilter *v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  hkaiNavMesh::Face *v24; // rax
  int v25; // ebp
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
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // esi
  hkaiNavMeshInstance *v43; // r15
  hkaiSpatialQueryHitFilter *v44; // rcx
  _QWORD *v45; // r8
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rax
  signed __int64 v48; // rcx
  _QWORD *v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // r8
  unsigned __int64 v52; // rax
  signed __int64 v53; // rcx
  hkVector4f projectionOut; // [rsp+30h] [rbp-88h]
  hkVector4f edgeA; // [rsp+40h] [rbp-78h]
  hkVector4f edgeB; // [rsp+50h] [rbp-68h]
  hkaiNavMeshQueryMediator *v58; // [rsp+C0h] [rbp+8h]
  hkaiStreamingCollection *v59; // [rsp+C8h] [rbp+10h]

  v59 = collection;
  v58 = this;
  v5 = cinput->m_previousFaceKey;
  _mm_store_si128((__m128i *)&projectionOut, (__m128i)input->m_position.m_quad);
  v6 = this;
  v7 = cinput;
  v8 = input;
  v9 = collection;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = v10[1];
  if ( v11 < v10[3] )
  {
    *(_QWORD *)v11 = "LtcoherentGCP";
    *(_QWORD *)(v11 + 16) = "StgetMesh";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    v10[1] = v11 + 24;
  }
  if ( needFullCheck(v5, v9) )
  {
LABEL_28:
    v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v46 = (_QWORD *)v45[1];
    if ( (unsigned __int64)v46 < v45[3] )
    {
      *v46 = "Stfull";
      v47 = __rdtsc();
      v48 = (signed __int64)(v46 + 2);
      *(_DWORD *)(v48 - 8) = v47;
      v45[1] = v48;
    }
    v5 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::GetClosestPointInput *, hkVector4f *))v6->vfptr[1].__first_virtual_table_function__)(
           v6,
           v8,
           &projectionOut);
    goto $foundPoint;
  }
  index = v7->m_previousFaceKey & 0x3FFFFF;
  v14 = v9->m_instances.m_data[v5 >> 22].m_instancePtr;
  v15 = v8->m_hitFilter;
  if ( v15
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v15->vfptr[2].__vecDelDtor)(
          v15,
          v14,
          index,
          v8->m_filterInfo,
          v8->m_userData) )
  {
    goto LABEL_36;
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Stprev";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
  if ( !isPointOnFaceAndProject(v14, index, &v8->m_position, v7, &projectionOut) )
  {
LABEL_36:
    v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v21 = (_QWORD *)v20[1];
    if ( (unsigned __int64)v21 < v20[3] )
    {
      *v21 = "Stneighbors";
      v22 = __rdtsc();
      v23 = (signed __int64)(v21 + 2);
      *(_DWORD *)(v23 - 8) = v22;
      v20[1] = v23;
    }
    v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__12(
            v14->m_originalFaces,
            v14->m_numOriginalFaces,
            &v14->m_instancedFaces,
            &v14->m_ownedFaces,
            &v14->m_faceMap,
            index);
    v25 = v24->m_startEdgeIndex;
    v26 = v24;
    v27 = _mm_sub_ps(v8->m_position.m_quad, v7->m_previousPoint.m_quad);
    v28 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v7->m_up.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v7->m_up.m_quad, v7->m_up.m_quad, 201), v27));
    v29 = _mm_shuffle_ps(v28, v28, 201);
    v30 = _mm_mul_ps(v7->m_previousPoint.m_quad, v29);
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
    if ( v25 < v25 + v24->m_numEdges )
    {
      do
      {
        v32 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__13(
                v14->m_originalEdges,
                v14->m_numOriginalEdges,
                &v14->m_instancedEdges,
                &v14->m_ownedEdges,
                &v14->m_edgeMap,
                v25);
        v33 = v32;
        if ( v32->m_oppositeEdge != -1 && !(v32->m_flags.m_storage & 0x20) )
        {
          hkaiNavMeshInstance::getEdgePoints(v14, v25, &edgeA, &edgeB);
          v34 = _mm_mul_ps(v31, edgeA.m_quad);
          v35 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v31), 196);
          v36 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 78), v35);
          v37 = _mm_mul_ps(edgeB.m_quad, v31);
          v38 = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v31), 196);
          v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
          if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 177)) + v36.m128_f32[0]) <= 0.0
            && (float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 177)) + v39.m128_f32[0]) >= 0.0 )
          {
            v40 = v33->m_oppositeFace;
            if ( v33->m_flags.m_storage & 0x40 )
              v41 = v40 & 0xFFC00000;
            else
              v41 = v14->m_runtimeId << 22;
            v5 = v41 | v40 & 0x3FFFFF;
            if ( v40 == -1 )
              v5 = -1;
            v42 = v5 & 0x3FFFFF;
            v43 = v9->m_instances.m_data[v5 >> 22].m_instancePtr;
            if ( v43 )
            {
              v44 = v8->m_hitFilter;
              if ( !v44
                || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v44->vfptr[2].__vecDelDtor)(
                     v44,
                     v43,
                     v42,
                     v8->m_filterInfo,
                     v8->m_userData) )
              {
                if ( isPointOnFaceAndProject(v43, v42, &v8->m_position, v7, &projectionOut) )
                  goto $foundPoint;
              }
            }
            v9 = v59;
          }
        }
        ++v25;
      }
      while ( v25 < v26->m_startEdgeIndex + v26->m_numEdges );
    }
    v6 = v58;
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
    v53 = (signed __int64)(v50 + 2);
    *(_DWORD *)(v53 - 8) = v52;
    v51[1] = v53;
  }
  return v5;
}

// File Line: 149
// RVA: 0xC0DB60
signed __int64 __fastcall isPointOnFaceAndCast(hkaiNavMeshInstance *meshInstance, hkaiNavMeshQueryMediator::RaycastInput *input, hkaiNavMeshQueryMediator::CoherentInput *cinput, hkSimdFloat32 *hitFractionOut)
{
  hkaiNavMeshQueryMediator::RaycastInput *v4; // rbx
  unsigned int v5; // edx
  hkSimdFloat32 *v6; // rdi
  hkaiNavMeshQueryMediator::CoherentInput *v7; // rsi
  __m128 v8; // xmm6
  __m128 v9; // xmm7
  __m128i v10; // xmm6
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  hkSimdFloat32 *hitFractionOuta[2]; // [rsp+20h] [rbp-68h]
  int faceIdx[4]; // [rsp+30h] [rbp-58h]
  __m128 v18; // [rsp+40h] [rbp-48h]
  __m128 v19; // [rsp+50h] [rbp-38h]

  v4 = input;
  v5 = cinput->m_previousFaceKey;
  v6 = hitFractionOut;
  v7 = cinput;
  v8 = v4->m_to.m_quad;
  v9 = v4->m_from.m_quad;
  *(_OWORD *)hitFractionOuta = 0i64;
  v10 = (__m128i)_mm_sub_ps(v8, v9);
  *(__m128 *)faceIdx = v9;
  v11 = _mm_cmpeqps((__m128)0i64, (__m128)v10);
  v12 = _mm_rcp_ps((__m128)v10);
  v18 = _mm_shuffle_ps((__m128)v10, _mm_unpackhi_ps((__m128)v10, query.m_quad), 196);
  v19 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v10, 0x1Fu), 0x1Fu), (__m128)_xmm), v11),
          _mm_andnot_ps(v11, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, (__m128)v10)), v12)));
  v19.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v18)) & 7 | 0x3F000000;
  if ( !(unsigned __int8)hkaiNavMeshUtils::castRayFace<hkaiNavMeshInstance>(
                           (hkaiNavMeshUtils *)meshInstance,
                           (hkaiNavMeshInstance *)(v5 & 0x3FFFFF),
                           (__int64)faceIdx,
                           (hkcdRay *)hitFractionOuta,
                           0i64) )
    return 0i64;
  v13 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(v4->m_to.m_quad, v4->m_from.m_quad), *(__m128 *)hitFractionOuta),
            v4->m_from.m_quad),
          v4->m_from.m_quad);
  v14 = _mm_mul_ps(v13, v13);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170))) >= (float)(v7->m_coherencyTolerance.m_real.m128_f32[0]
                                                                     * v7->m_coherencyTolerance.m_real.m128_f32[0]) )
    return 0i64;
  *v6 = *(hkSimdFloat32 *)hitFractionOuta;
  return 1i64;
}

// File Line: 169
// RVA: 0xC0DCA0
signed __int64 __fastcall isPointOnFaceAndCast_0(hkaiNavMeshInstance *meshInstance, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *input, hkaiNavMeshQueryMediator::CoherentInput *cinput, hkSimdFloat32 *hitFractionOut)
{
  hkaiNavMeshQueryMediator::BidirectionalRaycastInput *v4; // rbx
  unsigned int v5; // edx
  hkSimdFloat32 *v6; // rdi
  hkaiNavMeshQueryMediator::CoherentInput *v7; // rsi
  __m128 v8; // xmm6
  __m128 v9; // xmm7
  __m128 v10; // xmm0
  __m128 v11; // xmm7
  __m128i v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  signed __int64 result; // rax
  hkSimdFloat32 *hitFractionOuta[2]; // [rsp+20h] [rbp-68h]
  int faceIdx[4]; // [rsp+30h] [rbp-58h]
  __m128 v20; // [rsp+40h] [rbp-48h]
  __m128 v21; // [rsp+50h] [rbp-38h]

  v4 = input;
  v5 = cinput->m_previousFaceKey;
  v6 = hitFractionOut;
  v7 = cinput;
  v8 = v4->m_forwardTo.m_quad;
  v9 = v4->m_center.m_quad;
  v10 = v4->m_forwardTo.m_quad;
  *(_OWORD *)hitFractionOuta = 0i64;
  v11 = _mm_sub_ps(v9, _mm_sub_ps(v10, v9));
  v12 = (__m128i)_mm_sub_ps(v8, v11);
  *(__m128 *)faceIdx = v11;
  v13 = _mm_cmpeqps((__m128)0i64, (__m128)v12);
  v14 = _mm_rcp_ps((__m128)v12);
  v20 = _mm_shuffle_ps((__m128)v12, _mm_unpackhi_ps((__m128)v12, query.m_quad), 196);
  v21 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu), (__m128)_xmm), v13),
          _mm_andnot_ps(v13, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v12, v14)), v14)));
  v21.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v20)) & 7 | 0x3F000000;
  if ( !(unsigned __int8)hkaiNavMeshUtils::castRayFace<hkaiNavMeshInstance>(
                           (hkaiNavMeshUtils *)meshInstance,
                           (hkaiNavMeshInstance *)(v5 & 0x3FFFFF),
                           (__int64)faceIdx,
                           (hkcdRay *)hitFractionOuta,
                           0i64) )
    return 0i64;
  v15 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v4->m_forwardTo.m_quad, v11), *(__m128 *)hitFractionOuta), v11),
          v4->m_center.m_quad);
  v16 = _mm_mul_ps(v15, v15);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170))) >= (float)(v7->m_coherencyTolerance.m_real.m128_f32[0]
                                                                     * v7->m_coherencyTolerance.m_real.m128_f32[0]) )
    return 0i64;
  result = 1i64;
  v6->m_real = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A710D0, *(__m128 *)hitFractionOuta), g_vectorfConstants[0]);
  return result;
}

// File Line: 192
// RVA: 0xC0D5C0
__int64 __fastcall hkaiNavMeshQueryMediator::coherentCastRay(hkaiNavMeshQueryMediator *this, hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator::RaycastInput *input, hkaiNavMeshQueryMediator::CoherentInput *cinput, hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  unsigned int v5; // esi
  hkaiNavMeshQueryMediator *v6; // r14
  hkaiNavMeshQueryMediator::CoherentInput *v7; // rbp
  hkaiNavMeshQueryMediator::RaycastInput *v8; // rdi
  hkaiStreamingCollection *v9; // rbx
  _QWORD *v10; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  hkaiNavMeshInstance *v13; // rbx
  hkaiSpatialQueryHitFilter *v14; // rcx
  _QWORD *v15; // r9
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rax
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  __m128 v20; // xmm0
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  hkSimdFloat32 hitFractionOut; // [rsp+30h] [rbp-18h]

  v5 = cinput->m_previousFaceKey;
  v6 = this;
  v7 = cinput;
  v8 = input;
  v9 = collection;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = v10[1];
  if ( v11 < v10[3] )
  {
    *(_QWORD *)v11 = "LtcoherentRc";
    *(_QWORD *)(v11 + 16) = "StgetMesh";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    v10[1] = v11 + 24;
  }
  if ( needFullCheck(v5, v9) )
    goto LABEL_18;
  v13 = v9->m_instances.m_data[v5 >> 22].m_instancePtr;
  v14 = v8->m_hitFilter;
  if ( v14 )
  {
    if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, signed __int64, _QWORD, unsigned __int64))v14->vfptr[2].__vecDelDtor)(
            v14,
            v13,
            0xFFFFFFFFi64,
            v8->m_filterInfo,
            v8->m_userData) )
      goto LABEL_18;
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
  v18 = isPointOnFaceAndCast(v13, v8, v7, &hitFractionOut);
  v19 = v18 != 0;
  if ( !v18 )
  {
LABEL_18:
    v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v22 = (_QWORD *)v21[1];
    if ( (unsigned __int64)v22 < v21[3] )
    {
      *v22 = "Stfull";
      v23 = __rdtsc();
      v24 = (signed __int64)(v22 + 2);
      *(_DWORD *)(v24 - 8) = v23;
      v21[1] = v24;
    }
    v19 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::RaycastInput *, hkaiNavMeshQueryMediator::HitDetails *))v6->vfptr[2].__first_virtual_table_function__)(
            v6,
            v8,
            hitOut);
  }
  else
  {
    v20 = hitFractionOut.m_real;
    hitOut->m_hitFaceKey = v5;
    hitOut->m_hitFraction.m_real = v20;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "lt";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v25[1] = v28;
  }
  return v19;
}

// File Line: 236
// RVA: 0xC0D7A0
__int64 __fastcall hkaiNavMeshQueryMediator::coherentCastBidirectionalRay(hkaiNavMeshQueryMediator *this, hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *input, hkaiNavMeshQueryMediator::CoherentInput *cinput, hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  unsigned int v5; // esi
  hkaiNavMeshQueryMediator *v6; // r14
  hkaiNavMeshQueryMediator::CoherentInput *v7; // rbp
  hkaiNavMeshQueryMediator::BidirectionalRaycastInput *v8; // rdi
  hkaiStreamingCollection *v9; // rbx
  _QWORD *v10; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  hkaiNavMeshInstance *v13; // rbx
  hkaiSpatialQueryHitFilter *v14; // rcx
  _QWORD *v15; // r9
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rax
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  __m128 v20; // xmm0
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  hkSimdFloat32 hitFractionOut; // [rsp+30h] [rbp-18h]

  v5 = cinput->m_previousFaceKey;
  v6 = this;
  v7 = cinput;
  v8 = input;
  v9 = collection;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = v10[1];
  if ( v11 < v10[3] )
  {
    *(_QWORD *)v11 = "LtcoherentBrc";
    *(_QWORD *)(v11 + 16) = "StgetMesh";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    v10[1] = v11 + 24;
  }
  if ( needFullCheck(v5, v9) )
    goto LABEL_18;
  v13 = v9->m_instances.m_data[v5 >> 22].m_instancePtr;
  v14 = v8->m_hitFilter;
  if ( v14 )
  {
    if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, signed __int64, _QWORD, unsigned __int64))v14->vfptr[2].__vecDelDtor)(
            v14,
            v13,
            0xFFFFFFFFi64,
            v8->m_filterInfo,
            v8->m_userData) )
      goto LABEL_18;
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
  v18 = isPointOnFaceAndCast_0(v13, v8, v7, &hitFractionOut);
  v19 = v18 != 0;
  if ( !v18 )
  {
LABEL_18:
    v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v22 = (_QWORD *)v21[1];
    if ( (unsigned __int64)v22 < v21[3] )
    {
      *v22 = "Stfull";
      v23 = __rdtsc();
      v24 = (signed __int64)(v22 + 2);
      *(_DWORD *)(v24 - 8) = v23;
      v21[1] = v24;
    }
    v19 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *, hkaiNavMeshQueryMediator::HitDetails *))v6->vfptr[3].__vecDelDtor)(
            v6,
            v8,
            hitOut);
  }
  else
  {
    v20 = hitFractionOut.m_real;
    hitOut->m_hitFaceKey = v5;
    hitOut->m_hitFraction.m_real = v20;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "lt";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v25[1] = v28;
  }
  return v19;
}

// File Line: 279
// RVA: 0xC0D020
char __fastcall hkaiNavMeshQueryMediator::castBidirectionalRay(hkaiNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::BidirectionalRaycastInput *input, hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  __int128 v3; // xmm1
  hkaiNavMeshQueryMediator::HitDetails *v4; // rdi
  hkaiNavMeshQueryMediator::BidirectionalRaycastInput *v5; // rbx
  hkaiNavMeshQueryMediator *v6; // r14
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm0
  char v9; // si
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  int v12; // eax
  char result; // al
  __m128 v14; // xmm0
  __m128 v15; // [rsp+20h] [rbp-98h]
  unsigned int v16; // [rsp+30h] [rbp-88h]
  __int128 v17; // [rsp+40h] [rbp-78h]
  __int128 v18; // [rsp+50h] [rbp-68h]
  hkTransformf *v19; // [rsp+60h] [rbp-58h]
  __m128 v20; // [rsp+70h] [rbp-48h]
  __m128 v21; // [rsp+80h] [rbp-38h]
  __m128 v22; // [rsp+90h] [rbp-28h]
  int v23; // [rsp+A0h] [rbp-18h]

  v3 = *(_OWORD *)&input->m_hitFilter;
  v4 = hitOut;
  v5 = input;
  v6 = this;
  v17 = *(_OWORD *)&input->m_filterInfo;
  v18 = v3;
  v7.m_quad = (__m128)input->m_center;
  v19 = input->m_localToWorldTransform;
  v8.m_quad = (__m128)input->m_forwardTo;
  v20 = v7.m_quad;
  v21 = v8.m_quad;
  v9 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, __int128 *, __m128 *))this->vfptr[2].__first_virtual_table_function__)(
         this,
         &v17,
         &v15);
  v10 = _mm_add_ps(
          _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v5->m_forwardTo.m_quad),
          _mm_mul_ps(v5->m_center.m_quad, (__m128)xmmword_141A710D0));
  v21 = v10;
  if ( v9 )
    v21 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v10, v20), v15), v20);
  if ( ((unsigned __int8 (__fastcall *)(hkaiNavMeshQueryMediator *, __int128 *, __m128 *))v6->vfptr[2].__first_virtual_table_function__)(
         v6,
         &v17,
         &v22) )
  {
    v11 = _mm_sub_ps((__m128)0i64, v22);
    if ( v9 )
      v11 = _mm_mul_ps(v11, v15);
    v12 = v23;
    v4->m_hitFraction.m_real = v11;
    v4->m_hitFaceKey = v12;
    result = 1;
  }
  else if ( v9 )
  {
    v14 = v15;
    v4->m_hitFaceKey = v16;
    result = 1;
    v4->m_hitFraction.m_real = v14;
  }
  else
  {
    result = 0;
  }
  return result;
}

