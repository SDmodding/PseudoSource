// File Line: 32
// RVA: 0xD2A970
void __fastcall hkPredGskAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkPredGskAgent3::create;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkPredGskAgent3::process;
  f->m_sepNormalFunc = hkPredGskAgent3::sepNormal;
  f->m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkPredGskAgent3::cleanup;
  f->m_removePointFunc = hkPredGskAgent3::removePoint;
  f->m_commitPotentialFunc = hkPredGskAgent3::commitPotential;
  f->m_createZombieFunc = hkPredGskAgent3::createZombie;
  f->m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkPredGskAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 48
// RVA: 0xD2A900
void __fastcall hkPredGskAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher, hkcdShapeType::ShapeTypeEnum typeA, hkcdShapeType::ShapeTypeEnum typeB)
{
  hkpCollisionDispatcher *v3; // rsi
  hkcdShapeType::ShapeTypeEnum v4; // ebx
  hkcdShapeType::ShapeTypeEnum v5; // edi
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h]

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  v3 = dispatcher;
  v4 = typeB;
  v5 = typeA;
  f.m_updateFilterFunc = 0i64;
  f.m_invalidateTimFunc = 0i64;
  f.m_warpTimeFunc = 0i64;
  f.m_sepNormalFunc = 0i64;
  hkPredGskAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(v3, &f, v5, v4);
}

// File Line: 56
// RVA: 0xD2A160
unsigned __int64 __fastcall hkPredGskAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData)
{
  hkpGskCache *v3; // rbx
  hkpAgentEntry *v4; // rdi
  hkpConvexShape *v5; // rdx
  hkpCdBody *v6; // rax
  hkTransformf *v7; // r9
  hkpTriangleShape *v8; // r8

  v3 = (hkpGskCache *)agentData;
  v4 = entry;
  v5 = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
  v6 = input->m_bodyB.m_storage;
  v7 = &input->m_aTb;
  v8 = (hkpTriangleShape *)v6->m_shape;
  if ( v6->m_shape->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(v3, v5, v8, v7);
  else
    hkpGskCache::init(v3, v5, (hkpConvexShape *)&v8->vfptr, v7);
  v4->m_numContactPoints = 0;
  v3->m_gskFlags &= 0xEFu;
  *(_DWORD *)v3[1].m_vertices = 0;
  return (unsigned __int64)v3
       + ((2 * (LOBYTE(v3[1].m_vertices[0]) + HIBYTE(v3[1].m_vertices[0]) + 4 * LOBYTE(v3[1].m_vertices[1])) + 31) & 0xFFFFFFFFFFFFFFF0ui64);
}

// File Line: 92
// RVA: 0xD2A660
void __fastcall hkPredGskAgent3::sepNormal(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormalOut)
{
  hkpGskCache *v4; // rbx
  __int64 v5; // r8
  hkpConvexShape *v6; // rsi
  unsigned int v7; // edx
  hkpConvexShape *v8; // r14
  hkpAgent3Input *v9; // rdi
  hkVector4f *v10; // rbp
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // [rsp+30h] [rbp-1C8h]
  hkpGsk v14; // [rsp+40h] [rbp-1B8h]
  unsigned int v15; // [rsp+200h] [rbp+8h]

  v4 = (hkpGskCache *)agentData;
  v5 = *((unsigned __int8 *)agentData + 8);
  v6 = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
  v7 = *((unsigned __int8 *)v4 + 10);
  v8 = (hkpConvexShape *)input->m_bodyB.m_storage->m_shape;
  v9 = input;
  v14.m_dimB.m_storage = (unsigned __int8)v4->m_dimB;
  *(_QWORD *)&v14.m_doNotHandlePenetration.m_storage = 0i64;
  *(_QWORD *)&v14.m_maxDimB.m_storage = v7 >> 4;
  v14.m_dimA.m_storage = v5;
  v14.m_maxDimA.m_storage = v7 & 0xF;
  v10 = separatingNormalOut;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))v6->vfptr[4].__first_virtual_table_function__)(
    v6,
    v4,
    v5,
    v14.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v8->vfptr[4].__first_virtual_table_function__)(
    v8,
    &v4->m_vertices[v14.m_dimA.m_storage],
    (unsigned int)v14.m_dimB.m_storage,
    v14.m_verticesBinB);
  hkpGsk::getClosestFeature(&v14, v6, v8, &v9->m_aTb, &v13);
  if ( v14.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v14, v4);
  v11 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 255);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), *((__m128 *)v9->m_bodyA.m_storage->m_motion + 1)),
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), *(__m128 *)v9->m_bodyA.m_storage->m_motion)),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 170), *((__m128 *)v9->m_bodyA.m_storage->m_motion + 2)));
  *v10 = (hkVector4f)v12;
  *(float *)&v15 = v8->m_radius + v6->m_radius;
  v10->m_quad = _mm_shuffle_ps(
                  v12,
                  _mm_unpackhi_ps(v12, _mm_sub_ps(v11, _mm_shuffle_ps((__m128)v15, (__m128)v15, 0))),
                  196);
}

