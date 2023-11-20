// File Line: 11
// RVA: 0x3F6100
signed __int64 __fastcall UFG::qReflectInventory<UFG::PartDefinition>::GetClassSize(UFG::qReflectInventory<UFG::PartDefinition> *this)
{
  return 224i64;
}

// File Line: 28
// RVA: 0x3F2560
void __fastcall UFG::EncounterUnitComponent::EncounterUnitComponent(UFG::EncounterUnitComponent *this, unsigned int name_uid)
{
  UFG::EncounterUnitComponent *v2; // rbx
  UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *v3; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::EncounterUnitComponent::`vftable';
  v2->mRole = 0;
  v3 = &v2->mpEncounter;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v2->mpEncounter.m_BindCallback.m_Closure.m_pthis = 0i64;
  v2->mpEncounter.m_BindCallback.m_Closure.m_pFunction = 0i64;
  v2->mpEncounter.m_UnbindCallback.m_Closure.m_pthis = 0i64;
  v2->mpEncounter.m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  v2->mpEncounter.m_pPointer = 0i64;
  v2->mpEncounter.m_Changed = 0;
  v2->mWaveType.mUID = -1;
  *(_DWORD *)&v2->mWaveTypeGroupIndex = 255;
  v2->mEnableKillCount = 1;
  v2->mInsideRadiusTimer = -1.0;
  *(_QWORD *)&v2->mAcquiredTimer = 0i64;
  v4 = &v2->mGroupVehicle;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v2->mGroupVehicle.m_pPointer = 0i64;
  v2->mpObjectiveIndicator = 0i64;
  v2->mContext.mpSimObject = 0i64;
  v2->mContext.mpVehicle = 0i64;
  v2->mContext.mWaterContextTimer = 0.0;
  *(_DWORD *)&v2->mContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&v2->mContext.mIsOnMeshHeuristic = 1;
  v2->mContext.mOpenFiredWithHostage = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::EncounterUnitComponent::_EncounterUnitComponentTypeUID,
    "EncounterUnitComponent");
  v2->mpEncounter.m_UnbindCallback.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::EncounterUnitComponent::EncounterGoingNull;
  v2->mpEncounter.m_UnbindCallback.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
}

// File Line: 38
// RVA: 0x3F29F0
void __fastcall UFG::EncounterUnitComponent::~EncounterUnitComponent(UFG::EncounterUnitComponent *this)
{
  UFG::EncounterUnitComponent *v1; // rbx
  UFG::ObjectiveIndicator *v2; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::EncounterUnitComponent::`vftable';
  v2 = this->mpObjectiveIndicator;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->mpObjectiveIndicator = 0i64;
  }
  v3 = &v1->mGroupVehicle;
  if ( v1->mGroupVehicle.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v1->mGroupVehicle.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v1->mGroupVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mGroupVehicle.mPrev;
  }
  v1->mGroupVehicle.m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v1->mGroupVehicle.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->mGroupVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mGroupVehicle.mPrev;
  UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>::~qSafePointerWithCallbacksBase<UFG::EncounterBase>((UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase> *)&v1->mpEncounter.mPrev);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 47
// RVA: 0x3F3AD0
void __fastcall UFG::EncounterUnitComponent::EncounterGoingNull(UFG::EncounterUnitComponent *this, UFG::EncounterBase *e)
{
  UFG::qPrintf("who's fucking with this! %p\n", e);
}

// File Line: 53
// RVA: 0x3F2E90
void __fastcall UFG::EncounterUnitComponent::AcquireBy(UFG::EncounterUnitComponent *this, UFG::EncounterBase *pEncounter, UFG::qPropertySet *pGroupPropertySet)
{
  UFG::qPropertySet *v3; // rdi
  UFG::EncounterUnitComponent *v4; // rbx
  UFG::EncounterBase *v5; // rcx

  v3 = pGroupPropertySet;
  v4 = this;
  if ( this->mpEncounter.m_pPointer != pEncounter )
    this->mAcquiredTimer = 0.0;
  ++this->mUsageCount;
  this->mEngaged = 0;
  this->mEnableKillCount = 1;
  this->mVehicleFlipTimer = 0.0;
  this->mInsideRadiusTimer = -1.0;
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(&this->mpEncounter, pEncounter);
  v5 = v4->mpEncounter.m_pPointer;
  v4->mRole = 0;
  v4->mWaveType.mUID = *(_DWORD *)((__int64 (*)(void))v5->vfptr[26].__vecDelDtor)();
  if ( v3 )
    v4->mWaveTypeGroupIndex = (__int64)v4->mpEncounter.m_pPointer->vfptr[29].__vecDelDtor(
                                         (UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->mpEncounter.m_pPointer->vfptr,
                                         (unsigned int)v3);
  else
    v4->mWaveTypeGroupIndex = -1;
  UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v4);
  v4->mContext.mpSimObject = 0i64;
  v4->mContext.mpVehicle = 0i64;
  v4->mContext.mWaterContextTimer = 0.0;
  v4->mContext.mOpenFiredWithHostage = 0;
  *(_DWORD *)&v4->mContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&v4->mContext.mIsOnMeshHeuristic = 1;
}

