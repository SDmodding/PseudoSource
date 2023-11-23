// File Line: 16
// RVA: 0xCF5000
void __fastcall hkpTransformAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpTransformAgent::createTransformBAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, TRANSFORM);
  f.m_createFunc = hkpTransformAgent::createTransformAAgent;
  f.m_getPenetrationsFunc = hkpTransformAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpTransformAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpTransformAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRANSFORM, ALL_SHAPE_TYPES);
}

// File Line: 58
// RVA: 0xCF57C0
void __fastcall hkpTransformAgent::cleanup(hkpTransformAgent *this, hkpConstraintOwner *constraintOwner)
{
  ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))this->m_childAgent->vfptr[3].__first_virtual_table_function__)(
    this->m_childAgent,
    constraintOwner);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 80
// RVA: 0xCF5940
hkpCollisionAgent *__fastcall hkpTransformAgent::createTransformAAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v10; // rbx
  hkVector4f *m_motion; // rdx
  hkpShape *m_shape; // rbp
  hkTransformf *v13; // rcx
  __int64 v14; // r14
  __int64 v15; // r8
  hkVector4f v16; // xmm0
  bool v17; // zf
  hkpCollisionDispatcher *m_storage; // r10
  hkpShape *v19; // rax
  __int64 v20; // rdx
  char (*m_agent2TypesPred)[35]; // rax
  __int64 v22; // [rsp+20h] [rbp-E8h] BYREF
  int v23; // [rsp+28h] [rbp-E0h]
  hkTransformf *v24; // [rsp+30h] [rbp-D8h]
  hkpCdBody *v25; // [rsp+38h] [rbp-D0h]
  hkTransformf Dst[2]; // [rsp+40h] [rbp-C8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  v10 = result;
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->m_contactMgr = mgr;
    result->vfptr = (hkBaseObjectVtbl *)&hkpTransformAgent::`vftable;
    m_motion = (hkVector4f *)bodyA->m_motion;
    m_shape = bodyA->m_shape;
    v13 = Dst;
    v14 = *(_QWORD *)&bodyA->m_shape[1].m_memSizeAndFlags;
    v15 = 1i64;
    if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
    {
      memmove(Dst, m_motion, 0xB0ui64);
    }
    else
    {
      do
      {
        v16.m_quad = m_motion->m_quad;
        v13 += 2;
        m_motion += 8;
        v13[-2].m_rotation.m_col0 = (hkVector4f)v16.m_quad;
        v13[-2].m_rotation.m_col1 = (hkVector4f)m_motion[-7].m_quad;
        v13[-2].m_rotation.m_col2 = (hkVector4f)m_motion[-6].m_quad;
        v13[-2].m_translation = (hkVector4f)m_motion[-5].m_quad;
        v13[-1].m_rotation.m_col0 = (hkVector4f)m_motion[-4].m_quad;
        v13[-1].m_rotation.m_col1 = (hkVector4f)m_motion[-3].m_quad;
        v13[-1].m_rotation.m_col2 = (hkVector4f)m_motion[-2].m_quad;
        v13[-1].m_translation = (hkVector4f)m_motion[-1].m_quad;
        --v15;
      }
      while ( v15 );
      v13->m_rotation.m_col0 = (hkVector4f)m_motion->m_quad;
      v13->m_rotation.m_col1 = (hkVector4f)m_motion[1].m_quad;
      v13->m_rotation.m_col2 = (hkVector4f)m_motion[2].m_quad;
    }
    hkTransformf::setMul(Dst, (hkTransformf *)bodyA->m_motion, (hkTransformf *)&m_shape[2].m_type);
    v17 = input->m_createPredictiveAgents.m_storage == 0;
    m_storage = input->m_dispatcher.m_storage;
    v22 = v14;
    v24 = Dst;
    v19 = bodyB->m_shape;
    v25 = bodyA;
    v23 = 0;
    v20 = (unsigned __int8)v19->m_type.m_storage;
    m_agent2TypesPred = m_storage->m_agent2TypesPred;
    if ( v17 )
      m_agent2TypesPred = m_storage->m_agent2Types;
    v10[1].vfptr = (hkBaseObjectVtbl *)m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v14 + 16)][v20]].m_createFunc(
                                         (hkpCdBody *)&v22,
                                         bodyB,
                                         input,
                                         mgr);
    return v10;
  }
  return result;
}

// File Line: 88
// RVA: 0xCF5B00
hkpCollisionAgent *__fastcall hkpTransformAgent::createTransformBAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v10; // rbx
  hkVector4f *m_motion; // rax
  hkpShape *m_shape; // rbp
  hkTransformf *v13; // rdx
  __int64 v14; // r14
  __int64 v15; // r8
  hkVector4f v16; // xmm0
  bool v17; // zf
  hkpCollisionDispatcher *m_storage; // r10
  hkpShape *v19; // rax
  __int64 v20; // rdx
  char (*m_agent2TypesPred)[35]; // rax
  __int64 v22; // [rsp+20h] [rbp-E8h] BYREF
  int v23; // [rsp+28h] [rbp-E0h]
  hkTransformf *v24; // [rsp+30h] [rbp-D8h]
  hkpCdBody *v25; // [rsp+38h] [rbp-D0h]
  hkTransformf Dst[2]; // [rsp+40h] [rbp-C8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  v10 = result;
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->m_contactMgr = mgr;
    result->vfptr = (hkBaseObjectVtbl *)&hkpTransformAgent::`vftable;
    m_motion = (hkVector4f *)bodyB->m_motion;
    m_shape = bodyB->m_shape;
    v13 = Dst;
    v14 = *(_QWORD *)&bodyB->m_shape[1].m_memSizeAndFlags;
    v15 = 1i64;
    if ( (((unsigned __int8)Dst | (unsigned __int8)m_motion) & 0xF) != 0 )
    {
      memmove(Dst, m_motion, 0xB0ui64);
    }
    else
    {
      do
      {
        v16.m_quad = m_motion->m_quad;
        v13 += 2;
        m_motion += 8;
        v13[-2].m_rotation.m_col0 = (hkVector4f)v16.m_quad;
        v13[-2].m_rotation.m_col1 = (hkVector4f)m_motion[-7].m_quad;
        v13[-2].m_rotation.m_col2 = (hkVector4f)m_motion[-6].m_quad;
        v13[-2].m_translation = (hkVector4f)m_motion[-5].m_quad;
        v13[-1].m_rotation.m_col0 = (hkVector4f)m_motion[-4].m_quad;
        v13[-1].m_rotation.m_col1 = (hkVector4f)m_motion[-3].m_quad;
        v13[-1].m_rotation.m_col2 = (hkVector4f)m_motion[-2].m_quad;
        v13[-1].m_translation = (hkVector4f)m_motion[-1].m_quad;
        --v15;
      }
      while ( v15 );
      v13->m_rotation.m_col0 = (hkVector4f)m_motion->m_quad;
      v13->m_rotation.m_col1 = (hkVector4f)m_motion[1].m_quad;
      v13->m_rotation.m_col2 = (hkVector4f)m_motion[2].m_quad;
    }
    hkTransformf::setMul(Dst, (hkTransformf *)bodyB->m_motion, (hkTransformf *)&m_shape[2].m_type);
    v17 = input->m_createPredictiveAgents.m_storage == 0;
    m_storage = input->m_dispatcher.m_storage;
    v22 = v14;
    v24 = Dst;
    v19 = bodyA->m_shape;
    v25 = bodyB;
    v23 = 0;
    v20 = (unsigned __int8)v19->m_type.m_storage;
    m_agent2TypesPred = m_storage->m_agent2TypesPred;
    if ( v17 )
      m_agent2TypesPred = m_storage->m_agent2Types;
    v10[1].vfptr = (hkBaseObjectVtbl *)m_storage->m_agent2Func[(unsigned __int8)m_agent2TypesPred[*(unsigned __int8 *)(v14 + 16)][v20]].m_createFunc(
                                         (hkpCdBody *)&v22,
                                         bodyA,
                                         input,
                                         mgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpTransformAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 94
// RVA: 0xCF50B0
void __fastcall hkpTransformAgent::processCollision(
        hkpTransformAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpShape *m_shape; // rdi
  const void *m_motion; // rax
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm6
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm3
  __m128 v28; // xmm6
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  hkpCollisionAgent *m_childAgent; // rcx
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *v41; // rcx
  __int64 v42; // [rsp+30h] [rbp-F8h] BYREF
  int v43; // [rsp+38h] [rbp-F0h]
  hkTransformf *v44; // [rsp+40h] [rbp-E8h]
  hkpCdBody *v45; // [rsp+48h] [rbp-E0h]
  hkTransformf v46; // [rsp+50h] [rbp-D8h] BYREF
  __int128 v47; // [rsp+90h] [rbp-98h]
  __int128 v48; // [rsp+A0h] [rbp-88h]
  __m128 v49; // [rsp+B0h] [rbp-78h]
  __m128 v50; // [rsp+C0h] [rbp-68h]
  __m128 v51; // [rsp+D0h] [rbp-58h]
  __int128 v52; // [rsp+E0h] [rbp-48h]
  int v53; // [rsp+F0h] [rbp-38h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtTransform";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v46, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_motion = bodyAin->m_motion;
  v47 = *((_OWORD *)m_motion + 4);
  v48 = *((_OWORD *)m_motion + 5);
  v15 = *((__m128 *)m_motion + 6);
  v16 = (__m128)m_shape[2].hkReferencedObject;
  v17 = _mm_shuffle_ps(v16, v16, 255);
  v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
  v19 = _mm_mul_ps(v16, v15);
  v20 = _mm_shuffle_ps(v15, v15, 255);
  v21 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps((__m128)m_shape[2].hkReferencedObject, v20)),
          _mm_mul_ps(v15, v17));
  v49 = _mm_shuffle_ps(
          v21,
          _mm_unpackhi_ps(
            v21,
            _mm_sub_ps(
              _mm_mul_ps(v17, v20),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170)))),
          196);
  v22 = *((__m128 *)m_motion + 7);
  v23 = (__m128)m_shape[2].hkReferencedObject;
  v24 = _mm_shuffle_ps(v22, v22, 255);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23);
  v26 = _mm_shuffle_ps(v23, v23, 255);
  v27 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22);
  v28 = _mm_mul_ps(v22, v23);
  v29 = _mm_sub_ps(v27, v25);
  v30 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(v24, v23)),
          _mm_mul_ps(*((__m128 *)m_motion + 7), v26));
  v50 = _mm_shuffle_ps(
          v30,
          _mm_unpackhi_ps(
            v30,
            _mm_sub_ps(
              _mm_mul_ps(v26, v24),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170)))),
          196);
  v31 = _mm_sub_ps(*((__m128 *)m_motion + 8), (__m128)m_shape[4].hkReferencedObject);
  v32 = *(__m128 *)&m_shape[3].m_type.m_storage;
  m_childAgent = this->m_childAgent;
  v34 = *(__m128 *)&m_shape[2].m_type.m_storage;
  v35 = _mm_unpackhi_ps(v34, (__m128)m_shape[3].hkReferencedObject);
  v36 = _mm_unpacklo_ps(v34, (__m128)m_shape[3].hkReferencedObject);
  v37 = _mm_movelh_ps(v36, v32);
  v51 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(_mm_movehl_ps(v37, v36), v32, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v37)),
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), _mm_shuffle_ps(v35, v32, 228)));
  v52 = *((_OWORD *)m_motion + 9);
  v36.m128_i32[0] = *((_DWORD *)m_motion + 40);
  v45 = bodyAin;
  v44 = &v46;
  v53 = v36.m128_i32[0];
  v42 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v43 = 0;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))m_childAgent->vfptr[3].__vecDelDtor)(
    m_childAgent,
    &v42,
    bodyB,
    input,
    result);
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "Et";
    v40 = __rdtsc();
    v41 = v39 + 2;
    *((_DWORD *)v41 - 2) = v40;
    v38[1] = v41;
  }
}

