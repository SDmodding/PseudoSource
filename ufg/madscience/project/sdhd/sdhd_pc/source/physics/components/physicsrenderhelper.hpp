// File Line: 31
// RVA: 0x4541C0
UFG::ComponentIDDesc *__fastcall UFG::PhysicsRenderHelper::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PhysicsRenderHelper::_DescInit )
  {
    UFG::PhysicsRenderHelper::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PhysicsRenderHelper::_DescInit = 1;
    UFG::PhysicsRenderHelper::_TypeUID = UFG::PhysicsRenderHelper::_TypeIDesc.mChildBitMask | (UFG::PhysicsRenderHelper::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PhysicsRenderHelper::_PhysicsRenderHelperTypeUID = UFG::PhysicsRenderHelper::_TypeIDesc.mChildBitMask | (UFG::PhysicsRenderHelper::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PhysicsRenderHelper::_TypeIDesc;
}

