// File Line: 28
// RVA: 0x1543F80
__int64 dynamic_initializer_for__UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList__);
}

// File Line: 29
// RVA: 0x52CAA0
UFG::ComponentIDDesc *__fastcall UFG::MissionFailConditionComponent::GetDesc(UFG::MissionFailConditionComponent *this)
{
  return &UFG::MissionFailConditionComponent::_TypeIDesc;
}

// File Line: 49
// RVA: 0x518370
void __fastcall UFG::MissionFailConditionComponent::MissionFailConditionComponent(
        UFG::MissionFailConditionComponent *this,
        unsigned int name_uid,
        component_MissionFailCondition *dataPtr)
{
  const char *v5; // rsi
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *mPrev; // rax
  __int64 mOffset; // rax
  const char *v8; // rdx
  __int64 v9; // rax
  const char *v10; // rdx
  __int64 v11; // rax
  const char *v12; // rdx
  __int64 v13; // rax
  const char *v14; // rdx
  __int64 v15; // rax
  const char *v16; // rdx
  __int64 v17; // rax
  const char *v18; // rdx
  __int64 v19; // rax
  const char *v20; // rdx
  __int64 v21; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent>;
  this->mNext = &this->UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MissionFailConditionComponent::`vftable;
  v5 = 0i64;
  this->mpDistanceFailObject = 0i64;
  this->mpCustomGameSlice = 0i64;
  *(_WORD *)&this->mIsPanicking = 0;
  *(_QWORD *)&this->mVehicleFlippedTimer = 0i64;
  *(_QWORD *)&this->mDamageHealthThreshold = 0i64;
  *(_QWORD *)&this->mArrestFailTrigger = 0i64;
  UFG::qSharedString::qSharedString(&this->mArrestFailCaption);
  UFG::qSharedString::qSharedString(&this->mDeathFailCaption);
  UFG::qSharedString::qSharedString(&this->mDamageFailCaption);
  UFG::qSharedString::qSharedString(&this->mDistanceFailCaption);
  UFG::qSharedString::qSharedString(&this->mPanicWeaponFailCaption);
  UFG::qSharedString::qSharedString(&this->mPanicVehicleFailCaption);
  UFG::qSharedString::qSharedString(&this->mVehicleFlipFailCaption);
  UFG::qSharedString::qSharedString(&this->mBoatStuckFailCaption);
  mPrev = UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mPrev;
  UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)&UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList;
  UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mPrev = &this->UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::MissionFailConditionComponent::_MissionFailConditionComponentTypeUID,
    "MissionFailConditionComponent");
  if ( dataPtr )
  {
    this->mArrestFailTrigger = dataPtr->ArrestFailTrigger;
    this->mDeathFailTrigger = dataPtr->DeathFailTrigger;
    this->mDamageFailTrigger = dataPtr->DamageFailTrigger;
    this->mDistanceFailTrigger = dataPtr->DistanceFailTrigger;
    this->mPanicWeaponFailTrigger = dataPtr->PanicWeaponFailTrigger;
    this->mPanicVehicleFailTrigger = dataPtr->PanicVehicleFailTrigger;
    this->mVehicleFlipFailTrigger = dataPtr->VehicleFlipFailTrigger;
    this->mBoatStuckFailTrigger = dataPtr->BoatStuckFailTrigger;
    this->mDamageHealthThreshold = dataPtr->DamageHealthThreshold;
    this->mDistanceFailThreshold = dataPtr->DistanceFailThreshold;
    mOffset = dataPtr->ArrestFailCaption.mOffset;
    if ( mOffset )
      v8 = (char *)&dataPtr->ArrestFailCaption + mOffset;
    else
      v8 = 0i64;
    UFG::qSharedString::operator=(&this->mArrestFailCaption, v8);
    v9 = dataPtr->DeathFailCaption.mOffset;
    if ( v9 )
      v10 = (char *)&dataPtr->DeathFailCaption + v9;
    else
      v10 = 0i64;
    UFG::qSharedString::operator=(&this->mDeathFailCaption, v10);
    v11 = dataPtr->DamageFailCaption.mOffset;
    if ( v11 )
      v12 = (char *)&dataPtr->DamageFailCaption + v11;
    else
      v12 = 0i64;
    UFG::qSharedString::operator=(&this->mDamageFailCaption, v12);
    v13 = dataPtr->DistanceFailCaption.mOffset;
    if ( v13 )
      v14 = (char *)&dataPtr->DistanceFailCaption + v13;
    else
      v14 = 0i64;
    UFG::qSharedString::operator=(&this->mDistanceFailCaption, v14);
    v15 = dataPtr->PanicWeaponFailCaption.mOffset;
    if ( v15 )
      v16 = (char *)&dataPtr->PanicWeaponFailCaption + v15;
    else
      v16 = 0i64;
    UFG::qSharedString::operator=(&this->mPanicWeaponFailCaption, v16);
    v17 = dataPtr->PanicVehicleFailCaption.mOffset;
    if ( v17 )
      v18 = (char *)&dataPtr->PanicVehicleFailCaption + v17;
    else
      v18 = 0i64;
    UFG::qSharedString::operator=(&this->mPanicVehicleFailCaption, v18);
    v19 = dataPtr->VehicleFlipFailCaption.mOffset;
    if ( v19 )
      v20 = (char *)&dataPtr->VehicleFlipFailCaption + v19;
    else
      v20 = 0i64;
    UFG::qSharedString::operator=(&this->mVehicleFlipFailCaption, v20);
    v21 = dataPtr->BoatStuckFailCaption.mOffset;
    if ( v21 )
      v5 = (char *)&dataPtr->BoatStuckFailCaption + v21;
    UFG::qSharedString::operator=(&this->mBoatStuckFailCaption, v5);
  }
}

// File Line: 81
// RVA: 0x51C0C0
void __fastcall UFG::MissionFailConditionComponent::~MissionFailConditionComponent(
        UFG::MissionFailConditionComponent *this)
{
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v2; // rbx
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *mPrev; // rcx
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *mNext; // rax
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v5; // rcx
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MissionFailConditionComponent::`vftable;
  if ( this == UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator )
    UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator = (UFG::MissionFailConditionComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qSharedString::~qSharedString(&this->mBoatStuckFailCaption);
  UFG::qSharedString::~qSharedString(&this->mVehicleFlipFailCaption);
  UFG::qSharedString::~qSharedString(&this->mPanicVehicleFailCaption);
  UFG::qSharedString::~qSharedString(&this->mPanicWeaponFailCaption);
  UFG::qSharedString::~qSharedString(&this->mDistanceFailCaption);
  UFG::qSharedString::~qSharedString(&this->mDamageFailCaption);
  UFG::qSharedString::~qSharedString(&this->mDeathFailCaption);
  UFG::qSharedString::~qSharedString(&this->mArrestFailCaption);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 87
// RVA: 0x53E580
void __fastcall UFG::MissionFailConditionComponent::OnAttach(
        UFG::MissionFailConditionComponent *this,
        UFG::SimObject *pObject)
{
  this->mIsPanicking = 0;
  *(_QWORD *)&this->mVehicleFlippedTimer = 0i64;
  if ( this->mDistanceFailTrigger )
    UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(this, 1);
}

// File Line: 92
// RVA: 0x540AD0
void __fastcall UFG::MissionFailConditionComponent::OnDetach(UFG::MissionFailConditionComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax

  m_pSimObject = this->m_pSimObject;
  if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0) && this->mIsDistanceFailTriggerEnabled )
  {
    UFG::SceneObjectProperties::Deactivate(this->mpDistanceFailObject);
    this->mpDistanceFailObject = 0i64;
    this->mIsDistanceFailTriggerEnabled = 0;
  }
}

