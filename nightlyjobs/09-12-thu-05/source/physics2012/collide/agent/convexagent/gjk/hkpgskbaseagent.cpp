// File Line: 26
// RVA: 0xD36000
void __fastcall hkpGskBaseAgent::processCollision(hkpGskBaseAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input)
{
  ;
}

// File Line: 34
// RVA: 0xD369B0
void __fastcall hkpGskBaseAgent::hkpGskBaseAgent(hkpGskBaseAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpContactMgr *mgr)
{
  hkpConvexShape *v4; // r14
  hkpTriangleShape *v5; // rbp
  hkpCdBody *v6; // rdi
  hkpCdBody *v7; // rbx
  hkpGskBaseAgent *v8; // rsi
  hkpGskCache *v9; // rcx
  hkpCdBody *i; // rax
  hkpCdBody *j; // rax
  hkTransformf btoa; // [rsp+20h] [rbp-58h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpGskBaseAgent::`vftable;
  v4 = (hkpConvexShape *)bodyA->m_shape;
  v5 = (hkpTriangleShape *)bodyB->m_shape;
  v6 = bodyB;
  v7 = bodyA;
  v8 = this;
  hkTransformf::setMulInverseMul(&btoa, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  v9 = &v8->m_cache;
  if ( v5->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(v9, v4, v5, &btoa);
  else
    hkpGskCache::init(v9, v4, (hkpConvexShape *)&v5->vfptr, &btoa);
  v8->m_separatingNormal = 0i64;
  v8->m_separatingNormal.m_quad.m128_i32[3] = -1082130432;
  v8->m_timeOfSeparatingNormal = -1.0;
  for ( i = v7->m_parent; i; i = i->m_parent )
    v7 = i;
  for ( j = v6->m_parent; j; j = j->m_parent )
    v6 = j;
  v8->m_allowedPenetration = fminf(*(float *)&v7[3].m_shapeKey, *(float *)&v6[3].m_shapeKey);
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
    this->vfptr->__vecDelDtor((hkBaseObject *)this, 1u);
}

// File Line: 76
// RVA: 0xD36DA0
void __fastcall hkpGskBaseAgent::warpTime(hkpGskBaseAgent *this, float oldTime, float newTime, hkpCollisionInput *input)
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
void __fastcall hkpGskBaseAgent::calcSeparatingNormal(hkpCdBody *bodyA, hkpCdBody *bodyB, float earlyOutTolerance, hkpGsk *gsk, hkVector4f *separatingNormalOut)
{
  hkpConvexShape *v5; // rbp
  hkpConvexShape *v6; // rsi
  hkpCdBody *v7; // rbx
  hkpGsk *v8; // rdi
  float v9; // xmm3_4
  hkVector4f v10; // [rsp+30h] [rbp-58h]
  hkTransformf aTb; // [rsp+40h] [rbp-48h]

  v5 = (hkpConvexShape *)bodyB->m_shape;
  v6 = (hkpConvexShape *)bodyA->m_shape;
  v7 = bodyA;
  v8 = gsk;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  hkpGsk::getClosestFeature(v8, v6, v5, &aTb, &v10);
  v9 = v10.m_quad.m128_f32[3];
  separatingNormalOut->m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v10.m_quad, v10.m_quad, 85),
                                      *((__m128 *)v7->m_motion + 1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 0), *(__m128 *)v7->m_motion)),
                                  _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 170), *((__m128 *)v7->m_motion + 2)));
  separatingNormalOut->m_quad.m128_f32[3] = (float)(v9 - v6->m_radius) - v5->m_radius;
}

