// File Line: 18
// RVA: 0xD242E0
void __fastcall hkpSphereBoxAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpSphereBoxAgent::createBoxSphereAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BOX, 0);
  f.m_createFunc = hkpSphereBoxAgent::createSphereBoxAgent;
  f.m_getPenetrationsFunc = hkpSphereBoxAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSphereBoxAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, 0, BOX);
}

// File Line: 46
// RVA: 0xD25050
hkpCollisionAgent *__fastcall hkpSphereBoxAgent::createBoxSphereAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpCollisionAgent *result; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::`vftable';
    result->m_contactMgr = v4;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 53
// RVA: 0xD24FF0
hkpCollisionAgent *__fastcall hkpSphereBoxAgent::createSphereBoxAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v4; // rbx
  _QWORD **v5; // rax
  hkpCollisionAgent *result; // rax

  v4 = mgr;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereBoxAgent::`vftable';
    result->m_contactMgr = v4;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 59
// RVA: 0xD24FB0
void __fastcall hkpSphereBoxAgent::cleanup(hkpSphereBoxAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 v3; // rdx
  hkpSphereBoxAgent *v4; // rbx

  v2 = constraintOwner;
  v3 = this->m_contactPointId;
  v4 = this;
  if ( (_WORD)v3 != -1 )
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      v3,
      v2);
  ((void (__fastcall *)(hkpSphereBoxAgent *, signed __int64, hkpConstraintOwner *))v4->vfptr->__vecDelDtor)(
    v4,
    1i64,
    v2);
}

// File Line: 126
// RVA: 0xD24390
void __fastcall hkpSphereBoxAgent::processCollision(hkpSphereBoxAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpSphereBoxAgent *v5; // rbx
  hkpProcessCollisionInput *v6; // rbp
  hkpCdBody *v7; // r15
  hkpCdBody *v8; // r12
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __m128 *v14; // rdx
  __m128 *v15; // r8
  __m128 v16; // xmm3
  hkpProcessCollisionOutput *v17; // r14
  hkpShape *v18; // r9
  __m128 v19; // xmm5
  hkpProcessCdPoint *v20; // rsi
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128i v25; // xmm6
  __m128 v26; // xmm9
  __m128 v27; // xmm2
  __m128 v28; // xmm8
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm7
  __m128 v33; // xmm5
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __int64 v36; // rdx
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  __m128 v39; // xmm0
  int v40; // eax
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  unsigned __int16 v45; // ax
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  unsigned int resulta; // [rsp+C0h] [rbp+28h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtSphereBox";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = (__m128 *)v7->m_motion;
  v15 = (__m128 *)v8->m_motion;
  v16 = v14[2];
  v17 = result;
  v18 = v8->m_shape;
  v19 = _mm_sub_ps(v15[3], v14[3]);
  v20 = result->m_firstFreeContactPoint.m_storage;
  v21 = _mm_unpacklo_ps(*v14, v14[1]);
  v22 = _mm_movelh_ps(v21, v16);
  v23 = _mm_movehl_ps(v22, v21);
  v24 = *(__m128 *)&v7->m_shape[1].m_type.m_storage;
  v25 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v23, v16, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v22)),
                   _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v14, v14[1]), v16, 228), _mm_shuffle_ps(v19, v19, 170)));
  *(float *)&resulta = *(float *)&v7->m_shape[1].vfptr + *(float *)&v8->m_shape[1].vfptr;
  v26 = _mm_shuffle_ps((__m128)resulta, (__m128)resulta, 0);
  v27 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v25, 1u), 1u);
  v28 = _mm_sub_ps(_mm_min_ps(v27, v24), v27);
  if ( !(_mm_movemask_ps(_mm_cmpltps(v28, (__m128)0i64)) & 7) )
  {
    v37 = _mm_sub_ps(v27, v24);
    v38 = _mm_max_ps(
            _mm_shuffle_ps(v37, v37, 170),
            _mm_max_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
    v39 = v38;
    v33 = _mm_sub_ps(v38, v26);
    v40 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmpleps(v39, v37),
                                                                   *(__m128 *)&hkVector4fComparison_maskToComparison_359[28]))];
    v41 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v40], (__m128)v25);
    v42 = _mm_or_ps(_mm_shuffle_ps(v41, v41, 78), v41);
    v43 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v42, v42, 177), v42), (__m128)0i64),
                        0x1Fu),
                      0x1Fu),
            v14[v40]);
    v20->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, v33), 196);
    goto LABEL_9;
  }
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32 = _mm_andnot_ps(
          _mm_cmpleps(v30, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)), _mm_mul_ps(*(__m128 *)_xmm, v31)));
  v33 = _mm_sub_ps(_mm_mul_ps(v32, v30), v26);
  if ( v33.m128_f32[0] <= COERCE_FLOAT(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(v6->m_tolerance.m_storage),
                              (__m128)LODWORD(v6->m_tolerance.m_storage),
                              0)) )
  {
    v34 = _mm_xor_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v25, 0x1Fu), 0x1Fu), _mm_mul_ps(v28, v32)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v14[1]), _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), *v14)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v14[2]));
    v20->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v33), 196);
