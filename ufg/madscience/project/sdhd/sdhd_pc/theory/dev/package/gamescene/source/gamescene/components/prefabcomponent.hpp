// File Line: 25
// RVA: 0x2391A0
UFG::ComponentIDDesc *__fastcall UFG::PrefabComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PrefabComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PrefabComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PrefabComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PrefabComponent::_DescInit = 1;
    UFG::PrefabComponent::_TypeUID = UFG::PrefabComponent::_TypeIDesc.mChildBitMask | (UFG::PrefabComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PrefabComponent::_PrefabComponentTypeUID = UFG::PrefabComponent::_TypeIDesc.mChildBitMask | (UFG::PrefabComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PrefabComponent::_TypeIDesc;
}

