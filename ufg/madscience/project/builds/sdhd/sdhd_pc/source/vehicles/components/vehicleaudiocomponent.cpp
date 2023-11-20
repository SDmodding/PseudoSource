// File Line: 142
// RVA: 0x1582A70
__int64 UFG::_dynamic_initializer_for__civilian__()
{
  civilian.mUID = UFG::qWiseSymbolUIDFromString("civilian", 0x811C9DC5);
  _((AMD_HD3D *)civilian.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__civilian__);
}

// File Line: 143
// RVA: 0x15837A0
__int64 UFG::_dynamic_initializer_for__police__()
{
  police.mUID = UFG::qWiseSymbolUIDFromString("police", 0x811C9DC5);
  _((AMD_HD3D *)police.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__police__);
}

// File Line: 144
// RVA: 0x1582B00
__int64 UFG::_dynamic_initializer_for__emergency__()
{
  emergency.mUID = UFG::qWiseSymbolUIDFromString("emergency", 0x811C9DC5);
  _((AMD_HD3D *)emergency.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__emergency__);
}

// File Line: 145
// RVA: 0x1585820
__int64 UFG::_dynamic_initializer_for__undercover__()
{
  undercover.mUID = UFG::qWiseSymbolUIDFromString("undercover", 0x811C9DC5);
  _((AMD_HD3D *)undercover.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__undercover__);
}

// File Line: 147
// RVA: 0x157B890
__int64 dynamic_initializer_for__UFG::VehicleAudioComponent::s_VehicleAudioComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::VehicleAudioComponent::s_VehicleAudioComponentList__);
}

// File Line: 148
// RVA: 0x67B510
signed __int64 __fastcall UFG::qReflectInventory<UFG::DUIThemeEditorWindow>::GetClassSize(UFG::qReflectInventory<UFG::DUIThemeEditorWindow> *this)
{
  return 640i64;
}

// File Line: 188
// RVA: 0x157B980
__int64 dynamic_initializer_for__UFG::VehicleAudioComponent::sm_vehicleFollowTarget__()
{
  UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer = 0i64;
  return atexit(dynamic_atexit_destructor_for__UFG::VehicleAudioComponent::sm_vehicleFollowTarget__);
}

// File Line: 195
// RVA: 0x157B930
__int64 dynamic_initializer_for__UFG::VehicleAudioParameters::sm_Map__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::VehicleAudioParameters::sm_Map.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::VehicleAudioParameters::sm_Map__);
}

// File Line: 215
// RVA: 0x66AA50
void __fastcall UFG::VehicleAudioParameters::VehicleAudioParameters(UFG::VehicleAudioParameters *this, UFG::qSymbol *parametersTableName)
{
  UFG::VehicleAudioParameters *v2; // rbx
  UFG::VehicleAudioSubTypeParameters *v3; // rbp
  UFG::qPropertySet *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *v10; // rax

  v2 = this;
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
  v3 = &this->m_trafficParameters;
  *(_QWORD *)&v3->m_rateLimitedSpeed.m_currentValue = 0i64;
  v3->m_rateLimitedSpeed.m_riseRate = 10000000.0;
  v3->m_rateLimitedSpeed.m_fallRate = 10000000.0;
  *(_QWORD *)&v3->m_rateLimitedSpeed.m_max = 1065353216i64;
  this->m_ParametersTableName.mUID = -1;
  this->m_uRefCount = 1;
  this->mNode.mUID = parametersTableName->mUID;
  v4 = UFG::PropertySetManager::FindPropertySet(parametersTableName);
  v2->m_pPropertySet = v4;
  if ( v4 )
  {
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(v4, (UFG::qSymbol *)&VehAudSym_propset_player.mUID, DEPTH_RECURSE);
    v6 = UFG::PropertySetManager::FindPropertySet(v5);
    UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(&v2->m_playerParameters, v6);
    v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v2->m_pPropertySet,
           (UFG::qSymbol *)&VehAudSym_propset_traffic.mUID,
           DEPTH_RECURSE);
    v8 = UFG::PropertySetManager::FindPropertySet(v7);
    UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(v3, v8);
    v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v2->m_pPropertySet,
           (UFG::qSymbol *)&VehAudSym_propset_ai.mUID,
           DEPTH_RECURSE);
    v10 = UFG::PropertySetManager::FindPropertySet(v9);
    UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(&v2->m_aiParameters, v10);
  }
}

// File Line: 254
// RVA: 0x66D250
void __fastcall UFG::VehicleAudioParameters::~VehicleAudioParameters(UFG::VehicleAudioParameters *this)
{
  UFG::VehicleAudioParameters *v1; // rdi
  UFG::EngineManager *v2; // rbx
  UFG::EngineManager *v3; // rbx
  UFG::EngineManager *v4; // rbx

  v1 = this;
  v2 = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(v2, &v1->m_trafficParameters.m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(v2, &v1->m_trafficParameters.m_parentEngineCurve->m_name);
  v3 = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(v3, &v1->m_aiParameters.m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(v3, &v1->m_aiParameters.m_parentEngineCurve->m_name);
  v4 = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(v4, &v1->m_playerParameters.m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(v4, &v1->m_playerParameters.m_parentEngineCurve->m_name);
}

// File Line: 260
// RVA: 0x67BAA0
UFG::qBaseTreeRB *__fastcall UFG::VehicleAudioParameters::GrabParametersInstance(UFG::qSymbol *parametersTableName)
{
  UFG::qSymbol *v1; // rbx
  UFG::qBaseTreeRB *result; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::VehicleAudioParameters *v4; // rax
  UFG::VehicleAudioParameters *v5; // rbx

  v1 = parametersTableName;
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
      UFG::VehicleAudioParameters::VehicleAudioParameters((UFG::VehicleAudioParameters *)v3, v1);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::VehicleAudioParameters::sm_Map.mTree, &v5->mNode);
    result = (UFG::qBaseTreeRB *)v5;
  }
  return result;
}

// File Line: 290
// RVA: 0x68AF70
void __fastcall UFG::VehicleAudioParameters::SetRLFFromPropertySet(UFG::RateLimitedFloat *rlf, UFG::qPropertySet *pSet)
{
  UFG::qPropertySet *v2; // rdi
  float v3; // xmm6_4
  UFG::RateLimitedFloat *v4; // rbx
  float v5; // xmm9_4
  float v6; // xmm8_4
  float v7; // xmm7_4
  float *v8; // rax
  float *v9; // rax
  float *v10; // rax
  float *v11; // rax

  if ( pSet )
  {
    v2 = pSet;
    v3 = 0.0;
    v4 = rlf;
    v5 = 0.0;
    v6 = *(float *)&FLOAT_1_0;
    v7 = 0.0;
    v8 = UFG::qPropertySet::Get<float>(pSet, (UFG::qSymbol *)&RlfSym_min_25.mUID, DEPTH_RECURSE);
    if ( v8 )
      v3 = *v8;
    v9 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&RlfSym_max_25.mUID, DEPTH_RECURSE);
    if ( v9 )
      v6 = *v9;
    v10 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&RlfSym_rise_rate_25.mUID, DEPTH_RECURSE);
    if ( v10 )
      v5 = *v10;
    v11 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&RlfSym_fall_rate_25.mUID, DEPTH_RECURSE);
    if ( v11 )
      v7 = *v11;
    v4->m_min = v3;
    v4->m_max = v6;
    v4->m_riseRate = v5;
    v4->m_fallRate = v7;
  }
}

// File Line: 328
// RVA: 0x67D310
void __fastcall UFG::VehicleAudioComponent::HotSwapEngineCurve(const char *filename)
{
  UFG::qPropertySet *v1; // rdi
  UFG::EngineManager *v2; // rax
  UFG::EngineCurve *v3; // rax
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]

  UFG::qString::qString(&v5, filename);
  UFG::qString::ReplaceString(&v5, ".props.xml", &customWorldMapCaption, 0);
  UFG::qString::ReplaceString(&v5, "Data\\PropertySets\\", &customWorldMapCaption, 0);
  UFG::qString::ReplaceCharInPlace(&v5, 92, 45);
  UFG::qSymbol::create_from_string(&result, v5.mData);
  v1 = UFG::PropertySetManager::ReloadPropertySet(&result);
  if ( v1 )
  {
    v2 = UFG::EngineManager::GetInstance();
    v3 = (UFG::EngineCurve *)UFG::EngineManager::FindEngine(v2, &v1->mName);
    if ( v3 )
      UFG::EngineCurve::Reload(v3, v1);
  }
  v4 = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext - 24;
  for ( UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext[-24];
        v4 != (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)(&UFG::VehicleAudioComponent::s_VehicleAudioComponentList
                                                                                  - 24);
        UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)v4 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *))v4->mPrev[8].mPrev)(v4);
    v4 = UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator->mNext - 24;
  }
  UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = 0i64;
  UFG::qString::~qString(&v5);
}

// File Line: 401
// RVA: 0x66A850
void __fastcall UFG::VehicleAudioComponent::VehicleAudioComponent(UFG::VehicleAudioComponent *this, UFG::SceneObjectProperties *pSceneObj, component_VehicleAudio *dataPtr)
{
  component_VehicleAudio *v3; // rbp
  UFG::VehicleAudioComponent *v4; // rdi
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v5; // rbx
  AMD_HD3D *v6; // rcx
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx
  signed __int64 v9; // rsi
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v11; // [rsp+60h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v12; // [rsp+60h] [rbp+18h]

  v3 = dataPtr;
  v4 = this;
  UFG::HkAudioEntityComponent::HkAudioEntityComponent((UFG::HkAudioEntityComponent *)&this->vfptr, pSceneObj);
  v5 = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::AudioEntity};
  v4->m_bMissionPlaylist = 0;
  v4->m_entScrape = 0i64;
  v6 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  v4->m_vehicleBank.mUID = (unsigned int)v6;
  _(v6);
  v7 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  v4->m_driverTypeBank.mUID = (unsigned int)v7;
  _(v7);
  v8 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  v4->m_commonBank.mUID = (unsigned int)v8;
  _(v8);
  *(_QWORD *)&v4->m_eDriverType = -1i64;
  v4->m_pTypeParameters = 0i64;
  v4->m_pSubTypeParameters = 0i64;
  *(_QWORD *)&v4->m_fTimeAlive = 0i64;
  v4->m_fLastWhooshTime = 0.0;
  v4->m_fDistance2ToListener = 3.4028235e38;
  *(_QWORD *)&v4->m_hornAccum = 0i64;
  v11 = &v4->m_physicsMoverInterface;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v4->m_physicsMoverInterface.m_pPointer = 0i64;
  v12 = &v4->m_transformNode;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v4->m_transformNode.m_pPointer = 0i64;
  v4->m_engineModel = 0i64;
  v4->m_damageModel = 0i64;
  v4->m_envModel = 0i64;
  v4->m_radio = 0i64;
  v4->m_driverReaction = 0i64;
  v4->m_ecRoadNoise.m_pEvent = 0i64;
  v4->m_ecHorn.m_pEvent = 0i64;
  v4->m_ecSiren.m_pEvent = 0i64;
  v9 = (signed __int64)&v4->m_rateLimitedSpeed;
  *(_QWORD *)v9 = 0i64;
  *(_DWORD *)(v9 + 8) = 1259902592;
  *(_DWORD *)(v9 + 12) = 1259902592;
  *(_QWORD *)(v9 + 16) = 1065353216i64;
  *((_BYTE *)v4 + 636) = *((_BYTE *)v4 + 636) & 0xC8 | 8;
  v4->m_bVehicleIsInitialized = 0;
  *((_BYTE *)v4 + 638) &= 0xC4u;
  *((_BYTE *)v4 + 638) |= 0x40u;
  v4->m_bOverrideDriverType = 0;
  v10 = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mPrev;
  UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)&v4->mPrev;
  v5->mPrev = v10;
  v4->mNext = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList;
  UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mPrev = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::VehicleAudioComponent::_VehicleAudioComponentTypeUID,
    "VehicleAudioComponent");
  if ( v3 )
    v4->m_pTypeParameters = UFG::VehicleAudioParameters::GrabParametersInstance(&v3->AudioPropertySet);
  UFG::RateLimitedFloat::SetMinMax(&v4->m_rateLimitedSpeed, 0.0, 1000.0);
}

// File Line: 426
// RVA: 0x66D060
void __fastcall UFG::VehicleAudioComponent::~VehicleAudioComponent(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v2; // rdi
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v3; // rcx
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v4; // rax
  UFG::VehicleAudioParameters *v5; // rsi
  bool v6; // zf
  UFG::DamageModel *v7; // rsi
  UFG::AudioEvent *v8; // rcx
  UFG::AudioEvent *v9; // rcx
  UFG::AudioEvent *v10; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v21; // rcx
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v22; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::`vftable{for `UFG::AudioEntity};
  if ( this == UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator )
    UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&this->mPrev[-24];
  v2 = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->m_pTypeParameters;
  if ( v5 )
  {
    v6 = v5->m_uRefCount-- == 1;
    if ( v6 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::VehicleAudioParameters::sm_Map,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v5);
      UFG::VehicleAudioParameters::~VehicleAudioParameters(v5);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, v5);
    }
  }
  v7 = v1->m_damageModel;
  if ( v7 )
  {
    UFG::DamageModel::~DamageModel(v1->m_damageModel);
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v7);
    v1->m_damageModel = 0i64;
  }
  v8 = v1->m_ecSiren.m_pEvent;
  if ( v8 )
    UFG::AudioEvent::OnControllerDestroy(v8);
  v9 = v1->m_ecHorn.m_pEvent;
  if ( v9 )
    UFG::AudioEvent::OnControllerDestroy(v9);
  v10 = v1->m_ecRoadNoise.m_pEvent;
  if ( v10 )
    UFG::AudioEvent::OnControllerDestroy(v10);
  v11 = &v1->m_transformNode;
  if ( v1->m_transformNode.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->m_transformNode.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->m_transformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_transformNode.mPrev;
  }
  v1->m_transformNode.m_pPointer = 0i64;
  v14 = v11->mPrev;
  v15 = v1->m_transformNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v1->m_transformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_transformNode.mPrev;
  v16 = &v1->m_physicsMoverInterface;
  if ( v1->m_physicsMoverInterface.m_pPointer )
  {
    v17 = v16->mPrev;
    v18 = v1->m_physicsMoverInterface.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v1->m_physicsMoverInterface.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_physicsMoverInterface.mPrev;
  }
  v1->m_physicsMoverInterface.m_pPointer = 0i64;
  v19 = v16->mPrev;
  v20 = v1->m_physicsMoverInterface.mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  v1->m_physicsMoverInterface.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_physicsMoverInterface.mPrev;
  _((AMD_HD3D *)v1->m_commonBank.mUID);
  _((AMD_HD3D *)v1->m_driverTypeBank.mUID);
  _((AMD_HD3D *)v1->m_vehicleBank.mUID);
  v21 = v2->mPrev;
  v22 = v2->mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HkAudioEntityComponent::~HkAudioEntityComponent((UFG::HkAudioEntityComponent *)&v1->vfptr);
}