LABEL_9:
    v44 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_sub_ps((__m128)0i64, v33),
                _mm_shuffle_ps((__m128)LODWORD(v18[1].vfptr), (__m128)LODWORD(v18[1].vfptr), 0)),
              v20->m_contact.m_separatingNormal.m_quad),
            v15[3]);
    v20->m_contact.m_position.m_quad = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, query.m_quad), 196);
    if ( v5->m_contactPointId == -1 )
      v5->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                               v5->m_contactMgr,
                               v8,
                               v7,
                               v6,
                               v17,
                               0i64,
                               v20);
    v45 = v5->m_contactPointId;
    if ( v45 != -1 )
    {
      v20->m_contactPointId = v45;
      ++v17->m_firstFreeContactPoint.m_storage;
    }
    goto LABEL_13;
  }
  v36 = v5->m_contactPointId;
  if ( (_WORD)v36 != -1 )
  {
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
      v5->m_contactMgr,
      v36,
      v17->m_constraintOwner.m_storage);
    v5->m_contactPointId = -1;
  }
LABEL_13:
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  v48 = v46;
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "Et";
    v49 = __rdtsc();
    v50 = (signed __int64)(v47 + 2);
    *(_DWORD *)(v50 - 8) = v49;
    v48[1] = v50;
  }
}

