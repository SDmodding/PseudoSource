// File Line: 26
// RVA: 0xD36000
void __fastcall hkpGskBaseAgent::processCollision(
        hkpGskBaseAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input)
{
  ;
}

// File Line: 34
// RVA: 0xD369B0
void __fastcall hkpGskBaseAgent::hkpGskBaseAgent(
        hkpGskBaseAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpContactMgr *mgr)
{
  hkpConvexShape *m_shape; // r14
  hkpTriangleShape *v5; // rbp
  hkpCdBody *v6; // rdi
  hkpCdBody *v7; // rbx
  hkpGskCache *p_m_cache; // rcx
  hkpCdBody *i; // rax
  hkpCdBody *j; // rax
  hkTransformf btoa; // [rsp+20h] [rbp-58h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpGskBaseAgent::`vftable;
  m_shape = (hkpConvexShape *)bodyA->m_shape;
  v5 = (hkpTriangleShape *)bodyB->m_shape;
  v6 = bodyB;
  v7 = bodyA;
  hkTransformf::setMulInverseMul(&btoa, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  p_m_cache = &this->m_cache;
  if ( v5->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(p_m_cache, m_shape, v5, &btoa);
  else
    hkpGskCache::init(p_m_cache, m_shape, v5, &btoa);
  this->m_separatingNormal = 0i64;
  this->m_separatingNormal.m_quad.m128_i32[3] = -1082130432;
  this->m_timeOfSeparatingNormal = -1.0;
  for ( i = v7->m_parent; i; i = i->m_parent )
    v7 = i;
  for ( j = v6->m_parent; j; j = j->m_parent )
    v6 = j;
  this->m_allowedPenetration = fminf(*(float *)&v7[3].m_shapeKey, *(float *)&v6[3].m_shapeKey);
}

// File Line: 59
// RVA: 0xD36D80
void __fastcall hkpGskBaseAgent::invalidateTim(hkpGskBaseAgent *this, hkpCollisionInput *input)
{
  this->m_timeOfSeparatingNormal = -1.0;
  this->m_separatingNormal = 0i64;
}

// File Line: 68
// RVA: 0xD36990
void __fastcall hkpGskBaseAgent::cleanup(hkpGskBaseAgent *this, hkpConstraintOwner *constraintOwner)
{
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 76
// RVA: 0xD36DA0
void __fastcall hkpGskBaseAgent::warpTime(
        hkpGskBaseAgent *this,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  if ( oldTime == this->m_timeOfSeparatingNormal )
  {
    this->m_timeOfSeparatingNormal = newTime;
  }
  else
  {
    this->m_timeOfSeparatingNormal = -1.0;
    this->m_separatingNormal = 0i64;
  }
}

// File Line: 141
// RVA: 0xD36AC0
void __fastcall hkpGskBaseAgent::calcSeparatingNormal(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        float earlyOutTolerance,
        hkpGsk *gsk,
        hkVector4f *separatingNormalOut)
{
  hkpConvexShape *m_shape; // rbp
  hkpConvexShape *v6; // rsi
  float v9; // xmm3_4
  hkVector4f v10; // [rsp+30h] [rbp-58h] BYREF
  hkTransformf aTb; // [rsp+40h] [rbp-48h] BYREF

  m_shape = (hkpConvexShape *)bodyB->m_shape;
  v6 = (hkpConvexShape *)bodyA->m_shape;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  hkpGsk::getClosestFeature(gsk, v6, m_shape, &aTb, &v10);
  v9 = v10.m_quad.m128_f32[3];
  separatingNormalOut->m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v10.m_quad, v10.m_quad, 85),
                                      *((__m128 *)bodyA->m_motion + 1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 0), *(__m128 *)bodyA->m_motion)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(v10.m_quad, v10.m_quad, 170),
                                    *((__m128 *)bodyA->m_motion + 2)));
  separatingNormalOut->m_quad.m128_f32[3] = (float)(v9 - v6->m_radius) - m_shape->m_radius;
}

