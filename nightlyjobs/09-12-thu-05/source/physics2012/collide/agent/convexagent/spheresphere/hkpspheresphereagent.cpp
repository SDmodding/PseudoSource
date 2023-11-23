// File Line: 19
// RVA: 0xD1F1F0
void __fastcall hkpSphereSphereAgent::initAgentFunc(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpSphereSphereAgent::createSphereSphereAgent;
  af->m_getPenetrationsFunc = hkpSphereSphereAgent::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpSphereSphereAgent::staticGetClosestPoints;
  af->m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
}

// File Line: 40
// RVA: 0xD1F230
void __fastcall hkpSphereSphereAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereSphereAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, SPHERE, SPHERE);
}

// File Line: 47
// RVA: 0xD1F270
void __fastcall hkpSphereSphereAgent::registerAgent2(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereSphereAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(dispatcher, &f, SPHERE, SPHERE);
}

// File Line: 67
// RVA: 0xD1F9E0
hkpCollisionAgent *__fastcall hkpSphereSphereAgent::createSphereSphereAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *contactMgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereSphereAgent::`vftable;
    result->m_contactMgr = contactMgr;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 75
// RVA: 0xD1F990
void __fastcall hkpSphereSphereAgent::cleanup(hkpSphereSphereAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 m_contactPointId; // rdx

  v2 = constraintOwner;
  m_contactPointId = this->m_contactPointId;
  if ( (_WORD)m_contactPointId != 0xFFFF )
  {
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      m_contactPointId,
      v2);
    this->m_contactPointId = -1;
  }
  ((void (__fastcall *)(hkpSphereSphereAgent *, __int64, hkpConstraintOwner *))this->vfptr->__vecDelDtor)(
    this,
    1i64,
    v2);
}

// File Line: 90
// RVA: 0xD1F2B0
void __fastcall hkpSphereSphereAgent::processCollision(
        hkpSphereSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __m128 *m_motion; // rcx
  hkpShape *m_shape; // rdx
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  float v19; // xmm0_4
  __m128 v20; // xmm1
  hkpProcessCdPoint *m_storage; // rbp
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm5
  unsigned __int16 v26; // ax
  __int64 m_contactPointId; // rdx
  _QWORD *v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  unsigned int v33; // [rsp+88h] [rbp+10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtSphereSphere";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyB->m_shape;
  v15 = _mm_sub_ps(*((__m128 *)bodyA->m_motion + 3), m_motion[3]);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  *(float *)&v33 = *(float *)&bodyA->m_shape[1].vfptr + *(float *)&bodyB->m_shape[1].vfptr;
  v18 = _mm_shuffle_ps((__m128)v33, (__m128)v33, 0);
  v19 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v18.m128_f32[0];
  if ( v17.m128_f32[0] >= (float)(v19 * v19) )
  {
    m_contactPointId = this->m_contactPointId;
    if ( (_WORD)m_contactPointId != 0xFFFF )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
        this->m_contactMgr,
        m_contactPointId,
        result->m_constraintOwner.m_storage);
      this->m_contactPointId = -1;
    }
  }
  else
  {
    v20 = _mm_rsqrt_ps(v17);
    m_storage = result->m_firstFreeContactPoint.m_storage;
    v22 = _mm_cmplt_ps((__m128)0i64, v17);
    v23 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v17), v20)), _mm_mul_ps(*(__m128 *)_xmm, v20));
    v24 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v23), v22), _mm_andnot_ps(v22, transform.m_quad));
    v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_sub_ps(_mm_and_ps(_mm_mul_ps(v23, v17), v22), v18)), 196);
    m_storage->m_contact.m_separatingNormal.m_quad = v25;
    m_storage->m_contact.m_position.m_quad = _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(
                                                   (__m128)LODWORD(m_shape[1].vfptr),
                                                   (__m128)LODWORD(m_shape[1].vfptr),
                                                   0),
                                                 v25),
                                               m_motion[3]);
    if ( this->m_contactPointId == 0xFFFF )
      this->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                                 this->m_contactMgr,
                                 bodyA,
                                 bodyB,
                                 input,
                                 result,
                                 0i64,
                                 m_storage);
    v26 = this->m_contactPointId;
    if ( v26 != 0xFFFF )
    {
      m_storage->m_contactPointId = v26;
      ++result->m_firstFreeContactPoint.m_storage;
    }
  }
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  v30 = v28;
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v31 = __rdtsc();
    v32 = v29 + 2;
    *((_DWORD *)v32 - 2) = v31;
    v30[1] = v32;
  }
}

// File Line: 220
// RVA: 0xD1F4F0
void __fastcall hkpSphereSphereAgent::getClosestPoints(
        hkpSphereSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpShape *m_shape; // rcx
  __m128 v13; // xmm7
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  float v18; // xmm0_4
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 vfptr_low; // xmm0
  hkpCdPointCollectorVtbl *vfptr; // rax
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  __m128 v29; // [rsp+20h] [rbp-68h] BYREF
  __m128 v30; // [rsp+30h] [rbp-58h]
  __m128 v31; // [rsp+40h] [rbp-48h]
  hkpCdBody *v32; // [rsp+50h] [rbp-38h]
  hkpCdBody *v33; // [rsp+58h] [rbp-30h]
  unsigned int v34; // [rsp+98h] [rbp+10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSphereSphere";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_shape = bodyB->m_shape;
  v13 = *((__m128 *)bodyB->m_motion + 3);
  v14 = _mm_sub_ps(*((__m128 *)bodyA->m_motion + 3), v13);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  *(float *)&v34 = *(float *)&bodyA->m_shape[1].vfptr + *(float *)&bodyB->m_shape[1].vfptr;
  v17 = _mm_shuffle_ps((__m128)v34, (__m128)v34, 0);
  v18 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v17.m128_f32[0];
  if ( v16.m128_f32[0] < (float)(v18 * v18) )
  {
    v19 = _mm_rsqrt_ps(v16);
    v32 = bodyA;
    v33 = bodyB;
    v20 = _mm_cmplt_ps((__m128)0i64, v16);
    v21 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v16), v19)), _mm_mul_ps(*(__m128 *)_xmm, v19));
    v22 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v14, v21), v20), _mm_andnot_ps(v20, transform.m_quad));
    vfptr_low = (__m128)LODWORD(m_shape[1].vfptr);
    v30 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, _mm_sub_ps(_mm_and_ps(_mm_mul_ps(v21, v16), v20), v17)), 196);
    v31 = v30;
    vfptr = collector->vfptr;
    v29 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vfptr_low, vfptr_low, 0), v30), v13);
    vfptr->addCdPoint(collector, (hkpCdPoint *)&v29);
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
}

// File Line: 235
// RVA: 0xD1F6B0
void __fastcall hkpSphereSphereAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpShape *m_shape; // rcx
  __m128 v14; // xmm7
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  float v19; // xmm0_4
  hkpCdPointCollectorVtbl *vfptr; // rax
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 vfptr_low; // xmm0
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  __m128 v30; // [rsp+20h] [rbp-68h] BYREF
  __m128 v31; // [rsp+30h] [rbp-58h]
  __m128 v32; // [rsp+40h] [rbp-48h]
  hkpCdBody *v33; // [rsp+50h] [rbp-38h]
  hkpCdBody *v34; // [rsp+58h] [rbp-30h]
  unsigned int v35; // [rsp+90h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSphereSphere";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_shape = bodyB->m_shape;
  v14 = *((__m128 *)bodyB->m_motion + 3);
  v15 = _mm_sub_ps(*((__m128 *)bodyA->m_motion + 3), v14);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  *(float *)&v35 = *(float *)&bodyA->m_shape[1].vfptr + *(float *)&bodyB->m_shape[1].vfptr;
  v18 = _mm_shuffle_ps((__m128)v35, (__m128)v35, 0);
  v19 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0]
      + v18.m128_f32[0];
  if ( v17.m128_f32[0] < (float)(v19 * v19) )
  {
    vfptr = collector->vfptr;
    v21 = _mm_rsqrt_ps(v17);
    v33 = bodyA;
    v34 = bodyB;
    v22 = _mm_cmplt_ps((__m128)0i64, v17);
    v23 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v17), v21)), _mm_mul_ps(*(__m128 *)_xmm, v21));
    v24 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v23), v22), _mm_andnot_ps(v22, transform.m_quad));
    vfptr_low = (__m128)LODWORD(m_shape[1].vfptr);
    v31 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_sub_ps(_mm_and_ps(_mm_mul_ps(v23, v17), v22), v18)), 196);
    v32 = v31;
    v30 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vfptr_low, vfptr_low, 0), v31), v14);
    vfptr->addCdPoint(collector, (hkpCdPoint *)&v30);
  }
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = v27 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v26[1] = v29;
  }
}

// File Line: 250
// RVA: 0xD1F870
void __fastcall hkpSphereSphereAgent::getPenetrations(
        hkpSphereSphereAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpSphereSphereAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 258
// RVA: 0xD1F890
void __fastcall hkpSphereSphereAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  float v14; // xmm2_4
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  unsigned int v19; // [rsp+30h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtSphereSphere";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  v12 = _mm_sub_ps(*((__m128 *)bodyB->m_motion + 3), *((__m128 *)bodyA->m_motion + 3));
  v13 = _mm_mul_ps(v12, v12);
  *(float *)&v19 = *(float *)&bodyA->m_shape[1].vfptr + *(float *)&bodyB->m_shape[1].vfptr;
  v14 = _mm_shuffle_ps((__m128)v19, (__m128)v19, 0).m128_f32[0];
  if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
             + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) < (float)(v14 * v14) )
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v15[1] = v18;
  }
}

