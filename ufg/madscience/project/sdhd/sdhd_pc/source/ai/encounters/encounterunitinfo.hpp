// File Line: 75
// RVA: 0x3F2D80
UFG::ComponentIDDesc *__fastcall UFG::EncounterUnitComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::EncounterUnitComponent::_DescInit )
  {
    UFG::EncounterUnitComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::EncounterUnitComponent::_DescInit = 1;
    UFG::EncounterUnitComponent::_TypeUID = UFG::EncounterUnitComponent::_TypeIDesc.mChildBitMask | (UFG::EncounterUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::EncounterUnitComponent::_EncounterUnitComponentTypeUID = UFG::EncounterUnitComponent::_TypeIDesc.mChildBitMask | (UFG::EncounterUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::EncounterUnitComponent::_TypeIDesc;
}

