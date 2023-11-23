// File Line: 46
// RVA: 0x149EE70
__int64 dynamic_initializer_for__symSensorComponent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-Sensor", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSensorComponent, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symSensorComponent__);
}

// File Line: 54
// RVA: 0x2EE780
void __fastcall GravityTask::Begin(GravityTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rax
  float v8; // xmm1_4
  bool v9; // dl

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      v8 = *(float *)&m_Track[1].vfptr;
      v9 = BYTE4(m_Track[1].vfptr) != 0;
      *(float *)&m_pComponent[9].m_SafePointerList.mNode.mPrev = v8;
      if ( v8 == 0.0 )
        m_pComponent[9].m_NameUID |= 1u;
      else
        m_pComponent[9].m_NameUID &= ~1u;
      m_pComponent[9].m_NameUID &= ~0x10u;
      m_pComponent[9].m_NameUID |= 16 * v9;
    }
  }
}

// File Line: 83
// RVA: 0x2EDCD0
void __fastcall DisableCollisionTask::Begin(DisableCollisionTask *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::RigidBody *i; // rbx

  m_pPointer = pContext->mSimObject.m_pPointer;
  this->m_pSimObject = m_pPointer;
  for ( i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
        i;
        i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                i->m_pSimObject,
                                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                0,
                                i) )
  {
    _((AMD_HD3D *)i);
    UFG::RigidBody::SetCollisionLayer(i, 0x15u, -1, -1, -1);
  }
}

// File Line: 100
// RVA: 0x2FEB30
void __fastcall DisableCollisionTask::End(DisableCollisionTask *this)
{
  UFG::RigidBodyComponent *i; // rbx

  for ( i = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                         this->m_pSimObject,
                                         UFG::RigidBodyComponent::_TypeUID);
        i;
        i = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                         i->m_pSimObject,
                                         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                         0,
                                         i) )
  {
    UFG::RigidBodyComponent::RestoreCollisionFilter(i);
  }
}

// File Line: 116
// RVA: 0x2F1E70
void __fastcall PhysicsMotionTypeTask::Begin(PhysicsMotionTypeTask *this, ActionContext *context)
{
  UFG::RigidBody *i; // rbx
  PhysicsMotionTypeTrack *m_Track; // rdi
  unsigned int v5; // edx
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  for ( i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                context->mSimObject.m_pPointer,
                                UFG::RigidBodyComponent::_TypeUID);
        i;
        i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                i->m_pSimObject,
                                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                0,
                                i) )
  {
    m_Track = (PhysicsMotionTypeTrack *)this->m_Track;
    PhysicsMotionTypeTrack::GetCollisionGeoNameSymbol(m_Track, &result);
    if ( result.mUID == -1 || result.mUID == i->mCollisionMeshData->mNode.mUID )
    {
      v5 = 128;
      if ( m_Track->mMode.mValue )
        v5 = 256;
      UFG::RigidBody::SetMotionType(i, v5);
    }
  }
}

// File Line: 145
// RVA: 0x2EA840
void __fastcall CharacterPhysicsTask::Begin(CharacterPhysicsTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = (UFG::CharacterPhysicsComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      UFG::CharacterPhysicsComponent::SetCollisionModel(
        m_pComponent,
        (UFG::CharacterCollisionMode)this->m_Track[1].vfptr);
  }
}

// File Line: 168
// RVA: 0x2EA7B0
void __fastcall CharacterPhysicsSuperMassiveTask::Begin(CharacterPhysicsSuperMassiveTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::CharacterPhysicsComponent::SetSuperMassive(m_pComponent);
  }
}

// File Line: 184
// RVA: 0x2FE410
void __fastcall CharacterPhysicsSuperMassiveTask::End(CharacterPhysicsSuperMassiveTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::CharacterPhysicsComponent::ClearSuperMassive(m_pComponent);
  }
}

