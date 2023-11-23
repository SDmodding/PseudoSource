// File Line: 44
// RVA: 0x14BFF80
__int64 dynamic_initializer_for__UFG::ScriptCameraComponent::s_ScriptCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ScriptCameraComponent::s_ScriptCameraComponentList__);
}

// File Line: 45
// RVA: 0x3C3EB0
const char *__fastcall UFG::ScriptCameraComponent::GetTypeName(UFG::ScriptCameraComponent *this)
{
  return "ScriptCameraComponent";
}

// File Line: 54
// RVA: 0x3BD190
void __fastcall UFG::ScriptCameraComponent::ScriptCameraComponent(
        UFG::ScriptCameraComponent *this,
        unsigned int name_uid,
        UFG::SimObject *pObj)
{
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v4; // r12
  UFG::qSafePointer<Creature,Creature> *p_mCameraCreature; // rsi
  UFG::qSafePointer<Creature,Creature> *p_mTargetCreature; // rdi
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v12; // rdi
  unsigned int v13; // eax
  UFG::TransformNodeComponent *v14; // rax
  UFG::qMemoryPool *v15; // rax
  UFG::allocator::free_link *v16; // rdi
  unsigned int v17; // eax
  UFG::TransformNodeComponent *v18; // rax
  UFG::qMemoryPool *v19; // rax
  UFG::allocator::free_link *v20; // rdi
  unsigned int v21; // eax
  UFG::TransformNodeComponent *v22; // rax
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm1_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v46; // rax
  UFG::qVector3 v47; // [rsp+38h] [rbp-C0h] BYREF
  UFG::qVector3 v48; // [rsp+48h] [rbp-B0h] BYREF
  UFG::qVector3 v49; // [rsp+58h] [rbp-A0h] BYREF
  UFG::SimObjectModifier v50; // [rsp+68h] [rbp-90h] BYREF

  UFG::GameCameraComponent::GameCameraComponent(this, name_uid);
  v4 = &this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>;
  this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>::mPrev = &this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>;
  this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>::mNext = &this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ScriptCameraComponent::`vftable;
  p_mCameraCreature = &this->mCameraCreature;
  this->mCameraCreature.mPrev = &this->mCameraCreature;
  this->mCameraCreature.mNext = &this->mCameraCreature;
  this->mCameraCreature.m_pPointer = 0i64;
  p_mTargetCreature = &this->mTargetCreature;
  this->mTargetCreature.mPrev = &this->mTargetCreature;
  this->mTargetCreature.mNext = &this->mTargetCreature;
  this->mTargetCreature.m_pPointer = 0i64;
  Render::DepthOfField::Focus::Focus(&this->mDofParameters);
  this->mFov.mDuration = 0.0099999998;
  this->mEye.mDuration.x = 0.0099999998;
  this->mEye.mDuration.y = 0.0099999998;
  this->mEye.mDuration.z = 0.0099999998;
  this->mLook.mDuration.x = 0.0099999998;
  this->mLook.mDuration.y = 0.0099999998;
  this->mLook.mDuration.z = 0.0099999998;
  this->mEyeNoise.bCircular = 0;
  v47.x = 1.0;
  v47.y = 1.0;
  v47.z = 1.0;
  v48.x = -1.0;
  v48.y = -1.0;
  v48.z = -1.0;
  v49.x = 0.5;
  v49.y = 0.5;
  v49.z = 0.5;
  UFG::qNoise<UFG::qVector3,float>::SetParameters(&this->mEyeNoise, 6, 1.0, &v49, &v48, &v47);
  UFG::qNoise<UFG::qVector3,float>::qNoise<UFG::qVector3,float>(&this->mLookNoise);
  this->mHighlightedCharacter.mPrev = &this->mHighlightedCharacter;
  this->mHighlightedCharacter.mNext = &this->mHighlightedCharacter;
  this->mHighlightedCharacter.m_pPointer = 0i64;
  if ( this->mCameraCreature.m_pPointer )
  {
    mPrev = p_mCameraCreature->mPrev;
    mNext = this->mCameraCreature.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCameraCreature->mPrev = p_mCameraCreature;
    this->mCameraCreature.mNext = &this->mCameraCreature;
  }
  this->mCameraCreature.m_pPointer = 0i64;
  this->nCameraCreatureBone = -1;
  if ( this->mTargetCreature.m_pPointer )
  {
    v9 = p_mTargetCreature->mPrev;
    v10 = this->mTargetCreature.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_mTargetCreature->mPrev = p_mTargetCreature;
    this->mTargetCreature.mNext = &this->mTargetCreature;
  }
  this->mTargetCreature.m_pPointer = 0i64;
  this->nTargetCreatureBone = -1;
  this->mPreviousCameraComponent = 0i64;
  this->mDofSnapNext = 1;
  this->mDofParameters.mFocalDistance = 5.0;
  this->mDofParameters.mInFocusRange = 200.0;
  *(_QWORD *)&this->mDofParameters.mNearRange = 1056964608i64;
  this->mDofParameters.mFarRange = 5.0;
  this->mDofParameters.mFarBlurRadius = 4.0;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v12 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v12 )
  {
    v13 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v12, v13, 0i64, 0);
  }
  else
  {
    v14 = 0i64;
  }
  this->mTargetTransform = v14;
  v15 = UFG::GetSimulationMemoryPool();
  v16 = UFG::qMemoryPool::Allocate(v15, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v16 )
  {
    v17 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v16, v17, 0i64, 0);
  }
  else
  {
    v18 = 0i64;
  }
  this->mCameraTransform = v18;
  v19 = UFG::GetSimulationMemoryPool();
  v20 = UFG::qMemoryPool::Allocate(v19, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v20 )
  {
    v21 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v20, v21, 0i64, 0);
  }
  else
  {
    v22 = 0i64;
  }
  this->mNextCameraTransform = v22;
  LODWORD(v23) = LODWORD(FLOAT_0_1) & _xmm;
  v24 = FLOAT_0_000099999997;
  if ( COERCE_FLOAT(LODWORD(FLOAT_0_1) & _xmm) <= 0.000099999997 )
    v25 = FLOAT_0_000099999997;
  else
    LODWORD(v25) = LODWORD(FLOAT_0_1) & _xmm;
  this->mEyeNoise.tOffset = (float)((float)(1.0 / v25) * this->mEyeNoise.tFrequency) * this->mEyeNoise.tOffset;
  this->mEyeNoise.tFrequency = v23;
  UFG::qNoise<UFG::qVector3,float>::Init(&this->mEyeNoise);
  if ( v23 > 0.000099999997 )
    LODWORD(v24) = LODWORD(FLOAT_0_1) & _xmm;
  this->mLookNoise.tOffset = (float)((float)(1.0 / v24) * this->mLookNoise.tFrequency) * this->mLookNoise.tOffset;
  this->mLookNoise.tFrequency = v23;
  UFG::qNoise<UFG::qVector3,float>::Init(&this->mLookNoise);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mLookOffset.x = UFG::qVector3::msZero.x;
  this->mLookOffset.y = y;
  this->mLookOffset.z = z;
  v28 = UFG::qVector3::msZero.y;
  v29 = UFG::qVector3::msZero.z;
  this->mFollowTargetEyeOffset.x = UFG::qVector3::msZero.x;
  this->mFollowTargetEyeOffset.y = v28;
  this->mFollowTargetEyeOffset.z = v29;
  *(_QWORD *)&this->mFov.mDuration = 1065353216i64;
  *(_QWORD *)&this->mFov.v0 = 0i64;
  this->mFov.p0 = 100.0;
  this->mFov.p1 = 100.0;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mEye.mDuration.x = 1.0;
  this->mEye.mDuration.y = 1.0;
  *(_QWORD *)&this->mEye.mDuration.z = 1065353216i64;
  *(_QWORD *)&this->mEye.mParameter.y = 0i64;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  this->mEye.v0.x = UFG::qVector3::msZero.x;
  this->mEye.v0.y = v30;
  this->mEye.v0.z = v31;
  v32 = UFG::qVector3::msZero.y;
  v33 = UFG::qVector3::msZero.z;
  this->mEye.v1.x = UFG::qVector3::msZero.x;
  this->mEye.v1.y = v32;
  this->mEye.v1.z = v33;
  v34 = UFG::qVector3::msZero.y;
  v35 = UFG::qVector3::msZero.z;
  this->mEye.p0.x = UFG::qVector3::msZero.x;
  this->mEye.p0.y = v34;
  this->mEye.p0.z = v35;
  v36 = UFG::qVector3::msZero.y;
  v37 = UFG::qVector3::msZero.z;
  this->mEye.p1.x = UFG::qVector3::msZero.x;
  this->mEye.p1.y = v36;
  this->mEye.p1.z = v37;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  this->mLook.mDuration.x = 1.0;
  this->mLook.mDuration.y = 1.0;
  *(_QWORD *)&this->mLook.mDuration.z = 1065353216i64;
  *(_QWORD *)&this->mLook.mParameter.y = 0i64;
  v38 = UFG::qVector3::msZero.y;
  v39 = UFG::qVector3::msZero.z;
  this->mLook.v0.x = UFG::qVector3::msZero.x;
  this->mLook.v0.y = v38;
  this->mLook.v0.z = v39;
  v40 = UFG::qVector3::msZero.y;
  v41 = UFG::qVector3::msZero.z;
  this->mLook.v1.x = UFG::qVector3::msZero.x;
  this->mLook.v1.y = v40;
  this->mLook.v1.z = v41;
  v42 = UFG::qVector3::msZero.y;
  v43 = UFG::qVector3::msZero.z;
  this->mLook.p0.x = UFG::qVector3::msZero.x;
  this->mLook.p0.y = v42;
  this->mLook.p0.z = v43;
  v44 = UFG::qVector3::msZero.y;
  v45 = UFG::qVector3::msZero.z;
  this->mLook.p1.x = UFG::qVector3::msZero.x;
  this->mLook.p1.y = v44;
  this->mLook.p1.z = v45;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mEyeNoiseMagnitude = 0i64;
  this->mElapsedSeconds = 0.0;
  *(_QWORD *)&this->mLatitude = 0i64;
  *(_DWORD *)&this->mbScriptCameraOn = 0;
  *(_WORD *)&this->mbPanning = 0;
  this->mbHighlightOn = 0;
  this->bAllowWideAspectDisplay = 0;
  v46 = UFG::ScriptCameraComponent::s_ScriptCameraComponentList.mNode.mPrev;
  UFG::ScriptCameraComponent::s_ScriptCameraComponentList.mNode.mPrev->mNext = v4;
  v4->mPrev = v46;
  this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>::mNext = (UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *)&UFG::ScriptCameraComponent::s_ScriptCameraComponentList;
  UFG::ScriptCameraComponent::s_ScriptCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>;
  UFG::SimComponent::AddType(this, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID, "ScriptCameraComponent");
  UFG::SimObjectModifier::SimObjectModifier(&v50, pObj, 1);
  UFG::SimObjectModifier::AttachComponent(&v50, this, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v50);
  UFG::SimObjectModifier::~SimObjectModifier(&v50);
}

// File Line: 108
// RVA: 0x3BE100
void __fastcall UFG::ScriptCameraComponent::~ScriptCameraComponent(UFG::ScriptCameraComponent *this)
{
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v2; // r9
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mHighlightedCharacter; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<Creature,Creature> *p_mTargetCreature; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<Creature,Creature> *p_mCameraCreature; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v20; // rcx
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v21; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ScriptCameraComponent::`vftable;
  if ( this == UFG::ScriptCameraComponent::s_ScriptCameraComponentpCurrentIterator )
    UFG::ScriptCameraComponent::s_ScriptCameraComponentpCurrentIterator = (UFG::ScriptCameraComponent *)&this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>::mPrev[-78];
  v2 = &this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>;
  mPrev = this->UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mHighlightedCharacter = &this->mHighlightedCharacter;
  if ( this->mHighlightedCharacter.m_pPointer )
  {
    v6 = p_mHighlightedCharacter->mPrev;
    v7 = this->mHighlightedCharacter.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mHighlightedCharacter->mPrev = p_mHighlightedCharacter;
    this->mHighlightedCharacter.mNext = &this->mHighlightedCharacter;
  }
  this->mHighlightedCharacter.m_pPointer = 0i64;
  v8 = p_mHighlightedCharacter->mPrev;
  v9 = this->mHighlightedCharacter.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mHighlightedCharacter->mPrev = p_mHighlightedCharacter;
  this->mHighlightedCharacter.mNext = &this->mHighlightedCharacter;
  p_mTargetCreature = &this->mTargetCreature;
  if ( this->mTargetCreature.m_pPointer )
  {
    v11 = p_mTargetCreature->mPrev;
    v12 = this->mTargetCreature.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mTargetCreature->mPrev = p_mTargetCreature;
    this->mTargetCreature.mNext = &this->mTargetCreature;
  }
  this->mTargetCreature.m_pPointer = 0i64;
  v13 = p_mTargetCreature->mPrev;
  v14 = this->mTargetCreature.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mTargetCreature->mPrev = p_mTargetCreature;
  this->mTargetCreature.mNext = &this->mTargetCreature;
  p_mCameraCreature = &this->mCameraCreature;
  if ( this->mCameraCreature.m_pPointer )
  {
    v16 = p_mCameraCreature->mPrev;
    v17 = this->mCameraCreature.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_mCameraCreature->mPrev = p_mCameraCreature;
    this->mCameraCreature.mNext = &this->mCameraCreature;
  }
  this->mCameraCreature.m_pPointer = 0i64;
  v18 = p_mCameraCreature->mPrev;
  v19 = this->mCameraCreature.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_mCameraCreature->mPrev = p_mCameraCreature;
  this->mCameraCreature.mNext = &this->mCameraCreature;
  v20 = v2->mPrev;
  v21 = v2->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GameCameraComponent::~GameCameraComponent(this);
}

