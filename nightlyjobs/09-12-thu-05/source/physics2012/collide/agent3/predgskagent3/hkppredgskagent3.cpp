// File Line: 32
// RVA: 0xD2A970
void __fastcall hkPredGskAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkPredGskAgent3::create;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkPredGskAgent3::process;
  f->m_sepNormalFunc = (void (__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *, hkVector4f *))hkPredGskAgent3::sepNormal;
  f->m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkPredGskAgent3::cleanup;
  f->m_removePointFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkPredGskAgent3::removePoint;
  f->m_commitPotentialFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkPredGskAgent3::commitPotential;
  f->m_createZombieFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkPredGskAgent3::createZombie;
  f->m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkPredGskAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 48
// RVA: 0xD2A900
void __fastcall hkPredGskAgent3::registerAgent3(
        hkpCollisionDispatcher *dispatcher,
        hkcdShapeType::ShapeTypeEnum typeA,
        hkcdShapeType::ShapeTypeEnum typeB)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkPredGskAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, typeA, typeB);
}

// File Line: 56
// RVA: 0xD2A160
char *__fastcall hkPredGskAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, hkpGskCache *agentData)
{
  hkpConvexShape *m_shape; // rdx
  hkpCdBody *m_storage; // rax
  hkTransformf *p_m_aTb; // r9
  hkpTriangleShape *v8; // r8

  m_shape = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
  m_storage = input->m_bodyB.m_storage;
  p_m_aTb = &input->m_aTb;
  v8 = (hkpTriangleShape *)m_storage->m_shape;
  if ( m_storage->m_shape->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(agentData, m_shape, v8, p_m_aTb);
  else
    hkpGskCache::init(agentData, m_shape, v8, p_m_aTb);
  entry->m_numContactPoints = 0;
  agentData->m_gskFlags &= ~0x10u;
  *(_DWORD *)agentData[1].m_vertices = 0;
  return (char *)agentData
       + ((2
         * (LOBYTE(agentData[1].m_vertices[0])
          + HIBYTE(agentData[1].m_vertices[0])
          + 4 * LOBYTE(agentData[1].m_vertices[1]))
         + 31) & 0xFFFFFFFFFFFFFFF0ui64);
}

// File Line: 92
// RVA: 0xD2A660
void __fastcall hkPredGskAgent3::sepNormal(
        hkpAgent3Input *input,
        hkpAgentEntry *entry,
        hkpGskCache *agentData,
        hkVector4f *separatingNormalOut)
{
  __int64 m_dimA; // r8
  hkpConvexShape *m_shape; // rsi
  unsigned int v7; // edx
  hkpConvexShape *v8; // r14
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // [rsp+30h] [rbp-1C8h] BYREF
  hkpGsk v14; // [rsp+40h] [rbp-1B8h] BYREF
  unsigned int v15; // [rsp+200h] [rbp+8h]

  m_dimA = (unsigned __int8)agentData->m_dimA;
  m_shape = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
  v7 = *((unsigned __int8 *)agentData + 10);
  v8 = (hkpConvexShape *)input->m_bodyB.m_storage->m_shape;
  v14.m_dimB.m_storage = (unsigned __int8)agentData->m_dimB;
  v14.m_featureChange.m_storage = 0;
  *(_QWORD *)&v14.m_maxDimB.m_storage = v7 >> 4;
  v14.m_dimA.m_storage = m_dimA;
  v14.m_maxDimA.m_storage = v7 & 0xF;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))m_shape->vfptr[4].__first_virtual_table_function__)(
    m_shape,
    agentData,
    m_dimA,
    v14.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v8->vfptr[4].__first_virtual_table_function__)(
    v8,
    &agentData->m_vertices[v14.m_dimA.m_storage],
    (unsigned int)v14.m_dimB.m_storage,
    v14.m_verticesBinB);
  hkpGsk::getClosestFeature(&v14, m_shape, v8, &input->m_aTb, &v13);
  if ( v14.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v14, agentData);
  v11 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 255);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), *((__m128 *)input->m_bodyA.m_storage->m_motion + 1)),
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), *(__m128 *)input->m_bodyA.m_storage->m_motion)),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 170), *((__m128 *)input->m_bodyA.m_storage->m_motion + 2)));
  *separatingNormalOut = (hkVector4f)v12;
  *(float *)&v15 = v8->m_radius + m_shape->m_radius;
  separatingNormalOut->m_quad = _mm_shuffle_ps(
                                  v12,
                                  _mm_unpackhi_ps(v12, _mm_sub_ps(v11, _mm_shuffle_ps((__m128)v15, (__m128)v15, 0))),
                                  196);
}