// File Line: 116
// RVA: 0xD2A820
void __fastcall hkPredGskAgent3::removePoint(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToRemove)
{
  __int64 v3; // r9
  hkpGskManifold *v4; // r10
  int v5; // edx
  __int64 v6; // rcx
  unsigned __int16 *v7; // rax

  v3 = *((unsigned __int8 *)agentData + 14);
  v4 = (hkpGskManifold *)((char *)agentData + 12);
  v5 = 0;
  v6 = 0i64;
  if ( v3 > 0 )
  {
    v7 = &v4->m_contactPoints[0].m_id;
    while ( *v7 != idToRemove )
    {
      ++v6;
      ++v5;
      v7 += 4;
      if ( v6 >= v3 )
        return;
    }
    hkGskManifold_removePoint(v4, v5);
  }
}

// File Line: 130
// RVA: 0xD2A860
void __fastcall hkPredGskAgent3::commitPotential(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToCommit)
{
  __int64 v3; // r9
  char *v4; // r10
  int v5; // edx
  __int64 v6; // rcx
  _WORD *v7; // rax

  v3 = *((unsigned __int8 *)agentData + 14);
  v4 = (char *)agentData + 12;
  v5 = 0;
  v6 = 0i64;
  if ( v3 > 0 )
  {
    v7 = v4 + 6;
    while ( *v7 != -1 )
    {
      ++v6;
      ++v5;
      v7 += 4;
      if ( v6 >= v3 )
        return;
    }
    *(_WORD *)&v4[8 * v5 + 6] = idToCommit;
  }
}

// File Line: 145
// RVA: 0xD2A8B0
void __fastcall hkPredGskAgent3::createZombie(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToConvert)
{
  __int64 v3; // r9
  __int64 v4; // rcx
  _WORD *v5; // rax

  v3 = *((unsigned __int8 *)agentData + 14);
  v4 = 0i64;
  if ( v3 > 0 )
  {
    v5 = (char *)agentData + 16;
    while ( v5[1] != idToConvert )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        return;
    }
    *v5 = 0;
  }
}

// File Line: 164
// RVA: 0xD2A7B0
unsigned __int64 __fastcall hkPredGskAgent3::cleanup(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  unsigned __int8 *v4; // rsi
  hkpAgentEntry *v5; // rdi
  int v6; // er9

  v4 = (unsigned __int8 *)agentData;
  v5 = entry;
  hkGskManifold_cleanup((hkpGskManifold *)((char *)agentData + 12), mgr, constraintOwner);
  v6 = v4[12] + v4[13] + 4 * v4[14];
  v5->m_numContactPoints = 0;
  return (unsigned __int64)&v4[(2 * v6 + 4 + 27i64) & 0xFFFFFFFFFFFFFFF0ui64];
}

