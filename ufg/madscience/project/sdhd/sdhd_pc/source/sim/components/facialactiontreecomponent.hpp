// File Line: 46
// RVA: 0x51EF40
UFG::ComponentIDDesc *__fastcall UFG::FacialActionTreeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::FacialActionTreeComponent::_DescInit )
  {
    UFG::FacialActionTreeComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::FacialActionTreeComponent::_DescInit = 1;
    UFG::FacialActionTreeComponent::_TypeUID = UFG::FacialActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::FacialActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FacialActionTreeComponent::_FacialActionTreeComponentTypeUID = UFG::FacialActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::FacialActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FacialActionTreeComponent::_TypeIDesc;
}

