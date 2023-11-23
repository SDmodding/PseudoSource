// File Line: 38
// RVA: 0x4544A0
UFG::ComponentIDDesc *__fastcall UFG::WaterPhantomComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::WaterPhantomComponent::_DescInit )
  {
    UFG::WaterPhantomComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::WaterPhantomComponent::_DescInit = 1;
    UFG::WaterPhantomComponent::_TypeUID = UFG::WaterPhantomComponent::_TypeIDesc.mChildBitMask | (UFG::WaterPhantomComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::WaterPhantomComponent::_WaterPhantomComponentTypeUID = UFG::WaterPhantomComponent::_TypeIDesc.mChildBitMask | (UFG::WaterPhantomComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::WaterPhantomComponent::_TypeIDesc;
}

