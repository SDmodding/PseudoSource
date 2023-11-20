// File Line: 41
// RVA: 0x15548B0
__int64 dynamic_initializer_for__UFG::AudioEventHandler::m_collisionList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEventHandler::m_collisionList__);
}

// File Line: 54
// RVA: 0x59CFD0
UFG::AudioEventHandler *__fastcall UFG::AudioEventHandler::GetInstance()
{
  UFG::AudioEventHandler *result; // rax
  UFG::AudioEventHandler *v1; // rcx

  result = UFG::AudioEventHandler::m_instance;
  if ( !UFG::AudioEventHandler::m_instance )
  {
    v1 = (UFG::AudioEventHandler *)UFG::qMalloc(
                                     (unsigned int)((_DWORD)UFG::AudioEventHandler::m_instance + 8),
                                     "AudioEventHandler",
                                     0i64);
    if ( v1 )
      v1->m_tido = (UFG::TidoGame *)UFG::TiDo::m_pInstance;
    else
      v1 = 0i64;
    UFG::AudioEventHandler::m_instance = v1;
    result = v1;
  }
  return result;
}

// File Line: 75
// RVA: 0x5A9B00
void __fastcall UFG::AudioEventHandler::RegisterEventHandlers(UFG::AudioEventHandler *this)
{
  UFG::AudioEventHandler *v1; // rbx
  UFG::AudioEventHandler *v2; // [rsp+30h] [rbp-18h]
  void (__fastcall *v3)(AMD_HD3D *); // [rsp+38h] [rbp-10h]

  v1 = this;
  if ( !UFG::AudioEventHandler::sm_EventRegistered )
  {
    v2 = this;
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleCollisionEvent;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gCollisionEventChannel.mUID,
      0i64,
      0);
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleCollisionEvent;
    v2 = v1;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gBulletCollisionEventChannel.mUID,
      0i64,
      0);
    v2 = v1;
    v3 = _;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gDestructionEventChannel.mUID,
      0i64,
      0);
    v2 = v1;
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleConstraintEvent;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gConstraintAudioEventChannel.mUID,
      0i64,
      0);
    v2 = v1;
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleScreenMinimizedEvent;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gScreenMinimizedEvent.mUID,
      0i64,
      0);
    v2 = v1;
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleScreenRestoredEvent;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gScreenRestoredEvent.mUID,
      0i64,
      0);
    UFG::AudioEventHandler::sm_EventRegistered = 1;
  }
}

// File Line: 97
// RVA: 0x5AE9D0
void __fastcall UFG::AudioEventHandler::UnregisterEventHandlers(UFG::AudioEventHandler *this)
{
  UFG::AudioEventHandler *v1; // rbx
  UFG::AudioEventHandler *v2; // [rsp+20h] [rbp-18h]
  void (__fastcall *v3)(AMD_HD3D *); // [rsp+28h] [rbp-10h]

  v1 = this;
  if ( UFG::AudioEventHandler::sm_EventRegistered )
  {
    v2 = this;
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleCollisionEvent;
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gCollisionEventChannel.mUID);
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleCollisionEvent;
    v2 = v1;
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gBulletCollisionEventChannel.mUID);
    v3 = _;
    v2 = v1;
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gDestructionEventChannel.mUID);
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleConstraintEvent;
    v2 = v1;
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gConstraintAudioEventChannel.mUID);
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleScreenMinimizedEvent;
    v2 = v1;
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gScreenMinimizedEvent.mUID);
    v3 = (void (__fastcall *)(AMD_HD3D *))UFG::AudioEventHandler::HandleScreenRestoredEvent;
    v2 = v1;
    UFG::EventDispatcher::UnRegister(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
      UFG::gScreenRestoredEvent.mUID);
    UFG::AudioEventHandler::sm_EventRegistered = 0;
  }
}