// File Line: 446
// RVA: 0x68C810
void UFG::VehicleAudioComponent::StaticInit(void)
{
  UFG::qPropertySet *v0; // rbx

  v0 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&VehAudSymX_propset_vehicleconfig.mUID);
  if ( audio_vehicleaudiocomponent::IsClass(v0->mSchemaName.mUID) )
    UFG::VehicleAudioComponent::sm_configPs = (audio_vehicleaudiocomponent *)UFG::qPropertySet::GetMemImagePtr(v0);
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
  UFG::SimObject *v1; // rcx
  UFG::SimComponent *v2; // rdi
  UFG::SimObject *v3; // rax
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::SimObject *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v0 = 0i64;
  v1 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v1 )
    v2 = UFG::SimObject::GetComponentOfType(v1, UFG::FollowCameraComponent::_TypeUID);
  else
    v2 = 0i64;
  if ( v2 )
  {
    if ( ((__int64 (__fastcall *)(UFG::SimComponent *))v2->vfptr[17].__vecDelDtor)(v2) )
    {
      if ( ((__int64 (__fastcall *)(UFG::SimComponent *))v2->vfptr[17].__vecDelDtor)(v2) )
      {
        v3 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v2->vfptr[17].__vecDelDtor)(v2);
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                  v3,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
        if ( v4 )
        {
          v5 = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
          if ( v5 )
          {
            v6 = UFG::SimObject::GetComponentOfType(v5, UFG::VehicleAudioComponent::_TypeUID);
            v0 = v6;
            if ( v6 )
              BYTE1(v6[5].m_pSimObject) = 0;
          }
        }
      }
    }
  }
  v7 = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer;
  if ( UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer )
  {
    if ( UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer != v0 )
    {
      BYTE1(UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[5].m_pSimObject) = 1;
      v7 = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer;
    }
    if ( v7 )
    {
      v8 = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev;
      v9 = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext;
      UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev->mNext = UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext;
      v9->mPrev = v8;
      UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
      UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
    }
  }
  UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer = v0;
  if ( v0 )
  {
    v10 = v0->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
    UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mPrev = v10;
    UFG::VehicleAudioComponent::sm_vehicleFollowTarget.mNext = &v0->m_SafePointerList.mNode;
    v0->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget;
  }
}

// File Line: 504
// RVA: 0x6881E0
UFG::SimComponent *__fastcall UFG::VehicleAudioComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rdx
  unsigned __int16 v12; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_VehicleAudio::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x280ui64, "VehicleAudioComponent", 0i64, 1u);
  if ( v9 )
  {
    UFG::VehicleAudioComponent::VehicleAudioComponent(
      (UFG::VehicleAudioComponent *)v9,
      v3,
      (component_VehicleAudio *)v7);
    v6 = v10;
  }
  v11 = v3->m_pSimObject;
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 || (v12 & 0x8000u) == 0 )
    v13 = -1;
  else
    v13 = 28;
  UFG::SimObjectModifier::SimObjectModifier(&v14, v11, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v6;
}

// File Line: 544
// RVA: 0x67F670
void __fastcall UFG::VehicleAudioComponent::KillOffensiveSoundsForNIS(hkgpIndexedMesh::EdgeBarrier *a1, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v2; // rbx
  UFG::AudioEvent *v3; // rcx

  v2 = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext - 24;
  for ( UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext[-24];
        v2 != (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)(&UFG::VehicleAudioComponent::s_VehicleAudioComponentList
                                                                                  - 24);
        UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)v2 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(a1, a2) )
    {
      v3 = (UFG::AudioEvent *)v2[37].mPrev;
      if ( v3 )
        UFG::AudioEvent::StopAndForget(v3, 0);
      BYTE6(v2[39].mNext) &= 0xFCu;
    }
    a1 = (hkgpIndexedMesh::EdgeBarrier *)v2[35].mPrev;
    if ( a1 )
    {
      if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled )
      {
        a1 = (hkgpIndexedMesh::EdgeBarrier *)a1[1].vfptr;
        if ( a1 )
          UFG::AudioEvent::StopAndForget((UFG::AudioEvent *)a1, 0xC8u);
      }
    }
    v2 = UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator->mNext - 24;
  }
  UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = 0i64;
}

// File Line: 614
// RVA: 0x683520
void __fastcall UFG::VehicleAudioComponent::OnAttach(UFG::VehicleAudioComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rsi
  UFG::VehicleAudioComponent *v3; // rbx
  UFG::TransformNodeComponent *v4; // rdi
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1
  UFG::qVector4 v7; // xmm0
  float *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::allocator::free_link *v11; // rax
  char v12; // dl
  hkgpIndexedMeshDefinitions::Edge *v13; // rdx
  hkgpIndexedMesh::EdgeBarrier *v14; // rcx

  v2 = object;
  v3 = this;
  if ( object )
    v4 = object->m_pTransformNodeComponent;
  else
    v4 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v5 = v4->mWorldTransform.v1;
  v6 = v4->mWorldTransform.v2;
  v7 = v4->mWorldTransform.v3;
  v3->m_WorldMatrix.v0 = v4->mWorldTransform.v0;
  v3->m_WorldMatrix.v1 = v5;
  v3->m_WorldMatrix.v2 = v6;
  v3->m_WorldMatrix.v3 = v7;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v8 = &v3->m_pMotionData->m_vLastPosition.x;
  if ( v8 )
  {
    v9 = v4->mWorldTransform.v3.y;
    v10 = v4->mWorldTransform.v3.z;
    *v8 = v4->mWorldTransform.v3.x;
    v8[1] = v9;
    v8[2] = v10;
  }
  v3->m_driverReaction = 0i64;
  v11 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x10ui64, "VehicleAudioComponent.DriverReactions", 0i64, 1u);
  if ( v11 )
  {
    v11[1].mNext = 0i64;
    v12 = UFG::DriverReactions::sm_tweakablesLoaded;
    if ( !UFG::DriverReactions::sm_tweakablesLoaded )
      v12 = 1;
    UFG::DriverReactions::sm_tweakablesLoaded = v12;
    v11->mNext = (UFG::allocator::free_link *)v3;
  }
  v3->m_driverReaction = (UFG::DriverReactions *)v11;
  v3->m_ambientHornId = UFG::qRandom(7, &UFG::qDefaultSeed);
  v3->m_pSubTypeParameters = UFG::VehicleAudioComponent::FindSubTypeParameters(v3);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v14, v13) )
  {
    UFG::AudioEntity::Init((UFG::AudioEntity *)&v3->vfptr, &v2->m_Name, &UFG::qMatrix44::msIdentity);
    UFG::VehicleAudioComponent::sm_numCarsActive = UFG::VehicleAudioComponent::sm_numCarsActive + 1.0;
  }
}

// File Line: 646
// RVA: 0x684200
void __fastcall UFG::VehicleAudioComponent::OnDetach(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx
  UFG::RadioFullyControlled *v2; // rcx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx

  v1 = this;
  v2 = this->m_radio;
  if ( v2 )
    ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD))v2->vfptr[1].StopAndForgetAllEvents)(v2, 0i64);
  ((void (__fastcall *)(UFG::VehicleAudioComponent *))v1->vfptr[16].__vecDelDtor)(v1);
  UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v1->vfptr);
  UFG::VehicleAudioComponent::UnloadSoundbanks(v1);
  v4 = (hkgpIndexedMeshDefinitions::Edge *)v1->m_driverReaction;
  if ( v4 )
  {
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v4);
    v1->m_driverReaction = 0i64;
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v4) )
    UFG::VehicleAudioComponent::sm_numCarsActive = UFG::VehicleAudioComponent::sm_numCarsActive + -1.0;
}

// File Line: 674
// RVA: 0x682520
void __fastcall UFG::VehicleAudioComponent::OnActionDefStartHorn(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx
  UFG::qPropertySet *v2; // rdi
  char *v3; // rax
  char v4; // al
  float v5; // xmm0_4

  v1 = this;
  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    v2 = this->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v2->mSchemaName.mUID) )
      v3 = UFG::qPropertySet::GetMemImagePtr(v2);
    else
      v3 = 0i64;
    if ( *((_DWORD *)v3 + 62) )
    {
      v4 = *((_BYTE *)v1 + 0x27E);
      if ( !(v4 & 8) )
      {
        v5 = UFG::Metrics::msInstance.mSimTimeDelta + v1->m_hornAccum;
        v1->m_hornAccum = v5;
        if ( v5 > 0.2 )
          *((_BYTE *)v1 + 0x27E) = v4 | 6;
      }
    }
    else
    {
      *((_BYTE *)v1 + 0x27E) |= 6u;
    }
  }
}

// File Line: 700
// RVA: 0x6825C0
void __fastcall UFG::VehicleAudioComponent::OnActionDefStopHorn(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx
  UFG::qPropertySet *v2; // rdi
  char *v3; // rax
  unsigned __int8 v4; // dl

  v1 = this;
  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    v2 = this->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v2->mSchemaName.mUID) )
      v3 = UFG::qPropertySet::GetMemImagePtr(v2);
    else
      v3 = 0i64;
    if ( *((_DWORD *)v3 + 62) )
    {
      v4 = *((_BYTE *)v1 + 0x27E);
      if ( v4 & 1 )
      {
        v1->m_hornAccum = 0.0;
        *((_BYTE *)v1 + 638) = v4 & 0xFD | 4;
      }
      else if ( !(((v4 >> 4) ^ (v4 >> 3)) & 1) )
      {
        *((_BYTE *)v1 + 638) = v4 ^ (v4 ^ 16 * ~(v4 >> 4)) & 0x10;
      }
    }
    else
    {
      *((_BYTE *)v1 + 638) &= 0xFDu;
      *((_BYTE *)v1 + 638) |= 4u;
    }
  }
}

// File Line: 743
// RVA: 0x6848E0
void __fastcall UFG::VehicleAudioComponent::OnDriverComponentParked(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::EnvironmentalModel *v2; // rax
  UFG::VehicleAudioComponent *v3; // rbx
  char v4; // al

  v2 = this->m_envModel;
  v3 = this;
  if ( v2 )
  {
    this = (UFG::VehicleAudioComponent *)v2->m_ecForceStopSkid.m_pEvent;
    if ( this )
      UFG::AudioEvent::StopAndForget((UFG::AudioEvent *)this, 0);
  }
  if ( *((_BYTE *)v3 + 638) & 0x40 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            a2) )
    {
      v4 = *((_BYTE *)v3 + 636);
      if ( v4 & 2 )
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
void __fastcall UFG::VehicleAudioComponent::OnDriverComponentUncontrolled(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  __int64 v3; // rdx
  UFG::RadioFullyControlled *v4; // rcx

  v2 = this;
  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized && this->m_eDriverType == eDriverType_Player )
    UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_GetOutOfVehicle, 1, 0i64);
  if ( v2->m_radio && *((_BYTE *)v2 + 638) & 0x40 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)this,
            a2) )
    {
      v4 = v2->m_radio;
      if ( v4 )
      {
        LOBYTE(v3) = v2->m_eDriverType == 0;
        ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))v4->vfptr[1].CountNumPlayingEvents)(v4, v3);
      }
      *((_BYTE *)v2 + 636) &= 0xDFu;
    }
    UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = 0i64;
    v2->m_radio = 0i64;
  }
  UFG::VehicleAudioComponent::SetDriverType(v2, eDriverType_GhostRider);
}

// File Line: 803
// RVA: 0x68A700
void __fastcall UFG::VehicleAudioComponent::SetDriverType(UFG::VehicleAudioComponent *this, UFG::VehicleAudioComponent::eDriverType driverType)
{
  UFG::VehicleAudioComponent::eDriverType v2; // ebx
  UFG::VehicleAudioComponent *v3; // rdi
  UFG::VehicleAudioComponent::eDriverType v4; // eax
  UFG::VehicleAudioSubTypeParameters *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *v7; // rsi
  char *v8; // rax
  __int64 v9; // rcx
  UFG::qPropertyList *v10; // r13
  unsigned int v11; // er15
  char v12; // r14
  unsigned int v13; // ebp
  char *v14; // rax
  UFG::qPropertySet *v15; // rbx
  char *v16; // rax
  unsigned int v17; // eax
  char *v18; // rax
  UFG::TiDo *v19; // rax
  UFG::TiDo *v20; // rax
  UFG::qWiseSymbol bankId; // [rsp+68h] [rbp+10h]

  v2 = driverType;
  v3 = this;
  v4 = this->m_eDriverType;
  if ( driverType != v4 )
  {
    this->m_eLastDriverType = v4;
    this->m_eDriverType = driverType;
    v5 = UFG::VehicleAudioComponent::FindSubTypeParameters(this);
    v3->m_pSubTypeParameters = v5;
    if ( v5 )
    {
      v3->m_rateLimitedSpeed.m_currentValue = v5->m_rateLimitedSpeed.m_currentValue;
      v3->m_rateLimitedSpeed.m_targetValue = v5->m_rateLimitedSpeed.m_targetValue;
      v3->m_rateLimitedSpeed.m_riseRate = v5->m_rateLimitedSpeed.m_riseRate;
      v3->m_rateLimitedSpeed.m_fallRate = v5->m_rateLimitedSpeed.m_fallRate;
      v3->m_rateLimitedSpeed.m_max = v5->m_rateLimitedSpeed.m_max;
      v3->m_rateLimitedSpeed.m_min = v5->m_rateLimitedSpeed.m_min;
      v3->m_pEnginePropertySet = v5->mpPropertySet;
    }
    if ( v2 == 1 )
    {
      v3->m_pEnginePropertySet = v3->m_pTypeParameters->m_playerParameters.mpPropertySet;
    }
    else if ( v2 - 3 <= 1 )
    {
      v6 = v5->mpPropertySet;
      v7 = 0i64;
      v8 = Vehicles_Audio_Base_BaseVehicleBase::IsClass(v6->mSchemaName.mUID) ? UFG::qPropertySet::GetMemImagePtr(v6) : 0i64;
      v9 = *((_QWORD *)v8 + 30);
      if ( v9 )
      {
        v10 = (UFG::qPropertyList *)&v8[v9 + 240];
        if ( v10 )
        {
          v11 = v10->mNumElements;
          if ( v11 )
          {
            v12 = 0;
            v13 = 0;
            while ( v13 < v11 )
            {
              v14 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v13);
              if ( !v14 || (v15 = (UFG::qPropertySet *)&v14[*(_QWORD *)v14], !*(_QWORD *)v14) )
                v15 = 0i64;
              if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v15->mSchemaName.mUID) )
                v16 = UFG::qPropertySet::GetMemImagePtr(v15);
              else
                v16 = 0i64;
              bankId.mUID = *((_DWORD *)v16 + 1);
              _((AMD_HD3D *)bankId.mUID);
              if ( bankId.mUID != UFG::qWiseSymbol::get_null()->mUID
                && !UFG::SoundBankManager::BankLoadRequested(&bankId) )
              {
                v3->m_pEnginePropertySet = v15;
                v12 = 1;
              }
              ++v13;
              _((AMD_HD3D *)bankId.mUID);
              if ( v12 )
                goto LABEL_31;
            }
            if ( !v12 )
            {
              v17 = UFG::qRandom(v11, &UFG::qDefaultSeed);
              v18 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v17);
              if ( v18 && *(_QWORD *)v18 )
                v7 = (UFG::qPropertySet *)&v18[*(_QWORD *)v18];
              v3->m_pEnginePropertySet = v7;
            }
          }
        }
      }
    }
