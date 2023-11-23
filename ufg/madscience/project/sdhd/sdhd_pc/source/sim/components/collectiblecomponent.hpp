// File Line: 23
// RVA: 0x51EBB0
UFG::ComponentIDDesc *__fastcall UFG::CollectibleComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CollectibleComponent::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CollectibleComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CollectibleComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CollectibleComponent::_TypeIDesc.mChildren = 0;
    UFG::CollectibleComponent::_DescInit = 1;
    UFG::CollectibleComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CollectibleComponent::_CollectibleComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CollectibleComponent::_TypeIDesc;
}

