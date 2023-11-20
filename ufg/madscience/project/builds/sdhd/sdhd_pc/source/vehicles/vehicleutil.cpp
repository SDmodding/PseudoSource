// File Line: 57
// RVA: 0x67A130
UFG::TransformNodeComponent *__fastcall UFG::VehicleUtility::GetChaseSpawnTransform(UFG::SimObject *chasee, float distance_behind)
{
  unsigned __int16 v2; // dx
  UFG::VehicleDriverInterface *v3; // rax
  UFG::TransformNodeComponent *result; // rax

  if ( chasee
    && ((v2 = chasee->m_Flags, !((v2 >> 14) & 1)) ? ((v2 & 0x8000u) == 0 ? (!((v2 >> 13) & 1) ? (!((v2 >> 12) & 1) ? (v3 = (UFG::VehicleDriverInterface *)UFG::SimObject::GetComponentOfType(chasee, UFG::VehicleDriverInterface::_TypeUID)) : (v3 = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)chasee, UFG::VehicleDriverInterface::_TypeUID))) : (v3 = (UFG::VehicleDriverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)chasee, UFG::VehicleDriverInterface::_TypeUID))) : (v3 = (UFG::VehicleDriverInterface *)chasee->m_Components.p[23].m_pComponent)) : (v3 = (UFG::VehicleDriverInterface *)chasee->m_Components.p[23].m_pComponent),
        v3) )
  {
    result = UFG::VehicleDriverInterface::GetChaseSpawnTransform(v3, distance_behind);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 66
// RVA: 0x6782B0
void __fastcall UFG::VehicleUtility::ExitVehicleNoAnim(UFG::SimObject *character)
{
  UFG::SimObjectCharacter *v1; // rbx
  ActionNode *v2; // r14
  unsigned __int16 v3; // dx
  UFG::TargetingSystemPedBaseComponent *v4; // rax
  UFG::TargetingSystemPedBaseComponent *v5; // rbp
  unsigned __int16 v6; // cx
  UFG::ActionTreeComponent *v7; // rsi
  UFG::ActionTreeComponent *v8; // rax
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  __int64 v11; // r15
  __int64 v12; // rax
  ActionNodeRoot *v13; // rdi
  ActionContext *v14; // rdx
  __int64 v15; // rax
  UFG::ActionTreeComponentBase *v16; // rcx
  ActionNodePlayable *v17; // r14
  UEL::ParametersBase *v18; // r15
  unsigned __int16 v19; // dx
  UFG::UELComponent *v20; // rax
  bool v21; // di

  v1 = (UFG::SimObjectCharacter *)character;
  if ( !(_S20_3 & 1) )
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
  if ( v1 )
  {
    v3 = v1->m_Flags;
    if ( (v1->m_Flags >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>((UFG::SimObjectCVBase *)&v1->vfptr);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v1->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      else
        v4 = (UFG::TargetingSystemPedBaseComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v1->vfptr,
                                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID));
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>((UFG::SimObjectCVBase *)&v1->vfptr);
    }
    v5 = v4;
    v6 = v1->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::ActionTreeComponent *)v1->m_Components.p[7].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::ActionTreeComponent *)v1->m_Components.p[6].m_pComponent;
      }
      else
      {
        v8 = (UFG::ActionTreeComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v1->vfptr,
                                                             UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v1->vfptr,
                                                                                                     UFG::ActionTreeComponent::_TypeUID));
        v7 = v8;
      }
    }
    else
    {
      v7 = (UFG::ActionTreeComponent *)v1->m_Components.p[7].m_pComponent;
    }
    v9 = v1->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v1->m_Components.p[44].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v1->vfptr,
                UFG::CharacterOccupantComponent::_TypeUID);
      else
        v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                 (UFG::SimObjectGame *)&v1->vfptr,
                                 UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                (UFG::SimObject *)&v1->vfptr,
                                                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v1->vfptr,
              UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v5 && v7 && v2 && v10 )
    {
      v11 = ((__int64 (__cdecl *)(ActionNode *))v7->mpActionContext->m_OpeningBranch->vfptr[1].GetResourceOwner)(v7->mpActionContext->m_OpeningBranch);
      v12 = (__int64)v2->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v2->vfptr);
      v13 = (ActionNodeRoot *)v12;
      v14 = v7->mpActionContext;
      v15 = *(char *)(v12 + 236);
      if ( (v14->mActionTreeComponentBase[v15] || v14->mActionTreeComponentBase[1]) && (ActionNodeRoot *)v11 != v13 )
      {
        v16 = v14->mActionTreeComponentBase[v15];
        if ( !v16 )
          v16 = v14->mActionTreeComponentBase[1];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v16, v13) )
          ActionNodeRoot::Init(v13, v7->mpActionContext);
      }
      v17 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))v2->vfptr[2].GetClassNameUID)(
                                    v2,
                                    v7->mpActionContext);
      if ( v17 )
      {
        v18 = UEL::gCurrentParameters;
        v19 = v1->m_Flags;
        if ( (v19 >> 14) & 1 )
        {
          v20 = (UFG::UELComponent *)v1->m_Components.p->m_pComponent;
        }
        else if ( (v19 & 0x8000u) == 0 )
        {
          if ( (v19 >> 13) & 1 )
          {
            v20 = (UFG::UELComponent *)v1->m_Components.p->m_pComponent;
          }
          else if ( (v19 >> 12) & 1 )
          {
            v20 = (UFG::UELComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v1->vfptr,
                                         UFG::UELComponent::_TypeUID);
          }
          else
          {
            v20 = (UFG::UELComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v1->vfptr,
                                         UFG::UELComponent::_TypeUID);
          }
        }
        else
        {
          v20 = (UFG::UELComponent *)v1->m_Components.p->m_pComponent;
        }
        if ( v20 )
          UEL::gCurrentParameters = (UEL::ParametersBase *)&v20->mParameters;
        v21 = v7->mActionController.mKeepAlive != 0;
        v7->mActionController.mKeepAlive = 0;
        ActionController::Play(&v7->mActionController, v17);
        ActionController::Update(&v7->mActionController, 0.0);
        v7->mActionController.mKeepAlive = v21;
        UEL::gCurrentParameters = v18;
      }
      UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v5);
    }
  }
}

