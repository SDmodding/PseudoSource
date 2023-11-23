// File Line: 18
// RVA: 0x4AE100
char __fastcall UFG::GameStatPCDisplaySettings::LoadFromXML(UFG::GameStatPCDisplaySettings *this, const char *filename)
{
  SimpleXML::XMLDocument *v5; // rax
  SimpleXML::XMLDocument *v6; // rdi
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *v8; // rsi
  SimpleXML::XMLNode *ChildNode; // rax
  int Value; // eax
  SimpleXML::XMLDocument *v11; // rcx
  SimpleXML::XMLNode *v12; // rax
  SimpleXML::XMLNode *v13; // rax
  SimpleXML::XMLNode *v14; // rax
  SimpleXML::XMLNode *v15; // rax
  SimpleXML::XMLNode *v16; // rax
  SimpleXML::XMLNode *v17; // rax
  SimpleXML::XMLNode *v18; // rax
  char *v19; // rax
  SimpleXML::XMLNode *v20; // rax
  char *v21; // rax
  SimpleXML::XMLNode *v22; // rax
  SimpleXML::XMLNode *v23; // rax
  SimpleXML::XMLNode *v24; // rax
  double v25; // xmm0_8
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

  Render::RenderOutputParams::SetDefault(&this->mDisplaySettings);
  if ( !UFG::qFileExists(filename) )
    return 0;
  v5 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
  v6 = v5;
  if ( !v5 )
    return 0;
  Node = SimpleXML::XMLDocument::GetNode(v5, "DisplaySettings", 0i64);
  v8 = Node;
  if ( !Node )
    return 0;
  ChildNode = SimpleXML::XMLDocument::GetChildNode(v6, "Version", Node);
  if ( !ChildNode )
  {
    v11 = v6;
    goto LABEL_57;
  }
  Value = SimpleXML::XMLNode::GetValue(ChildNode, 0);
  v11 = v6;
  if ( Value != 1 )
  {
LABEL_57:
    SimpleXML::XMLDocument::~XMLDocument(v11);
    operator delete[](v6);
    return 0;
  }
  v12 = SimpleXML::XMLDocument::GetChildNode(v6, "AdapterUID", v8);
  if ( v12 )
    this->mDisplaySettings.mDisplayMode.mAdapterUID = SimpleXML::XMLNode::GetValue(
                                                        v12,
                                                        this->mDisplaySettings.mDisplayMode.mAdapterUID);
  v13 = SimpleXML::XMLDocument::GetChildNode(v6, "MonitorUID", v8);
  if ( v13 )
    this->mDisplaySettings.mDisplayMode.mMonitorUID = SimpleXML::XMLNode::GetValue(
                                                        v13,
                                                        this->mDisplaySettings.mDisplayMode.mMonitorUID);
  v14 = SimpleXML::XMLDocument::GetChildNode(v6, "ResolutionWidth", v8);
  if ( v14 )
    this->mDisplaySettings.mDisplayMode.mBackBufferWidth = SimpleXML::XMLNode::GetValue(
                                                             v14,
                                                             this->mDisplaySettings.mDisplayMode.mBackBufferWidth);
  v15 = SimpleXML::XMLDocument::GetChildNode(v6, "ResolutionHeight", v8);
  if ( v15 )
    this->mDisplaySettings.mDisplayMode.mBackBufferHeight = SimpleXML::XMLNode::GetValue(
                                                              v15,
                                                              this->mDisplaySettings.mDisplayMode.mBackBufferHeight);
  v16 = SimpleXML::XMLDocument::GetChildNode(v6, "RefreshRateNumerator", v8);
  if ( v16 )
    this->mDisplaySettings.mDisplayMode.mRefreshRateNumerator = SimpleXML::XMLNode::GetValue(
                                                                  v16,
                                                                  this->mDisplaySettings.mDisplayMode.mRefreshRateNumerator);
  v17 = SimpleXML::XMLDocument::GetChildNode(v6, "RefreshRateDenominator", v8);
  if ( v17 )
    this->mDisplaySettings.mDisplayMode.mRefreshRateDenominator = SimpleXML::XMLNode::GetValue(
                                                                    v17,
                                                                    this->mDisplaySettings.mDisplayMode.mRefreshRateDenominator);
  v18 = SimpleXML::XMLDocument::GetChildNode(v6, "ScalingMode", v8);
  if ( v18 )
  {
    v19 = SimpleXML::XMLNode::GetValue(v18);
    this->mDisplaySettings.mDisplayMode.mScaling = UFG::GameStatPCDisplaySettings::GetScalingMode(v19);
  }
  v20 = SimpleXML::XMLDocument::GetChildNode(v6, "ScanlineMode", v8);
  if ( v20 )
  {
    v21 = SimpleXML::XMLNode::GetValue(v20);
    this->mDisplaySettings.mDisplayMode.mScanlineMode = UFG::qStringCompareInsensitive(v21, "progressive", -1) == 0;
  }
  v22 = SimpleXML::XMLDocument::GetChildNode(v6, "Fullscreen", v8);
  if ( v22 )
    this->mDisplaySettings.mEnableFullscreen = SimpleXML::XMLNode::GetValue(
                                                 v22,
                                                 this->mDisplaySettings.mEnableFullscreen) != 0;
  v23 = SimpleXML::XMLDocument::GetChildNode(v6, "Stereo3D", v8);
  if ( v23 )
    this->mDisplaySettings.mEnable3D = SimpleXML::XMLNode::GetValue(v23, this->mDisplaySettings.mEnable3D) != 0;
  v24 = SimpleXML::XMLDocument::GetChildNode(v6, "StereoEyeDistance", v8);
  if ( v24 )
  {
    v25 = SimpleXML::XMLNode::GetValue(
            v24,
            COERCE_DOUBLE((unsigned __int64)LODWORD(this->mDisplaySettings.mInterAxialDistance)));
    this->mDisplaySettings.mInterAxialDistance = *(float *)&v25;
  }
  v26 = SimpleXML::XMLDocument::GetChildNode(v6, "VSync", v8);
  if ( v26 )
    this->mDisplaySettings.mEnableVSync = SimpleXML::XMLNode::GetValue(v26, this->mDisplaySettings.mEnableVSync) != 0;
  v27 = SimpleXML::XMLDocument::GetChildNode(v6, "AAQuality", v8);
  if ( v27 )
    this->mDisplaySettings.mAAQuality = SimpleXML::XMLNode::GetValue(v27, this->mDisplaySettings.mAAQuality);
  v28 = SimpleXML::XMLDocument::GetChildNode(v6, "TextureDetailLevel", v8);
  if ( v28 )
    this->mDisplaySettings.mTextureDetailLevel = SimpleXML::XMLNode::GetValue(
                                                   v28,
                                                   this->mDisplaySettings.mTextureDetailLevel);
  v29 = SimpleXML::XMLDocument::GetChildNode(v6, "ShadowRes", v8);
  if ( v29 )
    this->mDisplaySettings.mShadowRes = SimpleXML::XMLNode::GetValue(v29, this->mDisplaySettings.mShadowRes);
  v30 = SimpleXML::XMLDocument::GetChildNode(v6, "ShadowFilter", v8);
  if ( v30 )
    this->mDisplaySettings.mShadowFilter = SimpleXML::XMLNode::GetValue(v30, this->mDisplaySettings.mShadowFilter);
  v31 = SimpleXML::XMLDocument::GetChildNode(v6, "MotionBlur", v8);
  if ( v31 )
    this->mDisplaySettings.mMotionBlur = SimpleXML::XMLNode::GetValue(v31, this->mDisplaySettings.mMotionBlur);
  v32 = SimpleXML::XMLDocument::GetChildNode(v6, "SSAO", v8);
  if ( v32 )
    this->mDisplaySettings.mSSAO = SimpleXML::XMLNode::GetValue(v32, this->mDisplaySettings.mSSAO);
  v33 = SimpleXML::XMLDocument::GetChildNode(v6, "FPSLimiter", v8);
  if ( v33 )
    this->mDisplaySettings.mFPSLimiter = SimpleXML::XMLNode::GetValue(v33, this->mDisplaySettings.mFPSLimiter);
  v34 = SimpleXML::XMLDocument::GetChildNode(v6, "Option3DDepth", v8);
  if ( v34 )
    this->mDisplaySettings.m3DDepth = SimpleXML::XMLNode::GetValue(v34, this->mDisplaySettings.m3DDepth);
  v35 = SimpleXML::XMLDocument::GetChildNode(v6, "Option3DConvergence", v8);
  if ( v35 )
    this->mDisplaySettings.m3DConvergence = SimpleXML::XMLNode::GetValue(v35, this->mDisplaySettings.m3DConvergence);
  v36 = SimpleXML::XMLDocument::GetChildNode(v6, "WorldDensity", v8);
  if ( v36 )
    this->mDisplaySettings.mLODSetting = SimpleXML::XMLNode::GetValue(v36, this->mDisplaySettings.mLODSetting);
  v37 = SimpleXML::XMLDocument::GetChildNode(v6, "GlobalSetting", v8);
  if ( v37 )
  {
    v38 = SimpleXML::XMLNode::GetValue(v37, this->mDisplaySettings.mGlobalSetting);
    this->mDisplaySettings.mGlobalSetting = v38;
    Render::RenderOutputParams::ChangeGlobalSetting(&this->mDisplaySettings, v38);
  }
  v39 = SimpleXML::XMLDocument::GetChildNode(v6, "EnableLowResBuffer", v8);
  if ( v39 )
    this->mDisplaySettings.mEnableLowResBuffer = SimpleXML::XMLNode::GetValue(
                                                   v39,
                                                   this->mDisplaySettings.mEnableLowResBuffer) != 0;
  SimpleXML::XMLDocument::~XMLDocument(v6);
  operator delete[](v6);
  return 1;
}

