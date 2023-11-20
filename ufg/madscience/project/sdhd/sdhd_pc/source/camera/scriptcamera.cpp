// File Line: 44
// RVA: 0x14BFF80
__int64 dynamic_initializer_for__UFG::ScriptCameraComponent::s_ScriptCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ScriptCameraComponent::s_ScriptCameraComponentList__);
}

// File Line: 45
// RVA: 0x3C3EB0
const char *__fastcall UFG::ScriptCameraComponent::GetTypeName(UFG::ScriptCameraComponent *this)
{
  return "ScriptCameraComponent";
}

// File Line: 54
// RVA: 0x3BD190
void __fastcall UFG::ScriptCameraComponent::ScriptCameraComponent(UFG::ScriptCameraComponent *this, unsigned int name_uid, UFG::SimObject *pObj)
{
  UFG::ScriptCameraComponent *v3; // rbx
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v4; // r12
  UFG::qSafePointer<Creature,Creature> *v5; // rsi
  UFG::qSafePointer<Creature,Creature> *v6; // rdi
  _DWORD *v7; // r14
  _DWORD *v8; // r15
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qMemoryPool *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  unsigned int v15; // eax
  UFG::TransformNodeComponent *v16; // rax
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rdi
  unsigned int v19; // eax
  UFG::TransformNodeComponent *v20; // rax
  UFG::qMemoryPool *v21; // rax
  UFG::allocator::free_link *v22; // rdi
  unsigned int v23; // eax
  UFG::TransformNodeComponent *v24; // rax
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  signed __int64 v32; // rax
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v49; // rax
  int v50; // [rsp+38h] [rbp-C0h]
  int v51; // [rsp+3Ch] [rbp-BCh]
  int v52; // [rsp+40h] [rbp-B8h]
  int v53; // [rsp+48h] [rbp-B0h]
  int v54; // [rsp+4Ch] [rbp-ACh]
  int v55; // [rsp+50h] [rbp-A8h]
  int v56; // [rsp+58h] [rbp-A0h]
  int v57; // [rsp+5Ch] [rbp-9Ch]
  int v58; // [rsp+60h] [rbp-98h]
  UFG::SimObjectModifier v59; // [rsp+68h] [rbp-90h]
  UFG::SimObject *simObject; // [rsp+110h] [rbp+18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v61; // [rsp+118h] [rbp+20h]

  simObject = pObj;
  v3 = this;
  UFG::GameCameraComponent::GameCameraComponent((UFG::GameCameraComponent *)&this->vfptr, name_uid);
  v4 = (UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ScriptCameraComponent::`vftable;
  v5 = &v3->mCameraCreature;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v3->mCameraCreature.m_pPointer = 0i64;
  v6 = &v3->mTargetCreature;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v3->mTargetCreature.m_pPointer = 0i64;
  Render::DepthOfField::Focus::Focus(&v3->mDofParameters);
  v3->mFov.mDuration = 0.0099999998;
  v7 = (_DWORD *)&v3->mEye.mDuration.x;
  *v7 = 1008981770;
  v7[1] = 1008981770;
  v7[2] = 1008981770;
  v8 = (_DWORD *)&v3->mLook.mDuration.x;
  *v8 = 1008981770;
  v8[1] = 1008981770;
  v8[2] = 1008981770;
  v3->mEyeNoise.bCircular = 0;
  v50 = 1065353216;
  v51 = 1065353216;
  v52 = 1065353216;
  v53 = -1082130432;
  v54 = -1082130432;
  v55 = -1082130432;
  v56 = 1056964608;
  v57 = 1056964608;
  v58 = 1056964608;
  UFG::qNoise<UFG::qVector3,float>::SetParameters(
    &v3->mEyeNoise,
    6,
    1.0,
    (UFG::qVector3 *)&v56,
    (UFG::qVector3 *)&v53,
    (UFG::qVector3 *)&v50);
  UFG::qNoise<UFG::qVector3,float>::qNoise<UFG::qVector3,float>(&v3->mLookNoise);
  v61 = &v3->mHighlightedCharacter;
  v61->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v61->mPrev;
  v61->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v61->mPrev;
  v3->mHighlightedCharacter.m_pPointer = 0i64;
  if ( v3->mCameraCreature.m_pPointer )
  {
    v9 = v5->mPrev;
    v10 = v3->mCameraCreature.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->mCameraCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v3->mCameraCreature.mPrev;
  }
  v3->mCameraCreature.m_pPointer = 0i64;
  v3->nCameraCreatureBone = -1;
  if ( v3->mTargetCreature.m_pPointer )
  {
    v11 = v6->mPrev;
    v12 = v3->mTargetCreature.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->mTargetCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v3->mTargetCreature.mPrev;
  }
  v3->mTargetCreature.m_pPointer = 0i64;
  v3->nTargetCreatureBone = -1;
  v3->mPreviousCameraComponent = 0i64;
  v3->mDofSnapNext = 1;
  v3->mDofParameters.mFocalDistance = 5.0;
  v3->mDofParameters.mInFocusRange = 200.0;
  *(_QWORD *)&v3->mDofParameters.mNearRange = 1056964608i64;
  v3->mDofParameters.mFarRange = 5.0;
  v3->mDofParameters.mFarBlurRadius = 4.0;
  v13 = UFG::GetSimulationMemoryPool();
  v14 = UFG::qMemoryPool::Allocate(v13, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v14 )
  {
    v15 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v14, v15, 0i64, 0);
  }
  else
  {
    v16 = 0i64;
  }
  v3->mTargetTransform = v16;
  v17 = UFG::GetSimulationMemoryPool();
  v18 = UFG::qMemoryPool::Allocate(v17, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v18 )
  {
    v19 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v18, v19, 0i64, 0);
  }
  else
  {
    v20 = 0i64;
  }
  v3->mCameraTransform = v20;
  v21 = UFG::GetSimulationMemoryPool();
  v22 = UFG::qMemoryPool::Allocate(v21, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v22 )
  {
    v23 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v22, v23, 0i64, 0);
  }
  else
  {
    v24 = 0i64;
  }
  v3->mNextCameraTransform = v24;
  LODWORD(v25) = LODWORD(FLOAT_0_1) & _xmm;
  v26 = FLOAT_0_000099999997;
  if ( COERCE_FLOAT(LODWORD(FLOAT_0_1) & _xmm) <= 0.000099999997 )
    v27 = FLOAT_0_000099999997;
  else
    LODWORD(v27) = LODWORD(FLOAT_0_1) & _xmm;
  v3->mEyeNoise.tOffset = (float)((float)(1.0 / v27) * v3->mEyeNoise.tFrequency) * v3->mEyeNoise.tOffset;
  v3->mEyeNoise.tFrequency = v25;
  UFG::qNoise<UFG::qVector3,float>::Init(&v3->mEyeNoise);
  if ( v25 > 0.000099999997 )
    LODWORD(v26) = LODWORD(FLOAT_0_1) & _xmm;
  v3->mLookNoise.tOffset = (float)((float)(1.0 / v26) * v3->mLookNoise.tFrequency) * v3->mLookNoise.tOffset;
  v3->mLookNoise.tFrequency = v25;
  UFG::qNoise<UFG::qVector3,float>::Init(&v3->mLookNoise);
  v28 = UFG::qVector3::msZero.y;
  v29 = UFG::qVector3::msZero.z;
  v3->mLookOffset.x = UFG::qVector3::msZero.x;
  v3->mLookOffset.y = v28;
  v3->mLookOffset.z = v29;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  v3->mFollowTargetEyeOffset.x = UFG::qVector3::msZero.x;
  v3->mFollowTargetEyeOffset.y = v30;
  v3->mFollowTargetEyeOffset.z = v31;
  v32 = (signed __int64)&v3->mFov;
  *(_QWORD *)v32 = 1065353216i64;
  *(_QWORD *)(v32 + 32) = 0i64;
  *(_DWORD *)(v32 + 24) = 1120403456;
  *(_DWORD *)(v32 + 28) = 1120403456;
  UFG::HomerCubic<float>::MakeCoeffs(&v3->mFov);
  *v7 = 1065353216;
  v3->mEye.mDuration.y = 1.0;
  *(_QWORD *)&v3->mEye.mDuration.z = 1065353216i64;
  *(_QWORD *)&v3->mEye.mParameter.y = 0i64;
  v33 = UFG::qVector3::msZero.y;
  v34 = UFG::qVector3::msZero.z;
  v3->mEye.v0.x = UFG::qVector3::msZero.x;
  v3->mEye.v0.y = v33;
  v3->mEye.v0.z = v34;
  v35 = UFG::qVector3::msZero.y;
  v36 = UFG::qVector3::msZero.z;
  v3->mEye.v1.x = UFG::qVector3::msZero.x;
  v3->mEye.v1.y = v35;
  v3->mEye.v1.z = v36;
  v37 = UFG::qVector3::msZero.y;
  v38 = UFG::qVector3::msZero.z;
  v3->mEye.p0.x = UFG::qVector3::msZero.x;
  v3->mEye.p0.y = v37;
  v3->mEye.p0.z = v38;
  v39 = UFG::qVector3::msZero.y;
  v40 = UFG::qVector3::msZero.z;
  v3->mEye.p1.x = UFG::qVector3::msZero.x;
  v3->mEye.p1.y = v39;
  v3->mEye.p1.z = v40;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
  *v8 = 1065353216;
  v3->mLook.mDuration.y = 1.0;
  *(_QWORD *)&v3->mLook.mDuration.z = 1065353216i64;
  *(_QWORD *)&v3->mLook.mParameter.y = 0i64;
  v41 = UFG::qVector3::msZero.y;
  v42 = UFG::qVector3::msZero.z;
  v3->mLook.v0.x = UFG::qVector3::msZero.x;
  v3->mLook.v0.y = v41;
  v3->mLook.v0.z = v42;
  v43 = UFG::qVector3::msZero.y;
  v44 = UFG::qVector3::msZero.z;
  v3->mLook.v1.x = UFG::qVector3::msZero.x;
  v3->mLook.v1.y = v43;
  v3->mLook.v1.z = v44;
  v45 = UFG::qVector3::msZero.y;
  v46 = UFG::qVector3::msZero.z;
  v3->mLook.p0.x = UFG::qVector3::msZero.x;
  v3->mLook.p0.y = v45;
  v3->mLook.p0.z = v46;
  v47 = UFG::qVector3::msZero.y;
  v48 = UFG::qVector3::msZero.z;
  v3->mLook.p1.x = UFG::qVector3::msZero.x;
  v3->mLook.p1.y = v47;
  v3->mLook.p1.z = v48;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
  *(_QWORD *)&v3->mEyeNoiseMagnitude = 0i64;
  v3->mElapsedSeconds = 0.0;
  *(_QWORD *)&v3->mLatitude = 0i64;
  *(_DWORD *)&v3->mbScriptCameraOn = 0;
  *(_WORD *)&v3->mbPanning = 0;
  v3->mbHighlightOn = 0;
  v3->bAllowWideAspectDisplay = 0;
  v49 = UFG::ScriptCameraComponent::s_ScriptCameraComponentList.mNode.mPrev;
  UFG::ScriptCameraComponent::s_ScriptCameraComponentList.mNode.mPrev->mNext = v4;
  v4->mPrev = v49;
  v3->mNext = (UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *)&UFG::ScriptCameraComponent::s_ScriptCameraComponentList;
  UFG::ScriptCameraComponent::s_ScriptCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID,
    "ScriptCameraComponent");
  UFG::SimObjectModifier::SimObjectModifier(&v59, simObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v59, (UFG::SimComponent *)&v3->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v59);
  UFG::SimObjectModifier::~SimObjectModifier(&v59);
}

// File Line: 108
// RVA: 0x3BE100
void __fastcall UFG::ScriptCameraComponent::~ScriptCameraComponent(UFG::ScriptCameraComponent *this)
{
  UFG::ScriptCameraComponent *v1; // r8
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v2; // r9
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v3; // rcx
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<Creature,Creature> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<Creature,Creature> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v20; // rcx
  UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *v21; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ScriptCameraComponent::`vftable;
  if ( this == UFG::ScriptCameraComponent::s_ScriptCameraComponentpCurrentIterator )
    UFG::ScriptCameraComponent::s_ScriptCameraComponentpCurrentIterator = (UFG::ScriptCameraComponent *)&this->mPrev[-78];
  v2 = (UFG::qNode<UFG::ScriptCameraComponent,UFG::ScriptCameraComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mHighlightedCharacter;
  if ( v1->mHighlightedCharacter.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mHighlightedCharacter.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mHighlightedCharacter.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mHighlightedCharacter.mPrev;
  }
  v1->mHighlightedCharacter.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mHighlightedCharacter.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mHighlightedCharacter.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mHighlightedCharacter.mPrev;
  v10 = &v1->mTargetCreature;
  if ( v1->mTargetCreature.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mTargetCreature.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mTargetCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mTargetCreature.mPrev;
  }
  v1->mTargetCreature.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->mTargetCreature.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->mTargetCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mTargetCreature.mPrev;
  v15 = &v1->mCameraCreature;
  if ( v1->mCameraCreature.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v1->mCameraCreature.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v1->mCameraCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mCameraCreature.mPrev;
  }
  v1->mCameraCreature.m_pPointer = 0i64;
  v18 = v15->mPrev;
  v19 = v1->mCameraCreature.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v1->mCameraCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mCameraCreature.mPrev;
  v20 = v2->mPrev;
  v21 = v2->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GameCameraComponent::~GameCameraComponent((UFG::GameCameraComponent *)&v1->vfptr);
}

// File Line: 113
// RVA: 0x3CE500
void __usercall UFG::ScriptCameraComponent::SwitchToScriptCam(UFG::ScriptCameraComponent *this@<rcx>, UFG::TransformNodeComponent *pTNC@<rdx>, bool transitionIn@<r8b>, float fov@<xmm3>, float *a5@<r13>)
{
  UFG::ScriptCameraComponent *v5; // rbx
  Render::DepthOfField::Focus *v6; // rcx
  bool v7; // r15
  UFG::TransformNodeComponent *v8; // rsi
  UFG::BaseCameraComponent *v9; // rcx
  float v10; // xmm0_4
  float v11; // xmm1_4
  float *v12; // rbp
  float *v13; // r14
  float v14; // xmm1_4
  float v15; // xmm0_4
  __int64 v16; // r8
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  UFG::Director *v25; // rax
  UFG::TransformNodeComponent *v26; // rcx
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  UFG::qVector3 desLook; // [rsp+40h] [rbp-58h]
  UFG::qVector3 desEye; // [rsp+4Ch] [rbp-4Ch]

  v5 = this;
  v6 = &this->mCamera.mDepthOfFieldFocus;
  v6[71].mFarRange = 0.0;
  *(float *)((char *)&v6[72].mNearBlurRadius + 1) = 0.0;
  v7 = transitionIn;
  v8 = pTNC;
  Render::DepthOfField::Focus::DisableFocus(v6);
  if ( !v5->mbScriptCameraOn )
    v5->mPreviousCameraComponent = UFG::Director::Get()->mCurrentCamera;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 && v9->m_pSimObject )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    v10 = v8->mWorldTransform.v3.y;
    v11 = v8->mWorldTransform.v3.z;
    v12 = &v5->mEye.mDuration.x;
    v12[21] = v8->mWorldTransform.v3.x;
    v12[22] = v10;
    v12[23] = v11;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mEye);
    *(_QWORD *)&v5->mEye.mParameter.x = 0i64;
    v5->mEye.mParameter.z = 0.0;
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    v13 = &v5->mLook.mDuration.x;
    v14 = v8->mWorldTransform.v0.y + v8->mWorldTransform.v3.y;
    v15 = v8->mWorldTransform.v0.z + v8->mWorldTransform.v3.z;
    v13[21] = v8->mWorldTransform.v0.x + v8->mWorldTransform.v3.x;
    v13[22] = v14;
    v13[23] = v15;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mLook);
    *(_QWORD *)&v5->mLook.mParameter.x = 0i64;
    v5->mLook.mParameter.z = 0.0;
    if ( fov == 0.0 )
    {
      ((void (*)(void))v5->mPreviousCameraComponent->vfptr[19].__vecDelDtor)();
      v5->mFov.p1 = (float)(v15 * 180.0) * 0.31830987;
    }
    else
    {
      v5->mFov.p1 = fov;
    }
    UFG::HomerCubic<float>::MakeCoeffs(&v5->mFov);
    v5->mFov.mParameter = 0.0;
    if ( v7 )
    {
      LOBYTE(v16) = 1;
      ((void (__fastcall *)(UFG::ScriptCameraComponent *, UFG::BaseCameraComponent *, __int64))v5->vfptr[29].__vecDelDtor)(
        v5,
        v5->mPreviousCameraComponent,
        v16);
    }
    else
    {
      v17 = v5->mEye.p1.y;
      v18 = v5->mEye.p1.z;
      v5->mEye.p0.x = v5->mEye.p1.x;
      v5->mEye.p0.y = v17;
      v5->mEye.p0.z = v18;
      v19 = v5->mEye.v1.y;
      v20 = v5->mEye.v1.z;
      v5->mEye.v0.x = v5->mEye.v1.x;
      v5->mEye.v0.y = v19;
      v5->mEye.v0.z = v20;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mEye);
      *(_QWORD *)&v5->mEye.mParameter.x = 0i64;
      v5->mEye.mParameter.z = 0.0;
      v21 = v5->mLook.p1.z;
      v22 = v5->mLook.p1.x;
      v5->mLook.p0.y = v5->mLook.p1.y;
      v5->mLook.p0.z = v21;
      v5->mLook.p0.x = v22;
      v23 = v5->mLook.v1.y;
      v24 = v5->mLook.v1.z;
      v5->mLook.v0.x = v5->mLook.v1.x;
      v5->mLook.v0.y = v23;
      v5->mLook.v0.z = v24;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mLook);
      *(_QWORD *)&v5->mLook.mParameter.x = 0i64;
      v5->mLook.mParameter.z = 0.0;
      v5->mFov.p0 = v5->mFov.p1;
      v5->mFov.v0 = v5->mFov.v1;
      UFG::HomerCubic<float>::MakeCoeffs(&v5->mFov);
      v5->mFov.mParameter = 0.0;
    }
    v25 = UFG::Director::Get();
    UFG::Director::SetCurrentCamera(v25, (UFG::BaseCameraComponent *)&v5->vfptr);
    v26 = v5->mCameraTransform;
    v5->mbScriptCameraOn = 1;
    UFG::TransformNodeComponent::SetLocalTransform(v26, &UFG::qMatrix44::msIdentity);
    UFG::TransformNodeComponent::SetParent(v5->mCameraTransform, v8, 0);
    if ( UFG::ScriptCameraComponent::mbUserInputEnabled )
      UFG::ScriptCameraComponent::InitUserControlledCamera(v5);
    v27 = v5->mEye.p0.x;
    v28 = v5->mLook.p0.y;
    desLook.x = v5->mLook.p0.x;
    v29 = v5->mLook.p0.z;
    desEye.x = v27;
    v30 = v5->mEye.p0.z;
    desLook.z = v29;
    v31 = v5->mEye.p0.y;
    desLook.y = v28;
    desEye.y = v31;
    desEye.z = v30;
    UFG::GameCameraComponent::SetDesiredEyeLookUp(
      (UFG::GameCameraComponent *)&v5->vfptr,
      0.0,
      &desEye,
      &desLook,
      a5,
      &UFG::qVector3::msDirUp,
      0,
      0i64,
      0i64);
  }
}

