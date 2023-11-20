// File Line: 20
// RVA: 0xBD59F0
void __fastcall hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(hkaiStaticTreeNavMeshQueryMediator *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStaticTreeNavMeshQueryMediator::`vftable;
  this->m_tree.m_pntr = 0i64;
  this->m_navMesh.m_pntr = 0i64;
}

// File Line: 26
// RVA: 0xBD5A20
void __fastcall hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(hkaiStaticTreeNavMeshQueryMediator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStaticTreeNavMeshQueryMediator::`vftable;
}

// File Line: 31
// RVA: 0xBD5A40
void __fastcall hkaiStaticTreeNavMeshQueryMediator::~hkaiStaticTreeNavMeshQueryMediator(hkaiStaticTreeNavMeshQueryMediator *this)
{
  hkaiStaticTreeNavMeshQueryMediator *v1; // rbx
  hkaiNavMesh *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStaticTreeNavMeshQueryMediator::`vftable;
  v2 = this->m_navMesh.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_navMesh.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_tree.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_tree.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 35
// RVA: 0xBD5AA0
void __fastcall hkaiStaticTreeNavMeshQueryMediator::setNavMesh(hkaiStaticTreeNavMeshQueryMediator *this, hkaiNavMesh *mesh)
{
  hkaiStaticTreeNavMeshQueryMediator *v2; // rdi
  hkaiNavMesh *v3; // rbx
  hkReferencedObject *v4; // rcx
  int v5; // ebp
  hkcdStaticAabbTree *v6; // rsi
  unsigned int v7; // ebx
  hkaiNavMeshUtils *v8; // rcx
  _QWORD **v9; // rax
  hkcdStaticAabbTree *v10; // rax
  hkcdStaticAabbTree *v11; // rax
  hkReferencedObject *v12; // rcx
  hkAabb *aabbOut[2]; // [rsp+20h] [rbp-68h]
  hkcdDynamicAabbTree dynTree; // [rsp+30h] [rbp-58h]
  hkSimdFloat32 extraRadius; // [rsp+50h] [rbp-38h]
  hkResult result; // [rsp+90h] [rbp+8h]

  v2 = this;
  v3 = mesh;
  if ( mesh )
    hkReferencedObject::addReference((hkReferencedObject *)&mesh->vfptr);
  v4 = (hkReferencedObject *)&v2->m_navMesh.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v2->m_navMesh.m_pntr = v3;
  v5 = v3->m_faces.m_size;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&dynTree);
  hkcdDynamicAabbTree::reserveLeaves(&dynTree, &result, v5);
  v6 = 0i64;
  v7 = 0;
  if ( v5 > 0 )
  {
    do
    {
      v8 = (hkaiNavMeshUtils *)v2->m_navMesh.m_pntr;
      *(_OWORD *)aabbOut = 0i64;
      hkaiNavMeshUtils::calcFaceAabb<hkaiNavMesh>(v8, (hkaiNavMesh *)v7, (__int64)aabbOut, &extraRadius);
      hkcdDynamicAabbTree::insert(&dynTree, (hkAabb *)&extraRadius, v7++);
    }
    while ( (signed int)v7 < v5 );
  }
  hkcdDynamicAabbTree::rebuild(&dynTree);
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkcdStaticAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 32i64);
  if ( v10 )
  {
    hkcdStaticAabbTree::hkcdStaticAabbTree(v10);
    v6 = v11;
  }
  v12 = (hkReferencedObject *)&v2->m_tree.m_pntr->vfptr;
  if ( v12 && v12 != (hkReferencedObject *)v6 )
    hkReferencedObject::removeReference(v12);
  v2->m_tree.m_pntr = v6;
  hkcdStaticAabbTree::buildFromDynamicTree(v6, &dynTree);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&dynTree);
}

// File Line: 56
// RVA: 0xBD5BE0
void __fastcall hkaiStaticTreeNavMeshQueryMediator::setNavMeshAndTree(hkaiStaticTreeNavMeshQueryMediator *this, hkaiNavMesh *navMesh, hkcdStaticAabbTree *staticTree)
{
  hkcdStaticAabbTree *v3; // rdi
  hkaiNavMesh *v4; // rsi
  hkaiStaticTreeNavMeshQueryMediator *v5; // rbx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx

  v3 = staticTree;
  v4 = navMesh;
  v5 = this;
  if ( navMesh )
    hkReferencedObject::addReference((hkReferencedObject *)&navMesh->vfptr);
  v6 = (hkReferencedObject *)&v5->m_navMesh.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_navMesh.m_pntr = v4;
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v7 = (hkReferencedObject *)&v5->m_tree.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_tree.m_pntr = v3;
}

// File Line: 81
// RVA: 0xBD6790
hkSimdFloat32 *__fastcall NavMeshMediatorCPCollector::processLeaf(NavMeshMediatorCPCollector *this, hkSimdFloat32 *result, unsigned int leafKey, hkAabb *leafAabb, hkVector4f *queryPoint, hkVector4f *closestPointOut, hkSimdFloat32 *closestDistanceSquared)
{
  unsigned int v7; // edi
  hkaiNavMeshQueryMediator::GetClosestPointInput *v8; // r8
  NavMeshMediatorCPCollector *v9; // rsi
  hkaiSpatialQueryHitFilter *v10; // rcx
  hkSimdFloat32 *v11; // rbx
  hkSimdFloat32 *v12; // rax
  hkaiNavMeshQueryMediator::GetClosestPointInput *v13; // rax
  hkaiNavMeshCutter *v14; // rcx
  unsigned int v15; // edi
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  __m128i v19; // xmm2
  hkVector4f v20; // [rsp+30h] [rbp-18h]

  v7 = leafKey;
  v8 = this->m_gcpInput;
  v9 = this;
  v10 = v8->m_hitFilter;
  v11 = result;
  if ( v10
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v10->vfptr[2].__vecDelDtor)(
          v10,
          v8->m_instance,
          v7,
          v8->m_filterInfo,
          v8->m_userData) )
  {
    v12 = v11;
    *v11 = (hkSimdFloat32)xmmword_141A712A0;
    return v12;
  }
  v13 = v9->m_gcpInput;
  _mm_store_si128((__m128i *)&v20, (__m128i)queryPoint->m_quad);
  v14 = v13->m_navMeshCutter;
  if ( !v14 )
  {
    hkaiNavMeshUtils::getClosestPointOnFace(v9->m_mesh, queryPoint, v7, &v20);
    goto LABEL_9;
  }
  v15 = hkaiNavMeshCutter::getClosestPointOnFaceLocal(v14, queryPoint, v7 | (v9->m_runtimeIndex << 22), &v20);
  if ( v15 != -1 )
  {
    v7 = v15 & 0x3FFFFF;
LABEL_9:
    v16 = v20.m_quad;
    *closestPointOut = (hkVector4f)v20.m_quad;
    v17 = _mm_sub_ps(queryPoint->m_quad, v16);
    v18 = _mm_mul_ps(v17, v17);
    v19 = (__m128i)_mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                     _mm_shuffle_ps(v18, v18, 170));
    if ( *(float *)v19.m128i_i32 < closestDistanceSquared->m_real.m128_f32[0] )
      v9->m_bestFace = v7;
    _mm_store_si128((__m128i *)v11, v19);
    return v11;
  }
  *v11 = (hkSimdFloat32)xmmword_141A712A0;
  return v11;
}

// File Line: 123
// RVA: 0xBD5C50
__int64 __fastcall hkaiStaticTreeNavMeshQueryMediator::getClosestPoint(hkaiStaticTreeNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::GetClosestPointInput *input, hkVector4f *closestPointOut)
{
  hkaiStaticTreeNavMeshQueryMediator *v3; // rbp
  hkaiNavMeshQueryMediator::GetClosestPointInput *v4; // rdi
  hkVector4f *v5; // r14
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkaiNavMeshInstance *v11; // rbx
  hkaiSpatialQueryHitFilter *v12; // rcx
  unsigned int v13; // ebx
  hkVector4f *v14; // rsi
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  int v19; // eax
  hkcdStaticAabbTree *v20; // rcx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  hkVector4f point; // [rsp+30h] [rbp-48h]
  hkVector4f v28; // [rsp+40h] [rbp-38h]
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+50h] [rbp-28h]
  hkaiNavMesh *v30; // [rsp+58h] [rbp-20h]
  hkaiNavMeshQueryMediator::GetClosestPointInput *v31; // [rsp+60h] [rbp-18h]
  int v32; // [rsp+68h] [rbp-10h]
  int v33; // [rsp+6Ch] [rbp-Ch]

  v3 = this;
  v4 = input;
  v5 = closestPointOut;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtStaticTree::GCP";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v4->m_instance;
  if ( v11
    && (v12 = v4->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v12->vfptr[1].__first_virtual_table_function__)(
          v12,
          v4->m_instance,
          v4->m_filterInfo,
          v4->m_userData) )
  {
    v13 = -1;
  }
  else
  {
    v14 = &transform;
    if ( v4->m_localToWorldTransform )
      v14 = &v4->m_localToWorldTransform->m_rotation.m_col0;
    v15 = _mm_sub_ps(v4->m_position.m_quad, v14[3].m_quad);
    v16 = v14[2].m_quad;
    v17 = _mm_unpacklo_ps(v14->m_quad, v14[1].m_quad);
    v18 = _mm_movelh_ps(v17, v16);
    point.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v16, 212)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v15, v15, 170),
                       _mm_shuffle_ps(_mm_unpackhi_ps(v14->m_quad, v14[1].m_quad), v16, 228)));
    if ( v11 )
    {
      v19 = v11->m_runtimeId;
      LODWORD(v11) = 0;
      if ( v19 > 0 )
        LODWORD(v11) = v19;
    }
    v20 = v3->m_tree.m_pntr;
    collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshMediatorCPCollector::`vftable;
    v30 = v3->m_navMesh.m_pntr;
    v31 = v4;
    v32 = -1;
    v33 = (signed int)v11;
    hkcdStaticAabbTree::getClosestPoint(v20, &point, &v4->m_queryRadius, &collector, &v28);
    if ( v32 == -1 )
    {
      v13 = -1;
      *v5 = v4->m_position;
    }
    else
    {
      v13 = v32 | ((_DWORD)v11 << 22);
      v5->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 0), v14->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 85), v14[1].m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 170), v14[2].m_quad)),
                     v14[3].m_quad);
    }
    collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&hkcdAabbTreeQueries::ClosestPointCollector::`vftable;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
  return v13;
}sc();
    v25 = (signed __int64)(v22 + 2);

// File Line: 169
// RVA: 0xBD66A0
hkSimdFloat32 *__fastcall NavMeshMediatorBoundaryCollector::processLeaf(NavMeshMediatorBoundaryCollector *this, hkSimdFloat32 *result, __int64 leafKey, hkAabb *leafAabb, hkVector4f *queryPoint, hkVector4f *closestPointOut, hkSimdFloat32 *closestDistanceSquared)
{
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v7; // r9
  NavMeshMediatorBoundaryCollector *v8; // rdi
  hkSimdFloat32 *v9; // rbx
  hkaiSpatialQueryHitFilter *v10; // rcx
  int v11; // esi
  hkSimdFloat32 *v12; // rax
  hkVector4f *v13; // r9
  hkaiNavMeshCutter *v14; // rcx
  unsigned int v15; // eax
  int v16; // eax
  __m128 v17; // xmm0
  __m128i v18; // xmm0
  hkVector4f v19; // [rsp+30h] [rbp-18h]

  v7 = this->m_gcbInput;
  v8 = this;
  v9 = result;
  v10 = v7->m_hitFilter;
  v11 = leafKey;
  if ( v10
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, __int64, _QWORD, unsigned __int64))v10->vfptr[2].__vecDelDtor)(
          v10,
          v7->m_instance,
          leafKey,
          v7->m_filterInfo,
          v7->m_userData) )
  {
    goto LABEL_3;
  }
  v13 = &v8->m_gcbInput->m_projectionDirection;
  _mm_store_si128((__m128i *)&v19, (__m128i)queryPoint->m_quad);
  v14 = (hkaiNavMeshCutter *)v13[-1].m_quad.m128_u64[0];
  if ( v14 )
  {
    v15 = hkaiNavMeshCutter::getClosestBoundaryOnFaceLocal(v14, queryPoint, v11 | (v8->m_runtimeIndex << 22), v13, &v19);
    if ( v15 == -1 )
    {
LABEL_3:
      v12 = v9;
      *v9 = (hkSimdFloat32)xmmword_141A712A0;
      return v12;
    }
    v16 = v15 & 0x3FFFFF;
  }
  else
  {
    v16 = hkaiNavMeshUtils::getClosestBoundaryOnFace(v8->m_mesh, queryPoint, v11, v13, &v19);
  }
  v17 = v19.m_quad;
  *closestPointOut = (hkVector4f)v19.m_quad;
  v18 = (__m128i)_mm_shuffle_ps(v17, v17, 255);
  if ( *(float *)v18.m128i_i32 < closestDistanceSquared->m_real.m128_f32[0] )
    v8->m_bestEdge = v16;
  _mm_store_si128((__m128i *)v9, v18);
  return v9;
}

// File Line: 212
// RVA: 0xBD5E60
__int64 __fastcall hkaiStaticTreeNavMeshQueryMediator::getClosestBoundaryEdge(hkaiStaticTreeNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *input, hkVector4f *closestPointOut)
{
  hkaiStaticTreeNavMeshQueryMediator *v3; // rsi
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v4; // rdi
  hkVector4f *v5; // r14
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkaiNavMeshInstance *v11; // rbx
  hkaiSpatialQueryHitFilter *v12; // rcx
  unsigned int v13; // ebx
  hkVector4f *v14; // rbp
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  int v19; // eax
  hkcdStaticAabbTree *v20; // rcx
  __m128 v21; // xmm3
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  hkVector4f point; // [rsp+30h] [rbp-48h]
  hkVector4f v29; // [rsp+40h] [rbp-38h]
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+50h] [rbp-28h]
  hkaiNavMesh *v31; // [rsp+58h] [rbp-20h]
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v32; // [rsp+60h] [rbp-18h]
  int v33; // [rsp+68h] [rbp-10h]
  int v34; // [rsp+6Ch] [rbp-Ch]

  v3 = this;
  v4 = input;
  v5 = closestPointOut;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtStaticTree::GCBoundary";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v4->m_instance;
  if ( v11
    && (v12 = v4->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v12->vfptr[1].__first_virtual_table_function__)(
          v12,
          v4->m_instance,
          v4->m_filterInfo,
          v4->m_userData) )
  {
    v13 = -1;
  }
  else
  {
    v14 = &transform;
    if ( v4->m_localToWorldTransform )
      v14 = &v4->m_localToWorldTransform->m_rotation.m_col0;
    v15 = _mm_sub_ps(v4->m_position.m_quad, v14[3].m_quad);
    v16 = v14[2].m_quad;
    v17 = _mm_unpacklo_ps(v14->m_quad, v14[1].m_quad);
    v18 = _mm_movelh_ps(v17, v16);
    point.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v16, 212)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v15, v15, 170),
                       _mm_shuffle_ps(_mm_unpackhi_ps(v14->m_quad, v14[1].m_quad), v16, 228)));
    if ( v11 )
    {
      v19 = v11->m_runtimeId;
      LODWORD(v11) = 0;
      if ( v19 > 0 )
        LODWORD(v11) = v19;
    }
    v20 = v3->m_tree.m_pntr;
    collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshMediatorBoundaryCollector::`vftable;
    v31 = v3->m_navMesh.m_pntr;
    v32 = v4;
    v33 = -1;
    v34 = (signed int)v11;
    hkcdStaticAabbTree::getClosestPoint(v20, &point, &v4->m_queryRadius, &collector, &v29);
    if ( v33 == -1 )
    {
      v13 = -1;
      *v5 = v4->m_position;
    }
    else
    {
      v13 = v33 | ((_DWORD)v11 << 22);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 85), v14[1].m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 0), v14->m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 170), v14[2].m_quad)),
              v14[3].m_quad);
      v5->m_quad = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, _mm_shuffle_ps(v29.m_quad, v29.m_quad, 255)), 196);
    }
    collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&hkcdAabbTreeQueries::ClosestPointCollector::`vftable;
  }
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v24[1] = v26;
  }
  return v13;
}

// File Line: 261
// RVA: 0xBD68B0
signed __int64 __fastcall NavMeshMediatorRayCastCollector::processLeaf(NavMeshMediatorRayCastCollector *this, unsigned int leafKey, hkAabb *leafAabb, hkSimdFloat32 *hitFractionInOut)
{
  hkaiNavMeshQueryMediator::RaycastInput *v4; // r8
  NavMeshMediatorRayCastCollector *v5; // rbx
  unsigned int v6; // edi
  hkaiSpatialQueryHitFilter *v7; // rcx
  hkSimdFloat32 *v8; // rsi
  hkaiNavMeshUtils *v9; // rcx
  __m128 v10; // xmm0
  signed __int64 result; // rax
  hkSimdFloat32 *hitFractionOut; // [rsp+20h] [rbp-28h]
  __m128 v13; // [rsp+30h] [rbp-18h]

  v4 = this->m_rayInput;
  v5 = this;
  v6 = leafKey;
  v7 = v4->m_hitFilter;
  v8 = hitFractionInOut;
  if ( v7 )
  {
    hitFractionOut = (hkSimdFloat32 *)v4->m_userData;
    if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD))v7->vfptr[2].__vecDelDtor)(
            v7,
            v4->m_instance,
            leafKey,
            v4->m_filterInfo) )
      return 0i64;
  }
  v9 = (hkaiNavMeshUtils *)v5->m_mesh;
  v13 = query.m_quad;
  if ( !(unsigned __int8)hkaiNavMeshUtils::castRayFace<hkaiNavMesh>(
                           v9,
                           (hkaiNavMesh *)v6,
                           (__int64)&v5->m_ray,
                           (hkcdRay *)&v13,
                           hitFractionOut) )
    return 0i64;
  v10 = v13;
  if ( v13.m128_f32[0] >= v8->m_real.m128_f32[0] )
    return 0i64;
  *v8 = (hkSimdFloat32)v13;
  result = 1i64;
  v5->m_bestHitFraction.m_real = v10;
  v5->m_bestFace = v6;
  return result;
}

// File Line: 292
// RVA: 0xBD6080
__int64 __fastcall hkaiStaticTreeNavMeshQueryMediator::castRay(hkaiStaticTreeNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::RaycastInput *input, hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  hkaiStaticTreeNavMeshQueryMediator *v3; // rbp
  hkaiNavMeshQueryMediator::HitDetails *v4; // rsi
  hkaiNavMeshQueryMediator::RaycastInput *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkaiNavMeshInstance *v11; // rdi
  hkaiSpatialQueryHitFilter *v12; // rcx
  unsigned __int8 v13; // bl
  hkVector4f *v14; // rcx
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm7
  __m128 v20; // xmm5
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __int64 v25; // rax
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  __m128i v28; // xmm6
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  hkcdStaticAabbTree *v31; // rcx
  int v32; // ecx
  int v33; // ecx
  _QWORD *v34; // rax
  _QWORD *v35; // rcx
  _QWORD *v36; // r8
  unsigned __int64 v37; // rax
  signed __int64 v38; // rcx
  hkVector4f end; // [rsp+20h] [rbp-A8h]
  hkVector4f start; // [rsp+30h] [rbp-98h]
  hkcdAabbTreeQueries::RaycastCollector collector; // [rsp+40h] [rbp-88h]
  __int64 v43; // [rsp+48h] [rbp-80h]
  hkaiNavMeshQueryMediator::RaycastInput *v44; // [rsp+50h] [rbp-78h]
  int v45; // [rsp+58h] [rbp-70h]
  __m128 v46; // [rsp+60h] [rbp-68h]
  __m128 v47; // [rsp+70h] [rbp-58h]
  __m128 v48; // [rsp+80h] [rbp-48h]
  __m128 v49; // [rsp+90h] [rbp-38h]

  v3 = this;
  v4 = hitOut;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtStaticTree::castRay";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v5->m_instance;
  if ( v11
    && (v12 = v5->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v12->vfptr[1].__first_virtual_table_function__)(
          v12,
          v5->m_instance,
          v5->m_filterInfo,
          v5->m_userData) )
  {
    v13 = 0;
  }
  else
  {
    v14 = &transform;
    if ( v5->m_localToWorldTransform )
      v14 = &v5->m_localToWorldTransform->m_rotation.m_col0;
    v15 = _mm_sub_ps(v5->m_from.m_quad, v14[3].m_quad);
    v16 = v14[2].m_quad;
    v17 = _mm_unpacklo_ps(v14->m_quad, v14[1].m_quad);
    v18 = _mm_movelh_ps(v17, v16);
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v16, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
            _mm_mul_ps(
              _mm_shuffle_ps(v15, v15, 170),
              _mm_shuffle_ps(_mm_unpackhi_ps(v14->m_quad, v14[1].m_quad), v16, 228)));
    v20 = v5->m_to.m_quad;
    start.m_quad = v19;
    v21 = _mm_sub_ps(v20, v14[3].m_quad);
    v22 = v14[2].m_quad;
    v23 = _mm_unpacklo_ps(v14->m_quad, v14[1].m_quad);
    v24 = _mm_shuffle_ps(_mm_unpackhi_ps(v14->m_quad, v14[1].m_quad), v22, 228);
    collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&NavMeshMediatorRayCastCollector::`vftable;
    v25 = (__int64)v3->m_navMesh.m_pntr;
    v44 = v5;
    v43 = v25;
    v45 = -1;
    v26 = _mm_movelh_ps(v23, v22);
    v49 = query.m_quad;
    v27 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(_mm_movehl_ps(v26, v23), v22, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v26)),
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v24));
    end.m_quad = v27;
    v28 = (__m128i)_mm_sub_ps(v27, v19);
    v29 = _mm_cmpeqps((__m128)0i64, (__m128)v28);
    v30 = _mm_rcp_ps((__m128)v28);
    v47 = _mm_shuffle_ps((__m128)v28, _mm_unpackhi_ps((__m128)v28, query.m_quad), 196);
    v31 = v3->m_tree.m_pntr;
    v46 = v19;
    v48 = _mm_or_ps(
            _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v28, 0x1Fu), 0x1Fu), (__m128)_xmm), v29),
            _mm_andnot_ps(v29, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v28, v30)), v30)));
    v48.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v47)) & 7 | 0x3F000000;
    if ( hkcdStaticAabbTree::castRay(v31, &start, &end, &collector) )
    {
      v32 = 0;
      if ( v11 && v11->m_runtimeId > 0 )
        v32 = v11->m_runtimeId;
      v13 = 1;
      v33 = v45 | (v32 << 22);
      v4->m_hitFraction.m_real = v49;
      v4->m_hitFaceKey = v33;
    }
    else
    {
      v13 = 0;
    }
    collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&hkcdAabbTreeQueries::RaycastCollector::`vftable;
  }
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  v36 = v34;
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Et";
    v37 = __rdtsc();
    v38 = (signed __int64)(v35 + 2);
    *(_DWORD *)(v38 - 8) = v37;
    v36[1] = v38;
  }
  return v13;
}

// File Line: 323
// RVA: 0xBD6340
void __fastcall hkaiStaticTreeNavMeshQueryMediator::queryAabb(hkaiStaticTreeNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::AabbQueryInput *input, hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  hkaiStaticTreeNavMeshQueryMediator *v3; // rbp
  hkArray<unsigned int,hkContainerTempAllocator> *v4; // rbx
  hkaiNavMeshQueryMediator::AabbQueryInput *v5; // rsi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkaiNavMeshInstance *v11; // rdi
  hkaiSpatialQueryHitFilter *v12; // rcx
  hkVector4f *v13; // rcx
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  int v17; // er15
  signed __int64 v18; // rdi
  signed __int64 v19; // r12
  int v20; // er14
  signed __int64 v21; // rbp
  hkaiSpatialQueryHitFilter *v22; // rcx
  unsigned int v23; // edi
  __int64 v24; // rax
  _QWORD *v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  hkSimdFloat32 extraRadius; // [rsp+30h] [rbp-88h]
  hkAabb aabbOut; // [rsp+40h] [rbp-78h]
  hkTransformf BvToWorld; // [rsp+60h] [rbp-58h]

  v3 = this;
  v4 = hits;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtStaticTree::queryAabb";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v5->m_instance;
  if ( !v11
    || (v12 = v5->m_hitFilter) == 0i64
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v12->vfptr[1].__first_virtual_table_function__)(
         v12,
         v5->m_instance,
         v5->m_filterInfo,
         v5->m_userData) )
  {
    v13 = &transform;
    if ( v5->m_localToWorldTransform )
      v13 = &v5->m_localToWorldTransform->m_rotation.m_col0;
    v14 = v13[2].m_quad;
    v15 = _mm_unpacklo_ps(v13->m_quad, v13[1].m_quad);
    BvToWorld.m_rotation.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v13->m_quad, v13[1].m_quad), v14, 228);
    BvToWorld.m_rotation.m_col0.m_quad = _mm_movelh_ps(v15, v14);
    BvToWorld.m_rotation.m_col1.m_quad = _mm_shuffle_ps(
                                           _mm_movehl_ps(BvToWorld.m_rotation.m_col0.m_quad, v15),
                                           v14,
                                           212);
    v16 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v13[3].m_quad);
    extraRadius.m_real = ::aabbOut.m_quad;
    BvToWorld.m_translation.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), BvToWorld.m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), BvToWorld.m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), BvToWorld.m_rotation.m_col2.m_quad));
    hkAabbUtil::calcAabb(&BvToWorld, &v5->m_aabb, &extraRadius, &aabbOut);
    v17 = 0;
    if ( v11 && v11->m_runtimeId > 0 )
      v17 = v11->m_runtimeId;
    v18 = v4->m_size;
    hkcdStaticAabbTree::queryAabb(v3->m_tree.m_pntr, &aabbOut, v4);
    v19 = v18;
    v20 = v4->m_size - 1;
    v21 = v20;
    if ( v20 >= v18 )
    {
      do
      {
        v22 = v5->m_hitFilter;
        v23 = v4->m_data[v21] & 0x3FFFFF;
        if ( !v22
          || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v22->vfptr[2].__vecDelDtor)(
               v22,
               v5->m_instance,
               v23,
               v5->m_filterInfo,
               v5->m_userData) )
        {
          v4->m_data[v21] = v23 | (v17 << 22);
        }
        else
        {
          v24 = --v4->m_size;
          if ( (_DWORD)v24 != v20 )
            v4->m_data[v21] = v4->m_data[v24];
        }
        --v21;
        --v20;
      }
      while ( v21 >= v19 );
    }
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  v27 = v25;
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v27[1] = v29;
  }
}

// File Line: 360
// RVA: 0xBD65B0
int __fastcall hkaiStaticTreeNavMeshQueryMediator::getMemoryFootPrint(hkaiStaticTreeNavMeshQueryMediator *this)
{
  return hkcdStaticAabbTree::getMemoryFootPrint(this->m_tree.m_pntr);
}

