// File Line: 11
// RVA: 0x3F6100
__int64 __fastcall UFG::qReflectInventory<UFG::PartDefinition>::GetClassSize(
        UFG::qReflectInventory<UFG::PartDefinition> *this)
{
  return 224i64;
}

// File Line: 28
// RVA: 0x3F2560
void __fastcall UFG::EncounterUnitComponent::EncounterUnitComponent(
        UFG::EncounterUnitComponent *this,
        unsigned int name_uid)
{
  UFG::SimComponent::SimComponent(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::EncounterUnitComponent::`vftable;
  this->mRole = eENCOUNTER_ROLE_NONE;
  this->mpEncounter.mPrev = &this->mpEncounter;
  this->mpEncounter.mNext = &this->mpEncounter;
  this->mpEncounter.m_BindCallback.m_Closure.m_pthis = 0i64;
  this->mpEncounter.m_BindCallback.m_Closure.m_pFunction = 0i64;
  this->mpEncounter.m_UnbindCallback.m_Closure.m_pthis = 0i64;
  this->mpEncounter.m_UnbindCallback.m_Closure.m_pFunction = 0i64;
  this->mpEncounter.m_pPointer = 0i64;
  this->mpEncounter.m_Changed = 0;
  this->mWaveType.mUID = -1;
  *(_DWORD *)&this->mWaveTypeGroupIndex = 255;
  this->mEnableKillCount = 1;
  this->mInsideRadiusTimer = -1.0;
  *(_QWORD *)&this->mAcquiredTimer = 0i64;
  this->mGroupVehicle.mPrev = &this->mGroupVehicle;
  this->mGroupVehicle.mNext = &this->mGroupVehicle;
  this->mGroupVehicle.m_pPointer = 0i64;
  this->mpObjectiveIndicator = 0i64;
  this->mContext.mpSimObject = 0i64;
  this->mContext.mpVehicle = 0i64;
  this->mContext.mWaterContextTimer = 0.0;
  *(_DWORD *)&this->mContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&this->mContext.mIsOnMeshHeuristic = 1;
  this->mContext.mOpenFiredWithHostage = 0;
  UFG::SimComponent::AddType(
    this,
    UFG::EncounterUnitComponent::_EncounterUnitComponentTypeUID,
    "EncounterUnitComponent");
  this->mpEncounter.m_UnbindCallback.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::EncounterUnitComponent::EncounterGoingNull;
  this->mpEncounter.m_UnbindCallback.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
}

// File Line: 38
// RVA: 0x3F29F0
void __fastcall UFG::EncounterUnitComponent::~EncounterUnitComponent(UFG::EncounterUnitComponent *this)
{
  UFG::ObjectiveIndicator *mpObjectiveIndicator; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mGroupVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::EncounterUnitComponent::`vftable;
  mpObjectiveIndicator = this->mpObjectiveIndicator;
  if ( mpObjectiveIndicator )
  {
    mpObjectiveIndicator->vfptr->__vecDelDtor(mpObjectiveIndicator, 1u);
    this->mpObjectiveIndicator = 0i64;
  }
  p_mGroupVehicle = &this->mGroupVehicle;
  if ( this->mGroupVehicle.m_pPointer )
  {
    mPrev = p_mGroupVehicle->mPrev;
    mNext = this->mGroupVehicle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mGroupVehicle->mPrev = p_mGroupVehicle;
    this->mGroupVehicle.mNext = &this->mGroupVehicle;
  }
  this->mGroupVehicle.m_pPointer = 0i64;
  v6 = p_mGroupVehicle->mPrev;
  v7 = this->mGroupVehicle.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_mGroupVehicle->mPrev = p_mGroupVehicle;
  this->mGroupVehicle.mNext = &this->mGroupVehicle;
  UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>::~qSafePointerWithCallbacksBase<UFG::EncounterBase>(&this->mpEncounter);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 47
// RVA: 0x3F3AD0
void __fastcall UFG::EncounterUnitComponent::EncounterGoingNull(
        UFG::EncounterUnitComponent *this,
        UFG::EncounterBase *e)
{
  UFG::qPrintf("whos fucking with this! %p\n", e);
}

// File Line: 53
// RVA: 0x3F2E90
void __fastcall UFG::EncounterUnitComponent::AcquireBy(
        UFG::EncounterUnitComponent *this,
        UFG::EncounterBase *pEncounter,
        UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterBase *m_pPointer; // rcx

  if ( this->mpEncounter.m_pPointer != pEncounter )
    this->mAcquiredTimer = 0.0;
  ++this->mUsageCount;
  this->mEngaged = 0;
  this->mEnableKillCount = 1;
  this->mVehicleFlipTimer = 0.0;
  this->mInsideRadiusTimer = -1.0;
  UFG::qSafePointerWithCallbacks<UFG::SimObject,UFG::SimObjectVehicle>::Set(&this->mpEncounter, pEncounter);
  m_pPointer = this->mpEncounter.m_pPointer;
  this->mRole = eENCOUNTER_ROLE_NONE;
  this->mWaveType.mUID = *(_DWORD *)((__int64 (__fastcall *)(UFG::EncounterBase *))m_pPointer->vfptr[26].__vecDelDtor)(m_pPointer);
  if ( pGroupPropertySet )
    this->mWaveTypeGroupIndex = (char)this->mpEncounter.m_pPointer->vfptr[29].__vecDelDtor(
                                        this->mpEncounter.m_pPointer,
                                        pGroupPropertySet);
  else
    this->mWaveTypeGroupIndex = -1;
  UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(this);
  this->mContext.mpSimObject = 0i64;
  this->mContext.mpVehicle = 0i64;
  this->mContext.mWaterContextTimer = 0.0;
  this->mContext.mOpenFiredWithHostage = 0;
  *(_DWORD *)&this->mContext.mIsOnFootRaw = 16777217;
  *(_WORD *)&this->mContext.mIsOnMeshHeuristic = 1;
}

// File Line: 87
// RVA: 0x3F8EF0
void __fastcall UFG::EncounterUnitComponent::ReleaseByEncounter(UFG::EncounterUnitComponent *this)
{
  UFG::qSafePointerWithCallbacks<UFG::EncounterBase,UFG::EncounterBase> *p_mpEncounter; // r8
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::EncounterBase>,UFG::qSafePointerNodeList> *mNext; // rax

  --this->mUsageCount;
  p_mpEncounter = &this->mpEncounter;
  this->mEngaged = 0;
  this->mAcquiredTimer = 0.0;
  this->mInsideRadiusTimer = -1.0;
  if ( this->mpEncounter.m_pPointer )
  {
    mPrev = p_mpEncounter->mPrev;
    mNext = this->mpEncounter.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpEncounter->mPrev = p_mpEncounter;
    this->mpEncounter.mNext = &this->mpEncounter;
    this->mpEncounter.m_Changed = 1;
  }
  this->mpEncounter.m_pPointer = 0i64;
  this->mRole = eENCOUNTER_ROLE_NONE;
  this->mWaveType = UFG::gNullQSymbol;
  this->mWaveTypeGroupIndex = -1;
  UFG::EncounterUnitComponent::DecrementGroupVehicleUsageCount(this);
}

// File Line: 108
// RVA: 0x3F7BC0
void __fastcall UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(UFG::EncounterUnitComponent *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mGroupVehicle.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::EncounterUnitComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::EncounterUnitComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    }
    if ( m_pComponent )
      ++BYTE5(m_pComponent[2].m_SafePointerList.mNode.mPrev);
  }
}