// File Line: 173
// RVA: 0x3C84B0
void __fastcall UFG::ScriptCameraComponent::ReleaseCamera(UFG::ScriptCameraComponent *this, bool transitionOut)
{
  bool v2; // bp
  UFG::ScriptCameraComponent *v3; // rbx
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rsi
  char v6; // al
  UFG::SimObject *v7; // rcx
  UFG::BaseCameraComponent *v8; // rdi
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax
  __int64 v11; // rsi
  UFG::Director *v12; // rax
  __int64 v13; // r8
  UFG::FollowCameraComponent *v14; // rdi
  UFG::Director *v15; // rax
  __int64 v16; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v17; // rdx
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax

  v2 = transitionOut;
  v3 = this;
  if ( this->mbScriptCameraOn )
  {
    UFG::ScriptCameraComponent::mbUserInputEnabled = 0;
    if ( this->mbHighlightOn )
      UFG::UnHighlightSimObject(this->mHighlightedCharacter.m_pPointer);
    v3->mbProfiling = 0;
    if ( LocalPlayer )
    {
      v4 = UFG::SimObject::GetComponentOfType(
             (UFG::SimObject *)&LocalPlayer->vfptr,
             UFG::CharacterSubjectComponent::_TypeUID);
      v5 = v4;
      if ( v4 )
      {
        v6 = ((__int64 (__fastcall *)(UFG::SimComponent *))v4->vfptr[42].__vecDelDtor)(v4);
        v7 = v3->m_pSimObject;
        if ( v6 )
        {
          if ( v7 )
            v8 = (UFG::BaseCameraComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::ChaseCameraComponent::_TypeUID);
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
          if ( v2 )
          {
            ((void (__fastcall *)(UFG::BaseCameraComponent *))v8->vfptr[14].__vecDelDtor)(v8);
            v8->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v8->vfptr, v11);
            ((void (__fastcall *)(UFG::BaseCameraComponent *))v8->vfptr[15].__vecDelDtor)(v8);
            LOBYTE(v13) = 1;
            ((void (__fastcall *)(UFG::BaseCameraComponent *, UFG::ScriptCameraComponent *, __int64))v8->vfptr[29].__vecDelDtor)(
              v8,
              v3,
              v13);
          }
        }
        else if ( v7 )
        {
          v14 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                v7,
                                                UFG::FollowCameraComponent::_TypeUID);
          if ( v14 )
          {
            v15 = UFG::Director::Get();
            UFG::Director::SetCurrentCamera(v15, (UFG::BaseCameraComponent *)&v14->vfptr);
            if ( v2 )
            {
              ((void (__fastcall *)(UFG::FollowCameraComponent *))v14->vfptr[14].__vecDelDtor)(v14);
              UFG::FollowCameraComponent::UpdateLocalWorld(v14, 0.0);
              LOBYTE(v16) = 1;
              ((void (__fastcall *)(UFG::FollowCameraComponent *, UFG::ScriptCameraComponent *, __int64))v14->vfptr[43].__vecDelDtor)(
                v14,
                v3,
                v16);
              ((void (__fastcall *)(UFG::FollowCameraComponent *))v14->vfptr[15].__vecDelDtor)(v14);
            }
            else
            {
              v14->vfptr[16].__vecDelDtor(
                (UFG::qSafePointerNode<UFG::SimComponent> *)&v14->vfptr,
                (unsigned int)LocalPlayer);
            }
          }
        }
        v3->mDofSnapNext = 1;
        v3->mDofParameters.mFocalDistance = 5.0;
        v3->mDofParameters.mInFocusRange = 200.0;
        *(_QWORD *)&v3->mDofParameters.mNearRange = 1056964608i64;
        v3->mDofParameters.mFarRange = 5.0;
        v3->mDofParameters.mFarBlurRadius = 4.0;
        v17 = &v3->mHighlightedCharacter;
        v18 = UFG::qVector3::msZero.y;
        v19 = UFG::qVector3::msZero.z;
        v3->mLookOffset.x = UFG::qVector3::msZero.x;
        v3->mLookOffset.y = v18;
        v3->mLookOffset.z = v19;
        v20 = UFG::qVector3::msZero.y;
        v21 = UFG::qVector3::msZero.z;
        v3->mFollowTargetEyeOffset.x = UFG::qVector3::msZero.x;
        v3->mFollowTargetEyeOffset.y = v20;
        v3->mFollowTargetEyeOffset.z = v21;
        *(_DWORD *)&v3->mbScriptCameraOn = 0;
        if ( v3->mHighlightedCharacter.m_pPointer )
        {
          v22 = v17->mPrev;
          v23 = v3->mHighlightedCharacter.mNext;
          v22->mNext = v23;
          v23->mPrev = v22;
          v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v17->mPrev;
          v3->mHighlightedCharacter.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mHighlightedCharacter.mPrev;
        }
        v3->mHighlightedCharacter.m_pPointer = 0i64;
        v3->mbHighlightOn = 0;
      }
    }
  }
}

