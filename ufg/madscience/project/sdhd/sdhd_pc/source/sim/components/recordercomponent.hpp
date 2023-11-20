// File Line: 31
// RVA: 0x57EC80
UFG::ComponentIDDesc *__fastcall UFG::RecorderInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RecorderInterface::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RecorderInterface::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RecorderInterface::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RecorderInterface::_DescInit = 1;
    UFG::RecorderInterface::_TypeUID = UFG::RecorderInterface::_TypeIDesc.mChildBitMask | (UFG::RecorderInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RecorderInterface::_RecorderInterfaceTypeUID = UFG::RecorderInterface::_TypeIDesc.mChildBitMask | (UFG::RecorderInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RecorderInterface::_TypeIDesc;
}

// File Line: 60
// RVA: 0x57ED80
UFG::ComponentIDDesc *__fastcall UFG::SplineRecorderComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::SplineRecorderComponent::_DescInit )
  {
    v0 = UFG::RecorderInterface::AccessComponentDesc();
    ++UFG::RecorderInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RecorderInterface::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SplineRecorderComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::SplineRecorderComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::SplineRecorderComponent::_TypeIDesc.mChildren = 0;
    UFG::SplineRecorderComponent::_DescInit = 1;
    UFG::SplineRecorderComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::SplineRecorderComponent::_SplineRecorderComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::SplineRecorderComponent::_TypeIDesc;
}

