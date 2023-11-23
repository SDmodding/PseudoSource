// File Line: 26
// RVA: 0x489B50
UFG::ComponentIDDesc *__fastcall UFG::DoorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DoorComponent::_DescInit )
  {
    UFG::DoorComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::DoorComponent::_DescInit = 1;
    UFG::DoorComponent::_TypeUID = UFG::DoorComponent::_TypeIDesc.mChildBitMask | (UFG::DoorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DoorComponent::_DoorComponentTypeUID = UFG::DoorComponent::_TypeIDesc.mChildBitMask | (UFG::DoorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DoorComponent::_TypeIDesc;
}