// File Line: 220
// RVA: 0xD36580
void __fastcall hkpGskBaseAgent::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpConvexShape *m_shape; // r14
  hkpTriangleShape *v14; // rsi
  hkpConvexShape *v15; // r14
  hkpConvexShape *v16; // rsi
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v18; // xmm7
  float v19; // xmm3_4
  bool v20; // cf
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 *m_motion; // r9
  const void *v26; // r8
  hkBaseObjectVtbl *v27; // r10
  int v28; // eax
  __m128 *v29; // rax
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm6
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  hkpCdPointCollectorVtbl *v35; // rax
  _QWORD *v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  hkpGskCache cache; // [rsp+40h] [rbp-B8h] BYREF
  __int128 v42; // [rsp+50h] [rbp-A8h] BYREF
  char out[56]; // [rsp+60h] [rbp-98h] BYREF
  __int128 v44; // [rsp+98h] [rbp-60h]
  __m128 v45; // [rsp+A8h] [rbp-50h]
  __m128 v46; // [rsp+B8h] [rbp-40h] BYREF
  __m128 v47; // [rsp+C8h] [rbp-30h]
  hkVector4f separatingNormal; // [rsp+D8h] [rbp-20h] BYREF
  hkTransformf btoa; // [rsp+E8h] [rbp-10h] BYREF
  __int128 v50[3]; // [rsp+128h] [rbp+30h] BYREF
  hkpCdBody *v51; // [rsp+158h] [rbp+60h]
  hkpCdBody *v52; // [rsp+160h] [rbp+68h]
  hkpGsk v53; // [rsp+168h] [rbp+70h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtGsk";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_shape = (hkpConvexShape *)bodyA->m_shape;
  v14 = (hkpTriangleShape *)bodyB->m_shape;
  hkTransformf::setMulInverseMul(&btoa, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  if ( v14->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(&cache, m_shape, v14, &btoa);
  else
    hkpGskCache::init(&cache, m_shape, v14, &btoa);
  v15 = (hkpConvexShape *)bodyA->m_shape;
  v16 = (hkpConvexShape *)bodyB->m_shape;
  v53.m_dimB.m_storage = (unsigned __int8)cache.m_dimB;
  v53.m_featureChange.m_storage = 0;
  *(_QWORD *)&v53.m_maxDimB.m_storage = *((unsigned __int8 *)&cache + 10) >> 4;
  v53.m_maxDimA.m_storage = *((_BYTE *)&cache + 10) & 0xF;
  vfptr = v15->vfptr;
  v53.m_dimA.m_storage = (unsigned __int8)cache.m_dimA;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, _QWORD, hkcdVertex *))vfptr[4].__first_virtual_table_function__)(
    v15,
    &cache,
    (unsigned __int8)cache.m_dimA,
    v53.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v16->vfptr[4].__first_virtual_table_function__)(
    v16,
    &cache.m_vertices[v53.m_dimA.m_storage],
    (unsigned int)v53.m_dimB.m_storage,
    v53.m_verticesBinB);
  if ( hkpGsk::getClosestFeature(&v53, v15, v16, &btoa, &separatingNormal) == HK_GSK_OK )
  {
    hkpGsk::convertFeatureToClosestDistance(&v53, &separatingNormal, (hkpGskOut *)out);
    v18 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)out, *(__m128 *)out, 85), *((__m128 *)bodyA->m_motion + 1)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)out, *(__m128 *)out, 0), *(__m128 *)bodyA->m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)out, *(__m128 *)out, 170), *((__m128 *)bodyA->m_motion + 2)));
    v44 = (__int128)v18;
    v45 = v18;
    v19 = (float)(*(float *)&out[24] - v15->m_radius) - v16->m_radius;
    v20 = v19 < input->m_tolerance.m_storage;
    *(float *)&out[24] = v19;
    if ( v20 )
    {
      *(__m128 *)&out[16] = _mm_add_ps(
                              *(__m128 *)&out[16],
                              _mm_mul_ps(
                                _mm_shuffle_ps(
                                  (__m128)(unsigned int)(LODWORD(v15->m_radius) ^ _xmm[0]),
                                  (__m128)(unsigned int)(LODWORD(v15->m_radius) ^ _xmm[0]),
                                  0),
                                *(__m128 *)out));
      v21 = _mm_sub_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)(unsigned int)(LODWORD(v19) ^ _xmm[0]),
                    (__m128)(unsigned int)(LODWORD(v19) ^ _xmm[0]),
                    0),
                  *(__m128 *)out),
                *(__m128 *)&out[16]),
              btoa.m_translation.m_quad);
      v22 = _mm_unpacklo_ps(btoa.m_rotation.m_col0.m_quad, btoa.m_rotation.m_col1.m_quad);
      v23 = _mm_movelh_ps(v22, btoa.m_rotation.m_col2.m_quad);
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v21, v21, 85),
                  _mm_shuffle_ps(_mm_movehl_ps(v23, v22), btoa.m_rotation.m_col2.m_quad, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v23)),
              _mm_mul_ps(
                _mm_shuffle_ps(v21, v21, 170),
                _mm_shuffle_ps(
                  _mm_unpackhi_ps(btoa.m_rotation.m_col0.m_quad, btoa.m_rotation.m_col1.m_quad),
                  btoa.m_rotation.m_col2.m_quad,
                  228)));
      *(__m128 *)&out[40] = v24;
      if ( v16->m_type.m_storage != 2 || !input->m_weldClosestPoints.m_storage )
        goto LABEL_17;
      if ( v53.m_featureChange.m_storage )
      {
        hkpGsk::exitAndExportCacheImpl(&v53, &cache);
        v18 = (__m128)v44;
        v24 = *(__m128 *)&out[40];
      }
      m_motion = (__m128 *)bodyB->m_motion;
      v26 = bodyA->m_motion;
      v42 = (__int128)v18;
      v27 = v16->vfptr;
      v46 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), m_motion[1]),
                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *m_motion)),
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), m_motion[2])),
              m_motion[3]);
      v28 = ((__int64 (__fastcall *)(hkpConvexShape *, unsigned __int16 *, char *, __m128 *, __m128 *, hkpConvexShape *, const void *, __int128 *))v27[6].__first_virtual_table_function__)(
              v16,
              &cache.m_vertices[(unsigned __int8)cache.m_dimA],
              &cache.m_dimB,
              &v46,
              m_motion,
              v15,
              v26,
              &v42);
      if ( input->m_forceAcceptContactPoints.m_storage || v28 )
      {
        v24 = *(__m128 *)&out[40];
        if ( v28 == 1 )
        {
          v18 = (__m128)v42;
          v44 = v42;
        }
        else
        {
          v18 = (__m128)v44;
        }
LABEL_17:
        v29 = (__m128 *)bodyB->m_motion;
        v47 = v18;
        v30 = _mm_shuffle_ps(v24, v24, 85);
        v31 = _mm_shuffle_ps(v24, v24, 0);
        v32 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v29[2]);
        v33 = _mm_add_ps(_mm_mul_ps(v30, v29[1]), _mm_mul_ps(v31, *v29));
        v47.m128_i32[3] = *(_DWORD *)&out[24];
        v34 = _mm_add_ps(_mm_add_ps(v33, v32), v29[3]);
        v35 = collector->vfptr;
        v50[1] = (__int128)v47;
        v51 = bodyA;
        v52 = bodyB;
        v50[0] = (__int128)v34;
        v50[2] = (__int128)v45;
        v35->addCdPoint(collector, (hkpCdPoint *)v50);
      }
    }
  }
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  v38 = v36;
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "Et";
    v39 = __rdtsc();
    v40 = v37 + 2;
    *((_DWORD *)v40 - 2) = v39;
    v38[1] = v40;
  }
}

