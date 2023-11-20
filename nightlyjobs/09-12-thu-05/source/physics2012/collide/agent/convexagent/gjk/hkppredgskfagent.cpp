// File Line: 24
// RVA: 0xD19C30
void __fastcall hkpPredGskfAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpPredGskfAgent::createPredGskfAgent;
  f.m_getPenetrationsFunc = hkpGskBaseAgent::staticGetPenetrations;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_getClosestPointFunc = hkpGskBaseAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, CONVEX);
}

// File Line: 40
// RVA: 0xD1A2B0
void __fastcall hkpPredGskfAgent::createPredGskfAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rdi
  hkpCdBody *v6; // rsi
  _QWORD **v7; // rax
  hkpGskfAgent *v8; // rax
  hkpGskfAgent *v9; // rbx
  _QWORD **v10; // rax
  hkpGskBaseAgent *v11; // rax

  v4 = bodyA;
  v5 = mgr;
  v6 = bodyB;
  if ( mgr )
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 144i64);
    v9 = v8;
    if ( v8 )
    {
      hkpGskfAgent::hkpGskfAgent(v8, v4, v6, v5);
      v9->vfptr = (hkBaseObjectVtbl *)&hkpPredGskfAgent::`vftable';
    }
  }
  else
  {
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkpGskBaseAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 64i64);
    if ( v11 )
      hkpGskBaseAgent::hkpGskBaseAgent(v11, v4, v6, 0i64);
  }
}

// File Line: 55
// RVA: 0xD19C90
void __usercall hkpPredGskfAgent::processCollision(hkpPredGskfAgent *this@<rcx>, hkpCdBody *bodyA@<rdx>, hkpCdBody *bodyB@<r8>, hkpProcessCollisionInput *input@<r9>, hkpProcessCollisionOutput *a5@<rdi>, hkpProcessCollisionOutput *output)
{
  hkpPredGskfAgent *v6; // rdi
  hkpProcessCollisionInput *v7; // rsi
  hkpCdBody *v8; // r14
  hkpCdBody *v9; // r15
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  float v15; // xmm1_4
  int explicitlyAllowNewPoint; // er12
  hkpProcessCollisionOutput *v17; // rbx
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  char *v23; // rcx
  unsigned int v24; // eax
  unsigned int v25; // edx
  hkpShape *v26; // rcx
  __int64 v27; // r8
  hkpShape *v28; // rbx
  __m128 *v29; // rcx
  __m128 *v30; // rax
  unsigned int *v31; // rdx
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 v34; // xmm0
  __m128 v35; // xmm4
  __m128 v36; // xmm5
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm6
  __m128 v41; // xmm0
  __m128 *v42; // rcx
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  unsigned __int64 v48; // rax
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  hkpShape *v52; // rcx
  float *v53; // r12
  unsigned __int8 v54; // al
  float v55; // xmm0_4
  __m128 *v56; // rax
  __int64 v57; // rcx
  __m128 v58; // xmm3
  __m128 v59; // xmm4
  __m128 v60; // xmm5
  __m128 v61; // xmm6
  __int64 v62; // r8
  __m128 *v63; // rdx
  __m128 v64; // xmm1
  char *v65; // rbx
  __m128 *v66; // rax
  __m128 v67; // xmm3
  __m128 v68; // xmm4
  __m128 v69; // xmm5
  __m128 v70; // xmm6
  __int64 v71; // rdx
  signed __int64 v72; // rax
  __m128 v73; // xmm1
  hkpCdBody bodyAa; // [rsp+40h] [rbp-B8h]
  hkpCdBody bodyBa; // [rsp+60h] [rbp-98h]
  hkpGsk gsk; // [rsp+88h] [rbp-70h]
  hkTransformf v77; // [rsp+228h] [rbp+130h]
  hkTransformf transformOut; // [rsp+268h] [rbp+170h]
  signed __int64 retaddr; // [rsp+2E8h] [rbp+1F0h]
  hkpProcessCollisionOutput *processOut; // [rsp+308h] [rbp+210h]

  processOut = a5;
  v6 = this;
  v7 = input;
  v8 = bodyA;
  v9 = bodyB;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtGsk";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = v7->m_stepInfo.m_startTime.m_storage;
  explicitlyAllowNewPoint = 0;
  if ( v15 != v6->m_timeOfSeparatingNormal )
  {
    if ( !v7->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
    {
      v6->m_timeOfSeparatingNormal = v7->m_stepInfo.m_endTime.m_storage;
      goto LABEL_6;
    }
    v23 = (char *)v8->m_motion;
    bodyAa.m_motion = &transformOut;
    bodyAa.m_shape = v8->m_shape;
    v24 = v8->m_shapeKey;
    bodyAa.m_parent = v8;
    bodyAa.m_shapeKey = v24;
    bodyBa.m_parent = v9;
    bodyBa.m_motion = &v77;
    bodyBa.m_shape = v9->m_shape;
    bodyBa.m_shapeKey = v9->m_shapeKey;
    hkSweptTransformUtil::lerp2((hkSweptTransformf *)(v23 + 64), v15, &transformOut);
    hkSweptTransformUtil::lerp2(
      (hkSweptTransformf *)((char *)v9->m_motion + 64),
      v7->m_stepInfo.m_startTime.m_storage,
      &v77);
    v25 = *((unsigned __int8 *)&v6->m_cache + 10);
    v26 = v8->m_shape;
    v27 = (unsigned __int8)v6->m_cache.m_dimA;
    v28 = v9->m_shape;
    gsk.m_dimB.m_storage = (unsigned __int8)v6->m_cache.m_dimB;
    *(_QWORD *)&gsk.m_doNotHandlePenetration.m_storage = 0i64;
    *(_QWORD *)&gsk.m_maxDimB.m_storage = v25 >> 4;
    gsk.m_dimA.m_storage = v27;
    gsk.m_maxDimA.m_storage = v25 & 0xF;
    ((void (__fastcall *)(hkpShape *, hkpGskCache *, __int64, hkcdVertex *))v26->vfptr[4].__first_virtual_table_function__)(
      v26,
      &v6->m_cache,
      v27,
      gsk.m_verticesA);
    ((void (__fastcall *)(hkpShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v28->vfptr[4].__first_virtual_table_function__)(
      v28,
      &v6->m_cache.m_vertices[gsk.m_dimA.m_storage],
      (unsigned int)gsk.m_dimB.m_storage,
      gsk.m_verticesBinB);
    hkpGskBaseAgent::calcSeparatingNormal(
      &bodyAa,
      &bodyBa,
      v7->m_collisionQualityInfo.m_storage->m_keepContact,
      &gsk,
      &v6->m_separatingNormal);
    if ( gsk.m_featureChange.m_storage )
      hkpGsk::exitAndExportCacheImpl(&gsk, &v6->m_cache);
  }
  v6->m_timeOfSeparatingNormal = v7->m_stepInfo.m_endTime.m_storage;
  v29 = (__m128 *)v8->m_motion;
  v30 = (__m128 *)v9->m_motion;
  v31 = (unsigned int *)v7->m_collisionQualityInfo.m_storage;
  v32 = v29[5];
  v33 = v30[5];
  v34 = _mm_shuffle_ps(
          (__m128)LODWORD(v7->m_stepInfo.m_deltaTime.m_storage),
          (__m128)LODWORD(v7->m_stepInfo.m_deltaTime.m_storage),
          0);
  v35 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), v34);
  v36 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), v34);
  v37 = _mm_mul_ps(_mm_sub_ps(v29[4], v32), v35);
  v38 = _mm_mul_ps(_mm_shuffle_ps(v29[9], v29[9], 255), v35);
  v39 = v6->m_separatingNormal.m_quad;
  v40 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v33, v30[4]), v36), v37);
  v41 = (__m128)v29[10].m128_u32[0];
  v42 = &v6->m_separatingNormal.m_quad;
  v43 = _mm_mul_ps(
          _mm_mul_ps(_mm_shuffle_ps(v30[9], v30[9], 255), v36),
          _mm_shuffle_ps((__m128)v30[10].m128_u32[0], (__m128)v30[10].m128_u32[0], 0));
  v44 = _mm_shuffle_ps((__m128)LODWORD(v6->m_allowedPenetration), (__m128)LODWORD(v6->m_allowedPenetration), 0);
  *(__m128 *)&bodyBa.m_parent = v44;
  v45 = _mm_shuffle_ps(v40, _mm_unpackhi_ps(v40, _mm_add_ps(_mm_mul_ps(v38, _mm_shuffle_ps(v41, v41, 0)), v43)), 196);
  v46 = _mm_mul_ps(v45, v39);
  v47 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v39, v39, 255),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
              _mm_shuffle_ps(v46, v46, 170))),
          _mm_shuffle_ps(v45, v45, 255));
  if ( v47.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)*v31, (__m128)*v31, 0))
    || v47.m128_f32[0] <= (float)(v44.m128_f32[0] * 0.5) )
  {
    if ( v31[4] )
    {
      v48 = (unsigned __int64)v6->m_contactMgr;
      v49 = *v42;
      *(_QWORD *)&gsk.m_doNotHandlePenetration.m_storage = 0i64;
      *(_QWORD *)&gsk.m_dimA.m_storage = v8;
      *(_QWORD *)&gsk.m_maxDimA.m_storage = v9;
      *(_QWORD *)(&gsk.m_featureChange + 1) = v7;
      gsk.m_dummy[1].m_quad.m128_i32[0] = v47.m128_i32[0];
      gsk.m_dummy[2].m_quad = v45;
      v50 = _mm_shuffle_ps(v49, v49, 255);
      gsk.m_verticesA[0].m_quad.m128_u64[0] = v48;
      *(__m128 *)&bodyBa.m_shape = _mm_min_ps(
                                     _mm_mul_ps(_mm_shuffle_ps((__m128)v31[6], (__m128)v31[6], 0), v44),
                                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v31[7], (__m128)v31[7], 0), v44), v50));
      if ( v47.m128_f32[0] < *(float *)&bodyBa.m_shape )
      {
        v17 = processOut;
        *(__m128 *)&bodyAa.m_shape = _mm_min_ps(
                                       _mm_mul_ps(_mm_shuffle_ps((__m128)v31[10], (__m128)v31[10], 0), v44),
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps((__m128)v31[11], (__m128)v31[11], 0), v44),
                                         v50));
        hk4dGskCollideCalcToi(
          (hkpAgent3ProcessInput *)&gsk,
          (hkSimdFloat32 *)&bodyBa.m_parent,
          (hkSimdFloat32 *)&bodyBa,
          (hkSimdFloat32 *)&bodyAa,
          &v6->m_cache,
          &v6->m_separatingNormal,
          processOut);
        goto $PROCESS_AT_T1;
      }
    }
    if ( v47.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)v31[3], (__m128)v31[3], 0)) )
    {
LABEL_6:
      v17 = processOut;
$PROCESS_AT_T1:
      hkpGskfAgent::processCollisionNoTim((hkpGskfAgent *)&v6->vfptr, v8, v9, v7, explicitlyAllowNewPoint, v17);
      goto $END_OF_FUNCTION;
    }
    v51 = _mm_shuffle_ps(*v42, _mm_unpackhi_ps(*v42, v47), 196);
    *v42 = v51;
    v52 = v8->m_shape;
    v53 = (float *)v9->m_shape;
    v54 = v6->m_manifold.m_numContactPoints;
    gsk.m_verticesBinB[3].m_quad.m128_i32[2] = LODWORD(v7->m_tolerance.m_storage);
    gsk.m_verticesBinB[3].m_quad.m128_i32[0] = (int)v52[1].vfptr;
    v55 = v53[8];
    gsk.m_verticesBinB[2].m_quad = v51;
    gsk.m_verticesBinB[3].m_quad.m128_f32[1] = v55;
    gsk.m_verticesBinB[3].m_quad.m128_f32[3] = (float)((float)(gsk.m_verticesBinB[3].m_quad.m128_f32[0]
                                                             + gsk.m_verticesBinB[3].m_quad.m128_f32[2])
                                                     + v55)
                                             * (float)((float)(gsk.m_verticesBinB[3].m_quad.m128_f32[0]
                                                             + gsk.m_verticesBinB[3].m_quad.m128_f32[2])
                                                     + v55);
    if ( v54 )
    {
      retaddr = (signed __int64)&v6->m_manifold.m_contactPoints[v54];
      ((void (__fastcall *)(hkpShape *, signed __int64, _QWORD, hkpGsk *))v52->vfptr[4].__first_virtual_table_function__)(
        v52,
        retaddr,
        (unsigned __int8)v6->m_manifold.m_numVertsA,
        &gsk);
      v56 = (__m128 *)v8->m_motion;
      v57 = (unsigned __int8)v6->m_manifold.m_numVertsA;
      v58 = *v56;
      v59 = v56[1];
      v60 = v56[2];
      v61 = v56[3];
      v62 = (signed int)v57 - 1;
      v63 = (__m128 *)((char *)&gsk + 16 * v62);
      do
      {
        v64 = *v63;
        --v63;
        --v62;
        v63[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v64, v64, 85), v59),
                       _mm_mul_ps(_mm_shuffle_ps(v64, v64, 0), v58)),
                     _mm_mul_ps(_mm_shuffle_ps(v64, v64, 170), v60)),
                   v61);
      }
      while ( v62 >= 0 );
      v65 = (char *)&gsk + 16 * v57;
      (*(void (__fastcall **)(float *, signed __int64, _QWORD, char *))(*(_QWORD *)v53 + 72i64))(
        v53,
        retaddr + 2 * v57,
        (unsigned __int8)v6->m_manifold.m_numVertsB,
        v65);
      v66 = (__m128 *)v9->m_motion;
      v67 = *v66;
      v68 = v66[1];
      v69 = v66[2];
      v70 = v66[3];
      v71 = (unsigned __int8)v6->m_manifold.m_numVertsB - 1;
      v72 = (signed __int64)&v65[16 * v71];
      do
      {
        v73 = *(__m128 *)v72;
        v72 -= 16i64;
        --v71;
        *(__m128 *)(v72 + 16) = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), v68),
                                      _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), v67)),
                                    _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), v69)),
                                  v70);
      }
      while ( v71 >= 0 );
    }
    explicitlyAllowNewPoint = hkGskManifold_verifyAndGetPoints(
                                &v6->m_manifold,
                                (hkpGskManifoldWork *)&gsk,
                                0,
                                processOut,
                                v6->m_contactMgr);
    if ( explicitlyAllowNewPoint && v6->m_cache.m_gskFlags < 0 )
    {
      v17 = processOut;
      v17->m_firstFreeContactPoint.m_storage -= (unsigned __int8)v6->m_manifold.m_numContactPoints;
      goto $PROCESS_AT_T1;
    }
  }
  else
  {
    *v42 = _mm_shuffle_ps(*v42, _mm_unpackhi_ps(*v42, v47), 196);
    if ( v6->m_manifold.m_numContactPoints )
      hkGskManifold_cleanup(&v6->m_manifold, v6->m_contactMgr, processOut->m_constraintOwner.m_storage);
  }
$END_OF_FUNCTION:
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  v20 = v18;
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v21 = __rdtsc();
    v22 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v20[1] = v22;
  }
}ntOwner.m_storage);
  }
$END_OF_FUNCTION:
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  v20 = v18;
  if ( (unsig

