// File Line: 28
// RVA: 0xFB2C0
void __fastcall UFG::FlowfieldMass::FlowfieldMass(UFG::FlowfieldMass *this, UFG::FlowfieldComponent *pFlow, UFG::qVector3 *pStartPosition, UFG::qVector3 *pStartVelocity)
{
  UFG::FlowfieldMass *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  v4 = this;
  this->mPrev = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&this->mPrev;
  this->mThisRef = this;
  this->mActive = 0;
  this->mParams.FlowToVelocityCoeff = 5.0;
  this->mParams.BlendDuration = 0.015;
  UFG::FlowfieldMass::Initialize(this, pFlow, pStartPosition, pStartVelocity);
  *(_QWORD *)&v4->mFlowStrength = 0i64;
  v5 = v4->mStartPosition.y;
  v6 = v4->mStartPosition.z;
  v4->mPosition.x = v4->mStartPosition.x;
  v4->mPosition.y = v5;
  v4->mPosition.z = v6;
  v7 = v4->mStartVelocity.y;
  v8 = v4->mStartVelocity.z;
  v4->mVelocity.x = v4->mStartVelocity.x;
  v4->mVelocity.y = v7;
  v4->mVelocity.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v4->mNegVelDir.x = UFG::qVector3::msZero.x;
  v4->mNegVelDir.y = v9;
  v4->mNegVelDir.z = v10;
}

// File Line: 37
// RVA: 0x1003E0
void __fastcall UFG::FlowfieldMass::Initialize(UFG::FlowfieldMass *this, UFG::FlowfieldComponent *pFlow, UFG::qVector3 *pStartPosition, UFG::qVector3 *pStartVelocity)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm0_4

  this->mpFlow = pFlow;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mStartVelocity.x = UFG::qVector3::msZero.x;
  this->mStartVelocity.y = v4;
  v6 = this->mStartVelocity.x;
  this->mStartVelocity.z = v5;
  this->mStartPosition.y = v4;
  this->mStartPosition.z = v5;
  this->mStartPosition.x = v6;
  if ( pStartPosition )
  {
    v7 = pStartPosition->y;
    v8 = pStartPosition->z;
    this->mStartPosition.x = pStartPosition->x;
    this->mStartPosition.y = v7;
    this->mStartPosition.z = v8;
  }
  if ( pStartVelocity )
  {
    v9 = pStartVelocity->y;
    v10 = pStartVelocity->z;
    this->mStartVelocity.x = pStartVelocity->x;
    this->mStartVelocity.y = v9;
    this->mStartVelocity.z = v10;
  }
  *(_QWORD *)&this->mFlowStrength = 0i64;
  v11 = this->mStartPosition.y;
  v12 = this->mStartPosition.z;
  this->mPosition.x = this->mStartPosition.x;
  this->mPosition.y = v11;
  this->mPosition.z = v12;
  v13 = this->mStartVelocity.y;
  v14 = this->mStartVelocity.z;
  this->mVelocity.x = this->mStartVelocity.x;
  this->mVelocity.y = v13;
  this->mVelocity.z = v14;
  v15 = UFG::qVector3::msZero.z;
  v16 = UFG::qVector3::msZero.x;
  this->mNegVelDir.y = UFG::qVector3::msZero.y;
  this->mNegVelDir.x = v16;
  this->mNegVelDir.z = v15;
}

