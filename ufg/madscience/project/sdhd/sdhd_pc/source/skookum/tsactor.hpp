// File Line: 61
// RVA: 0x4CC540
UFG::ComponentIDDesc *__fastcall UFG::TSActorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::TSActorComponent::_DescInit )
  {
    UFG::TSActorComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::TSActorComponent::_DescInit = 1;
    UFG::TSActorComponent::_TypeUID = UFG::TSActorComponent::_TypeIDesc.mChildBitMask | (UFG::TSActorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TSActorComponent::_TSActorComponentTypeUID = UFG::TSActorComponent::_TypeIDesc.mChildBitMask | (UFG::TSActorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TSActorComponent::_TypeIDesc;
}

