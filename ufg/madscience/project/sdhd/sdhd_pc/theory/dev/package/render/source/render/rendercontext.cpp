// File Line: 53
// RVA: 0x3FA50
void __fastcall UFG::RenderContext::RenderContext(
        UFG::RenderContext *this,
        const char *description,
        unsigned int scene_output_width,
        unsigned int scene_output_height,
        unsigned int reflection_width,
        unsigned int reflection_height,
        unsigned int envmap_size,
        bool bRequireReadAccess,
        bool bLightMRT,
        Render::eAAQuality aaQuality,
        UFG::RenderContext::AntiAliasState aa_state)
{
  int v15; // eax
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm3
  UFG::qVector4 v19; // xmm1
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm3
  UFG::RenderContextPlat *v22; // rax
  Render::RenderOutputParams outSettings; // [rsp+60h] [rbp-78h] BYREF

  Render::RenderOutputParams::RenderOutputParams(&this->mRenderSettingsForFrame);
  *(_DWORD *)&this->mRenderFeatures.mWorld = 0x1000101;
  *(_DWORD *)&this->mRenderFeatures.mAlternateGradientBackground = 16843008;
  *(_DWORD *)&this->mRenderFeatures.mAO = 65793;
  Render::ViewMetrics::Reset(&this->mRenderStats);
  UFG::qMemSet(this, 0, 0x4D0u);
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  this->mNumCascades = 0;
  v15 = 0;
  if ( outSettings.mShadowRes >= SHADOW_RES_NORMAL )
    v15 = 4;
  this->mNumSpotShadowsAllowed = v15;
  *(_QWORD *)&this->mAOOpacity = 1065353216i64;
  this->mLightWithIrradianceVolumesType = 1;
  this->mAmbientOcclusionVolumesType = 2;
  this->mAntiAliasState = aa_state;
  this->mReflection = 0i64;
  this->mCombineAmbientSpecAndSun = 1;
  this->mTargetsCreated = 0;
  this->mMainViewSettings.mCullIndex = -1;
  v16 = UFG::qMatrix44::msIdentity.v1;
  v17 = UFG::qMatrix44::msIdentity.v2;
  v18 = UFG::qMatrix44::msIdentity.v3;
  this->mMainViewSettings.mWorldView.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mMainViewSettings.mWorldView.v1 = v16;
  this->mMainViewSettings.mWorldView.v2 = v17;
  this->mMainViewSettings.mWorldView.v3 = v18;
  v19 = UFG::qMatrix44::msIdentity.v1;
  v20 = UFG::qMatrix44::msIdentity.v2;
  v21 = UFG::qMatrix44::msIdentity.v3;
  this->mMainViewSettings.mProjection.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mMainViewSettings.mProjection.v1 = v19;
  this->mMainViewSettings.mProjection.v2 = v20;
  this->mMainViewSettings.mProjection.v3 = v21;
  v22 = (UFG::RenderContextPlat *)UFG::qMalloc(0x10ui64, "RenderContextPlat", 0i64);
  if ( v22 )
    v22->mRenderContext = this;
  this->mRenderContextPlat = v22;
  UFG::RenderContext::CreateTargets(
    this,
    description,
    scene_output_width,
    scene_output_height,
    reflection_width,
    reflection_height,
    envmap_size,
    bRequireReadAccess,
    bLightMRT,
    aaQuality);
  UFG::RenderContext::CreateMaterials(this);
}

