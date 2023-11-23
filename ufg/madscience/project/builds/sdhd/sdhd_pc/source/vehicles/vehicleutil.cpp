// File Line: 57
// RVA: 0x67A130
UFG::TransformNodeComponent *__fastcall UFG::VehicleUtility::GetChaseSpawnTransform(
        UFG::SimObjectGame *chasee,
        float distance_behind)
{
  signed __int16 m_Flags; // dx
  UFG::VehicleDriverInterface *ComponentOfTypeHK; // rax

  if ( chasee
    && ((m_Flags = chasee->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                chasee,
                                                                UFG::VehicleDriverInterface::_TypeUID))
        : (ComponentOfTypeHK = (UFG::VehicleDriverInterface *)UFG::SimObject::GetComponentOfType(
                                                                chasee,
                                                                UFG::VehicleDriverInterface::_TypeUID)))
       : (ComponentOfTypeHK = (UFG::VehicleDriverInterface *)chasee->m_Components.p[23].m_pComponent))
      : (ComponentOfTypeHK = (UFG::VehicleDriverInterface *)chasee->m_Components.p[23].m_pComponent),
        ComponentOfTypeHK) )
  {
    return UFG::VehicleDriverInterface::GetChaseSpawnTransform(ComponentOfTypeHK, distance_behind);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 66
// RVA: 0x6782B0
void __fastcall UFG::VehicleUtility::ExitVehicleNoAnim(UFG::SimObjectCVBase *character)
{
  ActionNode *v2; // r14
  signed __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *v4; // rax
  UFG::TargetingSystemPedBaseComponent *v5; // rbp
  signed __int16 v6; // cx
  UFG::ActionTreeComponent *m_pComponent; // rsi
  UFG::ActionTreeComponent *v8; // rax
  signed __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  Expression::IMemberMap *v11; // r15
  ActionNodeRoot *v12; // rdi
  ActionContext *mpActionContext; // rdx
  __int64 mValue; // rax
  UFG::ActionTreeComponentBase *v15; // rcx
  ActionNodePlayable *v16; // r14
  UEL::ParametersBase *v17; // r15
  signed __int16 v18; // dx
  UFG::UELComponent *ComponentOfTypeHK; // rax
  bool v20; // di

  if ( (_S20_3 & 1) == 0 )
  {
    _S20_3 |= 1u;
    genericExit.mPath.mCount = 0;
    genericExit.mPath.mData.mOffset = 0i64;
    ActionPath::Append(
      &genericExit,
      "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\HelperFunctions\\SeatDetach\\Immediate");
    atexit(UFG::VehicleUtility::ExitVehicleNoAnim_::_2_::_dynamic_atexit_destructor_for__genericExit__);
  }
  v2 = ActionNode::Find(&genericExit, 0i64);
  if ( character )
  {
    m_Flags = character->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(character);
    else
      v4 = (UFG::TargetingSystemPedBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      character,
                                                      UFG::TargetingSystemPedBaseComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      character,
                                                      UFG::TargetingSystemPedBaseComponent::_TypeUID));
    v5 = v4;
    v6 = character->m_Flags;
    if ( (v6 & 0x4000) != 0 )
    {
      m_pComponent = (UFG::ActionTreeComponent *)character->m_Components.p[7].m_pComponent;
    }
    else if ( v6 >= 0 )
    {
      if ( (v6 & 0x2000) != 0 )
      {
        m_pComponent = (UFG::ActionTreeComponent *)character->m_Components.p[6].m_pComponent;
      }
      else
      {
        v8 = (UFG::ActionTreeComponent *)((v6 & 0x1000) != 0
                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                            character,
                                            UFG::ActionTreeComponent::_TypeUID)
                                        : UFG::SimObject::GetComponentOfType(
                                            character,
                                            UFG::ActionTreeComponent::_TypeUID));
        m_pComponent = v8;
      }
    }
    else
    {
      m_pComponent = (UFG::ActionTreeComponent *)character->m_Components.p[7].m_pComponent;
    }
    v9 = character->m_Flags;
    if ( (v9 & 0x4000) != 0 )
      v10 = character->m_Components.p[44].m_pComponent;
    else
      v10 = v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(character, UFG::CharacterOccupantComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(character, UFG::CharacterOccupantComponent::_TypeUID);
    if ( v5 && m_pComponent && v2 && v10 )
    {
      v11 = m_pComponent->mpActionContext->m_OpeningBranch->vfptr[1].GetResourceOwner(m_pComponent->mpActionContext->m_OpeningBranch);
      v12 = (ActionNodeRoot *)v2->vfptr[1].GetResourceOwner(v2);
      mpActionContext = m_pComponent->mpActionContext;
      mValue = v12->mActionTreeType.mValue;
      if ( (mpActionContext->mActionTreeComponentBase[mValue] || mpActionContext->mActionTreeComponentBase[1])
        && v11 != v12 )
      {
        v15 = mpActionContext->mActionTreeComponentBase[mValue];
        if ( !v15 )
          v15 = mpActionContext->mActionTreeComponentBase[1];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v15, v12) )
          ActionNodeRoot::Init(v12, m_pComponent->mpActionContext);
      }
      v16 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))v2->vfptr[2].GetClassNameUID)(
                                    v2,
                                    m_pComponent->mpActionContext);
      if ( v16 )
      {
        v17 = UEL::gCurrentParameters;
        v18 = character->m_Flags;
        if ( (v18 & 0x4000) != 0 )
        {
          ComponentOfTypeHK = (UFG::UELComponent *)character->m_Components.p->m_pComponent;
        }
        else if ( v18 >= 0 )
        {
          if ( (v18 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = (UFG::UELComponent *)character->m_Components.p->m_pComponent;
          }
          else if ( (v18 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::UELComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       character,
                                                       UFG::UELComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::UELComponent *)UFG::SimObject::GetComponentOfType(
                                                       character,
                                                       UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          ComponentOfTypeHK = (UFG::UELComponent *)character->m_Components.p->m_pComponent;
        }
        if ( ComponentOfTypeHK )
          UEL::gCurrentParameters = &ComponentOfTypeHK->mParameters;
        v20 = m_pComponent->mActionController.mKeepAlive != 0;
        m_pComponent->mActionController.mKeepAlive = 0;
        ActionController::Play(&m_pComponent->mActionController, v16);
        ActionController::Update(&m_pComponent->mActionController, 0.0);
        m_pComponent->mActionController.mKeepAlive = v20;
        UEL::gCurrentParameters = v17;
      }
      UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v5);
    }
  }
}