// File Line: 139
// RVA: 0x6864B0
void __fastcall UFG::VehicleUtility::PlaceCharacterInVehicle(UFG::SimObjectCharacter *character, UFG::SimObjectVehicle *vehicle, UFG::eTargetTypeEnum eRole, bool addAI, bool destroyEquipped, bool ignoreRoleGetInFirstEmptyPassengerSeat)
{
  bool v6; // r12
  __int64 v7; // rbx
  UFG::SimObjectVehicle *v8; // r14
  UFG::SimObjectCharacter *v9; // rsi
  UFG::PedSpawnManager *v10; // rax
  UFG::ActionTreeComponent *v11; // r13
  UFG::Event *v12; // rdi
  UFG::SimObjectVehiclePropertiesComponent *v13; // r15
  unsigned int v14; // ecx
  ActionPath *v15; // rbp
  ActionNode *v16; // r15
  UFG::TargetingSystemPedBaseComponent *v17; // rbp
  UFG::SimObject *v18; // rcx
  UFG::TargetingSystemVehicleComponent *v19; // rax
  UFG::TargetingSystemBaseComponent *v20; // r10
  UFG::TargetingMap *v21; // r8
  UFG::TargetingSimObject *v22; // r9
  UFG::SimObjectCharacter *v23; // rax
  UFG::SimObjectCharacter *v24; // rcx
  UFG::allocator::free_link *v25; // rbp
  unsigned int v26; // ebx
  UFG::Event *v27; // rax
  __int64 v28; // rdi
  ActionNodeRoot *v29; // rax
  ActionNodeRoot *v30; // rbx
  ActionContext *v31; // rdx
  __int64 v32; // r9
  UFG::ActionTreeComponentBase *v33; // rcx
  ActionNodePlayable *v34; // rbp
  UFG::AICharacterControllerBaseComponent *v35; // rax
  UEL::ParametersBase *v36; // r15
  UEL::ParametersBase *v37; // rax
  bool v38; // di
  UFG::SimComponent *v39; // rcx
  UFG::RagdollComponent *v40; // rcx
  UFG::VehicleDriverInterface *v41; // rcx
  UFG::SimComponent *v42; // rax
  UFG::SimObject *v43; // rcx
  UFG::ChaseCameraComponent *v44; // rax
  UFG::TargetingSystemPedBaseComponent *v45; // [rsp+40h] [rbp-58h]
  UFG::TransformNodeComponent *v46; // [rsp+A0h] [rbp+8h]
  bool bDriver; // [rsp+B0h] [rbp+18h]
  bool v48; // [rsp+B8h] [rbp+20h]

  v48 = addAI;
  v6 = addAI;
  v7 = (unsigned int)eRole;
  v8 = vehicle;
  v9 = character;
  if ( character )
  {
    v10 = UFG::PedSpawnManager::GetInstance();
    if ( !UFG::PedSpawnManager::ChangeActiveStatusOfSimObj(
            v10,
            Active,
            (UFG::SimObject *)&v9->vfptr,
            "d:\\ufg\\madscience\\project\\builds\\sdhd\\sdhd_pc\\source\\vehicles\\vehicleutil.cpp",
            140) )
      UFG::SimObject::Restore((UFG::SimObject *)&v9->vfptr);
  }
  bDriver = (_DWORD)v7 == 4;
  if ( v9 )
  {
    v45 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>((UFG::SimObjectCVBase *)&v9->vfptr);
    if ( v45 )
    {
      v11 = (UFG::ActionTreeComponent *)v9->m_Components.p[7].m_pComponent;
      if ( v11 )
      {
        v12 = 0i64;
        if ( v8 )
        {
          v46 = (UFG::TransformNodeComponent *)v8->m_Components.p[2].m_pComponent;
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>((UFG::SimObjectCVBase *)&v8->vfptr);
        }
        else
        {
          v46 = 0i64;
          v13 = 0i64;
        }
        if ( v6 && (_DWORD)v7 == 4 )
          UFG::VehicleUtility::ClearDriver(v8);
        v14 = _S21_3;
        if ( !(_S21_3 & 1) )
        {
          _S21_3 |= 1u;
          carDriverAnimationName.mPath.mCount = 0;
          carDriverAnimationName.mPath.mData.mOffset = 0i64;
          ActionPath::Append(&carDriverAnimationName, "\\Global\\Vehicle\\Interactions\\Action\\GetIn\\NOANIM\\Driver");
          atexit(UFG::VehicleUtility::PlaceCharacterInVehicle_::_14_::_dynamic_atexit_destructor_for__carDriverAnimationName__);
          v14 = _S21_3;
        }
        v15 = &carFirstAvailablePassengerAnimationName;
        if ( !(v14 & 2) )
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
        if ( !(v14 & 4) )
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
        if ( !(v14 & 8) )
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
        if ( !(v14 & 0x10) )
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
        if ( !(v14 & 0x20) )
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
        if ( !(v14 & 0x40) )
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
        if ( !_bittest((const signed int *)&v14, 8u) )
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
          if ( v13->m_eSimObjectVehicleType == 1 )
          {
            v15 = &bikePassengerAnimationName;
            if ( bDriver )
              v15 = &bikeDriverAnimationName;
          }
          else if ( v13->m_eSimObjectVehicleType == 6 )
          {
            v15 = &scooterDriverAnimationName;
          }
          else if ( bDriver || !ignoreRoleGetInFirstEmptyPassengerSeat )
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
            UFG::TargetingSystemBaseComponent::SetTarget(
              (UFG::TargetingSystemBaseComponent *)&v45->vfptr,
              eTARGET_TYPE_INTERACTIVE_PROP,
              (UFG::SimObject *)&v8->vfptr);
            UFG::TargetingSystemBaseComponent::SetTarget(
              (UFG::TargetingSystemBaseComponent *)&v45->vfptr,
              eTARGET_TYPE_VEHICLE,
              (UFG::SimObject *)&v8->vfptr);
            ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, signed __int64, signed __int64))v17->vfptr[14].__vecDelDtor)(
              v17,
              0x28i64,
              1i64);
            ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, signed __int64, signed __int64))v17->vfptr[14].__vecDelDtor)(
              v17,
              0x1Ci64,
              1i64);
            if ( destroyEquipped )
            {
              v18 = v45->m_pTargets[(unsigned __int8)v45->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
              if ( v18 )
                UFG::SimObject::Destroy(v18);
            }
            if ( v8 )
            {
              v19 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>((UFG::SimObjectCVBase *)&v8->vfptr);
              v20 = (UFG::TargetingSystemBaseComponent *)&v19->vfptr;
              if ( v19 )
              {
                v21 = v19->m_pTargetingMap;
                v22 = v19->m_pTargets;
                v23 = (UFG::SimObjectCharacter *)v22[(unsigned __int8)v21->m_Map.p[v7]].m_pTarget.m_pPointer;
                if ( !v23 || v23 == v9 )
                  goto LABEL_96;
                if ( !bDriver && ignoreRoleGetInFirstEmptyPassengerSeat )
                {
                  LODWORD(v7) = 5;
                  v24 = (UFG::SimObjectCharacter *)v22[(unsigned __int8)v21->m_Map.p[5]].m_pTarget.m_pPointer;
                  if ( !v24 )
                    goto LABEL_96;
                  do
                  {
                    if ( v24 == v9 )
                      break;
                    if ( (signed int)v7 > 8 )
                      return;
                    v7 = (unsigned int)(unsigned __int8)v7 + 1;
                    v24 = (UFG::SimObjectCharacter *)v22[(unsigned __int8)v21->m_Map.p[v7]].m_pTarget.m_pPointer;
                  }
                  while ( v24 );
                  if ( (signed int)v7 <= 8 )
                  {
LABEL_96:
                    UFG::TargetingSystemBaseComponent::SetTarget(
                      v20,
                      (UFG::eTargetTypeEnum)v7,
                      (UFG::SimObject *)&v9->vfptr);
                    UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v45);
                    v25 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
                    if ( v25 )
                    {
                      v26 = v9->mNode.mUID;
                      UFG::TransformNodeComponent::UpdateWorldTransform(v46);
                      UFG::TeleportEvent::TeleportEvent(
                        (UFG::TeleportEvent *)v25,
                        (UFG::qVector3 *)&v46->mWorldTransform.v3,
                        v26,
                        0,
                        UFG::TeleportEvent::m_Name,
                        0);
                      v12 = v27;
                    }
                    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v12);
                    v28 = ((__int64 (*)(void))v11->mpActionContext->m_OpeningBranch->vfptr[1].GetResourceOwner)();
                    v29 = (ActionNodeRoot *)v16->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v16->vfptr);
                    v30 = v29;
                    v31 = v11->mpActionContext;
                    v32 = v29->mActionTreeType.mValue;
                    if ( (v31->mActionTreeComponentBase[v32] || v31->mActionTreeComponentBase[1])
                      && (ActionNodeRoot *)v28 != v29 )
                    {
                      v33 = v31->mActionTreeComponentBase[v32];
                      if ( !v33 )
                        v33 = v31->mActionTreeComponentBase[1];
                      if ( UFG::ActionTreeComponentBase::AllocateFor(v33, v29) )
                        ActionNodeRoot::Init(v30, v11->mpActionContext);
                    }
                    v34 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))v16->vfptr[2].GetClassNameUID)(
                                                  v16,
                                                  v11->mpActionContext);
                    if ( v34 )
                    {
                      if ( UFG::IsAnyLocalPlayer((UFG::SimObject *)&v9->vfptr) )
                        UFG::FollowCameraComponent::SetForceSnapOnEvent(1);
                      PropertyUtils::SetRuntime<bool>(
                        v9->m_pSceneObj,
                        (UFG::qSymbol *)&qSymbol_GetInParam_VehicleInteractSkipSettingUpAI.mUID,
                        1);
                      v35 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>((UFG::SimObjectCVBase *)&v9->vfptr);
                      if ( v35 )
                      {
                        Intention::Set(&v35->m_Intention, gActionRequest_EnterVehicleForced.m_EnumValue, 0.0);
                        v36 = UEL::gCurrentParameters;
                        v37 = (UEL::ParametersBase *)v9->m_Components.p->m_pComponent;
                        if ( v37 )
                          UEL::gCurrentParameters = v37 + 88;
                        v38 = v11->mActionController.mKeepAlive != 0;
                        v11->mActionController.mKeepAlive = 0;
                        ActionController::Stop(&v11->mActionController);
                        ActionController::Play(&v11->mActionController, v34);
                        ActionController::Update(&v11->mActionController, 0.0);
                        v11->mActionController.mKeepAlive = v38;
                        UEL::gCurrentParameters = v36;
                        v39 = v9->m_Components.p[13].m_pComponent;
                        if ( v39 )
                          LOBYTE(v39[4].m_BoundComponentHandles.mNode.mNext) |= 4u;
                        PropertyUtils::SetRuntime<bool>(
                          v9->m_pSceneObj,
                          (UFG::qSymbol *)&qSymbol_GetInParam_VehicleInteractSkipSettingUpAI.mUID,
                          0);
                        v40 = (UFG::RagdollComponent *)v9->m_Components.p[42].m_pComponent;
                        if ( v40 )
                          UFG::RagdollComponent::ResetState(v40);
                        if ( !bDriver )
                          goto LABEL_90;
                        if ( v48 )
                          UFG::VehicleUtility::SetAIDriver((UFG::SimObject *)&v9->vfptr, v8, 0);
                        v41 = (UFG::VehicleDriverInterface *)v8->m_Components.p[23].m_pComponent;
                        if ( !v41 )
                        {
                          v42 = UFG::VehicleUtility::SetRemoteDriver(v8);
                          if ( !v42 )
                          {
LABEL_90:
                            if ( UFG::IsAnyLocalPlayer((UFG::SimObject *)&v9->vfptr) )
                            {
                              UFG::FollowCameraComponent::SetForceSnapOnEvent(0);
                              v43 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
                              if ( v43 )
                              {
                                v44 = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v43,
                                                                     UFG::ChaseCameraComponent::_TypeUID);
                                if ( v44 )
                                  UFG::ChaseCameraComponent::LockEye(v44, 0);
                              }
                            }
                            return;
                          }
                          v41 = (UFG::VehicleDriverInterface *)v42;
                        }
                        UFG::VehicleDriverInterface::SetDriver(v41, (UFG::SimObject *)&v9->vfptr);
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
void __fastcall UFG::VehicleUtility::PlaceCharacterInTrunk(UFG::SimObject *character, UFG::SimObjectVehicle *vehicle)
{
  UFG::SimObjectVehicle *v2; // r15
  UFG::SimObjectCVBase *v3; // rdi
  UFG::Event *v4; // rbp
  UFG::TargetingSystemBaseComponent *v5; // rbx
  UFG::SimComponent *v6; // rsi
  unsigned __int16 v7; // cx
  UFG::TargetingSystemPedBaseComponent *v8; // rax
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // r13
  UFG::SimObjectVehiclePropertiesComponent *v13; // r14
  ActionNode *v14; // rax
  ActionNode *v15; // r14
  UFG::allocator::free_link *v16; // r15
  unsigned int v17; // ebx
  UFG::Event *v18; // rax
  __int64 v19; // rbp
  __int64 v20; // rax
  ActionNodeRoot *v21; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  __int64 v23; // rax
  UFG::ActionTreeComponentBase *v24; // rcx
  ActionNodePlayable *v25; // rbp
  UEL::ParametersBase *v26; // r14
  unsigned __int16 v27; // dx
  UFG::SimComponent *v28; // rax
  bool v29; // di

  v2 = vehicle;
  v3 = (UFG::SimObjectCVBase *)character;
  v4 = 0i64;
  if ( character )
  {
    v7 = character->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v3);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v3->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v3->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v3->vfptr,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v3);
    }
    v5 = (UFG::TargetingSystemBaseComponent *)&v8->vfptr;
    v9 = v3->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[7].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v6 = v3->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v9 >> 12) & 1 )
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v3->vfptr,
                  UFG::ActionTreeComponent::_TypeUID);
        else
          v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v6 = v10;
      }
    }
    else
    {
      v6 = v3->m_Components.p[7].m_pComponent;
    }
    v11 = v3->m_Flags;
    if ( !((v11 >> 14) & 1) )
    {
      if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(
            (UFG::SimObjectGame *)&v3->vfptr,
            UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(
            (UFG::SimObjectGame *)&v3->vfptr,
            UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(
          (UFG::SimObjectGame *)&v3->vfptr,
          UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
  }
  else
  {
    v5 = 0i64;
    v6 = 0i64;
  }
  if ( v2 )
  {
    UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>((UFG::SimObjectCVBase *)&v2->vfptr);
    v12 = v2->m_Components.p[2].m_pComponent;
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>((UFG::SimObjectCVBase *)&v2->vfptr);
  }
  else
  {
    v12 = 0i64;
    v13 = 0i64;
  }
  if ( !(_S22_3 & 1) )
  {
    _S22_3 |= 1u;
    carTrunkPath.mPath.mCount = 0;
    carTrunkPath.mPath.mData.mOffset = 0i64;
    ActionPath::Append(&carTrunkPath, "\\Global\\Vehicle\\Interactions\\Trunk\\Grapple\\PutIn\\ForceInNOANIM");
    atexit(UFG::VehicleUtility::PlaceCharacterInTrunk_::_2_::_dynamic_atexit_destructor_for__carTrunkPath__);
  }
  if ( v13->m_eSimObjectVehicleType != 1 && v13->m_eSimObjectVehicleType != 6 && carTrunkPath.mPath.mCount & 0x7FFFFFFF )
  {
    v14 = ActionNode::Find(&carTrunkPath, 0i64);
    v15 = v14;
    if ( v5 && v6 && v14 )
    {
      UFG::TargetingSystemBaseComponent::SetTarget(v5, eTARGET_TYPE_VEHICLE, (UFG::SimObject *)&v2->vfptr);
      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, signed __int64, signed __int64))v5->vfptr[14].__vecDelDtor)(
        v5,
        28i64,
        1i64);
      v16 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      if ( v16 )
      {
        v17 = v3->mNode.mUID;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        UFG::TeleportEvent::TeleportEvent(
          (UFG::TeleportEvent *)v16,
          (UFG::qVector3 *)&v12[2].m_BoundComponentHandles,
          v17,
          0,
          UFG::TeleportEvent::m_Name,
          0);
        v4 = v18;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v4);
      v19 = ((__int64 (*)(void))v6[2].m_BoundComponentHandles.mNode.mNext[1].mNext->mPrev[9].mNext)();
      v20 = (__int64)v15->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v15->vfptr);
      v21 = (ActionNodeRoot *)v20;
      v22 = v6[2].m_BoundComponentHandles.mNode.mNext;
      v23 = *(char *)(v20 + 236);
      if ( (*((_QWORD *)&v22[4].mNext + v23) || v22[5].mPrev) && (ActionNodeRoot *)v19 != v21 )
      {
        v24 = (UFG::ActionTreeComponentBase *)*((_QWORD *)&v22[4].mNext + v23);
        if ( !v24 )
          v24 = (UFG::ActionTreeComponentBase *)v22[5].mPrev;
        if ( UFG::ActionTreeComponentBase::AllocateFor(v24, v21) )
          ActionNodeRoot::Init(v21, (ActionContext *)v6[2].m_BoundComponentHandles.mNode.mNext);
      }
      v25 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v15->vfptr[2].GetClassNameUID)(
                                    v15,
                                    v6[2].m_BoundComponentHandles.mNode.mNext);
      if ( v25 )
      {
        v26 = UEL::gCurrentParameters;
        if ( v3 )
        {
          v27 = v3->m_Flags;
          if ( (v27 >> 14) & 1 )
          {
            v28 = v3->m_Components.p->m_pComponent;
          }
          else if ( (v27 & 0x8000u) == 0 )
          {
            if ( (v27 >> 13) & 1 )
            {
              v28 = v3->m_Components.p->m_pComponent;
            }
            else if ( (v27 >> 12) & 1 )
            {
              v28 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v3->vfptr,
                      UFG::UELComponent::_TypeUID);
            }
            else
            {
              v28 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::UELComponent::_TypeUID);
            }
          }
          else
          {
            v28 = v3->m_Components.p->m_pComponent;
          }
          if ( v28 )
            UEL::gCurrentParameters = (UEL::ParametersBase *)&v28[1].m_TypeUID;
        }
        v29 = *((_BYTE *)&v6[3].m_SimObjIndex + 3) != 0;
        *((_BYTE *)&v6[3].m_SimObjIndex + 3) = 0;
        ActionController::Play((ActionController *)&v6[3], v25);
        ActionController::Update((ActionController *)&v6[3], 0.0);
        *((_BYTE *)&v6[3].m_SimObjIndex + 3) = v29;
        UEL::gCurrentParameters = v26;
      }
    }
    else
    {
      UFG::qPrintf(
        "PlaceCharacterInTrunk: Could Not Find TargetingSystemPedBaseComponent (0x%x) or ActionTreeComponent (0x%x) or Ac"
        "tion Node (0x%x)\n",
        v5,
        v6,
        v14);
    }
  }
}

