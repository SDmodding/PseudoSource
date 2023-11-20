// File Line: 94
// RVA: 0x33F070
UFG::ComponentIDDesc *__fastcall UFG::AIScriptInterfaceComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIScriptInterfaceComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AIScriptInterfaceComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AIScriptInterfaceComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AIScriptInterfaceComponent::_DescInit = 1;
    UFG::AIScriptInterfaceComponent::_TypeUID = UFG::AIScriptInterfaceComponent::_TypeIDesc.mChildBitMask | (UFG::AIScriptInterfaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIScriptInterfaceComponent::_AIScriptInterfaceComponentTypeUID = UFG::AIScriptInterfaceComponent::_TypeIDesc.mChildBitMask | (UFG::AIScriptInterfaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIScriptInterfaceComponent::_TypeIDesc;
}

