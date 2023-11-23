// File Line: 37
// RVA: 0xBD6A10
void __fastcall hkaiStreamingUtils::FindEdgeOverlapInput::FindEdgeOverlapInput(
        hkaiStreamingUtils::FindEdgeOverlapInput *this)
{
  *(_QWORD *)&this->m_uidA = -1i64;
  this->m_edgeMatchTolerance = 0.0099999998;
  this->m_meshA = 0i64;
  this->m_meshB = 0i64;
  this->m_mediatorA = 0i64;
  this->m_mediatorB = 0i64;
  this->m_graphA = 0i64;
  this->m_graphB = 0i64;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchingParams);
  this->m_up.m_quad = _xmm;
  this->m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transformA.m_translation = 0i64;
  this->m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transformB.m_translation = 0i64;
}

// File Line: 44
// RVA: 0xBD6AD0
void __fastcall hkaiStreamingUtils::findPotentialDependencies(
        hkArrayBase<hkAabb> *aabbs,
        hkArray<hkKeyPair,hkContainerTempAllocator> *pairs,
        float _tolerance)
{
  _QWORD *Value; // rax
  _QWORD *v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  __int64 m_size; // r13
  __m128 v11; // xmm6
  hkLifoAllocator *v12; // rax
  hk1AxisSweep::AabbInt *m_cur; // rbx
  int v14; // edx
  char *v15; // rcx
  __int64 v16; // r14
  __int64 v17; // r15
  int v18; // edi
  hkAabb *m_data; // rax
  hkVector4f v20; // xmm0
  __int64 v21; // rax
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm1
  hkVector4f *v24; // rax
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  hkKeyPair *v28; // r8
  int v29; // r9d
  int v30; // eax
  hkResultEnum m_enum; // ecx
  int m_capacityAndFlags; // eax
  int v33; // eax
  int v34; // r9d
  int v35; // eax
  hkKeyPair *v36; // r8
  int v37; // r9d
  int v38; // ebp
  hkLifoAllocator *v39; // rax
  int v40; // r8d
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  hkAabb aabbIn; // [rsp+30h] [rbp-68h] BYREF
  hkResult result; // [rsp+A0h] [rbp+8h] BYREF
  hkResult v47; // [rsp+A8h] [rbp+10h] BYREF
  unsigned int v48; // [rsp+B0h] [rbp+18h]

  v48 = LODWORD(_tolerance);
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  v7 = Value;
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TtFindDepend";
    v8 = __rdtsc();
    v9 = v6 + 2;
    *((_DWORD *)v9 - 2) = v8;
    v7[1] = v9;
  }
  m_size = aabbs->m_size;
  v11 = _mm_shuffle_ps((__m128)v48, (__m128)v48, 0);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hk1AxisSweep::AabbInt *)v12->m_cur;
  v14 = (32 * (m_size + 4) + 127) & 0xFFFFFF80;
  v15 = (char *)m_cur + v14;
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    m_cur = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  else
    v12->m_cur = v15;
  v16 = 0i64;
  v17 = m_size;
  v18 = 0;
  if ( (int)m_size > 0 )
  {
    do
    {
      m_data = aabbs->m_data;
      aabbIn.m_min = aabbs->m_data[v16].m_min;
      v20.m_quad = _mm_add_ps(m_data[v16].m_max.m_quad, v11);
      aabbIn.m_min.m_quad = _mm_sub_ps(aabbIn.m_min.m_quad, v11);
      aabbIn.m_max = (hkVector4f)v20.m_quad;
      hk1AxisSweep::AabbInt::set(&m_cur[v18], &aabbIn, v18);
      ++v18;
      ++v16;
      --v17;
    }
    while ( v17 );
  }
  v21 = aabbs->m_size;
  v22.m_quad = (__m128)aabbIn.m_max;
  aabbIn.m_min.m_quad.m128_i32[0] = -1;
  v23.m_quad = (__m128)aabbIn.m_min;
  v24 = (hkVector4f *)&m_cur[v21];
  *v24 = aabbIn.m_min;
  v24[1] = (hkVector4f)v22.m_quad;
  v24[2] = (hkVector4f)v23.m_quad;
  v24[3] = (hkVector4f)v22.m_quad;
  v24[4] = (hkVector4f)v23.m_quad;
  v24[5] = (hkVector4f)v22.m_quad;
  v24[6] = (hkVector4f)v23.m_quad;
  v24[7] = (hkVector4f)v22.m_quad;
  hk1AxisSweep::sortAabbs(m_cur, m_size);
  v25 = pairs->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < (int)m_size )
  {
    v26 = 2 * v25;
    v27 = m_size;
    if ( (int)m_size < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, pairs, v27, 8);
  }
  v28 = pairs->m_data;
  v29 = pairs->m_capacityAndFlags & 0x3FFFFFFF;
  result.m_enum = HK_SUCCESS;
  v30 = hk1AxisSweep::collide(m_cur, m_size, v28, v29, (hkPadSpu<int> *)&result);
  m_enum = result.m_enum;
  if ( result.m_enum > HK_SUCCESS )
  {
    m_capacityAndFlags = pairs->m_capacityAndFlags;
    pairs->m_size = 0;
    v33 = m_capacityAndFlags & 0x3FFFFFFF;
    v34 = v33 + m_enum;
    if ( v33 < v33 + m_enum )
    {
      v35 = 2 * v33;
      if ( v34 < v35 )
        v34 = v35;
      hkArrayUtil::_reserve(&v47, &hkContainerTempAllocator::s_alloc, pairs, v34, 8);
    }
    v36 = pairs->m_data;
    v37 = pairs->m_capacityAndFlags & 0x3FFFFFFF;
    result.m_enum = HK_SUCCESS;
    v30 = hk1AxisSweep::collide(m_cur, m_size, v36, v37, (hkPadSpu<int> *)&result);
  }
  pairs->m_size = v30;
  v38 = (32 * (m_size + 4) + 127) & 0xFFFFFF80;
  v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v40 = (v38 + 15) & 0xFFFFFFF0;
  if ( v38 > v39->m_slabSize || (char *)m_cur + v40 != v39->m_cur || v39->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v39, m_cur, v40);
  else
    v39->m_cur = m_cur;
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "Et";
    v43 = __rdtsc();
    v44 = v42 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v41[1] = v44;
  }
}