// File Line: 561
// RVA: 0x68A270
UFG::AiDriverComponent *__fastcall UFG::VehicleUtility::SetAIDriver(UFG::SimObject *character, UFG::SimObjectVehicle *vehicle, bool isAmbient)
{
  bool v3; // bl
  UFG::SimObjectVehicle *v4; // rdi
  UFG::HumanDriverComponent *v5; // rax
  UFG::AiDriverComponent *result; // rax
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::AiDriverComponent *v9; // rax
  UFG::AiDriverComponent *v10; // rbp
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  unsigned int v13; // esi
  UFG::RoadSpaceComponent *v14; // rsi
  UFG::qMemoryPool *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::RoadSpaceComponent *v17; // rax
  unsigned __int16 v18; // cx
  UFG::SimObjectModifier v19; // [rsp+38h] [rbp-30h]

  v3 = isAmbient;
  v4 = vehicle;
  if ( !vehicle )
    goto LABEL_27;
  v5 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>((UFG::SimObjectCVBase *)&vehicle->vfptr);
  if ( v5 )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v5->vfptr);
  result = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&v4->vfptr);
  if ( !result )
  {
LABEL_27:
    v7 = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(v7, 0x628ui64, "AiDriverComponent", 0i64, 1u);
    if ( v8 )
    {
      UFG::AiDriverComponent::AiDriverComponent((UFG::AiDriverComponent *)v8, v3);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = v4->m_Flags;
    v12 = -1;
    if ( (v11 >> 14) & 1 )
    {
      v13 = 23;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      v13 = -1;
    }
    else
    {
      v13 = 23;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v19, (UFG::SimObject *)&v4->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v19, (UFG::SimComponent *)&v10->vfptr, v13);
    UFG::SimObjectModifier::Close(&v19);
    UFG::SimObjectModifier::~SimObjectModifier(&v19);
    v14 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
    if ( !v14 )
    {
      v15 = UFG::GetSimulationMemoryPool();
      v16 = UFG::qMemoryPool::Allocate(v15, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
      if ( v16 )
      {
        UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v16);
        v14 = v17;
      }
      else
      {
        v14 = 0i64;
      }
      v18 = v4->m_Flags;
      if ( (v18 >> 14) & 1 )
      {
        v12 = 24;
      }
      else if ( (v18 & 0x8000u) != 0 )
      {
        v12 = 24;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v19, (UFG::SimObject *)&v4->vfptr, 1);
      UFG::SimObjectModifier::AttachComponent(&v19, (UFG::SimComponent *)&v14->vfptr, v12);
      UFG::SimObjectModifier::Close(&v19);
      UFG::SimObjectModifier::~SimObjectModifier(&v19);
    }
    UFG::VehicleUtility::AttachAIActionTreeComponent(v4);
    if ( !v10->m_bIsParked )
      UFG::RoadSpaceComponent::AttachToRoadNetwork(v14, 0);
    result = v10;
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
  UFG::SimObjectVehicle *v1; // rbp
  UFG::SimComponent *v2; // r14
  UFG::SimComponent *v3; // rsi
  unsigned int v4; // ebx
  UFG::BoatPhysicsMoverComponent *v5; // rdi
  UFG::BikePhysicsMoverComponent *v6; // r15
  UFG::CarPhysicsMoverComponent *v7; // r12
  UFG::SimComponent *v8; // rdx
  UFG::qMemoryPool *v9; // rax
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
  unsigned __int16 v24; // cx
  unsigned int v25; // edi
  unsigned __int16 v26; // cx
  UFG::SimObjectModifier v28; // [rsp+38h] [rbp-50h]

  v1 = vehicle;
  v2 = 0i64;
  v3 = 0i64;
  v4 = -1;
  if ( !vehicle )
    goto LABEL_33;
  v5 = UFG::SimObjectVehicle::GetComponent<UFG::BoatPhysicsMoverComponent>(vehicle);
  v6 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v1);
  v7 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(v1);
  v8 = v1->m_Components.p[23].m_pComponent;
  if ( v8 )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v8);
  if ( v5 )
  {
    v9 = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(v9, 0x1A0ui64, "BoatDriverComponent", 0i64, 1u);
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
  if ( !v1->m_Components.p[24].m_pComponent )
  {
LABEL_33:
    v21 = UFG::GetSimulationMemoryPool();
    v22 = UFG::qMemoryPool::Allocate(v21, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
    if ( v22 )
    {
      UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v22);
      v2 = v23;
    }
    v24 = v1->m_Flags;
    if ( (v24 >> 14) & 1 )
    {
      v25 = 24;
    }
    else if ( (v24 & 0x8000u) == 0 )
    {
      v25 = -1;
    }
    else
    {
      v25 = 24;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v28, (UFG::SimObject *)&v1->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, v2, v25);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
  }
  v26 = v1->m_Flags;
  if ( (v26 >> 14) & 1 || (v26 & 0x8000u) != 0 )
    v4 = 23;
  UFG::SimObjectModifier::SimObjectModifier(&v28, (UFG::SimObject *)&v1->vfptr, 1);
  UFG::SimObjectModifier::AttachComponent(&v28, v3, v4);
  UFG::SimObjectModifier::Close(&v28);
  UFG::SimObjectModifier::~SimObjectModifier(&v28);
  return v3;
}

