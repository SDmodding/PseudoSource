// File Line: 53
// RVA: 0x17A0
UFG::ComponentIDDesc *__fastcall Render::SimpleDrawableComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !Render::SimpleDrawableComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&Render::SimpleDrawableComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    Render::SimpleDrawableComponent::_TypeIDesc.mChildren = v0->mChildren;
    Render::SimpleDrawableComponent::_DescInit = 1;
    Render::SimpleDrawableComponent::_TypeUID = Render::SimpleDrawableComponent::_TypeIDesc.mChildBitMask | (Render::SimpleDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::SimpleDrawableComponent::_SimpleDrawableComponentTypeUID = Render::SimpleDrawableComponent::_TypeIDesc.mChildBitMask | (Render::SimpleDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::SimpleDrawableComponent::_TypeIDesc;
}