// File Line: 139
// RVA: 0x6864B0
void __fastcall UFG::VehicleUtility::PlaceCharacterInVehicle(
        UFG::SimObjectCharacter *character,
        UFG::SimObjectVehicle *vehicle,
        unsigned int eRole,
        bool addAI,
        bool destroyEquipped,
        bool ignoreRoleGetInFirstEmptyPassengerSeat)
{
  __int64 v7; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::ActionTreeComponent *m_pComponent; // r13
  UFG::Event *v12; // rdi
  UFG::SimObjectVehiclePropertiesComponent *v13; // r15
  unsigned int v14; // ecx
  ActionPath *v15; // rbp
  ActionNode *v16; // r15
  UFG::TargetingSystemPedBaseComponent *v17; // rbp
  UFG::SimObject *m_pPointer; // rcx
  UFG::TargetingSystemVehicleComponent *v19; // rax
  UFG::TargetingSystemBaseComponent *v20; // r10
  UFG::TargetingMap *m_pTargetingMap; // r8
  UFG::TargetingSimObject *m_pTargets; // r9
  UFG::SimObjectCharacter *v23; // rax
  UFG::SimObjectCharacter *v24; // rcx
  UFG::allocator::free_link *v25; // rbp
  unsigned int mUID; // ebx
  UFG::Event *v27; // rax
  Expression::IMemberMap *v28; // rdi
  ActionNodeRoot *v29; // rax
  ActionNodeRoot *v30; // rbx
  ActionContext *mpActionContext; // rdx
  __int64 mValue; // r9
  UFG::ActionTreeComponentBase *v33; // rcx
  ActionNodePlayable *v34; // rbp
  UFG::AICharacterControllerBaseComponent *v35; // rax
  UEL::ParametersBase *v36; // r15
  UFG::SimComponent *v37; // rax
  bool v38; // di
  UFG::SimComponent *v39; // rcx
  UFG::RagdollComponent *v40; // rcx
  UFG::VehicleDriverInterface *v41; // rcx
  UFG::SimComponent *v42; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ChaseCameraComponent *ComponentOfType; // rax
  UFG::TargetingSystemPedBaseComponent *v45; // [rsp+40h] [rbp-58h]
  UFG::TransformNodeComponent *v46; // [rsp+A0h] [rbp+8h]
  bool bDriver; // [rsp+B0h] [rbp+18h]

  v7 = eRole;
  if ( character )
  {
    Instance = UFG::PedSpawnManager::GetInstance();
    if ( !UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
            Instance,
            Active,
            character,
            "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\source\\vehicles\\vehicleutil.cpp",
            140) )
      UFG::SimObject::Restore(character);
  }
  bDriver = (_DWORD)v7 == 4;
  if ( character )
  {
    v45 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(character);
    if ( v45 )
    {
      m_pComponent = (UFG::ActionTreeComponent *)character->m_Components.p[7].m_pComponent;
      if ( m_pComponent )
      {
        v12 = 0i64;
        if ( vehicle )
        {
          v46 = (UFG::TransformNodeComponent *)vehicle->m_Components.p[2].m_pComponent;
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(vehicle);
        }
        else
        {
          v46 = 0i64;
          v13 = 0i64;
        }
        if ( addAI && (_DWORD)v7 == 4 )
          UFG::VehicleUtility::ClearDriver(vehicle);
        v14 = _S21_3;
        if ( (_S21_3 & 1) == 0 )
        {
          _S21_3 |= 1u;
          carDriverAnimationName.mPath.mCount = 0;
          carDriverAnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(&carDriverAnimationName, "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Driver");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carDriverAnimationName__);
          v14 = _S21_3;
        }
        v15 = &carFirstAvailablePassengerAnimationName;
        if ( (v14 & 2) == 0 )
        {
          _S21_3 = v14 | 2;
          carFirstAvailablePassengerAnimationName.mPath.mCount = 0;
          carFirstAvailablePassengerAnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(
            &carFirstAvailablePassengerAnimationName,
            "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Passenger");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carFirstAvailablePassengerAnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 4) == 0 )
        {
          _S21_3 = v14 | 4;
          carPassenger1AnimationName.mPath.mCount = 0;
          carPassenger1AnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(
            &carPassenger1AnimationName,
            "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Passenger\\Passenger1");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carPassenger1AnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 8) == 0 )
        {
          _S21_3 = v14 | 8;
          carPassenger2AnimationName.mPath.mCount = 0;
          carPassenger2AnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(
            &carPassenger2AnimationName,
            "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Passenger\\Passenger2");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carPassenger2AnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 0x10) == 0 )
        {
          _S21_3 = v14 | 0x10;
          carPassenger3AnimationName.mPath.mCount = 0;
          carPassenger3AnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(
            &carPassenger3AnimationName,
            "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Passenger\\Passenger3");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carPassenger3AnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 0x20) == 0 )
        {
          _S21_3 = v14 | 0x20;
          carPassenger4AnimationName.mPath.mCount = 0;
          carPassenger4AnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(
            &carPassenger4AnimationName,
            "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Passenger\\Passenger4");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carPassenger4AnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 0x40) == 0 )
        {
          _S21_3 = v14 | 0x40;
          bikeDriverAnimationName.mPath.mCount = 0;
          bikeDriverAnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(&bikeDriverAnimationName, "\\Global\\Bike\\Interactions\\Vehicle\\GetOnNoAnim");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__bikeDriverAnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 0x80u) == 0 )
        {
          _S21_3 = v14 | 0x80;
          bikePassengerAnimationName.mPath.mCount = 0;
          bikePassengerAnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(&bikePassengerAnimationName, "\\Global\\Bike\\Interactions\\Vehicle\\GetPassengerOnNoAnim");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__bikePassengerAnimationName__);
          v14 = _S21_3;
        }
        if ( (v14 & 0x100) == 0 )
        {
          _S21_3 = v14 | 0x100;
          scooterDriverAnimationName.mPath.mCount = 0;
          scooterDriverAnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(
            &scooterDriverAnimationName,
            "\\Global\\Scooter\\Interactions\\MasterSpawn\\Vehicle\\GetIN\\HelperFunctions\\GetInNoAnim");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__scooterDriverAnimationName__);
        }
        if ( v13 )
        {
          if ( v13->m_eSimObjectVehicleType == eSIM_OBJ_VEHICLE_TYPE_BIKE )
          {
            v15 = &bikePassengerAnimationName;
            if ( (_DWORD)v7 == 4 )
              v15 = &bikeDriverAnimationName;
          }
          else if ( v13->m_eSimObjectVehicleType == eSIM_OBJ_VEHICLE_TYPE_SCOOTER )
          {
            v15 = &scooterDriverAnimationName;
          }
          else if ( (_DWORD)v7 == 4 || !ignoreRoleGetInFirstEmptyPassengerSeat )
          {
            switch ( (_DWORD)v7 )
            {
              case 4:
                v15 = &carDriverAnimationName;
                break;
              case 5:
                v15 = &carPassenger1AnimationName;
                break;
              case 6:
                v15 = &carPassenger2AnimationName;
                break;
              case 7:
                v15 = &carPassenger3AnimationName;
                break;
              case 8:
                v15 = &carPassenger4AnimationName;
                break;
              default:
                return;
            }
          }
          v16 = ActionNode::Find(v15, 0i64);
          if ( v16 )
          {
            v17 = v45;
            UFG::TargetingSystemBaseComponent::SetTarget(v45, 0x28u, vehicle);
            UFG::TargetingSystemBaseComponent::SetTarget(v45, 0x1Cu, vehicle);
            ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, __int64, __int64))v17->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
              v17,
              0x28i64,
              1i64);
            ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, __int64, __int64))v17->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
              v17,
              0x1Ci64,
              1i64);
            if ( destroyEquipped )
            {
              m_pPointer = v45->m_pTargets[(unsigned __int8)v45->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
              if ( m_pPointer )
                UFG::SimObject::Destroy(m_pPointer);
            }
            if ( vehicle )
            {
              v19 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(vehicle);
              v20 = v19;
              if ( v19 )
              {
                m_pTargetingMap = v19->m_pTargetingMap;
                m_pTargets = v19->m_pTargets;
                v23 = (UFG::SimObjectCharacter *)m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[v7]].m_pTarget.m_pPointer;
                if ( !v23 || v23 == character )
                  goto LABEL_64;
                if ( (_DWORD)v7 != 4 && ignoreRoleGetInFirstEmptyPassengerSeat )
                {
                  LODWORD(v7) = 5;
                  v24 = (UFG::SimObjectCharacter *)m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[5]].m_pTarget.m_pPointer;
                  if ( !v24 )
                    goto LABEL_64;
                  do
                  {
                    if ( v24 == character )
                      break;
                    if ( (int)v7 > 8 )
                      return;
                    v7 = (unsigned int)(unsigned __int8)v7 + 1;
                    v24 = (UFG::SimObjectCharacter *)m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[v7]].m_pTarget.m_pPointer;
                  }
                  while ( v24 );
                  if ( (int)v7 <= 8 )
                  {
LABEL_64:
                    UFG::TargetingSystemBaseComponent::SetTarget(v20, v7, character);
                    UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v45);
                    v25 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                    if ( v25 )
                    {
                      mUID = character->mNode.mUID;
                      UFG::TransformNodeComponent::UpdateWorldTransform(v46);
                      UFG::TeleportEvent::TeleportEvent(
                        (UFG::TeleportEvent *)v25,
                        (UFG::qVector3 *)&v46->mWorldTransform.v3,
                        mUID,
                        0,
                        UFG::TeleportEvent::m_Name,
                        0);
                      v12 = v27;
                    }
                    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v12);
                    v28 = m_pComponent->mpActionContext->m_OpeningBranch->vfptr[1].GetResourceOwner(m_pComponent->mpActionContext->m_OpeningBranch);
                    v29 = (ActionNodeRoot *)v16->vfptr[1].GetResourceOwner(v16);
                    v30 = v29;
                    mpActionContext = m_pComponent->mpActionContext;
                    mValue = v29->mActionTreeType.mValue;
                    if ( (mpActionContext->mActionTreeComponentBase[mValue]
                       || mpActionContext->mActionTreeComponentBase[1])
                      && v28 != v29 )
                    {
                      v33 = mpActionContext->mActionTreeComponentBase[mValue];
                      if ( !v33 )
                        v33 = mpActionContext->mActionTreeComponentBase[1];
                      if ( UFG::ActionTreeComponentBase::AllocateFor(v33, v29) )
                        ActionNodeRoot::Init(v30, m_pComponent->mpActionContext);
                    }
                    v34 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))v16->vfptr[2].GetClassNameUID)(
                                                  v16,
                                                  m_pComponent->mpActionContext);
                    if ( v34 )
                    {
                      if ( UFG::IsAnyLocalPlayer(character) )
                        UFG::FollowCameraComponent::SetForceSnapOnEvent(1);
                      PropertyUtils::SetRuntime<bool>(
                        character->m_pSceneObj,
                        (UFG::qArray<unsigned long,0> *)&qSymbol_GetInParam_VehicleInteractSkipSettingUpAI,
                        1);
                      v35 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(character);
                      if ( v35 )
                      {
                        Intention::Set(&v35->m_Intention, gActionRequest_EnterVehicleForced.m_EnumValue, 0.0);
                        v36 = UEL::gCurrentParameters;
                        v37 = character->m_Components.p->m_pComponent;
                        if ( v37 )
                          UEL::gCurrentParameters = (UEL::ParametersBase *)&v37[1].m_TypeUID;
                        v38 = m_pComponent->mActionController.mKeepAlive != 0;
                        m_pComponent->mActionController.mKeepAlive = 0;
                        ActionController::Stop(&m_pComponent->mActionController);
                        ActionController::Play(&m_pComponent->mActionController, v34);
                        ActionController::Update(&m_pComponent->mActionController, 0.0);
                        m_pComponent->mActionController.mKeepAlive = v38;
                        UEL::gCurrentParameters = v36;
                        v39 = character->m_Components.p[13].m_pComponent;
                        if ( v39 )
                          LOBYTE(v39[4].m_BoundComponentHandles.mNode.mNext) |= 4u;
                        PropertyUtils::SetRuntime<bool>(
                          character->m_pSceneObj,
                          (UFG::qArray<unsigned long,0> *)&qSymbol_GetInParam_VehicleInteractSkipSettingUpAI,
                          0);
                        v40 = (UFG::RagdollComponent *)character->m_Components.p[42].m_pComponent;
                        if ( v40 )
                          UFG::RagdollComponent::ResetState(v40);
                        if ( !bDriver )
                          goto LABEL_90;
                        if ( addAI )
                          UFG::VehicleUtility::SetAIDriver(character, vehicle, 0);
                        v41 = (UFG::VehicleDriverInterface *)vehicle->m_Components.p[23].m_pComponent;
                        if ( !v41 )
                        {
                          v42 = UFG::VehicleUtility::SetRemoteDriver(vehicle);
                          if ( !v42 )
                          {
LABEL_90:
                            if ( UFG::IsAnyLocalPlayer(character) )
                            {
                              UFG::FollowCameraComponent::SetForceSnapOnEvent(0);
                              m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
                              if ( m_pSimObject )
                              {
                                ComponentOfType = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                                                 m_pSimObject,
                                                                                 UFG::ChaseCameraComponent::_TypeUID);
                                if ( ComponentOfType )
                                  UFG::ChaseCameraComponent::LockEye(ComponentOfType, 0);
                              }
                            }
                            return;
                          }
                          v41 = (UFG::VehicleDriverInterface *)v42;
                        }
                        UFG::VehicleDriverInterface::SetDriver(v41, character);
                        goto LABEL_90;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 461
// RVA: 0x686060
void __fastcall UFG::VehicleUtility::PlaceCharacterInTrunk(
        UFG::SimObjectCVBase *character,
        UFG::SimObjectVehicle *vehicle)
{
  UFG::Event *v4; // rbp
  UFG::TargetingSystemBaseComponent *v5; // rbx
  UFG::SimComponent *m_pComponent; // rsi
  signed __int16 m_Flags; // cx
  UFG::TargetingSystemPedBaseComponent *ComponentOfTypeHK; // rax
  signed __int16 v9; // cx
  UFG::SimComponent *ComponentOfType; // rax
  signed __int16 v11; // cx
  UFG::SimComponent *v12; // r13
  UFG::SimObjectVehiclePropertiesComponent *v13; // r14
  ActionNode *v14; // rax
  ActionNode *v15; // r14
  UFG::allocator::free_link *v16; // r15
  unsigned int mUID; // ebx
  UFG::Event *v18; // rax
  __int64 v19; // rbp
  ActionNodeRoot *v20; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdx
  __int64 mValue; // rax
  UFG::ActionTreeComponentBase *mPrev; // rcx
  ActionNodePlayable *v24; // rbp
  UEL::ParametersBase *v25; // r14
  signed __int16 v26; // dx
  UFG::SimComponent *v27; // rax
  bool v28; // di

  v4 = 0i64;
  if ( character )
  {
    m_Flags = character->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(character);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    character,
                                                                    UFG::TargetingSystemPedBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                    character,
                                                                    UFG::TargetingSystemPedBaseComponent::_TypeUID);
    }
    v5 = ComponentOfTypeHK;
    v9 = character->m_Flags;
    if ( (v9 & 0x4000) != 0 )
    {
      m_pComponent = character->m_Components.p[7].m_pComponent;
    }
    else if ( v9 >= 0 )
    {
      if ( (v9 & 0x2000) != 0 )
      {
        m_pComponent = character->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v9 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(character, UFG::ActionTreeComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(character, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
    }
    else
    {
      m_pComponent = character->m_Components.p[7].m_pComponent;
    }
    v11 = character->m_Flags;
    if ( (v11 & 0x4000) == 0 )
    {
      if ( v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
        UFG::SimObjectGame::GetComponentOfTypeHK(character, UFG::CharacterPhysicsComponent::_TypeUID);
      else
        UFG::SimObject::GetComponentOfType(character, UFG::CharacterPhysicsComponent::_TypeUID);
    }
  }
  else
  {
    v5 = 0i64;
    m_pComponent = 0i64;
  }
  if ( vehicle )
  {
    UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(vehicle);
    v12 = vehicle->m_Components.p[2].m_pComponent;
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(vehicle);
  }
  else
  {
    v12 = 0i64;
    v13 = 0i64;
  }
  if ( (_S22_3 & 1) == 0 )
  {
    _S22_3 |= 1u;
    carTrunkPath.mPath.mCount = 0;
    carTrunkPath.mPath.mData.mOffset = 0i64;
    ActionPath::Append(&carTrunkPath, "\\Global\\Vehicle\\Interactions\\Trunk\\Grapple\\PutIn\\ForceInNOANIM");
    atexit(UFG::VehicleUtility::PlaceCharacterInTrunk_::_2_::_dynamic_atexit_destructor_for__carTrunkPath__);
  }
  if ( v13->m_eSimObjectVehicleType != eSIM_OBJ_VEHICLE_TYPE_BIKE
    && v13->m_eSimObjectVehicleType != eSIM_OBJ_VEHICLE_TYPE_SCOOTER
    && (carTrunkPath.mPath.mCount & 0x7FFFFFFF) != 0 )
  {
    v14 = ActionNode::Find(&carTrunkPath, 0i64);
    v15 = v14;
    if ( v5 && m_pComponent && v14 )
    {
      UFG::TargetingSystemBaseComponent::SetTarget(v5, 0x1Cu, vehicle);
      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, __int64))v5->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
        v5,
        28i64,
        1i64);
      v16 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      if ( v16 )
      {
        mUID = character->mNode.mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        UFG::TeleportEvent::TeleportEvent(
          (UFG::TeleportEvent *)v16,
          (UFG::qVector3 *)&v12[2].m_BoundComponentHandles,
          mUID,
          0,
          UFG::TeleportEvent::m_Name,
          0);
        v4 = v18;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v4);
      v19 = ((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))m_pComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext->mPrev[9].mNext)(m_pComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext);
      v20 = (ActionNodeRoot *)v15->vfptr[1].GetResourceOwner(v15);
      mNext = m_pComponent[2].m_BoundComponentHandles.mNode.mNext;
      mValue = v20->mActionTreeType.mValue;
      if ( (*((_QWORD *)&mNext[4].mNext + mValue) || mNext[5].mPrev) && (ActionNodeRoot *)v19 != v20 )
      {
        mPrev = (UFG::ActionTreeComponentBase *)*((_QWORD *)&mNext[4].mNext + mValue);
        if ( !mPrev )
          mPrev = (UFG::ActionTreeComponentBase *)mNext[5].mPrev;
        if ( UFG::ActionTreeComponentBase::AllocateFor(mPrev, v20) )
          ActionNodeRoot::Init(v20, (ActionContext *)m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
      }
      v24 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v15->vfptr[2].GetClassNameUID)(
                                    v15,
                                    m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
      if ( v24 )
      {
        v25 = UEL::gCurrentParameters;
        if ( character )
        {
          v26 = character->m_Flags;
          if ( (v26 & 0x4000) != 0 )
          {
            v27 = character->m_Components.p->m_pComponent;
          }
          else if ( v26 >= 0 )
          {
            if ( (v26 & 0x2000) != 0 )
            {
              v27 = character->m_Components.p->m_pComponent;
            }
            else if ( (v26 & 0x1000) != 0 )
            {
              v27 = UFG::SimObjectGame::GetComponentOfTypeHK(character, UFG::UELComponent::_TypeUID);
            }
            else
            {
              v27 = UFG::SimObject::GetComponentOfType(character, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            v27 = character->m_Components.p->m_pComponent;
          }
          if ( v27 )
            UEL::gCurrentParameters = (UEL::ParametersBase *)&v27[1].m_TypeUID;
        }
        v28 = *((_BYTE *)&m_pComponent[3].m_SimObjIndex + 3) != 0;
        *((_BYTE *)&m_pComponent[3].m_SimObjIndex + 3) = 0;
        ActionController::Play((ActionController *)&m_pComponent[3], v24);
        ActionController::Update((ActionController *)&m_pComponent[3], 0.0);
        *((_BYTE *)&m_pComponent[3].m_SimObjIndex + 3) = v28;
        UEL::gCurrentParameters = v25;
      }
    }
    else
    {
      UFG::qPrintf(
        "PlaceCharacterInTrunk: Could Not Find TargetingSystemPedBaseComponent (0x%x) or ActionTreeComponent (0x%x) or Ac"
        "tion Node (0x%x)\n",
        v5,
        m_pComponent,
        v14);
    }
  }
}

// File Line: 561
// RVA: 0x68A270
UFG::AiDriverComponent *__fastcall UFG::VehicleUtility::SetAIDriver(
        UFG::SimObject *character,
        UFG::SimObjectVehicle *vehicle,
        bool isAmbient)
{
  UFG::HumanDriverComponent *v5; // rax
  UFG::AiDriverComponent *result; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbp
  signed __int16 m_Flags; // cx
  unsigned int v12; // ebx
  unsigned int v13; // esi
  UFG::RoadSpaceComponent *m_pComponent; // rsi
  UFG::qMemoryPool *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::RoadSpaceComponent *v17; // rax
  signed __int16 v18; // cx
  UFG::SimObjectModifier v19; // [rsp+38h] [rbp-30h] BYREF

  if ( !vehicle )
    goto LABEL_5;
  v5 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(vehicle);
  if ( v5 )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v5);
  result = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(vehicle);
  if ( !result )
  {
LABEL_5:
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x628ui64, "AiDriverComponent", 0i64, 1u);
    if ( v8 )
    {
      UFG::AiDriverComponent::AiDriverComponent((UFG::AiDriverComponent *)v8, isAmbient);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    m_Flags = vehicle->m_Flags;
    v12 = -1;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v13 = 23;
    }
    else if ( m_Flags >= 0 )
    {
      v13 = -1;
    }
    else
    {
      v13 = 23;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v19, vehicle, 1);
    UFG::SimObjectModifier::AttachComponent(&v19, (UFG::SimComponent *)v10, v13);
    UFG::SimObjectModifier::Close(&v19);
    UFG::SimObjectModifier::~SimObjectModifier(&v19);
    m_pComponent = (UFG::RoadSpaceComponent *)vehicle->m_Components.p[24].m_pComponent;
    if ( !m_pComponent )
    {
      v15 = UFG::GetSimulationMemoryPool();
      v16 = UFG::qMemoryPool::Allocate(v15, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
      if ( v16 )
      {
        UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v16);
        m_pComponent = v17;
      }
      else
      {
        m_pComponent = 0i64;
      }
      v18 = vehicle->m_Flags;
      if ( (v18 & 0x4000) != 0 )
      {
        v12 = 24;
      }
      else if ( v18 < 0 )
      {
        v12 = 24;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v19, vehicle, 1);
      UFG::SimObjectModifier::AttachComponent(&v19, m_pComponent, v12);
      UFG::SimObjectModifier::Close(&v19);
      UFG::SimObjectModifier::~SimObjectModifier(&v19);
    }
    UFG::VehicleUtility::AttachAIActionTreeComponent(vehicle);
    if ( !*(_BYTE *)(v10 + 1465) )
      UFG::RoadSpaceComponent::AttachToRoadNetwork(m_pComponent, 0);
    return (UFG::AiDriverComponent *)v10;
  }
  return result;
}

