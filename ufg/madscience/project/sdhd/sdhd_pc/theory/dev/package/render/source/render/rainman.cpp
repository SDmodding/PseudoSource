// File Line: 33
// RVA: 0x1456C80
__int64 dynamic_initializer_for__Render::RainManager::gRainManager__()
{
  UFG::qResourceHandle::qResourceHandle(&stru_142142F58);
  UFG::qResourceHandle::qResourceHandle(&stru_142142F78);
  UFG::qResourceHandle::qResourceHandle(&stru_142142F98);
  UFG::qResourceHandle::qResourceHandle(&stru_142142FB8);
  UFG::qResourceHandle::qResourceHandle(&stru_142142FE0);
  Assembly::GetRCX(&stru_1421430B8);
  Assembly::GetRCX(&stru_1421432A8);
  unk_1421432F8 = 0;
  unk_1421432FC = (_DWORD)FLOAT_1_0;
  return atexit(dynamic_atexit_destructor_for__Render::RainManager::gRainManager__);
}

// File Line: 37
// RVA: 0x1456E10
__int64 Render::_dynamic_initializer_for__sRainDropTextureUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RainDropSheet", 0xFFFFFFFF);
  sRainDropTextureUID = result;
  return result;
}

// File Line: 38
// RVA: 0x1456DD0
__int64 Render::_dynamic_initializer_for__sRainDropShaderUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HK_Rain", 0xFFFFFFFF);
  sRainDropShaderUID = result;
  return result;
}

// File Line: 40
// RVA: 0x1456D90
__int64 Render::_dynamic_initializer_for__sRainDropMatUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RainManager.RainDropMat", 0xFFFFFFFF);
  sRainDropMatUID = result;
  return result;
}

// File Line: 45
// RVA: 0x1456E30
__int64 Render::_dynamic_initializer_for__sRainDropVertexDeclUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VertexDecl.Rain", 0xFFFFFFFF);
  sRainDropVertexDeclUID = result;
  return result;
}

// File Line: 47
// RVA: 0x1456E80
__int64 Render::_dynamic_initializer_for__sRainSettingsUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("cbRainSettings", 0xFFFFFFFF);
  sRainSettingsUID = result;
  return result;
}

// File Line: 51
// RVA: 0x1456D70
__int64 Render::_dynamic_initializer_for__sRainDropAlphaStateUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32(sRainDropAlphaStateName, 0xFFFFFFFF);
  sRainDropAlphaStateUID = result;
  return result;
}

// File Line: 54
// RVA: 0x1456DB0
__int64 Render::_dynamic_initializer_for__sRainDropRasterStateUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32(sRainDropRasterStateName, 0xFFFFFFFF);
  sRainDropRasterStateUID = result;
  return result;
}

// File Line: 56
// RVA: 0x1456DF0
__int64 Render::_dynamic_initializer_for__sRainDropSplashEffect__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HK_RainSplashBox_Heavy_BEAM_01", 0xFFFFFFFF);
  sRainDropSplashEffect = result;
  return result;
}

// File Line: 58
// RVA: 0x1456E50
__int64 Render::_dynamic_initializer_for__sRainProfilePropertySet__()
{
  UFG::qSymbol::create_from_string(&sRainProfilePropertySet, "default-rain-list");
  return atexit(Render::_dynamic_atexit_destructor_for__sRainProfilePropertySet__);
}

