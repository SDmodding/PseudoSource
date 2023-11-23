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
__int64 __fastcall UFG::AltColorPostEffect::GetTypeSize(UFG::AltColorPostEffect *this)
{
  return 8912i64;
}

// File Line: 97
// RVA: 0x6F7A0
void __fastcall UFG::AltColorPostEffect::AltColorPostEffect(UFG::AltColorPostEffect *this)
{
  unsigned int v2; // eax
  Illusion::Material *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  unsigned int *p_mVolumeUID; // rax
  __int64 v6; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  float *mAltStateValues; // rax
  __int64 v12; // rcx

  UFG::RenderStagePlugin::RenderStagePlugin(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AltColorPostEffect::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mStateBlockGlobal);
  UFG::qResourceHandle::qResourceHandle(&this->mStateBlockAlt);
  *(_WORD *)&this->mEnableGlobally = 256;
  UFG::SimComponent::AddType(this, UFG::AltColorPostEffect::_AltColorPostEffectTypeUID, "AltColorPostEffect");
  if ( !sIsStaticInit_4 )
  {
    v2 = UFG::qStringHashUpper32("AltColorVolume", 0xFFFFFFFF);
    v3 = Illusion::Factory::NewMaterial("AltColorVolume", v2, 4u, 0i64, 0i64, 0i64);
    LOWORD(v3[1].mNode.mChild[0]) = 0;
    HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    LODWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    v3[1].mTypeUID = -1957338719;
    LODWORD(v3[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = 2046191078;
    *(_WORD *)&v3[1].mDebugName[12] = 0;
    *(_DWORD *)&v3[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    *(_DWORD *)&v3[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
    LODWORD(v3[1].mStateBlockMask.mFlags[1]) = -1958479169;
    LODWORD(v3[1].mStateBlockMask.mFlags[0]) = 0;
    LOWORD(v3[1].mMaterialUser.mOffset) = 0;
    *(&v3[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    v3[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
    v3[2].mNode.mUID = -1032465351;
    LOWORD(v3[2].mTypeUID) = 0;
    HIDWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    *((_DWORD *)&v3[2].UFG::qResourceData + 22) = 1002903008;
    *(_DWORD *)&v3[2].mDebugName[28] = -823005223;
    v4 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v4, v3);
    this->mAltColorVolumeMaterial = v3;
    p_mVolumeUID = &this->mVolumes[0].mVolumeUID;
    v6 = 32i64;
    do
    {
      *p_mVolumeUID = -1;
      p_mVolumeUID += 68;
      --v6;
    }
    while ( v6 );
    Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
    {
      v8 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mStateBlockGlobal, 0x4D04C7F2u, 0xFA64CB1u, Inventory);
    v9 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
    {
      v10 = UFG::qResourceWarehouse::Instance();
      v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v9;
    }
    UFG::qResourceHandle::Init(&this->mStateBlockAlt, 0x4D04C7F2u, 0xA6F3AB7u, v9);
    mAltStateValues = this->mAltStateValues;
    v12 = 6i64;
    do
    {
      *(mAltStateValues - 6) = 1.0;
      *mAltStateValues++ = 1.0;
      --v12;
    }
    while ( v12 );
    sIsStaticInit_4 = 1;
  }
}

// File Line: 148
// RVA: 0x70990
void __fastcall UFG::AltColorPostEffect::Update(UFG::AltColorPostEffect *this, float fDeltaT)
{
  UFG::qResourceData *mData; // rbx
  UFG::qResourceData *v3; // rdi
  float v5; // xmm4_4
  __int64 i; // r10
  char *v7; // r9
  int v8; // r8d
  float *v9; // rdx
  __int64 v10; // r8
  float *v11; // rax
  float v12; // xmm3_4
  unsigned int v13; // ecx
  __int64 j; // r10
  char *v15; // r9
  int v16; // r8d
  float *v17; // rdx
  __int64 v18; // r8
  float *v19; // rax
  float v20; // xmm3_4
  unsigned int v21; // ecx

  mData = this->mStateBlockGlobal.mData;
  v3 = this->mStateBlockAlt.mData;
  v5 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight * 0.000011574074;
  if ( mData )
  {
    for ( i = 0i64; (unsigned int)i < mData[1].mNode.mUID; i = (unsigned int)(i + 1) )
    {
      v7 = (char *)mData
         + *(unsigned __int16 *)((char *)&mData[1].mResourceHandles.mNode.mNext
                               + 4 * i
                               + ((HIDWORD(mData[1].mNode.mChild[1]) + 15) & 0xFFFFFFF0));
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
      this->mGlobalStateValues[i] = v12;
    }
  }
  if ( v3 )
  {
    for ( j = 0i64; (unsigned int)j < v3[1].mNode.mUID; j = (unsigned int)(j + 1) )
    {
      v15 = (char *)v3
          + *(unsigned __int16 *)((char *)&v3[1].mResourceHandles.mNode.mNext
                                + 4 * j
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
      this->mAltStateValues[j] = v20;
    }
  }
}

// File Line: 179
// RVA: 0x70060
void __fastcall UFG::AltColorPostEffect::RenderFinalPass(
        UFG::AltColorPostEffect *this,
        UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *serialization_list,
        Render::vDynamic *render_context,
        float delta_time,
        Illusion::Target **curr_target,
        Illusion::Target **scratch_target)
{
  UFG::RenderContext *mVertices; // r13
  _WORD *v9; // rdi
  float v10; // r14d
  UFG::AltColorVolume *mVolumes; // rbx
  __int64 v12; // r15
  unsigned int mUID; // r8d
  Illusion::Material *mAltColorVolumeMaterial; // rbx
  __int64 mOffset; // rax
  _WORD *v16; // rax
  Illusion::StateArgs *StateArgs; // rbx
  Render::ViewSettings *mSettings; // r15
  UFG::qMatrix44 *p_mProjection; // rax
  unsigned __int16 Param; // ax
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
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v36; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  Render::ViewSettings *Identity; // rax
  Illusion::Material *mMaterial; // r15
  __int64 v42; // rax
  _WORD *v43; // rax
  Illusion::Target **v44; // r12
  unsigned int v45; // r8d
  __int64 v46; // rax
  _WORD *v47; // rax
  unsigned int v48; // r8d
  __int64 v49; // rax
  float *v50; // rax
  float *v51; // rbx
  Illusion::StateValues *v52; // rax
  Illusion::Target *v53; // rcx
  Illusion::Target **v54; // rdx
  float distance_from_near_plane; // [rsp+50h] [rbp-B0h] BYREF
  Render::cbExternalViewTransformState arg; // [rsp+58h] [rbp-A8h] BYREF
  Render::cbShadowTransformState v57; // [rsp+90h] [rbp-70h] BYREF
  UFG::qVector3 scale; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qVector3 v59; // [rsp+FCh] [rbp-4h] BYREF
  __int64 v60; // [rsp+108h] [rbp+8h]
  __int128 v61[8]; // [rsp+110h] [rbp+10h] BYREF
  UFG::qMatrix44 dest; // [rsp+190h] [rbp+90h] BYREF
  UFG::qMatrix44 v63; // [rsp+1D0h] [rbp+D0h] BYREF
  Render::View v64; // [rsp+210h] [rbp+110h] BYREF
  RenderQueueLayer v65; // [rsp+3A0h] [rbp+2A0h] BYREF
  Render::View v66; // [rsp+480h] [rbp+380h] BYREF
  __int64 v67[32]; // [rsp+610h] [rbp+510h] BYREF
  Render::View v68; // [rsp+710h] [rbp+610h] BYREF
  LayerSubmitContext ptr; // [rsp+8A0h] [rbp+7A0h] BYREF
  Render::Poly poly; // [rsp+1560h] [rbp+1460h] BYREF

  poly.mVertices = render_context;
  v60 = -2i64;
  mVertices = (UFG::RenderContext *)render_context;
  if ( LOBYTE(render_context[17].mColour) && this->mIsEnabled )
  {
    RenderQueueLayer::RenderQueueLayer(&v65);
    LayerSubmitContext::LayerSubmitContext(&ptr);
    v65.mSerializationList = serialization_list;
    ptr.mRenderQueueProvider = &v65;
    v9 = 0i64;
    ptr.mQueueMode = QM_Single;
    v10 = 0.0;
    if ( !this->mEnableGlobally )
    {
      Render::View::View(&v68, &mVertices->mMainViewSettings, &ptr);
      mVolumes = this->mVolumes;
      v12 = 32i64;
      do
      {
        if ( mVolumes->mVolumeUID != -1
          && Render::View::IsInView(&v68, &gDeferredCube, &mVolumes->mTransform, &distance_from_near_plane) )
        {
          v67[LODWORD(v10)] = (__int64)mVolumes;
          ++LODWORD(v10);
        }
        ++mVolumes;
        --v12;
      }
      while ( v12 );
      distance_from_near_plane = v10;
      if ( v10 != 0.0 )
      {
        mUID = mVertices->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
        mAltColorVolumeMaterial = this->mAltColorVolumeMaterial;
        if ( LODWORD(mAltColorVolumeMaterial[1].mStateBlockMask.mFlags[0]) != mUID )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mAltColorVolumeMaterial[1].mDebugName[20],
            mAltColorVolumeMaterial[1].mStateBlockMask.mFlags[1],
            mUID);
          mOffset = mAltColorVolumeMaterial->mMaterialUser.mOffset;
          if ( mOffset )
            v16 = (_WORD *)((char *)&mAltColorVolumeMaterial->mMaterialUser + mOffset);
          else
            v16 = 0i64;
          *v16 |= 0x20u;
        }
        Render::View::View(&v64, &mVertices->mMainViewSettings, &ptr);
        Render::View::BeginTarget(&v64, *scratch_target, "Outline", 0, 0, 0i64, 1, 0, 0, 0);
        Render::View::Clear(&v64, &UFG::qColour::Black, 1u, 1.0, 1u);
        StateArgs = Render::View::GetStateArgs(&v64);
        mSettings = v64.mSettings;
        p_mProjection = &v64.mSettings->mProjection;
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
          p_mProjection = &mSettings->mProjection;
        }
        arg.mWorldView = &mSettings->mWorldView;
        arg.mProjection = p_mProjection;
        arg.mCached_Remote.m_Stream = 0i64;
        Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(StateArgs, &arg);
        v21 = v67;
        v22 = LODWORD(v10);
        do
        {
          v23 = (_OWORD *)*v21;
          v24 = *(_OWORD *)(*v21 + 80);
          v25 = *(_OWORD *)(*v21 + 96);
          v26 = *(_OWORD *)(*v21 + 112);
          v61[0] = *(_OWORD *)(*v21 + 64);
          v61[1] = v24;
          v61[2] = v25;
          v61[3] = v26;
          v27 = v23[13];
          v28 = v23[14];
          v29 = v23[15];
          v61[4] = v23[12];
          v61[5] = v27;
          v61[6] = v28;
          v61[7] = v29;
          scale.x = 1.0;
          scale.y = -1.0;
          scale.z = 0.5;
          UFG::qScaleMatrix(&dest, &scale);
          dest.v3.z = 0.5;
          v59.x = 2.0;
          v59.y = -2.0;
          v59.z = 1.0;
          UFG::qScaleMatrix(&v63, &v59);
          v63.v3.x = -0.5;
          v63.v3.y = -0.5;
          v57.mPrev = &v57;
          v57.mNext = &v57;
          v57.mCallback = 0i64;
          v57.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
          *(_WORD *)&v57.mFlags = 1;
          if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
          {
            v30 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
            Render::cbShadowTransformState::sStateParamIndex = v30;
            v57.mStateParamIndex = v30;
          }
          v57.mViewWorld = &v64.mViewWorld;
          v57.mWorldView = (UFG::qMatrix44 *)v61;
          v57.mProjection = &dest;
          memset(&v57.mCutplanes, 0, 32);
          Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v57);
          StateValues = Render::View::GetStateValues(&v64);
          Render::cbShadowTransformState::SetStateBlock(&v57, StateValues);
          Render::View::Draw(&v64, &gDeferredCube, (UFG::qMatrix44 *)*v21, 0, this->mAltColorVolumeMaterial);
          mPrev = v57.mPrev;
          mNext = v57.mNext;
          v57.mPrev->mNext = v57.mNext;
          mNext->mPrev = mPrev;
          v57.mPrev = &v57;
          v57.mNext = &v57;
          v57.mIsSet = 0;
          if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v57.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v57.mStateParamIndex] )
            StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v57.mStateParamIndex >> 6] &= ~(1i64 << (v57.mStateParamIndex & 0x3F));
          v34 = v57.mPrev;
          v35 = v57.mNext;
          v57.mPrev->mNext = v57.mNext;
          v35->mPrev = v34;
          v57.mPrev = &v57;
          v57.mNext = &v57;
          ++v21;
          --v22;
        }
        while ( v22 );
        v10 = distance_from_near_plane;
        mVertices = (UFG::RenderContext *)poly.mVertices;
        v36 = arg.mPrev;
        v37 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v37->mPrev = v36;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
          StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v38 = arg.mPrev;
        v39 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v39->mPrev = v38;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        Render::View::EndTarget(&v64);
        Render::gRenderUtilities.mSubmitContext = &ptr;
        Render::RenderUtilities::GaussBlur3x3(
          &Render::gRenderUtilities,
          *scratch_target,
          mVertices->mHalfSizeScratchTargetB,
          0,
          0i64,
          kGaussBlur3x3UID_17);
      }
    }
    Identity = Render::ViewSettings::GetIdentity();
    Render::View::View(&v66, Identity, &ptr);
    Render::View::BeginTarget(&v66, *scratch_target, "ApplyColorEffects", 0, 0, 0i64, 1, 0, 0, 0);
    mMaterial = Render::gRenderUtilities.mMaterial;
    if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != 293922946 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
        Render::gRenderUtilities.mMaterial[1].mTypeUID,
        0x1184E882u);
      v42 = mMaterial->mMaterialUser.mOffset;
      if ( v42 )
        v43 = (_WORD *)((char *)&mMaterial->mMaterialUser + v42);
      else
        v43 = 0i64;
      *v43 |= 0x20u;
    }
    v44 = curr_target;
    v45 = (*curr_target)->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(mMaterial[1].mStateBlockMask.mFlags[0]) != v45 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[1].mDebugName[20],
        mMaterial[1].mStateBlockMask.mFlags[1],
        v45);
      v46 = mMaterial->mMaterialUser.mOffset;
      if ( v46 )
        v47 = (_WORD *)((char *)&mMaterial->mMaterialUser + v46);
      else
        v47 = 0i64;
      *v47 |= 0x20u;
    }
    if ( v10 == 0.0 )
    {
      v48 = 840494775;
      if ( this->mEnableGlobally )
        v48 = -1324127765;
    }
    else
    {
      v48 = mVertices->mHalfSizeScratchTargetB->mTargetTexture[0]->mNode.mUID;
    }
    if ( *(_DWORD *)&mMaterial[3].mDebugName[12] != v48 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
        *(_DWORD *)&mMaterial[3].mDebugName[20],
        v48);
      v49 = mMaterial->mMaterialUser.mOffset;
      if ( v49 )
        v9 = (_WORD *)((char *)&mMaterial->mMaterialUser + v49);
      *v9 |= 0x20u;
    }
    v50 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v51 = v50;
    if ( mVertices->mRenderFeatures.mPostFX )
    {
      *v50 = this->mGlobalStateValues[0];
      v50[1] = this->mGlobalStateValues[1];
      v50[2] = this->mGlobalStateValues[2];
      v50[3] = this->mGlobalStateValues[3];
      v50[4] = this->mGlobalStateValues[4];
      v50[5] = this->mGlobalStateValues[5];
      v50[8] = this->mAltStateValues[0];
      v50[9] = this->mAltStateValues[1];
      v50[10] = this->mAltStateValues[2];
      v50[11] = this->mAltStateValues[3];
      v50[12] = this->mAltStateValues[4];
      v50[13] = this->mAltStateValues[5];
    }
    else
    {
      *v50 = 1.0;
      v50[1] = 1.0;
      v50[2] = 1.0;
      v50[3] = 1.0;
      v50[4] = 1.0;
      v50[5] = 1.0;
      v50[8] = 1.0;
      v50[9] = 1.0;
      v50[10] = 1.0;
      v50[11] = 1.0;
      v50[12] = 1.0;
      v50[13] = 1.0;
    }
    v52 = Render::View::GetStateValues(&v66);
    v52->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v52->mParamValues[15] = v51;
    Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
    Render::View::Draw(&v66, &poly, mMaterial, 0i64);
    Render::View::EndTarget(&v66);
    v53 = *v44;
    v54 = scratch_target;
    *v44 = *scratch_target;
    *v54 = v53;
    poly.mVertices = (Render::vDynamic *)&ptr.mStateArgs;
    `eh vector destructor iterator(
      ptr.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
    RenderQueueLayer::~RenderQueueLayer(&v65);
  }
}

// File Line: 325
// RVA: 0x6FF00
void __fastcall UFG::CreateAltColorPlugin(UFG *this)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v2; // rax
  UFG::SimObjectModifier v3; // [rsp+38h] [rbp-30h] BYREF

  UFG::SimObjectModifier::SimObjectModifier(&v3, UFG::RenderWorld::msRenderStagePlugin, 1);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v2 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x22D0ui64, "AltColorPostEffect", 0i64, 1u);
  if ( v2 )
    UFG::AltColorPostEffect::AltColorPostEffect((UFG::AltColorPostEffect *)v2);
  UFG::SimObjectModifier::AttachComponent(&v3, (UFG::SimComponent *)v2, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v3);
  UFG::SimObjectModifier::~SimObjectModifier(&v3);
}

// File Line: 330
// RVA: 0x6FC30
void __fastcall UFG::AddAltColorEffect(
        unsigned int uid,
        UFG::qMatrix44 *mtx,
        UFG::qVector3 *box_min,
        UFG::qVector3 *box_max)
{
  UFG::SimComponent *ComponentOfType; // r10
  unsigned int v9; // r8d
  unsigned int *p_m_NameUID; // rdx
  unsigned int v11; // ecx
  __int64 v12; // rdi
  float v13; // xmm14_4
  float v14; // xmm1_4
  float v15; // xmm11_4
  float v16; // xmm12_4
  float v17; // xmm13_4
  float v18; // xmm10_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm12_4
  float v26; // xmm13_4
  UFG::qVector4 v27; // xmm3
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  UFG::qVector3 scale; // [rsp+20h] [rbp-A8h] BYREF

  Render::GetRenderCallbacks();
  if ( UFG::RenderWorld::msRenderStagePlugin )
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::AltColorPostEffect::_TypeUID);
  else
    ComponentOfType = 0i64;
  v9 = -1;
  p_m_NameUID = &ComponentOfType[5].m_NameUID;
  v11 = 0;
  while ( *p_m_NameUID != -1 )
  {
    ++v11;
    p_m_NameUID += 68;
    if ( v11 >= 0x20 )
      goto LABEL_9;
  }
  v9 = v11;
LABEL_9:
  v12 = (__int64)(&ComponentOfType[1].m_SafePointerList.mNode.mNext + 34 * v9);
  v13 = (float)(box_max->x - box_min->x) * 0.5;
  v14 = v13 + box_min->x;
  v15 = mtx->v0.x * v14;
  v16 = mtx->v0.y * v14;
  v17 = mtx->v0.z * v14;
  v18 = (float)(box_max->y - box_min->y) * 0.5;
  v19 = v18 + box_min->y;
  v20 = mtx->v1.x * v19;
  v21 = mtx->v1.y * v19;
  v22 = mtx->v1.z * v19;
  v23 = (float)(box_max->z - box_min->z) * 0.5;
  v24 = v23 + box_min->z;
  v25 = (float)((float)(v16 + mtx->v3.y) + v21) + (float)(mtx->v2.y * v24);
  v26 = (float)((float)(v17 + mtx->v3.z) + v22) + (float)(mtx->v2.z * v24);
  *(float *)(v12 + 256) = (float)((float)(v15 + mtx->v3.x) + v20) + (float)(mtx->v2.x * v24);
  *(float *)(v12 + 260) = v25;
  *(float *)(v12 + 264) = v26;
  v27 = mtx->v1;
  v28 = mtx->v2;
  v29 = mtx->v3;
  *(UFG::qVector4 *)(v12 + 128) = mtx->v0;
  *(UFG::qVector4 *)(v12 + 144) = v27;
  *(UFG::qVector4 *)(v12 + 160) = v28;
  *(UFG::qVector4 *)(v12 + 176) = v29;
  *(_QWORD *)(v12 + 176) = 0i64;
  *(_DWORD *)(v12 + 184) = 0;
  *(_DWORD *)(v12 + 188) = 1065353216;
  UFG::qInverseAffine((UFG::qMatrix44 *)(v12 + 192), (UFG::qMatrix44 *)(v12 + 128));
  scale.x = v13;
  scale.y = v18;
  scale.z = v23 * 1.01;
  UFG::qScaleMatrix((UFG::qMatrix44 *)v12, &scale);
  UFG::qMatrix44::operator*=((UFG::qMatrix44 *)v12, (UFG::qMatrix44 *)(v12 + 128));
  v29.x = *(float *)(v12 + 260);
  v28.x = *(float *)(v12 + 264);
  *(_DWORD *)(v12 + 48) = *(_DWORD *)(v12 + 256);
  *(float *)(v12 + 52) = v29.x;
  *(float *)(v12 + 56) = v28.x;
  *(_DWORD *)(v12 + 60) = 1065353216;
  UFG::qInverse((UFG::qMatrix44 *)(v12 + 64), (UFG::qMatrix44 *)v12);
  *(_DWORD *)(v12 + 268) = uid;
}

// File Line: 380
// RVA: 0x70000
void __fastcall UFG::RemoveAltColorEffect(unsigned int uid)
{
  UFG::SimComponent *ComponentOfType; // rax
  _DWORD *v3; // rax
  __int64 v4; // rcx

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::AltColorPostEffect::_TypeUID);
    if ( ComponentOfType )
    {
      v3 = (_DWORD *)&ComponentOfType[9].m_pSimObject + 1;
      v4 = 16i64;
      do
      {
        if ( *(v3 - 68) == uid )
          *(v3 - 68) = -1;
        if ( *v3 == uid )
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
  UFG::SimComponent *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::AltColorPostEffect::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[139].m_SafePointerList.mNode.mPrev) = bEnable;
  }
}

// File Line: 405
// RVA: 0x6FF90
void __fastcall UFG::EnableAltColorEffect(bool enable)
{
  UFG::SimComponent *ComponentOfType; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::AltColorPostEffect::_TypeUID);
    if ( ComponentOfType )
      BYTE1(ComponentOfType[139].m_SafePointerList.mNode.mPrev) = enable;
  }
}

// File Line: 414
// RVA: 0x708D0
void __fastcall UFG::SetGlobalEffectUID(unsigned int uid)
{
  UFG::SimComponent *ComponentOfType; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax

  if ( UFG::RenderWorld::msRenderStagePlugin )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        UFG::RenderWorld::msRenderStagePlugin,
                        UFG::AltColorPostEffect::_TypeUID);
    if ( ComponentOfType )
    {
      Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
      {
        v4 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x4D04C7F2u);
        `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&ComponentOfType[137].m_TypeUID, 0x4D04C7F2u, uid, Inventory);
      v5 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
      {
        v6 = UFG::qResourceWarehouse::Instance();
        v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x4D04C7F2u);
        `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v5;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&ComponentOfType[137].m_BoundComponentHandles.mNode.mNext,
        0x4D04C7F2u,
        uid,
        v5);
    }
  }
}

