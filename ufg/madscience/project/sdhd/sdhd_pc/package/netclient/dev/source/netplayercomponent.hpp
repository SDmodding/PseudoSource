// File Line: 22
// RVA: 0x15DAC0
UFG::ComponentIDDesc *__fastcall NetPlayerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !NetPlayerComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&NetPlayerComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    NetPlayerComponent::_TypeIDesc.mChildren = v0->mChildren;
    NetPlayerComponent::_DescInit = 1;
    NetPlayerComponent::_TypeUID = NetPlayerComponent::_TypeIDesc.mChildBitMask | (NetPlayerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    NetPlayerComponent::_NetPlayerComponentTypeUID = NetPlayerComponent::_TypeIDesc.mChildBitMask | (NetPlayerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &NetPlayerComponent::_TypeIDesc;
}

