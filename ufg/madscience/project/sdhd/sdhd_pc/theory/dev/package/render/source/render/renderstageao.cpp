// File Line: 77
// RVA: 0x33B40
void __fastcall UFG::RenderStageAO::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  UFG::RenderStageAO *v2; // rax

  v1 = render_context;
  v2 = (UFG::RenderStageAO *)UFG::qMalloc(0x90ui64, "RenderStageAO", 0i64);
  if ( v2 )
    UFG::RenderStageAO::RenderStageAO(v2, v1);
}

// File Line: 86
// RVA: 0x33940
void __fastcall UFG::RenderStageAO::RenderStageAO(UFG::RenderStageAO *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageAO *v2; // rbx
  UFG::qResourceHandle *v3; // r14
  unsigned int v4; // er15
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  unsigned int v10; // edi
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  unsigned int v13; // edi
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-98h]

  v2 = this;
  v3 = (UFG::qResourceHandle *)&this->mAOCSShader.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mAOCSShader.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mHalfResAOCSShader.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mBilateralXCSShader.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mBilateralYCSShader.mPrev);
  *(_WORD *)&v2->mAOBlur = 257;
  v2->mAOBilateralCS = 1;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( outSettings.mFeatureLevel == 2 )
  {
    v4 = UFG::qStringHash32("HK_AO_HD_CS_HALFRES", 0xFFFFFFFF);
    v5 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v5;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mHalfResAOCSShader.mPrev, 0x8B5561A1, v4, v5);
    v7 = UFG::qStringHash32("HK_AO_HD_CS_FULLRES", 0xFFFFFFFF);
    v8 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v8;
    }
    UFG::qResourceHandle::Init(v3, 0x8B5561A1, v7, v8);
    v2->mAOCSUAVParamIndex = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "AO_Output");
    v10 = UFG::qStringHash32("BILATERALBLURAMD_CS_X", 0xFFFFFFFF);
    v11 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v11;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mBilateralXCSShader.mPrev, 0x8B5561A1, v10, v11);
    v13 = UFG::qStringHash32("BILATERALBLURAMD_CS_Y", 0xFFFFFFFF);
    v14 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v15 = UFG::qResourceWarehouse::Instance();
      v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v14;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mBilateralYCSShader.mPrev, 0x8B5561A1, v13, v14);
  }
}

// File Line: 133
// RVA: 0x33B90
UFG::qVector3 *__fastcall UFG::RenderStageAO::EvaluateSphericalHarmonic(UFG::qVector3 *result, UFG::qVector3 *normal, CB_SphericalHarmonic *sh)
{
  float v3; // xmm11_4
  float v4; // xmm10_4
  float v5; // xmm8_4
  float v6; // xmm13_4
  float v7; // xmm6_4
  float v8; // xmm12_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm12_4
  UFG::qVector3 *v16; // rax

  v3 = normal->x;
  v4 = normal->z;
  v5 = normal->x * v4;
  v6 = normal->y;
  v7 = normal->x * v6;
  v8 = normal->y * v6;
  v9 = normal->y * v4;
  v10 = (float)(v3 * v3) * sh->GreenIrradianceConst[0][0];
  v11 = v5 * sh->GreenIrradianceConst[1][1];
  v12 = (float)(v3 * v3) * sh->BlueIrradianceConst[0][0];
  v13 = normal->y;
  result->x = (float)((float)((float)((float)((float)(v8 * sh->RedIrradianceConst[0][1])
                                            + (float)((float)(v3 * v3) * sh->RedIrradianceConst[0][0]))
                                    + (float)((float)(v4 * v4) * sh->RedIrradianceConst[0][2]))
                            + sh->IrradianceConst[0])
                    + (float)((float)((float)(v5 * sh->RedIrradianceConst[1][1])
                                    + (float)(v7 * sh->RedIrradianceConst[1][0]))
                            + (float)(v9 * sh->RedIrradianceConst[1][2])))
            + (float)((float)((float)(normal->y * sh->RedIrradianceConst[2][1])
                            + (float)(normal->x * sh->RedIrradianceConst[2][0]))
                    + (float)(normal->z * sh->RedIrradianceConst[2][2]));
  v14 = (float)(v8 * sh->GreenIrradianceConst[0][1]) + v10;
  v15 = v8 * sh->BlueIrradianceConst[0][1];
  result->y = (float)((float)((float)(v14 + (float)((float)(v4 * v4) * sh->GreenIrradianceConst[0][2]))
                            + sh->IrradianceConst[1])
                    + (float)((float)(v11 + (float)(v7 * sh->GreenIrradianceConst[1][0]))
                            + (float)(v9 * sh->GreenIrradianceConst[1][2])))
            + (float)((float)((float)(v13 * sh->GreenIrradianceConst[2][1])
                            + (float)(v3 * sh->GreenIrradianceConst[2][0]))
                    + (float)(v4 * sh->GreenIrradianceConst[2][2]));
  v16 = result;
  result->z = (float)((float)((float)((float)(v15 + v12) + (float)((float)(v4 * v4) * sh->BlueIrradianceConst[0][2]))
                            + sh->IrradianceConst[2])
                    + (float)((float)((float)(v5 * sh->BlueIrradianceConst[1][1])
                                    + (float)(v7 * sh->BlueIrradianceConst[1][0]))
                            + (float)(v9 * sh->BlueIrradianceConst[1][2])))
            + (float)((float)((float)(v6 * sh->BlueIrradianceConst[2][1]) + (float)(v3 * sh->BlueIrradianceConst[2][0]))
                    + (float)(v4 * sh->BlueIrradianceConst[2][2]));
  return v16;
}

