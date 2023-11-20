// File Line: 62
// RVA: 0x32C40
void __fastcall UFG::RenderStageExposureMetering::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  char *v2; // rax

  v1 = render_context;
  v2 = UFG::qMalloc(0xA8ui64, "RenderStageExposureMetering", 0i64);
  if ( v2 )
    UFG::RenderStageExposureMetering::RenderStageExposureMetering((UFG::RenderStageExposureMetering *)v2, v1);
}

// File Line: 67
// RVA: 0x32790
void __fastcall UFG::RenderStageExposureMetering::RenderStageExposureMetering(UFG::RenderStageExposureMetering *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageExposureMetering *v2; // rsi
  UFG::qResourceHandle *v3; // r14
  signed int v4; // ebx
  Illusion::Target **v5; // rdi
  UFG::qString *v6; // rax
  unsigned int v7; // eax
  Illusion::Material *v8; // rdi
  int v9; // ebx
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // ebx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qString v14; // [rsp+30h] [rbp-D0h]
  __int64 v15; // [rsp+58h] [rbp-A8h]
  int v16; // [rsp+60h] [rbp-A0h]
  int v17; // [rsp+64h] [rbp-9Ch]
  int v18; // [rsp+68h] [rbp-98h]
  __int64 v19; // [rsp+6Ch] [rbp-94h]
  int v20; // [rsp+74h] [rbp-8Ch]
  int v21; // [rsp+78h] [rbp-88h]
  __int128 v22; // [rsp+80h] [rbp-80h]
  __int128 v23; // [rsp+90h] [rbp-70h]
  __int64 v24; // [rsp+A0h] [rbp-60h]
  __int64 v25; // [rsp+A8h] [rbp-58h]
  __int64 v26; // [rsp+B0h] [rbp-50h]
  __int64 v27; // [rsp+B8h] [rbp-48h]
  __int64 v28; // [rsp+C0h] [rbp-40h]
  __int64 v29; // [rsp+C8h] [rbp-38h]
  int v30; // [rsp+D0h] [rbp-30h]
  char v31; // [rsp+D4h] [rbp-2Ch]
  __int64 v32; // [rsp+E0h] [rbp-20h]
  UFG::qString result; // [rsp+E8h] [rbp-18h]

  v32 = -2i64;
  v2 = this;
  v3 = (UFG::qResourceHandle *)&this->mStateBlockHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mStateBlockHandle.mPrev);
  v2->mCurrTargetIndex = 0;
  *(_QWORD *)&v2->mTargetExposureEV = 0i64;
  v2->mSkyIrradValue = 1.0;
  *(_WORD *)&v2->mEnableMetering = 1;
  v2->mExposureEVRate = 0.15000001;
  v2->mNumCameraIrradVol = 0;
  UFG::qMemSet(v2->mCameraIrradVol, 0, 0x30u);
  v2->mEnableSkyIrradBlend = 1.0;
  v2->mInsideNoSkyVisibleVolume = 0;
  v4 = 0;
  v5 = v2->mTarget;
  do
  {
    v6 = UFG::qString::FormatEx(&result, "MeteringTarget%d", (unsigned int)v4);
    UFG::qString::qString(&v14, v6->mData);
    v19 = 1i64;
    v15 = 0i64;
    v16 = 1;
    v17 = 1;
    v18 = -1;
    v20 = 0;
    v21 = 1;
    _mm_store_si128((__m128i *)&v22, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v23, (__m128i)0i64);
    v24 = 0i64;
    v25 = 0i64;
    v26 = 0i64;
    v27 = 0i64;
    v28 = 0i64;
    v29 = 0i64;
    v30 = 0;
    v31 = 0;
    UFG::qString::~qString(&result);
    v15 = 137438953504i64;
    LOBYTE(v18) = 0;
    v20 = 0x4000;
    *v5 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v14);
    UFG::qString::~qString(&v14);
    ++v4;
    ++v5;
  }
  while ( v4 < 5 );
  v7 = UFG::qStringHashUpper32("IrradianceSkyMetering", 0xFFFFFFFF);
  v8 = Illusion::Factory::NewMaterial("IrradianceSkyMetering", v7, 6u, 0i64, 0i64, 0i64);
  v9 = UFG::qStringHash32("DRIRRADIANCESKYMETER", 0xFFFFFFFF);
  LOWORD(v8[1].mNode.mChild[0]) = 0;
  HIDWORD(v8[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v8[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v8[1].mTypeUID = -1957338719;
  LODWORD(v8[1].mResourceHandles.mNode.mNext) = v9;
  *(_WORD *)&v8[1].mDebugName[12] = 0;
  *(_DWORD *)&v8[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v8[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v8[1].mStateBlockMask.mFlags[0]) = 662883558;
  LOWORD(v8[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v8[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v8[2].mNode.mUID = 1660426324;
  LOWORD(v8[2].mTypeUID) = 0;
  HIDWORD(v8[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  *((_DWORD *)&v8[2].0 + 22) = -1958479169;
  *(_DWORD *)&v8[2].mDebugName[28] = 0;
  LOWORD(v8[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  LODWORD(v8[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v8[3].mNode.mChild[0]) = 0;
  LOWORD(v8[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v8[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v8[3].mNode.mUID = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  *(_DWORD *)&v8[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v8[3].mDebugName[12] = 0;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, (UFG::qResourceData *)&v8->mNode);
  v2->mMaterial = v8;
  v11 = UFG::qStringHashUpper32("ed80cbf8-430b-4546-962c-6ca13242c855", 0xFFFFFFFF);
  v12 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v12;
  }
  UFG::qResourceHandle::Init(v3, 0x4D04C7F2u, v11, v12);
}

// File Line: 122
// RVA: 0x33850
void __fastcall UFG::RenderStageExposureMetering::Update(UFG::RenderStageExposureMetering *this, float realtime_delta)
{
  UFG::qResourceData *v2; // rdx
  UFG::RenderStageExposureMetering *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm1_4

  v2 = this->mStateBlockHandle.mData;
  v3 = this;
  v4 = realtime_delta;
  if ( v2 )
  {
    v5 = this->mSkyIrradValue;
    this->mExposureEVRate = *(float *)((char *)&v2[1].mResourceHandles.mNode.mNext
                                     + *(unsigned __int16 *)((char *)&v2[1].mResourceHandles.mNode.mNext
                                                           + ((HIDWORD(v2[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)));
    v6 = Illusion::StateBlockCurve::EvaluateCurve(
           (Illusion::StateBlockCurve *)((char *)&v2[1].mResourceHandles.mNode.mNext
                                       + *(unsigned __int16 *)((char *)&v2[1].mResourceHandles.mNode.mNext
                                                             + ((HIDWORD(v2[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0)
                                                             + 4)),
           v5);
    v7 = v3->mCurrentExposureEV;
    v8 = v4 * v3->mExposureEVRate;
    v9 = v6 * v3->mEnableSkyIrradBlend;
    v10 = v3->mCurrentExposureEV - v9;
    v3->mTargetExposureEV = v9;
    if ( COERCE_FLOAT(LODWORD(v10) & _xmm) >= v8 )
    {
      if ( v7 <= v9 )
      {
        if ( v7 < v9 )
          v3->mCurrentExposureEV = v7 + v8;
      }
      else
      {
        v3->mCurrentExposureEV = v7 - v8;
      }
    }
    else
    {
      v3->mCurrentExposureEV = v9;
    }
  }
}

// File Line: 148
// RVA: 0x33830
void __fastcall UFG::RenderStageExposureMetering::SetCameraIrradianceVolume(UFG::RenderStageExposureMetering *this, Render::IrradianceVolume *irradiance_volume)
{
  __int64 v2; // rax

  if ( irradiance_volume->mType == 2 )
  {
    v2 = this->mNumCameraIrradVol;
    if ( (unsigned int)v2 < 6 )
    {
      this->mCameraIrradVol[v2] = irradiance_volume;
      ++this->mNumCameraIrradVol;
    }
  }
}

// File Line: 157
// RVA: 0x33690
void __fastcall UFG::RenderStageExposureMetering::RenderDebug(UFG::RenderStageExposureMetering *this, UFG::RenderContext *render_context, Render::View *view)
{
  UFG::RenderContext *v3; // rsi
  UFG::RenderStageExposureMetering *v4; // rdi
  Render::DebugDrawContext *v5; // rbx

  v3 = render_context;
  v4 = this;
  if ( this->mDebugDisplay )
  {
    v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawTextA(
      v5,
      text_x,
      text_y,
      &UFG::qColour::White,
      "SkyIrrad       %1.3f",
      v4->mSkyIrradValue);
    Render::DebugDrawContext::DrawTextA(
      v5,
      text_x,
      text_y + text_height,
      &UFG::qColour::White,
      "Exposure EV    %1.3f | %1.3f",
      v4->mCurrentExposureEV,
      v4->mTargetExposureEV);
    Render::DebugDrawContext::DrawTextA(
      v5,
      text_x,
      text_y + 2 * text_height,
      &UFG::qColour::White,
      "Exposure Rate  %1.3f/sec",
      v4->mExposureEVRate);
    Render::DebugDrawContext::DrawTextA(
      v5,
      text_x,
      text_y + 2 * text_height + text_height,
      &UFG::qColour::White,
      "TOD Sky Blend  %1.3f",
      v4->mEnableSkyIrradBlend);
    Render::DebugDrawContext::DrawTextA(
      v5,
      text_x,
      text_y + 4 * text_height,
      &UFG::qColour::White,
      "Final Exposure %1.3f",
      v3->mEnvState->DisplayDebug[1]);
  }
}

// File Line: 174
// RVA: 0x32D10
void __fastcall UFG::RenderStageExposureMetering::Render(UFG::RenderStageExposureMetering *this, UFG::RenderContext *render_context, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list)
{
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // r15
  UFG::RenderContext *v4; // r14
  UFG::RenderStageExposureMetering *v5; // rdi
  float v6; // xmm0_4
  unsigned int v7; // er9
  Render::IrradianceVolume *v8; // rbx
  float v9; // xmm3_4
  unsigned int v10; // er10
  signed __int64 v11; // r11
  Render::IrradianceVolume **v12; // rdx
  unsigned int v13; // eax
  __int64 v14; // r8
  Render::IrradianceVolume *v15; // rcx
  signed __int64 v16; // rdx
  __int64 v17; // r8
  __int64 v18; // rcx
  Illusion::Target *v19; // rsi
  int v20; // xmm9_4
  unsigned int v21; // er8
  Illusion::Material *v22; // rsi
  __int64 v23; // rax
  _WORD *v24; // rax
  unsigned int v25; // er8
  Illusion::Material *v26; // rsi
  __int64 v27; // rax
  _WORD *v28; // rax
  Illusion::StateArgs *v29; // rsi
  __int128 v30; // xmm2
  __int128 v31; // xmm1
  __int128 v32; // xmm0
  __int128 v33; // xmm2
  __int128 v34; // xmm1
  __int128 v35; // xmm0
  CB_EnvironmentSettings *v36; // rbx
  Illusion::StateValues *v37; // rax
  char *v38; // rbx
  UFG::TimeOfDayManager *v39; // rax
  float v40; // xmm1_4
  float v41; // xmm2_4
  UFG::TimeOfDayManager *v42; // rax
  float v43; // xmm1_4
  float v44; // xmm2_4
  UFG::TimeOfDayManager *v45; // rax
  float v46; // xmm1_4
  float v47; // xmm2_4
  Illusion::StateValues *v48; // rax
  unsigned __int16 v49; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rax
  UFG::qVector3 scale; // [rsp+50h] [rbp-B0h]
  Illusion::TextureLockInfo info; // [rsp+60h] [rbp-A0h]
  Render::cbShadowTransformState arg; // [rsp+70h] [rbp-90h]
  float v57; // [rsp+D0h] [rbp-30h]
  float v58; // [rsp+D4h] [rbp-2Ch]
  float v59; // [rsp+D8h] [rbp-28h]
  int v60; // [rsp+DCh] [rbp-24h]
  UFG::qVector4 v61; // [rsp+E0h] [rbp-20h]
  UFG::qVector4 v62; // [rsp+F0h] [rbp-10h]
  UFG::qVector4 v63; // [rsp+100h] [rbp+0h]
  float v64; // [rsp+110h] [rbp+10h]
  float v65; // [rsp+114h] [rbp+14h]
  float v66; // [rsp+118h] [rbp+18h]
  float v67; // [rsp+11Ch] [rbp+1Ch]
  __int64 v68; // [rsp+120h] [rbp+20h]
  UFG::qVector4 v69; // [rsp+130h] [rbp+30h]
  __int128 v70; // [rsp+140h] [rbp+40h]
  __int128 v71; // [rsp+150h] [rbp+50h]
  __int128 v72; // [rsp+160h] [rbp+60h]
  UFG::qVector4 v73; // [rsp+170h] [rbp+70h]
  __int128 v74; // [rsp+180h] [rbp+80h]
  __int128 v75; // [rsp+190h] [rbp+90h]
  __int128 v76; // [rsp+1A0h] [rbp+A0h]
  Render::View v77; // [rsp+1B0h] [rbp+B0h]
  UFG::qMatrix44 dest; // [rsp+340h] [rbp+240h]
  UFG::qMatrix44 v79; // [rsp+380h] [rbp+280h]
  RenderQueueLayer v80; // [rsp+3C0h] [rbp+2C0h]
  LayerSubmitContext ptr; // [rsp+4A0h] [rbp+3A0h]
  Render::Poly poly; // [rsp+1190h] [rbp+1090h]
  Illusion::StateArgs *v83; // [rsp+1198h] [rbp+1098h]

  v68 = -2i64;
  v3 = serialization_list;
  v4 = render_context;
  v5 = this;
  v6 = render_context->mEnvState->AmbientColorHorizon[3];
  if ( v6 <= 0.0 )
  {
    v6 = 0.0;
  }
  else if ( v6 >= 1.0 )
  {
    v6 = *(float *)&FLOAT_1_0;
  }
  this->mEnableSkyIrradBlend = v6;
  v7 = this->mNumCameraIrradVol;
  this->mNumCameraIrradVol = 0;
  if ( this->mEnableMetering )
  {
    if ( v7 )
    {
      v8 = this->mCameraIrradVol[0];
      v9 = FLOAT_1000_0;
      if ( v7 > 1 )
      {
        v10 = 0;
        v11 = 0i64;
        if ( (signed int)v7 >= 4 )
        {
          v12 = &this->mCameraIrradVol[1];
          v13 = ((v7 - 4) >> 2) + 1;
          v14 = v13;
          v10 = 4 * v13;
          v11 = 4i64 * v13;
          do
          {
            if ( (float)((float)((float)((*(v12 - 1))->mScale.y / (float)(*(v12 - 1))->mImageDimensions[1])
                               * (float)((*(v12 - 1))->mScale.x / (float)(*(v12 - 1))->mImageDimensions[0]))
                       * (float)((*(v12 - 1))->mScale.z / (float)(*(v12 - 1))->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)((*(v12 - 1))->mScale.y / (float)(*(v12 - 1))->mImageDimensions[1])
                         * (float)((*(v12 - 1))->mScale.x / (float)(*(v12 - 1))->mImageDimensions[0]))
                 * (float)((*(v12 - 1))->mScale.z / (float)(*(v12 - 1))->mImageDimensions[2]);
              v8 = *(v12 - 1);
            }
            if ( (float)((float)((float)((*v12)->mScale.y / (float)(*v12)->mImageDimensions[1])
                               * (float)((*v12)->mScale.x / (float)(*v12)->mImageDimensions[0]))
                       * (float)((*v12)->mScale.z / (float)(*v12)->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)((*v12)->mScale.y / (float)(*v12)->mImageDimensions[1])
                         * (float)((*v12)->mScale.x / (float)(*v12)->mImageDimensions[0]))
                 * (float)((*v12)->mScale.z / (float)(*v12)->mImageDimensions[2]);
              v8 = *v12;
            }
            if ( (float)((float)((float)(v12[1]->mScale.y / (float)v12[1]->mImageDimensions[1])
                               * (float)(v12[1]->mScale.x / (float)v12[1]->mImageDimensions[0]))
                       * (float)(v12[1]->mScale.z / (float)v12[1]->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)(v12[1]->mScale.y / (float)v12[1]->mImageDimensions[1])
                         * (float)(v12[1]->mScale.x / (float)v12[1]->mImageDimensions[0]))
                 * (float)(v12[1]->mScale.z / (float)v12[1]->mImageDimensions[2]);
              v8 = v12[1];
            }
            v15 = v12[2];
            if ( (float)((float)((float)(v15->mScale.y / (float)v12[2]->mImageDimensions[1])
                               * (float)(v15->mScale.x / (float)v12[2]->mImageDimensions[0]))
                       * (float)(v15->mScale.z / (float)v15->mImageDimensions[2])) < v9 )
            {
              v9 = (float)((float)(v15->mScale.y / (float)v12[2]->mImageDimensions[1])
                         * (float)(v15->mScale.x / (float)v12[2]->mImageDimensions[0]))
                 * (float)(v15->mScale.z / (float)v15->mImageDimensions[2]);
              v8 = v12[2];
            }
            v12 += 4;
            --v14;
          }
          while ( v14 );
        }
        if ( v10 < v7 )
        {
          v16 = (signed __int64)&v5->mCameraIrradVol[v11];
          v17 = v7 - v10;
          do
          {
            if ( (float)((float)((float)(*(float *)(*(_QWORD *)v16 + 336i64)
                                       / (float)*(signed __int16 *)(*(_QWORD *)v16 + 358i64))
                               * (float)(*(float *)(*(_QWORD *)v16 + 332i64)
                                       / (float)*(signed __int16 *)(*(_QWORD *)v16 + 356i64)))
                       * (float)(*(float *)(*(_QWORD *)v16 + 340i64)
                               / (float)*(signed __int16 *)(*(_QWORD *)v16 + 360i64))) < v9 )
            {
              v9 = (float)((float)(*(float *)(*(_QWORD *)v16 + 336i64)
                                 / (float)*(signed __int16 *)(*(_QWORD *)v16 + 358i64))
                         * (float)(*(float *)(*(_QWORD *)v16 + 332i64)
                                 / (float)*(signed __int16 *)(*(_QWORD *)v16 + 356i64)))
                 * (float)(*(float *)(*(_QWORD *)v16 + 340i64) / (float)*(signed __int16 *)(*(_QWORD *)v16 + 360i64));
              v8 = *(Render::IrradianceVolume **)v16;
            }
            v16 += 8i64;
            --v17;
          }
          while ( v17 );
        }
      }
      v5->mInsideNoSkyVisibleVolume = 0;
      if ( v8 )
      {
        v18 = (v5->mCurrTargetIndex + 1) % 5;
        v5->mCurrTargetIndex = v18;
        v19 = v5->mTarget[v18];
        if ( v8->mFlags & 1 )
        {
          v5->mSkyIrradValue = 0.0;
          v5->mInsideNoSkyVisibleVolume = 1;
        }
        else if ( Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)v19->mTargetTexture[0], 0, &info, 0, 0) )
        {
          v5->mSkyIrradValue = (float)(unsigned __int8)*info.mData * 0.0039215689;
          Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v19->mTargetTexture[0]);
        }
        RenderQueueLayer::RenderQueueLayer(&v80);
        LayerSubmitContext::LayerSubmitContext(&ptr);
        v80.mSerializationList = v3;
        ptr.mRenderQueueProvider = &v80;
        ptr.mQueueMode = 0;
        Render::View::View(&v77, &v4->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
        if ( v8->mFlags & 4 )
          v20 = (signed int)FLOAT_1_0;
        else
          v20 = 0;
        Render::View::BeginTarget(&v77, v19, "ExposureMetering", 0, 0, 0i64, 1, 0, 0, 0);
        v21 = v8->mTextureUID[1];
        if ( !v21 )
          v21 = -1324127765;
        v22 = v5->mMaterial;
        if ( LODWORD(v22[3].mNode.mChild[0]) != v21 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v22[2].mNumParams,
            (unsigned int)v22[3].mNode.mChild[1],
            v21);
          v23 = v22->mMaterialUser.mOffset;
          if ( v23 )
            v24 = (_WORD *)((char *)&v22->mMaterialUser + v23);
          else
            v24 = 0i64;
          *v24 |= 0x20u;
        }
        v25 = v8->mTextureUID[2];
        if ( !v25 )
          v25 = -1324127765;
        v26 = v5->mMaterial;
        if ( *(_DWORD *)&v26[3].mDebugName[12] != v25 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v26[3].mResourceHandles.mNode.mNext,
            *(_DWORD *)&v26[3].mDebugName[20],
            v25);
          v27 = v26->mMaterialUser.mOffset;
          if ( v27 )
            v28 = (_WORD *)((char *)&v26->mMaterialUser + v27);
          else
            v28 = 0i64;
          *v28 |= 0x20u;
        }
        v29 = Render::View::GetStateArgs(&v77);
        v30 = (__int128)v8->mTransformInv.v1;
        v31 = (__int128)v8->mTransformInv.v2;
        v32 = (__int128)v8->mTransformInv.v3;
        v69 = v8->mTransformInv.v0;
        v70 = v30;
        v71 = v31;
        v72 = v32;
        v33 = (__int128)v8->mRotationMtxInv.v1;
        v34 = (__int128)v8->mRotationMtxInv.v2;
        v35 = (__int128)v8->mRotationMtxInv.v3;
        v73 = v8->mRotationMtxInv.v0;
        v74 = v33;
        v75 = v34;
        v76 = v35;
        scale.x = 1.0;
        scale.y = FLOAT_N1_0;
        scale.z = 0.5;
        if ( v8->mFlags & 4 )
          scale.y = 1.0;
        UFG::qScaleMatrix(&dest, &scale);
        dest.v3.z = 0.5;
        *(float *)&info.mData = scale.x * 2.0;
        *((float *)&info.mData + 1) = scale.y * 2.0;
        *(float *)&info.mLinePitch = scale.z * 2.0;
        UFG::qScaleMatrix(&v79, (UFG::qVector3 *)&info);
        v79.v3.x = -0.5;
        v79.v3.y = -0.5;
        v57 = (float)(v8->mScale.x / (float)((float)v8->mImageDimensions[0] - 1.0)) / (float)(v8->mScale.x * 2.0);
        v58 = (float)(v8->mScale.y / (float)((float)v8->mImageDimensions[1] - 1.0)) / (float)(v8->mScale.y * 2.0);
        v59 = (float)(v8->mScale.z / (float)((float)v8->mImageDimensions[2] - 1.0)) / (float)(v8->mScale.z * 2.0);
        v60 = 0;
        v36 = v4->mEnvState;
        v37 = Render::View::GetStateValues(&v77);
        v37->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
        v37->mParamValues[55] = v36;
        v38 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
        v39 = UFG::TimeOfDayManager::GetInstance();
        v40 = v39->mAmbientSkyDirection[0].y;
        v41 = v39->mAmbientSkyDirection[0].z;
        *(float *)v38 = v39->mAmbientSkyDirection[0].x;
        *((float *)v38 + 1) = v40;
        *((float *)v38 + 2) = v41;
        v42 = UFG::TimeOfDayManager::GetInstance();
        v43 = v42->mAmbientSkyDirection[1].y;
        v44 = v42->mAmbientSkyDirection[1].z;
        *((_DWORD *)v38 + 4) = LODWORD(v42->mAmbientSkyDirection[1].x);
        *((float *)v38 + 5) = v43;
        *((float *)v38 + 6) = v44;
        v45 = UFG::TimeOfDayManager::GetInstance();
        v46 = v45->mAmbientSkyDirection[2].y;
        v47 = v45->mAmbientSkyDirection[2].z;
        *((_DWORD *)v38 + 8) = LODWORD(v45->mAmbientSkyDirection[2].x);
        *((float *)v38 + 9) = v46;
        *((float *)v38 + 10) = v47;
        *((_DWORD *)v38 + 12) = v20;
        v48 = Render::View::GetStateValues(&v77);
        v48->mSetValueMask.mFlags[0] |= 0x8000ui64;
        v48->mParamValues[15] = v38;
        v61 = v77.mViewWorld.v0;
        v62 = v77.mViewWorld.v1;
        v63 = v77.mViewWorld.v2;
        v64 = v77.mViewWorld.v3.x;
        v65 = v77.mViewWorld.v3.y;
        v67 = v77.mViewWorld.v3.w;
        v66 = v77.mViewWorld.v3.z + 0.5;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mCallback = 0i64;
        arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
        *(_WORD *)&arg.mFlags = 1;
        if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
        {
          v49 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
          Render::cbShadowTransformState::sStateParamIndex = v49;
          arg.mStateParamIndex = v49;
        }
        arg.mViewWorld = (UFG::qMatrix44 *)&v61;
        arg.mWorldView = (UFG::qMatrix44 *)&v69;
        arg.mProjection = &dest;
        arg.mCutplanes = 0i64;
        arg.mBiases = &v57;
        arg.mBlurWidths = 0i64;
        arg.mCached_Remote.m_Stream = 0i64;
        Illusion::StateArgs::Set<Render::cbShadowTransformState>(v29, &arg);
        Render::Poly::Poly(&poly, 0.0, 0.0, 0.0625, 0.0625, 0.0);
        Render::View::Draw(&v77, &poly, v5->mMaterial, 0i64);
        v50 = arg.mPrev;
        v51 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v51->mPrev = v50;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v29->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v29 + 16 * (arg.mStateParamIndex + 3i64)) )
          v29->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        Render::View::EndTarget(&v77);
        v52 = arg.mPrev;
        v53 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v53->mPrev = v52;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        v83 = &ptr.mStateArgs;
        `eh vector destructor iterator(
          ptr.mStateArgs.mStateArgs,
          0x10ui64,
          128,
          (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
        RenderQueueLayer::~RenderQueueLayer(&v80);
      }
    }
    else
    {
      this->mSkyIrradValue = 1.0;
    }
  }
  else
  {
    this->mCurrentExposureEV = 0.0;
  }
}

