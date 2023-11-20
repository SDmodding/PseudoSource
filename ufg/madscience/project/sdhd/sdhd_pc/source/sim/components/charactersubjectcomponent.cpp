// File Line: 61
// RVA: 0x1543DE0
__int64 dynamic_initializer_for__UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList__);
}

// File Line: 62
// RVA: 0x15430A0
__int64 dynamic_initializer_for__UFG::CharacterSubjectComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::CharacterSubjectComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::CharacterSubjectComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::CharacterSubjectComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::CharacterSubjectComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 67
// RVA: 0x516450
void __fastcall UFG::CharacterSubjectComponent::CharacterSubjectComponent(UFG::CharacterSubjectComponent *this, unsigned int name_uid)
{
  UFG::CharacterSubjectComponent *v2; // rdi
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v3; // rbx
  signed __int64 v4; // rbp
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0> *v5; // rsi
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v6; // rax
  UFG::qSymbol *v7; // rcx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax

  v2 = this;
  UFG::CameraSubject::CameraSubject((UFG::CameraSubject *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterSubjectComponent::`vftable';
  v4 = 4i64;
  `eh vector constructor iterator'(
    v2->mContextOverrideScriptGlobal,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator'(
    v2->mContextOverrideFreemanNPC,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator'(
    v2->mContextOverrideFreemanPlayer,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator'(
    v2->mContextOverrideScriptLocal,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  *(_QWORD *)&v2->mBox.mMin.x = 0i64;
  *(_QWORD *)&v2->mBox.mMin.z = 0i64;
  *(_QWORD *)&v2->mBox.mMax.y = 0i64;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&v2->pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v2->pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v2->pTargetingSystemBaseComponent);
  v5 = &v2->pSocialTargetOverrideComponent;
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>(&v2->pSocialTargetOverrideComponent);
  v6 = UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mPrev;
  UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *)&v2->mPrev;
  v3->mPrev = v6;
  v2->mNext = (UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *)&UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList;
  UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mPrev = (UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::CharacterSubjectComponent::_CharacterSubjectComponentTypeUID,
    "CharacterSubjectComponent");
  *(_QWORD *)&v2->mIsHostage = 0i64;
  *(_WORD *)&v2->mSprinting = 0;
  *(_QWORD *)&v2->mActionHijacking = 0i64;
  v7 = (UFG::qSymbol *)&v2->mContextOverrideScriptGlobal[0].mUID;
  do
  {
    v7[-1].mUID = UFG::gNullQSymbol.mUID;
    v7->mUID = -1;
    v7[7].mUID = UFG::gNullQSymbol.mUID;
    v7[8].mUID = -1;
    v7[15].mUID = UFG::gNullQSymbol.mUID;
    v7[16].mUID = -1;
    v7[23].mUID = UFG::gNullQSymbol.mUID;
    v7[24].mUID = -1;
    v7 += 2;
    --v4;
  }
  while ( v4 );
  v2->mTypeOverrideFreeman = -1;
  v2->bGotoRise = 0;
  *(_QWORD *)&v2->rGotoRise = 0i64;
  v2->rGotoRisePatience = 0.0;
  v2->bGotoRadius = 0;
  *(_QWORD *)&v2->rGotoRadius = 0i64;
  v2->rGotoRadiusPatience = 0.0;
  v2->bGotoAngle = 0;
  *(_QWORD *)&v2->rGotoAngle = 0i64;
  v2->rGotoAnglePatience = 0.0;
  *(_WORD *)&v2->bGotoAngleWorldSpace = 0;
  v2->rGotoAngleSecond = 0.0;
  *(_WORD *)&v2->bGotoAngleFarthestAngle = 0;
  v2->bElevationLock = 0;
  *(_QWORD *)&v2->rLockedElevationDef = 0i64;
  *(_QWORD *)&v2->rLockedElevationHip = 0i64;
  *(_QWORD *)&v2->rLockedElevationFocusCreatureCambone = 0i64;
  v2->rLockedElevationFocusCreatureHead = 0.0;
  v2->mParkourHandle = 0i64;
  v2->mFilteredSpeed = 0.0;
  v2->mPositionFilterSpeed = 1.0;
  v2->mVelocityFilterSpeed = 10.0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v2->mFilteredPosition.x = UFG::qVector3::msZero.x;
  v2->mFilteredPosition.y = v8;
  v2->mFilteredPosition.z = v9;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  v2->mFilteredVelocity.x = UFG::qVector3::msZero.x;
  v2->mFilteredVelocity.y = v10;
  v2->mFilteredVelocity.z = v11;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v2->mLastAliveHeadPosition.x = UFG::qVector3::msZero.x;
  v2->mLastAliveHeadPosition.y = v12;
  v2->mLastAliveHeadPosition.z = v13;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  v2->mAntiJitterPosition.x = UFG::qVector3::msZero.x;
  v2->mAntiJitterPosition.y = v14;
  v2->mAntiJitterPosition.z = v15;
  v16 = UFG::qVector3::msZero.y;
  v17 = UFG::qVector3::msZero.z;
  v2->mGrapplePosition.x = UFG::qVector3::msZero.x;
  v2->mGrapplePosition.y = v16;
  v2->mGrapplePosition.z = v17;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  v2->mHeadPosition.x = UFG::qVector3::msZero.x;
  v2->mHeadPosition.y = v18;
  v2->mHeadPosition.z = v19;
  v20 = UFG::qVector3::msZero.y;
  v21 = UFG::qVector3::msZero.z;
  v2->mCambonePosition.x = UFG::qVector3::msZero.x;
  v2->mCambonePosition.y = v20;
  v2->mCambonePosition.z = v21;
  v22 = UFG::qVector3::msZero.y;
  v23 = UFG::qVector3::msZero.z;
  v2->mPelvisPosition.x = UFG::qVector3::msZero.x;
  v2->mPelvisPosition.y = v22;
  v2->mPelvisPosition.z = v23;
  v24 = UFG::qVector3::msZero.y;
  v25 = UFG::qVector3::msZero.z;
  v2->mSyncPosition.x = UFG::qVector3::msZero.x;
  v2->mSyncPosition.y = v24;
  v2->mSyncPosition.z = v25;
  v26 = 0i64;
  v27 = 0i64;
  v27.m128_f32[0] = (float)1;
  v2->mHeadTransformation.v0 = (UFG::qVector4)v27;
  v2->mHeadTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps(v27, v27, 81);
  v2->mHeadTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps(v27, v27, 69);
  v2->mHeadTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps(v27, v27, 21);
  v28 = 0i64;
  v28.m128_f32[0] = (float)1;
  v2->mCamboneTransformation.v0 = (UFG::qVector4)v28;
  v2->mCamboneTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps(v28, v28, 81);
  v2->mCamboneTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps(v28, v28, 69);
  v2->mCamboneTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps(v28, v28, 21);
  v29 = 0i64;
  v29.m128_f32[0] = (float)1;
  v2->mPelvisTransformation.v0 = (UFG::qVector4)v29;
  v2->mPelvisTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps(v29, v29, 81);
  v2->mPelvisTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps(v29, v29, 69);
  v2->mPelvisTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps(v29, v29, 21);
  v30 = 0i64;
  v30.m128_f32[0] = (float)1;
  v2->mSyncTransformation.v0 = (UFG::qVector4)v30;
  v2->mSyncTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps(v30, v30, 81);
  v2->mSyncTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps(v30, v30, 69);
  v2->mSyncTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps(v30, v30, 21);
  *(_QWORD *)&v2->mBoneHead = -1i64;
  *(_QWORD *)&v2->mBonePelvis = -1i64;
  v2->mRadius = 0.0;
  v31 = UFG::qVector3::msZero.y;
  v32 = UFG::qVector3::msZero.z;
  v2->mBox.mMin.x = UFG::qVector3::msZero.x;
  v2->mBox.mMin.y = v31;
  v2->mBox.mMin.z = v32;
  v33 = UFG::qVector3::msZero.y;
  v34 = UFG::qVector3::msZero.z;
  v2->mBox.mMax.x = UFG::qVector3::msZero.x;
  v2->mBox.mMax.y = v33;
  v2->mBox.mMax.z = v34;
  if ( v2->pSocialTargetOverrideComponent.m_pSimComponent )
  {
    v35 = v5->mPrev;
    v36 = v2->pSocialTargetOverrideComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    v2->pSocialTargetOverrideComponent.m_pSimComponent = 0i64;
LABEL_9:
    v2->pSocialTargetOverrideComponent.m_pSimObject = 0i64;
    v2->pSocialTargetOverrideComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pSocialTargetOverrideComponent.mPrev;
    v5->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v5->mPrev;
    goto LABEL_10;
  }
  if ( v2->pSocialTargetOverrideComponent.m_pSimObject )
  {
    v37 = v5->mPrev;
    if ( (UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0> *)v5->mPrev != v5
      || (UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0> *)v2->pSocialTargetOverrideComponent.mNext != &v2->pSocialTargetOverrideComponent )
    {
      v38 = v2->pSocialTargetOverrideComponent.mNext;
      v37->mNext = v38;
      v38->mPrev = v37;
      goto LABEL_9;
    }
  }
LABEL_10:
  v2->pSocialTargetOverrideComponent.m_Changed = 1;
  v2->pSocialTargetOverrideComponent.m_TypeUID = UFG::CharacterSubjectComponent::_TypeUID;
  *(_DWORD *)&v2->mHeadDirty = 16843009;
  v26.m128_f32[0] = (float)1;
  v2->mTargetWorld.v0 = (UFG::qVector4)v26;
  v2->mTargetWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v26, v26, 81);
  v2->mTargetWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v26, v26, 69);
  v2->mTargetWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v26, v26, 21);
}

// File Line: 159
// RVA: 0x51B120
void __fastcall UFG::CharacterSubjectComponent::~CharacterSubjectComponent(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent *v1; // rdi
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v2; // rbx
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v3; // rcx
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v4; // rax
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v5; // rcx
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterSubjectComponent::`vftable';
  if ( this == UFG::CharacterSubjectComponent::s_CharacterSubjectComponentpCurrentIterator )
    UFG::CharacterSubjectComponent::s_CharacterSubjectComponentpCurrentIterator = (UFG::CharacterSubjectComponent *)&this->mPrev[-18];
  v2 = (UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pSocialTargetOverrideComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pCharacterPhysicsComponent);
  `eh vector destructor iterator'(v1->mContextOverrideScriptLocal, 8ui64, 4, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mContextOverrideFreemanPlayer, 8ui64, 4, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mContextOverrideFreemanNPC, 8ui64, 4, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mContextOverrideScriptGlobal, 8ui64, 4, (void (__fastcall *)(void *))_);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::CameraSubject::~CameraSubject((UFG::CameraSubject *)&v1->vfptr);
}

// File Line: 164
// RVA: 0x530BA0
UFG::TransformNodeComponent *__fastcall UFG::RegionComponent::GetXformNode(UFG::RegionComponent *this)
{
  UFG::TransformNodeComponent *result; // rax

  result = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( result )
    result = (UFG::TransformNodeComponent *)result->mChildren.mNode.mNext;
  return result;
}

// File Line: 165
// RVA: 0x530AE0
UFG::SimComponent *__fastcall UFG::CharacterSubjectComponent::GetTargetingSystem(UFG::CharacterSubjectComponent *this)
{
  return this->pTargetingSystemBaseComponent.m_pSimComponent;
}

// File Line: 175
// RVA: 0x546110
UFG::SimComponent *__fastcall UFG::CharacterSubjectComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *scene_object_properties, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  unsigned int v3; // edi
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *v8; // rdx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v2 = scene_object_properties;
  v3 = scene_object_properties->m_NameUID;
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0x4E0ui64, "CharacterSubjectComponent", 0i64, 1u);
  if ( v5 )
  {
    UFG::CharacterSubjectComponent::CharacterSubjectComponent((UFG::CharacterSubjectComponent *)v5, v3);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v2->m_pSimObject;
  if ( (v8->m_Flags >> 14) & 1 )
    v9 = 37;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v8, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v7, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v7;
}

// File Line: 186
// RVA: 0x53D5B0
void __fastcall UFG::CharacterSubjectComponent::OnAttach(UFG::CharacterSubjectComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectCharacter *v2; // rbx
  UFG::CharacterSubjectComponent *v3; // rdi
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = (UFG::SimObjectCharacter *)object;
  v3 = this;
  UFG::CameraSubject::OnAttach((UFG::CameraSubject *)&this->vfptr, object);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v3->pCharacterPhysicsComponent,
    v2);
  v4 = &v3->pCharacterAnimationComponent;
  if ( v3->pCharacterAnimationComponent.m_pSimComponent )
  {
    v5 = v3->pCharacterAnimationComponent.mNext;
    v6 = v4->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->pCharacterAnimationComponent.m_pSimObject = 0i64;
    v3->pCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->pCharacterAnimationComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->pCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->pCharacterAnimationComponent.mNext != &v3->pCharacterAnimationComponent) )
  {
    v7 = v3->pCharacterAnimationComponent.mNext;
    v8 = v4->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->pCharacterAnimationComponent.m_Changed = 1;
  v3->pCharacterAnimationComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->pCharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(v4, v2);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v3->pTargetingSystemBaseComponent,
    v2);
  UFG::CharacterSubjectComponent::UpdateTargetWorld(v3);
}

// File Line: 198
// RVA: 0x53FF40
void __fastcall UFG::CharacterSubjectComponent::OnDetach(UFG::CharacterSubjectComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v1; // r8
  UFG::CharacterSubjectComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax

  v1 = &this->pTargetingSystemBaseComponent;
  v2 = this;
  if ( this->pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->pTargetingSystemBaseComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)this->pTargetingSystemBaseComponent.mNext != &this->pTargetingSystemBaseComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->pCharacterAnimationComponent;
  v1->m_Changed = 1;
  if ( v2->pCharacterAnimationComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->pCharacterAnimationComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->pCharacterAnimationComponent.m_pSimObject = 0i64;
    v2->pCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pCharacterAnimationComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->pCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v2->pCharacterAnimationComponent.mNext != &v2->pCharacterAnimationComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->pCharacterAnimationComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->pCharacterAnimationComponent.m_Changed = 1;
  v12 = &v2->pCharacterPhysicsComponent;
  if ( v2->pCharacterPhysicsComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->pCharacterPhysicsComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->pCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->pCharacterPhysicsComponent.m_pSimObject = 0i64;
    v2->pCharacterPhysicsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pCharacterPhysicsComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->pCharacterPhysicsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v2->pCharacterPhysicsComponent.mNext != &v2->pCharacterPhysicsComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->pCharacterPhysicsComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->pCharacterPhysicsComponent.m_Changed = 1;
  UFG::CameraSubject::OnDetach((UFG::CameraSubject *)&v2->vfptr);
  *(_QWORD *)&v2->mBoneHead = -1i64;
  *(_QWORD *)&v2->mBonePelvis = -1i64;
}

// File Line: 213
// RVA: 0x55F750
void __fastcall UFG::CharacterSubjectComponent::UpdateFilteredVelocity(UFG::CharacterSubjectComponent *this, float delta_sec, UFG::qVector3 *raw_velocity)
{
  __m128 v3; // xmm3
  float v4; // xmm5_4
  float v5; // xmm4_4
  __m128 v6; // xmm2
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4

  v3 = (__m128)LODWORD(raw_velocity->y);
  v3.m128_f32[0] = v3.m128_f32[0] - this->mFilteredVelocity.y;
  v4 = raw_velocity->z - this->mFilteredVelocity.z;
  v5 = COERCE_FLOAT(LODWORD(delta_sec) & _xmm) * this->mVelocityFilterSpeed;
  v6 = v3;
  v7 = this->mFilteredVelocity.x;
  v8 = raw_velocity->x - v7;
  v6.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v8 * v8)) + (float)(v4 * v4);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v6);
  if ( v5 > 0.00000011920929 && v9 > v5 )
  {
    v10 = v5 / v9;
    v8 = v8 * v10;
    v3.m128_f32[0] = v3.m128_f32[0] * v10;
    v4 = v4 * v10;
  }
  this->mFilteredVelocity.x = v7 + v8;
  v3.m128_f32[0] = v3.m128_f32[0] + this->mFilteredVelocity.y;
  v11 = v4 + this->mFilteredVelocity.z;
  LODWORD(this->mFilteredVelocity.y) = v3.m128_i32[0];
  this->mFilteredVelocity.z = v11;
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0])
                         + (float)(this->mFilteredVelocity.x * this->mFilteredVelocity.x))
                 + (float)(v11 * v11);
  LODWORD(this->mFilteredSpeed) = (unsigned __int128)_mm_sqrt_ps(v3);
}

