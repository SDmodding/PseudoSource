// File Line: 29
// RVA: 0x157B810
__int64 dynamic_initializer_for__UFG::RemoteDriverComponent::s_RemoteDriverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RemoteDriverComponent::s_RemoteDriverComponentList__);
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
void __fastcall UFG::RemoteDriverComponent::RemoteDriverComponent(UFG::RemoteDriverComponent *this, unsigned int name_uid)
{
  UFG::RemoteDriverComponent *v2; // rbx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v3; // rdx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v4; // rax

  v2 = this;
  UFG::VehicleDriverInterface::VehicleDriverInterface((UFG::VehicleDriverInterface *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::UpdateInterface};
  *(_WORD *)&v2->mIsInAir = 0;
  v4 = UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mPrev;
  UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)&UFG::RemoteDriverComponent::s_RemoteDriverComponentList;
  UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mPrev = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::RemoteDriverComponent::_RemoteDriverComponentTypeUID,
    "RemoteDriverComponent");
  *(_QWORD *)&v2->mReplicatedInput.mSteering = 0i64;
  v2->mReplicatedInput.mRawGasBrakes = 0.0;
  *(_WORD *)&v2->mReplicatedInput.mHandbrake = 0;
  v2->mReplicatedInput.mHorn = 0;
}

// File Line: 47
// RVA: 0x66CF50
void __fastcall UFG::RemoteDriverComponent::~RemoteDriverComponent(UFG::RemoteDriverComponent *this)
{
  UFG::RemoteDriverComponent *v1; // r8
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v2; // rdx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v3; // rcx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v4; // rax
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v5; // rcx
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::RemoteDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator )
    UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator = (UFG::RemoteDriverComponent *)&this->mPrev[-19];
  v2 = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::VehicleDriverInterface::~VehicleDriverInterface((UFG::VehicleDriverInterface *)&v1->vfptr);
}