// File Line: 155
// RVA: 0x5A50C0
void __fastcall UFG::AudioEventHandler::PlayCollisionEvent(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::CollisionAudioData *v2; // rbx
  UFG::AudioEventHandler *v3; // rdi
  bool v4; // dl
  bool v5; // sf
  unsigned __int8 v6; // of
  UFG::SimObjectVehicle *v7; // rcx
  char v8; // si
  unsigned __int16 v9; // dx
  UFG::VehicleAudioComponent *v10; // rax
  UFG::SimObjectVehicle *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::VehicleAudioComponent *v13; // rax
  UFG::SimObjectVehicle *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::VehicleAudioComponent *v16; // rax
  UFG::SimObjectVehicle *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::VehicleAudioComponent *v19; // rax
  unsigned int v20; // eax
  unsigned int v21; // eax
  UFG::SimObjectGame *v22; // rcx
  unsigned __int16 v23; // dx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  UFG::CollisionEvent::ContactType v27; // ecx
  int v28; // ecx

  v2 = cad;
  v3 = this;
  v4 = cad->a.audioProperty == -2083503057 || cad->b.audioProperty == -2083503057;
  if ( v2->playEvent )
  {
    v2->averageVelocity = v2->totalVelocity;
    v6 = __OFSUB__(UFG::AudioEventHandler::sm_numCollisions, UFG::AudioEventHandler::sm_maxNumCollisionsPerFrame);
    v5 = UFG::AudioEventHandler::sm_numCollisions++ - UFG::AudioEventHandler::sm_maxNumCollisionsPerFrame < 0;
    if ( v5 ^ v6 || v4 )
    {
      v7 = (UFG::SimObjectVehicle *)v2->a.obj.m_pPointer;
      v8 = 0;
      if ( v7 && !v2->isBulletEvent )
      {
        v9 = v7->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                UFG::VehicleAudioComponent::_TypeUID);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v10 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v7->vfptr,
                                                  UFG::VehicleAudioComponent::_TypeUID);
          else
            v10 = (UFG::VehicleAudioComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v7->vfptr,
                                                                    UFG::VehicleAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::VehicleAudioComponent::_TypeUID));
        }
        else
        {
          v10 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v7);
        }
        if ( v10 )
        {
          if ( v10->m_bIsInitialized )
          {
            if ( v10->m_bVehicleIsInitialized )
            {
              v11 = (UFG::SimObjectVehicle *)v2->a.obj.m_pPointer;
              if ( v11 )
              {
                v12 = v11->m_Flags;
                if ( (v12 >> 14) & 1 )
                {
                  v13 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v11->vfptr,
                                                        UFG::VehicleAudioComponent::_TypeUID);
                }
                else if ( (v12 & 0x8000u) == 0 )
                {
                  if ( (v12 >> 13) & 1 )
                    v13 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v11->vfptr,
                                                          UFG::VehicleAudioComponent::_TypeUID);
                  else
                    v13 = (UFG::VehicleAudioComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v11->vfptr,
                                                                             UFG::VehicleAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::VehicleAudioComponent::_TypeUID));
                }
                else
                {
                  v13 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v11);
                }
                if ( v13
                  && v13->m_bIsInitialized
                  && v13->m_bVehicleIsInitialized
                  && v2->a.objProperties->collisionLayer
                  && v2->b.objProperties->collisionLayer )
                {
                  UFG::VehicleAudioComponent::HandleImpact(
                    v13,
                    v2->averageVelocity,
                    &v2->position,
                    v2->contactType,
                    v2->a.audioProperty,
                    v2->b.audioProperty);
                  v8 = 1;
                }
              }
            }
          }
        }
      }
      v14 = (UFG::SimObjectVehicle *)v2->b.obj.m_pPointer;
      if ( v14
        && !v2->isBulletEvent
        && ((v15 = v14->m_Flags, !((v15 >> 14) & 1)) ? ((v15 & 0x8000u) == 0 ? (!((v15 >> 13) & 1) ? (!((v15 >> 12) & 1) ? (v16 = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::VehicleAudioComponent::_TypeUID)) : (v16 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v14->vfptr, UFG::VehicleAudioComponent::_TypeUID))) : (v16 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v14->vfptr, UFG::VehicleAudioComponent::_TypeUID))) : (v16 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v14))) : (v16 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v14->vfptr, UFG::VehicleAudioComponent::_TypeUID)),
            v16
         && v16->m_bIsInitialized
         && v16->m_bVehicleIsInitialized
         && (v17 = (UFG::SimObjectVehicle *)v2->b.obj.m_pPointer) != 0i64
         && ((v18 = v17->m_Flags, !((v18 >> 14) & 1)) ? ((v18 & 0x8000u) == 0 ? (!((v18 >> 13) & 1) ? (!((v18 >> 12) & 1) ? (v19 = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::VehicleAudioComponent::_TypeUID)) : (v19 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v17->vfptr, UFG::VehicleAudioComponent::_TypeUID))) : (v19 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v17->vfptr, UFG::VehicleAudioComponent::_TypeUID))) : (v19 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v17))) : (v19 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v17->vfptr, UFG::VehicleAudioComponent::_TypeUID)),
             v19 && v19->m_bIsInitialized && v19->m_bVehicleIsInitialized)) )
      {
        UFG::VehicleAudioComponent::HandleImpact(
          v19,
          v2->averageVelocity,
          &v2->position,
          v2->contactType,
          v2->b.audioProperty,
          v2->a.audioProperty);
      }
      else if ( !v8 )
      {
        v20 = v2->a.audioProperty;
        if ( v20 == -432501436
          || v20 == 1073319342
          || v20 == -327412783
          || (v21 = v2->b.audioProperty, v21 == 1073319342)
          || v21 == -432501436
          || v21 == -327412783 )
        {
          v22 = (UFG::SimObjectGame *)v2->a.obj.m_pPointer;
          if ( v22 || (v22 = (UFG::SimObjectGame *)v2->b.obj.m_pPointer) != 0i64 )
          {
            v23 = v22->m_Flags;
            if ( !((v23 >> 14) & 1) )
            {
              if ( (v23 & 0x8000u) == 0 )
              {
                if ( (v23 >> 13) & 1 )
                {
                  UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::RagdollComponent::_TypeUID);
                }
                else if ( (v23 >> 12) & 1 )
                {
                  UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::RagdollComponent::_TypeUID);
                }
                else
                {
                  UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v22->vfptr, UFG::RagdollComponent::_TypeUID);
                }
              }
              else
              {
                UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::RagdollComponent::_TypeUID);
              }
            }
          }
          v24 = v2->a.audioProperty;
          if ( v24 == 1073319342 || v24 == -432501436 || v24 == -327412783 )
          {
            if ( v2->b.objProperties )
              v26 = v2->b.surfProperties;
            else
              v26 = (unsigned int)v2->a.objProperties->mDefaultSurfaceProperties.mData[1].mBaseNode.mChildren[0];
            v2->b.audioProperty = v26;
          }
          else
          {
            if ( v2->b.objProperties )
              v25 = v2->b.surfProperties;
            else
              v25 = (unsigned int)v2->a.objProperties->mDefaultSurfaceProperties.mData[1].mBaseNode.mChildren[0];
            v2->a.audioProperty = v25;
          }
        }
        if ( v2->isBulletEvent )
        {
          UFG::AudioEventHandler::PlayBulletSfx(v3, v2);
        }
        else
        {
          v27 = v2->contactType;
          if ( v27 )
          {
            v28 = v27 - 1;
            if ( v28 )
            {
              if ( v28 == 1 )
              {
                v2->velocityId = 1771175504;
                UFG::AudioEventHandler::PlayRollingSfx(v3, v2);
              }
            }
            else
            {
              v2->velocityId = 1771175504;
              UFG::AudioEventHandler::PlaySlidingSfx(v3, v2);
            }
          }
          else
          {
            UFG::AudioEventHandler::PlayCollisionSfx(v3, v2);
          }
        }
      }
    }
  }
}

