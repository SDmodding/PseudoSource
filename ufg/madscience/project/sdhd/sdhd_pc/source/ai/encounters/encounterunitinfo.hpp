// File Line: 75
// RVA: 0x3F2D80
UFG::ComponentIDDesc *__fastcall UFG::EncounterUnitComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::EncounterUnitComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::EncounterUnitComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::EncounterUnitComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::EncounterUnitComponent::_DescInit = 1;
    UFG::EncounterUnitComponent::_TypeUID = UFG::EncounterUnitComponent::_TypeIDesc.mChildBitMask | (UFG::EncounterUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::EncounterUnitComponent::_EncounterUnitComponentTypeUID = UFG::EncounterUnitComponent::_TypeIDesc.mChildBitMask | (UFG::EncounterUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::EncounterUnitComponent::_TypeIDesc;
}

