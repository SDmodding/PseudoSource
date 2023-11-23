// File Line: 142
// RVA: 0x1582A70
__int64 UFG::_dynamic_initializer_for__civilian__()
{
  civilian.mUID = UFG::qWiseSymbolUIDFromString("civilian", 0x811C9DC5);
  _((AMD_HD3D *)civilian.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__civilian__);
}

// File Line: 143
// RVA: 0x15837A0
__int64 UFG::_dynamic_initializer_for__police__()
{
  police.mUID = UFG::qWiseSymbolUIDFromString("police", 0x811C9DC5);
  _((AMD_HD3D *)police.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__police__);
}

// File Line: 144
// RVA: 0x1582B00
__int64 UFG::_dynamic_initializer_for__emergency__()
{
  emergency.mUID = UFG::qWiseSymbolUIDFromString("emergency", 0x811C9DC5);
  _((AMD_HD3D *)emergency.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__emergency__);
}

// File Line: 145
// RVA: 0x1585820
__int64 UFG::_dynamic_initializer_for__undercover__()
{
  undercover.mUID = UFG::qWiseSymbolUIDFromString("undercover", 0x811C9DC5);
  _((AMD_HD3D *)undercover.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__undercover__);
}

// File Line: 147
// RVA: 0x157B890
__int64 dynamic_initializer_for__UFG::VehicleAudioComponent::s_VehicleAudioComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehicleAudioComponent::s_VehicleAudioComponentList__);
}

// File Line: 148
// RVA: 0x67B510
__int64 __fastcall UFG::qReflectInventory<UFG::DUIThemeEditorWindow>::GetClassSize(
        UFG::qReflectInventory<UFG::DUIThemeEditorWindow> *this)
{
  return 640i64;
}

// File Line: 188
// RVA: 0x157B980
__int64 dynamic_initializer_for__UFG::VehicleAudioComponent::sm_vehicleFollowTarget__()
{
  UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer = 0i64;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehicleAudioComponent::sm_vehicleFollowTarget__);
}

// File Line: 195
// RVA: 0x157B930
__int64 dynamic_initializer_for__UFG::VehicleAudioParameters::sm_Map__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VehicleAudioParameters::sm_Map.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehicleAudioParameters::sm_Map__);
}

// File Line: 215
// RVA: 0x66AA50
void __fastcall UFG::VehicleAudioParameters::VehicleAudioParameters(
        UFG::VehicleAudioParameters *this,
        UFG::qSymbol *parametersTableName)
{
  UFG::VehicleAudioSubTypeParameters *p_m_trafficParameters; // rbp
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *v10; // rax

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  *(_QWORD *)&this->m_playerParameters.m_rateLimitedSpeed.m_currentValue = 0i64;
  this->m_playerParameters.m_rateLimitedSpeed.m_riseRate = 10000000.0;
  this->m_playerParameters.m_rateLimitedSpeed.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_playerParameters.m_rateLimitedSpeed.m_max = 1065353216i64;
  *(_QWORD *)&this->m_aiParameters.m_rateLimitedSpeed.m_currentValue = 0i64;
  this->m_aiParameters.m_rateLimitedSpeed.m_riseRate = 10000000.0;
  this->m_aiParameters.m_rateLimitedSpeed.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_aiParameters.m_rateLimitedSpeed.m_max = 1065353216i64;
  p_m_trafficParameters = &this->m_trafficParameters;
  *(_QWORD *)&this->m_trafficParameters.m_rateLimitedSpeed.m_currentValue = 0i64;
  this->m_trafficParameters.m_rateLimitedSpeed.m_riseRate = 10000000.0;
  this->m_trafficParameters.m_rateLimitedSpeed.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_trafficParameters.m_rateLimitedSpeed.m_max = 1065353216i64;
  this->m_ParametersTableName.mUID = -1;
  this->m_uRefCount = 1;
  this->mNode.mUID = parametersTableName->mUID;
  PropertySet = UFG::PropertySetManager::FindPropertySet(parametersTableName);
  this->m_pPropertySet = PropertySet;
  if ( PropertySet )
  {
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&VehAudSym_propset_player,
           DEPTH_RECURSE);
    v6 = UFG::PropertySetManager::FindPropertySet(v5);
    UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(&this->m_playerParameters, v6);
    v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
           this->m_pPropertySet,
           (UFG::qArray<unsigned long,0> *)&VehAudSym_propset_traffic,
           DEPTH_RECURSE);
    v8 = UFG::PropertySetManager::FindPropertySet(v7);
    UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(p_m_trafficParameters, v8);
    v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
           this->m_pPropertySet,
           (UFG::qArray<unsigned long,0> *)&VehAudSym_propset_ai,
           DEPTH_RECURSE);
    v10 = UFG::PropertySetManager::FindPropertySet(v9);
    UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(&this->m_aiParameters, v10);
  }
}

// File Line: 254
// RVA: 0x66D250
void __fastcall UFG::VehicleAudioParameters::~VehicleAudioParameters(UFG::VehicleAudioParameters *this)
{
  UFG::EngineManager *Instance; // rbx
  UFG::EngineManager *v3; // rbx
  UFG::EngineManager *v4; // rbx

  Instance = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(Instance, &this->m_trafficParameters.m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(Instance, &this->m_trafficParameters.m_parentEngineCurve->m_name);
  v3 = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(v3, &this->m_aiParameters.m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(v3, &this->m_aiParameters.m_parentEngineCurve->m_name);
  v4 = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(v4, &this->m_playerParameters.m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(v4, &this->m_playerParameters.m_parentEngineCurve->m_name);
}

// File Line: 260
// RVA: 0x67BAA0
UFG::qBaseTreeRB *__fastcall UFG::VehicleAudioParameters::GrabParametersInstance(UFG::qSymbol *parametersTableName)
{
  UFG::qBaseTreeRB *result; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *v5; // rbx

  if ( parametersTableName->mUID
    && (result = UFG::qBaseTreeRB::Get(&UFG::VehicleAudioParameters::sm_Map.mTree, parametersTableName->mUID)) != 0i64 )
  {
    ++HIDWORD(result[2].mNULL.mChild[0]);
  }
  else
  {
    v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xC0ui64, "VehicleAudioParameters", 0i64, 1u);
    if ( v3 )
    {
      UFG::VehicleAudioParameters::VehicleAudioParameters((UFG::VehicleAudioParameters *)v3, parametersTableName);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::VehicleAudioParameters::sm_Map.mTree, v5);
    return (UFG::qBaseTreeRB *)v5;
  }
  return result;
}

// File Line: 290
// RVA: 0x68AF70
void __fastcall UFG::VehicleAudioParameters::SetRLFFromPropertySet(UFG::RateLimitedFloat *rlf, UFG::qPropertySet *pSet)
{
  float v3; // xmm6_4
  float v5; // xmm9_4
  float v6; // xmm8_4
  float v7; // xmm7_4
  float *v8; // rax
  float *v9; // rax
  float *v10; // rax
  float *v11; // rax

  if ( pSet )
  {
    v3 = 0.0;
    v5 = 0.0;
    v6 = *(float *)&FLOAT_1_0;
    v7 = 0.0;
    v8 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&RlfSym_min_25, DEPTH_RECURSE);
    if ( v8 )
      v3 = *v8;
    v9 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&RlfSym_max_25, DEPTH_RECURSE);
    if ( v9 )
      v6 = *v9;
    v10 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&RlfSym_rise_rate_25, DEPTH_RECURSE);
    if ( v10 )
      v5 = *v10;
    v11 = UFG::qPropertySet::Get<float>(pSet, (UFG::qArray<unsigned long,0> *)&RlfSym_fall_rate_25, DEPTH_RECURSE);
    if ( v11 )
      v7 = *v11;
    rlf->m_min = v3;
    rlf->m_max = v6;
    rlf->m_riseRate = v5;
    rlf->m_fallRate = v7;
  }
}

// File Line: 328
// RVA: 0x67D310
void __fastcall UFG::VehicleAudioComponent::HotSwapEngineCurve(const char *filename)
{
  UFG::qPropertySet *v1; // rdi
  UFG::EngineManager *Instance; // rax
  UFG::EngineCurve *Engine; // rax
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF

  UFG::qString::qString(&v5, filename);
  UFG::qString::ReplaceString(&v5, ".props.xml", &customCaption, 0);
  UFG::qString::ReplaceString(&v5, "Data\\PropertySets\\", &customCaption, 0);
  UFG::qString::ReplaceCharInPlace(&v5, 92, 45);
  UFG::qSymbol::create_from_string(&result, v5.mData);
  v1 = UFG::PropertySetManager::ReloadPropertySet(&result);
  if ( v1 )
  {
    Instance = UFG::EngineManager::GetInstance();
    Engine = (UFG::EngineCurve *)UFG::EngineManager::FindEngine(Instance, &v1->mName);
    if ( Engine )
      UFG::EngineCurve::Reload(Engine, v1);
  }
  v4 = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext - 24;
  for ( UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext[-24];
        v4 != (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)(&UFG::VehicleAudioComponent::s_VehicleAudioComponentList
                                                                                  - 24);
        UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)v4 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *))v4->mPrev[8].mPrev)(v4);
    v4 = UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mNext
       - 24;
  }
  UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = 0i64;
  UFG::qString::~qString(&v5);
}

// File Line: 401
// RVA: 0x66A850
void __fastcall UFG::VehicleAudioComponent::VehicleAudioComponent(
        UFG::VehicleAudioComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_VehicleAudio *dataPtr)
{
  AMD_HD3D *mUID; // rcx
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *mPrev; // rax

  UFG::HkAudioEntityComponent::HkAudioEntityComponent(this, pSceneObj);
  this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mPrev = &this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>;
  this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mNext = &this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>;
  this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::AudioEntity};
  this->m_bMissionPlaylist = 0;
  this->m_entScrape = 0i64;
  mUID = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  this->m_vehicleBank.mUID = (unsigned int)mUID;
  _(mUID);
  v6 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  this->m_driverTypeBank.mUID = (unsigned int)v6;
  _(v6);
  v7 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  this->m_commonBank.mUID = (unsigned int)v7;
  _(v7);
  *(_QWORD *)&this->m_eDriverType = -1i64;
  this->m_pTypeParameters = 0i64;
  this->m_pSubTypeParameters = 0i64;
  *(_QWORD *)&this->m_fTimeAlive = 0i64;
  this->m_fLastWhooshTime = 0.0;
  this->m_fDistance2ToListener = 3.4028235e38;
  *(_QWORD *)&this->m_hornAccum = 0i64;
  this->m_physicsMoverInterface.mPrev = &this->m_physicsMoverInterface;
  this->m_physicsMoverInterface.mNext = &this->m_physicsMoverInterface;
  this->m_physicsMoverInterface.m_pPointer = 0i64;
  this->m_transformNode.mPrev = &this->m_transformNode;
  this->m_transformNode.mNext = &this->m_transformNode;
  this->m_transformNode.m_pPointer = 0i64;
  this->m_engineModel = 0i64;
  this->m_damageModel = 0i64;
  this->m_envModel = 0i64;
  this->m_radio = 0i64;
  this->m_driverReaction = 0i64;
  this->m_ecRoadNoise.m_pEvent = 0i64;
  this->m_ecHorn.m_pEvent = 0i64;
  this->m_ecSiren.m_pEvent = 0i64;
  *(_QWORD *)&this->m_rateLimitedSpeed.m_currentValue = 0i64;
  this->m_rateLimitedSpeed.m_riseRate = 10000000.0;
  this->m_rateLimitedSpeed.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_rateLimitedSpeed.m_max = 1065353216i64;
  *((_BYTE *)this + 636) = *((_BYTE *)this + 636) & 0xC0 | 8;
  this->m_bVehicleIsInitialized = 0;
  *((_BYTE *)this + 638) &= 0xC4u;
  *((_BYTE *)this + 638) |= 0x40u;
  this->m_bOverrideDriverType = 0;
  mPrev = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mPrev;
  UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>;
  this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mNext = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList;
  UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mPrev = &this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>;
  UFG::SimComponent::AddType(this, UFG::VehicleAudioComponent::_VehicleAudioComponentTypeUID, "VehicleAudioComponent");
  if ( dataPtr )
    this->m_pTypeParameters = UFG::VehicleAudioParameters::GrabParametersInstance(&dataPtr->AudioPropertySet);
  UFG::RateLimitedFloat::SetMinMax(&this->m_rateLimitedSpeed, 0.0, 1000.0);
}

// File Line: 426
// RVA: 0x66D060
void __fastcall UFG::VehicleAudioComponent::~VehicleAudioComponent(UFG::VehicleAudioComponent *this)
{
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v2; // rdi
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *mPrev; // rcx
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *mNext; // rax
  UFG::VehicleAudioParameters *m_pTypeParameters; // rsi
  char *m_damageModel; // rsi
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::AudioEvent *v9; // rcx
  UFG::AudioEvent *v10; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_transformNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_physicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v21; // rcx
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v22; // rax

  this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::AudioEntity};
  if ( this == UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator )
    UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mPrev[-24];
  v2 = &this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>;
  mPrev = this->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  m_pTypeParameters = this->m_pTypeParameters;
  if ( m_pTypeParameters )
  {
    if ( m_pTypeParameters->m_uRefCount-- == 1 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::VehicleAudioParameters::sm_Map,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)m_pTypeParameters);
      UFG::VehicleAudioParameters::~VehicleAudioParameters(m_pTypeParameters);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, (char *)m_pTypeParameters);
    }
  }
  m_damageModel = (char *)this->m_damageModel;
  if ( m_damageModel )
  {
    UFG::DamageModel::~DamageModel(this->m_damageModel);
    UFG::qMemoryPool::Free(&g_AudioComponentPool, m_damageModel);
    this->m_damageModel = 0i64;
  }
  m_pEvent = this->m_ecSiren.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  v9 = this->m_ecHorn.m_pEvent;
  if ( v9 )
    UFG::AudioEvent::OnControllerDestroy(v9);
  v10 = this->m_ecRoadNoise.m_pEvent;
  if ( v10 )
    UFG::AudioEvent::OnControllerDestroy(v10);
  p_m_transformNode = &this->m_transformNode;
  if ( this->m_transformNode.m_pPointer )
  {
    v12 = p_m_transformNode->mPrev;
    v13 = this->m_transformNode.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_m_transformNode->mPrev = p_m_transformNode;
    this->m_transformNode.mNext = &this->m_transformNode;
  }
  this->m_transformNode.m_pPointer = 0i64;
  v14 = p_m_transformNode->mPrev;
  v15 = this->m_transformNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  p_m_transformNode->mPrev = p_m_transformNode;
  this->m_transformNode.mNext = &this->m_transformNode;
  p_m_physicsMoverInterface = &this->m_physicsMoverInterface;
  if ( this->m_physicsMoverInterface.m_pPointer )
  {
    v17 = p_m_physicsMoverInterface->mPrev;
    v18 = this->m_physicsMoverInterface.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    p_m_physicsMoverInterface->mPrev = p_m_physicsMoverInterface;
    this->m_physicsMoverInterface.mNext = &this->m_physicsMoverInterface;
  }
  this->m_physicsMoverInterface.m_pPointer = 0i64;
  v19 = p_m_physicsMoverInterface->mPrev;
  v20 = this->m_physicsMoverInterface.mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  p_m_physicsMoverInterface->mPrev = p_m_physicsMoverInterface;
  this->m_physicsMoverInterface.mNext = &this->m_physicsMoverInterface;
  _((AMD_HD3D *)this->m_commonBank.mUID);
  _((AMD_HD3D *)this->m_driverTypeBank.mUID);
  _((AMD_HD3D *)this->m_vehicleBank.mUID);
  v21 = v2->mPrev;
  v22 = v2->mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HkAudioEntityComponent::~HkAudioEntityComponent(this);
}