// File Line: 137
// RVA: 0xCF5350
void __fastcall hkpTransformAgent::linearCast(
        hkpTransformAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpShape *m_shape; // rdi
  hkpCollisionAgent *m_childAgent; // rcx
  __int64 v12; // rax
  __int64 v13; // [rsp+30h] [rbp-68h] BYREF
  int v14; // [rsp+38h] [rbp-60h]
  hkTransformf *v15; // [rsp+40h] [rbp-58h]
  hkpCdBody *v16; // [rsp+48h] [rbp-50h]
  hkTransformf v17; // [rsp+50h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v17, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_childAgent = this->m_childAgent;
  v16 = bodyAin;
  v15 = &v17;
  v12 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v14 = 0;
  v13 = v12;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *))m_childAgent->vfptr[2].__first_virtual_table_function__)(
    m_childAgent,
    &v13,
    bodyB,
    input,
    collector,
    startCollector);
}

// File Line: 154
// RVA: 0xCF5410
void __fastcall hkpTransformAgent::staticLinearCast(
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpShape *m_shape; // rdi
  hkpCollisionDispatcher *m_storage; // r11
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h] BYREF
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_storage = input->m_dispatcher.m_storage;
  v15 = bodyAin;
  v14 = &v16;
  v11 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[*(unsigned __int8 *)(v11 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_linearCastFunc(
    (hkpCdBody *)&v12,
    bodyB,
    input,
    collector,
    startCollector);
}

// File Line: 178
// RVA: 0xCF54E0
void __fastcall hkpTransformAgent::getClosestPoints(
        hkpTransformAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *pointDetails)
{
  hkpShape *m_shape; // rdi
  hkpCollisionAgent *m_childAgent; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h] BYREF
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_childAgent = this->m_childAgent;
  v15 = bodyAin;
  v14 = &v16;
  v11 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))m_childAgent->vfptr[2].__vecDelDtor)(
    m_childAgent,
    &v12,
    bodyB,
    input,
    pointDetails);
}

