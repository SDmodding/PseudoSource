// File Line: 41
// RVA: 0x51F660
UFG::ComponentIDDesc *__fastcall UFG::SimObjectSignalMemoryComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectSignalMemoryComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::SimObjectSignalMemoryComponent::_DescInit = 1;
    UFG::SimObjectSignalMemoryComponent::_TypeUID = UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SimObjectSignalMemoryComponent::_SimObjectSignalMemoryComponentTypeUID = UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mChildBitMask | (UFG::SimObjectSignalMemoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SimObjectSignalMemoryComponent::_TypeIDesc;
}

