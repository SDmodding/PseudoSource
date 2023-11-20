// File Line: 42
// RVA: 0x51F020
UFG::ComponentIDDesc *__fastcall UFG::HealthComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HealthComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HealthComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HealthComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::HealthComponent::_DescInit = 1;
    UFG::HealthComponent::_TypeUID = UFG::HealthComponent::_TypeIDesc.mChildBitMask | (UFG::HealthComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HealthComponent::_HealthComponentTypeUID = UFG::HealthComponent::_TypeIDesc.mChildBitMask | (UFG::HealthComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HealthComponent::_TypeIDesc;
}

