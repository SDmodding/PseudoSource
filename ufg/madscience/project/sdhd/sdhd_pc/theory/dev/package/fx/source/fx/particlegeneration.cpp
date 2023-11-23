// File Line: 26
// RVA: 0x1E77B0
void __fastcall Render::`anonymous namespace::MatrixToEulerAngles(UFG::qMatrix44 *mat, UFG::qVector3 *euler)
{
  float x; // xmm0_4
  float v5; // xmm8_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  float v8; // xmm9_4
  float y; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4

  x = mat->v2.x;
  if ( x <= -1.0 )
  {
    x = FLOAT_N1_0;
  }
  else if ( x >= 1.0 )
  {
    x = *(float *)&FLOAT_1_0;
  }
  v5 = asinf(x);
  v6 = cosf(v5);
  if ( COERCE_FLOAT(LODWORD(v6) & _xmm) <= 0.0049999999 )
  {
    y = mat->v1.y;
    v10 = mat->v0.y;
    v8 = 0.0;
  }
  else
  {
    v7 = 1.0 / v6;
    v8 = atan2f(COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 * mat->v2.y) ^ _xmm[0]), v7 * mat->v2.z);
    y = v7 * mat->v0.x;
    LODWORD(v10) = COERCE_UNSIGNED_INT(v7 * mat->v1.x) ^ _xmm[0];
  }
  v11 = atan2f(v10, y);
  euler->x = v8;
  euler->y = v5;
  euler->z = v11;
}

// File Line: 60
// RVA: 0x1E67F0
void __fastcall Render::ParticleGenerator::CreateScale(
        Render::ParticleGenerator *this,
        Render::EmitterParticleAttribute *attribute)
{
  Render::ParticleEmitterSettings *pfx; // r8
  int *seed; // rdx
  float mXScaleMax; // xmm6_4
  float mXScaleMin; // xmm7_4
  float v8; // xmm0_4
  Render::ParticleEmitterSettings *v9; // rax
  float v10; // xmm8_4
  float mYScaleMin; // xmm7_4
  float mYScaleMax; // xmm6_4
  float v13; // xmm2_4
  float sizeScale; // xmm0_4
  Render::ParticleEmitterSettings *v15; // rax
  float mXScaleSpeedMax; // xmm6_4
  float mXScaleSpeedMin; // xmm7_4
  float v18; // xmm0_4
  Render::ParticleEmitterSettings *v19; // rcx
  float v20; // xmm8_4
  float mYScaleSpeedMax; // xmm7_4
  float mYScaleSpeedMin; // xmm6_4

  pfx = this->mParameters->pfx;
  seed = this->mParameters->seed;
  mXScaleMax = pfx->mXScaleMax;
  mXScaleMin = pfx->mXScaleMin;
  if ( (pfx->mBitFields[0] & 0x10) != 0 )
  {
    v8 = UFG::qRandom(1.0, (unsigned int *)seed);
    v9 = this->mParameters->pfx;
    v10 = (float)(v8 * (float)(mXScaleMax - mXScaleMin)) + mXScaleMin;
    mYScaleMin = v9->mYScaleMin;
    mYScaleMax = v9->mYScaleMax;
    v13 = (float)(UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed) * (float)(mYScaleMax - mYScaleMin))
        + mYScaleMin;
  }
  else
  {
    v13 = (float)(UFG::qRandom(1.0, (unsigned int *)seed) * (float)(mXScaleMax - mXScaleMin)) + mXScaleMin;
    v10 = v13;
  }
  sizeScale = this->mParameters->sizeScale;
  attribute->vScale.z = sizeScale * v13;
  attribute->vScale.x = sizeScale * v10;
  v15 = this->mParameters->pfx;
  mXScaleSpeedMax = v15->mXScaleSpeedMax;
  mXScaleSpeedMin = v15->mXScaleSpeedMin;
  v18 = UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed);
  v19 = this->mParameters->pfx;
  v20 = (float)(v18 * (float)(mXScaleSpeedMax - mXScaleSpeedMin)) + mXScaleSpeedMin;
  if ( (v19->mBitFields[0] & 0x20) != 0 )
  {
    mYScaleSpeedMax = v19->mYScaleSpeedMax;
    mYScaleSpeedMin = v19->mYScaleSpeedMin;
    attribute->vScale.w = (float)((float)(mYScaleSpeedMax - mYScaleSpeedMin)
                                * UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed))
                        + mYScaleSpeedMin;
  }
  else
  {
    attribute->vScale.w = v20;
  }
  attribute->vScale.y = v20;
}

// File Line: 90
// RVA: 0x1E6650
void __fastcall Render::ParticleGenerator::CreateRotation(
        Render::ParticleGenerator *this,
        Render::EmitterParticleAttribute *attribute)
{
  float x; // xmm0_4
  float y; // xmm1_4
  Render::GenerateParticleParameters *mParameters; // rdx
  float z; // xmm0_4
  Render::ParticleEmitterSettings *pfx; // rax
  float mRotationDampMax; // xmm6_4
  float mRotationDampMin; // xmm7_4
  float v11; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-D8h] BYREF
  int v13; // [rsp+30h] [rbp-C8h]
  int v14; // [rsp+34h] [rbp-C4h]
  int v15; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 v16; // [rsp+40h] [rbp-B8h] BYREF
  UFG::qMatrix44 rot; // [rsp+50h] [rbp-A8h] BYREF
  UFG::qMatrix44 mat; // [rsp+90h] [rbp-68h] BYREF

  Render::ParticleGenerator::GetRandomVector(
    this,
    &result,
    &this->mParameters->pfx->mRotateMin,
    &this->mParameters->pfx->mRotateMax);
  if ( this->mParameters->pfx->mType == 3 )
  {
    UFG::qRotationMatrixXYZDepreciated(&rot, &result);
    UFG::qMatrix44::operator*(&rot, &mat, &this->mParameters->curBasisNormalized);
    Render::`anonymous namespace::MatrixToEulerAngles(&mat, &result);
  }
  v13 = (int)(float)((float)(result.x + 6.2831855) * 20.292255);
  v14 = (int)(float)((float)(result.y + 6.2831855) * 20.292255);
  v15 = (int)(float)((float)(result.z + 6.2831855) * 20.292255);
  Render::ParticleGenerator::GetRandomVector(
    this,
    &v16,
    &this->mParameters->pfx->mRotateSpeedMin,
    &this->mParameters->pfx->mRotateSpeedMax);
  x = v16.x;
  y = v16.y;
  attribute->vRotationI[0] = v13;
  attribute->vRotationI[1] = v14;
  attribute->vRotationI[2] = v15;
  mParameters = this->mParameters;
  attribute->vRotationV.x = x;
  z = v16.z;
  attribute->vRotationV.y = y;
  attribute->vRotationV.z = z;
  pfx = mParameters->pfx;
  mRotationDampMax = pfx->mRotationDampMax;
  mRotationDampMin = pfx->mRotationDampMin;
  v11 = UFG::qRandom(1.0, (unsigned int *)mParameters->seed);
  Render::EmitterParticleAttribute::SetRotationDamp(
    attribute,
    (float)(v11 * (float)(mRotationDampMax - mRotationDampMin)) + mRotationDampMin);
}

