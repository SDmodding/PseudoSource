// File Line: 8
// RVA: 0x3EDD30
void __fastcall UFG::CopSystem::HandleDamageEvent(UFG::CopSystem *this, UFG::SimObject *pSource, UFG::SimObject *pTarget, UFG::HitRecord *pHitRecord, UFG::HealthComponent *pTargetHealthComponent, bool appliedDamage)
{
  UFG::HitRecord *v6; // r13
  UFG::SimObjectVehicle *v7; // rdi
  UFG::SimObjectProp *v8; // rsi
  UFG::SimObjectCharacter *v9; // r14
  char v10; // r15
  char v11; // r12
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  unsigned __int16 v14; // cx
  UFG::SimObjectWeaponPropertiesComponent *v15; // rax
  unsigned __int16 v16; // cx
  UFG::VehicleOwnershipComponent *v17; // rax
  UFG::SimObject *v18; // rax
  unsigned __int16 v19; // cx
  UFG::TSActorComponent *v20; // rbx
  unsigned __int16 v21; // dx
  UFG::SimComponent *v22; // rbp
  UFG::SimComponent *v23; // rax
  UFG::TSActor *v24; // rax
  SSActorClass *v25; // rcx
  SSClass *v26; // rcx
  unsigned __int16 v27; // cx
  UFG::MissionFailConditionComponent *v28; // rax
  float v29; // xmm6_4
  unsigned int v30; // ebx
  bool v31; // si
  bool v32; // al
  _BOOL8 v33; // rdx
  int v34; // ecx
  int v35; // ebx
  UFG::CopSystem *v36; // rcx
  UFG::GameStatAction::MissionScoring::CopScoreEvent v37; // ecx
  unsigned __int16 v38; // cx
  UFG::SimComponent *v39; // rax
  hkSimpleLocalFrame *v40; // rbp
  UFG::SimObject *v41; // rax
  char v42; // bp
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  UFG::TransformNodeComponent *v45; // rsi
  unsigned __int16 v46; // cx
  UFG::VehicleAudioComponent *v47; // rax
  UFG::TransformNodeComponent *v48; // rsi
  unsigned __int16 v49; // cx
  UFG::VehicleAudioComponent *v50; // rax
  UFG::OneShotHandle pHandle; // [rsp+20h] [rbp-58h]
  __int64 v52; // [rsp+28h] [rbp-50h]
  UFG::CopSystem *v53; // [rsp+80h] [rbp+8h]
  bool pIsCop; // [rsp+88h] [rbp+10h]
  bool pIsAmbient; // [rsp+90h] [rbp+18h]

  v53 = this;
  v52 = -2i64;
  v6 = pHitRecord;
  v7 = (UFG::SimObjectVehicle *)pTarget;
  v8 = (UFG::SimObjectProp *)pSource;
  v9 = UFG::GetLocalPlayer();
  if ( v7 == (UFG::SimObjectVehicle *)v9 && v6 && v6->mIsDeadly )
    UFG::GameStatAction::Player::RegisterPlayerDeath((UFG::SimObject *)&v8->vfptr, v6);
  if ( !v8 )
    return;
  v10 = 0;
  v11 = 1;
  if ( v8 != (UFG::SimObjectProp *)v9 )
  {
    v12 = v8->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = v8->m_Components.p[23].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v8->vfptr,
                UFG::VehicleDriverInterface::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v8->vfptr,
                UFG::VehicleDriverInterface::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::VehicleDriverInterface::_TypeUID);
      }
    }
    else
    {
      v13 = v8->m_Components.p[23].m_pComponent;
    }
    if ( v13 )
    {
      if ( (UFG::SimObjectCharacter *)v13[3].m_BoundComponentHandles.mNode.mNext != v9 )
        return;
LABEL_46:
      v10 = 1;
      goto LABEL_47;
    }
    v14 = v8->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v8->vfptr,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v8);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v8->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
      else
      {
        v15 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v8->vfptr,
                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v15 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v8->vfptr,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    if ( !v15 )
    {
      if ( v9
        && ((v16 = v9->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v17 = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::VehicleOwnershipComponent::_TypeUID)) : (v17 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v9->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v17 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v9->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v17 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v9->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v17 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v9->vfptr, UFG::VehicleOwnershipComponent::_TypeUID)),
            v17) )
      {
        v18 = UFG::VehicleOwnershipComponent::GetOwnedVehicle(v17);
      }
      else
      {
        v18 = 0i64;
      }
      if ( v18 != (UFG::SimObject *)v8 )
        return;
      v11 = 0;
      goto LABEL_46;
    }
    if ( v15->mLastOwner != v9->mNode.mUID )
      return;
  }
