// File Line: 42
// RVA: 0x49790
UFG::ComponentIDDesc *__fastcall UFG::RenderStagePlugin::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RenderStagePlugin::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RenderStagePlugin::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RenderStagePlugin::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RenderStagePlugin::_DescInit = 1;
    UFG::RenderStagePlugin::_TypeUID = UFG::RenderStagePlugin::_TypeIDesc.mChildBitMask | (UFG::RenderStagePlugin::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RenderStagePlugin::_RenderStagePluginTypeUID = UFG::RenderStagePlugin::_TypeIDesc.mChildBitMask | (UFG::RenderStagePlugin::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RenderStagePlugin::_TypeIDesc;
}

