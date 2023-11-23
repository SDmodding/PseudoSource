// File Line: 41
// RVA: 0x15548B0
__int64 dynamic_initializer_for__UFG::AudioEventHandler::m_collisionList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEventHandler::m_collisionList__);
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
    return v1;
  }
  return result;
}

// File Line: 75
// RVA: 0x5A9B00
void __fastcall UFG::AudioEventHandler::RegisterEventHandlers(UFG::AudioEventHandler *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+30h] [rbp-18h] BYREF

  if ( !UFG::AudioEventHandler::sm_EventRegistered )
  {
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleCollisionEvent;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v2, UFG::gCollisionEventChannel.mUID, 0i64, 0);
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleCollisionEvent;
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      &v2,
      UFG::gBulletCollisionEventChannel.mUID,
      0i64,
      0);
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))_;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v2, UFG::gDestructionEventChannel.mUID, 0i64, 0);
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleConstraintEvent;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      &v2,
      UFG::gConstraintAudioEventChannel.mUID,
      0i64,
      0);
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleScreenMinimizedEvent;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v2, UFG::gScreenMinimizedEvent.mUID, 0i64, 0);
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleScreenRestoredEvent;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v2, UFG::gScreenRestoredEvent.mUID, 0i64, 0);
    UFG::AudioEventHandler::sm_EventRegistered = 1;
  }
}

// File Line: 97
// RVA: 0x5AE9D0
void __fastcall UFG::AudioEventHandler::UnregisterEventHandlers(UFG::AudioEventHandler *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+20h] [rbp-18h] BYREF

  if ( UFG::AudioEventHandler::sm_EventRegistered )
  {
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleCollisionEvent;
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gCollisionEventChannel.mUID);
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleCollisionEvent;
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gBulletCollisionEventChannel.mUID);
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))_;
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gDestructionEventChannel.mUID);
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleConstraintEvent;
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gConstraintAudioEventChannel.mUID);
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleScreenMinimizedEvent;
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gScreenMinimizedEvent.mUID);
    v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AudioEventHandler::HandleScreenRestoredEvent;
    v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
    UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gScreenRestoredEvent.mUID);
    UFG::AudioEventHandler::sm_EventRegistered = 0;
  }
}

// File Line: 155
// RVA: 0x5A50C0
void __fastcall UFG::AudioEventHandler::PlayCollisionEvent(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  bool v4; // dl
  bool v5; // cc
  UFG::SimObjectVehicle *m_pPointer; // rcx
  char v7; // si
  __int16 m_Flags; // dx
  UFG::VehicleAudioComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectVehicle *v10; // rcx
  __int16 v11; // dx
  UFG::VehicleAudioComponent *ComponentOfType; // rax
  UFG::SimObjectVehicle *v13; // rcx
  __int16 v14; // dx
  UFG::VehicleAudioComponent *v15; // rax
  UFG::SimObjectVehicle *v16; // rcx
  __int16 v17; // dx
  UFG::VehicleAudioComponent *v18; // rax
  unsigned int audioProperty; // eax
  unsigned int v20; // eax
  UFG::SimObjectGame *v21; // rcx
  __int16 v22; // dx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int surfProperties; // eax
  UFG::CollisionEvent::ContactType contactType; // ecx
  __int32 v27; // ecx

  v4 = cad->a.audioProperty == -2083503057 || cad->b.audioProperty == -2083503057;
  if ( !cad->playEvent )
    return;
  cad->averageVelocity = cad->totalVelocity;
  v5 = UFG::AudioEventHandler::sm_numCollisions++ < UFG::AudioEventHandler::sm_maxNumCollisionsPerFrame;
  if ( !v5 && !v4 )
    return;
  m_pPointer = (UFG::SimObjectVehicle *)cad->a.obj.m_pPointer;
  v7 = 0;
  if ( m_pPointer && !cad->isBulletEvent )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
LABEL_18:
        if ( !ComponentOfTypeHK )
          goto LABEL_36;
        if ( !ComponentOfTypeHK->m_bIsInitialized )
          goto LABEL_36;
        if ( !ComponentOfTypeHK->m_bVehicleIsInitialized )
          goto LABEL_36;
        v10 = (UFG::SimObjectVehicle *)cad->a.obj.m_pPointer;
        if ( !v10 )
          goto LABEL_36;
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) == 0 )
        {
          if ( v11 < 0 )
          {
            ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v10);
LABEL_30:
            if ( ComponentOfType
              && ComponentOfType->m_bIsInitialized
              && ComponentOfType->m_bVehicleIsInitialized
              && cad->a.objProperties->collisionLayer
              && cad->b.objProperties->collisionLayer )
            {
              UFG::VehicleAudioComponent::HandleImpact(
                ComponentOfType,
                cad->averageVelocity,
                &cad->position,
                cad->contactType,
                cad->a.audioProperty,
                cad->b.audioProperty);
              v7 = 1;
            }
            goto LABEL_36;
          }
          if ( (v11 & 0x2000) == 0 && (v11 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                              v10,
                                                              UFG::VehicleAudioComponent::_TypeUID);
            goto LABEL_30;
          }
        }
        ComponentOfType = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v10,
                                                          UFG::VehicleAudioComponent::_TypeUID);
        goto LABEL_30;
      }
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        ComponentOfTypeHK = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::VehicleAudioComponent::_TypeUID);
        goto LABEL_18;
      }
    }
    ComponentOfTypeHK = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::VehicleAudioComponent::_TypeUID);
    goto LABEL_18;
  }