// File Line: 238
// RVA: 0x3CC100
void __fastcall UFG::ScriptCameraComponent::SetDurations(UFG::ScriptCameraComponent *this, float duration)
{
  UFG::ScriptCameraComponent *v2; // rbx
  UFG::HomerCubic<UFG::qVector3> *v3; // rcx
  float v4; // xmm6_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  UFG::HomerCubic<UFG::qVector3> *v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  UFG::HomerCubic<float> *v18; // rcx
  float v19; // xmm0_4

  v2 = this;
  v3 = &this->mEye;
  v4 = duration;
  v5 = v3->mParameter.y / v3->mDuration.y;
  v6 = v3->mParameter.z / v3->mDuration.z;
  v3->mParameter.x = v3->mParameter.x / v3->mDuration.x;
  v3->mParameter.y = v5;
  v3->mParameter.z = v6;
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
  v3->mDuration.y = duration;
  v3->mDuration.x = v8;
  v3->mDuration.z = v7;
  v9 = v7 * v3->mParameter.z;
  v3->mParameter.x = v8 * v3->mParameter.x;
  v3->mParameter.z = v9;
  v3->mParameter.y = duration * v5;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v3);
  v10 = &v2->mLook;
  v11 = v2->mLook.mParameter.z / v2->mLook.mDuration.z;
  v12 = v2->mLook.mParameter.x / v2->mLook.mDuration.x;
  v10->mParameter.y = v2->mLook.mParameter.y / v2->mLook.mDuration.y;
  v10->mParameter.z = v11;
  v10->mParameter.x = v12;
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
  v10->mDuration.x = v15;
  v2->mLook.mDuration.y = v14;
  v2->mLook.mDuration.z = v13;
  v16 = v14 * v2->mLook.mParameter.y;
  v17 = v13 * v2->mLook.mParameter.z;
  v2->mLook.mParameter.x = v15 * v2->mLook.mParameter.x;
  v2->mLook.mParameter.y = v16;
  v2->mLook.mParameter.z = v17;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v10);
  v18 = &v2->mFov;
  v19 = v2->mFov.mParameter / v2->mFov.mDuration;
  v2->mFov.mParameter = v19;
  if ( v4 <= 0.0099999998 )
    v4 = FLOAT_0_0099999998;
  v18->mDuration = v4;
  v2->mFov.mParameter = v4 * v19;
  UFG::HomerCubic<float>::MakeCoeffs(v18);
}

