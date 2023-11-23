// File Line: 31
// RVA: 0x454150
UFG::ComponentIDDesc *__fastcall UFG::PhantomVolumeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PhantomVolumeComponent::_DescInit )
  {
    UFG::PhantomVolumeComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PhantomVolumeComponent::_DescInit = 1;
    UFG::PhantomVolumeComponent::_TypeUID = UFG::PhantomVolumeComponent::_TypeIDesc.mChildBitMask | (UFG::PhantomVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID = UFG::PhantomVolumeComponent::_TypeIDesc.mChildBitMask | (UFG::PhantomVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PhantomVolumeComponent::_TypeIDesc;
}

