// File Line: 22
// RVA: 0xD22AE0
void __fastcall hkpCapsuleTriangleAgent::initAgentFunc(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpCapsuleTriangleAgent::createCapsuleTriangleAgent;
  af->m_getPenetrationsFunc = hkpCapsuleTriangleAgent::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpCapsuleTriangleAgent::staticGetClosestPoints;
  af->m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 0;
}

// File Line: 33
// RVA: 0xD22B20
void __fastcall hkpCapsuleTriangleAgent::initAgentFuncInverse(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpCapsuleTriangleAgent::createTriangleCapsuleAgent;
  af->m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticGetClosestPoints;
  af->m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 1;
}

// File Line: 63
// RVA: 0xD22B60
void __fastcall hkpCapsuleTriangleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRIANGLE, CAPSULE);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CAPSULE, TRIANGLE);
}

// File Line: 78
// RVA: 0xD22BD0
void __fastcall hkpCapsuleTriangleAgent::registerAgent2(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(dispatcher, &f, TRIANGLE, CAPSULE);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(dispatcher, &f, CAPSULE, TRIANGLE);
}

// File Line: 110
// RVA: 0xD23800
hkpCollisionAgent *__fastcall hkpCapsuleTriangleAgent::createTriangleCapsuleAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = mgr;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleTriangleAgent::`vftable;
    WORD2(result[1].vfptr) = -1;
    LODWORD(result[1].vfptr) = -1;
    hkpCollideTriangleUtil::setupPointTriangleDistanceCache(
      (hkVector4f *)&bodyA->m_shape[1].m_type,
      (hkpCollideTriangleUtil::PointTriangleDistanceCache *)&result[1].m_memSizeAndFlags);
    v8->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::`vftable;
    return v8;
  }
  return result;
}

