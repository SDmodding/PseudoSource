// File Line: 26
// RVA: 0x73D10
UFG::ComponentIDDesc *__fastcall Render::IrradianceVolumeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !Render::IrradianceVolumeComponent::_DescInit )
  {
    Render::IrradianceVolumeComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    Render::IrradianceVolumeComponent::_DescInit = 1;
    Render::IrradianceVolumeComponent::_TypeUID = Render::IrradianceVolumeComponent::_TypeIDesc.mChildBitMask | (Render::IrradianceVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::IrradianceVolumeComponent::_IrradianceVolumeComponentTypeUID = Render::IrradianceVolumeComponent::_TypeIDesc.mChildBitMask | (Render::IrradianceVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::IrradianceVolumeComponent::_TypeIDesc;
}

