// File Line: 86
// RVA: 0xFC650
UFG::ComponentIDDesc *__fastcall UFG::AvoidanceController::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AvoidanceController::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AvoidanceController::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AvoidanceController::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AvoidanceController::_DescInit = 1;
    UFG::AvoidanceController::_TypeUID = UFG::AvoidanceController::_TypeIDesc.mChildBitMask | (UFG::AvoidanceController::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AvoidanceController::_AvoidanceControllerTypeUID = UFG::AvoidanceController::_TypeIDesc.mChildBitMask | (UFG::AvoidanceController::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AvoidanceController::_TypeIDesc;
}

