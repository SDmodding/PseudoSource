// File Line: 31
// RVA: 0xD36E20
void __fastcall hkpGskfAgent::initAgentFunc(hkpCollisionDispatcher::AgentFuncs *af)
{
  af->m_createFunc = hkpGskfAgent::createGskfAgent;
  af->m_getPenetrationsFunc = hkpGskBaseAgent::staticGetPenetrations;
  af->m_getClosestPointFunc = hkpGskBaseAgent::staticGetClosestPoints;
  af->m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  *(_WORD *)&af->m_isFlipped.m_bool = 0;
}

// File Line: 53
// RVA: 0xD36E60
void __fastcall hkpGskfAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpGskfAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, CONVEX);
}

// File Line: 63
// RVA: 0xD371E0
void __fastcall hkpGskfAgent::hkpGskfAgent(hkpGskfAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpContactMgr *mgr)
{
  hkpGskBaseAgent::hkpGskBaseAgent(this, bodyA, bodyB, mgr);
  this->vfptr = (hkBaseObjectVtbl *)&hkpGskfAgent::`vftable;
  *(_DWORD *)&this->m_manifold.m_numVertsA = 0;
}

// File Line: 71
// RVA: 0xD372B0
void __fastcall hkpGskfAgent::createGskfAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpGskfAgent *v8; // rax
  _QWORD **v9; // rax
  hkpGskBaseAgent *v10; // rax

  if ( mgr )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
    if ( v8 )
      hkpGskfAgent::hkpGskfAgent(v8, bodyA, bodyB, mgr);
  }
  else
  {
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpGskBaseAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v9[11] + 8i64))(v9[11], 64i64);
    if ( v10 )
      hkpGskBaseAgent::hkpGskBaseAgent(v10, bodyA, bodyB, 0i64);
  }
}

// File Line: 88
// RVA: 0xD370D0
void __fastcall hkpGskfAgent::cleanup(hkpGskfAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, constraintOwner);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 97
// RVA: 0xD37110
void __fastcall hkpGskfAgent::removePoint(hkpGskfAgent *this, unsigned __int16 idToRemove)
{
  int v3; // edx
  __int64 v4; // r8
  unsigned __int16 *i; // rax

  v3 = 0;
  v4 = 0i64;
  if ( this->m_manifold.m_numContactPoints )
  {
    for ( i = &this->m_manifold.m_contactPoints[0].m_id; *i != idToRemove; i += 4 )
    {
      ++v4;
      ++v3;
      if ( v4 >= (unsigned __int8)this->m_manifold.m_numContactPoints )
        return;
    }
    hkGskManifold_removePoint(&this->m_manifold, v3);
  }
}

// File Line: 112
// RVA: 0xD37150
void __fastcall hkpGskfAgent::commitPotential(hkpGskfAgent *this, unsigned __int16 idToCommit)
{
  int v2; // r9d
  __int64 v3; // r8
  unsigned __int16 *i; // rax

  v2 = 0;
  v3 = 0i64;
  if ( this->m_manifold.m_numContactPoints )
  {
    for ( i = &this->m_manifold.m_contactPoints[0].m_id; *i != 0xFFFF; i += 4 )
    {
      ++v3;
      ++v2;
      if ( v3 >= (unsigned __int8)this->m_manifold.m_numContactPoints )
        return;
    }
    this->m_manifold.m_contactPoints[v2].m_id = idToCommit;
  }
}

// File Line: 127
// RVA: 0xD371A0
void __fastcall hkpGskfAgent::createZombie(hkpGskfAgent *this, unsigned __int16 idTobecomeZombie)
{
  __int64 v2; // r8
  hkpGskManifold::ContactPoint *i; // rax

  v2 = 0i64;
  if ( this->m_manifold.m_numContactPoints )
  {
    for ( i = this->m_manifold.m_contactPoints; i->m_id != idTobecomeZombie; ++i )
    {
      if ( ++v2 >= (unsigned __int8)this->m_manifold.m_numContactPoints )
        return;
    }
    *(_WORD *)&i->m_dimA = 0;
  }
}

// File Line: 151
// RVA: 0xD37210
void __fastcall hkpGskfAgent::processCollisionNoTim(
        hkpGskfAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        int explicitlyAllowNewPoint,
        hkpProcessCollisionOutput *output)
{
  hkpContactMgr *m_contactMgr; // rax
  hkTransformf *m_motion; // rdx
  hkTransformf *v8; // r8
  char agentData[16]; // [rsp+40h] [rbp-A8h] BYREF
  hkpAgent3Input inputa; // [rsp+50h] [rbp-98h] BYREF
  hkpAgentEntry entry; // [rsp+F0h] [rbp+8h] BYREF

  m_contactMgr = this->m_contactMgr;
  inputa.m_bodyA.m_storage = bodyA;
  m_motion = (hkTransformf *)bodyA->m_motion;
  inputa.m_bodyB.m_storage = bodyB;
  v8 = (hkTransformf *)bodyB->m_motion;
  inputa.m_contactMgr.m_storage = m_contactMgr;
  inputa.m_overrideBodyA.m_storage = 0i64;
  inputa.m_input.m_storage = input;
  hkTransformf::setMulInverseMul(&inputa.m_aTb, m_motion, v8);
  hkGskAgentUtil_processCollisionNoTim(
    &inputa,
    &entry,
    agentData,
    &this->m_cache,
    &this->m_manifold,
    &this->m_separatingNormal,
    explicitlyAllowNewPoint,
    output);
}

// File Line: 174
// RVA: 0xD36EA0
void __fastcall hkpGskfAgent::processCollision(
        hkpGskfAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  _QWORD *Value; // rcx
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  __m128 *m_motion; // rax
  __m128 *v13; // rcx
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  hkVector4f v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  float v24; // xmm5_4
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LtGskAgent";
    *(_QWORD *)(v10 + 16) = "StTim";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    Value[1] = v10 + 24;
  }
  if ( input->m_stepInfo.m_startTime.m_storage == this->m_timeOfSeparatingNormal )
    goto LABEL_6;
  m_motion = (__m128 *)bodyB->m_motion;
  v13 = (__m128 *)bodyA->m_motion;
  v14 = v13[5];
  v15 = m_motion[5];
  v16 = _mm_shuffle_ps(
          (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
          (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
          0);
  v17 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v16);
  v18 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v16);
  v19 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v15, m_motion[4]), v17), _mm_mul_ps(_mm_sub_ps(v13[4], v14), v18));
  v20.m_quad = (__m128)this->m_separatingNormal;
  v21 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13[9], v13[9], 255), v18),
            _mm_shuffle_ps((__m128)v13[10].m128_u32[0], (__m128)v13[10].m128_u32[0], 0)),
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(m_motion[9], m_motion[9], 255), v17),
            _mm_shuffle_ps((__m128)m_motion[10].m128_u32[0], (__m128)m_motion[10].m128_u32[0], 0)));
  v22 = _mm_shuffle_ps(v20.m_quad, v20.m_quad, 255);
  v23 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v21), 196);
  v24 = _mm_shuffle_ps((__m128)LODWORD(input->m_tolerance.m_storage), (__m128)LODWORD(input->m_tolerance.m_storage), 0).m128_f32[0];
  if ( v22.m128_f32[0] <= v24
    || (v25 = _mm_mul_ps(v20.m_quad, v23),
        v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v23), 196),
        v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26),
        v28 = _mm_sub_ps(v22, _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27)),
        this->m_separatingNormal.m_quad = _mm_shuffle_ps(v20.m_quad, _mm_unpackhi_ps(v20.m_quad, v28), 196),
        v28.m128_f32[0] <= v24) )
  {
LABEL_6:
    v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v30 = (_QWORD *)v29[1];
    if ( (unsigned __int64)v30 < v29[3] )
    {
      *v30 = "StGsk";
      v31 = __rdtsc();
      v32 = v30 + 2;
      *((_DWORD *)v32 - 2) = v31;
      v29[1] = v32;
    }
    this->m_timeOfSeparatingNormal = input->m_stepInfo.m_endTime.m_storage;
    hkpGskfAgent::processCollisionNoTim(this, bodyA, bodyB, input, 0, result);
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  v35 = v33;
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "lt";
    v36 = __rdtsc();
    v37 = v34 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v35[1] = v37;
  }
}

