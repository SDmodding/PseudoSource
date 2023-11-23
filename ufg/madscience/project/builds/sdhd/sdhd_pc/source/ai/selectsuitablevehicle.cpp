// File Line: 33
// RVA: 0x14ACC90
__int64 dynamic_initializer_for__UFG::SelectSuitableVehicle::PrintChannel__()
{
  UFG::qString::qString(&stru_14206D7E0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SelectSuitableVehicle::PrintChannel__);
}

// File Line: 36
// RVA: 0x35FA00
bool __fastcall UFG::SelectSuitableVehicle::GetFollowTarget(
        UFG::SimObjectCVBase *pMySelf,
        UFG::SimObjectGame **ppFollowTarget,
        UFG::SimObject **ppFollowTargetVehicle)
{
  UFG::SimObjectGame *v6; // rdi
  UFG::SimObject *v7; // rbp
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  UFG::eAIObjective m_CurrentObjective; // ecx
  signed __int16 v11; // cx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v14; // cx
  UFG::SimComponent *v15; // rax

  v6 = 0i64;
  v7 = 0i64;
  if ( pMySelf )
  {
    m_Flags = pMySelf->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(pMySelf);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            pMySelf,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            pMySelf,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  m_CurrentObjective = ComponentOfTypeHK->m_CurrentObjective;
  if ( (m_CurrentObjective == eAI_OBJECTIVE_FOLLOW_TARGET || m_CurrentObjective == eAI_OBJECTIVE_BE_ALLY) && pMySelf )
  {
    v11 = pMySelf->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      m_pComponent = pMySelf->m_Components.p[20].m_pComponent;
    }
    else if ( v11 >= 0 )
    {
      if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(pMySelf, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(pMySelf, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = pMySelf->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v6 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 38i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v6 )
      {
        v14 = v6->m_Flags;
        if ( (v14 & 0x4000) != 0 )
        {
          v15 = v6->m_Components.p[20].m_pComponent;
        }
        else if ( v14 >= 0 )
        {
          if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v15 = UFG::SimObject::GetComponentOfType(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v15 = v6->m_Components.p[20].m_pComponent;
        }
        if ( v15 )
          v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v15[1].m_Flags + 36i64)
                                  + *(_QWORD *)&v15[1].m_TypeUID
                                  + 40);
      }
    }
  }
  *ppFollowTarget = v6;
  *ppFollowTargetVehicle = v7;
  return v6 != 0i64;
}

// File Line: 72
// RVA: 0x36C1C0
__int64 __fastcall UFG::SelectSuitableVehicle::IsValidTarget(
        ActionContext *pActionContext,
        UFG::SimObjectCVBase *pMyself,
        UFG::SimObjectGame *pVehicle,
        UFG::SimObjectCVBase *pFollowTarget,
        UFG::SimObjectGame *pFollowTargetVehicle)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r12
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *Texture; // rax
  __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  signed int v13; // edi
  __int64 NumberOfSeats; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *ReservationList; // rax
  signed int v16; // ebp
  __int64 v17; // r14
  UFG::SimObjectCVBase **v18; // r15
  __int64 v19; // rax
  UFG::SimObjectCVBase *v20; // rbx
  __int16 v21; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  signed __int16 v27; // cx
  UFG::PhysicsMoverInterface *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  __int64 v33; // [rsp+20h] [rbp-58h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v34; // [rsp+28h] [rbp-50h]
  bool v35; // [rsp+90h] [rbp+18h]

  v35 = pFollowTarget != 0i64;
  if ( !pVehicle )
    return 0i64;
  m_Flags = pVehicle->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = pVehicle->m_Components.p[30].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pVehicle, UFG::VehicleOccupantComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pVehicle, UFG::VehicleOccupantComponent::_TypeUID);
  m_pComponent = ComponentOfTypeHK;
