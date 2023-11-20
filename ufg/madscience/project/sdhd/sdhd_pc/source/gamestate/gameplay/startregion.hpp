// File Line: 21
// RVA: 0x418E80
UFG::ComponentIDDesc *__fastcall UFG::StartRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::StartRegion::_DescInit )
  {
    v0 = UFG::TriggerRegion::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::StartRegion::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::StartRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::StartRegion::_TypeIDesc.mChildren = 0;
    UFG::StartRegion::_DescInit = 1;
    UFG::StartRegion::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::StartRegion::_StartRegionTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::StartRegion::_TypeIDesc;
}