// File Line: 220
// RVA: 0xD36580
void __fastcall hkpGskBaseAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rbx
  hkpCdPointCollector *v5; // r12
  hkpCollisionInput *v6; // r15
  hkpCdBody *v7; // rdi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpConvexShape *v13; // r14
  hkpTriangleShape *v14; // rsi
  hkpConvexShape *v15; // r14
  hkpConvexShape *v16; // rsi
  hkBaseObjectVtbl *v17; // rax
  __m128i v18; // xmm7
  float v19; // xmm3_4
  bool v20; // cf
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 *v25; // r9
  __int64 v26; // rax
  const void *v27; // r8
  hkBaseObjectVtbl *v28; // r10
  int v29; // eax
  __m128 *v30; // rax
  __m128 v31; // xmm1
  __m128 v32; // xmm0
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  hkpCdPointCollectorVtbl *v36; // rax
  _QWORD *v37; // rax
  _QWORD *v38; // rcx
  _QWORD *v39; // r8
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  hkpGskCache cache; // [rsp+40h] [rbp-B8h]
  __m128i v43; // [rsp+50h] [rbp-A8h]
  hkpGskOut out; // [rsp+60h] [rbp-98h]
  __m128i v45; // [rsp+98h] [rbp-60h]
  __m128i v46; // [rsp+A8h] [rbp-50h]
  __m128 v47; // [rsp+B8h] [rbp-40h]
  __m128i v48; // [rsp+C8h] [rbp-30h]
  hkVector4f separatingNormal; // [rsp+D8h] [rbp-20h]
  hkTransformf btoa; // [rsp+E8h] [rbp-10h]
  __m128 v51; // [rsp+128h] [rbp+30h]
  __m128i v52; // [rsp+138h] [rbp+40h]
  __m128i v53; // [rsp+148h] [rbp+50h]
  hkpCdBody *v54; // [rsp+158h] [rbp+60h]
  hkpCdBody *v55; // [rsp+160h] [rbp+68h]
  hkpGsk v56; // [rsp+168h] [rbp+70h]

  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtGsk";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (hkpConvexShape *)v4->m_shape;
  v14 = (hkpTriangleShape *)v7->m_shape;
  hkTransformf::setMulInverseMul(&btoa, (hkTransformf *)v4->m_motion, (hkTransformf *)v7->m_motion);
  if ( v14->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(&cache, v13, v14, &btoa);
  else
    hkpGskCache::init(&cache, v13, (hkpConvexShape *)&v14->vfptr, &btoa);
  v15 = (hkpConvexShape *)v4->m_shape;
  v16 = (hkpConvexShape *)v7->m_shape;
  v56.m_dimB.m_storage = (unsigned __int8)cache.m_dimB;
  *(_QWORD *)&v56.m_doNotHandlePenetration.m_storage = 0i64;
  *(_QWORD *)&v56.m_maxDimB.m_storage = (unsigned int)*((unsigned __int8 *)&cache + 10) >> 4;
  v56.m_maxDimA.m_storage = *((_BYTE *)&cache + 10) & 0xF;
  v17 = v15->vfptr;
  v56.m_dimA.m_storage = (unsigned __int8)cache.m_dimA;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, _QWORD, hkcdVertex *))v17[4].__first_virtual_table_function__)(
    v15,
    &cache,
    (unsigned __int8)cache.m_dimA,
    v56.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v16->vfptr[4].__first_virtual_table_function__)(
    v16,
    &cache.m_vertices[v56.m_dimA.m_storage],
    (unsigned int)v56.m_dimB.m_storage,
    v56.m_verticesBinB);
  if ( hkpGsk::getClosestFeature(&v56, v15, v16, &btoa, &separatingNormal) == HK_GSK_OK )
  {
    hkpGsk::convertFeatureToClosestDistance(&v56, &separatingNormal, &out);
    v18 = (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(out.m_normalInA.m_quad, out.m_normalInA.m_quad, 85),
                         *((__m128 *)v4->m_motion + 1)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(out.m_normalInA.m_quad, out.m_normalInA.m_quad, 0),
                         *(__m128 *)v4->m_motion)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(out.m_normalInA.m_quad, out.m_normalInA.m_quad, 170),
                       *((__m128 *)v4->m_motion + 2)));
    v45 = v18;
    v46 = v18;
    v19 = (float)(out.m_pointAinA.m_quad.m128_f32[2] - v15->m_radius) - v16->m_radius;
    v20 = v19 < v6->m_tolerance.m_storage;
    out.m_pointAinA.m_quad.m128_f32[2] = (float)(out.m_pointAinA.m_quad.m128_f32[2] - v15->m_radius) - v16->m_radius;
    if ( v20 )
    {
      out.m_pointAinA.m_quad = _mm_add_ps(
                                 out.m_pointAinA.m_quad,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(
                                     (__m128)(unsigned int)(LODWORD(v15->m_radius) ^ _xmm[0]),
                                     (__m128)(unsigned int)(LODWORD(v15->m_radius) ^ _xmm[0]),
                                     0),
                                   out.m_normalInA.m_quad));
      v21 = _mm_sub_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)(unsigned int)(LODWORD(v19) ^ _xmm[0]),
                    (__m128)(unsigned int)(LODWORD(v19) ^ _xmm[0]),
                    0),
                  out.m_normalInA.m_quad),
                out.m_pointAinA.m_quad),
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
      *(__m128 *)(&out.m_distance + 2) = v24;
      if ( v16->m_type.m_storage != 2 || !v6->m_weldClosestPoints.m_storage )
        goto LABEL_17;
      if ( v56.m_featureChange.m_storage )
      {
        hkpGsk::exitAndExportCacheImpl(&v56, &cache);
        v18 = v45;
        v24 = *(__m128 *)(&out.m_distance + 2);
      }
      v25 = (__m128 *)v7->m_motion;
      v26 = (unsigned __int8)cache.m_dimA;
      v27 = v4->m_motion;
      _mm_store_si128(&v43, v18);
      v28 = v16->vfptr;
      v47 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v25[1]),
                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *v25)),
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v25[2])),
              v25[3]);
      v29 = ((__int64 (__fastcall *)(hkpConvexShape *, unsigned __int16 *, char *, __m128 *, __m128 *, hkpConvexShape *, const void *, __m128i *))v28[6].__first_virtual_table_function__)(
              v16,
              &cache.m_vertices[v26],
              &cache.m_dimB,
              &v47,
              v25,
              v15,
              v27,
              &v43);
      if ( v6->m_forceAcceptContactPoints.m_storage || v29 )
      {
        v24 = *(__m128 *)(&out.m_distance + 2);
        if ( v29 == 1 )
        {
          v18 = v43;
          v45 = v43;
        }
        else
        {
          v18 = v45;
        }
LABEL_17:
        v30 = (__m128 *)v7->m_motion;
        v48 = v18;
        v31 = _mm_shuffle_ps(v24, v24, 85);
        v32 = _mm_shuffle_ps(v24, v24, 0);
        v33 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v30[2]);
        v34 = _mm_add_ps(_mm_mul_ps(v31, v30[1]), _mm_mul_ps(v32, *v30));
        v48.m128i_i32[3] = out.m_pointAinA.m_quad.m128_i32[2];
        v35 = _mm_add_ps(_mm_add_ps(v34, v33), v30[3]);
        v36 = v5->vfptr;
        v52 = v48;
        v54 = v4;
        v55 = v7;
        v51 = v35;
        v53 = v46;
        v36->addCdPoint(v5, (hkpCdPoint *)&v51);
        goto LABEL_18;
      }
    }
  }
