// File Line: 33
// RVA: 0x51F4F0
UFG::ComponentIDDesc *__fastcall UFG::PropInteractComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PropInteractComponent::_DescInit )
  {
    UFG::PropInteractComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PropInteractComponent::_DescInit = 1;
    UFG::PropInteractComponent::_TypeUID = UFG::PropInteractComponent::_TypeIDesc.mChildBitMask | (UFG::PropInteractComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PropInteractComponent::_PropInteractComponentTypeUID = UFG::PropInteractComponent::_TypeIDesc.mChildBitMask | (UFG::PropInteractComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PropInteractComponent::_TypeIDesc;
}