LABEL_11:
  if ( !m_pComponent )
    return 0i64;
  Texture = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
  if ( Texture )
  {
    v11 = Texture->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      v12 = Texture->m_Components.p[6].m_pComponent;
    }
    else if ( v11 >= 0 )
    {
      v12 = (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(Texture, UFG::HealthComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(Texture, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      v12 = Texture->m_Components.p[6].m_pComponent;
    }
    if ( v12 && BYTE4(v12[1].m_BoundComponentHandles.mNode.mPrev) )
      return 0i64;
  }
  v13 = -1;
  NumberOfSeats = (int)UFG::VehicleOccupantComponent::GetNumberOfSeats((UFG::VehicleOccupantComponent *)m_pComponent);
  ReservationList = UFG::VehicleOccupantComponent::GetReservationList((UFG::VehicleOccupantComponent *)m_pComponent);
  v16 = pVehicle == pFollowTargetVehicle;
  v33 = NumberOfSeats;
  v17 = pVehicle == pFollowTargetVehicle;
  v34 = ReservationList;
  if ( v17 >= NumberOfSeats )
    return 0i64;
  v18 = (UFG::SimObjectCVBase **)(&ReservationList->m_pPointer
                                + 2 * (pVehicle == pFollowTargetVehicle)
                                + (pVehicle == pFollowTargetVehicle));
  v19 = NumberOfSeats;
  do
  {
    v20 = *v18;
    if ( *v18 == pMyself )
    {
      v13 = v16;
      goto LABEL_60;
    }
    if ( v20 )
    {
      if ( !UFG::AreCharactersAllied(*v18, pMyself) && (!v35 || pFollowTarget != v20) )
      {
        v21 = v20->m_Flags;
        if ( (v21 & 0x4000) != 0 )
        {
          ComponentOfType = v20->m_Components.p[44].m_pComponent;
        }
        else if ( v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
        {
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v20, UFG::CharacterOccupantComponent::_TypeUID);
        }
        if ( ComponentOfType && LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) != 13 )
        {
LABEL_44:
          if ( v13 != -1
            && UFG::VehicleOccupantComponent::GetOccupant((UFG::VehicleOccupantComponent *)m_pComponent, v13, 0i64) == pMyself )
          {
            v23 = &v34[v13];
            if ( v23->m_pPointer )
            {
              mPrev = v23->mPrev;
              mNext = v23->mNext;
              mPrev->mNext = mNext;
              mNext->mPrev = mPrev;
              v23->mPrev = v23;
              v23->mNext = v23;
            }
            v23->m_pPointer = 0i64;
          }
          return 0i64;
        }
        goto LABEL_59;
      }
      v27 = pVehicle->m_Flags;
      if ( (v27 & 0x4000) == 0 )
      {
        if ( v27 < 0 )
        {
          v28 = (UFG::PhysicsMoverInterface *)pVehicle->m_Components.p[34].m_pComponent;
          goto LABEL_57;
        }
        if ( (v27 & 0x2000) == 0 )
        {
          if ( (v27 & 0x1000) != 0 )
            v28 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  pVehicle,
                                                  UFG::PhysicsMoverInterface::_TypeUID);
          else
            v28 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                  pVehicle,
                                                  UFG::PhysicsMoverInterface::_TypeUID);
LABEL_57:
          if ( v28 && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v28) > 40.0 )
            goto LABEL_44;
        }
      }
LABEL_59:
      v19 = v33;
      goto LABEL_60;
    }
    if ( v13 == -1 )
      v13 = v16;
LABEL_60:
    ++v17;
    ++v16;
    v18 += 3;
  }
  while ( v17 < v19 );
  if ( v13 == -1 )
    return 0i64;
  v29 = &v34[v13];
  if ( v29[1].mPrev )
  {
    v30 = v29->mPrev;
    v31 = v29->mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    v29->mPrev = v29;
    v29->mNext = v29;
  }
  v29[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)pMyself;
  if ( pMyself )
  {
    v32 = pMyself->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v32->mNext = v29;
    v29->mPrev = v32;
    v29->mNext = &pMyself->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pMyself->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v29;
  }
  return (unsigned int)(v13 + 4);
}

