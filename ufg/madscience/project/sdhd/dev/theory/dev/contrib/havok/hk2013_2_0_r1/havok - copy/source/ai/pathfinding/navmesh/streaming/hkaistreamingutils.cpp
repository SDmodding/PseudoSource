// File Line: 37
// RVA: 0xBD6A10
void __fastcall hkaiStreamingUtils::FindEdgeOverlapInput::FindEdgeOverlapInput(hkaiStreamingUtils::FindEdgeOverlapInput *this)
{
  hkaiStreamingUtils::FindEdgeOverlapInput *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->m_uidA = -1i64;
  this->m_edgeMatchTolerance = 0.0099999998;
  this->m_meshA = 0i64;
  this->m_meshB = 0i64;
  this->m_mediatorA = 0i64;
  this->m_mediatorB = 0i64;
  this->m_graphA = 0i64;
  this->m_graphB = 0i64;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchingParams);
  v1->m_up.m_quad = _xmm;
  v1->m_transformA.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_transformA.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_transformA.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v1->m_transformA.m_translation = 0i64;
  v1->m_transformB.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_transformB.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_transformB.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v1->m_transformB.m_translation = 0i64;
}

// File Line: 44
// RVA: 0xBD6AD0
void __fastcall hkaiStreamingUtils::findPotentialDependencies(hkArrayBase<hkAabb> *aabbs, hkArray<hkKeyPair,hkContainerTempAllocator> *pairs, float _tolerance)
{
  hkArrayBase<hkAabb> *v3; // r12
  hkArray<hkKeyPair,hkContainerTempAllocator> *v4; // rsi
  _QWORD *v5; // rax
  _QWORD *v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // r13
  __m128 v11; // xmm6
  hkLifoAllocator *v12; // rax
  hk1AxisSweep::AabbInt *v13; // rbx
  int v14; // edx
  char *v15; // rcx
  __int64 v16; // r14
  __int64 v17; // r15
  int v18; // edi
  hkAabb *v19; // rax
  hkVector4f v20; // xmm0
  __int64 v21; // rax
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm1
  signed __int64 v24; // rax
  int v25; // eax
  int v26; // eax
  int v27; // er9
  hkKeyPair *v28; // r8
  int v29; // er9
  int v30; // eax
  hkResultEnum v31; // ecx
  int v32; // eax
  int v33; // eax
  int v34; // er9
  int v35; // eax
  hkKeyPair *v36; // r8
  int v37; // er9
  int v38; // ebp
  hkLifoAllocator *v39; // rax
  int v40; // er8
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  hkAabb aabbIn; // [rsp+30h] [rbp-68h]
  hkResult result; // [rsp+A0h] [rbp+8h]
  hkResult v47; // [rsp+A8h] [rbp+10h]
  float v48; // [rsp+B0h] [rbp+18h]

  v48 = _tolerance;
  v3 = aabbs;
  v4 = pairs;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v5[1];
  v7 = v5;
  if ( (unsigned __int64)v6 < v5[3] )
  {
    *v6 = "TtFindDepend";
    v8 = __rdtsc();
    v9 = (signed __int64)(v6 + 2);
    *(_DWORD *)(v9 - 8) = v8;
    v7[1] = v9;
  }
  v10 = v3->m_size;
  v11 = _mm_shuffle_ps((__m128)LODWORD(v48), (__m128)LODWORD(v48), 0);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hk1AxisSweep::AabbInt *)v12->m_cur;
  v14 = (32 * (v10 + 4) + 127) & 0xFFFFFF80;
  v15 = (char *)v13 + v14;
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    v13 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  else
    v12->m_cur = v15;
  v16 = 0i64;
  v17 = v10;
  v18 = 0;
  if ( (signed int)v10 > 0 )
  {
    do
    {
      v19 = v3->m_data;
      aabbIn.m_min = *(hkVector4f *)((char *)&v3->m_data->m_min + v16);
      v20.m_quad = _mm_add_ps(*(__m128 *)((char *)&v19->m_max.m_quad + v16), v11);
      aabbIn.m_min.m_quad = _mm_sub_ps(aabbIn.m_min.m_quad, v11);
      aabbIn.m_max = (hkVector4f)v20.m_quad;
      hk1AxisSweep::AabbInt::set(&v13[v18], &aabbIn, v18);
      ++v18;
      v16 += 32i64;
      --v17;
    }
    while ( v17 );
    LODWORD(v16) = 0;
  }
  v21 = v3->m_size;
  v22.m_quad = (__m128)aabbIn.m_max;
  aabbIn.m_min.m_quad.m128_i32[0] = -1;
  v23.m_quad = (__m128)aabbIn.m_min;
  v24 = (signed __int64)&v13[v21];
  *(hkVector4f *)v24 = aabbIn.m_min;
  *(hkVector4f *)(v24 + 16) = (hkVector4f)v22.m_quad;
  *(hkVector4f *)(v24 + 32) = (hkVector4f)v23.m_quad;
  *(hkVector4f *)(v24 + 48) = (hkVector4f)v22.m_quad;
  *(hkVector4f *)(v24 + 64) = (hkVector4f)v23.m_quad;
  *(hkVector4f *)(v24 + 80) = (hkVector4f)v22.m_quad;
  *(hkVector4f *)(v24 + 96) = (hkVector4f)v23.m_quad;
  *(hkVector4f *)(v24 + 112) = (hkVector4f)v22.m_quad;
  hk1AxisSweep::sortAabbs(v13, v10);
  v25 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < (signed int)v10 )
  {
    v26 = 2 * v25;
    v27 = v10;
    if ( (signed int)v10 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, v27, 8);
  }
  v28 = v4->m_data;
  v29 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  result.m_enum = 0;
  v30 = hk1AxisSweep::collide(v13, v10, v28, v29, (hkPadSpu<int> *)&result);
  v31 = result.m_enum;
  if ( (signed int)result.m_enum > 0 )
  {
    v32 = v4->m_capacityAndFlags;
    v4->m_size = v16;
    v33 = v32 & 0x3FFFFFFF;
    v34 = v33 + v31;
    if ( v33 < v33 + v31 )
    {
      v35 = 2 * v33;
      if ( v34 < v35 )
        v34 = v35;
      hkArrayUtil::_reserve(&v47, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, v34, 8);
    }
    v36 = v4->m_data;
    v37 = v4->m_capacityAndFlags & 0x3FFFFFFF;
    result.m_enum = 0;
    v30 = hk1AxisSweep::collide(v13, v10, v36, v37, (hkPadSpu<int> *)&result);
  }
  v4->m_size = v30;
  v38 = (32 * (v10 + 4) + 127) & 0xFFFFFF80;
  v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v40 = (v38 + 15) & 0xFFFFFFF0;
  if ( v38 > v39->m_slabSize || (char *)v13 + v40 != v39->m_cur || v39->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v39, v13, v40);
  else
    v39->m_cur = v13;
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v42 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v41[1] = v44;
  }
}

