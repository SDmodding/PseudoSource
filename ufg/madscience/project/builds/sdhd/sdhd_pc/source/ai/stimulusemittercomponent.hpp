// File Line: 41
// RVA: 0x33F680
UFG::ComponentIDDesc *__fastcall UFG::StimulusEmitterComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::StimulusEmitterComponent::_DescInit )
  {
    UFG::StimulusEmitterComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::StimulusEmitterComponent::_DescInit = 1;
    UFG::StimulusEmitterComponent::_TypeUID = UFG::StimulusEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID = UFG::StimulusEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StimulusEmitterComponent::_TypeIDesc;
}

