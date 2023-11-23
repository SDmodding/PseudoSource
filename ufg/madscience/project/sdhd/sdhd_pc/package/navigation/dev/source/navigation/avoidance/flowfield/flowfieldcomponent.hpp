// File Line: 47
// RVA: 0xFC730
UFG::ComponentIDDesc *__fastcall UFG::FlowfieldComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::FlowfieldComponent::_DescInit )
  {
    UFG::FlowfieldComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::FlowfieldComponent::_DescInit = 1;
    UFG::FlowfieldComponent::_TypeUID = UFG::FlowfieldComponent::_TypeIDesc.mChildBitMask | (UFG::FlowfieldComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FlowfieldComponent::_FlowfieldComponentTypeUID = UFG::FlowfieldComponent::_TypeIDesc.mChildBitMask | (UFG::FlowfieldComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FlowfieldComponent::_TypeIDesc;
}

