// File Line: 26
// RVA: 0x51F3A0
UFG::ComponentIDDesc *__fastcall UFG::MissionFailConditionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::MissionFailConditionComponent::_DescInit )
  {
    UFG::MissionFailConditionComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::MissionFailConditionComponent::_DescInit = 1;
    UFG::MissionFailConditionComponent::_TypeUID = UFG::MissionFailConditionComponent::_TypeIDesc.mChildBitMask | (UFG::MissionFailConditionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::MissionFailConditionComponent::_MissionFailConditionComponentTypeUID = UFG::MissionFailConditionComponent::_TypeIDesc.mChildBitMask | (UFG::MissionFailConditionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::MissionFailConditionComponent::_TypeIDesc;
}