// File Line: 670
// RVA: 0x68B290
UFG::SimComponent *__fastcall UFG::VehicleUtility::SetRemoteDriver(UFG::SimObjectVehicle *vehicle)
{
  UFG::SimObjectVehicle *v1; // rbp
  UFG::SimComponent *v2; // r14
  UFG::SimComponent *v3; // rsi
  unsigned int v4; // ebx
  UFG::BoatPhysicsMoverComponent *v5; // rdi
  UFG::BikePhysicsMoverComponent *v6; // r15
  UFG::CarPhysicsMoverComponent *v7; // r12
  UFG::SimComponent *v8; // rdx
  UFG::qMemoryPool *v9; // rax
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
  unsigned __int16 v20; // cx
  unsigned int v21; // edi
  unsigned __int16 v22; // cx
  UFG::SimObjectModifier v24; // [rsp+38h] [rbp-50h]

  v1 = vehicle;
  v2 = 0i64;
  v3 = 0i64;
  v4 = -1;
  if ( !vehicle )
    goto LABEL_31;
  v5 = UFG::SimObjectVehicle::GetComponent<UFG::BoatPhysicsMoverComponent>(vehicle);
  v6 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v1);
  v7 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(v1);
  v8 = v1->m_Components.p[23].m_pComponent;
  if ( v8 )
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v8);
  if ( !v5 )
  {
    if ( v6 )
    {
      v9 = UFG::GetSimulationMemoryPool();
      v10 = UFG::qMemoryPool::Allocate(v9, 0x160ui64, "BikeRemoteDriverComponent", 0i64, 1u);
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
  if ( !v1->m_Components.p[24].m_pComponent )
  {
LABEL_31:
    v17 = UFG::GetSimulationMemoryPool();
    v18 = UFG::qMemoryPool::Allocate(v17, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
    if ( v18 )
    {
      UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v18);
      v2 = v19;
    }
    v20 = v1->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v21 = 24;
    }
    else if ( (v20 & 0x8000u) == 0 )
    {
      v21 = -1;
    }
    else
    {
      v21 = 24;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v24, (UFG::SimObject *)&v1->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v2, v21);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
  if ( v3 )
  {
    v22 = v1->m_Flags;
    if ( (v22 >> 14) & 1 || (v22 & 0x8000u) != 0 )
      v4 = 23;
    UFG::SimObjectModifier::SimObjectModifier(&v24, (UFG::SimObject *)&v1->vfptr, 1);
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
  UFG::SimObjectVehicle *v1; // rbx
  UFG::AiDriverComponent *v2; // rax
  UFG::SimComponent *v3; // rdi
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rdx
  UFG::HumanDriverComponent *v6; // rax
  UFG::RemoteDriverComponent *v7; // rax

  if ( vehicle )
  {
    v1 = vehicle;
    v2 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&vehicle->vfptr);
    v3 = (UFG::SimComponent *)&v2->vfptr;
    if ( v2 )
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v2->vfptr[16].__vecDelDtor)(v2) )
        UFG::WheeledVehicleManager::RemoveWheeledVehicleFromList(UFG::WheeledVehicleManager::m_Instance, v1);
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v3);
    }
    v4 = v1->m_Components.p[24].m_pComponent;
    if ( v4 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v4);
    v5 = v1->m_Components.p[19].m_pComponent;
    if ( v5 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v5);
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>((UFG::SimObjectCVBase *)&v1->vfptr);
    if ( v6 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v6->vfptr);
    v7 = UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>((UFG::SimObjectCVBase *)&v1->vfptr);
    if ( v7 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v7->vfptr);
  }
}

