// File Line: 37
// RVA: 0xD2B540
void __fastcall hkPredGskCylinderAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h]

  *(_WORD *)&f.m_ignoreSymmetricVersion.m_bool = 1;
  f.m_updateFilterFunc = 0i64;
  f.m_invalidateTimFunc = 0i64;
  f.m_warpTimeFunc = 0i64;
  f.m_createFunc = hkPredGskCylinderAgent3::create;
  v1 = dispatcher;
  f.m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkPredGskCylinderAgent3::process;
  f.m_sepNormalFunc = hkPredGskAgent3::sepNormal;
  f.m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkPredGskAgent3::cleanup;
  f.m_removePointFunc = hkPredGskAgent3::removePoint;
  f.m_commitPotentialFunc = hkPredGskAgent3::commitPotential;
  f.m_createZombieFunc = hkPredGskAgent3::createZombie;
  f.m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkPredGskAgent3::destroy;
  f.m_isPredictive.m_bool = 1;
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, CYLINDER, CONVEX);
  f.m_reusePreviousEntry.m_bool = 1;
  hkpCollisionDispatcher::registerAgent3(v1, &f, CONVEX, CYLINDER);
}

// File Line: 58
// RVA: 0xD2B600
void __fastcall replaceCylindersWithCapsulesInCdBodies(hkPadSpu<hkpCdBody const *> **cdBodies, hkPadSpu<unsigned int> *isReplacedWithCapsule, hkpCdBody *temporaryCdBodies, hkPadSpu<hkpCdBody const *> *originalCdBodies)
{
  hkpCdBody *v4; // rbp
  hkPadSpu<unsigned int> *v5; // rsi
  signed __int64 v6; // r15
  hkPadSpu<hkpCdBody const *> **v7; // rbx
  const void **v8; // rdi
  signed __int64 v9; // r12
  hkpCylinderShape *v10; // r14
  _QWORD **v11; // rax
  hkpCapsuleShape *v12; // r13
  float v13; // xmm0_4
  const void *v14; // rax
  const void *v15; // r8
  hkpCdBody *v16; // rcx
  const void *v17; // rax

  v4 = temporaryCdBodies;
  v5 = isReplacedWithCapsule;
  v6 = (char *)originalCdBodies - (char *)cdBodies;
  v7 = cdBodies;
  v8 = &temporaryCdBodies->m_motion;
  v9 = 2i64;
  do
  {
    if ( v5->m_storage )
    {
      v10 = (hkpCylinderShape *)(*v7)->m_storage->m_shape;
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpCapsuleShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 80i64);
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
      if ( v8 != (const void **)16 )
      {
        v16 = (*v7)->m_storage;
        v17 = v16->m_motion;
        v8[1] = v16;
        *v8 = v17;
      }
      *(v8 - 2) = v15;
      *((_DWORD *)v8 - 2) = -1;
      *(hkPadSpu<hkpCdBody const *> **)((char *)v7 + v6) = (hkPadSpu<hkpCdBody const *> *)(*v7)->m_storage;
      (*v7)->m_storage = v4;
    }
    else
    {
      *(hkPadSpu<hkpCdBody const *> **)((char *)v7 + v6) = 0i64;
    }
    ++v4;
    ++v5;
    v8 += 4;
    ++v7;
    --v9;
  }
  while ( v9 );
}

