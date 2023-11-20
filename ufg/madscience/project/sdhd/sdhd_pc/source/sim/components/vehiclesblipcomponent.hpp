// File Line: 23
// RVA: 0x51FDC0
UFG::ComponentIDDesc *__fastcall UFG::VehiclesBlipComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehiclesBlipComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::VehiclesBlipComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::VehiclesBlipComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::VehiclesBlipComponent::_DescInit = 1;
    UFG::VehiclesBlipComponent::_TypeUID = UFG::VehiclesBlipComponent::_TypeIDesc.mChildBitMask | (UFG::VehiclesBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehiclesBlipComponent::_VehiclesBlipComponentTypeUID = UFG::VehiclesBlipComponent::_TypeIDesc.mChildBitMask | (UFG::VehiclesBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehiclesBlipComponent::_TypeIDesc;
}

