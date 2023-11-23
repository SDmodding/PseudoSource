// File Line: 16
// RVA: 0xC2F410
void __fastcall hkaiPhysics2012BodyObstacleGenerator::hkaiPhysics2012BodyObstacleGenerator(
        hkaiPhysics2012BodyObstacleGenerator *this,
        hkpRigidBody *rigidBody)
{
  hkaiObstacleGenerator::hkaiObstacleGenerator(this);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodyObstacleGenerator::`vftable;
  if ( rigidBody )
    hkReferencedObject::addReference(rigidBody);
  this->m_rigidBody.m_pntr = rigidBody;
  this->m_velocityThreshold = 3.0;
  this->m_clipBoundaries.m_bool = 1;
}

// File Line: 24
// RVA: 0xC2F470
void __fastcall hkaiPhysics2012BodyObstacleGenerator::hkaiPhysics2012BodyObstacleGenerator(
        hkaiPhysics2012BodyObstacleGenerator *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiObstacleGenerator::hkaiObstacleGenerator(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodyObstacleGenerator::`vftable;
}

// File Line: 29
// RVA: 0xC2F4A0
void __fastcall hkaiPhysics2012BodyObstacleGenerator::~hkaiPhysics2012BodyObstacleGenerator(
        hkaiPhysics2012BodyObstacleGenerator *this)
{
  hkpRigidBody *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodyObstacleGenerator::`vftable;
  m_pntr = this->m_rigidBody.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_rigidBody.m_pntr = 0i64;
  hkaiObstacleGenerator::~hkaiObstacleGenerator(this);
}

// File Line: 33
// RVA: 0xC2F4F0
void __fastcall hkaiPhysics2012BodyObstacleGenerator::update(hkaiPhysics2012BodyObstacleGenerator *this)
{
  hkpRigidBody *m_pntr; // rdx
  hkTransformf *m_motion; // rax
  __m128 m_velocityThreshold_low; // xmm3
  int v5; // edi
  float v6; // xmm3_4
  __int64 m_size; // r8
  __int64 v8; // rcx
  hkSimpleProperty *m_data; // rax
  __m128 v10; // xmm2
  char v11; // al
  __int64 v12; // rbp
  hkpRigidBody *v13; // rax
  hkaiAvoidanceSolver::SphereObstacle *v14; // rcx
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __int64 v18; // rcx
  hkVector4f v19; // [rsp+20h] [rbp-18h] BYREF

  m_pntr = this->m_rigidBody.m_pntr;
  m_motion = (hkTransformf *)m_pntr->m_collidable.m_motion;
  if ( !m_motion )
  {
    *(_WORD *)&this->m_useSpheres.m_bool = 0;
    this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    this->m_transform.m_translation = 0i64;
    return;
  }
  m_velocityThreshold_low = (__m128)LODWORD(this->m_velocityThreshold);
  this->m_transform = *m_motion;
  v5 = 0;
  m_velocityThreshold_low.m128_f32[0] = _mm_shuffle_ps(m_velocityThreshold_low, m_velocityThreshold_low, 0).m128_f32[0];
  v6 = m_velocityThreshold_low.m128_f32[0] * m_velocityThreshold_low.m128_f32[0];
  if ( m_pntr->m_collidable.m_broadPhaseHandle.m_type == 1 )
  {
    m_size = m_pntr->m_properties.m_size;
    v8 = 0i64;
    if ( m_size <= 0 )
    {
LABEL_8:
      v10 = _mm_mul_ps(m_pntr->m_motion.m_linearVelocity.m_quad, m_pntr->m_motion.m_linearVelocity.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
                 + _mm_shuffle_ps(v10, v10, 170).m128_f32[0]) < v6 )
      {
        v11 = 0;
        goto LABEL_11;
      }
    }
    else
    {
      m_data = m_pntr->m_properties.m_data;
      while ( m_data->m_key != 1699627811 )
      {
        ++v8;
        ++m_data;
        if ( v8 >= m_size )
          goto LABEL_8;
      }
    }
  }
  v11 = 1;
LABEL_11:
  this->m_useSpheres.m_bool = v11;
  this->m_useBoundaries.m_bool = 1;
  if ( v11 )
  {
    if ( m_pntr->m_collidable.m_broadPhaseHandle.m_type == 1 )
    {
      if ( this->m_spheres.m_size > 0 )
      {
        v12 = 0i64;
        do
        {
          hkVector4f::setTransformedPos(&v19, &this->m_transform, &this->m_spheres.m_data[v5].m_sphere.m_pos);
          v13 = this->m_rigidBody.m_pntr;
          v14 = this->m_spheres.m_data;
          v15 = _mm_sub_ps(v19.m_quad, v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
          ++v5;
          ++v12;
          v16 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v13->m_motion.m_angularVelocity.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v13->m_motion.m_angularVelocity.m_quad, v13->m_motion.m_angularVelocity.m_quad, 201),
                    v15));
          v17 = _mm_shuffle_ps(v16, v16, 201);
          v14[v12 - 1].m_velocity.m_quad = v17;
          v14[v12 - 1].m_velocity.m_quad = _mm_add_ps(v13->m_motion.m_linearVelocity.m_quad, v17);
        }
        while ( v5 < this->m_spheres.m_size );
      }
    }
    else if ( this->m_spheres.m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        ++v5;
        this->m_spheres.m_data[v18++].m_velocity = 0i64;
      }
      while ( v5 < this->m_spheres.m_size );
    }
  }
}

// File Line: 80
// RVA: 0xC2F6C0
void __fastcall hkaiPhysics2012BodyObstacleGenerator::getAabb(
        hkaiPhysics2012BodyObstacleGenerator *this,
        hkAabb *aabbOut,
        __int64 a3)
{
  ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, hkAabb *))this->m_rigidBody.m_pntr->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
    this->m_rigidBody.m_pntr->m_collidable.m_shape,
    &this->m_rigidBody.m_pntr->m_motion.m_motionState,
    a3,
    aabbOut);
}