LABEL_47:
  UFG::GameStatAction::Player::RegisterSuccessfulHit((UFG::SimObject *)&v8->vfptr, (UFG::SimObject *)&v7->vfptr, v6);
  if ( v7 )
  {
    v19 = v7->m_Flags;
    if ( (v19 >> 14) & 1 )
    {
      v20 = (UFG::TSActorComponent *)v7->m_Components.p[4].m_pComponent;
    }
    else if ( (v19 & 0x8000u) == 0 )
    {
      if ( (v19 >> 13) & 1 )
        v20 = (UFG::TSActorComponent *)v7->m_Components.p[3].m_pComponent;
      else
        v20 = (UFG::TSActorComponent *)((v19 >> 12) & 1 ? v7->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v7->vfptr,
                                                                                                 UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      v20 = (UFG::TSActorComponent *)v7->m_Components.p[4].m_pComponent;
    }
    v21 = v7->m_Flags;
    if ( (v21 >> 14) & 1 )
    {
      v22 = v7->m_Components.p[6].m_pComponent;
    }
    else if ( (v21 & 0x8000u) == 0 )
    {
      if ( (v21 >> 13) & 1 )
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::HealthComponent::_TypeUID);
      else
        v23 = (v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)&v7->vfptr,
                                  UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                      (UFG::SimObject *)&v7->vfptr,
                                                                      UFG::HealthComponent::_TypeUID);
      v22 = v23;
    }
    else
    {
      v22 = v7->m_Components.p[6].m_pComponent;
    }
    if ( v20 )
    {
      if ( v22 )
      {
        v24 = v20->mpActor.i_obj_p;
        if ( v24 )
        {
          if ( v20->mpActor.i_ptr_id == v24->i_ptr_id )
          {
            v25 = (SSActorClass *)UFG::TSActorComponent::GetActor(v20)->i_class_p;
            if ( UFG::SkookumMgr::mspCharacterClass == v25
              || (v26 = v25->i_superclass_p) != 0i64
              && SSClass::is_class(v26, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
            {
              v27 = v7->m_Flags;
              if ( (v27 >> 14) & 1 )
              {
                v28 = (UFG::MissionFailConditionComponent *)v7->m_Components.p[8].m_pComponent;
              }
              else if ( (v27 & 0x8000u) == 0 )
              {
                if ( (v27 >> 13) & 1 )
                  v28 = (UFG::MissionFailConditionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                                UFG::MissionFailConditionComponent::_TypeUID);
                else
                  v28 = (UFG::MissionFailConditionComponent *)((v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                   (UFG::SimObjectGame *)&v7->vfptr,
                                                                                   UFG::MissionFailConditionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::MissionFailConditionComponent::_TypeUID));
              }
              else
              {
                v28 = (UFG::MissionFailConditionComponent *)v7->m_Components.p[8].m_pComponent;
              }
              if ( v28 )
              {
                if ( v28->mDamageFailTrigger )
                {
                  v29 = *((float *)&v22[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&v22[1].m_NameUID;
                  if ( v29 <= UFG::MissionFailConditionComponent::GetFailThreshold(
                                v28,
                                (UFG::qSymbol *)&qSymbol_DamageHealthThreshold.mUID) )
                    UFG::MissionFailConditionComponent::FailObject(
                      (UFG::SimObject *)&v7->vfptr,
                      (UFG::qSymbol *)&qSymbol_DamageFailCaption.mUID);
                }
              }
            }
          }
        }
      }
    }
  }
  v30 = 26;
  if ( !v6 )
  {
    if ( !v10 )
      return;
    pIsCop = 0;
    pIsAmbient = 0;
    UFG::GameStatAction::MissionScoring::DeduceFaction((UFG::SimObject *)&v7->vfptr, &pIsCop, &pIsAmbient);
    if ( !v7 )
      goto LABEL_126;
    v38 = v7->m_Flags;
    if ( (v38 >> 14) & 1 )
    {
      v39 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v7->vfptr,
              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      if ( (v38 & 0x8000u) != 0 )
      {
        v40 = (hkSimpleLocalFrame *)v7->m_Components.p[30].m_pComponent;
LABEL_123:
        if ( v40 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v40) )
        {
          v41 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v40);
          v42 = UFG::AreCharactersAllied((UFG::SimObject *)&v9->vfptr, v41);
          goto LABEL_127;
        }
LABEL_126:
        v42 = 1;
LABEL_127:
        v43 = v8->m_Flags;
        if ( (v43 >> 14) & 1 )
        {
          v44 = 0i64;
        }
        else if ( (v43 & 0x8000u) == 0 )
        {
          if ( (v43 >> 13) & 1 )
          {
            v44 = 0i64;
          }
          else if ( (v43 >> 12) & 1 )
          {
            v44 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v8->vfptr,
                    UFG::PhysicsMoverInterface::_TypeUID);
          }
          else
          {
            v44 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
          }
        }
        else
        {
          v44 = v8->m_Components.p[34].m_pComponent;
        }
        if ( !v11 || v44 && (float)(*((float *)&v44[10].m_BoundComponentHandles.mNode.mPrev + 1) * 3.5999999) > 40.0 )
        {
          if ( pIsCop || pIsAmbient )
          {
            v30 = (pIsCop != 0) + 19;
            if ( pIsCop )
              goto LABEL_146;
            UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DAMAGE, 0, &customWorldMapCaption);
          }
          else
          {
            if ( v42 )
              return;
            UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_DAMAGE, 0, &customWorldMapCaption);
          }
        }
        if ( !pIsCop )
        {
LABEL_175:
          v36 = v53;
LABEL_176:
          if ( v30 != 26 )
            v36->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v36->vfptr, v30);
          return;
        }