LABEL_31:
    if ( !(_S7_16 & 1) )
    {
      _S7_16 |= 1u;
      UFG::qWiseSymbol::create_from_string(&amb_traffic, "amb_traffic_d");
      atexit(UFG::VehicleAudioComponent::SetDriverType_::_31_::_dynamic_atexit_destructor_for__amb_traffic__);
    }
    if ( v3->m_eLastDriverType > 1 )
      goto LABEL_42;
    if ( v3->m_eDriverType > 1 && !--UFG::VehicleAudioComponent::sm_numPlayerDrivers )
    {
      v19 = UFG::TiDo::GetInstance();
      UFG::AudioEntity::SetWwiseState(v19, ms_vehicle.mUID, on_foot.mUID);
      UFG::TidoGame::StartDistantTraffic((UFG::TidoGame *)UFG::TiDo::m_pInstance);
    }
    if ( v3->m_eLastDriverType > 1 )
    {
LABEL_42:
      if ( v3->m_eDriverType <= 1 )
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
signed __int64 __fastcall UFG::VehicleAudioComponent::FindPlayerIndexInVehicleOccupantComponent(UFG::VehicleAudioComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::VehicleOccupantComponent *v2; // rdi
  UFG::SimObjectCharacter *v3; // rsi
  signed int v4; // ebx
  unsigned int v5; // er11
  UFG::SimObjectCharacter *v6; // rax
  signed __int64 v7; // r8
  int v8; // er9
  signed __int64 v9; // rax
  int v10; // edx
  signed __int64 v11; // rcx
  signed __int64 v12; // r8
  int v13; // edx
  signed __int64 v14; // rcx
  int v15; // ecx

  v1 = this->m_pSimObject;
  if ( v1 )
    v2 = (UFG::VehicleOccupantComponent *)v1->m_Components.p[30].m_pComponent;
  else
    v2 = 0i64;
  v3 = LocalPlayer;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  if ( !LocalPlayer )
    return 0xFFFFFFFFi64;
  v4 = 0;
  v5 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v2);
  if ( !v5 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    if ( v2->mpDriver.m_pPointer )
    {
      if ( !v4 )
      {
        v6 = (UFG::SimObjectCharacter *)v2->mpDriver.m_pPointer;
        goto LABEL_25;
      }
      v7 = (signed __int64)&v2->m_BoundComponentHandles;
      v8 = 0;
      v9 = (signed __int64)&v2->mPassengers.mNode.mNext[-4];
      v10 = v4 - 1;
      v11 = v9;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != &v2->m_BoundComponentHandles )
      {
        do
        {
          ++v8;
          v11 = *(_QWORD *)(v11 + 72) - 64i64;
        }
        while ( v11 != v7 );
      }
      if ( v10 < v8 )
      {
        for ( ; v10 > 0; v9 = *(_QWORD *)(v9 + 72) - 64i64 )
        {
          if ( v9 == v7 )
            break;
          --v10;
        }
LABEL_16:
        v6 = *(UFG::SimObjectCharacter **)(v9 + 40);
        goto LABEL_25;
      }
    }
    else
    {
      v12 = (signed __int64)&v2->m_BoundComponentHandles;
      v13 = 0;
      v9 = (signed __int64)&v2->mPassengers.mNode.mNext[-4];
      v14 = v9;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != &v2->m_BoundComponentHandles )
      {
        do
        {
          ++v13;
          v14 = *(_QWORD *)(v14 + 72) - 64i64;
        }
        while ( v14 != v12 );
      }
      if ( v4 < v13 )
      {
        v15 = v4;
        if ( v4 > 0 )
        {
          while ( v9 != v12 )
          {
            --v15;
            v9 = *(_QWORD *)(v9 + 72) - 64i64;
            if ( v15 <= 0 )
            {
              v6 = *(UFG::SimObjectCharacter **)(v9 + 40);
              goto LABEL_25;
            }
          }
        }
        goto LABEL_16;
      }
    }
    v6 = 0i64;
LABEL_25:
    if ( v6 == v3 )
      return (unsigned int)v4;
    if ( ++v4 >= v5 )
      return 0xFFFFFFFFi64;
  }
}

// File Line: 925
// RVA: 0x678970
signed __int64 __fastcall UFG::VehicleAudioComponent::FindDriverType(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx
  signed __int64 result; // rax
  int v3; // eax
  UFG::SimObjectCVBase *v4; // rcx
  UFG::AiDriverComponent *v5; // rdi
  UFG::SimObjectCVBase *v6; // rcx
  UFG::SimComponent *v7; // rsi
  UFG::SimObjectCVBase *v8; // rcx
  UFG::RemoteDriverComponent *v9; // rax
  char v10; // al
  unsigned int v11; // ecx
  unsigned int v12; // eax

  v1 = this;
  if ( this->m_bOverrideDriverType )
    return this->m_eOverridenDriverType;
  if ( this->m_eDriverType == 7 )
    return 7i64;
  v3 = UFG::VehicleAudioComponent::FindPlayerIndexInVehicleOccupantComponent(this);
  if ( !v3 )
  {
    UFG::VehicleAudioComponent::FindPlayerIndexInVehicleOccupantComponent(v1);
    return 0i64;
  }
  if ( v3 > 0 )
    return 1i64;
  v4 = (UFG::SimObjectCVBase *)v1->m_pSimObject;
  if ( v4 )
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
  else
    v5 = 0i64;
  v6 = (UFG::SimObjectCVBase *)v1->m_pSimObject;
  if ( v6 )
    v7 = v6->m_Components.p[17].m_pComponent;
  else
    v7 = 0i64;
  if ( v6 )
    UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v6);
  v8 = (UFG::SimObjectCVBase *)v1->m_pSimObject;
  if ( v8 && (v9 = UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(v8)) != 0i64 )
  {
    v10 = ((__int64 (__fastcall *)(UFG::RemoteDriverComponent *))v9->vfptr[15].__vecDelDtor)(v9);
    v11 = 2;
    if ( v10 )
      v11 = 0;
    result = v11;
  }
  else
  {
    if ( v5 )
    {
      if ( v7 )
        return 5i64;
      v12 = v5->m_DrivingRole;
      if ( v12 == 1 )
        return 3i64;
      if ( v12 == 2 || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v5->vfptr[16].__vecDelDtor)(v5) )
        return 4i64;
      if ( !v5->m_DrivingRole || UFG::AiDriverComponent::IsTransit(v5) || UFG::AiDriverComponent::IsBoat(v5) )
        return 2i64;
    }
    result = 0xFFFFFFFFi64;
    if ( v1->m_eDriverType == 6 )
      result = 6i64;
  }
  return result;
}

// File Line: 994
// RVA: 0x67F600
bool __fastcall UFG::VehicleAudioComponent::KeepAliveTest(UFG::VehicleAudioComponent *this, UFG::VehicleAudioComponent::eDriverType desiredDriverType, float distance2ToListener)
{
  UFG::VehicleAudioComponent::eDriverType v3; // ebx
  UFG::VehicleAudioComponent *v4; // rdi

  v3 = desiredDriverType;
  v4 = this;
  return ((unsigned int)desiredDriverType <= 1
       || (UFG::VehicleAudioComponent::HasDriver(this) || v4->m_bOverrideDriverType) && v3 - 3 <= 2
       || v3 == 2)
      && UFG::VehicleAudioComponent::IsDriverTypeWithinCutoffRange(v4, v3, distance2ToListener);
}

// File Line: 1007
// RVA: 0x693F90
void __usercall UFG::VehicleAudioComponent::Update(UFG::VehicleAudioComponent *this@<rcx>, float delta_sec@<xmm1>, hkgpIndexedMeshDefinitions::Edge *a3@<rdx>)
{
  float v3; // xmm6_4
  UFG::VehicleAudioComponent *v4; // rsi
  UFG::VehicleAudioComponent::eDriverType v5; // ebp
  UFG::SimObject *v6; // rdx
  UFG::SimComponent *v7; // r14
  char v8; // bl
  char v9; // di
  char v10; // al
  char v11; // al
  __int64 v12; // rdx
  __int64 v13; // rdx
  char v14; // al
  char v15; // al
  char v16; // al
  UFG::Radio *v17; // rax
  hkgpIndexedMesh::EdgeBarrier *v18; // rcx
  UFG::RadioFullyControlled *v19; // rcx
  UFG::TiDo *v20; // rax
  UFG::Audio3DListener *v21; // rbx
  __int128 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 v24; // xmm0
  UFG::allocator::free_link *v25; // rax
  UFG::DamageModel *v26; // rbx
  char v27; // al
  float v28; // xmm6_4

  v3 = delta_sec;
  v4 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a3) )
  {
    v5 = (unsigned int)UFG::VehicleAudioComponent::FindDriverType(v4);
    if ( v5 == eDriverType_Player )
      *((_BYTE *)v4 + 0x27C) |= 4u;
    v6 = v4->m_pSimObject;
    if ( v6 )
      v7 = v6->m_Components.p[2].m_pComponent;
    else
      v7 = 0i64;
    if ( !(*((_BYTE *)v4 + 636) & 4) )
      goto LABEL_93;
    if ( v7
      && (UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated > UFG::VehicleAudioComponent::sm_minTimeBetweenActivations
       || v5 == eDriverType_Player) )
    {
      if ( v4->m_bIsInitialized && v4->m_bVehicleIsInitialized )
      {
        if ( v5 != v4->m_eDriverType )
        {
          UFG::VehicleAudioComponent::FindDriverType(v4);
          if ( v4->m_eDriverType != 6 || v4->m_eLastDriverType || v5 )
          {
            if ( UFG::VehicleAudioComponent::KeepAliveTest(v4, v5, v4->m_fDistance2ToListener) )
            {
              v8 = (*((_BYTE *)v4 + 638) >> 4) & 1;
              v9 = (*((_BYTE *)v4 + 636) >> 1) & 1;
              ((void (__fastcall *)(UFG::VehicleAudioComponent *))v4->vfptr[16].__vecDelDtor)(v4);
              v4->vfptr[15].__vecDelDtor(
                (UFG::qSafePointerNode<UFG::SimComponent> *)v4,
                (unsigned int)&v4->m_pSimObject->m_Name);
              *((_BYTE *)v4 + 638) ^= (*((_BYTE *)v4 + 638) ^ 16 * v8) & 0x10;
              *((_BYTE *)v4 + 636) &= 0xFDu;
              *((_BYTE *)v4 + 636) |= 2 * (v9 & 1);
              UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated = 0.0;
              *((_BYTE *)v4 + 636) |= 4u;
            }
            else if ( v5 == 6 && !(*((_BYTE *)v4 + 638) & 0x40) )
            {
              *((_BYTE *)v4 + 636) |= 4u;
            }
          }
          else
          {
            UFG::VehicleAudioComponent::SetDriverType(v4, 0);
            *((_BYTE *)v4 + 636) |= 4u;
          }
        }
      }
      else if ( v5 != -1 )
      {
        v4->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)v4, (unsigned int)&v6->m_Name);
        UFG::VehicleAudioComponent::sm_timeSinceVehicleActivated = 0.0;
      }
    }
    if ( !(*((_BYTE *)v4 + 636) & 4) || !((v5 + 1) & 0xFFFFFFF7) )
    {
LABEL_93:
      ((void (__fastcall *)(UFG::VehicleAudioComponent *))v4->vfptr[16].__vecDelDtor)(v4);
      if ( v5 == 7 )
        UFG::VehicleAudioComponent::SetDriverType(v4, eDriverType_Disabled);
      if ( *((_BYTE *)v4 + 638) & 0x20 && !((unsigned int (*)(void))v4->vfptr->CountNumPlayingEvents)() )
        UFG::VehicleAudioComponent::UnloadSoundbanks(v4);
    }
    if ( v4->m_bIsInitialized )
    {
      if ( v4->m_bVehicleIsInitialized )
      {
        v10 = *((_BYTE *)v4 + 636);
        if ( v10 & 2 )
        {
          if ( !(v10 & 1)
            && (UFG::SoundBankManager::BankLoadRequestFinished(&v4->m_vehicleBank)
             || v4->m_vehicleBank.mUID == UFG::qWiseSymbol::get_null()->mUID) )
          {
            v4->m_engineModel->m_engineStateMachine->m_event = 1;
            *((_BYTE *)v4 + 636) |= 1u;
          }
        }
      }
    }
    v11 = *((_BYTE *)v4 + 636);
    if ( !(v11 & 2) && v11 & 1 )
    {
      v4->m_engineModel->m_engineStateMachine->m_event = 2;
      UFG::VehicleAudioComponent::TurnOffRadio(v4, (hkgpIndexedMeshDefinitions::Edge *)v6);
      *((_BYTE *)v4 + 636) &= 0xFEu;
    }
    if ( v4->m_bIsInitialized )
    {
      if ( v4->m_bVehicleIsInitialized )
      {
        v12 = *((unsigned __int8 *)v4 + 0x27E);
        if ( v12 & 2 )
        {
          if ( !(v12 & 1) )
          {
            LOBYTE(v12) = ((unsigned __int8)v12 >> 2) & 1;
            UFG::VehicleAudioComponent::DoStartHorn(v4, v12);
          }
        }
      }
    }
    v13 = *((unsigned __int8 *)v4 + 638);
    if ( !(v13 & 2) && v13 & 1 )
    {
      LOBYTE(v13) = ((unsigned __int8)v13 >> 2) & 1;
      UFG::VehicleAudioComponent::DoStopHorn(v4, v13);
    }
    if ( v4->m_bIsInitialized )
    {
      if ( v4->m_bVehicleIsInitialized )
      {
        v14 = *((_BYTE *)v4 + 0x27E);
        if ( v14 & 0x10 )
        {
          if ( !(v14 & 8) )
            UFG::VehicleAudioComponent::DoStartSiren(v4, 0i64);
        }
      }
      if ( v4->m_bIsInitialized )
      {
        if ( v4->m_bVehicleIsInitialized )
        {
          v15 = *((_BYTE *)v4 + 638);
          if ( v15 & 0x10 )
          {
            if ( v15 & 8 && !v4->m_ecSiren.m_pEvent )
              UFG::VehicleAudioComponent::DoStartSiren(v4, 0i64);
          }
        }
      }
    }
    v16 = *((_BYTE *)v4 + 638);
    if ( !(v16 & 0x10) && v16 & 8 )
      UFG::VehicleAudioComponent::DoStopSiren(v4, 0i64);
    if ( v4->m_bIsInitialized )
    {
      if ( v4->m_bVehicleIsInitialized )
      {
        v17 = (UFG::Radio *)&v4->m_radio->vfptr;
        if ( v17 )
        {
          v18 = (hkgpIndexedMesh::EdgeBarrier *)*((unsigned __int8 *)v4 + 0x27C);
          if ( (unsigned __int8)v18 & 0x20 )
          {
            if ( (unsigned __int8)v18 & 1 )
            {
              if ( *((_BYTE *)v17 + 0x158) & 4 )
              {
                if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
                        v18,
                        (hkgpIndexedMeshDefinitions::Edge *)v13) )
                {
                  v19 = v4->m_radio;
                  if ( v19 )
                  {
                    if ( *((_BYTE *)&v19->0 + 344) & 4 )
                      ((void (*)(void))v19->vfptr[1].AudioEntityUpdate)();
                  }
                }
              }
            }
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
    v20 = UFG::TiDo::GetInstance();
    v21 = UFG::TiDo::GetListener(v20, 0);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
    v22 = *(_OWORD *)&v7[2].m_SafePointerList.mNode.mNext;
    v23 = *(UFG::qVector4 *)&v7[2].m_Flags;
    v24 = (UFG::qVector4)v7[2].m_BoundComponentHandles;
    v4->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v7[2].vfptr;
    v4->m_WorldMatrix.v1 = (UFG::qVector4)v22;
    v4->m_WorldMatrix.v2 = v23;
    v4->m_WorldMatrix.v3 = v24;
    *(float *)&v22 = (float)((float)((float)(v21->m_matrix.v3.y - v4->m_WorldMatrix.v3.y)
                                   * (float)(v21->m_matrix.v3.y - v4->m_WorldMatrix.v3.y))
                           + (float)((float)(v21->m_matrix.v3.x - v4->m_WorldMatrix.v3.x)
                                   * (float)(v21->m_matrix.v3.x - v4->m_WorldMatrix.v3.x)))
                   + (float)((float)(v21->m_matrix.v3.z - v4->m_WorldMatrix.v3.z)
                           * (float)(v21->m_matrix.v3.z - v4->m_WorldMatrix.v3.z));
    LODWORD(v4->m_fDistance2ToListener) = v22;
    if ( *(float *)&v22 >= 2500.0 )
    {
      v26 = v4->m_damageModel;
      if ( v26 )
      {
        UFG::DamageModel::~DamageModel(v4->m_damageModel);
        UFG::qMemoryPool::Free(&g_AudioComponentPool, v26);
        v4->m_damageModel = 0i64;
      }
    }
    else
    {
      if ( !v4->m_damageModel )
      {
        v25 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "VehicleAudioComponent.DamageModel", 0i64, 1u);
        if ( v25 )
          UFG::DamageModel::DamageModel((UFG::DamageModel *)v25, v4);
        v4->m_damageModel = (UFG::DamageModel *)v25;
      }
      UFG::VehicleAudioComponent::sm_numCarsNearby = UFG::VehicleAudioComponent::sm_numCarsNearby + 1.0;
    }
    if ( UFG::VehicleAudioComponent::KeepAliveTest(v4, v5, v4->m_fDistance2ToListener) )
    {
      *((_BYTE *)v4 + 636) |= 4u;
    }
    else if ( v5 == 6 )
    {
      *((_BYTE *)v4 + 636) |= 4u;
      v27 = *((_BYTE *)v4 + 636);
      v28 = v3 + v4->m_ghostRiderTime;
      v4->m_ghostRiderTime = v28;
      if ( v28 > gGhostRiderTimeMax )
      {
        if ( *((_BYTE *)v4 + 638) & 0x40 )
        {
          *((_BYTE *)v4 + 636) = v27 & 0xFB;
          v4->m_ghostRiderTime = 0.0;
        }
      }
    }
    else
    {
      *((_BYTE *)v4 + 636) &= 0xFBu;
    }
  }
}