LABEL_36:
  v13 = (UFG::SimObjectVehicle *)cad->b.obj.m_pPointer;
  if ( !v13 || cad->isBulletEvent )
    goto LABEL_62;
  v14 = v13->m_Flags;
  if ( (v14 & 0x4000) != 0 )
  {
LABEL_44:
    v15 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v13,
                                          UFG::VehicleAudioComponent::_TypeUID);
    goto LABEL_46;
  }
  if ( v14 >= 0 )
  {
    if ( (v14 & 0x2000) == 0 && (v14 & 0x1000) == 0 )
    {
      v15 = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(v13, UFG::VehicleAudioComponent::_TypeUID);
      goto LABEL_46;
    }
    goto LABEL_44;
  }
  v15 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v13);
LABEL_46:
  if ( v15 )
  {
    if ( v15->m_bIsInitialized && v15->m_bVehicleIsInitialized )
    {
      v16 = (UFG::SimObjectVehicle *)cad->b.obj.m_pPointer;
      if ( v16 )
      {
        v17 = v16->m_Flags;
        if ( (v17 & 0x4000) == 0 )
        {
          if ( v17 < 0 )
          {
            v18 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v16);
LABEL_58:
            if ( v18 && v18->m_bIsInitialized && v18->m_bVehicleIsInitialized )
            {
              UFG::VehicleAudioComponent::HandleImpact(
                v18,
                cad->averageVelocity,
                &cad->position,
                cad->contactType,
                cad->b.audioProperty,
                cad->a.audioProperty);
              return;
            }
            goto LABEL_62;
          }
          if ( (v17 & 0x2000) == 0 && (v17 & 0x1000) == 0 )
          {
            v18 = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                  v16,
                                                  UFG::VehicleAudioComponent::_TypeUID);
            goto LABEL_58;
          }
        }
        v18 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v16,
                                              UFG::VehicleAudioComponent::_TypeUID);
        goto LABEL_58;
      }
    }
  }
LABEL_62:
  if ( !v7 )
  {
    audioProperty = cad->a.audioProperty;
    if ( audioProperty == -432501436
      || audioProperty == 1073319342
      || audioProperty == -327412783
      || (v20 = cad->b.audioProperty, v20 == 1073319342)
      || v20 == -432501436
      || v20 == -327412783 )
    {
      v21 = (UFG::SimObjectGame *)cad->a.obj.m_pPointer;
      if ( v21 || (v21 = (UFG::SimObjectGame *)cad->b.obj.m_pPointer) != 0i64 )
      {
        v22 = v21->m_Flags;
        if ( (v22 & 0x4000) == 0 )
        {
          if ( v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
            UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::RagdollComponent::_TypeUID);
          else
            UFG::SimObject::GetComponentOfType(v21, UFG::RagdollComponent::_TypeUID);
        }
      }
      v23 = cad->a.audioProperty;
      if ( v23 == 1073319342 || v23 == -432501436 || v23 == -327412783 )
      {
        if ( cad->b.objProperties )
          surfProperties = cad->b.surfProperties;
        else
          surfProperties = (unsigned int)cad->a.objProperties->mDefaultSurfaceProperties.mData[1].mBaseNode.mChildren[0];
        cad->b.audioProperty = surfProperties;
      }
      else
      {
        if ( cad->b.objProperties )
          v24 = cad->b.surfProperties;
        else
          v24 = (unsigned int)cad->a.objProperties->mDefaultSurfaceProperties.mData[1].mBaseNode.mChildren[0];
        cad->a.audioProperty = v24;
      }
    }
    if ( cad->isBulletEvent )
    {
      UFG::AudioEventHandler::PlayBulletSfx(this, cad);
    }
    else
    {
      contactType = cad->contactType;
      if ( contactType )
      {
        v27 = contactType - 1;
        if ( v27 )
        {
          if ( v27 == 1 )
          {
            cad->velocityId = 1771175504;
            UFG::AudioEventHandler::PlayRollingSfx(this, cad);
          }
        }
        else
        {
          cad->velocityId = 1771175504;
          UFG::AudioEventHandler::PlaySlidingSfx(this, cad);
        }
      }
      else
      {
        UFG::AudioEventHandler::PlayCollisionSfx(this, cad);
      }
    }
  }
}