LABEL_146:
        if ( v7 )
        {
          v45 = v7->m_pTransformNodeComponent;
          v46 = v7->m_Flags;
          if ( (v46 >> 14) & 1 )
          {
            v47 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v7->vfptr,
                                                  UFG::VehicleAudioComponent::_TypeUID);
          }
          else if ( (v46 & 0x8000u) == 0 )
          {
            if ( (v46 >> 13) & 1 )
              v47 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v7->vfptr,
                                                    UFG::VehicleAudioComponent::_TypeUID);
            else
              v47 = (UFG::VehicleAudioComponent *)((v46 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v7->vfptr,
                                                                       UFG::VehicleAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::VehicleAudioComponent::_TypeUID));
          }
          else
          {
            v47 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v7);
          }
          if ( v45 && v47 )
          {
            pHandle.m_pOneShot = 0i64;
            UFG::TransformNodeComponent::UpdateWorldTransform(v45);
            UFG::OneShotPool::GetOneShotHandle(&pHandle, &v45->mWorldTransform);
            if ( UFG::OneShotHandle::IsValid(&pHandle) )
            {
              v48 = v7->m_pTransformNodeComponent;
              v49 = v7->m_Flags;
              if ( (v49 >> 14) & 1 )
              {
                v50 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v7->vfptr,
                                                      UFG::VehicleAudioComponent::_TypeUID);
              }
              else if ( (v49 & 0x8000u) == 0 )
              {
                if ( (v49 >> 13) & 1 )
                  v50 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v7->vfptr,
                                                        UFG::VehicleAudioComponent::_TypeUID);
                else
                  v50 = (UFG::VehicleAudioComponent *)((v49 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v7->vfptr,
                                                                           UFG::VehicleAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::VehicleAudioComponent::_TypeUID));
              }
              else
              {
                v50 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v7);
              }
              if ( v48 && v50 && UFG::VehicleAudioComponent::HasOccupant(v50) )
              {
                if ( !(dword_1423D9A80 & 1) )
                {
                  dword_1423D9A80 |= 1u;
                  stru_1423D9A7C.mUID = UFG::qWiseSymbolUIDFromString("play_sirens_warning", 0x811C9DC5);
                  _((AMD_HD3D *)stru_1423D9A7C.mUID);
                  atexit(UFG::CopSystem::HandleDamageEvent__::J_::_dynamic_atexit_destructor_for__play_sirens_warning__);
                }
                UFG::OneShot::Play(pHandle.m_pOneShot, stru_1423D9A7C.mUID);
              }
            }
            UFG::OneShotHandle::Release(&pHandle);
          }
        }
        goto LABEL_175;
      }
      if ( (v38 >> 13) & 1 )
      {
        v39 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v7->vfptr,
                UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v38 >> 12) & 1 )
      {
        v39 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v7->vfptr,
                UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v39 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      }
    }
    v40 = (hkSimpleLocalFrame *)v39;
    goto LABEL_123;
  }
  v31 = 0;
  pIsCop = 0;
  pIsAmbient = 0;
  UFG::GameStatAction::MissionScoring::DeduceFaction((UFG::SimObject *)&v7->vfptr, &pIsCop, &pIsAmbient);
  v32 = pIsCop;
  v33 = pIsAmbient;
  if ( !pTargetHealthComponent || (v31 = pTargetHealthComponent->m_bIsKnockedOut, pIsAmbient) || pIsCop )
  {
    v34 = v6->mAttackTypeID;
    if ( v31 )
    {
      v35 = 0;
      v36 = v53;
      if ( v10 )
      {
        LOBYTE(v35) = pIsCop != 0;
        v30 = v35 + 14;
      }
      else
      {
        LOBYTE(v35) = pIsCop != 0;
        v30 = v35 + 6;
      }
      goto LABEL_176;
    }
    if ( v34 == gAttackCollisionVehicleTireShot.m_EnumValue )
    {
      v30 = (pIsCop != 0) + 21;
    }
    else if ( v10 )
    {
      v30 = (pIsCop != 0) + 12;
    }
    else if ( v34 == gAttackCollisionProjectile.m_EnumValue )
    {
      v30 = (pIsCop != 0) + 4;
    }
    else
    {
      if ( !appliedDamage )
      {
LABEL_108:
        v36 = v53;
        if ( !v53->mIsExcludingPlayerForRestOfChase || !v32 )
          goto LABEL_176;
        v53->vfptr[103].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v53->vfptr, v33);
        goto LABEL_175;
      }
      v30 = (pIsCop != 0) + 2;
    }
    if ( pIsCop || pIsAmbient )
    {
      v37 = 3;
      if ( pIsCop )
        v37 = 1;
      UFG::GameStatAction::MissionScoring::LogCopEvent(v37, 0, &customWorldMapCaption);
      v32 = pIsCop;
    }
    goto LABEL_108;
  }
}

