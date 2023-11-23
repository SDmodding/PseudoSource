// File Line: 77
// RVA: 0x33B40
void __fastcall UFG::RenderStageAO::Create(UFG::RenderContext *render_context)
{
  UFG::RenderStageAO *v2; // rax

  v2 = (UFG::RenderStageAO *)UFG::qMalloc(0x90ui64, "RenderStageAO", 0i64);
  if ( v2 )
    UFG::RenderStageAO::RenderStageAO(v2, render_context);
}

// File Line: 86
// RVA: 0x33940
void __fastcall UFG::RenderStageAO::RenderStageAO(UFG::RenderStageAO *this, UFG::RenderContext *render_context)
{
  Illusion::ShaderHandle *p_mAOCSShader; // r14
  unsigned int v4; // r15d
  UFG::qResourceInventory *Inventory; // rax
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
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-98h] BYREF

  p_mAOCSShader = &this->mAOCSShader;
  UFG::qResourceHandle::qResourceHandle(&this->mAOCSShader);
  UFG::qResourceHandle::qResourceHandle(&this->mHalfResAOCSShader);
  UFG::qResourceHandle::qResourceHandle(&this->mBilateralXCSShader);
  UFG::qResourceHandle::qResourceHandle(&this->mBilateralYCSShader);
  *(_WORD *)&this->mAOBlur = 257;
  this->mAOBilateralCS = 1;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  if ( outSettings.mFeatureLevel == FEATURE_LEVEL_D3D11_0 )
  {
    v4 = UFG::qStringHash32("HK_AO_HD_CS_HALFRES", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mHalfResAOCSShader, 0x8B5561A1, v4, Inventory);
    v7 = UFG::qStringHash32("HK_AO_HD_CS_FULLRES", 0xFFFFFFFF);
    v8 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v8;
    }
    UFG::qResourceHandle::Init(p_mAOCSShader, 0x8B5561A1, v7, v8);
    this->mAOCSUAVParamIndex = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "AO_Output");
    v10 = UFG::qStringHash32("BILATERALBLURAMD_CS_X", 0xFFFFFFFF);
    v11 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v11;
    }
    UFG::qResourceHandle::Init(&this->mBilateralXCSShader, 0x8B5561A1, v10, v11);
    v13 = UFG::qStringHash32("BILATERALBLURAMD_CS_Y", 0xFFFFFFFF);
    v14 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v15 = UFG::qResourceWarehouse::Instance();
      v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v14;
    }
    UFG::qResourceHandle::Init(&this->mBilateralYCSShader, 0x8B5561A1, v13, v14);
  }
}

// File Line: 133
// RVA: 0x33B90
UFG::qVector3 *__fastcall UFG::RenderStageAO::EvaluateSphericalHarmonic(
        UFG::qVector3 *result,
        UFG::qVector3 *normal,
        CB_SphericalHarmonic *sh)
{
  float x; // xmm11_4
  float z; // xmm10_4
  float v5; // xmm8_4
  float y; // xmm13_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm9_4
  float v11; // xmm12_4
  UFG::qVector3 *v12; // rax

  x = normal->x;
  z = normal->z;
  v5 = normal->x * z;
  y = normal->y;
  v7 = normal->x * y;
  v8 = (float)(x * x) * sh->GreenIrradianceConst[0][0];
  v9 = v5 * sh->GreenIrradianceConst[1][1];
  v10 = (float)(x * x) * sh->BlueIrradianceConst[0][0];
  result->x = (float)((float)((float)((float)((float)((float)(y * y) * sh->RedIrradianceConst[0][1])
                                            + (float)((float)(normal->x * normal->x) * sh->RedIrradianceConst[0][0]))
                                    + (float)((float)(z * z) * sh->RedIrradianceConst[0][2]))
                            + sh->IrradianceConst[0])
                    + (float)((float)((float)(v5 * sh->RedIrradianceConst[1][1])
                                    + (float)(v7 * sh->RedIrradianceConst[1][0]))
                            + (float)((float)(y * z) * sh->RedIrradianceConst[1][2])))
            + (float)((float)((float)(y * sh->RedIrradianceConst[2][1])
                            + (float)(normal->x * sh->RedIrradianceConst[2][0]))
                    + (float)(z * sh->RedIrradianceConst[2][2]));
  v11 = (float)(y * y) * sh->BlueIrradianceConst[0][1];
  result->y = (float)((float)((float)((float)((float)((float)(y * y) * sh->GreenIrradianceConst[0][1]) + v8)
                                    + (float)((float)(z * z) * sh->GreenIrradianceConst[0][2]))
                            + sh->IrradianceConst[1])
                    + (float)((float)(v9 + (float)(v7 * sh->GreenIrradianceConst[1][0]))
                            + (float)((float)(y * z) * sh->GreenIrradianceConst[1][2])))
            + (float)((float)((float)(y * sh->GreenIrradianceConst[2][1]) + (float)(x * sh->GreenIrradianceConst[2][0]))
                    + (float)(z * sh->GreenIrradianceConst[2][2]));
  v12 = result;
  result->z = (float)((float)((float)((float)(v11 + v10) + (float)((float)(z * z) * sh->BlueIrradianceConst[0][2]))
                            + sh->IrradianceConst[2])
                    + (float)((float)((float)(v5 * sh->BlueIrradianceConst[1][1])
                                    + (float)(v7 * sh->BlueIrradianceConst[1][0]))
                            + (float)((float)(y * z) * sh->BlueIrradianceConst[1][2])))
            + (float)((float)((float)(y * sh->BlueIrradianceConst[2][1]) + (float)(x * sh->BlueIrradianceConst[2][0]))
                    + (float)(z * sh->BlueIrradianceConst[2][2]));
  return v12;
}

