// File Line: 18
// RVA: 0xD242E0
void __fastcall hkpSphereBoxAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpSphereBoxAgent::createBoxSphereAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, BOX, SPHERE);
  f.m_createFunc = hkpSphereBoxAgent::createSphereBoxAgent;
  f.m_getPenetrationsFunc = hkpSphereBoxAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSphereBoxAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, SPHERE, BOX);
}

// File Line: 46
// RVA: 0xD25050
hkpCollisionAgent *__fastcall hkpSphereBoxAgent::createBoxSphereAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::`vftable;
    result->m_contactMgr = mgr;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 53
// RVA: 0xD24FF0
hkpCollisionAgent *__fastcall hkpSphereBoxAgent::createSphereBoxAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpCollisionAgent *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpSphereBoxAgent::`vftable;
    result->m_contactMgr = mgr;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 59
// RVA: 0xD24FB0
void __fastcall hkpSphereBoxAgent::cleanup(hkpSphereBoxAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // r8
  __int64 m_contactPointId; // rdx

  v2 = constraintOwner;
  m_contactPointId = this->m_contactPointId;
  if ( (_WORD)m_contactPointId != 0xFFFF )
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      m_contactPointId,
      v2);
  ((void (__fastcall *)(hkpSphereBoxAgent *, __int64, hkpConstraintOwner *))this->vfptr->__vecDelDtor)(this, 1i64, v2);
}

// File Line: 126
// RVA: 0xD24390
void __fastcall hkpSphereBoxAgent::processCollision(
        hkpSphereBoxAgent *this,
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
  __m128 *m_motion; // rdx
  __m128 *v15; // r8
  __m128 v16; // xmm3
  hkpShape *m_shape; // r9
  __m128 v19; // xmm5
  hkpProcessCdPoint *m_storage; // rsi
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
  __m128 v38; // xmm0
  int v39; // eax
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm4
  unsigned __int16 m_contactPointId; // ax
  _QWORD *v45; // rax
  _QWORD *v46; // rcx
  _QWORD *v47; // r8
  unsigned __int64 v48; // rax
  _QWORD *v49; // rcx
  unsigned int resulta; // [rsp+C0h] [rbp+28h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtSphereBox";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  v15 = (__m128 *)bodyA->m_motion;
  v16 = m_motion[2];
  m_shape = bodyA->m_shape;
  v19 = _mm_sub_ps(v15[3], m_motion[3]);
  m_storage = result->m_firstFreeContactPoint.m_storage;
  v21 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v22 = _mm_movelh_ps(v21, v16);
  v23 = _mm_movehl_ps(v22, v21);
  v24 = *(__m128 *)&bodyB->m_shape[1].m_type.m_storage;
  v25 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v23, v16, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v22)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v16, 228),
                     _mm_shuffle_ps(v19, v19, 170)));
  *(float *)&resulta = *(float *)&bodyB->m_shape[1].vfptr + *(float *)&bodyA->m_shape[1].vfptr;
  v26 = _mm_shuffle_ps((__m128)resulta, (__m128)resulta, 0);
  v27 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v25, 1u), 1u);
  v28 = _mm_sub_ps(_mm_min_ps(v27, v24), v27);
  if ( (_mm_movemask_ps(_mm_cmplt_ps(v28, (__m128)0i64)) & 7) == 0 )
  {
    v37 = _mm_sub_ps(v27, v24);
    v38 = _mm_max_ps(
            _mm_shuffle_ps(v37, v37, 170),
            _mm_max_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
    v33 = _mm_sub_ps(v38, v26);
    v39 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmple_ps(v38, v37),
                                                                   *(__m128 *)&hkVector4fComparison_maskToComparison_359[28]))];
    v40 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v39], (__m128)v25);
    v41 = _mm_or_ps(_mm_shuffle_ps(v40, v40, 78), v40);
    v42 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v41, v41, 177), v41), (__m128)0i64),
                        0x1Fu),
                      0x1Fu),
            m_motion[v39]);
    m_storage->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, v33), 196);
    goto LABEL_9;
  }
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32 = _mm_andnot_ps(
          _mm_cmple_ps(v30, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)), _mm_mul_ps(*(__m128 *)_xmm, v31)));
  v33 = _mm_sub_ps(_mm_mul_ps(v32, v30), v26);
  if ( v33.m128_f32[0] <= _mm_shuffle_ps(
                            (__m128)LODWORD(input->m_tolerance.m_storage),
                            (__m128)LODWORD(input->m_tolerance.m_storage),
                            0).m128_f32[0] )
  {
    v34 = _mm_xor_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v25, 0x1Fu), 0x1Fu), _mm_mul_ps(v28, v32)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), m_motion[1]),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), *m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), m_motion[2]));
    m_storage->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v33), 196);
