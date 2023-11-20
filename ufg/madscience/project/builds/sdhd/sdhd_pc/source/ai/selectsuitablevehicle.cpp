// File Line: 33
// RVA: 0x14ACC90
__int64 dynamic_initializer_for__UFG::SelectSuitableVehicle::PrintChannel__()
{
  UFG::qString::qString(&stru_14206D7E0);
  return atexit(dynamic_atexit_destructor_for__UFG::SelectSuitableVehicle::PrintChannel__);
}

// File Line: 36
// RVA: 0x35FA00
bool __fastcall UFG::SelectSuitableVehicle::GetFollowTarget(UFG::SimObject *pMySelf, UFG::SimObject **ppFollowTarget, UFG::SimObject **ppFollowTargetVehicle)
{
  UFG::SimObject **v3; // r14
  UFG::SimObject **v4; // r15
  UFG::SimObjectCVBase *v5; // rbx
  UFG::SimObjectGame *v6; // rdi
  UFG::SimObject *v7; // rbp
  UFG::ActiveAIEntityComponent *v8; // rax
  unsigned __int16 v9; // cx
  UFG::eAIObjective v10; // ecx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rdx
  UFG::SimComponent *v13; // rax
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rax

  v3 = ppFollowTargetVehicle;
  v4 = ppFollowTarget;
  v5 = (UFG::SimObjectCVBase *)pMySelf;
  v6 = 0i64;
  v7 = 0i64;
  if ( pMySelf )
  {
    v9 = pMySelf->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v5->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v5->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v5->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v10 = v8->m_CurrentObjective;
  if ( (v10 == eAI_OBJECTIVE_FOLLOW_TARGET || v10 == eAI_OBJECTIVE_BE_ALLY) && v5 )
  {
    v11 = v5->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v5->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v11 >> 12) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v5->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v5->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v12 = v13;
    }
    else
    {
      v12 = v5->m_Components.p[20].m_pComponent;
    }
    if ( v12 )
    {
      v6 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v12[1].m_Flags + 38i64)
                                  + *(_QWORD *)&v12[1].m_TypeUID
                                  + 40);
      if ( v6 )
      {
        v14 = v6->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v15 = v6->m_Components.p[20].m_pComponent;
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
          {
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v14 >> 12) & 1 )
          {
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v15 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v6->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
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
  *v4 = (UFG::SimObject *)&v6->vfptr;
  *v3 = v7;
  return v6 != 0i64;
}

