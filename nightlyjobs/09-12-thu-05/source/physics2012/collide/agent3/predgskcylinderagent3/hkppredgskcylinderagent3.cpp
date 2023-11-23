// File Line: 37
// RVA: 0xD2B540
void __fastcall hkPredGskCylinderAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_ignoreSymmetricVersion.m_bool = 1;
  memset(&f.m_updateFilterFunc, 0, 24);
  f.m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkPredGskCylinderAgent3::create;
  f.m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkPredGskCylinderAgent3::process;
  f.m_sepNormalFunc = (void (__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *, hkVector4f *))hkPredGskAgent3::sepNormal;
  f.m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkPredGskAgent3::cleanup;
  f.m_removePointFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkPredGskAgent3::removePoint;
  f.m_commitPotentialFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkPredGskAgent3::commitPotential;
  f.m_createZombieFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkPredGskAgent3::createZombie;
  f.m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkPredGskAgent3::destroy;
  f.m_isPredictive.m_bool = 1;
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, CYLINDER, CONVEX);
  f.m_reusePreviousEntry.m_bool = 1;
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, CONVEX, CYLINDER);
}

// File Line: 58
// RVA: 0xD2B600
void __fastcall replaceCylindersWithCapsulesInCdBodies(
        hkPadSpu<hkpCdBody const *> **cdBodies,
        hkPadSpu<unsigned int> *isReplacedWithCapsule,
        hkpCdBody *temporaryCdBodies,
        hkPadSpu<hkpCdBody const *> *originalCdBodies)
{
  hkpCdBody *v4; // rbp
  signed __int64 v6; // r15
  hkpCylinderShape ****v7; // rbx
  const void **p_m_motion; // rdi
  __int64 v9; // r12
  hkpCylinderShape *v10; // r14
  _QWORD **Value; // rax
  hkpCapsuleShape *v12; // r13
  float v13; // xmm0_4
  const void *v14; // rax
  const void *v15; // r8
  hkpCylinderShape **v16; // rcx
  hkpCylinderShape *v17; // rax

  v4 = temporaryCdBodies;
  v6 = (char *)originalCdBodies - (char *)cdBodies;
  v7 = (hkpCylinderShape ****)cdBodies;
  p_m_motion = &temporaryCdBodies->m_motion;
  v9 = 2i64;
  do
  {
    if ( isReplacedWithCapsule->m_storage )
    {
      v10 = ***v7;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpCapsuleShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
      if ( v12 )
      {
        v13 = (float)(hkpCylinderShape::getCylinderRadius(v10) + v10->m_radius) + 0.0020000001;
        hkpCapsuleShape::hkpCapsuleShape(v12, &v10->m_vertexA, &v10->m_vertexB, v13);
        v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      if ( p_m_motion != (const void **)16 )
      {
        v16 = **v7;
        v17 = v16[2];
        p_m_motion[1] = v16;
        *p_m_motion = v17;
      }
      *(p_m_motion - 2) = v15;
      *((_DWORD *)p_m_motion - 2) = -1;
      *(hkpCylinderShape ****)((char *)v7 + v6) = (hkpCylinderShape ***)**v7;
      **v7 = (hkpCylinderShape **)v4;
    }
    else
    {
      *(hkpCylinderShape ****)((char *)v7 + v6) = 0i64;
    }
    ++v4;
    ++isReplacedWithCapsule;
    p_m_motion += 4;
    ++v7;
    --v9;
  }
  while ( v9 );
}

// File Line: 88
// RVA: 0xD2B720
void __fastcall restoreOriginalShapesInCdBodies(
        hkReferencedObject ****cdBodies,
        hkPadSpu<hkpCdBody const *> *originalCdBodies)
{
  hkReferencedObject ****v2; // rbx
  __int64 v3; // rdi
  signed __int64 v4; // rsi

  v2 = cdBodies;
  v3 = 2i64;
  v4 = (char *)originalCdBodies - (char *)cdBodies;
  do
  {
    if ( *(hkReferencedObject ****)((char *)v2 + v4) )
    {
      hkReferencedObject::removeReference(***v2);
      **v2 = *(hkReferencedObject ***)((char *)v2 + v4);
    }
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 100
// RVA: 0xD2B780
void __fastcall resetGskManifold(
        hkpGskManifold *gskManifold,
        hkpAgentEntry *entry,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkGskManifold_cleanup(gskManifold, mgr, constraintOwner);
  entry->m_numContactPoints = gskManifold->m_numContactPoints;
}

// File Line: 113
// RVA: 0xD2B7C0
void __fastcall convertCylinderCacheToCapsuleCache(
        hkpGskCache *gskCache,
        hkPadSpu<unsigned int> *isReplacedWithCapsule)
{
  char m_dimA; // al
  unsigned __int16 v4; // ax
  unsigned __int16 *v5; // rcx

  if ( isReplacedWithCapsule->m_storage )
  {
    gskCache->m_vertices[0] = 16 * (1 - ((gskCache->m_vertices[0] >> 7) & 1));
    m_dimA = gskCache->m_dimA;
    if ( (unsigned __int8)m_dimA > 1u )
    {
      *(_DWORD *)gskCache->m_vertices = 16;
      if ( m_dimA == 3 )
      {
        v4 = gskCache->m_vertices[3];
        gskCache->m_dimA = 2;
        gskCache->m_vertices[2] = v4;
      }
    }
  }
  if ( isReplacedWithCapsule[1].m_storage )
  {
    v5 = &gskCache->m_vertices[(unsigned __int8)gskCache->m_dimA];
    *v5 = 16 * (1 - ((*v5 >> 7) & 1));
    if ( gskCache->m_dimB > 1u )
    {
      gskCache->m_vertices[(unsigned __int8)gskCache->m_dimA] = 16;
      gskCache->m_vertices[(unsigned __int8)gskCache->m_dimA + 1] = 0;
      if ( gskCache->m_dimB == 3 )
        gskCache->m_dimB = 2;
    }
  }
}

// File Line: 152
// RVA: 0xD2AA20
char *__fastcall hkPredGskCylinderAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, hkpGskCache *agentData)
{
  char *result; // rax

  result = hkPredGskAgent3::create(input, entry, agentData);
  agentData->m_gskFlags &= 0xF0u;
  if ( input->m_bodyA.m_storage->m_shape->m_type.m_storage == 1 )
    agentData->m_gskFlags |= 5u;
  if ( input->m_bodyB.m_storage->m_shape->m_type.m_storage == 1 )
    agentData->m_gskFlags |= 0xAu;
  return result;
}

// File Line: 176
// RVA: 0xD2B870
hkSimdFloat32 *__fastcall separatingDistanceUsingCapsuleRepresentations(
        hkSimdFloat32 *result,
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        _BYTE *agentData)
{
  __int128 v4; // xmm1
  char v5; // cl
  __int128 v6; // xmm0
  int *v7; // r15
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  __int64 v10; // rdi
  char *v11; // r12
  hkVector4f v12; // xmm0
  __int64 v13; // rax
  hkVector4f v14; // xmm1
  char *v15; // rbx
  __int64 v16; // rsi
  hkVector4f v17; // xmm0
  __int128 v18; // xmm1
  hkpCylinderShape ***v19; // r14
  hkpCylinderShape *v20; // r13
  _QWORD **Value; // rax
  float v22; // xmm0_4
  __int64 v23; // rax
  __int64 v24; // r8
  hkpCylinderShape *v25; // rcx
  __int64 v26; // rsi
  hkReferencedObject ***v27; // rbx
  hkSimdFloat32 *v28; // rax
  __int64 v29; // [rsp+20h] [rbp-E0h]
  __int64 v30[2]; // [rsp+28h] [rbp-D8h]
  __int64 v31[2]; // [rsp+38h] [rbp-C8h]
  hkpCapsuleShape *v32; // [rsp+48h] [rbp-B8h]
  hkpGskCache agentDataa; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f separatingNormalOut; // [rsp+60h] [rbp-A0h] BYREF
  hkpAgent3Input inputa; // [rsp+70h] [rbp-90h] BYREF
  __int128 v36; // [rsp+E0h] [rbp-20h]
  __m128 m_quad; // [rsp+F0h] [rbp-10h]
  char v38; // [rsp+100h] [rbp+0h] BYREF
  char v39; // [rsp+110h] [rbp+10h] BYREF
  int v43; // [rsp+1B8h] [rbp+B8h] BYREF
  int v44; // [rsp+1BCh] [rbp+BCh]

  v4 = *(_OWORD *)&input->m_overrideBodyA.m_storage;
  v5 = agentData[11];
  *(_OWORD *)&inputa.m_bodyA.m_storage = *(_OWORD *)&input->m_bodyA.m_storage;
  v6 = *(_OWORD *)&input->m_contactMgr.m_storage;
  *(_OWORD *)&inputa.m_overrideBodyA.m_storage = v4;
  v31[0] = (__int64)&inputa;
  v7 = &v43;
  v8.m_quad = (__m128)input->m_aTb.m_rotation.m_col0;
  *(_OWORD *)&inputa.m_contactMgr.m_storage = v6;
  v9.m_quad = (__m128)input->m_aTb.m_rotation.m_col1;
  v31[1] = (__int64)&inputa.m_bodyB;
  v10 = 0i64;
  v11 = &v38;
  inputa.m_aTb.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
  v12.m_quad = (__m128)input->m_aTb.m_translation;
  v43 = v5 & 1;
  v13 = 2i64;
  inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)v8.m_quad;
  v14.m_quad = (__m128)input->m_aTb.m_rotation.m_col2;
  inputa.m_aTb.m_translation = (hkVector4f)v12.m_quad;
  v44 = v5 & 2;
  v30[0] = 0i64;
  v30[1] = 0i64;
  v15 = &v39;
  v16 = 0i64;
  v29 = 2i64;
  v17.m_quad = (__m128)input->m_linearTimInfo;
  inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)v14.m_quad;
  v18 = *(_OWORD *)&input->m_distAtT1.m_storage;
  m_quad = v17.m_quad;
  v36 = v18;
  do
  {
    if ( *v7 )
    {
      v19 = (hkpCylinderShape ***)v31[v16];
      v20 = **v19;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (hkpCapsuleShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
      if ( v32 )
      {
        v22 = (float)(hkpCylinderShape::getCylinderRadius(v20) + v20->m_radius) + 0.0020000001;
        hkpCapsuleShape::hkpCapsuleShape(v32, &v20->m_vertexA, &v20->m_vertexB, v22);
        v24 = v23;
      }
      else
      {
        v24 = 0i64;
      }
      if ( v15 != (char *)16 )
      {
        v25 = (*v19)[2];
        *((_QWORD *)v15 + 1) = *v19;
        *(_QWORD *)v15 = v25;
      }
      *((_QWORD *)v15 - 2) = v24;
      *((_DWORD *)v15 - 2) = -1;
      v30[v16] = (__int64)*v19;
      v13 = v29;
      *v19 = (hkpCylinderShape **)v11;
    }
    else
    {
      v30[v16] = 0i64;
    }
    v11 += 32;
    ++v7;
    v15 += 32;
    ++v16;
    v29 = --v13;
  }
  while ( v13 );
  hkpGskCache::init(
    &agentDataa,
    (hkpConvexShape *)inputa.m_bodyA.m_storage->m_shape,
    (hkpConvexShape *)inputa.m_bodyB.m_storage->m_shape,
    &input->m_aTb);
  hkPredGskAgent3::sepNormal(&inputa, entry, &agentDataa, &separatingNormalOut);
  do
  {
    v26 = v30[v10];
    if ( v26 )
    {
      v27 = (hkReferencedObject ***)v31[v10];
      hkReferencedObject::removeReference(**v27);
      *v27 = (hkReferencedObject **)v26;
    }
    ++v10;
  }
  while ( v10 < 2 );
  v28 = result;
  result->m_real = _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 255);
  return v28;
}

