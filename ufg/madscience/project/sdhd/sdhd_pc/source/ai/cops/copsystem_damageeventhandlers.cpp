// File Line: 8
// RVA: 0x3EDD30
void __fastcall UFG::CopSystem::HandleDamageEvent(
        UFG::CopSystem *this,
        UFG::SimObjectProp *pSource,
        UFG::SimObjectVehicle *pTarget,
        UFG::HitRecord *pHitRecord,
        UFG::HealthComponent *pTargetHealthComponent,
        bool appliedDamage)
{
  UFG::SimObjectCharacter *LocalPlayer; // r14
  char v10; // r15
  char v11; // r12
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  signed __int16 v14; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  __int16 v16; // cx
  UFG::VehicleOwnershipComponent *ComponentOfType; // rax
  UFG::SimObject *OwnedVehicle; // rax
  signed __int16 v19; // cx
  UFG::TSActorComponent *v20; // rbx
  signed __int16 v21; // dx
  UFG::SimComponent *v22; // rbp
  UFG::SimComponent *v23; // rax
  UFG::TSActor *i_obj_p; // rax
  SSActorClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  signed __int16 v27; // cx
  UFG::MissionFailConditionComponent *v28; // rax
  float v29; // xmm6_4
  unsigned int v30; // ebx
  bool m_bIsKnockedOut; // si
  bool v32; // al
  _BOOL8 v33; // rdx
  int mAttackTypeID; // ecx
  UFG::CopSystem *v35; // rcx
  BOOL v36; // ebx
  UFG::GameStatAction::MissionScoring::CopScoreEvent v37; // ecx
  signed __int16 v38; // cx
  UFG::SimComponent *v39; // rbp
  UFG::SimComponent *v40; // rax
  UFG::SimObjectCVBase *Texture; // rax
  char v42; // bp
  signed __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  signed __int16 v46; // cx
  UFG::VehicleAudioComponent *v47; // rax
  UFG::TransformNodeComponent *v48; // rsi
  signed __int16 v49; // cx
  UFG::VehicleAudioComponent *v50; // rax
  UFG::OneShotHandle pHandle; // [rsp+20h] [rbp-58h] BYREF
  __int64 v52; // [rsp+28h] [rbp-50h]
  bool pIsCop; // [rsp+88h] [rbp+10h] BYREF
  bool pIsAmbient; // [rsp+90h] [rbp+18h] BYREF

  v52 = -2i64;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( pTarget == (UFG::SimObjectVehicle *)LocalPlayer && pHitRecord && pHitRecord->mIsDeadly )
    UFG::GameStatAction::Player::RegisterPlayerDeath(pSource, pHitRecord);
  if ( !pSource )
    return;
  v10 = 0;
  v11 = 1;
  if ( pSource == (UFG::SimObjectProp *)LocalPlayer )
    goto LABEL_43;
  m_Flags = pSource->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSource->m_Components.p[23].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(pSource, UFG::VehicleDriverInterface::_TypeUID);
    else
      m_pComponent = UFG::SimObject::GetComponentOfType(pSource, UFG::VehicleDriverInterface::_TypeUID);
  }
  else
  {
    m_pComponent = pSource->m_Components.p[23].m_pComponent;
  }
  if ( m_pComponent )
  {
    if ( (UFG::SimObjectCharacter *)m_pComponent[3].m_BoundComponentHandles.mNode.mNext != LocalPlayer )
      return;
LABEL_42:
    v10 = 1;
    goto LABEL_43;
  }
  v14 = pSource->m_Flags;
  if ( (v14 & 0x4000) != 0 || v14 < 0 )
  {
LABEL_24:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     pSource,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_26;
  }
  if ( (v14 & 0x2000) == 0 )
  {
    if ( (v14 & 0x1000) == 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       pSource,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_26;
    }
    goto LABEL_24;
  }
  ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(pSource);
LABEL_26:
  if ( !ComponentOfTypeHK )
  {
    if ( LocalPlayer
      && ((v16 = LocalPlayer->m_Flags, (v16 & 0x4000) == 0) && v16 >= 0 && (v16 & 0x2000) == 0 && (v16 & 0x1000) == 0
        ? (ComponentOfType = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                                 LocalPlayer,
                                                                 UFG::VehicleOwnershipComponent::_TypeUID))
        : (ComponentOfType = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 LocalPlayer,
                                                                 UFG::VehicleOwnershipComponent::_TypeUID)),
          ComponentOfType) )
    {
      OwnedVehicle = UFG::VehicleOwnershipComponent::GetOwnedVehicle(ComponentOfType);
    }
    else
    {
      OwnedVehicle = 0i64;
    }
    if ( OwnedVehicle != pSource )
      return;
    v11 = 0;
    goto LABEL_42;
  }
  if ( ComponentOfTypeHK->mLastOwner != LocalPlayer->mNode.mUID )
    return;