// File Line: 297
// RVA: 0x59DD80
void __fastcall UFG::AudioEventHandler::HandleCollisionEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::Event *v2; // rdi
  UFG::AudioEventHandler *v3; // rsi
  UFG::CollisionAudioData *v4; // rbx
  bool v5; // al
  float v6; // xmm1_4
  float v7; // xmm2_4
  char v8; // cl
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v9; // rcx
  const char *v10; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  unsigned int v17; // eax
  unsigned int v18; // eax
  UFG::SimObject *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::SimObject *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::CollisionAudioData *v28; // rax
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v29; // rax
  UFG::CollisionAudioData __that; // [rsp+20h] [rbp-E0h]
  UFG::qReflectHandleBase v31; // [rsp+C0h] [rbp-40h]
  UFG::qReflectHandleBase v32; // [rsp+E8h] [rbp-18h]
  UFG::qReflectHandleBase v33; // [rsp+110h] [rbp+10h]
  UFG::qReflectHandleBase v34; // [rsp+138h] [rbp+38h]
  __int64 v35; // [rsp+160h] [rbp+60h]

  v35 = -2i64;
  v2 = thisEvent;
  v3 = this;
  if ( !UFG::TidoGame::sm_disableCollisions )
  {
    __that.mPrev = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&__that;
    __that.mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&__that;
    v4 = 0i64;
    __that.a.audioProperty = 0;
    __that.a.obj.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.a.obj.mPrev;
    __that.a.obj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.a.obj.mPrev;
    __that.a.obj.m_pPointer = 0i64;
    __that.a.objProperties = 0i64;
    __that.b.audioProperty = 0;
    __that.b.obj.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.b.obj.mPrev;
    __that.b.obj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.b.obj.mPrev;
    __that.b.obj.m_pPointer = 0i64;
    __that.b.objProperties = 0i64;
    *(_WORD *)&__that.setVelocity = 0;
    __that.playEvent = 1;
    *(_QWORD *)&__that.mappedVelocity = 0i64;
    *(_QWORD *)&__that.totalVelocity = 0i64;
    __that.instanceCount = 1;
    *(_QWORD *)&__that.position.x = 0i64;
    __that.position.z = 0.0;
    if ( LocalPlayer == (UFG::SimObjectCharacter *)thisEvent[2].vfptr
      || (v5 = 0, LocalPlayer == *(UFG::SimObjectCharacter **)&thisEvent[2].m_EventUID) )
    {
      v5 = 1;
    }
    __that.involvesPlayer = v5;
    v6 = *(float *)&thisEvent[1].mPrev;
    v7 = *((float *)&thisEvent[1].mPrev + 1);
    __that.position.x = *((float *)&thisEvent[1].vfptr + 1);
    __that.position.y = v6;
    __that.position.z = v7;
    v8 = __that.isBulletEvent;
    if ( thisEvent->m_EventUID == UFG::gBulletCollisionEventChannel.mUID )
      v8 = 1;
    __that.isBulletEvent = v8;
    UFG::qReflectHandleBase::qReflectHandleBase(&v31);
    v10 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v9);
    v31.mTypeUID = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v31, v31.mTypeUID, *(_QWORD *)&v2[3].m_EventUID);
    if ( !v31.mData )
      UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v31);
    UFG::qReflectHandleBase::qReflectHandleBase(&v32);
    v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
    v32.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v32, v32.mTypeUID, (unsigned __int64)v2[3].m_NamePTR);
    if ( !v32.mData )
      UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v32);
    UFG::qReflectHandleBase::qReflectHandleBase(&v34);
    v14 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v13);
    v34.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v34, v34.mTypeUID, v2[3].mUserData0);
    UFG::qReflectHandleBase::qReflectHandleBase(&v33);
    v16 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v15);
    v33.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v33, v33.mTypeUID, v2[3].mUserData1);
    if ( !(_S30_1 & 1) )
    {
      _S30_1 |= 1u;
      UFG::qSymbolUC::create_from_string(&qcAudioEvent, "AudioEvent");
      atexit(UFG::AudioEventHandler::HandleCollisionEvent_::_11_::_dynamic_atexit_destructor_for__qcAudioEvent__);
    }
    __that.a.audioProperty = *(_DWORD *)(v31.mData[4].mBaseNode.mUID + 104);
    __that.b.audioProperty = *(_DWORD *)(v32.mData[4].mBaseNode.mUID + 104);
    __that.setVelocity = 1;
    __that.a.objProperties = (UFG::PhysicsObjectProperties *)v31.mData;
    __that.b.objProperties = (UFG::PhysicsObjectProperties *)v32.mData;
    if ( v34.mData )
      v17 = (unsigned int)v34.mData[1].mBaseNode.mChildren[0];
    else
      v17 = 0;
    __that.a.surfProperties = v17;
    if ( v33.mData )
      v18 = (unsigned int)v33.mData[1].mBaseNode.mChildren[0];
    else
      v18 = 0;
    __that.b.surfProperties = v18;
    v19 = (UFG::SimObject *)v2[2].vfptr;
    if ( __that.a.obj.m_pPointer )
    {
      v20 = __that.a.obj.mPrev;
      v21 = __that.a.obj.mNext;
      __that.a.obj.mPrev->mNext = __that.a.obj.mNext;
      v21->mPrev = v20;
      __that.a.obj.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.a.obj.mPrev;
      __that.a.obj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.a.obj.mPrev;
    }
    __that.a.obj.m_pPointer = v19;
    if ( v19 )
    {
      v22 = v19->m_SafePointerList.mNode.mPrev;
      v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.a.obj.mPrev;
      __that.a.obj.mPrev = v22;
      __that.a.obj.mNext = &v19->m_SafePointerList.mNode;
      v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.a.obj.mPrev;
    }
    v23 = *(UFG::SimObject **)&v2[2].m_EventUID;
    if ( __that.b.obj.m_pPointer )
    {
      v24 = __that.b.obj.mPrev;
      v25 = __that.b.obj.mNext;
      __that.b.obj.mPrev->mNext = __that.b.obj.mNext;
      v25->mPrev = v24;
      __that.b.obj.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.b.obj.mPrev;
      __that.b.obj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.b.obj.mPrev;
    }
    __that.b.obj.m_pPointer = v23;
    if ( v23 )
    {
      v26 = v23->m_SafePointerList.mNode.mPrev;
      v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.b.obj.mPrev;
      __that.b.obj.mPrev = v26;
      __that.b.obj.mNext = &v23->m_SafePointerList.mNode;
      v23->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.b.obj.mPrev;
    }
    __that.contactType = (UFG::CollisionEvent::ContactType)v2[1].vfptr;
    __that.mappedVelocity = COERCE_FLOAT(COERCE_UNSIGNED_INT(*((float *)&v2[1].m_EventUID + 1) / UFG::TidoGame::sm_MaxCollisionVelocity) & _xmm)
                          * 100.0;
    __that.totalVelocity = __that.mappedVelocity;
    if ( UFG::TidoGame::sm_useCollisionAveraging )
    {
      v27 = UFG::qMalloc(0x98ui64, "Audio.CollisionRecord", 0i64);
      if ( v27 )
      {
        UFG::CollisionAudioData::CollisionAudioData((UFG::CollisionAudioData *)v27);
        v4 = v28;
      }
      UFG::CollisionAudioData::operator=(v4, &__that);
      v29 = UFG::AudioEventHandler::m_collisionList.mNode.mPrev;
      UFG::AudioEventHandler::m_collisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&v4->mPrev;
      v4->mPrev = v29;
      v4->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList;
      UFG::AudioEventHandler::m_collisionList.mNode.mPrev = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&v4->mPrev;
    }
    else if ( UFG::AudioEventHandler::IsValidCollision(&__that) )
    {
      UFG::AudioEventHandler::PlayCollisionEvent(v3, &__that);
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v33);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v34);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v32);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v31);
    UFG::CollisionAudioData::~CollisionAudioData(&__that);
  }
}

