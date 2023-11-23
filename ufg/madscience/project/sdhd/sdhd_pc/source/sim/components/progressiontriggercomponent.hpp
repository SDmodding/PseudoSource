// File Line: 42
// RVA: 0x51F480
UFG::ComponentIDDesc *__fastcall UFG::ProgressionTriggerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::ProgressionTriggerComponent::_DescInit )
  {
    UFG::ProgressionTriggerComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::ProgressionTriggerComponent::_DescInit = 1;
    UFG::ProgressionTriggerComponent::_TypeUID = UFG::ProgressionTriggerComponent::_TypeIDesc.mChildBitMask | (UFG::ProgressionTriggerComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ProgressionTriggerComponent::_ProgressionTriggerComponentTypeUID = UFG::ProgressionTriggerComponent::_TypeIDesc.mChildBitMask | (UFG::ProgressionTriggerComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ProgressionTriggerComponent::_TypeIDesc;
}

