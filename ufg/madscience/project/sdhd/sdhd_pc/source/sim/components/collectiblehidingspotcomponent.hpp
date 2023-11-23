// File Line: 23
// RVA: 0x51EC40
UFG::ComponentIDDesc *__fastcall UFG::CollectibleHidingSpotComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CollectibleHidingSpotComponent::_DescInit )
  {
    v0 = UFG::CollectibleComponent::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CollectibleHidingSpotComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CollectibleHidingSpotComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CollectibleHidingSpotComponent::_TypeIDesc.mChildren = 0;
    UFG::CollectibleHidingSpotComponent::_DescInit = 1;
    UFG::CollectibleHidingSpotComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CollectibleHidingSpotComponent::_CollectibleHidingSpotComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CollectibleHidingSpotComponent::_TypeIDesc;
}