// File Line: 226
// RVA: 0x55F670
void __fastcall UFG::CharacterSubjectComponent::UpdateFilteredPosition(UFG::CharacterSubjectComponent *this, float delta_sec)
{
  UFG::CharacterSubjectComponent *v2; // rbx
  __int64 v3; // rax
  float v4; // xmm7_4
  float v5; // xmm6_4
  __m128 v6; // xmm3
  float v7; // xmm4_4
  __m128 v8; // xmm2
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm4_4

  v2 = this;
  v3 = ((__int64 (*)(void))this->vfptr[17].__vecDelDtor)();
  v4 = v2->mFilteredPosition.x;
  v5 = COERCE_FLOAT(LODWORD(delta_sec) & _xmm) * v2->mPositionFilterSpeed;
  v6 = (__m128)*(unsigned int *)(v3 + 4);
  v6.m128_f32[0] = v6.m128_f32[0] - v2->mFilteredPosition.y;
  v7 = *(float *)(v3 + 8) - v2->mFilteredPosition.z;
  v8 = v6;
  v9 = *(float *)v3 - v4;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v9 * v9)) + (float)(v7 * v7);
  LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v8);
  if ( v5 > 0.00000011920929 && v10 > v5 )
  {
    v11 = v5 / v10;
    v9 = v9 * v11;
    v6.m128_f32[0] = v6.m128_f32[0] * v11;
    v7 = v7 * v11;
  }
  v2->mFilteredPosition.x = v4 + v9;
  v12 = v7 + v2->mFilteredPosition.z;
  v2->mFilteredPosition.y = v6.m128_f32[0] + v2->mFilteredPosition.y;
  v2->mFilteredPosition.z = v12;
}

// File Line: 238
// RVA: 0x52FC40
void __fastcall UFG::CharacterSubjectComponent::GetRigidBodyPosition(UFG::CharacterSubjectComponent *this, UFG::qVector3 *dest)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::qVector3 *v4; // rbx
  hkpRigidBody *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4

  v2 = this->mTargetWorld.v3.y;
  v3 = this->mTargetWorld.v3.z;
  v4 = dest;
  dest->x = this->mTargetWorld.v3.x;
  dest->y = v2;
  dest->z = v3;
  if ( this->pCharacterPhysicsComponent.m_pSimComponent )
  {
    v5 = UFG::CharacterPhysicsComponent::GetRigidBody((UFG::CharacterPhysicsComponent *)this->pCharacterPhysicsComponent.m_pSimComponent);
    if ( v5 )
    {
      v6 = v5->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
      v7 = v5->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
      v4->x = v5->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0];
      v4->y = v6;
      v4->z = v7;
    }
  }
}

// File Line: 252
// RVA: 0x561060
void __fastcall UFG::CharacterSubjectComponent::UpdateTargetWorld(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent *v1; // rbx
  float *v2; // rax
  float v3; // xmm10_4
  __m128 v4; // xmm11
  float v5; // xmm9_4
  float v6; // xmm0_4
  __m128 v7; // xmm1
  float v8; // xmm6_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float *v11; // rax
  float v12; // xmm10_4
  __m128 v13; // xmm6
  float v14; // xmm5_4
  float v15; // xmm9_4
  __m128 v16; // xmm2
  float v17; // xmm8_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm9_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v21; // rax
  float *v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4

  v1 = this;
  v2 = (float *)((__int64 (*)(void))this->vfptr[16].__vecDelDtor)();
  v3 = v2[2];
  v4 = (__m128)*(unsigned int *)v2;
  v5 = v2[1];
  LODWORD(v6) = (_DWORD)v2[2] & _xmm;
  if ( v6 > 0.80000001 )
  {
    if ( v6 >= 1.0 )
      v6 = *(float *)&FLOAT_1_0;
    v7 = (__m128)(unsigned int)FLOAT_1_0;
    v8 = sinf((float)(v6 - 0.80000001) * 7.8539824);
    v9 = v8 * v8;
    v7.m128_f32[0] = 1.0 - (float)(v9 * v9);
    LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v7);
    v11 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v1->vfptr[14].__vecDelDtor)(v1);
    v3 = (float)(v3 * v9) + (float)(v10 * v11[2]);
    v4.m128_f32[0] = (float)(v4.m128_f32[0] * v9) + (float)(v10 * *v11);
    v5 = (float)(v5 * v9) + (float)(v10 * v11[1]);
  }
  v13 = v4;
  v12 = v3 * 0.0;
  v13.m128_f32[0] = v4.m128_f32[0] - v12;
  v14 = v12 - v5;
  v16 = v13;
  v15 = (float)(v5 * 0.0) - (float)(v4.m128_f32[0] * 0.0);
  v16.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v14 * v14)) + (float)(v15 * v15);
  if ( v16.m128_f32[0] == 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
  v18 = v14 * v17;
  v19 = v13.m128_f32[0] * v17;
  v1->mTargetWorld.v0.w = 0.0;
  v20 = v15 * v17;
  v1->mTargetWorld.v0.z = (float)(v18 * 0.0) - (float)(v19 * 0.0);
  v1->mTargetWorld.v0.y = (float)(v20 * 0.0) - v18;
  v1->mTargetWorld.v0.x = v19 - (float)(v20 * 0.0);
  v1->mTargetWorld.v1.x = v18;
  *(_QWORD *)&v1->mTargetWorld.v1.w = 0i64;
  v1->mTargetWorld.v1.y = v19;
  v1->mTargetWorld.v1.z = v20;
  v1->mTargetWorld.v2.y = 0.0;
  v21 = v1->vfptr;
  *(_QWORD *)&v1->mTargetWorld.v2.z = 1065353216i64;
  v22 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v21[18].__vecDelDtor)(v1);
  v23 = v22[13];
  v24 = v22[14];
  v25 = v22[15];
  v1->mTargetWorld.v3.x = v22[12];
  v1->mTargetWorld.v3.y = v23;
  v1->mTargetWorld.v3.z = v24;
  v1->mTargetWorld.v3.w = v25;
}

// File Line: 295
// RVA: 0x154CC10
__int64 UFG::_dynamic_initializer_for__symBip01Head__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Head", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBip01Head, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symBip01Head__);
}

// File Line: 299
// RVA: 0x55F880
void __fastcall UFG::CharacterSubjectComponent::UpdateHead(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *v1; // rsi
  UFG::CharacterSubjectComponent *v2; // rdi
  signed int v3; // eax
  Creature *v4; // rsi
  int v5; // edx
  float v6; // xmm4_4
  float v7; // xmm2_4
  UFG::qVector4 *v8; // rax
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm3
  UFG::SimComponent *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  signed __int64 v14; // rcx
  float v15; // xmm0_4
  float v16; // xmm1_4

  v1 = this->pCharacterAnimationComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    v3 = -1;
    if ( this->pCharacterAnimationComponent.m_Changed )
    {
      this->mBoneHead = -1;
      this->mBoneCamera = -1;
      this->mBonePelvis = -1;
      this->mBoneSync = -1;
      this->pCharacterAnimationComponent.m_Changed = 0;
    }
    v4 = *(Creature **)&v1[2].m_TypeUID;
    if ( v4 )
    {
      if ( this->mBoneHead == -1 )
      {
        if ( v4->mPose.mRigHandle.mData )
          v3 = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::symBip01Head.mUID);
        v2->mBoneHead = v3;
      }
      v5 = v2->mBoneHead;
      if ( v5 != -1 )
      {
        Creature::GetTransform(v4, v5, &v2->mHeadTransformation);
        v6 = (float)((float)((float)(v2->mHeadTransformation.v0.y * 0.1) + (float)(v2->mHeadTransformation.v1.y * 0.0))
                   + (float)(v2->mHeadTransformation.v2.y * 0.0))
           + v2->mHeadTransformation.v3.y;
        v7 = (float)((float)((float)(v2->mHeadTransformation.v0.z * 0.1) + (float)(v2->mHeadTransformation.v1.z * 0.0))
                   + (float)(v2->mHeadTransformation.v2.z * 0.0))
           + v2->mHeadTransformation.v3.z;
        v2->mHeadPosition.x = (float)((float)((float)(v2->mHeadTransformation.v1.x * 0.0)
                                            + (float)(v2->mHeadTransformation.v0.x * 0.1))
                                    + (float)(v2->mHeadTransformation.v2.x * 0.0))
                            + v2->mHeadTransformation.v3.x;
        v2->mHeadPosition.y = v6;
        v2->mHeadPosition.z = v7;
      }
    }
    if ( v2->mBoneHead == -1 )
    {
      v8 = (UFG::qVector4 *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v2->vfptr[18].__vecDelDtor)(v2);
      v9 = v8[1];
      v10 = v8[2];
      v11 = v8[3];
      v2->mHeadTransformation.v0 = *v8;
      v2->mHeadTransformation.v1 = v9;
      v2->mHeadTransformation.v2 = v10;
      v2->mHeadTransformation.v3 = v11;
      v11.x = (float)((float)((float)(v2->mHeadTransformation.v1.y + v2->mHeadTransformation.v0.y) * 0.0)
                    + (float)(v2->mHeadTransformation.v2.y * 1.7))
            + v2->mHeadTransformation.v3.y;
      v9.x = (float)((float)((float)(v2->mHeadTransformation.v1.z + v2->mHeadTransformation.v0.z) * 0.0)
                   + (float)(v2->mHeadTransformation.v2.z * 1.7))
           + v2->mHeadTransformation.v3.z;
      v2->mHeadPosition.x = (float)((float)((float)(v2->mHeadTransformation.v1.x + v2->mHeadTransformation.v0.x) * 0.0)
                                  + (float)(v2->mHeadTransformation.v2.x * 1.7))
                          + v2->mHeadTransformation.v3.x;
      v2->mHeadPosition.y = v11.x;
      v2->mHeadPosition.z = v9.x;
    }
    if ( UFG::CharacterSubjectComponent::IsDowned(v2)
      && (v12 = v2->pTargetingSystemBaseComponent.m_pSimComponent) != 0i64
      && (v13 = v12[1].m_BoundComponentHandles.mNode.mPrev,
          v14 = (signed __int64)&v12[1].m_pSimObject,
          v13 != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v14) )
    {
      while ( LOBYTE(v13[3].mPrev) != 22 || !v13[2].mNext || !BYTE1(v13[3].mPrev) )
      {
        v13 = v13->mNext;
        if ( v13 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v14 )
          goto LABEL_20;
      }
    }
    else
    {
LABEL_20:
      v15 = v2->mHeadPosition.y;
      v16 = v2->mHeadPosition.z;
      v2->mLastAliveHeadPosition.x = v2->mHeadPosition.x;
      v2->mLastAliveHeadPosition.y = v15;
      v2->mLastAliveHeadPosition.z = v16;
    }
    v2->mHeadDirty = 0;
  }
}

// File Line: 340
// RVA: 0x1549980
__int64 UFG::_dynamic_initializer_for___symBip01Head__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraSync01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::_symBip01Head, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for___symBip01Head__);
}

// File Line: 344
// RVA: 0x55E8C0
void __fastcall UFG::CharacterSubjectComponent::UpdateCambone(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *v1; // rsi
  UFG::CharacterSubjectComponent *v2; // rdi
  signed int v3; // eax
  Creature *v4; // rsi
  int v5; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qVector4 *v8; // rax
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm3

  v1 = this->pCharacterAnimationComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    v3 = -1;
    if ( this->pCharacterAnimationComponent.m_Changed )
    {
      this->mBoneHead = -1;
      this->mBoneCamera = -1;
      this->mBonePelvis = -1;
      this->mBoneSync = -1;
      this->pCharacterAnimationComponent.m_Changed = 0;
    }
    v4 = *(Creature **)&v1[2].m_TypeUID;
    if ( v4 )
    {
      if ( this->mBoneCamera == -1 )
      {
        if ( v4->mPose.mRigHandle.mData )
          v3 = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::_symBip01Head.mUID);
        v2->mBoneCamera = v3;
      }
      v5 = v2->mBoneCamera;
      if ( v5 != -1 )
      {
        Creature::GetTransform(v4, v5, &v2->mCamboneTransformation);
        v6 = (float)((float)((float)(v2->mCamboneTransformation.v1.y + v2->mCamboneTransformation.v0.y)
                           + v2->mCamboneTransformation.v2.y)
                   * 0.0)
           + v2->mCamboneTransformation.v3.y;
        v7 = (float)((float)((float)(v2->mCamboneTransformation.v1.z + v2->mCamboneTransformation.v0.z)
                           + v2->mCamboneTransformation.v2.z)
                   * 0.0)
           + v2->mCamboneTransformation.v3.z;
        v2->mCambonePosition.x = (float)((float)((float)(v2->mCamboneTransformation.v1.x
                                                       + v2->mCamboneTransformation.v0.x)
                                               + v2->mCamboneTransformation.v2.x)
                                       * 0.0)
                               + v2->mCamboneTransformation.v3.x;
        v2->mCambonePosition.y = v6;
        v2->mCambonePosition.z = v7;
      }
    }
    if ( v2->mBoneCamera == -1 )
    {
      v8 = (UFG::qVector4 *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v2->vfptr[18].__vecDelDtor)(v2);
      v9 = v8[1];
      v10 = v8[2];
      v11 = v8[3];
      v2->mCamboneTransformation.v0 = *v8;
      v2->mCamboneTransformation.v1 = v9;
      v2->mCamboneTransformation.v2 = v10;
      v2->mCamboneTransformation.v3 = v11;
      v11.x = (float)((float)((float)(v2->mCamboneTransformation.v1.y + v2->mCamboneTransformation.v0.y) * 0.0)
                    + (float)(v2->mCamboneTransformation.v2.y * 0.85000002))
            + v2->mCamboneTransformation.v3.y;
      v9.x = (float)((float)((float)(v2->mCamboneTransformation.v1.z + v2->mCamboneTransformation.v0.z) * 0.0)
                   + (float)(v2->mCamboneTransformation.v2.z * 0.85000002))
           + v2->mCamboneTransformation.v3.z;
      v2->mCambonePosition.x = (float)((float)((float)(v2->mCamboneTransformation.v1.x + v2->mCamboneTransformation.v0.x)
                                             * 0.0)
                                     + (float)(v2->mCamboneTransformation.v2.x * 0.85000002))
                             + v2->mCamboneTransformation.v3.x;
      v2->mCambonePosition.y = v11.x;
      v2->mCambonePosition.z = v9.x;
    }
    v2->mCamboneDirty = 0;
  }
}

