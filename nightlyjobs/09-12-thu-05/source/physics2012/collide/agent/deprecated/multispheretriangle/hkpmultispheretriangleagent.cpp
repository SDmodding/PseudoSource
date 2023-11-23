// File Line: 19
// RVA: 0xD25270
void __fastcall hkpMultiSphereTriangleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpMultiSphereTriangleAgent::createTriangleMultiSphereAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRIANGLE, MULTI_SPHERE);
  f.m_createFunc = hkpMultiSphereTriangleAgent::createMultiSphereTriangleAgent;
  f.m_getPenetrationsFunc = hkpMultiSphereTriangleAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpMultiSphereTriangleAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, MULTI_SPHERE, TRIANGLE);
}

// File Line: 57
// RVA: 0xD25D10
hkpCollisionAgent *__fastcall hkpMultiSphereTriangleAgent::createTriangleMultiSphereAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = contactMgr;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereTriangleAgent::`vftable;
    result[1].m_contactMgr = (hkpContactMgr *)-1i64;
    result[2].vfptr = (hkBaseObjectVtbl *)-1i64;
    hkpCollideTriangleUtil::setupClosestPointTriangleCache(
      (hkVector4f *)&bodyA->m_shape[1].m_type,
      (hkpCollideTriangleUtil::ClosestPointTriangleCache *)&result[1]);
    v8->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::`vftable;
    return v8;
  }
  return result;
}