// File Line: 87
// RVA: 0x3F8EF0
void __fastcall UFG::EncounterUnitComponent::ReleaseByEncounter(UFG::EncounterUnitComponent *this)
{
  UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *v1; // r8
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *v3; // rax

  --this->mUsageCount;
  v1 = &this->mpEncounter;
  this->mEngaged = 0;
  this->mAcquiredTimer = 0.0;
  this->mInsideRadiusTimer = -1.0;
  if ( this->mpEncounter.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->mpEncounter.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->mpEncounter.mNext = (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *)&this->mpEncounter.mPrev;
    this->mpEncounter.m_Changed = 1;
  }
  this->mpEncounter.m_pPointer = 0i64;
  this->mRole = 0;
  this->mWaveType = UFG::gNullQSymbol;
  this->mWaveTypeGroupIndex = -1;
  UFG::EncounterUnitComponent::DecrementGroupVehicleUsageCount(this);
}

// File Line: 108
// RVA: 0x3F7BC0
void __fastcall UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(UFG::EncounterUnitComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mGroupVehicle.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[16].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::EncounterUnitComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::EncounterUnitComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::EncounterUnitComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v1->m_Components.p[16].m_pComponent;
    }
    if ( v3 )
      ++BYTE5(v3[2].m_SafePointerList.mNode.mPrev);
  }
}

// File Line: 118
// RVA: 0x3F39F0
void __fastcall UFG::EncounterUnitComponent::DecrementGroupVehicleUsageCount(UFG::EncounterUnitComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mGroupVehicle.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[16].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::EncounterUnitComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::EncounterUnitComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::EncounterUnitComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v1->m_Components.p[16].m_pComponent;
    }
    if ( v3 )
      --BYTE5(v3[2].m_SafePointerList.mNode.mPrev);
  }
}

// File Line: 128
// RVA: 0x3F8DB0
void __fastcall UFG::EncounterUnitComponent::OnAttach(UFG::EncounterUnitComponent *this, UFG::SimObject *pObject)
{
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pObject->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[EncounterUnitComponent]: OnAttach (%s)\n");
}

// File Line: 133
// RVA: 0x3F8DE0
void __fastcall UFG::EncounterUnitComponent::OnDetach(UFG::EncounterUnitComponent *this)
{
  UFG::EncounterUnitComponent *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::EncounterBase *v3; // rcx

  v1 = this;
  v2 = this->m_pSimObject;
  if ( v2 )
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[EncounterUnitComponent]: OnDetach (%s)\n");
  v3 = v1->mpEncounter.m_pPointer;
  if ( v3 )
  {
    v3->vfptr[24].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, (unsigned int)v1);
    UFG::EncounterUnitComponent::ReleaseByEncounter(v1);
  }
}

// File Line: 157
// RVA: 0x3F9230
void __fastcall UFG::EncounterUnitContext::Reset(UFG::EncounterUnitContext *this)
{
  *(_DWORD *)&this->mIsOnFootRaw = 16777217;
  *(_WORD *)&this->mIsOnMeshHeuristic = 1;
  this->mpSimObject = 0i64;
  this->mpVehicle = 0i64;
  this->mWaterContextTimer = 0.0;
  this->mOpenFiredWithHostage = 0;
}

// File Line: 171
// RVA: 0x3F9B20
void __fastcall UFG::EncounterUnitContext::Update(UFG::EncounterUnitContext *this, UFG::SimObject *pSimObject, float deltaTime)
{
  UFG::SimObjectGame *v3; // rbp
  UFG::EncounterUnitContext *v4; // rdi
  char v5; // si
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::CharacterOccupantComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  bool v10; // bl
  unsigned __int16 v11; // dx
  UFG::PhysicsMoverInterface *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::SimObjectGame *v16; // rcx
  UFG::SimComponent *v17; // rbx
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  char v20; // al
  bool v21; // r14
  bool v22; // si
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  unsigned __int64 v25; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v26; // rcx
  const char *v27; // rax
  UFG::qReflectObject *v28; // rax
  float v29; // xmm7_4
  char v30; // [rsp+28h] [rbp-60h]
  float v31; // [rsp+30h] [rbp-58h]
  UFG::qReflectHandleBase v32; // [rsp+38h] [rbp-50h]

  v3 = (UFG::SimObjectGame *)pSimObject;
  v4 = this;
  v5 = 0;
  if ( pSimObject != this->mpSimObject )
  {
    this->mpVehicle = 0i64;
    this->mWaterContextTimer = 0.0;
    *(_DWORD *)&this->mIsOnFootRaw = 16777217;
    *(_WORD *)&this->mIsOnMeshHeuristic = 1;
    this->mOpenFiredWithHostage = 0;
    this->mpSimObject = pSimObject;
    v5 = 1;
  }
  v6 = (UFG::SimObjectGame *)this->mpSimObject;
  if ( v6
    && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID))) : (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID))) : (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID))) : (v8 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent),
        v8) )
  {
    v4->mpVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v8);
  }
  else
  {
    v4->mpVehicle = 0i64;
  }
  v9 = (UFG::SimObjectGame *)v4->mpVehicle;
  v4->mIsOnFootRaw = v9 == 0i64;
  v10 = 1;
  if ( v5 )
  {
    v10 = v9 == 0i64;
    goto LABEL_32;
  }
  if ( v4->mIsOnFootHeuristic )
  {
    if ( !v9 )
      goto LABEL_32;
    v11 = v9->m_Flags;
    if ( (v11 >> 14) & 1 )
      goto LABEL_32;
    if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        goto LABEL_32;
      if ( (v11 >> 12) & 1 )
        v12 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v9,
                                              UFG::PhysicsMoverInterface::_TypeUID);
      else
        v12 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v9->vfptr,
                                              UFG::PhysicsMoverInterface::_TypeUID);
    }
    else
    {
      v12 = (UFG::PhysicsMoverInterface *)v9->m_Components.p[34].m_pComponent;
    }
    if ( v12 && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v12) > 20.0 )
      v10 = 0;
  }
  else
  {
    v10 = 1;
    if ( v9 )
      v10 = 0;
  }
