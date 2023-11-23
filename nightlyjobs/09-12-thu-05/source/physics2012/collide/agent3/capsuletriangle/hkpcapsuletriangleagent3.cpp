// File Line: 34
// RVA: 0xD2C240
void __fastcall hkCapsuleTriangleAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs v1; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&v1.m_ignoreSymmetricVersion.m_bool = 0;
  v1.m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkCapsuleTriangleAgent3::create;
  v1.m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkCapsuleTriangleAgent3::process;
  v1.m_sepNormalFunc = (void (__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *, hkVector4f *))hkCapsuleTriangleAgent3::sepNormal;
  memset(&v1.m_updateFilterFunc, 0, 24);
  v1.m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkCapsuleTriangleAgent3::cleanup;
  v1.m_removePointFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkCapsuleTriangleAgent3::removePoint;
  v1.m_commitPotentialFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkCapsuleTriangleAgent3::commitPotential;
  v1.m_createZombieFunc = hkCapsuleTriangleAgent3::createZombie;
  v1.m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkCapsuleTriangleAgent3::destroy;
  v1.m_isPredictive.m_bool = 0;
  hkpCollisionDispatcher::registerAgent3(dispatcher, &v1, CAPSULE, TRIANGLE);
}

// File Line: 55
// RVA: 0xD2BAC0
char *__fastcall hkCapsuleTriangleAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, char *agentData)
{
  hkpShape *m_shape; // rcx

  m_shape = input->m_bodyB.m_storage->m_shape;
  entry->m_numContactPoints = 0;
  *(_DWORD *)agentData = -1;
  *((_WORD *)agentData + 2) = -1;
  hkpCollideTriangleUtil::setupPointTriangleDistanceCache(
    (hkVector4f *)&m_shape[1].m_type,
    (hkpCollideTriangleUtil::PointTriangleDistanceCache *)(agentData + 8));
  return agentData + 32;
}

// File Line: 75
// RVA: 0xD2BFB0
void __fastcall hkCapsuleTriangleAgent3::sepNormal(
        hkpAgent3Input *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormalOut)
{
  hkpCdBody *m_storage; // r10
  hkpCdBody *v5; // rax
  __m128 *m_motion; // rcx
  hkpShape *m_shape; // rbx
  hkpShape *v9; // r11
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 *v13; // rax
  __m128 v14; // xmm6
  __int64 i; // rcx
  __m128 v16; // xmm1
  __m128 *v17; // rax
  __int64 v18; // rcx
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 *p_m_type; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  hkVector4f capsAPoints; // [rsp+50h] [rbp-D8h] BYREF
  char v27[16]; // [rsp+60h] [rbp-C8h] BYREF
  hkVector4f triVertices; // [rsp+70h] [rbp-B8h] BYREF
  char v29[16]; // [rsp+90h] [rbp-98h] BYREF
  hkContactPoint points; // [rsp+A0h] [rbp-88h] BYREF
  __m128 v31; // [rsp+D0h] [rbp-58h]

  m_storage = input->m_bodyB.m_storage;
  v5 = input->m_bodyA.m_storage;
  m_motion = (__m128 *)input->m_bodyA.m_storage->m_motion;
  m_shape = v5->m_shape;
  v9 = m_storage->m_shape;
  v10 = *m_motion;
  v11 = m_motion[1];
  v12 = m_motion[2];
  v13 = (__m128 *)&v5->m_shape[2];
  v14 = m_motion[3];
  for ( i = 1i64; i >= 0; --i )
  {
    v16 = *v13--;
    *(__m128 *)((char *)v13 + v27 - (char *)m_shape - 48) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v10),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v11)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12)),
                                                              v14);
  }
  v17 = (__m128 *)m_storage->m_motion;
  v18 = 2i64;
  v19 = *v17;
  v20 = v17[1];
  v21 = v17[2];
  v22 = v17[3];
  p_m_type = (__m128 *)&v9[2].m_type;
  do
  {
    v24 = *p_m_type--;
    --v18;
    *(__m128 *)((char *)p_m_type + v29 - (char *)v9 - 64) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v20),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v19)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v21)),
                                                              v22);
  }
  while ( v18 >= 0 );
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&m_shape[1].vfptr,
    &triVertices,
    *(float *)&v9[1].vfptr,
    (hkpCollideTriangleUtil::PointTriangleDistanceCache *)(agentData + 8),
    3.40282e38,
    0,
    &points,
    0i64);
  v25 = _mm_cmplt_ps(
          _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255),
          _mm_shuffle_ps(v31, v31, 255));
  separatingNormalOut->m_quad = _mm_or_ps(_mm_andnot_ps(v25, v31), _mm_and_ps(points.m_separatingNormal.m_quad, v25));
}