// File Line: 88
// RVA: 0xD2B720
void __fastcall restoreOriginalShapesInCdBodies(hkPadSpu<hkpCdBody const *> **cdBodies, hkPadSpu<hkpCdBody const *> *originalCdBodies)
{
  hkReferencedObject ****v2; // rbx
  signed __int64 v3; // rdi
  signed __int64 v4; // rsi

  v2 = (hkReferencedObject ****)cdBodies;
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
void __fastcall resetGskManifold(hkpGskManifold *gskManifold, hkpAgentEntry *entry, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkpAgentEntry *v4; // rdi
  hkpGskManifold *v5; // rbx

  v4 = entry;
  v5 = gskManifold;
  hkGskManifold_cleanup(gskManifold, mgr, constraintOwner);
  v4->m_numContactPoints = v5->m_numContactPoints;
}

// File Line: 113
// RVA: 0xD2B7C0
void __fastcall convertCylinderCacheToCapsuleCache(hkpGskCache *gskCache, hkPadSpu<unsigned int> *isReplacedWithCapsule)
{
  hkpGskCache *v2; // r9
  char v3; // al
  unsigned __int16 v4; // ax
  unsigned __int16 *v5; // rcx

  v2 = gskCache;
  if ( isReplacedWithCapsule->m_storage )
  {
    gskCache->m_vertices[0] = 16 * (1 - ((gskCache->m_vertices[0] >> 7) & 1));
    v3 = gskCache->m_dimA;
    if ( (unsigned __int8)v3 > 1u )
    {
      *(_DWORD *)gskCache->m_vertices = 16;
      if ( v3 == 3 )
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
    if ( v2->m_dimB > 1u )
    {
      v2->m_vertices[(unsigned __int8)v2->m_dimA] = 16;
      v2->m_vertices[(unsigned __int8)v2->m_dimA + 1] = 0;
      if ( v2->m_dimB == 3 )
        v2->m_dimB = 2;
    }
  }
}

// File Line: 152
// RVA: 0xD2AA20
void *__fastcall hkPredGskCylinderAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData)
{
  _BYTE *v3; // rbx
  hkpAgent3Input *v4; // rdi
  void *result; // rax

  v3 = agentData;
  v4 = input;
  result = (void *)hkPredGskAgent3::create(input, entry, agentData);
  v3[11] &= 0xF0u;
  if ( v4->m_bodyA.m_storage->m_shape->m_type.m_storage == 1 )
    v3[11] |= 5u;
  if ( v4->m_bodyB.m_storage->m_shape->m_type.m_storage == 1 )
    v3[11] |= 0xAu;
  return result;
}

// File Line: 176
// RVA: 0xD2B870
hkSimdFloat32 *__fastcall separatingDistanceUsingCapsuleRepresentations(hkSimdFloat32 *result, hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData)
{
  __int128 v4; // xmm1
  char v5; // cl
  __int128 v6; // xmm0
  int *v7; // r15
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  signed __int64 v10; // rdi
  char *v11; // r12
  hkVector4f v12; // xmm0
  signed __int64 v13; // rax
  hkVector4f v14; // xmm1
  char *v15; // rbx
  __int64 v16; // rsi
  hkVector4f v17; // xmm0
  __int128 v18; // xmm1
  hkpCylinderShape ***v19; // r14
  hkpCylinderShape *v20; // r13
  _QWORD **v21; // rax
  float v22; // xmm0_4
  __int64 v23; // rax
  __int64 v24; // r8
  hkpCylinderShape *v25; // rcx
  hkReferencedObject **v26; // rsi
  hkReferencedObject ***v27; // rbx
  hkSimdFloat32 *v28; // rax
  signed __int64 v29; // [rsp+20h] [rbp-E0h]
  __int64 v30; // [rsp+28h] [rbp-D8h]
  __int64 v31; // [rsp+30h] [rbp-D0h]
  hkpAgent3Input *v32; // [rsp+38h] [rbp-C8h]
  hkPadSpu<hkpCdBody const *> *v33; // [rsp+40h] [rbp-C0h]
  hkpCapsuleShape *v34; // [rsp+48h] [rbp-B8h]
  hkpGskCache agentDataa; // [rsp+50h] [rbp-B0h]
  hkVector4f separatingNormalOut; // [rsp+60h] [rbp-A0h]
  hkpAgent3Input inputa; // [rsp+70h] [rbp-90h]
  __int128 v38; // [rsp+E0h] [rbp-20h]
  __m128 v39; // [rsp+F0h] [rbp-10h]
  char v40; // [rsp+100h] [rbp+0h]
  char v41; // [rsp+110h] [rbp+10h]
  hkSimdFloat32 *v42; // [rsp+1A0h] [rbp+A0h]
  hkpAgent3ProcessInput *v43; // [rsp+1A8h] [rbp+A8h]
  hkpAgentEntry *entrya; // [rsp+1B0h] [rbp+B0h]
  int v45; // [rsp+1B8h] [rbp+B8h]
  int v46; // [rsp+1BCh] [rbp+BCh]

  entrya = entry;
  v43 = input;
  v42 = result;
  v4 = *(_OWORD *)&input->m_overrideBodyA.m_storage;
  v5 = *((_BYTE *)agentData + 11);
  *(_OWORD *)&inputa.m_bodyA.m_storage = *(_OWORD *)&input->m_bodyA.m_storage;
  v6 = *(_OWORD *)&input->m_contactMgr.m_storage;
  *(_OWORD *)&inputa.m_overrideBodyA.m_storage = v4;
  v32 = &inputa;
  v7 = &v45;
  v8.m_quad = (__m128)input->m_aTb.m_rotation.m_col0;
  *(_OWORD *)&inputa.m_contactMgr.m_storage = v6;
  v9.m_quad = (__m128)input->m_aTb.m_rotation.m_col1;
  v33 = &inputa.m_bodyB;
  v10 = 0i64;
  v11 = &v40;
  inputa.m_aTb.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
  v12.m_quad = (__m128)input->m_aTb.m_translation;
  v45 = v5 & 1;
  v13 = 2i64;
  inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)v8.m_quad;
  v14.m_quad = (__m128)input->m_aTb.m_rotation.m_col2;
  inputa.m_aTb.m_translation = (hkVector4f)v12.m_quad;
  v46 = v5 & 2;
  v30 = 0i64;
  v31 = 0i64;
  v15 = &v41;
  v16 = 0i64;
  v29 = 2i64;
  v17.m_quad = (__m128)input->m_linearTimInfo;
  inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)v14.m_quad;
  v18 = *(_OWORD *)&input->m_distAtT1.m_storage;
  v39 = v17.m_quad;
  v38 = v18;
  do
  {
    if ( *v7 )
    {
      v19 = *(hkpCylinderShape ****)((char *)&v32 + v16);
      v20 = **v19;
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v34 = (hkpCapsuleShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 80i64);
      if ( v34 )
      {
        v22 = (float)(hkpCylinderShape::getCylinderRadius(v20) + v20->m_radius) + 0.0020000001;
        hkpCapsuleShape::hkpCapsuleShape(v34, &v20->m_vertexA, &v20->m_vertexB, v22);
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
      *(__int64 *)((char *)&v30 + v16) = (__int64)*v19;
      v13 = v29;
      *v19 = (hkpCylinderShape **)v11;
    }
    else
    {
      *(__int64 *)((char *)&v30 + v16) = 0i64;
    }
    v11 += 32;
    ++v7;
    v15 += 32;
    v16 += 8i64;
    v29 = --v13;
  }
  while ( v13 );
  hkpGskCache::init(
    &agentDataa,
    (hkpConvexShape *)inputa.m_bodyA.m_storage->m_shape,
    (hkpConvexShape *)inputa.m_bodyB.m_storage->m_shape,
    &v43->m_aTb);
  hkPredGskAgent3::sepNormal(&inputa, entrya, &agentDataa, &separatingNormalOut);
  do
  {
    v26 = *(hkReferencedObject ***)((char *)&v30 + v10);
    if ( v26 )
    {
      v27 = *(hkReferencedObject ****)((char *)&v32 + v10);
      hkReferencedObject::removeReference(**v27);
      *v27 = v26;
    }
    v10 += 8i64;
  }
  while ( v10 < 16 );
  v28 = v42;
  v42->m_real = _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 255);
  return v28;
}