// File Line: 116
// RVA: 0x1E69A0
void __fastcall Render::ParticleGenerator::CreateVelocity(
        Render::ParticleGenerator *this,
        Render::EmitterParticleAttribute *pAttrib)
{
  Render::GenerateParticleParameters *mParameters; // rbx
  UFG::qVector3 *RandomVector; // rax
  float x; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm9_4
  Render::GenerateParticleParameters *v9; // rax
  float v10; // xmm7_4
  Render::ParticleEmitterSettings *pfx; // r8
  Render::GenerateParticleParameters *v12; // rax
  Render::ParticleEmitterSettings *v13; // r8
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm8_4
  float v30; // xmm6_4
  float v31; // xmm4_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm7_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm6_4
  float v38; // xmm9_4
  Render::GenerateParticleParameters *v39; // rcx
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm8_4
  float v44; // xmm7_4
  float v45; // xmm5_4
  float v46; // xmm9_4
  float v47; // xmm10_4
  float v48; // xmm6_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm5_4
  float v52; // xmm9_4
  float v53; // xmm2_4
  float v54; // xmm10_4
  float v55; // xmm1_4
  float v56; // xmm6_4
  float v57; // xmm0_4
  float v58; // xmm8_4
  float v59; // xmm7_4
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm8_4
  float v63; // xmm4_4
  float v64; // xmm9_4
  float v65; // xmm3_4
  float v66; // xmm2_4
  float v67; // xmm0_4
  float v68; // xmm2_4
  Render::ParticleEmitterSettings *v69; // rax
  float mDragMax; // xmm11_4
  float mDragMin; // xmm10_4
  float v72; // xmm7_4
  Render::ParticleEmitterSettings *v73; // rax
  float v74; // xmm8_4
  float v75; // xmm9_4
  float v76; // xmm8_4
  float v77; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qVector3 scale; // [rsp+30h] [rbp-B8h] BYREF
  float v80; // [rsp+40h] [rbp-A8h]
  float v81; // [rsp+44h] [rbp-A4h]
  float v82; // [rsp+48h] [rbp-A0h]
  float y; // [rsp+4Ch] [rbp-9Ch]
  float z; // [rsp+50h] [rbp-98h]
  float v85; // [rsp+54h] [rbp-94h]
  UFG::qVector3 v86; // [rsp+58h] [rbp-90h] BYREF
  float v87; // [rsp+68h] [rbp-80h]
  float v88; // [rsp+6Ch] [rbp-7Ch]
  UFG::qMatrix44 dest; // [rsp+70h] [rbp-78h] BYREF
  float v90; // [rsp+118h] [rbp+30h]
  void *retaddr; // [rsp+128h] [rbp+40h]
  float v92; // [rsp+130h] [rbp+48h]

  mParameters = this->mParameters;
  RandomVector = Render::ParticleGenerator::GetRandomVector(
                   this,
                   &result,
                   &this->mParameters->pfx->mNormalVelocityMin,
                   &this->mParameters->pfx->mNormalVelocityMax);
  x = RandomVector->x;
  v7 = mParameters->meshNormal.y * RandomVector->y;
  v8 = mParameters->meshNormal.z * RandomVector->z;
  v9 = this->mParameters;
  v80 = v7;
  v85 = v8;
  v10 = x * mParameters->meshNormal.x;
  pfx = v9->pfx;
  v82 = v10;
  Render::ParticleGenerator::GetRandomVector(this, &result, &pfx->mLocalVelocityMin, &pfx->mLocalVelocityMax);
  Render::ParticleGenerator::GetRandomVector(
    this,
    &v86,
    &this->mParameters->pfx->mGlobalVelocityMin,
    &this->mParameters->pfx->mGlobalVelocityMax);
  v12 = this->mParameters;
  v13 = this->mParameters->pfx;
  if ( v13->mSpace == 1 )
  {
    v90 = (float)((float)(v86.y * this->mInvBasis.v1.x) + (float)(v86.x * this->mInvBasis.v0.x))
        + (float)(v86.z * this->mInvBasis.v2.x);
    v32 = v86.z * this->mInvBasis.v2.y;
    v33 = v86.z * this->mInvBasis.v2.z;
    v34 = (float)(v86.y * this->mInvBasis.v1.y) + (float)(v86.x * this->mInvBasis.v0.y);
    v35 = (float)(v86.y * this->mInvBasis.v1.z) + (float)(v86.x * this->mInvBasis.v0.z);
    z = result.z;
    y = result.y;
    *(float *)&retaddr = result.x;
    v92 = v34 + v32;
    v81 = v35 + v33;
  }
  else
  {
    v14 = v10;
    v15 = v8 * v12->curBasisNormalized.v2.x;
    v16 = v7 * v12->curBasisNormalized.v1.y;
    v17 = (float)(v10 * v12->curBasisNormalized.v0.z) + (float)(v7 * v12->curBasisNormalized.v1.z);
    v18 = v10 * v12->curBasisNormalized.v0.x;
    v19 = v8 * v12->curBasisNormalized.v2.y;
    v20 = v14 * v12->curBasisNormalized.v0.y;
    v21 = v7 * v12->curBasisNormalized.v1.x;
    v85 = (float)(v8 * v12->curBasisNormalized.v2.z) + v17;
    v22 = v18 + v21;
    v23 = result.x * v12->curBasisNormalized.v0.y;
    v24 = result.y * v12->curBasisNormalized.v1.y;
    v25 = v19 + (float)(v20 + v16);
    v26 = result.y * v12->curBasisNormalized.v1.x;
    v27 = result.y * v12->curBasisNormalized.v1.z;
    v80 = v25;
    v82 = v22 + v15;
    v28 = (float)(result.x * v12->curBasisNormalized.v0.x) + v26;
    v29 = result.z * v12->curBasisNormalized.v2.x;
    v30 = result.z * v12->curBasisNormalized.v2.z;
    v31 = (float)(result.x * v12->curBasisNormalized.v0.z) + v27;
    v92 = v86.y;
    y = (float)(result.z * v12->curBasisNormalized.v2.y) + (float)(v23 + v24);
    v90 = v86.x;
    *(float *)&retaddr = v29 + v28;
    z = v30 + v31;
    v81 = v86.z;
  }
  Render::ParticleGenerator::GetRandomVector(this, &scale, &v13->mInheritVelocityMin, &v13->mInheritVelocityMax);
  v36 = scale.x;
  if ( scale.x != UFG::qVector3::msZero.x
    || (v37 = scale.y, scale.y != UFG::qVector3::msZero.y)
    || (v38 = scale.z, scale.z != UFG::qVector3::msZero.z) )
  {
    UFG::qScaleMatrix(&dest, &scale);
    v39 = this->mParameters;
    v40 = this->mParameters->emitterVelocity.z;
    v41 = this->mParameters->emitterVelocity.x;
    v42 = v40 * this->mInvBasis.v2.x;
    if ( this->mParameters->pfx->mSpace == 1 )
    {
      v43 = (float)((float)((float)(v41 * this->mInvBasis.v0.x) + (float)(v39->emitterVelocity.y * this->mInvBasis.v1.x))
                  + v42)
          + (float)(this->mInvBasis.v3.x * 0.0);
      v44 = (float)((float)((float)(v41 * this->mInvBasis.v0.y) + (float)(v39->emitterVelocity.y * this->mInvBasis.v1.y))
                  + (float)(v40 * this->mInvBasis.v2.y))
          + (float)(this->mInvBasis.v3.y * 0.0);
      v45 = (float)((float)((float)(this->mParameters->emitterVelocity.x * this->mInvBasis.v0.z)
                          + (float)(v39->emitterVelocity.y * this->mInvBasis.v1.z))
                  + (float)(v40 * this->mInvBasis.v2.z))
          + (float)(this->mInvBasis.v3.z * 0.0);
      v46 = (float)((float)((float)(v39->emitterVelocity.y * this->mInvBasis.v1.w) + (float)(v41 * this->mInvBasis.v0.w))
                  + (float)(v40 * this->mInvBasis.v2.w))
          + (float)(this->mInvBasis.v3.w * 0.0);
      v47 = (float)((float)((float)(dest.v0.x * v43) + (float)(v87 * v44)) + (float)(dest.v0.z * v45))
          + (float)(dest.v1.z * v46);
      v48 = (float)((float)((float)(dest.v0.y * v43) + (float)(v88 * v44)) + (float)(dest.v0.w * v45))
          + (float)(dest.v1.w * v46);
      v49 = (float)((float)((float)(dest.v0.z * v43) + (float)(dest.v0.x * v44)) + (float)(dest.v1.x * v45))
          + (float)(dest.v2.x * v46);
      v50 = (float)((float)((float)(dest.v0.w * v43) + (float)(dest.v0.y * v44)) + (float)(dest.v1.y * v45))
          + (float)(dest.v2.y * v46);
      v51 = (float)((float)((float)(v48 * v39->curBasisNormalized.v1.x) + (float)(v47 * v39->curBasisNormalized.v0.x))
                  + (float)(v49 * v39->curBasisNormalized.v2.x))
          + (float)(v50 * v39->curBasisNormalized.v3.x);
      v52 = (float)((float)((float)(v47 * v39->curBasisNormalized.v0.y) + (float)(v48 * v39->curBasisNormalized.v1.y))
                  + (float)(v49 * v39->curBasisNormalized.v2.y))
          + (float)(v50 * v39->curBasisNormalized.v3.y);
      v53 = (float)((float)((float)(v47 * v39->curBasisNormalized.v0.z) + (float)(v48 * v39->curBasisNormalized.v1.z))
                  + (float)(v49 * v39->curBasisNormalized.v2.z))
          + (float)(v50 * v39->curBasisNormalized.v3.z);
      v54 = (float)((float)((float)(v47 * v39->curBasisNormalized.v0.w) + (float)(v48 * v39->curBasisNormalized.v1.w))
                  + (float)(v49 * v39->curBasisNormalized.v2.w))
          + (float)(v50 * v39->curBasisNormalized.v3.w);
      v55 = v53 * this->mInvBasis.v2.y;
      v36 = (float)((float)((float)(v52 * this->mInvBasis.v1.x) + (float)(v51 * this->mInvBasis.v0.x))
                  + (float)(v53 * this->mInvBasis.v2.x))
          + (float)(v54 * this->mInvBasis.v3.x);
      v56 = (float)(v52 * this->mInvBasis.v1.y) + (float)(v51 * this->mInvBasis.v0.y);
      v57 = v54 * this->mInvBasis.v3.y;
      v38 = (float)((float)((float)(v52 * this->mInvBasis.v1.z) + (float)(v51 * this->mInvBasis.v0.z))
                  + (float)(v53 * this->mInvBasis.v2.z))
          + (float)(v54 * this->mInvBasis.v3.z);
    }
    else
    {
      v58 = v39->emitterVelocity.y;
      v59 = (float)((float)((float)(v58 * this->mInvBasis.v1.x) + (float)(v41 * this->mInvBasis.v0.x)) + v42)
          + (float)(this->mInvBasis.v3.x * 0.0);
      v60 = (float)((float)((float)(v58 * this->mInvBasis.v1.y) + (float)(v41 * this->mInvBasis.v0.y))
                  + (float)(v40 * this->mInvBasis.v2.y))
          + (float)(this->mInvBasis.v3.y * 0.0);
      v61 = (float)((float)((float)(v58 * this->mInvBasis.v1.z) + (float)(v41 * this->mInvBasis.v0.z))
                  + (float)(v40 * this->mInvBasis.v2.z))
          + (float)(this->mInvBasis.v3.z * 0.0);
      v62 = (float)((float)((float)(v58 * this->mInvBasis.v1.w) + (float)(v41 * this->mInvBasis.v0.w))
                  + (float)(v40 * this->mInvBasis.v2.w))
          + (float)(this->mInvBasis.v3.w * 0.0);
      v63 = (float)((float)((float)(dest.v0.x * v59) + (float)(v87 * v60)) + (float)(dest.v0.z * v61))
          + (float)(dest.v1.z * v62);
      v64 = (float)((float)((float)(dest.v0.y * v59) + (float)(v88 * v60)) + (float)(dest.v0.w * v61))
          + (float)(dest.v1.w * v62);
      v65 = (float)((float)((float)(dest.v0.z * v59) + (float)(dest.v0.x * v60)) + (float)(dest.v1.x * v61))
          + (float)(dest.v2.x * v62);
      v66 = (float)((float)((float)(dest.v0.w * v59) + (float)(dest.v0.y * v60)) + (float)(dest.v1.y * v61))
          + (float)(dest.v2.y * v62);
      v55 = v65 * v39->curBasisNormalized.v2.y;
      v36 = (float)((float)((float)(v64 * v39->curBasisNormalized.v1.x) + (float)(v63 * v39->curBasisNormalized.v0.x))
                  + (float)(v65 * v39->curBasisNormalized.v2.x))
          + (float)(v66 * v39->curBasisNormalized.v3.x);
      v56 = (float)(v64 * v39->curBasisNormalized.v1.y) + (float)(v63 * v39->curBasisNormalized.v0.y);
      v57 = v66 * v39->curBasisNormalized.v3.y;
      v38 = (float)((float)((float)(v64 * v39->curBasisNormalized.v1.z) + (float)(v63 * v39->curBasisNormalized.v0.z))
                  + (float)(v65 * v39->curBasisNormalized.v2.z))
          + (float)(v66 * v39->curBasisNormalized.v3.z);
    }
    scale.z = v38;
    scale.x = v36;
    v37 = (float)(v56 + v55) + v57;
    scale.y = v37;
  }
  v67 = (float)(this->mParameters->velocityScale * (float)((float)(v90 + *(float *)&retaddr) + v82)) + v36;
  v68 = (float)(this->mParameters->velocityScale * (float)((float)(v81 + z) + v85)) + v38;
  result.y = (float)(this->mParameters->velocityScale * (float)((float)(v92 + y) + v80)) + v37;
  result.x = v67;
  result.z = v68;
  Render::EmitterParticleAttribute::SetInitialVelocity(pAttrib, &result);
  v69 = this->mParameters->pfx;
  mDragMax = v69->mDragMax;
  mDragMin = v69->mDragMin;
  v72 = UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed);
  v73 = this->mParameters->pfx;
  v74 = 1.0 / this->mParameters->transformScale;
  v75 = v74 * v73->mGravityMin;
  v76 = v74 * v73->mGravityMax;
  v77 = UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed);
  Render::EmitterParticleAttribute::SetVelocityGravityAndDrag(
    pAttrib,
    &result,
    (float)((float)(v76 - v75) * v77) + v75,
    (float)((float)(mDragMax - mDragMin) * v72) + mDragMin);
}x;
  v77 = UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed);
  Render::EmitterParticleAttribute::SetVelocityGravityAndDrag(
    pAttrib,
    &result,
    (float)((float)(v76 - v75) * v77) + v75,
    (

// File Line: 167
// RVA: 0x1E7300
Render::EmitterParticleAttribute *__fastcall Render::ParticleGenerator::Generate(
        Render::ParticleGenerator *this,
        Render::EmitterParticleAttribute *attribBuffer,
        unsigned int currentBufferCount)
{
  Render::EmitterParticleAttribute *v4; // rdi
  int v6; // esi
  UFG::qHalfVector4 *v7; // rbx
  Render::EmitterParticleAttribute *v8; // rbp
  float v9; // xmm6_4
  int v10; // ebx
  unsigned int v11; // ecx
  Render::ParticleGenerator v13; // [rsp+20h] [rbp-AF8h] BYREF
  char dest[24]; // [rsp+70h] [rbp-AA8h] BYREF
  UFG::qHalfVector4 v15; // [rsp+88h] [rbp-A90h] BYREF

  v4 = attribBuffer;
  v6 = 31;
  v7 = &v15;
  v8 = &attribBuffer[currentBufferCount];
  v9 = (float)((float)((float)(this->mParameters->cameraPos.y - this->mParameters->pos.y)
                     * (float)(this->mParameters->cameraPos.y - this->mParameters->pos.y))
             + (float)((float)(this->mParameters->cameraPos.x - this->mParameters->pos.x)
                     * (float)(this->mParameters->cameraPos.x - this->mParameters->pos.x)))
     + (float)((float)(this->mParameters->cameraPos.z - this->mParameters->pos.z)
             * (float)(this->mParameters->cameraPos.z - this->mParameters->pos.z));
  do
  {
    UFG::qHalfVector4::qHalfVector4(v7 - 1);
    UFG::qHalfVector4::qHalfVector4(v7);
    UFG::qHalfVector4::qHalfVector4(v7 + 6);
    v7 = (UFG::qHalfVector4 *)((char *)v7 + 84);
    --v6;
  }
  while ( v6 >= 0 );
  v10 = 0;
  v11 = 0;
  if ( currentBufferCount )
  {
    while ( v9 <= (float)((float)((float)((float)(this->mParameters->cameraPos.y - v4->vPosAndGrav.y)
                                        * (float)(this->mParameters->cameraPos.y - v4->vPosAndGrav.y))
                                + (float)((float)(this->mParameters->cameraPos.x - v4->vPosAndGrav.x)
                                        * (float)(this->mParameters->cameraPos.x - v4->vPosAndGrav.x)))
                        + (float)((float)(this->mParameters->cameraPos.z - v4->vPosAndGrav.z)
                                * (float)(this->mParameters->cameraPos.z - v4->vPosAndGrav.z))) )
    {
      ++v11;
      ++v4;
      if ( v11 >= currentBufferCount )
        goto LABEL_8;
    }
    v10 = currentBufferCount - v11;
    UFG::qMemCopy(dest, v4, 84 * (currentBufferCount - v11));
    v8 = v4;
  }
LABEL_8:
  v13.mParameters = this->mParameters;
  UFG::qInverseAffine(&v13.mInvBasis, &v13.mParameters->curBasisNormalized);
  Render::ParticleGenerator::GenerateAtPosition(&v13, v8);
  if ( v10 )
    UFG::qMemCopy(&v8[1], dest, 84 * v10);
  return v8;
}

// File Line: 227
// RVA: 0x1E7490
void __fastcall Render::ParticleGenerator::GenerateAtPosition(
        Render::ParticleGenerator *this,
        Render::EmitterParticleAttribute *pAttrib)
{
  Render::GenerateParticleParameters *mParameters; // r8
  float x; // eax
  float start_time; // xmm1_4
  float end_time; // xmm0_4
  float simTime; // xmm2_4
  float y; // eax
  float v10; // xmm2_4
  Render::GenerateParticleParameters *v11; // rbx
  Render::ParticleEmitterSettings *pfx; // rcx
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  Render::ParticleLighting *particleLighting; // rcx
  unsigned int mTextureOrientation; // edx
  unsigned int v18; // edx
  unsigned int v19; // edx
  char v20; // al
  Render::ParticleEmitterSettings *v21; // rcx
  unsigned int v22; // ebx
  __m128i v23; // xmm0
  float v24; // xmm0_4
  UFG::qVector3 particlePosition; // [rsp+20h] [rbp-38h] BYREF
  UFG::qColour unlitColour; // [rsp+30h] [rbp-28h] BYREF
  UFG::qColour result; // [rsp+40h] [rbp-18h] BYREF

  mParameters = this->mParameters;
  x = this->mParameters->pos.x;
  unlitColour.r = 1.0;
  unlitColour.g = 1.0;
  start_time = mParameters->start_time;
  end_time = mParameters->end_time;
  simTime = mParameters->simTime;
  pAttrib->vPosAndGrav.x = x;
  y = mParameters->pos.y;
  unlitColour.b = 1.0;
  v10 = (float)(simTime - start_time) / (float)(end_time - start_time);
  pAttrib->vPosAndGrav.y = y;
  pAttrib->vPosAndGrav.z = mParameters->pos.z;
  v11 = this->mParameters;
  pfx = this->mParameters->pfx;
  v13 = v11->renderMatrix.v3.y + v11->pos.y;
  v14 = v11->renderMatrix.v3.z + v11->pos.z;
  particlePosition.x = v11->renderMatrix.v3.x + v11->pos.x;
  particlePosition.y = v13;
  particlePosition.z = v14;
  v15 = Render::ComputeInterpolatedAlpha(pfx->mSettings.ColorAlphaKeys, pfx->mSettings.AlphaKeyPositions, v10);
  particleLighting = v11->particleLighting;
  unlitColour.a = v15;
  Render::ParticleLighting::ApplyDynamicLights(particleLighting, &result, &unlitColour, &particlePosition);
  unlitColour.r = result.r * result.r;
  unlitColour.g = result.g * result.g;
  unlitColour.b = result.b * result.b;
  unlitColour.a = result.a;
  Render::EmitterParticleAttribute::SetColour(pAttrib, &unlitColour);
  Render::ParticleGenerator::CreateRotation(this, pAttrib);
  Render::ParticleGenerator::CreateScale(this, pAttrib);
  mTextureOrientation = this->mParameters->pfx->mTextureOrientation;
  if ( mTextureOrientation )
  {
    v18 = mTextureOrientation - 1;
    if ( !v18 )
    {
LABEL_6:
      v20 = 126;
      goto LABEL_9;
    }
    v19 = v18 - 1;
    if ( !v19 )
    {
      v20 = -1;
      goto LABEL_9;
    }
    if ( v19 == 1 && (unsigned int)UFG::qRandom(2u, (unsigned int *)this->mParameters->seed) == 1 )
      goto LABEL_6;
  }
  v20 = 0;
LABEL_9:
  pAttrib->vRotationI[3] = v20;
  Render::ParticleGenerator::CreateVelocity(this, pAttrib);
  v21 = this->mParameters->pfx;
  if ( v21->mType != 2 )
  {
    v22 = (int)v21->mSettings.AnimExtras[1];
    if ( v21->mSettings.AnimUVScaleOffset[2] > 0.0 && (v21->mBitFields[0] & 8) != 0 )
      v23 = _mm_cvtsi32_si128(
              v22
            + (unsigned int)UFG::qRandom(
                              (int)v21->mSettings.AnimExtras[2] - v22 + 1,
                              (unsigned int *)this->mParameters->seed));
    else
      v23 = _mm_cvtsi32_si128(v22);
    LODWORD(pAttrib->fAnimStartFrame) = _mm_cvtepi32_ps(v23).m128_u32[0];
  }
  v24 = this->mParameters->end_time;
  pAttrib->fStartTime = this->mParameters->start_time;
  pAttrib->fEndTime = v24;
}

