// File Line: 48
// RVA: 0x9FA20
UFG::ComponentIDDesc *__fastcall UFG::RigidBody::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::RigidBody::_DescInit )
  {
    UFG::RigidBody::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::RigidBody::_DescInit = 1;
    UFG::RigidBody::_TypeUID = UFG::RigidBody::_TypeIDesc.mChildBitMask | (UFG::RigidBody::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RigidBody::_RigidBodyTypeUID = UFG::RigidBody::_TypeIDesc.mChildBitMask | (UFG::RigidBody::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RigidBody::_TypeIDesc;
}

