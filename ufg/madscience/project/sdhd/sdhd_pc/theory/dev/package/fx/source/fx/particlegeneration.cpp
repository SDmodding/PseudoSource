// File Line: 26
// RVA: 0x1E77B0
void __fastcall Render::`anonymous namespace'::MatrixToEulerAngles(UFG::qMatrix44 *mat, UFG::qVector3 *euler)
{
  float v2; // xmm0_4
  UFG::qVector3 *v3; // rdi
  UFG::qMatrix44 *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm0_4
  float v8; // xmm7_4
  float v9; // xmm9_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4

  v2 = mat->v2.x;
  v3 = euler;
  v4 = mat;
  if ( v2 <= -1.0 )
  {
    v2 = FLOAT_N1_0;
  }
  else if ( v2 >= 1.0 )
  {
    v2 = *(float *)&FLOAT_1_0;
  }
  v5 = asinf(v2);
  v6 = v5;
  v7 = cosf(v5);
  if ( COERCE_FLOAT(LODWORD(v7) & _xmm) <= 0.0049999999 )
  {
    v10 = v4->v1.y;
    v11 = v4->v0.y;
    v9 = 0.0;
  }
  else
  {
    v8 = 1.0 / v7;
    v9 = atan2f(COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * v4->v2.y) ^ _xmm[0]), v8 * v4->v2.z);
    v10 = v8 * v4->v0.x;
    LODWORD(v11) = COERCE_UNSIGNED_INT(v8 * v4->v1.x) ^ _xmm[0];
  }
  v12 = atan2f(v11, v10);
  v3->x = v9;
  v3->y = v6;
  v3->z = v12;
}

// File Line: 60
// RVA: 0x1E67F0
void __fastcall Render::ParticleGenerator::CreateScale(Render::ParticleGenerator *this, Render::EmitterParticleAttribute *attribute)
{
  Render::EmitterParticleAttribute *v2; // rbx
  Render::ParticleGenerator *v3; // rdi
  Render::ParticleEmitterSettings *v4; // r8
  int *v5; // rdx
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  Render::ParticleEmitterSettings *v9; // rax
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Render::ParticleEmitterSettings *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  Render::ParticleEmitterSettings *v20; // rcx
  float v21; // xmm8_4
  float v22; // xmm7_4
  float v23; // xmm6_4

  v2 = attribute;
  v3 = this;
  v4 = this->mParameters->pfx;
  v5 = this->mParameters->seed;
  v6 = v4->mXScaleMax;
  v7 = v4->mXScaleMin;
  if ( (LOBYTE(v4->mBitFields[0]) >> 4) & 1 )
  {
    v8 = UFG::qRandom(1.0, v5);
    v9 = v3->mParameters->pfx;
    v10 = (float)(v8 * (float)(v6 - v7)) + v7;
    v11 = v9->mYScaleMin;
    v12 = v9->mYScaleMax;
    v13 = (float)(UFG::qRandom(1.0, v3->mParameters->seed) * (float)(v12 - v11)) + v11;
  }
  else
  {
    v14 = UFG::qRandom(1.0, v5);
    v13 = (float)(v14 * (float)(v6 - v7)) + v7;
    v10 = (float)(v14 * (float)(v6 - v7)) + v7;
  }
  v15 = v3->mParameters->sizeScale;
  v2->vScale.z = v15 * v13;
  v2->vScale.x = v15 * v10;
  v16 = v3->mParameters->pfx;
  v17 = v16->mXScaleSpeedMax;
  v18 = v16->mXScaleSpeedMin;
  v19 = UFG::qRandom(1.0, v3->mParameters->seed);
  v20 = v3->mParameters->pfx;
  v21 = (float)(v19 * (float)(v17 - v18)) + v18;
  if ( (LOBYTE(v20->mBitFields[0]) >> 5) & 1 )
  {
    v22 = v20->mYScaleSpeedMax;
    v23 = v20->mYScaleSpeedMin;
    v2->vScale.w = (float)((float)(v22 - v23) * UFG::qRandom(1.0, v3->mParameters->seed)) + v23;
  }
  else
  {
    v2->vScale.w = v21;
  }
  v2->vScale.y = v21;
}

// File Line: 90
// RVA: 0x1E6650
void __fastcall Render::ParticleGenerator::CreateRotation(Render::ParticleGenerator *this, Render::EmitterParticleAttribute *attribute)
{
  Render::EmitterParticleAttribute *v2; // rdi
  UFG::qMatrix44 **v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::qMatrix44 *v6; // rdx
  float v7; // xmm0_4
  __int64 v8; // rax
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-D8h]
  int v13; // [rsp+30h] [rbp-C8h]
  int v14; // [rsp+34h] [rbp-C4h]
  int v15; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 v16; // [rsp+40h] [rbp-B8h]
  UFG::qMatrix44 rot; // [rsp+50h] [rbp-A8h]
  UFG::qMatrix44 mat; // [rsp+90h] [rbp-68h]

  v2 = attribute;
  v3 = (UFG::qMatrix44 **)this;
  Render::ParticleGenerator::GetRandomVector(
    this,
    &result,
    &this->mParameters->pfx->mRotateMin,
    &this->mParameters->pfx->mRotateMax);
  if ( *(_BYTE *)(*(_QWORD *)&(*v3)[2].v3.x + 724i64) == 3 )
  {
    UFG::qRotationMatrixXYZDepreciated(&rot, &result);
    UFG::qMatrix44::operator*(&rot, &mat, *v3);
    Render::`anonymous namespace'::MatrixToEulerAngles(&mat, &result);
  }
  v13 = (signed int)(float)((float)(result.x + 6.2831855) * 20.292255);
  v14 = (signed int)(float)((float)(result.y + 6.2831855) * 20.292255);
  v15 = (signed int)(float)((float)(result.z + 6.2831855) * 20.292255);
  Render::ParticleGenerator::GetRandomVector(
    (Render::ParticleGenerator *)v3,
    &v16,
    (UFG::qVector3 *)(*(_QWORD *)&(*v3)[2].v3.x + 560i64),
    (UFG::qVector3 *)(*(_QWORD *)&(*v3)[2].v3.x + 572i64));
  v4 = v16.x;
  v5 = v16.y;
  v2->vRotationI[0] = v13;
  v2->vRotationI[1] = v14;
  v2->vRotationI[2] = v15;
  v6 = *v3;
  v2->vRotationV.x = v4;
  v7 = v16.z;
  v2->vRotationV.y = v5;
  v2->vRotationV.z = v7;
  v8 = *(_QWORD *)&v6[2].v3.x;
  v9 = *(float *)(v8 + 520);
  v10 = *(float *)(v8 + 516);
  v11 = UFG::qRandom(1.0, *(int **)&v6[3].v0.x);
  Render::EmitterParticleAttribute::SetRotationDamp(v2, (float)(v11 * (float)(v9 - v10)) + v10);
}

