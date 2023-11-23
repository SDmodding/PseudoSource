// File Line: 17
// RVA: 0x1E0170
UFG::qVector3 *__fastcall Render::ApplyFXForcesToParticle(
        UFG::qVector3 *result,
        UFG::qVector3 *originalPosition,
        Render::FXForce *forceList,
        unsigned int numForces)
{
  float *p_radMin; // rax
  __int64 v5; // r8
  float x; // xmm14_4
  float y; // xmm15_4
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
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v21; // [rsp+B0h] [rbp+8h]
  float v22; // [rsp+C8h] [rbp+20h]

  *(_QWORD *)&result->x = 0i64;
  result->z = 0.0;
  if ( numForces )
  {
    p_radMin = &forceList->radMin;
    v5 = numForces;
    v22 = 0.0;
    v21 = 0.0;
    x = originalPosition->x;
    y = originalPosition->y;
    do
    {
      v8 = *(p_radMin - 1);
      if ( v8 >= 0.0 )
      {
        v9 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v9 = FLOAT_N1_0;
        LODWORD(v8) ^= _xmm[0];
      }
      v10 = *(p_radMin - 4);
      v11 = (__m128)*((unsigned int *)p_radMin - 3);
      v12 = *(p_radMin - 2);
      v13 = (float)((float)(fsqrt(
                              (float)((float)((float)(y - v11.m128_f32[0]) * (float)(y - v11.m128_f32[0]))
                                    + (float)((float)(x - v10) * (float)(x - v10)))
                            + (float)((float)(originalPosition->z - v12) * (float)(originalPosition->z - v12)))
                          - *p_radMin)
                  * (float)(COERCE_FLOAT(LODWORD(v8) ^ _xmm[0]) / (float)(p_radMin[1] - *p_radMin)))
          + v8;
      if ( v13 <= 0.0 )
        v13 = 0.0;
      if ( v13 >= v8 )
        v13 = v8;
      v14 = v12 - originalPosition->z;
      v15 = v10 - x;
      v11.m128_f32[0] = v11.m128_f32[0] - y;
      v16 = v11;
      v16.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v15 * v15)) + (float)(v14 * v14);
      if ( v16.m128_f32[0] == 0.0 )
        v17 = 0.0;
      else
        v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
      p_radMin += 6;
      v18 = v22 + (float)((float)((float)(v11.m128_f32[0] * v17) * v13) * v9);
      result->x = (float)((float)((float)(v15 * v17) * v13) * v9) + result->x;
      v22 = v18;
      v19 = v21 + (float)((float)((float)(v14 * v17) * v13) * v9);
      v21 = v19;
      --v5;
    }
    while ( v5 );
    result->y = v18;
    result->z = v19;
  }
  return result;
}