// File Line: 765
// RVA: 0x67B560
__int64 __fastcall UFG::VehicleUtility::GetVehicleOrientation(UFG::SimObjectVehicle *pVehicleSimObject, bool bIgnoreWheelState, float *pfReturn)
{
  unsigned int v3; // ebx
  float *v4; // rdi
  UFG::SimComponentHolder *v5; // rax
  UFG::TransformNodeComponent *v6; // rsi
  UFG::SimComponent *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  float v10; // xmm6_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm7_4
  float v14; // xmm11_4
  float v15; // xmm0_4
  float v16; // xmm10_4
  float v17; // xmm1_4
  float v18; // xmm9_4
  float v19; // xmm1_4
  float v20; // xmm6_4

  v3 = 0;
  v4 = pfReturn;
  if ( pVehicleSimObject )
  {
    v5 = pVehicleSimObject->m_Components.p;
    v6 = (UFG::TransformNodeComponent *)v5[2].m_pComponent;
    v7 = v5[34].m_pComponent;
    if ( v6 )
    {
      if ( v7 )
      {
        v8 = v7[10].m_SafePointerList.mNode.mPrev;
        v9 = 0i64;
        if ( v8 && BYTE4(v8[37].mNext) & 7 )
          v9 = v8;
        if ( bIgnoreWheelState || !v9 || !((LODWORD(v9[68].mNext) >> 4) & 1) )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v6);
          v10 = UFG::qVector3::msDirDown.y;
          v11 = UFG::qVector3::msDirDown.x;
          v12 = UFG::qVector3::msDirDown.z;
          v13 = *(float *)&FLOAT_1_0;
          v14 = (float)((float)(UFG::qVector3::msDirDown.y * v6->mWorldTransform.v1.y)
                      + (float)(UFG::qVector3::msDirDown.x * v6->mWorldTransform.v1.x))
              + (float)(UFG::qVector3::msDirDown.z * v6->mWorldTransform.v1.z);
          LODWORD(v15) = LODWORD(v14) & _xmm;
          v16 = (float)((float)(UFG::qVector3::msDirDown.y * v6->mWorldTransform.v0.y)
                      + (float)(UFG::qVector3::msDirDown.x * v6->mWorldTransform.v0.x))
              + (float)(UFG::qVector3::msDirDown.z * v6->mWorldTransform.v0.z);
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
                v20 = (float)((float)(v10 * v6->mWorldTransform.v2.y) + (float)(v11 * v6->mWorldTransform.v2.x))
                    + (float)(v12 * v6->mWorldTransform.v2.z);
                if ( v20 > 0.0 )
                  v3 = 5;
                if ( v4 )
                {
                  UFG::qACos(COERCE_FLOAT(LODWORD(v20) & _xmm));
                  *(_DWORD *)v4 = LODWORD(v20) & _xmm;
                }
              }
              else
              {
                LOBYTE(v3) = v16 <= 0.0;
                v3 += 3;
                if ( v4 )
                  *v4 = v19;
              }
            }
            else
            {
              LOBYTE(v3) = v14 <= 0.0;
              ++v3;
              if ( v4 )
                *v4 = v18;
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
  UFG::SimComponent *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // r11
  signed __int64 v3; // rdx
  unsigned int v4; // er9
  signed __int64 v5; // r11
  signed __int64 i; // rax
  int v7; // er8
  int v8; // ecx
  signed __int64 j; // rax
  int v10; // ecx
  signed __int64 k; // rax
  UFG::SimObjectCharacter *v12; // rcx

  if ( (vehicle_simobj->m_Flags & 0x8000u) == 0 )
    return 0;
  v1 = vehicle_simobj->m_Components.p[30].m_pComponent;
  if ( !v1 )
    return 0;
  v2 = v1[1].m_BoundComponentHandles.mNode.mNext;
  v3 = (signed __int64)&v1->m_BoundComponentHandles;
  v4 = 0;
  v5 = (signed __int64)&v2[-4];
  for ( i = v5; i != v3; i = *(_QWORD *)(i + 72) - 64i64 )
    ++v4;
  v7 = 0;
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v8 = 0;
    for ( j = v5; j != v3; j = *(_QWORD *)(j + 72) - 64i64 )
      ++v8;
    if ( v7 >= v8 )
    {
      v12 = 0i64;
    }
    else
    {
      v10 = v7;
      for ( k = v5; v10 > 0; k = *(_QWORD *)(k + 72) - 64i64 )
      {
        if ( k == v3 )
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
  UFG::SceneObjectProperties *v1; // rax
  UFG::SimObjectVehicle *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rax
  float *v5; // rax
  UFG::qSymbolUC *v6; // rax
  char *v7; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v1 = vehicle->m_pSceneObj;
  v2 = vehicle;
  v3 = v1->mpWritableProperties;
  if ( !v3 )
    v3 = v1->mpConstProperties;
  v4 = UFG::SimObjectUtility::FindDriverProfile(v3);
  if ( v4 )
  {
    v5 = UFG::qPropertySet::Get<float>(v4, (UFG::qSymbol *)&qSymbol_RadioStation.mUID, DEPTH_RECURSE);
    if ( v5 )
      PropertyUtils::SetRuntime<float>(v2->m_pSceneObj, (UFG::qSymbol *)&qSymbol_RadioStation.mUID, *v5);
  }
  else
  {
    v6 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, v2->m_pSceneObj->m_NameUID);
    v7 = UFG::qSymbol::as_cstr_dbg(v6);
    UFG::qPrintf("Did not set Radiostation. No Driver Profile found in %s\n", v7);
  }
}

// File Line: 888
// RVA: 0x6785F0
void __fastcall UFG::VehicleUtility::ExitVehicleNow(UFG::SimObject *pOccupantSimObject, bool bForceClearDriver, bool bDispatchNonCameraEvents, bool bDispatchCameraEvents)
{
  UFG::VehicleUtility::FinishExitingVehicle(
    pOccupantSimObject,
    bForceClearDriver,
    bDispatchNonCameraEvents,
    bDispatchCameraEvents);
}

// File Line: 900
// RVA: 0x678FB0
void __fastcall UFG::VehicleUtility::FinishExitingVehicle(UFG::SimObject *pOccupantSimObject, bool bForceClearDriver, bool bDispatchNonCameraEvents, bool bDispatchCameraEvents)
{
  bool v4; // r12
  bool v5; // bl
  bool v6; // r13
  UFG::SimObjectGame *v7; // rdi
  UFG::CharacterOccupantComponent *v8; // r14
  unsigned __int16 v9; // cx
  UFG::CharacterOccupantComponent *v10; // rax
  bool v11; // r15
  UFG::SimObjectVehicle *v12; // rsi
  UFG::TargetingSystemBaseComponent *v13; // rdx
  unsigned __int16 v14; // cx
  UFG::TargetingSystemBaseComponent *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::TargetingSimObject *v17; // rcx
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::AiDriverComponent *v21; // rax
  UFG::AiDriverComponent *v22; // rbx
  UFG::SimComponentHolder *v23; // rax
  float *v24; // rbx
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm8_4
  UFG::GameStatTracker *v28; // rax
  UFG::GameStatTracker *v29; // rax
  UFG::GameStatTracker *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::SimComponent *v36; // rbx
  UFG::AiDriverComponent *v37; // rax
  char v38; // r15
  UFG::SimObject **v39; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  UFG::VehicleSubjectComponent *v42; // rax
  __int64 v43; // rbx
  UFG::TargetingSystemVehicleComponent *v44; // rax
  UFG::TargetingSystemVehicleComponent *v45; // r15
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v46; // r10
  unsigned __int8 v47; // dl
  signed __int64 v48; // rbx
  UFG::VehicleOccupantComponent *v49; // rcx
  unsigned __int16 v50; // cx
  UFG::SimComponent *v51; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> object; // [rsp+20h] [rbp-11h]
  __int64 v53; // [rsp+38h] [rbp+7h]
  UFG::allocator::free_link *v54; // [rsp+98h] [rbp+67h]

  v4 = bDispatchCameraEvents;
  v5 = bDispatchNonCameraEvents;
  v6 = bForceClearDriver;
  v7 = (UFG::SimObjectGame *)pOccupantSimObject;
  if ( pOccupantSimObject )
  {
    v9 = pOccupantSimObject->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v8 = (UFG::CharacterOccupantComponent *)v7->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v10 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v7,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v9 >> 12) & 1 )
        {
          v10 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v7,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v10 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v7->vfptr,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v10 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v7,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      v8 = v10;
    }
    if ( v8 )
    {
      v11 = v8->mTargetType == 4;
      v12 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v8);
      goto LABEL_16;
    }
  }
  else
  {
    v8 = 0i64;
  }
  v11 = 0;
  v12 = 0i64;