// File Line: 180
// RVA: 0x3842D0
char __fastcall UFG::SelectSuitableVehicle::SelectVehicle(UFG::SelectSuitableVehicle::Params *params)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObjectCVBase *m_pPointer; // rsi
  bool FollowTarget; // al
  char v5; // bl
  float v6; // xmm7_4
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbol *v9; // rax
  unsigned int mUID; // eax
  UFG::SimObjectCVBase *v11; // rcx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::InteractorComponent *m_pComponent; // r13
  __int16 v15; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *p_mNext; // rbp
  char v18; // r13
  UFG::SimObjectCVBase *v19; // r14
  UFG::SimObjectGame *pFollowTargetVehicle; // r15
  UFG::SimObjectGame *mNext; // rbx
  float v22; // xmm6_4
  int IsValidTarget; // r14d
  bool v24; // di
  __int16 v25; // dx
  UFG::InteractableComponent *v26; // r10
  UFG::SimComponent *v27; // rax
  bool ignoreMeshTest; // r9
  UFG::SimObject *v29; // rdi
  __int16 v30; // cx
  UFG::TargetingSystemBaseComponent *v31; // rdi
  UFG::SimComponent *v32; // rax
  UFG::TargetingSimObject *m_pTargets; // rdx
  UFG::SimObject *pVehicle; // rsi
  __int64 v35; // rbx
  UFG::TargetingSimObject *v36; // rdx
  UFG::SimObject *v37; // rsi
  __int64 v38; // rbx
  UFG::InteractorComponent *v40; // [rsp+30h] [rbp-A8h]
  UFG::SimObject *ppFollowTarget; // [rsp+38h] [rbp-A0h] BYREF
  UFG::SimObject *ppFollowTargetVehicle; // [rsp+40h] [rbp-98h] BYREF
  UFG::InteractionPoint *pIP; // [rsp+48h] [rbp-90h]
  UFG::TransformNodeComponent *m_pSimComponent; // [rsp+50h] [rbp-88h]
  UFG::qStaticBitField<6> bfTestIP; // [rsp+E0h] [rbp+8h] BYREF
  bool v46; // [rsp+E8h] [rbp+10h]
  UFG::qSymbol targetClassType; // [rsp+F0h] [rbp+18h] BYREF
  UFG::SimObjectGame *v48; // [rsp+F8h] [rbp+20h]

  m_pTransformNodeComponent = 0i64;
  m_pPointer = (UFG::SimObjectCVBase *)params->pActionContext->mSimObject.m_pPointer;
  ppFollowTarget = 0i64;
  ppFollowTargetVehicle = 0i64;
  FollowTarget = UFG::SelectSuitableVehicle::GetFollowTarget(
                   m_pPointer,
                   (UFG::SimObjectGame **)&ppFollowTarget,
                   &ppFollowTargetVehicle);
  v48 = 0i64;
  v5 = FollowTarget;
  v46 = FollowTarget;
  if ( FollowTarget )
    v6 = FLOAT_9999999_0;
  else
    v6 = params->maxSearchRadius * params->maxSearchRadius;
  targetClassType.mUID = params->filterClassSymbol.mUID;
  LOBYTE(bfTestIP.mBits[0]) = targetClassType.mUID != -1;
  if ( targetClassType.mUID == -1 )
  {
    if ( m_pPointer && (m_pSceneObj = m_pPointer->m_pSceneObj) != 0i64 )
    {
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( mpWritableProperties )
      {
LABEL_11:
        v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
               mpWritableProperties,
               (UFG::qArray<unsigned long,0> *)&qSymbol_VehicleSearchFilter,
               DEPTH_RECURSE);
        if ( v9 )
        {
          mUID = v9->mUID;
          if ( mUID != -1 )
          {
            targetClassType.mUID = mUID;
            LOBYTE(bfTestIP.mBits[0]) = 1;
          }
        }
        goto LABEL_14;
      }
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    }
    else
    {
      mpWritableProperties = 0i64;
    }
    if ( mpWritableProperties )
      goto LABEL_11;
  }
