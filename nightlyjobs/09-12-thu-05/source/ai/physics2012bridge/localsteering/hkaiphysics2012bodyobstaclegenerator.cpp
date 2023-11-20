// File Line: 16
// RVA: 0xC2F410
void __fastcall hkaiPhysics2012BodyObstacleGenerator::hkaiPhysics2012BodyObstacleGenerator(hkaiPhysics2012BodyObstacleGenerator *this, hkpRigidBody *rigidBody)
{
  hkpRigidBody *v2; // rdi
  hkaiPhysics2012BodyObstacleGenerator *v3; // rbx

  v2 = rigidBody;
  v3 = this;
  hkaiObstacleGenerator::hkaiObstacleGenerator((hkaiObstacleGenerator *)&this->vfptr);
  v3->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodyObstacleGenerator::`vftable';
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v3->m_rigidBody.m_pntr = v2;
  v3->m_velocityThreshold = 3.0;
  v3->m_clipBoundaries.m_bool = 1;
}

// File Line: 24
// RVA: 0xC2F470
void __fastcall hkaiPhysics2012BodyObstacleGenerator::hkaiPhysics2012BodyObstacleGenerator(hkaiPhysics2012BodyObstacleGenerator *this, hkFinishLoadedObjectFlag f)
{
  hkaiPhysics2012BodyObstacleGenerator *v2; // rbx

  v2 = this;
  hkaiObstacleGenerator::hkaiObstacleGenerator((hkaiObstacleGenerator *)&this->vfptr, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodyObstacleGenerator::`vftable';
}

// File Line: 29
// RVA: 0xC2F4A0
void __fastcall hkaiPhysics2012BodyObstacleGenerator::~hkaiPhysics2012BodyObstacleGenerator(hkaiPhysics2012BodyObstacleGenerator *this)
{
  hkaiPhysics2012BodyObstacleGenerator *v1; // rbx
  hkpRigidBody *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodyObstacleGenerator::`vftable';
  v2 = this->m_rigidBody.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_rigidBody.m_pntr = 0i64;
  hkaiObstacleGenerator::~hkaiObstacleGenerator((hkaiObstacleGenerator *)&v1->vfptr);
}

// File Line: 33
// RVA: 0xC2F4F0
void __fastcall hkaiPhysics2012BodyObstacleGenerator::update(hkaiPhysics2012BodyObstacleGenerator *this)
{
  hkpRigidBody *v1; // rdx
  hkaiPhysics2012BodyObstacleGenerator *v2; // rbx
  hkVector4f *v3; // rax
  __m128 v4; // xmm3
  int v5; // edi
  float v6; // xmm3_4
  __int64 v7; // r8
  __int64 v8; // rcx
  hkSimpleProperty *v9; // rax
  __m128 v10; // xmm2
  char v11; // al
  __int64 v12; // rbp
  __m128 *v13; // rax
  hkaiAvoidanceSolver::SphereObstacle *v14; // rcx
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __int64 v18; // rcx
  hkVector4f v19; // [rsp+20h] [rbp-18h]

  v1 = this->m_rigidBody.m_pntr;
  v2 = this;
  v3 = (hkVector4f *)v1->m_collidable.m_motion;
  if ( !v3 )
  {
    *(_WORD *)&this->m_useSpheres.m_bool = 0;
    this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    this->m_transform.m_translation = 0i64;
    return;
  }
  v4 = (__m128)LODWORD(this->m_velocityThreshold);
  this->m_transform.m_rotation.m_col0 = (hkVector4f)v3->m_quad;
  v5 = 0;
  v4.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v4, v4, 0);
  v6 = v4.m128_f32[0] * v4.m128_f32[0];
  this->m_transform.m_rotation.m_col1 = (hkVector4f)v3[1].m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)v3[2].m_quad;
  this->m_transform.m_translation = (hkVector4f)v3[3].m_quad;
  if ( v1->m_collidable.m_broadPhaseHandle.m_type == 1 )
  {
    v7 = v1->m_properties.m_size;
    v8 = 0i64;
    if ( v7 <= 0 )
    {
LABEL_8:
      v10 = _mm_mul_ps(v1->m_motion.m_linearVelocity.m_quad, v1->m_motion.m_linearVelocity.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170))) < v6 )
      {
        v11 = 0;
        goto LABEL_11;
      }
    }
    else
    {
      v9 = v1->m_properties.m_data;
      while ( v9->m_key != 1699627811 )
      {
        ++v8;
        ++v9;
        if ( v8 >= v7 )
          goto LABEL_8;
      }
    }
  }
  v11 = 1;
LABEL_11:
  v2->m_useSpheres.m_bool = v11;
  v2->m_useBoundaries.m_bool = 1;
  if ( v11 )
  {
    if ( v1->m_collidable.m_broadPhaseHandle.m_type == 1 )
    {
      if ( v2->m_spheres.m_size > 0 )
      {
        v12 = 0i64;
        do
        {
          hkVector4f::setTransformedPos(&v19, &v2->m_transform, &v2->m_spheres.m_data[v5].m_sphere.m_pos);
          v13 = (__m128 *)v2->m_rigidBody.m_pntr;
          v14 = v2->m_spheres.m_data;
          v15 = _mm_sub_ps(v19.m_quad, v13[28]);
          ++v5;
          ++v12;
          v16 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v13[36]),
                  _mm_mul_ps(_mm_shuffle_ps(v13[36], v13[36], 201), v15));
          v17 = _mm_shuffle_ps(v16, v16, 201);
          *((__m128 *)&v14[v12] - 1) = v17;
          *((__m128 *)&v14[v12] - 1) = _mm_add_ps(v13[35], v17);
        }
        while ( v5 < v2->m_spheres.m_size );
      }
    }
    else if ( v2->m_spheres.m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        ++v5;
        ++v18;
        *((_OWORD *)&v2->m_spheres.m_data[v18] - 1) = 0i64;
      }
      while ( v5 < v2->m_spheres.m_size );
    }
  }
}

// File Line: 80
// RVA: 0xC2F6C0
void __fastcall hkaiPhysics2012BodyObstacleGenerator::getAabb(hkaiPhysics2012BodyObstacleGenerator *this, hkAabb *aabbOut, __int64 a3)
{
  ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, hkAabb *))this->m_rigidBody.m_pntr->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
    this->m_rigidBody.m_pntr->m_collidable.m_shape,
    &this->m_rigidBody.m_pntr->m_motion.m_motionState,
    a3,
    aabbOut);
}

