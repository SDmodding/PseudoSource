// File Line: 41
// RVA: 0x5B2590
UFG::ComponentIDDesc *__fastcall UFG::TrafficRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TrafficRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TrafficRegion::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TrafficRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::TrafficRegion::_TypeIDesc.mChildren = 0;
    UFG::TrafficRegion::_DescInit = 1;
    UFG::TrafficRegion::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TrafficRegion::_TrafficRegionTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TrafficRegion::_TypeIDesc;
}

