// File Line: 19
// RVA: 0x131D5E0
float __fastcall hkpWorldLinearCaster::addBroadPhaseHandle(hkpWorldLinearCaster *this, hkpBroadPhaseHandle *broadPhaseHandle, int castIndex)
{
  hkpWorldLinearCaster *v3; // rbx
  hkpCollidable *v4; // rdi
  hkpShape *v5; // rsi
  hkpCollidable *v6; // r8
  hkpCdPointCollector *v7; // rax
  char v9; // [rsp+48h] [rbp+10h]

  v3 = this;
  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  v5 = v4->m_shape;
  if ( v4->m_shape && (v6 = this->m_collidableA, v6 != v4) )
  {
    if ( *(_BYTE *)this->m_filter->vfptr->isCollisionEnabled(this->m_filter, (hkBool *)&v9, v6, v4) )
      v3->m_shapeInput.m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v3->m_shapeInput.m_dispatcher.m_storage->m_agent2Types[v3->m_typeA][(unsigned __int8)v5->m_type.m_storage]].m_linearCastFunc(
        (hkpCdBody *)&v3->m_collidableA->m_shape,
        (hkpCdBody *)&v4->m_shape,
        &v3->m_shapeInput,
        v3->m_castCollector,
        v3->m_startPointCollector);
    v7 = v3->m_castCollector;
  }
  else
  {
    v7 = this->m_castCollector;
  }
  return v7->m_earlyOutDistance;
}

// File Line: 50
// RVA: 0x131D410
void __fastcall hkpWorldLinearCaster::linearCast(hkpWorldLinearCaster *this, hkpBroadPhase *broadphase, hkpCollidable *collA, hkpLinearCastInput *input, hkpCollidableCollidableFilter *filter, hkpCollisionInput *collInput, hkpCollisionAgentConfig *config, char *m_broadPhaseCache, hkpCdPointCollector *castCollector, hkpCdPointCollector *startPointCollector)
{
  hkpWorldLinearCaster *v10; // rdi
  hkpLinearCastInput *v11; // rbx
  hkcdShapeType::ShapeTypeEnum v12; // er10
  hkpBroadPhase *v13; // rsi
  float v14; // xmm5_4
  hkVector4f v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __int128 v19; // xmm2
  __m128 v20; // xmm2
  float v21; // eax
  __m128 v22; // [rsp+20h] [rbp-78h]
  __m128 v23; // [rsp+30h] [rbp-68h]
  __m128 v24; // [rsp+40h] [rbp-58h]
  __m128 v25; // [rsp+50h] [rbp-48h]
  __m128 v26; // [rsp+60h] [rbp-38h]
  char *v27; // [rsp+70h] [rbp-28h]

  this->m_collidableA = collA;
  this->m_castCollector = castCollector;
  v10 = this;
  this->m_startPointCollector = startPointCollector;
  v11 = input;
  this->m_filter = filter;
  this->m_input = input;
  v12 = (unsigned __int8)collA->m_shape->m_type.m_storage;
  v27 = 0i64;
  v13 = broadphase;
  this->m_typeA = v12;
  this->m_shapeInput.m_dispatcher.m_storage = collInput->m_dispatcher.m_storage;
  this->m_shapeInput.m_weldClosestPoints.m_storage = collInput->m_weldClosestPoints.m_storage;
  this->m_shapeInput.m_forceAcceptContactPoints.m_storage = collInput->m_forceAcceptContactPoints.m_storage;
  this->m_shapeInput.m_tolerance.m_storage = collInput->m_tolerance.m_storage;
  this->m_shapeInput.m_filter.m_storage = collInput->m_filter.m_storage;
  this->m_shapeInput.m_convexListFilter.m_storage = collInput->m_convexListFilter.m_storage;
  this->m_shapeInput.m_createPredictiveAgents.m_storage = collInput->m_createPredictiveAgents.m_storage;
  this->m_shapeInput.m_aabb32Info.m_bitOffsetLow = collInput->m_aabb32Info.m_bitOffsetLow;
  this->m_shapeInput.m_aabb32Info.m_bitOffsetHigh = collInput->m_aabb32Info.m_bitOffsetHigh;
  this->m_shapeInput.m_aabb32Info.m_bitScale = collInput->m_aabb32Info.m_bitScale;
  this->m_shapeInput.m_config = config;
  v14 = input->m_startPointTolerance;
  v15.m_quad = _mm_sub_ps(input->m_to.m_quad, *((__m128 *)collA->m_motion + 3));
  this->m_shapeInput.m_path = (hkVector4f)v15.m_quad;
  v16 = _mm_mul_ps(v15.m_quad, v15.m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  LODWORD(this->m_shapeInput.m_cachedPathLength) = (unsigned __int128)_mm_andnot_ps(
                                                                        _mm_cmpleps(v17, (__m128)0i64),
                                                                        _mm_mul_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_sub_ps(
                                                                              (__m128)_xmm,
                                                                              _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                                                            _mm_mul_ps(*(__m128 *)_xmm, v18)),
                                                                          v17));
  this->m_shapeInput.m_tolerance.m_storage = v14;
  v19 = LODWORD(input->m_startPointTolerance);
  ((void (__fastcall *)(hkpShape *, const void *, hkpCollidable *, __m128 *))collA->m_shape->vfptr[2].__vecDelDtor)(
    collA->m_shape,
    collA->m_motion,
    collA,
    &v22);
  v20 = _mm_mul_ps(_mm_sub_ps(v23, v22), (__m128)xmmword_141A711B0);
  v24 = _mm_add_ps(v20, v22);
  v27 = m_broadPhaseCache;
  v21 = v11->m_maxExtraPenetration;
  v26 = v20;
  v25 = _mm_add_ps(v15.m_quad, v24);
  v10->m_shapeInput.m_maxExtraPenetration = v21;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpWorldLinearCaster *))v13->vfptr[14].__first_virtual_table_function__)(
    v13,
    &v24,
    v10);
}tr[14].__first_vir

