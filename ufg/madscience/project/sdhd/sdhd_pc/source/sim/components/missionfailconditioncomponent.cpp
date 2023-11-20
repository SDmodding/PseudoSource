// File Line: 28
// RVA: 0x1543F80
__int64 dynamic_initializer_for__UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList__);
}

// File Line: 29
// RVA: 0x52CAA0
UFG::ComponentIDDesc *__fastcall UFG::MissionFailConditionComponent::GetDesc(UFG::MissionFailConditionComponent *this)
{
  return &UFG::MissionFailConditionComponent::_TypeIDesc;
}

// File Line: 49
// RVA: 0x518370
void __fastcall UFG::MissionFailConditionComponent::MissionFailConditionComponent(UFG::MissionFailConditionComponent *this, unsigned int name_uid, component_MissionFailCondition *dataPtr)
{
  component_MissionFailCondition *v3; // rdi
  UFG::MissionFailConditionComponent *v4; // r14
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v5; // rbx
  const char *v6; // rsi
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v7; // rax
  __int64 v8; // rax
  const char *v9; // rdx
  __int64 v10; // rax
  const char *v11; // rdx
  __int64 v12; // rax
  const char *v13; // rdx
  __int64 v14; // rax
  const char *v15; // rdx
  __int64 v16; // rax
  const char *v17; // rdx
  __int64 v18; // rax
  const char *v19; // rdx
  __int64 v20; // rax
  const char *v21; // rdx
  __int64 v22; // rax

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MissionFailConditionComponent::`vftable';
  v6 = 0i64;
  v4->mpDistanceFailObject = 0i64;
  v4->mpCustomGameSlice = 0i64;
  *(_WORD *)&v4->mIsPanicking = 0;
  *(_QWORD *)&v4->mVehicleFlippedTimer = 0i64;
  *(_QWORD *)&v4->mDamageHealthThreshold = 0i64;
  *(_QWORD *)&v4->mArrestFailTrigger = 0i64;
  UFG::qSharedString::qSharedString(&v4->mArrestFailCaption);
  UFG::qSharedString::qSharedString(&v4->mDeathFailCaption);
  UFG::qSharedString::qSharedString(&v4->mDamageFailCaption);
  UFG::qSharedString::qSharedString(&v4->mDistanceFailCaption);
  UFG::qSharedString::qSharedString(&v4->mPanicWeaponFailCaption);
  UFG::qSharedString::qSharedString(&v4->mPanicVehicleFailCaption);
  UFG::qSharedString::qSharedString(&v4->mVehicleFlipFailCaption);
  UFG::qSharedString::qSharedString(&v4->mBoatStuckFailCaption);
  v7 = UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mPrev;
  UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)&v4->mPrev;
  v5->mPrev = v7;
  v4->mNext = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)&UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList;
  UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mPrev = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::MissionFailConditionComponent::_MissionFailConditionComponentTypeUID,
    "MissionFailConditionComponent");
  if ( v3 )
  {
    v4->mArrestFailTrigger = v3->ArrestFailTrigger;
    v4->mDeathFailTrigger = v3->DeathFailTrigger;
    v4->mDamageFailTrigger = v3->DamageFailTrigger;
    v4->mDistanceFailTrigger = v3->DistanceFailTrigger;
    v4->mPanicWeaponFailTrigger = v3->PanicWeaponFailTrigger;
    v4->mPanicVehicleFailTrigger = v3->PanicVehicleFailTrigger;
    v4->mVehicleFlipFailTrigger = v3->VehicleFlipFailTrigger;
    v4->mBoatStuckFailTrigger = v3->BoatStuckFailTrigger;
    v4->mDamageHealthThreshold = v3->DamageHealthThreshold;
    v4->mDistanceFailThreshold = v3->DistanceFailThreshold;
    v8 = v3->ArrestFailCaption.mOffset;
    if ( v8 )
      v9 = (char *)&v3->ArrestFailCaption + v8;
    else
      v9 = 0i64;
    UFG::qSharedString::operator=(&v4->mArrestFailCaption, v9);
    v10 = v3->DeathFailCaption.mOffset;
    if ( v10 )
      v11 = (char *)&v3->DeathFailCaption + v10;
    else
      v11 = 0i64;
    UFG::qSharedString::operator=(&v4->mDeathFailCaption, v11);
    v12 = v3->DamageFailCaption.mOffset;
    if ( v12 )
      v13 = (char *)&v3->DamageFailCaption + v12;
    else
      v13 = 0i64;
    UFG::qSharedString::operator=(&v4->mDamageFailCaption, v13);
    v14 = v3->DistanceFailCaption.mOffset;
    if ( v14 )
      v15 = (char *)&v3->DistanceFailCaption + v14;
    else
      v15 = 0i64;
    UFG::qSharedString::operator=(&v4->mDistanceFailCaption, v15);
    v16 = v3->PanicWeaponFailCaption.mOffset;
    if ( v16 )
      v17 = (char *)&v3->PanicWeaponFailCaption + v16;
    else
      v17 = 0i64;
    UFG::qSharedString::operator=(&v4->mPanicWeaponFailCaption, v17);
    v18 = v3->PanicVehicleFailCaption.mOffset;
    if ( v18 )
      v19 = (char *)&v3->PanicVehicleFailCaption + v18;
    else
      v19 = 0i64;
    UFG::qSharedString::operator=(&v4->mPanicVehicleFailCaption, v19);
    v20 = v3->VehicleFlipFailCaption.mOffset;
    if ( v20 )
      v21 = (char *)&v3->VehicleFlipFailCaption + v20;
    else
      v21 = 0i64;
    UFG::qSharedString::operator=(&v4->mVehicleFlipFailCaption, v21);
    v22 = v3->BoatStuckFailCaption.mOffset;
    if ( v22 )
      v6 = (char *)&v3->BoatStuckFailCaption + v22;
    UFG::qSharedString::operator=(&v4->mBoatStuckFailCaption, v6);
  }
}

// File Line: 81
// RVA: 0x51C0C0
void __fastcall UFG::MissionFailConditionComponent::~MissionFailConditionComponent(UFG::MissionFailConditionComponent *this)
{
  UFG::MissionFailConditionComponent *v1; // rdi
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v2; // rbx
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v3; // rcx
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v4; // rax
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v5; // rcx
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MissionFailConditionComponent::`vftable';
  if ( this == UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator )
    UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator = (UFG::MissionFailConditionComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qSharedString::~qSharedString(&v1->mBoatStuckFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mVehicleFlipFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mPanicVehicleFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mPanicWeaponFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mDistanceFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mDamageFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mDeathFailCaption);
  UFG::qSharedString::~qSharedString(&v1->mArrestFailCaption);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 87
// RVA: 0x53E580
void __fastcall UFG::MissionFailConditionComponent::OnAttach(UFG::MissionFailConditionComponent *this, UFG::SimObject *pObject)
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
  UFG::MissionFailConditionComponent *v1; // rbx
  UFG::SimObject *v2; // rax

  v1 = this;
  v2 = this->m_pSimObject;
  if ( !v2 || !((v2->m_Flags >> 10) & 1) )
  {
    if ( this->mIsDistanceFailTriggerEnabled )
    {
      UFG::SceneObjectProperties::Deactivate(this->mpDistanceFailObject);
      v1->mpDistanceFailObject = 0i64;
      v1->mIsDistanceFailTriggerEnabled = 0;
    }
  }
}

// File Line: 116
// RVA: 0x5269A0
void __fastcall UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(UFG::MissionFailConditionComponent *this, bool enable)
{
  bool v2; // bp
  UFG::MissionFailConditionComponent *v3; // rdi
  UFG::SimObject *v4; // r8
  UFG::SceneObjectProperties *v5; // rax
  UFG::SimObjectCharacter *v6; // r14
  UFG::SimObject *v7; // rcx
  UFG::TransformNodeComponent *v8; // rsi
  char *v9; // rax
  UFG::SceneObjectProperties *v10; // rax
  UFG::qPropertySet *v11; // rax
  UFG::qPropertySet *v12; // rbx
  UFG::SimObject *v13; // rbx
  UFG::TransformNodeComponent *v14; // rcx
  unsigned __int16 v15; // cx
  unsigned int v16; // er8
  unsigned int v17; // er10
  UFG::SimComponentHolder *v18; // rbx
  signed __int64 v19; // rdx
  UFG::TriggerRegion *v20; // rbx
  unsigned int v21; // er8
  unsigned int v22; // er10
  unsigned int v23; // er8
  unsigned int v24; // er10
  unsigned int v25; // er8
  unsigned int v26; // er10
  hkSeekableStreamReader *v27; // rax
  UFG::qString result; // [rsp+28h] [rbp-40h]
  UFG::qSymbol objName; // [rsp+70h] [rbp+8h]

  v2 = enable;
  v3 = this;
  v4 = this->m_pSimObject;
  if ( (!v4 || !((v4->m_Flags >> 10) & 1)) && enable != this->mIsDistanceFailTriggerEnabled )
  {
    if ( v4 )
      v5 = v4->m_pSceneObj;
    else
      v5 = 0i64;
    if ( !enable || !v5 )
    {
      UFG::SceneObjectProperties::Deactivate(this->mpDistanceFailObject);
      v3->mpDistanceFailObject = 0i64;
      goto LABEL_51;
    }
    v6 = UFG::GetLocalPlayer();
    v7 = v3->m_pSimObject;
    v8 = 0i64;
    if ( v7 )
      v8 = v7->m_pTransformNodeComponent;
    if ( !(_S27_1 & 1) )
    {
      _S27_1 |= 1u;
      UFG::qSymbol::create_from_string(&triggerPropertySetSymbol, "object-logical-TriggerRegion");
      atexit(UFG::MissionFailConditionComponent::EnableDistanceFailTrigger_::_10_::_dynamic_atexit_destructor_for__triggerPropertySetSymbol__);
    }
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_pSimObject->m_Name);
    UFG::qString::FormatEx(&result, "%s_fdtrigger", v9);
    UFG::qSymbol::create_from_string(&objName, result.mData);
    v10 = UFG::SceneObjectProperties::Create(&objName, 0i64, &triggerPropertySetSymbol);
    v3->mpDistanceFailObject = v10;
    v11 = UFG::SceneObjectProperties::GetWritableProperties(v10);
    v12 = UFG::RegionComponent::PropertiesAppendDefaultProperty(v11);
    UFG::qPropertySet::Set<unsigned long>(v12, (UFG::qSymbol *)&SimSym_Type.mUID, 2u);
    UFG::qPropertySet::Set<float>(v12, (UFG::qSymbol *)&SimSym_Radius.mUID, v3->mDistanceFailThreshold);
    UFG::SceneObjectProperties::Activate(v3->mpDistanceFailObject, 1u, 0i64, 0i64);
    v13 = v3->mpDistanceFailObject->m_pSimObject;
    if ( !v13 )
    {
LABEL_49:
      UFG::qString::~qString(&result);
LABEL_51:
      v3->mIsDistanceFailTriggerEnabled = v2;
      return;
    }
    v14 = v13->m_pTransformNodeComponent;
    if ( v14 )
      UFG::TransformNodeComponent::SetParent(v14, v8, 0);
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v16 = (unsigned int)v13[1].vfptr;
      v17 = v13->m_Components.size;
      if ( v16 < v17 )
      {
        v18 = v13->m_Components.p;
        while ( 1 )
        {
          v19 = v16;
          if ( (v18[v16].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && !(UFG::TriggerRegion::_TypeUID & ~v18[v16].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v16 >= v17 )
            goto LABEL_24;
        }
LABEL_23:
        v20 = (UFG::TriggerRegion *)v18[v19].m_pComponent;
        goto LABEL_47;
      }
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v23 = (unsigned int)v13[1].vfptr;
        v24 = v13->m_Components.size;
        if ( v23 < v24 )
        {
          v18 = v13->m_Components.p;
          do
          {
            v19 = v23;
            if ( (v18[v23].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && !(UFG::TriggerRegion::_TypeUID & ~v18[v23].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_23;
            }
          }
          while ( ++v23 < v24 );
        }
      }
      else
      {
        if ( !((v15 >> 12) & 1) )
        {
          v20 = (UFG::TriggerRegion *)UFG::SimObject::GetComponentOfType(v13, UFG::TriggerRegion::_TypeUID);
LABEL_47:
          if ( v20 )
          {
            UFG::TriggerRegion::TrackTarget(v20, (UFG::SimObject *)&v6->vfptr, 0i64);
            v27 = Assembly::GetRCX(v3);
            v20->mOnExitedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::MissionFailConditionComponent::OnExitTrigger;
            v20->mOnExitedDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v27;
            UFG::TriggerRegion::EnableHot(v20, 1);
          }
          goto LABEL_49;
        }
        v25 = (unsigned int)v13[1].vfptr;
        v26 = v13->m_Components.size;
        if ( v25 < v26 )
        {
          v18 = v13->m_Components.p;
          do
          {
            v19 = v25;
            if ( (v18[v25].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
              && !(UFG::TriggerRegion::_TypeUID & ~v18[v25].m_TypeUID & 0x1FFFFFF) )
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
        v18 = v13->m_Components.p;
        do
        {
          v19 = v21;
          if ( (v18[v21].m_TypeUID & 0xFE000000) == (UFG::TriggerRegion::_TypeUID & 0xFE000000)
            && !(UFG::TriggerRegion::_TypeUID & ~v18[v21].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_23;
          }
        }
        while ( ++v21 < v22 );
      }
    }
LABEL_24:
    v20 = 0i64;
    goto LABEL_47;
  }
}

// File Line: 179
// RVA: 0x527C70
void __fastcall UFG::MissionFailConditionComponent::FailObject(UFG::SimObject *simObject, UFG::qSymbol *captionType)
{
  UFG::qSymbol *v2; // rbx
  UFG::SimObject *v3; // rdi
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rcx
  component_MissionFailCondition *v6; // rax
  const char *v7; // rdx
  unsigned int v8; // ecx
  __int64 v9; // rcx
  UFG::qOffset64<char *> *v10; // rdx
  UFG::ProgressionTracker *v11; // rax
  UFG::qString caption; // [rsp+28h] [rbp-30h]

  v2 = captionType;
  v3 = simObject;
  v4 = simObject->m_pSceneObj;
  v5 = v4->mpWritableProperties;
  if ( !v5 )
    v5 = v4->mpConstProperties;
  v6 = (component_MissionFailCondition *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                           v5,
                                           (UFG::qSymbol *)&component_MissionFailCondition::sPropertyName.mUID,
                                           DEPTH_RECURSE);
  if ( v6 )
    v6 = (component_MissionFailCondition *)UFG::qPropertySet::GetMemImagePtr((UFG::qPropertySet *)v6);
  v7 = &customWorldMapCaption;
  v8 = v2->mUID;
  if ( v2->mUID == qSymbol_ArrestFailCaption.mUID )
  {
    v9 = v6->ArrestFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->ArrestFailCaption;
LABEL_29:
      v7 = (char *)v10 + v9;
      goto LABEL_31;
    }
    goto LABEL_30;
  }
  if ( v8 == qSymbol_DeathFailCaption.mUID )
  {
    v9 = v6->DeathFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->DeathFailCaption;
      goto LABEL_29;
    }
LABEL_30:
    v7 = 0i64;
    goto LABEL_31;
  }
  if ( v8 == qSymbol_DamageFailCaption.mUID )
  {
    v9 = v6->DamageFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->DamageFailCaption;
      goto LABEL_29;
    }
    goto LABEL_30;
  }
  if ( v8 == qSymbol_DistanceFailCaption.mUID )
  {
    v9 = v6->DistanceFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->DistanceFailCaption;
      goto LABEL_29;
    }
    goto LABEL_30;
  }
  if ( v8 == qSymbol_PanicWeaponFailCaption.mUID )
  {
    v9 = v6->PanicWeaponFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->PanicWeaponFailCaption;
      goto LABEL_29;
    }
    goto LABEL_30;
  }
  if ( v8 == qSymbol_PanicVehicleFailCaption.mUID )
  {
    v9 = v6->PanicVehicleFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->PanicVehicleFailCaption;
      goto LABEL_29;
    }
    goto LABEL_30;
  }
  if ( v8 == qSymbol_VehicleFlipFailCaption.mUID )
  {
    v9 = v6->VehicleFlipFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->VehicleFlipFailCaption;
      goto LABEL_29;
    }
    goto LABEL_30;
  }
  if ( v8 == qSymbol_BoatStuckFailCaption.mUID )
  {
    v9 = v6->BoatStuckFailCaption.mOffset;
    if ( v9 )
    {
      v10 = &v6->BoatStuckFailCaption;
      goto LABEL_29;
    }
    goto LABEL_30;
  }