// File Line: 604
// RVA: 0x68A460
UFG::AiDriverComponent *__fastcall UFG::VehicleUtility::SetAIDriver(UFG::SimObjectVehicle *vehicle, bool isAmbient)
{
  return UFG::VehicleUtility::SetAIDriver(0i64, vehicle, isAmbient);
}

// File Line: 612
// RVA: 0x68ACC0
UFG::SimComponent *__fastcall UFG::VehicleUtility::SetPlayerDriver(UFG::SimObjectVehicle *vehicle)
{
  UFG::SimComponent *v2; // r14
  UFG::SimComponent *v3; // rsi
  unsigned int v4; // ebx
  UFG::BoatPhysicsMoverComponent *v5; // rdi
  UFG::BikePhysicsMoverComponent *v6; // r15
  UFG::CarPhysicsMoverComponent *v7; // r12
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rdi
  unsigned int v11; // eax
  UFG::SimComponent *v12; // rax
  UFG::qMemoryPool *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  unsigned int v15; // eax
  UFG::SimComponent *v16; // rax
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rdi
  unsigned int v19; // eax
  UFG::SimComponent *v20; // rax
  UFG::qMemoryPool *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::SimComponent *v23; // rax
  signed __int16 m_Flags; // cx
  unsigned int v25; // edi
  signed __int16 v26; // cx
  UFG::SimObjectModifier v28; // [rsp+38h] [rbp-50h] BYREF

  v2 = 0i64;
  v3 = 0i64;
  v4 = -1;
  if ( !vehicle )
    goto LABEL_17;
  v5 = UFG::SimObjectVehicle::GetComponent<UFG::BoatPhysicsMoverComponent>(vehicle);
  v6 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(vehicle);
  v7 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(vehicle);
  m_pComponent = vehicle->m_Components.p[23].m_pComponent;
  if ( m_pComponent )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
  if ( v5 )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1A0ui64, "BoatDriverComponent", 0i64, 1u);
    if ( v10 )
    {
      v11 = UFG::qStringHash32("BoatDriverComponent", 0xFFFFFFFF);
      UFG::BoatHumanDriverComponent::BoatHumanDriverComponent((UFG::BoatHumanDriverComponent *)v10, v11);
      v3 = v12;
    }
    else
    {
      v3 = 0i64;
    }
  }
  else if ( v6 )
  {
    v13 = UFG::GetSimulationMemoryPool();
    v14 = UFG::qMemoryPool::Allocate(v13, 0x1B0ui64, "BikeDriverComponent", 0i64, 1u);
    if ( v14 )
    {
      v15 = UFG::qStringHash32("BikeDriverComponent", 0xFFFFFFFF);
      UFG::BikeHumanDriverComponent::BikeHumanDriverComponent((UFG::BikeHumanDriverComponent *)v14, v15);
      v3 = v16;
    }
    else
    {
      v3 = 0i64;
    }
  }
  else if ( v7 )
  {
    v17 = UFG::GetSimulationMemoryPool();
    v18 = UFG::qMemoryPool::Allocate(v17, 0x1C0ui64, "CarDriverComponent", 0i64, 1u);
    if ( v18 )
    {
      v19 = UFG::qStringHash32("CarDriverComponent", 0xFFFFFFFF);
      UFG::CarHumanDriverComponent::CarHumanDriverComponent((UFG::CarHumanDriverComponent *)v18, v19);
      v3 = v20;
    }
    else
    {
      v3 = 0i64;
    }
  }
  if ( !vehicle->m_Components.p[24].m_pComponent )
  {
LABEL_17:
    v21 = UFG::GetSimulationMemoryPool();
    v22 = UFG::qMemoryPool::Allocate(v21, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
    if ( v22 )
    {
      UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v22);
      v2 = v23;
    }
    m_Flags = vehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v25 = 24;
    }
    else if ( m_Flags >= 0 )
    {
      v25 = -1;
    }
    else
    {
      v25 = 24;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v28, vehicle, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, v2, v25);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
  }
  v26 = vehicle->m_Flags;
  if ( (v26 & 0x4000) != 0 || v26 < 0 )
    v4 = 23;
  UFG::SimObjectModifier::SimObjectModifier(&v28, vehicle, 1);
  UFG::SimObjectModifier::AttachComponent(&v28, v3, v4);
  UFG::SimObjectModifier::Close(&v28);
  UFG::SimObjectModifier::~SimObjectModifier(&v28);
  return v3;
}