// File Line: 116
// RVA: 0x1E69A0
void __fastcall Render::ParticleGenerator::CreateVelocity(Render::ParticleGenerator *this, Render::EmitterParticleAttribute *pAttrib)
{
  Render::GenerateParticleParameters *v2; // rbx
  Render::EmitterParticleAttribute *v3; // rsi
  Render::ParticleGenerator *v4; // rdi
  UFG::qVector3 *v5; // rax
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm9_4
  Render::GenerateParticleParameters *v9; // rax
  float v10; // xmm7_4
  Render::ParticleEmitterSettings *v11; // r8
  float *v12; // rax
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
  float *v39; // rcx
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
  float v70; // xmm11_4
  float v71; // xmm10_4
  float v72; // xmm7_4
  Render::ParticleEmitterSettings *v73; // rax
  float v74; // xmm8_4
  float v75; // xmm9_4
  float v76; // xmm8_4
  float v77; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-C8h]
  UFG::qVector3 scale; // [rsp+30h] [rbp-B8h]
  float v80; // [rsp+40h] [rbp-A8h]
  float v81; // [rsp+44h] [rbp-A4h]
  float v82; // [rsp+48h] [rbp-A0h]
  float v83; // [rsp+4Ch] [rbp-9Ch]
  float v84; // [rsp+50h] [rbp-98h]
  float v85; // [rsp+54h] [rbp-94h]
  UFG::qVector3 v86; // [rsp+58h] [rbp-90h]
  float v87; // [rsp+68h] [rbp-80h]
  float v88; // [rsp+6Ch] [rbp-7Ch]
  UFG::qMatrix44 dest; // [rsp+70h] [rbp-78h]
  float v90; // [rsp+118h] [rbp+30h]
  float retaddr; // [rsp+128h] [rbp+40h]
  float v92; // [rsp+130h] [rbp+48h]

  v2 = this->mParameters;
  v3 = pAttrib;
  v4 = this;
  v5 = Render::ParticleGenerator::GetRandomVector(
         this,
         &result,
         &this->mParameters->pfx->mNormalVelocityMin,
         &this->mParameters->pfx->mNormalVelocityMax);
  v6 = v5->x;
  v7 = v2->meshNormal.y * v5->y;
  v8 = v2->meshNormal.z * v5->z;
  v9 = v4->mParameters;
  v80 = v7;
  v85 = v8;
  v10 = v6 * v2->meshNormal.x;
  v11 = v9->pfx;
  v82 = v10;
  Render::ParticleGenerator::GetRandomVector(v4, &result, &v11->mLocalVelocityMin, &v11->mLocalVelocityMax);
  Render::ParticleGenerator::GetRandomVector(
    v4,
    &v86,
    &v4->mParameters->pfx->mGlobalVelocityMin,
    &v4->mParameters->pfx->mGlobalVelocityMax);
  v12 = &v4->mParameters->curBasisNormalized.v0.x;
  v13 = v4->mParameters->pfx;
  if ( v13->mSpace == 1 )
  {
    v90 = (float)((float)(v86.y * v4->mInvBasis.v1.x) + (float)(v86.x * v4->mInvBasis.v0.x))
        + (float)(v86.z * v4->mInvBasis.v2.x);
    v32 = v86.z * v4->mInvBasis.v2.y;
    v33 = v86.z * v4->mInvBasis.v2.z;
    v34 = (float)(v86.y * v4->mInvBasis.v1.y) + (float)(v86.x * v4->mInvBasis.v0.y);
    v35 = (float)(v86.y * v4->mInvBasis.v1.z) + (float)(v86.x * v4->mInvBasis.v0.z);
    v84 = result.z;
    v83 = result.y;
    retaddr = result.x;
    v92 = v34 + v32;
    v81 = v35 + v33;
  }
  else
  {
    v14 = v10;
    v15 = v8 * v12[8];
    v16 = v7 * v12[5];
    v17 = (float)(v10 * v12[2]) + (float)(v7 * v12[6]);
    v18 = v10 * *v12;
    v19 = v8 * v12[9];
    v20 = v14 * v12[1];
    v21 = v7 * v12[4];
    v85 = (float)(v8 * v12[10]) + v17;
    v22 = v18 + v21;
    v23 = result.x * v12[1];
    v24 = result.y * v12[5];
    v25 = v19 + (float)(v20 + v16);
    v26 = result.y * v12[4];
    v27 = result.y * v12[6];
    v80 = v25;
    v82 = v22 + v15;
    v28 = (float)(result.x * *v12) + v26;
    v29 = result.z * v12[8];
    v30 = result.z * v12[10];
    v31 = (float)(result.x * v12[2]) + v27;
    v92 = v86.y;
    v83 = (float)(result.z * v12[9]) + (float)(v23 + v24);
    v90 = v86.x;
    retaddr = v29 + v28;
    v84 = v30 + v31;
    v81 = v86.z;
  }
  Render::ParticleGenerator::GetRandomVector(v4, &scale, &v13->mInheritVelocityMin, &v13->mInheritVelocityMax);
  v36 = scale.x;
  if ( scale.x != UFG::qVector3::msZero.x
    || (v37 = scale.y, scale.y != UFG::qVector3::msZero.y)
    || (v38 = scale.z, scale.z != UFG::qVector3::msZero.z) )
  {
    UFG::qScaleMatrix(&dest, &scale);
    v39 = &v4->mParameters->curBasisNormalized.v0.x;
    v40 = v4->mParameters->emitterVelocity.z;
    v41 = v4->mParameters->emitterVelocity.x;
    v42 = v4->mParameters->emitterVelocity.z * v4->mInvBasis.v2.x;
    if ( v4->mParameters->pfx->mSpace == 1 )
    {
      v43 = (float)((float)((float)(v41 * v4->mInvBasis.v0.x) + (float)(v39[39] * v4->mInvBasis.v1.x)) + v42)
          + (float)(v4->mInvBasis.v3.x * 0.0);
      v44 = (float)((float)((float)(v41 * v4->mInvBasis.v0.y) + (float)(v39[39] * v4->mInvBasis.v1.y))
                  + (float)(v40 * v4->mInvBasis.v2.y))
          + (float)(v4->mInvBasis.v3.y * 0.0);
      v45 = (float)((float)((float)(v4->mParameters->emitterVelocity.x * v4->mInvBasis.v0.z)
                          + (float)(v39[39] * v4->mInvBasis.v1.z))
                  + (float)(v40 * v4->mInvBasis.v2.z))
          + (float)(v4->mInvBasis.v3.z * 0.0);
      v46 = (float)((float)((float)(v39[39] * v4->mInvBasis.v1.w) + (float)(v41 * v4->mInvBasis.v0.w))
                  + (float)(v40 * v4->mInvBasis.v2.w))
          + (float)(v4->mInvBasis.v3.w * 0.0);
      v47 = (float)((float)((float)(dest.v0.x * v43) + (float)(v87 * v44)) + (float)(dest.v0.z * v45))
          + (float)(dest.v1.z * v46);
      v48 = (float)((float)((float)(dest.v0.y * v43) + (float)(v88 * v44)) + (float)(dest.v0.w * v45))
          + (float)(dest.v1.w * v46);
      v49 = (float)((float)((float)(dest.v0.z * v43) + (float)(dest.v0.x * v44)) + (float)(dest.v1.x * v45))
          + (float)(dest.v2.x * v46);
      v50 = (float)((float)((float)(dest.v0.w * v43) + (float)(dest.v0.y * v44)) + (float)(dest.v1.y * v45))
          + (float)(dest.v2.y * v46);
      v51 = (float)((float)((float)(v48 * v39[4]) + (float)(v47 * *v39)) + (float)(v49 * v39[8]))
          + (float)(v50 * v39[12]);
      v52 = (float)((float)((float)(v47 * v39[1]) + (float)(v48 * v39[5])) + (float)(v49 * v39[9]))
          + (float)(v50 * v39[13]);
      v53 = (float)((float)((float)(v47 * v39[2]) + (float)(v48 * v39[6])) + (float)(v49 * v39[10]))
          + (float)(v50 * v39[14]);
      v54 = (float)((float)((float)(v47 * v39[3]) + (float)(v48 * v39[7])) + (float)(v49 * v39[11]))
          + (float)(v50 * v39[15]);
      v55 = v53 * v4->mInvBasis.v2.y;
      v36 = (float)((float)((float)(v52 * v4->mInvBasis.v1.x) + (float)(v51 * v4->mInvBasis.v0.x))
                  + (float)(v53 * v4->mInvBasis.v2.x))
          + (float)(v54 * v4->mInvBasis.v3.x);
      v56 = (float)(v52 * v4->mInvBasis.v1.y) + (float)(v51 * v4->mInvBasis.v0.y);
      v57 = v54 * v4->mInvBasis.v3.y;
      v38 = (float)((float)((float)(v52 * v4->mInvBasis.v1.z) + (float)(v51 * v4->mInvBasis.v0.z))
                  + (float)(v53 * v4->mInvBasis.v2.z))
          + (float)(v54 * v4->mInvBasis.v3.z);
    }
    else
    {
      v58 = v39[39];
      v59 = (float)((float)((float)(v58 * v4->mInvBasis.v1.x) + (float)(v41 * v4->mInvBasis.v0.x)) + v42)
          + (float)(v4->mInvBasis.v3.x * 0.0);
      v60 = (float)((float)((float)(v39[39] * v4->mInvBasis.v1.y) + (float)(v41 * v4->mInvBasis.v0.y))
                  + (float)(v40 * v4->mInvBasis.v2.y))
          + (float)(v4->mInvBasis.v3.y * 0.0);
      v61 = (float)((float)((float)(v39[39] * v4->mInvBasis.v1.z) + (float)(v41 * v4->mInvBasis.v0.z))
                  + (float)(v40 * v4->mInvBasis.v2.z))
          + (float)(v4->mInvBasis.v3.z * 0.0);
      v62 = (float)((float)((float)(v58 * v4->mInvBasis.v1.w) + (float)(v41 * v4->mInvBasis.v0.w))
                  + (float)(v40 * v4->mInvBasis.v2.w))
          + (float)(v4->mInvBasis.v3.w * 0.0);
      v63 = (float)((float)((float)(dest.v0.x * v59) + (float)(v87 * v60)) + (float)(dest.v0.z * v61))
          + (float)(dest.v1.z * v62);
      v64 = (float)((float)((float)(dest.v0.y * v59) + (float)(v88 * v60)) + (float)(dest.v0.w * v61))
          + (float)(dest.v1.w * v62);
      v65 = (float)((float)((float)(dest.v0.z * v59) + (float)(dest.v0.x * v60)) + (float)(dest.v1.x * v61))
          + (float)(dest.v2.x * v62);
      v66 = (float)((float)((float)(dest.v0.w * v59) + (float)(dest.v0.y * v60)) + (float)(dest.v1.y * v61))
          + (float)(dest.v2.y * v62);
      v55 = v65 * v39[9];
      v36 = (float)((float)((float)(v64 * v39[4]) + (float)(v63 * *v39)) + (float)(v65 * v39[8]))
          + (float)(v66 * v39[12]);
      v56 = (float)(v64 * v39[5]) + (float)(v63 * v39[1]);
      v57 = v66 * v39[13];
      v38 = (float)((float)((float)(v64 * v39[6]) + (float)(v63 * v39[2])) + (float)(v65 * v39[10]))
          + (float)(v66 * v39[14]);
    }
    scale.z = v38;
    scale.x = v36;
    v37 = (float)(v56 + v55) + v57;
    scale.y = v37;
  }
  v67 = (float)(v4->mParameters->velocityScale * (float)((float)(v90 + retaddr) + v82)) + v36;
  v68 = (float)(v4->mParameters->velocityScale * (float)((float)(v81 + v84) + v85)) + v38;
  result.y = (float)(v4->mParameters->velocityScale * (float)((float)(v92 + v83) + v80)) + v37;
  result.x = v67;
  result.z = v68;
  Render::EmitterParticleAttribute::SetInitialVelocity(v3, &result);
  v69 = v4->mParameters->pfx;
  v70 = v69->mDragMax;
  v71 = v69->mDragMin;
  v72 = UFG::qRandom(1.0, v4->mParameters->seed);
  v73 = v4->mParameters->pfx;
  v74 = 1.0 / v4->mParameters->transformScale;
  v75 = v74 * v73->mGravityMin;
  v76 = v74 * v73->mGravityMax;
  v77 = UFG::qRandom(1.0, v4->mParameters->seed);
  Render::EmitterParticleAttribute::SetVelocityGravityAndDrag(
    v3,
    &result,
    (float)((float)(v76 - v75) * v77) + v75,
    (float)((float)(v70 - v71) * v72) + v71);
}