// File Line: 260
// RVA: 0xD36010
void __fastcall hkpGskBaseAgent::getPenetrations(
        hkpGskBaseAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r9
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkpConvexShape *m_shape; // r15
  hkpConvexShape *v17; // r12
  unsigned int v18; // ecx
  __int64 m_dimA; // r8
  hkpGskStatus ClosestFeature; // ebp
  float v21; // xmm3_4
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkVector4f separatingNormalOut; // [rsp+30h] [rbp-208h] BYREF
  hkTransformf aTb; // [rsp+40h] [rbp-1F8h] BYREF
  hkpGsk v28; // [rsp+80h] [rbp-1B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtGsk";
    *(_QWORD *)(v9 + 16) = "Sttim";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "StSepNormal";
    v14 = __rdtsc();
    v15 = v13 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v12[1] = v15;
  }
  m_shape = (hkpConvexShape *)bodyA->m_shape;
  v17 = (hkpConvexShape *)bodyB->m_shape;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  v18 = *((unsigned __int8 *)&this->m_cache + 10);
  m_dimA = (unsigned __int8)this->m_cache.m_dimA;
  v28.m_dimB.m_storage = (unsigned __int8)this->m_cache.m_dimB;
  *(_QWORD *)&v28.m_doNotHandlePenetration.m_storage = 1i64;
  v28.m_maxDimB.m_storage = v18 >> 4;
  v28.m_dimA.m_storage = m_dimA;
  v28.m_maxDimA.m_storage = v18 & 0xF;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))m_shape->vfptr[4].__first_virtual_table_function__)(
    m_shape,
    &this->m_cache,
    m_dimA,
    v28.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v17->vfptr[4].__first_virtual_table_function__)(
    v17,
    &this->m_cache.m_vertices[v28.m_dimA.m_storage],
    (unsigned int)v28.m_dimB.m_storage,
    v28.m_verticesBinB);
  ClosestFeature = hkpGsk::getClosestFeature(&v28, m_shape, v17, &aTb, &separatingNormalOut);
  if ( v28.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v28, &this->m_cache);
  if ( ClosestFeature )
  {
    this->m_separatingNormal = 0i64;
  }
  else
  {
    v21 = (float)(separatingNormalOut.m_quad.m128_f32[3] - m_shape->m_radius) - v17->m_radius;
    this->m_separatingNormal.m_quad = _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 85),
                                            *((__m128 *)bodyA->m_motion + 1)),
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 0),
                                            *(__m128 *)bodyA->m_motion)),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 170),
                                          *((__m128 *)bodyA->m_motion + 2)));
    this->m_separatingNormal.m_quad.m128_f32[3] = v21;
    if ( v21 >= 0.0 )
      goto LABEL_12;
  }
  collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
