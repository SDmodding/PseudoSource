// File Line: 94
// RVA: 0x33F070
UFG::ComponentIDDesc *__fastcall UFG::AIScriptInterfaceComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AIScriptInterfaceComponent::_DescInit )
  {
    UFG::AIScriptInterfaceComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AIScriptInterfaceComponent::_DescInit = 1;
    UFG::AIScriptInterfaceComponent::_TypeUID = UFG::AIScriptInterfaceComponent::_TypeIDesc.mChildBitMask | (UFG::AIScriptInterfaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIScriptInterfaceComponent::_AIScriptInterfaceComponentTypeUID = UFG::AIScriptInterfaceComponent::_TypeIDesc.mChildBitMask | (UFG::AIScriptInterfaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIScriptInterfaceComponent::_TypeIDesc;
}