// File Line: 670
// RVA: 0x68B290
UFG::SimComponent *__fastcall UFG::VehicleUtility::SetRemoteDriver(UFG::SimObjectVehicle *vehicle)
{
  UFG::SimComponent *v2; // r14
  UFG::SimComponent *v3; // rsi
  unsigned int v4; // ebx
  UFG::BoatPhysicsMoverComponent *v5; // rdi
  UFG::BikePhysicsMoverComponent *v6; // r15
  UFG::CarPhysicsMoverComponent *v7; // r12
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rdi
  unsigned int v11; // eax
  UFG::SimComponent *v12; // rax
  UFG::qMemoryPool *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  unsigned int v15; // eax
  UFG::SimComponent *v16; // rax
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::SimComponent *v19; // rax
  signed __int16 m_Flags; // cx
  unsigned int v21; // edi
  signed __int16 v22; // cx
  UFG::SimObjectModifier v24; // [rsp+38h] [rbp-50h] BYREF

  v2 = 0i64;
  v3 = 0i64;
  v4 = -1;
  if ( !vehicle )
    goto LABEL_14;
  v5 = UFG::SimObjectVehicle::GetComponent<UFG::BoatPhysicsMoverComponent>(vehicle);
  v6 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(vehicle);
  v7 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(vehicle);
  m_pComponent = vehicle->m_Components.p[23].m_pComponent;
  if ( m_pComponent )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
  if ( !v5 )
  {
    if ( v6 )
    {
      SimulationMemoryPool = UFG::GetSimulationMemoryPool();
      v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x160ui64, "BikeRemoteDriverComponent", 0i64, 1u);
      if ( v10 )
      {
        v11 = UFG::qStringHash32("BikeRemoteDriverComponent", 0xFFFFFFFF);
        UFG::RemoteDriverComponent::RemoteDriverComponent((UFG::RemoteDriverComponent *)v10, v11);
        v3 = v12;
      }
      else
      {
        v3 = 0i64;
      }
    }
    else if ( v7 )
    {
      v13 = UFG::GetSimulationMemoryPool();
      v14 = UFG::qMemoryPool::Allocate(v13, 0x160ui64, "CarRemoteDriverComponent", 0i64, 1u);
      if ( v14 )
      {
        v15 = UFG::qStringHash32("CarRemoteDriverComponent", 0xFFFFFFFF);
        UFG::RemoteDriverComponent::RemoteDriverComponent((UFG::RemoteDriverComponent *)v14, v15);
        v3 = v16;
      }
      else
      {
        v3 = 0i64;
      }
    }
  }
  if ( !vehicle->m_Components.p[24].m_pComponent )
  {
LABEL_14:
    v17 = UFG::GetSimulationMemoryPool();
    v18 = UFG::qMemoryPool::Allocate(v17, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
    if ( v18 )
    {
      UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v18);
      v2 = v19;
    }
    m_Flags = vehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v21 = 24;
    }
    else if ( m_Flags >= 0 )
    {
      v21 = -1;
    }
    else
    {
      v21 = 24;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v24, vehicle, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v2, v21);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
  if ( v3 )
  {
    v22 = vehicle->m_Flags;
    if ( (v22 & 0x4000) != 0 || v22 < 0 )
      v4 = 23;
    UFG::SimObjectModifier::SimObjectModifier(&v24, vehicle, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v3, v4);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
  return v3;
}

