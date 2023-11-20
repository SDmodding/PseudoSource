// File Line: 48
// RVA: 0x9FA20
UFG::ComponentIDDesc *__fastcall UFG::RigidBody::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RigidBody::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RigidBody::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RigidBody::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RigidBody::_DescInit = 1;
    UFG::RigidBody::_TypeUID = UFG::RigidBody::_TypeIDesc.mChildBitMask | (UFG::RigidBody::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RigidBody::_RigidBodyTypeUID = UFG::RigidBody::_TypeIDesc.mChildBitMask | (UFG::RigidBody::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RigidBody::_TypeIDesc;
}