LABEL_12:
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "lt";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
}

// File Line: 321
// RVA: 0xD36260
void __fastcall hkpGskBaseAgent::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpConvexShape *m_shape; // r15
  hkpTriangleShape *v13; // rbx
  hkpGskStatus ClosestFeature; // r12d
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkpGskCache v20; // [rsp+30h] [rbp-D0h] BYREF
  hkVector4f separatingNormalOut; // [rsp+40h] [rbp-C0h] BYREF
  hkTransformf btoa; // [rsp+50h] [rbp-B0h] BYREF
  hkpGsk v23; // [rsp+90h] [rbp-70h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtGsk";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  m_shape = (hkpConvexShape *)bodyA->m_shape;
  v13 = (hkpTriangleShape *)bodyB->m_shape;
  hkTransformf::setMulInverseMul(&btoa, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  if ( v13->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(&v20, m_shape, v13, &btoa);
  else
    hkpGskCache::init(&v20, m_shape, v13, &btoa);
  v23.m_dimB.m_storage = (unsigned __int8)v20.m_dimB;
  v23.m_maxDimB.m_storage = *((unsigned __int8 *)&v20 + 10) >> 4;
  *(_QWORD *)&v23.m_doNotHandlePenetration.m_storage = 1i64;
  v23.m_dimA.m_storage = (unsigned __int8)v20.m_dimA;
  v23.m_maxDimA.m_storage = *((_BYTE *)&v20 + 10) & 0xF;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, _QWORD, hkcdVertex *))m_shape->vfptr[4].__first_virtual_table_function__)(
    m_shape,
    &v20,
    (unsigned __int8)v20.m_dimA,
    v23.m_verticesA);
  ((void (__fastcall *)(hkpTriangleShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v13->vfptr[4].__first_virtual_table_function__)(
    v13,
    &v20.m_vertices[v23.m_dimA.m_storage],
    (unsigned int)v23.m_dimB.m_storage,
    v23.m_verticesBinB);
  ClosestFeature = hkpGsk::getClosestFeature(&v23, m_shape, v13, &btoa, &separatingNormalOut);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = v16 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v17[1] = v19;
  }
  if ( ClosestFeature
    || (float)((float)(separatingNormalOut.m_quad.m128_f32[3] - m_shape->m_radius) - v13->m_radius) < 0.0 )
  {
    collector->vfptr->addCdBodyPair(collector, bodyA, bodyB);
  }
}