// File Line: 297
// RVA: 0x59DD80
void __fastcall UFG::AudioEventHandler::HandleCollisionEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::CollisionAudioData *v4; // rbx
  bool v5; // al
  float v6; // xmm1_4
  float v7; // xmm2_4
  bool isBulletEvent; // cl
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v9; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  unsigned int v17; // eax
  unsigned int v18; // eax
  UFG::SimObject *vfptr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::SimObject *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::CollisionAudioData *v28; // rax
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v29; // rax
  UFG::CollisionAudioData __that; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qReflectHandleBase v31; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qReflectHandleBase v32; // [rsp+E8h] [rbp-18h] BYREF
  UFG::qReflectHandleBase v33; // [rsp+110h] [rbp+10h] BYREF
  UFG::qReflectHandleBase v34; // [rsp+138h] [rbp+38h] BYREF
  __int64 v35; // [rsp+160h] [rbp+60h]

  v35 = -2i64;
  if ( !UFG::TidoGame::sm_disableCollisions )
  {
    __that.mPrev = &__that;
    __that.mNext = &__that;
    v4 = 0i64;
    __that.a.audioProperty = 0;
    __that.a.obj.mPrev = &__that.a.obj;
    __that.a.obj.mNext = &__that.a.obj;
    __that.a.obj.m_pPointer = 0i64;
    __that.a.objProperties = 0i64;
    __that.b.audioProperty = 0;
    __that.b.obj.mPrev = &__that.b.obj;
    __that.b.obj.mNext = &__that.b.obj;
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
    isBulletEvent = __that.isBulletEvent;
    if ( thisEvent->m_EventUID == UFG::gBulletCollisionEventChannel.mUID )
      isBulletEvent = 1;
    __that.isBulletEvent = isBulletEvent;
    UFG::qReflectHandleBase::qReflectHandleBase(&v31);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v9);
    v31.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v31, v31.mTypeUID, *(_QWORD *)&thisEvent[3].m_EventUID);
    if ( !v31.mData )
      UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v31);
    UFG::qReflectHandleBase::qReflectHandleBase(&v32);
    v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
    v32.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v32, v32.mTypeUID, (unsigned __int64)thisEvent[3].m_NamePTR);
    if ( !v32.mData )
      UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v32);
    UFG::qReflectHandleBase::qReflectHandleBase(&v34);
    v14 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v13);
    v34.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v34, v34.mTypeUID, thisEvent[3].mUserData0);
    UFG::qReflectHandleBase::qReflectHandleBase(&v33);
    v16 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v15);
    v33.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v33, v33.mTypeUID, thisEvent[3].mUserData1);
    if ( (_S30_1 & 1) == 0 )
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
    vfptr = (UFG::SimObject *)thisEvent[2].vfptr;
    if ( __that.a.obj.m_pPointer )
    {
      mPrev = __that.a.obj.mPrev;
      mNext = __that.a.obj.mNext;
      __that.a.obj.mPrev->mNext = __that.a.obj.mNext;
      mNext->mPrev = mPrev;
      __that.a.obj.mPrev = &__that.a.obj;
      __that.a.obj.mNext = &__that.a.obj;
    }
    __that.a.obj.m_pPointer = vfptr;
    if ( vfptr )
    {
      v22 = vfptr->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v22->mNext = &__that.a.obj;
      __that.a.obj.mPrev = v22;
      __that.a.obj.mNext = &vfptr->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      vfptr->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &__that.a.obj;
    }
    v23 = *(UFG::SimObject **)&thisEvent[2].m_EventUID;
    if ( __that.b.obj.m_pPointer )
    {
      v24 = __that.b.obj.mPrev;
      v25 = __that.b.obj.mNext;
      __that.b.obj.mPrev->mNext = __that.b.obj.mNext;
      v25->mPrev = v24;
      __that.b.obj.mPrev = &__that.b.obj;
      __that.b.obj.mNext = &__that.b.obj;
    }
    __that.b.obj.m_pPointer = v23;
    if ( v23 )
    {
      v26 = v23->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v26->mNext = &__that.b.obj;
      __that.b.obj.mPrev = v26;
      __that.b.obj.mNext = &v23->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v23->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &__that.b.obj;
    }
    __that.contactType = (UFG::CollisionEvent::ContactType)thisEvent[1].vfptr;
    __that.mappedVelocity = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                           *((float *)&thisEvent[1].m_EventUID + 1)
                                         / UFG::TidoGame::sm_MaxCollisionVelocity) & _xmm)
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
      UFG::AudioEventHandler::m_collisionList.mNode.mPrev->mNext = v4;
      v4->mPrev = v29;
      v4->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList;
      UFG::AudioEventHandler::m_collisionList.mNode.mPrev = v4;
    }
    else if ( UFG::AudioEventHandler::IsValidCollision(&__that) )
    {
      UFG::AudioEventHandler::PlayCollisionEvent(this, &__that);
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
  UFG::OneShotHandle pHandle; // [rsp+48h] [rbp+10h] BYREF

  pHandle.m_pOneShot = 0i64;
  UFG::OneShotPool::GetOneShotHandle(&pHandle, (UFG::qVector3 *)(&thisEvent[1].m_EventUID + 1));
  if ( UFG::OneShotHandle::IsValid(&pHandle) )
  {
    if ( (_S31_1 & 1) == 0 )
    {
      _S31_1 |= 1u;
      velocity_0.mUID = UFG::qWiseSymbolUIDFromString("velocity", 0x811C9DC5);
      _((AMD_HD3D *)velocity_0.mUID);
      atexit(UFG::AudioEventHandler::HandleConstraintEvent_::_4_::_dynamic_atexit_destructor_for__velocity__);
    }
    UFG::AudioEntity::SetRtpcValue(pHandle.m_pOneShot, velocity_0.mUID, *(float *)&thisEvent[1].mUserData0);
    UFG::OneShot::Play(pHandle.m_pOneShot, thisEvent[1].m_EventUID);
  }
  UFG::OneShotHandle::Release(&pHandle);
}