LABEL_16:
  if ( !UFG::IsAnyLocalPlayer((UFG::SimObject *)&v7->vfptr) )
    goto LABEL_61;
  if ( v7 )
  {
    v14 = v7->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = (UFG::TargetingSystemBaseComponent *)v7->m_Components.p[20].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v7,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v7,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v15 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v7->vfptr,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v13 = v15;
    }
    else
    {
      v13 = (UFG::TargetingSystemBaseComponent *)v7->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  object.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
  object.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
  object.m_pPointer = (UFG::SimObject *)&v7->vfptr;
  if ( v7 )
  {
    v16 = v7->m_SafePointerList.mNode.mPrev;
    v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
    object.mPrev = v16;
    object.mNext = &v7->m_SafePointerList.mNode;
    v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
  }
  if ( v13
    && (v17 = &v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_ACTION_HIJACK]],
        v17->m_pTarget.m_pPointer)
    && v17->m_bLock )
  {
    if ( v5 )
    {
      v18 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v54 = v18;
      if ( v18 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v18, "EVT_MOUNT_VEHICLE", &object);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v18);
    }
    if ( v4 )
    {
      v19 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v54 = v19;
      if ( v19 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v19, "EVT_MOUNT_VEHICLE_CAMERA", &object);
LABEL_49:
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v19);
      goto LABEL_50;
    }
  }
  else
  {
    if ( v5 )
    {
      v20 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v54 = v20;
      if ( v20 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v20, "EVT_DISMOUNT_VEHICLE", &object);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v20);
    }
    if ( v4 )
    {
      v19 = UFG::qMalloc(0x50ui64, "VehicleInteractTask", 0i64);
      v54 = v19;
      if ( v19 )
        UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v19, "EVT_DISMOUNT_VEHICLE_CAMERA", &object);
      goto LABEL_49;
    }
  }
