// File Line: 26
// RVA: 0x72FF0
UFG::ComponentIDDesc *__fastcall Render::DynamicLightComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !Render::DynamicLightComponent::_DescInit )
  {
    Render::DynamicLightComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    Render::DynamicLightComponent::_DescInit = 1;
    Render::DynamicLightComponent::_TypeUID = Render::DynamicLightComponent::_TypeIDesc.mChildBitMask | (Render::DynamicLightComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::DynamicLightComponent::_DynamicLightComponentTypeUID = Render::DynamicLightComponent::_TypeIDesc.mChildBitMask | (Render::DynamicLightComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::DynamicLightComponent::_TypeIDesc;
}

