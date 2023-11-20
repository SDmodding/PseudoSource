// File Line: 46
// RVA: 0x149EE70
__int64 dynamic_initializer_for__symSensorComponent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-Sensor", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSensorComponent, v0);
  return atexit(dynamic_atexit_destructor_for__symSensorComponent__);
}

// File Line: 54
// RVA: 0x2EE780
void __fastcall GravityTask::Begin(GravityTask *this, ActionContext *context)
{
  GravityTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rax
  float v8; // xmm1_4
  bool v9; // dl

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      v8 = *(float *)&v7[1].vfptr;
      v9 = BYTE4(v7[1].vfptr) != 0;
      *(float *)&v5[9].m_SafePointerList.mNode.mPrev = v8;
      if ( v8 == 0.0 )
        v5[9].m_NameUID |= 1u;
      else
        v5[9].m_NameUID &= 0xFFFFFFFE;
      v5[9].m_NameUID &= 0xFFFFFFEF;
      v5[9].m_NameUID |= 16 * (v9 != 0);
    }
  }
}

// File Line: 83
// RVA: 0x2EDCD0
void __fastcall DisableCollisionTask::Begin(DisableCollisionTask *this, ActionContext *pContext)
{
  UFG::SimObject *v2; // rax
  UFG::RigidBody *i; // rbx

  v2 = pContext->mSimObject.m_pPointer;
  this->m_pSimObject = v2;
  for ( i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v2, UFG::RigidBodyComponent::_TypeUID);
        i;
        i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                i->m_pSimObject,
                                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                0,
                                (UFG::SimComponent *)&i->vfptr) )
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
                                         (UFG::SimComponent *)&i->vfptr) )
  {
    UFG::RigidBodyComponent::RestoreCollisionFilter(i);
  }
}

// File Line: 116
// RVA: 0x2F1E70
void __fastcall PhysicsMotionTypeTask::Begin(PhysicsMotionTypeTask *this, ActionContext *context)
{
  PhysicsMotionTypeTask *v2; // rsi
  UFG::RigidBody *i; // rbx
  ITrack *v4; // rdi
  unsigned int v5; // edx
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v2 = this;
  for ( i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                context->mSimObject.m_pPointer,
                                UFG::RigidBodyComponent::_TypeUID);
        i;
        i = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                i->m_pSimObject,
                                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                0,
                                (UFG::SimComponent *)&i->vfptr) )
  {
    v4 = v2->m_Track;
    PhysicsMotionTypeTrack::GetCollisionGeoNameSymbol((PhysicsMotionTypeTrack *)v2->m_Track, &result);
    if ( result.mUID == -1 || result.mUID == i->mCollisionMeshData->mNode.mUID )
    {
      v5 = 128;
      if ( LOBYTE(v4[1].vfptr) )
        v5 = 256;
      UFG::RigidBody::SetMotionType(i, v5);
    }
  }
}

// File Line: 145
// RVA: 0x2EA840
void __fastcall CharacterPhysicsTask::Begin(CharacterPhysicsTask *this, ActionContext *context)
{
  CharacterPhysicsTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterPhysicsComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v5 = (UFG::CharacterPhysicsComponent *)v6;
    }
    if ( v5 )
      UFG::CharacterPhysicsComponent::SetCollisionModel(v5, (UFG::CharacterCollisionMode)v2->m_Track[1].vfptr);
  }
}

// File Line: 168
// RVA: 0x2EA7B0
void __fastcall CharacterPhysicsSuperMassiveTask::Begin(CharacterPhysicsSuperMassiveTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::CharacterPhysicsComponent *v4; // rax

  this->mContext = context;
  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterPhysicsComponent *)v2->m_Components.p[27].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v4 )
      UFG::CharacterPhysicsComponent::SetSuperMassive(v4);
  }
}

// File Line: 184
// RVA: 0x2FE410
void __fastcall CharacterPhysicsSuperMassiveTask::End(CharacterPhysicsSuperMassiveTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::CharacterPhysicsComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::CharacterPhysicsComponent *)v1->m_Components.p[27].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v1,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v1,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v1->vfptr,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v1,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v3 )
      UFG::CharacterPhysicsComponent::ClearSuperMassive(v3);
  }
}

