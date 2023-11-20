// File Line: 31
// RVA: 0x4541C0
UFG::ComponentIDDesc *__fastcall UFG::PhysicsRenderHelper::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PhysicsRenderHelper::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PhysicsRenderHelper::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PhysicsRenderHelper::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PhysicsRenderHelper::_DescInit = 1;
    UFG::PhysicsRenderHelper::_TypeUID = UFG::PhysicsRenderHelper::_TypeIDesc.mChildBitMask | (UFG::PhysicsRenderHelper::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PhysicsRenderHelper::_PhysicsRenderHelperTypeUID = UFG::PhysicsRenderHelper::_TypeIDesc.mChildBitMask | (UFG::PhysicsRenderHelper::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PhysicsRenderHelper::_TypeIDesc;
}

