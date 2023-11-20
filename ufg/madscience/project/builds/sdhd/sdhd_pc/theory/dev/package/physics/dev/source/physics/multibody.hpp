// File Line: 47
// RVA: 0x9F9B0
UFG::ComponentIDDesc *__fastcall UFG::MultiBodyComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::MultiBodyComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::MultiBodyComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::MultiBodyComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::MultiBodyComponent::_DescInit = 1;
    UFG::MultiBodyComponent::_TypeUID = UFG::MultiBodyComponent::_TypeIDesc.mChildBitMask | (UFG::MultiBodyComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::MultiBodyComponent::_MultiBodyComponentTypeUID = UFG::MultiBodyComponent::_TypeIDesc.mChildBitMask | (UFG::MultiBodyComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::MultiBodyComponent::_TypeIDesc;
}

