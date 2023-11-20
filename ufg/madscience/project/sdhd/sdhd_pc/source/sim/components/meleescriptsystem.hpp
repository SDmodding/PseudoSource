// File Line: 24
// RVA: 0x51F330
UFG::ComponentIDDesc *__fastcall UFG::MeleeScriptSystemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::MeleeScriptSystemComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::MeleeScriptSystemComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::MeleeScriptSystemComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::MeleeScriptSystemComponent::_DescInit = 1;
    UFG::MeleeScriptSystemComponent::_TypeUID = UFG::MeleeScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::MeleeScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::MeleeScriptSystemComponent::_MeleeScriptSystemComponentTypeUID = UFG::MeleeScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::MeleeScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::MeleeScriptSystemComponent::_TypeIDesc;
}