// File Line: 113
// RVA: 0x3CE500
void __fastcall UFG::ScriptCameraComponent::SwitchToScriptCam(
        UFG::ScriptCameraComponent *this,
        UFG::TransformNodeComponent *pTNC,
        bool transitionIn,
        float fov)
{
  Render::DepthOfField::Focus *p_mDepthOfFieldFocus; // rcx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  __int64 v13; // r8
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float x; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  UFG::Director *v22; // rax
  UFG::TransformNodeComponent *mCameraTransform; // rcx
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  UFG::qVector3 desLook; // [rsp+40h] [rbp-58h] BYREF
  UFG::qVector3 desEye; // [rsp+4Ch] [rbp-4Ch] BYREF

  p_mDepthOfFieldFocus = &this->mCamera.mDepthOfFieldFocus;
  p_mDepthOfFieldFocus[71].mFarRange = 0.0;
  *(float *)((char *)&p_mDepthOfFieldFocus[72].mNearBlurRadius + 1) = 0.0;
  Render::DepthOfField::Focus::DisableFocus(p_mDepthOfFieldFocus);
  if ( !this->mbScriptCameraOn )
    this->mPreviousCameraComponent = UFG::Director::Get()->mCurrentCamera;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && mCurrentCamera->m_pSimObject )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTNC);
    y = pTNC->mWorldTransform.v3.y;
    z = pTNC->mWorldTransform.v3.z;
    this->mEye.p1.x = pTNC->mWorldTransform.v3.x;
    this->mEye.p1.y = y;
    this->mEye.p1.z = z;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
    UFG::TransformNodeComponent::UpdateWorldTransform(pTNC);
    UFG::TransformNodeComponent::UpdateWorldTransform(pTNC);
    v11 = pTNC->mWorldTransform.v0.y + pTNC->mWorldTransform.v3.y;
    v12 = pTNC->mWorldTransform.v0.z + pTNC->mWorldTransform.v3.z;
    this->mLook.p1.x = pTNC->mWorldTransform.v0.x + pTNC->mWorldTransform.v3.x;
    this->mLook.p1.y = v11;
    this->mLook.p1.z = v12;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
    *(_QWORD *)&this->mLook.mParameter.x = 0i64;
    this->mLook.mParameter.z = 0.0;
    if ( fov == 0.0 )
      this->mFov.p1 = (float)(((float (__fastcall *)(UFG::BaseCameraComponent *))this->mPreviousCameraComponent->vfptr[19].__vecDelDtor)(this->mPreviousCameraComponent)
                            * 180.0)
                    * 0.31830987;
    else
      this->mFov.p1 = fov;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.mParameter = 0.0;
    if ( transitionIn )
    {
      LOBYTE(v13) = 1;
      ((void (__fastcall *)(UFG::ScriptCameraComponent *, UFG::BaseCameraComponent *, __int64))this->vfptr[29].__vecDelDtor)(
        this,
        this->mPreviousCameraComponent,
        v13);
    }
    else
    {
      v14 = this->mEye.p1.y;
      v15 = this->mEye.p1.z;
      this->mEye.p0.x = this->mEye.p1.x;
      this->mEye.p0.y = v14;
      this->mEye.p0.z = v15;
      v16 = this->mEye.v1.y;
      v17 = this->mEye.v1.z;
      this->mEye.v0.x = this->mEye.v1.x;
      this->mEye.v0.y = v16;
      this->mEye.v0.z = v17;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
      *(_QWORD *)&this->mEye.mParameter.x = 0i64;
      this->mEye.mParameter.z = 0.0;
      v18 = this->mLook.p1.z;
      x = this->mLook.p1.x;
      this->mLook.p0.y = this->mLook.p1.y;
      this->mLook.p0.z = v18;
      this->mLook.p0.x = x;
      v20 = this->mLook.v1.y;
      v21 = this->mLook.v1.z;
      this->mLook.v0.x = this->mLook.v1.x;
      this->mLook.v0.y = v20;
      this->mLook.v0.z = v21;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
      *(_QWORD *)&this->mLook.mParameter.x = 0i64;
      this->mLook.mParameter.z = 0.0;
      this->mFov.p0 = this->mFov.p1;
      this->mFov.v0 = this->mFov.v1;
      UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
      this->mFov.mParameter = 0.0;
    }
    v22 = UFG::Director::Get();
    UFG::Director::SetCurrentCamera(v22, this);
    mCameraTransform = this->mCameraTransform;
    this->mbScriptCameraOn = 1;
    UFG::TransformNodeComponent::SetLocalTransform(mCameraTransform, &UFG::qMatrix44::msIdentity);
    UFG::TransformNodeComponent::SetParent(this->mCameraTransform, pTNC, eInheritXform_Full);
    if ( UFG::ScriptCameraComponent::mbUserInputEnabled )
      UFG::ScriptCameraComponent::InitUserControlledCamera(this);
    v24 = this->mEye.p0.x;
    v25 = this->mLook.p0.y;
    desLook.x = this->mLook.p0.x;
    v26 = this->mLook.p0.z;
    desEye.x = v24;
    v27 = this->mEye.p0.z;
    desLook.z = v26;
    v28 = this->mEye.p0.y;
    desLook.y = v25;
    desEye.y = v28;
    desEye.z = v27;
    UFG::GameCameraComponent::SetDesiredEyeLookUp(this, 0.0, &desEye, &desLook, &UFG::qVector3::msDirUp, 0, 0i64, 0i64);
  }
}

