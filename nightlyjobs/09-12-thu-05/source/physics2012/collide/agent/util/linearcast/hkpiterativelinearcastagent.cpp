// File Line: 21
// RVA: 0xD356D0
void __fastcall hkpIterativeLinearCastAgent::linearCast(
        hkpIterativeLinearCastAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkBaseObjectVtbl *vfptr; // rax
  __int128 v11; // xmm0
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  __m128 v15; // xmm1
  __int128 v16; // xmm7
  __m128 v17; // xmm6
  hkpCdPointCollectorVtbl *v18; // rax
  hkVector4f v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  hkpCollisionAgentConfig *m_config; // rcx
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  hkpCdPointCollectorVtbl *v29; // rax
  __int128 *m_motion; // rax
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __int128 v34; // xmm1
  hkpShape *m_shape; // rax
  int v36; // edi
  __m128 *v37; // rax
  __m128 v38; // xmm7
  __m128 v39; // xmm0
  hkBaseObjectVtbl *v40; // rax
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  hkpCdPointCollectorVtbl *v47; // rax
  __int128 v48; // [rsp+30h] [rbp-D0h] BYREF
  __m128 v49; // [rsp+40h] [rbp-C0h]
  __m128 v50; // [rsp+50h] [rbp-B0h]
  hkpCdBody *v51; // [rsp+60h] [rbp-A0h]
  hkpCdBody *v52; // [rsp+68h] [rbp-98h]
  hkpShape *v53; // [rsp+70h] [rbp-90h] BYREF
  int v54; // [rsp+78h] [rbp-88h]
  __int128 *v55; // [rsp+80h] [rbp-80h]
  hkpCdBody *v56; // [rsp+88h] [rbp-78h]
  void **v57; // [rsp+90h] [rbp-70h] BYREF
  int v58; // [rsp+98h] [rbp-68h]
  __int128 v59; // [rsp+A0h] [rbp-60h]
  __m128 v60; // [rsp+B0h] [rbp-50h]
  __int64 v61; // [rsp+C0h] [rbp-40h]
  __m128 v62; // [rsp+E0h] [rbp-20h]
  __int128 v63; // [rsp+F0h] [rbp-10h] BYREF
  __int128 v64; // [rsp+100h] [rbp+0h]
  __int128 v65; // [rsp+110h] [rbp+10h]
  __m128 m_quad; // [rsp+120h] [rbp+20h]
  __m128 v67; // [rsp+130h] [rbp+30h]
  __m128 v68; // [rsp+140h] [rbp+40h]
  void **v69; // [rsp+150h] [rbp+50h] BYREF
  int v70; // [rsp+158h] [rbp+58h]
  __int128 v71; // [rsp+160h] [rbp+60h]
  __m128 v72; // [rsp+170h] [rbp+70h]
  __int64 v73; // [rsp+180h] [rbp+80h]
  __m128 v74; // [rsp+1A0h] [rbp+A0h]
  __int128 v75[3]; // [rsp+1B0h] [rbp+B0h] BYREF
  hkpCdBody *v76; // [rsp+1E0h] [rbp+E0h]
  hkpCdBody *v77; // [rsp+1E8h] [rbp+E8h]
  __int128 v78[3]; // [rsp+1F0h] [rbp+F0h] BYREF
  __int128 v79; // [rsp+220h] [rbp+120h]

  vfptr = this->vfptr;
  v64 = *(_OWORD *)&input->m_tolerance.m_storage;
  *(float *)&v64 = *(float *)&v64 + input->m_cachedPathLength;
  v63 = *(_OWORD *)&input->m_dispatcher.m_storage;
  v11 = *(_OWORD *)&input->m_convexListFilter.m_storage;
  v72 = _mm_shuffle_ps(v72, _mm_unpackhi_ps(v72, (__m128)xmmword_141A712A0), 196);
  v69 = &hkpClosestCdPointCollector::`vftable;
  v73 = 0i64;
  v70 = 2139095022;
  HIDWORD(v63) = 1;
  v12.m_quad = (__m128)input->m_aabb32Info.m_bitOffsetLow;
  v65 = v11;
  v13.m_quad = (__m128)input->m_aabb32Info.m_bitOffsetHigh;
  m_quad = v12.m_quad;
  v14.m_quad = (__m128)input->m_aabb32Info.m_bitScale;
  v67 = v13.m_quad;
  v68 = v14.m_quad;
  ((void (__fastcall *)(hkpIterativeLinearCastAgent *, hkpCdBody *, hkpCdBody *, __int128 *, void ***))vfptr[2].__vecDelDtor)(
    this,
    bodyA,
    bodyB,
    &v63,
    &v69);
  if ( v73 )
  {
    v15 = _mm_shuffle_ps(v72, v72, 255);
    v16 = v71;
    v17 = _mm_shuffle_ps(v74, _mm_unpackhi_ps(v74, v15), 196);
    if ( v15.m128_f32[0] < _mm_shuffle_ps(
                             (__m128)LODWORD(input->m_tolerance.m_storage),
                             (__m128)LODWORD(input->m_tolerance.m_storage),
                             0).m128_f32[0]
      && startCollector )
    {
      v18 = startCollector->vfptr;
      v48 = v71;
      v49 = v17;
      v51 = bodyA;
      v52 = bodyB;
      v50 = v17;
      v18->addCdPoint(startCollector, (hkpCdPoint *)&v48);
    }
    v19.m_quad = (__m128)input->m_path;
    v20 = _mm_mul_ps(v17, v19.m_quad);
    v21 = _mm_shuffle_ps(v17, v17, 255);
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v23 = _mm_add_ps(v22, v21);
    if ( v23.m128_f32[0] <= 0.0
      && (float)(_mm_shuffle_ps(
                   (__m128)LODWORD(input->m_maxExtraPenetration),
                   (__m128)LODWORD(input->m_maxExtraPenetration),
                   0).m128_f32[0]
               + v22.m128_f32[0]) < 0.0 )
    {
      m_config = input->m_config;
      v25 = _mm_sub_ps(v21, v23);
      v26 = _mm_rcp_ps(v25);
      v27 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26), v21);
      if ( v21.m128_f32[0] > _mm_shuffle_ps(
                               (__m128)LODWORD(m_config->m_iterativeLinearCastEarlyOutDistance),
                               (__m128)LODWORD(m_config->m_iterativeLinearCastEarlyOutDistance),
                               0).m128_f32[0] )
      {
        m_motion = (__int128 *)bodyA->m_motion;
        v31 = (__m128)xmmword_141A712A0;
        v57 = &hkpClosestCdPointCollector::`vftable;
        v61 = 0i64;
        v58 = 2139095022;
        v32 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v27), 196);
        v33 = _mm_shuffle_ps(v60, _mm_unpackhi_ps(v60, (__m128)xmmword_141A712A0), 196);
        v60 = v33;
        v78[0] = *m_motion;
        v78[1] = m_motion[1];
        v78[2] = m_motion[2];
        v34 = m_motion[3];
        v56 = bodyA;
        v54 = -1;
        v55 = v78;
        m_shape = bodyA->m_shape;
        v79 = v34;
        v53 = m_shape;
        v36 = m_config->m_iterativeLinearCastMaxIterations - 1;
        if ( v36 < 0 )
        {
LABEL_20:
          if ( DWORD2(v63) )
            v32 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v32), 196);
          v47 = collector->vfptr;
          v75[0] = v16;
          v75[1] = (__int128)v32;
          v75[2] = (__int128)v32;
          v76 = bodyA;
          v77 = bodyB;
          v47->addCdPoint(collector, (hkpCdPoint *)v75);
        }
        else
        {
          while ( 1 )
          {
            v37 = (__m128 *)bodyA->m_motion;
            v61 = 0i64;
            v58 = 2139095022;
            v38 = _mm_shuffle_ps(v32, v32, 255);
            v60 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v31), 196);
            v39 = _mm_add_ps(_mm_mul_ps(v38, v19.m_quad), v37[3]);
            v40 = this->vfptr;
            v79 = (__int128)v39;
            ((void (__fastcall *)(hkpIterativeLinearCastAgent *, hkpShape **, hkpCdBody *, __int128 *, void ***))v40[2].__vecDelDtor)(
              this,
              &v53,
              bodyB,
              &v63,
              &v57);
            v19.m_quad = (__m128)input->m_path;
            v41 = _mm_mul_ps(v62, v19.m_quad);
            v42 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                    _mm_shuffle_ps(v41, v41, 170));
            if ( v42.m128_f32[0] >= 0.0 )
              break;
            v33 = v60;
            v43 = _mm_sub_ps((__m128)0i64, v42);
            v44 = _mm_shuffle_ps(v60, v60, 255);
            if ( (float)((float)(v38.m128_f32[0] * v43.m128_f32[0]) + v44.m128_f32[0]) > v43.m128_f32[0] )
              break;
            v45 = _mm_rcp_ps(v43);
            v46 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v43)), v45), v44), v38);
            if ( v46.m128_f32[0] > _mm_shuffle_ps(
                                     (__m128)LODWORD(collector->m_earlyOutDistance),
                                     (__m128)LODWORD(collector->m_earlyOutDistance),
                                     0).m128_f32[0] )
              break;
            v16 = v59;
            v32 = _mm_shuffle_ps(v62, _mm_unpackhi_ps(v62, v46), 196);
            if ( v44.m128_f32[0] <= _mm_shuffle_ps(
                                      (__m128)input->m_config->m_iterativeLinearCastEarlyOutDistance,
                                      (__m128)input->m_config->m_iterativeLinearCastEarlyOutDistance,
                                      0).m128_f32[0] )
              goto LABEL_20;
            if ( --v36 < 0 )
              goto LABEL_20;
            v31 = (__m128)xmmword_141A712A0;
          }
        }
      }
      else
      {
        if ( v21.m128_f32[0] <= 0.0 )
        {
          v28 = _mm_unpackhi_ps(v17, aabbOut.m_quad);
        }
        else
        {
          if ( v27.m128_f32[0] > _mm_shuffle_ps(
                                   (__m128)LODWORD(collector->m_earlyOutDistance),
                                   (__m128)LODWORD(collector->m_earlyOutDistance),
                                   0).m128_f32[0] )
            return;
          v28 = _mm_unpackhi_ps(v17, v27);
        }
        v29 = collector->vfptr;
        v48 = v16;
        v51 = bodyA;
        v52 = bodyB;
        v49 = _mm_shuffle_ps(v17, v28, 196);
        v50 = v49;
        v29->addCdPoint(collector, (hkpCdPoint *)&v48);
      }
    }
  }
}

