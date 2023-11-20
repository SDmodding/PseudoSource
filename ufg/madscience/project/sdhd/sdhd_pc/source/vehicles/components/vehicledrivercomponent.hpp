// File Line: 61
// RVA: 0x644560
UFG::ComponentIDDesc *__fastcall UFG::VehicleDriverInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleDriverInterface::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::VehicleDriverInterface::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::VehicleDriverInterface::_TypeIDesc.mChildren = v0->mChildren;
    UFG::VehicleDriverInterface::_DescInit = 1;
    UFG::VehicleDriverInterface::_TypeUID = UFG::VehicleDriverInterface::_TypeIDesc.mChildBitMask | (UFG::VehicleDriverInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleDriverInterface::_VehicleDriverInterfaceTypeUID = UFG::VehicleDriverInterface::_TypeIDesc.mChildBitMask | (UFG::VehicleDriverInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleDriverInterface::_TypeIDesc;
}

