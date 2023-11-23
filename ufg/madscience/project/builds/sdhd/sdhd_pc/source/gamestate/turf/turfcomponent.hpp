// File Line: 37
// RVA: 0x41A040
UFG::ComponentIDDesc *__fastcall UFG::TurfComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::TurfComponent::_DescInit )
  {
    UFG::TurfComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::TurfComponent::_DescInit = 1;
    UFG::TurfComponent::_TypeUID = UFG::TurfComponent::_TypeIDesc.mChildBitMask | (UFG::TurfComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TurfComponent::_TurfComponentTypeUID = UFG::TurfComponent::_TypeIDesc.mChildBitMask | (UFG::TurfComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TurfComponent::_TypeIDesc;
}

