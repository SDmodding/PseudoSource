// File Line: 69
// RVA: 0x57ECF0
UFG::ComponentIDDesc *__fastcall UFG::SpawnPoint::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::SpawnPoint::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SpawnPoint::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::SpawnPoint::_TypeIDesc.mChildBitMask = v1;
    UFG::SpawnPoint::_TypeIDesc.mChildren = 0;
    UFG::SpawnPoint::_DescInit = 1;
    UFG::SpawnPoint::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::SpawnPoint::_SpawnPointTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::SpawnPoint::_TypeIDesc;
}