// File Line: 92
// RVA: 0xBD6DA0
void __fastcall hkaiStreamingUtils::collectBoundaryEdges(hkaiNavMeshInstance *instance, hkaiNavMeshQueryMediator *mediator, hkAabb *otherAabb, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *aabbsInt, hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *facesEdges, hkSimdFloat32 *tolerance)
{
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *v6; // rbp
  hkaiNavMeshInstance *v7; // rbx
  int v8; // edi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v10; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v11; // r8
  __int64 v12; // r14
  int v13; // er15
  hkaiNavMesh::Edge *v14; // r12
  int index; // esi
  int *v16; // rax
  int v17; // er8
  bool v18; // zf
  int v19; // ecx
  hkaiNavMesh::Edge *v20; // rax
  signed int v21; // edx
  __int64 v22; // rcx
  __m128 *v23; // rcx
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __int64 v26; // rax
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm3
  __m128 *v30; // rax
  __m128 v31; // xmm2
  hkVector4f v32; // xmm1
  int v33; // eax
  hk1AxisSweep::AabbInt *v34; // rcx
  hkAabb aabbIn; // [rsp+30h] [rbp-68h]

  v6 = aabbsInt;
  v7 = instance;
  hkaiNavMeshUtils::getEdgesInsideAabb(instance, mediator, otherAabb, facesEdges);
  v8 = 0;
  if ( facesEdges->m_size > 0 )
  {
    instanceMap = &v7->m_edgeMap;
    v10 = &v7->m_ownedEdges;
    v11 = &v7->m_instancedEdges;
    v12 = 0i64;
    do
    {
      v13 = v7->m_numOriginalEdges;
      v14 = v7->m_originalEdges;
      index = facesEdges->m_data[v12].m_edgeKey & 0x3FFFFF;
      v16 = (int *)hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
                     v7->m_originalEdges,
                     v7->m_numOriginalEdges,
                     v11,
                     v10,
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
                v14,
                v13,
                &v7->m_instancedEdges,
                &v7->m_ownedEdges,
                &v7->m_edgeMap,
                index);
        v21 = v7->m_numOriginalVertices;
        v22 = v20->m_a;
        if ( (signed int)v22 >= v21 )
          v23 = &v7->m_ownedVertices.m_data[(signed int)v22 - v21].m_quad;
        else
          v23 = &v7->m_originalVertices[v22].m_quad;
        v24 = v7->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
        v25 = v7->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
        v26 = v20->m_b;
        v27 = v7->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
        v28 = v7->m_referenceFrame.m_transform.m_translation.m_quad;
        v29 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v23, *v23, 0), v25),
                    _mm_mul_ps(_mm_shuffle_ps(*v23, *v23, 85), v24)),
                  _mm_mul_ps(_mm_shuffle_ps(*v23, *v23, 170), v27)),
                v28);
        if ( (signed int)v26 >= v21 )
          v30 = &v7->m_ownedVertices.m_data[(signed int)v26 - v21].m_quad;
        else
          v30 = &v7->m_originalVertices[v26].m_quad;
        v31 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v30, *v30, 0), v25),
                    _mm_mul_ps(_mm_shuffle_ps(*v30, *v30, 85), v24)),
                  _mm_mul_ps(_mm_shuffle_ps(*v30, *v30, 170), v27)),
                v28);
        v32.m_quad = _mm_sub_ps(_mm_min_ps(v29, v31), tolerance->m_real);
        v33 = v6->m_capacityAndFlags & 0x3FFFFFFF;
        aabbIn.m_max.m_quad = _mm_add_ps(_mm_max_ps(v29, v31), tolerance->m_real);
        aabbIn.m_min = (hkVector4f)v32.m_quad;
        if ( v6->m_size == v33 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v6, 32);
        v34 = &v6->m_data[v6->m_size++];
        hk1AxisSweep::AabbInt::set(v34, &aabbIn, v8);
      }
      ++v8;
      ++v12;
      instanceMap = &v7->m_edgeMap;
      v10 = &v7->m_ownedEdges;
      v11 = &v7->m_instancedEdges;
    }
    while ( v8 < facesEdges->m_size );
  }
}