// File Line: 118
// RVA: 0x3F39F0
void __fastcall UFG::EncounterUnitComponent::DecrementGroupVehicleUsageCount(UFG::EncounterUnitComponent *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mGroupVehicle.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::EncounterUnitComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::EncounterUnitComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    }
    if ( m_pComponent )
      --BYTE5(m_pComponent[2].m_SafePointerList.mNode.mPrev);
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
  UFG::SimObject *m_pSimObject; // rcx
  UFG::EncounterBase *m_pPointer; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Encounters,
    OUTPUT_LEVEL_DEBUG,
    "[EncounterUnitComponent]: OnDetach (%s)\n");
  m_pPointer = this->mpEncounter.m_pPointer;
  if ( m_pPointer )
  {
    m_pPointer->vfptr[24].__vecDelDtor(m_pPointer, (unsigned int)this);
    UFG::EncounterUnitComponent::ReleaseByEncounter(this);
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
void __fastcall UFG::EncounterUnitContext::Update(
        UFG::EncounterUnitContext *this,
        UFG::SimObjectGame *pSimObject,
        float deltaTime)
{
  char v5; // si
  UFG::SimObjectGame *mpSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObjectGame *mpVehicle; // rcx
  bool v10; // bl
  __int16 v11; // dx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::SimObjectGame *v16; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  char v20; // al
  char mIsInWater; // r14
  char v22; // si
  signed __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  unsigned __int64 mPrev; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v26; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  float v29; // xmm7_4
  char v30[8]; // [rsp+28h] [rbp-60h] BYREF
  float v31; // [rsp+30h] [rbp-58h]
  UFG::qReflectHandleBase v32; // [rsp+38h] [rbp-50h] BYREF

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
  mpSimObject = (UFG::SimObjectGame *)this->mpSimObject;
  if ( mpSimObject
    && ((m_Flags = mpSimObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 mpSimObject,
                                                                 UFG::CharacterOccupantComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 mpSimObject,
                                                                 UFG::CharacterOccupantComponent::_TypeUID)))
      : (ComponentOfType = (UFG::CharacterOccupantComponent *)mpSimObject->m_Components.p[44].m_pComponent),
        ComponentOfType) )
  {
    this->mpVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType);
  }
  else
  {
    this->mpVehicle = 0i64;
  }
  mpVehicle = (UFG::SimObjectGame *)this->mpVehicle;
  this->mIsOnFootRaw = mpVehicle == 0i64;
  v10 = 1;
  if ( v5 )
  {
    v10 = mpVehicle == 0i64;
    goto LABEL_30;
  }
  if ( this->mIsOnFootHeuristic )
  {
    if ( !mpVehicle )
      goto LABEL_30;
    v11 = mpVehicle->m_Flags;
    if ( (v11 & 0x4000) != 0 )
      goto LABEL_30;
    if ( v11 >= 0 )
    {
      if ( (v11 & 0x2000) != 0 )
        goto LABEL_30;
      if ( (v11 & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            mpVehicle,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                            mpVehicle,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)mpVehicle->m_Components.p[34].m_pComponent;
    }
    if ( ComponentOfTypeHK && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(ComponentOfTypeHK) > 20.0 )
      v10 = 0;
  }
  else
  {
    v10 = mpVehicle == 0i64;
  }
LABEL_30:
  this->mIsOnFootHeuristic = v10;
  if ( v10
    && (v13 = (UFG::SimObjectGame *)this->mpSimObject) != 0i64
    && ((v14 = v13->m_Flags, (v14 & 0x4000) == 0)
      ? (v14 >= 0 && (v14 & 0x2000) == 0 && (v14 & 0x1000) == 0
       ? (v15 = UFG::SimObject::GetComponentOfType(v13, UFG::CharacterPhysicsComponent::_TypeUID))
       : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::CharacterPhysicsComponent::_TypeUID)))
      : (v15 = v13->m_Components.p[27].m_pComponent),
        v15) )
  {
    if ( (v15[6].m_NameUID & 2) != 0 )
    {
      v16 = (UFG::SimObjectGame *)this->mpSimObject;
      if ( this->mpSimObject )
      {
        v18 = v16->m_Flags;
        if ( (v18 & 0x4000) != 0 )
        {
          m_pComponent = v16->m_Components.p[36].m_pComponent;
        }
        else
        {
          if ( v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::NavComponent::_TypeUID);
          else
            v19 = UFG::SimObject::GetComponentOfType(v16, UFG::NavComponent::_TypeUID);
          m_pComponent = v19;
        }
      }
      else
      {
        m_pComponent = 0i64;
      }
      v20 = ((__int64 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))m_pComponent[1].m_SafePointerList.mNode.mNext[1].mNext)(&m_pComponent[1].m_SafePointerList.mNode.mNext);
      if ( v20 )
      {
        ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **, char *))m_pComponent[1].m_SafePointerList.mNode.mNext[2].mNext)(
          &m_pComponent[1].m_SafePointerList.mNode.mNext,
          v30);
        v20 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v31 - *(float *)&m_pComponent[1].m_Flags) & _xmm) < 0.30000001;
      }
      this->mIsOnMeshHeuristic = v20;
    }
    else if ( UFG::CharacterPhysicsComponent::IsInWater((UFG::CharacterPhysicsComponent *)v15) )
    {
      this->mIsOnMeshHeuristic = 0;
    }
  }
  else
  {
    this->mIsOnMeshHeuristic = 1;
  }
  UFG::UIHKScreenHud::getInstance();
  this->mIsInsideInterior = UFG::UIHKScreenHud::mInteriorManager->mActiveInterior != INTERIOR_NONE;
  this->mIsInsideInterior |= UFG::GeographicalLayerManager::GetActiveCategory()->mUID != -1;
  mIsInWater = this->mIsInWater;
  v22 = UFG::SimObjectUtility::IsInWater(this->mpSimObject);
  if ( !v22 && pSimObject )
  {
    v23 = pSimObject->m_Flags;
    if ( (v23 & 0x4000) != 0 )
      v24 = pSimObject->m_Components.p[27].m_pComponent;
    else
      v24 = v23 < 0 || (v23 & 0x2000) != 0 || (v23 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::CharacterPhysicsComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(pSimObject, UFG::CharacterPhysicsComponent::_TypeUID);
    if ( v24 )
    {
      mPrev = (unsigned __int64)v24[6].m_SafePointerList.mNode.mPrev;
      UFG::qReflectHandleBase::qReflectHandleBase(&v32);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v26);
      v32.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v32, v32.mTypeUID, mPrev);
      mData = v32.mData;
      if ( !v32.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v32);
        mData = v32.mData;
      }
      if ( HIDWORD(mData[4].mBaseNode.mParent) == 1015345352 )
        v22 = 1;
      UFG::qReflectHandleBase::~qReflectHandleBase(&v32);
    }
  }
  if ( this->mIsInsideInterior )
    this->mIsOnFootHeuristic = 1;
  if ( mIsInWater != v22 )
  {
    v29 = deltaTime + this->mWaterContextTimer;
    this->mWaterContextTimer = v29;
    if ( v29 <= 1.0 )
      return;
    this->mIsInWater = v22;
  }
  this->mWaterContextTimer = 0.0;
}

