// File Line: 20
// RVA: 0xBD59F0
void __fastcall hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(
        hkaiStaticTreeNavMeshQueryMediator *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStaticTreeNavMeshQueryMediator::`vftable;
  this->m_tree.m_pntr = 0i64;
  this->m_navMesh.m_pntr = 0i64;
}

// File Line: 26
// RVA: 0xBD5A20
void __fastcall hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStaticTreeNavMeshQueryMediator::`vftable;
}

// File Line: 31
// RVA: 0xBD5A40
void __fastcall hkaiStaticTreeNavMeshQueryMediator::~hkaiStaticTreeNavMeshQueryMediator(
        hkaiStaticTreeNavMeshQueryMediator *this)
{
  hkaiNavMesh *m_pntr; // rcx
  hkcdStaticAabbTree *v3; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiStaticTreeNavMeshQueryMediator::`vftable;
  m_pntr = this->m_navMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navMesh.m_pntr = 0i64;
  v3 = this->m_tree.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_tree.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 35
// RVA: 0xBD5AA0
void __fastcall hkaiStaticTreeNavMeshQueryMediator::setNavMesh(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkaiNavMesh *mesh)
{
  hkaiNavMesh *m_pntr; // rcx
  int m_size; // ebp
  hkcdStaticAabbTree *v6; // rsi
  unsigned int i; // ebx
  hkaiNavMesh *v8; // rcx
  _QWORD **Value; // rax
  hkcdStaticAabbTree *v10; // rax
  hkcdStaticAabbTree *v11; // rax
  hkcdStaticAabbTree *v12; // rcx
  hkAabb *aabbOut[2]; // [rsp+20h] [rbp-68h] BYREF
  hkcdDynamicAabbTree dynTree; // [rsp+30h] [rbp-58h] BYREF
  hkAabb extraRadius; // [rsp+50h] [rbp-38h] BYREF
  hkResult result; // [rsp+90h] [rbp+8h] BYREF

  if ( mesh )
    hkReferencedObject::addReference(mesh);
  m_pntr = this->m_navMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navMesh.m_pntr = mesh;
  m_size = mesh->m_faces.m_size;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&dynTree);
  hkcdDynamicAabbTree::reserveLeaves(&dynTree, &result, m_size);
  v6 = 0i64;
  for ( i = 0; (int)i < m_size; ++i )
  {
    v8 = this->m_navMesh.m_pntr;
    *(_OWORD *)aabbOut = 0i64;
    hkaiNavMeshUtils::calcFaceAabb<hkaiNavMesh>(
      (hkaiNavMeshUtils *)v8,
      (hkaiNavMesh *)i,
      (__m128 *)aabbOut,
      (hkSimdFloat32 *)&extraRadius);
    hkcdDynamicAabbTree::insert(&dynTree, &extraRadius, i);
  }
  hkcdDynamicAabbTree::rebuild(&dynTree);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkcdStaticAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( v10 )
  {
    hkcdStaticAabbTree::hkcdStaticAabbTree(v10);
    v6 = v11;
  }
  v12 = this->m_tree.m_pntr;
  if ( v12 && v12 != v6 )
    hkReferencedObject::removeReference(v12);
  this->m_tree.m_pntr = v6;
  hkcdStaticAabbTree::buildFromDynamicTree(v6, &dynTree);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&dynTree);
}

// File Line: 56
// RVA: 0xBD5BE0
void __fastcall hkaiStaticTreeNavMeshQueryMediator::setNavMeshAndTree(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkaiNavMesh *navMesh,
        hkcdStaticAabbTree *staticTree)
{
  hkaiNavMesh *m_pntr; // rcx
  hkcdStaticAabbTree *v7; // rcx

  if ( navMesh )
    hkReferencedObject::addReference(navMesh);
  m_pntr = this->m_navMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navMesh.m_pntr = navMesh;
  if ( staticTree )
    hkReferencedObject::addReference(staticTree);
  v7 = this->m_tree.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  this->m_tree.m_pntr = staticTree;
}

// File Line: 81
// RVA: 0xBD6790
hkSimdFloat32 *__fastcall NavMeshMediatorCPCollector::processLeaf(
        NavMeshMediatorCPCollector *this,
        hkSimdFloat32 *result,
        int leafKey,
        hkAabb *leafAabb,
        hkVector4f *queryPoint,
        hkVector4f *closestPointOut,
        hkSimdFloat32 *closestDistanceSquared)
{
  hkaiNavMeshQueryMediator::GetClosestPointInput *m_gcpInput; // r8
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  hkSimdFloat32 *v12; // rax
  hkaiNavMeshQueryMediator::GetClosestPointInput *v13; // rax
  hkaiNavMeshCutter *m_navMeshCutter; // rcx
  unsigned int ClosestPointOnFaceLocal; // edi
  __m128 m_quad; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  hkSimdFloat32 v19; // xmm2
  hkVector4f v20; // [rsp+30h] [rbp-18h] BYREF

  m_gcpInput = this->m_gcpInput;
  m_hitFilter = m_gcpInput->m_hitFilter;
  if ( m_hitFilter
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
          m_hitFilter,
          m_gcpInput->m_instance,
          (unsigned int)leafKey,
          m_gcpInput->m_filterInfo,
          m_gcpInput->m_userData) )
  {
    v12 = result;
    *result = (hkSimdFloat32)xmmword_141A712A0;
    return v12;
  }
  v13 = this->m_gcpInput;
  v20.m_quad = queryPoint->m_quad;
  m_navMeshCutter = v13->m_navMeshCutter;
  if ( !m_navMeshCutter )
  {
    hkaiNavMeshUtils::getClosestPointOnFace(this->m_mesh, queryPoint, leafKey, &v20);
    goto LABEL_9;
  }
  ClosestPointOnFaceLocal = hkaiNavMeshCutter::getClosestPointOnFaceLocal(
                              m_navMeshCutter,
                              queryPoint,
                              leafKey | (this->m_runtimeIndex << 22),
                              &v20);
  if ( ClosestPointOnFaceLocal != -1 )
  {
    leafKey = ClosestPointOnFaceLocal & 0x3FFFFF;
LABEL_9:
    m_quad = v20.m_quad;
    *closestPointOut = (hkVector4f)v20.m_quad;
    v17 = _mm_sub_ps(queryPoint->m_quad, m_quad);
    v18 = _mm_mul_ps(v17, v17);
    v19.m_real = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                   _mm_shuffle_ps(v18, v18, 170));
    if ( v19.m_real.m128_f32[0] < closestDistanceSquared->m_real.m128_f32[0] )
      this->m_bestFace = leafKey;
    *result = (hkSimdFloat32)v19.m_real;
    return result;
  }
  *result = (hkSimdFloat32)xmmword_141A712A0;
  return result;
}

// File Line: 123
// RVA: 0xBD5C50
__int64 __fastcall hkaiStaticTreeNavMeshQueryMediator::getClosestPoint(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::GetClosestPointInput *input,
        hkVector4f *closestPointOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkaiNavMeshInstance *m_instance; // rbx
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned int v13; // ebx
  hkTransformf *m_localToWorldTransform; // rsi
  __m128 v15; // xmm5
  __m128 m_quad; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  int m_runtimeId; // eax
  hkcdStaticAabbTree *m_pntr; // rcx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkVector4f point; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f v28; // [rsp+40h] [rbp-38h] BYREF
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+50h] [rbp-28h] BYREF
  hkaiNavMesh *v30; // [rsp+58h] [rbp-20h]
  hkaiNavMeshQueryMediator::GetClosestPointInput *v31; // [rsp+60h] [rbp-18h]
  int v32; // [rsp+68h] [rbp-10h]
  int v33; // [rsp+6Ch] [rbp-Ch]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtStaticTree::GCP";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_instance = input->m_instance;
  if ( m_instance
    && (m_hitFilter = input->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))m_hitFilter->vfptr[1].__first_virtual_table_function__)(
          m_hitFilter,
          input->m_instance,
          input->m_filterInfo,
          input->m_userData) )
  {
    v13 = -1;
  }
  else
  {
    m_localToWorldTransform = (hkTransformf *)&transform;
    if ( input->m_localToWorldTransform )
      m_localToWorldTransform = input->m_localToWorldTransform;
    v15 = _mm_sub_ps(input->m_position.m_quad, m_localToWorldTransform->m_translation.m_quad);
    m_quad = m_localToWorldTransform->m_rotation.m_col2.m_quad;
    v17 = _mm_unpacklo_ps(
            m_localToWorldTransform->m_rotation.m_col0.m_quad,
            m_localToWorldTransform->m_rotation.m_col1.m_quad);
    v18 = _mm_movelh_ps(v17, m_quad);
    point.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), m_quad, 212)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v15, v15, 170),
                       _mm_shuffle_ps(
                         _mm_unpackhi_ps(
                           m_localToWorldTransform->m_rotation.m_col0.m_quad,
                           m_localToWorldTransform->m_rotation.m_col1.m_quad),
                         m_quad,
                         228)));
    if ( m_instance )
    {
      m_runtimeId = m_instance->m_runtimeId;
      LODWORD(m_instance) = 0;
      if ( m_runtimeId > 0 )
        LODWORD(m_instance) = m_runtimeId;
    }
    m_pntr = this->m_tree.m_pntr;
    collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshMediatorCPCollector::`vftable;
    v30 = this->m_navMesh.m_pntr;
    v31 = input;
    v32 = -1;
    v33 = (int)m_instance;
    hkcdStaticAabbTree::getClosestPoint(m_pntr, &point, &input->m_queryRadius, &collector, &v28);
    if ( v32 == -1 )
    {
      v13 = -1;
      *closestPointOut = input->m_position;
    }
    else
    {
      v13 = v32 | ((_DWORD)m_instance << 22);
      closestPointOut->m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v28.m_quad, v28.m_quad, 0),
                                        m_localToWorldTransform->m_rotation.m_col0.m_quad),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v28.m_quad, v28.m_quad, 85),
                                        m_localToWorldTransform->m_rotation.m_col1.m_quad)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v28.m_quad, v28.m_quad, 170),
                                      m_localToWorldTransform->m_rotation.m_col2.m_quad)),
                                  m_localToWorldTransform->m_translation.m_quad);
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
    v25 = v22 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v23[1] = v25;
  }
  return v13;
}

