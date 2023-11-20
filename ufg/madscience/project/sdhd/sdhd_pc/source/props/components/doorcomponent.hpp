// File Line: 26
// RVA: 0x489B50
UFG::ComponentIDDesc *__fastcall UFG::DoorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::DoorComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::DoorComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::DoorComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::DoorComponent::_DescInit = 1;
    UFG::DoorComponent::_TypeUID = UFG::DoorComponent::_TypeIDesc.mChildBitMask | (UFG::DoorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DoorComponent::_DoorComponentTypeUID = UFG::DoorComponent::_TypeIDesc.mChildBitMask | (UFG::DoorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DoorComponent::_TypeIDesc;
}

