// File Line: 18
// RVA: 0x4AE100
char __usercall UFG::GameStatPCDisplaySettings::LoadFromXML@<al>(UFG::GameStatPCDisplaySettings *this@<rcx>, const char *filename@<rdx>, float a3@<xmm0>)
{
  const char *v3; // rdi
  UFG::GameStatPCDisplaySettings *v4; // rbx
  SimpleXML::XMLDocument *v6; // rax
  SimpleXML::XMLDocument *v7; // rdi
  SimpleXML::XMLNode *v8; // rax
  SimpleXML::XMLNode *v9; // rsi
  SimpleXML::XMLNode *v10; // rax
  int v11; // eax
  SimpleXML::XMLDocument *v12; // rcx
  SimpleXML::XMLNode *v13; // rax
  SimpleXML::XMLNode *v14; // rax
  SimpleXML::XMLNode *v15; // rax
  SimpleXML::XMLNode *v16; // rax
  SimpleXML::XMLNode *v17; // rax
  SimpleXML::XMLNode *v18; // rax
  SimpleXML::XMLNode *v19; // rax
  const char *v20; // rax
  SimpleXML::XMLNode *v21; // rax
  const char *v22; // rax
  SimpleXML::XMLNode *v23; // rax
  SimpleXML::XMLNode *v24; // rax
  SimpleXML::XMLNode *v25; // rax
  SimpleXML::XMLNode *v26; // rax
  SimpleXML::XMLNode *v27; // rax
  SimpleXML::XMLNode *v28; // rax
  SimpleXML::XMLNode *v29; // rax
  SimpleXML::XMLNode *v30; // rax
  SimpleXML::XMLNode *v31; // rax
  SimpleXML::XMLNode *v32; // rax
  SimpleXML::XMLNode *v33; // rax
  SimpleXML::XMLNode *v34; // rax
  SimpleXML::XMLNode *v35; // rax
  SimpleXML::XMLNode *v36; // rax
  SimpleXML::XMLNode *v37; // rax
  Render::eGlobalSetting v38; // eax
  SimpleXML::XMLNode *v39; // rax

  v3 = filename;
  v4 = this;
  Render::RenderOutputParams::SetDefault(&this->mDisplaySettings);
  if ( !(unsigned __int8)UFG::qFileExists(v3) )
    return 0;
  v6 = SimpleXML::XMLDocument::Open(v3, 1ui64, 0i64);
  v7 = v6;
  if ( !v6 )
    return 0;
  v8 = SimpleXML::XMLDocument::GetNode(v6, "DisplaySettings", 0i64);
  v9 = v8;
  if ( !v8 )
    return 0;
  v10 = SimpleXML::XMLDocument::GetChildNode(v7, "Version", v8);
  if ( !v10 )
  {
    v12 = v7;
    goto LABEL_57;
  }
  v11 = SimpleXML::XMLNode::GetValue(v10, 0);
  v12 = v7;
  if ( v11 != 1 )
  {
LABEL_57:
    SimpleXML::XMLDocument::~XMLDocument(v12);
    operator delete[](v7);
    return 0;
  }
  v13 = SimpleXML::XMLDocument::GetChildNode(v7, "AdapterUID", v9);
  if ( v13 )
    v4->mDisplaySettings.mDisplayMode.mAdapterUID = SimpleXML::XMLNode::GetValue(
                                                      v13,
                                                      v4->mDisplaySettings.mDisplayMode.mAdapterUID);
  v14 = SimpleXML::XMLDocument::GetChildNode(v7, "MonitorUID", v9);
  if ( v14 )
    v4->mDisplaySettings.mDisplayMode.mMonitorUID = SimpleXML::XMLNode::GetValue(
                                                      v14,
                                                      v4->mDisplaySettings.mDisplayMode.mMonitorUID);
  v15 = SimpleXML::XMLDocument::GetChildNode(v7, "ResolutionWidth", v9);
  if ( v15 )
    v4->mDisplaySettings.mDisplayMode.mBackBufferWidth = SimpleXML::XMLNode::GetValue(
                                                           v15,
                                                           v4->mDisplaySettings.mDisplayMode.mBackBufferWidth);
  v16 = SimpleXML::XMLDocument::GetChildNode(v7, "ResolutionHeight", v9);
  if ( v16 )
    v4->mDisplaySettings.mDisplayMode.mBackBufferHeight = SimpleXML::XMLNode::GetValue(
                                                            v16,
                                                            v4->mDisplaySettings.mDisplayMode.mBackBufferHeight);
  v17 = SimpleXML::XMLDocument::GetChildNode(v7, "RefreshRateNumerator", v9);
  if ( v17 )
    v4->mDisplaySettings.mDisplayMode.mRefreshRateNumerator = SimpleXML::XMLNode::GetValue(
                                                                v17,
                                                                v4->mDisplaySettings.mDisplayMode.mRefreshRateNumerator);
  v18 = SimpleXML::XMLDocument::GetChildNode(v7, "RefreshRateDenominator", v9);
  if ( v18 )
    v4->mDisplaySettings.mDisplayMode.mRefreshRateDenominator = SimpleXML::XMLNode::GetValue(
                                                                  v18,
                                                                  v4->mDisplaySettings.mDisplayMode.mRefreshRateDenominator);
  v19 = SimpleXML::XMLDocument::GetChildNode(v7, "ScalingMode", v9);
  if ( v19 )
  {
    v20 = SimpleXML::XMLNode::GetValue(v19);
    v4->mDisplaySettings.mDisplayMode.mScaling = UFG::GameStatPCDisplaySettings::GetScalingMode(v20);
  }
  v21 = SimpleXML::XMLDocument::GetChildNode(v7, "ScanlineMode", v9);
  if ( v21 )
  {
    v22 = SimpleXML::XMLNode::GetValue(v21);
    v4->mDisplaySettings.mDisplayMode.mScanlineMode = (unsigned __int64)UFG::qStringCompareInsensitive(
                                                                          v22,
                                                                          "progressive",
                                                                          -1) == 0;
  }
  v23 = SimpleXML::XMLDocument::GetChildNode(v7, "Fullscreen", v9);
  if ( v23 )
    v4->mDisplaySettings.mEnableFullscreen = SimpleXML::XMLNode::GetValue(v23, v4->mDisplaySettings.mEnableFullscreen) != 0;
  v24 = SimpleXML::XMLDocument::GetChildNode(v7, "Stereo3D", v9);
  if ( v24 )
    v4->mDisplaySettings.mEnable3D = SimpleXML::XMLNode::GetValue(v24, v4->mDisplaySettings.mEnable3D) != 0;
  v25 = SimpleXML::XMLDocument::GetChildNode(v7, "StereoEyeDistance", v9);
  if ( v25 )
  {
    SimpleXML::XMLNode::GetValue(v25, v4->mDisplaySettings.mInterAxialDistance);
    v4->mDisplaySettings.mInterAxialDistance = a3;
  }
  v26 = SimpleXML::XMLDocument::GetChildNode(v7, "VSync", v9);
  if ( v26 )
    v4->mDisplaySettings.mEnableVSync = SimpleXML::XMLNode::GetValue(v26, v4->mDisplaySettings.mEnableVSync) != 0;
  v27 = SimpleXML::XMLDocument::GetChildNode(v7, "AAQuality", v9);
  if ( v27 )
    v4->mDisplaySettings.mAAQuality = SimpleXML::XMLNode::GetValue(v27, v4->mDisplaySettings.mAAQuality);
  v28 = SimpleXML::XMLDocument::GetChildNode(v7, "TextureDetailLevel", v9);
  if ( v28 )
    v4->mDisplaySettings.mTextureDetailLevel = SimpleXML::XMLNode::GetValue(
                                                 v28,
                                                 v4->mDisplaySettings.mTextureDetailLevel);
  v29 = SimpleXML::XMLDocument::GetChildNode(v7, "ShadowRes", v9);
  if ( v29 )
    v4->mDisplaySettings.mShadowRes = SimpleXML::XMLNode::GetValue(v29, v4->mDisplaySettings.mShadowRes);
  v30 = SimpleXML::XMLDocument::GetChildNode(v7, "ShadowFilter", v9);
  if ( v30 )
    v4->mDisplaySettings.mShadowFilter = SimpleXML::XMLNode::GetValue(v30, v4->mDisplaySettings.mShadowFilter);
  v31 = SimpleXML::XMLDocument::GetChildNode(v7, "MotionBlur", v9);
  if ( v31 )
    v4->mDisplaySettings.mMotionBlur = SimpleXML::XMLNode::GetValue(v31, v4->mDisplaySettings.mMotionBlur);
  v32 = SimpleXML::XMLDocument::GetChildNode(v7, "SSAO", v9);
  if ( v32 )
    v4->mDisplaySettings.mSSAO = SimpleXML::XMLNode::GetValue(v32, v4->mDisplaySettings.mSSAO);
  v33 = SimpleXML::XMLDocument::GetChildNode(v7, "FPSLimiter", v9);
  if ( v33 )
    v4->mDisplaySettings.mFPSLimiter = SimpleXML::XMLNode::GetValue(v33, v4->mDisplaySettings.mFPSLimiter);
  v34 = SimpleXML::XMLDocument::GetChildNode(v7, "Option3DDepth", v9);
  if ( v34 )
    v4->mDisplaySettings.m3DDepth = SimpleXML::XMLNode::GetValue(v34, v4->mDisplaySettings.m3DDepth);
  v35 = SimpleXML::XMLDocument::GetChildNode(v7, "Option3DConvergence", v9);
  if ( v35 )
    v4->mDisplaySettings.m3DConvergence = SimpleXML::XMLNode::GetValue(v35, v4->mDisplaySettings.m3DConvergence);
  v36 = SimpleXML::XMLDocument::GetChildNode(v7, "WorldDensity", v9);
  if ( v36 )
    v4->mDisplaySettings.mLODSetting = SimpleXML::XMLNode::GetValue(v36, v4->mDisplaySettings.mLODSetting);
  v37 = SimpleXML::XMLDocument::GetChildNode(v7, "GlobalSetting", v9);
  if ( v37 )
  {
    v38 = SimpleXML::XMLNode::GetValue(v37, v4->mDisplaySettings.mGlobalSetting);
    v4->mDisplaySettings.mGlobalSetting = v38;
    Render::RenderOutputParams::ChangeGlobalSetting(&v4->mDisplaySettings, v38);
  }
  v39 = SimpleXML::XMLDocument::GetChildNode(v7, "EnableLowResBuffer", v9);
  if ( v39 )
    v4->mDisplaySettings.mEnableLowResBuffer = SimpleXML::XMLNode::GetValue(
                                                 v39,
                                                 v4->mDisplaySettings.mEnableLowResBuffer) != 0;
  SimpleXML::XMLDocument::~XMLDocument(v7);
  operator delete[](v7);
  return 1;
}