// File Line: 173
// RVA: 0x3C84B0
void __fastcall UFG::ScriptCameraComponent::ReleaseCamera(UFG::ScriptCameraComponent *this, bool transitionOut)
{
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v5; // rsi
  char v6; // al
  UFG::SimObject *m_pSimObject; // rcx
  UFG::BaseCameraComponent *v8; // rdi
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax
  __int64 v11; // rsi
  UFG::Director *v12; // rax
  __int64 v13; // r8
  UFG::FollowCameraComponent *v14; // rdi
  UFG::Director *v15; // rax
  __int64 v16; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mHighlightedCharacter; // rdx
  float y; // xmm1_4
  float z; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mbScriptCameraOn )
  {
    UFG::ScriptCameraComponent::mbUserInputEnabled = 0;
    if ( this->mbHighlightOn )
      UFG::UnHighlightSimObject(this->mHighlightedCharacter.m_pPointer);
    this->mbProfiling = 0;
    if ( LocalPlayer )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterSubjectComponent::_TypeUID);
      v5 = ComponentOfType;
      if ( ComponentOfType )
      {
        v6 = ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[42].__vecDelDtor)(ComponentOfType);
        m_pSimObject = this->m_pSimObject;
        if ( v6 )
        {
          if ( m_pSimObject )
            v8 = (UFG::BaseCameraComponent *)UFG::SimObject::GetComponentOfType(
                                               m_pSimObject,
                                               UFG::ChaseCameraComponent::_TypeUID);
          else
            v8 = 0i64;
          v9 = v5->m_pSimObject;
          if ( v9 && (v10 = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID)) != 0i64 )
            v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 36i64)
                            + *(_QWORD *)&v10[1].m_TypeUID
                            + 40);
          else
            v11 = 0i64;
          v12 = UFG::Director::Get();
          UFG::Director::SetCurrentCamera(v12, v8);
          if ( transitionOut )
          {
            ((void (__fastcall *)(UFG::BaseCameraComponent *))v8->vfptr[14].__vecDelDtor)(v8);
            v8->vfptr[16].__vecDelDtor(v8, v11);
            ((void (__fastcall *)(UFG::BaseCameraComponent *))v8->vfptr[15].__vecDelDtor)(v8);
            LOBYTE(v13) = 1;
            ((void (__fastcall *)(UFG::BaseCameraComponent *, UFG::ScriptCameraComponent *, __int64))v8->vfptr[29].__vecDelDtor)(
              v8,
              this,
              v13);
          }
        }
        else if ( m_pSimObject )
        {
          v14 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pSimObject,
                                                UFG::FollowCameraComponent::_TypeUID);
          if ( v14 )
          {
            v15 = UFG::Director::Get();
            UFG::Director::SetCurrentCamera(v15, v14);
            if ( transitionOut )
            {
              ((void (__fastcall *)(UFG::FollowCameraComponent *))v14->vfptr[14].__vecDelDtor)(v14);
              UFG::FollowCameraComponent::UpdateLocalWorld(v14, 0.0);
              LOBYTE(v16) = 1;
              ((void (__fastcall *)(UFG::FollowCameraComponent *, UFG::ScriptCameraComponent *, __int64))v14->vfptr[43].__vecDelDtor)(
                v14,
                this,
                v16);
              ((void (__fastcall *)(UFG::FollowCameraComponent *))v14->vfptr[15].__vecDelDtor)(v14);
            }
            else
            {
              v14->vfptr[16].__vecDelDtor(v14, (unsigned int)LocalPlayer);
            }
          }
        }
        this->mDofSnapNext = 1;
        this->mDofParameters.mFocalDistance = 5.0;
        this->mDofParameters.mInFocusRange = 200.0;
        *(_QWORD *)&this->mDofParameters.mNearRange = 1056964608i64;
        this->mDofParameters.mFarRange = 5.0;
        this->mDofParameters.mFarBlurRadius = 4.0;
        p_mHighlightedCharacter = &this->mHighlightedCharacter;
        y = UFG::qVector3::msZero.y;
        z = UFG::qVector3::msZero.z;
        this->mLookOffset.x = UFG::qVector3::msZero.x;
        this->mLookOffset.y = y;
        this->mLookOffset.z = z;
        v20 = UFG::qVector3::msZero.y;
        v21 = UFG::qVector3::msZero.z;
        this->mFollowTargetEyeOffset.x = UFG::qVector3::msZero.x;
        this->mFollowTargetEyeOffset.y = v20;
        this->mFollowTargetEyeOffset.z = v21;
        *(_DWORD *)&this->mbScriptCameraOn = 0;
        if ( this->mHighlightedCharacter.m_pPointer )
        {
          mPrev = p_mHighlightedCharacter->mPrev;
          mNext = this->mHighlightedCharacter.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mHighlightedCharacter->mPrev = p_mHighlightedCharacter;
          this->mHighlightedCharacter.mNext = &this->mHighlightedCharacter;
        }
        this->mHighlightedCharacter.m_pPointer = 0i64;
        this->mbHighlightOn = 0;
      }
    }
  }
}

// File Line: 238
// RVA: 0x3CC100
void __fastcall UFG::ScriptCameraComponent::SetDurations(UFG::ScriptCameraComponent *this, float duration)
{
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rcx
  float v4; // xmm6_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rcx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  UFG::HomerCubic<float> *p_mFov; // rcx
  float v19; // xmm0_4

  p_mEye = &this->mEye;
  v4 = duration;
  v5 = p_mEye->mParameter.y / p_mEye->mDuration.y;
  v6 = p_mEye->mParameter.z / p_mEye->mDuration.z;
  p_mEye->mParameter.x = p_mEye->mParameter.x / p_mEye->mDuration.x;
  p_mEye->mParameter.y = v5;
  p_mEye->mParameter.z = v6;
  if ( duration <= 0.0099999998 )
    v7 = FLOAT_0_0099999998;
  else
    v7 = duration;
  if ( duration <= 0.0099999998 )
    duration = FLOAT_0_0099999998;
  if ( v4 <= 0.0099999998 )
    v8 = FLOAT_0_0099999998;
  else
    v8 = v4;
  p_mEye->mDuration.y = duration;
  p_mEye->mDuration.x = v8;
  p_mEye->mDuration.z = v7;
  v9 = v7 * p_mEye->mParameter.z;
  p_mEye->mParameter.x = v8 * p_mEye->mParameter.x;
  p_mEye->mParameter.z = v9;
  p_mEye->mParameter.y = duration * v5;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
  p_mLook = &this->mLook;
  v11 = this->mLook.mParameter.z / this->mLook.mDuration.z;
  v12 = this->mLook.mParameter.x / this->mLook.mDuration.x;
  this->mLook.mParameter.y = this->mLook.mParameter.y / this->mLook.mDuration.y;
  this->mLook.mParameter.z = v11;
  this->mLook.mParameter.x = v12;
  if ( v4 <= 0.0099999998 )
    v13 = FLOAT_0_0099999998;
  else
    v13 = v4;
  if ( v4 <= 0.0099999998 )
    v14 = FLOAT_0_0099999998;
  else
    v14 = v4;
  if ( v4 <= 0.0099999998 )
    v15 = FLOAT_0_0099999998;
  else
    v15 = v4;
  p_mLook->mDuration.x = v15;
  this->mLook.mDuration.y = v14;
  this->mLook.mDuration.z = v13;
  v16 = v14 * this->mLook.mParameter.y;
  v17 = v13 * this->mLook.mParameter.z;
  this->mLook.mParameter.x = v15 * this->mLook.mParameter.x;
  this->mLook.mParameter.y = v16;
  this->mLook.mParameter.z = v17;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  p_mFov = &this->mFov;
  v19 = this->mFov.mParameter / this->mFov.mDuration;
  this->mFov.mParameter = v19;
  if ( v4 <= 0.0099999998 )
    v4 = FLOAT_0_0099999998;
  p_mFov->mDuration = v4;
  this->mFov.mParameter = v4 * v19;
  UFG::HomerCubic<float>::MakeCoeffs(p_mFov);
}