// File Line: 92
// RVA: 0xBD6DA0
void __fastcall hkaiStreamingUtils::collectBoundaryEdges(
        hkaiNavMeshInstance *instance,
        hkaiNavMeshQueryMediator *mediator,
        hkAabb *otherAabb,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *aabbsInt,
        hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *facesEdges,
        hkSimdFloat32 *tolerance)
{
  int v8; // edi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  __int64 v12; // r14
  int m_numOriginalEdges; // r15d
  hkaiNavMesh::Edge *m_originalEdges; // r12
  int index; // esi
  int *v16; // rax
  int v17; // r8d
  bool v18; // zf
  int v19; // ecx
  hkaiNavMesh::Edge *v20; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  hkVector4f *v23; // rcx
  hkVector4f v24; // xmm4
  hkVector4f v25; // xmm5
  __int64 m_b; // rax
  hkVector4f v27; // xmm6
  hkVector4f v28; // xmm7
  __m128 v29; // xmm3
  hkVector4f *v30; // rax
  __m128 v31; // xmm2
  hkVector4f v32; // xmm1
  int v33; // eax
  hk1AxisSweep::AabbInt *v34; // rcx
  hkAabb aabbIn; // [rsp+30h] [rbp-68h] BYREF

  hkaiNavMeshUtils::getEdgesInsideAabb(instance, mediator, otherAabb, facesEdges);
  v8 = 0;
  if ( facesEdges->m_size > 0 )
  {
    instanceMap = &instance->m_edgeMap;
    p_m_ownedEdges = &instance->m_ownedEdges;
    p_m_instancedEdges = &instance->m_instancedEdges;
    v12 = 0i64;
    do
    {
      m_numOriginalEdges = instance->m_numOriginalEdges;
      m_originalEdges = instance->m_originalEdges;
      index = facesEdges->m_data[v12].m_edgeKey & 0x3FFFFF;
      v16 = (int *)hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
                     m_originalEdges,
                     m_numOriginalEdges,
                     p_m_instancedEdges,
                     p_m_ownedEdges,
                     instanceMap,
                     index);
      v17 = v16[3];
      v18 = v16[2] == -1;
      aabbIn.m_min.m_quad.m128_i32[0] = *v16;
      v19 = v16[1];
      aabbIn.m_max.m_quad.m128_i32[0] = v16[4];
      aabbIn.m_min.m_quad.m128_i32[1] = v19;
      aabbIn.m_min.m_quad.m128_i32[3] = v17;
      if ( v18 )
      {
        v20 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
                m_originalEdges,
                m_numOriginalEdges,
                &instance->m_instancedEdges,
                &instance->m_ownedEdges,
                &instance->m_edgeMap,
                index);
        m_numOriginalVertices = instance->m_numOriginalVertices;
        m_a = v20->m_a;
        if ( (int)m_a >= m_numOriginalVertices )
          v23 = &instance->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
        else
          v23 = &instance->m_originalVertices[m_a];
        v24.m_quad = (__m128)instance->m_referenceFrame.m_transform.m_rotation.m_col1;
        v25.m_quad = (__m128)instance->m_referenceFrame.m_transform.m_rotation.m_col0;
        m_b = v20->m_b;
        v27.m_quad = (__m128)instance->m_referenceFrame.m_transform.m_rotation.m_col2;
        v28.m_quad = (__m128)instance->m_referenceFrame.m_transform.m_translation;
        v29 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v23->m_quad, v23->m_quad, 0), v25.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v23->m_quad, v23->m_quad, 85), v24.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v23->m_quad, v23->m_quad, 170), v27.m_quad)),
                v28.m_quad);
        if ( (int)m_b >= m_numOriginalVertices )
          v30 = &instance->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
        else
          v30 = &instance->m_originalVertices[m_b];
        v31 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v30->m_quad, v30->m_quad, 0), v25.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v30->m_quad, v30->m_quad, 85), v24.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v30->m_quad, v30->m_quad, 170), v27.m_quad)),
                v28.m_quad);
        v32.m_quad = _mm_sub_ps(_mm_min_ps(v29, v31), tolerance->m_real);
        v33 = aabbsInt->m_capacityAndFlags & 0x3FFFFFFF;
        aabbIn.m_max.m_quad = _mm_add_ps(_mm_max_ps(v29, v31), tolerance->m_real);
        aabbIn.m_min = (hkVector4f)v32.m_quad;
        if ( aabbsInt->m_size == v33 )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, aabbsInt, 32);
        v34 = &aabbsInt->m_data[aabbsInt->m_size++];
        hk1AxisSweep::AabbInt::set(v34, &aabbIn, v8);
      }
      ++v8;
      ++v12;
      instanceMap = &instance->m_edgeMap;
      p_m_ownedEdges = &instance->m_ownedEdges;
      p_m_instancedEdges = &instance->m_instancedEdges;
    }
    while ( v8 < facesEdges->m_size );
  }
}