LABEL_18:
  v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v38 = (_QWORD *)v37[1];
  v39 = v37;
  if ( (unsigned __int64)v38 < v37[3] )
  {
    *v38 = "Et";
    v40 = __rdtsc();
    v41 = (signed __int64)(v38 + 2);
    *(_DWORD *)(v41 - 8) = v40;
    v39[1] = v41;
  }
}

// File Line: 260
// RVA: 0xD36010
void __fastcall hkpGskBaseAgent::getPenetrations(hkpGskBaseAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpGskBaseAgent *v5; // rsi
  hkpCdBody *v6; // rdi
  hkpCdBody *v7; // rbx
  _QWORD *v8; // rax
  unsigned __int64 v9; // r9
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkpConvexShape *v16; // r15
  hkpConvexShape *v17; // r12
  unsigned int v18; // ecx
  __int64 v19; // r8
  hkpGskStatus v20; // ebp
  float v21; // xmm3_4
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  hkVector4f separatingNormalOut; // [rsp+30h] [rbp-208h]
  hkTransformf aTb; // [rsp+40h] [rbp-1F8h]
  hkpGsk v28; // [rsp+80h] [rbp-1B8h]

  v5 = this;
  v6 = bodyB;
  v7 = bodyA;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
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
    v15 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v12[1] = v15;
  }
  v16 = (hkpConvexShape *)v7->m_shape;
  v17 = (hkpConvexShape *)v6->m_shape;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)v7->m_motion, (hkTransformf *)v6->m_motion);
  v18 = *((unsigned __int8 *)&v5->m_cache + 10);
  v19 = (unsigned __int8)v5->m_cache.m_dimA;
  v28.m_dimB.m_storage = (unsigned __int8)v5->m_cache.m_dimB;
  *(_QWORD *)&v28.m_doNotHandlePenetration.m_storage = 1i64;
  v28.m_maxDimB.m_storage = v18 >> 4;
  v28.m_dimA.m_storage = v19;
  v28.m_maxDimA.m_storage = v18 & 0xF;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))v16->vfptr[4].__first_virtual_table_function__)(
    v16,
    &v5->m_cache,
    v19,
    v28.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v17->vfptr[4].__first_virtual_table_function__)(
    v17,
    &v5->m_cache.m_vertices[v28.m_dimA.m_storage],
    (unsigned int)v28.m_dimB.m_storage,
    v28.m_verticesBinB);
  v20 = hkpGsk::getClosestFeature(&v28, v16, v17, &aTb, &separatingNormalOut);
  if ( v28.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v28, &v5->m_cache);
  if ( v20 )
  {
    v5->m_separatingNormal = 0i64;
  }
  else
  {
    v21 = (float)(separatingNormalOut.m_quad.m128_f32[3] - v16->m_radius) - v17->m_radius;
    v5->m_separatingNormal.m_quad = _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 85),
                                          *((__m128 *)v7->m_motion + 1)),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 0),
                                          *(__m128 *)v7->m_motion)),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 170),
                                        *((__m128 *)v7->m_motion + 2)));
    v5->m_separatingNormal.m_quad.m128_f32[3] = v21;
    if ( v21 >= 0.0 )
      goto LABEL_12;
  }
  collector->vfptr->addCdBodyPair(collector, v7, v6);