// File Line: 446
// RVA: 0x68C810
void UFG::VehicleAudioComponent::StaticInit(void)
{
  UFG::qPropertySet *PropertySet; // rbx

  PropertySet = UFG::PropertySetManager::FindPropertySet(&VehAudSymX_propset_vehicleconfig);
  if ( audio_vehicleaudiocomponent::IsClass(PropertySet->mSchemaName.mUID) )
    UFG::VehicleAudioComponent::sm_configPs = (audio_vehicleaudiocomponent *)UFG::qPropertySet::GetMemImagePtr(PropertySet);
  else
    UFG::VehicleAudioComponent::sm_configPs = 0i64;
}

// File Line: 453
// RVA: 0x68C680
void UFG::VehicleAudioComponent::StaticDestroy(void)
{
  UFG::VehicleAudioComponent::sm_configPs = 0i64;
}

// File Line: 460
// RVA: 0x68C860
void UFG::VehicleAudioComponent::StaticUpdate(void)
{
  UFG::SimComponent *v0; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rdi
  UFG::SimObject *v3; // rax
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::SimObject *CurrentVehicle; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *m_pPointer; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v0 = 0i64;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  if ( ComponentOfType )
  {
    if ( ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType) )
    {
      if ( ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType) )
      {
        v3 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType);
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                  v3,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
        if ( v4 )
        {
          CurrentVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
          if ( CurrentVehicle )
          {
            v6 = UFG::SimObject::GetComponentOfType(CurrentVehicle, UFG::VehicleAudioComponent::_TypeUID);
            v0 = v6;
            if ( v6 )
              BYTE1(v6[5].m_pSimObject) = 0;
          }
        }
      }
    }
  }
  m_pPointer = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer;
  if ( UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer )
  {
    if ( UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer != v0 )
    {
      BYTE1(UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[5].m_pSimObject) = 1;
      m_pPointer = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer;
    }
    if ( m_pPointer )
    {
      mPrev = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev;
      mNext = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext;
      UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev->mNext = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext;
      mNext->mPrev = mPrev;
      UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev = &UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
      UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext = &UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
    }
  }
  UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer = v0;
  if ( v0 )
  {
    v10 = v0->m_SafePointerList.mNode.mPrev;
    v10->mNext = &UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
    UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev = v10;
    UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext = &v0->m_SafePointerList.mNode;
    v0->m_SafePointerList.mNode.mPrev = &UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
  }
}

// File Line: 504
// RVA: 0x6881E0
UFG::VehicleAudioComponent *__fastcall UFG::VehicleAudioComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_VehicleAudio::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  v9 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x280ui64, "VehicleAudioComponent", 0i64, 1u);
  if ( v9 )
  {
    UFG::VehicleAudioComponent::VehicleAudioComponent(
      (UFG::VehicleAudioComponent *)v9,
      sceneObject,
      (component_VehicleAudio *)MemImagePtr);
    v6 = v10;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v13 = -1;
  else
    v13 = 28;
  UFG::SimObjectModifier::SimObjectModifier(&v14, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return (UFG::VehicleAudioComponent *)v6;
}

// File Line: 544
// RVA: 0x67F670
void __fastcall UFG::VehicleAudioComponent::KillOffensiveSoundsForNIS(
        hkgpIndexedMesh::EdgeBarrier *vfptr,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v2; // rbx
  UFG::AudioEvent *mPrev; // rcx

  v2 = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext - 24;
  for ( UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext[-24];
        v2 != (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)(&UFG::VehicleAudioComponent::s_VehicleAudioComponentList
                                                                                  - 24);
        UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)v2 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(vfptr, a2) )
    {
      mPrev = (UFG::AudioEvent *)v2[37].mPrev;
      if ( mPrev )
        UFG::AudioEvent::StopAndForget(mPrev, 0);
      BYTE6(v2[39].mNext) &= 0xFCu;
    }
    vfptr = (hkgpIndexedMesh::EdgeBarrier *)v2[35].mPrev;
    if ( vfptr )
    {
      if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled )
      {
        vfptr = (hkgpIndexedMesh::EdgeBarrier *)vfptr[1].vfptr;
        if ( vfptr )
          UFG::AudioEvent::StopAndForget((UFG::AudioEvent *)vfptr, 200);
      }
    }
    v2 = UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator->UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent>::mNext
       - 24;
  }
  UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = 0i64;
}

// File Line: 614
// RVA: 0x683520
void __fastcall UFG::VehicleAudioComponent::OnAttach(UFG::VehicleAudioComponent *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1
  UFG::qVector4 v7; // xmm0
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::allocator::free_link *v11; // rax
  char v12; // dl
  hkgpIndexedMeshDefinitions::Edge *v13; // rdx
  hkgpIndexedMesh::EdgeBarrier *v14; // rcx

  if ( object )
    m_pTransformNodeComponent = object->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v5 = m_pTransformNodeComponent->mWorldTransform.v1;
  v6 = m_pTransformNodeComponent->mWorldTransform.v2;
  v7 = m_pTransformNodeComponent->mWorldTransform.v3;
  this->m_WorldMatrix.v0 = m_pTransformNodeComponent->mWorldTransform.v0;
  this->m_WorldMatrix.v1 = v5;
  this->m_WorldMatrix.v2 = v6;
  this->m_WorldMatrix.v3 = v7;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  m_pMotionData = this->m_pMotionData;
  if ( m_pMotionData )
  {
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    m_pMotionData->m_vLastPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    m_pMotionData->m_vLastPosition.y = y;
    m_pMotionData->m_vLastPosition.z = z;
  }
  this->m_driverReaction = 0i64;
  v11 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x10ui64, "VehicleAudioComponent.DriverReactions", 0i64, 1u);
  if ( v11 )
  {
    v11[1].mNext = 0i64;
    v12 = UFG::DriverReactions::sm_tweakablesLoaded;
    if ( !UFG::DriverReactions::sm_tweakablesLoaded )
      v12 = 1;
    UFG::DriverReactions::sm_tweakablesLoaded = v12;
    v11->mNext = (UFG::allocator::free_link *)this;
  }
  this->m_driverReaction = (UFG::DriverReactions *)v11;
  this->m_ambientHornId = UFG::qRandom(7u, (unsigned int *)&UFG::qDefaultSeed);
  this->m_pSubTypeParameters = UFG::VehicleAudioComponent::FindSubTypeParameters(this);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v14, v13) )
  {
    UFG::AudioEntity::Init(&this->UFG::AudioEntity, (UFG::qSymbolUC *)&object->m_Name, &UFG::qMatrix44::msIdentity);
    UFG::VehicleAudioComponent::sm_numCarsActive = UFG::VehicleAudioComponent::sm_numCarsActive + 1.0;
  }
}

// File Line: 646
// RVA: 0x684200
void __fastcall UFG::VehicleAudioComponent::OnDetach(UFG::VehicleAudioComponent *this)
{
  UFG::RadioFullyControlled *m_radio; // rcx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  char *m_driverReaction; // rdx

  m_radio = this->m_radio;
  if ( m_radio )
    ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD))m_radio->vfptr[1].StopAndForgetAllEvents)(m_radio, 0i64);
  ((void (__fastcall *)(UFG::VehicleAudioComponent *))this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
  UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
  UFG::VehicleAudioComponent::UnloadSoundbanks(this);
  m_driverReaction = (char *)this->m_driverReaction;
  if ( m_driverReaction )
  {
    UFG::qMemoryPool::Free(&g_AudioComponentPool, m_driverReaction);
    this->m_driverReaction = 0i64;
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          v3,
          (hkgpIndexedMeshDefinitions::Edge *)m_driverReaction) )
    UFG::VehicleAudioComponent::sm_numCarsActive = UFG::VehicleAudioComponent::sm_numCarsActive + -1.0;
}

// File Line: 674
// RVA: 0x682520
void __fastcall UFG::VehicleAudioComponent::OnActionDefStartHorn(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *mpPropertySet; // rdi
  char *MemImagePtr; // rax
  char v4; // al
  float v5; // xmm0_4

  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
    else
      MemImagePtr = 0i64;
    if ( *((_DWORD *)MemImagePtr + 62) )
    {
      v4 = *((_BYTE *)this + 0x27E);
      if ( (v4 & 8) == 0 )
      {
        v5 = UFG::Metrics::msInstance.mSimTimeDelta + this->m_hornAccum;
        this->m_hornAccum = v5;
        if ( v5 > 0.2 )
          *((_BYTE *)this + 0x27E) = v4 | 6;
      }
    }
    else
    {
      *((_BYTE *)this + 0x27E) |= 6u;
    }
  }
}

// File Line: 700
// RVA: 0x6825C0
void __fastcall UFG::VehicleAudioComponent::OnActionDefStopHorn(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *mpPropertySet; // rdi
  char *MemImagePtr; // rax
  unsigned __int8 v4; // dl

  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
    else
      MemImagePtr = 0i64;
    if ( *((_DWORD *)MemImagePtr + 62) )
    {
      v4 = *((_BYTE *)this + 0x27E);
      if ( (v4 & 1) != 0 )
      {
        this->m_hornAccum = 0.0;
        *((_BYTE *)this + 638) = v4 & 0xF9 | 4;
      }
      else if ( (((v4 >> 4) ^ (v4 >> 3)) & 1) == 0 )
      {
        *((_BYTE *)this + 638) = v4 ^ (v4 ^ (16 * ~(v4 >> 4))) & 0x10;
      }
    }
    else
    {
      *((_BYTE *)this + 638) &= ~2u;
      *((_BYTE *)this + 638) |= 4u;
    }
  }
}

// File Line: 743
// RVA: 0x6848E0
void __fastcall UFG::VehicleAudioComponent::OnDriverComponentParked(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::EnvironmentalModel *m_envModel; // rax
  UFG::VehicleAudioComponent *v3; // rbx
  char v4; // al

  m_envModel = this->m_envModel;
  v3 = this;
  if ( m_envModel )
  {
    this = (UFG::VehicleAudioComponent *)m_envModel->m_ecForceStopSkid.m_pEvent;
    if ( this )
      UFG::AudioEvent::StopAndForget((UFG::AudioEvent *)this, 0);
  }
  if ( (*((_BYTE *)v3 + 638) & 0x40) != 0 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            a2) )
    {
      v4 = *((_BYTE *)v3 + 636);
      if ( (v4 & 2) != 0 )
        *((_BYTE *)v3 + 636) = v4 & 0xFD;
    }
  }
  else
  {
    UFG::VehicleAudioComponent::SetDriverType(v3, eDriverType_GhostRider);
  }
  if ( v3->m_bIsInitialized && v3->m_bVehicleIsInitialized && v3->m_eDriverType == eDriverType_Player )
    UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_GetOutOfVehicle, 1, 0i64);
}

// File Line: 766
// RVA: 0x684970
void __fastcall UFG::VehicleAudioComponent::OnDriverComponentUncontrolled(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  __int64 v3; // rdx
  UFG::RadioFullyControlled *m_radio; // rcx

  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized && this->m_eDriverType == eDriverType_Player )
    UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_GetOutOfVehicle, 1, 0i64);
  if ( this->m_radio && (*((_BYTE *)this + 638) & 0x40) != 0 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            a2) )
    {
      m_radio = this->m_radio;
      if ( m_radio )
      {
        LOBYTE(v3) = this->m_eDriverType == eDriverType_Player;
        ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))m_radio->vfptr[1].CountNumPlayingEvents)(
          m_radio,
          v3);
      }
      *((_BYTE *)this + 636) &= ~0x20u;
    }
    UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = 0i64;
    this->m_radio = 0i64;
  }
  UFG::VehicleAudioComponent::SetDriverType(this, eDriverType_GhostRider);
}

// File Line: 803
// RVA: 0x68A700
void __fastcall UFG::VehicleAudioComponent::SetDriverType(
        UFG::VehicleAudioComponent *this,
        UFG::VehicleAudioComponent::eDriverType driverType)
{
  UFG::VehicleAudioComponent::eDriverType m_eDriverType; // eax
  UFG::VehicleAudioSubTypeParameters *SubTypeParameters; // rax
  UFG::qPropertySet *mpPropertySet; // rbx
  UFG::qPropertySet *v7; // rsi
  char *v8; // rax
  __int64 v9; // rcx
  UFG::qPropertyList *v10; // r13
  unsigned int mNumElements; // r15d
  char v12; // r14
  unsigned int v13; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v15; // rbx
  char *MemImagePtr; // rax
  unsigned int v17; // eax
  char *v18; // rax
  UFG::TiDo *Instance; // rax
  UFG::TiDo *v20; // rax
  UFG::qWiseSymbol bankId; // [rsp+68h] [rbp+10h] BYREF

  m_eDriverType = this->m_eDriverType;
  if ( driverType != m_eDriverType )
  {
    this->m_eLastDriverType = m_eDriverType;
    this->m_eDriverType = driverType;
    SubTypeParameters = UFG::VehicleAudioComponent::FindSubTypeParameters(this);
    this->m_pSubTypeParameters = SubTypeParameters;
    if ( SubTypeParameters )
    {
      this->m_rateLimitedSpeed.m_currentValue = SubTypeParameters->m_rateLimitedSpeed.m_currentValue;
      this->m_rateLimitedSpeed.m_targetValue = SubTypeParameters->m_rateLimitedSpeed.m_targetValue;
      this->m_rateLimitedSpeed.m_riseRate = SubTypeParameters->m_rateLimitedSpeed.m_riseRate;
      this->m_rateLimitedSpeed.m_fallRate = SubTypeParameters->m_rateLimitedSpeed.m_fallRate;
      this->m_rateLimitedSpeed.m_max = SubTypeParameters->m_rateLimitedSpeed.m_max;
      this->m_rateLimitedSpeed.m_min = SubTypeParameters->m_rateLimitedSpeed.m_min;
      this->m_pEnginePropertySet = SubTypeParameters->mpPropertySet;
    }
    if ( driverType == eDriverType_PlayerPassenger )
    {
      this->m_pEnginePropertySet = this->m_pTypeParameters->m_playerParameters.mpPropertySet;
    }
    else if ( (unsigned int)(driverType - 3) <= 1 )
    {
      mpPropertySet = SubTypeParameters->mpPropertySet;
      v7 = 0i64;
      v8 = Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID)
         ? UFG::qPropertySet::GetMemImagePtr(mpPropertySet)
         : 0i64;
      v9 = *((_QWORD *)v8 + 30);
      if ( v9 )
      {
        v10 = (UFG::qPropertyList *)&v8[v9 + 240];
        if ( v10 )
        {
          mNumElements = v10->mNumElements;
          if ( mNumElements )
          {
            v12 = 0;
            v13 = 0;
            while ( v13 < mNumElements )
            {
              ValuePtr = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v13);
              if ( !ValuePtr || (v15 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
                v15 = 0i64;
              if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v15->mSchemaName.mUID) )
                MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v15);
              else
                MemImagePtr = 0i64;
              bankId.mUID = *((_DWORD *)MemImagePtr + 1);
              _((AMD_HD3D *)bankId.mUID);
              if ( bankId.mUID != UFG::qWiseSymbol::get_null()->mUID
                && !UFG::SoundBankManager::BankLoadRequested(&bankId) )
              {
                this->m_pEnginePropertySet = v15;
                v12 = 1;
              }
              ++v13;
              _((AMD_HD3D *)bankId.mUID);
              if ( v12 )
                goto LABEL_30;
            }
            v17 = UFG::qRandom(mNumElements, (unsigned int *)&UFG::qDefaultSeed);
            v18 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v17);
            if ( v18 && *(_QWORD *)v18 )
              v7 = (UFG::qPropertySet *)&v18[*(_QWORD *)v18];
            this->m_pEnginePropertySet = v7;
          }
        }
      }
    }
