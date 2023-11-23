// File Line: 63
// RVA: 0x1456AF0
__int64 UFG::_dynamic_initializer_for__gUsedRipples__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUsedRipples__);
}

// File Line: 64
// RVA: 0x1456AD0
__int64 UFG::_dynamic_initializer_for__gFreeRipples__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gFreeRipples__);
}

// File Line: 67
// RVA: 0x632F0
CB_WaterOffset *__fastcall UFG::Water::GetWaterSettings()
{
  CB_WaterOffset *result; // rax

  result = (CB_WaterOffset *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  gWaterSettings = result;
  result->RippleOffset[0] = UFG::Water::mCameraPos.x;
  result->RippleOffset[1] = UFG::Water::mCameraPos.y;
  result->FogFalloff[0] = UFG::`anonymous namespace::WaterFogFalloffScale;
  result->FogFalloff[1] = UFG::`anonymous namespace::WaterFogFalloffAdd;
  return result;
}

// File Line: 93
// RVA: 0x63350
void __fastcall UFG::Water::Init(int water_size, int num_mips)
{
  __int64 v4; // rbx
  char *v5; // rax
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v6; // rdx
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *mPrev; // rax
  unsigned int v8; // r15d
  Illusion::Target *(*v9)[2]; // rsi
  unsigned int i; // edi
  UFG::qString *v11; // rax
  Illusion::Target *v12; // rax
  Illusion::Texture *v13; // rbx
  unsigned int SamplerAddressFlags; // eax
  unsigned int v15; // eax
  int v16; // edi
  Illusion::Material *v17; // rbx
  Illusion::Material *v18; // rbx
  Illusion::Material *v19; // rbx
  Illusion::Material *v20; // rbx
  UFG::qResourceWarehouse *v21; // rax
  unsigned int v22; // eax
  int v23; // edi
  Illusion::Material *v24; // rbx
  Illusion::Material *v25; // rbx
  Illusion::Material *v26; // rbx
  Illusion::Material *v27; // rbx
  UFG::qResourceWarehouse *v28; // rax
  Illusion::CreateTargetParams v29; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v30; // [rsp+E0h] [rbp-20h]
  UFG::qString result; // [rsp+E8h] [rbp-18h] BYREF

  v30 = -2i64;
  *(_QWORD *)&UFG::Water::mCameraPos.x = 0i64;
  UFG::Water::mCameraPos.z = 0.0;
  UFG::Water::mCurrRippleTargetIndex = 0;
  UFG::Water::mRenderRippleTargetIndex = 0;
  v4 = 32i64;
  do
  {
    v5 = UFG::qMalloc(0x38ui64, "Water::RipleGenerator", 0i64);
    v6 = (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)v5;
    if ( v5 )
    {
      *(_QWORD *)v5 = v5;
      *((_QWORD *)v5 + 1) = v5;
      *((_QWORD *)v5 + 2) = v5 + 16;
      *((_QWORD *)v5 + 3) = v5 + 16;
      *((_QWORD *)v5 + 4) = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    mPrev = UFG::gFreeRipples.mNode.mPrev;
    UFG::gFreeRipples.mNode.mPrev->mNext = v6;
    v6->mPrev = mPrev;
    v6->mNext = (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)&UFG::gFreeRipples;
    UFG::gFreeRipples.mNode.mPrev = v6;
    --v4;
  }
  while ( v4 );
  v8 = 0;
  v9 = UFG::Water::mWaterRippleTarget;
  do
  {
    for ( i = 0; i < 2; ++i )
    {
      v11 = UFG::qString::FormatEx(&result, "RippleTarget%d_%d", v8, i);
      UFG::qString::qString(&v29.name, v11->mData);
      *(_QWORD *)&v29.num_mrt = 1i64;
      *(_QWORD *)&v29.width = 0i64;
      v29.depth = 1;
      v29.array_size = 1;
      *(_DWORD *)v29.mrt_formats = -1;
      v29.target_flags = 0;
      v29.num_mips = 1;
      memset(v29.textures, 0, 85);
      UFG::qString::~qString(&result);
      v29.width = water_size;
      v29.height = water_size;
      v29.mrt_formats[0] = 0;
      v29.target_flags = 0x20000;
      v29.num_mips = num_mips;
      v12 = Illusion::CreateTarget(&v29);
      (*v9)[0] = v12;
      v13 = v12->mTargetTexture[0];
      SamplerAddressFlags = Illusion::Texture::GetSamplerAddressFlags(v13);
      Illusion::Texture::SetSamplerState(v13, 1u, SamplerAddressFlags & 0xFFFFFFFC);
      UFG::qString::~qString(&v29.name);
      v9 = (Illusion::Target *(*)[2])((char *)v9 + 8);
    }
    ++v8;
  }
  while ( v8 < 4 );
  v15 = UFG::qStringHashUpper32("RippleMat", 0xFFFFFFFF);
  UFG::Water::mMatRipple = Illusion::Factory::NewMaterial("RippleMat", v15, 4u, 0i64, 0i64, 0i64);
  v16 = UFG::qStringHash32("HK_ICON", 0xFFFFFFFF);
  v17 = UFG::Water::mMatRipple;
  LOWORD(UFG::Water::mMatRipple[1].mNode.mChild[0]) = 0;
  HIDWORD(v17[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v17[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v17[1].mTypeUID = -1957338719;
  LODWORD(v17[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v16;
  v18 = UFG::Water::mMatRipple;
  *(_WORD *)&UFG::Water::mMatRipple[1].mDebugName[12] = 0;
  *(_DWORD *)&v18[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v18[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v18[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v18[1].mStateBlockMask.mFlags[0]) = 1579518255;
  v19 = UFG::Water::mMatRipple;
  LOWORD(UFG::Water::mMatRipple[1].mMaterialUser.mOffset) = 0;
  *(&v19[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v19[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v19[2].mNode.mUID = -773675157;
  v20 = UFG::Water::mMatRipple;
  LOWORD(UFG::Water::mMatRipple[2].mTypeUID) = 0;
  HIDWORD(v20[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v20[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v20[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v20[2].mDebugName[28] = 1660426324;
  v21 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v21, UFG::Water::mMatRipple);
  v22 = UFG::qStringHashUpper32("RippleIntegratorMat", 0xFFFFFFFF);
  UFG::Water::mMatRippleIntegrator = Illusion::Factory::NewMaterial("RippleIntegratorMat", v22, 4u, 0i64, 0i64, 0i64);
  v23 = UFG::qStringHash32("HK_RIPPLE", 0xFFFFFFFF);
  v24 = UFG::Water::mMatRippleIntegrator;
  LOWORD(UFG::Water::mMatRippleIntegrator[1].mNode.mChild[0]) = 0;
  HIDWORD(v24[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v24[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v24[1].mTypeUID = -1957338719;
  LODWORD(v24[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v23;
  v25 = UFG::Water::mMatRippleIntegrator;
  *(_WORD *)&UFG::Water::mMatRippleIntegrator[1].mDebugName[12] = 0;
  *(_DWORD *)&v25[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v25[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v25[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v25[1].mStateBlockMask.mFlags[0]) = 0;
  v26 = UFG::Water::mMatRippleIntegrator;
  LOWORD(UFG::Water::mMatRippleIntegrator[1].mMaterialUser.mOffset) = 0;
  *(&v26[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v26[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v26[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v26[2].mNode.mUID = 662883558;
  v27 = UFG::Water::mMatRippleIntegrator;
  LOWORD(UFG::Water::mMatRippleIntegrator[2].mTypeUID) = 0;
  HIDWORD(v27[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v27[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v27[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v27[2].mDebugName[28] = 1660426324;
  v28 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v28, UFG::Water::mMatRippleIntegrator);
}

// File Line: 164
// RVA: 0x63860
void __fastcall UFG::Water::ModifyRippleGeneratorScale(
        UFG::RippleGenerator *ripple,
        UFG::qVector2 *scale,
        UFG::qVector2 *offset)
{
  float y; // xmm0_4
  float v4; // xmm1_4

  y = scale->y;
  ripple->scale.x = scale->x;
  ripple->scale.y = y;
  v4 = offset->y;
  ripple->offset.x = offset->x;
  ripple->offset.y = v4;
}

// File Line: 170
// RVA: 0x63270
UFG::qVector2 *__fastcall UFG::RoadNetworkGuide::GetTargetLocation(UFG::RippleGenerator *ripple)
{
  return &ripple->scale;
}

// File Line: 175
// RVA: 0x63890
void __fastcall UFG::Water::RemoveRippleGenerator(UFG::RippleGenerator *generator)
{
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *mNext; // rax
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *mPrev; // rdx
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v3; // rax

  if ( generator )
  {
    mNext = generator->mNext;
    mPrev = generator->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    generator->mPrev = generator;
    generator->mNext = generator;
    v3 = UFG::gFreeRipples.mNode.mPrev;
    UFG::gFreeRipples.mNode.mPrev->mNext = generator;
    generator->mPrev = v3;
    generator->mNext = (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)&UFG::gFreeRipples;
    UFG::gFreeRipples.mNode.mPrev = generator;
  }
}

// File Line: 185
// RVA: 0x63100
UFG::RippleGenerator *__fastcall UFG::Water::AddRippleGenerator(
        UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *transform,
        UFG::qVector2 *scale)
{
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *mNext; // r8
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v6; // rax
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *mPrev; // rcx
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v8; // r9
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v9; // rax
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v10; // rcx
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_mNext; // rdx
  float y; // xmm0_4

  mNext = UFG::gFreeRipples.mNode.mNext;
  if ( (UFG::qList<UFG::RippleGenerator,UFG::RippleGenerator,1,0> *)UFG::gFreeRipples.mNode.mNext == &UFG::gFreeRipples )
    return 0i64;
  v6 = UFG::gFreeRipples.mNode.mNext->mNext;
  mPrev = UFG::gFreeRipples.mNode.mNext->mPrev;
  v8 = UFG::gFreeRipples.mNode.mNext + 1;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  v9 = UFG::gUsedRipples.mNode.mPrev;
  UFG::gUsedRipples.mNode.mPrev->mNext = mNext;
  mNext->mPrev = v9;
  mNext->mNext = (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)&UFG::gUsedRipples;
  UFG::gUsedRipples.mNode.mPrev = mNext;
  if ( mNext[2].mPrev )
  {
    v10 = v8->mPrev;
    v11 = mNext[1].mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v8->mPrev = v8;
    mNext[1].mNext = mNext + 1;
  }
  mNext[2].mPrev = transform;
  if ( transform )
  {
    v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)transform->mNext;
    p_mNext = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)&transform->mNext;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
    v8->mPrev = (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)v12;
    mNext[1].mNext = (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)p_mNext;
    p_mNext->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
  }
  y = scale->y;
  *(float *)&mNext[2].mNext = scale->x;
  *((float *)&mNext[2].mNext + 1) = y;
  mNext[3].mPrev = 0i64;
  return (UFG::RippleGenerator *)mNext;
}

// File Line: 203
// RVA: 0x638D0
void __fastcall UFG::Water::UpdateRippleMap(
        UFG::RenderContext *render_context,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  bool v3; // di
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm15_4
  Illusion::Target *v7; // r14
  Illusion::Target *v8; // rsi
  __m128 m_WeatherState_low; // xmm1
  int v10; // ecx
  int v11; // ebx
  unsigned int mUID; // r8d
  Illusion::Material *v13; // rbx
  __int64 mOffset; // rax
  _WORD *v15; // rax
  unsigned int v16; // edi
  int i; // ebx
  float h; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *j; // rdi
  UFG::TransformNodeComponent *mPrev; // rbx
  float v23; // xmm6_4
  float v24; // xmm8_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *v27; // rbx
  __m128 mPrev_low; // xmm6
  float v29; // xmm8_4
  float v30; // xmm10_4
  float v31; // xmm12_4
  UFG::TransformNodeComponent *v32; // rbx
  float v33; // xmm8_4
  float y; // xmm7_4
  float z; // xmm6_4
  float w; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm3_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm7_4
  float v45; // xmm6_4
  float v46; // xmm7_4
  float v47; // xmm6_4
  UFG::qMatrix44 local_world; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qColour colour; // [rsp+90h] [rbp-70h] BYREF
  Render::Poly v50; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qColour v51; // [rsp+A8h] [rbp-58h] BYREF
  Render::Poly poly; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v53; // [rsp+C0h] [rbp-40h]
  Render::ViewSettings settings; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qMatrix44 dest; // [rsp+160h] [rbp+60h] BYREF
  UFG::qMatrix44 d; // [rsp+1A0h] [rbp+A0h] BYREF
  Render::View v57; // [rsp+1E0h] [rbp+E0h] BYREF
  RenderQueueLayer v58; // [rsp+370h] [rbp+270h] BYREF
  LayerSubmitContext ptr; // [rsp+450h] [rbp+350h] BYREF
  int pseed; // [rsp+11A0h] [rbp+10A0h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+11B0h] [rbp+10B0h]
  float x; // [rsp+11B8h] [rbp+10B8h]

  v53 = -2i64;
  if ( render_context->mRenderFeatures.mWorld && UFG::gEnableWater )
  {
    v3 = UFG::Metrics::msInstance.mSimPausedInGame || UFG::Metrics::msInstance.mSimPausedDebug;
    UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
    x = d.v3.x;
    UFG::Water::mCameraPos.x = d.v3.x;
    *(float *)&p_mStateArgs = d.v3.y;
    UFG::Water::mCameraPos.y = d.v3.y;
    UFG::Water::mCameraPos.z = d.v3.z;
    Render::Poly::Poly(&v50, -0.5, -0.5, 1.0, 1.0, 0.0);
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    if ( v3 )
    {
      v4 = 0.0;
    }
    else
    {
      v5 = (float)(int)UFG::Metrics::msRealTimeMSec;
      if ( (UFG::Metrics::msRealTimeMSec & 0x8000000000000000ui64) != 0i64 )
        v5 = v5 + 1.8446744e19;
      v4 = v5 * 0.001;
    }
    v6 = (float)(sinf(UFG::gWaterRippleFreq * v4) + 1.0) * 0.5;
    if ( (UFG::Water::mCurrRippleTargetIndex & 1) != 0 )
    {
      v7 = UFG::Water::mWaterRippleTarget[Render::GetCurrentGPUIndex()][0];
      v8 = UFG::Water::mWaterRippleTarget[Render::GetCurrentGPUIndex()][1];
    }
    else
    {
      v8 = UFG::Water::mWaterRippleTarget[Render::GetCurrentGPUIndex()][0];
      v7 = UFG::Water::mWaterRippleTarget[Render::GetCurrentGPUIndex()][1];
    }
    local_world.v0 = UFG::qMatrix44::msIdentity.v0;
    local_world.v1 = UFG::qMatrix44::msIdentity.v1;
    local_world.v2 = UFG::qMatrix44::msIdentity.v2;
    UFG::qOrthographicMatrix(&dest, 1.0, 1.0, -100.0, 100.0);
    if ( v3 )
    {
      UFG::Water::mRenderRippleTargetIndex = UFG::Water::mCurrRippleTargetIndex;
    }
    else
    {
      UFG::Water::mRenderRippleTargetIndex = UFG::Water::mCurrRippleTargetIndex + 1;
      if ( !Render::GetCurrentGPUIndex() )
      {
        UFG::Water::mRandomSeed = UFG::qGetTicks();
        m_WeatherState_low = (__m128)LODWORD(UFG::TimeOfDayManager::GetInstance()->m_WeatherState);
        m_WeatherState_low.m128_f32[0] = m_WeatherState_low.m128_f32[0] - 1.0;
        if ( m_WeatherState_low.m128_f32[0] <= 0.0 )
        {
          m_WeatherState_low = 0i64;
        }
        else if ( m_WeatherState_low.m128_f32[0] >= 1.0 )
        {
          m_WeatherState_low = (__m128)(unsigned int)FLOAT_1_0;
        }
        m_WeatherState_low.m128_f32[0] = m_WeatherState_low.m128_f32[0] * kMaxRipplePerFrame;
        v10 = (int)m_WeatherState_low.m128_f32[0];
        if ( (int)m_WeatherState_low.m128_f32[0] != 0x80000000 && (float)v10 != m_WeatherState_low.m128_f32[0] )
          m_WeatherState_low.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(m_WeatherState_low, m_WeatherState_low)) & 1)
                                                 + v10);
        UFG::Water::mRaindropsPerFrame = (int)m_WeatherState_low.m128_f32[0];
      }
      v11 = Render::GetGPUCount() - 1;
      if ( Render::GetCurrentGPUIndex() == v11 )
        ++UFG::Water::mCurrRippleTargetIndex;
    }
    pseed = UFG::Water::mRandomSeed;
    LayerSubmitContext::LayerSubmitContext(&ptr);
    RenderQueueLayer::RenderQueueLayer(&v58);
    v58.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v58;
    ptr.mQueueMode = QM_Default;
    settings.mCullIndex = -1;
    settings.mCullPixelDensityThreshold = FLOAT_0_2;
    settings.mCullPixelDistanceBias = 0.0;
    settings.mWorldView.v0 = local_world.v0;
    settings.mWorldView.v1 = local_world.v1;
    settings.mWorldView.v2 = local_world.v2;
    settings.mWorldView.v3 = (UFG::qVector4)_xmm;
    settings.mProjection = dest;
    Render::View::View(&v57, &settings, &ptr);
    Render::View::BeginTarget(&v57, v8, "RippleTarget", 0, 0, 0i64, 1, 0, 0, 0);
    if ( (int)UFG::Water::mRenderRippleTargetIndex >= 2 * Render::GetGPUCount() )
    {
      mUID = v7->mTargetTexture[0]->mNode.mUID;
      v13 = UFG::Water::mMatRippleIntegrator;
      if ( LODWORD(UFG::Water::mMatRippleIntegrator[1].mStateBlockMask.mFlags[0]) != mUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&UFG::Water::mMatRippleIntegrator[1].mDebugName[20],
          UFG::Water::mMatRippleIntegrator[1].mStateBlockMask.mFlags[1],
          mUID);
        mOffset = v13->mMaterialUser.mOffset;
        if ( mOffset )
          v15 = (_WORD *)((char *)&v13->mMaterialUser + mOffset);
        else
          v15 = 0i64;
        *v15 |= 0x20u;
        v13 = UFG::Water::mMatRippleIntegrator;
      }
      Render::View::Draw(&v57, &poly, v13, 0i64);
      if ( !v3 )
      {
        v16 = UFG::Water::mRaindropsPerFrame;
        *(_QWORD *)&v51.r = 0i64;
        v51.b = 0.0;
        v51.a = 1.0;
        for ( i = 0; i < v16; ++i )
        {
          h = (float)((float)i * 0.0049999999) + kSizeOfRipple;
          v19 = UFG::qRandom(1.0, &pseed);
          v20 = UFG::qRandom(1.0, &pseed);
          Render::Poly::Poly((Render::Poly *)&colour, v20, v19, h, h, 0.0);
          Render::Poly::SetColour((Render::Poly *)&colour, &v51);
          Render::View::Draw(&v57, (Render::Poly *)&colour, 0x5E25892Fu, 0i64, 0x62F81854u, 0x69DAE2D1u);
        }
      }
      for ( j = UFG::gUsedRipples.mNode.mNext;
            j != (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)&UFG::gUsedRipples;
            j = j->mNext )
      {
        mPrev = (UFG::TransformNodeComponent *)j[2].mPrev;
        if ( mPrev )
        {
          local_world = UFG::qMatrix44::msIdentity;
          v23 = *((float *)&j[3].mPrev + 1);
          v24 = *(float *)&j[3].mPrev;
          UFG::TransformNodeComponent::UpdateWorldTransform(mPrev);
          v25 = (float)((float)(v23 * mPrev->mWorldTransform.v1.x) + (float)(v24 * mPrev->mWorldTransform.v0.x))
              + (float)(mPrev->mWorldTransform.v2.x * 0.0);
          v26 = (float)((float)(v24 * mPrev->mWorldTransform.v0.y) + (float)(v23 * mPrev->mWorldTransform.v1.y))
              + (float)(mPrev->mWorldTransform.v2.y * 0.0);
          v27 = j[2].mPrev;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v27);
          mPrev_low = (__m128)LODWORD(v27[11].mPrev);
          mPrev_low.m128_f32[0] = mPrev_low.m128_f32[0] + v25;
          v29 = v26 + *((float *)&v27[11].mPrev + 1);
          v30 = fmodf(v29 * -0.015625, 1.0);
          v31 = fmodf(mPrev_low.m128_f32[0] * 0.015625, 1.0);
          mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] - x) * (float)(mPrev_low.m128_f32[0] - x))
                                + (float)((float)(v29 - *(float *)&p_mStateArgs) * (float)(v29 - *(float *)&p_mStateArgs));
          if ( _mm_sqrt_ps(mPrev_low).m128_f32[0] <= 32.0 )
          {
            local_world.v3.x = v31;
            local_world.v3.y = v30;
            local_world.v3.z = 0.0;
            local_world.v3.w = 1.0;
            v32 = (UFG::TransformNodeComponent *)j[2].mPrev;
            UFG::TransformNodeComponent::UpdateWorldTransform(v32);
            v33 = v32->mWorldTransform.v1.x;
            y = v32->mWorldTransform.v1.y;
            z = v32->mWorldTransform.v1.z;
            w = v32->mWorldTransform.v1.w;
            v37 = *(float *)&j[2].mNext;
            v38 = (float)(v32->mWorldTransform.v0.w * v37) * 0.015625;
            v39 = (float)((float)(v32->mWorldTransform.v0.z * v37) * 0.015625) * 0.0;
            v40 = (float)((float)(v32->mWorldTransform.v0.y * v37) * 0.015625) * -1.0;
            local_world.v0.x = (float)(v32->mWorldTransform.v0.x * v37) * 0.015625;
            local_world.v0.y = v40;
            local_world.v0.z = v39;
            local_world.v0.w = v38;
            v41 = *((float *)&j[2].mNext + 1) * w;
            v42 = (float)((float)(*((float *)&j[2].mNext + 1) * z) * 0.015625) * 0.0;
            v43 = (float)((float)(*((float *)&j[2].mNext + 1) * y) * 0.015625) * -1.0;
            local_world.v1.x = (float)(*((float *)&j[2].mNext + 1) * v33) * 0.015625;
            local_world.v1.y = v43;
            local_world.v1.z = v42;
            local_world.v1.w = v41 * 0.015625;
            colour.r = v6;
            colour.g = 1.0;
            colour.b = 0.5;
            colour.a = 1.0;
            Render::Poly::SetColours(&v50, &colour, &colour, &colour, &colour);
            if ( v31 <= 0.5 )
              v44 = *(float *)&FLOAT_1_0;
            else
              v44 = FLOAT_N1_0;
            if ( v30 <= 0.5 )
              v45 = *(float *)&FLOAT_1_0;
            else
              v45 = FLOAT_N1_0;
            Render::View::Draw(&v57, &v50, UFG::Water::mMatRipple, &local_world);
            local_world.v3.x = v31;
            local_world.v3.y = v30;
            local_world.v3.z = 0.0;
            local_world.v3.w = 1.0;
            Render::View::Draw(&v57, &v50, UFG::Water::mMatRipple, &local_world);
            v46 = v44 + v31;
            local_world.v3.x = v46;
            local_world.v3.y = v30;
            local_world.v3.z = 0.0;
            local_world.v3.w = 1.0;
            Render::View::Draw(&v57, &v50, UFG::Water::mMatRipple, &local_world);
            v47 = v45 + v30;
            local_world.v3.x = v31;
            local_world.v3.y = v47;
            local_world.v3.z = 0.0;
            local_world.v3.w = 1.0;
            Render::View::Draw(&v57, &v50, UFG::Water::mMatRipple, &local_world);
            local_world.v3.x = v46;
            local_world.v3.y = v47;
            local_world.v3.z = 0.0;
            local_world.v3.w = 1.0;
            Render::View::Draw(&v57, &v50, UFG::Water::mMatRipple, &local_world);
          }
        }
      }
    }
    else
    {
      colour.r = 0.5;
      colour.g = 0.5;
      colour.b = 0.5;
      colour.a = 0.5;
      Render::View::Clear(&v57, &colour, 1u, 1.0, 0);
    }
    Render::View::EndTarget(&v57);
    if ( v8->mTargetTexture[0]->mNumMipMaps > 1u )
    {
      Render::gRenderUtilities.mSubmitContext = &ptr;
      Render::RenderUtilities::RenderMips(
        &Render::gRenderUtilities,
        v8,
        (unsigned __int8)v8->mTargetTexture[0]->mNumMipMaps,
        kGaussBlur3x3UID_12);
      Render::gRenderUtilities.mSubmitContext = 0i64;
    }
    RenderQueueLayer::SerializeRenderQueues(&v58);
    RenderQueueLayer::~RenderQueueLayer(&v58);
    p_mStateArgs = &ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

// File Line: 408
// RVA: 0x63280
Illusion::Texture *__fastcall UFG::Water::GetRippleMap(bool bPostRippleMapUpdate)
{
  int v1; // ebx
  char v2; // bl

  if ( bPostRippleMapUpdate
    || (v1 = Render::GetGPUCount() - 1, Render::GetCurrentGPUIndex() == v1)
    || UFG::Metrics::msInstance.mSimPausedInGame
    || UFG::Metrics::msInstance.mSimPausedDebug )
  {
    v2 = ~(_BYTE)UFG::Water::mRenderRippleTargetIndex;
  }
  else
  {
    v2 = UFG::Water::mRenderRippleTargetIndex;
  }
  return UFG::Water::mWaterRippleTarget[Render::GetCurrentGPUIndex()][v2 & 1]->mTargetTexture[0];
}