// File Line: 724
// RVA: 0x674480
void __fastcall UFG::VehicleUtility::ClearDriver(UFG::SimObjectVehicle *vehicle)
{
  UFG::AiDriverComponent *v2; // rax
  UFG::SimComponent *v3; // rdi
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v5; // rdx
  UFG::HumanDriverComponent *v6; // rax
  UFG::RemoteDriverComponent *v7; // rax

  if ( vehicle )
  {
    v2 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(vehicle);
    v3 = v2;
    if ( v2 )
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v2->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v2) )
        UFG::WheeledVehicleManager::RemoveWheeledVehicleFromList(UFG::WheeledVehicleManager::m_Instance, vehicle);
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v3);
    }
    m_pComponent = vehicle->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
    v5 = vehicle->m_Components.p[19].m_pComponent;
    if ( v5 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v5);
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(vehicle);
    if ( v6 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v6);
    v7 = UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(vehicle);
    if ( v7 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v7);
  }
}

// File Line: 765
// RVA: 0x67B560
__int64 __fastcall UFG::VehicleUtility::GetVehicleOrientation(
        UFG::SimObjectVehicle *pVehicleSimObject,
        bool bIgnoreWheelState,
        float *pfReturn)
{
  unsigned int v3; // ebx
  UFG::SimComponentHolder *p; // rax
  UFG::TransformNodeComponent *m_pComponent; // rsi
  UFG::SimComponent *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  __int64 y_low; // xmm6_8
  float x; // xmm12_4
  float z; // xmm13_4
  float v13; // xmm7_4
  float v14; // xmm11_4
  float v15; // xmm0_4
  float v16; // xmm10_4
  float v17; // xmm1_4
  float v18; // xmm9_4
  float v19; // xmm1_4
  double v20; // xmm0_8

  v3 = 0;
  if ( pVehicleSimObject )
  {
    p = pVehicleSimObject->m_Components.p;
    m_pComponent = (UFG::TransformNodeComponent *)p[2].m_pComponent;
    v7 = p[34].m_pComponent;
    if ( m_pComponent )
    {
      if ( v7 )
      {
        mPrev = v7[10].m_SafePointerList.mNode.mPrev;
        v9 = 0i64;
        if ( mPrev && (BYTE4(mPrev[37].mNext) & 7) != 0 )
          v9 = mPrev;
        if ( bIgnoreWheelState || !v9 || ((__int64)v9[68].mNext & 0x10) == 0 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
          y_low = LODWORD(UFG::qVector3::msDirDown.y);
          x = UFG::qVector3::msDirDown.x;
          z = UFG::qVector3::msDirDown.z;
          v13 = *(float *)&FLOAT_1_0;
          v14 = (float)((float)(UFG::qVector3::msDirDown.y * m_pComponent->mWorldTransform.v1.y)
                      + (float)(UFG::qVector3::msDirDown.x * m_pComponent->mWorldTransform.v1.x))
              + (float)(UFG::qVector3::msDirDown.z * m_pComponent->mWorldTransform.v1.z);
          LODWORD(v15) = LODWORD(v14) & _xmm;
          v16 = (float)((float)(UFG::qVector3::msDirDown.y * m_pComponent->mWorldTransform.v0.y)
                      + (float)(UFG::qVector3::msDirDown.x * m_pComponent->mWorldTransform.v0.x))
              + (float)(UFG::qVector3::msDirDown.z * m_pComponent->mWorldTransform.v0.z);
          if ( COERCE_FLOAT(LODWORD(v14) & _xmm) <= -1.0 )
          {
            v15 = FLOAT_N1_0;
          }
          else if ( v15 >= 1.0 )
          {
            v15 = *(float *)&FLOAT_1_0;
          }
          LODWORD(v17) = LODWORD(v16) & _xmm;
          v18 = acosf(v15);
          if ( COERCE_FLOAT(LODWORD(v16) & _xmm) <= -1.0 )
          {
            v17 = FLOAT_N1_0;
          }
          else if ( v17 >= 1.0 )
          {
LABEL_19:
            v19 = acosf(v13);
            if ( v18 > 0.52359879 )
            {
              if ( v19 > 0.52359879 )
              {
                *(float *)&y_low = (float)((float)(*(float *)&y_low * m_pComponent->mWorldTransform.v2.y)
                                         + (float)(x * m_pComponent->mWorldTransform.v2.x))
                                 + (float)(z * m_pComponent->mWorldTransform.v2.z);
                if ( *(float *)&y_low > 0.0 )
                  v3 = 5;
                if ( pfReturn )
                {
                  v20 = UFG::qACos(COERCE_DOUBLE(y_low & _xmm));
                  *pfReturn = *(float *)&v20;
                }
              }
              else
              {
                LOBYTE(v3) = v16 <= 0.0;
                v3 += 3;
                if ( pfReturn )
                  *pfReturn = v19;
              }
            }
            else
            {
              LOBYTE(v3) = v14 <= 0.0;
              ++v3;
              if ( pfReturn )
                *pfReturn = v18;
            }
            return v3;
          }
          v13 = v17;
          goto LABEL_19;
        }
      }
    }
  }
  return v3;
}