// File Line: 212
// RVA: 0xD2AA80
unsigned __int64 __fastcall hkPredGskCylinderAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v5; // r12
  char *gskCache; // r14
  hkpAgentEntry *v7; // rbx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  char v12; // cl
  __m128 v13; // xmm8
  signed __int64 v14; // rdi
  __m128 v15; // xmm8
  unsigned __int8 *v16; // rsi
  __m128 ****v17; // r13
  signed int v18; // er15
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
  hkpProcessCollisionInput *v29; // r8
  char v30; // r9
  unsigned int *v31; // rdx
  hkpCdBody *v32; // rcx
  hkpCdBody *i; // rax
  __m128 v34; // xmm2
  hkpCdBody *v35; // rcx
  __m128 v36; // xmm2
  hkpCdBody *j; // rax
  __m128 *v38; // rax
  __m128 v39; // xmm2
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __int64 *v43; // rax
  char *v44; // rcx
  signed __int64 v45; // rdx
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
  signed __int64 v56; // rdx
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
  hkpCdBody *v67; // r13
  hkpCdBody *v68; // rbx
  hkpShape *v69; // rcx
  float *v70; // r15
  float v71; // xmm2_4
  float v72; // xmm2_4
  unsigned __int8 v73; // al
  __int64 v74; // r8
  signed __int64 v75; // rdx
  hkBaseObjectVtbl *v76; // rax
  __m128 *v77; // rax
  __int64 v78; // rcx
  __m128 v79; // xmm3
  __m128 v80; // xmm4
  __m128 v81; // xmm5
  __m128 v82; // xmm7
  __int64 v83; // r8
  hkcdVertex *v84; // rdx
  __m128 v85; // xmm1
  hkcdVertex *v86; // rbx
  __m128 *v87; // rax
  __m128 v88; // xmm3
  __m128 v89; // xmm4
  __m128 v90; // xmm5
  __m128 v91; // xmm7
  __int64 v92; // rdx
  signed __int64 v93; // rcx
  __m128 v94; // xmm1
  unsigned __int8 v95; // al
  hkpProcessCollisionOutput::PotentialInfo *v96; // r8
  hkpCylinderShape *v97; // rcx
  hkpCylinderShape **v98; // rax
  hkpGskCache *v99; // r9
  unsigned __int8 v100; // cl
  char v101; // cl
  unsigned __int64 v102; // r15
  hkReferencedObject ***v103; // rbx
  _QWORD *v104; // rax
  _QWORD *v105; // rcx
  _QWORD *v106; // r8
  unsigned __int64 v107; // rax
  signed __int64 v108; // rcx
  hkSimdFloat32 result; // [rsp+40h] [rbp-A8h]
  int explicitlyAllowNewPoint; // [rsp+50h] [rbp-98h]
  __int64 v112; // [rsp+58h] [rbp-90h]
  hkSimdFloat32 minSeparation; // [rsp+60h] [rbp-88h]
  hkSimdFloat32 allowedPenetrationDepth; // [rsp+70h] [rbp-78h]
  hkpAgent3ProcessInput *v115; // [rsp+80h] [rbp-68h]
  hkPadSpu<hkpCdBody const *> *v116; // [rsp+88h] [rbp-60h]
  hkVector4f separatingNormalOut; // [rsp+98h] [rbp-50h]
  char v118; // [rsp+A8h] [rbp-40h]
  char v119; // [rsp+B8h] [rbp-30h]
  hkpGskManifoldWork work; // [rsp+E8h] [rbp+0h]
  hkpAgent3ProcessInput *v121; // [rsp+288h] [rbp+1A0h]
  hkpAgentEntry *entrya; // [rsp+290h] [rbp+1A8h]
  char *retaddr; // [rsp+298h] [rbp+1B0h]
  hkVector4f *v124; // [rsp+2A0h] [rbp+1B8h]
  hkpProcessCollisionOutput *processOut; // [rsp+2A8h] [rbp+1C0h]

  processOut = (hkpProcessCollisionOutput *)entry;
  v124 = (hkVector4f *)input;
  v5 = input;
  gskCache = (char *)agentData;
  v7 = entry;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtPredGskf3";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = gskCache[11];
  v13 = (__m128)LODWORD(v5->m_distAtT1.m_storage);
  v116 = &v5->m_bodyB;
  v14 = 0i64;
  v15 = _mm_shuffle_ps(v13, v13, 0);
  minSeparation.m_real.m128_i32[0] = v12 & 1;
  v16 = (unsigned __int8 *)(gskCache + 12);
  v115 = v5;
  minSeparation.m_real.m128_i32[1] = v12 & 2;
  HIDWORD(v112) = v12 & 8;
  allowedPenetrationDepth.m_real = (__m128)0i64;
  LODWORD(v112) = v12 & 4;
  hkPredGskAgent3::sepNormal((hkpAgent3Input *)&v5->m_bodyA, v7, gskCache, &separatingNormalOut);
  v17 = (__m128 ****)&v115;
  v18 = 0;
  allowedPenetrationDepth.m_real.m128_u64[0] = (unsigned __int64)&v115;
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
              _mm_cmpleps(v23, (__m128)0i64),
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
                                * COERCE_SIGNED_INT(
                                    (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170)))) >> 1;
    separatingDistanceUsingCapsuleRepresentations(&result, v5, entrya, gskCache);
    if ( !*(_DWORD *)((char *)&v112 + v19) )
    {
      explicitlyAllowNewPoint = 1028443341;
      if ( v27 < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0))
        || (minSeparation.m_real.m128_i32[2] = 1008981770,
            result.m_real.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3C23D70Au, (__m128)0x3C23D70Au, 0))) )
      {
        out = processOut;
        *(_DWORD *)((char *)&v112 + v19) = 1;
        gskCache[11] |= 4 << v18;
        hkGskManifold_cleanup(
          (hkpGskManifold *)(gskCache + 12),
          v5->m_contactMgr.m_storage,
          processOut->m_constraintOwner.m_storage);
        entrya->m_numContactPoints = gskCache[14];
        goto LABEL_14;
      }
