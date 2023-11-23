// File Line: 29
// RVA: 0x157B810
__int64 dynamic_initializer_for__UFG::RemoteDriverComponent::s_RemoteDriverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RemoteDriverComponent::s_RemoteDriverComponentList__);
}

// File Line: 30
// RVA: 0x157AD30
__int64 dynamic_initializer_for__UFG::RemoteDriverComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::RemoteDriverComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::RemoteDriverComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::RemoteDriverComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::RemoteDriverComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 40
// RVA: 0x66A390
void __fastcall UFG::RemoteDriverComponent::RemoteDriverComponent(
        UFG::RemoteDriverComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *mPrev; // rax

  UFG::VehicleDriverInterface::VehicleDriverInterface(this, name_uid);
  this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>::mPrev = &this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>;
  this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>::mNext = &this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>;
  this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::UpdateInterface};
  *(_WORD *)&this->mIsInAir = 0;
  mPrev = UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mPrev;
  UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>;
  this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>::mNext = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)&UFG::RemoteDriverComponent::s_RemoteDriverComponentList;
  UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>;
  UFG::SimComponent::AddType(this, UFG::RemoteDriverComponent::_RemoteDriverComponentTypeUID, "RemoteDriverComponent");
  *(_QWORD *)&this->mReplicatedInput.mSteering = 0i64;
  this->mReplicatedInput.mRawGasBrakes = 0.0;
  *(_WORD *)&this->mReplicatedInput.mHandbrake = 0;
  this->mReplicatedInput.mHorn = 0;
}

// File Line: 47
// RVA: 0x66CF50
void __fastcall UFG::RemoteDriverComponent::~RemoteDriverComponent(UFG::RemoteDriverComponent *this)
{
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v2; // rdx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *mPrev; // rcx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *mNext; // rax
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v5; // rcx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v6; // rax

  this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator )
    UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator = (UFG::RemoteDriverComponent *)&this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>::mPrev[-19];
  v2 = &this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>;
  mPrev = this->UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::VehicleDriverInterface::~VehicleDriverInterface(this);
}