// File Line: 831
// RVA: 0x67F410
char __fastcall UFG::VehicleUtility::IsPlayerPassengerOfVehicle(UFG::SimObject *vehicle_simobj)
{
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // r11
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rdx
  unsigned int v4; // r9d
  __int64 v5; // r11
  __int64 i; // rax
  int v7; // r8d
  int v8; // ecx
  __int64 j; // rax
  int v10; // ecx
  __int64 k; // rax
  UFG::SimObjectCharacter *v12; // rcx

  if ( (vehicle_simobj->m_Flags & 0x8000u) == 0 )
    return 0;
  m_pComponent = vehicle_simobj->m_Components.p[30].m_pComponent;
  if ( !m_pComponent )
    return 0;
  mNext = m_pComponent[1].m_BoundComponentHandles.mNode.mNext;
  p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
  v4 = 0;
  v5 = (__int64)&mNext[-4];
  for ( i = v5;
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)i != p_m_BoundComponentHandles;
        i = *(_QWORD *)(i + 72) - 64i64 )
  {
    ++v4;
  }
  v7 = 0;
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v8 = 0;
    for ( j = v5;
          (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)j != p_m_BoundComponentHandles;
          j = *(_QWORD *)(j + 72) - 64i64 )
    {
      ++v8;
    }
    if ( v7 >= v8 )
    {
      v12 = 0i64;
    }
    else
    {
      v10 = v7;
      for ( k = v5; v10 > 0; k = *(_QWORD *)(k + 72) - 64i64 )
      {
        if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)k == p_m_BoundComponentHandles )
          break;
        --v10;
      }
      v12 = *(UFG::SimObjectCharacter **)(k + 40);
    }
    if ( LocalPlayer && v12 == LocalPlayer )
      break;
    if ( ++v7 >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 864
// RVA: 0x68B200
void __fastcall UFG::VehicleUtility::SetRadiostation(UFG::SimObjectVehicle *vehicle)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *DriverProfile; // rax
  float *v5; // rax
  UFG::qSymbolUC *v6; // rax
  char *v7; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  m_pSceneObj = vehicle->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  DriverProfile = UFG::SimObjectUtility::FindDriverProfile(mpWritableProperties);
  if ( DriverProfile )
  {
    v5 = UFG::qPropertySet::Get<float>(
           DriverProfile,
           (UFG::qArray<unsigned long,0> *)&qSymbol_RadioStation,
           DEPTH_RECURSE);
    if ( v5 )
      PropertyUtils::SetRuntime<float>(vehicle->m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_RadioStation, *v5);
  }
  else
  {
    v6 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, vehicle->m_pSceneObj->m_NameUID);
    v7 = UFG::qSymbol::as_cstr_dbg(v6);
    UFG::qPrintf("Did not set Radiostation. No Driver Profile found in %s\n", v7);
  }
}

// File Line: 888
// RVA: 0x6785F0
// attributes: thunk
void __fastcall UFG::VehicleUtility::ExitVehicleNow(
        UFG::SimObject *pOccupantSimObject,
        bool bForceClearDriver,
        bool bDispatchNonCameraEvents,
        bool bDispatchCameraEvents)
{
  UFG::VehicleUtility::FinishExitingVehicle(
    pOccupantSimObject,
    bForceClearDriver,
    bDispatchNonCameraEvents,
    bDispatchCameraEvents);
}