// File Line: 122
// RVA: 0xBD7130
void __fastcall hkaiStreamingUtils::findEdgeOverlaps(
        hkaiStreamingUtils::FindEdgeOverlapInput *input,
        hkaiStreamingSet *meshSetA,
        hkaiStreamingSet *meshSetB,
        hkaiStreamingSet *graphSetA,
        hkaiStreamingSet *graphSetB)
{
  hkaiStreamingSet *v5; // rbx
  hkaiStreamingSet *v6; // r13
  hkaiNavMesh *m_meshB; // r14
  void *m_meshA; // r15
  _QWORD *Value; // r10
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rax
  hkVector4f v13; // xmm1
  __int128 *v14; // rcx
  __int64 v15; // rdx
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm0
  hkVector4f v19; // xmm1
  hkVector4f v20; // xmm0
  hkVector4f v21; // xmm1
  unsigned int v22; // xmm2_4
  __m128 v23; // xmm7
  hkAabb *v24; // rax
  __m128 v25; // xmm8
  __m128 v26; // xmm10
  __m128 v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  hkVector4f v34; // xmm1
  hkVector4f v35; // xmm0
  hkVector4f v36; // xmm1
  hkaiNavMeshQueryMediator *m_mediatorA; // rdx
  hkVector4f v38; // xmm0
  hkVector4f v39; // xmm1
  __m128 m_edgeMatchTolerance_low; // xmm11
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> v41; // xmm11
  hkVector4f v42; // xmm0
  hkVector4f v43; // xmm1
  int v44; // edi
  hkArray<hkVector4f,hkContainerHeapAllocator> m_vertices; // xmm6
  int m_size; // r14d
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> m_edges; // xmm7
  __int64 v48; // rbx
  hkBaseObjectVtbl *v49; // rax
  hk1AxisSweep::AabbInt *v50; // rax
  _QWORD *v51; // r8
  _QWORD *v52; // rcx
  unsigned __int64 v53; // rax
  _QWORD *v54; // rcx
  _QWORD *v55; // r8
  _QWORD *v56; // rcx
  unsigned __int64 v57; // rax
  _QWORD *v58; // rcx
  hkaiStreamingSet *m_data; // r8
  hkBaseObjectVtbl *vfptr; // rdx
  float m_edgeMatchTolerance; // xmm0_4
  float v62; // xmm10_4
  float v63; // xmm10_4
  unsigned int m_thisUid; // eax
  bool v65; // cf
  bool v66; // zf
  hkVector4f *v67; // rax
  int *v68; // rcx
  __int64 v69; // r14
  __int64 v70; // r12
  unsigned __int64 v71; // r15
  __int64 v72; // rbx
  unsigned __int64 v73; // r13
  __int64 edgeIdxB; // rdi
  hkaiNavMesh::Edge *v75; // rax
  __int64 m_a; // rcx
  hkVector4f *v77; // rcx
  __int64 m_b; // rax
  __m128 v79; // xmm6
  hkVector4f *v80; // rax
  __m128 v81; // xmm7
  __m128 v82; // xmm2
  __m128 v83; // xmm2
  hkaiNavMesh::Edge *v84; // rax
  __int64 v85; // rcx
  hkVector4f *v86; // rcx
  __int64 v87; // rax
  __m128 v88; // xmm3
  hkVector4f *v89; // rax
  __m128 v90; // xmm4
  __m128 v91; // xmm2
  __m128 v92; // xmm2
  int v93; // edx
  int faceIdxB; // eax
  int v95; // r10d
  int v96; // r9d
  int v97; // r9d
  int v98; // r11d
  int v99; // ecx
  int v100; // edx
  int v101; // r10d
  int m_faceDataStriding; // r9d
  int v103; // r9d
  int v104; // r11d
  int v105; // ecx
  int v106; // edx
  _QWORD *v107; // r8
  _QWORD *v108; // rcx
  unsigned __int64 v109; // rax
  _QWORD *v110; // rcx
  unsigned int *m_min; // rdx
  unsigned int v112; // eax
  unsigned __int64 v113; // rax
  unsigned __int64 v114; // rdx
  __int64 v115; // rcx
  int v116; // ebx
  int v117; // r9d
  __int64 v118; // rcx
  int v119; // r8d
  int v120; // edi
  int v121; // r10d
  int v122; // ecx
  int v123; // edx
  int v124; // eax
  int v125; // r8d
  int v126; // ecx
  int v127; // edx
  int v128; // eax
  int v129; // ecx
  hkBaseObjectVtbl *v130; // rcx
  hkaiNavMesh *sectionB; // r14
  __int64 v132; // rbx
  int v133; // ecx
  int v134; // edi
  hkaiStreamingSet *v135; // r12
  _QWORD *v136; // rax
  _QWORD *v137; // rcx
  _QWORD *v138; // r8
  unsigned __int64 v139; // rax
  _QWORD *v140; // rcx
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> array; // [rsp+60h] [rbp-80h] BYREF
  hkaiNavMesh aabbsInt; // [rsp+70h] [rbp-70h] BYREF
  unsigned int v143; // [rsp+120h] [rbp+40h]
  hkaiNavMesh *meshA; // [rsp+128h] [rbp+48h]
  hkAabb v145; // [rsp+130h] [rbp+50h] BYREF
  hkAabb v146; // [rsp+150h] [rbp+70h]
  hkResult result; // [rsp+170h] [rbp+90h] BYREF
  hkAabb otherAabb; // [rsp+180h] [rbp+A0h] BYREF
  hkAabb v149; // [rsp+1A0h] [rbp+C0h] BYREF
  hkVector4f v150; // [rsp+1C0h] [rbp+E0h]
  __m128 m_quad; // [rsp+1D0h] [rbp+F0h]
  __int128 v152[6]; // [rsp+1E0h] [rbp+100h] BYREF
  hkaiNavMeshInstance meshInstanceB; // [rsp+240h] [rbp+160h] BYREF
  hkaiNavMeshInstance instance; // [rsp+420h] [rbp+340h] BYREF
  hkaiStreamingSet *meshSetAa; // [rsp+6A8h] [rbp+5C8h] BYREF
  hkaiStreamingSet *vars0; // [rsp+6B0h] [rbp+5D0h]
  hkaiStreamingSet *retaddr; // [rsp+6B8h] [rbp+5D8h]
  hkaiStreamingSet *v158; // [rsp+6C0h] [rbp+5E0h]

  v6 = meshSetA;
  if ( meshSetA->m_thisUid != meshSetB->m_thisUid )
  {
    v158 = v5;
    m_meshB = input->m_meshB;
    m_meshA = input->m_meshA;
    aabbsInt.m_faces.m_data = (hkaiNavMesh::Face *)input->m_meshA;
    meshA = m_meshB;
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = Value[1];
    if ( v11 < Value[3] )
    {
      *(_QWORD *)v11 = "LtfindEdgeOverlaps";
      *(_QWORD *)(v11 + 16) = "StcollectAabbInt";
      v12 = __rdtsc();
      *(_DWORD *)(v11 + 8) = v12;
      Value[1] = v11 + 24;
    }
    v13.m_quad = (__m128)*((_OWORD *)m_meshA + 9);
    v14 = v152;
    v15 = 2i64;
    v145.m_min = (hkVector4f)*((_OWORD *)m_meshA + 8);
    v16.m_quad = (__m128)m_meshB->m_aabb.m_min;
    v145.m_max = (hkVector4f)v13.m_quad;
    v17.m_quad = (__m128)m_meshB->m_aabb.m_max;
    v146.m_min = (hkVector4f)v16.m_quad;
    v150.m_quad = (__m128)input->m_transformA.m_rotation.m_col0;
    v18.m_quad = (__m128)input->m_transformA.m_rotation.m_col2;
    v146.m_max = (hkVector4f)v17.m_quad;
    v19.m_quad = (__m128)input->m_transformA.m_rotation.m_col1;
    v152[0] = (__int128)v18.m_quad;
    v152[2] = (__int128)input->m_transformB.m_rotation.m_col0;
    v20.m_quad = (__m128)input->m_transformB.m_rotation.m_col2;
    m_quad = v19.m_quad;
    v21.m_quad = (__m128)input->m_transformA.m_translation;
    v152[4] = (__int128)v20.m_quad;
    array.m_size = LODWORD(input->m_edgeMatchingParams.m_maxStepHeight);
    v20.m_quad.m128_i32[0] = LODWORD(input->m_edgeMatchTolerance);
    v152[1] = (__int128)v21.m_quad;
    v152[3] = (__int128)input->m_transformB.m_rotation.m_col1;
    v152[5] = (__int128)input->m_transformB.m_translation;
    array.m_size = fmaxf(input->m_edgeMatchingParams.m_maxSeparation, *(float *)&array.m_size);
    *(float *)&v22 = fmaxf(v20.m_quad.m128_f32[0], *(float *)&array.m_size);
    *(float *)&array.m_data = FLOAT_0_050000001;
    v23 = _mm_shuffle_ps((__m128)v22, (__m128)v22, 0);
    v24 = &v145;
    v25 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
    v26 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v27 = v24->m_min.m_quad;
      v28 = v24->m_max.m_quad;
      ++v24;
      v14 += 4;
      v29 = _mm_mul_ps(_mm_sub_ps(v28, v27), (__m128)xmmword_141A711B0);
      v30 = _mm_mul_ps(_mm_add_ps(v27, v24[-1].m_max.m_quad), (__m128)xmmword_141A711B0);
      v31 = _mm_add_ps(v29, _mm_max_ps(_mm_mul_ps(v25, v29), v23));
      v32 = _mm_add_ps(
              _mm_add_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), *((__m128 *)v14 - 6)), 1u),
                          1u),
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), *((__m128 *)v14 - 5)), 1u),
                          1u)),
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), *((__m128 *)v14 - 4)), 1u),
                        1u));
      v33 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), *((__m128 *)v14 - 6)),
                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), *((__m128 *)v14 - 5))),
                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), *((__m128 *)v14 - 4))),
              *((__m128 *)v14 - 3));
      v24[-1].m_max.m_quad = _mm_add_ps(v33, v32);
      v24[-1].m_min.m_quad = _mm_add_ps(_mm_xor_ps(v26, v32), v33);
      --v15;
    }
    while ( v15 );
    v149 = v145;
    otherAabb = v146;
    hkaiNavMeshInstance::hkaiNavMeshInstance(&instance);
    hkaiNavMeshInstance::tempInit(&instance, (hkaiNavMesh *)m_meshA, 0);
    v34.m_quad = (__m128)input->m_transformA.m_rotation.m_col1;
    instance.m_referenceFrame.m_transform.m_rotation.m_col0 = input->m_transformA.m_rotation.m_col0;
    v35.m_quad = (__m128)input->m_transformA.m_rotation.m_col2;
    instance.m_referenceFrame.m_transform.m_rotation.m_col1 = (hkVector4f)v34.m_quad;
    v36.m_quad = (__m128)input->m_transformA.m_translation;
    instance.m_referenceFrame.m_transform.m_rotation.m_col2 = (hkVector4f)v35.m_quad;
    instance.m_referenceFrame.m_transform.m_translation = (hkVector4f)v36.m_quad;
    hkaiNavMeshInstance::hkaiNavMeshInstance(&meshInstanceB);
    hkaiNavMeshInstance::tempInit(&meshInstanceB, m_meshB, 0);
    m_mediatorA = input->m_mediatorA;
    v38.m_quad = (__m128)input->m_transformB.m_rotation.m_col0;
    v39.m_quad = (__m128)input->m_transformB.m_rotation.m_col1;
    m_edgeMatchTolerance_low = (__m128)LODWORD(input->m_edgeMatchTolerance);
    aabbsInt.m_aabb.m_min.m_quad.m128_u64[0] = 0i64;
    aabbsInt.m_aabb.m_min.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    aabbsInt.m_aabb.m_max.m_quad.m128_u64[0] = 0i64;
    v41 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator>)_mm_shuffle_ps(
                                                                 m_edgeMatchTolerance_low,
                                                                 m_edgeMatchTolerance_low,
                                                                 0);
    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col0 = (hkVector4f)v38.m_quad;
    v42.m_quad = (__m128)input->m_transformB.m_rotation.m_col2;
    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col1 = (hkVector4f)v39.m_quad;
    aabbsInt.m_aabb.m_max.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    aabbsInt.vfptr = 0i64;
    *(_DWORD *)&aabbsInt.m_memSizeAndFlags = 0;
    v43.m_quad = (__m128)input->m_transformB.m_translation;
    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col2 = (hkVector4f)v42.m_quad;
    aabbsInt.m_edges = v41;
    array.m_data = 0i64;
    array.m_size = 0;
    meshInstanceB.m_referenceFrame.m_transform.m_translation = (hkVector4f)v43.m_quad;
    *(_DWORD *)(&aabbsInt.m_referenceCount + 1) = 0x80000000;
    array.m_capacityAndFlags = 0x80000000;
    hkaiStreamingUtils::collectBoundaryEdges(
      &instance,
      m_mediatorA,
      &otherAabb,
      (hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *)&aabbsInt,
      (hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *)&aabbsInt.m_aabb,
      (hkSimdFloat32 *)&aabbsInt.m_edges);
    hkaiStreamingUtils::collectBoundaryEdges(
      &meshInstanceB,
      input->m_mediatorB,
      &v149,
      &array,
      (hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *)&aabbsInt.m_aabb.m_max,
      (hkSimdFloat32 *)&aabbsInt.m_edges);
    v44 = *(_DWORD *)&aabbsInt.m_memSizeAndFlags;
    m_vertices = aabbsInt.m_vertices;
    m_size = array.m_size;
    LODWORD(aabbsInt.m_edges.m_data) = -1;
    array.m_size = *(_DWORD *)&aabbsInt.m_memSizeAndFlags;
    m_edges = aabbsInt.m_edges;
    v143 = m_size;
    v48 = 4i64;
    do
    {
      if ( *(_DWORD *)&aabbsInt.m_memSizeAndFlags == (*(_DWORD *)(&aabbsInt.m_referenceCount + 1) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &aabbsInt, 32);
      v49 = &aabbsInt.vfptr[2 * *(int *)&aabbsInt.m_memSizeAndFlags];
      if ( v49 )
      {
        *(hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)v49 = m_edges;
        v49[1] = (hkBaseObjectVtbl)m_vertices;
      }
      ++*(_DWORD *)&aabbsInt.m_memSizeAndFlags;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 32);
      v50 = &array.m_data[array.m_size];
      if ( v50 )
      {
        *(hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)v50->m_min = m_edges;
        *(hkArray<hkVector4f,hkContainerHeapAllocator> *)v50->m_max = m_vertices;
      }
      ++array.m_size;
      --v48;
    }
    while ( v48 );
    v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v52 = (_QWORD *)v51[1];
    if ( (unsigned __int64)v52 < v51[3] )
    {
      *v52 = "Stsort";
      v53 = __rdtsc();
      v54 = v52 + 2;
      *((_DWORD *)v54 - 2) = v53;
      v51[1] = v54;
    }
    hk1AxisSweep::sortAabbs((hk1AxisSweep::AabbInt *)aabbsInt.vfptr, v44);
    hk1AxisSweep::sortAabbs(array.m_data, m_size);
    v55 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v56 = (_QWORD *)v55[1];
    if ( (unsigned __int64)v56 < v55[3] )
    {
      *v56 = "Stquick match";
      v57 = __rdtsc();
      v58 = v56 + 2;
      *((_DWORD *)v58 - 2) = v57;
      v55[1] = v58;
    }
    m_data = (hkaiStreamingSet *)array.m_data;
    vfptr = aabbsInt.vfptr;
    m_edgeMatchTolerance = input->m_edgeMatchTolerance;
    aabbsInt.m_faceData.m_capacityAndFlags = 0x80000000;
    aabbsInt.m_edgeDataStriding = 0x80000000;
    aabbsInt.m_faceData.m_data = 0i64;
    aabbsInt.m_faceData.m_size = 0;
    *(float *)&array.m_data = m_edgeMatchTolerance * 2.0;
    v62 = _mm_shuffle_ps((__m128)LODWORD(array.m_data), (__m128)LODWORD(array.m_data), 0).m128_f32[0];
    v63 = v62 * v62;
    LODWORD(aabbsInt.m_edgeData.m_data) = 0;
    *(_QWORD *)&aabbsInt.m_edgeData.m_size = 0i64;
    aabbsInt.m_faceDataStriding = 0;
    *(_DWORD *)&aabbsInt.m_flags.m_storage = 0;
    m_thisUid = m_data->m_thisUid;
    *(_QWORD *)&aabbsInt.m_vertices.m_size = aabbsInt.vfptr;
    v65 = (char *)aabbsInt.vfptr->__vecDelDtor < (char *)m_thisUid;
    v66 = LODWORD(aabbsInt.vfptr->__vecDelDtor) == m_thisUid;
    aabbsInt.m_streamingSets.m_data = m_data;
    aabbsInt.m_streamingSets.m_size = v44;
    aabbsInt.m_streamingSets.m_capacityAndFlags = m_size;
    LODWORD(aabbsInt.m_edges.m_data) = !v65 && !v66;
    if ( v65 || v66 )
    {
      *(_QWORD *)&aabbsInt.m_edges.m_size = aabbsInt.vfptr;
      vfptr = (hkBaseObjectVtbl *)m_data;
    }
    else
    {
      *(_QWORD *)&aabbsInt.m_edges.m_size = m_data;
    }
    aabbsInt.m_vertices.m_data = (hkVector4f *)&vfptr[-2];
