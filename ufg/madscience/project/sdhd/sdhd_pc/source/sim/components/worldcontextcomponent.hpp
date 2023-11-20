// File Line: 51
// RVA: 0x51FE30
UFG::ComponentIDDesc *__fastcall UFG::WorldContextComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::WorldContextComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::WorldContextComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::WorldContextComponent::_TypeIDesc.mChildren = v0->mChildren;
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
  return this->mSyncLatchedHandle || *(_WORD *)&this->mbSyncingCoverParkour || this->mbSyncingCoverRCorner;
}