// File Line: 389
// RVA: 0x59E1D0
void __fastcall UFG::AudioEventHandler::HandleConstraintEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::Event *v2; // rbx
  UFG::OneShotHandle pHandle; // [rsp+48h] [rbp+10h]

  v2 = thisEvent;
  pHandle.m_pOneShot = 0i64;
  UFG::OneShotPool::GetOneShotHandle(&pHandle, (UFG::qVector3 *)(&thisEvent[1].m_EventUID + 1));
  if ( UFG::OneShotHandle::IsValid(&pHandle) )
  {
    if ( !(_S31_1 & 1) )
    {
      _S31_1 |= 1u;
      velocity_0.mUID = UFG::qWiseSymbolUIDFromString("velocity", 0x811C9DC5);
      _((AMD_HD3D *)velocity_0.mUID);
      atexit(UFG::AudioEventHandler::HandleConstraintEvent_::_4_::_dynamic_atexit_destructor_for__velocity__);
    }
    UFG::AudioEntity::SetRtpcValue(
      (UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr,
      velocity_0.mUID,
      *(float *)&v2[1].mUserData0);
    UFG::OneShot::Play(pHandle.m_pOneShot, v2[1].m_EventUID);
  }
  UFG::OneShotHandle::Release(&pHandle);
}

// File Line: 401
// RVA: 0x59F2F0
void __fastcall UFG::AudioEventHandler::HandleScreenMinimizedEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::TiDo *v2; // rax

  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
  {
    v2 = UFG::TiDo::GetInstance();
    UFG::TiDo::ScreenMinimized(v2, 1);
    UFG::MovieHandler::SetVolumeAll(&UFG::TheMovieHandler, 0);
  }
}

// File Line: 410
// RVA: 0x59F330
void __fastcall UFG::AudioEventHandler::HandleScreenRestoredEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::TiDo *v2; // rax
  UFG::GameStatTracker *v3; // rax
  signed int v4; // eax

  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
  {
    v2 = UFG::TiDo::GetInstance();
    UFG::TiDo::ScreenMinimized(v2, 0);
    v3 = UFG::GameStatTracker::Instance();
    v4 = UFG::GameStatTracker::GetStat(v3, VolumeSFX);
    UFG::MovieHandler::SetVolumeAll(&UFG::TheMovieHandler, (signed int)(float)((float)v4 * 2000.0));
  }
}

