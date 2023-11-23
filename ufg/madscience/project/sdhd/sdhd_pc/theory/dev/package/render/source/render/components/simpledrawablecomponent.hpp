// File Line: 53
// RVA: 0x17A0
UFG::ComponentIDDesc *__fastcall Render::SimpleDrawableComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !Render::SimpleDrawableComponent::_DescInit )
  {
    Render::SimpleDrawableComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    Render::SimpleDrawableComponent::_DescInit = 1;
    Render::SimpleDrawableComponent::_TypeUID = Render::SimpleDrawableComponent::_TypeIDesc.mChildBitMask | (Render::SimpleDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::SimpleDrawableComponent::_SimpleDrawableComponentTypeUID = Render::SimpleDrawableComponent::_TypeIDesc.mChildBitMask | (Render::SimpleDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::SimpleDrawableComponent::_TypeIDesc;
}