// File Line: 64
// RVA: 0x683130
void __fastcall UFG::RemoteDriverComponent::OnAttach(UFG::RemoteDriverComponent *this, UFG::SimObject *object)
{
  UFG::RemoteDriverComponent *v2; // r14
  UFG::SimObjectGame *v3; // rbx
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  int v9; // eax
  UFG::PhysicsWheeledVehicle *v10; // rdi
  UFG::SimObject *v11; // rax
  UFG::SimComponent *v12; // rsi
  signed int v13; // er15
  int v14; // xmm2_4
  int v15; // xmm3_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm2_4
  int v19; // xmm3_4
  int v20; // xmm2_4
  int v21; // xmm3_4
  int v22; // xmm0_4
  int v23; // xmm2_4
  int v24; // xmm3_4
  int v25; // xmm0_4
  UFG::PhysicsVehicle *v26; // rcx
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 *v29; // rax
  float v30; // xmm1_4
  float v31; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v33; // rax
  UFG::SimObjectCVBase *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::SimObjectCVBase *v36; // rcx
  unsigned __int16 v37; // dx
  unsigned int v38; // edx
  bool v39; // zf
  UFG::qVector3 velocity; // [rsp+18h] [rbp-29h]
  UFG::qVector3 result; // [rsp+28h] [rbp-19h]
  int v42; // [rsp+38h] [rbp-9h]
  int v43; // [rsp+3Ch] [rbp-5h]
  int v44; // [rsp+40h] [rbp-1h]
  int v45; // [rsp+44h] [rbp+3h]
  int v46; // [rsp+48h] [rbp+7h]
  int v47; // [rsp+4Ch] [rbp+Bh]
  int v48; // [rsp+50h] [rbp+Fh]
  int v49; // [rsp+54h] [rbp+13h]
  int v50; // [rsp+58h] [rbp+17h]
  int v51; // [rsp+5Ch] [rbp+1Bh]
  int v52; // [rsp+60h] [rbp+1Fh]
  int v53; // [rsp+64h] [rbp+23h]
  int v54; // [rsp+68h] [rbp+27h]
  int v55; // [rsp+6Ch] [rbp+2Bh]
  int v56; // [rsp+70h] [rbp+2Fh]
  int v57; // [rsp+74h] [rbp+33h]
  signed int retaddr; // [rsp+A8h] [rbp+67h]
  int v59; // [rsp+B0h] [rbp+6Fh]

  v2 = this;
  v3 = (UFG::SimObjectGame *)object;
  UFG::VehicleDriverInterface::OnAttach((UFG::VehicleDriverInterface *)&this->vfptr, object);
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          goto LABEL_37;
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v5 = v6;
      }
      else
      {
        v5 = v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
      {
        retaddr = -1;
        UFG::qSymbol::set_null((UFG::qSymbol *)&retaddr);
        if ( HIDWORD(v5[9].m_BoundComponentHandles.mNode.mPrev) == -1 )
          HIDWORD(v5[9].m_BoundComponentHandles.mNode.mPrev) = UFG::qStringHashUpper32(
                                                                 (const char *)v5[9].m_pSimObject,
                                                                 0xFFFFFFFF);
        v7 = UFG::qStringHashUpper32("_Body_P", HIDWORD(v5[9].m_BoundComponentHandles.mNode.mPrev));
        if ( UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v7) )
        {
          v8 = v5[10].m_SafePointerList.mNode.mPrev;
          v9 = *(_DWORD *)(&v5[3].m_SimObjIndex + 1);
          v10 = 0i64;
          v59 = *(_DWORD *)(&v5[3].m_SimObjIndex + 1);
          if ( !v8 || v9 != LODWORD(v5[8].m_BoundComponentHandles.mNode.mPrev) )
          {
            LODWORD(v5[8].m_BoundComponentHandles.mNode.mPrev) = v9;
            if ( v8 )
            {
              ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, int *))v8->mPrev[1].mNext)(
                v8,
                &v59);
            }
            else
            {
              v11 = v5->m_pSimObject;
              if ( v11 )
                v12 = v11->m_Components.p[2].m_pComponent;
              else
                v12 = 0i64;
              v13 = 1;
              if ( (_QWORD)v5[14].vfptr & 8 )
                v13 = 4;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v14 = (int)v12[2].m_SafePointerList.mNode.mPrev;
              v15 = HIDWORD(v12[2].m_SafePointerList.mNode.mPrev);
              v16 = (int)v12[2].vfptr;
              v43 = HIDWORD(v12[2].vfptr);
              v44 = v14;
              v42 = v16;
              v45 = v15;
              v17 = HIDWORD(v12[2].m_SafePointerList.mNode.mNext);
              v18 = v12[2].m_TypeUID;
              v19 = v12[2].m_NameUID;
              v46 = (int)v12[2].m_SafePointerList.mNode.mNext;
              v47 = v17;
              v48 = v18;
              v49 = v19;
              v20 = (int)v12[2].m_pSimObject;
              v21 = HIDWORD(v12[2].m_pSimObject);
              v22 = *(_DWORD *)&v12[2].m_Flags;
              v51 = *(_DWORD *)(&v12[2].m_SimObjIndex + 1);
              v50 = v22;
              v52 = v20;
              v53 = v21;
              v23 = (int)v12[2].m_BoundComponentHandles.mNode.mNext;
              v24 = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mNext);
              v25 = (int)v12[2].m_BoundComponentHandles.mNode.mPrev;
              v55 = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mPrev);
              v56 = v23;
              v54 = v25;
              v57 = v24;
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)v5, 0);
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v26 = (UFG::PhysicsVehicle *)v5[10].m_SafePointerList.mNode.mPrev;
              v27 = *((float *)&v12[4].vfptr + 1);
              v28 = *(float *)&v12[4].m_SafePointerList.mNode.mPrev;
              velocity.x = *(float *)&v12[4].vfptr;
              velocity.y = v27;
              velocity.z = v28;
              if ( v26 )
              {
                v29 = UFG::PhysicsVehicle::GetVelocity(v26, &result);
                v30 = v29->y;
                v31 = v29->z;
                velocity.x = v29->x;
                velocity.y = v30;
                velocity.z = v31;
              }
              v32 = v5[10].m_SafePointerList.mNode.mPrev;
              if ( v32 )
                ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, signed __int64))v32->mPrev->mPrev)(
                  v32,
                  1i64);
              v33 = v5->vfptr;
              v5[10].m_SafePointerList.mNode.mPrev = 0i64;
              ((void (__fastcall *)(UFG::SimComponent *, int *, UFG::qVector3 *))v33[19].__vecDelDtor)(
                v5,
                &v42,
                &velocity);
              LODWORD(v5[10].m_SafePointerList.mNode.mPrev[34].mPrev) = v13;
              UFG::PhysicsVehicle::SetVelocity((UFG::PhysicsVehicle *)v5[10].m_SafePointerList.mNode.mPrev, &velocity);
              if ( (_QWORD)v5[14].vfptr & 2 )
                ((void (__cdecl *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))v5[10].m_SafePointerList.mNode.mPrev->mPrev[3].mNext)(v5[10].m_SafePointerList.mNode.mPrev);
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)v5, 1);
            }
          }
          v34 = (UFG::SimObjectCVBase *)v5->m_pSimObject;
          if ( v34 )
          {
            if ( UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v34) )
            {
              v35 = v5[10].m_SafePointerList.mNode.mPrev;
              if ( v35 )
              {
                if ( BYTE4(v35[37].mNext) & 7 )
                  v10 = (UFG::PhysicsWheeledVehicle *)v5[10].m_SafePointerList.mNode.mPrev;
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
  v36 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( !v36 )
    return;
  v37 = v36->m_Flags;
  if ( (v37 >> 14) & 1 || (v37 & 0x8000u) != 0 )
  {
    UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v36);
    return;
  }
  if ( (v37 >> 13) & 1 )
  {
    v38 = UFG::SimObjectVehiclePropertiesComponent::_TypeUID;
LABEL_43:
    UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v36->vfptr, v38);
    return;
  }
  v39 = ((v37 >> 12) & 1) == 0;
  v38 = UFG::SimObjectVehiclePropertiesComponent::_TypeUID;
  if ( !v39 )
    goto LABEL_43;
  UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v36->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
}

