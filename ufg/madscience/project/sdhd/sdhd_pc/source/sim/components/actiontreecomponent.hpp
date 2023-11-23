// File Line: 50
// RVA: 0x57E680
UFG::ComponentIDDesc *__fastcall UFG::ActionTreeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::ActionTreeComponent::_DescInit )
  {
    UFG::ActionTreeComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::ActionTreeComponent::_DescInit = 1;
    UFG::ActionTreeComponent::_TypeUID = UFG::ActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ActionTreeComponent::_ActionTreeComponentTypeUID = UFG::ActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ActionTreeComponent::_TypeIDesc;
}

