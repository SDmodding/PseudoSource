// File Line: 28
// RVA: 0x4540E0
UFG::ComponentIDDesc *__fastcall UFG::ParkourComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::ParkourComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::ParkourComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::ParkourComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::ParkourComponent::_DescInit = 1;
    UFG::ParkourComponent::_TypeUID = UFG::ParkourComponent::_TypeIDesc.mChildBitMask | (UFG::ParkourComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ParkourComponent::_ParkourComponentTypeUID = UFG::ParkourComponent::_TypeIDesc.mChildBitMask | (UFG::ParkourComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ParkourComponent::_TypeIDesc;
}

// File Line: 55
// RVA: 0x2FDBF0
void __fastcall UFG::ParkourComponent::Disable(UFG::ParkourComponent *this, UFG::ParkourData *data)
{
  UFG::ParkourData *v2; // rdi
  UFG::ParkourComponent *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  signed __int64 v5; // rdi
  int *v6; // r8
  signed int v7; // edx

  v2 = data;
  v3 = this;
  if ( data )
  {
    if ( !this->mDisabledBits )
    {
      v4 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      if ( v4 )
        UFG::BitArray::BitArray((UFG::BitArray *)v4, v3->mParkourContainer.mData[1].mTypeUID);
      v3->mDisabledBits = (UFG::BitArray *)v4;
    }
    v5 = (char *)v2 - (char *)v3->mParkourContainer.mData[1].mResourceHandles.mNode.mPrev;
    v6 = (int *)&v3->mDisabledBits->mData[((unsigned int)((unsigned __int128)(v5
                                                                            * (signed __int128)3074457345618258603i64) >> 64)
                                         + ((unsigned __int64)((unsigned __int128)(v5
                                                                                 * (signed __int128)3074457345618258603i64) >> 64) >> 63)) >> 5];
    v7 = 1 << (((unsigned __int64)((unsigned __int128)(v5 * (signed __int128)3074457345618258603i64) >> 64)
              + ((((unsigned __int128)(v5 * (signed __int128)3074457345618258603i64) >> 64) & 0x8000000000000000ui64) != 0i64)) & 0x1F);
    *v6 = v7 | *v6 & ~v7;
  }
  else
  {
    this->mFlags |= 8u;
  }
}

