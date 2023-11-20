// File Line: 46
// RVA: 0x51EF40
UFG::ComponentIDDesc *__fastcall UFG::FacialActionTreeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::FacialActionTreeComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::FacialActionTreeComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::FacialActionTreeComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::FacialActionTreeComponent::_DescInit = 1;
    UFG::FacialActionTreeComponent::_TypeUID = UFG::FacialActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::FacialActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FacialActionTreeComponent::_FacialActionTreeComponentTypeUID = UFG::FacialActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::FacialActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FacialActionTreeComponent::_TypeIDesc;
}