// File Line: 64
// RVA: 0x683130
void __fastcall UFG::RemoteDriverComponent::OnAttach(UFG::RemoteDriverComponent *this, UFG::SimObjectGame *object)
{
  signed __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int v7; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  int v9; // eax
  UFG::PhysicsWheeledVehicle *v10; // rdi
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *v12; // rsi
  int v13; // r15d
  int v14; // xmm2_4
  int mPrev_high; // xmm3_4
  int vfptr; // xmm0_4
  int mNext_high; // xmm1_4
  int m_TypeUID; // xmm2_4
  int m_NameUID; // xmm3_4
  int v20; // xmm2_4
  int m_pSimObject_high; // xmm3_4
  int v22; // xmm0_4
  int mNext; // xmm2_4
  int v24; // xmm3_4
  int v25; // xmm0_4
  UFG::PhysicsVehicle *v26; // rcx
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 *v29; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v33; // rax
  UFG::SimObjectCVBase *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::SimObjectCVBase *v36; // rcx
  __int16 v37; // dx
  unsigned int v38; // edx
  bool v39; // zf
  UFG::qVector3 velocity; // [rsp+18h] [rbp-29h] BYREF
  UFG::qVector3 result; // [rsp+28h] [rbp-19h] BYREF
  int v42[18]; // [rsp+38h] [rbp-9h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+67h] BYREF
  int v44; // [rsp+B0h] [rbp+6Fh] BYREF

  UFG::VehicleDriverInterface::OnAttach(this, object);
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          goto LABEL_37;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = object->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        LODWORD(retaddr) = -1;
        UFG::qSymbol::set_null((UFG::qSymbol *)&retaddr);
        if ( HIDWORD(m_pComponent[9].m_BoundComponentHandles.mNode.mPrev) == -1 )
          HIDWORD(m_pComponent[9].m_BoundComponentHandles.mNode.mPrev) = UFG::qStringHashUpper32(
                                                                           (const char *)m_pComponent[9].m_pSimObject,
                                                                           -1);
        v7 = UFG::qStringHashUpper32("_Body_P", HIDWORD(m_pComponent[9].m_BoundComponentHandles.mNode.mPrev));
        if ( UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v7) )
        {
          mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
          v9 = *(_DWORD *)(&m_pComponent[3].m_SimObjIndex + 1);
          v10 = 0i64;
          v44 = v9;
          if ( !mPrev || v9 != LODWORD(m_pComponent[8].m_BoundComponentHandles.mNode.mPrev) )
          {
            LODWORD(m_pComponent[8].m_BoundComponentHandles.mNode.mPrev) = v9;
            if ( mPrev )
            {
              ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, int *))mPrev->mPrev[1].mNext)(
                mPrev,
                &v44);
            }
            else
            {
              m_pSimObject = m_pComponent->m_pSimObject;
              if ( m_pSimObject )
                v12 = m_pSimObject->m_Components.p[2].m_pComponent;
              else
                v12 = 0i64;
              v13 = 1;
              if ( ((__int64)m_pComponent[14].vfptr & 8) != 0 )
                v13 = 4;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v14 = (int)v12[2].m_SafePointerList.mNode.mPrev;
              mPrev_high = HIDWORD(v12[2].m_SafePointerList.mNode.mPrev);
              vfptr = (int)v12[2].vfptr;
              v42[1] = HIDWORD(v12[2].vfptr);
              v42[2] = v14;
              v42[0] = vfptr;
              v42[3] = mPrev_high;
              mNext_high = HIDWORD(v12[2].m_SafePointerList.mNode.mNext);
              m_TypeUID = v12[2].m_TypeUID;
              m_NameUID = v12[2].m_NameUID;
              v42[4] = (int)v12[2].m_SafePointerList.mNode.mNext;
              v42[5] = mNext_high;
              v42[6] = m_TypeUID;
              v42[7] = m_NameUID;
              v20 = (int)v12[2].m_pSimObject;
              m_pSimObject_high = HIDWORD(v12[2].m_pSimObject);
              v22 = *(_DWORD *)&v12[2].m_Flags;
              v42[9] = *(_DWORD *)(&v12[2].m_SimObjIndex + 1);
              v42[8] = v22;
              v42[10] = v20;
              v42[11] = m_pSimObject_high;
              mNext = (int)v12[2].m_BoundComponentHandles.mNode.mNext;
              v24 = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mNext);
              v25 = (int)v12[2].m_BoundComponentHandles.mNode.mPrev;
              v42[13] = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mPrev);
              v42[14] = mNext;
              v42[12] = v25;
              v42[15] = v24;
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)m_pComponent, 0);
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v26 = (UFG::PhysicsVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev;
              v27 = *((float *)&v12[4].vfptr + 1);
              v28 = *(float *)&v12[4].m_SafePointerList.mNode.mPrev;
              velocity.x = *(float *)&v12[4].vfptr;
              velocity.y = v27;
              velocity.z = v28;
              if ( v26 )
              {
                v29 = UFG::PhysicsVehicle::GetVelocity(v26, &result);
                y = v29->y;
                z = v29->z;
                velocity.x = v29->x;
                velocity.y = y;
                velocity.z = z;
              }
              v32 = m_pComponent[10].m_SafePointerList.mNode.mPrev;
              if ( v32 )
                ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, __int64))v32->mPrev->mPrev)(
                  v32,
                  1i64);
              v33 = m_pComponent->vfptr;
              m_pComponent[10].m_SafePointerList.mNode.mPrev = 0i64;
              ((void (__fastcall *)(UFG::SimComponent *, int *, UFG::qVector3 *))v33[19].__vecDelDtor)(
                m_pComponent,
                v42,
                &velocity);
              LODWORD(m_pComponent[10].m_SafePointerList.mNode.mPrev[34].mPrev) = v13;
              UFG::PhysicsVehicle::SetVelocity(
                (UFG::PhysicsVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev,
                &velocity);
              if ( ((__int64)m_pComponent[14].vfptr & 2) != 0 )
                ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))m_pComponent[10].m_SafePointerList.mNode.mPrev->mPrev[3].mNext)(m_pComponent[10].m_SafePointerList.mNode.mPrev);
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)m_pComponent, 1);
            }
          }
          v34 = (UFG::SimObjectCVBase *)m_pComponent->m_pSimObject;
          if ( v34 )
          {
            if ( UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v34) )
            {
              v35 = m_pComponent[10].m_SafePointerList.mNode.mPrev;
              if ( v35 )
              {
                if ( (BYTE4(v35[37].mNext) & 7) != 0 )
                  v10 = (UFG::PhysicsWheeledVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev;
                if ( v10 )
                  UFG::PhysicsWheeledVehicle::ClearSteeringDeadZone(v10);
              }
            }
          }
        }
      }
    }
  }
LABEL_37:
  v36 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( !v36 )
    return;
  v37 = v36->m_Flags;
  if ( (v37 & 0x4000) != 0 || v37 < 0 )
  {
    UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v36);
    return;
  }
  if ( (v37 & 0x2000) != 0 )
  {
    v38 = UFG::SimObjectVehiclePropertiesComponent::_TypeUID;
LABEL_43:
    UFG::SimObjectGame::GetComponentOfTypeHK(v36, v38);
    return;
  }
  v39 = (v37 & 0x1000) == 0;
  v38 = UFG::SimObjectVehiclePropertiesComponent::_TypeUID;
  if ( !v39 )
    goto LABEL_43;
  UFG::SimObject::GetComponentOfType(v36, UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
}