// File Line: 1301
// RVA: 0x678C60
UFG::VehicleAudioSubTypeParameters *__fastcall UFG::VehicleAudioComponent::FindSubTypeParameters(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioParameters *v1; // rax
  UFG::VehicleAudioSubTypeParameters *result; // rax

  switch ( this->m_eDriverType + 1 )
  {
    case 0u:
    case 3u:
      goto $LN3_64;
    case 1u:
    case 7u:
      if ( UFG::gDebugPlayerCarsUseTrafficData )
      {
$LN3_64:
        result = &this->m_pTypeParameters->m_trafficParameters;
      }
      else
      {
        v1 = this->m_pTypeParameters;
        if ( UFG::gDebugPlayerCarsUseAiData )
LABEL_6:
          result = &v1->m_aiParameters;
        else
          result = &v1->m_playerParameters;
      }
      break;
    case 2u:
    case 4u:
    case 5u:
    case 6u:
      v1 = this->m_pTypeParameters;
      goto LABEL_6;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 1367
// RVA: 0x67D4B0
void __fastcall UFG::VehicleAudioComponent::Init(UFG::VehicleAudioComponent *this, UFG::qSymbol *objectName)
{
  UFG::qSymbol *v2; // rbp
  UFG::VehicleAudioComponent *v3; // rdi
  UFG::SimObject *v4; // rax
  UFG::SimComponent *v5; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsMoverInterface> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SimComponent *v11; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::VehicleAudioComponent::eDriverType v16; // eax
  UFG::qWiseSymbol *v17; // rsi
  UFG::qPropertySet *v18; // rbx
  char *v19; // rax
  unsigned int v20; // eax
  UFG::SimObjectCVBase *v21; // rcx
  UFG::AiDriverComponent *v22; // rax
  UFG::qWiseSymbol *v23; // rsi
  unsigned __int16 v24; // dx
  UFG::ActorAudioComponent *v25; // rax
  UFG::AudioEntity *v26; // rcx
  UFG::allocator::free_link *v27; // rax
  unsigned int v28; // ebx
  UFG::allocator::free_link *v29; // rax
  UFG::VehicleAudioComponent::eDriverType v30; // eax
  UFG::RadioFullyControlled *v31; // rax
  signed __int64 v32; // rdx
  UFG::RadioFullyControlled *v33; // rcx
  UFG::qPropertySet *v34; // rbx
  char *v35; // rax
  float v36; // xmm1_4
  unsigned int v37; // edx
  UFG::VehicleAudioComponent::ScrapeImpactEntity *v38; // rax
  UFG::AudioEntityVtbl *v39; // rbx
  UFG::qSymbol *v40; // rax
  UFG::qWiseSymbol bankId; // [rsp+60h] [rbp+8h]
  void *result; // [rsp+70h] [rbp+18h]

  v2 = objectName;
  v3 = this;
  if ( !this->m_bIsInitialized || !this->m_bVehicleIsInitialized )
  {
    v4 = this->m_pSimObject;
    if ( v4 )
      v5 = v4->m_Components.p[34].m_pComponent;
    else
      v5 = 0i64;
    v6 = &this->m_physicsMoverInterface;
    if ( this->m_physicsMoverInterface.m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v6->m_pPointer = v5;
    if ( v5 )
    {
      v9 = v5->m_SafePointerList.mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v9;
      v6->mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v10 = v3->m_pSimObject;
    if ( v10 )
      v11 = v10->m_Components.p[2].m_pComponent;
    else
      v11 = 0i64;
    v12 = &v3->m_transformNode;
    if ( v3->m_transformNode.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v3->m_transformNode.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v3->m_transformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_transformNode.mPrev;
    }
    v3->m_transformNode.m_pPointer = v11;
    if ( v11 )
    {
      v15 = v11->m_SafePointerList.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v12->mPrev = v15;
      v3->m_transformNode.mNext = &v11->m_SafePointerList.mNode;
      v11->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    }
    v16 = (unsigned int)UFG::VehicleAudioComponent::FindDriverType(v3);
    if ( v16 == -1 )
      v16 = (unsigned int)UFG::VehicleAudioComponent::FindDriverType(v3);
    UFG::VehicleAudioComponent::SetDriverType(v3, v16);
    if ( v3->m_eDriverType == -1 )
      v17 = UFG::qWiseSymbol::get_null();
    else
      v17 = &veh_common_all;
    UFG::SoundBankManager::QueueBankForUnload(&v3->m_commonBank);
    UFG::SoundBankManager::QueueBankForLoad(v17);
    UFG::qWiseSymbol::operator=(&v3->m_commonBank, v17);
    bankId.mUID = UFG::qWiseSymbol::get_null()->mUID;
    _((AMD_HD3D *)bankId.mUID);
    v18 = v3->m_pEnginePropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v18->mSchemaName.mUID) )
    {
      v19 = UFG::qPropertySet::GetMemImagePtr(v18);
      if ( v19 )
        UFG::qWiseSymbol::operator=(&bankId, (UFG::qWiseSymbol *)v19 + 1);
    }
    UFG::SoundBankManager::QueueBankForUnload(&v3->m_vehicleBank);
    UFG::SoundBankManager::QueueBankForLoad(&bankId);
    UFG::qWiseSymbol::operator=(&v3->m_vehicleBank, &bankId);
    v20 = v3->m_eDriverType;
    if ( v20 <= 1 )
    {
      v23 = &veh_common_player;
    }
    else if ( v20 == 2 )
    {
      v21 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
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
    UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&v3->vfptr, veh_driver_type.mUID, v3->m_vehicleBank.mUID);
    if ( v3->m_eDriverType <= 1 && LocalPlayer )
    {
      v24 = LocalPlayer->m_Flags;
      if ( (v24 >> 14) & 1 )
      {
        v25 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(LocalPlayer);
      }
      else if ( (v24 & 0x8000u) == 0 )
      {
        if ( (v24 >> 13) & 1 )
          v25 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        else
          v25 = (UFG::ActorAudioComponent *)((v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                                 UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::ActorAudioComponent::_TypeUID));
      }
      else
      {
        v25 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      if ( v25 )
      {
        v26 = v25->m_SFXEntity;
        if ( v26 )
        {
          if ( v26->m_bIsInitialized )
            UFG::AudioEntity::SetWwiseSwitch(v26, veh_driver_type.mUID, v3->m_vehicleBank.mUID);
        }
      }
    }
    UFG::SoundBankManager::QueueBankForUnload(&v3->m_driverTypeBank);
    UFG::SoundBankManager::QueueBankForLoad(v23);
    UFG::qWiseSymbol::operator=(&v3->m_driverTypeBank, v23);
    v27 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x60ui64, "VehicleAudioComponent.EngineModel", 0i64, 1u);
    result = v27;
    if ( v27 )
      UFG::EngineModel2::EngineModel2((UFG::EngineModel2 *)v27, v3);
    v3->m_engineModel = (UFG::EngineModel2 *)v27;
    v28 = v3->m_eDriverType;
    if ( v28 <= 1 || (UFG::VehicleAudioComponent::HasDriver(v3) || v3->m_bOverrideDriverType) && v28 - 3 <= 2 )
    {
      v29 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x78ui64, "VehicleAudioComponent.EnvModel", 0i64, 1u);
      result = v29;
      if ( v29 )
        UFG::EnvironmentalModel::EnvironmentalModel((UFG::EnvironmentalModel *)v29, v3);
      v3->m_envModel = (UFG::EnvironmentalModel *)v29;
    }
    v30 = v3->m_eDriverType;
    if ( v30 && v30 != 1 )
      goto LABEL_89;
    if ( v3->m_radio )
      goto LABEL_85;
    if ( UFG::VehicleAudioComponent::IsPoliceVehicle(v3)
      || UFG::VehicleAudioComponent::IsEmergencyVehicle(v3)
      || UFG::VehicleAudioComponent::IsUndercoverVehicle(v3) )
    {
      v32 = 2i64;
    }
    else
    {
      if ( v3->m_eDriverType == eDriverType_Player && UFG::VehicleAudioComponent::GetRadioIsEnabled(v3) )
      {
        UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = v3;
        v31 = UFG::RadioFullyControlled::sm_playerRadio;
        v3->m_radio = UFG::RadioFullyControlled::sm_playerRadio;
        v31->vfptr[1].__vecDelDtor((UFG::AudioEntity *)&v31->vfptr, 0);
      }
      if ( v3->m_eDriverType != eDriverType_PlayerPassenger
        || !(*((_BYTE *)v3 + 636) & 0x10)
        || !UFG::VehicleAudioComponent::GetRadioIsEnabled(v3) )
      {
LABEL_73:
        v34 = v3->m_pSubTypeParameters->mpPropertySet;
        if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v34->mSchemaName.mUID) )
          v35 = UFG::qPropertySet::GetMemImagePtr(v34);
        else
          v35 = 0i64;
        v36 = *((float *)v35 + 49);
        if ( v3->m_eDriverType == eDriverType_Player )
        {
          if ( UFG::VehicleAudioComponent::sm_lastPlayerVehicleAudioComponent == v3 )
          {
            v37 = UFG::VehicleAudioComponent::sm_playerRadioStationSetInLastVehicle;
          }
          else
          {
            if ( v36 > 0.0 )
              UFG::VehicleAudioComponent::SetRadioStation(v3, (signed int)v36);
            if ( !UFG::VehicleAudioComponent::IsPoliceVehicle(v3) && !UFG::VehicleAudioComponent::IsEmergencyVehicle(v3) )
              goto LABEL_85;
            v37 = 11;
          }
          UFG::VehicleAudioComponent::SetRadioStation(v3, v37);
        }
LABEL_85:
        *((_BYTE *)v3 + 636) |= 0x20u;
        if ( !v3->m_entScrape )
        {
          v38 = (UFG::VehicleAudioComponent::ScrapeImpactEntity *)UFG::qMemoryPool::Allocate(
                                                                    &g_AudioComponentPool,
                                                                    0x180ui64,
                                                                    "VehicleAudioComponent.ScrapeEntity",
                                                                    0i64,
                                                                    1u);
          result = v38;
          if ( v38 )
            UFG::VehicleAudioComponent::ScrapeImpactEntity::ScrapeImpactEntity(v38);
          v3->m_entScrape = v38;
          v38->m_pVehicleAudio = v3;
          v39 = v3->m_entScrape->vfptr;
          v40 = UFG::qSymbol::create_suffix((UFG::qSymbol *)&result, v2, "_Scrape");
          (*(void (__fastcall **)(UFG::VehicleAudioComponent::ScrapeImpactEntity *, UFG::qSymbol *, UFG::qMatrix44 *))v39->gap8)(
            v3->m_entScrape,
            v40,
            &UFG::qMatrix44::msIdentity);
        }
LABEL_89:
        v3->m_fTimeAlive = 0.0;
        LODWORD(v3->m_fLastWhooshTime) = LODWORD(UFG::Audio3DDopplerEmitter::sm_fWhooshInterval) ^ _xmm[0];
        v3->m_bVehicleIsInitialized = 1;
        v3->m_surfaceType = 0;
        UFG::VehicleAudioComponent::SetTargetSpeed(v3);
        v3->m_rateLimitedSpeed.m_currentValue = v3->m_rateLimitedSpeed.m_targetValue;
        _((AMD_HD3D *)bankId.mUID);
        return;
      }
      v32 = 0i64;
    }
    UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = v3;
    v33 = UFG::RadioFullyControlled::sm_playerRadio;
    v3->m_radio = UFG::RadioFullyControlled::sm_playerRadio;
    v33->vfptr[1].__vecDelDtor((UFG::AudioEntity *)&v33->vfptr, v32);
    goto LABEL_73;
  }
}33->vfptr[1].__vecDelDtor((UFG::AudioEntity *)&v33->vfptr, v32);
    goto LABEL_73;
  }
}

