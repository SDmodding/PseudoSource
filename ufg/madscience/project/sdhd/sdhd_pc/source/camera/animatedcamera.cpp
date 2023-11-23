// File Line: 17
// RVA: 0x14BFEE0
__int64 dynamic_initializer_for__UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList__);
}

// File Line: 18
// RVA: 0x3C3ED0
__int64 __fastcall UFG::AnimatedCameraComponent::GetTypeSize(UFG::AnimatedCameraComponent *this)
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
void __fastcall UFG::AnimatedCameraComponent::AnimatedCameraComponent(
        UFG::AnimatedCameraComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *mPrev; // rax

  UFG::GameCameraComponent::GameCameraComponent(this, name_uid);
  this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>::mPrev = &this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>;
  this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>::mNext = &this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimatedCameraComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTransformNode);
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0>::RebindingComponentHandle<UFG::CameraAnimationComponent,0>(&this->mAnimation);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mTarget);
  Render::DepthOfField::Focus::Focus(&this->mDofParameters);
  this->mAnimationNode.mPrev = &this->mAnimationNode;
  this->mAnimationNode.mNext = &this->mAnimationNode;
  this->mAnimationNode.m_pPointer = 0i64;
  mPrev = UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList.mNode.mPrev;
  UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>;
  this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>::mNext = (UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *)&UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList;
  UFG::AnimatedCameraComponent::s_AnimatedCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID,
    "AnimatedCameraComponent");
  this->mFov = 55.0;
  *(_QWORD *)&this->nEyeBone = -1i64;
  this->nParamsBone = -1;
  *(_DWORD *)&this->bTargetSpace = 0;
  this->mAnimateParams = 0;
  this->mMotionblurMagnitude = 0.15000001;
  this->mDofParameters.mFocalDistance = 5.0;
  this->mDofParameters.mInFocusRange = 100.0;
  *(_QWORD *)&this->mDofParameters.mNearRange = 1084227584i64;
  *(_QWORD *)&this->mDofParameters.mFarRange = 1084227584i64;
}