// File Line: 246
// RVA: 0x3C7B80
void __fastcall UFG::ScriptCameraComponent::PanToTransform(UFG::ScriptCameraComponent *this, UFG::TransformNodeComponent *pTNC, float duration, float fov)
{
  UFG::ScriptCameraComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm6_4
  UFG::HomerCubic<UFG::qVector3> *v7; // rcx
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::HomerCubic<UFG::qVector3> *v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4

  v4 = this;
  v5 = pTNC;
  v6 = duration;
  UFG::TransformNodeComponent::SetLocalTransform(this->mNextCameraTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(v4->mNextCameraTransform, v5, 0);
  v7 = &v4->mEye;
  v4->mbPanning = 1;
  v8 = v4->mEye.mParameter.y / v4->mEye.mDuration.y;
  v9 = v4->mEye.mParameter.z / v4->mEye.mDuration.z;
  v7->mParameter.x = v4->mEye.mParameter.x / v4->mEye.mDuration.x;
  v7->mParameter.y = v8;
  v7->mParameter.z = v9;
  if ( v6 <= 0.0099999998 )
    v10 = FLOAT_0_0099999998;
  else
    v10 = v6;
  if ( v6 <= 0.0099999998 )
    v11 = FLOAT_0_0099999998;
  else
    v11 = v6;
  if ( v6 <= 0.0099999998 )
    v12 = FLOAT_0_0099999998;
  else
    v12 = v6;
  v7->mDuration.x = v12;
  v4->mEye.mDuration.y = v11;
  v4->mEye.mDuration.z = v10;
  v13 = v11 * v4->mEye.mParameter.y;
  v14 = v10 * v4->mEye.mParameter.z;
  v4->mEye.mParameter.x = v12 * v4->mEye.mParameter.x;
  v4->mEye.mParameter.y = v13;
  v4->mEye.mParameter.z = v14;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v7);
  v15 = &v4->mLook;
  v16 = v4->mLook.mParameter.z / v4->mLook.mDuration.z;
  v17 = v4->mLook.mParameter.x / v4->mLook.mDuration.x;
  v15->mParameter.y = v4->mLook.mParameter.y / v4->mLook.mDuration.y;
  v15->mParameter.z = v16;
  v15->mParameter.x = v17;
  if ( v6 <= 0.0099999998 )
    v18 = FLOAT_0_0099999998;
  else
    v18 = v6;
  if ( v6 <= 0.0099999998 )
    v19 = FLOAT_0_0099999998;
  else
    v19 = v6;
  if ( v6 <= 0.0099999998 )
    v20 = FLOAT_0_0099999998;
  else
    v20 = v6;
  v15->mDuration.x = v20;
  v4->mLook.mDuration.y = v19;
  v4->mLook.mDuration.z = v18;
  v21 = v19 * v4->mLook.mParameter.y;
  v22 = v18 * v4->mLook.mParameter.z;
  v4->mLook.mParameter.x = v20 * v4->mLook.mParameter.x;
  v4->mLook.mParameter.y = v21;
  v4->mLook.mParameter.z = v22;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v15);
  if ( fov != 0.0 )
  {
    v23 = v4->mFov.mParameter / v4->mFov.mDuration;
    v4->mFov.mParameter = v23;
    if ( v6 <= 0.0099999998 )
      v6 = FLOAT_0_0099999998;
    v4->mFov.mDuration = v6;
    v4->mFov.mParameter = v6 * v23;
    UFG::HomerCubic<float>::MakeCoeffs(&v4->mFov);
    v4->mFov.p1 = fov;
    UFG::HomerCubic<float>::MakeCoeffs(&v4->mFov);
    v4->mFov.mParameter = 0.0;
  }
}

// File Line: 263
// RVA: 0x3CD600
void __fastcall UFG::ScriptCameraComponent::SetTarget(UFG::ScriptCameraComponent *this, UFG::TransformNodeComponent *pTNC)
{
  UFG::qSafePointer<Creature,Creature> *v2; // r9
  UFG::TransformNodeComponent *v3; // rdi
  UFG::ScriptCameraComponent *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v6; // rax

  v2 = &this->mTargetCreature;
  v3 = pTNC;
  v4 = this;
  if ( this->mTargetCreature.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = this->mTargetCreature.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    this->mTargetCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&this->mTargetCreature.mPrev;
  }
  this->mTargetCreature.m_pPointer = 0i64;
  UFG::TransformNodeComponent::SetLocalTransform(this->mTargetTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(v4->mTargetTransform, v3, 0);
  v4->mbFollowTarget = 1;
}

// File Line: 271
// RVA: 0x3CC480
void __fastcall UFG::ScriptCameraComponent::SetEyeOffsetFromTarget(UFG::ScriptCameraComponent *this, UFG::qVector3 *offset)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = offset->y;
  v3 = offset->z;
  this->mFollowTargetEyeOffset.x = offset->x;
  this->mFollowTargetEyeOffset.y = v2;
  this->mFollowTargetEyeOffset.z = v3;
  this->mbFollowTargetEyeOffset = 1;
}