// File Line: 199
// RVA: 0x2ED6A0
void __fastcall DetailedOnGroundTask::Begin(DetailedOnGroundTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::CharacterPhysicsComponent *v4; // rax

  this->mContext = context;
  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterPhysicsComponent *)v2->m_Components.p[27].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v4 )
      UFG::CharacterPhysicsComponent::EnableDetailedOnGroundCheck(v4);
  }
}

// File Line: 210
// RVA: 0x2FEAA0
void __fastcall DetailedOnGroundTask::End(DetailedOnGroundTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::CharacterPhysicsComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::CharacterPhysicsComponent *)v1->m_Components.p[27].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v1,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v1,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v1->vfptr,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v1,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v3 )
      UFG::CharacterPhysicsComponent::DisableDetailedOnGroundCheck(v3);
  }
}

// File Line: 222
// RVA: 0x2FD290
void __fastcall VelocitySlopeModeTask::Begin(VelocitySlopeModeTask *this, ActionContext *context)
{
  VelocitySlopeModeTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool v7; // cl

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = LOBYTE(v2->m_Track[1].vfptr) != 0;
      v5[9].m_NameUID &= 0xFFFFFF9F;
      v5[9].m_NameUID = (v5[9].m_NameUID | (v7 << 6)) & 0xFFFFFFF7 | 8 * (v7 | 4 * v7);
    }
  }
}

// File Line: 238
// RVA: 0x2F4480
void __fastcall SlopeLocomotionFixupTask::Begin(SlopeLocomotionFixupTask *this, ActionContext *context)
{
  SlopeLocomotionFixupTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *v6; // rcx
  float v7; // xmm0_4
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    if ( v5 )
    {
      v6 = v5->mCreature;
      if ( v6 )
      {
        v7 = *(float *)&v2->m_Track[1].vfptr;
        v6->mIsSlopeLocomotionFixupEnabled = 1;
        v6->mMaxSlopeLocomotionFixupAngle = v7;
      }
    }
    v8 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v10 = v8->m_Components.p[27].m_pComponent;
      }
      else if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v9 >> 12) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v8->vfptr,
                  UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      if ( v10 )
        v10[9].m_NameUID |= 8u;
    }
  }
}

// File Line: 262
// RVA: 0x300270
void __fastcall SlopeLocomotionFixupTask::End(SlopeLocomotionFixupTask *this)
{
  SlopeLocomotionFixupTask *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterAnimationComponent *v4; // rax
  Creature *v5; // rcx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax

  v1 = this;
  if ( BYTE4(this->m_Track[1].vfptr) )
  {
    v2 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v2);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v2->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v4 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v2->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
      }
      if ( v4 )
      {
        v5 = v4->mCreature;
        if ( v5 )
          v5->mIsSlopeLocomotionFixupEnabled = 0;
      }
      v6 = (UFG::SimObjectGame *)v1->mContext->mSimObject.m_pPointer;
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = v6->m_Components.p[27].m_pComponent;
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else
          {
            v8 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v6->vfptr,
                   UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        if ( v8 )
          v8[9].m_NameUID &= 0xFFFFFFF7;
      }
    }
  }
}

