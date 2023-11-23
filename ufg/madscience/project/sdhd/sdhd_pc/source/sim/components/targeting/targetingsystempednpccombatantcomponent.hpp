// File Line: 36
// RVA: 0x51FBA0
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedNPCCombatantComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemPedNPCCombatantComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemPedNPCBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemPedNPCCombatantComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TargetingSystemPedNPCCombatantComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemPedNPCCombatantComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemPedNPCCombatantComponent::_DescInit = 1;
    UFG::TargetingSystemPedNPCCombatantComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TargetingSystemPedNPCCombatantComponent::_TargetingSystemPedNPCCombatantComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TargetingSystemPedNPCCombatantComponent::_TypeIDesc;
}

