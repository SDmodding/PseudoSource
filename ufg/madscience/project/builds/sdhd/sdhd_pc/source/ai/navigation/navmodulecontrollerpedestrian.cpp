// File Line: 58
// RVA: 0x391110
void __fastcall UFG::NavModuleControllerPedestrian::Update(UFG::NavModuleControllerPedestrian *this)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  Intention *p_m_Intention; // rdx
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  float x; // eax
  float z; // xmm1_4
  float m_fLocalSpeed; // xmm2_4
  UFG::NavObject *NavObject; // rax

  if ( UFG::NavComponent::HasPath(this->m_navComponent) && !UFG::NavComponent::ms_bDisableNavigation )
  {
    m_pSimObject = (UFG::SimObjectCVBase *)this->m_navComponent->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pSimObject);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         m_pSimObject,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pSimObject,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      v3 = ComponentOfTypeHK;
    }
    else
    {
      v3 = 0i64;
    }
    p_m_Intention = &v3->m_Intention;
    m_pNavModuleLocal = this->m_navComponent->m_pNavModuleLocal;
    x = m_pNavModuleLocal->m_steerData.m_vClampedDirection.x;
    z = m_pNavModuleLocal->m_steerData.m_vClampedDirection.z;
    m_fLocalSpeed = m_pNavModuleLocal->m_steerData.m_fLocalSpeed;
    p_m_Intention->mMotionIntentionDirection.y = m_pNavModuleLocal->m_steerData.m_vClampedDirection.y;
    p_m_Intention->mMotionIntentionDirection.z = z;
    p_m_Intention->mMotionIntentionDirection.x = x;
    UFG::NavModuleControllerPedestrian::SetIntentionSpeed(this, p_m_Intention, m_fLocalSpeed);
    NavObject = UFG::NavModulePathing::GetNavObject(this->m_navComponent->m_pNavModulePathing);
    if ( NavObject )
      NavObject->vfptr->UpdateControl(NavObject, this->m_navComponent);
  }
}

// File Line: 97
// RVA: 0x382EB0
void __fastcall UFG::NavModuleControllerPedestrian::Reset(UFG::NavModuleControllerPedestrian *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vDirection.x = UFG::qVector3::msZero.x;
  this->m_vDirection.y = y;
  this->m_vDirection.z = z;
  this->m_fSpeed = 0.0;
  this->m_bVaulting = 0;
  this->m_fDebugPlaybackSpeed = -1.0;
}