// File Line: 165
// RVA: 0xD24750
void __fastcall hkpSphereBoxAgent::getClosestPoints(hkpSphereBoxAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCollisionInput *v5; // rsi
  hkpCdBody *v6; // rbx
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rdx
  hkpShape *v13; // r8
  __m128 v14; // xmm10
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128i v21; // xmm6
  __m128 v22; // xmm9
  __m128 v23; // xmm2
  __m128 v24; // xmm8
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm7
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __int64 v34; // rcx
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  hkpCdPointCollectorVtbl *v37; // rax
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  __m128 v45; // [rsp+20h] [rbp-98h]
  __m128 v46; // [rsp+30h] [rbp-88h]
  __m128 v47; // [rsp+40h] [rbp-78h]
  hkpCdBody *v48; // [rsp+50h] [rbp-68h]
  hkpCdBody *v49; // [rsp+58h] [rbp-60h]
  unsigned int v50; // [rsp+C8h] [rbp+10h]

  v5 = input;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereBox";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v6->m_motion;
  v13 = v7->m_shape;
  v14 = *((__m128 *)v7->m_motion + 3);
  v15 = v12[2];
  v16 = _mm_unpacklo_ps(*v12, v12[1]);
  v17 = _mm_sub_ps(v14, v12[3]);
  v18 = _mm_movelh_ps(v16, v15);
  v19 = _mm_movehl_ps(v18, v16);
  v20 = *(__m128 *)&v6->m_shape[1].m_type.m_storage;
  v21 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v19, v15, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v18)),
                   _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v12, v12[1]), v15, 228), _mm_shuffle_ps(v17, v17, 170)));
  *(float *)&v50 = *(float *)&v6->m_shape[1].vfptr + *(float *)&v7->m_shape[1].vfptr;
  v22 = _mm_shuffle_ps((__m128)v50, (__m128)v50, 0);
  v23 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v21, 1u), 1u);
  v24 = _mm_sub_ps(_mm_min_ps(v23, v20), v23);
  if ( _mm_movemask_ps(_mm_cmpltps(v24, (__m128)0i64)) & 7 )
  {
    v25 = _mm_mul_ps(v24, v24);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_rsqrt_ps(v26);
    v28 = _mm_andnot_ps(
            _mm_cmpleps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(*(__m128 *)_xmm, v27)));
    v29 = _mm_sub_ps(_mm_mul_ps(v28, v26), v22);
    if ( v29.m128_f32[0] > COERCE_FLOAT(
                             _mm_shuffle_ps(
                               (__m128)LODWORD(v5->m_tolerance.m_storage),
                               (__m128)LODWORD(v5->m_tolerance.m_storage),
                               0)) )
      goto LABEL_8;
    v30 = _mm_xor_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v21, 0x1Fu), 0x1Fu), _mm_mul_ps(v24, v28)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v12[1]), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), *v12)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v12[2]));
  }
  else
  {
    v32 = _mm_sub_ps(v23, v20);
    v33 = _mm_max_ps(
            _mm_shuffle_ps(v32, v32, 170),
            _mm_max_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)));
    v29 = _mm_sub_ps(v33, v22);
    v34 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmpleps(v33, v32),
                                                                   *(__m128 *)&hkVector4fComparison_maskToComparison_359[28]))];
    v35 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v34], (__m128)v21);
    v36 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
    v31 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36), (__m128)0i64),
                        0x1Fu),
                      0x1Fu),
            v12[v34]);
  }
  v48 = v7;
  v49 = v6;
  v37 = collector->vfptr;
  v38 = _mm_shuffle_ps((__m128)LODWORD(v13[1].vfptr), (__m128)LODWORD(v13[1].vfptr), 0);
  v46 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v29), 196);
  v47 = v46;
  v39 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, v29), v38), v46), v14);
  v45 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, query.m_quad), 196);
  v37->addCdPoint(collector, (hkpCdPoint *)&v45);
LABEL_8:
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v41 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v42[1] = v44;
  }
}

