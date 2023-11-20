// File Line: 33
// RVA: 0x220D20
UFG::ComponentIDDesc *__fastcall UFG::ModelAssetComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::ModelAssetComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::ModelAssetComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::ModelAssetComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::ModelAssetComponent::_DescInit = 1;
    UFG::ModelAssetComponent::_TypeUID = UFG::ModelAssetComponent::_TypeIDesc.mChildBitMask | (UFG::ModelAssetComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ModelAssetComponent::_ModelAssetComponentTypeUID = UFG::ModelAssetComponent::_TypeIDesc.mChildBitMask | (UFG::ModelAssetComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ModelAssetComponent::_TypeIDesc;
}