LABEL_31:
  UFG::qString::qString(&caption, v7);
  v11 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::OnFailObject(v11, v3, &caption);
  UFG::qString::~qString(&caption);
}

// File Line: 221
// RVA: 0x541CD0
void __fastcall UFG::MissionFailConditionComponent::OnExitTrigger(UFG::MissionFailConditionComponent *this, UFG::TriggerRegion *pTriggerRegion)
{
  UFG::MissionFailConditionComponent *v2; // rbx

  v2 = this;
  UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(this, 0);
  UFG::MissionFailConditionComponent::FailObject(v2->m_pSimObject, (UFG::qSymbol *)&qSymbol_DistanceFailCaption.mUID);
}

// File Line: 229
// RVA: 0x55BC00
void __fastcall UFG::MissionFailConditionComponent::Update(UFG::MissionFailConditionComponent *this, float deltaTime)
{
  UFG::MissionFailConditionComponent *v2; // rbx
  UFG::SimObject *v3; // rax
  unsigned int v4; // eax
  UFG::SimObject *v5; // rcx
  UFG::SceneObjectProperties *v6; // rax
  bool v7; // si
  bool v8; // bp
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rcx
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned int v14; // er9
  UFG::SimComponentHolder *v15; // rdi
  signed __int64 v16; // r8
  unsigned int v17; // edx
  unsigned int v18; // er9
  UFG::SimObject *v19; // r8
  unsigned __int16 v20; // cx
  UFG::SimComponent *v21; // rdi
  unsigned int v22; // ecx
  unsigned int v23; // er9
  UFG::SimComponentHolder *v24; // r11
  signed __int64 v25; // rdi
  unsigned int v26; // ecx
  unsigned int v27; // er9
  UFG::qStaticSymbol *v28; // rdx
  float v29; // xmm0_4
  float v30; // xmm7_4

  v2 = this;
  v3 = this->m_pSimObject;
  if ( !v3 || !((v3->m_Flags >> 10) & 1) )
  {
    v4 = _S28_0;
    if ( !(_S28_0 & 1) )
    {
      _S28_0 |= 1u;
      UID_BeScaredOfGunPointedAtMe.mUID = UFG::qStringHashUpper32("BeScaredOfGunPointedAtMe", 0xFFFFFFFF);
      v4 = _S28_0;
    }
    if ( !(v4 & 2) )
    {
      _S28_0 = v4 | 2;
      UID_Cower.mUID = UFG::qStringHashUpper32("Cower", 0xFFFFFFFF);
      v4 = _S28_0;
    }
    if ( !(v4 & 4) )
    {
      _S28_0 = v4 | 4;
      UID_BeScaredOfGunPointedNearMe.mUID = UFG::qStringHashUpper32("BeScaredOfGunPointedNearMe", 0xFFFFFFFF);
      v4 = _S28_0;
    }
    if ( !(v4 & 8) )
    {
      _S28_0 = v4 | 8;
      UID_BeScaredOfDrawnWeapon.mUID = UFG::qStringHashUpper32("BeScaredOfDrawnWeapon", 0xFFFFFFFF);
      v4 = _S28_0;
    }
    if ( !(v4 & 0x10) )
    {
      _S28_0 = v4 | 0x10;
      UID_RunAwayFromDangerousVehicle.mUID = UFG::qStringHashUpper32("RunAwayFromDangerousVehicle", 0xFFFFFFFF);
      v4 = _S28_0;
    }
    if ( !(v4 & 0x20) )
    {
      _S28_0 = v4 | 0x20;
      UID_Flinch.mUID = UFG::qStringHashUpper32("Flinch", 0xFFFFFFFF);
    }
    v5 = v2->m_pSimObject;
    if ( v5 )
    {
      v6 = v5->m_pSceneObj;
      if ( v6 )
      {
        if ( v6->mpWritableProperties || v6->mpConstProperties )
        {
          if ( v2->mIsPanicking )
            goto LABEL_84;
          v7 = v2->mPanicWeaponFailTrigger;
          v8 = v2->mPanicVehicleFailTrigger;
          if ( !v7 && !v8 )
            goto LABEL_84;
          v9 = v5->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = v5->m_Components.p[22].m_pComponent;
            if ( !v10 )
              goto LABEL_26;
            v11 = v10->m_TypeUID;
            if ( (v11 ^ UFG::ActiveAIEntityComponent::_TypeUID) & 0xFE000000
              || UFG::ActiveAIEntityComponent::_TypeUID & ~v11 & 0x1FFFFFF )
            {
              goto LABEL_26;
            }
          }
          else
          {
            if ( (v9 & 0x8000u) == 0 )
            {
              if ( (v9 >> 13) & 1 )
              {
                v13 = (unsigned int)v5[1].vfptr;
                v14 = v5->m_Components.size;
                if ( v13 >= v14 )
                {
LABEL_26:
                  v10 = 0i64;
                  goto LABEL_48;
                }
                v15 = v5->m_Components.p;
                while ( 1 )
                {
                  v16 = v13;
                  if ( (v15[v13].m_TypeUID & 0xFE000000) == (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
                    && !(UFG::ActiveAIEntityComponent::_TypeUID & ~v15[v13].m_TypeUID & 0x1FFFFFF) )
                  {
                    break;
                  }
                  if ( ++v13 >= v14 )
                    goto LABEL_26;
                }
              }
              else
              {
                if ( !((v9 >> 12) & 1) )
                {
                  v10 = UFG::SimObject::GetComponentOfType(v5, UFG::ActiveAIEntityComponent::_TypeUID);
                  goto LABEL_48;
                }
                v17 = (unsigned int)v5[1].vfptr;
                v18 = v5->m_Components.size;
                if ( v17 >= v18 )
                  goto LABEL_26;
                v15 = v5->m_Components.p;
                while ( 1 )
                {
                  v16 = v17;
                  if ( (v15[v17].m_TypeUID & 0xFE000000) == (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
                    && !(UFG::ActiveAIEntityComponent::_TypeUID & ~v15[v17].m_TypeUID & 0x1FFFFFF) )
                  {
                    break;
                  }
                  if ( ++v17 >= v18 )
                    goto LABEL_26;
                }
              }
              v10 = v15[v16].m_pComponent;
              goto LABEL_48;
            }
            v10 = v5->m_Components.p[22].m_pComponent;
            if ( !v10 )
              goto LABEL_26;
            v12 = v10->m_TypeUID;
            if ( (v12 ^ UFG::ActiveAIEntityComponent::_TypeUID) & 0xFE000000 )
              goto LABEL_26;
            if ( UFG::ActiveAIEntityComponent::_TypeUID & ~v12 & 0x1FFFFFF )
              v10 = 0i64;
          }
LABEL_48:
          if ( !v10 )
            goto LABEL_84;
          if ( HIDWORD(v10[64].m_BoundComponentHandles.mNode.mNext) != 1 )
            goto LABEL_84;
          v19 = v2->m_pSimObject;
          if ( !v19 )
            goto LABEL_84;
          v20 = v19->m_Flags;
          if ( (v20 >> 14) & 1 )
          {
            v21 = v19->m_Components.p[19].m_pComponent;
            goto LABEL_72;
          }
          if ( (v20 & 0x8000u) != 0 )
          {
            v21 = v19->m_Components.p[19].m_pComponent;
            goto LABEL_72;
          }
          if ( (v20 >> 13) & 1 )
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
                  && !(UFG::AIActionTreeComponent::_TypeUID & ~v24[v22].m_TypeUID & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v22 >= v23 )
                  goto LABEL_63;
              }
LABEL_62:
              v21 = v24[v25].m_pComponent;
              goto LABEL_72;
            }
          }
          else
          {
            if ( !((v20 >> 12) & 1) )
            {
              v21 = UFG::SimObject::GetComponentOfType(v2->m_pSimObject, UFG::AIActionTreeComponent::_TypeUID);
LABEL_72:
              if ( v21 )
              {
                if ( v7
                  && (ActionController::IsPlaying(
                        (ActionController *)&v21[3].m_TypeUID,
                        &UID_BeScaredOfGunPointedAtMe,
                        0xFFFFFFFF,
                        0)
                   || ActionController::IsPlaying((ActionController *)&v21[3].m_TypeUID, &UID_Cower, 0xFFFFFFFF, 0)
                   || ActionController::IsPlaying(
                        (ActionController *)&v21[3].m_TypeUID,
                        &UID_BeScaredOfGunPointedNearMe,
                        0xFFFFFFFF,
                        0)
                   || ActionController::IsPlaying(
                        (ActionController *)&v21[3].m_TypeUID,
                        &UID_BeScaredOfDrawnWeapon,
                        0xFFFFFFFF,
                        0)) )
                {
                  v28 = &qSymbol_PanicWeaponFailCaption;
                }
                else
                {
                  if ( !v8
                    || !ActionController::IsPlaying(
                          (ActionController *)&v21[3].m_TypeUID,
                          &UID_RunAwayFromDangerousVehicle,
                          0xFFFFFFFF,
                          0)
                    && !ActionController::IsPlaying((ActionController *)&v21[3].m_TypeUID, &UID_Flinch, 0xFFFFFFFF, 0) )
                  {
                    goto LABEL_84;
                  }
                  v28 = &qSymbol_PanicVehicleFailCaption;
                }
                v2->mIsPanicking = 1;
                UFG::MissionFailConditionComponent::FailObject(v2->m_pSimObject, (UFG::qSymbol *)&v28->mUID);
              }
LABEL_84:
              if ( v2->mVehicleFlipFailTrigger
                && (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(
                                   (UFG::SimObjectVehicle *)v2->m_pSimObject,
                                   0,
                                   0i64) )
              {
                v29 = deltaTime + v2->mVehicleFlippedTimer;
                v2->mVehicleFlippedTimer = v29;
                if ( v29 > 2.0 )
                  UFG::MissionFailConditionComponent::FailObject(
                    v2->m_pSimObject,
                    (UFG::qSymbol *)&qSymbol_VehicleFlipFailCaption.mUID);
              }
              else
              {
                v2->mVehicleFlippedTimer = 0.0;
              }
              if ( !v2->mBoatStuckFailTrigger || UFG::SimObjectUtility::IsBoatInWater(v2->m_pSimObject) )
              {
                v2->mBoatStuckTimer = 0.0;
              }
              else
              {
                v30 = deltaTime + v2->mBoatStuckTimer;
                v2->mBoatStuckTimer = v30;
                if ( v30 > 2.0 )
                  UFG::MissionFailConditionComponent::FailObject(
                    v2->m_pSimObject,
                    (UFG::qSymbol *)&qSymbol_BoatStuckFailCaption.mUID);
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
                  && !(UFG::AIActionTreeComponent::_TypeUID & ~v24[v26].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_62;
                }
              }
              while ( ++v26 < v27 );
            }
          }
LABEL_63:
          v21 = 0i64;
          goto LABEL_72;
        }
      }
    }
  }
}