// File Line: 122
// RVA: 0xBD7130
void __usercall hkaiStreamingUtils::findEdgeOverlaps(hkaiStreamingUtils::FindEdgeOverlapInput *input@<rcx>, hkaiStreamingSet *meshSetA@<rdx>, hkaiStreamingSet *meshSetB@<r8>, hkaiStreamingSet *graphSetA@<r9>, hkaiStreamingSet *a5@<rbx>, hkaiStreamingSet *graphSetB)
{
  hkaiStreamingSet *v6; // r13
  hkaiStreamingUtils::FindEdgeOverlapInput *v7; // rsi
  hkaiNavMesh *v8; // r14
  hkaiNavMesh *v9; // r15
  _QWORD *v10; // r10
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rax
  hkVector4f v13; // xmm1
  __int128 *v14; // rcx
  signed __int64 v15; // rdx
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __int128 v21; // xmm1
  unsigned int v22; // xmm2_4
  __m128 v23; // xmm7
  char *v24; // rax
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
  hkaiNavMeshQueryMediator *v37; // rdx
  hkVector4f v38; // xmm0
  hkVector4f v39; // xmm1
  __m128 v40; // xmm11
  __m128 v41; // xmm11
  hkVector4f v42; // xmm0
  hkVector4f v43; // xmm1
  int v44; // edi
  __int128 v45; // xmm6
  int v46; // er14
  __m128 v47; // xmm7
  signed __int64 v48; // rbx
  hk1AxisSweep::AabbInt *v49; // rax
  hk1AxisSweep::AabbInt *v50; // rax
  _QWORD *v51; // r8
  _QWORD *v52; // rcx
  unsigned __int64 v53; // rax
  signed __int64 v54; // rcx
  _QWORD *v55; // r8
  _QWORD *v56; // rcx
  unsigned __int64 v57; // rax
  signed __int64 v58; // rcx
  hk1AxisSweep::AabbInt *v59; // r8
  hk1AxisSweep::AabbInt *v60; // rdx
  float v61; // xmm0_4
  float v62; // xmm10_4
  float v63; // xmm10_4
  unsigned int v64; // eax
  bool v65; // cf
  bool v66; // zf
  __int64 v67; // rax
  __int64 v68; // rcx
  __int64 v69; // r14
  __int64 v70; // r12
  hkaiNavMeshUtils::FaceEdgeKeyPair *v71; // r15
  __int64 v72; // rbx
  hkaiNavMeshUtils::FaceEdgeKeyPair *v73; // r13
  __int64 edgeIdxB; // rdi
  hkaiNavMesh::Edge *v75; // rax
  __int64 v76; // rcx
  hkVector4f *v77; // rcx
  __int64 v78; // rax
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
  int v95; // er10
  int v96; // er9
  int v97; // er9
  signed int v98; // er11
  int v99; // ecx
  int v100; // edx
  int v101; // er10
  int v102; // er9
  int v103; // er9
  signed int v104; // er11
  int v105; // ecx
  int v106; // edx
  _QWORD *v107; // r8
  _QWORD *v108; // rcx
  unsigned __int64 v109; // rax
  signed __int64 v110; // rcx
  hk1AxisSweep::AabbInt *v111; // rdx
  unsigned int v112; // eax
  __int64 v113; // rax
  __int64 v114; // rdx
  __int64 v115; // rcx
  int v116; // ebx
  int v117; // er9
  __int64 v118; // rcx
  int v119; // er8
  int v120; // edi
  int v121; // er10
  int v122; // ecx
  int v123; // edx
  int v124; // eax
  int v125; // er8
  int v126; // ecx
  int v127; // edx
  int v128; // eax
  int v129; // ecx
  char *v130; // rcx
  hkaiNavMesh *sectionB; // r14
  __int64 v132; // rbx
  int v133; // ecx
  int v134; // edi
  hkaiStreamingSet *v135; // r12
  _QWORD *v136; // rax
  _QWORD *v137; // rcx
  _QWORD *v138; // r8
  unsigned __int64 v139; // rax
  signed __int64 v140; // rcx
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> array; // [rsp+60h] [rbp-80h]
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> aabbsInt; // [rsp+70h] [rbp-70h]
  hkaiNavMesh *sectionA; // [rsp+80h] [rbp-60h]
  hkSimdFloat32 tolerance; // [rsp+90h] [rbp-50h]
  __int128 v145; // [rsp+A0h] [rbp-40h]
  hk1AxisSweep::AabbInt *v146; // [rsp+B0h] [rbp-30h]
  int v147; // [rsp+B8h] [rbp-28h]
  int v148; // [rsp+BCh] [rbp-24h]
  hkSet<int,hkContainerTempAllocator,hkMapOperations<int> > v149; // [rsp+C0h] [rbp-20h]
  hkSet<int,hkContainerTempAllocator,hkMapOperations<int> > v150; // [rsp+D8h] [rbp-8h]
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> facesEdges; // [rsp+F0h] [rbp+10h]
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> v152; // [rsp+100h] [rbp+20h]
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> edgePairs; // [rsp+110h] [rbp+30h]
  int v154; // [rsp+120h] [rbp+40h]
  hkaiNavMesh *meshA; // [rsp+128h] [rbp+48h]
  char v156[64]; // [rsp+130h] [rbp+50h]
  hkResult result; // [rsp+170h] [rbp+90h]
  hkAabb otherAabb; // [rsp+180h] [rbp+A0h]
  hkAabb v159; // [rsp+1A0h] [rbp+C0h]
  hkVector4f v160; // [rsp+1C0h] [rbp+E0h]
  __int128 v161; // [rsp+1D0h] [rbp+F0h]
  __int128 v162; // [rsp+1E0h] [rbp+100h]
  __int128 v163; // [rsp+1F0h] [rbp+110h]
  hkVector4f v164; // [rsp+200h] [rbp+120h]
  hkVector4f v165; // [rsp+210h] [rbp+130h]
  __int128 v166; // [rsp+220h] [rbp+140h]
  hkVector4f v167; // [rsp+230h] [rbp+150h]
  hkaiNavMeshInstance meshInstanceB; // [rsp+240h] [rbp+160h]
  hkaiNavMeshInstance instance; // [rsp+420h] [rbp+340h]
  hkaiStreamingSet *meshSetAa; // [rsp+6A8h] [rbp+5C8h]
  hkaiStreamingSet *vars0; // [rsp+6B0h] [rbp+5D0h]
  hkaiStreamingSet *retaddr; // [rsp+6B8h] [rbp+5D8h]
  hkaiStreamingSet *v173; // [rsp+6C0h] [rbp+5E0h]

  v6 = meshSetA;
  v7 = input;
  if ( meshSetA->m_thisUid != meshSetB->m_thisUid )
  {
    v173 = a5;
    v8 = input->m_meshB;
    v9 = input->m_meshA;
    sectionA = input->m_meshA;
    meshA = v8;
    v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = v10[1];
    if ( v11 < v10[3] )
    {
      *(_QWORD *)v11 = "LtfindEdgeOverlaps";
      *(_QWORD *)(v11 + 16) = "StcollectAabbInt";
      v12 = __rdtsc();
      *(_DWORD *)(v11 + 8) = v12;
      v10[1] = v11 + 24;
    }
    v13.m_quad = (__m128)v9->m_aabb.m_max;
    v14 = &v162;
    v15 = 2i64;
    *(hkVector4f *)v156 = v9->m_aabb.m_min;
    v16.m_quad = (__m128)v8->m_aabb.m_min;
    *(hkVector4f *)&v156[16] = (hkVector4f)v13.m_quad;
    v17.m_quad = (__m128)v8->m_aabb.m_max;
    *(hkVector4f *)&v156[32] = (hkVector4f)v16.m_quad;
    v160.m_quad = (__m128)v7->m_transformA.m_rotation.m_col0;
    v18 = (__int128)v7->m_transformA.m_rotation.m_col2;
    *(hkVector4f *)&v156[48] = (hkVector4f)v17.m_quad;
    v19 = (__int128)v7->m_transformA.m_rotation.m_col1;
    v162 = v18;
    v164.m_quad = (__m128)v7->m_transformB.m_rotation.m_col0;
    v20 = (__int128)v7->m_transformB.m_rotation.m_col2;
    v161 = v19;
    v21 = (__int128)v7->m_transformA.m_translation;
    v166 = v20;
    array.m_size = LODWORD(v7->m_edgeMatchingParams.m_maxStepHeight);
    *(float *)&v20 = v7->m_edgeMatchTolerance;
    v163 = v21;
    v165.m_quad = (__m128)v7->m_transformB.m_rotation.m_col1;
    v167.m_quad = (__m128)v7->m_transformB.m_translation;
    array.m_size = fmaxf(v7->m_edgeMatchingParams.m_maxSeparation, *(float *)&array.m_size);
    *(float *)&v22 = fmaxf(*(float *)&v20, *(float *)&array.m_size);
    *(float *)&array.m_data = FLOAT_0_050000001;
    v23 = _mm_shuffle_ps((__m128)v22, (__m128)v22, 0);
    v24 = v156;
    v25 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
    v26 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v27 = *(__m128 *)v24;
      v28 = *((__m128 *)v24 + 1);
      v24 += 32;
      v14 += 4;
      v29 = _mm_mul_ps(_mm_sub_ps(v28, v27), (__m128)xmmword_141A711B0);
      v30 = _mm_mul_ps(_mm_add_ps(v27, *((__m128 *)v24 - 1)), (__m128)xmmword_141A711B0);
      v31 = _mm_add_ps(v29, _mm_max_ps(_mm_mul_ps(v25, v29), v23));
      v32 = _mm_add_ps(
              _mm_add_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), (__m128)*(v14 - 6)), 1u),
                          1u),
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), (__m128)*(v14 - 5)), 1u),
                          1u)),
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), (__m128)*(v14 - 4)), 1u),
                        1u));
      v33 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), (__m128)*(v14 - 6)),
                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), (__m128)*(v14 - 5))),
                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), (__m128)*(v14 - 4))),
              (__m128)*(v14 - 3));
      *((__m128 *)v24 - 1) = _mm_add_ps(v33, v32);
      *((__m128 *)v24 - 2) = _mm_add_ps(_mm_xor_ps(v26, v32), v33);
      --v15;
    }
    while ( v15 );
    v159 = *(hkAabb *)v156;
    otherAabb = *(hkAabb *)&v156[32];
    hkaiNavMeshInstance::hkaiNavMeshInstance(&instance);
    hkaiNavMeshInstance::tempInit(&instance, v9, 0);
    v34.m_quad = (__m128)v7->m_transformA.m_rotation.m_col1;
    instance.m_referenceFrame.m_transform.m_rotation.m_col0 = v7->m_transformA.m_rotation.m_col0;
    v35.m_quad = (__m128)v7->m_transformA.m_rotation.m_col2;
    instance.m_referenceFrame.m_transform.m_rotation.m_col1 = (hkVector4f)v34.m_quad;
    v36.m_quad = (__m128)v7->m_transformA.m_translation;
    instance.m_referenceFrame.m_transform.m_rotation.m_col2 = (hkVector4f)v35.m_quad;
    instance.m_referenceFrame.m_transform.m_translation = (hkVector4f)v36.m_quad;
    hkaiNavMeshInstance::hkaiNavMeshInstance(&meshInstanceB);
    hkaiNavMeshInstance::tempInit(&meshInstanceB, v8, 0);
    v37 = v7->m_mediatorA;
    v38.m_quad = (__m128)v7->m_transformB.m_rotation.m_col0;
    v39.m_quad = (__m128)v7->m_transformB.m_rotation.m_col1;
    v40 = (__m128)LODWORD(v7->m_edgeMatchTolerance);
    facesEdges.m_data = 0i64;
    facesEdges.m_size = 0;
    v152.m_data = 0i64;
    v41 = _mm_shuffle_ps(v40, v40, 0);
    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col0 = (hkVector4f)v38.m_quad;
    v42.m_quad = (__m128)v7->m_transformB.m_rotation.m_col2;
    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col1 = (hkVector4f)v39.m_quad;
    v152.m_size = 0;
    aabbsInt.m_data = 0i64;
    aabbsInt.m_size = 0;
    v43.m_quad = (__m128)v7->m_transformB.m_translation;
    meshInstanceB.m_referenceFrame.m_transform.m_rotation.m_col2 = (hkVector4f)v42.m_quad;
    tolerance.m_real = v41;
    array.m_data = 0i64;
    array.m_size = 0;
    meshInstanceB.m_referenceFrame.m_transform.m_translation = (hkVector4f)v43.m_quad;
    facesEdges.m_capacityAndFlags = 2147483648;
    v152.m_capacityAndFlags = 2147483648;
    aabbsInt.m_capacityAndFlags = 2147483648;
    array.m_capacityAndFlags = 2147483648;
    hkaiStreamingUtils::collectBoundaryEdges(&instance, v37, &otherAabb, &aabbsInt, &facesEdges, &tolerance);
    hkaiStreamingUtils::collectBoundaryEdges(&meshInstanceB, v7->m_mediatorB, &v159, &array, &v152, &tolerance);
    v44 = aabbsInt.m_size;
    v45 = v145;
    v46 = array.m_size;
    tolerance.m_real.m128_i32[0] = -1;
    array.m_size = aabbsInt.m_size;
    v47 = tolerance.m_real;
    v154 = v46;
    v48 = 4i64;
    do
    {
      if ( aabbsInt.m_size == (aabbsInt.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &aabbsInt, 32);
      v49 = &aabbsInt.m_data[aabbsInt.m_size];
      if ( v49 )
      {
        *(__m128 *)v49->m_min = v47;
        *(_OWORD *)v49->m_max = v45;
      }
      ++aabbsInt.m_size;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 32);
      v50 = &array.m_data[array.m_size];
      if ( v50 )
      {
        *(__m128 *)v50->m_min = v47;
        *(_OWORD *)v50->m_max = v45;
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
      v54 = (signed __int64)(v52 + 2);
      *(_DWORD *)(v54 - 8) = v53;
      v51[1] = v54;
    }
    hk1AxisSweep::sortAabbs(aabbsInt.m_data, v44);
    hk1AxisSweep::sortAabbs(array.m_data, v46);
    v55 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v56 = (_QWORD *)v55[1];
    if ( (unsigned __int64)v56 < v55[3] )
    {
      *v56 = "Stquick match";
      v57 = __rdtsc();
      v58 = (signed __int64)(v56 + 2);
      *(_DWORD *)(v58 - 8) = v57;
      v55[1] = v58;
    }
    v59 = array.m_data;
    v60 = aabbsInt.m_data;
    v61 = v7->m_edgeMatchTolerance;
    v149.m_elem.m_capacityAndFlags = 2147483648;
    v150.m_elem.m_capacityAndFlags = 2147483648;
    v149.m_elem.m_data = 0i64;
    v149.m_elem.m_size = 0;
    *(float *)&array.m_data = v61 * 2.0;
    LODWORD(v62) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(array.m_data), (__m128)LODWORD(array.m_data), 0);
    v63 = v62 * v62;
    v149.m_numElems = 0;
    v150.m_elem.m_data = 0i64;
    v150.m_elem.m_size = 0;
    v150.m_numElems = 0;
    v64 = v59->m_min[0];
    *((_QWORD *)&v145 + 1) = aabbsInt.m_data;
    v65 = aabbsInt.m_data->m_min[0] < v64;
    v66 = aabbsInt.m_data->m_min[0] == v64;
    v146 = v59;
    v147 = v44;
    v148 = v46;
    tolerance.m_real.m128_i32[0] = !v65 && !v66;
    if ( v65 || v66 )
    {
      tolerance.m_real.m128_u64[1] = (unsigned __int64)aabbsInt.m_data;
      v60 = v59;
    }
    else
    {
      tolerance.m_real.m128_u64[1] = (unsigned __int64)v59;
    }
    *(_QWORD *)&v145 = v60 - 1;