// File Line: 427
// RVA: 0x5A5580
void __fastcall UFG::AudioEventHandler::PlayCollisionSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::CollisionAudioData *v2; // rbx
  unsigned int v3; // ebp
  unsigned int v4; // esi
  UFG::CollisionAudioObjectData *v5; // rdi
  UFG::CollisionAudioObjectData *v6; // r14
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  UFG::CollisionAudioObjectData *v11; // rcx
  unsigned int v12; // eax
  UFG::CollisionAudioObjectData *v13; // rax
  UFG::SimObject *v14; // rcx
  UFG::TransformNodeComponent *v15; // rax
  float *v16; // rdi
  unsigned int v17; // eax
  UFG::OneShotHandle pHandle; // [rsp+58h] [rbp+10h]

  v2 = cad;
  v3 = cad->a.surfProperties;
  if ( !v3 )
    v3 = cad->a.audioProperty;
  v4 = cad->b.surfProperties;
  if ( !v4 )
    v4 = cad->b.audioProperty;
  if ( v3 )
  {
    if ( v4 )
    {
      v5 = &cad->a;
      if ( cad->a.audioProperty != -974062208
        || cad->b.audioProperty != -974062208 && cad->b.audioProperty != -1793093012 )
      {
        v6 = &cad->b;
        v7 = _S32_0;
        if ( _S32_0 & 1 )
        {
          v9 = s_uBodyWholeBody;
        }
        else
        {
          _S32_0 |= 1u;
          v8 = UFG::TiDo::CalcWwiseUid("BODY_WHOLE_BODY");
          v9 = v8;
          s_uBodyWholeBody = v8;
          v7 = _S32_0;
        }
        if ( !(v7 & 2) )
        {
          _S32_0 = v7 | 2;
          s_uObjectCar = UFG::TiDo::CalcWwiseUid("OBJECT_CAR");
          v9 = s_uBodyWholeBody;
        }
        v10 = v5->surfProperties;
        if ( !v10 )
          v10 = v5->audioProperty;
        if ( v10 == v9 )
        {
          v11 = v5;
        }
        else
        {
          v12 = v6->surfProperties;
          if ( !v12 )
            v12 = v6->audioProperty;
          if ( v12 != v9 )
            goto LABEL_34;
          v11 = v6;
        }
        if ( !v11 || !v2->involvesPlayer || v4 == 536829512 )
          goto LABEL_34;
        v13 = 0i64;
        if ( v11 == v5 )
          v13 = v6;
        if ( v11 == v6 )
          v13 = v5;
        if ( !v13
          || (v14 = v13->obj.m_pPointer) == 0i64
          || (v15 = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                                     v14,
                                                     UFG::TransformNodeComponent::_TransformNodeComponentTypeUID),
              (v16 = (float *)v15) == 0i64)
          || (UFG::TransformNodeComponent::UpdateWorldTransform(v15),
              (float)((float)((float)(v16[64] * v16[64]) + (float)(v16[65] * v16[65])) + (float)(v16[66] * v16[66])) >= 1.0) )
        {
LABEL_34:
          pHandle.m_pOneShot = 0i64;
          UFG::OneShotPool::GetOneShotHandle(&pHandle, &v2->position);
          if ( UFG::OneShotHandle::IsValid(&pHandle) )
          {
            v17 = _S32_0;
            if ( !(_S32_0 & 4) )
            {
              _S32_0 |= 4u;
              material1.mUID = UFG::qWiseSymbolUIDFromString("material1", 0x811C9DC5);
              _((AMD_HD3D *)material1.mUID);
              atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_33_::_dynamic_atexit_destructor_for__material1__);
              v17 = _S32_0;
            }
            if ( !(v17 & 8) )
            {
              _S32_0 = v17 | 8;
              material2.mUID = UFG::qWiseSymbolUIDFromString("material2", 0x811C9DC5);
              _((AMD_HD3D *)material2.mUID);
              atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_33_::_dynamic_atexit_destructor_for__material2__);
              v17 = _S32_0;
            }
            if ( !(v17 & 0x10) )
            {
              _S32_0 = v17 | 0x10;
              play_debris_collision.mUID = UFG::qWiseSymbolUIDFromString("play_debris_collision", 0x811C9DC5);
              _((AMD_HD3D *)play_debris_collision.mUID);
              atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_33_::_dynamic_atexit_destructor_for__play_debris_collision__);
            }
            UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr, material1.mUID, v3);
            UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr, material2.mUID, v4);
            if ( v2->setVelocity )
            {
              if ( !(_S32_0 & 0x20) )
              {
                _S32_0 |= 0x20u;
                velocity_1.mUID = UFG::qWiseSymbolUIDFromString("velocity", 0x811C9DC5);
                _((AMD_HD3D *)velocity_1.mUID);
                atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_36_::_dynamic_atexit_destructor_for__velocity__);
              }
              UFG::AudioEntity::SetRtpcValue(
                (UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr,
                velocity_1.mUID,
                v2->mappedVelocity);
            }
            UFG::OneShot::Play(pHandle.m_pOneShot, play_debris_collision.mUID);
          }
          UFG::OneShotHandle::Release(&pHandle);
          return;
        }
      }
    }
  }
}

