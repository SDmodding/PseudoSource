// File Line: 20
// RVA: 0x14BFF60
__int64 dynamic_initializer_for__UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList__);
}

// File Line: 21
// RVA: 0x3C3F10
__int64 __fastcall UFG::ProgressionCameraComponent::GetTypeSize(UFG::ProgressionCameraComponent *this)
{
  return 1568i64;
}

// File Line: 22
// RVA: 0x14BFEA0
void dynamic_initializer_for__UFG::ProgressionCameraComponent::mMarkerTransform__()
{
  UFG::ProgressionCameraComponent::mMarkerTransform = UFG::qMatrix44::msIdentity;
}

// File Line: 37
// RVA: 0x3BCF70
void __fastcall UFG::ProgressionCameraComponent::ProgressionCameraComponent(
        UFG::ProgressionCameraComponent *this,
        unsigned int nameUID)
{
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *mPrev; // rax
  float rParamDuration; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  UFG::GameCameraComponent::GameCameraComponent(this, nameUID);
  this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>::mPrev = &this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>;
  this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>::mNext = &this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionCameraComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTransformNode);
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0>::RebindingComponentHandle<UFG::CameraAnimationComponent,0>(&this->mAnimation);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTarget);
  this->bSnapProgress = 0;
  this->bParamMonotonicallyIncreasing = UFG::ProgressionCameraComponent::tbParamMonotonicallyIncreasing;
  this->rParamWindowSize = UFG::ProgressionCameraComponent::trParamWindowSize;
  this->rParamDuration = UFG::ProgressionCameraComponent::trParamDuration;
  this->mParamProgress.mDuration = 0.0099999998;
  Render::DepthOfField::Focus::Focus(&this->mDofParameters);
  this->mAnimationNode.mPrev = &this->mAnimationNode;
  this->mAnimationNode.mNext = &this->mAnimationNode;
  this->mAnimationNode.m_pPointer = 0i64;
  mPrev = UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList.mNode.mPrev;
  UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>;
  this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>::mNext = (UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *)&UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList;
  UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID,
    "ProgressionCameraComponent");
  rParamDuration = this->rParamDuration;
  if ( rParamDuration <= 0.0099999998 )
    rParamDuration = FLOAT_0_0099999998;
  this->mParamProgress.mDuration = rParamDuration;
  this->mParamProgress.mParameter = 0.0;
  *(_QWORD *)&this->mParamProgress.v0 = 0i64;
  *(_QWORD *)&this->mParamProgress.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mParamProgress);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->vProgressMarkerA.x = UFG::qVector3::msZero.x;
  this->vProgressMarkerA.y = y;
  this->vProgressMarkerA.z = z;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->vProgressMarkerB.x = UFG::qVector3::msZero.x;
  this->vProgressMarkerB.y = v7;
  this->vProgressMarkerB.z = v8;
  this->mFov = 55.0;
  *(_QWORD *)&this->nEyeBone = -1i64;
  this->nParamsBone = -1;
  *(_WORD *)&this->bTargetSpace = 0;
  this->bSingleBone = 0;
  this->mMotionblurMagnitude = 0.15000001;
  this->mDofParameters.mFocalDistance = 5.0;
  this->mDofParameters.mInFocusRange = 100.0;
  *(_QWORD *)&this->mDofParameters.mNearRange = 1084227584i64;
  *(_QWORD *)&this->mDofParameters.mFarRange = 1084227584i64;
  ++UFG::ProgressionCameraComponent::nNumCinematicCameraInstances;
}