LABEL_24:
    while ( 1 )
    {
      hk1AxisSweep::IteratorAB::next((hk1AxisSweep::IteratorAB *)&aabbsInt.m_edges);
      if ( aabbsInt.m_streamingSets.m_size <= 0 || aabbsInt.m_streamingSets.m_capacityAndFlags <= 0 )
        break;
      if ( LODWORD(aabbsInt.m_edges.m_data) )
      {
        v67 = aabbsInt.m_vertices.m_data;
        v68 = (int *)aabbsInt.m_streamingSets.m_data;
      }
      else
      {
        v67 = *(hkVector4f **)&aabbsInt.m_vertices.m_size;
        v68 = (int *)aabbsInt.m_vertices.m_data;
      }
      v69 = v67->m_quad.m128_i32[3];
      v70 = v68[3];
      v71 = aabbsInt.m_aabb.m_min.m_quad.m128_u64[0];
      v72 = *(int *)(aabbsInt.m_aabb.m_min.m_quad.m128_u64[0] + 8 * v69 + 4);
      v73 = aabbsInt.m_aabb.m_max.m_quad.m128_u64[0];
      edgeIdxB = *(int *)(aabbsInt.m_aabb.m_max.m_quad.m128_u64[0] + 8 * v70 + 4);
      if ( *(_DWORD *)(*(_QWORD *)&aabbsInt.m_faces.m_data[2].m_startEdgeIndex + 20 * v72 + 8) != -1
        || meshA->m_edges.m_data[edgeIdxB].m_oppositeEdge != -1 )
      {
        goto LABEL_62;
      }
      v75 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
              instance.m_originalEdges,
              instance.m_numOriginalEdges,
              &instance.m_instancedEdges,
              &instance.m_ownedEdges,
              &instance.m_edgeMap,
              *(_DWORD *)(aabbsInt.m_aabb.m_min.m_quad.m128_u64[0] + 8 * v69 + 4));
      m_a = v75->m_a;
      v77 = (int)m_a >= instance.m_numOriginalVertices
          ? &instance.m_ownedVertices.m_data[(int)m_a - instance.m_numOriginalVertices]
          : &instance.m_originalVertices[m_a];
      m_b = v75->m_b;
      v79 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v77->m_quad, v77->m_quad, 85),
                    instance.m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v77->m_quad, v77->m_quad, 0),
                    instance.m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v77->m_quad, v77->m_quad, 170),
                  instance.m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              instance.m_referenceFrame.m_transform.m_translation.m_quad);
      v80 = (int)m_b >= instance.m_numOriginalVertices
          ? &instance.m_ownedVertices.m_data[(int)m_b - instance.m_numOriginalVertices]
          : &instance.m_originalVertices[m_b];
      v81 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v80->m_quad, v80->m_quad, 85),
                    instance.m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v80->m_quad, v80->m_quad, 0),
                    instance.m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v80->m_quad, v80->m_quad, 170),
                  instance.m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              instance.m_referenceFrame.m_transform.m_translation.m_quad);
      v82 = _mm_sub_ps(v79, v81);
      v83 = _mm_mul_ps(v82, v82);
      if ( (float)((float)(_mm_shuffle_ps(v83, v83, 85).m128_f32[0] + _mm_shuffle_ps(v83, v83, 0).m128_f32[0])
                 + _mm_shuffle_ps(v83, v83, 170).m128_f32[0]) < v63 )
        goto LABEL_62;
      v84 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
              meshInstanceB.m_originalEdges,
              meshInstanceB.m_numOriginalEdges,
              &meshInstanceB.m_instancedEdges,
              &meshInstanceB.m_ownedEdges,
              &meshInstanceB.m_edgeMap,
              edgeIdxB);
      v85 = v84->m_a;
      v86 = (int)v85 >= meshInstanceB.m_numOriginalVertices
          ? &meshInstanceB.m_ownedVertices.m_data[(int)v85 - meshInstanceB.m_numOriginalVertices]
          : &meshInstanceB.m_originalVertices[v85];
      v87 = v84->m_b;
      v88 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v86->m_quad, v86->m_quad, 85),
                    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v86->m_quad, v86->m_quad, 0),
                    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v86->m_quad, v86->m_quad, 170),
                  meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              meshInstanceB.m_referenceFrame.m_transform.m_translation.m_quad);
      v89 = (int)v87 >= meshInstanceB.m_numOriginalVertices
          ? &meshInstanceB.m_ownedVertices.m_data[(int)v87 - meshInstanceB.m_numOriginalVertices]
          : &meshInstanceB.m_originalVertices[v87];
      v90 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v89->m_quad, v89->m_quad, 85),
                    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v89->m_quad, v89->m_quad, 0),
                    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v89->m_quad, v89->m_quad, 170),
                  meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              meshInstanceB.m_referenceFrame.m_transform.m_translation.m_quad);
      v91 = _mm_sub_ps(v88, v90);
      v92 = _mm_mul_ps(v91, v91);
      if ( (float)((float)(_mm_shuffle_ps(v92, v92, 85).m128_f32[0] + _mm_shuffle_ps(v92, v92, 0).m128_f32[0])
                 + _mm_shuffle_ps(v92, v92, 170).m128_f32[0]) >= v63
        && (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v79, v90), 1u), 1u), (__m128)v41)) & 7) == 7
        && (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v88, v81), 1u), 1u), (__m128)v41)) & 7) == 7 )
      {
        v93 = *(_DWORD *)(v71 + 8 * v69);
        m_meshA = aabbsInt.m_faces.m_data;
        faceIdxB = *(_DWORD *)(v73 + 8 * v70);
        v6 = meshSetAa;
        hkaiStreamingUtils::connectEdges(
          (hkaiNavMesh *)aabbsInt.m_faces.m_data,
          v93,
          v72,
          input->m_graphA,
          meshSetAa,
          retaddr,
          meshA,
          faceIdxB,
          edgeIdxB,
          input->m_graphB,
          vars0,
          v158);
        v95 = (int)aabbsInt.m_edgeData.m_data;
        v96 = aabbsInt.m_faceData.m_size;
        if ( 2 * LODWORD(aabbsInt.m_edgeData.m_data) > aabbsInt.m_faceData.m_size - 1 )
        {
          hkSet<int,hkContainerTempAllocator,hkMapOperations<int>>::resizeTable(
            (hkSet<int,hkContainerTempAllocator,hkMapOperations<int> > *)&aabbsInt.m_faceData,
            (hkResult *)&array,
            2 * (aabbsInt.m_faceData.m_size - 1) + 2);
          v95 = (int)aabbsInt.m_edgeData.m_data;
          v96 = aabbsInt.m_faceData.m_size;
        }
        v97 = v96 - 1;
        v98 = 1;
        v99 = v97 & (-1640531535 * v72);
        v100 = aabbsInt.m_faceData.m_data[v99];
        if ( v100 != -1 )
        {
          while ( v100 != (_DWORD)v72 )
          {
            v99 = v97 & (v99 + 1);
            v100 = aabbsInt.m_faceData.m_data[v99];
            if ( v100 == -1 )
              goto LABEL_54;
          }
          v98 = 0;
        }
LABEL_54:
        LODWORD(aabbsInt.m_edgeData.m_data) = v98 + v95;
        aabbsInt.m_faceData.m_data[v99] = v72;
        v101 = *(_DWORD *)&aabbsInt.m_flags.m_storage;
        m_faceDataStriding = aabbsInt.m_faceDataStriding;
        if ( 2 * *(_DWORD *)&aabbsInt.m_flags.m_storage > aabbsInt.m_faceDataStriding - 1 )
        {
          hkSet<int,hkContainerTempAllocator,hkMapOperations<int>>::resizeTable(
            (hkSet<int,hkContainerTempAllocator,hkMapOperations<int> > *)&aabbsInt.m_edgeData.m_size,
            &result,
            2 * (aabbsInt.m_faceDataStriding - 1) + 2);
          v101 = *(_DWORD *)&aabbsInt.m_flags.m_storage;
          m_faceDataStriding = aabbsInt.m_faceDataStriding;
        }
        v103 = m_faceDataStriding - 1;
        v104 = 1;
        v105 = v103 & (-1640531535 * edgeIdxB);
        v106 = *(_DWORD *)(*(_QWORD *)&aabbsInt.m_edgeData.m_size + 4i64 * v105);
        if ( v106 != -1 )
        {
          while ( v106 != (_DWORD)edgeIdxB )
          {
            v105 = v103 & (v105 + 1);
            v106 = *(_DWORD *)(*(_QWORD *)&aabbsInt.m_edgeData.m_size + 4i64 * v105);
            if ( v106 == -1 )
            {
              *(_DWORD *)&aabbsInt.m_flags.m_storage = v101 + 1;
              *(_DWORD *)(*(_QWORD *)&aabbsInt.m_edgeData.m_size + 4i64 * v105) = edgeIdxB;
              goto LABEL_24;
            }
          }
          v104 = 0;
        }
        *(_DWORD *)&aabbsInt.m_flags.m_storage = v104 + v101;
        *(_DWORD *)(*(_QWORD *)&aabbsInt.m_edgeData.m_size + 4i64 * v105) = edgeIdxB;
      }
      else
      {
LABEL_62:
        v6 = meshSetAa;
        m_meshA = aabbsInt.m_faces.m_data;
      }
    }
    v107 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v108 = (_QWORD *)v107[1];
    if ( (unsigned __int64)v108 < v107[3] )
    {
      *v108 = "Stmatch";
      v109 = __rdtsc();
      v110 = v108 + 2;
      *((_DWORD *)v110 - 2) = v109;
      v107[1] = v110;
    }
    m_min = (unsigned int *)aabbsInt.vfptr;
    v146.m_min.m_quad.m128_u64[1] = __PAIR64__(v143, array.m_size);
    aabbsInt.vfptr = 0i64;
    *(_DWORD *)&aabbsInt.m_memSizeAndFlags = 0;
    *(_DWORD *)(&aabbsInt.m_referenceCount + 1) = 0x80000000;
    v112 = array.m_data->m_min[0];
    v145.m_max.m_quad.m128_u64[1] = (unsigned __int64)m_min;
    v65 = *m_min < v112;
    v66 = *m_min == v112;
    v146.m_min.m_quad.m128_u64[0] = (unsigned __int64)array.m_data;
    v145.m_min.m_quad.m128_i32[0] = !v65 && !v66;
    if ( v65 || v66 )
    {
      v145.m_min.m_quad.m128_u64[1] = (unsigned __int64)m_min;
      m_min = array.m_data->m_min;
    }
    else
    {
      v145.m_min.m_quad.m128_u64[1] = (unsigned __int64)array.m_data;
    }
    v145.m_max.m_quad.m128_u64[0] = (unsigned __int64)(m_min - 8);
    while ( 1 )
    {
      hk1AxisSweep::IteratorAB::next((hk1AxisSweep::IteratorAB *)&v145);
      if ( v146.m_min.m_quad.m128_i32[2] <= 0 || v146.m_min.m_quad.m128_i32[3] <= 0 )
        break;
      if ( v145.m_min.m_quad.m128_i32[0] )
      {
        v113 = v145.m_max.m_quad.m128_u64[0];
        v114 = v146.m_min.m_quad.m128_u64[0];
      }
      else
      {
        v113 = v145.m_max.m_quad.m128_u64[1];
        v114 = v145.m_max.m_quad.m128_u64[0];
      }
      v115 = *(int *)(v113 + 12);
      v116 = *(_DWORD *)(aabbsInt.m_aabb.m_min.m_quad.m128_u64[0] + 8 * v115);
      v117 = *(_DWORD *)(aabbsInt.m_aabb.m_min.m_quad.m128_u64[0] + 8 * v115 + 4);
      v118 = *(int *)(v114 + 12);
      v119 = aabbsInt.m_faceData.m_size - 1;
      v120 = *(_DWORD *)(aabbsInt.m_aabb.m_max.m_quad.m128_u64[0] + 8 * v118);
      v121 = *(_DWORD *)(aabbsInt.m_aabb.m_max.m_quad.m128_u64[0] + 8 * v118 + 4);
      if ( aabbsInt.m_faceData.m_size - 1 <= 0
        || (v122 = v119 & (-1640531535 * v117), v123 = aabbsInt.m_faceData.m_data[v122], v123 == -1) )
      {
LABEL_78:
        v124 = aabbsInt.m_faceData.m_size;
      }
      else
      {
        while ( v123 != v117 )
        {
          v122 = v119 & (v122 + 1);
          v123 = aabbsInt.m_faceData.m_data[v122];
          if ( v123 == -1 )
            goto LABEL_78;
        }
        v124 = v122;
      }
      if ( v124 > v119 )
      {
        v125 = aabbsInt.m_faceDataStriding - 1;
        if ( aabbsInt.m_faceDataStriding - 1 <= 0
          || (v126 = v125 & (-1640531535 * v121),
              v127 = *(_DWORD *)(*(_QWORD *)&aabbsInt.m_edgeData.m_size + 4i64 * v126),
              v127 == -1) )
        {
LABEL_84:
          v128 = aabbsInt.m_faceDataStriding;
        }
        else
        {
          while ( v127 != v121 )
          {
            v126 = v125 & (v126 + 1);
            v127 = *(_DWORD *)(*(_QWORD *)&aabbsInt.m_edgeData.m_size + 4i64 * v126);
            if ( v127 == -1 )
              goto LABEL_84;
          }
          v128 = v126;
        }
        if ( v128 > v125
          && hkaiNavMeshGenerationUtils::calculateConnectivity(
               (hkaiNavMeshGenerationUtils *)&input->m_edgeMatchingParams,
               (hkaiNavMeshEdgeMatchingParameters *)&input->m_up,
               (hkSimdFloat32 *)&instance,
               &meshInstanceB,
               v117,
               v121,
               v116,
               v120,
               (hkaiNavMeshGenerationUtils::EdgePair *)&aabbsInt.m_edges) == CONNECT_SUCCESS )
        {
          v129 = *(_DWORD *)&aabbsInt.m_memSizeAndFlags;
          HIDWORD(aabbsInt.m_edges.m_data) |= 0x400000u;
          aabbsInt.m_edges.m_capacityAndFlags |= 0x400000u;
          if ( *(_DWORD *)&aabbsInt.m_memSizeAndFlags == (*(_DWORD *)(&aabbsInt.m_referenceCount + 1) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &aabbsInt, 48);
            v129 = *(_DWORD *)&aabbsInt.m_memSizeAndFlags;
          }
          v130 = &aabbsInt.vfptr[3 * v129];
          *v130 = (hkBaseObjectVtbl)aabbsInt.m_edges;
          v130[1] = (hkBaseObjectVtbl)aabbsInt.m_vertices;
          v130[2] = (hkBaseObjectVtbl)aabbsInt.m_streamingSets;
          ++*(_DWORD *)&aabbsInt.m_memSizeAndFlags;
        }
      }
    }
    if ( *(_DWORD *)&aabbsInt.m_memSizeAndFlags )
    {
      if ( *(int *)&aabbsInt.m_memSizeAndFlags > 1 )
        hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgePair,hkAlgorithm::less<hkaiNavMeshGenerationUtils::EdgePair>>(
          (hkaiNavMeshGenerationUtils::EdgePair *)aabbsInt.vfptr,
          0,
          *(_DWORD *)&aabbsInt.m_memSizeAndFlags - 1,
          0);
      hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(
        (hkResult *)&meshSetAa,
        (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&aabbsInt);
      sectionB = meshA;
      v132 = 0i64;
      *(_QWORD *)&aabbsInt.m_erosionRadius = 0i64;
      aabbsInt.m_userData = 0x8000000000000000ui64;
      hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMesh>(
        (hkaiNavMeshGenerationUtils *)&meshSetAa,
        (hkResult *)m_meshA,
        meshA,
        &aabbsInt,
        (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&aabbsInt.m_erosionRadius);
      v133 = *(_DWORD *)&aabbsInt.m_memSizeAndFlags;
      v134 = 0;
      if ( *(int *)&aabbsInt.m_memSizeAndFlags > 0 )
      {
        v135 = vars0;
        do
        {
          if ( BYTE4(aabbsInt.vfptr[v132 + 1].__first_virtual_table_function__) )
          {
            hkaiStreamingUtils::connectEdges(
              (hkaiNavMesh *)m_meshA,
              (__int64)aabbsInt.vfptr[v132].__first_virtual_table_function__ & 0x3FFFFF,
              (__int64)aabbsInt.vfptr[v132].__vecDelDtor & 0x3FFFFF,
              input->m_graphA,
              v6,
              retaddr,
              sectionB,
              HIDWORD(aabbsInt.vfptr[v132].__first_virtual_table_function__) & 0x3FFFFF,
              HIDWORD(aabbsInt.vfptr[v132].__vecDelDtor) & 0x3FFFFF,
              input->m_graphB,
              v135,
              v158);
            v133 = *(_DWORD *)&aabbsInt.m_memSizeAndFlags;
          }
          ++v134;
          v132 += 3i64;
        }
        while ( v134 < v133 );
      }
      LODWORD(aabbsInt.m_userData) = 0;
      if ( (aabbsInt.m_userData & 0x8000000000000000ui64) == 0i64 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          *(void **)&aabbsInt.m_erosionRadius,
          24 * (HIDWORD(aabbsInt.m_userData) & 0x3FFFFFFF));
      *(_QWORD *)&aabbsInt.m_erosionRadius = 0i64;
      HIDWORD(aabbsInt.m_userData) = 0x80000000;
    }
    *(_DWORD *)&aabbsInt.m_memSizeAndFlags = 0;
    if ( *(int *)(&aabbsInt.m_referenceCount + 1) >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        aabbsInt.vfptr,
        48 * (*(_DWORD *)(&aabbsInt.m_referenceCount + 1) & 0x3FFFFFFF));
    aabbsInt.vfptr = 0i64;
    *(_DWORD *)(&aabbsInt.m_referenceCount + 1) = 0x80000000;
    aabbsInt.m_faceDataStriding = 0;
    if ( aabbsInt.m_edgeDataStriding >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        *(void **)&aabbsInt.m_edgeData.m_size,
        4 * aabbsInt.m_edgeDataStriding);
    *(_QWORD *)&aabbsInt.m_edgeData.m_size = 0i64;
    aabbsInt.m_edgeDataStriding = 0x80000000;
    aabbsInt.m_faceData.m_size = 0;
    if ( aabbsInt.m_faceData.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        aabbsInt.m_faceData.m_data,
        4 * aabbsInt.m_faceData.m_capacityAndFlags);
    aabbsInt.m_faceData.m_data = 0i64;
    aabbsInt.m_faceData.m_capacityAndFlags = 0x80000000;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        32 * array.m_capacityAndFlags);
    array.m_data = 0i64;
    array.m_capacityAndFlags = 0x80000000;
    *(_DWORD *)&aabbsInt.m_memSizeAndFlags = 0;
    if ( *(int *)(&aabbsInt.m_referenceCount + 1) >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        aabbsInt.vfptr,
        32 * *(_DWORD *)(&aabbsInt.m_referenceCount + 1));
    aabbsInt.vfptr = 0i64;
    *(_DWORD *)(&aabbsInt.m_referenceCount + 1) = 0x80000000;
    aabbsInt.m_aabb.m_max.m_quad.m128_i32[2] = 0;
    if ( aabbsInt.m_aabb.m_max.m_quad.m128_i32[3] >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        (void *)aabbsInt.m_aabb.m_max.m_quad.m128_u64[0],
        8 * aabbsInt.m_aabb.m_max.m_quad.m128_i32[3]);
    aabbsInt.m_aabb.m_max.m_quad.m128_u64[0] = 0i64;
    aabbsInt.m_aabb.m_max.m_quad.m128_i32[3] = 0x80000000;
    aabbsInt.m_aabb.m_min.m_quad.m128_i32[2] = 0;
    if ( aabbsInt.m_aabb.m_min.m_quad.m128_i32[3] >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        (void *)aabbsInt.m_aabb.m_min.m_quad.m128_u64[0],
        8 * aabbsInt.m_aabb.m_min.m_quad.m128_i32[3]);
    aabbsInt.m_aabb.m_min.m_quad.m128_u64[0] = 0i64;
    aabbsInt.m_aabb.m_min.m_quad.m128_i32[3] = 0x80000000;
    hkaiNavMeshInstance::~hkaiNavMeshInstance(&meshInstanceB);
    hkaiNavMeshInstance::~hkaiNavMeshInstance(&instance);
    v136 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v137 = (_QWORD *)v136[1];
    v138 = v136;
    if ( (unsigned __int64)v137 < v136[3] )
    {
      *v137 = "lt";
      v139 = __rdtsc();
      v140 = v137 + 2;
      *((_DWORD *)v140 - 2) = v139;
      v138[1] = v140;
    }
  }
}

