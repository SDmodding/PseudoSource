// File Line: 47
// RVA: 0x9F9B0
UFG::ComponentIDDesc *__fastcall UFG::MultiBodyComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::MultiBodyComponent::_DescInit )
  {
    UFG::MultiBodyComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::MultiBodyComponent::_DescInit = 1;
    UFG::MultiBodyComponent::_TypeUID = UFG::MultiBodyComponent::_TypeIDesc.mChildBitMask | (UFG::MultiBodyComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::MultiBodyComponent::_MultiBodyComponentTypeUID = UFG::MultiBodyComponent::_TypeIDesc.mChildBitMask | (UFG::MultiBodyComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::MultiBodyComponent::_TypeIDesc;
}