// File Line: 1522
// RVA: 0x68BE60
void __fastcall UFG::VehicleAudioComponent::Shutdown(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rdi
  UFG::AudioEvent *v3; // rcx
  signed int v4; // esi
  UFG::EngineModel2 *v5; // rbx
  UFG::EnvironmentalModel *v6; // rbx
  bool v7; // zf
  __int64 v8; // rdx
  UFG::RadioFullyControlled *v9; // rcx
  hkgpIndexedMeshDefinitions::Edge *v10; // rdx
  UFG::AudioEntity *v11; // rcx
  __int64 v12; // rdx
  UFG::AudioEvent *v13; // rcx
  char v14; // al

  v2 = this;
  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    v3 = this->m_ecRoadNoise.m_pEvent;
    v4 = UFG::VehicleAudioComponent::sm_configPs->traffic_fadeout_time_ms;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, v4);
    v5 = v2->m_engineModel;
    if ( v5 )
    {
      UFG::EngineModel2::~EngineModel2(v2->m_engineModel, (__int64)a2);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, v5);
    }
    v6 = v2->m_envModel;
    if ( v6 )
    {
      UFG::EnvironmentalModel::~EnvironmentalModel(v2->m_envModel);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, v6);
    }
    v7 = (*((_BYTE *)v2 + 638) & 0x40) == 0;
    v2->m_engineModel = 0i64;
    v2->m_envModel = 0i64;
    if ( !v7 )
    {
      if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
              (hkgpIndexedMesh::EdgeBarrier *)v3,
              a2) )
      {
        v9 = v2->m_radio;
        if ( v9 )
        {
          LOBYTE(v8) = v2->m_eDriverType == 0;
          ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))v9->vfptr[1].CountNumPlayingEvents)(v9, v8);
        }
        *((_BYTE *)v2 + 636) &= 0xDFu;
      }
      if ( UFG::RadioFullyControlled::sm_playerRadio
        && UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent == v2 )
      {
        UFG::VehicleAudioComponent::sm_lastPlayerVehicleAudioComponent = v2;
        UFG::VehicleAudioComponent::sm_playerRadioStationSetInLastVehicle = UFG::RadioFullyControlled::sm_playerRadio->m_curStation->m_id;
        UFG::RadioFullyControlled::sm_playerRadio->m_pVehAudComponent = 0i64;
        v2->m_radio = 0i64;
      }
    }
    UFG::VehicleAudioComponent::SetDriverType(v2, eDriverType_Uninitialized);
    v11 = (UFG::AudioEntity *)&v2->m_entScrape->vfptr;
    if ( v11 )
    {
      UFG::AudioEntity::Shutdown(v11);
      v11 = (UFG::AudioEntity *)&v2->m_entScrape->vfptr;
      if ( v11 )
        v11->vfptr->__vecDelDtor(v11, 1u);
      v2->m_entScrape = 0i64;
    }
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
            (hkgpIndexedMesh::EdgeBarrier *)v11,
            v10) )
    {
      v13 = v2->m_ecHorn.m_pEvent;
      if ( v13 )
      {
        UFG::AudioEvent::StopAndForget(v13, 0);
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_VEHICLE_HORN, v2->m_pSimObject);
      }
      *((_BYTE *)v2 + 638) &= 0xFCu;
    }
    v14 = *((_BYTE *)v2 + 638);
    if ( v14 & 8 )
    {
      LOBYTE(v12) = 1;
      *((_BYTE *)v2 + 638) = v14 & 0xEF;
      UFG::VehicleAudioComponent::DoStopSiren(v2, v12);
    }
    UFG::AudioEntity::StopAndForgetAllEvents((UFG::AudioEntity *)&v2->vfptr, (float)v4);
    *((_BYTE *)v2 + 636) &= 0xFAu;
    *((_BYTE *)v2 + 638) |= 0x20u;
    v2->m_bVehicleIsInitialized = 0;
    v2->m_surfaceType = 0;
    UFG::AudioEntity::ClearContainmentInfo((UFG::AudioEntity *)&v2->vfptr);
  }
}

// File Line: 1586
// RVA: 0x670CE0
void __fastcall UFG::VehicleAudioComponent::AudioEntityUpdate(UFG::VehicleAudioComponent *this, float delta_sec)
{
  float v2; // xmm6_4
  UFG::VehicleAudioComponent *v3; // rbx
  _OWORD *v4; // rsi
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> v5; // xmm2
  __int128 v6; // xmm1
  __int128 v7; // xmm0
  float *v8; // rcx
  float v9; // xmm1_4
  int v10; // xmm0_4
  float v11; // xmm2_4
  UFG::VehicleAudioSubTypeParameters *v12; // rbp
  __int64 v13; // rax
  UFG::PhysicsWheeledVehicle *v14; // rcx
  unsigned __int64 v15; // rsi
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v16; // rcx
  const char *v17; // rax
  UFG::qReflectObject *v18; // rax
  unsigned int v19; // er8
  UFG::AudioEvent *v20; // rcx
  UFG::EngineModel2 *v21; // rcx
  UFG::EnvironmentalModel *v22; // rcx
  UFG::Radio *v23; // rcx
  UFG::SimComponent *v24; // rcx
  float v25; // xmm0_4
  UFG::DamageModel *v26; // rbx
  UFG::qReflectHandleBase v27; // [rsp+28h] [rbp-40h]

  v2 = delta_sec;
  v3 = this;
  if ( !UFG::gFlowController.mCurrentState
    || !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
  {
    if ( LOBYTE(v3->m_containmentInfo.vfptr) && BYTE5(v3->m_radio) && *(_DWORD *)&v3->m_bPositionIsDirty != -1 )
    {
      *(float *)&v3->m_bMissionPlaylist = delta_sec + *(float *)&v3->m_bMissionPlaylist;
      v4 = *(_OWORD **)&v3->m_fLastWhooshTime;
      if ( v4 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&v3->m_fLastWhooshTime);
        v5 = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0>)v4[9];
        v6 = v4[10];
        v7 = v4[11];
        *(_OWORD *)&v3->m_Flags = v4[8];
        v3->m_BoundComponentHandles = v5;
        *(_OWORD *)&v3->vfptr = v6;
        *(_OWORD *)&v3->mNext = v7;
      }
      if ( UFG::VehicleAudioComponent::SoundbanksLoaded((UFG::VehicleAudioComponent *)((char *)v3 - 64)) )
      {
        v8 = (float *)((char *)&v3->m_engineModel + 4);
        v9 = *(float *)&v3->m_damageModel;
        if ( v9 <= *(float *)&v3->m_radio )
          v9 = *(float *)&v3->m_radio;
        if ( v9 >= *((float *)&v3->m_envModel + 1) )
          v9 = *((float *)&v3->m_envModel + 1);
        v10 = (int)v3->m_damageModel;
        if ( *(float *)&v10 < *v8 )
          v11 = *(float *)&v3->m_envModel;
        else
          v11 = *((float *)&v3->m_damageModel + 1);
        UFG::qApproach(v8, v9, v11, v2);
        UFG::VehicleAudioComponent::SetTargetSpeed((UFG::VehicleAudioComponent *)((char *)v3 - 64));
        v12 = v3->m_pSubTypeParameters;
        v13 = *(_QWORD *)&v12[13].m_rateLimitedSpeed.m_riseRate;
        if ( !v13 )
          goto LABEL_50;
        v14 = 0i64;
        if ( *(_BYTE *)(v13 + 604) & 7 )
          v14 = *(UFG::PhysicsWheeledVehicle **)&v12[13].m_rateLimitedSpeed.m_riseRate;
        if ( v14 )
          v15 = UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(v14, 0);
        else
LABEL_50:
          v15 = 0i64;
        UFG::qReflectHandleBase::qReflectHandleBase(&v27);
        v17 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v16);
        v27.mTypeUID = UFG::qStringHash64(v17, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v27, v27.mTypeUID, v15);
        v18 = v27.mData;
        if ( !v27.mData )
        {
          UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v27);
          v18 = v27.mData;
        }
        v19 = (unsigned int)v18[1].mBaseNode.mChildren[0];
        if ( v19 != v3->m_vehicleBank.mUID && v19 != -1 )
        {
          v3->m_vehicleBank.mUID = v19;
          UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)v3, 0x49597BC2u, v19);
          v20 = (UFG::AudioEvent *)v3->m_transformNode.mPrev;
          if ( v20 )
            UFG::AudioEvent::StopAndForget(v20, 0x19u);
        }
        if ( BYTE4(v3->m_radio) & 1 )
        {
          if ( !v3->m_transformNode.mPrev && (v3->m_vehicleBank.mUID || !LODWORD(v12[17].m_parentEngineCurve)) )
            UFG::VehicleAudioComponent::StartRoadNoise((UFG::VehicleAudioComponent *)((char *)v3 - 64));
          if ( BYTE4(v3->m_radio) & 1 )
          {
            v21 = *(UFG::EngineModel2 **)&v3->m_surfaceType;
            if ( v21 )
              UFG::EngineModel2::Update(v21, v2, v10);
          }
        }
        v22 = (UFG::EnvironmentalModel *)v3->m_physicsMoverInterface.mPrev;
        if ( v22 )
          UFG::EnvironmentalModel::Update(v22, v2);
        v23 = (UFG::Radio *)v3->m_physicsMoverInterface.mNext;
        if ( v23 )
          UFG::Radio::Update(v23, v2);
        v24 = v3->m_physicsMoverInterface.m_pPointer;
        if ( v24 && HIDWORD(v24->vfptr[53].__vecDelDtor) )
        {
          v25 = v2 + *(float *)&v24->m_SafePointerList.mNode.mPrev;
          *(float *)&v24->m_SafePointerList.mNode.mPrev = v25;
          if ( v25 >= UFG::DriverReactions::sm_ReactionCooldownPeriod )
            HIDWORD(v24->m_SafePointerList.mNode.mPrev) = 0;
        }
        UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)v3, v2);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v27);
      }
      else
      {
        UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)v3, v2);
      }
    }
    else if ( *(_QWORD *)&v3->m_hornTime )
    {
      UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)v3, delta_sec);
      v26 = *(UFG::DamageModel **)&v3->m_hornTime;
      UFG::DamageModel::HandleDamagedTires(v26);
      UFG::DamageModel::HandleDamagedEngine(v26);
    }
  }
}

// File Line: 1690
// RVA: 0x673C50
float __fastcall UFG::VehicleAudioComponent::CalculateAndApplyDoppler(UFG::VehicleAudioComponent *this, float delta_sec, UFG::qVector3 *vListenerPos, UFG::qVector3 *vListenerVelocity)
{
  UFG::VehicleAudioComponent *v4; // rdi
  float v5; // xmm13_4
  float *v6; // rbx
  UFG::DriverReactions *v7; // rsi
  UFG::qVector3 *v8; // rcx
  UFG::qVector3 *v9; // rax
  UFG::qVector3 *v10; // rcx
  UFG::qVector3 *v11; // rdx
  __m128 v12; // xmm6
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm0_4
  __m128 v17; // xmm1
  float v18; // xmm9_4
  unsigned int v19; // eax
  float v20; // xmm8_4
  float v21; // xmm8_4
  float v22; // xmm10_4
  __m128 v23; // xmm11
  float v24; // xmm12_4
  float v25; // xmm4_4
  __m128 v26; // xmm2
  float v27; // xmm5_4
  __m128 v28; // xmm3
  float v29; // xmm1_4
  float v30; // xmm10_4
  float v31; // xmm11_4
  float v32; // xmm12_4
  __m128 v33; // xmm3
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm6_4
  bool v37; // bl
  bool v38; // bp
  float v39; // xmm0_4
  UFG::DriverReactions *v40; // rcx

  v4 = this;
  v5 = UFG::AudioEntity::CalculateAndApplyDoppler((UFG::AudioEntity *)this, delta_sec, vListenerPos, vListenerVelocity);
  v6 = (float *)UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer;
  if ( UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer )
  {
    v7 = (UFG::DriverReactions *)&v4[-1].m_driverReaction;
    if ( &v4[-1].m_driverReaction != (UFG::DriverReactions **)UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer )
    {
      v8 = *(UFG::qVector3 **)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_Flags;
      v9 = &UFG::qVector3::msZero;
      if ( v8 )
        v10 = v8 + 2;
      else
        v10 = &UFG::qVector3::msZero;
      v11 = *(UFG::qVector3 **)&v4->m_WorldMatrix.v0.x;
      if ( v11 )
        v9 = v11 + 2;
      v12 = (__m128)LODWORD(v9->x);
      v12.m128_f32[0] = (float)((float)((float)(v12.m128_f32[0] - v10->x) * (float)(v12.m128_f32[0] - v10->x))
                              + (float)((float)(v9->y - v10->y) * (float)(v9->y - v10->y)))
                      + (float)((float)(v9->z - v10->z) * (float)(v9->z - v10->z));
      v13 = (float)(UFG::VehicleAudioComponent::sm_fWhooshSpeedThreshold * 0.27777779)
          * (float)(UFG::VehicleAudioComponent::sm_fWhooshSpeedThreshold * 0.27777779);
      v14 = (float)(UFG::VehicleAudioComponent::sm_fHonkSpeedThreshold * 0.27777779)
          * (float)(UFG::VehicleAudioComponent::sm_fHonkSpeedThreshold * 0.27777779);
      if ( v12.m128_f32[0] >= v13 || v12.m128_f32[0] >= v14 )
      {
        LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v12);
        v16 = *((float *)&v4->mNext + 1)
            - *((float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_SafePointerList.mNode.mNext
              + 1);
        v17 = (__m128)LODWORD(v4->mNext);
        v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0]
                                                - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_SafePointerList.mNode.mNext)
                                        * (float)(v17.m128_f32[0]
                                                - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_SafePointerList.mNode.mNext))
                                + (float)(v16 * v16))
                        + (float)((float)(*(float *)&v4->m_name.mUID
                                        - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_TypeUID)
                                * (float)(*(float *)&v4->m_name.mUID
                                        - *(float *)&UFG::VehicleAudioComponent::sm_vehicleFollowTarget.m_pPointer[2].m_TypeUID));
        LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
        if ( (float)(v18 / v15) <= UFG::VehicleAudioComponent::sm_fWhooshScaledDistanceThreshold
          && v12.m128_f32[0] >= v13
          && (float)(*(float *)&v4->m_entScrape + 2.0) <= *(float *)&v4->m_bMissionPlaylist )
        {
          v19 = _S8_17;
          if ( !(_S8_17 & 1) )
          {
            _S8_17 |= 1u;
            s_uWhooshRelSpeed = UFG::TiDo::CalcWwiseUid("whoosh_rel_speed");
            v19 = _S8_17;
          }
          if ( !(v19 & 2) )
          {
            _S8_17 = v19 | 2;
            uEvtWhoosh = UFG::TiDo::CalcWwiseUid("Play_vehicle_whooshes");
          }
          v20 = v15 * 3.5999999;
          if ( LODWORD(v4->m_pSubTypeParameters[17].m_parentEngineCurve) || v20 >= 100.0 )
          {
            UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)v4, s_uWhooshRelSpeed, v20);
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)v4, uEvtWhoosh, 0i64, 0, 0i64);
            LODWORD(v4->m_entScrape) = *(_DWORD *)&v4->m_bMissionPlaylist;
          }
        }
        if ( LOBYTE(v7[eTARGET_TYPE_FOCUS].m_reactionCooldownTimer) )
        {
          if ( BYTE1(v7[eTARGET_TYPE_CONVERSATION].m_numReactions) )
          {
            v21 = UFG::VehicleAudioComponent::sm_fHonkDistanceThreshold;
            if ( v18 <= UFG::VehicleAudioComponent::sm_fHonkDistanceThreshold && v12.m128_f32[0] >= v14 )
            {
              v22 = *(float *)&v4->mNext + *(float *)&v4->m_Flags;
              v26 = (__m128)HIDWORD(v4->mNext);
              v23 = (__m128)HIDWORD(v4->mNext);
              v23.m128_f32[0] = v23.m128_f32[0] + *(float *)(&v4->m_SimObjIndex + 1);
              v24 = *(float *)&v4->m_name.mUID + *(float *)&v4->m_pSimObject;
              v25 = *(float *)&v4->mNext - v6[36];
              v26.m128_f32[0] = v26.m128_f32[0] - v6[37];
              v27 = *(float *)&v4->m_name.mUID - v6[38];
              v28 = v23;
              v28.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22))
                              + (float)(v24 * v24);
              v29 = v28.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
              v30 = v22 * v29;
              v31 = v23.m128_f32[0] * v29;
              v32 = v24 * v29;
              v33 = v26;
              v33.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25))
                              + (float)(v27 * v27);
              v34 = v33.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
              v35 = (float)((float)((float)(v26.m128_f32[0] * v34) * v31) + (float)((float)(v25 * v34) * v30))
                  + (float)((float)(v27 * v34) * v32);
              if ( v35 > 0.0 )
              {
                UFG::qACos(v35);
                if ( (float)((float)(v35 * 180.0) * 0.31830987) < UFG::VehicleAudioComponent::sm_fHonkApproachAngleThreshold )
                {
                  v36 = 1.0 - (float)(v18 / v21);
                  v37 = UFG::VehicleAudioComponent::sm_fOncomingHonkChance > UFG::qRandom(v36, &UFG::qDefaultSeed);
                  v38 = UFG::VehicleAudioComponent::sm_fOncomingYellChance > UFG::qRandom(v36, &UFG::qDefaultSeed);
                  if ( v37 )
                  {
                    v39 = UFG::qRandom(
                            UFG::VehicleAudioComponent::sm_fOncomingHonkMaxLength
                          - UFG::VehicleAudioComponent::sm_fOncomingHonkMinLength,
                            &UFG::qDefaultSeed);
                    UFG::VehicleAudioComponent::HonkAmbientHorn(
                      (UFG::VehicleAudioComponent *)((char *)v4 - 64),
                      v39 + UFG::VehicleAudioComponent::sm_fOncomingHonkMinLength);
                  }
                  if ( v38 )
                  {
                    v40 = (UFG::DriverReactions *)v4->m_physicsMoverInterface.m_pPointer;
                    if ( v40 )
                      UFG::DriverReactions::YellReactionBase(v40, eVocalDriverReactionType_BadDriver);
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
}     }
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
void __fastcall UFG::VehicleAudioComponent::EngineStart(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  char v3; // al

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = *((_BYTE *)v2 + 636);
    if ( !(v3 & 2) )
      *((_BYTE *)v2 + 636) = v3 | 2;
  }
}