LABEL_12:
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "lt";
    v24 = __rdtsc();
    v25 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v22[1] = v25;
  }
}

// File Line: 321
// RVA: 0xD36260
void __fastcall hkpGskBaseAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // r14
  hkpCdBodyPairCollector *v5; // rdi
  hkpCdBody *v6; // rsi
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkpConvexShape *v12; // r15
  hkpTriangleShape *v13; // rbx
  hkpGskStatus v14; // er12
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkpGskCache v20; // [rsp+30h] [rbp-D0h]
  hkVector4f separatingNormalOut; // [rsp+40h] [rbp-C0h]
  hkTransformf btoa; // [rsp+50h] [rbp-B0h]
  hkpGsk v23; // [rsp+90h] [rbp-70h]

  v4 = bodyA;
  v5 = collector;
  v6 = bodyB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtGsk";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12 = (hkpConvexShape *)v4->m_shape;
  v13 = (hkpTriangleShape *)v6->m_shape;
  hkTransformf::setMulInverseMul(&btoa, (hkTransformf *)v4->m_motion, (hkTransformf *)v6->m_motion);
  if ( v13->m_type.m_storage == 2 )
    hkpGskCache::initTriangle(&v20, v12, v13, &btoa);
  else
    hkpGskCache::init(&v20, v12, (hkpConvexShape *)&v13->vfptr, &btoa);
  v23.m_dimB.m_storage = (unsigned __int8)v20.m_dimB;
  v23.m_maxDimB.m_storage = (unsigned int)*((unsigned __int8 *)&v20 + 10) >> 4;
  *(_QWORD *)&v23.m_doNotHandlePenetration.m_storage = 1i64;
  v23.m_dimA.m_storage = (unsigned __int8)v20.m_dimA;
  v23.m_maxDimA.m_storage = *((_BYTE *)&v20 + 10) & 0xF;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, _QWORD, hkcdVertex *))v12->vfptr[4].__first_virtual_table_function__)(
    v12,
    &v20,
    (unsigned __int8)v20.m_dimA,
    v23.m_verticesA);
  ((void (__fastcall *)(hkpTriangleShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v13->vfptr[4].__first_virtual_table_function__)(
    v13,
    &v20.m_vertices[v23.m_dimA.m_storage],
    (unsigned int)v23.m_dimB.m_storage,
    v23.m_verticesBinB);
  v14 = hkpGsk::getClosestFeature(&v23, v12, (hkpConvexShape *)&v13->vfptr, &btoa, &separatingNormalOut);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v17[1] = v19;
  }
  if ( v14 || (float)((float)(separatingNormalOut.m_quad.m128_f32[3] - v12->m_radius) - v13->m_radius) < 0.0 )
    v5->vfptr->addCdBodyPair(v5, v4, v6);
}

