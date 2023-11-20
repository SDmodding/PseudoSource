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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereSphereAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, 0, 0);
}

// File Line: 47
// RVA: 0xD1F270
void __fastcall hkpSphereSphereAgent::registerAgent2(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  hkpSphereSphereAgent::initAgentFunc(&f);
  hkpCollisionDispatcher::registerCollisionAgent2(v1, &f, 0, 0);
}

// File Line: 67
// RVA: 0xD1F9E0
hkpCollisionAgent *__fastcall hkpSphereSphereAgent::createSphereSphereAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpCollisionAgent *result; // rax

  v4 = contactMgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereSphereAgent::`vftable;
    result->m_contactMgr = v4;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 75
// RVA: 0xD1F990
void __fastcall hkpSphereSphereAgent::cleanup(hkpSphereSphereAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 v3; // rdx
  hkpSphereSphereAgent *v4; // rbx

  v2 = constraintOwner;
  v3 = this->m_contactPointId;
  v4 = this;
  if ( (_WORD)v3 != -1 )
  {
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      v3,
      v2);
    v4->m_contactPointId = -1;
  }
  ((void (__fastcall *)(hkpSphereSphereAgent *, signed __int64, hkpConstraintOwner *))v4->vfptr->__vecDelDtor)(
    v4,
    1i64,
    v2);
}

// File Line: 90
// RVA: 0xD1F2B0
void __fastcall hkpSphereSphereAgent::processCollision(hkpSphereSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpSphereSphereAgent *v5; // rbx
  hkpProcessCollisionInput *v6; // r12
  hkpCdBody *v7; // r14
  hkpCdBody *v8; // r15
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 *v13; // rcx
  hkpShape *v14; // rdx
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  float v19; // xmm0_4
  __m128 v20; // xmm1
  hkpProcessCdPoint *v21; // rbp
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm5
  unsigned __int16 v26; // ax
  __int64 v27; // rdx
  _QWORD *v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  unsigned int v33; // [rsp+88h] [rbp+10h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtSphereSphere";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = (__m128 *)v7->m_motion;
  v14 = v7->m_shape;
  v15 = _mm_sub_ps(*((__m128 *)v8->m_motion + 3), v13[3]);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  *(float *)&v33 = *(float *)&v8->m_shape[1].vfptr + *(float *)&v7->m_shape[1].vfptr;
  v18 = _mm_shuffle_ps((__m128)v33, (__m128)v33, 0);
  v19 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6->m_tolerance.m_storage), (__m128)LODWORD(v6->m_tolerance.m_storage), 0))
      + v18.m128_f32[0];
  if ( v17.m128_f32[0] >= (float)(v19 * v19) )
  {
    v27 = v5->m_contactPointId;
    if ( (_WORD)v27 != -1 )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
        v5->m_contactMgr,
        v27,
        result->m_constraintOwner.m_storage);
      v5->m_contactPointId = -1;
    }
  }
  else
  {
    v20 = _mm_rsqrt_ps(v17);
    v21 = result->m_firstFreeContactPoint.m_storage;
    v22 = _mm_cmpltps((__m128)0i64, v17);
    v23 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v17), v20)), _mm_mul_ps(*(__m128 *)_xmm, v20));
    v24 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v23), v22), _mm_andnot_ps(v22, transform.m_quad));
    v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_sub_ps(_mm_and_ps(_mm_mul_ps(v23, v17), v22), v18)), 196);
    v21->m_contact.m_separatingNormal.m_quad = v25;
    v21->m_contact.m_position.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             (__m128)LODWORD(v14[1].vfptr),
                                             (__m128)LODWORD(v14[1].vfptr),
                                             0),
                                           v25),
                                         v13[3]);
    if ( v5->m_contactPointId == -1 )
      v5->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                               v5->m_contactMgr,
                               v8,
                               v7,
                               v6,
                               result,
                               0i64,
                               v21);
    v26 = v5->m_contactPointId;
    if ( v26 != -1 )
    {
      v21->m_contactPointId = v26;
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
    v32 = (signed __int64)(v29 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v30[1] = v32;
  }
}

// File Line: 220
// RVA: 0xD1F4F0
void __fastcall hkpSphereSphereAgent::getClosestPoints(hkpSphereSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCollisionInput *v5; // rsi
  hkpCdBody *v6; // rbx
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkpShape *v12; // rcx
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
  __m128 v23; // xmm0
  hkpCdPointCollectorVtbl *v24; // rax
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  __m128 v29; // [rsp+20h] [rbp-68h]
  __m128 v30; // [rsp+30h] [rbp-58h]
  __m128 v31; // [rsp+40h] [rbp-48h]
  hkpCdBody *v32; // [rsp+50h] [rbp-38h]
  hkpCdBody *v33; // [rsp+58h] [rbp-30h]
  unsigned int v34; // [rsp+98h] [rbp+10h]

  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereSphere";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v6->m_shape;
  v13 = *((__m128 *)v6->m_motion + 3);
  v14 = _mm_sub_ps(*((__m128 *)v7->m_motion + 3), v13);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  *(float *)&v34 = *(float *)&v7->m_shape[1].vfptr + *(float *)&v6->m_shape[1].vfptr;
  v17 = _mm_shuffle_ps((__m128)v34, (__m128)v34, 0);
  v18 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v5->m_tolerance.m_storage), (__m128)LODWORD(v5->m_tolerance.m_storage), 0))
      + v17.m128_f32[0];
  if ( v16.m128_f32[0] < (float)(v18 * v18) )
  {
    v19 = _mm_rsqrt_ps(v16);
    v32 = v7;
    v33 = v6;
    v20 = _mm_cmpltps((__m128)0i64, v16);
    v21 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v16), v19)), _mm_mul_ps(*(__m128 *)_xmm, v19));
    v22 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v14, v21), v20), _mm_andnot_ps(v20, transform.m_quad));
    v23 = (__m128)LODWORD(v12[1].vfptr);
    v30 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, _mm_sub_ps(_mm_and_ps(_mm_mul_ps(v21, v16), v20), v17)), 196);
    v31 = v30;
    v24 = collector->vfptr;
    v29 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v30), v13);
    v24->addCdPoint(collector, (hkpCdPoint *)&v29);
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v25[1] = v28;
  }
}

// File Line: 235
// RVA: 0xD1F6B0
void __fastcall hkpSphereSphereAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rdi
  hkpCdPointCollector *v5; // r14
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpShape *v13; // rcx
  __m128 v14; // xmm7
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  float v19; // xmm0_4
  hkpCdPointCollectorVtbl *v20; // rax
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm0
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  __m128 v30; // [rsp+20h] [rbp-68h]
  __m128 v31; // [rsp+30h] [rbp-58h]
  __m128 v32; // [rsp+40h] [rbp-48h]
  hkpCdBody *v33; // [rsp+50h] [rbp-38h]
  hkpCdBody *v34; // [rsp+58h] [rbp-30h]
  unsigned int v35; // [rsp+90h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereSphere";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v7->m_shape;
  v14 = *((__m128 *)v7->m_motion + 3);
  v15 = _mm_sub_ps(*((__m128 *)v4->m_motion + 3), v14);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  *(float *)&v35 = *(float *)&v4->m_shape[1].vfptr + *(float *)&v7->m_shape[1].vfptr;
  v18 = _mm_shuffle_ps((__m128)v35, (__m128)v35, 0);
  v19 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6->m_tolerance.m_storage), (__m128)LODWORD(v6->m_tolerance.m_storage), 0))
      + v18.m128_f32[0];
  if ( v17.m128_f32[0] < (float)(v19 * v19) )
  {
    v20 = v5->vfptr;
    v21 = _mm_rsqrt_ps(v17);
    v33 = v4;
    v34 = v7;
    v22 = _mm_cmpltps((__m128)0i64, v17);
    v23 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v17), v21)), _mm_mul_ps(*(__m128 *)_xmm, v21));
    v24 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v23), v22), _mm_andnot_ps(v22, transform.m_quad));
    v25 = (__m128)LODWORD(v13[1].vfptr);
    v31 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_sub_ps(_mm_and_ps(_mm_mul_ps(v23, v17), v22), v18)), 196);
    v32 = v31;
    v30 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v31), v14);
    v20->addCdPoint(v5, (hkpCdPoint *)&v30);
  }
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v27 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v26[1] = v29;
  }
}

// File Line: 250
// RVA: 0xD1F870
void __fastcall hkpSphereSphereAgent::getPenetrations(hkpSphereSphereAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpSphereSphereAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

// File Line: 258
// RVA: 0xD1F890
void __fastcall hkpSphereSphereAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdBodyPairCollector *v5; // rbx
  hkpCdBody *v6; // rdi
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  float v14; // xmm2_4
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  unsigned int v19; // [rsp+30h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = bodyB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtSphereSphere";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12 = _mm_sub_ps(*((__m128 *)v6->m_motion + 3), *((__m128 *)v4->m_motion + 3));
  v13 = _mm_mul_ps(v12, v12);
  *(float *)&v19 = *(float *)&v4->m_shape[1].vfptr + *(float *)&v6->m_shape[1].vfptr;
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps((__m128)v19, (__m128)v19, 0);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) < (float)(v14 * v14) )
    v5->vfptr->addCdBodyPair(v5, v4, v6);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v15[1] = v18;
  }
}

