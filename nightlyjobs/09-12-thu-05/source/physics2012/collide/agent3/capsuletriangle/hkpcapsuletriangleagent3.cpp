// File Line: 34
// RVA: 0xD2C240
void __fastcall hkCapsuleTriangleAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  signed __int64 (__fastcall *v1)(hkpAgent3Input *, hkpAgentEntry *, void *); // [rsp+20h] [rbp-68h]
  void (__fastcall *v2)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *); // [rsp+28h] [rbp-60h]
  signed __int64 (__fastcall *v3)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *); // [rsp+30h] [rbp-58h]
  void (__fastcall *v4)(hkpAgentEntry *, void *, unsigned __int16); // [rsp+38h] [rbp-50h]
  void (__fastcall *v5)(hkpAgentEntry *, void *, unsigned __int16); // [rsp+40h] [rbp-48h]
  void (__fastcall *v6)(hkpAgentEntry *, void *, unsigned __int16); // [rsp+48h] [rbp-40h]
  __int64 v7; // [rsp+50h] [rbp-38h]
  __int64 v8; // [rsp+58h] [rbp-30h]
  __int64 v9; // [rsp+60h] [rbp-28h]
  void (__fastcall *v10)(hkpAgent3Input *, hkpAgentEntry *, void *, hkVector4f *); // [rsp+68h] [rbp-20h]
  signed __int64 (__fastcall *v11)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *); // [rsp+70h] [rbp-18h]
  char v12; // [rsp+78h] [rbp-10h]
  __int16 v13; // [rsp+79h] [rbp-Fh]

  v13 = 0;
  v1 = hkCapsuleTriangleAgent3::create;
  v8 = 0i64;
  v11 = hkCapsuleTriangleAgent3::process;
  v9 = 0i64;
  v10 = hkCapsuleTriangleAgent3::sepNormal;
  v7 = 0i64;
  v3 = hkCapsuleTriangleAgent3::cleanup;
  v4 = hkCapsuleTriangleAgent3::removePoint;
  v5 = hkCapsuleTriangleAgent3::commitPotential;
  v6 = hkCapsuleTriangleAgent3::createZombie;
  v2 = hkCapsuleTriangleAgent3::destroy;
  v12 = 0;
  hkpCollisionDispatcher::registerAgent3(dispatcher, (hkpCollisionDispatcher::Agent3Funcs *)&v1, CAPSULE, TRIANGLE);
}

// File Line: 55
// RVA: 0xD2BAC0
signed __int64 __fastcall hkCapsuleTriangleAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData)
{
  char *v3; // rbx
  hkpShape *v4; // rcx

  v3 = (char *)agentData;
  v4 = input->m_bodyB.m_storage->m_shape;
  entry->m_numContactPoints = 0;
  *(_DWORD *)agentData = -1;
  *((_WORD *)agentData + 2) = -1;
  hkpCollideTriangleUtil::setupPointTriangleDistanceCache(
    (hkVector4f *)&v4[1].m_type,
    (hkpCollideTriangleUtil::PointTriangleDistanceCache *)((char *)agentData + 8));
  return (signed __int64)(v3 + 32);
}

