// File Line: 25
// RVA: 0x2391A0
UFG::ComponentIDDesc *__fastcall UFG::PrefabComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PrefabComponent::_DescInit )
  {
    UFG::PrefabComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PrefabComponent::_DescInit = 1;
    UFG::PrefabComponent::_TypeUID = UFG::PrefabComponent::_TypeIDesc.mChildBitMask | (UFG::PrefabComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PrefabComponent::_PrefabComponentTypeUID = UFG::PrefabComponent::_TypeIDesc.mChildBitMask | (UFG::PrefabComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PrefabComponent::_TypeIDesc;
}

