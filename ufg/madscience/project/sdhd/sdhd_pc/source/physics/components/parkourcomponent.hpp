// File Line: 28
// RVA: 0x4540E0
UFG::ComponentIDDesc *__fastcall UFG::ParkourComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::ParkourComponent::_DescInit )
  {
    UFG::ParkourComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
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
  UFG::allocator::free_link *v4; // rax
  signed __int64 v5; // rdi
  unsigned int *v6; // r8

  if ( data )
  {
    if ( !this->mDisabledBits )
    {
      v4 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      if ( v4 )
        UFG::BitArray::BitArray((UFG::BitArray *)v4, this->mParkourContainer.mData[1].mTypeUID);
      this->mDisabledBits = (UFG::BitArray *)v4;
    }
    v5 = (char *)data - (char *)this->mParkourContainer.mData[1].mResourceHandles.mNode.mPrev;
    v6 = &this->mDisabledBits->mData[(unsigned int)((int)v5 / 6) >> 5];
    *v6 = (1 << (((int)v5 / 6) & 0x1F)) | *v6 & ~(1 << (((int)v5 / 6) & 0x1F));
  }
  else
  {
    this->mFlags |= 8u;
  }
}

