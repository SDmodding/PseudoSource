// File Line: 41
// RVA: 0x33EF70
UFG::ComponentIDDesc *__fastcall UFG::AIOutlineComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIOutlineComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AIOutlineComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AIOutlineComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AIOutlineComponent::_DescInit = 1;
    UFG::AIOutlineComponent::_TypeUID = UFG::AIOutlineComponent::_TypeIDesc.mChildBitMask | (UFG::AIOutlineComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIOutlineComponent::_AIOutlineComponentTypeUID = UFG::AIOutlineComponent::_TypeIDesc.mChildBitMask | (UFG::AIOutlineComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIOutlineComponent::_TypeIDesc;
}