// File Line: 374
// RVA: 0xD36B80
hkBool *__fastcall hkpGskBaseAgent::getClosestPoint(
        hkpGskBaseAgent *this,
        hkBool *result,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpExtendedGskOut *output)
{
  hkpConvexShape *m_shape; // rsi
  hkpConvexShape *v7; // r14
  int m_dimB; // eax
  unsigned int v12; // ecx
  __int64 m_dimA; // r8
  hkpGskCache *p_m_cache; // rbx
  hkBaseObjectVtbl *vfptr; // rax
  hkVector4f v16; // xmm3
  hkVector4f v17; // xmm2
  float v18; // xmm2_4
  __m128 m_radius_low; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm4
  __m128 v22; // xmm0
  hkVector4f v23; // xmm3
  hkVector4f v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  hkVector4f separatingNormal; // [rsp+30h] [rbp-D0h] BYREF
  hkTransformf aTb; // [rsp+40h] [rbp-C0h] BYREF
  hkpGsk v32; // [rsp+80h] [rbp-80h] BYREF

  m_shape = (hkpConvexShape *)bodyA->m_shape;
  v7 = (hkpConvexShape *)bodyB->m_shape;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  m_dimB = (unsigned __int8)this->m_cache.m_dimB;
  v12 = *((unsigned __int8 *)&this->m_cache + 10);
  m_dimA = (unsigned __int8)this->m_cache.m_dimA;
  p_m_cache = &this->m_cache;
  v32.m_dimB.m_storage = m_dimB;
  v32.m_featureChange.m_storage = 0;
  *(_QWORD *)&v32.m_maxDimB.m_storage = v12 >> 4;
  v32.m_maxDimA.m_storage = v12 & 0xF;
  vfptr = m_shape->vfptr;
  v32.m_dimA.m_storage = m_dimA;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))vfptr[4].__first_virtual_table_function__)(
    m_shape,
    p_m_cache,
    m_dimA,
    v32.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v7->vfptr[4].__first_virtual_table_function__)(
    v7,
    &p_m_cache->m_vertices[v32.m_dimA.m_storage],
    (unsigned int)v32.m_dimB.m_storage,
    v32.m_verticesBinB);
  hkpGsk::getClosestFeature(&v32, m_shape, v7, &aTb, &separatingNormal);
  if ( v32.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v32, p_m_cache);
  hkpGsk::convertFeatureToClosestDistance(&v32, &separatingNormal, output);
  v16.m_quad = (__m128)output->m_normalInA;
  v17.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 85), *((__m128 *)bodyA->m_motion + 1)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(output->m_normalInA.m_quad, output->m_normalInA.m_quad, 0),
                     *(__m128 *)bodyA->m_motion)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(output->m_normalInA.m_quad, output->m_normalInA.m_quad, 170),
                   *((__m128 *)bodyA->m_motion + 2)));
  output->m_normalInWorld = (hkVector4f)v17.m_quad;
  output->m_unweldedNormalInWorld = (hkVector4f)v17.m_quad;
  v18 = (float)(output->m_distance.m_storage - m_shape->m_radius) - v7->m_radius;
  output->m_distance.m_storage = v18;
  if ( v18 >= input->m_tolerance.m_storage )
  {
    result->m_bool = 0;
  }
  else
  {
    m_radius_low = (__m128)LODWORD(m_shape->m_radius);
    v20.m_quad = (__m128)output->m_pointAinA;
    v21.m_quad = (__m128)aTb.m_rotation.m_col0;
    result->m_bool = 1;
    v22 = _mm_mul_ps(_mm_shuffle_ps(m_radius_low, m_radius_low, 0), v16.m_quad);
    v23.m_quad = (__m128)aTb.m_rotation.m_col2;
    v24.m_quad = _mm_sub_ps(v20.m_quad, v22);
    output->m_pointAinA = (hkVector4f)v24.m_quad;
    v25 = _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)(unsigned int)(LODWORD(v18) ^ _xmm[0]),
                (__m128)(unsigned int)(LODWORD(v18) ^ _xmm[0]),
                0),
              output->m_normalInA.m_quad),
            v24.m_quad);
    v26 = _mm_unpacklo_ps(v21.m_quad, aTb.m_rotation.m_col1.m_quad);
    v27 = _mm_sub_ps(v25, aTb.m_translation.m_quad);
    v28 = _mm_movelh_ps(v26, v23.m_quad);
    output->m_pointBinB.m_quad = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v27, v27, 85),
                                       _mm_shuffle_ps(_mm_movehl_ps(v28, v26), v23.m_quad, 212)),
                                     _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v28)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(
                                       _mm_unpackhi_ps(v21.m_quad, aTb.m_rotation.m_col1.m_quad),
                                       v23.m_quad,
                                       228),
                                     _mm_shuffle_ps(v27, v27, 170)));
  }
  return result;
}

