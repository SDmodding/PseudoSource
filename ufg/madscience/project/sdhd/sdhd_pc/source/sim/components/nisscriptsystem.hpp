// File Line: 24
// RVA: 0x51F410
UFG::ComponentIDDesc *__fastcall UFG::NISScriptSystemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::NISScriptSystemComponent::_DescInit )
  {
    UFG::NISScriptSystemComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::NISScriptSystemComponent::_DescInit = 1;
    UFG::NISScriptSystemComponent::_TypeUID = UFG::NISScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::NISScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::NISScriptSystemComponent::_NISScriptSystemComponentTypeUID = UFG::NISScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::NISScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::NISScriptSystemComponent::_TypeIDesc;
}

