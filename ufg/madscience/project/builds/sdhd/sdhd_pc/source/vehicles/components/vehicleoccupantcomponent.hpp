// File Line: 32
// RVA: 0x66F0E0
UFG::ComponentIDDesc *__fastcall UFG::VehicleOccupantComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleOccupantComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::VehicleOccupantComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::VehicleOccupantComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::VehicleOccupantComponent::_DescInit = 1;
    UFG::VehicleOccupantComponent::_TypeUID = UFG::VehicleOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleOccupantComponent::_VehicleOccupantComponentTypeUID = UFG::VehicleOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleOccupantComponent::_TypeIDesc;
}

