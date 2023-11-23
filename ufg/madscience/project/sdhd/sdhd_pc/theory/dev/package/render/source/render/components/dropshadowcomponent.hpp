// File Line: 41
// RVA: 0x746C0
UFG::ComponentIDDesc *__fastcall UFG::DropShadowComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DropShadowComponent::_DescInit )
  {
    UFG::DropShadowComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::DropShadowComponent::_DescInit = 1;
    UFG::DropShadowComponent::_TypeUID = UFG::DropShadowComponent::_TypeIDesc.mChildBitMask | (UFG::DropShadowComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DropShadowComponent::_DropShadowComponentTypeUID = UFG::DropShadowComponent::_TypeIDesc.mChildBitMask | (UFG::DropShadowComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DropShadowComponent::_TypeIDesc;
}

