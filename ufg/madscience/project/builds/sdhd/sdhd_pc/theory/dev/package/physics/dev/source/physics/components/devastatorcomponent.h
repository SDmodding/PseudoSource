// File Line: 153
// RVA: 0x9F940
UFG::ComponentIDDesc *__fastcall UFG::DevastatorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::DevastatorComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::DevastatorComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::DevastatorComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::DevastatorComponent::_DescInit = 1;
    UFG::DevastatorComponent::_TypeUID = UFG::DevastatorComponent::_TypeIDesc.mChildBitMask | (UFG::DevastatorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DevastatorComponent::_DevastatorComponentTypeUID = UFG::DevastatorComponent::_TypeIDesc.mChildBitMask | (UFG::DevastatorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DevastatorComponent::_TypeIDesc;
}