// File Line: 64
// RVA: 0x3BDB30
void __fastcall UFG::AnimatedCameraComponent::~AnimatedCameraComponent(UFG::AnimatedCameraComponent *this)
{
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v2; // rdi
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *mNext; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mAnimationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v10; // rcx
  UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimatedCameraComponent::`vftable;
  if ( this == UFG::AnimatedCameraComponent::s_AnimatedCameraComponentpCurrentIterator )
    UFG::AnimatedCameraComponent::s_AnimatedCameraComponentpCurrentIterator = (UFG::AnimatedCameraComponent *)&this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>::mPrev[-78];
  v2 = &this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>;
  mPrev = this->UFG::qNode<UFG::AnimatedCameraComponent,UFG::AnimatedCameraComponent>::mPrev;
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

// File Line: 70
// RVA: 0x3C5560
bool __fastcall UFG::ProgressionCameraComponent::HasComponent(UFG::SceneObjectProperties *sceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           sceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAnimatedCamera);
}

// File Line: 76
// RVA: 0x3C8000
UFG::AnimatedCameraComponent *__fastcall UFG::AnimatedCameraComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *scene_object_properties)
{
  unsigned int m_NameUID; // ebx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  m_NameUID = scene_object_properties->m_NameUID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x5D0ui64, "AnimatedCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::AnimatedCameraComponent::AnimatedCameraComponent((UFG::AnimatedCameraComponent *)v4, m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, scene_object_properties->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::AnimatedCameraComponent *)v6;
}

// File Line: 85
// RVA: 0x3C79B0
void __fastcall UFG::AnimatedCameraComponent::OnAttach(UFG::ProgressionCameraComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *p_mAnimation; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  p_mAnimation = &this->mAnimation;
  if ( p_mAnimation->m_pSimComponent )
  {
    mNext = p_mAnimation->mNext;
    mPrev = p_mAnimation->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAnimation->m_pSimComponent = 0i64;
LABEL_7:
    p_mAnimation->m_pSimObject = 0i64;
    p_mAnimation->mNext = p_mAnimation;
    p_mAnimation->mPrev = p_mAnimation;
    goto LABEL_8;
  }
  if ( p_mAnimation->m_pSimObject && (p_mAnimation->mPrev != p_mAnimation || p_mAnimation->mNext != p_mAnimation) )
  {
    v7 = p_mAnimation->mNext;
    v8 = p_mAnimation->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  p_mAnimation->m_Changed = 1;
  p_mAnimation->m_pSimObject = object;
  p_mAnimation->m_TypeUID = UFG::CameraAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0>::BindInternal<UFG::SimObject>(p_mAnimation, object);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&this->mTransformNode, object);
}

// File Line: 93
// RVA: 0x3C7A50
void __fastcall UFG::AnimatedCameraComponent::OnDetach(UFG::ProgressionCameraComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CameraAnimationComponent,0> *p_mAnimation; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mTransformNode; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  p_mAnimation = &this->mAnimation;
  if ( this->mAnimation.m_pSimComponent )
  {
    mPrev = p_mAnimation->mPrev;
    mNext = this->mAnimation.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mAnimation.m_pSimComponent = 0i64;
LABEL_7:
    p_mAnimation->m_pSimObject = 0i64;
    p_mAnimation->mNext = p_mAnimation;
    p_mAnimation->mPrev = p_mAnimation;
    goto LABEL_8;
  }
  if ( this->mAnimation.m_pSimObject
    && (p_mAnimation->mPrev != p_mAnimation || this->mAnimation.mNext != &this->mAnimation) )
  {
    v5 = p_mAnimation->mPrev;
    v6 = p_mAnimation->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mTransformNode = &this->mTransformNode;
  p_mAnimation->m_Changed = 1;
  if ( this->mTransformNode.m_pSimComponent )
  {
    v8 = p_mTransformNode->mPrev;
    v9 = this->mTransformNode.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->mTransformNode.m_pSimComponent = 0i64;
    this->mTransformNode.m_pSimObject = 0i64;
    this->mTransformNode.mNext = &this->mTransformNode;
    p_mTransformNode->mPrev = p_mTransformNode;
    this->mTransformNode.m_Changed = 1;
  }
  else
  {
    if ( this->mTransformNode.m_pSimObject
      && (p_mTransformNode->mPrev != p_mTransformNode || this->mTransformNode.mNext != &this->mTransformNode) )
    {
      v10 = p_mTransformNode->mPrev;
      v11 = this->mTransformNode.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      this->mTransformNode.m_pSimObject = 0i64;
      this->mTransformNode.mNext = &this->mTransformNode;
      p_mTransformNode->mPrev = p_mTransformNode;
    }
    this->mTransformNode.m_Changed = 1;
  }
}

// File Line: 109
// RVA: 0x3CC020
void __fastcall UFG::AnimatedCameraComponent::SetDofParameters(
        UFG::AnimatedCameraComponent *this,
        float focal_distance,
        float focal_range,
        float near_radius,
        float near_range,
        float far_radius,
        float far_range)
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

  v0 = UFG::qStringHashUpper32("CameraProxy", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCameraProxy, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCameraProxy__);
}

// File Line: 120
// RVA: 0x14C8B80
__int64 UFG::_dynamic_initializer_for__symCameraTargetProxy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraTargetProxy", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCameraTargetProxy, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCameraTargetProxy__);
}

// File Line: 121
// RVA: 0x14C8B00
__int64 UFG::_dynamic_initializer_for__symCameraParamsProxy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraParamsProxy", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCameraParamsProxy, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCameraParamsProxy__);
}

// File Line: 126
// RVA: 0x3CFA30
void __fastcall UFG::AnimatedCameraComponent::Update(UFG::AnimatedCameraComponent *this, float delta_seconds)
{
  bool v3; // cl
  bool v4; // r14
  bool v5; // r15
  int v6; // esi
  Creature *v7; // rdi
  int BoneID; // eax
  int v9; // eax
  int nEyeBone; // edx
  UFG::qVector4 v11; // xmm2
  int nLookBone; // edx
  UFG::qVector4 v13; // xmm2
  int nParamsBone; // edx
  UFG::qVector4 v15; // xmm2
  UFG::qMatrix44 *v16; // rdx
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::qMatrix44 *v18; // rax
  float v19; // xmm6_4
  float v20; // xmm10_4
  float v21; // xmm11_4
  hkQsTransformf *v22; // rdx
  float v23; // xmm8_4
  float v24; // xmm9_4
  __int128 m_scale; // xmm0
  float v26; // xmm2_4
  float ExtraWideAspectCorrectedFOV; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  float v29; // xmm0_4
  SkeletalPose *v30; // rcx
  UFG::qVector3 desEye; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 desLook; // [rsp+4Ch] [rbp-B4h] BYREF
  UFG::qVector3 desUp; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-90h] BYREF
  UFG::qMatrix44 v35; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qColour newEye[2]; // [rsp+F0h] [rbp-10h] BYREF
  hkQuaternionf v37; // [rsp+110h] [rbp+10h]
  __int128 v38; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 matrixLS; // [rsp+130h] [rbp+30h] BYREF
  UFG::qVector3 newLook; // [rsp+170h] [rbp+70h] BYREF

  if ( UFG::gFlowController.mCurrentState
    && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
    || !this->mActive
    || !this->mAnimation.m_pSimComponent )
  {
    return;
  }
  UFG::GameCameraComponent::Update(this, delta_seconds);
  v3 = this->nEyeBone == -1;
  v4 = this->nLookBone == -1;
  v5 = this->nParamsBone == -1;
  if ( this->mAnimation.m_Changed )
  {
    this->mAnimation.m_Changed = 0;
    v5 = 1;
    v4 = 1;
    v3 = 1;
  }
  v6 = -1;
  v7 = *(Creature **)&this->mAnimation.m_pSimComponent[2].m_TypeUID;
  if ( v3 )
  {
    if ( v7->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, UFG::symCameraProxy.mUID);
    else
      BoneID = -1;
    this->nEyeBone = BoneID;
  }
  if ( v4 )
  {
    if ( v7->mPose.mRigHandle.mData )
      v9 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, UFG::symCameraTargetProxy.mUID);
    else
      v9 = -1;
    this->nLookBone = v9;
  }
  if ( v5 )
  {
    if ( v7->mPose.mRigHandle.mData )
      v6 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, UFG::symCameraParamsProxy.mUID);
    this->nParamsBone = v6;
  }
  nEyeBone = this->nEyeBone;
  if ( nEyeBone == -1 )
  {
    v11 = 0i64;
    v11.x = (float)1;
    transform.v0 = v11;
    transform.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 21);
    transform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 81);
    transform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 69);
  }
  else
  {
    Creature::GetTransform(v7, nEyeBone, &transform);
  }
  nLookBone = this->nLookBone;
  if ( nLookBone == -1 )
  {
    v13 = 0i64;
    v13.x = (float)1;
    v35.v0 = v13;
    v35.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v13, (__m128)v13, 21);
    v35.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v13, (__m128)v13, 81);
    v35.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v13, (__m128)v13, 69);
  }
  else
  {
    Creature::GetTransform(v7, nLookBone, &v35);
  }
  nParamsBone = this->nParamsBone;
  if ( nParamsBone == -1 )
  {
    v15 = 0i64;
    v15.x = (float)1;
    matrixLS.v0 = v15;
    matrixLS.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v15, (__m128)v15, 21);
    matrixLS.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v15, (__m128)v15, 81);
    matrixLS.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v15, (__m128)v15, 69);
  }
  else
  {
    SkeletalPose::GetPositionLS(&v7->mPose, nParamsBone, &matrixLS);
  }
  if ( this->bSingleBone )
    v35.v3 = (UFG::qVector4)_mm_add_ps((__m128)transform.v3, (__m128)transform.v0);
  if ( this->bMarkerRelative )
  {
    UFG::qMatrix44::operator*=(&transform, &UFG::AnimatedCameraComponent::mMarkerTransform);
    v16 = &UFG::AnimatedCameraComponent::mMarkerTransform;
  }
  else
  {
    if ( !this->bTargetSpace )
      goto LABEL_38;
    m_pSimComponent = this->mTarget.m_pSimComponent;
    if ( !m_pSimComponent )
      goto LABEL_38;
    v18 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    UFG::qMatrix44::operator*=(&transform, v18);
    v16 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
  }
  UFG::qMatrix44::operator*=(&v35, v16);
LABEL_38:
  desUp.x = transform.v1.x;
  desUp.y = transform.v1.y;
  desUp.z = transform.v1.z;
  desEye.x = transform.v3.x;
  desEye.y = transform.v3.y;
  desEye.z = transform.v3.z;
  desLook.x = v35.v3.x;
  desLook.y = v35.v3.y;
  desLook.z = v35.v3.z;
  UFG::GameCameraComponent::SetDesiredEyeLookUp(
    this,
    delta_seconds,
    &desEye,
    &desLook,
    &desUp,
    0,
    (UFG::qVector3 *)newEye,
    &newLook);
  v19 = matrixLS.v3.x * 100.0;
  v20 = matrixLS.v3.y * 100.0;
  v21 = matrixLS.v3.z * 100.0;
  v22 = &hkaPose::getSyncedPoseLocalSpace(v7->mPose.mHavokPose)->m_data[this->nParamsBone];
  v23 = 0.0;
  v24 = 0.0;
  m_scale = (__int128)v22->m_scale;
  v37.m_vec.m_quad = (__m128)v22->m_rotation;
  v38 = m_scale;
  v26 = v22->m_rotation.m_vec.m_quad.m128_f32[3];
  if ( v26 > 0.0 )
  {
    LODWORD(v23) = COERCE_UNSIGNED_INT(v37.m_vec.m_quad.m128_f32[1] * (float)(1.0 / v26)) & _xmm;
    LODWORD(v24) = COERCE_UNSIGNED_INT(v37.m_vec.m_quad.m128_f32[2] * (float)(1.0 / v26)) & _xmm;
  }
  if ( this->mAnimateParams && v19 > 0.0 )
    this->mFov = v19;
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
  if ( UFG::gEnableCameraDofAnim && v20 > 0.0 && v21 > 0.0 )
  {
    v29 = *(float *)&v38;
    if ( *(float *)&v38 > 0.0 && *((float *)&v38 + 1) > 0.0 )
    {
      this->mDofParameters.mFocalDistance = *((float *)&v38 + 1);
      this->mDofParameters.mInFocusRange = v29;
      this->mDofParameters.mNearRange = v20;
      this->mDofParameters.mNearBlurRadius = v23;
      this->mDofParameters.mFarRange = v21;
      this->mDofParameters.mFarBlurRadius = v24;
    }
  }
  UFG::Camera::ApplyDutch(&this->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
  UFG::GameCameraComponent::UpdateDof(this, delta_seconds, &this->mDofParameters, 1);
  if ( gSkeletonDebug )
  {
    v30 = (SkeletalPose *)(*(_QWORD *)&this->mAnimation.m_pSimComponent[2].m_TypeUID + 240i64);
    newEye[0] = UFG::qColour::Green;
    SkeletalPose::DebugDraw(v30, newEye, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
  }
}

// File Line: 291
// RVA: 0x3CD430
void __fastcall UFG::ProgressionCameraComponent::SetTarget(
        UFG::ProgressionCameraComponent *this,
        UFG::CameraSubject *target)
{
  UFG::CameraSubject *ComponentOfType; // rax

  ComponentOfType = target;
  if ( target )
    ComponentOfType = (UFG::CameraSubject *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)target,
                                              UFG::CameraSubject::_TypeUID);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::Set(&this->mTarget, ComponentOfType);
}

// File Line: 297
// RVA: 0x3C7EB0
AnimationNode *__fastcall UFG::AnimatedCameraComponent::Play(
        UFG::AnimatedCameraComponent *this,
        UFG::qSymbolUC *name,
        float start_time)
{
  UFG::BaseAnimationComponent *m_pSimComponent; // rcx
  AnimationNode *v5; // r8
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mAnimationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax

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
  return this->mAnimationNode.m_pPointer;
}

