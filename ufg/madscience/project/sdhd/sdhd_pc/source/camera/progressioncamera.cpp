// File Line: 20
// RVA: 0x14BFF60
__int64 dynamic_initializer_for__UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList__);
}

// File Line: 21
// RVA: 0x3C3F10
signed __int64 __fastcall UFG::ProgressionCameraComponent::GetTypeSize(UFG::ProgressionCameraComponent *this)
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
void __fastcall UFG::ProgressionCameraComponent::ProgressionCameraComponent(UFG::ProgressionCameraComponent *this, unsigned int nameUID)
{
  UFG::ProgressionCameraComponent *v2; // rdi
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v3; // rbx
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::qSafePointer<AnimationNode,AnimationNode> *v10; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::GameCameraComponent::GameCameraComponent((UFG::GameCameraComponent *)&this->vfptr, nameUID);
  v3 = (UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionCameraComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->mTransformNode);
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0>::RebindingComponentHandle<UFG::CameraAnimationComponent,0>(&v2->mAnimation);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&v2->mTarget);
  v2->bSnapProgress = 0;
  v2->bParamMonotonicallyIncreasing = UFG::ProgressionCameraComponent::tbParamMonotonicallyIncreasing;
  v2->rParamWindowSize = UFG::ProgressionCameraComponent::trParamWindowSize;
  v2->rParamDuration = UFG::ProgressionCameraComponent::trParamDuration;
  v2->mParamProgress.mDuration = 0.0099999998;
  Render::DepthOfField::Focus::Focus(&v2->mDofParameters);
  v10 = &v2->mAnimationNode;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v2->mAnimationNode.m_pPointer = 0i64;
  v4 = UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList.mNode.mPrev;
  UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *)&UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList;
  UFG::ProgressionCameraComponent::s_ProgressionCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID,
    "ProgressionCameraComponent");
  v5 = v2->rParamDuration;
  if ( v5 <= 0.0099999998 )
    v5 = FLOAT_0_0099999998;
  v2->mParamProgress.mDuration = v5;
  v2->mParamProgress.mParameter = 0.0;
  *(_QWORD *)&v2->mParamProgress.v0 = 0i64;
  *(_QWORD *)&v2->mParamProgress.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mParamProgress);
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v2->vProgressMarkerA.x = UFG::qVector3::msZero.x;
  v2->vProgressMarkerA.y = v6;
  v2->vProgressMarkerA.z = v7;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v2->vProgressMarkerB.x = UFG::qVector3::msZero.x;
  v2->vProgressMarkerB.y = v8;
  v2->vProgressMarkerB.z = v9;
  v2->mFov = 55.0;
  *(_QWORD *)&v2->nEyeBone = -1i64;
  v2->nParamsBone = -1;
  *(_WORD *)&v2->bTargetSpace = 0;
  v2->bSingleBone = 0;
  v2->mMotionblurMagnitude = 0.15000001;
  v2->mDofParameters.mFocalDistance = 5.0;
  v2->mDofParameters.mInFocusRange = 100.0;
  *(_QWORD *)&v2->mDofParameters.mNearRange = 1084227584i64;
  *(_QWORD *)&v2->mDofParameters.mFarRange = 1084227584i64;
  ++UFG::ProgressionCameraComponent::nNumCinematicCameraInstances;
}