// File Line: 401
// RVA: 0x59F2F0
void __fastcall UFG::AudioEventHandler::HandleScreenMinimizedEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::TiDo *Instance; // rax

  if ( UFG::TiDo::GetIsInstantiated() )
  {
    Instance = UFG::TiDo::GetInstance();
    UFG::TiDo::ScreenMinimized(Instance, 1);
    UFG::MovieHandler::SetVolumeAll(&UFG::TheMovieHandler, 0);
  }
}

// File Line: 410
// RVA: 0x59F330
void __fastcall UFG::AudioEventHandler::HandleScreenRestoredEvent(UFG::AudioEventHandler *this, UFG::Event *thisEvent)
{
  UFG::TiDo *Instance; // rax
  UFG::GameStatTracker *v3; // rax
  int Stat; // eax

  if ( UFG::TiDo::GetIsInstantiated() )
  {
    Instance = UFG::TiDo::GetInstance();
    UFG::TiDo::ScreenMinimized(Instance, 0);
    v3 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v3, VolumeSFX);
    UFG::MovieHandler::SetVolumeAll(&UFG::TheMovieHandler, (int)(float)((float)Stat * 2000.0));
  }
}

// File Line: 427
// RVA: 0x5A5580
void __fastcall UFG::AudioEventHandler::PlayCollisionSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  unsigned int surfProperties; // ebp
  unsigned int audioProperty; // esi
  UFG::CollisionAudioObjectData *p_a; // rdi
  UFG::CollisionAudioObjectData *p_b; // r14
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  UFG::CollisionAudioObjectData *v10; // rcx
  unsigned int v11; // eax
  UFG::CollisionAudioObjectData *v12; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::TransformNodeComponent *ComponentOfType; // rax
  float *v15; // rdi
  unsigned int v16; // eax
  UFG::OneShotHandle pHandle; // [rsp+58h] [rbp+10h] BYREF

  surfProperties = cad->a.surfProperties;
  if ( !surfProperties )
    surfProperties = cad->a.audioProperty;
  audioProperty = cad->b.surfProperties;
  if ( !audioProperty )
    audioProperty = cad->b.audioProperty;
  if ( surfProperties )
  {
    if ( audioProperty )
    {
      p_a = &cad->a;
      if ( cad->a.audioProperty != -974062208
        || cad->b.audioProperty != -974062208 && cad->b.audioProperty != -1793093012 )
      {
        p_b = &cad->b;
        v7 = _S32_0;
        if ( (_S32_0 & 1) != 0 )
        {
          v8 = s_uBodyWholeBody;
        }
        else
        {
          _S32_0 |= 1u;
          v8 = UFG::TiDo::CalcWwiseUid("BODY_WHOLE_BODY");
          s_uBodyWholeBody = v8;
          v7 = _S32_0;
        }
        if ( (v7 & 2) == 0 )
        {
          _S32_0 = v7 | 2;
          s_uObjectCar = UFG::TiDo::CalcWwiseUid("OBJECT_CAR");
          v8 = s_uBodyWholeBody;
        }
        v9 = p_a->surfProperties;
        if ( !v9 )
          v9 = p_a->audioProperty;
        if ( v9 == v8 )
        {
          v10 = p_a;
        }
        else
        {
          v11 = p_b->surfProperties;
          if ( !v11 )
            v11 = p_b->audioProperty;
          if ( v11 != v8 )
            goto LABEL_34;
          v10 = p_b;
        }
        if ( !v10 || !cad->involvesPlayer || audioProperty == 536829512 )
          goto LABEL_34;
        v12 = 0i64;
        if ( v10 == p_a )
          v12 = p_b;
        if ( v10 == p_b )
          v12 = p_a;
        if ( !v12
          || (m_pPointer = v12->obj.m_pPointer) == 0i64
          || (ComponentOfType = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                                                 m_pPointer,
                                                                 UFG::TransformNodeComponent::_TransformNodeComponentTypeUID),
              (v15 = (float *)ComponentOfType) == 0i64)
          || (UFG::TransformNodeComponent::UpdateWorldTransform(ComponentOfType),
              (float)((float)((float)(v15[64] * v15[64]) + (float)(v15[65] * v15[65])) + (float)(v15[66] * v15[66])) >= 1.0) )
        {
LABEL_34:
          pHandle.m_pOneShot = 0i64;
          UFG::OneShotPool::GetOneShotHandle(&pHandle, &cad->position);
          if ( UFG::OneShotHandle::IsValid(&pHandle) )
          {
            v16 = _S32_0;
            if ( (_S32_0 & 4) == 0 )
            {
              _S32_0 |= 4u;
              material1.mUID = UFG::qWiseSymbolUIDFromString("material1", 0x811C9DC5);
              _((AMD_HD3D *)material1.mUID);
              atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_33_::_dynamic_atexit_destructor_for__material1__);
              v16 = _S32_0;
            }
            if ( (v16 & 8) == 0 )
            {
              _S32_0 = v16 | 8;
              material2.mUID = UFG::qWiseSymbolUIDFromString("material2", 0x811C9DC5);
              _((AMD_HD3D *)material2.mUID);
              atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_33_::_dynamic_atexit_destructor_for__material2__);
              v16 = _S32_0;
            }
            if ( (v16 & 0x10) == 0 )
            {
              _S32_0 = v16 | 0x10;
              play_debris_collision.mUID = UFG::qWiseSymbolUIDFromString("play_debris_collision", 0x811C9DC5);
              _((AMD_HD3D *)play_debris_collision.mUID);
              atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_33_::_dynamic_atexit_destructor_for__play_debris_collision__);
            }
            UFG::AudioEntity::SetWwiseSwitch(pHandle.m_pOneShot, material1.mUID, surfProperties);
            UFG::AudioEntity::SetWwiseSwitch(pHandle.m_pOneShot, material2.mUID, audioProperty);
            if ( cad->setVelocity )
            {
              if ( (_S32_0 & 0x20) == 0 )
              {
                _S32_0 |= 0x20u;
                velocity_1.mUID = UFG::qWiseSymbolUIDFromString("velocity", 0x811C9DC5);
                _((AMD_HD3D *)velocity_1.mUID);
                atexit(UFG::AudioEventHandler::PlayCollisionSfx_::_36_::_dynamic_atexit_destructor_for__velocity__);
              }
              UFG::AudioEntity::SetRtpcValue(pHandle.m_pOneShot, velocity_1.mUID, cad->mappedVelocity);
            }
            UFG::OneShot::Play(pHandle.m_pOneShot, play_debris_collision.mUID);
          }
          UFG::OneShotHandle::Release(&pHandle);
        }
      }
    }
  }
}

