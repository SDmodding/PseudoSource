// File Line: 17
// RVA: 0xE112D0
void __fastcall hkpSurfaceVelocityUtil::hkpSurfaceVelocityUtil(
        hkpSurfaceVelocityUtil *this,
        hkpRigidBody *body,
        hkVector4f *surfaceVelocityWorld)
{
  hkpRigidBody *m_rigidBody; // rcx

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpContactListener};
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpEntityListener};
  hkReferencedObject::addReference(this);
  this->m_rigidBody = body;
  body->m_responseModifierFlags |= 4u;
  m_rigidBody = this->m_rigidBody;
  this->m_surfaceVelocity = (hkVector4f)surfaceVelocityWorld->m_quad;
  hkpEntity::addContactListener(m_rigidBody, &this->hkpContactListener);
  hkpEntity::addEntityListener(this->m_rigidBody, &this->hkpEntityListener);
}

// File Line: 30
// RVA: 0xE114E0
void __fastcall hkpSurfaceVelocityUtil::contactPointCallback(hkpSurfaceVelocityUtil *this, hkpContactPointEvent *event)
{
  hkpAddModifierUtil::setSurfaceVelocity(
    event,
    (hkpRigidBody *)this->hkpContactListener::vfptr,
    (hkVector4f *)&this->m_rigidBody);
}

// File Line: 36
// RVA: 0xE11380
void __fastcall hkpSurfaceVelocityUtil::~hkpSurfaceVelocityUtil(hkpSurfaceVelocityUtil *this)
{
  hkpRigidBody *m_rigidBody; // rcx

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpContactListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpEntityListener};
  m_rigidBody = this->m_rigidBody;
  if ( m_rigidBody )
  {
    hkpEntity::removeContactListener(m_rigidBody, &this->hkpContactListener);
    hkpEntity::removeEntityListener(this->m_rigidBody, &this->hkpEntityListener);
  }
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 45
// RVA: 0xE11500
void __fastcall hkpSurfaceVelocityUtil::entityDeletedCallback(hkpSurfaceVelocityUtil *this, hkpEntity *entity)
{
  hkReferencedObject *v2; // rdi
  hkpContactListener *v5; // rdx
  hkpEntityListener *v6; // rdx

  v2 = (hkpSurfaceVelocityUtil *)((char *)this - 24);
  if ( this == (hkpSurfaceVelocityUtil *)24 )
    v5 = 0i64;
  else
    v5 = (hkpContactListener *)&this[-1].m_surfaceVelocity.m_quad.m128_u16[4];
  hkpEntity::removeContactListener(entity, v5);
  v6 = 0i64;
  if ( v2 )
    v6 = (hkpEntityListener *)this;
  hkpEntity::removeEntityListener(entity, v6);
  *(_QWORD *)&this->m_memSizeAndFlags = 0i64;
  hkReferencedObject::removeReference(v2);
}

// File Line: 54
// RVA: 0xE11410
void __fastcall hkpSurfaceVelocityUtil::setSurfaceVelocity(hkpSurfaceVelocityUtil *this, hkVector4f *velWorld)
{
  hkpRigidBody *m_rigidBody; // rsi
  int v4; // ebx
  __int64 v5; // rdi
  hkpDynamicsContactMgr *m_contactMgr; // r14
  hkpConstraintInstance *v7; // rax
  hkpSimulationIsland *SimulationIsland; // rax

  if ( (_mm_movemask_ps(_mm_cmpeq_ps(velWorld->m_quad, this->m_surfaceVelocity.m_quad)) & 7) != 7 )
  {
    m_rigidBody = this->m_rigidBody;
    this->m_surfaceVelocity = (hkVector4f)velWorld->m_quad;
    v4 = 0;
    if ( m_rigidBody->m_collidable.m_collisionEntries.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        m_contactMgr = (hkpDynamicsContactMgr *)m_rigidBody->m_collidable.m_collisionEntries.m_data[v5].m_agentEntry->m_contactMgr;
        v7 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *))m_contactMgr->vfptr[8].__vecDelDtor)(m_contactMgr);
        if ( v7 )
        {
          if ( v7->m_internal )
          {
            SimulationIsland = hkpConstraintInstance::getSimulationIsland(v7);
            hkpResponseModifier::setSurfaceVelocity(
              m_contactMgr,
              this->m_rigidBody,
              SimulationIsland,
              &this->m_surfaceVelocity);
          }
        }
        ++v4;
        ++v5;
      }
      while ( v4 < m_rigidBody->m_collidable.m_collisionEntries.m_size );
    }
  }
}

