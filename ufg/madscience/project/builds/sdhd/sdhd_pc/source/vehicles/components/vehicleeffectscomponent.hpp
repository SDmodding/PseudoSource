// File Line: 109
// RVA: 0x667FE0
void __fastcall UFG::EffectStatus::EffectStatus(UFG::EffectStatus *this)
{
  *((_DWORD *)this + 4) &= 0xFFFFFFFE;
  this->mState = 0;
  this->mInternalState = 0i64;
}

// File Line: 147
// RVA: 0x66F070
UFG::ComponentIDDesc *__fastcall UFG::VehicleEffectsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleEffectsComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::VehicleEffectsComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::VehicleEffectsComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::VehicleEffectsComponent::_DescInit = 1;
    UFG::VehicleEffectsComponent::_TypeUID = UFG::VehicleEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleEffectsComponent::_VehicleEffectsComponentTypeUID = UFG::VehicleEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleEffectsComponent::_TypeIDesc;
}

