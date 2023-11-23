// File Line: 38
// RVA: 0xFC5E0
UFG::ComponentIDDesc *__fastcall UFG::AIInterestComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AIInterestComponent::_DescInit )
  {
    UFG::AIInterestComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AIInterestComponent::_DescInit = 1;
    UFG::AIInterestComponent::_TypeUID = UFG::AIInterestComponent::_TypeIDesc.mChildBitMask | (UFG::AIInterestComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIInterestComponent::_AIInterestComponentTypeUID = UFG::AIInterestComponent::_TypeIDesc.mChildBitMask | (UFG::AIInterestComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIInterestComponent::_TypeIDesc;
}