// File Line: 203
// RVA: 0x4B8F30
char __fastcall UFG::GameStatPCDisplaySettings::SaveToXML(UFG::GameStatPCDisplaySettings *this, const char *filename)
{
  SimpleXML::XMLWriter *Buffer; // rdi
  const char *v5; // rbx
  const char *v6; // rdx

  Buffer = SimpleXML::XMLWriter::CreateBuffer(0x400u, 1);
  SimpleXML::XMLWriter::BeginNode(Buffer, "DisplaySettings");
  SimpleXML::XMLWriter::BeginNode(Buffer, "Version");
  SimpleXML::XMLWriter::AddValue(Buffer, 1u);
  SimpleXML::XMLWriter::EndNode(Buffer, "Version");
  SimpleXML::XMLWriter::BeginNode(Buffer, "AdapterUID");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mDisplayMode.mAdapterUID);
  SimpleXML::XMLWriter::EndNode(Buffer, "AdapterUID");
  SimpleXML::XMLWriter::BeginNode(Buffer, "MonitorUID");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mDisplayMode.mMonitorUID);
  SimpleXML::XMLWriter::EndNode(Buffer, "MonitorUID");
  SimpleXML::XMLWriter::BeginNode(Buffer, "ResolutionWidth");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mDisplayMode.mBackBufferWidth);
  SimpleXML::XMLWriter::EndNode(Buffer, "ResolutionWidth");
  SimpleXML::XMLWriter::BeginNode(Buffer, "ResolutionHeight");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mDisplayMode.mBackBufferHeight);
  SimpleXML::XMLWriter::EndNode(Buffer, "ResolutionHeight");
  SimpleXML::XMLWriter::BeginNode(Buffer, "RefreshRateNumerator");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mDisplayMode.mRefreshRateNumerator);
  SimpleXML::XMLWriter::EndNode(Buffer, "RefreshRateNumerator");
  SimpleXML::XMLWriter::BeginNode(Buffer, "RefreshRateDenominator");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mDisplayMode.mRefreshRateDenominator);
  SimpleXML::XMLWriter::EndNode(Buffer, "RefreshRateDenominator");
  SimpleXML::XMLWriter::BeginNode(Buffer, "ScalingMode");
  v5 = "default";
  if ( this->mDisplaySettings.mDisplayMode.mScaling == SCALING_MODE_CENTERED )
  {
    v6 = "centered";
  }
  else if ( this->mDisplaySettings.mDisplayMode.mScaling == SCALING_MODE_STRETCHED )
  {
    v6 = "stretched";
  }
  else
  {
    v6 = "default";
  }
  SimpleXML::XMLWriter::AddValue(Buffer, v6, 1);
  SimpleXML::XMLWriter::EndNode(Buffer, "ScalingMode");
  SimpleXML::XMLWriter::BeginNode(Buffer, "ScanlineMode");
  if ( this->mDisplaySettings.mDisplayMode.mScanlineMode == SCANLINE_MODE_PROGRESSIVE )
    v5 = "progressive";
  SimpleXML::XMLWriter::AddValue(Buffer, v5, 1);
  SimpleXML::XMLWriter::EndNode(Buffer, "ScanlineMode");
  SimpleXML::XMLWriter::BeginNode(Buffer, "Fullscreen");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mEnableFullscreen);
  SimpleXML::XMLWriter::EndNode(Buffer, "Fullscreen");
  SimpleXML::XMLWriter::BeginNode(Buffer, "Stereo3D");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mEnable3D);
  SimpleXML::XMLWriter::EndNode(Buffer, "Stereo3D");
  SimpleXML::XMLWriter::BeginNode(Buffer, "StereoEyeDistance");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mInterAxialDistance);
  SimpleXML::XMLWriter::EndNode(Buffer, "StereoEyeDistance");
  SimpleXML::XMLWriter::BeginNode(Buffer, "VSync");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mEnableVSync);
  SimpleXML::XMLWriter::EndNode(Buffer, "VSync");
  SimpleXML::XMLWriter::BeginNode(Buffer, "AAQuality");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mAAQuality);
  SimpleXML::XMLWriter::EndNode(Buffer, "AAQuality");
  SimpleXML::XMLWriter::BeginNode(Buffer, "TextureDetailLevel");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mTextureDetailLevel);
  SimpleXML::XMLWriter::EndNode(Buffer, "TextureDetailLevel");
  SimpleXML::XMLWriter::BeginNode(Buffer, "ShadowRes");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mShadowRes);
  SimpleXML::XMLWriter::EndNode(Buffer, "ShadowRes");
  SimpleXML::XMLWriter::BeginNode(Buffer, "ShadowFilter");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mShadowFilter);
  SimpleXML::XMLWriter::EndNode(Buffer, "ShadowFilter");
  SimpleXML::XMLWriter::BeginNode(Buffer, "MotionBlur");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mMotionBlur);
  SimpleXML::XMLWriter::EndNode(Buffer, "MotionBlur");
  SimpleXML::XMLWriter::BeginNode(Buffer, "SSAO");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mSSAO);
  SimpleXML::XMLWriter::EndNode(Buffer, "SSAO");
  SimpleXML::XMLWriter::BeginNode(Buffer, "FPSLimiter");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mFPSLimiter);
  SimpleXML::XMLWriter::EndNode(Buffer, "FPSLimiter");
  SimpleXML::XMLWriter::BeginNode(Buffer, "Option3DDepth");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.m3DDepth);
  SimpleXML::XMLWriter::EndNode(Buffer, "Option3DDepth");
  SimpleXML::XMLWriter::BeginNode(Buffer, "Option3DConvergence");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.m3DConvergence);
  SimpleXML::XMLWriter::EndNode(Buffer, "Option3DConvergence");
  SimpleXML::XMLWriter::BeginNode(Buffer, "WorldDensity");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mLODSetting);
  SimpleXML::XMLWriter::EndNode(Buffer, "WorldDensity");
  SimpleXML::XMLWriter::BeginNode(Buffer, "GlobalSetting");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mGlobalSetting);
  SimpleXML::XMLWriter::EndNode(Buffer, "GlobalSetting");
  SimpleXML::XMLWriter::BeginNode(Buffer, "EnableLowResBuffer");
  SimpleXML::XMLWriter::AddValue(Buffer, this->mDisplaySettings.mEnableLowResBuffer);
  SimpleXML::XMLWriter::EndNode(Buffer, "EnableLowResBuffer");
  SimpleXML::XMLWriter::EndNode(Buffer, "DisplaySettings");
  SimpleXML::XMLWriter::CloseBufferAndWriteToFile(Buffer, filename);
  return 1;
}

// File Line: 336
// RVA: 0x4A6230
__int64 __fastcall UFG::GameStatPCDisplaySettings::GetScalingMode(const char *str)
{
  int v3; // eax
  unsigned int v4; // ecx

  if ( !(unsigned int)UFG::qStringCompareInsensitive(str, "centered", -1) )
    return 1i64;
  v3 = UFG::qStringCompareInsensitive(str, "stretched", -1);
  v4 = 0;
  if ( !v3 )
    return 2;
  return v4;
}