// File Line: 75
// RVA: 0xD2BFB0
void __fastcall hkCapsuleTriangleAgent3::sepNormal(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormalOut)
{
  hkpCdBody *v4; // r10
  hkpCdBody *v5; // rax
  hkVector4f *v6; // rdi
  __m128 *v7; // rcx
  hkpShape *v8; // rbx
  hkpShape *v9; // r11
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 *v13; // rax
  __m128 v14; // xmm6
  signed __int64 v15; // rcx
  __m128 v16; // xmm1
  __m128 *v17; // rax
  signed __int64 v18; // rcx
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 *v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  hkVector4f capsAPoints; // [rsp+50h] [rbp-D8h]
  char v27[16]; // [rsp+60h] [rbp-C8h]
  hkVector4f triVertices; // [rsp+70h] [rbp-B8h]
  char v29[16]; // [rsp+90h] [rbp-98h]
  hkContactPoint points; // [rsp+A0h] [rbp-88h]
  __m128 v31; // [rsp+D0h] [rbp-58h]

  v4 = input->m_bodyB.m_storage;
  v5 = input->m_bodyA.m_storage;
  v6 = separatingNormalOut;
  v7 = (__m128 *)input->m_bodyA.m_storage->m_motion;
  v8 = v5->m_shape;
  v9 = v4->m_shape;
  v10 = *v7;
  v11 = v7[1];
  v12 = v7[2];
  v13 = (__m128 *)&v5->m_shape[2];
  v14 = v7[3];
  v15 = 1i64;
  do
  {
    v16 = *v13;
    --v13;
    --v15;
    *(__m128 *)((char *)v13 + v27 - (char *)v8 - 48) = _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v10),
                                                             _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v11)),
                                                           _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12)),
                                                         v14);
  }
  while ( v15 >= 0 );
  v17 = (__m128 *)v4->m_motion;
  v18 = 2i64;
  v19 = *v17;
  v20 = v17[1];
  v21 = v17[2];
  v22 = v17[3];
  v23 = (__m128 *)&v9[2].m_type;
  do
  {
    v24 = *v23;
    --v23;
    --v18;
    *(__m128 *)((char *)v23 + v29 - (char *)v9 - 64) = _mm_add_ps(
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
    *(float *)&v8[1].vfptr,
    &triVertices,
    *(float *)&v9[1].vfptr,
    (hkpCollideTriangleUtil::PointTriangleDistanceCache *)((char *)agentData + 8),
    3.40282e38,
    0,
    &points,
    0i64);
  v25 = _mm_cmpltps(
          _mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255),
          _mm_shuffle_ps(v31, v31, 255));
  v6->m_quad = _mm_or_ps(_mm_andnot_ps(v25, v31), _mm_and_ps(points.m_separatingNormal.m_quad, v25));
}

// File Line: 110
// RVA: 0xD2C130
signed __int64 __fastcall hkCapsuleTriangleAgent3::cleanup(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v4; // rbp
  hkpContactMgr *v5; // rsi
  char *v6; // r14
  _WORD *v7; // rbx
  signed __int64 v8; // rdi
  __int64 v9; // rdx

  v4 = constraintOwner;
  v5 = mgr;
  v6 = (char *)agentData;
  v7 = agentData;
  v8 = 3i64;
  do
  {
    v9 = (unsigned __int16)*v7;
    if ( (_WORD)v9 != -1 )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->vfptr[2].__first_virtual_table_function__)(
        v5,
        v9,
        v4);
      *v7 = -1;
    }
    ++v7;
    --v8;
  }
  while ( v8 );
  return (signed __int64)(v6 + 32);
}

// File Line: 124
// RVA: 0xD2C1B0
void __fastcall hkCapsuleTriangleAgent3::removePoint(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToRemove)
{
  int v3; // ecx
  signed __int64 v4; // rax

  v3 = 0;
  v4 = 0i64;
  while ( *((_WORD *)agentData + v4) != idToRemove )
  {
    ++v4;
    ++v3;
    if ( v4 >= 3 )
      return;
  }
  *((_WORD *)agentData + v3) = -1;
}

// File Line: 137
// RVA: 0xD2C1E0
void __fastcall hkCapsuleTriangleAgent3::commitPotential(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToCommit)
{
  int v3; // ecx
  signed __int64 v4; // rax

  v3 = 0;
  v4 = 0i64;
  while ( *((_WORD *)agentData + v4) != -1 )
  {
    ++v4;
    ++v3;
    if ( v4 >= 3 )
      return;
  }
  *((_WORD *)agentData + v3) = idToCommit;
}

// File Line: 150
// RVA: 0xD2C220
void __fastcall hkCapsuleTriangleAgent3::createZombie(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToConvert)
{
  ;
}