// File Line: 195
// RVA: 0xCF5590
void __fastcall hkpTransformAgent::staticGetClosestPoints(
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *pointDetails)
{
  hkpShape *m_shape; // rdi
  hkpCollisionDispatcher *m_storage; // r10
  __int64 v10; // rax
  __int64 v11; // [rsp+20h] [rbp-68h] BYREF
  int v12; // [rsp+28h] [rbp-60h]
  hkTransformf *v13; // [rsp+30h] [rbp-58h]
  hkpCdBody *v14; // [rsp+38h] [rbp-50h]
  hkTransformf v15; // [rsp+40h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v15, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_storage = input->m_dispatcher.m_storage;
  v14 = bodyAin;
  v13 = &v15;
  v10 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v12 = 0;
  v11 = v10;
  m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[*(unsigned __int8 *)(v10 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_getClosestPointFunc(
    (hkpCdBody *)&v11,
    bodyB,
    input,
    pointDetails);
}

// File Line: 220
// RVA: 0xCF5650
void __fastcall hkpTransformAgent::getPenetrations(
        hkpTransformAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpShape *m_shape; // rdi
  hkpCollisionAgent *m_childAgent; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h] BYREF
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_childAgent = this->m_childAgent;
  v15 = bodyAin;
  v14 = &v16;
  v11 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))m_childAgent->vfptr[1].__first_virtual_table_function__)(
    m_childAgent,
    &v12,
    bodyB,
    input,
    collector);
}

