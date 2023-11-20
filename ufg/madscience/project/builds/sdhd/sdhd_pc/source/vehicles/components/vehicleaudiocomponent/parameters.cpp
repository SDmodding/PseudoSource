// File Line: 17
// RVA: 0x1582430
__int64 UFG::_dynamic_initializer_for__VehAudPropSym_siren_event__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("siren_event", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::VehAudPropSym_siren_event, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__VehAudPropSym_siren_event__);
}

// File Line: 25
// RVA: 0x1582C00
__int64 UFG::_dynamic_initializer_for__gParentEngineCurvePropertySetSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicles-audio-engines-Base", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gParentEngineCurvePropertySetSymbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gParentEngineCurvePropertySetSymbol__);
}

// File Line: 30
// RVA: 0x66D300
void __fastcall UFG::VehicleAudioSubTypeParameters::~VehicleAudioSubTypeParameters(UFG::VehicleAudioSubTypeParameters *this)
{
  UFG::VehicleAudioSubTypeParameters *v1; // rbx
  UFG::EngineManager *v2; // rdi

  v1 = this;
  v2 = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(v2, &v1->m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(v2, &v1->m_parentEngineCurve->m_name);
}

// File Line: 45
// RVA: 0x67DFD0
void __fastcall UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(UFG::VehicleAudioSubTypeParameters *this, UFG::qPropertySet *ps)
{
  UFG::VehicleAudioSubTypeParameters *v2; // rdi
  UFG::qPropertySet *v3; // rbx
  char *v4; // rdx
  __int64 v5; // rax
  UFG::qPropertySet *v6; // rdx
  void (__fastcall *v7)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rbx
  void (__fastcall *v8)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  UFG::EngineManager *v9; // rax
  UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *v10; // rax
  UFG::EngineManager *v11; // rax
  void (__fastcall *v12)(const char *); // [rsp+20h] [rbp-18h]
  void (__fastcall *v13)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+28h] [rbp-10h]
  int v14; // [rsp+40h] [rbp+8h]

  v2 = this;
  this->mpPropertySet = ps;
  v3 = ps;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(ps->mSchemaName.mUID) )
    v4 = UFG::qPropertySet::GetMemImagePtr(v3);
  else
    v4 = 0i64;
  v14 = *((_DWORD *)v4 + 14);
  v5 = *((_QWORD *)v4 + 32);
  if ( v5 )
    v6 = (UFG::qPropertySet *)&v4[v5 + 256];
  else
    v6 = 0i64;
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&v2->m_rateLimitedSpeed, v6);
  v7 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v8 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v12 = UFG::VehicleAudioComponent::HotSwapEngineCurve;
  if ( !UFG::VehicleAudioComponent::HotSwapEngineCurve )
    v8 = 0i64;
  v13 = v8;
  v9 = UFG::EngineManager::GetInstance();
  v10 = UFG::EngineManager::FindOrCreateEngine(
          v9,
          (UFG::qSymbol *)&v14,
          (fastdelegate::FastDelegate1<char const *,void> *)&v12);
  v12 = UFG::VehicleAudioComponent::HotSwapEngineCurve;
  if ( !UFG::VehicleAudioComponent::HotSwapEngineCurve )
    v7 = 0i64;
  v2->m_engineCurve = (UFG::EngineCurve *)v10;
  v13 = v7;
  v11 = UFG::EngineManager::GetInstance();
  v2->m_parentEngineCurve = (UFG::EngineCurve *)UFG::EngineManager::FindOrCreateEngine(
                                                  v11,
                                                  (UFG::qSymbol *)&gParentEngineCurvePropertySetSymbol.mUID,
                                                  (fastdelegate::FastDelegate1<char const *,void> *)&v12);
}

