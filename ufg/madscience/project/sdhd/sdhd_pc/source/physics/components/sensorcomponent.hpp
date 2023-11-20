// File Line: 72
// RVA: 0x454330
UFG::ComponentIDDesc *__fastcall UFG::SensorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::SensorComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::SensorComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::SensorComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::SensorComponent::_DescInit = 1;
    UFG::SensorComponent::_TypeUID = UFG::SensorComponent::_TypeIDesc.mChildBitMask | (UFG::SensorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SensorComponent::_SensorComponentTypeUID = UFG::SensorComponent::_TypeIDesc.mChildBitMask | (UFG::SensorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SensorComponent::_TypeIDesc;
}