LABEL_30:
    if ( (_S7_16 & 1) == 0 )
    {
      _S7_16 |= 1u;
      UFG::qWiseSymbol::create_from_string(&amb_traffic, "amb_traffic_d");
      atexit(UFG::VehicleAudioComponent::SetDriverType_::_31_::_dynamic_atexit_destructor_for__amb_traffic__);
    }
    if ( this->m_eLastDriverType > (unsigned int)eDriverType_PlayerPassenger )
      goto LABEL_37;
    if ( this->m_eDriverType > (unsigned int)eDriverType_PlayerPassenger
      && !--UFG::VehicleAudioComponent::sm_numPlayerDrivers )
    {
      Instance = UFG::TiDo::GetInstance();
      UFG::AudioEntity::SetWwiseState(Instance, ms_vehicle.mUID, on_foot.mUID);
      UFG::TidoGame::StartDistantTraffic((UFG::TidoGame *)UFG::TiDo::m_pInstance);
    }
    if ( this->m_eLastDriverType > (unsigned int)eDriverType_PlayerPassenger )
    {
LABEL_37:
      if ( this->m_eDriverType <= (unsigned int)eDriverType_PlayerPassenger )
      {
        ++UFG::VehicleAudioComponent::sm_numPlayerDrivers;
        v20 = UFG::TiDo::GetInstance();
        UFG::AudioEntity::SetWwiseState(v20, ms_vehicle.mUID, in_vehicle.mUID);
        hkpCdBodyPairCollector::reset((hkpCdBodyPairCollector *)UFG::TiDo::m_pInstance);
      }
    }
  }
}

// File Line: 900
// RVA: 0x678AD0
__int64 __fastcall UFG::VehicleAudioComponent::FindPlayerIndexInVehicleOccupantComponent(
        UFG::VehicleAudioComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::VehicleOccupantComponent *m_pComponent; // rdi
  UFG::SimObjectCharacter *v3; // rsi
  int v4; // ebx
  unsigned int NumberOfOccupants; // r11d
  UFG::SimObjectCharacter *m_pPointer; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r8
  int v8; // r9d
  __int64 v9; // rax
  int v10; // edx
  __int64 v11; // rcx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  int v15; // ecx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pComponent = (UFG::VehicleOccupantComponent *)m_pSimObject->m_Components.p[30].m_pComponent;
  else
    m_pComponent = 0i64;
  v3 = LocalPlayer;
  if ( !m_pComponent )
    return 0xFFFFFFFFi64;
  if ( !LocalPlayer )
    return 0xFFFFFFFFi64;
  v4 = 0;
  NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent);
  if ( !NumberOfOccupants )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    if ( m_pComponent->mpDriver.m_pPointer )
    {
      if ( !v4 )
      {
        m_pPointer = (UFG::SimObjectCharacter *)m_pComponent->mpDriver.m_pPointer;
        goto LABEL_25;
      }
      p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
      v8 = 0;
      v9 = (__int64)&m_pComponent->mPassengers.mNode.mNext[-4];
      v10 = v4 - 1;
      v11 = v9;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != &m_pComponent->m_BoundComponentHandles )
      {
        do
        {
          ++v8;
          v11 = *(_QWORD *)(v11 + 72) - 64i64;
        }
        while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v11 != p_m_BoundComponentHandles );
      }
      if ( v10 < v8 )
      {
        for ( ; v10 > 0; v9 = *(_QWORD *)(v9 + 72) - 64i64 )
        {
          if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 == p_m_BoundComponentHandles )
            break;
          --v10;
        }
LABEL_16:
        m_pPointer = *(UFG::SimObjectCharacter **)(v9 + 40);
        goto LABEL_25;
      }
    }
    else
    {
      v12 = &m_pComponent->m_BoundComponentHandles;
      v13 = 0;
      v9 = (__int64)&m_pComponent->mPassengers.mNode.mNext[-4];
      v14 = v9;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != &m_pComponent->m_BoundComponentHandles )
      {
        do
        {
          ++v13;
          v14 = *(_QWORD *)(v14 + 72) - 64i64;
        }
        while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v14 != v12 );
      }
      if ( v4 < v13 )
      {
        v15 = v4;
        if ( v4 > 0 )
        {
          while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != v12 )
          {
            --v15;
            v9 = *(_QWORD *)(v9 + 72) - 64i64;
            if ( v15 <= 0 )
            {
              m_pPointer = *(UFG::SimObjectCharacter **)(v9 + 40);
              goto LABEL_25;
            }
          }
        }
        goto LABEL_16;
      }
    }
    m_pPointer = 0i64;
LABEL_25:
    if ( m_pPointer == v3 )
      return (unsigned int)v4;
    if ( ++v4 >= NumberOfOccupants )
      return 0xFFFFFFFFi64;
  }
}

// File Line: 925
// RVA: 0x678970
__int64 __fastcall UFG::VehicleAudioComponent::FindDriverType(UFG::VehicleAudioComponent *this)
{
  __int64 result; // rax
  int PlayerIndexInVehicleOccupantComponent; // eax
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::AiDriverComponent *v5; // rdi
  UFG::SimObjectCVBase *v6; // rcx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimObjectCVBase *v8; // rcx
  UFG::RemoteDriverComponent *v9; // rax
  char v10; // al
  unsigned int v11; // ecx
  unsigned int m_DrivingRole; // eax

  if ( this->m_bOverrideDriverType )
    return (unsigned int)this->m_eOverridenDriverType;
  if ( this->m_eDriverType == eDriverType_Disabled )
    return 7i64;
  PlayerIndexInVehicleOccupantComponent = UFG::VehicleAudioComponent::FindPlayerIndexInVehicleOccupantComponent(this);
  if ( !PlayerIndexInVehicleOccupantComponent )
  {
    UFG::VehicleAudioComponent::FindPlayerIndexInVehicleOccupantComponent(this);
    return 0i64;
  }
  if ( PlayerIndexInVehicleOccupantComponent > 0 )
    return 1i64;
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pSimObject);
  else
    v5 = 0i64;
  v6 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( v6 )
    m_pComponent = v6->m_Components.p[17].m_pComponent;
  else
    m_pComponent = 0i64;
  if ( v6 )
    UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v6);
  v8 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( v8 && (v9 = UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(v8)) != 0i64 )
  {
    v10 = ((__int64 (__fastcall *)(UFG::RemoteDriverComponent *))v9->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor)(v9);
    v11 = 2;
    if ( v10 )
      return 0;
    return v11;
  }
  else
  {
    if ( v5 )
    {
      if ( m_pComponent )
        return 5i64;
      m_DrivingRole = v5->m_DrivingRole;
      if ( m_DrivingRole == 1 )
        return 3i64;
      if ( m_DrivingRole == 2
        || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v5->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v5) )
      {
        return 4i64;
      }
      if ( !v5->m_DrivingRole || UFG::AiDriverComponent::IsTransit(v5) || UFG::AiDriverComponent::IsBoat(v5) )
        return 2i64;
    }
    result = 0xFFFFFFFFi64;
    if ( this->m_eDriverType == eDriverType_GhostRider )
      return 6i64;
  }
  return result;
}

// File Line: 994
// RVA: 0x67F600
bool __fastcall UFG::VehicleAudioComponent::KeepAliveTest(
        UFG::VehicleAudioComponent *this,
        UFG::VehicleAudioComponent::eDriverType desiredDriverType,
        float distance2ToListener)
{
  return ((unsigned int)desiredDriverType <= eDriverType_PlayerPassenger
       || (UFG::VehicleAudioComponent::HasDriver(this) || this->m_bOverrideDriverType)
       && (unsigned int)(desiredDriverType - 3) <= 2
       || desiredDriverType == eDriverType_Traffic)
      && UFG::VehicleAudioComponent::IsDriverTypeWithinCutoffRange(this, desiredDriverType, distance2ToListener);
}

// File Line: 1007
// RVA: 0x693F90
void __fastcall UFG::VehicleAudioComponent::Update(UFG::VehicleAudioComponent *this, float delta_sec)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  UFG::VehicleAudioComponent::eDriverType DriverType; // ebp
  UFG::SimObject *m_pSimObject; // rdx
  UFG::SimComponent *m_pComponent; // r14
  bool v8; // bl
  bool v9; // di
  char v10; // al
  char v11; // al
  hkgpIndexedMeshDefinitions::Edge *v12; // rdx
  hkgpIndexedMeshDefinitions::Edge *v13; // rdx
  char v14; // al
  char v15; // al
  char v16; // al
  UFG::Radio *m_radio; // rax
  hkgpIndexedMesh::EdgeBarrier *v18; // rcx
  UFG::RadioFullyControlled *v19; // rcx
  UFG::TiDo *Instance; // rax
  UFG::Audio3DListener *Listener; // rbx
  __int128 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 m_BoundComponentHandles; // xmm0
  UFG::allocator::free_link *v25; // rax
  char *m_damageModel; // rbx
  char v27; // al
  float v28; // xmm6_4

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, v2) )
  {
    DriverType = (unsigned int)UFG::VehicleAudioComponent::FindDriverType(this);
    if ( DriverType == eDriverType_Player )
      *((_BYTE *)this + 0x27C) |= 4u;
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = m_pSimObject->m_Components.p[2].m_pComponent;
    else
      m_pComponent = 0i64;
    if ( (*((_BYTE *)this + 636) & 4) == 0 )
      goto LABEL_27;
    if ( m_pComponent
      && (UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated > UFG::VehicleAudioComponent::sm_minTimeBetweenActivations
       || DriverType == eDriverType_Player) )
    {
      if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
      {
        if ( DriverType != this->m_eDriverType )
        {
          UFG::VehicleAudioComponent::FindDriverType(this);
          if ( this->m_eDriverType != eDriverType_GhostRider || this->m_eLastDriverType || DriverType )
          {
            if ( UFG::VehicleAudioComponent::KeepAliveTest(this, DriverType, this->m_fDistance2ToListener) )
            {
              v8 = (*((_BYTE *)this + 638) & 0x10) != 0;
              v9 = (*((_BYTE *)this + 636) & 2) != 0;
              ((void (__fastcall *)(UFG::VehicleAudioComponent *))this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
              this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(
                this,
                (unsigned int)&this->m_pSimObject->m_Name);
              *((_BYTE *)this + 638) ^= (*((_BYTE *)this + 638) ^ (16 * v8)) & 0x10;
              *((_BYTE *)this + 636) &= ~2u;
              *((_BYTE *)this + 636) |= 2 * v9;
              UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated = 0.0;
              *((_BYTE *)this + 636) |= 4u;
            }
            else if ( DriverType == eDriverType_GhostRider && (*((_BYTE *)this + 638) & 0x40) == 0 )
            {
              *((_BYTE *)this + 636) |= 4u;
            }
          }
          else
          {
            UFG::VehicleAudioComponent::SetDriverType(this, eDriverType_Player);
            *((_BYTE *)this + 636) |= 4u;
          }
        }
      }
      else if ( DriverType != eDriverType_Uninitialized )
      {
        this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(
          this,
          (unsigned int)&m_pSimObject->m_Name);
        UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated = 0.0;
      }
    }
    if ( (*((_BYTE *)this + 636) & 4) == 0 || ((DriverType + 1) & 0xFFFFFFF7) == 0 )
    {
LABEL_27:
      ((void (__fastcall *)(UFG::VehicleAudioComponent *))this->UFG::HkAudioEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
      if ( DriverType == eDriverType_Disabled )
        UFG::VehicleAudioComponent::SetDriverType(this, eDriverType_Disabled);
      if ( (*((_BYTE *)this + 638) & 0x20) != 0
        && !this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr->CountNumPlayingEvents(&this->UFG::AudioEntity) )
      {
        UFG::VehicleAudioComponent::UnloadSoundbanks(this);
      }
    }
    if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
    {
      v10 = *((_BYTE *)this + 636);
      if ( (v10 & 2) != 0
        && (v10 & 1) == 0
        && (UFG::SoundBankManager::BankLoadRequestFinished(&this->m_vehicleBank)
         || this->m_vehicleBank.mUID == UFG::qWiseSymbol::get_null()->mUID) )
      {
        this->m_engineModel->m_engineStateMachine->m_event = eEVENT_START;
        *((_BYTE *)this + 636) |= 1u;
      }
    }
    v11 = *((_BYTE *)this + 636);
    if ( (v11 & 2) == 0 && (v11 & 1) != 0 )
    {
      this->m_engineModel->m_engineStateMachine->m_event = eEVENT_STOP;
      UFG::VehicleAudioComponent::TurnOffRadio(this, (hkgpIndexedMeshDefinitions::Edge *)m_pSimObject);
      *((_BYTE *)this + 636) &= ~1u;
    }
    if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
    {
      v12 = (hkgpIndexedMeshDefinitions::Edge *)*((unsigned __int8 *)this + 0x27E);
      if ( ((unsigned __int8)v12 & 2) != 0 && ((unsigned __int8)v12 & 1) == 0 )
      {
        LOBYTE(v12) = ((unsigned __int8)v12 & 4) != 0;
        UFG::VehicleAudioComponent::DoStartHorn(this, v12);
      }
    }
    v13 = (hkgpIndexedMeshDefinitions::Edge *)*((unsigned __int8 *)this + 638);
    if ( ((unsigned __int8)v13 & 2) == 0 && ((unsigned __int8)v13 & 1) != 0 )
    {
      LOBYTE(v13) = ((unsigned __int8)v13 & 4) != 0;
      UFG::VehicleAudioComponent::DoStopHorn(this, v13);
    }
    if ( this->m_bIsInitialized )
    {
      if ( this->m_bVehicleIsInitialized )
      {
        v14 = *((_BYTE *)this + 0x27E);
        if ( (v14 & 0x10) != 0 && (v14 & 8) == 0 )
          UFG::VehicleAudioComponent::DoStartSiren(this, 0i64);
      }
      if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
      {
        v15 = *((_BYTE *)this + 638);
        if ( (v15 & 0x10) != 0 && (v15 & 8) != 0 && !this->m_ecSiren.m_pEvent )
          UFG::VehicleAudioComponent::DoStartSiren(this, 0i64);
      }
    }
    v16 = *((_BYTE *)this + 638);
    if ( (v16 & 0x10) == 0 && (v16 & 8) != 0 )
      UFG::VehicleAudioComponent::DoStopSiren(this, 0i64);
    if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
    {
      m_radio = this->m_radio;
      if ( m_radio )
      {
        v18 = (hkgpIndexedMesh::EdgeBarrier *)*((unsigned __int8 *)this + 0x27C);
        if ( ((unsigned __int8)v18 & 0x20) != 0
          && ((unsigned __int8)v18 & 1) != 0
          && (*((_BYTE *)m_radio + 0x158) & 4) != 0
          && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v18, v13) )
        {
          v19 = this->m_radio;
          if ( v19 )
          {
            if ( (*((_BYTE *)&v19->UFG::Radio + 344) & 4) != 0 )
              ((void (__fastcall *)(UFG::RadioFullyControlled *))v19->vfptr[1].AudioEntityUpdate)(v19);
          }
        }
      }
    }
    if ( UFG::Metrics::msFrameCount != UFG::VehicleAudioComponent::sm_uLastFrameUpdate )
    {
      UFG::VehicleAudioComponent::sm_numCarsNearby = 0.0;
      UFG::VehicleAudioComponent::sm_uLastFrameUpdate = UFG::Metrics::msFrameCount;
      UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated = UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated
                                                               + delta_sec;
    }
    Instance = UFG::TiDo::GetInstance();
    Listener = UFG::TiDo::GetListener(Instance, 0);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pComponent);
    v22 = *(_OWORD *)&m_pComponent[2].m_SafePointerList.mNode.mNext;
    v23 = *(UFG::qVector4 *)&m_pComponent[2].m_Flags;
    m_BoundComponentHandles = (UFG::qVector4)m_pComponent[2].m_BoundComponentHandles;
    this->m_WorldMatrix.v0 = *(UFG::qVector4 *)&m_pComponent[2].vfptr;
    this->m_WorldMatrix.v1 = (UFG::qVector4)v22;
    this->m_WorldMatrix.v2 = v23;
    this->m_WorldMatrix.v3 = m_BoundComponentHandles;
    *(float *)&v22 = (float)((float)((float)(Listener->m_matrix.v3.y - this->m_WorldMatrix.v3.y)
                                   * (float)(Listener->m_matrix.v3.y - this->m_WorldMatrix.v3.y))
                           + (float)((float)(Listener->m_matrix.v3.x - this->m_WorldMatrix.v3.x)
                                   * (float)(Listener->m_matrix.v3.x - this->m_WorldMatrix.v3.x)))
                   + (float)((float)(Listener->m_matrix.v3.z - this->m_WorldMatrix.v3.z)
                           * (float)(Listener->m_matrix.v3.z - this->m_WorldMatrix.v3.z));
    LODWORD(this->m_fDistance2ToListener) = v22;
    if ( *(float *)&v22 >= 2500.0 )
    {
      m_damageModel = (char *)this->m_damageModel;
      if ( m_damageModel )
      {
        UFG::DamageModel::~DamageModel(this->m_damageModel);
        UFG::qMemoryPool::Free(&g_AudioComponentPool, m_damageModel);
        this->m_damageModel = 0i64;
      }
    }
    else
    {
      if ( !this->m_damageModel )
      {
        v25 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "VehicleAudioComponent.DamageModel", 0i64, 1u);
        if ( v25 )
          UFG::DamageModel::DamageModel((UFG::DamageModel *)v25, this);
        this->m_damageModel = (UFG::DamageModel *)v25;
      }
      UFG::VehicleAudioComponent::sm_numCarsNearby = UFG::VehicleAudioComponent::sm_numCarsNearby + 1.0;
    }
    if ( UFG::VehicleAudioComponent::KeepAliveTest(this, DriverType, this->m_fDistance2ToListener) )
    {
      *((_BYTE *)this + 636) |= 4u;
    }
    else if ( DriverType == eDriverType_GhostRider )
    {
      *((_BYTE *)this + 636) |= 4u;
      v27 = *((_BYTE *)this + 636);
      v28 = delta_sec + this->m_ghostRiderTime;
      this->m_ghostRiderTime = v28;
      if ( v28 > gGhostRiderTimeMax && (*((_BYTE *)this + 638) & 0x40) != 0 )
      {
        *((_BYTE *)this + 636) = v27 & 0xFB;
        this->m_ghostRiderTime = 0.0;
      }
    }
    else
    {
      *((_BYTE *)this + 636) &= ~4u;
    }
  }
}

