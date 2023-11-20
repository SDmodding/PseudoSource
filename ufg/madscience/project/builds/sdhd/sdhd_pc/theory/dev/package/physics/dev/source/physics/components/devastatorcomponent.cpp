// File Line: 1070
// RVA: 0x1458DA0
__int64 dynamic_initializer_for__UFG::DevastatorComponent::s_DevastatorComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DevastatorComponent::s_DevastatorComponentList__);
}

// File Line: 1071
// RVA: 0x1458370
__int64 dynamic_initializer_for__UFG::DevastatorComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::DevastatorComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::DevastatorComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::DevastatorComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::DevastatorComponent::_TypeIDesc.mChildren = result;
  return result;
}