LABEL_43:
  UFG::GameStatAction::Player::RegisterSuccessfulHit(pSource, pTarget, pHitRecord);
  if ( pTarget )
  {
    v19 = pTarget->m_Flags;
    if ( (v19 & 0x4000) != 0 )
    {
      v20 = (UFG::TSActorComponent *)pTarget->m_Components.p[4].m_pComponent;
    }
    else if ( v19 >= 0 )
    {
      if ( (v19 & 0x2000) != 0 )
        v20 = (UFG::TSActorComponent *)pTarget->m_Components.p[3].m_pComponent;
      else
        v20 = (UFG::TSActorComponent *)((v19 & 0x1000) != 0
                                      ? pTarget->m_Components.p[2].m_pComponent
                                      : UFG::SimObject::GetComponentOfType(pTarget, UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      v20 = (UFG::TSActorComponent *)pTarget->m_Components.p[4].m_pComponent;
    }
    v21 = pTarget->m_Flags;
    if ( (v21 & 0x4000) != 0 )
    {
      v22 = pTarget->m_Components.p[6].m_pComponent;
    }
    else if ( v21 >= 0 )
    {
      v23 = (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(pTarget, UFG::HealthComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(pTarget, UFG::HealthComponent::_TypeUID);
      v22 = v23;
    }
    else
    {
      v22 = pTarget->m_Components.p[6].m_pComponent;
    }
    if ( v20 )
    {
      if ( v22 )
      {
        i_obj_p = v20->mpActor.i_obj_p;
        if ( i_obj_p )
        {
          if ( v20->mpActor.i_ptr_id == i_obj_p->i_ptr_id )
          {
            i_class_p = (SSActorClass *)UFG::TSActorComponent::GetActor(v20)->i_class_p;
            if ( UFG::SkookumMgr::mspCharacterClass == i_class_p
              || (i_superclass_p = i_class_p->i_superclass_p) != 0i64
              && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass) )
            {
              v27 = pTarget->m_Flags;
              if ( (v27 & 0x4000) != 0 )
              {
                v28 = (UFG::MissionFailConditionComponent *)pTarget->m_Components.p[8].m_pComponent;
              }
              else if ( v27 >= 0 )
              {
                v28 = (UFG::MissionFailConditionComponent *)((v27 & 0x2000) != 0 || (v27 & 0x1000) != 0
                                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               pTarget,
                                                               UFG::MissionFailConditionComponent::_TypeUID)
                                                           : UFG::SimObject::GetComponentOfType(
                                                               pTarget,
                                                               UFG::MissionFailConditionComponent::_TypeUID));
              }
              else
              {
                v28 = (UFG::MissionFailConditionComponent *)pTarget->m_Components.p[8].m_pComponent;
              }
              if ( v28 )
              {
                if ( v28->mDamageFailTrigger )
                {
                  v29 = *((float *)&v22[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&v22[1].m_NameUID;
                  if ( v29 <= UFG::MissionFailConditionComponent::GetFailThreshold(v28, &qSymbol_DamageHealthThreshold) )
                    UFG::MissionFailConditionComponent::FailObject(pTarget, &qSymbol_DamageFailCaption);
                }
              }
            }
          }
        }
      }
    }
  }
  v30 = 26;
  if ( !pHitRecord )
  {
    if ( !v10 )
      return;
    pIsCop = 0;
    pIsAmbient = 0;
    UFG::GameStatAction::MissionScoring::DeduceFaction(pTarget, &pIsCop, &pIsAmbient);
    if ( !pTarget )
      goto LABEL_119;
    v38 = pTarget->m_Flags;
    if ( (v38 & 0x4000) != 0 )
      goto LABEL_113;
    if ( v38 < 0 )
    {
      v39 = pTarget->m_Components.p[30].m_pComponent;
LABEL_116:
      if ( v39 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v39) )
      {
        Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v39);
        v42 = UFG::AreCharactersAllied(LocalPlayer, Texture);
        goto LABEL_120;
      }
LABEL_119:
      v42 = 1;
LABEL_120:
      v43 = pSource->m_Flags;
      if ( (v43 & 0x4000) != 0 )
      {
        v44 = 0i64;
      }
      else if ( v43 >= 0 )
      {
        if ( (v43 & 0x2000) != 0 )
        {
          v44 = 0i64;
        }
        else if ( (v43 & 0x1000) != 0 )
        {
          v44 = UFG::SimObjectGame::GetComponentOfTypeHK(pSource, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          v44 = UFG::SimObject::GetComponentOfType(pSource, UFG::PhysicsMoverInterface::_TypeUID);
        }
      }
      else
      {
        v44 = pSource->m_Components.p[34].m_pComponent;
      }
      if ( !v11 || v44 && (float)(*((float *)&v44[10].m_BoundComponentHandles.mNode.mPrev + 1) * 3.5999999) > 40.0 )
      {
        if ( pIsCop || pIsAmbient )
        {
          v30 = pIsCop + 19;
          if ( pIsCop )
          {
LABEL_139:
            if ( pTarget )
            {
              m_pTransformNodeComponent = pTarget->m_pTransformNodeComponent;
              v46 = pTarget->m_Flags;
              if ( (v46 & 0x4000) == 0 )
              {
                if ( v46 < 0 )
                {
                  v47 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(pTarget);
LABEL_148:
                  if ( !m_pTransformNodeComponent || !v47 )
                    goto LABEL_166;
                  pHandle.m_pOneShot = 0i64;
                  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                  UFG::OneShotPool::GetOneShotHandle(&pHandle, &m_pTransformNodeComponent->mWorldTransform);
                  if ( !UFG::OneShotHandle::IsValid(&pHandle) )
                    goto LABEL_165;
                  v48 = pTarget->m_pTransformNodeComponent;
                  v49 = pTarget->m_Flags;
                  if ( (v49 & 0x4000) == 0 )
                  {
                    if ( v49 < 0 )
                    {
                      v50 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(pTarget);
LABEL_159:
                      if ( v48 && v50 && UFG::VehicleAudioComponent::HasOccupant(v50) )
                      {
                        if ( (dword_1423D9A80 & 1) == 0 )
                        {
                          dword_1423D9A80 |= 1u;
                          stru_1423D9A7C.mUID = UFG::qWiseSymbolUIDFromString("play_sirens_warning", 0x811C9DC5);
                          _((AMD_HD3D *)stru_1423D9A7C.mUID);
                          atexit(UFG::CopSystem::HandleDamageEvent__::J_::_dynamic_atexit_destructor_for__play_sirens_warning__);
                        }
                        UFG::OneShot::Play(pHandle.m_pOneShot, stru_1423D9A7C.mUID);
                      }
LABEL_165:
                      UFG::OneShotHandle::Release(&pHandle);
                      goto LABEL_166;
                    }
                    if ( (v49 & 0x2000) == 0 && (v49 & 0x1000) == 0 )
                    {
                      v50 = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                            pTarget,
                                                            UFG::VehicleAudioComponent::_TypeUID);
                      goto LABEL_159;
                    }
                  }
                  v50 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        pTarget,
                                                        UFG::VehicleAudioComponent::_TypeUID);
                  goto LABEL_159;
                }
                if ( (v46 & 0x2000) == 0 && (v46 & 0x1000) == 0 )
                {
                  v47 = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        pTarget,
                                                        UFG::VehicleAudioComponent::_TypeUID);
                  goto LABEL_148;
                }
              }
              v47 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    pTarget,
                                                    UFG::VehicleAudioComponent::_TypeUID);
              goto LABEL_148;
            }
LABEL_166:
            v35 = this;
LABEL_167:
            if ( v30 != 26 )
              v35->vfptr[111].__vecDelDtor(v35, v30);
            return;
          }
          UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DAMAGE, 0, &customCaption);
        }
        else
        {
          if ( v42 )
            return;
          UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_DAMAGE, 0, &customCaption);
        }
      }
      if ( !pIsCop )
        goto LABEL_166;
      goto LABEL_139;
    }
    if ( (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0 )
LABEL_113:
      v40 = UFG::SimObjectGame::GetComponentOfTypeHK(pTarget, UFG::VehicleOccupantComponent::_TypeUID);
    else
      v40 = UFG::SimObject::GetComponentOfType(pTarget, UFG::VehicleOccupantComponent::_TypeUID);
    v39 = v40;
    goto LABEL_116;
  }
  m_bIsKnockedOut = 0;
  pIsCop = 0;
  pIsAmbient = 0;
  UFG::GameStatAction::MissionScoring::DeduceFaction(pTarget, &pIsCop, &pIsAmbient);
  v32 = pIsCop;
  v33 = pIsAmbient;
  if ( !pTargetHealthComponent || (m_bIsKnockedOut = pTargetHealthComponent->m_bIsKnockedOut, pIsAmbient) || pIsCop )
  {
    mAttackTypeID = pHitRecord->mAttackTypeID;
    if ( m_bIsKnockedOut )
    {
      v35 = this;
      v36 = pIsCop;
      if ( v10 )
        v30 = v36 + 14;
      else
        v30 = v36 + 6;
      goto LABEL_167;
    }
    if ( mAttackTypeID == gAttackCollisionVehicleTireShot.m_EnumValue )
    {
      v30 = pIsCop + 21;
    }
    else if ( v10 )
    {
      v30 = pIsCop + 12;
    }
    else if ( mAttackTypeID == gAttackCollisionProjectile.m_EnumValue )
    {
      v30 = pIsCop + 4;
    }
    else
    {
      if ( !appliedDamage )
      {
LABEL_102:
        v35 = this;
        if ( !this->mIsExcludingPlayerForRestOfChase || !v32 )
          goto LABEL_167;
        this->vfptr[103].__vecDelDtor(this, v33);
        goto LABEL_166;
      }
      v30 = pIsCop + 2;
    }
    if ( pIsCop || pIsAmbient )
    {
      v37 = COP_PEDESTRIAN_HIT;
      if ( pIsCop )
        v37 = COP_HIT;
      UFG::GameStatAction::MissionScoring::LogCopEvent(v37, 0, &customCaption);
      v32 = pIsCop;
    }
    goto LABEL_102;
  }
}