// File Line: 291
// RVA: 0x2EE0C0
void __fastcall ExplosionTask::Begin(ExplosionTask *this, ActionContext *pContext)
{
  UFG::SimObject *v2; // rbx
  ActionContext *v3; // rdi
  ExplosionTask *v4; // rbp
  UFG::TransformNodeComponent *v5; // rbx
  ITrack *v6; // rax
  const char *v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm0_4
  UFG::SimObjectProp *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::CharacterAnimationComponent *v12; // rax
  Creature *v13; // rbx
  int v14; // eax
  UFG::qSymbol *v15; // rax
  UFG::qVector3 pos; // [rsp+30h] [rbp-58h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-48h]
  UFG::qSymbol result; // [rsp+98h] [rbp+10h]

  v2 = pContext->mSimObject.m_pPointer;
  v3 = pContext;
  v4 = this;
  if ( v2 )
  {
    v5 = v2->m_pTransformNodeComponent;
    if ( v5 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      v6 = v4->m_Track;
      v7 = 0i64;
      v8 = v5->mWorldTransform.v3.y;
      pos.x = v5->mWorldTransform.v3.x;
      v9 = v5->mWorldTransform.v3.z;
      pos.y = v8;
      pos.z = v9;
      if ( LODWORD(v6[1].vfptr) != -1 )
      {
        v10 = (UFG::SimObjectProp *)v3->mSimObject.m_pPointer;
        if ( v10
          && ((v11 = v10->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v12 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v12 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v10))) : (v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v10))) : (v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v10)),
              v12) )
        {
          v13 = v12->mCreature;
        }
        else
        {
          v13 = 0i64;
        }
        if ( v13 )
        {
          if ( v13->mPose.mRigHandle.mData )
          {
            v14 = Skeleton::GetBoneID(v13->mPose.mRigHandle.mUFGSkeleton, (const unsigned int)v4->m_Track[1].vfptr);
            if ( v14 >= 0 )
            {
              Creature::GetTransform(v13, v14, &transform);
              pos = *(UFG::qVector3 *)&transform.v3.x;
            }
          }
        }
      }
      if ( (gExplosionTypeEnum.m_enumLists.size & 0x80000000) == 0 )
        v7 = (*gExplosionTypeEnum.m_enumLists.p)->m_enumName.p[HIDWORD(v4->m_Track[1].vfptr)];
      v15 = UFG::qSymbol::create_from_string(&result, v7);
      UFG::ExplosionManager::CreateExplosion(&pos, v15, 0i64, 0i64);
    }
  }
}

// File Line: 330
// RVA: 0x2F1DB0
void __fastcall PhysicalDamageTask::Begin(PhysicalDamageTask *this, ActionContext *pContext)
{
  PhysicalDamageTask *v2; // rax
  UFG::SimObject *v3; // rcx
  float *v4; // rax
  int v5; // ebx
  UFG::StateMachineComponent::DamageType v6; // esi
  float v7; // xmm6_4
  UFG::TransformNodeComponent *i; // rdi
  UFG::StateMachineComponent *v9; // rcx

  v2 = this;
  v3 = pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = (float *)v2->m_Track;
    v5 = *((_DWORD *)v4 + 16);
    v6 = *((_DWORD *)v4 + 14);
    v7 = v4[15];
    for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::RigidBodyComponent::_TypeUID);
          i;
          i = UFG::SimObject::GetComponentOfType(
                i->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&i->vfptr) )
    {
      if ( v5 == -1 || v5 == *(_DWORD *)(*(_QWORD *)&i->mWorldTransform.v2.x + 24i64) )
      {
        v9 = *(UFG::StateMachineComponent **)&i[1].mChanged;
        if ( v9 )
          UFG::StateMachineComponent::ApplyDamage(v9, v7, v6, 0i64);
      }
    }
  }
}

// File Line: 357
// RVA: 0x2F3400
void __fastcall SensorComponentTask::Begin(SensorComponentTask *this, ActionContext *context)
{
  SensorComponentTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qPropertySet *v6; // rax
  char *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rdi
  UFG::SimObject *v11; // rdx
  unsigned __int16 v12; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3
    || ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SensorComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SensorComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SensorComponent::_TypeUID))) : (v5 = v3->m_Components.p[26].m_pComponent)) : (v5 = v3->m_Components.p[26].m_pComponent),
        !v5) )
  {
    v2->mAddedSensorComponent = 1;
    v6 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&symSensorComponent.mUID);
    v7 = UFG::qPropertySet::GetMemImagePtr(v6);
    v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "SensorComponentTask", 0i64, 1u);
    if ( v8 )
    {
      UFG::SensorComponent::SensorComponent((UFG::SensorComponent *)v8, symSensorComponent.mUID, (component_Sensor *)v7);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = v2->mContext->mSimObject.m_pPointer;
    v12 = v11->m_Flags;
    if ( (v12 >> 14) & 1 || (v12 & 0x8000u) != 0 )
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
  SensorComponentTask *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectModifier v6; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( this->mAddedSensorComponent )
  {
    v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[26].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SensorComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SensorComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::SensorComponent::_TypeUID);
        }
        v4 = v5;
      }
      else
      {
        v4 = v2->m_Components.p[26].m_pComponent;
      }
      if ( v4 )
      {
        UFG::SimObjectModifier::SimObjectModifier(&v6, v1->mContext->mSimObject.m_pPointer, 1);
        ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v6);
        UFG::SimObjectModifier::Close(&v6);
        UFG::SimObjectModifier::~SimObjectModifier(&v6);
        UFG::Simulation::DestroySimComponent(&UFG::gSim, v4);
      }
    }
  }
}

