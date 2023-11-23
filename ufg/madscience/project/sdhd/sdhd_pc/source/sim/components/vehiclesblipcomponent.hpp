// File Line: 23
// RVA: 0x51FDC0
UFG::ComponentIDDesc *__fastcall UFG::VehiclesBlipComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::VehiclesBlipComponent::_DescInit )
  {
    UFG::VehiclesBlipComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::VehiclesBlipComponent::_DescInit = 1;
    UFG::VehiclesBlipComponent::_TypeUID = UFG::VehiclesBlipComponent::_TypeIDesc.mChildBitMask | (UFG::VehiclesBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehiclesBlipComponent::_VehiclesBlipComponentTypeUID = UFG::VehiclesBlipComponent::_TypeIDesc.mChildBitMask | (UFG::VehiclesBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehiclesBlipComponent::_TypeIDesc;
}