// File Line: 319
// RVA: 0xBD8190
void __fastcall hkaiStreamingUtils::connectEdges(
        hkaiNavMesh *sectionA,
        int faceIdxA,
        int edgeIdxA,
        hkaiDirectedGraphExplicitCost *graphA,
        hkaiStreamingSet *meshSetA,
        hkaiStreamingSet *graphSetA,
        hkaiNavMesh *sectionB,
        int faceIdxB,
        int edgeIdxB,
        hkaiDirectedGraphExplicitCost *graphB,
        hkaiStreamingSet *meshSetB,
        hkaiStreamingSet *graphSetB)
{
  __int64 v14; // rsi
  hkaiStreamingSet::NavMeshConnection *v16; // rbx
  hkaiStreamingSet::NavMeshConnection *v17; // rcx
  __int16 m_clusterIndex; // bp
  __int16 v19; // si
  hkaiStreamingSet::GraphConnection *v20; // rcx
  hkaiStreamingSet::GraphConnection *v21; // rdi
  hkaiStreamingSet::GraphConnection *v22; // rcx
  hkaiStreamingSet::GraphConnection *v23; // r9
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  float faceIdxBa; // [rsp+88h] [rbp+40h]

  v14 = faceIdxA;
  if ( meshSetA->m_meshConnections.m_size == (meshSetA->m_meshConnections.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &meshSetA->m_meshConnections, 16);
  v16 = &meshSetA->m_meshConnections.m_data[meshSetA->m_meshConnections.m_size++];
  if ( meshSetB->m_meshConnections.m_size == (meshSetB->m_meshConnections.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &meshSetB->m_meshConnections, 16);
  v17 = &meshSetB->m_meshConnections.m_data[meshSetB->m_meshConnections.m_size++];
  v17->m_oppositeFaceIndex = v14;
  v16->m_faceIndex = v14;
  v17->m_oppositeEdgeIndex = edgeIdxA;
  v16->m_edgeIndex = edgeIdxA;
  v16->m_oppositeFaceIndex = faceIdxB;
  v17->m_faceIndex = faceIdxB;
  v16->m_oppositeEdgeIndex = edgeIdxB;
  v17->m_edgeIndex = edgeIdxB;
  if ( graphA )
  {
    if ( graphB )
    {
      m_clusterIndex = sectionA->m_faces.m_data[v14].m_clusterIndex;
      v19 = sectionB->m_faces.m_data[faceIdxB].m_clusterIndex;
      if ( m_clusterIndex != -1
        && v19 != -1
        && !hkaiStreamingSet::containsGraphConnection(graphSetA, m_clusterIndex, v19) )
      {
        if ( graphSetA->m_graphConnections.m_size == (graphSetA->m_graphConnections.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &graphSetA->m_graphConnections, 16);
        v20 = &graphSetA->m_graphConnections.m_data[graphSetA->m_graphConnections.m_size];
        if ( v20 )
          hkaiStreamingSet::GraphConnection::GraphConnection(v20);
        v21 = &graphSetA->m_graphConnections.m_data[graphSetA->m_graphConnections.m_size++];
        if ( graphSetB->m_graphConnections.m_size == (graphSetB->m_graphConnections.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &graphSetB->m_graphConnections, 16);
        v22 = &graphSetB->m_graphConnections.m_data[graphSetB->m_graphConnections.m_size];
        if ( v22 )
          hkaiStreamingSet::GraphConnection::GraphConnection(v22);
        v23 = &graphSetB->m_graphConnections.m_data[graphSetB->m_graphConnections.m_size++];
        v23->m_oppositeNodeIndex = m_clusterIndex;
        v21->m_nodeIndex = m_clusterIndex;
        v21->m_oppositeNodeIndex = v19;
        v23->m_nodeIndex = v19;
        v24 = _mm_sub_ps(graphA->m_positions.m_data[m_clusterIndex].m_quad, graphB->m_positions.m_data[v19].m_quad);
        v25 = _mm_mul_ps(v24, v24);
        v26 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                _mm_shuffle_ps(v25, v25, 170));
        v27 = _mm_rsqrt_ps(v26);
        faceIdxBa = _mm_andnot_ps(
                      _mm_cmple_ps(v26, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v27), v27)),
                          _mm_mul_ps(*(__m128 *)_xmm, v27)),
                        v26)).m128_f32[0]
                  * 1.0039062;
        v23->m_edgeCost.m_value = HIWORD(faceIdxBa);
        v21->m_edgeCost.m_value = HIWORD(faceIdxBa);
      }
    }
  }
}

