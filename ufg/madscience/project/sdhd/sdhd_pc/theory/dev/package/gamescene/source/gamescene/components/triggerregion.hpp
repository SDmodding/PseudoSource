// File Line: 126
// RVA: 0x239310
UFG::ComponentIDDesc *__fastcall UFG::TriggerRegion::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TriggerRegion::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TriggerRegion::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TriggerRegion::_TypeIDesc.mChildBitMask = v1;
    UFG::TriggerRegion::_TypeIDesc.mChildren = 0;
    UFG::TriggerRegion::_DescInit = 1;
    UFG::TriggerRegion::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TriggerRegion::_TriggerRegionTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TriggerRegion::_TypeIDesc;
}