// File Line: 116
// RVA: 0x386A90
void __fastcall UFG::NavModuleControllerPedestrian::SetIntentionSpeed(
        UFG::NavModuleControllerPedestrian *this,
        Intention *intention,
        float fSpeed)
{
  UFG::SimObjectGame *m_pSimObject; // rbx
  int v6; // esi
  UFG::AIEntityComponent *m_pComponent; // r14
  __int16 m_Flags; // cx
  UFG::AIEntityComponent *ComponentOfTypeHK; // rax
  unsigned __int64 v10; // rax
  float v11; // xmm6_4
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rax
  __int64 m_EnumValue; // r9
  char v15; // cl
  float v16; // xmm1_4
  UFG::CharacterAnimationComponent *m_pSimComponent; // rax
  Creature *mCreature; // rbp
  float v19; // xmm0_4
  char v20; // di
  __int16 v21; // cx
  UFG::CharacterPhysicsComponent *v22; // rbx
  UFG::CharacterPhysicsComponent *v23; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v24; // rcx
  const char *TypeName; // rax
  float v26; // xmm0_4
  UFG::qReflectHandleBase v27; // [rsp+28h] [rbp-60h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_navComponent->m_pSimObject;
  v6 = 0;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::AIEntityComponent *)m_pSimObject->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::AIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pSimObject,
                                                        UFG::AIEntityComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::AIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pSimObject,
                                                        UFG::AIEntityComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::AIEntityComponent *)m_pSimObject->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  ((void (__fastcall *)(UFG::AIEntityComponent *))m_pComponent->vfptr[14].__vecDelDtor)(m_pComponent);
  v10 = intention->mActionRequests.mBits[(__int64)(int)gActionRequest_Walk.m_EnumValue >> 6];
  v11 = 0.0;
  if ( _bittest64((const __int64 *)&v10, gActionRequest_Walk.m_EnumValue & 0x3F) )
  {
LABEL_20:
    v6 = 1;
    intention->mMotionIntentionSpeed = 0.50999999;
    m_EnumValue = gActionRequest_Walk.m_EnumValue;
    v15 = gActionRequest_Walk.m_EnumValue & 0x3F;
    intention->mActionRequests.mBits[(__int64)(int)gActionRequest_Walk.m_EnumValue >> 6] |= 1i64 << (gActionRequest_Walk.m_EnumValue & 0x3F);
    v16 = (float)(int)0.0;
    if ( v16 >= 255.0 )
      v16 = FLOAT_255_0;
    intention->mActionRequestChargeTimes[m_EnumValue] = (int)v16;
    intention->mSignals |= 1i64 << v15;
    goto LABEL_23;
  }
  v12 = intention->mActionRequests.mBits[(__int64)(int)gActionRequest_Jog.m_EnumValue >> 6];
  if ( _bittest64((const __int64 *)&v12, gActionRequest_Jog.m_EnumValue & 0x3F) )
    goto LABEL_19;
  v13 = intention->mActionRequests.mBits[(__int64)(int)gActionRequest_Sprint.m_EnumValue >> 6];
  if ( _bittest64((const __int64 *)&v13, gActionRequest_Sprint.m_EnumValue & 0x3F) )
  {
LABEL_18:
    v6 = 3;
    intention->mMotionIntentionSpeed = 1.6;
    Intention::Set(intention, gActionRequest_Jog.m_EnumValue, 0.0);
    Intention::Set(intention, gActionRequest_Sprint.m_EnumValue, 123.4);
    goto LABEL_23;
  }
  if ( fSpeed > 0.029999999 )
  {
    if ( fSpeed >= 3.0 )
    {
      if ( fSpeed >= 4.8000002 )
        goto LABEL_18;
LABEL_19:
      v6 = 2;
      intention->mMotionIntentionSpeed = 1.0;
      Intention::Set(intention, gActionRequest_Jog.m_EnumValue, 0.0);
      goto LABEL_23;
    }
    goto LABEL_20;
  }
LABEL_23:
  m_pSimComponent = (UFG::CharacterAnimationComponent *)m_pComponent->m_pCharacterAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    mCreature = m_pSimComponent->mCreature;
    if ( mCreature )
    {
      v19 = sNaturalMovementSpeeds[v6];
      if ( v19 > 0.0 )
        v11 = fSpeed / v19;
      v20 = 0;
      if ( !m_pSimObject )
        goto LABEL_45;
      v21 = m_pSimObject->m_Flags;
      if ( (v21 & 0x4000) != 0 )
      {
        v22 = (UFG::CharacterPhysicsComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
      }
      else
      {
        v23 = (UFG::CharacterPhysicsComponent *)(v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pSimObject,
                                                   UFG::CharacterPhysicsComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   m_pSimObject,
                                                   UFG::CharacterPhysicsComponent::_TypeUID));
        v22 = v23;
      }
      if ( !v22 )
        goto LABEL_45;
      UFG::qReflectHandleBase::qReflectHandleBase(&v27);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v24);
      v27.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v27, v27.mTypeUID, v22->mGroundProperties.groundSurfaceHandleUid);
      if ( v27.mData )
        v20 = BYTE4(v27.mData[1].mBaseNode.mParent);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v27);
      if ( v20 )
      {
        if ( v11 <= 0.89999998 )
        {
          v11 = FLOAT_0_89999998;
        }
        else
        {
          v26 = FLOAT_1_1;
          if ( v11 >= 1.1 )
            goto LABEL_50;
        }
      }
      else
      {
LABEL_45:
        if ( v11 <= 0.5 )
        {
          v11 = FLOAT_0_5;
        }
        else
        {
          v26 = FLOAT_1_5;
          if ( v11 >= 1.5 )
            goto LABEL_50;
        }
      }
      v26 = v11;
LABEL_50:
      this->m_fDebugPlaybackSpeed = v26;
      mCreature->mPlaybackSpeed = v26;
    }
  }
}