// File Line: 185
// RVA: 0xD2A8F0
void __fastcall hkPredGskAgent3::destroy(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkPredGskAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 214
// RVA: 0xD2A1E0
unsigned __int64 __fastcall hkPredGskAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v5; // rsi
  char *gskCache; // rbp
  hkVector4f *v7; // r15
  hkpAgentEntry *v8; // r13
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  unsigned int *v14; // rdx
  int v15; // ebx
  unsigned __int8 *v16; // rdi
  __m128 v17; // xmm3
  hkpCdBody *v18; // rcx
  hkpCdBody *i; // rax
  __m128 v20; // xmm2
  hkpCdBody *v21; // rcx
  __m128 v22; // xmm2
  hkpCdBody *j; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  unsigned __int64 v28; // rbx
  _QWORD *v29; // rax
  _QWORD *v30; // rcx
  _QWORD *v31; // r8
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  hkVector4f v35; // xmm4
  unsigned __int8 v36; // dl
  float **v37; // r8
  hkpCdBody *v38; // rbx
  hkpShape *v39; // rcx
  float *v40; // r12
  __int64 v41; // r8
  float v42; // xmm0_4
  __m128 *v43; // rax
  __int64 v44; // rcx
  __m128 v45; // xmm3
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm6
  __int64 v49; // r8
  hkcdVertex *v50; // rdx
  __m128 v51; // xmm1
  hkcdVertex *v52; // rbx
  __m128 *v53; // rax
  __m128 v54; // xmm3
  __m128 v55; // xmm4
  __m128 v56; // xmm5
  __m128 v57; // xmm6
  __int64 v58; // rcx
  signed __int64 v59; // rax
  __m128 v60; // xmm1
  unsigned __int8 v61; // al
  hkpProcessCollisionOutput::PotentialInfo *v62; // r8
  hkSimdFloat32 minSeparation; // [rsp+40h] [rbp-198h]
  hkSimdFloat32 allowedPenetrationDepth; // [rsp+50h] [rbp-188h]
  hkSimdFloat32 toiSeparation; // [rsp+60h] [rbp-178h]
  hkpGskManifoldWork work; // [rsp+70h] [rbp-168h]
  signed __int64 v67; // [rsp+1E0h] [rbp+8h]
  float **v68; // [rsp+1E8h] [rbp+10h]

  v5 = input;
  gskCache = (char *)agentData;
  v7 = separatingNormal;
  v8 = entry;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtPredGskf3";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = (unsigned int *)v5->m_input.m_storage->m_collisionQualityInfo.m_storage;
  v15 = 0;
  v16 = (unsigned __int8 *)(gskCache + 12);
  v17 = _mm_shuffle_ps((__m128)LODWORD(v5->m_distAtT1.m_storage), (__m128)LODWORD(v5->m_distAtT1.m_storage), 0);
  if ( v14[4] )
  {
    v18 = v5->m_bodyA.m_storage;
    for ( i = v5->m_bodyA.m_storage->m_parent; i; i = i->m_parent )
      v18 = i;
    v20 = (__m128)v18[3].m_shapeKey;
    v21 = v5->m_bodyB.m_storage;
    v22 = _mm_shuffle_ps(v20, v20, 0);
    for ( j = v21->m_parent; j; j = j->m_parent )
      v21 = j;
    v24 = _mm_min_ps(v22, _mm_shuffle_ps((__m128)v21[3].m_shapeKey, (__m128)v21[3].m_shapeKey, 0));
    v25 = _mm_shuffle_ps((__m128)v14[6], (__m128)v14[6], 0);
    v26 = _mm_mul_ps(_mm_shuffle_ps((__m128)v14[7], (__m128)v14[7], 0), v24);
    v27 = _mm_shuffle_ps(v7->m_quad, v7->m_quad, 255);
    allowedPenetrationDepth.m_real = v24;
    minSeparation.m_real = _mm_min_ps(_mm_mul_ps(v25, v24), _mm_add_ps(v26, v27));
    if ( v17.m128_f32[0] < minSeparation.m_real.m128_f32[0] )
    {
      toiSeparation.m_real = _mm_min_ps(
                               _mm_mul_ps(_mm_shuffle_ps((__m128)v14[10], (__m128)v14[10], 0), v24),
                               _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v14[11], (__m128)v14[11], 0), v24), v27));
      hk4dGskCollideCalcToi(
        v5,
        &allowedPenetrationDepth,
        &minSeparation,
        &toiSeparation,
        (hkpGskCache *)gskCache,
        v7,
        output);