LABEL_14:
  v11 = (UFG::SimObjectCVBase *)params->pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    m_Flags = v11->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v11);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v11,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            v11,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  m_pSimComponent = (UFG::TransformNodeComponent *)ComponentOfTypeHK->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  if ( m_pPointer )
  {
    v15 = m_pPointer->m_Flags;
    if ( (v15 & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InteractorComponent *)m_pPointer->m_Components.p[29].m_pComponent;
    }
    else
    {
      if ( v15 < 0 || (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractorComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractorComponent::_TypeUID);
      m_pComponent = (UFG::InteractorComponent *)ComponentOfType;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v40 = m_pComponent;
  p_mNext = (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext;
  pIP = 0i64;
  if ( &UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext == (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> **)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152) )
    goto LABEL_92;
  v18 = bfTestIP.mBits[0];
  v19 = (UFG::SimObjectCVBase *)ppFollowTarget;
  pFollowTargetVehicle = (UFG::SimObjectGame *)ppFollowTargetVehicle;
  while ( 1 )
  {
    if ( !v5 || (mNext = pFollowTargetVehicle) == 0i64 )
      mNext = (UFG::SimObjectGame *)p_mNext[2].mNode.mNext;
    bfTestIP.mBits[0] = 0i64;
    v22 = FLOAT_N1_0;
    if ( mNext )
      m_pTransformNodeComponent = mNext->m_pTransformNodeComponent;
    if ( mNext == pFollowTargetVehicle )
    {
      v22 = FLOAT_N1_0;
    }
    else
    {
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v22 = (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y
                                    - m_pSimComponent->mWorldTransform.v3.y)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y
                                    - m_pSimComponent->mWorldTransform.v3.y))
                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                    - m_pSimComponent->mWorldTransform.v3.x)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                    - m_pSimComponent->mWorldTransform.v3.x)))
            + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - m_pSimComponent->mWorldTransform.v3.z)
                    * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - m_pSimComponent->mWorldTransform.v3.z));
        if ( v22 > v6 )
          goto LABEL_67;
      }
      if ( v18 && !UFG::SimObjectUtility::IsClassType(mNext, &targetClassType)
        || UFG::SimObjectUtility::IsClassType(mNext, &qSymbol_Taxi)
        || UFG::SimObjectUtility::IsClassType(mNext, &qSymbol_Minibus)
        || UFG::SimObjectUtility::IsClassType(mNext, &qSymbol_Tram) )
      {
        goto LABEL_67;
      }
    }
    IsValidTarget = UFG::SelectSuitableVehicle::IsValidTarget(
                      params->pActionContext,
                      m_pPointer,
                      mNext,
                      v19,
                      pFollowTargetVehicle);
    v24 = IsValidTarget != 0;
    if ( IsValidTarget )
    {
      if ( mNext )
      {
        v25 = mNext->m_Flags;
        if ( (v25 & 0x4000) != 0 )
        {
          v26 = (UFG::InteractableComponent *)mNext->m_Components.p[12].m_pComponent;
        }
        else if ( v25 >= 0 )
        {
          v27 = (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(mNext, UFG::InteractableComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(mNext, UFG::InteractableComponent::_TypeUID);
          v26 = (UFG::InteractableComponent *)v27;
        }
        else
        {
          v26 = (UFG::InteractableComponent *)mNext->m_Components.p[12].m_pComponent;
        }
        if ( v26 )
        {
          ignoreMeshTest = params->ignoreMeshTest;
          bfTestIP.mBits[(__int64)(IsValidTarget - 3) >> 6] |= 1i64 << ((IsValidTarget - 3) & 0x3F);
          pIP = UFG::InteractableComponent::FindBestInteractionPoint(v26, m_pPointer, &bfTestIP, ignoreMeshTest);
          v24 = pIP != 0i64;
        }
      }
      v19 = (UFG::SimObjectCVBase *)ppFollowTarget;
      if ( v24 )
      {
        v29 = mNext;
        v48 = mNext;
        v6 = v22;
        goto LABEL_68;
      }
    }
    else
    {
      v19 = (UFG::SimObjectCVBase *)ppFollowTarget;
    }
LABEL_67:
    v29 = v48;
LABEL_68:
    v5 = v46;
    if ( v46 )
    {
      if ( v19 )
        break;
    }
    p_mNext = (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)&p_mNext[10].mNode.mPrev[-10].mNext;
    if ( p_mNext == (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152) )
      break;
    m_pTransformNodeComponent = 0i64;
  }
  m_pComponent = v40;
  if ( !v29 )
  {
LABEL_92:
    UFG::InteractorComponent::SetBestInteractionPoint(m_pComponent, 0i64, 1);
    return 0;
  }
  params->pVehicle = v29;
  if ( m_pPointer )
  {
    v30 = m_pPointer->m_Flags;
    if ( (v30 & 0x4000) != 0 )
    {
      v31 = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( v30 >= 0 )
    {
      v32 = (v30 & 0x2000) != 0 || (v30 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      v31 = (UFG::TargetingSystemBaseComponent *)v32;
    }
    else
    {
      v31 = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( v31 )
    {
      m_pTargets = v31->m_pTargets;
      pVehicle = params->pVehicle;
      if ( m_pTargets[(unsigned __int8)v31->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE]].m_pTarget.m_pPointer != pVehicle )
      {
        if ( v31->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE] )
        {
          v35 = (unsigned __int8)v31->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
          UFG::TargetingSimObject::SetTarget(&m_pTargets[v35], 0i64);
          UFG::TargetingSimObject::SetLock(&v31->m_pTargets[v35], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v31, eTARGET_TYPE_VEHICLE, pVehicle);
      }
      v36 = v31->m_pTargets;
      v37 = params->pVehicle;
      if ( v36[(unsigned __int8)v31->m_pTargetingMap->m_Map.p[40]].m_pTarget.m_pPointer != v37 )
      {
        if ( v31->m_pTargetingMap->m_Map.p[40] )
        {
          v38 = (unsigned __int8)v31->m_pTargetingMap->m_Map.p[40];
          UFG::TargetingSimObject::SetTarget(&v36[v38], 0i64);
          UFG::TargetingSimObject::SetLock(&v31->m_pTargets[v38], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v31, eTARGET_TYPE_INTERACTIVE_PROP, v37);
      }
    }
  }
  UFG::InteractorComponent::SetBestInteractionPoint(v40, pIP, 1);
  return 1;
}:SetTarget(&v36[v38], 0i64);
          UFG::TargetingSimObject::SetLock(&v31->m_pTargets[v38], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v31, eTARGET_TYPE_INTERACTIVE_PROP, v37);
      }
    }
  }
  UFG::InteractorComponent::SetBestInteractionPoint(v40, pIP, 1);
 

