// File Line: 61
// RVA: 0x4543A0
UFG::ComponentIDDesc *__fastcall UFG::StateMachineComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::StateMachineComponent::_DescInit )
  {
    UFG::StateMachineComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::StateMachineComponent::_DescInit = 1;
    UFG::StateMachineComponent::_TypeUID = UFG::StateMachineComponent::_TypeIDesc.mChildBitMask | (UFG::StateMachineComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StateMachineComponent::_StateMachineComponentTypeUID = UFG::StateMachineComponent::_TypeIDesc.mChildBitMask | (UFG::StateMachineComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StateMachineComponent::_TypeIDesc;
}

