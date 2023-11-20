// File Line: 109
// RVA: 0x2392A0
UFG::ComponentIDDesc *__fastcall UFG::SceneObjectProperties::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::SceneObjectProperties::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::SceneObjectProperties::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::SceneObjectProperties::_TypeIDesc.mChildren = v0->mChildren;
    UFG::SceneObjectProperties::_DescInit = 1;
    UFG::SceneObjectProperties::_TypeUID = UFG::SceneObjectProperties::_TypeIDesc.mChildBitMask | (UFG::SceneObjectProperties::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID = UFG::SceneObjectProperties::_TypeIDesc.mChildBitMask | (UFG::SceneObjectProperties::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SceneObjectProperties::_TypeIDesc;
}

