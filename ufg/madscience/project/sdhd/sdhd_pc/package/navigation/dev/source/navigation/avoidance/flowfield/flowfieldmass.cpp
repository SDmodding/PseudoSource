// File Line: 28
// RVA: 0xFB2C0
void __fastcall UFG::FlowfieldMass::FlowfieldMass(
        UFG::FlowfieldMass *this,
        UFG::FlowfieldComponent *pFlow,
        UFG::qVector3 *pStartPosition,
        UFG::qVector3 *pStartVelocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  this->mPrev = this;
  this->mNext = this;
  this->mThisRef = this;
  this->mActive = 0;
  this->mParams.FlowToVelocityCoeff = 5.0;
  this->mParams.BlendDuration = 0.015;
  UFG::FlowfieldMass::Initialize(this, pFlow, pStartPosition, pStartVelocity);
  *(_QWORD *)&this->mFlowStrength = 0i64;
  y = this->mStartPosition.y;
  z = this->mStartPosition.z;
  this->mPosition.x = this->mStartPosition.x;
  this->mPosition.y = y;
  this->mPosition.z = z;
  v7 = this->mStartVelocity.y;
  v8 = this->mStartVelocity.z;
  this->mVelocity.x = this->mStartVelocity.x;
  this->mVelocity.y = v7;
  this->mVelocity.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mNegVelDir.x = UFG::qVector3::msZero.x;
  this->mNegVelDir.y = v9;
  this->mNegVelDir.z = v10;
}

// File Line: 37
// RVA: 0x1003E0
void __fastcall UFG::FlowfieldMass::Initialize(
        UFG::FlowfieldMass *this,
        UFG::FlowfieldComponent *pFlow,
        UFG::qVector3 *pStartPosition,
        UFG::qVector3 *pStartVelocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float x; // eax
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
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mStartVelocity.x = UFG::qVector3::msZero.x;
  this->mStartVelocity.y = y;
  x = this->mStartVelocity.x;
  this->mStartVelocity.z = z;
  this->mStartPosition.y = y;
  this->mStartPosition.z = z;
  this->mStartPosition.x = x;
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
  UFG::FlowfieldComponent *mpFlow; // rcx
  float v5; // xmm5_4
  float FlowToVelocityCoeff; // xmm0_4
  __m128 y_low; // xmm7
  float v8; // xmm8_4
  float y; // xmm10_4
  float x; // xmm2_4
  float z; // xmm11_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  __m128 x_low; // xmm5
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
  UFG::qVector3 outFlow; // [rsp+20h] [rbp-88h] BYREF

  mpFlow = this->mpFlow;
  if ( mpFlow )
  {
    this->mFlowStrength = UFG::FlowfieldTask::GetFlow(mpFlow, &outFlow, &this->mPosition);
    v5 = fDeltaT / this->mParams.BlendDuration;
    if ( v5 <= 0.1 )
    {
      v5 = FLOAT_0_1;
    }
    else if ( v5 >= 1.0 )
    {
      v5 = *(float *)&FLOAT_1_0;
    }
    FlowToVelocityCoeff = this->mParams.FlowToVelocityCoeff;
    y_low = (__m128)LODWORD(this->mVelocity.y);
    y_low.m128_f32[0] = y_low.m128_f32[0]
                      + (float)((float)((float)(outFlow.y * FlowToVelocityCoeff) - y_low.m128_f32[0]) * v5);
    v8 = this->mVelocity.z + (float)((float)((float)(outFlow.z * FlowToVelocityCoeff) - this->mVelocity.z) * v5);
    this->mVelocity.x = this->mVelocity.x
                      + (float)((float)((float)(outFlow.x * FlowToVelocityCoeff) - this->mVelocity.x) * v5);
    LODWORD(this->mVelocity.y) = y_low.m128_i32[0];
    this->mVelocity.z = v8;
    y = this->mNegVelDir.y;
    x = this->mVelocity.x;
    z = this->mNegVelDir.z;
    v12 = (float)((float)(this->mNegVelDir.x * x) + (float)(y * y_low.m128_f32[0])) + (float)(z * v8);
    if ( COERCE_FLOAT(LODWORD(v12) & _xmm) > 0.0 )
    {
      this->mVelocity.x = x - (float)(this->mNegVelDir.x * v12);
      y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
      v13 = this->mVelocity.y - (float)(y * v12);
      v14 = this->mVelocity.z - (float)(z * v12);
      this->mVelocity.y = v13;
      this->mVelocity.z = v14;
      x_low = (__m128)LODWORD(this->mVelocity.x);
      v16 = x_low;
      y_low.m128_f32[0] = y_low.m128_f32[0] + (float)(v8 * v8);
      LODWORD(v17) = _mm_sqrt_ps(y_low).m128_u32[0];
      v16.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v13 * v13))
                      + (float)(v14 * v14);
      v18 = _mm_sqrt_ps(v16).m128_f32[0];
      *(float *)&v19 = v18;
      if ( v18 < 0.0 )
        v19 = LODWORD(v18) ^ _xmm[0];
      if ( *(float *)&v19 >= 0.001 )
      {
        this->mVelocity.x = x_low.m128_f32[0] * (float)(1.0 / v18);
        v22 = (float)(1.0 / v18) * this->mVelocity.z;
        this->mVelocity.y = (float)(1.0 / v18) * this->mVelocity.y;
        this->mVelocity.z = v22;
      }
      else
      {
        v20 = UFG::qVector3::msDirLeft.y;
        v21 = UFG::qVector3::msDirLeft.z;
        this->mVelocity.x = UFG::qVector3::msDirLeft.x;
        this->mVelocity.y = v20;
        this->mVelocity.z = v21;
      }
      v23 = v17 * this->mVelocity.x;
      v24 = v17 * this->mVelocity.y;
      this->mVelocity.z = v17 * this->mVelocity.z;
      this->mVelocity.x = v23;
      this->mVelocity.y = v24;
    }
    v25 = fDeltaT;
    v26 = fDeltaT;
    v27 = fDeltaT * this->mVelocity.z;
    v28 = v26 * this->mVelocity.y;
    v29 = v25 * this->mVelocity.x;
    v30 = v28 + this->mPosition.y;
    this->mPosition.x = v29 + this->mPosition.x;
    this->mPosition.y = v30;
    this->mPosition.z = v27 + this->mPosition.z;
    this->mDistanceTravelled = fsqrt((float)((float)(v28 * v28) + (float)(v29 * v29)) + (float)(v27 * v27))
                             + this->mDistanceTravelled;
  }
}