// File Line: 504
// RVA: 0x5A6E30
void __fastcall UFG::AudioEventHandler::PlayRollingSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v3; // rbx
  unsigned int mUID; // ebp
  UFG::SimObject *m_pPointer; // rsi
  UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *mNext; // rcx
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v8; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *mPrev; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v10; // rcx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v11; // rax

  if ( (_S33_1 & 1) == 0 )
  {
    _S33_1 |= 1u;
    AudioPropertyRolling_0.mUID = UFG::qWiseSymbolUIDFromString("AudioPropertyRolling", 0x811C9DC5);
    _((AMD_HD3D *)AudioPropertyRolling_0.mUID);
    atexit(UFG::AudioEventHandler::PlayRollingSfx_::_2_::_dynamic_atexit_destructor_for__AudioPropertyRolling__);
  }
  v3 = 0i64;
  mUID = 0;
  m_pPointer = 0i64;
  if ( cad->a.obj.m_pPointer )
  {
    mUID = UFG::PhysicsObjectProperties::GetAudioProperty(cad->a.objProperties, &AudioPropertyRolling_0)->mUID;
    m_pPointer = cad->a.obj.m_pPointer;
  }
  if ( cad->b.obj.m_pPointer && !mUID )
  {
    mUID = UFG::PhysicsObjectProperties::GetAudioProperty(cad->b.objProperties, &AudioPropertyRolling_0)->mUID;
    m_pPointer = cad->b.obj.m_pPointer;
  }
  mNext = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext;
  if ( (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext == &UFG::PersistentCollisionManager::smCollisionList )
  {
LABEL_13:
    if ( mUID - 1 <= 0xFFFFFFFD )
    {
      v7 = UFG::qMalloc(0x20ui64, "PersistentAudioCollision", 0i64);
      if ( v7 )
      {
        UFG::PersistentEventItem::PersistentEventItem((UFG::PersistentEventItem *)v7, m_pPointer, &cad->position);
        v3 = v8;
      }
      if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)v3 + 3) )
      {
        if ( (_S33_1 & 2) == 0 )
        {
          _S33_1 |= 2u;
          rolling_speed.mUID = UFG::qWiseSymbolUIDFromString("rolling_speed", 0x811C9DC5);
          _((AMD_HD3D *)rolling_speed.mUID);
          atexit(UFG::AudioEventHandler::PlayRollingSfx_::_14_::_dynamic_atexit_destructor_for__rolling_speed__);
        }
        UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)v3[3], rolling_speed.mUID, cad->mappedVelocity);
        UFG::OneShot::Play((UFG::OneShot *)v3[3], mUID);
        mPrev = UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev;
        UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        *v3 = mPrev;
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
    while ( (UFG::SimObject *)mNext[1].mNode.mPrev != m_pPointer )
    {
      mNext = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)mNext->mNode.mNext;
      if ( mNext == &UFG::PersistentCollisionManager::smCollisionList )
        goto LABEL_13;
    }
    UFG::PersistentCollisionManager::UpdateCollision((UFG::PersistentEventItem *)mNext, cad);
  }
}entCollisionManager::UpdateCollision((UFG::PersistentEventItem *)mNext, ca

// File Line: 555
// RVA: 0x5A76D0
void __fastcall UFG::AudioEventHandler::PlaySlidingSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v3; // rbx
  unsigned int mUID; // ebp
  UFG::SimObject *m_pPointer; // rsi
  UFG::qWiseSymbol *AudioProperty; // rax
  UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *mNext; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> **v9; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *mPrev; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v11; // rcx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v12; // rax

  if ( (_S34_0 & 1) == 0 )
  {
    _S34_0 |= 1u;
    AudioPropertySliding.mUID = UFG::qWiseSymbolUIDFromString("AudioPropertySliding", 0x811C9DC5);
    _((AMD_HD3D *)AudioPropertySliding.mUID);
    atexit(UFG::AudioEventHandler::PlaySlidingSfx_::_2_::_dynamic_atexit_destructor_for__AudioPropertySliding__);
  }
  v3 = 0i64;
  mUID = 0;
  m_pPointer = 0i64;
  if ( cad->a.obj.m_pPointer )
  {
    AudioProperty = UFG::PhysicsObjectProperties::GetAudioProperty(cad->a.objProperties, &AudioPropertySliding);
    m_pPointer = cad->a.obj.m_pPointer;
  }
  else
  {
    if ( !cad->b.obj.m_pPointer )
      goto LABEL_8;
    AudioProperty = UFG::PhysicsObjectProperties::GetAudioProperty(cad->a.objProperties, &AudioPropertySliding);
    m_pPointer = cad->b.obj.m_pPointer;
  }
  mUID = AudioProperty->mUID;
LABEL_8:
  mNext = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext;
  if ( (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext == &UFG::PersistentCollisionManager::smCollisionList )
  {
LABEL_13:
    if ( mUID - 1 <= 0xFFFFFFFD )
    {
      v8 = UFG::qMalloc(0x20ui64, "PersistentAudioCollision", 0i64);
      if ( v8 )
      {
        UFG::PersistentEventItem::PersistentEventItem((UFG::PersistentEventItem *)v8, m_pPointer, &cad->position);
        v3 = v9;
      }
      if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)v3 + 3) )
      {
        UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)v3[3], 0x6991FE50u, cad->mappedVelocity);
        UFG::OneShot::Play((UFG::OneShot *)v3[3], mUID);
        mPrev = UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev;
        UFG::PersistentCollisionManager::smCollisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)v3;
        *v3 = mPrev;
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
    while ( (UFG::SimObject *)mNext[1].mNode.mPrev != m_pPointer )
    {
      mNext = (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)mNext->mNode.mNext;
      if ( mNext == &UFG::PersistentCollisionManager::smCollisionList )
        goto LABEL_13;
    }
    UFG::PersistentCollisionManager::UpdateCollision((UFG::PersistentEventItem *)mNext, cad);
  }
}

