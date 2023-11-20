// File Line: 16
// RVA: 0x132E300
void __fastcall hkpCollisionListener::contactPointCallback(hkpCollisionListener *this, hkpContactPointEvent *event)
{
  hkpContactPointEvent *v2; // rbx
  hkpCollisionListener *v3; // rsi
  hkpContactPointEvent::Type v4; // eax
  signed int v5; // edi
  int v6; // xmm6_4
  float *v7; // rax
  __m128 v8; // xmm0
  __int64 v9; // rdx
  __int64 v10; // r8
  hkpCollisionEvent::CallbackSource v11; // ecx
  hkSimdFloat32 result; // [rsp+30h] [rbp-68h]
  __int64 v13; // [rsp+40h] [rbp-58h]
  __int64 v14; // [rsp+48h] [rbp-50h]
  __int64 v15; // [rsp+50h] [rbp-48h]
  hkContactPoint *v16; // [rsp+58h] [rbp-40h]
  hkpContactPointProperties *v17; // [rsp+60h] [rbp-38h]
  int v18; // [rsp+68h] [rbp-30h]
  int v19; // [rsp+6Ch] [rbp-2Ch]
  int v20; // [rsp+70h] [rbp-28h]
  hkpSimpleContactConstraintData *v21; // [rsp+78h] [rbp-20h]

  v2 = event;
  v3 = this;
  if ( event->m_contactPointProperties->m_flags & 1 )
  {
    v4 = event->m_type;
    if ( v4 != 3 )
    {
      if ( (signed int)v4 > 0 )
      {
        v5 = 1;
        v6 = 0;
      }
      else
      {
        v5 = 0;
        v6 = *(_DWORD *)event->m_rotateNormal;
      }
      v7 = event->m_separatingVelocity;
      if ( v7 )
        v8.m128_f32[0] = *v7;
      else
        v8 = hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
               &result,
               event->m_bodies[0],
               event->m_bodies[1],
               &event->m_bodies[0]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
               &event->m_bodies[1]->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1,
               event->m_contactPoint)->m_real;
      v9 = (__int64)v2->m_bodies[0];
      v10 = (__int64)v2->m_bodies[1];
      v11 = v2->m_source;
      v18 = v6;
      v19 = v8.m128_i32[0];
      v20 = v5;
      v13 = v9 + 32;
      v14 = v10 + 32;
      v16 = v2->m_contactPoint;
      v17 = v2->m_contactPointProperties;
      v21 = &v2->m_contactMgr->m_contactConstraintData;
      if ( v11 )
      {
        if ( v11 == 1 )
          v15 = v10;
        else
          v15 = 0i64;
      }
      else
      {
        v15 = v9;
      }
      v3->vfptr[1].contactPointCallback((hkpContactListener *)&v3->vfptr, (hkpContactPointEvent *)&v13);
      *(_DWORD *)v2->m_separatingVelocity = v19;
      if ( v2->m_type <= 0 )
        *(_DWORD *)v2->m_rotateNormal = v18;
    }
  }
}

