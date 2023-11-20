// File Line: 59
// RVA: 0xFB440
void __fastcall UFG::FlowfieldTaskParam::FlowfieldTaskParam(UFG::FlowfieldTaskParam *this)
{
  UFG::FlowfieldTaskParam *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  UFG::FlowfieldMass::FlowfieldMass(&this->FlowMass, 0i64, 0i64, 0i64);
  v1->FlowMassDistOffset = 10.0;
  v1->FlowMassUpdateDeltaT = 0.050000001;
  v1->FlowMassUpdateMaxT = 10.0;
  v1->FlowMassOutMinVelocity = 0.0099999998;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mAgentVelocity.x = UFG::qVector3::msZero.x;
  v1->mAgentVelocity.y = v2;
  v1->mAgentVelocity.z = v3;
  v1->mNumFlowfieldPrints = 0;
}

