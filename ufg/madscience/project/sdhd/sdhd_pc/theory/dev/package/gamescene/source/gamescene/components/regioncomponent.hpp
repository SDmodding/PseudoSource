// File Line: 41
// RVA: 0x239210
UFG::ComponentIDDesc *__fastcall UFG::RegionComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::RegionComponent::_DescInit )
  {
    v0 = UFG::HintComponentBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::RegionComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::RegionComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::RegionComponent::_TypeIDesc.mChildren = 0;
    UFG::RegionComponent::_DescInit = 1;
    UFG::RegionComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::RegionComponent::_RegionComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::RegionComponent::_TypeIDesc;
}

// File Line: 86
// RVA: 0x23E7E0
__int64 __fastcall UFG::RegionComponent::InsertAspect(UFG::RegionComponent *this, __int64 aspect)
{
  return this->mpRegion.mPtr->vfptr->InsertAspect(this->mpRegion.mPtr, aspect);
}

// File Line: 88
// RVA: 0x245070
__int64 __fastcall UFG::RegionComponent::RemoveAspect(UFG::RegionComponent *this, __int64 aspect)
{
  return this->mpRegion.mPtr->vfptr->RemoveAspect(this->mpRegion.mPtr, aspect);
}