// File Line: 169
// RVA: 0xBD66A0
hkSimdFloat32 *__fastcall NavMeshMediatorBoundaryCollector::processLeaf(
        NavMeshMediatorBoundaryCollector *this,
        hkSimdFloat32 *result,
        __int64 leafKey,
        hkAabb *leafAabb,
        hkVector4f *queryPoint,
        hkVector4f *closestPointOut,
        hkSimdFloat32 *closestDistanceSquared)
{
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *m_gcbInput; // r9
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  int v11; // esi
  hkSimdFloat32 *v12; // rax
  hkVector4f *p_m_projectionDirection; // r9
  hkaiNavMeshCutter *v14; // rcx
  unsigned int ClosestBoundaryOnFaceLocal; // eax
  int ClosestBoundaryOnFace; // eax
  __m128 m_quad; // xmm0
  hkSimdFloat32 v18; // xmm0
  hkVector4f v19; // [rsp+30h] [rbp-18h] BYREF

  m_gcbInput = this->m_gcbInput;
  m_hitFilter = m_gcbInput->m_hitFilter;
  v11 = leafKey;
  if ( m_hitFilter
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, __int64, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
          m_hitFilter,
          m_gcbInput->m_instance,
          leafKey,
          m_gcbInput->m_filterInfo,
          m_gcbInput->m_userData) )
  {
    goto LABEL_3;
  }
  p_m_projectionDirection = &this->m_gcbInput->m_projectionDirection;
  v19.m_quad = queryPoint->m_quad;
  v14 = (hkaiNavMeshCutter *)p_m_projectionDirection[-1].m_quad.m128_u64[0];
  if ( v14 )
  {
    ClosestBoundaryOnFaceLocal = hkaiNavMeshCutter::getClosestBoundaryOnFaceLocal(
                                   v14,
                                   queryPoint,
                                   v11 | (this->m_runtimeIndex << 22),
                                   p_m_projectionDirection,
                                   &v19);
    if ( ClosestBoundaryOnFaceLocal == -1 )
    {
LABEL_3:
      v12 = result;
      *result = (hkSimdFloat32)xmmword_141A712A0;
      return v12;
    }
    ClosestBoundaryOnFace = ClosestBoundaryOnFaceLocal & 0x3FFFFF;
  }
  else
  {
    ClosestBoundaryOnFace = hkaiNavMeshUtils::getClosestBoundaryOnFace(
                              this->m_mesh,
                              queryPoint,
                              v11,
                              p_m_projectionDirection,
                              &v19);
  }
  m_quad = v19.m_quad;
  *closestPointOut = (hkVector4f)v19.m_quad;
  v18.m_real = _mm_shuffle_ps(m_quad, m_quad, 255);
  if ( v18.m_real.m128_f32[0] < closestDistanceSquared->m_real.m128_f32[0] )
    this->m_bestEdge = ClosestBoundaryOnFace;
  *result = (hkSimdFloat32)v18.m_real;
  return result;
}