// File Line: 1301
// RVA: 0x678C60
UFG::VehicleAudioSubTypeParameters *__fastcall UFG::VehicleAudioComponent::FindSubTypeParameters(
        UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioParameters *m_pTypeParameters; // rax

  switch ( this->m_eDriverType )
  {
    case eDriverType_Uninitialized:
    case eDriverType_Traffic:
      return &this->m_pTypeParameters->m_trafficParameters;
    case eDriverType_Player:
    case eDriverType_GhostRider:
      if ( UFG::gDebugPlayerCarsUseTrafficData )
        return &this->m_pTypeParameters->m_trafficParameters;
      m_pTypeParameters = this->m_pTypeParameters;
      if ( UFG::gDebugPlayerCarsUseAiData )
        return &m_pTypeParameters->m_aiParameters;
      else
        return &m_pTypeParameters->m_playerParameters;
    case eDriverType_PlayerPassenger:
    case eDriverType_Racer:
    case eDriverType_Script:
    case eDriverType_Cop:
      m_pTypeParameters = this->m_pTypeParameters;
      return &m_pTypeParameters->m_aiParameters;
    default:
      return 0i64;
  }
}

// File Line: 1367
// RVA: 0x67D4B0
void __fastcall UFG::VehicleAudioComponent::Init(UFG::VehicleAudioComponent *this, UFG::qSymbol *objectName)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *m_pComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *p_m_physicsMoverInterface; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SimComponent *v11; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_transformNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::VehicleAudioComponent::eDriverType DriverType; // eax
  UFG::qWiseSymbol *null; // rsi
  UFG::qPropertySet *m_pEnginePropertySet; // rbx
  char *MemImagePtr; // rax
  UFG::VehicleAudioComponent::eDriverType m_eDriverType; // eax
  UFG::SimObjectCVBase *v21; // rcx
  UFG::AiDriverComponent *v22; // rax
  UFG::qWiseSymbol *v23; // rsi
  signed __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v25; // rax
  UFG::AudioEntity *m_SFXEntity; // rcx
  UFG::allocator::free_link *v27; // rax
  UFG::VehicleAudioComponent::eDriverType v28; // ebx
  UFG::allocator::free_link *v29; // rax
  UFG::RadioFullyControlled *v30; // rax
  __int64 v31; // rdx
  UFG::RadioFullyControlled *v32; // rcx
  UFG::qPropertySet *mpPropertySet; // rbx
  char *v34; // rax
  float v35; // xmm1_4
  unsigned int v36; // edx
  UFG::VehicleAudioComponent::ScrapeImpactEntity *v37; // rax
  UFG::AudioEntityVtbl *vfptr; // rbx
  UFG::qWiseSymbol *suffix; // rax
  UFG::qWiseSymbol bankId; // [rsp+60h] [rbp+8h] BYREF
  void *result; // [rsp+70h] [rbp+18h] BYREF

  if ( !this->m_bIsInitialized || !this->m_bVehicleIsInitialized )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pComponent = m_pSimObject->m_Components.p[34].m_pComponent;
    else
      m_pComponent = 0i64;
    p_m_physicsMoverInterface = &this->m_physicsMoverInterface;
    if ( this->m_physicsMoverInterface.m_pPointer )
    {
      mPrev = p_m_physicsMoverInterface->mPrev;
      mNext = p_m_physicsMoverInterface->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_physicsMoverInterface->mPrev = p_m_physicsMoverInterface;
      p_m_physicsMoverInterface->mNext = p_m_physicsMoverInterface;
    }
    p_m_physicsMoverInterface->m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v9 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v9->mNext = p_m_physicsMoverInterface;
      p_m_physicsMoverInterface->mPrev = v9;
      p_m_physicsMoverInterface->mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_physicsMoverInterface;
    }
    v10 = this->m_pSimObject;
    if ( v10 )
      v11 = v10->m_Components.p[2].m_pComponent;
    else
      v11 = 0i64;
    p_m_transformNode = &this->m_transformNode;
    if ( this->m_transformNode.m_pPointer )
    {
      v13 = p_m_transformNode->mPrev;
      v14 = this->m_transformNode.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      p_m_transformNode->mPrev = p_m_transformNode;
      this->m_transformNode.mNext = &this->m_transformNode;
    }
    this->m_transformNode.m_pPointer = v11;
    if ( v11 )
    {
      v15 = v11->m_SafePointerList.mNode.mPrev;
      v15->mNext = p_m_transformNode;
      p_m_transformNode->mPrev = v15;
      this->m_transformNode.mNext = &v11->m_SafePointerList.mNode;
      v11->m_SafePointerList.mNode.mPrev = p_m_transformNode;
    }
    DriverType = (unsigned int)UFG::VehicleAudioComponent::FindDriverType(this);
    if ( DriverType == eDriverType_Uninitialized )
      DriverType = (unsigned int)UFG::VehicleAudioComponent::FindDriverType(this);
    UFG::VehicleAudioComponent::SetDriverType(this, DriverType);
    if ( this->m_eDriverType == eDriverType_Uninitialized )
      null = UFG::qWiseSymbol::get_null();
    else
      null = &veh_common_all;
    UFG::SoundBankManager::QueueBankForUnload(&this->m_commonBank);
    UFG::SoundBankManager::QueueBankForLoad(null);
    UFG::qWiseSymbol::operator=(&this->m_commonBank, null);
    bankId.mUID = UFG::qWiseSymbol::get_null()->mUID;
    _((AMD_HD3D *)bankId.mUID);
    m_pEnginePropertySet = this->m_pEnginePropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(m_pEnginePropertySet->mSchemaName.mUID) )
    {
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(m_pEnginePropertySet);
      if ( MemImagePtr )
        UFG::qWiseSymbol::operator=(&bankId, (UFG::qWiseSymbol *)MemImagePtr + 1);
    }
    UFG::SoundBankManager::QueueBankForUnload(&this->m_vehicleBank);
    UFG::SoundBankManager::QueueBankForLoad(&bankId);
    UFG::qWiseSymbol::operator=(&this->m_vehicleBank, &bankId);
    m_eDriverType = this->m_eDriverType;
    if ( (unsigned int)m_eDriverType <= eDriverType_PlayerPassenger )
    {
      v23 = &veh_common_player;
    }
    else if ( m_eDriverType == eDriverType_Traffic )
    {
      v21 = (UFG::SimObjectCVBase *)this->m_pSimObject;
      if ( v21
        && (v22 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v21)) != 0i64
        && UFG::AiDriverComponent::IsBoat(v22) )
      {
        v23 = &veh_common_boat;
      }
      else
      {
        v23 = &veh_common_traffic;
      }
    }
    else
    {
      v23 = UFG::qWiseSymbol::get_null();
    }
    UFG::AudioEntity::SetWwiseSwitch(&this->UFG::AudioEntity, veh_driver_type.mUID, this->m_vehicleBank.mUID);
    if ( this->m_eDriverType <= (unsigned int)eDriverType_PlayerPassenger && LocalPlayer )
    {
      m_Flags = LocalPlayer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        v25 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(LocalPlayer);
      else
        v25 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                             LocalPlayer,
                                             UFG::ActorAudioComponent::_TypeUID)
                                         : UFG::SimObject::GetComponentOfType(
                                             LocalPlayer,
                                             UFG::ActorAudioComponent::_TypeUID));
      if ( v25 )
      {
        m_SFXEntity = v25->m_SFXEntity;
        if ( m_SFXEntity )
        {
          if ( m_SFXEntity->m_bIsInitialized )
            UFG::AudioEntity::SetWwiseSwitch(m_SFXEntity, veh_driver_type.mUID, this->m_vehicleBank.mUID);
        }
      }
    }
    UFG::SoundBankManager::QueueBankForUnload(&this->m_driverTypeBank);
    UFG::SoundBankManager::QueueBankForLoad(v23);
    UFG::qWiseSymbol::operator=(&this->m_driverTypeBank, v23);
    v27 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x60ui64, "VehicleAudioComponent.EngineModel", 0i64, 1u);
    result = v27;
    if ( v27 )
      UFG::EngineModel2::EngineModel2((UFG::EngineModel2 *)v27, this);
    this->m_engineModel = (UFG::EngineModel2 *)v27;
    v28 = this->m_eDriverType;
    if ( (unsigned int)v28 <= eDriverType_PlayerPassenger
      || (UFG::VehicleAudioComponent::HasDriver(this) || this->m_bOverrideDriverType) && (unsigned int)(v28 - 3) <= 2 )
    {
      v29 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x78ui64, "VehicleAudioComponent.EnvModel", 0i64, 1u);
      result = v29;
      if ( v29 )
        UFG::EnvironmentalModel::EnvironmentalModel((UFG::EnvironmentalModel *)v29, this);
      this->m_envModel = (UFG::EnvironmentalModel *)v29;
    }
    if ( this->m_eDriverType > (unsigned int)eDriverType_PlayerPassenger )
      goto LABEL_87;
    if ( this->m_radio )
      goto LABEL_83;
    if ( UFG::VehicleAudioComponent::IsPoliceVehicle(this)
      || UFG::VehicleAudioComponent::IsEmergencyVehicle(this)
      || UFG::VehicleAudioComponent::IsUndercoverVehicle(this) )
    {
      v31 = 2i64;
    }
    else
    {
      if ( this->m_eDriverType == eDriverType_Player && UFG::VehicleAudioComponent::GetRadioIsEnabled(this) )
      {
        UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = this;
        v30 = UFG::RadioFullyControlled::sm_playerRadio;
        this->m_radio = UFG::RadioFullyControlled::sm_playerRadio;
        v30->vfptr[1].__vecDelDtor(v30, 0);
      }
      if ( this->m_eDriverType != eDriverType_PlayerPassenger
        || (*((_BYTE *)this + 636) & 0x10) == 0
        || !UFG::VehicleAudioComponent::GetRadioIsEnabled(this) )
      {
LABEL_71:
        mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
        if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
          v34 = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
        else
          v34 = 0i64;
        v35 = *((float *)v34 + 49);
        if ( this->m_eDriverType == eDriverType_Player )
        {
          if ( UFG::VehicleAudioComponent::sm_lastPlayerVehicleAudioComponent == this )
          {
            v36 = UFG::VehicleAudioComponent::sm_playerRadioStationSetInLastVehicle;
          }
          else
          {
            if ( v35 > 0.0 )
              UFG::VehicleAudioComponent::SetRadioStation(this, (int)v35);
            if ( !UFG::VehicleAudioComponent::IsPoliceVehicle(this)
              && !UFG::VehicleAudioComponent::IsEmergencyVehicle(this) )
            {
              goto LABEL_83;
            }
            v36 = 11;
          }
          UFG::VehicleAudioComponent::SetRadioStation(this, v36);
        }
LABEL_83:
        *((_BYTE *)this + 636) |= 0x20u;
        if ( !this->m_entScrape )
        {
          v37 = (UFG::VehicleAudioComponent::ScrapeImpactEntity *)UFG::qMemoryPool::Allocate(
                                                                    &g_AudioComponentPool,
                                                                    0x180ui64,
                                                                    "VehicleAudioComponent.ScrapeEntity",
                                                                    0i64,
                                                                    1u);
          result = v37;
          if ( v37 )
            UFG::VehicleAudioComponent::ScrapeImpactEntity::ScrapeImpactEntity(v37);
          this->m_entScrape = v37;
          v37->m_pVehicleAudio = this;
          vfptr = this->m_entScrape->vfptr;
          suffix = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&result, objectName, "_Scrape");
          (*(void (__fastcall **)(UFG::VehicleAudioComponent::ScrapeImpactEntity *, UFG::qWiseSymbol *, UFG::qMatrix44 *))vfptr->gap8)(
            this->m_entScrape,
            suffix,
            &UFG::qMatrix44::msIdentity);
        }
LABEL_87:
        this->m_fTimeAlive = 0.0;
        LODWORD(this->m_fLastWhooshTime) = LODWORD(UFG::Audio3DDopplerEmitter::sm_fWhooshInterval) ^ _xmm[0];
        this->m_bVehicleIsInitialized = 1;
        this->m_surfaceType = 0;
        UFG::VehicleAudioComponent::SetTargetSpeed(this);
        this->m_rateLimitedSpeed.m_currentValue = this->m_rateLimitedSpeed.m_targetValue;
        _((AMD_HD3D *)bankId.mUID);
        return;
      }
      v31 = 0i64;
    }
    UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = this;
    v32 = UFG::RadioFullyControlled::sm_playerRadio;
    this->m_radio = UFG::RadioFullyControlled::sm_playerRadio;
    v32->vfptr[1].__vecDelDtor(v32, v31);
    goto LABEL_71;
  }
}

