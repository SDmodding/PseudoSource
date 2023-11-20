// File Line: 38
// RVA: 0x4544A0
UFG::ComponentIDDesc *__fastcall UFG::WaterPhantomComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::WaterPhantomComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::WaterPhantomComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::WaterPhantomComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::WaterPhantomComponent::_DescInit = 1;
    UFG::WaterPhantomComponent::_TypeUID = UFG::WaterPhantomComponent::_TypeIDesc.mChildBitMask | (UFG::WaterPhantomComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::WaterPhantomComponent::_WaterPhantomComponentTypeUID = UFG::WaterPhantomComponent::_TypeIDesc.mChildBitMask | (UFG::WaterPhantomComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::WaterPhantomComponent::_TypeIDesc;
}

