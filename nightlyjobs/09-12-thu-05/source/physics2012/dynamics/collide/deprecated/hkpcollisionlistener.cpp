// File Line: 16
// RVA: 0x132E300
void __fastcall hkpCollisionListener::contactPointCallback(hkpCollisionListener *this, hkpContactPointEvent *event)
{
  hkpContactPointEvent::Type m_type; // eax
  int v5; // edi
  int v6; // xmm6_4
  float *m_separatingVelocity; // rax
  __m128 m_real; // xmm0
  hkpRigidBody *v9; // rdx
  hkpRigidBody *v10; // r8
  hkpCollisionEvent::CallbackSource m_source; // ecx
  hkSimdFloat32 result; // [rsp+30h] [rbp-68h] BYREF
  __int64 v13[2]; // [rsp+40h] [rbp-58h] BYREF
  hkpRigidBody *v14; // [rsp+50h] [rbp-48h]
  hkContactPoint *m_contactPoint; // [rsp+58h] [rbp-40h]
  hkpContactPointProperties *m_contactPointProperties; // [rsp+60h] [rbp-38h]
  int v17; // [rsp+68h] [rbp-30h]
  int v18; // [rsp+6Ch] [rbp-2Ch]
  int v19; // [rsp+70h] [rbp-28h]
  hkpSimpleContactConstraintData *p_m_contactConstraintData; // [rsp+78h] [rbp-20h]

  if ( (event->m_contactPointProperties->m_flags & 1) != 0 )
  {
    m_type = event->m_type;
    if ( m_type != 3 )
    {
      if ( m_type > TYPE_TOI )
      {
        v5 = 1;
        v6 = 0;
      }
      else
      {
        v5 = 0;
        v6 = *(_DWORD *)event->m_rotateNormal;
      }
      m_separatingVelocity = event->m_separatingVelocity;
      if ( m_separatingVelocity )
        m_real.m128_f32[0] = *m_separatingVelocity;
      else
        m_real = hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
                   &result,
                   event->m_bodies[0],
                   event->m_bodies[1],
                   &event->m_bodies[0]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
                   &event->m_bodies[1]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
                   event->m_contactPoint)->m_real;
      v9 = event->m_bodies[0];
      v10 = event->m_bodies[1];
      m_source = event->m_source;
      v17 = v6;
      v18 = m_real.m128_i32[0];
      v19 = v5;
      v13[0] = (__int64)&v9->m_collidable;
      v13[1] = (__int64)&v10->m_collidable;
      m_contactPoint = event->m_contactPoint;
      m_contactPointProperties = event->m_contactPointProperties;
      p_m_contactConstraintData = &event->m_contactMgr->m_contactConstraintData;
      if ( m_source )
      {
        if ( m_source == SOURCE_B )
          v14 = v10;
        else
          v14 = 0i64;
      }
      else
      {
        v14 = v9;
      }
      this->vfptr[1].contactPointCallback(this, (hkpContactPointEvent *)v13);
      *(_DWORD *)event->m_separatingVelocity = v18;
      if ( event->m_type <= TYPE_TOI )
        *(_DWORD *)event->m_rotateNormal = v17;
    }
  }
}

