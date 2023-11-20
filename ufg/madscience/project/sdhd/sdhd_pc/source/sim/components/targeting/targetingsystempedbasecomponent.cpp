// File Line: 81
// RVA: 0x1544120
__int64 dynamic_initializer_for__UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters__);
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
void __fastcall UFG::TargetingParameters::InitFromPropertySet(UFG::TargetingParameters *this, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v2; // rsi
  UFG::TargetingParameters *v3; // rdi
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
  signed int v20; // eax
  signed int v21; // ecx
  signed int v22; // ecx
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
    v2 = properties;
    v3 = this;
    v4 = _S31_0;
    if ( !(_S31_0 & 1) )
    {
      _S31_0 |= 1u;
      UFG::qSymbol::create_from_string(&symBoneNameAimOrigin, "BoneNameAimOrigin");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symBoneNameAimOrigin__);
      v4 = _S31_0;
    }
    if ( !(v4 & 2) )
    {
      _S31_0 = v4 | 2;
      UFG::qSymbol::create_from_string(&symAimDirectionYawClamp, "AimDirectionYawClamp");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAimDirectionYawClamp__);
      v4 = _S31_0;
    }
    if ( !(v4 & 4) )
    {
      _S31_0 = v4 | 4;
      UFG::qSymbol::create_from_string(&symAimDirectionYawReset, "AimDirectionYawReset");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAimDirectionYawReset__);
      v4 = _S31_0;
    }
    if ( !(v4 & 8) )
    {
      _S31_0 = v4 | 8;
      UFG::qSymbol::create_from_string(&symMaxPOITargetingRange, "MaxPOITargetingRange");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symMaxPOITargetingRange__);
      v4 = _S31_0;
    }
    if ( !(v4 & 0x10) )
    {
      _S31_0 = v4 | 0x10;
      UFG::qSymbol::create_from_string(&symAccuracyEvadeModifier, "AccuracyEvadeModifier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAccuracyEvadeModifier__);
      v4 = _S31_0;
    }
    if ( !(v4 & 0x20) )
    {
      _S31_0 = v4 | 0x20;
      UFG::qSymbol::create_from_string(&symDefaultAccuracyRate, "DefaultAccuracyRate");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDefaultAccuracyRate__);
      v4 = _S31_0;
    }
    if ( !(v4 & 0x40) )
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
    if ( !_bittest((const signed int *)&v4, 8u) )
    {
      _S31_0 = v4 | 0x100;
      UFG::qSymbol::create_from_string(
        &symRequiredLevelForGunplayUpgradeMarksman,
        "RequiredLevelForGunplayUpgradeMarksman");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRequiredLevelForGunplayUpgradeMarksman__);
      v4 = _S31_0;
    }
    if ( !_bittest((const signed int *)&v4, 9u) )
    {
      _S31_0 = v4 | 0x200;
      UFG::qSymbol::create_from_string(&symGunplayUpgradeMarksmanMultiplier, "GunplayUpgradeMarksmanMultiplier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symGunplayUpgradeMarksmanMultiplier__);
      v4 = _S31_0;
    }
    if ( !_bittest((const signed int *)&v4, 0xAu) )
    {
      _S31_0 = v4 | 0x400;
      UFG::qSymbol::create_from_string(&symRequiredLevelForGunplayUpgradeDamage, "RequiredLevelForGunplayUpgradeDamage");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symRequiredLevelForGunplayUpgradeDamage__);
      v4 = _S31_0;
    }
    if ( !_bittest((const signed int *)&v4, 0xBu) )
    {
      _S31_0 = v4 | 0x800;
      UFG::qSymbol::create_from_string(&symGunplayUpgradeDamageMultiplier, "GunplayUpgradeDamageMultiplier");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symGunplayUpgradeDamageMultiplier__);
      v4 = _S31_0;
    }
    if ( !_bittest((const signed int *)&v4, 0xCu) )
    {
      _S31_0 = v4 | 0x1000;
      UFG::qSymbol::create_from_string(&symFlickTargetingAngularLimit, "FlickTargetingAngularLimit");
      atexit(UFG::TargetingParameters::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symFlickTargetingAngularLimit__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, &symBoneNameAimOrigin, DEPTH_RECURSE);
    v28 = UFG::qPropertySet::Get<float>(v2, &symAimDirectionYawClamp, DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<float>(v2, &symAimDirectionYawReset, DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(v2, &symMaxPOITargetingRange, DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(v2, &symAccuracyEvadeModifier, DEPTH_RECURSE);
    v9 = UFG::qPropertySet::Get<float>(v2, &symDefaultAccuracyRate, DEPTH_RECURSE);
    v10 = UFG::qPropertySet::Get<float>(v2, &symFullyAccurateDamageMultiplier, DEPTH_RECURSE);
    v29 = UFG::qPropertySet::Get<long>(v2, &symRequiredLevelForGunplayUpgradeSubTargeting, DEPTH_RECURSE);
    v30 = UFG::qPropertySet::Get<long>(v2, &symRequiredLevelForGunplayUpgradeMarksman, DEPTH_RECURSE);
    v25 = UFG::qPropertySet::Get<float>(v2, &symGunplayUpgradeMarksmanMultiplier, DEPTH_RECURSE);
    v26 = UFG::qPropertySet::Get<long>(v2, &symRequiredLevelForGunplayUpgradeDamage, DEPTH_RECURSE);
    v27 = UFG::qPropertySet::Get<float>(v2, &symGunplayUpgradeDamageMultiplier, DEPTH_RECURSE);
    v11 = UFG::qPropertySet::Get<float>(v2, &symFlickTargetingAngularLimit, DEPTH_RECURSE);
    v12 = &UFG::gNullQSymbolUC;
    if ( v5 )
      v12 = v5;
    v3->m_BoneUIDAimOrigin = (UFG::qSymbolUC)v12->mUID;
    v13 = FLOAT_N1_0;
    if ( v28 )
      v14 = (float)(*v28 * 3.1415927) * 0.0055555557;
    else
      v14 = FLOAT_N1_0;
    v3->m_fAimDirectionYawClamp = v14;
    if ( v6 )
      v15 = (float)(*v6 * 3.1415927) * 0.0055555557;
    else
      v15 = FLOAT_N1_0;
    v3->m_fAimDirectionYawReset = v15;
    if ( v7 )
      v16 = *v7;
    else
      v16 = FLOAT_N1_0;
    v3->m_fMaxPOITargetingRange = v16;
    if ( v8 )
      v17 = *v8;
    else
      v17 = FLOAT_N1_0;
    v3->m_fAccuracyEvadeModifier = v17;
    if ( v10 )
      v18 = *v10;
    else
      v18 = *(float *)&FLOAT_1_0;
    v3->m_fFullyAccurateDamageMultiplier = v18;
    if ( v9 )
      v19 = *v9;
    else
      v19 = FLOAT_N1_0;
    v3->m_fDefaultAccuracyRate = v19;
    v20 = -1;
    if ( v29 )
      v21 = *v29;
    else
      v21 = -1;
    v3->m_iRequiredLevelForGunplayUpgradeSubTargeting = v21;
    if ( v30 )
      v22 = *v30;
    else
      v22 = -1;
    v3->m_iRequiredLevelForGunplayUpgradeMarksman = v22;
    if ( v25 )
      v23 = *v25;
    else
      v23 = FLOAT_N1_0;
    v3->m_fGunplayUpgradeMarksmanMultiplier = v23;
    if ( v26 )
      v20 = *v26;
    v3->m_iRequiredLevelForGunplayUpgradeDamage = v20;
    if ( v27 )
      v24 = *v27;
    else
      v24 = FLOAT_N1_0;
    v3->m_fGunplayUpgradeDamageMultiplier = v24;
    if ( v11 )
      v13 = (float)(*v11 * 3.1415927) * 0.0055555557;
    v3->m_fFlickTargetingAngularLimitRad = v13;
  }
}else
      v24 = FLOAT_N1_0;
    v3->m_fGunplayUpgradeDamageMultiplier = v24;
    if ( v11 )
      v13 = (float)(*v11 * 3.1415927) * 0.0055555557;
    v3->m_fFlickTargetingAngularLimit

// File Line: 261
// RVA: 0x522B70
void UFG::TargetingSystemPedBaseComponent::BuildCloseToTargetTable(void)
{
  float v0; // xmm6_4
  signed int v1; // ebx
  float *v2; // rdi
  float v3; // xmm0_4

  v0 = UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetExponent;
  v1 = 0;
  v2 = UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetArray;
  do
  {
    v3 = powf((float)v1++ * 0.11111111, v0);
    ++v2;
    *(v2 - 1) = v3;
  }
  while ( (unsigned int)v1 < 0xA );
}

// File Line: 272
// RVA: 0x522B00
void UFG::TargetingSystemPedBaseComponent::BuildCloseToCenterTable(void)
{
  float v0; // xmm6_4
  signed int v1; // ebx
  float *v2; // rdi
  float v3; // xmm0_4

  v0 = UFG::TargetingSystemPedBaseComponent::ms_fCloseToCenterExponent;
  v1 = 0;
  v2 = UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterArray;
  do
  {
    v3 = powf((float)v1++ * 0.11111111, v0);
    ++v2;
    *(v2 - 1) = v3;
  }
  while ( (unsigned int)v1 < 0xA );
}

// File Line: 283
// RVA: 0x550780
void UFG::TargetingSystemPedBaseComponent::StaticInit(void)
{
  UFG::qPropertySet *v0; // rax

  if ( !(_S30_0 & 1) )
  {
    _S30_0 |= 1u;
    UFG::qSymbol::create_from_string(&propSetName, "Targeting-TargetingParameters");
    atexit(UFG::TargetingParameters::Init_::_2_::_dynamic_atexit_destructor_for__symTargetingParametersPropertySet__);
  }
  v0 = UFG::PropertySetManager::GetPropertySet(&propSetName);
  UFG::TargetingParameters::InitFromPropertySet(&UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters, v0);
  UFG::TargetingSystemPedBaseComponent::BuildCloseToTargetTable();
  UFG::TargetingSystemPedBaseComponent::BuildCloseToCenterTable();
}

// File Line: 333
// RVA: 0x519AE0
void __fastcall UFG::TargetingSystemPedBaseComponent::TargetingSystemPedBaseComponent(UFG::TargetingSystemPedBaseComponent *this, UFG::TargetingMap *pTargetingMap, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::TargetingSystemPedBaseComponent *v4; // rsi
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v5; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *v6; // ST38_8
  UFG::qList<TargetSteerToTask,TargetingSystemTargetSteerToList,0,0> *v7; // ST38_8
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v8; // rax

  v4 = this;
  UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
    (UFG::TargetingSystemBaseComponent *)&this->vfptr,
    pTargetingMap,
    name_uid,
    properties);
  v5 = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable'{for `UFG::SimComponent'};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v4->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0>::RebindingComponentHandle<UFG::AimingBaseComponent,0>(&v4->m_pAimingBaseComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v4->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v4->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v4->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerComponent,0>(&v4->m_pAICharacterControllerComponent);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&v4->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(&v4->m_pInterestPointUserComponent);
  v6 = &v4->m_pEquippedSOWPC;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->m_pEquippedSOWPC.m_pPointer = 0i64;
  v7 = &v4->m_TargetSteerToTaskList;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  `eh vector constructor iterator'(
    v4->m_CachedPedsList.p,
    0x18ui64,
    80,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v4->m_CachedPedsList.size = 0;
  v4->m_ClosePhysicalTargetsList.size = 0;
  v8 = UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mPrev;
  UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&v4->mPrev;
  v5->mPrev = v8;
  v4->mNext = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList;
  UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TargetingSystemPedBaseComponent::_TargetingSystemPedBaseComponentTypeUID,
    "TargetingSystemPedBaseComponent");
  UFG::TargetingSystemPedBaseComponent::initialize(v4);
}

// File Line: 343
// RVA: 0x51CEA0
void __fastcall UFG::TargetingSystemPedBaseComponent::~TargetingSystemPedBaseComponent(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::TargetingSystemPedBaseComponent *v1; // rbx
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *v2; // rsi
  unsigned int *v3; // rcx
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::InterestPoint *v6; // rdi
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v7; // rdi
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v8; // rcx
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v15; // rcx
  UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedBaseComponent::`vftable'{for `UFG::UpdateInterface'};
  v2 = &this->m_CachedPedsList;
  this->m_CachedPedsList.size = 0;
  v3 = this->m_pBucketList;
  if ( v3 )
  {
    --v3[v1->m_uUpdateBucket];
    v1->m_pBucketList = 0i64;
  }
  v4 = v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[26]].m_pTarget.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::InterestPoint *)v4->m_Components.p[25].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::InterestPoint *)v4->m_Components.p[10].m_pComponent;
      else
        v6 = (UFG::InterestPoint *)((v5 >> 12) & 1 ? v4->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                            v4,
                                                                                            UFG::InterestPoint::_TypeUID));
    }
    else
    {
      v6 = (UFG::InterestPoint *)v4->m_Components.p[25].m_pComponent;
    }
    if ( v6 )
    {
      UFG::InterestPoint::FinishUsing(v6);
      UFG::InterestPoint::EndReservation(v6);
    }
  }
  v2->size = 0;
  v1->m_ClosePhysicalTargetsList.size = 0;
  if ( v1 == UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentpCurrentIterator )
    UFG::TargetingSystemPedBaseComponent::s_TargetingSystemPedBaseComponentpCurrentIterator = (UFG::TargetingSystemPedBaseComponent *)&v1->mPrev[-8].mNext;
  v7 = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  v1->m_ClosePhysicalTargetsList.size = 0;
  v2->size = 0;
  `eh vector destructor iterator'(
    v2->p,
    0x18ui64,
    80,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_TargetSteerToTaskList);
  v10 = &v1->m_pEquippedSOWPC;
  if ( v1->m_pEquippedSOWPC.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_pEquippedSOWPC.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_pEquippedSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEquippedSOWPC.mPrev;
  }
  v1->m_pEquippedSOWPC.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->m_pEquippedSOWPC.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->m_pEquippedSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEquippedSOWPC.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pInterestPointUserComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAICharacterControllerComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAimingBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_pTransformNodeComponent);
  v15 = v7->mPrev;
  v16 = v1->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v7->mPrev = v7;
  v1->mNext = (UFG::qNode<UFG::TargetingSystemPedBaseComponent,UFG::TargetingSystemPedBaseComponent> *)&v1->mPrev;
  UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
}

// File Line: 369
// RVA: 0x56A0D0
void __fastcall UFG::TargetingSystemPedBaseComponent::initialize(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4

  v1 = &this->m_pEquippedSOWPC;
  if ( this->m_pEquippedSOWPC.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->m_pEquippedSOWPC.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->m_pEquippedSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pEquippedSOWPC.mPrev;
  }
  this->m_pEquippedSOWPC.m_pPointer = 0i64;
  this->m_pActiveTargetingProfile = UFG::TargetingProfiles::ms_TargetingProfilePool.p;
  this->m_bForceUpdate = 1;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->m_vTargetingPosition.x = UFG::qVector3::msZero.x;
  this->m_vTargetingPosition.y = v4;
  this->m_vTargetingPosition.z = v5;
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
bool __fastcall UFG::TargetingSystemPedBaseComponent::IsWithinVerticalFOV(UFG::TargetingSystemPedBaseComponent *this, UFG::qVector3 *vMeToTarget, const float fHalfVerticalFOV, const float fExtraPositivePitch, const float fExtraNegativePitch)
{
  float v5; // xmm5_4
  __m128 v6; // xmm4
  UFG::qVector3 *v7; // rbx
  float v8; // xmm7_4
  __m128 v9; // xmm1
  float v10; // xmm2_4
  UFG::qVector3 axis; // [rsp+18h] [rbp-71h]
  UFG::qMatrix44 dest; // [rsp+28h] [rbp-61h]
  UFG::qMatrix44 v14; // [rsp+68h] [rbp-21h]
  float v15; // [rsp+108h] [rbp+7Fh]

  v5 = vMeToTarget->x;
  v6 = (__m128)LODWORD(vMeToTarget->y);
  v9 = v6;
  v7 = vMeToTarget;
  v8 = fHalfVerticalFOV;
  v9.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  if ( v9.m128_f32[0] <= 0.001 )
    return 0;
  v10 = v9.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  axis.z = (float)((float)(v6.m128_f32[0] * v10) * 0.0) - (float)((float)(v5 * v10) * 0.0);
  UFG::qRotationMatrixAxis(&dest, &axis, v8 + fExtraPositivePitch);
  if ( (float)((float)((float)((float)((float)((float)(dest.v0.x + dest.v1.x) * 0.0) - (float)(dest.v2.x * 1.0)) * v7->x)
                     + (float)((float)((float)((float)(dest.v0.y + dest.v1.y) * 0.0) - (float)(dest.v2.y * 1.0)) * v7->y))
             + (float)((float)((float)((float)(dest.v0.z + dest.v1.z) * 0.0) - (float)(dest.v2.z * 1.0)) * v7->z)) < 0.0 )
    return 0;
  UFG::qRotationMatrixAxis(&v14, &axis, COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 + v15) ^ _xmm[0]));
  return (float)((float)((float)((float)((float)((float)(v14.v0.x + v14.v1.x) * 0.0) + v14.v2.x) * v7->x)
                       + (float)((float)((float)((float)(v14.v0.y + v14.v1.y) * 0.0) + v14.v2.y) * v7->y))
               + (float)((float)((float)((float)(v14.v0.z + v14.v1.z) * 0.0) + v14.v2.z) * v7->z)) >= 0.0;
}

// File Line: 486
// RVA: 0x569CD0
float __fastcall UFG::TargetingSystemPedBaseComponent::getTargetConsiderationDistanceSquared(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::SimComponent *v1; // rax
  float v2; // xmm0_4
  float result; // xmm0_4

  v1 = this->m_pEquippedSOWPC.m_pPointer;
  if ( v1 )
  {
    v2 = *(float *)(*((_QWORD *)&v1[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v1[2].m_pSimObject)) + 40i64);
    result = v2 * v2;
  }
  else
  {
    result = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  if ( this->m_fMinimumTargetDistanceSquared > result )
    result = this->m_fMinimumTargetDistanceSquared;
  return result;
}

// File Line: 498
// RVA: 0x569C90
float __fastcall UFG::TargetingSystemPedBaseComponent::getTargetAcquisitionDistanceSquared(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::SimComponent *v1; // rax
  float v2; // xmm0_4

  v1 = this->m_pEquippedSOWPC.m_pPointer;
  if ( !v1 )
    return this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  v2 = *(float *)(*((_QWORD *)&v1[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v1[2].m_pSimObject)) + 40i64);
  return v2 * v2;
}

// File Line: 567
// RVA: 0x56AA70
bool __fastcall UFG::TargetingSystemPedBaseComponent::isHostileToMe(UFG::TargetingSystemPedBaseComponent *this, UFG::SimObject *pOtherSimObject)
{
  UFG::SimObject *v2; // r8
  UFG::TargetingSystemPedBaseComponent *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::AttackRightsComponent *v5; // rax
  unsigned int v6; // er9
  unsigned int v7; // er10
  signed __int64 v8; // rdx
  unsigned int v9; // er9
  unsigned int v10; // er10
  unsigned int v11; // er9
  unsigned int v12; // er10
  UFG::ActiveAIEntityComponent *v13; // rcx
  char *v15; // rax

  v2 = pOtherSimObject;
  v3 = this;
  if ( !pOtherSimObject )
    return 0;
  v4 = pOtherSimObject->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::AttackRightsComponent *)v2->m_Components.p[46].m_pComponent;
    goto LABEL_27;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v6 = (unsigned int)v2[1].vfptr;
    v7 = v2->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
           || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v6;
        v8 += 16i64;
        if ( v6 >= v7 )
        {
          v5 = 0i64;
          goto LABEL_27;
        }
      }
LABEL_11:
      v5 = *(UFG::AttackRightsComponent **)v8;
      goto LABEL_27;
    }
    goto LABEL_25;
  }
  if ( (v4 >> 13) & 1 )
  {
    v9 = (unsigned int)v2[1].vfptr;
    v10 = v2->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
           || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
        {
          v5 = 0i64;
          goto LABEL_27;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_25;
  }
  if ( (v4 >> 12) & 1 )
  {
    v11 = (unsigned int)v2[1].vfptr;
    v12 = v2->m_Components.size;
    if ( v11 < v12 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v11];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
           || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v11;
        v8 += 16i64;
        if ( v11 >= v12 )
          goto LABEL_25;
      }
      goto LABEL_11;
    }
LABEL_25:
    v5 = 0i64;
    goto LABEL_27;
  }
  v5 = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::AttackRightsComponent::_TypeUID);
LABEL_27:
  if ( v5 )
  {
    v13 = (UFG::ActiveAIEntityComponent *)v3->m_pActiveAIEntityComponent.m_pSimComponent;
    if ( v13 )
      return UFG::ActiveAIEntityComponent::IsEnemyOfMine(v13, v5);
    v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_pSimObject->m_Name);
    UFG::qPrintf("WARNING: TargetingSystemPedBaseComponent::isHostileToMe: %s not an AI or target is not an AI\n", v15);
  }
  return 0;
}

// File Line: 584
// RVA: 0x56A7C0
bool __fastcall UFG::TargetingSystemPedBaseComponent::isAlliedToMe(UFG::TargetingSystemPedBaseComponent *this, UFG::SimObject *pOtherSimObject)
{
  UFG::TargetingSystemPedBaseComponent *v2; // rdi
  UFG::SimComponent *v3; // rdx
  unsigned __int16 v4; // cx
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // er9
  unsigned int v8; // er10
  UFG::SimComponentHolder *v9; // rdx
  unsigned int v10; // er9
  unsigned int v11; // er10
  UFG::SimComponent *v12; // rax
  UFG::eFactionClassEnum v13; // edi
  UFG::eFactionClassEnum v14; // ebx
  UFG::GameStatTracker *v15; // rax

  v2 = this;
  if ( !pOtherSimObject )
    goto LABEL_2;
  v4 = pOtherSimObject->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v3 = pOtherSimObject->m_Components.p[3].m_pComponent;
    if ( v3 )
    {
      v5 = v3->m_TypeUID;
      if ( !((v5 ^ UFG::SimObjectCharacterPropertiesComponent::_TypeUID) & 0xFE000000) )
      {
        if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v5 & 0x1FFFFFF )
          v3 = 0i64;
        goto LABEL_29;
      }
    }
LABEL_2:
    v3 = 0i64;
    goto LABEL_29;
  }
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v7 = (unsigned int)pOtherSimObject[1].vfptr;
      v8 = pOtherSimObject->m_Components.size;
      if ( v7 >= v8 )
        goto LABEL_2;
      v9 = &pOtherSimObject->m_Components.p[v7];
      while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF )
      {
        ++v7;
        ++v9;
        if ( v7 >= v8 )
        {
          v3 = 0i64;
          goto LABEL_29;
        }
      }
    }
    else
    {
      if ( !((v4 >> 12) & 1) )
      {
        v3 = UFG::SimObject::GetComponentOfType(pOtherSimObject, UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_29;
      }
      v10 = (unsigned int)pOtherSimObject[1].vfptr;
      v11 = pOtherSimObject->m_Components.size;
      if ( v10 >= v11 )
        goto LABEL_2;
      v9 = &pOtherSimObject->m_Components.p[v10];
      while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF )
      {
        ++v10;
        ++v9;
        if ( v10 >= v11 )
        {
          v3 = 0i64;
          goto LABEL_29;
        }
      }
    }
    v3 = v9->m_pComponent;
    goto LABEL_29;
  }
  v3 = pOtherSimObject->m_Components.p[3].m_pComponent;
  if ( !v3 )
    goto LABEL_2;
  v6 = v3->m_TypeUID;
  if ( (v6 ^ UFG::SimObjectCharacterPropertiesComponent::_TypeUID) & 0xFE000000 )
    goto LABEL_2;
  if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v6 & 0x1FFFFFF )
    v3 = 0i64;
LABEL_29:
  v12 = v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( !v12 || !v3 )
    return 0;
  v13 = (UFG::eFactionClassEnum)v12[3].m_SafePointerList.mNode.mPrev;
  v14 = (UFG::eFactionClassEnum)v3[3].m_SafePointerList.mNode.mPrev;
  v15 = UFG::FactionInterface::Get();
  return (unsigned int)UFG::FactionInterface::GetStanding(&v15->mFactionInterface, v13, v14) == 0;
}

// File Line: 625
// RVA: 0x567FA0
void __fastcall UFG::TargetingSystemPedBaseComponent::findCloseTargets(UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList, UFG::SimObject *pSimObjectToExclude, UFG::qVector3 *vTargetingPosition, const float fMaximumTargetDistanceSquared)
{
  UFG::qVector3 *v4; // r15
  UFG::SimObject *v5; // r12
  UFG::qFixedArray<UFG::CloseTarget,100> *v6; // r14
  UFG::SimObjectPropertiesComponent *v7; // rbx
  UFG::SimObjectPropertiesComponent *v8; // rdi
  UFG::SimObject *v9; // rsi
  UFG::TransformNodeComponent *v10; // rsi
  float v11; // xmm2_4
  __int64 v12; // rcx
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  float v16; // er9
  unsigned int v17; // er8
  float *v18; // rdx
  signed __int64 v19; // rax
  signed __int64 v20; // rcx
  UFG::qVector4 v21; // xmm2
  UFG::qVector4 v22; // xmm1
  UFG::qVector4 v23; // xmm0
  UFG::CloseTarget right; // [rsp+0h] [rbp-9CD0h]
  UFG::CloseTarget left[500]; // [rsp+50h] [rbp-9C80h]

  *(_QWORD *)&right.m_Xform.v2.z = -2i64;
  v4 = vTargetingPosition;
  v5 = pSimObjectToExclude;
  v6 = closeTargetsList;
  right.m_Xform.v3.z = 0.0;
  v7 = (UFG::SimObjectPropertiesComponent *)&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent,1,0> *)&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mNext[-4] != &UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList - 4 )
  {
    do
    {
      v8 = (UFG::SimObjectPropertiesComponent *)&v7->mNext[-4];
      if ( (v7->m_Flags & 3) == 1 )
      {
        v9 = v7->m_pSimObject;
        if ( v9 != v5 && !((LOBYTE(v7->m_BitField.mBits[0]) >> 5) & 1) )
        {
          if ( v9 )
          {
            v10 = v9->m_pTransformNodeComponent;
            if ( v10 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v10);
              v11 = (float)((float)((float)(v10->mWorldTransform.v3.x - v4->x)
                                  * (float)(v10->mWorldTransform.v3.x - v4->x))
                          + (float)((float)(v10->mWorldTransform.v3.y - v4->y)
                                  * (float)(v10->mWorldTransform.v3.y - v4->y)))
                  + (float)((float)(v10->mWorldTransform.v3.z - v4->z) * (float)(v10->mWorldTransform.v3.z - v4->z));
              if ( v11 <= fMaximumTargetDistanceSquared && LODWORD(right.m_Xform.v3.z) < 0x1F4 )
              {
                v12 = LODWORD(right.m_Xform.v3.z);
                ++LODWORD(right.m_Xform.v3.z);
                left[v12].m_fDistance2 = v11;
                left[v12].m_pSimObjectPropertiesComponent = v7;
                v13 = v10->mWorldTransform.v1;
                v14 = v10->mWorldTransform.v2;
                v15 = v10->mWorldTransform.v3;
                left[v12].m_Xform.v0 = v10->mWorldTransform.v0;
                left[v12].m_Xform.v1 = v13;
                left[v12].m_Xform.v2 = v14;
                left[v12].m_Xform.v3 = v15;
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
  v6->size = 0;
  v16 = right.m_Xform.v3.z;
  v17 = 0;
  v18 = &left[0].m_Xform.v2.x;
  do
  {
    if ( v17 >= LODWORD(v16) )
      break;
    v19 = v6->size;
    v20 = v19;
    v6->size = v19 + 1;
    v6->p[v20].m_fDistance2 = *(v18 - 12);
    v6->p[v20].m_pSimObjectPropertiesComponent = (UFG::SimObjectPropertiesComponent *)*((_QWORD *)v18 - 5);
    v21 = (UFG::qVector4)*((_OWORD *)v18 - 1);
    v22 = *(UFG::qVector4 *)v18;
    v23 = (UFG::qVector4)*((_OWORD *)v18 + 1);
    v6->p[v20].m_Xform.v0 = (UFG::qVector4)*((_OWORD *)v18 - 2);
    v6->p[v20].m_Xform.v1 = v21;
    v6->p[v20].m_Xform.v2 = v22;
    v6->p[v20].m_Xform.v3 = v23;
    ++v17;
    v18 += 20;
  }
  while ( v17 < 0x64 );
}

// File Line: 711
// RVA: 0x567290
void __fastcall UFG::TargetingSystemPedBaseComponent::filterCloseTargets(UFG::qFixedArray<UFG::CloseTarget,100> *closeTargetsList, UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *cachedPedsList, UFG::qFixedArray<UFG::CloseTarget *,80> *filteredClosePedsList, UFG::qFixedArray<UFG::CloseTarget *,5> *filteredClosePickupsList, UFG::qFixedArray<UFG::CloseTarget *,5> *filteredClosePropsList, UFG::qFixedArray<UFG::CloseTarget *,20> *filteredCloseVehiclesList, UFG::qFixedArray<UFG::CloseTarget,100> *filteredCloseTargetsList)
{
  UFG::qFixedArray<UFG::CloseTarget *,5> *v7; // r12
  UFG::qFixedArray<UFG::CloseTarget *,5> *v8; // r15
  unsigned int v9; // ebp
  __int64 v10; // r14
  UFG::qFixedArray<UFG::CloseTarget *,80> *v11; // r13
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *v12; // r9
  UFG::CloseTarget *v13; // rdi
  UFG::SimObjectPropertiesComponent *v14; // rax
  signed int v15; // ecx
  UFG::SimObjectProp *v16; // rbx
  UFG::PhysicsMoverInterface *v17; // rcx
  unsigned int v18; // eax
  unsigned __int16 v19; // cx
  unsigned int v20; // er8
  unsigned int v21; // er10
  signed __int64 v22; // rdx
  UFG::PropInteractComponent *v23; // rax
  unsigned int v24; // er8
  unsigned int v25; // er10
  unsigned int v26; // eax
  __int64 v27; // rdx
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  unsigned int v30; // er8
  unsigned int v31; // er10
  signed __int64 v32; // rdx
  unsigned __int16 v33; // cx
  UFG::CharacterAnimationComponent *v34; // rcx
  UFG::CharacterAnimationComponent *v35; // rax
  unsigned int v36; // er8
  unsigned int v37; // er10
  signed __int64 v38; // rdx
  Creature *v39; // rax
  unsigned int v40; // eax
  unsigned int v41; // eax
  __int64 v42; // r8
  signed __int64 v43; // rdx
  bool v44; // zf
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v45; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v47; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v48; // rax
  __int64 v49; // rdx
  __int64 v50; // rcx
  UFG::qVector4 v51; // xmm3
  UFG::qVector4 v52; // xmm2
  UFG::qVector4 v53; // xmm1
  UFG::qFixedArray<UFG::CloseTarget,100> *v54; // [rsp+70h] [rbp+8h]
  UFG::qFixedArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>,80> *v55; // [rsp+78h] [rbp+10h]
  unsigned int filteredClosePropsLista; // [rsp+90h] [rbp+28h]

  v55 = cachedPedsList;
  v54 = closeTargetsList;
  v7 = filteredClosePropsList;
  cachedPedsList->size = 0;
  filteredClosePedsList->size = 0;
  v8 = filteredClosePickupsList;
  filteredClosePickupsList->size = 0;
  filteredClosePropsList->size = 0;
  filteredCloseVehiclesList->size = 0;
  filteredCloseTargetsList->size = 0;
  v9 = 0;
  v10 = 0i64;
  v11 = filteredClosePedsList;
  v12 = cachedPedsList;
  filteredClosePropsLista = closeTargetsList->size;
  if ( closeTargetsList->size )
  {
    while ( 1 )
    {
      v13 = &closeTargetsList->p[v10];
      v14 = v13->m_pSimObjectPropertiesComponent;
      v15 = v14->m_eSimObjectType;
      v16 = (UFG::SimObjectProp *)v14->m_pSimObject;
      if ( v15 == 1 )
        break;
      if ( v15 > 1 )
      {
        if ( v15 <= 3 )
        {
          if ( UFG::TargetingSystemPedBaseComponent::ms_fMaxDistanceToPickup2 < v13->m_fDistance2 )
            goto LABEL_97;
          if ( !v16 )
            goto LABEL_97;
          v28 = v16->m_Flags;
          if ( (v28 >> 14) & 1 || (v28 & 0x8000u) != 0 )
            goto LABEL_97;
          if ( (v28 >> 13) & 1 )
          {
            v29 = v16->m_Components.p[11].m_pComponent;
          }
          else if ( (v28 >> 12) & 1 )
          {
            v30 = v16->mComponentTableEntryCount;
            v31 = v16->m_Components.size;
            if ( v30 >= v31 )
            {
LABEL_54:
              v29 = 0i64;
            }
            else
            {
              v32 = (signed __int64)&v16->m_Components.p[v30];
              while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                   || UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
              {
                ++v30;
                v32 += 16i64;
                if ( v30 >= v31 )
                  goto LABEL_54;
              }
              v29 = *(UFG::SimComponent **)v32;
            }
          }
          else
          {
            v29 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v16->vfptr,
                    UFG::InventoryItemComponent::_TypeUID);
          }
          if ( !v29
            || !LODWORD(v29[1].m_pSimObject)
            || SLODWORD(v29[1].m_BoundComponentHandles.mNode.mPrev) <= 0
            || *(_QWORD *)&v29[1].m_Flags )
          {
            goto LABEL_97;
          }
          v33 = v16->m_Flags;
          if ( (v33 >> 14) & 1 )
          {
            v34 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
            if ( !v34
              || (UFG::CharacterAnimationComponent::_TypeUID ^ v34->m_TypeUID) & 0xFE000000
              || UFG::CharacterAnimationComponent::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF )
            {
              goto LABEL_65;
            }
          }
          else
          {
            if ( (v33 & 0x8000u) == 0 )
            {
              if ( (v33 >> 13) & 1 )
              {
                v35 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v16);
              }
              else
              {
                if ( (v33 >> 12) & 1 )
                {
                  v36 = v16->mComponentTableEntryCount;
                  v37 = v16->m_Components.size;
                  if ( v36 >= v37 )
                    goto LABEL_65;
                  v38 = (signed __int64)&v16->m_Components.p[v36];
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
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
                v35 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v16->vfptr,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
              }
              v34 = v35;
              goto LABEL_83;
            }
            v34 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
            if ( !v34 || (UFG::CharacterAnimationComponent::_TypeUID ^ v34->m_TypeUID) & 0xFE000000 )
            {
LABEL_65:
              v34 = 0i64;
            }
            else if ( UFG::CharacterAnimationComponent::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF )
            {
              v34 = 0i64;
            }
          }
LABEL_83:
          if ( v34 )
          {
            v39 = v34->mCreature;
            if ( v39 )
            {
              if ( !v39->mIsAttached )
              {
                v40 = v8->size;
                if ( v8->size < 5 )
                {
                  v8->size = v40 + 1;
                  v8->p[v40] = v13;
                }
              }
            }
          }
          goto LABEL_97;
        }
        if ( v15 == 4 )
        {
          if ( !v16 )
            goto LABEL_39;
          v17 = (UFG::PhysicsMoverInterface *)v16->m_Components.p[34].m_pComponent;
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
            if ( !v16 )
              goto LABEL_39;
            v19 = v16->m_Flags;
            if ( (v19 >> 14) & 1 )
            {
              v20 = v16->mComponentTableEntryCount;
              v21 = v16->m_Components.size;
              if ( v20 < v21 )
              {
                v22 = (signed __int64)&v16->m_Components.p[v20];
                while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                     || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
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
            else if ( (v19 & 0x8000u) == 0 )
            {
              if ( (v19 >> 13) & 1 )
              {
                v23 = (UFG::PropInteractComponent *)v16->m_Components.p[13].m_pComponent;
              }
              else if ( (v19 >> 12) & 1 )
              {
                v24 = v16->mComponentTableEntryCount;
                v25 = v16->m_Components.size;
                if ( v24 >= v25 )
                  goto LABEL_20;
                v22 = (signed __int64)&v16->m_Components.p[v24];
                while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                     || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
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
                                                      (UFG::SimObject *)&v16->vfptr,
                                                      UFG::PropInteractComponent::_TypeUID);
              }
            }
            else
            {
              v23 = (UFG::PropInteractComponent *)v16->m_Components.p[33].m_pComponent;
            }
LABEL_34:
            if ( !v23 || v23->mInteractingSimObject.m_pPointer || UFG::PropInteractComponent::NotInteractable(v23) )
            {
LABEL_39:
              if ( filteredCloseVehiclesList->size )
              {
                v27 = filteredCloseVehiclesList->size - 1;
                if ( (UFG::SimObjectProp *)filteredCloseVehiclesList->p[v27]->m_pSimObjectPropertiesComponent->m_pSimObject == v16 )
                  filteredCloseVehiclesList->size = v27;
              }
              goto LABEL_97;
            }
            v26 = v7->size;
            if ( v7->size < 5 )
            {
              v7->size = v26 + 1;
              v7->p[v26] = v13;
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
            goto LABEL_97;
          }
        }
        else if ( v15 == 5 )
        {
          goto LABEL_13;
        }
      }
LABEL_97:
      v12 = v55;
      closeTargetsList = v54;
      ++v9;
      ++v10;
      if ( v9 >= filteredClosePropsLista )
        return;
    }
    v41 = v11->size;
    if ( v11->size < 0x50 )
    {
      v11->size = v41 + 1;
      v11->p[v41] = v13;
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
        v46 = v45->mPrev;
        v47 = v45->mNext;
        v46->mNext = v47;
        v47->mPrev = v46;
        v45->mPrev = v45;
        v45->mNext = v45;
      }
      v45[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v16;
      if ( v16 )
      {
        v48 = v16->m_SafePointerList.mNode.mPrev;
        v48->mNext = v45;
        v45->mPrev = v48;
        v45->mNext = &v16->m_SafePointerList.mNode;
        v16->m_SafePointerList.mNode.mPrev = v45;
      }
    }
    goto LABEL_95;
  }
}

// File Line: 871
// RVA: 0x56AF80
bool __fastcall UFG::TargetingSystemPedBaseComponent::isScripted(UFG::SimObject *pSimObject)
{
  unsigned __int16 v1; // dx
  UFG::StreamedResourceComponent *v2; // rax
  unsigned int v3; // er8
  unsigned int v4; // er9
  UFG::SimComponentHolder *v5; // rdx
  bool result; // al

  if ( !pSimObject )
    goto LABEL_22;
  v1 = pSimObject->m_Flags;
  if ( (v1 >> 14) & 1 )
  {
    v2 = (UFG::StreamedResourceComponent *)pSimObject->m_Components.p[10].m_pComponent;
  }
  else if ( (v1 & 0x8000u) == 0 )
  {
    if ( (v1 >> 13) & 1 )
    {
      v2 = (UFG::StreamedResourceComponent *)pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( (v1 >> 12) & 1 )
    {
      v3 = (unsigned int)pSimObject[1].vfptr;
      v4 = pSimObject->m_Components.size;
      if ( v3 >= v4 )
      {
LABEL_14:
        v2 = 0i64;
      }
      else
      {
        v5 = &pSimObject->m_Components.p[v3];
        while ( (v5->m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
             || UFG::StreamedResourceComponent::_TypeUID & ~v5->m_TypeUID & 0x1FFFFFF )
        {
          ++v3;
          ++v5;
          if ( v3 >= v4 )
            goto LABEL_14;
        }
        v2 = (UFG::StreamedResourceComponent *)v5->m_pComponent;
      }
    }
    else
    {
      v2 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                               pSimObject,
                                               UFG::StreamedResourceComponent::_TypeUID);
    }
  }
  else
  {
    v2 = (UFG::StreamedResourceComponent *)pSimObject->m_Components.p[10].m_pComponent;
  }
  if ( v2 )
    result = UFG::StreamedResourceComponent::GetSpawnPriority(v2, 0i64)->mUID == qSymbol_Critical.mUID;
  else
LABEL_22:
    result = 0;
  return result;
}

// File Line: 948
// RVA: 0x567AC0
void __fastcall UFG::TargetingSystemPedBaseComponent::findClosePhysicalTargets(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *closePhysicalTargetsList, UFG::SimObject *pSimObjectToExclude, const float fMaximumTargetDistanceSquared)
{
  UFG::SimObject *v4; // rsi
  UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *v5; // rdi
  UFG::TargetingSystemPedBaseComponent *v6; // rbp
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // r9
  UFG::SimComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  UFG::SimComponentHolder *v12; // rbx
  signed __int64 v13; // rdx
  unsigned int v14; // er8
  unsigned int v15; // er9
  UFG::SimObject *v16; // rax
  unsigned __int16 v17; // dx
  unsigned int v18; // er9
  unsigned int v19; // er10
  signed __int64 v20; // rdx
  UFG::RigidBody *v21; // rbx
  unsigned int v22; // er9
  unsigned int v23; // er10
  unsigned int v24; // er9
  unsigned int v25; // er10
  unsigned int v26; // er9
  unsigned int v27; // er10
  float v28; // xmm2_4
  __int64 v29; // rax
  unsigned int v30; // er9
  unsigned int v31; // edx
  ClassTypeDescriptor *v32; // r8
  signed __int64 v33; // rcx
  UFG::SensorPhantomIterator v34; // [rsp+20h] [rbp-1FC8h]
  __int64 v35; // [rsp+38h] [rbp-1FB0h]
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-1FA8h]
  unsigned int v37; // [rsp+80h] [rbp-1F68h]
  ClassTypeDescriptor left[500]; // [rsp+88h] [rbp-1F60h]

  v35 = -2i64;
  v4 = pSimObjectToExclude;
  v5 = closePhysicalTargetsList;
  v6 = this;
  v37 = 0;
  v7 = this->m_pSimObject;
  if ( !v7 )
    goto LABEL_60;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = v7->m_Components.p[26].m_pComponent;
    goto LABEL_23;
  }
  if ( (v8 & 0x8000u) != 0 )
  {
    v9 = v7->m_Components.p[26].m_pComponent;
    goto LABEL_23;
  }
  if ( (v8 >> 13) & 1 )
  {
    v10 = (unsigned int)v7[1].vfptr;
    v11 = v7->m_Components.size;
    if ( v10 < v11 )
    {
      v12 = v7->m_Components.p;
      while ( 1 )
      {
        v13 = v10;
        if ( (v12[v10].m_TypeUID & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && !(UFG::SensorComponent::_TypeUID & ~v12[v10].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v10 >= v11 )
          goto LABEL_14;
      }
LABEL_13:
      v9 = v12[v13].m_pComponent;
      goto LABEL_23;
    }
LABEL_14:
    v9 = 0i64;
    goto LABEL_23;
  }
  if ( (v8 >> 12) & 1 )
  {
    v14 = (unsigned int)v7[1].vfptr;
    v15 = v7->m_Components.size;
    if ( v14 < v15 )
    {
      v12 = v7->m_Components.p;
      while ( 1 )
      {
        v13 = v14;
        if ( (v12[v14].m_TypeUID & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && !(UFG::SensorComponent::_TypeUID & ~v12[v14].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_13;
        }
        if ( ++v14 >= v15 )
          goto LABEL_14;
      }
    }
    goto LABEL_14;
  }
  v9 = UFG::SimObject::GetComponentOfType(v7, UFG::SensorComponent::_TypeUID);
LABEL_23:
  if ( v9 )
  {
    UFG::SensorPhantomIterator::SensorPhantomIterator(
      &v34,
      (UFG::SensorPhantom *)v9[1].m_SafePointerList.mNode.mNext,
      0);
    if ( UFG::SensorPhantomIterator::operator*(&v34) )
    {
      while ( 1 )
      {
        v16 = (UFG::SimObject *)UFG::SensorPhantomIterator::operator*(&v34);
        if ( v16 )
        {
          if ( v16 != v4 )
            break;
        }
LABEL_58:
        UFG::SensorPhantomIterator::operator++(&v34);
        if ( !UFG::SensorPhantomIterator::operator*(&v34) )
          goto LABEL_59;
      }
      v17 = v16->m_Flags;
      if ( (v17 >> 14) & 1 )
      {
        v18 = (unsigned int)v16[1].vfptr;
        v19 = v16->m_Components.size;
        if ( v18 < v19 )
        {
          while ( 1 )
          {
            v20 = (signed __int64)&v16->m_Components.p[v18];
            if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) )
            {
              break;
            }
            if ( ++v18 >= v19 )
              goto LABEL_34;
          }
LABEL_33:
          v21 = *(UFG::RigidBody **)v20;
LABEL_54:
          if ( v21 )
          {
            UFG::RigidBody::GetTransform(v21, &mat);
            v28 = (float)((float)((float)(mat.v3.y - v6->m_vTargetingPosition.y)
                                * (float)(mat.v3.y - v6->m_vTargetingPosition.y))
                        + (float)((float)(mat.v3.x - v6->m_vTargetingPosition.x)
                                * (float)(mat.v3.x - v6->m_vTargetingPosition.x)))
                + (float)((float)(mat.v3.z - v6->m_vTargetingPosition.z) * (float)(mat.v3.z - v6->m_vTargetingPosition.z));
            if ( v28 <= fMaximumTargetDistanceSquared && v37 < 0x1F4 )
            {
              v29 = v37++;
              *(float *)&left[v29].mUID = v28;
              left[v29].mfnInPlaceNew = (void (__fastcall *)(void *))v21;
            }
          }
          goto LABEL_58;
        }
      }
      else if ( (v17 & 0x8000u) == 0 )
      {
        if ( (v17 >> 13) & 1 )
        {
          v24 = (unsigned int)v16[1].vfptr;
          v25 = v16->m_Components.size;
          if ( v24 < v25 )
          {
            do
            {
              v20 = (signed __int64)&v16->m_Components.p[v24];
              if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) )
              {
                goto LABEL_33;
              }
            }
            while ( ++v24 < v25 );
          }
        }
        else
        {
          if ( !((v17 >> 12) & 1) )
          {
            v21 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v16, UFG::RigidBodyComponent::_TypeUID);
            goto LABEL_54;
          }
          v26 = (unsigned int)v16[1].vfptr;
          v27 = v16->m_Components.size;
          if ( v26 < v27 )
          {
            do
            {
              v20 = (signed __int64)&v16->m_Components.p[v26];
              if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) )
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
            v20 = (signed __int64)&v16->m_Components.p[v22];
            if ( (*(_DWORD *)(v20 + 8) & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_33;
            }
          }
          while ( ++v22 < v23 );
        }
      }
LABEL_34:
      v21 = 0i64;
      goto LABEL_54;
    }
LABEL_59:
    UFG::SensorPhantomIterator::~SensorPhantomIterator(&v34);
  }
LABEL_60:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    left,
    (ClassTypeDescriptor *)&mat.v3.z + (signed int)v37,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
  v5->size = 0;
  v30 = v37;
  v31 = 0;
  v32 = left;
  do
  {
    if ( v31 >= v30 )
      break;
    v33 = v5->size++;
    *(_QWORD *)&v5->p[v33].m_fDistance2 = *(_QWORD *)&v32->mUID;
    v5->p[v33].m_pRigidBodyComponent = (UFG::RigidBodyComponent *)v32->mfnInPlaceNew;
    ++v31;
    ++v32;
  }
  while ( v31 < 0xA );
}

// File Line: 1028
// RVA: 0x567140
void __fastcall UFG::TargetingSystemPedBaseComponent::filterClosePhysicalTargets(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *closePhysicalTargetsList, UFG::qFixedArray<UFG::ClosePhysicalTarget,2> *closePhysicalDodgeableList, UFG::qFixedArray<UFG::ClosePhysicalTarget,1> *closePhysicalMeleeAttackableList, UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *filteredClosePhysicalTargetsList)
{
  UFG::qFixedArray<UFG::ClosePhysicalTarget,1> *v5; // r14
  UFG::qFixedArray<UFG::ClosePhysicalTarget,2> *v6; // r15
  UFG::ClosePhysicalTarget *v7; // rdi
  __int64 v8; // rbp
  UFG::RigidBodyComponent *v9; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v10; // rcx
  const char *v11; // rax
  UFG::CollisionMeshData *v12; // rdx
  UFG::qReflectObject *v13; // rax
  unsigned int v14; // edx
  signed __int64 v15; // rcx
  unsigned int v16; // edx
  signed __int64 v17; // rcx
  unsigned int v18; // edx
  __int64 v19; // rcx
  UFG::qReflectHandleBase v20; // [rsp+28h] [rbp-40h]

  v5 = closePhysicalMeleeAttackableList;
  v6 = closePhysicalDodgeableList;
  filteredClosePhysicalTargetsList->size = 0;
  if ( closePhysicalTargetsList->size )
  {
    v7 = closePhysicalTargetsList->p;
    v8 = closePhysicalTargetsList->size;
    do
    {
      v9 = v7->m_pRigidBodyComponent;
      UFG::qReflectHandleBase::qReflectHandleBase(&v20);
      v11 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v10);
      v20.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
      v12 = v9->mCollisionMeshData;
      if ( v12 )
        UFG::qReflectHandleBase::operator=(&v20, (UFG::qReflectHandleBase *)&v12->mObjectProperties.mPrev);
      v13 = v20.mData;
      if ( v20.mData )
      {
        if ( BYTE3(v20.mData[2].vfptr) )
        {
          v14 = v6->size;
          if ( v6->size < 2 )
          {
            v15 = v14;
            v6->size = v14 + 1;
            *(_QWORD *)&v6->p[v15].m_fDistance2 = *(_QWORD *)&v7->m_fDistance2;
            v6->p[v15].m_pRigidBodyComponent = v7->m_pRigidBodyComponent;
            v13 = v20.mData;
          }
        }
        if ( BYTE4(v13[2].vfptr) )
        {
          v16 = v5->size;
          if ( v5->size < 1 )
          {
            v17 = v16;
            v5->size = v16 + 1;
            *(_QWORD *)&v5->p[v17].m_fDistance2 = *(_QWORD *)&v7->m_fDistance2;
            v5->p[v17].m_pRigidBodyComponent = v7->m_pRigidBodyComponent;
          }
        }
      }
      v18 = filteredClosePhysicalTargetsList->size;
      if ( filteredClosePhysicalTargetsList->size < 0xA )
      {
        v19 = v18;
        filteredClosePhysicalTargetsList->size = v18 + 1;
        *(_QWORD *)&filteredClosePhysicalTargetsList->p[v19].m_fDistance2 = *(_QWORD *)&v7->m_fDistance2;
        filteredClosePhysicalTargetsList->p[v19].m_pRigidBodyComponent = v7->m_pRigidBodyComponent;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v20);
      ++v7;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 1095
// RVA: 0x576660
void __fastcall UFG::TargetingSystemPedBaseComponent::updatePhysicalTarget(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::ClosePhysicalTarget,10> *closePhysicalTargetsList)
{
  UFG::TargetingSystemPedBaseComponent *v2; // rdi
  UFG::TargetingSimObject *v3; // rcx
  UFG::RigidBodyComponent *v4; // rbx
  UFG::SimObject *v5; // rdx
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl
  signed __int64 v8; // rbx
  UFG::TargetingSimObject *v9; // rax
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[49]];
  if ( !v3->m_pTarget.m_pPointer || !v3->m_bLock )
  {
    if ( closePhysicalTargetsList->size
      && (v4 = closePhysicalTargetsList->p[0].m_pRigidBodyComponent,
          UFG::RigidBody::GetTransform((UFG::RigidBody *)&v4->vfptr, &mat),
          (v5 = v4->m_pSimObject) != 0i64) )
    {
      v6 = v2->m_pTargetingMap->m_Map.p[49];
      if ( v6 )
        UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v6], v5);
    }
    else
    {
      v7 = v2->m_pTargetingMap->m_Map.p[49];
      if ( v7 )
      {
        v8 = v7;
        UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v8], 0i64);
        v9 = v2->m_pTargets;
        if ( v9[v8].m_bLock )
          v9[v8].m_bLock = 0;
      }
    }
  }
}

// File Line: 1146
// RVA: 0x570670
void __fastcall UFG::TargetingSystemPedBaseComponent::updateCloseVehiclesList(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::CloseTarget,20> *closeTargetsList, UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::SimObject *v3; // r13
  UFG::PhysicsMoverInterface *v4; // rdi
  UFG::qFixedArray<UFG::CloseTarget *,20> *v5; // r14
  UFG::qFixedArray<UFG::CloseTarget,20> *v6; // r15
  UFG::TargetingSystemPedBaseComponent *i; // rbp
  UFG::SimObject *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  unsigned int v11; // er8
  unsigned int v12; // er10
  signed __int64 v13; // rdx
  UFG::qVector4 *v14; // rsi
  float v15; // xmm6_4
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  unsigned int v18; // er8
  unsigned int v19; // er9
  signed __int64 v20; // rdx
  signed __int64 v21; // rcx
  signed __int64 v22; // rdx
  UFG::qVector4 v23; // xmm3
  UFG::qVector4 v24; // xmm2
  UFG::qVector4 v25; // xmm1
  signed __int64 v26; // rbx
  __int64 v27; // rcx

  v3 = this->m_pSimObject;
  v4 = (UFG::PhysicsMoverInterface *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  v5 = closeVehiclesList;
  v6 = closeTargetsList;
  for ( i = this;
        v4 != (UFG::PhysicsMoverInterface *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72);
        v4 = (UFG::PhysicsMoverInterface *)&v4->mNext[-5].mNext )
  {
    if ( (v4->m_Flags & 3) == 1 && v4->m_pSimObject != v3 && UFG::PhysicsMoverInterface::GetEngineDamage(v4) < 1.0 )
    {
      v8 = v4->m_pSimObject;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = v8->m_Components.p[3].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v10 = v8->m_Components.p[4].m_pComponent;
          }
          else if ( (v9 >> 12) & 1 )
          {
            v11 = (unsigned int)v8[1].vfptr;
            v12 = v8->m_Components.size;
            if ( v11 >= v12 )
            {
LABEL_18:
              v10 = 0i64;
            }
            else
            {
              v13 = (signed __int64)&v8->m_Components.p[v11];
              while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
                   || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF )
              {
                ++v11;
                v13 += 16i64;
                if ( v11 >= v12 )
                  goto LABEL_18;
              }
              v10 = *(UFG::SimComponent **)v13;
            }
          }
          else
          {
            v10 = UFG::SimObject::GetComponentOfType(v4->m_pSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
          }
        }
        else
        {
          v10 = v8->m_Components.p[3].m_pComponent;
        }
        if ( !v10 || !((LOBYTE(v10[1].m_Flags) >> 5) & 1) )
        {
          v14 = (UFG::qVector4 *)v8->m_pTransformNodeComponent;
          if ( v14 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v8->m_pTransformNodeComponent);
            v15 = (float)((float)((float)(v14[11].x - i->m_vTargetingPosition.x)
                                * (float)(v14[11].x - i->m_vTargetingPosition.x))
                        + (float)((float)(v14[11].y - i->m_vTargetingPosition.y)
                                * (float)(v14[11].y - i->m_vTargetingPosition.y)))
                + (float)((float)(v14[11].z - i->m_vTargetingPosition.z) * (float)(v14[11].z - i->m_vTargetingPosition.z));
            if ( v15 <= UFG::TargetingSystemPedBaseComponent::getTargetConsiderationDistanceSquared(i)
              && v6->size < 0x14 )
            {
              v16 = v8->m_Flags;
              if ( (v16 >> 14) & 1 )
              {
                v17 = v8->m_Components.p[3].m_pComponent;
              }
              else if ( (v16 & 0x8000u) == 0 )
              {
                if ( (v16 >> 13) & 1 )
                {
                  v17 = v8->m_Components.p[4].m_pComponent;
                }
                else if ( (v16 >> 12) & 1 )
                {
                  v18 = (unsigned int)v8[1].vfptr;
                  v19 = v8->m_Components.size;
                  if ( v18 >= v19 )
                  {
LABEL_38:
                    v17 = 0i64;
                  }
                  else
                  {
                    v20 = (signed __int64)&v8->m_Components.p[v18];
                    while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
                         || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
                    {
                      ++v18;
                      v20 += 16i64;
                      if ( v18 >= v19 )
                        goto LABEL_38;
                    }
                    v17 = *(UFG::SimComponent **)v20;
                  }
                }
                else
                {
                  v17 = UFG::SimObject::GetComponentOfType(v8, UFG::SimObjectPropertiesComponent::_TypeUID);
                }
              }
              else
              {
                v17 = v8->m_Components.p[3].m_pComponent;
              }
              if ( v17 )
              {
                v21 = v6->size;
                v22 = v21;
                v6->size = v21 + 1;
                v6->p[v22].m_pSimObjectPropertiesComponent = (UFG::SimObjectPropertiesComponent *)v17;
                v6->p[v22].m_fDistance2 = v15;
                v23 = v14[9];
                v24 = v14[10];
                v25 = v14[11];
                v6->p[v22].m_Xform.v0 = v14[8];
                v6->p[v22].m_Xform.v1 = v23;
                v6->p[v22].m_Xform.v2 = v24;
                v6->p[v22].m_Xform.v3 = v25;
              }
            }
          }
        }
      }
    }
  }
  v26 = (signed __int64)v6->p;
  UFG::qQuickSortImpl<UFG::CloseTarget,bool (*)(UFG::CloseTarget const &,UFG::CloseTarget const &)>(
    v6->p,
    (UFG::CloseTarget *)((char *)&v6[-1].p[(signed int)v6->size + 19] + 8),
    (bool (__fastcall *)(UFG::CloseTarget *, UFG::CloseTarget *))UFG::CloseTargetsSort);
  v5->size = 0;
  if ( v6->size )
  {
    v27 = v6->size;
    do
    {
      v5->p[v5->size++] = (UFG::CloseTarget *)v26;
      v26 += 80i64;
      --v27;
    }
    while ( v27 );
  }
}

// File Line: 1216
// RVA: 0x55EC80
void __fastcall UFG::TargetingSystemPedBaseComponent::UpdateCommon(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::TargetingSystemPedBaseComponent *v1; // rsi
  char v2; // di
  UFG::SimObjectProp *v3; // rcx
  UFG::SimObjectWeaponPropertiesComponent *v4; // rdx
  unsigned __int16 v5; // dx
  unsigned int v6; // er8
  unsigned int v7; // er10
  signed __int64 v8; // rdx
  unsigned int v9; // er8
  unsigned int v10; // er10
  UFG::SimObjectWeaponPropertiesComponent *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // er10
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectWeaponPropertiesComponent> *v14; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectProp *v18; // rcx
  UFG::SimObjectWeaponPropertiesComponent *v19; // rdx
  unsigned __int16 v20; // dx
  unsigned int v21; // er8
  unsigned int v22; // er10
  signed __int64 v23; // rdx
  unsigned int v24; // er8
  unsigned int v25; // er10
  UFG::SimObjectWeaponPropertiesComponent *v26; // rax
  unsigned int v27; // er8
  unsigned int v28; // er10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::SimObjectWeaponPropertiesComponent *v32; // rax
  bool v33; // zf
  UFG::SimComponent *v34; // rbx
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // eax
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4

  v1 = this;
  v2 = 0;
  v3 = (UFG::SimObjectProp *)this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[18]].m_pTarget.m_pPointer;
  if ( !v3 )
    goto LABEL_2;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->mComponentTableEntryCount;
    v7 = v3->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = (signed __int64)&v3->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v6;
        v8 += 16i64;
        if ( v6 >= v7 )
        {
          v4 = 0i64;
          goto LABEL_29;
        }
      }
LABEL_10:
      v4 = *(UFG::SimObjectWeaponPropertiesComponent **)v8;
      goto LABEL_29;
    }
    goto LABEL_2;
  }
  if ( (v5 & 0x8000u) != 0 )
  {
    v9 = v3->mComponentTableEntryCount;
    v10 = v3->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (signed __int64)&v3->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
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
  if ( (v5 >> 13) & 1 )
  {
    v11 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v3);
  }
  else
  {
    if ( (v5 >> 12) & 1 )
    {
      v12 = v3->mComponentTableEntryCount;
      v13 = v3->m_Components.size;
      if ( v12 < v13 )
      {
        v8 = (signed __int64)&v3->m_Components.p[v12];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
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
    v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v3->vfptr,
                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  v4 = v11;
LABEL_29:
  v14 = &v1->m_pEquippedSOWPC;
  if ( v1->m_pEquippedSOWPC.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = v1->m_pEquippedSOWPC.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v1->m_pEquippedSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEquippedSOWPC.mPrev;
  }
  v1->m_pEquippedSOWPC.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v17 = v4->m_SafePointerList.mNode.mPrev;
    v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v14->mPrev = v17;
    v1->m_pEquippedSOWPC.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  }
  if ( !v1->m_pEquippedSOWPC.m_pPointer )
  {
    v18 = (UFG::SimObjectProp *)v1->m_pTargets[(unsigned __int8)v1->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
    if ( !v18 )
    {
LABEL_35:
      v19 = 0i64;
LABEL_62:
      if ( v1->m_pEquippedSOWPC.m_pPointer )
      {
        v29 = v14->mPrev;
        v30 = v1->m_pEquippedSOWPC.mNext;
        v29->mNext = v30;
        v30->mPrev = v29;
        v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v1->m_pEquippedSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pEquippedSOWPC.mPrev;
      }
      v1->m_pEquippedSOWPC.m_pPointer = (UFG::SimComponent *)&v19->vfptr;
      if ( v19 )
      {
        v31 = v19->m_SafePointerList.mNode.mPrev;
        v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v14->mPrev = v31;
        v1->m_pEquippedSOWPC.mNext = &v19->m_SafePointerList.mNode;
        v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      }
      goto LABEL_66;
    }
    v20 = v18->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v21 = v18->mComponentTableEntryCount;
      v22 = v18->m_Components.size;
      if ( v21 >= v22 )
        goto LABEL_35;
      v23 = (signed __int64)&v18->m_Components.p[v21];
      while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
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
      if ( (v20 & 0x8000u) == 0 )
      {
        if ( (v20 >> 13) & 1 )
        {
          v26 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v18);
        }
        else
        {
          if ( (v20 >> 12) & 1 )
          {
            v27 = v18->mComponentTableEntryCount;
            v28 = v18->m_Components.size;
            if ( v27 >= v28 )
              goto LABEL_35;
            v23 = (signed __int64)&v18->m_Components.p[v27];
            while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
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
                                                             (UFG::SimObject *)&v18->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        v19 = v26;
        goto LABEL_62;
      }
      v24 = v18->mComponentTableEntryCount;
      v25 = v18->m_Components.size;
      if ( v24 >= v25 )
        goto LABEL_35;
      v23 = (signed __int64)&v18->m_Components.p[v24];
      while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
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
    v19 = *(UFG::SimObjectWeaponPropertiesComponent **)v23;
    goto LABEL_62;
  }
LABEL_66:
  v32 = (UFG::SimObjectWeaponPropertiesComponent *)v1->m_pEquippedSOWPC.m_pPointer;
  if ( v32
    && v32->mWeaponTypeInfo->mFireModes[v32->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID )
  {
    v2 = 1;
  }
  v33 = v1->m_pTransformNodeComponent.m_pSimComponent == 0i64;
  v1->m_bHasRangedWeapon = v2;
  if ( !v33 )
  {
    v34 = v1->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    v35 = (float)(UFG::TargetingSystemPedBaseComponent::ms_fTargetingPositionXOffset * *(float *)&v34[2].vfptr)
        + *(float *)&v34[2].m_BoundComponentHandles.mNode.mPrev;
    v36 = (float)(UFG::TargetingSystemPedBaseComponent::ms_fTargetingPositionXOffset * *((float *)&v34[2].vfptr + 1))
        + *((float *)&v34[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v1->m_vTargetingPosition.z = (float)(UFG::TargetingSystemPedBaseComponent::ms_fTargetingPositionXOffset
                                       * *(float *)&v34[2].m_SafePointerList.mNode.mPrev)
                               + *(float *)&v34[2].m_BoundComponentHandles.mNode.mNext;
    v1->m_vTargetingPosition.x = v35;
    v1->m_vTargetingPosition.y = v36;
    v37 = *(float *)&v34[2].vfptr;
    v38 = *(float *)&v34[2].m_SafePointerList.mNode.mPrev;
    v1->m_vTargetingForward.y = *((float *)&v34[2].vfptr + 1);
    v1->m_vTargetingForward.x = v37;
    v1->m_vTargetingForward.z = v38;
    v39 = *((float *)&v34[2].m_SafePointerList.mNode.mNext + 1);
    v40 = *(float *)&v34[2].m_TypeUID;
    v1->m_vTargetingLeft.x = *(float *)&v34[2].m_SafePointerList.mNode.mNext;
    v1->m_vTargetingLeft.y = v39;
    v1->m_vTargetingLeft.z = v40;
  }
}

// File Line: 1256
// RVA: 0x570C10
void __fastcall UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::CloseTarget *,80> *closePedsList)
{
  unsigned int v2; // ebp
  unsigned int v3; // ebx
  UFG::TargetingSystemPedBaseComponent *v4; // r14
  UFG::CloseTarget **v5; // rdi
  UFG::SimObject *v6; // rsi
  UFG::ActionTreeComponent *v7; // rcx
  UFG::HealthComponent *v8; // rdx
  UFG::SimComponentHolder *v9; // rax
  unsigned __int8 v10; // cl
  signed __int64 v11; // rbx
  UFG::TargetingSimObject *v12; // rax
  unsigned __int8 v13; // cl

  v2 = closePedsList->size;
  v3 = 0;
  v4 = this;
  if ( !closePedsList->size )
    goto LABEL_8;
  v5 = closePedsList->p;
  while ( 1 )
  {
    v6 = (*v5)->m_pSimObjectPropertiesComponent->m_pSimObject;
    if ( v6 )
    {
      v9 = v6->m_Components.p;
      v7 = (UFG::ActionTreeComponent *)v9[7].m_pComponent;
      v8 = (UFG::HealthComponent *)v9[6].m_pComponent;
    }
    else
    {
      v7 = 0i64;
      v8 = 0i64;
    }
    if ( !UFG::IsDowned(v7, v8) )
      break;
    ++v3;
    ++v5;
    if ( v3 >= v2 )
      goto LABEL_8;
  }
  if ( v6 )
  {
    v13 = v4->m_pTargetingMap->m_Map.p[14];
    if ( v13 )
      UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v13], v6);
  }
  else
  {
LABEL_8:
    v10 = v4->m_pTargetingMap->m_Map.p[14];
    if ( v10 )
    {
      v11 = v10;
      UFG::TargetingSimObject::SetTarget(&v4->m_pTargets[v11], 0i64);
      v12 = v4->m_pTargets;
      if ( v12[v11].m_bLock )
        v12[v11].m_bLock = 0;
    }
  }
}

// File Line: 1291
// RVA: 0x575EC0
void __fastcall UFG::TargetingSystemPedBaseComponent::updateGroupTargets(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::TargetingSystemPedBaseComponent *v1; // r13
  __int64 v2; // rdi
  UFG::SimObject *v3; // r15
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v4; // rax
  UFG::GroupComponent *v5; // rsi
  UFG::GroupComponent *v6; // rax
  UFG::GroupComponent *v7; // rbp
  UFG::PedSpawningInfo *v8; // r14
  unsigned int v9; // ebx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rcx
  unsigned __int16 v11; // cx
  UFG::PedFormationManagerComponent *v12; // rax
  unsigned int v13; // ecx
  unsigned int v14; // er9
  UFG::qNode<UFG::PedSpawningInfo,UFG::PedSpawningInfo> *v15; // rbx
  signed __int64 v16; // r8
  unsigned int v17; // ecx
  unsigned int v18; // er9
  unsigned int v19; // ecx
  unsigned int v20; // er9
  unsigned __int8 v21; // dl
  unsigned int v22; // ebx
  UFG::SimObject *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::PedFormationManagerComponent *v25; // rax
  unsigned int v26; // edx
  unsigned int v27; // er9
  UFG::SimComponentHolder *v28; // rbx
  signed __int64 v29; // r8
  unsigned int v30; // edx
  unsigned int v31; // er9
  unsigned int v32; // edx
  unsigned int v33; // er9
  unsigned __int8 v34; // cl
  signed __int64 v35; // rbx
  UFG::TargetingSimObject *v36; // rax
  unsigned __int8 v37; // cl
  signed __int64 v38; // rbx
  UFG::TargetingSimObject *v39; // rax
  unsigned int v40; // esi
  UFG::eTargetTypeEnum *v41; // r14
  UFG::GroupComponent **v42; // r15
  UFG::SimObject *v43; // rax
  unsigned __int8 v44; // dl
  signed __int64 v45; // rbx
  UFG::TargetingSimObject *v46; // rax
  int v47; // [rsp+28h] [rbp-50h]
  int v48; // [rsp+2Ch] [rbp-4Ch]
  int v49; // [rsp+30h] [rbp-48h]
  int v50; // [rsp+34h] [rbp-44h]
  int v51; // [rsp+38h] [rbp-40h]
  __int64 v52[4]; // [rsp+40h] [rbp-38h]

  v1 = this;
  v47 = 63;
  v48 = 64;
  v49 = 65;
  v50 = 66;
  v2 = 0i64;
  v51 = 0;
  v3 = 0i64;
  v4 = UFG::GroupComponent::GetGroupComponent(this->m_pSimObject);
  v5 = (UFG::GroupComponent *)v4;
  if ( !v4 )
    goto LABEL_73;
  v6 = UFG::GroupComponent::GetLeader((UFG::GroupComponent *)v4);
  v7 = v6;
  if ( !v6 )
  {
    if ( !UFG::GroupComponent::IsLeader(v5) )
      goto LABEL_73;
    v22 = 0;
    if ( Scaleform::Render::Hairliner::GetMeshVertexCount(v5) )
    {
      do
      {
        if ( (unsigned int)v2 < 4 )
        {
          v52[v2] = (__int64)UFG::GroupComponent::GetFollower(v5, v22);
          v2 = (unsigned int)(v51++ + 1);
        }
        ++v22;
      }
      while ( v22 < Scaleform::Render::Hairliner::GetMeshVertexCount(v5) );
    }
    v23 = v1->m_pSimObject;
    if ( !v23 )
      goto LABEL_73;
    v24 = v23->m_Flags;
    if ( (v24 >> 14) & 1 )
    {
      v25 = (UFG::PedFormationManagerComponent *)v23->m_Components.p[33].m_pComponent;
      goto LABEL_71;
    }
    if ( (v24 & 0x8000u) == 0 )
    {
      if ( (v24 >> 13) & 1 )
      {
        v30 = (unsigned int)v23[1].vfptr;
        v31 = v23->m_Components.size;
        if ( v30 < v31 )
        {
          v28 = v23->m_Components.p;
          do
          {
            v29 = v30;
            if ( (v28[v30].m_TypeUID & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && !(UFG::PedFormationManagerComponent::_TypeUID & ~v28[v30].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_54;
            }
          }
          while ( ++v30 < v31 );
        }
      }
      else
      {
        if ( !((v24 >> 12) & 1) )
        {
          v25 = (UFG::PedFormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                       v23,
                                                       UFG::PedFormationManagerComponent::_TypeUID);
LABEL_71:
          if ( v25 )
            v3 = UFG::PedFormationManagerComponent::GetLeadersPair(v25);
          goto LABEL_73;
        }
        v32 = (unsigned int)v23[1].vfptr;
        v33 = v23->m_Components.size;
        if ( v32 < v33 )
        {
          v28 = v23->m_Components.p;
          do
          {
            v29 = v32;
            if ( (v28[v32].m_TypeUID & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && !(UFG::PedFormationManagerComponent::_TypeUID & ~v28[v32].m_TypeUID & 0x1FFFFFF) )
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
      v26 = (unsigned int)v23[1].vfptr;
      v27 = v23->m_Components.size;
      if ( v26 < v27 )
      {
        v28 = v23->m_Components.p;
        while ( 1 )
        {
          v29 = v26;
          if ( (v28[v26].m_TypeUID & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
            && !(UFG::PedFormationManagerComponent::_TypeUID & ~v28[v26].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v26 >= v27 )
            goto LABEL_55;
        }
LABEL_54:
        v25 = (UFG::PedFormationManagerComponent *)v28[v29].m_pComponent;
        goto LABEL_71;
      }
    }
LABEL_55:
    v25 = 0i64;
    goto LABEL_71;
  }
  v8 = UFG::GroupComponent::GetSimObjectPtr(v6);
  if ( v8 )
  {
    v52[0] = (__int64)v7;
    LODWORD(v2) = 1;
    v51 = 1;
    v9 = 0;
    if ( Scaleform::Render::Hairliner::GetMeshVertexCount(v7) )
    {
      do
      {
        v10 = UFG::GroupComponent::GetFollower(v7, v9);
        if ( v5 != (UFG::GroupComponent *)v10 && (unsigned int)v2 < 4 )
        {
          v52[(unsigned int)v2] = (__int64)v10;
          LODWORD(v2) = v51++ + 1;
        }
        ++v9;
      }
      while ( v9 < Scaleform::Render::Hairliner::GetMeshVertexCount(v7) );
    }
    v11 = WORD2(v8->mNext);
    if ( (v11 >> 14) & 1 )
    {
      v12 = (UFG::PedFormationManagerComponent *)v8->mNext[33].mPrev;
LABEL_35:
      if ( v12 )
        v3 = (UFG::SimObject *)UFG::PedFormationManagerComponent::GetFollowersPair(v12, v1->m_pSimObject);
      v21 = v1->m_pTargetingMap->m_Map.p[62];
      if ( v21 )
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v21], (UFG::SimObject *)v8);
      goto LABEL_76;
    }
    if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v17 = v8->mPedIndex;
        v18 = (unsigned int)v8->mPrev;
        if ( v17 < v18 )
        {
          v15 = v8->mNext;
          do
          {
            v16 = v17;
            if ( ((_QWORD)v15[v17].mNext & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && !(UFG::PedFormationManagerComponent::_TypeUID & ~LODWORD(v15[v17].mNext) & 0x1FFFFFF) )
            {
              goto LABEL_18;
            }
          }
          while ( ++v17 < v18 );
        }
      }
      else
      {
        if ( !((v11 >> 12) & 1) )
        {
          v12 = (UFG::PedFormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)v8,
                                                       UFG::PedFormationManagerComponent::_TypeUID);
          goto LABEL_35;
        }
        v19 = v8->mPedIndex;
        v20 = (unsigned int)v8->mPrev;
        if ( v19 < v20 )
        {
          v15 = v8->mNext;
          do
          {
            v16 = v19;
            if ( ((_QWORD)v15[v19].mNext & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
              && !(UFG::PedFormationManagerComponent::_TypeUID & ~LODWORD(v15[v19].mNext) & 0x1FFFFFF) )
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
      v13 = v8->mPedIndex;
      v14 = (unsigned int)v8->mPrev;
      if ( v13 < v14 )
      {
        v15 = v8->mNext;
        while ( 1 )
        {
          v16 = v13;
          if ( ((_QWORD)v15[v13].mNext & 0xFE000000) == (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
            && !(UFG::PedFormationManagerComponent::_TypeUID & ~LODWORD(v15[v13].mNext) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v13 >= v14 )
            goto LABEL_19;
        }
LABEL_18:
        v12 = (UFG::PedFormationManagerComponent *)v15[v16].mPrev;
        goto LABEL_35;
      }
    }
LABEL_19:
    v12 = 0i64;
    goto LABEL_35;
  }
LABEL_73:
  v34 = v1->m_pTargetingMap->m_Map.p[62];
  if ( v34 )
  {
    v35 = v34;
    UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v35], 0i64);
    v36 = v1->m_pTargets;
    if ( v36[v35].m_bLock )
      v36[v35].m_bLock = 0;
  }
LABEL_76:
  v37 = v1->m_pTargetingMap->m_Map.p[67];
  if ( v3 )
  {
    if ( v37 )
      UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v37], v3);
  }
  else if ( v37 )
  {
    v38 = v37;
    UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v38], 0i64);
    v39 = v1->m_pTargets;
    if ( v39[v38].m_bLock )
      v39[v38].m_bLock = 0;
  }
  v40 = 0;
  v41 = (UFG::eTargetTypeEnum *)&v47;
  v42 = (UFG::GroupComponent **)v52;
  do
  {
    if ( v40 >= (unsigned int)v2 )
    {
      v44 = v1->m_pTargetingMap->m_Map.p[*(unsigned int *)v41];
      if ( v44 )
      {
        v45 = v44;
        UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v45], 0i64);
        v46 = v1->m_pTargets;
        if ( v46[v45].m_bLock )
          v46[v45].m_bLock = 0;
      }
    }
    else
    {
      v43 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(*v42);
      UFG::TargetingSystemBaseComponent::SetTarget((UFG::TargetingSystemBaseComponent *)&v1->vfptr, *v41, v43);
    }
    ++v40;
    ++v42;
    ++v41;
  }
  while ( v40 < 4 );
}

// File Line: 1430
// RVA: 0x576720
void __fastcall UFG::TargetingSystemPedBaseComponent::updatePickupTarget(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::CloseTarget *,5> *closePickupsList)
{
  UFG::TargetingSystemPedBaseComponent *v2; // rbp
  UFG::TargetingSimObject *v3; // r8
  unsigned int v4; // er14
  unsigned int v5; // edi
  unsigned int v6; // er11
  UFG::CloseTarget **v7; // rsi
  UFG::SimObject *v8; // rbx
  unsigned __int16 v9; // cx
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  UFG::SimComponent *v13; // rax
  unsigned int v14; // er8
  unsigned int v15; // er9
  unsigned int v16; // er8
  unsigned int v17; // er9
  unsigned int v18; // er8
  unsigned int v19; // er9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rdx
  __int64 v21; // rax
  signed int v22; // eax
  unsigned __int8 v23; // cl
  signed __int64 v24; // rbx
  UFG::TargetingSimObject *v25; // rax
  unsigned __int8 v26; // cl

  v2 = this;
  v3 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[41]];
  if ( !v3->m_pTarget.m_pPointer || !v3->m_bLock )
  {
    v4 = closePickupsList->size;
    v5 = 0;
    if ( closePickupsList->size )
    {
      v6 = UFG::GunComponent::_TypeUID;
      v7 = closePickupsList->p;
      do
      {
        v8 = (*v7)->m_pSimObjectPropertiesComponent->m_pSimObject;
        if ( !v8 )
          break;
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = (unsigned int)v8[1].vfptr;
          v11 = v8->m_Components.size;
          if ( v10 < v11 )
          {
            v12 = (signed __int64)&v8->m_Components.p[v10];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
            {
              ++v10;
              v12 += 16i64;
              if ( v10 >= v11 )
                goto LABEL_12;
            }
LABEL_13:
            v13 = *(UFG::SimComponent **)v12;
            goto LABEL_36;
          }
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v16 = (unsigned int)v8[1].vfptr;
            v17 = v8->m_Components.size;
            if ( v16 < v17 )
            {
              v12 = (signed __int64)&v8->m_Components.p[v16];
              while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
              {
                ++v16;
                v12 += 16i64;
                if ( v16 >= v17 )
                {
                  v13 = 0i64;
                  goto LABEL_36;
                }
              }
              goto LABEL_13;
            }
          }
          else
          {
            if ( !((v9 >> 12) & 1) )
            {
              v13 = UFG::SimObject::GetComponentOfType(v8, v6);
              v6 = UFG::GunComponent::_TypeUID;
              goto LABEL_36;
            }
            v18 = (unsigned int)v8[1].vfptr;
            v19 = v8->m_Components.size;
            if ( v18 < v19 )
            {
              v12 = (signed __int64)&v8->m_Components.p[v18];
              while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
              {
                ++v18;
                v12 += 16i64;
                if ( v18 >= v19 )
                {
                  v13 = 0i64;
                  goto LABEL_36;
                }
              }
              goto LABEL_13;
            }
          }
        }
        else
        {
          v14 = (unsigned int)v8[1].vfptr;
          v15 = v8->m_Components.size;
          if ( v14 < v15 )
          {
            v12 = (signed __int64)&v8->m_Components.p[v14];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (v6 & 0xFE000000) || v6 & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
            {
              ++v14;
              v12 += 16i64;
              if ( v14 >= v15 )
              {
                v13 = 0i64;
                goto LABEL_36;
              }
            }
            goto LABEL_13;
          }
        }
LABEL_12:
        v13 = 0i64;
LABEL_36:
        if ( !v13
          || ((v20 = v13[2].m_BoundComponentHandles.mNode.mNext[6].mPrev) == 0i64 ? (v22 = 0) : (v21 = *(signed int *)(*((_QWORD *)&v13[2].m_SafePointerList.mNode.mPrev[11].mPrev->mNext + HIDWORD(v13[2].m_SafePointerList.mNode.mPrev[10].mNext)) + 4i64),
                                                                                                 !LOBYTE(v20[58].mNext))
                                                                                             || (_DWORD)v21 != LODWORD(v20[58].mPrev) ? (v22 = *((_DWORD *)&v20[5].mNext + v21 + 1)) : (v22 = 1),
              v22 <= 0) )
        {
          if ( !v8 )
            break;
          v26 = v2->m_pTargetingMap->m_Map.p[41];
          if ( v26 )
            UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v26], v8);
          return;
        }
        ++v5;
        ++v7;
      }
      while ( v5 < v4 );
    }
    v23 = v2->m_pTargetingMap->m_Map.p[41];
    if ( v23 )
    {
      v24 = v23;
      UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v24], 0i64);
      v25 = v2->m_pTargets;
      if ( v25[v24].m_bLock )
        v25[v24].m_bLock = 0;
    }
  }
}

// File Line: 1486
// RVA: 0x57B730
void __fastcall UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::eTargetTypeEnum *v1; // r14
  signed __int64 v2; // r15
  UFG::TargetingSystemPedBaseComponent *v3; // rbp
  UFG::eTargetTypeEnum *v4; // rdi
  signed __int64 v5; // rsi
  unsigned __int8 v6; // r8
  signed __int64 v7; // rbx
  UFG::TargetingSimObject *v8; // rax
  UFG::SimObject *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rbx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // er8
  signed __int64 v16; // rbx
  unsigned int v17; // edx
  unsigned int v18; // er8
  __int64 v19; // rdx
  UFG::SimObject *v20; // r8

  v1 = UFG::TargetingSystemBaseComponent::ms_eVehicleRoleTargetTypes;
  v2 = 7i64;
  v3 = this;
  v4 = UFG::TargetingSystemBaseComponent::ms_eVehicleRoleTargetTypes;
  v5 = 7i64;
  do
  {
    v6 = v3->m_pTargetingMap->m_Map.p[*(unsigned int *)v4];
    if ( v6 )
    {
      v7 = v6;
      UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v7], 0i64);
      v8 = v3->m_pTargets;
      if ( v8[v7].m_bLock )
        v8[v7].m_bLock = 0;
    }
    ++v4;
    --v5;
  }
  while ( v5 );
  v9 = v3->m_pTargets[(unsigned __int8)v3->m_pTargetingMap->m_Map.p[28]].m_pTarget.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v9->m_Components.p[20].m_pComponent;
      if ( !v11 )
        goto LABEL_11;
      v12 = v11->m_TypeUID;
      if ( (v12 ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000
        || UFG::TargetingSystemVehicleComponent::_TypeUID & ~v12 & 0x1FFFFFF )
      {
        goto LABEL_11;
      }
LABEL_33:
      if ( v11 )
      {
        do
        {
          v19 = *(unsigned int *)v1;
          v20 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(v19 + *(_QWORD *)&v11[1].m_Flags + 8)
                                   + *(_QWORD *)&v11[1].m_TypeUID
                                   + 40);
          if ( v20 )
            UFG::TargetingSystemBaseComponent::SetTarget(
              (UFG::TargetingSystemBaseComponent *)&v3->vfptr,
              (UFG::eTargetTypeEnum)v19,
              v20);
          ++v1;
          --v2;
        }
        while ( v2 );
      }
      return;
    }
    if ( (v10 & 0x8000u) != 0 )
    {
      v11 = v9->m_Components.p[20].m_pComponent;
      if ( v11 )
      {
        v13 = v11->m_TypeUID;
        if ( !((v13 ^ UFG::TargetingSystemVehicleComponent::_TypeUID) & 0xFE000000) )
        {
          if ( UFG::TargetingSystemVehicleComponent::_TypeUID & ~v13 & 0x1FFFFFF )
            v11 = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_11;
    }
    if ( (v10 >> 13) & 1 )
    {
      v14 = (unsigned int)v9[1].vfptr;
      v15 = v9->m_Components.size;
      if ( v14 < v15 )
      {
        v16 = (signed __int64)&v9->m_Components.p[v14];
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
        {
          ++v14;
          v16 += 16i64;
          if ( v14 >= v15 )
          {
            v11 = 0i64;
            goto LABEL_33;
          }
        }
LABEL_24:
        v11 = *(UFG::SimComponent **)v16;
        goto LABEL_33;
      }
    }
    else
    {
      if ( !((v10 >> 12) & 1) )
      {
        v11 = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemVehicleComponent::_TypeUID);
        goto LABEL_33;
      }
      v17 = (unsigned int)v9[1].vfptr;
      v18 = v9->m_Components.size;
      if ( v17 < v18 )
      {
        v16 = (signed __int64)&v9->m_Components.p[v17];
        while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::TargetingSystemVehicleComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemVehicleComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
        {
          ++v17;
          v16 += 16i64;
          if ( v17 >= v18 )
          {
            v11 = 0i64;
            goto LABEL_33;
          }
        }
        goto LABEL_24;
      }
    }
LABEL_11:
    v11 = 0i64;
    goto LABEL_33;
  }
}

// File Line: 1517
// RVA: 0x56C090
float __fastcall UFG::TargetingSystemPedBaseComponent::scoreBasic(const float fDistanceSquared, const float fMaxDistanceSquared, const float fAngleDiffRad)
{
  float v3; // xmm7_4

  v3 = (float)(1.0
             - UFG::LinearTable<float>::GetValue(
                 &UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetTable,
                 1.0 - (float)(fDistanceSquared / fMaxDistanceSquared)))
     * UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias;
  return v3
       + (float)(UFG::LinearTable<float>::GetValue(
                   &UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterTable,
                   fAngleDiffRad * 0.31830987)
               * (float)(1.0 - UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias));
}

// File Line: 1540
// RVA: 0x567890
UFG::SimObject *__fastcall UFG::TargetingSystemPedBaseComponent::findBestTarget(UFG::qVector3 *vTargetingPosition, UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList, UFG::qVector3 *vTargetingIntention, float fMaxDistanceSquared, float angle)
{
  UFG::qVector3 *v5; // r14
  UFG::qVector3 *v6; // rbp
  UFG::CloseTarget **v7; // rdi
  __int64 v8; // rsi
  void (__fastcall *v9)(void *); // r15
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  int v15; // eax
  __int64 v16; // rbx
  float v17; // xmm9_4
  float v18; // xmm7_4
  unsigned int v19; // xmm1_4
  UFG::SimObject *result; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-718h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-708h]
  __int64 v23; // [rsp+40h] [rbp-6F8h]
  ClassTypeDescriptor right; // [rsp+48h] [rbp-6F0h]
  ClassTypeDescriptor left[108]; // [rsp+58h] [rbp-6E0h]

  v23 = -2i64;
  v5 = vTargetingIntention;
  v6 = vTargetingPosition;
  LODWORD(right.mfnInPlaceNew) = 0;
  if ( closeVehiclesList->size )
  {
    v7 = closeVehiclesList->p;
    v8 = closeVehiclesList->size;
    while ( 1 )
    {
      v9 = (void (__fastcall *)(void *))(*v7)->m_pSimObjectPropertiesComponent->m_pSimObject;
      v10 = (*v7)->m_Xform.v3.z - v6->z;
      v11 = (*v7)->m_Xform.v3.y - v6->y;
      v12 = (*v7)->m_Xform.v3.x - v6->x;
      v1.x = (*v7)->m_Xform.v3.x - v6->x;
      v1.y = v11;
      v1.z = 0.0;
      v13 = v5->y;
      v2.x = v5->x;
      v2.y = v13;
      v2.z = 0.0;
      v14 = UFG::qAngleBetween(&v1, &v2);
      if ( angle < v14 )
        goto LABEL_6;
      v15 = (int)right.mfnInPlaceNew;
      if ( LODWORD(right.mfnInPlaceNew) < 0x64 )
        break;
LABEL_7:
      ++v7;
      if ( !--v8 )
        goto LABEL_10;
    }
    v16 = LODWORD(right.mfnInPlaceNew);
    ++LODWORD(right.mfnInPlaceNew);
    v17 = v14 * 0.31830987;
    v18 = (float)(1.0
                - UFG::LinearTable<float>::GetValue(
                    &UFG::TargetingSystemPedBaseComponent::ms_CloseToTargetTable,
                    1.0
                  - (float)((float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10))
                          / fMaxDistanceSquared)))
        * UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias;
    *(float *)&v19 = (float)((float)(1.0 - UFG::TargetingSystemPedBaseComponent::ms_fCloseToTargetBias)
                           * UFG::LinearTable<float>::GetValue(
                               &UFG::TargetingSystemPedBaseComponent::ms_CloseToCenterTable,
                               v17))
                   + v18;
    left[v16].mfnInPlaceNew = v9;
    left[v16].mUID = v19;
LABEL_6:
    v15 = (int)right.mfnInPlaceNew;
    goto LABEL_7;
  }
  v15 = (int)right.mfnInPlaceNew;
LABEL_10:
  UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
    left,
    &right + v15,
    (bool (__fastcall *)(ClassTypeDescriptor *, ClassTypeDescriptor *))UFG::CloseTargetsSort);
  result = 0i64;
  if ( LODWORD(right.mfnInPlaceNew) )
    result = (UFG::SimObject *)left[0].mfnInPlaceNew;
  return result;
}

// File Line: 1589
// RVA: 0x57BC40
void __fastcall UFG::TargetingSystemPedBaseComponent::updateVehicleTarget(UFG::TargetingSystemPedBaseComponent *this, UFG::qFixedArray<UFG::CloseTarget *,20> *closeVehiclesList)
{
  UFG::TargetingSystemPedBaseComponent *v2; // rdi
  UFG::TargetingMap *v3; // rcx
  UFG::TargetingSimObject *v4; // rax
  signed __int64 v5; // rbx
  UFG::SimObject *v6; // rbx
  signed __int64 v7; // rcx
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned __int8 v13; // cl
  signed __int64 v14; // rbx
  UFG::TargetingSimObject *v15; // rax
  unsigned __int8 v16; // al

  v2 = this;
  v3 = this->m_pTargetingMap;
  v4 = v2->m_pTargets;
  v5 = (unsigned __int8)v3->m_Map.p[eTARGET_TYPE_VEHICLE];
  if ( v4[v5].m_pTarget.m_pPointer && v4[v5].m_bLock )
  {
    v6 = v4[v5].m_pTarget.m_pPointer;
  }
  else
  {
    v7 = (unsigned __int8)v3->m_Map.p[eTARGET_TYPE_FOCUS];
    v6 = v4[v7].m_pTarget.m_pPointer;
    if ( v6 && v4[v7].m_bLock )
    {
      v8 = v6->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = v6->m_Components.p[3].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = v6->m_Components.p[4].m_pComponent;
        }
        else if ( (v8 >> 12) & 1 )
        {
          v10 = (unsigned int)v6[1].vfptr;
          v11 = v6->m_Components.size;
          if ( v10 >= v11 )
          {
LABEL_18:
            v9 = 0i64;
          }
          else
          {
            v12 = (signed __int64)&v6->m_Components.p[v10];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
                 || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
            {
              ++v10;
              v12 += 16i64;
              if ( v10 >= v11 )
                goto LABEL_18;
            }
            v9 = *(UFG::SimComponent **)v12;
          }
        }
        else
        {
          v9 = UFG::SimObject::GetComponentOfType(v6, UFG::SimObjectPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v9 = v6->m_Components.p[3].m_pComponent;
      }
      if ( v9 && LODWORD(v9[1].m_SafePointerList.mNode.mNext) != 4 )
        goto LABEL_23;
    }
    else
    {
      v6 = UFG::TargetingSystemPedBaseComponent::findBestTarget(
             &v2->m_vTargetingPosition,
             closeVehiclesList,
             &v2->m_vTargetingIntention,
             v2->m_pActiveTargetingProfile->m_ConeDistancesSquared[3],
             v2->m_pActiveTargetingProfile->m_HalfHorizontalFOVs[3]);
    }
  }
  if ( !v6 )
  {
LABEL_23:
    v13 = v2->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
    if ( v13 )
    {
      v14 = v13;
      UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v14], 0i64);
      v15 = v2->m_pTargets;
      if ( v15[v14].m_bLock )
        v15[v14].m_bLock = 0;
    }
    goto LABEL_26;
  }
  v16 = v2->m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE];
  if ( !v16 )
  {
LABEL_26:
    UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v2);
    return;
  }
  UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v16], v6);
  UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v2);
}

// File Line: 1667
// RVA: 0x549CD0
void __fastcall UFG::TargetingSystemPedBaseComponent::Reset(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::TargetingSystemPedBaseComponent *v1; // rbx
  unsigned int *v2; // rcx

  v1 = this;
  UFG::TargetingSystemBaseComponent::shutdown((UFG::TargetingSystemBaseComponent *)&this->vfptr);
  UFG::TargetingSystemBaseComponent::initialize((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
  v2 = v1->m_pBucketList;
  v1->m_CachedPedsList.size = 0;
  if ( v2 )
  {
    --v2[v1->m_uUpdateBucket];
    v1->m_pBucketList = 0i64;
  }
  UFG::TargetingSystemPedBaseComponent::initialize(v1);
}

// File Line: 1677
// RVA: 0x54BBE0
void __fastcall UFG::TargetingSystemPedBaseComponent::SetActiveTargetingProfile(UFG::TargetingSystemPedBaseComponent *this, UFG::qSymbol *theTargetingProfileSymbol)
{
  UFG::qSymbol *v2; // rbx
  unsigned int v3; // edx
  UFG::TargetingSystemPedBaseComponent *v4; // rdi
  UFG::qBaseTreeRB *v5; // rax
  char *v6; // rax

  v2 = theTargetingProfileSymbol;
  v3 = theTargetingProfileSymbol->mUID;
  v4 = this;
  if ( v3 && (v5 = UFG::qBaseTreeRB::Get(&UFG::TargetingProfiles::ms_TargetingProfiles.mTree, v3)) != 0i64 )
  {
    v4->m_pActiveTargetingProfile = (UFG::TargetingProfile *)v5;
  }
  else
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v2);
    UFG::qPrintf("WARNING: Could Not Set Active Targeting Profile: %s\n", v6);
  }
}

// File Line: 1692
// RVA: 0x556A10
void __fastcall UFG::TargetingSystemPedBaseComponent::TeleportEventHandler(UFG::TargetingSystemPedBaseComponent *this, UFG::Event *this_event)
{
  UFG::TargetingMap *v2; // rax
  UFG::TargetingSystemPedBaseComponent *v3; // rdi
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::InterestPoint *v6; // rbx
  unsigned __int8 v7; // cl
  signed __int64 v8; // rbx
  UFG::TargetingSimObject *v9; // rax
  unsigned __int8 v10; // cl
  signed __int64 v11; // rbx
  UFG::TargetingSimObject *v12; // rax

  v2 = this->m_pTargetingMap;
  this->m_bForceUpdate = 1;
  v3 = this;
  v4 = this->m_pTargets[(unsigned __int8)v2->m_Map.p[26]].m_pTarget.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::InterestPoint *)v4->m_Components.p[25].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::InterestPoint *)v4->m_Components.p[10].m_pComponent;
      else
        v6 = (UFG::InterestPoint *)((v5 >> 12) & 1 ? v4->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                            v4,
                                                                                            UFG::InterestPoint::_TypeUID));
    }
    else
    {
      v6 = (UFG::InterestPoint *)v4->m_Components.p[25].m_pComponent;
    }
    if ( v6 )
    {
      UFG::InterestPoint::FinishUsing(v6);
      UFG::InterestPoint::EndReservation(v6);
    }
  }
  v7 = v3->m_pTargetingMap->m_Map.p[26];
  if ( v7 )
  {
    v8 = v7;
    UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v8], 0i64);
    v9 = v3->m_pTargets;
    if ( v9[v8].m_bLock )
      v9[v8].m_bLock = 0;
  }
  v10 = v3->m_pTargetingMap->m_Map.p[25];
  if ( v10 )
  {
    v11 = v10;
    UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v11], 0i64);
    v12 = v3->m_pTargets;
    if ( v12[v11].m_bLock )
      v12[v11].m_bLock = 0;
  }
}

// File Line: 1727
// RVA: 0x54EE70
void __fastcall UFG::TargetingSystemPedBaseComponent::SetTargetLock(UFG::TargetingSystemPedBaseComponent *this, UFG::eTargetTypeEnum eTargetType, const bool bLock, const bool bModifyCollisionAccordingToLock)
{
  __int64 v4; // rdi
  bool v5; // r14
  UFG::TargetingSystemPedBaseComponent *v6; // rsi
  UFG::SimObject *v7; // rbx
  UFG::SimObject *v8; // rdx
  unsigned __int8 v9; // cl
  UFG::TargetingSimObject *v10; // rcx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rbx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // er8
  unsigned int v16; // er9
  signed __int64 v17; // rdx
  unsigned int v18; // er8
  unsigned int v19; // er9
  __int64 v20; // rdi
  unsigned __int8 v21; // al
  signed __int64 v22; // rcx
  signed __int64 v23; // rax

  v4 = (unsigned int)eTargetType;
  v5 = bLock;
  v6 = this;
  v7 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer;
  if ( v7
    && (unsigned int)(eTargetType - eTARGET_TYPE_FACING) > 1
    && eTargetType != eTARGET_TYPE_PICKUP_ITEM
    && bModifyCollisionAccordingToLock )
  {
    v8 = this->m_pSimObject;
    if ( bLock )
      UFG::PhysicsSystem::DisableCollisionsBetween((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v8, v7);
    else
      UFG::PhysicsSystem::ReEnableCollisionsBetween((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v8, v7);
  }
  v9 = v6->m_pTargetingMap->m_Map.p[v4];
  if ( v9 )
  {
    v10 = &v6->m_pTargets[v9];
    if ( v10->m_bLock != v5 )
      v10->m_bLock = v5;
  }
  if ( (_DWORD)v4 == eTARGET_TYPE_GRAPPLE
    && v6->m_pTargetingMap->m_Map.p[eTARGET_TYPE_GRAPPLE]
    && v7
    && v6->m_pSimObject != v7 )
  {
    v11 = v7->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v7->m_Components.p[20].m_pComponent;
      if ( !v12 )
        goto LABEL_19;
      v13 = v12->m_TypeUID;
      if ( (v13 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000
        || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v13 & 0x1FFFFFF )
      {
        goto LABEL_19;
      }
LABEL_41:
      if ( v12 )
      {
        v20 = (unsigned __int8)v6->m_pTargetingMap->m_Map.p[eTARGET_TYPE_GRAPPLE];
        if ( v5 )
        {
          v21 = *(_BYTE *)(*(_QWORD *)&v12[1].m_Flags + 31i64);
          if ( v21 )
            UFG::TargetingSimObject::SetTarget(
              (UFG::TargetingSimObject *)(*(_QWORD *)&v12[1].m_TypeUID + 56i64 * v21),
              v6->m_pSimObject);
          v22 = *(_QWORD *)&v12[1].m_TypeUID + 56 * v20;
          if ( *(_BYTE *)(v22 + 49) ^ 1 )
            *(_BYTE *)(v22 + 49) = 1;
        }
        else
        {
          v23 = *(_QWORD *)&v12[1].m_TypeUID + 56 * v20;
          if ( *(_BYTE *)(v23 + 49) )
            *(_BYTE *)(v23 + 49) = 0;
        }
      }
      return;
    }
    if ( (v11 & 0x8000u) != 0 )
    {
      v12 = v7->m_Components.p[20].m_pComponent;
      if ( v12 )
      {
        v14 = v12->m_TypeUID;
        if ( !((v14 ^ UFG::TargetingSystemPedBaseComponent::_TypeUID) & 0xFE000000) )
        {
          if ( UFG::TargetingSystemPedBaseComponent::_TypeUID & ~v14 & 0x1FFFFFF )
            v12 = 0i64;
          goto LABEL_41;
        }
      }
      goto LABEL_19;
    }
    if ( (v11 >> 13) & 1 )
    {
      v15 = (unsigned int)v7[1].vfptr;
      v16 = v7->m_Components.size;
      if ( v15 < v16 )
      {
        v17 = (signed __int64)&v7->m_Components.p[v15];
        while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
        {
          ++v15;
          v17 += 16i64;
          if ( v15 >= v16 )
          {
            v12 = 0i64;
            goto LABEL_41;
          }
        }
LABEL_32:
        v12 = *(UFG::SimComponent **)v17;
        goto LABEL_41;
      }
    }
    else
    {
      if ( !((v11 >> 12) & 1) )
      {
        v12 = UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemPedBaseComponent::_TypeUID);
        goto LABEL_41;
      }
      v18 = (unsigned int)v7[1].vfptr;
      v19 = v7->m_Components.size;
      if ( v18 < v19 )
      {
        v17 = (signed __int64)&v7->m_Components.p[v18];
        while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::TargetingSystemPedBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemPedBaseComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
        {
          ++v18;
          v17 += 16i64;
          if ( v18 >= v19 )
          {
            v12 = 0i64;
            goto LABEL_41;
          }
        }
        goto LABEL_32;
      }
    }
LABEL_19:
    v12 = 0i64;
    goto LABEL_41;
  }
}

// File Line: 1861
// RVA: 0x530360
UFG::SubTargetingProfile *__fastcall UFG::TargetingSystemPedBaseComponent::GetSubTargetingProfileForTarget(UFG::TargetingSystemPedBaseComponent *this, UFG::SimObject *pTargetSimObject, __int64 a3)
{
  UFG::SimObject *v3; // r9
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // er10
  UFG::SimComponentHolder *v7; // rdx
  UFG::SubTargetingProfile *result; // rax

  v3 = pTargetSimObject;
  if ( !pTargetSimObject )
    goto LABEL_22;
  v4 = pTargetSimObject->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = pTargetSimObject->m_Components.p[3].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = pTargetSimObject->m_Components.p[4].m_pComponent;
    }
    else if ( (v4 >> 12) & 1 )
    {
      a3 = LODWORD(pTargetSimObject[1].vfptr);
      v6 = pTargetSimObject->m_Components.size;
      if ( (unsigned int)a3 >= v6 )
      {
LABEL_14:
        v5 = 0i64;
      }
      else
      {
        v7 = &pTargetSimObject->m_Components.p[(unsigned int)a3];
        while ( (v7->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectPropertiesComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF )
        {
          a3 = (unsigned int)(a3 + 1);
          ++v7;
          if ( (unsigned int)a3 >= v6 )
            goto LABEL_14;
        }
        v5 = v7->m_pComponent;
      }
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType(pTargetSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    v5 = pTargetSimObject->m_Components.p[3].m_pComponent;
  }
  if ( v5 )
    result = (UFG::SubTargetingProfile *)((__int64 (__fastcall *)(UFG::SimComponent *, UFG::qSafePointerNode<UFG::SimComponent>Vtbl *, __int64, UFG::SimObject *))v5->vfptr[14].__vecDelDtor)(
                                           v5,
                                           v5->vfptr,
                                           a3,
                                           v3);
  else
LABEL_22:
    result = 0i64;
  return result;
}

// File Line: 1876
// RVA: 0x530590
signed __int64 __fastcall UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(UFG::TargetingSystemPedBaseComponent *this, UFG::SimObject *pTargetSimObject)
{
  UFG::SimObject *v2; // rsi
  UFG::TargetingSystemPedBaseComponent *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::AttackRightsComponent *v5; // rax
  unsigned int v6; // er8
  unsigned int v7; // er9
  signed __int64 v8; // rdx
  unsigned int v9; // er8
  unsigned int v10; // er9
  unsigned int v11; // er8
  unsigned int v12; // er9
  UFG::SimComponent *v14; // rcx
  unsigned __int16 v15; // cx
  unsigned int v16; // er8
  unsigned int v17; // er9
  signed __int64 v18; // rdx
  unsigned int v19; // er8
  unsigned int v20; // er9
  UFG::SimComponent *v21; // rax
  UFG::eFactionClassEnum v22; // ebx
  UFG::eFactionClassEnum v23; // edi
  UFG::GameStatTracker *v24; // rax
  unsigned int v25; // ebx
  unsigned __int16 v26; // dx
  UFG::SimComponent *v27; // rdx
  unsigned int v28; // er8
  unsigned int v29; // er9
  signed __int64 v30; // rdx
  unsigned int v31; // er8
  unsigned int v32; // er9

  v2 = pTargetSimObject;
  v3 = this;
  if ( !this->m_pActiveAIEntityComponent.m_pSimComponent )
    goto LABEL_31;
  if ( !pTargetSimObject )
  {
LABEL_32:
    v14 = 0i64;
    goto LABEL_59;
  }
  v4 = pTargetSimObject->m_Flags;
  if ( !((v4 >> 14) & 1) )
  {
    if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v9 = (unsigned int)v2[1].vfptr;
        v10 = v2->m_Components.size;
        if ( v9 < v10 )
        {
          v8 = (signed __int64)&v2->m_Components.p[v9];
          while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
               || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
          {
            ++v9;
            v8 += 16i64;
            if ( v9 >= v10 )
            {
              v5 = 0i64;
              goto LABEL_28;
            }
          }
          goto LABEL_12;
        }
      }
      else
      {
        if ( !((v4 >> 12) & 1) )
        {
          v5 = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                               v2,
                                               UFG::AttackRightsComponent::_TypeUID);
          goto LABEL_28;
        }
        v11 = (unsigned int)v2[1].vfptr;
        v12 = v2->m_Components.size;
        if ( v11 < v12 )
        {
          v8 = (signed __int64)&v2->m_Components.p[v11];
          while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
               || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
          {
            ++v11;
            v8 += 16i64;
            if ( v11 >= v12 )
            {
              v5 = 0i64;
              goto LABEL_28;
            }
          }
          goto LABEL_12;
        }
      }
    }
    else
    {
      v6 = (unsigned int)v2[1].vfptr;
      v7 = v2->m_Components.size;
      if ( v6 < v7 )
      {
        v8 = (signed __int64)&v2->m_Components.p[v6];
        while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
             || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
        {
          ++v6;
          v8 += 16i64;
          if ( v6 >= v7 )
            goto LABEL_11;
        }
LABEL_12:
        v5 = *(UFG::AttackRightsComponent **)v8;
        goto LABEL_28;
      }
    }
LABEL_11:
    v5 = 0i64;
    goto LABEL_28;
  }
  v5 = (UFG::AttackRightsComponent *)v2->m_Components.p[46].m_pComponent;
LABEL_28:
  if ( v5
    && UFG::ActiveAIEntityComponent::IsEnemyOfMine(
         (UFG::ActiveAIEntityComponent *)v3->m_pActiveAIEntityComponent.m_pSimComponent,
         v5) )
  {
    return 2i64;
  }
LABEL_31:
  if ( !v2 )
    goto LABEL_32;
  v15 = v2->m_Flags;
  if ( (v15 >> 14) & 1 )
  {
    v14 = v2->m_Components.p[3].m_pComponent;
    if ( !v14 || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v14->m_TypeUID) & 0xFE000000 )
      goto LABEL_32;
    if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF )
      v14 = 0i64;
  }
  else
  {
    if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v16 = (unsigned int)v2[1].vfptr;
        v17 = v2->m_Components.size;
        if ( v16 >= v17 )
          goto LABEL_32;
        v18 = (signed __int64)&v2->m_Components.p[v16];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
        {
          ++v16;
          v18 += 16i64;
          if ( v16 >= v17 )
          {
            v14 = 0i64;
            goto LABEL_59;
          }
        }
      }
      else
      {
        if ( !((v15 >> 12) & 1) )
        {
          v14 = UFG::SimObject::GetComponentOfType(v2, UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          goto LABEL_59;
        }
        v19 = (unsigned int)v2[1].vfptr;
        v20 = v2->m_Components.size;
        if ( v19 >= v20 )
          goto LABEL_32;
        v18 = (signed __int64)&v2->m_Components.p[v19];
        while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
        {
          ++v19;
          v18 += 16i64;
          if ( v19 >= v20 )
          {
            v14 = 0i64;
            goto LABEL_59;
          }
        }
      }
      v14 = *(UFG::SimComponent **)v18;
      goto LABEL_59;
    }
    v14 = v2->m_Components.p[3].m_pComponent;
    if ( !v14 || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v14->m_TypeUID) & 0xFE000000 )
      goto LABEL_32;
    if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF )
      v14 = 0i64;
  }
LABEL_59:
  v21 = v3->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( v21 && v14 )
  {
    v22 = (UFG::eFactionClassEnum)v14[3].m_SafePointerList.mNode.mPrev;
    v23 = (UFG::eFactionClassEnum)v21[3].m_SafePointerList.mNode.mPrev;
    v24 = UFG::FactionInterface::Get();
    v25 = UFG::FactionInterface::GetStanding(&v24->mFactionInterface, v23, v22);
    if ( !v25 || !v2 )
      return v25;
    v26 = v2->m_Flags;
    if ( (v26 >> 14) & 1 )
    {
      v27 = v2->m_Components.p[22].m_pComponent;
LABEL_65:
      if ( !v27
        || (UFG::ActiveAIEntityComponent::_TypeUID ^ v27->m_TypeUID) & 0xFE000000
        || UFG::ActiveAIEntityComponent::_TypeUID & ~v27->m_TypeUID & 0x1FFFFFF )
      {
        goto LABEL_68;
      }
LABEL_87:
      if ( v27 )
      {
        if ( UFG::g_AIObjectiveParams[SHIDWORD(v27[65].vfptr)].m_IsHostile )
          v25 = 2;
      }
      return v25;
    }
    if ( (v26 & 0x8000u) != 0 )
    {
      v27 = v2->m_Components.p[22].m_pComponent;
      goto LABEL_65;
    }
    if ( (v26 >> 13) & 1 )
    {
      v28 = (unsigned int)v2[1].vfptr;
      v29 = v2->m_Components.size;
      if ( v28 < v29 )
      {
        v30 = (signed __int64)&v2->m_Components.p[v28];
        while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
             || UFG::ActiveAIEntityComponent::_TypeUID & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
        {
          ++v28;
          v30 += 16i64;
          if ( v28 >= v29 )
          {
            v27 = 0i64;
            goto LABEL_87;
          }
        }
LABEL_78:
        v27 = *(UFG::SimComponent **)v30;
        goto LABEL_87;
      }
    }
    else
    {
      if ( !((v26 >> 12) & 1) )
      {
        v27 = UFG::SimObject::GetComponentOfType(v2, UFG::ActiveAIEntityComponent::_TypeUID);
        goto LABEL_87;
      }
      v31 = (unsigned int)v2[1].vfptr;
      v32 = v2->m_Components.size;
      if ( v31 < v32 )
      {
        v30 = (signed __int64)&v2->m_Components.p[v31];
        while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (UFG::ActiveAIEntityComponent::_TypeUID & 0xFE000000)
             || UFG::ActiveAIEntityComponent::_TypeUID & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
        {
          ++v31;
          v30 += 16i64;
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
signed __int64 __fastcall UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(UFG::TargetingSystemPedBaseComponent *this, UFG::eTargetTypeEnum eTargetType)
{
  return UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
           this,
           this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer);
}

// File Line: 1950
// RVA: 0x521400
void __fastcall UFG::TargetingSystemPedBaseComponent::AddTargetSteerToTask(UFG::TargetingSystemPedBaseComponent *this, TargetSteerToTask *pTargetSteerToTask)
{
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v2; // rdx
  UFG::qList<TargetSteerToTask,TargetingSystemTargetSteerToList,0,0> *v3; // rcx
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v4; // rax

  v2 = (UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *)&pTargetSteerToTask->mPrev;
  v3 = &this->m_TargetSteerToTaskList;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

// File Line: 1957
// RVA: 0x54D250
void __fastcall UFG::TargetingSystemPedBaseComponent::SetFocusTargetSubTargetingLocationOverride(UFG::TargetingSystemPedBaseComponent *this, UFG::qSymbol *focusTargetSubTargetingLocationOverrideSymbol)
{
  unsigned int v2; // edx

  v2 = focusTargetSubTargetingLocationOverrideSymbol->mUID;
  if ( v2 == -1 )
  {
    this->m_pFocusTargetSubTargetingLocationOverride = 0i64;
  }
  else if ( v2 )
  {
    this->m_pFocusTargetSubTargetingLocationOverride = (UFG::SubTargetingLocation *)UFG::qBaseTreeRB::Get(
                                                                                      &UFG::SubTargetingLocations::ms_SubTargetingLocations.mTree,
                                                                                      v2);
  }
  else
  {
    this->m_pFocusTargetSubTargetingLocationOverride = 0i64;
  }
}

// File Line: 1985
// RVA: 0x55CD00
void __fastcall UFG::TargetingSystemPedBaseComponent::Update(UFG::TargetingSystemPedBaseComponent *this, float delta_sec)
{
  *(_QWORD *)&this->m_vTargetingPosition.z = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 30i64)
                                                       + *(_QWORD *)&this->m_TypeUID
                                                       + 40);
}

// File Line: 1995
// RVA: 0x53EB90
void __fastcall UFG::TargetingSystemPedBaseComponent::OnAttach(UFG::TargetingSystemPedBaseComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v2; // rbx
  UFG::TargetingSystemPedBaseComponent *v3; // rdi
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *v4; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v19; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *v24; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v29; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v34; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax

  v2 = pSimObject;
  v3 = this;
  UFG::TargetingSystemBaseComponent::OnAttach((UFG::TargetingSystemBaseComponent *)&this->vfptr, pSimObject);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&v3->m_pTransformNodeComponent, v2);
  v4 = &v3->m_pAimingBaseComponent;
  if ( v3->m_pAimingBaseComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v3->m_pAimingBaseComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pAimingBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pAimingBaseComponent.m_pSimObject = 0i64;
    v3->m_pAimingBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pAimingBaseComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pAimingBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *)v3->m_pAimingBaseComponent.mNext != &v3->m_pAimingBaseComponent) )
  {
    v7 = v4->mPrev;
    v8 = v3->m_pAimingBaseComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_pAimingBaseComponent.m_Changed = 1;
  v3->m_pAimingBaseComponent.m_pSimObject = v2;
  v3->m_pAimingBaseComponent.m_TypeUID = UFG::AimingBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pAimingBaseComponent,
    v2);
  v9 = &v3->m_pActionTreeComponent;
  if ( v3->m_pActionTreeComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v3->m_pActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v3->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v3->m_pActionTreeComponent.m_pSimObject = 0i64;
    v3->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pActionTreeComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v3->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v3->m_pActionTreeComponent.mNext != &v3->m_pActionTreeComponent) )
  {
    v12 = v9->mPrev;
    v13 = v3->m_pActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v3->m_pActionTreeComponent.m_Changed = 1;
  v3->m_pActionTreeComponent.m_pSimObject = v2;
  v3->m_pActionTreeComponent.m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pActionTreeComponent,
    v2);
  v14 = &v3->m_pActiveAIEntityComponent;
  if ( v3->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v3->m_pActiveAIEntityComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v3->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_21:
    v3->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    v3->m_pActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pActiveAIEntityComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v3->m_pActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->m_pActiveAIEntityComponent.mNext != &v3->m_pActiveAIEntityComponent) )
  {
    v17 = v14->mPrev;
    v18 = v3->m_pActiveAIEntityComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v3->m_pActiveAIEntityComponent.m_Changed = 1;
  v3->m_pActiveAIEntityComponent.m_pSimObject = v2;
  v3->m_pActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pActiveAIEntityComponent,
    v2);
  v19 = &v3->m_pSimObjectCharacterPropertiesComponent;
  if ( v3->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v20 = v19->mPrev;
    v21 = v3->m_pSimObjectCharacterPropertiesComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v3->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_28:
    v3->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v3->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v19->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v19->mPrev;
    goto LABEL_29;
  }
  if ( v3->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v19->mPrev != v19
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v3->m_pSimObjectCharacterPropertiesComponent.mNext != &v3->m_pSimObjectCharacterPropertiesComponent) )
  {
    v22 = v19->mPrev;
    v23 = v3->m_pSimObjectCharacterPropertiesComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  v3->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v3->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = v2;
  v3->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pSimObjectCharacterPropertiesComponent,
    v2);
  v24 = &v3->m_pAICharacterControllerComponent;
  if ( v3->m_pAICharacterControllerComponent.m_pSimComponent )
  {
    v25 = v24->mPrev;
    v26 = v3->m_pAICharacterControllerComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v3->m_pAICharacterControllerComponent.m_pSimComponent = 0i64;
LABEL_35:
    v3->m_pAICharacterControllerComponent.m_pSimObject = 0i64;
    v3->m_pAICharacterControllerComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pAICharacterControllerComponent.mPrev;
    v24->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v24->mPrev;
    goto LABEL_36;
  }
  if ( v3->m_pAICharacterControllerComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *)v24->mPrev != v24
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *)v3->m_pAICharacterControllerComponent.mNext != &v3->m_pAICharacterControllerComponent) )
  {
    v27 = v24->mPrev;
    v28 = v3->m_pAICharacterControllerComponent.mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    goto LABEL_35;
  }
LABEL_36:
  v3->m_pAICharacterControllerComponent.m_Changed = 1;
  v3->m_pAICharacterControllerComponent.m_pSimObject = v2;
  v3->m_pAICharacterControllerComponent.m_TypeUID = UFG::AICharacterControllerComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pAICharacterControllerComponent,
    v2);
  v29 = &v3->m_pAICharacterControllerBaseComponent;
  if ( v3->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v30 = v29->mPrev;
    v31 = v3->m_pAICharacterControllerBaseComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    v3->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_42:
    v3->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v3->m_pAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pAICharacterControllerBaseComponent.mPrev;
    v29->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v29->mPrev;
    goto LABEL_43;
  }
  if ( v3->m_pAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v29->mPrev != v29
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v3->m_pAICharacterControllerBaseComponent.mNext != &v3->m_pAICharacterControllerBaseComponent) )
  {
    v32 = v29->mPrev;
    v33 = v3->m_pAICharacterControllerBaseComponent.mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    goto LABEL_42;
  }
LABEL_43:
  v3->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  v3->m_pAICharacterControllerBaseComponent.m_pSimObject = v2;
  v3->m_pAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pAICharacterControllerBaseComponent,
    v2);
  v34 = &v3->m_pInterestPointUserComponent;
  if ( v3->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v35 = v34->mPrev;
    v36 = v3->m_pInterestPointUserComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    v3->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_49:
    v3->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    v3->m_pInterestPointUserComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_pInterestPointUserComponent.mPrev;
    v34->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v34->mPrev;
    goto LABEL_50;
  }
  if ( v3->m_pInterestPointUserComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v34->mPrev != v34
     || (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v3->m_pInterestPointUserComponent.mNext != &v3->m_pInterestPointUserComponent) )
  {
    v37 = v34->mPrev;
    v38 = v3->m_pInterestPointUserComponent.mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    goto LABEL_49;
  }
LABEL_50:
  v3->m_pInterestPointUserComponent.m_Changed = 1;
  v3->m_pInterestPointUserComponent.m_pSimObject = v2;
  v3->m_pInterestPointUserComponent.m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::BindInternal<UFG::SimObject>(
    &v3->m_pInterestPointUserComponent,
    v2);
}

// File Line: 2013
// RVA: 0x540D80
void __fastcall UFG::TargetingSystemPedBaseComponent::OnDetach(UFG::TargetingSystemPedBaseComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // r8
  UFG::TargetingSystemPedBaseComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  unsigned int *v42; // rcx

  v1 = &this->m_pTransformNodeComponent;
  v2 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pTransformNodeComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pAimingBaseComponent;
  v1->m_Changed = 1;
  if ( v2->m_pAimingBaseComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAimingBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pAimingBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pAimingBaseComponent.m_pSimObject = 0i64;
    v2->m_pAimingBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAimingBaseComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pAimingBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AimingBaseComponent,0> *)v2->m_pAimingBaseComponent.mNext != &v2->m_pAimingBaseComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pAimingBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pAimingBaseComponent.m_Changed = 1;
  v12 = &v2->m_pActionTreeComponent;
  if ( v2->m_pActionTreeComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActionTreeComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->m_pActionTreeComponent.mNext != &v2->m_pActionTreeComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pActionTreeComponent.m_Changed = 1;
  v17 = &v2->m_pActiveAIEntityComponent;
  if ( v2->m_pActiveAIEntityComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pActiveAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->m_pActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pActiveAIEntityComponent.m_pSimObject = 0i64;
    v2->m_pActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActiveAIEntityComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v2->m_pActiveAIEntityComponent.mNext != &v2->m_pActiveAIEntityComponent) )
  {
    v20 = v17->mPrev;
    v21 = v2->m_pActiveAIEntityComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pActiveAIEntityComponent.m_Changed = 1;
  v22 = &v2->m_pSimObjectCharacterPropertiesComponent;
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_35:
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pSimObjectCharacterPropertiesComponent.mNext != &v2->m_pSimObjectCharacterPropertiesComponent) )
  {
    v25 = v22->mPrev;
    v26 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v2->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v27 = &v2->m_pAICharacterControllerComponent;
  if ( v2->m_pAICharacterControllerComponent.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v2->m_pAICharacterControllerComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v2->m_pAICharacterControllerComponent.m_pSimComponent = 0i64;
LABEL_42:
    v2->m_pAICharacterControllerComponent.m_pSimObject = 0i64;
    v2->m_pAICharacterControllerComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAICharacterControllerComponent.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_43;
  }
  if ( v2->m_pAICharacterControllerComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerComponent,0> *)v2->m_pAICharacterControllerComponent.mNext != &v2->m_pAICharacterControllerComponent) )
  {
    v30 = v27->mPrev;
    v31 = v2->m_pAICharacterControllerComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  v2->m_pAICharacterControllerComponent.m_Changed = 1;
  v32 = &v2->m_pAICharacterControllerBaseComponent;
  if ( v2->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v33 = v32->mPrev;
    v34 = v2->m_pAICharacterControllerBaseComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v2->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_49:
    v2->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v2->m_pAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAICharacterControllerBaseComponent.mPrev;
    v32->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v32->mPrev;
    goto LABEL_50;
  }
  if ( v2->m_pAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v32->mPrev != v32
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v2->m_pAICharacterControllerBaseComponent.mNext != &v2->m_pAICharacterControllerBaseComponent) )
  {
    v35 = v32->mPrev;
    v36 = v2->m_pAICharacterControllerBaseComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  v2->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  v37 = &v2->m_pInterestPointUserComponent;
  if ( v2->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v38 = v37->mPrev;
    v39 = v2->m_pInterestPointUserComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    v2->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
  }
  else
  {
    if ( !v2->m_pInterestPointUserComponent.m_pSimObject
      || (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v37->mPrev == v37
      && (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v2->m_pInterestPointUserComponent.mNext == &v2->m_pInterestPointUserComponent )
    {
      goto LABEL_57;
    }
    v40 = v37->mPrev;
    v41 = v2->m_pInterestPointUserComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
  }
  v2->m_pInterestPointUserComponent.m_pSimObject = 0i64;
  v2->m_pInterestPointUserComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pInterestPointUserComponent.mPrev;
  v37->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v37->mPrev;
LABEL_57:
  v2->m_pInterestPointUserComponent.m_Changed = 1;
  UFG::TargetingSystemBaseComponent::OnDetach((UFG::TargetingSystemBaseComponent *)&v2->vfptr);
  v42 = v2->m_pBucketList;
  if ( v42 )
  {
    --v42[v2->m_uUpdateBucket];
    v2->m_pBucketList = 0i64;
  }
}

// File Line: 2055
// RVA: 0x54F3A0
void __fastcall UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(UFG::TargetingSystemPedBaseComponent *this)
{
  unsigned int *v1; // rdx
  UFG::TargetingSystemPedBaseComponent *v2; // r10
  unsigned int v3; // er8
  unsigned int v4; // er9
  unsigned int *v5; // rcx
  unsigned int v6; // eax

  v1 = this->m_pBucketList;
  v2 = this;
  if ( v1 )
    --v1[this->m_uUpdateBucket];
  v3 = UFG::TargetingSystemPedBaseComponent::ms_LowFrequencyUpdateBuckets[0];
  v4 = 0;
  v5 = (unsigned int *)&unk_14240DD84;
  v6 = 1;
  do
  {
    if ( *v5 < v3 )
    {
      v4 = v6;
      v3 = *v5;
    }
    ++v6;
    ++v5;
  }
  while ( v6 < 0x3C );
  v2->m_uUpdateBucket = v4;
  v2->m_pBucketList = UFG::TargetingSystemPedBaseComponent::ms_LowFrequencyUpdateBuckets;
  ++UFG::TargetingSystemPedBaseComponent::ms_LowFrequencyUpdateBuckets[v4];
}

// File Line: 2071
// RVA: 0x54F2B0
void __fastcall UFG::TargetingSystemPedBaseComponent::SetToHighFrequencyUpdate(UFG::TargetingSystemPedBaseComponent *this)
{
  unsigned int *v1; // rdx
  unsigned int v2; // eax
  signed __int64 v3; // rdx

  v1 = this->m_pBucketList;
  if ( v1 )
    --v1[this->m_uUpdateBucket];
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