// File Line: 116
// RVA: 0x5269A0
void __fastcall UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(
        UFG::MissionFailConditionComponent *this,
        bool enable)
{
  UFG::SimObject *m_pSimObject; // r8
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::SimObjectCharacter *LocalPlayer; // r14
  UFG::SimObject *v7; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  char *v9; // rax
  UFG::SceneObjectProperties *v10; // rax
  UFG::qPropertySet *WritableProperties; // rax
  UFG::qPropertySet *appended; // rbx
  UFG::SimObject *v13; // rbx
  UFG::TransformNodeComponent *v14; // rcx
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *p; // rbx
  __int64 v19; // rdx
  UFG::TriggerRegion *m_pComponent; // rbx
  unsigned int v21; // r8d
  unsigned int v22; // r10d
  unsigned int v23; // r8d
  unsigned int v24; // r10d
  unsigned int v25; // r8d
  unsigned int v26; // r10d
  hkSeekableStreamReader *RCX; // rax
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol objName; // [rsp+70h] [rbp+8h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0) && enable != this->mIsDistanceFailTriggerEnabled )
  {
    if ( m_pSimObject )
      m_pSceneObj = m_pSimObject->m_pSceneObj;
    else
      m_pSceneObj = 0i64;
    if ( !enable || !m_pSceneObj )
    {
      UFG::SceneObjectProperties::Deactivate(this->mpDistanceFailObject);
      this->mpDistanceFailObject = 0i64;
      goto LABEL_51;
    }
    LocalPlayer = UFG::GetLocalPlayer();
    v7 = this->m_pSimObject;
    m_pTransformNodeComponent = 0i64;
    if ( v7 )
      m_pTransformNodeComponent = v7->m_pTransformNodeComponent;
    if ( (_S27_1 & 1) == 0 )
    {
      _S27_1 |= 1u;
      UFG::qSymbol::create_from_string(&triggerPropertySetSymbol, "object-logical-TriggerRegion");
      atexit(UFG::MissionFailConditionComponent::EnableDistanceFailTrigger_::_10_::_dynamic_atexit_destructor_for__triggerPropertySetSymbol__);
    }
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qString::FormatEx(&result, "%s_fdtrigger", v9);
    UFG::qSymbol::create_from_string(&objName, result.mData);
    v10 = UFG::SceneObjectProperties::Create(&objName, 0i64, &triggerPropertySetSymbol);
    this->mpDistanceFailObject = v10;
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(v10);
    appended = UFG::RegionComponent::PropertiesAppendDefaultProperty(WritableProperties);
    UFG::qPropertySet::Set<unsigned long>(appended, (UFG::qArray<unsigned long,0> *)&SimSym_Type, 2u);
    UFG::qPropertySet::Set<float>(
      appended,
      (UFG::qArray<unsigned long,0> *)&SimSym_Radius,
      this->mDistanceFailThreshold);
    UFG::SceneObjectProperties::Activate(this->mpDistanceFailObject, 1u, 0i64, 0i64);
    v13 = this->mpDistanceFailObject->m_pSimObject;
    if ( !v13 )
    {
LABEL_49:
      UFG::qString::~qString(&result);
LABEL_51:
      this->mIsDistanceFailTriggerEnabled = enable;
      return;
    }
    v14 = v13->m_pTransformNodeComponent;
    if ( v14 )
      UFG::TransformNodeComponent::SetParent(v14, m_pTransformNodeComponent, eInheritXform_Full);
    m_Flags = v13->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      vfptr = (unsigned int)v13[1].vfptr;
      size = v13->m_Components.size;
      if ( vfptr < size )
      {
        p = v13->m_Components.p;
        while ( 1 )
        {
          v19 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && (UFG::TriggerRegion::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_24;
        }
LABEL_23:
        m_pComponent = (UFG::TriggerRegion *)p[v19].m_pComponent;
        goto LABEL_47;
      }
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v23 = (unsigned int)v13[1].vfptr;
        v24 = v13->m_Components.size;
        if ( v23 < v24 )
        {
          p = v13->m_Components.p;
          do
          {
            v19 = v23;
            if ( (p[v23].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && (UFG::TriggerRegion::_TypeUID & ~p[v23].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_23;
            }
          }
          while ( ++v23 < v24 );
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = (UFG::TriggerRegion *)UFG::SimObject::GetComponentOfType(v13, UFG::TriggerRegion::_TypeUID);
LABEL_47:
          if ( m_pComponent )
          {
            UFG::TriggerRegion::TrackTarget(m_pComponent, LocalPlayer, 0i64);
            RCX = Assembly::GetRCX(this);
            m_pComponent->mOnExitedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::MissionFailConditionComponent::OnExitTrigger;
            m_pComponent->mOnExitedDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)RCX;
            UFG::TriggerRegion::EnableHot(m_pComponent, 1);
          }
          goto LABEL_49;
        }
        v25 = (unsigned int)v13[1].vfptr;
        v26 = v13->m_Components.size;
        if ( v25 < v26 )
        {
          p = v13->m_Components.p;
          do
          {
            v19 = v25;
            if ( (p[v25].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && (UFG::TriggerRegion::_TypeUID & ~p[v25].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_23;
            }
          }
          while ( ++v25 < v26 );
        }
      }
    }
    else
    {
      v21 = (unsigned int)v13[1].vfptr;
      v22 = v13->m_Components.size;
      if ( v21 < v22 )
      {
        p = v13->m_Components.p;
        do
        {
          v19 = v21;
          if ( (p[v21].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && (UFG::TriggerRegion::_TypeUID & ~p[v21].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_23;
          }
        }
        while ( ++v21 < v22 );
      }
    }
LABEL_24:
    m_pComponent = 0i64;
    goto LABEL_47;
  }
}

// File Line: 179
// RVA: 0x527C70
void __fastcall UFG::MissionFailConditionComponent::FailObject(
        UFG::SimObjectGame *simObject,
        UFG::qSymbol *captionType)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  component_MissionFailCondition *MemImagePtr; // rax
  const char *v7; // rdx
  unsigned int mUID; // ecx
  __int64 mOffset; // rcx
  UFG::qOffset64<char *> *p_DeathFailCaption; // rdx
  UFG::ProgressionTracker *v11; // rax
  UFG::qString caption; // [rsp+28h] [rbp-30h] BYREF

  m_pSceneObj = simObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  MemImagePtr = (component_MissionFailCondition *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                                    mpWritableProperties,
                                                    (UFG::qArray<unsigned long,0> *)&component_MissionFailCondition::sPropertyName,
                                                    DEPTH_RECURSE);
  if ( MemImagePtr )
    MemImagePtr = (component_MissionFailCondition *)UFG::qPropertySet::GetMemImagePtr((UFG::qPropertySet *)MemImagePtr);
  v7 = &customCaption;
  mUID = captionType->mUID;
  if ( captionType->mUID != qSymbol_ArrestFailCaption.mUID )
  {
    if ( mUID == qSymbol_DeathFailCaption.mUID )
    {
      mOffset = MemImagePtr->DeathFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->DeathFailCaption;
        goto LABEL_29;
      }
    }
    else if ( mUID == qSymbol_DamageFailCaption.mUID )
    {
      mOffset = MemImagePtr->DamageFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->DamageFailCaption;
        goto LABEL_29;
      }
    }
    else if ( mUID == qSymbol_DistanceFailCaption.mUID )
    {
      mOffset = MemImagePtr->DistanceFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->DistanceFailCaption;
        goto LABEL_29;
      }
    }
    else if ( mUID == qSymbol_PanicWeaponFailCaption.mUID )
    {
      mOffset = MemImagePtr->PanicWeaponFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->PanicWeaponFailCaption;
        goto LABEL_29;
      }
    }
    else if ( mUID == qSymbol_PanicVehicleFailCaption.mUID )
    {
      mOffset = MemImagePtr->PanicVehicleFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->PanicVehicleFailCaption;
        goto LABEL_29;
      }
    }
    else if ( mUID == qSymbol_VehicleFlipFailCaption.mUID )
    {
      mOffset = MemImagePtr->VehicleFlipFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->VehicleFlipFailCaption;
        goto LABEL_29;
      }
    }
    else
    {
      if ( mUID != qSymbol_BoatStuckFailCaption.mUID )
      {
LABEL_31:
        UFG::qString::qString(&caption, v7);
        goto LABEL_32;
      }
      mOffset = MemImagePtr->BoatStuckFailCaption.mOffset;
      if ( mOffset )
      {
        p_DeathFailCaption = &MemImagePtr->BoatStuckFailCaption;
        goto LABEL_29;
      }
    }