// File Line: 199
// RVA: 0x2ED6A0
void __fastcall DetailedOnGroundTask::Begin(DetailedOnGroundTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::CharacterPhysicsComponent::EnableDetailedOnGroundCheck(m_pComponent);
  }
}

// File Line: 210
// RVA: 0x2FEAA0
void __fastcall DetailedOnGroundTask::End(DetailedOnGroundTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::CharacterPhysicsComponent::DisableDetailedOnGroundCheck(m_pComponent);
  }
}

// File Line: 222
// RVA: 0x2FD290
void __fastcall VelocitySlopeModeTask::Begin(VelocitySlopeModeTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v7; // cl

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      v7 = LOBYTE(this->m_Track[1].vfptr) != 0;
      m_pComponent[9].m_NameUID &= 0xFFFFFF9F;
      m_pComponent[9].m_NameUID = m_pComponent[9].m_NameUID & 0xFFFFFFF7 | (v7 << 6) | (8 * (v7 | (4 * v7)));
    }
  }
}

// File Line: 238
// RVA: 0x2F4480
void __fastcall SlopeLocomotionFixupTask::Begin(SlopeLocomotionFixupTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  float v7; // xmm0_4
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *m_pComponent; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
    {
      mCreature = ComponentOfTypeHK->mCreature;
      if ( mCreature )
      {
        v7 = *(float *)&this->m_Track[1].vfptr;
        mCreature->mIsSlopeLocomotionFixupEnabled = 1;
        mCreature->mMaxSlopeLocomotionFixupAngle = v7;
      }
    }
    v8 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 & 0x4000) != 0 )
      {
        m_pComponent = v8->m_Components.p[27].m_pComponent;
      }
      else if ( v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v8, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      if ( m_pComponent )
        m_pComponent[9].m_NameUID |= 8u;
    }
  }
}

// File Line: 262
// RVA: 0x300270
void __fastcall SlopeLocomotionFixupTask::End(SlopeLocomotionFixupTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::SimComponent *m_pComponent; // rax

  if ( BYTE4(this->m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
      {
        mCreature = ComponentOfTypeHK->mCreature;
        if ( mCreature )
          mCreature->mIsSlopeLocomotionFixupEnabled = 0;
      }
      v6 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 & 0x4000) != 0 )
        {
          m_pComponent = v6->m_Components.p[27].m_pComponent;
        }
        else if ( v7 < 0 || (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(v6, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        if ( m_pComponent )
          m_pComponent[9].m_NameUID &= ~8u;
      }
    }
  }
}

// File Line: 291
// RVA: 0x2EE0C0
void __fastcall ExplosionTask::Begin(ExplosionTask *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  ITrack *m_Track; // rax
  const char *v7; // rsi
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimObjectCVBase *v10; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::qSymbol *v15; // rax
  UFG::qVector3 pos; // [rsp+30h] [rbp-58h] BYREF
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-48h] BYREF
  UFG::qSymbol result; // [rsp+98h] [rbp+10h] BYREF

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      m_Track = this->m_Track;
      v7 = 0i64;
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      pos.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      pos.y = y;
      pos.z = z;
      if ( LODWORD(m_Track[1].vfptr) != -1 )
      {
        v10 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
        if ( v10
          && ((m_Flags = v10->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
            ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10))
            : (m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                        v10,
                                                                        UFG::CharacterAnimationComponent::_TypeUID))
             : (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v10,
                                                                        UFG::CharacterAnimationComponent::_TypeUID)))
            : (ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10)),
              ComponentOfType) )
        {
          mCreature = ComponentOfType->mCreature;
        }
        else
        {
          mCreature = 0i64;
        }
        if ( mCreature )
        {
          if ( mCreature->mPose.mRigHandle.mData )
          {
            BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, (unsigned int)this->m_Track[1].vfptr);
            if ( BoneID >= 0 )
            {
              Creature::GetTransform(mCreature, BoneID, &transform);
              pos.x = transform.v3.x;
              pos.y = transform.v3.y;
              pos.z = transform.v3.z;
            }
          }
        }
      }
      if ( (gExplosionTypeEnum.m_enumLists.size & 0x80000000) == 0 )
        v7 = (*gExplosionTypeEnum.m_enumLists.p)->m_enumName.p[HIDWORD(this->m_Track[1].vfptr)];
      v15 = UFG::qSymbol::create_from_string(&result, v7);
      UFG::ExplosionManager::CreateExplosion(&pos, v15, 0i64, 0i64);
    }
  }
}

