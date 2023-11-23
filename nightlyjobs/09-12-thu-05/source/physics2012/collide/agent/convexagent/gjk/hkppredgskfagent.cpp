// File Line: 24
// RVA: 0xD19C30
void __fastcall hkpPredGskfAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpPredGskfAgent::createPredGskfAgent;
  f.m_getPenetrationsFunc = hkpGskBaseAgent::staticGetPenetrations;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_getClosestPointFunc = hkpGskBaseAgent::staticGetClosestPoints;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, CONVEX, CONVEX);
}

// File Line: 40
// RVA: 0xD1A2B0
void __fastcall hkpPredGskfAgent::createPredGskfAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpGskfAgent *v8; // rax
  hkpGskfAgent *v9; // rbx
  _QWORD **v10; // rax
  hkpGskBaseAgent *v11; // rax

  if ( mgr )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpGskfAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
    v9 = v8;
    if ( v8 )
    {
      hkpGskfAgent::hkpGskfAgent(v8, bodyA, bodyB, mgr);
      v9->vfptr = (hkBaseObjectVtbl *)&hkpPredGskfAgent::`vftable;
    }
  }
  else
  {
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkpGskBaseAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 64i64);
    if ( v11 )
      hkpGskBaseAgent::hkpGskBaseAgent(v11, bodyA, bodyB, 0i64);
  }
}

// File Line: 55
// RVA: 0xD19C90
void __fastcall hkpPredGskfAgent::processCollision(
        hkpPredGskfAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output)
{
  hkpProcessCollisionOutput *v5; // rdi
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  float m_storage; // xmm1_4
  int explicitlyAllowNewPoint; // r12d
  hkpProcessCollisionOutput *v17; // rbx
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
  char *m_motion; // rcx
  unsigned int m_shapeKey; // eax
  unsigned int v25; // edx
  hkpShape *m_shape; // rcx
  __int64 m_dimA; // r8
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
  hkVector4f v39; // xmm4
  __m128 v40; // xmm6
  __m128 v41; // xmm0
  hkVector4f *p_m_separatingNormal; // rcx
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  hkpContactMgr *m_contactMgr; // rax
  __m128 m_quad; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  hkpShape *v52; // rcx
  float *v53; // r12
  unsigned __int8 m_numContactPoints; // al
  float v55; // xmm0_4
  __m128 *v56; // rax
  __int64 m_numVertsA; // rcx
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
  __m128 *v72; // rax
  __m128 v73; // xmm1
  hkpCdBody bodyAa; // [rsp+40h] [rbp-B8h] BYREF
  char bodyBa[40]; // [rsp+60h] [rbp-98h] BYREF
  hkpGsk gsk; // [rsp+88h] [rbp-70h] BYREF
  hkTransformf v77; // [rsp+228h] [rbp+130h] BYREF
  hkTransformf transformOut; // [rsp+268h] [rbp+170h] BYREF
  char *retaddr; // [rsp+2E8h] [rbp+1F0h]
  hkpProcessCollisionOutput *processOut; // [rsp+308h] [rbp+210h]

  processOut = v5;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtGsk";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  m_storage = input->m_stepInfo.m_startTime.m_storage;
  explicitlyAllowNewPoint = 0;
  if ( m_storage != this->m_timeOfSeparatingNormal )
  {
    if ( !input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
    {
      this->m_timeOfSeparatingNormal = input->m_stepInfo.m_endTime.m_storage;
      goto LABEL_6;
    }
    m_motion = (char *)bodyA->m_motion;
    bodyAa.m_motion = &transformOut;
    bodyAa.m_shape = bodyA->m_shape;
    m_shapeKey = bodyA->m_shapeKey;
    bodyAa.m_parent = bodyA;
    bodyAa.m_shapeKey = m_shapeKey;
    *(_QWORD *)&bodyBa[24] = bodyB;
    *(_QWORD *)&bodyBa[16] = &v77;
    *(_QWORD *)bodyBa = bodyB->m_shape;
    *(_DWORD *)&bodyBa[8] = bodyB->m_shapeKey;
    hkSweptTransformUtil::lerp2((hkSweptTransformf *)(m_motion + 64), m_storage, &transformOut);
    hkSweptTransformUtil::lerp2(
      (hkSweptTransformf *)((char *)bodyB->m_motion + 64),
      input->m_stepInfo.m_startTime.m_storage,
      &v77);
    v25 = *((unsigned __int8 *)&this->m_cache + 10);
    m_shape = bodyA->m_shape;
    m_dimA = (unsigned __int8)this->m_cache.m_dimA;
    v28 = bodyB->m_shape;
    gsk.m_dimB.m_storage = (unsigned __int8)this->m_cache.m_dimB;
    gsk.m_featureChange.m_storage = 0;
    *(_QWORD *)&gsk.m_maxDimB.m_storage = v25 >> 4;
    gsk.m_dimA.m_storage = m_dimA;
    gsk.m_maxDimA.m_storage = v25 & 0xF;
    ((void (__fastcall *)(hkpShape *, hkpGskCache *, __int64, hkcdVertex *))m_shape->vfptr[4].__first_virtual_table_function__)(
      m_shape,
      &this->m_cache,
      m_dimA,
      gsk.m_verticesA);
    ((void (__fastcall *)(hkpShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v28->vfptr[4].__first_virtual_table_function__)(
      v28,
      &this->m_cache.m_vertices[gsk.m_dimA.m_storage],
      (unsigned int)gsk.m_dimB.m_storage,
      gsk.m_verticesBinB);
    hkpGskBaseAgent::calcSeparatingNormal(
      &bodyAa,
      (hkpCdBody *)bodyBa,
      input->m_collisionQualityInfo.m_storage->m_keepContact,
      &gsk,
      &this->m_separatingNormal);
    if ( gsk.m_featureChange.m_storage )
      hkpGsk::exitAndExportCacheImpl(&gsk, &this->m_cache);
  }
  this->m_timeOfSeparatingNormal = input->m_stepInfo.m_endTime.m_storage;
  v29 = (__m128 *)bodyA->m_motion;
  v30 = (__m128 *)bodyB->m_motion;
  v31 = (unsigned int *)input->m_collisionQualityInfo.m_storage;
  v32 = v29[5];
  v33 = v30[5];
  v34 = _mm_shuffle_ps(
          (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
          (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
          0);
  v35 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), v34);
  v36 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), v34);
  v37 = _mm_mul_ps(_mm_sub_ps(v29[4], v32), v35);
  v38 = _mm_mul_ps(_mm_shuffle_ps(v29[9], v29[9], 255), v35);
  v39.m_quad = (__m128)this->m_separatingNormal;
  v40 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v33, v30[4]), v36), v37);
  v41 = (__m128)v29[10].m128_u32[0];
  p_m_separatingNormal = &this->m_separatingNormal;
  v43 = _mm_mul_ps(
          _mm_mul_ps(_mm_shuffle_ps(v30[9], v30[9], 255), v36),
          _mm_shuffle_ps((__m128)v30[10].m128_u32[0], (__m128)v30[10].m128_u32[0], 0));
  v44 = _mm_shuffle_ps((__m128)LODWORD(this->m_allowedPenetration), (__m128)LODWORD(this->m_allowedPenetration), 0);
  *(__m128 *)&bodyBa[24] = v44;
  v45 = _mm_shuffle_ps(v40, _mm_unpackhi_ps(v40, _mm_add_ps(_mm_mul_ps(v38, _mm_shuffle_ps(v41, v41, 0)), v43)), 196);
  v46 = _mm_mul_ps(v45, v39.m_quad);
  v47 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v39.m_quad, v39.m_quad, 255),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
              _mm_shuffle_ps(v46, v46, 170))),
          _mm_shuffle_ps(v45, v45, 255));
  if ( v47.m128_f32[0] <= _mm_shuffle_ps((__m128)*v31, (__m128)*v31, 0).m128_f32[0]
    || v47.m128_f32[0] <= (float)(v44.m128_f32[0] * 0.5) )
  {
    if ( v31[4] )
    {
      m_contactMgr = this->m_contactMgr;
      m_quad = p_m_separatingNormal->m_quad;
      *(_QWORD *)&gsk.m_doNotHandlePenetration.m_storage = 0i64;
      *(_QWORD *)&gsk.m_dimA.m_storage = bodyA;
      *(_QWORD *)&gsk.m_maxDimA.m_storage = bodyB;
      *(_QWORD *)(&gsk.m_featureChange + 1) = input;
      gsk.m_dummy[1].m_quad.m128_i32[0] = v47.m128_i32[0];
      gsk.m_dummy[2].m_quad = v45;
      v50 = _mm_shuffle_ps(m_quad, m_quad, 255);
      gsk.m_verticesA[0].m_quad.m128_u64[0] = (unsigned __int64)m_contactMgr;
      *(__m128 *)bodyBa = _mm_min_ps(
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v31[6], (__m128)v31[6], 0), v44),
                            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v31[7], (__m128)v31[7], 0), v44), v50));
      if ( v47.m128_f32[0] < *(float *)bodyBa )
      {
        v17 = processOut;
        *(__m128 *)&bodyAa.m_shape = _mm_min_ps(
                                       _mm_mul_ps(_mm_shuffle_ps((__m128)v31[10], (__m128)v31[10], 0), v44),
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps((__m128)v31[11], (__m128)v31[11], 0), v44),
                                         v50));
        hk4dGskCollideCalcToi(
          (hkpAgent3ProcessInput *)&gsk,
          (hkSimdFloat32 *)&bodyBa[24],
          (hkSimdFloat32 *)bodyBa,
          (hkSimdFloat32 *)&bodyAa,
          &this->m_cache,
          &this->m_separatingNormal,
          processOut);
        goto $PROCESS_AT_T1;
      }
    }
    if ( v47.m128_f32[0] <= _mm_shuffle_ps((__m128)v31[3], (__m128)v31[3], 0).m128_f32[0] )
    {
LABEL_6:
      v17 = processOut;
$PROCESS_AT_T1:
      hkpGskfAgent::processCollisionNoTim(this, bodyA, bodyB, input, explicitlyAllowNewPoint, v17);
      goto $END_OF_FUNCTION;
    }
    v51 = _mm_shuffle_ps(p_m_separatingNormal->m_quad, _mm_unpackhi_ps(p_m_separatingNormal->m_quad, v47), 196);
    *p_m_separatingNormal = (hkVector4f)v51;
    v52 = bodyA->m_shape;
    v53 = (float *)bodyB->m_shape;
    m_numContactPoints = this->m_manifold.m_numContactPoints;
    gsk.m_verticesBinB[3].m_quad.m128_i32[2] = LODWORD(input->m_tolerance.m_storage);
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
    if ( m_numContactPoints )
    {
      retaddr = &this->m_manifold.m_padding[8 * m_numContactPoints - 32];
      ((void (__fastcall *)(hkpShape *, char *, _QWORD, hkpGsk *))v52->vfptr[4].__first_virtual_table_function__)(
        v52,
        retaddr,
        (unsigned __int8)this->m_manifold.m_numVertsA,
        &gsk);
      v56 = (__m128 *)bodyA->m_motion;
      m_numVertsA = (unsigned __int8)this->m_manifold.m_numVertsA;
      v58 = *v56;
      v59 = v56[1];
      v60 = v56[2];
      v61 = v56[3];
      v62 = (int)m_numVertsA - 1;
      v63 = (__m128 *)((char *)&gsk + 16 * v62);
      do
      {
        v64 = *v63--;
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
      v65 = (char *)&gsk + 16 * m_numVertsA;
      (*(void (__fastcall **)(float *, char *, _QWORD, char *))(*(_QWORD *)v53 + 72i64))(
        v53,
        &retaddr[2 * m_numVertsA],
        (unsigned __int8)this->m_manifold.m_numVertsB,
        v65);
      v66 = (__m128 *)bodyB->m_motion;
      v67 = *v66;
      v68 = v66[1];
      v69 = v66[2];
      v70 = v66[3];
      v71 = (unsigned __int8)this->m_manifold.m_numVertsB - 1;
      v72 = (__m128 *)&v65[16 * v71];
      do
      {
        v73 = *v72--;
        --v71;
        v72[1] = _mm_add_ps(
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
                                &this->m_manifold,
                                (hkpGskManifoldWork *)&gsk,
                                0,
                                processOut,
                                this->m_contactMgr);
    if ( explicitlyAllowNewPoint && this->m_cache.m_gskFlags < 0 )
    {
      v17 = processOut;
      processOut->m_firstFreeContactPoint.m_storage -= (unsigned __int8)this->m_manifold.m_numContactPoints;
      goto $PROCESS_AT_T1;
    }
  }
  else
  {
    p_m_separatingNormal->m_quad = _mm_shuffle_ps(
                                     p_m_separatingNormal->m_quad,
                                     _mm_unpackhi_ps(p_m_separatingNormal->m_quad, v47),
                                     196);
    if ( this->m_manifold.m_numContactPoints )
      hkGskManifold_cleanup(&this->m_manifold, this->m_contactMgr, processOut->m_constraintOwner.m_storage);
  }
$END_OF_FUNCTION:
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  v20 = v18;
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v21 = __rdtsc();
    v22 = v19 + 2;
    *((_DWORD *)v22 - 2) = v21;
    v20[1] = v22;
  }
}

