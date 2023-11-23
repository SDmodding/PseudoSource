// File Line: 43
// RVA: 0x51F5F0
UFG::ComponentIDDesc *__fastcall UFG::SimObjectPropertiesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::SimObjectPropertiesComponent::_DescInit )
  {
    UFG::SimObjectPropertiesComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::SimObjectPropertiesComponent::_DescInit = 1;
    UFG::SimObjectPropertiesComponent::_TypeUID = UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectPropertiesComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID = UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectPropertiesComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SimObjectPropertiesComponent::_TypeIDesc;
}

