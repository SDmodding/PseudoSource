// File Line: 57
// RVA: 0x33EC90
UFG::ComponentIDDesc *__fastcall UFG::AIActionTreeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AIActionTreeComponent::_DescInit )
  {
    UFG::AIActionTreeComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AIActionTreeComponent::_DescInit = 1;
    UFG::AIActionTreeComponent::_TypeUID = UFG::AIActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::AIActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIActionTreeComponent::_AIActionTreeComponentTypeUID = UFG::AIActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::AIActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIActionTreeComponent::_TypeIDesc;
}