// File Line: 78
// RVA: 0x1E03A0
void __fastcall Render::CalcPositionAndVelocityInSimulatedLocalSpace(
        Render::EmitterParticleAttribute *attr,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        UFG::qMatrix44 *curBasisNormalized,
        UFG::qMatrix44 *worldLocal,
        UFG::qMatrix44 *inverseOldBasis,
        float transformScale,
        UFG::qVector3 *resultWorldSpacePosition,
        UFG::qVector3 *resultWorldSpaceVelocity)
{
  float x; // xmm6_4
  float y; // xmm7_4
  UFG::qHalfVector4 *p_vVelAndDamp; // rcx
  float v14; // xmm8_4
  float v17; // xmm5_4
  float v18; // xmm11_4
  float v19; // xmm13_4
  float z; // xmm4_4
  float v21; // xmm9_4
  float v22; // xmm14_4
  float v23; // xmm12_4
  float v24; // xmm15_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm13_4
  float deltaTime; // xmm3_4
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
  float v42; // xmm0_4
  float v43; // xmm14_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm5_4
  float v49; // xmm15_4
  float v50; // xmm13_4
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm6_4
  float v54; // xmm15_4
  float v55; // xmm2_4
  float v56; // xmm3_4
  float v57; // xmm0_4
  float v58; // [rsp+20h] [rbp-E8h]
  float v59; // [rsp+24h] [rbp-E4h]
  float v60; // [rsp+28h] [rbp-E0h]
  UFG::qVector4 result; // [rsp+2Ch] [rbp-DCh] BYREF
  float v62; // [rsp+110h] [rbp+8h]
  float v63; // [rsp+120h] [rbp+18h]
  int v64; // [rsp+120h] [rbp+18h]
  float v65; // [rsp+128h] [rbp+20h]
  float inverseOldBasisa; // [rsp+130h] [rbp+28h]
  float inverseOldBasisb; // [rsp+130h] [rbp+28h]

  x = attr->vPosAndGrav.x;
  y = attr->vPosAndGrav.y;
  p_vVelAndDamp = &attr->vVelAndDamp;
  v14 = *(float *)&p_vVelAndDamp[-1].x.mRep;
  UFG::qHalfVector4::operator UFG::qVector4 const(p_vVelAndDamp, &result);
  v17 = inverseOldBasis->v1.y;
  v18 = inverseOldBasis->v2.y;
  v19 = inverseOldBasis->v3.y;
  z = inverseOldBasis->v1.z;
  v21 = inverseOldBasis->v2.z;
  v22 = inverseOldBasis->v3.x;
  v23 = inverseOldBasis->v3.z;
  v24 = (float)((float)(inverseOldBasis->v0.x * x) + (float)(inverseOldBasis->v1.x * y))
      + (float)(inverseOldBasis->v2.x * v14);
  v63 = (float)((float)((float)(inverseOldBasis->v0.y * x) + (float)(v17 * y)) + (float)(v18 * v14)) + v19;
  v25 = inverseOldBasis->v0.z * x;
  v26 = inverseOldBasis->v0.y;
  v65 = (float)((float)(v25 + (float)(z * y)) + (float)(v21 * v14)) + v23;
  inverseOldBasisa = (float)((float)((float)(inverseOldBasis->v0.x * result.x)
                                   + (float)(inverseOldBasis->v1.x * result.y))
                           + (float)(inverseOldBasis->v2.x * result.z))
                   + (float)(v22 * 0.0);
  v62 = (float)((float)((float)(v26 * result.x) + (float)(v17 * result.y)) + (float)(v18 * result.z))
      + (float)(v19 * 0.0);
  v27 = v63;
  deltaTime = taskParams->deltaTime;
  v29 = curBasisNormalized->v1.x;
  v30 = curBasisNormalized->v2.y;
  v31 = curBasisNormalized->v3.y;
  v32 = curBasisNormalized->v3.z;
  v64 = ((((attr->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((attr->vVelAndDamp.w.mRep & 0x3FF | (8 * (attr->vVelAndDamp.w.mRep & 0x8000))) << 13);
  v33 = curBasisNormalized->v2.z;
  v34 = v27 + (float)(v62 * deltaTime);
  v35 = (float)((float)(inverseOldBasis->v0.z * result.x) + (float)(z * result.y)) + (float)(v21 * result.z);
  v36 = curBasisNormalized->v2.x;
  v37 = v35 + (float)(v23 * 0.0);
  v38 = curBasisNormalized->v3.x;
  v39 = (float)(inverseOldBasisa * deltaTime) + (float)(v24 + v22);
  v40 = curBasisNormalized->v0.z;
  v41 = v65 + (float)(v37 * deltaTime);
  v59 = (float)((float)((float)(curBasisNormalized->v0.x * v39) + (float)(v29 * v34)) + (float)(v36 * v41)) + v38;
  v58 = curBasisNormalized->v0.y;
  v60 = (float)((float)((float)(v58 * v39) + (float)(curBasisNormalized->v1.y * v34)) + (float)(v30 * v41)) + v31;
  v42 = taskParams->deltaTime;
  v43 = (float)((float)((float)(v40 * v39) + (float)(curBasisNormalized->v1.z * v34)) + (float)(v33 * v41)) + v32;
  v44 = inverseOldBasisa * v42;
  v45 = v62 * v42;
  v46 = v37 - (float)((float)(v37 * v42) * *(float *)&v64);
  inverseOldBasisb = inverseOldBasisa - (float)(v44 * *(float *)&v64);
  v47 = v62 - (float)(v45 * *(float *)&v64);
  v48 = curBasisNormalized->v1.y * v47;
  v49 = (float)(v40 * inverseOldBasisb) + (float)(curBasisNormalized->v1.z * v47);
  v50 = (float)((float)(curBasisNormalized->v0.x * inverseOldBasisb) + (float)(v29 * v47)) + (float)(v36 * v46);
  v51 = (float)(worldLocal->v1.z + worldLocal->v0.z) * 0.0;
  v52 = (float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0)
      + (float)((float)(transformScale * attr->vPosAndGrav.w) * worldLocal->v2.x);
  v53 = (float)((float)(v58 * inverseOldBasisb) + v48) + (float)(v30 * v46);
  v54 = (float)(v49 + (float)(v33 * v46)) + (float)(v32 * 0.0);
  v55 = (float)(transformScale * attr->vPosAndGrav.w) * worldLocal->v2.z;
  v56 = (float)((float)(worldLocal->v1.y + worldLocal->v0.y) * 0.0)
      + (float)((float)(transformScale * attr->vPosAndGrav.w) * worldLocal->v2.y);
  v57 = taskParams->deltaTime;
  resultWorldSpacePosition->z = v43;
  resultWorldSpacePosition->x = v59;
  resultWorldSpacePosition->y = v60;
  resultWorldSpaceVelocity->y = (float)(v53 + (float)(v31 * 0.0)) + (float)(v56 * v57);
  resultWorldSpaceVelocity->x = (float)(v50 + (float)(v38 * 0.0)) + (float)(v52 * v57);
  resultWorldSpaceVelocity->z = v54 + (float)((float)(v51 + v55) * v57);
}

// File Line: 113
// RVA: 0x1E0AB0
void __fastcall Render::CalcWorldSpacePositionAndVelocity(
        Render::EmitterParticleAttribute *attr,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        UFG::qMatrix44 *worldLocal,
        float transformScale,
        UFG::qVector3 *resultWorldSpacePosition,
        UFG::qVector3 *resultWorldSpaceVelocity)
{
  UFG::qHalfVector4 *p_vVelAndDamp; // rcx
  float v10; // xmm11_4
  float v11; // xmm13_4
  float v12; // xmm12_4
  float v13; // xmm6_4
  float deltaTime; // xmm10_4
  float v15; // xmm13_4
  float v16; // xmm12_4
  float v17; // xmm8_4
  float v18; // xmm9_4
  float v19; // xmm7_4
  UFG::qVector4 result; // [rsp+20h] [rbp-98h] BYREF
  int v21; // [rsp+D8h] [rbp+20h]

  p_vVelAndDamp = &attr->vVelAndDamp;
  v10 = *(float *)&p_vVelAndDamp[-2].x.mRep;
  v11 = *(float *)&p_vVelAndDamp[-1].x.mRep;
  v12 = *(float *)&p_vVelAndDamp[-2].z.mRep;
  UFG::qHalfVector4::operator UFG::qVector4 const(p_vVelAndDamp, &result);
  v13 = transformScale * attr->vPosAndGrav.w;
  deltaTime = taskParams->deltaTime;
  v21 = ((((attr->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((attr->vVelAndDamp.w.mRep & 0x3FF | (8 * (attr->vVelAndDamp.w.mRep & 0x8000))) << 13);
  v15 = v11 + (float)(result.z * deltaTime);
  v16 = v12 + (float)(result.y * deltaTime);
  v17 = (float)((float)((float)((float)(worldLocal->v1.y + worldLocal->v0.y) * 0.0) + (float)(v13 * worldLocal->v2.y))
              * deltaTime)
      + result.y;
  v18 = (float)((float)((float)((float)(worldLocal->v1.x + worldLocal->v0.x) * 0.0) + (float)(v13 * worldLocal->v2.x))
              * deltaTime)
      + result.x;
  v19 = (float)((float)((float)((float)(worldLocal->v1.z + worldLocal->v0.z) * 0.0) + (float)(v13 * worldLocal->v2.z))
              * deltaTime)
      + result.z;
  resultWorldSpacePosition->x = v10 + (float)(result.x * deltaTime);
  resultWorldSpacePosition->y = v16;
  resultWorldSpacePosition->z = v15;
  resultWorldSpaceVelocity->x = v18 - (float)((float)(v18 * deltaTime) * *(float *)&v21);
  resultWorldSpaceVelocity->y = v17 - (float)((float)(v17 * deltaTime) * *(float *)&v21);
  resultWorldSpaceVelocity->z = v19 - (float)((float)(v19 * deltaTime) * *(float *)&v21);
}

// File Line: 154
// RVA: 0x1E08A0
void __fastcall Render::CalcPositionAndVelocityWithLocalToWorldInterpolation(
        Render::EmitterParticleAttribute *attr,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        Render::ParticleEmitterSettings *settings,
        UFG::qMatrix44 *curBasisNormalized,
        UFG::qMatrix44 *worldLocal,
        UFG::qMatrix44 *inverseOldBasis,
        float transformScale,
        UFG::qVector3 *resultWorldSpacePosition,
        UFG::qVector3 *resultWorldSpaceVelocity)
{
  float v13; // xmm2_4
  float v14; // xmm9_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  UFG::qVector3 v20; // [rsp+40h] [rbp-88h] BYREF
  UFG::qVector3 v21; // [rsp+50h] [rbp-78h] BYREF
  UFG::qVector3 v22; // [rsp+60h] [rbp-68h] BYREF
  UFG::qVector3 v23; // [rsp+70h] [rbp-58h] BYREF

  Render::CalcPositionAndVelocityInSimulatedLocalSpace(
    attr,
    taskParams,
    curBasisNormalized,
    worldLocal,
    inverseOldBasis,
    transformScale,
    &v21,
    &v23);
  Render::CalcWorldSpacePositionAndVelocity(attr, taskParams, worldLocal, transformScale, &v20, &v22);
  v13 = (float)((float)(taskParams->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime))
      * settings->mLocalSpaceToWorldSpaceBlend;
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
  v15 = (float)((float)(v22.x - v23.x) * v14) + v23.x;
  v16 = (float)((float)(v22.y - v23.y) * v14) + v23.y;
  v17 = (float)((float)(v22.z - v23.z) * v14) + v23.z;
  v18 = (float)((float)((float)(v20.y + (float)((float)(curBasisNormalized->v3.y - taskParams->oldBasis.v3.y) * v14))
                      - v21.y)
              * v14)
      + v21.y;
  v19 = (float)((float)((float)(v20.z + (float)((float)(curBasisNormalized->v3.z - taskParams->oldBasis.v3.z) * v14))
                      - v21.z)
              * v14)
      + v21.z;
  resultWorldSpacePosition->x = (float)((float)((float)(v20.x
                                                      + (float)((float)(curBasisNormalized->v3.x
                                                                      - taskParams->oldBasis.v3.x)
                                                              * v14))
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
void __fastcall Render::CalcWorldSpacePositionAndVelocityToTarget(
        Render::EmitterParticleAttribute *attr,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        UFG::qVector3 *resultWorldSpacePosition,
        UFG::qVector3 *resultWorldSpaceVelocity)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm11_4
  float x; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float deltaTime; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4

  y = attr->vPosAndGrav.y;
  z = attr->vPosAndGrav.z;
  v6 = taskParams->targetPosition.x - attr->vPosAndGrav.x;
  v7 = taskParams->targetPosition.y - y;
  v8 = taskParams->targetPosition.z - z;
  if ( (float)((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8)) >= 0.0625 )
  {
    v12 = 1.0 / (float)(attr->fEndTime - taskParams->simTime);
    deltaTime = taskParams->deltaTime;
    v11 = z + (float)((float)(v12 * v8) * deltaTime);
    x = attr->vPosAndGrav.x + (float)((float)(v12 * v6) * deltaTime);
    v10 = y + (float)((float)(v12 * v7) * deltaTime);
  }
  else
  {
    x = taskParams->targetPosition.x;
    v10 = taskParams->targetPosition.y;
    v11 = taskParams->targetPosition.z;
  }
  resultWorldSpacePosition->z = v11;
  resultWorldSpacePosition->x = x;
  resultWorldSpacePosition->y = v10;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  resultWorldSpaceVelocity->x = UFG::qVector3::msZero.x;
  resultWorldSpaceVelocity->y = v14;
  resultWorldSpaceVelocity->z = v15;
}

// File Line: 216
// RVA: 0x1DD550
void __fastcall Render::TargetParticleMover::TargetParticleMover(
        Render::TargetParticleMoverWithBlend *this,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        Render::ParticleEmitterSettings *pfx,
        Render::ParticleLighting *particleLighting,
        float transformScale,
        UFG::qMatrix44 *worldLocal)
{
  float x; // eax
  float z; // xmm1_4
  float w; // xmm2_4
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // eax
  float v17; // xmm2_4

  x = worldLocal->v0.x;
  z = worldLocal->v0.z;
  w = worldLocal->v0.w;
  this->mWorldLocal.v0.y = worldLocal->v0.y;
  this->mWorldLocal.v0.z = z;
  this->mWorldLocal.v0.x = x;
  this->mWorldLocal.v0.w = w;
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
void __fastcall Render::BasicParticleMover::operator()(
        Render::BasicParticleMover *this,
        Render::EmitterParticleAttribute *attr)
{
  float mTransformScaleFactor; // xmm3_4
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rdx
  float v6; // xmm0_4
  float v7; // xmm9_4
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  Render::ParticleRenderUpdateTaskParam *v11; // rax
  Render::ParticleEmitterSettings *mSettings; // rcx
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  UFG::qVector3 particlePosition; // [rsp+28h] [rbp-19h] BYREF
  UFG::qColour resultWorldSpaceVelocity; // [rsp+38h] [rbp-9h] BYREF
  UFG::qColour result; // [rsp+48h] [rbp+7h] BYREF

  mTransformScaleFactor = this->mTransformScaleFactor;
  mTaskParams = this->mTaskParams;
  v6 = attr->fEndTime - attr->fStartTime;
  *(_QWORD *)&particlePosition.x = &resultWorldSpaceVelocity.b;
  v7 = (float)(mTaskParams->simTime - attr->fStartTime) / v6;
  Render::CalcWorldSpacePositionAndVelocity(
    attr,
    mTaskParams,
    &this->mWorldLocal,
    mTransformScaleFactor,
    (UFG::qVector3 *)&particlePosition.z,
    (UFG::qVector3 *)&resultWorldSpaceVelocity.b);
  x = particlePosition.x;
  y = particlePosition.y;
  z = particlePosition.z;
  attr->vPosAndGrav.x = particlePosition.x;
  attr->vPosAndGrav.y = y;
  attr->vPosAndGrav.z = z;
  Render::EmitterParticleAttribute::SetVelocity(attr, (UFG::qVector3 *)&resultWorldSpaceVelocity);
  v11 = this->mTaskParams;
  mSettings = this->mSettings;
  v13 = x + v11->renderMatrix.v3.x;
  v14 = y + v11->renderMatrix.v3.y;
  v15 = z + v11->renderMatrix.v3.z;
  resultWorldSpaceVelocity.r = 1.0;
  resultWorldSpaceVelocity.g = 1.0;
  resultWorldSpaceVelocity.b = 1.0;
  particlePosition.x = v13;
  particlePosition.y = v14;
  particlePosition.z = v15;
  v16 = Render::ComputeInterpolatedAlpha(
          mSettings->mSettings.ColorAlphaKeys,
          mSettings->mSettings.AlphaKeyPositions,
          v7);
  mParticleLighting = this->mParticleLighting;
  resultWorldSpaceVelocity.a = v16;
  Render::ParticleLighting::ApplyDynamicLights(mParticleLighting, &result, &resultWorldSpaceVelocity, &particlePosition);
  resultWorldSpaceVelocity.r = result.r * result.r;
  resultWorldSpaceVelocity.g = result.g * result.g;
  resultWorldSpaceVelocity.b = result.b * result.b;
  resultWorldSpaceVelocity.a = result.a;
  Render::EmitterParticleAttribute::SetColour(attr, &resultWorldSpaceVelocity);
}

// File Line: 263
// RVA: 0x1DD860
void __fastcall Render::BasicParticleMoverWithLocalToWorldBlend::BasicParticleMoverWithLocalToWorldBlend(
        Render::BasicParticleMoverWithLocalToWorldBlend *this,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        Render::ParticleEmitterSettings *pfx,
        Render::ParticleLighting *particleLighting,
        float transformScale,
        UFG::qMatrix44 *curBasisNormalized,
        UFG::qMatrix44 *worldLocal,
        UFG::qMatrix44 *invOldBasis)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4
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

  y = invOldBasis->v0.y;
  z = invOldBasis->v0.z;
  w = invOldBasis->v0.w;
  this->mInverseOldBasis.v0.x = invOldBasis->v0.x;
  this->mInverseOldBasis.v0.y = y;
  this->mInverseOldBasis.v0.z = z;
  this->mInverseOldBasis.v0.w = w;
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
void __fastcall Render::BasicParticleMoverWithLocalToWorldBlend::operator()(
        Render::BasicParticleMoverWithLocalToWorldBlend *this,
        Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rdx
  float v5; // xmm9_4
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  Render::ParticleRenderUpdateTaskParam *v9; // rax
  Render::ParticleEmitterSettings *mSettings; // rcx
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  UFG::qVector3 particlePosition; // [rsp+48h] [rbp-19h] BYREF
  UFG::qColour vVel; // [rsp+58h] [rbp-9h] BYREF
  UFG::qColour result; // [rsp+68h] [rbp+7h] BYREF

  mTaskParams = this->mTaskParams;
  v5 = (float)(mTaskParams->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime);
  Render::CalcPositionAndVelocityWithLocalToWorldInterpolation(
    attr,
    mTaskParams,
    this->mSettings,
    &this->mCurBasisNormalized,
    &this->mWorldLocal,
    &this->mInverseOldBasis,
    this->mTransformScaleFactor,
    &particlePosition,
    (UFG::qVector3 *)&vVel);
  x = particlePosition.x;
  y = particlePosition.y;
  z = particlePosition.z;
  attr->vPosAndGrav.x = particlePosition.x;
  attr->vPosAndGrav.y = y;
  attr->vPosAndGrav.z = z;
  Render::EmitterParticleAttribute::SetVelocity(attr, (UFG::qVector3 *)&vVel);
  v9 = this->mTaskParams;
  mSettings = this->mSettings;
  v11 = x + v9->renderMatrix.v3.x;
  v12 = y + v9->renderMatrix.v3.y;
  v13 = z + v9->renderMatrix.v3.z;
  vVel.r = 1.0;
  vVel.g = 1.0;
  vVel.b = 1.0;
  particlePosition.x = v11;
  particlePosition.y = v12;
  particlePosition.z = v13;
  v14 = Render::ComputeInterpolatedAlpha(
          mSettings->mSettings.ColorAlphaKeys,
          mSettings->mSettings.AlphaKeyPositions,
          v5);
  mParticleLighting = this->mParticleLighting;
  vVel.a = v14;
  Render::ParticleLighting::ApplyDynamicLights(mParticleLighting, &result, &vVel, &particlePosition);
  vVel.r = result.r * result.r;
  vVel.g = result.g * result.g;
  vVel.b = result.b * result.b;
  vVel.a = result.a;
  Render::EmitterParticleAttribute::SetColour(attr, &vVel);
}

// File Line: 304
// RVA: 0x1DDE70
void __fastcall Render::FXForceParticleMover::FXForceParticleMover(
        Render::FXForceParticleMover *this,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        Render::ParticleEmitterSettings *pfx,
        Render::ParticleLighting *particleLighting,
        float transformScale,
        UFG::qMatrix44 *worldLocal,
        UFG::qMatrix44 *invOldBasis,
        Render::FXForce *forceList)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4
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

  y = invOldBasis->v0.y;
  z = invOldBasis->v0.z;
  w = invOldBasis->v0.w;
  this->mInverseOldBasis.v0.x = invOldBasis->v0.x;
  this->mInverseOldBasis.v0.y = y;
  this->mInverseOldBasis.v0.z = z;
  this->mInverseOldBasis.v0.w = w;
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
void __fastcall Render::FXForceParticleMover::operator()(
        Render::FXForceParticleMover *this,
        Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rdi
  float x; // xmm13_4
  float y; // xmm14_4
  float z; // xmm15_4
  float deltaTime; // xmm2_4
  float v9; // xmm15_4
  float v10; // xmm14_4
  Render::ParticleRenderUpdateTaskParam *v11; // rbx
  float v12; // xmm6_4
  float v13; // xmm0_4
  Render::ParticleEmitterSettings *mSettings; // rcx
  float v15; // xmm15_4
  float v16; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  UFG::qColour originalPosition; // [rsp+8h] [rbp-59h] BYREF
  UFG::qVector3 vVel; // [rsp+18h] [rbp-49h] BYREF
  UFG::qVector4 result; // [rsp+28h] [rbp-39h] BYREF
  UFG::qVector4 v21; // [rsp+40h] [rbp-21h] BYREF
  int v22; // [rsp+C8h] [rbp+67h]
  float lifetime; // [rsp+D0h] [rbp+6Fh]

  mTaskParams = this->mTaskParams;
  x = attr->vPosAndGrav.x;
  y = attr->vPosAndGrav.y;
  z = attr->vPosAndGrav.z;
  lifetime = (float)(mTaskParams->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime);
  UFG::qHalfVector4::operator UFG::qVector4 const(&attr->vVelAndDamp, &v21);
  deltaTime = mTaskParams->deltaTime;
  v9 = z + (float)(result.z * deltaTime);
  v10 = y + (float)(result.y * deltaTime);
  attr->vPosAndGrav.x = x + (float)(result.x * deltaTime);
  attr->vPosAndGrav.y = v10;
  attr->vPosAndGrav.z = v9;
  v11 = this->mTaskParams;
  v12 = (float)((float)(this->mWorldLocal.v1.z + this->mWorldLocal.v0.z) * 0.0)
      + (float)((float)(this->mTransformScaleFactor * attr->vPosAndGrav.w) * this->mWorldLocal.v2.z);
  Render::ApplyFXForcesToParticle(&vVel, (UFG::qVector3 *)&originalPosition, this->mForceList, v11->numForces);
  v13 = v11->deltaTime;
  v22 = ((((attr->vVelAndDamp.w.mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((attr->vVelAndDamp.w.mRep & 0x3FF | (8 * (attr->vVelAndDamp.w.mRep & 0x8000))) << 13);
  vVel.z = (float)((float)((float)(vVel.z + v12) * v13) + result.z)
         - (float)((float)((float)((float)((float)(vVel.z + v12) * v13) + result.z) * v13) * *(float *)&v22);
  Render::EmitterParticleAttribute::SetVelocity(attr, &vVel);
  mSettings = this->mSettings;
  result.x = 1.0;
  v15 = v9 + mTaskParams->renderMatrix.v3.z;
  result.y = 1.0;
  result.z = 1.0;
  vVel.z = v15;
  v16 = Render::ComputeInterpolatedAlpha(
          mSettings->mSettings.ColorAlphaKeys,
          mSettings->mSettings.AlphaKeyPositions,
          lifetime);
  mParticleLighting = this->mParticleLighting;
  result.w = v16;
  Render::ParticleLighting::ApplyDynamicLights(mParticleLighting, &originalPosition, (UFG::qColour *)&result, &vVel);
  result.x = originalPosition.r * originalPosition.r;
  result.y = originalPosition.g * originalPosition.g;
  result.z = originalPosition.b * originalPosition.b;
  result.w = originalPosition.a;
  Render::EmitterParticleAttribute::SetColour(attr, (UFG::qColour *)&result);
}

// File Line: 365
// RVA: 0x1DE440
void __fastcall Render::BounceParticleMover::operator()(
        Render::BounceParticleMover *this,
        Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rsi
  Render::ParticleRenderUpdateTaskParam *v5; // rcx
  float b; // xmm14_4
  unsigned int numBouncePlanes; // eax
  float g; // xmm15_4
  int v9; // xmm1_4
  float *p_z; // rcx
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
  float mBounciness; // xmm0_4
  Render::ParticleEmitterSettings *mSettings; // rcx
  float v32; // xmm7_4
  float v33; // xmm15_4
  float v34; // xmm14_4
  float v35; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  float lifetime; // [rsp+30h] [rbp-D0h]
  UFG::qColour vVel; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qColour particlePosition; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qColour result; // [rsp+58h] [rbp-A8h] BYREF
  float r; // [rsp+140h] [rbp+40h]
  float x; // [rsp+148h] [rbp+48h]
  float y; // [rsp+150h] [rbp+50h]
  float z; // [rsp+158h] [rbp+58h]

  mTaskParams = this->mTaskParams;
  x = attr->vPosAndGrav.x;
  z = attr->vPosAndGrav.z;
  y = attr->vPosAndGrav.y;
  lifetime = (float)(mTaskParams->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime);
  Render::CalcWorldSpacePositionAndVelocity(
    attr,
    mTaskParams,
    &this->mWorldLocal,
    this->mTransformScaleFactor,
    (UFG::qVector3 *)&particlePosition,
    (UFG::qVector3 *)&vVel);
  v5 = this->mTaskParams;
  b = particlePosition.b;
  numBouncePlanes = v5->numBouncePlanes;
  g = particlePosition.g;
  if ( numBouncePlanes )
  {
    v9 = _xmm[0];
    p_z = &v5->bouncePlaneList[0].normal.z;
    v11 = numBouncePlanes;
    r = particlePosition.r;
    v12 = vVel.r;
    v13 = vVel.b;
    v14 = vVel.g;
    do
    {
      v15 = *(p_z - 1);
      v16 = *(p_z - 2);
      v17 = *p_z;
      v18 = *((_DWORD *)p_z - 5) ^ v9;
      v19 = *((_DWORD *)p_z - 4) ^ v9;
      v20 = *((_DWORD *)p_z - 3) ^ v9;
      if ( (float)((float)((float)((float)(v16 * *(float *)&v18) + (float)(v15 * *(float *)&v19))
                         + (float)(*p_z * *(float *)&v20))
                 + (float)((float)((float)(v16 * r) + (float)(v15 * g)) + (float)(*p_z * b))) >= 0.0
        || (v21 = v16 * *(float *)&v18,
            v22 = x,
            (float)((float)((float)(v21 + (float)(v15 * *(float *)&v19)) + (float)(v17 * *(float *)&v20))
                  + (float)((float)((float)(v16 * x) + (float)(v15 * y)) + (float)(v17 * z))) < 0.0) )
      {
        v22 = r;
      }
      else
      {
        b = z;
        r = x;
        g = y;
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
        mBounciness = this->mSettings->mBounciness;
        v12 = (float)((float)(v26 - (float)((float)(v16 * 2.0) * v29)) * v24) * mBounciness;
        v14 = (float)((float)(v27 - (float)((float)(v15 * 2.0) * v29)) * v24) * mBounciness;
        vVel.r = v12;
        vVel.g = v14;
        v13 = (float)((float)(v28 - (float)((float)(v17 * 2.0) * v29)) * v24) * mBounciness;
        vVel.b = v13;
      }
      v9 = _xmm[0];
      p_z += 6;
      --v11;
    }
    while ( v11 );
  }
  else
  {
    v22 = particlePosition.r;
  }
  attr->vPosAndGrav.x = v22;
  attr->vPosAndGrav.y = g;
  attr->vPosAndGrav.z = b;
  Render::EmitterParticleAttribute::SetVelocity(attr, (UFG::qVector3 *)&vVel);
  mSettings = this->mSettings;
  vVel.r = 1.0;
  vVel.g = 1.0;
  v32 = v22 + mTaskParams->renderMatrix.v3.x;
  v33 = g + mTaskParams->renderMatrix.v3.y;
  v34 = b + mTaskParams->renderMatrix.v3.z;
  vVel.b = 1.0;
  particlePosition.r = v32;
  particlePosition.g = v33;
  particlePosition.b = v34;
  v35 = Render::ComputeInterpolatedAlpha(
          mSettings->mSettings.ColorAlphaKeys,
          mSettings->mSettings.AlphaKeyPositions,
          lifetime);
  mParticleLighting = this->mParticleLighting;
  vVel.a = v35;
  Render::ParticleLighting::ApplyDynamicLights(mParticleLighting, &result, &vVel, (UFG::qVector3 *)&particlePosition);
  particlePosition.r = result.r * result.r;
  particlePosition.g = result.g * result.g;
  particlePosition.b = result.b * result.b;
  particlePosition.a = result.a;
  Render::EmitterParticleAttribute::SetColour(attr, &particlePosition);
}

// File Line: 428
// RVA: 0x1DDAB0
void __fastcall Render::BounceParticleMoverWithLocalToWorldBlend::BounceParticleMoverWithLocalToWorldBlend(
        Render::BounceParticleMoverWithLocalToWorldBlend *this,
        Render::ParticleRenderUpdateTaskParam *taskParams,
        Render::ParticleEmitterSettings *pfx,
        Render::ParticleLighting *particleLighting,
        float transformScale,
        UFG::qMatrix44 *curBasisNormalized,
        UFG::qMatrix44 *worldLocal,
        UFG::qMatrix44 *invOldBasis)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float w; // xmm2_4
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

  y = curBasisNormalized->v0.y;
  z = curBasisNormalized->v0.z;
  w = curBasisNormalized->v0.w;
  this->mCurBasisNormalized.v0.x = curBasisNormalized->v0.x;
  this->mCurBasisNormalized.v0.y = y;
  this->mCurBasisNormalized.v0.z = z;
  this->mCurBasisNormalized.v0.w = w;
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
void __fastcall Render::BounceParticleMoverWithLocalToWorldBlend::operator()(
        Render::BounceParticleMoverWithLocalToWorldBlend *this,
        Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rsi
  Render::ParticleEmitterSettings *mSettings; // r8
  float v6; // xmm0_4
  float simTime; // xmm2_4
  float v8; // xmm2_4
  Render::ParticleRenderUpdateTaskParam *v9; // rcx
  float b; // xmm14_4
  float g; // xmm15_4
  unsigned int numBouncePlanes; // eax
  int v13; // xmm1_4
  float *p_z; // rcx
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
  int r_low; // xmm7_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm13_4
  float v31; // xmm12_4
  float v32; // xmm11_4
  float v33; // xmm2_4
  float mBounciness; // xmm0_4
  Render::ParticleEmitterSettings *v35; // rcx
  float v36; // xmm7_4
  float v37; // xmm15_4
  float v38; // xmm14_4
  float v39; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  float lifetime; // [rsp+50h] [rbp-90h]
  UFG::qColour vVel; // [rsp+58h] [rbp-88h] BYREF
  UFG::qColour particlePosition; // [rsp+68h] [rbp-78h] BYREF
  UFG::qColour result; // [rsp+78h] [rbp-68h] BYREF
  float r; // [rsp+140h] [rbp+60h]
  float x; // [rsp+148h] [rbp+68h]
  float y; // [rsp+150h] [rbp+70h]
  void *retaddr; // [rsp+158h] [rbp+78h]

  mTaskParams = this->mTaskParams;
  mSettings = this->mSettings;
  v6 = attr->fEndTime - attr->fStartTime;
  simTime = mTaskParams->simTime;
  x = attr->vPosAndGrav.x;
  v8 = (float)(simTime - attr->fStartTime) / v6;
  *(float *)&retaddr = attr->vPosAndGrav.z;
  y = attr->vPosAndGrav.y;
  lifetime = v8;
  Render::CalcPositionAndVelocityWithLocalToWorldInterpolation(
    attr,
    mTaskParams,
    mSettings,
    &this->mCurBasisNormalized,
    &this->mWorldLocal,
    &this->mInverseOldBasis,
    this->mTransformScaleFactor,
    (UFG::qVector3 *)&particlePosition,
    (UFG::qVector3 *)&vVel);
  v9 = this->mTaskParams;
  b = particlePosition.b;
  g = particlePosition.g;
  numBouncePlanes = v9->numBouncePlanes;
  if ( numBouncePlanes )
  {
    v13 = _xmm[0];
    p_z = &v9->bouncePlaneList[0].normal.z;
    v15 = numBouncePlanes;
    r = particlePosition.r;
    v16 = vVel.r;
    v17 = vVel.b;
    v18 = vVel.g;
    do
    {
      v19 = *(p_z - 1);
      v20 = *(p_z - 2);
      v21 = *p_z;
      v22 = *((_DWORD *)p_z - 5) ^ v13;
      v23 = *((_DWORD *)p_z - 4) ^ v13;
      v24 = *((_DWORD *)p_z - 3) ^ v13;
      if ( (float)((float)((float)((float)(v20 * *(float *)&v22) + (float)(v19 * *(float *)&v23))
                         + (float)(*p_z * *(float *)&v24))
                 + (float)((float)((float)(v20 * r) + (float)(v19 * g)) + (float)(*p_z * b))) >= 0.0
        || (v25 = v20 * *(float *)&v22,
            *(float *)&r_low = x,
            (float)((float)((float)(v25 + (float)(v19 * *(float *)&v23)) + (float)(v21 * *(float *)&v24))
                  + (float)((float)((float)(v20 * x) + (float)(v19 * y)) + (float)(v21 * *(float *)&retaddr))) < 0.0) )
      {
        *(float *)&r_low = r;
      }
      else
      {
        b = *(float *)&retaddr;
        r = x;
        g = y;
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
        mBounciness = this->mSettings->mBounciness;
        v16 = (float)((float)(v30 - (float)((float)(v20 * 2.0) * v33)) * v28) * mBounciness;
        v18 = (float)((float)(v31 - (float)((float)(v19 * 2.0) * v33)) * v28) * mBounciness;
        vVel.r = v16;
        vVel.g = v18;
        v17 = (float)((float)(v32 - (float)((float)(v21 * 2.0) * v33)) * v28) * mBounciness;
        vVel.b = v17;
      }
      v13 = _xmm[0];
      p_z += 6;
      --v15;
    }
    while ( v15 );
  }
  else
  {
    r_low = SLODWORD(particlePosition.r);
  }
  attr->vPosAndGrav.x = *(float *)&r_low;
  attr->vPosAndGrav.y = g;
  attr->vPosAndGrav.z = b;
  Render::EmitterParticleAttribute::SetVelocity(attr, (UFG::qVector3 *)&vVel);
  v35 = this->mSettings;
  vVel.r = 1.0;
  vVel.g = 1.0;
  v36 = *(float *)&r_low + mTaskParams->renderMatrix.v3.x;
  v37 = g + mTaskParams->renderMatrix.v3.y;
  v38 = b + mTaskParams->renderMatrix.v3.z;
  vVel.b = 1.0;
  particlePosition.r = v36;
  particlePosition.g = v37;
  particlePosition.b = v38;
  v39 = Render::ComputeInterpolatedAlpha(v35->mSettings.ColorAlphaKeys, v35->mSettings.AlphaKeyPositions, lifetime);
  mParticleLighting = this->mParticleLighting;
  vVel.a = v39;
  Render::ParticleLighting::ApplyDynamicLights(mParticleLighting, &result, &vVel, (UFG::qVector3 *)&particlePosition);
  particlePosition.r = result.r * result.r;
  particlePosition.g = result.g * result.g;
  particlePosition.b = vVel.b * vVel.b;
  particlePosition.a = vVel.a;
  Render::EmitterParticleAttribute::SetColour(attr, &particlePosition);
}

// File Line: 513
// RVA: 0x1DF050
void __fastcall Render::TargetParticleMover::operator()(
        Render::TargetParticleMover *this,
        Render::EmitterParticleAttribute *attr)
{
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rdx
  float v5; // xmm9_4
  float y; // xmm7_4
  float z; // xmm8_4
  Render::ParticleEmitterSettings *mSettings; // rcx
  float v9; // xmm8_4
  float v10; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  UFG::qVector3 resultWorldSpacePosition; // [rsp+18h] [rbp-19h] BYREF
  UFG::qColour resultWorldSpaceVelocity; // [rsp+28h] [rbp-9h] BYREF
  UFG::qColour result; // [rsp+38h] [rbp+7h] BYREF

  mTaskParams = this->mTaskParams;
  v5 = (float)(mTaskParams->simTime - attr->fStartTime) / (float)(attr->fEndTime - attr->fStartTime);
  Render::CalcWorldSpacePositionAndVelocityToTarget(
    attr,
    mTaskParams,
    (UFG::qVector3 *)&resultWorldSpacePosition.z,
    (UFG::qVector3 *)&resultWorldSpaceVelocity.b);
  y = resultWorldSpacePosition.y;
  z = resultWorldSpacePosition.z;
  attr->vPosAndGrav.x = resultWorldSpacePosition.x;
  attr->vPosAndGrav.y = y;
  attr->vPosAndGrav.z = z;
  Render::EmitterParticleAttribute::SetVelocity(attr, (UFG::qVector3 *)&resultWorldSpaceVelocity);
  mSettings = this->mSettings;
  v9 = z + this->mTaskParams->renderMatrix.v3.z;
  resultWorldSpaceVelocity.r = 1.0;
  resultWorldSpaceVelocity.g = 1.0;
  resultWorldSpaceVelocity.b = 1.0;
  resultWorldSpacePosition.z = v9;
  v10 = Render::ComputeInterpolatedAlpha(
          mSettings->mSettings.ColorAlphaKeys,
          mSettings->mSettings.AlphaKeyPositions,
          v5);
  mParticleLighting = this->mParticleLighting;
  resultWorldSpaceVelocity.a = v10;
  Render::ParticleLighting::ApplyDynamicLights(
    mParticleLighting,
    &result,
    &resultWorldSpaceVelocity,
    &resultWorldSpacePosition);
  resultWorldSpaceVelocity.r = result.r * result.r;
  resultWorldSpaceVelocity.g = result.g * result.g;
  resultWorldSpaceVelocity.b = result.b * result.b;
  resultWorldSpaceVelocity.a = result.a;
  Render::EmitterParticleAttribute::SetColour(attr, &resultWorldSpaceVelocity);
}

// File Line: 550
// RVA: 0x1DF1B0
void __fastcall Render::TargetParticleMoverWithBlend::operator()(
        Render::TargetParticleMoverWithBlend *this,
        Render::EmitterParticleAttribute *attr)
{
  float mTransformScaleFactor; // xmm3_4
  Render::ParticleRenderUpdateTaskParam *mTaskParams; // rdx
  float v6; // xmm0_4
  float v7; // xmm9_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  Render::ParticleRenderUpdateTaskParam *v13; // rax
  Render::ParticleEmitterSettings *mSettings; // rcx
  float v15; // xmm8_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  Render::ParticleLighting *mParticleLighting; // rcx
  UFG::qVector3 resultWorldSpaceVelocity; // [rsp+28h] [rbp-29h] BYREF
  UFG::qVector3 particlePosition; // [rsp+38h] [rbp-19h] BYREF
  UFG::qColour vVel; // [rsp+48h] [rbp-9h] BYREF
  UFG::qColour v23[5]; // [rsp+58h] [rbp+7h] BYREF

  mTransformScaleFactor = this->mTransformScaleFactor;
  mTaskParams = this->mTaskParams;
  v6 = attr->fEndTime - attr->fStartTime;
  *(_QWORD *)&resultWorldSpaceVelocity.x = &vVel.b;
  v7 = (float)(mTaskParams->simTime - attr->fStartTime) / v6;
  Render::CalcWorldSpacePositionAndVelocity(
    attr,
    mTaskParams,
    &this->mWorldLocal,
    mTransformScaleFactor,
    (UFG::qVector3 *)&particlePosition.z,
    (UFG::qVector3 *)&vVel.b);
  Render::CalcWorldSpacePositionAndVelocityToTarget(
    attr,
    this->mTaskParams,
    &resultWorldSpaceVelocity,
    (UFG::qVector3 *)v23);
  v8 = *(float *)&FLOAT_1_0;
  v9 = v7 * this->mSettings->mLocalSpaceToWorldSpaceBlend;
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
  v10 = (float)((float)(resultWorldSpaceVelocity.x - particlePosition.x) * v8) + particlePosition.x;
  v11 = (float)((float)(resultWorldSpaceVelocity.y - particlePosition.y) * v8) + particlePosition.y;
  v12 = (float)((float)(resultWorldSpaceVelocity.z - particlePosition.z) * v8) + particlePosition.z;
  attr->vPosAndGrav.x = v10;
  attr->vPosAndGrav.y = v11;
  attr->vPosAndGrav.z = v12;
  Render::EmitterParticleAttribute::SetVelocity(attr, (UFG::qVector3 *)&vVel);
  v13 = this->mTaskParams;
  mSettings = this->mSettings;
  v15 = v10 + v13->renderMatrix.v3.x;
  v16 = v11 + v13->renderMatrix.v3.y;
  v17 = v12 + v13->renderMatrix.v3.z;
  v23[0].r = 1.0;
  v23[0].g = 1.0;
  v23[0].b = 1.0;
  particlePosition.x = v15;
  particlePosition.y = v16;
  particlePosition.z = v17;
  v18 = Render::ComputeInterpolatedAlpha(
          mSettings->mSettings.ColorAlphaKeys,
          mSettings->mSettings.AlphaKeyPositions,
          v7);
  mParticleLighting = this->mParticleLighting;
  v23[0].a = v18;
  Render::ParticleLighting::ApplyDynamicLights(mParticleLighting, &vVel, v23, &particlePosition);
  v23[0].r = vVel.r * vVel.r;
  v23[0].g = vVel.g * vVel.g;
  v23[0].b = vVel.b * vVel.b;
  v23[0].a = vVel.a;
  Render::EmitterParticleAttribute::SetColour(attr, v23);
}

