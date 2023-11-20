// File Line: 24
// RVA: 0x51F410
UFG::ComponentIDDesc *__fastcall UFG::NISScriptSystemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::NISScriptSystemComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::NISScriptSystemComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::NISScriptSystemComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::NISScriptSystemComponent::_DescInit = 1;
    UFG::NISScriptSystemComponent::_TypeUID = UFG::NISScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::NISScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::NISScriptSystemComponent::_NISScriptSystemComponentTypeUID = UFG::NISScriptSystemComponent::_TypeIDesc.mChildBitMask | (UFG::NISScriptSystemComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::NISScriptSystemComponent::_TypeIDesc;
}

