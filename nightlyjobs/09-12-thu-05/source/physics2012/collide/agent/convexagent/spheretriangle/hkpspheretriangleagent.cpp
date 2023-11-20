// File Line: 20
// RVA: 0xD20D60
void __fastcall hkpSphereTriangleAgent::initAgentFunc(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpSphereTriangleAgent::createSphereTriangleAgent;
  af->m_getPenetrationsFunc = hkpSphereTriangleAgent::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpSphereTriangleAgent::staticGetClosestPoints;
  af->m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 0;
}

// File Line: 31
// RVA: 0xD20DA0
void __fastcall hkpSphereTriangleAgent::initAgentFuncInverse(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpSphereTriangleAgent::createTriangleSphereAgent;
  af->m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::staticGetClosestPoints;
  af->m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 1;
}

// File Line: 61
// RVA: 0xD20DE0
void __fastcall hkpSphereTriangleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereTriangleAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRIANGLE, 0);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereTriangleAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, 0, TRIANGLE);
}

// File Line: 76
// RVA: 0xD20E50
void __fastcall hkpSphereTriangleAgent::registerAgent2(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereTriangleAgent::initAgentFuncInverse(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(v1, &f, TRIANGLE, 0);
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereTriangleAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(v1, &f, 0, TRIANGLE);
}

// File Line: 106
// RVA: 0xD21700
hkpCollisionAgent *__fastcall hkpSphereTriangleAgent::createTriangleSphereAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rsi
  hkpContactMgr *v5; // rdi
  _QWORD **v6; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  v4 = bodyA;
  v5 = mgr;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = v5;
    result->m_memSizeAndFlags = -1;
    LOWORD(result[1].vfptr) = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereTriangleAgent::`vftable;
    hkpCollideTriangleUtil::setupClosestPointTriangleCache(
      (hkVector4f *)&v4->m_shape[1].m_type,
      (hkpCollideTriangleUtil::ClosestPointTriangleCache *)((char *)&result[1].vfptr + 4));
    v8->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::`vftable;
    result = v8;
  }
  return result;
}