// File Line: 246
// RVA: 0x3C7B80
void __fastcall UFG::ScriptCameraComponent::PanToTransform(
        UFG::ScriptCameraComponent *this,
        UFG::TransformNodeComponent *pTNC,
        float duration,
        float fov)
{
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rcx
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rcx
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4

  UFG::TransformNodeComponent::SetLocalTransform(this->mNextCameraTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(this->mNextCameraTransform, pTNC, eInheritXform_Full);
  p_mEye = &this->mEye;
  this->mbPanning = 1;
  v8 = this->mEye.mParameter.y / this->mEye.mDuration.y;
  v9 = this->mEye.mParameter.z / this->mEye.mDuration.z;
  this->mEye.mParameter.x = this->mEye.mParameter.x / this->mEye.mDuration.x;
  this->mEye.mParameter.y = v8;
  this->mEye.mParameter.z = v9;
  if ( duration <= 0.0099999998 )
    v10 = FLOAT_0_0099999998;
  else
    v10 = duration;
  if ( duration <= 0.0099999998 )
    v11 = FLOAT_0_0099999998;
  else
    v11 = duration;
  if ( duration <= 0.0099999998 )
    v12 = FLOAT_0_0099999998;
  else
    v12 = duration;
  p_mEye->mDuration.x = v12;
  this->mEye.mDuration.y = v11;
  this->mEye.mDuration.z = v10;
  v13 = v11 * this->mEye.mParameter.y;
  v14 = v10 * this->mEye.mParameter.z;
  this->mEye.mParameter.x = v12 * this->mEye.mParameter.x;
  this->mEye.mParameter.y = v13;
  this->mEye.mParameter.z = v14;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
  p_mLook = &this->mLook;
  v16 = this->mLook.mParameter.z / this->mLook.mDuration.z;
  v17 = this->mLook.mParameter.x / this->mLook.mDuration.x;
  this->mLook.mParameter.y = this->mLook.mParameter.y / this->mLook.mDuration.y;
  this->mLook.mParameter.z = v16;
  this->mLook.mParameter.x = v17;
  if ( duration <= 0.0099999998 )
    v18 = FLOAT_0_0099999998;
  else
    v18 = duration;
  if ( duration <= 0.0099999998 )
    v19 = FLOAT_0_0099999998;
  else
    v19 = duration;
  if ( duration <= 0.0099999998 )
    v20 = FLOAT_0_0099999998;
  else
    v20 = duration;
  p_mLook->mDuration.x = v20;
  this->mLook.mDuration.y = v19;
  this->mLook.mDuration.z = v18;
  v21 = v19 * this->mLook.mParameter.y;
  v22 = v18 * this->mLook.mParameter.z;
  this->mLook.mParameter.x = v20 * this->mLook.mParameter.x;
  this->mLook.mParameter.y = v21;
  this->mLook.mParameter.z = v22;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  if ( fov != 0.0 )
  {
    v23 = this->mFov.mParameter / this->mFov.mDuration;
    this->mFov.mParameter = v23;
    if ( duration <= 0.0099999998 )
      duration = FLOAT_0_0099999998;
    this->mFov.mDuration = duration;
    this->mFov.mParameter = duration * v23;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.p1 = fov;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.mParameter = 0.0;
  }
}

// File Line: 263
// RVA: 0x3CD600
void __fastcall UFG::ScriptCameraComponent::SetTarget(
        UFG::ScriptCameraComponent *this,
        UFG::TransformNodeComponent *pTNC)
{
  UFG::qSafePointer<Creature,Creature> *p_mTargetCreature; // r9
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rax

  p_mTargetCreature = &this->mTargetCreature;
  if ( this->mTargetCreature.m_pPointer )
  {
    mPrev = p_mTargetCreature->mPrev;
    mNext = this->mTargetCreature.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTargetCreature->mPrev = p_mTargetCreature;
    this->mTargetCreature.mNext = &this->mTargetCreature;
  }
  this->mTargetCreature.m_pPointer = 0i64;
  UFG::TransformNodeComponent::SetLocalTransform(this->mTargetTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(this->mTargetTransform, pTNC, eInheritXform_Full);
  this->mbFollowTarget = 1;
}

// File Line: 271
// RVA: 0x3CC480
void __fastcall UFG::ScriptCameraComponent::SetEyeOffsetFromTarget(
        UFG::ScriptCameraComponent *this,
        UFG::qVector3 *offset)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = offset->y;
  z = offset->z;
  this->mFollowTargetEyeOffset.x = offset->x;
  this->mFollowTargetEyeOffset.y = y;
  this->mFollowTargetEyeOffset.z = z;
  this->mbFollowTargetEyeOffset = 1;
}

// File Line: 286
// RVA: 0x3C9830
void __fastcall UFG::ScriptCameraComponent::SetCameraCreature(
        UFG::ScriptCameraComponent *this,
        Creature *creature,
        int bone_id)
{
  UFG::qSafePointer<Creature,Creature> *p_mCameraCreature; // r10
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::TransformNodeComponent *mCameraTransform; // rcx

  p_mCameraCreature = &this->mCameraCreature;
  if ( this->mCameraCreature.m_pPointer )
  {
    mPrev = p_mCameraCreature->mPrev;
    mNext = this->mCameraCreature.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCameraCreature->mPrev = p_mCameraCreature;
    this->mCameraCreature.mNext = &this->mCameraCreature;
  }
  this->mCameraCreature.m_pPointer = creature;
  if ( creature )
  {
    v7 = creature->m_SafePointerList.mNode.mPrev;
    v7->mNext = p_mCameraCreature;
    p_mCameraCreature->mPrev = v7;
    this->mCameraCreature.mNext = &creature->m_SafePointerList.mNode;
    creature->m_SafePointerList.mNode.mPrev = p_mCameraCreature;
  }
  mCameraTransform = this->mCameraTransform;
  this->nCameraCreatureBone = bone_id;
  UFG::TransformNodeComponent::SetLocalTransform(mCameraTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(this->mCameraTransform, 0i64, eInheritXform_Full);
  this->mbAttached = 1;
}

// File Line: 295
// RVA: 0x3CC400
void __fastcall UFG::ScriptCameraComponent::SetEyeAttachment(
        UFG::ScriptCameraComponent *this,
        UFG::TransformNodeComponent *pTNC)
{
  UFG::qSafePointer<Creature,Creature> *p_mCameraCreature; // r9
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rax

  p_mCameraCreature = &this->mCameraCreature;
  if ( this->mCameraCreature.m_pPointer )
  {
    mPrev = p_mCameraCreature->mPrev;
    mNext = this->mCameraCreature.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCameraCreature->mPrev = p_mCameraCreature;
    this->mCameraCreature.mNext = &this->mCameraCreature;
  }
  this->mCameraCreature.m_pPointer = 0i64;
  UFG::TransformNodeComponent::SetLocalTransform(this->mCameraTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(this->mCameraTransform, pTNC, eInheritXform_Full);
  this->mbAttached = 1;
}

// File Line: 303
// RVA: 0x3C8CE0
void __fastcall UFG::ScriptCameraComponent::ResetDOF(UFG::ScriptCameraComponent *this)
{
  this->mDofSnapNext = 1;
  this->mDofParameters.mFocalDistance = 5.0;
  this->mDofParameters.mInFocusRange = 200.0;
  *(_QWORD *)&this->mDofParameters.mNearRange = 0x3F000000i64;
  this->mDofParameters.mFarRange = 5.0;
  this->mDofParameters.mFarBlurRadius = 4.0;
}

// File Line: 314
// RVA: 0x3CB030
void __fastcall UFG::ScriptCameraComponent::SetDOF(
        UFG::ScriptCameraComponent *this,
        float focalDistance,
        float inFocusHalfRange,
        float nearBlendRange,
        float nearBlurRadius,
        float farBlendRange,
        float farBlurRadius,
        bool snap)
{
  this->mDofParameters.mFocalDistance = focalDistance;
  this->mDofParameters.mNearBlurRadius = nearBlurRadius;
  this->mDofSnapNext = snap;
  this->mDofParameters.mInFocusRange = inFocusHalfRange * 2.0;
  this->mDofParameters.mNearRange = nearBlendRange;
  this->mDofParameters.mFarBlurRadius = farBlurRadius;
  this->mDofParameters.mFarRange = farBlendRange;
}

// File Line: 326
// RVA: 0x3CB090
void __fastcall UFG::ScriptCameraComponent::SetDesiredEyeLook(
        UFG::ScriptCameraComponent *this,
        UFG::qVector3 *eye,
        UFG::qVector3 *look,
        float duration,
        bool snap)
{
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rbp
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rdi
  float x; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4

  UFG::ScriptCameraComponent::SetDurations(this, duration);
  y = eye->y;
  z = eye->z;
  p_mEye = &this->mEye;
  this->mEye.p1.x = eye->x;
  this->mEye.p1.y = y;
  this->mEye.p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  p_mLook = &this->mLook;
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
  x = look->x;
  v13 = look->z;
  p_mLook->p1.y = look->y;
  p_mLook->p1.z = v13;
  p_mLook->p1.x = x;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
  if ( snap )
  {
    v14 = p_mEye->p1.y;
    v15 = p_mEye->p1.z;
    p_mEye->p0.x = p_mEye->p1.x;
    p_mEye->p0.y = v14;
    p_mEye->p0.z = v15;
    v16 = p_mEye->v1.y;
    v17 = p_mEye->v1.z;
    p_mEye->v0.x = p_mEye->v1.x;
    p_mEye->v0.y = v16;
    p_mEye->v0.z = v17;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
    *(_QWORD *)&p_mEye->mParameter.x = 0i64;
    p_mEye->mParameter.z = 0.0;
    v18 = p_mLook->p1.z;
    v19 = p_mLook->p1.x;
    p_mLook->p0.y = p_mLook->p1.y;
    p_mLook->p0.z = v18;
    p_mLook->p0.x = v19;
    v20 = p_mLook->v1.y;
    v21 = p_mLook->v1.z;
    p_mLook->v0.x = p_mLook->v1.x;
    p_mLook->v0.y = v20;
    p_mLook->v0.z = v21;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
    *(_QWORD *)&p_mLook->mParameter.x = 0i64;
    p_mLook->mParameter.z = 0.0;
  }
}

// File Line: 338
// RVA: 0x3D7370
void __fastcall UFG::ScriptCameraComponent::Update(UFG::ScriptCameraComponent *this, float delta_sec)
{
  Creature *m_pPointer; // rcx
  Creature *v5; // rcx
  UFG::TransformNodeComponent *mTargetTransform; // rbx
  float y; // xmm0_4
  float z; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  UFG::TransformNodeComponent *v13; // rbx
  float v14; // xmm13_4
  float v15; // xmm14_4
  float v16; // xmm13_4
  float v17; // xmm12_4
  UFG::TransformNodeComponent *v18; // rbx
  float v19; // xmm8_4
  float v20; // xmm9_4
  float v21; // xmm11_4
  UFG::TransformNodeComponent *v22; // rbx
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm10_4
  UFG::TransformNodeComponent *v26; // rbx
  float v27; // xmm12_4
  float v28; // xmm14_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  UFG::TransformNodeComponent *mCameraTransform; // rbx
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  UFG::TransformNodeComponent *v38; // rbx
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  UFG::TransformNodeComponent *v45; // rdi
  UFG::TransformNodeComponent *v46; // rbx
  float v47; // xmm1_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  UFG::TransformNodeComponent *mNextCameraTransform; // rbx
  float v54; // xmm0_4
  float v55; // xmm1_4
  UFG::TransformNodeComponent *v56; // rdi
  UFG::TransformNodeComponent *v57; // rbx
  float v58; // xmm1_4
  float v59; // xmm0_4
  float ExtraWideAspectCorrectedFOV; // xmm9_4
  float DisplayAspectRatio; // xmm12_4
  bool v62; // r9
  UFG::qVector3 *Value; // rax
  float x; // xmm7_4
  float mEyeNoiseMagnitude; // xmm0_4
  float v66; // xmm5_4
  float v67; // xmm4_4
  float v68; // xmm3_4
  float v69; // xmm7_4
  __int128 y_low; // xmm10
  __m128 v71; // xmm2
  float v72; // xmm1_4
  float v73; // xmm7_4
  float v74; // xmm10_4
  float v75; // xmm4_4
  float v76; // xmm6_4
  float v77; // xmm7_4
  float v78; // xmm8_4
  UFG::qVector3 *v79; // rax
  float mLookNoiseMagnitude; // xmm2_4
  float v81; // xmm3_4
  float v82; // xmm2_4
  UFG::qVector3 desLook; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 turn; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 desEye; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-90h] BYREF

  if ( !this->mActive
    || UFG::gFlowController.mCurrentState
    && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
  {
    return;
  }
  UFG::GameCameraComponent::Update(this, delta_sec);
  m_pPointer = this->mTargetCreature.m_pPointer;
  this->mElapsedSeconds = delta_sec + this->mElapsedSeconds;
  if ( m_pPointer )
  {
    Creature::GetTransform(m_pPointer, this->nTargetCreatureBone, &transform);
    UFG::TransformNodeComponent::SetWorldTransform(this->mTargetTransform, &transform);
  }
  v5 = this->mCameraCreature.m_pPointer;
  if ( v5 )
  {
    Creature::GetTransform(v5, this->nCameraCreatureBone, &transform);
    UFG::TransformNodeComponent::SetWorldTransform(this->mCameraTransform, &transform);
  }
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mLook, delta_sec);
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mEye, delta_sec);
  UFG::HomerCubic<float>::Update(&this->mFov, delta_sec);
  if ( this->mbFollowTarget )
  {
    mTargetTransform = this->mTargetTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(mTargetTransform);
    y = mTargetTransform->mWorldTransform.v3.y;
    z = mTargetTransform->mWorldTransform.v3.z;
    this->mLook.p1.x = mTargetTransform->mWorldTransform.v3.x;
    this->mLook.p1.y = y;
    this->mLook.p1.z = z;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
    *(_QWORD *)&this->mLook.mParameter.x = 0i64;
    this->mLook.mParameter.z = 0.0;
    v9 = this->mLook.p1.y;
    v10 = this->mLook.p1.z;
    this->mLook.p0.x = this->mLook.p1.x;
    this->mLook.p0.y = v9;
    this->mLook.p0.z = v10;
    v11 = this->mLook.v1.y;
    v12 = this->mLook.v1.z;
    this->mLook.v0.x = this->mLook.v1.x;
    this->mLook.v0.y = v11;
    this->mLook.v0.z = v12;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
    *(_QWORD *)&this->mLook.mParameter.x = 0i64;
    this->mLook.mParameter.z = 0.0;
    if ( this->mbFollowTargetEyeOffset )
    {
      v13 = this->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      v14 = this->mFollowTargetEyeOffset.z;
      v15 = v14 * v13->mWorldTransform.v2.z;
      v16 = v14 * v13->mWorldTransform.v2.x;
      v17 = this->mFollowTargetEyeOffset.z * v13->mWorldTransform.v2.y;
      v18 = this->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v18);
      v19 = this->mFollowTargetEyeOffset.y * v18->mWorldTransform.v1.x;
      v20 = this->mFollowTargetEyeOffset.y * v18->mWorldTransform.v1.y;
      v21 = this->mFollowTargetEyeOffset.y * v18->mWorldTransform.v1.z;
      v22 = this->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v22);
      v23 = this->mFollowTargetEyeOffset.x * v22->mWorldTransform.v0.x;
      v24 = this->mFollowTargetEyeOffset.x * v22->mWorldTransform.v0.y;
      v25 = this->mFollowTargetEyeOffset.x * v22->mWorldTransform.v0.z;
      v26 = this->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v26);
      v27 = v17 + (float)((float)(v24 + v26->mWorldTransform.v3.y) + v20);
      v28 = v15 + (float)((float)(v25 + v26->mWorldTransform.v3.z) + v21);
      this->mEye.p1.x = v16 + (float)((float)(v23 + v26->mWorldTransform.v3.x) + v19);
      this->mEye.p1.y = v27;
      this->mEye.p1.z = v28;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
      *(_QWORD *)&this->mEye.mParameter.x = 0i64;
      this->mEye.mParameter.z = 0.0;
      v29 = this->mEye.p1.y;
      v30 = this->mEye.p1.z;
      this->mEye.p0.x = this->mEye.p1.x;
      this->mEye.p0.y = v29;
      this->mEye.p0.z = v30;
      v31 = this->mEye.v1.y;
      v32 = this->mEye.v1.z;
      this->mEye.v0.x = this->mEye.v1.x;
      this->mEye.v0.y = v31;
      this->mEye.v0.z = v32;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
LABEL_13:
      this->mEye.mParameter.z = 0.0;
      *(_QWORD *)&this->mEye.mParameter.x = 0i64;
      goto LABEL_14;
    }
    if ( !this->mbPanning )
    {
      mCameraTransform = this->mCameraTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(mCameraTransform);
      UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(
        &this->mEye,
        (UFG::qVector3 *)&mCameraTransform->mWorldTransform.v3);
      v34 = this->mEye.p1.y;
      v35 = this->mEye.p1.z;
      this->mEye.p0.x = this->mEye.p1.x;
      this->mEye.p0.y = v34;
      this->mEye.p0.z = v35;
      v36 = this->mEye.v1.y;
      v37 = this->mEye.v1.z;
      this->mEye.v0.x = this->mEye.v1.x;
      this->mEye.v0.y = v36;
      this->mEye.v0.z = v37;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
      goto LABEL_13;
    }
  }