// File Line: 235
// RVA: 0xCF5700
void __fastcall hkpTransformAgent::staticGetPenetrations(
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpShape *m_shape; // rdi
  hkpCollisionDispatcher *m_storage; // r10
  __int64 v10; // rax
  __int64 v11; // [rsp+20h] [rbp-68h] BYREF
  int v12; // [rsp+28h] [rbp-60h]
  hkTransformf *v13; // [rsp+30h] [rbp-58h]
  hkpCdBody *v14; // [rsp+38h] [rbp-50h]
  hkTransformf v15; // [rsp+40h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v15, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_storage = input->m_dispatcher.m_storage;
  v14 = bodyAin;
  v13 = &v15;
  v10 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v12 = 0;
  v11 = v10;
  m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[*(unsigned __int8 *)(v10 + 16)][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_getPenetrationsFunc(
    (hkpCdBody *)&v11,
    bodyB,
    input,
    collector);
}

// File Line: 254
// RVA: 0xCF5890
void __fastcall hkpTransformAgent::updateShapeCollectionFilter(
        hkpTransformAgent *this,
        hkpCdBody *bodyAin,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  hkpShape *m_shape; // rdi
  hkpCollisionAgent *m_childAgent; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h] BYREF
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h] BYREF

  m_shape = bodyAin->m_shape;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  m_childAgent = this->m_childAgent;
  v15 = bodyAin;
  v14 = &v16;
  v11 = *(_QWORD *)&m_shape[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))m_childAgent->vfptr[4].__vecDelDtor)(
    m_childAgent,
    &v12,
    bodyB,
    input,
    constraintOwner);
}

// File Line: 267
// RVA: 0xCF57F0
void __fastcall hkpTransformAgent::invalidateTim(hkpTransformAgent *this, hkpCollisionInput *input)
{
  ((void (__fastcall *)(hkpCollisionAgent *, hkpCollisionInput *))this->m_childAgent->vfptr[4].__first_virtual_table_function__)(
    this->m_childAgent,
    input);
}

// File Line: 272
// RVA: 0xCF5810
void __fastcall hkpTransformAgent::warpTime(
        hkpTransformAgent *this,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  __int64 v4; // rdx
  __int64 v5; // r8

  ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))this->m_childAgent->vfptr[5].__vecDelDtor)(
    this->m_childAgent,
    v4,
    v5,
    input);
}

// File Line: 277
// RVA: 0xCF5830
void __fastcall hkpTransformAgent::removePoint(hkpTransformAgent *this, __int64 idToRemove)
{
  ((void (__fastcall *)(hkpCollisionAgent *, __int64))this->m_childAgent->vfptr[5].__first_virtual_table_function__)(
    this->m_childAgent,
    idToRemove);
}

// File Line: 282
// RVA: 0xCF5850
void __fastcall hkpTransformAgent::commitPotential(hkpTransformAgent *this, __int64 newId)
{
  this->m_childAgent->vfptr[6].__vecDelDtor(this->m_childAgent, newId);
}

// File Line: 287
// RVA: 0xCF5870
void __fastcall hkpTransformAgent::createZombie(hkpTransformAgent *this, __int64 idTobecomeZombie)
{
  ((void (__fastcall *)(hkpCollisionAgent *, __int64))this->m_childAgent->vfptr[6].__first_virtual_table_function__)(
    this->m_childAgent,
    idTobecomeZombie);
}