LABEL_30:
    v7 = 0i64;
    goto LABEL_31;
  }
  mOffset = MemImagePtr->ArrestFailCaption.mOffset;
  if ( !mOffset )
    goto LABEL_30;
  p_DeathFailCaption = &MemImagePtr->ArrestFailCaption;
LABEL_29:
  UFG::qString::qString(&caption, (const char *)p_DeathFailCaption + mOffset);
LABEL_32:
  v11 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::OnFailObject(v11, simObject, &caption);
  UFG::qString::~qString(&caption);
}

// File Line: 221
// RVA: 0x541CD0
void __fastcall UFG::MissionFailConditionComponent::OnExitTrigger(
        UFG::MissionFailConditionComponent *this,
        UFG::TriggerRegion *pTriggerRegion)
{
  UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(this, 0);
  UFG::MissionFailConditionComponent::FailObject((UFG::SimObjectGame *)this->m_pSimObject, &qSymbol_DistanceFailCaption);
}

// File Line: 229
// RVA: 0x55BC00
void __fastcall UFG::MissionFailConditionComponent::Update(UFG::MissionFailConditionComponent *this, float deltaTime)
{
  UFG::SimObject *m_pSimObject; // rax
  unsigned int v4; // eax
  UFG::SimObject *v5; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  bool mPanicWeaponFailTrigger; // si
  bool mPanicVehicleFailTrigger; // bp
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v12; // edx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  __int64 v16; // r8
  unsigned int v17; // edx
  unsigned int v18; // r9d
  UFG::SimObject *v19; // r8
  __int16 v20; // cx
  UFG::SimComponent *ComponentOfType; // rdi
  unsigned int v22; // ecx
  unsigned int v23; // r9d
  UFG::SimComponentHolder *v24; // r11
  __int64 v25; // rdi
  unsigned int v26; // ecx
  unsigned int v27; // r9d
  UFG::qStaticSymbol *v28; // rdx
  float v29; // xmm0_4
  float v30; // xmm7_4

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
  {
    v4 = _S28_0;
    if ( (_S28_0 & 1) == 0 )
    {
      _S28_0 |= 1u;
      UID_BeScaredOfGunPointedAtMe.mUID = UFG::qStringHashUpper32("BeScaredOfGunPointedAtMe", -1);
      v4 = _S28_0;
    }
    if ( (v4 & 2) == 0 )
    {
      _S28_0 = v4 | 2;
      UID_Cower.mUID = UFG::qStringHashUpper32("Cower", -1);
      v4 = _S28_0;
    }
    if ( (v4 & 4) == 0 )
    {
      _S28_0 = v4 | 4;
      UID_BeScaredOfGunPointedNearMe.mUID = UFG::qStringHashUpper32("BeScaredOfGunPointedNearMe", -1);
      v4 = _S28_0;
    }
    if ( (v4 & 8) == 0 )
    {
      _S28_0 = v4 | 8;
      UID_BeScaredOfDrawnWeapon.mUID = UFG::qStringHashUpper32("BeScaredOfDrawnWeapon", -1);
      v4 = _S28_0;
    }
    if ( (v4 & 0x10) == 0 )
    {
      _S28_0 = v4 | 0x10;
      UID_RunAwayFromDangerousVehicle.mUID = UFG::qStringHashUpper32("RunAwayFromDangerousVehicle", -1);
      v4 = _S28_0;
    }
    if ( (v4 & 0x20) == 0 )
    {
      _S28_0 = v4 | 0x20;
      UID_Flinch.mUID = UFG::qStringHashUpper32("Flinch", -1);
    }
    v5 = this->m_pSimObject;
    if ( v5 )
    {
      m_pSceneObj = v5->m_pSceneObj;
      if ( m_pSceneObj )
      {
        if ( m_pSceneObj->mpWritableProperties || m_pSceneObj->mpConstProperties )
        {
          if ( this->mIsPanicking )
            goto LABEL_84;
          mPanicWeaponFailTrigger = this->mPanicWeaponFailTrigger;
          mPanicVehicleFailTrigger = this->mPanicVehicleFailTrigger;
          if ( !mPanicWeaponFailTrigger && !mPanicVehicleFailTrigger )
            goto LABEL_84;
          m_Flags = v5->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = v5->m_Components.p[22].m_pComponent;
            if ( !m_pComponent )
              goto LABEL_26;
            m_TypeUID = m_pComponent->m_TypeUID;
            if ( ((m_TypeUID ^ UFG::ActiveAIEntityComponent::_TypeUID) & 0xFE000000) != 0
              || (UFG::ActiveAIEntityComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
            {
              goto LABEL_26;
            }
          }
          else
          {
            if ( m_Flags >= 0 )
            {
              if ( (m_Flags & 0x2000) != 0 )
              {
                vfptr = (unsigned int)v5[1].vfptr;
                size = v5->m_Components.size;
                if ( vfptr >= size )
                {
LABEL_26:
                  m_pComponent = 0i64;
                  goto LABEL_48;
                }
                p = v5->m_Components.p;
                while ( 1 )
                {
                  v16 = vfptr;
                  if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
                    && (UFG::ActiveAIEntityComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    break;
                  }
                  if ( ++vfptr >= size )
                    goto LABEL_26;
                }
              }
              else
              {
                if ( (m_Flags & 0x1000) == 0 )
                {
                  m_pComponent = UFG::SimObject::GetComponentOfType(v5, UFG::ActiveAIEntityComponent::_TypeUID);
                  goto LABEL_48;
                }
                v17 = (unsigned int)v5[1].vfptr;
                v18 = v5->m_Components.size;
                if ( v17 >= v18 )
                  goto LABEL_26;
                p = v5->m_Components.p;
                while ( 1 )
                {
                  v16 = v17;
                  if ( (p[v17].m_TypeUID & 0xFE000000) == (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
                    && (UFG::ActiveAIEntityComponent::_TypeUID & ~p[v17].m_TypeUID & 0x1FFFFFF) == 0 )
                  {
                    break;
                  }
                  if ( ++v17 >= v18 )
                    goto LABEL_26;
                }
              }
              m_pComponent = p[v16].m_pComponent;
              goto LABEL_48;
            }
            m_pComponent = v5->m_Components.p[22].m_pComponent;
            if ( !m_pComponent )
              goto LABEL_26;
            v12 = m_pComponent->m_TypeUID;
            if ( ((v12 ^ UFG::ActiveAIEntityComponent::_TypeUID) & 0xFE000000) != 0 )
              goto LABEL_26;
            if ( (UFG::ActiveAIEntityComponent::_TypeUID & ~v12 & 0x1FFFFFF) != 0 )
              m_pComponent = 0i64;
          }
LABEL_48:
          if ( !m_pComponent )
            goto LABEL_84;
          if ( HIDWORD(m_pComponent[64].m_BoundComponentHandles.mNode.mNext) != 1 )
            goto LABEL_84;
          v19 = this->m_pSimObject;
          if ( !v19 )
            goto LABEL_84;
          v20 = v19->m_Flags;
          if ( (v20 & 0x4000) != 0 )
          {
            ComponentOfType = v19->m_Components.p[19].m_pComponent;
            goto LABEL_72;
          }
          if ( v20 < 0 )
          {
            ComponentOfType = v19->m_Components.p[19].m_pComponent;
            goto LABEL_72;
          }
          if ( (v20 & 0x2000) != 0 )
          {
            v22 = (unsigned int)v19[1].vfptr;
            v23 = v19->m_Components.size;
            if ( v22 < v23 )
            {
              v24 = v19->m_Components.p;
              while ( 1 )
              {
                v25 = v22;
                if ( (v24[v22].m_TypeUID & 0xFE000000) == (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
                  && (UFG::AIActionTreeComponent::_TypeUID & ~v24[v22].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  break;
                }
                if ( ++v22 >= v23 )
                  goto LABEL_63;
              }
LABEL_62:
              ComponentOfType = v24[v25].m_pComponent;
              goto LABEL_72;
            }
          }
          else
          {
            if ( (v20 & 0x1000) == 0 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  this->m_pSimObject,
                                  UFG::AIActionTreeComponent::_TypeUID);
LABEL_72:
              if ( ComponentOfType )
              {
                if ( mPanicWeaponFailTrigger
                  && (ActionController::IsPlaying(
                        (ActionController *)&ComponentOfType[3].m_TypeUID,
                        &UID_BeScaredOfGunPointedAtMe,
                        0xFFFFFFFF,
                        0)
                   || ActionController::IsPlaying(
                        (ActionController *)&ComponentOfType[3].m_TypeUID,
                        &UID_Cower,
                        0xFFFFFFFF,
                        0)
                   || ActionController::IsPlaying(
                        (ActionController *)&ComponentOfType[3].m_TypeUID,
                        &UID_BeScaredOfGunPointedNearMe,
                        0xFFFFFFFF,
                        0)
                   || ActionController::IsPlaying(
                        (ActionController *)&ComponentOfType[3].m_TypeUID,
                        &UID_BeScaredOfDrawnWeapon,
                        0xFFFFFFFF,
                        0)) )
                {
                  v28 = &qSymbol_PanicWeaponFailCaption;
                }
                else
                {
                  if ( !mPanicVehicleFailTrigger
                    || !ActionController::IsPlaying(
                          (ActionController *)&ComponentOfType[3].m_TypeUID,
                          &UID_RunAwayFromDangerousVehicle,
                          0xFFFFFFFF,
                          0)
                    && !ActionController::IsPlaying(
                          (ActionController *)&ComponentOfType[3].m_TypeUID,
                          &UID_Flinch,
                          0xFFFFFFFF,
                          0) )
                  {
                    goto LABEL_84;
                  }
                  v28 = &qSymbol_PanicVehicleFailCaption;
                }
                this->mIsPanicking = 1;
                UFG::MissionFailConditionComponent::FailObject((UFG::SimObjectGame *)this->m_pSimObject, v28);
              }
LABEL_84:
              if ( this->mVehicleFlipFailTrigger
                && (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(
                                   (UFG::SimObjectVehicle *)this->m_pSimObject,
                                   0,
                                   0i64) )
              {
                v29 = deltaTime + this->mVehicleFlippedTimer;
                this->mVehicleFlippedTimer = v29;
                if ( v29 > 2.0 )
                  UFG::MissionFailConditionComponent::FailObject(
                    (UFG::SimObjectGame *)this->m_pSimObject,
                    &qSymbol_VehicleFlipFailCaption);
              }
              else
              {
                this->mVehicleFlippedTimer = 0.0;
              }
              if ( !this->mBoatStuckFailTrigger || UFG::SimObjectUtility::IsBoatInWater(this->m_pSimObject) )
              {
                this->mBoatStuckTimer = 0.0;
              }
              else
              {
                v30 = deltaTime + this->mBoatStuckTimer;
                this->mBoatStuckTimer = v30;
                if ( v30 > 2.0 )
                  UFG::MissionFailConditionComponent::FailObject(
                    (UFG::SimObjectGame *)this->m_pSimObject,
                    &qSymbol_BoatStuckFailCaption);
              }
              return;
            }
            v26 = (unsigned int)v19[1].vfptr;
            v27 = v19->m_Components.size;
            if ( v26 < v27 )
            {
              v24 = v19->m_Components.p;
              do
              {
                v25 = v26;
                if ( (v24[v26].m_TypeUID & 0xFE000000) == (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
                  && (UFG::AIActionTreeComponent::_TypeUID & ~v24[v26].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_62;
                }
              }
              while ( ++v26 < v27 );
            }
          }
LABEL_63:
          ComponentOfType = 0i64;
          goto LABEL_72;
        }
      }
    }
  }
}

// File Line: 339
// RVA: 0x546A30
UFG::MissionFailConditionComponent *__fastcall UFG::MissionFailConditionComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *MemImagePtr; // rax

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  MemImagePtr = UFG::qPropertySet::Get<UFG::qPropertySet>(
                  mpWritableProperties,
                  (UFG::qArray<unsigned long,0> *)&component_MissionFailCondition::sPropertyName,
                  DEPTH_RECURSE);
  if ( MemImagePtr )
  {
    MemImagePtr = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(MemImagePtr);
    if ( MemImagePtr )
      return UFG::MissionFailConditionComponent::HandleAttachment(
               0i64,
               pSceneObj->m_pSimObject,
               (component_MissionFailCondition *)MemImagePtr);
  }
  if ( required )
    return UFG::MissionFailConditionComponent::HandleAttachment(
             0i64,
             pSceneObj->m_pSimObject,
             (component_MissionFailCondition *)MemImagePtr);
  else
    return 0i64;
}

// File Line: 389
// RVA: 0x54CE70
void __fastcall UFG::MissionFailConditionComponent::SetFailTrigger(
        UFG::SimObject *pSimObject,
        UFG::qSymbol *triggerName,
        bool enabled)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r8d
  UFG::SimComponentHolder *p; // r11
  __int64 v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // r8d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SimComponent *v16; // rax
  signed __int16 v17; // cx
  unsigned int v18; // edi
  unsigned int mUID; // eax
  UFG::SimObjectModifier v20; // [rsp+38h] [rbp-40h] BYREF

  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        p = pSimObject->m_Components.p;
        while ( 1 )
        {
          v11 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && (UFG::MissionFailConditionComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_14;
        }
LABEL_13:
        m_pComponent = p[v11].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_23:
        if ( m_pComponent )
          goto LABEL_34;
        goto LABEL_24;
      }
      v12 = (unsigned int)pSimObject[1].vfptr;
      v13 = pSimObject->m_Components.size;
      if ( v12 < v13 )
      {
        p = pSimObject->m_Components.p;
        do
        {
          v11 = v12;
          if ( (p[v12].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && (UFG::MissionFailConditionComponent::_TypeUID & ~p[v12].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_13;
          }
        }
        while ( ++v12 < v13 );
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
LABEL_24:
  if ( !enabled )
    return;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v15 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
  if ( v15 )
  {
    UFG::MissionFailConditionComponent::MissionFailConditionComponent(
      (UFG::MissionFailConditionComponent *)v15,
      pSimObject->mNode.mUID,
      0i64);
    m_pComponent = v16;
  }
  else
  {
    m_pComponent = 0i64;
  }
  v17 = pSimObject->m_Flags;
  if ( (v17 & 0x4000) != 0 )
  {
    v18 = 8;
  }
  else if ( v17 >= 0 )
  {
    v18 = -1;
  }
  else
  {
    v18 = 8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v20, pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v20, m_pComponent, v18);
  UFG::SimObjectModifier::Close(&v20);
  UFG::SimObjectModifier::~SimObjectModifier(&v20);
LABEL_34:
  mUID = triggerName->mUID;
  if ( triggerName->mUID == qSymbol_ArrestFailTrigger.mUID )
  {
    BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = enabled;
  }
  else if ( mUID == qSymbol_DeathFailTrigger.mUID )
  {
    BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = enabled;
  }
  else if ( mUID == qSymbol_DamageFailTrigger.mUID )
  {
    BYTE6(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = enabled;
  }
  else if ( mUID == qSymbol_DistanceFailTrigger.mUID )
  {
    HIBYTE(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = enabled;
  }
  else if ( mUID == qSymbol_PanicWeaponFailTrigger.mUID )
  {
    LOBYTE(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) = enabled;
  }
  else if ( mUID == qSymbol_PanicVehicleFailTrigger.mUID )
  {
    BYTE1(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) = enabled;
  }
  else if ( mUID == qSymbol_VehicleFlipFailTrigger.mUID )
  {
    BYTE2(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) = enabled;
  }
  else if ( mUID == qSymbol_BoatStuckFailTrigger.mUID )
  {
    BYTE3(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) = enabled;
  }
}

// File Line: 442
// RVA: 0x54CC40
void __fastcall UFG::MissionFailConditionComponent::SetFailThreshold(
        UFG::SimObject *pSimObject,
        UFG::qSymbol *triggerName,
        float threshold)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r8d
  UFG::SimComponentHolder *p; // r11
  __int64 v10; // rbx
  unsigned int v11; // ecx
  unsigned int v12; // r8d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::SimComponent *v15; // rax
  signed __int16 v16; // cx
  unsigned int v17; // edi
  UFG::SimObjectModifier v18; // [rsp+38h] [rbp-40h] BYREF

  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        p = pSimObject->m_Components.p;
        while ( 1 )
        {
          v10 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && (UFG::MissionFailConditionComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_14;
        }
LABEL_13:
        m_pComponent = p[v10].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_23:
        if ( m_pComponent )
          goto LABEL_33;
        goto LABEL_24;
      }
      v11 = (unsigned int)pSimObject[1].vfptr;
      v12 = pSimObject->m_Components.size;
      if ( v11 < v12 )
      {
        p = pSimObject->m_Components.p;
        do
        {
          v10 = v11;
          if ( (p[v11].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && (UFG::MissionFailConditionComponent::_TypeUID & ~p[v11].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_13;
          }
        }
        while ( ++v11 < v12 );
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
LABEL_24:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v14 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
  if ( v14 )
  {
    UFG::MissionFailConditionComponent::MissionFailConditionComponent(
      (UFG::MissionFailConditionComponent *)v14,
      pSimObject->mNode.mUID,
      0i64);
    m_pComponent = v15;
  }
  else
  {
    m_pComponent = 0i64;
  }
  v16 = pSimObject->m_Flags;
  if ( (v16 & 0x4000) != 0 )
  {
    v17 = 8;
  }
  else if ( v16 >= 0 )
  {
    v17 = -1;
  }
  else
  {
    v17 = 8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v18, pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v18, m_pComponent, v17);
  UFG::SimObjectModifier::Close(&v18);
  UFG::SimObjectModifier::~SimObjectModifier(&v18);
LABEL_33:
  if ( triggerName->mUID == qSymbol_DamageHealthThreshold.mUID )
  {
    *((float *)&m_pComponent[1].m_pSimObject + 1) = threshold;
  }
  else if ( triggerName->mUID == qSymbol_DistanceFailThreshold.mUID )
  {
    *(float *)&m_pComponent[1].m_BoundComponentHandles.mNode.mPrev = threshold;
  }
}

// File Line: 465
// RVA: 0x52D040
float __fastcall UFG::MissionFailConditionComponent::GetFailThreshold(
        UFG::MissionFailConditionComponent *this,
        UFG::qSymbol *triggerName)
{
  if ( triggerName->mUID == qSymbol_DamageHealthThreshold.mUID )
    return this->mDamageHealthThreshold;
  if ( triggerName->mUID == qSymbol_DistanceFailThreshold.mUID )
    return this->mDistanceFailThreshold;
  return 0.0;
}

// File Line: 483
// RVA: 0x54C9A0
void __fastcall UFG::MissionFailConditionComponent::SetFailCaption(
        UFG::SimObject *pSimObject,
        UFG::qSymbol *triggerName,
        const char *caption)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r8d
  UFG::SimComponentHolder *p; // r11
  __int64 v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // r8d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SimComponent *v16; // rax
  signed __int16 v17; // cx
  unsigned int v18; // edi
  unsigned int mUID; // eax
  UFG::qSharedString *p_m_SafePointerList; // rcx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-40h] BYREF

  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        p = pSimObject->m_Components.p;
        while ( 1 )
        {
          v11 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && (UFG::MissionFailConditionComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_14;
        }
LABEL_13:
        m_pComponent = p[v11].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_23:
        if ( m_pComponent )
          goto LABEL_33;
        goto LABEL_24;
      }
      v12 = (unsigned int)pSimObject[1].vfptr;
      v13 = pSimObject->m_Components.size;
      if ( v12 < v13 )
      {
        p = pSimObject->m_Components.p;
        do
        {
          v11 = v12;
          if ( (p[v12].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && (UFG::MissionFailConditionComponent::_TypeUID & ~p[v12].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_13;
          }
        }
        while ( ++v12 < v13 );
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
LABEL_24:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v15 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
  if ( v15 )
  {
    UFG::MissionFailConditionComponent::MissionFailConditionComponent(
      (UFG::MissionFailConditionComponent *)v15,
      pSimObject->mNode.mUID,
      0i64);
    m_pComponent = v16;
  }
  else
  {
    m_pComponent = 0i64;
  }
  v17 = pSimObject->m_Flags;
  if ( (v17 & 0x4000) != 0 )
  {
    v18 = 8;
  }
  else if ( v17 >= 0 )
  {
    v18 = -1;
  }
  else
  {
    v18 = 8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v21, pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, m_pComponent, v18);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
LABEL_33:
  mUID = triggerName->mUID;
  if ( triggerName->mUID == qSymbol_ArrestFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2];
  }
  else if ( mUID == qSymbol_DeathFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_SafePointerList;
  }
  else if ( mUID == qSymbol_DamageFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_SafePointerList.mNode.mNext;
  }
  else if ( mUID == qSymbol_DistanceFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_TypeUID;
  }
  else if ( mUID == qSymbol_PanicWeaponFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_Flags;
  }
  else if ( mUID == qSymbol_PanicVehicleFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_pSimObject;
  }
  else if ( mUID == qSymbol_VehicleFlipFailCaption.mUID )
  {
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_BoundComponentHandles;
  }
  else
  {
    if ( mUID != qSymbol_BoatStuckFailCaption.mUID )
      return;
    p_m_SafePointerList = (UFG::qSharedString *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext;
  }
  UFG::qSharedString::operator=(p_m_SafePointerList, caption);
}

// File Line: 531
// RVA: 0x5339A0
UFG::MissionFailConditionComponent *__fastcall UFG::MissionFailConditionComponent::HandleAttachment(
        UFG::GameSlice *pGameSlice,
        UFG::SimObject *pSimObject,
        component_MissionFailCondition *data_ptr)
{
  UFG::MissionFailConditionComponent *m_pComponent; // rbx
  signed __int16 m_Flags; // cx
  unsigned int vfptr; // ecx
  unsigned int size; // r8d
  UFG::SimComponentHolder *p; // r11
  __int64 v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // r8d
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v16; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::MissionFailConditionComponent *v19; // rax
  signed __int16 v20; // cx
  unsigned int v21; // esi
  UFG::SimObjectModifier v23; // [rsp+38h] [rbp-40h] BYREF

  if ( !pSimObject )
  {
    m_pComponent = 0i64;
LABEL_28:
    mpWritableProperties = 0i64;
    goto LABEL_29;
  }
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::MissionFailConditionComponent *)pSimObject->m_Components.p[8].m_pComponent;
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::MissionFailConditionComponent *)pSimObject->m_Components.p[8].m_pComponent;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = pSimObject->m_Components.p;
      while ( 1 )
      {
        v11 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
          && (UFG::MissionFailConditionComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_15;
      }
LABEL_14:
      m_pComponent = (UFG::MissionFailConditionComponent *)p[v11].m_pComponent;
      goto LABEL_24;
    }
LABEL_15:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v12 = (unsigned int)pSimObject[1].vfptr;
    v13 = pSimObject->m_Components.size;
    if ( v12 < v13 )
    {
      p = pSimObject->m_Components.p;
      while ( 1 )
      {
        v11 = v12;
        if ( (p[v12].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
          && (UFG::MissionFailConditionComponent::_TypeUID & ~p[v12].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_14;
        }
        if ( ++v12 >= v13 )
          goto LABEL_15;
      }
    }
    goto LABEL_15;
  }
  m_pComponent = (UFG::MissionFailConditionComponent *)UFG::SimObject::GetComponentOfType(
                                                         pSimObject,
                                                         UFG::MissionFailConditionComponent::_TypeUID);
LABEL_24:
  if ( m_pComponent )
  {
LABEL_49:
    m_pComponent->mpCustomGameSlice = pGameSlice;
    if ( data_ptr )
      UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(m_pComponent, data_ptr->DistanceFailTrigger);
    return m_pComponent;
  }
  m_pSceneObj = pSimObject->m_pSceneObj;
  if ( !m_pSceneObj )
    goto LABEL_28;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
LABEL_29:
  if ( (data_ptr
     || (v16 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                 mpWritableProperties,
                 (UFG::qArray<unsigned long,0> *)&component_MissionFailCondition::sPropertyName,
                 DEPTH_RECURSE)) != 0i64
     && (data_ptr = (component_MissionFailCondition *)UFG::qPropertySet::GetMemImagePtr(v16)) != 0i64)
    && (data_ptr->ArrestFailTrigger
     || data_ptr->DeathFailTrigger
     || data_ptr->DamageFailTrigger
     || data_ptr->DistanceFailTrigger
     || data_ptr->PanicWeaponFailTrigger
     || data_ptr->PanicVehicleFailTrigger
     || data_ptr->VehicleFlipFailTrigger
     || data_ptr->BoatStuckFailTrigger) )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v18 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
    if ( v18 )
    {
      UFG::MissionFailConditionComponent::MissionFailConditionComponent(
        (UFG::MissionFailConditionComponent *)v18,
        pSimObject->mNode.mUID,
        data_ptr);
      m_pComponent = v19;
    }
    else
    {
      m_pComponent = 0i64;
    }
    v20 = pSimObject->m_Flags;
    if ( (v20 & 0x4000) != 0 )
      v21 = 8;
    else
      v21 = v20 >= 0 ? -1 : 8;
    UFG::SimObjectModifier::SimObjectModifier(&v23, pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v23, m_pComponent, v21);
    UFG::SimObjectModifier::Close(&v23);
    UFG::SimObjectModifier::~SimObjectModifier(&v23);
    if ( m_pComponent )
      goto LABEL_49;
  }
  return m_pComponent;
}

