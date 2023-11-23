// File Line: 29
// RVA: 0x39A670
UFG::ComponentIDDesc *__fastcall UFG::AIAwarenessComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AIAwarenessComponent::_DescInit )
  {
    UFG::AIAwarenessComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AIAwarenessComponent::_DescInit = 1;
    UFG::AIAwarenessComponent::_TypeUID = UFG::AIAwarenessComponent::_TypeIDesc.mChildBitMask | (UFG::AIAwarenessComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIAwarenessComponent::_AIAwarenessComponentTypeUID = UFG::AIAwarenessComponent::_TypeIDesc.mChildBitMask | (UFG::AIAwarenessComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIAwarenessComponent::_TypeIDesc;
}