// File Line: 504
// RVA: 0x5A6E30
void __fastcall UFG::AudioEventHandler::PlayRollingSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::CollisionAudioData *v2; // rdi
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v3; // rbx
  unsigned int v4; // ebp
  UFG::SimObject *v5; // rsi
  UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *v6; // rcx
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v8; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v9; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v10; // rcx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v11; // rax

  v2 = cad;
  if ( !(_S33_1 & 1) )
  {
    _S33_1 |= 1u;
    AudioPropertyRolling_0.mUID = UFG::qWiseSymbolUIDFromString("AudioPropertyRolling", 0x811C9DC5);
    _((AMD_HD3D *)AudioPropertyRolling_0.mUID);
    atexit(UFG::AudioEventHandler::PlayRollingSfx_::_2_::_dynamic_atexit_destructor_for__AudioPropertyRolling__);
  }
  v3 = 0i64;
  v4 = 0;
  v5 = 0i64;
  if ( v2->a.obj.m_pPointer )
  {
    v4 = UFG::PhysicsObjectProperties::GetAudioProperty(
           v2->a.objProperties,
           (UFG::qWiseSymbol *)&AudioPropertyRolling_0.mUID)->mUID;
    v5 = v2->a.obj.m_pPointer;
  }
  if ( v2->b.obj.m_pPointer && !v4 )
  {
    v4 = UFG::PhysicsObjectProperties::GetAudioProperty(
           v2->b.objProperties,
           (UFG::qWiseSymbol *)&AudioPropertyRolling_0.mUID)->mUID;
    v5 = v2->b.obj.m_pPointer;
  }
  v6 = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext;
  if ( (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext == &UFG::PersistentCollisionManager::smCollisionList )
  {
LABEL_13:
    if ( v4 - 1 <= 0xFFFFFFFD )
    {
      v7 = UFG::qMalloc(0x20ui64, "PersistentAudioCollision", 0i64);
      if ( v7 )
      {
        UFG::PersistentEventItem::PersistentEventItem((UFG::PersistentEventItem *)v7, v5, &v2->position);
        v3 = v8;
      }
      if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)v3 + 3) )
      {
        if ( !(_S33_1 & 2) )
        {
          _S33_1 |= 2u;
          rolling_speed.mUID = UFG::qWiseSymbolUIDFromString("rolling_speed", 0x811C9DC5);
          _((AMD_HD3D *)rolling_speed.mUID);
          atexit(UFG::AudioEventHandler::PlayRollingSfx_::_14_::_dynamic_atexit_destructor_for__rolling_speed__);
        }
        UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)v3[3], rolling_speed.mUID, v2->mappedVelocity);
        UFG::OneShot::Play((UFG::OneShot *)v3[3], v4);
        v9 = UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev;
        UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        *v3 = v9;
        v3[1] = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&UFG::PersistentCollisionManager::smCollisionList;
        UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        ++UFG::PersistentCollisionManager::sm_numPersistentEvents;
      }
      else if ( v3 )
      {
        UFG::OneShotHandle::Release((UFG::OneShotHandle *)v3 + 3);
        v10 = *v3;
        v11 = v3[1];
        v10->mNext = v11;
        v11->mPrev = v10;
        *v3 = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        v3[1] = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        operator delete[](v3);
      }
    }
  }
  else
  {
    while ( (UFG::SimObject *)v6[1].mNode.mPrev != v5 )
    {
      v6 = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)v6->mNode.mNext;
      if ( v6 == &UFG::PersistentCollisionManager::smCollisionList )
        goto LABEL_13;
    }
    UFG::PersistentCollisionManager::UpdateCollision((UFG::PersistentEventItem *)v6, v2);
  }
}G::PersistentCollisionManager::Update

// File Line: 555
// RVA: 0x5A76D0
void __fastcall UFG::AudioEventHandler::PlaySlidingSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::CollisionAudioData *v2; // rdi
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v3; // rbx
  unsigned int v4; // ebp
  UFG::SimObject *v5; // rsi
  UFG::qWiseSymbol *v6; // rax
  UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v9; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v10; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v11; // rcx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v12; // rax

  v2 = cad;
  if ( !(_S34_0 & 1) )
  {
    _S34_0 |= 1u;
    AudioPropertySliding.mUID = UFG::qWiseSymbolUIDFromString("AudioPropertySliding", 0x811C9DC5);
    _((AMD_HD3D *)AudioPropertySliding.mUID);
    atexit(UFG::AudioEventHandler::PlaySlidingSfx_::_2_::_dynamic_atexit_destructor_for__AudioPropertySliding__);
  }
  v3 = 0i64;
  v4 = 0;
  v5 = 0i64;
  if ( v2->a.obj.m_pPointer )
  {
    v6 = UFG::PhysicsObjectProperties::GetAudioProperty(
           v2->a.objProperties,
           (UFG::qWiseSymbol *)&AudioPropertySliding.mUID);
    v5 = v2->a.obj.m_pPointer;
  }
  else
  {
    if ( !v2->b.obj.m_pPointer )
      goto LABEL_8;
    v6 = UFG::PhysicsObjectProperties::GetAudioProperty(
           v2->a.objProperties,
           (UFG::qWiseSymbol *)&AudioPropertySliding.mUID);
    v5 = v2->b.obj.m_pPointer;
  }
  v4 = v6->mUID;
LABEL_8:
  v7 = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext;
  if ( (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext == &UFG::PersistentCollisionManager::smCollisionList )
  {
LABEL_13:
    if ( v4 - 1 <= 0xFFFFFFFD )
    {
      v8 = UFG::qMalloc(0x20ui64, "PersistentAudioCollision", 0i64);
      if ( v8 )
      {
        UFG::PersistentEventItem::PersistentEventItem((UFG::PersistentEventItem *)v8, v5, &v2->position);
        v3 = v9;
      }
      if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)v3 + 3) )
      {
        UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)v3[3], 0x6991FE50u, v2->mappedVelocity);
        UFG::OneShot::Play((UFG::OneShot *)v3[3], v4);
        v10 = UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev;
        UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        *v3 = v10;
        v3[1] = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&UFG::PersistentCollisionManager::smCollisionList;
        UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        ++UFG::PersistentCollisionManager::sm_numPersistentEvents;
      }
      else if ( v3 )
      {
        UFG::OneShotHandle::Release((UFG::OneShotHandle *)v3 + 3);
        v11 = *v3;
        v12 = v3[1];
        v11->mNext = v12;
        v12->mPrev = v11;
        *v3 = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        v3[1] = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        operator delete[](v3);
      }
    }
  }
  else
  {
    while ( (UFG::SimObject *)v7[1].mNode.mPrev != v5 )
    {
      v7 = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)v7->mNode.mNext;
      if ( v7 == &UFG::PersistentCollisionManager::smCollisionList )
        goto LABEL_13;
    }
    UFG::PersistentCollisionManager::UpdateCollision((UFG::PersistentEventItem *)v7, v2);
  }
}

