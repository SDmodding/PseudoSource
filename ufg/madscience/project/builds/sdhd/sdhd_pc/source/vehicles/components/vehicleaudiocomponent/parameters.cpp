// File Line: 17
// RVA: 0x1582430
__int64 UFG::_dynamic_initializer_for__VehAudPropSym_siren_event__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("siren_event", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::VehAudPropSym_siren_event, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__VehAudPropSym_siren_event__);
}

// File Line: 25
// RVA: 0x1582C00
__int64 UFG::_dynamic_initializer_for__gParentEngineCurvePropertySetSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("vehicles-audio-engines-Base", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gParentEngineCurvePropertySetSymbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gParentEngineCurvePropertySetSymbol__);
}

// File Line: 30
// RVA: 0x66D300
void __fastcall UFG::VehicleAudioSubTypeParameters::~VehicleAudioSubTypeParameters(
        UFG::VehicleAudioSubTypeParameters *this)
{
  UFG::EngineManager *Instance; // rdi

  Instance = UFG::EngineManager::GetInstance();
  UFG::EngineManager::ReleaseEngine(Instance, &this->m_engineCurve->m_name);
  UFG::EngineManager::ReleaseEngine(Instance, &this->m_parentEngineCurve->m_name);
}

// File Line: 45
// RVA: 0x67DFD0
void __fastcall UFG::VehicleAudioSubTypeParameters::InitFromPropertySet(
        UFG::VehicleAudioSubTypeParameters *this,
        UFG::qPropertySet *ps)
{
  char *MemImagePtr; // rdx
  __int64 v5; // rax
  UFG::qPropertySet *v6; // rdx
  void (__fastcall *v7)(fastdelegate::detail::GenericClass *); // rbx
  void (__fastcall *v8)(fastdelegate::detail::GenericClass *); // rax
  UFG::EngineManager *Instance; // rax
  UFG::EngineCurve *v10; // rax
  UFG::EngineManager *v11; // rax
  fastdelegate::FastDelegate1<char const *,void> v12; // [rsp+20h] [rbp-18h] BYREF
  UFG::qSymbol v13; // [rsp+40h] [rbp+8h] BYREF

  this->mpPropertySet = ps;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(ps->mSchemaName.mUID) )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(ps);
  else
    MemImagePtr = 0i64;
  v13.mUID = *((_DWORD *)MemImagePtr + 14);
  v5 = *((_QWORD *)MemImagePtr + 32);
  if ( v5 )
    v6 = (UFG::qPropertySet *)&MemImagePtr[v5 + 256];
  else
    v6 = 0i64;
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&this->m_rateLimitedSpeed, v6);
  v7 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v8 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v12.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::VehicleAudioComponent::HotSwapEngineCurve;
  if ( !UFG::VehicleAudioComponent::HotSwapEngineCurve )
    v8 = 0i64;
  v12.m_Closure.m_pFunction = v8;
  Instance = UFG::EngineManager::GetInstance();
  v10 = UFG::EngineManager::FindOrCreateEngine(Instance, &v13, &v12);
  v12.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::VehicleAudioComponent::HotSwapEngineCurve;
  if ( !UFG::VehicleAudioComponent::HotSwapEngineCurve )
    v7 = 0i64;
  this->m_engineCurve = v10;
  v12.m_Closure.m_pFunction = v7;
  v11 = UFG::EngineManager::GetInstance();
  this->m_parentEngineCurve = UFG::EngineManager::FindOrCreateEngine(v11, &gParentEngineCurvePropertySetSymbol, &v12);
}