// File Line: 362
// RVA: 0x392AD0
char __fastcall UFG::SelectSuitableVehicle::Update(UFG::SelectSuitableVehicle::Params *params)
{
  UFG::InteractorComponent *v1; // rsi
  UFG::SimObjectCVBase *m_pPointer; // rbx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v7; // rcx
  char result; // al
  int IsValidTarget; // ebp
  UFG::SimObjectGame *pVehicle; // rcx
  __int16 v11; // dx
  UFG::InteractableComponent *v12; // r10
  UFG::SimComponent *v13; // rax
  bool ignoreMeshTest; // r9
  _QWORD *v15; // rdx
  UFG::InteractionPoint *BestInteractionPoint; // rbp
  __int16 v17; // cx
  unsigned int v18; // edx
  UFG::SimObjectGame *v19; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  bool v21; // zf
  __int128 ppFollowTargetVehicle; // [rsp+50h] [rbp+8h] BYREF

  v1 = 0i64;
  m_pPointer = (UFG::SimObjectCVBase *)params->pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v7 = (__int64)&m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[28]];
  if ( *(_QWORD *)(v7 + 40) && *(_BYTE *)(v7 + 49) )
    return 0;
  ppFollowTargetVehicle = 0ui64;
  UFG::SelectSuitableVehicle::GetFollowTarget(
    m_pPointer,
    (UFG::SimObjectGame **)&ppFollowTargetVehicle + 1,
    (UFG::SimObject **)&ppFollowTargetVehicle);
  IsValidTarget = UFG::SelectSuitableVehicle::IsValidTarget(
                    params->pActionContext,
                    m_pPointer,
                    (UFG::SimObjectGame *)params->pVehicle,
                    *((UFG::SimObjectCVBase **)&ppFollowTargetVehicle + 1),
                    (UFG::SimObjectGame *)ppFollowTargetVehicle);
  if ( IsValidTarget )
  {
    pVehicle = (UFG::SimObjectGame *)params->pVehicle;
    if ( !pVehicle )
      goto LABEL_40;
    v11 = pVehicle->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      v12 = (UFG::InteractableComponent *)pVehicle->m_Components.p[12].m_pComponent;
    }
    else if ( v11 >= 0 )
    {
      v13 = (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(pVehicle, UFG::InteractableComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(pVehicle, UFG::InteractableComponent::_TypeUID);
      v12 = (UFG::InteractableComponent *)v13;
    }
    else
    {
      v12 = (UFG::InteractableComponent *)pVehicle->m_Components.p[12].m_pComponent;
    }
    if ( !v12 )
      goto LABEL_40;
    ignoreMeshTest = params->ignoreMeshTest;
    *(_QWORD *)&ppFollowTargetVehicle = 0i64;
    v15 = (_QWORD *)&ppFollowTargetVehicle + ((__int64)(IsValidTarget - 3) >> 6);
    *v15 |= 1i64 << ((IsValidTarget - 3) & 0x3F);
    BestInteractionPoint = UFG::InteractableComponent::FindBestInteractionPoint(
                             v12,
                             m_pPointer,
                             (UFG::qStaticBitField<6> *)&ppFollowTargetVehicle,
                             ignoreMeshTest);
    if ( !m_pPointer )
      goto LABEL_39;
    v17 = m_pPointer->m_Flags;
    if ( (v17 & 0x4000) != 0 )
    {
      v1 = (UFG::InteractorComponent *)m_pPointer->m_Components.p[29].m_pComponent;
LABEL_39:
      UFG::InteractorComponent::SetBestInteractionPoint(v1, BestInteractionPoint, 1);
      goto LABEL_40;
    }
    if ( v17 < 0 || (v17 & 0x2000) != 0 )
    {
      v18 = UFG::InteractorComponent::_TypeUID;
      v19 = m_pPointer;
    }
    else
    {
      v18 = UFG::InteractorComponent::_TypeUID;
      v21 = (v17 & 0x1000) == 0;
      v19 = m_pPointer;
      if ( v21 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractorComponent::_TypeUID);
        goto LABEL_38;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v19, v18);
LABEL_38:
    v1 = (UFG::InteractorComponent *)ComponentOfType;
    goto LABEL_39;
  }
  result = UFG::SelectSuitableVehicle::SelectVehicle(params);
  if ( result )
  {
LABEL_40:
    UFG::TargetingSystemBaseComponent::AssignTarget(m_pComponent, eTARGET_TYPE_VEHICLE, params->pVehicle);
    UFG::TargetingSystemBaseComponent::AssignTarget(m_pComponent, eTARGET_TYPE_INTERACTIVE_PROP, params->pVehicle);
    return 1;
  }
  return result;
}

