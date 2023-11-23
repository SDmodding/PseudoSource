// File Line: 22
// RVA: 0x15DAC0
UFG::ComponentIDDesc *__fastcall NetPlayerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !NetPlayerComponent::_DescInit )
  {
    NetPlayerComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    NetPlayerComponent::_DescInit = 1;
    NetPlayerComponent::_TypeUID = NetPlayerComponent::_TypeIDesc.mChildBitMask | (NetPlayerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    NetPlayerComponent::_NetPlayerComponentTypeUID = NetPlayerComponent::_TypeIDesc.mChildBitMask | (NetPlayerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &NetPlayerComponent::_TypeIDesc;
}