LABEL_50:
  if ( v11 )
  {
LABEL_55:
    if ( v12 )
    {
      v23 = v12->m_Components.p;
      v24 = (float *)v23[2].m_pComponent;
      if ( v24 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v23[2].m_pComponent);
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
    goto LABEL_58;
  }
  if ( v12 )
  {
    v21 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&v12->vfptr);
    v22 = v21;
    if ( v21 && v21->m_DrivingRole == 4 )
    {
      v21->m_IsAmbient = 1;
      UFG::AiDriverComponent::SetDrivingRole(v21, 0);
      UFG::AiDriverComponent::SetDrivingMode(v22, 1u);
      UFG::AiDriverComponent::SetObeyTrafficLights(v22, 1);
    }
    goto LABEL_55;
  }
LABEL_58:
  if ( object.m_pPointer )
  {
    v32 = object.mPrev;
    v33 = object.mNext;
    object.mPrev->mNext = object.mNext;
    v33->mPrev = v32;
    object.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
    object.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
  }
  object.m_pPointer = 0i64;
  v34 = object.mPrev;
  v35 = object.mNext;
  object.mPrev->mNext = object.mNext;
  v35->mPrev = v34;
  object.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
  object.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&object;
LABEL_61:
  if ( v12 )
    v36 = v12->m_Components.p[23].m_pComponent;
  else
    v36 = 0i64;
  if ( v11 )
  {
    if ( v36 )
    {
      if ( v12
        && (v37 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&v12->vfptr)) != 0i64 )
      {
        v38 = ((__int64 (__fastcall *)(UFG::AiDriverComponent *))v37->vfptr[16].__vecDelDtor)(v37);
        if ( v38 )
          UFG::PedSpawnManager::GetInstance();
      }
      else
      {
        v38 = 0;
      }
      if ( v6 || !v38 )
      {
        UFG::VehicleUtility::ClearDriver(v12);
      }
      else
      {
        v39 = &v36[3].m_pSimObject;
        if ( v36[3].m_BoundComponentHandles.mNode.mNext )
        {
          v40 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)*v39;
          v41 = v36[3].m_BoundComponentHandles.mNode.mPrev;
          v40->mNext = v41;
          v41->mPrev = v40;
          *v39 = (UFG::SimObject *)v39;
          v36[3].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v36[3].m_pSimObject;
        }
        v36[3].m_BoundComponentHandles.mNode.mNext = 0i64;
      }
    }
    if ( v12 )
    {
      v42 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v12);
      if ( v42 )
        UFG::VehicleSubjectComponent::ReassignChasersTo(v42, (UFG::SimObject *)&v7->vfptr);
    }
  }
  if ( v8 )
  {
    v43 = (unsigned int)v8->mTargetType;
    if ( v12 )
    {
      v44 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>((UFG::SimObjectCVBase *)&v12->vfptr);
      v45 = v44;
      if ( v44 )
      {
        v46 = v44->vfptr;
        v53 = 0i64;
        object.m_pPointer = 0i64;
        object.mNext = 0i64;
        LODWORD(object.mPrev) = 0;
        ((void (__fastcall *)(UFG::TargetingSystemVehicleComponent *, _QWORD, _QWORD, _QWORD, UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *, _QWORD, _QWORD, _QWORD))v46[14].__vecDelDtor)(
          v44,
          (unsigned int)v43,
          0i64,
          0i64,
          object.mPrev,
          0i64,
          0i64,
          0i64);
        v47 = v45->m_pTargetingMap->m_Map.p[v43];
        if ( v47 )
        {
          v48 = v47;
          UFG::TargetingSimObject::SetTarget(&v45->m_pTargets[v48], 0i64);
          UFG::TargetingSimObject::SetLock(&v45->m_pTargets[v48], 0);
        }
      }
      v49 = (UFG::VehicleOccupantComponent *)v12->m_Components.p[30].m_pComponent;
      if ( v49 )
        UFG::VehicleOccupantComponent::RemoveOccupant(v49, v8);
    }
    UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v8->vfptr);
  }
  if ( !v7
    || ((v50 = v7->m_Flags, !((v50 >> 14) & 1)) ? ((v50 & 0x8000u) == 0 ? (!((v50 >> 13) & 1) ? (!((v50 >> 12) & 1) ? (v51 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RagdollComponent::_TypeUID)) : (v51 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RagdollComponent::_TypeUID))) : (v51 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RagdollComponent::_TypeUID))) : (v51 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RagdollComponent::_TypeUID))) : (v51 = v7->m_Components.p[42].m_pComponent),
        !v51) )
  {
    UFG::RagdollComponent::PropertiesOnActivateNew(v7->m_pSceneObj, 0);
  }
}

// File Line: 1064
// RVA: 0x67EA00
bool __fastcall UFG::VehicleUtility::IsClassTypeRoadTypeMatch(UFG::qPropertySet *set, unsigned int roadType)
{
  unsigned int v2; // ebx
  UFG::qPropertySet *v3; // rdi
  char v4; // si

  v2 = roadType;
  v3 = set;
  v4 = UFG::SimObjectUtility::IsClassType(set, (UFG::qSymbol *)&qSymbol_Boat_22.mUID);
  if ( UFG::SimObjectUtility::IsClassType(v3, (UFG::qSymbol *)&qSymbol_Ferry.mUID) )
    return v2 == 2;
  if ( v4 )
    return v2 == 3;
  if ( UFG::SimObjectUtility::IsClassType(v3, (UFG::qSymbol *)&qSymbol_Tram.mUID) )
    return v2 == 1;
  return v2 == 0;
}