// File Line: 330
// RVA: 0x2F1DB0
void __fastcall PhysicalDamageTask::Begin(PhysicalDamageTask *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rcx
  ITrack *m_Track; // rax
  int mResourceOwner; // ebx
  UFG::StateMachineComponent::DamageType vfptr; // esi
  float v7; // xmm6_4
  UFG::TransformNodeComponent *i; // rdi
  UFG::StateMachineComponent *v9; // rcx

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Track = this->m_Track;
    mResourceOwner = (int)m_Track[1].mResourceOwner;
    vfptr = (UFG::StateMachineComponent::DamageType)m_Track[1].vfptr;
    v7 = *((float *)&m_Track[1].vfptr + 1);
    for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                               m_pPointer,
                                               UFG::RigidBodyComponent::_TypeUID);
          i;
          i = UFG::SimObject::GetComponentOfType(
                i->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                i) )
    {
      if ( mResourceOwner == -1 || mResourceOwner == *(_DWORD *)(*(_QWORD *)&i->mWorldTransform.v2.x + 24i64) )
      {
        v9 = *(UFG::StateMachineComponent **)&i[1].mChanged;
        if ( v9 )
          UFG::StateMachineComponent::ApplyDamage(v9, v7, vfptr, 0i64);
      }
    }
  }
}

// File Line: 357
// RVA: 0x2F3400
void __fastcall SensorComponentTask::Begin(SensorComponentTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v4; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qPropertySet *PropertySet; // rax
  char *MemImagePtr; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rdi
  UFG::SimObject *v11; // rdx
  __int16 m_Flags; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h] BYREF

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer
    || ((v4 = m_pPointer->m_Flags, (v4 & 0x4000) == 0)
      ? (v4 >= 0
       ? ((v4 & 0x2000) != 0 || (v4 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SensorComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SensorComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[26].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[26].m_pComponent),
        !ComponentOfTypeHK) )
  {
    this->mAddedSensorComponent = 1;
    PropertySet = UFG::PropertySetManager::FindPropertySet(&symSensorComponent);
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(PropertySet);
    v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "SensorComponentTask", 0i64, 1u);
    if ( v8 )
    {
      UFG::SensorComponent::SensorComponent(
        (UFG::SensorComponent *)v8,
        symSensorComponent.mUID,
        (component_Sensor *)MemImagePtr);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = this->mContext->mSimObject.m_pPointer;
    m_Flags = v11->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v13 = 26;
    else
      v13 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v14, v11, 1);
    UFG::SimObjectModifier::AttachComponent(&v14, v10, v13);
    UFG::SimObjectModifier::Close(&v14);
    UFG::SimObjectModifier::~SimObjectModifier(&v14);
  }
}

// File Line: 375
// RVA: 0x300120
void __fastcall SensorComponentTask::End(SensorComponentTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ArrayOfTuplesImplementation v6; // [rsp+28h] [rbp-30h] BYREF

  if ( this->mAddedSensorComponent )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[26].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SensorComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SensorComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[26].m_pComponent;
      }
      if ( m_pComponent )
      {
        UFG::SimObjectModifier::SimObjectModifier(
          (UFG::SimObjectModifier *)&v6,
          this->mContext->mSimObject.m_pPointer,
          1);
        ArrayOfTuplesImplementation::clear(&v6);
        UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&v6);
        UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&v6);
        UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
      }
    }
  }
}