// File Line: 1522
// RVA: 0x68BE60
void __fastcall UFG::VehicleAudioComponent::Shutdown(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::AudioEvent *m_pEvent; // rcx
  int traffic_fadeout_time_ms; // esi
  char *m_engineModel; // rbx
  char *m_envModel; // rbx
  bool v7; // zf
  __int64 v8; // rdx
  UFG::RadioFullyControlled *m_radio; // rcx
  hkgpIndexedMeshDefinitions::Edge *v10; // rdx
  UFG::VehicleAudioComponent::ScrapeImpactEntity *m_entScrape; // rcx
  hkgpIndexedMeshDefinitions::Edge *v12; // rdx
  UFG::AudioEvent *v13; // rcx
  char v14; // al

  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    m_pEvent = this->m_ecRoadNoise.m_pEvent;
    traffic_fadeout_time_ms = UFG::VehicleAudioComponent::sm_configPs->traffic_fadeout_time_ms;
    if ( m_pEvent )
      UFG::AudioEvent::StopAndForget(m_pEvent, traffic_fadeout_time_ms);
    m_engineModel = (char *)this->m_engineModel;
    if ( m_engineModel )
    {
      UFG::EngineModel2::~EngineModel2(this->m_engineModel, (__int64)a2);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, m_engineModel);
    }
    m_envModel = (char *)this->m_envModel;
    if ( m_envModel )
    {
      UFG::EnvironmentalModel::~EnvironmentalModel(this->m_envModel);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, m_envModel);
    }
    v7 = (*((_BYTE *)this + 638) & 0x40) == 0;
    this->m_engineModel = 0i64;
    this->m_envModel = 0i64;
    if ( !v7 )
    {
      if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
              (hkgpIndexedMesh::EdgeBarrier *)m_pEvent,
              a2) )
      {
        m_radio = this->m_radio;
        if ( m_radio )
        {
          LOBYTE(v8) = this->m_eDriverType == eDriverType_Player;
          ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))m_radio->vfptr[1].CountNumPlayingEvents)(
            m_radio,
            v8);
        }
        *((_BYTE *)this + 636) &= ~0x20u;
      }
      if ( UFG::RadioFullyControlled::sm_playerRadio
        && UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent == this )
      {
        UFG::VehicleAudioComponent::sm_lastPlayerVehicleAudioComponent = this;
        UFG::VehicleAudioComponent::sm_playerRadioStationSetInLastVehicle = UFG::RadioFullyControlled::sm_playerRadio->m_curStation->m_id;
        UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = 0i64;
        this->m_radio = 0i64;
      }
    }
    UFG::VehicleAudioComponent::SetDriverType(this, eDriverType_Uninitialized);
    m_entScrape = this->m_entScrape;
    if ( m_entScrape )
    {
      UFG::AudioEntity::Shutdown(m_entScrape);
      m_entScrape = this->m_entScrape;
      if ( m_entScrape )
        m_entScrape->vfptr->__vecDelDtor(m_entScrape, 1u);
      this->m_entScrape = 0i64;
    }
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)m_entScrape,
            v10) )
    {
      v13 = this->m_ecHorn.m_pEvent;
      if ( v13 )
      {
        UFG::AudioEvent::StopAndForget(v13, 0);
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_VEHICLE_HORN, this->m_pSimObject);
      }
      *((_BYTE *)this + 638) &= 0xFCu;
    }
    v14 = *((_BYTE *)this + 638);
    if ( (v14 & 8) != 0 )
    {
      LOBYTE(v12) = 1;
      *((_BYTE *)this + 638) = v14 & 0xEF;
      UFG::VehicleAudioComponent::DoStopSiren(this, v12);
    }
    UFG::AudioEntity::StopAndForgetAllEvents(&this->UFG::AudioEntity, (float)traffic_fadeout_time_ms);
    *((_BYTE *)this + 636) &= 0xFAu;
    *((_BYTE *)this + 638) |= 0x20u;
    this->m_bVehicleIsInitialized = 0;
    this->m_surfaceType = 0;
    UFG::AudioEntity::ClearContainmentInfo(&this->UFG::AudioEntity);
  }
}

// File Line: 1586
// RVA: 0x670CE0
void __fastcall UFG::VehicleAudioComponent::AudioEntityUpdate(UFG::VehicleAudioComponent *this, float delta_sec)
{
  _OWORD *v4; // rsi
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> v5; // xmm2
  __int128 v6; // xmm1
  __int128 v7; // xmm0
  float *v8; // rcx
  float v9; // xmm1_4
  int m_damageModel; // xmm0_4
  float v11; // xmm2_4
  UFG::VehicleAudioSubTypeParameters *m_pSubTypeParameters; // rbp
  __int64 v13; // rax
  UFG::PhysicsWheeledVehicle *v14; // rcx
  unsigned __int64 SurfacePropertyHandleUidUnderWheel; // rsi
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v16; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  unsigned int v19; // r8d
  UFG::AudioEvent *mPrev; // rcx
  UFG::EngineModel2 *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::SimComponent *m_pPointer; // rcx
  float v25; // xmm0_4
  UFG::DamageModel *v26; // rbx
  UFG::qReflectHandleBase v27; // [rsp+28h] [rbp-40h] BYREF

  if ( !UFG::gFlowController.mCurrentState
    || !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
  {
    if ( LOBYTE(this->m_containmentInfo.UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr)
      && BYTE5(this->m_radio)
      && *(_DWORD *)&this->m_bPositionIsDirty != -1 )
    {
      *(float *)&this->m_bMissionPlaylist = delta_sec + *(float *)&this->m_bMissionPlaylist;
      v4 = *(_OWORD **)&this->m_fLastWhooshTime;
      if ( v4 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&this->m_fLastWhooshTime);
        v5 = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0>)v4[9];
        v6 = v4[10];
        v7 = v4[11];
        *(_OWORD *)&this->m_Flags = v4[8];
        this->m_BoundComponentHandles = v5;
        *(_OWORD *)&this->UFG::HkAudioEntityComponent::UFG::AudioEntity::vfptr = v6;
        *(_OWORD *)&this->UFG::HkAudioEntityComponent::UFG::AudioEntity::UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>::mNext = v7;
      }
      if ( UFG::VehicleAudioComponent::SoundbanksLoaded((UFG::VehicleAudioComponent *)((char *)this - 64)) )
      {
        v8 = (float *)&this->m_engineModel + 1;
        v9 = *(float *)&this->m_damageModel;
        if ( v9 <= *(float *)&this->m_radio )
          v9 = *(float *)&this->m_radio;
        if ( v9 >= *((float *)&this->m_envModel + 1) )
          v9 = *((float *)&this->m_envModel + 1);
        m_damageModel = (int)this->m_damageModel;
        if ( *(float *)&m_damageModel < *v8 )
          v11 = *(float *)&this->m_envModel;
        else
          v11 = *((float *)&this->m_damageModel + 1);
        UFG::qApproach(v8, v9, v11, delta_sec);
        UFG::VehicleAudioComponent::SetTargetSpeed((UFG::VehicleAudioComponent *)((char *)this - 64));
        m_pSubTypeParameters = this->m_pSubTypeParameters;
        v13 = *(_QWORD *)&m_pSubTypeParameters[13].m_rateLimitedSpeed.m_riseRate;
        if ( !v13 )
          goto LABEL_22;
        v14 = 0i64;
        if ( (*(_BYTE *)(v13 + 604) & 7) != 0 )
          v14 = *(UFG::PhysicsWheeledVehicle **)&m_pSubTypeParameters[13].m_rateLimitedSpeed.m_riseRate;
        if ( v14 )
          SurfacePropertyHandleUidUnderWheel = UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(v14, 0);
        else
LABEL_22:
          SurfacePropertyHandleUidUnderWheel = 0i64;
        UFG::qReflectHandleBase::qReflectHandleBase(&v27);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v16);
        v27.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v27, v27.mTypeUID, SurfacePropertyHandleUidUnderWheel);
        mData = v27.mData;
        if ( !v27.mData )
        {
          UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v27);
          mData = v27.mData;
        }
        v19 = (unsigned int)mData[1].mBaseNode.mChildren[0];
        if ( v19 != this->m_vehicleBank.mUID && v19 != -1 )
        {
          this->m_vehicleBank.mUID = v19;
          UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)this, 0x49597BC2u, v19);
          mPrev = (UFG::AudioEvent *)this->m_transformNode.mPrev;
          if ( mPrev )
            UFG::AudioEvent::StopAndForget(mPrev, 25);
        }
        if ( (BYTE4(this->m_radio) & 1) != 0 )
        {
          if ( !this->m_transformNode.mPrev
            && (this->m_vehicleBank.mUID || !LODWORD(m_pSubTypeParameters[17].m_parentEngineCurve)) )
          {
            UFG::VehicleAudioComponent::StartRoadNoise((UFG::VehicleAudioComponent *)((char *)this - 64));
          }
          if ( (BYTE4(this->m_radio) & 1) != 0 )
          {
            v21 = *(UFG::EngineModel2 **)&this->m_surfaceType;
            if ( v21 )
              UFG::EngineModel2::Update(v21, delta_sec, m_damageModel);
          }
        }
        v22 = this->m_physicsMoverInterface.mPrev;
        if ( v22 )
          UFG::EnvironmentalModel::Update((UFG::EnvironmentalModel *)v22, delta_sec);
        mNext = this->m_physicsMoverInterface.mNext;
        if ( mNext )
          UFG::Radio::Update((UFG::Radio *)mNext, delta_sec);
        m_pPointer = this->m_physicsMoverInterface.m_pPointer;
        if ( m_pPointer && HIDWORD(m_pPointer->vfptr[53].__vecDelDtor) )
        {
          v25 = delta_sec + *(float *)&m_pPointer->m_SafePointerList.mNode.mPrev;
          *(float *)&m_pPointer->m_SafePointerList.mNode.mPrev = v25;
          if ( v25 >= UFG::DriverReactions::sm_ReactionCooldownPeriod )
            HIDWORD(m_pPointer->m_SafePointerList.mNode.mPrev) = 0;
        }
        UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)this, delta_sec);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v27);
      }
      else
      {
        UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)this, delta_sec);
      }
    }
    else if ( *(_QWORD *)&this->m_hornTime )
    {
      UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)this, delta_sec);
      v26 = *(UFG::DamageModel **)&this->m_hornTime;
      UFG::DamageModel::HandleDamagedTires(v26);
      UFG::DamageModel::HandleDamagedEngine(v26);
    }
  }
}

