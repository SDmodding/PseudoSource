// File Line: 26
// RVA: 0xC2E5B0
hkpMoppCode *__fastcall hkaiMoppNavMeshQueryMediator::buildCode(hkaiNavMesh *navMesh, hkpMoppCompilerInput *req)
{
  hkpMoppCode *v3; // rbx
  hkaiNavMeshShapeCollection v5; // [rsp+20h] [rbp-48h] BYREF

  hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(&v5, navMesh);
  v3 = hkpMoppUtility::buildCode(&v5.hkpShapeContainer, req, 0i64);
  hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection(&v5);
  return v3;
}

// File Line: 35
// RVA: 0xC2E590
void __fastcall hkaiMoppNavMeshQueryMediator::hkaiMoppNavMeshQueryMediator(
        hkaiMoppNavMeshQueryMediator *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMoppNavMeshQueryMediator::`vftable;
}

// File Line: 39
// RVA: 0xC2E530
void __fastcall hkaiMoppNavMeshQueryMediator::~hkaiMoppNavMeshQueryMediator(hkaiMoppNavMeshQueryMediator *this)
{
  hkaiNavMesh *m_pntr; // rcx
  hkpMoppCode *v3; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiMoppNavMeshQueryMediator::`vftable;
  m_pntr = this->m_navMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navMesh.m_pntr = 0i64;
  v3 = this->m_code.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_code.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 42
// RVA: 0xC2E490
void __fastcall hkaiMoppNavMeshQueryMediator::hkaiMoppNavMeshQueryMediator(
        hkaiMoppNavMeshQueryMediator *this,
        hkpMoppCode *code,
        hkaiNavMesh *navMesh)
{
  hkpMoppCode *m_pntr; // rcx
  hkaiNavMesh *v7; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMoppNavMeshQueryMediator::`vftable;
  this->m_code.m_pntr = 0i64;
  this->m_navMesh.m_pntr = 0i64;
  if ( code )
    hkReferencedObject::addReference(code);
  m_pntr = this->m_code.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_code.m_pntr = code;
  this->m_codeInfoCopy = (hkVector4f)code->m_info;
  if ( navMesh )
    hkReferencedObject::addReference(navMesh);
  v7 = this->m_navMesh.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  this->m_navMesh.m_pntr = navMesh;
}

// File Line: 58
// RVA: 0xC2F3B0
hkBool *__fastcall hkaiMoppNavMeshFilter::isCollisionEnabled(
        hkaiMoppNavMeshFilter *this,
        hkBool *result,
        hkpShapeRayCastInput *aInput,
        hkpShapeContainer *hContainer,
        unsigned int bKey)
{
  hkaiNavMeshQueryMediator::RaycastInput *m_input; // r8
  hkaiNavMeshInstance *m_instance; // rdx
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx

  m_input = this->m_input;
  m_instance = this->m_instance;
  m_hitFilter = m_input->m_hitFilter;
  if ( !m_hitFilter
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
         m_hitFilter,
         m_instance,
         bKey,
         m_input->m_filterInfo,
         m_input->m_userData) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 68
// RVA: 0xC2E9E0
__int64 __fastcall hkaiMoppNavMeshQueryMediator::castRay(
        hkaiMoppNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::RaycastInput *rcInput,
        hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkaiNavMeshInstance *m_instance; // rsi
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  int m_runtimeId; // ebx
  hkaiNavMesh *m_pntr; // rdx
  hkTransformf *m_localToWorldTransform; // rax
  hkVector4f v16; // xmm5
  hkVector4f *p_m_col0; // rcx
  __m128 v18; // xmm5
  __m128 m_quad; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm4
  hkVector4f v25; // xmm5
  __m128 v26; // xmm5
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  unsigned int m_filterInfo; // eax
  hkpCollidable *m_userData; // rax
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm0
  _QWORD *v35; // rax
  _QWORD *v36; // rcx
  _QWORD *v37; // r8
  unsigned __int64 v38; // rax
  _QWORD *v39; // rcx
  __int64 v41[4]; // [rsp+30h] [rbp-C8h] BYREF
  hkpShapeRayCastInput input; // [rsp+50h] [rbp-A8h] BYREF
  unsigned int v43; // [rsp+98h] [rbp-60h]
  int v44; // [rsp+9Ch] [rbp-5Ch]
  int v45; // [rsp+A8h] [rbp-50h]
  int v46; // [rsp+C8h] [rbp-30h]
  hkaiNavMeshShapeCollection v47; // [rsp+D8h] [rbp-20h] BYREF
  hkpMoppLongRayVirtualMachine v48; // [rsp+118h] [rbp+20h] BYREF
  hkBool result; // [rsp+1E0h] [rbp+E8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtMOPP::castRay";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_instance = rcInput->m_instance;
  if ( m_instance
    && (m_hitFilter = rcInput->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))m_hitFilter->vfptr[1].__first_virtual_table_function__)(
          m_hitFilter,
          m_instance,
          rcInput->m_filterInfo,
          rcInput->m_userData) )
  {
    LOBYTE(m_runtimeId) = 0;
  }
  else
  {
    m_pntr = this->m_navMesh.m_pntr;
    m_runtimeId = 0;
    v48.m_ray.m_filterInfo = 0;
    memset(&v48.m_ray.m_rayShapeCollectionFilter, 0, 24);
    hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(&v47, m_pntr);
    m_localToWorldTransform = rcInput->m_localToWorldTransform;
    v16.m_quad = (__m128)rcInput->m_from;
    input.m_filterInfo = 0;
    input.m_collidable = 0i64;
    v41[1] = (__int64)m_instance;
    v41[2] = (__int64)rcInput;
    input.m_rayShapeCollectionFilter = 0i64;
    p_m_col0 = &transform;
    if ( m_localToWorldTransform )
      p_m_col0 = &m_localToWorldTransform->m_rotation.m_col0;
    v41[0] = (__int64)&hkaiMoppNavMeshFilter::`vftable;
    v18 = _mm_sub_ps(v16.m_quad, p_m_col0[3].m_quad);
    m_quad = p_m_col0[2].m_quad;
    v20 = _mm_unpacklo_ps(p_m_col0->m_quad, p_m_col0[1].m_quad);
    v21 = _mm_movelh_ps(v20, m_quad);
    v22 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v21, v20), m_quad, 212));
    v23 = _mm_shuffle_ps(v18, v18, 0);
    v24 = _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(p_m_col0->m_quad, p_m_col0[1].m_quad), m_quad, 228),
            _mm_shuffle_ps(v18, v18, 170));
    v25.m_quad = (__m128)rcInput->m_to;
    input.m_from.m_quad = _mm_add_ps(_mm_add_ps(v22, _mm_mul_ps(v23, v21)), v24);
    v26 = _mm_sub_ps(v25.m_quad, p_m_col0[3].m_quad);
    v27 = p_m_col0[2].m_quad;
    v28 = _mm_unpacklo_ps(p_m_col0->m_quad, p_m_col0[1].m_quad);
    v29 = _mm_shuffle_ps(_mm_unpackhi_ps(p_m_col0->m_quad, p_m_col0[1].m_quad), v27, 228);
    input.m_rayShapeCollectionFilter = (hkpRayShapeCollectionFilter *)v41;
    m_filterInfo = rcInput->m_filterInfo;
    v44 = -1;
    input.m_filterInfo = m_filterInfo;
    m_userData = (hkpCollidable *)rcInput->m_userData;
    v46 = 0;
    v32 = _mm_movelh_ps(v28, v27);
    input.m_collidable = m_userData;
    v45 = -1;
    v43 = (unsigned int)FLOAT_1_0;
    input.m_to.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(_mm_movehl_ps(v32, v28), v27, 212)),
                            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v32)),
                          _mm_mul_ps(v29, _mm_shuffle_ps(v26, v26, 170)));
    hkpMoppLongRayVirtualMachine::queryLongRay(
      &v48,
      &result,
      &v47.hkpShapeContainer,
      this->m_code.m_pntr,
      &input,
      (hkpShapeRayCastOutput *)&input.m_userData);
    if ( v45 == -1 )
    {
      hitOut->m_hitFaceKey = -1;
      v34 = query.m_quad;
    }
    else
    {
      if ( m_instance && m_instance->m_runtimeId > 0 )
        m_runtimeId = m_instance->m_runtimeId;
      v33 = (__m128)v43;
      hitOut->m_hitFaceKey = v45 | (m_runtimeId << 22);
      LOBYTE(m_runtimeId) = 1;
      v34 = _mm_shuffle_ps(v33, v33, 0);
    }
    hitOut->m_hitFraction.m_real = v34;
    v41[0] = (__int64)&hkpRayShapeCollectionFilter::`vftable;
    hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection(&v47);
  }
  v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v36 = (_QWORD *)v35[1];
  v37 = v35;
  if ( (unsigned __int64)v36 < v35[3] )
  {
    *v36 = "Et";
    v38 = __rdtsc();
    v39 = v36 + 2;
    *((_DWORD *)v39 - 2) = v38;
    v37[1] = v39;
  }
  return (unsigned __int8)m_runtimeId;
}

// File Line: 114
// RVA: 0xC2E600
__int64 __fastcall hkaiMoppNavMeshQueryMediator::getClosestPoint(
        hkaiMoppNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::GetClosestPointInput *gcpInput,
        hkVector4f *closestPointOut)
{
  _QWORD *Value; // r9
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkaiNavMeshInstance *m_instance; // r13
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned int v11; // esi
  hkaiNavMesh *m_pntr; // rdx
  hkTransformf *m_localToWorldTransform; // rcx
  __m128 v14; // xmm5
  __m128 m_quad; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  hkpMoppCode *v18; // rdx
  __int64 v19; // r14
  hkVector4f v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  int m_runtimeId; // r12d
  __m128 v24; // xmm6
  int v25; // r15d
  float v26; // xmm7_4
  hkaiSpatialQueryHitFilter *v27; // rcx
  unsigned int ID; // ebx
  hkaiNavMeshCutter *m_navMeshCutter; // rcx
  int ClosestPointOnFaceLocal; // ebx
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  float v33; // xmm2_4
  unsigned int v34; // edx
  _QWORD *v35; // rax
  _QWORD *v36; // rcx
  _QWORD *v37; // r8
  unsigned __int64 v38; // rax
  _QWORD *v39; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f position; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f closestPointOuta; // [rsp+50h] [rbp-A8h] BYREF
  hkAabb aabb; // [rsp+60h] [rbp-98h] BYREF
  hkpMoppObbVirtualMachine v45; // [rsp+B8h] [rbp-40h] BYREF
  hkaiNavMesh **retaddr; // [rsp+178h] [rbp+80h]
  int v47; // [rsp+180h] [rbp+88h]
  __m128 *v48; // [rsp+188h] [rbp+90h]
  __m128 *p_m_quad; // [rsp+190h] [rbp+98h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TtMOPP::GCP";
    v7 = __rdtsc();
    v8 = v6 + 2;
    *((_DWORD *)v8 - 2) = v7;
    Value[1] = v8;
  }
  m_instance = gcpInput->m_instance;
  if ( m_instance )
  {
    m_hitFilter = gcpInput->m_hitFilter;
    if ( m_hitFilter )
    {
      if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))m_hitFilter->vfptr[1].__first_virtual_table_function__)(
              m_hitFilter,
              m_instance,
              gcpInput->m_filterInfo,
              gcpInput->m_userData) )
      {
        v11 = -1;
        goto LABEL_30;
      }
    }
  }
  m_pntr = this->m_navMesh.m_pntr;
  m_localToWorldTransform = (hkTransformf *)&transform;
  if ( gcpInput->m_localToWorldTransform )
    m_localToWorldTransform = gcpInput->m_localToWorldTransform;
  p_m_quad = &m_localToWorldTransform->m_rotation.m_col0.m_quad;
  v14 = _mm_sub_ps(gcpInput->m_position.m_quad, m_localToWorldTransform->m_translation.m_quad);
  m_quad = m_localToWorldTransform->m_rotation.m_col2.m_quad;
  v16 = _mm_unpacklo_ps(
          m_localToWorldTransform->m_rotation.m_col0.m_quad,
          m_localToWorldTransform->m_rotation.m_col1.m_quad);
  v17 = _mm_movelh_ps(v16, m_quad);
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(_mm_movehl_ps(v17, v16), m_quad, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v17)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          _mm_unpackhi_ps(
                            m_localToWorldTransform->m_rotation.m_col0.m_quad,
                            m_localToWorldTransform->m_rotation.m_col1.m_quad),
                          m_quad,
                          228),
                        _mm_shuffle_ps(v14, v14, 170)));
  hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(
    (hkaiNavMeshShapeCollection *)&aabb.m_max.m_quad.m128_u16[4],
    m_pntr);
  v18 = this->m_code.m_pntr;
  v19 = 0i64;
  v20.m_quad = (__m128)this->m_codeInfoCopy;
  v21 = _mm_add_ps(_mm_sub_ps((__m128)0i64, gcpInput->m_queryRadius.m_real), position.m_quad);
  v22 = _mm_add_ps(position.m_quad, gcpInput->m_queryRadius.m_real);
  primitives_out.m_data = 0i64;
  primitives_out.m_size = 0;
  primitives_out.m_capacityAndFlags = 0x80000000;
  aabb.m_min.m_quad = _mm_max_ps(v20.m_quad, v21);
  v21.m128_f32[0] = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
  aabb.m_max.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 0), this->m_codeInfoCopy.m_quad), v22);
  hkpMoppObbVirtualMachine::queryAabb(&v45, v18, &aabb, &primitives_out);
  if ( !primitives_out.m_size )
  {
    v11 = -1;
    goto LABEL_27;
  }
  m_runtimeId = 0;
  if ( m_instance && m_instance->m_runtimeId > 0 )
    m_runtimeId = m_instance->m_runtimeId;
  v24 = position.m_quad;
  v11 = -1;
  v47 = -1;
  v25 = 0;
  v26 = gcpInput->m_queryRadius.m_real.m128_f32[0] * gcpInput->m_queryRadius.m_real.m128_f32[0];
  if ( primitives_out.m_size > 0 )
  {
    while ( 1 )
    {
      v27 = gcpInput->m_hitFilter;
      ID = primitives_out.m_data[v19].ID;
      if ( v27 )
      {
        if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v27->vfptr[2].__vecDelDtor)(
                v27,
                m_instance,
                ID,
                gcpInput->m_filterInfo,
                gcpInput->m_userData) )
          break;
      }
      m_navMeshCutter = gcpInput->m_navMeshCutter;
      if ( m_navMeshCutter )
      {
        ClosestPointOnFaceLocal = hkaiNavMeshCutter::getClosestPointOnFaceLocal(
                                    m_navMeshCutter,
                                    &position,
                                    ID | (m_runtimeId << 22),
                                    &closestPointOuta);
        if ( ClosestPointOnFaceLocal == -1 )
          break;
        ID = ClosestPointOnFaceLocal & 0x3FFFFF;
      }
      else
      {
        hkaiNavMeshUtils::getClosestPointOnFace(retaddr[6], &position, ID, &closestPointOuta);
      }
      v31 = _mm_sub_ps(position.m_quad, closestPointOuta.m_quad);
      v32 = _mm_mul_ps(v31, v31);
      v33 = (float)(_mm_shuffle_ps(v32, v32, 85).m128_f32[0] + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
          + _mm_shuffle_ps(v32, v32, 170).m128_f32[0];
      if ( v33 >= v26 )
        break;
      v26 = v33;
      v34 = ID;
      v47 = ID;
      v24 = closestPointOuta.m_quad;
LABEL_24:
      ++v25;
      ++v19;
      if ( v25 >= primitives_out.m_size )
      {
        if ( v34 != -1 )
        {
          v11 = v34 | (m_runtimeId << 22);
          *v48 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *p_m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), p_m_quad[1])),
                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), p_m_quad[2])),
                   p_m_quad[3]);
        }
        goto LABEL_27;
      }
    }
    v34 = v47;
    goto LABEL_24;
  }
LABEL_27:
  primitives_out.m_size = 0;
  if ( primitives_out.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      primitives_out.m_data,
      4 * primitives_out.m_capacityAndFlags);
  primitives_out.m_data = 0i64;
  primitives_out.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection((hkaiNavMeshShapeCollection *)&aabb.m_max.m_quad.m128_u16[4]);
LABEL_30:
  v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v36 = (_QWORD *)v35[1];
  v37 = v35;
  if ( (unsigned __int64)v36 < v35[3] )
  {
    *v36 = "Et";
    v38 = __rdtsc();
    v39 = v36 + 2;
    *((_DWORD *)v39 - 2) = v38;
    v37[1] = v39;
  }
  return v11;
}

// File Line: 216
// RVA: 0xC2ECB0
void __fastcall hkaiMoppNavMeshQueryMediator::queryAabb(
        hkaiMoppNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::AabbQueryInput *input,
        hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  __m128 v3; // xmm1
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkaiNavMeshInstance *m_instance; // r14
  hkaiSpatialQueryHitFilter *v13; // rcx
  hkTransformf *m_localToWorldTransform; // rdx
  hkpMoppCode *m_pntr; // rdx
  float v16; // xmm0_4
  __int64 m_size; // rbp
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int m_runtimeId; // r15d
  __int64 v22; // rbx
  __int64 v23; // r12
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned int ID; // ebp
  _QWORD *v26; // rax
  _QWORD *v27; // rcx
  _QWORD *v28; // r8
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+30h] [rbp-118h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+40h] [rbp-108h] BYREF
  hkAabb aabbOut; // [rsp+50h] [rbp-F8h] BYREF
  hkAabb aabb; // [rsp+70h] [rbp-D8h] BYREF
  hkTransformf BvToWorld; // [rsp+90h] [rbp-B8h] BYREF
  hkpMoppObbVirtualMachine v36; // [rsp+D0h] [rbp-78h] BYREF
  hkResult result; // [rsp+158h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtMOPP::queryAabb";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  m_instance = input->m_instance;
  if ( !m_instance
    || (v13 = input->m_hitFilter) == 0i64
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v13->vfptr[1].__first_virtual_table_function__)(
         v13,
         input->m_instance,
         input->m_filterInfo,
         input->m_userData) )
  {
    m_localToWorldTransform = (hkTransformf *)&transform;
    if ( input->m_localToWorldTransform )
      m_localToWorldTransform = input->m_localToWorldTransform;
    hkTransformf::setInverse(&BvToWorld, m_localToWorldTransform);
    extraRadius.m_real = ::aabbOut.m_quad;
    hkAabbUtil::calcAabb(&BvToWorld, &input->m_aabb, &extraRadius, &aabbOut);
    m_pntr = this->m_code.m_pntr;
    aabb.m_min.m_quad = _mm_max_ps(this->m_codeInfoCopy.m_quad, aabbOut.m_min.m_quad);
    v16 = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
    primitives_out.m_data = 0i64;
    primitives_out.m_size = 0;
    primitives_out.m_capacityAndFlags = 0x80000000;
    v3.m128_f32[0] = v16;
    aabb.m_max.m_quad = _mm_min_ps(
                          _mm_add_ps(_mm_shuffle_ps(v3, v3, 0), this->m_codeInfoCopy.m_quad),
                          aabbOut.m_max.m_quad);
    hkpMoppObbVirtualMachine::queryAabb(&v36, m_pntr, &aabb, &primitives_out);
    m_size = primitives_out.m_size;
    v18 = hits->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < primitives_out.m_size )
    {
      v19 = 2 * v18;
      v20 = primitives_out.m_size;
      if ( primitives_out.m_size < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, hits, v20, 4);
    }
    m_runtimeId = 0;
    if ( m_instance && m_instance->m_runtimeId > 0 )
      m_runtimeId = m_instance->m_runtimeId;
    v22 = 0i64;
    v23 = m_size;
    if ( (int)m_size > 0 )
    {
      do
      {
        m_hitFilter = input->m_hitFilter;
        ID = primitives_out.m_data[v22].ID;
        if ( !m_hitFilter
          || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__vecDelDtor)(
               m_hitFilter,
               m_instance,
               ID,
               input->m_filterInfo,
               input->m_userData) )
        {
          hits->m_data[hits->m_size++] = ID | (m_runtimeId << 22);
        }
        ++v22;
      }
      while ( v22 < v23 );
    }
    primitives_out.m_size = 0;
    if ( primitives_out.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        primitives_out.m_data,
        4 * primitives_out.m_capacityAndFlags);
    primitives_out.m_data = 0i64;
    primitives_out.m_capacityAndFlags = 0x80000000;
  }
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  v28 = v26;
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v29 = __rdtsc();
    v30 = v27 + 2;
    *((_DWORD *)v30 - 2) = v29;
    v28[1] = v30;
  }
}

// File Line: 266
// RVA: 0xC2EF70
__int64 __fastcall hkaiMoppNavMeshQueryMediator::getClosestBoundaryEdge(
        hkaiMoppNavMeshQueryMediator *this,
        hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *gcbInput,
        hkVector4f *closestPointOut)
{
  _QWORD *Value; // rax
  _QWORD *v6; // rcx
  _QWORD *v7; // r9
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  hkaiNavMeshInstance *m_instance; // r13
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  unsigned int v12; // edi
  hkaiNavMesh *m_pntr; // rdx
  hkTransformf *m_localToWorldTransform; // rcx
  __m128 v15; // xmm5
  __m128 m_quad; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  hkpMoppCode *v19; // rdx
  hkVector4f v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  int m_runtimeId; // r12d
  __m128 v24; // xmm6
  int v25; // r15d
  float v26; // xmm7_4
  __int64 v27; // r14
  hkaiSpatialQueryHitFilter *v28; // rcx
  unsigned int ID; // esi
  hkaiNavMeshCutter *m_navMeshCutter; // rcx
  hkVector4f *p_m_projectionDirection; // r9
  int ClosestBoundaryOnFaceLocal; // eax
  int ClosestBoundaryOnFace; // eax
  float v34; // xmm0_4
  int v35; // edx
  _QWORD *v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+30h] [rbp-C0h] BYREF
  hkVector4f position; // [rsp+40h] [rbp-B0h] BYREF
  hkVector4f v44; // [rsp+50h] [rbp-A0h] BYREF
  hkAabb aabb; // [rsp+60h] [rbp-90h] BYREF
  hkpMoppObbVirtualMachine v46; // [rsp+B0h] [rbp-40h] BYREF
  __int64 vars0; // [rsp+170h] [rbp+80h]
  void *retaddr; // [rsp+178h] [rbp+88h]
  __m128 *p_m_quad; // [rsp+188h] [rbp+98h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  v7 = Value;
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TtMOPP::GCBoundary";
    v8 = __rdtsc();
    v9 = v6 + 2;
    *((_DWORD *)v9 - 2) = v8;
    v7[1] = v9;
  }
  m_instance = gcbInput->m_instance;
  if ( m_instance )
  {
    m_hitFilter = gcbInput->m_hitFilter;
    if ( m_hitFilter )
    {
      if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))m_hitFilter->vfptr[1].__first_virtual_table_function__)(
              m_hitFilter,
              gcbInput->m_instance,
              gcbInput->m_filterInfo,
              gcbInput->m_userData) )
      {
        v12 = -1;
        goto LABEL_31;
      }
    }
  }
  m_pntr = this->m_navMesh.m_pntr;
  m_localToWorldTransform = (hkTransformf *)&transform;
  if ( gcbInput->m_localToWorldTransform )
    m_localToWorldTransform = gcbInput->m_localToWorldTransform;
  p_m_quad = &m_localToWorldTransform->m_rotation.m_col0.m_quad;
  v15 = _mm_sub_ps(gcbInput->m_position.m_quad, m_localToWorldTransform->m_translation.m_quad);
  m_quad = m_localToWorldTransform->m_rotation.m_col2.m_quad;
  v17 = _mm_unpacklo_ps(
          m_localToWorldTransform->m_rotation.m_col0.m_quad,
          m_localToWorldTransform->m_rotation.m_col1.m_quad);
  v18 = _mm_movelh_ps(v17, m_quad);
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), m_quad, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          _mm_unpackhi_ps(
                            m_localToWorldTransform->m_rotation.m_col0.m_quad,
                            m_localToWorldTransform->m_rotation.m_col1.m_quad),
                          m_quad,
                          228),
                        _mm_shuffle_ps(v15, v15, 170)));
  hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection((hkaiNavMeshShapeCollection *)&aabb.m_max, m_pntr);
  v19 = this->m_code.m_pntr;
  v20.m_quad = (__m128)this->m_codeInfoCopy;
  v21 = _mm_add_ps(_mm_sub_ps((__m128)0i64, gcbInput->m_queryRadius.m_real), position.m_quad);
  v22 = _mm_add_ps(position.m_quad, gcbInput->m_queryRadius.m_real);
  primitives_out.m_data = 0i64;
  primitives_out.m_size = 0;
  primitives_out.m_capacityAndFlags = 0x80000000;
  aabb.m_min.m_quad = _mm_max_ps(v20.m_quad, v21);
  v21.m128_f32[0] = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
  aabb.m_max.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 0), this->m_codeInfoCopy.m_quad), v22);
  hkpMoppObbVirtualMachine::queryAabb(&v46, v19, &aabb, &primitives_out);
  if ( !primitives_out.m_size )
  {
    v12 = -1;
    goto LABEL_28;
  }
  m_runtimeId = 0;
  if ( m_instance && m_instance->m_runtimeId > 0 )
    m_runtimeId = m_instance->m_runtimeId;
  v24 = position.m_quad;
  v12 = -1;
  LODWORD(retaddr) = -1;
  v25 = 0;
  v26 = gcbInput->m_queryRadius.m_real.m128_f32[0] * gcbInput->m_queryRadius.m_real.m128_f32[0];
  if ( primitives_out.m_size > 0 )
  {
    v27 = 0i64;
    while ( 1 )
    {
      v28 = gcbInput->m_hitFilter;
      ID = primitives_out.m_data[v27].ID;
      if ( v28 )
      {
        if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v28->vfptr[2].__vecDelDtor)(
                v28,
                m_instance,
                ID,
                gcbInput->m_filterInfo,
                gcbInput->m_userData) )
          break;
      }
      m_navMeshCutter = gcbInput->m_navMeshCutter;
      p_m_projectionDirection = &gcbInput->m_projectionDirection;
      if ( m_navMeshCutter )
      {
        ClosestBoundaryOnFaceLocal = hkaiNavMeshCutter::getClosestBoundaryOnFaceLocal(
                                       m_navMeshCutter,
                                       &position,
                                       ID | (m_runtimeId << 22),
                                       p_m_projectionDirection,
                                       &v44);
        if ( ClosestBoundaryOnFaceLocal == -1 )
          break;
        ClosestBoundaryOnFace = ClosestBoundaryOnFaceLocal & 0x3FFFFF;
      }
      else
      {
        ClosestBoundaryOnFace = hkaiNavMeshUtils::getClosestBoundaryOnFace(
                                  *(hkaiNavMesh **)(vars0 + 48),
                                  &position,
                                  ID,
                                  p_m_projectionDirection,
                                  &v44);
      }
      v34 = _mm_shuffle_ps(v44.m_quad, v44.m_quad, 255).m128_f32[0];
      if ( v34 >= v26 )
        break;
      v26 = v34;
      v35 = ClosestBoundaryOnFace;
      LODWORD(retaddr) = ClosestBoundaryOnFace;
      v24 = v44.m_quad;
LABEL_25:
      ++v25;
      ++v27;
      if ( v25 >= primitives_out.m_size )
      {
        if ( v35 != -1 )
        {
          v12 = v35 | (m_runtimeId << 22);
          this->hkaiNavMeshQueryMediator = (hkaiNavMeshQueryMediator)_mm_add_ps(
                                                                       _mm_add_ps(
                                                                         _mm_add_ps(
                                                                           _mm_mul_ps(
                                                                             _mm_shuffle_ps(v24, v24, 85),
                                                                             p_m_quad[1]),
                                                                           _mm_mul_ps(
                                                                             _mm_shuffle_ps(v24, v24, 0),
                                                                             *p_m_quad)),
                                                                         _mm_mul_ps(
                                                                           _mm_shuffle_ps(v24, v24, 170),
                                                                           p_m_quad[2])),
                                                                       p_m_quad[3]);
        }
        goto LABEL_28;
      }
    }
    v35 = (int)retaddr;
    goto LABEL_25;
  }
LABEL_28:
  primitives_out.m_size = 0;
  if ( primitives_out.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      primitives_out.m_data,
      4 * primitives_out.m_capacityAndFlags);
  primitives_out.m_data = 0i64;
  primitives_out.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection((hkaiNavMeshShapeCollection *)&aabb.m_max);
LABEL_31:
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  v38 = v36;
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "Et";
    v39 = __rdtsc();
    v40 = v37 + 2;
    *((_DWORD *)v40 - 2) = v39;
    v38[1] = v40;
  }
  return v12;
}