// File Line: 116
// RVA: 0xD2A820
void __fastcall hkPredGskAgent3::removePoint(
        hkpAgentEntry *entry,
        unsigned __int8 *agentData,
        unsigned __int16 idToRemove)
{
  __int64 v3; // r9
  hkpGskManifold *v4; // r10
  int v5; // edx
  __int64 v6; // rcx
  unsigned __int16 *i; // rax

  v3 = agentData[14];
  v4 = (hkpGskManifold *)(agentData + 12);
  v5 = 0;
  v6 = 0i64;
  if ( v3 )
  {
    for ( i = &v4->m_contactPoints[0].m_id; *i != idToRemove; i += 4 )
    {
      ++v6;
      ++v5;
      if ( v6 >= v3 )
        return;
    }
    hkGskManifold_removePoint(v4, v5);
  }
}

// File Line: 130
// RVA: 0xD2A860
void __fastcall hkPredGskAgent3::commitPotential(
        hkpAgentEntry *entry,
        unsigned __int8 *agentData,
        unsigned __int16 idToCommit)
{
  __int64 v3; // r9
  char *v4; // r10
  int v5; // edx
  __int64 v6; // rcx
  _WORD *i; // rax

  v3 = agentData[14];
  v4 = (char *)(agentData + 12);
  v5 = 0;
  v6 = 0i64;
  if ( v3 )
  {
    for ( i = v4 + 6; *i != 0xFFFF; i += 4 )
    {
      ++v6;
      ++v5;
      if ( v6 >= v3 )
        return;
    }
    *(_WORD *)&v4[8 * v5 + 6] = idToCommit;
  }
}

// File Line: 145
// RVA: 0xD2A8B0
void __fastcall hkPredGskAgent3::createZombie(hkpAgentEntry *entry, _BYTE *agentData, unsigned __int16 idToConvert)
{
  __int64 v3; // rcx
  _WORD *i; // rax

  v3 = 0i64;
  if ( agentData[14] )
  {
    for ( i = agentData + 16; i[1] != idToConvert; i += 4 )
    {
      if ( ++v3 >= (unsigned __int8)agentData[14] )
        return;
    }
    *i = 0;
  }
}

// File Line: 164
// RVA: 0xD2A7B0
char *__fastcall hkPredGskAgent3::cleanup(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  int v6; // r9d

  hkGskManifold_cleanup((hkpGskManifold *)(agentData + 12), mgr, constraintOwner);
  v6 = (unsigned __int8)agentData[12] + (unsigned __int8)agentData[13] + 4 * (unsigned __int8)agentData[14];
  entry->m_numContactPoints = 0;
  return &agentData[(2 * v6 + 4 + 27i64) & 0xFFFFFFFFFFFFFFF0ui64];
}