// File Line: 275
// RVA: 0x3EF020
void __fastcall UFG::CopSystem::HandleVehicleMeleeDamage(
        UFG::CopSystem *this,
        UFG::SimObjectCharacter *pSource,
        UFG::SimObject *pTarget)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  BOOL v7; // ebx
  bool pIsCop; // [rsp+38h] [rbp+10h] BYREF
  bool pIsAmbient; // [rsp+48h] [rbp+20h] BYREF

  LocalPlayer = UFG::GetLocalPlayer();
  if ( pSource )
  {
    if ( pSource == LocalPlayer )
    {
      pIsCop = 0;
      pIsAmbient = 0;
      UFG::GameStatAction::MissionScoring::DeduceFaction(pTarget, &pIsCop, &pIsAmbient);
      if ( pIsCop || pIsAmbient )
      {
        v7 = pIsCop;
        if ( !pIsCop )
          UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DAMAGE, 0, &customCaption);
        this->vfptr[111].__vecDelDtor(this, v7 + 12);
      }
    }
  }
}

// File Line: 299
// RVA: 0x3EE5D0
void __fastcall UFG::CopSystem::HandleDestructionEvent(UFG::CopSystem *this, UFG::DestructionEvent *e)
{
  UFG::qReflectObject *mData; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCharacter *Texture; // rbx

  mData = e->objectProperty.mData;
  if ( !mData || BYTE4(mData[1].mTypeUID) )
  {
    m_pPointer = (UFG::SimObjectGame *)e->mCollidingComponent.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (UFG::SimObjectGame *)m_pPointer->mNode.mParent;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        goto LABEL_12;
      if ( m_Flags < 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[30].m_pComponent;
        goto LABEL_14;
      }
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_12:
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_14:
      if ( m_pComponent )
      {
        Texture = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
        if ( Texture == UFG::GetLocalPlayer() )
        {
          this->vfptr[111].__vecDelDtor(this, 11u);
          UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_HIT_DESTRUCTIBLE, 0, &customCaption);
        }
      }
    }
  }
}