// File Line: 376
// RVA: 0x154CC50
__int64 UFG::_dynamic_initializer_for__symBip01Pelvis__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Pelvis", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBip01Pelvis, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symBip01Pelvis__);
}

// File Line: 380
// RVA: 0x5606B0
void __fastcall UFG::CharacterSubjectComponent::UpdatePelvis(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *v1; // rsi
  UFG::CharacterSubjectComponent *v2; // rdi
  signed int v3; // eax
  Creature *v4; // rsi
  int v5; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qVector4 *v8; // rax
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm3

  v1 = this->pCharacterAnimationComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    v3 = -1;
    if ( this->pCharacterAnimationComponent.m_Changed )
    {
      this->mBoneHead = -1;
      this->mBoneCamera = -1;
      this->mBonePelvis = -1;
      this->mBoneSync = -1;
      this->pCharacterAnimationComponent.m_Changed = 0;
    }
    v4 = *(Creature **)&v1[2].m_TypeUID;
    if ( v4 )
    {
      if ( this->mBonePelvis == -1 )
      {
        if ( v4->mPose.mRigHandle.mData )
          v3 = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::symBip01Pelvis.mUID);
        v2->mBonePelvis = v3;
      }
      v5 = v2->mBonePelvis;
      if ( v5 != -1 )
      {
        Creature::GetTransform(v4, v5, &v2->mPelvisTransformation);
        v6 = (float)((float)((float)(v2->mPelvisTransformation.v1.y + v2->mPelvisTransformation.v0.y)
                           + v2->mPelvisTransformation.v2.y)
                   * 0.0)
           + v2->mPelvisTransformation.v3.y;
        v7 = (float)((float)((float)(v2->mPelvisTransformation.v1.z + v2->mPelvisTransformation.v0.z)
                           + v2->mPelvisTransformation.v2.z)
                   * 0.0)
           + v2->mPelvisTransformation.v3.z;
        v2->mPelvisPosition.x = (float)((float)((float)(v2->mPelvisTransformation.v1.x + v2->mPelvisTransformation.v0.x)
                                              + v2->mPelvisTransformation.v2.x)
                                      * 0.0)
                              + v2->mPelvisTransformation.v3.x;
        v2->mPelvisPosition.y = v6;
        v2->mPelvisPosition.z = v7;
      }
    }
    if ( v2->mBonePelvis == -1 )
    {
      v8 = (UFG::qVector4 *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v2->vfptr[18].__vecDelDtor)(v2);
      v9 = v8[1];
      v10 = v8[2];
      v11 = v8[3];
      v2->mPelvisTransformation.v0 = *v8;
      v2->mPelvisTransformation.v1 = v9;
      v2->mPelvisTransformation.v2 = v10;
      v2->mPelvisTransformation.v3 = v11;
      v11.x = (float)((float)((float)(v2->mPelvisTransformation.v1.y + v2->mPelvisTransformation.v0.y) * 0.0)
                    + (float)(v2->mPelvisTransformation.v2.y * 0.85000002))
            + v2->mPelvisTransformation.v3.y;
      v9.x = (float)((float)((float)(v2->mPelvisTransformation.v1.z + v2->mPelvisTransformation.v0.z) * 0.0)
                   + (float)(v2->mPelvisTransformation.v2.z * 0.85000002))
           + v2->mPelvisTransformation.v3.z;
      v2->mPelvisPosition.x = (float)((float)((float)(v2->mPelvisTransformation.v1.x + v2->mPelvisTransformation.v0.x)
                                            * 0.0)
                                    + (float)(v2->mPelvisTransformation.v2.x * 0.85000002))
                            + v2->mPelvisTransformation.v3.x;
      v2->mPelvisPosition.y = v11.x;
      v2->mPelvisPosition.z = v9.x;
    }
    v2->mPelvisDirty = 0;
  }
}

// File Line: 413
// RVA: 0x154CDD0
__int64 UFG::_dynamic_initializer_for__symSync01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Sync01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSync01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symSync01__);
}

// File Line: 445
// RVA: 0x1544920
__int64 UFG::_dynamic_initializer_for__HASH_Hostage__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Hostage", 0xFFFFFFFF);
  HASH_Hostage.mUID = result;
  return result;
}

// File Line: 446
// RVA: 0x1549C90
signed __int64 UFG::_dynamic_initializer_for__mostUsedIndex_Hostage__()
{
  signed __int64 result; // rax

  result = GetMostUsedIndex(HASH_Hostage.mUID);
  mostUsedIndex_Hostage = result;
  return result;
}

// File Line: 447
// RVA: 0x1544900
__int64 UFG::_dynamic_initializer_for__HASH_ActionHijack__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ActionHijack", 0xFFFFFFFF);
  HASH_ActionHijack_0.mUID = result;
  return result;
}

// File Line: 448
// RVA: 0x1549C70
signed __int64 UFG::_dynamic_initializer_for__mostUsedIndex_ActionHijack__()
{
  signed __int64 result; // rax

  result = GetMostUsedIndex(HASH_ActionHijack_0.mUID);
  mostUsedIndex_ActionHijack_0 = result;
  return result;
}

// File Line: 449
// RVA: 0x1544940
__int64 UFG::_dynamic_initializer_for__HASH_Run__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Run", 0xFFFFFFFF);
  HASH_Run.mUID = result;
  return result;
}

// File Line: 450
// RVA: 0x1549CB0
signed __int64 UFG::_dynamic_initializer_for__mostUsedIndex_Run__()
{
  signed __int64 result; // rax

  result = GetMostUsedIndex(HASH_Run.mUID);
  mostUsedIndex_Run = result;
  return result;
}

// File Line: 451
// RVA: 0x1544960
__int64 UFG::_dynamic_initializer_for__HASH_Walk__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Walk", 0xFFFFFFFF);
  HASH_Walk.mUID = result;
  return result;
}

// File Line: 452
// RVA: 0x1549CD0
signed __int64 UFG::_dynamic_initializer_for__mostUsedIndex_Walk__()
{
  signed __int64 result; // rax

  result = GetMostUsedIndex(HASH_Walk.mUID);
  mostUsedIndex_Walk = result;
  return result;
}

// File Line: 455
// RVA: 0x53A920
bool __fastcall UFG::CharacterSubjectComponent::IsHostage(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState v1; // edx
  UFG::CharacterSubjectComponent *v2; // rbx
  bool result; // al
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx

  v1 = this->mIsHostage;
  v2 = this;
  if ( v1 )
    return v1 == 1;
  v4 = this->m_pSimObject;
  if ( !v4 )
    goto LABEL_26;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v6 = v4->m_Components.p[6].m_pComponent;
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_16:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v4->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_16;
        }
        v6 = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v4, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  if ( v6 && ActionController::IsPlaying((ActionController *)&v6[3], &HASH_Hostage, mostUsedIndex_Hostage, 0) )
    result = 1;
  else
LABEL_26:
    result = 0;
  v2->mIsHostage = 2 - (result != 0);
  return result;
}

// File Line: 474
// RVA: 0x539630
bool __fastcall UFG::CharacterSubjectComponent::IsActionHijacking(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState v1; // edx
  UFG::CharacterSubjectComponent *v2; // rbx
  bool result; // al
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx

  v1 = this->mActionHijacking;
  v2 = this;
  if ( v1 )
    return v1 == 1;
  v4 = this->m_pSimObject;
  if ( !v4 )
    goto LABEL_26;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v6 = v4->m_Components.p[6].m_pComponent;
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_16:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v4->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_16;
        }
        v6 = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v4, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  if ( v6
    && ActionController::IsPlaying((ActionController *)&v6[3], &HASH_ActionHijack_0, mostUsedIndex_ActionHijack_0, 0) )
  {
    result = 1;
  }
  else
  {
LABEL_26:
    result = 0;
  }
  v2->mActionHijacking = 2 - (result != 0);
  return result;
}

// File Line: 493
// RVA: 0x53B0A0
bool __fastcall UFG::CharacterSubjectComponent::IsJogging(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState v1; // edx
  UFG::CharacterSubjectComponent *v2; // rbx
  bool result; // al
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx

  v1 = this->mJogging;
  v2 = this;
  if ( v1 )
    return v1 == 1;
  v4 = this->m_pSimObject;
  if ( !v4 )
    goto LABEL_27;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v6 = v4->m_Components.p[6].m_pComponent;
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_16:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v4->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_16;
        }
        v6 = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v4, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  if ( v6 && ActionController::IsPlaying((ActionController *)&v6[3], &HASH_Run, mostUsedIndex_Run, 1) && !v2->mSprinting )
    result = 1;
  else
LABEL_27:
    result = 0;
  v2->mJogging = 2 - (result != 0);
  return result;
}

// File Line: 512
// RVA: 0x53C2F0
bool __fastcall UFG::CharacterSubjectComponent::IsWalking(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState v1; // edx
  UFG::CharacterSubjectComponent *v2; // rbx
  bool result; // al
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx

  v1 = this->mWalking;
  v2 = this;
  if ( v1 )
    return v1 == 1;
  v4 = this->m_pSimObject;
  if ( !v4 )
    goto LABEL_27;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v6 = v4->m_Components.p[6].m_pComponent;
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_16:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v4->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_16;
        }
        v6 = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v4, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    v6 = v4->m_Components.p[7].m_pComponent;
  }
  if ( v6
    && ActionController::IsPlaying((ActionController *)&v6[3], &HASH_Walk, mostUsedIndex_Walk, 1)
    && !v2->mSprinting )
  {
    result = 1;
  }
  else
  {
LABEL_27:
    result = 0;
  }
  v2->mWalking = 2 - (result != 0);
  return result;
}

// File Line: 531
// RVA: 0x55A530
void __fastcall UFG::CharacterSubjectComponent::Update(UFG::CharacterSubjectComponent *this, float delta_sec)
{
  UFG::CharacterSubjectComponent *v2; // rbx
  float v3; // xmm7_4
  UFG::CharacterPhysicsComponent *v4; // rcx
  UFG::ParkourHandle *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  UFG::qVector3 *v9; // rax
  UFG::CharacterPhysicsComponent *v10; // rcx
  UFG::CharacterCollisionMode v11; // edx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  int v15; // xmm6_4
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::SimObject *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  unsigned int v24; // er8
  unsigned int v25; // er10
  signed __int64 v26; // rdx
  unsigned int v27; // er8
  unsigned int v28; // er10
  unsigned int v29; // er8
  unsigned int v30; // er10
  float *v31; // rax
  float v32; // xmm7_4
  float v33; // xmm8_4
  float v34; // xmm6_4
  signed __int64 v35; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qVector3 raw_velocity; // [rsp+20h] [rbp-58h]
  UFG::qVector3 result; // [rsp+30h] [rbp-48h]

  v2 = this;
  v3 = delta_sec;
  UFG::CameraSubject::UpdateBase(
    (UFG::CameraSubject *)&this->vfptr,
    delta_sec,
    UFG::bCameraDebugDraw,
    &UFG::gCameraSubjectUpdateParams);
  v4 = (UFG::CharacterPhysicsComponent *)v2->pCharacterPhysicsComponent.m_pSimComponent;
  v5 = 0i64;
  *(_QWORD *)&v2->mIsHostage = 0i64;
  *(_QWORD *)&v2->mActionHijacking = 0i64;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  raw_velocity = UFG::qVector3::msZero;
  if ( v4 )
  {
    v8 = UFG::CharacterPhysicsComponent::GetRadius(v4);
    v9 = UFG::CharacterPhysicsComponent::GetVelocity(
           (UFG::CharacterPhysicsComponent *)v2->pCharacterPhysicsComponent.m_pSimComponent,
           &result);
    v10 = (UFG::CharacterPhysicsComponent *)v2->pCharacterPhysicsComponent.m_pSimComponent;
    v11 = v10->mCollisionModelType;
    v12 = v9->y;
    raw_velocity.x = v9->x;
    v13 = v9->z;
    raw_velocity.y = v12;
    raw_velocity.z = v13;
    v14 = UFG::CharacterPhysicsComponent::GetHeight(v10, v11);
    v2->mBox.mMax.x = v8;
    v2->mBox.mMax.y = v8;
    v15 = LODWORD(v8) ^ _xmm[0];
    v2->mBox.mMax.z = v14;
    LODWORD(v2->mBox.mMin.x) = v15;
    LODWORD(v2->mBox.mMin.y) = v15;
    v2->mBox.mMin.z = 0.0;
    v16 = (__m128)LODWORD(v2->mBox.mMax.x);
    v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v2->mBox.mMax.y * v2->mBox.mMax.y))
                    + (float)(v2->mBox.mMax.z * v2->mBox.mMax.z);
    LODWORD(v2->mRadius) = (unsigned __int128)_mm_sqrt_ps(v16);
  }
  else
  {
    v2->mFilteredVelocity.x = UFG::qVector3::msZero.x;
    v2->mFilteredVelocity.y = v6;
    v2->mFilteredVelocity.z = v7;
    v17 = UFG::qVector3::msZero.y;
    v18 = UFG::qVector3::msZero.z;
    v2->mBox.mMin.x = UFG::qVector3::msZero.x;
    v2->mBox.mMin.y = v17;
    v2->mBox.mMin.z = v18;
    v19 = UFG::qVector3::msZero.y;
    v20 = UFG::qVector3::msZero.z;
    v2->mBox.mMax.x = UFG::qVector3::msZero.x;
    v2->mBox.mMax.y = v19;
    v2->mBox.mMax.z = v20;
    v2->mRadius = 0.0;
  }
  UFG::CharacterSubjectComponent::UpdateFilteredVelocity(v2, v3, &raw_velocity);
  UFG::CharacterSubjectComponent::UpdateFilteredPosition(v2, v3);
  v21 = v2->m_pSimObject;
  if ( !v21 )
    goto LABEL_32;
  v22 = v21->m_Flags;
  if ( (v22 >> 14) & 1 )
  {
    v23 = v21->m_Components.p[28].m_pComponent;
    goto LABEL_30;
  }
  if ( (v22 & 0x8000u) != 0 )
  {
    v24 = (unsigned int)v21[1].vfptr;
    v25 = v21->m_Components.size;
    if ( v24 < v25 )
    {
      v26 = (signed __int64)&v21->m_Components.p[v24];
      while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
           || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
      {
        ++v24;
        v26 += 16i64;
        if ( v24 >= v25 )
          goto LABEL_13;
      }
LABEL_14:
      v23 = *(UFG::SimComponent **)v26;
      goto LABEL_30;
    }
    goto LABEL_13;
  }
  if ( (v22 >> 13) & 1 )
  {
    v27 = (unsigned int)v21[1].vfptr;
    v28 = v21->m_Components.size;
    if ( v27 < v28 )
    {
      v26 = (signed __int64)&v21->m_Components.p[v27];
      while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
           || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
      {
        ++v27;
        v26 += 16i64;
        if ( v27 >= v28 )
        {
          v23 = 0i64;
          goto LABEL_30;
        }
      }
      goto LABEL_14;
    }
LABEL_13:
    v23 = 0i64;
    goto LABEL_30;
  }
  if ( (v22 >> 12) & 1 )
  {
    v29 = (unsigned int)v21[1].vfptr;
    v30 = v21->m_Components.size;
    if ( v29 < v30 )
    {
      v26 = (signed __int64)&v21->m_Components.p[v29];
      while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
           || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
      {
        ++v29;
        v26 += 16i64;
        if ( v29 >= v30 )
        {
          v23 = 0i64;
          goto LABEL_30;
        }
      }
      goto LABEL_14;
    }
    goto LABEL_13;
  }
  v23 = UFG::SimObject::GetComponentOfType(v21, UFG::WorldContextComponent::_TypeUID);