// File Line: 610
// RVA: 0x5A4E00
void __fastcall UFG::AudioEventHandler::PlayBulletSfx(UFG::AudioEventHandler *this, UFG::CollisionAudioData *cad)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *v4; // rdi
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  unsigned int v7; // ecx
  UFG::AudioEntity *m_SFXEntity; // rdi
  unsigned int v9; // eax
  unsigned int audioProperty; // r8d
  float y; // xmm0_4
  float z; // xmm1_4
  unsigned int surfProperties; // r8d
  UFG::OneShotHandle pHandle; // [rsp+58h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectCharacter *)cad->a.obj.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = _S35_1;
  if ( (_S35_1 & 1) == 0 )
  {
    _S35_1 |= 1u;
    play_gp_bullet_impacts = UFG::TiDo::CalcWwiseUid("play_gp_bullet_impacts");
    v7 = _S35_1;
  }
  if ( v4 && (m_SFXEntity = v4->m_SFXEntity) != 0i64 )
  {
    if ( LocalPlayer == cad->a.obj.m_pPointer )
    {
      if ( (v7 & 2) != 0 )
      {
        v9 = player_rumble;
      }
      else
      {
        _S35_1 = v7 | 2;
        v9 = UFG::TiDo::CalcWwiseUid("Play_gun_hit_motion");
        player_rumble = v9;
      }
      UFG::AudioEntity::CreateAndPlayEvent(m_SFXEntity, v9, 0i64, 0, 0i64);
    }
    audioProperty = cad->a.audioProperty;
    if ( audioProperty || cad->a.surfProperties )
    {
      if ( cad->a.surfProperties )
        audioProperty = cad->a.surfProperties;
      UFG::AudioEntity::SetWwiseSwitch(m_SFXEntity, 0xF17446D7, audioProperty);
      y = cad->position.y;
      z = cad->position.z;
      m_SFXEntity->m_WorldMatrix.v3.x = cad->position.x;
      m_SFXEntity->m_WorldMatrix.v3.y = y;
      m_SFXEntity->m_WorldMatrix.v3.z = z;
      m_SFXEntity->m_WorldMatrix.v3.w = 1.0;
      UFG::AudioEntity::ForcePositionUpdate(m_SFXEntity);
      UFG::AudioEntity::CreateAndPlayEvent(m_SFXEntity, play_gp_bullet_impacts, 0i64, 0, 0i64);
    }
  }
  else if ( cad->a.audioProperty || cad->a.surfProperties )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &cad->position);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      surfProperties = cad->a.surfProperties;
      if ( !surfProperties )
        surfProperties = cad->a.audioProperty;
      UFG::AudioEntity::SetWwiseSwitch(pHandle.m_pOneShot, 0xF17446D7, surfProperties);
      UFG::OneShot::Play(pHandle.m_pOneShot, play_gp_bullet_impacts);
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 658
// RVA: 0x5A06A0
char __fastcall UFG::AudioEventHandler::IsValidCollision(UFG::CollisionAudioData *cad)
{
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *mNext; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rcx
  UFG::allocator::free_link *v7; // rax
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *mPrev; // rax

  mNext = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
  if ( (UFG::qList<UFG::CollisionAudioData,UFG::CollisionAudioData,1,0> *)UFG::AudioEventHandler::m_collisionList.mNode.mNext == &UFG::AudioEventHandler::m_collisionList )
  {
LABEL_6:
    v4 = UFG::qMalloc(0x98ui64, "Audio.CollisionRecord", 0i64);
    v5 = v4;
    if ( v4 )
    {
      v4->mNext = v4;
      v4[1].mNext = v4;
      v6 = v4 + 2;
      LODWORD(v4[2].mNext) = 0;
      v7 = v4 + 3;
      v7->mNext = v7;
      v7[1].mNext = v7;
      v7[2].mNext = 0i64;
      v6[4].mNext = 0i64;
      LODWORD(v5[8].mNext) = 0;
      v5[9].mNext = v5 + 9;
      v5[10].mNext = v5 + 9;
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
    UFG::CollisionAudioData::operator=((UFG::CollisionAudioData *)v5, cad);
    mPrev = UFG::AudioEventHandler::m_collisionList.mNode.mPrev;
    UFG::AudioEventHandler::m_collisionList.mNode.mPrev->mNext = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)v5;
    v5->mNext = (UFG::allocator::free_link *)mPrev;
    v5[1].mNext = (UFG::allocator::free_link *)&UFG::AudioEventHandler::m_collisionList;
    UFG::AudioEventHandler::m_collisionList.mNode.mPrev = (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)v5;
    return 1;
  }
  else
  {
    while ( (float)((float)((float)((float)(cad->position.x - *((float *)&mNext[8].mNext + 1))
                                  * (float)(cad->position.x - *((float *)&mNext[8].mNext + 1)))
                          + (float)((float)(cad->position.y - *(float *)&mNext[9].mPrev)
                                  * (float)(cad->position.y - *(float *)&mNext[9].mPrev)))
                  + (float)((float)(cad->position.z - *((float *)&mNext[9].mPrev + 1))
                          * (float)(cad->position.z - *((float *)&mNext[9].mPrev + 1)))) >= UFG::TidoGame::sm_minCollisionSeparation )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList )
        goto LABEL_6;
    }
    return 0;
  }
}

