// File Line: 41
// RVA: 0x33EF70
UFG::ComponentIDDesc *__fastcall UFG::AIOutlineComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AIOutlineComponent::_DescInit )
  {
    UFG::AIOutlineComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AIOutlineComponent::_DescInit = 1;
    UFG::AIOutlineComponent::_TypeUID = UFG::AIOutlineComponent::_TypeIDesc.mChildBitMask | (UFG::AIOutlineComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIOutlineComponent::_AIOutlineComponentTypeUID = UFG::AIOutlineComponent::_TypeIDesc.mChildBitMask | (UFG::AIOutlineComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIOutlineComponent::_TypeIDesc;
}