// File Line: 115
// RVA: 0xD21660
hkpCollisionAgent *__fastcall hkpSphereTriangleAgent::createSphereTriangleAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rdi
  hkpCdBody *v5; // rsi
  _QWORD **v6; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  v4 = mgr;
  v5 = bodyB;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = v4;
    result->m_memSizeAndFlags = -1;
    LOWORD(result[1].vfptr) = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereTriangleAgent::`vftable;
    hkpCollideTriangleUtil::setupClosestPointTriangleCache(
      (hkVector4f *)&v5->m_shape[1].m_type,
      (hkpCollideTriangleUtil::ClosestPointTriangleCache *)((char *)&result[1].vfptr + 4));
    result = v8;
  }
  return result;
}

// File Line: 123
// RVA: 0xD21620
void __fastcall hkpSphereTriangleAgent::cleanup(hkpSphereTriangleAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 v3; // rdx
  hkpSphereTriangleAgent *v4; // rbx

  v2 = constraintOwner;
  v3 = this->m_contactPointId;
  v4 = this;
  if ( (_WORD)v3 != -1 )
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      v3,
      v2);
  ((void (__fastcall *)(hkpSphereTriangleAgent *, signed __int64, hkpConstraintOwner *))v4->vfptr->__vecDelDtor)(
    v4,
    1i64,
    v2);
}

// File Line: 171
// RVA: 0xD217A0
__int64 __fastcall hkpSphereTriangleAgent::getClosestPoint(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCollideTriangleUtil::ClosestPointTriangleCache *cache, hkContactPoint *cpoint)
{
  __m128 *v5; // rax
  hkpShape *v6; // rdi
  hkpShape *v7; // r14
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  hkVector4f *v11; // rsi
  __m128 v12; // xmm6
  hkpCollisionInput *v13; // rbp
  signed __int64 v14; // rcx
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v15; // rax
  signed __int64 v16; // rdx
  __m128 v17; // xmm1
  int v18; // ebx
  hkpCollideTriangleUtil::ClosestPointTriangleStatus v19; // eax
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  hkVector4f v22; // xmm1
  __int64 v23; // rax
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+30h] [rbp-78h]
  hkVector4f tri; // [rsp+50h] [rbp-58h]
  char v26; // [rsp+70h] [rbp-38h]
  unsigned int v27; // [rsp+B0h] [rbp+8h]

  v5 = (__m128 *)bodyB->m_motion;
  v6 = bodyB->m_shape;
  v7 = bodyA->m_shape;
  v8 = *v5;
  v9 = v5[1];
  v10 = v5[2];
  v11 = (hkVector4f *)bodyA->m_motion;
  v12 = v5[3];
  v13 = input;
  v14 = 2i64;
  v15 = &bodyB->m_shape[2].m_type;
  v16 = &v26 - (char *)bodyB->m_shape;
  do
  {
    v17 = *(__m128 *)&v15->m_storage;
    v15 -= 16;
    --v14;
    *(__m128 *)&v15[v16 - 64].m_storage = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v8),
                                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v9)),
                                              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v10)),
                                            v12);
  }
  while ( v14 >= 0 );
  v18 = 0;
  v19 = hkpCollideTriangleUtil::closestPointTriangle(v11 + 3, &tri, cache, &result, 0i64);
  v20 = _mm_shuffle_ps((__m128)LODWORD(result.distance), (__m128)LODWORD(result.distance), 0);
  *(float *)&v27 = *(float *)&v7[1].vfptr + *(float *)&v6[1].vfptr;
  v21 = _mm_shuffle_ps((__m128)v27, (__m128)v27, 0);
  if ( v20.m128_f32[0] >= (float)(COERCE_FLOAT(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(v13->m_tolerance.m_storage),
                                      (__m128)LODWORD(v13->m_tolerance.m_storage),
                                      0))
                                + v21.m128_f32[0]) )
    return 0i64;
  v22.m_quad = (__m128)result.hitDirection;
  LOBYTE(v18) = v19 != 0;
  v23 = (unsigned int)(v18 + 1);
  cpoint->m_position.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps(
                                    _mm_shuffle_ps((__m128)LODWORD(v6[1].vfptr), (__m128)LODWORD(v6[1].vfptr), 0),
                                    v20),
                                  result.hitDirection.m_quad),
                                v11[3].m_quad);
  cpoint->m_separatingNormal.m_quad = _mm_shuffle_ps(v22.m_quad, _mm_unpackhi_ps(v22.m_quad, _mm_sub_ps(v20, v21)), 196);
  return v23;
}

// File Line: 179
// RVA: 0xD21A40
void __fastcall hkpSphereTriangleAgent::processCollision(hkpSphereTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpSphereTriangleAgent *v5; // rbx
  hkpProcessCollisionInput *v6; // r13
  hkpCdBody *v7; // r15
  __int64 *v8; // rbp
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpShape *v13; // rdi
  hkpProcessCollisionOutput *v14; // r14
  hkpProcessCdPoint *v15; // rsi
  hkVector4f *v16; // r12
  __m128 *v17; // rax
  signed __int64 v18; // rcx
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 *v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  hkVector4f v27; // xmm1
  __m128 v28; // xmm1
  __int64 v29; // r8
  const void *v30; // rdx
  hkpShape *v31; // rcx
  __m128i v32; // xmm0
  __m128i v33; // xmm1
  int v34; // eax
  __int64 v35; // rdx
  unsigned __int16 v36; // ax
  __int64 v37; // rdx
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  __m128 v42; // [rsp+40h] [rbp-A8h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult v43; // [rsp+50h] [rbp-98h]
  hkVector4f tri; // [rsp+70h] [rbp-78h]
  char v45[16]; // [rsp+90h] [rbp-58h]
  hkpFeatureOutput featureOutput; // [rsp+F0h] [rbp+8h]
  __int64 v47; // [rsp+F8h] [rbp+10h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = (__int64 *)bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtSphereTri";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = v7->m_shape;
  v14 = result;
  v15 = result->m_firstFreeContactPoint.m_storage;
  v16 = (hkVector4f *)v8[2];
  v47 = *v8;
  v17 = (__m128 *)v7->m_motion;
  v18 = 2i64;
  v19 = *v17;
  v20 = v17[1];
  v21 = v17[2];
  v22 = v17[3];
  v23 = (__m128 *)&v13[2].m_type;
  do
  {
    v24 = *v23;
    --v23;
    --v18;
    *(__m128 *)((char *)v23 + v45 - (char *)v13 - 64) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v20),
                                                              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v19)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v21)),
                                                          v22);
  }
  while ( v18 >= 0 );
  hkpCollideTriangleUtil::closestPointTriangle(v16 + 3, &tri, &v5->m_closestPointTriangleCache, &v43, &featureOutput);
  v25 = _mm_shuffle_ps((__m128)LODWORD(v43.distance), (__m128)LODWORD(v43.distance), 0);
  *(float *)&result = *(float *)(v47 + 32) + *(float *)&v13[1].vfptr;
  v26 = _mm_shuffle_ps((__m128)(unsigned int)result, (__m128)(unsigned int)result, 0);
  *(float *)&result = v6->m_tolerance.m_storage;
  if ( v25.m128_f32[0] >= (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)result, (__m128)(unsigned int)result, 0))
                                + v26.m128_f32[0]) )
  {
    v37 = v5->m_contactPointId;
    if ( (_WORD)v37 != -1 )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
        v5->m_contactMgr,
        v37,
        v14->m_constraintOwner.m_storage);
      v5->m_contactPointId = -1;
    }
  }
  else
  {
    v27.m_quad = (__m128)v43.hitDirection;
    v15->m_contact.m_position.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps(
                                             _mm_shuffle_ps(
                                               (__m128)LODWORD(v13[1].vfptr),
                                               (__m128)LODWORD(v13[1].vfptr),
                                               0),
                                             v25),
                                           v43.hitDirection.m_quad),
                                         v16[3].m_quad);
    v28 = _mm_shuffle_ps(v27.m_quad, _mm_unpackhi_ps(v27.m_quad, _mm_sub_ps(v25, v26)), 196);
    v15->m_contact.m_separatingNormal.m_quad = v28;
    LOBYTE(result) = featureOutput.numFeatures;
    if ( featureOutput.numFeatures )
    {
      v29 = *v8;
      v30 = v7->m_motion;
      v31 = v7->m_shape;
      v32 = (__m128i)v28;
      v33 = (__m128i)v15->m_contact.m_position;
      _mm_store_si128((__m128i *)&v42, v32);
      _mm_store_si128((__m128i *)&v43, v33);
      v34 = ((__int64 (__fastcall *)(hkpShape *, unsigned __int16 *, hkpProcessCollisionOutput **, hkpCollideTriangleUtil::ClosestPointTriangleResult *, const void *, __int64, __int64, __m128 *))v31->vfptr[6].__first_virtual_table_function__)(
              v31,
              featureOutput.featureIds,
              &result,
              &v43,
              v30,
              v29,
              v8[2],
              &v42);
      if ( !v34 )
      {
        v35 = v5->m_contactPointId;
        if ( (_WORD)v35 != -1 )
        {
          ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
            v5->m_contactMgr,
            v35,
            v14->m_constraintOwner.m_storage);
          v5->m_contactPointId = -1;
        }
        return;
      }
      if ( v34 == 1 )
        v15->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                     v42,
                                                     _mm_unpackhi_ps(v42, v15->m_contact.m_separatingNormal.m_quad),
                                                     196);
    }
    if ( v5->m_contactPointId == -1 )
      v5->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                               v5->m_contactMgr,
                               v8,
                               v7,
                               v6,
                               v14,
                               0i64,
                               v15);
    v36 = v5->m_contactPointId;
    if ( v36 != -1 )
    {
      v15->m_contactPointId = v36;
      ++v14->m_firstFreeContactPoint.m_storage;
    }
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "Et";
    v40 = __rdtsc();
    v41 = (signed __int64)(v39 + 2);
    *(_DWORD *)(v41 - 8) = v40;
    v38[1] = v41;
  }
}

// File Line: 252
// RVA: 0xD20EC0
void __fastcall hkpSphereTriangleAgent::getClosestPoints(hkpSphereTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpSphereTriangleAgent *v5; // r15
  hkpCollisionInput *v6; // rbp
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // r14
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 *v13; // rax
  hkpShape *v14; // rbx
  hkpShape *v15; // r12
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  hkVector4f *v19; // rdi
  signed __int64 v20; // rcx
  __m128 v21; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v22; // rax
  char *v23; // rdx
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  hkpCdPointCollectorVtbl *v27; // rax
  __m128 v28; // xmm2
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+30h] [rbp-98h]
  hkVector4f tri; // [rsp+50h] [rbp-78h]
  __m128 v35; // [rsp+60h] [rbp-68h]
  __m128 v36; // [rsp+70h] [rbp-58h]
  hkpCdBody *v37; // [rsp+80h] [rbp-48h]
  hkpCdBody *v38; // [rsp+88h] [rbp-40h]
  unsigned int v39; // [rsp+D0h] [rbp+8h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtSphereTri";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = (__m128 *)v7->m_motion;
  v14 = v7->m_shape;
  v15 = v8->m_shape;
  v16 = *v13;
  v17 = v13[1];
  v18 = v13[2];
  v19 = (hkVector4f *)v8->m_motion;
  v20 = 2i64;
  v21 = v13[3];
  v22 = &v7->m_shape[2].m_type;
  v23 = (char *)((char *)&v36 - (char *)v7->m_shape);
  do
  {
    v24 = *(__m128 *)&v22->m_storage;
    v22 -= 16;
    --v20;
    *(__m128 *)&v22[(_QWORD)v23 - 64].m_storage = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v17),
                                                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v16)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v18)),
                                                    v21);
  }
  while ( v20 >= 0 );
  hkpCollideTriangleUtil::closestPointTriangle(v19 + 3, &tri, &v5->m_closestPointTriangleCache, &result, 0i64);
  v25 = _mm_shuffle_ps((__m128)LODWORD(result.distance), (__m128)LODWORD(result.distance), 0);
  *(float *)&v39 = *(float *)&v15[1].vfptr + *(float *)&v14[1].vfptr;
  v26 = _mm_shuffle_ps((__m128)v39, (__m128)v39, 0);
  if ( v25.m128_f32[0] < (float)(COERCE_FLOAT(
                                   _mm_shuffle_ps(
                                     (__m128)LODWORD(v6->m_tolerance.m_storage),
                                     (__m128)LODWORD(v6->m_tolerance.m_storage),
                                     0))
                               + v26.m128_f32[0]) )
  {
    v27 = collector->vfptr;
    v28 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v14[1].vfptr), (__m128)LODWORD(v14[1].vfptr), 0), v25),
              result.hitDirection.m_quad),
            v19[3].m_quad);
    v37 = v8;
    v38 = v7;
    tri.m_quad = v28;
    v35 = _mm_shuffle_ps(
            result.hitDirection.m_quad,
            _mm_unpackhi_ps(result.hitDirection.m_quad, _mm_sub_ps(v25, v26)),
            196);
    v36 = v35;
    v27->addCdPoint(collector, (hkpCdPoint *)&tri);
  }
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v31 = __rdtsc();
    v32 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v29[1] = v32;
  }
}v31 = __rdtsc();
    v32 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v29[1] 

// File Line: 268
// RVA: 0xD210C0
void __fastcall hkpSphereTriangleAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  __int64 *v4; // rbx
  hkpCdPointCollector *v5; // rsi
  hkpCollisionInput *v6; // r15
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkVector4f *v12; // r14
  hkVector4f *v13; // r13
  hkVector4f *v14; // r12
  __m128 *v15; // rax
  signed __int64 v16; // rcx
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 *v21; // rax
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  bool v25; // zf
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128i v28; // xmm3
  __int64 v29; // r8
  const void *v30; // rdx
  __int64 v31; // rax
  int v32; // eax
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  __m128 v37; // [rsp+40h] [rbp-69h]
  hkpCollideTriangleUtil::ClosestPointTriangleCache cache; // [rsp+50h] [rbp-59h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+60h] [rbp-49h]
  hkVector4f tri; // [rsp+80h] [rbp-29h]
  __m128 v41; // [rsp+90h] [rbp-19h]
  __m128i v42; // [rsp+A0h] [rbp-9h]
  __int64 *v43; // [rsp+B0h] [rbp+7h]
  hkpCdBody *v44; // [rsp+B8h] [rbp+Fh]
  float v45; // [rsp+110h] [rbp+67h]
  hkpFeatureOutput featureOutput; // [rsp+118h] [rbp+6Fh]
  __int64 v47; // [rsp+120h] [rbp+77h]

  v4 = (__int64 *)bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereTri";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (hkVector4f *)v7->m_shape;
  hkpCollideTriangleUtil::setupClosestPointTriangleCache((hkVector4f *)&v7->m_shape[1].m_type, &cache);
  v13 = (hkVector4f *)v7->m_shape;
  v14 = (hkVector4f *)v4[2];
  v47 = *v4;
  v15 = (__m128 *)v7->m_motion;
  v16 = 2i64;
  v17 = *v15;
  v18 = v15[1];
  v19 = v15[2];
  v20 = v15[3];
  v21 = &v13[5].m_quad;
  do
  {
    v22 = *v21;
    --v21;
    --v16;
    *(__m128 *)((char *)v21 + (char *)&v42 - (char *)v13 - 64) = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_add_ps(
                                                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v18),
                                                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v17)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v19)),
                                                                   v20);
  }
  while ( v16 >= 0 );
  hkpCollideTriangleUtil::closestPointTriangle(v14 + 3, &tri, &cache, &result, &featureOutput);
  v23 = _mm_shuffle_ps((__m128)LODWORD(result.distance), (__m128)LODWORD(result.distance), 0);
  v45 = *(float *)(v47 + 32) + v13[2].m_quad.m128_f32[0];
  v24 = _mm_shuffle_ps((__m128)LODWORD(v45), (__m128)LODWORD(v45), 0);
  v45 = v6->m_tolerance.m_storage;
  if ( v23.m128_f32[0] < (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v45), (__m128)LODWORD(v45), 0))
                               + v24.m128_f32[0]) )
  {
    v25 = v6->m_weldClosestPoints.m_storage == 0;
    v26 = (__m128)v13[2].m_quad.m128_u32[0];
    LOBYTE(v45) = featureOutput.numFeatures;
    v27 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v26, v26, 0), v23), result.hitDirection.m_quad),
            v14[3].m_quad);
    v28 = (__m128i)_mm_shuffle_ps(
                     result.hitDirection.m_quad,
                     _mm_unpackhi_ps(result.hitDirection.m_quad, _mm_sub_ps(v23, v24)),
                     196);
    v43 = v4;
    v44 = v7;
    tri.m_quad = v27;
    v41 = (__m128)v28;
    v42 = v28;
    if ( !v25 && featureOutput.numFeatures )
    {
      v29 = *v4;
      v30 = v7->m_motion;
      v31 = v4[2];
      _mm_store_si128((__m128i *)&v37, v28);
      _mm_store_si128((__m128i *)&result, (__m128i)v27);
      v32 = (*(__int64 (__fastcall **)(hkVector4f *, unsigned __int16 *, float *, hkpCollideTriangleUtil::ClosestPointTriangleResult *, const void *, __int64, __int64, __m128 *))(v12->m_quad.m128_u64[0] + 104))(
              v12,
              featureOutput.featureIds,
              &v45,
              &result,
              v30,
              v29,
              v31,
              &v37);
      if ( !v6->m_forceAcceptContactPoints.m_storage && !v32 )
        goto LABEL_13;
      if ( v32 == 1 )
        v41 = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v41), 196);
    }
    v5->vfptr->addCdPoint(v5, (hkpCdPoint *)&tri);
  }
LABEL_13:
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
}

// File Line: 313
// RVA: 0xD21330
void __fastcall hkpSphereTriangleAgent::getPenetrations(hkpSphereTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpSphereTriangleAgent *v5; // rbp
  hkpCdBody *v6; // rsi
  hkpCdBody *v7; // r14
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 *v13; // rcx
  hkpShape *v14; // rbx
  __m128 v15; // xmm3
  hkpShape *v16; // rdi
  hkVector4f *v17; // rdx
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  hkVector4f position; // [rsp+30h] [rbp-48h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+40h] [rbp-38h]
  unsigned int v27; // [rsp+80h] [rbp+8h]

  v5 = this;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereTri";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (__m128 *)v6->m_motion;
  v14 = v6->m_shape;
  v15 = v13[2];
  v16 = v7->m_shape;
  v17 = (hkVector4f *)&v6->m_shape[1].m_type;
  v18 = _mm_sub_ps(*((__m128 *)v7->m_motion + 3), v13[3]);
  v19 = _mm_unpacklo_ps(*v13, v13[1]);
  v20 = _mm_movelh_ps(v19, v15);
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v20, v19), v15, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v20)),
                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v13, v13[1]), v15, 228)));
  hkpCollideTriangleUtil::closestPointTriangle(&position, v17, &v5->m_closestPointTriangleCache, &result, 0i64);
  *(float *)&v27 = *(float *)&v14[1].vfptr + *(float *)&v16[1].vfptr;
  if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(result.distance), (__m128)LODWORD(result.distance), 0)) < COERCE_FLOAT(_mm_shuffle_ps((__m128)v27, (__m128)v27, 0)) )
    collector->vfptr->addCdBodyPair(collector, v7, v6);
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v21[1] = v24;
  }
}

// File Line: 341
// RVA: 0xD214A0
void __fastcall hkpSphereTriangleAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rbp
  hkpCdBodyPairCollector *v5; // r14
  hkpCdBody *v6; // r15
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkVector4f *v12; // rdi
  hkpShape *v13; // rsi
  __m128 *v14; // rcx
  __m128 v15; // xmm3
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  hkpCollideTriangleUtil::ClosestPointTriangleCache cache; // [rsp+30h] [rbp-58h]
  hkVector4f position; // [rsp+40h] [rbp-48h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+50h] [rbp-38h]
  unsigned int v26; // [rsp+90h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = bodyB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtSphereTri";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12 = (hkVector4f *)v6->m_shape;
  v13 = v4->m_shape;
  hkpCollideTriangleUtil::setupClosestPointTriangleCache((hkVector4f *)&v6->m_shape[1].m_type, &cache);
  v14 = (__m128 *)v6->m_motion;
  v15 = v14[2];
  v16 = _mm_sub_ps(*((__m128 *)v4->m_motion + 3), v14[3]);
  v17 = _mm_unpacklo_ps(*v14, v14[1]);
  v18 = _mm_movelh_ps(v17, v15);
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v15, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v18)),
                      _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v14, v14[1]), v15, 228)));
  hkpCollideTriangleUtil::closestPointTriangle(&position, v12 + 3, &cache, &result, 0i64);
  *(float *)&v26 = v12[2].m_quad.m128_f32[0] + *(float *)&v13[1].vfptr;
  if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(result.distance), (__m128)LODWORD(result.distance), 0)) < COERCE_FLOAT(_mm_shuffle_ps((__m128)v26, (__m128)v26, 0)) )
    v5->vfptr->addCdBodyPair(v5, v4, v6);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v21 = __rdtsc();
    v22 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v19[1] = v22;
  }
}