// File Line: 275
// RVA: 0x3EF020
void __fastcall UFG::CopSystem::HandleVehicleMeleeDamage(UFG::CopSystem *this, UFG::SimObject *pSource, UFG::SimObject *pTarget)
{
  UFG::SimObject *v3; // rsi
  UFG::SimObject *v4; // rbx
  UFG::CopSystem *v5; // rdi
  UFG::SimObjectCharacter *v6; // rax
  BOOL v7; // ebx
  bool pIsCop; // [rsp+38h] [rbp+10h]
  bool pIsAmbient; // [rsp+48h] [rbp+20h]

  v3 = pTarget;
  v4 = pSource;
  v5 = this;
  v6 = UFG::GetLocalPlayer();
  if ( v4 )
  {
    if ( v4 == (UFG::SimObject *)v6 )
    {
      pIsCop = 0;
      pIsAmbient = 0;
      UFG::GameStatAction::MissionScoring::DeduceFaction(v3, &pIsCop, &pIsAmbient);
      if ( pIsCop || pIsAmbient )
      {
        v7 = pIsCop != 0;
        if ( !pIsCop )
          UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DAMAGE, 0, &customWorldMapCaption);
        v5->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v7 + 12);
      }
    }
  }
}

// File Line: 299
// RVA: 0x3EE5D0
void __fastcall UFG::CopSystem::HandleDestructionEvent(UFG::CopSystem *this, UFG::DestructionEvent *e)
{
  UFG::qReflectObject *v2; // rax
  UFG::CopSystem *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCharacter *v7; // rbx

  v2 = e->objectProperty.mData;
  v3 = this;
  if ( !v2 || BYTE4(v2[1].mTypeUID) )
  {
    v4 = (UFG::SimObjectGame *)e->mCollidingComponent.m_pPointer;
    if ( v4 )
      v4 = (UFG::SimObjectGame *)v4->mNode.mParent;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleOccupantComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleOccupantComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v6 = v4->m_Components.p[30].m_pComponent;
      }
      if ( v6 )
      {
        v7 = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v6);
        if ( v7 == UFG::GetLocalPlayer() )
        {
          v3->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, 11u);
          UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_HIT_DESTRUCTIBLE, 0, &customWorldMapCaption);
        }
      }
    }
  }
}