// File Line: 900
// RVA: 0x678FB0
void __fastcall UFG::VehicleUtility::FinishExitingVehicle(
        UFG::SimObjectCharacter *pOccupantSimObject,
        bool bForceClearDriver,
        bool bDispatchNonCameraEvents,
        bool bDispatchCameraEvents)
{
  UFG::CharacterOccupantComponent *m_pComponent; // r14
  signed __int16 m_Flags; // cx
  UFG::CharacterOccupantComponent *ComponentOfTypeHK; // rax
  bool v11; // r15
  UFG::SimObjectVehicle *CurrentVehicle; // rsi
  UFG::TargetingSystemBaseComponent *v13; // rdx
  signed __int16 v14; // cx
  UFG::TargetingSystemBaseComponent *ComponentOfType; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::TargetingSimObject *v17; // rcx
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::AiDriverComponent *v21; // rax
  UFG::AiDriverComponent *v22; // rbx
  UFG::SimComponentHolder *p; // rax
  float *v24; // rbx
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm8_4
  UFG::GameStatTracker *v28; // rax
  UFG::GameStatTracker *v29; // rax
  UFG::GameStatTracker *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::SimComponent *v36; // rbx
  UFG::AiDriverComponent *v37; // rax
  char v38; // r15
  UFG::SimObject **p_m_pSimObject; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  UFG::VehicleSubjectComponent *v42; // rax
  __int64 mTargetType; // rbx
  UFG::TargetingSystemVehicleComponent *v44; // rax
  UFG::TargetingSystemVehicleComponent *v45; // r15
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // r10
  unsigned __int8 v47; // dl
  __int64 v48; // rbx
  UFG::VehicleOccupantComponent *v49; // rcx
  signed __int16 v50; // cx
  UFG::SimComponent *v51; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> object; // [rsp+20h] [rbp-11h] BYREF
  UFG::allocator::free_link *v53; // [rsp+98h] [rbp+67h]

  if ( pOccupantSimObject )
  {
    m_Flags = pOccupantSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterOccupantComponent *)pOccupantSimObject->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 pOccupantSimObject,
                                                                 UFG::CharacterOccupantComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 pOccupantSimObject,
                                                                 UFG::CharacterOccupantComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      v11 = m_pComponent->mTargetType == eTARGET_TYPE_VEHICLE_DRIVER;
      CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      goto LABEL_15;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v11 = 0;
  CurrentVehicle = 0i64;
LABEL_15:
  if ( !UFG::IsAnyLocalPlayer(pOccupantSimObject) )
    goto LABEL_59;
  if ( pOccupantSimObject )
  {
    v14 = pOccupantSimObject->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      v13 = (UFG::TargetingSystemBaseComponent *)pOccupantSimObject->m_Components.p[20].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 pOccupantSimObject,
                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                 pOccupantSimObject,
                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
      v13 = ComponentOfType;
    }
    else
    {
      v13 = (UFG::TargetingSystemBaseComponent *)pOccupantSimObject->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  object.mPrev = &object;
  object.mNext = &object;
  object.m_pPointer = pOccupantSimObject;
  if ( pOccupantSimObject )
  {
    mPrev = pOccupantSimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    mPrev->mNext = &object;
    object.mPrev = mPrev;
    object.mNext = &pOccupantSimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pOccupantSimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &object;
  }
  if ( v13
    && (v17 = &v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK]],
        v17->m_pTarget.m_pPointer)
    && v17->m_bLock )
  {
    if ( bDispatchNonCameraEvents )
    {
      v18 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v53 = v18;
      if ( v18 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v18, "EVT_MOUNT_VEHICLE", &object);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v18);
    }
    if ( bDispatchCameraEvents )
    {
      v19 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v53 = v19;
      if ( v19 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v19, "EVT_MOUNT_VEHICLE_CAMERA", &object);
LABEL_47:
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v19);
    }
  }
  else
  {
    if ( bDispatchNonCameraEvents )
    {
      v20 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v53 = v20;
      if ( v20 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v20, "EVT_DISMOUNT_VEHICLE", &object);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v20);
    }
    if ( bDispatchCameraEvents )
    {
      v19 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v53 = v19;
      if ( v19 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v19, "EVT_DISMOUNT_VEHICLE_CAMERA", &object);
      goto LABEL_47;
    }
  }
  if ( v11 )
  {
LABEL_53:
    if ( CurrentVehicle )
    {
      p = CurrentVehicle->m_Components.p;
      v24 = (float *)p[2].m_pComponent;
      if ( v24 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
        v25 = v24[44];
        v26 = v24[45];
        v27 = v24[46];
        v28 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v28, LastUsedVehicleDismountLocationX, v25);
        v29 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v29, LastUsedVehicleDismountLocationY, v26);
        v30 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v30, LastUsedVehicleDismountLocationZ, v27);
        v31 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v31, LastUsedVehicleIsCurrentlyUsed, 0);
      }
    }
    goto LABEL_56;
  }
  if ( CurrentVehicle )
  {
    v21 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
    v22 = v21;
    if ( v21 && v21->m_DrivingRole == 4 )
    {
      v21->m_IsAmbient = 1;
      UFG::AiDriverComponent::SetDrivingRole(v21, 0);
      UFG::AiDriverComponent::SetDrivingMode(v22, 1u);
      UFG::AiDriverComponent::SetObeyTrafficLights(v22, 1);
    }
    goto LABEL_53;
  }
LABEL_56:
  if ( object.m_pPointer )
  {
    v32 = object.mPrev;
    mNext = object.mNext;
    object.mPrev->mNext = object.mNext;
    mNext->mPrev = v32;
    object.mPrev = &object;
    object.mNext = &object;
  }
  object.m_pPointer = 0i64;
  v34 = object.mPrev;
  v35 = object.mNext;
  object.mPrev->mNext = object.mNext;
  v35->mPrev = v34;
  object.mPrev = &object;
  object.mNext = &object;
LABEL_59:
  if ( CurrentVehicle )
    v36 = CurrentVehicle->m_Components.p[23].m_pComponent;
  else
    v36 = 0i64;
  if ( v11 )
  {
    if ( v36 )
    {
      if ( CurrentVehicle && (v37 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle)) != 0i64 )
      {
        v38 = ((__int64 (__fastcall *)(UFG::AiDriverComponent *))v37->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v37);
        if ( v38 )
          UFG::PedSpawnManager::GetInstance();
      }
      else
      {
        v38 = 0;
      }
      if ( bForceClearDriver || !v38 )
      {
        UFG::VehicleUtility::ClearDriver(CurrentVehicle);
      }
      else
      {
        p_m_pSimObject = &v36[3].m_pSimObject;
        if ( v36[3].m_BoundComponentHandles.mNode.mNext )
        {
          v40 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)*p_m_pSimObject;
          v41 = v36[3].m_BoundComponentHandles.mNode.mPrev;
          v40->mNext = v41;
          v41->mPrev = v40;
          *p_m_pSimObject = (UFG::SimObject *)p_m_pSimObject;
          v36[3].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v36[3].m_pSimObject;
        }
        v36[3].m_BoundComponentHandles.mNode.mNext = 0i64;
      }
    }
    if ( CurrentVehicle )
    {
      v42 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(CurrentVehicle);
      if ( v42 )
        UFG::VehicleSubjectComponent::ReassignChasersTo(v42, pOccupantSimObject);
    }
  }
  if ( m_pComponent )
  {
    mTargetType = (unsigned int)m_pComponent->mTargetType;
    if ( CurrentVehicle )
    {
      v44 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(CurrentVehicle);
      v45 = v44;
      if ( v44 )
      {
        vfptr = v44->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr;
        LODWORD(object.mPrev) = 0;
        ((void (__fastcall *)(UFG::TargetingSystemVehicleComponent *, _QWORD, _QWORD, _QWORD, UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *, _QWORD, _QWORD, _QWORD))vfptr[14].__vecDelDtor)(
          v44,
          (unsigned int)mTargetType,
          0i64,
          0i64,
          object.mPrev,
          0i64,
          0i64,
          0i64);
        v47 = v45->m_pTargetingMap->m_Map.p[mTargetType];
        if ( v47 )
        {
          v48 = v47;
          UFG::TargetingSimObject::SetTarget(&v45->m_pTargets[v48], 0i64);
          UFG::TargetingSimObject::SetLock(&v45->m_pTargets[v48], 0);
        }
      }
      v49 = (UFG::VehicleOccupantComponent *)CurrentVehicle->m_Components.p[30].m_pComponent;
      if ( v49 )
        UFG::VehicleOccupantComponent::RemoveOccupant(v49, m_pComponent);
    }
    UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
  }
  if ( !pOccupantSimObject
    || ((v50 = pOccupantSimObject->m_Flags, (v50 & 0x4000) == 0)
      ? (v50 >= 0 && (v50 & 0x2000) == 0 && (v50 & 0x1000) == 0
       ? (v51 = UFG::SimObject::GetComponentOfType(pOccupantSimObject, UFG::RagdollComponent::_TypeUID))
       : (v51 = UFG::SimObjectGame::GetComponentOfTypeHK(pOccupantSimObject, UFG::RagdollComponent::_TypeUID)))
      : (v51 = pOccupantSimObject->m_Components.p[42].m_pComponent),
        !v51) )
  {
    UFG::RagdollComponent::PropertiesOnActivateNew(pOccupantSimObject->m_pSceneObj, 0);
  }
}

// File Line: 1064
// RVA: 0x67EA00
bool __fastcall UFG::VehicleUtility::IsClassTypeRoadTypeMatch(UFG::qPropertySet *set, unsigned int roadType)
{
  char IsClassType; // si

  IsClassType = UFG::SimObjectUtility::IsClassType(set, &qSymbol_Boat_22);
  if ( UFG::SimObjectUtility::IsClassType(set, &qSymbol_Ferry) )
    return roadType == 2;
  if ( IsClassType )
    return roadType == 3;
  if ( UFG::SimObjectUtility::IsClassType(set, &qSymbol_Tram) )
    return roadType == 1;
  return roadType == 0;
}