// File Line: 201
// RVA: 0xD35B60
void __fastcall hkpIterativeLinearCastAgent::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  __int128 v5; // xmm2
  hkpShape *m_shape; // rax
  __int128 v11; // xmm0
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkpCollisionDispatcher *m_storage; // r8
  void (__fastcall *m_getClosestPointFunc)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *); // r12
  __m128 v17; // xmm6
  __int128 v18; // xmm10
  hkpCdPointCollectorVtbl *vfptr; // rax
  hkVector4f v20; // xmm8
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  hkpCollisionAgentConfig *m_config; // rcx
  hkpCdPointCollectorVtbl *v26; // rax
  __int128 *m_motion; // rax
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm7
  __m128 v31; // xmm2
  __m128 v32; // xmm7
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  hkpShape *v35; // rax
  int v36; // edi
  __m128 *v37; // rax
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm4
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  hkpCdPointCollectorVtbl *v43; // rax
  __int128 v44; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v45; // [rsp+30h] [rbp-D0h]
  __m128 v46; // [rsp+40h] [rbp-C0h]
  hkpCdBody *v47; // [rsp+50h] [rbp-B0h]
  hkpCdBody *v48; // [rsp+58h] [rbp-A8h]
  hkpShape *v49; // [rsp+60h] [rbp-A0h] BYREF
  int v50; // [rsp+68h] [rbp-98h]
  __int128 *v51; // [rsp+70h] [rbp-90h]
  hkpCdBody *v52; // [rsp+78h] [rbp-88h]
  void **v53; // [rsp+80h] [rbp-80h] BYREF
  int v54; // [rsp+88h] [rbp-78h]
  __int128 v55; // [rsp+90h] [rbp-70h]
  __m128 v56; // [rsp+A0h] [rbp-60h]
  __int64 v57; // [rsp+B0h] [rbp-50h]
  __m128 v58; // [rsp+D0h] [rbp-30h]
  __int128 v59; // [rsp+E0h] [rbp-20h] BYREF
  __int128 v60; // [rsp+F0h] [rbp-10h]
  __int128 v61; // [rsp+100h] [rbp+0h]
  __m128 m_quad; // [rsp+110h] [rbp+10h]
  __m128 v63; // [rsp+120h] [rbp+20h]
  __m128 v64; // [rsp+130h] [rbp+30h]
  void **v65; // [rsp+140h] [rbp+40h] BYREF
  int v66; // [rsp+148h] [rbp+48h]
  __int128 v67; // [rsp+150h] [rbp+50h]
  __m128 v68; // [rsp+160h] [rbp+60h]
  __int64 v69; // [rsp+170h] [rbp+70h]
  __m128 v70; // [rsp+190h] [rbp+90h]
  __int128 v71[3]; // [rsp+1A0h] [rbp+A0h] BYREF
  hkpCdBody *v72; // [rsp+1D0h] [rbp+D0h]
  hkpCdBody *v73; // [rsp+1D8h] [rbp+D8h]
  __int128 v74[3]; // [rsp+1E0h] [rbp+E0h] BYREF
  __m128 v75; // [rsp+210h] [rbp+110h]

  v5 = *(_OWORD *)&input->m_tolerance.m_storage;
  m_shape = bodyA->m_shape;
  v66 = 2139095022;
  v60 = v5;
  *(float *)&v5 = *(float *)&v5 + input->m_cachedPathLength;
  v65 = &hkpClosestCdPointCollector::`vftable;
  v69 = 0i64;
  LODWORD(v60) = v5;
  v59 = *(_OWORD *)&input->m_dispatcher.m_storage;
  v11 = *(_OWORD *)&input->m_convexListFilter.m_storage;
  v68 = _mm_shuffle_ps(v68, _mm_unpackhi_ps(v68, (__m128)xmmword_141A712A0), 196);
  HIDWORD(v59) = 1;
  v12.m_quad = (__m128)input->m_aabb32Info.m_bitOffsetLow;
  v61 = v11;
  v13.m_quad = (__m128)input->m_aabb32Info.m_bitOffsetHigh;
  m_quad = v12.m_quad;
  v14.m_quad = (__m128)input->m_aabb32Info.m_bitScale;
  v63 = v13.m_quad;
  m_storage = input->m_dispatcher.m_storage;
  v64 = v14.m_quad;
  m_getClosestPointFunc = m_storage->m_agent2Func[(unsigned __int8)m_storage->m_agent2Types[(unsigned __int8)m_shape->m_type.m_storage][(unsigned __int8)bodyB->m_shape->m_type.m_storage]].m_getClosestPointFunc;
  m_getClosestPointFunc(bodyA, bodyB, (hkpCollisionInput *)&v59, (hkpCdPointCollector *)&v65);
  if ( v69 )
  {
    v17 = v68;
    v18 = v67;
    if ( _mm_shuffle_ps(v68, v68, 255).m128_f32[0] < _mm_shuffle_ps(
                                                       (__m128)LODWORD(input->m_tolerance.m_storage),
                                                       (__m128)LODWORD(input->m_tolerance.m_storage),
                                                       0).m128_f32[0]
      && startCollector )
    {
      vfptr = startCollector->vfptr;
      v44 = v67;
      v45 = v68;
      v47 = bodyA;
      v48 = bodyB;
      v46 = v68;
      vfptr->addCdPoint(startCollector, (hkpCdPoint *)&v44);
    }
    v20.m_quad = (__m128)input->m_path;
    v21 = _mm_mul_ps(v70, v20.m_quad);
    v22 = _mm_shuffle_ps(v17, v17, 255);
    v23 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170));
    v24 = _mm_add_ps(v23, v22);
    if ( v24.m128_f32[0] <= 0.0
      && (float)(_mm_shuffle_ps(
                   (__m128)LODWORD(input->m_maxExtraPenetration),
                   (__m128)LODWORD(input->m_maxExtraPenetration),
                   0).m128_f32[0]
               + v23.m128_f32[0]) < 0.0 )
    {
      m_config = input->m_config;
      if ( v22.m128_f32[0] > _mm_shuffle_ps(
                               (__m128)LODWORD(m_config->m_iterativeLinearCastEarlyOutDistance),
                               (__m128)LODWORD(m_config->m_iterativeLinearCastEarlyOutDistance),
                               0).m128_f32[0] )
      {
        m_motion = (__int128 *)bodyA->m_motion;
        v53 = &hkpClosestCdPointCollector::`vftable;
        v57 = 0i64;
        v54 = 2139095022;
        v28 = _mm_sub_ps(v22, v24);
        v29 = _mm_rcp_ps(v28);
        v30 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v28)), v29);
        v31 = (__m128)xmmword_141A712A0;
        v32 = _mm_mul_ps(v30, v22);
        v33 = _mm_shuffle_ps(v56, _mm_unpackhi_ps(v56, (__m128)xmmword_141A712A0), 196);
        v56 = v33;
        v74[0] = *m_motion;
        v74[1] = m_motion[1];
        v74[2] = m_motion[2];
        v34 = (__m128)m_motion[3];
        v52 = bodyA;
        v50 = -1;
        v51 = v74;
        v35 = bodyA->m_shape;
        v75 = v34;
        v49 = v35;
        v36 = m_config->m_iterativeLinearCastMaxIterations - 1;
        if ( v36 < 0 )
        {
LABEL_19:
          if ( DWORD2(v59) )
            v17 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v17), 196);
          v43 = collector->vfptr;
          v71[0] = v18;
          v71[1] = (__int128)v17;
          v71[2] = (__int128)v17;
          v72 = bodyA;
          v73 = bodyB;
          v43->addCdPoint(collector, (hkpCdPoint *)v71);
        }
        else
        {
          while ( 1 )
          {
            v37 = (__m128 *)bodyA->m_motion;
            v57 = 0i64;
            v54 = 2139095022;
            v56 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v31), 196);
            v75 = _mm_add_ps(_mm_mul_ps(v32, v20.m_quad), v37[3]);
            m_getClosestPointFunc((hkpCdBody *)&v49, bodyB, (hkpCollisionInput *)&v59, (hkpCdPointCollector *)&v53);
            if ( !v57 )
              break;
            v20.m_quad = (__m128)input->m_path;
            v18 = v55;
            v38 = _mm_mul_ps(v58, v20.m_quad);
            v17 = _mm_shuffle_ps(v58, _mm_unpackhi_ps(v58, v32), 196);
            v39 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                    _mm_shuffle_ps(v38, v38, 170));
            if ( v39.m128_f32[0] >= 0.0 )
              break;
            v33 = v56;
            v40 = _mm_sub_ps((__m128)0i64, v39);
            v41 = _mm_shuffle_ps(v56, v56, 255);
            if ( (float)((float)(_mm_shuffle_ps(v17, v17, 255).m128_f32[0] * v40.m128_f32[0]) + v41.m128_f32[0]) > v40.m128_f32[0] )
              break;
            if ( v41.m128_f32[0] <= _mm_shuffle_ps(
                                      (__m128)input->m_config->m_iterativeLinearCastEarlyOutDistance,
                                      (__m128)input->m_config->m_iterativeLinearCastEarlyOutDistance,
                                      0).m128_f32[0] )
              goto LABEL_19;
            v42 = _mm_rcp_ps(v40);
            v32 = _mm_add_ps(v32, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v40)), v42), v41));
            if ( v32.m128_f32[0] > _mm_shuffle_ps(
                                     (__m128)LODWORD(collector->m_earlyOutDistance),
                                     (__m128)LODWORD(collector->m_earlyOutDistance),
                                     0).m128_f32[0] )
              break;
            if ( --v36 < 0 )
              goto LABEL_19;
            v31 = (__m128)xmmword_141A712A0;
          }
        }
      }
      else if ( v22.m128_f32[0] <= 0.0
             || v22.m128_f32[0] <= (float)(_mm_shuffle_ps(
                                             (__m128)LODWORD(collector->m_earlyOutDistance),
                                             (__m128)LODWORD(collector->m_earlyOutDistance),
                                             0).m128_f32[0]
                                         * (float)(v22.m128_f32[0] - v24.m128_f32[0])) )
      {
        v26 = collector->vfptr;
        v44 = v18;
        v47 = bodyA;
        v48 = bodyB;
        v45 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, aabbOut.m_quad), 196);
        v46 = v45;
        v26->addCdPoint(collector, (hkpCdPoint *)&v44);
      }
    }
  }
}