// File Line: 161
// RVA: 0x33DC0
void __fastcall UFG::GetSHFromCulledLights(UFG::qMatrix44 *local_world, Render::SphericalHarmonic *sh, const int max_lights, const float luminance_threshold, const float radius_boost)
{
  Render::SphericalHarmonic *v5; // r12
  UFG::qVector3 *v6; // r13
  unsigned int v7; // edi
  int v8; // er14
  int v9; // ebx
  unsigned int v10; // ebp
  unsigned int v11; // er15
  __int64 v12; // rsi
  UFG::qMatrix44 d; // [rsp+30h] [rbp-88h]

  v5 = sh;
  v6 = (UFG::qVector3 *)&local_world->v3;
  v7 = 0;
  v8 = max_lights;
  v9 = 0;
  UFG::qInverseAffine(&d, local_world);
  v10 = 0;
  v11 = gNumNearLights + gNumStencilLights + gNumFarLights;
  if ( gNumNearLights + gNumStencilLights + gNumFarLights )
  {
    v12 = 0i64;
    while ( 1 )
    {
      if ( !(gCulledLights[v12].flags & 1) )
      {
        if ( Render::AddLightContributionToHarmonic(
               v5,
               gLights[gCulledLights[v12].lightIndex],
               v6,
               &d,
               luminance_threshold,
               radius_boost) )
        {
          if ( ++v9 == v8 )
            break;
        }
      }
      ++v10;
      ++v12;
      if ( v10 >= v11 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    if ( gSpotShadowCount > 0 )
    {
      do
      {
        if ( Render::AddLightContributionToHarmonic(
               v5,
               gLights[gCulledLights[gSpotShadowIndices[v7]].lightIndex],
               v6,
               &d,
               luminance_threshold,
               radius_boost) )
        {
          if ( ++v9 == v8 )
            break;
        }
        ++v7;
      }
      while ( v7 < gSpotShadowCount );
    }
  }
}

// File Line: 210
// RVA: 0x33F10
void __fastcall UFG::RenderStageAO::GetSignificantLightDirection(UFG::qMatrix44 *matLocalWorld, UFG::qMatrix44 *matLocalWorldInv, CB_EnvironmentSettings *envState, bool bUseDirectional, __int64 lightRadiusBoost)
{
  UFG::qMatrix44 *v5; // r14
  bool v6; // bl
  CB_EnvironmentSettings *v7; // rsi
  UFG::qMatrix44 *v8; // rdi
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  __int128 v23; // xmm7
  float v24; // xmm3_4
  float v25; // xmm6_4
  __m128 v26; // xmm2
  float v27; // xmm1_4
  float v28; // xmm6_4
  float v29; // xmm9_4
  UFG::qVector3 *v30; // rax
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm14_4
  __m128 v35; // xmm2
  float v36; // xmm3_4
  UFG::qVector3 *v37; // rax
  float v38; // xmm12_4
  float v39; // xmm11_4
  float v40; // xmm13_4
  float v41; // xmm11_4
  float v42; // xmm13_4
  float v43; // xmm12_4
  float v44; // xmm14_4
  int v45; // xmm14_4
  float v46; // xmm3_4
  __m128 v47; // xmm2
  float v48; // xmm2_4
  UFG::qVector3 *v49; // rax
  __m128 v50; // xmm3
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm12_4
  float v54; // xmm11_4
  float v55; // xmm13_4
  __m128 v56; // xmm2
  float v57; // xmm2_4
  UFG::qVector3 *v58; // rax
  float v59; // xmm14_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm12_4
  float v63; // xmm11_4
  float v64; // xmm13_4
  float v65; // xmm2_4
  float v66; // xmm10_4
  UFG::qVector3 *v67; // rax
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm12_4
  float v71; // xmm11_4
  float v72; // xmm13_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm1_4
  float v76; // xmm7_4
  float v77; // xmm2_4
  float v78; // xmm6_4
  float v79; // xmm1_4
  UFG::qVector3 direction; // [rsp+30h] [rbp-B8h]
  UFG::qColour colour; // [rsp+40h] [rbp-A8h]
  Render::SphericalHarmonic sh; // [rsp+50h] [rbp-98h]
  float irr_const; // [rsp+168h] [rbp+80h]
  float v84; // [rsp+198h] [rbp+B0h]
  float v85; // [rsp+278h] [rbp+190h]
  float radius_boost; // [rsp+298h] [rbp+1B0h]
  float v87; // [rsp+2A0h] [rbp+1B8h]
  __int64 v88; // [rsp+2A8h] [rbp+1C0h]

  v5 = matLocalWorld;
  v6 = bUseDirectional;
  v7 = envState;
  v8 = matLocalWorldInv;
  Render::SphericalHarmonic::SphericalHarmonic(&sh);
  UFG::GetSHFromCulledLights(v5, &sh, 16, s_fLumThresh, radius_boost);
  if ( v6 )
  {
    v9 = v7->SunDirWorld[0];
    v10 = v7->SunDirWorld[1];
    v11 = v7->SunDirWorld[2];
    v12 = v9;
    v13 = v7->SunDirWorld[0];
    v14 = v9 * v8->v0.z;
    colour.a = 1.0;
    v15 = v13 * v8->v0.y;
    v16 = (float)(v10 * v8->v1.x) + (float)(v12 * v8->v0.x);
    v17 = v10 * v8->v1.y;
    v18 = v10 * v8->v1.z;
    direction.x = v16 + (float)(v11 * v8->v2.x);
    v19 = v7->SunColor[1] * v87;
    v20 = (float)(v14 + v18) + (float)(v11 * v8->v2.z);
    v21 = v7->SunColor[0] * v87;
    direction.y = (float)(v15 + v17) + (float)(v11 * v8->v2.y);
    v22 = v7->SunColor[2];
    direction.z = v20;
    colour.r = v21;
    colour.g = v19;
    colour.b = v22 * v87;
    Render::SphericalHarmonic::EvalDirectionalLight(&sh, &direction, &colour);
  }
  v23 = LODWORD(sh.mRedCoefficients[1]);
  *(float *)&v23 = (float)(sh.mRedCoefficients[1] + sh.mGreenCoefficients[1]) + sh.mGreenCoefficients[4];
  v24 = (float)(sh.mRedCoefficients[3] + sh.mRedCoefficients[6]) + sh.mGreenCoefficients[6];
  v25 = (float)(sh.mRedCoefficients[2] + sh.mGreenCoefficients[2]) + sh.mGreenCoefficients[5];
  v26 = (__m128)v23;
  v26.m128_f32[0] = (float)((float)(*(float *)&v23 * *(float *)&v23) + (float)(v24 * v24)) + (float)(v25 * v25);
  if ( v26.m128_f32[0] <= 0.000001 )
  {
    v29 = 0.0;
    v23 = 0i64;
    v28 = *(float *)&FLOAT_1_0;
  }
  else
  {
    if ( v26.m128_f32[0] == 0.0 )
      v27 = 0.0;
    else
      v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
    *(float *)&v23 = *(float *)&v23 * v27;
    v28 = v25 * v27;
    v29 = v27 * v24;
  }
  direction.z = v28;
  LODWORD(direction.y) = v23;
  direction.x = v29;
  Render::SphericalHarmonic::ComputeIrradianceConstants(
    &sh,
    (float *)&sh.mHelperLight[13],
    (float *)&sh.mHelperLight[15],
    sh.mRedCoefficients);
  Render::SphericalHarmonic::ComputeIrradianceConstants(
    &sh,
    (float *)&sh.mHelperLight[13] + 1,
    &irr_const,
    sh.mGreenCoefficients);
  Render::SphericalHarmonic::ComputeIrradianceConstants(
    &sh,
    (float *)&sh.mHelperLight[14],
    &v84,
    &sh.mGreenCoefficients[3]);
  v30 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v35 = (__m128)v23;
  v31 = v29 + colorSamplingOffset;
  v32 = v30->y;
  v33 = v30->z;
  v34 = v30->x;
  *(_DWORD *)(lightRadiusBoost + 12) = 1065353216;
  *(float *)(lightRadiusBoost + 4) = v32;
  v85 = v33;
  *(float *)(lightRadiusBoost + 8) = v33;
  *(float *)lightRadiusBoost = v34;
  v35.m128_f32[0] = (float)((float)(*(float *)&v23 * *(float *)&v23) + (float)(v31 * v31)) + (float)(v28 * v28);
  if ( v35.m128_f32[0] == 0.0 )
    v36 = 0.0;
  else
    v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
  direction.x = v31 * v36;
  direction.y = *(float *)&v23 * v36;
  direction.z = v28 * v36;
  v37 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v47 = (__m128)v23;
  v38 = v37->x;
  v39 = v37->y;
  v40 = v37->z;
  *(_DWORD *)(lightRadiusBoost + 12) = 0x40000000;
  v41 = v39 + v32;
  v42 = v40 + v85;
  v43 = v38 + v34;
  v44 = colorSamplingOffset;
  *(float *)lightRadiusBoost = v43;
  *(float *)(lightRadiusBoost + 4) = v41;
  v45 = LODWORD(v44) ^ _xmm[0];
  *(float *)(lightRadiusBoost + 8) = v42;
  v46 = *(float *)&v45 + v29;
  v47.m128_f32[0] = (float)((float)(*(float *)&v23 * *(float *)&v23) + (float)(v46 * v46)) + (float)(v28 * v28);
  if ( v47.m128_f32[0] == 0.0 )
    v48 = 0.0;
  else
    v48 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v47));
  direction.x = v46 * v48;
  direction.y = *(float *)&v23 * v48;
  direction.z = v28 * v48;
  v49 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v50 = (__m128)v23;
  v50.m128_f32[0] = *(float *)&v23 + colorSamplingOffset;
  v51 = v49->y;
  v52 = v49->z;
  v53 = v43 + v49->x;
  v56 = v50;
  *(_DWORD *)(lightRadiusBoost + 12) = 1077936128;
  v54 = v41 + v51;
  v55 = v42 + v52;
  *(float *)lightRadiusBoost = v53;
  *(float *)(lightRadiusBoost + 4) = v54;
  *(float *)(lightRadiusBoost + 8) = v55;
  v56.m128_f32[0] = (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v29 * v29)) + (float)(v28 * v28);
  if ( v56.m128_f32[0] == 0.0 )
    v57 = 0.0;
  else
    v57 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v56));
  direction.y = v50.m128_f32[0] * v57;
  direction.x = v29 * v57;
  direction.z = v28 * v57;
  v58 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v59 = *(float *)&v45 + *(float *)&v23;
  v60 = v58->y;
  v61 = v58->z;
  v62 = v53 + v58->x;
  *(_DWORD *)(lightRadiusBoost + 12) = 1082130432;
  v63 = v54 + v60;
  v64 = v55 + v61;
  *(float *)lightRadiusBoost = v62;
  *(float *)(lightRadiusBoost + 4) = v63;
  *(float *)(lightRadiusBoost + 8) = v64;
  v65 = (float)((float)(v59 * v59) + (float)(v29 * v29)) + (float)(v28 * v28);
  if ( v65 == 0.0 )
    v66 = 0.0;
  else
    v66 = 1.0 / fsqrt(v65);
  direction.y = v59 * v66;
  direction.x = v29 * v66;
  direction.z = v28 * v66;
  v67 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v68 = v67->y;
  v69 = v67->z;
  v70 = (float)(v62 + v67->x) * 0.2;
  *(float *)lightRadiusBoost = v70;
  v71 = (float)(v63 + v68) * 0.2;
  v72 = (float)(v64 + v69) * 0.2;
  *(float *)(lightRadiusBoost + 4) = v71;
  *(float *)(lightRadiusBoost + 8) = v72;
  LODWORD(v73) = v23 ^ _xmm[0];
  *(float *)(lightRadiusBoost + 12) = (float)((float)(v71 * 0.5) + (float)(v70 * 0.30000001)) + (float)(v72 * 0.2);
  v74 = (float)((float)(COERCE_FLOAT(v23 ^ _xmm[0]) * v5->v1.x)
              + (float)(COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) * v5->v0.x))
      + (float)(v28 * v5->v2.x);
  v75 = v28;
  v76 = (float)(COERCE_FLOAT(v23 ^ _xmm[0]) * v5->v1.z) + (float)(COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) * v5->v0.z);
  v77 = (float)(v73 * v5->v1.y) + (float)(COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) * v5->v0.y);
  v78 = v28 * v5->v2.z;
  v79 = v75 * v5->v2.y;
  *(float *)v88 = v74;
  *(_DWORD *)(v88 + 12) = 0;
  *(float *)(v88 + 8) = v76 + v78;
  *(float *)(v88 + 4) = v77 + v79;
}

// File Line: 270
// RVA: 0x1454600
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURX__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURX", 0xFFFFFFFF);
  uidBILATERALBLURX = result;
  return result;
}

// File Line: 271
// RVA: 0x1454620
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURX_NOSUN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURX_NOSUN", 0xFFFFFFFF);
  uidBILATERALBLURX_NOSUN = result;
  return result;
}

// File Line: 272
// RVA: 0x1454640
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURY__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURY", 0xFFFFFFFF);
  uidBILATERALBLURY = result;
  return result;
}

// File Line: 273
// RVA: 0x1454660
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURY_NOSUN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURY_NOSUN", 0xFFFFFFFF);
  uidBILATERALBLURY_NOSUN = result;
  return result;
}