// File Line: 72
// RVA: 0x36C1C0
__int64 __fastcall UFG::SelectSuitableVehicle::IsValidTarget(ActionContext *pActionContext, UFG::SimObject *pMyself, UFG::SimObject *pVehicle, UFG::SimObject *pFollowTarget, UFG::SimObject *pFollowTargetVehicle)
{
  UFG::SimObjectGame *v5; // rsi
  UFG::SimObject *v6; // r13
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // r12
  UFG::SimObjectGame *v10; // rax
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  signed int v13; // edi
  __int64 v14; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rax
  signed int v16; // ebp
  __int64 v17; // r14
  UFG::SimObject **v18; // r15
  __int64 v19; // rax
  UFG::SimObjectGame *v20; // rbx
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  unsigned __int16 v27; // cx
  UFG::PhysicsMoverInterface *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  __int64 v33; // [rsp+20h] [rbp-58h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v34; // [rsp+28h] [rbp-50h]
  bool v35; // [rsp+90h] [rbp+18h]
  UFG::SimObject *v36; // [rsp+98h] [rbp+20h]

  v36 = pFollowTarget;
  v5 = (UFG::SimObjectGame *)pVehicle;
  v6 = pMyself;
  v35 = pFollowTarget != 0i64;
  if ( !pVehicle )
    return 0i64;
  v7 = pVehicle->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
           (UFG::SimObjectGame *)pVehicle,
           UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v7 & 0x8000u) != 0 )
    {
      v9 = pVehicle->m_Components.p[30].m_pComponent;
      goto LABEL_12;
    }
    if ( (v7 >> 13) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)pVehicle,
             UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v7 >> 12) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)pVehicle,
             UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v8 = UFG::SimObject::GetComponentOfType(pVehicle, UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v9 = v8;
LABEL_12:
  if ( !v9 )
    return 0i64;
  v10 = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v9);
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v10->m_Components.p[6].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HealthComponent::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      v12 = v10->m_Components.p[6].m_pComponent;
    }
    if ( v12 && BYTE4(v12[1].m_BoundComponentHandles.mNode.mPrev) )
      return 0i64;
  }
  v13 = -1;
  v14 = (signed int)UFG::VehicleOccupantComponent::GetNumberOfSeats((UFG::VehicleOccupantComponent *)v9);
  v15 = UFG::VehicleOccupantComponent::GetReservationList((UFG::VehicleOccupantComponent *)v9);
  v16 = v5 == (UFG::SimObjectGame *)pFollowTargetVehicle;
  v33 = v14;
  v17 = v5 == (UFG::SimObjectGame *)pFollowTargetVehicle;
  v34 = v15;
  if ( v17 >= v14 )
    return 0i64;
  v18 = (UFG::SimObject **)(&v15->mPrev
                          + (v5 == (UFG::SimObjectGame *)pFollowTargetVehicle)
                          + 2 * ((v5 == (UFG::SimObjectGame *)pFollowTargetVehicle) + 1i64));
  v19 = v14;
  do
  {
    v20 = (UFG::SimObjectGame *)*v18;
    if ( *v18 == v6 )
    {
      v13 = v16;
      goto LABEL_64;
    }
    if ( v20 )
    {
      if ( !UFG::AreCharactersAllied(*v18, v6) && (!v35 || v36 != (UFG::SimObject *)v20) )
      {
        v21 = v20->m_Flags;
        if ( (v21 >> 14) & 1 )
        {
          v22 = v20->m_Components.p[44].m_pComponent;
        }
        else if ( (v21 & 0x8000u) == 0 )
        {
          if ( (v21 >> 13) & 1 )
          {
            v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::CharacterOccupantComponent::_TypeUID);
          }
          else if ( (v21 >> 12) & 1 )
          {
            v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v22 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v20->vfptr,
                    UFG::CharacterOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::CharacterOccupantComponent::_TypeUID);
        }
        if ( v22 && LODWORD(v22[1].m_SafePointerList.mNode.mNext) != 13 )
        {
LABEL_47:
          if ( v13 != -1
            && UFG::VehicleOccupantComponent::GetOccupant((UFG::VehicleOccupantComponent *)v9, v13, 0i64) == v6 )
          {
            v23 = &v34[v13];
            if ( v34[v13].m_pPointer )
            {
              v24 = v23->mPrev;
              v25 = v23->mNext;
              v24->mNext = v25;
              v25->mPrev = v24;
              v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v23->mPrev;
              v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v23->mPrev;
            }
            v23->m_pPointer = 0i64;
          }
          return 0i64;
        }
        goto LABEL_63;
      }
      v27 = v5->m_Flags;
      if ( !((v27 >> 14) & 1) )
      {
        if ( (v27 & 0x8000u) != 0 )
        {
          v28 = (UFG::PhysicsMoverInterface *)v5->m_Components.p[34].m_pComponent;
          goto LABEL_61;
        }
        if ( !((v27 >> 13) & 1) )
        {
          if ( (v27 >> 12) & 1 )
            v28 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v5,
                                                  UFG::PhysicsMoverInterface::_TypeUID);
          else
            v28 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v5->vfptr,
                                                  UFG::PhysicsMoverInterface::_TypeUID);
LABEL_61:
          if ( v28 && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v28) > 40.0 )
            goto LABEL_47;
          goto LABEL_63;
        }
      }
LABEL_63:
      v19 = v33;
      goto LABEL_64;
    }
    if ( v13 == -1 )
      v13 = v16;
LABEL_64:
    ++v17;
    ++v16;
    v18 += 3;
  }
  while ( v17 < v19 );
  if ( v13 == -1 )
    return 0i64;
  v29 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v34[v13].mPrev;
  if ( v34[v13].m_pPointer )
  {
    v30 = v29->mPrev;
    v31 = v29->mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    v29->mPrev = v29;
    v29->mNext = v29;
  }
  v29[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
  if ( v6 )
  {
    v32 = v6->m_SafePointerList.mNode.mPrev;
    v32->mNext = v29;
    v29->mPrev = v32;
    v29->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = v29;
  }
  return (unsigned int)(v13 + 4);
}

