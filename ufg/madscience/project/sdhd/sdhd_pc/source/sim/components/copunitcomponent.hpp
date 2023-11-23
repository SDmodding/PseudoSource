// File Line: 35
// RVA: 0x51EDF0
UFG::ComponentIDDesc *__fastcall UFG::CopUnitComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CopUnitComponent::_DescInit )
  {
    UFG::CopUnitComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CopUnitComponent::_DescInit = 1;
    UFG::CopUnitComponent::_TypeUID = UFG::CopUnitComponent::_TypeIDesc.mChildBitMask | (UFG::CopUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CopUnitComponent::_CopUnitComponentTypeUID = UFG::CopUnitComponent::_TypeIDesc.mChildBitMask | (UFG::CopUnitComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CopUnitComponent::_TypeIDesc;
}