// File Line: 212
// RVA: 0xBD5E60
__int64 __fastcall hkaiStaticTreeNavMeshQueryMediator::getClosestBoundaryEdge(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *input,
        hkVector4f *closestPointOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkaiNavMeshInstance *m_instance; // rbx
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned int v13; // ebx
  hkTransformf *m_localToWorldTransform; // rbp
  __m128 v15; // xmm5
  __m128 m_quad; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  int m_runtimeId; // eax
  hkcdStaticAabbTree *m_pntr; // rcx
  __m128 v21; // xmm3
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  hkVector4f point; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f v29; // [rsp+40h] [rbp-38h] BYREF
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+50h] [rbp-28h] BYREF
  hkaiNavMesh *v31; // [rsp+58h] [rbp-20h]
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v32; // [rsp+60h] [rbp-18h]
  int v33; // [rsp+68h] [rbp-10h]
  int v34; // [rsp+6Ch] [rbp-Ch]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtStaticTree::GCBoundary";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_instance = input->m_instance;
  if ( m_instance
    && (m_hitFilter = input->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))m_hitFilter->vfptr[1].__first_virtual_table_function__)(
          m_hitFilter,
          input->m_instance,
          input->m_filterInfo,
          input->m_userData) )
  {
    v13 = -1;
  }
  else
  {
    m_localToWorldTransform = (hkTransformf *)&transform;
    if ( input->m_localToWorldTransform )
      m_localToWorldTransform = input->m_localToWorldTransform;
    v15 = _mm_sub_ps(input->m_position.m_quad, m_localToWorldTransform->m_translation.m_quad);
    m_quad = m_localToWorldTransform->m_rotation.m_col2.m_quad;
    v17 = _mm_unpacklo_ps(
            m_localToWorldTransform->m_rotation.m_col0.m_quad,
            m_localToWorldTransform->m_rotation.m_col1.m_quad);
    v18 = _mm_movelh_ps(v17, m_quad);
    point.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), m_quad, 212)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v15, v15, 170),
                       _mm_shuffle_ps(
                         _mm_unpackhi_ps(
                           m_localToWorldTransform->m_rotation.m_col0.m_quad,
                           m_localToWorldTransform->m_rotation.m_col1.m_quad),
                         m_quad,
                         228)));
    if ( m_instance )
    {
      m_runtimeId = m_instance->m_runtimeId;
      LODWORD(m_instance) = 0;
      if ( m_runtimeId > 0 )
        LODWORD(m_instance) = m_runtimeId;
    }
    m_pntr = this->m_tree.m_pntr;
    collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavMeshMediatorBoundaryCollector::`vftable;
    v31 = this->m_navMesh.m_pntr;
    v32 = input;
    v33 = -1;
    v34 = (int)m_instance;
    hkcdStaticAabbTree::getClosestPoint(m_pntr, &point, &input->m_queryRadius, &collector, &v29);
    if ( v33 == -1 )
    {
      v13 = -1;
      *closestPointOut = input->m_position;
    }
    else
    {
      v13 = v33 | ((_DWORD)m_instance << 22);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v29.m_quad, v29.m_quad, 85),
                    m_localToWorldTransform->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v29.m_quad, v29.m_quad, 0),
                    m_localToWorldTransform->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v29.m_quad, v29.m_quad, 170),
                  m_localToWorldTransform->m_rotation.m_col2.m_quad)),
              m_localToWorldTransform->m_translation.m_quad);
      closestPointOut->m_quad = _mm_shuffle_ps(
                                  v21,
                                  _mm_unpackhi_ps(v21, _mm_shuffle_ps(v29.m_quad, v29.m_quad, 255)),
                                  196);
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
    v26 = v23 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v24[1] = v26;
  }
  return v13;
}

// File Line: 261
// RVA: 0xBD68B0
__int64 __fastcall NavMeshMediatorRayCastCollector::processLeaf(
        NavMeshMediatorRayCastCollector *this,
        int leafKey,
        hkAabb *leafAabb,
        hkSimdFloat32 *hitFractionInOut)
{
  hkaiNavMeshQueryMediator::RaycastInput *m_rayInput; // r8
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  hkaiNavMeshUtils *m_mesh; // rcx
  hkSimdFloat32 v10; // xmm0
  __int64 result; // rax
  hkSimdFloat32 *hitFractionOut; // [rsp+20h] [rbp-28h]
  _BYTE v13[24]; // [rsp+30h] [rbp-18h] BYREF

  m_rayInput = this->m_rayInput;
  m_hitFilter = m_rayInput->m_hitFilter;
  if ( m_hitFilter )
  {
    hitFractionOut = (hkSimdFloat32 *)m_rayInput->m_userData;
    if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD))m_hitFilter->vfptr[2].__vecDelDtor)(
            m_hitFilter,
            m_rayInput->m_instance,
            (unsigned int)leafKey,
            m_rayInput->m_filterInfo) )
      return 0i64;
  }
  m_mesh = (hkaiNavMeshUtils *)this->m_mesh;
  *(hkVector4f *)v13 = (hkVector4f)query.m_quad;
  if ( !(unsigned __int8)hkaiNavMeshUtils::castRayFace<hkaiNavMesh>(
                           m_mesh,
                           (hkaiNavMesh *)(unsigned int)leafKey,
                           &this->m_ray.m_origin.m_quad,
                           (hkcdRay *)v13,
                           hitFractionOut) )
    return 0i64;
  v10.m_real = *(__m128 *)v13;
  if ( *(float *)v13 >= hitFractionInOut->m_real.m128_f32[0] )
    return 0i64;
  *hitFractionInOut = *(hkSimdFloat32 *)v13;
  result = 1i64;
  this->m_bestHitFraction = (hkSimdFloat32)v10.m_real;
  this->m_bestFace = leafKey;
  return result;
}

// File Line: 292
// RVA: 0xBD6080
__int64 __fastcall hkaiStaticTreeNavMeshQueryMediator::castRay(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::RaycastInput *input,
        hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkaiNavMeshInstance *m_instance; // rdi
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned __int8 v13; // bl
  hkTransformf *m_localToWorldTransform; // rcx
  __m128 v15; // xmm5
  __m128 m_quad; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm7
  hkVector4f v20; // xmm5
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  hkaiNavMesh *m_pntr; // rax
  __m128 v26; // xmm2
  __m128i v27; // xmm6
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  hkcdStaticAabbTree *v30; // rcx
  int m_runtimeId; // ecx
  int v32; // ecx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  hkVector4f end; // [rsp+20h] [rbp-A8h] BYREF
  hkVector4f start; // [rsp+30h] [rbp-98h] BYREF
  hkcdAabbTreeQueries::RaycastCollector collector; // [rsp+40h] [rbp-88h] BYREF
  hkaiNavMesh *v42; // [rsp+48h] [rbp-80h]
  hkaiNavMeshQueryMediator::RaycastInput *v43; // [rsp+50h] [rbp-78h]
  int v44; // [rsp+58h] [rbp-70h]
  __m128 v45; // [rsp+60h] [rbp-68h]
  __m128 v46; // [rsp+70h] [rbp-58h]
  __m128 v47; // [rsp+80h] [rbp-48h]
  __m128 v48; // [rsp+90h] [rbp-38h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtStaticTree::castRay";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_instance = input->m_instance;
  if ( m_instance
    && (m_hitFilter = input->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))m_hitFilter->vfptr[1].__first_virtual_table_function__)(
          m_hitFilter,
          input->m_instance,
          input->m_filterInfo,
          input->m_userData) )
  {
    v13 = 0;
  }
  else
  {
    m_localToWorldTransform = (hkTransformf *)&transform;
    if ( input->m_localToWorldTransform )
      m_localToWorldTransform = input->m_localToWorldTransform;
    v15 = _mm_sub_ps(input->m_from.m_quad, m_localToWorldTransform->m_translation.m_quad);
    m_quad = m_localToWorldTransform->m_rotation.m_col2.m_quad;
    v17 = _mm_unpacklo_ps(
            m_localToWorldTransform->m_rotation.m_col0.m_quad,
            m_localToWorldTransform->m_rotation.m_col1.m_quad);
    v18 = _mm_movelh_ps(v17, m_quad);
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), m_quad, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
            _mm_mul_ps(
              _mm_shuffle_ps(v15, v15, 170),
              _mm_shuffle_ps(
                _mm_unpackhi_ps(
                  m_localToWorldTransform->m_rotation.m_col0.m_quad,
                  m_localToWorldTransform->m_rotation.m_col1.m_quad),
                m_quad,
                228)));
    v20.m_quad = (__m128)input->m_to;
    start.m_quad = v19;
    v21 = _mm_sub_ps(v20.m_quad, m_localToWorldTransform->m_translation.m_quad);
    v22 = m_localToWorldTransform->m_rotation.m_col2.m_quad;
    v23 = _mm_unpacklo_ps(
            m_localToWorldTransform->m_rotation.m_col0.m_quad,
            m_localToWorldTransform->m_rotation.m_col1.m_quad);
    v24 = _mm_shuffle_ps(
            _mm_unpackhi_ps(
              m_localToWorldTransform->m_rotation.m_col0.m_quad,
              m_localToWorldTransform->m_rotation.m_col1.m_quad),
            v22,
            228);
    collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&NavMeshMediatorRayCastCollector::`vftable;
    m_pntr = this->m_navMesh.m_pntr;
    v43 = input;
    v42 = m_pntr;
    v44 = -1;
    v26 = _mm_movelh_ps(v23, v22);
    v48 = query.m_quad;
    end.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(_mm_movehl_ps(v26, v23), v22, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v26)),
                   _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v24));
    v27 = (__m128i)_mm_sub_ps(end.m_quad, v19);
    v28 = _mm_cmpeq_ps((__m128)0i64, (__m128)v27);
    v29 = _mm_rcp_ps((__m128)v27);
    v46 = _mm_shuffle_ps((__m128)v27, _mm_unpackhi_ps((__m128)v27, query.m_quad), 196);
    v30 = this->m_tree.m_pntr;
    v45 = v19;
    v47 = _mm_or_ps(
            _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v27, 0x1Fu), 0x1Fu), (__m128)_xmm), v28),
            _mm_andnot_ps(v28, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v27, v29)), v29)));
    v47.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v46)) & 7 | 0x3F000000;
    if ( hkcdStaticAabbTree::castRay(v30, &start, &end, &collector) )
    {
      m_runtimeId = 0;
      if ( m_instance && m_instance->m_runtimeId > 0 )
        m_runtimeId = m_instance->m_runtimeId;
      v13 = 1;
      v32 = v44 | (m_runtimeId << 22);
      hitOut->m_hitFraction.m_real = v48;
      hitOut->m_hitFaceKey = v32;
    }
    else
    {
      v13 = 0;
    }
    collector.vfptr = (hkcdAabbTreeQueries::RaycastCollectorVtbl *)&hkcdAabbTreeQueries::RaycastCollector::`vftable;
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  v35 = v33;
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v36 = __rdtsc();
    v37 = v34 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v35[1] = v37;
  }
  return v13;
}

// File Line: 323
// RVA: 0xBD6340
void __fastcall hkaiStaticTreeNavMeshQueryMediator::queryAabb(
        hkaiStaticTreeNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::AabbQueryInput *input,
        hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkaiNavMeshInstance *m_instance; // rdi
  hkaiSpatialQueryHitFilter *v12; // rcx
  hkTransformf *m_localToWorldTransform; // rcx
  __m128 m_quad; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  int m_runtimeId; // r15d
  __int64 m_size; // rdi
  __int64 v19; // r12
  int v20; // r14d
  __int64 v21; // rbp
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned int v23; // edi
  __int64 v24; // rax
  _QWORD *v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  hkSimdFloat32 extraRadius; // [rsp+30h] [rbp-88h] BYREF
  hkAabb aabbOut; // [rsp+40h] [rbp-78h] BYREF
  hkTransformf BvToWorld; // [rsp+60h] [rbp-58h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtStaticTree::queryAabb";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_instance = input->m_instance;
  if ( !m_instance
    || (v12 = input->m_hitFilter) == 0i64
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v12->vfptr[1].__first_virtual_table_function__)(
         v12,
         input->m_instance,
         input->m_filterInfo,
         input->m_userData) )
  {
    m_localToWorldTransform = (hkTransformf *)&transform;
    if ( input->m_localToWorldTransform )
      m_localToWorldTransform = input->m_localToWorldTransform;
    m_quad = m_localToWorldTransform->m_rotation.m_col2.m_quad;
    v15 = _mm_unpacklo_ps(
            m_localToWorldTransform->m_rotation.m_col0.m_quad,
            m_localToWorldTransform->m_rotation.m_col1.m_quad);
    BvToWorld.m_rotation.m_col2.m_quad = _mm_shuffle_ps(
                                           _mm_unpackhi_ps(
                                             m_localToWorldTransform->m_rotation.m_col0.m_quad,
                                             m_localToWorldTransform->m_rotation.m_col1.m_quad),
                                           m_quad,
                                           228);
    BvToWorld.m_rotation.m_col0.m_quad = _mm_movelh_ps(v15, m_quad);
    BvToWorld.m_rotation.m_col1.m_quad = _mm_shuffle_ps(
                                           _mm_movehl_ps(BvToWorld.m_rotation.m_col0.m_quad, v15),
                                           m_quad,
                                           212);
    v16 = _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
            m_localToWorldTransform->m_translation.m_quad);
    extraRadius.m_real = ::aabbOut.m_quad;
    BvToWorld.m_translation.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), BvToWorld.m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), BvToWorld.m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), BvToWorld.m_rotation.m_col2.m_quad));
    hkAabbUtil::calcAabb(&BvToWorld, &input->m_aabb, &extraRadius, &aabbOut);
    m_runtimeId = 0;
    if ( m_instance && m_instance->m_runtimeId > 0 )
      m_runtimeId = m_instance->m_runtimeId;
    m_size = hits->m_size;
    hkcdStaticAabbTree::queryAabb(this->m_tree.m_pntr, &aabbOut, hits);
    v19 = m_size;
    v20 = hits->m_size - 1;
    v21 = v20;
    if ( v20 >= m_size )
    {
      do
      {
        m_hitFilter = input->m_hitFilter;
        v23 = hits->m_data[v21] & 0x3FFFFF;
        if ( !m_hitFilter
          || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
               m_hitFilter,
               input->m_instance,
               v23,
               input->m_filterInfo,
               input->m_userData) )
        {
          hits->m_data[v21] = v23 | (m_runtimeId << 22);
        }
        else
        {
          v24 = --hits->m_size;
          if ( (_DWORD)v24 != v20 )
            hits->m_data[v21] = hits->m_data[v24];
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
    v29 = v26 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v27[1] = v29;
  }
}

// File Line: 360
// RVA: 0xBD65B0
int __fastcall hkaiStaticTreeNavMeshQueryMediator::getMemoryFootPrint(hkaiStaticTreeNavMeshQueryMediator *this)
{
  return hkcdStaticAabbTree::getMemoryFootPrint(this->m_tree.m_pntr);
}