LABEL_30:
  if ( v23 )
    v5 = *(UFG::ParkourHandle **)&v23[5].m_TypeUID;
LABEL_32:
  v2->mParkourHandle = v5;
  UFG::CharacterSubjectComponent::UpdateTargetWorld(v2);
  v31 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v2->vfptr[17].__vecDelDtor)(v2);
  v32 = *v31;
  v33 = v31[1];
  v34 = v31[2];
  if ( v2->bElevationLock )
    v34 = v2->rLockedElevationDef;
  if ( UFG::CharacterSubjectComponent::IsDowned(v2)
    && v2->pTargetingSystemBaseComponent.m_pSimComponent
    && (v35 = (signed __int64)&v2->pTargetingSystemBaseComponent.m_pSimComponent[1].m_pSimObject,
        v36 = v2->pTargetingSystemBaseComponent.m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev,
        v36 != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v35) )
  {
    while ( LOBYTE(v36[3].mPrev) != 22 || !v36[2].mNext || !BYTE1(v36[3].mPrev) )
    {
      v36 = v36->mNext;
      if ( v36 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v35 )
        goto LABEL_41;
    }
  }
  else
  {
LABEL_41:
    v2->mGrapplePosition.x = v32;
    v2->mGrapplePosition.y = v33;
    v2->mGrapplePosition.z = v34;
  }
  if ( v2->pCharacterAnimationComponent.m_pSimComponent )
    *(_DWORD *)&v2->mHeadDirty = 16843009;
}

// File Line: 620
// RVA: 0x54F940
bool __fastcall UFG::CharacterSubjectComponent::ShouldHide(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent *v1; // rbx
  UFG::BaseCameraComponent *v2; // rax
  __int64 v3; // rax
  bool v4; // zf
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::BaseCameraComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  UFG::SimObject *v13; // rcx
  UFG::SimComponent *v14; // rax
  UFG::qVector3 P; // [rsp+20h] [rbp-58h]
  UFG::qVector3 lA1; // [rsp+30h] [rbp-48h]
  UFG::qVector3 lA0; // [rsp+40h] [rbp-38h]
  UFG::qVector3 closest_point; // [rsp+50h] [rbp-28h]

  v1 = this;
  v2 = UFG::Director::Get()->mCurrentCamera;
  if ( !v2 || v2 == (UFG::BaseCameraComponent *)-80i64 )
    return 0;
  v3 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v1->vfptr[26].__vecDelDtor)(v1);
  v4 = v1->mPelvisDirty == 0;
  v5 = *(float *)(v3 + 4);
  v6 = *(float *)(v3 + 8);
  lA1.x = *(float *)v3;
  lA1.y = v5;
  lA1.z = v6;
  if ( !v4 )
    UFG::CharacterSubjectComponent::UpdatePelvis(v1);
  v7 = v1->mPelvisPosition.y;
  lA0.x = v1->mPelvisPosition.x;
  v8 = v1->mPelvisPosition.z;
  lA0.y = v7;
  lA0.z = v8;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 )
    v9 = (UFG::BaseCameraComponent *)((char *)v9 + 80);
  v10 = v9->mCamera.mView.v2.y;
  v11 = v9->mCamera.mView.v2.z;
  P.x = v9->mCamera.mView.v2.x;
  P.y = v10;
  P.z = v11;
  UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &lA1, &P);
  if ( UFG::IsAnyLocalPlayer(v1->m_pSimObject) )
    v12 = UFG::gFadeThresholdPlayer;
  else
    v12 = UFG::gFadeThresholdNPC;
  v13 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v13 )
  {
    v14 = UFG::SimObject::GetComponentOfType(v13, UFG::FollowCameraComponent::_TypeUID);
    if ( v14 )
    {
      if ( v14[24].m_NameUID == 5 )
        v12 = UFG::gFadeThresholdPlayer;
    }
  }
  return (float)(v12 * v12) > (float)((float)((float)((float)(closest_point.y - P.y) * (float)(closest_point.y - P.y))
                                            + (float)((float)(closest_point.x - P.x) * (float)(closest_point.x - P.x)))
                                    + (float)((float)(closest_point.z - P.z) * (float)(closest_point.z - P.z)));
}

// File Line: 648
// RVA: 0x55E060
void __fastcall UFG::CharacterSubjectComponent::UpdateAll(float delta_sec)
{
  UFG::CharacterSubjectComponent *v1; // rcx
  UFG::qList<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent,1,0> *v2; // rbx

  v1 = (UFG::CharacterSubjectComponent *)&UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mNext[-18];
  if ( (UFG::qList<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent,1,0> *)&UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mNext[-18] != &UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList - 18 )
  {
    do
    {
      v2 = (UFG::qList<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent,1,0> *)&v1->mNext[-18];
      UFG::CharacterSubjectComponent::Update(v1, delta_sec);
      v1 = (UFG::CharacterSubjectComponent *)v2;
    }
    while ( v2 != &UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList - 18 );
  }
}

// File Line: 666
// RVA: 0x52DCC0
void __fastcall UFG::CharacterSubjectComponent::GetHeadTransform(UFG::CharacterSubjectComponent *this, UFG::qMatrix44 *m)
{
  UFG::qMatrix44 *v2; // rsi
  UFG::CharacterSubjectComponent *v3; // rdi
  int v4; // edx
  Creature *v5; // rcx
  float *v6; // rbx
  float *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4

  v2 = m;
  v3 = this;
  if ( this->mHeadDirty )
    UFG::CharacterSubjectComponent::UpdateHead(this);
  v4 = v3->mBoneHead;
  if ( v4 != -1 && v3->pCharacterAnimationComponent.m_pSimComponent )
  {
    v5 = *(Creature **)&v3->pCharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v5 )
      Creature::GetTransform(v5, v4, v2);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    v7 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    v8 = (float)((float)((float)(v7[5] + v7[1]) * 0.0) + (float)(v7[9] * 1.7)) + v7[13];
    v9 = (float)((float)((float)(v7[6] + v7[2]) * 0.0) + (float)(v7[10] * 1.7)) + v7[14];
    v10 = (float)((float)((float)(v7[7] + v7[3]) * 0.0) + (float)(v7[11] * 1.7)) + v7[15];
    v2->v3.x = (float)((float)((float)(v7[4] + *v7) * 0.0) + (float)(v7[8] * 1.7)) + v7[12];
    v2->v3.y = v8;
    v2->v3.w = v10;
    v2->v3.z = v9;
    *(float *)&v7 = *v6;
    v11 = v6[2];
    v12 = v6[3];
    v2->v0.y = v6[1];
    LODWORD(v2->v0.x) = (_DWORD)v7;
    v2->v0.z = v11;
    v2->v0.w = v12;
    *(float *)&v7 = v6[4];
    v13 = v6[6];
    v14 = v6[7];
    v2->v1.y = v6[5];
    LODWORD(v2->v1.x) = (_DWORD)v7;
    v2->v1.z = v13;
    v2->v1.w = v14;
    *(float *)&v7 = v6[8];
    v15 = v6[10];
    v16 = v6[11];
    v2->v2.y = v6[9];
    LODWORD(v2->v2.x) = (_DWORD)v7;
    v2->v2.z = v15;
    v2->v2.w = v16;
  }
}

// File Line: 690
// RVA: 0x52AD20
void __fastcall UFG::CharacterSubjectComponent::GetCamboneTransform(UFG::CharacterSubjectComponent *this, UFG::qMatrix44 *m)
{
  UFG::qMatrix44 *v2; // rsi
  UFG::CharacterSubjectComponent *v3; // rdi
  int v4; // edx
  Creature *v5; // rcx
  float *v6; // rbx
  float *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4

  v2 = m;
  v3 = this;
  if ( this->mCamboneDirty )
    UFG::CharacterSubjectComponent::UpdateCambone(this);
  v4 = v3->mBoneCamera;
  if ( v4 != -1 && v3->pCharacterAnimationComponent.m_pSimComponent )
  {
    v5 = *(Creature **)&v3->pCharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v5 )
      Creature::GetTransform(v5, v4, v2);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    v7 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    v8 = (float)((float)((float)(v7[5] + v7[1]) * 0.0) + (float)(v7[9] * 0.85000002)) + v7[13];
    v9 = (float)((float)((float)(v7[6] + v7[2]) * 0.0) + (float)(v7[10] * 0.85000002)) + v7[14];
    v10 = (float)((float)((float)(v7[7] + v7[3]) * 0.0) + (float)(v7[11] * 0.85000002)) + v7[15];
    v2->v3.x = (float)((float)((float)(v7[4] + *v7) * 0.0) + (float)(v7[8] * 0.85000002)) + v7[12];
    v2->v3.y = v8;
    v2->v3.w = v10;
    v2->v3.z = v9;
    *(float *)&v7 = *v6;
    v11 = v6[2];
    v12 = v6[3];
    v2->v0.y = v6[1];
    LODWORD(v2->v0.x) = (_DWORD)v7;
    v2->v0.z = v11;
    v2->v0.w = v12;
    *(float *)&v7 = v6[4];
    v13 = v6[6];
    v14 = v6[7];
    v2->v1.y = v6[5];
    LODWORD(v2->v1.x) = (_DWORD)v7;
    v2->v1.z = v13;
    v2->v1.w = v14;
    *(float *)&v7 = v6[8];
    v15 = v6[10];
    v16 = v6[11];
    v2->v2.y = v6[9];
    LODWORD(v2->v2.x) = (_DWORD)v7;
    v2->v2.z = v15;
    v2->v2.w = v16;
  }
}

// File Line: 714
// RVA: 0x52F450
void __fastcall UFG::CharacterSubjectComponent::GetPelvisTransform(UFG::CharacterSubjectComponent *this, UFG::qMatrix44 *m)
{
  UFG::qMatrix44 *v2; // rsi
  UFG::CharacterSubjectComponent *v3; // rdi
  int v4; // edx
  Creature *v5; // rcx
  float *v6; // rbx
  float *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4

  v2 = m;
  v3 = this;
  if ( this->mPelvisDirty )
    UFG::CharacterSubjectComponent::UpdatePelvis(this);
  v4 = v3->mBonePelvis;
  if ( v4 != -1 && v3->pCharacterAnimationComponent.m_pSimComponent )
  {
    v5 = *(Creature **)&v3->pCharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v5 )
      Creature::GetTransform(v5, v4, v2);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    v7 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[18].__vecDelDtor)(v3);
    v8 = (float)((float)((float)(v7[5] + v7[1]) * 0.0) + (float)(v7[9] * 0.85000002)) + v7[13];
    v9 = (float)((float)((float)(v7[6] + v7[2]) * 0.0) + (float)(v7[10] * 0.85000002)) + v7[14];
    v10 = (float)((float)((float)(v7[7] + v7[3]) * 0.0) + (float)(v7[11] * 0.85000002)) + v7[15];
    v2->v3.x = (float)((float)((float)(v7[4] + *v7) * 0.0) + (float)(v7[8] * 0.85000002)) + v7[12];
    v2->v3.y = v8;
    v2->v3.w = v10;
    v2->v3.z = v9;
    *(float *)&v7 = *v6;
    v11 = v6[2];
    v12 = v6[3];
    v2->v0.y = v6[1];
    LODWORD(v2->v0.x) = (_DWORD)v7;
    v2->v0.z = v11;
    v2->v0.w = v12;
    *(float *)&v7 = v6[4];
    v13 = v6[6];
    v14 = v6[7];
    v2->v1.y = v6[5];
    LODWORD(v2->v1.x) = (_DWORD)v7;
    v2->v1.z = v13;
    v2->v1.w = v14;
    *(float *)&v7 = v6[8];
    v15 = v6[10];
    v16 = v6[11];
    v2->v2.y = v6[9];
    LODWORD(v2->v2.x) = (_DWORD)v7;
    v2->v2.z = v15;
    v2->v2.w = v16;
  }
}

// File Line: 738
// RVA: 0x556920
void __fastcall UFG::CharacterSubjectComponent::TeleportEventHandler(UFG::CharacterSubjectComponent *this, UFG::Event *event)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  UFG::CharacterSubjectComponent *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // eax
  float v8; // xmm0_4
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rdi
  UFG::SimObject *v12; // rbx

  v2 = *((float *)&event[2].mNext + 1);
  v3 = *(float *)&event[2].m_EventUID;
  this->mLastAliveHeadPosition.x = *(float *)&event[2].mNext;
  v4 = this;
  this->mLastAliveHeadPosition.y = v2;
  this->mLastAliveHeadPosition.z = v3;
  v5 = *((float *)&event[2].mNext + 1);
  v6 = *(float *)&event[2].m_EventUID;
  this->mFilteredPosition.x = *(float *)&event[2].mNext;
  this->mFilteredPosition.y = v5;
  this->mFilteredPosition.z = v6;
  v7 = *(float *)&event[2].mNext;
  v8 = *(float *)&event[2].m_EventUID;
  this->mGrapplePosition.y = *((float *)&event[2].mNext + 1);
  this->mGrapplePosition.x = v7;
  this->mGrapplePosition.z = v8;
  UFG::CharacterSubjectComponent::Update(this, 0.0);
  v9 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v9 )
  {
    v10 = UFG::SimObject::GetComponentOfType(v9, UFG::FollowCameraComponent::_TypeUID);
    v11 = v10;
    if ( v10 )
    {
      v12 = v4->m_pSimObject;
      if ( v12 == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v10->vfptr[17].__vecDelDtor)(v10) )
        ((void (__fastcall *)(UFG::SimComponent *))v11->vfptr[14].__vecDelDtor)(v11);
    }
  }
}

