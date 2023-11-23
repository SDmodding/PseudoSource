// File Line: 21
// RVA: 0x418E80
UFG::ComponentIDDesc *__fastcall UFG::StartRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::StartRegion::_DescInit )
  {
    v0 = UFG::TriggerRegion::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::StartRegion::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::StartRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::StartRegion::_TypeIDesc.mChildren = 0;
    UFG::StartRegion::_DescInit = 1;
    UFG::StartRegion::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::StartRegion::_StartRegionTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::StartRegion::_TypeIDesc;
}