// File Line: 286
// RVA: 0x3C9830
void __fastcall UFG::ScriptCameraComponent::SetCameraCreature(UFG::ScriptCameraComponent *this, Creature *creature, int bone_id)
{
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v3; // r10
  UFG::ScriptCameraComponent *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v5; // r9
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::TransformNodeComponent *v8; // rcx

  v3 = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&this->mCameraCreature.mPrev;
  v4 = this;
  if ( this->mCameraCreature.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = this->mCameraCreature.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = v3;
    this->mCameraCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&this->mCameraCreature.mPrev;
  }
  this->mCameraCreature.m_pPointer = creature;
  if ( creature )
  {
    v7 = creature->m_SafePointerList.mNode.mPrev;
    v7->mNext = v3;
    v3->mPrev = v7;
    this->mCameraCreature.mNext = &creature->m_SafePointerList.mNode;
    creature->m_SafePointerList.mNode.mPrev = v3;
  }
  v8 = this->mCameraTransform;
  v4->nCameraCreatureBone = bone_id;
  UFG::TransformNodeComponent::SetLocalTransform(v8, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(v4->mCameraTransform, 0i64, 0);
  v4->mbAttached = 1;
}

// File Line: 295
// RVA: 0x3CC400
void __fastcall UFG::ScriptCameraComponent::SetEyeAttachment(UFG::ScriptCameraComponent *this, UFG::TransformNodeComponent *pTNC)
{
  UFG::qSafePointer<Creature,Creature> *v2; // r9
  UFG::TransformNodeComponent *v3; // rdi
  UFG::ScriptCameraComponent *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v6; // rax

  v2 = &this->mCameraCreature;
  v3 = pTNC;
  v4 = this;
  if ( this->mCameraCreature.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = this->mCameraCreature.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    this->mCameraCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&this->mCameraCreature.mPrev;
  }
  this->mCameraCreature.m_pPointer = 0i64;
  UFG::TransformNodeComponent::SetLocalTransform(this->mCameraTransform, &UFG::qMatrix44::msIdentity);
  UFG::TransformNodeComponent::SetParent(v4->mCameraTransform, v3, 0);
  v4->mbAttached = 1;
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
void __fastcall UFG::ScriptCameraComponent::SetDOF(UFG::ScriptCameraComponent *this, float focalDistance, float inFocusHalfRange, float nearBlendRange, float nearBlurRadius, float farBlendRange, float farBlurRadius, bool snap)
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
void __fastcall UFG::ScriptCameraComponent::SetDesiredEyeLook(UFG::ScriptCameraComponent *this, UFG::qVector3 *eye, UFG::qVector3 *look, float duration, bool snap)
{
  UFG::qVector3 *v5; // rsi
  UFG::qVector3 *v6; // rbx
  UFG::ScriptCameraComponent *v7; // rdi
  float v8; // xmm0_4
  float v9; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *v10; // rbp
  UFG::HomerCubic<UFG::qVector3> *v11; // rdi
  float v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4

  v5 = look;
  v6 = eye;
  v7 = this;
  UFG::ScriptCameraComponent::SetDurations(this, duration);
  v8 = v6->y;
  v9 = v6->z;
  v10 = &v7->mEye;
  v10->p1.x = v6->x;
  v10->p1.y = v8;
  v10->p1.z = v9;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v7->mEye);
  v11 = &v7->mLook;
  *(_QWORD *)&v10->mParameter.x = 0i64;
  v10->mParameter.z = 0.0;
  v12 = v5->x;
  v13 = v5->z;
  v11->p1.y = v5->y;
  v11->p1.z = v13;
  v11->p1.x = v12;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v11);
  *(_QWORD *)&v11->mParameter.x = 0i64;
  v11->mParameter.z = 0.0;
  if ( snap )
  {
    v14 = v10->p1.y;
    v15 = v10->p1.z;
    v10->p0.x = v10->p1.x;
    v10->p0.y = v14;
    v10->p0.z = v15;
    v16 = v10->v1.y;
    v17 = v10->v1.z;
    v10->v0.x = v10->v1.x;
    v10->v0.y = v16;
    v10->v0.z = v17;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v10);
    *(_QWORD *)&v10->mParameter.x = 0i64;
    v10->mParameter.z = 0.0;
    v18 = v11->p1.z;
    v19 = v11->p1.x;
    v11->p0.y = v11->p1.y;
    v11->p0.z = v18;
    v11->p0.x = v19;
    v20 = v11->v1.y;
    v21 = v11->v1.z;
    v11->v0.x = v11->v1.x;
    v11->v0.y = v20;
    v11->v0.z = v21;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v11);
    *(_QWORD *)&v11->mParameter.x = 0i64;
    v11->mParameter.z = 0.0;
  }
}

// File Line: 338
// RVA: 0x3D7370
void __usercall UFG::ScriptCameraComponent::Update(UFG::ScriptCameraComponent *this@<rcx>, float delta_sec@<xmm1>, float *a3@<r13>)
{
  UFG::ScriptCameraComponent *v3; // r15
  float v4; // xmm15_4
  Creature *v5; // rcx
  Creature *v6; // rcx
  UFG::TransformNodeComponent *v7; // rbx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  UFG::TransformNodeComponent *v14; // rbx
  float v15; // xmm13_4
  float v16; // xmm14_4
  float v17; // xmm13_4
  float v18; // xmm12_4
  float *v19; // rbx
  float v20; // xmm8_4
  float v21; // xmm9_4
  float v22; // xmm11_4
  float *v23; // rbx
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm10_4
  float *v27; // rbx
  float v28; // xmm12_4
  float v29; // xmm14_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  UFG::TransformNodeComponent *v34; // rbx
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  UFG::TransformNodeComponent *v39; // rbx
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float *v46; // rdi
  float *v47; // rbx
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  UFG::TransformNodeComponent *v54; // rbx
  float v55; // xmm0_4
  float v56; // xmm1_4
  float *v57; // rdi
  float *v58; // rbx
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm9_4
  float v62; // xmm12_4
  bool v63; // r9
  UFG::qVector3 *v64; // rax
  float v65; // xmm2_4
  float v66; // xmm7_4
  float v67; // xmm5_4
  float v68; // xmm4_4
  float v69; // xmm3_4
  float v70; // xmm7_4
  __int128 v71; // xmm10
  __m128 v72; // xmm2
  float v73; // xmm1_4
  float v74; // xmm7_4
  float v75; // xmm10_4
  float v76; // xmm4_4
  float v77; // xmm6_4
  float v78; // xmm7_4
  float v79; // xmm8_4
  UFG::qVector3 *v80; // rax
  float v81; // xmm3_4
  float v82; // xmm2_4
  float v83; // xmm3_4
  float v84; // xmm2_4
  UFG::qVector3 desLook; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 turn; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 desEye; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-90h]

  v3 = this;
  v4 = delta_sec;
  if ( !this->mActive
    || UFG::gFlowController.mCurrentState
    && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
  {
    return;
  }
  UFG::GameCameraComponent::Update((UFG::GameCameraComponent *)&v3->vfptr, delta_sec);
  v5 = v3->mTargetCreature.m_pPointer;
  v3->mElapsedSeconds = delta_sec + v3->mElapsedSeconds;
  if ( v5 )
  {
    Creature::GetTransform(v5, v3->nTargetCreatureBone, &transform);
    UFG::TransformNodeComponent::SetWorldTransform(v3->mTargetTransform, &transform);
  }
  v6 = v3->mCameraCreature.m_pPointer;
  if ( v6 )
  {
    Creature::GetTransform(v6, v3->nCameraCreatureBone, &transform);
    UFG::TransformNodeComponent::SetWorldTransform(v3->mCameraTransform, &transform);
  }
  UFG::HomerCubic<UFG::qVector3>::Update(&v3->mLook, delta_sec);
  UFG::HomerCubic<UFG::qVector3>::Update(&v3->mEye, delta_sec);
  UFG::HomerCubic<float>::Update(&v3->mFov, delta_sec);
  if ( v3->mbFollowTarget )
  {
    v7 = v3->mTargetTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3->mTargetTransform);
    v8 = v7->mWorldTransform.v3.y;
    v9 = v7->mWorldTransform.v3.z;
    v3->mLook.p1.x = v7->mWorldTransform.v3.x;
    v3->mLook.p1.y = v8;
    v3->mLook.p1.z = v9;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
    *(_QWORD *)&v3->mLook.mParameter.x = 0i64;
    v3->mLook.mParameter.z = 0.0;
    v10 = v3->mLook.p1.y;
    v11 = v3->mLook.p1.z;
    v3->mLook.p0.x = v3->mLook.p1.x;
    v3->mLook.p0.y = v10;
    v3->mLook.p0.z = v11;
    v12 = v3->mLook.v1.y;
    v13 = v3->mLook.v1.z;
    v3->mLook.v0.x = v3->mLook.v1.x;
    v3->mLook.v0.y = v12;
    v3->mLook.v0.z = v13;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
    *(_QWORD *)&v3->mLook.mParameter.x = 0i64;
    v3->mLook.mParameter.z = 0.0;
    if ( v3->mbFollowTargetEyeOffset )
    {
      v14 = v3->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v14);
      v15 = v3->mFollowTargetEyeOffset.z;
      v16 = v15 * v14->mWorldTransform.v2.z;
      v17 = v15 * v14->mWorldTransform.v2.x;
      v18 = v3->mFollowTargetEyeOffset.z * v14->mWorldTransform.v2.y;
      v19 = (float *)v3->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v3->mTargetTransform);
      v20 = v3->mFollowTargetEyeOffset.y * v19[36];
      v21 = v3->mFollowTargetEyeOffset.y * v19[37];
      v22 = v3->mFollowTargetEyeOffset.y * v19[38];
      v23 = (float *)v3->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v3->mTargetTransform);
      v24 = v3->mFollowTargetEyeOffset.x * v23[32];
      v25 = v3->mFollowTargetEyeOffset.x * v23[33];
      v26 = v3->mFollowTargetEyeOffset.x * v23[34];
      v27 = (float *)v3->mTargetTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v3->mTargetTransform);
      v28 = v18 + (float)((float)(v25 + v27[45]) + v21);
      v29 = v16 + (float)((float)(v26 + v27[46]) + v22);
      v3->mEye.p1.x = v17 + (float)((float)(v24 + v27[44]) + v20);
      v3->mEye.p1.y = v28;
      v3->mEye.p1.z = v29;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
      *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
      v3->mEye.mParameter.z = 0.0;
      v30 = v3->mEye.p1.y;
      v31 = v3->mEye.p1.z;
      v3->mEye.p0.x = v3->mEye.p1.x;
      v3->mEye.p0.y = v30;
      v3->mEye.p0.z = v31;
      v32 = v3->mEye.v1.y;
      v33 = v3->mEye.v1.z;
      v3->mEye.v0.x = v3->mEye.v1.x;
      v3->mEye.v0.y = v32;
      v3->mEye.v0.z = v33;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
