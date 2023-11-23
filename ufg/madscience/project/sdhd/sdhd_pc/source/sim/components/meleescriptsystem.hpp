// File Line: 24
// RVA: 0x51F330
UFG::ComponentIDDesc *__fastcall UFG::MeleeScriptSystemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::MeleeScriptSystemComponent::_DescInit )
  {
    UFG::MeleeScriptSystemComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::MeleeScriptSystemComponent::_DescInit = 1;
    UFG::MeleeScriptSystemComponent::_TypeUID = UFG::MeleeScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::MeleeScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::MeleeScriptSystemComponent::_MeleeScriptSystemComponentTypeUID = UFG::MeleeScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::MeleeScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::MeleeScriptSystemComponent::_TypeIDesc;
}