// File Line: 1095
// RVA: 0x670880
void __fastcall UFG::VehicleUtility::AttachAIActionTreeComponent(UFG::SimObjectVehicle *vehicle)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // eax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rsi
  signed __int16 m_Flags; // cx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h] BYREF

  if ( !vehicle || !vehicle->m_Components.p[19].m_pComponent )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x678ui64, "AIActionTreeComponent", 0i64, 1u);
    v4 = -1;
    if ( v3 )
    {
      v5 = UFG::qStringHashUpper32("AIActionTreeComponent", -1);
      UFG::AIActionTreeComponent::AIActionTreeComponent(
        (UFG::AIActionTreeComponent *)v3,
        v5,
        "Data\\Global\\Act\\CarAI.act");
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    m_Flags = vehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v4 = 19;
    UFG::SimObjectModifier::SimObjectModifier(&v9, vehicle, 1);
    UFG::SimObjectModifier::AttachComponent(&v9, v7, v4);
    UFG::SimObjectModifier::Close(&v9);
    UFG::SimObjectModifier::~SimObjectModifier(&v9);
  }
}

// File Line: 1108
// RVA: 0x69A110
void __fastcall UFG::VehicleUtility::UpdateTargetsForEachVehicleRole(UFG::SimObjectVehicle *vehicle)
{
  UFG::TargetingSystemVehicleComponent *v1; // rsi
  UFG::eTargetTypeEnum *v2; // rbx
  __int64 v3; // rdi
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *ComponentOfTypeHK; // rax

  if ( vehicle )
    v1 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(vehicle);
  else
    v1 = 0i64;
  v2 = UFG::TargetingSystemBaseComponent::ms_eVehicleRoleTargetTypes;
  v3 = 7i64;
  do
  {
    m_pPointer = (UFG::SimObjectCVBase *)v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[*(unsigned int *)v2]].m_pTarget.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      m_pPointer,
                                                                      UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                      m_pPointer,
                                                                      UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(ComponentOfTypeHK);
    }
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 1138
// RVA: 0x685AD0
void __fastcall UFG::VehicleUtility::OverrideForwardSpeedKPH(UFG::SimObjectVehicle *pVehicle, float forwardSpeedKPH)
{
  UFG::PhysicsVehicle *mPrev; // rcx
  UFG::SimComponent *m_pComponent; // rax
  float v5; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float z; // xmm2_4
  UFG::SimComponentHolder *p; // rax
  float *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 velocity; // [rsp+20h] [rbp-28h] BYREF

  mPrev = 0i64;
  if ( pVehicle )
  {
    m_pComponent = pVehicle->m_Components.p[34].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_8;
    mPrev = (UFG::PhysicsVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( m_pComponent && mPrev )
  {
    v5 = forwardSpeedKPH * 0.27777779;
    v6 = mPrev->mBodyTransform.v0.x * (float)(forwardSpeedKPH * 0.27777779);
    v7 = mPrev->mBodyTransform.v0.y * (float)(forwardSpeedKPH * 0.27777779);
    z = mPrev->mBodyTransform.v0.z;
    velocity.x = v6;
    velocity.y = v7;
    velocity.z = z * v5;
    UFG::PhysicsVehicle::SetVelocity(mPrev, &velocity);
    return;
  }
LABEL_8:
  if ( pVehicle )
  {
    p = pVehicle->m_Components.p;
    v10 = (float *)p[2].m_pComponent;
    if ( v10 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
      v11 = forwardSpeedKPH * 0.27777779;
      v12 = v10[33] * (float)(forwardSpeedKPH * 0.27777779);
      v13 = v10[34] * v11;
      v10[64] = v10[32] * v11;
      v10[65] = v12;
      v10[66] = v13;
    }
  }
}

// File Line: 1166
// RVA: 0x685BD0
void __fastcall UFG::VehicleUtility::OverrideLinearVelocityMagnitudeKPH(
        UFG::SimObjectVehicle *pVehicle,
        float speedKPH)
{
  UFG::PhysicsVehicle *mPrev; // rbx
  UFG::SimComponent *m_pComponent; // rax
  __m128 x_low; // xmm2
  float v6; // xmm1_4
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v10; // xmm6_4
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *v12; // rbx
  float v13; // xmm2_4
  __m128 vfptr_high; // xmm3
  float v15; // xmm4_4
  __m128 v16; // xmm5
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF

  mPrev = 0i64;
  if ( pVehicle )
  {
    m_pComponent = pVehicle->m_Components.p[34].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_13;
    mPrev = (UFG::PhysicsVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( m_pComponent && mPrev )
  {
    UFG::PhysicsVehicle::GetVelocity(mPrev, &result);
    x_low = (__m128)LODWORD(result.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                      + (float)(result.z * result.z);
    if ( x_low.m128_f32[0] <= 0.001 )
    {
      x = mPrev->mBodyTransform.v0.x;
      y = mPrev->mBodyTransform.v0.y;
      z = mPrev->mBodyTransform.v0.z;
    }
    else
    {
      v6 = 0.0;
      if ( x_low.m128_f32[0] != 0.0 )
        v6 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
      x = result.x * v6;
      y = result.y * v6;
      z = result.z * v6;
    }
    v10 = speedKPH * 0.27777779;
    result.x = x * v10;
    result.y = y * v10;
    result.z = z * v10;
    UFG::PhysicsVehicle::SetVelocity(mPrev, &result);
    return;
  }
LABEL_13:
  if ( pVehicle )
  {
    p = pVehicle->m_Components.p;
    v12 = p[2].m_pComponent;
    if ( v12 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
      v13 = *(float *)&v12[4].vfptr;
      vfptr_high = (__m128)HIDWORD(v12[4].vfptr);
      v15 = *(float *)&v12[4].m_SafePointerList.mNode.mPrev;
      v16 = vfptr_high;
      v16.m128_f32[0] = (float)((float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v13 * v13))
                      + (float)(v15 * v15);
      if ( v16.m128_f32[0] <= 0.001 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        v18 = *(float *)&v12[2].vfptr;
        v19 = *((float *)&v12[2].vfptr + 1);
        v20 = *(float *)&v12[2].m_SafePointerList.mNode.mPrev;
      }
      else
      {
        v17 = 0.0;
        if ( v16.m128_f32[0] != 0.0 )
          v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
        v18 = v13 * v17;
        v19 = vfptr_high.m128_f32[0] * v17;
        v20 = v15 * v17;
      }
      v21 = speedKPH * 0.27777779;
      *(float *)&v12[4].vfptr = v18 * v21;
      *((float *)&v12[4].vfptr + 1) = v19 * v21;
      *(float *)&v12[4].m_SafePointerList.mNode.mPrev = v20 * v21;
    }
  }
}

// File Line: 1207
// RVA: 0x67EBA0
bool __fastcall UFG::VehicleUtility::IsDriverTypeInList(UFG::SimObject *pSimObject, UFG::qPropertyList *list)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx

  if ( pSimObject && (m_pSceneObj = pSimObject->m_pSceneObj) != 0i64 )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      return UFG::VehicleUtility::IsDriverTypeInList(m_pSceneObj->mpConstProperties, list);
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  return UFG::VehicleUtility::IsDriverTypeInList(mpWritableProperties, list);
}

// File Line: 1213
// RVA: 0x67EBD0
char __fastcall UFG::VehicleUtility::IsDriverTypeInList(UFG::qPropertySet *pPropertySet, UFG::qPropertyList *list)
{
  UFG::qPropertyList *v3; // rax
  unsigned int mNumElements; // esi
  UFG::qSymbol *v5; // r14
  unsigned int v6; // ebx
  UFG::qSymbol *v7; // r9
  __int64 v8; // rdx
  __int64 v9; // rax

  if ( !list )
    return 0;
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_VehicleDriverTypeList,
         DEPTH_RECURSE);
  if ( !v3 )
    return 0;
  mNumElements = v3->mNumElements;
  v5 = mNumElements ? UFG::qPropertyList::Get<UFG::qSymbol>(v3, 0) : 0i64;
  v6 = list->mNumElements;
  v7 = v6 ? UFG::qPropertyList::Get<UFG::qSymbol>(list, 0) : 0i64;
  v8 = 0i64;
  if ( !mNumElements )
    return 0;
  while ( 1 )
  {
    v9 = 0i64;
    if ( v6 )
      break;
LABEL_13:
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= mNumElements )
      return 0;
  }
  while ( v5[v8].mUID != v7[v9].mUID )
  {
    v9 = (unsigned int)(v9 + 1);
    if ( (unsigned int)v9 >= v6 )
      goto LABEL_13;
  }
  return 1;
}