// File Line: 180
// RVA: 0x3842D0
char __fastcall UFG::SelectSuitableVehicle::SelectVehicle(UFG::SelectSuitableVehicle::Params *params)
{
  UFG::SelectSuitableVehicle::Params *v1; // r12
  UFG::TransformNodeComponent *v2; // rdi
  UFG::SimObjectGame *v3; // rsi
  UFG::SimObject *v4; // rcx
  bool v5; // al
  char v6; // bl
  float v7; // xmm7_4
  UFG::SceneObjectProperties *v8; // rax
  UFG::qPropertySet *v9; // rcx
  UFG::qSymbol *v10; // rax
  unsigned int v11; // eax
  UFG::SimObjectCVBase *v12; // rcx
  UFG::ActiveAIEntityComponent *v13; // rax
  unsigned __int16 v14; // dx
  UFG::InteractorComponent *v15; // r13
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *v18; // rbp
  char v19; // r13
  UFG::SimObject *v20; // r14
  UFG::SimObject *pFollowTargetVehicle; // r15
  UFG::SimObjectGame *v22; // rbx
  float v23; // xmm6_4
  int v24; // er14
  bool v25; // di
  unsigned __int16 v26; // dx
  UFG::InteractableComponent *v27; // r10
  UFG::SimComponent *v28; // rax
  bool v29; // r9
  __int64 v30; // rdi
  unsigned __int16 v31; // cx
  UFG::TargetingSystemBaseComponent *v32; // rdi
  UFG::SimComponent *v33; // rax
  UFG::TargetingSimObject *v34; // rdx
  UFG::SimObject *v35; // rsi
  signed __int64 v36; // rbx
  UFG::TargetingSimObject *v37; // rdx
  UFG::SimObject *v38; // rsi
  signed __int64 v39; // rbx
  UFG::InteractorComponent *v41; // [rsp+30h] [rbp-A8h]
  UFG::SimObject *ppFollowTarget; // [rsp+38h] [rbp-A0h]
  UFG::SimObject *ppFollowTargetVehicle; // [rsp+40h] [rbp-98h]
  UFG::InteractionPoint *pIP; // [rsp+48h] [rbp-90h]
  UFG::TransformNodeComponent *v45; // [rsp+50h] [rbp-88h]
  UFG::qStaticBitField<6> bfTestIP; // [rsp+E0h] [rbp+8h]
  bool v47; // [rsp+E8h] [rbp+10h]
  UFG::qSymbol targetClassType; // [rsp+F0h] [rbp+18h]
  UFG::SimObjectGame *v49; // [rsp+F8h] [rbp+20h]

  v1 = params;
  v2 = 0i64;
  v3 = (UFG::SimObjectGame *)params->pActionContext->mSimObject.m_pPointer;
  v4 = params->pActionContext->mSimObject.m_pPointer;
  ppFollowTarget = 0i64;
  ppFollowTargetVehicle = 0i64;
  v5 = UFG::SelectSuitableVehicle::GetFollowTarget(v4, &ppFollowTarget, &ppFollowTargetVehicle);
  v49 = 0i64;
  v6 = v5;
  v47 = v5;
  if ( v5 )
    v7 = FLOAT_9999999_0;
  else
    v7 = v1->maxSearchRadius * v1->maxSearchRadius;
  targetClassType.mUID = v1->filterClassSymbol.mUID;
  LOBYTE(bfTestIP.mBits[0]) = targetClassType.mUID != -1;
  if ( targetClassType.mUID == -1 )
  {
    if ( v3 && (v8 = v3->m_pSceneObj) != 0i64 )
    {
      v9 = v8->mpWritableProperties;
      if ( v9 )
      {
LABEL_11:
        v10 = UFG::qPropertySet::Get<UFG::qSymbol>(v9, (UFG::qSymbol *)&qSymbol_VehicleSearchFilter.mUID, DEPTH_RECURSE);
        if ( v10 )
        {
          v11 = v10->mUID;
          if ( v11 != -1 )
          {
            targetClassType.mUID = v11;
            LOBYTE(bfTestIP.mBits[0]) = 1;
          }
        }
        goto LABEL_14;
      }
      v9 = v8->mpConstProperties;
    }
    else
    {
      v9 = 0i64;
    }
    if ( v9 )
      goto LABEL_11;
  }
LABEL_14:
  v12 = (UFG::SimObjectCVBase *)v1->pActionContext->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v12);
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v13 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v12->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v13 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v12->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v13 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v12->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v12);
    }
  }
  else
  {
    v13 = 0i64;
  }
  v45 = (UFG::TransformNodeComponent *)v13->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v45);
  if ( v3 )
  {
    v16 = v3->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v15 = (UFG::InteractorComponent *)v3->m_Components.p[29].m_pComponent;
    }
    else
    {
      if ( (v16 & 0x8000u) == 0 )
      {
        if ( (v16 >> 13) & 1 )
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
        }
        else if ( (v16 >> 12) & 1 )
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
        }
        else
        {
          v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractorComponent::_TypeUID);
        }
      }
      else
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
      }
      v15 = (UFG::InteractorComponent *)v17;
    }
  }
  else
  {
    v15 = 0i64;
  }
  v41 = v15;
  v18 = (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext;
  pIP = 0i64;
  if ( &UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext == (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> **)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152) )
    goto LABEL_97;
  v19 = bfTestIP.mBits[0];
  v20 = ppFollowTarget;
  pFollowTargetVehicle = ppFollowTargetVehicle;
  while ( 1 )
  {
    if ( !v6 || (v22 = (UFG::SimObjectGame *)pFollowTargetVehicle) == 0i64 )
      v22 = (UFG::SimObjectGame *)v18[2].mNode.mNext;
    bfTestIP.mBits[0] = 0i64;
    v23 = FLOAT_N1_0;
    if ( v22 )
      v2 = v22->m_pTransformNodeComponent;
    if ( v22 == (UFG::SimObjectGame *)pFollowTargetVehicle )
    {
      v23 = FLOAT_N1_0;
    }
    else
    {
      if ( v2 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v2);
        v23 = (float)((float)((float)(v2->mWorldTransform.v3.y - v45->mWorldTransform.v3.y)
                            * (float)(v2->mWorldTransform.v3.y - v45->mWorldTransform.v3.y))
                    + (float)((float)(v2->mWorldTransform.v3.x - v45->mWorldTransform.v3.x)
                            * (float)(v2->mWorldTransform.v3.x - v45->mWorldTransform.v3.x)))
            + (float)((float)(v2->mWorldTransform.v3.z - v45->mWorldTransform.v3.z)
                    * (float)(v2->mWorldTransform.v3.z - v45->mWorldTransform.v3.z));
        if ( v23 > v7 )
          goto LABEL_71;
      }
      if ( v19 && !UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v22->vfptr, &targetClassType)
        || UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v22->vfptr, (UFG::qSymbol *)&qSymbol_Taxi.mUID)
        || UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v22->vfptr, (UFG::qSymbol *)&qSymbol_Minibus.mUID)
        || UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v22->vfptr, (UFG::qSymbol *)&qSymbol_Tram.mUID) )
      {
        goto LABEL_71;
      }
    }
    v24 = UFG::SelectSuitableVehicle::IsValidTarget(
            v1->pActionContext,
            (UFG::SimObject *)&v3->vfptr,
            (UFG::SimObject *)&v22->vfptr,
            v20,
            pFollowTargetVehicle);
    v25 = v24 != 0;
    if ( v24 )
    {
      if ( v22 )
      {
        v26 = v22->m_Flags;
        if ( (v26 >> 14) & 1 )
        {
          v27 = (UFG::InteractableComponent *)v22->m_Components.p[12].m_pComponent;
        }
        else if ( (v26 & 0x8000u) == 0 )
        {
          if ( (v26 >> 13) & 1 )
            v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::InteractableComponent::_TypeUID);
          else
            v28 = (v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v22->vfptr, UFG::InteractableComponent::_TypeUID);
          v27 = (UFG::InteractableComponent *)v28;
        }
        else
        {
          v27 = (UFG::InteractableComponent *)v22->m_Components.p[12].m_pComponent;
        }
        if ( v27 )
        {
          v29 = v1->ignoreMeshTest;
          bfTestIP.mBits[(signed __int64)(v24 - 3) >> 6] |= 1i64 << ((v24 - 3) & 0x3F);
          pIP = UFG::InteractableComponent::FindBestInteractionPoint(v27, (UFG::SimObject *)&v3->vfptr, &bfTestIP, v29);
          v25 = pIP != 0i64;
        }
      }
      v20 = ppFollowTarget;
      if ( v25 )
      {
        v30 = (__int64)v22;
        v49 = v22;
        v7 = v23;
        goto LABEL_72;
      }
    }
    else
    {
      v20 = ppFollowTarget;
    }