// File Line: 392
// RVA: 0x2F1530
void __fastcall PairedGrappleTask::Begin(PairedGrappleTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *p_mSlave; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::CharacterPhysicsComponent::GrappleMode v15; // esi
  UFG::SimObjectGame *v16; // rcx
  UFG::CharacterPhysicsComponent *v17; // rbx
  __int16 v18; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::CharacterPhysicsComponent *v20; // rdx

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v9 = v7->m_Components.p[27].m_pComponent;
        }
        else
        {
          if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::CharacterPhysicsComponent::_TypeUID);
          v9 = ComponentOfTypeHK;
        }
        p_mSlave = &this->mSlave;
        if ( this->mSlave.m_pPointer )
        {
          mPrev = p_mSlave->mPrev;
          mNext = this->mSlave.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mSlave->mPrev = p_mSlave;
          this->mSlave.mNext = &this->mSlave;
        }
        this->mSlave.m_pPointer = v9;
        if ( v9 )
        {
          v14 = v9->m_SafePointerList.mNode.mPrev;
          v14->mNext = p_mSlave;
          p_mSlave->mPrev = v14;
          this->mSlave.mNext = &v9->m_SafePointerList.mNode;
          v9->m_SafePointerList.mNode.mPrev = p_mSlave;
        }
        v15 = GRAPPLE_REGULAR;
        v16 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
        if ( v16 )
        {
          v18 = v16->m_Flags;
          if ( (v18 & 0x4000) != 0 )
          {
            v17 = (UFG::CharacterPhysicsComponent *)v16->m_Components.p[27].m_pComponent;
          }
          else
          {
            if ( v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
              ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::CharacterPhysicsComponent::_TypeUID);
            else
              ComponentOfType = UFG::SimObject::GetComponentOfType(v16, UFG::CharacterPhysicsComponent::_TypeUID);
            v17 = (UFG::CharacterPhysicsComponent *)ComponentOfType;
          }
        }
        else
        {
          v17 = 0i64;
        }
        v20 = (UFG::CharacterPhysicsComponent *)this->mSlave.m_pPointer;
        if ( v20 )
        {
          LOBYTE(v15) = LOBYTE(this->m_Track[1].vfptr) != 0;
          UFG::CharacterPhysicsComponent::SetPairedGrappleMaster(v17, v20, v15);
          UFG::CharacterPhysicsComponent::SetPairedGrappleSlave(
            (UFG::CharacterPhysicsComponent *)this->mSlave.m_pPointer,
            v17);
        }
      }
    }
  }
}

// File Line: 424
// RVA: 0x2FF730
void __fastcall PairedGrappleTask::End(PairedGrappleTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CharacterPhysicsComponent *v6; // rcx
  UFG::SimComponent *v7; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      UFG::CharacterPhysicsComponent::ClearPairedGrapple((UFG::CharacterPhysicsComponent *)m_pComponent);
      *(_QWORD *)&m_pComponent[6].m_Flags = 0i64;
      LODWORD(m_pComponent[6].m_pSimObject) = 0;
    }
  }
  v6 = (UFG::CharacterPhysicsComponent *)this->mSlave.m_pPointer;
  if ( v6 )
  {
    UFG::CharacterPhysicsComponent::ClearPairedGrapple(v6);
    v7 = this->mSlave.m_pPointer;
    *(_QWORD *)&v7[6].m_Flags = 0i64;
    LODWORD(v7[6].m_pSimObject) = 0;
  }
}

