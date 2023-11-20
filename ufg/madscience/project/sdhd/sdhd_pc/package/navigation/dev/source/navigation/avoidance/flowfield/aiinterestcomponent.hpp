// File Line: 38
// RVA: 0xFC5E0
UFG::ComponentIDDesc *__fastcall UFG::AIInterestComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIInterestComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AIInterestComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AIInterestComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AIInterestComponent::_DescInit = 1;
    UFG::AIInterestComponent::_TypeUID = UFG::AIInterestComponent::_TypeIDesc.mChildBitMask | (UFG::AIInterestComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIInterestComponent::_AIInterestComponentTypeUID = UFG::AIInterestComponent::_TypeIDesc.mChildBitMask | (UFG::AIInterestComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIInterestComponent::_TypeIDesc;
}