LABEL_71:
    v30 = (__int64)v49;
LABEL_72:
    v6 = v47;
    if ( v47 )
    {
      if ( v20 )
        break;
    }
    v18 = (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)&v18[10].mNode.mPrev[-10].mNext;
    if ( v18 == (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152) )
      break;
    v2 = 0i64;
  }
  v15 = v41;
  if ( !v30 )
  {
LABEL_97:
    UFG::InteractorComponent::SetBestInteractionPoint(v15, 0i64, 1);
    return 0;
  }
  v1->pVehicle = (UFG::SimObject *)v30;
  if ( v3 )
  {
    v31 = v3->m_Flags;
    if ( (v31 >> 14) & 1 )
    {
      v32 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v31 & 0x8000u) == 0 )
    {
      if ( (v31 >> 13) & 1 )
        v33 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v33 = (v31 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v3,
                                  UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v3->vfptr,
                                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      v32 = (UFG::TargetingSystemBaseComponent *)v33;
    }
    else
    {
      v32 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    if ( v32 )
    {
      v34 = v32->m_pTargets;
      v35 = v1->pVehicle;
      if ( v34[(unsigned __int8)v32->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE]].m_pTarget.m_pPointer != v35 )
      {
        if ( v32->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE] )
        {
          v36 = (unsigned __int8)v32->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
          UFG::TargetingSimObject::SetTarget(&v34[v36], 0i64);
          UFG::TargetingSimObject::SetLock(&v32->m_pTargets[v36], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v32, eTARGET_TYPE_VEHICLE, v35);
      }
      v37 = v32->m_pTargets;
      v38 = v1->pVehicle;
      if ( v37[(unsigned __int8)v32->m_pTargetingMap->m_Map.p[40]].m_pTarget.m_pPointer != v38 )
      {
        if ( v32->m_pTargetingMap->m_Map.p[40] )
        {
          v39 = (unsigned __int8)v32->m_pTargetingMap->m_Map.p[40];
          UFG::TargetingSimObject::SetTarget(&v37[v39], 0i64);
          UFG::TargetingSimObject::SetLock(&v32->m_pTargets[v39], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v32, eTARGET_TYPE_INTERACTIVE_PROP, v38);
      }
    }
  }
  UFG::InteractorComponent::SetBestInteractionPoint(v41, pIP, 1);
  return 1;
}    UFG::TargetingSimObject::SetTarget(&v37[v39], 0i64);
          UFG::TargetingSimObject::SetLock(&v32->m_pTargets[v39], 0);
        