// File Line: 392
// RVA: 0x2F1530
void __fastcall PairedGrappleTask::Begin(PairedGrappleTask *this, ActionContext *context)
{
  PairedGrappleTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::CharacterPhysicsComponent::GrappleMode v15; // esi
  UFG::SimObjectGame *v16; // rcx
  UFG::CharacterPhysicsComponent *v17; // rbx
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  UFG::CharacterPhysicsComponent *v20; // rdx

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 31i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = v7->m_Components.p[27].m_pComponent;
        }
        else
        {
          if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
            }
            else if ( (v8 >> 12) & 1 )
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
            }
            else
            {
              v10 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v7->vfptr,
                      UFG::CharacterPhysicsComponent::_TypeUID);
            }
          }
          else
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          v9 = v10;
        }
        v11 = &v2->mSlave;
        if ( v2->mSlave.m_pPointer )
        {
          v12 = v11->mPrev;
          v13 = v2->mSlave.mNext;
          v12->mNext = v13;
          v13->mPrev = v12;
          v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
          v2->mSlave.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mSlave.mPrev;
        }
        v2->mSlave.m_pPointer = v9;
        if ( v9 )
        {
          v14 = v9->m_SafePointerList.mNode.mPrev;
          v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
          v11->mPrev = v14;
          v2->mSlave.mNext = &v9->m_SafePointerList.mNode;
          v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
        }
        v15 = 0;
        v16 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
        if ( v16 )
        {
          v18 = v16->m_Flags;
          if ( (v18 >> 14) & 1 )
          {
            v17 = (UFG::CharacterPhysicsComponent *)v16->m_Components.p[27].m_pComponent;
          }
          else
          {
            if ( (v18 & 0x8000u) == 0 )
            {
              if ( (v18 >> 13) & 1 )
              {
                v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::CharacterPhysicsComponent::_TypeUID);
              }
              else if ( (v18 >> 12) & 1 )
              {
                v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::CharacterPhysicsComponent::_TypeUID);
              }
              else
              {
                v19 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v16->vfptr,
                        UFG::CharacterPhysicsComponent::_TypeUID);
              }
            }
            else
            {
              v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::CharacterPhysicsComponent::_TypeUID);
            }
            v17 = (UFG::CharacterPhysicsComponent *)v19;
          }
        }
        else
        {
          v17 = 0i64;
        }
        v20 = (UFG::CharacterPhysicsComponent *)v2->mSlave.m_pPointer;
        if ( v20 )
        {
          LOBYTE(v15) = LOBYTE(v2->m_Track[1].vfptr) != 0;
          UFG::CharacterPhysicsComponent::SetPairedGrappleMaster(v17, v20, v15);
          UFG::CharacterPhysicsComponent::SetPairedGrappleSlave(
            (UFG::CharacterPhysicsComponent *)v2->mSlave.m_pPointer,
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
  PairedGrappleTask *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  UFG::CharacterPhysicsComponent *v6; // rcx
  UFG::SimComponent *v7; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v4 = v5;
    }
    if ( v4 )
    {
      UFG::CharacterPhysicsComponent::ClearPairedGrapple((UFG::CharacterPhysicsComponent *)v4);
      *(_QWORD *)&v4[6].m_Flags = 0i64;
      LODWORD(v4[6].m_pSimObject) = 0;
    }
  }
  v6 = (UFG::CharacterPhysicsComponent *)v1->mSlave.m_pPointer;
  if ( v6 )
  {
    UFG::CharacterPhysicsComponent::ClearPairedGrapple(v6);
    v7 = v1->mSlave.m_pPointer;
    *(_QWORD *)&v7[6].m_Flags = 0i64;
    LODWORD(v7[6].m_pSimObject) = 0;
  }
}