// File Line: 383
// RVA: 0xD36410
void __fastcall hkpGskBaseAgent::getClosestPoints(
        hkpGskBaseAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkpConvexShape *m_shape; // rax
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkpGsk::GetClosesetPointInput inputa; // [rsp+30h] [rbp-D8h] BYREF
  hkVector4f pointOnBOut; // [rsp+60h] [rbp-A8h] BYREF
  hkVector4f separatingNormalOut; // [rsp+70h] [rbp-98h] BYREF
  __int128 v22[3]; // [rsp+80h] [rbp-88h] BYREF
  hkpCdBody *v23; // [rsp+B0h] [rbp-58h]
  hkpCdBody *v24; // [rsp+B8h] [rbp-50h]
  hkTransformf v25; // [rsp+C0h] [rbp-48h] BYREF
  hkResult result; // [rsp+110h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtGsk";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  hkTransformf::setMulInverseMul(&v25, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  m_shape = (hkpConvexShape *)bodyA->m_shape;
  inputa.m_collisionTolerance.m_storage = input->m_tolerance.m_storage;
  inputa.m_shapeA.m_storage = m_shape;
  inputa.m_shapeB.m_storage = (hkpConvexShape *)bodyB->m_shape;
  inputa.m_aTb.m_storage = &v25;
  inputa.m_transformA.m_storage = (hkTransformf *)bodyA->m_motion;
  if ( hkpGsk::getClosestPoint(&result, &inputa, &this->m_cache, &separatingNormalOut, &pointOnBOut)->m_enum == HK_SUCCESS )
  {
    v23 = bodyA;
    v24 = bodyB;
    v22[0] = (__int128)pointOnBOut.m_quad;
    v22[1] = (__int128)separatingNormalOut.m_quad;
    v22[2] = (__int128)separatingNormalOut.m_quad;
    collector->vfptr->addCdPoint(collector, (hkpCdPoint *)v22);
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v15[1] = v18;
  }
}