// File Line: 1690
// RVA: 0x673C50
float __fastcall UFG::VehicleAudioComponent::CalculateAndApplyDoppler(
        UFG::VehicleAudioComponent *this,
        float delta_sec,
        UFG::qVector3 *vListenerPos,
        UFG::qVector3 *vListenerVelocity)
{
  float v5; // xmm13_4
  float *m_pPointer; // rbx
  UFG::DriverReactions *p_m_driverReaction; // rsi
  UFG::qVector3 *v8; // rcx
  UFG::qVector3 *v9; // rax
  UFG::qVector3 *v10; // rcx
  UFG::qVector3 *v11; // rdx
  __m128 x_low; // xmm6
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm0_4
  __m128 mNext_low; // xmm1
  float v18; // xmm9_4
  unsigned int v19; // eax
  float v20; // xmm8_4
  float v21; // xmm8_4
  float v22; // xmm10_4
  __m128 v23; // xmm11
  float v24; // xmm12_4
  float v25; // xmm4_4
  __m128 mNext_high; // xmm2
  float v27; // xmm5_4
  __m128 v28; // xmm3
  float v29; // xmm1_4
  float v30; // xmm10_4
  float v31; // xmm11_4
  float v32; // xmm12_4
  __m128 v33; // xmm3
  float v34; // xmm1_4
  double v35; // xmm0_8
  float v36; // xmm6_4
  bool v37; // bl
  bool v38; // bp
  float v39; // xmm0_4
  UFG::SimComponent *v40; // rcx

  v5 = UFG::AudioEntity::CalculateAndApplyDoppler((UFG::AudioEntity *)this, delta_sec, vListenerPos, vListenerVelocity);
  m_pPointer = (float *)UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer;
  if ( UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer )
  {
    p_m_driverReaction = (UFG::DriverReactions *)&this[-1].m_driverReaction;
    if ( &this[-1].m_driverReaction != (UFG::DriverReactions **)UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer )
    {
      v8 = *(UFG::qVector3 **)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_Flags;
      v9 = &UFG::qVector3::msZero;
      if ( v8 )
        v10 = v8 + 2;
      else
        v10 = &UFG::qVector3::msZero;
      v11 = *(UFG::qVector3 **)&this->m_WorldMatrix.v0.x;
      if ( v11 )
        v9 = v11 + 2;
      x_low = (__m128)LODWORD(v9->x);
      x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v10->x) * (float)(x_low.m128_f32[0] - v10->x))
                                + (float)((float)(v9->y - v10->y) * (float)(v9->y - v10->y)))
                        + (float)((float)(v9->z - v10->z) * (float)(v9->z - v10->z));
      v13 = (float)(UFG::VehicleAudioComponent::sm_fWhooshSpeedThreshold * 0.27777779)
          * (float)(UFG::VehicleAudioComponent::sm_fWhooshSpeedThreshold * 0.27777779);
      v14 = (float)(UFG::VehicleAudioComponent::sm_fHonkSpeedThreshold * 0.27777779)
          * (float)(UFG::VehicleAudioComponent::sm_fHonkSpeedThreshold * 0.27777779);
      if ( x_low.m128_f32[0] >= v13 || x_low.m128_f32[0] >= v14 )
      {
        v15 = _mm_sqrt_ps(x_low).m128_f32[0];
        v16 = *((float *)&this->UFG::HkAudioEntityComponent::UFG::AudioEntity::UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>::mNext
              + 1)
            - *((float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_SafePointerList.mNode.mNext
              + 1);
        mNext_low = (__m128)LODWORD(this->UFG::HkAudioEntityComponent::UFG::AudioEntity::UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>::mNext);
        mNext_low.m128_f32[0] = (float)((float)((float)(mNext_low.m128_f32[0]
                                                      - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_SafePointerList.mNode.mNext)
                                              * (float)(mNext_low.m128_f32[0]
                                                      - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_SafePointerList.mNode.mNext))
                                      + (float)(v16 * v16))
                              + (float)((float)(*(float *)&this->m_name.mUID
                                              - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_TypeUID)
                                      * (float)(*(float *)&this->m_name.mUID
                                              - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_TypeUID));
        v18 = _mm_sqrt_ps(mNext_low).m128_f32[0];
        if ( (float)(v18 / v15) <= UFG::VehicleAudioComponent::sm_fWhooshScaledDistanceThreshold
          && x_low.m128_f32[0] >= v13
          && (float)(*(float *)&this->m_entScrape + 2.0) <= *(float *)&this->m_bMissionPlaylist )
        {
          v19 = _S8_17;
          if ( (_S8_17 & 1) == 0 )
          {
            _S8_17 |= 1u;
            s_uWhooshRelSpeed = UFG::TiDo::CalcWwiseUid("whoosh_rel_speed");
            v19 = _S8_17;
          }
          if ( (v19 & 2) == 0 )
          {
            _S8_17 = v19 | 2;
            uEvtWhoosh = UFG::TiDo::CalcWwiseUid("Play_vehicle_whooshes");
          }
          v20 = v15 * 3.5999999;
          if ( LODWORD(this->m_pSubTypeParameters[17].m_parentEngineCurve) || v20 >= 100.0 )
          {
            UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)this, s_uWhooshRelSpeed, v20);
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)this, uEvtWhoosh, 0i64, 0, 0i64);
            LODWORD(this->m_entScrape) = *(_DWORD *)&this->m_bMissionPlaylist;
          }
        }
        if ( LOBYTE(p_m_driverReaction[eTARGET_TYPE_FOCUS].m_reactionCooldownTimer) )
        {
          if ( BYTE1(p_m_driverReaction[eTARGET_TYPE_CONVERSATION].m_numReactions) )
          {
            v21 = UFG::VehicleAudioComponent::sm_fHonkDistanceThreshold;
            if ( v18 <= UFG::VehicleAudioComponent::sm_fHonkDistanceThreshold && x_low.m128_f32[0] >= v14 )
            {
              v22 = *(float *)&this->UFG::HkAudioEntityComponent::UFG::AudioEntity::UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>::mNext
                  + *(float *)&this->m_Flags;
              mNext_high = (__m128)HIDWORD(this->UFG::HkAudioEntityComponent::UFG::AudioEntity::UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>::mNext);
              v23 = mNext_high;
              v23.m128_f32[0] = mNext_high.m128_f32[0] + *(float *)(&this->m_SimObjIndex + 1);
              v24 = *(float *)&this->m_name.mUID + *(float *)&this->m_pSimObject;
              v25 = *(float *)&this->UFG::HkAudioEntityComponent::UFG::AudioEntity::UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>::mNext
                  - m_pPointer[36];
              mNext_high.m128_f32[0] = mNext_high.m128_f32[0] - m_pPointer[37];
              v27 = *(float *)&this->m_name.mUID - m_pPointer[38];
              v28 = v23;
              v28.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22))
                              + (float)(v24 * v24);
              v29 = v28.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
              v30 = v22 * v29;
              v31 = v23.m128_f32[0] * v29;
              v32 = v24 * v29;
              v33 = mNext_high;
              v33.m128_f32[0] = (float)((float)(mNext_high.m128_f32[0] * mNext_high.m128_f32[0]) + (float)(v25 * v25))
                              + (float)(v27 * v27);
              v34 = v33.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
              mNext_high.m128_f32[0] = (float)((float)((float)(mNext_high.m128_f32[0] * v34) * v31)
                                             + (float)((float)(v25 * v34) * v30))
                                     + (float)((float)(v27 * v34) * v32);
              if ( mNext_high.m128_f32[0] > 0.0 )
              {
                v35 = UFG::qACos(*(double *)mNext_high.m128_u64);
                if ( (float)((float)(*(float *)&v35 * 180.0) * 0.31830987) < UFG::VehicleAudioComponent::sm_fHonkApproachAngleThreshold )
                {
                  v36 = 1.0 - (float)(v18 / v21);
                  v37 = UFG::VehicleAudioComponent::sm_fOncomingHonkChance > UFG::qRandom(
                                                                               v36,
                                                                               (unsigned int *)&UFG::qDefaultSeed);
                  v38 = UFG::VehicleAudioComponent::sm_fOncomingYellChance > UFG::qRandom(
                                                                               v36,
                                                                               (unsigned int *)&UFG::qDefaultSeed);
                  if ( v37 )
                  {
                    v39 = UFG::qRandom(
                            UFG::VehicleAudioComponent::sm_fOncomingHonkMaxLength
                          - UFG::VehicleAudioComponent::sm_fOncomingHonkMinLength,
                            (unsigned int *)&UFG::qDefaultSeed);
                    UFG::VehicleAudioComponent::HonkAmbientHorn(
                      (UFG::VehicleAudioComponent *)((char *)this - 64),
                      v39 + UFG::VehicleAudioComponent::sm_fOncomingHonkMinLength);
                  }
                  if ( v38 )
                  {
                    v40 = this->m_physicsMoverInterface.m_pPointer;
                    if ( v40 )
                      UFG::DriverReactions::YellReactionBase(
                        (UFG::DriverReactions *)v40,
                        eVocalDriverReactionType_BadDriver);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return v5;
}

// File Line: 1794
// RVA: 0x677F20
void __fastcall UFG::VehicleAudioComponent::EngineStart(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  char v3; // al

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = *((_BYTE *)this + 636);
    if ( (v3 & 2) == 0 )
      *((_BYTE *)this + 636) = v3 | 2;
  }
}

// File Line: 1824
// RVA: 0x68C3B0
void __fastcall UFG::VehicleAudioComponent::StartRoadNoise(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioSubTypeParameters *m_pSubTypeParameters; // rax
  UFG::qPropertySet *mpPropertySet; // rdi
  char *MemImagePtr; // rax

  m_pSubTypeParameters = this->m_pSubTypeParameters;
  if ( m_pSubTypeParameters )
  {
    mpPropertySet = m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
    else
      MemImagePtr = 0i64;
    UFG::AudioEntity::CreateAndPlayEvent(
      &this->UFG::AudioEntity,
      *((_DWORD *)MemImagePtr + 66),
      &this->m_ecRoadNoise,
      0i64,
      0x3E8u,
      0i64);
  }
}

// File Line: 1848
// RVA: 0x68C9B0
void __fastcall UFG::VehicleAudioComponent::StopRadio(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::RadioFullyControlled *m_radio; // rcx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
      ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD))m_radio->vfptr[1].CountNumPlayingEvents)(m_radio, 0i64);
    *((_BYTE *)this + 636) &= ~0x20u;
  }
}

// File Line: 1861
// RVA: 0x68B130
void __fastcall UFG::VehicleAudioComponent::SetRadioStation(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *stationIdx)
{
  unsigned int v2; // edi
  UFG::RadioFullyControlled *m_radio; // rcx

  v2 = (unsigned int)stationIdx;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          stationIdx) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
      UFG::Radio::SetStation(m_radio, v2);
  }
}

// File Line: 1872
// RVA: 0x67B140
__int64 __fastcall UFG::VehicleAudioComponent::GetRadioStation(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::RadioFullyControlled *m_radio; // rax

  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
    return 0i64;
  m_radio = this->m_radio;
  if ( !m_radio )
    return 0i64;
  else
    return m_radio->m_curStation->m_id;
}

// File Line: 1885
// RVA: 0x68B070
void __fastcall UFG::VehicleAudioComponent::SetRadioIsEnabled(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *isEnabled)
{
  char v2; // di
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  UFG::RadioFullyControlled *v6; // rax
  UFG::RadioFullyControlled *m_radio; // rcx

  v2 = (char)isEnabled;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          isEnabled) )
  {
    *((_BYTE *)this + 636) &= ~8u;
    *((_BYTE *)this + 636) |= 8 * (v2 & 1 | 2);
    if ( v2 )
    {
      if ( !this->m_radio )
      {
        v6 = UFG::RadioFullyControlled::sm_playerRadio;
        if ( UFG::RadioFullyControlled::sm_playerRadio )
        {
          if ( UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent )
          {
            UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = 0i64;
            v6 = UFG::RadioFullyControlled::sm_playerRadio;
          }
        }
        v6->m_pVehAudComponent = this;
        this->m_radio = UFG::RadioFullyControlled::sm_playerRadio;
      }
    }
    else if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
    {
      m_radio = this->m_radio;
      if ( m_radio )
        ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD))m_radio->vfptr[1].CountNumPlayingEvents)(
          m_radio,
          0i64);
      *((_BYTE *)this + 636) &= ~0x20u;
    }
  }
}

// File Line: 1915
// RVA: 0x67B0D0
bool __fastcall UFG::VehicleAudioComponent::GetRadioIsEnabled(UFG::VehicleAudioComponent *this)
{
  char v1; // al
  UFG::VehicleAudioSubTypeParameters *m_pSubTypeParameters; // rax
  UFG::qPropertySet *mpPropertySet; // rbx

  v1 = *((_BYTE *)this + 636);
  if ( (v1 & 0x10) != 0 )
  {
    LOBYTE(m_pSubTypeParameters) = (v1 & 8) != 0;
  }
  else
  {
    m_pSubTypeParameters = this->m_pSubTypeParameters;
    if ( m_pSubTypeParameters )
    {
      mpPropertySet = m_pSubTypeParameters->mpPropertySet;
      if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
        LOBYTE(m_pSubTypeParameters) = UFG::qPropertySet::GetMemImagePtr(mpPropertySet)[192];
      else
        LOBYTE(m_pSubTypeParameters) = MEMORY[0xC0];
    }
  }
  return (char)m_pSubTypeParameters;
}

// File Line: 1931
// RVA: 0x68B4F0
void __fastcall UFG::VehicleAudioComponent::SetShutdownOnExit(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *shutdown)
{
  char v2; // bl

  v2 = (char)shutdown;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          shutdown) )
  {
    *((_BYTE *)this + 638) &= ~0x40u;
    *((_BYTE *)this + 638) |= (v2 & 1) << 6;
  }
}

// File Line: 1985
// RVA: 0x68DFB0
void __fastcall UFG::VehicleAudioComponent::TurnOffRadio(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  __int64 v3; // rdx
  UFG::RadioFullyControlled *m_radio; // rcx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
    {
      LOBYTE(v3) = this->m_eDriverType == eDriverType_Player;
      ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))m_radio->vfptr[1].CountNumPlayingEvents)(m_radio, v3);
    }
    *((_BYTE *)this + 0x27C) &= ~0x20u;
  }
}

// File Line: 2003
// RVA: 0x68EAF0
void __fastcall UFG::VehicleAudioComponent::TurnOnRadio(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::RadioFullyControlled *m_radio; // rcx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
    {
      if ( (*((_BYTE *)&m_radio->UFG::Radio + 344) & 4) != 0 )
        ((void (__fastcall *)(UFG::RadioFullyControlled *))m_radio->vfptr[1].AudioEntityUpdate)(m_radio);
    }
  }
}

// File Line: 2016
// RVA: 0x6745A0
void __fastcall UFG::VehicleAudioComponent::ClearRadioPlaylist(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::RadioFullyControlled *m_radio; // rax
  UFG::RadioStation *m_curStation; // rcx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
    {
      m_curStation = m_radio->m_curStation;
      if ( m_curStation )
        UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&m_curStation->m_playList);
    }
  }
}

// File Line: 2026
// RVA: 0x674550
void __fastcall UFG::VehicleAudioComponent::ClearRadioHistory(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::RadioFullyControlled *m_radio; // rbx
  UFG::RadioStation *m_curStation; // rbx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
    {
      m_curStation = m_radio->m_curStation;
      if ( m_curStation )
      {
        UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&m_curStation->m_prevPlayed);
        m_curStation->m_numRecentlyPlayed = 0;
      }
    }
  }
}

// File Line: 2036
// RVA: 0x670190
void __fastcall UFG::VehicleAudioComponent::AddTrackToPlaylist(UFG::VehicleAudioComponent *this, char *track)
{
  UFG::RadioFullyControlled *m_radio; // rax
  UFG::RadioStation *m_curStation; // rbx
  unsigned int v6; // eax

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)track) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
    {
      m_curStation = m_radio->m_curStation;
      if ( m_curStation )
      {
        v6 = UFG::TiDo::CalcWwiseUid(track);
        UFG::RadioStation::AddToPlaylist(m_curStation, v6, 0);
      }
    }
  }
}

// File Line: 2047
// RVA: 0x688640
void __fastcall UFG::VehicleAudioComponent::RandomizeRadioPlaylist(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::RadioFullyControlled *m_radio; // rax
  UFG::RadioStation *m_curStation; // rcx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    m_radio = this->m_radio;
    if ( m_radio )
    {
      m_curStation = m_radio->m_curStation;
      if ( m_curStation )
        UFG::RadioStation::RandomizePlaylist(m_curStation);
    }
  }
}

// File Line: 2058
// RVA: 0x68C390
void __fastcall UFG::VehicleAudioComponent::StartHorn(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 638) = *((_BYTE *)this + 638) ^ (*((_BYTE *)this + 638) ^ (4 * stimulus)) & 4 | 2;
}

// File Line: 2066
// RVA: 0x676D70
void __fastcall UFG::VehicleAudioComponent::DoStartHorn(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *stimulus)
{
  char v2; // bp
  UFG::qPropertySet *mpPropertySet; // rsi
  char *MemImagePtr; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h] BYREF

  v2 = (char)stimulus;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          stimulus) )
  {
    if ( !this->m_ecHorn.m_pEvent )
    {
      mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
      if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
      else
        MemImagePtr = 0i64;
      UFG::AudioEntity::CreateAndPlayEvent(
        &this->UFG::AudioEntity,
        *((_DWORD *)MemImagePtr + 44),
        &this->m_ecHorn,
        0i64,
        0,
        0i64);
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
      if ( v2 )
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_VEHICLE_HORN,
          &stimulus_parameters,
          this->m_pSimObject);
    }
    *((_BYTE *)this + 638) |= 1u;
  }
}

// File Line: 2090
// RVA: 0x68C990
void __fastcall UFG::VehicleAudioComponent::StopHorn(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 0x27E) &= 0xF9u;
  *((_BYTE *)this + 0x27E) |= 4 * stimulus;
}

// File Line: 2098
// RVA: 0x677130
void __fastcall UFG::VehicleAudioComponent::DoStopHorn(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *stimulus)
{
  char v2; // di
  UFG::AudioEvent *m_pEvent; // rcx

  v2 = (char)stimulus;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          stimulus) )
  {
    m_pEvent = this->m_ecHorn.m_pEvent;
    if ( m_pEvent )
    {
      UFG::AudioEvent::StopAndForget(m_pEvent, 0);
      if ( v2 )
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_VEHICLE_HORN, this->m_pSimObject);
    }
    *((_BYTE *)this + 638) &= 0xFCu;
  }
}

// File Line: 2117
// RVA: 0x67F4E0
bool __fastcall UFG::VehicleAudioComponent::IsPoliceVehicle(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *mpPropertySet; // rbx

  mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    return *(_DWORD *)UFG::qPropertySet::GetMemImagePtr(mpPropertySet) == police.mUID;
  else
    return (_DWORD)MEMORY[0] == police.mUID;
}

// File Line: 2131
// RVA: 0x67ED10
bool __fastcall UFG::VehicleAudioComponent::IsEmergencyVehicle(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *mpPropertySet; // rbx

  mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    return *(_DWORD *)UFG::qPropertySet::GetMemImagePtr(mpPropertySet) == emergency.mUID;
  else
    return (_DWORD)MEMORY[0] == emergency.mUID;
}

// File Line: 2145
// RVA: 0x67F5B0
bool __fastcall UFG::VehicleAudioComponent::IsUndercoverVehicle(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *mpPropertySet; // rbx

  mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    return *(_DWORD *)UFG::qPropertySet::GetMemImagePtr(mpPropertySet) == undercover.mUID;
  else
    return (_DWORD)MEMORY[0] == undercover.mUID;
}

// File Line: 2159
// RVA: 0x68C420
void __fastcall UFG::VehicleAudioComponent::StartSiren(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 0x27E) |= 0x10u;
}

