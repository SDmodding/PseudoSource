// File Line: 23
// RVA: 0x51EBB0
UFG::ComponentIDDesc *__fastcall UFG::CollectibleComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CollectibleComponent::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CollectibleComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CollectibleComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CollectibleComponent::_TypeIDesc.mChildren = 0;
    UFG::CollectibleComponent::_DescInit = 1;
    UFG::CollectibleComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CollectibleComponent::_CollectibleComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CollectibleComponent::_TypeIDesc;
}

