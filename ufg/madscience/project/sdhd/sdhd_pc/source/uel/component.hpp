// File Line: 31
// RVA: 0x5B7C40
UFG::ComponentIDDesc *__fastcall UFG::UELComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::UELComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::UELComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::UELComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::UELComponent::_DescInit = 1;
    UFG::UELComponent::_TypeUID = UFG::UELComponent::_TypeIDesc.mChildBitMask | (UFG::UELComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::UELComponent::_UELComponentTypeUID = UFG::UELComponent::_TypeIDesc.mChildBitMask | (UFG::UELComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::UELComponent::_TypeIDesc;
}