// File Line: 63
// RVA: 0xD25C60
hkpCollisionAgent *__fastcall hkpMultiSphereTriangleAgent::createMultiSphereTriangleAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = contactMgr;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereTriangleAgent::`vftable;
    result[1].m_contactMgr = (hkpContactMgr *)-1i64;
    result[2].vfptr = (hkBaseObjectVtbl *)-1i64;
    hkpCollideTriangleUtil::setupClosestPointTriangleCache(
      (hkVector4f *)&bodyB->m_shape[1].m_type,
      (hkpCollideTriangleUtil::ClosestPointTriangleCache *)&result[1]);
    return v8;
  }
  return result;
}

// File Line: 73
// RVA: 0xD25BE0
void __fastcall hkpMultiSphereTriangleAgent::cleanup(
        hkpMultiSphereTriangleAgent *this,
        hkpConstraintOwner *constraintOwner)
{
  unsigned __int16 *m_contactPointId; // rbx
  __int64 v5; // rdi
  __int64 v6; // rdx

  m_contactPointId = this->m_contactPointId;
  v5 = 8i64;
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

// File Line: 86
// RVA: 0xD25F00
void __fastcall hkpMultiSphereTriangleAgent::processCollision(
        hkpMultiSphereTriangleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r9
  hkpShape *v16; // r10
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 *p_m_type; // rax
  __int64 v22; // rdx
  signed __int64 v23; // r8
  __m128 v24; // xmm1
  __m128 *v25; // rax
  int v26; // r14d
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm5
  __int64 v30; // rcx
  __m128 v31; // xmm6
  __m128 *v32; // rax
  __m128 v33; // xmm1
  hkVector4f *p_position; // rdi
  unsigned __int16 *v35; // rbx
  __int64 v36; // r12
  hkpCollideTriangleUtil::ClosestPointTriangleCache *p_m_closestPointTriangleCache; // rcx
  float v38; // xmm6_4
  hkpProcessCdPoint *m_storage; // rbp
  unsigned __int16 v40; // ax
  __int64 v41; // rdx
  _QWORD *v42; // rax
  _QWORD *v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  hkpShape *v47; // [rsp+48h] [rbp-120h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult v48; // [rsp+50h] [rbp-118h] BYREF
  hkVector4f tri; // [rsp+70h] [rbp-F8h] BYREF
  hkVector4f position; // [rsp+A0h] [rbp-C8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtMultiSphereTri";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v16 = bodyA->m_shape;
  v17 = *m_motion;
  v18 = m_motion[1];
  v19 = m_motion[2];
  v47 = bodyB->m_shape;
  v20 = m_motion[3];
  p_m_type = (__m128 *)&bodyB->m_shape[2].m_type;
  v22 = 2i64;
  v23 = (char *)&tri - (char *)&bodyB->m_shape[1].m_type;
  do
  {
    v24 = *p_m_type--;
    --v22;
    *(__m128 *)((char *)p_m_type + v23 + 16) = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v18),
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v17)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v19)),
                                                 v20);
  }
  while ( v22 >= 0 );
  v25 = (__m128 *)bodyA->m_motion;
  v26 = LODWORD(v16[1].vfptr) - 1;
  v27 = *v25;
  v28 = v25[1];
  v29 = v25[2];
  v30 = v26;
  v31 = v25[3];
  v32 = (__m128 *)(&v16[1].m_type + 16 * v26);
  do
  {
    v33 = *v32--;
    --v30;
    *(__m128 *)((char *)v32 + (char *)&position - (char *)&v16[1].m_type + 16) = _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v33, v33, 85),
                                                                                         v28),
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v33, v33, 0),
                                                                                         v27)),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(v33, v33, 170),
                                                                                       v29)),
                                                                                   v31);
  }
  while ( v30 >= 0 );
  p_position = &position;
  if ( v26 >= 0 )
  {
    v35 = &this->m_contactPointId[v26];
    v36 = &v16[1].m_type - (hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *)&position;
    p_m_closestPointTriangleCache = &this->m_closestPointTriangleCache;
    do
    {
      v38 = *(float *)((char *)&p_position->m_quad.m128_f32[3] + v36) + *(float *)&m_shape[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(p_position, &tri, p_m_closestPointTriangleCache, &v48, 0i64);
      if ( v48.distance >= (float)(v38 + input->m_tolerance.m_storage) )
      {
        v41 = *v35;
        if ( (_WORD)v41 != 0xFFFF )
        {
          ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
            this->m_contactMgr,
            v41,
            result->m_constraintOwner.m_storage);
          *v35 = -1;
        }
      }
      else
      {
        m_storage = result->m_firstFreeContactPoint.m_storage;
        m_storage->m_contact.m_position.m_quad = _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       (__m128)COERCE_UNSIGNED_INT(*(float *)&v47[1].vfptr - v48.distance),
                                                       (__m128)COERCE_UNSIGNED_INT(*(float *)&v47[1].vfptr - v48.distance),
                                                       0),
                                                     v48.hitDirection.m_quad),
                                                   p_position->m_quad);
        m_storage->m_contact.m_separatingNormal = v48.hitDirection;
        m_storage->m_contact.m_separatingNormal.m_quad.m128_f32[3] = v48.distance - v38;
        if ( *v35 != 0xFFFF
          || (v40 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                      this->m_contactMgr,
                      bodyA,
                      bodyB,
                      input,
                      result,
                      0i64,
                      m_storage),
              *v35 = v40,
              v40 != 0xFFFF) )
        {
          ++result->m_firstFreeContactPoint.m_storage;
          m_storage->m_contactPointId = *v35;
        }
      }
      m_shape = v47;
      ++p_position;
      --v35;
      --v26;
      p_m_closestPointTriangleCache = &this->m_closestPointTriangleCache;
    }
    while ( v26 >= 0 );
  }
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  v44 = v42;
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Et";
    v45 = __rdtsc();
    v46 = v43 + 2;
    *((_DWORD *)v46 - 2) = v45;
    v44[1] = v46;
  }
}

// File Line: 185
// RVA: 0xD25690
void __fastcall hkpMultiSphereTriangleAgent::getClosestPoints(
        hkpMultiSphereTriangleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  __int64 v5; // rbx
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  __m128 *m_motion; // rax
  hkpShape *m_shape; // r14
  hkpShape *v17; // r9
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *p_m_type; // rcx
  __int64 v22; // rdx
  __m128 v23; // xmm6
  __m128 *v24; // rax
  __m128 v25; // xmm1
  __m128 *v26; // rax
  __int64 vfptr_low; // r8
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __int64 v32; // rcx
  __m128 *v33; // rax
  __m128 v34; // xmm1
  __int64 v35; // rdi
  __int64 v36; // rsi
  hkVector4f *p_position; // rbx
  float v38; // xmm6_4
  unsigned int v39; // xmm0_4
  __int64 v40; // rax
  __m128 v41; // xmm1
  _QWORD *v42; // rax
  _QWORD *v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  hkVector4f v47; // [rsp+50h] [rbp-A8h]
  __m128 v48; // [rsp+60h] [rbp-98h] BYREF
  _QWORD v49[5]; // [rsp+70h] [rbp-88h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f tri; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f position; // [rsp+E8h] [rbp-10h] BYREF
  __int64 v53; // [rsp+1C0h] [rbp+C8h]
  __int64 *v55; // [rsp+1D8h] [rbp+E0h]

  v53 = v5;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtMultiSphereTriangle";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v17 = bodyA->m_shape;
  v18 = *m_motion;
  v19 = m_motion[1];
  v20 = m_motion[2];
  p_m_type = &bodyB->m_shape[1].m_type;
  v22 = 2i64;
  v23 = m_motion[3];
  v24 = (__m128 *)&bodyB->m_shape[2].m_type;
  do
  {
    v25 = *v24--;
    --v22;
    *(__m128 *)((char *)v24 + (char *)&tri - (char *)p_m_type + 16) = _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v25, v25, 85),
                                                                              v19),
                                                                            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v18)),
                                                                          _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v20)),
                                                                        v23);
  }
  while ( v22 >= 0 );
  v26 = (__m128 *)bodyA->m_motion;
  vfptr_low = SLODWORD(v17[1].vfptr);
  v28 = *v26;
  v29 = v26[1];
  v30 = v26[2];
  v31 = v26[3];
  v32 = (int)vfptr_low - 1;
  v33 = (__m128 *)(&v17[1].m_type + 16 * v32);
  do
  {
    v34 = *v33--;
    --v32;
    *(__m128 *)((char *)v33 + (char *)&position - (char *)&v17[1].m_type + 16) = _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v34, v34, 85),
                                                                                         v29),
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v34, v34, 0),
                                                                                         v28)),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(v34, v34, 170),
                                                                                       v30)),
                                                                                   v31);
  }
  while ( v32 >= 0 );
  v35 = vfptr_low;
  if ( (int)vfptr_low > 0 )
  {
    v36 = &v17[1].m_type - (hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *)&position;
    p_position = &position;
    do
    {
      v38 = *(float *)((char *)&p_position->m_quad.m128_f32[3] + v36) + *(float *)&m_shape[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(p_position, &tri, &this->m_closestPointTriangleCache, &result, 0i64);
      if ( result.distance < (float)(v38 + input->m_tolerance.m_storage) )
      {
        *(float *)&v39 = *(float *)&m_shape[1].vfptr - result.distance;
        v49[3] = v53;
        v49[4] = bodyA;
        v40 = *v55;
        v47.m_quad = (__m128)result.hitDirection;
        v47.m_quad.m128_f32[3] = result.distance - v38;
        v41 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)v39, (__m128)v39, 0), result.hitDirection.m_quad),
                p_position->m_quad);
        v49[0] = result.hitDirection.m_quad.m128_u64[0];
        *(hkVector4f *)&v49[1] = (hkVector4f)v47.m_quad;
        v48 = v41;
        (*(void (__fastcall **)(__int64 *, __m128 *))(v40 + 8))(v55, &v48);
      }
      ++p_position;
      --v35;
    }
    while ( v35 );
  }
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  v44 = v42;
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Et";
    v45 = __rdtsc();
    v46 = v43 + 2;
    *((_DWORD *)v46 - 2) = v45;
    v44[1] = v46;
  }
}

// File Line: 233
// RVA: 0xD25950
void __fastcall hkpMultiSphereTriangleAgent::staticGetClosestPoints(
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
  hkpShape *m_shape; // r14
  hkpShape *v14; // r8
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *p_m_type; // r9
  __int64 v19; // rcx
  __m128 v20; // xmm6
  __m128 *v21; // rax
  __m128 v22; // xmm1
  __m128 *v23; // rax
  __int64 vfptr_low; // rdi
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v25; // rsi
  __m128 v26; // xmm3
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __int64 v30; // rdx
  __m128 *v31; // rax
  char *v32; // r8
  __m128 v33; // xmm1
  hkVector4f *p_position; // rbx
  signed __int64 v35; // rsi
  float v36; // xmm6_4
  unsigned int v37; // xmm0_4
  hkpCdPointCollectorVtbl *vfptr; // rax
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  _QWORD *v42; // rcx
  hkpCollideTriangleUtil::ClosestPointTriangleCache cache; // [rsp+30h] [rbp-D0h] BYREF
  hkVector4f v44; // [rsp+50h] [rbp-B0h]
  __int128 v45[3]; // [rsp+60h] [rbp-A0h] BYREF
  hkpCdBody *v46; // [rsp+90h] [rbp-70h]
  hkpCdBody *v47; // [rsp+98h] [rbp-68h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+A0h] [rbp-60h] BYREF
  hkVector4f tri; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f position; // [rsp+F0h] [rbp-10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtMultiSphereTriangle";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v14 = bodyA->m_shape;
  v15 = *m_motion;
  v16 = m_motion[1];
  v17 = m_motion[2];
  p_m_type = (hkVector4f *)&bodyB->m_shape[1].m_type;
  v19 = 2i64;
  v20 = m_motion[3];
  v21 = (__m128 *)&bodyB->m_shape[2].m_type;
  do
  {
    v22 = *v21--;
    --v19;
    *(__m128 *)((char *)v21 + (char *)&tri - (char *)p_m_type + 16) = _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v22, v22, 85),
                                                                              v16),
                                                                            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v15)),
                                                                          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v17)),
                                                                        v20);
  }
  while ( v19 >= 0 );
  v23 = (__m128 *)bodyA->m_motion;
  vfptr_low = SLODWORD(v14[1].vfptr);
  v25 = &v14[1].m_type;
  v26 = *v23;
  v27 = v23[1];
  v28 = v23[2];
  v29 = v23[3];
  v30 = (int)vfptr_low - 1;
  v31 = (__m128 *)(&v14[1].m_type + 16 * v30);
  v32 = (char *)((char *)&position - (char *)&v14[1].m_type);
  do
  {
    v33 = *v31--;
    --v30;
    *(__m128 *)((char *)v31 + (_QWORD)v32 + 16) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v27),
                                                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v26)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v28)),
                                                    v29);
  }
  while ( v30 >= 0 );
  hkpCollideTriangleUtil::setupClosestPointTriangleCache(p_m_type, &cache);
  if ( vfptr_low > 0 )
  {
    p_position = &position;
    v35 = v25 - (hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *)&position;
    do
    {
      v36 = *(float *)((char *)&p_position->m_quad.m128_f32[3] + v35) + *(float *)&m_shape[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(p_position, &tri, &cache, &result, 0i64);
      if ( result.distance < (float)(v36 + input->m_tolerance.m_storage) )
      {
        *(float *)&v37 = *(float *)&m_shape[1].vfptr - result.distance;
        v46 = bodyA;
        vfptr = collector->vfptr;
        v47 = bodyB;
        v44.m_quad = (__m128)result.hitDirection;
        v44.m_quad.m128_f32[3] = result.distance - v36;
        v45[1] = (__int128)v44.m_quad;
        v45[2] = (__int128)v44.m_quad;
        v45[0] = (__int128)_mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps((__m128)v37, (__m128)v37, 0), result.hitDirection.m_quad),
                             p_position->m_quad);
        vfptr->addCdPoint(collector, (hkpCdPoint *)v45);
      }
      ++p_position;
      --vfptr_low;
    }
    while ( vfptr_low );
  }
  v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v40 = (_QWORD *)v39[1];
  if ( (unsigned __int64)v40 < v39[3] )
  {
    *v40 = "Et";
    v41 = __rdtsc();
    v42 = v40 + 2;
    *((_DWORD *)v42 - 2) = v41;
    v39[1] = v42;
  }
}

// File Line: 286
// RVA: 0xD25320
void __fastcall hkpMultiSphereTriangleAgent::getPenetrations(
        hkpMultiSphereTriangleAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpShape *m_shape; // r10
  hkpShape *v6; // r15
  __m128 *m_motion; // rax
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *p_m_type; // r9
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __int64 v15; // rcx
  __m128 v16; // xmm6
  __m128 *v17; // rax
  __m128 v18; // xmm1
  __m128 *v19; // rax
  __int64 vfptr_low; // r8
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __int64 v25; // rcx
  __m128 *v26; // rax
  __m128 v27; // xmm1
  int v28; // edi
  __int64 v29; // rbx
  __int64 v30; // rbp
  float *i; // rsi
  float v32; // xmm6_4
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+30h] [rbp-108h] BYREF
  hkVector4f tri; // [rsp+50h] [rbp-E8h] BYREF
  _OWORD v35[9]; // [rsp+80h] [rbp-B8h] BYREF

  m_shape = bodyA->m_shape;
  v6 = bodyB->m_shape;
  m_motion = (__m128 *)bodyB->m_motion;
  p_m_type = &bodyB->m_shape[1].m_type;
  v12 = *m_motion;
  v13 = m_motion[1];
  v14 = m_motion[2];
  v15 = 2i64;
  v16 = m_motion[3];
  v17 = (__m128 *)&bodyB->m_shape[2].m_type;
  do
  {
    v18 = *v17--;
    --v15;
    *(__m128 *)((char *)v17 + (char *)&tri - (char *)p_m_type + 16) = _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v18, v18, 85),
                                                                              v13),
                                                                            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v12)),
                                                                          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v14)),
                                                                        v16);
  }
  while ( v15 >= 0 );
  v19 = (__m128 *)bodyA->m_motion;
  vfptr_low = SLODWORD(m_shape[1].vfptr);
  v21 = *v19;
  v22 = v19[1];
  v23 = v19[2];
  v24 = v19[3];
  v25 = (int)vfptr_low - 1;
  v26 = (__m128 *)(&m_shape[1].m_type + 16 * v25);
  do
  {
    v27 = *v26--;
    --v25;
    *(__m128 *)((char *)v26 + (char *)v35 - (char *)&m_shape[1].m_type + 16) = _mm_add_ps(
                                                                                 _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(v27, v27, 85),
                                                                                       v22),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(v27, v27, 0),
                                                                                       v21)),
                                                                                   _mm_mul_ps(
                                                                                     _mm_shuffle_ps(v27, v27, 170),
                                                                                     v23)),
                                                                                 v24);
  }
  while ( v25 >= 0 );
  v28 = 0;
  v29 = 0i64;
  v30 = vfptr_low;
  if ( (int)vfptr_low > 0 )
  {
    for ( i = (float *)&m_shape[1].m_userData + 1; ; i += 4 )
    {
      v32 = *i + *(float *)&v6[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(
        (hkVector4f *)&v35[v28],
        &tri,
        &this->m_closestPointTriangleCache,
        &result,
        0i64);
      if ( result.distance < v32 )
        break;
      ++v29;
      ++v28;
      if ( v29 >= v30 )
        return;
    }
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  }
}

// File Line: 325
// RVA: 0xD254E0
void __fastcall hkpMultiSphereTriangleAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpShape *m_shape; // r14
  hkpShape *v5; // r8
  __m128 *m_motion; // rax
  hkVector4f *p_m_type; // r10
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __int64 v14; // rcx
  __m128 v15; // xmm6
  __m128 *v16; // rax
  __m128 v17; // xmm1
  __m128 *v18; // rax
  __int64 vfptr_low; // rbp
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v20; // rdi
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __int64 v25; // rdx
  __m128 *v26; // rax
  char *v27; // r8
  __m128 v28; // xmm1
  int v29; // esi
  __int64 v30; // rbx
  float *i; // rdi
  float v32; // xmm6_4
  hkpCollideTriangleUtil::ClosestPointTriangleCache cache; // [rsp+30h] [rbp-118h] BYREF
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+40h] [rbp-108h] BYREF
  hkVector4f tri; // [rsp+60h] [rbp-E8h] BYREF
  _OWORD v36[9]; // [rsp+90h] [rbp-B8h] BYREF

  m_shape = bodyB->m_shape;
  v5 = bodyA->m_shape;
  m_motion = (__m128 *)bodyB->m_motion;
  p_m_type = (hkVector4f *)&bodyB->m_shape[1].m_type;
  v11 = *m_motion;
  v12 = m_motion[1];
  v13 = m_motion[2];
  v14 = 2i64;
  v15 = m_motion[3];
  v16 = (__m128 *)&bodyB->m_shape[2].m_type;
  do
  {
    v17 = *v16--;
    --v14;
    *(__m128 *)((char *)v16 + (char *)&tri - (char *)p_m_type + 16) = _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v17, v17, 85),
                                                                              v12),
                                                                            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v11)),
                                                                          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v13)),
                                                                        v15);
  }
  while ( v14 >= 0 );
  v18 = (__m128 *)bodyA->m_motion;
  vfptr_low = SLODWORD(v5[1].vfptr);
  v20 = &v5[1].m_type;
  v21 = *v18;
  v22 = v18[1];
  v23 = v18[2];
  v24 = v18[3];
  v25 = (int)vfptr_low - 1;
  v26 = (__m128 *)(&v5[1].m_type + 16 * v25);
  v27 = (char *)((char *)v36 - (char *)&v5[1].m_type);
  do
  {
    v28 = *v26--;
    --v25;
    *(__m128 *)((char *)v26 + (_QWORD)v27 + 16) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), v22),
                                                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v21)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v23)),
                                                    v24);
  }
  while ( v25 >= 0 );
  hkpCollideTriangleUtil::setupClosestPointTriangleCache(p_m_type, &cache);
  v29 = 0;
  v30 = 0i64;
  if ( vfptr_low > 0 )
  {
    for ( i = (float *)&v20[12].m_storage; ; i += 4 )
    {
      v32 = *i + *(float *)&m_shape[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle((hkVector4f *)&v36[v29], &tri, &cache, &result, 0i64);
      if ( result.distance < v32 )
        break;
      ++v30;
      ++v29;
      if ( v30 >= vfptr_low )
        return;
    }
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  }
}

