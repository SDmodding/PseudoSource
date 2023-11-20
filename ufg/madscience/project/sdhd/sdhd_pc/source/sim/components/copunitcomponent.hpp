// File Line: 35
// RVA: 0x51EDF0
UFG::ComponentIDDesc *__fastcall UFG::CopUnitComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CopUnitComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CopUnitComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CopUnitComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CopUnitComponent::_DescInit = 1;
    UFG::CopUnitComponent::_TypeUID = UFG::CopUnitComponent::_TypeIDesc.mChildBitMask | (UFG::CopUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CopUnitComponent::_CopUnitComponentTypeUID = UFG::CopUnitComponent::_TypeIDesc.mChildBitMask | (UFG::CopUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CopUnitComponent::_TypeIDesc;
}