// File Line: 276
// RVA: 0x35370
void __fastcall UFG::RenderStageAO::RenderAmbientOcclusion(UFG::RenderStageAO *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // r15
  UFG::RenderContext *v4; // rdi
  UFG::RenderStageAO *v5; // rbx
  Illusion::StateArgs *v6; // r14
  float v7; // xmm1_4
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v8; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v9; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v10; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rax
  Illusion::RenderQueue *v12; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v13; // rcx
  Illusion::RenderQueue *v14; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v15; // rcx
  UFG::RenderContext *v16; // rdx
  UFG::RenderStageAO *v17; // rcx
  Render::ViewSettings *v18; // rbx
  UFG::qMatrix44 *v19; // r15
  unsigned __int16 v20; // ax
  const float *v21; // rbx
  const float *v22; // r15
  const float *v23; // r12
  unsigned __int16 v24; // ax
  CB_EnvironmentSettings *v25; // rbx
  Illusion::StateValues *v26; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v27; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h]
  Render::cbShadowTransformState v36; // [rsp+90h] [rbp-70h]
  __int64 v37; // [rsp+F0h] [rbp-10h]
  Render::View view; // [rsp+100h] [rbp+0h]
  RenderQueueLayer v39; // [rsp+290h] [rbp+190h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+370h] [rbp+270h]
  LayerSubmitContext ptr; // [rsp+570h] [rbp+470h]

  v37 = -2i64;
  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  if ( !render_context->mRenderFeatures.mWorld )
    return;
  RenderQueueLayer::RenderQueueLayer(&v39);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v39.mSerializationList = v3;
  ptr.mQueueMode = 0;
  ptr.mRenderQueueProvider = &v39;
  Render::View::View(&view, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
  v6 = Render::View::GetStateArgs(&view);
  if ( !v4->mRenderFeatures.mAO )
  {
    Render::View::BeginTarget(&view, v4->mAmbientOcclusionAliasTarget, "AmbientOcclusionNone", 0, 0, 0i64, 0, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::White, 1u, 1.0, 1u);
    Render::View::EndTarget(&view);
    goto LABEL_23;
  }
  v7 = v4->mAOOpacity;
  if ( v7 < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 < 0.001 )
  {
    Render::View::BeginTarget(&view, v4->mAmbientOcclusionAliasTarget, "DropShadows", 0, 0, 0i64, 0, 0, 0, 0);
    Render::View::Clear(&view, &UFG::qColour::White, 1u, 1.0, 1u);
    Render::cbExternalViewTransformState::cbExternalViewTransformState(
      &arg,
      &view.mSettings->mWorldView,
      &view.mSettings->mProjection);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v6, &arg);
    UFG::DropShadowComponent::DrawAll(&view, v4->mHalfSizeLinearDepthTarget);
    v8 = arg.mPrev;
    v9 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v9->mPrev = v8;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (arg.mStateParamIndex + 3i64)) )
      v6->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&view);
    v10 = arg.mPrev;
    v11 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v11->mPrev = v10;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    goto LABEL_23;
  }
  if ( v4->mRenderSettingsForFrame.mFeatureLevel != 2
    || v4->mRenderSettingsForFrame.mSSAO != 1
    || !v4->mQuarterSizeAmbientOcclusionTarget
    || !v5->mHDAOCS )
  {
    UFG::RenderStageAO::RenderAmbientOcclusionPS(v5, v4, &view);
    if ( !v5->mAOBlur )
      goto LABEL_23;
    v16 = v4;
    v17 = v5;
LABEL_21:
    UFG::RenderStageAO::RenderAOBilateralBlurPS(v17, v16, &view);
    goto LABEL_23;
  }
  v12 = UFG::RenderStageAO::RenderAmbientOcclusionCS(v5, v4, 1);
  v13 = v3->mNode.mPrev;
  v13->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v12->mPrev;
  v12->mPrev = v13;
  v12->mNext = &v3->mNode;
  v3->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v12->mPrev;
  if ( v5->mAOBlur && v5->mAOBilateralCS )
    UFG::RenderStageAO::RenderAOBilateralBlurCS(v5, v4, &view, 1);
  v14 = UFG::RenderStageAO::RenderAmbientOcclusionCS(v5, v4, 0);
  v15 = v3->mNode.mPrev;
  v15->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v14->mPrev;
  v14->mPrev = v15;
  v14->mNext = &v3->mNode;
  v3->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v14->mPrev;
  if ( !v5->mAOBlur )
    goto LABEL_23;
  v16 = v4;
  v17 = v5;
  if ( !v5->mAOBilateralCS )
    goto LABEL_21;
  UFG::RenderStageAO::RenderAOBilateralBlurCS(v5, v4, &view, 0);