// File Line: 1824
// RVA: 0x68C3B0
void __fastcall UFG::VehicleAudioComponent::StartRoadNoise(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioSubTypeParameters *v1; // rax
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::qPropertySet *v3; // rdi
  char *v4; // rax

  v1 = this->m_pSubTypeParameters;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v3->mSchemaName.mUID) )
      v4 = UFG::qPropertySet::GetMemImagePtr(v3);
    else
      v4 = 0i64;
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&v2->vfptr,
      *((_DWORD *)v4 + 66),
      &v2->m_ecRoadNoise,
      0i64,
      0x3E8u,
      0i64);
  }
}

// File Line: 1848
// RVA: 0x68C9B0
void __fastcall UFG::VehicleAudioComponent::StopRadio(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::RadioFullyControlled *v3; // rcx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = v2->m_radio;
    if ( v3 )
      ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD))v3->vfptr[1].CountNumPlayingEvents)(v3, 0i64);
    *((_BYTE *)v2 + 636) &= 0xDFu;
  }
}

// File Line: 1861
// RVA: 0x68B130
void __fastcall UFG::VehicleAudioComponent::SetRadioStation(UFG::VehicleAudioComponent *this, __int64 stationIdx)
{
  unsigned int v2; // edi
  UFG::VehicleAudioComponent *v3; // rbx
  UFG::Radio *v4; // rcx

  v2 = stationIdx;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)stationIdx) )
  {
    v4 = (UFG::Radio *)&v3->m_radio->vfptr;
    if ( v4 )
      UFG::Radio::SetStation(v4, v2);
  }
}

// File Line: 1872
// RVA: 0x67B140
__int64 __fastcall UFG::VehicleAudioComponent::GetRadioStation(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::RadioFullyControlled *v3; // rax
  __int64 result; // rax

  v2 = this;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2)
    || (v3 = v2->m_radio) == 0i64 )
  {
    result = 0i64;
  }
  else
  {
    result = v3->m_curStation->m_id;
  }
  return result;
}

// File Line: 1885
// RVA: 0x68B070
void __fastcall UFG::VehicleAudioComponent::SetRadioIsEnabled(UFG::VehicleAudioComponent *this, __int64 isEnabled)
{
  char v2; // di
  UFG::VehicleAudioComponent *v3; // rbx
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  UFG::RadioFullyControlled *v6; // rax
  UFG::RadioFullyControlled *v7; // rcx

  v2 = isEnabled;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)isEnabled) )
  {
    *((_BYTE *)v3 + 636) &= 0xF7u;
    *((_BYTE *)v3 + 636) |= 8 * (v2 & 1 | 2);
    if ( v2 )
    {
      if ( !v3->m_radio )
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
        v6->m_pVehAudComponent = v3;
        v3->m_radio = UFG::RadioFullyControlled::sm_playerRadio;
      }
    }
    else if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
    {
      v7 = v3->m_radio;
      if ( v7 )
        ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD))v7->vfptr[1].CountNumPlayingEvents)(v7, 0i64);
      *((_BYTE *)v3 + 636) &= 0xDFu;
    }
  }
}

// File Line: 1915
// RVA: 0x67B0D0
bool __fastcall UFG::VehicleAudioComponent::GetRadioIsEnabled(UFG::VehicleAudioComponent *this)
{
  unsigned __int8 v1; // al
  UFG::VehicleAudioSubTypeParameters *v2; // rax
  UFG::qPropertySet *v3; // rbx

  v1 = *((_BYTE *)this + 636);
  if ( v1 & 0x10 )
  {
    LOBYTE(v2) = (v1 >> 3) & 1;
  }
  else
  {
    v2 = this->m_pSubTypeParameters;
    if ( v2 )
    {
      v3 = v2->mpPropertySet;
      if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v3->mSchemaName.mUID) )
        v2 = (UFG::VehicleAudioSubTypeParameters *)(unsigned __int8)UFG::qPropertySet::GetMemImagePtr(v3)[192];
      else
        LOBYTE(v2) = MEMORY[0xC0];
    }
  }
  return (char)v2;
}

// File Line: 1931
// RVA: 0x68B4F0
void __fastcall UFG::VehicleAudioComponent::SetShutdownOnExit(UFG::VehicleAudioComponent *this, __int64 shutdown)
{
  char v2; // bl
  UFG::VehicleAudioComponent *v3; // rdi

  v2 = shutdown;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)shutdown) )
  {
    *((_BYTE *)v3 + 638) &= 0xBFu;
    *((_BYTE *)v3 + 638) |= (v2 & 1) << 6;
  }
}

// File Line: 1985
// RVA: 0x68DFB0
void __fastcall UFG::VehicleAudioComponent::TurnOffRadio(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  __int64 v3; // rdx
  UFG::RadioFullyControlled *v4; // rcx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v4 = v2->m_radio;
    if ( v4 )
    {
      LOBYTE(v3) = v2->m_eDriverType == 0;
      ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))v4->vfptr[1].CountNumPlayingEvents)(v4, v3);
    }
    *((_BYTE *)v2 + 0x27C) &= 0xDFu;
  }
}

// File Line: 2003
// RVA: 0x68EAF0
void __fastcall UFG::VehicleAudioComponent::TurnOnRadio(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::RadioFullyControlled *v3; // rcx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = v2->m_radio;
    if ( v3 )
    {
      if ( *((_BYTE *)&v3->0 + 344) & 4 )
        ((void (*)(void))v3->vfptr[1].AudioEntityUpdate)();
    }
  }
}

// File Line: 2016
// RVA: 0x6745A0
void __fastcall UFG::VehicleAudioComponent::ClearRadioPlaylist(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::RadioFullyControlled *v3; // rax
  UFG::RadioStation *v4; // rcx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = v2->m_radio;
    if ( v3 )
    {
      v4 = v3->m_curStation;
      if ( v4 )
        UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v4->m_playList);
    }
  }
}

// File Line: 2026
// RVA: 0x674550
void __fastcall UFG::VehicleAudioComponent::ClearRadioHistory(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::RadioFullyControlled *v3; // rbx
  UFG::RadioStation *v4; // rbx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = v2->m_radio;
    if ( v3 )
    {
      v4 = v3->m_curStation;
      if ( v4 )
      {
        UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v4->m_prevPlayed);
        v4->m_numRecentlyPlayed = 0;
      }
    }
  }
}

// File Line: 2036
// RVA: 0x670190
void __fastcall UFG::VehicleAudioComponent::AddTrackToPlaylist(UFG::VehicleAudioComponent *this, const char *track)
{
  const char *v2; // rdi
  UFG::VehicleAudioComponent *v3; // rbx
  UFG::RadioFullyControlled *v4; // rax
  UFG::RadioStation *v5; // rbx
  unsigned int v6; // eax

  v2 = track;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)track) )
  {
    v4 = v3->m_radio;
    if ( v4 )
    {
      v5 = v4->m_curStation;
      if ( v5 )
      {
        v6 = UFG::TiDo::CalcWwiseUid(v2);
        UFG::RadioStation::AddToPlaylist(v5, v6, 0);
      }
    }
  }
}

// File Line: 2047
// RVA: 0x688640
void __fastcall UFG::VehicleAudioComponent::RandomizeRadioPlaylist(UFG::VehicleAudioComponent *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::RadioFullyControlled *v3; // rax
  UFG::RadioStation *v4; // rcx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
  {
    v3 = v2->m_radio;
    if ( v3 )
    {
      v4 = v3->m_curStation;
      if ( v4 )
        UFG::RadioStation::RandomizePlaylist(v4);
    }
  }
}

// File Line: 2058
// RVA: 0x68C390
void __fastcall UFG::VehicleAudioComponent::StartHorn(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 638) = *((_BYTE *)this + 638) ^ (*((_BYTE *)this + 638) ^ 4 * stimulus) & 4 | 2;
}

// File Line: 2066
// RVA: 0x676D70
void __fastcall UFG::VehicleAudioComponent::DoStartHorn(UFG::VehicleAudioComponent *this, __int64 stimulus)
{
  char v2; // bp
  UFG::VehicleAudioComponent *v3; // rbx
  UFG::qPropertySet *v4; // rsi
  char *v5; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h]

  v2 = stimulus;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)stimulus) )
  {
    if ( !v3->m_ecHorn.m_pEvent )
    {
      v4 = v3->m_pSubTypeParameters->mpPropertySet;
      if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v4->mSchemaName.mUID) )
        v5 = UFG::qPropertySet::GetMemImagePtr(v4);
      else
        v5 = 0i64;
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&v3->vfptr,
        *((_DWORD *)v5 + 44),
        &v3->m_ecHorn,
        0i64,
        0,
        0i64);
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 1;
      if ( v2 )
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_VEHICLE_HORN,
          &stimulus_parameters,
          v3->m_pSimObject);
    }
    *((_BYTE *)v3 + 638) |= 1u;
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
void __fastcall UFG::VehicleAudioComponent::DoStopHorn(UFG::VehicleAudioComponent *this, __int64 stimulus)
{
  char v2; // di
  UFG::VehicleAudioComponent *v3; // rbx
  UFG::AudioEvent *v4; // rcx

  v2 = stimulus;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)stimulus) )
  {
    v4 = v3->m_ecHorn.m_pEvent;
    if ( v4 )
    {
      UFG::AudioEvent::StopAndForget(v4, 0);
      if ( v2 )
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_VEHICLE_HORN, v3->m_pSimObject);
    }
    *((_BYTE *)v3 + 638) &= 0xFCu;
  }
}

// File Line: 2117
// RVA: 0x67F4E0
bool __fastcall UFG::VehicleAudioComponent::IsPoliceVehicle(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *v1; // rbx
  bool result; // al

  v1 = this->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v1->mSchemaName.mUID) )
    result = *(_DWORD *)UFG::qPropertySet::GetMemImagePtr(v1) == police.mUID;
  else
    result = (_DWORD)MEMORY[0] == police.mUID;
  return result;
}

// File Line: 2131
// RVA: 0x67ED10
bool __fastcall UFG::VehicleAudioComponent::IsEmergencyVehicle(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *v1; // rbx
  bool result; // al

  v1 = this->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v1->mSchemaName.mUID) )
    result = *(_DWORD *)UFG::qPropertySet::GetMemImagePtr(v1) == emergency.mUID;
  else
    result = (_DWORD)MEMORY[0] == emergency.mUID;
  return result;
}

// File Line: 2145
// RVA: 0x67F5B0
bool __fastcall UFG::VehicleAudioComponent::IsUndercoverVehicle(UFG::VehicleAudioComponent *this)
{
  UFG::qPropertySet *v1; // rbx
  bool result; // al

  v1 = this->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v1->mSchemaName.mUID) )
    result = *(_DWORD *)UFG::qPropertySet::GetMemImagePtr(v1) == undercover.mUID;
  else
    result = (_DWORD)MEMORY[0] == undercover.mUID;
  return result;
}