// File Line: 749
// RVA: 0x5AEE70
void __fastcall UFG::AudioEventHandler::Update(UFG::AudioEventHandler *this, float delta_sec)
{
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *mNext; // rbx
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v4; // rdx
  int v5; // r9d
  bool v6; // r8
  bool v7; // cl
  bool v8; // zf
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v9; // r9
  char v10; // r10
  UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *v11; // r8
  float v12; // xmm0_4
  int v13; // ecx
  int v14; // eax

  if ( UFG::TidoGame::sm_useCollisionAveraging )
  {
    mNext = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
    v4 = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
    if ( (UFG::qList<UFG::CollisionAudioData,UFG::CollisionAudioData,1,0> *)UFG::AudioEventHandler::m_collisionList.mNode.mNext != &UFG::AudioEventHandler::m_collisionList )
    {
      do
      {
        if ( BYTE3(v4[7].mPrev)
          && mNext != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList )
        {
          do
          {
            if ( v4 != mNext )
            {
              v5 = (int)v4[3].mNext;
              v6 = 0;
              v7 = 0;
              if ( v5 == LODWORD(mNext[3].mNext) )
                v6 = LODWORD(v4[6].mNext) == LODWORD(mNext[6].mNext);
              v8 = v5 == LODWORD(mNext[6].mNext);
              v9 = v4[2].mNext;
              v10 = v6;
              v11 = mNext[2].mNext;
              if ( v8 )
                v10 = 1;
              if ( v11 == v9 )
                v7 = mNext[5].mNext == v4[5].mNext;
              if ( v11 == v4[5].mNext && mNext[5].mNext == v9 )
                v7 = 1;
              if ( v10 && v7 )
              {
                ++HIDWORD(v4[8].mPrev);
                v12 = *((float *)&v4[7].mNext + 1);
                if ( v12 <= *((float *)&mNext[7].mPrev + 1) )
                  v12 = *((float *)&mNext[7].mPrev + 1);
                *((float *)&v4[7].mNext + 1) = v12;
                v13 = (int)mNext[8].mNext;
                BYTE3(mNext[7].mPrev) = 0;
                v14 = (int)v4[8].mNext;
                if ( v14 != v13 && (!v14 || !v13) )
                  LODWORD(v4[8].mNext) = 0;
              }
            }
            mNext = mNext->mNext;
          }
          while ( mNext != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList );
          mNext = UFG::AudioEventHandler::m_collisionList.mNode.mNext;
        }
        v4 = v4->mNext;
      }
      while ( v4 != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList );
      for ( ;
            mNext != (UFG::qNode<UFG::CollisionAudioData,UFG::CollisionAudioData> *)&UFG::AudioEventHandler::m_collisionList;
            mNext = mNext->mNext )
      {
        UFG::AudioEventHandler::PlayCollisionEvent(this, (UFG::CollisionAudioData *)mNext);
      }
    }
  }
}

