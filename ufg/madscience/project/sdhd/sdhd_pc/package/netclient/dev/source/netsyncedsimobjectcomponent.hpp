// File Line: 78
// RVA: 0x15DB30
UFG::ComponentIDDesc *__fastcall NetSyncedSimObjectComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !NetSyncedSimObjectComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&NetSyncedSimObjectComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    NetSyncedSimObjectComponent::_TypeIDesc.mChildren = v0->mChildren;
    NetSyncedSimObjectComponent::_DescInit = 1;
    NetSyncedSimObjectComponent::_TypeUID = NetSyncedSimObjectComponent::_TypeIDesc.mChildBitMask | (NetSyncedSimObjectComponent::_TypeIDesc.mBaseTypeIndex << 25);
    NetSyncedSimObjectComponent::_NetSyncedSimObjectComponentTypeUID = NetSyncedSimObjectComponent::_TypeIDesc.mChildBitMask | (NetSyncedSimObjectComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &NetSyncedSimObjectComponent::_TypeIDesc;
}

