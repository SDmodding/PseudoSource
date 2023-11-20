// File Line: 26
// RVA: 0x72FF0
UFG::ComponentIDDesc *__fastcall Render::DynamicLightComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !Render::DynamicLightComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&Render::DynamicLightComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    Render::DynamicLightComponent::_TypeIDesc.mChildren = v0->mChildren;
    Render::DynamicLightComponent::_DescInit = 1;
    Render::DynamicLightComponent::_TypeUID = Render::DynamicLightComponent::_TypeIDesc.mChildBitMask | (Render::DynamicLightComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::DynamicLightComponent::_DynamicLightComponentTypeUID = Render::DynamicLightComponent::_TypeIDesc.mChildBitMask | (Render::DynamicLightComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::DynamicLightComponent::_TypeIDesc;
}