// File Line: 445
// RVA: 0x2EAC40
void __fastcall CollisionDisableAgainstTargetTask::Begin(
        CollisionDisableAgainstTargetTask *this,
        ActionContext *context)
{
  ITrack *m_Track; // rax
  int v3; // ebp
  __int64 vfptr_low; // rbx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v10; // rax
  UFG::SimObjectGame *v11; // rbx
  __int16 v12; // cx
  UFG::CustomCollisionFilter *mCollisionFilter; // r14
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  hkpRigidBody *m_pSimObject; // rdi
  __int16 v16; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v18; // rcx
  __int16 v19; // dx
  UFG::RagdollComponent *v20; // rax
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *RigidBodies; // rsi
  __int64 v22; // rbx
  UFG::SimObjectGame *v23; // rcx
  __int16 v24; // dx
  UFG::SimComponent *v25; // rax
  hkpEntity *v26; // rdx

  m_Track = this->m_Track;
  v3 = 0;
  this->mContext = context;
  this->mDisabledTarget = 0i64;
  vfptr_low = LODWORD(m_Track[1].vfptr);
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v10 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v10;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return;
  v11 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_low + 8)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( !v11 )
    return;
  v12 = v11->m_Flags;
  mCollisionFilter = UFG::BasePhysicsSystem::mInstance->mCollisionFilter;
  if ( (v12 & 0x4000) != 0 )
    goto LABEL_22;
  if ( v12 >= 0 )
  {
    if ( (v12 & 0x2000) != 0 )
      goto LABEL_22;
    if ( (v12 & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v11,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          v11,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)v11->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
  {
LABEL_22:
    v16 = v11->m_Flags;
    if ( (v16 & 0x4000) != 0 || v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::RigidBodyComponent::_TypeUID);
    m_pSimObject = (hkpRigidBody *)ComponentOfType[2].m_pSimObject;
    goto LABEL_30;
  }
  m_pSimObject = (hkpRigidBody *)UFG::PhysicsMoverInterface::GetRigidBody(ComponentOfTypeHK);
LABEL_30:
  if ( !m_pSimObject )
    return;
  v18 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v18 )
  {
    v19 = v18->m_Flags;
    if ( (v19 & 0x4000) != 0 )
      v20 = (UFG::RagdollComponent *)v18->m_Components.p[42].m_pComponent;
    else
      v20 = (UFG::RagdollComponent *)(v19 < 0 || (v19 & 0x2000) != 0 || (v19 & 0x1000) != 0
                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID)
                                    : UFG::SimObject::GetComponentOfType(v18, UFG::RagdollComponent::_TypeUID));
    if ( v20 )
    {
      RigidBodies = UFG::RagdollComponent::GetRigidBodies(v20);
      if ( RigidBodies->m_size > 0 )
      {
        v22 = 0i64;
        do
        {
          UFG::CustomCollisionFilter::DisableCollisionsBetween(mCollisionFilter, RigidBodies->m_data[v22], m_pSimObject);
          ++v3;
          ++v22;
        }
        while ( v3 < RigidBodies->m_size );
      }
      goto LABEL_56;
    }
  }
  v23 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v23 )
  {
    v24 = v23->m_Flags;
    if ( (v24 & 0x4000) != 0 || v24 < 0 || (v24 & 0x2000) != 0 || (v24 & 0x1000) != 0 )
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::RigidBodyComponent::_TypeUID);
    else
      v25 = UFG::SimObject::GetComponentOfType(v23, UFG::RigidBodyComponent::_TypeUID);
    if ( v25 )
    {
      v26 = (hkpEntity *)v25[2].m_pSimObject;
      if ( v26 )
      {
        UFG::CustomCollisionFilter::DisableCollisionsBetween(mCollisionFilter, v26, m_pSimObject);
LABEL_56:
        this->mDisabledTarget = m_pSimObject;
      }
    }
  }
}

// File Line: 525
// RVA: 0x2FE650
void __fastcall CollisionDisableAgainstTargetTask::End(CollisionDisableAgainstTargetTask *this)
{
  UFG::CustomCollisionFilter::ReenableCollisions(
    UFG::BasePhysicsSystem::mInstance->mCollisionFilter,
    this->mDisabledTarget);
}

