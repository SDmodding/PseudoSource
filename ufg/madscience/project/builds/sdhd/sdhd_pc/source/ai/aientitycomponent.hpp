// File Line: 103
// RVA: 0x33EE90
UFG::ComponentIDDesc *__fastcall UFG::AIEntityComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIEntityComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AIEntityComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AIEntityComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AIEntityComponent::_DescInit = 1;
    UFG::AIEntityComponent::_TypeUID = UFG::AIEntityComponent::_TypeIDesc.mChildBitMask | (UFG::AIEntityComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AIEntityComponent::_AIEntityComponentTypeUID = UFG::AIEntityComponent::_TypeIDesc.mChildBitMask | (UFG::AIEntityComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AIEntityComponent::_TypeIDesc;
}

// File Line: 227
// RVA: 0x33F0E0
UFG::ComponentIDDesc *__fastcall UFG::ActiveAIEntityComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::ActiveAIEntityComponent::_DescInit )
  {
    v0 = UFG::AIEntityComponent::AccessComponentDesc();
    ++UFG::AIEntityComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AIEntityComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ActiveAIEntityComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::ActiveAIEntityComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ActiveAIEntityComponent::_TypeIDesc.mChildren = 0;
    UFG::ActiveAIEntityComponent::_DescInit = 1;
    UFG::ActiveAIEntityComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::ActiveAIEntityComponent::_ActiveAIEntityComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::ActiveAIEntityComponent::_TypeIDesc;
}

