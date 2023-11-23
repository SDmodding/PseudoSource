// File Line: 33
// RVA: 0x51F100
UFG::ComponentIDDesc *__fastcall UFG::HudComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HudComponent::_DescInit )
  {
    UFG::HudComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HudComponent::_DescInit = 1;
    UFG::HudComponent::_TypeUID = UFG::HudComponent::_TypeIDesc.mChildBitMask | (UFG::HudComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HudComponent::_HudComponentTypeUID = UFG::HudComponent::_TypeIDesc.mChildBitMask | (UFG::HudComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HudComponent::_TypeIDesc;
}

