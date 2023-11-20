// File Line: 31
// RVA: 0x33EFE0
UFG::ComponentIDDesc *__fastcall UFG::AIOutlineRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIOutlineRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AIOutlineRegion::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::AIOutlineRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::AIOutlineRegion::_TypeIDesc.mChildren = 0;
    UFG::AIOutlineRegion::_DescInit = 1;
    UFG::AIOutlineRegion::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::AIOutlineRegion::_AIOutlineRegionTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::AIOutlineRegion::_TypeIDesc;
}

// File Line: 36
// RVA: 0x363290
signed __int64 __fastcall UFG::AIOutlineRegion::GetType(UFG::AIOutlineRegion *this)
{
  return 0x80000i64;
}

