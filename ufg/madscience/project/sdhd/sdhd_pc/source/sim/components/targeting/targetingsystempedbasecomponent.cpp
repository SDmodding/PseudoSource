// File Line: 81
// RVA: 0x1544120
__int64 dynamic_initializer_for__UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList__);
}

// File Line: 82
// RVA: 0x1543670
__int64 dynamic_initializer_for__UFG::TargetingSystemPedBaseComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::TargetingSystemPedBaseComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::TargetingSystemPedBaseComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::TargetingSystemPedBaseComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::TargetingSystemPedBaseComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 102
// RVA: 0x1543C50
__int64 dynamic_initializer_for__UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters__);
}

// File Line: 142
// RVA: 0x522E30
bool __fastcall UFG::CloseTargetsSort(UFG::WeaponManager::WeaponEntry *a, UFG::WeaponManager::WeaponEntry *b)
{
  return a->mScore < b->mScore;
}

// File Line: 156
// RVA: 0x522A40
bool __fastcall UFG::BiggerScoresAreBetter(UFG::ScoredTarget *a, UFG::ScoredTarget *b)
{
  return b->m_fScore < a->m_fScore;
}

// File Line: 184
// RVA: 0x538230
void __fastcall UFG::TargetingParameters::InitFromPropertySet(
        UFG::TargetingParameters *this,
        UFG::qPropertySet *properties)
{
  unsigned int v4; // eax
  UFG::qSymbolUC *v5; // rbx
  float *v6; // rbp
  float *v7; // r14
  float *v8; // r15
  float *v9; // r13
  float *v10; // r12
  float *v11; // rdx
  UFG::qSymbolUC *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  int v20; // eax
  int v21; // ecx
  int v22; // ecx
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // [rsp+20h] [rbp-58h]
  int *v26; // [rsp+28h] [rbp-50h]
  float *v27; // [rsp+30h] [rbp-48h]
  float *v28; // [rsp+88h] [rbp+10h]
  int *v29; // [rsp+90h] [rbp+18h]
  int *v30; // [rsp+98h] [rbp+20h]

  if ( properties )
  {
    v4 = _S31_0;
    if ( (_S31_0 & 1) == 0 )
    {
      _S31_0 |= 1u;
      UFG::qSymbol::create_from_string(&symBoneNameAimOrigin, "BoneNameAimOrigin");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symBoneNameAimOrigin__);
      v4 = _S31_0;
    }
    if ( (v4 & 2) == 0 )
    {
      _S31_0 = v4 | 2;
      UFG::qSymbol::create_from_string(&symAimDirectionYawClamp, "AimDirectionYawClamp");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAimDirectionYawClamp__);
      v4 = _S31_0;
    }
    if ( (v4 & 4) == 0 )
    {
      _S31_0 = v4 | 4;
      UFG::qSymbol::create_from_string(&symAimDirectionYawReset, "AimDirectionYawReset");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAimDirectionYawReset__);
      v4 = _S31_0;
    }
    if ( (v4 & 8) == 0 )
    {
      _S31_0 = v4 | 8;
      UFG::qSymbol::create_from_string(&symMaxPOITargetingRange, "MaxPOITargetingRange");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symMaxPOITargetingRange__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x10) == 0 )
    {
      _S31_0 = v4 | 0x10;
      UFG::qSymbol::create_from_string(&symAccuracyEvadeModifier, "AccuracyEvadeModifier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAccuracyEvadeModifier__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x20) == 0 )
    {
      _S31_0 = v4 | 0x20;
      UFG::qSymbol::create_from_string(&symDefaultAccuracyRate, "DefaultAccuracyRate");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDefaultAccuracyRate__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x40) == 0 )
    {
      _S31_0 = v4 | 0x40;
      UFG::qSymbol::create_from_string(&symFullyAccurateDamageMultiplier, "FullyAccurateDamageMultiplier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symFullyAccurateDamageMultiplier__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x80u) == 0 )
    {
      _S31_0 = v4 | 0x80;
      UFG::qSymbol::create_from_string(
        &symRequiredLevelForGunplayUpgradeSubTargeting,
        "RequiredLevelForGunplayUpgradeSubTargeting");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRequiredLevelForGunplayUpgradeSubTargeting__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x100) == 0 )
    {
      _S31_0 = v4 | 0x100;
      UFG::qSymbol::create_from_string(
        &symRequiredLevelForGunplayUpgradeMarksman,
        "RequiredLevelForGunplayUpgradeMarksman");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRequiredLevelForGunplayUpgradeMarksman__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x200) == 0 )
    {
      _S31_0 = v4 | 0x200;
      UFG::qSymbol::create_from_string(&symGunplayUpgradeMarksmanMultiplier, "GunplayUpgradeMarksmanMultiplier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symGunplayUpgradeMarksmanMultiplier__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x400) == 0 )
    {
      _S31_0 = v4 | 0x400;
      UFG::qSymbol::create_from_string(&symRequiredLevelForGunplayUpgradeDamage, "RequiredLevelForGunplayUpgradeDamage");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRequiredLevelForGunplayUpgradeDamage__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x800) == 0 )
    {
      _S31_0 = v4 | 0x800;
      UFG::qSymbol::create_from_string(&symGunplayUpgradeDamageMultiplier, "GunplayUpgradeDamageMultiplier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symGunplayUpgradeDamageMultiplier__);
      v4 = _S31_0;
    }
    if ( (v4 & 0x1000) == 0 )
    {
      _S31_0 = v4 | 0x1000;
      UFG::qSymbol::create_from_string(&symFlickTargetingAngularLimit, "FlickTargetingAngularLimit");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symFlickTargetingAngularLimit__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
           properties,
           (UFG::qArray<unsigned long,0> *)&symBoneNameAimOrigin,
           DEPTH_RECURSE);
    v28 = UFG::qPropertySet::Get<float>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symAimDirectionYawClamp,
            DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<float>(
           properties,
           (UFG::qArray<unsigned long,0> *)&symAimDirectionYawReset,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(
           properties,
           (UFG::qArray<unsigned long,0> *)&symMaxPOITargetingRange,
           DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(
           properties,
           (UFG::qArray<unsigned long,0> *)&symAccuracyEvadeModifier,
           DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<float>(
           properties,
           (UFG::qArray<unsigned long,0> *)&symDefaultAccuracyRate,
           DEPTH_RECURSE);
    v10 = UFG::qPropertySet::Get<float>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symFullyAccurateDamageMultiplier,
            DEPTH_RECURSE);
    v29 = UFG::qPropertySet::Get<long>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symRequiredLevelForGunplayUpgradeSubTargeting,
            DEPTH_RECURSE);
    v30 = UFG::qPropertySet::Get<long>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symRequiredLevelForGunplayUpgradeMarksman,
            DEPTH_RECURSE);
    v25 = UFG::qPropertySet::Get<float>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symGunplayUpgradeMarksmanMultiplier,
            DEPTH_RECURSE);
    v26 = UFG::qPropertySet::Get<long>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symRequiredLevelForGunplayUpgradeDamage,
            DEPTH_RECURSE);
    v27 = UFG::qPropertySet::Get<float>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symGunplayUpgradeDamageMultiplier,
            DEPTH_RECURSE);
    v11 = UFG::qPropertySet::Get<float>(
            properties,
            (UFG::qArray<unsigned long,0> *)&symFlickTargetingAngularLimit,
            DEPTH_RECURSE);
    v12 = &UFG::gNullQSymbolUC;
    if ( v5 )
      v12 = v5;
    this->m_BoneUIDAimOrigin = (UFG::qSymbolUC)v12->mUID;
    v13 = FLOAT_N1_0;
    if ( v28 )
      v14 = (float)(*v28 * 3.1415927) * 0.0055555557;
    else
      v14 = FLOAT_N1_0;
    this->m_fAimDirectionYawClamp = v14;
    if ( v6 )
      v15 = (float)(*v6 * 3.1415927) * 0.0055555557;
    else
      v15 = FLOAT_N1_0;
    this->m_fAimDirectionYawReset = v15;
    if ( v7 )
      v16 = *v7;
    else
      v16 = FLOAT_N1_0;
    this->m_fMaxPOITargetingRange = v16;
    if ( v8 )
      v17 = *v8;
    else
      v17 = FLOAT_N1_0;
    this->m_fAccuracyEvadeModifier = v17;
    if ( v10 )
      v18 = *v10;
    else
      v18 = *(float *)&FLOAT_1_0;
    this->m_fFullyAccurateDamageMultiplier = v18;
    if ( v9 )
      v19 = *v9;
    else
      v19 = FLOAT_N1_0;
    this->m_fDefaultAccuracyRate = v19;
    v20 = -1;
    if ( v29 )
      v21 = *v29;
    else
      v21 = -1;
    this->m_iRequiredLevelForGunplayUpgradeSubTargeting = v21;
    if ( v30 )
      v22 = *v30;
    else
      v22 = -1;
    this->m_iRequiredLevelForGunplayUpgradeMarksman = v22;
    if ( v25 )
      v23 = *v25;
    else
      v23 = FLOAT_N1_0;
    this->m_fGunplayUpgradeMarksmanMultiplier = v23;
    if ( v26 )
      v20 = *v26;
    this->m_iRequiredLevelForGunplayUpgradeDamage = v20;
    if ( v27 )
      v24 = *v27;
    else
      v24 = FLOAT_N1_0;
    this->m_fGunplayUpgradeDamageMultiplier = v24;
    if ( v11 )
      v13 = (float)(*v11 * 3.1415927) * 0.0055555557;
    this->m_fFlickTargetingAngularLimitRad = v13;
  }
}

// File Line: 261
// RVA: 0x522B70
void UFG::TargetingSystemPedBaseComponent::BuildCloseToTargetTable(void)
{
  float v0; // xmm6_4
  int v1; // ebx
  float *v2; // rdi
  float v3; // xmm0_4

  v0 = UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetExponent;
  v1 = 0;
  v2 = UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetArray;
  do
  {
    v3 = powf((float)v1++ * 0.11111111, v0);
    *v2++ = v3;
  }
  while ( (unsigned int)v1 < 0xA );
}

// File Line: 272
// RVA: 0x522B00
void UFG::TargetingSystemPedBaseComponent::BuildCloseToCenterTable(void)
{
  float v0; // xmm6_4
  int v1; // ebx
  float *v2; // rdi
  float v3; // xmm0_4

  v0 = UFG::TargetingSystemPedBaseComponent::ms_fCloseToCenterExponent;
  v1 = 0;
  v2 = UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterArray;
  do
  {
    v3 = powf((float)v1++ * 0.11111111, v0);
    *v2++ = v3;
  }
  while ( (unsigned int)v1 < 0xA );
}

// File Line: 283
// RVA: 0x550780
void UFG::TargetingSystemPedBaseComponent::StaticInit(void)
{
  UFG::qPropertySet *PropertySet; // rax

  if ( (_S30_0 & 1) == 0 )
  {
    _S30_0 |= 1u;
    UFG::qSymbol::create_from_string(&propSetName, "Targeting-TargetingParameters");
    atexit(UFG::TargetingParameters::Init_::_2_::_dynamic_atexit_destructor_for__symTargetingParametersPropertySet__);
  }
  PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
  UFG::TargetingParameters::InitFromPropertySet(
    &UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters,
    PropertySet);
  UFG::TargetingSystemPedBaseComponent::BuildCloseToTargetTable();
  UFG::TargetingSystemPedBaseComponent::BuildCloseToCenterTable();
}