// File Line: 161
// RVA: 0x33DC0
void __fastcall UFG::GetSHFromCulledLights(
        UFG::qMatrix44 *local_world,
        Render::SphericalHarmonic *sh,
        const int max_lights,
        float luminance_threshold,
        float radius_boost)
{
  UFG::qVector4 *v6; // r13
  unsigned int v7; // edi
  int v9; // ebx
  unsigned int v10; // ebp
  unsigned int v11; // r15d
  __int64 v12; // rsi
  UFG::qMatrix44 d; // [rsp+30h] [rbp-88h] BYREF

  v6 = &local_world->v3;
  v7 = 0;
  v9 = 0;
  UFG::qInverseAffine(&d, local_world);
  v10 = 0;
  v11 = gNumNearLights + gNumStencilLights + gNumFarLights;
  if ( v11 )
  {
    v12 = 0i64;
    while ( 1 )
    {
      if ( (gCulledLights[v12].flags & 1) == 0 )
      {
        if ( Render::AddLightContributionToHarmonic(
               sh,
               gLights[gCulledLights[v12].lightIndex],
               (UFG::qVector3 *)v6,
               &d,
               luminance_threshold,
               radius_boost) )
        {
          if ( ++v9 == max_lights )
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
    if ( gSpotShadowCount )
    {
      do
      {
        if ( Render::AddLightContributionToHarmonic(
               sh,
               gLights[gCulledLights[gSpotShadowIndices[v7]].lightIndex],
               (UFG::qVector3 *)v6,
               &d,
               luminance_threshold,
               radius_boost) )
        {
          if ( ++v9 == max_lights )
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
void __fastcall UFG::RenderStageAO::GetSignificantLightDirection(
        UFG::qMatrix44 *matLocalWorld,
        UFG::qMatrix44 *matLocalWorldInv,
        CB_EnvironmentSettings *envState,
        bool bUseDirectional,
        __int64 lightRadiusBoost)
{
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  __int128 v21; // xmm7
  float v22; // xmm3_4
  float v23; // xmm6_4
  __m128 v24; // xmm2
  float v25; // xmm1_4
  float v26; // xmm6_4
  float v27; // xmm9_4
  UFG::qVector3 *v28; // rax
  float v29; // xmm4_4
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // xmm14_4
  __m128 v33; // xmm2
  float v34; // xmm3_4
  UFG::qVector3 *v35; // rax
  float v36; // xmm12_4
  float v37; // xmm11_4
  float v38; // xmm13_4
  float v39; // xmm11_4
  float v40; // xmm13_4
  float v41; // xmm12_4
  float v42; // xmm14_4
  int v43; // xmm14_4
  float v44; // xmm3_4
  __m128 v45; // xmm2
  float v46; // xmm2_4
  UFG::qVector3 *v47; // rax
  __m128 v48; // xmm3
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm12_4
  float v52; // xmm11_4
  float v53; // xmm13_4
  __m128 v54; // xmm2
  float v55; // xmm2_4
  UFG::qVector3 *v56; // rax
  float v57; // xmm14_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm12_4
  float v61; // xmm11_4
  float v62; // xmm13_4
  float v63; // xmm2_4
  float v64; // xmm10_4
  UFG::qVector3 *v65; // rax
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm12_4
  float v69; // xmm11_4
  float v70; // xmm13_4
  float v71; // xmm2_4
  float v72; // xmm3_4
  float v73; // xmm1_4
  float v74; // xmm7_4
  float v75; // xmm2_4
  float v76; // xmm6_4
  float v77; // xmm1_4
  UFG::qVector3 direction; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qColour colour; // [rsp+40h] [rbp-A8h] BYREF
  Render::SphericalHarmonic sh; // [rsp+50h] [rbp-98h] BYREF
  float irr_const[12]; // [rsp+168h] [rbp+80h] BYREF
  float v82[54]; // [rsp+198h] [rbp+B0h] BYREF
  float v83; // [rsp+278h] [rbp+190h]
  float radius_boost; // [rsp+298h] [rbp+1B0h]
  float v85; // [rsp+2A0h] [rbp+1B8h]
  __int64 v86; // [rsp+2A8h] [rbp+1C0h]

  Render::SphericalHarmonic::SphericalHarmonic(&sh);
  UFG::GetSHFromCulledLights(matLocalWorld, &sh, 16, s_fLumThresh, radius_boost);
  if ( bUseDirectional )
  {
    v9 = envState->SunDirWorld[1];
    v10 = envState->SunDirWorld[2];
    v11 = envState->SunDirWorld[0];
    v12 = v11 * matLocalWorldInv->v0.z;
    colour.a = 1.0;
    v13 = v11 * matLocalWorldInv->v0.y;
    v14 = (float)(v9 * matLocalWorldInv->v1.x) + (float)(v11 * matLocalWorldInv->v0.x);
    v15 = v9 * matLocalWorldInv->v1.y;
    v16 = v9 * matLocalWorldInv->v1.z;
    direction.x = v14 + (float)(v10 * matLocalWorldInv->v2.x);
    v17 = envState->SunColor[1] * v85;
    v18 = (float)(v12 + v16) + (float)(v10 * matLocalWorldInv->v2.z);
    v19 = envState->SunColor[0] * v85;
    direction.y = (float)(v13 + v15) + (float)(v10 * matLocalWorldInv->v2.y);
    v20 = envState->SunColor[2];
    direction.z = v18;
    colour.r = v19;
    colour.g = v17;
    colour.b = v20 * v85;
    Render::SphericalHarmonic::EvalDirectionalLight(&sh, &direction, &colour);
  }
  v21 = LODWORD(sh.mRedCoefficients[1]);
  *(float *)&v21 = (float)(sh.mRedCoefficients[1] + sh.mGreenCoefficients[1]) + sh.mGreenCoefficients[4];
  v22 = (float)(sh.mRedCoefficients[3] + sh.mRedCoefficients[6]) + sh.mGreenCoefficients[6];
  v23 = (float)(sh.mRedCoefficients[2] + sh.mGreenCoefficients[2]) + sh.mGreenCoefficients[5];
  v24 = (__m128)v21;
  v24.m128_f32[0] = (float)((float)(*(float *)&v21 * *(float *)&v21) + (float)(v22 * v22)) + (float)(v23 * v23);
  if ( v24.m128_f32[0] <= 0.000001 )
  {
    v27 = 0.0;
    v21 = 0i64;
    v26 = *(float *)&FLOAT_1_0;
  }
  else
  {
    if ( v24.m128_f32[0] == 0.0 )
      v25 = 0.0;
    else
      v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
    *(float *)&v21 = *(float *)&v21 * v25;
    v26 = v23 * v25;
    v27 = v25 * v22;
  }
  direction.z = v26;
  LODWORD(direction.y) = v21;
  direction.x = v27;
  Render::SphericalHarmonic::ComputeIrradianceConstants(
    &sh,
    (float *)&sh.mHelperLight[13],
    (float *)&sh.mHelperLight[15],
    sh.mRedCoefficients);
  Render::SphericalHarmonic::ComputeIrradianceConstants(
    &sh,
    (float *)&sh.mHelperLight[13] + 1,
    irr_const,
    sh.mGreenCoefficients);
  Render::SphericalHarmonic::ComputeIrradianceConstants(
    &sh,
    (float *)&sh.mHelperLight[14],
    v82,
    &sh.mGreenCoefficients[3]);
  v28 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v33 = (__m128)v21;
  v29 = v27 + colorSamplingOffset;
  y = v28->y;
  z = v28->z;
  x = v28->x;
  *(_DWORD *)(lightRadiusBoost + 12) = 1065353216;
  *(float *)(lightRadiusBoost + 4) = y;
  v83 = z;
  *(float *)(lightRadiusBoost + 8) = z;
  *(float *)lightRadiusBoost = x;
  v33.m128_f32[0] = (float)((float)(*(float *)&v21 * *(float *)&v21) + (float)(v29 * v29)) + (float)(v26 * v26);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
  direction.x = v29 * v34;
  direction.y = *(float *)&v21 * v34;
  direction.z = v26 * v34;
  v35 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v45 = (__m128)v21;
  v36 = v35->x;
  v37 = v35->y;
  v38 = v35->z;
  *(_DWORD *)(lightRadiusBoost + 12) = 0x40000000;
  v39 = v37 + y;
  v40 = v38 + v83;
  v41 = v36 + x;
  v42 = colorSamplingOffset;
  *(float *)lightRadiusBoost = v41;
  *(float *)(lightRadiusBoost + 4) = v39;
  v43 = LODWORD(v42) ^ _xmm[0];
  *(float *)(lightRadiusBoost + 8) = v40;
  v44 = *(float *)&v43 + v27;
  v45.m128_f32[0] = (float)((float)(*(float *)&v21 * *(float *)&v21) + (float)(v44 * v44)) + (float)(v26 * v26);
  if ( v45.m128_f32[0] == 0.0 )
    v46 = 0.0;
  else
    v46 = 1.0 / _mm_sqrt_ps(v45).m128_f32[0];
  direction.x = v44 * v46;
  direction.y = *(float *)&v21 * v46;
  direction.z = v26 * v46;
  v47 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v48 = (__m128)v21;
  v48.m128_f32[0] = *(float *)&v21 + colorSamplingOffset;
  v49 = v47->y;
  v50 = v47->z;
  v51 = v41 + v47->x;
  v54 = v48;
  *(_DWORD *)(lightRadiusBoost + 12) = 1077936128;
  v52 = v39 + v49;
  v53 = v40 + v50;
  *(float *)lightRadiusBoost = v51;
  *(float *)(lightRadiusBoost + 4) = v52;
  *(float *)(lightRadiusBoost + 8) = v53;
  v54.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v27 * v27)) + (float)(v26 * v26);
  if ( v54.m128_f32[0] == 0.0 )
    v55 = 0.0;
  else
    v55 = 1.0 / _mm_sqrt_ps(v54).m128_f32[0];
  direction.y = v48.m128_f32[0] * v55;
  direction.x = v27 * v55;
  direction.z = v26 * v55;
  v56 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v57 = *(float *)&v43 + *(float *)&v21;
  v58 = v56->y;
  v59 = v56->z;
  v60 = v51 + v56->x;
  *(_DWORD *)(lightRadiusBoost + 12) = 1082130432;
  v61 = v52 + v58;
  v62 = v53 + v59;
  *(float *)lightRadiusBoost = v60;
  *(float *)(lightRadiusBoost + 4) = v61;
  *(float *)(lightRadiusBoost + 8) = v62;
  v63 = (float)((float)(v57 * v57) + (float)(v27 * v27)) + (float)(v26 * v26);
  if ( v63 == 0.0 )
    v64 = 0.0;
  else
    v64 = 1.0 / fsqrt(v63);
  direction.y = v57 * v64;
  direction.x = v27 * v64;
  direction.z = v26 * v64;
  v65 = UFG::RenderStageAO::EvaluateSphericalHarmonic(
          (UFG::qVector3 *)&colour,
          &direction,
          (CB_SphericalHarmonic *)&sh.mHelperLight[13]);
  v66 = v65->y;
  v67 = v65->z;
  v68 = (float)(v60 + v65->x) * 0.2;
  *(float *)lightRadiusBoost = v68;
  v69 = (float)(v61 + v66) * 0.2;
  v70 = (float)(v62 + v67) * 0.2;
  *(float *)(lightRadiusBoost + 4) = v69;
  *(float *)(lightRadiusBoost + 8) = v70;
  LODWORD(v71) = v21 ^ _xmm[0];
  *(float *)(lightRadiusBoost + 12) = (float)((float)(v69 * 0.5) + (float)(v68 * 0.30000001)) + (float)(v70 * 0.2);
  v72 = (float)((float)(COERCE_FLOAT(v21 ^ _xmm[0]) * matLocalWorld->v1.x)
              + (float)(COERCE_FLOAT(LODWORD(v27) ^ _xmm[0]) * matLocalWorld->v0.x))
      + (float)(v26 * matLocalWorld->v2.x);
  v73 = v26;
  v74 = (float)(COERCE_FLOAT(v21 ^ _xmm[0]) * matLocalWorld->v1.z)
      + (float)(COERCE_FLOAT(LODWORD(v27) ^ _xmm[0]) * matLocalWorld->v0.z);
  v75 = (float)(v71 * matLocalWorld->v1.y) + (float)(COERCE_FLOAT(LODWORD(v27) ^ _xmm[0]) * matLocalWorld->v0.y);
  v76 = v26 * matLocalWorld->v2.z;
  v77 = v73 * matLocalWorld->v2.y;
  *(float *)v86 = v72;
  *(_DWORD *)(v86 + 12) = 0;
  *(float *)(v86 + 8) = v74 + v76;
  *(float *)(v86 + 4) = v75 + v77;
}

// File Line: 270
// RVA: 0x1454600
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURX__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURX", -1);
  uidBILATERALBLURX = result;
  return result;
}

// File Line: 271
// RVA: 0x1454620
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURX_NOSUN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURX_NOSUN", -1);
  uidBILATERALBLURX_NOSUN = result;
  return result;
}

// File Line: 272
// RVA: 0x1454640
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURY__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURY", -1);
  uidBILATERALBLURY = result;
  return result;
}

// File Line: 273
// RVA: 0x1454660
__int64 UFG::_dynamic_initializer_for__uidBILATERALBLURY_NOSUN__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("BILATERALBLURY_NOSUN", -1);
  uidBILATERALBLURY_NOSUN = result;
  return result;
}

// File Line: 276
// RVA: 0x35370
void __fastcall UFG::RenderStageAO::RenderAmbientOcclusion(
        UFG::RenderStageAO *this,
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  Illusion::StateArgs *StateArgs; // r14
  float mAOOpacity; // xmm1_4
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v10; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rax
  Illusion::RenderQueue *v12; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v13; // rcx
  Illusion::RenderQueue *v14; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v15; // rcx
  UFG::RenderContext *v16; // rdx
  UFG::RenderStageAO *v17; // rcx
  Render::ViewSettings *mSettings; // rbx
  UFG::qMatrix44 *p_mProjection; // r15
  unsigned __int16 Param; // ax
  float *mShadowFilterWidth; // rbx
  float *mBiases; // r15
  float *mCutplanes; // r12
  unsigned __int16 v24; // ax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v27; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rax
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-B0h] BYREF
  Render::cbShadowTransformState v36; // [rsp+90h] [rbp-70h] BYREF
  __int64 v37; // [rsp+F0h] [rbp-10h]
  Render::View view; // [rsp+100h] [rbp+0h] BYREF
  RenderQueueLayer v39; // [rsp+290h] [rbp+190h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+370h] [rbp+270h] BYREF
  LayerSubmitContext ptr; // [rsp+570h] [rbp+470h] BYREF

  v37 = -2i64;
  if ( !render_context->mRenderFeatures.mWorld )
    return;
  RenderQueueLayer::RenderQueueLayer(&v39);
  LayerSubmitContext::LayerSubmitContext(&ptr);
  v39.mSerializationList = serialization_list;
  ptr.mQueueMode = QM_Single;
  ptr.mRenderQueueProvider = &v39;
  Render::View::View(&view, &render_context->mMainViewSettings, &ptr);
  StateArgs = Render::View::GetStateArgs(&view);
  if ( !render_context->mRenderFeatures.mAO )
  {
    Render::View::BeginTarget(
      &view,
      render_context->mAmbientOcclusionAliasTarget,
      "AmbientOcclusionNone",
      0,
      0,
      0i64,
      0,
      0,
      0,
      0);
    Render::View::Clear(&view, &UFG::qColour::White, 1u, 1.0, 1u);
    Render::View::EndTarget(&view);
    goto LABEL_23;
  }
  mAOOpacity = render_context->mAOOpacity;
  if ( mAOOpacity < 0.0 )
    LODWORD(mAOOpacity) ^= _xmm[0];
  if ( mAOOpacity < 0.001 )
  {
    Render::View::BeginTarget(
      &view,
      render_context->mAmbientOcclusionAliasTarget,
      "DropShadows",
      0,
      0,
      0i64,
      0,
      0,
      0,
      0);
    Render::View::Clear(&view, &UFG::qColour::White, 1u, 1.0, 1u);
    Render::cbExternalViewTransformState::cbExternalViewTransformState(
      &arg,
      &view.mSettings->mWorldView,
      &view.mSettings->mProjection);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
    UFG::DropShadowComponent::DrawAll(&view, render_context->mHalfSizeLinearDepthTarget);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    Render::View::EndTarget(&view);
    v10 = arg.mPrev;
    v11 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v11->mPrev = v10;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    goto LABEL_23;
  }
  if ( render_context->mRenderSettingsForFrame.mFeatureLevel != FEATURE_LEVEL_D3D11_0
    || render_context->mRenderSettingsForFrame.mSSAO != SSAO_HIGH
    || !render_context->mQuarterSizeAmbientOcclusionTarget
    || !this->mHDAOCS )
  {
    UFG::RenderStageAO::RenderAmbientOcclusionPS(this, render_context, &view);
    if ( !this->mAOBlur )
      goto LABEL_23;
    v16 = render_context;
    v17 = this;
LABEL_21:
    UFG::RenderStageAO::RenderAOBilateralBlurPS(v17, v16, &view);
    goto LABEL_23;
  }
  v12 = UFG::RenderStageAO::RenderAmbientOcclusionCS(this, render_context, 1);
  v13 = serialization_list->mNode.mPrev;
  v13->mNext = v12;
  v12->mPrev = v13;
  v12->mNext = &serialization_list->mNode;
  serialization_list->mNode.mPrev = v12;
  if ( this->mAOBlur && this->mAOBilateralCS )
    UFG::RenderStageAO::RenderAOBilateralBlurCS(this, render_context, &view, 1);
  v14 = UFG::RenderStageAO::RenderAmbientOcclusionCS(this, render_context, 0);
  v15 = serialization_list->mNode.mPrev;
  v15->mNext = v14;
  v14->mPrev = v15;
  v14->mNext = &serialization_list->mNode;
  serialization_list->mNode.mPrev = v14;
  if ( !this->mAOBlur )
    goto LABEL_23;
  v16 = render_context;
  v17 = this;
  if ( !this->mAOBilateralCS )
    goto LABEL_21;
  UFG::RenderStageAO::RenderAOBilateralBlurCS(this, render_context, &view, 0);
LABEL_23:
  Render::View::BeginTarget(&view, render_context->mSkyOcclusionAliasTarget, "SkyOcclusion", 0, 0, 0i64, 0, 1, 0, 0);
  Render::View::Clear(&view, &UFG::qColour::White, 1u, 1.0, 1u);
  mSettings = view.mSettings;
  p_mProjection = &view.mSettings->mProjection;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  arg.mWorldView = &mSettings->mWorldView;
  arg.mProjection = p_mProjection;
  arg.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  mBiases = UFG::RenderWorld::msStageShadow->mBiases;
  mCutplanes = UFG::RenderWorld::msStageShadow->mCutplanes;
  v36.mPrev = &v36;
  v36.mNext = &v36;
  v36.mCallback = 0i64;
  v36.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&v36.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v24;
    v36.mStateParamIndex = v24;
  }
  v36.mViewWorld = &view.mViewWorld;
  v36.mWorldView = (UFG::qMatrix44 *)&views;
  v36.mProjection = views.mProjection;
  v36.mCutplanes = mCutplanes;
  v36.mBiases = mBiases;
  v36.mBlurWidths = mShadowFilterWidth;
  v36.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v36);
  mEnvState = render_context->mEnvState;
  StateValues = Render::View::GetStateValues(&view);
  StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  StateValues->mParamValues[55] = mEnvState;
  if ( gEnableSkyIrradianceVolumes )
    DrawIrradianceVolumes(render_context, &view, render_context->mAmbientOcclusionVolumesType);
  v27 = arg.mPrev;
  v28 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v28->mPrev = v27;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v29 = v36.mPrev;
  v30 = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  v30->mPrev = v29;
  v36.mPrev = &v36;
  v36.mNext = &v36;
  v36.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v36.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v36.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v36.mStateParamIndex >> 6] &= ~(1i64 << (v36.mStateParamIndex & 0x3F));
  Render::View::EndTarget(&view);
  v31 = v36.mPrev;
  v32 = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  v32->mPrev = v31;
  v36.mPrev = &v36;
  v36.mNext = &v36;
  v33 = arg.mPrev;
  v34 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v34->mPrev = v33;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  RenderQueueLayer::SerializeRenderQueues(&v39);
  `eh vector destructor iterator(
    ptr.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  RenderQueueLayer::~RenderQueueLayer(&v39);
}

// File Line: 386
// RVA: 0x36140
void __fastcall UFG::RenderStageAO::RenderAmbientOcclusionPS(
        UFG::RenderStageAO *this,
        UFG::RenderContext *render_context,
        Render::View *view)
{
  Illusion::StateArgs *StateArgs; // r14
  float *mShadowFilterWidth; // rbx
  float *mBiases; // r15
  float *mCutplanes; // r12
  unsigned __int16 Param; // ax
  char *v10; // rbx
  Render::ViewSettings *mSettings; // r15
  UFG::qMatrix44 *p_mProjection; // r12
  unsigned __int16 v13; // ax
  Illusion::StateValues *StateValues; // rax
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *v16; // rax
  char v17; // r15
  UFG::TimeOfDayManager *Instance; // rax
  bool IsSunShining; // r12
  char *v20; // rax
  float *v21; // rbx
  CB_EnvironmentSettings *v22; // rdx
  char *v23; // r8
  __int64 v24; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float x; // xmm4_4
  float v38; // xmm8_4
  float v39; // xmm5_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm8_4
  Illusion::StateValues *v45; // rax
  Illusion::Material *mSSAOHighMaterial; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  __int64 v49; // rcx
  UFG::qMatrix44 *mWorldView; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rax
  __int64 v53; // rcx
  UFG::qMatrix44 *v54; // rax
  __int64 dest_mip_level; // [rsp+20h] [rbp-B8h]
  Render::cbExternalViewTransformState arg; // [rsp+50h] [rbp-88h] BYREF
  UFG::qMatrix44 *p_mViewWorld; // [rsp+88h] [rbp-50h]
  UFG::RenderStageShadow::LinearCascadeViews *p_views; // [rsp+90h] [rbp-48h]
  UFG::qMatrix44 *mProjection; // [rsp+98h] [rbp-40h]
  float *v60; // [rsp+A0h] [rbp-38h]
  float *v61; // [rsp+A8h] [rbp-30h]
  float *v62; // [rsp+B0h] [rbp-28h]
  __int64 v63; // [rsp+B8h] [rbp-20h]
  UFG::qVector4 outLightDirWorld; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 m; // [rsp+D8h] [rbp+0h] BYREF
  __int64 v66; // [rsp+118h] [rbp+40h]
  UFG::qMatrix44 d; // [rsp+138h] [rbp+60h] BYREF
  UFG::RenderStageShadow::LinearCascadeViews views; // [rsp+178h] [rbp+A0h] BYREF
  Render::Poly poly; // [rsp+3E0h] [rbp+308h] BYREF

  v66 = -2i64;
  StateArgs = Render::View::GetStateArgs(view);
  UFG::RenderStageShadow::GetLinearCascadeViews(UFG::RenderWorld::msStageShadow, &views);
  mShadowFilterWidth = UFG::RenderWorld::msStageShadow->mShadowFilterWidth;
  mBiases = UFG::RenderWorld::msStageShadow->mBiases;
  mCutplanes = UFG::RenderWorld::msStageShadow->mCutplanes;
  *(_QWORD *)&arg.mStateParamIndex = &arg.mStateParamIndex;
  arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
  arg.mProjection = 0i64;
  LOWORD(arg.mCached_Remote.m_Stream) = Render::cbShadowTransformState::sStateParamIndex;
  WORD1(arg.mCached_Remote.m_Stream) = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = Param;
    LOWORD(arg.mCached_Remote.m_Stream) = Param;
  }
  p_mViewWorld = &view->mViewWorld;
  p_views = &views;
  mProjection = views.mProjection;
  v60 = mCutplanes;
  v61 = mBiases;
  v62 = mShadowFilterWidth;
  v63 = 0i64;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  *(float *)v10 = render_context->mAOOpacity;
  Render::View::BeginTarget(
    view,
    render_context->mAmbientOcclusionAliasTarget,
    "AmbientOcclusion",
    0,
    0,
    0i64,
    0,
    0,
    0,
    0);
  mSettings = view->mSettings;
  p_mProjection = &view->mSettings->mProjection;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v13;
    arg.mStateParamIndex = v13;
  }
  arg.mWorldView = &mSettings->mWorldView;
  arg.mProjection = p_mProjection;
  arg.mNext = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(
    StateArgs,
    (Render::cbShadowTransformState *)&arg.mStateParamIndex);
  StateValues = Render::View::GetStateValues(view);
  StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
  StateValues->mParamValues[15] = v10;
  mEnvState = render_context->mEnvState;
  v16 = Render::View::GetStateValues(view);
  v16->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  v16->mParamValues[55] = mEnvState;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  if ( UFG::RenderWorld::msIsNisPlaying || UFG::RenderWorld::msStageHairSkin->mEnableSSSOutsideNIS )
  {
    v17 = 1;
    Instance = UFG::TimeOfDayManager::GetInstance();
    IsSunShining = UFG::TimeOfDayManager::IsSunShining(Instance, render_context->mEnvState);
    v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x100u, 0x10u);
    v21 = (float *)v20;
    v22 = render_context->mEnvState;
    v23 = v20;
    if ( (((unsigned __int8)v20 | (unsigned __int8)v22) & 0xF) != 0 )
    {
      memmove(v20, v22, 0x100ui64);
    }
    else
    {
      v24 = 2i64;
      do
      {
        *(_OWORD *)v23 = *(_OWORD *)v22->SunDir;
        *((_OWORD *)v23 + 1) = *(_OWORD *)v22->SunDirWorld;
        *((_OWORD *)v23 + 2) = *(_OWORD *)v22->SunColor;
        *((_OWORD *)v23 + 3) = *(_OWORD *)v22->AmbientColorHorizon;
        *((_OWORD *)v23 + 4) = *(_OWORD *)v22->ScaleAndHeight;
        *((_OWORD *)v23 + 5) = *(_OWORD *)v22->ScatterZenithColor;
        *((_OWORD *)v23 + 6) = *(_OWORD *)v22->ScatterHorizonColor;
        v23 += 128;
        *((_OWORD *)v23 - 1) = *(_OWORD *)v22->ScatterGroundColor;
        v22 = (CB_EnvironmentSettings *)((char *)v22 + 128);
        --v24;
      }
      while ( v24 );
    }
    y = view->mViewWorld.v0.y;
    z = view->mViewWorld.v0.z;
    w = view->mViewWorld.v0.w;
    m.v0.x = view->mViewWorld.v0.x;
    m.v0.y = y;
    m.v0.z = z;
    m.v0.w = w;
    v28 = view->mViewWorld.v1.y;
    v29 = view->mViewWorld.v1.z;
    v30 = view->mViewWorld.v1.w;
    m.v1.x = view->mViewWorld.v1.x;
    m.v1.y = v28;
    m.v1.z = v29;
    m.v1.w = v30;
    v31 = view->mViewWorld.v2.y;
    v32 = view->mViewWorld.v2.z;
    v33 = view->mViewWorld.v2.w;
    m.v2.x = view->mViewWorld.v2.x;
    m.v2.y = v31;
    m.v2.z = v32;
    m.v2.w = v33;
    v34 = view->mViewWorld.v3.y - v31;
    v35 = view->mViewWorld.v3.z - v32;
    v36 = view->mViewWorld.v3.w - v33;
    m.v3.x = view->mViewWorld.v3.x - m.v2.x;
    m.v3.y = v34;
    m.v3.z = v35;
    m.v3.w = v36;
    UFG::qInverseAffine(&d, &m);
    *(float *)&dest_mip_level = FLOAT_2_0;
    UFG::RenderStageAO::GetSignificantLightDirection(&m, &d, render_context->mEnvState, IsSunShining, dest_mip_level);
    x = outLightDirWorld.x;
    v21[4] = outLightDirWorld.x;
    v38 = outLightDirWorld.y;
    v21[5] = outLightDirWorld.y;
    v39 = outLightDirWorld.z;
    v21[6] = outLightDirWorld.z;
    v40 = outLightDirWorld.w;
    v21[7] = outLightDirWorld.w;
    v41 = (float)((float)((float)(v38 * view->mSettings->mWorldView.v1.x) + (float)(x * view->mSettings->mWorldView.v0.x))
                + (float)(v39 * view->mSettings->mWorldView.v2.x))
        + (float)(v40 * view->mSettings->mWorldView.v3.x);
    v42 = (float)((float)((float)(v38 * view->mSettings->mWorldView.v1.y) + (float)(x * view->mSettings->mWorldView.v0.y))
                + (float)(v39 * view->mSettings->mWorldView.v2.y))
        + (float)(v40 * view->mSettings->mWorldView.v3.y);
    v43 = (float)((float)((float)(v38 * view->mSettings->mWorldView.v1.z) + (float)(x * view->mSettings->mWorldView.v0.z))
                + (float)(v39 * view->mSettings->mWorldView.v2.z))
        + (float)(v40 * view->mSettings->mWorldView.v3.z);
    v44 = (float)((float)((float)(v38 * view->mSettings->mWorldView.v1.w) + (float)(x * view->mSettings->mWorldView.v0.w))
                + (float)(v39 * view->mSettings->mWorldView.v2.w))
        + (float)(v40 * view->mSettings->mWorldView.v3.w);
    *v21 = v41;
    v21[1] = v42;
    v21[2] = v43;
    v21[3] = v44;
    v45 = Render::View::GetStateValues(view);
    v45->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v45->mParamValues[55] = v21;
  }
  else
  {
    v17 = 0;
  }
  if ( render_context->mRenderSettingsForFrame.mSSAO == SSAO_HIGH )
  {
    mSSAOHighMaterial = render_context->mSSAOHighMaterial;
  }
  else if ( v17 )
  {
    mSSAOHighMaterial = render_context->mSSAONISMaterial;
  }
  else
  {
    mSSAOHighMaterial = render_context->mSSAOMaterial;
  }
  Render::View::Draw(view, &poly, mSSAOHighMaterial, 0i64);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v49 = *(_QWORD *)&arg.mStateParamIndex;
  mWorldView = arg.mWorldView;
  *(_QWORD *)(*(_QWORD *)&arg.mStateParamIndex + 8i64) = arg.mWorldView;
  *(_QWORD *)&mWorldView->v0.x = v49;
  *(_QWORD *)&arg.mStateParamIndex = &arg.mStateParamIndex;
  arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
  BYTE3(arg.mCached_Remote.m_Stream) = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(arg.mCached_Remote.m_Stream)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(arg.mCached_Remote.m_Stream)] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(arg.mCached_Remote.m_Stream) >> 6] &= ~(1i64 << ((__int64)arg.mCached_Remote.m_Stream & 0x3F));
  Render::View::EndTarget(view);
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
void __fastcall UFG::RenderStageAO::RenderAOBilateralBlurPS(
        UFG::RenderStageAO *this,
        UFG::RenderContext *render_context,
        Render::View *view)
{
  Illusion::StateArgs *StateArgs; // r15
  _WORD *v6; // rbx
  Illusion::Target *mHalfSizeScratchTargetB; // r8
  Illusion::Target *mAmbientOcclusionAliasTarget; // rdx
  unsigned int v9; // r9d
  Render::ViewSettings *mSettings; // rdi
  UFG::qMatrix44 *p_mProjection; // r12
  unsigned __int16 Param; // ax
  Illusion::Material *mMaterial; // rdi
  __int64 v14; // rax
  _WORD *v15; // rax
  __int64 mOffset; // rax
  unsigned int mUID; // r8d
  __int64 v18; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v21; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  Render::cbExternalViewTransformState clearOnResolve; // [rsp+30h] [rbp-1h] BYREF
  Render::Poly poly; // [rsp+A0h] [rbp+6Fh] BYREF

  StateArgs = Render::View::GetStateArgs(view);
  Render::gRenderUtilities.mSubmitContext = view->mSubmitContext;
  v6 = 0i64;
  mHalfSizeScratchTargetB = render_context->mHalfSizeScratchTargetB;
  mAmbientOcclusionAliasTarget = render_context->mAmbientOcclusionAliasTarget;
  clearOnResolve.mNext = 0i64;
  LOBYTE(clearOnResolve.mPrev) = 1;
  v9 = uidBILATERALBLURX;
  if ( !render_context->mRenderSun )
    v9 = uidBILATERALBLURX_NOSUN;
  Render::RenderUtilities::Blit(
    &Render::gRenderUtilities,
    mAmbientOcclusionAliasTarget,
    mHalfSizeScratchTargetB,
    v9,
    "AO Blur X",
    0,
    (bool)clearOnResolve.mPrev,
    (UFG::qVector4 *)clearOnResolve.mNext);
  Render::gRenderUtilities.mSubmitContext = 0i64;
  Render::View::BeginTarget(
    view,
    render_context->mAmbientOcclusionAliasTarget,
    "AO Blur Y/ Blobs",
    0,
    0,
    0i64,
    1,
    0,
    0,
    0);
  mSettings = view->mSettings;
  p_mProjection = &view->mSettings->mProjection;
  clearOnResolve.mPrev = &clearOnResolve;
  clearOnResolve.mNext = &clearOnResolve;
  clearOnResolve.mCallback = 0i64;
  clearOnResolve.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&clearOnResolve.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = Param;
    clearOnResolve.mStateParamIndex = Param;
  }
  clearOnResolve.mWorldView = &mSettings->mWorldView;
  clearOnResolve.mProjection = p_mProjection;
  clearOnResolve.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &clearOnResolve);
  mMaterial = Render::gRenderUtilities.mMaterial;
  if ( !render_context->mRenderSun )
  {
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == uidBILATERALBLURY_NOSUN )
      goto LABEL_14;
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
      Render::gRenderUtilities.mMaterial[1].mTypeUID,
      uidBILATERALBLURY_NOSUN);
    mOffset = mMaterial->mMaterialUser.mOffset;
    if ( mOffset )
    {
      v15 = (_WORD *)((char *)&mMaterial->mMaterialUser + mOffset);
      goto LABEL_13;
    }
LABEL_12:
    v15 = 0i64;
    goto LABEL_13;
  }
  if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == uidBILATERALBLURY )
    goto LABEL_14;
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
    Render::gRenderUtilities.mMaterial[1].mTypeUID,
    uidBILATERALBLURY);
  v14 = mMaterial->mMaterialUser.mOffset;
  if ( !v14 )
    goto LABEL_12;
  v15 = (_WORD *)((char *)&mMaterial->mMaterialUser + v14);
LABEL_13:
  *v15 |= 0x20u;
  mMaterial = Render::gRenderUtilities.mMaterial;
LABEL_14:
  mUID = render_context->mHalfSizeScratchTargetB->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
      mMaterial[1].mStateBlockMask.mFlags[1],
      mUID);
    v18 = mMaterial->mMaterialUser.mOffset;
    if ( v18 )
      v6 = (_WORD *)((char *)&mMaterial->mMaterialUser + v18);
    *v6 |= 0x20u;
  }
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::View::Draw(view, &poly, Render::gRenderUtilities.mMaterial, 0i64);
  UFG::DropShadowComponent::DrawAll(view, render_context->mHalfSizeLinearDepthTarget);
  mPrev = clearOnResolve.mPrev;
  mNext = clearOnResolve.mNext;
  clearOnResolve.mPrev->mNext = clearOnResolve.mNext;
  mNext->mPrev = mPrev;
  clearOnResolve.mPrev = &clearOnResolve;
  clearOnResolve.mNext = &clearOnResolve;
  clearOnResolve.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[clearOnResolve.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[clearOnResolve.mStateParamIndex] )
  {
    v21 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)clearOnResolve.mStateParamIndex >> 6];
    *v21 &= ~(1i64 << (clearOnResolve.mStateParamIndex & 0x3F));
  }
  Render::View::EndTarget(view);
  v22 = clearOnResolve.mPrev;
  v23 = clearOnResolve.mNext;
  clearOnResolve.mPrev->mNext = clearOnResolve.mNext;
  v23->mPrev = v22;
}

// File Line: 489
// RVA: 0x359C0
Illusion::RenderQueue *__fastcall UFG::RenderStageAO::RenderAmbientOcclusionCS(
        UFG::RenderStageAO *this,
        UFG::RenderContext *render_context,
        bool bQuarterSize)
{
  Illusion::Target *mQuarterSizeAmbientOcclusionTarget; // rbp
  __m128 v7; // xmm1
  int v8; // ecx
  __m128 v9; // xmm1
  int v10; // ecx
  int v11; // r12d
  char *v12; // rax
  char *v13; // rbx
  UFG::qResourceData *mData; // r15
  __int64 v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rcx
  char *v18; // rax
  char *v19; // rdx
  __int64 v20; // rax
  __int64 v21; // rax
  float z; // xmm1_4
  float v23; // xmm10_4
  float w; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm10_4
  float v27; // xmm10_4
  float v28; // xmm9_4
  float v29; // xmm7_4
  float *v30; // r15
  __int64 v31; // rdx
  __int64 v32; // rax
  __int64 v33; // rcx
  char *v34; // rax
  char *v35; // rdx
  __int64 v36; // rax
  __int64 v37; // rax
  Illusion::Target *mQuarterSizeLinearDepthTarget; // rax
  Illusion::Texture *v39; // rbp
  __int64 v40; // rdx
  __int64 v41; // rax
  __int64 v42; // rcx
  char *v43; // rax
  char *v44; // rdx
  __int64 v45; // rax
  __int64 v46; // rax
  Illusion::Texture *v47; // rbp
  __int64 v48; // rdx
  __int64 v49; // rax
  __int64 v50; // rcx
  char *v51; // rax
  char *v52; // rdx
  __int64 v53; // rax
  __int64 v54; // rax
  Illusion::UnorderedAccessView *mAmbientOcclusionAliasUAV; // rsi
  unsigned __int16 mAOCSUAVParamIndex; // bp
  __int64 v57; // rdx
  __int64 v58; // rax
  __int64 v59; // rcx
  char *v60; // rax
  char *v61; // rdx
  __int64 v62; // rax
  __int64 v63; // rax
  char *v64; // rsi
  __int64 v65; // rcx
  __int64 v66; // rdx
  __int64 v67; // rax
  char *v68; // rax
  char *v69; // rdx
  __int64 v70; // rax
  __int64 v71; // rax
  __int64 v72; // rax
  int v74; // [rsp+D0h] [rbp+8h]
  float v75; // [rsp+E0h] [rbp+18h]

  if ( bQuarterSize )
    mQuarterSizeAmbientOcclusionTarget = render_context->mQuarterSizeAmbientOcclusionTarget;
  else
    mQuarterSizeAmbientOcclusionTarget = render_context->mAmbientOcclusionAliasTarget;
  v7 = (__m128)COERCE_UNSIGNED_INT((float)mQuarterSizeAmbientOcclusionTarget->mWidth);
  v7.m128_f32[0] = v7.m128_f32[0] * 0.03125;
  v8 = (int)v7.m128_f32[0];
  if ( (int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
    v7.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1) + v8);
  v74 = (int)v7.m128_f32[0];
  v9 = (__m128)COERCE_UNSIGNED_INT((float)mQuarterSizeAmbientOcclusionTarget->mHeight);
  v9.m128_f32[0] = v9.m128_f32[0] * 0.03125;
  v10 = (int)v9.m128_f32[0];
  if ( (int)v9.m128_f32[0] != 0x80000000 && (float)v10 != v9.m128_f32[0] )
    v9.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v9, v9)) & 1) + v10);
  v11 = (int)v9.m128_f32[0];
  v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v13 = v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = v12;
    *((_QWORD *)v12 + 1) = v12;
    *((_QWORD *)v12 + 2) = v12 + 16;
    *((_QWORD *)v12 + 3) = v12 + 16;
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
  if ( bQuarterSize )
    mData = this->mHalfResAOCSShader.mData;
  else
    mData = this->mAOCSShader.mData;
  v15 = *((_QWORD *)v13 + 5);
  if ( v15 )
  {
    v16 = *(unsigned int *)(v15 + 24);
    if ( (unsigned int)v16 < 0x7E )
    {
      v17 = v15 + 16 * (v16 + 2);
      *(_DWORD *)(v15 + 24) = v16 + 1;
      goto LABEL_24;
    }
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v15 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  v18 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v19 = v18;
  if ( v18 )
  {
    *(_QWORD *)v18 = v18;
    *((_QWORD *)v18 + 1) = v18;
    *((_QWORD *)v18 + 2) = 0i64;
    *((_DWORD *)v18 + 6) = 0;
    v20 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v20 + 8) = v19;
    *(_QWORD *)v19 = v20;
    *((_QWORD *)v19 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v19;
    *((_QWORD *)v13 + 5) = v19;
  }
  v21 = *((_QWORD *)v13 + 5);
  if ( v21 )
  {
    *(_DWORD *)(v21 + 24) = 1;
    v17 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_24:
    if ( v17 )
    {
      *(_DWORD *)v17 = 1;
      *(_QWORD *)(v17 + 8) = mData;
    }
  }
  z = render_context->mMainViewSettings.mProjection.v2.z;
  v23 = render_context->mMainViewSettings.mProjection.v3.z;
  w = render_context->mMainViewSettings.mProjection.v2.w;
  if ( z == 0.0 || z == w )
  {
    v26 = v75;
    v25 = v75;
  }
  else
  {
    v25 = v23 / z;
    v26 = (float)(v23 - render_context->mMainViewSettings.mProjection.v3.w) / (float)(z - w);
  }
  v27 = v26 / (float)(v26 - v25);
  v28 = 1.0 / render_context->mMainViewSettings.mProjection.v0.x;
  v29 = 1.0 / render_context->mMainViewSettings.mProjection.v1.y;
  v30 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  *v30 = (float)mQuarterSizeAmbientOcclusionTarget->mWidth;
  v30[1] = (float)mQuarterSizeAmbientOcclusionTarget->mHeight;
  v30[2] = 1.0 / (float)mQuarterSizeAmbientOcclusionTarget->mWidth;
  v30[3] = 1.0 / (float)mQuarterSizeAmbientOcclusionTarget->mHeight;
  v30[7] = v27 * v25;
  v30[6] = v27 * v25;
  v30[5] = v27 * v25;
  v30[4] = v27 * v25;
  v30[11] = v27;
  v30[10] = v27;
  v30[9] = v27;
  v30[8] = v27;
  v30[12] = v28;
  v30[13] = v29;
  v31 = *((_QWORD *)v13 + 5);
  if ( v31 )
  {
    v32 = *(unsigned int *)(v31 + 24);
    if ( (unsigned int)v32 < 0x7E )
    {
      v33 = v31 + 16 * (v32 + 2);
      *(_DWORD *)(v31 + 24) = v32 + 1;
      goto LABEL_38;
    }
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v31 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  v34 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v35 = v34;
  if ( v34 )
  {
    *(_QWORD *)v34 = v34;
    *((_QWORD *)v34 + 1) = v34;
    *((_QWORD *)v34 + 2) = 0i64;
    *((_DWORD *)v34 + 6) = 0;
    v36 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v36 + 8) = v35;
    *(_QWORD *)v35 = v36;
    *((_QWORD *)v35 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v35;
    *((_QWORD *)v13 + 5) = v35;
  }
  v37 = *((_QWORD *)v13 + 5);
  if ( v37 )
  {
    *(_DWORD *)(v37 + 24) = 1;
    v33 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_38:
    if ( v33 )
    {
      *(_DWORD *)v33 = 983042;
      *(_QWORD *)(v33 + 8) = v30;
    }
  }
  if ( bQuarterSize )
    mQuarterSizeLinearDepthTarget = render_context->mQuarterSizeLinearDepthTarget;
  else
    mQuarterSizeLinearDepthTarget = render_context->mHalfSizeLinearDepthTarget;
  v39 = mQuarterSizeLinearDepthTarget->mTargetTexture[0];
  v40 = *((_QWORD *)v13 + 5);
  if ( v40 )
  {
    v41 = *(unsigned int *)(v40 + 24);
    if ( (unsigned int)v41 < 0x7E )
    {
      v42 = v40 + 16 * (v41 + 2);
      *(_DWORD *)(v40 + 24) = v41 + 1;
      goto LABEL_51;
    }
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v40 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  v43 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v44 = v43;
  if ( v43 )
  {
    *(_QWORD *)v43 = v43;
    *((_QWORD *)v43 + 1) = v43;
    *((_QWORD *)v43 + 2) = 0i64;
    *((_DWORD *)v43 + 6) = 0;
    v45 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v45 + 8) = v44;
    *(_QWORD *)v44 = v45;
    *((_QWORD *)v44 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v44;
    *((_QWORD *)v13 + 5) = v44;
  }
  v46 = *((_QWORD *)v13 + 5);
  if ( v46 )
  {
    *(_DWORD *)(v46 + 24) = 1;
    v42 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_51:
    if ( v42 )
    {
      *(_DWORD *)v42 = 3080194;
      *(_QWORD *)(v42 + 8) = v39;
    }
  }
  if ( !bQuarterSize )
  {
    v47 = render_context->mQuarterSizeAmbientOcclusionTarget->mTargetTexture[0];
    v48 = *((_QWORD *)v13 + 5);
    if ( v48 )
    {
      v49 = *(unsigned int *)(v48 + 24);
      if ( (unsigned int)v49 < 0x7E )
      {
        v50 = v48 + 16 * (v49 + 2);
        *(_DWORD *)(v48 + 24) = v49 + 1;
        goto LABEL_62;
      }
      *((_DWORD *)v13 + 18) += *(_DWORD *)(v48 + 24);
      *((_QWORD *)v13 + 5) = 0i64;
    }
    v51 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v52 = v51;
    if ( v51 )
    {
      *(_QWORD *)v51 = v51;
      *((_QWORD *)v51 + 1) = v51;
      *((_QWORD *)v51 + 2) = 0i64;
      *((_DWORD *)v51 + 6) = 0;
      v53 = *((_QWORD *)v13 + 2);
      *(_QWORD *)(v53 + 8) = v52;
      *(_QWORD *)v52 = v53;
      *((_QWORD *)v52 + 1) = v13 + 16;
      *((_QWORD *)v13 + 2) = v52;
      *((_QWORD *)v13 + 5) = v52;
    }
    v54 = *((_QWORD *)v13 + 5);
    if ( !v54 )
      goto LABEL_64;
    *(_DWORD *)(v54 + 24) = 1;
    v50 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_62:
    if ( v50 )
    {
      *(_DWORD *)v50 = 1114114;
      *(_QWORD *)(v50 + 8) = v47;
    }
LABEL_64:
    mAmbientOcclusionAliasUAV = render_context->mAmbientOcclusionAliasUAV;
    goto LABEL_66;
  }
  mAmbientOcclusionAliasUAV = render_context->mQuarterSizeAmbientOcclusionAliasUAV;
LABEL_66:
  mAOCSUAVParamIndex = this->mAOCSUAVParamIndex;
  v57 = *((_QWORD *)v13 + 5);
  if ( v57 )
  {
    v58 = *(unsigned int *)(v57 + 24);
    if ( (unsigned int)v58 < 0x7E )
    {
      v59 = v57 + 16 * (v58 + 2);
      *(_DWORD *)(v57 + 24) = v58 + 1;
      goto LABEL_74;
    }
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v57 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  v60 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v61 = v60;
  if ( v60 )
  {
    *(_QWORD *)v60 = v60;
    *((_QWORD *)v60 + 1) = v60;
    *((_QWORD *)v60 + 2) = 0i64;
    *((_DWORD *)v60 + 6) = 0;
    v62 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v62 + 8) = v61;
    *(_QWORD *)v61 = v62;
    *((_QWORD *)v61 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v61;
    *((_QWORD *)v13 + 5) = v61;
  }
  v63 = *((_QWORD *)v13 + 5);
  if ( v63 )
  {
    *(_DWORD *)(v63 + 24) = 1;
    v59 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_74:
    if ( v59 )
    {
      *(_WORD *)v59 = 2;
      *(_WORD *)(v59 + 2) = mAOCSUAVParamIndex;
      *(_QWORD *)(v59 + 8) = mAmbientOcclusionAliasUAV;
    }
  }
  v64 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 4u);
  if ( v64 )
  {
    *(_DWORD *)v64 = v74;
    *((_DWORD *)v64 + 1) = v11;
    *((_DWORD *)v64 + 2) = 1;
  }
  else
  {
    v64 = 0i64;
  }
  v65 = *((_QWORD *)v13 + 5);
  if ( v65 )
  {
    v66 = *(unsigned int *)(v65 + 24);
    if ( (unsigned int)v66 < 0x7E )
    {
      *(_DWORD *)(v65 + 24) = v66 + 1;
      v67 = v65 + 16 * (v66 + 2);
      goto LABEL_87;
    }
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v65 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  v68 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v69 = v68;
  if ( v68 )
  {
    *(_QWORD *)v68 = v68;
    *((_QWORD *)v68 + 1) = v68;
    *((_QWORD *)v68 + 2) = 0i64;
    *((_DWORD *)v68 + 6) = 0;
    v70 = *((_QWORD *)v13 + 2);
    *(_QWORD *)(v70 + 8) = v69;
    *(_QWORD *)v69 = v70;
    *((_QWORD *)v69 + 1) = v13 + 16;
    *((_QWORD *)v13 + 2) = v69;
    *((_QWORD *)v13 + 5) = v69;
  }
  v71 = *((_QWORD *)v13 + 5);
  if ( v71 )
  {
    *(_DWORD *)(v71 + 24) = 1;
    v67 = *((_QWORD *)v13 + 5) + 32i64;
LABEL_87:
    if ( v67 )
    {
      *(_DWORD *)v67 = 26;
      *(_QWORD *)(v67 + 8) = v64;
    }
  }
  v72 = *((_QWORD *)v13 + 5);
  if ( v72 )
  {
    *((_DWORD *)v13 + 18) += *(_DWORD *)(v72 + 24);
    *((_QWORD *)v13 + 5) = 0i64;
  }
  return (Illusion::RenderQueue *)v13;
}

// File Line: 543
// RVA: 0x34590
void __fastcall UFG::RenderStageAO::RenderAOBilateralBlurCS(
        UFG::RenderStageAO *this,
        UFG::RenderContext *render_context,
        Render::View *view,
        bool bQuarterSize)
{
  Illusion::Target *mQuarterSizeAmbientOcclusionTarget; // r15
  float *v7; // r14
  char *v8; // rax
  char *v9; // rdi
  UFG::qResourceData *mData; // rbx
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rcx
  char *v14; // rax
  char *v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rax
  __int64 v20; // rcx
  char *v21; // rax
  char *v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rax
  char v25; // r14
  Illusion::Texture *mQuarterSizeScratchAPointSampleTexture; // rbx
  __int64 v27; // rdx
  __int64 v28; // rax
  __int64 v29; // rcx
  char *v30; // rax
  char *v31; // rdx
  __int64 v32; // rax
  __int64 v33; // rax
  Illusion::UnorderedAccessView *mQuarterSizeAmbientOcclusionScratchUAV; // rbx
  __int16 v35; // r14
  __int64 v36; // rdx
  __int64 v37; // rax
  __int64 v38; // rcx
  char *v39; // rax
  char *v40; // rdx
  __int64 v41; // rax
  __int64 v42; // rax
  __m128 v43; // xmm1
  int v44; // ecx
  __m128 v45; // xmm2
  int v46; // ecx
  char *v47; // rax
  char *v48; // rbx
  __int64 v49; // rdx
  __int64 v50; // rax
  __int64 v51; // rcx
  char *v52; // rax
  char *v53; // rdx
  __int64 v54; // rax
  __int64 v55; // rax
  __int64 v56; // r15
  __int64 v57; // rbx
  __int64 v58; // rdx
  __int64 v59; // rax
  __int64 v60; // rcx
  char *v61; // rax
  char *v62; // rdx
  __int64 v63; // rax
  __int64 v64; // rax
  __int64 v65; // rdx
  __int64 v66; // rax
  __int64 v67; // rcx
  char *v68; // rax
  char *v69; // rdx
  __int64 v70; // rax
  __int64 v71; // rax
  char v72; // r14
  Illusion::Texture *mQuarterSizeScratchBPointSampleTexture; // rbx
  __int64 v74; // rdx
  __int64 v75; // rax
  __int64 v76; // rcx
  char *v77; // rax
  char *v78; // rdx
  __int64 v79; // rax
  __int64 v80; // rax
  Illusion::UnorderedAccessView *mQuarterSizeAmbientOcclusionAliasUAV; // rbx
  __int16 v82; // r14
  __int64 v83; // rdx
  __int64 v84; // rax
  __int64 v85; // rcx
  char *v86; // rax
  char *v87; // rdx
  __int64 v88; // rax
  __int64 v89; // rax
  __m128 v90; // xmm1
  int v91; // ecx
  int v92; // r15d
  __m128 v93; // xmm1
  int v94; // ecx
  char *v95; // rax
  char *v96; // rbx
  __int64 v97; // rdx
  __int64 v98; // rax
  __int64 v99; // rcx
  char *v100; // rax
  char *v101; // rdx
  __int64 v102; // rax
  __int64 v103; // rax
  __int64 v104; // rax
  Render::View *v105; // r15
  RenderQueueLayer *v106; // rbx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *mSerializationList; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  Illusion::StateArgs *StateArgs; // rbx
  UFG::qMatrix44 *p_mWorldView; // rdi
  UFG::qMatrix44 *p_mProjection; // r14
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v113; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v115; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v116; // rax
  int *vp_scissor; // [rsp+28h] [rbp-39h]
  Render::cbExternalViewTransformState clear_on_resolve; // [rsp+30h] [rbp-31h] BYREF
  float *v119; // [rsp+68h] [rbp+7h]
  char *v120; // [rsp+70h] [rbp+Fh]
  __int64 v121; // [rsp+78h] [rbp+17h]
  char *v122; // [rsp+C8h] [rbp+67h]
  Render::View *viewa; // [rsp+D8h] [rbp+77h]
  char v124; // [rsp+E0h] [rbp+7Fh]

  v121 = -2i64;
  if ( bQuarterSize )
    mQuarterSizeAmbientOcclusionTarget = render_context->mQuarterSizeAmbientOcclusionTarget;
  else
    mQuarterSizeAmbientOcclusionTarget = render_context->mAmbientOcclusionAliasTarget;
  vp_scissor = (int *)mQuarterSizeAmbientOcclusionTarget;
  v7 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
  v119 = v7;
  *v7 = (float)mQuarterSizeAmbientOcclusionTarget->mWidth;
  v7[1] = (float)mQuarterSizeAmbientOcclusionTarget->mHeight;
  v7[2] = 1.0 / (float)mQuarterSizeAmbientOcclusionTarget->mWidth;
  v7[3] = 1.0 / (float)mQuarterSizeAmbientOcclusionTarget->mHeight;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v9 = v8;
  v120 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    *((_QWORD *)v8 + 2) = v8 + 16;
    *((_QWORD *)v8 + 3) = v8 + 16;
    UFG::qMemSet(v8 + 96, 0, 0x400u);
    *((_QWORD *)v9 + 11) = 0i64;
    *((_QWORD *)v9 + 10) = 0i64;
    *((_DWORD *)v9 + 8) = 0;
    *((_QWORD *)v9 + 5) = 0i64;
    *((_QWORD *)v9 + 6) = 0i64;
    *((_QWORD *)v9 + 7) = 0i64;
    *((_QWORD *)v9 + 8) = 0i64;
    *((_QWORD *)v9 + 9) = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  mData = this->mBilateralXCSShader.mData;
  v11 = *((_QWORD *)v9 + 5);
  if ( v11 )
  {
    v12 = *(unsigned int *)(v11 + 24);
    if ( (unsigned int)v12 < 0x7E )
    {
      v13 = v11 + 16 * (v12 + 2);
      *(_DWORD *)(v11 + 24) = v12 + 1;
      goto LABEL_15;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v11 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v15 = v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = v14;
    *((_QWORD *)v14 + 1) = v14;
    *((_QWORD *)v14 + 2) = 0i64;
    *((_DWORD *)v14 + 6) = 0;
    v16 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v16 + 8) = v15;
    *(_QWORD *)v15 = v16;
    *((_QWORD *)v15 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v15;
    *((_QWORD *)v9 + 5) = v15;
  }
  v17 = *((_QWORD *)v9 + 5);
  if ( v17 )
  {
    *(_DWORD *)(v17 + 24) = 1;
    v13 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_15:
    if ( v13 )
    {
      *(_DWORD *)v13 = 1;
      *(_QWORD *)(v13 + 8) = mData;
    }
  }
  v18 = *((_QWORD *)v9 + 5);
  if ( v18 )
  {
    v19 = *(unsigned int *)(v18 + 24);
    if ( (unsigned int)v19 < 0x7E )
    {
      v20 = v18 + 16 * (v19 + 2);
      *(_DWORD *)(v18 + 24) = v19 + 1;
      goto LABEL_25;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v18 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v22 = v21;
  if ( v21 )
  {
    *(_QWORD *)v21 = v21;
    *((_QWORD *)v21 + 1) = v21;
    *((_QWORD *)v21 + 2) = 0i64;
    *((_DWORD *)v21 + 6) = 0;
    v23 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v23 + 8) = v22;
    *(_QWORD *)v22 = v23;
    *((_QWORD *)v22 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v22;
    *((_QWORD *)v9 + 5) = v22;
  }
  v24 = *((_QWORD *)v9 + 5);
  if ( v24 )
  {
    *(_DWORD *)(v24 + 24) = 1;
    v20 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_25:
    if ( v20 )
    {
      *(_DWORD *)v20 = 983042;
      *(_QWORD *)(v20 + 8) = v7;
    }
  }
  v25 = v124;
  if ( v124 )
    mQuarterSizeScratchAPointSampleTexture = render_context->mQuarterSizeScratchAPointSampleTexture;
  else
    mQuarterSizeScratchAPointSampleTexture = render_context->mHalfSizeScratchCPointSampleTexture;
  v27 = *((_QWORD *)v9 + 5);
  if ( v27 )
  {
    v28 = *(unsigned int *)(v27 + 24);
    if ( (unsigned int)v28 < 0x7E )
    {
      v29 = v27 + 16 * (v28 + 2);
      *(_DWORD *)(v27 + 24) = v28 + 1;
      goto LABEL_38;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v27 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v30 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v31 = v30;
  if ( v30 )
  {
    *(_QWORD *)v30 = v30;
    *((_QWORD *)v30 + 1) = v30;
    *((_QWORD *)v30 + 2) = 0i64;
    *((_DWORD *)v30 + 6) = 0;
    v32 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v32 + 8) = v31;
    *(_QWORD *)v31 = v32;
    *((_QWORD *)v31 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v31;
    *((_QWORD *)v9 + 5) = v31;
  }
  v33 = *((_QWORD *)v9 + 5);
  if ( v33 )
  {
    *(_DWORD *)(v33 + 24) = 1;
    v29 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_38:
    if ( v29 )
    {
      *(_DWORD *)v29 = 1114114;
      *(_QWORD *)(v29 + 8) = mQuarterSizeScratchAPointSampleTexture;
    }
  }
  if ( v25 )
    mQuarterSizeAmbientOcclusionScratchUAV = render_context->mQuarterSizeAmbientOcclusionScratchUAV;
  else
    mQuarterSizeAmbientOcclusionScratchUAV = render_context->mAmbientOcclusionScratchUAV;
  v35 = *((_WORD *)v122 + 68);
  v36 = *((_QWORD *)v9 + 5);
  if ( v36 )
  {
    v37 = *(unsigned int *)(v36 + 24);
    if ( (unsigned int)v37 < 0x7E )
    {
      v38 = v36 + 16 * (v37 + 2);
      *(_DWORD *)(v36 + 24) = v37 + 1;
      goto LABEL_51;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v36 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v39 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v40 = v39;
  if ( v39 )
  {
    *(_QWORD *)v39 = v39;
    *((_QWORD *)v39 + 1) = v39;
    *((_QWORD *)v39 + 2) = 0i64;
    *((_DWORD *)v39 + 6) = 0;
    v41 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v41 + 8) = v40;
    *(_QWORD *)v40 = v41;
    *((_QWORD *)v40 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v40;
    *((_QWORD *)v9 + 5) = v40;
  }
  v42 = *((_QWORD *)v9 + 5);
  if ( v42 )
  {
    *(_DWORD *)(v42 + 24) = 1;
    v38 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_51:
    if ( v38 )
    {
      *(_WORD *)v38 = 2;
      *(_WORD *)(v38 + 2) = v35;
      *(_QWORD *)(v38 + 8) = mQuarterSizeAmbientOcclusionScratchUAV;
    }
  }
  v43 = (__m128)COERCE_UNSIGNED_INT((float)mQuarterSizeAmbientOcclusionTarget->mWidth);
  v43.m128_f32[0] = v43.m128_f32[0] * 0.0078125;
  v44 = (int)v43.m128_f32[0];
  if ( (int)v43.m128_f32[0] != 0x80000000 && (float)v44 != v43.m128_f32[0] )
    v43.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v43, v43)) & 1) + v44);
  v45 = (__m128)COERCE_UNSIGNED_INT((float)mQuarterSizeAmbientOcclusionTarget->mHeight);
  v45.m128_f32[0] = v45.m128_f32[0] * 0.5;
  v46 = (int)v45.m128_f32[0];
  if ( (int)v45.m128_f32[0] != 0x80000000 && (float)v46 != v45.m128_f32[0] )
    v45.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v45, v45)) & 1) + v46);
  v47 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 4u);
  v48 = v47;
  if ( v47 )
  {
    *(_DWORD *)v47 = (int)v43.m128_f32[0];
    *((_DWORD *)v47 + 1) = (int)v45.m128_f32[0];
    *((_DWORD *)v47 + 2) = 1;
  }
  else
  {
    v48 = 0i64;
  }
  v49 = *((_QWORD *)v9 + 5);
  if ( v49 )
  {
    v50 = *(unsigned int *)(v49 + 24);
    if ( (unsigned int)v50 < 0x7E )
    {
      v51 = v49 + 16 * (v50 + 2);
      *(_DWORD *)(v49 + 24) = v50 + 1;
      goto LABEL_70;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v49 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v52 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v53 = v52;
  if ( v52 )
  {
    *(_QWORD *)v52 = v52;
    *((_QWORD *)v52 + 1) = v52;
    *((_QWORD *)v52 + 2) = 0i64;
    *((_DWORD *)v52 + 6) = 0;
    v54 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v54 + 8) = v53;
    *(_QWORD *)v53 = v54;
    *((_QWORD *)v53 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v53;
    *((_QWORD *)v9 + 5) = v53;
  }
  v55 = *((_QWORD *)v9 + 5);
  if ( v55 )
  {
    *(_DWORD *)(v55 + 24) = 1;
    v51 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_70:
    if ( v51 )
    {
      *(_DWORD *)v51 = 26;
      *(_QWORD *)(v51 + 8) = v48;
    }
  }
  v56 = (__int64)v122;
  v57 = *((_QWORD *)v122 + 15);
  v58 = *((_QWORD *)v9 + 5);
  if ( v58 )
  {
    v59 = *(unsigned int *)(v58 + 24);
    if ( (unsigned int)v59 < 0x7E )
    {
      v60 = v58 + 16 * (v59 + 2);
      *(_DWORD *)(v58 + 24) = v59 + 1;
      goto LABEL_80;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v58 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v61 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v62 = v61;
  v122 = v61;
  if ( v61 )
  {
    *(_QWORD *)v61 = v61;
    *((_QWORD *)v61 + 1) = v61;
    *((_QWORD *)v61 + 2) = 0i64;
    *((_DWORD *)v61 + 6) = 0;
    v63 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v63 + 8) = v62;
    *(_QWORD *)v62 = v63;
    *((_QWORD *)v62 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v62;
    *((_QWORD *)v9 + 5) = v62;
  }
  v64 = *((_QWORD *)v9 + 5);
  if ( v64 )
  {
    *(_DWORD *)(v64 + 24) = 1;
    v60 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_80:
    if ( v60 )
    {
      *(_DWORD *)v60 = 1;
      *(_QWORD *)(v60 + 8) = v57;
    }
  }
  v65 = *((_QWORD *)v9 + 5);
  if ( v65 )
  {
    v66 = *(unsigned int *)(v65 + 24);
    if ( (unsigned int)v66 < 0x7E )
    {
      v67 = v65 + 16 * (v66 + 2);
      *(_DWORD *)(v65 + 24) = v66 + 1;
      goto LABEL_90;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v65 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v68 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v69 = v68;
  v122 = v68;
  if ( v68 )
  {
    *(_QWORD *)v68 = v68;
    *((_QWORD *)v68 + 1) = v68;
    *((_QWORD *)v68 + 2) = 0i64;
    *((_DWORD *)v68 + 6) = 0;
    v70 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v70 + 8) = v69;
    *(_QWORD *)v69 = v70;
    *((_QWORD *)v69 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v69;
    *((_QWORD *)v9 + 5) = v69;
  }
  v71 = *((_QWORD *)v9 + 5);
  if ( v71 )
  {
    *(_DWORD *)(v71 + 24) = 1;
    v67 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_90:
    if ( v67 )
    {
      *(_DWORD *)v67 = 983042;
      *(_QWORD *)(v67 + 8) = v119;
    }
  }
  v72 = v124;
  if ( v124 )
    mQuarterSizeScratchBPointSampleTexture = render_context->mQuarterSizeScratchBPointSampleTexture;
  else
    mQuarterSizeScratchBPointSampleTexture = render_context->mHalfSizeScratchBPointSampleTexture;
  v74 = *((_QWORD *)v9 + 5);
  if ( v74 )
  {
    v75 = *(unsigned int *)(v74 + 24);
    if ( (unsigned int)v75 < 0x7E )
    {
      v76 = v74 + 16 * (v75 + 2);
      *(_DWORD *)(v74 + 24) = v75 + 1;
      goto LABEL_103;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v74 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v77 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v78 = v77;
  v122 = v77;
  if ( v77 )
  {
    *(_QWORD *)v77 = v77;
    *((_QWORD *)v77 + 1) = v77;
    *((_QWORD *)v77 + 2) = 0i64;
    *((_DWORD *)v77 + 6) = 0;
    v79 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v79 + 8) = v78;
    *(_QWORD *)v78 = v79;
    *((_QWORD *)v78 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v78;
    *((_QWORD *)v9 + 5) = v78;
  }
  v80 = *((_QWORD *)v9 + 5);
  if ( v80 )
  {
    *(_DWORD *)(v80 + 24) = 1;
    v76 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_103:
    if ( v76 )
    {
      *(_DWORD *)v76 = 1114114;
      *(_QWORD *)(v76 + 8) = mQuarterSizeScratchBPointSampleTexture;
    }
  }
  if ( v72 )
    mQuarterSizeAmbientOcclusionAliasUAV = render_context->mQuarterSizeAmbientOcclusionAliasUAV;
  else
    mQuarterSizeAmbientOcclusionAliasUAV = render_context->mAmbientOcclusionAliasUAV;
  v82 = *(_WORD *)(v56 + 136);
  v83 = *((_QWORD *)v9 + 5);
  if ( v83 )
  {
    v84 = *(unsigned int *)(v83 + 24);
    if ( (unsigned int)v84 < 0x7E )
    {
      v85 = v83 + 16 * (v84 + 2);
      *(_DWORD *)(v83 + 24) = v84 + 1;
      goto LABEL_116;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v83 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v86 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v87 = v86;
  v122 = v86;
  if ( v86 )
  {
    *(_QWORD *)v86 = v86;
    *((_QWORD *)v86 + 1) = v86;
    *((_QWORD *)v86 + 2) = 0i64;
    *((_DWORD *)v86 + 6) = 0;
    v88 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v88 + 8) = v87;
    *(_QWORD *)v87 = v88;
    *((_QWORD *)v87 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v87;
    *((_QWORD *)v9 + 5) = v87;
  }
  v89 = *((_QWORD *)v9 + 5);
  if ( v89 )
  {
    *(_DWORD *)(v89 + 24) = 1;
    v85 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_116:
    if ( v85 )
    {
      *(_WORD *)v85 = 2;
      *(_WORD *)(v85 + 2) = v82;
      *(_QWORD *)(v85 + 8) = mQuarterSizeAmbientOcclusionAliasUAV;
    }
  }
  v90 = (__m128)COERCE_UNSIGNED_INT((float)*vp_scissor);
  v90.m128_f32[0] = v90.m128_f32[0] * 0.5;
  v91 = (int)v90.m128_f32[0];
  if ( (int)v90.m128_f32[0] != 0x80000000 && (float)v91 != v90.m128_f32[0] )
    v90.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v90, v90)) & 1) + v91);
  v92 = (int)v90.m128_f32[0];
  v93 = (__m128)COERCE_UNSIGNED_INT((float)vp_scissor[1]);
  v93.m128_f32[0] = v93.m128_f32[0] * 0.0078125;
  v94 = (int)v93.m128_f32[0];
  if ( (int)v93.m128_f32[0] != 0x80000000 && (float)v94 != v93.m128_f32[0] )
    v93.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v93, v93)) & 1) + v94);
  v95 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 4u);
  v96 = v95;
  v122 = v95;
  if ( v95 )
  {
    *(_DWORD *)v95 = v92;
    *((_DWORD *)v95 + 1) = (int)v93.m128_f32[0];
    *((_DWORD *)v95 + 2) = 1;
  }
  else
  {
    v96 = 0i64;
  }
  v97 = *((_QWORD *)v9 + 5);
  if ( v97 )
  {
    v98 = *(unsigned int *)(v97 + 24);
    if ( (unsigned int)v98 < 0x7E )
    {
      v99 = v97 + 16 * (v98 + 2);
      *(_DWORD *)(v97 + 24) = v98 + 1;
      goto LABEL_135;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v97 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v100 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v101 = v100;
  v122 = v100;
  if ( v100 )
  {
    *(_QWORD *)v100 = v100;
    *((_QWORD *)v100 + 1) = v100;
    *((_QWORD *)v100 + 2) = 0i64;
    *((_DWORD *)v100 + 6) = 0;
    v102 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v102 + 8) = v101;
    *(_QWORD *)v101 = v102;
    *((_QWORD *)v101 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v101;
    *((_QWORD *)v9 + 5) = v101;
  }
  v103 = *((_QWORD *)v9 + 5);
  if ( v103 )
  {
    *(_DWORD *)(v103 + 24) = 1;
    v99 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_135:
    if ( v99 )
    {
      *(_DWORD *)v99 = 26;
      *(_QWORD *)(v99 + 8) = v96;
    }
  }
  v104 = *((_QWORD *)v9 + 5);
  if ( v104 )
  {
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v104 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v105 = viewa;
  v106 = (RenderQueueLayer *)viewa->mSubmitContext[1].mStateValues.mParamValues[0];
  RenderQueueLayer::SerializeRenderQueues(v106);
  mSerializationList = v106->mSerializationList;
  mPrev = v106->mSerializationList->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
  *(_QWORD *)v9 = mPrev;
  *((_QWORD *)v9 + 1) = mSerializationList;
  mSerializationList->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
  if ( !v124 )
  {
    StateArgs = Render::View::GetStateArgs(v105);
    Render::View::BeginTarget(v105, render_context->mAmbientOcclusionAliasTarget, "DropShadows", 0, 0, 0i64, 1, 0, 0, 0);
    p_mWorldView = &v105->mSettings->mWorldView;
    p_mProjection = &v105->mSettings->mProjection;
    clear_on_resolve.mPrev = &clear_on_resolve;
    clear_on_resolve.mNext = &clear_on_resolve;
    clear_on_resolve.mCallback = 0i64;
    clear_on_resolve.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&clear_on_resolve.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = Param;
      clear_on_resolve.mStateParamIndex = Param;
    }
    clear_on_resolve.mWorldView = p_mWorldView;
    clear_on_resolve.mProjection = p_mProjection;
    clear_on_resolve.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &clear_on_resolve);
    UFG::DropShadowComponent::DrawAll(v105, render_context->mHalfSizeLinearDepthTarget);
    v113 = clear_on_resolve.mPrev;
    mNext = clear_on_resolve.mNext;
    clear_on_resolve.mPrev->mNext = clear_on_resolve.mNext;
    mNext->mPrev = v113;
    clear_on_resolve.mPrev = &clear_on_resolve;
    clear_on_resolve.mNext = &clear_on_resolve;
    clear_on_resolve.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[clear_on_resolve.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[clear_on_resolve.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)clear_on_resolve.mStateParamIndex >> 6] &= ~(1i64 << (clear_on_resolve.mStateParamIndex & 0x3F));
    Render::View::EndTarget(v105);
    v115 = clear_on_resolve.mPrev;
    v116 = clear_on_resolve.mNext;
    clear_on_resolve.mPrev->mNext = clear_on_resolve.mNext;
    v116->mPrev = v115;
  }
}    clear_on_resolve.mPrev = &clear_on_resolve;
    clear_on_resolve.mNext = &clear_on_resolve;
    clear_on_resolve.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[clear_on_resolve.mStateParamInde

