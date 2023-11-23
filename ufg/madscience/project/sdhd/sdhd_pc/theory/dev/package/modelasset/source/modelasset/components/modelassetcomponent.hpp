// File Line: 33
// RVA: 0x220D20
UFG::ComponentIDDesc *__fastcall UFG::ModelAssetComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::ModelAssetComponent::_DescInit )
  {
    UFG::ModelAssetComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::ModelAssetComponent::_DescInit = 1;
    UFG::ModelAssetComponent::_TypeUID = UFG::ModelAssetComponent::_TypeIDesc.mChildBitMask | (UFG::ModelAssetComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ModelAssetComponent::_ModelAssetComponentTypeUID = UFG::ModelAssetComponent::_TypeIDesc.mChildBitMask | (UFG::ModelAssetComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ModelAssetComponent::_TypeIDesc;
}