// File Line: 95
// RVA: 0x693880
void __fastcall UFG::RemoteDriverComponent::Update(UFG::RemoteDriverComponent *this, float deltaTime)
{
  UFG::RemoteDriverComponent *v2; // rbx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  UFG::PhysicsMoverInterface *v4; // rdi
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  float v6; // xmm1_4
  bool v7; // cf
  char v8; // bp
  UFG::VehicleAudioComponent *v9; // rsi
  hkgpIndexedMeshDefinitions::Edge *v10; // rdx
  char v11; // al
  UFG::VehicleEffectsComponent *v12; // rcx
  int v13; // eax
  UFG::VehicleEffectsComponent *v14; // rcx
  UFG::VehicleAudioComponent *v15; // rax

  v2 = this;
  UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)&this->vfptr, deltaTime);
  v4 = (UFG::PhysicsMoverInterface *)v2->m_BoundComponentHandles.mNode.mPrev;
  LOBYTE(v5) = 0;
  v6 = v4->mForwardSpeed;
  if ( v2->mAudioComponent.mPrev )
  {
    *((_DWORD *)&v4->mInput + 4) |= 0x200u;
    LODWORD(v4->mInput.mGasBrakes) = v2->mDesiredState;
    v7 = 0.1 < v4->mInput.mGasBrakes;
    v4->mInput.mRawGasBrakes = v2->mReverseLockoutDelay;
    v8 = 0;
    if ( v7 )
      v8 = 1;
    LODWORD(v4->mInput.mSteering) = v2->mState;
    *((_DWORD *)&v4->mInput + 4) ^= (*((_DWORD *)&v4->mInput + 4) ^ 4
                                                                  * *((unsigned __int8 *)&v2->mReverseLockoutDelay + 4)) & 4;
    if ( UFG::RemoteDriverComponent::gShouldResetVehicle && v2->m_BoundComponentHandles.mNode.mPrev )
    {
      UFG::RemoteDriverComponent::gShouldResetVehicle = 0;
      ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, _QWORD))v2->m_BoundComponentHandles.mNode.mPrev->mPrev[7].mPrev)(
        v2->m_BoundComponentHandles.mNode.mPrev,
        0i64);
      HIDWORD(v2->mAudioComponent.mNext) = 2;
    }
    v9 = (UFG::VehicleAudioComponent *)v2->mRenderComponent.mNext;
    if ( v9 && *(float *)&v2->mDesiredState < -0.1 )
    {
      if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v5) )
      {
        v11 = *((_BYTE *)v9 + 636);
        if ( !(v11 & 2) )
          *((_BYTE *)v9 + 636) = v11 | 2;
      }
      UFG::VehicleAudioComponent::TurnOnRadio((UFG::VehicleAudioComponent *)v2->mRenderComponent.mNext, v10);
    }
    v12 = (UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext;
    if ( v12 )
    {
      if ( v8 || ((v13 = (int)v2->mPropertySet, v13 == 1) || v13 == 6) && *((_BYTE *)&v4->mInput + 16) & 4 )
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v12, FX_BRAKELIGHTS);
      else
        UFG::VehicleEffectsComponent::TurnOffLightEffects(v12, FX_BRAKELIGHTS);
      v14 = (UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext;
      if ( v6 >= -0.1 )
        UFG::VehicleEffectsComponent::TurnOffLightEffects(v14, FX_REVERSE);
      else
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v14, FX_REVERSE);
      v15 = (UFG::VehicleAudioComponent *)v2->mRenderComponent.mNext;
      if ( v15 )
      {
        if ( *((_BYTE *)v15 + 0x27E) & 8 && !*(&v2->mForceDock + 1) )
        {
          *(&v2->mForceDock + 1) = 1;
          UFG::VehicleEffectsComponent::TurnOnCopLights((UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext);
        }
        if ( !(BYTE6(v2->mRenderComponent.mNext[39].mNext) & 8) )
        {
          if ( *(&v2->mForceDock + 1) )
          {
            *(&v2->mForceDock + 1) = 0;
            UFG::VehicleEffectsComponent::TurnOffCopLights((UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext);
          }
        }
      }
    }
  }
  else
  {
    v2->mAudioComponent.m_TypeUID = 0;
  }
}