// File Line: 90
// RVA: 0x435A0
void __fastcall UFG::RenderContext::CreateTargets(
        UFG::RenderContext *this,
        const char *description,
        int scene_output_width,
        int scene_output_height,
        unsigned int reflection_width,
        unsigned int reflection_height,
        unsigned int envmap_size,
        bool bRequireReadAccess,
        bool bLightMRT,
        Render::eAAQuality aaQuality)
{
  float v14; // xmm1_4
  unsigned int v15; // eax
  unsigned int v16; // eax
  char *v17; // rax
  Render::EnvCubeMap *v18; // rdi
  UFG::qString *v19; // rax
  Illusion::Target *mGBufferTarget; // rax
  Illusion::Texture *v21; // r14
  Illusion::Texture *v22; // rbx
  Illusion::Texture *v23; // rdi
  Illusion::Texture *mDepthTextureCopy; // rsi
  UFG::qString *v25; // rax
  UFG::qString *v26; // rax
  Illusion::Target *v27; // rax
  Illusion::Texture *v28; // rbx
  unsigned int SamplerAddressFlags; // eax
  UFG::qString *v30; // rax
  Illusion::Target *v31; // rax
  Illusion::Texture *v32; // rbx
  unsigned int v33; // eax
  Illusion::Texture *v34; // rbx
  unsigned int v35; // eax
  UFG::qString *v36; // rax
  int v37; // edi
  int v38; // ebx
  UFG::qString *v39; // rax
  UFG::qString *v40; // rax
  int v41; // edi
  int v42; // ebx
  UFG::qString *v43; // rax
  Illusion::Target *v44; // rax
  UFG::qString *v45; // rax
  UFG::qString *v46; // rax
  Illusion::Target *v47; // rax
  UFG::qString *v48; // rax
  Illusion::Target *v49; // rax
  unsigned int v50; // eax
  UFG::qString *v51; // rax
  Illusion::Target *v52; // rax
  unsigned int v53; // ebx
  UFG::qString *v54; // rax
  UFG::qString *v55; // rax
  UFG::qString *v56; // rax
  UFG::qString *v57; // rax
  UFG::qString *v58; // rax
  UFG::qString *v59; // rax
  UFG::qString *v60; // rax
  UFG::qString *v61; // rax
  UFG::qString *v62; // rax
  UFG::qString *v63; // rax
  UFG::qString *v64; // rax
  UFG::qString *v65; // rax
  UFG::qString *v66; // rax
  Illusion::Texture *v67; // rbx
  UFG::qString *v68; // rax
  Illusion::Texture *v69; // rbx
  UFG::qString *v70; // rax
  UFG::qString *v71; // rax
  UFG::qString *v72; // rax
  Illusion::Target *BackBufferTarget; // rax
  unsigned int mHeight; // edi
  UFG::qString *v75; // rax
  UFG::qString *v76; // rax
  UFG::qString *v77; // rax
  Illusion::Target *v78; // rax
  Illusion::Texture *mDepthTexture; // rbx
  unsigned int v80; // eax
  UFG::qString *v81; // rax
  Illusion::Target *v82; // rax
  Illusion::Texture *v83; // rbx
  unsigned int v84; // eax
  UFG::qString *v85; // rax
  Illusion::Target *v86; // rax
  Illusion::Texture *v87; // rbx
  unsigned int v88; // eax
  UFG::qString *v89; // rax
  Illusion::Target *v90; // rax
  Illusion::Texture *v91; // rbx
  unsigned int v92; // eax
  UFG::qString *v93; // rax
  UFG::qString *v94; // rax
  Illusion::Target *v95; // rax
  Illusion::Texture *v96; // rbx
  unsigned int v97; // eax
  UFG::qString *v98; // rax
  unsigned int v99; // eax
  UFG::qString *v100; // rax
  unsigned int v101; // eax
  UFG::qString *v102; // rax
  unsigned int v103; // eax
  UFG::qString *v104; // rax
  unsigned int v105; // eax
  UFG::qString *v106; // rax
  unsigned int v107; // eax
  UFG::qString *v108; // rax
  unsigned int v109; // eax
  UFG::qString *v110; // rax
  unsigned int v111; // eax
  UFG::qString *v112; // rax
  UFG::qString *v113; // rax
  UFG::qString *v114; // rax
  Render::eHardwareFeatureLevel mFeatureLevel; // eax
  UFG::qString *v116; // rax
  UFG::qString *v117; // rax
  Illusion::Texture *v118; // rbx
  UFG::qString *v119; // rax
  Illusion::Target *v120; // rax
  UFG::qString *v121; // rax
  UFG::qString *v122; // rax
  UFG::qString result; // [rsp+50h] [rbp-B0h] BYREF
  Illusion::CreateTargetParams v124; // [rsp+80h] [rbp-80h] BYREF
  Illusion::CreateTargetParams v125; // [rsp+130h] [rbp+30h] BYREF
  Illusion::CreateTargetParams v126; // [rsp+1E0h] [rbp+E0h] BYREF
  Illusion::CreateTargetParams v127; // [rsp+290h] [rbp+190h] BYREF
  Illusion::CreateTargetParams v128; // [rsp+340h] [rbp+240h] BYREF
  Illusion::CreateTargetParams v129; // [rsp+3F0h] [rbp+2F0h] BYREF
  Illusion::CreateTargetParams v130; // [rsp+4A0h] [rbp+3A0h] BYREF
  Illusion::CreateTargetParams v131; // [rsp+550h] [rbp+450h] BYREF
  Illusion::CreateTargetParams v132; // [rsp+600h] [rbp+500h] BYREF
  Illusion::CreateTargetParams v133; // [rsp+6B0h] [rbp+5B0h] BYREF
  Illusion::CreateTargetParams v134; // [rsp+760h] [rbp+660h] BYREF
  Illusion::CreateTargetParams v135; // [rsp+810h] [rbp+710h] BYREF
  Illusion::CreateTargetParams v136; // [rsp+8C0h] [rbp+7C0h] BYREF
  Illusion::CreateTargetParams v137; // [rsp+970h] [rbp+870h] BYREF
  Illusion::CreateTargetParams v138; // [rsp+A20h] [rbp+920h] BYREF
  Illusion::CreateTargetParams v139; // [rsp+AD0h] [rbp+9D0h] BYREF
  Illusion::CreateTargetParams v140; // [rsp+B80h] [rbp+A80h] BYREF
  Illusion::CreateTargetParams v141; // [rsp+C30h] [rbp+B30h] BYREF
  Illusion::CreateTargetParams v142; // [rsp+CE0h] [rbp+BE0h] BYREF
  Illusion::CreateTargetParams v143; // [rsp+D90h] [rbp+C90h] BYREF
  Illusion::CreateTargetParams v144; // [rsp+E40h] [rbp+D40h] BYREF
  Illusion::CreateTargetParams v145; // [rsp+EF0h] [rbp+DF0h] BYREF
  Illusion::CreateTargetParams v146; // [rsp+FA0h] [rbp+EA0h] BYREF
  Illusion::CreateTargetParams v147; // [rsp+1050h] [rbp+F50h] BYREF
  Illusion::CreateTargetParams v148; // [rsp+1100h] [rbp+1000h] BYREF
  Illusion::CreateTargetParams v149; // [rsp+11B0h] [rbp+10B0h] BYREF
  Illusion::CreateTargetParams v150; // [rsp+1260h] [rbp+1160h] BYREF
  Illusion::CreateTargetParams v151; // [rsp+1310h] [rbp+1210h] BYREF
  Illusion::CreateTargetParams v152; // [rsp+13C0h] [rbp+12C0h] BYREF
  Illusion::CreateTargetParams v153; // [rsp+1470h] [rbp+1370h] BYREF
  Illusion::CreateTargetParams v154; // [rsp+1520h] [rbp+1420h] BYREF
  Illusion::CreateTargetParams v155; // [rsp+15D0h] [rbp+14D0h] BYREF
  __int64 v156; // [rsp+1680h] [rbp+1580h]
  Illusion::CreateTargetParams params; // [rsp+1690h] [rbp+1590h] BYREF
  Render::RenderOutputParams outSettings; // [rsp+1740h] [rbp+1640h] BYREF

  v156 = -2i64;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  this->mGBufferTarget = 0i64;
  this->mCascadeShadowTarget = 0i64;
  this->mCharacterShadowTarget = 0i64;
  this->mCubeMapTarget = 0i64;
  if ( outSettings.mShadowRes == SHADOW_RES_HIGH )
  {
    this->mCascadeShadowSize = 2048;
    this->mSpotShadowSize = 2048;
    this->mCharacterShadowSize = 1408;
  }
  else
  {
    this->mCascadeShadowSize = 1024;
    this->mSpotShadowSize = 1024;
    this->mCharacterShadowSize = 1024;
  }
  v14 = *(float *)&FLOAT_1_0;
  if ( aaQuality == AA_QUALITY_HIGH )
  {
    v14 = FLOAT_1_333333;
LABEL_9:
    v15 = ((int)(float)((float)scene_output_width * v14) + 31) & 0xFFFFFFE0;
    goto LABEL_11;
  }
  if ( aaQuality == AA_QUALITY_EXTREME )
  {
    v14 = FLOAT_2_0;
    goto LABEL_9;
  }
  if ( aaQuality )
    goto LABEL_9;
  v15 = scene_output_width;
LABEL_11:
  this->mGBufferWidth = v15;
  if ( aaQuality )
    v16 = ((int)(float)((float)scene_output_height * v14) + 31) & 0xFFFFFFE0;
  else
    v16 = scene_output_height;
  this->mGBufferHeight = v16;
  UFG::RenderContextPlat::CreateTargets(
    this->mRenderContextPlat,
    description,
    scene_output_width,
    scene_output_height,
    reflection_width,
    reflection_height,
    envmap_size,
    bRequireReadAccess,
    bLightMRT,
    aaQuality);
  if ( envmap_size )
  {
    v17 = UFG::qMalloc(0x4B0ui64, "EnvCubeMap", 0i64);
    v18 = (Render::EnvCubeMap *)v17;
    if ( v17 )
      `eh vector constructor iterator(v17 + 944, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::qString);
    else
      v18 = 0i64;
    this->mEnvCubeMap = v18;
    if ( !this->mCubeMapTarget )
    {
      UFG::qString::qString(&v124.name, "RealtimeCubeMap");
      v124.depth = 1;
      v124.array_size = 1;
      *(_DWORD *)v124.mrt_formats = -256;
      *(_QWORD *)&v124.num_mrt = 0x200000001i64;
      v124.num_mips = 1;
      memset(v124.textures, 0, 85);
      v124.width = envmap_size;
      v124.height = envmap_size;
      v124.target_flags = 1;
      this->mCubeMapTarget = Illusion::CreateTarget(&v124);
      UFG::qString::~qString(&v124.name);
    }
    Render::EnvCubeMap::Init(this->mEnvCubeMap, this->mCubeMapTarget);
  }
  else
  {
    this->mEnvCubeMap = 0i64;
  }
  if ( !this->mGBufferTarget )
  {
    v19 = UFG::qString::FormatEx(&result, "GBuffers%s", description);
    UFG::qString::qString(&v124.name, v19->mData);
    *(_QWORD *)&v124.num_mrt = 1i64;
    *(_QWORD *)&v124.width = 0i64;
    v124.depth = 1;
    v124.array_size = 1;
    *(_DWORD *)v124.mrt_formats = -1;
    v124.target_flags = 0;
    v124.num_mips = 1;
    memset(v124.textures, 0, 85);
    UFG::qString::~qString(&result);
    *(_QWORD *)&v124.width = *(_QWORD *)&this->mGBufferWidth;
    *(_WORD *)v124.mrt_formats = 0;
    v124.mrt_formats[2] = 0;
    v124.num_mrt = 3;
    v124.target_flags = (bRequireReadAccess ? 0x4000 : 0) | 0x210303;
    this->mGBufferTarget = Illusion::CreateTarget(&v124);
    UFG::qString::~qString(&v124.name);
  }
  mGBufferTarget = this->mGBufferTarget;
  v21 = mGBufferTarget->mTargetTexture[0];
  v22 = mGBufferTarget->mTargetTexture[1];
  v23 = mGBufferTarget->mTargetTexture[2];
  mDepthTextureCopy = mGBufferTarget->mDepthTextureCopy;
  Illusion::Texture::SetSamplerFilter(v21, 2u);
  Illusion::Texture::SetSamplerFilter(v22, 1u);
  Illusion::Texture::SetSamplerFilter(v23, 2u);
  Illusion::Texture::SetSamplerFilter(mDepthTextureCopy, 2u);
  Illusion::Texture::SetSamplerFilter(this->mGBufferTarget->mDepthTexture, 2u);
  v25 = UFG::qString::FormatEx(&result, "GBufferDiffuseAlbedoAliasTarget%s", description);
  UFG::qString::qString(&v155.name, v25->mData);
  *(_QWORD *)&v155.num_mrt = 1i64;
  *(_QWORD *)&v155.width = 0i64;
  v155.depth = 1;
  v155.array_size = 1;
  *(_DWORD *)v155.mrt_formats = -1;
  v155.target_flags = 0;
  v155.num_mips = 1;
  memset(v155.textures, 0, 85);
  UFG::qString::~qString(&result);
  v155.textures[0] = v21;
  v155.target_flags = 256;
  this->mGBufferDiffuseAlbedoAliasTarget = Illusion::CreateTarget(&v155);
  this->mGBufferDepthTarget = 0i64;
  v26 = UFG::qString::FormatEx(&result, "DynamicRange%s", description);
  UFG::qString::qString(&v130.name, v26->mData);
  *(_QWORD *)&v130.num_mrt = 1i64;
  *(_QWORD *)&v130.width = 0i64;
  v130.depth = 1;
  v130.array_size = 1;
  *(_DWORD *)v130.mrt_formats = -1;
  v130.target_flags = 0;
  v130.num_mips = 1;
  memset(v130.textures, 0, 85);
  UFG::qString::~qString(&result);
  *(_QWORD *)&v130.width = *(_QWORD *)&this->mGBufferWidth;
  v130.mrt_formats[0] = 0;
  v130.target_flags = 2097923;
  v130.depth_texture = this->mGBufferTarget->mDepthTexture;
  v27 = Illusion::CreateTarget(&v130);
  this->mDynamicRangeTarget = v27;
  v28 = v27->mTargetTexture[0];
  SamplerAddressFlags = Illusion::Texture::GetSamplerAddressFlags(v28);
  Illusion::Texture::SetSamplerState(v28, 1u, SamplerAddressFlags | 3);
  v30 = UFG::qString::FormatEx(&result, "LightBuffer%s", description);
  UFG::qString::qString(&v125.name, v30->mData);
  *(_QWORD *)&v125.num_mrt = 1i64;
  *(_QWORD *)&v125.width = 0i64;
  v125.depth = 1;
  v125.array_size = 1;
  *(_DWORD *)v125.mrt_formats = -1;
  v125.target_flags = 0;
  v125.num_mips = 1;
  memset(v125.textures, 0, 85);
  UFG::qString::~qString(&result);
  *(_QWORD *)&v125.width = *(_QWORD *)&this->mGBufferWidth;
  v125.mrt_formats[0] = 15;
  v125.mrt_formats[1] = bLightMRT ? 0xF : 0;
  v125.num_mrt = bLightMRT + 1;
  v125.target_flags = 2097921;
  v125.depth_texture = this->mGBufferTarget->mDepthTexture;
  v31 = Illusion::CreateTarget(&v125);
  this->mLightBufferTarget = v31;
  v32 = v31->mTargetTexture[0];
  v33 = Illusion::Texture::GetSamplerAddressFlags(v32);
  Illusion::Texture::SetSamplerAddressFlags(v32, v33 | 3);
  if ( bLightMRT )
  {
    v34 = this->mLightBufferTarget->mTargetTexture[1];
    v35 = Illusion::Texture::GetSamplerAddressFlags(v34);
    Illusion::Texture::SetSamplerState(v34, 2u, v35 | 3);
  }
  v36 = UFG::qString::FormatEx(&result, "HDRBloom%s", description);
  UFG::qString::qString(&v153.name, v36->mData);
  *(_QWORD *)&v153.num_mrt = 1i64;
  *(_QWORD *)&v153.width = 0i64;
  v153.depth = 1;
  v153.array_size = 1;
  *(_DWORD *)v153.mrt_formats = -1;
  v153.target_flags = 0;
  v153.num_mips = 1;
  memset(v153.textures, 0, 85);
  UFG::qString::~qString(&result);
  v153.width = this->mGBufferWidth >> 2;
  v153.height = this->mGBufferHeight >> 2;
  v153.mrt_formats[0] = 0;
  this->mHDRBloomTarget = Illusion::CreateTarget(&v153);
  v37 = this->mGBufferWidth >> 1;
  v38 = this->mGBufferHeight >> 1;
  v39 = UFG::qString::FormatEx(&result, "HalfsizeLinearDepthTarget%s", description);
  UFG::qString::qString(&v138.name, v39->mData);
  *(_QWORD *)&v138.num_mrt = 1i64;
  *(_QWORD *)&v138.width = 0i64;
  v138.depth = 1;
  v138.array_size = 1;
  *(_DWORD *)v138.mrt_formats = -1;
  v138.target_flags = 0;
  v138.num_mips = 1;
  memset(v138.textures, 0, 85);
  UFG::qString::~qString(&result);
  v138.width = v37;
  v138.height = v38;
  v138.mrt_formats[0] = 14;
  v138.target_flags = 65539;
  this->mHalfSizeLinearDepthTarget = Illusion::CreateTarget(&v138);
  v40 = UFG::qString::FormatEx(&result, "Halfsize%s", description);
  UFG::qString::qString(&v135.name, v40->mData);
  *(_QWORD *)&v135.num_mrt = 1i64;
  *(_QWORD *)&v135.width = 0i64;
  v135.depth = 1;
  v135.array_size = 1;
  *(_DWORD *)v135.mrt_formats = -1;
  v135.target_flags = 0;
  v135.num_mips = 1;
  memset(v135.textures, 0, 85);
  UFG::qString::~qString(&result);
  v135.width = v37;
  v135.height = v38;
  v135.mrt_formats[0] = 0;
  v135.target_flags = 3;
  v135.depth_texture = this->mHalfSizeLinearDepthTarget->mDepthTexture;
  this->mHalfSizeTarget = Illusion::CreateTarget(&v135);
  Illusion::Texture::SetSamplerFilter(this->mHalfSizeLinearDepthTarget->mTargetTexture[0], 2u);
  Illusion::Texture::SetSamplerFilter(this->mHalfSizeLinearDepthTarget->mDepthTexture, 2u);
  v41 = this->mGBufferWidth >> 2;
  v42 = this->mGBufferHeight >> 2;
  v43 = UFG::qString::FormatEx(&result, "QuarterSizeLinearDepthTarget%s", description);
  UFG::qString::qString(&v141.name, v43->mData);
  *(_QWORD *)&v141.num_mrt = 1i64;
  *(_QWORD *)&v141.width = 0i64;
  v141.depth = 1;
  v141.array_size = 1;
  *(_DWORD *)v141.mrt_formats = -1;
  v141.target_flags = 0;
  v141.num_mips = 1;
  memset(v141.textures, 0, 85);
  UFG::qString::~qString(&result);
  v141.width = v41;
  v141.height = v42;
  v141.mrt_formats[0] = 14;
  v141.target_flags = 65539;
  v44 = Illusion::CreateTarget(&v141);
  this->mQuarterSizeLinearDepthTarget = v44;
  Illusion::Texture::SetSamplerFilter(v44->mTargetTexture[0], 2u);
  Illusion::Texture::SetSamplerFilter(this->mQuarterSizeLinearDepthTarget->mDepthTexture, 2u);
  if ( reflection_width && reflection_height )
  {
    v45 = UFG::qString::FormatEx(&result, "ReflectionMips%s", description);
    Illusion::CreateTargetParams::CreateTargetParams(&v124, v45->mData, 0);
    UFG::qString::~qString(&result);
    v124.width = reflection_width;
    v124.height = reflection_height;
    v124.mrt_formats[0] = 0;
    v124.target_flags = 0x20000;
    v124.num_mips = 6;
    this->mReflectionMipTarget = Illusion::CreateTarget(&v124);
    v46 = UFG::qString::FormatEx(&result, "Reflection%s", description);
    Illusion::CreateTargetParams::CreateTargetParams(&params, v46->mData, 0);
    UFG::qString::~qString(&result);
    params.width = reflection_width;
    params.height = reflection_height;
    params.mrt_formats[0] = 0;
    params.target_flags = 1;
    v47 = Illusion::CreateTarget(&params);
    this->mReflectionTarget = v47;
    Illusion::Texture::SetSamplerAddressFlags(v47->mTargetTexture[0], 0xCu);
    Illusion::Texture::SetSamplerAddressFlags(this->mReflectionMipTarget->mTargetTexture[0], 0xCu);
    UFG::qString::~qString(&params.name);
    UFG::qString::~qString(&v124.name);
  }
  else
  {
    this->mReflectionMipTarget = 0i64;
    this->mReflectionTarget = 0i64;
  }
  if ( envmap_size )
  {
    v48 = UFG::qString::FormatEx(&result, "SphericalEnvMap%s", description);
    UFG::qString::qString(&v124.name, v48->mData);
    *(_QWORD *)&v124.num_mrt = 1i64;
    *(_QWORD *)&v124.width = 0i64;
    v124.depth = 1;
    v124.array_size = 1;
    *(_DWORD *)v124.mrt_formats = -1;
    v124.target_flags = 0;
    v124.num_mips = 1;
    memset(v124.textures, 0, 85);
    UFG::qString::~qString(&result);
    *(_QWORD *)&v124.width = 0x28000000500i64;
    v124.mrt_formats[0] = 0;
    v124.target_flags = 0x20000;
    v124.num_mips = 7;
    v49 = Illusion::CreateTarget(&v124);
    this->mSphericalEnvMapTarget = v49;
    v50 = Illusion::Texture::GetSamplerAddressFlags(v49->mTargetTexture[0]);
    Illusion::Texture::SetSamplerAddressFlags(this->mSphericalEnvMapTarget->mTargetTexture[0], v50 & 0xFFFFFFFC | 2);
    UFG::qString::~qString(&v124.name);
  }
  else
  {
    this->mSphericalEnvMapTarget = 0i64;
  }
  v51 = UFG::qString::FormatEx(&result, "FullSizeScratchTargetA%s", description);
  UFG::qString::qString(&v133.name, v51->mData);
  *(_QWORD *)&v133.num_mrt = 1i64;
  *(_QWORD *)&v133.width = 0i64;
  v133.depth = 1;
  v133.array_size = 1;
  *(_DWORD *)v133.mrt_formats = -1;
  v133.target_flags = 0;
  v133.num_mips = 1;
  memset(v133.textures, 0, 85);
  UFG::qString::~qString(&result);
  *(_QWORD *)&v133.width = *(_QWORD *)&this->mGBufferWidth;
  v133.mrt_formats[0] = 0;
  v133.target_flags = 2097921;
  v133.depth_texture = this->mGBufferTarget->mDepthTexture;
  v52 = Illusion::CreateTarget(&v133);
  this->mFullSizeScratchTargetA = v52;
  Illusion::Texture::SetSamplerFilter(v52->mTargetTexture[0], 1u);
  v53 = 0;
  if ( outSettings.mFeatureLevel == FEATURE_LEVEL_D3D11_0 )
    v53 = 0x80000;
  v54 = UFG::qString::FormatEx(&result, "HalfSizeScratchTargetA%s", description);
  UFG::qString::qString(&v154.name, v54->mData);
  *(_QWORD *)&v154.num_mrt = 1i64;
  *(_QWORD *)&v154.width = 0i64;
  v154.depth = 1;
  v154.array_size = 1;
  *(_DWORD *)v154.mrt_formats = -1;
  v154.target_flags = 0;
  v154.num_mips = 1;
  memset(v154.textures, 0, 85);
  UFG::qString::~qString(&result);
  v154.width = this->mGBufferWidth >> 1;
  v154.height = this->mGBufferHeight >> 1;
  v154.mrt_formats[0] = 0;
  this->mHalfSizeScratchTargetA = Illusion::CreateTarget(&v154);
  v55 = UFG::qString::FormatEx(&result, "HalfSizeScratchTargetB%s", description);
  UFG::qString::qString(&v139.name, v55->mData);
  *(_QWORD *)&v139.num_mrt = 1i64;
  *(_QWORD *)&v139.width = 0i64;
  v139.depth = 1;
  v139.array_size = 1;
  *(_DWORD *)v139.mrt_formats = -1;
  v139.target_flags = 0;
  v139.num_mips = 1;
  memset(v139.textures, 0, 85);
  UFG::qString::~qString(&result);
  v139.width = this->mGBufferWidth >> 1;
  v139.height = this->mGBufferHeight >> 1;
  v139.mrt_formats[0] = 0;
  v139.target_flags = v53;
  this->mHalfSizeScratchTargetB = Illusion::CreateTarget(&v139);
  v56 = UFG::qString::FormatEx(&result, "HalfSizeScratchTargetC%s", description);
  UFG::qString::qString(&v136.name, v56->mData);
  *(_QWORD *)&v136.num_mrt = 1i64;
  *(_QWORD *)&v136.width = 0i64;
  v136.depth = 1;
  v136.array_size = 1;
  *(_DWORD *)v136.mrt_formats = -1;
  v136.target_flags = 0;
  v136.num_mips = 1;
  memset(v136.textures, 0, 85);
  UFG::qString::~qString(&result);
  v136.width = this->mGBufferWidth >> 1;
  v136.height = this->mGBufferHeight >> 1;
  v136.mrt_formats[0] = 0;
  v136.target_flags = v53;
  this->mHalfSizeScratchTargetC = Illusion::CreateTarget(&v136);
  v57 = UFG::qString::FormatEx(&result, "QuarterSizeScratchTargetA%s", description);
  UFG::qString::qString(&v137.name, v57->mData);
  *(_QWORD *)&v137.num_mrt = 1i64;
  *(_QWORD *)&v137.width = 0i64;
  v137.depth = 1;
  v137.array_size = 1;
  *(_DWORD *)v137.mrt_formats = -1;
  v137.target_flags = 0;
  v137.num_mips = 1;
  memset(v137.textures, 0, 85);
  UFG::qString::~qString(&result);
  v137.width = this->mGBufferWidth >> 2;
  v137.height = this->mGBufferHeight >> 2;
  v137.mrt_formats[0] = 0;
  v137.target_flags = v53;
  this->mQuarterSizeScratchTargetA = Illusion::CreateTarget(&v137);
  v58 = UFG::qString::FormatEx(&result, "QuarterSizeScratchTargetB%s", description);
  UFG::qString::qString(&v140.name, v58->mData);
  *(_QWORD *)&v140.num_mrt = 1i64;
  *(_QWORD *)&v140.width = 0i64;
  v140.depth = 1;
  v140.array_size = 1;
  *(_DWORD *)v140.mrt_formats = -1;
  v140.target_flags = 0;
  v140.num_mips = 1;
  memset(v140.textures, 0, 85);
  UFG::qString::~qString(&result);
  v140.width = this->mGBufferWidth >> 2;
  v140.height = this->mGBufferHeight >> 2;
  v140.mrt_formats[0] = 0;
  v140.target_flags = v53;
  this->mQuarterSizeScratchTargetB = Illusion::CreateTarget(&v140);
  v59 = UFG::qString::FormatEx(&result, "EighthSizeScratchTargetA%s", description);
  UFG::qString::qString(&v150.name, v59->mData);
  *(_QWORD *)&v150.num_mrt = 1i64;
  *(_QWORD *)&v150.width = 0i64;
  v150.depth = 1;
  v150.array_size = 1;
  *(_DWORD *)v150.mrt_formats = -1;
  v150.target_flags = 0;
  v150.num_mips = 1;
  memset(v150.textures, 0, 85);
  UFG::qString::~qString(&result);
  v150.width = this->mGBufferWidth >> 3;
  v150.height = this->mGBufferHeight >> 3;
  v150.mrt_formats[0] = 0;
  this->mEighthSizeScratchTargetA = Illusion::CreateTarget(&v150);
  v60 = UFG::qString::FormatEx(&result, "EighthSizeScratchTargetB%s", description);
  UFG::qString::qString(&v148.name, v60->mData);
  *(_QWORD *)&v148.num_mrt = 1i64;
  *(_QWORD *)&v148.width = 0i64;
  v148.depth = 1;
  v148.array_size = 1;
  *(_DWORD *)v148.mrt_formats = -1;
  v148.target_flags = 0;
  v148.num_mips = 1;
  memset(v148.textures, 0, 85);
  UFG::qString::~qString(&result);
  v148.width = this->mGBufferWidth >> 3;
  v148.height = this->mGBufferHeight >> 3;
  v148.mrt_formats[0] = 0;
  this->mEighthSizeScratchTargetB = Illusion::CreateTarget(&v148);
  v61 = UFG::qString::FormatEx(&result, "mSixteenthSizeScratchTargetA%s", description);
  UFG::qString::qString(&v146.name, v61->mData);
  *(_QWORD *)&v146.num_mrt = 1i64;
  *(_QWORD *)&v146.width = 0i64;
  v146.depth = 1;
  v146.array_size = 1;
  *(_DWORD *)v146.mrt_formats = -1;
  v146.target_flags = 0;
  v146.num_mips = 1;
  memset(v146.textures, 0, 85);
  UFG::qString::~qString(&result);
  v146.width = this->mGBufferWidth >> 4;
  v146.height = this->mGBufferHeight >> 4;
  v146.mrt_formats[0] = 0;
  this->mSixteenthSizeScratchTargetA = Illusion::CreateTarget(&v146);
  v62 = UFG::qString::FormatEx(&result, "mSixteenthSizeScratchTargetB%s", description);
  UFG::qString::qString(&v144.name, v62->mData);
  *(_QWORD *)&v144.num_mrt = 1i64;
  *(_QWORD *)&v144.width = 0i64;
  v144.depth = 1;
  v144.array_size = 1;
  *(_DWORD *)v144.mrt_formats = -1;
  v144.target_flags = 0;
  v144.num_mips = 1;
  memset(v144.textures, 0, 85);
  UFG::qString::~qString(&result);
  v144.width = this->mGBufferWidth >> 4;
  v144.height = this->mGBufferHeight >> 4;
  v144.mrt_formats[0] = 0;
  this->mSixteenthSizeScratchTargetB = Illusion::CreateTarget(&v144);
  v63 = UFG::qString::FormatEx(&result, "mThrityTwoSizeScratchTargetA%s", description);
  UFG::qString::qString(&v143.name, v63->mData);
  *(_QWORD *)&v143.num_mrt = 1i64;
  *(_QWORD *)&v143.width = 0i64;
  v143.depth = 1;
  v143.array_size = 1;
  *(_DWORD *)v143.mrt_formats = -1;
  v143.target_flags = 0;
  v143.num_mips = 1;
  memset(v143.textures, 0, 85);
  UFG::qString::~qString(&result);
  v143.width = this->mGBufferWidth >> 5;
  v143.height = this->mGBufferHeight >> 5;
  v143.mrt_formats[0] = 0;
  this->mThrityTwoSizeScratchTargetA = Illusion::CreateTarget(&v143);
  v64 = UFG::qString::FormatEx(&result, "mThrityTwoSizeScratchTargetB%s", description);
  UFG::qString::qString(&v152.name, v64->mData);
  *(_QWORD *)&v152.num_mrt = 1i64;
  *(_QWORD *)&v152.width = 0i64;
  v152.depth = 1;
  v152.array_size = 1;
  *(_DWORD *)v152.mrt_formats = -1;
  v152.target_flags = 0;
  v152.num_mips = 1;
  memset(v152.textures, 0, 85);
  UFG::qString::~qString(&result);
  v152.width = this->mGBufferWidth >> 5;
  v152.height = this->mGBufferHeight >> 5;
  v152.mrt_formats[0] = 0;
  this->mThrityTwoSizeScratchTargetB = Illusion::CreateTarget(&v152);
  v65 = UFG::qString::FormatEx(&result, "mSixtyFourSizeScratchTargetA%s", description);
  UFG::qString::qString(&v149.name, v65->mData);
  *(_QWORD *)&v149.num_mrt = 1i64;
  *(_QWORD *)&v149.width = 0i64;
  v149.depth = 1;
  v149.array_size = 1;
  *(_DWORD *)v149.mrt_formats = -1;
  v149.target_flags = 0;
  v149.num_mips = 1;
  memset(v149.textures, 0, 85);
  UFG::qString::~qString(&result);
  v149.width = this->mGBufferWidth >> 6;
  v149.height = this->mGBufferHeight >> 6;
  v149.mrt_formats[0] = 0;
  this->mSixtyFourSizeScratchTargetA = Illusion::CreateTarget(&v149);
  v66 = UFG::qString::FormatEx(&result, "mSixtyFourSizeScratchTargetB%s", description);
  UFG::qString::qString(&v142.name, v66->mData);
  *(_QWORD *)&v142.num_mrt = 1i64;
  *(_QWORD *)&v142.width = 0i64;
  v142.depth = 1;
  v142.array_size = 1;
  *(_DWORD *)v142.mrt_formats = -1;
  v142.target_flags = 0;
  v142.num_mips = 1;
  memset(v142.textures, 0, 85);
  UFG::qString::~qString(&result);
  v142.width = this->mGBufferWidth >> 6;
  v142.height = this->mGBufferHeight >> 6;
  v142.mrt_formats[0] = 0;
  this->mSixtyFourSizeScratchTargetB = Illusion::CreateTarget(&v142);
  v67 = this->mHalfSizeScratchTargetC->mTargetTexture[0];
  v68 = UFG::qString::FormatEx(&result, "AmbientOcclusionTarget%s", description);
  UFG::qString::qString(&v147.name, v68->mData);
  *(_QWORD *)&v147.num_mrt = 1i64;
  *(_QWORD *)&v147.width = 0i64;
  v147.depth = 1;
  v147.array_size = 1;
  *(_DWORD *)v147.mrt_formats = -1;
  v147.target_flags = 0;
  v147.num_mips = 1;
  memset(v147.textures, 0, 85);
  UFG::qString::~qString(&result);
  v147.textures[0] = v67;
  v147.depth_texture = this->mHalfSizeLinearDepthTarget->mDepthTexture;
  v147.target_flags = 771;
  this->mAmbientOcclusionAliasTarget = Illusion::CreateTarget(&v147);
  v69 = this->mHalfSizeScratchTargetB->mTargetTexture[0];
  v70 = UFG::qString::FormatEx(&result, "SkyOcclusionTarget%s", description);
  UFG::qString::qString(&v151.name, v70->mData);
  *(_QWORD *)&v151.num_mrt = 1i64;
  *(_QWORD *)&v151.width = 0i64;
  v151.depth = 1;
  v151.array_size = 1;
  *(_DWORD *)v151.mrt_formats = -1;
  v151.target_flags = 0;
  v151.num_mips = 1;
  memset(v151.textures, 0, 85);
  UFG::qString::~qString(&result);
  v151.textures[0] = v69;
  v151.depth_texture = this->mHalfSizeLinearDepthTarget->mDepthTexture;
  v151.target_flags = 771;
  this->mSkyOcclusionAliasTarget = Illusion::CreateTarget(&v151);
  v71 = UFG::qString::FormatEx(&result, "QuarterSizeVolumetricTargetA%s", description);
  UFG::qString::qString(&v131.name, v71->mData);
  *(_QWORD *)&v131.num_mrt = 1i64;
  *(_QWORD *)&v131.width = 0i64;
  v131.depth = 1;
  v131.array_size = 1;
  *(_DWORD *)v131.mrt_formats = -1;
  v131.target_flags = 0;
  v131.num_mips = 1;
  memset(v131.textures, 0, 85);
  UFG::qString::~qString(&result);
  v131.width = this->mGBufferWidth >> 2;
  v131.height = this->mGBufferHeight >> 2;
  v131.mrt_formats[0] = 0;
  v131.target_flags = 1;
  v131.depth_texture = this->mQuarterSizeLinearDepthTarget->mDepthTexture;
  this->mQuarterSizeVolumetricTarget = Illusion::CreateTarget(&v131);
  v72 = UFG::qString::FormatEx(&result, "HalfSizeVolumetricTargetA%s", description);
  UFG::qString::qString(&v129.name, v72->mData);
  *(_QWORD *)&v129.num_mrt = 1i64;
  *(_QWORD *)&v129.width = 0i64;
  v129.depth = 1;
  v129.array_size = 1;
  *(_DWORD *)v129.mrt_formats = -1;
  v129.target_flags = 0;
  v129.num_mips = 1;
  memset(v129.textures, 0, 85);
  UFG::qString::~qString(&result);
  v129.width = this->mGBufferWidth >> 1;
  v129.height = this->mGBufferHeight >> 1;
  v129.mrt_formats[0] = 0;
  v129.target_flags = 1;
  v129.depth_texture = this->mHalfSizeLinearDepthTarget->mDepthTexture;
  this->mHalfSizeVolumetricTarget = Illusion::CreateTarget(&v129);
  BackBufferTarget = Render::GetBackBufferTarget();
  LODWORD(v69) = BackBufferTarget->mWidth;
  mHeight = BackBufferTarget->mHeight;
  v75 = UFG::qString::FormatEx(&result, "DepthOfField_NearBlur%s", description);
  UFG::qString::qString(&v145.name, v75->mData);
  *(_QWORD *)&v145.num_mrt = 1i64;
  *(_QWORD *)&v145.width = 0i64;
  v145.depth = 1;
  v145.array_size = 1;
  *(_DWORD *)v145.mrt_formats = -1;
  v145.target_flags = 0;
  v145.num_mips = 1;
  memset(v145.textures, 0, 85);
  UFG::qString::~qString(&result);
  v145.width = (unsigned int)v69 >> 2;
  v145.height = mHeight >> 2;
  v145.mrt_formats[0] = 0;
  this->mNearBlur = Illusion::CreateTarget(&v145);
  if ( !this->mCascadeShadowTarget )
  {
    v76 = UFG::qString::FormatEx(&result, "CascadeTarget%s", description);
    UFG::qString::qString(&v124.name, v76->mData);
    *(_QWORD *)&v124.num_mrt = 1i64;
    *(_QWORD *)&v124.width = 0i64;
    v124.depth = 1;
    v124.array_size = 1;
    *(_DWORD *)v124.mrt_formats = -1;
    v124.target_flags = 0;
    v124.num_mips = 1;
    memset(v124.textures, 0, 85);
    UFG::qString::~qString(&result);
    v124.width = this->mCascadeShadowSize;
    v124.height = v124.width;
    v124.mrt_formats[0] = 0;
    v124.num_mrt = 0;
    v124.target_flags = 2097795;
    this->mCascadeShadowTarget = Illusion::CreateTarget(&v124);
    UFG::qString::~qString(&v124.name);
  }
  this->mCascadeShadowTexture = this->mCascadeShadowTarget->mDepthTexture;
  v77 = UFG::qString::FormatEx(&result, "HalfSizeShadowTarget%s", description);
  UFG::qString::qString(&v127.name, v77->mData);
  *(_QWORD *)&v127.num_mrt = 1i64;
  *(_QWORD *)&v127.width = 0i64;
  v127.depth = 1;
  v127.array_size = 1;
  *(_DWORD *)v127.mrt_formats = -1;
  v127.target_flags = 0;
  v127.num_mips = 1;
  memset(v127.textures, 0, 85);
  UFG::qString::~qString(&result);
  v127.width = this->mCascadeShadowSize >> 1;
  v127.height = v127.width;
  v127.mrt_formats[0] = 0;
  v127.num_mrt = 0;
  v127.target_flags = 3;
  v78 = Illusion::CreateTarget(&v127);
  this->mHalfSizeShadowTarget = v78;
  if ( v78 )
  {
    mDepthTexture = v78->mDepthTexture;
    v80 = Illusion::Texture::GetSamplerAddressFlags(mDepthTexture);
    Illusion::Texture::SetSamplerState(mDepthTexture, 2u, v80 | 3);
  }
  v81 = UFG::qString::FormatEx(&result, "QuarterSizeShadowTarget%s", description);
  UFG::qString::qString(&v134.name, v81->mData);
  *(_QWORD *)&v134.num_mrt = 1i64;
  *(_QWORD *)&v134.width = 0i64;
  v134.depth = 1;
  v134.array_size = 1;
  *(_DWORD *)v134.mrt_formats = -1;
  v134.target_flags = 0;
  v134.num_mips = 1;
  memset(v134.textures, 0, 85);
  UFG::qString::~qString(&result);
  v134.width = this->mCascadeShadowSize >> 2;
  v134.height = v134.width;
  v134.mrt_formats[0] = 0;
  v134.num_mrt = 0;
  v134.target_flags = 3;
  v82 = Illusion::CreateTarget(&v134);
  this->mQuarterSizeShadowTarget = v82;
  if ( v82 )
  {
    v83 = v82->mDepthTexture;
    v84 = Illusion::Texture::GetSamplerAddressFlags(v83);
    Illusion::Texture::SetSamplerState(v83, 2u, v84 | 3);
  }
  v85 = UFG::qString::FormatEx(&result, "SingleShadowTarget%s", description);
  UFG::qString::qString(&v126.name, v85->mData);
  *(_QWORD *)&v126.num_mrt = 1i64;
  *(_QWORD *)&v126.width = 0i64;
  v126.depth = 1;
  v126.array_size = 1;
  *(_DWORD *)v126.mrt_formats = -1;
  v126.target_flags = 0;
  v126.num_mips = 1;
  memset(v126.textures, 0, 85);
  UFG::qString::~qString(&result);
  v126.width = this->mSpotShadowSize;
  v126.height = v126.width;
  v126.mrt_formats[0] = 0;
  v126.num_mrt = 0;
  v126.target_flags = 707;
  v86 = Illusion::CreateTarget(&v126);
  this->mSingleShadowTarget = v86;
  v87 = v86->mTargetTexture[0];
  if ( v87 )
  {
    v88 = Illusion::Texture::GetSamplerAddressFlags(v86->mTargetTexture[0]);
    Illusion::Texture::SetSamplerState(v87, 2u, v88 | 3);
  }
  this->mSingleShadowTarget->mDepthTexture->mFilter = 1;
  this->mSingleShadowSubtexture = this->mSingleShadowTarget->mDepthTexture;
  v89 = UFG::qString::FormatEx(&result, "HalfSizeSingleShadowTarget%s", description);
  UFG::qString::qString(&v132.name, v89->mData);
  *(_QWORD *)&v132.num_mrt = 1i64;
  *(_QWORD *)&v132.width = 0i64;
  v132.depth = 1;
  v132.array_size = 1;
  *(_DWORD *)v132.mrt_formats = -1;
  v132.target_flags = 0;
  v132.num_mips = 1;
  memset(v132.textures, 0, 85);
  UFG::qString::~qString(&result);
  v132.width = this->mSpotShadowSize >> 1;
  v132.height = v132.width;
  v132.mrt_formats[0] = 0;
  v132.num_mrt = 0;
  v132.target_flags = 1049091;
  v90 = Illusion::CreateTarget(&v132);
  this->mHalfSizeSingleShadowTarget = v90;
  v91 = v90->mDepthTexture;
  v92 = Illusion::Texture::GetSamplerAddressFlags(v91);
  Illusion::Texture::SetSamplerState(v91, 2u, v92 | 3);
  if ( !this->mCharacterShadowTarget )
  {
    v93 = UFG::qString::FormatEx(&result, "CharacterShadowTarget%s", description);
    UFG::qString::qString(&v124.name, v93->mData);
    *(_QWORD *)&v124.num_mrt = 1i64;
    *(_QWORD *)&v124.width = 0i64;
    v124.depth = 1;
    v124.array_size = 1;
    *(_DWORD *)v124.mrt_formats = -1;
    v124.target_flags = 0;
    v124.num_mips = 1;
    memset(v124.textures, 0, 85);
    UFG::qString::~qString(&result);
    v124.width = this->mCharacterShadowSize;
    v124.height = v124.width;
    v124.mrt_formats[0] = 0;
    v124.num_mrt = 0;
    v124.target_flags = 131;
    this->mCharacterShadowTarget = Illusion::CreateTarget(&v124);
    UFG::qString::~qString(&v124.name);
  }
  this->mCharacterShadowTexture = this->mCharacterShadowTarget->mDepthTexture;
  v94 = UFG::qString::FormatEx(&result, "HeightmapTarget%s", description);
  UFG::qString::qString(&v128.name, v94->mData);
  *(_QWORD *)&v128.num_mrt = 1i64;
  *(_QWORD *)&v128.width = 0i64;
  v128.depth = 1;
  v128.array_size = 1;
  *(_DWORD *)v128.mrt_formats = -1;
  v128.target_flags = 0;
  v128.num_mips = 1;
  memset(v128.textures, 0, 85);
  UFG::qString::~qString(&result);
  v128.width = this->mCascadeShadowSize >> 2;
  v128.height = v128.width;
  v128.mrt_formats[0] = 0;
  v128.num_mrt = 0;
  v128.target_flags = 3;
  v95 = Illusion::CreateTarget(&v128);
  this->mHeightmapTarget = v95;
  v96 = v95->mDepthTexture;
  v97 = Illusion::Texture::GetSamplerAddressFlags(v96);
  Illusion::Texture::SetSamplerState(v96, 2u, v97 | 3);
  v98 = UFG::qString::FormatEx(&result, "HeightmapShadowAlias%s", description);
  this->mHeightmapShadowTextureAlias = Illusion::CreateTextureAlias(
                                         v98->mData,
                                         this->mHeightmapTarget->mDepthTexture,
                                         FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v99 = Illusion::Texture::GetSamplerAddressFlags(this->mHeightmapShadowTextureAlias);
  Illusion::Texture::SetSamplerState(this->mHeightmapShadowTextureAlias, 1u, v99 | 3);
  v100 = UFG::qString::FormatEx(&result, "CascadeTargetAlias%s", description);
  this->mCascadeShadowTextureAliasDepth = Illusion::CreateTextureAlias(
                                            v100->mData,
                                            this->mCascadeShadowTexture,
                                            FORMAT_D24S8);
  UFG::qString::~qString(&result);
  v101 = Illusion::Texture::GetSamplerAddressFlags(this->mCascadeShadowTextureAliasDepth);
  Illusion::Texture::SetSamplerState(this->mCascadeShadowTextureAliasDepth, 2u, v101 | 3);
  v102 = UFG::qString::FormatEx(&result, "HalfSizeShadowAlias%s", description);
  this->mHalfSizeShadowAliasTexture = Illusion::CreateTextureAlias(
                                        v102->mData,
                                        this->mHalfSizeShadowTarget->mDepthTexture,
                                        FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v103 = Illusion::Texture::GetSamplerAddressFlags(this->mHalfSizeShadowAliasTexture);
  Illusion::Texture::SetSamplerState(this->mHalfSizeShadowAliasTexture, 1u, v103 | 3);
  v104 = UFG::qString::FormatEx(&result, "QuarterSizeShadowAlias%s", description);
  this->mQuarterSizeShadowAliasTexture = Illusion::CreateTextureAlias(
                                           v104->mData,
                                           this->mQuarterSizeShadowTarget->mDepthTexture,
                                           FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v105 = Illusion::Texture::GetSamplerAddressFlags(this->mQuarterSizeShadowAliasTexture);
  Illusion::Texture::SetSamplerState(this->mQuarterSizeShadowAliasTexture, 1u, v105 | 3);
  v106 = UFG::qString::FormatEx(&result, "CharacterShadowTargetAlias%s", description);
  this->mCharacterShadowTextureAliasDepth = Illusion::CreateTextureAlias(
                                              v106->mData,
                                              this->mCharacterShadowTexture,
                                              FORMAT_D24S8);
  UFG::qString::~qString(&result);
  v107 = Illusion::Texture::GetSamplerAddressFlags(this->mCharacterShadowTextureAliasDepth);
  Illusion::Texture::SetSamplerState(this->mCharacterShadowTextureAliasDepth, 2u, v107 | 3);
  v108 = UFG::qString::FormatEx(&result, "SingleShadowTargetAlias%s", description);
  this->mSingleShadowTextureAliasDepth = Illusion::CreateTextureAlias(
                                           v108->mData,
                                           this->mSingleShadowSubtexture,
                                           FORMAT_D24S8);
  UFG::qString::~qString(&result);
  v109 = Illusion::Texture::GetSamplerAddressFlags(this->mSingleShadowTextureAliasDepth);
  Illusion::Texture::SetSamplerState(this->mSingleShadowTextureAliasDepth, 2u, v109 | 3);
  v110 = UFG::qString::FormatEx(&result, "HalfSizeSingleShadowAliasTexture%s", description);
  this->mHalfSizeSingleShadowAliasTexture = Illusion::CreateTextureAlias(
                                              v110->mData,
                                              this->mHalfSizeSingleShadowTarget->mDepthTexture,
                                              FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v111 = Illusion::Texture::GetSamplerAddressFlags(this->mHalfSizeSingleShadowAliasTexture);
  Illusion::Texture::SetSamplerState(this->mHalfSizeSingleShadowAliasTexture, 1u, v111 | 3);
  if ( aaQuality == AA_QUALITY_NORMAL || this->mAAResultTarget )
  {
    this->mAAResultTarget = 0i64;
  }
  else
  {
    v112 = UFG::qString::FormatEx(&result, "AAResult%s", description);
    Illusion::CreateTargetParams::CreateTargetParams(&params, v112->mData, 0);
    UFG::qString::~qString(&result);
    params.width = scene_output_width;
    params.height = scene_output_height;
    params.mrt_formats[0] = this->mGBufferTarget->mTargetTexture[0]->mFormat;
    params.target_flags = 1;
    this->mAAResultTarget = Illusion::CreateTarget(&params);
    UFG::qString::~qString(&params.name);
  }
  if ( bLightMRT )
  {
    v113 = UFG::qString::FormatEx(&result, "DirectionalOcclusion%s", description);
    UFG::qString::qString(&v124.name, v113->mData);
    *(_QWORD *)&v124.num_mrt = 1i64;
    *(_QWORD *)&v124.width = 0i64;
    v124.depth = 1;
    v124.array_size = 1;
    *(_DWORD *)v124.mrt_formats = -1;
    v124.target_flags = 0;
    v124.num_mips = 1;
    memset(v124.textures, 0, 85);
    UFG::qString::~qString(&result);
    *(_QWORD *)&v124.width = *(_QWORD *)&this->mGBufferWidth;
    v124.mrt_formats[0] = this->mLightBufferTarget->mTargetTexture[0]->mFormat;
    this->mDirectionalOcclusionTarget = Illusion::CreateTarget(&v124);
    v114 = UFG::qString::FormatEx(&result, "LightBuffer%s", description);
    this->mLightBufferMain = Illusion::CreateTextureAlias(
                               v114->mData,
                               this->mLightBufferTarget->mTargetTexture[0],
                               FORMAT_X16FY16FZ16FW16F);
    UFG::qString::~qString(&result);
    UFG::qString::~qString(&v124.name);
  }
  else
  {
    this->mLightBufferMain = 0i64;
    this->mDirectionalOcclusionTarget = 0i64;
  }
  mFeatureLevel = outSettings.mFeatureLevel;
  if ( outSettings.mFeatureLevel == FEATURE_LEVEL_D3D11_0 && outSettings.mSSAO >= SSAO_HIGH )
  {
    v116 = UFG::qString::FormatEx(&result, "QuarterSizeScratchAPointSample%s", description);
    this->mQuarterSizeScratchAPointSampleTexture = Illusion::CreateTextureAlias(
                                                     v116->mData,
                                                     this->mQuarterSizeScratchTargetA->mTargetTexture[0],
                                                     FORMAT_A8R8G8B8);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(this->mQuarterSizeScratchAPointSampleTexture, 2u);
    v117 = UFG::qString::FormatEx(&result, "QuarterSizeScratchBPointSample%s", description);
    this->mQuarterSizeScratchBPointSampleTexture = Illusion::CreateTextureAlias(
                                                     v117->mData,
                                                     this->mQuarterSizeScratchTargetB->mTargetTexture[0],
                                                     FORMAT_A8R8G8B8);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(this->mQuarterSizeScratchBPointSampleTexture, 2u);
    v118 = this->mQuarterSizeScratchTargetA->mTargetTexture[0];
    v119 = UFG::qString::FormatEx(&result, "QuarterAmbientOcclusionTarget%s", description);
    Illusion::CreateTargetParams::CreateTargetParams(&params, v119->mData, 0);
    UFG::qString::~qString(&result);
    params.textures[0] = v118;
    params.depth_texture = this->mQuarterSizeLinearDepthTarget->mDepthTexture;
    params.target_flags = 771;
    v120 = Illusion::CreateTarget(&params);
    this->mQuarterSizeAmbientOcclusionTarget = v120;
    this->mQuarterSizeAmbientOcclusionAliasUAV = Illusion::UnorderedAccessView::Create(v120->mTargetTexture[0]);
    this->mQuarterSizeAmbientOcclusionScratchUAV = Illusion::UnorderedAccessView::Create(this->mQuarterSizeScratchTargetB->mTargetTexture[0]);
    UFG::qString::~qString(&params.name);
    mFeatureLevel = outSettings.mFeatureLevel;
  }
  else
  {
    this->mQuarterSizeScratchAPointSampleTexture = 0i64;
    this->mQuarterSizeScratchBPointSampleTexture = 0i64;
    this->mQuarterSizeAmbientOcclusionTarget = 0i64;
    this->mQuarterSizeAmbientOcclusionAliasUAV = 0i64;
    this->mQuarterSizeAmbientOcclusionScratchUAV = 0i64;
  }
  if ( mFeatureLevel == FEATURE_LEVEL_D3D11_0 )
  {
    v121 = UFG::qString::FormatEx(&result, "HalfSizeScratchCPointSample%s", description);
    this->mHalfSizeScratchCPointSampleTexture = Illusion::CreateTextureAlias(
                                                  v121->mData,
                                                  this->mHalfSizeScratchTargetC->mTargetTexture[0],
                                                  FORMAT_A8R8G8B8);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(this->mHalfSizeScratchCPointSampleTexture, 2u);
    v122 = UFG::qString::FormatEx(&result, "HalfSizeScratchBPointSample%s", description);
    this->mHalfSizeScratchBPointSampleTexture = Illusion::CreateTextureAlias(
                                                  v122->mData,
                                                  this->mHalfSizeScratchTargetB->mTargetTexture[0],
                                                  FORMAT_A8R8G8B8);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(this->mHalfSizeScratchBPointSampleTexture, 2u);
    this->mAmbientOcclusionAliasUAV = Illusion::UnorderedAccessView::Create(this->mAmbientOcclusionAliasTarget->mTargetTexture[0]);
    this->mAmbientOcclusionScratchUAV = Illusion::UnorderedAccessView::Create(this->mHalfSizeScratchTargetB->mTargetTexture[0]);
  }
  else
  {
    this->mHalfSizeScratchCPointSampleTexture = 0i64;
    this->mHalfSizeScratchBPointSampleTexture = 0i64;
    this->mAmbientOcclusionAliasUAV = 0i64;
    this->mAmbientOcclusionScratchUAV = 0i64;
  }
  _((AMD_HD3D *)this->mRenderContextPlat);
  this->mTargetsCreated = 1;
  UFG::qString::~qString(&v128.name);
  UFG::qString::~qString(&v132.name);
  UFG::qString::~qString(&v126.name);
  UFG::qString::~qString(&v134.name);
  UFG::qString::~qString(&v127.name);
  UFG::qString::~qString(&v145.name);
  UFG::qString::~qString(&v129.name);
  UFG::qString::~qString(&v131.name);
  UFG::qString::~qString(&v151.name);
  UFG::qString::~qString(&v147.name);
  UFG::qString::~qString(&v142.name);
  UFG::qString::~qString(&v149.name);
  UFG::qString::~qString(&v152.name);
  UFG::qString::~qString(&v143.name);
  UFG::qString::~qString(&v144.name);
  UFG::qString::~qString(&v146.name);
  UFG::qString::~qString(&v148.name);
  UFG::qString::~qString(&v150.name);
  UFG::qString::~qString(&v140.name);
  UFG::qString::~qString(&v137.name);
  UFG::qString::~qString(&v136.name);
  UFG::qString::~qString(&v139.name);
  UFG::qString::~qString(&v154.name);
  UFG::qString::~qString(&v133.name);
  UFG::qString::~qString(&v141.name);
  UFG::qString::~qString(&v135.name);
  UFG::qString::~qString(&v138.name);
  UFG::qString::~qString(&v153.name);
  UFG::qString::~qString(&v125.name);
  UFG::qString::~qString(&v130.name);
  UFG::qString::~qString(&v155.name);
}

// File Line: 797
// RVA: 0x3FC60
void __fastcall UFG::RenderContext::CreateMaterials(UFG::RenderContext *this)
{
  Illusion::Target *mGBufferTarget; // rax
  Illusion::Texture *v3; // r12
  Illusion::Texture *v4; // r13
  Illusion::Texture *v5; // r15
  Illusion::Texture *mDepthTextureCopy; // r14
  unsigned int v7; // eax
  Illusion::Material *v8; // rdi
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  unsigned int mUID; // ebx
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  unsigned int v16; // ebx
  int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ebx
  int v20; // eax
  unsigned int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  unsigned int v29; // eax
  int v30; // ebx
  int v31; // eax
  UFG::qResourceWarehouse *v32; // rax
  __int64 mOffset; // rax
  _WORD *v34; // rax
  __int64 v35; // rax
  _WORD *v36; // rax
  unsigned int v37; // eax
  Illusion::Material *v38; // rdi
  int v39; // ebx
  int v40; // eax
  unsigned int v41; // ebx
  int v42; // eax
  unsigned int v43; // ebx
  unsigned int v44; // eax
  unsigned int v45; // ebx
  int v46; // eax
  int v47; // eax
  unsigned int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  UFG::qResourceWarehouse *v52; // rax
  unsigned int v53; // eax
  Illusion::Material *v54; // rdi
  int v55; // ebx
  int v56; // eax
  unsigned int v57; // ebx
  int v58; // eax
  unsigned int v59; // ebx
  unsigned int v60; // eax
  unsigned int v61; // ebx
  int v62; // eax
  int v63; // eax
  unsigned int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  UFG::qResourceWarehouse *v68; // rax
  unsigned int v69; // eax
  Illusion::Material *v70; // rdi
  int v71; // ebx
  int v72; // eax
  unsigned int v73; // ebx
  int v74; // eax
  unsigned int v75; // ebx
  unsigned int v76; // eax
  unsigned int v77; // ebx
  int v78; // eax
  int v79; // eax
  unsigned int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  UFG::qResourceWarehouse *v84; // rax
  unsigned int v85; // eax
  Illusion::Material *v86; // rdi
  int v87; // ebx
  int v88; // eax
  unsigned int v89; // ebx
  int v90; // eax
  unsigned int v91; // ebx
  unsigned int v92; // eax
  unsigned int v93; // ebx
  int v94; // eax
  int v95; // eax
  unsigned int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // eax
  UFG::qResourceWarehouse *v100; // rax
  unsigned int v101; // eax
  Illusion::Material *v102; // rdi
  int v103; // ebx
  int v104; // eax
  unsigned int v105; // ebx
  int v106; // eax
  unsigned int v107; // eax
  int v108; // eax
  unsigned int v109; // ebx
  unsigned int v110; // ebx
  unsigned int v111; // eax
  int v112; // ebx
  int v113; // eax
  unsigned int v114; // ebx
  int v115; // eax
  unsigned int v116; // ebx
  int v117; // eax
  UFG::qResourceWarehouse *v118; // rax
  unsigned int v119; // esi
  UFG::qResourceData *v120; // rbx
  UFG::qResourceWarehouse *v121; // rax
  unsigned int v122; // eax
  Illusion::Material *v123; // rdi
  int v124; // eax
  int v125; // eax
  unsigned int v126; // eax
  UFG::qResourceWarehouse *v127; // rax
  UFG::qResourceData *v128; // rbx
  UFG::qResourceWarehouse *v129; // rax
  UFG::qResourceData *v130; // rax
  UFG::qResourceData *v131; // rbx
  UFG::qResourceWarehouse *v132; // rax
  unsigned int v133; // eax
  Illusion::Material *v134; // rdi
  int v135; // eax
  int v136; // eax
  unsigned int v137; // eax
  int v138; // eax
  unsigned int v139; // eax
  int v140; // eax
  UFG::qResourceWarehouse *v141; // rax
  unsigned int v142; // eax
  Illusion::Material *v143; // rax
  Illusion::Material *v144; // rdi
  int v145; // eax
  int v146; // eax
  unsigned int v147; // eax
  int v148; // eax
  int v149; // eax
  unsigned int v150; // eax
  int v151; // eax
  UFG::qResourceWarehouse *v152; // rax
  unsigned int v153; // eax
  Illusion::Material *v154; // rdi
  int v155; // eax
  int v156; // eax
  unsigned int v157; // eax
  int v158; // eax
  int v159; // eax
  unsigned int v160; // eax
  UFG::qResourceWarehouse *v161; // rax
  __int64 v162; // rax
  _WORD *v163; // rax
  __int64 v164; // rax
  _WORD *v165; // rax
  unsigned int v166; // eax
  Illusion::Material *v167; // rax
  Illusion::Material *v168; // rdi
  int v169; // eax
  unsigned int v170; // ebx
  int v171; // eax
  unsigned int v172; // ebx
  unsigned int v173; // eax
  unsigned int v174; // ebx
  int v175; // eax
  int v176; // eax
  unsigned int v177; // eax
  unsigned int v178; // ebx
  int v179; // eax
  unsigned int v180; // ebx
  int v181; // eax
  unsigned int v182; // ebx
  int v183; // eax
  unsigned int v184; // ebx
  int v185; // eax
  int v186; // eax
  int v187; // ebx
  unsigned int v188; // eax
  UFG::qResourceWarehouse *v189; // rax
  unsigned int v190; // eax
  Illusion::Material *v191; // rax
  Illusion::Material *v192; // rdi
  int v193; // eax
  int v194; // eax
  unsigned int v195; // ebx
  unsigned int v196; // eax
  int v197; // eax
  int v198; // eax
  unsigned int v199; // eax
  UFG::qResourceWarehouse *v200; // rax
  unsigned int v201; // eax
  Illusion::Material *v202; // rdi
  int v203; // eax
  int v204; // ebx
  int v205; // eax
  int v206; // eax
  unsigned int v207; // ebx
  unsigned int v208; // eax
  unsigned int v209; // ebx
  int v210; // eax
  int v211; // eax
  unsigned int v212; // eax
  UFG::qResourceWarehouse *v213; // rax
  unsigned int v214; // eax
  Illusion::Material *v215; // rdi
  int v216; // ebx
  int v217; // eax
  unsigned int v218; // ebx
  int v219; // eax
  unsigned int v220; // eax
  int v221; // eax
  UFG::qResourceWarehouse *v222; // rax
  __int64 v223; // rax
  _WORD *v224; // rax
  __int64 v225; // rax
  _WORD *v226; // rax
  unsigned int v227; // eax
  Illusion::Material *v228; // rdi
  int v229; // ebx
  int v230; // eax
  int v231; // eax
  unsigned int v232; // eax
  int v233; // ebx
  int v234; // eax
  unsigned int v235; // ebx
  int v236; // eax
  UFG::qResourceWarehouse *v237; // rax
  unsigned int v238; // eax
  Illusion::Material *v239; // rdi
  int v240; // ebx
  int v241; // eax
  int v242; // eax
  unsigned int v243; // eax
  int v244; // ebx
  int v245; // eax
  unsigned int v246; // ebx
  int v247; // eax
  UFG::qResourceWarehouse *v248; // rax
  unsigned int v249; // eax
  Illusion::Material *v250; // rdi
  int v251; // ebx
  int v252; // eax
  int v253; // eax
  unsigned int v254; // eax
  int v255; // ebx
  int v256; // eax
  unsigned int v257; // ebx
  int v258; // eax
  UFG::qResourceWarehouse *v259; // rax
  unsigned int v260; // eax
  Illusion::Material *v261; // rdi
  int v262; // ebx
  int v263; // eax
  int v264; // eax
  unsigned int v265; // eax
  unsigned int v266; // ebx
  int v267; // eax
  int v268; // eax
  int v269; // ebx
  int v270; // eax
  unsigned int v271; // ebx
  unsigned int v272; // eax
  int v273; // eax
  unsigned int v274; // ebx
  int v275; // eax
  UFG::qResourceWarehouse *v276; // rax
  unsigned int v277; // eax
  Illusion::Material *v278; // rdi
  int v279; // ebx
  int v280; // eax
  unsigned int v281; // ebx
  unsigned int v282; // eax
  int v283; // eax
  int v284; // eax
  int v285; // ebx
  int v286; // eax
  int v287; // eax
  int v288; // ebx
  unsigned int v289; // eax
  int v290; // eax
  int v291; // ebx
  int v292; // eax
  unsigned int v293; // eax
  unsigned int v294; // ebx
  int v295; // eax
  UFG::qResourceWarehouse *v296; // rax
  unsigned int v297; // eax
  Illusion::Material *v298; // rdi
  int v299; // ebx
  int v300; // eax
  unsigned int v301; // ebx
  int v302; // eax
  unsigned int v303; // eax
  int v304; // eax
  unsigned int v305; // ebx
  int v306; // eax
  UFG::qResourceWarehouse *v307; // rax
  unsigned int v308; // eax
  Illusion::Material *v309; // rdi
  int v310; // ebx
  int v311; // eax
  unsigned int v312; // ebx
  int v313; // eax
  unsigned int v314; // eax
  int v315; // eax
  unsigned int v316; // ebx
  UFG::qResourceWarehouse *v317; // rax
  unsigned int v318; // eax
  Illusion::Material *v319; // rdi
  int v320; // ebx
  int v321; // eax
  int v322; // eax
  unsigned int v323; // eax
  int v324; // eax
  unsigned int v325; // ebx
  int v326; // eax
  unsigned int v327; // ebx
  unsigned int v328; // eax
  unsigned int v329; // ebx
  int v330; // eax
  UFG::qResourceWarehouse *v331; // rax
  unsigned int v332; // eax
  Illusion::Material *v333; // rax
  Illusion::Material *v334; // rdi
  int v335; // eax
  int v336; // eax
  unsigned int v337; // eax
  int v338; // eax
  unsigned int v339; // ebx
  int v340; // eax
  unsigned int v341; // eax
  UFG::qResourceWarehouse *v342; // rax
  unsigned int v343; // eax
  Illusion::Material *v344; // rax
  Illusion::Material *v345; // rbx
  int v346; // eax
  int v347; // eax
  unsigned int v348; // eax
  int v349; // eax
  int v350; // eax
  unsigned int v351; // eax
  UFG::qResourceWarehouse *v352; // rax
  Illusion::Texture *v353; // [rsp+60h] [rbp+8h]

  mGBufferTarget = this->mGBufferTarget;
  v3 = mGBufferTarget->mTargetTexture[0];
  v4 = mGBufferTarget->mTargetTexture[1];
  v5 = mGBufferTarget->mTargetTexture[2];
  mDepthTextureCopy = mGBufferTarget->mDepthTextureCopy;
  v353 = this->mLightBufferTarget->mTargetTexture[0];
  v7 = UFG::qStringHashUpper32("DeferredLight", 0xFFFFFFFF);
  v8 = Illusion::Factory::NewMaterial("DeferredLight", v7, 0xCu, 0i64, 0i64, 0i64);
  v9 = UFG::qStringHash32("DRSPOTLIGHTSHADOWS", 0xFFFFFFFF);
  LOWORD(v8[1].mNode.mChild[0]) = 0;
  v10 = v9;
  HIDWORD(v8[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v8[1].mTypeUID = -1957338719;
  LODWORD(v8[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v10;
  LODWORD(v8[1].mNode.mParent) = v11;
  mUID = v3->mNode.mUID;
  *(_WORD *)&v8[1].mDebugName[12] = 0;
  *(_DWORD *)&v8[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v8[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v8[1].mStateBlockMask.mFlags[0]) = mUID;
  *(_DWORD *)&v8[1].mDebugName[4] = v13;
  v14 = v4->mNode.mUID;
  LOWORD(v8[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v8[2].mNode.mUID = v14;
  v8[1].mNumParams = v15;
  v16 = mDepthTextureCopy->mNode.mUID;
  LOWORD(v8[2].mTypeUID) = 0;
  HIDWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v8[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v8[2].mDebugName[28] = v16;
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v17;
  LOWORD(v8[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[3].mNode.mChild[1]) = 315097330;
  LODWORD(v8[3].mNode.mChild[0]) = -1032465351;
  LOWORD(v8[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v8[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v8[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v8[3].mDebugName[12] = -929296280;
  v8[3].mNode.mUID = v18;
  v19 = this->mSingleShadowTarget->mDepthTexture->mNode.mUID;
  *((_WORD *)&v8[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v8[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("texShadow", 0xFFFFFFFF);
  LODWORD(v8[4].mNode.mParent) = -1958479169;
  LODWORD(v8[3].mMaterialUser.mOffset) = v19;
  *(_DWORD *)&v8[3].mDebugName[28] = v20;
  v21 = v5->mNode.mUID;
  LOWORD(v8[4].mNode.mChild[1]) = 0;
  HIDWORD(v8[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v22 = UFG::qStringHash32("texAmbient", 0xFFFFFFFF);
  *(_DWORD *)&v8[4].mDebugName[4] = -1958479169;
  v8[4].mTypeUID = v21;
  LODWORD(v8[4].mNode.mChild[0]) = v22;
  v23 = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  *(_WORD *)&v8[4].mDebugName[20] = 0;
  v24 = v23;
  *(_DWORD *)&v8[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v25 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  v8[4].mNumParams = -1958479169;
  LODWORD(v8[4].mStateBlockMask.mFlags[1]) = v24;
  *(_DWORD *)&v8[4].mDebugName[12] = v25;
  v26 = UFG::qStringHashUpper32("FX_NOISESINCOS", 0xFFFFFFFF);
  LOWORD(v8[5].mNode.mParent) = 0;
  v27 = v26;
  HIDWORD(v8[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v28 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v8[5].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1958479169;
  LODWORD(v8[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) = v27;
  LODWORD(v8[4].mMaterialUser.mOffset) = v28;
  *(_WORD *)&v8[5].mDebugName[4] = 0;
  *(_DWORD *)v8[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v29 = UFG::qStringHash32("texDistAtten", 0xFFFFFFFF);
  LODWORD(v8[5].mStateBlockMask.mFlags[0]) = -1958479169;
  *((_DWORD *)&v8[5].UFG::qResourceData + 22) = 0;
  v8[5].mTypeUID = v29;
  v30 = UFG::qStringHashUpper32("25c7d589-9646-416c-985c-57db93552ed3", 0xFFFFFFFF);
  LOWORD(v8[5].mNumParams) = 0;
  HIDWORD(v8[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v31 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v8[6].mNode.mUID = 1292158962;
  LODWORD(v8[6].mNode.mChild[1]) = v30;
  LODWORD(v8[5].mStateBlockMask.mFlags[1]) = v31;
  v32 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v32, v8);
  if ( LODWORD(v8[3].mNode.mChild[0]) != -1032465351 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v8[2].mNumParams,
      (unsigned int)v8[3].mNode.mChild[1],
      0xC275D439);
    mOffset = v8->mMaterialUser.mOffset;
    if ( mOffset )
      v34 = (_WORD *)((char *)&v8->mMaterialUser + mOffset);
    else
      v34 = 0i64;
    *v34 |= 0x20u;
  }
  if ( *(_DWORD *)&v8[3].mDebugName[12] != -929296280 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v8[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
      *(_DWORD *)&v8[3].mDebugName[20],
      0xC89C1068);
    v35 = v8->mMaterialUser.mOffset;
    if ( v35 )
      v36 = (_WORD *)((char *)&v8->mMaterialUser + v35);
    else
      v36 = 0i64;
    *v36 |= 0x20u;
  }
  this->mLightMaterial = v8;
  v37 = UFG::qStringHashUpper32("IrradianceVolume", 0xFFFFFFFF);
  v38 = Illusion::Factory::NewMaterial("IrradianceVolume", v37, 9u, 0i64, 0i64, 0i64);
  v39 = UFG::qStringHash32("DRIRRADIANCEVOLUME", 0xFFFFFFFF);
  LOWORD(v38[1].mNode.mChild[0]) = 0;
  HIDWORD(v38[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v40 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v38[1].mTypeUID = -1957338719;
  LODWORD(v38[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v39;
  LODWORD(v38[1].mNode.mParent) = v40;
  v41 = v3->mNode.mUID;
  *(_WORD *)&v38[1].mDebugName[12] = 0;
  *(_DWORD *)&v38[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v42 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v38[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v38[1].mStateBlockMask.mFlags[0]) = v41;
  *(_DWORD *)&v38[1].mDebugName[4] = v42;
  v43 = v4->mNode.mUID;
  LOWORD(v38[1].mMaterialUser.mOffset) = 0;
  *(&v38[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v44 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v38[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v38[2].mNode.mUID = v43;
  v38[1].mNumParams = v44;
  v45 = mDepthTextureCopy->mNode.mUID;
  LOWORD(v38[2].mTypeUID) = 0;
  HIDWORD(v38[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v46 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v38[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v38[2].mDebugName[28] = v45;
  LODWORD(v38[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v46;
  LOWORD(v38[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v38[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v47 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v38[3].mNode.mChild[1]) = 315097330;
  LODWORD(v38[3].mNode.mChild[0]) = 662883558;
  LODWORD(v38[2].mStateBlockMask.mFlags[0]) = v47;
  LOWORD(v38[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v38[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v48 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v38[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v38[3].mDebugName[12] = -262489691;
  v38[3].mNode.mUID = v48;
  *((_WORD *)&v38[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v38[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v49 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v38[4].mNode.mParent) = -1958479169;
  LODWORD(v38[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v38[3].mDebugName[28] = v49;
  LOWORD(v38[4].mNode.mChild[1]) = 0;
  HIDWORD(v38[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v50 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v38[4].mDebugName[4] = -1958479169;
  v38[4].mTypeUID = 0;
  LODWORD(v38[4].mNode.mChild[0]) = v50;
  *(_WORD *)&v38[4].mDebugName[20] = 0;
  *(_DWORD *)&v38[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v51 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v38[4].mNumParams = -1958479169;
  LODWORD(v38[4].mStateBlockMask.mFlags[1]) = 0;
  *(_DWORD *)&v38[4].mDebugName[12] = v51;
  v52 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v52, v38);
  this->mIrradianceVolumeMaterial = v38;
  v53 = UFG::qStringHashUpper32("IrradianceSkyVolume", 0xFFFFFFFF);
  v54 = Illusion::Factory::NewMaterial("IrradianceSkyVolume", v53, 9u, 0i64, 0i64, 0i64);
  v55 = UFG::qStringHash32("DRIRRADIANCESKYVOLUME", 0xFFFFFFFF);
  LOWORD(v54[1].mNode.mChild[0]) = 0;
  HIDWORD(v54[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v56 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v54[1].mTypeUID = -1957338719;
  LODWORD(v54[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v55;
  LODWORD(v54[1].mNode.mParent) = v56;
  v57 = v3->mNode.mUID;
  *(_WORD *)&v54[1].mDebugName[12] = 0;
  *(_DWORD *)&v54[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v58 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v54[1].mStateBlockMask.mFlags[1]) = -1958479169;
  *(_DWORD *)&v54[1].mDebugName[4] = v58;
  LODWORD(v54[1].mStateBlockMask.mFlags[0]) = v57;
  v59 = v4->mNode.mUID;
  LOWORD(v54[1].mMaterialUser.mOffset) = 0;
  *(&v54[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v60 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v54[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v54[2].mNode.mUID = v59;
  v54[1].mNumParams = v60;
  v61 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v54[2].mTypeUID) = 0;
  HIDWORD(v54[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v62 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v54[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v54[2].mDebugName[28] = v61;
  LODWORD(v54[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v62;
  LOWORD(v54[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v54[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v63 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v54[3].mNode.mChild[1]) = 315097330;
  LODWORD(v54[3].mNode.mChild[0]) = 1478433551;
  LODWORD(v54[2].mStateBlockMask.mFlags[0]) = v63;
  LOWORD(v54[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v54[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v64 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v54[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v54[3].mDebugName[12] = -262489691;
  v54[3].mNode.mUID = v64;
  *((_WORD *)&v54[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v54[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v65 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v54[4].mNode.mParent) = -1958479169;
  LODWORD(v54[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v54[3].mDebugName[28] = v65;
  LOWORD(v54[4].mNode.mChild[1]) = 0;
  HIDWORD(v54[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v66 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v54[4].mDebugName[4] = -1958479169;
  v54[4].mTypeUID = 0;
  LODWORD(v54[4].mNode.mChild[0]) = v66;
  *(_WORD *)&v54[4].mDebugName[20] = 0;
  *(_DWORD *)&v54[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v67 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v54[4].mNumParams = -1958479169;
  *(_DWORD *)&v54[4].mDebugName[12] = v67;
  LODWORD(v54[4].mStateBlockMask.mFlags[1]) = 0;
  v68 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v68, v54);
  this->mIrradianceVolumeSkyMaterial = v54;
  v69 = UFG::qStringHashUpper32("IrradianceSkyVolume", 0xFFFFFFFF);
  v70 = Illusion::Factory::NewMaterial("IrradianceSkyVolume", v69, 9u, 0i64, 0i64, 0i64);
  v71 = UFG::qStringHash32("DRIRRADIANCESKYVOLUME", 0xFFFFFFFF);
  LOWORD(v70[1].mNode.mChild[0]) = 0;
  HIDWORD(v70[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v72 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v70[1].mTypeUID = -1957338719;
  LODWORD(v70[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v71;
  LODWORD(v70[1].mNode.mParent) = v72;
  v73 = v3->mNode.mUID;
  *(_WORD *)&v70[1].mDebugName[12] = 0;
  *(_DWORD *)&v70[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v74 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v70[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v70[1].mStateBlockMask.mFlags[0]) = v73;
  *(_DWORD *)&v70[1].mDebugName[4] = v74;
  v75 = v4->mNode.mUID;
  LOWORD(v70[1].mMaterialUser.mOffset) = 0;
  *(&v70[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v76 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v70[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v70[2].mNode.mUID = v75;
  v70[1].mNumParams = v76;
  v77 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v70[2].mTypeUID) = 0;
  HIDWORD(v70[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v78 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v70[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v70[2].mDebugName[28] = v77;
  LODWORD(v70[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v78;
  LOWORD(v70[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v70[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v79 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v70[3].mNode.mChild[1]) = 315097330;
  LODWORD(v70[3].mNode.mChild[0]) = 662883558;
  LODWORD(v70[2].mStateBlockMask.mFlags[0]) = v79;
  LOWORD(v70[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v70[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v80 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v70[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v70[3].mDebugName[12] = -262489691;
  v70[3].mNode.mUID = v80;
  *((_WORD *)&v70[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v70[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v81 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v70[4].mNode.mParent) = -1958479169;
  LODWORD(v70[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v70[3].mDebugName[28] = v81;
  LOWORD(v70[4].mNode.mChild[1]) = 0;
  HIDWORD(v70[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v82 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v70[4].mDebugName[4] = -1958479169;
  v70[4].mTypeUID = 0;
  LODWORD(v70[4].mNode.mChild[0]) = v82;
  *(_WORD *)&v70[4].mDebugName[20] = 0;
  *(_DWORD *)&v70[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v83 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v70[4].mNumParams = -1958479169;
  *(_DWORD *)&v70[4].mDebugName[12] = v83;
  LODWORD(v70[4].mStateBlockMask.mFlags[1]) = 0;
  v84 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v84, v70);
  this->mIrradianceVolumeSkyMaterial2 = v70;
  v85 = UFG::qStringHashUpper32("IrradianceSkyBlackVolume", 0xFFFFFFFF);
  v86 = Illusion::Factory::NewMaterial("IrradianceSkyBlackVolume", v85, 9u, 0i64, 0i64, 0i64);
  v87 = UFG::qStringHash32("DRIRRADIANCESKYBLACKVOLUME", 0xFFFFFFFF);
  LOWORD(v86[1].mNode.mChild[0]) = 0;
  HIDWORD(v86[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v88 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v86[1].mTypeUID = -1957338719;
  LODWORD(v86[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v87;
  LODWORD(v86[1].mNode.mParent) = v88;
  v89 = v3->mNode.mUID;
  *(_WORD *)&v86[1].mDebugName[12] = 0;
  *(_DWORD *)&v86[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v90 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v86[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v86[1].mStateBlockMask.mFlags[0]) = v89;
  *(_DWORD *)&v86[1].mDebugName[4] = v90;
  v91 = v4->mNode.mUID;
  LOWORD(v86[1].mMaterialUser.mOffset) = 0;
  *(&v86[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v92 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v86[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v86[2].mNode.mUID = v91;
  v86[1].mNumParams = v92;
  v93 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v86[2].mTypeUID) = 0;
  HIDWORD(v86[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v94 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v86[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v86[2].mDebugName[28] = v93;
  LODWORD(v86[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v94;
  LOWORD(v86[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v86[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v95 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v86[3].mNode.mChild[1]) = 315097330;
  LODWORD(v86[3].mNode.mChild[0]) = 1478433551;
  LODWORD(v86[2].mStateBlockMask.mFlags[0]) = v95;
  LOWORD(v86[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v86[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v96 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v86[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v86[3].mDebugName[12] = -262489691;
  v86[3].mNode.mUID = v96;
  *((_WORD *)&v86[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v86[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v97 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v86[4].mNode.mParent) = -1958479169;
  LODWORD(v86[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v86[3].mDebugName[28] = v97;
  LOWORD(v86[4].mNode.mChild[1]) = 0;
  HIDWORD(v86[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v98 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v86[4].mDebugName[4] = -1958479169;
  v86[4].mTypeUID = 0;
  LODWORD(v86[4].mNode.mChild[0]) = v98;
  *(_WORD *)&v86[4].mDebugName[20] = 0;
  *(_DWORD *)&v86[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v99 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v86[4].mNumParams = -1958479169;
  LODWORD(v86[4].mStateBlockMask.mFlags[1]) = 0;
  *(_DWORD *)&v86[4].mDebugName[12] = v99;
  v100 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v100, v86);
  this->mIrradianceVolumeSkyBlackMaterial = v86;
  v101 = UFG::qStringHashUpper32("ShadowCollector", 0xFFFFFFFF);
  v102 = Illusion::Factory::NewMaterial("ShadowCollector", v101, 9u, 0i64, 0i64, 0i64);
  v103 = UFG::qStringHash32("DRSHADOWCOLLECTOR", 0xFFFFFFFF);
  LOWORD(v102[1].mNode.mChild[0]) = 0;
  HIDWORD(v102[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v104 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v102[1].mTypeUID = -1957338719;
  LODWORD(v102[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v103;
  LODWORD(v102[1].mNode.mParent) = v104;
  v105 = mDepthTextureCopy->mNode.mUID;
  *(_WORD *)&v102[1].mDebugName[12] = 0;
  *(_DWORD *)&v102[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v106 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v102[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v102[1].mStateBlockMask.mFlags[0]) = v105;
  *(_DWORD *)&v102[1].mDebugName[4] = v106;
  LOWORD(v102[1].mMaterialUser.mOffset) = 0;
  *(&v102[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v107 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v102[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v102[2].mNode.mUID = 662883558;
  v102[1].mNumParams = v107;
  LOWORD(v102[2].mTypeUID) = 0;
  HIDWORD(v102[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v108 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v102[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v102[2].mDebugName[28] = 1660426324;
  LODWORD(v102[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v108;
  v109 = this->mHalfSizeScratchTargetC->mTargetTexture[0]->mNode.mUID;
  LOWORD(v102[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v102[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v102[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v102[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v102[3].mNode.mChild[0]) = v109;
  v110 = this->mCascadeShadowTexture->mNode.mUID;
  LOWORD(v102[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v102[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v111 = UFG::qStringHash32("texShadowAtlas", 0xFFFFFFFF);
  *(_DWORD *)&v102[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v102[3].mDebugName[12] = v110;
  v102[3].mNode.mUID = v111;
  v112 = UFG::qStringHashUpper32("FX_NOISESINCOS", 0xFFFFFFFF);
  *((_WORD *)&v102[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v102[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v113 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v102[4].mNode.mParent) = -1958479169;
  LODWORD(v102[3].mMaterialUser.mOffset) = v112;
  *(_DWORD *)&v102[3].mDebugName[28] = v113;
  v114 = this->mCascadeShadowTextureAliasDepth->mNode.mUID;
  LOWORD(v102[4].mNode.mChild[1]) = 0;
  HIDWORD(v102[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v115 = UFG::qStringHash32("texShadowRaw", 0xFFFFFFFF);
  *(_DWORD *)&v102[4].mDebugName[4] = -1958479169;
  v102[4].mTypeUID = v114;
  LODWORD(v102[4].mNode.mChild[0]) = v115;
  v116 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v102[4].mDebugName[20] = 0;
  *(_DWORD *)&v102[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v117 = UFG::qStringHash32("texDepth2", 0xFFFFFFFF);
  v102[4].mNumParams = -1958479169;
  *(_DWORD *)&v102[4].mDebugName[12] = v117;
  LODWORD(v102[4].mStateBlockMask.mFlags[1]) = v116;
  v118 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v118, v102);
  this->mShadowCollectorMaterial = v102;
  v119 = UFG::qStringHashUpper32("RasterState.SunMark", 0xFFFFFFFF);
  v120 = Illusion::Factory::NewRasterState("RasterState.SunMark", v119, 0i64, 0i64, 0i64);
  LODWORD(v120[1].mNode.mParent) = 33619969;
  *(_DWORD *)((char *)&v120[1].mNode.mParent + 6) = -16711423;
  *(_DWORD *)((char *)v120[1].mNode.mChild + 5) = 133119;
  BYTE4(v120[1].mNode.mChild[0]) = -1;
  BYTE1(v120[1].mNode.mChild[1]) = 0;
  v121 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v121, v120);
  v122 = UFG::qStringHashUpper32("StencilMaterialSunMark", 0xFFFFFFFF);
  v123 = Illusion::Factory::NewMaterial("StencilMaterialSunMark", v122, 3u, 0i64, 0i64, 0i64);
  LODWORD(v120) = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v123[1].mNode.mChild[0]) = 0;
  HIDWORD(v123[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v124 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v123[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v120;
  v123[1].mTypeUID = -1957338719;
  LODWORD(v123[1].mNode.mParent) = v124;
  *(_WORD *)&v123[1].mDebugName[12] = 0;
  *(_DWORD *)&v123[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v125 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v123[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v123[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v123[1].mDebugName[4] = v125;
  LOWORD(v123[1].mMaterialUser.mOffset) = 0;
  *(&v123[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v126 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v123[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v123[1].mNumParams = v126;
  v123[2].mNode.mUID = v119;
  v127 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v127, v123);
  this->mSunAfterAmbientSpecMarkMaterial = v123;
  LODWORD(v123) = UFG::qStringHashUpper32("RasterState.SunTest", 0xFFFFFFFF);
  v128 = Illusion::Factory::NewRasterState("RasterState.SunTest", (unsigned int)v123, 0i64, 0i64, 0i64);
  LODWORD(v128[1].mNode.mParent) = 17235968;
  BYTE6(v128[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v128[1].mNode.mChild + 5) = 767;
  BYTE4(v128[1].mNode.mChild[0]) = -1;
  BYTE1(v128[1].mNode.mChild[1]) = 0;
  v129 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v129, v128);
  this->mSunAfterAmbientSpecTestRasterStateUID = (unsigned int)v123;
  LODWORD(v123) = UFG::qStringHashUpper32("RasterState.SunTest.NoClear", 0xFFFFFFFF);
  v130 = Illusion::Factory::NewRasterState("RasterState.SunTest.NoClear", (unsigned int)v123, 0i64, 0i64, 0i64);
  LODWORD(v130[1].mNode.mParent) = 17235968;
  HIWORD(v130[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v130[1].mNode.mChild + 5) = 66303;
  BYTE4(v130[1].mNode.mChild[0]) = -1;
  *(_WORD *)((char *)v130[1].mNode.mChild + 1) = 511;
  LOBYTE(v130[1].mNode.mChild[0]) = 1;
  BYTE1(v130[1].mNode.mChild[1]) = 0;
  v131 = v130;
  v132 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v132, v131);
  this->mSunAfterAmbientSpecTestNoClearRasterStateUID = (unsigned int)v123;
  v133 = UFG::qStringHashUpper32("SunUsingCollectorMat", 0xFFFFFFFF);
  v134 = Illusion::Factory::NewMaterial("SunUsingCollectorMat", v133, 7u, 0i64, 0i64, 0i64);
  LODWORD(v131) = UFG::qStringHash32("DRSUNLIGHTUSINGCOLLECTOR", 0xFFFFFFFF);
  LOWORD(v134[1].mNode.mChild[0]) = 0;
  HIDWORD(v134[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v135 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v134[1].mTypeUID = -1957338719;
  LODWORD(v134[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v131;
  LODWORD(v134[1].mNode.mParent) = v135;
  LODWORD(v131) = v3->mNode.mUID;
  *(_WORD *)&v134[1].mDebugName[12] = 0;
  *(_DWORD *)&v134[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v136 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v134[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v134[1].mStateBlockMask.mFlags[0]) = (_DWORD)v131;
  *(_DWORD *)&v134[1].mDebugName[4] = v136;
  LODWORD(v131) = v4->mNode.mUID;
  LOWORD(v134[1].mMaterialUser.mOffset) = 0;
  *(&v134[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v137 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v134[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v134[2].mNode.mUID = (unsigned int)v131;
  v134[1].mNumParams = v137;
  LODWORD(v131) = mDepthTextureCopy->mNode.mUID;
  LOWORD(v134[2].mTypeUID) = 0;
  HIDWORD(v134[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v134[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v134[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v134[2].mDebugName[28] = (_DWORD)v131;
  LOWORD(v134[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v134[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v138 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v134[3].mNode.mChild[1]) = 315097330;
  LODWORD(v134[3].mNode.mChild[0]) = -1032465351;
  LODWORD(v134[2].mStateBlockMask.mFlags[0]) = v138;
  LOWORD(v134[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v134[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v139 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v134[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v134[3].mDebugName[12] = 1660426324;
  v134[3].mNode.mUID = v139;
  LODWORD(v131) = this->mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  *((_WORD *)&v134[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v134[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v140 = UFG::qStringHash32("texCollector", 0xFFFFFFFF);
  LODWORD(v134[4].mNode.mParent) = -1958479169;
  *(_DWORD *)&v134[3].mDebugName[28] = v140;
  LODWORD(v134[3].mMaterialUser.mOffset) = (_DWORD)v131;
  v141 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v141, v134);
  this->mSunUsingCollectorMaterial = v134;
  this->mAmbientSpecShaderUID = UFG::qStringHash32("DRSKYAMBIENTSPEC", 0xFFFFFFFF);
  this->mAmbientSpecWithSunShaderUID = UFG::qStringHash32("DRSKYAMBIENTSPECWITHSUN", 0xFFFFFFFF);
  this->mAmbientSpecWithSunShader_DOUID = UFG::qStringHash32("DRSKYAMBIENTSPECWITHSUN_DO", 0xFFFFFFFF);
  v142 = UFG::qStringHashUpper32("SkyLightAmbientMaterial", 0xFFFFFFFF);
  v143 = Illusion::Factory::NewMaterial("SkyLightAmbientMaterial", v142, 8u, 0i64, 0i64, 0i64);
  LODWORD(v131) = this->mAmbientSpecShaderUID;
  v144 = v143;
  LOWORD(v143[1].mNode.mChild[0]) = 0;
  HIDWORD(v143[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v145 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v144[1].mTypeUID = -1957338719;
  LODWORD(v144[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v131;
  LODWORD(v144[1].mNode.mParent) = v145;
  LODWORD(v131) = v3->mNode.mUID;
  *(_WORD *)&v144[1].mDebugName[12] = 0;
  *(_DWORD *)&v144[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v146 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v144[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v144[1].mStateBlockMask.mFlags[0]) = (_DWORD)v131;
  *(_DWORD *)&v144[1].mDebugName[4] = v146;
  LODWORD(v131) = v4->mNode.mUID;
  LOWORD(v144[1].mMaterialUser.mOffset) = 0;
  *(&v144[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v147 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v144[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v144[2].mNode.mUID = (unsigned int)v131;
  v144[1].mNumParams = v147;
  LODWORD(v131) = mDepthTextureCopy->mNode.mUID;
  LOWORD(v144[2].mTypeUID) = 0;
  HIDWORD(v144[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v148 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v144[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v144[2].mDebugName[28] = (_DWORD)v131;
  LODWORD(v144[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v148;
  LOWORD(v144[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v144[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v149 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v144[3].mNode.mChild[1]) = 315097330;
  LODWORD(v144[3].mNode.mChild[0]) = -1032465351;
  LODWORD(v144[2].mStateBlockMask.mFlags[0]) = v149;
  LOWORD(v144[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v144[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v150 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v144[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v144[3].mDebugName[12] = -1835606658;
  v144[3].mNode.mUID = v150;
  LODWORD(v131) = this->mSkyOcclusionAliasTarget->mTargetTexture[0]->mNode.mUID;
  *((_WORD *)&v144[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v144[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v151 = UFG::qStringHash32("texAmbient2", 0xFFFFFFFF);
  LODWORD(v144[4].mNode.mParent) = -1958479169;
  LODWORD(v144[3].mMaterialUser.mOffset) = (_DWORD)v131;
  *(_DWORD *)&v144[3].mDebugName[28] = v151;
  LODWORD(v131) = this->mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  LOWORD(v144[4].mNode.mChild[1]) = 0;
  HIDWORD(v144[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v144[4].mNode.mChild[0]) = UFG::qStringHash32("texCollector", 0xFFFFFFFF);
  *(_DWORD *)&v144[4].mDebugName[4] = -1958479169;
  v144[4].mTypeUID = (unsigned int)v131;
  v152 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v152, v144);
  this->mSkyAmbientMaterial = v144;
  v153 = UFG::qStringHashUpper32("BlobMat", 0xFFFFFFFF);
  v154 = Illusion::Factory::NewMaterial("BlobMat", v153, 6u, 0i64, 0i64, 0i64);
  LODWORD(v131) = UFG::qStringHash32("DRBLOBSHADOW", 0xFFFFFFFF);
  LOWORD(v154[1].mNode.mChild[0]) = 0;
  HIDWORD(v154[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v155 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v154[1].mTypeUID = -1957338719;
  LODWORD(v154[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v131;
  LODWORD(v154[1].mNode.mParent) = v155;
  LODWORD(v131) = v4->mNode.mUID;
  *(_WORD *)&v154[1].mDebugName[12] = 0;
  *(_DWORD *)&v154[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v156 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v154[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v154[1].mStateBlockMask.mFlags[0]) = (_DWORD)v131;
  *(_DWORD *)&v154[1].mDebugName[4] = v156;
  LODWORD(v131) = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v154[1].mMaterialUser.mOffset) = 0;
  *(&v154[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v157 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v154[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v154[2].mNode.mUID = (unsigned int)v131;
  v154[1].mNumParams = v157;
  LOWORD(v154[2].mTypeUID) = 0;
  HIDWORD(v154[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v158 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v154[2].UFG::qResourceData + 22) = 315097330;
  *(_DWORD *)&v154[2].mDebugName[28] = 1478433551;
  LODWORD(v154[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v158;
  LOWORD(v154[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v154[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v159 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v154[3].mNode.mChild[1]) = 1002903008;
  LODWORD(v154[2].mStateBlockMask.mFlags[0]) = v159;
  LODWORD(v154[3].mNode.mChild[0]) = 1660426324;
  LOWORD(v154[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v154[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v160 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *(_DWORD *)&v154[3].mDebugName[20] = -1958479169;
  v154[3].mNode.mUID = v160;
  *(_DWORD *)&v154[3].mDebugName[12] = 0;
  v161 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v161, v154);
  if ( *(_DWORD *)&v154[2].mDebugName[28] != 1478433551 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v154[2].mDebugName[4],
      *((_DWORD *)&v154[2].UFG::qResourceData + 22),
      0x581F1B0Fu);
    v162 = v154->mMaterialUser.mOffset;
    if ( v162 )
      v163 = (_WORD *)((char *)&v154->mMaterialUser + v162);
    else
      v163 = 0i64;
    *v163 |= 0x20u;
  }
  if ( LODWORD(v154[3].mNode.mChild[0]) != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v154[2].mNumParams,
      (unsigned int)v154[3].mNode.mChild[1],
      0x62F81854u);
    v164 = v154->mMaterialUser.mOffset;
    if ( v164 )
      v165 = (_WORD *)((char *)&v154->mMaterialUser + v164);
    else
      v165 = 0i64;
    *v165 |= 0x20u;
  }
  this->mBlobMaterial = v154;
  v166 = UFG::qStringHashUpper32("CompositeLightsAndEffects", 0xFFFFFFFF);
  v167 = Illusion::Factory::NewMaterial("CompositeLightsAndEffects", v166, 0xBu, 0i64, 0i64, 0i64);
  LOWORD(v167[1].mNode.mChild[0]) = 0;
  v168 = v167;
  HIDWORD(v167[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v169 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v168[1].mTypeUID = -1957338719;
  LODWORD(v168[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 443851384;
  LODWORD(v168[1].mNode.mParent) = v169;
  v170 = v3->mNode.mUID;
  *(_WORD *)&v168[1].mDebugName[12] = 0;
  *(_DWORD *)&v168[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v171 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v168[1].mStateBlockMask.mFlags[1]) = -1958479169;
  *(_DWORD *)&v168[1].mDebugName[4] = v171;
  LODWORD(v168[1].mStateBlockMask.mFlags[0]) = v170;
  v172 = v353->mNode.mUID;
  LOWORD(v168[1].mMaterialUser.mOffset) = 0;
  *(&v168[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v173 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v168[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v168[2].mNode.mUID = v172;
  v168[1].mNumParams = v173;
  v174 = v5->mNode.mUID;
  LOWORD(v168[2].mTypeUID) = 0;
  HIDWORD(v168[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v175 = UFG::qStringHash32("texAmbient", 0xFFFFFFFF);
  *((_DWORD *)&v168[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v168[2].mDebugName[28] = v174;
  LODWORD(v168[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v175;
  LOWORD(v168[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v168[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v176 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v168[3].mNode.mChild[1]) = 315097330;
  LODWORD(v168[3].mNode.mChild[0]) = 662883558;
  LODWORD(v168[2].mStateBlockMask.mFlags[0]) = v176;
  LOWORD(v168[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v168[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v177 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v168[3].mDebugName[20] = 1002903008;
  v168[3].mNode.mUID = v177;
  *(_DWORD *)&v168[3].mDebugName[12] = 785612091;
  v178 = v4->mNode.mUID;
  *((_WORD *)&v168[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v168[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v179 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v168[4].mNode.mParent) = -1958479169;
  LODWORD(v168[3].mMaterialUser.mOffset) = v178;
  *(_DWORD *)&v168[3].mDebugName[28] = v179;
  v180 = mDepthTextureCopy->mNode.mUID;
  LOWORD(v168[4].mNode.mChild[1]) = 0;
  HIDWORD(v168[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v181 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *(_DWORD *)&v168[4].mDebugName[4] = -1958479169;
  v168[4].mTypeUID = v180;
  LODWORD(v168[4].mNode.mChild[0]) = v181;
  v182 = this->mSkyOcclusionAliasTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v168[4].mDebugName[20] = 0;
  *(_DWORD *)&v168[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v183 = UFG::qStringHash32("texAmbient2", 0xFFFFFFFF);
  v168[4].mNumParams = -1958479169;
  LODWORD(v168[4].mStateBlockMask.mFlags[1]) = v182;
  *(_DWORD *)&v168[4].mDebugName[12] = v183;
  v184 = this->mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  LOWORD(v168[5].mNode.mParent) = 0;
  HIDWORD(v168[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v185 = UFG::qStringHash32("texCollector", 0xFFFFFFFF);
  LODWORD(v168[5].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1958479169;
  LODWORD(v168[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) = v184;
  LODWORD(v168[4].mMaterialUser.mOffset) = v185;
  v186 = UFG::qStringHash32("ATAN2", 0xFFFFFFFF);
  *(_WORD *)&v168[5].mDebugName[4] = 0;
  v187 = v186;
  *(_DWORD *)v168[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v188 = UFG::qStringHash32("texArcTan", 0xFFFFFFFF);
  LODWORD(v168[5].mStateBlockMask.mFlags[0]) = -1958479169;
  v168[5].mTypeUID = v188;
  *((_DWORD *)&v168[5].UFG::qResourceData + 22) = v187;
  v189 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v189, v168);
  this->mCompositeLightingMaterial = v168;
  v190 = UFG::qStringHashUpper32("CompositeFinalMaterial", 0xFFFFFFFF);
  v191 = Illusion::Factory::NewMaterial("CompositeFinalMaterial", v190, 6u, 0i64, 0i64, 0i64);
  LOWORD(v191[1].mNode.mChild[0]) = 0;
  v192 = v191;
  HIDWORD(v191[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v193 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v192[1].mTypeUID = -1957338719;
  LODWORD(v192[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1067196633;
  LODWORD(v192[1].mNode.mParent) = v193;
  *(_WORD *)&v192[1].mDebugName[12] = 0;
  *(_DWORD *)&v192[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v194 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v192[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v192[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v192[1].mDebugName[4] = v194;
  v195 = this->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v192[1].mMaterialUser.mOffset) = 0;
  *(&v192[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v196 = UFG::qStringHash32("texHDRBloom", 0xFFFFFFFF);
  LODWORD(v192[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v192[2].mNode.mUID = v195;
  v192[1].mNumParams = v196;
  LOWORD(v192[2].mTypeUID) = 0;
  HIDWORD(v192[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v197 = UFG::qStringHash32("texColourCube", 0xFFFFFFFF);
  *((_DWORD *)&v192[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v192[2].mDebugName[28] = 0;
  LODWORD(v192[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v197;
  LOWORD(v192[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v192[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v198 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v192[3].mNode.mChild[1]) = 315097330;
  LODWORD(v192[3].mNode.mChild[0]) = 662883558;
  LODWORD(v192[2].mStateBlockMask.mFlags[0]) = v198;
  LOWORD(v192[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v192[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v199 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v192[3].mDebugName[20] = 1002903008;
  v192[3].mNode.mUID = v199;
  *(_DWORD *)&v192[3].mDebugName[12] = 1660426324;
  v200 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v200, v192);
  this->mCompositeFinalMaterial = v192;
  v201 = UFG::qStringHashUpper32("CameraBlur", 0xFFFFFFFF);
  v202 = Illusion::Factory::NewMaterial("CameraBlur", v201, 6u, 0i64, 0i64, 0i64);
  v203 = UFG::qStringHashUpper32("HK_CAMERABLUR", 0xFFFFFFFF);
  LOWORD(v202[1].mNode.mChild[0]) = 0;
  v204 = v203;
  HIDWORD(v202[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v205 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v202[1].mTypeUID = -1957338719;
  LODWORD(v202[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v204;
  LODWORD(v202[1].mNode.mParent) = v205;
  *(_WORD *)&v202[1].mDebugName[12] = 0;
  *(_DWORD *)&v202[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v206 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v202[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v202[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v202[1].mDebugName[4] = v206;
  v207 = v5->mNode.mUID;
  LOWORD(v202[1].mMaterialUser.mOffset) = 0;
  *(&v202[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v208 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v202[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v202[2].mNode.mUID = v207;
  v202[1].mNumParams = v208;
  v209 = mDepthTextureCopy->mNode.mUID;
  LOWORD(v202[2].mTypeUID) = 0;
  HIDWORD(v202[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v210 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v202[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v202[2].mDebugName[28] = v209;
  LODWORD(v202[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v210;
  LOWORD(v202[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v202[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v211 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v202[3].mNode.mChild[1]) = 315097330;
  LODWORD(v202[3].mNode.mChild[0]) = 662883558;
  LODWORD(v202[2].mStateBlockMask.mFlags[0]) = v211;
  LOWORD(v202[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v202[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v212 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v202[3].mDebugName[20] = 1002903008;
  v202[3].mNode.mUID = v212;
  *(_DWORD *)&v202[3].mDebugName[12] = 1660426324;
  v213 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v213, v202);
  this->mCameraBlurMaterial = v202;
  v214 = UFG::qStringHashUpper32("DownsampleDepth", 0xFFFFFFFF);
  v215 = Illusion::Factory::NewMaterial("DownsampleDepth", v214, 4u, 0i64, 0i64, 0i64);
  v216 = UFG::qStringHash32("DR_BLITDEPTHDOWNSAMPLE", 0xFFFFFFFF);
  LOWORD(v215[1].mNode.mChild[0]) = 0;
  HIDWORD(v215[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v217 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v215[1].mTypeUID = -1957338719;
  LODWORD(v215[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v216;
  LODWORD(v215[1].mNode.mParent) = v217;
  v218 = mDepthTextureCopy->mNode.mUID;
  *(_WORD *)&v215[1].mDebugName[12] = 0;
  *(_DWORD *)&v215[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v219 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v215[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v215[1].mStateBlockMask.mFlags[0]) = v218;
  *(_DWORD *)&v215[1].mDebugName[4] = v219;
  LOWORD(v215[1].mMaterialUser.mOffset) = 0;
  *(&v215[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v220 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v215[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v215[2].mNode.mUID = 662883558;
  v215[1].mNumParams = v220;
  LOWORD(v215[2].mTypeUID) = 0;
  HIDWORD(v215[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v221 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v215[2].UFG::qResourceData + 22) = 1002903008;
  LODWORD(v215[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v221;
  *(_DWORD *)&v215[2].mDebugName[28] = 304454940;
  v222 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v222, v215);
  if ( v215[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v215[2],
      (unsigned int)v215[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v223 = v215->mMaterialUser.mOffset;
    if ( v223 )
      v224 = (_WORD *)((char *)&v215->mMaterialUser + v223);
    else
      v224 = 0i64;
    *v224 |= 0x20u;
  }
  if ( *(_DWORD *)&v215[2].mDebugName[28] != 304454940 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v215[2].mDebugName[4],
      *((_DWORD *)&v215[2].UFG::qResourceData + 22),
      0x12259D1Cu);
    v225 = v215->mMaterialUser.mOffset;
    if ( v225 )
      v226 = (_WORD *)((char *)&v215->mMaterialUser + v225);
    else
      v226 = 0i64;
    *v226 |= 0x20u;
  }
  this->mDownsampleDepthMaterial = v215;
  v227 = UFG::qStringHashUpper32("DR_SSAO", 0xFFFFFFFF);
  v228 = Illusion::Factory::NewMaterial("DR_SSAO", v227, 5u, 0i64, 0i64, 0i64);
  v229 = UFG::qStringHashUpper32("HK_AO", 0xFFFFFFFF);
  LOWORD(v228[1].mNode.mChild[0]) = 0;
  HIDWORD(v228[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v230 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v228[1].mTypeUID = -1957338719;
  LODWORD(v228[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v229;
  LODWORD(v228[1].mNode.mParent) = v230;
  *(_WORD *)&v228[1].mDebugName[12] = 0;
  *(_DWORD *)&v228[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v231 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v228[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v228[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v228[1].mDebugName[4] = v231;
  LOWORD(v228[1].mMaterialUser.mOffset) = 0;
  *(&v228[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v232 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v228[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v228[2].mNode.mUID = 1660426324;
  v228[1].mNumParams = v232;
  v233 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v228[2].mTypeUID) = 0;
  HIDWORD(v228[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v234 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  *((_DWORD *)&v228[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v228[2].mDebugName[28] = v233;
  LODWORD(v228[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v234;
  v235 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v228[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v228[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v236 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v228[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v228[2].mStateBlockMask.mFlags[0]) = v236;
  LODWORD(v228[3].mNode.mChild[0]) = v235;
  v237 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v237, v228);
  this->mSSAOMaterial = v228;
  v238 = UFG::qStringHashUpper32("DR_SSAONIS", 0xFFFFFFFF);
  v239 = Illusion::Factory::NewMaterial("DR_SSAONIS", v238, 5u, 0i64, 0i64, 0i64);
  v240 = UFG::qStringHashUpper32("HK_AO_NIS", 0xFFFFFFFF);
  LOWORD(v239[1].mNode.mChild[0]) = 0;
  HIDWORD(v239[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v241 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v239[1].mTypeUID = -1957338719;
  LODWORD(v239[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v240;
  LODWORD(v239[1].mNode.mParent) = v241;
  *(_WORD *)&v239[1].mDebugName[12] = 0;
  *(_DWORD *)&v239[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v242 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v239[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v239[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v239[1].mDebugName[4] = v242;
  LOWORD(v239[1].mMaterialUser.mOffset) = 0;
  *(&v239[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v243 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v239[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v239[2].mNode.mUID = 1660426324;
  v239[1].mNumParams = v243;
  v244 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v239[2].mTypeUID) = 0;
  HIDWORD(v239[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v245 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  *((_DWORD *)&v239[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v239[2].mDebugName[28] = v244;
  LODWORD(v239[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v245;
  v246 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v239[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v239[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v247 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v239[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v239[2].mStateBlockMask.mFlags[0]) = v247;
  LODWORD(v239[3].mNode.mChild[0]) = v246;
  v248 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v248, v239);
  this->mSSAONISMaterial = v239;
  v249 = UFG::qStringHashUpper32("DR_SSAOHIGH", 0xFFFFFFFF);
  v250 = Illusion::Factory::NewMaterial("DR_SSAOHIGH", v249, 5u, 0i64, 0i64, 0i64);
  v251 = UFG::qStringHashUpper32("HK_AO_HIGH", 0xFFFFFFFF);
  LOWORD(v250[1].mNode.mChild[0]) = 0;
  HIDWORD(v250[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v252 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v250[1].mTypeUID = -1957338719;
  LODWORD(v250[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v251;
  LODWORD(v250[1].mNode.mParent) = v252;
  *(_WORD *)&v250[1].mDebugName[12] = 0;
  *(_DWORD *)&v250[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v253 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v250[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v250[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v250[1].mDebugName[4] = v253;
  LOWORD(v250[1].mMaterialUser.mOffset) = 0;
  *(&v250[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v254 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v250[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v250[2].mNode.mUID = 1660426324;
  v250[1].mNumParams = v254;
  v255 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v250[2].mTypeUID) = 0;
  HIDWORD(v250[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v256 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  *((_DWORD *)&v250[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v250[2].mDebugName[28] = v255;
  LODWORD(v250[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v256;
  v257 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v250[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v250[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v258 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v250[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v250[2].mStateBlockMask.mFlags[0]) = v258;
  LODWORD(v250[3].mNode.mChild[0]) = v257;
  v259 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v259, v250);
  this->mSSAOHighMaterial = v250;
  v260 = UFG::qStringHashUpper32("DR_SSDO", 0xFFFFFFFF);
  v261 = Illusion::Factory::NewMaterial("DR_SSDO", v260, 8u, 0i64, 0i64, 0i64);
  v262 = UFG::qStringHashUpper32("HK_DO", 0xFFFFFFFF);
  LOWORD(v261[1].mNode.mChild[0]) = 0;
  HIDWORD(v261[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v263 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v261[1].mTypeUID = -1957338719;
  LODWORD(v261[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v262;
  LODWORD(v261[1].mNode.mParent) = v263;
  *(_WORD *)&v261[1].mDebugName[12] = 0;
  *(_DWORD *)&v261[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v264 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v261[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v261[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v261[1].mDebugName[4] = v264;
  LOWORD(v261[1].mMaterialUser.mOffset) = 0;
  *(&v261[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v265 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v261[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v261[2].mNode.mUID = 1660426324;
  v261[1].mNumParams = v265;
  v266 = this->mLightBufferTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v261[2].mTypeUID) = 0;
  HIDWORD(v261[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v267 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v261[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v261[2].mDebugName[28] = v266;
  LODWORD(v261[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v267;
  v268 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v261[2].mStateBlockMask.mFlags[1]) = 0;
  v269 = v268;
  HIDWORD(v261[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v270 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v261[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v261[2].mStateBlockMask.mFlags[0]) = v270;
  LODWORD(v261[3].mNode.mChild[0]) = v269;
  v271 = this->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
  LOWORD(v261[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v261[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v272 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *(_DWORD *)&v261[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v261[3].mDebugName[12] = v271;
  v261[3].mNode.mUID = v272;
  *((_WORD *)&v261[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v261[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v273 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v261[4].mNode.mParent) = -1958479169;
  LODWORD(v261[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v261[3].mDebugName[28] = v273;
  v274 = this->mGBufferTarget->mTargetTexture[1]->mNode.mUID;
  LOWORD(v261[4].mNode.mChild[1]) = 0;
  HIDWORD(v261[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v275 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  *(_DWORD *)&v261[4].mDebugName[4] = -1958479169;
  LODWORD(v261[4].mNode.mChild[0]) = v275;
  v261[4].mTypeUID = v274;
  v276 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v276, v261);
  this->mSSDOMaterial = v261;
  v277 = UFG::qStringHashUpper32("SpotlightLightShaftMat", 0xFFFFFFFF);
  v278 = Illusion::Factory::NewMaterial("SpotlightLightShaftMat", v277, 8u, 0i64, 0i64, 0i64);
  v279 = UFG::qStringHash32("HK_LIGHTSHAFT_SPOTLIGHT", 0xFFFFFFFF);
  LOWORD(v278[1].mNode.mChild[0]) = 0;
  HIDWORD(v278[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v280 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v278[1].mTypeUID = -1957338719;
  LODWORD(v278[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v279;
  LODWORD(v278[1].mNode.mParent) = v280;
  v281 = this->mQuarterSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v278[1].mDebugName[12] = 0;
  *(_DWORD *)&v278[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v278[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v278[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v278[1].mStateBlockMask.mFlags[0]) = v281;
  LOWORD(v278[1].mMaterialUser.mOffset) = 0;
  *(&v278[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v282 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v278[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v278[2].mNode.mUID = -89056095;
  v278[1].mNumParams = v282;
  LOWORD(v278[2].mTypeUID) = 0;
  HIDWORD(v278[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v283 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v278[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v278[2].mDebugName[28] = -652645828;
  LODWORD(v278[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v283;
  v284 = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v278[2].mStateBlockMask.mFlags[1]) = 0;
  v285 = v284;
  HIDWORD(v278[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v286 = UFG::qStringHash32("texShadow", 0xFFFFFFFF);
  LODWORD(v278[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v278[3].mNode.mChild[0]) = v285;
  LODWORD(v278[2].mStateBlockMask.mFlags[0]) = v286;
  v287 = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v278[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  v288 = v287;
  *(&v278[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v289 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *(_DWORD *)&v278[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v278[3].mDebugName[12] = v288;
  v278[3].mNode.mUID = v289;
  v290 = UFG::qStringHashUpper32("FX_NOISESINCOS", 0xFFFFFFFF);
  *((_WORD *)&v278[3].UFG::qResourceData + 44) = 0;
  v291 = v290;
  *(_DWORD *)&v278[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v292 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v278[4].mNode.mParent) = -1958479169;
  LODWORD(v278[3].mMaterialUser.mOffset) = v291;
  *(_DWORD *)&v278[3].mDebugName[28] = v292;
  v293 = UFG::qStringHashUpper32("SKY_Noise_001", 0xFFFFFFFF);
  LOWORD(v278[4].mNode.mChild[1]) = 0;
  v294 = v293;
  HIDWORD(v278[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v295 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v278[4].mDebugName[4] = -1958479169;
  v278[4].mTypeUID = v294;
  LODWORD(v278[4].mNode.mChild[0]) = v295;
  v296 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v296, v278);
  this->mLightShaftSpotLightMaterial = v278;
  v297 = UFG::qStringHashUpper32("BlendVolumesIntoHalfSizeTarget", 0xFFFFFFFF);
  v298 = Illusion::Factory::NewMaterial("BlendVolumesIntoHalfSizeTarget", v297, 5u, 0i64, 0i64, 0i64);
  v299 = UFG::qStringHash32("BLENDVOLUMETRICEFFECTS", 0xFFFFFFFF);
  LOWORD(v298[1].mNode.mChild[0]) = 0;
  HIDWORD(v298[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v300 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v298[1].mTypeUID = -1957338719;
  LODWORD(v298[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v299;
  LODWORD(v298[1].mNode.mParent) = v300;
  v301 = this->mQuarterSizeVolumetricTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v298[1].mDebugName[12] = 0;
  *(_DWORD *)&v298[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v302 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v298[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v298[1].mStateBlockMask.mFlags[0]) = v301;
  *(_DWORD *)&v298[1].mDebugName[4] = v302;
  LOWORD(v298[1].mMaterialUser.mOffset) = 0;
  *(&v298[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v303 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v298[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v298[2].mNode.mUID = -89056095;
  v298[1].mNumParams = v303;
  LOWORD(v298[2].mTypeUID) = 0;
  HIDWORD(v298[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v304 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v298[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v298[2].mDebugName[28] = 1660426324;
  LODWORD(v298[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v304;
  v305 = this->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v298[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v298[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v306 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v298[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v298[3].mNode.mChild[0]) = v305;
  LODWORD(v298[2].mStateBlockMask.mFlags[0]) = v306;
  v307 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v307, v298);
  this->mMatBlendVolumesIntoHalfSize = v298;
  v308 = UFG::qStringHashUpper32("PostCompLightshaft", 0xFFFFFFFF);
  v309 = Illusion::Factory::NewMaterial("PostCompLightshaft", v308, 5u, 0i64, 0i64, 0i64);
  v310 = UFG::qStringHash32("HK_POSTCOMPBLIT_LIGHTSHAFT", 0xFFFFFFFF);
  LOWORD(v309[1].mNode.mChild[0]) = 0;
  HIDWORD(v309[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v311 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v309[1].mTypeUID = -1957338719;
  LODWORD(v309[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v310;
  LODWORD(v309[1].mNode.mParent) = v311;
  v312 = this->mHalfSizeVolumetricTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v309[1].mDebugName[12] = 0;
  *(_DWORD *)&v309[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v313 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v309[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v309[1].mStateBlockMask.mFlags[0]) = v312;
  *(_DWORD *)&v309[1].mDebugName[4] = v313;
  LOWORD(v309[1].mMaterialUser.mOffset) = 0;
  *(&v309[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v314 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v309[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v309[2].mNode.mUID = -89056095;
  v309[1].mNumParams = v314;
  LOWORD(v309[2].mTypeUID) = 0;
  HIDWORD(v309[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v315 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v309[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v309[2].mDebugName[28] = 1660426324;
  LODWORD(v309[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v315;
  v316 = mDepthTextureCopy->mNode.mUID;
  LOWORD(v309[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v309[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v309[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v309[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v309[3].mNode.mChild[0]) = v316;
  v317 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v317, v309);
  this->mPostCompLightshaftMaterial = v309;
  v318 = UFG::qStringHashUpper32("BloomThresholdMaterial", 0xFFFFFFFF);
  v319 = Illusion::Factory::NewMaterial("BloomThresholdMaterial", v318, 7u, 0i64, 0i64, 0i64);
  v320 = UFG::qStringHash32("BLOOMTHRESHOLD", 0xFFFFFFFF);
  LOWORD(v319[1].mNode.mChild[0]) = 0;
  HIDWORD(v319[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v321 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v319[1].mTypeUID = -1957338719;
  LODWORD(v319[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v320;
  LODWORD(v319[1].mNode.mParent) = v321;
  *(_WORD *)&v319[1].mDebugName[12] = 0;
  *(_DWORD *)&v319[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v322 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v319[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v319[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v319[1].mDebugName[4] = v322;
  LOWORD(v319[1].mMaterialUser.mOffset) = 0;
  *(&v319[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v323 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v319[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v319[2].mNode.mUID = -89056095;
  v319[1].mNumParams = v323;
  LOWORD(v319[2].mTypeUID) = 0;
  HIDWORD(v319[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v324 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v319[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v319[2].mDebugName[28] = 1660426324;
  LODWORD(v319[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v324;
  v325 = this->mHalfSizeLinearDepthTarget->mDepthTextureCopy->mNode.mUID;
  LOWORD(v319[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v319[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v326 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v319[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v319[2].mStateBlockMask.mFlags[0]) = v326;
  LODWORD(v319[3].mNode.mChild[0]) = v325;
  v327 = this->mHalfSizeVolumetricTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v319[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v319[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v328 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v319[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v319[3].mDebugName[12] = v327;
  v319[3].mNode.mUID = v328;
  v329 = v5->mNode.mUID;
  *((_WORD *)&v319[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v319[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v330 = UFG::qStringHash32("texEmission", 0xFFFFFFFF);
  LODWORD(v319[4].mNode.mParent) = -1958479169;
  *(_DWORD *)&v319[3].mDebugName[28] = v330;
  LODWORD(v319[3].mMaterialUser.mOffset) = v329;
  v331 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v331, v319);
  this->mBloomThresholdMaterial = v319;
  v332 = UFG::qStringHashUpper32("AntiAliasMaterial", 0xFFFFFFFF);
  v333 = Illusion::Factory::NewMaterial("AntiAliasMaterial", v332, 6u, 0i64, 0i64, 0i64);
  LOWORD(v333[1].mNode.mChild[0]) = 0;
  v334 = v333;
  HIDWORD(v333[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v335 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v334[1].mTypeUID = -1957338719;
  LODWORD(v334[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 0;
  LODWORD(v334[1].mNode.mParent) = v335;
  *(_WORD *)&v334[1].mDebugName[12] = 0;
  *(_DWORD *)&v334[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v336 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v334[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v334[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v334[1].mDebugName[4] = v336;
  LOWORD(v334[1].mMaterialUser.mOffset) = 0;
  *(&v334[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v337 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v334[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v334[2].mNode.mUID = 662883558;
  v334[1].mNumParams = v337;
  LOWORD(v334[2].mTypeUID) = 0;
  HIDWORD(v334[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v338 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v334[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v334[2].mDebugName[28] = 1660426324;
  LODWORD(v334[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v338;
  v339 = mDepthTextureCopy->mNode.mUID;
  LOWORD(v334[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v334[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v340 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v334[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v334[3].mNode.mChild[0]) = v339;
  LODWORD(v334[2].mStateBlockMask.mFlags[0]) = v340;
  LOWORD(v334[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v334[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v341 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v334[3].mDebugName[20] = -1958479169;
  v334[3].mNode.mUID = v341;
  *(_DWORD *)&v334[3].mDebugName[12] = 0;
  v342 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v342, v334);
  this->mAntiAliasMaterial = v334;
  v343 = UFG::qStringHashUpper32("DistortionMaterial", 0xFFFFFFFF);
  v344 = Illusion::Factory::NewMaterial("DistortionMaterial", v343, 6u, 0i64, 0i64, 0i64);
  LOWORD(v344[1].mNode.mChild[0]) = 0;
  v345 = v344;
  HIDWORD(v344[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v346 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v345[1].mTypeUID = -1957338719;
  LODWORD(v345[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 0;
  LODWORD(v345[1].mNode.mParent) = v346;
  *(_WORD *)&v345[1].mDebugName[12] = 0;
  *(_DWORD *)&v345[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v347 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v345[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v345[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v345[1].mDebugName[4] = v347;
  LOWORD(v345[1].mMaterialUser.mOffset) = 0;
  *(&v345[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v348 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v345[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v345[2].mNode.mUID = 662883558;
  v345[1].mNumParams = v348;
  LOWORD(v345[2].mTypeUID) = 0;
  HIDWORD(v345[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v349 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v345[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v345[2].mDebugName[28] = 1660426324;
  LODWORD(v345[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v349;
  LOWORD(v345[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v345[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v350 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v345[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v345[3].mNode.mChild[0]) = 0;
  LODWORD(v345[2].mStateBlockMask.mFlags[0]) = v350;
  LOWORD(v345[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v345[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v351 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v345[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v345[3].mDebugName[12] = 0;
  v345[3].mNode.mUID = v351;
  v352 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v352, v345);
  this->mDistortionMaterial = v345;
}FFFFFFF);
  LODWORD(v345[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v345[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v345[1].mDebugName[4] = v347;
  LOWORD(v345

// File Line: 1495
// RVA: 0x46890
void __fastcall UFG::RenderContext::DeleteTargets(UFG::RenderContext *this)
{
  Illusion::Target *mDynamicRangeTarget; // rcx
  Illusion::Target *mLightBufferTarget; // rcx
  Illusion::Target *mHDRBloomTarget; // rcx
  Illusion::Target *mHalfSizeLinearDepthTarget; // rcx
  Illusion::Target *mHalfSizeTarget; // rcx
  Illusion::Target *mReflectionMipTarget; // rcx
  Illusion::Target *mReflectionTarget; // rcx
  Illusion::Target *mSphericalEnvMapTarget; // rcx
  Illusion::Target *mCubeMapTarget; // rcx
  Illusion::Target *mHalfSizeScratchTargetA; // rcx
  Illusion::Target *mHalfSizeScratchTargetB; // rcx
  Illusion::Target *mHalfSizeScratchTargetC; // rcx
  Illusion::Target *mQuarterSizeScratchTargetA; // rcx
  Illusion::Target *mQuarterSizeScratchTargetB; // rcx
  Illusion::Target *mEighthSizeScratchTargetA; // rcx
  Illusion::Target *mEighthSizeScratchTargetB; // rcx
  Illusion::Target *mSixteenthSizeScratchTargetA; // rcx
  Illusion::Target *mSixteenthSizeScratchTargetB; // rcx
  Illusion::Target *mThrityTwoSizeScratchTargetA; // rcx
  Illusion::Target *mThrityTwoSizeScratchTargetB; // rcx
  Illusion::Target *mSixtyFourSizeScratchTargetA; // rcx
  Illusion::Target *mSixtyFourSizeScratchTargetB; // rcx
  Illusion::Target *mAmbientOcclusionAliasTarget; // rcx
  Illusion::Target *mSkyOcclusionAliasTarget; // rcx
  Illusion::Target *mNearBlur; // rcx
  Illusion::Texture *mHeightmapShadowTextureAlias; // rcx
  Illusion::Target *mCascadeShadowTarget; // rcx
  Illusion::Target *mHalfSizeShadowTarget; // rcx
  Illusion::Target *mSingleShadowTarget; // rcx
  Illusion::Target *mHalfSizeSingleShadowTarget; // rcx
  Illusion::Target *mHeightmapTarget; // rcx
  Illusion::Target *mCharacterShadowTarget; // rcx
  Illusion::Target *mAAResultTarget; // rcx
  Illusion::Target *mDirectionalOcclusionTarget; // rcx
  Illusion::Texture *mLightBufferMain; // rcx
  Illusion::Target *mQuarterSizeAmbientOcclusionTarget; // rcx
  Illusion::UnorderedAccessView *mQuarterSizeAmbientOcclusionAliasUAV; // rcx
  Illusion::UnorderedAccessView *mQuarterSizeAmbientOcclusionScratchUAV; // rcx
  Illusion::UnorderedAccessView *mAmbientOcclusionAliasUAV; // rcx
  Illusion::UnorderedAccessView *mAmbientOcclusionScratchUAV; // rcx
  Illusion::Texture *mQuarterSizeScratchAPointSampleTexture; // rcx
  Illusion::Texture *mQuarterSizeScratchBPointSampleTexture; // rcx
  Illusion::Texture *mHalfSizeScratchCPointSampleTexture; // rcx
  Illusion::Texture *mHalfSizeScratchBPointSampleTexture; // rcx
  Illusion::Target *mQuarterSizeVolumetricTarget; // rcx
  Illusion::Target *mHalfSizeVolumetricTarget; // rcx

  if ( this->mTargetsCreated )
  {
    Illusion::DeleteTarget(this->mGBufferTarget, 1);
    mDynamicRangeTarget = this->mDynamicRangeTarget;
    this->mGBufferTarget = 0i64;
    Illusion::DeleteTarget(mDynamicRangeTarget, 1);
    mLightBufferTarget = this->mLightBufferTarget;
    this->mDynamicRangeTarget = 0i64;
    Illusion::DeleteTarget(mLightBufferTarget, 1);
    mHDRBloomTarget = this->mHDRBloomTarget;
    this->mLightBufferTarget = 0i64;
    Illusion::DeleteTarget(mHDRBloomTarget, 1);
    mHalfSizeLinearDepthTarget = this->mHalfSizeLinearDepthTarget;
    this->mHDRBloomTarget = 0i64;
    Illusion::DeleteTarget(mHalfSizeLinearDepthTarget, 1);
    mHalfSizeTarget = this->mHalfSizeTarget;
    this->mHalfSizeLinearDepthTarget = 0i64;
    Illusion::DeleteTarget(mHalfSizeTarget, 1);
    mReflectionMipTarget = this->mReflectionMipTarget;
    this->mHalfSizeTarget = 0i64;
    if ( mReflectionMipTarget )
    {
      Illusion::DeleteTarget(mReflectionMipTarget, 1);
      this->mReflectionMipTarget = 0i64;
    }
    mReflectionTarget = this->mReflectionTarget;
    if ( mReflectionTarget )
    {
      Illusion::DeleteTarget(mReflectionTarget, 1);
      this->mReflectionTarget = 0i64;
    }
    mSphericalEnvMapTarget = this->mSphericalEnvMapTarget;
    if ( mSphericalEnvMapTarget )
    {
      Illusion::DeleteTarget(mSphericalEnvMapTarget, 1);
      this->mSphericalEnvMapTarget = 0i64;
    }
    mCubeMapTarget = this->mCubeMapTarget;
    if ( mCubeMapTarget )
    {
      Illusion::DeleteTarget(mCubeMapTarget, 1);
      this->mCubeMapTarget = 0i64;
    }
    Illusion::DeleteTarget(this->mFullSizeScratchTargetA, 1);
    mHalfSizeScratchTargetA = this->mHalfSizeScratchTargetA;
    this->mFullSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mHalfSizeScratchTargetA, 1);
    mHalfSizeScratchTargetB = this->mHalfSizeScratchTargetB;
    this->mHalfSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mHalfSizeScratchTargetB, 1);
    mHalfSizeScratchTargetC = this->mHalfSizeScratchTargetC;
    this->mHalfSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(mHalfSizeScratchTargetC, 1);
    mQuarterSizeScratchTargetA = this->mQuarterSizeScratchTargetA;
    this->mHalfSizeScratchTargetC = 0i64;
    Illusion::DeleteTarget(mQuarterSizeScratchTargetA, 1);
    mQuarterSizeScratchTargetB = this->mQuarterSizeScratchTargetB;
    this->mQuarterSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mQuarterSizeScratchTargetB, 1);
    mEighthSizeScratchTargetA = this->mEighthSizeScratchTargetA;
    this->mQuarterSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(mEighthSizeScratchTargetA, 1);
    mEighthSizeScratchTargetB = this->mEighthSizeScratchTargetB;
    this->mEighthSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mEighthSizeScratchTargetB, 1);
    mSixteenthSizeScratchTargetA = this->mSixteenthSizeScratchTargetA;
    this->mEighthSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(mSixteenthSizeScratchTargetA, 1);
    mSixteenthSizeScratchTargetB = this->mSixteenthSizeScratchTargetB;
    this->mSixteenthSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mSixteenthSizeScratchTargetB, 1);
    mThrityTwoSizeScratchTargetA = this->mThrityTwoSizeScratchTargetA;
    this->mSixteenthSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(mThrityTwoSizeScratchTargetA, 1);
    mThrityTwoSizeScratchTargetB = this->mThrityTwoSizeScratchTargetB;
    this->mThrityTwoSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mThrityTwoSizeScratchTargetB, 1);
    mSixtyFourSizeScratchTargetA = this->mSixtyFourSizeScratchTargetA;
    this->mThrityTwoSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(mSixtyFourSizeScratchTargetA, 1);
    mSixtyFourSizeScratchTargetB = this->mSixtyFourSizeScratchTargetB;
    this->mSixtyFourSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(mSixtyFourSizeScratchTargetB, 1);
    mAmbientOcclusionAliasTarget = this->mAmbientOcclusionAliasTarget;
    this->mSixtyFourSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(mAmbientOcclusionAliasTarget, 1);
    mSkyOcclusionAliasTarget = this->mSkyOcclusionAliasTarget;
    this->mAmbientOcclusionAliasTarget = 0i64;
    Illusion::DeleteTarget(mSkyOcclusionAliasTarget, 1);
    mNearBlur = this->mNearBlur;
    this->mSkyOcclusionAliasTarget = 0i64;
    Illusion::DeleteTarget(mNearBlur, 1);
    mHeightmapShadowTextureAlias = this->mHeightmapShadowTextureAlias;
    this->mNearBlur = 0i64;
    Illusion::DeleteTexture(mHeightmapShadowTextureAlias, 1);
    mCascadeShadowTarget = this->mCascadeShadowTarget;
    this->mHeightmapShadowTextureAlias = 0i64;
    Illusion::DeleteTarget(mCascadeShadowTarget, 1);
    mHalfSizeShadowTarget = this->mHalfSizeShadowTarget;
    this->mCascadeShadowTarget = 0i64;
    this->mCascadeShadowTexture = 0i64;
    Illusion::DeleteTarget(mHalfSizeShadowTarget, 1);
    this->mHalfSizeShadowTarget = 0i64;
    Illusion::DeleteTarget(this->mQuarterSizeShadowTarget, 1);
    mSingleShadowTarget = this->mSingleShadowTarget;
    this->mQuarterSizeShadowTarget = 0i64;
    Illusion::DeleteTarget(mSingleShadowTarget, 1);
    mHalfSizeSingleShadowTarget = this->mHalfSizeSingleShadowTarget;
    this->mSingleShadowTarget = 0i64;
    Illusion::DeleteTarget(mHalfSizeSingleShadowTarget, 1);
    mHeightmapTarget = this->mHeightmapTarget;
    this->mHalfSizeSingleShadowTarget = 0i64;
    Illusion::DeleteTarget(mHeightmapTarget, 1);
    mCharacterShadowTarget = this->mCharacterShadowTarget;
    this->mHeightmapTarget = 0i64;
    Illusion::DeleteTarget(mCharacterShadowTarget, 1);
    Illusion::DeleteTexture(this->mCascadeShadowTextureAliasDepth, 1);
    Illusion::DeleteTexture(this->mHalfSizeShadowAliasTexture, 1);
    Illusion::DeleteTexture(this->mQuarterSizeShadowAliasTexture, 1);
    Illusion::DeleteTexture(this->mCharacterShadowTextureAliasDepth, 1);
    Illusion::DeleteTexture(this->mSingleShadowTextureAliasDepth, 1);
    Illusion::DeleteTexture(this->mHalfSizeSingleShadowAliasTexture, 1);
    mAAResultTarget = this->mAAResultTarget;
    this->mCharacterShadowTarget = 0i64;
    this->mCharacterShadowTexture = 0i64;
    this->mCascadeShadowTextureAliasDepth = 0i64;
    this->mHalfSizeShadowAliasTexture = 0i64;
    this->mQuarterSizeShadowAliasTexture = 0i64;
    this->mCharacterShadowTextureAliasDepth = 0i64;
    this->mSingleShadowTextureAliasDepth = 0i64;
    this->mHalfSizeSingleShadowAliasTexture = 0i64;
    if ( mAAResultTarget )
    {
      Illusion::DeleteTarget(mAAResultTarget, 1);
      this->mAAResultTarget = 0i64;
    }
    mDirectionalOcclusionTarget = this->mDirectionalOcclusionTarget;
    if ( mDirectionalOcclusionTarget )
    {
      Illusion::DeleteTarget(mDirectionalOcclusionTarget, 1);
      this->mDirectionalOcclusionTarget = 0i64;
    }
    mLightBufferMain = this->mLightBufferMain;
    if ( mLightBufferMain )
    {
      Illusion::DeleteTexture(mLightBufferMain, 1);
      this->mLightBufferMain = 0i64;
    }
    mQuarterSizeAmbientOcclusionTarget = this->mQuarterSizeAmbientOcclusionTarget;
    if ( mQuarterSizeAmbientOcclusionTarget )
    {
      Illusion::DeleteTarget(mQuarterSizeAmbientOcclusionTarget, 1);
      this->mQuarterSizeAmbientOcclusionTarget = 0i64;
    }
    mQuarterSizeAmbientOcclusionAliasUAV = this->mQuarterSizeAmbientOcclusionAliasUAV;
    if ( mQuarterSizeAmbientOcclusionAliasUAV )
    {
      Illusion::UnorderedAccessView::Delete(mQuarterSizeAmbientOcclusionAliasUAV);
      this->mQuarterSizeAmbientOcclusionAliasUAV = 0i64;
    }
    mQuarterSizeAmbientOcclusionScratchUAV = this->mQuarterSizeAmbientOcclusionScratchUAV;
    if ( mQuarterSizeAmbientOcclusionScratchUAV )
    {
      Illusion::UnorderedAccessView::Delete(mQuarterSizeAmbientOcclusionScratchUAV);
      this->mQuarterSizeAmbientOcclusionScratchUAV = 0i64;
    }
    mAmbientOcclusionAliasUAV = this->mAmbientOcclusionAliasUAV;
    if ( mAmbientOcclusionAliasUAV )
    {
      Illusion::UnorderedAccessView::Delete(mAmbientOcclusionAliasUAV);
      this->mAmbientOcclusionAliasUAV = 0i64;
    }
    mAmbientOcclusionScratchUAV = this->mAmbientOcclusionScratchUAV;
    if ( mAmbientOcclusionScratchUAV )
    {
      Illusion::UnorderedAccessView::Delete(mAmbientOcclusionScratchUAV);
      this->mAmbientOcclusionScratchUAV = 0i64;
    }
    mQuarterSizeScratchAPointSampleTexture = this->mQuarterSizeScratchAPointSampleTexture;
    if ( mQuarterSizeScratchAPointSampleTexture )
    {
      Illusion::DeleteTexture(mQuarterSizeScratchAPointSampleTexture, 1);
      this->mQuarterSizeScratchAPointSampleTexture = 0i64;
    }
    mQuarterSizeScratchBPointSampleTexture = this->mQuarterSizeScratchBPointSampleTexture;
    if ( mQuarterSizeScratchBPointSampleTexture )
    {
      Illusion::DeleteTexture(mQuarterSizeScratchBPointSampleTexture, 1);
      this->mQuarterSizeScratchBPointSampleTexture = 0i64;
    }
    mHalfSizeScratchCPointSampleTexture = this->mHalfSizeScratchCPointSampleTexture;
    if ( mHalfSizeScratchCPointSampleTexture )
    {
      Illusion::DeleteTexture(mHalfSizeScratchCPointSampleTexture, 1);
      this->mHalfSizeScratchCPointSampleTexture = 0i64;
    }
    mHalfSizeScratchBPointSampleTexture = this->mHalfSizeScratchBPointSampleTexture;
    if ( mHalfSizeScratchBPointSampleTexture )
    {
      Illusion::DeleteTexture(mHalfSizeScratchBPointSampleTexture, 1);
      this->mHalfSizeScratchBPointSampleTexture = 0i64;
    }
    mQuarterSizeVolumetricTarget = this->mQuarterSizeVolumetricTarget;
    if ( mQuarterSizeVolumetricTarget )
    {
      Illusion::DeleteTarget(mQuarterSizeVolumetricTarget, 1);
      this->mQuarterSizeVolumetricTarget = 0i64;
    }
    mHalfSizeVolumetricTarget = this->mHalfSizeVolumetricTarget;
    if ( mHalfSizeVolumetricTarget )
    {
      Illusion::DeleteTarget(mHalfSizeVolumetricTarget, 1);
      this->mHalfSizeVolumetricTarget = 0i64;
    }
    _((AMD_HD3D *)this->mRenderContextPlat);
    this->mTargetsCreated = 0;
  }
}