// File Line: 2166
// RVA: 0x676E70
void __fastcall UFG::VehicleAudioComponent::DoStartSiren(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *stimulus)
{
  UFG::qPropertySet *mpPropertySet; // rsi
  char *MemImagePtr; // rax

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          stimulus) )
  {
    if ( !this->m_ecSiren.m_pEvent )
    {
      mpPropertySet = this->m_pSubTypeParameters->mpPropertySet;
      if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
      else
        MemImagePtr = 0i64;
      UFG::AudioEntity::CreateAndPlayEvent(
        &this->UFG::AudioEntity,
        *((_DWORD *)MemImagePtr + 62),
        &this->m_ecSiren,
        0i64,
        0,
        0i64);
    }
    *((_BYTE *)this + 638) |= 8u;
  }
}

// File Line: 2183
// RVA: 0x68C9F0
void __fastcall UFG::VehicleAudioComponent::StopSiren(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 638) &= ~0x10u;
}

// File Line: 2190
// RVA: 0x677190
void __fastcall UFG::VehicleAudioComponent::DoStopSiren(
        UFG::VehicleAudioComponent *this,
        hkgpIndexedMeshDefinitions::Edge *stimulus)
{
  UFG::AudioEvent *m_pEvent; // rcx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx

  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          stimulus) )
  {
    m_pEvent = this->m_ecSiren.m_pEvent;
    if ( m_pEvent )
    {
      UFG::AudioEvent::StopAndForget(m_pEvent, 0);
      v4 = _S9_19;
      if ( (_S9_19 & 1) == 0 )
      {
        _S9_19 |= 1u;
        play_siren_windown = UFG::TiDo::CalcWwiseUid("play_siren_windown");
        v4 = _S9_19;
      }
      if ( (v4 & 2) != 0 )
      {
        v5 = play_siren_windown_ai;
      }
      else
      {
        _S9_19 = v4 | 2;
        v5 = UFG::TiDo::CalcWwiseUid("play_siren_windown_ai");
        play_siren_windown_ai = v5;
      }
      v6 = play_siren_windown;
      if ( this->m_eDriverType )
        v6 = v5;
      UFG::AudioEntity::CreateAndPlayEvent(&this->UFG::AudioEntity, v6, 0i64, 0, 0i64);
    }
    *((_BYTE *)this + 638) &= ~8u;
  }
}

// File Line: 2218
// RVA: 0x67D250
void __fastcall UFG::VehicleAudioComponent::HonkAmbientHorn(UFG::VehicleAudioComponent *this, float timeSec)
{
  const char *v3; // rdx
  unsigned int v4; // eax
  char dest[96]; // [rsp+30h] [rbp-78h] BYREF

  if ( !this->m_ecHorn.m_pEvent )
  {
    memset(dest, 0, sizeof(dest));
    if ( timeSec >= 0.5 )
    {
      v3 = "play_os_horn_t%u_medium";
      if ( timeSec >= 1.0 )
        v3 = "play_os_horn_t%u_long";
      UFG::qSPrintf(dest, v3, this->m_ambientHornId);
    }
    else
    {
      UFG::qSPrintf(dest, "play_os_horn_t%u_short", this->m_ambientHornId);
    }
    v4 = UFG::TiDo::CalcWwiseUid(dest);
    UFG::AudioEntity::CreateAndPlayEvent(&this->UFG::AudioEntity, v4, &this->m_ecHorn, 0i64, 0, 0i64);
  }
}

// File Line: 2265
// RVA: 0x68B690
void __fastcall UFG::VehicleAudioComponent::SetTargetSpeed(UFG::VehicleAudioComponent *this)
{
  UFG::PhysicsMoverInterface *m_pPointer; // rax
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  UFG::qVector3 *p_m_vCurVelocity; // rax

  m_pPointer = (UFG::PhysicsMoverInterface *)this->m_physicsMoverInterface.m_pPointer;
  if ( m_pPointer )
  {
    this->m_rateLimitedSpeed.m_targetValue = m_pPointer->mForwardSpeed * 3.5999999;
  }
  else
  {
    m_pMotionData = this->m_pMotionData;
    if ( m_pMotionData )
      p_m_vCurVelocity = &m_pMotionData->m_vCurVelocity;
    else
      p_m_vCurVelocity = &UFG::qVector3::msZero;
    this->m_rateLimitedSpeed.m_targetValue = (float)((float)((float)(this->m_WorldMatrix.v0.y * p_m_vCurVelocity->y)
                                                           + (float)(p_m_vCurVelocity->x * this->m_WorldMatrix.v0.x))
                                                   + (float)(this->m_WorldMatrix.v0.z * p_m_vCurVelocity->z))
                                           * 3.5999999;
  }
}

// File Line: 2286
// RVA: 0x68ED70
void __fastcall UFG::VehicleAudioComponent::UnloadSoundbanks(UFG::VehicleAudioComponent *this)
{
  UFG::qWiseSymbol *null; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol *v4; // rax

  if ( (*((_BYTE *)this + 638) & 0x20) != 0 )
  {
    UFG::SoundBankManager::QueueBankForUnload(&this->m_vehicleBank);
    UFG::SoundBankManager::QueueBankForUnload(&this->m_driverTypeBank);
    UFG::SoundBankManager::QueueBankForUnload(&this->m_commonBank);
    null = UFG::qWiseSymbol::get_null();
    UFG::qWiseSymbol::operator=(&this->m_vehicleBank, null);
    v3 = UFG::qWiseSymbol::get_null();
    UFG::qWiseSymbol::operator=(&this->m_driverTypeBank, v3);
    v4 = UFG::qWiseSymbol::get_null();
    UFG::qWiseSymbol::operator=(&this->m_commonBank, v4);
    *((_BYTE *)this + 638) &= ~0x20u;
  }
}

// File Line: 2304
// RVA: 0x68C240
bool __fastcall UFG::VehicleAudioComponent::SoundbanksLoaded(UFG::VehicleAudioComponent *this)
{
  return (UFG::SoundBankManager::BankLoadRequestFinished(&this->m_vehicleBank)
       || this->m_vehicleBank.mUID == UFG::qWiseSymbol::get_null()->mUID)
      && (UFG::SoundBankManager::BankLoadRequestFinished(&this->m_driverTypeBank)
       || this->m_driverTypeBank.mUID == UFG::qWiseSymbol::get_null()->mUID)
      && (UFG::SoundBankManager::BankLoadRequestFinished(&this->m_commonBank)
       || this->m_commonBank.mUID == UFG::qWiseSymbol::get_null()->mUID);
}

// File Line: 2318
// RVA: 0x69B950
bool __fastcall UFG::VehicleAudioComponent::WheelsInAir(UFG::VehicleAudioComponent *this)
{
  UFG::SimComponent *m_pPointer; // rdi
  int mNext; // eax
  int v3; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::PhysicsWheeledVehicle *v5; // rcx

  m_pPointer = this->m_physicsMoverInterface.m_pPointer;
  mNext = (int)m_pPointer[12].m_BoundComponentHandles.mNode.mNext;
  if ( mNext )
  {
    v3 = 0;
    if ( mNext <= 0 )
    {
LABEL_9:
      LOBYTE(mNext) = 1;
    }
    else
    {
      while ( 1 )
      {
        mPrev = m_pPointer[10].m_SafePointerList.mNode.mPrev;
        if ( !mPrev )
          break;
        v5 = 0i64;
        if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
          v5 = (UFG::PhysicsWheeledVehicle *)m_pPointer[10].m_SafePointerList.mNode.mPrev;
        if ( !v5 || UFG::PhysicsWheeledVehicle::IsWheelOnGround(v5, v3) )
          break;
        if ( ++v3 >= SLODWORD(m_pPointer[12].m_BoundComponentHandles.mNode.mNext) )
          goto LABEL_9;
      }
      LOBYTE(mNext) = 0;
    }
  }
  return mNext;
}

// File Line: 2344
// RVA: 0x67C320
void __fastcall UFG::VehicleAudioComponent::HandleImpact(
        UFG::VehicleAudioComponent *this,
        float mappedVelocity,
        UFG::qVector3 *position,
        UFG::CollisionEvent::ContactType contactType,
        unsigned int myAudioProperty,
        unsigned int otherAudioProperty)
{
  unsigned int v9; // eax
  UFG::EngineModel2 *m_engineModel; // rax
  UFG::VehicleAudioComponent::ScrapeImpactEntity *m_entScrape; // rcx
  unsigned int v12; // esi
  unsigned int v13; // edi
  UFG::DriverReactions *m_driverReaction; // rcx
  char v15; // cl
  UFG::PassengerReactions v16; // [rsp+30h] [rbp-28h] BYREF
  __int64 v17; // [rsp+38h] [rbp-20h]
  UFG::OneShotHandle pHandle; // [rsp+60h] [rbp+8h] BYREF

  v17 = -2i64;
  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    v9 = _S10_14;
    if ( (_S10_14 & 1) == 0 )
    {
      _S10_14 |= 1u;
      s_uMaterial1 = UFG::TiDo::CalcWwiseUid("MATERIAL1");
      v9 = _S10_14;
    }
    if ( (v9 & 2) == 0 )
    {
      _S10_14 = v9 | 2;
      s_uMaterial2 = UFG::TiDo::CalcWwiseUid("MATERIAL2");
      v9 = _S10_14;
    }
    if ( (v9 & 4) == 0 )
    {
      _S10_14 = v9 | 4;
      s_uCollisionEvent = UFG::TiDo::CalcWwiseUid("PLAY_DEBRIS_COLLISION");
      v9 = _S10_14;
    }
    if ( (v9 & 8) == 0 )
    {
      _S10_14 = v9 | 8;
      s_uScrapeEvent = UFG::TiDo::CalcWwiseUid("PLAY_SCRAPE");
      v9 = _S10_14;
    }
    if ( (v9 & 0x10) == 0 )
    {
      _S10_14 = v9 | 0x10;
      s_uBikeCollisionVelocity = UFG::TiDo::CalcWwiseUid("velocity");
    }
    if ( mappedVelocity > 20.0 )
    {
      m_engineModel = this->m_engineModel;
      if ( m_engineModel )
      {
        m_engineModel->m_engineStateMachine->m_event = eEVENT_COLLISION;
        this->m_engineModel->m_engineStateMachine->m_eventParameter = (float)((float)(mappedVelocity * 0.0099999998)
                                                                            * 0.40000001)
                                                                    + 0.1;
      }
    }
    if ( contactType )
    {
      if ( contactType == SLIDING )
      {
        m_entScrape = this->m_entScrape;
        if ( m_entScrape )
          UFG::VehicleAudioComponent::ScrapeImpactEntity::HandleImpact(
            m_entScrape,
            s_uScrapeEvent,
            position,
            myAudioProperty,
            otherAudioProperty);
      }
    }
    else
    {
      pHandle.m_pOneShot = 0i64;
      UFG::OneShotPool::GetOneShotHandle(&pHandle, &this->m_WorldMatrix);
      if ( UFG::OneShotHandle::IsValid(&pHandle) )
      {
        v12 = myAudioProperty;
        UFG::AudioEntity::SetWwiseSwitch(pHandle.m_pOneShot, s_uMaterial1, myAudioProperty);
        v13 = otherAudioProperty;
        UFG::AudioEntity::SetWwiseSwitch(pHandle.m_pOneShot, s_uMaterial2, otherAudioProperty);
        UFG::AudioEntity::SetRtpcValue(pHandle.m_pOneShot, s_uBikeCollisionVelocity, mappedVelocity);
        UFG::OneShot::Play(pHandle.m_pOneShot, s_uCollisionEvent);
        m_driverReaction = this->m_driverReaction;
        if ( m_driverReaction
          && this->m_eDriverType
          && (v12 == 456259212 || v12 == -2083503057)
          && (v13 == 456259212 || v13 == -2083503057) )
        {
          UFG::DriverReactions::OnCollision(m_driverReaction);
        }
        v15 = UFG::PassengerReactions::sm_tweakablesLoaded;
        if ( !UFG::PassengerReactions::sm_tweakablesLoaded )
          v15 = 1;
        UFG::PassengerReactions::sm_tweakablesLoaded = v15;
        v16.m_pVehAudComponent = this;
        if ( mappedVelocity > 20.0 )
          UFG::PassengerReactions::OnCollision(&v16, v13);
        if ( this->m_eDriverType == eDriverType_Player )
        {
          if ( (_S10_14 & 0x20) == 0 )
          {
            _S10_14 |= 0x20u;
            rumble = UFG::TiDo::CalcWwiseUid("play_motion_vehicle_impact");
          }
          v16.m_pVehAudComponent = 0i64;
          UFG::OneShotPool::GetOneShotHandle((UFG::OneShotHandle *)&v16, &this->m_WorldMatrix);
          if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)&v16) )
          {
            UFG::AudioEntity::SetRtpcValue(
              (UFG::AudioEntity *)v16.m_pVehAudComponent,
              s_uBikeCollisionVelocity,
              mappedVelocity);
            UFG::OneShot::Play((UFG::OneShot *)v16.m_pVehAudComponent, rumble);
          }
          UFG::OneShotHandle::Release((UFG::OneShotHandle *)&v16);
        }
      }
      UFG::OneShotHandle::Release(&pHandle);
    }
  }
}