LABEL_32:
  v4->mIsOnFootHeuristic = v10;
  if ( v10
    && (v13 = (UFG::SimObjectGame *)v4->mpSimObject) != 0i64
    && ((v14 = v13->m_Flags, !((v14 >> 14) & 1)) ? ((v14 & 0x8000u) == 0 ? (!((v14 >> 13) & 1) ? (!((v14 >> 12) & 1) ? (v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::CharacterPhysicsComponent::_TypeUID)) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::CharacterPhysicsComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::CharacterPhysicsComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::CharacterPhysicsComponent::_TypeUID))) : (v15 = v13->m_Components.p[27].m_pComponent),
        v15) )
  {
    if ( v15[6].m_NameUID & 2 )
    {
      v16 = (UFG::SimObjectGame *)v4->mpSimObject;
      if ( v4->mpSimObject )
      {
        v18 = v16->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v17 = v16->m_Components.p[36].m_pComponent;
        }
        else
        {
          if ( (v18 & 0x8000u) == 0 )
          {
            if ( (v18 >> 13) & 1 )
            {
              v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::NavComponent::_TypeUID);
            }
            else if ( (v18 >> 12) & 1 )
            {
              v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::NavComponent::_TypeUID);
            }
            else
            {
              v19 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::NavComponent::_TypeUID);
            }
          }
          else
          {
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::NavComponent::_TypeUID);
          }
          v17 = v19;
        }
      }
      else
      {
        v17 = 0i64;
      }
      v20 = ((__int64 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v17[1].m_SafePointerList.mNode.mNext[1].mNext)(&v17[1].m_SafePointerList.mNode.mNext);
      if ( v20 )
      {
        ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **, char *))v17[1].m_SafePointerList.mNode.mNext[2].mNext)(
          &v17[1].m_SafePointerList.mNode.mNext,
          &v30);
        v20 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v31 - *(float *)&v17[1].m_Flags) & _xmm) < 0.30000001;
      }
      v4->mIsOnMeshHeuristic = v20;
    }
    else if ( UFG::CharacterPhysicsComponent::IsInWater((UFG::CharacterPhysicsComponent *)v15) )
    {
      v4->mIsOnMeshHeuristic = 0;
    }
  }
  else
  {
    v4->mIsOnMeshHeuristic = 1;
  }
  UFG::UIHKScreenHud::getInstance();
  v4->mIsInsideInterior = UFG::UIHKScreenHud::mInteriorManager->mActiveInterior != 0;
  v4->mIsInsideInterior |= UFG::GeographicalLayerManager::GetActiveCategory()->mUID != -1;
  v21 = v4->mIsInWater;
  v22 = UFG::SimObjectUtility::IsInWater(v4->mpSimObject);
  if ( !v22 && v3 )
  {
    v23 = v3->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v24 = v3->m_Components.p[27].m_pComponent;
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      else
        v24 = (v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v24 )
    {
      v25 = (unsigned __int64)v24[6].m_SafePointerList.mNode.mPrev;
      UFG::qReflectHandleBase::qReflectHandleBase(&v32);
      v27 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v26);
      v32.mTypeUID = UFG::qStringHash64(v27, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v32, v32.mTypeUID, v25);
      v28 = v32.mData;
      if ( !v32.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v32);
        v28 = v32.mData;
      }
      if ( HIDWORD(v28[4].mBaseNode.mParent) == 1015345352 )
        v22 = 1;
      UFG::qReflectHandleBase::~qReflectHandleBase(&v32);
    }
  }
  if ( v4->mIsInsideInterior )
    v4->mIsOnFootHeuristic = 1;
  if ( v21 != v22 )
  {
    v29 = deltaTime + v4->mWaterContextTimer;
    v4->mWaterContextTimer = v29;
    if ( v29 <= 1.0 )
      return;
    v4->mIsInWater = v22;
  }
  v4->mWaterContextTimer = 0.0;
}
  if ( v21 != v22 )
  {
    v29 = deltaTime

