// File Line: 16
// RVA: 0xCF5000
void __fastcall hkpTransformAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpTransformAgent::createTransformBAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, ALL_SHAPE_TYPES, TRANSFORM);
  f.m_createFunc = hkpTransformAgent::createTransformAAgent;
  f.m_getPenetrationsFunc = hkpTransformAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpTransformAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpTransformAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, TRANSFORM, ALL_SHAPE_TYPES);
}

// File Line: 58
// RVA: 0xCF57C0
void __fastcall hkpTransformAgent::cleanup(hkpTransformAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpTransformAgent *v2; // rbx

  v2 = this;
  ((void (__fastcall *)(hkpCollisionAgent *, hkpConstraintOwner *))this->m_childAgent->vfptr[3].__first_virtual_table_function__)(
    this->m_childAgent,
    constraintOwner);
  v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
}

// File Line: 80
// RVA: 0xCF5940
hkpCollisionAgent *__fastcall hkpTransformAgent::createTransformAAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkTransformf **v4; // rsi
  hkpContactMgr *v5; // r12
  hkpCollisionInput *v6; // r15
  hkpCdBody *v7; // r13
  _QWORD **v8; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v10; // rbx
  hkTransformf *v11; // rdx
  hkTransformf *v12; // rbp
  char *v13; // rcx
  __int64 v14; // r14
  signed __int64 v15; // r8
  hkVector4f v16; // xmm0
  bool v17; // zf
  hkpCollisionDispatcher *v18; // r10
  hkpShape *v19; // rax
  __int64 v20; // rdx
  signed __int64 v21; // rax
  __int64 v22; // [rsp+20h] [rbp-E8h]
  int v23; // [rsp+28h] [rbp-E0h]
  char *v24; // [rsp+30h] [rbp-D8h]
  hkTransformf **v25; // [rsp+38h] [rbp-D0h]
  char Dst; // [rsp+40h] [rbp-C8h]

  v4 = (hkTransformf **)bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 32i64);
  v10 = result;
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->m_contactMgr = v5;
    result->vfptr = (hkBaseObjectVtbl *)&hkpTransformAgent::`vftable;
    v11 = v4[2];
    v12 = *v4;
    v13 = &Dst;
    v14 = (*v4)->m_rotation.m_col2.m_quad.m128_i64[1];
    v15 = 1i64;
    if ( ((unsigned __int8)&Dst | (unsigned __int8)v11) & 0xF )
    {
      memmove(&Dst, v11, 0xB0ui64);
    }
    else
    {
      do
      {
        v16.m_quad = (__m128)v11->m_rotation.m_col0;
        v13 += 128;
        v11 += 2;
        *((hkVector4f *)v13 - 8) = (hkVector4f)v16.m_quad;
        *((_OWORD *)v13 - 7) = v11[-2].m_rotation.m_col1;
        *((_OWORD *)v13 - 6) = v11[-2].m_rotation.m_col2;
        *((_OWORD *)v13 - 5) = v11[-2].m_translation;
        *((_OWORD *)v13 - 4) = v11[-1].m_rotation.m_col0;
        *((_OWORD *)v13 - 3) = v11[-1].m_rotation.m_col1;
        *((_OWORD *)v13 - 2) = v11[-1].m_rotation.m_col2;
        *((_OWORD *)v13 - 1) = v11[-1].m_translation;
        --v15;
      }
      while ( v15 );
      *(hkVector4f *)v13 = v11->m_rotation.m_col0;
      *((_OWORD *)v13 + 1) = v11->m_rotation.m_col1;
      *((_OWORD *)v13 + 2) = v11->m_rotation.m_col2;
    }
    hkTransformf::setMul((hkTransformf *)&Dst, v4[2], (hkTransformf *)((char *)v12 + 80));
    v17 = v6->m_createPredictiveAgents.m_storage == 0;
    v18 = v6->m_dispatcher.m_storage;
    v22 = v14;
    v24 = &Dst;
    v19 = v7->m_shape;
    v25 = v4;
    v23 = 0;
    v20 = (unsigned __int8)v19->m_type.m_storage;
    v21 = (signed __int64)v18->m_agent2TypesPred;
    if ( v17 )
      v21 = (signed __int64)v18->m_agent2Types;
    v10[1].vfptr = (hkBaseObjectVtbl *)((__int64 (__fastcall *)(__int64 *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, __int64, _QWORD, char *, hkTransformf **))v18->m_agent2Func[*(unsigned __int8 *)(v20 + v21 + 35i64 * *(unsigned __int8 *)(v14 + 16))].m_createFunc)(
                                         &v22,
                                         v7,
                                         v6,
                                         v5,
                                         v22,
                                         *(_QWORD *)&v23,
                                         v24,
                                         v25);
    result = v10;
  }
  return result;
}

// File Line: 88
// RVA: 0xCF5B00
hkpCollisionAgent *__fastcall hkpTransformAgent::createTransformBAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // r13
  hkpContactMgr *v5; // r12
  hkpCollisionInput *v6; // r15
  hkTransformf **v7; // rsi
  _QWORD **v8; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v10; // rbx
  hkTransformf *v11; // rax
  hkTransformf *v12; // rbp
  char *v13; // rdx
  __int64 v14; // r14
  signed __int64 v15; // r8
  hkVector4f v16; // xmm0
  bool v17; // zf
  hkpCollisionDispatcher *v18; // r10
  hkpShape *v19; // rax
  __int64 v20; // rdx
  signed __int64 v21; // rax
  __int64 v22; // [rsp+20h] [rbp-E8h]
  int v23; // [rsp+28h] [rbp-E0h]
  char *v24; // [rsp+30h] [rbp-D8h]
  hkTransformf **v25; // [rsp+38h] [rbp-D0h]
  char Dst; // [rsp+40h] [rbp-C8h]

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = (hkTransformf **)bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 32i64);
  v10 = result;
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->m_contactMgr = v5;
    result->vfptr = (hkBaseObjectVtbl *)&hkpTransformAgent::`vftable;
    v11 = v7[2];
    v12 = *v7;
    v13 = &Dst;
    v14 = (*v7)->m_rotation.m_col2.m_quad.m128_i64[1];
    v15 = 1i64;
    if ( ((unsigned __int8)&Dst | (unsigned __int8)v11) & 0xF )
    {
      memmove(&Dst, v11, 0xB0ui64);
    }
    else
    {
      do
      {
        v16.m_quad = (__m128)v11->m_rotation.m_col0;
        v13 += 128;
        v11 += 2;
        *((hkVector4f *)v13 - 8) = (hkVector4f)v16.m_quad;
        *((_OWORD *)v13 - 7) = v11[-2].m_rotation.m_col1;
        *((_OWORD *)v13 - 6) = v11[-2].m_rotation.m_col2;
        *((_OWORD *)v13 - 5) = v11[-2].m_translation;
        *((_OWORD *)v13 - 4) = v11[-1].m_rotation.m_col0;
        *((_OWORD *)v13 - 3) = v11[-1].m_rotation.m_col1;
        *((_OWORD *)v13 - 2) = v11[-1].m_rotation.m_col2;
        *((_OWORD *)v13 - 1) = v11[-1].m_translation;
        --v15;
      }
      while ( v15 );
      *(hkVector4f *)v13 = v11->m_rotation.m_col0;
      *((_OWORD *)v13 + 1) = v11->m_rotation.m_col1;
      *((_OWORD *)v13 + 2) = v11->m_rotation.m_col2;
    }
    hkTransformf::setMul((hkTransformf *)&Dst, v7[2], (hkTransformf *)((char *)v12 + 80));
    v17 = v6->m_createPredictiveAgents.m_storage == 0;
    v18 = v6->m_dispatcher.m_storage;
    v22 = v14;
    v24 = &Dst;
    v19 = v4->m_shape;
    v25 = v7;
    v23 = 0;
    v20 = (unsigned __int8)v19->m_type.m_storage;
    v21 = (signed __int64)v18->m_agent2TypesPred;
    if ( v17 )
      v21 = (signed __int64)v18->m_agent2Types;
    v10[1].vfptr = (hkBaseObjectVtbl *)((__int64 (__fastcall *)(__int64 *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, __int64, _QWORD, char *, hkTransformf **))v18->m_agent2Func[*(unsigned __int8 *)(v20 + v21 + 35i64 * *(unsigned __int8 *)(v14 + 16))].m_createFunc)(
                                         &v22,
                                         v4,
                                         v6,
                                         v5,
                                         v22,
                                         *(_QWORD *)&v23,
                                         v24,
                                         v25);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpTransformAgent>::`vftable;
    result = v10;
  }
  return result;
}

// File Line: 94
// RVA: 0xCF50B0
void __fastcall hkpTransformAgent::processCollision(hkpTransformAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpTransformAgent *v5; // r15
  hkpProcessCollisionInput *v6; // rbp
  hkpCdBody *v7; // r14
  hkTransformf **v8; // rsi
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkTransformf *v13; // rdi
  hkTransformf *v14; // rax
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
  hkpCollisionAgent *v33; // rcx
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  __int64 v40; // [rsp+30h] [rbp-F8h]
  int v41; // [rsp+38h] [rbp-F0h]
  hkTransformf *v42; // [rsp+40h] [rbp-E8h]
  hkTransformf **v43; // [rsp+48h] [rbp-E0h]
  hkTransformf v44; // [rsp+50h] [rbp-D8h]
  hkVector4f v45; // [rsp+90h] [rbp-98h]
  hkVector4f v46; // [rsp+A0h] [rbp-88h]
  __m128 v47; // [rsp+B0h] [rbp-78h]
  __m128 v48; // [rsp+C0h] [rbp-68h]
  __m128 v49; // [rsp+D0h] [rbp-58h]
  hkVector4f v50; // [rsp+E0h] [rbp-48h]
  int v51; // [rsp+F0h] [rbp-38h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = (hkTransformf **)bodyAin;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtTransform";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = *v8;
  hkTransformf::setMul(&v44, v8[2], (hkTransformf *)((char *)*v8 + 80));
  v14 = v8[2];
  v45.m_quad = (__m128)v14[1].m_rotation.m_col0;
  v46.m_quad = (__m128)v14[1].m_rotation.m_col1;
  v15 = v14[1].m_rotation.m_col2.m_quad;
  v16 = v13[1].m_rotation.m_col0.m_quad;
  v17 = _mm_shuffle_ps(v13[1].m_rotation.m_col0.m_quad, v13[1].m_rotation.m_col0.m_quad, 255);
  v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
  v19 = _mm_mul_ps(v16, v15);
  v20 = _mm_shuffle_ps(v14[1].m_rotation.m_col2.m_quad, v14[1].m_rotation.m_col2.m_quad, 255);
  v21 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(v13[1].m_rotation.m_col0.m_quad, v20)),
          _mm_mul_ps(v14[1].m_rotation.m_col2.m_quad, v17));
  v47 = _mm_shuffle_ps(
          v21,
          _mm_unpackhi_ps(
            v21,
            _mm_sub_ps(
              _mm_mul_ps(v17, v20),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170)))),
          196);
  v22 = v14[1].m_translation.m_quad;
  v23 = v13[1].m_rotation.m_col0.m_quad;
  v24 = _mm_shuffle_ps(v14[1].m_translation.m_quad, v14[1].m_translation.m_quad, 255);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23);
  v26 = _mm_shuffle_ps(v13[1].m_rotation.m_col0.m_quad, v13[1].m_rotation.m_col0.m_quad, 255);
  v27 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22);
  v28 = _mm_mul_ps(v22, v23);
  v29 = _mm_sub_ps(v27, v25);
  v30 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(v24, v23)),
          _mm_mul_ps(v14[1].m_translation.m_quad, v26));
  v48 = _mm_shuffle_ps(
          v30,
          _mm_unpackhi_ps(
            v30,
            _mm_sub_ps(
              _mm_mul_ps(v26, v24),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170)))),
          196);
  v31 = _mm_sub_ps(v14[2].m_rotation.m_col0.m_quad, v13[2].m_rotation.m_col0.m_quad);
  v32 = v13[1].m_translation.m_quad;
  v33 = v5->m_childAgent;
  v34 = _mm_unpacklo_ps(v13[1].m_rotation.m_col1.m_quad, v13[1].m_rotation.m_col2.m_quad);
  v35 = _mm_movelh_ps(v34, v32);
  v49 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(_mm_movehl_ps(v35, v34), v32, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v35)),
          _mm_mul_ps(
            _mm_shuffle_ps(v31, v31, 170),
            _mm_shuffle_ps(_mm_unpackhi_ps(v13[1].m_rotation.m_col1.m_quad, v13[1].m_rotation.m_col2.m_quad), v32, 228)));
  v50.m_quad = (__m128)v14[2].m_rotation.m_col1;
  v34.m128_i32[0] = v14[2].m_rotation.m_col2.m_quad.m128_i32[0];
  v43 = v8;
  v42 = &v44;
  v51 = v34.m128_i32[0];
  v40 = v13->m_rotation.m_col2.m_quad.m128_i64[1];
  v41 = 0;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v33->vfptr[3].__vecDelDtor)(
    v33,
    &v40,
    v7,
    v6,
    result);
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "Et";
    v38 = __rdtsc();
    v39 = (signed __int64)(v37 + 2);
    *(_DWORD *)(v39 - 8) = v38;
    v36[1] = v39;
  }
}

// File Line: 137
// RVA: 0xCF5350
void __fastcall hkpTransformAgent::linearCast(hkpTransformAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpShape *v6; // rdi
  hkpCdBody *v7; // rbx
  hkpCdBody *v8; // r14
  hkpTransformAgent *v9; // rsi
  hkpLinearCastCollisionInput *v10; // rbp
  hkpCollisionAgent *v11; // rcx
  __int64 v12; // rax
  __int64 v13; // [rsp+30h] [rbp-68h]
  int v14; // [rsp+38h] [rbp-60h]
  hkTransformf *v15; // [rsp+40h] [rbp-58h]
  hkpCdBody *v16; // [rsp+48h] [rbp-50h]
  hkTransformf v17; // [rsp+50h] [rbp-48h]

  v6 = bodyAin->m_shape;
  v7 = bodyAin;
  v8 = bodyB;
  v9 = this;
  v10 = input;
  hkTransformf::setMul(&v17, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v11 = v9->m_childAgent;
  v16 = v7;
  v15 = &v17;
  v12 = *(_QWORD *)&v6[1].m_memSizeAndFlags;
  v14 = 0;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpLinearCastCollisionInput *, hkpCdPointCollector *, hkpCdPointCollector *, __int64, _QWORD, hkTransformf *, hkpCdBody *))v11->vfptr[2].__first_virtual_table_function__)(
    v11,
    &v13,
    v8,
    v10,
    collector,
    startCollector,
    v12,
    *(_QWORD *)&v14,
    &v17,
    v7);
}

// File Line: 154
// RVA: 0xCF5410
void __fastcall hkpTransformAgent::staticLinearCast(hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpShape *v5; // rdi
  hkpCdBody *v6; // r15
  hkpLinearCastCollisionInput *v7; // r14
  hkpCdBody *v8; // rbx
  hkpCdPointCollector *v9; // rsi
  hkpCollisionDispatcher *v10; // r11
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h]
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h]

  v5 = bodyAin->m_shape;
  v6 = bodyB;
  v7 = input;
  v8 = bodyAin;
  v9 = collector;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v10 = v7->m_dispatcher.m_storage;
  v15 = v8;
  v14 = &v16;
  v11 = *(_QWORD *)&v5[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  v10->m_agent2Func[(unsigned __int8)v10->m_agent2Types[*(unsigned __int8 *)(v11 + 16)][(unsigned __int8)v6->m_shape->m_type.m_storage]].m_linearCastFunc(
    (hkpCdBody *)&v12,
    v6,
    v7,
    v9,
    startCollector);
}

// File Line: 178
// RVA: 0xCF54E0
void __fastcall hkpTransformAgent::getClosestPoints(hkpTransformAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *pointDetails)
{
  hkpShape *v5; // rdi
  hkpCdBody *v6; // rbx
  hkpCdBody *v7; // r14
  hkpTransformAgent *v8; // rsi
  hkpCollisionInput *v9; // rbp
  hkpCollisionAgent *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h]
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h]

  v5 = bodyAin->m_shape;
  v6 = bodyAin;
  v7 = bodyB;
  v8 = this;
  v9 = input;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v10 = v8->m_childAgent;
  v15 = v6;
  v14 = &v16;
  v11 = *(_QWORD *)&v5[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *))v10->vfptr[2].__vecDelDtor)(
    v10,
    &v12,
    v7,
    v9,
    pointDetails);
}

// File Line: 195
// RVA: 0xCF5590
void __fastcall hkpTransformAgent::staticGetClosestPoints(hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *pointDetails)
{
  hkpShape *v4; // rdi
  hkpCdBody *v5; // r15
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // rbx
  hkpCdPointCollector *v8; // rsi
  hkpCollisionDispatcher *v9; // r10
  __int64 v10; // rax
  __int64 v11; // [rsp+20h] [rbp-68h]
  int v12; // [rsp+28h] [rbp-60h]
  hkTransformf *v13; // [rsp+30h] [rbp-58h]
  hkpCdBody *v14; // [rsp+38h] [rbp-50h]
  hkTransformf v15; // [rsp+40h] [rbp-48h]

  v4 = bodyAin->m_shape;
  v5 = bodyB;
  v6 = input;
  v7 = bodyAin;
  v8 = pointDetails;
  hkTransformf::setMul(&v15, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v9 = v6->m_dispatcher.m_storage;
  v14 = v7;
  v13 = &v15;
  v10 = *(_QWORD *)&v4[1].m_memSizeAndFlags;
  v12 = 0;
  v11 = v10;
  (*((void (__fastcall **)(__int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *, __int64, _QWORD, hkTransformf *, hkpCdBody *))&v9->vfptr
   + 5
   * ((unsigned __int8)v9->m_agent2Types[*(unsigned __int8 *)(v10 + 16)][(unsigned __int8)v5->m_shape->m_type.m_storage]
    + 79i64)))(
    &v11,
    v5,
    v6,
    v8,
    v10,
    *(_QWORD *)&v12,
    &v15,
    v7);
}

// File Line: 220
// RVA: 0xCF5650
void __fastcall hkpTransformAgent::getPenetrations(hkpTransformAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShape *v5; // rdi
  hkpCdBody *v6; // rbx
  hkpCdBody *v7; // r14
  hkpTransformAgent *v8; // rsi
  hkpCollisionInput *v9; // rbp
  hkpCollisionAgent *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h]
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h]

  v5 = bodyAin->m_shape;
  v6 = bodyAin;
  v7 = bodyB;
  v8 = this;
  v9 = input;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v10 = v8->m_childAgent;
  v15 = v6;
  v14 = &v16;
  v11 = *(_QWORD *)&v5[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *))v10->vfptr[1].__first_virtual_table_function__)(
    v10,
    &v12,
    v7,
    v9,
    collector);
}

// File Line: 235
// RVA: 0xCF5700
void __fastcall hkpTransformAgent::staticGetPenetrations(hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShape *v4; // rdi
  hkpCdBody *v5; // r15
  hkpCollisionInput *v6; // r14
  hkpCdBody *v7; // rbx
  hkpCdBodyPairCollector *v8; // rsi
  hkpCollisionDispatcher *v9; // r10
  __int64 v10; // rax
  __int64 v11; // [rsp+20h] [rbp-68h]
  int v12; // [rsp+28h] [rbp-60h]
  hkTransformf *v13; // [rsp+30h] [rbp-58h]
  hkpCdBody *v14; // [rsp+38h] [rbp-50h]
  hkTransformf v15; // [rsp+40h] [rbp-48h]

  v4 = bodyAin->m_shape;
  v5 = bodyB;
  v6 = input;
  v7 = bodyAin;
  v8 = collector;
  hkTransformf::setMul(&v15, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v9 = v6->m_dispatcher.m_storage;
  v14 = v7;
  v13 = &v15;
  v10 = *(_QWORD *)&v4[1].m_memSizeAndFlags;
  v12 = 0;
  v11 = v10;
  ((void (__fastcall *)(__int64 *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *, __int64, _QWORD, hkTransformf *, hkpCdBody *))v9->m_agent2Func[(unsigned __int8)v9->m_agent2Types[*(unsigned __int8 *)(v10 + 16)][(unsigned __int8)v5->m_shape->m_type.m_storage]].m_getPenetrationsFunc)(
    &v11,
    v5,
    v6,
    v8,
    v10,
    *(_QWORD *)&v12,
    &v15,
    v7);
}

// File Line: 254
// RVA: 0xCF5890
void __fastcall hkpTransformAgent::updateShapeCollectionFilter(hkpTransformAgent *this, hkpCdBody *bodyAin, hkpCdBody *bodyB, hkpCollisionInput *input, hkpConstraintOwner *constraintOwner)
{
  hkpShape *v5; // rdi
  hkpCdBody *v6; // rbx
  hkpCdBody *v7; // r14
  hkpTransformAgent *v8; // rsi
  hkpCollisionInput *v9; // rbp
  hkpCollisionAgent *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp-68h]
  int v13; // [rsp+38h] [rbp-60h]
  hkTransformf *v14; // [rsp+40h] [rbp-58h]
  hkpCdBody *v15; // [rsp+48h] [rbp-50h]
  hkTransformf v16; // [rsp+50h] [rbp-48h]

  v5 = bodyAin->m_shape;
  v6 = bodyAin;
  v7 = bodyB;
  v8 = this;
  v9 = input;
  hkTransformf::setMul(&v16, (hkTransformf *)bodyAin->m_motion, (hkTransformf *)&bodyAin->m_shape[2].m_type);
  v10 = v8->m_childAgent;
  v15 = v6;
  v14 = &v16;
  v11 = *(_QWORD *)&v5[1].m_memSizeAndFlags;
  v13 = 0;
  v12 = v11;
  ((void (__fastcall *)(hkpCollisionAgent *, __int64 *, hkpCdBody *, hkpCollisionInput *, hkpConstraintOwner *))v10->vfptr[4].__vecDelDtor)(
    v10,
    &v12,
    v7,
    v9,
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
void __usercall hkpTransformAgent::warpTime(hkpTransformAgent *this@<rcx>, float oldTime@<xmm1>, float newTime@<xmm2>, hkpCollisionInput *input@<r9>, __int64 a5@<rdx>, __int64 a6@<r8>)
{
  ((void (__fastcall *)(hkpCollisionAgent *, __int64, __int64, hkpCollisionInput *))this->m_childAgent->vfptr[5].__vecDelDtor)(
    this->m_childAgent,
    a5,
    a6,
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
  this->m_childAgent->vfptr[6].__vecDelDtor((hkBaseObject *)this->m_childAgent, newId);
}

// File Line: 287
// RVA: 0xCF5870
void __fastcall hkpTransformAgent::createZombie(hkpTransformAgent *this, __int64 idTobecomeZombie)
{
  ((void (__fastcall *)(hkpCollisionAgent *, __int64))this->m_childAgent->vfptr[6].__first_virtual_table_function__)(
    this->m_childAgent,
    idTobecomeZombie);
}

