// File Line: 57
// RVA: 0x1460BE0
__int64 UFG::_dynamic_initializer_for__RlfSym_min___0()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_min_0, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_min___0);
}

// File Line: 58
// RVA: 0x1460BA0
__int64 UFG::_dynamic_initializer_for__RlfSym_max___0()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_max_0, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_max___0);
}

// File Line: 59
// RVA: 0x1460C20
__int64 UFG::_dynamic_initializer_for__RlfSym_rise_rate___0()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("rise_rate", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_rise_rate_0, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_rise_rate___0);
}

// File Line: 60
// RVA: 0x1460B60
__int64 UFG::_dynamic_initializer_for__RlfSym_fall_rate___0()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("fall_rate", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_fall_rate_0, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_fall_rate___0);
}

// File Line: 129
// RVA: 0x66EFE0
UFG::ComponentIDDesc *__fastcall UFG::VehicleAudioComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleAudioComponent::_DescInit )
  {
    v0 = UFG::HkAudioEntityComponent::AccessComponentDesc();
    ++UFG::HkAudioEntityComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HkAudioEntityComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::VehicleAudioComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::VehicleAudioComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::VehicleAudioComponent::_TypeIDesc.mChildren = 0;
    UFG::VehicleAudioComponent::_DescInit = 1;
    UFG::VehicleAudioComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::VehicleAudioComponent::_VehicleAudioComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::VehicleAudioComponent::_TypeIDesc;
}

// File Line: 339
// RVA: 0x66CB90
void __fastcall UFG::VehicleAudioComponent::ImpactEntity::~ImpactEntity(UFG::VehicleAudioComponent::ImpactEntity *this)
{
  UFG::AudioEvent *m_pEvent; // rcx

  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::VehicleAudioComponent::ImpactEntity::`vftable;
  this->m_pVehicleAudio = 0i64;
  m_pEvent = this->m_Event.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  UFG::AudioEntity::~AudioEntity(this);
}