// File Line: 362
// RVA: 0x392AD0
char __fastcall UFG::SelectSuitableVehicle::Update(UFG::SelectSuitableVehicle::Params *params)
{
  UFG::InteractorComponent *v1; // rsi
  UFG::SelectSuitableVehicle::Params *v2; // r14
  UFG::SimObjectGame *v3; // rbx
  UFG::TargetingSystemBaseComponent *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  signed __int64 v7; // rcx
  char result; // al
  int v9; // ebp
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::InteractableComponent *v12; // r10
  UFG::SimComponent *v13; // rax
  bool v14; // r9
  _QWORD *v15; // rdx
  UFG::InteractionPoint *v16; // rbp
  unsigned __int16 v17; // cx
  unsigned int v18; // edx
  UFG::SimObjectGame *v19; // rcx
  UFG::SimComponent *v20; // rax
  bool v21; // zf
  __int128 ppFollowTargetVehicle; // [rsp+50h] [rbp+8h]

  v1 = 0i64;
  v2 = params;
  v3 = (UFG::SimObjectGame *)params->pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = (UFG::TargetingSystemBaseComponent *)v6;
    }
    else
    {
      v4 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = (signed __int64)&v4->m_pTargets[(unsigned __int8)v4->m_pTargetingMap->m_Map.p[28]];
  if ( *(_QWORD *)(v7 + 40) && *(_BYTE *)(v7 + 49) )
    return 0;
  ppFollowTargetVehicle = 0ui64;
  UFG::SelectSuitableVehicle::GetFollowTarget(
    (UFG::SimObject *)&v3->vfptr,
    (UFG::SimObject **)&ppFollowTargetVehicle + 1,
    (UFG::SimObject **)&ppFollowTargetVehicle);
  v9 = UFG::SelectSuitableVehicle::IsValidTarget(
         v2->pActionContext,
         (UFG::SimObject *)&v3->vfptr,
         v2->pVehicle,
         *((UFG::SimObject **)&ppFollowTargetVehicle + 1),
         (UFG::SimObject *)ppFollowTargetVehicle);
  if ( v9 )
  {
    v10 = (UFG::SimObjectGame *)v2->pVehicle;
    if ( !v10 )
      goto LABEL_42;
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = (UFG::InteractableComponent *)v10->m_Components.p[12].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::InteractableComponent::_TypeUID);
      else
        v13 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::InteractableComponent::_TypeUID);
      v12 = (UFG::InteractableComponent *)v13;
    }
    else
    {
      v12 = (UFG::InteractableComponent *)v10->m_Components.p[12].m_pComponent;
    }
    if ( !v12 )
      goto LABEL_42;
    v14 = v2->ignoreMeshTest;
    *(_QWORD *)&ppFollowTargetVehicle = 0i64;
    v15 = (_QWORD *)((char *)&ppFollowTargetVehicle + 8 * ((signed __int64)(v9 - 3) >> 6));
    *v15 |= 1i64 << ((v9 - 3) & 0x3F);
    v16 = UFG::InteractableComponent::FindBestInteractionPoint(
            v12,
            (UFG::SimObject *)&v3->vfptr,
            (UFG::qStaticBitField<6> *)&ppFollowTargetVehicle,
            v14);
    if ( !v3 )
      goto LABEL_41;
    v17 = v3->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v1 = (UFG::InteractorComponent *)v3->m_Components.p[29].m_pComponent;
