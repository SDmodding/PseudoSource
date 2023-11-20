// File Line: 20
// RVA: 0x1C53C0
UFG::ComponentIDDesc *__fastcall Render::FXSimComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !Render::FXSimComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&Render::FXSimComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    Render::FXSimComponent::_TypeIDesc.mChildren = v0->mChildren;
    Render::FXSimComponent::_DescInit = 1;
    Render::FXSimComponent::_TypeUID = Render::FXSimComponent::_TypeIDesc.mChildBitMask | (Render::FXSimComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::FXSimComponent::_FXSimComponentTypeUID = Render::FXSimComponent::_TypeIDesc.mChildBitMask | (Render::FXSimComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::FXSimComponent::_TypeIDesc;
}

