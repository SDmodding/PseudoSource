// File Line: 61
// RVA: 0x644560
UFG::ComponentIDDesc *__fastcall UFG::VehicleDriverInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::VehicleDriverInterface::_DescInit )
  {
    UFG::VehicleDriverInterface::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::VehicleDriverInterface::_DescInit = 1;
    UFG::VehicleDriverInterface::_TypeUID = UFG::VehicleDriverInterface::_TypeIDesc.mChildBitMask | (UFG::VehicleDriverInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleDriverInterface::_VehicleDriverInterfaceTypeUID = UFG::VehicleDriverInterface::_TypeIDesc.mChildBitMask | (UFG::VehicleDriverInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleDriverInterface::_TypeIDesc;
}

