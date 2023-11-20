// File Line: 22
// RVA: 0x266730
void __fastcall UFG::NavModuleLocalNone::Update(UFG::NavModuleLocalNone *this, float dt)
{
  UFG::NavModuleLocalNone *v2; // rbx
  UFG::TransformNodeComponent *v3; // rdi
  float v4; // xmm8_4
  float v5; // xmm3_4
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  float v8; // xmm5_4
  float v9; // xmm1_4
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // [rsp+20h] [rbp-48h]
  float v17; // [rsp+24h] [rbp-44h]
  float v18; // [rsp+28h] [rbp-40h]

  v2 = this;
  v3 = (UFG::TransformNodeComponent *)this->m_navComponent->m_pSimObject;
  if ( v3 )
    v3 = (UFG::TransformNodeComponent *)v3->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v6 = (__m128)LODWORD(v2->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
  v4 = v2->m_fAdjustedSpeed;
  v5 = v2->m_adjustedWaypoint.m_navPosition.m_vPosition.x - v3->mWorldTransform.v3.x;
  v6.m128_f32[0] = v6.m128_f32[0] - v3->mWorldTransform.v3.y;
  v7 = v6;
  v7.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  if ( v8 <= 0.0 )
  {
    v9 = UFG::qVector3::msZero.y;
    v16 = UFG::qVector3::msZero.x;
    v18 = UFG::qVector3::msZero.z;
  }
  else
  {
    v18 = (float)((float)(1.0 / v8) * 0.0) * v4;
    v9 = (float)((float)(1.0 / v8) * v6.m128_f32[0]) * v4;
    v16 = (float)((float)(1.0 / v8) * v5) * v4;
  }
  v17 = v9;
  v10 = (__m128)LODWORD(v9);
  v11 = v10;
  v11.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v16 * v12;
  v14 = v9 * v12;
  v15 = v18 * v12;
  if ( v4 <= 0.0 )
  {
    v2->m_steerData.m_fLocalSpeed = 0.0;
  }
  else
  {
    v2->m_steerData.m_vDesiredDirection.x = v13;
    v2->m_steerData.m_vDesiredDirection.y = v14;
    v2->m_steerData.m_vDesiredDirection.z = v15;
    v2->m_steerData.m_vClampedDirection.x = v13;
    v2->m_steerData.m_vClampedDirection.y = v14;
    v2->m_steerData.m_vClampedDirection.z = v15;
    v2->m_steerData.m_vLocalDirection.x = v13;
    v2->m_steerData.m_vLocalDirection.y = v14;
    v2->m_steerData.m_vLocalDirection.z = v15;
    v2->m_steerData.m_fLocalSpeed = v2->m_fAdjustedSpeed;
  }
}

// File Line: 58
// RVA: 0x2673C0
void __fastcall UFG::NavModuleLocalNone::UpdateSteering(UFG::NavModuleLocalFlowField *this, float dt)
{
  UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed((UFG::NavModuleLocal *)&this->vfptr, dt);
}