LABEL_14:
  if ( this->mbAttached )
  {
    v38 = this->mCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v38);
    v39 = v38->mWorldTransform.v3.y;
    v40 = v38->mWorldTransform.v3.z;
    this->mEye.p1.x = v38->mWorldTransform.v3.x;
    this->mEye.p1.y = v39;
    this->mEye.p1.z = v40;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
    if ( !this->mbPanning )
    {
      v41 = this->mEye.p1.y;
      v42 = this->mEye.p1.z;
      this->mEye.p0.x = this->mEye.p1.x;
      this->mEye.p0.y = v41;
      this->mEye.p0.z = v42;
      v43 = this->mEye.v1.y;
      v44 = this->mEye.v1.z;
      this->mEye.v0.x = this->mEye.v1.x;
      this->mEye.v0.y = v43;
      this->mEye.v0.z = v44;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
      *(_QWORD *)&this->mEye.mParameter.x = 0i64;
      this->mEye.mParameter.z = 0.0;
    }
    v45 = this->mCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v45);
    v46 = this->mCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v46);
    v47 = v46->mWorldTransform.v3.y + v45->mWorldTransform.v0.y;
    v48 = v46->mWorldTransform.v3.z + v45->mWorldTransform.v0.z;
    this->mLook.p1.x = v46->mWorldTransform.v3.x + v45->mWorldTransform.v0.x;
    this->mLook.p1.y = v47;
    this->mLook.p1.z = v48;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
    *(_QWORD *)&this->mLook.mParameter.x = 0i64;
    this->mLook.mParameter.z = 0.0;
    v49 = this->mLook.p1.y;
    v50 = this->mLook.p1.z;
    this->mLook.p0.x = this->mLook.p1.x;
    this->mLook.p0.y = v49;
    this->mLook.p0.z = v50;
    v51 = this->mLook.v1.y;
    v52 = this->mLook.v1.z;
    this->mLook.v0.x = this->mLook.v1.x;
    this->mLook.v0.y = v51;
    this->mLook.v0.z = v52;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
    *(_QWORD *)&this->mLook.mParameter.x = 0i64;
    this->mLook.mParameter.z = 0.0;
  }
  if ( this->mbPanning )
  {
    mNextCameraTransform = this->mNextCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(mNextCameraTransform);
    v54 = mNextCameraTransform->mWorldTransform.v3.y;
    v55 = mNextCameraTransform->mWorldTransform.v3.z;
    this->mEye.p1.x = mNextCameraTransform->mWorldTransform.v3.x;
    this->mEye.p1.y = v54;
    this->mEye.p1.z = v55;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
    if ( !this->mbFollowTarget )
    {
      v56 = this->mNextCameraTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v56);
      v57 = this->mNextCameraTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v57);
      v58 = v57->mWorldTransform.v3.y + v56->mWorldTransform.v0.y;
      v59 = v57->mWorldTransform.v3.z + v56->mWorldTransform.v0.z;
      this->mLook.p1.x = v57->mWorldTransform.v3.x + v56->mWorldTransform.v0.x;
      this->mLook.p1.y = v58;
      this->mLook.p1.z = v59;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
      *(_QWORD *)&this->mLook.mParameter.x = 0i64;
      this->mLook.mParameter.z = 0.0;
    }
  }
  ExtraWideAspectCorrectedFOV = (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    ExtraWideAspectCorrectedFOV = Render::GetExtraWideAspectCorrectedFOV(ExtraWideAspectCorrectedFOV);
  DisplayAspectRatio = Render::GetDisplayAspectRatio();
  if ( UFG::ScriptCameraComponent::mbUserInputEnabled )
  {
    turn = UFG::qVector3::msZero;
    UFG::ScriptCameraComponent::UpdateInput(this, delta_sec, &turn);
    UFG::ScriptCameraComponent::UpdateMovement(this, &turn);
    UFG::Camera::SetViewProjection(
      &this->mCamera,
      ExtraWideAspectCorrectedFOV,
      DisplayAspectRatio,
      UFG::gCameraDefaultNear,
      UFG::gCameraDefaultFar,
      0.0,
      0.0,
      1);
  }
  else
  {
    v62 = 0;
    if ( this->mDofSnapNext )
    {
      v62 = 1;
      this->mDofSnapNext = 0;
    }
    UFG::GameCameraComponent::UpdateDof(this, delta_sec, &this->mDofParameters, v62);
    Value = UFG::qNoise<UFG::qVector3,float>::GetValue(&this->mEyeNoise, &turn, this->mElapsedSeconds);
    x = this->mLook.p0.x;
    y_low = LODWORD(this->mLook.p0.y);
    mEyeNoiseMagnitude = this->mEyeNoiseMagnitude;
    v66 = this->mEye.p0.z + (float)(mEyeNoiseMagnitude * Value->z);
    v67 = this->mEye.p0.y + (float)(mEyeNoiseMagnitude * Value->y);
    v68 = this->mEye.p0.x + (float)(mEyeNoiseMagnitude * Value->x);
    desLook.z = this->mLook.p0.z;
    desLook.x = x;
    v69 = x - v68;
    LODWORD(desLook.y) = y_low;
    *(float *)&y_low = *(float *)&y_low - v67;
    v71 = (__m128)y_low;
    desEye.x = v68;
    v71.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v69 * v69))
                    + (float)((float)(desLook.z - v66) * (float)(desLook.z - v66));
    desEye.y = v67;
    desEye.z = v66;
    if ( v71.m128_f32[0] == 0.0 )
      v72 = 0.0;
    else
      v72 = 1.0 / _mm_sqrt_ps(v71).m128_f32[0];
    v73 = v69 * v72;
    v74 = *(float *)&y_low * v72;
    v75 = this->mLookOffset.z * 0.0;
    v76 = (float)((float)(this->mLookOffset.x * v73) + (float)(this->mLookOffset.y * v74)) + v75;
    v77 = (float)((float)(this->mLookOffset.x * v74)
                + (float)(this->mLookOffset.y * COERCE_FLOAT(LODWORD(v73) ^ _xmm[0])))
        + v75;
    v78 = (float)((float)(this->mLookOffset.x * 0.0) + (float)(this->mLookOffset.y * 0.0)) + this->mLookOffset.z;
    v79 = UFG::qNoise<UFG::qVector3,float>::GetValue(&this->mLookNoise, &turn, this->mElapsedSeconds + 511.0);
    mLookNoiseMagnitude = this->mLookNoiseMagnitude;
    v81 = mLookNoiseMagnitude * v79->z;
    v82 = (float)(mLookNoiseMagnitude * v79->y) + v77;
    desLook.x = desLook.x + (float)((float)(this->mLookNoiseMagnitude * v79->x) + v76);
    desLook.y = desLook.y + v82;
    desLook.z = desLook.z + (float)(v81 + v78);
    UFG::GameCameraComponent::SetDesiredEyeLookUp(this, 0.0, &desEye, &desLook, &UFG::qVector3::msDirUp, 0, 0i64, 0i64);
    UFG::Camera::SetViewProjection(
      &this->mCamera,
      ExtraWideAspectCorrectedFOV,
      DisplayAspectRatio,
      UFG::gCameraDefaultNear,
      UFG::gCameraDefaultFar,
      0.0,
      0.0,
      1);
    UFG::Camera::ApplyDutch(&this->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
  }
}

