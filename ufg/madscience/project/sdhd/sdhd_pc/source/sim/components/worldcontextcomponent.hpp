// File Line: 51
// RVA: 0x51FE30
UFG::ComponentIDDesc *__fastcall UFG::WorldContextComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::WorldContextComponent::_DescInit )
  {
    UFG::WorldContextComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::WorldContextComponent::_DescInit = 1;
    UFG::WorldContextComponent::_TypeUID = UFG::WorldContextComponent::_TypeIDesc.mChildBitMask | (UFG::WorldContextComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::WorldContextComponent::_WorldContextComponentTypeUID = UFG::WorldContextComponent::_TypeIDesc.mChildBitMask | (UFG::WorldContextComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::WorldContextComponent::_TypeIDesc;
}

// File Line: 103
// RVA: 0x53C1C0
bool __fastcall UFG::WorldContextComponent::IsSyncing(UFG::WorldContextComponent *this)
{
  return this->mSyncLatchedHandle
      || this->mbSyncingCoverParkour
      || this->mbSyncingCoverLCorner
      || this->mbSyncingCoverRCorner;
}