// File Line: 333
// RVA: 0x519AE0
void __fastcall UFG::TargetingSystemPedBaseComponent::TargetingSystemPedBaseComponent(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::TargetingMap *pTargetingMap,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *mPrev; // rax

  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(this, pTargetingMap, name_uid, properties);
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0>::RebindingComponentHandle<UFG::AimingBaseComponent,0>(&this->m_pAimingBaseComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerComponent,0>(&this->m_pAICharacterControllerComponent);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&this->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(&this->m_pInterestPointUserComponent);
  this->m_pEquippedSOWPC.mPrev = &this->m_pEquippedSOWPC;
  this->m_pEquippedSOWPC.mNext = &this->m_pEquippedSOWPC;
  this->m_pEquippedSOWPC.m_pPointer = 0i64;
  this->m_TargetSteerToTaskList.mNode.mPrev = &this->m_TargetSteerToTaskList.mNode;
  this->m_TargetSteerToTaskList.mNode.mNext = &this->m_TargetSteerToTaskList.mNode;
  `eh vector constructor iterator(
    this->m_CachedPedsList.p,
    0x18ui64,
    80,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  this->m_CachedPedsList.size = 0;
  this->m_ClosePhysicalTargetsList.size = 0;
  mPrev = UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mPrev;
  UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mNext = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList;
  UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemPedBaseComponent::_TargetingSystemPedBaseComponentTypeUID,
    "TargetingSystemPedBaseComponent");
  UFG::TargetingSystemPedBaseComponent::initialize(this);
}

// File Line: 343
// RVA: 0x51CEA0
void __fastcall UFG::TargetingSystemPedBaseComponent::~TargetingSystemPedBaseComponent(
        UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *p_m_CachedPedsList; // rsi
  unsigned int *m_pBucketList; // rcx
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InterestPoint *m_pComponent; // rdi
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v7; // rdi
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *p_m_pEquippedSOWPC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v15; // rcx
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v16; // rax

  this->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable{for `UFG::UpdateInterface};
  p_m_CachedPedsList = &this->m_CachedPedsList;
  this->m_CachedPedsList.size = 0;
  m_pBucketList = this->m_pBucketList;
  if ( m_pBucketList )
  {
    --m_pBucketList[this->m_uUpdateBucket];
    this->m_pBucketList = 0i64;
  }
  m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[26]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPoint *)m_pPointer->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::InterestPoint *)m_pPointer->m_Components.p[10].m_pComponent;
      else
        m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                            ? m_pPointer->m_Components.p[3].m_pComponent
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::InterestPoint::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::InterestPoint *)m_pPointer->m_Components.p[25].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::InterestPoint::FinishUsing(m_pComponent);
      UFG::InterestPoint::EndReservation(m_pComponent);
    }
  }
  p_m_CachedPedsList->size = 0;
  this->m_ClosePhysicalTargetsList.size = 0;
  if ( this == UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentpCurrentIterator )
    UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentpCurrentIterator = (UFG::TargetingSystemPedBaseComponent *)&this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mPrev[-8].mNext;
  v7 = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mPrev;
  mNext = this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  this->m_ClosePhysicalTargetsList.size = 0;
  p_m_CachedPedsList->size = 0;
  `eh vector destructor iterator(
    p_m_CachedPedsList->p,
    0x18ui64,
    80,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_TargetSteerToTaskList);
  p_m_pEquippedSOWPC = &this->m_pEquippedSOWPC;
  if ( this->m_pEquippedSOWPC.m_pPointer )
  {
    v11 = p_m_pEquippedSOWPC->mPrev;
    v12 = this->m_pEquippedSOWPC.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_pEquippedSOWPC->mPrev = p_m_pEquippedSOWPC;
    this->m_pEquippedSOWPC.mNext = &this->m_pEquippedSOWPC;
  }
  this->m_pEquippedSOWPC.m_pPointer = 0i64;
  v13 = p_m_pEquippedSOWPC->mPrev;
  v14 = this->m_pEquippedSOWPC.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_pEquippedSOWPC->mPrev = p_m_pEquippedSOWPC;
  this->m_pEquippedSOWPC.mNext = &this->m_pEquippedSOWPC;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pInterestPointUserComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAICharacterControllerComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAimingBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_pTransformNodeComponent);
  v15 = v7->mPrev;
  v16 = this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v7->mPrev = v7;
  this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent>;
  UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent(this);
}

// File Line: 369
// RVA: 0x56A0D0
void __fastcall UFG::TargetingSystemPedBaseComponent::initialize(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *p_m_pEquippedSOWPC; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4

  p_m_pEquippedSOWPC = &this->m_pEquippedSOWPC;
  if ( this->m_pEquippedSOWPC.m_pPointer )
  {
    mPrev = p_m_pEquippedSOWPC->mPrev;
    mNext = this->m_pEquippedSOWPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pEquippedSOWPC->mPrev = p_m_pEquippedSOWPC;
    this->m_pEquippedSOWPC.mNext = &this->m_pEquippedSOWPC;
  }
  this->m_pEquippedSOWPC.m_pPointer = 0i64;
  this->m_pActiveTargetingProfile = UFG::TargetingProfiles::ms_TargetingProfilePool.p;
  this->m_bForceUpdate = 1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vTargetingPosition.x = UFG::qVector3::msZero.x;
  this->m_vTargetingPosition.y = y;
  this->m_vTargetingPosition.z = z;
  v6 = UFG::qVector3::msDirFront.y;
  v7 = UFG::qVector3::msDirFront.z;
  this->m_vTargetingForward.x = UFG::qVector3::msDirFront.x;
  this->m_vTargetingForward.y = v6;
  this->m_vTargetingForward.z = v7;
  v8 = UFG::qVector3::msDirLeft.y;
  v9 = UFG::qVector3::msDirLeft.z;
  this->m_vTargetingLeft.x = UFG::qVector3::msDirLeft.x;
  this->m_vTargetingLeft.y = v8;
  this->m_vTargetingLeft.z = v9;
  v10 = UFG::qVector3::msDirFront.y;
  v11 = UFG::qVector3::msDirFront.z;
  this->m_vTargetingIntention.x = UFG::qVector3::msDirFront.x;
  this->m_vTargetingIntention.y = v10;
  this->m_vTargetingIntention.z = v11;
  *(_WORD *)&this->m_bHasRangedWeapon = 256;
  this->m_fMinimumTargetDistanceSquared = 0.0;
  this->m_pFocusTargetSubTargetingLocation = 0i64;
  this->m_pLastFocusTargetSubTargetingLocation = 0i64;
  this->m_pFocusTargetSubTargetingLocationOverride = 0i64;
  this->m_pLastFocusTarget = 0i64;
  this->m_uUpdateBucket = 0;
  this->m_pBucketList = 0i64;
}

// File Line: 438
// RVA: 0x53C440
bool __fastcall UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qVector3 *vMeToTarget,
        const float fHalfVerticalFOV,
        const float fExtraPositivePitch,
        float fExtraNegativePitch)
{
  float x; // xmm5_4
  __m128 y_low; // xmm4
  __m128 v9; // xmm1
  float v10; // xmm2_4
  UFG::qVector3 axis; // [rsp+18h] [rbp-71h] BYREF
  UFG::qMatrix44 dest; // [rsp+28h] [rbp-61h] BYREF
  UFG::qMatrix44 v14; // [rsp+68h] [rbp-21h] BYREF
  float v15; // [rsp+108h] [rbp+7Fh]

  x = vMeToTarget->x;
  y_low = (__m128)LODWORD(vMeToTarget->y);
  v9 = y_low;
  v9.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
  if ( v9.m128_f32[0] <= 0.001 )
    return 0;
  v10 = v9.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
  axis.z = (float)((float)(y_low.m128_f32[0] * v10) * 0.0) - (float)((float)(x * v10) * 0.0);
  UFG::qRotationMatrixAxis(&dest, &axis, fHalfVerticalFOV + fExtraPositivePitch);
  if ( (float)((float)((float)((float)((float)((float)(dest.v0.x + dest.v1.x) * 0.0) - (float)(dest.v2.x * 1.0))
                             * vMeToTarget->x)
                     + (float)((float)((float)((float)(dest.v0.y + dest.v1.y) * 0.0) - (float)(dest.v2.y * 1.0))
                             * vMeToTarget->y))
             + (float)((float)((float)((float)(dest.v0.z + dest.v1.z) * 0.0) - (float)(dest.v2.z * 1.0)) * vMeToTarget->z)) < 0.0 )
    return 0;
  UFG::qRotationMatrixAxis(&v14, &axis, COERCE_FLOAT(COERCE_UNSIGNED_INT(fHalfVerticalFOV + v15) ^ _xmm[0]));
  return (float)((float)((float)((float)((float)((float)(v14.v0.x + v14.v1.x) * 0.0) + v14.v2.x) * vMeToTarget->x)
                       + (float)((float)((float)((float)(v14.v0.y + v14.v1.y) * 0.0) + v14.v2.y) * vMeToTarget->y))
               + (float)((float)((float)((float)(v14.v0.z + v14.v1.z) * 0.0) + v14.v2.z) * vMeToTarget->z)) >= 0.0;
}

// File Line: 486
// RVA: 0x569CD0
float __fastcall UFG::TargetingSystemPedBaseComponent::getTargetConsiderationDistanceSquared(
        UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  float v2; // xmm0_4
  float result; // xmm0_4

  m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
  if ( m_pPointer )
  {
    v2 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                    + HIDWORD(m_pPointer[2].m_pSimObject))
                  + 40i64);
    result = v2 * v2;
  }
  else
  {
    result = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  if ( this->m_fMinimumTargetDistanceSquared > result )
    return this->m_fMinimumTargetDistanceSquared;
  return result;
}

// File Line: 498
// RVA: 0x569C90
float __fastcall UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared(
        UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  float v2; // xmm0_4

  m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
  if ( !m_pPointer )
    return this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  v2 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                  + HIDWORD(m_pPointer[2].m_pSimObject))
                + 40i64);
  return v2 * v2;
}

// File Line: 567
// RVA: 0x56AA70
bool __fastcall UFG::TargetingSystemPedBaseComponent::isHostileToMe(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::SimObject *pOtherSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::AttackRightsComponent *m_pComponent; // rax
  unsigned int vfptr; // r9d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v8; // rdx
  unsigned int v9; // r9d
  unsigned int v10; // r10d
  unsigned int v11; // r9d
  unsigned int v12; // r10d
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rcx
  char *v15; // rax

  if ( !pOtherSimObject )
    return 0;
  m_Flags = pOtherSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::AttackRightsComponent *)pOtherSimObject->m_Components.p[46].m_pComponent;
    goto LABEL_27;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)pOtherSimObject[1].vfptr;
    size = pOtherSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v8 = &pOtherSimObject->m_Components.p[vfptr];
      while ( (v8->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
           || (UFG::AttackRightsComponent::_TypeUID & ~v8->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v8;
        if ( vfptr >= size )
        {
          m_pComponent = 0i64;
          goto LABEL_27;
        }
      }
LABEL_11:
      m_pComponent = (UFG::AttackRightsComponent *)v8->m_pComponent;
      goto LABEL_27;
    }
    goto LABEL_25;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v9 = (unsigned int)pOtherSimObject[1].vfptr;
    v10 = pOtherSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = &pOtherSimObject->m_Components.p[v9];
      while ( (v8->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
           || (UFG::AttackRightsComponent::_TypeUID & ~v8->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v9;
        ++v8;
        if ( v9 >= v10 )
        {
          m_pComponent = 0i64;
          goto LABEL_27;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_25;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v11 = (unsigned int)pOtherSimObject[1].vfptr;
    v12 = pOtherSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      v8 = &pOtherSimObject->m_Components.p[v11];
      while ( (v8->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
           || (UFG::AttackRightsComponent::_TypeUID & ~v8->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v11;
        ++v8;
        if ( v11 >= v12 )
          goto LABEL_25;
      }
      goto LABEL_11;
    }
LABEL_25:
    m_pComponent = 0i64;
    goto LABEL_27;
  }
  m_pComponent = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                 pOtherSimObject,
                                                 UFG::AttackRightsComponent::_TypeUID);
LABEL_27:
  if ( m_pComponent )
  {
    m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->m_pActiveAIEntityComponent.m_pSimComponent;
    if ( m_pSimComponent )
      return UFG::ActiveAIEntityComponent::IsEnemyOfMine(m_pSimComponent, m_pComponent);
    v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qPrintf("WARNING: TargetingSystemPedBaseComponent::isHostileToMe: %s not an AI or target is not an AI\n", v15);
  }
  return 0;
}

// File Line: 584
// RVA: 0x56A7C0
bool __fastcall UFG::TargetingSystemPedBaseComponent::isAlliedToMe(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::SimObject *pOtherSimObject)
{
  UFG::SimComponent *m_pComponent; // rdx
  signed __int16 m_Flags; // cx
  unsigned int m_TypeUID; // ecx
  unsigned int v6; // ecx
  unsigned int vfptr; // r9d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v9; // rdx
  unsigned int v10; // r9d
  unsigned int v11; // r10d
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::eFactionClassEnum mPrev; // edi
  UFG::eFactionClassEnum v14; // ebx
  UFG::GameStatTracker *v15; // rax

  if ( !pOtherSimObject )
    goto LABEL_2;
  m_Flags = pOtherSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pOtherSimObject->m_Components.p[3].m_pComponent;
    if ( m_pComponent )
    {
      m_TypeUID = m_pComponent->m_TypeUID;
      if ( ((m_TypeUID ^ UFG::SimObjectCharacterPropertiesComponent::_TypeUID) & 0xFE000000) == 0 )
      {
        if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
          m_pComponent = 0i64;
        goto LABEL_29;
      }
    }
LABEL_2:
    m_pComponent = 0i64;
    goto LABEL_29;
  }
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pOtherSimObject[1].vfptr;
      size = pOtherSimObject->m_Components.size;
      if ( vfptr >= size )
        goto LABEL_2;
      v9 = &pOtherSimObject->m_Components.p[vfptr];
      while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v9;
        if ( vfptr >= size )
        {
          m_pComponent = 0i64;
          goto LABEL_29;
        }
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(
                         pOtherSimObject,
                         UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_29;
      }
      v10 = (unsigned int)pOtherSimObject[1].vfptr;
      v11 = pOtherSimObject->m_Components.size;
      if ( v10 >= v11 )
        goto LABEL_2;
      v9 = &pOtherSimObject->m_Components.p[v10];
      while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v10;
        ++v9;
        if ( v10 >= v11 )
        {
          m_pComponent = 0i64;
          goto LABEL_29;
        }
      }
    }
    m_pComponent = v9->m_pComponent;
    goto LABEL_29;
  }
  m_pComponent = pOtherSimObject->m_Components.p[3].m_pComponent;
  if ( !m_pComponent )
    goto LABEL_2;
  v6 = m_pComponent->m_TypeUID;
  if ( ((v6 ^ UFG::SimObjectCharacterPropertiesComponent::_TypeUID) & 0xFE000000) != 0 )
    goto LABEL_2;
  if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v6 & 0x1FFFFFF) != 0 )
    m_pComponent = 0i64;
LABEL_29:
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( !m_pSimComponent || !m_pComponent )
    return 0;
  mPrev = (UFG::eFactionClassEnum)m_pSimComponent[3].m_SafePointerList.mNode.mPrev;
  v14 = (UFG::eFactionClassEnum)m_pComponent[3].m_SafePointerList.mNode.mPrev;
  v15 = UFG::FactionInterface::Get();
  return (unsigned int)UFG::FactionInterface::GetStanding(&v15->mFactionInterface, mPrev, v14) == 0;
}

// File Line: 625
// RVA: 0x567FA0
void __fastcall UFG::TargetingSystemPedBaseComponent::findCloseTargets(
        UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList,
        UFG::SimObject *pSimObjectToExclude,
        UFG::qVector3 *vTargetingPosition,
        float fMaximumTargetDistanceSquared)
{
  UFG::SimObjectPropertiesComponent *v7; // rbx
  UFG::SimObjectPropertiesComponent *v8; // rdi
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v11; // xmm2_4
  __int64 z_low; // rcx
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  float z; // r9d
  unsigned int v17; // r8d
  UFG::qVector4 *v18; // rdx
  __int64 size; // rax
  __int64 v20; // rcx
  UFG::qVector4 v21; // xmm2
  UFG::qVector4 v22; // xmm1
  UFG::qVector4 v23; // xmm0
  UFG::CloseTarget right; // [rsp+0h] [rbp-9CD0h] BYREF
  UFG::CloseTarget left[500]; // [rsp+50h] [rbp-9C80h] BYREF

  *(_QWORD *)&right.m_Xform.v2.z = -2i64;
  right.m_Xform.v3.z = 0.0;
  v7 = (UFG::SimObjectPropertiesComponent *)&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent,1,0> *)&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mNext[-4] != &UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList - 4 )
  {
    do
    {
      v8 = (UFG::SimObjectPropertiesComponent *)&v7->mNext[-4];
      if ( (v7->m_Flags & 3) == 1 )
      {
        m_pSimObject = v7->m_pSimObject;
        if ( m_pSimObject != pSimObjectToExclude && (v7->m_BitField.mBits[0] & 0x20) == 0 )
        {
          if ( m_pSimObject )
          {
            m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
            if ( m_pTransformNodeComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v11 = (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - vTargetingPosition->x)
                                  * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - vTargetingPosition->x))
                          + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - vTargetingPosition->y)
                                  * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - vTargetingPosition->y)))
                  + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - vTargetingPosition->z)
                          * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - vTargetingPosition->z));
              if ( v11 <= fMaximumTargetDistanceSquared && LODWORD(right.m_Xform.v3.z) < 0x1F4 )
              {
                z_low = LODWORD(right.m_Xform.v3.z);
                ++LODWORD(right.m_Xform.v3.z);
                left[z_low].m_fDistance2 = v11;
                left[z_low].m_pSimObjectPropertiesComponent = v7;
                v13 = m_pTransformNodeComponent->mWorldTransform.v1;
                v14 = m_pTransformNodeComponent->mWorldTransform.v2;
                v15 = m_pTransformNodeComponent->mWorldTransform.v3;
                left[z_low].m_Xform.v0 = m_pTransformNodeComponent->mWorldTransform.v0;
                left[z_low].m_Xform.v1 = v13;
                left[z_low].m_Xform.v2 = v14;
                left[z_low].m_Xform.v3 = v15;
              }
            }
          }
        }
      }
      v7 = v8;
    }
    while ( v8 != (UFG::SimObjectPropertiesComponent *)(&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList
                                                      - 4) );
  }
  UFG::qQuickSortImpl<UFG::CloseTarget,bool (*)(UFG::CloseTarget const &,UFG::CloseTarget const &)>(
    left,
    &right + SLODWORD(right.m_Xform.v3.z),
    (bool (__fastcall *)(UFG::CloseTarget *, UFG::CloseTarget *))UFG::CloseTargetsSort);
  closeTargetsList->size = 0;
  z = right.m_Xform.v3.z;
  v17 = 0;
  v18 = &left[0].m_Xform.v2;
  do
  {
    if ( v17 >= LODWORD(z) )
      break;
    size = closeTargetsList->size;
    v20 = size;
    closeTargetsList->size = size + 1;
    closeTargetsList->p[v20].m_fDistance2 = v18[-3].x;
    closeTargetsList->p[v20].m_pSimObjectPropertiesComponent = *(UFG::SimObjectPropertiesComponent **)&v18[-3].z;
    v21 = v18[-1];
    v22 = *v18;
    v23 = v18[1];
    closeTargetsList->p[v20].m_Xform.v0 = v18[-2];
    closeTargetsList->p[v20].m_Xform.v1 = v21;
    closeTargetsList->p[v20].m_Xform.v2 = v22;
    closeTargetsList->p[v20].m_Xform.v3 = v23;
    ++v17;
    v18 += 5;
  }
  while ( v17 < 0x64 );
}

// File Line: 711
// RVA: 0x567290
void __fastcall UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
        UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList,
        UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *cachedPedsList,
        UFG::qFixedArray<UFG::CloseTarget *,80> *filteredClosePedsList,
        UFG::qFixedArray<UFG::CloseTarget *,5> *filteredClosePickupsList,
        UFG::qFixedArray<UFG::CloseTarget *,5> *filteredClosePropsList,
        UFG::qFixedArray<UFG::CloseTarget *,20> *filteredCloseVehiclesList,
        UFG::qFixedArray<UFG::CloseTarget,100> *filteredCloseTargetsList)
{
  unsigned int v9; // ebp
  __int64 v10; // r14
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *v12; // r9
  UFG::CloseTarget *v13; // rdi
  UFG::SimObjectPropertiesComponent *m_pSimObjectPropertiesComponent; // rax
  int m_eSimObjectType; // ecx
  UFG::SimObjectProp *m_pSimObject; // rbx
  UFG::PhysicsMoverInterface *v17; // rcx
  unsigned int v18; // eax
  __int16 v19; // cx
  unsigned int v20; // r8d
  unsigned int v21; // r10d
  __int64 v22; // rdx
  UFG::PropInteractComponent *v23; // rax
  unsigned int v24; // r8d
  unsigned int v25; // r10d
  unsigned int v26; // eax
  __int64 v27; // rdx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  __int64 v32; // rdx
  __int16 v33; // cx
  UFG::CharacterAnimationComponent *v34; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int v36; // r8d
  unsigned int v37; // r10d
  __int64 v38; // rdx
  Creature *mCreature; // rax
  unsigned int v40; // eax
  unsigned int v41; // eax
  __int64 v42; // r8
  __int64 v43; // rdx
  bool v44; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v45; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v48; // rax
  __int64 v49; // rdx
  __int64 v50; // rcx
  UFG::qVector4 v51; // xmm3
  UFG::qVector4 v52; // xmm2
  UFG::qVector4 v53; // xmm1
  UFG::qFixedArray<UFG::CloseTarget,100> *v54; // [rsp+70h] [rbp+8h]
  unsigned int filteredClosePropsLista; // [rsp+90h] [rbp+28h]

  v54 = closeTargetsList;
  cachedPedsList->size = 0;
  filteredClosePedsList->size = 0;
  filteredClosePickupsList->size = 0;
  filteredClosePropsList->size = 0;
  filteredCloseVehiclesList->size = 0;
  filteredCloseTargetsList->size = 0;
  v9 = 0;
  v10 = 0i64;
  v12 = cachedPedsList;
  filteredClosePropsLista = closeTargetsList->size;
  if ( closeTargetsList->size )
  {
    while ( 1 )
    {
      v13 = &closeTargetsList->p[v10];
      m_pSimObjectPropertiesComponent = v13->m_pSimObjectPropertiesComponent;
      m_eSimObjectType = m_pSimObjectPropertiesComponent->m_eSimObjectType;
      m_pSimObject = (UFG::SimObjectProp *)m_pSimObjectPropertiesComponent->m_pSimObject;
      if ( m_eSimObjectType == 1 )
        break;
      if ( m_eSimObjectType > 1 )
      {
        if ( m_eSimObjectType <= 3 )
        {
          if ( UFG::TargetingSystemPedBaseComponent::ms_fMaxDistanceToPickup2 < v13->m_fDistance2 )
            goto LABEL_97;
          if ( !m_pSimObject )
            goto LABEL_97;
          m_Flags = m_pSimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
            goto LABEL_97;
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p[11].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
            size = m_pSimObject->m_Components.size;
            if ( mComponentTableEntryCount >= size )
            {
LABEL_54:
              m_pComponent = 0i64;
            }
            else
            {
              v32 = (__int64)&m_pSimObject->m_Components.p[mComponentTableEntryCount];
              while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                   || (UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) != 0 )
              {
                ++mComponentTableEntryCount;
                v32 += 16i64;
                if ( mComponentTableEntryCount >= size )
                  goto LABEL_54;
              }
              m_pComponent = *(UFG::SimComponent **)v32;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::InventoryItemComponent::_TypeUID);
          }
          if ( !m_pComponent
            || !LODWORD(m_pComponent[1].m_pSimObject)
            || SLODWORD(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) <= 0
            || *(_QWORD *)&m_pComponent[1].m_Flags )
          {
            goto LABEL_97;
          }
          v33 = m_pSimObject->m_Flags;
          if ( (v33 & 0x4000) != 0 )
          {
            v34 = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
            if ( !v34
              || ((UFG::CharacterAnimationComponent::_TypeUID ^ v34->m_TypeUID) & 0xFE000000) != 0
              || (UFG::CharacterAnimationComponent::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              goto LABEL_65;
            }
          }
          else
          {
            if ( v33 >= 0 )
            {
              if ( (v33 & 0x2000) != 0 )
              {
                ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
              }
              else
              {
                if ( (v33 & 0x1000) != 0 )
                {
                  v36 = m_pSimObject->mComponentTableEntryCount;
                  v37 = m_pSimObject->m_Components.size;
                  if ( v36 >= v37 )
                    goto LABEL_65;
                  v38 = (__int64)&m_pSimObject->m_Components.p[v36];
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v36;
                    v38 += 16i64;
                    if ( v36 >= v37 )
                    {
                      v34 = 0i64;
                      goto LABEL_83;
                    }
                  }
                  v34 = *(UFG::CharacterAnimationComponent **)v38;
                  goto LABEL_83;
                }
                ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                        m_pSimObject,
                                                                        UFG::CharacterAnimationComponent::_TypeUID);
              }
              v34 = ComponentOfType;
              goto LABEL_83;
            }
            v34 = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
            if ( !v34 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v34->m_TypeUID) & 0xFE000000) != 0 )
            {
LABEL_65:
              v34 = 0i64;
            }
            else if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              v34 = 0i64;
            }
          }
LABEL_83:
          if ( v34 )
          {
            mCreature = v34->mCreature;
            if ( mCreature )
            {
              if ( !mCreature->mIsAttached )
              {
                v40 = filteredClosePickupsList->size;
                if ( filteredClosePickupsList->size < 5 )
                {
                  filteredClosePickupsList->size = v40 + 1;
                  filteredClosePickupsList->p[v40] = v13;
                }
              }
            }
          }
          goto LABEL_97;
        }
        if ( m_eSimObjectType == 4 )
        {
          if ( !m_pSimObject )
            goto LABEL_39;
          v17 = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
          if ( !v17 )
            goto LABEL_13;
          if ( UFG::PhysicsMoverInterface::GetEngineDamage(v17) < 1.0 )
          {
            v18 = filteredCloseVehiclesList->size;
            if ( filteredCloseVehiclesList->size < 0x14 )
            {
              filteredCloseVehiclesList->size = v18 + 1;
              filteredCloseVehiclesList->p[v18] = v13;
            }
LABEL_13:
            if ( !m_pSimObject )
              goto LABEL_39;
            v19 = m_pSimObject->m_Flags;
            if ( (v19 & 0x4000) != 0 )
            {
              v20 = m_pSimObject->mComponentTableEntryCount;
              v21 = m_pSimObject->m_Components.size;
              if ( v20 < v21 )
              {
                v22 = (__int64)&m_pSimObject->m_Components.p[v20];
                while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                     || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v20;
                  v22 += 16i64;
                  if ( v20 >= v21 )
                    goto LABEL_20;
                }
                goto LABEL_21;
              }
LABEL_20:
              v23 = 0i64;
            }
            else if ( v19 >= 0 )
            {
              if ( (v19 & 0x2000) != 0 )
              {
                v23 = (UFG::PropInteractComponent *)m_pSimObject->m_Components.p[13].m_pComponent;
              }
              else if ( (v19 & 0x1000) != 0 )
              {
                v24 = m_pSimObject->mComponentTableEntryCount;
                v25 = m_pSimObject->m_Components.size;
                if ( v24 >= v25 )
                  goto LABEL_20;
                v22 = (__int64)&m_pSimObject->m_Components.p[v24];
                while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                     || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF) != 0 )
                {
                  ++v24;
                  v22 += 16i64;
                  if ( v24 >= v25 )
                  {
                    v23 = 0i64;
                    goto LABEL_34;
                  }
                }
LABEL_21:
                v23 = *(UFG::PropInteractComponent **)v22;
              }
              else
              {
                v23 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::PropInteractComponent::_TypeUID);
              }
            }
            else
            {
              v23 = (UFG::PropInteractComponent *)m_pSimObject->m_Components.p[33].m_pComponent;
            }
LABEL_34:
            if ( !v23 || v23->mInteractingSimObject.m_pPointer || UFG::PropInteractComponent::NotInteractable(v23) )
            {
LABEL_39:
              if ( filteredCloseVehiclesList->size )
              {
                v27 = filteredCloseVehiclesList->size - 1;
                if ( filteredCloseVehiclesList->p[v27]->m_pSimObjectPropertiesComponent->m_pSimObject == m_pSimObject )
                  filteredCloseVehiclesList->size = v27;
              }
              goto LABEL_97;
            }
            v26 = filteredClosePropsList->size;
            if ( filteredClosePropsList->size < 5 )
            {
              filteredClosePropsList->size = v26 + 1;
              filteredClosePropsList->p[v26] = v13;
            }
LABEL_95:
            v49 = filteredCloseTargetsList->size;
            if ( (unsigned int)v49 < 0x64 )
            {
              filteredCloseTargetsList->size = v49 + 1;
              v50 = v49;
              filteredCloseTargetsList->p[v50].m_fDistance2 = v13->m_fDistance2;
              filteredCloseTargetsList->p[v50].m_pSimObjectPropertiesComponent = v13->m_pSimObjectPropertiesComponent;
              v51 = v13->m_Xform.v1;
              v52 = v13->m_Xform.v2;
              v53 = v13->m_Xform.v3;
              filteredCloseTargetsList->p[v50].m_Xform.v0 = v13->m_Xform.v0;
              filteredCloseTargetsList->p[v50].m_Xform.v1 = v51;
              filteredCloseTargetsList->p[v50].m_Xform.v2 = v52;
              filteredCloseTargetsList->p[v50].m_Xform.v3 = v53;
            }
          }
        }
        else if ( m_eSimObjectType == 5 )
        {
          goto LABEL_13;
        }
      }
LABEL_97:
      v12 = cachedPedsList;
      closeTargetsList = v54;
      ++v9;
      ++v10;
      if ( v9 >= filteredClosePropsLista )
        return;
    }
    v41 = filteredClosePedsList->size;
    if ( filteredClosePedsList->size < 0x50 )
    {
      filteredClosePedsList->size = v41 + 1;
      filteredClosePedsList->p[v41] = v13;
    }
    v42 = v12->size;
    if ( (unsigned int)v42 < 0x50 )
    {
      v43 = v42 + 2 * v42 + 1;
      v12->size = v42 + 1;
      v44 = *((_QWORD *)&v12->p[0].mNext + v43) == 0i64;
      v45 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)((char *)v12 + 8 * v43);
      if ( !v44 )
      {
        mPrev = v45->mPrev;
        mNext = v45->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v45->mPrev = v45;
        v45->mNext = v45;
      }
      v45[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)m_pSimObject;
      if ( m_pSimObject )
      {
        v48 = m_pSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v48->mNext = v45;
        v45->mPrev = v48;
        v45->mNext = &m_pSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        m_pSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v45;
      }
    }
    goto LABEL_95;
  }
}

// File Line: 871
// RVA: 0x56AF80
bool __fastcall UFG::TargetingSystemPedBaseComponent::isScripted(UFG::SimObject *pSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v5; // rdx

  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::StreamedResourceComponent *)pSimObject->m_Components.p[10].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_14:
        m_pComponent = 0i64;
      }
      else
      {
        v5 = &pSimObject->m_Components.p[vfptr];
        while ( (v5->m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
             || (UFG::StreamedResourceComponent::_TypeUID & ~v5->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v5;
          if ( vfptr >= size )
            goto LABEL_14;
        }
        m_pComponent = (UFG::StreamedResourceComponent *)v5->m_pComponent;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                         pSimObject,
                                                         UFG::StreamedResourceComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = (UFG::StreamedResourceComponent *)pSimObject->m_Components.p[10].m_pComponent;
  }
  return m_pComponent
      && UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID == qSymbol_Critical.mUID;
}

// File Line: 948
// RVA: 0x567AC0
void __fastcall UFG::TargetingSystemPedBaseComponent::findClosePhysicalTargets(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *closePhysicalTargetsList,
        UFG::SimObject *pSimObjectToExclude,
        float fMaximumTargetDistanceSquared)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v13; // rdx
  unsigned int v14; // r8d
  unsigned int v15; // r9d
  UFG::SimObject *v16; // rax
  __int16 v17; // dx
  unsigned int v18; // r9d
  unsigned int v19; // r10d
  __int64 v20; // rdx
  UFG::RigidBody *ComponentOfType; // rbx
  unsigned int v22; // r9d
  unsigned int v23; // r10d
  unsigned int v24; // r9d
  unsigned int v25; // r10d
  unsigned int v26; // r9d
  unsigned int v27; // r10d
  float v28; // xmm2_4
  __int64 v29; // rax
  unsigned int v30; // r9d
  unsigned int v31; // edx
  ClassTypeDescriptor *v32; // r8
  __int64 v33; // rcx
  UFG::SensorPhantomIterator v34; // [rsp+20h] [rbp-1FC8h] BYREF
  __int64 v35; // [rsp+38h] [rbp-1FB0h]
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-1FA8h] BYREF
  unsigned int v37; // [rsp+80h] [rbp-1F68h]
  ClassTypeDescriptor left[500]; // [rsp+88h] [rbp-1F60h] BYREF

  v35 = -2i64;
  v37 = 0;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_60;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[26].m_pComponent;
    goto LABEL_23;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[26].m_pComponent;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v13 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && (UFG::SensorComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_14;
      }
LABEL_13:
      m_pComponent = p[v13].m_pComponent;
      goto LABEL_23;
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v14 = (unsigned int)m_pSimObject[1].vfptr;
    v15 = m_pSimObject->m_Components.size;
    if ( v14 < v15 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v13 = v14;
        if ( (p[v14].m_TypeUID & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && (UFG::SensorComponent::_TypeUID & ~p[v14].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_13;
        }
        if ( ++v14 >= v15 )
          goto LABEL_14;
      }
    }
    goto LABEL_14;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::SensorComponent::_TypeUID);
LABEL_23:
  if ( m_pComponent )
  {
    UFG::SensorPhantomIterator::SensorPhantomIterator(
      &v34,
      (UFG::SensorPhantom *)m_pComponent[1].m_SafePointerList.mNode.mNext,
      0);
    if ( UFG::SensorPhantomIterator::operator*(&v34) )
    {
      while ( 1 )
      {
        v16 = (UFG::SimObject *)UFG::SensorPhantomIterator::operator*(&v34);
        if ( v16 )
        {
          if ( v16 != pSimObjectToExclude )
            break;
        }
LABEL_58:
        UFG::SensorPhantomIterator::operator++(&v34);
        if ( !UFG::SensorPhantomIterator::operator*(&v34) )
          goto LABEL_59;
      }
      v17 = v16->m_Flags;
      if ( (v17 & 0x4000) != 0 )
      {
        v18 = (unsigned int)v16[1].vfptr;
        v19 = v16->m_Components.size;
        if ( v18 < v19 )
        {
          while ( 1 )
          {
            v20 = (__int64)&v16->m_Components.p[v18];
            if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) == 0 )
            {
              break;
            }
            if ( ++v18 >= v19 )
              goto LABEL_34;
          }
LABEL_33:
          ComponentOfType = *(UFG::RigidBody **)v20;
LABEL_54:
          if ( ComponentOfType )
          {
            UFG::RigidBody::GetTransform(ComponentOfType, &mat);
            v28 = (float)((float)((float)(mat.v3.y - this->m_vTargetingPosition.y)
                                * (float)(mat.v3.y - this->m_vTargetingPosition.y))
                        + (float)((float)(mat.v3.x - this->m_vTargetingPosition.x)
                                * (float)(mat.v3.x - this->m_vTargetingPosition.x)))
                + (float)((float)(mat.v3.z - this->m_vTargetingPosition.z)
                        * (float)(mat.v3.z - this->m_vTargetingPosition.z));
            if ( v28 <= fMaximumTargetDistanceSquared && v37 < 0x1F4 )
            {
              v29 = v37++;
              *(float *)&left[v29].mUID = v28;
              left[v29].mfnInPlaceNew = (void (__fastcall *)(void *))ComponentOfType;
            }
          }
          goto LABEL_58;
        }
      }
      else if ( v17 >= 0 )
      {
        if ( (v17 & 0x2000) != 0 )
        {
          v24 = (unsigned int)v16[1].vfptr;
          v25 = v16->m_Components.size;
          if ( v24 < v25 )
          {
            do
            {
              v20 = (__int64)&v16->m_Components.p[v24];
              if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) == 0 )
              {
                goto LABEL_33;
              }
            }
            while ( ++v24 < v25 );
          }
        }
        else
        {
          if ( (v17 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  v16,
                                                  UFG::RigidBodyComponent::_TypeUID);
            goto LABEL_54;
          }
          v26 = (unsigned int)v16[1].vfptr;
          v27 = v16->m_Components.size;
          if ( v26 < v27 )
          {
            do
            {
              v20 = (__int64)&v16->m_Components.p[v26];
              if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) == 0 )
              {
                goto LABEL_33;
              }
            }
            while ( ++v26 < v27 );
          }
        }
      }
      else
      {
        v22 = (unsigned int)v16[1].vfptr;
        v23 = v16->m_Components.size;
        if ( v22 < v23 )
        {
          do
          {
            v20 = (__int64)&v16->m_Components.p[v22];
            if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) == 0 )
            {
              goto LABEL_33;
            }
          }
          while ( ++v22 < v23 );
        }
      }
LABEL_34:
      ComponentOfType = 0i64;
      goto LABEL_54;
    }
LABEL_59:
    UFG::SensorPhantomIterator::~SensorPhantomIterator(&v34);
  }
LABEL_60:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    left,
    (ClassTypeDescriptor *)&mat.v3.z + (int)v37,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
  closePhysicalTargetsList->size = 0;
  v30 = v37;
  v31 = 0;
  v32 = left;
  do
  {
    if ( v31 >= v30 )
      break;
    v33 = closePhysicalTargetsList->size++;
    *(_QWORD *)&closePhysicalTargetsList->p[v33].m_fDistance2 = *(_QWORD *)&v32->mUID;
    closePhysicalTargetsList->p[v33].m_pRigidBodyComponent = (UFG::RigidBodyComponent *)v32->mfnInPlaceNew;
    ++v31;
    ++v32;
  }
  while ( v31 < 0xA );
}++;
    *(_QWORD *)&closePhysicalTargetsList->p[v33].m_fDistance2 = *(_

// File Line: 1028
// RVA: 0x567140
void __fastcall UFG::TargetingSystemPedBaseComponent::filterClosePhysicalTargets(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *closePhysicalTargetsList,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,2> *closePhysicalDodgeableList,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,1> *closePhysicalMeleeAttackableList,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *filteredClosePhysicalTargetsList)
{
  UFG::ClosePhysicalTarget *p; // rdi
  __int64 size; // rbp
  UFG::RigidBodyComponent *m_pRigidBodyComponent; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v10; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::qReflectObject *mData; // rax
  unsigned int v14; // edx
  __int64 v15; // rcx
  unsigned int v16; // edx
  __int64 v17; // rcx
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-40h] BYREF

  filteredClosePhysicalTargetsList->size = 0;
  if ( closePhysicalTargetsList->size )
  {
    p = closePhysicalTargetsList->p;
    size = closePhysicalTargetsList->size;
    do
    {
      m_pRigidBodyComponent = p->m_pRigidBodyComponent;
      UFG::qReflectHandleBase::qReflectHandleBase(&v18);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v10);
      v18.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = m_pRigidBodyComponent->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v18, &mCollisionMeshData->mObjectProperties);
      mData = v18.mData;
      if ( v18.mData )
      {
        if ( BYTE3(v18.mData[2].vfptr) )
        {
          v14 = closePhysicalDodgeableList->size;
          if ( closePhysicalDodgeableList->size < 2 )
          {
            v15 = v14;
            closePhysicalDodgeableList->size = v14 + 1;
            *(_QWORD *)&closePhysicalDodgeableList->p[v15].m_fDistance2 = *(_QWORD *)&p->m_fDistance2;
            closePhysicalDodgeableList->p[v15].m_pRigidBodyComponent = p->m_pRigidBodyComponent;
            mData = v18.mData;
          }
        }
        if ( BYTE4(mData[2].vfptr) && !closePhysicalMeleeAttackableList->size )
        {
          closePhysicalMeleeAttackableList->size = 1;
          *(_QWORD *)&closePhysicalMeleeAttackableList->p[0].m_fDistance2 = *(_QWORD *)&p->m_fDistance2;
          closePhysicalMeleeAttackableList->p[0].m_pRigidBodyComponent = p->m_pRigidBodyComponent;
        }
      }
      v16 = filteredClosePhysicalTargetsList->size;
      if ( filteredClosePhysicalTargetsList->size < 0xA )
      {
        v17 = v16;
        filteredClosePhysicalTargetsList->size = v16 + 1;
        *(_QWORD *)&filteredClosePhysicalTargetsList->p[v17].m_fDistance2 = *(_QWORD *)&p->m_fDistance2;
        filteredClosePhysicalTargetsList->p[v17].m_pRigidBodyComponent = p->m_pRigidBodyComponent;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
      ++p;
      --size;
    }
    while ( size );
  }
}

// File Line: 1095
// RVA: 0x576660
void __fastcall UFG::TargetingSystemPedBaseComponent::updatePhysicalTarget(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *closePhysicalTargetsList)
{
  UFG::TargetingSimObject *v3; // rcx
  UFG::RigidBodyComponent *m_pRigidBodyComponent; // rbx
  UFG::SimObject *m_pSimObject; // rdx
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl
  unsigned __int64 v8; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-48h] BYREF

  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[49]];
  if ( !v3->m_pTarget.m_pPointer || !v3->m_bLock )
  {
    if ( closePhysicalTargetsList->size
      && (m_pRigidBodyComponent = closePhysicalTargetsList->p[0].m_pRigidBodyComponent,
          UFG::RigidBody::GetTransform(m_pRigidBodyComponent, &mat),
          (m_pSimObject = m_pRigidBodyComponent->m_pSimObject) != 0i64) )
    {
      v6 = this->m_pTargetingMap->m_Map.p[49];
      if ( v6 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v6], m_pSimObject);
    }
    else
    {
      v7 = this->m_pTargetingMap->m_Map.p[49];
      if ( v7 )
      {
        v8 = v7;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v8], 0i64);
        m_pTargets = this->m_pTargets;
        if ( m_pTargets[v8].m_bLock )
          m_pTargets[v8].m_bLock = 0;
      }
    }
  }
}

// File Line: 1146
// RVA: 0x570670
void __fastcall UFG::TargetingSystemPedBaseComponent::updateCloseVehiclesList(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::CloseTarget,20> *closeTargetsList,
        UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::SimObject *m_pSimObject; // r13
  UFG::PhysicsMoverInterface *i; // rdi
  UFG::SimObject *v8; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v13; // rdx
  UFG::qVector4 *m_pTransformNodeComponent; // rsi
  float v15; // xmm6_4
  __int16 v16; // cx
  UFG::SimObjectPropertiesComponent *ComponentOfType; // rax
  unsigned int v18; // r8d
  unsigned int v19; // r9d
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // rdx
  UFG::qVector4 v23; // xmm3
  UFG::qVector4 v24; // xmm2
  UFG::qVector4 v25; // xmm1
  UFG::CloseTarget *p; // rbx
  __int64 v27; // rcx

  m_pSimObject = this->m_pSimObject;
  for ( i = (UFG::PhysicsMoverInterface *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
        i != (UFG::PhysicsMoverInterface *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72);
        i = (UFG::PhysicsMoverInterface *)&i->mNext[-5].mNext )
  {
    if ( (i->m_Flags & 3) == 1
      && i->m_pSimObject != m_pSimObject
      && UFG::PhysicsMoverInterface::GetEngineDamage(i) < 1.0 )
    {
      v8 = i->m_pSimObject;
      if ( v8 )
      {
        m_Flags = v8->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v8->m_Components.p[3].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = v8->m_Components.p[4].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            vfptr = (unsigned int)v8[1].vfptr;
            size = v8->m_Components.size;
            if ( vfptr >= size )
            {
LABEL_18:
              m_pComponent = 0i64;
            }
            else
            {
              v13 = (__int64)&v8->m_Components.p[vfptr];
              while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
                   || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF) != 0 )
              {
                ++vfptr;
                v13 += 16i64;
                if ( vfptr >= size )
                  goto LABEL_18;
              }
              m_pComponent = *(UFG::SimComponent **)v13;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(
                             i->m_pSimObject,
                             UFG::SimObjectPropertiesComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = v8->m_Components.p[3].m_pComponent;
        }
        if ( !m_pComponent || (m_pComponent[1].m_Flags & 0x20) == 0 )
        {
          m_pTransformNodeComponent = (UFG::qVector4 *)v8->m_pTransformNodeComponent;
          if ( m_pTransformNodeComponent )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v8->m_pTransformNodeComponent);
            v15 = (float)((float)((float)(m_pTransformNodeComponent[11].x - this->m_vTargetingPosition.x)
                                * (float)(m_pTransformNodeComponent[11].x - this->m_vTargetingPosition.x))
                        + (float)((float)(m_pTransformNodeComponent[11].y - this->m_vTargetingPosition.y)
                                * (float)(m_pTransformNodeComponent[11].y - this->m_vTargetingPosition.y)))
                + (float)((float)(m_pTransformNodeComponent[11].z - this->m_vTargetingPosition.z)
                        * (float)(m_pTransformNodeComponent[11].z - this->m_vTargetingPosition.z));
            if ( v15 <= UFG::TargetingSystemPedBaseComponent::getTargetConsiderationDistanceSquared(this)
              && closeTargetsList->size < 0x14 )
            {
              v16 = v8->m_Flags;
              if ( (v16 & 0x4000) != 0 )
              {
                ComponentOfType = (UFG::SimObjectPropertiesComponent *)v8->m_Components.p[3].m_pComponent;
              }
              else if ( v16 >= 0 )
              {
                if ( (v16 & 0x2000) != 0 )
                {
                  ComponentOfType = (UFG::SimObjectPropertiesComponent *)v8->m_Components.p[4].m_pComponent;
                }
                else if ( (v16 & 0x1000) != 0 )
                {
                  v18 = (unsigned int)v8[1].vfptr;
                  v19 = v8->m_Components.size;
                  if ( v18 >= v19 )
                  {
LABEL_38:
                    ComponentOfType = 0i64;
                  }
                  else
                  {
                    v20 = (__int64)&v8->m_Components.p[v18];
                    while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
                         || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++v18;
                      v20 += 16i64;
                      if ( v18 >= v19 )
                        goto LABEL_38;
                    }
                    ComponentOfType = *(UFG::SimObjectPropertiesComponent **)v20;
                  }
                }
                else
                {
                  ComponentOfType = (UFG::SimObjectPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                           v8,
                                                                           UFG::SimObjectPropertiesComponent::_TypeUID);
                }
              }
              else
              {
                ComponentOfType = (UFG::SimObjectPropertiesComponent *)v8->m_Components.p[3].m_pComponent;
              }
              if ( ComponentOfType )
              {
                v21 = closeTargetsList->size;
                v22 = v21;
                closeTargetsList->size = v21 + 1;
                closeTargetsList->p[v22].m_pSimObjectPropertiesComponent = ComponentOfType;
                closeTargetsList->p[v22].m_fDistance2 = v15;
                v23 = m_pTransformNodeComponent[9];
                v24 = m_pTransformNodeComponent[10];
                v25 = m_pTransformNodeComponent[11];
                closeTargetsList->p[v22].m_Xform.v0 = m_pTransformNodeComponent[8];
                closeTargetsList->p[v22].m_Xform.v1 = v23;
                closeTargetsList->p[v22].m_Xform.v2 = v24;
                closeTargetsList->p[v22].m_Xform.v3 = v25;
              }
            }
          }
        }
      }
    }
  }
  p = closeTargetsList->p;
  UFG::qQuickSortImpl<UFG::CloseTarget,bool (*)(UFG::CloseTarget const &,UFG::CloseTarget const &)>(
    closeTargetsList->p,
    (UFG::CloseTarget *)&closeTargetsList[-1].p[(int)closeTargetsList->size + 19].m_pSimObjectPropertiesComponent,
    (bool (__fastcall *)(UFG::CloseTarget *, UFG::CloseTarget *))UFG::CloseTargetsSort);
  closeVehiclesList->size = 0;
  if ( closeTargetsList->size )
  {
    v27 = closeTargetsList->size;
    do
    {
      closeVehiclesList->p[closeVehiclesList->size++] = p++;
      --v27;
    }
    while ( v27 );
  }
}

// File Line: 1216
// RVA: 0x55EC80
void __fastcall UFG::TargetingSystemPedBaseComponent::UpdateCommon(UFG::TargetingSystemPedBaseComponent *this)
{
  bool v2; // di
  UFG::SimObjectProp *m_pPointer; // rcx
  UFG::SimComponent *v4; // rdx
  __int16 m_Flags; // dx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  __int64 v8; // rdx
  unsigned int v9; // r8d
  unsigned int v10; // r10d
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  unsigned int v12; // r8d
  unsigned int v13; // r10d
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *p_m_pEquippedSOWPC; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectProp *v18; // rcx
  UFG::SimComponent *v19; // rdx
  __int16 v20; // dx
  unsigned int v21; // r8d
  unsigned int v22; // r10d
  __int64 v23; // rdx
  unsigned int v24; // r8d
  unsigned int v25; // r10d
  UFG::SimObjectWeaponPropertiesComponent *v26; // rax
  unsigned int v27; // r8d
  unsigned int v28; // r10d
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::SimObjectWeaponPropertiesComponent *v32; // rax
  bool v33; // zf
  UFG::SimComponent *m_pSimComponent; // rbx
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // eax
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4

  v2 = 0;
  m_pPointer = (UFG::SimObjectProp *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[18]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_2;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
    size = m_pPointer->m_Components.size;
    if ( mComponentTableEntryCount < size )
    {
      v8 = (__int64)&m_pPointer->m_Components.p[mComponentTableEntryCount];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++mComponentTableEntryCount;
        v8 += 16i64;
        if ( mComponentTableEntryCount >= size )
        {
          v4 = 0i64;
          goto LABEL_29;
        }
      }
LABEL_10:
      v4 = *(UFG::SimComponent **)v8;
      goto LABEL_29;
    }
    goto LABEL_2;
  }
  if ( m_Flags < 0 )
  {
    v9 = m_pPointer->mComponentTableEntryCount;
    v10 = m_pPointer->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (__int64)&m_pPointer->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
        {
          v4 = 0i64;
          goto LABEL_29;
        }
      }
      goto LABEL_10;
    }
LABEL_2:
    v4 = 0i64;
    goto LABEL_29;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
  }
  else
  {
    if ( (m_Flags & 0x1000) != 0 )
    {
      v12 = m_pPointer->mComponentTableEntryCount;
      v13 = m_pPointer->m_Components.size;
      if ( v12 < v13 )
      {
        v8 = (__int64)&m_pPointer->m_Components.p[v12];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v8 += 16i64;
          if ( v12 >= v13 )
          {
            v4 = 0i64;
            goto LABEL_29;
          }
        }
        goto LABEL_10;
      }
      goto LABEL_2;
    }
    ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  v4 = ComponentOfType;
LABEL_29:
  p_m_pEquippedSOWPC = &this->m_pEquippedSOWPC;
  if ( this->m_pEquippedSOWPC.m_pPointer )
  {
    mPrev = p_m_pEquippedSOWPC->mPrev;
    mNext = this->m_pEquippedSOWPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pEquippedSOWPC->mPrev = p_m_pEquippedSOWPC;
    this->m_pEquippedSOWPC.mNext = &this->m_pEquippedSOWPC;
  }
  this->m_pEquippedSOWPC.m_pPointer = v4;
  if ( v4 )
  {
    v17 = v4->m_SafePointerList.mNode.mPrev;
    v17->mNext = p_m_pEquippedSOWPC;
    p_m_pEquippedSOWPC->mPrev = v17;
    this->m_pEquippedSOWPC.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_pEquippedSOWPC;
  }
  if ( !this->m_pEquippedSOWPC.m_pPointer )
  {
    v18 = (UFG::SimObjectProp *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
    if ( !v18 )
    {
LABEL_35:
      v19 = 0i64;
LABEL_62:
      if ( this->m_pEquippedSOWPC.m_pPointer )
      {
        v29 = p_m_pEquippedSOWPC->mPrev;
        v30 = this->m_pEquippedSOWPC.mNext;
        v29->mNext = v30;
        v30->mPrev = v29;
        p_m_pEquippedSOWPC->mPrev = p_m_pEquippedSOWPC;
        this->m_pEquippedSOWPC.mNext = &this->m_pEquippedSOWPC;
      }
      this->m_pEquippedSOWPC.m_pPointer = v19;
      if ( v19 )
      {
        v31 = v19->m_SafePointerList.mNode.mPrev;
        v31->mNext = p_m_pEquippedSOWPC;
        p_m_pEquippedSOWPC->mPrev = v31;
        this->m_pEquippedSOWPC.mNext = &v19->m_SafePointerList.mNode;
        v19->m_SafePointerList.mNode.mPrev = p_m_pEquippedSOWPC;
      }
      goto LABEL_66;
    }
    v20 = v18->m_Flags;
    if ( (v20 & 0x4000) != 0 )
    {
      v21 = v18->mComponentTableEntryCount;
      v22 = v18->m_Components.size;
      if ( v21 >= v22 )
        goto LABEL_35;
      v23 = (__int64)&v18->m_Components.p[v21];
      while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v21;
        v23 += 16i64;
        if ( v21 >= v22 )
        {
          v19 = 0i64;
          goto LABEL_62;
        }
      }
    }
    else
    {
      if ( v20 >= 0 )
      {
        if ( (v20 & 0x2000) != 0 )
        {
          v26 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v18);
        }
        else
        {
          if ( (v20 & 0x1000) != 0 )
          {
            v27 = v18->mComponentTableEntryCount;
            v28 = v18->m_Components.size;
            if ( v27 >= v28 )
              goto LABEL_35;
            v23 = (__int64)&v18->m_Components.p[v27];
            while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v27;
              v23 += 16i64;
              if ( v27 >= v28 )
              {
                v19 = 0i64;
                goto LABEL_62;
              }
            }
            goto LABEL_43;
          }
          v26 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             v18,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        v19 = v26;
        goto LABEL_62;
      }
      v24 = v18->mComponentTableEntryCount;
      v25 = v18->m_Components.size;
      if ( v24 >= v25 )
        goto LABEL_35;
      v23 = (__int64)&v18->m_Components.p[v24];
      while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v24;
        v23 += 16i64;
        if ( v24 >= v25 )
        {
          v19 = 0i64;
          goto LABEL_62;
        }
      }
    }
LABEL_43:
    v19 = *(UFG::SimComponent **)v23;
    goto LABEL_62;
  }
LABEL_66:
  v32 = (UFG::SimObjectWeaponPropertiesComponent *)this->m_pEquippedSOWPC.m_pPointer;
  if ( v32
    && v32->mWeaponTypeInfo->mFireModes[v32->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID )
  {
    v2 = 1;
  }
  v33 = this->m_pTransformNodeComponent.m_pSimComponent == 0i64;
  this->m_bHasRangedWeapon = v2;
  if ( !v33 )
  {
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    v35 = (float)(UFG::TargetingSystemPedBaseComponent::ms_fTargetingPositionXOffset
                * *(float *)&m_pSimComponent[2].vfptr)
        + *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v36 = (float)(UFG::TargetingSystemPedBaseComponent::ms_fTargetingPositionXOffset
                * *((float *)&m_pSimComponent[2].vfptr + 1))
        + *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
    this->m_vTargetingPosition.z = (float)(UFG::TargetingSystemPedBaseComponent::ms_fTargetingPositionXOffset
                                         * *(float *)&m_pSimComponent[2].m_SafePointerList.mNode.mPrev)
                                 + *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    this->m_vTargetingPosition.x = v35;
    this->m_vTargetingPosition.y = v36;
    v37 = *(float *)&m_pSimComponent[2].vfptr;
    v38 = *(float *)&m_pSimComponent[2].m_SafePointerList.mNode.mPrev;
    this->m_vTargetingForward.y = *((float *)&m_pSimComponent[2].vfptr + 1);
    this->m_vTargetingForward.x = v37;
    this->m_vTargetingForward.z = v38;
    v39 = *((float *)&m_pSimComponent[2].m_SafePointerList.mNode.mNext + 1);
    v40 = *(float *)&m_pSimComponent[2].m_TypeUID;
    this->m_vTargetingLeft.x = *(float *)&m_pSimComponent[2].m_SafePointerList.mNode.mNext;
    this->m_vTargetingLeft.y = v39;
    this->m_vTargetingLeft.z = v40;
  }
}

// File Line: 1256
// RVA: 0x570C10
void __fastcall UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList)
{
  unsigned int size; // ebp
  unsigned int v3; // ebx
  UFG::CloseTarget **p; // rdi
  UFG::SimObject *m_pSimObject; // rsi
  UFG::ActionTreeComponent *m_pComponent; // rcx
  UFG::HealthComponent *v8; // rdx
  UFG::SimComponentHolder *v9; // rax
  unsigned __int8 v10; // cl
  unsigned __int64 v11; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v13; // cl

  size = closePedsList->size;
  v3 = 0;
  if ( !closePedsList->size )
    goto LABEL_8;
  p = closePedsList->p;
  while ( 1 )
  {
    m_pSimObject = (*p)->m_pSimObjectPropertiesComponent->m_pSimObject;
    if ( m_pSimObject )
    {
      v9 = m_pSimObject->m_Components.p;
      m_pComponent = (UFG::ActionTreeComponent *)v9[7].m_pComponent;
      v8 = (UFG::HealthComponent *)v9[6].m_pComponent;
    }
    else
    {
      m_pComponent = 0i64;
      v8 = 0i64;
    }
    if ( !UFG::IsDowned(m_pComponent, v8) )
      break;
    ++v3;
    ++p;
    if ( v3 >= size )
      goto LABEL_8;
  }
  if ( m_pSimObject )
  {
    v13 = this->m_pTargetingMap->m_Map.p[14];
    if ( v13 )
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v13], m_pSimObject);
  }
  else
  {
LABEL_8:
    v10 = this->m_pTargetingMap->m_Map.p[14];
    if ( v10 )
    {
      v11 = v10;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v11], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v11].m_bLock )
        m_pTargets[v11].m_bLock = 0;
    }
  }
}

// File Line: 1291
// RVA: 0x575EC0
void __fastcall UFG::TargetingSystemPedBaseComponent::updateGroupTargets(UFG::TargetingSystemPedBaseComponent *this)
{
  __int64 v2; // rdi
  UFG::SimObject *LeadersPair; // r15
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  UFG::GroupComponent *v5; // rsi
  UFG::GroupComponent *Leader; // rax
  UFG::GroupComponent *v7; // rbp
  UFG::PedSpawningInfo *SimObjectPtr; // r14
  unsigned int j; // ebx
  UFG::GroupComponent *Follower; // rcx
  __int16 v11; // cx
  UFG::PedFormationManagerComponent *mPrev; // rax
  unsigned int v13; // ecx
  unsigned int v14; // r9d
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *mNext; // rbx
  __int64 v16; // r8
  unsigned int mPedIndex; // ecx
  unsigned int v18; // r9d
  unsigned int v19; // ecx
  unsigned int v20; // r9d
  unsigned __int8 v21; // dl
  unsigned int i; // ebx
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::PedFormationManagerComponent *m_pComponent; // rax
  unsigned int v26; // edx
  unsigned int v27; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v29; // r8
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  unsigned int v32; // edx
  unsigned int v33; // r9d
  unsigned __int8 v34; // cl
  unsigned __int64 v35; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v37; // cl
  unsigned __int64 v38; // rbx
  UFG::TargetingSimObject *v39; // rax
  unsigned int v40; // esi
  unsigned int *v41; // r14
  UFG::GroupComponent **v42; // r15
  UFG::SimObject *v43; // rax
  unsigned __int8 v44; // dl
  unsigned __int64 v45; // rbx
  UFG::TargetingSimObject *v46; // rax
  _DWORD v47[4]; // [rsp+28h] [rbp-50h] BYREF
  int v48; // [rsp+38h] [rbp-40h]
  __int64 v49[4]; // [rsp+40h] [rbp-38h] BYREF

  v47[0] = 63;
  v47[1] = 64;
  v47[2] = 65;
  v47[3] = 66;
  v2 = 0i64;
  v48 = 0;
  LeadersPair = 0i64;
  GroupComponent = UFG::GroupComponent::GetGroupComponent((UFG::SimObjectGame *)this->m_pSimObject);
  v5 = (UFG::GroupComponent *)GroupComponent;
  if ( !GroupComponent )
    goto LABEL_73;
  Leader = UFG::GroupComponent::GetLeader((UFG::GroupComponent *)GroupComponent);
  v7 = Leader;
  if ( !Leader )
  {
    if ( !UFG::GroupComponent::IsLeader(v5) )
      goto LABEL_73;
    for ( i = 0; i < Scaleform::Render::Hairliner::GetMeshVertexCount(v5); ++i )
    {
      if ( (unsigned int)v2 < 4 )
      {
        v49[v2] = (__int64)UFG::GroupComponent::GetFollower(v5, i);
        v2 = (unsigned int)++v48;
      }
    }
    m_pSimObject = this->m_pSimObject;
    if ( !m_pSimObject )
      goto LABEL_73;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::PedFormationManagerComponent *)m_pSimObject->m_Components.p[33].m_pComponent;
      goto LABEL_71;
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          p = m_pSimObject->m_Components.p;
          do
          {
            v29 = vfptr;
            if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && (UFG::PedFormationManagerComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_54;
            }
          }
          while ( ++vfptr < size );
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = (UFG::PedFormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::PedFormationManagerComponent::_TypeUID);
LABEL_71:
          if ( m_pComponent )
            LeadersPair = UFG::PedFormationManagerComponent::GetLeadersPair(m_pComponent);
          goto LABEL_73;
        }
        v32 = (unsigned int)m_pSimObject[1].vfptr;
        v33 = m_pSimObject->m_Components.size;
        if ( v32 < v33 )
        {
          p = m_pSimObject->m_Components.p;
          do
          {
            v29 = v32;
            if ( (p[v32].m_TypeUID & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && (UFG::PedFormationManagerComponent::_TypeUID & ~p[v32].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_54;
            }
          }
          while ( ++v32 < v33 );
        }
      }
    }
    else
    {
      v26 = (unsigned int)m_pSimObject[1].vfptr;
      v27 = m_pSimObject->m_Components.size;
      if ( v26 < v27 )
      {
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v29 = v26;
          if ( (p[v26].m_TypeUID & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
            && (UFG::PedFormationManagerComponent::_TypeUID & ~p[v26].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v26 >= v27 )
            goto LABEL_55;
        }
LABEL_54:
        m_pComponent = (UFG::PedFormationManagerComponent *)p[v29].m_pComponent;
        goto LABEL_71;
      }
    }
LABEL_55:
    m_pComponent = 0i64;
    goto LABEL_71;
  }
  SimObjectPtr = UFG::GroupComponent::GetSimObjectPtr(Leader);
  if ( SimObjectPtr )
  {
    v49[0] = (__int64)v7;
    LODWORD(v2) = 1;
    v48 = 1;
    for ( j = 0; j < Scaleform::Render::Hairliner::GetMeshVertexCount(v7); ++j )
    {
      Follower = UFG::GroupComponent::GetFollower(v7, j);
      if ( v5 != Follower && (unsigned int)v2 < 4 )
      {
        v49[(unsigned int)v2] = (__int64)Follower;
        LODWORD(v2) = ++v48;
      }
    }
    v11 = WORD2(SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedInfoList>::mNext);
    if ( (v11 & 0x4000) != 0 )
    {
      mPrev = (UFG::PedFormationManagerComponent *)SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mNext[33].mPrev;
LABEL_35:
      if ( mPrev )
        LeadersPair = (UFG::SimObject *)UFG::PedFormationManagerComponent::GetFollowersPair(mPrev, this->m_pSimObject);
      v21 = this->m_pTargetingMap->m_Map.p[62];
      if ( v21 )
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v21], (UFG::SimObject *)SimObjectPtr);
      goto LABEL_76;
    }
    if ( v11 >= 0 )
    {
      if ( (v11 & 0x2000) != 0 )
      {
        mPedIndex = SimObjectPtr->mPedIndex;
        v18 = (unsigned int)SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mPrev;
        if ( mPedIndex < v18 )
        {
          mNext = SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mNext;
          do
          {
            v16 = mPedIndex;
            if ( ((__int64)mNext[mPedIndex].mNext & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && (UFG::PedFormationManagerComponent::_TypeUID & ~LODWORD(mNext[mPedIndex].mNext) & 0x1FFFFFF) == 0 )
            {
              goto LABEL_18;
            }
          }
          while ( ++mPedIndex < v18 );
        }
      }
      else
      {
        if ( (v11 & 0x1000) == 0 )
        {
          mPrev = (UFG::PedFormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)SimObjectPtr,
                                                         UFG::PedFormationManagerComponent::_TypeUID);
          goto LABEL_35;
        }
        v19 = SimObjectPtr->mPedIndex;
        v20 = (unsigned int)SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mPrev;
        if ( v19 < v20 )
        {
          mNext = SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mNext;
          do
          {
            v16 = v19;
            if ( ((__int64)mNext[v19].mNext & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && (UFG::PedFormationManagerComponent::_TypeUID & ~LODWORD(mNext[v19].mNext) & 0x1FFFFFF) == 0 )
            {
              goto LABEL_18;
            }
          }
          while ( ++v19 < v20 );
        }
      }
    }
    else
    {
      v13 = SimObjectPtr->mPedIndex;
      v14 = (unsigned int)SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mPrev;
      if ( v13 < v14 )
      {
        mNext = SimObjectPtr->UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo>::mNext;
        while ( 1 )
        {
          v16 = v13;
          if ( ((__int64)mNext[v13].mNext & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
            && (UFG::PedFormationManagerComponent::_TypeUID & ~LODWORD(mNext[v13].mNext) & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v13 >= v14 )
            goto LABEL_19;
        }
LABEL_18:
        mPrev = (UFG::PedFormationManagerComponent *)mNext[v16].mPrev;
        goto LABEL_35;
      }
    }
LABEL_19:
    mPrev = 0i64;
    goto LABEL_35;
  }
LABEL_73:
  v34 = this->m_pTargetingMap->m_Map.p[62];
  if ( v34 )
  {
    v35 = v34;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v35], 0i64);
    m_pTargets = this->m_pTargets;
    if ( m_pTargets[v35].m_bLock )
      m_pTargets[v35].m_bLock = 0;
  }
LABEL_76:
  v37 = this->m_pTargetingMap->m_Map.p[67];
  if ( LeadersPair )
  {
    if ( v37 )
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v37], LeadersPair);
  }
  else if ( v37 )
  {
    v38 = v37;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v38], 0i64);
    v39 = this->m_pTargets;
    if ( v39[v38].m_bLock )
      v39[v38].m_bLock = 0;
  }
  v40 = 0;
  v41 = v47;
  v42 = (UFG::GroupComponent **)v49;
  do
  {
    if ( v40 >= (unsigned int)v2 )
    {
      v44 = this->m_pTargetingMap->m_Map.p[*v41];
      if ( v44 )
      {
        v45 = v44;
        UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v45], 0i64);
        v46 = this->m_pTargets;
        if ( v46[v45].m_bLock )
          v46[v45].m_bLock = 0;
      }
    }
    else
    {
      v43 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(*v42);
      UFG::TargetingSystemBaseComponent::SetTarget(this, *v41, v43);
    }
    ++v40;
    ++v42;
    ++v41;
  }
  while ( v40 < 4 );
}

// File Line: 1430
// RVA: 0x576720
void __fastcall UFG::TargetingSystemPedBaseComponent::updatePickupTarget(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,5> *closePickupsList)
{
  UFG::TargetingSimObject *v3; // r8
  unsigned int size; // r14d
  unsigned int v5; // edi
  unsigned int v6; // r11d
  UFG::CloseTarget **p; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int v11; // r9d
  __int64 v12; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v14; // r8d
  unsigned int v15; // r9d
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  unsigned int v18; // r8d
  unsigned int v19; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  __int64 v21; // rax
  int v22; // eax
  unsigned __int8 v23; // cl
  unsigned __int64 v24; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v26; // cl

  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[41]];
  if ( !v3->m_pTarget.m_pPointer || !v3->m_bLock )
  {
    size = closePickupsList->size;
    v5 = 0;
    if ( closePickupsList->size )
    {
      v6 = UFG::GunComponent::_TypeUID;
      p = closePickupsList->p;
      do
      {
        m_pSimObject = (*p)->m_pSimObjectPropertiesComponent->m_pSimObject;
        if ( !m_pSimObject )
          break;
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          v11 = m_pSimObject->m_Components.size;
          if ( vfptr < v11 )
          {
            v12 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000)
                 || (v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v12 += 16i64;
              if ( vfptr >= v11 )
                goto LABEL_12;
            }
LABEL_13:
            ComponentOfType = *(UFG::SimComponent **)v12;
            goto LABEL_36;
          }
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            v16 = (unsigned int)m_pSimObject[1].vfptr;
            v17 = m_pSimObject->m_Components.size;
            if ( v16 < v17 )
            {
              v12 = (__int64)&m_pSimObject->m_Components.p[v16];
              while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000)
                   || (v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v16;
                v12 += 16i64;
                if ( v16 >= v17 )
                {
                  ComponentOfType = 0i64;
                  goto LABEL_36;
                }
              }
              goto LABEL_13;
            }
          }
          else
          {
            if ( (m_Flags & 0x1000) == 0 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, v6);
              v6 = UFG::GunComponent::_TypeUID;
              goto LABEL_36;
            }
            v18 = (unsigned int)m_pSimObject[1].vfptr;
            v19 = m_pSimObject->m_Components.size;
            if ( v18 < v19 )
            {
              v12 = (__int64)&m_pSimObject->m_Components.p[v18];
              while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000)
                   || (v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v18;
                v12 += 16i64;
                if ( v18 >= v19 )
                {
                  ComponentOfType = 0i64;
                  goto LABEL_36;
                }
              }
              goto LABEL_13;
            }
          }
        }
        else
        {
          v14 = (unsigned int)m_pSimObject[1].vfptr;
          v15 = m_pSimObject->m_Components.size;
          if ( v14 < v15 )
          {
            v12 = (__int64)&m_pSimObject->m_Components.p[v14];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000)
                 || (v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v14;
              v12 += 16i64;
              if ( v14 >= v15 )
              {
                ComponentOfType = 0i64;
                goto LABEL_36;
              }
            }
            goto LABEL_13;
          }
        }
LABEL_12:
        ComponentOfType = 0i64;
LABEL_36:
        if ( !ComponentOfType
          || ((mPrev = ComponentOfType[2].m_BoundComponentHandles.mNode.mNext[6].mPrev) == 0i64
            ? (v22 = 0)
            : (v21 = *(int *)(*((_QWORD *)&ComponentOfType[2].m_SafePointerList.mNode.mPrev[11].mPrev->mNext
                              + HIDWORD(ComponentOfType[2].m_SafePointerList.mNode.mPrev[10].mNext))
                            + 4i64),
               !LOBYTE(mPrev[58].mNext))
           || (_DWORD)v21 != LODWORD(mPrev[58].mPrev)
            ? (v22 = *((_DWORD *)&mPrev[5].mNext + v21 + 1))
            : (v22 = 1),
              v22 <= 0) )
        {
          v26 = this->m_pTargetingMap->m_Map.p[41];
          if ( v26 )
            UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v26], m_pSimObject);
          return;
        }
        ++v5;
        ++p;
      }
      while ( v5 < size );
    }
    v23 = this->m_pTargetingMap->m_Map.p[41];
    if ( v23 )
    {
      v24 = v23;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v24], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v24].m_bLock )
        m_pTargets[v24].m_bLock = 0;
    }
  }
}

// File Line: 1486
// RVA: 0x57B730
void __fastcall UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(
        UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::eTargetTypeEnum *v1; // r14
  __int64 v2; // r15
  UFG::eTargetTypeEnum *v4; // rdi
  __int64 v5; // rsi
  unsigned __int8 v6; // r8
  unsigned __int64 v7; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int m_TypeUID; // ecx
  unsigned int v13; // ecx
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  __int64 v16; // rbx
  unsigned int v17; // edx
  unsigned int v18; // r8d
  __int64 v19; // rdx
  UFG::SimObject *v20; // r8

  v1 = UFG::TargetingSystemBaseComponent::ms_eVehicleRoleTargetTypes;
  v2 = 7i64;
  v4 = UFG::TargetingSystemBaseComponent::ms_eVehicleRoleTargetTypes;
  v5 = 7i64;
  do
  {
    v6 = this->m_pTargetingMap->m_Map.p[*(unsigned int *)v4];
    if ( v6 )
    {
      v7 = v6;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v7], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v7].m_bLock )
        m_pTargets[v7].m_bLock = 0;
    }
    ++v4;
    --v5;
  }
  while ( v5 );
  m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[28]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( !m_pComponent )
        goto LABEL_11;
      m_TypeUID = m_pComponent->m_TypeUID;
      if ( ((m_TypeUID ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000) != 0
        || (UFG::TargetingSystemVehicleComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_11;
      }
LABEL_33:
      if ( m_pComponent )
      {
        do
        {
          v19 = *(unsigned int *)v1;
          v20 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(v19 + *(_QWORD *)&m_pComponent[1].m_Flags + 8)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
          if ( v20 )
            UFG::TargetingSystemBaseComponent::SetTarget(this, v19, v20);
          ++v1;
          --v2;
        }
        while ( v2 );
      }
      return;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        v13 = m_pComponent->m_TypeUID;
        if ( ((v13 ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::TargetingSystemVehicleComponent::_TypeUID & ~v13 & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_11;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pPointer[1].vfptr;
      size = m_pPointer->m_Components.size;
      if ( vfptr < size )
      {
        v16 = (__int64)&m_pPointer->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v16 += 16i64;
          if ( vfptr >= size )
          {
            m_pComponent = 0i64;
            goto LABEL_33;
          }
        }
LABEL_24:
        m_pComponent = *(UFG::SimComponent **)v16;
        goto LABEL_33;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemVehicleComponent::_TypeUID);
        goto LABEL_33;
      }
      v17 = (unsigned int)m_pPointer[1].vfptr;
      v18 = m_pPointer->m_Components.size;
      if ( v17 < v18 )
      {
        v16 = (__int64)&m_pPointer->m_Components.p[v17];
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v17;
          v16 += 16i64;
          if ( v17 >= v18 )
          {
            m_pComponent = 0i64;
            goto LABEL_33;
          }
        }
        goto LABEL_24;
      }
    }
LABEL_11:
    m_pComponent = 0i64;
    goto LABEL_33;
  }
}

// File Line: 1517
// RVA: 0x56C090
float __fastcall UFG::TargetingSystemPedBaseComponent::scoreBasic(
        const float fDistanceSquared,
        const float fMaxDistanceSquared,
        double fAngleDiffRad)
{
  float v3; // xmm0_4
  double v4; // xmm8_8
  double v5; // xmm1_8
  float v6; // xmm7_4

  v3 = fDistanceSquared / fMaxDistanceSquared;
  HIDWORD(v4) = HIDWORD(fAngleDiffRad);
  *(_QWORD *)&v5 = (unsigned int)FLOAT_1_0;
  *(float *)&v5 = 1.0 - v3;
  *(float *)&v4 = *(float *)&fAngleDiffRad * 0.31830987;
  v6 = (float)(1.0 - UFG::LinearTable<float>::GetValue(&UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetTable, v5))
     * UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias;
  return v6
       + (float)(UFG::LinearTable<float>::GetValue(&UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterTable, v4)
               * (float)(1.0 - UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias));
}

// File Line: 1540
// RVA: 0x567890
UFG::SimObject *__fastcall UFG::TargetingSystemPedBaseComponent::findBestTarget(
        UFG::qVector3 *vTargetingPosition,
        UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList,
        UFG::qVector3 *vTargetingIntention,
        float fMaxDistanceSquared,
        float angle)
{
  UFG::CloseTarget **p; // rdi
  __int64 size; // rsi
  void (__fastcall *m_pSimObject)(void *); // r15
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float y; // xmm1_4
  __int64 x_low; // xmm0_8
  float v15; // xmm0_4
  double v16; // xmm9_8
  int mfnInPlaceNew; // eax
  __int64 mfnInPlaceNew_low; // rbx
  double v19; // xmm1_8
  float v20; // xmm7_4
  UFG::SimObject *result; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-718h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-708h] BYREF
  __int64 v24; // [rsp+40h] [rbp-6F8h]
  ClassTypeDescriptor right; // [rsp+48h] [rbp-6F0h] BYREF
  ClassTypeDescriptor left[108]; // [rsp+58h] [rbp-6E0h] BYREF

  v24 = -2i64;
  LODWORD(right.mfnInPlaceNew) = 0;
  if ( closeVehiclesList->size )
  {
    p = closeVehiclesList->p;
    size = closeVehiclesList->size;
    while ( 1 )
    {
      m_pSimObject = (void (__fastcall *)(void *))(*p)->m_pSimObjectPropertiesComponent->m_pSimObject;
      v10 = (*p)->m_Xform.v3.z - vTargetingPosition->z;
      v11 = (*p)->m_Xform.v3.y - vTargetingPosition->y;
      v12 = (*p)->m_Xform.v3.x - vTargetingPosition->x;
      v1.x = v12;
      v1.y = v11;
      v1.z = 0.0;
      y = vTargetingIntention->y;
      v2.x = vTargetingIntention->x;
      x_low = LODWORD(v2.x);
      v2.y = y;
      v2.z = 0.0;
      v15 = UFG::qAngleBetween(&v1, &v2);
      HIDWORD(v16) = HIDWORD(x_low);
      if ( angle < v15 )
        goto LABEL_6;
      mfnInPlaceNew = (int)right.mfnInPlaceNew;
      if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
        break;
LABEL_7:
      ++p;
      if ( !--size )
        goto LABEL_10;
    }
    mfnInPlaceNew_low = LODWORD(right.mfnInPlaceNew);
    ++LODWORD(right.mfnInPlaceNew);
    *(float *)&v16 = v15 * 0.31830987;
    *(_QWORD *)&v19 = (unsigned int)FLOAT_1_0;
    *(float *)&v19 = 1.0
                   - (float)((float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10))
                           / fMaxDistanceSquared);
    v20 = (float)(1.0
                - UFG::LinearTable<float>::GetValue(&UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetTable, v19))
        * UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias;
    *(float *)&v19 = (float)((float)(1.0 - UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias)
                           * UFG::LinearTable<float>::GetValue(
                               &UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterTable,
                               v16))
                   + v20;
    left[mfnInPlaceNew_low].mfnInPlaceNew = m_pSimObject;
    left[mfnInPlaceNew_low].mUID = LODWORD(v19);
LABEL_6:
    mfnInPlaceNew = (int)right.mfnInPlaceNew;
    goto LABEL_7;
  }
  mfnInPlaceNew = (int)right.mfnInPlaceNew;
LABEL_10:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    left,
    &right + mfnInPlaceNew,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
  result = 0i64;
  if ( LODWORD(right.mfnInPlaceNew) )
    return (UFG::SimObject *)left[0].mfnInPlaceNew;
  return result;
}

// File Line: 1589
// RVA: 0x57BC40
void __fastcall UFG::TargetingSystemPedBaseComponent::updateVehicleTarget(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::TargetingMap *m_pTargetingMap; // rcx
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v5; // rbx
  UFG::SimObject *m_pPointer; // rbx
  __int64 v7; // rcx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx
  unsigned __int8 v13; // cl
  unsigned __int64 v14; // rbx
  UFG::TargetingSimObject *v15; // rax
  unsigned __int8 v16; // al

  m_pTargetingMap = this->m_pTargetingMap;
  m_pTargets = this->m_pTargets;
  v5 = (unsigned __int8)m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
  if ( m_pTargets[v5].m_pTarget.m_pPointer && m_pTargets[v5].m_bLock )
  {
    m_pPointer = m_pTargets[v5].m_pTarget.m_pPointer;
  }
  else
  {
    v7 = (unsigned __int8)m_pTargetingMap->m_Map.p[eTARGET_TYPE_FOCUS];
    m_pPointer = m_pTargets[v7].m_pTarget.m_pPointer;
    if ( m_pPointer && m_pTargets[v7].m_bLock )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[4].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pPointer[1].vfptr;
          size = m_pPointer->m_Components.size;
          if ( vfptr >= size )
          {
LABEL_18:
            m_pComponent = 0i64;
          }
          else
          {
            v12 = (__int64)&m_pPointer->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
                 || (UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v12 += 16i64;
              if ( vfptr >= size )
                goto LABEL_18;
            }
            m_pComponent = *(UFG::SimComponent **)v12;
          }
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
      }
      if ( m_pComponent && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) != 4 )
        goto LABEL_23;
    }
    else
    {
      m_pPointer = UFG::TargetingSystemPedBaseComponent::findBestTarget(
                     &this->m_vTargetingPosition,
                     closeVehiclesList,
                     &this->m_vTargetingIntention,
                     this->m_pActiveTargetingProfile->m_ConeDistancesSquared[3],
                     this->m_pActiveTargetingProfile->m_HalfHorizontalFOVs[3]);
    }
  }
  if ( !m_pPointer )
  {
LABEL_23:
    v13 = this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
    if ( v13 )
    {
      v14 = v13;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v14], 0i64);
      v15 = this->m_pTargets;
      if ( v15[v14].m_bLock )
        v15[v14].m_bLock = 0;
    }
    goto LABEL_26;
  }
  v16 = this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
  if ( !v16 )
  {
LABEL_26:
    UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(this);
    return;
  }
  UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v16], m_pPointer);
  UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(this);
}

// File Line: 1667
// RVA: 0x549CD0
void __fastcall UFG::TargetingSystemPedBaseComponent::Reset(UFG::TargetingSystemPedBaseComponent *this)
{
  unsigned int *m_pBucketList; // rcx

  UFG::TargetingSystemBaseComponent::shutdown(this);
  UFG::TargetingSystemBaseComponent::initialize(this);
  m_pBucketList = this->m_pBucketList;
  this->m_CachedPedsList.size = 0;
  if ( m_pBucketList )
  {
    --m_pBucketList[this->m_uUpdateBucket];
    this->m_pBucketList = 0i64;
  }
  UFG::TargetingSystemPedBaseComponent::initialize(this);
}

// File Line: 1677
// RVA: 0x54BBE0
void __fastcall UFG::TargetingSystemPedBaseComponent::SetActiveTargetingProfile(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qSymbolUC *theTargetingProfileSymbol)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v5; // rax
  char *v6; // rax

  mUID = theTargetingProfileSymbol->mUID;
  if ( mUID && (v5 = UFG::qBaseTreeRB::Get(&UFG::TargetingProfiles::ms_TargetingProfiles.mTree, mUID)) != 0i64 )
  {
    this->m_pActiveTargetingProfile = (UFG::TargetingProfile *)v5;
  }
  else
  {
    v6 = UFG::qSymbol::as_cstr_dbg(theTargetingProfileSymbol);
    UFG::qPrintf("WARNING: Could Not Set Active Targeting Profile: %s\n", v6);
  }
}

// File Line: 1692
// RVA: 0x556A10
void __fastcall UFG::TargetingSystemPedBaseComponent::TeleportEventHandler(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::Event *this_event)
{
  UFG::TargetingMap *m_pTargetingMap; // rax
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InterestPoint *m_pComponent; // rbx
  unsigned __int8 v7; // cl
  unsigned __int64 v8; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v10; // cl
  unsigned __int64 v11; // rbx
  UFG::TargetingSimObject *v12; // rax

  m_pTargetingMap = this->m_pTargetingMap;
  this->m_bForceUpdate = 1;
  m_pPointer = this->m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[26]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPoint *)m_pPointer->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::InterestPoint *)m_pPointer->m_Components.p[10].m_pComponent;
      else
        m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                            ? m_pPointer->m_Components.p[3].m_pComponent
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::InterestPoint::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::InterestPoint *)m_pPointer->m_Components.p[25].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::InterestPoint::FinishUsing(m_pComponent);
      UFG::InterestPoint::EndReservation(m_pComponent);
    }
  }
  v7 = this->m_pTargetingMap->m_Map.p[26];
  if ( v7 )
  {
    v8 = v7;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v8], 0i64);
    m_pTargets = this->m_pTargets;
    if ( m_pTargets[v8].m_bLock )
      m_pTargets[v8].m_bLock = 0;
  }
  v10 = this->m_pTargetingMap->m_Map.p[25];
  if ( v10 )
  {
    v11 = v10;
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v11], 0i64);
    v12 = this->m_pTargets;
    if ( v12[v11].m_bLock )
      v12[v11].m_bLock = 0;
  }
}

// File Line: 1727
// RVA: 0x54EE70
void __fastcall UFG::TargetingSystemPedBaseComponent::SetTargetLock(
        UFG::TargetingSystemPedBaseComponent *this,
        unsigned int eTargetType,
        bool bLock,
        const bool bModifyCollisionAccordingToLock)
{
  __int64 v4; // rdi
  UFG::SimObjectGame *m_pPointer; // rbx
  UFG::SimObjectGame *m_pSimObject; // rdx
  unsigned __int8 v9; // cl
  UFG::TargetingSimObject *v10; // rcx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int m_TypeUID; // ecx
  unsigned int v14; // ecx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v17; // rdx
  unsigned int v18; // r8d
  unsigned int v19; // r9d
  __int64 v20; // rdi
  unsigned __int8 v21; // al
  __int64 v22; // rcx
  __int64 v23; // rax

  v4 = eTargetType;
  m_pPointer = (UFG::SimObjectGame *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer;
  if ( m_pPointer
    && eTargetType - eTARGET_TYPE_FACING > 1
    && eTargetType != eTARGET_TYPE_PICKUP_ITEM
    && bModifyCollisionAccordingToLock )
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( bLock )
      UFG::PhysicsSystem::DisableCollisionsBetween(
        (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
        m_pSimObject,
        m_pPointer);
    else
      UFG::PhysicsSystem::ReEnableCollisionsBetween(
        (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
        m_pSimObject,
        m_pPointer);
  }
  v9 = this->m_pTargetingMap->m_Map.p[v4];
  if ( v9 )
  {
    v10 = &this->m_pTargets[v9];
    if ( v10->m_bLock != bLock )
      v10->m_bLock = bLock;
  }
  if ( (_DWORD)v4 == eTARGET_TYPE_GRAPPLE
    && this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_GRAPPLE]
    && m_pPointer
    && this->m_pSimObject != m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( !m_pComponent )
        goto LABEL_19;
      m_TypeUID = m_pComponent->m_TypeUID;
      if ( ((m_TypeUID ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000) != 0
        || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_19;
      }
LABEL_41:
      if ( m_pComponent )
      {
        v20 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[eTARGET_TYPE_GRAPPLE];
        if ( bLock )
        {
          v21 = *(_BYTE *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64);
          if ( v21 )
            UFG::TargetingSimObject::SetTarget(
              (UFG::TargetingSimObject *)(*(_QWORD *)&m_pComponent[1].m_TypeUID + 56i64 * v21),
              this->m_pSimObject);
          v22 = *(_QWORD *)&m_pComponent[1].m_TypeUID + 56 * v20;
          if ( *(_BYTE *)(v22 + 49) != 1 )
            *(_BYTE *)(v22 + 49) = 1;
        }
        else
        {
          v23 = *(_QWORD *)&m_pComponent[1].m_TypeUID + 56 * v20;
          if ( *(_BYTE *)(v23 + 49) )
            *(_BYTE *)(v23 + 49) = 0;
        }
      }
      return;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        v14 = m_pComponent->m_TypeUID;
        if ( ((v14 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v14 & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_41;
        }
      }
      goto LABEL_19;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
      size = m_pPointer->m_Components.size;
      if ( mComponentTableEntryCount < size )
      {
        v17 = (__int64)&m_pPointer->m_Components.p[mComponentTableEntryCount];
        while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) != 0 )
        {
          ++mComponentTableEntryCount;
          v17 += 16i64;
          if ( mComponentTableEntryCount >= size )
          {
            m_pComponent = 0i64;
            goto LABEL_41;
          }
        }
LABEL_32:
        m_pComponent = *(UFG::SimComponent **)v17;
        goto LABEL_41;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemPedBaseComponent::_TypeUID);
        goto LABEL_41;
      }
      v18 = m_pPointer->mComponentTableEntryCount;
      v19 = m_pPointer->m_Components.size;
      if ( v18 < v19 )
      {
        v17 = (__int64)&m_pPointer->m_Components.p[v18];
        while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v18;
          v17 += 16i64;
          if ( v18 >= v19 )
          {
            m_pComponent = 0i64;
            goto LABEL_41;
          }
        }
        goto LABEL_32;
      }
    }
LABEL_19:
    m_pComponent = 0i64;
    goto LABEL_41;
  }
}

// File Line: 1861
// RVA: 0x530360
UFG::SubTargetingProfile *__fastcall UFG::TargetingSystemPedBaseComponent::GetSubTargetingProfileForTarget(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::SimObject *pTargetSimObject,
        __int64 vfptr_low)
{
  UFG::SimObject *v3; // r9
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int size; // r10d
  UFG::SimComponentHolder *v7; // rdx

  v3 = pTargetSimObject;
  if ( !pTargetSimObject )
    return 0i64;
  m_Flags = pTargetSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pTargetSimObject->m_Components.p[3].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = pTargetSimObject->m_Components.p[4].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr_low = LODWORD(pTargetSimObject[1].vfptr);
      size = pTargetSimObject->m_Components.size;
      if ( (unsigned int)vfptr_low >= size )
      {
LABEL_14:
        m_pComponent = 0i64;
      }
      else
      {
        v7 = &pTargetSimObject->m_Components.p[(unsigned int)vfptr_low];
        while ( (v7->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectPropertiesComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          vfptr_low = (unsigned int)(vfptr_low + 1);
          ++v7;
          if ( (unsigned int)vfptr_low >= size )
            goto LABEL_14;
        }
        m_pComponent = v7->m_pComponent;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(pTargetSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = pTargetSimObject->m_Components.p[3].m_pComponent;
  }
  if ( m_pComponent )
    return (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *, UFG::qSafePointerNode<UFG::SimComponent>Vtbl *, __int64, UFG::SimObject *))m_pComponent->vfptr[14].__vecDelDtor)(
                                         m_pComponent,
                                         m_pComponent->vfptr,
                                         vfptr_low,
                                         v3);
  else
    return 0i64;
}

// File Line: 1876
// RVA: 0x530590
signed __int64 __fastcall UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::SimObject *pTargetSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::AttackRightsComponent *ComponentOfType; // rax
  unsigned int v6; // r8d
  unsigned int v7; // r9d
  UFG::SimComponentHolder *v8; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  UFG::SimComponent *m_pComponent; // rcx
  signed __int16 v15; // cx
  unsigned int v16; // r8d
  unsigned int v17; // r9d
  UFG::SimComponentHolder *v18; // rdx
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::eFactionClassEnum mPrev; // ebx
  UFG::eFactionClassEnum v23; // edi
  UFG::GameStatTracker *v24; // rax
  unsigned int Standing; // ebx
  signed __int16 v26; // dx
  UFG::SimComponent *v27; // rdx
  unsigned int v28; // r8d
  unsigned int v29; // r9d
  UFG::SimComponentHolder *v30; // rdx
  unsigned int v31; // r8d
  unsigned int v32; // r9d

  if ( !this->m_pActiveAIEntityComponent.m_pSimComponent )
    goto LABEL_31;
  if ( !pTargetSimObject )
  {
LABEL_32:
    m_pComponent = 0i64;
    goto LABEL_59;
  }
  m_Flags = pTargetSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)pTargetSimObject[1].vfptr;
        size = pTargetSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v8 = &pTargetSimObject->m_Components.p[vfptr];
          while ( (v8->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
               || (UFG::AttackRightsComponent::_TypeUID & ~v8->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            ++v8;
            if ( vfptr >= size )
            {
              ComponentOfType = 0i64;
              goto LABEL_28;
            }
          }
          goto LABEL_12;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                            pTargetSimObject,
                                                            UFG::AttackRightsComponent::_TypeUID);
          goto LABEL_28;
        }
        v11 = (unsigned int)pTargetSimObject[1].vfptr;
        v12 = pTargetSimObject->m_Components.size;
        if ( v11 < v12 )
        {
          v8 = &pTargetSimObject->m_Components.p[v11];
          while ( (v8->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
               || (UFG::AttackRightsComponent::_TypeUID & ~v8->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v11;
            ++v8;
            if ( v11 >= v12 )
            {
              ComponentOfType = 0i64;
              goto LABEL_28;
            }
          }
          goto LABEL_12;
        }
      }
    }
    else
    {
      v6 = (unsigned int)pTargetSimObject[1].vfptr;
      v7 = pTargetSimObject->m_Components.size;
      if ( v6 < v7 )
      {
        v8 = &pTargetSimObject->m_Components.p[v6];
        while ( (v8->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
             || (UFG::AttackRightsComponent::_TypeUID & ~v8->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v6;
          ++v8;
          if ( v6 >= v7 )
            goto LABEL_11;
        }
LABEL_12:
        ComponentOfType = (UFG::AttackRightsComponent *)v8->m_pComponent;
        goto LABEL_28;
      }
    }
LABEL_11:
    ComponentOfType = 0i64;
    goto LABEL_28;
  }
  ComponentOfType = (UFG::AttackRightsComponent *)pTargetSimObject->m_Components.p[46].m_pComponent;
LABEL_28:
  if ( ComponentOfType
    && UFG::ActiveAIEntityComponent::IsEnemyOfMine(
         (UFG::ActiveAIEntityComponent *)this->m_pActiveAIEntityComponent.m_pSimComponent,
         ComponentOfType) )
  {
    return 2i64;
  }
LABEL_31:
  if ( !pTargetSimObject )
    goto LABEL_32;
  v15 = pTargetSimObject->m_Flags;
  if ( (v15 & 0x4000) != 0 )
  {
    m_pComponent = pTargetSimObject->m_Components.p[3].m_pComponent;
    if ( !m_pComponent
      || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
    {
      goto LABEL_32;
    }
    if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
  }
  else
  {
    if ( v15 >= 0 )
    {
      if ( (v15 & 0x2000) != 0 )
      {
        v16 = (unsigned int)pTargetSimObject[1].vfptr;
        v17 = pTargetSimObject->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_32;
        v18 = &pTargetSimObject->m_Components.p[v16];
        while ( (v18->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v16;
          ++v18;
          if ( v16 >= v17 )
          {
            m_pComponent = 0i64;
            goto LABEL_59;
          }
        }
      }
      else
      {
        if ( (v15 & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(
                           pTargetSimObject,
                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          goto LABEL_59;
        }
        v19 = (unsigned int)pTargetSimObject[1].vfptr;
        v20 = pTargetSimObject->m_Components.size;
        if ( v19 >= v20 )
          goto LABEL_32;
        v18 = &pTargetSimObject->m_Components.p[v19];
        while ( (v18->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v19;
          ++v18;
          if ( v19 >= v20 )
          {
            m_pComponent = 0i64;
            goto LABEL_59;
          }
        }
      }
      m_pComponent = v18->m_pComponent;
      goto LABEL_59;
    }
    m_pComponent = pTargetSimObject->m_Components.p[3].m_pComponent;
    if ( !m_pComponent
      || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
    {
      goto LABEL_32;
    }
    if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
  }
LABEL_59:
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent && m_pComponent )
  {
    mPrev = (UFG::eFactionClassEnum)m_pComponent[3].m_SafePointerList.mNode.mPrev;
    v23 = (UFG::eFactionClassEnum)m_pSimComponent[3].m_SafePointerList.mNode.mPrev;
    v24 = UFG::FactionInterface::Get();
    Standing = UFG::FactionInterface::GetStanding(&v24->mFactionInterface, v23, mPrev);
    if ( !Standing || !pTargetSimObject )
      return Standing;
    v26 = pTargetSimObject->m_Flags;
    if ( (v26 & 0x4000) != 0 )
    {
      v27 = pTargetSimObject->m_Components.p[22].m_pComponent;
LABEL_65:
      if ( !v27
        || ((UFG::ActiveAIEntityComponent::_TypeUID ^ v27->m_TypeUID) & 0xFE000000) != 0
        || (UFG::ActiveAIEntityComponent::_TypeUID & ~v27->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_68;
      }
LABEL_87:
      if ( v27 )
      {
        if ( UFG::g_AIObjectiveParams[SHIDWORD(v27[65].vfptr)].m_IsHostile )
          return 2;
      }
      return Standing;
    }
    if ( v26 < 0 )
    {
      v27 = pTargetSimObject->m_Components.p[22].m_pComponent;
      goto LABEL_65;
    }
    if ( (v26 & 0x2000) != 0 )
    {
      v28 = (unsigned int)pTargetSimObject[1].vfptr;
      v29 = pTargetSimObject->m_Components.size;
      if ( v28 < v29 )
      {
        v30 = &pTargetSimObject->m_Components.p[v28];
        while ( (v30->m_TypeUID & 0xFE000000) != (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
             || (UFG::ActiveAIEntityComponent::_TypeUID & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v28;
          ++v30;
          if ( v28 >= v29 )
          {
            v27 = 0i64;
            goto LABEL_87;
          }
        }
LABEL_78:
        v27 = v30->m_pComponent;
        goto LABEL_87;
      }
    }
    else
    {
      if ( (v26 & 0x1000) == 0 )
      {
        v27 = UFG::SimObject::GetComponentOfType(pTargetSimObject, UFG::ActiveAIEntityComponent::_TypeUID);
        goto LABEL_87;
      }
      v31 = (unsigned int)pTargetSimObject[1].vfptr;
      v32 = pTargetSimObject->m_Components.size;
      if ( v31 < v32 )
      {
        v30 = &pTargetSimObject->m_Components.p[v31];
        while ( (v30->m_TypeUID & 0xFE000000) != (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
             || (UFG::ActiveAIEntityComponent::_TypeUID & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v31;
          ++v30;
          if ( v31 >= v32 )
          {
            v27 = 0i64;
            goto LABEL_87;
          }
        }
        goto LABEL_78;
      }
    }
LABEL_68:
    v27 = 0i64;
    goto LABEL_87;
  }
  return 1i64;
}

// File Line: 1934
// RVA: 0x530AC0
signed __int64 __fastcall UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::eTargetTypeEnum eTargetType)
{
  return UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
           this,
           this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer);
}

// File Line: 1950
// RVA: 0x521400
void __fastcall UFG::TargetingSystemPedBaseComponent::AddTargetSteerToTask(
        UFG::TargetingSystemPedBaseComponent *this,
        TargetSteerToTask *pTargetSteerToTask)
{
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v2; // rdx
  UFG::qList<TargetSteerToTask,TargetingSystemTargetSteerToList,0,0> *p_m_TargetSteerToTaskList; // rcx
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *mPrev; // rax

  v2 = &pTargetSteerToTask->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>;
  p_m_TargetSteerToTaskList = &this->m_TargetSteerToTaskList;
  mPrev = p_m_TargetSteerToTaskList->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_m_TargetSteerToTaskList->mNode;
  p_m_TargetSteerToTaskList->mNode.mPrev = v2;
}

// File Line: 1957
// RVA: 0x54D250
void __fastcall UFG::TargetingSystemPedBaseComponent::SetFocusTargetSubTargetingLocationOverride(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::qSymbol *focusTargetSubTargetingLocationOverrideSymbol)
{
  unsigned int mUID; // edx

  mUID = focusTargetSubTargetingLocationOverrideSymbol->mUID;
  if ( mUID == -1 )
  {
    this->m_pFocusTargetSubTargetingLocationOverride = 0i64;
  }
  else if ( mUID )
  {
    this->m_pFocusTargetSubTargetingLocationOverride = (UFG::SubTargetingLocation *)UFG::qBaseTreeRB::Get(
                                                                                      &UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree,
                                                                                      mUID);
  }
  else
  {
    this->m_pFocusTargetSubTargetingLocationOverride = 0i64;
  }
}

// File Line: 1985
// RVA: 0x55CD00
void __fastcall UFG::TargetingSystemPedBaseComponent::Update(
        UFG::TargetingSystemPedBaseComponent *this,
        float delta_sec)
{
  *(_QWORD *)&this->m_vTargetingPosition.z = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 30i64)
                                                       + *(_QWORD *)&this->m_TypeUID
                                                       + 40);
}

// File Line: 1995
// RVA: 0x53EB90
void __fastcall UFG::TargetingSystemPedBaseComponent::OnAttach(
        UFG::TargetingSystemPedBaseComponent *this,
        UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *p_m_pAimingBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pActiveAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *p_m_pAICharacterControllerComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_m_pAICharacterControllerBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *p_m_pInterestPointUserComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax

  UFG::TargetingSystemBaseComponent::OnAttach(this, pSimObject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->m_pTransformNodeComponent,
    pSimObject);
  p_m_pAimingBaseComponent = &this->m_pAimingBaseComponent;
  if ( this->m_pAimingBaseComponent.m_pSimComponent )
  {
    mPrev = p_m_pAimingBaseComponent->mPrev;
    mNext = this->m_pAimingBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAimingBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pAimingBaseComponent.m_pSimObject = 0i64;
    this->m_pAimingBaseComponent.mNext = &this->m_pAimingBaseComponent;
    p_m_pAimingBaseComponent->mPrev = p_m_pAimingBaseComponent;
    goto LABEL_8;
  }
  if ( this->m_pAimingBaseComponent.m_pSimObject
    && (p_m_pAimingBaseComponent->mPrev != p_m_pAimingBaseComponent
     || this->m_pAimingBaseComponent.mNext != &this->m_pAimingBaseComponent) )
  {
    v7 = p_m_pAimingBaseComponent->mPrev;
    v8 = this->m_pAimingBaseComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->m_pAimingBaseComponent.m_Changed = 1;
  this->m_pAimingBaseComponent.m_pSimObject = pSimObject;
  this->m_pAimingBaseComponent.m_TypeUID = UFG::AimingBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAimingBaseComponent,
    pSimObject);
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v10 = p_m_pActionTreeComponent->mPrev;
    v11 = this->m_pActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v12 = p_m_pActionTreeComponent->mPrev;
    v13 = this->m_pActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pActionTreeComponent.m_Changed = 1;
  this->m_pActionTreeComponent.m_pSimObject = pSimObject;
  this->m_pActionTreeComponent.m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pActionTreeComponent,
    pSimObject);
  p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
  if ( this->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v15 = p_m_pActiveAIEntityComponent->mPrev;
    v16 = this->m_pActiveAIEntityComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    this->m_pActiveAIEntityComponent.mNext = &this->m_pActiveAIEntityComponent;
    p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
    goto LABEL_22;
  }
  if ( this->m_pActiveAIEntityComponent.m_pSimObject
    && (p_m_pActiveAIEntityComponent->mPrev != p_m_pActiveAIEntityComponent
     || this->m_pActiveAIEntityComponent.mNext != &this->m_pActiveAIEntityComponent) )
  {
    v17 = p_m_pActiveAIEntityComponent->mPrev;
    v18 = this->m_pActiveAIEntityComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pActiveAIEntityComponent.m_Changed = 1;
  this->m_pActiveAIEntityComponent.m_pSimObject = pSimObject;
  this->m_pActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pActiveAIEntityComponent,
    pSimObject);
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v20 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v21 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_29;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v22 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v23 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = pSimObject;
  this->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pSimObjectCharacterPropertiesComponent,
    pSimObject);
  p_m_pAICharacterControllerComponent = &this->m_pAICharacterControllerComponent;
  if ( this->m_pAICharacterControllerComponent.m_pSimComponent )
  {
    v25 = p_m_pAICharacterControllerComponent->mPrev;
    v26 = this->m_pAICharacterControllerComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    this->m_pAICharacterControllerComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pAICharacterControllerComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerComponent.mNext = &this->m_pAICharacterControllerComponent;
    p_m_pAICharacterControllerComponent->mPrev = p_m_pAICharacterControllerComponent;
    goto LABEL_36;
  }
  if ( this->m_pAICharacterControllerComponent.m_pSimObject
    && (p_m_pAICharacterControllerComponent->mPrev != p_m_pAICharacterControllerComponent
     || this->m_pAICharacterControllerComponent.mNext != &this->m_pAICharacterControllerComponent) )
  {
    v27 = p_m_pAICharacterControllerComponent->mPrev;
    v28 = this->m_pAICharacterControllerComponent.mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pAICharacterControllerComponent.m_Changed = 1;
  this->m_pAICharacterControllerComponent.m_pSimObject = pSimObject;
  this->m_pAICharacterControllerComponent.m_TypeUID = UFG::AICharacterControllerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAICharacterControllerComponent,
    pSimObject);
  p_m_pAICharacterControllerBaseComponent = &this->m_pAICharacterControllerBaseComponent;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v30 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v31 = this->m_pAICharacterControllerBaseComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_42:
    this->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerBaseComponent.mNext = &this->m_pAICharacterControllerBaseComponent;
    p_m_pAICharacterControllerBaseComponent->mPrev = p_m_pAICharacterControllerBaseComponent;
    goto LABEL_43;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && (p_m_pAICharacterControllerBaseComponent->mPrev != p_m_pAICharacterControllerBaseComponent
     || this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v32 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v33 = this->m_pAICharacterControllerBaseComponent.mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    goto LABEL_42;
  }
LABEL_43:
  this->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  this->m_pAICharacterControllerBaseComponent.m_pSimObject = pSimObject;
  this->m_pAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAICharacterControllerBaseComponent,
    pSimObject);
  p_m_pInterestPointUserComponent = &this->m_pInterestPointUserComponent;
  if ( this->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v35 = p_m_pInterestPointUserComponent->mPrev;
    v36 = this->m_pInterestPointUserComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    this->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_49:
    this->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    this->m_pInterestPointUserComponent.mNext = &this->m_pInterestPointUserComponent;
    p_m_pInterestPointUserComponent->mPrev = p_m_pInterestPointUserComponent;
    goto LABEL_50;
  }
  if ( this->m_pInterestPointUserComponent.m_pSimObject
    && (p_m_pInterestPointUserComponent->mPrev != p_m_pInterestPointUserComponent
     || this->m_pInterestPointUserComponent.mNext != &this->m_pInterestPointUserComponent) )
  {
    v37 = p_m_pInterestPointUserComponent->mPrev;
    v38 = this->m_pInterestPointUserComponent.mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    goto LABEL_49;
  }
LABEL_50:
  this->m_pInterestPointUserComponent.m_Changed = 1;
  this->m_pInterestPointUserComponent.m_pSimObject = pSimObject;
  this->m_pInterestPointUserComponent.m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pInterestPointUserComponent,
    pSimObject);
}

// File Line: 2013
// RVA: 0x540D80
void __fastcall UFG::TargetingSystemPedBaseComponent::OnDetach(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *p_m_pAimingBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_pActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *p_m_pAICharacterControllerComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_m_pAICharacterControllerBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *p_m_pInterestPointUserComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  unsigned int *m_pBucketList; // rcx

  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = this->m_pTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pTransformNodeComponent->m_pSimObject = 0i64;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    goto LABEL_8;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
     || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v5 = p_m_pTransformNodeComponent->mPrev;
    v6 = p_m_pTransformNodeComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAimingBaseComponent = &this->m_pAimingBaseComponent;
  p_m_pTransformNodeComponent->m_Changed = 1;
  if ( this->m_pAimingBaseComponent.m_pSimComponent )
  {
    v8 = p_m_pAimingBaseComponent->mPrev;
    v9 = this->m_pAimingBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pAimingBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAimingBaseComponent.m_pSimObject = 0i64;
    this->m_pAimingBaseComponent.mNext = &this->m_pAimingBaseComponent;
    p_m_pAimingBaseComponent->mPrev = p_m_pAimingBaseComponent;
    goto LABEL_15;
  }
  if ( this->m_pAimingBaseComponent.m_pSimObject
    && (p_m_pAimingBaseComponent->mPrev != p_m_pAimingBaseComponent
     || this->m_pAimingBaseComponent.mNext != &this->m_pAimingBaseComponent) )
  {
    v10 = p_m_pAimingBaseComponent->mPrev;
    v11 = this->m_pAimingBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAimingBaseComponent.m_Changed = 1;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v13 = p_m_pActionTreeComponent->mPrev;
    v14 = this->m_pActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_22;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v15 = p_m_pActionTreeComponent->mPrev;
    v16 = this->m_pActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pActionTreeComponent.m_Changed = 1;
  p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
  if ( this->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v18 = p_m_pActiveAIEntityComponent->mPrev;
    v19 = this->m_pActiveAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    this->m_pActiveAIEntityComponent.mNext = &this->m_pActiveAIEntityComponent;
    p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
    goto LABEL_29;
  }
  if ( this->m_pActiveAIEntityComponent.m_pSimObject
    && (p_m_pActiveAIEntityComponent->mPrev != p_m_pActiveAIEntityComponent
     || this->m_pActiveAIEntityComponent.mNext != &this->m_pActiveAIEntityComponent) )
  {
    v20 = p_m_pActiveAIEntityComponent->mPrev;
    v21 = this->m_pActiveAIEntityComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pActiveAIEntityComponent.m_Changed = 1;
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v23 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v24 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_36;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v25 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v26 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  p_m_pAICharacterControllerComponent = &this->m_pAICharacterControllerComponent;
  if ( this->m_pAICharacterControllerComponent.m_pSimComponent )
  {
    v28 = p_m_pAICharacterControllerComponent->mPrev;
    v29 = this->m_pAICharacterControllerComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->m_pAICharacterControllerComponent.m_pSimComponent = 0i64;
LABEL_42:
    this->m_pAICharacterControllerComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerComponent.mNext = &this->m_pAICharacterControllerComponent;
    p_m_pAICharacterControllerComponent->mPrev = p_m_pAICharacterControllerComponent;
    goto LABEL_43;
  }
  if ( this->m_pAICharacterControllerComponent.m_pSimObject
    && (p_m_pAICharacterControllerComponent->mPrev != p_m_pAICharacterControllerComponent
     || this->m_pAICharacterControllerComponent.mNext != &this->m_pAICharacterControllerComponent) )
  {
    v30 = p_m_pAICharacterControllerComponent->mPrev;
    v31 = this->m_pAICharacterControllerComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  this->m_pAICharacterControllerComponent.m_Changed = 1;
  p_m_pAICharacterControllerBaseComponent = &this->m_pAICharacterControllerBaseComponent;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v33 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v34 = this->m_pAICharacterControllerBaseComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_49:
    this->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerBaseComponent.mNext = &this->m_pAICharacterControllerBaseComponent;
    p_m_pAICharacterControllerBaseComponent->mPrev = p_m_pAICharacterControllerBaseComponent;
    goto LABEL_50;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && (p_m_pAICharacterControllerBaseComponent->mPrev != p_m_pAICharacterControllerBaseComponent
     || this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v35 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v36 = this->m_pAICharacterControllerBaseComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  this->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  p_m_pInterestPointUserComponent = &this->m_pInterestPointUserComponent;
  if ( this->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v38 = p_m_pInterestPointUserComponent->mPrev;
    v39 = this->m_pInterestPointUserComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    this->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
  }
  else
  {
    if ( !this->m_pInterestPointUserComponent.m_pSimObject
      || p_m_pInterestPointUserComponent->mPrev == p_m_pInterestPointUserComponent
      && this->m_pInterestPointUserComponent.mNext == &this->m_pInterestPointUserComponent )
    {
      goto LABEL_57;
    }
    v40 = p_m_pInterestPointUserComponent->mPrev;
    v41 = this->m_pInterestPointUserComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
  }
  this->m_pInterestPointUserComponent.m_pSimObject = 0i64;
  this->m_pInterestPointUserComponent.mNext = &this->m_pInterestPointUserComponent;
  p_m_pInterestPointUserComponent->mPrev = p_m_pInterestPointUserComponent;
LABEL_57:
  this->m_pInterestPointUserComponent.m_Changed = 1;
  UFG::TargetingSystemBaseComponent::OnDetach(this);
  m_pBucketList = this->m_pBucketList;
  if ( m_pBucketList )
  {
    --m_pBucketList[this->m_uUpdateBucket];
    this->m_pBucketList = 0i64;
  }
}

// File Line: 2055
// RVA: 0x54F3A0
void __fastcall UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(
        UFG::TargetingSystemPedBaseComponent *this)
{
  unsigned int *m_pBucketList; // rdx
  unsigned int v3; // r8d
  unsigned int v4; // r9d
  unsigned int *v5; // rcx
  unsigned int i; // eax

  m_pBucketList = this->m_pBucketList;
  if ( m_pBucketList )
    --m_pBucketList[this->m_uUpdateBucket];
  v3 = UFG::TargetingSystemPedBaseComponent::ms_LowFrequencyUpdateBuckets[0];
  v4 = 0;
  v5 = (unsigned int *)&unk_14240DD84;
  for ( i = 1; i < 0x3C; ++i )
  {
    if ( *v5 < v3 )
    {
      v4 = i;
      v3 = *v5;
    }
    ++v5;
  }
  this->m_uUpdateBucket = v4;
  this->m_pBucketList = UFG::TargetingSystemPedBaseComponent::ms_LowFrequencyUpdateBuckets;
  ++UFG::TargetingSystemPedBaseComponent::ms_LowFrequencyUpdateBuckets[v4];
}

// File Line: 2071
// RVA: 0x54F2B0
void __fastcall UFG::TargetingSystemPedBaseComponent::SetToHighFrequencyUpdate(
        UFG::TargetingSystemPedBaseComponent *this)
{
  unsigned int *m_pBucketList; // rdx
  unsigned int v2; // eax
  __int64 v3; // rdx

  m_pBucketList = this->m_pBucketList;
  if ( m_pBucketList )
    --m_pBucketList[this->m_uUpdateBucket];
  v2 = UFG::TargetingSystemPedBaseComponent::ms_HighFrequencyUpdateBuckets[0];
  v3 = 0i64;
  if ( dword_14240DE74 < UFG::TargetingSystemPedBaseComponent::ms_HighFrequencyUpdateBuckets[0] )
  {
    v3 = 1i64;
    v2 = dword_14240DE74;
  }
  if ( dword_14240DE78 < v2 )
  {
    v3 = 2i64;
    v2 = dword_14240DE78;
  }
  if ( dword_14240DE7C < v2 )
  {
    v3 = 3i64;
    v2 = dword_14240DE7C;
  }
  if ( dword_14240DE80 < v2 )
  {
    v3 = 4i64;
    v2 = dword_14240DE80;
  }
  if ( dword_14240DE84 < v2 )
  {
    v3 = 5i64;
    v2 = dword_14240DE84;
  }
  if ( dword_14240DE88 < v2 )
  {
    v3 = 6i64;
    v2 = dword_14240DE88;
  }
  if ( dword_14240DE8C < v2 )
  {
    v3 = 7i64;
    v2 = dword_14240DE8C;
  }
  if ( dword_14240DE90 < v2 )
  {
    v3 = 8i64;
    v2 = dword_14240DE90;
  }
  if ( dword_14240DE94 < v2 )
    v3 = 9i64;
  this->m_pBucketList = UFG::TargetingSystemPedBaseComponent::ms_HighFrequencyUpdateBuckets;
  this->m_uUpdateBucket = v3;
  ++UFG::TargetingSystemPedBaseComponent::ms_HighFrequencyUpdateBuckets[v3];
}