// File Line: 468
// RVA: 0x3C5D40
void __fastcall UFG::ScriptCameraComponent::InitUserControlledCamera(UFG::ScriptCameraComponent *this)
{
  UFG::TransformNodeComponent *mCameraTransform; // rbx
  __m128 x_low; // xmm1

  UFG::TransformNodeComponent::UpdateWorldTransform(this->mCameraTransform);
  mCameraTransform = this->mCameraTransform;
  UFG::TransformNodeComponent::UpdateWorldTransform(mCameraTransform);
  x_low = (__m128)LODWORD(mCameraTransform->mWorldTransform.v0.x);
  x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                    + (float)(mCameraTransform->mWorldTransform.v0.y * mCameraTransform->mWorldTransform.v0.y);
  this->mLatitude = atan2f(mCameraTransform->mWorldTransform.v0.z, _mm_sqrt_ps(x_low).m128_f32[0]);
  this->mLongitude = atan2f(mCameraTransform->mWorldTransform.v0.y, mCameraTransform->mWorldTransform.v0.x);
  *(_QWORD *)&this->mTurnX = 0i64;
}

// File Line: 482
// RVA: 0x3DCC20
void __fastcall UFG::ScriptCameraComponent::UpdateInput(
        UFG::ScriptCameraComponent *this,
        const float delta_sec,
        UFG::qVector3 *turn)
{
  __int64 v3; // r9
  UFG::InputActionData *v4; // rax
  float v6; // xmm4_4
  __int64 v7; // rdx
  UFG::InputActionData *v8; // rax
  float mAxisPositionX; // xmm1_4
  UFG::InputSystem *v10; // r10
  UFG::InputActionData *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float mAxisPositionY; // xmm3_4
  UFG::InputActionData *v15; // rax
  float v16; // xmm3_4
  UFG::InputActionData *v17; // rax
  float v18; // xmm0_4
  UFG::InputActionData *v19; // rax
  unsigned __int8 v20; // cl
  bool v21; // al
  __m128i v22; // xmm3
  UFG::InputActionData *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4

  v3 = (int)UFG::gActiveControllerNum;
  v4 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
  v6 = delta_sec * 0.40000001;
  v7 = (int)UFG::gActiveControllerNum;
  if ( v4 && v4->mActionTrue )
  {
    turn->x = turn->x - (float)(v4->mAxisPositionY * v6);
    v8 = UFG::ActionDef_UIRightThumbstick.mDataPerController[v3];
    if ( v8 )
      mAxisPositionX = v8->mAxisPositionX;
    else
      mAxisPositionX = 0.0;
    turn->y = turn->y - (float)(mAxisPositionX * v6);
    LODWORD(v3) = UFG::gActiveControllerNum;
  }
  v10 = UFG::gInputSystem;
  if ( UFG::gInputSystem->mControllers[(int)v3]->m_IsKeyboardController )
  {
    v11 = UFG::ActionDef_Mouse.mDataPerController[(int)v3];
    if ( v11 )
      v12 = v11->mAxisPositionX;
    else
      v12 = 0.0;
    v13 = v12 * UFG::gMousePosMultiplier;
    if ( v11 )
      mAxisPositionY = v11->mAxisPositionY;
    else
      mAxisPositionY = 0.0;
    turn->x = turn->x - (float)((float)(mAxisPositionY * UFG::gMousePosMultiplier) * v6);
    turn->y = turn->y - (float)(v13 * v6);
    LODWORD(v3) = UFG::gActiveControllerNum;
    v10 = UFG::gInputSystem;
  }
  v15 = UFG::ActionDef_UIR2Repeat.mDataPerController[v7];
  if ( v15 )
    v16 = v15->mAxisPositionX;
  else
    v16 = 0.0;
  v17 = UFG::ActionDef_UIL2Repeat.mDataPerController[v7];
  if ( v17 )
    v18 = v17->mAxisPositionX;
  else
    v18 = 0.0;
  if ( v10->mControllers[(int)v3]->m_IsKeyboardController )
  {
    v19 = UFG::ActionDef_CamZoomIn.mDataPerController[v7];
    v20 = 1;
    v21 = v19 && v19->mActionTrue;
    v22 = _mm_cvtsi32_si128(v21);
    v23 = UFG::ActionDef_CamZoomOut.mDataPerController[v7];
    v16 = _mm_cvtepi32_ps(v22).m128_f32[0] * UFG::gMouseZoomMultiplier;
    if ( !v23 || !v23->mActionTrue )
      v20 = 0;
    v18 = (float)v20 * UFG::gMouseZoomMultiplier;
  }
  if ( v16 <= 0.0 )
  {
    if ( v18 <= 0.0 )
      return;
    v25 = v18 + this->mFov.p1;
    if ( v25 <= 35.0 )
    {
      v25 = FLOAT_35_0;
    }
    else
    {
      v26 = FLOAT_85_0;
      if ( v25 >= 85.0 )
        goto LABEL_42;
    }
    v26 = v25;
LABEL_42:
    this->mFov.p1 = v26;
    goto LABEL_43;
  }
  v24 = this->mFov.p1 - v16;
  if ( v24 <= 35.0 )
  {
    v24 = FLOAT_35_0;
    goto LABEL_35;
  }
  if ( v24 < 85.0 )
  {
LABEL_35:
    this->mFov.p1 = v24;
    goto LABEL_43;
  }
  this->mFov.p1 = FLOAT_85_0;
LABEL_43:
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
}

