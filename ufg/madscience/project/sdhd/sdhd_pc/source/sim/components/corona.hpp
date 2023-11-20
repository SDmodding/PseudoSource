// File Line: 39
// RVA: 0x57E9F0
UFG::ComponentIDDesc *__fastcall UFG::Corona::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::Corona::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::Corona::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::Corona::_TypeIDesc.mChildBitMask = v1;
    UFG::Corona::_TypeIDesc.mChildren = 0;
    UFG::Corona::_DescInit = 1;
    UFG::Corona::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::Corona::_CoronaTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::Corona::_TypeIDesc;
}

// File Line: 49
// RVA: 0x582950
signed __int64 __fastcall UFG::Corona::GetType(UFG::Corona *this)
{
  return 0x400000i64;
}