// File Line: 185
// RVA: 0xD2A8F0
// attributes: thunk
void __fastcall hkPredGskAgent3::destroy(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkPredGskAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 214
// RVA: 0xD2A1E0
char *__fastcall hkPredGskAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  unsigned int *m_storage; // rdx
  int Points; // ebx
  unsigned __int8 *v16; // rdi
  __m128 v17; // xmm3
  hkpCdBody *v18; // rcx
  hkpCdBody *i; // rax
  __m128 m_shapeKey; // xmm2
  hkpCdBody *v21; // rcx
  __m128 v22; // xmm2
  hkpCdBody *j; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  char *v28; // rbx
  _QWORD *v29; // rax
  _QWORD *v30; // rcx
  _QWORD *v31; // r8
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  hkVector4f v35; // xmm4
  unsigned __int8 v36; // dl
  hkpCdBody *v37; // r8
  hkpCdBody *v38; // rbx
  hkpShape *m_shape; // rcx
  float *v40; // r12
  __int64 v41; // r8
  float v42; // xmm0_4
  __m128 *m_motion; // rax
  __int64 v44; // rcx
  __m128 v45; // xmm3
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm6
  __int64 v49; // r8
  hkcdVertex *v50; // rdx
  __m128 m_quad; // xmm1
  hkcdVertex *v52; // rbx
  __m128 *v53; // rax
  __m128 v54; // xmm3
  __m128 v55; // xmm4
  __m128 v56; // xmm5
  __m128 v57; // xmm6
  __int64 v58; // rcx
  __m128 *p_m_quad; // rax
  __m128 v60; // xmm1
  unsigned __int8 v61; // al
  hkpProcessCollisionOutput::PotentialInfo *v62; // r8
  hkSimdFloat32 minSeparation; // [rsp+40h] [rbp-198h] BYREF
  hkSimdFloat32 allowedPenetrationDepth; // [rsp+50h] [rbp-188h] BYREF
  hkSimdFloat32 toiSeparation; // [rsp+60h] [rbp-178h] BYREF
  hkpGskManifoldWork work; // [rsp+70h] [rbp-168h] BYREF
  char *v67; // [rsp+1E0h] [rbp+8h]
  hkpCdBody *v68; // [rsp+1E8h] [rbp+10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtPredGskf3";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_storage = (unsigned int *)input->m_input.m_storage->m_collisionQualityInfo.m_storage;
  Points = 0;
  v16 = (unsigned __int8 *)(agentData + 12);
  v17 = _mm_shuffle_ps((__m128)LODWORD(input->m_distAtT1.m_storage), (__m128)LODWORD(input->m_distAtT1.m_storage), 0);
  if ( m_storage[4] )
  {
    v18 = input->m_bodyA.m_storage;
    for ( i = input->m_bodyA.m_storage->m_parent; i; i = i->m_parent )
      v18 = i;
    m_shapeKey = (__m128)v18[3].m_shapeKey;
    v21 = input->m_bodyB.m_storage;
    v22 = _mm_shuffle_ps(m_shapeKey, m_shapeKey, 0);
    for ( j = v21->m_parent; j; j = j->m_parent )
      v21 = j;
    v24 = _mm_min_ps(v22, _mm_shuffle_ps((__m128)v21[3].m_shapeKey, (__m128)v21[3].m_shapeKey, 0));
    v25 = _mm_shuffle_ps((__m128)m_storage[6], (__m128)m_storage[6], 0);
    v26 = _mm_mul_ps(_mm_shuffle_ps((__m128)m_storage[7], (__m128)m_storage[7], 0), v24);
    v27 = _mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 255);
    allowedPenetrationDepth.m_real = v24;
    minSeparation.m_real = _mm_min_ps(_mm_mul_ps(v25, v24), _mm_add_ps(v26, v27));
    if ( v17.m128_f32[0] < minSeparation.m_real.m128_f32[0] )
    {
      toiSeparation.m_real = _mm_min_ps(
                               _mm_mul_ps(_mm_shuffle_ps((__m128)m_storage[10], (__m128)m_storage[10], 0), v24),
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)m_storage[11], (__m128)m_storage[11], 0), v24),
                                 v27));
      hk4dGskCollideCalcToi(
        input,
        &allowedPenetrationDepth,
        &minSeparation,
        &toiSeparation,
        (hkpGskCache *)agentData,
        separatingNormal,
        output);