// File Line: 110
// RVA: 0xD2C130
char *__fastcall hkCapsuleTriangleAgent3::cleanup(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  _WORD *v7; // rbx
  __int64 v8; // rdi
  __int64 v9; // rdx

  v7 = agentData;
  v8 = 3i64;
  do
  {
    v9 = (unsigned __int16)*v7;
    if ( (_WORD)v9 != 0xFFFF )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))mgr->vfptr[2].__first_virtual_table_function__)(
        mgr,
        v9,
        constraintOwner);
      *v7 = -1;
    }
    ++v7;
    --v8;
  }
  while ( v8 );
  return agentData + 32;
}

// File Line: 124
// RVA: 0xD2C1B0
void __fastcall hkCapsuleTriangleAgent3::removePoint(
        hkpAgentEntry *entry,
        _WORD *agentData,
        unsigned __int16 idToRemove)
{
  int v3; // ecx
  __int64 v4; // rax

  v3 = 0;
  v4 = 0i64;
  while ( agentData[v4] != idToRemove )
  {
    ++v4;
    ++v3;
    if ( v4 >= 3 )
      return;
  }
  agentData[v3] = -1;
}

// File Line: 137
// RVA: 0xD2C1E0
void __fastcall hkCapsuleTriangleAgent3::commitPotential(
        hkpAgentEntry *entry,
        _WORD *agentData,
        unsigned __int16 idToCommit)
{
  int v3; // ecx
  __int64 v4; // rax

  v3 = 0;
  v4 = 0i64;
  while ( agentData[v4] != 0xFFFF )
  {
    ++v4;
    ++v3;
    if ( v4 >= 3 )
      return;
  }
  agentData[v3] = idToCommit;
}

// File Line: 150
// RVA: 0xD2C220
void __fastcall hkCapsuleTriangleAgent3::createZombie(
        hkpAgentEntry *entry,
        void *agentData,
        unsigned __int16 idToConvert)
{
  ;
}