// File Line: 212
// RVA: 0xD2AA80
char *__fastcall hkPredGskCylinderAgent3::process(
        hkVector4f *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  hkVector4f *v5; // r12
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  char v12; // cl
  __m128 v13; // xmm8
  __int64 v14; // rdi
  __m128 v15; // xmm8
  unsigned __int8 *v16; // rsi
  __m128 ****v17; // r13
  int v18; // r15d
  unsigned __int64 v19; // rbx
  __m128 **v20; // rcx
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  float v27; // xmm6_4
  hkpProcessCollisionOutput *out; // r13
  unsigned __int64 v29; // r8
  char v30; // r9
  unsigned int *v31; // rdx
  unsigned __int64 v32; // rcx
  unsigned __int64 i; // rax
  __m128 v34; // xmm2
  unsigned __int64 v35; // rcx
  __m128 v36; // xmm2
  unsigned __int64 j; // rax
  __m128 *p_m_quad; // rax
  __m128 v39; // xmm2
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __int64 *v43; // rax
  char *v44; // rcx
  unsigned __int64 v45; // rdx
  char *v46; // rbx
  __int64 v47; // r15
  hkpCylinderShape ***v48; // r12
  hkpCylinderShape *v49; // r13
  _QWORD **v50; // rax
  float v51; // xmm0_4
  __int64 v52; // rax
  __int64 v53; // r8
  __int64 *v54; // rax
  char *v55; // rcx
  unsigned __int64 v56; // rdx
  char *v57; // rbx
  __int64 v58; // r15
  hkpCylinderShape ***v59; // r12
  hkpCylinderShape *v60; // r13
  _QWORD **v61; // rax
  float v62; // xmm0_4
  __int64 v63; // rax
  __int64 v64; // r8
  hkpCylinderShape *v65; // rcx
  hkpCylinderShape **v66; // rax
  unsigned __int64 v67; // r13
  __int64 **v68; // rbx
  __int64 *v69; // rcx
  float *v70; // r15
  float v71; // xmm2_4
  unsigned __int8 v72; // al
  __int64 v73; // r8
  char *v74; // rdx
  __int64 v75; // rax
  __m128 *v76; // rax
  __int64 v77; // rcx
  __m128 v78; // xmm3
  __m128 v79; // xmm4
  __m128 v80; // xmm5
  __m128 v81; // xmm7
  __int64 v82; // r8
  hkcdVertex *v83; // rdx
  __m128 m_quad; // xmm1
  hkcdVertex *v85; // rbx
  __m128 *v86; // rax
  __m128 v87; // xmm3
  __m128 v88; // xmm4
  __m128 v89; // xmm5
  __m128 v90; // xmm7
  __int64 v91; // rdx
  __m128 *v92; // rcx
  __m128 v93; // xmm1
  unsigned __int8 v94; // al
  __int64 v95; // r8
  hkpCylinderShape *v96; // rcx
  hkpCylinderShape **v97; // rax
  hkpGskCache *p_result; // r9
  unsigned __int8 v99; // cl
  char v100; // cl
  unsigned __int64 v101; // r15
  hkReferencedObject ***v102; // rbx
  _QWORD *v103; // rax
  _QWORD *v104; // rcx
  _QWORD *v105; // r8
  unsigned __int64 v106; // rax
  _QWORD *v107; // rcx
  hkSimdFloat32 result; // [rsp+40h] [rbp-A8h] BYREF
  int explicitlyAllowNewPoint; // [rsp+50h] [rbp-98h]
  __int64 v111; // [rsp+58h] [rbp-90h] BYREF
  hkSimdFloat32 minSeparation; // [rsp+60h] [rbp-88h] BYREF
  hkSimdFloat32 allowedPenetrationDepth; // [rsp+70h] [rbp-78h] BYREF
  hkVector4f *v114; // [rsp+80h] [rbp-68h] BYREF
  unsigned __int64 *v115; // [rsp+88h] [rbp-60h]
  hkVector4f separatingNormalOut; // [rsp+98h] [rbp-50h] BYREF
  char v117[16]; // [rsp+A8h] [rbp-40h] BYREF
  char v118[48]; // [rsp+B8h] [rbp-30h] BYREF
  hkpGskManifoldWork work; // [rsp+E8h] [rbp+0h] BYREF
  hkVector4f *v120; // [rsp+288h] [rbp+1A0h]
  hkpAgentEntry *entrya; // [rsp+290h] [rbp+1A8h]
  char *retaddr; // [rsp+298h] [rbp+1B0h]

  v5 = input;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtPredGskf3";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  v12 = agentData[11];
  v13 = (__m128)v5[7].m_quad.m128_u32[0];
  v115 = &v5->m_quad.m128_u64[1];
  v14 = 0i64;
  v15 = _mm_shuffle_ps(v13, v13, 0);
  minSeparation.m_real.m128_i32[0] = v12 & 1;
  v16 = (unsigned __int8 *)(agentData + 12);
  v114 = v5;
  minSeparation.m_real.m128_i32[1] = v12 & 2;
  HIDWORD(v111) = v12 & 8;
  allowedPenetrationDepth.m_real = (__m128)0i64;
  LODWORD(v111) = v12 & 4;
  hkPredGskAgent3::sepNormal((hkpAgent3Input *)v5, entry, (hkpGskCache *)agentData, &separatingNormalOut);
  v17 = (__m128 ****)&v114;
  v18 = 0;
  allowedPenetrationDepth.m_real.m128_u64[0] = (unsigned __int64)&v114;
  v19 = 0i64;
  while ( 1 )
  {
    if ( !minSeparation.m_real.m128_i32[v19 / 4] )
      goto LABEL_13;
    v20 = **v17;
    v21 = _mm_sub_ps((*v20)[4], (*v20)[3]);
    v22 = _mm_mul_ps(v21, v21);
    v23 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
            _mm_shuffle_ps(v22, v22, 170));
    v24 = _mm_rsqrt_ps(v23);
    v25 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmple_ps(v23, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                _mm_mul_ps(*(__m128 *)_xmm, v24))));
    v26 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v20[2][1]),
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), *v20[2])),
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v20[2][2])),
            separatingNormalOut.m_quad);
    LODWORD(v27) = (unsigned int)(2
                                * COERCE_INT(
                                    (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v26, v26, 170).m128_f32[0])) >> 1;
    separatingDistanceUsingCapsuleRepresentations(&result, (hkpAgent3ProcessInput *)v5, entrya, agentData);
    if ( !*(_DWORD *)((char *)&v111 + v19) )
    {
      explicitlyAllowNewPoint = 1028443341;
      if ( v27 < _mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0).m128_f32[0]
        || (minSeparation.m_real.m128_i32[2] = 1008981770,
            result.m_real.m128_f32[0] > _mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0).m128_f32[0]) )
      {
        out = (hkpProcessCollisionOutput *)entry;
        *(_DWORD *)((char *)&v111 + v19) = 1;
        agentData[11] |= 4 << v18;
        hkGskManifold_cleanup(
          (hkpGskManifold *)(agentData + 12),
          (hkpContactMgr *)v5[2].m_quad.m128_u64[0],
          *(hkpConstraintOwner **)&entry[2].m_streamCommand);
        entrya->m_numContactPoints = agentData[14];
        goto LABEL_14;
      }