// File Line: 339
// RVA: 0x546A30
UFG::MissionFailConditionComponent *__fastcall UFG::MissionFailConditionComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  bool v4; // di
  component_MissionFailCondition *v5; // rax
  UFG::MissionFailConditionComponent *result; // rax

  v2 = pSceneObj;
  v3 = pSceneObj->mpWritableProperties;
  v4 = required;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = (component_MissionFailCondition *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                           v3,
                                           (UFG::qSymbol *)&component_MissionFailCondition::sPropertyName.mUID,
                                           DEPTH_RECURSE);
  if ( v5 && (v5 = (component_MissionFailCondition *)UFG::qPropertySet::GetMemImagePtr((UFG::qPropertySet *)v5)) != 0i64
    || v4 )
  {
    result = UFG::MissionFailConditionComponent::HandleAttachment(0i64, v2->m_pSimObject, v5);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 389
// RVA: 0x54CE70
void __fastcall UFG::MissionFailConditionComponent::SetFailTrigger(UFG::SimObject *pSimObject, UFG::qSymbol *triggerName, bool enabled)
{
  bool v3; // bp
  UFG::qSymbol *v4; // r14
  UFG::SimObject *v5; // rsi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rbx
  unsigned int v8; // ecx
  unsigned int v9; // er8
  UFG::SimComponentHolder *v10; // r11
  signed __int64 v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // er8
  UFG::qMemoryPool *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SimComponent *v16; // rax
  unsigned __int16 v17; // cx
  unsigned int v18; // edi
  unsigned int v19; // eax
  UFG::SimObjectModifier v20; // [rsp+38h] [rbp-40h]

  v3 = enabled;
  v4 = triggerName;
  v5 = pSimObject;
  if ( pSimObject )
  {
    v6 = pSimObject->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (v6 & 0x8000u) != 0 )
    {
      v7 = v5->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (v6 >> 13) & 1 )
    {
      v8 = (unsigned int)v5[1].vfptr;
      v9 = v5->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = v5->m_Components.p;
        while ( 1 )
        {
          v11 = v8;
          if ( (v10[v8].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && !(UFG::MissionFailConditionComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v8 >= v9 )
            goto LABEL_14;
        }
LABEL_13:
        v7 = v10[v11].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v6 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType(v5, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_23:
        if ( v7 )
          goto LABEL_34;
        goto LABEL_24;
      }
      v12 = (unsigned int)v5[1].vfptr;
      v13 = v5->m_Components.size;
      if ( v12 < v13 )
      {
        v10 = v5->m_Components.p;
        do
        {
          v11 = v12;
          if ( (v10[v12].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && !(UFG::MissionFailConditionComponent::_TypeUID & ~v10[v12].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_13;
          }
        }
        while ( ++v12 < v13 );
      }
    }
LABEL_14:
    v7 = 0i64;
    goto LABEL_23;
  }
LABEL_24:
  if ( !v3 )
    return;
  v14 = UFG::GetSimulationMemoryPool();
  v15 = UFG::qMemoryPool::Allocate(v14, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
  if ( v15 )
  {
    UFG::MissionFailConditionComponent::MissionFailConditionComponent(
      (UFG::MissionFailConditionComponent *)v15,
      v5->mNode.mUID,
      0i64);
    v7 = v16;
  }
  else
  {
    v7 = 0i64;
  }
  v17 = v5->m_Flags;
  if ( (v17 >> 14) & 1 )
  {
    v18 = 8;
  }
  else if ( (v17 & 0x8000u) == 0 )
  {
    v18 = -1;
  }
  else
  {
    v18 = 8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v20, v5, 1);
  UFG::SimObjectModifier::AttachComponent(&v20, v7, v18);
  UFG::SimObjectModifier::Close(&v20);
  UFG::SimObjectModifier::~SimObjectModifier(&v20);
LABEL_34:
  v19 = v4->mUID;
  if ( v4->mUID == qSymbol_ArrestFailTrigger.mUID )
  {
    BYTE4(v7[1].m_BoundComponentHandles.mNode.mPrev) = v3;
  }
  else if ( v19 == qSymbol_DeathFailTrigger.mUID )
  {
    BYTE5(v7[1].m_BoundComponentHandles.mNode.mPrev) = v3;
  }
  else if ( v19 == qSymbol_DamageFailTrigger.mUID )
  {
    BYTE6(v7[1].m_BoundComponentHandles.mNode.mPrev) = v3;
  }
  else if ( v19 == qSymbol_DistanceFailTrigger.mUID )
  {
    HIBYTE(v7[1].m_BoundComponentHandles.mNode.mPrev) = v3;
  }
  else if ( v19 == qSymbol_PanicWeaponFailTrigger.mUID )
  {
    LOBYTE(v7[1].m_BoundComponentHandles.mNode.mNext) = v3;
  }
  else if ( v19 == qSymbol_PanicVehicleFailTrigger.mUID )
  {
    BYTE1(v7[1].m_BoundComponentHandles.mNode.mNext) = v3;
  }
  else if ( v19 == qSymbol_VehicleFlipFailTrigger.mUID )
  {
    BYTE2(v7[1].m_BoundComponentHandles.mNode.mNext) = v3;
  }
  else if ( v19 == qSymbol_BoatStuckFailTrigger.mUID )
  {
    BYTE3(v7[1].m_BoundComponentHandles.mNode.mNext) = v3;
  }
}

// File Line: 442
// RVA: 0x54CC40
void __fastcall UFG::MissionFailConditionComponent::SetFailThreshold(UFG::SimObject *pSimObject, UFG::qSymbol *triggerName, float threshold)
{
  UFG::qSymbol *v3; // r14
  UFG::SimObject *v4; // rsi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rbx
  unsigned int v7; // ecx
  unsigned int v8; // er8
  UFG::SimComponentHolder *v9; // r11
  signed __int64 v10; // rbx
  unsigned int v11; // ecx
  unsigned int v12; // er8
  UFG::qMemoryPool *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::SimComponent *v15; // rax
  unsigned __int16 v16; // cx
  unsigned int v17; // edi
  UFG::SimObjectModifier v18; // [rsp+38h] [rbp-40h]

  v3 = triggerName;
  v4 = pSimObject;
  if ( pSimObject )
  {
    v5 = pSimObject->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (v5 & 0x8000u) != 0 )
    {
      v6 = v4->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (v5 >> 13) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 < v8 )
      {
        v9 = v4->m_Components.p;
        while ( 1 )
        {
          v10 = v7;
          if ( (v9[v7].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && !(UFG::MissionFailConditionComponent::_TypeUID & ~v9[v7].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v7 >= v8 )
            goto LABEL_14;
        }
LABEL_13:
        v6 = v9[v10].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v5 >> 12) & 1) )
      {
        v6 = UFG::SimObject::GetComponentOfType(v4, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_23:
        if ( v6 )
          goto LABEL_33;
        goto LABEL_24;
      }
      v11 = (unsigned int)v4[1].vfptr;
      v12 = v4->m_Components.size;
      if ( v11 < v12 )
      {
        v9 = v4->m_Components.p;
        do
        {
          v10 = v11;
          if ( (v9[v11].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && !(UFG::MissionFailConditionComponent::_TypeUID & ~v9[v11].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_13;
          }
        }
        while ( ++v11 < v12 );
      }
    }
LABEL_14:
    v6 = 0i64;
    goto LABEL_23;
  }
LABEL_24:
  v13 = UFG::GetSimulationMemoryPool();
  v14 = UFG::qMemoryPool::Allocate(v13, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
  if ( v14 )
  {
    UFG::MissionFailConditionComponent::MissionFailConditionComponent(
      (UFG::MissionFailConditionComponent *)v14,
      v4->mNode.mUID,
      0i64);
    v6 = v15;
  }
  else
  {
    v6 = 0i64;
  }
  v16 = v4->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = 8;
  }
  else if ( (v16 & 0x8000u) == 0 )
  {
    v17 = -1;
  }
  else
  {
    v17 = 8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v18, v4, 1);
  UFG::SimObjectModifier::AttachComponent(&v18, v6, v17);
  UFG::SimObjectModifier::Close(&v18);
  UFG::SimObjectModifier::~SimObjectModifier(&v18);
LABEL_33:
  if ( v3->mUID == qSymbol_DamageHealthThreshold.mUID )
  {
    *((float *)&v6[1].m_pSimObject + 1) = threshold;
  }
  else if ( v3->mUID == qSymbol_DistanceFailThreshold.mUID )
  {
    *(float *)&v6[1].m_BoundComponentHandles.mNode.mPrev = threshold;
  }
}

// File Line: 465
// RVA: 0x52D040
float __fastcall UFG::MissionFailConditionComponent::GetFailThreshold(UFG::MissionFailConditionComponent *this, UFG::qSymbol *triggerName)
{
  if ( triggerName->mUID == qSymbol_DamageHealthThreshold.mUID )
    return this->mDamageHealthThreshold;
  if ( triggerName->mUID == qSymbol_DistanceFailThreshold.mUID )
    return this->mDistanceFailThreshold;
  return 0.0;
}

// File Line: 483
// RVA: 0x54C9A0
void __fastcall UFG::MissionFailConditionComponent::SetFailCaption(UFG::SimObject *pSimObject, UFG::qSymbol *triggerName, const char *caption)
{
  const char *v3; // rbp
  UFG::qSymbol *v4; // r14
  UFG::SimObject *v5; // rsi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rbx
  unsigned int v8; // ecx
  unsigned int v9; // er8
  UFG::SimComponentHolder *v10; // r11
  signed __int64 v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // er8
  UFG::qMemoryPool *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SimComponent *v16; // rax
  unsigned __int16 v17; // cx
  unsigned int v18; // edi
  unsigned int v19; // eax
  UFG::qSharedString *v20; // rcx
  UFG::SimObjectModifier v21; // [rsp+38h] [rbp-40h]

  v3 = caption;
  v4 = triggerName;
  v5 = pSimObject;
  if ( pSimObject )
  {
    v6 = pSimObject->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (v6 & 0x8000u) != 0 )
    {
      v7 = v5->m_Components.p[8].m_pComponent;
      goto LABEL_23;
    }
    if ( (v6 >> 13) & 1 )
    {
      v8 = (unsigned int)v5[1].vfptr;
      v9 = v5->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = v5->m_Components.p;
        while ( 1 )
        {
          v11 = v8;
          if ( (v10[v8].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && !(UFG::MissionFailConditionComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v8 >= v9 )
            goto LABEL_14;
        }
LABEL_13:
        v7 = v10[v11].m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v6 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType(v5, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_23:
        if ( v7 )
          goto LABEL_33;
        goto LABEL_24;
      }
      v12 = (unsigned int)v5[1].vfptr;
      v13 = v5->m_Components.size;
      if ( v12 < v13 )
      {
        v10 = v5->m_Components.p;
        do
        {
          v11 = v12;
          if ( (v10[v12].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
            && !(UFG::MissionFailConditionComponent::_TypeUID & ~v10[v12].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_13;
          }
        }
        while ( ++v12 < v13 );
      }
    }
LABEL_14:
    v7 = 0i64;
    goto LABEL_23;
  }
LABEL_24:
  v14 = UFG::GetSimulationMemoryPool();
  v15 = UFG::qMemoryPool::Allocate(v14, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
  if ( v15 )
  {
    UFG::MissionFailConditionComponent::MissionFailConditionComponent(
      (UFG::MissionFailConditionComponent *)v15,
      v5->mNode.mUID,
      0i64);
    v7 = v16;
  }
  else
  {
    v7 = 0i64;
  }
  v17 = v5->m_Flags;
  if ( (v17 >> 14) & 1 )
  {
    v18 = 8;
  }
  else if ( (v17 & 0x8000u) == 0 )
  {
    v18 = -1;
  }
  else
  {
    v18 = 8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v21, v5, 1);
  UFG::SimObjectModifier::AttachComponent(&v21, v7, v18);
  UFG::SimObjectModifier::Close(&v21);
  UFG::SimObjectModifier::~SimObjectModifier(&v21);
LABEL_33:
  v19 = v4->mUID;
  if ( v4->mUID == qSymbol_ArrestFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2];
  }
  else if ( v19 == qSymbol_DeathFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2].m_SafePointerList;
  }
  else if ( v19 == qSymbol_DamageFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2].m_SafePointerList.mNode.mNext;
  }
  else if ( v19 == qSymbol_DistanceFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2].m_TypeUID;
  }
  else if ( v19 == qSymbol_PanicWeaponFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2].m_Flags;
  }
  else if ( v19 == qSymbol_PanicVehicleFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2].m_pSimObject;
  }
  else if ( v19 == qSymbol_VehicleFlipFailCaption.mUID )
  {
    v20 = (UFG::qSharedString *)&v7[2].m_BoundComponentHandles;
  }
  else
  {
    if ( v19 != qSymbol_BoatStuckFailCaption.mUID )
      return;
    v20 = (UFG::qSharedString *)&v7[2].m_BoundComponentHandles.mNode.mNext;
  }
  UFG::qSharedString::operator=(v20, v3);
}

// File Line: 531
// RVA: 0x5339A0
UFG::MissionFailConditionComponent *__fastcall UFG::MissionFailConditionComponent::HandleAttachment(UFG::GameSlice *pGameSlice, UFG::SimObject *pSimObject, component_MissionFailCondition *data_ptr)
{
  component_MissionFailCondition *v3; // rdi
  UFG::SimObject *v4; // rbp
  UFG::GameSlice *v5; // r14
  UFG::MissionFailConditionComponent *v6; // rbx
  unsigned __int16 v7; // cx
  unsigned int v8; // ecx
  unsigned int v9; // er8
  UFG::SimComponentHolder *v10; // r11
  signed __int64 v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // er8
  UFG::SceneObjectProperties *v14; // rax
  UFG::qPropertySet *v15; // rcx
  UFG::qPropertySet *v16; // rax
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::MissionFailConditionComponent *v19; // rax
  unsigned __int16 v20; // cx
  unsigned int v21; // esi
  UFG::SimObjectModifier v23; // [rsp+38h] [rbp-40h]

  v3 = data_ptr;
  v4 = pSimObject;
  v5 = pGameSlice;
  if ( !pSimObject )
  {
    v6 = 0i64;
LABEL_28:
    v15 = 0i64;
    goto LABEL_29;
  }
  v7 = pSimObject->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v6 = (UFG::MissionFailConditionComponent *)pSimObject->m_Components.p[8].m_pComponent;
    goto LABEL_24;
  }
  if ( (v7 & 0x8000u) != 0 )
  {
    v6 = (UFG::MissionFailConditionComponent *)pSimObject->m_Components.p[8].m_pComponent;
    goto LABEL_24;
  }
  if ( (v7 >> 13) & 1 )
  {
    v8 = (unsigned int)pSimObject[1].vfptr;
    v9 = pSimObject->m_Components.size;
    if ( v8 < v9 )
    {
      v10 = pSimObject->m_Components.p;
      while ( 1 )
      {
        v11 = v8;
        if ( (v10[v8].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
          && !(UFG::MissionFailConditionComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v8 >= v9 )
          goto LABEL_15;
      }
LABEL_14:
      v6 = (UFG::MissionFailConditionComponent *)v10[v11].m_pComponent;
      goto LABEL_24;
    }
LABEL_15:
    v6 = 0i64;
    goto LABEL_24;
  }
  if ( (v7 >> 12) & 1 )
  {
    v12 = (unsigned int)pSimObject[1].vfptr;
    v13 = pSimObject->m_Components.size;
    if ( v12 < v13 )
    {
      v10 = pSimObject->m_Components.p;
      while ( 1 )
      {
        v11 = v12;
        if ( (v10[v12].m_TypeUID & 0xFE000000) == (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
          && !(UFG::MissionFailConditionComponent::_TypeUID & ~v10[v12].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_14;
        }
        if ( ++v12 >= v13 )
          goto LABEL_15;
      }
    }
    goto LABEL_15;
  }
  v6 = (UFG::MissionFailConditionComponent *)UFG::SimObject::GetComponentOfType(
                                               pSimObject,
                                               UFG::MissionFailConditionComponent::_TypeUID);
LABEL_24:
  if ( v6 )
  {
LABEL_49:
    v6->mpCustomGameSlice = v5;
    if ( v3 )
      UFG::MissionFailConditionComponent::EnableDistanceFailTrigger(v6, v3->DistanceFailTrigger);
    return v6;
  }
  v14 = v4->m_pSceneObj;
  if ( !v14 )
    goto LABEL_28;
  v15 = v14->mpWritableProperties;
  if ( !v15 )
    v15 = v14->mpConstProperties;
LABEL_29:
  if ( v3
    || (v16 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v15,
                (UFG::qSymbol *)&component_MissionFailCondition::sPropertyName.mUID,
                DEPTH_RECURSE)) != 0i64
    && (v3 = (component_MissionFailCondition *)UFG::qPropertySet::GetMemImagePtr(v16)) != 0i64 )
  {
    if ( v3->ArrestFailTrigger
      || v3->DeathFailTrigger
      || v3->DamageFailTrigger
      || v3->DistanceFailTrigger
      || v3->PanicWeaponFailTrigger
      || v3->PanicVehicleFailTrigger
      || v3->VehicleFlipFailTrigger
      || v3->BoatStuckFailTrigger )
    {
      v17 = UFG::GetSimulationMemoryPool();
      v18 = UFG::qMemoryPool::Allocate(v17, 0xC0ui64, "MissionFailConditionComponent", 0i64, 1u);
      if ( v18 )
      {
        UFG::MissionFailConditionComponent::MissionFailConditionComponent(
          (UFG::MissionFailConditionComponent *)v18,
          v4->mNode.mUID,
          v3);
        v6 = v19;
      }
      else
      {
        v6 = 0i64;
      }
      v20 = v4->m_Flags;
      if ( (v20 >> 14) & 1 )
        v21 = 8;
      else
        v21 = (v20 & 0x8000u) == 0 ? -1 : 8;
      UFG::SimObjectModifier::SimObjectModifier(&v23, v4, 1);
      UFG::SimObjectModifier::AttachComponent(&v23, (UFG::SimComponent *)&v6->vfptr, v21);
      UFG::SimObjectModifier::Close(&v23);
      UFG::SimObjectModifier::~SimObjectModifier(&v23);
      if ( v6 )
        goto LABEL_49;
    }
  }
  return v6;
}