// File Line: 2159
// RVA: 0x68C420
void __fastcall UFG::VehicleAudioComponent::StartSiren(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 0x27E) |= 0x10u;
}

// File Line: 2166
// RVA: 0x676E70
void __fastcall UFG::VehicleAudioComponent::DoStartSiren(UFG::VehicleAudioComponent *this, __int64 stimulus)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::qPropertySet *v3; // rsi
  char *v4; // rax

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)stimulus) )
  {
    if ( !v2->m_ecSiren.m_pEvent )
    {
      v3 = v2->m_pSubTypeParameters->mpPropertySet;
      if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v3->mSchemaName.mUID) )
        v4 = UFG::qPropertySet::GetMemImagePtr(v3);
      else
        v4 = 0i64;
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&v2->vfptr,
        *((_DWORD *)v4 + 62),
        &v2->m_ecSiren,
        0i64,
        0,
        0i64);
    }
    *((_BYTE *)v2 + 638) |= 8u;
  }
}

// File Line: 2183
// RVA: 0x68C9F0
void __fastcall UFG::VehicleAudioComponent::StopSiren(UFG::VehicleAudioComponent *this, bool stimulus)
{
  *((_BYTE *)this + 638) &= 0xEFu;
}

// File Line: 2190
// RVA: 0x677190
void __fastcall UFG::VehicleAudioComponent::DoStopSiren(UFG::VehicleAudioComponent *this, __int64 stimulus)
{
  UFG::VehicleAudioComponent *v2; // rbx
  UFG::AudioEvent *v3; // rcx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx

  v2 = this;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)this,
          (hkgpIndexedMeshDefinitions::Edge *)stimulus) )
  {
    v3 = v2->m_ecSiren.m_pEvent;
    if ( v3 )
    {
      UFG::AudioEvent::StopAndForget(v3, 0);
      v4 = _S9_19;
      if ( !(_S9_19 & 1) )
      {
        _S9_19 |= 1u;
        play_siren_windown = UFG::TiDo::CalcWwiseUid("play_siren_windown");
        v4 = _S9_19;
      }
      if ( v4 & 2 )
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
      if ( v2->m_eDriverType )
        v6 = v5;
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v2->vfptr, v6, 0i64, 0, 0i64);
    }
    *((_BYTE *)v2 + 638) &= 0xF7u;
  }
}

// File Line: 2218
// RVA: 0x67D250
void __fastcall UFG::VehicleAudioComponent::HonkAmbientHorn(UFG::VehicleAudioComponent *this, float timeSec)
{
  UFG::VehicleAudioComponent *v2; // rbx
  const char *v3; // rdx
  unsigned int v4; // eax
  char dest; // [rsp+30h] [rbp-78h]
  _BYTE v6[7]; // [rsp+31h] [rbp-77h]

  v2 = this;
  if ( !this->m_ecHorn.m_pEvent )
  {
    dest = 0;
    memset(v6, 0, 0x5Fui64);
    if ( timeSec >= 0.5 )
    {
      v3 = "play_os_horn_t%u_medium";
      if ( timeSec >= 1.0 )
        v3 = "play_os_horn_t%u_long";
    }
    else
    {
      v3 = "play_os_horn_t%u_short";
    }
    UFG::qSPrintf(&dest, v3, v2->m_ambientHornId);
    v4 = UFG::TiDo::CalcWwiseUid(&dest);
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v2->vfptr, v4, &v2->m_ecHorn, 0i64, 0, 0i64);
  }
}

// File Line: 2265
// RVA: 0x68B690
void __fastcall UFG::VehicleAudioComponent::SetTargetSpeed(UFG::VehicleAudioComponent *this)
{
  UFG::PhysicsMoverInterface *v1; // rax
  UFG::AudioEntityMotionData *v2; // rax
  UFG::qVector3 *v3; // rax

  v1 = (UFG::PhysicsMoverInterface *)this->m_physicsMoverInterface.m_pPointer;
  if ( v1 )
  {
    this->m_rateLimitedSpeed.m_targetValue = v1->mForwardSpeed * 3.5999999;
  }
  else
  {
    v2 = this->m_pMotionData;
    if ( v2 )
      v3 = &v2->m_vCurVelocity;
    else
      v3 = &UFG::qVector3::msZero;
    this->m_rateLimitedSpeed.m_targetValue = (float)((float)((float)(this->m_WorldMatrix.v0.y * v3->y)
                                                           + (float)(v3->x * this->m_WorldMatrix.v0.x))
                                                   + (float)(this->m_WorldMatrix.v0.z * v3->z))
                                           * 3.5999999;
  }
}

// File Line: 2286
// RVA: 0x68ED70
void __fastcall UFG::VehicleAudioComponent::UnloadSoundbanks(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbp
  UFG::qWiseSymbol *v2; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol *v4; // rax

  v1 = this;
  if ( *((_BYTE *)this + 638) & 0x20 )
  {
    UFG::SoundBankManager::QueueBankForUnload(&this->m_vehicleBank);
    UFG::SoundBankManager::QueueBankForUnload(&v1->m_driverTypeBank);
    UFG::SoundBankManager::QueueBankForUnload(&v1->m_commonBank);
    v2 = UFG::qWiseSymbol::get_null();
    UFG::qWiseSymbol::operator=(&v1->m_vehicleBank, v2);
    v3 = UFG::qWiseSymbol::get_null();
    UFG::qWiseSymbol::operator=(&v1->m_driverTypeBank, v3);
    v4 = UFG::qWiseSymbol::get_null();
    UFG::qWiseSymbol::operator=(&v1->m_commonBank, v4);
    *((_BYTE *)v1 + 638) &= 0xDFu;
  }
}

// File Line: 2304
// RVA: 0x68C240
bool __fastcall UFG::VehicleAudioComponent::SoundbanksLoaded(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx

  v1 = this;
  return (UFG::SoundBankManager::BankLoadRequestFinished(&this->m_vehicleBank)
       || v1->m_vehicleBank.mUID == UFG::qWiseSymbol::get_null()->mUID)
      && (UFG::SoundBankManager::BankLoadRequestFinished(&v1->m_driverTypeBank)
       || v1->m_driverTypeBank.mUID == UFG::qWiseSymbol::get_null()->mUID)
      && (UFG::SoundBankManager::BankLoadRequestFinished(&v1->m_commonBank)
       || v1->m_commonBank.mUID == UFG::qWiseSymbol::get_null()->mUID);
}

// File Line: 2318
// RVA: 0x69B950
bool __fastcall UFG::VehicleAudioComponent::WheelsInAir(UFG::VehicleAudioComponent *this)
{
  UFG::SimComponent *v1; // rdi
  int v2; // eax
  int v3; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::PhysicsWheeledVehicle *v5; // rcx

  v1 = this->m_physicsMoverInterface.m_pPointer;
  v2 = (int)v1[12].m_BoundComponentHandles.mNode.mNext;
  if ( v2 )
  {
    v3 = 0;
    if ( v2 <= 0 )
    {
LABEL_9:
      LOBYTE(v2) = 1;
    }
    else
    {
      while ( 1 )
      {
        v4 = v1[10].m_SafePointerList.mNode.mPrev;
        if ( !v4 )
          break;
        v5 = 0i64;
        if ( BYTE4(v4[37].mNext) & 7 )
          v5 = (UFG::PhysicsWheeledVehicle *)v1[10].m_SafePointerList.mNode.mPrev;
        if ( !v5 || UFG::PhysicsWheeledVehicle::IsWheelOnGround(v5, v3) )
          break;
        if ( ++v3 >= SLODWORD(v1[12].m_BoundComponentHandles.mNode.mNext) )
          goto LABEL_9;
      }
      LOBYTE(v2) = 0;
    }
  }
  return v2;
}

// File Line: 2344
// RVA: 0x67C320
void __fastcall UFG::VehicleAudioComponent::HandleImpact(UFG::VehicleAudioComponent *this, float mappedVelocity, UFG::qVector3 *position, UFG::CollisionEvent::ContactType contactType, unsigned int myAudioProperty, unsigned int otherAudioProperty)
{
  UFG::CollisionEvent::ContactType v6; // edi
  UFG::qVector3 *v7; // rsi
  UFG::VehicleAudioComponent *v8; // rbx
  unsigned int v9; // eax
  UFG::EngineModel2 *v10; // rax
  UFG::VehicleAudioComponent::ScrapeImpactEntity *v11; // rcx
  unsigned int v12; // esi
  unsigned int v13; // edi
  UFG::DriverReactions *v14; // rcx
  char v15; // cl
  UFG::PassengerReactions v16; // [rsp+30h] [rbp-28h]
  __int64 v17; // [rsp+38h] [rbp-20h]
  UFG::OneShotHandle pHandle; // [rsp+60h] [rbp+8h]

  v17 = -2i64;
  v6 = contactType;
  v7 = position;
  v8 = this;
  if ( this->m_bIsInitialized && this->m_bVehicleIsInitialized )
  {
    v9 = _S10_14;
    if ( !(_S10_14 & 1) )
    {
      _S10_14 |= 1u;
      s_uMaterial1 = UFG::TiDo::CalcWwiseUid("MATERIAL1");
      v9 = _S10_14;
    }
    if ( !(v9 & 2) )
    {
      _S10_14 = v9 | 2;
      s_uMaterial2 = UFG::TiDo::CalcWwiseUid("MATERIAL2");
      v9 = _S10_14;
    }
    if ( !(v9 & 4) )
    {
      _S10_14 = v9 | 4;
      s_uCollisionEvent = UFG::TiDo::CalcWwiseUid("PLAY_DEBRIS_COLLISION");
      v9 = _S10_14;
    }
    if ( !(v9 & 8) )
    {
      _S10_14 = v9 | 8;
      s_uScrapeEvent = UFG::TiDo::CalcWwiseUid("PLAY_SCRAPE");
      v9 = _S10_14;
    }
    if ( !(v9 & 0x10) )
    {
      _S10_14 = v9 | 0x10;
      s_uBikeCollisionVelocity = UFG::TiDo::CalcWwiseUid("velocity");
    }
    if ( mappedVelocity > 20.0 )
    {
      v10 = v8->m_engineModel;
      if ( v10 )
      {
        v10->m_engineStateMachine->m_event = 14;
        v8->m_engineModel->m_engineStateMachine->m_eventParameter = (float)((float)(mappedVelocity * 0.0099999998)
                                                                          * 0.40000001)
                                                                  + 0.1;
      }
    }
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        v11 = v8->m_entScrape;
        if ( v11 )
          UFG::VehicleAudioComponent::ScrapeImpactEntity::HandleImpact(
            v11,
            s_uScrapeEvent,
            v7,
            myAudioProperty,
            otherAudioProperty);
      }
    }
    else
    {
      pHandle.m_pOneShot = 0i64;
      UFG::OneShotPool::GetOneShotHandle(&pHandle, &v8->m_WorldMatrix);
      if ( UFG::OneShotHandle::IsValid(&pHandle) )
      {
        v12 = myAudioProperty;
        UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr, s_uMaterial1, myAudioProperty);
        v13 = otherAudioProperty;
        UFG::AudioEntity::SetWwiseSwitch(
          (UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr,
          s_uMaterial2,
          otherAudioProperty);
        UFG::AudioEntity::SetRtpcValue(
          (UFG::AudioEntity *)&pHandle.m_pOneShot->vfptr,
          s_uBikeCollisionVelocity,
          mappedVelocity);
        UFG::OneShot::Play(pHandle.m_pOneShot, s_uCollisionEvent);
        v14 = v8->m_driverReaction;
        if ( v14
          && v8->m_eDriverType
          && (v12 == 456259212 || v12 == -2083503057)
          && (v13 == 456259212 || v13 == -2083503057) )
        {
          UFG::DriverReactions::OnCollision(v14);
        }
        v15 = UFG::PassengerReactions::sm_tweakablesLoaded;
        if ( !UFG::PassengerReactions::sm_tweakablesLoaded )
          v15 = 1;
        UFG::PassengerReactions::sm_tweakablesLoaded = v15;
        v16.m_pVehAudComponent = v8;
        if ( mappedVelocity > 20.0 )
          UFG::PassengerReactions::OnCollision(&v16, v13);
        if ( v8->m_eDriverType == eDriverType_Player )
        {
          if ( !(_S10_14 & 0x20) )
          {
            _S10_14 |= 0x20u;
            rumble = UFG::TiDo::CalcWwiseUid("play_motion_vehicle_impact");
          }
          v16.m_pVehAudComponent = 0i64;
          UFG::OneShotPool::GetOneShotHandle((UFG::OneShotHandle *)&v16, &v8->m_WorldMatrix);
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
  UFG::VehicleAudioComponent::ImpactEntity *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::ImpactEntity::`vftable;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->m_vLocalPos.x = UFG::qVector3::msZero.x;
  v1->m_vLocalPos.y = v2;
  v1->m_vLocalPos.z = v3;
  v1->m_pVehicleAudio = 0i64;
  v1->m_Event.m_pEvent = 0i64;
  v1->m_bActive = 0;
}

// File Line: 2444
// RVA: 0x697BC0
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::UpdateImpactPosition(UFG::VehicleAudioComponent::ImpactEntity *this, UFG::qVector3 *vWorldPos)
{
  UFG::VehicleAudioComponent *v2; // rax
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm6_4

  v2 = this->m_pVehicleAudio;
  v3 = vWorldPos->x - v2->m_WorldMatrix.v3.x;
  v4 = vWorldPos->y - v2->m_WorldMatrix.v3.y;
  v5 = vWorldPos->z - v2->m_WorldMatrix.v3.z;
  v6 = (float)((float)(v4 * v2->m_WorldMatrix.v0.y) + (float)(v3 * v2->m_WorldMatrix.v0.x))
     + (float)(v5 * v2->m_WorldMatrix.v0.z);
  v7 = (float)(v4 * v2->m_WorldMatrix.v2.y) + (float)(v3 * v2->m_WorldMatrix.v2.x);
  v8 = v5;
  v9 = (float)(v4 * v2->m_WorldMatrix.v1.y) + (float)(v3 * v2->m_WorldMatrix.v1.x);
  v10 = v5 * v2->m_WorldMatrix.v2.z;
  v11 = v8 * v2->m_WorldMatrix.v1.z;
  this->m_vLocalPos.x = v6;
  v12 = v7 + v10;
  v13 = v9 + v11;
  this->m_vLocalPos.y = v13;
  this->m_vLocalPos.z = v12;
  v14 = (float)((float)((float)(v13 * v2->m_WorldMatrix.v1.x) + (float)(v6 * v2->m_WorldMatrix.v0.x))
              + (float)(v12 * v2->m_WorldMatrix.v2.x))
      + v2->m_WorldMatrix.v3.x;
  v15 = (float)((float)((float)(v6 * v2->m_WorldMatrix.v0.y) + (float)(v13 * v2->m_WorldMatrix.v1.y))
              + (float)(v12 * v2->m_WorldMatrix.v2.y))
      + v2->m_WorldMatrix.v3.y;
  v16 = (float)((float)((float)(v6 * v2->m_WorldMatrix.v0.z) + (float)(v13 * v2->m_WorldMatrix.v1.z))
              + (float)(v12 * v2->m_WorldMatrix.v2.z))
      + v2->m_WorldMatrix.v3.z;
  this->m_WorldMatrix.v3.y = v15;
  this->m_WorldMatrix.v3.x = v14;
  this->m_WorldMatrix.v3.w = 1.0;
  this->m_WorldMatrix.v3.z = v16;
  UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&this->vfptr);
}

// File Line: 2452
// RVA: 0x67C0C0
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::HandleImpact(UFG::VehicleAudioComponent::ImpactEntity *this, unsigned int eventId, UFG::qVector3 *position, float mappedVelocity, unsigned int myAudioProperty, unsigned int otherAudioProperty)
{
  UFG::qVector3 *v6; // rdi
  unsigned int v7; // esi
  UFG::VehicleAudioComponent::ImpactEntity *v8; // rbx
  unsigned int v9; // eax

  v6 = position;
  v7 = eventId;
  v8 = this;
  v9 = _S11_11;
  if ( !(_S11_11 & 1) )
  {
    _S11_11 |= 1u;
    s_uMaterial1_0 = UFG::TiDo::CalcWwiseUid("MATERIAL1");
    v9 = _S11_11;
  }
  if ( !(v9 & 2) )
  {
    _S11_11 = v9 | 2;
    s_uMaterial2_0 = UFG::TiDo::CalcWwiseUid("MATERIAL2");
    v9 = _S11_11;
  }
  if ( !(v9 & 4) )
  {
    _S11_11 = v9 | 4;
    s_uBikeCollisionVelocity_0 = UFG::TiDo::CalcWwiseUid("velocity");
  }
  UFG::VehicleAudioComponent::ImpactEntity::UpdateImpactPosition(v8, v6);
  UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&v8->vfptr, s_uMaterial1_0, myAudioProperty);
  UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&v8->vfptr, s_uMaterial2_0, otherAudioProperty);
  UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v8->vfptr, s_uBikeCollisionVelocity_0, mappedVelocity);
  v8->m_bActive = UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, v7, &v8->m_Event, 0i64, 0, 0i64);
}

// File Line: 2469
// RVA: 0x6709B0
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::AudioEntityUpdate(UFG::VehicleAudioComponent::ImpactEntity *this, float delta_sec)
{
  UFG::VehicleAudioComponent *v2; // rax
  UFG::VehicleAudioComponent::ImpactEntity *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm2_4

  v2 = this->m_pVehicleAudio;
  v3 = this;
  v4 = this->m_vLocalPos.x;
  v5 = v4;
  v6 = (float)((float)((float)(v4 * v2->m_WorldMatrix.v0.z) + (float)(this->m_vLocalPos.y * v2->m_WorldMatrix.v1.z))
             + (float)(this->m_vLocalPos.z * v2->m_WorldMatrix.v2.z))
     + v2->m_WorldMatrix.v3.z;
  v7 = (float)((float)((float)(v5 * v2->m_WorldMatrix.v0.y) + (float)(this->m_vLocalPos.y * v2->m_WorldMatrix.v1.y))
             + (float)(this->m_vLocalPos.z * v2->m_WorldMatrix.v2.y))
     + v2->m_WorldMatrix.v3.y;
  this->m_WorldMatrix.v3.x = (float)((float)((float)(this->m_vLocalPos.y * v2->m_WorldMatrix.v1.x)
                                           + (float)(this->m_vLocalPos.x * v2->m_WorldMatrix.v0.x))
                                   + (float)(this->m_vLocalPos.z * v2->m_WorldMatrix.v2.x))
                           + v2->m_WorldMatrix.v3.x;
  this->m_WorldMatrix.v3.z = v6;
  this->m_WorldMatrix.v3.w = 1.0;
  this->m_WorldMatrix.v3.y = v7;
  UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&this->vfptr);
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)&v3->vfptr, delta_sec);
  if ( v3->m_bActive )
  {
    if ( !v3->m_Event.m_pEvent )
      v3->m_bActive = 0;
  }
}

// File Line: 2487
// RVA: 0x66A670
void __fastcall UFG::VehicleAudioComponent::ScrapeImpactEntity::ScrapeImpactEntity(UFG::VehicleAudioComponent::ScrapeImpactEntity *this)
{
  UFG::VehicleAudioComponent::ScrapeImpactEntity *v1; // rbx

  v1 = this;
  UFG::VehicleAudioComponent::ImpactEntity::ImpactEntity((UFG::VehicleAudioComponent::ImpactEntity *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::ScrapeImpactEntity::`vftable;
  *(_QWORD *)&v1->m_myPrevAudioProperty = 0i64;
  v1->m_fScrapeCountdown = 0.0;
}

// File Line: 2493
// RVA: 0x67C1E0
void __fastcall UFG::VehicleAudioComponent::ScrapeImpactEntity::HandleImpact(UFG::VehicleAudioComponent::ScrapeImpactEntity *this, unsigned int eventId, UFG::qVector3 *position, unsigned int myAudioProperty, unsigned int otherAudioProperty)
{
  unsigned int v5; // esi
  UFG::qVector3 *v6; // rbx
  unsigned int v7; // ebp
  UFG::VehicleAudioComponent::ScrapeImpactEntity *v8; // rdi
  unsigned int v9; // eax
  UFG::AudioEvent *v10; // rcx
  unsigned int v11; // ebx

  v5 = myAudioProperty;
  v6 = position;
  v7 = eventId;
  v8 = this;
  v9 = _S12_12;
  if ( !(_S12_12 & 1) )
  {
    _S12_12 |= 1u;
    s_uMaterial1_1 = UFG::TiDo::CalcWwiseUid("MATERIAL1");
    v9 = _S12_12;
  }
  if ( !(v9 & 2) )
  {
    _S12_12 = v9 | 2;
    s_uMaterial2_1 = UFG::TiDo::CalcWwiseUid("MATERIAL2");
  }
  UFG::VehicleAudioComponent::ImpactEntity::UpdateImpactPosition(
    (UFG::VehicleAudioComponent::ImpactEntity *)&v8->vfptr,
    v6);
  v10 = v8->m_Event.m_pEvent;
  if ( !v10 )
  {
    UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&v8->vfptr, s_uMaterial1_1, v5);
    v11 = otherAudioProperty;
    goto LABEL_11;
  }
  v11 = otherAudioProperty;
  if ( v8->m_myPrevAudioProperty != v5 || v8->m_otherPrevAudioProperty != otherAudioProperty )
  {
    UFG::AudioEvent::StopAndForget(v10, 0xC8u);
    UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&v8->vfptr, s_uMaterial1_1, v5);
LABEL_11:
    UFG::AudioEntity::SetWwiseSwitch((UFG::AudioEntity *)&v8->vfptr, s_uMaterial2_1, v11);
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, v7, &v8->m_Event, 0i64, 0, 0i64);
    v8->m_otherPrevAudioProperty = v11;
    v8->m_myPrevAudioProperty = v5;
    goto LABEL_12;
  }
  UFG::AudioEvent::TouchUpdate(v10);