// File Line: 119
// RVA: 0xD23760
hkpCollisionAgent *__fastcall hkpCapsuleTriangleAgent::createCapsuleTriangleAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = mgr;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleTriangleAgent::`vftable;
    WORD2(result[1].vfptr) = -1;
    LODWORD(result[1].vfptr) = -1;
    hkpCollideTriangleUtil::setupPointTriangleDistanceCache(
      (hkVector4f *)&bodyB->m_shape[1].m_type,
      (hkpCollideTriangleUtil::PointTriangleDistanceCache *)&result[1].m_memSizeAndFlags);
    return v8;
  }
  return result;
}

// File Line: 128
// RVA: 0xD236E0
void __fastcall hkpCapsuleTriangleAgent::cleanup(hkpCapsuleTriangleAgent *this, hkpConstraintOwner *constraintOwner)
{
  unsigned __int16 *m_contactPointId; // rbx
  __int64 v5; // rdi
  __int64 v6; // rdx

  m_contactPointId = this->m_contactPointId;
  v5 = 3i64;
  do
  {
    v6 = *m_contactPointId;
    if ( (_WORD)v6 != 0xFFFF )
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
        this->m_contactMgr,
        v6,
        constraintOwner);
    ++m_contactPointId;
    --v5;
  }
  while ( v5 );
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 161
// RVA: 0xD238B0
void __fastcall hkpCapsuleTriangleAgent::getClosestPointsPublic(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCollideTriangleUtil::PointTriangleDistanceCache *cache,
        int searchManifold,
        hkContactPoint *points)
{
  hkpShape *m_shape; // rbx
  hkpShape *v7; // r10
  __m128 *m_motion; // rax
  __int64 v9; // rcx
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 *v14; // rax
  __m128 v15; // xmm1
  __m128 *v16; // rax
  __int64 v17; // rcx
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm7
  __m128 *p_m_type; // rax
  __m128 v23; // xmm1
  hkVector4f capsAPoints; // [rsp+50h] [rbp-78h] BYREF
  char v25[16]; // [rsp+60h] [rbp-68h] BYREF
  hkVector4f triVertices; // [rsp+70h] [rbp-58h] BYREF
  char v27[16]; // [rsp+90h] [rbp-38h] BYREF

  m_shape = bodyA->m_shape;
  v7 = bodyB->m_shape;
  m_motion = (__m128 *)bodyA->m_motion;
  v9 = 1i64;
  v10 = *m_motion;
  v11 = m_motion[1];
  v12 = m_motion[2];
  v13 = m_motion[3];
  v14 = (__m128 *)&m_shape[2];
  do
  {
    v15 = *v14--;
    --v9;
    *(__m128 *)((char *)v14 + v25 - (char *)m_shape - 48) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v11),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v10)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v12)),
                                                              v13);
  }
  while ( v9 >= 0 );
  v16 = (__m128 *)bodyB->m_motion;
  v17 = 2i64;
  v18 = *v16;
  v19 = v16[1];
  v20 = v16[2];
  v21 = v16[3];
  p_m_type = (__m128 *)&v7[2].m_type;
  do
  {
    v23 = *p_m_type--;
    --v17;
    *(__m128 *)((char *)p_m_type + v27 - (char *)v7 - 64) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v18),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v19)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v20)),
                                                              v21);
  }
  while ( v17 >= 0 );
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v7[1].vfptr,
    cache,
    input->m_tolerance.m_storage,
    searchManifold,
    points,
    0i64);
}

// File Line: 244
// RVA: 0xD239F0
__int64 __fastcall hkpCapsuleTriangleAgent::getClosestPoint(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCollideTriangleUtil::PointTriangleDistanceCache *cache,
        hkContactPoint *cpoint)
{
  hkpShape *m_shape; // r13
  hkpShape *v6; // rsi
  __m128 m_quad; // xmm7
  __m128 *m_motion; // rax
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  signed __int64 v15; // rdx
  __int64 v16; // rcx
  __m128 v17; // xmm6
  __m128 v18; // xmm8
  __m128 *v19; // rax
  __m128 v20; // xmm1
  __m128 *v21; // rax
  __int64 v22; // rcx
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __m128 *p_m_type; // rax
  __m128 v28; // xmm1
  unsigned int v29; // edi
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  int v35; // ecx
  __int64 v36; // rdx
  char numFeatures; // al
  __int64 v38; // rbx
  const void *v39; // rcx
  const void *v40; // rax
  hkVector4f v41; // xmm1
  hkBaseObjectVtbl *vfptr; // r10
  int v43; // eax
  hkContactPoint *v44; // rcx
  __int64 result; // rax
  hkVector4f v46; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f capsAPoints; // [rsp+60h] [rbp-A0h] BYREF
  char v48; // [rsp+70h] [rbp-90h] BYREF
  hkpFeatureOutput featuresOut[4]; // [rsp+80h] [rbp-80h] BYREF
  hkContactPoint points; // [rsp+A0h] [rbp-60h] BYREF
  __m128 v51; // [rsp+D0h] [rbp-30h]
  hkVector4f triVertices; // [rsp+100h] [rbp+0h] BYREF
  char v53[64]; // [rsp+120h] [rbp+20h] BYREF
  char v54; // [rsp+190h] [rbp+90h] BYREF

  m_shape = bodyA->m_shape;
  v6 = bodyB->m_shape;
  m_quad = aabbOut.m_quad;
  m_motion = (__m128 *)bodyA->m_motion;
  v12 = *m_motion;
  v13 = m_motion[1];
  v14 = m_motion[2];
  v15 = &v48 - (char *)bodyA->m_shape;
  v16 = 1i64;
  v17 = m_motion[3];
  v18 = aabbOut.m_quad;
  v19 = (__m128 *)&m_shape[2];
  do
  {
    v20 = *v19--;
    --v16;
    *(__m128 *)((char *)v19 + v15 - 48) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v13),
                                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v12)),
                                              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v14)),
                                            v17);
  }
  while ( v16 >= 0 );
  v21 = (__m128 *)bodyB->m_motion;
  v22 = 2i64;
  v23 = *v21;
  v24 = v21[1];
  v25 = v21[2];
  v26 = v21[3];
  p_m_type = (__m128 *)&v6[2].m_type;
  do
  {
    v28 = *p_m_type--;
    --v22;
    *(__m128 *)((char *)p_m_type + v53 - (char *)v6 - 64) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), v24),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v23)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v25)),
                                                              v26);
  }
  while ( v22 >= 0 );
  v29 = 0;
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v6[1].vfptr,
    cache,
    input->m_tolerance.m_storage,
    0,
    &points,
    featuresOut);
  v30 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0);
  v31 = _mm_shuffle_ps(v51, v51, 255);
  v32 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255);
  v33 = _mm_cmplt_ps(v32, v30);
  v34 = _mm_cmplt_ps(v32, v31);
  if ( _mm_movemask_ps(_mm_and_ps(v33, v34)) )
  {
    v35 = 0;
  }
  else
  {
    v35 = -1;
    if ( _mm_movemask_ps(_mm_andnot_ps(v34, _mm_cmplt_ps(v31, v30))) )
      v35 = 1;
    if ( v35 == -1 )
      goto LABEL_17;
  }
  v36 = v35;
  numFeatures = featuresOut[v35].numFeatures;
  v38 = 32i64 * v35;
  v54 = numFeatures;
  if ( !input->m_weldClosestPoints.m_storage || !numFeatures )
  {
LABEL_16:
    m_quad = *(__m128 *)((char *)&points.m_position.m_quad + v38);
    v18 = *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v38);
    v29 = 1;
    goto LABEL_17;
  }
  v39 = bodyB->m_motion;
  v40 = bodyA->m_motion;
  v41.m_quad = *(__m128 *)((char *)&points.m_position + v38);
  vfptr = v6->vfptr;
  capsAPoints.m_quad = *(__m128 *)((char *)&points.m_separatingNormal + v38);
  v46.m_quad = v41.m_quad;
  v43 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, hkVector4f *, const void *, hkpShape *, const void *, hkVector4f *))vfptr[6].__first_virtual_table_function__)(
          v6,
          featuresOut[v36].featureIds,
          &v54,
          &v46,
          v39,
          m_shape,
          v40,
          &capsAPoints);
  *(hkVector4f *)((char *)&points.m_position + v38) = (hkVector4f)v46.m_quad;
  if ( input->m_forceAcceptContactPoints.m_storage || v43 )
  {
    if ( v43 == 1 )
      *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v38) = _mm_shuffle_ps(
                                                                       capsAPoints.m_quad,
                                                                       _mm_unpackhi_ps(
                                                                         capsAPoints.m_quad,
                                                                         *(__m128 *)((char *)&points.m_separatingNormal.m_quad
                                                                                   + v38)),
                                                                       196);
    goto LABEL_16;
  }
LABEL_17:
  v44 = cpoint;
  result = v29;
  cpoint->m_position.m_quad = m_quad;
  v44->m_separatingNormal.m_quad = v18;
  return result;
}

// File Line: 259
// RVA: 0xD23E40
void __fastcall hkpCapsuleTriangleAgent::processCollision(
        hkpCapsuleTriangleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r9
  hkpShape *v15; // r8
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  hkpShape *v20; // rax
  __int64 i; // rcx
  __m128 v22; // xmm1
  __m128 *v23; // rax
  __int64 v24; // rcx
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 *p_m_type; // rax
  __m128 v30; // xmm1
  hkpProcessCollisionInput *v31; // rdx
  hkpProcessCollisionOutput *v32; // rsi
  hkVector4f *p_m_separatingNormal; // rdi
  hkpFeatureOutput *p_featuresOut; // r14
  float v35; // xmm6_4
  unsigned __int16 *m_contactPointId; // rbx
  hkContactPoint *p_points; // rbp
  unsigned __int16 *featureIds; // r15
  __int64 v39; // r12
  __int128 v40; // xmm1
  int v41; // eax
  __int64 v42; // rdx
  unsigned __int16 v43; // ax
  hkpProcessCdPoint *m_storage; // rcx
  hkVector4f v45; // xmm0
  _QWORD *v46; // r8
  _QWORD *v47; // rcx
  unsigned __int64 v48; // rax
  _QWORD *v49; // rcx
  hkpShape *v50; // [rsp+50h] [rbp-148h]
  hkpShape *v51; // [rsp+58h] [rbp-140h]
  __int128 v52; // [rsp+60h] [rbp-138h] BYREF
  hkVector4f capsAPoints; // [rsp+70h] [rbp-128h] BYREF
  char v54[16]; // [rsp+80h] [rbp-118h] BYREF
  hkpFeatureOutput featuresOut; // [rsp+90h] [rbp-108h] BYREF
  hkVector4f triVertices; // [rsp+B0h] [rbp-E8h] BYREF
  char v57[16]; // [rsp+D0h] [rbp-C8h] BYREF
  hkContactPoint points; // [rsp+E0h] [rbp-B8h] BYREF
  char numFeatures; // [rsp+1A0h] [rbp+8h] BYREF
  hkpCdBody *v60; // [rsp+1A8h] [rbp+10h]
  hkpCdBody *v61; // [rsp+1B0h] [rbp+18h]
  hkpProcessCollisionInput *v62; // [rsp+1B8h] [rbp+20h]

  v62 = input;
  v61 = bodyB;
  v60 = bodyA;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtCapsuleTri";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v15 = bodyB->m_shape;
  v16 = *m_motion;
  v17 = m_motion[1];
  v18 = m_motion[2];
  v50 = bodyA->m_shape;
  v51 = bodyB->m_shape;
  v19 = m_motion[3];
  v20 = bodyA->m_shape + 2;
  for ( i = 1i64; i >= 0; --i )
  {
    v22 = (__m128)v20->hkReferencedObject;
    v20 = (hkpShape *)((char *)v20 - 16);
    *(__m128 *)((char *)&v20[-1] + v54 - (char *)m_shape - 16) = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_add_ps(
                                                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v17),
                                                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v16)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v18)),
                                                                   v19);
  }
  v23 = (__m128 *)bodyB->m_motion;
  v24 = 2i64;
  v25 = *v23;
  v26 = v23[1];
  v27 = v23[2];
  v28 = v23[3];
  p_m_type = (__m128 *)&v15[2].m_type;
  do
  {
    v30 = *p_m_type--;
    --v24;
    *(__m128 *)((char *)p_m_type + v57 - (char *)v15 - 64) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v26),
                                                                   _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v25)),
                                                                 _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v27)),
                                                               v28);
  }
  while ( v24 >= 0 );
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v15[1].vfptr,
    &this->m_triangleCache,
    input->m_tolerance.m_storage,
    1,
    &points,
    &featuresOut);
  v31 = v62;
  v32 = result;
  p_m_separatingNormal = &points.m_separatingNormal;
  p_featuresOut = &featuresOut;
  LODWORD(v35) = _mm_shuffle_ps(
                   (__m128)LODWORD(v62->m_tolerance.m_storage),
                   (__m128)LODWORD(v62->m_tolerance.m_storage),
                   0).m128_u32[0];
  m_contactPointId = this->m_contactPointId;
  p_points = &points;
  featureIds = featuresOut.featureIds;
  v39 = 3i64;
  do
  {
    if ( _mm_shuffle_ps(p_m_separatingNormal->m_quad, p_m_separatingNormal->m_quad, 255).m128_f32[0] >= v35 )
    {
      v42 = *m_contactPointId;
      if ( (_WORD)v42 == 0xFFFF )
        goto LABEL_20;
      goto LABEL_19;
    }
    numFeatures = p_featuresOut->numFeatures;
    if ( numFeatures )
    {
      v40 = (__int128)p_m_separatingNormal[-1];
      capsAPoints.m_quad = p_m_separatingNormal->m_quad;
      v52 = v40;
      v41 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, __int128 *, const void *, hkpShape *, const void *, hkVector4f *))v51->vfptr[6].__first_virtual_table_function__)(
              v51,
              featureIds,
              &numFeatures,
              &v52,
              v61->m_motion,
              v50,
              v60->m_motion,
              &capsAPoints);
      p_m_separatingNormal[-1] = (hkVector4f)v52;
      if ( !v41 )
      {
        v42 = *m_contactPointId;
        if ( (_WORD)v42 == 0xFFFF )
          goto LABEL_20;
LABEL_19:
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
          this->m_contactMgr,
          v42,
          v32->m_constraintOwner.m_storage);
        *m_contactPointId = -1;
        goto LABEL_20;
      }
      v31 = v62;
      if ( v41 == 1 )
        p_m_separatingNormal->m_quad = _mm_shuffle_ps(
                                         capsAPoints.m_quad,
                                         _mm_unpackhi_ps(capsAPoints.m_quad, p_m_separatingNormal->m_quad),
                                         196);
    }
    if ( *m_contactPointId != 0xFFFF
      || (v43 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkContactPoint *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                  this->m_contactMgr,
                  v60,
                  v61,
                  v31,
                  v32,
                  0i64,
                  p_points),
          *m_contactPointId = v43,
          v43 != 0xFFFF) )
    {
      m_storage = v32->m_firstFreeContactPoint.m_storage;
      v45.m_quad = (__m128)p_m_separatingNormal[-1];
      ++v32->m_firstFreeContactPoint.m_storage;
      m_storage->m_contact.m_position = (hkVector4f)v45.m_quad;
      m_storage->m_contact.m_separatingNormal = (hkVector4f)p_m_separatingNormal->m_quad;
      m_storage->m_contactPointId = *m_contactPointId;
    }
LABEL_20:
    v31 = v62;
    featureIds += 4;
    ++p_points;
    ++m_contactPointId;
    ++p_featuresOut;
    p_m_separatingNormal += 2;
    --v39;
  }
  while ( v39 );
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "Et";
    v48 = __rdtsc();
    v49 = v47 + 2;
    *((_DWORD *)v49 - 2) = v48;
    v46[1] = v49;
  }
}

// File Line: 333
// RVA: 0xD22C40
void __fastcall hkpCapsuleTriangleAgent::getClosestPoints(
        hkpCapsuleTriangleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r13
  hkpShape *v14; // rdi
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __int64 v18; // rcx
  __m128 v19; // xmm6
  __m128 *v20; // rax
  __m128 v21; // xmm1
  __m128 *v22; // rax
  __int64 v23; // rcx
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 *p_m_type; // rax
  __m128 v29; // xmm1
  hkpCollideTriangleUtil::PointTriangleDistanceCache *cache; // rax
  int v31; // ebx
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __int64 v37; // rdx
  char numFeatures; // al
  unsigned __int64 v39; // rbx
  bool v40; // zf
  __int128 v41; // xmm6
  const void *v42; // rcx
  const void *v43; // rax
  __int128 v44; // xmm1
  hkBaseObjectVtbl *vfptr; // r10
  int v46; // eax
  __int128 v47; // xmm1
  __int64 v48; // rax
  _QWORD *v49; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  _QWORD *v52; // rcx
  _BYTE v53[40]; // [rsp+50h] [rbp-88h] BYREF
  __int64 v54; // [rsp+78h] [rbp-60h]
  hkpCdBody *v55; // [rsp+80h] [rbp-58h]
  hkpFeatureOutput featuresOut[4]; // [rsp+88h] [rbp-50h] BYREF
  hkContactPoint points; // [rsp+A8h] [rbp-30h] BYREF
  __m128 v58; // [rsp+D8h] [rbp+0h]
  hkVector4f capsAPoints; // [rsp+108h] [rbp+30h] BYREF
  char v60[16]; // [rsp+118h] [rbp+40h] BYREF
  hkVector4f triVertices; // [rsp+128h] [rbp+50h] BYREF
  char v62[72]; // [rsp+148h] [rbp+70h] BYREF
  char v63[24]; // [rsp+198h] [rbp+C0h] BYREF
  __int64 *retaddr; // [rsp+1B8h] [rbp+E0h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtCapsTriangle";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v14 = bodyB->m_shape;
  v55 = bodyB;
  v54 = 0i64;
  *(hkVector4f *)&v53[8] = (hkVector4f)aabbOut.m_quad;
  *(hkVector4f *)&v53[24] = (hkVector4f)aabbOut.m_quad;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = 1i64;
  v19 = m_motion[3];
  v20 = (__m128 *)&m_shape[2];
  do
  {
    v21 = *v20--;
    --v18;
    *(__m128 *)((char *)v20 + v60 - (char *)m_shape - 48) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v16),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v15)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v17)),
                                                              v19);
  }
  while ( v18 >= 0 );
  v22 = (__m128 *)bodyB->m_motion;
  v23 = 2i64;
  v24 = *v22;
  v25 = v22[1];
  v26 = v22[2];
  v27 = v22[3];
  p_m_type = (__m128 *)&v14[2].m_type;
  do
  {
    v29 = *p_m_type--;
    --v23;
    *(__m128 *)((char *)p_m_type + v62 - (char *)v14 - 64) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v25),
                                                                   _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v24)),
                                                                 _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v26)),
                                                               v27);
  }
  while ( v23 >= 0 );
  cache = &this->m_triangleCache;
  v31 = 0;
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v14[1].vfptr,
    cache,
    input->m_tolerance.m_storage,
    0,
    &points,
    featuresOut);
  v32 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0);
  v33 = _mm_shuffle_ps(v58, v58, 255);
  v34 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255);
  v35 = _mm_cmplt_ps(v34, v32);
  v36 = _mm_cmplt_ps(v34, v33);
  if ( _mm_movemask_ps(_mm_and_ps(v35, v36)) )
    goto LABEL_11;
  v31 = -1;
  if ( _mm_movemask_ps(_mm_andnot_ps(v36, _mm_cmplt_ps(v33, v32))) )
    v31 = 1;
  if ( v31 != -1 )
  {
LABEL_11:
    v37 = v31;
    numFeatures = featuresOut[v31].numFeatures;
    v39 = 32i64 * v31;
    v40 = input->m_weldClosestPoints.m_storage == 0;
    v41 = *(__int128 *)((char *)&points.m_separatingNormal + v39);
    v63[0] = featuresOut[v37].numFeatures;
    if ( !v40 && numFeatures )
    {
      v42 = bodyB->m_motion;
      v43 = bodyA->m_motion;
      v44 = *(__int128 *)((char *)&points.m_position + v39);
      vfptr = v14->vfptr;
      *(_OWORD *)v53 = v41;
      *(_OWORD *)&v53[16] = v44;
      v46 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, _BYTE *, const void *, hkpShape *, const void *, _BYTE *))vfptr[6].__first_virtual_table_function__)(
              v14,
              featuresOut[v37].featureIds,
              v63,
              &v53[16],
              v42,
              m_shape,
              v43,
              v53);
      v40 = input->m_forceAcceptContactPoints.m_storage == 0;
      *(hkVector4f *)((char *)&points.m_position + v39) = *(hkVector4f *)&v53[16];
      if ( v40 && !v46 )
        goto LABEL_18;
      if ( v46 == 1 )
        *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v39) = _mm_shuffle_ps(
                                                                         *(__m128 *)v53,
                                                                         _mm_unpackhi_ps(
                                                                           *(__m128 *)v53,
                                                                           *(__m128 *)((char *)&points.m_separatingNormal.m_quad
                                                                                     + v39)),
                                                                         196);
    }
    v47 = *(__int128 *)((char *)&points.m_separatingNormal + v39);
    v48 = *retaddr;
    v54 = points.m_position.m_quad.m128_i64[v39 / 8 + 1];
    *(_OWORD *)&v53[8] = v47;
    *(_OWORD *)&v53[24] = v41;
    (*(void (__fastcall **)(__int64 *, _BYTE *))(v48 + 8))(retaddr, &v53[32]);
  }
LABEL_18:
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "Et";
    v51 = __rdtsc();
    v52 = v50 + 2;
    *((_DWORD *)v52 - 2) = v51;
    v49[1] = v52;
  }
}

// File Line: 351
// RVA: 0xD22F70
void __fastcall hkpCapsuleTriangleAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r13
  hkpShape *v14; // rdi
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __int64 v18; // rcx
  __m128 v19; // xmm6
  __m128 *v20; // rax
  __m128 v21; // xmm1
  __m128 *v22; // rax
  __int64 v23; // rcx
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 *p_m_type; // rax
  __m128 v29; // xmm1
  int v30; // ebx
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __int64 v36; // rdx
  char numFeatures; // al
  unsigned __int64 v38; // rbx
  bool v39; // zf
  __int128 v40; // xmm6
  const void *v41; // rcx
  const void *v42; // rax
  __int128 v43; // xmm1
  hkBaseObjectVtbl *vfptr; // r10
  int v45; // eax
  __int128 v46; // xmm1
  hkpCdPointCollectorVtbl *v47; // rax
  _QWORD *v48; // r8
  _QWORD *v49; // rcx
  unsigned __int64 v50; // rax
  _QWORD *v51; // rcx
  _BYTE v52[40]; // [rsp+50h] [rbp-88h] BYREF
  hkpCdBody *v53; // [rsp+78h] [rbp-60h]
  hkpCdBody *v54; // [rsp+80h] [rbp-58h]
  hkpFeatureOutput featuresOut[4]; // [rsp+88h] [rbp-50h] BYREF
  hkContactPoint points; // [rsp+A8h] [rbp-30h] BYREF
  __m128 v57; // [rsp+D8h] [rbp+0h]
  hkpCollideTriangleUtil::PointTriangleDistanceCache cache; // [rsp+108h] [rbp+30h] BYREF
  hkVector4f capsAPoints; // [rsp+128h] [rbp+50h] BYREF
  char v60[16]; // [rsp+138h] [rbp+60h] BYREF
  hkVector4f triVertices; // [rsp+148h] [rbp+70h] BYREF
  char v62[72]; // [rsp+168h] [rbp+90h] BYREF
  char v63[24]; // [rsp+1B8h] [rbp+E0h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtCapsTriangle";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  hkpCollideTriangleUtil::setupPointTriangleDistanceCache((hkVector4f *)&bodyB->m_shape[1].m_type, &cache);
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v53 = 0i64;
  *(hkVector4f *)&v52[8] = (hkVector4f)aabbOut.m_quad;
  *(hkVector4f *)&v52[24] = (hkVector4f)aabbOut.m_quad;
  v14 = bodyB->m_shape;
  v53 = bodyA;
  v54 = bodyB;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = 1i64;
  v19 = m_motion[3];
  v20 = (__m128 *)&m_shape[2];
  do
  {
    v21 = *v20--;
    --v18;
    *(__m128 *)((char *)v20 + v60 - (char *)m_shape - 48) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v16),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v15)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v17)),
                                                              v19);
  }
  while ( v18 >= 0 );
  v22 = (__m128 *)bodyB->m_motion;
  v23 = 2i64;
  v24 = *v22;
  v25 = v22[1];
  v26 = v22[2];
  v27 = v22[3];
  p_m_type = (__m128 *)&v14[2].m_type;
  do
  {
    v29 = *p_m_type--;
    --v23;
    *(__m128 *)((char *)p_m_type + v62 - (char *)v14 - 64) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v25),
                                                                   _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v24)),
                                                                 _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v26)),
                                                               v27);
  }
  while ( v23 >= 0 );
  v30 = 0;
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v14[1].vfptr,
    &cache,
    input->m_tolerance.m_storage,
    0,
    &points,
    featuresOut);
  v31 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0);
  v32 = _mm_shuffle_ps(v57, v57, 255);
  v33 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255);
  v34 = _mm_cmplt_ps(v33, v31);
  v35 = _mm_cmplt_ps(v33, v32);
  if ( _mm_movemask_ps(_mm_and_ps(v34, v35)) )
    goto LABEL_11;
  v30 = -1;
  if ( _mm_movemask_ps(_mm_andnot_ps(v35, _mm_cmplt_ps(v32, v31))) )
    v30 = 1;
  if ( v30 != -1 )
  {
LABEL_11:
    v36 = v30;
    numFeatures = featuresOut[v30].numFeatures;
    v38 = 32i64 * v30;
    v39 = input->m_weldClosestPoints.m_storage == 0;
    v40 = *(__int128 *)((char *)&points.m_separatingNormal + v38);
    v63[0] = featuresOut[v36].numFeatures;
    if ( !v39 && numFeatures )
    {
      v41 = bodyB->m_motion;
      v42 = bodyA->m_motion;
      v43 = *(__int128 *)((char *)&points.m_position + v38);
      vfptr = v14->vfptr;
      *(_OWORD *)v52 = v40;
      *(_OWORD *)&v52[16] = v43;
      v45 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, _BYTE *, const void *, hkpShape *, const void *, _BYTE *))vfptr[6].__first_virtual_table_function__)(
              v14,
              featuresOut[v36].featureIds,
              v63,
              &v52[16],
              v41,
              m_shape,
              v42,
              v52);
      v39 = input->m_forceAcceptContactPoints.m_storage == 0;
      *(hkVector4f *)((char *)&points.m_position + v38) = *(hkVector4f *)&v52[16];
      if ( v39 && !v45 )
        goto LABEL_18;
      if ( v45 == 1 )
        *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v38) = _mm_shuffle_ps(
                                                                         *(__m128 *)v52,
                                                                         _mm_unpackhi_ps(
                                                                           *(__m128 *)v52,
                                                                           *(__m128 *)((char *)&points.m_separatingNormal.m_quad
                                                                                     + v38)),
                                                                         196);
    }
    v46 = *(__int128 *)((char *)&points.m_separatingNormal + v38);
    v47 = collector->vfptr;
    v53 = (hkpCdBody *)points.m_position.m_quad.m128_u64[v38 / 8 + 1];
    *(_OWORD *)&v52[8] = v46;
    *(_OWORD *)&v52[24] = v40;
    v47->addCdPoint(collector, (hkpCdPoint *)&v52[32]);
  }
LABEL_18:
  v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v49 = (_QWORD *)v48[1];
  if ( (unsigned __int64)v49 < v48[3] )
  {
    *v49 = "Et";
    v50 = __rdtsc();
    v51 = v49 + 2;
    *((_DWORD *)v51 - 2) = v50;
    v48[1] = v51;
  }
}

// File Line: 376
// RVA: 0xD232B0
void __fastcall hkpCapsuleTriangleAgent::getPenetrations(
        hkpCapsuleTriangleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r9
  hkpShape *v16; // r8
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __int64 v20; // rcx
  signed __int64 v21; // rdx
  __m128 v22; // xmm6
  hkpShape *v23; // rax
  __m128 v24; // xmm1
  __m128 *v25; // rax
  __int64 v26; // rcx
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 *p_m_type; // rax
  __m128 v32; // xmm1
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  _QWORD *v36; // rcx
  hkVector4f capsAPoints; // [rsp+50h] [rbp-D8h] BYREF
  char v38; // [rsp+60h] [rbp-C8h] BYREF
  hkVector4f triVertices; // [rsp+70h] [rbp-B8h] BYREF
  char v40[16]; // [rsp+90h] [rbp-98h] BYREF
  hkContactPoint points; // [rsp+A0h] [rbp-88h] BYREF
  __m128 v42; // [rsp+D0h] [rbp-58h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtCapsTriangle";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v16 = bodyB->m_shape;
  v17 = *m_motion;
  v18 = m_motion[1];
  v19 = m_motion[2];
  v20 = 1i64;
  v21 = &v38 - (char *)bodyA->m_shape;
  v22 = m_motion[3];
  v23 = bodyA->m_shape + 2;
  do
  {
    v24 = (__m128)v23->hkReferencedObject;
    v23 = (hkpShape *)((char *)v23 - 16);
    --v20;
    *(__m128 *)((char *)&v23[-1] + v21 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v18),
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v17)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v19)),
                                                 v22);
  }
  while ( v20 >= 0 );
  v25 = (__m128 *)bodyB->m_motion;
  v26 = 2i64;
  v27 = *v25;
  v28 = v25[1];
  v29 = v25[2];
  v30 = v25[3];
  p_m_type = (__m128 *)&v16[2].m_type;
  do
  {
    v32 = *p_m_type--;
    --v26;
    *(__m128 *)((char *)p_m_type + v40 - (char *)v16 - 64) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v28),
                                                                   _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v27)),
                                                                 _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v29)),
                                                               v30);
  }
  while ( v26 >= 0 );
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v16[1].vfptr,
    &this->m_triangleCache,
    input->m_tolerance.m_storage,
    0,
    &points,
    0i64);
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmplt_ps(
             _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255),
             (__m128)0i64),
           _mm_cmplt_ps(_mm_shuffle_ps(v42, v42, 255), (__m128)0i64))) )
  {
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = v34 + 2;
    *((_DWORD *)v36 - 2) = v35;
    v33[1] = v36;
  }
})
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = v34

// File Line: 397
// RVA: 0xD234C0
void __fastcall hkpCapsuleTriangleAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r9
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkpShape *v18; // r8
  __int64 v19; // rcx
  __m128 v20; // xmm6
  hkpShape *v21; // rax
  signed __int64 v22; // rdx
  __m128 v23; // xmm1
  __m128 *v24; // rax
  __int64 v25; // rcx
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 v29; // xmm7
  __m128 *p_m_type; // rax
  __m128 v31; // xmm1
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  hkpCollideTriangleUtil::PointTriangleDistanceCache cache; // [rsp+50h] [rbp-F8h] BYREF
  hkVector4f capsAPoints; // [rsp+70h] [rbp-D8h] BYREF
  char v38; // [rsp+80h] [rbp-C8h] BYREF
  hkVector4f triVertices; // [rsp+90h] [rbp-B8h] BYREF
  char v40[16]; // [rsp+B0h] [rbp-98h] BYREF
  hkContactPoint points; // [rsp+C0h] [rbp-88h] BYREF
  __m128 v42; // [rsp+F0h] [rbp-58h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtCapsTriangle";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  hkpCollideTriangleUtil::setupPointTriangleDistanceCache((hkVector4f *)&bodyB->m_shape[1].m_type, &cache);
  m_motion = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  v18 = bodyB->m_shape;
  v19 = 1i64;
  v20 = m_motion[3];
  v21 = bodyA->m_shape + 2;
  v22 = &v38 - (char *)bodyA->m_shape;
  do
  {
    v23 = (__m128)v21->hkReferencedObject;
    v21 = (hkpShape *)((char *)v21 - 16);
    --v19;
    *(__m128 *)((char *)&v21[-1] + v22 - 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                     _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                 v20);
  }
  while ( v19 >= 0 );
  v24 = (__m128 *)bodyB->m_motion;
  v25 = 2i64;
  v26 = *v24;
  v27 = v24[1];
  v28 = v24[2];
  v29 = v24[3];
  p_m_type = (__m128 *)&v18[2].m_type;
  do
  {
    v31 = *p_m_type--;
    --v25;
    *(__m128 *)((char *)p_m_type + v40 - (char *)v18 - 64) = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v27),
                                                                   _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v26)),
                                                                 _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v28)),
                                                               v29);
  }
  while ( v25 >= 0 );
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v18[1].vfptr,
    &cache,
    input->m_tolerance.m_storage,
    0,
    &points,
    0i64);
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmplt_ps(
             _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255),
             (__m128)0i64),
           _mm_cmplt_ps(_mm_shuffle_ps(v42, v42, 255), (__m128)0i64))) )
  {
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = v33 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v32[1] = v35;
  }
}