// File Line: 326
// RVA: 0x3EE750
void __fastcall UFG::CopSystem::HandleGameStatEvent(UFG::CopSystem *this, UFG::Event *e)
{
  UFG::SimObjectCharacter *v2; // rbx
  UFG::Event *v3; // rsi
  UFG::CopSystem *v4; // rdi
  int v5; // esi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rdx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rax
  signed __int64 v10; // rcx
  UFG::SimObject *v11; // rbx
  UFG::SimObject *v12; // rcx
  UFG::GameStatTracker *v13; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v14; // rax
  int v15; // ebx
  UFG::GameStatTracker *v16; // rax
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rdx
  UFG::SimComponent *v19; // rax
  UFG::SimObjectCharacter *v20; // rbx
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  signed int v23; // edx
  bool pIsCop; // [rsp+38h] [rbp+10h]
  bool pIsAmbient; // [rsp+40h] [rbp+18h]

  v2 = (UFG::SimObjectCharacter *)e[1].mPrev;
  v3 = e;
  v4 = this;
  if ( v2 == UFG::GetLocalPlayer() )
  {
    v5 = (int)v3[1].vfptr;
    switch ( v5 )
    {
      case 45:
      case 46:
        if ( v2 )
        {
          v6 = v2->m_Flags;
          if ( (v6 >> 14) & 1 )
          {
            v7 = v2->m_Components.p[20].m_pComponent;
          }
          else if ( (v6 & 0x8000u) == 0 )
          {
            if ( (v6 >> 13) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)&v2->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else if ( (v6 >> 12) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)&v2->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v8 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&v2->vfptr,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v7 = v8;
          }
          else
          {
            v7 = v2->m_Components.p[20].m_pComponent;
          }
          if ( v7 )
          {
            v9 = *(_QWORD *)&v7[1].m_TypeUID;
            v10 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + 31i64);
            v11 = *(UFG::SimObject **)(v10 + v9 + 40);
            if ( v11 )
            {
              v12 = *(UFG::SimObject **)(v10 + v9 + 40);
              pIsCop = 0;
              pIsAmbient = 0;
              UFG::GameStatAction::MissionScoring::DeduceFaction(v12, &pIsCop, &pIsAmbient);
              if ( pIsCop || pIsAmbient )
              {
                v13 = UFG::FactionInterface::Get();
                UFG::FactionInterface::GetFaction(&v13->mFactionInterface, v11);
                v14 = v4->vfptr;
                v15 = 0;
                if ( v5 == 46 )
                {
                  LOBYTE(v15) = pIsCop != 0;
                  v14[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, v15 + 2);
                }
                else
                {
                  LOBYTE(v15) = pIsCop != 0;
                  v14[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, v15 + 17);
                }
              }
            }
          }
        }
        break;
      case 51:
        v4->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, 23u);
        break;
      case 96:
        v16 = UFG::GameStatTracker::Instance();
        if ( (signed int)UFG::GameStatTracker::GetStat(v16, CopDrivingStage) >= 3 )
          UFG::CopSystem::ApplyReducedRadius(v4);
        break;
      case 103:
      case 106:
        v4->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, 16u);
        break;
      default:
        return;
    }
  }
  else if ( LODWORD(v3[1].vfptr) == 6 )
  {
    if ( v2
      && ((v17 = v2->m_Flags, !((v17 >> 14) & 1)) ? ((v17 & 0x8000u) == 0 ? (!((v17 >> 13) & 1) ? (!((v17 >> 12) & 1) ? (v19 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v19 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v19 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                             v18 = v19) : (v18 = v2->m_Components.p[20].m_pComponent)) : (v18 = v2->m_Components.p[20].m_pComponent),
          v18) )
    {
      v20 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v18[1].m_Flags + 31i64)
                                        + *(_QWORD *)&v18[1].m_TypeUID
                                        + 40);
    }
    else
    {
      v20 = 0i64;
    }
    if ( v20 == UFG::GetLocalPlayer() )
    {
      ++v4->mNumArrestAttempts;
      if ( v20 )
      {
        v21 = v20->m_Flags;
        if ( (v21 >> 14) & 1 )
        {
          v22 = v20->m_Components.p[5].m_pComponent;
        }
        else if ( (v21 & 0x8000u) == 0 )
        {
          if ( (v21 >> 13) & 1 )
            v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v20->vfptr,
                    UFG::AIScriptInterfaceComponent::_TypeUID);
          else
            v22 = (v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&v20->vfptr,
                                      UFG::AIScriptInterfaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v20->vfptr,
                                                                                     UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          v22 = v20->m_Components.p[5].m_pComponent;
        }
        if ( v22 )
        {
          if ( !((_QWORD)v22[32].m_BoundComponentHandles.mNode.mPrev & 0x20) )
          {
            v4->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, 25u);
            v23 = v4->mHeatLevel;
            if ( v23 < 2 )
              ((void (__fastcall *)(UFG::CopSystem *, _QWORD, signed __int64))v4->vfptr[88].__vecDelDtor)(
                v4,
                (unsigned int)(v23 + 1),
                25i64);
          }
        }
      }
    }
  }
}

// File Line: 425
// RVA: 0x3EE6C0
void __fastcall UFG::CopSystem::HandleDryWeaponFire(UFG::CopSystem *this, UFG::SimObject *pSource)
{
  UFG::CopSystem *v2; // rdi

  v2 = this;
  if ( pSource == (UFG::SimObject *)UFG::GetLocalPlayer() )
    v2->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, 10u);
}

// File Line: 433
// RVA: 0x3EE700
void __fastcall UFG::CopSystem::HandleFaceAction(UFG::CopSystem *this, UFG::SimObject *pSource, UFG::Stimulus *pStimulus)
{
  UFG::Stimulus *v3; // rsi
  UFG::CopSystem *v4; // rdi

  v3 = pStimulus;
  v4 = this;
  if ( pSource == (UFG::SimObject *)UFG::GetLocalPlayer() && v3->m_Description.m_Type == 29 )
    v4->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, 1u);
}

