// File Line: 20
// RVA: 0x1C53C0
UFG::ComponentIDDesc *__fastcall Render::FXSimComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !Render::FXSimComponent::_DescInit )
  {
    Render::FXSimComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    Render::FXSimComponent::_DescInit = 1;
    Render::FXSimComponent::_TypeUID = Render::FXSimComponent::_TypeIDesc.mChildBitMask | (Render::FXSimComponent::_TypeIDesc.mBaseTypeIndex << 25);
    Render::FXSimComponent::_FXSimComponentTypeUID = Render::FXSimComponent::_TypeIDesc.mChildBitMask | (Render::FXSimComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &Render::FXSimComponent::_TypeIDesc;
}