LABEL_12:
  v8->m_fScrapeCountdown = 0.2;
}

// File Line: 2532
// RVA: 0x670BB0
void __fastcall UFG::VehicleAudioComponent::ScrapeImpactEntity::AudioEntityUpdate(UFG::VehicleAudioComponent::ScrapeImpactEntity *this, float delta_sec)
{
  UFG::VehicleAudioComponent *v2; // rax
  float v3; // xmm3_4
  UFG::VehicleAudioComponent::ScrapeImpactEntity *v4; // rbx
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  UFG::AudioEvent *v11; // rcx

  v2 = this->m_pVehicleAudio;
  v3 = this->m_vLocalPos.y;
  v4 = this;
  v5 = this->m_vLocalPos.x;
  v6 = v5;
  v7 = (float)((float)((float)(v5 * v2->m_WorldMatrix.v0.z) + (float)(v3 * v2->m_WorldMatrix.v1.z))
             + (float)(this->m_vLocalPos.z * v2->m_WorldMatrix.v2.z))
     + v2->m_WorldMatrix.v3.z;
  v8 = (float)((float)((float)(v6 * v2->m_WorldMatrix.v0.y) + (float)(v3 * v2->m_WorldMatrix.v1.y))
             + (float)(this->m_vLocalPos.z * v2->m_WorldMatrix.v2.y))
     + v2->m_WorldMatrix.v3.y;
  this->m_WorldMatrix.v3.x = (float)((float)((float)(this->m_vLocalPos.y * v2->m_WorldMatrix.v1.x)
                                           + (float)(this->m_vLocalPos.x * v2->m_WorldMatrix.v0.x))
                                   + (float)(this->m_vLocalPos.z * v2->m_WorldMatrix.v2.x))
                           + v2->m_WorldMatrix.v3.x;
  this->m_WorldMatrix.v3.z = v7;
  this->m_WorldMatrix.v3.w = 1.0;
  this->m_WorldMatrix.v3.y = v8;
  UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&this->vfptr);
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)&v4->vfptr, delta_sec);
  v9 = v4->m_fScrapeCountdown;
  if ( v9 > 0.0 )
  {
    v10 = v9 - UFG::Metrics::msInstance.mSimTimeDelta;
    v4->m_fScrapeCountdown = v10;
    if ( v10 <= 0.0 )
    {
      v11 = v4->m_Event.m_pEvent;
      if ( v11 )
        UFG::AudioEvent::StopAndForget(v11, 0xC8u);
      v4->m_fScrapeCountdown = 0.0;
    }
  }
}

// File Line: 2614
// RVA: 0x687440
void __fastcall UFG::VehicleAudioComponent::PlayVehicleEvent(UFG::VehicleAudioComponent *this, UFG::qSymbol *name, UFG::AudioEventController *pController, unsigned int fadeInDurationMs)
{
  unsigned int v4; // edi
  UFG::AudioEventController *v5; // rsi
  UFG::qSymbol *v6; // rbp
  UFG::VehicleAudioComponent *v7; // rbx
  UFG::qWiseSymbol *v8; // rax
  unsigned int v9; // edx
  UFG::qWiseSymbol *v10; // rax
  UFG::AudioEntity *v11; // rcx

  v4 = fadeInDurationMs;
  v5 = pController;
  v6 = name;
  v7 = this;
  if ( this->m_eDriverType )
    v4 = UFG::VehicleAudioComponent::sm_configPs->traffic_fadeout_time_ms;
  v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(this->m_pEnginePropertySet, name, DEPTH_RECURSE);
  if ( v8 )
  {
    v9 = v8->mUID;
  }
  else
  {
    v10 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v7->m_pSubTypeParameters->mpPropertySet, v6, DEPTH_RECURSE);
    if ( v10 )
      v9 = v10->mUID;
    else
      v9 = 0;
  }
  v11 = (UFG::AudioEntity *)&v7->vfptr;
  if ( v5 )
    UFG::AudioEntity::CreateAndPlayEvent(v11, v9, v5, 0i64, v4, 0i64);
  else
    UFG::AudioEntity::CreateAndPlayEvent(v11, v9, 0i64, v4, 0i64);
}

// File Line: 2657
// RVA: 0x67D0E0
bool __fastcall UFG::VehicleAudioComponent::HasDriver(UFG::VehicleAudioComponent *this)
{
  UFG::VehicleAudioComponent *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  bool result; // al
  UFG::SimObjectCVBase *v4; // rcx
  UFG::SimObjectCVBase *v5; // rcx

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  result = 1;
  if ( !v2 || !UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2) )
  {
    v4 = (UFG::SimObjectCVBase *)v1->m_pSimObject;
    if ( !v4
      || !v4->m_Components.p[17].m_pComponent
      && (!v4 || !UFG::SimObjectCVBase::GetComponent<UFG::HumanDriverComponent>(v4)) )
    {
      v5 = (UFG::SimObjectCVBase *)v1->m_pSimObject;
      if ( !v5 || !UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(v5) )
        result = 0;
    }
  }
  return result;
}

// File Line: 2688
// RVA: 0x67D150
bool __fastcall UFG::VehicleAudioComponent::HasOccupant(UFG::VehicleAudioComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::SimComponent *v2; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  signed __int64 v4; // rdx
  int v5; // ecx
  signed __int64 i; // rax
  bool result; // al
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  signed __int64 v9; // rdx
  int v10; // eax
  signed __int64 j; // rcx

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v2 = v1->m_Components.p[30].m_pComponent;
  if ( !v2 )
    return 0;
  if ( v2[1].m_pSimObject )
  {
    v3 = v2[1].m_BoundComponentHandles.mNode.mNext;
    v4 = (signed __int64)&v2->m_BoundComponentHandles;
    v5 = 0;
    for ( i = (signed __int64)&v3[-4]; i != v4; i = *(_QWORD *)(i + 72) - 64i64 )
      ++v5;
    result = v5 != -1;
  }
  else
  {
    v8 = v2[1].m_BoundComponentHandles.mNode.mNext;
    v9 = (signed __int64)&v2->m_BoundComponentHandles;
    v10 = 0;
    for ( j = (signed __int64)&v8[-4]; j != v9; j = *(_QWORD *)(j + 72) - 64i64 )
      ++v10;
    result = v10 != 0;
  }
  return result;
}

// File Line: 2723
// RVA: 0x67EC80
char __fastcall UFG::VehicleAudioComponent::IsDriverTypeWithinCutoffRange(UFG::VehicleAudioComponent *this, UFG::VehicleAudioComponent::eDriverType driverType, float distanceToListener2)
{
  UFG::SimComponent *v3; // rax
  float v4; // xmm1_4

  v3 = this->m_physicsMoverInterface.m_pPointer;
  v4 = *(float *)&FLOAT_1_0;
  if ( v3 && !LODWORD(v3[12].m_BoundComponentHandles.mNode.mNext) )
    v4 = FLOAT_2_0;
  if ( distanceToListener2 > (float)(UFG::VehicleAudioComponent::sm_configPs->all_vehicles_max_distance
                                   * UFG::VehicleAudioComponent::sm_configPs->all_vehicles_max_distance) )
    return 0;
  if ( driverType == 4 )
    return (float)((float)(UFG::VehicleAudioComponent::sm_configPs->script_vehicle_max_distance * v4)
                 * (float)(UFG::VehicleAudioComponent::sm_configPs->script_vehicle_max_distance * v4)) > distanceToListener2;
  if ( driverType == 5 )
    return (float)((float)(UFG::VehicleAudioComponent::sm_configPs->cop_vehicle_max_distance * v4)
                 * (float)(UFG::VehicleAudioComponent::sm_configPs->cop_vehicle_max_distance * v4)) > distanceToListener2;
  if ( (unsigned int)driverType <= 1 || driverType != 2 )
    return 1;
  return (float)((float)(UFG::VehicleAudioComponent::sm_configPs->traffic_vehicle_max_distance * v4)
               * (float)(UFG::VehicleAudioComponent::sm_configPs->traffic_vehicle_max_distance * v4)) > distanceToListener2;
}