LABEL_10:
      hkGskAgentUtil_processCollisionNoTim(
        (hkpAgent3Input *)&v5->m_bodyA,
        v8,
        gskCache,
        (hkpGskCache *)gskCache,
        (hkpGskManifold *)(gskCache + 12),
        v7,
        v15,
        output);
      goto $END_OF_FUNCTION_0;
    }
  }
  if ( v17.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)v14[3], (__m128)v14[3], 0)) || gskCache[11] & 0x10 )
    goto LABEL_10;
  v35.m_quad = _mm_shuffle_ps(v7->m_quad, _mm_unpackhi_ps(v7->m_quad, v17), 196);
  *v7 = (hkVector4f)v35.m_quad;
  v36 = gskCache[14];
  if ( v36 )
  {
    v37 = (float **)v5->m_bodyB.m_storage;
    v38 = v5->m_bodyA.m_storage;
    work.m_keepContact.m_storage = v5->m_input.m_storage->m_tolerance.m_storage;
    v39 = v38->m_shape;
    v40 = *v37;
    v68 = v37;
    v41 = *v16;
    work.m_radiusA.m_storage = *(float *)&v38->m_shape[1].vfptr;
    v42 = v40[8];
    work.m_masterNormal = (hkVector4f)v35.m_quad;
    work.m_radiusB.m_storage = v42;
    v67 = (signed __int64)&gskCache[8 * v36 + 16];
    work.m_radiusSumSqrd.m_storage = (float)((float)(work.m_radiusA.m_storage + work.m_keepContact.m_storage) + v42)
                                   * (float)((float)(work.m_radiusA.m_storage + work.m_keepContact.m_storage) + v42);
    ((void (__fastcall *)(hkpShape *, signed __int64, __int64, hkpGskManifoldWork *))v39->vfptr[4].__first_virtual_table_function__)(
      v39,
      v67,
      v41,
      &work);
    v43 = (__m128 *)v38->m_motion;
    v44 = *v16;
    v45 = *v43;
    v46 = v43[1];
    v47 = v43[2];
    v48 = v43[3];
    v49 = (signed int)v44 - 1;
    v50 = &work.m_vertices[v49];
    do
    {
      v51 = v50->m_quad;
      --v50;
      --v49;
      v50[1].m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), v46),
                            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), v45)),
                          _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), v47)),
                        v48);
    }
    while ( v49 >= 0 );
    v52 = &work.m_vertices[v44];
    (*(void (__fastcall **)(float *, signed __int64, _QWORD, hkcdVertex *))(*(_QWORD *)v40 + 72i64))(
      v40,
      v67 + 2 * v44,
      (unsigned __int8)gskCache[13],
      v52);
    v53 = (__m128 *)v68[2];
    v54 = *v53;
    v55 = v53[1];
    v56 = v53[2];
    v57 = v53[3];
    v58 = (unsigned __int8)gskCache[13] - 1;
    v59 = (signed __int64)&v52[v58];
    do
    {
      v60 = *(__m128 *)v59;
      v59 -= 16i64;
      --v58;
      *(__m128 *)(v59 + 16) = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), v55),
                                    _mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v54)),
                                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), v56)),
                                v57);
    }
    while ( v58 >= 0 );
    v15 = hkGskManifold_verifyAndGetPoints(
            (hkpGskManifold *)(gskCache + 12),
            &work,
            0,
            output,
            v5->m_contactMgr.m_storage);
    if ( v15 && gskCache[11] < 0 )
    {
      output->m_firstFreeContactPoint.m_storage -= (unsigned __int8)gskCache[14];
      goto LABEL_10;
    }
    v61 = gskCache[14];
    if ( v61 )
    {
      v62 = output->m_potentialContacts.m_storage;
      if ( v62 )
      {
        *v62->m_firstFreeRepresentativeContact = &output->m_firstFreeContactPoint.m_storage[-v61];
        ++v62->m_firstFreeRepresentativeContact;
      }
    }
  }
$END_OF_FUNCTION_0:
  v8->m_numContactPoints = gskCache[14];
  v28 = (unsigned __int64)&gskCache[(2
                                   * ((unsigned __int8)gskCache[12]
                                    + (unsigned __int8)gskCache[13]
                                    + 4 * (unsigned __int8)gskCache[14])
                                   + 4
                                   + 27i64) & 0xFFFFFFFFFFFFFFF0ui64];
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  v31 = v29;
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v32 = __rdtsc();
    v33 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v33 - 8) = v32;
    v31[1] = v33;
  }
  return v28;
}ID);
  v30 = (_QWORD *)v29[1];
  v31 = v29;
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";