LABEL_9:
    v43 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_sub_ps((__m128)0i64, v33),
                _mm_shuffle_ps((__m128)LODWORD(m_shape[1].vfptr), (__m128)LODWORD(m_shape[1].vfptr), 0)),
              m_storage->m_contact.m_separatingNormal.m_quad),
            v15[3]);
    m_storage->m_contact.m_position.m_quad = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, query.m_quad), 196);
    if ( this->m_contactPointId == 0xFFFF )
      this->m_contactPointId = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                                 this->m_contactMgr,
                                 bodyA,
                                 bodyB,
                                 input,
                                 result,
                                 0i64,
                                 m_storage);
    m_contactPointId = this->m_contactPointId;
    if ( m_contactPointId != 0xFFFF )
    {
      m_storage->m_contactPointId = m_contactPointId;
      ++result->m_firstFreeContactPoint.m_storage;
    }
    goto LABEL_13;
  }
  v36 = this->m_contactPointId;
  if ( (_WORD)v36 != 0xFFFF )
  {
    ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpIterativeLinearCastAgent::hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
      this->m_contactMgr,
      v36,
      result->m_constraintOwner.m_storage);
    this->m_contactPointId = -1;
  }
LABEL_13:
  v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v46 = (_QWORD *)v45[1];
  v47 = v45;
  if ( (unsigned __int64)v46 < v45[3] )
  {
    *v46 = "Et";
    v48 = __rdtsc();
    v49 = v46 + 2;
    *((_DWORD *)v49 - 2) = v48;
    v47[1] = v49;
  }
}

// File Line: 165
// RVA: 0xD24750
void __fastcall hkpSphereBoxAgent::getClosestPoints(
        hkpSphereBoxAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_motion; // rdx
  hkpShape *m_shape; // r8
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
  hkpCdPointCollectorVtbl *vfptr; // rax
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  __m128 v45; // [rsp+20h] [rbp-98h] BYREF
  __m128 v46; // [rsp+30h] [rbp-88h]
  __m128 v47; // [rsp+40h] [rbp-78h]
  hkpCdBody *v48; // [rsp+50h] [rbp-68h]
  hkpCdBody *v49; // [rsp+58h] [rbp-60h]
  unsigned int v50; // [rsp+C8h] [rbp+10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSphereBox";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyA->m_shape;
  v14 = *((__m128 *)bodyA->m_motion + 3);
  v15 = m_motion[2];
  v16 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v17 = _mm_sub_ps(v14, m_motion[3]);
  v18 = _mm_movelh_ps(v16, v15);
  v19 = _mm_movehl_ps(v18, v16);
  v20 = *(__m128 *)&bodyB->m_shape[1].m_type.m_storage;
  v21 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v19, v15, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v18)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v15, 228),
                     _mm_shuffle_ps(v17, v17, 170)));
  *(float *)&v50 = *(float *)&bodyB->m_shape[1].vfptr + *(float *)&bodyA->m_shape[1].vfptr;
  v22 = _mm_shuffle_ps((__m128)v50, (__m128)v50, 0);
  v23 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v21, 1u), 1u);
  v24 = _mm_sub_ps(_mm_min_ps(v23, v20), v23);
  if ( (_mm_movemask_ps(_mm_cmplt_ps(v24, (__m128)0i64)) & 7) != 0 )
  {
    v25 = _mm_mul_ps(v24, v24);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_rsqrt_ps(v26);
    v28 = _mm_andnot_ps(
            _mm_cmple_ps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(*(__m128 *)_xmm, v27)));
    v29 = _mm_sub_ps(_mm_mul_ps(v28, v26), v22);
    if ( v29.m128_f32[0] > _mm_shuffle_ps(
                             (__m128)LODWORD(input->m_tolerance.m_storage),
                             (__m128)LODWORD(input->m_tolerance.m_storage),
                             0).m128_f32[0] )
      goto LABEL_8;
    v30 = _mm_xor_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v21, 0x1Fu), 0x1Fu), _mm_mul_ps(v24, v28)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), m_motion[1]),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), *m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), m_motion[2]));
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
                                                                   _mm_cmple_ps(v33, v32),
                                                                   *(__m128 *)&hkVector4fComparison_maskToComparison_359[28]))];
    v35 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v34], (__m128)v21);
    v36 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
    v31 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36), (__m128)0i64),
                        0x1Fu),
                      0x1Fu),
            m_motion[v34]);
  }
  v48 = bodyA;
  v49 = bodyB;
  vfptr = collector->vfptr;
  v38 = _mm_shuffle_ps((__m128)LODWORD(m_shape[1].vfptr), (__m128)LODWORD(m_shape[1].vfptr), 0);
  v46 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v29), 196);
  v47 = v46;
  v39 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, v29), v38), v46), v14);
  v45 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, query.m_quad), 196);
  vfptr->addCdPoint(collector, (hkpCdPoint *)&v45);
LABEL_8:
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = v41 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v42[1] = v44;
  }
}