// File Line: 95
// RVA: 0x693880
void __fastcall UFG::RemoteDriverComponent::Update(UFG::RemoteDriverComponent *this, float deltaTime)
{
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  UFG::PhysicsMoverInterface *mPrev; // rdi
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  float mForwardSpeed; // xmm1_4
  bool v7; // cf
  bool v8; // bp
  UFG::VehicleAudioComponent *mNext; // rsi
  hkgpIndexedMeshDefinitions::Edge *v10; // rdx
  char v11; // al
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  int mPropertySet; // eax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  UFG::VehicleAudioComponent *v15; // rax

  UFG::VehicleDriverInterface::Update(this, deltaTime);
  mPrev = (UFG::PhysicsMoverInterface *)this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
  LOBYTE(v5) = 0;
  mForwardSpeed = mPrev->mForwardSpeed;
  if ( this->mAudioComponent.UFG::VehicleDriverInterface::mPrev )
  {
    *((_DWORD *)&mPrev->mInput + 4) |= 0x200u;
    LODWORD(mPrev->mInput.mGasBrakes) = this->mDesiredState;
    v7 = mPrev->mInput.mGasBrakes > 0.1;
    mPrev->mInput.mRawGasBrakes = this->mReverseLockoutDelay;
    v8 = v7;
    LODWORD(mPrev->mInput.mSteering) = this->mState;
    *((_DWORD *)&mPrev->mInput + 4) ^= (*((_DWORD *)&mPrev->mInput + 4) ^ (4
                                                                         * *((unsigned __int8 *)&this->mReverseLockoutDelay
                                                                           + 4))) & 4;
    if ( UFG::RemoteDriverComponent::gShouldResetVehicle
      && this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev )
    {
      UFG::RemoteDriverComponent::gShouldResetVehicle = 0;
      ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, _QWORD))this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev->UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[7].mPrev)(
        this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev,
        0i64);
      HIDWORD(this->mAudioComponent.mNext) = 2;
    }
    mNext = (UFG::VehicleAudioComponent *)this->mRenderComponent.mNext;
    if ( mNext && *(float *)&this->mDesiredState < -0.1 )
    {
      if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v5) )
      {
        v11 = *((_BYTE *)mNext + 636);
        if ( (v11 & 2) == 0 )
          *((_BYTE *)mNext + 636) = v11 | 2;
      }
      UFG::VehicleAudioComponent::TurnOnRadio((UFG::VehicleAudioComponent *)this->mRenderComponent.mNext, v10);
    }
    v12 = this->mMoverComponent.mNext;
    if ( v12 )
    {
      if ( v8
        || ((mPropertySet = (int)this->mPropertySet, mPropertySet == 1) || mPropertySet == 6)
        && (*((_BYTE *)&mPrev->mInput + 16) & 4) != 0 )
      {
        UFG::VehicleEffectsComponent::TurnOnLightEffects((UFG::VehicleEffectsComponent *)v12, FX_BRAKELIGHTS);
      }
      else
      {
        UFG::VehicleEffectsComponent::TurnOffLightEffects((UFG::VehicleEffectsComponent *)v12, FX_BRAKELIGHTS);
      }
      v14 = this->mMoverComponent.mNext;
      if ( mForwardSpeed >= -0.1 )
        UFG::VehicleEffectsComponent::TurnOffLightEffects((UFG::VehicleEffectsComponent *)v14, FX_REVERSE);
      else
        UFG::VehicleEffectsComponent::TurnOnLightEffects((UFG::VehicleEffectsComponent *)v14, FX_REVERSE);
      v15 = (UFG::VehicleAudioComponent *)this->mRenderComponent.mNext;
      if ( v15 )
      {
        if ( (*((_BYTE *)v15 + 0x27E) & 8) != 0 && !*(&this->mForceDock + 1) )
        {
          *(&this->mForceDock + 1) = 1;
          UFG::VehicleEffectsComponent::TurnOnCopLights((UFG::VehicleEffectsComponent *)this->mMoverComponent.mNext);
        }
        if ( (BYTE6(this->mRenderComponent.mNext[39].mNext) & 8) == 0 && *(&this->mForceDock + 1) )
        {
          *(&this->mForceDock + 1) = 0;
          UFG::VehicleEffectsComponent::TurnOffCopLights((UFG::VehicleEffectsComponent *)this->mMoverComponent.mNext);
        }
      }
    }
  }
  else
  {
    this->mAudioComponent.m_TypeUID = 0;
  }
}