// File Line: 76
// RVA: 0x101B20
void __fastcall UFG::FlowfieldMass::OnUpdate(UFG::FlowfieldMass *this, float fDeltaT)
{
  UFG::FlowfieldMass *v2; // rbx
  UFG::FlowfieldComponent *v3; // rcx
  float v4; // xmm6_4
  float v5; // xmm5_4
  float v6; // xmm0_4
  __m128 v7; // xmm7
  float v8; // xmm8_4
  float v9; // xmm10_4
  float v10; // xmm2_4
  float v11; // xmm11_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  __m128 v15; // xmm5
  __m128 v16; // xmm0
  float v17; // xmm3_4
  float v18; // xmm1_4
  int v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm6_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  UFG::qVector3 outFlow; // [rsp+20h] [rbp-88h]

  v2 = this;
  v3 = this->mpFlow;
  v4 = fDeltaT;
  if ( v3 )
  {
    v2->mFlowStrength = UFG::FlowfieldTask::GetFlow(v3, &outFlow, &v2->mPosition);
    v5 = fDeltaT / v2->mParams.BlendDuration;
    if ( v5 <= 0.1 )
    {
      v5 = FLOAT_0_1;
    }
    else if ( v5 >= 1.0 )
    {
      v5 = *(float *)&FLOAT_1_0;
    }
    v6 = v2->mParams.FlowToVelocityCoeff;
    v7 = (__m128)LODWORD(v2->mVelocity.y);
    v7.m128_f32[0] = v7.m128_f32[0] + (float)((float)((float)(outFlow.y * v6) - v7.m128_f32[0]) * v5);
    v8 = v2->mVelocity.z + (float)((float)((float)(outFlow.z * v6) - v2->mVelocity.z) * v5);
    v2->mVelocity.x = v2->mVelocity.x + (float)((float)((float)(outFlow.x * v6) - v2->mVelocity.x) * v5);
    LODWORD(v2->mVelocity.y) = v7.m128_i32[0];
    v2->mVelocity.z = v8;
    v9 = v2->mNegVelDir.y;
    v10 = v2->mVelocity.x;
    v11 = v2->mNegVelDir.z;
    v12 = (float)((float)(v2->mNegVelDir.x * v10) + (float)(v2->mNegVelDir.y * v7.m128_f32[0]))
        + (float)(v2->mNegVelDir.z * v8);
    if ( COERCE_FLOAT(LODWORD(v12) & _xmm) > 0.0 )
    {
      v2->mVelocity.x = v10 - (float)(v2->mNegVelDir.x * v12);
      v7.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v10 * v10);
      v13 = v2->mVelocity.y - (float)(v9 * v12);
      v14 = v2->mVelocity.z - (float)(v11 * v12);
      v2->mVelocity.y = v13;
      v2->mVelocity.z = v14;
      v15 = (__m128)LODWORD(v2->mVelocity.x);
      v16 = v15;
      v7.m128_f32[0] = v7.m128_f32[0] + (float)(v8 * v8);
      LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v7);
      v16.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v13 * v13)) + (float)(v14 * v14);
      LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v16);
      *(float *)&v19 = v18;
      if ( v18 < 0.0 )
        v19 = LODWORD(v18) ^ _xmm[0];
      if ( *(float *)&v19 >= 0.001 )
      {
        v2->mVelocity.x = v15.m128_f32[0] * (float)(1.0 / v18);
        v22 = (float)(1.0 / v18) * v2->mVelocity.z;
        v2->mVelocity.y = (float)(1.0 / v18) * v2->mVelocity.y;
        v2->mVelocity.z = v22;
      }
      else
      {
        v20 = UFG::qVector3::msDirLeft.y;
        v21 = UFG::qVector3::msDirLeft.z;
        v2->mVelocity.x = UFG::qVector3::msDirLeft.x;
        v2->mVelocity.y = v20;
        v2->mVelocity.z = v21;
      }
      v23 = v17 * v2->mVelocity.x;
      v24 = v17 * v2->mVelocity.y;
      v2->mVelocity.z = v17 * v2->mVelocity.z;
      v2->mVelocity.x = v23;
      v2->mVelocity.y = v24;
    }
    v25 = v4;
    v26 = v4;
    v27 = v4 * v2->mVelocity.z;
    v28 = v26 * v2->mVelocity.y;
    v29 = v25 * v2->mVelocity.x;
    v30 = v28 + v2->mPosition.y;
    v2->mPosition.x = v29 + v2->mPosition.x;
    v2->mPosition.y = v30;
    v2->mPosition.z = v27 + v2->mPosition.z;
    v2->mDistanceTravelled = fsqrt((float)((float)(v28 * v28) + (float)(v29 * v29)) + (float)(v27 * v27))
                           + v2->mDistanceTravelled;
  }
}

