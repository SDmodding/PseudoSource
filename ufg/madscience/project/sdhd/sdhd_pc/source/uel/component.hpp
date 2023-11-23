// File Line: 31
// RVA: 0x5B7C40
UFG::ComponentIDDesc *__fastcall UFG::UELComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::UELComponent::_DescInit )
  {
    UFG::UELComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::UELComponent::_DescInit = 1;
    UFG::UELComponent::_TypeUID = UFG::UELComponent::_TypeIDesc.mChildBitMask | (UFG::UELComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::UELComponent::_UELComponentTypeUID = UFG::UELComponent::_TypeIDesc.mChildBitMask | (UFG::UELComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::UELComponent::_TypeIDesc;
}