// File Line: 756
// RVA: 0x53A000
bool __fastcall UFG::CharacterSubjectComponent::IsCop(UFG::CharacterSubjectComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  unsigned int v7; // er8
  unsigned int v8; // er9

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v3 = v1->m_Flags;
  if ( (v3 >> 14) & 1 || (v3 & 0x8000u) != 0 )
    return v1->m_Components.p[17].m_pComponent != 0i64;
  if ( (v3 >> 13) & 1 )
  {
    v4 = (unsigned int)v1[1].vfptr;
    v5 = v1->m_Components.size;
    if ( v4 < v5 )
    {
      v6 = (signed __int64)&v1->m_Components.p[v4];
      while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CopUnitComponent::_TypeUID & 0xFE000000)
           || UFG::CopUnitComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
      {
        ++v4;
        v6 += 16i64;
        if ( v4 >= v5 )
          return 0;
      }
      return *(_QWORD *)v6 != 0i64;
    }
    return 0;
  }
  if ( (v3 >> 12) & 1 )
  {
    v7 = (unsigned int)v1[1].vfptr;
    v8 = v1->m_Components.size;
    if ( v7 < v8 )
    {
      v6 = (signed __int64)&v1->m_Components.p[v7];
      while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CopUnitComponent::_TypeUID & 0xFE000000)
           || UFG::CopUnitComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
      {
        ++v7;
        v6 += 16i64;
        if ( v7 >= v8 )
          return 0;
      }
      return *(_QWORD *)v6 != 0i64;
    }
    return 0;
  }
  return UFG::SimObject::GetComponentOfType(v1, UFG::CopUnitComponent::_TypeUID) != 0i64;
}

// File Line: 762
// RVA: 0x532DC0
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::GetVelocity(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent *v1; // rbx
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  int v15; // edx

  v1 = this;
  v2 = this->m_pSimObject;
  if ( !v2 )
    return &v1->mFilteredVelocity;
  v3 = v2->m_Flags;
  if ( !((v3 >> 14) & 1) )
  {
    if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v8 = (unsigned int)v2[1].vfptr;
        v9 = v2->m_Components.size;
        if ( v8 < v9 )
        {
          v7 = (signed __int64)&v2->m_Components.p[v8];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v8;
            v7 += 16i64;
            if ( v8 >= v9 )
            {
              v4 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( !((v3 >> 12) & 1) )
        {
          v4 = UFG::SimObject::GetComponentOfType(v2, UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_27;
        }
        v10 = (unsigned int)v2[1].vfptr;
        v11 = v2->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (signed __int64)&v2->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v7 += 16i64;
            if ( v10 >= v11 )
            {
              v4 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v5 = (unsigned int)v2[1].vfptr;
      v6 = v2->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (signed __int64)&v2->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
            goto LABEL_10;
        }
LABEL_11:
        v4 = *(UFG::SimComponent **)v7;
        goto LABEL_27;
      }
    }
LABEL_10:
    v4 = 0i64;
    goto LABEL_27;
  }
  v4 = v2->m_Components.p[44].m_pComponent;
LABEL_27:
  if ( v4 )
  {
    v12 = v4[1].m_BoundComponentHandles.mNode.mPrev;
    if ( v12 )
    {
      v13 = v12[2].mNext;
      if ( v13 )
      {
        v14 = v13[6].mNext[31].mPrev;
        if ( v14 )
        {
          v15 = (int)v14[1].mNext;
          if ( !((v15 ^ UFG::VehicleSubjectComponent::_TypeUID) & 0xFE000000)
            && !(UFG::VehicleSubjectComponent::_TypeUID & ~v15 & 0x1FFFFFF) )
          {
            return (UFG::qVector3 *)((__int64 (*)(void))v14->mPrev[10].mPrev)();
          }
        }
      }
    }
  }
  return &v1->mFilteredVelocity;
}

// File Line: 783
// RVA: 0x53AA60
bool __fastcall UFG::CharacterSubjectComponent::IsInVehicle(UFG::CharacterSubjectComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  unsigned int v7; // er8
  unsigned int v8; // er9
  unsigned int v9; // er8
  unsigned int v10; // er9

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v3 = v1->m_Flags;
  if ( (v3 >> 14) & 1 )
    return v1->m_Components.p[44].m_pComponent != 0i64;
  if ( (v3 & 0x8000u) != 0 )
  {
    v4 = (unsigned int)v1[1].vfptr;
    v5 = v1->m_Components.size;
    if ( v4 < v5 )
    {
      v6 = (signed __int64)&v1->m_Components.p[v4];
      while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
      {
        ++v4;
        v6 += 16i64;
        if ( v4 >= v5 )
          return 0;
      }
      return *(_QWORD *)v6 != 0i64;
    }
    return 0;
  }
  if ( (v3 >> 13) & 1 )
  {
    v7 = (unsigned int)v1[1].vfptr;
    v8 = v1->m_Components.size;
    if ( v7 < v8 )
    {
      v6 = (signed __int64)&v1->m_Components.p[v7];
      while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
      {
        ++v7;
        v6 += 16i64;
        if ( v7 >= v8 )
          return 0;
      }
      return *(_QWORD *)v6 != 0i64;
    }
    return 0;
  }
  if ( (v3 >> 12) & 1 )
  {
    v9 = (unsigned int)v1[1].vfptr;
    v10 = v1->m_Components.size;
    if ( v9 < v10 )
    {
      v6 = (signed __int64)&v1->m_Components.p[v9];
      while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
      {
        ++v9;
        v6 += 16i64;
        if ( v9 >= v10 )
          return 0;
      }
      return *(_QWORD *)v6 != 0i64;
    }
    return 0;
  }
  return UFG::SimObject::GetComponentOfType(v1, UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
}

// File Line: 789
// RVA: 0x53A160
bool __fastcall UFG::CharacterSubjectComponent::IsDowned(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent *v1; // rsi
  UFG::SimObject *v2; // rcx
  UFG::ActionTreeComponent *v3; // rdi
  UFG::HealthComponent *v4; // rbx
  unsigned __int16 v5; // dx
  unsigned int v6; // er8
  unsigned int v7; // er9
  signed __int64 v8; // rdx
  unsigned int v9; // er8
  unsigned int v10; // er9
  UFG::SimObject *v11; // rcx
  unsigned __int16 v12; // dx
  unsigned int v13; // er8
  unsigned int v14; // er9
  signed __int64 v15; // rdx

  v1 = this;
  v2 = this->m_pSimObject;
  v3 = 0i64;
  if ( !v2 )
    goto LABEL_2;
  v5 = v2->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v4 = (UFG::HealthComponent *)v2->m_Components.p[6].m_pComponent;
    goto LABEL_23;
  }
  if ( (v5 & 0x8000u) != 0 )
  {
    v4 = (UFG::HealthComponent *)v2->m_Components.p[6].m_pComponent;
    goto LABEL_23;
  }
  if ( (v5 >> 13) & 1 )
  {
    v6 = (unsigned int)v2[1].vfptr;
    v7 = v2->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v6;
        v8 += 16i64;
        if ( v6 >= v7 )
        {
          v4 = 0i64;
          goto LABEL_23;
        }
      }
LABEL_14:
      v4 = *(UFG::HealthComponent **)v8;
      goto LABEL_23;
    }
    goto LABEL_2;
  }
  if ( (v5 >> 12) & 1 )
  {
    v9 = (unsigned int)v2[1].vfptr;
    v10 = v2->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
        {
          v4 = 0i64;
          goto LABEL_23;
        }
      }
      goto LABEL_14;
    }
LABEL_2:
    v4 = 0i64;
    goto LABEL_23;
  }
  v4 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::HealthComponent::_TypeUID);
