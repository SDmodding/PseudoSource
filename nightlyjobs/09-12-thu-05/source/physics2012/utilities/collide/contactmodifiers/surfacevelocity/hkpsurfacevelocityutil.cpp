// File Line: 17
// RVA: 0xE112D0
void __fastcall hkpSurfaceVelocityUtil::hkpSurfaceVelocityUtil(hkpSurfaceVelocityUtil *this, hkpRigidBody *body, hkVector4f *surfaceVelocityWorld)
{
  hkVector4f *v3; // rbp
  hkpRigidBody *v4; // rsi
  hkpSurfaceVelocityUtil *v5; // r14
  hkpEntity *v6; // rcx

  v3 = surfaceVelocityWorld;
  v4 = body;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkReferencedObject};
  v5 = this;
  this->vfptr = (hkpContactListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpContactListener};
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkpEntityListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpEntityListener};
  hkReferencedObject::addReference((hkReferencedObject *)&this->vfptr);
  v5->m_rigidBody = v4;
  v4->m_responseModifierFlags |= 4u;
  v6 = (hkpEntity *)&v5->m_rigidBody->vfptr;
  v5->m_surfaceVelocity = (hkVector4f)v3->m_quad;
  hkpEntity::addContactListener(v6, (hkpContactListener *)&v5->vfptr);
  hkpEntity::addEntityListener((hkpEntity *)&v5->m_rigidBody->vfptr, (hkpEntityListener *)&v5->vfptr);
}

// File Line: 30
// RVA: 0xE114E0
void __fastcall hkpSurfaceVelocityUtil::contactPointCallback(hkpSurfaceVelocityUtil *this, hkpContactPointEvent *event)
{
  hkpAddModifierUtil::setSurfaceVelocity(event, (hkpRigidBody *)this->vfptr, (hkVector4f *)&this->m_rigidBody);
}

// File Line: 36
// RVA: 0xE11380
void __fastcall hkpSurfaceVelocityUtil::~hkpSurfaceVelocityUtil(hkpSurfaceVelocityUtil *this)
{
  hkpSurfaceVelocityUtil *v1; // rbx
  hkpRigidBody *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpContactListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpContactListener};
  this->vfptr = (hkpEntityListenerVtbl *)&hkpSurfaceVelocityUtil::`vftable{for `hkpEntityListener};
  v2 = this->m_rigidBody;
  if ( v2 )
  {
    hkpEntity::removeContactListener((hkpEntity *)&v2->vfptr, (hkpContactListener *)&v1->vfptr);
    hkpEntity::removeEntityListener((hkpEntity *)&v1->m_rigidBody->vfptr, (hkpEntityListener *)&v1->vfptr);
  }
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  v1->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 45
// RVA: 0xE11500
void __fastcall hkpSurfaceVelocityUtil::entityDeletedCallback(hkpSurfaceVelocityUtil *this, hkpEntity *entity)
{
  hkReferencedObject *v2; // rdi
  hkpEntity *v3; // rsi
  hkpSurfaceVelocityUtil *v4; // rbx
  hkpContactListener *v5; // rdx
  hkpEntityListener *v6; // rdx

  v2 = (hkReferencedObject *)(&this[-1].m_rigidBody + 1);
  v3 = entity;
  v4 = this;
  if ( this == (hkpSurfaceVelocityUtil *)24 )
    v5 = 0i64;
  else
    v5 = (hkpContactListener *)&this[-1].m_surfaceVelocity.m_quad.m128_u16[4];
  hkpEntity::removeContactListener(v3, v5);
  v6 = 0i64;
  if ( v2 )
    v6 = (hkpEntityListener *)v4;
  hkpEntity::removeEntityListener(v3, v6);
  *(_QWORD *)&v4->m_memSizeAndFlags = 0i64;
  hkReferencedObject::removeReference(v2);
}

// File Line: 54
// RVA: 0xE11410
void __fastcall hkpSurfaceVelocityUtil::setSurfaceVelocity(hkpSurfaceVelocityUtil *this, hkVector4f *velWorld)
{
  hkpSurfaceVelocityUtil *v2; // rbp
  hkpRigidBody *v3; // rsi
  int v4; // ebx
  __int64 v5; // rdi
  hkpDynamicsContactMgr *v6; // r14
  hkpConstraintInstance *v7; // rax
  hkpSimulationIsland *v8; // rax

  v2 = this;
  if ( (_mm_movemask_ps(_mm_cmpeqps(velWorld->m_quad, this->m_surfaceVelocity.m_quad)) & 7) != 7 )
  {
    v3 = this->m_rigidBody;
    this->m_surfaceVelocity = (hkVector4f)velWorld->m_quad;
    v4 = 0;
    if ( v3->m_collidable.m_collisionEntries.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        v6 = (hkpDynamicsContactMgr *)v3->m_collidable.m_collisionEntries.m_data[v5].m_agentEntry->m_contactMgr;
        v7 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *))v6->vfptr[8].__vecDelDtor)(v6);
        if ( v7 )
        {
          if ( v7->m_internal )
          {
            v8 = hkpConstraintInstance::getSimulationIsland(v7);
            hkpResponseModifier::setSurfaceVelocity(
              v6,
              v2->m_rigidBody,
              (hkpConstraintOwner *)&v8->vfptr,
              &v2->m_surfaceVelocity);
          }
        }
        ++v4;
        ++v5;
      }
      while ( v4 < v3->m_collidable.m_collisionEntries.m_size );
    }
  }
}

