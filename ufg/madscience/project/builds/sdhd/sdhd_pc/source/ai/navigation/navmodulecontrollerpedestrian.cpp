// File Line: 58
// RVA: 0x391110
void __fastcall UFG::NavModuleControllerPedestrian::Update(UFG::NavModuleControllerPedestrian *this)
{
  UFG::NavModuleControllerPedestrian *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  Intention *v6; // rdx
  UFG::NavModuleLocal *v7; // rcx
  float v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::NavObject *v11; // rax

  v1 = this;
  if ( UFG::NavComponent::HasPath(this->m_navComponent) && !UFG::NavComponent::ms_bDisableNavigation )
  {
    v2 = (UFG::SimObjectCVBase *)v1->m_navComponent->m_pSimObject;
    if ( v2 )
    {
      v4 = v2->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v2->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v2->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v2->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
      }
      v3 = v5;
    }
    else
    {
      v3 = 0i64;
    }
    v6 = &v3->m_Intention;
    v7 = v1->m_navComponent->m_pNavModuleLocal;
    v8 = v7->m_steerData.m_vClampedDirection.x;
    v9 = v7->m_steerData.m_vClampedDirection.z;
    v10 = v7->m_steerData.m_fLocalSpeed;
    v6->mMotionIntentionDirection.y = v7->m_steerData.m_vClampedDirection.y;
    v6->mMotionIntentionDirection.z = v9;
    v6->mMotionIntentionDirection.x = v8;
    UFG::NavModuleControllerPedestrian::SetIntentionSpeed(v1, v6, v10);
    v11 = UFG::NavModulePathing::GetNavObject(v1->m_navComponent->m_pNavModulePathing);
    if ( v11 )
      v11->vfptr->UpdateControl(v11, v1->m_navComponent);
  }
}

// File Line: 97
// RVA: 0x382EB0
void __fastcall UFG::NavModuleControllerPedestrian::Reset(UFG::NavModuleControllerPedestrian *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4

  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->m_vDirection.x = UFG::qVector3::msZero.x;
  this->m_vDirection.y = v1;
  this->m_vDirection.z = v2;
  this->m_fSpeed = 0.0;
  this->m_bVaulting = 0;
  this->m_fDebugPlaybackSpeed = -1.0;
}

// File Line: 116
// RVA: 0x386A90
void __fastcall UFG::NavModuleControllerPedestrian::SetIntentionSpeed(UFG::NavModuleControllerPedestrian *this, Intention *intention, float fSpeed)
{
  Intention *v3; // rdi
  UFG::NavModuleControllerPedestrian *v4; // r15
  UFG::SimObjectGame *v5; // rbx
  signed int v6; // esi
  UFG::AIEntityComponent *v7; // r14
  unsigned __int16 v8; // cx
  UFG::AIEntityComponent *v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int8 v11; // cl
  float v12; // xmm6_4
  unsigned __int64 v13; // rax
  unsigned __int8 v14; // cl
  unsigned __int64 v15; // rax
  unsigned __int8 v16; // cl
  __int64 v17; // r9
  char v18; // cl
  float v19; // xmm1_4
  UFG::CharacterAnimationComponent *v20; // rax
  Creature *v21; // rbp
  float v22; // xmm0_4
  char v23; // di
  unsigned __int16 v24; // cx
  UFG::CharacterPhysicsComponent *v25; // rbx
  UFG::CharacterPhysicsComponent *v26; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v27; // rcx
  const char *v28; // rax
  float v29; // xmm0_4
  UFG::qReflectHandleBase v30; // [rsp+28h] [rbp-60h]

  v3 = intention;
  v4 = this;
  v5 = (UFG::SimObjectGame *)this->m_navComponent->m_pSimObject;
  v6 = 0;
  if ( v5 )
  {
    v8 = v5->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = (UFG::AIEntityComponent *)v5->m_Components.p[22].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::AIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::AIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::AIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v5->vfptr,
                                         UFG::AIEntityComponent::_TypeUID);
      }
      v7 = v9;
    }
    else
    {
      v7 = (UFG::AIEntityComponent *)v5->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  ((void (__fastcall *)(UFG::AIEntityComponent *))v7->vfptr[14].__vecDelDtor)(v7);
  v10 = v3->mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Walk.m_EnumValue >> 6];
  v11 = _bittest64((const signed __int64 *)&v10, gActionRequest_Walk.m_EnumValue & 0x3F);
  v12 = 0.0;
  if ( v11 && (!v3->mActionRequestChargeTimes[gActionRequest_Walk.m_EnumValue] || v11) )
  {
LABEL_27:
    v6 = 1;
    v3->mMotionIntentionSpeed = 0.50999999;
    v17 = gActionRequest_Walk.m_EnumValue;
    v18 = gActionRequest_Walk.m_EnumValue & 0x3F;
    v3->mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Walk.m_EnumValue >> 6] |= 1i64 << (gActionRequest_Walk.m_EnumValue & 0x3F);
    v19 = (float)(signed int)0.0;
    if ( v19 >= 255.0 )
      v19 = FLOAT_255_0;
    v3->mActionRequestChargeTimes[v17] = (signed int)v19;
    v3->mSignals |= 1i64 << v18;
    goto LABEL_30;
  }
  v13 = v3->mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Jog.m_EnumValue >> 6];
  v14 = _bittest64((const signed __int64 *)&v13, gActionRequest_Jog.m_EnumValue & 0x3F);
  if ( v14 && (!v3->mActionRequestChargeTimes[gActionRequest_Jog.m_EnumValue] || v14) )
    goto LABEL_26;
  v15 = v3->mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Sprint.m_EnumValue >> 6];
  v16 = _bittest64((const signed __int64 *)&v15, gActionRequest_Sprint.m_EnumValue & 0x3F);
  if ( v16 && (!v3->mActionRequestChargeTimes[gActionRequest_Sprint.m_EnumValue] || v16) )
    goto LABEL_25;
  if ( fSpeed > 0.029999999 )
  {
    if ( fSpeed >= 3.0 )
    {
      if ( fSpeed >= 4.8000002 )
      {
LABEL_25:
        v6 = 3;
        v3->mMotionIntentionSpeed = 1.6;
        Intention::Set(v3, gActionRequest_Jog.m_EnumValue, 0.0);
        Intention::Set(v3, gActionRequest_Sprint.m_EnumValue, 123.4);
        goto LABEL_30;
      }
LABEL_26:
      v6 = 2;
      v3->mMotionIntentionSpeed = 1.0;
      Intention::Set(v3, gActionRequest_Jog.m_EnumValue, 0.0);
      goto LABEL_30;
    }
    goto LABEL_27;
  }
