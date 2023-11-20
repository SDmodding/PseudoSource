// File Line: 26
// RVA: 0x51F3A0
UFG::ComponentIDDesc *__fastcall UFG::MissionFailConditionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::MissionFailConditionComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::MissionFailConditionComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::MissionFailConditionComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::MissionFailConditionComponent::_DescInit = 1;
    UFG::MissionFailConditionComponent::_TypeUID = UFG::MissionFailConditionComponent::_TypeIDesc.mChildBitMask | (UFG::MissionFailConditionComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::MissionFailConditionComponent::_MissionFailConditionComponentTypeUID = UFG::MissionFailConditionComponent::_TypeIDesc.mChildBitMask | (UFG::MissionFailConditionComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::MissionFailConditionComponent::_TypeIDesc;
}