// File Line: 167
// RVA: 0x1E7300
Render::EmitterParticleAttribute *__fastcall Render::ParticleGenerator::Generate(Render::ParticleGenerator *this, Render::EmitterParticleAttribute *attribBuffer, unsigned int currentBufferCount)
{
  unsigned int v3; // er14
  Render::EmitterParticleAttribute *v4; // rdi
  Render::ParticleGenerator *v5; // r15
  signed int v6; // esi
  UFG::qHalfVector4 *v7; // rbx
  Render::EmitterParticleAttribute *v8; // rbp
  float v9; // xmm6_4
  int v10; // ebx
  unsigned int v11; // ecx
  Render::ParticleGenerator v13; // [rsp+20h] [rbp-AF8h]
  char dest; // [rsp+70h] [rbp-AA8h]
  UFG::qHalfVector4 v15; // [rsp+88h] [rbp-A90h]

  v3 = currentBufferCount;
  v4 = attribBuffer;
  v5 = this;
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
  if ( v3 )
  {
    while ( v9 <= (float)((float)((float)((float)(v5->mParameters->cameraPos.y - v4->vPosAndGrav.y)
                                        * (float)(v5->mParameters->cameraPos.y - v4->vPosAndGrav.y))
                                + (float)((float)(v5->mParameters->cameraPos.x - v4->vPosAndGrav.x)
                                        * (float)(v5->mParameters->cameraPos.x - v4->vPosAndGrav.x)))
                        + (float)((float)(v5->mParameters->cameraPos.z - v4->vPosAndGrav.z)
                                * (float)(v5->mParameters->cameraPos.z - v4->vPosAndGrav.z))) )
    {
      ++v11;
      ++v4;
      if ( v11 >= v3 )
        goto LABEL_8;
    }
    v10 = v3 - v11;
    UFG::qMemCopy(&dest, v4, 84 * (v3 - v11));
    v8 = v4;
  }
LABEL_8:
  v13.mParameters = v5->mParameters;
  UFG::qInverseAffine(&v13.mInvBasis, &v13.mParameters->curBasisNormalized);
  Render::ParticleGenerator::GenerateAtPosition(&v13, v8);
  if ( v10 )
    UFG::qMemCopy(&v8[1], &dest, 84 * v10);
  return v8;
}

