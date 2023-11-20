// File Line: 31
// RVA: 0x454150
UFG::ComponentIDDesc *__fastcall UFG::PhantomVolumeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PhantomVolumeComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PhantomVolumeComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PhantomVolumeComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PhantomVolumeComponent::_DescInit = 1;
    UFG::PhantomVolumeComponent::_TypeUID = UFG::PhantomVolumeComponent::_TypeIDesc.mChildBitMask | (UFG::PhantomVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PhantomVolumeComponent::_PhantomVolumeComponentTypeUID = UFG::PhantomVolumeComponent::_TypeIDesc.mChildBitMask | (UFG::PhantomVolumeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PhantomVolumeComponent::_TypeIDesc;
}