// File Line: 203
// RVA: 0x4B8F30
char __fastcall UFG::GameStatPCDisplaySettings::SaveToXML(UFG::GameStatPCDisplaySettings *this, const char *filename)
{
  const char *v2; // rbp
  UFG::GameStatPCDisplaySettings *v3; // rsi
  SimpleXML::XMLWriter *v4; // rdi
  const char *v5; // rbx
  const char *v6; // rdx

  v2 = filename;
  v3 = this;
  v4 = (SimpleXML::XMLWriter *)SimpleXML::XMLWriter::CreateBuffer(0x400u, 1);
  SimpleXML::XMLWriter::BeginNode(v4, "DisplaySettings");
  SimpleXML::XMLWriter::BeginNode(v4, "Version");
  SimpleXML::XMLWriter::AddValue(v4, 1u);
  SimpleXML::XMLWriter::EndNode(v4, "Version");
  SimpleXML::XMLWriter::BeginNode(v4, "AdapterUID");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mDisplayMode.mAdapterUID);
  SimpleXML::XMLWriter::EndNode(v4, "AdapterUID");
  SimpleXML::XMLWriter::BeginNode(v4, "MonitorUID");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mDisplayMode.mMonitorUID);
  SimpleXML::XMLWriter::EndNode(v4, "MonitorUID");
  SimpleXML::XMLWriter::BeginNode(v4, "ResolutionWidth");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mDisplayMode.mBackBufferWidth);
  SimpleXML::XMLWriter::EndNode(v4, "ResolutionWidth");
  SimpleXML::XMLWriter::BeginNode(v4, "ResolutionHeight");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mDisplayMode.mBackBufferHeight);
  SimpleXML::XMLWriter::EndNode(v4, "ResolutionHeight");
  SimpleXML::XMLWriter::BeginNode(v4, "RefreshRateNumerator");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mDisplayMode.mRefreshRateNumerator);
  SimpleXML::XMLWriter::EndNode(v4, "RefreshRateNumerator");
  SimpleXML::XMLWriter::BeginNode(v4, "RefreshRateDenominator");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mDisplayMode.mRefreshRateDenominator);
  SimpleXML::XMLWriter::EndNode(v4, "RefreshRateDenominator");
  SimpleXML::XMLWriter::BeginNode(v4, "ScalingMode");
  v5 = "default";
  if ( v3->mDisplaySettings.mDisplayMode.mScaling == 1 )
  {
    v6 = "centered";
  }
  else if ( v3->mDisplaySettings.mDisplayMode.mScaling == 2 )
  {
    v6 = "stretched";
  }
  else
  {
    v6 = "default";
  }
  SimpleXML::XMLWriter::AddValue(v4, v6, 1);
  SimpleXML::XMLWriter::EndNode(v4, "ScalingMode");
  SimpleXML::XMLWriter::BeginNode(v4, "ScanlineMode");
  if ( v3->mDisplaySettings.mDisplayMode.mScanlineMode == 1 )
    v5 = "progressive";
  SimpleXML::XMLWriter::AddValue(v4, v5, 1);
  SimpleXML::XMLWriter::EndNode(v4, "ScanlineMode");
  SimpleXML::XMLWriter::BeginNode(v4, "Fullscreen");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mEnableFullscreen != 0);
  SimpleXML::XMLWriter::EndNode(v4, "Fullscreen");
  SimpleXML::XMLWriter::BeginNode(v4, "Stereo3D");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mEnable3D != 0);
  SimpleXML::XMLWriter::EndNode(v4, "Stereo3D");
  SimpleXML::XMLWriter::BeginNode(v4, "StereoEyeDistance");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mInterAxialDistance);
  SimpleXML::XMLWriter::EndNode(v4, "StereoEyeDistance");
  SimpleXML::XMLWriter::BeginNode(v4, "VSync");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mEnableVSync != 0);
  SimpleXML::XMLWriter::EndNode(v4, "VSync");
  SimpleXML::XMLWriter::BeginNode(v4, "AAQuality");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mAAQuality);
  SimpleXML::XMLWriter::EndNode(v4, "AAQuality");
  SimpleXML::XMLWriter::BeginNode(v4, "TextureDetailLevel");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mTextureDetailLevel);
  SimpleXML::XMLWriter::EndNode(v4, "TextureDetailLevel");
  SimpleXML::XMLWriter::BeginNode(v4, "ShadowRes");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mShadowRes);
  SimpleXML::XMLWriter::EndNode(v4, "ShadowRes");
  SimpleXML::XMLWriter::BeginNode(v4, "ShadowFilter");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mShadowFilter);
  SimpleXML::XMLWriter::EndNode(v4, "ShadowFilter");
  SimpleXML::XMLWriter::BeginNode(v4, "MotionBlur");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mMotionBlur);
  SimpleXML::XMLWriter::EndNode(v4, "MotionBlur");
  SimpleXML::XMLWriter::BeginNode(v4, "SSAO");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mSSAO);
  SimpleXML::XMLWriter::EndNode(v4, "SSAO");
  SimpleXML::XMLWriter::BeginNode(v4, "FPSLimiter");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mFPSLimiter);
  SimpleXML::XMLWriter::EndNode(v4, "FPSLimiter");
  SimpleXML::XMLWriter::BeginNode(v4, "Option3DDepth");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.m3DDepth);
  SimpleXML::XMLWriter::EndNode(v4, "Option3DDepth");
  SimpleXML::XMLWriter::BeginNode(v4, "Option3DConvergence");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.m3DConvergence);
  SimpleXML::XMLWriter::EndNode(v4, "Option3DConvergence");
  SimpleXML::XMLWriter::BeginNode(v4, "WorldDensity");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mLODSetting);
  SimpleXML::XMLWriter::EndNode(v4, "WorldDensity");
  SimpleXML::XMLWriter::BeginNode(v4, "GlobalSetting");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mGlobalSetting);
  SimpleXML::XMLWriter::EndNode(v4, "GlobalSetting");
  SimpleXML::XMLWriter::BeginNode(v4, "EnableLowResBuffer");
  SimpleXML::XMLWriter::AddValue(v4, v3->mDisplaySettings.mEnableLowResBuffer != 0);
  SimpleXML::XMLWriter::EndNode(v4, "EnableLowResBuffer");
  SimpleXML::XMLWriter::EndNode(v4, "DisplaySettings");
  SimpleXML::XMLWriter::CloseBufferAndWriteToFile(v4, v2);
  return 1;
}

// File Line: 336
// RVA: 0x4A6230
signed __int64 __fastcall UFG::GameStatPCDisplaySettings::GetScalingMode(const char *str)
{
  const char *v1; // rbx
  int v3; // eax
  unsigned int v4; // ecx

  v1 = str;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(str, "centered", -1) )
    return 1i64;
  v3 = UFG::qStringCompareInsensitive(v1, "stretched", -1);
  v4 = 0;
  if ( !v3 )
    v4 = 2;
  return v4;
}