// File Line: 179
// RVA: 0xD24A90
void __fastcall hkpSphereBoxAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdPointCollector *v5; // rbx
  hkpCollisionInput *v6; // rbp
  hkpCdBody *v7; // rdi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rdx
  hkpShape *v13; // r8
  __m128 v14; // xmm10
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128i v21; // xmm6
  __m128 v22; // xmm9
  __m128 v23; // xmm2
  __m128 v24; // xmm8
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm7
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __int64 v34; // rcx
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  hkpCdPointCollectorVtbl *v37; // rax
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  __m128 v45; // [rsp+20h] [rbp-98h]
  __m128 v46; // [rsp+30h] [rbp-88h]
  __m128 v47; // [rsp+40h] [rbp-78h]
  hkpCdBody *v48; // [rsp+50h] [rbp-68h]
  hkpCdBody *v49; // [rsp+58h] [rbp-60h]
  unsigned int v50; // [rsp+C0h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtSphereBox";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v7->m_motion;
  v13 = v4->m_shape;
  v14 = *((__m128 *)v4->m_motion + 3);
  v15 = v12[2];
  v16 = _mm_unpacklo_ps(*v12, v12[1]);
  v17 = _mm_sub_ps(v14, v12[3]);
  v18 = _mm_movelh_ps(v16, v15);
  v19 = _mm_movehl_ps(v18, v16);
  v20 = *(__m128 *)&v7->m_shape[1].m_type.m_storage;
  v21 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v19, v15, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v18)),
                   _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v12, v12[1]), v15, 228), _mm_shuffle_ps(v17, v17, 170)));
  *(float *)&v50 = *(float *)&v7->m_shape[1].vfptr + *(float *)&v4->m_shape[1].vfptr;
  v22 = _mm_shuffle_ps((__m128)v50, (__m128)v50, 0);
  v23 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v21, 1u), 1u);
  v24 = _mm_sub_ps(_mm_min_ps(v23, v20), v23);
  if ( _mm_movemask_ps(_mm_cmpltps(v24, (__m128)0i64)) & 7 )
  {
    v25 = _mm_mul_ps(v24, v24);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_rsqrt_ps(v26);
    v28 = _mm_andnot_ps(
            _mm_cmpleps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(*(__m128 *)_xmm, v27)));
    v29 = _mm_sub_ps(_mm_mul_ps(v28, v26), v22);
    if ( v29.m128_f32[0] > COERCE_FLOAT(
                             _mm_shuffle_ps(
                               (__m128)LODWORD(v6->m_tolerance.m_storage),
                               (__m128)LODWORD(v6->m_tolerance.m_storage),
                               0)) )
      goto LABEL_8;
    v30 = _mm_xor_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v21, 0x1Fu), 0x1Fu), _mm_mul_ps(v24, v28)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v12[1]), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), *v12)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v12[2]));
  }
  else
  {
    v32 = _mm_sub_ps(v23, v20);
    v33 = _mm_max_ps(
            _mm_shuffle_ps(v32, v32, 170),
            _mm_max_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)));
    v29 = _mm_sub_ps(v33, v22);
    v34 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmpleps(v33, v32),
                                                                   *(__m128 *)&hkVector4fComparison_maskToComparison_359[28]))];
    v35 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v34], (__m128)v21);
    v36 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
    v31 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmpltps(_mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36), (__m128)0i64),
                        0x1Fu),
                      0x1Fu),
            v12[v34]);
  }
  v37 = v5->vfptr;
  v48 = v4;
  v49 = v7;
  v38 = _mm_shuffle_ps((__m128)LODWORD(v13[1].vfptr), (__m128)LODWORD(v13[1].vfptr), 0);
  v46 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v29), 196);
  v47 = v46;
  v39 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, v29), v38), v46), v14);
  v45 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, query.m_quad), 196);
  v37->addCdPoint(v5, (hkpCdPoint *)&v45);
LABEL_8:
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v41 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v42[1] = v44;
  }
}

// File Line: 193
// RVA: 0xD24E00
void __fastcall hkpSphereBoxAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // rsi
  hkpCdBodyPairCollector *v5; // rbx
  hkpCdBody *v6; // rdi
  _QWORD *v7; // r8
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  __m128 *v11; // rcx
  __m128 *v12; // rax
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128i v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  unsigned int v25; // [rsp+50h] [rbp+8h]

  v4 = bodyA;
  v5 = collector;
  v6 = bodyB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtSphereBox";
    v9 = __rdtsc();
    v10 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v7[1] = v10;
  }
  v11 = (__m128 *)v6->m_motion;
  v12 = (__m128 *)v4->m_motion;
  v13 = v11[2];
  v14 = _mm_sub_ps(v12[3], v11[3]);
  v15 = _mm_unpacklo_ps(*v11, v11[1]);
  v16 = _mm_movelh_ps(v15, v13);
  v17 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(_mm_movehl_ps(v16, v15), v13, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v16)),
                   _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v11, v11[1]), v13, 228)));
  v18 = _mm_xor_ps(
          _mm_min_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v17, 1u), 1u), *(__m128 *)&v6->m_shape[1].m_type.m_storage),
          (__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu));
  v19 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v11[1]),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *v11)),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v11[2])),
            v11[3]),
          v12[3]);
  v20 = _mm_mul_ps(v19, v19);
  *(float *)&v25 = *(float *)&v4->m_shape[1].vfptr + *(float *)&v6->m_shape[1].vfptr;
  v16.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps((__m128)v25, (__m128)v25, 0);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))) < (float)(v16.m128_f32[0] * v16.m128_f32[0]) )
    v5->vfptr->addCdBodyPair(v5, v4, v6);
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

// File Line: 221
// RVA: 0xD24DE0
void __fastcall hkpSphereBoxAgent::getPenetrations(hkpSphereBoxAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpSphereBoxAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

