// File Line: 19
// RVA: 0x131D5E0
float __fastcall hkpWorldLinearCaster::addBroadPhaseHandle(
        hkpWorldLinearCaster *this,
        hkpBroadPhaseHandle *broadPhaseHandle,
        int castIndex)
{
  hkpCollidable *v4; // rdi
  hkpShape *m_shape; // rsi
  hkpCollidable *m_collidableA; // r8
  hkpCdPointCollector *m_castCollector; // rax
  char v9; // [rsp+48h] [rbp+10h] BYREF

  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  m_shape = v4->m_shape;
  if ( !v4->m_shape || (m_collidableA = this->m_collidableA, m_collidableA == v4) )
  {
    m_castCollector = this->m_castCollector;
  }
  else
  {
    if ( this->m_filter->vfptr->isCollisionEnabled(this->m_filter, &v9, m_collidableA, v4)->m_bool )
      this->m_shapeInput.m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)this->m_shapeInput.m_dispatcher.m_storage->m_agent2Types[this->m_typeA][(unsigned __int8)m_shape->m_type.m_storage]].m_linearCastFunc(
        this->m_collidableA,
        v4,
        &this->m_shapeInput,
        this->m_castCollector,
        this->m_startPointCollector);
    m_castCollector = this->m_castCollector;
  }
  return m_castCollector->m_earlyOutDistance;
}

// File Line: 50
// RVA: 0x131D410
void __fastcall hkpWorldLinearCaster::linearCast(
        hkpWorldLinearCaster *this,
        hkpBroadPhase *broadphase,
        hkpCollidable *collA,
        hkpLinearCastInput *input,
        hkpCollidableCollidableFilter *filter,
        hkpCollisionInput *collInput,
        hkpCollisionAgentConfig *config,
        char *m_broadPhaseCache,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startPointCollector)
{
  hkcdShapeType::ShapeTypeEnum m_storage; // r10d
  float m_startPointTolerance; // xmm5_4
  hkVector4f v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float m_maxExtraPenetration; // eax
  __m128 v21[2]; // [rsp+20h] [rbp-78h] BYREF
  __m128 v22[3]; // [rsp+40h] [rbp-58h] BYREF
  char *v23; // [rsp+70h] [rbp-28h]

  this->m_collidableA = collA;
  this->m_castCollector = castCollector;
  this->m_startPointCollector = startPointCollector;
  this->m_filter = filter;
  this->m_input = input;
  m_storage = (unsigned __int8)collA->m_shape->m_type.m_storage;
  v23 = 0i64;
  this->m_typeA = m_storage;
  this->m_shapeInput.m_dispatcher.m_storage = collInput->m_dispatcher.m_storage;
  this->m_shapeInput.m_weldClosestPoints.m_storage = collInput->m_weldClosestPoints.m_storage;
  this->m_shapeInput.m_forceAcceptContactPoints.m_storage = collInput->m_forceAcceptContactPoints.m_storage;
  this->m_shapeInput.m_tolerance.m_storage = collInput->m_tolerance.m_storage;
  this->m_shapeInput.m_filter.m_storage = collInput->m_filter.m_storage;
  this->m_shapeInput.m_convexListFilter.m_storage = collInput->m_convexListFilter.m_storage;
  this->m_shapeInput.m_createPredictiveAgents.m_storage = collInput->m_createPredictiveAgents.m_storage;
  this->m_shapeInput.m_aabb32Info = collInput->m_aabb32Info;
  this->m_shapeInput.m_config = config;
  m_startPointTolerance = input->m_startPointTolerance;
  v15.m_quad = _mm_sub_ps(input->m_to.m_quad, *((__m128 *)collA->m_motion + 3));
  this->m_shapeInput.m_path = (hkVector4f)v15.m_quad;
  v16 = _mm_mul_ps(v15.m_quad, v15.m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  LODWORD(this->m_shapeInput.m_cachedPathLength) = _mm_andnot_ps(
                                                     _mm_cmple_ps(v17, (__m128)0i64),
                                                     _mm_mul_ps(
                                                       _mm_mul_ps(
                                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                                         _mm_mul_ps(*(__m128 *)_xmm, v18)),
                                                       v17)).m128_u32[0];
  this->m_shapeInput.m_tolerance.m_storage = m_startPointTolerance;
  ((void (__fastcall *)(hkpShape *, const void *, hkpCollidable *, __m128 *))collA->m_shape->vfptr[2].__vecDelDtor)(
    collA->m_shape,
    collA->m_motion,
    collA,
    v21);
  v19 = _mm_mul_ps(_mm_sub_ps(v21[1], v21[0]), (__m128)xmmword_141A711B0);
  v22[0] = _mm_add_ps(v19, v21[0]);
  v23 = m_broadPhaseCache;
  m_maxExtraPenetration = input->m_maxExtraPenetration;
  v22[2] = v19;
  v22[1] = _mm_add_ps(v15.m_quad, v22[0]);
  this->m_shapeInput.m_maxExtraPenetration = m_maxExtraPenetration;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkpWorldLinearCaster *))broadphase->vfptr[14].__first_virtual_table_function__)(
    broadphase,
    v22,
    this);
}