// File Line: 166
// RVA: 0xD2C230
void __fastcall hkCapsuleTriangleAgent3::destroy(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkCapsuleTriangleAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 177
// RVA: 0xD2BB10
signed __int64 __fastcall hkCapsuleTriangleAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal)
{
  hkpAgent3ProcessInput *v4; // r15
  char *v5; // r12
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r10
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpCdBody *v11; // r8
  __int64 v12; // r9
  __m128 *v13; // rcx
  __int64 v14; // r10
  __m128 *v15; // rax
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  signed __int64 v20; // rcx
  __m128 v21; // xmm1
  __m128 *v22; // rax
  signed __int64 v23; // rcx
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 *v28; // rax
  __m128 v29; // xmm1
  __m128i **v30; // rdi
  __m128 v31; // xmm6
  float v32; // xmm6_4
  unsigned __int16 *v33; // r10
  __m128i *v34; // rsi
  hkContactPoint *v35; // r13
  __int64 v36; // r14
  signed __int64 v37; // rax
  unsigned __int16 v38; // bx
  hkpContactMgr *v39; // rcx
  hkBaseObjectVtbl *v40; // rax
  __m128i *v41; // rcx
  _QWORD *v42; // rdx
  __m128i *v43; // rax
  unsigned __int16 v44; // ax
  hkpCdBody *v45; // rax
  __int64 v46; // r11
  __m128i v47; // xmm1
  int v48; // eax
  __int64 v49; // rcx
  _QWORD *v50; // r8
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rax
  signed __int64 v53; // rcx
  __m128i *v55; // rcx
  __m128i v56; // xmm0
  __m128i v57; // xmm1
  __m128i *v58; // rdx
  hkpFeatureOutput *featuresOut[2]; // [rsp+40h] [rbp-80h]
  __m128 v60; // [rsp+50h] [rbp-70h]
  hkpFeatureOutput v61; // [rsp+60h] [rbp-60h]
  _BOOL8 v62; // [rsp+68h] [rbp-58h]
  __int64 v63; // [rsp+70h] [rbp-50h]
  __int64 v64; // [rsp+78h] [rbp-48h]
  hkContactPoint points; // [rsp+80h] [rbp-40h]
  __m128 v66; // [rsp+B0h] [rbp-10h]
  hkVector4f capsAPoints; // [rsp+E0h] [rbp+20h]
  char v68[16]; // [rsp+F0h] [rbp+30h]
  hkVector4f triVertices; // [rsp+100h] [rbp+40h]
  char v70[80]; // [rsp+120h] [rbp+60h]
  char v71; // [rsp+190h] [rbp+D0h]
  __int64 v72; // [rsp+198h] [rbp+D8h]
  int v73; // [rsp+1A0h] [rbp+E0h]
  _OWORD *v74; // [rsp+1A8h] [rbp+E8h]
  __m128i **v75; // [rsp+1B0h] [rbp+F0h]

  v4 = input;
  v5 = (char *)agentData;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtCapsTri3";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v4->m_bodyB.m_storage;
  v12 = (__int64)v11->m_shape;
  v73 = 0;
  v13 = (__m128 *)v4->m_bodyA.m_storage->m_motion;
  v14 = (__int64)v4->m_bodyA.m_storage->m_shape;
  v64 = v12;
  v63 = v14;
  v15 = (__m128 *)(v14 + 64);
  v16 = *v13;
  v17 = v13[1];
  v18 = v13[2];
  v19 = v13[3];
  v20 = 1i64;
  do
  {
    v21 = *v15;
    --v15;
    --v20;
    *(__m128 *)&v68[(_QWORD)v15 - v14 - 48] = _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v17),
                                                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v16)),
                                                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v18)),
                                                v19);
  }
  while ( v20 >= 0 );
  v22 = (__m128 *)v11->m_motion;
  v23 = 2i64;
  v24 = *v22;
  v25 = v22[1];
  v26 = v22[2];
  v27 = v22[3];
  v28 = (__m128 *)(v12 + 80);
  do
  {
    v29 = *v28;
    --v28;
    --v23;
    *(__m128 *)&v70[(_QWORD)v28 - v12 - 64] = _mm_add_ps(
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
    *(float *)(v14 + 32),
    &triVertices,
    *(float *)(v12 + 32),
    (hkpCollideTriangleUtil::PointTriangleDistanceCache *)(v5 + 8),
    3.40282e38,
    1,
    &points,
    &v61);
  v30 = v75;
  v31 = (__m128)LODWORD(v4->m_input.m_storage->m_tolerance.m_storage);
  LODWORD(v32) = (unsigned __int128)_mm_shuffle_ps(v31, v31, 0);
  v33 = v61.featureIds;
  v34 = (__m128i *)&points.m_separatingNormal;
  v35 = &points;
  v36 = 0i64;
  v60.m128_u64[0] = (unsigned __int64)v61.featureIds;
  v62 = COERCE_FLOAT(_mm_shuffle_ps(points.m_separatingNormal.m_quad, points.m_separatingNormal.m_quad, 255)) >= COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 255));
  v37 = 3i64;
  v60.m128_u64[1] = 3i64;
  do
  {
    v38 = *(_WORD *)&v5[2 * v36];
    if ( COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)v34, *(__m128 *)v34, 255)) >= v32 )
    {
      if ( v38 == -1 )
        goto LABEL_29;
      ((void (__fastcall *)(hkpContactMgr *, _QWORD, __m128i *))v4->m_contactMgr.m_storage->vfptr[2].__first_virtual_table_function__)(
        v4->m_contactMgr.m_storage,
        v38,
        v30[1]);
      v37 = v60.m128_i64[1];
      v33 = (unsigned __int16 *)v60.m128_u64[0];
      *(_WORD *)&v5[2 * v36] = -1;
    }
    else
    {
      if ( v38 == -1 )
      {
        v39 = v4->m_contactMgr.m_storage;
        v40 = v39->vfptr;
        if ( v30[1554] )
        {
          ((void (__fastcall *)(hkpContactMgr *, hkpFeatureOutput *, signed __int64))v40[2].__vecDelDtor)(
            v39,
            &v61,
            1i64);
          v33 = (unsigned __int16 *)v60.m128_u64[0];
          if ( *(_DWORD *)&v61.numFeatures )
            goto LABEL_28;
          v41 = v30[1554];
          v42 = (_QWORD *)v41->m128i_i64[0];
          v41->m128i_i64[0] += 24i64;
          v43 = *v30;
          v42[2] = v5;
          *v42 = v43;
          v42[1] = v72;
        }
        else
        {
          v44 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *))v40[1].__first_virtual_table_function__)(
                  v39,
                  v4->m_bodyA.m_storage,
                  v4->m_bodyB.m_storage,
                  v4->m_input.m_storage);
          v33 = (unsigned __int16 *)v60.m128_u64[0];
          v38 = v44;
          if ( v44 == -1 )
            goto LABEL_28;
        }
      }
      v71 = *(&v61.numFeatures + 8 * v36);
      if ( !v71 )
        goto LABEL_25;
      v45 = v4->m_bodyA.m_storage;
      v46 = v64;
      v47 = v34[-1];
      _mm_store_si128((__m128i *)&v60, *v34);
      _mm_store_si128((__m128i *)featuresOut, v47);
      v48 = (*(__int64 (__fastcall **)(__int64, unsigned __int16 *, char *, hkpFeatureOutput **, const void *, __int64, const void *, __m128 *))(*(_QWORD *)v46 + 104i64))(
              v46,
              v33,
              &v71,
              featuresOut,
              v4->m_bodyB.m_storage->m_motion,
              v63,
              v45->m_motion,
              &v60);
      v34[-1] = *(__m128i *)featuresOut;
      if ( v48 )
      {
        if ( v48 == 1 )
          *(__m128 *)v34 = _mm_shuffle_ps(v60, _mm_unpackhi_ps(v60, *(__m128 *)v34), 196);
LABEL_25:
        v55 = *v30;
        v56 = v34[-1];
        ++v73;
        v33 = (unsigned __int16 *)v60.m128_u64[0];
        *v30 = v55 + 3;
        *v55 = v56;
        v57 = *v34;
        v55[2].m128i_i32[0] = v38;
        v55[1] = v57;
        if ( v36 == v62 )
        {
          v58 = v30[1554];
          if ( v58 )
          {
            *(_QWORD *)v58->m128i_i64[1] = v55;
            v58->m128i_i64[1] += 8i64;
          }
        }
LABEL_28:
        v37 = v60.m128_i64[1];
LABEL_29:
        *(_WORD *)&v5[2 * v36] = v38;
        goto LABEL_19;
      }
      if ( v38 != -1 )
      {
        ((void (__fastcall *)(hkpContactMgr *, _QWORD, __m128i *))v4->m_contactMgr.m_storage->vfptr[2].__first_virtual_table_function__)(
          v4->m_contactMgr.m_storage,
          v38,
          v30[1]);
        *(_WORD *)&v5[2 * v36] = -1;
      }
      v37 = v60.m128_i64[1];
      v33 = (unsigned __int16 *)v60.m128_u64[0];
    }
LABEL_19:
    v33 += 4;
    ++v35;
    ++v36;
    v34 += 2;
    --v37;
    v60.m128_u64[0] = (unsigned __int64)v33;
    v60.m128_u64[1] = v37;
  }
  while ( v37 );
  v49 = v72;
  *v74 = *((_OWORD *)&points.m_separatingNormal + 2 * v62);
  *(_BYTE *)(v49 + 2) = v73;
  v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v51 = (_QWORD *)v50[1];
  if ( (unsigned __int64)v51 < v50[3] )
  {
    *v51 = "Et";
    v52 = __rdtsc();
    v53 = (signed __int64)(v51 + 2);
    *(_DWORD *)(v53 - 8) = v52;
    v50[1] = v53;
  }
  return (signed __int64)(v5 + 32);
}

