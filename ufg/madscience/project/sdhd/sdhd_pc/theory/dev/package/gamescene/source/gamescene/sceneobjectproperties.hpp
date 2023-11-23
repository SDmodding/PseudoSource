// File Line: 109
// RVA: 0x2392A0
UFG::ComponentIDDesc *__fastcall UFG::SceneObjectProperties::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::SceneObjectProperties::_DescInit )
  {
    UFG::SceneObjectProperties::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::SceneObjectProperties::_DescInit = 1;
    UFG::SceneObjectProperties::_TypeUID = UFG::SceneObjectProperties::_TypeIDesc.mChildBitMask | (UFG::SceneObjectProperties::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID = UFG::SceneObjectProperties::_TypeIDesc.mChildBitMask | (UFG::SceneObjectProperties::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SceneObjectProperties::_TypeIDesc;
}