// File Line: 76
// RVA: 0x3BE000
void __fastcall UFG::ProgressionCameraComponent::~ProgressionCameraComponent(UFG::ProgressionCameraComponent *this)
{
  UFG::ProgressionCameraComponent *v1; // rbx
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v2; // rdi
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v3; // rcx
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v4; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v10; // rcx
  UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ProgressionCameraComponent::`vftable;
  --UFG::ProgressionCameraComponent::nNumCinematicCameraInstances;
  if ( this == UFG::ProgressionCameraComponent::s_ProgressionCameraComponentpCurrentIterator )
    UFG::ProgressionCameraComponent::s_ProgressionCameraComponentpCurrentIterator = (UFG::ProgressionCameraComponent *)&this->mPrev[-78];
  v2 = (UFG::qNode<UFG::ProgressionCameraComponent,UFG::ProgressionCameraComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mAnimationNode;
  if ( v1->mAnimationNode.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mAnimationNode.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mAnimationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mAnimationNode.mPrev;
  }
  v1->mAnimationNode.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mAnimationNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mAnimationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mAnimationNode.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mTarget);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAnimation);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mTransformNode);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GameCameraComponent::~GameCameraComponent((UFG::GameCameraComponent *)&v1->vfptr);
}

// File Line: 98
// RVA: 0x3C8280
UFG::SimComponent *__fastcall UFG::ProgressionCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObjectProperties)
{
  UFG::SceneObjectProperties *v1; // rdi
  unsigned int v2; // ebx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = sceneObjectProperties;
  v2 = sceneObjectProperties->m_NameUID;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x620ui64, "ProgressionCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::ProgressionCameraComponent::ProgressionCameraComponent((UFG::ProgressionCameraComponent *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 145
// RVA: 0x3D6A60
void __usercall UFG::ProgressionCameraComponent::Update(UFG::ProgressionCameraComponent *this@<rcx>, float dt@<xmm1>, float *a3@<r13>)
{
  float v3; // xmm12_4
  UFG::ProgressionCameraComponent *v4; // rdi
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  bool v9; // r15
  bool v10; // r12
  float v11; // xmm1_4
  float v12; // xmm0_4
  float *v13; // rax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  bool v22; // al
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm9_4
  float v26; // xmm8_4
  Render::DebugDrawContext *v27; // rbx
  Creature *v28; // rbx
  signed int v29; // esi
  signed int v30; // eax
  signed int v31; // eax
  int v32; // edx
  __m128 v33; // xmm2
  int v34; // edx
  __m128 v35; // xmm2
  int v36; // edx
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
  float v47; // xmm6_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  UFG::qVector3 desEye; // [rsp+40h] [rbp-98h]
  UFG::qVector3 desLook; // [rsp+4Ch] [rbp-8Ch]
  __m128 v52; // [rsp+58h] [rbp-80h]
  __m128 v53; // [rsp+68h] [rbp-70h]
  __m128 v54; // [rsp+78h] [rbp-60h]
  __m128 v55; // [rsp+88h] [rbp-50h]
  __m128 v56; // [rsp+98h] [rbp-40h]
  __m128 v57; // [rsp+A8h] [rbp-30h]
  __m128 v58; // [rsp+B8h] [rbp-20h]
  hkQuaternionf v59; // [rsp+D8h] [rbp+0h]
  hkVector4f v60; // [rsp+E8h] [rbp+10h]
  __int64 v61; // [rsp+F8h] [rbp+20h]
  UFG::qMatrix44 matrixLS; // [rsp+108h] [rbp+30h]

  v61 = -2i64;
  v3 = dt;
  v4 = this;
  if ( UFG::gFlowController.mCurrentState
    && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
    || !v4->mActive
    || !v4->mAnimation.m_pSimComponent
    || !v4->mAnimationNode.m_pPointer )
  {
    return;
  }
  v5 = _S5_8;
  if ( !(_S5_8 & 1) )
  {
    _S5_8 |= 1u;
    v6 = UFG::qStringHashUpper32("CameraProxy", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCameraProxy, v6);
    atexit(UFG::ProgressionCameraComponent::Update_::_6_::_dynamic_atexit_destructor_for__symCameraProxy__);
    v5 = _S5_8;
  }
  if ( !(v5 & 2) )
  {
    _S5_8 = v5 | 2;
    v7 = UFG::qStringHashUpper32("CameraTargetProxy", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCameraTargetProxy, v7);
    atexit(UFG::ProgressionCameraComponent::Update_::_6_::_dynamic_atexit_destructor_for__symCameraTargetProxy__);
    v5 = _S5_8;
  }
  if ( !(v5 & 4) )
  {
    _S5_8 = v5 | 4;
    v8 = UFG::qStringHashUpper32("CameraParamsProxy", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCameraParamsProxy, v8);
    atexit(UFG::ProgressionCameraComponent::Update_::_6_::_dynamic_atexit_destructor_for__symCameraParamsProxy__);
  }
  UFG::GameCameraComponent::Update((UFG::GameCameraComponent *)&v4->vfptr, dt);
  v9 = v4->nEyeBone == -1;
  v10 = v4->nLookBone == -1;
  LOBYTE(a3) = v4->nParamsBone == -1;
  if ( UFG::ProgressionCameraComponent::tbUseTweakables )
    v11 = UFG::ProgressionCameraComponent::trParamDuration;
  else
    v11 = v4->rParamDuration;
  v12 = v4->mParamProgress.mParameter / v4->mParamProgress.mDuration;
  v4->mParamProgress.mParameter = v12;
  if ( v11 <= 0.0099999998 )
    v11 = FLOAT_0_0099999998;
  v4->mParamProgress.mDuration = v11;
  v4->mParamProgress.mParameter = v11 * v12;
  UFG::HomerCubic<float>::MakeCoeffs(&v4->mParamProgress);
  v13 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
  v15 = v4->vProgressMarkerA.y;
  v16 = v4->vProgressMarkerB.y - v15;
  v18 = v13[1] - v15;
  if ( UFG::ProgressionCameraComponent::tbUseTweakables )
    v19 = UFG::ProgressionCameraComponent::trParamWindowSize;
  else
    v19 = v4->rParamWindowSize;
  v17 = v4->vProgressMarkerA.z;
  v14 = v4->vProgressMarkerA.x;
  v20 = (float)((float)((float)(v18 * v16) + (float)((float)(v4->vProgressMarkerB.x - v14) * (float)(*v13 - v14)))
              + (float)((float)(v13[2] - v17) * (float)(v4->vProgressMarkerB.z - v17)))
      / (float)((float)((float)(v16 * v16)
                      + (float)((float)(v4->vProgressMarkerB.x - v14) * (float)(v4->vProgressMarkerB.x - v14)))
              + (float)((float)(v4->vProgressMarkerB.z - v17) * (float)(v4->vProgressMarkerB.z - v17)));
  v21 = v4->mParamProgress.p1;
  v22 = UFG::ProgressionCameraComponent::tbParamMonotonicallyIncreasing;
  if ( !UFG::ProgressionCameraComponent::tbUseTweakables )
    v22 = v4->bParamMonotonicallyIncreasing;
  if ( !v22 && v20 < (float)(v21 - (float)(v19 * 0.5)) )
    v21 = (float)(v19 * 0.5) + v20;
  v23 = v19 * 0.5;
  v24 = v23 + v21;
  if ( v20 > (float)(v23 + v21) )
    v21 = v20 - v23;
  v4->mParamProgress.p1 = v21;
  UFG::HomerCubic<float>::MakeCoeffs(&v4->mParamProgress);
  v4->mParamProgress.mParameter = 0.0;
  UFG::HomerCubic<float>::Update(&v4->mParamProgress, v3);
  if ( v4->bSnapProgress )
  {
    v4->mParamProgress.p0 = v4->mParamProgress.p1;
    v4->mParamProgress.v0 = v4->mParamProgress.v1;
    UFG::HomerCubic<float>::MakeCoeffs(&v4->mParamProgress);
    v4->mParamProgress.mParameter = 0.0;
    v4->bSnapProgress = 0;
  }
  ((void (*)(void))v4->mAnimationNode.m_pPointer->vfptr[2].SetResourceOwner)();
  v25 = v24 - 0.033333335;
  v26 = (float)(v24 - 0.033333335) * v4->mParamProgress.p0;
  if ( v26 <= 0.0 )
    v26 = 0.0;
  if ( v26 >= v25 )
    v26 = v24 - 0.033333335;
  ((void (*)(void))v4->mAnimationNode.m_pPointer->vfptr[3].GetResourcePath)();
  if ( UFG::bCameraDebugText )
  {
    v27 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawTextA(
      v27,
      40,
      200,
      &UFG::qColour::White,
      "ProgressParam       :%f",
      v4->mParamProgress.p0);
    Render::DebugDrawContext::DrawTextA(v27, 40, 212, &UFG::qColour::White, "ProgressParamDesired:%f", v21);
    Render::DebugDrawContext::DrawTextA(v27, 40, 224, &UFG::qColour::White, "AnimTime            :%f", v26);
    Render::DebugDrawContext::DrawTextA(v27, 40, 236, &UFG::qColour::White, "AnimTimeTotal       :%f", v25);
  }
  if ( v4->mAnimation.m_Changed )
  {
    v4->mAnimation.m_Changed = 0;
    LOBYTE(a3) = 1;
    v10 = 1;
    v9 = 1;
  }
  v28 = *(Creature **)&v4->mAnimation.m_pSimComponent[2].m_TypeUID;
  v29 = -1;
  if ( v9 )
  {
    if ( v28->mPose.mRigHandle.mData )
      v30 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, symCameraProxy.mUID);
    else
      v30 = -1;
    v4->nEyeBone = v30;
  }
  if ( v10 )
  {
    if ( v28->mPose.mRigHandle.mData )
      v31 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, symCameraTargetProxy.mUID);
    else
      v31 = -1;
    v4->nLookBone = v31;
  }
  if ( (_BYTE)a3 )
  {
    if ( v28->mPose.mRigHandle.mData )
      v29 = Skeleton::GetBoneID(v28->mPose.mRigHandle.mUFGSkeleton, symCameraParamsProxy.mUID);
    v4->nParamsBone = v29;
  }
  v32 = v4->nEyeBone;
  if ( v32 == -1 )
  {
    v33 = 0i64;
    v33.m128_f32[0] = (float)1;
    v52 = _mm_shuffle_ps(v33, v33, 81);
    v53 = _mm_shuffle_ps(v33, v33, 69);
    v54 = _mm_shuffle_ps(v33, v33, 21);
  }
  else
  {
    Creature::GetTransform(v28, v32, (UFG::qMatrix44 *)&v53.m128_u16[4]);
  }
  v34 = v4->nLookBone;
  if ( v34 == -1 )
  {
    v35 = 0i64;
    v35.m128_f32[0] = (float)1;
    v55 = v35;
    v56 = _mm_shuffle_ps(v35, v35, 81);
    v57 = _mm_shuffle_ps(v35, v35, 69);
    v58 = _mm_shuffle_ps(v35, v35, 21);
  }
  else
  {
    Creature::GetTransform(v28, v34, (UFG::qMatrix44 *)&v55);
  }
  v36 = v4->nParamsBone;
  if ( v36 == -1 )
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
    SkeletalPose::GetPositionLS(&v28->mPose, v36, &matrixLS);
  }
  if ( v4->bSingleBone )
    v58 = _mm_add_ps(v54, *(__m128 *)((char *)&v53 + 8));
  if ( v4->bMarkerRelative )
  {
    UFG::qMatrix44::operator*=((UFG::qMatrix44 *)&v53.m128_u16[4], &UFG::ProgressionCameraComponent::mMarkerTransform);
    v38 = &UFG::ProgressionCameraComponent::mMarkerTransform;
  }
  else
  {
    if ( !v4->bTargetSpace || !v4->mTarget.m_pSimComponent )
      goto LABEL_68;
    v39 = (UFG::qMatrix44 *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
    UFG::qMatrix44::operator*=((UFG::qMatrix44 *)&v53.m128_u16[4], v39);
    v38 = (UFG::qMatrix44 *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
  }
  UFG::qMatrix44::operator*=((UFG::qMatrix44 *)&v55, v38);
LABEL_68:
  desEye = *(UFG::qVector3 *)v54.m128_f32;
  desLook = *(UFG::qVector3 *)v58.m128_f32;
  UFG::GameCameraComponent::SetDesiredEyeLookUp(
    (UFG::GameCameraComponent *)&v4->vfptr,
    v3,
    &desEye,
    &desLook,
    a3,
    (UFG::qVector3 *)&v52,
    0,
    0i64,
    0i64);
  UFG::Camera::ApplyDutch(&v4->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
  v40 = matrixLS.v3.x * 100.0;
  v41 = matrixLS.v3.y * 100.0;
  v42 = matrixLS.v3.z * 100.0;
  v43 = &hkaPose::getSyncedPoseLocalSpace(v28->mPose.mHavokPose)->m_data[v4->nParamsBone];
  v59.m_vec.m_quad = (__m128)v43->m_rotation;
  v60.m_quad = (__m128)v43->m_scale;
  v44 = 0.0;
  v45 = 0.0;
  v46 = v43->m_rotation.m_vec.m_quad.m128_f32[3];
  if ( v46 > 0.0 )
  {
    LODWORD(v44) = COERCE_UNSIGNED_INT(v59.m_vec.m_quad.m128_f32[1] * (float)(1.0 / v46)) & _xmm;
    LODWORD(v45) = COERCE_UNSIGNED_INT(v59.m_vec.m_quad.m128_f32[2] * (float)(1.0 / v46)) & _xmm;
  }
  if ( v40 > 0.0 )
    v4->mFov = v40;
  v47 = (float)(v4->mFov * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    v47 = Render::GetExtraWideAspectCorrectedFOV(v47);
  v48 = Render::GetDisplayAspectRatio();
  UFG::Camera::SetViewProjection(&v4->mCamera, v47, v48, UFG::gCameraDefaultNear, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
  if ( v41 > 0.0 && v42 > 0.0 )
  {
    v49 = v60.m_quad.m128_f32[0];
    if ( v60.m_quad.m128_f32[0] > 0.0 && v60.m_quad.m128_f32[1] > 0.0 )
    {
      v4->mDofParameters.mFocalDistance = v60.m_quad.m128_f32[1];
      v4->mDofParameters.mInFocusRange = v49;
      v4->mDofParameters.mNearRange = v41;
      v4->mDofParameters.mNearBlurRadius = v44;
      v4->mDofParameters.mFarRange = v42;
      v4->mDofParameters.mFarBlurRadius = v45;
    }
  }
  UFG::GameCameraComponent::UpdateDof((UFG::GameCameraComponent *)&v4->vfptr, v3, &v4->mDofParameters, 0);
}

// File Line: 323
// RVA: 0x3C7F30
AnimationNode *__fastcall UFG::ProgressionCameraComponent::Play(UFG::ProgressionCameraComponent *this, UFG::qSymbolUC *name, float start_time)
{
  UFG::ProgressionCameraComponent *v3; // rbx
  UFG::BaseAnimationComponent *v4; // rcx
  AnimationNode *v5; // r8
  UFG::qSafePointer<AnimationNode,AnimationNode> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  AnimationNode *v10; // rcx
  AnimationNode *result; // rax

  v3 = this;
  v4 = (UFG::BaseAnimationComponent *)this->mAnimation.m_pSimComponent;
  if ( v4 )
    v5 = UFG::BaseAnimationComponent::PlayAnimation(v4, name, start_time);
  else
    v5 = 0i64;
  v6 = &v3->mAnimationNode;
  if ( v3->mAnimationNode.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v3->mAnimationNode.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->mAnimationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v3->mAnimationNode.mPrev;
  }
  v3->mAnimationNode.m_pPointer = v5;
  if ( v5 )
  {
    v9 = v5->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v3->mAnimationNode.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v10 = v3->mAnimationNode.m_pPointer;
  if ( v10 )
  {
    ((void (*)(void))v10->vfptr[3].GetResourcePath)();
    result = v3->mAnimationNode.m_pPointer;
  }
  else
  {
    result = 0i64;
  }
  v3->bSnapProgress = 1;
  return result;
}