LABEL_24:
    while ( 1 )
    {
      hk1AxisSweep::IteratorAB::next((hk1AxisSweep::IteratorAB *)&tolerance);
      if ( v147 <= 0 || v148 <= 0 )
        break;
      if ( tolerance.m_real.m128_i32[0] )
      {
        v67 = v145;
        v68 = (__int64)v146;
      }
      else
      {
        v67 = *((_QWORD *)&v145 + 1);
        v68 = v145;
      }
      v69 = *(signed int *)(v67 + 12);
      v70 = *(signed int *)(v68 + 12);
      v71 = facesEdges.m_data;
      v72 = (signed int)facesEdges.m_data[v69].m_edgeKey;
      v73 = v152.m_data;
      edgeIdxB = (signed int)v152.m_data[v70].m_edgeKey;
      if ( sectionA->m_edges.m_data[v72].m_oppositeEdge != -1 || meshA->m_edges.m_data[edgeIdxB].m_oppositeEdge != -1 )
        goto LABEL_123;
      v75 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
              instance.m_originalEdges,
              instance.m_numOriginalEdges,
              &instance.m_instancedEdges,
              &instance.m_ownedEdges,
              &instance.m_edgeMap,
              facesEdges.m_data[v69].m_edgeKey);
      v76 = v75->m_a;
      v77 = (signed int)v76 >= instance.m_numOriginalVertices ? &instance.m_ownedVertices.m_data[(signed int)v76
                                                                                               - instance.m_numOriginalVertices] : &instance.m_originalVertices[v76];
      v78 = v75->m_b;
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
      v80 = (signed int)v78 >= instance.m_numOriginalVertices ? &instance.m_ownedVertices.m_data[(signed int)v78
                                                                                               - instance.m_numOriginalVertices] : &instance.m_originalVertices[v78];
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
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 170))) < v63 )
        goto LABEL_123;
      v84 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__6(
              meshInstanceB.m_originalEdges,
              meshInstanceB.m_numOriginalEdges,
              &meshInstanceB.m_instancedEdges,
              &meshInstanceB.m_ownedEdges,
              &meshInstanceB.m_edgeMap,
              edgeIdxB);
      v85 = v84->m_a;
      v86 = (signed int)v85 >= meshInstanceB.m_numOriginalVertices ? &meshInstanceB.m_ownedVertices.m_data[(signed int)v85 - meshInstanceB.m_numOriginalVertices] : &meshInstanceB.m_originalVertices[v85];
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
      v89 = (signed int)v87 >= meshInstanceB.m_numOriginalVertices ? &meshInstanceB.m_ownedVertices.m_data[(signed int)v87 - meshInstanceB.m_numOriginalVertices] : &meshInstanceB.m_originalVertices[v87];
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
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 170))) < v63
        || (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v79, v90), 1u), 1u), v41)) & 7) != 7
        || (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v88, v81), 1u), 1u), v41)) & 7) != 7 )
      {
LABEL_123:
        v6 = meshSetAa;
        v9 = sectionA;
      }
      else
      {
        v93 = v71[v69].m_faceKey;
        v9 = sectionA;
        faceIdxB = v73[v70].m_faceKey;
        v6 = meshSetAa;
        hkaiStreamingUtils::connectEdges(
          sectionA,
          v93,
          v72,
          v7->m_graphA,
          meshSetAa,
          retaddr,
          meshA,
          faceIdxB,
          edgeIdxB,
          v7->m_graphB,
          vars0,
          v173);
        v95 = v149.m_numElems;
        v96 = v149.m_elem.m_size;
        if ( 2 * v149.m_numElems > v149.m_elem.m_size - 1 )
        {
          hkSet<int,hkContainerTempAllocator,hkMapOperations<int>>::resizeTable(
            &v149,
            (hkResult *)&array,
            2 * (v149.m_elem.m_size - 1) + 2);
          v95 = v149.m_numElems;
          v96 = v149.m_elem.m_size;
        }
        v97 = v96 - 1;
        v98 = 1;
        v99 = v97 & -1640531535 * v72;
        v100 = v149.m_elem.m_data[v99];
        if ( v100 != -1 )
        {
          while ( v100 != (_DWORD)v72 )
          {
            v99 = v97 & (v99 + 1);
            v100 = v149.m_elem.m_data[v99];
            if ( v100 == -1 )
              goto LABEL_54;
          }
          v98 = 0;
        }
LABEL_54:
        v149.m_numElems = v98 + v95;
        v149.m_elem.m_data[v99] = v72;
        v101 = v150.m_numElems;
        v102 = v150.m_elem.m_size;
        if ( 2 * v150.m_numElems > v150.m_elem.m_size - 1 )
        {
          hkSet<int,hkContainerTempAllocator,hkMapOperations<int>>::resizeTable(
            &v150,
            &result,
            2 * (v150.m_elem.m_size - 1) + 2);
          v101 = v150.m_numElems;
          v102 = v150.m_elem.m_size;
        }
        v103 = v102 - 1;
        v104 = 1;
        v105 = v103 & -1640531535 * edgeIdxB;
        v106 = v150.m_elem.m_data[v105];
        if ( v106 != -1 )
        {
          while ( v106 != (_DWORD)edgeIdxB )
          {
            v105 = v103 & (v105 + 1);
            v106 = v150.m_elem.m_data[v105];
            if ( v106 == -1 )
            {
              v150.m_numElems = v101 + 1;
              v150.m_elem.m_data[v105] = edgeIdxB;
              goto LABEL_24;
            }
          }
          v104 = 0;
        }
        v150.m_numElems = v104 + v101;
        v150.m_elem.m_data[v105] = edgeIdxB;
      }
    }
    v107 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v108 = (_QWORD *)v107[1];
    if ( (unsigned __int64)v108 < v107[3] )
    {
      *v108 = "Stmatch";
      v109 = __rdtsc();
      v110 = (signed __int64)(v108 + 2);
      *(_DWORD *)(v110 - 8) = v109;
      v107[1] = v110;
    }
    v111 = aabbsInt.m_data;
    *(_DWORD *)&v156[40] = array.m_size;
    aabbsInt.m_data = 0i64;
    aabbsInt.m_size = 0;
    aabbsInt.m_capacityAndFlags = 2147483648;
    *(_DWORD *)&v156[44] = v154;
    v112 = array.m_data->m_min[0];
    *(_QWORD *)&v156[24] = v111;
    v65 = v111->m_min[0] < v112;
    v66 = v111->m_min[0] == v112;
    *(_QWORD *)&v156[32] = array.m_data;
    *(_DWORD *)v156 = !v65 && !v66;
    if ( v65 || v66 )
    {
      *(_QWORD *)&v156[8] = v111;
      v111 = array.m_data;
    }
    else
    {
      *(_QWORD *)&v156[8] = array.m_data;
    }
    *(_QWORD *)&v156[16] = v111 - 1;
    while ( 1 )
    {
      hk1AxisSweep::IteratorAB::next((hk1AxisSweep::IteratorAB *)v156);
      if ( *(_DWORD *)&v156[40] <= 0 || *(_DWORD *)&v156[44] <= 0 )
        break;
      if ( *(_DWORD *)v156 )
      {
        v113 = *(_QWORD *)&v156[16];
        v114 = *(_QWORD *)&v156[32];
      }
      else
      {
        v113 = *(_QWORD *)&v156[24];
        v114 = *(_QWORD *)&v156[16];
      }
      v115 = *(signed int *)(v113 + 12);
      v116 = facesEdges.m_data[v115].m_faceKey;
      v117 = facesEdges.m_data[v115].m_edgeKey;
      v118 = *(signed int *)(v114 + 12);
      v119 = v149.m_elem.m_size - 1;
      v120 = v152.m_data[v118].m_faceKey;
      v121 = v152.m_data[v118].m_edgeKey;
      if ( v149.m_elem.m_size - 1 <= 0
        || (v122 = v119 & -1640531535 * v117, v123 = v149.m_elem.m_data[v122], v123 == -1) )
      {
LABEL_78:
        v124 = v149.m_elem.m_size;
      }
      else
      {
        while ( v123 != v117 )
        {
          v122 = v119 & (v122 + 1);
          v123 = v149.m_elem.m_data[v122];
          if ( v123 == -1 )
            goto LABEL_78;
        }
        v124 = v122;
      }
      if ( v124 > v119 )
      {
        v125 = v150.m_elem.m_size - 1;
        if ( v150.m_elem.m_size - 1 <= 0
          || (v126 = v125 & -1640531535 * v121, v127 = v150.m_elem.m_data[v126], v127 == -1) )
        {
LABEL_84:
          v128 = v150.m_elem.m_size;
        }
        else
        {
          while ( v127 != v121 )
          {
            v126 = v125 & (v126 + 1);
            v127 = v150.m_elem.m_data[v126];
            if ( v127 == -1 )
              goto LABEL_84;
          }
          v128 = v126;
        }
        if ( v128 > v125
          && hkaiNavMeshGenerationUtils::calculateConnectivity(
               &v7->m_edgeMatchingParams,
               &v7->m_up,
               &instance,
               &meshInstanceB,
               v117,
               v121,
               v116,
               v120,
               (hkaiNavMeshGenerationUtils::EdgePair *)&tolerance) == -1 )
        {
          v129 = aabbsInt.m_size;
          tolerance.m_real.m128_i32[1] |= 0x400000u;
          tolerance.m_real.m128_i32[3] |= 0x400000u;
          if ( aabbsInt.m_size == (aabbsInt.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &aabbsInt, 48);
            v129 = aabbsInt.m_size;
          }
          v130 = (char *)aabbsInt.m_data + 48 * v129;
          *(hkSimdFloat32 *)v130 = (hkSimdFloat32)tolerance.m_real;
          *((_OWORD *)v130 + 1) = v145;
          *((_QWORD *)v130 + 4) = v146;
          *((_DWORD *)v130 + 10) = v147;
          *((_DWORD *)v130 + 11) = v148;
          ++aabbsInt.m_size;
        }
      }
    }
    if ( aabbsInt.m_size )
    {
      if ( aabbsInt.m_size > 1 )
        hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgePair,hkAlgorithm::less<hkaiNavMeshGenerationUtils::EdgePair>>(
          (hkaiNavMeshGenerationUtils::EdgePair *)aabbsInt.m_data,
          0,
          aabbsInt.m_size - 1,
          0);
      hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(
        (hkResult *)&meshSetAa,
        (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&aabbsInt);
      sectionB = meshA;
      v132 = 0i64;
      edgePairs.m_capacityAndFlags = 2147483648;
      edgePairs.m_data = 0i64;
      edgePairs.m_size = 0;
      hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMesh>(
        (hkaiNavMeshGenerationUtils *)&meshSetAa,
        (hkResult *)v9,
        meshA,
        (hkaiNavMesh *)&aabbsInt,
        &edgePairs);
      v133 = aabbsInt.m_size;
      v134 = 0;
      if ( aabbsInt.m_size > 0 )
      {
        v135 = vars0;
        do
        {
          if ( aabbsInt.m_data->m_expansionMax[v132] )
          {
            hkaiStreamingUtils::connectEdges(
              v9,
              *(unsigned int *)((_BYTE *)&aabbsInt.m_data->m_min[2] + v132) & 0x3FFFFF,
              *(unsigned int *)((_BYTE *)aabbsInt.m_data->m_min + v132) & 0x3FFFFF,
              v7->m_graphA,
              v6,
              retaddr,
              sectionB,
              *(_DWORD *)&aabbsInt.m_data->m_expansionMin[v132] & 0x3FFFFF,
              *(unsigned int *)((_BYTE *)&aabbsInt.m_data->m_min[1] + v132) & 0x3FFFFF,
              v7->m_graphB,
              v135,
              v173);
            v133 = aabbsInt.m_size;
          }
          ++v134;
          v132 += 48i64;
        }
        while ( v134 < v133 );
        LODWORD(v132) = 0;
      }
      edgePairs.m_size = v132;
      if ( edgePairs.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          edgePairs.m_data,
          24 * (edgePairs.m_capacityAndFlags & 0x3FFFFFFF));
      edgePairs.m_data = 0i64;
      edgePairs.m_capacityAndFlags = 2147483648;
    }
    else
    {
      LODWORD(v132) = 0;
    }
    aabbsInt.m_size = v132;
    if ( aabbsInt.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        aabbsInt.m_data,
        48 * (aabbsInt.m_capacityAndFlags & 0x3FFFFFFF));
    aabbsInt.m_data = 0i64;
    aabbsInt.m_capacityAndFlags = 2147483648;
    v150.m_elem.m_size = 0;
    if ( v150.m_elem.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v150.m_elem.m_data,
        4 * v150.m_elem.m_capacityAndFlags);
    v150.m_elem.m_data = 0i64;
    v150.m_elem.m_capacityAndFlags = 2147483648;
    v149.m_elem.m_size = 0;
    if ( v149.m_elem.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v149.m_elem.m_data,
        4 * v149.m_elem.m_capacityAndFlags);
    v149.m_elem.m_data = 0i64;
    v149.m_elem.m_capacityAndFlags = 2147483648;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array.m_data,
        32 * array.m_capacityAndFlags);
    array.m_data = 0i64;
    array.m_capacityAndFlags = 2147483648;
    aabbsInt.m_size = 0;
    if ( aabbsInt.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        aabbsInt.m_data,
        32 * aabbsInt.m_capacityAndFlags);
    aabbsInt.m_data = 0i64;
    aabbsInt.m_capacityAndFlags = 2147483648;
    v152.m_size = 0;
    if ( v152.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v152.m_data,
        8 * v152.m_capacityAndFlags);
    v152.m_data = 0i64;
    v152.m_capacityAndFlags = 2147483648;
    facesEdges.m_size = 0;
    if ( facesEdges.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        facesEdges.m_data,
        8 * facesEdges.m_capacityAndFlags);
    facesEdges.m_data = 0i64;
    facesEdges.m_capacityAndFlags = 2147483648;
    hkaiNavMeshInstance::~hkaiNavMeshInstance(&meshInstanceB);
    hkaiNavMeshInstance::~hkaiNavMeshInstance(&instance);
    v136 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v137 = (_QWORD *)v136[1];
    v138 = v136;
    if ( (unsigned __int64)v137 < v136[3] )
    {
      *v137 = "lt";
      v139 = __rdtsc();
      v140 = (signed __int64)(v137 + 2);
      *(_DWORD *)(v140 - 8) = v139;
      v138[1] = v140;
    }
  }
}