// File Line: 797
// RVA: 0x1554AE0
__int64 dynamic_initializer_for__UFG::PersistentCollisionManager::smCollisionList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PersistentCollisionManager::smCollisionList__);
}

// File Line: 817
// RVA: 0x59BED0
UFG::PersistentEventItem *__fastcall UFG::PersistentCollisionManager::FindCollision(UFG::OneShot *obj)
{
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *mNext; // rbx

  mNext = UFG::PersistentCollisionManager::smCollisionList.mNode.mNext;
  if ( (UFG::qList<UFG::PersistentEventItem,UFG::PersistentEventItem,1,0> *)UFG::PersistentCollisionManager::smCollisionList.mNode.mNext == &UFG::PersistentCollisionManager::smCollisionList )
    return 0i64;
  while ( !UFG::OneShotHandle::OwnsOneShot((UFG::OneShotHandle *)&mNext[1].mNext, obj) )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *)&UFG::PersistentCollisionManager::smCollisionList )
      return 0i64;
  }
  return (UFG::PersistentEventItem *)mNext;
}

// File Line: 833
// RVA: 0x5B0150
void __fastcall UFG::PersistentCollisionManager::UpdateCollision(
        UFG::PersistentEventItem *item,
        UFG::CollisionAudioData *cad)
{
  UFG::OneShotHandle *p_m_pOneShot; // rbx
  UFG::AudioEntity *m_pOneShot; // rcx
  float y; // xmm0_4
  float z; // xmm1_4

  p_m_pOneShot = &item->m_pOneShot;
  if ( UFG::OneShotHandle::IsValid(&item->m_pOneShot) )
  {
    m_pOneShot = p_m_pOneShot->m_pOneShot;
    if ( p_m_pOneShot->m_pOneShot->mPrev == &p_m_pOneShot->m_pOneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>
      && p_m_pOneShot->m_pOneShot->mNext == &p_m_pOneShot->m_pOneShot->UFG::qNode<UFG::OneShot,UFG::OneShot> )
    {
      if ( m_pOneShot[1].mNext )
      {
        y = cad->position.y;
        z = cad->position.z;
        m_pOneShot->m_WorldMatrix.v3.x = cad->position.x;
        m_pOneShot->m_WorldMatrix.v3.w = 1.0;
        m_pOneShot->m_WorldMatrix.v3.y = y;
        m_pOneShot->m_WorldMatrix.v3.z = z;
        UFG::AudioEntity::ForcePositionUpdate(m_pOneShot);
        UFG::AudioEntity::SetRtpcValue(p_m_pOneShot->m_pOneShot, cad->velocityId, cad->mappedVelocity);
        UFG::AudioEvent::TouchUpdate(p_m_pOneShot->m_pOneShot->m_controller.m_pEvent);
      }
    }
  }
}

// File Line: 860
// RVA: 0x5A9EE0
void __fastcall UFG::PersistentCollisionManager::RemoveCollision(UFG::PersistentEventItem *item)
{
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *mPrev; // rdx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *mNext; // rax
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v4; // rcx
  UFG::qNode<UFG::PersistentEventItem,UFG::PersistentEventItem> *v5; // rax

  mPrev = item->mPrev;
  mNext = item->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  item->mPrev = item;
  item->mNext = item;
  UFG::OneShotHandle::Release(&item->m_pOneShot);
  v4 = item->mPrev;
  v5 = item->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  item->mPrev = item;
  item->mNext = item;
  operator delete[](item);
  --UFG::PersistentCollisionManager::sm_numPersistentEvents;
}

