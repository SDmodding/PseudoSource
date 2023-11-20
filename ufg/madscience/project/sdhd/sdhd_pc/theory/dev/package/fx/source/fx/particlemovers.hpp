// File Line: 17
// RVA: 0x1E0170
UFG::qVector3 *__fastcall Render::ApplyFXForcesToParticle(UFG::qVector3 *result, UFG::qVector3 *originalPosition, Render::FXForce *forceList, unsigned int numForces)
{
  float *v4; // rax
  __int64 v5; // r8
  float v6; // xmm14_4
  float v7; // xmm15_4
  float v8; // xmm3_4
  float v9; // xmm10_4
  float v10; // xmm6_4
  __m128 v11; // xmm7
  float v12; // xmm8_4
  float v13; // xmm4_4
  float v14; // xmm8_4
  float v15; // xmm6_4
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v22; // [rsp+B0h] [rbp+8h]
  float v23; // [rsp+C8h] [rbp+20h]

  *(_QWORD *)&result->x = 0i64;
  result->z = 0.0;
  if ( numForces )
  {
    v4 = &forceList->radMin;
    v5 = numForces;
    v23 = 0.0;
    v22 = 0.0;
    v6 = originalPosition->x;
    v7 = originalPosition->y;
    do
    {
      v8 = *(v4 - 1);
      if ( v8 >= 0.0 )
      {
        v9 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v9 = FLOAT_N1_0;
        LODWORD(v8) ^= _xmm[0];
      }
      v10 = *(v4 - 4);
      v11 = (__m128)*((unsigned int *)v4 - 3);
      v12 = *(v4 - 2);
      v13 = (float)((float)(fsqrt(
                              (float)((float)((float)(v7 - v11.m128_f32[0]) * (float)(v7 - v11.m128_f32[0]))
                                    + (float)((float)(v6 - v10) * (float)(v6 - v10)))
                            + (float)((float)(originalPosition->z - v12) * (float)(originalPosition->z - v12)))
                          - *v4)
                  * (float)(COERCE_FLOAT(LODWORD(v8) ^ _xmm[0]) / (float)(v4[1] - *v4)))
          + v8;
      if ( v13 <= 0.0 )
        v13 = 0.0;
      if ( v13 >= v8 )
        v13 = v8;
      v14 = v12 - originalPosition->z;
      v15 = v10 - v6;
      v11.m128_f32[0] = v11.m128_f32[0] - v7;
      v16 = v11;
      v16.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v15 * v15)) + (float)(v14 * v14);
      if ( v16.m128_f32[0] == 0.0 )
        v17 = 0.0;
      else
        v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
      v4 += 6;
      v18 = (float)(v11.m128_f32[0] * v17) * v13;
      v19 = v23 + (float)(v18 * v9);
      result->x = (float)((float)((float)(v15 * v17) * v13) * v9) + result->x;
      v23 = v23 + (float)(v18 * v9);
      v20 = v22 + (float)((float)((float)(v14 * v17) * v13) * v9);
      v22 = v20;
      --v5;
    }
    while ( v5 );
    result->y = v19;
    result->z = v20;
  }
  return result;
}