// File Line: 166
// RVA: 0xD2C230
// attributes: thunk
void __fastcall hkCapsuleTriangleAgent3::destroy(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkCapsuleTriangleAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 177
// RVA: 0xD2BB10
char *__fastcall hkCapsuleTriangleAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r10
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpCdBody *m_storage; // r8
  __int64 m_shape; // r9
  __m128 *m_motion; // rcx
  hkpShape *v14; // r10
  __m128 *v15; // rax
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __int64 i; // rcx
  __m128 v21; // xmm1
  __m128 *v22; // rax
  __int64 v23; // rcx
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 *v28; // rax
  __m128 v29; // xmm1
  hkVector4f **v30; // rdi
  __m128 m_storage_low; // xmm6
  float v32; // xmm6_4
  unsigned __int16 *featureIds; // r10
  hkVector4f *p_m_separatingNormal; // rsi
  hkContactPoint *p_points; // r13
  __int64 v36; // r14
  unsigned __int64 v37; // rax
  unsigned __int16 v38; // bx
  hkpContactMgr *v39; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  hkVector4f *v41; // rcx
  _QWORD *v42; // rdx
  hkVector4f *v43; // rax
  unsigned __int16 v44; // ax
  hkpCdBody *v45; // rax
  hkVector4f v46; // xmm1
  int v47; // eax
  __int64 v48; // rcx
  _QWORD *v49; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  _QWORD *v52; // rcx
  hkVector4f *v54; // rcx
  hkVector4f v55; // xmm0
  __m128 v56; // xmm1
  hkVector4f *v57; // rdx
  hkpFeatureOutput *featuresOut[2]; // [rsp+40h] [rbp-80h] BYREF
  __m128 m_quad; // [rsp+50h] [rbp-70h] BYREF
  hkpFeatureOutput v60; // [rsp+60h] [rbp-60h] BYREF
  __int64 v61; // [rsp+68h] [rbp-58h]
  hkpShape *v62; // [rsp+70h] [rbp-50h]
  __int64 v63; // [rsp+78h] [rbp-48h]
  hkContactPoint points; // [rsp+80h] [rbp-40h] BYREF
  __m128 v65; // [rsp+B0h] [rbp-10h]
  hkVector4f capsAPoints; // [rsp+E0h] [rbp+20h] BYREF
  char v67[16]; // [rsp+F0h] [rbp+30h] BYREF
  hkVector4f triVertices; // [rsp+100h] [rbp+40h] BYREF
  char v69[80]; // [rsp+120h] [rbp+60h] BYREF
  char v70[8]; // [rsp+190h] [rbp+D0h] BYREF
  __int64 v71; // [rsp+198h] [rbp+D8h]
  int v72; // [rsp+1A0h] [rbp+E0h]
  _OWORD *v73; // [rsp+1A8h] [rbp+E8h]
  hkVector4f **v74; // [rsp+1B0h] [rbp+F0h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtCapsTri3";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_storage = input->m_bodyB.m_storage;
  m_shape = (__int64)m_storage->m_shape;
  v72 = 0;
  m_motion = (__m128 *)input->m_bodyA.m_storage->m_motion;
  v14 = input->m_bodyA.m_storage->m_shape;
  v63 = m_shape;
  v62 = v14;
  v15 = (__m128 *)&v14[2];
  v16 = *m_motion;
  v17 = m_motion[1];
  v18 = m_motion[2];
  v19 = m_motion[3];
  for ( i = 1i64; i >= 0; --i )
  {
    v21 = *v15--;
    *(__m128 *)((char *)v15 + v67 - (char *)v14 - 48) = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v17),
                                                              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v16)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v18)),
                                                          v19);
  }
  v22 = (__m128 *)m_storage->m_motion;
  v23 = 2i64;
  v24 = *v22;
  v25 = v22[1];
  v26 = v22[2];
  v27 = v22[3];
  v28 = (__m128 *)(m_shape + 80);
  do
  {
    v29 = *v28--;
    --v23;
    *(__m128 *)&v69[(_QWORD)v28 - m_shape - 64] = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v25),
                                                        _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v24)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v26)),
                                                    v27);
  }
  while ( v23 >= 0 );
  hkCollideCapsuleUtilCapsVsTri(
    &capsAPoints,
    *(float *)&v14[1].vfptr,
    &triVertices,
    *(float *)(m_shape + 32),
    (hkpCollideTriangleUtil::PointTriangleDistanceCache *)(agentData + 8),
    3.40282e38,
    1,
    &points,
    &v60);
  v30 = v74;
  m_storage_low = (__m128)LODWORD(input->m_input.m_storage->m_tolerance.m_storage);
  LODWORD(v32) = _mm_shuffle_ps(m_storage_low, m_storage_low, 0).m128_u32[0];
  featureIds = v60.featureIds;
  p_m_separatingNormal = &points.m_separatingNormal;
  p_points = &points;
  v36 = 0i64;
  m_quad.m128_u64[0] = (unsigned __int64)v60.featureIds;
  v61 = _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255).m128_f32[0] >= _mm_shuffle_ps(v65, v65, 255).m128_f32[0];
  v37 = 3i64;
  m_quad.m128_u64[1] = 3i64;
  do
  {
    v38 = *(_WORD *)&agentData[2 * v36];
    if ( _mm_shuffle_ps(p_m_separatingNormal->m_quad, p_m_separatingNormal->m_quad, 255).m128_f32[0] >= v32 )
    {
      if ( v38 == 0xFFFF )
        goto LABEL_29;
      ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkVector4f *))input->m_contactMgr.m_storage->vfptr[2].__first_virtual_table_function__)(
        input->m_contactMgr.m_storage,
        v38,
        v30[1]);
      v37 = m_quad.m128_u64[1];
      featureIds = (unsigned __int16 *)m_quad.m128_u64[0];
      *(_WORD *)&agentData[2 * v36] = -1;
    }
    else
    {
      if ( v38 == 0xFFFF )
      {
        v39 = input->m_contactMgr.m_storage;
        vfptr = v39->vfptr;
        if ( v30[1554] )
        {
          ((void (__fastcall *)(hkpContactMgr *, hkpFeatureOutput *, __int64))vfptr[2].__vecDelDtor)(v39, &v60, 1i64);
          featureIds = (unsigned __int16 *)m_quad.m128_u64[0];
          if ( *(_DWORD *)&v60.numFeatures )
            goto LABEL_28;
          v41 = v30[1554];
          v42 = (_QWORD *)v41->m_quad.m128_u64[0];
          v41->m_quad.m128_u64[0] += 24i64;
          v43 = *v30;
          v42[2] = agentData;
          *v42 = v43;
          v42[1] = v71;
        }
        else
        {
          v44 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkVector4f **, _QWORD, hkContactPoint *))vfptr[1].__first_virtual_table_function__)(
                  v39,
                  input->m_bodyA.m_storage,
                  input->m_bodyB.m_storage,
                  input->m_input.m_storage,
                  v30,
                  0i64,
                  p_points);
          featureIds = (unsigned __int16 *)m_quad.m128_u64[0];
          v38 = v44;
          if ( v44 == 0xFFFF )
            goto LABEL_28;
        }
      }
      v70[0] = *(&v60.numFeatures + 8 * v36);
      if ( !v70[0] )
        goto LABEL_25;
      v45 = input->m_bodyA.m_storage;
      v46.m_quad = (__m128)p_m_separatingNormal[-1];
      m_quad = p_m_separatingNormal->m_quad;
      *(hkVector4f *)featuresOut = (hkVector4f)v46.m_quad;
      v47 = (*(__int64 (__fastcall **)(__int64, unsigned __int16 *, char *, hkpFeatureOutput **, const void *, hkpShape *, const void *, __m128 *))(*(_QWORD *)v63 + 104i64))(
              v63,
              featureIds,
              v70,
              featuresOut,
              input->m_bodyB.m_storage->m_motion,
              v62,
              v45->m_motion,
              &m_quad);
      p_m_separatingNormal[-1] = *(hkVector4f *)featuresOut;
      if ( v47 )
      {
        if ( v47 == 1 )
          p_m_separatingNormal->m_quad = _mm_shuffle_ps(
                                           m_quad,
                                           _mm_unpackhi_ps(m_quad, p_m_separatingNormal->m_quad),
                                           196);
LABEL_25:
        v54 = *v30;
        v55.m_quad = (__m128)p_m_separatingNormal[-1];
        ++v72;
        featureIds = (unsigned __int16 *)m_quad.m128_u64[0];
        *v30 = v54 + 3;
        *v54 = (hkVector4f)v55.m_quad;
        v56 = p_m_separatingNormal->m_quad;
        v54[2].m_quad.m128_i32[0] = v38;
        v54[1] = (hkVector4f)v56;
        if ( v36 == v61 )
        {
          v57 = v30[1554];
          if ( v57 )
          {
            *(_QWORD *)v57->m_quad.m128_u64[1] = v54;
            v57->m_quad.m128_u64[1] += 8i64;
          }
        }
LABEL_28:
        v37 = m_quad.m128_u64[1];
LABEL_29:
        *(_WORD *)&agentData[2 * v36] = v38;
        goto LABEL_19;
      }
      if ( v38 != 0xFFFF )
      {
        ((void (__fastcall *)(hkpContactMgr *, _QWORD, hkVector4f *))input->m_contactMgr.m_storage->vfptr[2].__first_virtual_table_function__)(
          input->m_contactMgr.m_storage,
          v38,
          v30[1]);
        *(_WORD *)&agentData[2 * v36] = -1;
      }
      v37 = m_quad.m128_u64[1];
      featureIds = (unsigned __int16 *)m_quad.m128_u64[0];
    }
LABEL_19:
    featureIds += 4;
    ++p_points;
    ++v36;
    p_m_separatingNormal += 2;
    --v37;
    m_quad.m128_u64[0] = (unsigned __int64)featureIds;
    m_quad.m128_u64[1] = v37;
  }
  while ( v37 );
  v48 = v71;
  *v73 = *((_OWORD *)&points.m_separatingNormal + 2 * v61);
  *(_BYTE *)(v48 + 2) = v72;
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "Et";
    v51 = __rdtsc();
    v52 = v50 + 2;
    *((_DWORD *)v52 - 2) = v51;
    v49[1] = v52;
  }
  return agentData + 32;
}

