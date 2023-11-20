// File Line: 26
// RVA: 0x73D10
UFG::ComponentIDDesc *__fastcall Render::IrradianceVolumeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !Render::IrradianceVolumeComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&Render::IrradianceVolumeComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    Render::IrradianceVolumeComponent::_TypeIDesc.mChildren = v0->mChildren;
    Render::IrradianceVolumeComponent::_DescInit = 1;
    Render::IrradianceVolumeComponent::_TypeUID = Render::IrradianceVolumeComponent::_TypeIDesc.mChildBitMask | (Render::IrradianceVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::IrradianceVolumeComponent::_IrradianceVolumeComponentTypeUID = Render::IrradianceVolumeComponent::_TypeIDesc.mChildBitMask | (Render::IrradianceVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::IrradianceVolumeComponent::_TypeIDesc;
}

