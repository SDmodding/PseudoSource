// File Line: 95
// RVA: 0x22FE60
UFG::ComponentIDDesc *__fastcall UFG::DynamicSceneryInstance::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::DynamicSceneryInstance::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::DynamicSceneryInstance::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::DynamicSceneryInstance::_TypeIDesc.mChildren = v0->mChildren;
    UFG::DynamicSceneryInstance::_DescInit = 1;
    UFG::DynamicSceneryInstance::_TypeUID = UFG::DynamicSceneryInstance::_TypeIDesc.mChildBitMask | (UFG::DynamicSceneryInstance::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DynamicSceneryInstance::_DynamicSceneryInstanceTypeUID = UFG::DynamicSceneryInstance::_TypeIDesc.mChildBitMask | (UFG::DynamicSceneryInstance::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DynamicSceneryInstance::_TypeIDesc;
}