// File Line: 2437
// RVA: 0x669A40
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::ImpactEntity(UFG::VehicleAudioComponent::ImpactEntity *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  UFG::AudioEntity::AudioEntity(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::ImpactEntity::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vLocalPos.x = UFG::qVector3::msZero.x;
  this->m_vLocalPos.y = y;
  this->m_vLocalPos.z = z;
  this->m_pVehicleAudio = 0i64;
  this->m_Event.m_pEvent = 0i64;
  this->m_bActive = 0;
}

// File Line: 2444
// RVA: 0x697BC0
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::UpdateImpactPosition(
        UFG::VehicleAudioComponent::ImpactEntity *this,
        UFG::qVector3 *vWorldPos)
{
  UFG::VehicleAudioComponent *m_pVehicleAudio; // rax
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm6_4

  m_pVehicleAudio = this->m_pVehicleAudio;
  v3 = vWorldPos->y - m_pVehicleAudio->m_WorldMatrix.v3.y;
  v4 = vWorldPos->x - m_pVehicleAudio->m_WorldMatrix.v3.x;
  v5 = (float)((float)(v3 * m_pVehicleAudio->m_WorldMatrix.v0.y) + (float)(v4 * m_pVehicleAudio->m_WorldMatrix.v0.x))
     + (float)((float)(vWorldPos->z - m_pVehicleAudio->m_WorldMatrix.v3.z) * m_pVehicleAudio->m_WorldMatrix.v0.z);
  v6 = (float)(v3 * m_pVehicleAudio->m_WorldMatrix.v2.y) + (float)(v4 * m_pVehicleAudio->m_WorldMatrix.v2.x);
  v7 = vWorldPos->z - m_pVehicleAudio->m_WorldMatrix.v3.z;
  v8 = (float)(v3 * m_pVehicleAudio->m_WorldMatrix.v1.y) + (float)(v4 * m_pVehicleAudio->m_WorldMatrix.v1.x);
  v9 = v7 * m_pVehicleAudio->m_WorldMatrix.v2.z;
  v10 = v7 * m_pVehicleAudio->m_WorldMatrix.v1.z;
  this->m_vLocalPos.x = v5;
  v11 = v6 + v9;
  v12 = v8 + v10;
  this->m_vLocalPos.y = v12;
  this->m_vLocalPos.z = v11;
  v13 = (float)((float)((float)(v12 * m_pVehicleAudio->m_WorldMatrix.v1.x)
                      + (float)(v5 * m_pVehicleAudio->m_WorldMatrix.v0.x))
              + (float)(v11 * m_pVehicleAudio->m_WorldMatrix.v2.x))
      + m_pVehicleAudio->m_WorldMatrix.v3.x;
  v14 = (float)((float)((float)(v5 * m_pVehicleAudio->m_WorldMatrix.v0.y)
                      + (float)(v12 * m_pVehicleAudio->m_WorldMatrix.v1.y))
              + (float)(v11 * m_pVehicleAudio->m_WorldMatrix.v2.y))
      + m_pVehicleAudio->m_WorldMatrix.v3.y;
  v15 = (float)((float)((float)(v5 * m_pVehicleAudio->m_WorldMatrix.v0.z)
                      + (float)(v12 * m_pVehicleAudio->m_WorldMatrix.v1.z))
              + (float)(v11 * m_pVehicleAudio->m_WorldMatrix.v2.z))
      + m_pVehicleAudio->m_WorldMatrix.v3.z;
  this->m_WorldMatrix.v3.y = v14;
  this->m_WorldMatrix.v3.x = v13;
  this->m_WorldMatrix.v3.w = 1.0;
  this->m_WorldMatrix.v3.z = v15;
  UFG::AudioEntity::ForcePositionUpdate(this);
}

// File Line: 2452
// RVA: 0x67C0C0
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::HandleImpact(
        UFG::VehicleAudioComponent::ImpactEntity *this,
        unsigned int eventId,
        UFG::qVector3 *position,
        float mappedVelocity,
        unsigned int myAudioProperty,
        unsigned int otherAudioProperty)
{
  unsigned int v9; // eax

  v9 = _S11_11;
  if ( (_S11_11 & 1) == 0 )
  {
    _S11_11 |= 1u;
    s_uMaterial1_0 = UFG::TiDo::CalcWwiseUid("MATERIAL1");
    v9 = _S11_11;
  }
  if ( (v9 & 2) == 0 )
  {
    _S11_11 = v9 | 2;
    s_uMaterial2_0 = UFG::TiDo::CalcWwiseUid("MATERIAL2");
    v9 = _S11_11;
  }
  if ( (v9 & 4) == 0 )
  {
    _S11_11 = v9 | 4;
    s_uBikeCollisionVelocity_0 = UFG::TiDo::CalcWwiseUid("velocity");
  }
  UFG::VehicleAudioComponent::ImpactEntity::UpdateImpactPosition(this, position);
  UFG::AudioEntity::SetWwiseSwitch(this, s_uMaterial1_0, myAudioProperty);
  UFG::AudioEntity::SetWwiseSwitch(this, s_uMaterial2_0, otherAudioProperty);
  UFG::AudioEntity::SetRtpcValue(this, s_uBikeCollisionVelocity_0, mappedVelocity);
  this->m_bActive = UFG::AudioEntity::CreateAndPlayEvent(this, eventId, &this->m_Event, 0i64, 0, 0i64);
}

// File Line: 2469
// RVA: 0x6709B0
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::AudioEntityUpdate(
        UFG::VehicleAudioComponent::ImpactEntity *this,
        float delta_sec)
{
  UFG::VehicleAudioComponent *m_pVehicleAudio; // rax
  float x; // xmm2_4
  float y; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm2_4

  m_pVehicleAudio = this->m_pVehicleAudio;
  x = this->m_vLocalPos.x;
  y = this->m_vLocalPos.y;
  v6 = (float)((float)((float)(x * m_pVehicleAudio->m_WorldMatrix.v0.z)
                     + (float)(y * m_pVehicleAudio->m_WorldMatrix.v1.z))
             + (float)(this->m_vLocalPos.z * m_pVehicleAudio->m_WorldMatrix.v2.z))
     + m_pVehicleAudio->m_WorldMatrix.v3.z;
  v7 = (float)((float)((float)(x * m_pVehicleAudio->m_WorldMatrix.v0.y)
                     + (float)(y * m_pVehicleAudio->m_WorldMatrix.v1.y))
             + (float)(this->m_vLocalPos.z * m_pVehicleAudio->m_WorldMatrix.v2.y))
     + m_pVehicleAudio->m_WorldMatrix.v3.y;
  this->m_WorldMatrix.v3.x = (float)((float)((float)(y * m_pVehicleAudio->m_WorldMatrix.v1.x)
                                           + (float)(this->m_vLocalPos.x * m_pVehicleAudio->m_WorldMatrix.v0.x))
                                   + (float)(this->m_vLocalPos.z * m_pVehicleAudio->m_WorldMatrix.v2.x))
                           + m_pVehicleAudio->m_WorldMatrix.v3.x;
  this->m_WorldMatrix.v3.z = v6;
  this->m_WorldMatrix.v3.w = 1.0;
  this->m_WorldMatrix.v3.y = v7;
  UFG::AudioEntity::ForcePositionUpdate(this);
  UFG::AudioEntity::AudioEntityUpdate(this, delta_sec);
  if ( this->m_bActive && !this->m_Event.m_pEvent )
    this->m_bActive = 0;
}

// File Line: 2487
// RVA: 0x66A670
void __fastcall UFG::VehicleAudioComponent::ScrapeImpactEntity::ScrapeImpactEntity(
        UFG::VehicleAudioComponent::ScrapeImpactEntity *this)
{
  UFG::VehicleAudioComponent::ImpactEntity::ImpactEntity(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::ScrapeImpactEntity::`vftable;
  *(_QWORD *)&this->m_myPrevAudioProperty = 0i64;
  this->m_fScrapeCountdown = 0.0;
}

// File Line: 2493
// RVA: 0x67C1E0
void __fastcall UFG::VehicleAudioComponent::ScrapeImpactEntity::HandleImpact(
        UFG::VehicleAudioComponent::ScrapeImpactEntity *this,
        unsigned int eventId,
        UFG::qVector3 *position,
        unsigned int myAudioProperty,
        unsigned int otherAudioProperty)
{
  unsigned int v9; // eax
  UFG::AudioEvent *m_pEvent; // rcx
  unsigned int v11; // ebx

  v9 = _S12_12;
  if ( (_S12_12 & 1) == 0 )
  {
    _S12_12 |= 1u;
    s_uMaterial1_1 = UFG::TiDo::CalcWwiseUid("MATERIAL1");
    v9 = _S12_12;
  }
  if ( (v9 & 2) == 0 )
  {
    _S12_12 = v9 | 2;
    s_uMaterial2_1 = UFG::TiDo::CalcWwiseUid("MATERIAL2");
  }
  UFG::VehicleAudioComponent::ImpactEntity::UpdateImpactPosition(this, position);
  m_pEvent = this->m_Event.m_pEvent;
  if ( !m_pEvent )
  {
    UFG::AudioEntity::SetWwiseSwitch(this, s_uMaterial1_1, myAudioProperty);
    v11 = otherAudioProperty;
    goto LABEL_11;
  }
  v11 = otherAudioProperty;
  if ( this->m_myPrevAudioProperty != myAudioProperty || this->m_otherPrevAudioProperty != otherAudioProperty )
  {
    UFG::AudioEvent::StopAndForget(m_pEvent, 200);
    UFG::AudioEntity::SetWwiseSwitch(this, s_uMaterial1_1, myAudioProperty);
LABEL_11:
    UFG::AudioEntity::SetWwiseSwitch(this, s_uMaterial2_1, v11);
    UFG::AudioEntity::CreateAndPlayEvent(this, eventId, &this->m_Event, 0i64, 0, 0i64);
    this->m_otherPrevAudioProperty = v11;
    this->m_myPrevAudioProperty = myAudioProperty;
    goto LABEL_12;
  }
  UFG::AudioEvent::TouchUpdate(m_pEvent);
LABEL_12:
  this->m_fScrapeCountdown = 0.2;
}

// File Line: 2532
// RVA: 0x670BB0
void __fastcall UFG::VehicleAudioComponent::ScrapeImpactEntity::AudioEntityUpdate(
        UFG::VehicleAudioComponent::ScrapeImpactEntity *this,
        float delta_sec)
{
  UFG::VehicleAudioComponent *m_pVehicleAudio; // rax
  float x; // xmm2_4
  float y; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float m_fScrapeCountdown; // xmm0_4
  float v9; // xmm0_4
  UFG::AudioEvent *m_pEvent; // rcx

  m_pVehicleAudio = this->m_pVehicleAudio;
  x = this->m_vLocalPos.x;
  y = this->m_vLocalPos.y;
  v6 = (float)((float)((float)(x * m_pVehicleAudio->m_WorldMatrix.v0.z)
                     + (float)(y * m_pVehicleAudio->m_WorldMatrix.v1.z))
             + (float)(this->m_vLocalPos.z * m_pVehicleAudio->m_WorldMatrix.v2.z))
     + m_pVehicleAudio->m_WorldMatrix.v3.z;
  v7 = (float)((float)((float)(x * m_pVehicleAudio->m_WorldMatrix.v0.y)
                     + (float)(y * m_pVehicleAudio->m_WorldMatrix.v1.y))
             + (float)(this->m_vLocalPos.z * m_pVehicleAudio->m_WorldMatrix.v2.y))
     + m_pVehicleAudio->m_WorldMatrix.v3.y;
  this->m_WorldMatrix.v3.x = (float)((float)((float)(y * m_pVehicleAudio->m_WorldMatrix.v1.x)
                                           + (float)(this->m_vLocalPos.x * m_pVehicleAudio->m_WorldMatrix.v0.x))
                                   + (float)(this->m_vLocalPos.z * m_pVehicleAudio->m_WorldMatrix.v2.x))
                           + m_pVehicleAudio->m_WorldMatrix.v3.x;
  this->m_WorldMatrix.v3.z = v6;
  this->m_WorldMatrix.v3.w = 1.0;
  this->m_WorldMatrix.v3.y = v7;
  UFG::AudioEntity::ForcePositionUpdate(this);
  UFG::AudioEntity::AudioEntityUpdate(this, delta_sec);
  m_fScrapeCountdown = this->m_fScrapeCountdown;
  if ( m_fScrapeCountdown > 0.0 )
  {
    v9 = m_fScrapeCountdown - UFG::Metrics::msInstance.mSimTimeDelta;
    this->m_fScrapeCountdown = v9;
    if ( v9 <= 0.0 )
    {
      m_pEvent = this->m_Event.m_pEvent;
      if ( m_pEvent )
        UFG::AudioEvent::StopAndForget(m_pEvent, 200);
      this->m_fScrapeCountdown = 0.0;
    }
  }
}

// File Line: 2614
// RVA: 0x687440
void __fastcall UFG::VehicleAudioComponent::PlayVehicleEvent(
        UFG::VehicleAudioComponent *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::AudioEventController *pController,
        unsigned int fadeInDurationMs)
{
  UFG::qWiseSymbol *v8; // rax
  unsigned int mUID; // edx
  UFG::qWiseSymbol *v10; // rax
  UFG::AudioEntity *v11; // rcx

  if ( this->m_eDriverType )
    fadeInDurationMs = UFG::VehicleAudioComponent::sm_configPs->traffic_fadeout_time_ms;
  v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(this->m_pEnginePropertySet, name, DEPTH_RECURSE);
  if ( v8 )
  {
    mUID = v8->mUID;
  }
  else
  {
    v10 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(this->m_pSubTypeParameters->mpPropertySet, name, DEPTH_RECURSE);
    if ( v10 )
      mUID = v10->mUID;
    else
      mUID = 0;
  }
  v11 = &this->UFG::AudioEntity;
  if ( pController )
    UFG::AudioEntity::CreateAndPlayEvent(v11, mUID, pController, 0i64, fadeInDurationMs, 0i64);
  else
    UFG::AudioEntity::CreateAndPlayEvent(v11, mUID, 0i64, fadeInDurationMs, 0i64);
}

// File Line: 2657
// RVA: 0x67D0E0
bool __fastcall UFG::VehicleAudioComponent::HasDriver(UFG::VehicleAudioComponent *this)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  bool result; // al
  UFG::SimObjectCVBase *v4; // rcx
  UFG::SimObjectCVBase *v5; // rcx

  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  result = 1;
  if ( !m_pSimObject || !UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pSimObject) )
  {
    v4 = (UFG::SimObjectCVBase *)this->m_pSimObject;
    if ( !v4
      || !v4->m_Components.p[17].m_pComponent && !UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v4) )
    {
      v5 = (UFG::SimObjectCVBase *)this->m_pSimObject;
      if ( !v5 || !UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(v5) )
        return 0;
    }
  }
  return result;
}

// File Line: 2688
// RVA: 0x67D150
bool __fastcall UFG::VehicleAudioComponent::HasOccupant(UFG::VehicleAudioComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rdx
  int v5; // ecx
  __int64 i; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v9; // rdx
  int v10; // eax
  __int64 j; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_pComponent = m_pSimObject->m_Components.p[30].m_pComponent;
  if ( !m_pComponent )
    return 0;
  if ( m_pComponent[1].m_pSimObject )
  {
    mNext = m_pComponent[1].m_BoundComponentHandles.mNode.mNext;
    p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
    v5 = 0;
    for ( i = (__int64)&mNext[-4];
          (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)i != p_m_BoundComponentHandles;
          i = *(_QWORD *)(i + 72) - 64i64 )
    {
      ++v5;
    }
    return v5 != -1;
  }
  else
  {
    v8 = m_pComponent[1].m_BoundComponentHandles.mNode.mNext;
    v9 = &m_pComponent->m_BoundComponentHandles;
    v10 = 0;
    for ( j = (__int64)&v8[-4];
          (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)j != v9;
          j = *(_QWORD *)(j + 72) - 64i64 )
    {
      ++v10;
    }
    return v10 != 0;
  }
}

// File Line: 2723
// RVA: 0x67EC80
char __fastcall UFG::VehicleAudioComponent::IsDriverTypeWithinCutoffRange(
        UFG::VehicleAudioComponent *this,
        UFG::VehicleAudioComponent::eDriverType driverType,
        float distanceToListener2)
{
  UFG::SimComponent *m_pPointer; // rax
  float v4; // xmm1_4

  m_pPointer = this->m_physicsMoverInterface.m_pPointer;
  v4 = *(float *)&FLOAT_1_0;
  if ( m_pPointer && !LODWORD(m_pPointer[12].m_BoundComponentHandles.mNode.mNext) )
    v4 = FLOAT_2_0;
  if ( distanceToListener2 > (float)(UFG::VehicleAudioComponent::sm_configPs->all_vehicles_max_distance
                                   * UFG::VehicleAudioComponent::sm_configPs->all_vehicles_max_distance) )
    return 0;
  switch ( driverType )
  {
    case eDriverType_Script:
      return (float)((float)(UFG::VehicleAudioComponent::sm_configPs->script_vehicle_max_distance * v4)
                   * (float)(UFG::VehicleAudioComponent::sm_configPs->script_vehicle_max_distance * v4)) > distanceToListener2;
    case eDriverType_Cop:
      return (float)((float)(UFG::VehicleAudioComponent::sm_configPs->cop_vehicle_max_distance * v4)
                   * (float)(UFG::VehicleAudioComponent::sm_configPs->cop_vehicle_max_distance * v4)) > distanceToListener2;
    case eDriverType_Traffic:
      return (float)((float)(UFG::VehicleAudioComponent::sm_configPs->traffic_vehicle_max_distance * v4)
                   * (float)(UFG::VehicleAudioComponent::sm_configPs->traffic_vehicle_max_distance * v4)) > distanceToListener2;
  }
  return 1;
}