// File Line: 610
// RVA: 0x3DD2B0
void __fastcall UFG::ScriptCameraComponent::UpdateMovement(UFG::ScriptCameraComponent *this, UFG::qVector3 *turn)
{
  float v3; // xmm0_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm9_4
  float v12; // xmm0_4
  float x; // xmm3_4
  float y; // xmm2_4
  float z; // xmm1_4
  float v16; // xmm7_4
  UFG::SimObject *v17; // r13
  __int64 v18; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mHighlightedCharacter; // r15
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  float v22; // xmm1_4
  float v23; // xmm2_4
  __int64 v24; // rsi
  UFG::SimObject **v25; // r14
  UFG::SimObjectGame *v26; // rbx
  UFG::CharacterSubjectComponent *ComponentOfType; // rax
  UFG::CharacterSubjectComponent *v28; // r14
  float v29; // xmm6_4
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  float v32; // xmm1_4
  float v33; // xmm2_4
  __int64 v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rax
  __int64 i; // rax
  _QWORD *v39; // rdx
  __int64 v40; // rcx
  _QWORD *v41; // rax
  _QWORD *v42; // rcx
  _QWORD *v43; // rax
  UFG::qVector3 eye; // [rsp+28h] [rbp-79h] BYREF
  float v45; // [rsp+34h] [rbp-6Dh]
  float ray_dir; // [rsp+38h] [rbp-69h]
  _QWORD *ray_dir_8; // [rsp+40h] [rbp-61h] BYREF
  UFG::HighlightParams highlight_params; // [rsp+48h] [rbp-59h] BYREF
  float v49; // [rsp+64h] [rbp-3Dh]
  float v50; // [rsp+68h] [rbp-39h]
  UFG::HighlightParams v51; // [rsp+70h] [rbp-31h] BYREF
  __int64 v52; // [rsp+108h] [rbp+67h]

  v3 = turn->x + this->mTurnX;
  if ( v3 <= -0.39269909 )
  {
    v3 = FLOAT_N0_39269909;
    goto LABEL_5;
  }
  v4 = FLOAT_0_39269909;
  if ( v3 < 0.39269909 )
LABEL_5:
    v4 = v3;
  this->mTurnX = v4;
  v5 = turn->y + this->mTurnY;
  if ( v5 <= -0.78539819 )
  {
    v5 = FLOAT_N0_78539819;
    goto LABEL_10;
  }
  v6 = FLOAT_0_78539819;
  if ( v5 < 0.78539819 )
LABEL_10:
    v6 = v5;
  this->mTurnY = v6;
  v7 = v4 + this->mLatitude;
  v8 = v6 + this->mLongitude;
  v9 = sinf(v7);
  v10 = cosf(v7);
  v11 = sinf(v8);
  v12 = cosf(v8);
  *(float *)&highlight_params.mIsDepthEnabled = v12 * v10;
  v49 = v11 * v10;
  v50 = v9;
  eye.z = (float)((float)(v11 * v10) * 0.0) - (float)(v12 * v9);
  v45 = (float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v9) - (float)((float)(v12 * v10) * 0.0);
  ray_dir = (float)((float)(v12 * v10) * v12) - (float)((float)(v11 * v10) * COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]));
  x = this->mEye.p0.x;
  y = this->mEye.p0.y;
  z = this->mEye.p0.z;
  *(float *)&ray_dir_8 = (float)(v12 * v10) + x;
  *((float *)&ray_dir_8 + 1) = (float)(v11 * v10) + y;
  highlight_params.mColour.r = z + v9;
  highlight_params.mColour.b = x;
  highlight_params.mColour.a = y;
  highlight_params.mOutlineStrength = z;
  UFG::Camera::SetLookAtMatrix(
    &this->mCamera,
    (UFG::qVector3 *)&highlight_params.mColour.b,
    (UFG::qVector3 *)&ray_dir_8,
    (UFG::qVector3 *)&eye.z);
  if ( this->mbProfiling )
  {
    v16 = FLOAT_1_0e8;
    v17 = 0i64;
    v18 = 0i64;
    v52 = 0i64;
    p_mHighlightedCharacter = &this->mHighlightedCharacter;
    if ( this->mHighlightedCharacter.m_pPointer )
    {
      mPrev = p_mHighlightedCharacter->mPrev;
      mNext = this->mHighlightedCharacter.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mHighlightedCharacter->mPrev = p_mHighlightedCharacter;
      this->mHighlightedCharacter.mNext = &this->mHighlightedCharacter;
    }
    this->mHighlightedCharacter.m_pPointer = 0i64;
    this->mbHighlightOn = 0;
    ray_dir_8 = &ray_dir_8;
    *(_QWORD *)&highlight_params.mColour.r = &ray_dir_8;
    v22 = this->mEye.p0.y;
    v23 = this->mEye.p0.z;
    highlight_params.mColour.b = this->mEye.p0.x;
    highlight_params.mColour.a = v22;
    highlight_params.mOutlineStrength = v23;
    UFG::NearbyCharacterManager::GetNearbyCharactersAll(
      UFG::NearbyCharacterManager::s_pInstance,
      (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&ray_dir_8,
      (UFG::qVector3 *)&highlight_params.mColour.b);
    v24 = *(_QWORD *)&highlight_params.mColour.r - 16i64;
    if ( (UFG::qVector3 *)(*(_QWORD *)&highlight_params.mColour.r - 16i64) != (UFG::qVector3 *)&eye.z )
    {
      do
      {
        v25 = *(UFG::SimObject ***)(v24 + 48);
        if ( v25 )
        {
          v26 = (UFG::SimObjectGame *)v25[5];
          if ( !v26 )
            goto LABEL_34;
          UFG::UnHighlightSimObject(v25[5]);
          if ( !((unsigned __int8 (__fastcall *)(UFG::SimObject **))(*v25)->m_UnboundComponentHandles.mNode.mPrev)(v25) )
            goto LABEL_34;
          ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                v26,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
          v28 = ComponentOfType;
          if ( !ComponentOfType )
            goto LABEL_34;
          if ( ComponentOfType->mPelvisDirty )
            UFG::CharacterSubjectComponent::UpdatePelvis(ComponentOfType);
          v29 = (float)((float)((float)(this->mEye.p0.y - v28->mPelvisPosition.y)
                              * (float)(this->mEye.p0.y - v28->mPelvisPosition.y))
                      + (float)((float)(this->mEye.p0.x - v28->mPelvisPosition.x)
                              * (float)(this->mEye.p0.x - v28->mPelvisPosition.x)))
              + (float)((float)(this->mEye.p0.z - v28->mPelvisPosition.z)
                      * (float)(this->mEye.p0.z - v28->mPelvisPosition.z));
          if ( v29 > 3600.0 )
            goto LABEL_34;
          m_Flags = v26->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
            m_pComponent = v26->m_Components.p[44].m_pComponent;
          else
            m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                         ? UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::CharacterOccupantComponent::_TypeUID)
                         : UFG::SimObject::GetComponentOfType(v26, UFG::CharacterOccupantComponent::_TypeUID);
          if ( !m_pComponent
            && (v32 = this->mEye.p0.y,
                v33 = this->mEye.p0.z,
                highlight_params.mColour.b = this->mEye.p0.x,
                highlight_params.mColour.a = v32,
                highlight_params.mOutlineStrength = v33,
                UFG::qDistanceRayPoint(
                  (UFG::qVector3 *)&highlight_params.mColour.b,
                  (UFG::qVector3 *)&highlight_params.mIsDepthEnabled,
                  &v28->mPelvisPosition) <= 0.69999999)
            && v29 < v16 )
          {
            v18 = v24;
            v52 = v24;
            v16 = v29;
          }
          else
          {
LABEL_34:
            v18 = v52;
          }
        }
        v24 = *(_QWORD *)(v24 + 24) - 16i64;
      }
      while ( (UFG::qVector3 *)v24 != (UFG::qVector3 *)&eye.z );
      if ( v18 )
      {
        v34 = *(_QWORD *)(v18 + 48);
        if ( v34 )
          v17 = *(UFG::SimObject **)(v34 + 40);
        if ( this->mHighlightedCharacter.m_pPointer )
        {
          v35 = p_mHighlightedCharacter->mPrev;
          v36 = this->mHighlightedCharacter.mNext;
          v35->mNext = v36;
          v36->mPrev = v35;
          p_mHighlightedCharacter->mPrev = p_mHighlightedCharacter;
          this->mHighlightedCharacter.mNext = &this->mHighlightedCharacter;
        }
        this->mHighlightedCharacter.m_pPointer = v17;
        if ( v17 )
        {
          v37 = v17->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
          v37->mNext = p_mHighlightedCharacter;
          p_mHighlightedCharacter->mPrev = v37;
          this->mHighlightedCharacter.mNext = &v17->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
          v17->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mHighlightedCharacter;
        }
        v51.mColour = UFG::qColour::White;
        LODWORD(v51.mOutlineStrength) = (_DWORD)FLOAT_1_0;
        v51.mXrayStrength = 0.0;
        v51.mIsDepthEnabled = 0;
        UFG::HighlightSimObject(this->mHighlightedCharacter.m_pPointer, &v51);
        this->mbHighlightOn = 1;
      }
    }
    for ( i = *(_QWORD *)&highlight_params.mColour.r - 16i64;
          (UFG::qVector3 *)(*(_QWORD *)&highlight_params.mColour.r - 16i64) != (UFG::qVector3 *)&eye.z;
          i = *(_QWORD *)&highlight_params.mColour.r - 16i64 )
    {
      v39 = (_QWORD *)(i + 16);
      v40 = *(_QWORD *)(i + 16);
      v41 = *(_QWORD **)(i + 24);
      *(_QWORD *)(v40 + 8) = v41;
      *v41 = v40;
      *v39 = v39;
      v39[1] = v39;
    }
    v42 = ray_dir_8;
    v43 = *(_QWORD **)&highlight_params.mColour.r;
    ray_dir_8[1] = *(_QWORD *)&highlight_params.mColour.r;
    *v43 = v42;
  }
}

