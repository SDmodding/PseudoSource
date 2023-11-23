// File Line: 59
// RVA: 0xFB440
void __fastcall UFG::FlowfieldTaskParam::FlowfieldTaskParam(UFG::FlowfieldTaskParam *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  UFG::FlowfieldMass::FlowfieldMass(&this->FlowMass, 0i64, 0i64, 0i64);
  this->FlowMassDistOffset = 10.0;
  this->FlowMassUpdateDeltaT = 0.050000001;
  this->FlowMassUpdateMaxT = 10.0;
  this->FlowMassOutMinVelocity = 0.0099999998;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mAgentVelocity.x = UFG::qVector3::msZero.x;
  this->mAgentVelocity.y = y;
  this->mAgentVelocity.z = z;
  this->mNumFlowfieldPrints = 0;
}

