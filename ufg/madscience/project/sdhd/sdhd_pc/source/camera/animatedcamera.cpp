// File Line: 17
// RVA: 0x14BFEE0
__int64 dynamic_initializer_for__UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList__);
}

// File Line: 18
// RVA: 0x3C3ED0
signed __int64 __fastcall UFG::AnimatedCameraComponent::GetTypeSize(UFG::AnimatedCameraComponent *this)
{
  return 1488i64;
}

// File Line: 19
// RVA: 0x14BFE60
void dynamic_initializer_for__UFG::AnimatedCameraComponent::mMarkerTransform__()
{
  UFG::AnimatedCameraComponent::mMarkerTransform = UFG::qMatrix44::msIdentity;
}

// File Line: 24
// RVA: 0x3BA8A0
void __fastcall UFG::AnimatedCameraComponent::AnimatedCameraComponent(UFG::AnimatedCameraComponent *this, unsigned int name_uid)
{
  UFG::AnimatedCameraComponent *v2; // rsi
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v3; // rdi
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v4; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::GameCameraComponent::GameCameraComponent((UFG::GameCameraComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimatedCameraComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->mTransformNode);
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0>::RebindingComponentHandle<UFG::CameraAnimationComponent,0>(&v2->mAnimation);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&v2->mTarget);
  Render::DepthOfField::Focus::Focus(&v2->mDofParameters);
  v5 = &v2->mAnimationNode;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v2->mAnimationNode.m_pPointer = 0i64;
  v4 = UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList.mNode.mPrev;
  UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *)&UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList;
  UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID,
    "AnimatedCameraComponent");
  v2->mFov = 55.0;
  *(_QWORD *)&v2->nEyeBone = -1i64;
  v2->nParamsBone = -1;
  *(_DWORD *)&v2->bTargetSpace = 0;
  v2->mAnimateParams = 0;
  v2->mMotionblurMagnitude = 0.15000001;
  v2->mDofParameters.mFocalDistance = 5.0;
  v2->mDofParameters.mInFocusRange = 100.0;
  *(_QWORD *)&v2->mDofParameters.mNearRange = 1084227584i64;
  *(_QWORD *)&v2->mDofParameters.mFarRange = 1084227584i64;
}

