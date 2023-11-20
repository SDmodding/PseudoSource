// File Line: 61
// RVA: 0x4543A0
UFG::ComponentIDDesc *__fastcall UFG::StateMachineComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::StateMachineComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::StateMachineComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::StateMachineComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::StateMachineComponent::_DescInit = 1;
    UFG::StateMachineComponent::_TypeUID = UFG::StateMachineComponent::_TypeIDesc.mChildBitMask | (UFG::StateMachineComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StateMachineComponent::_StateMachineComponentTypeUID = UFG::StateMachineComponent::_TypeIDesc.mChildBitMask | (UFG::StateMachineComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StateMachineComponent::_TypeIDesc;
}