LABEL_13:
      out = (hkpProcessCollisionOutput *)entry;
      goto LABEL_14;
    }
    LODWORD(retaddr) = 1036831949;
    if ( v27 <= _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0).m128_f32[0] )
      goto LABEL_13;
    out = (hkpProcessCollisionOutput *)entry;
    if ( result.m_real.m128_f32[0] < 0.0 )
    {
      *(_DWORD *)((char *)&v111 + v19) = 0;
      agentData[11] &= ~(4 << v18);
      hkGskManifold_cleanup(
        (hkpGskManifold *)(agentData + 12),
        (hkpContactMgr *)v5[2].m_quad.m128_u64[0],
        *(hkpConstraintOwner **)&entry[2].m_streamCommand);
      entrya->m_numContactPoints = agentData[14];
    }
LABEL_14:
    allowedPenetrationDepth.m_real.m128_u64[0] += 8i64;
    ++v18;
    v19 += 4i64;
    if ( v18 >= 2 )
      break;
    v17 = (__m128 ****)allowedPenetrationDepth.m_real.m128_u64[0];
  }
  v29 = v5[1].m_quad.m128_u64[1];
  v30 = 0;
  v31 = *(unsigned int **)(v29 + 112);
  explicitlyAllowNewPoint = 0;
  if ( v31[4] )
  {
    v32 = v5->m_quad.m128_u64[0];
    for ( i = *(_QWORD *)(v5->m_quad.m128_u64[0] + 24); i; i = *(_QWORD *)(i + 24) )
      v32 = i;
    v34 = (__m128)*(unsigned int *)(v32 + 104);
    v35 = v5->m_quad.m128_u64[1];
    v36 = _mm_shuffle_ps(v34, v34, 0);
    for ( j = *(_QWORD *)(v35 + 24); j; j = *(_QWORD *)(j + 24) )
      v35 = j;
    p_m_quad = &input->m_quad;
    v39 = _mm_min_ps(v36, _mm_shuffle_ps((__m128)*(unsigned int *)(v35 + 104), (__m128)*(unsigned int *)(v35 + 104), 0));
    v40 = _mm_shuffle_ps((__m128)v31[6], (__m128)v31[6], 0);
    v41 = _mm_mul_ps(_mm_shuffle_ps((__m128)v31[7], (__m128)v31[7], 0), v39);
    v42 = _mm_shuffle_ps(input->m_quad, input->m_quad, 255);
    allowedPenetrationDepth.m_real = v39;
    minSeparation.m_real = _mm_min_ps(_mm_mul_ps(v40, v39), _mm_add_ps(v41, v42));
    if ( v15.m128_f32[0] < minSeparation.m_real.m128_f32[0] )
    {
      result.m_real = _mm_min_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v31[10], (__m128)v31[10], 0), v39),
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v31[11], (__m128)v31[11], 0), v39), v42));
      hk4dGskCollideCalcToi(
        (hkpAgent3ProcessInput *)v5,
        &allowedPenetrationDepth,
        &minSeparation,
        &result,
        (hkpGskCache *)agentData,
        input,
        out);
      v30 = 0;
      goto LABEL_22;
    }
  }
  else
  {
    p_m_quad = &input->m_quad;
  }
  if ( v15.m128_f32[0] <= _mm_shuffle_ps((__m128)v31[3], (__m128)v31[3], 0).m128_f32[0]
    || (agentData[11] & 0x10) != 0
    || _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 255).m128_f32[0] >= _mm_shuffle_ps(
                                                                                                    (__m128)*(unsigned int *)(v29 + 16),
                                                                                                    (__m128)*(unsigned int *)(v29 + 16),
                                                                                                    0).m128_f32[0] )
  {
LABEL_22:
    if ( _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 255).m128_f32[0] >= _mm_shuffle_ps((__m128)*(unsigned int *)(v5[1].m_quad.m128_u64[1] + 16), (__m128)*(unsigned int *)(v5[1].m_quad.m128_u64[1] + 16), 0).m128_f32[0] )
    {
      if ( agentData[14] )
        hkGskManifold_cleanup(
          (hkpGskManifold *)(agentData + 12),
          (hkpContactMgr *)v5[2].m_quad.m128_u64[0],
          out->m_constraintOwner.m_storage);
    }
    else
    {
      if ( !v30 )
      {
        v43 = &v111;
        v44 = v117;
        v45 = 2i64;
        v46 = v118;
        v47 = 0i64;
        minSeparation.m_real.m128_u64[0] = (unsigned __int64)&v111;
        retaddr = v117;
        allowedPenetrationDepth.m_real.m128_u64[0] = 2i64;
        do
        {
          if ( *(_DWORD *)v43 )
          {
            v48 = *(hkpCylinderShape ****)((char *)&v114 + v47 * 8);
            v49 = **v48;
            v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            minSeparation.m_real.m128_u64[1] = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v50[11] + 8i64))(
                                                 v50[11],
                                                 80i64);
            if ( minSeparation.m_real.m128_u64[1] )
            {
              v51 = (float)(hkpCylinderShape::getCylinderRadius(v49) + v49->m_radius) + 0.0020000001;
              hkpCapsuleShape::hkpCapsuleShape(
                (hkpCapsuleShape *)minSeparation.m_real.m128_u64[1],
                &v49->m_vertexA,
                &v49->m_vertexB,
                v51);
              v53 = v52;
            }
            else
            {
              v53 = 0i64;
            }
            if ( v46 != (char *)16 )
            {
              v96 = (*v48)[2];
              *((_QWORD *)v46 + 1) = *v48;
              *(_QWORD *)v46 = v96;
            }
            v44 = retaddr;
            *((_QWORD *)v46 - 2) = v53;
            v45 = allowedPenetrationDepth.m_real.m128_u64[0];
            *((_DWORD *)v46 - 2) = -1;
            v97 = *v48;
            *v48 = (hkpCylinderShape **)retaddr;
            allowedPenetrationDepth.m_real.m128_u64[v47] = (unsigned __int64)v97;
            v43 = (__int64 *)minSeparation.m_real.m128_u64[0];
          }
          else
          {
            allowedPenetrationDepth.m_real.m128_u64[v47] = 0i64;
          }
          v44 += 32;
          v43 = (__int64 *)((char *)v43 + 4);
          v46 += 32;
          ++v47;
          --v45;
          retaddr = v44;
          allowedPenetrationDepth.m_real.m128_u64[0] = v45;
          minSeparation.m_real.m128_u64[0] = (unsigned __int64)v43;
        }
        while ( v45 );
        v5 = v120;
        out = (hkpProcessCollisionOutput *)entry;
      }
      p_result = (hkpGskCache *)agentData;
      if ( v111 )
      {
        p_result = (hkpGskCache *)&result;
        result.m_real.m128_u64[0] = *(_QWORD *)agentData;
        result.m_real.m128_i32[2] = *((_DWORD *)agentData + 2);
        if ( (_DWORD)v111 )
        {
          v99 = result.m_real.m128_i8[8];
          result.m_real.m128_i16[0] = 16 * (1 - (((unsigned __int16)result.m_real.m128_i16[0] >> 7) & 1));
          if ( result.m_real.m128_i8[8] > 1u )
          {
            result.m_real.m128_i32[0] = 16;
            if ( result.m_real.m128_i8[8] == 3 )
            {
              v99 = 2;
              result.m_real.m128_i16[2] = result.m_real.m128_i16[3];
              result.m_real.m128_i8[8] = 2;
            }
          }
        }
        else
        {
          v99 = result.m_real.m128_i8[8];
        }
        if ( HIDWORD(v111) )
        {
          result.m_real.m128_i16[v99] = 16 * (1 - (((unsigned __int16)result.m_real.m128_i16[v99] >> 7) & 1));
          if ( result.m_real.m128_i8[9] > 1u )
          {
            result.m_real.m128_i16[(unsigned __int8)result.m_real.m128_i8[8]] = 16;
            result.m_real.m128_i16[(unsigned __int8)result.m_real.m128_i8[8] + 1] = 0;
            v100 = result.m_real.m128_i8[9];
            if ( result.m_real.m128_i8[9] == 3 )
              v100 = 2;
            result.m_real.m128_i8[9] = v100;
          }
        }
      }
      hkGskAgentUtil_processCollisionNoTim(
        (hkpAgent3Input *)v5,
        entrya,
        agentData,
        p_result,
        (hkpGskManifold *)(agentData + 12),
        input,
        explicitlyAllowNewPoint,
        out);
    }
    *input = (hkVector4f)separatingNormalOut.m_quad;
  }
  else
  {
    *p_m_quad = _mm_shuffle_ps(*p_m_quad, _mm_unpackhi_ps(*p_m_quad, v15), 196);
    if ( agentData[14] )
    {
      v54 = &v111;
      v55 = v117;
      v56 = 2i64;
      v57 = v118;
      v58 = 0i64;
      minSeparation.m_real.m128_u64[0] = (unsigned __int64)&v111;
      retaddr = v117;
      allowedPenetrationDepth.m_real.m128_u64[0] = 2i64;
      do
      {
        if ( *(_DWORD *)v54 )
        {
          v59 = *(hkpCylinderShape ****)((char *)&v114 + v58 * 8);
          v60 = **v59;
          v61 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          minSeparation.m_real.m128_u64[1] = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v61[11] + 8i64))(
                                               v61[11],
                                               80i64);
          if ( minSeparation.m_real.m128_u64[1] )
          {
            v62 = (float)(hkpCylinderShape::getCylinderRadius(v60) + v60->m_radius) + 0.0020000001;
            hkpCapsuleShape::hkpCapsuleShape(
              (hkpCapsuleShape *)minSeparation.m_real.m128_u64[1],
              &v60->m_vertexA,
              &v60->m_vertexB,
              v62);
            v64 = v63;
          }
          else
          {
            v64 = 0i64;
          }
          if ( v57 != (char *)16 )
          {
            v65 = (*v59)[2];
            *((_QWORD *)v57 + 1) = *v59;
            *(_QWORD *)v57 = v65;
          }
          v55 = retaddr;
          *((_QWORD *)v57 - 2) = v64;
          v56 = allowedPenetrationDepth.m_real.m128_u64[0];
          *((_DWORD *)v57 - 2) = -1;
          v66 = *v59;
          *v59 = (hkpCylinderShape **)retaddr;
          allowedPenetrationDepth.m_real.m128_u64[v58] = (unsigned __int64)v66;
          v54 = (__int64 *)minSeparation.m_real.m128_u64[0];
        }
        else
        {
          allowedPenetrationDepth.m_real.m128_u64[v58] = 0i64;
        }
        v55 += 32;
        v54 = (__int64 *)((char *)v54 + 4);
        v57 += 32;
        ++v58;
        --v56;
        retaddr = v55;
        allowedPenetrationDepth.m_real.m128_u64[0] = v56;
        minSeparation.m_real.m128_u64[0] = (unsigned __int64)v54;
      }
      while ( v56 );
      v5 = v120;
      LOBYTE(retaddr) = 1;
      v67 = *v115;
      v68 = (__int64 **)v120->m_quad.m128_u64[0];
      work.m_keepContact.m_storage = *(float *)(v120[1].m_quad.m128_u64[1] + 16);
      v69 = *v68;
      v70 = *(float **)v67;
      work.m_radiusA.m_storage = *((float *)*v68 + 8);
      v71 = (float)(work.m_radiusA.m_storage + work.m_keepContact.m_storage) + v70[8];
      work.m_radiusB.m_storage = v70[8];
      v72 = agentData[14];
      work.m_masterNormal = (hkVector4f)input->m_quad;
      work.m_radiusSumSqrd.m_storage = v71 * v71;
      if ( v72 )
      {
        v73 = *v16;
        v74 = &agentData[8 * v72 + 16];
        v75 = *v69;
        minSeparation.m_real.m128_u64[0] = (unsigned __int64)v74;
        (*(void (__fastcall **)(__int64 *, char *, __int64, hkpGskManifoldWork *))(v75 + 72))(v69, v74, v73, &work);
        v76 = (__m128 *)v68[2];
        v77 = *v16;
        v78 = *v76;
        v79 = v76[1];
        v80 = v76[2];
        v81 = v76[3];
        v82 = (int)v77 - 1;
        v83 = &work.m_vertices[v82];
        do
        {
          m_quad = v83->m_quad;
          --v83;
          --v82;
          v83[1].m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v79),
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v78)),
                              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v80)),
                            v81);
        }
        while ( v82 >= 0 );
        v85 = &work.m_vertices[v77];
        (*(void (__fastcall **)(float *, unsigned __int64, _QWORD, hkcdVertex *))(*(_QWORD *)v70 + 72i64))(
          v70,
          minSeparation.m_real.m128_u64[0] + 2 * v77,
          (unsigned __int8)agentData[13],
          v85);
        v86 = *(__m128 **)(v67 + 16);
        v87 = *v86;
        v88 = v86[1];
        v89 = v86[2];
        v90 = v86[3];
        v91 = (unsigned __int8)agentData[13] - 1;
        v92 = &v85[v91].m_quad;
        do
        {
          v93 = *v92--;
          --v91;
          v92[1] = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v93, v93, 85), v88),
                         _mm_mul_ps(_mm_shuffle_ps(v93, v93, 0), v87)),
                       _mm_mul_ps(_mm_shuffle_ps(v93, v93, 170), v89)),
                     v90);
        }
        while ( v91 >= 0 );
      }
      out = (hkpProcessCollisionOutput *)entry;
      explicitlyAllowNewPoint = hkGskManifold_verifyAndGetPoints(
                                  (hkpGskManifold *)(agentData + 12),
                                  &work,
                                  0,
                                  (hkpProcessCollisionOutput *)entry,
                                  (hkpContactMgr *)v5[2].m_quad.m128_u64[0]);
      if ( explicitlyAllowNewPoint && agentData[11] < 0 )
      {
        v30 = (char)retaddr;
        *(_QWORD *)&entry->m_streamCommand += -48i64 * (unsigned __int8)agentData[14];
        goto LABEL_22;
      }
      v94 = agentData[14];
      if ( v94 )
      {
        v95 = *(_QWORD *)&entry[3108].m_streamCommand;
        if ( v95 )
        {
          **(_QWORD **)(v95 + 8) = *(_QWORD *)&entry->m_streamCommand - 48i64 * v94;
          *(_QWORD *)(v95 + 8) += 8i64;
        }
      }
    }
  }
  do
  {
    v101 = allowedPenetrationDepth.m_real.m128_u64[v14];
    if ( v101 )
    {
      v102 = *(hkReferencedObject ****)((char *)&v114 + v14 * 8);
      hkReferencedObject::removeReference(**v102);
      *v102 = (hkReferencedObject **)v101;
    }
    ++v14;
  }
  while ( v14 < 2 );
  entrya->m_numContactPoints = agentData[14];
  v103 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v104 = (_QWORD *)v103[1];
  v105 = v103;
  if ( (unsigned __int64)v104 < v103[3] )
  {
    *v104 = "Et";
    v106 = __rdtsc();
    v107 = v104 + 2;
    *((_DWORD *)v107 - 2) = v106;
    v105[1] = v107;
  }
  return &agentData[(2
                   * ((unsigned __int8)agentData[12]
                    + (unsigned __int8)agentData[13]
                    + 4 * (unsigned __int8)agentData[14])
                   + 4
                   + 27i64) & 0xFFFFFFFFFFFFFFF0ui64];
}

