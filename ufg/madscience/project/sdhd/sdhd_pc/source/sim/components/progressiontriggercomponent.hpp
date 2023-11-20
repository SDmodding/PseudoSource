// File Line: 42
// RVA: 0x51F480
UFG::ComponentIDDesc *__fastcall UFG::ProgressionTriggerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::ProgressionTriggerComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::ProgressionTriggerComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::ProgressionTriggerComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::ProgressionTriggerComponent::_DescInit = 1;
    UFG::ProgressionTriggerComponent::_TypeUID = UFG::ProgressionTriggerComponent::_TypeIDesc.mChildBitMask | (UFG::ProgressionTriggerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ProgressionTriggerComponent::_ProgressionTriggerComponentTypeUID = UFG::ProgressionTriggerComponent::_TypeIDesc.mChildBitMask | (UFG::ProgressionTriggerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ProgressionTriggerComponent::_TypeIDesc;
}