LABEL_13:
      v3->mEye.mParameter.z = 0.0;
      *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
      goto LABEL_14;
    }
    if ( !v3->mbPanning )
    {
      v34 = v3->mCameraTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v3->mCameraTransform);
      UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(&v3->mEye, (UFG::qVector3 *)&v34->mWorldTransform.v3);
      v35 = v3->mEye.p1.y;
      v36 = v3->mEye.p1.z;
      v3->mEye.p0.x = v3->mEye.p1.x;
      v3->mEye.p0.y = v35;
      v3->mEye.p0.z = v36;
      v37 = v3->mEye.v1.y;
      v38 = v3->mEye.v1.z;
      v3->mEye.v0.x = v3->mEye.v1.x;
      v3->mEye.v0.y = v37;
      v3->mEye.v0.z = v38;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
      goto LABEL_13;
    }
  }
LABEL_14:
  if ( v3->mbAttached )
  {
    v39 = v3->mCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3->mCameraTransform);
    v40 = v39->mWorldTransform.v3.y;
    v41 = v39->mWorldTransform.v3.z;
    v3->mEye.p1.x = v39->mWorldTransform.v3.x;
    v3->mEye.p1.y = v40;
    v3->mEye.p1.z = v41;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
    *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
    v3->mEye.mParameter.z = 0.0;
    if ( !v3->mbPanning )
    {
      v42 = v3->mEye.p1.y;
      v43 = v3->mEye.p1.z;
      v3->mEye.p0.x = v3->mEye.p1.x;
      v3->mEye.p0.y = v42;
      v3->mEye.p0.z = v43;
      v44 = v3->mEye.v1.y;
      v45 = v3->mEye.v1.z;
      v3->mEye.v0.x = v3->mEye.v1.x;
      v3->mEye.v0.y = v44;
      v3->mEye.v0.z = v45;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
      *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
      v3->mEye.mParameter.z = 0.0;
    }
    v46 = (float *)v3->mCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3->mCameraTransform);
    v47 = (float *)v3->mCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3->mCameraTransform);
    v48 = v47[45] + v46[33];
    v49 = v47[46] + v46[34];
    v3->mLook.p1.x = v47[44] + v46[32];
    v3->mLook.p1.y = v48;
    v3->mLook.p1.z = v49;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
    *(_QWORD *)&v3->mLook.mParameter.x = 0i64;
    v3->mLook.mParameter.z = 0.0;
    v50 = v3->mLook.p1.y;
    v51 = v3->mLook.p1.z;
    v3->mLook.p0.x = v3->mLook.p1.x;
    v3->mLook.p0.y = v50;
    v3->mLook.p0.z = v51;
    v52 = v3->mLook.v1.y;
    v53 = v3->mLook.v1.z;
    v3->mLook.v0.x = v3->mLook.v1.x;
    v3->mLook.v0.y = v52;
    v3->mLook.v0.z = v53;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
    *(_QWORD *)&v3->mLook.mParameter.x = 0i64;
    v3->mLook.mParameter.z = 0.0;
  }
  if ( v3->mbPanning )
  {
    v54 = v3->mNextCameraTransform;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3->mNextCameraTransform);
    v55 = v54->mWorldTransform.v3.y;
    v56 = v54->mWorldTransform.v3.z;
    v3->mEye.p1.x = v54->mWorldTransform.v3.x;
    v3->mEye.p1.y = v55;
    v3->mEye.p1.z = v56;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
    *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
    v3->mEye.mParameter.z = 0.0;
    if ( !v3->mbFollowTarget )
    {
      v57 = (float *)v3->mNextCameraTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v3->mNextCameraTransform);
      v58 = (float *)v3->mNextCameraTransform;
      UFG::TransformNodeComponent::UpdateWorldTransform(v3->mNextCameraTransform);
      v59 = v58[45] + v57[33];
      v60 = v58[46] + v57[34];
      v3->mLook.p1.x = v58[44] + v57[32];
      v3->mLook.p1.y = v59;
      v3->mLook.p1.z = v60;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
      *(_QWORD *)&v3->mLook.mParameter.x = 0i64;
      v3->mLook.mParameter.z = 0.0;
    }
  }
  v61 = (float)(v3->mFov.p0 * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    v61 = Render::GetExtraWideAspectCorrectedFOV(v61);
  v62 = Render::GetDisplayAspectRatio();
  if ( UFG::ScriptCameraComponent::mbUserInputEnabled )
  {
    turn = UFG::qVector3::msZero;
    UFG::ScriptCameraComponent::UpdateInput(v3, v4, &turn);
    UFG::ScriptCameraComponent::UpdateMovement(v3, &turn);
    UFG::Camera::SetViewProjection(&v3->mCamera, v61, v62, UFG::gCameraDefaultNear, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
  }
  else
  {
    v63 = 0;
    if ( v3->mDofSnapNext )
    {
      v63 = 1;
      v3->mDofSnapNext = 0;
    }
    UFG::GameCameraComponent::UpdateDof((UFG::GameCameraComponent *)&v3->vfptr, v4, &v3->mDofParameters, v63);
    v64 = UFG::qNoise<UFG::qVector3,float>::GetValue(&v3->mEyeNoise, &turn, v3->mElapsedSeconds);
    v65 = v3->mEyeNoiseMagnitude;
    v66 = v3->mLook.p0.x;
    v71 = LODWORD(v3->mLook.p0.y);
    v67 = v3->mEye.p0.z + (float)(v65 * v64->z);
    v68 = v3->mEye.p0.y + (float)(v3->mEyeNoiseMagnitude * v64->y);
    v69 = v3->mEye.p0.x + (float)(v65 * v64->x);
    desLook.z = v3->mLook.p0.z;
    desLook.x = v66;
    v70 = v66 - v69;
    LODWORD(desLook.y) = v71;
    *(float *)&v71 = *(float *)&v71 - v68;
    v72 = (__m128)v71;
    desEye.x = v69;
    v72.m128_f32[0] = (float)((float)(*(float *)&v71 * *(float *)&v71) + (float)(v70 * v70))
                    + (float)((float)(desLook.z - v67) * (float)(desLook.z - v67));
    desEye.y = v68;
    desEye.z = v67;
    if ( v72.m128_f32[0] == 0.0 )
      v73 = 0.0;
    else
      v73 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v72));
    v74 = v70 * v73;
    v75 = *(float *)&v71 * v73;
    v76 = v3->mLookOffset.z * 0.0;
    v77 = (float)((float)(v3->mLookOffset.x * v74) + (float)(v3->mLookOffset.y * v75)) + v76;
    v78 = (float)((float)(v3->mLookOffset.x * v75) + (float)(v3->mLookOffset.y * COERCE_FLOAT(LODWORD(v74) ^ _xmm[0])))
        + v76;
    v79 = (float)((float)(v3->mLookOffset.x * 0.0) + (float)(v3->mLookOffset.y * 0.0)) + v3->mLookOffset.z;
    v80 = UFG::qNoise<UFG::qVector3,float>::GetValue(&v3->mLookNoise, &turn, v3->mElapsedSeconds + 511.0);
    v81 = v3->mLookNoiseMagnitude;
    v82 = v81;
    v83 = (float)(v81 * v80->z) + v79;
    v84 = (float)(v82 * v80->y) + v78;
    desLook.x = desLook.x + (float)((float)(v3->mLookNoiseMagnitude * v80->x) + v77);
    desLook.y = desLook.y + v84;
    desLook.z = desLook.z + v83;
    UFG::GameCameraComponent::SetDesiredEyeLookUp(
      (UFG::GameCameraComponent *)&v3->vfptr,
      0.0,
      &desEye,
      &desLook,
      a3,
      &UFG::qVector3::msDirUp,
      0,
      0i64,
      0i64);
    UFG::Camera::SetViewProjection(&v3->mCamera, v61, v62, UFG::gCameraDefaultNear, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
    UFG::Camera::ApplyDutch(&v3->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
  }
}

// File Line: 468
// RVA: 0x3C5D40
void __fastcall UFG::ScriptCameraComponent::InitUserControlledCamera(UFG::ScriptCameraComponent *this)
{
  UFG::ScriptCameraComponent *v1; // rdi
  float *v2; // rbx
  __m128 v3; // xmm1

  v1 = this;
  UFG::TransformNodeComponent::UpdateWorldTransform(this->mCameraTransform);
  v2 = (float *)v1->mCameraTransform;
  UFG::TransformNodeComponent::UpdateWorldTransform(v1->mCameraTransform);
  v3 = (__m128)*((unsigned int *)v2 + 32);
  v3.m128_f32[0] = (float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v2[33] * v2[33]);
  v1->mLatitude = atan2f(v2[34], COERCE_FLOAT(_mm_sqrt_ps(v3)));
  v1->mLongitude = atan2f(v2[33], v2[32]);
  *(_QWORD *)&v1->mTurnX = 0i64;
}

// File Line: 482
// RVA: 0x3DCC20
void __fastcall UFG::ScriptCameraComponent::UpdateInput(UFG::ScriptCameraComponent *this, const float delta_sec, UFG::qVector3 *turn)
{
  __int64 v3; // r9
  UFG::InputActionData *v4; // rax
  UFG::ScriptCameraComponent *v5; // rbx
  float v6; // xmm4_4
  __int64 v7; // rdx
  UFG::InputActionData *v8; // rax
  float v9; // xmm1_4
  UFG::InputSystem *v10; // r10
  UFG::InputActionData *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm3_4
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

  v3 = (signed int)UFG::gActiveControllerNum;
  v4 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
  v5 = this;
  v6 = delta_sec * 0.40000001;
  v7 = (signed int)UFG::gActiveControllerNum;
  if ( v4 && v4->mActionTrue )
  {
    turn->x = turn->x - (float)(v4->mAxisPositionY * v6);
    v8 = UFG::ActionDef_UIRightThumbstick.mDataPerController[v3];
    if ( v8 )
      v9 = v8->mAxisPositionX;
    else
      v9 = 0.0;
    turn->y = turn->y - (float)(v9 * v6);
    LODWORD(v3) = UFG::gActiveControllerNum;
  }
  v10 = UFG::gInputSystem;
  if ( UFG::gInputSystem->mControllers[(signed int)v3]->m_IsKeyboardController )
  {
    v11 = UFG::ActionDef_Mouse.mDataPerController[(signed int)v3];
    if ( v11 )
      v12 = v11->mAxisPositionX;
    else
      v12 = 0.0;
    v13 = v12 * UFG::gMousePosMultiplier;
    if ( v11 )
      v14 = v11->mAxisPositionY;
    else
      v14 = 0.0;
    turn->x = turn->x - (float)((float)(v14 * UFG::gMousePosMultiplier) * v6);
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
  if ( v10->mControllers[(signed int)v3]->m_IsKeyboardController )
  {
    v19 = UFG::ActionDef_CamZoomIn.mDataPerController[v7];
    v20 = 1;
    v21 = v19 && v19->mActionTrue;
    v22 = _mm_cvtsi32_si128(v21);
    v23 = UFG::ActionDef_CamZoomOut.mDataPerController[v7];
    v16 = COERCE_FLOAT(_mm_cvtepi32_ps(v22)) * UFG::gMouseZoomMultiplier;
    if ( !v23 || !v23->mActionTrue )
      v20 = 0;
    v18 = (float)v20 * UFG::gMouseZoomMultiplier;
  }
  if ( v16 <= 0.0 )
  {
    if ( v18 <= 0.0 )
      return;
    v25 = v18 + v5->mFov.p1;
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
    v5->mFov.p1 = v26;
    goto LABEL_43;
  }
  v24 = v5->mFov.p1 - v16;
  if ( v24 <= 35.0 )
  {
    v24 = FLOAT_35_0;
    goto LABEL_35;
  }
  if ( v24 < 85.0 )
  {
LABEL_35:
    v5->mFov.p1 = v24;
    goto LABEL_43;
  }
  v5->mFov.p1 = FLOAT_85_0;
LABEL_43:
  UFG::HomerCubic<float>::MakeCoeffs(&v5->mFov);
  v5->mFov.mParameter = 0.0;
}

// File Line: 610
// RVA: 0x3DD2B0
void __fastcall UFG::ScriptCameraComponent::UpdateMovement(UFG::ScriptCameraComponent *this, UFG::qVector3 *turn)
{
  UFG::ScriptCameraComponent *v2; // rdi
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
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  UFG::SimObject *v16; // r13
  __int64 v17; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v18; // r15
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4
  signed __int64 v23; // rsi
  UFG::SimObject **v24; // r14
  UFG::SimObjectGame *v25; // rbx
  UFG::CharacterSubjectComponent *v26; // rax
  UFG::CharacterSubjectComponent *v27; // r14
  float v28; // xmm6_4
  unsigned __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  float v31; // xmm1_4
  float v32; // xmm2_4
  __int64 v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v36; // rax
  signed __int64 i; // rax
  _QWORD *v38; // rdx
  __int64 v39; // rcx
  _QWORD *v40; // rax
  __int64 v41; // rcx
  _QWORD *v42; // rax
  UFG::qVector3 up; // [rsp+8h] [rbp-71h]
  UFG::qVector3 look; // [rsp+18h] [rbp-61h]
  UFG::qVector3 eye; // [rsp+28h] [rbp-51h]
  UFG::qVector3 ray_dir; // [rsp+38h] [rbp-41h]
  UFG::HighlightParams highlight_params; // [rsp+48h] [rbp-31h]
  __int64 v48; // [rsp+E0h] [rbp+67h]

  v2 = this;
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
  ray_dir.x = v12 * v10;
  ray_dir.y = v11 * v10;
  ray_dir.z = v9;
  up.x = (float)((float)(v11 * v10) * 0.0) - (float)(v12 * v9);
  up.y = (float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v9) - (float)((float)(v12 * v10) * 0.0);
  up.z = (float)((float)(v12 * v10) * v12) - (float)((float)(v11 * v10) * COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]));
  v13 = v2->mEye.p0.y;
  v14 = v2->mEye.p0.z;
  eye.x = v2->mEye.p0.x;
  eye.y = v13;
  eye.z = v14;
  UFG::Camera::SetLookAtMatrix(&v2->mCamera, &eye, &look, &up);
  if ( v2->mbProfiling )
  {
    v15 = FLOAT_1_0e8;
    v16 = 0i64;
    v17 = 0i64;
    v48 = 0i64;
    v18 = &v2->mHighlightedCharacter;
    if ( v2->mHighlightedCharacter.m_pPointer )
    {
      v19 = v18->mPrev;
      v20 = v2->mHighlightedCharacter.mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
      v2->mHighlightedCharacter.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mHighlightedCharacter.mPrev;
    }
    v2->mHighlightedCharacter.m_pPointer = 0i64;
    v2->mbHighlightOn = 0;
    *(_QWORD *)&look.x = &look;
    *(_QWORD *)&look.z = &look;
    v21 = v2->mEye.p0.y;
    v22 = v2->mEye.p0.z;
    eye.x = v2->mEye.p0.x;
    eye.y = v21;
    eye.z = v22;
    UFG::NearbyCharacterManager::GetNearbyCharactersAll(
      UFG::NearbyCharacterManager::s_pInstance,
      (UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> *)&look,
      &eye);
    v23 = *(_QWORD *)&look.z - 16i64;
    if ( (UFG::qVector3 *)(*(_QWORD *)&look.z - 16i64) != &up )
    {
      do
      {
        v24 = *(UFG::SimObject ***)(v23 + 48);
        if ( v24 )
        {
          v25 = (UFG::SimObjectGame *)v24[5];
          if ( !v25 )
            goto LABEL_50;
          UFG::UnHighlightSimObject(v24[5]);
          if ( !((unsigned __int8 (__fastcall *)(UFG::SimObject **))(*v24)->m_UnboundComponentHandles.mNode.mPrev)(v24) )
            goto LABEL_50;
          v26 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v25->vfptr,
                                                    UFG::CharacterSubjectComponent::_TypeUID);
          v27 = v26;
          if ( !v26 )
            goto LABEL_50;
          if ( v26->mPelvisDirty )
            UFG::CharacterSubjectComponent::UpdatePelvis(v26);
          v28 = (float)((float)((float)(v2->mEye.p0.y - v27->mPelvisPosition.y)
                              * (float)(v2->mEye.p0.y - v27->mPelvisPosition.y))
                      + (float)((float)(v2->mEye.p0.x - v27->mPelvisPosition.x)
                              * (float)(v2->mEye.p0.x - v27->mPelvisPosition.x)))
              + (float)((float)(v2->mEye.p0.z - v27->mPelvisPosition.z) * (float)(v2->mEye.p0.z - v27->mPelvisPosition.z));
          if ( v28 > 3600.0 )
            goto LABEL_50;
          v29 = v25->m_Flags;
          if ( (v29 >> 14) & 1 )
          {
            v30 = v25->m_Components.p[44].m_pComponent;
          }
          else if ( (v29 & 0x8000u) == 0 )
          {
            if ( (v29 >> 13) & 1 )
              v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v25, UFG::CharacterOccupantComponent::_TypeUID);
            else
              v30 = (v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v25,
                                        UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v25->vfptr,
                                                                                       UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v25, UFG::CharacterOccupantComponent::_TypeUID);
          }
          if ( !v30
            && (v31 = v2->mEye.p0.y,
                v32 = v2->mEye.p0.z,
                eye.x = v2->mEye.p0.x,
                eye.y = v31,
                eye.z = v32,
                UFG::qDistanceRayPoint(&eye, &ray_dir, &v27->mPelvisPosition) <= 0.69999999)
            && v28 < v15 )
          {
            v17 = v23;
            v48 = v23;
            v15 = v28;
          }
          else
          {
LABEL_50:
            v17 = v48;
          }
        }
        v23 = *(_QWORD *)(v23 + 24) - 16i64;
      }
      while ( (UFG::qVector3 *)v23 != &up );
      if ( v17 )
      {
        v33 = *(_QWORD *)(v17 + 48);
        if ( v33 )
          v16 = *(UFG::SimObject **)(v33 + 40);
        if ( v2->mHighlightedCharacter.m_pPointer )
        {
          v34 = v18->mPrev;
          v35 = v2->mHighlightedCharacter.mNext;
          v34->mNext = v35;
          v35->mPrev = v34;
          v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
          v2->mHighlightedCharacter.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mHighlightedCharacter.mPrev;
        }
        v2->mHighlightedCharacter.m_pPointer = v16;
        if ( v16 )
        {
          v36 = v16->m_SafePointerList.mNode.mPrev;
          v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
          v18->mPrev = v36;
          v2->mHighlightedCharacter.mNext = &v16->m_SafePointerList.mNode;
          v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
        }
        highlight_params.mColour = UFG::qColour::White;
        LODWORD(highlight_params.mOutlineStrength) = (_DWORD)FLOAT_1_0;
        highlight_params.mXrayStrength = 0.0;
        highlight_params.mIsDepthEnabled = 0;
        UFG::HighlightSimObject(v2->mHighlightedCharacter.m_pPointer, &highlight_params);
        v2->mbHighlightOn = 1;
      }
    }
    for ( i = *(_QWORD *)&look.z - 16i64;
          (UFG::qVector3 *)(*(_QWORD *)&look.z - 16i64) != &up;
          i = *(_QWORD *)&look.z - 16i64 )
    {
      v38 = (_QWORD *)(i + 16);
      v39 = *(_QWORD *)(i + 16);
      v40 = *(_QWORD **)(i + 24);
      *(_QWORD *)(v39 + 8) = v40;
      *v40 = v39;
      *v38 = v38;
      v38[1] = v38;
    }
    v41 = *(_QWORD *)&look.x;
    v42 = *(_QWORD **)&look.z;
    *(_QWORD *)(*(_QWORD *)&look.x + 8i64) = *(_QWORD *)&look.z;
    *v42 = v41;
  }
}

