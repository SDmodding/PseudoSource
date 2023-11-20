// File Line: 37
// RVA: 0x3F1C0
void UFG::RenderWorldState::Init(void)
{
  UFG::qResourceData *v0; // rax
  UFG::qResourceData *v1; // rbx
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *v9; // rbx
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceData *v11; // rbx
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceData *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceData *v15; // rbx
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceData *v17; // rbx
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceData *v19; // rbx
  UFG::qResourceWarehouse *v20; // rax
  UFG::qResourceData *v21; // rbx
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceData *v23; // rbx
  UFG::qResourceWarehouse *v24; // rax
  UFG::qResourceData *v25; // rbx
  UFG::qResourceWarehouse *v26; // rax
  UFG::qResourceData *v27; // rbx
  UFG::qResourceWarehouse *v28; // rax
  UFG::qResourceData *v29; // rbx
  UFG::qResourceWarehouse *v30; // rax
  UFG::qResourceData *v31; // rbx
  UFG::qResourceWarehouse *v32; // rax
  UFG::qResourceData *v33; // rbx
  UFG::qResourceWarehouse *v34; // rax
  UFG::qResourceData *v35; // rbx
  UFG::qResourceWarehouse *v36; // rax
  UFG::qResourceData *v37; // rbx
  UFG::qResourceWarehouse *v38; // rax
  UFG::qResourceData *v39; // rbx
  UFG::qResourceWarehouse *v40; // rax

  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "bbDeferredRendering", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbSphericalHarmonic", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDiffuseBlend", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texEmission", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texRealTimeEnvMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texEnvMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texFogCube", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texNoise", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texArcTan", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "sbDepthBiasSortLayer", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbWaterOffset", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texNormal", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDepth", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDepth2", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texCollector", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbMotionblurSettings", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "sbWindSettings", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "sbLitWindows", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texReflection", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texColourCube", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbEnvironmentSettings", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texOcclusion", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texWetSphericalMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texIBLSphericalMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texRipple", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texWetLookMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texShadowAtlas", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texShadowRaw", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texFadeDitherMask", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbShadowTransform", 0);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetailDiffuse0", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetailNormal0", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetailDiffuse1", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetailNormal1", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetailDiffuse2", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDetailNormal2", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texFlowMap", 1);
  Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texAmbientDiffuseMask", 1);
  v0 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilTestFar", 0xC89C1068, 0i64, 0i64, 0i64);
  LODWORD(v0[1].mNode.mParent) = 16973825;
  HIWORD(v0[1].mNode.mParent) = 257;
  v1 = v0;
  *(_DWORD *)((char *)v0[1].mNode.mChild + 6) = 2;
  WORD2(v0[1].mNode.mChild[0]) = 255;
  v2 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v2, v1);
  v3 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilTestNear", 0x9296DD7E, 0i64, 0i64, 0i64);
  LODWORD(v3[1].mNode.mParent) = 34013184;
  HIWORD(v3[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v3[1].mNode.mChild + 5) = 512;
  BYTE4(v3[1].mNode.mChild[0]) = -1;
  BYTE1(v3[1].mNode.mChild[1]) = 0;
  v4 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v4, v3);
  v5 = Illusion::Factory::NewRasterState("Deferred.RasterState.TestSkybox", 0x2ED37D3Bu, 0i64, 0i64, 0i64);
  LODWORD(v5[1].mNode.mParent) = 458752;
  HIWORD(v5[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v5[1].mNode.mChild + 5) = 512;
  BYTE4(v5[1].mNode.mChild[0]) = -1;
  BYTE1(v5[1].mNode.mChild[1]) = 0;
  v6 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v6, v5);
  v7 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilWriteFar", 0x633AF8D7u, 0i64, 0i64, 0i64);
  LODWORD(v7[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v7[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v7[1].mNode.mChild + 6) = 519;
  WORD2(v7[1].mNode.mChild[0]) = 511;
  v8 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v8, v7);
  v9 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilWriteNear", 0xEE1AFF11, 0i64, 0i64, 0i64);
  LODWORD(v9[1].mNode.mParent) = 33751041;
  *(_DWORD *)((char *)&v9[1].mNode.mParent + 6) = 16777473;
  *(_DWORD *)((char *)v9[1].mNode.mChild + 6) = 519;
  WORD2(v9[1].mNode.mChild[0]) = 511;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, v9);
  v11 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilTestFarNoClear", 0x3F6305F7u, 0i64, 0i64, 0i64);
  LODWORD(v11[1].mNode.mParent) = 17235968;
  HIWORD(v11[1].mNode.mParent) = 257;
  *(_WORD *)((char *)v11[1].mNode.mChild + 1) = 511;
  LOBYTE(v11[1].mNode.mChild[0]) = 1;
  *(_DWORD *)((char *)v11[1].mNode.mChild + 6) = 258;
  WORD2(v11[1].mNode.mChild[0]) = -1;
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v12, v11);
  v13 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilTestNearNoClear", 0x5BAB7EB3u, 0i64, 0i64, 0i64);
  LODWORD(v13[1].mNode.mParent) = 34013184;
  HIWORD(v13[1].mNode.mParent) = 257;
  *(_WORD *)((char *)v13[1].mNode.mChild + 1) = 511;
  LOBYTE(v13[1].mNode.mChild[0]) = 1;
  *(_DWORD *)((char *)v13[1].mNode.mChild + 5) = 66303;
  BYTE4(v13[1].mNode.mChild[0]) = -1;
  BYTE1(v13[1].mNode.mChild[1]) = 0;
  v14 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v14, v13);
  v15 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilWriteFarNoClear", 0xF88F7517, 0i64, 0i64, 0i64);
  LODWORD(v15[1].mNode.mParent) = 196609;
  *(_DWORD *)((char *)&v15[1].mNode.mParent + 6) = -16711423;
  *(_DWORD *)((char *)v15[1].mNode.mChild + 6) = 1799;
  WORD2(v15[1].mNode.mChild[0]) = -1;
  WORD1(v15[1].mNode.mChild[1]) = -255;
  *(_DWORD *)((char *)&v15[1].mNode.mChild[1] + 5) = 1543;
  BYTE4(v15[1].mNode.mChild[1]) = -1;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, v15);
  v17 = Illusion::Factory::NewRasterState("Deferred.RasterState.StencilWriteNearNoClear", 0xF4165E2F, 0i64, 0i64, 0i64);
  LODWORD(v17[1].mNode.mParent) = 33947649;
  *(_DWORD *)((char *)&v17[1].mNode.mParent + 6) = -16711423;
  *(_DWORD *)((char *)v17[1].mNode.mChild + 6) = 519;
  WORD2(v17[1].mNode.mChild[0]) = -1;
  v18 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v18, v17);
  v19 = Illusion::Factory::NewRasterState("Deferred.RasterState.ReplaceDepthLE", 0xF8DA24DB, 0i64, 0i64, 0i64);
  LODWORD(v19[1].mNode.mParent) = 196865;
  v20 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v20, v19);
  v21 = Illusion::Factory::NewRasterState("Deferred.RasterState.ReplaceDepthALWAYS", 0xD1FE5B17, 0i64, 0i64, 0i64);
  LODWORD(v21[1].mNode.mParent) = 459009;
  v22 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v22, v21);
  v23 = Illusion::Factory::NewRasterState(
          "Deferred.RasterState.ReplaceDepthDownsampleALWAYS",
          0x12259D1Cu,
          0i64,
          0i64,
          0i64);
  LODWORD(v23[1].mNode.mParent) = 459009;
  v24 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v24, v23);
  v25 = Illusion::Factory::NewRasterState("Deferred.RasterState.IrradianceSkyVolume", 0xF896E1A8, 0i64, 0i64, 0i64);
  LOWORD(v25[1].mNode.mParent) = 1;
  BYTE3(v25[1].mNode.mParent) = 1;
  v26 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v26, v25);
  v27 = Illusion::Factory::NewRasterState("Deferred.RasterState.DisableWriteInvert", 0xCEF1EFD9, 0i64, 0i64, 0i64);
  LODWORD(v27[1].mNode.mParent) = 33947649;
  v28 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v28, v27);
  v29 = Illusion::Factory::NewRasterState("Deferred.RasterState.Highlight", 0x455DCC70u, 0i64, 0i64, 0i64);
  LODWORD(v29[1].mNode.mParent) = 16973825;
  v30 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v30, v29);
  v31 = Illusion::Factory::NewRasterState("Deferred.RasterState.SpotlightLightShaft", 0xD9196A3C, 0i64, 0i64, 0i64);
  LODWORD(v31[1].mNode.mParent) = 34013184;
  v32 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v32, v31);
  v33 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.TrueAdditive", 0xC275D439, 0i64, 0i64, 0i64);
  LOWORD(v33[1].mNode.mParent) = 257;
  BYTE2(v33[1].mNode.mParent) = 1;
  v34 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v34, v33);
  v35 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.AlphaStateTrueMultiply", 0x581F1B0Fu, 0i64, 0i64, 0i64);
  LOWORD(v35[1].mNode.mParent) = 1;
  BYTE2(v35[1].mNode.mParent) = 2;
  v36 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v36, v35);
  v37 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.SourceRGBDestAlpha", 0x5005E9F2u, 0i64, 0i64, 0i64);
  LOWORD(v37[1].mNode.mParent) = 257;
  BYTE2(v37[1].mNode.mParent) = 0;
  LOWORD(v37[1].mNode.mChild[0]) = 1;
  BYTE2(v37[1].mNode.mChild[0]) = 1;
  v38 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v38, v37);
  v39 = Illusion::Factory::NewAlphaState("Deferred.AlphaState.PunchThrough", 0x80EA5501, 0i64, 0i64, 0i64);
  LOBYTE(v39[1].mNode.mParent) = 0;
  BYTE5(v39[1].mNode.mParent) = 0;
  v40 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v40, v39);
}

