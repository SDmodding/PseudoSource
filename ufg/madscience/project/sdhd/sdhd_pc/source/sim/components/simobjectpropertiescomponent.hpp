// File Line: 43
// RVA: 0x51F5F0
UFG::ComponentIDDesc *__fastcall UFG::SimObjectPropertiesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectPropertiesComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::SimObjectPropertiesComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::SimObjectPropertiesComponent::_DescInit = 1;
    UFG::SimObjectPropertiesComponent::_TypeUID = UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectPropertiesComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID = UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectPropertiesComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SimObjectPropertiesComponent::_TypeIDesc;
}

