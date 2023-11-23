// File Line: 95
// RVA: 0x22FE60
UFG::ComponentIDDesc *__fastcall UFG::DynamicSceneryInstance::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DynamicSceneryInstance::_DescInit )
  {
    UFG::DynamicSceneryInstance::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::DynamicSceneryInstance::_DescInit = 1;
    UFG::DynamicSceneryInstance::_TypeUID = UFG::DynamicSceneryInstance::_TypeIDesc.mChildBitMask | (UFG::DynamicSceneryInstance::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DynamicSceneryInstance::_DynamicSceneryInstanceTypeUID = UFG::DynamicSceneryInstance::_TypeIDesc.mChildBitMask | (UFG::DynamicSceneryInstance::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DynamicSceneryInstance::_TypeIDesc;
}