LABEL_30:
  v20 = (UFG::CharacterAnimationComponent *)v7->m_pCharacterAnimationComponent.m_pSimComponent;
  if ( v20 )
  {
    v21 = v20->mCreature;
    if ( v21 )
    {
      v22 = sNaturalMovementSpeeds[v6];
      if ( v22 > 0.0 )
        v12 = fSpeed / v22;
      v23 = 0;
      if ( !v5 )
        goto LABEL_61;
      v24 = v5->m_Flags;
      if ( (v24 >> 14) & 1 )
      {
        v25 = (UFG::CharacterPhysicsComponent *)v5->m_Components.p[27].m_pComponent;
      }
      else
      {
        if ( (v24 & 0x8000u) == 0 )
        {
          if ( (v24 >> 13) & 1 )
            v26 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v5,
                                                      UFG::CharacterPhysicsComponent::_TypeUID);
          else
            v26 = (UFG::CharacterPhysicsComponent *)((v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v5,
                                                                         UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterPhysicsComponent::_TypeUID));
        }
        else
        {
          v26 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v5,
                                                    UFG::CharacterPhysicsComponent::_TypeUID);
        }
        v25 = v26;
      }
      if ( !v25 )
        goto LABEL_61;
      UFG::qReflectHandleBase::qReflectHandleBase(&v30);
      v28 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v27);
      v30.mTypeUID = UFG::qStringHash64(v28, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v30, v30.mTypeUID, v25->mGroundProperties.groundSurfaceHandleUid);
      if ( v30.mData )
        v23 = BYTE4(v30.mData[1].mBaseNode.mParent);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v30);
      if ( v23 )
      {
        if ( v12 <= 0.89999998 )
        {
          v12 = FLOAT_0_89999998;
        }
        else
        {
          v29 = FLOAT_1_1;
          if ( v12 >= 1.1 )
            goto LABEL_58;
        }
      }
      else
      {
LABEL_61:
        if ( v12 <= 0.5 )
        {
          v12 = FLOAT_0_5;
        }
        else
        {
          v29 = FLOAT_1_5;
          if ( v12 >= 1.5 )
            goto LABEL_58;
        }
      }
      v29 = v12;
LABEL_58:
      v4->m_fDebugPlaybackSpeed = v29;
      v21->mPlaybackSpeed = v29;
      return;
    }
  }
}

