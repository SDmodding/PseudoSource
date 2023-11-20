// File Line: 50
// RVA: 0x51E9B0
UFG::ComponentIDDesc *__fastcall UFG::BoostRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::BoostRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BoostRegion::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::BoostRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::BoostRegion::_TypeIDesc.mChildren = 0;
    UFG::BoostRegion::_DescInit = 1;
    UFG::BoostRegion::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::BoostRegion::_BoostRegionTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::BoostRegion::_TypeIDesc;
}

// File Line: 63
// RVA: 0x532330
signed __int64 __fastcall UFG::BoostRegion::GetType(UFG::BoostRegion *this)
{
  return 0x2000000i64;
}