LABEL_10:
      hkGskAgentUtil_processCollisionNoTim(
        input,
        entry,
        agentData,
        (hkpGskCache *)agentData,
        (hkpGskManifold *)(agentData + 12),
        separatingNormal,
        Points,
        output);
      goto $END_OF_FUNCTION_0;
    }
  }
  if ( v17.m128_f32[0] <= _mm_shuffle_ps((__m128)m_storage[3], (__m128)m_storage[3], 0).m128_f32[0]
    || (agentData[11] & 0x10) != 0 )
  {
    goto LABEL_10;
  }
  v35.m_quad = _mm_shuffle_ps(separatingNormal->m_quad, _mm_unpackhi_ps(separatingNormal->m_quad, v17), 196);
  *separatingNormal = (hkVector4f)v35.m_quad;
  v36 = agentData[14];
  if ( v36 )
  {
    v37 = input->m_bodyB.m_storage;
    v38 = input->m_bodyA.m_storage;
    work.m_keepContact.m_storage = input->m_input.m_storage->m_tolerance.m_storage;
    m_shape = v38->m_shape;
    v40 = (float *)v37->m_shape;
    v68 = v37;
    v41 = *v16;
    work.m_radiusA.m_storage = *(float *)&v38->m_shape[1].vfptr;
    v42 = v40[8];
    work.m_masterNormal = (hkVector4f)v35.m_quad;
    work.m_radiusB.m_storage = v42;
    v67 = &agentData[8 * v36 + 16];
    work.m_radiusSumSqrd.m_storage = (float)((float)(work.m_radiusA.m_storage + work.m_keepContact.m_storage) + v42)
                                   * (float)((float)(work.m_radiusA.m_storage + work.m_keepContact.m_storage) + v42);
    ((void (__fastcall *)(hkpShape *, char *, __int64, hkpGskManifoldWork *))m_shape->vfptr[4].__first_virtual_table_function__)(
      m_shape,
      v67,
      v41,
      &work);
    m_motion = (__m128 *)v38->m_motion;
    v44 = *v16;
    v45 = *m_motion;
    v46 = m_motion[1];
    v47 = m_motion[2];
    v48 = m_motion[3];
    v49 = (int)v44 - 1;
    v50 = &work.m_vertices[v49];
    do
    {
      m_quad = v50->m_quad;
      --v50;
      --v49;
      v50[1].m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v46),
                            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v45)),
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v47)),
                        v48);
    }
    while ( v49 >= 0 );
    v52 = &work.m_vertices[v44];
    (*(void (__fastcall **)(float *, char *, _QWORD, hkcdVertex *))(*(_QWORD *)v40 + 72i64))(
      v40,
      &v67[2 * v44],
      (unsigned __int8)agentData[13],
      v52);
    v53 = (__m128 *)v68->m_motion;
    v54 = *v53;
    v55 = v53[1];
    v56 = v53[2];
    v57 = v53[3];
    v58 = (unsigned __int8)agentData[13] - 1;
    p_m_quad = &v52[v58].m_quad;
    do
    {
      v60 = *p_m_quad--;
      --v58;
      p_m_quad[1] = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), v55),
                          _mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v54)),
                        _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), v56)),
                      v57);
    }
    while ( v58 >= 0 );
    Points = hkGskManifold_verifyAndGetPoints(
               (hkpGskManifold *)(agentData + 12),
               &work,
               0,
               output,
               input->m_contactMgr.m_storage);
    if ( Points && agentData[11] < 0 )
    {
      output->m_firstFreeContactPoint.m_storage -= (unsigned __int8)agentData[14];
      goto LABEL_10;
    }
    v61 = agentData[14];
    if ( v61 )
    {
      v62 = output->m_potentialContacts.m_storage;
      if ( v62 )
        *v62->m_firstFreeRepresentativeContact++ = &output->m_firstFreeContactPoint.m_storage[-v61];
    }
  }
$END_OF_FUNCTION_0:
  entry->m_numContactPoints = agentData[14];
  v28 = &agentData[(2
                  * ((unsigned __int8)agentData[12] + (unsigned __int8)agentData[13]
                                                    + 4 * (unsigned __int8)agentData[14])
                  + 4
                  + 27i64) & 0xFFFFFFFFFFFFFFF0ui64];
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  v31 = v29;
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v32 = __rdtsc();
    v33 = v30 + 2;
    *((_DWORD *)v33 - 2) = v32;
    v31[1] = v33;
  }
  return v28;
}instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  v31 = v29;
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v32 = __rdtsc();
    v33 = v3