// File Line: 363
// RVA: 0xBD7000
void __fastcall hkaiStreamingUtils::generateStreamingInfo(hkaiStreamingUtils::FindEdgeOverlapInput *input)
{
  unsigned int m_uidA; // esi
  unsigned int m_uidB; // edi
  hkaiNavMesh *m_meshB; // rdx
  hkaiNavMesh *m_meshA; // rcx
  hkaiStreamingSet *v6; // r14
  hkaiDirectedGraphExplicitCost *m_graphA; // rcx
  hkaiDirectedGraphExplicitCost *m_graphB; // rdx
  hkaiStreamingSet *v9; // rax
  hkaiStreamingSet *setAOut; // [rsp+60h] [rbp+28h] BYREF
  hkaiStreamingSet *setBOut; // [rsp+68h] [rbp+30h] BYREF
  hkaiStreamingSet *meshSetB; // [rsp+70h] [rbp+38h] BYREF
  hkaiStreamingSet *meshSetA; // [rsp+78h] [rbp+40h] BYREF

  m_uidA = input->m_uidA;
  m_uidB = input->m_uidB;
  if ( m_uidA != -1 && m_uidB != -1 )
  {
    m_meshB = input->m_meshB;
    m_meshA = input->m_meshA;
    v6 = 0i64;
    meshSetA = 0i64;
    meshSetB = 0i64;
    hkaiStreamingSet::_findOrExpandSetsForUids(
      &m_meshA->m_streamingSets,
      &m_meshB->m_streamingSets,
      m_uidA,
      m_uidB,
      &meshSetA,
      &meshSetB);
    meshSetB->m_thisUid = m_uidB;
    meshSetA->m_oppositeUid = m_uidB;
    meshSetA->m_thisUid = m_uidA;
    meshSetB->m_oppositeUid = m_uidA;
    meshSetA->m_meshConnections.m_size = 0;
    meshSetB->m_meshConnections.m_size = 0;
    m_graphA = input->m_graphA;
    m_graphB = input->m_graphB;
    v9 = 0i64;
    setAOut = 0i64;
    setBOut = 0i64;
    if ( m_graphA )
    {
      if ( m_graphB )
      {
        hkaiStreamingSet::_findOrExpandSetsForUids(
          &m_graphA->m_streamingSets,
          &m_graphB->m_streamingSets,
          m_uidA,
          m_uidB,
          &setAOut,
          &setBOut);
        setBOut->m_thisUid = m_uidB;
        setAOut->m_oppositeUid = m_uidB;
        setAOut->m_thisUid = m_uidA;
        setBOut->m_oppositeUid = m_uidA;
        setAOut->m_graphConnections.m_size = 0;
        setBOut->m_graphConnections.m_size = 0;
        v6 = setAOut;
        v9 = setBOut;
      }
    }
    hkaiStreamingUtils::findEdgeOverlaps(input, meshSetA, meshSetB, v6, v9);
  }
}

