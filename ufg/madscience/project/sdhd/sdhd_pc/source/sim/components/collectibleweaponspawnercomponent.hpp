// File Line: 26
// RVA: 0x51ECD0
UFG::ComponentIDDesc *__fastcall UFG::CollectibleWeaponSpawnerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CollectibleWeaponSpawnerComponent::_DescInit )
  {
    v0 = UFG::CollectibleComponent::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CollectibleWeaponSpawnerComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CollectibleWeaponSpawnerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CollectibleWeaponSpawnerComponent::_TypeIDesc.mChildren = 0;
    UFG::CollectibleWeaponSpawnerComponent::_DescInit = 1;
    UFG::CollectibleWeaponSpawnerComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CollectibleWeaponSpawnerComponent::_CollectibleWeaponSpawnerComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CollectibleWeaponSpawnerComponent::_TypeIDesc;
}