// File Line: 64
// RVA: 0x3BDB30
void __fastcall UFG::AnimatedCameraComponent::~AnimatedCameraComponent(UFG::AnimatedCameraComponent *this)
{
  UFG::AnimatedCameraComponent *v1; // rbx
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v2; // rdi
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v3; // rcx
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v4; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v10; // rcx
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimatedCameraComponent::`vftable;
  if ( this == UFG::AnimatedCameraComponent::s_AnimatedCameraComponentpCurrentIterator )
    UFG::AnimatedCameraComponent::s_AnimatedCameraComponentpCurrentIterator = (UFG::AnimatedCameraComponent *)&this->mPrev[-78];
  v2 = (UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *)&this->mPrev;
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

// File Line: 70
// RVA: 0x3C5560
bool __fastcall UFG::ProgressionCameraComponent::HasComponent(UFG::SceneObjectProperties *sceneObj)
{
  return PropertyUtils::HasComponentPropertySet(sceneObj, (UFG::qSymbol *)&SimSymX_propset_componentAnimatedCamera.mUID);
}

// File Line: 76
// RVA: 0x3C8000
UFG::SimComponent *__fastcall UFG::AnimatedCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *scene_object_properties)
{
  UFG::SceneObjectProperties *v1; // rdi
  unsigned int v2; // ebx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = scene_object_properties;
  v2 = scene_object_properties->m_NameUID;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x5D0ui64, "AnimatedCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::AnimatedCameraComponent::AnimatedCameraComponent((UFG::AnimatedCameraComponent *)v4, v2);
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

// File Line: 85
// RVA: 0x3C79B0
void __fastcall UFG::AnimatedCameraComponent::OnAttach(UFG::ProgressionCameraComponent *this, UFG::SimObject *object)
{
  UFG::ProgressionCameraComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = this;
  v3 = &this->mAnimation;
  v4 = object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mNext;
    v6 = v3->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mNext;
    v8 = v3->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::CameraAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&v2->mTransformNode, v4);
}

// File Line: 93
// RVA: 0x3C7A50
void __fastcall UFG::AnimatedCameraComponent::OnDetach(UFG::ProgressionCameraComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *v1; // r8
  UFG::ProgressionCameraComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  v1 = &this->mAnimation;
  v2 = this;
  if ( this->mAnimation.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mAnimation.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mAnimation.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mAnimation.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *)this->mAnimation.mNext != &this->mAnimation) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->mTransformNode;
  v1->m_Changed = 1;
  if ( v2->mTransformNode.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->mTransformNode.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->mTransformNode.m_pSimComponent = 0i64;
    v2->mTransformNode.m_pSimObject = 0i64;
    v2->mTransformNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mTransformNode.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    v2->mTransformNode.m_Changed = 1;
  }
  else
  {
    if ( v2->mTransformNode.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v7->mPrev != v7
       || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v2->mTransformNode.mNext != &v2->mTransformNode) )
    {
      v10 = v7->mPrev;
      v11 = v2->mTransformNode.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v2->mTransformNode.m_pSimObject = 0i64;
      v2->mTransformNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mTransformNode.mPrev;
      v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    }
    v2->mTransformNode.m_Changed = 1;
  }
}

// File Line: 109
// RVA: 0x3CC020
void __fastcall UFG::AnimatedCameraComponent::SetDofParameters(UFG::AnimatedCameraComponent *this, float focal_distance, float focal_range, float near_radius, float near_range, float far_radius, float far_range)
{
  this->mDofParameters.mFocalDistance = focal_distance;
  this->mDofParameters.mNearRange = near_range;
  this->mDofParameters.mInFocusRange = focal_range;
  this->mDofParameters.mFarBlurRadius = far_radius;
  this->mDofParameters.mNearBlurRadius = near_radius;
  this->mDofParameters.mFarRange = far_range;
}

// File Line: 119
// RVA: 0x14C8B40
__int64 UFG::_dynamic_initializer_for__symCameraProxy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraProxy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCameraProxy, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCameraProxy__);
}

// File Line: 120
// RVA: 0x14C8B80
__int64 UFG::_dynamic_initializer_for__symCameraTargetProxy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraTargetProxy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCameraTargetProxy, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCameraTargetProxy__);
}

// File Line: 121
// RVA: 0x14C8B00
__int64 UFG::_dynamic_initializer_for__symCameraParamsProxy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraParamsProxy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCameraParamsProxy, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCameraParamsProxy__);
}

// File Line: 126
// RVA: 0x3CFA30
void __usercall UFG::AnimatedCameraComponent::Update(UFG::AnimatedCameraComponent *this@<rcx>, float delta_seconds@<xmm1>, float *a3@<r13>)
{
  UFG::AnimatedCameraComponent *v3; // rbx
  bool v4; // cl
  bool v5; // r14
  bool v6; // r15
  signed int v7; // esi
  Creature *v8; // rdi
  signed int v9; // eax
  signed int v10; // eax
  int v11; // edx
  UFG::qVector4 v12; // xmm2
  int v13; // edx
  UFG::qVector4 v14; // xmm2
  int v15; // edx
  UFG::qVector4 v16; // xmm2
  UFG::qMatrix44 *v17; // rdx
  UFG::SimComponent *v18; // rcx
  UFG::qMatrix44 *v19; // rax
  float v20; // xmm6_4
  float v21; // xmm10_4
  float v22; // xmm11_4
  hkQsTransformf *v23; // rdx
  float v24; // xmm8_4
  float v25; // xmm9_4
  __int128 v26; // xmm0
  float v27; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  SkeletalPose *v31; // rcx
  UFG::qVector3 desEye; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 desLook; // [rsp+4Ch] [rbp-B4h]
  UFG::qVector3 desUp; // [rsp+58h] [rbp-A8h]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-90h]
  UFG::qMatrix44 v36; // [rsp+B0h] [rbp-50h]
  UFG::qColour newEye; // [rsp+F0h] [rbp-10h]
  hkQuaternionf v38; // [rsp+110h] [rbp+10h]
  __int128 v39; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 matrixLS; // [rsp+130h] [rbp+30h]
  UFG::qVector3 newLook; // [rsp+170h] [rbp+70h]

  v3 = this;
  if ( UFG::gFlowController.mCurrentState
    && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
    || !v3->mActive
    || !v3->mAnimation.m_pSimComponent )
  {
    return;
  }
  UFG::GameCameraComponent::Update((UFG::GameCameraComponent *)&v3->vfptr, delta_seconds);
  v4 = v3->nEyeBone == -1;
  v5 = v3->nLookBone == -1;
  v6 = v3->nParamsBone == -1;
  if ( v3->mAnimation.m_Changed )
  {
    v3->mAnimation.m_Changed = 0;
    v6 = 1;
    v5 = 1;
    v4 = 1;
  }
  v7 = -1;
  v8 = *(Creature **)&v3->mAnimation.m_pSimComponent[2].m_TypeUID;
  if ( v4 )
  {
    if ( v8->mPose.mRigHandle.mData )
      v9 = Skeleton::GetBoneID(v8->mPose.mRigHandle.mUFGSkeleton, UFG::symCameraProxy.mUID);
    else
      v9 = -1;
    v3->nEyeBone = v9;
  }
  if ( v5 )
  {
    if ( v8->mPose.mRigHandle.mData )
      v10 = Skeleton::GetBoneID(v8->mPose.mRigHandle.mUFGSkeleton, UFG::symCameraTargetProxy.mUID);
    else
      v10 = -1;
    v3->nLookBone = v10;
  }
  if ( v6 )
  {
    if ( v8->mPose.mRigHandle.mData )
      v7 = Skeleton::GetBoneID(v8->mPose.mRigHandle.mUFGSkeleton, UFG::symCameraParamsProxy.mUID);
    v3->nParamsBone = v7;
  }
  v11 = v3->nEyeBone;
  if ( v11 == -1 )
  {
    v12 = 0i64;
    v12.x = (float)1;
    transform.v0 = v12;
    transform.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 21);
    transform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 81);
    transform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 69);
  }
  else
  {
    Creature::GetTransform(v8, v11, &transform);
  }
  v13 = v3->nLookBone;
  if ( v13 == -1 )
  {
    v14 = 0i64;
    v14.x = (float)1;
    v36.v0 = v14;
    v36.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 21);
    v36.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 81);
    v36.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v14, (__m128)v14, 69);
  }
  else
  {
    Creature::GetTransform(v8, v13, &v36);
  }
  v15 = v3->nParamsBone;
  if ( v15 == -1 )
  {
    v16 = 0i64;
    v16.x = (float)1;
    matrixLS.v0 = v16;
    matrixLS.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v16, (__m128)v16, 21);
    matrixLS.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v16, (__m128)v16, 81);
    matrixLS.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v16, (__m128)v16, 69);
  }
  else
  {
    SkeletalPose::GetPositionLS(&v8->mPose, v15, &matrixLS);
  }
  if ( v3->bSingleBone )
    v36.v3 = (UFG::qVector4)_mm_add_ps((__m128)transform.v3, (__m128)transform.v0);
  if ( v3->bMarkerRelative )
  {
    UFG::qMatrix44::operator*=(&transform, &UFG::AnimatedCameraComponent::mMarkerTransform);
    v17 = &UFG::AnimatedCameraComponent::mMarkerTransform;
  }
  else
  {
    if ( !v3->bTargetSpace )
      goto LABEL_38;
    v18 = v3->mTarget.m_pSimComponent;
    if ( !v18 )
      goto LABEL_38;
    v19 = (UFG::qMatrix44 *)((__int64 (*)(void))v18->vfptr[18].__vecDelDtor)();
    UFG::qMatrix44::operator*=(&transform, v19);
    v17 = (UFG::qMatrix44 *)((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
  }
  UFG::qMatrix44::operator*=(&v36, v17);
LABEL_38:
  desUp = *(UFG::qVector3 *)&transform.v1.x;
  desEye = *(UFG::qVector3 *)&transform.v3.x;
  desLook = *(UFG::qVector3 *)&v36.v3.x;
  UFG::GameCameraComponent::SetDesiredEyeLookUp(
    (UFG::GameCameraComponent *)&v3->vfptr,
    delta_seconds,
    &desEye,
    &desLook,
    a3,
    &desUp,
    0,
    (UFG::qVector3 *)&newEye,
    &newLook);
  v20 = matrixLS.v3.x * 100.0;
  v21 = matrixLS.v3.y * 100.0;
  v22 = matrixLS.v3.z * 100.0;
  v23 = &hkaPose::getSyncedPoseLocalSpace(v8->mPose.mHavokPose)->m_data[v3->nParamsBone];
  v24 = 0.0;
  v25 = 0.0;
  v26 = (__int128)v23->m_scale;
  v38.m_vec.m_quad = (__m128)v23->m_rotation;
  v39 = v26;
  v27 = v23->m_rotation.m_vec.m_quad.m128_f32[3];
  if ( v27 > 0.0 )
  {
    LODWORD(v24) = COERCE_UNSIGNED_INT(v38.m_vec.m_quad.m128_f32[1] * (float)(1.0 / v27)) & _xmm;
    LODWORD(v25) = COERCE_UNSIGNED_INT(v38.m_vec.m_quad.m128_f32[2] * (float)(1.0 / v27)) & _xmm;
  }
  if ( v3->mAnimateParams && v20 > 0.0 )
    v3->mFov = v20;
  v28 = (float)(v3->mFov * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    v28 = Render::GetExtraWideAspectCorrectedFOV(v28);
  v29 = Render::GetDisplayAspectRatio();
  UFG::Camera::SetViewProjection(&v3->mCamera, v28, v29, UFG::gCameraDefaultNear, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
  if ( UFG::gEnableCameraDofAnim && v21 > 0.0 && v22 > 0.0 )
  {
    v30 = *(float *)&v39;
    if ( *(float *)&v39 > 0.0 && *((float *)&v39 + 1) > 0.0 )
    {
      v3->mDofParameters.mFocalDistance = *((float *)&v39 + 1);
      v3->mDofParameters.mInFocusRange = v30;
      v3->mDofParameters.mNearRange = v21;
      v3->mDofParameters.mNearBlurRadius = v24;
      v3->mDofParameters.mFarRange = v22;
      v3->mDofParameters.mFarBlurRadius = v25;
    }
  }
  UFG::Camera::ApplyDutch(&v3->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
  UFG::GameCameraComponent::UpdateDof((UFG::GameCameraComponent *)&v3->vfptr, delta_seconds, &v3->mDofParameters, 1);
  if ( gSkeletonDebug )
  {
    v31 = (SkeletalPose *)(*(_QWORD *)&v3->mAnimation.m_pSimComponent[2].m_TypeUID + 240i64);
    newEye = UFG::qColour::Green;
    SkeletalPose::DebugDraw(v31, &newEye, 1.0);
  }
}

// File Line: 291
// RVA: 0x3CD430
void __fastcall UFG::ProgressionCameraComponent::SetTarget(UFG::ProgressionCameraComponent *this, UFG::SimObject *target)
{
  UFG::CameraSubject *v2; // rax
  UFG::ProgressionCameraComponent *v3; // rbx

  v2 = (UFG::CameraSubject *)target;
  v3 = this;
  if ( target )
    v2 = (UFG::CameraSubject *)UFG::SimObject::GetComponentOfType(target, UFG::CameraSubject::_TypeUID);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::Set(&v3->mTarget, v2);
}

// File Line: 297
// RVA: 0x3C7EB0
AnimationNode *__fastcall UFG::AnimatedCameraComponent::Play(UFG::AnimatedCameraComponent *this, UFG::qSymbolUC *name, float start_time)
{
  UFG::AnimatedCameraComponent *v3; // rbx
  UFG::BaseAnimationComponent *v4; // rcx
  AnimationNode *v5; // r8
  UFG::qSafePointer<AnimationNode,AnimationNode> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax

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
  return v3->mAnimationNode.m_pPointer;
}