// File Line: 705
// RVA: 0x3CC8D0
void __fastcall UFG::ScriptCameraComponent::SetEyeWorld(UFG::ScriptCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *v5; // rdi
  UFG::qVector3 *v6; // rbx
  float v7; // eax
  float v8; // xmm1_4

  v3 = position->y;
  v4 = position->z;
  v5 = &this->mEye;
  v6 = velocity;
  v5->p0.x = position->x;
  v5->p0.y = v3;
  v5->p0.z = v4;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&v5->mParameter.x = 0i64;
  v5->mParameter.z = 0.0;
  v7 = v6->x;
  v8 = v6->z;
  v5->v0.y = v6->y;
  v5->v0.z = v8;
  v5->v0.x = v7;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v5);
  *(_QWORD *)&v5->mParameter.x = 0i64;
  v5->mParameter.z = 0.0;
}

// File Line: 711
// RVA: 0x3CCF00
void __fastcall UFG::ScriptCameraComponent::SetLookWorld(UFG::ScriptCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *v5; // rdi
  UFG::qVector3 *v6; // rbx
  float v7; // eax
  float v8; // xmm1_4

  v3 = position->y;
  v4 = position->z;
  v5 = &this->mLook;
  v6 = velocity;
  v5->p0.x = position->x;
  v5->p0.y = v3;
  v5->p0.z = v4;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&v5->mParameter.x = 0i64;
  v5->mParameter.z = 0.0;
  v7 = v6->x;
  v8 = v6->z;
  v5->v0.y = v6->y;
  v5->v0.z = v8;
  v5->v0.x = v7;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v5);
  *(_QWORD *)&v5->mParameter.x = 0i64;
  v5->mParameter.z = 0.0;
}