// File Line: 78
// RVA: 0x1E03A0
void __fastcall Render::CalcPositionAndVelocityInSimulatedLocalSpace(Render::EmitterParticleAttribute *attr, Render::ParticleRenderUpdateTaskParam *taskParams, UFG::qMatrix44 *curBasisNormalized, UFG::qMatrix44 *worldLocal, UFG::qMatrix44 *inverseOldBasis, float transformScale, UFG::qVector3 *resultWorldSpacePosition, UFG::qVector3 *resultWorldSpaceVelocity)
{
  float v8; // xmm6_4
  float v9; // xmm7_4
  Render::ParticleRenderUpdateTaskParam *v10; // rbx
  Render::EmitterParticleAttribute *v11; // rsi
  UFG::qHalfVector4 *v12; // rcx
  UFG::qMatrix44 *v13; // rbp
  float v14; // xmm8_4
  UFG::qMatrix44 *v15; // rdi
  UFG::qMatrix44 *v16; // rax
  float v17; // xmm5_4
  float v18; // xmm11_4
  float v19; // xmm13_4
  float v20; // xmm4_4
  float v21; // xmm9_4
  float v22; // xmm14_4
  float v23; // xmm12_4
  float v24; // xmm15_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm13_4
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm8_4
  float v31; // xmm11_4
  float v32; // xmm10_4
  float v33; // xmm7_4
  float v34; // xmm13_4
  float v35; // xmm5_4
  float v36; // xmm9_4
  float v37; // xmm5_4
  float v38; // xmm12_4
  float v39; // xmm2_4
  float v40; // xmm15_4
  float v41; // xmm3_4
  __int64 v42; // ST24_8
  float v43; // ST20_4
  float v44; // xmm0_4
  float v45; // xmm14_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm5_4
  float v51; // xmm15_4
  float v52; // xmm13_4
  float v53; // xmm1_4
  float v54; // xmm4_4
  float v55; // xmm6_4
  float v56; // xmm15_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float v59; // xmm0_4
  UFG::qVector4 result; // [rsp+2Ch] [rbp-DCh]
  float v61; // [rsp+110h] [rbp+8h]
  float v62; // [rsp+120h] [rbp+18h]
  float v63; // [rsp+120h] [rbp+18h]
  float v64; // [rsp+128h] [rbp+20h]
  float inverseOldBasisa; // [rsp+130h] [rbp+28h]
  float inverseOldBasisb; // [rsp+130h] [rbp+28h]

  v8 = attr->vPosAndGrav.x;
  v9 = attr->vPosAndGrav.y;
  v10 = taskParams;
  v11 = attr;
  v12 = &attr->vVelAndDamp;
  v13 = worldLocal;
  v14 = *(float *)&v12[-1].x.mRep;
  v15 = curBasisNormalized;
  UFG::qHalfVector4::operator UFG::qVector4 const(v12, &result);
  v16 = inverseOldBasis;
  v17 = inverseOldBasis->v1.y;
  v18 = inverseOldBasis->v2.y;
  v19 = inverseOldBasis->v3.y;
  v20 = inverseOldBasis->v1.z;
  v21 = inverseOldBasis->v2.z;
  v22 = inverseOldBasis->v3.x;
  v23 = inverseOldBasis->v3.z;
  v24 = (float)((float)(inverseOldBasis->v0.x * v8) + (float)(inverseOldBasis->v1.x * v9))
      + (float)(inverseOldBasis->v2.x * v14);
  v62 = (float)((float)((float)(inverseOldBasis->v0.y * v8) + (float)(inverseOldBasis->v1.y * v9))
              + (float)(inverseOldBasis->v2.y * v14))
      + v19;
  v25 = inverseOldBasis->v0.z * v8;
  v26 = inverseOldBasis->v0.y;
  v64 = (float)((float)(v25 + (float)(inverseOldBasis->v1.z * v9)) + (float)(inverseOldBasis->v2.z * v14)) + v23;
  inverseOldBasisa = (float)((float)((float)(inverseOldBasis->v0.x * result.x)
                                   + (float)(inverseOldBasis->v1.x * result.y))
                           + (float)(inverseOldBasis->v2.x * result.z))
                   + (float)(v22 * 0.0);
  v61 = (float)((float)((float)(v26 * result.x) + (float)(v17 * result.y)) + (float)(v18 * result.z))
      + (float)(v19 * 0.0);
  v27 = v62;
  v28 = v10->deltaTime;
  v29 = v15->v1.x;
  v30 = v15->v2.y;
  v31 = v15->v3.y;
  v32 = v15->v3.z;
  LODWORD(v63) = (((((unsigned int)v11->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v11->vVelAndDamp.w.mRep & 0x3FF | 8 * (v11->vVelAndDamp.w.mRep & 0x8000)) << 13);
  v33 = v15->v2.z;
  v34 = v27 + (float)(v61 * v28);
  v35 = (float)((float)(v16->v0.z * result.x) + (float)(v20 * result.y)) + (float)(v21 * result.z);
  v36 = v15->v2.x;
  v37 = v35 + (float)(v23 * 0.0);
  v38 = v15->v3.x;
  v39 = (float)(inverseOldBasisa * v28) + (float)(v24 + v22);
  v40 = v15->v0.z;
  v41 = v64 + (float)(v37 * v28);
  *(float *)&v42 = (float)((float)((float)(v15->v0.x * v39) + (float)(v29 * v34)) + (float)(v36 * v41)) + v38;
  v43 = v15->v0.y;
  *((float *)&v42 + 1) = (float)((float)((float)(v43 * v39) + (float)(v15->v1.y * v34)) + (float)(v30 * v41)) + v31;
  v44 = v10->deltaTime;
  v45 = (float)((float)((float)(v40 * v39) + (float)(v15->v1.z * v34)) + (float)(v33 * v41)) + v32;
  v46 = inverseOldBasisa * v44;
  v47 = v61 * v44;
  v48 = v37 - (float)((float)(v37 * v44) * v63);
  inverseOldBasisb = inverseOldBasisa - (float)(v46 * v63);
  v49 = v61 - (float)(v47 * v63);
  v50 = v15->v1.y * v49;
  v51 = (float)(v40 * inverseOldBasisb) + (float)(v15->v1.z * v49);
  v52 = (float)((float)(v15->v0.x * inverseOldBasisb) + (float)(v29 * v49)) + (float)(v36 * v48);
  v53 = (float)(v13->v1.z + v13->v0.z) * 0.0;
  v54 = (float)((float)(v13->v1.x + v13->v0.x) * 0.0)
      + (float)((float)(transformScale * v11->vPosAndGrav.w) * v13->v2.x);
  v55 = (float)((float)(v43 * inverseOldBasisb) + v50) + (float)(v30 * v48);
  v56 = (float)(v51 + (float)(v33 * v48)) + (float)(v32 * 0.0);
  v57 = (float)(transformScale * v11->vPosAndGrav.w) * v13->v2.z;
  v58 = (float)((float)(v13->v1.y + v13->v0.y) * 0.0)
      + (float)((float)(transformScale * v11->vPosAndGrav.w) * v13->v2.y);
  v59 = v10->deltaTime;
  resultWorldSpacePosition->z = v45;
  *(_QWORD *)&resultWorldSpacePosition->x = v42;
  resultWorldSpaceVelocity->y = (float)(v55 + (float)(v31 * 0.0)) + (float)(v58 * v59);
  resultWorldSpaceVelocity->x = (float)(v52 + (float)(v38 * 0.0)) + (float)(v54 * v59);
  resultWorldSpaceVelocity->z = v56 + (float)((float)(v53 + v57) * v59);
}

// File Line: 113
// RVA: 0x1E0AB0
void __fastcall Render::CalcWorldSpacePositionAndVelocity(Render::EmitterParticleAttribute *attr, Render::ParticleRenderUpdateTaskParam *taskParams, UFG::qMatrix44 *worldLocal, float transformScale, UFG::qVector3 *resultWorldSpacePosition, UFG::qVector3 *resultWorldSpaceVelocity)
{
  Render::ParticleRenderUpdateTaskParam *v6; // rbx
  Render::EmitterParticleAttribute *v7; // rsi
  UFG::qHalfVector4 *v8; // rcx
  UFG::qMatrix44 *v9; // rdi
  float v10; // xmm11_4
  float v11; // xmm13_4
  float v12; // xmm12_4
  float v13; // xmm6_4
  float v14; // xmm10_4
  float v15; // xmm13_4
  float v16; // xmm12_4
  float v17; // xmm8_4
  float v18; // xmm9_4
  float v19; // xmm7_4
  UFG::qVector4 result; // [rsp+20h] [rbp-98h]
  float v21; // [rsp+D8h] [rbp+20h]

  v6 = taskParams;
  v7 = attr;
  v8 = &attr->vVelAndDamp;
  v9 = worldLocal;
  v10 = *(float *)&v8[-2].x.mRep;
  v11 = *(float *)&v8[-1].x.mRep;
  v12 = *(float *)&v8[-2].z.mRep;
  UFG::qHalfVector4::operator UFG::qVector4 const(v8, &result);
  v13 = transformScale * v7->vPosAndGrav.w;
  v14 = v6->deltaTime;
  LODWORD(v21) = (((((unsigned int)v7->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v7->vVelAndDamp.w.mRep & 0x3FF | 8 * (v7->vVelAndDamp.w.mRep & 0x8000)) << 13);
  v15 = v11 + (float)(result.z * v14);
  v16 = v12 + (float)(result.y * v14);
  v17 = (float)((float)((float)((float)(v9->v1.y + v9->v0.y) * 0.0) + (float)(v13 * v9->v2.y)) * v14) + result.y;
  v18 = (float)((float)((float)((float)(v9->v1.x + v9->v0.x) * 0.0) + (float)(v13 * v9->v2.x)) * v14) + result.x;
  v19 = (float)((float)((float)((float)(v9->v1.z + v9->v0.z) * 0.0) + (float)(v13 * v9->v2.z)) * v14) + result.z;
  resultWorldSpacePosition->x = v10 + (float)(result.x * v14);
  resultWorldSpacePosition->y = v16;
  resultWorldSpacePosition->z = v15;
  resultWorldSpaceVelocity->x = v18 - (float)((float)(v18 * v14) * v21);
  resultWorldSpaceVelocity->y = v17 - (float)((float)(v17 * v14) * v21);
  resultWorldSpaceVelocity->z = v19 - (float)((float)(v19 * v14) * v21);
}

// File Line: 154
// RVA: 0x1E08A0
void __fastcall Render::CalcPositionAndVelocityWithLocalToWorldInterpolation(Render::EmitterParticleAttribute *attr, Render::ParticleRenderUpdateTaskParam *taskParams, Render::ParticleEmitterSettings *settings, UFG::qMatrix44 *curBasisNormalized, UFG::qMatrix44 *worldLocal, UFG::qMatrix44 *inverseOldBasis, float transformScale, UFG::qVector3 *resultWorldSpacePosition, UFG::qVector3 *resultWorldSpaceVelocity)
{
  UFG::qMatrix44 *v9; // r14
  Render::ParticleEmitterSettings *v10; // rsi
  Render::ParticleRenderUpdateTaskParam *v11; // rbp
  Render::EmitterParticleAttribute *v12; // rdi
  float v13; // xmm2_4
  float v14; // xmm9_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  UFG::qVector3 v20; // [rsp+40h] [rbp-88h]
  UFG::qVector3 v21; // [rsp+50h] [rbp-78h]
  UFG::qVector3 v22; // [rsp+60h] [rbp-68h]
  float v23; // [rsp+70h] [rbp-58h]
  float v24; // [rsp+74h] [rbp-54h]
  float v25; // [rsp+78h] [rbp-50h]

  v9 = curBasisNormalized;
  v10 = settings;
  v11 = taskParams;
  v12 = attr;
  Render::CalcPositionAndVelocityInSimulatedLocalSpace(
    attr,
    taskParams,
    curBasisNormalized,
    worldLocal,
    inverseOldBasis,
    transformScale,
    &v21,
    (UFG::qVector3 *)&v23);
  Render::CalcWorldSpacePositionAndVelocity(v12, v11, worldLocal, transformScale, &v20, &v22);
  v13 = (float)((float)(v11->simTime - v12->fStartTime) / (float)(v12->fEndTime - v12->fStartTime))
      * v10->mLocalSpaceToWorldSpaceBlend;
  if ( v13 <= 0.0 )
  {
    v13 = 0.0;
  }
  else
  {
    v14 = *(float *)&FLOAT_1_0;
    if ( v13 >= 1.0 )
      goto LABEL_6;
  }
  v14 = v13;
LABEL_6:
  v15 = (float)((float)(v22.x - v23) * v14) + v23;
  v16 = (float)((float)(v22.y - v24) * v14) + v24;
  v17 = (float)((float)(v22.z - v25) * v14) + v25;
  v18 = (float)((float)((float)(v20.y + (float)((float)(v9->v3.y - v11->oldBasis.v3.y) * v14)) - v21.y) * v14) + v21.y;
  v19 = (float)((float)((float)(v20.z + (float)((float)(v9->v3.z - v11->oldBasis.v3.z) * v14)) - v21.z) * v14) + v21.z;
  resultWorldSpacePosition->x = (float)((float)((float)(v20.x + (float)((float)(v9->v3.x - v11->oldBasis.v3.x) * v14))
                                              - v21.x)
                                      * v14)
                              + v21.x;
  resultWorldSpacePosition->y = v18;
  resultWorldSpacePosition->z = v19;
  resultWorldSpaceVelocity->x = v15;
  resultWorldSpaceVelocity->y = v16;
  resultWorldSpaceVelocity->z = v17;
}

// File Line: 188
// RVA: 0x1E0CB0
void __fastcall Render::CalcWorldSpacePositionAndVelocityToTarget(Render::EmitterParticleAttribute *attr, Render::ParticleRenderUpdateTaskParam *taskParams, UFG::qVector3 *resultWorldSpacePosition, UFG::qVector3 *resultWorldSpaceVelocity)
{
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm11_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4

  v4 = attr->vPosAndGrav.y;
  v5 = attr->vPosAndGrav.z;
  v6 = taskParams->targetPosition.x - attr->vPosAndGrav.x;
  v7 = taskParams->targetPosition.y - v4;
  v8 = taskParams->targetPosition.z - v5;
  if ( (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8)) >= 0.0625 )
  {
    v12 = 1.0 / (float)(attr->fEndTime - taskParams->simTime);
    v13 = taskParams->deltaTime;
    v11 = v5 + (float)((float)(v12 * v8) * v13);
    v9 = attr->vPosAndGrav.x + (float)((float)(v12 * v6) * v13);
    v10 = v4 + (float)((float)(v12 * v7) * v13);
  }
  else
  {
    v9 = taskParams->targetPosition.x;
    v10 = taskParams->targetPosition.y;
    v11 = taskParams->targetPosition.z;
  }
  resultWorldSpacePosition->z = v11;
  resultWorldSpacePosition->x = v9;
  resultWorldSpacePosition->y = v10;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  resultWorldSpaceVelocity->x = UFG::qVector3::msZero.x;
  resultWorldSpaceVelocity->y = v14;
  resultWorldSpaceVelocity->z = v15;
}

// File Line: 216
// RVA: 0x1DD550
void __fastcall Render::TargetParticleMover::TargetParticleMover(Render::TargetParticleMoverWithBlend *this, Render::ParticleRenderUpdateTaskParam *taskParams, Render::ParticleEmitterSettings *pfx, Render::ParticleLighting *particleLighting, float transformScale, UFG::qMatrix44 *worldLocal)
{
  float v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // eax
  float v17; // xmm2_4

  v6 = worldLocal->v0.x;
  v7 = worldLocal->v0.z;
  v8 = worldLocal->v0.w;
  this->mWorldLocal.v0.y = worldLocal->v0.y;
  this->mWorldLocal.v0.z = v7;
  this->mWorldLocal.v0.x = v6;
  this->mWorldLocal.v0.w = v8;
  v9 = worldLocal->v1.z;
  v10 = worldLocal->v1.x;
  v11 = worldLocal->v1.w;
  this->mWorldLocal.v1.y = worldLocal->v1.y;
  this->mWorldLocal.v1.z = v9;
  this->mWorldLocal.v1.x = v10;
  this->mWorldLocal.v1.w = v11;
  v12 = worldLocal->v2.z;
  v13 = worldLocal->v2.x;
  v14 = worldLocal->v2.w;
  this->mWorldLocal.v2.y = worldLocal->v2.y;
  this->mWorldLocal.v2.z = v12;
  this->mWorldLocal.v2.x = v13;
  this->mWorldLocal.v2.w = v14;
  v15 = worldLocal->v3.z;
  v16 = worldLocal->v3.x;
  v17 = worldLocal->v3.w;
  this->mWorldLocal.v3.y = worldLocal->v3.y;
  this->mWorldLocal.v3.x = v16;
  this->mWorldLocal.v3.z = v15;
  this->mWorldLocal.v3.w = v17;
  this->mTransformScaleFactor = transformScale;
  this->mSettings = pfx;
  this->mParticleLighting = particleLighting;
  this->mTaskParams = taskParams;
}

// File Line: 220
// RVA: 0x1DE120
void __fastcall Render::BasicParticleMover::operator()(Render::BasicParticleMover *this, Render::EmitterParticleAttribute *attr)
{
  float v2; // xmm3_4
  Render::EmitterParticleAttribute *v3; // rdi
  Render::ParticleRenderUpdateTaskParam *v4; // rdx
  Render::BasicParticleMover *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm8_4
  float *v11; // rax
  Render::ParticleEmitterSettings *v12; // rcx
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm0_4
  Render::ParticleLighting *v17; // rcx
  UFG::qVector3 particlePosition; // [rsp+28h] [rbp-19h]
  UFG::qVector3 resultWorldSpaceVelocity; // [rsp+38h] [rbp-9h]
  float v20; // [rsp+44h] [rbp+3h]
  UFG::qColour result; // [rsp+48h] [rbp+7h]

  v2 = this->mTransformScaleFactor;
  v3 = attr;
  v4 = this->mTaskParams;
  v5 = this;
  v6 = v3->fEndTime - v3->fStartTime;
  *(_QWORD *)&particlePosition.x = (char *)&resultWorldSpaceVelocity + 8;
  v7 = (float)(v4->simTime - v3->fStartTime) / v6;
  Render::CalcWorldSpacePositionAndVelocity(
    v3,
    v4,
    &this->mWorldLocal,
    v2,
    (UFG::qVector3 *)((char *)&particlePosition + 8),
    (UFG::qVector3 *)((char *)&resultWorldSpaceVelocity + 8));
  v8 = particlePosition.x;
  v9 = particlePosition.y;
  v10 = particlePosition.z;
  v3->vPosAndGrav.x = particlePosition.x;
  v3->vPosAndGrav.y = v9;
  v3->vPosAndGrav.z = v10;
  Render::EmitterParticleAttribute::SetVelocity(v3, &resultWorldSpaceVelocity);
  v11 = &v5->mTaskParams->renderMatrix.v0.x;
  v12 = v5->mSettings;
  v13 = v8 + v11[12];
  v14 = v9 + v11[13];
  v15 = v10 + v11[14];
  resultWorldSpaceVelocity.x = 1.0;
  resultWorldSpaceVelocity.y = 1.0;
  resultWorldSpaceVelocity.z = 1.0;
  particlePosition.x = v13;
  particlePosition.y = v14;
  particlePosition.z = v15;
  v16 = Render::ComputeInterpolatedAlpha(v12->mSettings.ColorAlphaKeys, v12->mSettings.AlphaKeyPositions, v7);
  v17 = v5->mParticleLighting;
  v20 = v16;
  Render::ParticleLighting::ApplyDynamicLights(
    v17,
    &result,
    (UFG::qColour *)&resultWorldSpaceVelocity,
    &particlePosition);
  resultWorldSpaceVelocity.x = result.r * result.r;
  resultWorldSpaceVelocity.y = result.g * result.g;
  resultWorldSpaceVelocity.z = result.b * result.b;
  v20 = result.a;
  Render::EmitterParticleAttribute::SetColour(v3, (UFG::qColour *)&resultWorldSpaceVelocity);
}

// File Line: 263
// RVA: 0x1DD860
void __fastcall Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(Render::BasicParticleMoverWithLocalToWorldBlend *this, Render::ParticleRenderUpdateTaskParam *taskParams, Render::ParticleEmitterSettings *pfx, Render::ParticleLighting *particleLighting, float transformScale, UFG::qMatrix44 *curBasisNormalized, UFG::qMatrix44 *worldLocal, UFG::qMatrix44 *invOldBasis)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4

  v8 = invOldBasis->v0.y;
  v9 = invOldBasis->v0.z;
  v10 = invOldBasis->v0.w;
  this->mInverseOldBasis.v0.x = invOldBasis->v0.x;
  this->mInverseOldBasis.v0.y = v8;
  this->mInverseOldBasis.v0.z = v9;
  this->mInverseOldBasis.v0.w = v10;
  v11 = invOldBasis->v1.y;
  v12 = invOldBasis->v1.z;
  v13 = invOldBasis->v1.w;
  this->mInverseOldBasis.v1.x = invOldBasis->v1.x;
  this->mInverseOldBasis.v1.y = v11;
  this->mInverseOldBasis.v1.z = v12;
  this->mInverseOldBasis.v1.w = v13;
  v14 = invOldBasis->v2.y;
  v15 = invOldBasis->v2.z;
  v16 = invOldBasis->v2.w;
  this->mInverseOldBasis.v2.x = invOldBasis->v2.x;
  this->mInverseOldBasis.v2.y = v14;
  this->mInverseOldBasis.v2.z = v15;
  this->mInverseOldBasis.v2.w = v16;
  v17 = invOldBasis->v3.y;
  v18 = invOldBasis->v3.z;
  v19 = invOldBasis->v3.w;
  this->mInverseOldBasis.v3.x = invOldBasis->v3.x;
  this->mInverseOldBasis.v3.y = v17;
  this->mInverseOldBasis.v3.z = v18;
  this->mInverseOldBasis.v3.w = v19;
  v20 = worldLocal->v0.y;
  v21 = worldLocal->v0.z;
  v22 = worldLocal->v0.w;
  this->mWorldLocal.v0.x = worldLocal->v0.x;
  this->mWorldLocal.v0.y = v20;
  this->mWorldLocal.v0.z = v21;
  this->mWorldLocal.v0.w = v22;
  v23 = worldLocal->v1.y;
  v24 = worldLocal->v1.z;
  v25 = worldLocal->v1.w;
  this->mWorldLocal.v1.x = worldLocal->v1.x;
  this->mWorldLocal.v1.y = v23;
  this->mWorldLocal.v1.z = v24;
  this->mWorldLocal.v1.w = v25;
  v26 = worldLocal->v2.y;
  v27 = worldLocal->v2.z;
  v28 = worldLocal->v2.w;
  this->mWorldLocal.v2.x = worldLocal->v2.x;
  this->mWorldLocal.v2.y = v26;
  this->mWorldLocal.v2.z = v27;
  this->mWorldLocal.v2.w = v28;
  v29 = worldLocal->v3.y;
  v30 = worldLocal->v3.z;
  v31 = worldLocal->v3.w;
  this->mWorldLocal.v3.x = worldLocal->v3.x;
  this->mWorldLocal.v3.y = v29;
  this->mWorldLocal.v3.z = v30;
  this->mWorldLocal.v3.w = v31;
  v32 = curBasisNormalized->v0.y;
  v33 = curBasisNormalized->v0.z;
  v34 = curBasisNormalized->v0.w;
  this->mCurBasisNormalized.v0.x = curBasisNormalized->v0.x;
  this->mCurBasisNormalized.v0.y = v32;
  this->mCurBasisNormalized.v0.z = v33;
  this->mCurBasisNormalized.v0.w = v34;
  v35 = curBasisNormalized->v1.y;
  v36 = curBasisNormalized->v1.z;
  v37 = curBasisNormalized->v1.w;
  this->mCurBasisNormalized.v1.x = curBasisNormalized->v1.x;
  this->mCurBasisNormalized.v1.y = v35;
  this->mCurBasisNormalized.v1.z = v36;
  this->mCurBasisNormalized.v1.w = v37;
  v38 = curBasisNormalized->v2.y;
  v39 = curBasisNormalized->v2.z;
  v40 = curBasisNormalized->v2.w;
  this->mCurBasisNormalized.v2.x = curBasisNormalized->v2.x;
  this->mCurBasisNormalized.v2.y = v38;
  this->mCurBasisNormalized.v2.z = v39;
  this->mCurBasisNormalized.v2.w = v40;
  v41 = curBasisNormalized->v3.y;
  v42 = curBasisNormalized->v3.z;
  v43 = curBasisNormalized->v3.w;
  this->mCurBasisNormalized.v3.x = curBasisNormalized->v3.x;
  this->mCurBasisNormalized.v3.y = v41;
  this->mCurBasisNormalized.v3.z = v42;
  this->mCurBasisNormalized.v3.w = v43;
  this->mTransformScaleFactor = transformScale;
  this->mSettings = pfx;
  this->mParticleLighting = particleLighting;
  this->mTaskParams = taskParams;
}

// File Line: 267
// RVA: 0x1DE2A0
void __fastcall Render::BasicParticleMoverWithLocalToWorldBlend::operator()(Render::BasicParticleMoverWithLocalToWorldBlend *this, Render::EmitterParticleAttribute *attr)
{
  Render::BasicParticleMoverWithLocalToWorldBlend *v2; // rbx
  Render::EmitterParticleAttribute *v3; // rdi
  Render::ParticleRenderUpdateTaskParam *v4; // rdx
  float v5; // xmm9_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float *v9; // rax
  Render::ParticleEmitterSettings *v10; // rcx
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm0_4
  Render::ParticleLighting *v15; // rcx
  UFG::qVector3 particlePosition; // [rsp+48h] [rbp-19h]
  UFG::qVector3 vVel; // [rsp+58h] [rbp-9h]
  float v18; // [rsp+64h] [rbp+3h]
  UFG::qColour result; // [rsp+68h] [rbp+7h]

  v2 = this;
  v3 = attr;
  v4 = this->mTaskParams;
  v5 = (float)(v4->simTime - v3->fStartTime) / (float)(v3->fEndTime - v3->fStartTime);
  Render::CalcPositionAndVelocityWithLocalToWorldInterpolation(
    v3,
    v4,
    this->mSettings,
    &this->mCurBasisNormalized,
    &this->mWorldLocal,
    &this->mInverseOldBasis,
    this->mTransformScaleFactor,
    &particlePosition,
    &vVel);
  v6 = particlePosition.x;
  v7 = particlePosition.y;
  v8 = particlePosition.z;
  v3->vPosAndGrav.x = particlePosition.x;
  v3->vPosAndGrav.y = v7;
  v3->vPosAndGrav.z = v8;
  Render::EmitterParticleAttribute::SetVelocity(v3, &vVel);
  v9 = &v2->mTaskParams->renderMatrix.v0.x;
  v10 = v2->mSettings;
  v11 = v6 + v9[12];
  v12 = v7 + v9[13];
  v13 = v8 + v9[14];
  vVel.x = 1.0;
  vVel.y = 1.0;
  vVel.z = 1.0;
  particlePosition.x = v11;
  particlePosition.y = v12;
  particlePosition.z = v13;
  v14 = Render::ComputeInterpolatedAlpha(v10->mSettings.ColorAlphaKeys, v10->mSettings.AlphaKeyPositions, v5);
  v15 = v2->mParticleLighting;
  v18 = v14;
  Render::ParticleLighting::ApplyDynamicLights(v15, &result, (UFG::qColour *)&vVel, &particlePosition);
  vVel.x = result.r * result.r;
  vVel.y = result.g * result.g;
  vVel.z = result.b * result.b;
  v18 = result.a;
  Render::EmitterParticleAttribute::SetColour(v3, (UFG::qColour *)&vVel);
}

// File Line: 304
// RVA: 0x1DDE70
void __fastcall Render::FXForceParticleMover::FXForceParticleMover(Render::FXForceParticleMover *this, Render::ParticleRenderUpdateTaskParam *taskParams, Render::ParticleEmitterSettings *pfx, Render::ParticleLighting *particleLighting, float transformScale, UFG::qMatrix44 *worldLocal, UFG::qMatrix44 *invOldBasis, Render::FXForce *forceList)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4

  v8 = invOldBasis->v0.y;
  v9 = invOldBasis->v0.z;
  v10 = invOldBasis->v0.w;
  this->mInverseOldBasis.v0.x = invOldBasis->v0.x;
  this->mInverseOldBasis.v0.y = v8;
  this->mInverseOldBasis.v0.z = v9;
  this->mInverseOldBasis.v0.w = v10;
  v11 = invOldBasis->v1.y;
  v12 = invOldBasis->v1.z;
  v13 = invOldBasis->v1.w;
  this->mInverseOldBasis.v1.x = invOldBasis->v1.x;
  this->mInverseOldBasis.v1.y = v11;
  this->mInverseOldBasis.v1.z = v12;
  this->mInverseOldBasis.v1.w = v13;
  v14 = invOldBasis->v2.y;
  v15 = invOldBasis->v2.z;
  v16 = invOldBasis->v2.w;
  this->mInverseOldBasis.v2.x = invOldBasis->v2.x;
  this->mInverseOldBasis.v2.y = v14;
  this->mInverseOldBasis.v2.z = v15;
  this->mInverseOldBasis.v2.w = v16;
  v17 = invOldBasis->v3.y;
  v18 = invOldBasis->v3.z;
  v19 = invOldBasis->v3.w;
  this->mInverseOldBasis.v3.x = invOldBasis->v3.x;
  this->mInverseOldBasis.v3.y = v17;
  this->mInverseOldBasis.v3.z = v18;
  this->mInverseOldBasis.v3.w = v19;
  v20 = worldLocal->v0.y;
  v21 = worldLocal->v0.z;
  v22 = worldLocal->v0.w;
  this->mWorldLocal.v0.x = worldLocal->v0.x;
  this->mWorldLocal.v0.y = v20;
  this->mWorldLocal.v0.z = v21;
  this->mWorldLocal.v0.w = v22;
  v23 = worldLocal->v1.y;
  v24 = worldLocal->v1.z;
  v25 = worldLocal->v1.w;
  this->mWorldLocal.v1.x = worldLocal->v1.x;
  this->mWorldLocal.v1.y = v23;
  this->mWorldLocal.v1.z = v24;
  this->mWorldLocal.v1.w = v25;
  v26 = worldLocal->v2.y;
  v27 = worldLocal->v2.z;
  v28 = worldLocal->v2.w;
  this->mWorldLocal.v2.x = worldLocal->v2.x;
  this->mWorldLocal.v2.y = v26;
  this->mWorldLocal.v2.z = v27;
  this->mWorldLocal.v2.w = v28;
  v29 = worldLocal->v3.y;
  v30 = worldLocal->v3.z;
  v31 = worldLocal->v3.w;
  this->mWorldLocal.v3.x = worldLocal->v3.x;
  this->mWorldLocal.v3.y = v29;
  this->mWorldLocal.v3.z = v30;
  this->mWorldLocal.v3.w = v31;
  this->mTransformScaleFactor = transformScale;
  this->mForceList = forceList;
  this->mSettings = pfx;
  this->mParticleLighting = particleLighting;
  this->mTaskParams = taskParams;
}

// File Line: 308
// RVA: 0x1DED20
void __fastcall Render::FXForceParticleMover::operator()(Render::FXForceParticleMover *this, Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *v2; // rdi
  Render::FXForceParticleMover *v3; // rsi
  Render::EmitterParticleAttribute *v4; // r14
  float v5; // xmm13_4
  float v6; // xmm14_4
  float v7; // xmm15_4
  float v8; // xmm2_4
  float v9; // xmm15_4
  float v10; // xmm14_4
  float v11; // xmm13_4
  Render::ParticleRenderUpdateTaskParam *v12; // rbx
  Render::FXForce *v13; // r8
  unsigned int v14; // er9
  float v15; // xmm2_4
  float v16; // xmm8_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  Render::ParticleEmitterSettings *v21; // rcx
  float v22; // xmm13_4
  float v23; // xmm14_4
  float v24; // xmm15_4
  float v25; // xmm0_4
  Render::ParticleLighting *v26; // rcx
  UFG::qVector3 originalPosition; // [rsp+8h] [rbp-59h]
  float v28; // [rsp+14h] [rbp-4Dh]
  UFG::qVector3 vVel; // [rsp+18h] [rbp-49h]
  UFG::qVector4 result; // [rsp+28h] [rbp-39h]
  __int64 v31; // [rsp+40h] [rbp-21h]
  float v32; // [rsp+C8h] [rbp+67h]
  float lifetime; // [rsp+D0h] [rbp+6Fh]

  v2 = this->mTaskParams;
  v3 = this;
  v4 = attr;
  v5 = attr->vPosAndGrav.x;
  v6 = attr->vPosAndGrav.y;
  v7 = attr->vPosAndGrav.z;
  lifetime = (float)(v2->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime);
  UFG::qHalfVector4::operator UFG::qVector4 const(&attr->vVelAndDamp, (UFG::qVector4 *)&v31);
  v8 = v2->deltaTime;
  v9 = v7 + (float)(result.z * v8);
  v10 = v6 + (float)(result.y * v8);
  v11 = v5 + (float)(result.x * v8);
  v4->vPosAndGrav.x = v11;
  v4->vPosAndGrav.y = v10;
  v4->vPosAndGrav.z = v9;
  v12 = v3->mTaskParams;
  v13 = v3->mForceList;
  v14 = v12->numForces;
  v15 = v3->mTransformScaleFactor * v4->vPosAndGrav.w;
  v16 = (float)((float)(v3->mWorldLocal.v1.x + v3->mWorldLocal.v0.x) * 0.0) + (float)(v15 * v3->mWorldLocal.v2.x);
  v17 = (float)((float)(v3->mWorldLocal.v1.y + v3->mWorldLocal.v0.y) * 0.0) + (float)(v15 * v3->mWorldLocal.v2.y);
  v18 = (float)((float)(v3->mWorldLocal.v1.z + v3->mWorldLocal.v0.z) * 0.0) + (float)(v15 * v3->mWorldLocal.v2.z);
  originalPosition.y = v10 + v2->renderMatrix.v3.y;
  originalPosition.x = v11 + v2->renderMatrix.v3.x;
  v19 = v9 + v2->renderMatrix.v3.z;
  Render::ApplyFXForcesToParticle(&vVel, &originalPosition, v13, v14);
  v20 = v12->deltaTime;
  LODWORD(v32) = (((((unsigned int)v4->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v4->vVelAndDamp.w.mRep & 0x3FF | 8 * (v4->vVelAndDamp.w.mRep & 0x8000)) << 13);
  vVel.z = (float)((float)((float)(vVel.z + v18) * v20) + result.z)
         - (float)((float)((float)((float)((float)(vVel.z + v18) * v20) + result.z) * v20) * v32);
  Render::EmitterParticleAttribute::SetVelocity(v4, &vVel);
  v21 = v3->mSettings;
  result.x = 1.0;
  v22 = v11 + v2->renderMatrix.v3.x;
  v23 = v10 + v2->renderMatrix.v3.y;
  v24 = v9 + v2->renderMatrix.v3.z;
  result.y = 1.0;
  result.z = 1.0;
  vVel.z = v24;
  v25 = Render::ComputeInterpolatedAlpha(v21->mSettings.ColorAlphaKeys, v21->mSettings.AlphaKeyPositions, lifetime);
  v26 = v3->mParticleLighting;
  result.w = v25;
  Render::ParticleLighting::ApplyDynamicLights(v26, (UFG::qColour *)&originalPosition, (UFG::qColour *)&result, &vVel);
  result.x = originalPosition.x * originalPosition.x;
  result.y = originalPosition.y * originalPosition.y;
  result.z = originalPosition.z * originalPosition.z;
  result.w = v28;
  Render::EmitterParticleAttribute::SetColour(v4, (UFG::qColour *)&result);
}

// File Line: 365
// RVA: 0x1DE440
void __fastcall Render::BounceParticleMover::operator()(Render::BounceParticleMover *this, Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *v2; // rsi
  Render::EmitterParticleAttribute *v3; // rbx
  Render::BounceParticleMover *v4; // rdi
  Render::ParticleRenderUpdateTaskParam *v5; // rcx
  float v6; // xmm14_4
  unsigned int v7; // eax
  float v8; // xmm15_4
  int v9; // xmm1_4
  float *v10; // rcx
  __int64 v11; // rdx
  float v12; // xmm13_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  int v18; // xmm7_4
  int v19; // xmm8_4
  int v20; // xmm9_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm13_4
  float v27; // xmm12_4
  float v28; // xmm11_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  Render::ParticleEmitterSettings *v31; // rcx
  float v32; // xmm7_4
  float v33; // xmm15_4
  float v34; // xmm14_4
  float v35; // xmm0_4
  Render::ParticleLighting *v36; // rcx
  float lifetime; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 vVel; // [rsp+38h] [rbp-C8h]
  float v39; // [rsp+44h] [rbp-BCh]
  UFG::qVector3 particlePosition; // [rsp+48h] [rbp-B8h]
  float v41; // [rsp+54h] [rbp-ACh]
  UFG::qColour result; // [rsp+58h] [rbp-A8h]
  float v43; // [rsp+140h] [rbp+40h]
  float v44; // [rsp+148h] [rbp+48h]
  float v45; // [rsp+150h] [rbp+50h]
  float v46; // [rsp+158h] [rbp+58h]

  v2 = this->mTaskParams;
  v3 = attr;
  v4 = this;
  v44 = attr->vPosAndGrav.x;
  v46 = attr->vPosAndGrav.z;
  v45 = attr->vPosAndGrav.y;
  lifetime = (float)(v2->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime);
  Render::CalcWorldSpacePositionAndVelocity(
    attr,
    v2,
    &this->mWorldLocal,
    this->mTransformScaleFactor,
    &particlePosition,
    &vVel);
  v5 = v4->mTaskParams;
  v6 = particlePosition.z;
  v7 = v5->numBouncePlanes;
  v8 = particlePosition.y;
  if ( v7 )
  {
    v9 = _xmm[0];
    v10 = &v5->bouncePlaneList[0].normal.z;
    v11 = v7;
    v43 = particlePosition.x;
    v12 = vVel.x;
    v13 = vVel.z;
    v14 = vVel.y;
    do
    {
      v15 = *(v10 - 1);
      v16 = *(v10 - 2);
      v17 = *v10;
      v18 = *((_DWORD *)v10 - 5) ^ v9;
      v19 = *((_DWORD *)v10 - 4) ^ v9;
      v20 = *((_DWORD *)v10 - 3) ^ v9;
      if ( (float)((float)((float)((float)(v16 * *(float *)&v18) + (float)(*(v10 - 1) * *(float *)&v19))
                         + (float)(*v10 * *(float *)&v20))
                 + (float)((float)((float)(*(v10 - 2) * v43) + (float)(*(v10 - 1) * v8)) + (float)(*v10 * v6))) >= 0.0
        || (v21 = v16 * *(float *)&v18,
            v22 = v44,
            (float)((float)((float)(v21 + (float)(v15 * *(float *)&v19)) + (float)(v17 * *(float *)&v20))
                  + (float)((float)((float)(v16 * v44) + (float)(v15 * v45)) + (float)(v17 * v46))) < 0.0) )
      {
        v22 = v43;
      }
      else
      {
        v6 = v46;
        v43 = v44;
        v8 = v45;
        v23 = (float)((float)(v12 * v12) + (float)(v14 * v14)) + (float)(v13 * v13);
        v24 = fsqrt(v23);
        if ( v23 == 0.0 )
          v25 = 0.0;
        else
          v25 = 1.0 / fsqrt(v23);
        v26 = v12 * v25;
        v27 = v14 * v25;
        v28 = v13 * v25;
        v29 = (float)((float)(v16 * v26) + (float)(v15 * v27)) + (float)(v17 * v28);
        v30 = v4->mSettings->mBounciness;
        v12 = (float)((float)(v26 - (float)((float)(v16 * 2.0) * v29)) * v24) * v30;
        v14 = (float)((float)(v27 - (float)((float)(v15 * 2.0) * v29)) * v24) * v30;
        vVel.x = v12;
        vVel.y = v14;
        v13 = (float)((float)(v28 - (float)((float)(v17 * 2.0) * v29)) * v24) * v30;
        vVel.z = v13;
      }
      v9 = _xmm[0];
      v10 += 6;
      --v11;
    }
    while ( v11 );
  }
  else
  {
    v22 = particlePosition.x;
  }
  v3->vPosAndGrav.x = v22;
  v3->vPosAndGrav.y = v8;
  v3->vPosAndGrav.z = v6;
  Render::EmitterParticleAttribute::SetVelocity(v3, &vVel);
  v31 = v4->mSettings;
  vVel.x = 1.0;
  vVel.y = 1.0;
  v32 = v22 + v2->renderMatrix.v3.x;
  v33 = v8 + v2->renderMatrix.v3.y;
  v34 = v6 + v2->renderMatrix.v3.z;
  vVel.z = 1.0;
  particlePosition.x = v32;
  particlePosition.y = v33;
  particlePosition.z = v34;
  v35 = Render::ComputeInterpolatedAlpha(v31->mSettings.ColorAlphaKeys, v31->mSettings.AlphaKeyPositions, lifetime);
  v36 = v4->mParticleLighting;
  v39 = v35;
  Render::ParticleLighting::ApplyDynamicLights(v36, &result, (UFG::qColour *)&vVel, &particlePosition);
  particlePosition.x = result.r * result.r;
  particlePosition.y = result.g * result.g;
  particlePosition.z = result.b * result.b;
  v41 = result.a;
  Render::EmitterParticleAttribute::SetColour(v3, (UFG::qColour *)&particlePosition);
}

// File Line: 428
// RVA: 0x1DDAB0
void __fastcall Render::BounceParticleMoverWithLocalToWorldBlend::BounceParticleMoverWithLocalToWorldBlend(Render::BounceParticleMoverWithLocalToWorldBlend *this, Render::ParticleRenderUpdateTaskParam *taskParams, Render::ParticleEmitterSettings *pfx, Render::ParticleLighting *particleLighting, float transformScale, UFG::qMatrix44 *curBasisNormalized, UFG::qMatrix44 *worldLocal, UFG::qMatrix44 *invOldBasis)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4

  v8 = curBasisNormalized->v0.y;
  v9 = curBasisNormalized->v0.z;
  v10 = curBasisNormalized->v0.w;
  this->mCurBasisNormalized.v0.x = curBasisNormalized->v0.x;
  this->mCurBasisNormalized.v0.y = v8;
  this->mCurBasisNormalized.v0.z = v9;
  this->mCurBasisNormalized.v0.w = v10;
  v11 = curBasisNormalized->v1.y;
  v12 = curBasisNormalized->v1.z;
  v13 = curBasisNormalized->v1.w;
  this->mCurBasisNormalized.v1.x = curBasisNormalized->v1.x;
  this->mCurBasisNormalized.v1.y = v11;
  this->mCurBasisNormalized.v1.z = v12;
  this->mCurBasisNormalized.v1.w = v13;
  v14 = curBasisNormalized->v2.y;
  v15 = curBasisNormalized->v2.z;
  v16 = curBasisNormalized->v2.w;
  this->mCurBasisNormalized.v2.x = curBasisNormalized->v2.x;
  this->mCurBasisNormalized.v2.y = v14;
  this->mCurBasisNormalized.v2.z = v15;
  this->mCurBasisNormalized.v2.w = v16;
  v17 = curBasisNormalized->v3.y;
  v18 = curBasisNormalized->v3.z;
  v19 = curBasisNormalized->v3.w;
  this->mCurBasisNormalized.v3.x = curBasisNormalized->v3.x;
  this->mCurBasisNormalized.v3.y = v17;
  this->mCurBasisNormalized.v3.z = v18;
  this->mCurBasisNormalized.v3.w = v19;
  v20 = invOldBasis->v0.y;
  v21 = invOldBasis->v0.z;
  v22 = invOldBasis->v0.w;
  this->mInverseOldBasis.v0.x = invOldBasis->v0.x;
  this->mInverseOldBasis.v0.y = v20;
  this->mInverseOldBasis.v0.z = v21;
  this->mInverseOldBasis.v0.w = v22;
  v23 = invOldBasis->v1.y;
  v24 = invOldBasis->v1.z;
  v25 = invOldBasis->v1.w;
  this->mInverseOldBasis.v1.x = invOldBasis->v1.x;
  this->mInverseOldBasis.v1.y = v23;
  this->mInverseOldBasis.v1.z = v24;
  this->mInverseOldBasis.v1.w = v25;
  v26 = invOldBasis->v2.y;
  v27 = invOldBasis->v2.z;
  v28 = invOldBasis->v2.w;
  this->mInverseOldBasis.v2.x = invOldBasis->v2.x;
  this->mInverseOldBasis.v2.y = v26;
  this->mInverseOldBasis.v2.z = v27;
  this->mInverseOldBasis.v2.w = v28;
  v29 = invOldBasis->v3.y;
  v30 = invOldBasis->v3.z;
  v31 = invOldBasis->v3.w;
  this->mInverseOldBasis.v3.x = invOldBasis->v3.x;
  this->mInverseOldBasis.v3.y = v29;
  this->mInverseOldBasis.v3.z = v30;
  this->mInverseOldBasis.v3.w = v31;
  v32 = worldLocal->v0.y;
  v33 = worldLocal->v0.z;
  v34 = worldLocal->v0.w;
  this->mWorldLocal.v0.x = worldLocal->v0.x;
  this->mWorldLocal.v0.y = v32;
  this->mWorldLocal.v0.z = v33;
  this->mWorldLocal.v0.w = v34;
  v35 = worldLocal->v1.y;
  v36 = worldLocal->v1.z;
  v37 = worldLocal->v1.w;
  this->mWorldLocal.v1.x = worldLocal->v1.x;
  this->mWorldLocal.v1.y = v35;
  this->mWorldLocal.v1.z = v36;
  this->mWorldLocal.v1.w = v37;
  v38 = worldLocal->v2.y;
  v39 = worldLocal->v2.z;
  v40 = worldLocal->v2.w;
  this->mWorldLocal.v2.x = worldLocal->v2.x;
  this->mWorldLocal.v2.y = v38;
  this->mWorldLocal.v2.z = v39;
  this->mWorldLocal.v2.w = v40;
  v41 = worldLocal->v3.y;
  v42 = worldLocal->v3.z;
  v43 = worldLocal->v3.w;
  this->mWorldLocal.v3.x = worldLocal->v3.x;
  this->mWorldLocal.v3.y = v41;
  this->mWorldLocal.v3.z = v42;
  this->mWorldLocal.v3.w = v43;
  this->mTransformScaleFactor = transformScale;
  this->mSettings = pfx;
  this->mParticleLighting = particleLighting;
  this->mTaskParams = taskParams;
}

// File Line: 432
// RVA: 0x1DE8A0
void __fastcall Render::BounceParticleMoverWithLocalToWorldBlend::operator()(Render::BounceParticleMoverWithLocalToWorldBlend *this, Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *v2; // rsi
  Render::BounceParticleMoverWithLocalToWorldBlend *v3; // rdi
  Render::EmitterParticleAttribute *v4; // rbx
  Render::ParticleEmitterSettings *v5; // r8
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm2_4
  Render::ParticleRenderUpdateTaskParam *v9; // rcx
  float v10; // xmm14_4
  float v11; // xmm15_4
  unsigned int v12; // eax
  int v13; // xmm1_4
  float *v14; // rcx
  __int64 v15; // rdx
  float v16; // xmm13_4
  float v17; // xmm11_4
  float v18; // xmm12_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  int v22; // xmm7_4
  int v23; // xmm8_4
  int v24; // xmm9_4
  float v25; // xmm3_4
  float v26; // xmm7_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm13_4
  float v31; // xmm12_4
  float v32; // xmm11_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  Render::ParticleEmitterSettings *v35; // rcx
  float v36; // xmm7_4
  float v37; // xmm15_4
  float v38; // xmm14_4
  float v39; // xmm0_4
  Render::ParticleLighting *v40; // rcx
  float lifetime; // [rsp+50h] [rbp-90h]
  UFG::qVector3 vVel; // [rsp+58h] [rbp-88h]
  int v43; // [rsp+64h] [rbp-7Ch]
  UFG::qVector3 particlePosition; // [rsp+68h] [rbp-78h]
  int v45; // [rsp+74h] [rbp-6Ch]
  UFG::qColour result; // [rsp+78h] [rbp-68h]
  float v47; // [rsp+140h] [rbp+60h]
  float v48; // [rsp+148h] [rbp+68h]
  float vars0; // [rsp+150h] [rbp+70h]
  float retaddr; // [rsp+158h] [rbp+78h]

  v2 = this->mTaskParams;
  v3 = this;
  v4 = attr;
  v5 = this->mSettings;
  v6 = attr->fEndTime - attr->fStartTime;
  v7 = v2->simTime;
  v48 = attr->vPosAndGrav.x;
  v8 = (float)(v7 - attr->fStartTime) / v6;
  retaddr = attr->vPosAndGrav.z;
  vars0 = attr->vPosAndGrav.y;
  lifetime = v8;
  Render::CalcPositionAndVelocityWithLocalToWorldInterpolation(
    attr,
    v2,
    v5,
    &v3->mCurBasisNormalized,
    &this->mWorldLocal,
    &this->mInverseOldBasis,
    v3->mTransformScaleFactor,
    &particlePosition,
    &vVel);
  v9 = v3->mTaskParams;
  v10 = particlePosition.z;
  v11 = particlePosition.y;
  v12 = v9->numBouncePlanes;
  if ( v12 )
  {
    v13 = _xmm[0];
    v14 = &v9->bouncePlaneList[0].normal.z;
    v15 = v12;
    v47 = particlePosition.x;
    v16 = vVel.x;
    v17 = vVel.z;
    v18 = vVel.y;
    do
    {
      v19 = *(v14 - 1);
      v20 = *(v14 - 2);
      v21 = *v14;
      v22 = *((_DWORD *)v14 - 5) ^ v13;
      v23 = *((_DWORD *)v14 - 4) ^ v13;
      v24 = *((_DWORD *)v14 - 3) ^ v13;
      if ( (float)((float)((float)((float)(v20 * *(float *)&v22) + (float)(*(v14 - 1) * *(float *)&v23))
                         + (float)(*v14 * *(float *)&v24))
                 + (float)((float)((float)(*(v14 - 2) * v47) + (float)(*(v14 - 1) * v11)) + (float)(*v14 * v10))) >= 0.0
        || (v25 = v20 * *(float *)&v22,
            v26 = v48,
            (float)((float)((float)(v25 + (float)(v19 * *(float *)&v23)) + (float)(v21 * *(float *)&v24))
                  + (float)((float)((float)(v20 * v48) + (float)(v19 * vars0)) + (float)(v21 * retaddr))) < 0.0) )
      {
        v26 = v47;
      }
      else
      {
        v10 = retaddr;
        v47 = v48;
        v11 = vars0;
        v27 = (float)((float)(v16 * v16) + (float)(v18 * v18)) + (float)(v17 * v17);
        v28 = fsqrt(v27);
        if ( v27 == 0.0 )
          v29 = 0.0;
        else
          v29 = 1.0 / fsqrt(v27);
        v30 = v16 * v29;
        v31 = v18 * v29;
        v32 = v17 * v29;
        v33 = (float)((float)(v20 * v30) + (float)(v19 * v31)) + (float)(v21 * v32);
        v34 = v3->mSettings->mBounciness;
        v16 = (float)((float)(v30 - (float)((float)(v20 * 2.0) * v33)) * v28) * v34;
        v18 = (float)((float)(v31 - (float)((float)(v19 * 2.0) * v33)) * v28) * v34;
        vVel.x = v16;
        vVel.y = v18;
        v17 = (float)((float)(v32 - (float)((float)(v21 * 2.0) * v33)) * v28) * v34;
        vVel.z = v17;
      }
      v13 = _xmm[0];
      v14 += 6;
      --v15;
    }
    while ( v15 );
  }
  else
  {
    v26 = particlePosition.x;
  }
  v4->vPosAndGrav.x = v26;
  v4->vPosAndGrav.y = v11;
  v4->vPosAndGrav.z = v10;
  Render::EmitterParticleAttribute::SetVelocity(v4, &vVel);
  v35 = v3->mSettings;
  vVel.x = 1.0;
  vVel.y = 1.0;
  v36 = v26 + v2->renderMatrix.v3.x;
  v37 = v11 + v2->renderMatrix.v3.y;
  v38 = v10 + v2->renderMatrix.v3.z;
  vVel.z = 1.0;
  particlePosition.x = v36;
  particlePosition.y = v37;
  particlePosition.z = v38;
  v39 = Render::ComputeInterpolatedAlpha(v35->mSettings.ColorAlphaKeys, v35->mSettings.AlphaKeyPositions, lifetime);
  v40 = v3->mParticleLighting;
  v43 = LODWORD(v39);
  Render::ParticleLighting::ApplyDynamicLights(v40, &result, (UFG::qColour *)&vVel, &particlePosition);
  particlePosition.x = result.r * result.r;
  particlePosition.y = result.g * result.g;
  particlePosition.z = vVel.z * vVel.z;
  v45 = v43;
  Render::EmitterParticleAttribute::SetColour(v4, (UFG::qColour *)&particlePosition);
}

// File Line: 513
// RVA: 0x1DF050
void __fastcall Render::TargetParticleMover::operator()(Render::TargetParticleMover *this, Render::EmitterParticleAttribute *attr)
{
  Render::EmitterParticleAttribute *v2; // rdi
  Render::ParticleRenderUpdateTaskParam *v3; // rdx
  Render::TargetParticleMover *v4; // rbx
  float v5; // xmm9_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float *v9; // rax
  Render::ParticleEmitterSettings *v10; // rcx
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm0_4
  Render::ParticleLighting *v15; // rcx
  UFG::qVector3 resultWorldSpacePosition; // [rsp+18h] [rbp-19h]
  UFG::qVector3 resultWorldSpaceVelocity; // [rsp+28h] [rbp-9h]
  float v18; // [rsp+34h] [rbp+3h]
  UFG::qColour result; // [rsp+38h] [rbp+7h]

  v2 = attr;
  v3 = this->mTaskParams;
  v4 = this;
  v5 = (float)(v3->simTime - v2->fStartTime) / (float)(v2->fEndTime - v2->fStartTime);
  Render::CalcWorldSpacePositionAndVelocityToTarget(
    v2,
    v3,
    (UFG::qVector3 *)((char *)&resultWorldSpacePosition + 8),
    (UFG::qVector3 *)((char *)&resultWorldSpaceVelocity + 8));
  v6 = resultWorldSpacePosition.x;
  v7 = resultWorldSpacePosition.y;
  v8 = resultWorldSpacePosition.z;
  v2->vPosAndGrav.x = resultWorldSpacePosition.x;
  v2->vPosAndGrav.y = v7;
  v2->vPosAndGrav.z = v8;
  Render::EmitterParticleAttribute::SetVelocity(v2, &resultWorldSpaceVelocity);
  v9 = &v4->mTaskParams->renderMatrix.v0.x;
  v10 = v4->mSettings;
  v11 = v6 + v9[12];
  v12 = v7 + v9[13];
  v13 = v8 + v9[14];
  resultWorldSpaceVelocity.x = 1.0;
  resultWorldSpaceVelocity.y = 1.0;
  resultWorldSpaceVelocity.z = 1.0;
  resultWorldSpacePosition.z = v13;
  v14 = Render::ComputeInterpolatedAlpha(v10->mSettings.ColorAlphaKeys, v10->mSettings.AlphaKeyPositions, v5);
  v15 = v4->mParticleLighting;
  v18 = v14;
  Render::ParticleLighting::ApplyDynamicLights(
    v15,
    &result,
    (UFG::qColour *)&resultWorldSpaceVelocity,
    &resultWorldSpacePosition);
  resultWorldSpaceVelocity.x = result.r * result.r;
  resultWorldSpaceVelocity.y = result.g * result.g;
  resultWorldSpaceVelocity.z = result.b * result.b;
  v18 = result.a;
  Render::EmitterParticleAttribute::SetColour(v2, (UFG::qColour *)&resultWorldSpaceVelocity);
}

// File Line: 550
// RVA: 0x1DF1B0
void __fastcall Render::TargetParticleMoverWithBlend::operator()(Render::TargetParticleMoverWithBlend *this, Render::EmitterParticleAttribute *attr)
{
  float v2; // xmm3_4
  Render::EmitterParticleAttribute *v3; // rdi
  Render::ParticleRenderUpdateTaskParam *v4; // rdx
  Render::TargetParticleMoverWithBlend *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm9_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float *v13; // rax
  Render::ParticleEmitterSettings *v14; // rcx
  float v15; // xmm8_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  Render::ParticleLighting *v19; // rcx
  UFG::qVector3 *resultWorldSpaceVelocity; // [rsp+28h] [rbp-29h]
  float v21; // [rsp+30h] [rbp-21h]
  UFG::qVector3 particlePosition; // [rsp+38h] [rbp-19h]
  UFG::qVector3 vVel; // [rsp+48h] [rbp-9h]
  int v24; // [rsp+54h] [rbp+3h]
  UFG::qVector3 v25; // [rsp+58h] [rbp+7h]
  int v26; // [rsp+64h] [rbp+13h]

  v2 = this->mTransformScaleFactor;
  v3 = attr;
  v4 = this->mTaskParams;
  v5 = this;
  v6 = v3->fEndTime - v3->fStartTime;
  resultWorldSpaceVelocity = (UFG::qVector3 *)((char *)&vVel + 8);
  v7 = (float)(v4->simTime - v3->fStartTime) / v6;
  Render::CalcWorldSpacePositionAndVelocity(
    v3,
    v4,
    &this->mWorldLocal,
    v2,
    (UFG::qVector3 *)((char *)&particlePosition + 8),
    (UFG::qVector3 *)((char *)&vVel + 8));
  Render::CalcWorldSpacePositionAndVelocityToTarget(
    v3,
    v5->mTaskParams,
    (UFG::qVector3 *)&resultWorldSpaceVelocity,
    &v25);
  v8 = *(float *)&FLOAT_1_0;
  v9 = v7 * v5->mSettings->mLocalSpaceToWorldSpaceBlend;
  if ( v9 <= 0.0 )
  {
    v9 = 0.0;
  }
  else if ( v9 >= 1.0 )
  {
    goto LABEL_6;
  }
  v8 = v9;
LABEL_6:
  v10 = (float)((float)(*(float *)&resultWorldSpaceVelocity - particlePosition.x) * v8) + particlePosition.x;
  v11 = (float)((float)(*((float *)&resultWorldSpaceVelocity + 1) - particlePosition.y) * v8) + particlePosition.y;
  v12 = (float)((float)(v21 - particlePosition.z) * v8) + particlePosition.z;
  v3->vPosAndGrav.x = v10;
  v3->vPosAndGrav.y = v11;
  v3->vPosAndGrav.z = v12;
  Render::EmitterParticleAttribute::SetVelocity(v3, &vVel);
  v13 = &v5->mTaskParams->renderMatrix.v0.x;
  v14 = v5->mSettings;
  v15 = v10 + v13[12];
  v16 = v11 + v13[13];
  v17 = v12 + v13[14];
  v25.x = 1.0;
  v25.y = 1.0;
  v25.z = 1.0;
  particlePosition.x = v15;
  particlePosition.y = v16;
  particlePosition.z = v17;
  v18 = Render::ComputeInterpolatedAlpha(v14->mSettings.ColorAlphaKeys, v14->mSettings.AlphaKeyPositions, v7);
  v19 = v5->mParticleLighting;
  v26 = LODWORD(v18);
  Render::ParticleLighting::ApplyDynamicLights(v19, (UFG::qColour *)&vVel, (UFG::qColour *)&v25, &particlePosition);
  v25.x = vVel.x * vVel.x;
  v25.y = vVel.y * vVel.y;
  v25.z = vVel.z * vVel.z;
  v26 = v24;
  Render::EmitterParticleAttribute::SetColour(v3, (UFG::qColour *)&v25);
}

