// File Line: 28
// RVA: 0x154DAA0
__int64 dynamic_initializer_for__UFG::RecorderInterface::s_RecorderInterfaceList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RecorderInterface::s_RecorderInterfaceList__);
}

// File Line: 29
// RVA: 0x154D6A0
__int64 dynamic_initializer_for__UFG::RecorderInterface::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::RecorderInterface::AccessComponentDesc();
  *(_DWORD *)&UFG::RecorderInterface::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::RecorderInterface::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::RecorderInterface::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 44
// RVA: 0x154DAC0
__int64 dynamic_initializer_for__UFG::SplineRecorderComponent::s_SplineRecorderComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SplineRecorderComponent::s_SplineRecorderComponentList__);
}

// File Line: 45
// RVA: 0x154D700
__int64 dynamic_initializer_for__UFG::SplineRecorderComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::SplineRecorderComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::SplineRecorderComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::SplineRecorderComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::SplineRecorderComponent::_TypeIDesc.mChildren = result;
  return result;
}