// File Line: 374
// RVA: 0xD36B80
hkBool *__fastcall hkpGskBaseAgent::getClosestPoint(hkpGskBaseAgent *this, hkBool *result, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpExtendedGskOut *output)
{
  hkpConvexShape *v6; // rsi
  hkpConvexShape *v7; // r14
  hkpCdBody *v8; // r15
  hkBool *v9; // rdi
  unsigned __int8 *v10; // rbx
  int v11; // eax
  unsigned int v12; // ecx
  __int64 v13; // r8
  hkpGskCache *v14; // rbx
  hkBaseObjectVtbl *v15; // rax
  hkVector4f v16; // xmm3
  hkVector4f v17; // xmm2
  float v18; // xmm2_4
  __m128 v19; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm4
  __m128 v22; // xmm0
  hkVector4f v23; // xmm3
  hkVector4f v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  hkVector4f separatingNormal; // [rsp+30h] [rbp-D0h]
  hkTransformf aTb; // [rsp+40h] [rbp-C0h]
  hkpGsk v32; // [rsp+80h] [rbp-80h]

  v6 = (hkpConvexShape *)bodyA->m_shape;
  v7 = (hkpConvexShape *)bodyB->m_shape;
  v8 = bodyA;
  v9 = result;
  v10 = (unsigned __int8 *)this;
  hkTransformf::setMulInverseMul(&aTb, (hkTransformf *)bodyA->m_motion, (hkTransformf *)bodyB->m_motion);
  v11 = v10[33];
  v12 = v10[34];
  v13 = v10[32];
  v14 = (hkpGskCache *)(v10 + 24);
  v32.m_dimB.m_storage = v11;
  *(_QWORD *)&v32.m_doNotHandlePenetration.m_storage = 0i64;
  *(_QWORD *)&v32.m_maxDimB.m_storage = v12 >> 4;
  v32.m_maxDimA.m_storage = v12 & 0xF;
  v15 = v6->vfptr;
  v32.m_dimA.m_storage = v13;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))v15[4].__first_virtual_table_function__)(
    v6,
    v14,
    v13,
    v32.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v7->vfptr[4].__first_virtual_table_function__)(
    v7,
    &v14->m_vertices[v32.m_dimA.m_storage],
    (unsigned int)v32.m_dimB.m_storage,
    v32.m_verticesBinB);
  hkpGsk::getClosestFeature(&v32, v6, v7, &aTb, &separatingNormal);
  if ( v32.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v32, v14);
  hkpGsk::convertFeatureToClosestDistance(&v32, &separatingNormal, (hkpGskOut *)&output->m_normalInA);
  v16.m_quad = (__m128)output->m_normalInA;
  v17.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 85), *((__m128 *)v8->m_motion + 1)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(output->m_normalInA.m_quad, output->m_normalInA.m_quad, 0),
                     *(__m128 *)v8->m_motion)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(output->m_normalInA.m_quad, output->m_normalInA.m_quad, 170),
                   *((__m128 *)v8->m_motion + 2)));
  output->m_normalInWorld = (hkVector4f)v17.m_quad;
  output->m_unweldedNormalInWorld = (hkVector4f)v17.m_quad;
  v18 = (float)(output->m_distance.m_storage - v6->m_radius) - v7->m_radius;
  output->m_distance.m_storage = v18;
  if ( v18 >= input->m_tolerance.m_storage )
  {
    v9->m_bool = 0;
  }
  else
  {
    v19 = (__m128)LODWORD(v6->m_radius);
    v20.m_quad = (__m128)output->m_pointAinA;
    v21.m_quad = (__m128)aTb.m_rotation.m_col0;
    v9->m_bool = 1;
    v22 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v16.m_quad);
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
  return v9;
}

// File Line: 383
// RVA: 0xD36410
void __fastcall hkpGskBaseAgent::getClosestPoints(hkpGskBaseAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpGskBaseAgent *v5; // rbp
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rdi
  hkpCdBody *v8; // rbx
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkpConvexShape *v14; // rax
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  hkpGsk::GetClosesetPointInput inputa; // [rsp+30h] [rbp-D8h]
  hkVector4f pointOnBOut; // [rsp+60h] [rbp-A8h]
  hkVector4f separatingNormalOut; // [rsp+70h] [rbp-98h]
  __m128 v22; // [rsp+80h] [rbp-88h]
  __m128 v23; // [rsp+90h] [rbp-78h]
  __m128 v24; // [rsp+A0h] [rbp-68h]
  hkpCdBody *v25; // [rsp+B0h] [rbp-58h]
  hkpCdBody *v26; // [rsp+B8h] [rbp-50h]
  hkTransformf v27; // [rsp+C0h] [rbp-48h]
  hkResult result; // [rsp+110h] [rbp+8h]

  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtGsk";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  hkTransformf::setMulInverseMul(&v27, (hkTransformf *)v8->m_motion, (hkTransformf *)v7->m_motion);
  v14 = (hkpConvexShape *)v8->m_shape;
  inputa.m_collisionTolerance.m_storage = v6->m_tolerance.m_storage;
  inputa.m_shapeA.m_storage = v14;
  inputa.m_shapeB.m_storage = (hkpConvexShape *)v7->m_shape;
  inputa.m_aTb.m_storage = &v27;
  inputa.m_transformA.m_storage = (hkTransformf *)v8->m_motion;
  if ( hkpGsk::getClosestPoint(&result, &inputa, &v5->m_cache, &separatingNormalOut, &pointOnBOut)->m_enum == HK_SUCCESS )
  {
    v25 = v8;
    v26 = v7;
    v22 = pointOnBOut.m_quad;
    v23 = separatingNormalOut.m_quad;
    v24 = separatingNormalOut.m_quad;
    collector->vfptr->addCdPoint(collector, (hkpCdPoint *)&v22);
  }
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

