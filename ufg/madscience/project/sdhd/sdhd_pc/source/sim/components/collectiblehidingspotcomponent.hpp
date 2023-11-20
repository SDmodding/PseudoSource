// File Line: 23
// RVA: 0x51EC40
UFG::ComponentIDDesc *__fastcall UFG::CollectibleHidingSpotComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CollectibleHidingSpotComponent::_DescInit )
  {
    v0 = UFG::CollectibleComponent::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CollectibleHidingSpotComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CollectibleHidingSpotComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CollectibleHidingSpotComponent::_TypeIDesc.mChildren = 0;
    UFG::CollectibleHidingSpotComponent::_DescInit = 1;
    UFG::CollectibleHidingSpotComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CollectibleHidingSpotComponent::_CollectibleHidingSpotComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CollectibleHidingSpotComponent::_TypeIDesc;
}