// File Line: 179
// RVA: 0xD24A90
void __fastcall hkpSphereBoxAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 *m_motion; // rdx
  hkpShape *m_shape; // r8
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
  hkpCdPointCollectorVtbl *vfptr; // rax
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  __m128 v45; // [rsp+20h] [rbp-98h] BYREF
  __m128 v46; // [rsp+30h] [rbp-88h]
  __m128 v47; // [rsp+40h] [rbp-78h]
  hkpCdBody *v48; // [rsp+50h] [rbp-68h]
  hkpCdBody *v49; // [rsp+58h] [rbp-60h]
  unsigned int v50; // [rsp+C0h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSphereBox";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  m_shape = bodyA->m_shape;
  v14 = *((__m128 *)bodyA->m_motion + 3);
  v15 = m_motion[2];
  v16 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v17 = _mm_sub_ps(v14, m_motion[3]);
  v18 = _mm_movelh_ps(v16, v15);
  v19 = _mm_movehl_ps(v18, v16);
  v20 = *(__m128 *)&bodyB->m_shape[1].m_type.m_storage;
  v21 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v19, v15, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v18)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v15, 228),
                     _mm_shuffle_ps(v17, v17, 170)));
  *(float *)&v50 = *(float *)&bodyB->m_shape[1].vfptr + *(float *)&bodyA->m_shape[1].vfptr;
  v22 = _mm_shuffle_ps((__m128)v50, (__m128)v50, 0);
  v23 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v21, 1u), 1u);
  v24 = _mm_sub_ps(_mm_min_ps(v23, v20), v23);
  if ( (_mm_movemask_ps(_mm_cmplt_ps(v24, (__m128)0i64)) & 7) != 0 )
  {
    v25 = _mm_mul_ps(v24, v24);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_rsqrt_ps(v26);
    v28 = _mm_andnot_ps(
            _mm_cmple_ps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(*(__m128 *)_xmm, v27)));
    v29 = _mm_sub_ps(_mm_mul_ps(v28, v26), v22);
    if ( v29.m128_f32[0] > _mm_shuffle_ps(
                             (__m128)LODWORD(input->m_tolerance.m_storage),
                             (__m128)LODWORD(input->m_tolerance.m_storage),
                             0).m128_f32[0] )
      goto LABEL_8;
    v30 = _mm_xor_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v21, 0x1Fu), 0x1Fu), _mm_mul_ps(v24, v28)),
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), m_motion[1]),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), *m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), m_motion[2]));
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
                                                                   _mm_cmple_ps(v33, v32),
                                                                   *(__m128 *)&hkVector4fComparison_maskToComparison_359[28]))];
    v35 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v34], (__m128)v21);
    v36 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
    v31 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_cmplt_ps(_mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36), (__m128)0i64),
                        0x1Fu),
                      0x1Fu),
            m_motion[v34]);
  }
  vfptr = collector->vfptr;
  v48 = bodyA;
  v49 = bodyB;
  v38 = _mm_shuffle_ps((__m128)LODWORD(m_shape[1].vfptr), (__m128)LODWORD(m_shape[1].vfptr), 0);
  v46 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v29), 196);
  v47 = v46;
  v39 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_sub_ps((__m128)0i64, v29), v38), v46), v14);
  v45 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, query.m_quad), 196);
  vfptr->addCdPoint(collector, (hkpCdPoint *)&v45);
LABEL_8:
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = v41 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v42[1] = v44;
  }
}

// File Line: 193
// RVA: 0xD24E00
void __fastcall hkpSphereBoxAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // r8
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  __m128 *m_motion; // rcx
  __m128 *v12; // rax
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128i v17; // xmm1
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  unsigned int v25; // [rsp+50h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtSphereBox";
    v9 = __rdtsc();
    v10 = v8 + 2;
    *((_DWORD *)v10 - 2) = v9;
    Value[1] = v10;
  }
  m_motion = (__m128 *)bodyB->m_motion;
  v12 = (__m128 *)bodyA->m_motion;
  v13 = m_motion[2];
  v14 = _mm_sub_ps(v12[3], m_motion[3]);
  v15 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v16 = _mm_movelh_ps(v15, v13);
  v17 = (__m128i)_mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(_mm_movehl_ps(v16, v15), v13, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v16)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(v14, v14, 170),
                     _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v13, 228)));
  v18 = _mm_xor_ps(
          _mm_min_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32(v17, 1u), 1u),
            *(__m128 *)&bodyB->m_shape[1].m_type.m_storage),
          (__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu));
  v19 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), m_motion[1]),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *m_motion)),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v13)),
            m_motion[3]),
          v12[3]);
  v20 = _mm_mul_ps(v19, v19);
  *(float *)&v25 = *(float *)&bodyA->m_shape[1].vfptr + *(float *)&bodyB->m_shape[1].vfptr;
  v16.m128_f32[0] = _mm_shuffle_ps((__m128)v25, (__m128)v25, 0).m128_f32[0];
  if ( (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
             + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]) < (float)(v16.m128_f32[0] * v16.m128_f32[0]) )
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v23 = __rdtsc();
    v24 = v22 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v21[1] = v24;
  }
}

// File Line: 221
// RVA: 0xD24DE0
void __fastcall hkpSphereBoxAgent::getPenetrations(
        hkpSphereBoxAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpSphereBoxAgent::staticGetPenetrations(bodyA, bodyB, input, collector);
}