// File Line: 418
// RVA: 0x34E810
void __fastcall UFG::SelectSuitableVehicle::Cleanup(UFG::SelectSuitableVehicle::Params *params)
{
  UFG::SimObjectGame *pVehicle; // r8
  UFG::SimObject *m_pPointer; // r14
  __int16 m_Flags; // cx
  UFG::VehicleOccupantComponent *m_pComponent; // rbp
  UFG::SimComponent *ComponentOfType; // rax
  __int64 NumberOfSeats; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *ReservationList; // rax
  signed int v8; // esi
  __int64 v9; // rdi
  __int64 v10; // r15
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // r12
  UFG::SimObject **i; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  pVehicle = (UFG::SimObjectGame *)params->pVehicle;
  m_pPointer = params->pActionContext->mSimObject.m_pPointer;
  if ( !pVehicle || !m_pPointer )
    return;
  m_Flags = pVehicle->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_9;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(pVehicle, UFG::VehicleOccupantComponent::_TypeUID);
      goto LABEL_11;
    }
LABEL_9:
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(pVehicle, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_11:
    m_pComponent = (UFG::VehicleOccupantComponent *)ComponentOfType;
    goto LABEL_12;
  }
  m_pComponent = (UFG::VehicleOccupantComponent *)pVehicle->m_Components.p[30].m_pComponent;
LABEL_12:
  if ( m_pComponent )
  {
    NumberOfSeats = (int)UFG::VehicleOccupantComponent::GetNumberOfSeats(m_pComponent);
    ReservationList = UFG::VehicleOccupantComponent::GetReservationList(m_pComponent);
    v8 = 0;
    v9 = 0i64;
    v10 = NumberOfSeats;
    v11 = ReservationList;
    if ( (int)NumberOfSeats > 0 )
    {
      for ( i = &ReservationList->m_pPointer;
            *i != m_pPointer || UFG::VehicleOccupantComponent::GetOccupant(m_pComponent, v8, 0i64) == m_pPointer;
            i += 3 )
      {
        ++v9;
        ++v8;
        if ( v9 >= v10 )
          return;
      }
      v13 = &v11[v8];
      if ( v13->m_pPointer )
      {
        mPrev = v13->mPrev;
        mNext = v13->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v13->mPrev = v13;
        v13->mNext = v13;
      }
      v13->m_pPointer = 0i64;
    }
  }
}