LABEL_13:
      out = processOut;
      goto LABEL_14;
    }
    LODWORD(retaddr) = 1036831949;
    if ( v27 <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0)) )
      goto LABEL_13;
    out = processOut;
    if ( result.m_real.m128_f32[0] < 0.0 )
    {
      *(_DWORD *)((char *)&v112 + v19) = 0;
      gskCache[11] &= ~(4 << v18);
      hkGskManifold_cleanup(
        (hkpGskManifold *)(gskCache + 12),
        v5->m_contactMgr.m_storage,
        processOut->m_constraintOwner.m_storage);
      entrya->m_numContactPoints = gskCache[14];
    }
LABEL_14:
    allowedPenetrationDepth.m_real.m128_u64[0] += 8i64;
    ++v18;
    v19 += 4i64;
    if ( v18 >= 2 )
      break;
    v17 = (__m128 ****)allowedPenetrationDepth.m_real.m128_u64[0];
  }
  v29 = v5->m_input.m_storage;
  v30 = 0;
  v31 = (unsigned int *)v29->m_collisionQualityInfo.m_storage;
  explicitlyAllowNewPoint = 0;
  if ( v31[4] )
  {
    v32 = v5->m_bodyA.m_storage;
    for ( i = v5->m_bodyA.m_storage->m_parent; i; i = i->m_parent )
      v32 = i;
    v34 = (__m128)v32[3].m_shapeKey;
    v35 = v5->m_bodyB.m_storage;
    v36 = _mm_shuffle_ps(v34, v34, 0);
    for ( j = v35->m_parent; j; j = j->m_parent )
      v35 = j;
    v38 = &v124->m_quad;
    v39 = _mm_min_ps(v36, _mm_shuffle_ps((__m128)v35[3].m_shapeKey, (__m128)v35[3].m_shapeKey, 0));
    v40 = _mm_shuffle_ps((__m128)v31[6], (__m128)v31[6], 0);
    v41 = _mm_mul_ps(_mm_shuffle_ps((__m128)v31[7], (__m128)v31[7], 0), v39);
    v42 = _mm_shuffle_ps(v124->m_quad, v124->m_quad, 255);
    allowedPenetrationDepth.m_real = v39;
    minSeparation.m_real = _mm_min_ps(_mm_mul_ps(v40, v39), _mm_add_ps(v41, v42));
    if ( v15.m128_f32[0] < minSeparation.m_real.m128_f32[0] )
    {
      result.m_real = _mm_min_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v31[10], (__m128)v31[10], 0), v39),
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v31[11], (__m128)v31[11], 0), v39), v42));
      hk4dGskCollideCalcToi(v5, &allowedPenetrationDepth, &minSeparation, &result, (hkpGskCache *)gskCache, v124, out);
      v30 = 0;
      goto LABEL_22;
    }
  }
  else
  {
    v38 = &v124->m_quad;
  }
  if ( v15.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)v31[3], (__m128)v31[3], 0))
    || gskCache[11] & 0x10
    || COERCE_FLOAT(_mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 255)) >= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v29->m_tolerance.m_storage), (__m128)LODWORD(v29->m_tolerance.m_storage), 0)) )
  {
LABEL_22:
    if ( COERCE_FLOAT(_mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 255)) >= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v5->m_input.m_storage->m_tolerance.m_storage), (__m128)LODWORD(v5->m_input.m_storage->m_tolerance.m_storage), 0)) )
    {
      if ( gskCache[14] )
        hkGskManifold_cleanup(
          (hkpGskManifold *)(gskCache + 12),
          v5->m_contactMgr.m_storage,
          out->m_constraintOwner.m_storage);
    }
    else
    {
      if ( !v30 )
      {
        v43 = &v112;
        v44 = &v118;
        v45 = 2i64;
        v46 = &v119;
        v47 = 0i64;
        minSeparation.m_real.m128_u64[0] = (unsigned __int64)&v112;
        retaddr = &v118;
        allowedPenetrationDepth.m_real.m128_u64[0] = 2i64;
        do
        {
          if ( *(_DWORD *)v43 )
          {
            v48 = *(hkpCylinderShape ****)((char *)&v115 + v47 * 8);
            v49 = **v48;
            v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            minSeparation.m_real.m128_u64[1] = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v50[11] + 8i64))(
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
              v97 = (*v48)[2];
              *((_QWORD *)v46 + 1) = *v48;
              *(_QWORD *)v46 = v97;
            }
            v44 = retaddr;
            *((_QWORD *)v46 - 2) = v53;
            v45 = allowedPenetrationDepth.m_real.m128_u64[0];
            *((_DWORD *)v46 - 2) = -1;
            v98 = *v48;
            *v48 = (hkpCylinderShape **)retaddr;
            allowedPenetrationDepth.m_real.m128_u64[v47] = (unsigned __int64)v98;
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
        v5 = v121;
        out = processOut;
      }
      v99 = (hkpGskCache *)gskCache;
      if ( v112 )
      {
        v99 = (hkpGskCache *)&result;
        result.m_real.m128_u64[0] = *(_QWORD *)gskCache;
        result.m_real.m128_i32[2] = *((_DWORD *)gskCache + 2);
        if ( (_DWORD)v112 )
        {
          v100 = result.m_real.m128_i8[8];
          result.m_real.m128_i16[0] = 16 * (1 - (((unsigned __int16)result.m_real.m128_i16[0] >> 7) & 1));
          if ( result.m_real.m128_i8[8] > 1u )
          {
            result.m_real.m128_i32[0] = 16;
            if ( result.m_real.m128_i8[8] == 3 )
            {
              v100 = 2;
              result.m_real.m128_i16[2] = result.m_real.m128_i16[3];
              result.m_real.m128_i8[8] = 2;
            }
          }
        }
        else
        {
          v100 = result.m_real.m128_i8[8];
        }
        if ( HIDWORD(v112) )
        {
          result.m_real.m128_i16[v100] = 16 * (1 - (((unsigned __int16)result.m_real.m128_i16[v100] >> 7) & 1));
          if ( result.m_real.m128_i8[9] > 1u )
          {
            result.m_real.m128_i16[(unsigned __int8)result.m_real.m128_i8[8]] = 16;
            result.m_real.m128_i16[(unsigned __int8)result.m_real.m128_i8[8] + 1] = 0;
            v101 = result.m_real.m128_i8[9];
            if ( result.m_real.m128_i8[9] == 3 )
              v101 = 2;
            result.m_real.m128_i8[9] = v101;
          }
        }
      }
      hkGskAgentUtil_processCollisionNoTim(
        (hkpAgent3Input *)&v5->m_bodyA,
        entrya,
        gskCache,
        v99,
        (hkpGskManifold *)(gskCache + 12),
        v124,
        explicitlyAllowNewPoint,
        out);
    }
    *v124 = (hkVector4f)separatingNormalOut.m_quad;
  }
  else
  {
    *v38 = _mm_shuffle_ps(*v38, _mm_unpackhi_ps(*v38, v15), 196);
    if ( gskCache[14] )
    {
      v54 = &v112;
      v55 = &v118;
      v56 = 2i64;
      v57 = &v119;
      v58 = 0i64;
      minSeparation.m_real.m128_u64[0] = (unsigned __int64)&v112;
      retaddr = &v118;
      allowedPenetrationDepth.m_real.m128_u64[0] = 2i64;
      do
      {
        if ( *(_DWORD *)v54 )
        {
          v59 = *(hkpCylinderShape ****)((char *)&v115 + v58 * 8);
          v60 = **v59;
          v61 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          minSeparation.m_real.m128_u64[1] = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v61[11] + 8i64))(
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
      v5 = v121;
      LOBYTE(retaddr) = 1;
      v67 = v116->m_storage;
      v68 = v121->m_bodyA.m_storage;
      work.m_keepContact.m_storage = v121->m_input.m_storage->m_tolerance.m_storage;
      v69 = v68->m_shape;
      v70 = (float *)v67->m_shape;
      v71 = *(float *)&v68->m_shape[1].vfptr;
      work.m_radiusA.m_storage = v71;
      v72 = (float)(v71 + work.m_keepContact.m_storage) + v70[8];
      work.m_radiusB.m_storage = v70[8];
      v73 = gskCache[14];
      work.m_masterNormal = (hkVector4f)v124->m_quad;
      work.m_radiusSumSqrd.m_storage = v72 * v72;
      if ( v73 )
      {
        v74 = *v16;
        v75 = (signed __int64)&gskCache[8 * v73 + 16];
        v76 = v69->vfptr;
        minSeparation.m_real.m128_u64[0] = v75;
        ((void (__fastcall *)(hkpShape *, signed __int64, __int64, hkpGskManifoldWork *))v76[4].__first_virtual_table_function__)(
          v69,
          v75,
          v74,
          &work);
        v77 = (__m128 *)v68->m_motion;
        v78 = *v16;
        v79 = *v77;
        v80 = v77[1];
        v81 = v77[2];
        v82 = v77[3];
        v83 = (signed int)v78 - 1;
        v84 = &work.m_vertices[v83];
        do
        {
          v85 = v84->m_quad;
          --v84;
          --v83;
          v84[1].m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v85, v85, 85), v80),
                                _mm_mul_ps(_mm_shuffle_ps(v85, v85, 0), v79)),
                              _mm_mul_ps(_mm_shuffle_ps(v85, v85, 170), v81)),
                            v82);
        }
        while ( v83 >= 0 );
        v86 = &work.m_vertices[v78];
        (*(void (__fastcall **)(float *, unsigned __int64, _QWORD, hkcdVertex *))(*(_QWORD *)v70 + 72i64))(
          v70,
          minSeparation.m_real.m128_u64[0] + 2 * v78,
          (unsigned __int8)gskCache[13],
          v86);
        v87 = (__m128 *)v67->m_motion;
        v88 = *v87;
        v89 = v87[1];
        v90 = v87[2];
        v91 = v87[3];
        v92 = (unsigned __int8)gskCache[13] - 1;
        v93 = (signed __int64)&v86[v92];
        do
        {
          v94 = *(__m128 *)v93;
          v93 -= 16i64;
          --v92;
          *(__m128 *)(v93 + 16) = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v94, v94, 85), v89),
                                        _mm_mul_ps(_mm_shuffle_ps(v94, v94, 0), v88)),
                                      _mm_mul_ps(_mm_shuffle_ps(v94, v94, 170), v90)),
                                    v91);
        }
        while ( v92 >= 0 );
      }
      out = processOut;
      explicitlyAllowNewPoint = hkGskManifold_verifyAndGetPoints(
                                  (hkpGskManifold *)(gskCache + 12),
                                  &work,
                                  0,
                                  processOut,
                                  v5->m_contactMgr.m_storage);
      if ( explicitlyAllowNewPoint && gskCache[11] < 0 )
      {
        v30 = (char)retaddr;
        processOut->m_firstFreeContactPoint.m_storage -= (unsigned __int8)gskCache[14];
        goto LABEL_22;
      }
      v95 = gskCache[14];
      if ( v95 )
      {
        v96 = processOut->m_potentialContacts.m_storage;
        if ( v96 )
        {
          *v96->m_firstFreeRepresentativeContact = &processOut->m_firstFreeContactPoint.m_storage[-v95];
          ++v96->m_firstFreeRepresentativeContact;
        }
      }
    }
  }
  do
  {
    v102 = allowedPenetrationDepth.m_real.m128_u64[v14];
    if ( v102 )
    {
      v103 = *(hkReferencedObject ****)((char *)&v115 + v14 * 8);
      hkReferencedObject::removeReference(**v103);
      *v103 = (hkReferencedObject **)v102;
    }
    ++v14;
  }
  while ( v14 < 2 );
  entrya->m_numContactPoints = gskCache[14];
  v104 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v105 = (_QWORD *)v104[1];
  v106 = v104;
  if ( (unsigned __int64)v105 < v104[3] )
  {
    *v105 = "Et";
    v107 = __rdtsc();
    v108 = (signed __int64)(v105 + 2);
    *(_DWORD *)(v108 - 8) = v107;
    v106[1] = v108;
  }
  return (unsigned __int64)&gskCache[(2
                                    * ((unsigned __int8)gskCache[12]
                                     + (unsigned __int8)gskCache[13]
                                     + 4 * (unsigned __int8)gskCache[14])
                                    + 4
                                    + 27i64) & 0xFFFFFFFFFFFFFFF0ui64];
}