// File Line: 1095
// RVA: 0x670880
void __fastcall UFG::VehicleUtility::AttachAIActionTreeComponent(UFG::SimObjectVehicle *vehicle)
{
  UFG::SimObjectVehicle *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // eax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rsi
  unsigned __int16 v8; // cx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h]

  v1 = vehicle;
  if ( !vehicle || !vehicle->m_Components.p[19].m_pComponent )
  {
    v2 = UFG::GetSimulationMemoryPool();
    v3 = UFG::qMemoryPool::Allocate(v2, 0x678ui64, "AIActionTreeComponent", 0i64, 1u);
    v4 = -1;
    if ( v3 )
    {
      v5 = UFG::qStringHashUpper32("AIActionTreeComponent", 0xFFFFFFFF);
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
    v8 = v1->m_Flags;
    if ( (v8 >> 14) & 1 || (v8 & 0x8000u) != 0 )
      v4 = 19;
    UFG::SimObjectModifier::SimObjectModifier(&v9, (UFG::SimObject *)&v1->vfptr, 1);
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
  signed __int64 v3; // rdi
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::TargetingSystemPedBaseComponent *v6; // rax

  if ( vehicle )
    v1 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>((UFG::SimObjectCVBase *)&vehicle->vfptr);
  else
    v1 = 0i64;
  v2 = UFG::TargetingSystemBaseComponent::ms_eVehicleRoleTargetTypes;
  v3 = 7i64;
  do
  {
    v4 = (UFG::SimObjectCVBase *)v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[*(unsigned int *)v2]].m_pTarget.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v4->vfptr,
                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v4->vfptr,
                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v4->vfptr,
                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
      }
      if ( v6 )
        UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v6);
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
  UFG::SimObjectVehicle *v2; // rdx
  UFG::PhysicsVehicle *v3; // rcx
  UFG::SimComponent *v4; // rax
  float v5; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::SimComponentHolder *v9; // rax
  float *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 velocity; // [rsp+20h] [rbp-28h]

  v2 = pVehicle;
  v3 = 0i64;
  if ( v2 )
  {
    v4 = v2->m_Components.p[34].m_pComponent;
    if ( !v4 )
      goto LABEL_8;
    v3 = (UFG::PhysicsVehicle *)v4[10].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v4 = 0i64;
  }
  if ( v4 && v3 )
  {
    v5 = forwardSpeedKPH * 0.27777779;
    v6 = v3->mBodyTransform.v0.x * (float)(forwardSpeedKPH * 0.27777779);
    v7 = v3->mBodyTransform.v0.y * (float)(forwardSpeedKPH * 0.27777779);
    v8 = v3->mBodyTransform.v0.z;
    velocity.x = v6;
    velocity.y = v7;
    velocity.z = v8 * v5;
    UFG::PhysicsVehicle::SetVelocity(v3, &velocity);
    return;
  }
LABEL_8:
  if ( v2 )
  {
    v9 = v2->m_Components.p;
    v10 = (float *)v9[2].m_pComponent;
    if ( v10 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9[2].m_pComponent);
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
void __fastcall UFG::VehicleUtility::OverrideLinearVelocityMagnitudeKPH(UFG::SimObjectVehicle *pVehicle, float speedKPH)
{
  UFG::PhysicsVehicle *v2; // rbx
  float v3; // xmm6_4
  UFG::SimComponent *v4; // rax
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  UFG::SimComponentHolder *v12; // rax
  UFG::SimComponent *v13; // rbx
  float v14; // xmm2_4
  __m128 v15; // xmm3
  float v16; // xmm4_4
  __m128 v17; // xmm5
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm6_4
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]

  v2 = 0i64;
  v3 = speedKPH;
  if ( pVehicle )
  {
    v4 = pVehicle->m_Components.p[34].m_pComponent;
    if ( !v4 )
      goto LABEL_13;
    v2 = (UFG::PhysicsVehicle *)v4[10].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v4 = 0i64;
  }
  if ( v4 && v2 )
  {
    UFG::PhysicsVehicle::GetVelocity(v2, &result);
    v5 = (__m128)LODWORD(result.x);
    v6 = v5;
    v6.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(result.y * result.y))
                   + (float)(result.z * result.z);
    if ( v6.m128_f32[0] <= 0.001 )
    {
      v8 = v2->mBodyTransform.v0.x;
      v9 = v2->mBodyTransform.v0.y;
      v10 = v2->mBodyTransform.v0.z;
    }
    else
    {
      v7 = 0.0;
      if ( v6.m128_f32[0] != 0.0 )
        v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
      v8 = result.x * v7;
      v9 = result.y * v7;
      v10 = result.z * v7;
    }
    v11 = v3 * 0.27777779;
    result.x = v8 * v11;
    result.y = v9 * v11;
    result.z = v10 * v11;
    UFG::PhysicsVehicle::SetVelocity(v2, &result);
    return;
  }
LABEL_13:
  if ( pVehicle )
  {
    v12 = pVehicle->m_Components.p;
    v13 = v12[2].m_pComponent;
    if ( v13 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12[2].m_pComponent);
      v14 = *(float *)&v13[4].vfptr;
      v15 = (__m128)HIDWORD(v13[4].vfptr);
      v16 = *(float *)&v13[4].m_SafePointerList.mNode.mPrev;
      v17 = v15;
      v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
      if ( v17.m128_f32[0] <= 0.001 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13);
        v19 = *(float *)&v13[2].vfptr;
        v20 = *((float *)&v13[2].vfptr + 1);
        v21 = *(float *)&v13[2].m_SafePointerList.mNode.mPrev;
      }
      else
      {
        v18 = 0.0;
        if ( v17.m128_f32[0] != 0.0 )
          v18 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
        v19 = v14 * v18;
        v20 = v15.m128_f32[0] * v18;
        v21 = v16 * v18;
      }
      v22 = v3 * 0.27777779;
      *(float *)&v13[4].vfptr = v19 * v22;
      *((float *)&v13[4].vfptr + 1) = v20 * v22;
      *(float *)&v13[4].m_SafePointerList.mNode.mPrev = v21 * v22;
    }
  }
}

// File Line: 1207
// RVA: 0x67EBA0
bool __fastcall UFG::VehicleUtility::IsDriverTypeInList(UFG::SimObject *pSimObject, UFG::qPropertyList *list)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::qPropertySet *v3; // rcx

  if ( pSimObject && (v2 = pSimObject->m_pSceneObj) != 0i64 )
  {
    v3 = v2->mpWritableProperties;
    if ( !v3 )
      return UFG::VehicleUtility::IsDriverTypeInList(v2->mpConstProperties, list);
  }
  else
  {
    v3 = 0i64;
  }
  return UFG::VehicleUtility::IsDriverTypeInList(v3, list);
}

// File Line: 1213
// RVA: 0x67EBD0
char __fastcall UFG::VehicleUtility::IsDriverTypeInList(UFG::qPropertySet *pPropertySet, UFG::qPropertyList *list)
{
  UFG::qPropertyList *v2; // rdi
  UFG::qPropertyList *v3; // rax
  unsigned int v4; // esi
  UFG::qSymbol *v5; // r14
  unsigned int v6; // ebx
  UFG::qSymbol *v7; // r9
  __int64 v8; // rdx
  __int64 v9; // rax

  v2 = list;
  if ( !list )
    return 0;
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pPropertySet,
         (UFG::qSymbol *)&qSymbol_VehicleDriverTypeList.mUID,
         DEPTH_RECURSE);
  if ( !v3 )
    return 0;
  v4 = v3->mNumElements;
  v5 = v4 ? UFG::qPropertyList::Get<UFG::qSymbol>(v3, 0) : 0i64;
  v6 = v2->mNumElements;
  v7 = v6 ? UFG::qPropertyList::Get<UFG::qSymbol>(v2, 0) : 0i64;
  v8 = 0i64;
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v9 = 0i64;
    if ( v6 )
      break;
LABEL_13:
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= v4 )
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

