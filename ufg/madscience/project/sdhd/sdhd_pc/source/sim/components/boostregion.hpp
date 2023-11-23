// File Line: 50
// RVA: 0x51E9B0
UFG::ComponentIDDesc *__fastcall UFG::BoostRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::BoostRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BoostRegion::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::BoostRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::BoostRegion::_TypeIDesc.mChildren = 0;
    UFG::BoostRegion::_DescInit = 1;
    UFG::BoostRegion::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::BoostRegion::_BoostRegionTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::BoostRegion::_TypeIDesc;
}

// File Line: 63
// RVA: 0x532330
__int64 __fastcall UFG::BoostRegion::GetType(UFG::BoostRegion *this)
{
  return 0x2000000i64;
}