LABEL_23:
  Render::View::BeginTarget(&view, v4->mSkyOcclusionAliasTarget, "SkyOcclusion", 0, 0, 0i64, 0, 1, 0, 0);
  Render::View::Clear(&view, &UFG::qColour::White, 1u, 1.0, 1u);
  v18 = view.mSettings;
  v19 = &view.mSettings->mProjection;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v20 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v20;
    arg.mStateParamIndex = v20;
  }
  arg.mWorldView = &v18->mWorldView;
  arg.mProjection = v19;
  arg.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v6, &arg);
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  v21 = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  v22 = UFG::RenderWorld::msStageShadow->mBiases;
  v23 = UFG::RenderWorld::msStageShadow->mCutplanes;
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mCallback = 0i64;
  v36.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v36.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v24;
    v36.mStateParamIndex = v24;
  }
  v36.mViewWorld = &view.mViewWorld;
  v36.mWorldView = (UFG::qMatrix44 *)&views;
  v36.mProjection = views.mProjection;
  v36.mCutplanes = v23;
  v36.mBiases = v22;
  v36.mBlurWidths = v21;
  v36.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v6, &v36);
  v25 = v4->mEnvState;
  v26 = Render::View::GetStateValues(&view);
  v26->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v26->mParamValues[55] = v25;
  if ( gEnableSkyIrradianceVolumes )
    DrawIrradianceVolumes(v4, &view, v4->mAmbientOcclusionVolumesType);
  v27 = arg.mPrev;
  v28 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v28->mPrev = v27;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (arg.mStateParamIndex + 3i64)) )
    v6->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v29 = v36.mPrev;
  v30 = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  v30->mPrev = v29;
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mIsSet = 0;
  if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (v36.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (v36.mStateParamIndex + 3i64)) )
    v6->mStateArgsCreateMask.mFlags[(unsigned int)v36.mStateParamIndex >> 6] &= ~(1i64 << (v36.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&view);
  v31 = v36.mPrev;
  v32 = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  v32->mPrev = v31;
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v33 = arg.mPrev;
  v34 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v34->mPrev = v33;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  RenderQueueLayer::SerializeRenderQueues(&v39);
  `eh vector destructor iterator'(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v39);
}

// File Line: 386
// RVA: 0x36140
void __fastcall UFG::RenderStageAO::RenderAmbientOcclusionPS(UFG::RenderStageAO *this, UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v3; // rsi
  UFG::RenderContext *v4; // rdi
  Illusion::StateArgs *v5; // r14
  char *v6; // rbx
  char *v7; // r15
  char *v8; // r12
  unsigned __int16 v9; // ax
  char *v10; // rbx
  UFG::qMatrix44 *v11; // r15
  UFG::qMatrix44 *v12; // r12
  unsigned __int16 v13; // ax
  Illusion::StateValues *v14; // rax
  CB_EnvironmentSettings *v15; // rbx
  Illusion::StateValues *v16; // rax
  char v17; // r15
  UFG::TimeOfDayManager *v18; // rax
  bool v19; // r12
  char *v20; // rax
  float *v21; // rbx
  _OWORD *v22; // rdx
  char *v23; // r8
  signed __int64 v24; // rcx
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm4_4
  float v38; // xmm8_4
  float v39; // xmm5_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm8_4
  Illusion::StateValues *v45; // rax
  Illusion::Material *v46; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v47; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v48; // rax
  __int64 v49; // rcx
  UFG::qMatrix44 *v50; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rax
  __int64 v53; // rcx
  UFG::qMatrix44 *v54; // rax
  __int64 dest_mip_level; // [rsp+20h] [rbp-B8h]
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h]
  UFG::qMatrix44 *v57; // [rsp+88h] [rbp-50h]
  UFG::RenderStageShadow::LinearCascadeViews *v58; // [rsp+90h] [rbp-48h]
  UFG::qMatrix44 *v59; // [rsp+98h] [rbp-40h]
  char *v60; // [rsp+A0h] [rbp-38h]
  char *v61; // [rsp+A8h] [rbp-30h]
  char *v62; // [rsp+B0h] [rbp-28h]
  __int64 v63; // [rsp+B8h] [rbp-20h]
  UFG::qVector4 outLightDirWorld; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 m; // [rsp+D8h] [rbp+0h]
  __int64 v66; // [rsp+118h] [rbp+40h]
  UFG::qMatrix44 d; // [rsp+138h] [rbp+60h]
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+178h] [rbp+A0h]
  Render::Poly poly; // [rsp+3E0h] [rbp+308h]

  v66 = -2i64;
  v3 = view;
  v4 = render_context;
  v5 = Render::View::GetStateArgs(view);
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  v6 = (char *)UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  v7 = (char *)UFG::RenderWorld::msStageShadow->mBiases;
  v8 = (char *)UFG::RenderWorld::msStageShadow->mCutplanes;
  *(_QWORD *)&arg.mStateParamIndex = (char *)&arg + 24;
  arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
  arg.mProjection = 0i64;
  LOWORD(arg.mCached_Remote.m_Stream) = Render::cbShadowTransformState::sStateParamIndex;
  WORD1(arg.mCached_Remote.m_Stream) = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v9;
    LOWORD(arg.mCached_Remote.m_Stream) = v9;
  }
  v57 = &v3->mViewWorld;
  v58 = &views;
  v59 = views.mProjection;
  v60 = v8;
  v61 = v7;
  v62 = v6;
  v63 = 0i64;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  *(float *)v10 = v4->mAOOpacity;
  Render::View::BeginTarget(v3, v4->mAmbientOcclusionAliasTarget, "AmbientOcclusion", 0, 0, 0i64, 0, 0, 0, 0);
  v11 = &v3->mSettings->mWorldView;
  v12 = &v3->mSettings->mProjection;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v13;
    arg.mStateParamIndex = v13;
  }
  arg.mWorldView = v11;
  arg.mProjection = v12;
  arg.mNext = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v5, &arg);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v5, (Render::cbShadowTransformState *)&arg.mStateParamIndex);
  v14 = Render::View::GetStateValues(v3);
  v14->mSetValueMask.mFlags[0] |= 0x8000ui64;
  v14->mParamValues[15] = v10;
  v15 = v4->mEnvState;
  v16 = Render::View::GetStateValues(v3);
  v16->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v16->mParamValues[55] = v15;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  if ( UFG::RenderWorld::msIsNisPlaying || UFG::RenderWorld::msStageHairSkin->mEnableSSSOutsideNIS )
  {
    v17 = 1;
    v18 = UFG::TimeOfDayManager::GetInstance();
    v19 = 1;
    if ( !UFG::TimeOfDayManager::IsSunShining(v18, v4->mEnvState) )
      v19 = 0;
    v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
    v21 = (float *)v20;
    v22 = (_OWORD *)v4->mEnvState->SunDir;
    v23 = v20;
    if ( ((unsigned __int8)v20 | (unsigned __int8)v4->mEnvState) & 0xF )
    {
      memmove(v20, v22, 0x100ui64);
    }
    else
    {
      v24 = 2i64;
      do
      {
        *(_OWORD *)v23 = *v22;
        *((_OWORD *)v23 + 1) = v22[1];
        *((_OWORD *)v23 + 2) = v22[2];
        *((_OWORD *)v23 + 3) = v22[3];
        *((_OWORD *)v23 + 4) = v22[4];
        *((_OWORD *)v23 + 5) = v22[5];
        *((_OWORD *)v23 + 6) = v22[6];
        v23 += 128;
        *((_OWORD *)v23 - 1) = v22[7];
        v22 += 8;
        --v24;
      }
      while ( v24 );
    }
    v25 = v3->mViewWorld.v0.y;
    v26 = v3->mViewWorld.v0.z;
    v27 = v3->mViewWorld.v0.w;
    m.v0.x = v3->mViewWorld.v0.x;
    m.v0.y = v25;
    m.v0.z = v26;
    m.v0.w = v27;
    v28 = v3->mViewWorld.v1.y;
    v29 = v3->mViewWorld.v1.z;
    v30 = v3->mViewWorld.v1.w;
    m.v1.x = v3->mViewWorld.v1.x;
    m.v1.y = v28;
    m.v1.z = v29;
    m.v1.w = v30;
    v31 = v3->mViewWorld.v2.y;
    v32 = v3->mViewWorld.v2.z;
    v33 = v3->mViewWorld.v2.w;
    m.v2.x = v3->mViewWorld.v2.x;
    m.v2.y = v31;
    m.v2.z = v32;
    m.v2.w = v33;
    v34 = v3->mViewWorld.v3.y - v31;
    v35 = v3->mViewWorld.v3.z - v32;
    v36 = v3->mViewWorld.v3.w - v33;
    m.v3.x = v3->mViewWorld.v3.x - m.v2.x;
    m.v3.y = v34;
    m.v3.z = v35;
    m.v3.w = v36;
    UFG::qInverseAffine(&d, &m);
    *(float *)&dest_mip_level = FLOAT_2_0;
    UFG::RenderStageAO::GetSignificantLightDirection(&m, &d, v4->mEnvState, v19, dest_mip_level);
    v37 = outLightDirWorld.x;
    v21[4] = outLightDirWorld.x;
    v38 = outLightDirWorld.y;
    v21[5] = outLightDirWorld.y;
    v39 = outLightDirWorld.z;
    v21[6] = outLightDirWorld.z;
    v40 = outLightDirWorld.w;
    v21[7] = outLightDirWorld.w;
    v41 = (float)((float)((float)(v38 * v3->mSettings->mWorldView.v1.x) + (float)(v37 * v3->mSettings->mWorldView.v0.x))
                + (float)(v39 * v3->mSettings->mWorldView.v2.x))
        + (float)(v40 * v3->mSettings->mWorldView.v3.x);
    v42 = (float)((float)((float)(v38 * v3->mSettings->mWorldView.v1.y) + (float)(v37 * v3->mSettings->mWorldView.v0.y))
                + (float)(v39 * v3->mSettings->mWorldView.v2.y))
        + (float)(v40 * v3->mSettings->mWorldView.v3.y);
    v43 = (float)((float)((float)(v38 * v3->mSettings->mWorldView.v1.z) + (float)(v37 * v3->mSettings->mWorldView.v0.z))
                + (float)(v39 * v3->mSettings->mWorldView.v2.z))
        + (float)(v40 * v3->mSettings->mWorldView.v3.z);
    v44 = (float)((float)((float)(v38 * v3->mSettings->mWorldView.v1.w) + (float)(v37 * v3->mSettings->mWorldView.v0.w))
                + (float)(v39 * v3->mSettings->mWorldView.v2.w))
        + (float)(v40 * v3->mSettings->mWorldView.v3.w);
    *v21 = v41;
    v21[1] = v42;
    v21[2] = v43;
    v21[3] = v44;
    v45 = Render::View::GetStateValues(v3);
    v45->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v45->mParamValues[55] = v21;
  }
  else
  {
    v17 = 0;
  }
  if ( v4->mRenderSettingsForFrame.mSSAO == 1 )
  {
    v46 = v4->mSSAOHighMaterial;
  }
  else if ( v17 )
  {
    v46 = v4->mSSAONISMaterial;
  }
  else
  {
    v46 = v4->mSSAOMaterial;
  }
  Render::View::Draw(v3, &poly, v46, 0i64);
  v47 = arg.mPrev;
  v48 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v48->mPrev = v47;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v5->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v5 + 16 * (arg.mStateParamIndex + 3i64)) )
    v5->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v49 = *(_QWORD *)&arg.mStateParamIndex;
  v50 = arg.mWorldView;
  *(_QWORD *)(*(_QWORD *)&arg.mStateParamIndex + 8i64) = arg.mWorldView;
  *(_QWORD *)&v50->v0.x = v49;
  *(_QWORD *)&arg.mStateParamIndex = (char *)&arg + 24;
  arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
  BYTE3(arg.mCached_Remote.m_Stream) = 0;
  if ( (Illusion::StateArgs *)v5->mStateArgsCreateMask.mFlags[2 * (SLOWORD(arg.mCached_Remote.m_Stream) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v5 + 16 * (SLOWORD(arg.mCached_Remote.m_Stream) + 3i64)) )
    v5->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(arg.mCached_Remote.m_Stream) >> 6] &= ~(1i64 << ((_QWORD)arg.mCached_Remote.m_Stream & 0x3F));
  Render::View::EndTarget(v3);
  v51 = arg.mPrev;
  v52 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v52->mPrev = v51;
  v53 = *(_QWORD *)&arg.mStateParamIndex;
  v54 = arg.mWorldView;
  *(_QWORD *)(*(_QWORD *)&arg.mStateParamIndex + 8i64) = arg.mWorldView;
  *(_QWORD *)&v54->v0.x = v53;
}

// File Line: 455
// RVA: 0x350C0
void __fastcall UFG::RenderStageAO::RenderAOBilateralBlurPS(UFG::RenderStageAO *this, UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v3; // r14
  UFG::RenderContext *v4; // rsi
  Illusion::StateArgs *v5; // r15
  _WORD *v6; // rbx
  Illusion::Target *v7; // r8
  Illusion::Target *v8; // rdx
  unsigned int v9; // er9
  __int64 v10; // rdi
  signed __int64 v11; // r12
  unsigned __int16 v12; // ax
  Illusion::Material *v13; // rdi
  __int64 v14; // rax
  _WORD *v15; // rax
  __int64 v16; // rax
  unsigned int v17; // er8
  __int64 v18; // rax
  __int64 v19; // rcx
  UFG::qVector4 *v20; // rax
  unsigned __int64 *v21; // rdx
  __int64 v22; // rcx
  UFG::qVector4 *v23; // rax
  bool clearOnResolve[8]; // [rsp+30h] [rbp-1h]
  UFG::qVector4 *texUV; // [rsp+38h] [rbp+7h]
  bool ps4_decompress_depth[8]; // [rsp+40h] [rbp+Fh]
  bool d3d_disable_depth_copy[2]; // [rsp+48h] [rbp+17h]
  __int16 v28; // [rsp+4Ah] [rbp+19h]
  __int64 v29; // [rsp+50h] [rbp+1Fh]
  __int64 v30; // [rsp+58h] [rbp+27h]
  __int64 v31; // [rsp+60h] [rbp+2Fh]
  Render::Poly poly; // [rsp+A0h] [rbp+6Fh]

  v3 = view;
  v4 = render_context;
  v5 = Render::View::GetStateArgs(view);
  Render::gRenderUtilities.mSubmitContext = v3->mSubmitContext;
  v6 = 0i64;
  v7 = v4->mHalfSizeScratchTargetB;
  v8 = v4->mAmbientOcclusionAliasTarget;
  texUV = 0i64;
  clearOnResolve[0] = 1;
  v9 = uidBILATERALBLURX;
  if ( !v4->mRenderSun )
    v9 = uidBILATERALBLURX_NOSUN;
  Render::RenderUtilities::Blit(&Render::gRenderUtilities, v8, v7, v9, "AO Blur X", 0, clearOnResolve[0], texUV);
  Render::gRenderUtilities.mSubmitContext = 0i64;
  Render::View::BeginTarget(v3, v4->mAmbientOcclusionAliasTarget, "AO Blur Y/ Blobs", 0, 0, 0i64, 1, 0, 0, 0);
  v10 = (__int64)v3->mSettings;
  v11 = (signed __int64)&v3->mSettings->mProjection;
  *(_QWORD *)clearOnResolve = clearOnResolve;
  texUV = (UFG::qVector4 *)clearOnResolve;
  *(_QWORD *)ps4_decompress_depth = 0i64;
  *(_WORD *)d3d_disable_depth_copy = Render::cbExternalViewTransformState::sStateParamIndex;
  v28 = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v12 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v12;
    *(_WORD *)d3d_disable_depth_copy = v12;
  }
  v29 = v10;
  v30 = v11;
  v31 = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(
    v5,
    (Render::cbExternalViewTransformState *)clearOnResolve);
  v13 = Render::gRenderUtilities.mMaterial;
  if ( !v4->mRenderSun )
  {
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) == uidBILATERALBLURY_NOSUN )
      goto LABEL_14;
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
      Render::gRenderUtilities.mMaterial[1].mTypeUID,
      uidBILATERALBLURY_NOSUN);
    v16 = v13->mMaterialUser.mOffset;
    if ( v16 )
    {
      v15 = (_WORD *)((char *)&v13->mMaterialUser + v16);
      goto LABEL_13;
    }
LABEL_12:
    v15 = 0i64;
    goto LABEL_13;
  }
  if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) == uidBILATERALBLURY )
    goto LABEL_14;
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
    Render::gRenderUtilities.mMaterial[1].mTypeUID,
    uidBILATERALBLURY);
  v14 = v13->mMaterialUser.mOffset;
  if ( !v14 )
    goto LABEL_12;
  v15 = (_WORD *)((char *)&v13->mMaterialUser + v14);
LABEL_13:
  *v15 |= 0x20u;
  v13 = Render::gRenderUtilities.mMaterial;
LABEL_14:
  v17 = v4->mHalfSizeScratchTargetB->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(v13[1].mStateBlockMask.mFlags[0]) != v17 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v13[1].mDebugName[20], v13[1].mStateBlockMask.mFlags[1], v17);
    v18 = v13->mMaterialUser.mOffset;
    if ( v18 )
      v6 = (_WORD *)((char *)&v13->mMaterialUser + v18);
    *v6 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(v3, &poly, Render::gRenderUtilities.mMaterial, 0i64);
  UFG::DropShadowComponent::DrawAll(v3, v4->mHalfSizeLinearDepthTarget);
  v19 = *(_QWORD *)clearOnResolve;
  v20 = texUV;
  *(_QWORD *)(*(_QWORD *)clearOnResolve + 8i64) = texUV;
  *(_QWORD *)&v20->x = v19;
  *(_QWORD *)clearOnResolve = clearOnResolve;
  texUV = (UFG::qVector4 *)clearOnResolve;
  HIBYTE(v28) = 0;
  if ( (Illusion::StateArgs *)v5->mStateArgsCreateMask.mFlags[2 * (*(signed __int16 *)d3d_disable_depth_copy + 3i64) + 1] == (Illusion::StateArgs *)((char *)v5 + 16 * (*(signed __int16 *)d3d_disable_depth_copy + 3i64)) )
  {
    v21 = &v5->mStateArgsCreateMask.mFlags[(unsigned int)*(signed __int16 *)d3d_disable_depth_copy >> 6];
    *v21 &= ~(1i64 << (d3d_disable_depth_copy[0] & 0x3F));
  }
  Render::View::EndTarget(v3);
  v22 = *(_QWORD *)clearOnResolve;
  v23 = texUV;
  *(_QWORD *)(*(_QWORD *)clearOnResolve + 8i64) = texUV;
  *(_QWORD *)&v23->x = v22;
}

// File Line: 489
// RVA: 0x359C0
Illusion::RenderQueue *__fastcall UFG::RenderStageAO::RenderAmbientOcclusionCS(UFG::RenderStageAO *this, UFG::RenderContext *render_context, bool bQuarterSize)
{
  bool v3; // r14
  UFG::RenderContext *v4; // rsi
  UFG::RenderStageAO *v5; // r13
  Illusion::Target *v6; // rbp
  __m128 v7; // xmm1
  signed int v8; // ecx
  __m128 v9; // xmm1
  signed int v10; // ecx
  signed int v11; // er12
  char *v12; // rax
  char *v13; // rbx
  _QWORD *v14; // ST28_8
  UFG::qResourceData *v15; // r15
  __int64 v16; // rdx
  __int64 v17; // rax
  signed __int64 v18; // rcx
  char *v19; // rax
  char *v20; // rdx
  __int64 v21; // rax
  __int64 v22; // rax
  float v23; // xmm1_4
  float v24; // xmm10_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm10_4
  float v28; // xmm10_4
  float v29; // xmm9_4
  float v30; // xmm7_4
  float *v31; // r15
  __int64 v32; // rdx
  __int64 v33; // rax
  signed __int64 v34; // rcx
  char *v35; // rax
  char *v36; // rdx
  __int64 v37; // rax
  __int64 v38; // rax
  Illusion::Target *v39; // rax
  Illusion::Texture *v40; // rbp
  __int64 v41; // rdx
  __int64 v42; // rax
  signed __int64 v43; // rcx
  char *v44; // rax
  char *v45; // rdx
  __int64 v46; // rax
  __int64 v47; // rax
  Illusion::Texture *v48; // rbp
  __int64 v49; // rdx
  __int64 v50; // rax
  signed __int64 v51; // rcx
  char *v52; // rax
  char *v53; // rdx
  __int64 v54; // rax
  __int64 v55; // rax
  Illusion::UnorderedAccessView *v56; // rsi
  unsigned __int16 v57; // bp
  __int64 v58; // rdx
  __int64 v59; // rax
  signed __int64 v60; // rcx
  char *v61; // rax
  char *v62; // rdx
  __int64 v63; // rax
  __int64 v64; // rax
  char *v65; // rsi
  __int64 v66; // rcx
  __int64 v67; // rdx
  signed __int64 v68; // rax
  char *v69; // rax
  char *v70; // rdx
  __int64 v71; // rax
  __int64 v72; // rax
  __int64 v73; // rax
  __int64 v75; // [rsp+D0h] [rbp+8h]
  float v76; // [rsp+E0h] [rbp+18h]

  v3 = bQuarterSize;
  v4 = render_context;
  v5 = this;
  if ( bQuarterSize )
    v6 = render_context->mQuarterSizeAmbientOcclusionTarget;
  else
    v6 = render_context->mAmbientOcclusionAliasTarget;
  v7 = (__m128)COERCE_UNSIGNED_INT((float)v6->mWidth);
  v7.m128_f32[0] = v7.m128_f32[0] * 0.03125;
  v8 = (signed int)v7.m128_f32[0];
  if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
    v7.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1 ^ 1) + v8);
  v75 = (unsigned int)(signed int)v7.m128_f32[0];
  v9 = (__m128)COERCE_UNSIGNED_INT((float)v6->mHeight);
  v9.m128_f32[0] = v9.m128_f32[0] * 0.03125;
  v10 = (signed int)v9.m128_f32[0];
  if ( (signed int)v9.m128_f32[0] != 0x80000000 && (float)v10 != v9.m128_f32[0] )
    v9.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v9, v9)) & 1 ^ 1) + v10);
  v11 = (signed int)v9.m128_f32[0];
  v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v13 = v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = v12;
    *((_QWORD *)v12 + 1) = v12;
    v14 = v12 + 16;
    *v14 = v14;
    v14[1] = v14;
    UFG::qMemSet(v12 + 96, 0, 0x400u);
    *((_QWORD *)v13 + 11) = 0i64;
    *((_QWORD *)v13 + 10) = 0i64;
    *((_DWORD *)v13 + 8) = 0;
    *((_QWORD *)v13 + 5) = 0i64;
    *((_QWORD *)v13 + 6) = 0i64;
    *((_QWORD *)v13 + 7) = 0i64;
    *((_QWORD *)v13 + 8) = 0i64;
    *((_QWORD *)v13 + 9) = 0i64;
  }
  else
  {
    v13 = 0i64;
  }
  if ( v3 )
    v15 = v5->mHalfResAOCSShader.mData;
  else
    v15 = v5->mAOCSShader.mData;
  v16 = *((_QWORD *)v13 + 5);
  if ( v16 )
  {
    v17 = *(unsigned int *)(v16 + 24);
    if ( (unsigned int)v17 < 0x7E )
    {
      v18 = v16 + 16 * (v17 + 2);
      *(_DWORD *)(v16 + 24) = v17 + 1;
      goto LABEL_25;
    }
    if ( v16 )
    {
      *((_DWORD *)v13 + 18) += *(_DWORD *)(v16 + 24);
      *((_QWORD *)v13 + 5) = 0i64;
    }
  }
  v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v20 = v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = v19;
    *((_QWORD *)v19 + 1) = v19;
    *((_QWORD *)v19 + 2) = 0i64;
    *((_DWORD *)v19 + 6) = 0;
    v21 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v21 + 8) = v20;
    *(_QWORD *)v20 = v21;
    *((_QWORD *)v20 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v20;
    *((_QWORD *)v13 + 5) = v20;
  }
  v22 = *((_QWORD *)v13 + 5);
  if ( v22 )
  {
    *(_DWORD *)(v22 + 24) = 1;
    v18 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_25:
    if ( v18 )
    {
      *(_DWORD *)v18 = 1;
      *(_QWORD *)(v18 + 8) = v15;
    }
  }
  v23 = v4->mMainViewSettings.mProjection.v2.z;
  v24 = v4->mMainViewSettings.mProjection.v3.z;
  v25 = v4->mMainViewSettings.mProjection.v2.w;
  if ( v23 == 0.0 || v23 == v25 )
  {
    v27 = v76;
    v26 = v76;
  }
  else
  {
    v26 = v24 / v23;
    v27 = (float)(v24 - v4->mMainViewSettings.mProjection.v3.w) / (float)(v23 - v25);
  }
  v28 = v27 / (float)(v27 - v26);
  v29 = 1.0 / v4->mMainViewSettings.mProjection.v0.x;
  v30 = 1.0 / v4->mMainViewSettings.mProjection.v1.y;
  v31 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  *v31 = (float)v6->mWidth;
  v31[1] = (float)v6->mHeight;
  v31[2] = 1.0 / (float)v6->mWidth;
  v31[3] = 1.0 / (float)v6->mHeight;
  v31[7] = v28 * v26;
  v31[6] = v28 * v26;
  v31[5] = v28 * v26;
  v31[4] = v28 * v26;
  v31[11] = v28;
  v31[10] = v28;
  v31[9] = v28;
  v31[8] = v28;
  v31[12] = v29;
  v31[13] = v30;
  v32 = *((_QWORD *)v13 + 5);
  if ( v32 )
  {
    v33 = *(unsigned int *)(v32 + 24);
    if ( (unsigned int)v33 < 0x7E )
    {
      v34 = v32 + 16 * (v33 + 2);
      *(_DWORD *)(v32 + 24) = v33 + 1;
      goto LABEL_40;
    }
    if ( v32 )
    {
      *((_DWORD *)v13 + 18) += *(_DWORD *)(v32 + 24);
      *((_QWORD *)v13 + 5) = 0i64;
    }
  }
  v35 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v36 = v35;
  if ( v35 )
  {
    *(_QWORD *)v35 = v35;
    *((_QWORD *)v35 + 1) = v35;
    *((_QWORD *)v35 + 2) = 0i64;
    *((_DWORD *)v35 + 6) = 0;
    v37 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v37 + 8) = v36;
    *(_QWORD *)v36 = v37;
    *((_QWORD *)v36 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v36;
    *((_QWORD *)v13 + 5) = v36;
  }
  v38 = *((_QWORD *)v13 + 5);
  if ( v38 )
  {
    *(_DWORD *)(v38 + 24) = 1;
    v34 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_40:
    if ( v34 )
    {
      *(_DWORD *)v34 = 983042;
      *(_QWORD *)(v34 + 8) = v31;
    }
  }
  if ( v3 )
    v39 = v4->mQuarterSizeLinearDepthTarget;
  else
    v39 = v4->mHalfSizeLinearDepthTarget;
  v40 = v39->mTargetTexture[0];
  v41 = *((_QWORD *)v13 + 5);
  if ( v41 )
  {
    v42 = *(unsigned int *)(v41 + 24);
    if ( (unsigned int)v42 < 0x7E )
    {
      v43 = v41 + 16 * (v42 + 2);
      *(_DWORD *)(v41 + 24) = v42 + 1;
      goto LABEL_54;
    }
    if ( v41 )
    {
      *((_DWORD *)v13 + 18) += *(_DWORD *)(v41 + 24);
      *((_QWORD *)v13 + 5) = 0i64;
    }
  }
  v44 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v45 = v44;
  if ( v44 )
  {
    *(_QWORD *)v44 = v44;
    *((_QWORD *)v44 + 1) = v44;
    *((_QWORD *)v44 + 2) = 0i64;
    *((_DWORD *)v44 + 6) = 0;
    v46 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v46 + 8) = v45;
    *(_QWORD *)v45 = v46;
    *((_QWORD *)v45 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v45;
    *((_QWORD *)v13 + 5) = v45;
  }
  v47 = *((_QWORD *)v13 + 5);
  if ( v47 )
  {
    *(_DWORD *)(v47 + 24) = 1;
    v43 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_54:
    if ( v43 )
    {
      *(_DWORD *)v43 = 3080194;
      *(_QWORD *)(v43 + 8) = v40;
    }
  }
  if ( !v3 )
  {
    v48 = v4->mQuarterSizeAmbientOcclusionTarget->mTargetTexture[0];
    v49 = *((_QWORD *)v13 + 5);
    if ( v49 )
    {
      v50 = *(unsigned int *)(v49 + 24);
      if ( (unsigned int)v50 < 0x7E )
      {
        v51 = v49 + 16 * (v50 + 2);
        *(_DWORD *)(v49 + 24) = v50 + 1;
        goto LABEL_66;
      }
      if ( v49 )
      {
        *((_DWORD *)v13 + 18) += *(_DWORD *)(v49 + 24);
        *((_QWORD *)v13 + 5) = 0i64;
      }
    }
    v52 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v53 = v52;
    if ( v52 )
    {
      *(_QWORD *)v52 = v52;
      *((_QWORD *)v52 + 1) = v52;
      *((_QWORD *)v52 + 2) = 0i64;
      *((_DWORD *)v52 + 6) = 0;
      v54 = *((_QWORD *)v13 + 2);
      *(_QWORD *)(v54 + 8) = v53;
      *(_QWORD *)v53 = v54;
      *((_QWORD *)v53 + 1) = v13 + 16;
      *((_QWORD *)v13 + 2) = v53;
      *((_QWORD *)v13 + 5) = v53;
    }
    v55 = *((_QWORD *)v13 + 5);
    if ( !v55 )
      goto LABEL_68;
    *(_DWORD *)(v55 + 24) = 1;
    v51 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_66:
    if ( v51 )
    {
      *(_DWORD *)v51 = 1114114;
      *(_QWORD *)(v51 + 8) = v48;
    }
LABEL_68:
    v56 = v4->mAmbientOcclusionAliasUAV;
    goto LABEL_70;
  }
  v56 = v4->mQuarterSizeAmbientOcclusionAliasUAV;
LABEL_70:
  v57 = v5->mAOCSUAVParamIndex;
  v58 = *((_QWORD *)v13 + 5);
  if ( v58 )
  {
    v59 = *(unsigned int *)(v58 + 24);
    if ( (unsigned int)v59 < 0x7E )
    {
      v60 = v58 + 16 * (v59 + 2);
      *(_DWORD *)(v58 + 24) = v59 + 1;
      goto LABEL_79;
    }
    if ( v58 )
    {
      *((_DWORD *)v13 + 18) += *(_DWORD *)(v58 + 24);
      *((_QWORD *)v13 + 5) = 0i64;
    }
  }
  v61 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v62 = v61;
  if ( v61 )
  {
    *(_QWORD *)v61 = v61;
    *((_QWORD *)v61 + 1) = v61;
    *((_QWORD *)v61 + 2) = 0i64;
    *((_DWORD *)v61 + 6) = 0;
    v63 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v63 + 8) = v62;
    *(_QWORD *)v62 = v63;
    *((_QWORD *)v62 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v62;
    *((_QWORD *)v13 + 5) = v62;
  }
  v64 = *((_QWORD *)v13 + 5);
  if ( v64 )
  {
    *(_DWORD *)(v64 + 24) = 1;
    v60 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_79:
    if ( v60 )
    {
      *(_WORD *)v60 = 2;
      *(_WORD *)(v60 + 2) = v57;
      *(_QWORD *)(v60 + 8) = v56;
    }
  }
  v65 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 4u);
  if ( v65 )
  {
    *(_DWORD *)v65 = v75;
    *((_DWORD *)v65 + 1) = v11;
    *((_DWORD *)v65 + 2) = 1;
  }
  else
  {
    v65 = 0i64;
  }
  v66 = *((_QWORD *)v13 + 5);
  if ( v66 )
  {
    v67 = *(unsigned int *)(v66 + 24);
    if ( (unsigned int)v67 < 0x7E )
    {
      *(_DWORD *)(v66 + 24) = v67 + 1;
      v68 = v66 + 16 * (v67 + 2);
      goto LABEL_93;
    }
    if ( v66 )
    {
      *((_DWORD *)v13 + 18) += *(_DWORD *)(v66 + 24);
      *((_QWORD *)v13 + 5) = 0i64;
    }
  }
  v69 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v70 = v69;
  if ( v69 )
  {
    *(_QWORD *)v69 = v69;
    *((_QWORD *)v69 + 1) = v69;
    *((_QWORD *)v69 + 2) = 0i64;
    *((_DWORD *)v69 + 6) = 0;
    v71 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v71 + 8) = v70;
    *(_QWORD *)v70 = v71;
    *((_QWORD *)v70 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v70;
    *((_QWORD *)v13 + 5) = v70;
  }
  v72 = *((_QWORD *)v13 + 5);
  if ( v72 )
  {
    *(_DWORD *)(v72 + 24) = 1;
    v68 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_93:
    if ( v68 )
    {
      *(_DWORD *)v68 = 26;
      *(_QWORD *)(v68 + 8) = v65;
    }
  }
  v73 = *((_QWORD *)v13 + 5);
  if ( v73 )
  {
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v73 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  return (Illusion::RenderQueue *)v13;
}

// File Line: 543
// RVA: 0x34590
void __fastcall UFG::RenderStageAO::RenderAOBilateralBlurCS(UFG::RenderStageAO *this, UFG::RenderContext *render_context, Render::View *view, bool bQuarterSize)
{
  UFG::RenderContext *v4; // r13
  UFG::RenderStageAO *v5; // rbx
  Illusion::Target *v6; // r15
  float *v7; // rax
  float *v8; // r14
  char *v9; // rax
  char *v10; // rdi
  _QWORD *v11; // ST18_8
  UFG::qResourceData *v12; // rbx
  __int64 v13; // rdx
  __int64 v14; // rax
  signed __int64 v15; // rcx
  char *v16; // rax
  char *v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rdx
  __int64 v21; // rax
  signed __int64 v22; // rcx
  char *v23; // rax
  char *v24; // rdx
  __int64 v25; // rax
  __int64 v26; // rax
  char v27; // r14
  Illusion::Texture *v28; // rbx
  __int64 v29; // rdx
  __int64 v30; // rax
  signed __int64 v31; // rcx
  char *v32; // rax
  char *v33; // rdx
  __int64 v34; // rax
  __int64 v35; // rax
  Illusion::UnorderedAccessView *v36; // rbx
  __int16 v37; // r14
  __int64 v38; // rdx
  __int64 v39; // rax
  signed __int64 v40; // rcx
  char *v41; // rax
  char *v42; // rdx
  __int64 v43; // rax
  __int64 v44; // rax
  __m128 v45; // xmm1
  signed int v46; // ecx
  __m128 v47; // xmm2
  signed int v48; // ecx
  char *v49; // rax
  char *v50; // rbx
  __int64 v51; // rdx
  __int64 v52; // rax
  signed __int64 v53; // rcx
  char *v54; // rax
  char *v55; // rdx
  __int64 v56; // rax
  __int64 v57; // rax
  __int64 v58; // r15
  __int64 v59; // rbx
  __int64 v60; // rdx
  __int64 v61; // rax
  signed __int64 v62; // rcx
  char *v63; // rax
  char *v64; // rdx
  __int64 v65; // rax
  __int64 v66; // rax
  __int64 v67; // rdx
  __int64 v68; // rax
  signed __int64 v69; // rcx
  char *v70; // rax
  char *v71; // rdx
  __int64 v72; // rax
  __int64 v73; // rax
  char v74; // r14
  Illusion::Texture *v75; // rbx
  __int64 v76; // rdx
  __int64 v77; // rax
  signed __int64 v78; // rcx
  char *v79; // rax
  char *v80; // rdx
  __int64 v81; // rax
  __int64 v82; // rax
  Illusion::UnorderedAccessView *v83; // rbx
  __int16 v84; // r14
  __int64 v85; // rdx
  __int64 v86; // rax
  signed __int64 v87; // rcx
  char *v88; // rax
  char *v89; // rdx
  __int64 v90; // rax
  __int64 v91; // rax
  __m128 v92; // xmm1
  signed int v93; // ecx
  signed int v94; // er15
  __m128 v95; // xmm1
  signed int v96; // ecx
  char *v97; // rax
  char *v98; // rbx
  __int64 v99; // rdx
  __int64 v100; // rax
  signed __int64 v101; // rcx
  char *v102; // rax
  char *v103; // rdx
  __int64 v104; // rax
  __int64 v105; // rax
  __int64 v106; // rax
  Render::View *v107; // r15
  RenderQueueLayer *v108; // rbx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v109; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v110; // rax
  Illusion::StateArgs *v111; // rbx
  __int64 v112; // rdi
  signed __int64 v113; // r14
  unsigned __int16 v114; // ax
  __int64 v115; // rcx
  _QWORD *v116; // rax
  __int64 v117; // rcx
  _QWORD *v118; // rax
  signed int *vp_scissor; // [rsp+28h] [rbp-39h]
  bool clear_on_resolve[8]; // [rsp+30h] [rbp-31h]
  bool ignore_resolve_depth[8]; // [rsp+38h] [rbp-29h]
  bool ps4_decompress_depth[8]; // [rsp+40h] [rbp-21h]
  bool d3d_disable_depth_copy[2]; // [rsp+48h] [rbp-19h]
  __int16 v124; // [rsp+4Ah] [rbp-17h]
  __int64 v125; // [rsp+50h] [rbp-11h]
  __int64 v126; // [rsp+58h] [rbp-9h]
  __int64 v127; // [rsp+60h] [rbp-1h]
  float *v128; // [rsp+68h] [rbp+7h]
  char *v129; // [rsp+70h] [rbp+Fh]
  __int64 v130; // [rsp+78h] [rbp+17h]
  char *v131; // [rsp+C8h] [rbp+67h]
  Render::View *viewa; // [rsp+D8h] [rbp+77h]
  char v133; // [rsp+E0h] [rbp+7Fh]

  v130 = -2i64;
  v4 = render_context;
  v5 = this;
  if ( bQuarterSize )
    v6 = render_context->mQuarterSizeAmbientOcclusionTarget;
  else
    v6 = render_context->mAmbientOcclusionAliasTarget;
  vp_scissor = (signed int *)v6;
  v7 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  v8 = v7;
  v128 = v7;
  *v7 = (float)v6->mWidth;
  v7[1] = (float)v6->mHeight;
  v7[2] = 1.0 / (float)v6->mWidth;
  v7[3] = 1.0 / (float)v6->mHeight;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v10 = v9;
  v129 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = v9;
    *((_QWORD *)v9 + 1) = v9;
    v11 = v9 + 16;
    *v11 = v11;
    v11[1] = v11;
    UFG::qMemSet(v9 + 96, 0, 0x400u);
    *((_QWORD *)v10 + 11) = 0i64;
    *((_QWORD *)v10 + 10) = 0i64;
    *((_DWORD *)v10 + 8) = 0;
    *((_QWORD *)v10 + 5) = 0i64;
    *((_QWORD *)v10 + 6) = 0i64;
    *((_QWORD *)v10 + 7) = 0i64;
    *((_QWORD *)v10 + 8) = 0i64;
    *((_QWORD *)v10 + 9) = 0i64;
  }
  else
  {
    v10 = 0i64;
  }
  v12 = v5->mBilateralXCSShader.mData;
  v13 = *((_QWORD *)v10 + 5);
  if ( v13 )
  {
    v14 = *(unsigned int *)(v13 + 24);
    if ( (unsigned int)v14 < 0x7E )
    {
      v15 = v13 + 16 * (v14 + 2);
      *(_DWORD *)(v13 + 24) = v14 + 1;
      goto LABEL_16;
    }
    if ( v13 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v13 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v17 = v16;
  if ( v16 )
  {
    *(_QWORD *)v16 = v16;
    *((_QWORD *)v16 + 1) = v16;
    *((_QWORD *)v16 + 2) = 0i64;
    *((_DWORD *)v16 + 6) = 0;
    v18 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v18 + 8) = v17;
    *(_QWORD *)v17 = v18;
    *((_QWORD *)v17 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v17;
    *((_QWORD *)v10 + 5) = v17;
  }
  v19 = *((_QWORD *)v10 + 5);
  if ( v19 )
  {
    *(_DWORD *)(v19 + 24) = 1;
    v15 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_16:
    if ( v15 )
    {
      *(_DWORD *)v15 = 1;
      *(_QWORD *)(v15 + 8) = v12;
    }
  }
  v20 = *((_QWORD *)v10 + 5);
  if ( v20 )
  {
    v21 = *(unsigned int *)(v20 + 24);
    if ( (unsigned int)v21 < 0x7E )
    {
      v22 = v20 + 16 * (v21 + 2);
      *(_DWORD *)(v20 + 24) = v21 + 1;
      goto LABEL_27;
    }
    if ( v20 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v20 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v23 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v24 = v23;
  if ( v23 )
  {
    *(_QWORD *)v23 = v23;
    *((_QWORD *)v23 + 1) = v23;
    *((_QWORD *)v23 + 2) = 0i64;
    *((_DWORD *)v23 + 6) = 0;
    v25 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v25 + 8) = v24;
    *(_QWORD *)v24 = v25;
    *((_QWORD *)v24 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v24;
    *((_QWORD *)v10 + 5) = v24;
  }
  v26 = *((_QWORD *)v10 + 5);
  if ( v26 )
  {
    *(_DWORD *)(v26 + 24) = 1;
    v22 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_27:
    if ( v22 )
    {
      *(_DWORD *)v22 = 983042;
      *(_QWORD *)(v22 + 8) = v8;
    }
  }
  v27 = v133;
  if ( v133 )
    v28 = v4->mQuarterSizeScratchAPointSampleTexture;
  else
    v28 = v4->mHalfSizeScratchCPointSampleTexture;
  v29 = *((_QWORD *)v10 + 5);
  if ( v29 )
  {
    v30 = *(unsigned int *)(v29 + 24);
    if ( (unsigned int)v30 < 0x7E )
    {
      v31 = v29 + 16 * (v30 + 2);
      *(_DWORD *)(v29 + 24) = v30 + 1;
      goto LABEL_41;
    }
    if ( v29 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v29 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v32 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v33 = v32;
  if ( v32 )
  {
    *(_QWORD *)v32 = v32;
    *((_QWORD *)v32 + 1) = v32;
    *((_QWORD *)v32 + 2) = 0i64;
    *((_DWORD *)v32 + 6) = 0;
    v34 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v34 + 8) = v33;
    *(_QWORD *)v33 = v34;
    *((_QWORD *)v33 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v33;
    *((_QWORD *)v10 + 5) = v33;
  }
  v35 = *((_QWORD *)v10 + 5);
  if ( v35 )
  {
    *(_DWORD *)(v35 + 24) = 1;
    v31 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_41:
    if ( v31 )
    {
      *(_DWORD *)v31 = 1114114;
      *(_QWORD *)(v31 + 8) = v28;
    }
  }
  if ( v27 )
    v36 = v4->mQuarterSizeAmbientOcclusionScratchUAV;
  else
    v36 = v4->mAmbientOcclusionScratchUAV;
  v37 = *((_WORD *)v131 + 68);
  v38 = *((_QWORD *)v10 + 5);
  if ( v38 )
  {
    v39 = *(unsigned int *)(v38 + 24);
    if ( (unsigned int)v39 < 0x7E )
    {
      v40 = v38 + 16 * (v39 + 2);
      *(_DWORD *)(v38 + 24) = v39 + 1;
      goto LABEL_55;
    }
    if ( v38 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v38 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v41 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v42 = v41;
  if ( v41 )
  {
    *(_QWORD *)v41 = v41;
    *((_QWORD *)v41 + 1) = v41;
    *((_QWORD *)v41 + 2) = 0i64;
    *((_DWORD *)v41 + 6) = 0;
    v43 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v43 + 8) = v42;
    *(_QWORD *)v42 = v43;
    *((_QWORD *)v42 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v42;
    *((_QWORD *)v10 + 5) = v42;
  }
  v44 = *((_QWORD *)v10 + 5);
  if ( v44 )
  {
    *(_DWORD *)(v44 + 24) = 1;
    v40 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_55:
    if ( v40 )
    {
      *(_WORD *)v40 = 2;
      *(_WORD *)(v40 + 2) = v37;
      *(_QWORD *)(v40 + 8) = v36;
    }
  }
  v45 = (__m128)COERCE_UNSIGNED_INT((float)v6->mWidth);
  v45.m128_f32[0] = v45.m128_f32[0] * 0.0078125;
  v46 = (signed int)v45.m128_f32[0];
  if ( (signed int)v45.m128_f32[0] != 0x80000000 && (float)v46 != v45.m128_f32[0] )
    v45.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v45, v45)) & 1 ^ 1) + v46);
  v47 = (__m128)COERCE_UNSIGNED_INT((float)v6->mHeight);
  v47.m128_f32[0] = v47.m128_f32[0] * 0.5;
  v48 = (signed int)v47.m128_f32[0];
  if ( (signed int)v47.m128_f32[0] != 0x80000000 && (float)v48 != v47.m128_f32[0] )
    v47.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v47, v47)) & 1 ^ 1) + v48);
  v49 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 4u);
  v50 = v49;
  if ( v49 )
  {
    *(_DWORD *)v49 = (signed int)v45.m128_f32[0];
    *((_DWORD *)v49 + 1) = (signed int)v47.m128_f32[0];
    *((_DWORD *)v49 + 2) = 1;
  }
  else
  {
    v50 = 0i64;
  }
  v51 = *((_QWORD *)v10 + 5);
  if ( v51 )
  {
    v52 = *(unsigned int *)(v51 + 24);
    if ( (unsigned int)v52 < 0x7E )
    {
      v53 = v51 + 16 * (v52 + 2);
      *(_DWORD *)(v51 + 24) = v52 + 1;
      goto LABEL_75;
    }
    if ( v51 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v51 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v54 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v55 = v54;
  if ( v54 )
  {
    *(_QWORD *)v54 = v54;
    *((_QWORD *)v54 + 1) = v54;
    *((_QWORD *)v54 + 2) = 0i64;
    *((_DWORD *)v54 + 6) = 0;
    v56 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v56 + 8) = v55;
    *(_QWORD *)v55 = v56;
    *((_QWORD *)v55 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v55;
    *((_QWORD *)v10 + 5) = v55;
  }
  v57 = *((_QWORD *)v10 + 5);
  if ( v57 )
  {
    *(_DWORD *)(v57 + 24) = 1;
    v53 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_75:
    if ( v53 )
    {
      *(_DWORD *)v53 = 26;
      *(_QWORD *)(v53 + 8) = v50;
    }
  }
  v58 = (__int64)v131;
  v59 = *((_QWORD *)v131 + 15);
  v60 = *((_QWORD *)v10 + 5);
  if ( v60 )
  {
    v61 = *(unsigned int *)(v60 + 24);
    if ( (unsigned int)v61 < 0x7E )
    {
      v62 = v60 + 16 * (v61 + 2);
      *(_DWORD *)(v60 + 24) = v61 + 1;
      goto LABEL_86;
    }
    if ( v60 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v60 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v63 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v64 = v63;
  v131 = v63;
  if ( v63 )
  {
    *(_QWORD *)v63 = v63;
    *((_QWORD *)v63 + 1) = v63;
    *((_QWORD *)v63 + 2) = 0i64;
    *((_DWORD *)v63 + 6) = 0;
    v65 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v65 + 8) = v64;
    *(_QWORD *)v64 = v65;
    *((_QWORD *)v64 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v64;
    *((_QWORD *)v10 + 5) = v64;
  }
  v66 = *((_QWORD *)v10 + 5);
  if ( v66 )
  {
    *(_DWORD *)(v66 + 24) = 1;
    v62 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_86:
    if ( v62 )
    {
      *(_DWORD *)v62 = 1;
      *(_QWORD *)(v62 + 8) = v59;
    }
  }
  v67 = *((_QWORD *)v10 + 5);
  if ( v67 )
  {
    v68 = *(unsigned int *)(v67 + 24);
    if ( (unsigned int)v68 < 0x7E )
    {
      v69 = v67 + 16 * (v68 + 2);
      *(_DWORD *)(v67 + 24) = v68 + 1;
      goto LABEL_97;
    }
    if ( v67 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v67 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v70 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v71 = v70;
  v131 = v70;
  if ( v70 )
  {
    *(_QWORD *)v70 = v70;
    *((_QWORD *)v70 + 1) = v70;
    *((_QWORD *)v70 + 2) = 0i64;
    *((_DWORD *)v70 + 6) = 0;
    v72 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v72 + 8) = v71;
    *(_QWORD *)v71 = v72;
    *((_QWORD *)v71 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v71;
    *((_QWORD *)v10 + 5) = v71;
  }
  v73 = *((_QWORD *)v10 + 5);
  if ( v73 )
  {
    *(_DWORD *)(v73 + 24) = 1;
    v69 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_97:
    if ( v69 )
    {
      *(_DWORD *)v69 = 983042;
      *(_QWORD *)(v69 + 8) = v128;
    }
  }
  v74 = v133;
  if ( v133 )
    v75 = v4->mQuarterSizeScratchBPointSampleTexture;
  else
    v75 = v4->mHalfSizeScratchBPointSampleTexture;
  v76 = *((_QWORD *)v10 + 5);
  if ( v76 )
  {
    v77 = *(unsigned int *)(v76 + 24);
    if ( (unsigned int)v77 < 0x7E )
    {
      v78 = v76 + 16 * (v77 + 2);
      *(_DWORD *)(v76 + 24) = v77 + 1;
      goto LABEL_111;
    }
    if ( v76 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v76 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v79 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v80 = v79;
  v131 = v79;
  if ( v79 )
  {
    *(_QWORD *)v79 = v79;
    *((_QWORD *)v79 + 1) = v79;
    *((_QWORD *)v79 + 2) = 0i64;
    *((_DWORD *)v79 + 6) = 0;
    v81 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v81 + 8) = v80;
    *(_QWORD *)v80 = v81;
    *((_QWORD *)v80 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v80;
    *((_QWORD *)v10 + 5) = v80;
  }
  v82 = *((_QWORD *)v10 + 5);
  if ( v82 )
  {
    *(_DWORD *)(v82 + 24) = 1;
    v78 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_111:
    if ( v78 )
    {
      *(_DWORD *)v78 = 1114114;
      *(_QWORD *)(v78 + 8) = v75;
    }
  }
  if ( v74 )
    v83 = v4->mQuarterSizeAmbientOcclusionAliasUAV;
  else
    v83 = v4->mAmbientOcclusionAliasUAV;
  v84 = *(_WORD *)(v58 + 136);
  v85 = *((_QWORD *)v10 + 5);
  if ( v85 )
  {
    v86 = *(unsigned int *)(v85 + 24);
    if ( (unsigned int)v86 < 0x7E )
    {
      v87 = v85 + 16 * (v86 + 2);
      *(_DWORD *)(v85 + 24) = v86 + 1;
      goto LABEL_125;
    }
    if ( v85 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v85 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v88 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v89 = v88;
  v131 = v88;
  if ( v88 )
  {
    *(_QWORD *)v88 = v88;
    *((_QWORD *)v88 + 1) = v88;
    *((_QWORD *)v88 + 2) = 0i64;
    *((_DWORD *)v88 + 6) = 0;
    v90 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v90 + 8) = v89;
    *(_QWORD *)v89 = v90;
    *((_QWORD *)v89 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v89;
    *((_QWORD *)v10 + 5) = v89;
  }
  v91 = *((_QWORD *)v10 + 5);
  if ( v91 )
  {
    *(_DWORD *)(v91 + 24) = 1;
    v87 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_125:
    if ( v87 )
    {
      *(_WORD *)v87 = 2;
      *(_WORD *)(v87 + 2) = v84;
      *(_QWORD *)(v87 + 8) = v83;
    }
  }
  v92 = (__m128)COERCE_UNSIGNED_INT((float)*vp_scissor);
  v92.m128_f32[0] = v92.m128_f32[0] * 0.5;
  v93 = (signed int)v92.m128_f32[0];
  if ( (signed int)v92.m128_f32[0] != 0x80000000 && (float)v93 != v92.m128_f32[0] )
    v92.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v92, v92)) & 1 ^ 1) + v93);
  v94 = (signed int)v92.m128_f32[0];
  v95 = (__m128)COERCE_UNSIGNED_INT((float)vp_scissor[1]);
  v95.m128_f32[0] = v95.m128_f32[0] * 0.0078125;
  v96 = (signed int)v95.m128_f32[0];
  if ( (signed int)v95.m128_f32[0] != 0x80000000 && (float)v96 != v95.m128_f32[0] )
    v95.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v95, v95)) & 1 ^ 1) + v96);
  v97 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 4u);
  v98 = v97;
  v131 = v97;
  if ( v97 )
  {
    *(_DWORD *)v97 = v94;
    *((_DWORD *)v97 + 1) = (signed int)v95.m128_f32[0];
    *((_DWORD *)v97 + 2) = 1;
  }
  else
  {
    v98 = 0i64;
  }
  v99 = *((_QWORD *)v10 + 5);
  if ( v99 )
  {
    v100 = *(unsigned int *)(v99 + 24);
    if ( (unsigned int)v100 < 0x7E )
    {
      v101 = v99 + 16 * (v100 + 2);
      *(_DWORD *)(v99 + 24) = v100 + 1;
      goto LABEL_145;
    }
    if ( v99 )
    {
      *((_DWORD *)v10 + 18) += *(_DWORD *)(v99 + 24);
      *((_QWORD *)v10 + 5) = 0i64;
    }
  }
  v102 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v103 = v102;
  v131 = v102;
  if ( v102 )
  {
    *(_QWORD *)v102 = v102;
    *((_QWORD *)v102 + 1) = v102;
    *((_QWORD *)v102 + 2) = 0i64;
    *((_DWORD *)v102 + 6) = 0;
    v104 = *((_QWORD *)v10 + 2);
    *(_QWORD *)(v104 + 8) = v103;
    *(_QWORD *)v103 = v104;
    *((_QWORD *)v103 + 1) = v10 + 16;
    *((_QWORD *)v10 + 2) = v103;
    *((_QWORD *)v10 + 5) = v103;
  }
  v105 = *((_QWORD *)v10 + 5);
  if ( v105 )
  {
    *(_DWORD *)(v105 + 24) = 1;
    v101 = *((_QWORD *)v10 + 5) + 32i64;
LABEL_145:
    if ( v101 )
    {
      *(_DWORD *)v101 = 26;
      *(_QWORD *)(v101 + 8) = v98;
    }
  }
  v106 = *((_QWORD *)v10 + 5);
  if ( v106 )
  {
    *((_DWORD *)v10 + 18) += *(_DWORD *)(v106 + 24);
    *((_QWORD *)v10 + 5) = 0i64;
  }
  v107 = viewa;
  v108 = (RenderQueueLayer *)viewa->mSubmitContext[1].mStateValues.mParamValues[0];
  RenderQueueLayer::SerializeRenderQueues(v108);
  v109 = v108->mSerializationList;
  v110 = v108->mSerializationList->mNode.mPrev;
  v110->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v10;
  *(_QWORD *)v10 = v110;
  *((_QWORD *)v10 + 1) = v109;
  v109->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v10;
  if ( !v133 )
  {
    v111 = Render::View::GetStateArgs(v107);
    Render::View::BeginTarget(v107, v4->mAmbientOcclusionAliasTarget, "DropShadows", 0, 0, 0i64, 1, 0, 0, 0);
    v112 = (__int64)v107->mSettings;
    v113 = (signed __int64)&v107->mSettings->mProjection;
    *(_QWORD *)clear_on_resolve = clear_on_resolve;
    *(_QWORD *)ignore_resolve_depth = clear_on_resolve;
    *(_QWORD *)ps4_decompress_depth = 0i64;
    *(_WORD *)d3d_disable_depth_copy = Render::cbExternalViewTransformState::sStateParamIndex;
    v124 = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
    {
      v114 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v114;
      *(_WORD *)d3d_disable_depth_copy = v114;
    }
    v125 = v112;
    v126 = v113;
    v127 = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(
      v111,
      (Render::cbExternalViewTransformState *)clear_on_resolve);
    UFG::DropShadowComponent::DrawAll(v107, v4->mHalfSizeLinearDepthTarget);
    v115 = *(_QWORD *)clear_on_resolve;
    v116 = *(_QWORD **)ignore_resolve_depth;
    *(_QWORD *)(*(_QWORD *)clear_on_resolve + 8i64) = *(_QWORD *)ignore_resolve_depth;
    *v116 = v115;
    *(_QWORD *)clear_on_resolve = clear_on_resolve;
    *(_QWORD *)ignore_resolve_depth = clear_on_resolve;
    HIBYTE(v124) = 0;
    if ( (Illusion::StateArgs *)v111->mStateArgsCreateMask.mFlags[2 * (*(signed __int16 *)d3d_disable_depth_copy + 3i64)
                                                                + 1] == (Illusion::StateArgs *)((char *)v111
                                                                                              + 16
                                                                                              * (*(signed __int16 *)d3d_disable_depth_copy
                                                                                               + 3i64)) )
      v111->mStateArgsCreateMask.mFlags[(unsigned int)*(signed __int16 *)d3d_disable_depth_copy >> 6] &= ~(1i64 << (d3d_disable_depth_copy[0] & 0x3F));
    Render::View::EndTarget(v107);
    v117 = *(_QWORD *)clear_on_resolve;
    v118 = *(_QWORD **)ignore_resolve_depth;
    *(_QWORD *)(*(_QWORD *)clear_on_resolve + 8i64) = *(_QWORD *)ignore_resolve_depth;
    *v118 = v117;
  }
}                                                                                              + 16
                      

