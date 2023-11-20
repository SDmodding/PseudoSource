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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpGskfAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, CONVEX, CONVEX);
}

// File Line: 63
// RVA: 0xD371E0
void __fastcall hkpGskfAgent::hkpGskfAgent(hkpGskfAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpContactMgr *mgr)
{
  hkpGskfAgent *v4; // rbx

  v4 = this;
  hkpGskBaseAgent::hkpGskBaseAgent((hkpGskBaseAgent *)&this->vfptr, bodyA, bodyB, mgr);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpGskfAgent::`vftable';
  *(_DWORD *)&v4->m_manifold.m_numVertsA = 0;
}

// File Line: 71
// RVA: 0xD372B0
void __fastcall hkpGskfAgent::createGskfAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rsi
  hkpContactMgr *v5; // rbx
  hkpCdBody *v6; // rdi
  _QWORD **v7; // rax
  hkpGskfAgent *v8; // rax
  _QWORD **v9; // rax
  hkpGskBaseAgent *v10; // rax

  v4 = bodyA;
  v5 = mgr;
  v6 = bodyB;
  if ( mgr )
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 144i64);
    if ( v8 )
      hkpGskfAgent::hkpGskfAgent(v8, v4, v6, v5);
  }
  else
  {
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpGskBaseAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 64i64);
    if ( v10 )
      hkpGskBaseAgent::hkpGskBaseAgent(v10, v4, v6, 0i64);
  }
}

// File Line: 88
// RVA: 0xD370D0
void __fastcall hkpGskfAgent::cleanup(hkpGskfAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpGskfAgent *v2; // rbx

  v2 = this;
  hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, constraintOwner);
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
}

// File Line: 97
// RVA: 0xD37110
void __fastcall hkpGskfAgent::removePoint(hkpGskfAgent *this, unsigned __int16 idToRemove)
{
  __int64 v2; // r9
  unsigned __int16 v3; // r10
  int v4; // edx
  __int64 v5; // r8
  unsigned __int16 *v6; // rax

  v2 = (unsigned __int8)this->m_manifold.m_numContactPoints;
  v3 = idToRemove;
  v4 = 0;
  v5 = 0i64;
  if ( v2 > 0 )
  {
    v6 = &this->m_manifold.m_contactPoints[0].m_id;
    while ( *v6 != v3 )
    {
      ++v5;
      ++v4;
      v6 += 4;
      if ( v5 >= v2 )
        return;
    }
    hkGskManifold_removePoint(&this->m_manifold, v4);
  }
}

// File Line: 112
// RVA: 0xD37150
void __fastcall hkpGskfAgent::commitPotential(hkpGskfAgent *this, unsigned __int16 idToCommit)
{
  __int64 v2; // r10
  int v3; // er9
  __int64 v4; // r8
  unsigned __int16 *v5; // rax

  v2 = (unsigned __int8)this->m_manifold.m_numContactPoints;
  v3 = 0;
  v4 = 0i64;
  if ( v2 > 0 )
  {
    v5 = &this->m_manifold.m_contactPoints[0].m_id;
    while ( *v5 != -1 )
    {
      ++v4;
      ++v3;
      v5 += 4;
      if ( v4 >= v2 )
        return;
    }
    this->m_manifold.m_contactPoints[v3].m_id = idToCommit;
  }
}

// File Line: 127
// RVA: 0xD371A0
void __fastcall hkpGskfAgent::createZombie(hkpGskfAgent *this, unsigned __int16 idTobecomeZombie)
{
  __int64 v2; // r9
  __int64 v3; // r8
  hkpGskManifold::ContactPoint *v4; // rax

  v2 = (unsigned __int8)this->m_manifold.m_numContactPoints;
  v3 = 0i64;
  if ( v2 > 0 )
  {
    v4 = this->m_manifold.m_contactPoints;
    while ( v4->m_id != idTobecomeZombie )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        return;
    }
    *(_WORD *)&v4->m_dimA = 0;
  }
}

// File Line: 151
// RVA: 0xD37210
void __fastcall hkpGskfAgent::processCollisionNoTim(hkpGskfAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, int explicitlyAllowNewPoint, hkpProcessCollisionOutput *output)
{
  hkpContactMgr *v6; // rax
  hkTransformf *v7; // rdx
  hkTransformf *v8; // r8
  hkpGskfAgent *v9; // rbx
  char agentData; // [rsp+40h] [rbp-A8h]
  hkpAgent3Input inputa; // [rsp+50h] [rbp-98h]
  hkpAgentEntry entry; // [rsp+F0h] [rbp+8h]

  v6 = this->m_contactMgr;
  inputa.m_bodyA.m_storage = bodyA;
  v7 = (hkTransformf *)bodyA->m_motion;
  inputa.m_bodyB.m_storage = bodyB;
  v8 = (hkTransformf *)bodyB->m_motion;
  v9 = this;
  inputa.m_contactMgr.m_storage = v6;
  inputa.m_overrideBodyA.m_storage = 0i64;
  inputa.m_input.m_storage = input;
  hkTransformf::setMulInverseMul(&inputa.m_aTb, v7, v8);
  hkGskAgentUtil_processCollisionNoTim(
    &inputa,
    &entry,
    &agentData,
    &v9->m_cache,
    &v9->m_manifold,
    &v9->m_separatingNormal,
    explicitlyAllowNewPoint,
    output);
}

// File Line: 174
// RVA: 0xD36EA0
void __fastcall hkpGskfAgent::processCollision(hkpGskfAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpGskfAgent *v5; // rbx
  hkpProcessCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  hkpCdBody *v8; // rbp
  _QWORD *v9; // rcx
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  __m128 *v12; // rax
  __m128 *v13; // rcx
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm3
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
  signed __int64 v32; // rcx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtGskAgent";
    *(_QWORD *)(v10 + 16) = "StTim";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  if ( v6->m_stepInfo.m_startTime.m_storage == v5->m_timeOfSeparatingNormal )
    goto LABEL_13;
  v12 = (__m128 *)v7->m_motion;
  v13 = (__m128 *)v8->m_motion;
  v14 = v13[5];
  v15 = v12[5];
  v16 = _mm_shuffle_ps(
          (__m128)LODWORD(v6->m_stepInfo.m_deltaTime.m_storage),
          (__m128)LODWORD(v6->m_stepInfo.m_deltaTime.m_storage),
          0);
  v17 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v16);
  v18 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v16);
  v19 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v15, v12[4]), v17), _mm_mul_ps(_mm_sub_ps(v13[4], v14), v18));
  v20 = v5->m_separatingNormal.m_quad;
  v21 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13[9], v13[9], 255), v18),
            _mm_shuffle_ps((__m128)v13[10].m128_u32[0], (__m128)v13[10].m128_u32[0], 0)),
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v12[9], v12[9], 255), v17),
            _mm_shuffle_ps((__m128)v12[10].m128_u32[0], (__m128)v12[10].m128_u32[0], 0)));
  v22 = _mm_shuffle_ps(v20, v20, 255);
  v23 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v21), 196);
  LODWORD(v24) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(v6->m_tolerance.m_storage),
                                      (__m128)LODWORD(v6->m_tolerance.m_storage),
                                      0);
  if ( v22.m128_f32[0] <= v24
    || (v25 = _mm_mul_ps(v20, v23),
        v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v23), 196),
        v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26),
        v28 = _mm_sub_ps(v22, _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27)),
        v5->m_separatingNormal.m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v28), 196),
        v28.m128_f32[0] <= v24) )
  {
LABEL_13:
    v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v30 = (_QWORD *)v29[1];
    if ( (unsigned __int64)v30 < v29[3] )
    {
      *v30 = "StGsk";
      v31 = __rdtsc();
      v32 = (signed __int64)(v30 + 2);
      *(_DWORD *)(v32 - 8) = v31;
      v29[1] = v32;
    }
    v5->m_timeOfSeparatingNormal = v6->m_stepInfo.m_endTime.m_storage;
    hkpGskfAgent::processCollisionNoTim(v5, v8, v7, v6, 0, result);
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  v35 = v33;
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "lt";
    v36 = __rdtsc();
    v37 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v37 - 8) = v36;
    v35[1] = v37;
  }
}