// File Line: 610
// RVA: 0x5A4E00
void __fastcall UFG::AudioEventHandler::PlayBulletSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::CollisionAudioData *v2; // rbx
  UFG::SimObjectCharacter *v3; // rcx
  UFG::ActorAudioComponent *v4; // rdi
  unsigned __int16 v5; // dx
  UFG::ActorAudioComponent *v6; // rax
  unsigned int v7; // ecx
  UFG::AudioEntity *v8; // rdi
  unsigned int v9; // eax
  unsigned int v10; // er8
  float v11; // xmm0_4
  float v12; // xmm1_4
  unsigned int v13; // er8
  UFG::OneShotHandle pHandle; // [rsp+58h] [rbp+10h]

  v2 = cad;
  v3 = (UFG::SimObjectCharacter *)cad->a.obj.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = _S35_1;
  if ( !(_S35_1 & 1) )
  {
    _S35_1 |= 1u;
    play_gp_bullet_impacts = UFG::TiDo::CalcWwiseUid("play_gp_bullet_impacts");
    v7 = _S35_1;
  }
  if ( v4 && (v8 = v4->m_SFXEntity) != 0i64 )
  {
    if ( LocalPlayer == (UFG::SimObjectCharacter *)v2->a.obj.m_pPointer )
    {
      if ( v7 & 2 )
      {
        v9 = player_rumble;
      }
      else
      {
        _S35_1 = v7 | 2;
        v9 = UFG::TiDo::CalcWwiseUid("Play_gun_hit_motion");
        player_rumble = v9;
      }
      UFG::AudioEntity::CreateAndPlayEvent(v8, v9, 0i64, 0, 0i64);
    }
    v10 = v2->a.audioProperty;
    if ( v10 || v2->a.surfProperties )
    {
      if ( v2->a.surfProperties )
        v10 = v2->a.surfProperties;
      UFG::AudioEntity::SetWwiseSwitch(v8, 0xF17446D7, v10);
      v11 = v2->position.y;
      v12 = v2->position.z;
      v8->m_WorldMatrix.v3.x = v2->position.x;
      v8->m_WorldMatrix.v3.y = v11;
      v8->m_WorldMatrix.v3.z = v12;
      v8->m_WorldMatrix.v3.w = 1.0;
      UFG::AudioEntity::ForcePositionUpdate(v8);
      UFG::AudioEntity::CreateAndPlayEvent(v8, play_gp_bullet_impacts, 0i64, 0, 0i64);
    }
  }
  else if ( v2->a.audioProperty || v2->a.surfProperties )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &v2->position);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      v13 = v2->a.surfProperties;
      if ( !v13 )
        v13 = v2->a.audioProperty;
      UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr, 0xF17446D7, v13);
      UFG::OneShot::Play(pHandle.m_pOneShot, play_gp_bullet_impacts);
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 658
// RVA: 0x5A06A0
char __fastcall UFG::AudioEventHandler::IsValidCollision(UFG::CollisionAudioData *cad)
{
  UFG::CollisionAudioData *v1; // rdi
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v2; // rax
  char result; // al
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  signed __int64 v6; // rcx
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v8; // rax
  UFG::allocator::free_link *v9; // [rsp+78h] [rbp+20h]

  v1 = cad;
  v2 = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
  if ( (UFG::qList<UFG::CollisionAudioData,UFG::CollisionAudioData,1,0> *)UFG::AudioEventHandler::m_collisionList.mNode.mNext == &UFG::AudioEventHandler::m_collisionList )
  {
LABEL_6:
    v4 = UFG::qMalloc(0x98ui64, "Audio.CollisionRecord", 0i64);
    v5 = v4;
    if ( v4 )
    {
      v4->mNext = v4;
      v4[1].mNext = v4;
      v6 = (signed __int64)&v4[2];
      *(_DWORD *)v6 = 0;
      v7 = v4 + 3;
      v7->mNext = v7;
      v7[1].mNext = v7;
      v7[2].mNext = 0i64;
      *(_QWORD *)(v6 + 32) = 0i64;
      LODWORD(v5[8].mNext) = 0;
      v9 = v5 + 9;
      v9->mNext = v9;
      v9[1].mNext = v9;
      v5[11].mNext = 0i64;
      v5[12].mNext = 0i64;
      *(_WORD *)((char *)&v5[14].mNext + 1) = 0;
      BYTE3(v5[14].mNext) = 1;
      *(UFG::allocator::free_link **)((char *)&v5[14].mNext + 4) = 0i64;
      *(UFG::allocator::free_link **)((char *)&v5[15].mNext + 4) = 0i64;
      HIDWORD(v5[16].mNext) = 1;
      *(UFG::allocator::free_link **)((char *)&v5[17].mNext + 4) = 0i64;
      HIDWORD(v5[18].mNext) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::CollisionAudioData::operator=((UFG::CollisionAudioData *)v5, v1);
    v8 = UFG::AudioEventHandler::m_collisionList.mNode.mPrev;
    UFG::AudioEventHandler::m_collisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)v5;
    v5->mNext = (UFG::allocator::free_link *)v8;
    v5[1].mNext = (UFG::allocator::free_link *)&UFG::AudioEventHandler::m_collisionList;
    UFG::AudioEventHandler::m_collisionList.mNode.mPrev = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)v5;
    result = 1;
  }
  else
  {
    while ( (float)((float)((float)((float)(cad->position.x - *((float *)&v2[8].mNext + 1))
                                  * (float)(cad->position.x - *((float *)&v2[8].mNext + 1)))
                          + (float)((float)(cad->position.y - *(float *)&v2[9].mPrev)
                                  * (float)(cad->position.y - *(float *)&v2[9].mPrev)))
                  + (float)((float)(cad->position.z - *((float *)&v2[9].mPrev + 1))
                          * (float)(cad->position.z - *((float *)&v2[9].mPrev + 1)))) >= UFG::TidoGame::sm_minCollisionSeparation )
    {
      v2 = v2->mNext;
      if ( v2 == (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList )
        goto LABEL_6;
    }
    result = 0;
  }
  return result;
}

