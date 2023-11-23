// File Line: 22
// RVA: 0x266730
void __fastcall UFG::NavModuleLocalNone::Update(UFG::NavModuleLocalNone *this, float dt)
{
  UFG::TransformNodeComponent *m_pSimObject; // rdi
  float m_fAdjustedSpeed; // xmm8_4
  float v5; // xmm3_4
  __m128 y_low; // xmm4
  __m128 v7; // xmm1
  float v8; // xmm5_4
  float y; // xmm1_4
  __m128 v10; // xmm5
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float x; // [rsp+20h] [rbp-48h]
  float z; // [rsp+28h] [rbp-40h]

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_navComponent->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  y_low = (__m128)LODWORD(this->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
  m_fAdjustedSpeed = this->m_fAdjustedSpeed;
  v5 = this->m_adjustedWaypoint.m_navPosition.m_vPosition.x - m_pSimObject->mWorldTransform.v3.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - m_pSimObject->mWorldTransform.v3.y;
  v7 = y_low;
  v7.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5);
  v8 = _mm_sqrt_ps(v7).m128_f32[0];
  if ( v8 <= 0.0 )
  {
    y = UFG::qVector3::msZero.y;
    x = UFG::qVector3::msZero.x;
    z = UFG::qVector3::msZero.z;
  }
  else
  {
    z = (float)((float)(1.0 / v8) * 0.0) * m_fAdjustedSpeed;
    y = (float)((float)(1.0 / v8) * y_low.m128_f32[0]) * m_fAdjustedSpeed;
    x = (float)((float)(1.0 / v8) * v5) * m_fAdjustedSpeed;
  }
  v10 = (__m128)LODWORD(y);
  v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = x * v11;
  v13 = y * v11;
  v14 = z * v11;
  if ( m_fAdjustedSpeed <= 0.0 )
  {
    this->m_steerData.m_fLocalSpeed = 0.0;
  }
  else
  {
    this->m_steerData.m_vDesiredDirection.x = v12;
    this->m_steerData.m_vDesiredDirection.y = v13;
    this->m_steerData.m_vDesiredDirection.z = v14;
    this->m_steerData.m_vClampedDirection.x = v12;
    this->m_steerData.m_vClampedDirection.y = v13;
    this->m_steerData.m_vClampedDirection.z = v14;
    this->m_steerData.m_vLocalDirection.x = v12;
    this->m_steerData.m_vLocalDirection.y = v13;
    this->m_steerData.m_vLocalDirection.z = v14;
    this->m_steerData.m_fLocalSpeed = this->m_fAdjustedSpeed;
  }
}

// File Line: 58
// RVA: 0x2673C0
// attributes: thunk
void __fastcall UFG::NavModuleLocalNone::UpdateSteering(UFG::NavModuleLocalFlowField *this, float dt)
{
  UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(this, dt);
}

