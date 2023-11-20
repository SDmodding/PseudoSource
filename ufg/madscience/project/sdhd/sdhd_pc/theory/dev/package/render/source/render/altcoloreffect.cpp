// File Line: 43
// RVA: 0x6FBA0
UFG::ComponentIDDesc *__fastcall UFG::AltColorPostEffect::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AltColorPostEffect::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AltColorPostEffect::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AltColorPostEffect::_TypeIDesc.mChildBitMask = v1;
    UFG::AltColorPostEffect::_TypeIDesc.mChildren = 0;
    UFG::AltColorPostEffect::_DescInit = 1;
    UFG::AltColorPostEffect::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AltColorPostEffect::_AltColorPostEffectTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AltColorPostEffect::_TypeIDesc;
}

// File Line: 92
// RVA: 0x6FFF0
signed __int64 __fastcall UFG::AltColorPostEffect::GetTypeSize(UFG::AltColorPostEffect *this)
{
  return 8912i64;
}

// File Line: 97
// RVA: 0x6F7A0
void __fastcall UFG::AltColorPostEffect::AltColorPostEffect(UFG::AltColorPostEffect *this)
{
  UFG::AltColorPostEffect *v1; // rdi
  unsigned int v2; // eax
  Illusion::Material *v3; // rax
  Illusion::Material *v4; // rbx
  UFG::qResourceWarehouse *v5; // rax
  unsigned int *v6; // rax
  signed __int64 v7; // rcx
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  _DWORD *v12; // rax
  signed __int64 v13; // rcx

  v1 = this;
  UFG::RenderStagePlugin::RenderStagePlugin((UFG::RenderStagePlugin *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AltColorPostEffect::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mStateBlockGlobal.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mStateBlockAlt.mPrev);
  *(_WORD *)&v1->mEnableGlobally = 256;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::AltColorPostEffect::_AltColorPostEffectTypeUID,
    "AltColorPostEffect");
  if ( !sIsStaticInit_4 )
  {
    v2 = UFG::qStringHashUpper32("AltColorVolume", 0xFFFFFFFF);
    v3 = Illusion::Factory::NewMaterial("AltColorVolume", v2, 4u, 0i64, 0i64, 0i64);
    v4 = v3;
    LOWORD(v3[1].mNode.mChild[0]) = 0;
    HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    LODWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    v4[1].mTypeUID = -1957338719;
    LODWORD(v4[1].mResourceHandles.mNode.mNext) = 2046191078;
    *(_WORD *)&v4[1].mDebugName[12] = 0;
    *(_DWORD *)&v4[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    *(_DWORD *)&v4[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
    LODWORD(v4[1].mStateBlockMask.mFlags[1]) = -1958479169;
    LODWORD(v4[1].mStateBlockMask.mFlags[0]) = 0;
    LOWORD(v4[1].mMaterialUser.mOffset) = 0;
    *(&v4[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    v4[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    LODWORD(v4[2].mResourceHandles.mNode.mPrev) = 315097330;
    v4[2].mNode.mUID = -1032465351;
    LOWORD(v4[2].mTypeUID) = 0;
    HIDWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    *((_DWORD *)&v4[2].0 + 22) = 1002903008;
    *(_DWORD *)&v4[2].mDebugName[28] = -823005223;
    v5 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v5, (UFG::qResourceData *)&v4->mNode);
    v1->mAltColorVolumeMaterial = v4;
    v6 = &v1->mVolumes[0].mVolumeUID;
    v7 = 32i64;
    do
    {
      *v6 = -1;
      v6 += 68;
      --v7;
    }
    while ( v7 );
    v8 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v8;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mStateBlockGlobal.mPrev, 0x4D04C7F2u, 0xFA64CB1u, v8);
    v10 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v10;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mStateBlockAlt.mPrev, 0x4D04C7F2u, 0xA6F3AB7u, v10);
    v12 = (_DWORD *)v1->mAltStateValues;
    v13 = 6i64;
    do
    {
      *(v12 - 6) = 1065353216;
      *v12 = 1065353216;
      ++v12;
      --v13;
    }
    while ( v13 );
    sIsStaticInit_4 = 1;
  }
}

// File Line: 148
// RVA: 0x70990
void __fastcall UFG::AltColorPostEffect::Update(UFG::AltColorPostEffect *this, float fDeltaT)
{
  UFG::qResourceData *v2; // rbx
  UFG::qResourceData *v3; // rdi
  UFG::AltColorPostEffect *v4; // rsi
  float v5; // xmm4_4
  __int64 v6; // r10
  char *v7; // r9
  int v8; // er8
  float *v9; // rdx
  __int64 v10; // r8
  float *v11; // rax
  float v12; // xmm3_4
  unsigned int v13; // ecx
  __int64 v14; // r10
  char *v15; // r9
  int v16; // er8
  float *v17; // rdx
  __int64 v18; // r8
  float *v19; // rax
  float v20; // xmm3_4
  unsigned int v21; // ecx

  v2 = this->mStateBlockGlobal.mData;
  v3 = this->mStateBlockAlt.mData;
  v4 = this;
  v5 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight * 0.000011574074;
  if ( v2 )
  {
    v6 = 0i64;
    if ( v2[1].mNode.mUID )
    {
      do
      {
        v7 = (char *)v2
           + *(unsigned __int16 *)((char *)&v2[1].mResourceHandles.mNode.mNext
                                 + 4 * v6
                                 + ((HIDWORD(v2[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
        v8 = *((_DWORD *)v7 + 32);
        if ( !v8 )
          goto LABEL_11;
        v9 = (float *)(v7 + 132);
        v10 = (unsigned int)(v8 - 1);
        v11 = (float *)(v7 + 140);
        if ( v5 > *((float *)v7 + 33) )
        {
          if ( v5 < *(float *)&v7[8 * v10 + 132] )
          {
            v13 = 0;
            if ( (_DWORD)v10 )
            {
              while ( v5 > *v11 )
              {
                ++v13;
                v9 += 2;
                v11 += 2;
                if ( v13 >= (unsigned int)v10 )
                  goto LABEL_11;
              }
              v12 = (float)((float)((float)(v5 - *v9) / (float)(*v11 - *v9)) * (float)(v11[1] - v9[1])) + v9[1];
              goto LABEL_12;
            }
LABEL_11:
            v12 = 0.0;
            goto LABEL_12;
          }
          v12 = *(float *)&v7[8 * v10 + 136];
        }
        else
        {
          v12 = *((float *)v7 + 34);
        }
LABEL_12:
        v4->mGlobalStateValues[v6] = v12;
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < v2[1].mNode.mUID );
    }
  }
  if ( v3 )
  {
    v14 = 0i64;
    if ( v3[1].mNode.mUID )
    {
      do
      {
        v15 = (char *)v3
            + *(unsigned __int16 *)((char *)&v3[1].mResourceHandles.mNode.mNext
                                  + 4 * v14
                                  + ((HIDWORD(v3[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
        v16 = *((_DWORD *)v15 + 32);
        if ( !v16 )
          goto LABEL_24;
        v17 = (float *)(v15 + 132);
        v18 = (unsigned int)(v16 - 1);
        v19 = (float *)(v15 + 140);
        if ( v5 > *((float *)v15 + 33) )
        {
          if ( v5 < *(float *)&v15[8 * v18 + 132] )
          {
            v21 = 0;
            if ( (_DWORD)v18 )
            {
              while ( v5 > *v19 )
              {
                ++v21;
                v17 += 2;
                v19 += 2;
                if ( v21 >= (unsigned int)v18 )
                  goto LABEL_24;
              }
              v20 = (float)((float)((float)(v5 - *v17) / (float)(*v19 - *v17)) * (float)(v19[1] - v17[1])) + v17[1];
              goto LABEL_25;
            }
LABEL_24:
            v20 = 0.0;
            goto LABEL_25;
          }
          v20 = *(float *)&v15[8 * v18 + 136];
        }
        else
        {
          v20 = *((float *)v15 + 34);
        }
LABEL_25:
        v4->mAltStateValues[v14] = v20;
        v14 = (unsigned int)(v14 + 1);
      }
      while ( (unsigned int)v14 < v3[1].mNode.mUID );
    }
  }
}

// File Line: 179
// RVA: 0x70060
void __fastcall UFG::AltColorPostEffect::RenderFinalPass(UFG::AltColorPostEffect *this, UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list, UFG::RenderContext *render_context, float delta_time, Illusion::Target **curr_target, Illusion::Target **scratch_target)
{
  UFG::RenderContext *v6; // r13
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v7; // rbx
  UFG::AltColorPostEffect *v8; // rsi
  _WORD *v9; // rdi
  float v10; // er14
  signed __int64 v11; // rbx
  signed __int64 v12; // r15
  unsigned int v13; // er8
  Illusion::Material *v14; // rbx
  __int64 v15; // rax
  _WORD *v16; // rax
  Illusion::StateArgs *v17; // rbx
  Render::ViewSettings *v18; // r15
  UFG::qMatrix44 *v19; // rax
  int v20; // eax
  __int64 *v21; // r15
  __int64 v22; // r13
  _OWORD *v23; // rax
  __int128 v24; // xmm2
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  __int128 v27; // xmm2
  __int128 v28; // xmm1
  __int128 v29; // xmm0
  unsigned __int16 v30; // ax
  Illusion::StateValues *v31; // rax
  Illusion::Material *dest_mip_level; // ST20_8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v36; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rax
  Render::ViewSettings *v41; // rax
  Illusion::Material *v42; // r15
  __int64 v43; // rax
  _WORD *v44; // rax
  Illusion::Target **v45; // r12
  unsigned int v46; // er8
  __int64 v47; // rax
  _WORD *v48; // rax
  signed int v49; // er8
  __int64 v50; // rax
  char *v51; // rax
  char *v52; // rbx
  Illusion::StateValues *v53; // rax
  Illusion::Target *v54; // rcx
  Illusion::Target **v55; // rdx
  float distance_from_near_plane; // [rsp+50h] [rbp-B0h]
  Render::cbExternalViewTransformState arg; // [rsp+58h] [rbp-A8h]
  Render::cbShadowTransformState v58; // [rsp+90h] [rbp-70h]
  UFG::qVector3 scale; // [rsp+F0h] [rbp-10h]
  UFG::qVector3 v60; // [rsp+FCh] [rbp-4h]
  __int64 v61; // [rsp+108h] [rbp+8h]
  __int128 v62; // [rsp+110h] [rbp+10h]
  __int128 v63; // [rsp+120h] [rbp+20h]
  __int128 v64; // [rsp+130h] [rbp+30h]
  __int128 v65; // [rsp+140h] [rbp+40h]
  __int128 v66; // [rsp+150h] [rbp+50h]
  __int128 v67; // [rsp+160h] [rbp+60h]
  __int128 v68; // [rsp+170h] [rbp+70h]
  __int128 v69; // [rsp+180h] [rbp+80h]
  UFG::qMatrix44 dest; // [rsp+190h] [rbp+90h]
  UFG::qMatrix44 v71; // [rsp+1D0h] [rbp+D0h]
  Render::View v72; // [rsp+210h] [rbp+110h]
  RenderQueueLayer v73; // [rsp+3A0h] [rbp+2A0h]
  Render::View v74; // [rsp+480h] [rbp+380h]
  __int64 v75[32]; // [rsp+610h] [rbp+510h]
  Render::View v76; // [rsp+710h] [rbp+610h]
  LayerSubmitContext ptr; // [rsp+8A0h] [rbp+7A0h]
  Render::Poly poly; // [rsp+1560h] [rbp+1460h]

  poly.mVertices = (Render::vDynamic *)render_context;
  v61 = -2i64;
  v6 = render_context;
  v7 = serialization_list;
  v8 = this;
  if ( render_context->mRenderFeatures.mWorld && this->mIsEnabled )
  {
    RenderQueueLayer::RenderQueueLayer(&v73);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v73.mSerializationList = v7;
    ptr.mRenderQueueProvider = &v73;
    v9 = 0i64;
    ptr.mQueueMode = 0;
    v10 = 0.0;
    if ( !v8->mEnableGlobally )
    {
      Render::View::View(&v76, &v6->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
      v11 = (signed __int64)v8->mVolumes;
      v12 = 32i64;
      do
      {
        if ( *(_DWORD *)(v11 + 0x10C) != -1
          && (unsigned int)Render::View::IsInView(
                             &v76,
                             &gDeferredCube,
                             (UFG::qMatrix44 *)v11,
                             &distance_from_near_plane) )
        {
          v75[LODWORD(v10)] = v11;
          ++LODWORD(v10);
        }
        v11 += 272i64;
        --v12;
      }
      while ( v12 );
      distance_from_near_plane = v10;
      if ( v10 != 0.0 )
      {
        v13 = v6->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
        v14 = v8->mAltColorVolumeMaterial;
        if ( LODWORD(v14[1].mStateBlockMask.mFlags[0]) != v13 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v14[1].mDebugName[20],
            v14[1].mStateBlockMask.mFlags[1],
            v13);
          v15 = v14->mMaterialUser.mOffset;
          if ( v15 )
            v16 = (_WORD *)((char *)&v14->mMaterialUser + v15);
          else
            v16 = 0i64;
          *v16 |= 0x20u;
        }
        Render::View::View(&v72, &v6->mMainViewSettings, (Illusion::SubmitContext *)&ptr.vfptr);
        Render::View::BeginTarget(&v72, *scratch_target, "Outline", 0, 0, 0i64, 1, 0, 0, 0);
        Render::View::Clear(&v72, &UFG::qColour::Black, 1u, 1.0, 1u);
        v17 = Render::View::GetStateArgs(&v72);
        v18 = v72.mSettings;
        v19 = &v72.mSettings->mProjection;
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
          v19 = &v18->mProjection;
        }
        arg.mWorldView = &v18->mWorldView;
        arg.mProjection = v19;
        arg.mCached_Remote.m_Stream = 0i64;
        Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(v17, &arg);
        if ( v10 != 0.0 )
        {
          v21 = v75;
          v22 = LODWORD(v10);
          do
          {
            v23 = (_OWORD *)*v21;
            v24 = *(_OWORD *)(*v21 + 80);
            v25 = *(_OWORD *)(*v21 + 96);
            v26 = *(_OWORD *)(*v21 + 112);
            v62 = *(_OWORD *)(*v21 + 64);
            v63 = v24;
            v64 = v25;
            v65 = v26;
            v27 = v23[13];
            v28 = v23[14];
            v29 = v23[15];
            v66 = v23[12];
            v67 = v27;
            v68 = v28;
            v69 = v29;
            scale.x = 1.0;
            scale.y = -1.0;
            scale.z = 0.5;
            UFG::qScaleMatrix(&dest, &scale);
            dest.v3.z = 0.5;
            v60.x = 2.0;
            v60.y = -2.0;
            v60.z = 1.0;
            UFG::qScaleMatrix(&v71, &v60);
            v71.v3.x = -0.5;
            v71.v3.y = -0.5;
            v58.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v58;
            v58.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v58;
            v58.mCallback = 0i64;
            v58.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
            *(_WORD *)&v58.mFlags = 1;
            if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
            {
              v30 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
              Render::cbShadowTransformState::sStateParamIndex = v30;
              v58.mStateParamIndex = v30;
            }
            v58.mViewWorld = &v72.mViewWorld;
            v58.mWorldView = (UFG::qMatrix44 *)&v62;
            v58.mProjection = &dest;
            v58.mCutplanes = 0i64;
            _mm_store_si128((__m128i *)&v58.mBiases, (__m128i)0i64);
            v58.mCached_Remote.m_Stream = 0i64;
            Illusion::StateArgs::Set<Render::cbShadowTransformState>(v17, &v58);
            v31 = Render::View::GetStateValues(&v72);
            Render::cbShadowTransformState::SetStateBlock(&v58, v31);
            dest_mip_level = v8->mAltColorVolumeMaterial;
            Render::View::Draw(&v72, &gDeferredCube, (UFG::qMatrix44 *)*v21, 0);
            v33 = v58.mPrev;
            v34 = v58.mNext;
            v58.mPrev->mNext = v58.mNext;
            v34->mPrev = v33;
            v58.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v58;
            v58.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v58;
            v58.mIsSet = 0;
            if ( (Illusion::StateArgs *)v17->mStateArgsCreateMask.mFlags[2 * (v58.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v17 + 16 * (v58.mStateParamIndex + 3i64)) )
              v17->mStateArgsCreateMask.mFlags[(unsigned int)v58.mStateParamIndex >> 6] &= ~(1i64 << (v58.mStateParamIndex & 0x3F));
            v35 = v58.mPrev;
            v36 = v58.mNext;
            v58.mPrev->mNext = v58.mNext;
            v36->mPrev = v35;
            v58.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v58;
            v58.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v58;
            ++v21;
            --v22;
          }
          while ( v22 );
          v10 = distance_from_near_plane;
          v6 = (UFG::RenderContext *)poly.mVertices;
        }
        v37 = arg.mPrev;
        v38 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v38->mPrev = v37;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mIsSet = 0;
        if ( (Illusion::StateArgs *)v17->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v17 + 16 * (arg.mStateParamIndex + 3i64)) )
          v17->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v39 = arg.mPrev;
        v40 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v40->mPrev = v39;
        arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        Render::View::EndTarget(&v72);
        Render::gRenderUtilities.mSubmitContext = (Illusion::SubmitContext *)&ptr;
        Render::RenderUtilities::GaussBlur3x3(
          &Render::gRenderUtilities,
          *scratch_target,
          v6->mHalfSizeScratchTargetB,
          0,
          0i64,
          kGaussBlur3x3UID_17);
      }
    }
    v41 = Render::ViewSettings::GetIdentity();
    Render::View::View(&v74, v41, (Illusion::SubmitContext *)&ptr.vfptr);
    Render::View::BeginTarget(&v74, *scratch_target, "ApplyColorEffects", 0, 0, 0i64, 1, 0, 0, 0);
    v42 = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != 293922946 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
        Render::gRenderUtilities.mMaterial[1].mTypeUID,
        0x1184E882u);
      v43 = v42->mMaterialUser.mOffset;
      if ( v43 )
        v44 = (_WORD *)((char *)&v42->mMaterialUser + v43);
      else
        v44 = 0i64;
      *v44 |= 0x20u;
    }
    v45 = curr_target;
    v46 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(v42[1].mStateBlockMask.mFlags[0]) != v46 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v42[1].mDebugName[20], v42[1].mStateBlockMask.mFlags[1], v46);
      v47 = v42->mMaterialUser.mOffset;
      if ( v47 )
        v48 = (_WORD *)((char *)&v42->mMaterialUser + v47);
      else
        v48 = 0i64;
      *v48 |= 0x20u;
    }
    if ( v10 == 0.0 )
    {
      v49 = 840494775;
      if ( v8->mEnableGlobally )
        v49 = -1324127765;
    }
    else
    {
      v49 = v6->mHalfSizeScratchTargetB->mTargetTexture[0]->mNode.mUID;
    }
    if ( *(_DWORD *)&v42[3].mDebugName[12] != v49 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v42[3].mResourceHandles.mNode.mNext,
        *(_DWORD *)&v42[3].mDebugName[20],
        v49);
      v50 = v42->mMaterialUser.mOffset;
      if ( v50 )
        v9 = (_WORD *)((char *)&v42->mMaterialUser + v50);
      *v9 |= 0x20u;
    }
    v51 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v52 = v51;
    if ( v6->mRenderFeatures.mPostFX )
    {
      *(float *)v51 = v8->mGlobalStateValues[0];
      *((_DWORD *)v51 + 1) = LODWORD(v8->mGlobalStateValues[1]);
      *((_DWORD *)v51 + 2) = LODWORD(v8->mGlobalStateValues[2]);
      *((_DWORD *)v51 + 3) = LODWORD(v8->mGlobalStateValues[3]);
      *((_DWORD *)v51 + 4) = LODWORD(v8->mGlobalStateValues[4]);
      *((_DWORD *)v51 + 5) = LODWORD(v8->mGlobalStateValues[5]);
      *((_DWORD *)v51 + 8) = LODWORD(v8->mAltStateValues[0]);
      *((_DWORD *)v51 + 9) = LODWORD(v8->mAltStateValues[1]);
      *((_DWORD *)v51 + 10) = LODWORD(v8->mAltStateValues[2]);
      *((_DWORD *)v51 + 11) = LODWORD(v8->mAltStateValues[3]);
      *((_DWORD *)v51 + 12) = LODWORD(v8->mAltStateValues[4]);
      *((_DWORD *)v51 + 13) = LODWORD(v8->mAltStateValues[5]);
    }
    else
    {
      *(_DWORD *)v51 = 0x3F800000;
      *((_DWORD *)v51 + 1) = 0x3F800000;
      *((_DWORD *)v51 + 2) = 1065353216;
      *((_DWORD *)v51 + 3) = 1065353216;
      *((_DWORD *)v51 + 4) = 1065353216;
      *((_DWORD *)v51 + 5) = 1065353216;
      *((_DWORD *)v51 + 8) = 1065353216;
      *((_DWORD *)v51 + 9) = 1065353216;
      *((_DWORD *)v51 + 10) = 1065353216;
      *((_DWORD *)v51 + 11) = 1065353216;
      *((_DWORD *)v51 + 12) = 1065353216;
      *((_DWORD *)v51 + 13) = 1065353216;
    }
    v53 = Render::View::GetStateValues(&v74);
    v53->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v53->mParamValues[15] = v52;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v74, &poly, v42, 0i64);
    Render::View::EndTarget(&v74);
    v54 = *v45;
    v55 = scratch_target;
    *v45 = *scratch_target;
    *v55 = v54;
    poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v73);
  }
}

// File Line: 325
// RVA: 0x6FF00
void __fastcall UFG::CreateAltColorPlugin(UFG *this)
{
  UFG::qMemoryPool *v1; // rax
  char *v2; // rax
  UFG::SimObjectModifier v3; // [rsp+38h] [rbp-30h]

  UFG::SimObjectModifier::SimObjectModifier(&v3, UFG::RenderWorld::msRenderStagePlugin, 1);
  v1 = UFG::GetSimulationMemoryPool();
  v2 = UFG::qMemoryPool::Allocate(v1, 0x22D0ui64, "AltColorPostEffect", 0i64, 1u);
  if ( v2 )
    UFG::AltColorPostEffect::AltColorPostEffect((UFG::AltColorPostEffect *)v2);
  UFG::SimObjectModifier::AttachComponent(&v3, (UFG::SimComponent *)v2, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v3);
  UFG::SimObjectModifier::~SimObjectModifier(&v3);
}

// File Line: 330
// RVA: 0x6FC30
void __fastcall UFG::AddAltColorEffect(unsigned int uid, UFG::qMatrix44 *mtx, UFG::qVector3 *box_min, UFG::qVector3 *box_max)
{
  UFG::qVector3 *v4; // rbx
  UFG::qVector3 *v5; // rbp
  UFG::qMatrix44 *v6; // rsi
  unsigned int v7; // er14
  UFG::SimComponent *v8; // r10
  unsigned int v9; // er8
  unsigned int *v10; // rdx
  unsigned int v11; // ecx
  signed __int64 v12; // rdi
  UFG::qVector4 *v13; // rdx
  float v14; // xmm14_4
  float v15; // xmm1_4
  float v16; // xmm11_4
  float v17; // xmm12_4
  float v18; // xmm13_4
  float v19; // xmm10_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm12_4
  float v27; // xmm13_4
  UFG::qVector4 v28; // xmm3
  UFG::qVector4 v29; // xmm2
  UFG::qVector4 v30; // xmm1
  UFG::qVector3 scale; // [rsp+20h] [rbp-A8h]

  v4 = box_max;
  v5 = box_min;
  v6 = mtx;
  v7 = uid;
  Render::GetRenderCallbacks();
  if ( UFG::RenderWorld::msRenderStagePlugin )
    v8 = UFG::SimObject::GetComponentOfType(UFG::RenderWorld::msRenderStagePlugin, UFG::AltColorPostEffect::_TypeUID);
  else
    v8 = 0i64;
  v9 = -1;
  v10 = &v8[5].m_NameUID;
  v11 = 0;
  while ( *v10 != -1 )
  {
    ++v11;
    v10 += 68;
    if ( v11 >= 0x20 )
      goto LABEL_9;
  }
  v9 = v11;
LABEL_9:
  v12 = (signed __int64)(&v8[1].m_SafePointerList.mNode.mNext + 34 * v9);
  v13 = (UFG::qVector4 *)(v12 + 128);
  v14 = (float)(v4->x - v5->x) * 0.5;
  v15 = v14 + v5->x;
  v16 = v6->v0.x * v15;
  v17 = v6->v0.y * v15;
  v18 = v6->v0.z * v15;
  v19 = (float)(v4->y - v5->y) * 0.5;
  v20 = v19 + v5->y;
  v21 = v6->v1.x * v20;
  v22 = v6->v1.y * v20;
  v23 = v6->v1.z * v20;
  v24 = (float)(v4->z - v5->z) * 0.5;
  v25 = v24 + v5->z;
  v26 = (float)((float)(v17 + v6->v3.y) + v22) + (float)(v6->v2.y * v25);
  v27 = (float)((float)(v18 + v6->v3.z) + v23) + (float)(v6->v2.z * v25);
  *(float *)(v12 + 256) = (float)((float)(v16 + v6->v3.x) + v21) + (float)(v6->v2.x * v25);
  *(float *)(v12 + 260) = v26;
  *(float *)(v12 + 264) = v27;
  v28 = v6->v1;
  v29 = v6->v2;
  v30 = v6->v3;
  *v13 = v6->v0;
  v13[1] = v28;
  v13[2] = v29;
  v13[3] = v30;
  *(_QWORD *)(v12 + 176) = 0i64;
  *(_DWORD *)(v12 + 184) = 0;
  *(_DWORD *)(v12 + 188) = 1065353216;
  UFG::qInverseAffine((UFG::qMatrix44 *)(v12 + 192), (UFG::qMatrix44 *)(v12 + 128));
  scale.x = v14;
  scale.y = v19;
  scale.z = v24 * 1.01;
  UFG::qScaleMatrix((UFG::qMatrix44 *)v12, &scale);
  UFG::qMatrix44::operator*=((UFG::qMatrix44 *)v12, (UFG::qMatrix44 *)(v12 + 128));
  v30.x = *(float *)(v12 + 260);
  v29.x = *(float *)(v12 + 264);
  *(_DWORD *)(v12 + 48) = *(_DWORD *)(v12 + 256);
  *(float *)(v12 + 52) = v30.x;
  *(float *)(v12 + 56) = v29.x;
  *(_DWORD *)(v12 + 60) = 1065353216;
  UFG::qInverse((UFG::qMatrix44 *)(v12 + 64), (UFG::qMatrix44 *)v12);
  *(_DWORD *)(v12 + 268) = v7;
}

// File Line: 380
// RVA: 0x70000
void __fastcall UFG::RemoveAltColorEffect(unsigned int uid)
{
  unsigned int v1; // ebx
  UFG::SimComponent *v2; // rax
  _DWORD *v3; // rax
  signed __int64 v4; // rcx

  v1 = uid;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = UFG::SimObject::GetComponentOfType(UFG::RenderWorld::msRenderStagePlugin, UFG::AltColorPostEffect::_TypeUID);
    if ( v2 )
    {
      v3 = (_DWORD *)((char *)&v2[9].m_pSimObject + 4);
      v4 = 16i64;
      do
      {
        if ( *(v3 - 68) == v1 )
          *(v3 - 68) = -1;
        if ( *v3 == v1 )
          *v3 = -1;
        v3 += 136;
        --v4;
      }
      while ( v4 );
    }
  }
}

// File Line: 396
// RVA: 0x70890
void __fastcall UFG::SetAltColorEffectActiveGlobally(bool bEnable)
{
  bool v1; // bl
  UFG::SimComponent *v2; // rax

  v1 = bEnable;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = UFG::SimObject::GetComponentOfType(UFG::RenderWorld::msRenderStagePlugin, UFG::AltColorPostEffect::_TypeUID);
    if ( v2 )
      LOBYTE(v2[139].m_SafePointerList.mNode.mPrev) = v1;
  }
}

// File Line: 405
// RVA: 0x6FF90
void __fastcall UFG::EnableAltColorEffect(bool enable)
{
  bool v1; // bl
  UFG::SimComponent *v2; // rax

  v1 = enable;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = UFG::SimObject::GetComponentOfType(UFG::RenderWorld::msRenderStagePlugin, UFG::AltColorPostEffect::_TypeUID);
    if ( v2 )
      BYTE1(v2[139].m_SafePointerList.mNode.mPrev) = v1;
  }
}

// File Line: 414
// RVA: 0x708D0
void __fastcall UFG::SetGlobalEffectUID(unsigned int uid)
{
  unsigned int v1; // edi
  UFG::SimComponent *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax

  v1 = uid;
  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    v2 = UFG::SimObject::GetComponentOfType(UFG::RenderWorld::msRenderStagePlugin, UFG::AltColorPostEffect::_TypeUID);
    if ( v2 )
    {
      v3 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
      {
        v4 = UFG::qResourceWarehouse::Instance();
        v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x4D04C7F2u);
        `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v3;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2[137].m_TypeUID, 0x4D04C7F2u, v1, v3);
      v5 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
      {
        v6 = UFG::qResourceWarehouse::Instance();
        v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x4D04C7F2u);
        `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v5;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v2[137].m_BoundComponentHandles.mNode.mNext,
        0x4D04C7F2u,
        v1,
        v5);
    }
  }
}