LABEL_23:
  v11 = v1->m_pSimObject;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 >> 14) & 1 || (v12 & 0x8000u) != 0 )
    {
      v3 = (UFG::ActionTreeComponent *)v11->m_Components.p[7].m_pComponent;
    }
    else if ( (v12 >> 13) & 1 )
    {
      v3 = (UFG::ActionTreeComponent *)v11->m_Components.p[6].m_pComponent;
    }
    else if ( (v12 >> 12) & 1 )
    {
      v13 = (unsigned int)v11[1].vfptr;
      v14 = v11->m_Components.size;
      if ( v13 < v14 )
      {
        v15 = (signed __int64)&v11->m_Components.p[v13];
        while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
        {
          ++v13;
          v15 += 16i64;
          if ( v13 >= v14 )
            return UFG::IsDowned(v3, v4);
        }
        v3 = *(UFG::ActionTreeComponent **)v15;
      }
    }
    else
    {
      v3 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(v11, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  return UFG::IsDowned(v3, v4);
}

// File Line: 809
// RVA: 0x539770
bool __fastcall UFG::CharacterSubjectComponent::IsAirborne(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent *v1; // rbx
  UFG::CharacterPhysicsComponent *v2; // rcx
  UFG::SimComponent *v3; // rax
  bool result; // al

  v1 = this;
  v2 = (UFG::CharacterPhysicsComponent *)this->pCharacterPhysicsComponent.m_pSimComponent;
  result = 0;
  if ( v2 )
  {
    if ( !UFG::CharacterPhysicsComponent::IsInWater(v2) )
    {
      v3 = v1->pCharacterPhysicsComponent.m_pSimComponent;
      if ( !(v3[6].m_NameUID & 2) && *(float *)&v3[5].m_BoundComponentHandles.mNode.mPrev > 1.0 )
        result = 1;
    }
  }
  return result;
}

// File Line: 823
// RVA: 0x53B240
bool __fastcall UFG::CharacterSubjectComponent::IsOnGround(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pCharacterPhysicsComponent.m_pSimComponent;
  return v1 && v1[6].m_NameUID & 2;
}

// File Line: 830
// RVA: 0x54C830
void __fastcall UFG::CharacterSubjectComponent::SetElevationLock(UFG::CharacterSubjectComponent *this, bool lock)
{
  bool v2; // di
  UFG::CharacterSubjectComponent *v3; // rbx
  __int64 v4; // rax
  bool v5; // zf
  float v6; // ecx
  float v7; // eax
  float v8; // eax

  v2 = lock;
  v3 = this;
  if ( this->bElevationLock != lock )
  {
    v4 = ((__int64 (*)(void))this->vfptr[17].__vecDelDtor)();
    v5 = v3->mCamboneDirty == 0;
    v3->rLockedElevationDef = *(float *)(v4 + 8);
    if ( !v5 )
      UFG::CharacterSubjectComponent::UpdateCambone(v3);
    v5 = v3->mPelvisDirty == 0;
    v3->rLockedElevationCam = v3->mCambonePosition.z;
    if ( !v5 )
      UFG::CharacterSubjectComponent::UpdatePelvis(v3);
    v3->rLockedElevationHip = v3->mPelvisPosition.z;
    v6 = *(float *)(((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[26].__vecDelDtor)(v3) + 8);
    v7 = v3->rLockedElevationCam;
    v3->bElevationLock = v2;
    v3->rLockedElevationFocusCreatureCambone = v7;
    v8 = v3->rLockedElevationHip;
    v3->rLockedElevationHed = v6;
    v3->rLockedElevationFocusCreaturePelvis = v8;
    v3->rLockedElevationFocusCreatureHead = v6;
  }
}

// File Line: 859
// RVA: 0x53B4C0
char __fastcall UFG::CharacterSubjectComponent::IsOverrideSymbolValid(__int64 _override)
{
  _DWORD *v1; // r14
  UFG::qSymbol *v2; // rbx
  UFG::qSymbol *v3; // rsi
  const char **v4; // rdi
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+38h] [rbp-40h]
  UFG::qSymbol v8; // [rsp+80h] [rbp+8h]

  v1 = (_DWORD *)_override;
  if ( *(_DWORD *)_override != UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v8, 0xFFFFFFFF)->mUID )
  {
    v2 = cached_names;
    if ( !(_S13_6 & 1) )
    {
      _S13_6 |= 1u;
      `eh vector constructor iterator'(cached_names, 4ui64, 106, (void (__fastcall *)(void *))BackInfo::BackInfo);
      atexit(UFG::CharacterSubjectComponent::IsOverrideSymbolValid_::_4_::_dynamic_atexit_destructor_for__cached_names__);
    }
    if ( !init_1 )
    {
      init_1 = 1;
      v3 = cached_names;
      v4 = TweakableOverrideNames_0;
      do
      {
        v5 = UFG::qString::FormatEx(&result, "Cameras-%s", *v4);
        v3->mUID = UFG::qSymbol::create_from_string(&v8, v5->mData)->mUID;
        UFG::qString::~qString(&result);
        ++v4;
        ++v3;
      }
      while ( (signed __int64)v4 < (signed __int64)&gIconSocialHubAvatarPlayer_ChallengeOutgoing_17 );
    }
    while ( *v1 != v2->mUID )
    {
      ++v2;
      if ( (signed __int64)v2 >= (signed __int64)&_S13_6 )
        return 0;
    }
  }
  return 1;
}

// File Line: 891
// RVA: 0x54C590
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(UFG::CharacterSubjectComponent *this, int type, __int64 override)
{
  unsigned int *v3; // rdi
  __int64 v4; // rsi
  UFG::CharacterSubjectComponent *v5; // rbx

  v3 = (unsigned int *)override;
  v4 = type;
  v5 = this;
  if ( !(_S14_2 & 1) )
  {
    _S14_2 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_1, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  v5->mContextOverrideScriptGlobal[v4].mSymbol.mUID = *v3;
  v5->mContextOverrideScriptGlobal[v4].mUID = -1;
}

// File Line: 918
// RVA: 0x54BF80
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(UFG::CharacterSubjectComponent *this, ActionContext *ac, int type, __int64 override, unsigned int uid)
{
  __int64 v5; // rdx

  v5 = type;
  this->mContextOverrideFreemanNPC[v5].mSymbol.mUID = *(_DWORD *)override;
  this->mContextOverrideFreemanNPC[v5].mUID = uid;
}

// File Line: 953
// RVA: 0x52C100
__int64 __fastcall UFG::CharacterSubjectComponent::GetContextOverrideFreemanNPC_ID(UFG::CharacterSubjectComponent *this, int type)
{
  return this->mContextOverrideFreemanNPC[type].mUID;
}

// File Line: 960
// RVA: 0x54BFA0
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(UFG::CharacterSubjectComponent *this, ActionContext *ac, int type, __int64 override, unsigned int uid)
{
  UFG::qSymbol *v5; // rbx
  __int64 v6; // rsi
  UFG::CharacterSubjectComponent *v7; // rdi
  unsigned int v8; // eax

  v5 = (UFG::qSymbol *)override;
  v6 = type;
  v7 = this;
  v8 = _S15_3;
  if ( !(_S15_3 & 1) )
  {
    _S15_3 |= 1u;
    UFG::qSymbol::create_from_string(&combatBasicSymbol, "Cameras-FollowCameraCombatBasic");
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer_::_2_::_dynamic_atexit_destructor_for__combatBasicSymbol__);
    v8 = _S15_3;
  }
  if ( !(v8 & 2) )
  {
    _S15_3 = v8 | 2;
    UFG::qSymbol::create_from_string(&combatBasicTargetedSymbol, "Cameras-FollowCameraCombatBasicTargeted");
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer_::_2_::_dynamic_atexit_destructor_for__combatBasicTargetedSymbol__);
    v8 = _S15_3;
  }
  if ( !(v8 & 4) )
  {
    _S15_3 = v8 | 4;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_2, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  if ( v5->mUID == combatBasicSymbol.mUID )
  {
    if ( v7->mContextOverrideFreemanPlayer[v6].mSymbol.mUID == combatBasicTargetedSymbol.mUID )
      return;
    if ( UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0) )
      v5->mUID = combatBasicTargetedSymbol.mUID;
  }
  v7->mContextOverrideFreemanPlayer[v6].mSymbol = (UFG::qSymbol)v5->mUID;
  v7->mContextOverrideFreemanPlayer[v6].mUID = uid;
}

// File Line: 1010
// RVA: 0x52C110
__int64 __fastcall UFG::CharacterSubjectComponent::GetContextOverrideFreemanPlayer_ID(UFG::CharacterSubjectComponent *this, int type)
{
  return this->mContextOverrideFreemanPlayer[type].mUID;
}

// File Line: 1016
// RVA: 0x54C3C0
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(UFG::CharacterSubjectComponent *this, ActionContext *ac, UFG::SimObject *poiobj, int type, UFG::qSymbol override_left, UFG::qSymbol override_right)
{
  __int64 v6; // rdi
  UFG::SimObject *v7; // rsi
  UFG::CharacterSubjectComponent *v8; // rbx
  UFG::TransformNodeComponent *v9; // rsi
  UFG::BaseCameraComponent *v10; // rcx
  UFG::Camera *v11; // rbp
  float v12; // xmm1_4
  float v13; // xmm2_4
  __int64 v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  unsigned int v17; // ecx
  unsigned int *v18; // rax
  UFG::qVector2 viewport_scale; // [rsp+30h] [rbp-58h]
  __int64 v20; // [rsp+38h] [rbp-50h]
  UFG::qVector3 world_pos; // [rsp+40h] [rbp-48h]
  UFG::qVector3 v22; // [rsp+50h] [rbp-38h]
  UFG::qVector3 v23; // [rsp+60h] [rbp-28h]
  UFG::qVector3 result; // [rsp+70h] [rbp-18h]
  bool is_on_screen; // [rsp+A0h] [rbp+18h]

  v20 = -2i64;
  v6 = type;
  v7 = poiobj;
  v8 = this;
  if ( !(_S16_3 & 1) )
  {
    _S16_3 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_3, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  if ( !v7 )
    goto LABEL_15;
  v9 = v7->m_pTransformNodeComponent;
  if ( !v9 )
    goto LABEL_15;
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 )
    v11 = &v10->mCamera;
  else
    v11 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v12 = v9->mWorldTransform.v3.y;
  v13 = v9->mWorldTransform.v3.z;
  world_pos.x = v9->mWorldTransform.v3.x;
  world_pos.y = v12;
  world_pos.z = v13;
  v14 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v8->vfptr[17].__vecDelDtor)(v8);
  v15 = *(float *)(v14 + 4);
  v16 = *(float *)(v14 + 8);
  v22.x = *(float *)v14;
  v22.y = v15;
  v22.z = v16;
  is_on_screen = 0;
  viewport_scale.x = 1.0;
  viewport_scale.y = 1.0;
  UFG::Camera::GetScreenCoord(v11, &result, &world_pos, &viewport_scale, &is_on_screen);
  viewport_scale.x = 1.0;
  viewport_scale.y = 1.0;
  UFG::Camera::GetScreenCoord(v11, &v23, &v22, &viewport_scale, &is_on_screen);
  v17 = v8->mContextOverrideFreemanPlayer[v6].mSymbol.mUID;
  if ( v23.x >= result.x )
  {
    if ( v17 == nullSym_3.mUID || v17 != **(_DWORD **)&override_left.mUID )
    {
      v18 = *(unsigned int **)&override_right.mUID;
LABEL_16:
      v8->mContextOverrideFreemanPlayer[v6].mSymbol.mUID = *v18;
      v8->mContextOverrideFreemanPlayer[v6].mUID = -1;
      return;
    }
  }
  else if ( v17 == nullSym_3.mUID || v17 != **(_DWORD **)&override_right.mUID )
  {
LABEL_15:
    v18 = *(unsigned int **)&override_left.mUID;
    goto LABEL_16;
  }
}

// File Line: 1090
// RVA: 0x530BB0
signed __int64 __fastcall UFG::CharacterSubjectComponent::GetTransformType(__int64 tag)
{
  int *v1; // rbx
  unsigned int v2; // eax
  signed __int64 result; // rax
  int v4; // ecx

  v1 = (int *)tag;
  v2 = _S17_4;
  if ( !(_S17_4 & 1) )
  {
    _S17_4 |= 1u;
    UFG::qSymbol::create_from_string(&def, "def");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__def__);
    v2 = _S17_4;
  }
  if ( !(v2 & 2) )
  {
    _S17_4 = v2 | 2;
    UFG::qSymbol::create_from_string(&cam, "cam");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__cam__);
    v2 = _S17_4;
  }
  if ( !(v2 & 4) )
  {
    _S17_4 = v2 | 4;
    UFG::qSymbol::create_from_string(&hip, "hip");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__hip__);
    v2 = _S17_4;
  }
  if ( !(v2 & 8) )
  {
    _S17_4 = v2 | 8;
    UFG::qSymbol::create_from_string(&pel, "pel");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__pel__);
    v2 = _S17_4;
  }
  if ( !(v2 & 0x10) )
  {
    _S17_4 = v2 | 0x10;
    UFG::qSymbol::create_from_string(&hed, "hed");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__hed__);
    v2 = _S17_4;
  }
  if ( !(v2 & 0x20) )
  {
    _S17_4 = v2 | 0x20;
    UFG::qSymbol::create_from_string(&poi, "poi");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__poi__);
    v2 = _S17_4;
  }
  if ( !(v2 & 0x40) )
  {
    _S17_4 = v2 | 0x40;
    UFG::qSymbol::create_from_string(&pip, "pip");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__pip__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x80u) == 0 )
  {
    _S17_4 = v2 | 0x80;
    UFG::qSymbol::create_from_string(&veh, "veh");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__veh__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 8u) )
  {
    _S17_4 = v2 | 0x100;
    UFG::qSymbol::create_from_string(&car, "car");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__car__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 9u) )
  {
    _S17_4 = v2 | 0x200;
    UFG::qSymbol::create_from_string(&foc, "foc");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__foc__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 0xAu) )
  {
    _S17_4 = v2 | 0x400;
    UFG::qSymbol::create_from_string(&fcc, "fcc");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__fcc__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 0xBu) )
  {
    _S17_4 = v2 | 0x800;
    UFG::qSymbol::create_from_string(&fcp, "fcp");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__fcp__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 0xCu) )
  {
    _S17_4 = v2 | 0x1000;
    UFG::qSymbol::create_from_string(&fch, "fch");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__fch__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 0xDu) )
  {
    _S17_4 = v2 | 0x2000;
    UFG::qSymbol::create_from_string(&soc, "soc");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__soc__);
    v2 = _S17_4;
  }
  if ( !_bittest((const signed int *)&v2, 0xEu) )
  {
    _S17_4 = v2 | 0x4000;
    UFG::qSymbol::create_from_string(&hhm, "hhm");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__hhm__);
  }
  result = 0i64;
  v4 = *v1;
  if ( *v1 != def.mUID )
  {
    if ( v4 == cam.mUID )
    {
      result = 1i64;
    }
    else if ( v4 == hip.mUID || v4 == pel.mUID )
    {
      result = 2i64;
    }
    else if ( v4 == hed.mUID )
    {
      result = 3i64;
    }
    else if ( v4 == poi.mUID )
    {
      result = 4i64;
    }
    else if ( v4 == pip.mUID )
    {
      result = 5i64;
    }
    else if ( v4 == veh.mUID || v4 == car.mUID )
    {
      result = 6i64;
    }
    else if ( v4 == foc.mUID )
    {
      result = 7i64;
    }
    else if ( v4 == fcc.mUID )
    {
      result = 8i64;
    }
    else if ( v4 == fcp.mUID )
    {
      result = 9i64;
    }
    else if ( v4 == fch.mUID )
    {
      result = 10i64;
    }
    else if ( v4 == soc.mUID || v4 == hhm.mUID )
    {
      result = 11i64;
    }
  }
  return result;
}

// File Line: 1138
// RVA: 0x531870
void __fastcall UFG::CharacterSubjectComponent::GetTransformTypePosition(UFG::CharacterSubjectComponent *this, UFG::qVector3 *pos, UFG::CharacterSubjectComponent::SrcTransform transType, bool antiJitter)
{
  UFG::CharacterSubjectComponent::SrcTransform v4; // edi
  UFG::qVector3 *v5; // rbp
  UFG::CharacterSubjectComponent *v6; // rsi
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::qVector3 *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::SimComponent *v18; // r8
  signed __int64 v19; // rcx
  int v20; // edi
  int v21; // edi
  int v22; // edi
  __int64 v23; // rbx
  UFG::TransformNodeComponent *v24; // rbx
  UFG::SimComponent *v25; // rdx
  Creature *v26; // rbx
  UFG::SimObjectCharacter *v27; // rsi
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  unsigned int v30; // er8
  unsigned int v31; // er9
  UFG::SimComponentHolder *v32; // rdx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // edx
  int v36; // eax
  int v37; // edi
  int v38; // edi
  UFG::SimComponent *v39; // rdx
  UFG::eSocialInteractionResultEnum v40; // ebx
  UFG::SimObject *v41; // rsi
  UFG::SimComponent *v42; // rdi
  unsigned __int16 v43; // cx
  unsigned int v44; // er8
  unsigned int v45; // er9
  UFG::SimComponentHolder *v46; // rdi
  signed __int64 v47; // rdx
  unsigned int v48; // er8
  unsigned int v49; // er9
  unsigned int v50; // er8
  unsigned int v51; // er9
  __int128 v52; // xmm12
  float v53; // xmm8_4
  float v54; // xmm9_4
  float v55; // xmm7_4
  float v56; // xmm10_4
  float v57; // xmm11_4
  float v58; // xmm6_4
  unsigned __int16 v59; // cx
  UFG::FaceActionComponent *v60; // rdi
  unsigned int v61; // er8
  unsigned int v62; // er9
  UFG::SimComponentHolder *v63; // rdi
  signed __int64 v64; // rdx
  unsigned int v65; // er8
  unsigned int v66; // er9
  unsigned int v67; // er8
  unsigned int v68; // er9
  UFG::Conversation *v69; // rax
  UFG::SimObject *v70; // rbx
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm7_4
  float v74; // xmm3_4
  __m128 v75; // xmm4
  float v76; // xmm5_4
  __m128 v77; // xmm2
  float v78; // xmm1_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm1_4
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-C8h]
  UFG::CharacterSubjectComponent *v83; // [rsp+100h] [rbp+8h]
  bool v84; // [rsp+118h] [rbp+20h]

  v84 = antiJitter;
  v83 = this;
  v4 = transType;
  v5 = pos;
  v6 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v7 = v6->mTargetWorld.v3.y;
  v8 = v6->mTargetWorld.v3.z;
  v5->x = v6->mTargetWorld.v3.x;
  v5->y = v7;
  v5->z = v8;
  switch ( v4 )
  {
    case 1:
      v9 = UFG::CharacterSubjectComponent::CambonePosition(v6);
      v10 = v9->y;
      v11 = v9->z;
      v5->x = v9->x;
      v5->y = v10;
      v5->z = v11;
      goto LABEL_138;
    case 2:
      v12 = UFG::CharacterSubjectComponent::PelvisPosition(v6);
      v13 = v12->y;
      v14 = v12->z;
      v5->x = v12->x;
      v5->y = v13;
      v5->z = v14;
      goto LABEL_138;
    case 3:
      v15 = (float *)v6->vfptr[26].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v6->vfptr, 1073741824u);
      v16 = v15[1];
      v17 = v15[2];
      v5->x = *v15;
      v5->y = v16;
      v5->z = v17;
      goto LABEL_138;
    case 4:
    case 5:
    case 6:
    case 7:
      v18 = v6->pTargetingSystemBaseComponent.m_pSimComponent;
      v19 = 26i64;
      v20 = v4 - 4;
      if ( v20 )
      {
        v21 = v20 - 1;
        if ( v21 )
        {
          v22 = v21 - 1;
          if ( v22 )
          {
            if ( v22 == 1 )
              v19 = 22i64;
          }
          else
          {
            v19 = 28i64;
          }
        }
        else
        {
          v19 = 27i64;
        }
      }
      if ( v18
        && (v23 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v18[1].m_Flags + v19 + 8)
                            + *(_QWORD *)&v18[1].m_TypeUID
                            + 40)) != 0 )
      {
        v24 = *(UFG::TransformNodeComponent **)(v23 + 88);
      }
      else
      {
        v24 = 0i64;
      }
      if ( v24 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v24);
        v5->x = v24->mWorldTransform.v3.x;
        v5->y = v24->mWorldTransform.v3.y;
        v5->z = v24->mWorldTransform.v3.z;
      }
      goto LABEL_138;
    case 8:
    case 9:
    case 10:
      v25 = v6->pTargetingSystemBaseComponent.m_pSimComponent;
      v26 = 0i64;
      if ( v25 )
      {
        v27 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v25[1].m_Flags + 86i64)
                                          + *(_QWORD *)&v25[1].m_TypeUID
                                          + 40);
        if ( !v27 )
          goto LABEL_54;
        v28 = v27->m_Flags;
        if ( (v28 >> 14) & 1 )
        {
          v29 = v27->m_Components.p[9].m_pComponent;
        }
        else if ( (v28 & 0x8000u) == 0 )
        {
          if ( (v28 >> 13) & 1 )
          {
            v29 = v27->m_Components.p[8].m_pComponent;
          }
          else if ( (v28 >> 12) & 1 )
          {
            v30 = v27->mComponentTableEntryCount;
            v31 = v27->m_Components.size;
            if ( v30 >= v31 )
            {
LABEL_33:
              v29 = 0i64;
            }
            else
            {
              while ( 1 )
              {
                v32 = &v27->m_Components.p[v30];
                if ( (v32->m_TypeUID & 0xFE000000) == (UFG::BaseAnimationComponent::_TypeUID & 0xFE000000)
                  && !(UFG::BaseAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v30 >= v31 )
                  goto LABEL_33;
              }
              v29 = v32->m_pComponent;
            }
          }
          else
          {
            v29 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v27->vfptr,
                    UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v29 = v27->m_Components.p[9].m_pComponent;
        }
        if ( v29 )
          v26 = *(Creature **)&v29[2].m_TypeUID;
      }
      else
      {
        v27 = 0i64;
      }
      if ( v27 && v26 )
      {
        v33 = _S18_4;
        if ( !(_S18_4 & 1) )
        {
          _S18_4 |= 1u;
          camBoneUID = UFG::qStringHashUpper32("CameraSync01", 0xFFFFFFFF);
          v33 = _S18_4;
        }
        if ( !(v33 & 2) )
        {
          _S18_4 = v33 | 2;
          pelBoneUID = UFG::qStringHashUpper32("Bip01 Pelvis", 0xFFFFFFFF);
          v33 = _S18_4;
        }
        if ( v33 & 4 )
        {
          v34 = hedBoneUID;
        }
        else
        {
          _S18_4 = v33 | 4;
          v34 = UFG::qStringHashUpper32("Bip01 Head", 0xFFFFFFFF);
          hedBoneUID = v34;
        }
        v35 = camBoneUID;
        if ( v4 == 9 )
        {
          v35 = pelBoneUID;
        }
        else if ( v4 == 10 )
        {
          v35 = v34;
        }
        if ( v26->mPose.mRigHandle.mData )
        {
          v36 = Skeleton::GetBoneID(v26->mPose.mRigHandle.mUFGSkeleton, v35);
          if ( v36 != -1 )
          {
            Creature::GetTransform(v26, v36, &transform);
            v5->x = transform.v3.x;
            v5->y = transform.v3.y;
            v5->z = transform.v3.z;
          }
        }
        goto LABEL_137;
      }
LABEL_54:
      v6 = v83;
      v37 = v4 - 8;
      if ( v37 )
      {
        v38 = v37 - 1;
        if ( v38 )
        {
          if ( v38 == 1 )
            UFG::CharacterSubjectComponent::GetTransformTypePosition(v83, v5, SrcTransform_Head, 1);
        }
        else
        {
          UFG::CharacterSubjectComponent::GetTransformTypePosition(v83, v5, SrcTransform_Pelvis, 1);
        }
      }
      else
      {
        UFG::CharacterSubjectComponent::GetTransformTypePosition(v83, v5, SrcTransform_Camera, 1);
      }
      goto LABEL_138;
    case 11:
      v39 = v6->pTargetingSystemBaseComponent.m_pSimComponent;
      v40 = 0;
      if ( v6->pSocialTargetOverrideComponent.m_pSimComponent )
        v41 = v6->pSocialTargetOverrideComponent.m_pSimComponent->m_pSimObject;
      else
        v41 = 0i64;
      if ( v41 )
        goto LABEL_69;
      if ( !v39 )
      {
        v41 = 0i64;
        goto LABEL_68;
      }
      v41 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v39[1].m_Flags + 58i64)
                               + *(_QWORD *)&v39[1].m_TypeUID
                               + 40);
      if ( !v41 )
      {
LABEL_68:
        v42 = 0i64;
        goto LABEL_97;
      }
LABEL_69:
      v43 = v41->m_Flags;
      if ( !((v43 >> 14) & 1) )
      {
        if ( (v43 & 0x8000u) == 0 )
        {
          if ( (v43 >> 13) & 1 )
          {
            v48 = (unsigned int)v41[1].vfptr;
            v49 = v41->m_Components.size;
            if ( v48 < v49 )
            {
              v46 = v41->m_Components.p;
              do
              {
                v47 = v48;
                if ( (v46[v48].m_TypeUID & 0xFE000000) == (UFG::CharacterSubjectComponent::_TypeUID & 0xFE000000)
                  && !(UFG::CharacterSubjectComponent::_TypeUID & ~v46[v48].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_81;
                }
              }
              while ( ++v48 < v49 );
            }
          }
          else
          {
            if ( !((v43 >> 12) & 1) )
            {
              v42 = UFG::SimObject::GetComponentOfType(v41, UFG::CharacterSubjectComponent::_TypeUID);
              goto LABEL_97;
            }
            v50 = (unsigned int)v41[1].vfptr;
            v51 = v41->m_Components.size;
            if ( v50 < v51 )
            {
              v46 = v41->m_Components.p;
              do
              {
                v47 = v50;
                if ( (v46[v50].m_TypeUID & 0xFE000000) == (UFG::CharacterSubjectComponent::_TypeUID & 0xFE000000)
                  && !(UFG::CharacterSubjectComponent::_TypeUID & ~v46[v50].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_81;
                }
              }
              while ( ++v50 < v51 );
            }
          }
        }
        else
        {
          v44 = (unsigned int)v41[1].vfptr;
          v45 = v41->m_Components.size;
          if ( v44 < v45 )
          {
            v46 = v41->m_Components.p;
            while ( 1 )
            {
              v47 = v44;
              if ( (v46[v44].m_TypeUID & 0xFE000000) == (UFG::CharacterSubjectComponent::_TypeUID & 0xFE000000)
                && !(UFG::CharacterSubjectComponent::_TypeUID & ~v46[v44].m_TypeUID & 0x1FFFFFF) )
              {
                break;
              }
              if ( ++v44 >= v45 )
                goto LABEL_73;
            }
LABEL_81:
            v42 = v46[v47].m_pComponent;
            goto LABEL_97;
          }
        }
LABEL_73:
        v42 = 0i64;
        goto LABEL_97;
      }
      v42 = v41->m_Components.p[37].m_pComponent;
      if ( !v42
        || (UFG::CharacterSubjectComponent::_TypeUID ^ v42->m_TypeUID) & 0xFE000000
        || UFG::CharacterSubjectComponent::_TypeUID & ~v42->m_TypeUID & 0x1FFFFFF )
      {
        goto LABEL_73;
      }
LABEL_97:
      if ( v42 )
      {
        v52 = *(unsigned int *)(((__int64 (__cdecl *)(UFG::CharacterSubjectComponent *))v83->vfptr[26].__vecDelDtor)(v83)
                              + 8);
        v53 = v83->mTargetWorld.v3.x;
        v54 = v83->mTargetWorld.v3.y;
        v55 = *(float *)(((__int64 (__fastcall *)(UFG::SimComponent *))v42->vfptr[26].__vecDelDtor)(v42) + 8);
        v56 = *(float *)&v42[9].m_Flags;
        v57 = *(float *)(&v42[9].m_SimObjIndex + 1);
        v58 = UFG::FollowCameraComponent::rSocialSlideBasePercent;
        if ( !v41 )
        {
LABEL_132:
          v5->x = v53 + (float)(v58 * (float)(v56 - v53));
          v5->y = v54 + (float)(v58 * (float)(v57 - v54));
          v5->z = (float)((float)(v55 - *(float *)&v52) * v58) + *(float *)&v52;
          goto LABEL_137;
        }
        v59 = v41->m_Flags;
        if ( (v59 >> 14) & 1 )
        {
          v60 = (UFG::FaceActionComponent *)v41->m_Components.p[45].m_pComponent;
          goto LABEL_125;
        }
        if ( (v59 & 0x8000u) == 0 )
        {
          if ( (v59 >> 13) & 1 )
          {
            v65 = (unsigned int)v41[1].vfptr;
            v66 = v41->m_Components.size;
            if ( v65 < v66 )
            {
              v63 = v41->m_Components.p;
              do
              {
                v64 = v65;
                if ( (v63[v65].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && !(UFG::FaceActionComponent::_TypeUID & ~v63[v65].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_108;
                }
              }
              while ( ++v65 < v66 );
            }
          }
          else
          {
            if ( !((v59 >> 12) & 1) )
            {
              v60 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                  v41,
                                                  UFG::FaceActionComponent::_TypeUID);
LABEL_125:
              if ( v60 )
              {
                while ( 1 )
                {
                  v69 = UFG::FaceActionComponent::GetConversationReference(v60, v40);
                  if ( v69 )
                  {
                    if ( v69->m_state == 1 )
                      break;
                  }
                  if ( (signed int)++v40 >= 8 )
                    goto LABEL_132;
                }
                if ( UFG::Conversation::IsSpeaker(v69, v41) )
                  v58 = v58 + UFG::FollowCameraComponent::rSocialTargetTalkPercent;
              }
              goto LABEL_132;
            }
            v67 = (unsigned int)v41[1].vfptr;
            v68 = v41->m_Components.size;
            if ( v67 < v68 )
            {
              v63 = v41->m_Components.p;
              do
              {
                v64 = v67;
                if ( (v63[v67].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && !(UFG::FaceActionComponent::_TypeUID & ~v63[v67].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_108;
                }
              }
              while ( ++v67 < v68 );
            }
          }
        }
        else
        {
          v61 = (unsigned int)v41[1].vfptr;
          v62 = v41->m_Components.size;
          if ( v61 < v62 )
          {
            v63 = v41->m_Components.p;
            while ( 1 )
            {
              v64 = v61;
              if ( (v63[v61].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && !(UFG::FaceActionComponent::_TypeUID & ~v63[v61].m_TypeUID & 0x1FFFFFF) )
              {
                break;
              }
              if ( ++v61 >= v62 )
                goto LABEL_109;
            }
LABEL_108:
            v60 = (UFG::FaceActionComponent *)v63[v64].m_pComponent;
            goto LABEL_125;
          }
        }
LABEL_109:
        v60 = 0i64;
        goto LABEL_125;
      }
LABEL_137:
      v6 = v83;
LABEL_138:
      if ( v84 && UFG::gAntiJitterRadius > 0.000099999997 )
      {
        v73 = v6->mAntiJitterPosition.x;
        v74 = v5->x - v73;
        v75 = (__m128)LODWORD(v5->y);
        v75.m128_f32[0] = v75.m128_f32[0] - v6->mAntiJitterPosition.y;
        v76 = v5->z - v6->mAntiJitterPosition.z;
        v77 = v75;
        v77.m128_f32[0] = (float)((float)(v75.m128_f32[0] * v75.m128_f32[0]) + (float)(v74 * v74)) + (float)(v76 * v76);
        LODWORD(v78) = (unsigned __int128)_mm_sqrt_ps(v77);
        if ( v78 > UFG::gAntiJitterRadius )
        {
          v79 = (float)(v78 - UFG::gAntiJitterRadius) / v78;
          v6->mAntiJitterPosition.x = (float)(v74 * v79) + v73;
          v6->mAntiJitterPosition.y = (float)(v75.m128_f32[0] * v79) + v6->mAntiJitterPosition.y;
          v6->mAntiJitterPosition.z = (float)(v76 * v79) + v6->mAntiJitterPosition.z;
        }
        v80 = v6->mAntiJitterPosition.y;
        v81 = v6->mAntiJitterPosition.z;
        v5->x = v6->mAntiJitterPosition.x;
        v5->y = v80;
        v5->z = v81;
      }
      return;
    case 12:
      v70 = v6->m_pSimObject;
      if ( v70 )
        v70 = (UFG::SimObject *)v70->m_pTransformNodeComponent;
      if ( v70 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v70);
        v71 = *((float *)v70[1].mNode.mChild + 1);
        v72 = *(float *)&v70[1].mNode.mChild[1];
        v5->x = *(float *)v70[1].mNode.mChild;
        v5->y = v71;
        v5->z = v72;
      }
      goto LABEL_138;
    default:
      goto LABEL_138;
  }
}

// File Line: 1345
// RVA: 0x532260
void __fastcall UFG::CharacterSubjectComponent::GetTransformTypePosition(UFG::CharacterSubjectComponent *this, UFG::qVector4 *pos, UFG::CharacterSubjectComponent::SrcTransform transType, bool antiJitter)
{
  UFG::qVector4 *v4; // rbx

  v4 = pos;
  UFG::CharacterSubjectComponent::GetTransformTypePosition(this, (UFG::qVector3 *)pos, transType, antiJitter);
  v4->w = 1.0;
}

// File Line: 1352
// RVA: 0x530FC0
UFG::CharacterSubjectComponent::GetTransformTypeOrientation

// File Line: 1535
// RVA: 0x54C0B0
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(UFG::CharacterSubjectComponent *this, ActionContext *ac, int type, __int64 left)
{
  unsigned int *v4; // r13
  __int64 v5; // r12
  ActionContext *v6; // rbx
  UFG::CharacterSubjectComponent *v7; // rsi
  unsigned int v8; // eax
  UFG::SimObject *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::Camera *v11; // r14
  UFG::SimComponent *v12; // rax
  unsigned int v13; // er8
  unsigned int v14; // er9
  UFG::SimComponentHolder *v15; // rbx
  signed __int64 v16; // rdx
  unsigned int v17; // er8
  unsigned int v18; // er9
  __int64 v19; // rax
  UFG::CharacterSubjectComponent::SrcTransform v20; // edi
  UFG::CharacterSubjectComponent::SrcTransform v21; // ebx
  UFG::BaseCameraComponent *v22; // rcx
  unsigned int v23; // eax
  UFG::qSymbol tag; // [rsp+8h] [rbp-41h]
  __int64 v25; // [rsp+10h] [rbp-39h]
  UFG::qSymbol *v26; // [rsp+18h] [rbp-31h]
  UFG::qVector3 world_pos; // [rsp+20h] [rbp-29h]
  UFG::qVector3 pos; // [rsp+30h] [rbp-19h]
  UFG::qVector3 v29; // [rsp+40h] [rbp-9h]
  UFG::qVector3 result; // [rsp+50h] [rbp+7h]
  bool is_on_screen; // [rsp+B0h] [rbp+67h]
  unsigned int *retaddr; // [rsp+B8h] [rbp+6Fh]
  _DWORD *v33; // [rsp+C0h] [rbp+77h]
  unsigned int *v34; // [rsp+C8h] [rbp+7Fh]

  v25 = -2i64;
  v4 = (unsigned int *)left;
  v5 = type;
  v6 = ac;
  v7 = this;
  if ( !(_S20_0 & 1) )
  {
    _S20_0 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_4, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  v8 = nullSym_4.mUID;
  if ( *v4 == nullSym_4.mUID || *retaddr == nullSym_4.mUID || *v33 == nullSym_4.mUID || *v34 == nullSym_4.mUID )
    goto LABEL_40;
  if ( !v6 )
    return;
  v9 = v6->mSimObject.m_pPointer;
  if ( !v9 )
    return;
  v10 = v9->m_Flags;
  v11 = 0i64;
  if ( (v10 >> 14) & 1 )
  {
    v12 = v9->m_Components.p[20].m_pComponent;
    goto LABEL_30;
  }
  if ( (v10 & 0x8000u) != 0 )
  {
    v12 = v9->m_Components.p[20].m_pComponent;
    goto LABEL_30;
  }
  if ( (v10 >> 13) & 1 )
  {
    v13 = (unsigned int)v9[1].vfptr;
    v14 = v9->m_Components.size;
    if ( v13 < v14 )
    {
      v15 = v9->m_Components.p;
      while ( 1 )
      {
        v16 = v13;
        if ( (v15[v13].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v15[v13].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v13 >= v14 )
          goto LABEL_21;
      }
LABEL_20:
      v12 = v15[v16].m_pComponent;
      goto LABEL_30;
    }
LABEL_21:
    v12 = 0i64;
    goto LABEL_30;
  }
  if ( (v10 >> 12) & 1 )
  {
    v17 = (unsigned int)v9[1].vfptr;
    v18 = v9->m_Components.size;
    if ( v17 < v18 )
    {
      v15 = v9->m_Components.p;
      while ( 1 )
      {
        v16 = v17;
        if ( (v15[v17].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && !(UFG::TargetingSystemBaseComponent::_TypeUID & ~v15[v17].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_20;
        }
        if ( ++v17 >= v18 )
          goto LABEL_21;
      }
    }
    goto LABEL_21;
  }
  v12 = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_30:
  if ( !v12 )
    return;
  v26 = &tag;
  v19 = (unsigned int)*v33;
  v20 = (unsigned int)UFG::CharacterSubjectComponent::GetTransformType((__int64)&tag);
  v26 = &tag;
  tag.mUID = *v34;
  v21 = (unsigned int)UFG::CharacterSubjectComponent::GetTransformType((__int64)&tag);
  UFG::CharacterSubjectComponent::GetTransformTypePosition(v7, &pos, v20, 1);
  UFG::CharacterSubjectComponent::GetTransformTypePosition(v7, &world_pos, v21, 1);
  v22 = UFG::Director::Get()->mCurrentCamera;
  if ( v22 )
    v11 = &v22->mCamera;
  is_on_screen = 0;
  UFG::Camera::GetScreenCoord(v11, &result, &world_pos, (UFG::qVector2 *)&tag, &is_on_screen);
  UFG::Camera::GetScreenCoord(v11, &v29, &pos, (UFG::qVector2 *)&tag, &is_on_screen);
  v23 = v7->mContextOverrideFreemanPlayer[v5].mSymbol.mUID;
  if ( v29.x >= result.x )
  {
    if ( v23 == nullSym_4.mUID || v23 != *v4 )
    {
      v8 = *retaddr;
      goto LABEL_40;
    }
  }
  else if ( v23 == nullSym_4.mUID || v23 != *retaddr )
  {
    v8 = *v4;
LABEL_40:
    v7->mContextOverrideFreemanPlayer[v5].mSymbol.mUID = v8;
    v7->mContextOverrideFreemanPlayer[v5].mUID = -1;
    return;
  }
}

// File Line: 1620
// RVA: 0x54C610
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(UFG::CharacterSubjectComponent *this, int type, __int64 override)
{
  __int64 v3; // r9

  v3 = type;
  this->mContextOverrideScriptLocal[v3].mSymbol.mUID = *(_DWORD *)override;
  this->mContextOverrideScriptLocal[v3].mUID = -1;
}

// File Line: 1646
// RVA: 0x52BC20
UFG::qSymbol *__fastcall UFG::CharacterSubjectComponent::GetContextOverride(UFG::CharacterSubjectComponent *this, UFG::qSymbol *result, int type)
{
  __int64 v3; // r15
  UFG::qSymbol *v4; // rsi
  UFG::CharacterSubjectComponent *v5; // r13
  UFG::SimObject *v6; // rbx
  UFG::HealthComponent *v7; // rbp
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // er9
  signed __int64 v12; // r8
  unsigned int v13; // ecx
  unsigned int v14; // er9
  unsigned int v15; // ecx
  unsigned int v16; // er9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::VehicleSubjectComponent *v18; // rdi
  unsigned int v19; // eax
  unsigned int v20; // ecx
  UFG::qSymbol *v21; // rax
  unsigned __int16 v22; // r8
  unsigned int v23; // er8
  unsigned int v24; // er11
  UFG::SimComponentHolder *v25; // r14
  signed __int64 v26; // r10
  unsigned int v27; // er8
  unsigned int v28; // er11
  unsigned int v29; // er8
  UFG::qSymbol resulta; // [rsp+20h] [rbp-48h]
  UFG::qSymbol v32; // [rsp+24h] [rbp-44h]
  UFG::qSymbol v33; // [rsp+28h] [rbp-40h]
  __int64 v34; // [rsp+30h] [rbp-38h]
  UFG::qSymbol *v35; // [rsp+38h] [rbp-30h]
  UFG::qSymbol name_a; // [rsp+70h] [rbp+8h]
  UFG::qSymbol _override; // [rsp+88h] [rbp+20h]

  v34 = -2i64;
  v3 = type;
  v4 = result;
  v5 = this;
  if ( !(_S21_0 & 1) )
  {
    _S21_0 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_5, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::GetContextOverride_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  v6 = v5->m_pSimObject;
  v7 = 0i64;
  if ( !v6 )
    goto LABEL_33;
  v8 = v6->m_Flags;
  if ( !((v8 >> 14) & 1) )
  {
    if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v13 = (unsigned int)v6[1].vfptr;
        v14 = v6->m_Components.size;
        if ( v13 < v14 )
        {
          do
          {
            v12 = (signed __int64)&v6->m_Components.p[v13];
            if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && !(UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_12;
            }
          }
          while ( ++v13 < v14 );
        }
      }
      else
      {
        if ( !((v8 >> 12) & 1) )
        {
          v9 = UFG::SimObject::GetComponentOfType(v5->m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_27;
        }
        v15 = (unsigned int)v6[1].vfptr;
        v16 = v6->m_Components.size;
        if ( v15 < v16 )
        {
          do
          {
            v12 = (signed __int64)&v6->m_Components.p[v15];
            if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && !(UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_12;
            }
          }
          while ( ++v15 < v16 );
        }
      }
    }
    else
    {
      v10 = (unsigned int)v6[1].vfptr;
      v11 = v6->m_Components.size;
      if ( v10 < v11 )
      {
        while ( 1 )
        {
          v12 = (signed __int64)&v6->m_Components.p[v10];
          if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
            && !(UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v10 >= v11 )
            goto LABEL_13;
        }
LABEL_12:
        v9 = *(UFG::SimComponent **)v12;
        goto LABEL_27;
      }
    }
LABEL_13:
    v9 = 0i64;
    goto LABEL_27;
  }
  v9 = v6->m_Components.p[44].m_pComponent;
LABEL_27:
  if ( !v9
    || !v9[1].m_BoundComponentHandles.mNode.mPrev
    || (v17 = v9[1].m_BoundComponentHandles.mNode.mPrev[2].mNext) == 0i64
    || (v18 = (UFG::VehicleSubjectComponent *)v17[6].mNext[31].mPrev) == 0i64
    || (UFG::VehicleSubjectComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000
    || UFG::VehicleSubjectComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF )
  {
LABEL_33:
    v18 = 0i64;
  }
  v19 = nullSym_5.mUID;
  v20 = nullSym_5.mUID;
  name_a.mUID = nullSym_5.mUID;
  if ( !v18 )
    goto LABEL_44;
  if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v18->vfptr[32].__vecDelDtor)(v18) )
  {
LABEL_42:
    v20 = name_a.mUID;
    goto LABEL_43;
  }
  if ( (_DWORD)v3 )
  {
    if ( (_DWORD)v3 == 1 )
    {
      v20 = UFG::VehicleSubjectComponent::GetFollowOverrideContext(v18, &resulta)->mUID;
      name_a.mUID = v20;
      v19 = nullSym_5.mUID;
      if ( v20 == nullSym_5.mUID )
        goto LABEL_44;
      name_a.mUID = UFG::qSymbol::create_suffix(&v32, &name_a, "Aim")->mUID;
      v35 = &_override;
      _override.mUID = name_a.mUID;
      if ( !UFG::CharacterSubjectComponent::IsOverrideSymbolValid((UFG::qSymbol)&_override) )
      {
        v19 = nullSym_5.mUID;
        v20 = nullSym_5.mUID;
        name_a.mUID = nullSym_5.mUID;
        goto LABEL_44;
      }
    }
    goto LABEL_42;
  }
  v21 = UFG::VehicleSubjectComponent::GetFollowOverrideContext(v18, &v33);
  v20 = v21->mUID;
  name_a.mUID = v21->mUID;
LABEL_43:
  v19 = nullSym_5.mUID;
LABEL_44:
  if ( !v6 )
    goto LABEL_74;
  v22 = v6->m_Flags;
  if ( (v22 >> 14) & 1 )
  {
    v7 = (UFG::HealthComponent *)v6->m_Components.p[6].m_pComponent;
    goto LABEL_65;
  }
  if ( (v22 & 0x8000u) != 0 )
  {
    v7 = (UFG::HealthComponent *)v6->m_Components.p[6].m_pComponent;
    goto LABEL_65;
  }
  if ( (v22 >> 13) & 1 )
  {
    v23 = (unsigned int)v6[1].vfptr;
    v24 = v6->m_Components.size;
    if ( v23 >= v24 )
      goto LABEL_65;
    v25 = v6->m_Components.p;
    while ( 1 )
    {
      v26 = v23;
      if ( (v25[v23].m_TypeUID & 0xFE000000) == (UFG::HealthComponent::_TypeUID & 0xFE000000)
        && !(UFG::HealthComponent::_TypeUID & ~v25[v23].m_TypeUID & 0x1FFFFFF) )
      {
        goto LABEL_56;
      }
      if ( ++v23 >= v24 )
        goto LABEL_65;
    }
  }
  if ( (v22 >> 12) & 1 )
  {
    v27 = (unsigned int)v6[1].vfptr;
    v28 = v6->m_Components.size;
    if ( v27 < v28 )
    {
      v25 = v6->m_Components.p;
      while ( 1 )
      {
        v26 = v27;
        if ( (v25[v27].m_TypeUID & 0xFE000000) == (UFG::HealthComponent::_TypeUID & 0xFE000000)
          && !(UFG::HealthComponent::_TypeUID & ~v25[v27].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v27 >= v28 )
          goto LABEL_65;
      }
LABEL_56:
      v7 = (UFG::HealthComponent *)v25[v26].m_pComponent;
      goto LABEL_65;
    }
  }
  else
  {
    v7 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v6, UFG::HealthComponent::_TypeUID);
    v20 = name_a.mUID;
    v19 = nullSym_5.mUID;
  }
LABEL_65:
  if ( v7 )
  {
    if ( (UFG::HealthComponent::GetIsKilled(v7) || v7->m_bIsKnockedOut || v7->m_bHealthClampedToMinimum) && !(_DWORD)v3 )
    {
      if ( !(_S21_0 & 2) )
      {
        _S21_0 |= 2u;
        UFG::qSymbol::create_from_string(&contextSymbolRagdoll, "Cameras-FollowCameraRagDoll");
        atexit(UFG::CharacterSubjectComponent::GetContextOverride_::_15_::_dynamic_atexit_destructor_for__contextSymbolRagdoll__);
      }
      v19 = contextSymbolRagdoll.mUID;
      goto LABEL_81;
    }
    v20 = name_a.mUID;
    v19 = nullSym_5.mUID;
  }
LABEL_74:
  v29 = v5->mContextOverrideScriptGlobal[v3].mSymbol.mUID;
  if ( v29 != v19
    || (v29 = v5->mContextOverrideFreemanNPC[v3].mSymbol.mUID, v29 != v19)
    || (v29 = v5->mContextOverrideFreemanPlayer[v3].mSymbol.mUID, v29 != v19) )
  {
    v4->mUID = v29;
  }
  else
  {
    if ( v20 == v19 )
    {
      v20 = v5->mContextOverrideScriptLocal[v3].mSymbol.mUID;
      if ( v20 == v19 )
      {
LABEL_81:
        v4->mUID = v19;
        return v4;
      }
    }
    v4->mUID = v20;
  }
  return v4;
}      if ( v20 == v19 )
      {
LABEL_81:
        v4->mUID = v19;
        return v4;
      }
    }
    v4->mUID = v20;
  }
  return v4;
}

// File Line: 1703
// RVA: 0x54D3B0
void __fastcall UFG::CharacterSubjectComponent::SetGotoRise(UFG::CharacterSubjectComponent *this, float rise, float rate, float patience)
{
  this->rGotoRise = rise;
  this->rGotoRiseRate = rate;
  this->rGotoRisePatience = patience;
  this->bGotoRise = 1;
}

// File Line: 1712
// RVA: 0x52A9C0
char __fastcall UFG::CharacterSubjectComponent::GetAndClearGotoRise(UFG::CharacterSubjectComponent *this, float *rise, float *rate, float *patience)
{
  if ( !this->bGotoRise )
    return 0;
  *rise = this->rGotoRise;
  *rate = this->rGotoRiseRate;
  *patience = this->rGotoRisePatience;
  this->bGotoRise = 0;
  return 1;
}

// File Line: 1725
// RVA: 0x54D390
void __fastcall UFG::CharacterSubjectComponent::SetGotoRadius(UFG::CharacterSubjectComponent *this, float radius, float rate, float patience)
{
  this->rGotoRadius = radius;
  this->rGotoRadiusRate = rate;
  this->rGotoRadiusPatience = patience;
  this->bGotoRadius = 1;
}

// File Line: 1734
// RVA: 0x52A990
char __fastcall UFG::CharacterSubjectComponent::GetAndClearGotoRadius(UFG::CharacterSubjectComponent *this, float *radius, float *rate, float *patience)
{
  if ( !this->bGotoRadius )
    return 0;
  *radius = this->rGotoRadius;
  *rate = this->rGotoRadiusRate;
  *patience = this->rGotoRadiusPatience;
  this->bGotoRadius = 0;
  return 1;
}

// File Line: 1747
// RVA: 0x54D330
void __fastcall UFG::CharacterSubjectComponent::SetGotoAngle(UFG::CharacterSubjectComponent *this, float angle, float rate, float patience, bool worldSpace, bool useSecond, float angleSecond, bool farthestAngle, bool angleAdditive)
{
  this->rGotoAngle = angle;
  this->bGotoAngleWorldSpace = worldSpace;
  this->bGotoAngle = 1;
  this->rGotoAngleRate = rate;
  this->rGotoAnglePatience = patience;
  this->rGotoAngleSecond = angleSecond;
  this->bGotoAngleUseSecond = useSecond;
  this->bGotoAngleFarthestAngle = farthestAngle;
  this->bGotoAngleAdditive = angleAdditive;
}

// File Line: 1765
// RVA: 0x52A8D0
char __fastcall UFG::CharacterSubjectComponent::GetAndClearGotoAngle(UFG::CharacterSubjectComponent *this, float *angle, float *rate, float *patience, bool *localSpace, bool *useSecond, float *angleSecond, bool *farthestAngle, bool *angleAdditive)
{
  if ( !this->bGotoAngle )
    return 0;
  *angle = (float)(this->rGotoAngle * 3.1415927) * 0.0055555557;
  *rate = (float)(this->rGotoAngleRate * 3.1415927) * 0.0055555557;
  *patience = this->rGotoAnglePatience;
  *localSpace = this->bGotoAngleWorldSpace == 0;
  *useSecond = this->bGotoAngleUseSecond;
  *angleSecond = (float)(this->rGotoAngleSecond * 3.1415927) * 0.0055555557;
  *farthestAngle = this->bGotoAngleFarthestAngle;
  *angleAdditive = this->bGotoAngleAdditive;
  this->bGotoAngle = 0;
  return 1;
}

