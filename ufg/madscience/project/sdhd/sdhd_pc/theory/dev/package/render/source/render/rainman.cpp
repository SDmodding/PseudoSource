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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::RainManager::gRainManager__);
}

// File Line: 37
// RVA: 0x1456E10
__int64 Render::_dynamic_initializer_for__sRainDropTextureUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RainDropSheet", -1);
  sRainDropTextureUID = result;
  return result;
}

// File Line: 38
// RVA: 0x1456DD0
__int64 Render::_dynamic_initializer_for__sRainDropShaderUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HK_Rain", -1);
  sRainDropShaderUID = result;
  return result;
}

// File Line: 40
// RVA: 0x1456D90
__int64 Render::_dynamic_initializer_for__sRainDropMatUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RainManager.RainDropMat", -1);
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

  result = UFG::qStringHashUpper32("HK_RainSplashBox_Heavy_BEAM_01", -1);
  sRainDropSplashEffect = result;
  return result;
}

// File Line: 58
// RVA: 0x1456E50
__int64 Render::_dynamic_initializer_for__sRainProfilePropertySet__()
{
  UFG::qSymbol::create_from_string(&sRainProfilePropertySet, "default-rain-list");
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__sRainProfilePropertySet__);
}

// File Line: 71
// RVA: 0x68010
void __fastcall Render::RainManager::BuildRainDropPrimitive(Render::RainManager *this)
{
  unsigned int v1; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // edi
  float v6; // xmm0_4
  _WORD *v7; // rsi
  char *v8; // rbx
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm1_4
  unsigned int v16; // edx
  int v17; // r8d
  __int16 v18; // r8
  unsigned int v19; // edx
  unsigned int v20; // edx
  unsigned int v21; // eax
  unsigned int v22; // edx
  unsigned int v23; // edx
  int v24; // r8d
  __int16 v25; // r8
  unsigned int v26; // edx
  unsigned int v27; // edx
  unsigned int v28; // eax
  unsigned int v29; // edx
  unsigned int v30; // xmm1_4
  unsigned int v31; // edx
  int v32; // r8d
  __int16 v33; // r8
  unsigned int v34; // edx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  int v39; // r8d
  __int16 v40; // r8
  unsigned int v41; // edx
  __int16 v42; // ax
  char *v43; // rax
  int v44; // [rsp+20h] [rbp-C8h] BYREF
  int v45; // [rsp+24h] [rbp-C4h] BYREF
  unsigned int v46; // [rsp+28h] [rbp-C0h]
  unsigned int v47; // [rsp+2Ch] [rbp-BCh]
  unsigned int v48; // [rsp+30h] [rbp-B8h]
  char *v49; // [rsp+38h] [rbp-B0h]
  char *v50; // [rsp+40h] [rbp-A8h]
  int pseed; // [rsp+100h] [rbp+18h] BYREF
  int v53; // [rsp+108h] [rbp+20h] BYREF

  v1 = sRainDropVertexDeclUID;
  Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mRainDropVertexDecl, 0x3E5FDA3Eu, v1, Inventory);
  v49 = UFG::qMalloc(0x6400ui64, sRainDropVertexBufferName, 0x10ui64);
  v5 = 0;
  v6 = FLOAT_16_0;
  v50 = UFG::qMalloc(0x12C0ui64, sRainDropIndexBufferName, 0x10ui64);
  v46 = 1065353216;
  v47 = 0;
  v7 = v50 + 4;
  v48 = 0;
  v44 = -1860099805;
  v53 = -2128334559;
  pseed = 1699239730;
  v45 = 1966499218;
  v8 = v49 + 24;
  do
  {
    v9 = UFG::qRandom(v6, &pseed);
    v10 = UFG::qRandom(16.0, &v53);
    v11 = UFG::qRandom(16.0, &v44);
    v6 = FLOAT_16_0;
    v12 = v11 + 16.0;
    v13 = v10 + 16.0;
    v14 = v9 + 16.0;
    v15 = (float)UFG::qRandom(15, &v45);
    *((float *)v8 - 6) = v12;
    *((float *)v8 - 5) = v13;
    *((float *)v8 - 4) = v14;
    v16 = fabs(v15);
    v17 = HIWORD(LODWORD(v15)) & 0x8000;
    if ( v16 <= 0x47FFEFFF )
    {
      if ( v16 >= 0x38800000 )
        v19 = v16 - 939524096;
      else
        v19 = (LODWORD(v15) & 0x7FFFFF | 0x800000u) >> (113 - (v16 >> 23));
      v18 = ((((v19 >> 13) & 1) + v19 + 4095) >> 13) | v17;
    }
    else
    {
      v18 = v17 | 0x7FFF;
    }
    v20 = v46;
    *((_WORD *)v8 - 6) = v18;
    if ( v20 <= 0x47FFEFFF )
    {
      if ( v20 >= 0x38800000 )
        v22 = v20 - 939524096;
      else
        v22 = (v20 & 0x7FFFFF | 0x800000) >> (113 - (v20 >> 23));
      v21 = (v22 + ((v22 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v21) = 0x7FFF;
    }
    *((_WORD *)v8 - 5) = v21;
    *((float *)v8 - 2) = v12;
    *((float *)v8 - 1) = v13;
    v23 = LODWORD(v15) & 0x7FFFFFFF;
    v24 = HIWORD(LODWORD(v15)) & 0x8000;
    *(float *)v8 = v14;
    if ( (LODWORD(v15) & 0x7FFFFFFFu) <= 0x47FFEFFF )
    {
      if ( v23 >= 0x38800000 )
        v26 = v23 - 939524096;
      else
        v26 = (LODWORD(v15) & 0x7FFFFF | 0x800000u) >> (113 - ((LODWORD(v15) & 0x7FFFFFFFu) >> 23));
      v25 = ((((v26 >> 13) & 1) + v26 + 4095) >> 13) | v24;
    }
    else
    {
      v25 = v24 | 0x7FFF;
    }
    v27 = v47;
    *((_WORD *)v8 + 2) = v25;
    if ( v27 <= 0x47FFEFFF )
    {
      if ( v27 >= 0x38800000 )
        v29 = v27 - 939524096;
      else
        v29 = (v27 & 0x7FFFFF | 0x800000) >> (113 - (v27 >> 23));
      v28 = (v29 + ((v29 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v28) = 0x7FFF;
    }
    *((_WORD *)v8 + 3) = v28;
    *((float *)v8 + 2) = v12;
    *((float *)v8 + 3) = v13;
    *((float *)v8 + 4) = v14;
    v30 = COERCE_UNSIGNED_INT(v15 + 1.0) ^ _xmm[0];
    v31 = v30 & 0x7FFFFFFF;
    v32 = HIWORD(v30) & 0x8000;
    if ( (v30 & 0x7FFFFFFF) <= 0x47FFEFFF )
    {
      if ( v31 >= 0x38800000 )
        v34 = v31 - 939524096;
      else
        v34 = (v30 & 0x7FFFFF | 0x800000) >> (113 - (v31 >> 23));
      v33 = ((((v34 >> 13) & 1) + v34 + 4095) >> 13) | v32;
    }
    else
    {
      v33 = v32 | 0x7FFF;
    }
    v35 = v48;
    *((_WORD *)v8 + 10) = v33;
    if ( v35 <= 0x47FFEFFF )
    {
      if ( v35 >= 0x38800000 )
        v37 = v35 - 939524096;
      else
        v37 = (v35 & 0x7FFFFF | 0x800000) >> (113 - (v35 >> 23));
      v36 = (v37 + ((v37 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v36) = 0x7FFF;
    }
    *((_WORD *)v8 + 11) = v36;
    *((float *)v8 + 6) = v12;
    *((float *)v8 + 7) = v13;
    v38 = v30 & 0x7FFFFFFF;
    v39 = HIWORD(v30) & 0x8000;
    *((float *)v8 + 8) = v14;
    if ( (v30 & 0x7FFFFFFF) <= 0x47FFEFFF )
    {
      if ( v38 >= 0x38800000 )
        v41 = v38 - 939524096;
      else
        v41 = (v30 & 0x7FFFFF | 0x800000) >> (113 - ((v30 & 0x7FFFFFFF) >> 23));
      v40 = ((((v41 >> 13) & 1) + v41 + 4095) >> 13) | v39;
    }
    else
    {
      v40 = v39 | 0x7FFF;
    }
    *((_WORD *)v8 + 18) = v40;
    *((_WORD *)v8 + 19) = 15360;
    *(v7 - 2) = v5;
    *(v7 - 1) = v5 + 1;
    v7[3] = v5;
    *v7 = v5 + 2;
    v7[1] = v5 + 2;
    v42 = v5 + 3;
    v5 += 4;
    v7[2] = v42;
    v7 += 6;
    v8 += 64;
  }
  while ( v5 < 1600 );
  this->mRainDropVertexData = v49;
  v43 = v50;
  this->mRainDropVertexCount = 1600;
  this->mRainDropIndexData = v43;
  this->mRainDropIndexCount = 2400;
}

// File Line: 140
// RVA: 0x689A0
void __fastcall Render::RainManager::InitRainDrops(Render::RainManager *this)
{
  unsigned int v1; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rax
  UFG::qResourceData *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceData *v8; // rbx
  UFG::qResourceWarehouse *v9; // rax
  unsigned int v10; // ebp
  Illusion::Material *v11; // rax
  Illusion::Material *v12; // rdi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // eax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceInventory *v19; // rax
  UFG::qResourceWarehouse *v20; // rax
  __int64 v21; // rbp
  Render::RainDropSeeds *p_mRainDropSeeds; // rbx
  __int64 v23; // rdi
  float *p_z; // rdi
  float *v25; // rbx
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector4 v35; // xmm1
  UFG::qVector4 v36; // xmm2
  UFG::qVector4 v37; // xmm3

  v1 = sRainDropTextureUID;
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mRainDropTexture, 0x8B43FABF, v1, Inventory);
  v5 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Modulated", sRainDropAlphaStateUID, 0i64, 0i64, 0i64);
  LOWORD(v5[1].mNode.mParent) = 1025;
  LOWORD(v5[1].mNode.mChild[0]) = 1792;
  BYTE2(v5[1].mNode.mParent) = 5;
  BYTE2(v5[1].mNode.mChild[0]) = 1;
  v6 = v5;
  v7 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v7, v6);
  v8 = Illusion::Factory::NewRasterState(sRainDropRasterStateName, sRainDropRasterStateUID, 0i64, 0i64, 0i64);
  LOWORD(v8[1].mNode.mParent) = 1;
  BYTE2(v8[1].mNode.mParent) = 3;
  HIWORD(v8[1].mNode.mParent) = 0;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, v8);
  v10 = sRainDropMatUID;
  v11 = Illusion::Factory::NewMaterial(sRainDropMatName, sRainDropMatUID, 5u, 0i64, 0i64, 0i64);
  LODWORD(v8) = sRainDropShaderUID;
  LOWORD(v11[1].mNode.mChild[0]) = 0;
  v12 = v11;
  HIDWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v12[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v8;
  LODWORD(v8) = sRainDropTextureUID;
  LODWORD(v12[1].mNode.mParent) = v13;
  v12[1].mTypeUID = -1957338719;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = (_DWORD)v8;
  LODWORD(v8) = sRainDropAlphaStateUID;
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = -1958479169;
  *(_DWORD *)&v12[1].mDebugName[4] = v14;
  LOWORD(v12[1].mMaterialUser.mOffset) = 0;
  *(&v12[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v12[2].mNode.mUID = (unsigned int)v8;
  LODWORD(v8) = sRainDropRasterStateUID;
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v12[1].mNumParams = v15;
  LOWORD(v12[2].mTypeUID) = 0;
  HIDWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v12[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v12[2].mDebugName[28] = (_DWORD)v8;
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v16;
  LOWORD(v12[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v12[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("texShadow", 0xFFFFFFFF);
  LODWORD(v12[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v12[2].mStateBlockMask.mFlags[0]) = v17;
  LODWORD(v12[3].mNode.mChild[0]) = 0;
  v18 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v18, v12);
  v19 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v20 = UFG::qResourceWarehouse::Instance();
    v19 = UFG::qResourceWarehouse::GetInventory(v20, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v19;
  }
  UFG::qResourceHandle::Init(&this->mRainDropMaterial, 0xB4C26312, v10, v19);
  Render::RainManager::BuildRainDropPrimitive(this);
  v21 = 16i64;
  p_mRainDropSeeds = &this->mRainDropSeeds;
  v23 = 16i64;
  do
  {
    p_mRainDropSeeds = (Render::RainDropSeeds *)((char *)p_mRainDropSeeds + 4);
    p_mRainDropSeeds[-1].mSpeedScale[15] = UFG::qRandom(0.40000001, &UFG::qDefaultSeed) + 0.60000002;
    --v23;
  }
  while ( v23 );
  *(_QWORD *)&this->mRainDropStates.mDeltaTime = 0i64;
  p_z = &this->mRainDropStates.mWindVariance[0].z;
  v25 = &this->mRainDropStates.mOffset[0].z;
  do
  {
    v26 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    v27 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    v28 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    v29 = UFG::qRandom(16.0, &UFG::qDefaultSeed);
    *(v25 - 1) = v28;
    *v25 = v27;
    *(v25 - 2) = v29;
    v25[1] = v26;
    v30 = UFG::qRandom(2.0, &UFG::qDefaultSeed) - 1.0;
    v31 = UFG::qRandom(2.0, &UFG::qDefaultSeed) - 1.0;
    v32 = UFG::qRandom(2.0, &UFG::qDefaultSeed);
    v25 += 4;
    *(p_z - 1) = v31;
    *p_z = v30;
    p_z += 3;
    *(p_z - 5) = v32 - 1.0;
    --v21;
  }
  while ( v21 );
  this->mDefaultRainParameters.mAlpha = 0.5;
  *(_QWORD *)&this->mDefaultRainParameters.mWidth = 1017370378i64;
  this->mDefaultRainParameters.mLength = 1.2;
  this->mDefaultRainParameters.mSpeed = 20.0;
  this->mDefaultRainParameters.mAlphaFadeSpeedBegin = 80.0;
  this->mDefaultRainParameters.mAlphaFadeSpeedEnd = 100.0;
  this->mRainProfileParameters[0].mLength = this->mDefaultRainParameters.mLength;
  this->mRainProfileParameters[0].mSpeed = this->mDefaultRainParameters.mSpeed;
  this->mRainProfileParameters[0].mAlpha = this->mDefaultRainParameters.mAlpha;
  this->mRainProfileParameters[0].mWidth = this->mDefaultRainParameters.mWidth;
  this->mRainProfileParameters[0].mDensity = this->mDefaultRainParameters.mDensity;
  this->mRainProfileParameters[0].mAlphaFadeSpeedBegin = this->mDefaultRainParameters.mAlphaFadeSpeedBegin;
  this->mRainProfileParameters[0].mAlphaFadeSpeedEnd = this->mDefaultRainParameters.mAlphaFadeSpeedEnd;
  this->mRainProfileParameters[1].mLength = this->mDefaultRainParameters.mLength;
  this->mRainProfileParameters[1].mSpeed = this->mDefaultRainParameters.mSpeed;
  this->mRainProfileParameters[1].mAlpha = this->mDefaultRainParameters.mAlpha;
  this->mRainProfileParameters[1].mWidth = this->mDefaultRainParameters.mWidth;
  this->mRainProfileParameters[1].mDensity = this->mDefaultRainParameters.mDensity;
  this->mRainProfileParameters[1].mAlphaFadeSpeedBegin = this->mDefaultRainParameters.mAlphaFadeSpeedBegin;
  this->mRainProfileParameters[1].mAlphaFadeSpeedEnd = this->mDefaultRainParameters.mAlphaFadeSpeedEnd;
  this->mRainProfileParameters[2].mLength = this->mDefaultRainParameters.mLength;
  this->mRainProfileParameters[2].mSpeed = this->mDefaultRainParameters.mSpeed;
  this->mRainProfileParameters[2].mAlpha = this->mDefaultRainParameters.mAlpha;
  this->mRainProfileParameters[2].mWidth = this->mDefaultRainParameters.mWidth;
  this->mRainProfileParameters[2].mDensity = this->mDefaultRainParameters.mDensity;
  this->mRainProfileParameters[2].mAlphaFadeSpeedBegin = this->mDefaultRainParameters.mAlphaFadeSpeedBegin;
  this->mRainProfileParameters[2].mAlphaFadeSpeedEnd = this->mDefaultRainParameters.mAlphaFadeSpeedEnd;
  this->mRainEnabled = 1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPreviousCameraPosition.x = UFG::qVector3::msZero.x;
  this->mPreviousCameraPosition.y = y;
  this->mPreviousCameraPosition.z = z;
  v35 = UFG::qMatrix44::msIdentity.v1;
  v36 = UFG::qMatrix44::msIdentity.v2;
  v37 = UFG::qMatrix44::msIdentity.v3;
  this->mPreviousWorldViewProjMatrix.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mPreviousWorldViewProjMatrix.v1 = v35;
  this->mPreviousWorldViewProjMatrix.v2 = v36;
  this->mPreviousWorldViewProjMatrix.v3 = v37;
}

// File Line: 256
// RVA: 0x68FB0
void __fastcall Render::RainManager::LoadRainProfiles(Render::RainManager *this)
{
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qPropertyList *v3; // r14
  unsigned int i; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v6; // rdi
  unsigned int v7; // eax
  UFG::qSymbol *p_ptr; // rcx
  __int64 v9; // rsi
  Render::RainDropParameters *p_mDefaultRainParameters; // rax
  float *p_mSpeed; // rax
  float *p_mAlpha; // rax
  float *p_mWidth; // rax
  float *p_mDensity; // rax
  float *p_mAlphaFadeSpeedBegin; // rax
  float *p_mAlphaFadeSpeedEnd; // rax
  UFG::qSymbol v17; // [rsp+20h] [rbp-58h] BYREF
  UFG::qSymbol v18; // [rsp+24h] [rbp-54h] BYREF
  UFG::qSymbol v19; // [rsp+28h] [rbp-50h] BYREF
  UFG::qSymbol v20; // [rsp+2Ch] [rbp-4Ch] BYREF
  UFG::qSymbol v21; // [rsp+30h] [rbp-48h] BYREF
  __int64 v22; // [rsp+38h] [rbp-40h]
  UFG::qSymbol ptr; // [rsp+40h] [rbp-38h] BYREF
  UFG::qSymbol v24; // [rsp+44h] [rbp-34h] BYREF
  UFG::qSymbol v25; // [rsp+48h] [rbp-30h] BYREF
  UFG::qSymbol name; // [rsp+88h] [rbp+10h] BYREF
  UFG::qSymbol result; // [rsp+90h] [rbp+18h] BYREF
  UFG::qSymbol v28; // [rsp+98h] [rbp+20h] BYREF

  v22 = -2i64;
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
  PropertySet = UFG::PropertySetManager::GetPropertySet(&sRainProfilePropertySet);
  if ( PropertySet )
  {
    UFG::qSymbol::create_from_string(&name, "RainList");
    v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &name, DEPTH_RECURSE);
    for ( i = 0; i < v3->mNumElements; ++i )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v3, 0x1Au, i);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v6 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v6 = 0i64;
      v7 = 0;
      p_ptr = &ptr;
      while ( v6->mName.mUID != p_ptr->mUID )
      {
        ++v7;
        ++p_ptr;
        if ( v7 >= 3 )
          goto LABEL_26;
      }
      v9 = v7;
      p_mDefaultRainParameters = (Render::RainDropParameters *)UFG::qPropertySet::Get<float>(v6, &result, DEPTH_RECURSE);
      if ( !p_mDefaultRainParameters )
        p_mDefaultRainParameters = &this->mDefaultRainParameters;
      this->mRainProfileParameters[v9].mLength = p_mDefaultRainParameters->mLength;
      p_mSpeed = UFG::qPropertySet::Get<float>(v6, &v28, DEPTH_RECURSE);
      if ( !p_mSpeed )
        p_mSpeed = &this->mDefaultRainParameters.mSpeed;
      this->mRainProfileParameters[v9].mSpeed = *p_mSpeed;
      p_mAlpha = UFG::qPropertySet::Get<float>(v6, &v17, DEPTH_RECURSE);
      if ( !p_mAlpha )
        p_mAlpha = &this->mDefaultRainParameters.mAlpha;
      this->mRainProfileParameters[v9].mAlpha = *p_mAlpha;
      p_mWidth = UFG::qPropertySet::Get<float>(v6, &v18, DEPTH_RECURSE);
      if ( !p_mWidth )
        p_mWidth = &this->mDefaultRainParameters.mWidth;
      this->mRainProfileParameters[v9].mWidth = *p_mWidth;
      p_mDensity = UFG::qPropertySet::Get<float>(v6, &v19, DEPTH_RECURSE);
      if ( !p_mDensity )
        p_mDensity = &this->mDefaultRainParameters.mDensity;
      this->mRainProfileParameters[v9].mDensity = *p_mDensity;
      p_mAlphaFadeSpeedBegin = UFG::qPropertySet::Get<float>(v6, &v20, DEPTH_RECURSE);
      if ( !p_mAlphaFadeSpeedBegin )
        p_mAlphaFadeSpeedBegin = &this->mDefaultRainParameters.mAlphaFadeSpeedBegin;
      this->mRainProfileParameters[v9].mAlphaFadeSpeedBegin = *p_mAlphaFadeSpeedBegin;
      p_mAlphaFadeSpeedEnd = UFG::qPropertySet::Get<float>(v6, &v21, DEPTH_RECURSE);
      if ( !p_mAlphaFadeSpeedEnd )
        p_mAlphaFadeSpeedEnd = &this->mDefaultRainParameters.mAlphaFadeSpeedEnd;
      this->mRainProfileParameters[v9].mAlphaFadeSpeedEnd = *p_mAlphaFadeSpeedEnd;
LABEL_26:
      ;
    }
  }
  `eh vector destructor iterator(&ptr, 4ui64, 3, (void (__fastcall *)(void *))_);
}

// File Line: 314
// RVA: 0x688E0
void __fastcall Render::RainManager::Init(Render::RainManager *this)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v3; // rax
  UFG::TransformNodeComponent *v4; // rdi
  unsigned int v5; // eax

  Render::RainManager::InitRainDrops(this);
  Render::RainManager::LoadRainProfiles(this);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(
         SimulationMemoryPool,
         0x110ui64,
         "RainManager::mRainDropSplashEffectTransform",
         0i64,
         1u);
  v4 = (UFG::TransformNodeComponent *)v3;
  if ( v3 )
  {
    v5 = UFG::qStringHashUpper32("RainDropSplashEffectTransform", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent(v4, v5, 0i64, 0);
  }
  this->mRainDropSplashEffectTransform = (UFG::TransformNodeComponent *)v3;
  this->mStateblockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                               &Illusion::gStateSystem,
                                               sRainSettingsUID,
                                               sRainSettingsName,
                                               0);
  this->mCurrentRainProfile = &this->mDefaultRainParameters;
}

// File Line: 329
// RVA: 0x68650
void __fastcall Render::RainManager::Close(Render::RainManager *this)
{
  UFG::TransformNodeComponent *mRainDropSplashEffectTransform; // rcx

  Render::FXManager::KillEffect(&Render::gFXManager, this->mRainDropSplashEffectID, FXKILLOPTION_DEFAULT);
  mRainDropSplashEffectTransform = this->mRainDropSplashEffectTransform;
  this->mRainDropSplashEffectID = 0;
  if ( mRainDropSplashEffectTransform )
    mRainDropSplashEffectTransform->vfptr->__vecDelDtor(mRainDropSplashEffectTransform, 1u);
  this->mRainDropSplashEffectTransform = 0i64;
}

// File Line: 338
// RVA: 0x69970
void __fastcall Render::RainManager::UpdateRainDrops(Render::RainManager *this, float delta_time)
{
  Render::RainDropParameters *mCurrentRainProfile; // rax
  float mDensity; // xmm0_4
  unsigned int v5; // r8d
  Render::RainDropVertex *v6; // rdx
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm0_4

  mCurrentRainProfile = this->mCurrentRainProfile;
  this->mRainDropStates.mDeltaTime = delta_time;
  mDensity = mCurrentRainProfile->mDensity;
  if ( mDensity == 0.0 )
    this->mRainDropStates.mNumActivePasses = (int)(float)((float)((float)(UFG::TimeOfDayManager::GetInstance()->m_WeatherState
                                                                        - 1.0)
                                                                * 16.0)
                                                        + 0.99900001);
  else
    this->mRainDropStates.mNumActivePasses = (int)(float)((float)(mDensity * 16.0) + 0.99900001);
  if ( this->mRainDropStates.mNumActivePasses )
  {
    v5 = 0;
    do
    {
      v6 = (Render::RainDropVertex *)&this->mRainDropStates.mOffset[v5];
      x = v6->mPosition.x;
      v6->mPosition.z = (float)((float)(this->mCurrentRainProfile->mSpeed * this->mRainDropStates.mDeltaTime)
                              * this->mRainDropSeeds.mSpeedScale[v5])
                      + v6->mPosition.z;
      if ( x <= 16.0 )
      {
        if ( x < 0.0 )
          v6->mPosition.x = 16.0;
      }
      else
      {
        v6->mPosition.x = 0.0;
      }
      y = v6->mPosition.y;
      if ( y <= 16.0 )
      {
        if ( y < 0.0 )
          v6->mPosition.y = 16.0;
      }
      else
      {
        v6->mPosition.y = 0.0;
      }
      z = v6->mPosition.z;
      if ( z <= 16.0 )
      {
        if ( z < 0.0 )
          v6->mPosition.z = 16.0;
      }
      else
      {
        v6->mPosition.z = 0.0;
      }
      ++v5;
    }
    while ( v5 < this->mRainDropStates.mNumActivePasses );
  }
}

// File Line: 382
// RVA: 0x69270
void __fastcall Render::RainManager::SetRainDropConstants(
        Render::RainManager *this,
        CB_RainSettings *cb_rain_settings,
        Render::View *view,
        const float time,
        float pass)
{
  __m128 x_low; // xmm2
  Render::ViewSettings *mSettings; // rbp
  float v10; // xmm0_4
  Render::RainDropParameters *mCurrentRainProfile; // rax
  float v13; // xmm11_4
  float v14; // xmm0_4
  float mRainInteriorBlend; // xmm1_4
  __int64 v16; // r14
  float v17; // xmm2_4
  float v18; // xmm13_4
  float v19; // xmm15_4
  float v20; // xmm14_4
  float v21; // xmm1_4
  __int64 v22; // rax
  float z; // xmm3_4
  float v24; // xmm7_4
  float v25; // xmm9_4
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  UFG::TimeOfDayManager *Instance; // rax
  __m128 v30; // xmm2
  float v31; // xmm1_4
  float mSpeed; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float mRainIndoorAlphaOverride; // xmm0_4
  float v38; // xmm0_4
  UFG::qVector4 v39; // xmm3
  UFG::qVector4 v40; // xmm2
  UFG::qVector4 v41; // xmm1
  UFG::qVector4 v42; // xmm3
  UFG::qVector4 v43; // xmm2
  UFG::qVector4 v44; // xmm1
  UFG::qVector4 v45; // xmm2
  UFG::qVector4 v46; // xmm1
  UFG::qVector4 v47; // xmm3
  float x; // xmm0_4
  UFG::qVector3 direction; // [rsp+20h] [rbp-C8h] BYREF
  float v50; // [rsp+108h] [rbp+20h]

  x_low = (__m128)LODWORD(this->mPreviousCameraPosition.x);
  mSettings = view->mSettings;
  v10 = this->mPreviousCameraPosition.y - view->mViewWorld.v3.y;
  mCurrentRainProfile = this->mCurrentRainProfile;
  v13 = 0.0;
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - view->mViewWorld.v3.x)
                                    * (float)(x_low.m128_f32[0] - view->mViewWorld.v3.x))
                            + (float)(v10 * v10))
                    + (float)((float)(this->mPreviousCameraPosition.z - view->mViewWorld.v3.z)
                            * (float)(this->mPreviousCameraPosition.z - view->mViewWorld.v3.z));
  v14 = (float)((float)(_mm_sqrt_ps(x_low).m128_f32[0] * (float)(1.0 / time)) - mCurrentRainProfile->mAlphaFadeSpeedBegin)
      / mCurrentRainProfile->mAlphaFadeSpeedEnd;
  if ( v14 <= 0.0 )
  {
    v14 = 0.0;
  }
  else if ( v14 >= 1.0 )
  {
    v14 = *(float *)&FLOAT_1_0;
  }
  if ( Render::gFXManager.mRenderRainWhileInside )
    mRainInteriorBlend = *(float *)&FLOAT_1_0;
  else
    mRainInteriorBlend = this->mRainInteriorBlend;
  v16 = LODWORD(pass);
  v17 = (float)(mSettings->mProjection.v1.y * 0.56232184) * mCurrentRainProfile->mWidth;
  v18 = (float)(1.0 - v14) * mRainInteriorBlend;
  v19 = mSettings->mWorldView.v1.z * -8.0;
  v20 = mSettings->mWorldView.v0.z * -8.0;
  v21 = mCurrentRainProfile->mLength / mCurrentRainProfile->mSpeed;
  v22 = 2 * (LODWORD(pass) + 35i64);
  z = mSettings->mWorldView.v2.z;
  cb_rain_settings->SizeScale[0] = v17;
  *(_QWORD *)&cb_rain_settings->SizeScale[2] = 0i64;
  cb_rain_settings->SizeScale[1] = v21 * (float)(1.0 / time);
  v50 = z * -8.0;
  v24 = (float)(*((float *)&this->mStateblockIndex + 2 * v22 + 1) + view->mViewWorld.v3.y) + v19;
  v25 = (float)(*((float *)&this->mRainDropTexture.mPrev + 2 * v22) + view->mViewWorld.v3.z) + (float)(z * -8.0);
  v26 = fmodf((float)(*((float *)&this->mStateblockIndex + 2 * v22) + view->mViewWorld.v3.x) + v20, 16.0);
  v27 = fmodf(v24, 16.0);
  v28 = fmodf(v25, 16.0);
  cb_rain_settings->PositionOffset[0] = v26;
  cb_rain_settings->PositionOffset[1] = v27;
  cb_rain_settings->PositionOffset[3] = 0.0;
  cb_rain_settings->PositionOffset[2] = v28;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::GetWind(Instance, &direction, &pass);
  v30 = (__m128)LODWORD(direction.x);
  v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(direction.y * direction.y))
                  + (float)(direction.z * direction.z);
  if ( v30.m128_f32[0] != 0.0 )
    v13 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  v31 = this->mRainDropSeeds.mSpeedScale[v16];
  mSpeed = this->mCurrentRainProfile->mSpeed;
  v33 = (float)(gRainWindVarianceScalar * this->mRainDropStates.mWindVariance[v16].x) + 1.0;
  v34 = gRainWindVarianceScalar * this->mRainDropStates.mWindVariance[v16].y;
  v35 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(direction.x * v13) ^ _xmm[0]) * pass) * gRainWindScalar;
  v36 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(direction.y * v13) ^ _xmm[0]) * pass) * gRainWindScalar;
  cb_rain_settings->Velocity[3] = 0.0;
  cb_rain_settings->Velocity[0] = (float)((float)(v33 * (float)(v31 * v35)) * mSpeed) * time;
  cb_rain_settings->Velocity[2] = (float)(mSpeed * v31) * time;
  cb_rain_settings->Velocity[1] = (float)((float)((float)(v34 + 1.0) * (float)(v31 * v36)) * mSpeed) * time;
  if ( Render::gFXManager.mRenderRainWhileInside )
    mRainIndoorAlphaOverride = this->mRainIndoorAlphaOverride;
  else
    mRainIndoorAlphaOverride = this->mCurrentRainProfile->mAlpha;
  v38 = mRainIndoorAlphaOverride * v18;
  cb_rain_settings->Alpha[0] = v38;
  cb_rain_settings->Alpha[1] = v38;
  cb_rain_settings->Alpha[2] = v38;
  cb_rain_settings->Alpha[3] = v38;
  v39 = this->mPreviousWorldViewProjMatrix.v1;
  v40 = this->mPreviousWorldViewProjMatrix.v2;
  v41 = this->mPreviousWorldViewProjMatrix.v3;
  *(UFG::qVector4 *)cb_rain_settings->PreviousWorldViewProj = this->mPreviousWorldViewProjMatrix.v0;
  *(UFG::qVector4 *)&cb_rain_settings->PreviousWorldViewProj[4] = v39;
  *(UFG::qVector4 *)&cb_rain_settings->PreviousWorldViewProj[8] = v40;
  *(UFG::qVector4 *)&cb_rain_settings->PreviousWorldViewProj[12] = v41;
  v42 = view->mWorldViewProjection.v1;
  v43 = view->mWorldViewProjection.v2;
  v44 = view->mWorldViewProjection.v3;
  *(UFG::qVector4 *)cb_rain_settings->WorldViewProj = view->mWorldViewProjection.v0;
  *(UFG::qVector4 *)&cb_rain_settings->WorldViewProj[4] = v42;
  *(UFG::qVector4 *)&cb_rain_settings->WorldViewProj[8] = v43;
  *(UFG::qVector4 *)&cb_rain_settings->WorldViewProj[12] = v44;
  v45 = mSettings->mWorldView.v2;
  v46 = mSettings->mWorldView.v3;
  v47 = mSettings->mWorldView.v1;
  *(UFG::qVector4 *)cb_rain_settings->WorldView = mSettings->mWorldView.v0;
  *(UFG::qVector4 *)&cb_rain_settings->WorldView[4] = v47;
  *(UFG::qVector4 *)&cb_rain_settings->WorldView[8] = v45;
  *(UFG::qVector4 *)&cb_rain_settings->WorldView[12] = v46;
  cb_rain_settings->ParticleBoxSize[0] = 16.0;
  cb_rain_settings->ParticleBoxSize[1] = 16.0;
  cb_rain_settings->ParticleBoxSize[2] = 16.0;
  cb_rain_settings->ParticleBoxSize[3] = 16.0;
  x = view->mViewWorld.v3.x;
  v46.x = view->mViewWorld.v3.y;
  v45.x = view->mViewWorld.v3.z;
  cb_rain_settings->ViewPosition[3] = 0.0;
  cb_rain_settings->ViewPosition[0] = x;
  cb_rain_settings->ViewPosition[1] = v46.x;
  cb_rain_settings->ViewPosition[2] = v45.x;
  cb_rain_settings->Forward[0] = v20;
  cb_rain_settings->Forward[1] = v19;
  cb_rain_settings->Forward[3] = 1.0;
  cb_rain_settings->Forward[2] = v50;
}

// File Line: 445
// RVA: 0x69750
void __fastcall Render::RainManager::Update(Render::RainManager *this, float deltaT, UFG::qMatrix44 *world_view)
{
  float v5; // xmm0_4
  float mRainInteriorBlend; // xmm6_4
  float v7; // xmm6_4
  float v8; // xmm1_4
  Render::RainDropParameters *p_mDefaultRainParameters; // rax
  UFG::TransformNodeComponent *mRainDropSplashEffectTransform; // rcx
  unsigned int mRainDropSplashEffectID; // edx
  UFG::qVector3 pos; // [rsp+30h] [rbp-78h] BYREF
  UFG::qMatrix44 d; // [rsp+40h] [rbp-68h] BYREF

  v5 = UFG::RenderWorld::msStageEnvMap->mInteriorBlend * 2.0;
  if ( v5 >= 1.0 )
    v5 = *(float *)&FLOAT_1_0;
  this->mRainInteriorBlend = v5;
  if ( UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0
    && (Render::gFXManager.mRenderRainWhileInside || this->mRainInteriorBlend > 0.0000099999997) )
  {
    Render::RainManager::UpdateRainDrops(this, deltaT);
    if ( gOverrideRainProfile )
    {
      p_mDefaultRainParameters = &this->mDefaultRainParameters;
    }
    else
    {
      if ( Render::gFXManager.mRenderRainWhileInside )
        mRainInteriorBlend = *(float *)&FLOAT_1_0;
      else
        mRainInteriorBlend = this->mRainInteriorBlend;
      v7 = mRainInteriorBlend * UFG::TimeOfDayManager::GetInstance()->m_WeatherState;
      v8 = v7 - 2.0;
      if ( (float)(v7 - 2.0) < 0.0 )
        LODWORD(v8) ^= _xmm[0];
      if ( v8 >= 0.001 )
      {
        if ( v7 <= 1.5 )
          p_mDefaultRainParameters = this->mRainProfileParameters;
        else
          p_mDefaultRainParameters = &this->mRainProfileParameters[1];
      }
      else
      {
        p_mDefaultRainParameters = &this->mRainProfileParameters[2];
      }
    }
    this->mCurrentRainProfile = p_mDefaultRainParameters;
    UFG::qInverseAffine(&d, world_view);
    mRainDropSplashEffectTransform = this->mRainDropSplashEffectTransform;
    pos.x = d.v3.x + (float)(COERCE_FLOAT(LODWORD(d.v2.x) ^ _xmm[0]) * Render::RainManager::sSplashEffectDistance);
    pos.y = d.v3.y + (float)(COERCE_FLOAT(LODWORD(d.v2.y) ^ _xmm[0]) * Render::RainManager::sSplashEffectDistance);
    pos.z = d.v3.z + (float)(COERCE_FLOAT(LODWORD(d.v2.z) ^ _xmm[0]) * Render::RainManager::sSplashEffectDistance);
    UFG::TransformNodeComponent::SetWorldTranslation(mRainDropSplashEffectTransform, &pos);
    if ( !this->mRainDropSplashEffectID )
      this->mRainDropSplashEffectID = Render::FXManager::CreateEffect(
                                        &Render::gFXManager,
                                        sRainDropSplashEffect,
                                        this->mRainDropSplashEffectTransform,
                                        0xFFFFFFFF,
                                        0i64);
  }
  else
  {
    mRainDropSplashEffectID = this->mRainDropSplashEffectID;
    if ( mRainDropSplashEffectID )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, mRainDropSplashEffectID, FXKILLOPTION_DEFAULT);
      this->mRainDropSplashEffectID = 0;
    }
  }
}

// File Line: 498
// RVA: 0x686A0
void __fastcall Render::RainManager::Draw(
        Render::RainManager *this,
        UFG::RenderContext *render_context,
        Render::View *view,
        float delta_time)
{
  Illusion::Primitive *v8; // rax
  unsigned int mRainDropVertexCount; // r9d
  void *mRainDropVertexData; // r8
  void *indices; // rcx
  UFG::qResourceData *mData; // rbp
  unsigned int mUID; // r8d
  unsigned int v14; // edi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  _WORD *v16; // rax
  char *v17; // rax
  char *v18; // rbp
  float v19; // xmm3_4
  unsigned int mStateblockIndex_low; // r14d
  Illusion::StateValues *StateValues; // rax
  UFG::qVector4 v22; // xmm1
  UFG::qVector4 v23; // xmm3
  UFG::qVector4 v24; // xmm2
  int num_indices; // [rsp+30h] [rbp-38h]

  if ( this->mRainEnabled && UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 && this->mRainDropSplashEffectID )
  {
    v8 = Illusion::Primitive::Create("RainDrops");
    mRainDropVertexCount = this->mRainDropVertexCount;
    mRainDropVertexData = this->mRainDropVertexData;
    num_indices = this->mRainDropIndexCount;
    indices = this->mRainDropIndexData;
    this->mRainDropPrimitive = v8;
    Illusion::Primitive::SetBuffers(
      v8,
      TRIANGLELIST,
      mRainDropVertexData,
      mRainDropVertexCount,
      (Illusion::VertexDecl *)this->mRainDropVertexDecl.mData,
      indices,
      num_indices,
      1);
    mData = this->mRainDropMaterial.mData;
    mUID = render_context->mHeightmapShadowTextureAlias->mNode.mUID;
    v14 = 0;
    if ( LODWORD(mData[4].mResourceHandles.mNode.mNext) != mUID )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&mData[4].mNode.mChild[1], mData[4].mTypeUID, mUID);
      mPrev = mData[1].mResourceHandles.mNode.mPrev;
      if ( mPrev )
        v16 = (_WORD *)((char *)&mPrev[7].mNext + (_QWORD)mData);
      else
        v16 = 0i64;
      *v16 |= 0x20u;
    }
    if ( this->mRainDropStates.mNumActivePasses )
    {
      do
      {
        v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x140u, 0x10u);
        v18 = v17;
        if ( delta_time <= 0.033 )
          v19 = FLOAT_0_033;
        else
          v19 = delta_time;
        Render::RainManager::SetRainDropConstants(this, (CB_RainSettings *)v17, view, v19, v14);
        mStateblockIndex_low = SLOWORD(this->mStateblockIndex);
        StateValues = Render::View::GetStateValues(view);
        if ( mStateblockIndex_low >= 0x40 )
          StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mStateblockIndex_low - 64);
        else
          StateValues->mSetValueMask.mFlags[0] |= 1i64 << mStateblockIndex_low;
        StateValues->mParamValues[(__int16)mStateblockIndex_low] = v18;
        Render::View::Draw(
          view,
          this->mRainDropPrimitive,
          (Illusion::Material *)this->mRainDropMaterial.mData,
          &UFG::qMatrix44::msIdentity);
        ++v14;
      }
      while ( v14 < this->mRainDropStates.mNumActivePasses );
    }
    v22 = view->mWorldViewProjection.v3;
    v23 = view->mWorldViewProjection.v1;
    v24 = view->mWorldViewProjection.v2;
    this->mPreviousWorldViewProjMatrix.v0 = view->mWorldViewProjection.v0;
    this->mPreviousWorldViewProjMatrix.v1 = v23;
    this->mPreviousWorldViewProjMatrix.v2 = v24;
    this->mPreviousWorldViewProjMatrix.v3 = v22;
    v22.x = view->mViewWorld.v3.z;
    *(_QWORD *)&this->mPreviousCameraPosition.x = *(_QWORD *)&view->mViewWorld.v3.x;
    this->mPreviousCameraPosition.z = v22.x;
  }
}

