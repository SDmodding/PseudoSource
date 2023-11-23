// File Line: 103
// RVA: 0x33EE90
UFG::ComponentIDDesc *__fastcall UFG::AIEntityComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AIEntityComponent::_DescInit )
  {
    UFG::AIEntityComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
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
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::ActiveAIEntityComponent::_DescInit )
  {
    v0 = UFG::AIEntityComponent::AccessComponentDesc();
    ++UFG::AIEntityComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AIEntityComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ActiveAIEntityComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::ActiveAIEntityComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ActiveAIEntityComponent::_TypeIDesc.mChildren = 0;
    UFG::ActiveAIEntityComponent::_DescInit = 1;
    UFG::ActiveAIEntityComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::ActiveAIEntityComponent::_ActiveAIEntityComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::ActiveAIEntityComponent::_TypeIDesc;
}

