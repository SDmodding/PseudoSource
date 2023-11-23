// File Line: 109
// RVA: 0x667FE0
void __fastcall UFG::EffectStatus::EffectStatus(UFG::EffectStatus *this)
{
  *((_DWORD *)this + 4) &= ~1u;
  this->mState = UNINITIALIZED;
  this->mInternalState = 0i64;
}

// File Line: 147
// RVA: 0x66F070
UFG::ComponentIDDesc *__fastcall UFG::VehicleEffectsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::VehicleEffectsComponent::_DescInit )
  {
    UFG::VehicleEffectsComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::VehicleEffectsComponent::_DescInit = 1;
    UFG::VehicleEffectsComponent::_TypeUID = UFG::VehicleEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleEffectsComponent::_VehicleEffectsComponentTypeUID = UFG::VehicleEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleEffectsComponent::_TypeIDesc;
}

