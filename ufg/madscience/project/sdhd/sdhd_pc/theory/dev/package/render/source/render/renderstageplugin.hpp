// File Line: 42
// RVA: 0x49790
UFG::ComponentIDDesc *__fastcall UFG::RenderStagePlugin::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::RenderStagePlugin::_DescInit )
  {
    UFG::RenderStagePlugin::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::RenderStagePlugin::_DescInit = 1;
    UFG::RenderStagePlugin::_TypeUID = UFG::RenderStagePlugin::_TypeIDesc.mChildBitMask | (UFG::RenderStagePlugin::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RenderStagePlugin::_RenderStagePluginTypeUID = UFG::RenderStagePlugin::_TypeIDesc.mChildBitMask | (UFG::RenderStagePlugin::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RenderStagePlugin::_TypeIDesc;
}