LABEL_41:
      UFG::InteractorComponent::SetBestInteractionPoint(v1, v16, 1);
      goto LABEL_42;
    }
    if ( (v17 & 0x8000u) != 0 || (v17 >> 13) & 1 )
    {
      v18 = UFG::InteractorComponent::_TypeUID;
      v19 = v3;
    }
    else
    {
      v18 = UFG::InteractorComponent::_TypeUID;
      v21 = ((v17 >> 12) & 1) == 0;
      v19 = v3;
      if ( v21 )
      {
        v20 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractorComponent::_TypeUID);
        goto LABEL_40;
      }
    }
    v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, v18);
LABEL_40:
    v1 = (UFG::InteractorComponent *)v20;
    goto LABEL_41;
  }
  result = UFG::SelectSuitableVehicle::SelectVehicle(v2);
  if ( result )
  {
LABEL_42:
    UFG::TargetingSystemBaseComponent::AssignTarget(v4, eTARGET_TYPE_VEHICLE, v2->pVehicle);
    UFG::TargetingSystemBaseComponent::AssignTarget(v4, eTARGET_TYPE_INTERACTIVE_PROP, v2->pVehicle);
    result = 1;
  }
  return result;
}

// File Line: 418
// RVA: 0x34E810
void __fastcall UFG::SelectSuitableVehicle::Cleanup(UFG::SelectSuitableVehicle::Params *params)
{
  UFG::SimObjectGame *v1; // r8
  UFG::SimObject *v2; // r14
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rbp
  __int64 v6; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rax
  signed int v8; // esi
  __int64 v9; // rdi
  __int64 v10; // r15
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // r12
  UFG::SimObject **v12; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = (UFG::SimObjectGame *)params->pVehicle;
  v2 = params->pActionContext->mSimObject.m_pPointer;
  if ( !v1 || !v2 )
    return;
  v3 = v1->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_12:
    v5 = (UFG::VehicleOccupantComponent *)v4;
    goto LABEL_13;
  }
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v3 >> 12) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
    goto LABEL_12;
  }
  v5 = (UFG::VehicleOccupantComponent *)v1->m_Components.p[30].m_pComponent;
LABEL_13:
  if ( v5 )
  {
    v6 = (signed int)UFG::VehicleOccupantComponent::GetNumberOfSeats(v5);
    v7 = UFG::VehicleOccupantComponent::GetReservationList(v5);
    v8 = 0;
    v9 = 0i64;
    v10 = v6;
    v11 = v7;
    if ( (signed int)v6 > 0 )
    {
      v12 = &v7->m_pPointer;
      while ( *v12 != v2 || UFG::VehicleOccupantComponent::GetOccupant(v5, v8, 0i64) == v2 )
      {
        ++v9;
        ++v8;
        v12 += 3;
        if ( v9 >= v10 )
          return;
      }
      v13 = &v11[v8];
      if ( v11[v8].m_pPointer )
      {
        v14 = v13->mPrev;
        v15 = v13->mNext;
        v14->mNext = v15;
        v15->mPrev = v14;
        v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
        v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      }
      v13->m_pPointer = 0i64;
    }
  }
}

