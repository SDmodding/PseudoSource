// File Line: 86
// RVA: 0xFC650
UFG::ComponentIDDesc *__fastcall UFG::AvoidanceController::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AvoidanceController::_DescInit )
  {
    UFG::AvoidanceController::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AvoidanceController::_DescInit = 1;
    UFG::AvoidanceController::_TypeUID = UFG::AvoidanceController::_TypeIDesc.mChildBitMask | (UFG::AvoidanceController::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AvoidanceController::_AvoidanceControllerTypeUID = UFG::AvoidanceController::_TypeIDesc.mChildBitMask | (UFG::AvoidanceController::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AvoidanceController::_TypeIDesc;
}

