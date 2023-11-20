// File Line: 42
// RVA: 0x51ED60
UFG::ComponentIDDesc *__fastcall UFG::CombatRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CombatRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CombatRegion::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CombatRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::CombatRegion::_TypeIDesc.mChildren = 0;
    UFG::CombatRegion::_DescInit = 1;
    UFG::CombatRegion::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CombatRegion::_CombatRegionTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CombatRegion::_TypeIDesc;
}

// File Line: 48
// RVA: 0x532340
signed __int64 __fastcall UFG::CombatRegion::GetType(UFG::CombatRegion *this)
{
  return 0x10000i64;
}

