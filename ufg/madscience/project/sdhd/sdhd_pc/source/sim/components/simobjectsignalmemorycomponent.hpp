// File Line: 41
// RVA: 0x51F660
UFG::ComponentIDDesc *__fastcall UFG::SimObjectSignalMemoryComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::SimObjectSignalMemoryComponent::_DescInit )
  {
    UFG::SimObjectSignalMemoryComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::SimObjectSignalMemoryComponent::_DescInit = 1;
    UFG::SimObjectSignalMemoryComponent::_TypeUID = UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SimObjectSignalMemoryComponent::_SimObjectSignalMemoryComponentTypeUID = UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SimObjectSignalMemoryComponent::_TypeIDesc;
}