// File Line: 76
// RVA: 0x3BE000
void __fastcall UFG::ProgressionCameraComponent::~ProgressionCameraComponent(UFG::ProgressionCameraComponent *this)
{
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v2; // rdi
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *mNext; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mAnimationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v10; // rcx
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionCameraComponent::`vftable;
  --UFG::ProgressionCameraComponent::nNumCinematicCameraInstances;
  if ( this == UFG::ProgressionCameraComponent::s_ProgressionCameraComponentpCurrentIterator )
    UFG::ProgressionCameraComponent::s_ProgressionCameraComponentpCurrentIterator = (UFG::ProgressionCameraComponent *)&this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>::mPrev[-78];
  v2 = &this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>;
  mPrev = this->UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mAnimationNode = &this->mAnimationNode;
  if ( this->mAnimationNode.m_pPointer )
  {
    v6 = p_mAnimationNode->mPrev;
    v7 = this->mAnimationNode.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mAnimationNode->mPrev = p_mAnimationNode;
    this->mAnimationNode.mNext = &this->mAnimationNode;
  }
  this->mAnimationNode.m_pPointer = 0i64;
  v8 = p_mAnimationNode->mPrev;
  v9 = this->mAnimationNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mAnimationNode->mPrev = p_mAnimationNode;
  this->mAnimationNode.mNext = &this->mAnimationNode;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mTarget);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAnimation);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mTransformNode);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GameCameraComponent::~GameCameraComponent(this);
}

// File Line: 98
// RVA: 0x3C8280
UFG::ProgressionCameraComponent *__fastcall UFG::ProgressionCameraComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObjectProperties)
{
  unsigned int m_NameUID; // ebx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  m_NameUID = sceneObjectProperties->m_NameUID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x620ui64, "ProgressionCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::ProgressionCameraComponent::ProgressionCameraComponent((UFG::ProgressionCameraComponent *)v4, m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, sceneObjectProperties->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::ProgressionCameraComponent *)v6;
}

// File Line: 145
// RVA: 0x3D6A60
void __fastcall UFG::ProgressionCameraComponent::Update(UFG::ProgressionCameraComponent *this, float dt)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  bool v8; // r15
  bool v9; // r12
  bool v10; // r13
  float rParamDuration; // xmm1_4
  float v12; // xmm0_4
  float *v13; // rax
  float x; // xmm2_4
  float y; // xmm1_4
  float v16; // xmm4_4
  float z; // xmm0_4
  float v18; // xmm3_4
  float rParamWindowSize; // xmm1_4
  float v20; // xmm3_4
  float p1; // xmm6_4
  bool bParamMonotonicallyIncreasing; // al
  float v23; // xmm1_4
  double v24; // xmm0_8
  float v25; // xmm9_4
  float v26; // xmm8_4
  Render::DebugDrawContext *Context; // rbx
  Creature *v28; // rbx
  int v29; // esi
  int BoneID; // eax
  int v31; // eax
  int nEyeBone; // edx
  __m128 v33; // xmm2
  int nLookBone; // edx
  UFG::qVector4 v35; // xmm2
  int nParamsBone; // edx
  UFG::qVector4 v37; // xmm2
  UFG::qMatrix44 *v38; // rdx
  UFG::qMatrix44 *v39; // rax
  float v40; // xmm6_4
  float v41; // xmm11_4
  float v42; // xmm10_4
  hkQsTransformf *v43; // rdx
  float v44; // xmm8_4
  float v45; // xmm9_4
  float v46; // xmm2_4
  float ExtraWideAspectCorrectedFOV; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  float v49; // xmm0_4
  UFG::qVector3 desEye; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 desLook; // [rsp+4Ch] [rbp-8Ch] BYREF
  __m128 v52; // [rsp+58h] [rbp-80h] BYREF
  __m256i v53; // [rsp+68h] [rbp-70h] BYREF
  UFG::qMatrix44 transform_24; // [rsp+88h] [rbp-50h] BYREF
  hkQuaternionf v55; // [rsp+D8h] [rbp+0h]
  hkVector4f v56; // [rsp+E8h] [rbp+10h]
  __int64 v57; // [rsp+F8h] [rbp+20h]
  UFG::qMatrix44 matrixLS; // [rsp+108h] [rbp+30h] BYREF

  v57 = -2i64;
  if ( UFG::gFlowController.mCurrentState
    && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
    || !this->mActive
    || !this->mAnimation.m_pSimComponent
    || !this->mAnimationNode.m_pPointer )
  {
    return;
  }
  v4 = _S5_8;
  if ( (_S5_8 & 1) == 0 )
  {
    _S5_8 |= 1u;
    v5 = UFG::qStringHashUpper32("CameraProxy", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCameraProxy, v5);
    atexit(UFG::ProgressionCameraComponent::Update_::_6_::_dynamic_atexit_destructor_for__symCameraProxy__);
    v4 = _S5_8;
  }
  if ( (v4 & 2) == 0 )
  {
    _S5_8 = v4 | 2;
    v6 = UFG::qStringHashUpper32("CameraTargetProxy", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCameraTargetProxy, v6);
    atexit(UFG::ProgressionCameraComponent::Update_::_6_::_dynamic_atexit_destructor_for__symCameraTargetProxy__);
    v4 = _S5_8;
  }
  if ( (v4 & 4) == 0 )
  {
    _S5_8 = v4 | 4;
    v7 = UFG::qStringHashUpper32("CameraParamsProxy", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCameraParamsProxy, v7);
    atexit(UFG::ProgressionCameraComponent::Update_::_6_::_dynamic_atexit_destructor_for__symCameraParamsProxy__);
  }
  UFG::GameCameraComponent::Update(this, dt);
  v8 = this->nEyeBone == -1;
  v9 = this->nLookBone == -1;
  v10 = this->nParamsBone == -1;
  if ( UFG::ProgressionCameraComponent::tbUseTweakables )
    rParamDuration = UFG::ProgressionCameraComponent::trParamDuration;
  else
    rParamDuration = this->rParamDuration;
  v12 = this->mParamProgress.mParameter / this->mParamProgress.mDuration;
  this->mParamProgress.mParameter = v12;
  if ( rParamDuration <= 0.0099999998 )
    rParamDuration = FLOAT_0_0099999998;
  this->mParamProgress.mDuration = rParamDuration;
  this->mParamProgress.mParameter = rParamDuration * v12;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mParamProgress);
  v13 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
  y = this->vProgressMarkerA.y;
  v16 = this->vProgressMarkerB.y - y;
  v18 = v13[1] - y;
  if ( UFG::ProgressionCameraComponent::tbUseTweakables )
    rParamWindowSize = UFG::ProgressionCameraComponent::trParamWindowSize;
  else
    rParamWindowSize = this->rParamWindowSize;
  z = this->vProgressMarkerA.z;
  x = this->vProgressMarkerA.x;
  v20 = (float)((float)((float)(v18 * v16) + (float)((float)(this->vProgressMarkerB.x - x) * (float)(*v13 - x)))
              + (float)((float)(v13[2] - z) * (float)(this->vProgressMarkerB.z - z)))
      / (float)((float)((float)(v16 * v16)
                      + (float)((float)(this->vProgressMarkerB.x - x) * (float)(this->vProgressMarkerB.x - x)))
              + (float)((float)(this->vProgressMarkerB.z - z) * (float)(this->vProgressMarkerB.z - z)));
  p1 = this->mParamProgress.p1;
  bParamMonotonicallyIncreasing = UFG::ProgressionCameraComponent::tbParamMonotonicallyIncreasing;
  if ( !UFG::ProgressionCameraComponent::tbUseTweakables )
    bParamMonotonicallyIncreasing = this->bParamMonotonicallyIncreasing;
  if ( !bParamMonotonicallyIncreasing && v20 < (float)(p1 - (float)(rParamWindowSize * 0.5)) )
    p1 = (float)(rParamWindowSize * 0.5) + v20;
  v23 = rParamWindowSize * 0.5;
  if ( v20 > (float)(v23 + p1) )
    p1 = v20 - v23;
  this->mParamProgress.p1 = p1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mParamProgress);
  this->mParamProgress.mParameter = 0.0;
  UFG::HomerCubic<float>::Update(&this->mParamProgress, dt);
  if ( this->bSnapProgress )
  {
    this->mParamProgress.p0 = this->mParamProgress.p1;
    this->mParamProgress.v0 = this->mParamProgress.v1;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mParamProgress);
    this->mParamProgress.mParameter = 0.0;
    this->bSnapProgress = 0;
  }
  v24 = ((double (__fastcall *)(AnimationNode *))this->mAnimationNode.m_pPointer->vfptr[2].SetResourceOwner)(this->mAnimationNode.m_pPointer);
  v25 = *(float *)&v24 - 0.033333335;
  v26 = (float)(*(float *)&v24 - 0.033333335) * this->mParamProgress.p0;
  if ( v26 <= 0.0 )
    v26 = 0.0;
  if ( v26 >= v25 )
    v26 = *(float *)&v24 - 0.033333335;
  ((void (__fastcall *)(AnimationNode *))this->mAnimationNode.m_pPointer->vfptr[3].GetResourcePath)(this->mAnimationNode.m_pPointer);
  if ( UFG::bCameraDebugText )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawTextA(
      Context,
      40,
      200,
      &UFG::qColour::White,
      "ProgressParam       :%f",
      this->mParamProgress.p0);
    Render::DebugDrawContext::DrawTextA(Context, 40, 212, &UFG::qColour::White, "ProgressParamDesired:%f", p1);
    Render::DebugDrawContext::DrawTextA(Context, 40, 224, &UFG::qColour::White, "AnimTime            :%f", v26);
    Render::DebugDrawContext::DrawTextA(Context, 40, 236, &UFG::qColour::White, "AnimTimeTotal       :%f", v25);
  }
  if ( this->mAnimation.m_Changed )
  {
    this->mAnimation.m_Changed = 0;
    v10 = 1;
    v9 = 1;
    v8 = 1;
  }
  v28 = *(Creature **)&this->mAnimation.m_pSimComponent[2].m_TypeUID;
  v29 = -1;
  if ( v8 )
  {
    if ( v28->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, symCameraProxy.mUID);
    else
      BoneID = -1;
    this->nEyeBone = BoneID;
  }
  if ( v9 )
  {
    if ( v28->mPose.mRigHandle.mData )
      v31 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, symCameraTargetProxy.mUID);
    else
      v31 = -1;
    this->nLookBone = v31;
  }
  if ( v10 )
  {
    if ( v28->mPose.mRigHandle.mData )
      v29 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, symCameraParamsProxy.mUID);
    this->nParamsBone = v29;
  }
  nEyeBone = this->nEyeBone;
  if ( nEyeBone == -1 )
  {
    v33 = 0i64;
    v33.m128_f32[0] = (float)1;
    v52 = _mm_shuffle_ps(v33, v33, 81);
    *(__m128 *)v53.m256i_i8 = _mm_shuffle_ps(v33, v33, 69);
    *(__m128 *)&v53.m256i_u64[2] = _mm_shuffle_ps(v33, v33, 21);
  }
  else
  {
    Creature::GetTransform(v28, nEyeBone, (UFG::qMatrix44 *)&v53.m256i_u64[1]);
  }
  nLookBone = this->nLookBone;
  if ( nLookBone == -1 )
  {
    v35 = 0i64;
    v35.x = (float)1;
    transform_24.v0 = v35;
    transform_24.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v35, (__m128)v35, 81);
    transform_24.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v35, (__m128)v35, 69);
    transform_24.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v35, (__m128)v35, 21);
  }
  else
  {
    Creature::GetTransform(v28, nLookBone, &transform_24);
  }
  nParamsBone = this->nParamsBone;
  if ( nParamsBone == -1 )
  {
    v37 = 0i64;
    v37.x = (float)1;
    matrixLS.v0 = v37;
    matrixLS.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v37, (__m128)v37, 81);
    matrixLS.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v37, (__m128)v37, 69);
    matrixLS.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v37, (__m128)v37, 21);
  }
  else
  {
    SkeletalPose::GetPositionLS(&v28->mPose, nParamsBone, &matrixLS);
  }
  if ( this->bSingleBone )
    transform_24.v3 = (UFG::qVector4)_mm_add_ps(*(__m128 *)&v53.m256i_u64[2], *(__m128 *)&v53.m256i_u64[1]);
  if ( this->bMarkerRelative )
  {
    UFG::qMatrix44::operator*=((UFG::qMatrix44 *)&v53.m256i_u64[1], &UFG::ProgressionCameraComponent::mMarkerTransform);
    v38 = &UFG::ProgressionCameraComponent::mMarkerTransform;
  }
  else
  {
    if ( !this->bTargetSpace || !this->mTarget.m_pSimComponent )
      goto LABEL_68;
    v39 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
    UFG::qMatrix44::operator*=((UFG::qMatrix44 *)&v53.m256i_u64[1], v39);
    v38 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
  }
  UFG::qMatrix44::operator*=(&transform_24, v38);
LABEL_68:
  desEye = *(UFG::qVector3 *)&v53.m256i_u64[2];
  *(_QWORD *)&desLook.x = *(_QWORD *)&transform_24.v3.x;
  desLook.z = transform_24.v3.z;
  UFG::GameCameraComponent::SetDesiredEyeLookUp(this, dt, &desEye, &desLook, (UFG::qVector3 *)&v52, 0, 0i64, 0i64);
  UFG::Camera::ApplyDutch(&this->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
  v40 = matrixLS.v3.x * 100.0;
  v41 = matrixLS.v3.y * 100.0;
  v42 = matrixLS.v3.z * 100.0;
  v43 = &hkaPose::getSyncedPoseLocalSpace(v28->mPose.mHavokPose)->m_data[this->nParamsBone];
  v55.m_vec.m_quad = (__m128)v43->m_rotation;
  v56.m_quad = (__m128)v43->m_scale;
  v44 = 0.0;
  v45 = 0.0;
  v46 = v43->m_rotation.m_vec.m_quad.m128_f32[3];
  if ( v46 > 0.0 )
  {
    LODWORD(v44) = COERCE_UNSIGNED_INT(v55.m_vec.m_quad.m128_f32[1] * (float)(1.0 / v46)) & _xmm;
    LODWORD(v45) = COERCE_UNSIGNED_INT(v55.m_vec.m_quad.m128_f32[2] * (float)(1.0 / v46)) & _xmm;
  }
  if ( v40 > 0.0 )
    this->mFov = v40;
  ExtraWideAspectCorrectedFOV = (float)(this->mFov * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    ExtraWideAspectCorrectedFOV = Render::GetExtraWideAspectCorrectedFOV(ExtraWideAspectCorrectedFOV);
  DisplayAspectRatio = Render::GetDisplayAspectRatio();
  UFG::Camera::SetViewProjection(
    &this->mCamera,
    ExtraWideAspectCorrectedFOV,
    DisplayAspectRatio,
    UFG::gCameraDefaultNear,
    UFG::gCameraDefaultFar,
    0.0,
    0.0,
    1);
  if ( v41 > 0.0 && v42 > 0.0 )
  {
    v49 = v56.m_quad.m128_f32[0];
    if ( v56.m_quad.m128_f32[0] > 0.0 && v56.m_quad.m128_f32[1] > 0.0 )
    {
      LODWORD(this->mDofParameters.mFocalDistance) = v56.m_quad.m128_i32[1];
      this->mDofParameters.mInFocusRange = v49;
      this->mDofParameters.mNearRange = v41;
      this->mDofParameters.mNearBlurRadius = v44;
      this->mDofParameters.mFarRange = v42;
      this->mDofParameters.mFarBlurRadius = v45;
    }
  }
  UFG::GameCameraComponent::UpdateDof(this, dt, &this->mDofParameters, 0);
}

// File Line: 323
// RVA: 0x3C7F30
AnimationNode *__fastcall UFG::ProgressionCameraComponent::Play(
        UFG::ProgressionCameraComponent *this,
        UFG::qSymbolUC *name,
        float start_time)
{
  UFG::BaseAnimationComponent *m_pSimComponent; // rcx
  AnimationNode *v5; // r8
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mAnimationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  AnimationNode *m_pPointer; // rcx
  AnimationNode *result; // rax

  m_pSimComponent = (UFG::BaseAnimationComponent *)this->mAnimation.m_pSimComponent;
  if ( m_pSimComponent )
    v5 = UFG::BaseAnimationComponent::PlayAnimation(m_pSimComponent, name, start_time);
  else
    v5 = 0i64;
  p_mAnimationNode = &this->mAnimationNode;
  if ( this->mAnimationNode.m_pPointer )
  {
    mPrev = p_mAnimationNode->mPrev;
    mNext = this->mAnimationNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAnimationNode->mPrev = p_mAnimationNode;
    this->mAnimationNode.mNext = &this->mAnimationNode;
  }
  this->mAnimationNode.m_pPointer = v5;
  if ( v5 )
  {
    v9 = v5->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev;
    v9->mNext = p_mAnimationNode;
    p_mAnimationNode->mPrev = v9;
    this->mAnimationNode.mNext = &v5->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode;
    v5->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev = p_mAnimationNode;
  }
  m_pPointer = this->mAnimationNode.m_pPointer;
  if ( m_pPointer )
  {
    ((void (__fastcall *)(AnimationNode *))m_pPointer->PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(m_pPointer);
    result = this->mAnimationNode.m_pPointer;
  }
  else
  {
    result = 0i64;
  }
  this->bSnapProgress = 1;
  return result;
}

