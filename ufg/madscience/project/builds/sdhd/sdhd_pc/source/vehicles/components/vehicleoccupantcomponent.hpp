// File Line: 32
// RVA: 0x66F0E0
UFG::ComponentIDDesc *__fastcall UFG::VehicleOccupantComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::VehicleOccupantComponent::_DescInit )
  {
    UFG::VehicleOccupantComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::VehicleOccupantComponent::_DescInit = 1;
    UFG::VehicleOccupantComponent::_TypeUID = UFG::VehicleOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleOccupantComponent::_VehicleOccupantComponentTypeUID = UFG::VehicleOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleOccupantComponent::_TypeIDesc;
}