// File Line: 749
// RVA: 0x5AEE70
void __fastcall UFG::AudioEventHandler::Update(UFG::AudioEventHandler *this, float delta_sec)
{
  UFG::AudioEventHandler *v2; // rdi
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v3; // rbx
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v4; // rdx
  int v5; // er9
  char v6; // r8
  char v7; // cl
  bool v8; // zf
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v9; // r9
  char v10; // r10
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v11; // r8
  float v12; // xmm0_4
  int v13; // ecx
  int v14; // eax

  v2 = this;
  if ( UFG::TidoGame::sm_useCollisionAveraging )
  {
    v3 = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
    v4 = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
    if ( (UFG::qList<UFG::CollisionAudioData,UFG::CollisionAudioData,1,0> *)UFG::AudioEventHandler::m_collisionList.mNode.mNext != &UFG::AudioEventHandler::m_collisionList )
    {
      do
      {
        if ( BYTE3(v4[7].mPrev)
          && v3 != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList )
        {
          do
          {
            if ( v4 != v3 )
            {
              v5 = (int)v4[3].mNext;
              v6 = 0;
              v7 = 0;
              if ( v5 == LODWORD(v3[3].mNext) )
              {
                v6 = 0;
                if ( LODWORD(v4[6].mNext) == LODWORD(v3[6].mNext) )
                  v6 = 1;
              }
              v8 = v5 == LODWORD(v3[6].mNext);
              v9 = v4[2].mNext;
              v10 = v6;
              v11 = v3[2].mNext;
              if ( v8 )
                v10 = 1;
              if ( v11 == v9 )
              {
                v7 = 0;
                if ( v3[5].mNext == v4[5].mNext )
                  v7 = 1;
              }
              if ( v11 == v4[5].mNext && v3[5].mNext == v9 )
                v7 = 1;
              if ( v10 && v7 )
              {
                ++HIDWORD(v4[8].mPrev);
                v12 = *((float *)&v4[7].mNext + 1);
                if ( v12 <= *((float *)&v3[7].mPrev + 1) )
                  v12 = *((float *)&v3[7].mPrev + 1);
                *((float *)&v4[7].mNext + 1) = v12;
                v13 = (int)v3[8].mNext;
                BYTE3(v3[7].mPrev) = 0;
                v14 = (int)v4[8].mNext;
                if ( v14 != v13 && (!v14 || !v13) )
                  LODWORD(v4[8].mNext) = 0;
              }
            }
            v3 = v3->mNext;
          }
          while ( v3 != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList );
          v3 = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
        }
        v4 = v4->mNext;
      }
      while ( v4 != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList );
      for ( ;
            v3 != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList;
            v3 = v3->mNext )
      {
        UFG::AudioEventHandler::PlayCollisionEvent(v2, (UFG::CollisionAudioData *)v3);
      }
    }
  }
}

// File Line: 797
// RVA: 0x1554AE0
__int64 dynamic_initializer_for__UFG::PersistentCollisionManager::smCollisionList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PersistentCollisionManager::smCollisionList__);
}

// File Line: 817
// RVA: 0x59BED0
UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *__fastcall UFG::PersistentCollisionManager::FindCollision(UFG::OneShot *obj)
{
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v1; // rbx
  UFG::OneShot *v2; // rdi

  v1 = UFG::PersistentCollisionManager::smCollisionList.mNode.mNext;
  v2 = obj;
  if ( (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext == &UFG::PersistentCollisionManager::smCollisionList )
    return 0i64;
  while ( !UFG::OneShotHandle::OwnsOneShot((UFG::OneShotHandle *)&v1[1].mNext, v2) )
  {
    v1 = v1->mNext;
    if ( v1 == (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&UFG::PersistentCollisionManager::smCollisionList )
      return 0i64;
  }
  return v1;
}

// File Line: 833
// RVA: 0x5B0150
void __fastcall UFG::PersistentCollisionManager::UpdateCollision(UFG::PersistentEventItem *item, UFG::CollisionAudioData *cad)
{
  UFG::AudioEntity **v2; // rbx
  UFG::CollisionAudioData *v3; // rdi
  UFG::AudioEntity *v4; // rcx
  float v5; // xmm0_4
  float v6; // xmm1_4

  v2 = (UFG::AudioEntity **)&item->m_pOneShot;
  v3 = cad;
  if ( UFG::OneShotHandle::IsValid(&item->m_pOneShot) )
  {
    v4 = *v2;
    if ( (UFG::AudioEntity *)(*v2)[1].vfptr == &(*v2)[1] && (UFG::AudioEntity *)(*v2)[1].mPrev == &(*v2)[1] )
    {
      if ( v4[1].mNext )
      {
        v5 = v3->position.y;
        v6 = v3->position.z;
        v4->m_WorldMatrix.v3.x = v3->position.x;
        v4->m_WorldMatrix.v3.w = 1.0;
        v4->m_WorldMatrix.v3.y = v5;
        v4->m_WorldMatrix.v3.z = v6;
        UFG::AudioEntity::ForcePositionUpdate(v4);
        UFG::AudioEntity::SetRtpcValue(*v2, v3->velocityId, v3->mappedVelocity);
        UFG::AudioEvent::TouchUpdate((UFG::AudioEvent *)(*v2)[1].mNext);
      }
    }
  }
}

// File Line: 860
// RVA: 0x5A9EE0
void __fastcall UFG::PersistentCollisionManager::RemoveCollision(UFG::PersistentEventItem *item)
{
  UFG::PersistentEventItem *v1; // rbx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v2; // rdx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v3; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v4; // rcx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v5; // rax

  v1 = item;
  v2 = item->mPrev;
  v3 = item->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  item->mPrev = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&item->mPrev;
  item->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&item->mPrev;
  UFG::OneShotHandle::Release(&item->m_pOneShot);
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&v1->mPrev;
  operator delete[](v1);
  --UFG::PersistentCollisionManager::sm_numPersistentEvents;
}