// File Line: 227
// RVA: 0x1E7490
void __fastcall Render::ParticleGenerator::GenerateAtPosition(Render::ParticleGenerator *this, Render::EmitterParticleAttribute *pAttrib)
{
  Render::GenerateParticleParameters *v2; // r8
  Render::ParticleGenerator *v3; // rsi
  Render::EmitterParticleAttribute *v4; // rdi
  float v5; // eax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // eax
  float v10; // xmm2_4
  Render::GenerateParticleParameters *v11; // rbx
  Render::ParticleEmitterSettings *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  Render::ParticleLighting *v16; // rcx
  unsigned int v17; // edx
  int v18; // edx
  int v19; // edx
  char v20; // al
  Render::ParticleEmitterSettings *v21; // rcx
  unsigned int v22; // ebx
  __m128i v23; // xmm0
  float v24; // xmm0_4
  UFG::qVector3 particlePosition; // [rsp+20h] [rbp-38h]
  UFG::qColour unlitColour; // [rsp+30h] [rbp-28h]
  UFG::qColour result; // [rsp+40h] [rbp-18h]

  v2 = this->mParameters;
  v3 = this;
  v4 = pAttrib;
  v5 = this->mParameters->pos.x;
  unlitColour.r = 1.0;
  unlitColour.g = 1.0;
  v6 = v2->start_time;
  v7 = v2->end_time;
  v8 = v2->simTime;
  pAttrib->vPosAndGrav.x = v5;
  v9 = v2->pos.y;
  unlitColour.b = 1.0;
  v10 = (float)(v8 - v6) / (float)(v7 - v6);
  pAttrib->vPosAndGrav.y = v9;
  pAttrib->vPosAndGrav.z = v2->pos.z;
  v11 = this->mParameters;
  v12 = this->mParameters->pfx;
  v13 = v11->renderMatrix.v3.y + v11->pos.y;
  v14 = v11->renderMatrix.v3.z + v11->pos.z;
  particlePosition.x = v11->renderMatrix.v3.x + v11->pos.x;
  particlePosition.y = v13;
  particlePosition.z = v14;
  v15 = Render::ComputeInterpolatedAlpha(v12->mSettings.ColorAlphaKeys, v12->mSettings.AlphaKeyPositions, v10);
  v16 = v11->particleLighting;
  unlitColour.a = v15;
  Render::ParticleLighting::ApplyDynamicLights(v16, &result, &unlitColour, &particlePosition);
  unlitColour.r = result.r * result.r;
  unlitColour.g = result.g * result.g;
  unlitColour.b = result.b * result.b;
  unlitColour.a = result.a;
  Render::EmitterParticleAttribute::SetColour(v4, &unlitColour);
  Render::ParticleGenerator::CreateRotation(v3, v4);
  Render::ParticleGenerator::CreateScale(v3, v4);
  v17 = v3->mParameters->pfx->mTextureOrientation;
  if ( v17 )
  {
    v18 = v17 - 1;
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
    if ( v19 == 1 && (unsigned int)UFG::qRandom(2, v3->mParameters->seed) == 1 )
      goto LABEL_6;
  }
  v20 = 0;
LABEL_9:
  v4->vRotationI[3] = v20;
  Render::ParticleGenerator::CreateVelocity(v3, v4);
  v21 = v3->mParameters->pfx;
  if ( v21->mType != 2 )
  {
    v22 = (signed int)v21->mSettings.AnimExtras[1];
    if ( v21->mSettings.AnimUVScaleOffset[2] > 0.0 && (LOBYTE(v21->mBitFields[0]) >> 3) & 1 )
      v23 = _mm_cvtsi32_si128(
              v22
            + (unsigned int)UFG::qRandom((signed int)v21->mSettings.AnimExtras[2] - v22 + 1, v3->mParameters->seed));
    else
      v23 = _mm_cvtsi32_si128(v22);
    LODWORD(v4->fAnimStartFrame) = (unsigned __int128)_mm_cvtepi32_ps(v23);
  }
  v24 = v3->mParameters->end_time;
  v4->fStartTime = v3->mParameters->start_time;
  v4->fEndTime = v24;
}