// File Line: 445
// RVA: 0x2EAC40
void __fastcall CollisionDisableAgainstTargetTask::Begin(CollisionDisableAgainstTargetTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  int v3; // ebp
  __int64 v4; // rbx
  CollisionDisableAgainstTargetTask *v5; // r15
  UFG::SimObjectGame *v6; // rcx
  ActionContext *v7; // rsi
  unsigned __int16 v8; // r8
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *v10; // rax
  UFG::SimObjectGame *v11; // rbx
  unsigned __int16 v12; // cx
  UFG::CustomCollisionFilter *v13; // r14
  UFG::PhysicsMoverInterface *v14; // rax
  hkpEntity *v15; // rdi
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  UFG::SimObjectGame *v18; // rcx
  unsigned __int16 v19; // dx
  UFG::RagdollComponent *v20; // rax
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *v21; // rsi
  __int64 v22; // rbx
  UFG::SimObjectGame *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::SimComponent *v25; // rax
  hkpEntity *v26; // rdx

  v2 = this->m_Track;
  v3 = 0;
  this->mContext = context;
  this->mDisabledTarget = 0i64;
  v4 = LODWORD(v2[1].vfptr);
  v5 = this;
  v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v7 = context;
  if ( !v6 )
    return;
  v8 = v6->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = v6->m_Components.p[20].m_pComponent;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v9 = v10;
  }
  else
  {
    v9 = v6->m_Components.p[20].m_pComponent;
  }
  if ( !v9 )
    return;
  v11 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v9[1].m_Flags + v4 + 8)
                               + *(_QWORD *)&v9[1].m_TypeUID
                               + 40);
  if ( !v11 )
    return;
  v12 = v11->m_Flags;
  v13 = UFG::BasePhysicsSystem::mInstance->mCollisionFilter;
  if ( (v12 >> 14) & 1 )
    goto LABEL_23;
  if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
    {
LABEL_23:
      v16 = v11->m_Flags;
      if ( (v16 >> 14) & 1 )
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v16 & 0x8000u) == 0 )
      {
        if ( (v16 >> 13) & 1 )
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v16 >> 12) & 1 )
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
      }
      else
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
      }
      v15 = (hkpEntity *)v17[2].m_pSimObject;
      goto LABEL_33;
    }
    if ( (v12 >> 12) & 1 )
      v14 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v11,
                                            UFG::PhysicsMoverInterface::_TypeUID);
    else
      v14 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v11->vfptr,
                                            UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v14 = (UFG::PhysicsMoverInterface *)v11->m_Components.p[34].m_pComponent;
  }
  if ( !v14 )
    goto LABEL_23;
  v15 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(v14);
LABEL_33:
  if ( !v15 )
    return;
  v18 = (UFG::SimObjectGame *)v7->mSimObject.m_pPointer;
  if ( v18 )
  {
    v19 = v18->m_Flags;
    if ( (v19 >> 14) & 1 )
    {
      v20 = (UFG::RagdollComponent *)v18->m_Components.p[42].m_pComponent;
    }
    else if ( (v19 & 0x8000u) == 0 )
    {
      if ( (v19 >> 13) & 1 )
        v20 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID);
      else
        v20 = (UFG::RagdollComponent *)((v19 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v18,
                                                            UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v18->vfptr,
                                                                                                 UFG::RagdollComponent::_TypeUID));
    }
    else
    {
      v20 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID);
    }
    if ( v20 )
    {
      v21 = UFG::RagdollComponent::GetRigidBodies(v20);
      if ( v21->m_size > 0 )
      {
        v22 = 0i64;
        do
        {
          UFG::CustomCollisionFilter::DisableCollisionsBetween(v13, (hkpEntity *)&v21->m_data[v22]->vfptr, v15);
          ++v3;
          ++v22;
        }
        while ( v3 < v21->m_size );
      }
      goto LABEL_62;
    }
  }
  v23 = (UFG::SimObjectGame *)v7->mSimObject.m_pPointer;
  if ( v23 )
  {
    v24 = v23->m_Flags;
    if ( (v24 >> 14) & 1 )
    {
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v24 & 0x8000u) == 0 )
    {
      if ( (v24 >> 13) & 1 )
        v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::RigidBodyComponent::_TypeUID);
      else
        v25 = (v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v25 )
    {
      v26 = (hkpEntity *)v25[2].m_pSimObject;
      if ( v26 )
      {
        UFG::CustomCollisionFilter::DisableCollisionsBetween(v13, v26, v15);
LABEL_62:
        v5->mDisabledTarget = (hkpRigidBody *)v15;
        return;
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
    (hkpEntity *)&this->mDisabledTarget->vfptr);
}