// File Line: 705
// RVA: 0x3CC8D0
void __fastcall UFG::ScriptCameraComponent::SetEyeWorld(
        UFG::ScriptCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rdi
  float x; // eax
  float v8; // xmm1_4

  y = position->y;
  z = position->z;
  p_mEye = &this->mEye;
  this->mEye.p0.x = position->x;
  this->mEye.p0.y = y;
  this->mEye.p0.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
  x = velocity->x;
  v8 = velocity->z;
  p_mEye->v0.y = velocity->y;
  p_mEye->v0.z = v8;
  p_mEye->v0.x = x;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
}

// File Line: 711
// RVA: 0x3CCF00
void __fastcall UFG::ScriptCameraComponent::SetLookWorld(
        UFG::ScriptCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rdi
  float x; // eax
  float v8; // xmm1_4

  y = position->y;
  z = position->z;
  p_mLook = &this->mLook;
  this->mLook.p0.x = position->x;
  this->mLook.p0.y = y;
  this->mLook.p0.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
  x = velocity->x;
  v8 = velocity->z;
  p_mLook->v0.y = velocity->y;
  p_mLook->v0.z = v8;
  p_mLook->v0.x = x;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
}

// File Line: 717
// RVA: 0x3C33C0
void __fastcall UFG::ScriptCameraComponent::GetEyeWorld(
        UFG::ScriptCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  y = this->mEye.p0.y;
  z = this->mEye.p0.z;
  position->x = this->mEye.p0.x;
  position->y = y;
  position->z = z;
  v5 = this->mEye.v0.y;
  v6 = this->mEye.v0.z;
  velocity->x = this->mEye.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 723
// RVA: 0x3C3890
void __fastcall UFG::ScriptCameraComponent::GetLookWorld(
        UFG::ScriptCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  y = this->mLook.p0.y;
  z = this->mLook.p0.z;
  position->x = this->mLook.p0.x;
  position->y = y;
  position->z = z;
  v5 = this->mLook.v0.y;
  v6 = this->mLook.v0.z;
  velocity->x = this->mLook.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 729
// RVA: 0x3C3530
void __fastcall UFG::ScriptCameraComponent::GetFovRadians(
        UFG::ScriptCameraComponent *this,
        float *fov,
        float *fov_velocity)
{
  *fov_velocity = this->mFov.v0 * 0.017453292;
  *fov = this->mFov.p0 * 0.017453292;
}

// File Line: 743
// RVA: 0x3C5570
bool __fastcall UFG::TurfCameraComponent::HasComponent(UFG::SceneObjectProperties *sceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           sceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentScriptCamera);
}

// File Line: 752
// RVA: 0x3C8320
void __fastcall UFG::ScriptCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x760ui64, "ScriptCameraComponent", 0i64, 1u);
  if ( v3 )
    UFG::ScriptCameraComponent::ScriptCameraComponent(
      (UFG::ScriptCameraComponent *)v3,
      pSceneObj->m_NameUID,
      pSceneObj->m_pSimObject);
}

// File Line: 759
// RVA: 0x3C20E0
void __fastcall UFG::ScriptCameraComponent::EnableProfiling(UFG::ScriptCameraComponent *this)
{
  this->mbProfiling = 1;
}

// File Line: 765
// RVA: 0x3C20A0
void __fastcall UFG::ScriptCameraComponent::DisableProfiling(UFG::ScriptCameraComponent *this)
{
  if ( this->mbHighlightOn )
  {
    UFG::UnHighlightSimObject(this->mHighlightedCharacter.m_pPointer);
    this->mbProfiling = 0;
  }
  else
  {
    this->mbProfiling = 0;
  }
}

// File Line: 775
// RVA: 0x3DE8D0
UFG::SimObject *__fastcall UFG::ScriptCameraComponent::getHighlightedCharacter(UFG::ScriptCameraComponent *this)
{
  return this->mHighlightedCharacter.m_pPointer;
}

