// File Line: 38
// RVA: 0xE5090
void __fastcall hkaiAvoidanceProperties::hkaiAvoidanceProperties(hkaiAvoidanceProperties *this)
{
  hkVector4f v1; // xmm2

  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAvoidanceProperties::`vftable';
  this->m_movementProperties.m_minVelocity = 0.02;
  this->m_movementProperties.m_maxVelocity = 5.6399999;
  this->m_movementProperties.m_maxAcceleration = 20.0;
  this->m_movementProperties.m_maxDeceleration = 30.0;
  this->m_movementProperties.m_leftTurnRadius = -1.0;
  this->m_movementProperties.m_rightTurnRadius = -1.0;
  this->m_movementProperties.m_maxAngularVelocity = 3.926991;
  this->m_movementProperties.m_maxTurnVelocity = 2.8199999;
  this->m_movementProperties.m_kinematicConstraintType.m_storage = 2;
  *(_WORD *)&this->m_avoidanceSolverType.m_storage = 256;
  this->m_agentLimitTime = 1.0;
  this->m_obstacleLimitTime = 1.0;
  this->m_boundaryLimitTime = 0.30000001;
  this->m_limitObstacleDistance = 1.0;
  this->m_limitBoundaryDistance = -1.0;
  this->m_limitObstacleVelocity = 0.5;
  this->m_wallFollowingAngle = 0.1;
  this->m_dodgingPenalty = 1.0;
  *(_QWORD *)&this->m_velocityHysteresis = 1008981770i64;
  this->m_collisionPenalty = 1.0;
  this->m_penetrationPenalty = 100.0;
  this->m_maxNeighbors = 16;
  v1.m_quad = _mm_shuffle_ps((__m128)LODWORD(FLOAT_5_0), (__m128)LODWORD(FLOAT_5_0), 0);
  this->m_localSensorAabb.m_max = (hkVector4f)v1.m_quad;
  this->m_localSensorAabb.m_min.m_quad = _mm_xor_ps(
                                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                           v1.m_quad);
}

