// File Line: 34
// RVA: 0x454410
UFG::ComponentIDDesc *__fastcall UFG::WaterFloatingTrackerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::WaterFloatingTrackerComponent::_DescInit )
  {
    v0 = UFG::WaterFloatingTrackerBaseComponent::AccessComponentDesc();
    ++UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::WaterFloatingTrackerComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::WaterFloatingTrackerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::WaterFloatingTrackerComponent::_TypeIDesc.mChildren = 0;
    UFG::WaterFloatingTrackerComponent::_DescInit = 1;
    UFG::WaterFloatingTrackerComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::WaterFloatingTrackerComponent::_TypeIDesc;
}

