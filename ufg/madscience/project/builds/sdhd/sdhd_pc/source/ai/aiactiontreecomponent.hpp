// File Line: 57
// RVA: 0x33EC90
UFG::ComponentIDDesc *__fastcall UFG::AIActionTreeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIActionTreeComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AIActionTreeComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AIActionTreeComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AIActionTreeComponent::_DescInit = 1;
    UFG::AIActionTreeComponent::_TypeUID = UFG::AIActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::AIActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIActionTreeComponent::_AIActionTreeComponentTypeUID = UFG::AIActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::AIActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIActionTreeComponent::_TypeIDesc;
}

