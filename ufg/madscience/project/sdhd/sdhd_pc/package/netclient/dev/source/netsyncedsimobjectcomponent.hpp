// File Line: 78
// RVA: 0x15DB30
UFG::ComponentIDDesc *__fastcall NetSyncedSimObjectComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !NetSyncedSimObjectComponent::_DescInit )
  {
    NetSyncedSimObjectComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    NetSyncedSimObjectComponent::_DescInit = 1;
    NetSyncedSimObjectComponent::_TypeUID = NetSyncedSimObjectComponent::_TypeIDesc.mChildBitMask | (NetSyncedSimObjectComponent::_TypeIDesc.mBaseTypeIndex << 25);
    NetSyncedSimObjectComponent::_NetSyncedSimObjectComponentTypeUID = NetSyncedSimObjectComponent::_TypeIDesc.mChildBitMask | (NetSyncedSimObjectComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &NetSyncedSimObjectComponent::_TypeIDesc;
}

