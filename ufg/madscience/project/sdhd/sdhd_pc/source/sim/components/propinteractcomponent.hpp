// File Line: 33
// RVA: 0x51F4F0
UFG::ComponentIDDesc *__fastcall UFG::PropInteractComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PropInteractComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PropInteractComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PropInteractComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PropInteractComponent::_DescInit = 1;
    UFG::PropInteractComponent::_TypeUID = UFG::PropInteractComponent::_TypeIDesc.mChildBitMask | (UFG::PropInteractComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PropInteractComponent::_PropInteractComponentTypeUID = UFG::PropInteractComponent::_TypeIDesc.mChildBitMask | (UFG::PropInteractComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PropInteractComponent::_TypeIDesc;
}

