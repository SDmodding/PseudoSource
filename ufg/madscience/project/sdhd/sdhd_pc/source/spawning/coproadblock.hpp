// File Line: 34
// RVA: 0x5B23E0
UFG::ComponentIDDesc *__fastcall UFG::CopRoadBlock::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CopRoadBlock::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CopRoadBlock::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CopRoadBlock::_TypeIDesc.mChildBitMask = v1;
    UFG::CopRoadBlock::_TypeIDesc.mChildren = 0;
    UFG::CopRoadBlock::_DescInit = 1;
    UFG::CopRoadBlock::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CopRoadBlock::_CopRoadBlockTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CopRoadBlock::_TypeIDesc;
}

// File Line: 38
// RVA: 0x5B4240
signed __int64 __fastcall UFG::CopRoadBlock::GetType(UFG::CopRoadBlock *this)
{
  return 2048i64;
}