// File Line: 717
// RVA: 0x3C33C0
void __fastcall UFG::ScriptCameraComponent::GetEyeWorld(UFG::ScriptCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v3 = this->mEye.p0.y;
  v4 = this->mEye.p0.z;
  position->x = this->mEye.p0.x;
  position->y = v3;
  position->z = v4;
  v5 = this->mEye.v0.y;
  v6 = this->mEye.v0.z;
  velocity->x = this->mEye.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 723
// RVA: 0x3C3890
void __fastcall UFG::ScriptCameraComponent::GetLookWorld(UFG::ScriptCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v3 = this->mLook.p0.y;
  v4 = this->mLook.p0.z;
  position->x = this->mLook.p0.x;
  position->y = v3;
  position->z = v4;
  v5 = this->mLook.v0.y;
  v6 = this->mLook.v0.z;
  velocity->x = this->mLook.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 729
// RVA: 0x3C3530
void __fastcall UFG::ScriptCameraComponent::GetFovRadians(UFG::ScriptCameraComponent *this, float *fov, float *fov_velocity)
{
  *fov_velocity = this->mFov.v0 * 0.017453292;
  *fov = this->mFov.p0 * 0.017453292;
}

// File Line: 743
// RVA: 0x3C5570
bool __fastcall UFG::TurfCameraComponent::HasComponent(UFG::SceneObjectProperties *sceneObj)
{
  return PropertyUtils::HasComponentPropertySet(sceneObj, (UFG::qSymbol *)&SimSymX_propset_componentScriptCamera.mUID);
}

// File Line: 752
// RVA: 0x3C8320
void __fastcall UFG::ScriptCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x760ui64, "ScriptCameraComponent", 0i64, 1u);
  if ( v3 )
    UFG::ScriptCameraComponent::ScriptCameraComponent((UFG::ScriptCameraComponent *)v3, v1->m_NameUID, v1->m_pSimObject);
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
  UFG::ScriptCameraComponent *v1; // rbx

  v1 = this;
  if ( this->mbHighlightOn )
  {
    UFG::UnHighlightSimObject(this->mHighlightedCharacter.m_pPointer);
    v1->mbProfiling = 0;
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

