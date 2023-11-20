// File Line: 47
// RVA: 0x57E860
UFG::ComponentIDDesc *__fastcall UFG::CharacterAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterAnimationComponent::_DescInit )
  {
    v0 = UFG::BaseAnimationComponent::AccessComponentDesc();
    ++UFG::BaseAnimationComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseAnimationComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::CharacterAnimationComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CharacterAnimationComponent::_TypeIDesc.mChildren = 0;
    UFG::CharacterAnimationComponent::_DescInit = 1;
    UFG::CharacterAnimationComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::CharacterAnimationComponent::_CharacterAnimationComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::CharacterAnimationComponent::_TypeIDesc;
}

// File Line: 101
// RVA: 0x57DFD0
void __fastcall UFG::ActiveAIEntityComponent::operator delete(void *ptr, unsigned __int64 size)
{
  void *v2; // rbx
  UFG::qMemoryPool *v3; // rax

  v2 = ptr;
  v3 = UFG::GetSimulationMemoryPool();
  UFG::qMemoryPool::Free(v3, v2);
}

// File Line: 139
// RVA: 0x57EBA0
UFG::ComponentIDDesc *__fastcall UFG::LightGroupComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::LightGroupComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::LightGroupComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::LightGroupComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::LightGroupComponent::_DescInit = 1;
    UFG::LightGroupComponent::_TypeUID = UFG::LightGroupComponent::_TypeIDesc.mChildBitMask | (UFG::LightGroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::LightGroupComponent::_LightGroupComponentTypeUID = UFG::LightGroupComponent::_TypeIDesc.mChildBitMask | (UFG::LightGroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::LightGroupComponent::_TypeIDesc;
}

// File Line: 173
// RVA: 0x57EB10
UFG::ComponentIDDesc *__fastcall UFG::LightGroupAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::LightGroupAnimationComponent::_DescInit )
  {
    v0 = UFG::BaseAnimationComponent::AccessComponentDesc();
    ++UFG::BaseAnimationComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::BaseAnimationComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::LightGroupAnimationComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::LightGroupAnimationComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::LightGroupAnimationComponent::_TypeIDesc.mChildren = 0;
    UFG::LightGroupAnimationComponent::_DescInit = 1;
    UFG::LightGroupAnimationComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::LightGroupAnimationComponent::_LightGroupAnimationComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::LightGroupAnimationComponent::_TypeIDesc;
}

