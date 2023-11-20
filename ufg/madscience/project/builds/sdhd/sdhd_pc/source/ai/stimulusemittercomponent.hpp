// File Line: 41
// RVA: 0x33F680
UFG::ComponentIDDesc *__fastcall UFG::StimulusEmitterComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::StimulusEmitterComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::StimulusEmitterComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::StimulusEmitterComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::StimulusEmitterComponent::_DescInit = 1;
    UFG::StimulusEmitterComponent::_TypeUID = UFG::StimulusEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID = UFG::StimulusEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StimulusEmitterComponent::_TypeIDesc;
}

