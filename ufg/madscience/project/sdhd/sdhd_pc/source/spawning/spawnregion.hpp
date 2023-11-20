// File Line: 44
// RVA: 0x5B2500
UFG::ComponentIDDesc *__fastcall UFG::SpawnRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::SpawnRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SpawnRegion::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::SpawnRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::SpawnRegion::_TypeIDesc.mChildren = 0;
    UFG::SpawnRegion::_DescInit = 1;
    UFG::SpawnRegion::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::SpawnRegion::_SpawnRegionTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::SpawnRegion::_TypeIDesc;
}

