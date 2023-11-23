// File Line: 42
// RVA: 0x51ED60
UFG::ComponentIDDesc *__fastcall UFG::CombatRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CombatRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CombatRegion::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CombatRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::CombatRegion::_TypeIDesc.mChildren = 0;
    UFG::CombatRegion::_DescInit = 1;
    UFG::CombatRegion::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CombatRegion::_CombatRegionTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CombatRegion::_TypeIDesc;
}

// File Line: 48
// RVA: 0x532340
__int64 __fastcall UFG::CombatRegion::GetType(UFG::CombatRegion *this)
{
  return 0x10000i64;
}