// File Line: 71
// RVA: 0x68010
void __fastcall Render::RainManager::BuildRainDropPrimitive(Render::RainManager *this)
{
  unsigned int v1; // ebx
  Render::RainManager *v2; // r14
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // edi
  float v6; // xmm0_4
  _WORD *v7; // rsi
  __int64 v8; // rbx
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  signed int v12; // eax
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm1_4
  unsigned int v17; // edx
  unsigned int v18; // er8
  __int16 v19; // r8
  unsigned int v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // edx
  int v25; // er8
  __int16 v26; // r8
  unsigned int v27; // edx
  unsigned int v28; // edx
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // xmm1_4
  unsigned int v32; // edx
  int v33; // er8
  __int16 v34; // r8
  unsigned int v35; // edx
  unsigned int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // edx
  unsigned int v39; // edx
  int v40; // er8
  __int16 v41; // r8
  unsigned int v42; // edx
  unsigned int v44; // edx
  __int16 v45; // ax
  char *v46; // rax
  int v47; // [rsp+20h] [rbp-C8h]
  int v48; // [rsp+24h] [rbp-C4h]
  unsigned int v49; // [rsp+28h] [rbp-C0h]
  unsigned int v50; // [rsp+2Ch] [rbp-BCh]
  unsigned int v51; // [rsp+30h] [rbp-B8h]
  char *v52; // [rsp+38h] [rbp-B0h]
  char *v53; // [rsp+40h] [rbp-A8h]
  Render::RainManager *v54; // [rsp+F0h] [rbp+8h]
  int pseed; // [rsp+100h] [rbp+18h]
  int v56; // [rsp+108h] [rbp+20h]

  v54 = this;
  v1 = sRainDropVertexDeclUID;
  v2 = this;
  v3 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mRainDropVertexDecl.mPrev, 0x3E5FDA3Eu, v1, v3);
  v52 = UFG::qMalloc(0x6400ui64, sRainDropVertexBufferName, 0x10ui64);
  v5 = 0;
  v6 = FLOAT_16_0;
  v53 = UFG::qMalloc(0x12C0ui64, sRainDropIndexBufferName, 0x10ui64);
  v49 = 1065353216;
  v50 = 0;
  v7 = v53 + 4;
  v51 = 0;
  v47 = -1860099805;
  v56 = -2128334559;
  pseed = 1699239730;
  v48 = 1966499218;
  v8 = (__int64)(v52 + 24);
  do
  {
    v9 = UFG::qRandom(v6, &pseed);
    v10 = UFG::qRandom(16.0, &v56);
    v11 = UFG::qRandom(16.0, &v47);
    v12 = UFG::qRandom(15, &v48);
    v6 = FLOAT_16_0;
    v13 = v11 + 16.0;
    v14 = v10 + 16.0;
    v15 = v9 + 16.0;
    v16 = (float)v12;
    *(float *)(v8 - 24) = v13;
    *(float *)(v8 - 20) = v14;
    *(float *)(v8 - 16) = v15;
    v17 = COERCE_UNSIGNED_INT((float)v12) & 0x7FFFFFFF;
    v18 = (COERCE_UNSIGNED_INT((float)v12) >> 16) & 0x8000;
    if ( v17 <= 0x47FFEFFF )
    {
      if ( v17 >= 0x38800000 )
        v20 = v17 - 939524096;
      else
        v20 = (COERCE_UNSIGNED_INT((float)v12) & 0x7FFFFF | 0x800000) >> (113 - (v17 >> 23));
      v19 = ((((v20 >> 13) & 1) + v20 + 4095) >> 13) | v18;
    }
    else
    {
      v19 = v18 | 0x7FFF;
    }
    v21 = v49;
    *(_WORD *)(v8 - 12) = v19;
    if ( v21 <= 0x47FFEFFF )
    {
      if ( v21 >= 0x38800000 )
        v23 = v21 - 939524096;
      else
        v23 = (v21 & 0x7FFFFF | 0x800000) >> (113 - (v21 >> 23));
      v22 = (v23 + ((v23 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v22) = 0x7FFF;
    }
    *(_WORD *)(v8 - 10) = v22;
    *(float *)(v8 - 8) = v13;
    *(float *)(v8 - 4) = v14;
    v24 = LODWORD(v16) & 0x7FFFFFFF;
    v25 = (LODWORD(v16) >> 16) & 0x8000;
    *(float *)v8 = v15;
    if ( (LODWORD(v16) & 0x7FFFFFFFu) <= 0x47FFEFFF )
    {
      if ( v24 >= 0x38800000 )
        v27 = v24 - 939524096;
      else
        v27 = (LODWORD(v16) & 0x7FFFFF | 0x800000u) >> (113 - ((LODWORD(v16) & 0x7FFFFFFFu) >> 23));
      v26 = ((((v27 >> 13) & 1) + v27 + 4095) >> 13) | v25;
    }
    else
    {
      v26 = v25 | 0x7FFF;
    }
    v28 = v50;
    *(_WORD *)(v8 + 4) = v26;
    if ( v28 <= 0x47FFEFFF )
    {
      if ( v28 >= 0x38800000 )
        v30 = v28 - 939524096;
      else
        v30 = (v28 & 0x7FFFFF | 0x800000) >> (113 - (v28 >> 23));
      v29 = (v30 + ((v30 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v29) = 0x7FFF;
    }
    *(_WORD *)(v8 + 6) = v29;
    *(float *)(v8 + 8) = v13;
    *(float *)(v8 + 12) = v14;
    *(float *)(v8 + 16) = v15;
    v31 = COERCE_UNSIGNED_INT(v16 + 1.0) ^ _xmm[0];
    v32 = v31 & 0x7FFFFFFF;
    v33 = (v31 >> 16) & 0x8000;
    if ( (v31 & 0x7FFFFFFF) <= 0x47FFEFFF )
    {
      if ( v32 >= 0x38800000 )
        v35 = v32 - 939524096;
      else
        v35 = (v31 & 0x7FFFFF | 0x800000) >> (113 - (v32 >> 23));
      v34 = ((((v35 >> 13) & 1) + v35 + 4095) >> 13) | v33;
    }
    else
    {
      v34 = v33 | 0x7FFF;
    }
    v36 = v51;
    *(_WORD *)(v8 + 20) = v34;
    if ( v36 <= 0x47FFEFFF )
    {
      if ( v36 >= 0x38800000 )
        v38 = v36 - 939524096;
      else
        v38 = (v36 & 0x7FFFFF | 0x800000) >> (113 - (v36 >> 23));
      v37 = (v38 + ((v38 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v37) = 0x7FFF;
    }
    *(_WORD *)(v8 + 22) = v37;
    *(float *)(v8 + 24) = v13;
    *(float *)(v8 + 28) = v14;
    v39 = v31 & 0x7FFFFFFF;
    v40 = (v31 >> 16) & 0x8000;
    *(float *)(v8 + 32) = v15;
    if ( (v31 & 0x7FFFFFFF) <= 0x47FFEFFF )
    {
      if ( v39 >= 0x38800000 )
        v42 = v39 - 939524096;
      else
        v42 = (v31 & 0x7FFFFF | 0x800000) >> (113 - ((v31 & 0x7FFFFFFF) >> 23));
      v41 = ((((v42 >> 13) & 1) + v42 + 4095) >> 13) | v40;
    }
    else
    {
      v41 = v40 | 0x7FFF;
    }
    *(_WORD *)(v8 + 36) = v41;
    v44 = 125829120;
    *(_WORD *)(v8 + 38) = (v44 + ((v44 >> 13) & 1) + 4095) >> 13;
    *(v7 - 2) = v5;
    *(v7 - 1) = v5 + 1;
    v7[3] = v5;
    *v7 = v5 + 2;
    v7[1] = v5 + 2;
    v45 = v5 + 3;
    v5 += 4;
    v7[2] = v45;
    v7 += 6;
    v8 += 64i64;
  }
  while ( v5 < 0x640 );
  v54->mRainDropVertexData = v52;
  v46 = v53;
  v54->mRainDropVertexCount = 1600;
  v54->mRainDropIndexData = v46;
  v54->mRainDropIndexCount = 2400;
}

// File Line: 140
// RVA: 0x689A0
void __fastcall Render::RainManager::InitRainDrops(Render::RainManager *this)
{
  unsigned int v1; // ebx
  Render::RainManager *v2; // rsi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rax
  UFG::qResourceData *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceData *v8; // rax
  UFG::qResourceData *v9; // rbx
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // ebp
  Illusion::Material *v12; // rax
  Illusion::Material *v13; // rdi
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  int v18; // eax
  UFG::qResourceWarehouse *v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  signed __int64 v22; // rbp
  signed __int64 v23; // rbx
  signed __int64 v24; // rdi
  float *v25; // rdi
  float *v26; // rbx
  float v27; // xmm8_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm7_4
  float v32; // xmm6_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  UFG::qVector4 v36; // xmm1
  UFG::qVector4 v37; // xmm2
  UFG::qVector4 v38; // xmm3

  v1 = sRainDropTextureUID;
  v2 = this;
  v3 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mRainDropTexture.mPrev, 0x8B43FABF, v1, v3);
  v5 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Modulated", sRainDropAlphaStateUID, 0i64, 0i64, 0i64);
  LOWORD(v5[1].mNode.mParent) = 1025;
  LOWORD(v5[1].mNode.mChild[0]) = 1792;
  BYTE2(v5[1].mNode.mParent) = 5;
  BYTE2(v5[1].mNode.mChild[0]) = 1;
  v6 = v5;
  v7 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v7, v6);
  v8 = Illusion::Factory::NewRasterState(sRainDropRasterStateName, sRainDropRasterStateUID, 0i64, 0i64, 0i64);
  v9 = v8;
  LOWORD(v8[1].mNode.mParent) = 1;
  BYTE2(v8[1].mNode.mParent) = 3;
  HIWORD(v8[1].mNode.mParent) = 0;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, v9);
  v11 = sRainDropMatUID;
  v12 = Illusion::Factory::NewMaterial(sRainDropMatName, sRainDropMatUID, 5u, 0i64, 0i64, 0i64);
  LODWORD(v9) = sRainDropShaderUID;
  LOWORD(v12[1].mNode.mChild[0]) = 0;
  v13 = v12;
  HIDWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v13[1].mResourceHandles.mNode.mNext) = (_DWORD)v9;
  LODWORD(v9) = sRainDropTextureUID;
  LODWORD(v13[1].mNode.mParent) = v14;
  v13[1].mTypeUID = -1957338719;
  *(_WORD *)&v13[1].mDebugName[12] = 0;
  *(_DWORD *)&v13[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v13[1].mStateBlockMask.mFlags[0]) = (_DWORD)v9;
  LODWORD(v9) = sRainDropAlphaStateUID;
  LODWORD(v13[1].mStateBlockMask.mFlags[1]) = -1958479169;
  *(_DWORD *)&v13[1].mDebugName[4] = v15;
  LOWORD(v13[1].mMaterialUser.mOffset) = 0;
  *(&v13[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v13[2].mNode.mUID = (unsigned int)v9;
  LODWORD(v9) = sRainDropRasterStateUID;
  LODWORD(v13[2].mResourceHandles.mNode.mPrev) = 315097330;
  v13[1].mNumParams = v16;
  LOWORD(v13[2].mTypeUID) = 0;
  HIDWORD(v13[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v13[2].0 + 22) = 1002903008;
  *(_DWORD *)&v13[2].mDebugName[28] = (_DWORD)v9;
  LODWORD(v13[2].mResourceHandles.mNode.mNext) = v17;
  LOWORD(v13[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v13[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("texShadow", 0xFFFFFFFF);
  LODWORD(v13[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v13[2].mStateBlockMask.mFlags[0]) = v18;
  LODWORD(v13[3].mNode.mChild[0]) = 0;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v13->mNode);
  v20 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v20;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mRainDropMaterial.mPrev, 0xB4C26312, v11, v20);
  Render::RainManager::BuildRainDropPrimitive(v2);
  v22 = 16i64;
  v23 = (signed __int64)&v2->mRainDropSeeds;
  v24 = 16i64;
  do
  {
    v23 += 4i64;
    *(float *)(v23 - 4) = UFG::qRandom(0.40000001, &UFG::qDefaultSeed) + 0.60000002;
    --v24;
  }
  while ( v24 );
  *(_QWORD *)&v2->mRainDropStates.mDeltaTime = 0i64;
  v25 = &v2->mRainDropStates.mWindVariance[0].z;
  v26 = &v2->mRainDropStates.mOffset[0].z;
  do
  {
    v27 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    v28 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    v29 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    v30 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    *(v26 - 1) = v29;
    *v26 = v28;
    *(v26 - 2) = v30;
    v26[1] = v27;
    v31 = UFG::qRandom(2.0, &UFG::qDefaultSeed) - 1.0;
    v32 = UFG::qRandom(2.0, &UFG::qDefaultSeed) - 1.0;
    v33 = UFG::qRandom(2.0, &UFG::qDefaultSeed);
    v26 += 4;
    *(v25 - 1) = v32;
    *v25 = v31;
    v25 += 3;
    *(v25 - 5) = v33 - 1.0;
    --v22;
  }
  while ( v22 );
  v2->mDefaultRainParameters.mAlpha = 0.5;
  *(_QWORD *)&v2->mDefaultRainParameters.mWidth = 1017370378i64;
  v2->mDefaultRainParameters.mLength = 1.2;
  v2->mDefaultRainParameters.mSpeed = 20.0;
  v2->mDefaultRainParameters.mAlphaFadeSpeedBegin = 80.0;
  v2->mDefaultRainParameters.mAlphaFadeSpeedEnd = 100.0;
  v2->mRainProfileParameters[0].mLength = v2->mDefaultRainParameters.mLength;
  v2->mRainProfileParameters[0].mSpeed = v2->mDefaultRainParameters.mSpeed;
  v2->mRainProfileParameters[0].mAlpha = v2->mDefaultRainParameters.mAlpha;
  v2->mRainProfileParameters[0].mWidth = v2->mDefaultRainParameters.mWidth;
  v2->mRainProfileParameters[0].mDensity = v2->mDefaultRainParameters.mDensity;
  v2->mRainProfileParameters[0].mAlphaFadeSpeedBegin = v2->mDefaultRainParameters.mAlphaFadeSpeedBegin;
  v2->mRainProfileParameters[0].mAlphaFadeSpeedEnd = v2->mDefaultRainParameters.mAlphaFadeSpeedEnd;
  v2->mRainProfileParameters[1].mLength = v2->mDefaultRainParameters.mLength;
  v2->mRainProfileParameters[1].mSpeed = v2->mDefaultRainParameters.mSpeed;
  v2->mRainProfileParameters[1].mAlpha = v2->mDefaultRainParameters.mAlpha;
  v2->mRainProfileParameters[1].mWidth = v2->mDefaultRainParameters.mWidth;
  v2->mRainProfileParameters[1].mDensity = v2->mDefaultRainParameters.mDensity;
  v2->mRainProfileParameters[1].mAlphaFadeSpeedBegin = v2->mDefaultRainParameters.mAlphaFadeSpeedBegin;
  v2->mRainProfileParameters[1].mAlphaFadeSpeedEnd = v2->mDefaultRainParameters.mAlphaFadeSpeedEnd;
  v2->mRainProfileParameters[2].mLength = v2->mDefaultRainParameters.mLength;
  v2->mRainProfileParameters[2].mSpeed = v2->mDefaultRainParameters.mSpeed;
  v2->mRainProfileParameters[2].mAlpha = v2->mDefaultRainParameters.mAlpha;
  v2->mRainProfileParameters[2].mWidth = v2->mDefaultRainParameters.mWidth;
  v2->mRainProfileParameters[2].mDensity = v2->mDefaultRainParameters.mDensity;
  v2->mRainProfileParameters[2].mAlphaFadeSpeedBegin = v2->mDefaultRainParameters.mAlphaFadeSpeedBegin;
  v2->mRainProfileParameters[2].mAlphaFadeSpeedEnd = v2->mDefaultRainParameters.mAlphaFadeSpeedEnd;
  v2->mRainEnabled = 1;
  v34 = UFG::qVector3::msZero.y;
  v35 = UFG::qVector3::msZero.z;
  v2->mPreviousCameraPosition.x = UFG::qVector3::msZero.x;
  v2->mPreviousCameraPosition.y = v34;
  v2->mPreviousCameraPosition.z = v35;
  v36 = UFG::qMatrix44::msIdentity.v1;
  v37 = UFG::qMatrix44::msIdentity.v2;
  v38 = UFG::qMatrix44::msIdentity.v3;
  v2->mPreviousWorldViewProjMatrix.v0 = UFG::qMatrix44::msIdentity.v0;
  v2->mPreviousWorldViewProjMatrix.v1 = v36;
  v2->mPreviousWorldViewProjMatrix.v2 = v37;
  v2->mPreviousWorldViewProjMatrix.v3 = v38;
}

// File Line: 256
// RVA: 0x68FB0
void __fastcall Render::RainManager::LoadRainProfiles(Render::RainManager *this)
{
  Render::RainManager *v1; // rbx
  UFG::qPropertySet *v2; // rdi
  UFG::qPropertyList *v3; // r14
  unsigned int v4; // ebp
  char *v5; // rax
  UFG::qPropertySet *v6; // rdi
  unsigned int v7; // eax
  UFG::qSymbol *v8; // rcx
  signed __int64 v9; // rsi
  float *v10; // rax
  float *v11; // rax
  float *v12; // rax
  float *v13; // rax
  float *v14; // rax
  float *v15; // rax
  float *v16; // rax
  UFG::qSymbol v17; // [rsp+20h] [rbp-58h]
  UFG::qSymbol v18; // [rsp+24h] [rbp-54h]
  UFG::qSymbol v19; // [rsp+28h] [rbp-50h]
  UFG::qSymbol v20; // [rsp+2Ch] [rbp-4Ch]
  UFG::qSymbol v21; // [rsp+30h] [rbp-48h]
  __int64 v22; // [rsp+38h] [rbp-40h]
  UFG::qSymbol ptr; // [rsp+40h] [rbp-38h]
  UFG::qSymbol v24; // [rsp+44h] [rbp-34h]
  UFG::qSymbol v25; // [rsp+48h] [rbp-30h]
  UFG::qSymbol name; // [rsp+88h] [rbp+10h]
  UFG::qSymbol result; // [rsp+90h] [rbp+18h]
  UFG::qSymbol v28; // [rsp+98h] [rbp+20h]

  v22 = -2i64;
  v1 = this;
  UFG::qSymbol::create_from_string(&result, "Length");
  UFG::qSymbol::create_from_string(&v28, "Speed");
  UFG::qSymbol::create_from_string(&v17, "Alpha");
  UFG::qSymbol::create_from_string(&v18, "Width");
  UFG::qSymbol::create_from_string(&v19, "Density");
  UFG::qSymbol::create_from_string(&v20, "AlphaFadeSpeedBegin");
  UFG::qSymbol::create_from_string(&v21, "AlphaFadeSpeedEnd");
  UFG::qSymbol::create_from_string(&ptr, "Light");
  UFG::qSymbol::create_from_string(&v24, "Medium");
  UFG::qSymbol::create_from_string(&v25, "Heavy");
  v2 = UFG::PropertySetManager::GetPropertySet(&sRainProfilePropertySet);
  if ( v2 )
  {
    UFG::qSymbol::create_from_string(&name, "RainList");
    v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &name, DEPTH_RECURSE);
    v4 = 0;
    if ( v3->mNumElements )
    {
      do
      {
        v5 = UFG::qPropertyList::GetValuePtr(v3, 0x1Au, v4);
        if ( v5 && *(_QWORD *)v5 )
          v6 = (UFG::qPropertySet *)&v5[*(_QWORD *)v5];
        else
          v6 = 0i64;
        v7 = 0;
        v8 = &ptr;
        while ( v6->mName.mUID != v8->mUID )
        {
          ++v7;
          ++v8;
          if ( v7 >= 3 )
            goto LABEL_26;
        }
        v9 = v7;
        v10 = UFG::qPropertySet::Get<float>(v6, &result, DEPTH_RECURSE);
        if ( !v10 )
          v10 = &v1->mDefaultRainParameters.mLength;
        v1->mRainProfileParameters[v9].mLength = *v10;
        v11 = UFG::qPropertySet::Get<float>(v6, &v28, DEPTH_RECURSE);
        if ( !v11 )
          v11 = &v1->mDefaultRainParameters.mSpeed;
        v1->mRainProfileParameters[v9].mSpeed = *v11;
        v12 = UFG::qPropertySet::Get<float>(v6, &v17, DEPTH_RECURSE);
        if ( !v12 )
          v12 = &v1->mDefaultRainParameters.mAlpha;
        v1->mRainProfileParameters[v9].mAlpha = *v12;
        v13 = UFG::qPropertySet::Get<float>(v6, &v18, DEPTH_RECURSE);
        if ( !v13 )
          v13 = &v1->mDefaultRainParameters.mWidth;
        v1->mRainProfileParameters[v9].mWidth = *v13;
        v14 = UFG::qPropertySet::Get<float>(v6, &v19, DEPTH_RECURSE);
        if ( !v14 )
          v14 = &v1->mDefaultRainParameters.mDensity;
        v1->mRainProfileParameters[v9].mDensity = *v14;
        v15 = UFG::qPropertySet::Get<float>(v6, &v20, DEPTH_RECURSE);
        if ( !v15 )
          v15 = &v1->mDefaultRainParameters.mAlphaFadeSpeedBegin;
        v1->mRainProfileParameters[v9].mAlphaFadeSpeedBegin = *v15;
        v16 = UFG::qPropertySet::Get<float>(v6, &v21, DEPTH_RECURSE);
        if ( !v16 )
          v16 = &v1->mDefaultRainParameters.mAlphaFadeSpeedEnd;
        v1->mRainProfileParameters[v9].mAlphaFadeSpeedEnd = *v16;
LABEL_26:
        ++v4;
      }
      while ( v4 < v3->mNumElements );
    }
  }
  `eh vector destructor iterator(&ptr, 4ui64, 3, (void (__fastcall *)(void *))_);
}

// File Line: 314
// RVA: 0x688E0
void __fastcall Render::RainManager::Init(Render::RainManager *this)
{
  Render::RainManager *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  char *v3; // rax
  UFG::TransformNodeComponent *v4; // rdi
  unsigned int v5; // eax

  v1 = this;
  Render::RainManager::InitRainDrops(this);
  Render::RainManager::LoadRainProfiles(v1);
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x110ui64, "RainManager::mRainDropSplashEffectTransform", 0i64, 1u);
  v4 = (UFG::TransformNodeComponent *)v3;
  if ( v3 )
  {
    v5 = UFG::qStringHashUpper32("RainDropSplashEffectTransform", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent(v4, v5, 0i64, 0);
  }
  v1->mRainDropSplashEffectTransform = (UFG::TransformNodeComponent *)v3;
  v1->mStateblockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             sRainSettingsUID,
                                             sRainSettingsName,
                                             0);
  v1->mCurrentRainProfile = &v1->mDefaultRainParameters;
}

// File Line: 329
// RVA: 0x68650
void __fastcall Render::RainManager::Close(Render::RainManager *this)
{
  Render::RainManager *v1; // rbx
  UFG::TransformNodeComponent *v2; // rcx

  v1 = this;
  Render::FXManager::KillEffect(&Render::gFXManager, this->mRainDropSplashEffectID, 0);
  v2 = v1->mRainDropSplashEffectTransform;
  v1->mRainDropSplashEffectID = 0;
  if ( v2 )
    v2->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 1u);
  v1->mRainDropSplashEffectTransform = 0i64;
}

// File Line: 338
// RVA: 0x69970
void __fastcall Render::RainManager::UpdateRainDrops(Render::RainManager *this, float delta_time)
{
  Render::RainDropParameters *v2; // rax
  Render::RainManager *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  unsigned int v6; // eax
  unsigned int v7; // er8
  float *v8; // rdx
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm0_4

  v2 = this->mCurrentRainProfile;
  this->mRainDropStates.mDeltaTime = delta_time;
  v3 = this;
  v4 = v2->mDensity;
  if ( v4 == 0.0 )
  {
    v5 = FLOAT_16_0;
    this->mRainDropStates.mNumActivePasses = (signed int)(float)((float)((float)(UFG::TimeOfDayManager::GetInstance()->m_WeatherState
                                                                               - 1.0)
                                                                       * 16.0)
                                                               + 0.99900001);
  }
  else
  {
    v5 = FLOAT_16_0;
    this->mRainDropStates.mNumActivePasses = (signed int)(float)((float)(v4 * 16.0) + 0.99900001);
  }
  v6 = v3->mRainDropStates.mNumActivePasses;
  if ( v6 )
  {
    v7 = 0;
    if ( v6 )
    {
      do
      {
        v8 = (float *)(&v3->mStateblockIndex + 4 * (v7 + 35i64));
        v9 = *v8;
        v8[2] = (float)((float)(v3->mCurrentRainProfile->mSpeed * v3->mRainDropStates.mDeltaTime)
                      * v3->mRainDropSeeds.mSpeedScale[v7])
              + v8[2];
        if ( v9 <= v5 )
        {
          if ( v9 < 0.0 )
            *v8 = 16.0;
        }
        else
        {
          *v8 = 0.0;
        }
        v10 = v8[1];
        if ( v10 <= v5 )
        {
          if ( v10 < 0.0 )
            v8[1] = 16.0;
        }
        else
        {
          v8[1] = 0.0;
        }
        v11 = v8[2];
        if ( v11 <= v5 )
        {
          if ( v11 < 0.0 )
            v8[2] = 16.0;
        }
        else
        {
          v8[2] = 0.0;
        }
        ++v7;
      }
      while ( v7 < v3->mRainDropStates.mNumActivePasses );
    }
  }
}

// File Line: 382
// RVA: 0x69270
void __fastcall Render::RainManager::SetRainDropConstants(Render::RainManager *this, CB_RainSettings *cb_rain_settings, Render::View *view, const float time, const unsigned int pass)
{
  __m128 v5; // xmm2
  Render::ViewSettings *v6; // rbp
  Render::View *v7; // rsi
  CB_RainSettings *v8; // rdi
  Render::RainManager *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm12_4
  Render::RainDropParameters *v12; // rax
  float v13; // xmm11_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  __int64 v16; // r14
  float v17; // xmm2_4
  float v18; // xmm13_4
  float v19; // xmm15_4
  float v20; // xmm14_4
  float v21; // xmm1_4
  signed __int64 v22; // rax
  float v23; // xmm3_4
  float v24; // xmm7_4
  float v25; // xmm9_4
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  UFG::TimeOfDayManager *v29; // rax
  __m128 v30; // xmm2
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  UFG::qVector4 v40; // xmm3
  UFG::qVector4 v41; // xmm2
  UFG::qVector4 v42; // xmm1
  UFG::qVector4 v43; // xmm3
  UFG::qVector4 v44; // xmm2
  UFG::qVector4 v45; // xmm1
  UFG::qVector4 v46; // xmm2
  UFG::qVector4 v47; // xmm1
  UFG::qVector4 v48; // xmm3
  float v49; // xmm0_4
  UFG::qVector3 direction; // [rsp+20h] [rbp-C8h]
  float v51; // [rsp+108h] [rbp+20h]

  v5 = (__m128)LODWORD(this->mPreviousCameraPosition.x);
  v6 = view->mSettings;
  v7 = view;
  v8 = cb_rain_settings;
  v9 = this;
  v10 = this->mPreviousCameraPosition.y - view->mViewWorld.v3.y;
  v11 = time;
  v12 = this->mCurrentRainProfile;
  v13 = 0.0;
  v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - view->mViewWorld.v3.x)
                                 * (float)(v5.m128_f32[0] - view->mViewWorld.v3.x))
                         + (float)(v10 * v10))
                 + (float)((float)(this->mPreviousCameraPosition.z - view->mViewWorld.v3.z)
                         * (float)(this->mPreviousCameraPosition.z - view->mViewWorld.v3.z));
  v14 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v5)) * (float)(1.0 / time)) - v12->mAlphaFadeSpeedBegin)
      / v12->mAlphaFadeSpeedEnd;
  if ( v14 <= 0.0 )
  {
    v14 = 0.0;
  }
  else if ( v14 >= 1.0 )
  {
    v14 = *(float *)&FLOAT_1_0;
  }
  if ( Render::gFXManager.mRenderRainWhileInside )
    v15 = *(float *)&FLOAT_1_0;
  else
    v15 = this->mRainInteriorBlend;
  v16 = pass;
  v17 = (float)(v6->mProjection.v1.y * 0.56232184) * v12->mWidth;
  v18 = (float)(1.0 - v14) * v15;
  v19 = v6->mWorldView.v1.z * -8.0;
  v20 = v6->mWorldView.v0.z * -8.0;
  v21 = v12->mLength / v12->mSpeed;
  v22 = 2 * (pass + 35i64);
  v23 = v6->mWorldView.v2.z;
  cb_rain_settings->SizeScale[0] = v17;
  *(_QWORD *)&cb_rain_settings->SizeScale[2] = 0i64;
  cb_rain_settings->SizeScale[1] = v21 * (float)(1.0 / v11);
  v51 = v23 * -8.0;
  v24 = (float)(*((float *)&this->mStateblockIndex + 2 * v22 + 1) + view->mViewWorld.v3.y) + v19;
  v25 = (float)(*((float *)&this->mRainDropTexture.mPrev + 2 * v22) + view->mViewWorld.v3.z) + (float)(v23 * -8.0);
  v26 = fmodf((float)(*((float *)&this->mStateblockIndex + 2 * v22) + view->mViewWorld.v3.x) + v20, 16.0);
  v27 = fmodf(v24, 16.0);
  v28 = fmodf(v25, 16.0);
  v8->PositionOffset[0] = v26;
  v8->PositionOffset[1] = v27;
  v8->PositionOffset[3] = 0.0;
  v8->PositionOffset[2] = v28;
  v29 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetWind(v29, &direction, (float *)&pass);
  v30 = (__m128)LODWORD(direction.x);
  v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(direction.y * direction.y))
                  + (float)(direction.z * direction.z);
  if ( v30.m128_f32[0] != 0.0 )
    v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
  v31 = v9->mRainDropSeeds.mSpeedScale[v16];
  v32 = v9->mCurrentRainProfile->mSpeed;
  v33 = v9->mRainDropSeeds.mSpeedScale[v16];
  v34 = (float)(gRainWindVarianceScalar * v9->mRainDropStates.mWindVariance[v16].x) + 1.0;
  v35 = gRainWindVarianceScalar * v9->mRainDropStates.mWindVariance[v16].y;
  v36 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(direction.x * v13) ^ _xmm[0]) * *(float *)&pass) * gRainWindScalar;
  v37 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(direction.y * v13) ^ _xmm[0]) * *(float *)&pass) * gRainWindScalar;
  v8->Velocity[3] = 0.0;
  v8->Velocity[0] = (float)((float)(v34 * (float)(v33 * v36)) * v32) * v11;
  v8->Velocity[2] = (float)(v32 * v31) * v11;
  v8->Velocity[1] = (float)((float)((float)(v35 + 1.0) * (float)(v31 * v37)) * v32) * v11;
  if ( Render::gFXManager.mRenderRainWhileInside )
    v38 = v9->mRainIndoorAlphaOverride;
  else
    v38 = v9->mCurrentRainProfile->mAlpha;
  v39 = v38 * v18;
  v8->Alpha[0] = v39;
  v8->Alpha[1] = v39;
  v8->Alpha[2] = v39;
  v8->Alpha[3] = v39;
  v40 = v9->mPreviousWorldViewProjMatrix.v1;
  v41 = v9->mPreviousWorldViewProjMatrix.v2;
  v42 = v9->mPreviousWorldViewProjMatrix.v3;
  *(UFG::qVector4 *)v8->PreviousWorldViewProj = v9->mPreviousWorldViewProjMatrix.v0;
  *(UFG::qVector4 *)&v8->PreviousWorldViewProj[4] = v40;
  *(UFG::qVector4 *)&v8->PreviousWorldViewProj[8] = v41;
  *(UFG::qVector4 *)&v8->PreviousWorldViewProj[12] = v42;
  v43 = v7->mWorldViewProjection.v1;
  v44 = v7->mWorldViewProjection.v2;
  v45 = v7->mWorldViewProjection.v3;
  *(UFG::qVector4 *)v8->WorldViewProj = v7->mWorldViewProjection.v0;
  *(UFG::qVector4 *)&v8->WorldViewProj[4] = v43;
  *(UFG::qVector4 *)&v8->WorldViewProj[8] = v44;
  *(UFG::qVector4 *)&v8->WorldViewProj[12] = v45;
  v46 = v6->mWorldView.v2;
  v47 = v6->mWorldView.v3;
  v48 = v6->mWorldView.v1;
  *(UFG::qVector4 *)v8->WorldView = v6->mWorldView.v0;
  *(UFG::qVector4 *)&v8->WorldView[4] = v48;
  *(UFG::qVector4 *)&v8->WorldView[8] = v46;
  *(UFG::qVector4 *)&v8->WorldView[12] = v47;
  v8->ParticleBoxSize[0] = 16.0;
  v8->ParticleBoxSize[1] = 16.0;
  v8->ParticleBoxSize[2] = 16.0;
  v8->ParticleBoxSize[3] = 16.0;
  v49 = v7->mViewWorld.v3.x;
  v47.x = v7->mViewWorld.v3.y;
  v46.x = v7->mViewWorld.v3.z;
  v8->ViewPosition[3] = 0.0;
  v8->ViewPosition[0] = v49;
  v8->ViewPosition[1] = v47.x;
  v8->ViewPosition[2] = v46.x;
  v8->Forward[0] = v20;
  v8->Forward[1] = v19;
  v8->Forward[3] = 1.0;
  v8->Forward[2] = v51;
}

// File Line: 445
// RVA: 0x69750
void __fastcall Render::RainManager::Update(Render::RainManager *this, float deltaT, UFG::qMatrix44 *world_view)
{
  UFG::qMatrix44 *v3; // rdi
  Render::RainManager *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm6_4
  float v8; // xmm1_4
  signed __int64 v9; // rax
  UFG::TransformNodeComponent *v10; // rcx
  unsigned int v11; // edx
  UFG::qVector3 pos; // [rsp+30h] [rbp-78h]
  UFG::qMatrix44 d; // [rsp+40h] [rbp-68h]

  v3 = world_view;
  v4 = this;
  v5 = UFG::RenderWorld::msStageEnvMap->mInteriorBlend * 2.0;
  if ( v5 >= 1.0 )
    v5 = *(float *)&FLOAT_1_0;
  this->mRainInteriorBlend = v5;
  if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0
    && (Render::gFXManager.mRenderRainWhileInside || v4->mRainInteriorBlend > 0.0000099999997) )
  {
    Render::RainManager::UpdateRainDrops(v4, deltaT);
    if ( gOverrideRainProfile )
    {
      v9 = (signed __int64)&v4->mDefaultRainParameters;
    }
    else
    {
      if ( Render::gFXManager.mRenderRainWhileInside )
        v6 = *(float *)&FLOAT_1_0;
      else
        v6 = v4->mRainInteriorBlend;
      v7 = v6 * UFG::TimeOfDayManager::GetInstance()->m_WeatherState;
      v8 = v7 - 2.0;
      if ( (float)(v7 - 2.0) < 0.0 )
        LODWORD(v8) ^= _xmm[0];
      if ( v8 >= 0.001 )
      {
        if ( v7 <= 1.5 )
          v9 = (signed __int64)v4->mRainProfileParameters;
        else
          v9 = (signed __int64)&v4->mRainProfileParameters[1];
      }
      else
      {
        v9 = (signed __int64)&v4->mRainProfileParameters[2];
      }
    }
    v4->mCurrentRainProfile = (Render::RainDropParameters *)v9;
    UFG::qInverseAffine(&d, v3);
    v10 = v4->mRainDropSplashEffectTransform;
    pos.x = d.v3.x + (float)(COERCE_FLOAT(LODWORD(d.v2.x) ^ _xmm[0]) * Render::RainManager::sSplashEffectDistance);
    pos.y = d.v3.y + (float)(COERCE_FLOAT(LODWORD(d.v2.y) ^ _xmm[0]) * Render::RainManager::sSplashEffectDistance);
    pos.z = d.v3.z + (float)(COERCE_FLOAT(LODWORD(d.v2.z) ^ _xmm[0]) * Render::RainManager::sSplashEffectDistance);
    UFG::TransformNodeComponent::SetWorldTranslation(v10, &pos);
    if ( !v4->mRainDropSplashEffectID )
      v4->mRainDropSplashEffectID = Render::FXManager::CreateEffect(
                                      &Render::gFXManager,
                                      sRainDropSplashEffect,
                                      v4->mRainDropSplashEffectTransform,
                                      0xFFFFFFFF,
                                      0i64);
  }
  else
  {
    v11 = v4->mRainDropSplashEffectID;
    if ( v11 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v11, 0);
      v4->mRainDropSplashEffectID = 0;
    }
  }
}

// File Line: 498
// RVA: 0x686A0
void __fastcall Render::RainManager::Draw(Render::RainManager *this, UFG::RenderContext *render_context, Render::View *view, float delta_time)
{
  Render::View *v4; // rsi
  float v5; // xmm7_4
  UFG::RenderContext *v6; // rdi
  Render::RainManager *v7; // rbx
  Illusion::Primitive *v8; // rax
  int v9; // er9
  void *v10; // r8
  int num_indices; // ST30_4
  void *indices; // rcx
  UFG::qResourceData *v13; // rbp
  unsigned int v14; // er8
  unsigned int v15; // edi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  _WORD *v17; // rax
  char *v18; // rax
  char *v19; // rbp
  float v20; // xmm3_4
  unsigned int v21; // er14
  Illusion::StateValues *v22; // rax
  UFG::qVector4 v23; // xmm1
  UFG::qVector4 v24; // xmm3
  UFG::qVector4 v25; // xmm2
  float v26; // eax

  v4 = view;
  v5 = delta_time;
  v6 = render_context;
  v7 = this;
  if ( this->mRainEnabled && UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 && v7->mRainDropSplashEffectID )
  {
    v8 = Illusion::Primitive::Create("RainDrops");
    v9 = v7->mRainDropVertexCount;
    v10 = v7->mRainDropVertexData;
    num_indices = v7->mRainDropIndexCount;
    indices = v7->mRainDropIndexData;
    v7->mRainDropPrimitive = v8;
    Illusion::Primitive::SetBuffers(
      v8,
      TRIANGLELIST,
      v10,
      v9,
      (Illusion::VertexDecl *)v7->mRainDropVertexDecl.mData,
      indices,
      num_indices,
      1);
    v13 = v7->mRainDropMaterial.mData;
    v14 = v6->mHeightmapShadowTextureAlias->mNode.mUID;
    v15 = 0;
    if ( LODWORD(v13[4].mResourceHandles.mNode.mNext) != v14 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v13[4].mNode.mChild[1], v13[4].mTypeUID, v14);
      v16 = v13[1].mResourceHandles.mNode.mPrev;
      if ( v16 )
        v17 = (_WORD *)((char *)&v16[7].mNext + (_QWORD)v13);
      else
        v17 = 0i64;
      *v17 |= 0x20u;
    }
    if ( v7->mRainDropStates.mNumActivePasses > 0 )
    {
      do
      {
        v18 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x140u, 0x10u);
        v19 = v18;
        if ( v5 <= 0.033 )
          v20 = FLOAT_0_033;
        else
          v20 = v5;
        Render::RainManager::SetRainDropConstants(v7, (CB_RainSettings *)v18, v4, v20, v15);
        v21 = SLOWORD(v7->mStateblockIndex);
        v22 = Render::View::GetStateValues(v4);
        if ( v21 >= 0x40 )
          v22->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v21 - 64);
        else
          v22->mSetValueMask.mFlags[0] |= 1i64 << v21;
        v22->mParamValues[(signed __int16)v21] = v19;
        Render::View::Draw(
          v4,
          v7->mRainDropPrimitive,
          (Illusion::Material *)v7->mRainDropMaterial.mData,
          &UFG::qMatrix44::msIdentity);
        ++v15;
      }
      while ( v15 < v7->mRainDropStates.mNumActivePasses );
    }
    v23 = v4->mWorldViewProjection.v3;
    v24 = v4->mWorldViewProjection.v1;
    v25 = v4->mWorldViewProjection.v2;
    v7->mPreviousWorldViewProjMatrix.v0 = v4->mWorldViewProjection.v0;
    v7->mPreviousWorldViewProjMatrix.v1 = v24;
    v7->mPreviousWorldViewProjMatrix.v2 = v25;
    v7->mPreviousWorldViewProjMatrix.v3 = v23;
    v26 = v4->mViewWorld.v3.x;
    v23.x = v4->mViewWorld.v3.z;
    v7->mPreviousCameraPosition.y = v4->mViewWorld.v3.y;
    v7->mPreviousCameraPosition.x = v26;
    v7->mPreviousCameraPosition.z = v23.x;
  }
}