// File Line: 326
// RVA: 0x3EE750
void __fastcall UFG::CopSystem::HandleGameStatEvent(UFG::CopSystem *this, UFG::Event *e)
{
  UFG::SimObjectCharacter *mPrev; // rbx
  int vfptr; // esi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v9; // rax
  __int64 v10; // rcx
  UFG::SimObjectCVBase *v11; // rbx
  UFG::SimObject *v12; // rcx
  UFG::GameStatTracker *v13; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v14; // rax
  BOOL v15; // ebx
  UFG::GameStatTracker *v16; // rax
  __int16 v17; // cx
  UFG::SimComponent *v18; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectCharacter *v20; // rbx
  __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  UFG::HeatLevelEnum mHeatLevel; // edx
  bool pIsCop; // [rsp+38h] [rbp+10h] BYREF
  bool pIsAmbient; // [rsp+40h] [rbp+18h] BYREF

  mPrev = (UFG::SimObjectCharacter *)e[1].mPrev;
  if ( mPrev == UFG::GetLocalPlayer() )
  {
    vfptr = (int)e[1].vfptr;
    switch ( vfptr )
    {
      case -:
      case .:
        if ( mPrev )
        {
          m_Flags = mPrev->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = mPrev->m_Components.p[20].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    mPrev,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mPrev, UFG::TargetingSystemBaseComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
          else
          {
            m_pComponent = mPrev->m_Components.p[20].m_pComponent;
          }
          if ( m_pComponent )
          {
            v9 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
            v10 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64);
            v11 = *(UFG::SimObjectCVBase **)(v10 + v9 + 40);
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
                v14 = this->vfptr;
                v15 = pIsCop;
                if ( vfptr == 46 )
                  v14[111].__vecDelDtor(this, v15 + 2);
                else
                  v14[111].__vecDelDtor(this, v15 + 17);
              }
            }
          }
        }
        break;
      case 3:
        this->vfptr[111].__vecDelDtor(this, 23u);
        break;
      case `:
        v16 = UFG::GameStatTracker::Instance();
        if ( (int)UFG::GameStatTracker::GetStat(v16, CopDrivingStage) >= 3 )
          UFG::CopSystem::ApplyReducedRadius(this);
        break;
      case g:
      case j:
        this->vfptr[111].__vecDelDtor(this, 16u);
        break;
      default:
        return;
    }
  }
  else if ( LODWORD(e[1].vfptr) == 6 )
  {
    if ( mPrev
      && ((v17 = mPrev->m_Flags, (v17 & 0x4000) == 0)
        ? (v17 >= 0
         ? ((v17 & 0x2000) != 0 || (v17 & 0x1000) != 0
          ? (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 mPrev,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
          : (ComponentOfType = UFG::SimObject::GetComponentOfType(mPrev, UFG::TargetingSystemBaseComponent::_TypeUID)),
            v18 = ComponentOfType)
         : (v18 = mPrev->m_Components.p[20].m_pComponent))
        : (v18 = mPrev->m_Components.p[20].m_pComponent),
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
      ++this->mNumArrestAttempts;
      if ( v20 )
      {
        v21 = v20->m_Flags;
        if ( (v21 & 0x4000) != 0 )
        {
          v22 = v20->m_Components.p[5].m_pComponent;
        }
        else if ( v21 >= 0 )
        {
          v22 = (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AIScriptInterfaceComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v20, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          v22 = v20->m_Components.p[5].m_pComponent;
        }
        if ( v22 )
        {
          if ( ((__int64)v22[32].m_BoundComponentHandles.mNode.mPrev & 0x20) == 0 )
          {
            this->vfptr[111].__vecDelDtor(this, 25u);
            mHeatLevel = this->mHeatLevel;
            if ( mHeatLevel < HEATLEVEL_TWO )
              ((void (__fastcall *)(UFG::CopSystem *, _QWORD, __int64))this->vfptr[88].__vecDelDtor)(
                this,
                (unsigned int)(mHeatLevel + 1),
                25i64);
          }
        }
      }
    }
  }
}

// File Line: 425
// RVA: 0x3EE6C0
void __fastcall UFG::CopSystem::HandleDryWeaponFire(UFG::CopSystem *this, UFG::SimObjectCharacter *pSource)
{
  if ( pSource == UFG::GetLocalPlayer() )
    this->vfptr[111].__vecDelDtor(this, 10u);
}

// File Line: 433
// RVA: 0x3EE700
void __fastcall UFG::CopSystem::HandleFaceAction(
        UFG::CopSystem *this,
        UFG::SimObjectCharacter *pSource,
        UFG::Stimulus *pStimulus)
{
  if ( pSource == UFG::GetLocalPlayer() && pStimulus->m_Description.m_Type == eSTIMULUS_INTIMIDATE )
    this->vfptr[111].__vecDelDtor(this, 1u);
}

