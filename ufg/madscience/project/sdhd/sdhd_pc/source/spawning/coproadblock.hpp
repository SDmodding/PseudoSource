// File Line: 34
// RVA: 0x5B23E0
UFG::ComponentIDDesc *__fastcall UFG::CopRoadBlock::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CopRoadBlock::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CopRoadBlock::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CopRoadBlock::_TypeIDesc.mChildBitMask = v1;
    UFG::CopRoadBlock::_TypeIDesc.mChildren = 0;
    UFG::CopRoadBlock::_DescInit = 1;
    UFG::CopRoadBlock::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CopRoadBlock::_CopRoadBlockTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CopRoadBlock::_TypeIDesc;
}

// File Line: 38
// RVA: 0x5B4240
__int64 __fastcall UFG::CopRoadBlock::GetType(UFG::CopRoadBlock *this)
{
  return 2048i64;
}

