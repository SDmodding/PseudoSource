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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRIANGLE, CAPSULE);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CAPSULE, TRIANGLE);
}

// File Line: 78
// RVA: 0xD22BD0
void __fastcall hkpCapsuleTriangleAgent::registerAgent2(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(v1, &f, TRIANGLE, CAPSULE);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpCapsuleTriangleAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(v1, &f, CAPSULE, TRIANGLE);
}

// File Line: 110
// RVA: 0xD23800
hkpCollisionAgent *__fastcall hkpCapsuleTriangleAgent::createTriangleCapsuleAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rsi
  hkpContactMgr *v5; // rdi
  _QWORD **v6; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  v4 = bodyA;
  v5 = mgr;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = v5;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleTriangleAgent::`vftable;
    WORD2(result[1].vfptr) = -1;
    LODWORD(result[1].vfptr) = -1;
    hkpCollideTriangleUtil::setupPointTriangleDistanceCache(
      (hkVector4f *)&v4->m_shape[1].m_type,
      (hkpCollideTriangleUtil::PointTriangleDistanceCache *)&result[1].m_memSizeAndFlags);
    v8->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::`vftable;
    result = v8;
  }
  return result;
}

// File Line: 119
// RVA: 0xD23760
hkpCollisionAgent *__fastcall hkpCapsuleTriangleAgent::createCapsuleTriangleAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rdi
  hkpCdBody *v5; // rsi
  _QWORD **v6; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  v4 = mgr;
  v5 = bodyB;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = v4;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleTriangleAgent::`vftable;
    WORD2(result[1].vfptr) = -1;
    LODWORD(result[1].vfptr) = -1;
    hkpCollideTriangleUtil::setupPointTriangleDistanceCache(
      (hkVector4f *)&v5->m_shape[1].m_type,
      (hkpCollideTriangleUtil::PointTriangleDistanceCache *)&result[1].m_memSizeAndFlags);
    result = v8;
  }
  return result;
}

// File Line: 128
// RVA: 0xD236E0
void __fastcall hkpCapsuleTriangleAgent::cleanup(hkpCapsuleTriangleAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // rbp
  hkpCapsuleTriangleAgent *v3; // rsi
  unsigned __int16 *v4; // rbx
  signed __int64 v5; // rdi
  __int64 v6; // rdx

  v2 = constraintOwner;
  v3 = this;
  v4 = this->m_contactPointId;
  v5 = 3i64;
  do
  {
    v6 = *v4;
    if ( (_WORD)v6 != -1 )
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v3->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
        v3->m_contactMgr,
        v6,
        v2);
    ++v4;
    --v5;
  }
  while ( v5 );
  if ( v3 )
    v3->vfptr->__vecDelDtor((hkBaseObject *)&v3->vfptr, 1u);
}

// File Line: 161
// RVA: 0xD238B0
void __fastcall hkpCapsuleTriangleAgent::getClosestPointsPublic(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCollideTriangleUtil::PointTriangleDistanceCache *cache, int searchManifold, hkContactPoint *points)
{
  hkpShape *v6; // rbx
  hkpShape *v7; // r10
  __m128 *v8; // rax
  signed __int64 v9; // rcx
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 *v14; // rax
  __m128 v15; // xmm1
  __m128 *v16; // rax
  signed __int64 v17; // rcx
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm7
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v22; // rax
  __m128 v23; // xmm1
  hkVector4f capsAPoints; // [rsp+50h] [rbp-78h]
  char v25[16]; // [rsp+60h] [rbp-68h]
  hkVector4f triVertices; // [rsp+70h] [rbp-58h]
  char v27[16]; // [rsp+90h] [rbp-38h]

  v6 = bodyA->m_shape;
  v7 = bodyB->m_shape;
  v8 = (__m128 *)bodyA->m_motion;
  v9 = 1i64;
  v10 = *v8;
  v11 = v8[1];
  v12 = v8[2];
  v13 = v8[3];
  v14 = (__m128 *)&v6[2];
  do
  {
    v15 = *v14;
    --v14;
    --v9;
    *(__m128 *)((char *)v14 + v25 - (char *)v6 - 48) = _mm_add_ps(
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
  v22 = &v7[2].m_type;
  do
  {
    v23 = *(__m128 *)&v22->m_storage;
    v22 -= 16;
    --v17;
    *(__m128 *)&v22[v27 - (char *)v7 - 64].m_storage = _mm_add_ps(
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
    *(float *)&v6[1].vfptr,
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
__int64 __fastcall hkpCapsuleTriangleAgent::getClosestPoint(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCollideTriangleUtil::PointTriangleDistanceCache *cache, hkContactPoint *cpoint)
{
  hkpShape *v5; // r13
  hkpShape *v6; // rsi
  __m128 v7; // xmm7
  __m128 *v8; // rax
  hkpCdBody *v9; // r15
  hkpCdBody *v10; // r12
  hkpCollisionInput *v11; // r14
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  signed __int64 v15; // rdx
  signed __int64 v16; // rcx
  __m128 v17; // xmm6
  __m128 v18; // xmm8
  __m128 *v19; // rax
  __m128 v20; // xmm1
  __m128 *v21; // rax
  signed __int64 v22; // rcx
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v27; // rax
  __m128 v28; // xmm1
  unsigned int v29; // edi
  __m128 v30; // xmm3
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  signed int v34; // ecx
  __int64 v35; // rdx
  char v36; // al
  signed __int64 v37; // rbx
  const void *v38; // rcx
  const void *v39; // rax
  __m128i v40; // xmm1
  hkBaseObjectVtbl *v41; // r10
  int v42; // eax
  hkContactPoint *v43; // rcx
  __int64 result; // rax
  hkVector4f v45; // [rsp+50h] [rbp-B0h]
  hkVector4f capsAPoints; // [rsp+60h] [rbp-A0h]
  char v47; // [rsp+70h] [rbp-90h]
  hkpFeatureOutput featuresOut[4]; // [rsp+80h] [rbp-80h]
  hkContactPoint points; // [rsp+A0h] [rbp-60h]
  __m128 v50; // [rsp+D0h] [rbp-30h]
  hkVector4f triVertices; // [rsp+100h] [rbp+0h]
  char v52[64]; // [rsp+120h] [rbp+20h]
  char v53; // [rsp+190h] [rbp+90h]

  v5 = bodyA->m_shape;
  v6 = bodyB->m_shape;
  v7 = aabbOut.m_quad;
  v8 = (__m128 *)bodyA->m_motion;
  v9 = bodyB;
  v10 = bodyA;
  v11 = input;
  v12 = *v8;
  v13 = v8[1];
  v14 = v8[2];
  v15 = &v47 - (char *)bodyA->m_shape;
  v16 = 1i64;
  v17 = v8[3];
  v18 = aabbOut.m_quad;
  v19 = (__m128 *)&v5[2];
  do
  {
    v20 = *v19;
    --v19;
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
  v21 = (__m128 *)v9->m_motion;
  v22 = 2i64;
  v23 = *v21;
  v24 = v21[1];
  v25 = v21[2];
  v26 = v21[3];
  v27 = &v6[2].m_type;
  do
  {
    v28 = *(__m128 *)&v27->m_storage;
    v27 -= 16;
    --v22;
    *(__m128 *)&v27[v52 - (char *)v6 - 64].m_storage = _mm_add_ps(
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
    *(float *)&v5[1].vfptr,
    &triVertices,
    *(float *)&v6[1].vfptr,
    cache,
    input->m_tolerance.m_storage,
    0,
    &points,
    featuresOut);
  v30 = _mm_shuffle_ps((__m128)LODWORD(v11->m_tolerance.m_storage), (__m128)LODWORD(v11->m_tolerance.m_storage), 0);
  v31 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255);
  v32 = _mm_shuffle_ps(v50, v50, 255);
  v33 = _mm_cmpltps(v31, v32);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_cmpltps(v31, v30), v33)) )
  {
    v34 = 0;
  }
  else
  {
    v34 = -1;
    if ( _mm_movemask_ps(_mm_andnot_ps(v33, _mm_cmpltps(v32, v30))) )
      v34 = 1;
    if ( v34 == -1 )
      goto LABEL_17;
  }
  v35 = v34;
  v36 = featuresOut[v34].numFeatures;
  v37 = 32i64 * v34;
  v53 = featuresOut[v34].numFeatures;
  if ( !v11->m_weldClosestPoints.m_storage || !v36 )
  {
LABEL_16:
    v7 = *(__m128 *)((char *)&points.m_position.m_quad + v37);
    v18 = *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v37);
    v29 = 1;
    goto LABEL_17;
  }
  v38 = v9->m_motion;
  v39 = v10->m_motion;
  v40 = *(__m128i *)((char *)&points.m_position + v37);
  v41 = v6->vfptr;
  _mm_store_si128((__m128i *)&capsAPoints, *(__m128i *)((char *)&points.m_separatingNormal + v37));
  _mm_store_si128((__m128i *)&v45, v40);
  v42 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, hkVector4f *, const void *, hkpShape *, const void *, hkVector4f *))v41[6].__first_virtual_table_function__)(
          v6,
          featuresOut[v35].featureIds,
          &v53,
          &v45,
          v38,
          v5,
          v39,
          &capsAPoints);
  *(hkVector4f *)((char *)&points.m_position + v37) = (hkVector4f)v45.m_quad;
  if ( v11->m_forceAcceptContactPoints.m_storage || v42 )
  {
    if ( v42 == 1 )
      *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v37) = _mm_shuffle_ps(
                                                                       capsAPoints.m_quad,
                                                                       _mm_unpackhi_ps(
                                                                         capsAPoints.m_quad,
                                                                         *(__m128 *)((char *)&points.m_separatingNormal.m_quad
                                                                                   + v37)),
                                                                       196);
    goto LABEL_16;
  }
LABEL_17:
  v43 = cpoint;
  result = v29;
  cpoint->m_position.m_quad = v7;
  v43->m_separatingNormal.m_quad = v18;
  return result;
}

// File Line: 259
// RVA: 0xD23E40
void __fastcall hkpCapsuleTriangleAgent::processCollision(hkpCapsuleTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpCapsuleTriangleAgent *v5; // r13
  hkpProcessCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 *v13; // rax
  hkpShape *v14; // r9
  hkpShape *v15; // r8
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __m128 *v20; // rax
  signed __int64 v21; // rcx
  __m128 v22; // xmm1
  __m128 *v23; // rax
  signed __int64 v24; // rcx
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 *v29; // rax
  __m128 v30; // xmm1
  hkpProcessCollisionInput *v31; // rdx
  hkpProcessCollisionOutput *v32; // rsi
  __m128i *v33; // rdi
  hkpFeatureOutput *v34; // r14
  float v35; // xmm6_4
  unsigned __int16 *v36; // rbx
  hkContactPoint *v37; // rbp
  unsigned __int16 *v38; // r15
  signed __int64 v39; // r12
  __m128i v40; // xmm1
  __int64 v41; // rax
  __int64 v42; // rcx
  int v43; // eax
  __int64 v44; // rdx
  unsigned __int16 v45; // ax
  hkpProcessCdPoint *v46; // rcx
  __m128i v47; // xmm0
  __int64 v48; // rdx
  _QWORD *v49; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  signed __int64 v52; // rcx
  hkpShape *v53; // [rsp+50h] [rbp-148h]
  hkpShape *v54; // [rsp+58h] [rbp-140h]
  __m128i v55; // [rsp+60h] [rbp-138h]
  hkVector4f capsAPoints; // [rsp+70h] [rbp-128h]
  char v57[16]; // [rsp+80h] [rbp-118h]
  hkpFeatureOutput featuresOut; // [rsp+90h] [rbp-108h]
  hkVector4f triVertices; // [rsp+B0h] [rbp-E8h]
  char v60[16]; // [rsp+D0h] [rbp-C8h]
  hkContactPoint points; // [rsp+E0h] [rbp-B8h]
  char v62; // [rsp+1A0h] [rbp+8h]
  hkpCdBody *v63; // [rsp+1A8h] [rbp+10h]
  hkpCdBody *v64; // [rsp+1B0h] [rbp+18h]
  hkpProcessCollisionInput *v65; // [rsp+1B8h] [rbp+20h]

  v65 = input;
  v64 = bodyB;
  v63 = bodyA;
  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtCapsuleTri";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = (__m128 *)v8->m_motion;
  v14 = v8->m_shape;
  v15 = v7->m_shape;
  v16 = *v13;
  v17 = v13[1];
  v18 = v13[2];
  v53 = v8->m_shape;
  v54 = v7->m_shape;
  v19 = v13[3];
  v20 = (__m128 *)&v8->m_shape[2];
  v21 = 1i64;
  do
  {
    v22 = *v20;
    --v20;
    --v21;
    *(__m128 *)((char *)v20 + v57 - (char *)v14 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v17),
                                                              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v16)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v18)),
                                                          v19);
  }
  while ( v21 >= 0 );
  v23 = (__m128 *)v7->m_motion;
  v24 = 2i64;
  v25 = *v23;
  v26 = v23[1];
  v27 = v23[2];
  v28 = v23[3];
  v29 = (__m128 *)&v15[2].m_type;
  do
  {
    v30 = *v29;
    --v29;
    --v24;
    *(__m128 *)((char *)v29 + v60 - (char *)v15 - 64) = _mm_add_ps(
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
    *(float *)&v14[1].vfptr,
    &triVertices,
    *(float *)&v15[1].vfptr,
    &v5->m_triangleCache,
    v6->m_tolerance.m_storage,
    1,
    &points,
    &featuresOut);
  v31 = v65;
  v32 = result;
  v33 = (__m128i *)&points.m_separatingNormal;
  v34 = &featuresOut;
  LODWORD(v35) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(v65->m_tolerance.m_storage),
                                      (__m128)LODWORD(v65->m_tolerance.m_storage),
                                      0);
  v36 = v5->m_contactPointId;
  v37 = &points;
  v38 = featuresOut.featureIds;
  v39 = 3i64;
  do
  {
    if ( COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)v33, *(__m128 *)v33, 255)) >= v35 )
    {
      v48 = *v36;
      if ( (_WORD)v48 != -1 )
      {
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
          v5->m_contactMgr,
          v48,
          v32->m_constraintOwner.m_storage);
        *v36 = -1;
      }
    }
    else
    {
      v62 = v34->numFeatures;
      if ( v62 )
      {
        v40 = v33[-1];
        v41 = (__int64)v63;
        v42 = (__int64)v64;
        _mm_store_si128((__m128i *)&capsAPoints, *v33);
        _mm_store_si128(&v55, v40);
        v43 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, __m128i *, _QWORD, hkpShape *, _QWORD, hkVector4f *))v54->vfptr[6].__first_virtual_table_function__)(
                v54,
                v38,
                &v62,
                &v55,
                *(_QWORD *)(v42 + 16),
                v53,
                *(_QWORD *)(v41 + 16),
                &capsAPoints);
        v33[-1] = v55;
        if ( !v43 )
        {
          v44 = *v36;
          if ( (_WORD)v44 != -1 )
          {
            ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
              v5->m_contactMgr,
              v44,
              v32->m_constraintOwner.m_storage);
            *v36 = -1;
          }
          goto LABEL_20;
        }
        v31 = v65;
        if ( v43 == 1 )
          *(__m128 *)v33 = _mm_shuffle_ps(capsAPoints.m_quad, _mm_unpackhi_ps(capsAPoints.m_quad, *(__m128 *)v33), 196);
      }
      if ( *v36 != -1
        || (v45 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkContactPoint *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                    v5->m_contactMgr,
                    v63,
                    v64,
                    v31,
                    v32,
                    0i64,
                    v37),
            *v36 = v45,
            v45 != -1) )
      {
        v46 = v32->m_firstFreeContactPoint.m_storage;
        v47 = v33[-1];
        ++v32->m_firstFreeContactPoint.m_storage;
        v46->m_contact.m_position = (hkVector4f)v47;
        v46->m_contact.m_separatingNormal = (hkVector4f)*v33;
        v46->m_contactPointId = *v36;
      }
    }
LABEL_20:
    v31 = v65;
    v38 += 4;
    ++v37;
    ++v36;
    ++v34;
    v33 += 2;
    --v39;
  }
  while ( v39 );
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "Et";
    v51 = __rdtsc();
    v52 = (signed __int64)(v50 + 2);
    *(_DWORD *)(v52 - 8) = v51;
    v49[1] = v52;
  }
}

// File Line: 333
// RVA: 0xD22C40
void __fastcall hkpCapsuleTriangleAgent::getClosestPoints(hkpCapsuleTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input)
{
  hkpCapsuleTriangleAgent *v4; // rbx
  hkpCollisionInput *v5; // r14
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // r15
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rax
  hkpShape *v13; // r13
  hkpShape *v14; // rdi
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  signed __int64 v18; // rcx
  __m128 v19; // xmm6
  __m128 *v20; // rax
  __m128 v21; // xmm1
  __m128 *v22; // rax
  signed __int64 v23; // rcx
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 *v28; // rax
  __m128 v29; // xmm1
  hkpCollideTriangleUtil::PointTriangleDistanceCache *cache; // rax
  signed int v31; // ebx
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __int64 v36; // rdx
  char v37; // al
  signed __int64 v38; // rbx
  bool v39; // zf
  __m128i v40; // xmm6
  const void *v41; // rcx
  const void *v42; // rax
  __m128i v43; // xmm1
  hkBaseObjectVtbl *v44; // r10
  int v45; // eax
  __int128 v46; // xmm1
  __int64 v47; // rax
  _QWORD *v48; // r8
  _QWORD *v49; // rcx
  unsigned __int64 v50; // rax
  signed __int64 v51; // rcx
  char v52[24]; // [rsp+50h] [rbp-88h]
  char v53[24]; // [rsp+68h] [rbp-70h]
  hkpCdBody *v54; // [rsp+80h] [rbp-58h]
  hkpFeatureOutput featuresOut[4]; // [rsp+88h] [rbp-50h]
  hkContactPoint points; // [rsp+A8h] [rbp-30h]
  __m128 v57; // [rsp+D8h] [rbp+0h]
  hkVector4f capsAPoints; // [rsp+108h] [rbp+30h]
  char v59[16]; // [rsp+118h] [rbp+40h]
  hkVector4f triVertices; // [rsp+128h] [rbp+50h]
  char v61[72]; // [rsp+148h] [rbp+70h]
  char v62; // [rsp+198h] [rbp+C0h]
  __int64 *retaddr; // [rsp+1B8h] [rbp+E0h]

  v4 = this;
  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtCapsTriangle";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v7->m_motion;
  v13 = v7->m_shape;
  v14 = v6->m_shape;
  v54 = v6;
  *(hkVector4f *)&v53[8] = (hkVector4f)aabbOut.m_quad;
  *(hkVector4f *)&v52[8] = (hkVector4f)aabbOut.m_quad;
  *(hkVector4f *)v53 = (hkVector4f)aabbOut.m_quad;
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v18 = 1i64;
  v19 = v12[3];
  v20 = (__m128 *)&v13[2];
  do
  {
    v21 = *v20;
    --v20;
    --v18;
    *(__m128 *)((char *)v20 + v59 - (char *)v13 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v16),
                                                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v15)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v17)),
                                                          v19);
  }
  while ( v18 >= 0 );
  v22 = (__m128 *)v6->m_motion;
  v23 = 2i64;
  v24 = *v22;
  v25 = v22[1];
  v26 = v22[2];
  v27 = v22[3];
  v28 = (__m128 *)&v14[2].m_type;
  do
  {
    v29 = *v28;
    --v28;
    --v23;
    *(__m128 *)((char *)v28 + v61 - (char *)v14 - 64) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v25),
                                                              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v24)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v26)),
                                                          v27);
  }
  while ( v23 >= 0 );
  cache = &v4->m_triangleCache;
  v31 = 0;
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&v13[1].vfptr,
    &triVertices,
    *(float *)&v14[1].vfptr,
    cache,
    v5->m_tolerance.m_storage,
    0,
    &points,
    featuresOut);
  v32 = _mm_shuffle_ps((__m128)LODWORD(v5->m_tolerance.m_storage), (__m128)LODWORD(v5->m_tolerance.m_storage), 0);
  v33 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255);
  v34 = _mm_shuffle_ps(v57, v57, 255);
  v35 = _mm_cmpltps(v33, v34);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_cmpltps(v33, v32), v35)) )
    goto LABEL_22;
  v31 = -1;
  if ( _mm_movemask_ps(_mm_andnot_ps(v35, _mm_cmpltps(v34, v32))) )
    v31 = 1;
  if ( v31 != -1 )
  {
LABEL_22:
    v36 = v31;
    v37 = featuresOut[v31].numFeatures;
    v38 = 32i64 * v31;
    v39 = v5->m_weldClosestPoints.m_storage == 0;
    v40 = *(__m128i *)((char *)&points.m_separatingNormal + v38);
    v62 = featuresOut[v36].numFeatures;
    if ( !v39 && v37 )
    {
      v41 = v6->m_motion;
      v42 = v7->m_motion;
      v43 = *(__m128i *)((char *)&points.m_position + v38);
      v44 = v14->vfptr;
      _mm_store_si128((__m128i *)v52, v40);
      _mm_store_si128((__m128i *)&v52[16], v43);
      v45 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, char *, char *, const void *, hkpShape *, const void *, char *))v44[6].__first_virtual_table_function__)(
              v14,
              featuresOut[v36].featureIds,
              &v62,
              &v52[16],
              v41,
              v13,
              v42,
              v52);
      v39 = v5->m_forceAcceptContactPoints.m_storage == 0;
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
    v47 = *retaddr;
    *(hkVector4f *)&v53[8] = *(hkVector4f *)((char *)&points.m_position + v38);
    *(_OWORD *)&v52[8] = v46;
    *(__m128i *)v53 = v40;
    (*(void (__fastcall **)(__int64 *, char *))(v47 + 8))(retaddr, &v53[8]);
  }
LABEL_18:
  v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v49 = (_QWORD *)v48[1];
  if ( (unsigned __int64)v49 < v48[3] )
  {
    *v49 = "Et";
    v50 = __rdtsc();
    v51 = (signed __int64)(v49 + 2);
    *(_DWORD *)(v51 - 8) = v50;
    v48[1] = v51;
  }
}

// File Line: 351
// RVA: 0xD22F70
void __fastcall hkpCapsuleTriangleAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // r12
  hkpCdPointCollector *v5; // r14
  hkpCollisionInput *v6; // r15
  hkpCdBody *v7; // rsi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rax
  hkpShape *v13; // r13
  hkVector4f *v14; // rdi
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  signed __int64 v18; // rcx
  __m128 v19; // xmm6
  __m128 *v20; // rax
  __m128 v21; // xmm1
  __m128 *v22; // rax
  signed __int64 v23; // rcx
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 *v28; // rax
  __m128 v29; // xmm1
  signed int v30; // ebx
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __int64 v35; // rdx
  char v36; // al
  signed __int64 v37; // rbx
  bool v38; // zf
  __m128i v39; // xmm6
  const void *v40; // rcx
  const void *v41; // rax
  __m128i v42; // xmm1
  unsigned __int64 v43; // r10
  int v44; // eax
  __int128 v45; // xmm1
  hkpCdPointCollectorVtbl *v46; // rax
  _QWORD *v47; // r8
  _QWORD *v48; // rcx
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  char v51[24]; // [rsp+50h] [rbp-88h]
  char v52[24]; // [rsp+68h] [rbp-70h]
  hkpCdBody *v53; // [rsp+80h] [rbp-58h]
  hkpFeatureOutput featuresOut[4]; // [rsp+88h] [rbp-50h]
  hkContactPoint points; // [rsp+A8h] [rbp-30h]
  __m128 v56; // [rsp+D8h] [rbp+0h]
  hkpCollideTriangleUtil::PointTriangleDistanceCache cache; // [rsp+108h] [rbp+30h]
  hkVector4f capsAPoints; // [rsp+128h] [rbp+50h]
  char v59[16]; // [rsp+138h] [rbp+60h]
  hkVector4f triVertices; // [rsp+148h] [rbp+70h]
  char v61[72]; // [rsp+168h] [rbp+90h]
  char v62; // [rsp+1B8h] [rbp+E0h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtCapsTriangle";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  hkpCollideTriangleUtil::setupPointTriangleDistanceCache((hkVector4f *)&v7->m_shape[1].m_type, &cache);
  v12 = (__m128 *)v4->m_motion;
  v13 = v4->m_shape;
  *(hkVector4f *)&v52[8] = (hkVector4f)aabbOut.m_quad;
  *(hkVector4f *)&v51[8] = (hkVector4f)aabbOut.m_quad;
  *(hkVector4f *)v52 = (hkVector4f)aabbOut.m_quad;
  v14 = (hkVector4f *)v7->m_shape;
  *(_QWORD *)&v52[16] = v4;
  v53 = v7;
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v18 = 1i64;
  v19 = v12[3];
  v20 = (__m128 *)&v13[2];
  do
  {
    v21 = *v20;
    --v20;
    --v18;
    *(__m128 *)((char *)v20 + v59 - (char *)v13 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v16),
                                                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v15)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v17)),
                                                          v19);
  }
  while ( v18 >= 0 );
  v22 = (__m128 *)v7->m_motion;
  v23 = 2i64;
  v24 = *v22;
  v25 = v22[1];
  v26 = v22[2];
  v27 = v22[3];
  v28 = &v14[5].m_quad;
  do
  {
    v29 = *v28;
    --v28;
    --v23;
    *(__m128 *)((char *)v28 + v61 - (char *)v14 - 64) = _mm_add_ps(
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
    *(float *)&v13[1].vfptr,
    &triVertices,
    v14[2].m_quad.m128_f32[0],
    &cache,
    v6->m_tolerance.m_storage,
    0,
    &points,
    featuresOut);
  v31 = _mm_shuffle_ps((__m128)LODWORD(v6->m_tolerance.m_storage), (__m128)LODWORD(v6->m_tolerance.m_storage), 0);
  v32 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255);
  v33 = _mm_shuffle_ps(v56, v56, 255);
  v34 = _mm_cmpltps(v32, v33);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_cmpltps(v32, v31), v34)) )
    goto LABEL_22;
  v30 = -1;
  if ( _mm_movemask_ps(_mm_andnot_ps(v34, _mm_cmpltps(v33, v31))) )
    v30 = 1;
  if ( v30 != -1 )
  {
LABEL_22:
    v35 = v30;
    v36 = featuresOut[v30].numFeatures;
    v37 = 32i64 * v30;
    v38 = v6->m_weldClosestPoints.m_storage == 0;
    v39 = *(__m128i *)((char *)&points.m_separatingNormal + v37);
    v62 = featuresOut[v35].numFeatures;
    if ( !v38 && v36 )
    {
      v40 = v7->m_motion;
      v41 = v4->m_motion;
      v42 = *(__m128i *)((char *)&points.m_position + v37);
      v43 = v14->m_quad.m128_u64[0];
      _mm_store_si128((__m128i *)v51, v39);
      _mm_store_si128((__m128i *)&v51[16], v42);
      v44 = (*(__int64 (__fastcall **)(hkVector4f *, unsigned __int16 *, char *, char *, const void *, hkpShape *, const void *, char *))(v43 + 104))(
              v14,
              featuresOut[v35].featureIds,
              &v62,
              &v51[16],
              v40,
              v13,
              v41,
              v51);
      v38 = v6->m_forceAcceptContactPoints.m_storage == 0;
      *(hkVector4f *)((char *)&points.m_position + v37) = *(hkVector4f *)&v51[16];
      if ( v38 && !v44 )
        goto LABEL_18;
      if ( v44 == 1 )
        *(__m128 *)((char *)&points.m_separatingNormal.m_quad + v37) = _mm_shuffle_ps(
                                                                         *(__m128 *)v51,
                                                                         _mm_unpackhi_ps(
                                                                           *(__m128 *)v51,
                                                                           *(__m128 *)((char *)&points.m_separatingNormal.m_quad
                                                                                     + v37)),
                                                                         196);
    }
    v45 = *(__int128 *)((char *)&points.m_separatingNormal + v37);
    v46 = v5->vfptr;
    *(hkVector4f *)&v52[8] = *(hkVector4f *)((char *)&points.m_position + v37);
    *(_OWORD *)&v51[8] = v45;
    *(__m128i *)v52 = v39;
    v46->addCdPoint(v5, (hkpCdPoint *)&v52[8]);
  }
LABEL_18:
  v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v48 = (_QWORD *)v47[1];
  if ( (unsigned __int64)v48 < v47[3] )
  {
    *v48 = "Et";
    v49 = __rdtsc();
    v50 = (signed __int64)(v48 + 2);
    *(_DWORD *)(v50 - 8) = v49;
    v47[1] = v50;
  }
}

// File Line: 376
// RVA: 0xD232B0
void __fastcall hkpCapsuleTriangleAgent::getPenetrations(hkpCapsuleTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCapsuleTriangleAgent *v5; // rbp
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __m128 *v14; // rax
  hkpShape *v15; // r9
  hkpShape *v16; // r8
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  signed __int64 v20; // rcx
  char *v21; // rdx
  __m128 v22; // xmm6
  __m128 *v23; // rax
  __m128 v24; // xmm1
  __m128 *v25; // rax
  signed __int64 v26; // rcx
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 *v31; // rax
  __m128 v32; // xmm1
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  hkVector4f capsAPoints; // [rsp+50h] [rbp-D8h]
  char v38[16]; // [rsp+60h] [rbp-C8h]
  hkVector4f triVertices; // [rsp+70h] [rbp-B8h]
  char v40[16]; // [rsp+90h] [rbp-98h]
  hkContactPoint points; // [rsp+A0h] [rbp-88h]
  __m128 v42; // [rsp+D0h] [rbp-58h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtCapsTriangle";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = (__m128 *)v8->m_motion;
  v15 = v8->m_shape;
  v16 = v7->m_shape;
  v17 = *v14;
  v18 = v14[1];
  v19 = v14[2];
  v20 = 1i64;
  v21 = (char *)(v38 - (char *)v8->m_shape);
  v22 = v14[3];
  v23 = (__m128 *)&v8->m_shape[2];
  do
  {
    v24 = *v23;
    --v23;
    --v20;
    *(__m128 *)((char *)v23 + (_QWORD)v21 - 48) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v18),
                                                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v17)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v19)),
                                                    v22);
  }
  while ( v20 >= 0 );
  v25 = (__m128 *)v7->m_motion;
  v26 = 2i64;
  v27 = *v25;
  v28 = v25[1];
  v29 = v25[2];
  v30 = v25[3];
  v31 = (__m128 *)&v16[2].m_type;
  do
  {
    v32 = *v31;
    --v31;
    --v26;
    *(__m128 *)((char *)v31 + v40 - (char *)v16 - 64) = _mm_add_ps(
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
    *(float *)&v15[1].vfptr,
    &triVertices,
    *(float *)&v16[1].vfptr,
    &v5->m_triangleCache,
    v6->m_tolerance.m_storage,
    0,
    &points,
    0i64);
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmpltps(
             _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255),
             (__m128)0i64),
           _mm_cmpltps(_mm_shuffle_ps(v42, v42, 255), (__m128)0i64))) )
  {
    collector->vfptr->addCdBodyPair(collector, v8, v7);
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v36 - 8) = v35;
    v33[1] = v36;
  }
}34 = "Et";
    v35 = __rdtsc();
    v36 = (sign

// File Line: 397
// RVA: 0xD234C0
void __fastcall hkpCapsuleTriangleAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdBodyPairCollector *v5; // rdi
  hkpCollisionInput *v6; // rbp
  hkpCdBody *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 *v13; // rax
  hkpShape *v14; // r9
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // r8
  signed __int64 v19; // rcx
  __m128 v20; // xmm6
  __m128 *v21; // rax
  char *v22; // rdx
  __m128 v23; // xmm1
  __m128 *v24; // rax
  signed __int64 v25; // rcx
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 v29; // xmm7
  __m128 *v30; // rax
  __m128 v31; // xmm1
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  hkpCollideTriangleUtil::PointTriangleDistanceCache cache; // [rsp+50h] [rbp-F8h]
  hkVector4f capsAPoints; // [rsp+70h] [rbp-D8h]
  char v38[16]; // [rsp+80h] [rbp-C8h]
  hkVector4f triVertices; // [rsp+90h] [rbp-B8h]
  char v40[16]; // [rsp+B0h] [rbp-98h]
  hkContactPoint points; // [rsp+C0h] [rbp-88h]
  __m128 v42; // [rsp+F0h] [rbp-58h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtCapsTriangle";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  hkpCollideTriangleUtil::setupPointTriangleDistanceCache((hkVector4f *)&v7->m_shape[1].m_type, &cache);
  v13 = (__m128 *)v4->m_motion;
  v14 = v4->m_shape;
  v15 = *v13;
  v16 = v13[1];
  v17 = v13[2];
  v18 = (hkVector4f *)v7->m_shape;
  v19 = 1i64;
  v20 = v13[3];
  v21 = (__m128 *)&v4->m_shape[2];
  v22 = (char *)(v38 - (char *)v4->m_shape);
  do
  {
    v23 = *v21;
    --v21;
    --v19;
    *(__m128 *)((char *)v21 + (_QWORD)v22 - 48) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16),
                                                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v17)),
                                                    v20);
  }
  while ( v19 >= 0 );
  v24 = (__m128 *)v7->m_motion;
  v25 = 2i64;
  v26 = *v24;
  v27 = v24[1];
  v28 = v24[2];
  v29 = v24[3];
  v30 = &v18[5].m_quad;
  do
  {
    v31 = *v30;
    --v30;
    --v25;
    *(__m128 *)((char *)v30 + v40 - (char *)v18 - 64) = _mm_add_ps(
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
    *(float *)&v14[1].vfptr,
    &triVertices,
    v18[2].m_quad.m128_f32[0],
    &cache,
    v6->m_tolerance.m_storage,
    0,
    &points,
    0i64);
  if ( _mm_movemask_ps(
         _mm_or_ps(
           _mm_cmpltps(
             _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255),
             (__m128)0i64),
           _mm_cmpltps(_mm_shuffle_ps(v42, v42, 255), (__m128)0i64))) )
  {
    v5->vfptr->addCdBodyPair(v5, v4, v7);
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v33 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v32[1] = v35;
  }
}

