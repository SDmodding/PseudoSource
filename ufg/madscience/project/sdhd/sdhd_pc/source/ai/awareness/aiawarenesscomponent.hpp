// File Line: 29
// RVA: 0x39A670
UFG::ComponentIDDesc *__fastcall UFG::AIAwarenessComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIAwarenessComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AIAwarenessComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AIAwarenessComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AIAwarenessComponent::_DescInit = 1;
    UFG::AIAwarenessComponent::_TypeUID = UFG::AIAwarenessComponent::_TypeIDesc.mChildBitMask | (UFG::AIAwarenessComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIAwarenessComponent::_AIAwarenessComponentTypeUID = UFG::AIAwarenessComponent::_TypeIDesc.mChildBitMask | (UFG::AIAwarenessComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIAwarenessComponent::_TypeIDesc;
}