// File Line: 319
// RVA: 0xBD8190
void __fastcall hkaiStreamingUtils::connectEdges(hkaiNavMesh *sectionA, int faceIdxA, int edgeIdxA, hkaiDirectedGraphExplicitCost *graphA, hkaiStreamingSet *meshSetA, hkaiStreamingSet *graphSetA, hkaiNavMesh *sectionB, int faceIdxB, int edgeIdxB, hkaiDirectedGraphExplicitCost *graphB, hkaiStreamingSet *meshSetB, hkaiStreamingSet *graphSetB)
{
  hkaiDirectedGraphExplicitCost *v12; // r13
  int v13; // ebp
  __int64 v14; // rsi
  hkaiNavMesh *v15; // r15
  hkaiStreamingSet::NavMeshConnection *v16; // rbx
  hkaiStreamingSet::NavMeshConnection *v17; // rcx
  __int16 v18; // bp
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

  v12 = graphA;
  v13 = edgeIdxA;
  v14 = faceIdxA;
  v15 = sectionA;
  if ( meshSetA->m_meshConnections.m_size == (meshSetA->m_meshConnections.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &meshSetA->m_meshConnections,
      16);
  v16 = &meshSetA->m_meshConnections.m_data[meshSetA->m_meshConnections.m_size++];
  if ( meshSetB->m_meshConnections.m_size == (meshSetB->m_meshConnections.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &meshSetB->m_meshConnections,
      16);
  v17 = &meshSetB->m_meshConnections.m_data[meshSetB->m_meshConnections.m_size++];
  v17->m_oppositeFaceIndex = v14;
  v16->m_faceIndex = v14;
  v17->m_oppositeEdgeIndex = v13;
  v16->m_edgeIndex = v13;
  v16->m_oppositeFaceIndex = faceIdxB;
  v17->m_faceIndex = faceIdxB;
  v16->m_oppositeEdgeIndex = edgeIdxB;
  v17->m_edgeIndex = edgeIdxB;
  if ( v12 )
  {
    if ( graphB )
    {
      v18 = v15->m_faces.m_data[v14].m_clusterIndex;
      v19 = sectionB->m_faces.m_data[faceIdxB].m_clusterIndex;
      if ( v18 != -1 && v19 != -1 && !hkaiStreamingSet::containsGraphConnection(graphSetA, v18, v19) )
      {
        if ( graphSetA->m_graphConnections.m_size == (graphSetA->m_graphConnections.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &graphSetA->m_graphConnections,
            16);
        v20 = &graphSetA->m_graphConnections.m_data[graphSetA->m_graphConnections.m_size];
        if ( v20 )
          hkaiStreamingSet::GraphConnection::GraphConnection(v20);
        v21 = &graphSetA->m_graphConnections.m_data[graphSetA->m_graphConnections.m_size++];
        if ( graphSetB->m_graphConnections.m_size == (graphSetB->m_graphConnections.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &graphSetB->m_graphConnections,
            16);
        v22 = &graphSetB->m_graphConnections.m_data[graphSetB->m_graphConnections.m_size];
        if ( v22 )
          hkaiStreamingSet::GraphConnection::GraphConnection(v22);
        v23 = &graphSetB->m_graphConnections.m_data[graphSetB->m_graphConnections.m_size++];
        v23->m_oppositeNodeIndex = v18;
        v21->m_nodeIndex = v18;
        v21->m_oppositeNodeIndex = v19;
        v23->m_nodeIndex = v19;
        v24 = _mm_sub_ps(v12->m_positions.m_data[v18].m_quad, graphB->m_positions.m_data[v19].m_quad);
        v25 = _mm_mul_ps(v24, v24);
        v26 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                _mm_shuffle_ps(v25, v25, 170));
        v27 = _mm_rsqrt_ps(v26);
        faceIdxBa = COERCE_FLOAT(
                      _mm_andnot_ps(
                        _mm_cmpleps(v26, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v27), v27)),
                            _mm_mul_ps(*(__m128 *)_xmm, v27)),
                          v26)))
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
  unsigned int v1; // esi
  unsigned int v2; // edi
  hkaiStreamingUtils::FindEdgeOverlapInput *v3; // rbx
  hkaiNavMesh *v4; // rdx
  hkaiNavMesh *v5; // rcx
  hkaiStreamingSet *v6; // r14
  hkaiDirectedGraphExplicitCost *v7; // rcx
  hkaiDirectedGraphExplicitCost *v8; // rdx
  hkaiStreamingSet *v9; // rax
  hkaiStreamingSet *setAOut; // [rsp+60h] [rbp+28h]
  hkaiStreamingSet *setBOut; // [rsp+68h] [rbp+30h]
  __int128 meshSetB; // [rsp+70h] [rbp+38h]

  v1 = input->m_uidA;
  v2 = input->m_uidB;
  v3 = input;
  if ( v1 != -1 && v2 != -1 )
  {
    v4 = input->m_meshB;
    v5 = input->m_meshA;
    v6 = 0i64;
    meshSetB = 0ui64;
    hkaiStreamingSet::_findOrExpandSetsForUids(
      &v5->m_streamingSets,
      &v4->m_streamingSets,
      v1,
      v2,
      (hkaiStreamingSet **)&meshSetB + 1,
      (hkaiStreamingSet **)&meshSetB);
    *(_DWORD *)meshSetB = v2;
    *(_DWORD *)(*((_QWORD *)&meshSetB + 1) + 4i64) = v2;
    **((_DWORD **)&meshSetB + 1) = v1;
    *(_DWORD *)(meshSetB + 4) = v1;
    *(_DWORD *)(*((_QWORD *)&meshSetB + 1) + 16i64) = 0;
    *(_DWORD *)(meshSetB + 16) = 0;
    v7 = v3->m_graphA;
    v8 = v3->m_graphB;
    v9 = 0i64;
    setAOut = 0i64;
    setBOut = 0i64;
    if ( v7 )
    {
      if ( v8 )
      {
        hkaiStreamingSet::_findOrExpandSetsForUids(
          &v7->m_streamingSets,
          &v8->m_streamingSets,
          v1,
          v2,
          &setAOut,
          &setBOut);
        setBOut->m_thisUid = v2;
        setAOut->m_oppositeUid = v2;
        setAOut->m_thisUid = v1;
        setBOut->m_oppositeUid = v1;
        setAOut->m_graphConnections.m_size = 0;
        setBOut->m_graphConnections.m_size = 0;
        v6 = setAOut;
        v9 = setBOut;
      }
    }
    hkaiStreamingUtils::findEdgeOverlaps(
      v3,
      *((hkaiStreamingSet **)&meshSetB + 1),
      (hkaiStreamingSet *)meshSetB,
      v6,
      v9);
  }
}

